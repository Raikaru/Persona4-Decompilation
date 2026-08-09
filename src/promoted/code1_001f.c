#include "include_asm.h"
#include "type.h"
extern s32 func_00232710(s32 arg0, s32 arg1);

extern void func_001f62b0();
extern void func_001f58d0();

extern void memset(void *destination, s32 value, u32 size);

extern s32 func_001ef720(s32 arg0, s32 arg1);

extern u32 func_00231d70(s32 arg0);

extern u8 *iGpfffb3ac;
extern u8 *iGpffffb3b8;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern void func_001f65d0(void);
extern s32 func_001ef9a0(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_00459880(void);

extern void func_00454bd0(u8 *arg0);
extern void func_002bd3c0(void);

extern void func_0045ae10(u16 arg0, u16 arg1, u16 arg2);
extern void func_0045aa90();



extern void func_001f38e0(u8 **arg0);
extern void func_001f3900(void);
extern void func_001f3930(void);
extern void *func_00194470();

extern void func_001f39b0(u8 **arg0);
extern void func_001f37b0(void);
extern void func_001f37d0(void);
extern void func_001f3850(void);

extern void func_001f39d0(void);
extern void func_001f3b00(void);

extern s32 func_001f8380(u8 **arg0);

extern s32 func_001f8400(u8 **arg0);

// FUN_001F01A0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f01a0);
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



// FUN_001F0620
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0620);
// FUN_001F08C0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f08c0);
// FUN_001F0950
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0950);
// FUN_001F0A10
void func_001f0a10(u8 *arg0) {
    memset(arg0, 0, 0x20);
}



// FUN_001F0A50
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0a50);
// FUN_001F0AF0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0af0);
// FUN_001F0B90
/* The two 0xFFFF masks are spelled differently on purpose: retail re-masks
   the counter separately for the index and for the loop bound, and writing
   both as `i & 0xFFFF` lets b210 common-subexpression them into one andi
   (nd 57, one word short). */
s32 func_001f0b90(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xE4) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

// FUN_001F0BF0
/* Mask spelling as in func_001f0b90: `(u16)i` for the index and
   `i & 0xFFFF` for the bound, so b210 does not fold retail's two andi
   instructions into one. */
s32 func_001f0bf0(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if ((*(u16 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xDE) & 6) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

// FUN_001F0C50
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0c50);
// FUN_001F0D30
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0d30);
// FUN_001F0DD0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0dd0);
// FUN_001F0F70
u32 func_001f0f70(u8 *arg0)
{
    u8 *target;
    s32 targetCount;
    s32 targetIndex;

    targetIndex = 0;
    targetCount = *(u16 *)(arg0 + 0x6A);
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = *(u8 **)(arg0 + 0x38 + (u32)(u16)targetIndex * 4);
        if (*(s32 *)(target + 0xE4) != 0) {
            return 1;
        }
        if ((*(u16 *)(target + 0xDC) & 0x500) != 0) {
            return 1;
        }
    }
    return 0;
}

// FUN_001F0FF0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f0ff0);
// FUN_001F1030
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f1030);
// FUN_001F11E0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f11e0);
// FUN_001F1210
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f1210);
// FUN_001F12B0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f12b0);
// FUN_001F14F0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f14f0);
// FUN_001F2CC0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f2cc0);
// FUN_001F2EB0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f2eb0);
// FUN_001F2F90
s32 func_001f2f90(u8 *arg0) {
    u8 *p;

    p = iGpffffb3b8 + *(s16 *)(arg0 + 0x6E) * 40;
    if ((p[0] & 2) != 0) {
        return 0;
    }
    return (p[0x24] ^ 6) != 0;
}

// FUN_001F3870
void func_001f3870(u8 *arg0, s8 arg1)
{
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)func_00194470(0x701, 8);
    *(void **)(temp_2 + 0x68) = (void *)func_001f37b0;
    *(void **)(temp_2 + 0x6C) = (void *)func_001f37d0;
    *(void **)(temp_2 + 0x70) = (void *)func_001f3850;
    temp_3 = *(u8 **)(temp_2 + 0x78);
    *(u8 **)(temp_3 + 0) = arg0;
    *(s8 *)(temp_3 + 4) = arg1;
}

// FUN_001F38E0
void func_001f38e0(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}
// FUN_001F3900
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f3900);
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

// FUN_001F39B0
void func_001f39b0(u8 **arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(*arg0 + 0x30);
    *(u16 *)(temp_4 + 0xA0) = (u16)(*(u16 *)(temp_4 + 0xA0) + 1);
}
// FUN_001F39D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f39d0);
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

// FUN_001F3B80
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f3b80);
// FUN_001F3BB0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f3bb0);
// FUN_001F3F60
s32 func_001f3f60(void)
{
    s32 state;

    state = *(s32 *)(iGpfffb3ac + 0xA58);
    if (state == 0xFC) {
        return -1;
    }
    if ((func_001ef720(1, 0x80000) & 0xFFFF) < 2) {
        return -1;
    }
    return 0xFC;
}

// FUN_001F3FE0
s32 func_001f3fe0(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0xCC;
}
// FUN_001F4010
s32 func_001f4010(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0x67;
}
// FUN_001F4040
s32 func_001f4040(u8 *arg0) {
    if (*(u8 *)((u8 *)(*(u8 **)(arg0 + 0x30)) + 0xA2) != 0) {
        return -1;
    }
    if (func_001f5ea0(0) != 0) {
        return 0xCD;
    }
    return 0xCE;
}

// FUN_001F40A0
s32 func_001f40a0(void) {
    s32 temp_3;

    temp_3 = func_001ef720(2, 0x80000) & 0xFFFF;
    if (temp_3 >= 5) {
        return -1;
    }
    if (temp_3 == 0) {
        return -1;
    }
    return 0x58 - temp_3;
}

// FUN_001F4100
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4100);
// FUN_001F41B0
s32 func_001f41b0(u8 *arg0)
{
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    return 0xCB;
}
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



// FUN_001F42A0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f42a0);
// FUN_001F42D0
s32 func_001f42d0(void) {
    if ((*(s32 *)(iGpfffb3ac + 0x10) & 0x20000000) != 0) {
        if (func_001ef9a0() == 0x20B) {
            return 0x18B;
        }
    }
    return 0x165;
}

// FUN_001F4330
s32 func_001f4330(u8 *arg0)
{
    if (*(u8 **)(iGpfffb3ac + 0x170) == arg0) {
        return 0x99;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
        return 0x5D;
    }
    return -1;
}

// FUN_001F4380
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4380);
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



// FUN_001F4550
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4550);
// FUN_001F4600
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4600);
// FUN_001F46B0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f46b0);
// FUN_001F4760
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4760);
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



// FUN_001F4AD0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4ad0);
// FUN_001F4B80
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4b80);
// FUN_001F4C30
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4c30);
// FUN_001F4CE0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4ce0);
// FUN_001F4E50
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f4e50);
// FUN_001F55B0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f55b0);
// FUN_001F5680
/* The `return -1` and `return v + 0x11` blocks are reached by goto so they
   land in retail's order; writing both as plain returns emits them the other
   way round. */
s32 func_001f5680(void) {
    u8 *p;
    s32 v;

    p = *(u8 **)(iGpfffb3ac + 0xC68);
    if (p == NULL) {
        return -1;
    }
    v = *(u16 *)(p + 2);
    if (v < 6) {
        if (v != 0) {
            goto add;
        }
    }
    return -1;
add:
    return v + 0x11;
}

// FUN_001F56D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f56d0);
// FUN_001F58D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f58d0);
// FUN_001F5A00
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f5a00);
// FUN_001F5BD0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f5bd0);
// FUN_001F5EA0
s32 func_001f5ea0(s32 arg0) {
    return (s32)((*(u16 *)((u8 *)iGpfffb3ac + 0xA48) & (1 << (arg0 & 0xFFFF))) != 0);
}



// FUN_001F5ED0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f5ed0);
// FUN_001F6090
s32 func_001f6090(void)
{
    func_001f62b0();
    return 1;
}

// FUN_001F6100
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6100);
// FUN_001F6190
void func_001f6190(void)
{
    func_001f58d0();
}

// FUN_001F61B0
void func_001f61b0(void)
{
    u8 *temp_3;
    u8 *var_4;

    var_4 = *(u8 **)(iGpfffb3ac + 0xA54);
    if (var_4 != NULL) {
        func_00454bd0(var_4);
        *(u8 **)(iGpfffb3ac + 0xA54) = NULL;
        temp_3 = iGpfffb3ac;
        *(s32 *)(temp_3 + 0xC) = *(s32 *)(temp_3 + 0xC) & 0xFEFFFFFF;
    }
    temp_3 = iGpfffb3ac;
    *(u16 *)(temp_3 + 0xA4E) = *(u16 *)(temp_3 + 0xA4E) & 0xFFFE;
    func_002bd3c0();
}

// FUN_001F6220
s32 func_001f6220(s16 arg0, s32 arg1)
{
    u8 *temp_3;

    temp_3 = iGpfffb3ac;
    if ((*(u16 *)(temp_3 + 0xA4E) & 1) != 0) {
        if (*(s32 *)(temp_3 + 0xA58) == arg1) {
            return 1;
        }
        if (*(s32 *)(temp_3 + 0xA60) == arg1) {
            return 1;
        }
    }
    *(s16 *)(temp_3 + 0xA64) = arg0;
    *(s32 *)(iGpfffb3ac + 0xA60) = arg1;
    *(s16 *)(iGpfffb3ac + 0xA50) = 1;
    return 1;
}

// FUN_001F6290
s32 func_001f6290(void) {
    return (s32)((*(u16 *)((u8 *)iGpfffb3ac + 0xA4E) & 1) != 0);
}



// FUN_001F62B0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f62b0);
// FUN_001F62F0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f62f0);
// FUN_001F65D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f65d0);
// FUN_001F6710
void func_001f6710(s32 arg0) {
    u8 *p;
    u8 *q;

    p = (u8 *)func_00194470(0x803, 8);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)func_001f65d0;
    q = *(u8 **)(p + 0x78);
    *(s16 *)(q + 4) = (s16)arg0;
    *(s16 *)(q + 6) = 0;
}

// FUN_001F6770
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6770);
// FUN_001F68E0
s32 func_001f68e0(u8 *arg0)
{
    u8 *unit;
    s32 status;

    unit = *(u8 **)(arg0 + 0x30);
    status = *(s32 *)(unit + 0xA64);
    if ((*(u16 *)(arg0 + 0x18) & 4) != 0) {
        return 0;
    }
    return (func_00232710(status, 0x60) != 0);
}

/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

// FUN_001F6930
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6930);
// FUN_001F6BF0
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
#pragma opt_loop_invariants on
s32 func_001f6bf0(u8 *arg0) {
    s32 i;
    s32 one;

    i = 0;
    one = 1;
    while ((u32)i < 0x18) {
        if ((one << i) == one) {
            return arg0[i + 0x3F6] >= 2;
        }
        i++;
    }
    return 1;
}
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
#pragma opt_loop_invariants off

// measured: required for exact retail loop codegen in func_001f7260.
#pragma opt_loop_invariants on

// FUN_001F6C40
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6c40);

// FUN_001F6CD0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6cd0);

// FUN_001F6D60
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6d60);

// FUN_001F6F60
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f6f60);

// FUN_001F7140
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f7140);
// FUN_001F7260
void func_001f7260(void)
{
    s32 offset;
    s32 empty;
    u16 i;
    u8 state;

    *(s16 *)(iGpfffb3ac + 0xAC8) = 5;
    empty = -1;
    *(s8 *)(iGpfffb3ac + 0xACA) = empty;
    i = 0;
    state = 3;
    for (; i < 0x10; i++) {
        offset = (u32)i * 6;
        *(s16 *)(iGpfffb3ac + offset + 0xACC) = empty;
        *(s16 *)(iGpfffb3ac + offset + 0xACE) = empty;
        *(s8 *)(iGpfffb3ac + offset + 0xAD0) = state;
    }
}
// measured: required for exact retail loop codegen in func_001f7260.
#pragma opt_loop_invariants off

// FUN_001F72E0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f72e0);
// FUN_001F73C0
void func_001f73c0(void)
{
}

// FUN_001F73D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f73d0);
// FUN_001F75B0
void func_001f75b0(void)
{
    if ((*(s32 *)(iGpfffb3ac + 0xC) & 0x40) != 0) {
        func_0045a9a0(1, 0);
        func_0045a9a0(2, 0);
        func_0045a9a0(3, 0);
        func_00459880();
    }
}

// FUN_001F7650
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f7650);
// FUN_001F7830
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f7830);
// FUN_001F7910
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f7910);
// FUN_001F7AD0
void func_001f7ad0(u8 *arg0)
{
    u16 temp_7;
    u8 *temp_6;
    u32 offset;

    temp_7 = *(u16 *)arg0;
    offset = temp_7 * 6;
    temp_6 = (u8 *)(offset + (u32)iGpfffb3ac);
    if ((*(s16 *)(temp_6 + 0xACC) != *(u16 *)(arg0 + 2)) ||
        (*(s16 *)(temp_6 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045aa90(1, (s16)temp_7, temp_6, temp_7);
    }
}

// FUN_001F7B40
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f7b40);
// FUN_001F8380
s32 func_001f8380(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) |= 0x40;
    }
    return 1;
}
// FUN_001F83B0
void func_001f83b0(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90B, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8380;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F8400
s32 func_001f8400(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) &= 0xFFBF;
    }
    return 1;
}
// FUN_001F8430
void func_001f8430(u32 value)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x90C, 0x4);
    *(void **)(packet + 0x6C) = (void *)func_001f8400;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
}

// FUN_001F8480
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8480);
// FUN_001F8690
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8690);
// FUN_001F86D0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f86d0);
// FUN_001F8700
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8700);
// FUN_001F8810
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8810);
// FUN_001F8920
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8920);
// FUN_001F8B00
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8b00);
// FUN_001F8B90
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8b90);
// FUN_001F8C20
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8c20);
// FUN_001F8CE0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8ce0);
// FUN_001F8D70
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8d70);
// FUN_001F8E10
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8e10);
// FUN_001F8EA0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8ea0);
// FUN_001F8F40
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8f40);
// FUN_001F8FE0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f8fe0);
// FUN_001F9080
s32 func_001f9080(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    if (p[0xA2] != 0) {
        return -1;
    }
    if (*(u8 **)(iGpfffb3ac + 0x170) == arg0) {
        return -1;
    }
    return D_00624FC0[*(u16 *)(p + 0xA4)] + 0x45;
}

// FUN_001F90E0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f90e0);
// FUN_001F92C0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f92c0);
// FUN_001F93A0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f93a0);
// FUN_001F9570
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9570);
// FUN_001F9650
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9650);
// FUN_001F9740
s32 func_001f9740(void)
{
    return -1;
}

// FUN_001F9750
s32 func_001f9750(s32 *arg0) {
    s32 r;

    if (arg0[1] == 0) {
        if (iGpffffb460 != 0) {
            arg0[0] = 0;
        }
        arg0[1] = 1;
    }
    if (arg0[0] == 0) {
        *(u16 *)(D_0076449C + 0xB2E) |= 1;
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

// FUN_001F9800
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9800);
// FUN_001F9A50
void func_001f9a50(s32 arg0, s32 arg1) {
    s32 f = *(u16 *)((u8 *)iGpfffb3ac + 0xB3A);
    func_0045ae10((u16)f, (u16)arg1, (u16)arg0);
}

// FUN_001F9A90
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9a90);
// FUN_001F9AC0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9ac0);
// FUN_001F9BE0
void func_001f9be0(void)
{
}
// FUN_001F9BF0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9bf0);
// FUN_001F9C40
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001f9c40);
// FUN_001F9CD0
void func_001f9cd0(void)
{
}
// FUN_001F9CE0
s32 func_001f9ce0(void)
{
    return 0;
}
// FUN_001FA660
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fa660);
// FUN_001FA720
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fa720);
// FUN_001FA7A0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fa7a0);
// FUN_001FA8F0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fa8f0);
// FUN_001FA940
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fa940);
// FUN_001FA9C0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fa9c0);
// FUN_001FAA00
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001faa00);
// FUN_001FAA60
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001faa60);
// FUN_001FAAA0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001faaa0);
// FUN_001FAAF0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001faaf0);
// FUN_001FAB40
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fab40);
// FUN_001FAB90
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fab90);
// FUN_001FABE0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fabe0);
// FUN_001FAC30
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fac30);
// FUN_001FAC80
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fac80);
// FUN_001FAD10
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fad10);
// FUN_001FADC0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fadc0);
// FUN_001FAE10
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fae10);
// FUN_001FAE60
void func_001fae60(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(D_0076449C + 0xB40) = arg0;
    *(s32 *)(D_0076449C + 0xB44) = arg1;
    *(s32 *)(D_0076449C + 0xB48) = arg2;
}
// FUN_001FAE80
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fae80);
// FUN_001FAF70
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001faf70);
// FUN_001FB170
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fb170);
// FUN_001FB1F0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fb1f0);
// FUN_001FB360
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fb360);
// FUN_001FB480
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fb480);
// FUN_001FBB50
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fbb50);
// FUN_001FC1B0
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fc1b0);
// FUN_001FC270
s32 func_001fc270(void)
{
    return 1;
}
// FUN_001FC280
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fc280);
// FUN_001FC300
INCLUDE_ASM("asm/nonmatchings/code1_001f", func_001fc300);