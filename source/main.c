#include <stdio.h>
#include <stdlib.h>
#include <ogcsys.h>
#include <wupc/wupc.h>
#include <wiiuse/wpad.h>
#include "patterns.h"

#define DI_BUTTONS_DOWN 0
#define DI_BUTTONS_HELD 1

#define resetscreen() printf("\x1b[2J")

struct timespec _wiilight_timeOn;
struct timespec _wiilight_timeOff;

int WIILIGHT_IsOn;
int WIILIGHT_Level;

void _wiilight_turn(int enable);
static void *_wiilight_loop(void *arg);
static vu32 *_wiilight_reg = (u32 *)0xCD0000C0;
lwp_t _wiilight_thread;

void WIILIGHT_Init();
void WIILIGHT_TurnOn();
int WIILIGHT_GetLevel();
int WIILIGHT_SetLevel(int level);

void WIILIGHT_Toggle();
void WIILIGHT_TurnOff();

int pattern_selectionmenu(int selection);
int solidlightmenu();

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void WIILIGHT_Init()
{
    _wiilight_timeOn.tv_sec = (time_t)0;
    _wiilight_timeOff.tv_sec = (time_t)0;
    WIILIGHT_IsOn = 0;
    WIILIGHT_SetLevel(0);
}

int WIILIGHT_GetLevel()
{
    return WIILIGHT_Level;
}

bool isDolphin(void)
{
    s32 checkDolphin;
    checkDolphin = IOS_Open("/dev/dolphin", IPC_OPEN_NONE);
    if (checkDolphin >= 0)
        return true;
    else
        return false;
}

bool isvWii(void)
{ // Function taken from priiloader
    s32 ret;
    u32 x;

    // check if the vWii NandLoader is installed ( 0x200 & 0x201)
    ret = ES_GetTitleContentsCount(0x0000000100000200ll, &x);

    if (ret < 0)
        return false; // title was never installed

    if (x <= 0)
        return false; // title was installed but deleted via Channel Management

    return true;
}

//
// here is where we set the light intensity
// it turns on the light and
// waits level*40000 nanoseconds
// (so, if it is 255 it will wait for 10200000 nanoseconds)
// (that means ~ 1/100secs)
//
// for the time turned off it is 10200000-level_on
// (so, if level is 255, it will wait for 0 seconds)
// (that means full light intensity)
//

int WIILIGHT_SetLevel(int level)
{
    // 0 to 255
    long level_on;
    long level_off;
    if (level > 255)
        level = 255;
    if (level < 0)
        level = 0;
    level_on = level * 40000;
    level_off = 10200000 - level_on;
    _wiilight_timeOn.tv_nsec = level_on;
    _wiilight_timeOff.tv_nsec = level_off;
    WIILIGHT_Level = level;
    return level;
}

//
// just turn one bit
//

void _wiilight_turn(int enable)
{
    u32 val = (*_wiilight_reg & ~0x20);
    if (enable)
        val |= 0x20;
    *_wiilight_reg = val;
}

void WIILIGHT_TurnOff()
{
    WIILIGHT_IsOn = false;
}

//
// Set the var on, and start the looping thread
//

void WIILIGHT_TurnOn()
{
    WIILIGHT_IsOn = true;
    LWP_CreateThread(&_wiilight_thread, _wiilight_loop, NULL, NULL, 0, 80);
}

void WIILIGHT_Toggle()
{
    if (WIILIGHT_IsOn)
    {
        WIILIGHT_TurnOff();
    }
    else
    {
        WIILIGHT_TurnOn();
    }
}

//
// This is the looping thread.. it just loops
// turning on and off the light depending on the timing
// specified by SetLevel()
//

static void *_wiilight_loop(void *arg)
{
    struct timespec timeOn;
    struct timespec timeOff;
    while (WIILIGHT_IsOn)
    {
        timeOn = _wiilight_timeOn;
        timeOff = _wiilight_timeOff;
        _wiilight_turn(1);
        nanosleep(&timeOn, &timeOn);
        if (timeOff.tv_nsec > 0)
            _wiilight_turn(0);
        nanosleep(&timeOff, &timeOff);
    }

    return NULL;
}

u32 DetectInput(u8 DownOrHeld)
{
    u32 pressed = 0;
    u32 gcpressed = 0;
    VIDEO_WaitVSync();

    // WiiMote (and Classic Controller) take precedence over the GCN controller to save time
    if (WPAD_ScanPads() > WPAD_ERR_NONE) // Scan the Wii remotes.  If there any problems, skip checking buttons
    {
        if (DownOrHeld == DI_BUTTONS_DOWN)
        {
            pressed = WPAD_ButtonsDown(0) | WPAD_ButtonsDown(1) | WPAD_ButtonsDown(2) | WPAD_ButtonsDown(3); // Store pressed buttons
        }
        else
        {
            pressed = WPAD_ButtonsHeld(0) | WPAD_ButtonsHeld(1) | WPAD_ButtonsHeld(2) | WPAD_ButtonsHeld(3); // Store held buttons
        }

        // Convert to WiiMote values
        if (pressed & WPAD_CLASSIC_BUTTON_ZR)
            pressed |= WPAD_BUTTON_PLUS;
        if (pressed & WPAD_CLASSIC_BUTTON_ZL)
            pressed |= WPAD_BUTTON_MINUS;

        if (pressed & WPAD_CLASSIC_BUTTON_PLUS)
            pressed |= WPAD_BUTTON_PLUS;
        if (pressed & WPAD_CLASSIC_BUTTON_MINUS)
            pressed |= WPAD_BUTTON_MINUS;

        if (pressed & WPAD_CLASSIC_BUTTON_A)
            pressed |= WPAD_BUTTON_A;
        if (pressed & WPAD_CLASSIC_BUTTON_B)
            pressed |= WPAD_BUTTON_B;
        if (pressed & WPAD_CLASSIC_BUTTON_X)
            pressed |= WPAD_BUTTON_2;
        if (pressed & WPAD_CLASSIC_BUTTON_Y)
            pressed |= WPAD_BUTTON_1;
        if (pressed & WPAD_CLASSIC_BUTTON_HOME)
            pressed |= WPAD_BUTTON_HOME;

        if (pressed & WPAD_CLASSIC_BUTTON_UP)
            pressed |= WPAD_BUTTON_UP;
        if (pressed & WPAD_CLASSIC_BUTTON_DOWN)
            pressed |= WPAD_BUTTON_DOWN;
        if (pressed & WPAD_CLASSIC_BUTTON_LEFT)
            pressed |= WPAD_BUTTON_LEFT;
        if (pressed & WPAD_CLASSIC_BUTTON_RIGHT)
            pressed |= WPAD_BUTTON_RIGHT;
    }

    // Return WiiMote / Classic Controller values
    if (pressed)
        return pressed;

    // No buttons on the WiiMote or Classic Controller were pressed
    if (PAD_ScanPads() > PAD_ERR_NONE)
    {
        if (DownOrHeld == DI_BUTTONS_DOWN)
        {
            gcpressed = PAD_ButtonsDown(0) | PAD_ButtonsDown(1) | PAD_ButtonsDown(2) | PAD_ButtonsDown(3); // Store pressed buttons
        }
        else
        {
            gcpressed = PAD_ButtonsHeld(0) | PAD_ButtonsHeld(1) | PAD_ButtonsHeld(2) | PAD_ButtonsHeld(3); // Store held buttons
        }

        // Convert to WiiMote values
        if (gcpressed & PAD_TRIGGER_R)
            pressed |= WPAD_BUTTON_PLUS;
        if (gcpressed & PAD_TRIGGER_L)
            pressed |= WPAD_BUTTON_MINUS;
        if (gcpressed & PAD_BUTTON_A)
            pressed |= WPAD_BUTTON_A;
        if (gcpressed & PAD_BUTTON_B)
            pressed |= WPAD_BUTTON_B;
        if (gcpressed & PAD_BUTTON_X)
            pressed |= WPAD_BUTTON_2;
        if (gcpressed & PAD_BUTTON_Y)
            pressed |= WPAD_BUTTON_1;
        if (gcpressed & PAD_BUTTON_MENU)
            pressed |= WPAD_BUTTON_HOME;
        if (gcpressed & PAD_BUTTON_UP)
            pressed |= WPAD_BUTTON_UP;
        if (gcpressed & PAD_BUTTON_DOWN)
            pressed |= WPAD_BUTTON_DOWN;
        if (gcpressed & PAD_BUTTON_LEFT)
            pressed |= WPAD_BUTTON_LEFT;
        if (gcpressed & PAD_BUTTON_RIGHT)
            pressed |= WPAD_BUTTON_RIGHT;
    }

    return pressed;
}

char *PatternNames[17] = {
    "Bush Warbler v1.1 - Default          ",
    "Bush Warbler v1.0                      ",
    "Disc Drive - Open                      ",
    "Disc Drive - Close                     ",
    "Blink 3 Times                           ",
    "Fast - 1 Time - Bright                ",
    "Special                                  ",
    "Special - Fast                          ",
    "Special - Slow                          ",
    "Blink and Loop Fast                     ",
    "Blink and Loop Fast - Bright           ",
    "Blink and Loop Fast - Special          ",
    "Blink and Loop Fast - Slow - Bright   ",
    "Blink and Loop Fast - Slow - Bright 2 ",
    "Blink and Loop Fast - Slow - Special  ",
    "Breathing of a Sleeper                   ",
    "Bell Cricket                               ",
};

int pattern_selectionmenu(int selection)
{
    u32 pressed;
    u32 pattern_count = 17;

MENU:
    while (true)
    {
        pressed = DetectInput(DI_BUTTONS_DOWN);

        resetscreen();

        printf("\x1B[%d;%dH", 5, 0); // move console cursor to y/x
        printf("GlowWii v1.1 - By Larsenv\n\n");

        if (isDolphin())
        {
            printf("This tool doesn't work on Dolphin Emulator.\n");
            printf("Dolphin Emulator doesn't emulate the disc drive light.\n");
            printf("\nExiting...");
            return 1;
        }

        else if (isvWii())
        {
            printf("This tool doesn't work on a Wii U.\n");
            printf("The Wii U doesn't have a disc drive light.\n");
            printf("\nExiting...");
            return 1;
        }

        printf("Select the pattern to use:       \b\b\b\b\b\b");

        printf("%s\n\n", PatternNames[selection]);

        printf("Press +Left/Right to change the pattern.\n");
        printf("Press A to load the pattern.\n");
        printf("Press 1 if you want to illuminate a solid light.\n");
        printf("Press HOME to exit.");

        if (pressed & WPAD_BUTTON_LEFT)
        {
            if (selection > 0)
            {
                selection--;
            }

            else
            {
                selection = pattern_count - 1;
            }
        }

        if (pressed & WPAD_BUTTON_RIGHT)
        {
            if (selection < pattern_count - 1)
            {
                selection++;
            }

            else
            {
                selection = 0;
            }
        }

        if (pressed & WPAD_BUTTON_A)
        {
            break;
        }

        if (pressed & WPAD_BUTTON_1)
        {
            int cmd = solidlightmenu();

            if (cmd == 1)
            {
                return 1;
            }

            else if (cmd == 0)
            {
                goto MENU;
            }
        }

        if (pressed & WPAD_BUTTON_HOME)
        {
            printf("\n\nExiting...");
            return 1;
        }
    }

    return selection;
}

int solidlightmenu()
{
    u32 pressed;

    int brightness = 0;

    while (true)
    {
        pressed = DetectInput(DI_BUTTONS_DOWN);

        resetscreen();

        printf("\x1B[%d;%dH", 5, 0); // move console cursor to y/x
        printf("GlowWii v1.1 - By Larsenv\n\n");

        printf("Brightness: %d\n\n", brightness);

        printf("Press +Left/Right to change the brightness.\n");
        printf("Press A to toggle the light with the given brightness.\n");
        printf("Press B to toggle the light with maximum brightness.\n");
        printf("Press 1 if you want to illuminate a pattern.\n");
        printf("Press HOME to exit.");

        if (pressed & WPAD_BUTTON_LEFT)
        {
            if (brightness > 0)
            {
                brightness--;
                WIILIGHT_SetLevel(brightness);
                WIILIGHT_TurnOn();
            }

            else
            {
                brightness = 254; // weird stuff happens with 255 as a brightness level, I can't toggle the brightness. the difference between 254 and 255 is unnoticeable
                WIILIGHT_SetLevel(brightness);
                WIILIGHT_TurnOn();
            }
        }

        if (pressed & WPAD_BUTTON_RIGHT)
        {
            if (brightness < 254)
            {
                brightness++;
                WIILIGHT_SetLevel(brightness);
                WIILIGHT_TurnOn();
            }

            else
            {
                brightness = 0;
                WIILIGHT_SetLevel(brightness);
                WIILIGHT_TurnOn();
            }
        }

        if (pressed & WPAD_BUTTON_A)
        {
            WIILIGHT_SetLevel(brightness);
            WIILIGHT_Toggle();
        }

        if (pressed & WPAD_BUTTON_B)
        {
            brightness = 254;
            WIILIGHT_SetLevel(brightness);
            WIILIGHT_Toggle();
        }

        if (pressed & WPAD_BUTTON_1)
        {
            return 0;
        }

        if (pressed & WPAD_BUTTON_HOME)
        {
            printf("\n\nExiting...");
            return 255;
        }
    }
}

#define GET_GAIN(cmd) (((u32)(cmd)) & 0xff) // brightness
#define GET_DURATION(cmd) ((((u32)(cmd)) >> 12) << ((((u32)(cmd)) >> 8) & 0x0f))
#define IS_LOOP(cmd) ((((u32)(cmd)) >> 12) == 0)
#define GET_LOOP_INDEX(cmd) (((u32)(cmd)) & 0xff)
#define GET_LOOP_COUNT(cmd) ((((u32)(cmd)) >> 8) & 0x0f)

int main(int argc, char **argv)
{
    VIDEO_Init();
    PAD_Init();
    WUPC_Init();
    WPAD_Init();

    rmode = VIDEO_GetPreferredMode(NULL);

    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

    console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIX_SZ);
    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    if (rmode->viTVMode & VI_NON_INTERLACE)
        VIDEO_WaitVSync();

    // Inits
    WIILIGHT_Init();

    int selection = 0;

PICK:
    while (1)
    {
        int pattern_num = pattern_selectionmenu(selection);

        selection = pattern_num;

        if (selection == 255)
        {
            return 0;
        }

        resetscreen();

        printf("\x1B[%d;%dH", 5, 0); // move console cursor to y/x
        printf("Illuminating Pattern: %s\n\n", PatternNames[pattern_num]);

        printf("Press A to restart the pattern.\n");
        printf("Press B to pick a different pattern.\n");
        printf("Press HOME to exit.");

        // Main App
        while (1)
        {
            for (int i = 0; i < sizeof(LightPatterns[pattern_num]) / 2; i++)
            {
                u32 pressed = DetectInput(DI_BUTTONS_DOWN);

                if (pressed & WPAD_BUTTON_A)
                {
                    break;
                }

                if (pressed & WPAD_BUTTON_B)
                {
                    goto PICK;
                }

                if (pressed & WPAD_BUTTON_HOME)
                {
                    printf("\n\nExiting...");
                    return 0;
                }

                u16 pattern = LightPatterns[pattern_num][i];

                if (!IS_LOOP(pattern)) // I don't think any of the patterns need a loop command.
                {
                    int milliseconds = GET_DURATION(pattern) * 20; // duration is measured in 20 milliseconds
                    struct timespec duration;
                    duration.tv_sec = (time_t)(int)(milliseconds / 1000);
                    duration.tv_nsec = (time_t)(milliseconds % 1000) * 1000000;
                    WIILIGHT_SetLevel(GET_GAIN(pattern));
                    if (duration.tv_nsec >= 0)
                    {
                        WIILIGHT_TurnOn();
                        nanosleep(&duration, &duration);
                        WIILIGHT_TurnOff();
                    }

                    struct timespec sleeper; // sleep for 1 millisecond
                    sleeper.tv_sec = (time_t)0;
                    sleeper.tv_nsec = (time_t)1000000;
                    nanosleep(&sleeper, &sleeper);
                }
            }
        }

        struct timespec pause; // sleep for 1 second
        pause.tv_sec = (time_t)1;
        pause.tv_nsec = (time_t)0;
        nanosleep(&pause, &pause);
    }

    return 0;
}
