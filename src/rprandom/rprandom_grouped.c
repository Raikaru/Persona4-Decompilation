/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
/* Measured file idiom: tight no_branch_likely on/off brackets reproduce retail's plain beqz/equality branches in seven functions; preserve them when adding bodies. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
u64 func_003b7a80(u64 value);
u64 func_003b82b0(u64 value);
u32 func_003b83f0(int object);
u32 func_003b8510(int object);
u64 func_003b88c0();
u64 func_003bf1c0(u64 value);
u64 func_003bf1f0(u64 value);
u64 func_003bf320(u64 value);
u64 func_003c38a0(u64 value);
u64 func_003cad80(u64 value);
u64 func_003caee0(u64 value);
u64 func_003e3800(u64 value);
u64 func_003e3810(u64 value);
u64 func_003e3820(u64 value);
extern s32 D_00886490[];
extern s32 D_00886498[];
extern u32 DAT_00886498_abs[];
extern s32 func_003e8930(s32 arg0, s32 arg1, void *arg2, void *arg3);
extern s32 func_003c1ab0(s32 arg0, s32 arg1, void *arg2, void *arg3, void *arg4);
extern s32 func_003c1b10(s32 arg0, void *arg1, void *arg2, void *arg3);
extern s32 func_003c1b40(s32 arg0, void *arg1);
extern s32 func_003b7450(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_003b88d0(s32 arg0);
extern s32 func_003c1b60(s32 arg0, void *arg1);
extern s32 func_003c2b70(s32 arg0, s32 arg1, void *arg2, void *arg3, void *arg4);
extern s32 func_003c2ba0(s32 arg0, void *arg1, void *arg2, void *arg3);
extern void func_003b7860();
extern void func_003b7970();
extern void func_003b79f0();
extern void func_003b7a10();
extern s32 func_003b7a90(s32 arg0);
extern s32 func_003b7ad0(s32 arg0);
extern s32 func_003b7b00(s32 arg0, s32 arg1);
extern s32 func_003c1b80(s32 arg0);
extern s32 func_003b7b20(s32 arg0);
extern s32 func_003b7bb0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_003b7c10(u8 *arg0);
extern s32 *func_003b7ca0(s32 *arg0, s32 arg1, u8 *arg2);
extern u8 *func_003b7e00(u8 *arg0, s32 arg1, u8 *arg2);
extern u8 *func_003b8050(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern s32 func_003b82c0(void);
extern s32 D_00886494[];
extern s32 iGpffffb6b4;
extern s32 iGpffffb6b0;
extern u8 D_008872E0[];
extern s32 iGpffffb710;
extern s32 iGpffffb718;
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_003b7480(u8 *arg0, s32 arg1);
extern void func_003b7150(u8 *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void (*jtbl_008873FC[])(s32 arg0, u8 *arg1);
extern s32 D_008864A8[];
extern void func_003c0880(s32 arg0, s32 arg1);
extern void func_003c08c0(s32 arg0, s32 arg1);
extern void func_003c3cc0(s32 arg0);
extern void func_003e8440(s32 arg0);
extern s32 func_003c3980(void);
extern s32 func_003e5250(void);
extern void func_003cbcf0(s32 arg0, s32 arg1);
extern s32 func_003e8960(s32 arg0);
extern u8 *func_003b85e0(u8 *arg0);
extern void func_003b8d40(u8 *arg0, s32 arg1);
extern u8 *(*D_008873F8[])(s32 arg0, s32 arg1);
extern u8 *func_003b7290(u8 *arg0, void *arg1);
extern void func_003b7510(u8 *arg0, s32 arg1, u32 arg2);
extern void func_003b7590(u8 *arg0, void *arg1, void *arg2, void *arg3,
                          u32 *arg4, u32 arg5);
extern s32 func_003b7680(u8 *arg0, s32 arg1, u32 arg2, u32 arg3,
                          void *arg4, void *arg5, void *arg6, s32 arg7);
extern s32 func_003b8ad0(u8 *arg0, u8 *arg1);
extern s32 func_003df300(u8 *arg0, void *arg1, s32 arg2);
extern s32 func_003df360(u8 *arg0, void *arg1, s32 arg2);
extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
extern s32 func_003e2ce0(u8 *arg0, s32 arg1);
extern u8 *func_003b8410(u8 *arg0, u8 *arg1);


/* Source unit: src/rprandom/rprandom_003b7a80.c (1 function markers) */
/* measured: removing this pragma takes func_003b7a80 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003B7A80
u64 func_003b7a80(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b82b0.c (1 function markers) */
/* measured: removing this pragma takes func_003b82b0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

// FUN_003B7A90
s32 func_003b7a90(s32 arg0)
{
    func_0043f9c8((void *)(arg0 + D_00886494[0]), 0, 4);
    return arg0;
}

// FUN_003B7AD0
/* measured: no_branch_likely on selects retail's plain beqz/nop guard. */
#pragma no_branch_likely on
s32 func_003b7ad0(s32 arg0)
{
    s32 *temp = (s32 *)(arg0 + D_00886494[0]);
    if (*temp == 0) {
        goto done;
    }
    *temp = 0;
done:
    return arg0;
}
/* measured: close no_branch_likely around func_003b7ad0. */
#pragma no_branch_likely off

// FUN_003B7B00
s32 func_003b7b00(s32 arg0, s32 arg1)
{
    *(s32 *)(arg0 + D_00886494[0]) = *(s32 *)(arg1 + D_00886494[0]);
    return arg0;
}
/* measured: no_branch_likely on selects retail's plain branches and prologue ordering. */
// FUN_003B7B20
#pragma no_branch_likely on
s32 func_003b7b20(s32 arg0)
{
    s32 var_17;
    u8 *object;
    var_17 = 1;
    object = (u8 *)arg0;

    if (func_003e8960(0x120) != -1) {
        goto check_status;
    }
check_object:
    if (*(u8 **)(object + 0x18) == NULL) {
        goto done;
    }
    if (func_003b83f0((int)*(u8 **)(object + 0x18)) == 0) {
        goto done;
    }
    func_003b7480(object, var_17);
done:
    return 1;
check_status:
    if (*(u8 *)(object + func_003c1b80(0x120)) != 0) {
        var_17 = 2;
    }
    goto check_object;
}
#pragma no_branch_likely off


// FUN_003B7BB0
/* measured: no_branch_likely on selects retail's plain beqz tests. */
#pragma no_branch_likely on
s32 func_003b7bb0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *temp_4 = *(u8 **)(arg0 + 0x18);
    if ((temp_4 != NULL) && (func_003b83f0((int)temp_4) != 0)) {
        func_003b7480(arg0, arg3);
    }
    return 1;
}
/* measured: close no_branch_likely around func_003b7bb0. */
#pragma no_branch_likely off

// FUN_003B7C10
/* measured: no_branch_likely on selects retail's plain pointer branches. */
#pragma no_branch_likely on
s32 func_003b7c10(u8 *arg0)
{
    s32 temp_16;
    s32 temp_5_2;
    s32 temp_6;
    s32 temp_7;
    s32 var_2;
    u8 *temp_5;

    var_2 = 0;
    temp_5 = *(u8 **)(arg0 + DAT_00886498_abs[0]);
    if (temp_5 == NULL) {
        goto done;
    }
    if ((*(s32 *)(arg0 + 8) & 0x01000000) != 0) {
        goto special;
    }
    temp_7 = *(s32 *)(arg0 + 0x14);
    temp_6 = 4;
    temp_6 += *(s32 *)(temp_5 + 4);
    temp_5_2 = temp_6;
    temp_5_2 += temp_7 * 4;
    temp_16 = temp_5_2;
    temp_16 += temp_7 * 0x10;
    temp_16 += *(s32 *)(temp_5 + 0) << 6;
    var_2 = temp_16 + func_003b7450((s32 *)temp_5, temp_5_2, temp_6, temp_7);
    goto done;
special:
    var_2 = func_003b88d0((s32)arg0);
done:
    return var_2;
}
/* measured: close no_branch_likely around pointer family probe. */
#pragma no_branch_likely off

// FUN_003B7CA0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7ca0);
// FUN_003B7E00
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7e00);

// FUN_003B8050
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b8050);
// FUN_003B82B0
u64 func_003b82b0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b83f0.c (1 function markers) */


#pragma schedule on

// FUN_003B82C0
s32 func_003b82c0(void) { return 0; }

// FUN_003B82D0
s32 func_003b82d0(void)
{
    D_00886490[0] = func_003e8930(0, 0x116, (void *)func_003b7860, (void *)func_003b7970);
    D_00886494[0] = func_003c1ab0(4, 0x116, (void *)func_003b7a90, (void *)func_003b7ad0, (void *)func_003b7b00);
    func_003c1b10(0x116, (void *)func_003b8050, (void *)func_003b82b0, (void *)func_003b82c0);
    func_003c1b40(0x116, (void *)func_003b7b20);
    func_003c1b60(0x116, (void *)func_003b7bb0);
    D_00886498[0] = func_003c2b70(4, 0x116, (void *)func_003b79f0, (void *)func_003b7a10, (void *)func_003b7a80);
    func_003c2ba0(0x116, (void *)func_003b7e00, (void *)func_003b7ca0, (void *)func_003b7c10);
    return 1;
}

// FUN_003B83D0
s32 func_003b83d0(s32 arg0, s32 arg1)
{
    *(s32 *)(arg0 + D_00886494[0]) = arg1;
    return arg0;
}
/* measured: removing the schedule on/off bracket takes func_003b83f0 nd 0 -> nd 6: retail loads in the jr $ra delay slot; unscheduled it emits lw; jr; nop. */
// FUN_003B83F0
u32 func_003b83f0(int object)
{
    return *(u32 *)(object + DAT_00886498_abs[0]);
}
#pragma schedule off

/* Source unit: src/rprandom/rprandom_003b8510.c (1 function markers) */
/* measured: removing this pragma takes func_003b8510 nd 0 -> nd 6: retail fills the jr $ra delay slot with lw $v0, 0xc($a0); baseline -O2 emits lw; jr; nop. */
#pragma optimization_level 3

// FUN_003B8410
/* measured: no_branch_likely on selects retail's plain pointer-equality branch. */
#pragma no_branch_likely on
u8 *func_003b8410(u8 *arg0, u8 *arg1)
{
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + DAT_00886498_abs[0]);
    if (arg1 != temp_2) {
        if (temp_2 != NULL) {
            func_003b88c0();
        }
        *(u8 **)(arg0 + DAT_00886498_abs[0]) = arg1;
        if ((arg1 != NULL) && (func_003b85e0(arg0) == 0)) {
            return NULL;
        }
    }
    return arg0;
}
/* measured: close no_branch_likely around func_003b8410. */
#pragma no_branch_likely off
// FUN_003B84A0
/* measured: no_branch_likely on selects retail's plain null branch. */
#pragma no_branch_likely on
s32 func_003b84a0(u8 *arg0)
{
    u8 *temp_4 = *(u8 **)(arg0 + 0x44);
    if (temp_4 != NULL) {
        jtbl_008873EC[0](temp_4);
    }
    func_003b7150(arg0);
    jtbl_008873FC[0](D_008864A8[0], arg0);
    return 0;
}
/* measured: close no_branch_likely around func_003b84a0. */
#pragma no_branch_likely off

// FUN_003B8500
u32 func_003b8500(int object) { return *(u32 *)(object + 0); }
// FUN_003B8510
u32 func_003b8510(int object) { return *(u32*)(object + 0xc); }
#pragma optimization_level 2
/* measured: removing this pragma takes func_003b88c0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

// FUN_003B8520
/* measured: no_branch_likely on selects retail's plain status branches. */
#pragma no_branch_likely on
void func_003b8520(u8 *arg0, s32 arg1)
{
    s32 var_16;

    var_16 = arg1;
    if (func_003e8960(0x120) != -1) {
        goto check_second;
    }
    if (var_16 != 2) {
        goto check_second;
    }
    var_16 = 1;
call:
    func_003b8d40(arg0, var_16);
    return;
check_second:
    if (func_003e8960(0x12e) == -1) {
        if (var_16 == 3) {
            var_16 = 1;
        }
    }
    goto call;
}
#pragma no_branch_likely off

// FUN_003B85B0
/* measured: no_branch_likely on selects retail's plain bne branch. */
#pragma no_branch_likely on
s32 func_003b85b0(u8 *arg0)
{
    u8 *temp_4 = *(u8 **)(arg0 + 0x6c);
    if (*(s32 *)(temp_4 + 0x2c) == 0x116) {
        return *(s32 *)(temp_4 + 0x30);
    }
    return 0;
}
/* measured: close no_branch_likely around func_003b85b0. */
#pragma no_branch_likely off

// FUN_003B85E0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b85e0);
// FUN_003B88C0
u64 func_003b88c0(u64 value) { return value; }
#pragma optimization_level 2
/* Source unit: src/rprandom/rprandom_003bf1c0.c (1 function markers) */
/* measured: removing this pragma takes func_003bf1c0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003BF1C0
u64 func_003bf1c0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf1f0.c (1 function markers) */
/* measured: removing this pragma takes func_003bf1f0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

// FUN_003BF1D0
s32 func_003bf1d0(s32 arg0)
{
    u8 *temp = (u8 *)(arg0 + iGpffffb6b4);
    *(s32 *)(temp + 8) = 0;
    *(s32 *)(temp + 4) = 0;
    *(s32 *)temp = 0;
    return arg0;
}
// FUN_003BF1F0
u64 func_003bf1f0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf320.c (1 function markers) */
/* measured: removing this pragma takes func_003bf320 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003BF200
s32 func_003bf200(s32 arg0)
{
    func_003c0880(*(s32 *)(arg0 + iGpffffb6b4), arg0);
    func_003c3cc0(arg0);
    return arg0;
}

// FUN_003BF240
s32 func_003bf240(s32 arg0)
{
    func_003c08c0(*(s32 *)(arg0 + iGpffffb6b0), arg0);
    func_003e8440(arg0);
    return arg0;
}

// FUN_003BF280
s32 func_003bf280(s32 arg0, s32 *arg1)
{
    *arg1 += 0x10;
    *arg1 += func_003c3980() + 0xc;
    return arg0;
}

// FUN_003BF2D0
s32 func_003bf2d0(s32 arg0, s32 *arg1)
{
    *arg1 += 0x10;
    *arg1 += func_003e5250() + 0xc;
    return arg0;
}

// FUN_003BF320
u64 func_003bf320(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003c38a0.c (1 function markers) */
/* measured: removing this pragma takes func_003c38a0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003C38A0
u64 func_003c38a0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003cad80.c (1 function markers) */
/* measured: removing this pragma takes func_003cad80 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003CAD80
u64 func_003cad80(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003caee0.c (1 function markers) */
/* measured: removing this pragma takes func_003caee0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

// FUN_003CAD90 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003cad90);

// FUN_003CAE70
s32 func_003cae70(s32 arg0)
{
    u8 *temp = (u8 *)(arg0 + iGpffffb710);
    *(s32 *)temp = 0;
    *(s32 *)(temp + 4) = *(s32 *)((u8 *)D_008872E0 + iGpffffb718 + 8);
    return arg0;
}

// FUN_003CAEA0
/* measured: no_branch_likely on selects retail's plain beqz branch. */
#pragma no_branch_likely on
s32 func_003caea0(s32 arg0, s32 arg1)
{
    s32 temp_4 = *(s32 *)(arg1 + iGpffffb710);
    if (temp_4 != 0) {
        func_003cbcf0(temp_4, arg0);
    }
    return arg0;
}
/* measured: close no_branch_likely around func_003caea0. */
#pragma no_branch_likely off

// FUN_003CAEE0
u64 func_003caee0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3800.c (1 function markers) */
/* measured: removing this pragma takes func_003e3800 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003E3800
u64 func_003e3800(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3810.c (1 function markers) */
/* measured: removing this pragma takes func_003e3810 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003E3810
u64 func_003e3810(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3820.c (1 function markers) */
/* measured: removing this pragma takes func_003e3820 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003E3820
u64 func_003e3820(u64 value) { return value; }
#pragma optimization_level 2
