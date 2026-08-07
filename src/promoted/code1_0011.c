#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb1b4;

extern s32 D_005E45E0[];

extern u8 D_0079B6D8[];

extern s8 D_005E3A00[];

s32 func_0029e970(void);
void func_0029e980(s32);

void func_00106390(s32, s32);

extern s32 uGpffffb1bc;
extern void func_001104d0(s32 seed, s32 *month, s32 *day);



// FUN_001104A0
s32 func_001104a0(s32 arg0)
{
    return D_005E45E0[(arg0 - 1) % 12];
}



// FUN_001105B0
s32 func_001105b0(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    func_001104d0(arg0, &sp1C, &sp18);
    sp18 = (sp18 - 1) / 7;
    return sp18 + 1;
}

/* The month index is walked in the PARAMETER, not a fresh local: retail keeps
   it in $a0 for the whole loop, and any separate `cur` local rotates the three
   live values through $a3/$a2/$a0 instead (identical instruction sequence,
   11 differing words). */
// FUN_00110600
s32 func_00110600(s32 arg0, s32 arg1) {
    s32 sum = 0;
    s32 next;

    if (arg0 != 4) {
        arg0 = arg0 - 1;
        if (arg0 == 0) {
            arg0 = 12;
        }
        do {
            next = arg0 - 1;
            sum = sum + D_005E45E0[next % 12];
            if (arg0 == 4) {
                break;
            }
            arg0 = next;
            if (next == 0) {
                arg0 = 12;
            }
        } while (1);
    }
    return sum + (arg1 - 1);
}

// FUN_00110680
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110680);

// FUN_00110810
void func_00110810(s32 arg0, s8 arg1)
{
    D_0079B6D8[arg0] = arg1;
}



// FUN_00110D30
s32 func_00110d30(s32 arg0)
{
    return D_005E3A00[arg0 * 6] != 0;
}



// FUN_00110E70
void func_00110e70(s32 arg0)
{
    iGpffffb1b4 = arg0;
}

// FUN_00110E80
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110e80);

// FUN_00110FC0
void func_00110fc0(void) {
    func_00260560();
    func_00122520(1, 1);
    func_001029a0(0x1B, 0, 0, 8);
}

// FUN_00111010
void func_00111010(void)
{
    s32 temp_2;

    if ((temp_2 = func_0029e970()) != 0) {
        func_0029e980(temp_2);
    }
}



// FUN_00111050
void func_00111050(s32 arg0)
{
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
    if (arg0 != 0) {
        uGpffffb1bc = 0;
    }
}
