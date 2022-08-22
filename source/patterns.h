

// this is the meat and potatoes, where all the light patterns are
// I really should figure out how to format this so it doesn't use a literal 1000 lines
static u16 LightPatterns[17][255] = {
    {0x1010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1048,
     0x1052,
     0x1060,
     0x1070,
     0x1180,
     0x1070,
     0x1060,
     0x1052,
     0x1048,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0x1010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1152,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0xF210,
     0x3011,
     0x3012,
     0x3013,
     0x3015,
     0x3017,
     0x3019,
     0x301B,
     0x301E,
     0x3022,
     0x3026,
     0x302E,
     0x3036,
     0x3040,
     0x304B,
     0x3056,
     0x3060,
     0x306A,
     0x3073,
     0x3076,
     0x3077,
     0x7478,
     0x5040,
     0x5078,
     0x5040,
     0x5078,
     0x1040,
     0x1020,
     0x1010,
     0x1010,
     0x3010,
     0x3010,
     0x1710,
     0x0025,
     0x301E,
     0x301B,
     0x3019,
     0x3017,
     0x3015,
     0x3013,
     0x3012,
     0x3011,
     0x0024},
    {0x1010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1048,
     0x1052,
     0x1060,
     0x1070,
     0x1180,
     0x1070,
     0x1060,
     0x1052,
     0x1048,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0x1010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1152,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0xF210,
     0x3011,
     0x3012,
     0x3013,
     0x3015,
     0x3017,
     0x3019,
     0x301B,
     0x301E,
     0x3022,
     0x3026,
     0x302E,
     0x3036,
     0x3040,
     0x304B,
     0x3056,
     0x3060,
     0x306A,
     0x3073,
     0x3076,
     0x3077,
     0x7478,
     0x5040,
     0x5078,
     0x5040,
     0x5078,
     0x1070,
     0x1060,
     0x1050,
     0x103C,
     0x3030,
     0x3020,
     0x9410,
     0x0025,
     0x301E,
     0x301B,
     0x3019,
     0x3017,
     0x3015,
     0x3013,
     0x3012,
     0x3011,
     0x0024},
    {0x5200,
     0x1110,
     0x1118,
     0x1120,
     0x1128,
     0x1130,
     0x1138,
     0x1140,
     0x1148,
     0x1150,
     0x1158,
     0x1160,
     0x1168,
     0x1170,
     0x1178,
     0x3180,
     0x1178,
     0x1170,
     0x1168,
     0x1160,
     0x1158,
     0x1150,
     0x1148,
     0x1140,
     0x1138,
     0x1130,
     0x1128,
     0x1120,
     0x1118,
     0x1110,
     0x1100,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF},
    {0x1000,
     0x1110,
     0x1118,
     0x1120,
     0x1128,
     0x1130,
     0x1138,
     0x1140,
     0x1148,
     0x1150,
     0x1158,
     0x1160,
     0x1168,
     0x1170,
     0x1178,
     0x5080,
     0x1178,
     0x1170,
     0x1168,
     0x1160,
     0x1158,
     0x1150,
     0x1148,
     0x1140,
     0x1138,
     0x1130,
     0x1128,
     0x1120,
     0x1118,
     0x1110,
     0x1100,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF,
     0x00FF},
    {0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x00FF},
    {0x1000,
     0x1110,
     0x1118,
     0x1120,
     0x1128,
     0x1130,
     0x2138,
     0x2140,
     0x2148,
     0x2150,
     0x2158,
     0x2160,
     0x3168,
     0x3170,
     0x3178,
     0x4180,
     0x3178,
     0x3170,
     0x3168,
     0x3160,
     0x2158,
     0x2150,
     0x2148,
     0x2140,
     0x2138,
     0x1130,
     0x1128,
     0x1120,
     0x1118,
     0x1110,
     0x00FF},
    {0x1000,
     0x1010,
     0x1018,
     0x1020,
     0x1028,
     0x1030,
     0x1038,
     0x1040,
     0x1048,
     0x1050,
     0x2058,
     0x4060,
     0x2058,
     0x1050,
     0x2048,
     0x1050,
     0x1058,
     0x1060,
     0x1068,
     0x2070,
     0x3078,
     0x4080,
     0x3078,
     0x2070,
     0x1068,
     0x1060,
     0x1058,
     0x1050,
     0x1048,
     0x1040,
     0x1038,
     0x1030,
     0x1028,
     0x1020,
     0x1018,
     0x1010,
     0x00FF},
    {0x3200,
     0x1020,
     0x1030,
     0x1040,
     0x1050,
     0x1058,
     0x1060,
     0x1058,
     0x1050,
     0x2040,
     0x1050,
     0x1060,
     0x1068,
     0x1070,
     0x1078,
     0x2080,
     0x1078,
     0x1070,
     0x1060,
     0x1050,
     0x1040,
     0x1030,
     0x1020,
     0x0100,
     0x00FF},
    {0x1000,
     0x2010,
     0x2018,
     0x2020,
     0x2028,
     0x2030,
     0x2038,
     0x2040,
     0x2048,
     0x2050,
     0x4058,
     0x8060,
     0x4058,
     0x2050,
     0x4048,
     0x2050,
     0x2058,
     0x2060,
     0x2068,
     0x4070,
     0x6078,
     0x8080,
     0x6078,
     0x4070,
     0x2068,
     0x2060,
     0x2058,
     0x2050,
     0x2048,
     0x2040,
     0x2038,
     0x2030,
     0x2028,
     0x2020,
     0x2018,
     0x2010},
    {0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x1700,
     0x2210,
     0x2218,
     0x2220,
     0x1228,
     0x1230,
     0x1238,
     0x2240,
     0x3248,
     0x4350,
     0x3248,
     0x2240,
     0x1238,
     0x1230,
     0x1228,
     0x1220,
     0x1218,
     0x1210},
    {0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x1700,
     0x1110,
     0x1118,
     0x1120,
     0x1128,
     0x1130,
     0x2138,
     0x2140,
     0x2148,
     0x2150,
     0x2158,
     0x2160,
     0x3168,
     0x3170,
     0x3178,
     0x4180,
     0x3178,
     0x3170,
     0x3168,
     0x3160,
     0x2158,
     0x2150,
     0x2148,
     0x2140,
     0x2138,
     0x1130,
     0x1128,
     0x1120,
     0x1118,
     0x1110},
    {0x3200,
     0x1020,
     0x1030,
     0x1040,
     0x1050,
     0x1058,
     0x1060,
     0x1058,
     0x1050,
     0x2040,
     0x1050,
     0x1060,
     0x1068,
     0x1070,
     0x1078,
     0x2080,
     0x1078,
     0x1070,
     0x1060,
     0x1050,
     0x1040,
     0x1030,
     0x1020,
     0x0100,
     0xc200,
     0x2010,
     0x2018,
     0x2020,
     0x2028,
     0x2030,
     0x2038,
     0x2040,
     0x2048,
     0x2050,
     0x4058,
     0x8060,
     0x4058,
     0x2050,
     0x4048,
     0x2050,
     0x2058,
     0x2060,
     0x2068,
     0x4070,
     0x6078,
     0x8080,
     0x6078,
     0x4070,
     0x2068,
     0x2060,
     0x2058,
     0x2050,
     0x2048,
     0x2040,
     0x2038,
     0x2030,
     0x2028,
     0x2020,
     0x2018,
     0x2010},
    {0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x1000,
     0x3080,
     0x1710,
     0x1320,
     0x1328,
     0x1330,
     0x1338,
     0x1340,
     0x1348,
     0x1350,
     0x1358,
     0x1360,
     0x1368,
     0x1370,
     0x1378,
     0x2380,
     0x1378,
     0x1370,
     0x1368,
     0x1360,
     0x1358,
     0x1350,
     0x1348,
     0x1340,
     0x1338,
     0x1330,
     0x1328,
     0x1320,
     0x1318},
    {0x3200,
     0x1020,
     0x1030,
     0x1040,
     0x1050,
     0x1058,
     0x1060,
     0x1058,
     0x1050,
     0x2040,
     0x1050,
     0x1060,
     0x1068,
     0x1070,
     0x1078,
     0x2080,
     0x1078,
     0x1070,
     0x1060,
     0x1050,
     0x1040,
     0x1030,
     0x1020,
     0x0100,
     0x1610,
     0x2212,
     0x2214,
     0x2216,
     0x2218,
     0x221a,
     0x221c,
     0x221e,
     0x2220,
     0x2224,
     0x2228,
     0x222c,
     0x1230,
     0x1234,
     0x1238,
     0x123c,
     0x1240,
     0x1244,
     0x1248,
     0x124c,
     0x1250,
     0x125c,
     0x1258,
     0x125c,
     0x1260,
     0x1264,
     0x1268,
     0x126c,
     0x1270,
     0x1274,
     0x1278,
     0x127c,
     0x2280,
     0x227c,
     0x1278,
     0x1274,
     0x1270,
     0x126c,
     0x1268,
     0x1264,
     0x1260,
     0x125c,
     0x1258,
     0x1254,
     0x1250,
     0x124c,
     0x1248,
     0x1244,
     0x1240,
     0x123c,
     0x1238,
     0x1234,
     0x1230,
     0x122c,
     0x2228,
     0x2224,
     0x2220,
     0x221e,
     0x221c,
     0x221a,
     0x2218,
     0x2216,
     0x2214,
     0x2212,
     0x0018},
    {0x3200,
     0x1020,
     0x1030,
     0x1040,
     0x1050,
     0x1058,
     0x1060,
     0x1058,
     0x1050,
     0x2040,
     0x1050,
     0x1060,
     0x1068,
     0x1070,
     0x1078,
     0x2080,
     0x1078,
     0x1070,
     0x1060,
     0x1050,
     0x1040,
     0x1030,
     0x1020,
     0x0100,
     0x3610,
     0x4018,
     0x3020,
     0x2028,
     0x2030,
     0x2038,
     0x2040,
     0x2048,
     0x2050,
     0x4058,
     0x8060,
     0x4058,
     0x2050,
     0x4048,
     0x2050,
     0x2058,
     0x2060,
     0x2068,
     0x4070,
     0x6078,
     0x8080,
     0x6078,
     0x4070,
     0x2068,
     0x2060,
     0x2058,
     0x2050,
     0x2048,
     0x2040,
     0x2038,
     0x2030,
     0x2028,
     0x3020,
     0x4018,
     0x0018},
    {0x1010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1048,
     0x1052,
     0x1060,
     0x1070,
     0x1180,
     0x1070,
     0x1060,
     0x1052,
     0x1048,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0x1010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1152,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0xF210,
     0x3011,
     0x3012,
     0x3013,
     0x3015,
     0x3017,
     0x3019,
     0x301B,
     0x301E,
     0x3022,
     0x3026,
     0x302E,
     0x3036,
     0x3040,
     0x304B,
     0x3056,
     0x3060,
     0x306A,
     0x3073,
     0x3076,
     0x3077,
     0x7378,
     0x3077,
     0x3076,
     0x3073,
     0x306A,
     0x3060,
     0x3056,
     0x304B,
     0x3040,
     0x3036,
     0x302E,
     0x3026,
     0x3022,
     0x301E,
     0x301B,
     0x3019,
     0x3017,
     0x3015,
     0x3013,
     0x3012,
     0x3011,
     0x0024},
    {0x7010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1048,
     0x1052,
     0x1060,
     0x1070,
     0x1180,
     0x1070,
     0x1060,
     0x1052,
     0x1048,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0x1010,
     0x1014,
     0x1018,
     0x101E,
     0x1024,
     0x1030,
     0x1038,
     0x1152,
     0x1038,
     0x1030,
     0x1024,
     0x101E,
     0x1018,
     0x1014,
     0x9410,
     0x0000},
};