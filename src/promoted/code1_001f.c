#include "include_asm.h"
#include "type.h"
extern void func_001f62b0();
extern void func_001f58d0();

extern void memset(void *destination, s32 value, u32 size);

extern s32 func_001ef720(s32 arg0, s32 arg1);

extern u32 func_00231d70(s32 arg0);

extern u8 *iGpfffb3ac;
extern void func_0045ae10(u16 arg0, u16 arg1, u16 arg2);



extern void func_001f38e0(void);
extern void func_001f3900(void);
extern void func_001f3930(void);
extern void *func_00194470();

extern void func_001f39b0(void);
extern void func_001f39d0(void);
extern void func_001f3b00(void);

extern void func_001f8380(void);

extern void func_001f8400(void);

// FUN_001F0260
s64 func_001f0260(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0xDA:
    case 0xDB:
        return 0x40;
    case 0xDC:
    case 0xDD:
        return 0x42;
    case 0xDE:
    case 0xDF:
        return 0x44;
    case 0xE0:
        return 0x60;
    case 0xD3:
    case 0xD4:
        return 0x5A;
    case 0xD5:
    case 0xD6:
        return 0x5C;
    case 0xD7:
    case 0xD8:
        return 0x5E;
    case 0xD9:
        return 0x62;
    case 0xEA:
        return 0x4A;
    case 0xEB:
        return 0x4C;
    case 0xE3:
        return 0x64;
    case 0xE4:
        return 0x66;
    case 0x63:
    case 0x64:
        return 0x4E;
    case 0xEC:
        return 0x6A;
    case 0xED:
        return 0x6C;
    case 0xEE:
        return 0x70;
    case 0xEF:
        return 0x6E;
    case 0x103:
        return 0x72;
    case 0xE7:
        return 0x74;
    case 0xE8:
        return 0x76;
    case 0xF0:
        return 0x7A;
    case 0xF1:
        return 0x7C;
    case 0xF2:
        return 0x7E;
    case 0xF3:
        return 0x80;
    case 0xE1:
        return 0x46;
    case 0xE2:
        return 0x48;
    case 0x169:
        return 0xA5;
    case 0x17F:
        return 0xB0;
    case 0x180:
        return 0xB1;
    case 0x165:
        return 0xA3;
    case 0x16B:
        return 0xA6;
    case 0x17A:
        return 0xAE;
    case 0x178:
        return 0xA8;
    case 0x186:
        return 0xB5;
    case 0x181:
        return 0xB7;
    default:
        return 0;
    }
}



// FUN_001F0A10
void func_001f0a10(u8 *arg0) {
    memset(arg0, 0, 0x20);
}



// FUN_001F0B90
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0b90);

// FUN_001F0BF0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0bf0);

// FUN_001F0F70
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0f70);

// FUN_001F2F90
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f2f90);

// FUN_001F3870
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f3870);

// FUN_001F3950
u8 *func_001f3950(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x703, 4);
    *(void **)(packet + 0x68) = (void *)func_001f38e0;
    *(void **)(packet + 0x6C) = (void *)func_001f3900;
    *(void **)(packet + 0x70) = (void *)func_001f3930;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_001F3B20
u8 *func_001f3b20(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x702, 4);
    *(void **)(packet + 0x68) = (void *)func_001f39b0;
    *(void **)(packet + 0x6C) = (void *)func_001f39d0;
    *(void **)(packet + 0x70) = (void *)func_001f3b00;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_001F3F60
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f3f60);

// FUN_001F4040
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4040);

// FUN_001F40A0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f40a0);

// FUN_001F41E0
s32 func_001f41e0(void) {
    s32 temp_3;

    temp_3 = func_001ef720(2, 0x80000) & 0xFFFF;
    if (temp_3 > 5) {
        return -1;
    }
    if (temp_3 < 2) {
        return -1;
    }
    return 0x5E - temp_3;
}



// FUN_001F42D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f42d0);

// FUN_001F4330
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4330);

// FUN_001F4430
s32 func_001f4430(u8 *arg0, s32 arg1) {
    s32 temp_4;
    u16 temp_2;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (arg1 <= 0) {
        return -1;
    }
    if (!(func_001ef720(2, 0x80000) & 0xFFFF)) {
        return -1;
    }
    temp_4 = (5 - arg1) * 7;
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 1:
        return temp_4 + 0xFD;
    case 2:
        return temp_4 + 0xFE;
    case 3:
        return temp_4 + 0xFF;
    case 4:
        return temp_4 + 0x100;
    case 6:
        return temp_4 + 0x101;
    case 7:
        return temp_4 + 0x102;
    case 8:
        return temp_4 + 0x103;
    default:
        return -1;
    }
}



// FUN_001F4810
s32 func_001f4810(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_4;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if ((arg2 >= 6) || (arg2 <= 0)) {
        return -1;
    }
    if (arg2 == 1) {
        if ((arg1 & 2) && (func_00231d70(0x64) < 0x1E)) {
            s32 var_2_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2_2 = 0x14A;
                    break;
                case 2:
                    var_2_2 = 0x14B;
                    break;
                case 3:
                    var_2_2 = 0x14C;
                    break;
                case 4:
                    var_2_2 = 0x14D;
                    break;
                case 6:
                    var_2_2 = 0x14E;
                    break;
                case 7:
                    var_2_2 = 0x14F;
                    break;
                case 8:
                    var_2_2 = 0x150;
                    break;
                default:
                    var_2_2 = -1;
                    break;
                }
            }
            return var_2_2;
        }
        if ((arg1 & 4) && (func_00231d70(0x64) < 0x1E)) {
            s32 var_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2 = 0x143;
                    break;
                case 2:
                    var_2 = 0x144;
                    break;
                case 3:
                    var_2 = 0x145;
                    break;
                case 4:
                    var_2 = 0x146;
                    break;
                case 6:
                    var_2 = 0x147;
                    break;
                case 7:
                    var_2 = 0x148;
                    break;
                case 8:
                    var_2 = 0x149;
                    break;
                default:
                    var_2 = -1;
                    break;
                }
            }
            return var_2;
        }
    }
    temp_4 = (5 - arg2) * 7;
    switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
    case 1:
        return temp_4 + 0x120;
    case 2:
        return temp_4 + 0x121;
    case 3:
        return temp_4 + 0x122;
    case 4:
        return temp_4 + 0x123;
    case 6:
        return temp_4 + 0x124;
    case 7:
        return temp_4 + 0x125;
    case 8:
        return temp_4 + 0x126;
    default:
        return -1;
    }
}



// FUN_001F5680
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f5680);

// FUN_001F5EA0
s32 func_001f5ea0(s32 arg0) {
    return (s32)((*(u16 *)((u8 *)iGpfffb3ac + 0xA48) & (1 << (arg0 & 0xFFFF))) != 0);
}



// FUN_001F6090
s32 func_001f6090(void)
{
    func_001f62b0();
    return 1;
}

// FUN_001F6190
void func_001f6190(void)
{
    func_001f58d0();
}

// FUN_001F61B0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f61b0);

// FUN_001F6220
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6220);

// FUN_001F6290
s32 func_001f6290(void) {
    return (s32)((*(u16 *)((u8 *)iGpfffb3ac + 0xA4E) & 1) != 0);
}



// FUN_001F6710
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6710);

// FUN_001F68E0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f68e0);

// FUN_001F6BF0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6bf0);

// FUN_001F7260
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f7260);

// FUN_001F73C0
void func_001f73c0(void)
{
}

// FUN_001F75B0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f75b0);

// FUN_001F7AD0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f7ad0);

// FUN_001F83B0
void func_001f83b0(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90B, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8380;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F8430
void func_001f8430(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90C, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8400;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F9080
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9080);

// FUN_001F9740
s32 func_001f9740(void)
{
    return -1;
}

// FUN_001F9750
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9750);

// FUN_001F9A50
void func_001f9a50(s32 arg0, s32 arg1) {
    s32 f = *(u16 *)((u8 *)iGpfffb3ac + 0xB3A);
    func_0045ae10((u16)f, (u16)arg1, (u16)arg0);
}
