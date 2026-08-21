# GlowWii

GlowWii is an app to illuminate your Wii disc drive light. Unlike other apps that have been made, this app supports using illumination patterns that Nintendo made (for example, the pattern for when you get a Wii message, which mimics the call of a bush warbler).

This app also supports illuminating a solid light with a brightness of your choice.

GlowWii doesn't work on Dolphin Emulator, Wii U, or Wii Mini because they don't have a disc drive light.

## Building with additional controllers

    ./scripts/build_controller_portlibs.sh
    make WITH_WIIDRC=1 WITH_WUPC=1 WITH_SICKSAXIS=1

This enables the Wii U GamePad, Wii U Pro Controller, and wired DualShock 3.
The GamePad still requires Wii U VC with a patched fw.img. GlowWii itself exits
on Wii U because that hardware has no Wii disc-drive light.
