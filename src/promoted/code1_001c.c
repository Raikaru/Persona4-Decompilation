#include "include_asm.h"
#include "type.h"
extern void func_001bdeb0();
extern void func_001c9820(u8 *arg0, s32 arg1, s32 arg2, f32 arg3);
extern void func_001ce620(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_001ce8c0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_001b73f0(void *arg0);
extern void func_004b3110(s32 arg0);
extern void func_001bab00(u8 *arg0, u8 *arg1);
extern void func_001c6f40(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4);
extern void func_001cfad0(u8 *arg0, f32 arg1, f32 arg2);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac;
extern f32 fGpffff811c;
extern void func_001bcd40(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3, s32 arg4);
extern void func_001ca590(u8 *arg0, f32 arg1, f32 arg2);
extern void func_001cacd0(u8 *arg0, f32 arg1, f32 arg2);
extern void func_0019de70(u8 *arg0, u16 arg1);
extern s32 func_001bc560(u8 *arg0, u8 *arg1);
extern s16 func_001d7f10(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_001d8df0(u8 *arg0);
extern void func_001c8e90(u8 *arg0, f32 *arg1, f32 *arg2);
extern void func_001bac20(u8 *arg0, f32 *arg1, f32 *arg2, s32 arg3);
extern void func_001bbef0(u8 *arg0, f32 arg1);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 func_004bd050(s32 arg0);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern s32 func_001f0ff0(u8 *arg0);
extern void func_001c2ee0(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

// FUN_001C04E0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c04e0);
// FUN_001C09A0
void func_001c09a0(void) {}
// FUN_001C09B0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c09b0);
// FUN_001C0E40
void func_001c0e40(void) {}
// FUN_001C0E50
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c0e50);
// FUN_001C1040
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c1040);
// FUN_001C17A0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c17a0);
// FUN_001C1F70
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c1f70);
// FUN_001C21D0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c21d0);
// FUN_001C2EE0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c2ee0);
// FUN_001C3EB0
void func_001c3eb0(u8 *arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((temp_4 != NULL) && ((*(u16 *)(temp_4 + 0x1A) & 1) != 0)) {
        if (*(s32 *)(arg0 + 0xDC) == 0) {
            if (arg1 == 0) {
                func_001bcd40(temp_4, NULL, NULL, 0.0f, 3);
            } else {
                func_001bcd40(temp_4, NULL, NULL, 0.0f, 0x11);
            }
        }
        if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
            func_0019de70(*(u8 **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}
// FUN_001C3F70
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c3f70);
// FUN_001C5110
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c5110);
// FUN_001C52C0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c52c0);
// FUN_001C5500
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c5500);
// FUN_001C5B80
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c5b80);
// FUN_001C79E0
void func_001c79e0(void) {}
// FUN_001C79F0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c79f0);
// FUN_001C80F0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c80f0);
// FUN_001C88D0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c88d0);
// FUN_001C8B00
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c8b00);
/* measured: optimization_level 1 probe for c8cf0 argument order. */
#pragma optimization_level 1
// FUN_001C8CF0
void func_001c8cf0(u8 *arg0)
{
    u8 *temp_16;
    u8 *call_arg0;
    s32 call_arg1;
    s32 call_arg2;

    temp_16 = *(u8 **)(arg0 + 0xE0);
    call_arg0 = temp_16;
    call_arg1 = 0;
    call_arg2 = *(u16 *)(temp_16 + 0x6E);
    *(s16 *)(arg0 + 0x106) = func_001d7f10((s32)call_arg0, call_arg1, call_arg2, 0);
    *(s16 *)(arg0 + 0x104) = func_001d8df0(temp_16 + 0x98);
    *(s32 *)(arg0 + 0x100) = 0;
}
/* measured: close optimization_level after c8cf0. */
#pragma optimization_level 2
// FUN_001C8D50
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c8d50);
// FUN_001C8E90
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c8e90);
// FUN_001C9750
void func_001c9750(u8 *arg0)
{
    struct Work {
        f32 first;
        u8 gap[0x18];
        f32 second;
        u8 tail[0x20];
    } work;

    func_001c8e90(arg0, &work.first, &work.second);
    func_001bac20(arg0, &work.first, &work.second, 1);
    func_001bbef0(arg0, fGpffff811c);
}
// FUN_001C97B0
void func_001c97b0(u8 *arg0)
{
    u8 *temp_4;
    f32 value;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((temp_4 != NULL) &&
        (*(u16 *)(temp_4 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x124) == *(s32 *)(temp_4 + 0x38)) &&
        ((*(u16 *)(temp_4 + 0x1A) & 1) != 0)) {
        value = *(f32 *)(arg0 + 0x10C);
        func_001bcd40(temp_4, arg0 + 0x9C, arg0 + 0x100, value, 0xC3);
    }
}
// FUN_001C9820
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c9820);
// FUN_001CA550
void func_001ca550(u8 *arg0) {
    func_001c9820(arg0, 0, 0, 50.0f);
}
// FUN_001CA590
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001ca590);
// FUN_001CACD0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cacd0);
// FUN_001CB0F0
void func_001cb0f0(u8 *arg0)
{
    u8 *temp_5;
    u8 *temp_6;
    u16 temp_5_2;

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if (*(u8 *)(*(u8 **)(temp_5 + 0x30) + 0xA2) != 0) {
        return;
    }
    *(s32 *)(arg0 + 0x128) = *(s32 *)(temp_5 + 0x38);
    temp_6 = iGpffffb3ac;
    if ((*(s32 *)(temp_6 + 0xC) & 0x200000) == 0) {
        temp_5_2 = *(u16 *)(temp_6 + 0x10E);
        switch (temp_5_2) {
        case 0:
            func_001ca590(arg0, 40.0f, 2.0f);
            return;
        case 1:
            func_001cacd0(arg0, 100.0f, 3.0f);
            return;
        }
    } else {
        temp_5_2 = *(u16 *)(temp_6 + 0x10E);
        switch (temp_5_2) {
        case 0:
            func_001ca590(arg0, 20.0f, 2.0f);
            return;
        case 1:
            func_001cacd0(arg0, 50.0f, 3.0f);
            return;
        }
    }
}
// FUN_001CB200
void func_001cb200(u8 *arg0)
{
    s32 temp_5;
    u16 temp_3;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    temp_5 = 0;
    if ((temp_4 != NULL) &&
        (*(u16 *)(temp_4 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x128) == *(s32 *)(temp_4 + 0x38)) &&
        ((temp_5 = *(u16 *)(temp_4 + 0x1A) & 1, temp_5 != 0)) &&
        (*(u8 *)(*(u8 **)(temp_4 + 0x30) + 0xA2) == 0)) {
        temp_3 = *(u16 *)(iGpffffb3ac + 0x10E);
        switch (temp_3) {
        case 0:
            if ((temp_4 != NULL) && (temp_5 != 0)) {
                func_001bcd40(temp_4, arg0 + 0x9C, arg0 + 0x100,
                              *(f32 *)(arg0 + 0x10C), 0xC3);
                return;
            }
            break;
        case 1:
        default:
            if ((temp_4 != NULL) && (temp_5 != 0)) {
                func_001bcd40(temp_4, arg0 + 0x9C, arg0 + 0x100,
                              *(f32 *)(arg0 + 0x10C), 0xC3);
            }
            break;
        }
    }
}
// FUN_001CB2E0
void func_001cb2e0(u8 *arg0)
{
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA4);
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = (value & 0xFFFF) * 0x1E8;
    target = (u8 *)&D_005F7CA0 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 2);
}
// FUN_001CB380
void func_001cb380(void) {
    func_001bdeb0();
}
// FUN_001CB3A0
void func_001cb3a0(u8 *arg0)
{
    u8 *temp;
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    temp = *(u8 **)(arg0 + 0xE0);
    value = *(u16 *)(*(u8 **)(temp + 0x30) + 0xA4);
    func_001b73f0(*(u8 **)(temp + 0x30));
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
    target = (u8 *)&D_005F91A0 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 2);
}
// FUN_001CB440
void func_001cb440(void) {
    func_001bdeb0();
}
// FUN_001CB460
void func_001cb460(u8 *arg0)
{
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA4);
    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        flag_offset = (func_004bd050(0) & 1) * 0xF4;
        index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
        target = (u8 *)&D_005FA2D0 + index_offset;
        func_001bdd80(arg0, target + flag_offset, 2);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 3);
    } else {
        func_001c2ee0(arg0, 0, 1);
    }
}
// FUN_001CB540
void func_001cb540(u8 *arg0)
{
    u8 *temp;

    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        func_001bdeb0(arg0);
        goto done;
    }
    temp = *(u8 **)(arg0 + 0xE0);
    if (temp == NULL)
        goto done;
    if (*(s32 *)(arg0 + 0xD8) != 0)
        goto done;
    if (temp == NULL)
        goto done;
    if ((*(u16 *)(temp + 0x1A) & 1) == 0)
        goto done;
    if (*(s32 *)(arg0 + 0xDC) == 0) {
        func_001bcd40(temp, NULL, NULL, 0.0f, 0x11);
    }
    if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
        func_0019de70(*(u8 **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
    }
done:
    ;
}
// FUN_001CB610
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cb610);
// FUN_001CB960
void func_001cb960(void) {}
// FUN_001CB970
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cb970);
// FUN_001CBF80
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cbf80);
// FUN_001CE470
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001ce470);
// FUN_001CE620
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001ce620);
// FUN_001CE7F0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001ce7f0);
// FUN_001CE880
void func_001ce880(u8 *arg0) {
    func_001ce620(arg0, -17.5f, 0.25f, 0.75f);
}
// FUN_001CE8C0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001ce8c0);
// FUN_001CEBA0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001ceba0);
// FUN_001CECB0
void func_001cecb0(u8 *arg0) {
    func_001ce8c0(arg0, -16.0f, fGpffff8198, fGpffff80fc);
}
// FUN_001CECE0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cece0);
// FUN_001CEF20
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cef20);
// FUN_001CEFB0
void func_001cefb0(u8 *arg0) {
    func_001ce620(arg0, -10.0f, 0.125f, fGpffff809c);
}
// FUN_001CEFF0
void func_001ceff0(void) {
    func_001b73f0(NULL);
    func_004b3110(5);
}
// FUN_001CF020
void func_001cf020(u8 *arg0) {
    u8 sp20[0x20];

    func_001c6f40(arg0, 0, 0, 0, sp20);
    func_001bab00(arg0, sp20);
}
// FUN_001CF070
void func_001cf070(u8 *arg0, u8 *arg1)
{
    s16 mode;
    u8 *target;

    mode = *(s16 *)(*(u8 **)(arg0 + 0xE0) + 0x448);
    target = arg1;
    switch (mode) {
    case 1:
        target = (u8 *)&D_005F78C0 + (func_004bd050(0) & 1) * 0xF4;
        break;
    case 0:
        target = (u8 *)&D_005F7AB0 + (func_004bd050(0) & 1) * 0xF4;
        break;
    }
    func_001bdd80(arg0, target, 2);
    func_004b3110(5);
}
// FUN_001CF140
void func_001cf140(void) {
    func_001bdeb0();
}
// FUN_001CF160
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cf160);
// FUN_001CF1F0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cf1f0);
// FUN_001CF350
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cf350);
// FUN_001CF730
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cf730);
// FUN_001CFAD0
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cfad0);
// FUN_001CFED0
void func_001cfed0(u8 *arg0) {
    func_001cfad0(arg0, fGpffff8114, 2.5f);
}
// FUN_001CFF00
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001cff00);