/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
typedef struct RwObjectOwnerLink RwObjectOwnerLink;
typedef struct RwObject RwObject;

/* Canonical grouped function declarations. */
u32 func_003e8110(u32 camera);
u32 func_003e8120(u32 camera);
u8 func_003e9240(RwObjectOwnerLink *param_1);
u32 func_003e9750(int param_1);
u32 func_004125d0(int param_1);
s32 func_0041f208(int param_1);
u32 func_0041f6e0(u32 *param_1);
u32 func_0041f6f0(u32 *param_1);

/* Source unit: src/rw/rwcore_003e8110.c (1 function markers) */

#pragma optimization_level 3
// FUN_003E8110
u32 func_003e8110(u32 camera)
{
    return ((u32 (*)(u32))*(u32 *)(camera + 0x1c))(camera);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e8120.c (1 function markers) */

#pragma optimization_level 3
// FUN_003E8120
u32 func_003e8120(u32 camera)
{
    return ((u32 (*)(u32))*(u32 *)(camera + 0x18))(camera);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e9240.c (1 function markers) */
#pragma optimization_level 3
struct RwObjectOwnerLink {
    u8 padding[0xa0];
    RwObject *owner;
};
struct RwObject {
    u8 padding[3];
    u8 type;
};

// FUN_003E9240
u8 func_003e9240(RwObjectOwnerLink *param_1)
{
    return param_1->owner->type & 3;
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e9750.c (1 function markers) */
#pragma optimization_level 3

// FUN_003E9250
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9250);
// FUN_003E9320
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9320);
// FUN_003E9390
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9390);
// FUN_003E9460
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9460);
// FUN_003E95C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e95c0);
// FUN_003E9680
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9680);
// FUN_003E9700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9700);
// FUN_003E9750
u32 func_003e9750(int param_1)
{
    return *(u32 *)(param_1 + 0xa0);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004125d0.c (1 function markers) */
#pragma optimization_level 3

// FUN_003E9760
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9760);
// FUN_003E9830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9830);
// FUN_003E99A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e99a0);
// FUN_003E9AF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9af0);
// FUN_003E9B60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9b60);
// FUN_003E9C10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9c10);
// FUN_003E9CB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9cb0);
// FUN_003E9D50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9d50);
// FUN_003E9DF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9df0);
// FUN_003E9EB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9eb0);
// FUN_003E9EE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9ee0);
// FUN_003EA130
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea130);
// FUN_003EA2C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea2c0);
// FUN_003EA370
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea370);
// FUN_003EA3E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea3e0);
// FUN_003EA510
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea510);
// FUN_003EA560
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea560);
// FUN_003EA690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea690);
// FUN_003EAA80
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eaa80);
// FUN_003EAB70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eab70);
// FUN_003EAF00
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eaf00);
// FUN_003EAF60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eaf60);
// FUN_003EB0D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb0d0);
// FUN_003EB1C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb1c0);
// FUN_003EB1F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb1f0);
// FUN_003EB3B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb3b0);
// FUN_003EB700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb700);
// FUN_003EBAC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebac0);
// FUN_003EBBF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebbf0);
// FUN_003EBDE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebde0);
// FUN_003EBFF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebff0);
// FUN_003EC110
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec110);
// FUN_003EC180
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec180);
// FUN_003EC1F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec1f0);
// FUN_003EC2A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec2a0);
// FUN_003EC2E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec2e0);
// FUN_003EC330
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec330);
// FUN_003EC3A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec3a0);
// FUN_003EC3D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec3d0);
// FUN_003EC420
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec420);
// FUN_003EC480
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec480);
// FUN_003EC4F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec4f0);
// FUN_003EC590
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec590);
// FUN_003EC6A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec6a0);
// FUN_003EC6F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec6f0);
// FUN_003EC760
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec760);
// FUN_003EC840
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec840);
// FUN_003ECE40
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ece40);
// FUN_003ED0B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed0b0);
// FUN_003ED2D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed2d0);
// FUN_003ED450
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed450);
// FUN_003ED540
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed540);
// FUN_003ED650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed650);
// FUN_003ED7E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed7e0);
// FUN_003ED850
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed850);
// FUN_003ED960
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed960);
// FUN_003EDA60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eda60);
// FUN_003EDB30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003edb30);
// FUN_003EDC30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003edc30);
// FUN_003EDE50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ede50);
// FUN_003EE1D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ee1d0);
// FUN_003EE470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ee470);
// FUN_003EEA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eea90);
// FUN_003EEAE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eeae0);
// FUN_003EEE70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eee70);
// FUN_003EEF60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eef60);
// FUN_003EF000
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef000);
// FUN_003EF020
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef020);
// FUN_003EF040
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef040);
// FUN_003EF060
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef060);
// FUN_003EF080
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef080);
// FUN_003EF0D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef0d0);
// FUN_003EF1B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef1b0);
// FUN_003EF260
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef260);
// FUN_003EF2E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef2e0);
// FUN_003EF3A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef3a0);
// FUN_003EF470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef470);
// FUN_003EF510
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef510);
// FUN_003EF5B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef5b0);
// FUN_003EF610
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef610);
// FUN_003EF650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef650);
// FUN_003EF6B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef6b0);
// FUN_003EF6D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef6d0);
// FUN_003EF6F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef6f0);
// FUN_003EF740
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef740);
// FUN_003EF890
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef890);
// FUN_003EF8C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef8c0);
// FUN_003EF900
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef900);
// FUN_003EFAC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003efac0);
// FUN_003EFD20
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003efd20);
// FUN_003EFDA0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003efda0);
// FUN_003EFDE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003efde0);
// FUN_003EFF30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eff30);
// FUN_003F0110
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0110);
// FUN_003F02D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f02d0);
// FUN_003F03F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f03f0);
// FUN_003F0510
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0510);
// FUN_003F0610
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0610);
// FUN_003F07D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f07d0);
// FUN_003F0C10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0c10);
// FUN_003F0DE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0de0);
// FUN_003F1030
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1030);
// FUN_003F1240
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1240);
// FUN_003F13B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f13b0);
// FUN_003F1520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1520);
// FUN_003F1600
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1600);
// FUN_003F1700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1700);
// FUN_003F17E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f17e0);
// FUN_003F1CE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1ce0);
// FUN_003F24A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f24a0);
// FUN_003F25C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f25c0);
// FUN_003F26C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f26c0);
// FUN_003F2760
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2760);
// FUN_003F2830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2830);
// FUN_003F2CD0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2cd0);
// FUN_003F2F40
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2f40);
// FUN_003F32D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f32d0);
// FUN_003F34E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f34e0);
// FUN_003F36A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f36a0);
// FUN_003F3750
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f3750);
// FUN_003F38D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f38d0);
// FUN_003F39C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f39c0);
// FUN_003F3EB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f3eb0);
// FUN_003F4370
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4370);
// FUN_003F44C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f44c0);
// FUN_003F4730
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4730);
// FUN_003F4950
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4950);
// FUN_003F4A80
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4a80);
// FUN_003F4BE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4be0);
// FUN_003F4C90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4c90);
// FUN_003F4F30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4f30);
// FUN_003F4F90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4f90);
// FUN_003F4FF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4ff0);
// FUN_003F5040
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5040);
// FUN_003F5070
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5070);
// FUN_003F5D90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5d90);
// FUN_003F6440
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6440);
// FUN_003F6690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6690);
// FUN_003F6780
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6780);
// FUN_003F67E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f67e0);
// FUN_003F67F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f67f0);
// FUN_003F6800
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6800);
// FUN_003F68A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f68a0);
// FUN_003F6910
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6910);
// FUN_003F6990
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6990);
// FUN_003F69F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f69f0);
// FUN_003F6A10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6a10);
// FUN_003F73D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f73d0);
// FUN_003F7490
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f7490);
// FUN_003F79B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f79b0);
// FUN_003F7A60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f7a60);
// FUN_003F7A70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f7a70);
// FUN_003F8110
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f8110);
// FUN_003F9750
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f9750);
// FUN_003F98A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f98a0);
// FUN_003FB3F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fb3f0);
// FUN_003FB830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fb830);
// FUN_003FB9D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fb9d0);
// FUN_003FBC50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fbc50);
// FUN_003FBFF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fbff0);
// FUN_003FC280
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fc280);
// FUN_003FC5F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fc5f0);
// FUN_003FD230
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd230);
// FUN_003FD460
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd460);
// FUN_003FD520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd520);
// FUN_003FD630
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd630);
// FUN_003FD690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd690);
// FUN_003FD940
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd940);
// FUN_003FDD10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fdd10);
// FUN_003FDDC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fddc0);
// FUN_003FDF20
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fdf20);
// FUN_003FE1F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe1f0);
// FUN_003FE200
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe200);
// FUN_003FE210
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe210);
// FUN_003FE320
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe320);
// FUN_003FE470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe470);
// FUN_003FE630
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe630);
// FUN_003FE700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe700);
// FUN_003FEA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fea90);
// FUN_003FF160
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ff160);
// FUN_003FF5B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ff5b0);
// FUN_004010C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004010c0);
// FUN_00401450
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401450);
// FUN_00401460
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401460);
// FUN_004015E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004015e0);
// FUN_00401650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401650);
// FUN_00401870
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401870);
// FUN_00401AA0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401aa0);
// FUN_00401B80
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401b80);
// FUN_00401B90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401b90);
// FUN_00402390
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402390);
// FUN_00402410
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402410);
// FUN_00402470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402470);
// FUN_00402510
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402510);
// FUN_00402570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402570);
// FUN_00402600
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402600);
// FUN_00402680
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402680);
// FUN_004026D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004026d0);
// FUN_00402970
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402970);
// FUN_00402AB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402ab0);
// FUN_00402C10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402c10);
// FUN_00402D50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402d50);
// FUN_00402FE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402fe0);
// FUN_00403170
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00403170);
// FUN_00403390
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00403390);
// FUN_004033E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004033e0);
// FUN_00403930
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00403930);
// FUN_004052B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004052b0);
// FUN_00406B60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00406b60);
// FUN_00407BD0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407bd0);
// FUN_00407C10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407c10);
// FUN_00407D10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407d10);
// FUN_00407DF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407df0);
// FUN_00407FF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407ff0);
// FUN_00409150
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00409150);
// FUN_00409D30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00409d30);
// FUN_00409E10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00409e10);
// FUN_0040A090
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a090);
// FUN_0040A500
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a500);
// FUN_0040A650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a650);
// FUN_0040A800
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a800);
// FUN_0040AA10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040aa10);
// FUN_0040AA60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040aa60);
// FUN_0040ADF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040adf0);
// FUN_0040AFB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040afb0);
// FUN_0040B010
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b010);
// FUN_0040B230
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b230);
// FUN_0040B290
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b290);
// FUN_0040B520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b520);
// FUN_0040B7B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b7b0);
// FUN_0040BAC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040bac0);
// FUN_0040BDE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040bde0);
// FUN_0040C0F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040c0f0);
// FUN_0040C170
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040c170);
// FUN_0040C420
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040c420);
// FUN_0040C6D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040c6d0);
// FUN_0040CA00
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040ca00);
// FUN_0040CD60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040cd60);
// FUN_0040D0A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d0a0);
// FUN_0040D110
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d110);
// FUN_0040D160
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d160);
// FUN_0040D170
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d170);
// FUN_0040D570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d570);
// FUN_0040D720
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d720);
// FUN_0040DA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040da90);
// FUN_0040DCC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040dcc0);
// FUN_0040DF40
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040df40);
// FUN_0040DF50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040df50);
// FUN_0040E830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040e830);
// FUN_0040EEE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040eee0);
// FUN_0040F020
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f020);
// FUN_0040F1B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f1b0);
// FUN_0040F1C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f1c0);
// FUN_0040F480
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f480);
// FUN_0040F570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f570);
// FUN_0040FA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040fa90);
// FUN_0040FCD0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040fcd0);
// FUN_00410080
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410080);
// FUN_00410360
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410360);
// FUN_00410370
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410370);
// FUN_00410390
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410390);
// FUN_00410420
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410420);
// FUN_004104D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004104d0);
// FUN_00410520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410520);
// FUN_004106A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004106a0);
// FUN_00410800
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410800);
// FUN_00410930
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410930);
// FUN_00410A40
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410a40);
// FUN_00410AB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410ab0);
// FUN_00410D90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410d90);
// FUN_00410DF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410df0);
// FUN_00410ED0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410ed0);
// FUN_00410F00
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410f00);
// FUN_00410F30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410f30);
// FUN_00410F40
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410f40);
// FUN_00410F50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410f50);
// FUN_00410FF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410ff0);
// FUN_00411060
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411060);
// FUN_00411130
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411130);
// FUN_004114C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004114c0);
// FUN_004114D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004114d0);
// FUN_004115D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004115d0);
// FUN_00411670
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411670);
// FUN_00411740
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411740);
// FUN_004117B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004117b0);
// FUN_00411820
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411820);
// FUN_004118C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004118c0);
// FUN_00411A70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411a70);
// FUN_00411CE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411ce0);
// FUN_00411EE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411ee0);
// FUN_00411FD0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411fd0);
// FUN_004123C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004123c0);
// FUN_00412520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00412520);
// FUN_004125D0
u32 func_004125d0(int param_1)
{
    return *(u32 *)(param_1 + 0x20);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f208.c (1 function markers) */
#pragma optimization_level 3

// FUN_0041F208
s32 func_0041f208(int param_1)
{
    return *(s32 *)(*(s32 *)(param_1 + 0x40) + 0x878) = 1;
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6e0.c (1 function markers) */
#pragma optimization_level 3

// FUN_0041F6E0
u32 func_0041f6e0(u32 *param_1)
{
    return param_1[3] = param_1[2];
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6f0.c (1 function markers) */
#pragma optimization_level 3

// FUN_0041F6F0
u32 func_0041f6f0(u32 *param_1)
{
    return param_1[2] = param_1[3];
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004222b0.c (1 function markers) */
#pragma optimization_level 3

// FUN_004222B0
asm u32 QueryIntrContext(void)
{
    .set noreorder
    mfc0 $v0, $12
    xori $v0, $v0, 1
    jr $ra
    andi $v0, $v0, 1
}
#pragma optimization_level 2
