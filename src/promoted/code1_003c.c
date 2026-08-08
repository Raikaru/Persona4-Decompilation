#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])();
extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 func_003c5760(u8 *arg0);
extern s32 func_003c2bd0(u8 *arg0);
extern s32 func_003c4c00(u8 *arg0);
extern s32 func_003e3370(u8 *desc, u8 *arg1);
extern s32 func_003e3c20(u8 *desc, u8 *arg1);
extern s32 func_003e6240(u8 *arg0);
extern void func_003efda0(u8 *arg0);
extern void func_003ef3a0(u8 *arg0);
typedef struct { f32 x, y, z, w; } Vec4f;

extern u8 D_0070AFB0[];
extern u8 D_008872E0[];
/* gp - 0x4648 = 0x00764aa8 */
extern s32 iGpffffb9b8;
/* gp - 0x48F8 = 0x007647f8 */
extern s32 iGpffffb708;
extern s64 iGpffffb8f0;
/* gp - 0x48F4 = 0x007647fc */
extern s32 iGpffffb70c;
extern void func_003e9680(u8 *arg0);
extern u8 func_003ca740[];
extern u8 func_003ca780[];
extern u8 func_003ca7a0[];
u8 *func_003cbc10(u8 *arg0, u8 *arg1);
void func_003f32d0();
extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);
extern void (*jtbl_008873E8[])(u8 *arg0, s32 arg1);
/* gp - 0x4930 = 0x007647c0 */
extern s32 iGpffffb8d0;
/* gp - 0x492C = 0x007647c4 */
extern s32 iGpffffb8d4;
/* gp - 0x4920 = 0x007647d0 */
extern s32 iGpffffb8e0;
/* gp - 0x491C = 0x007647d4 */
extern s32 iGpffffb8e4;
/* gp - 0x4918 = 0x007647d8 */
extern u8 *iGpffffb8e8;
/* gp - 0x490C = 0x007647e4 */
extern s32 iGpffffb8f4;
extern void func_003e18c0(u8 *arg0, void *arg1, s32 arg2);
extern void func_003e12f0(u8 *arg0);
extern void func_003c3890(void);
extern u8 D_0070AFD0[];
extern u8 D_0070AFF0[];
extern u8 *func_003c9c20(u32 arg0);
extern s32 func_003c5a90(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 D_007647CC;
extern s32 D_007647C8;


extern s32 D_007647BC;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 15 -> 0). */


// FUN_003C1D20
#pragma schedule on
s32 func_003c1d20(s32 arg0) {
    D_007647BC--;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 13 -> 0). */

// FUN_003C2130
#pragma schedule on
s32 func_003c2130(s32 arg0, u8 *arg1, s16 arg2, s16 arg3, s16 arg4) {
    ((s16 *)arg1)[0] = arg2;
    ((s16 *)arg1)[1] = arg3;
    ((s16 *)arg1)[2] = arg4;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colors the halfword scratch $v0; retail fills the slot
   with the final store and colors it $v1 (nd 15 -> 0). */

/* measured: schedule on fills the jr $ra delay slot (nd 6 without it), and
   no_branch_likely on stops b210 emitting beql where retail has a plain
   beqz on the null test. */

// FUN_003C2290
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c2290(u8 *arg0, s32 arg1) {
    u8 *temp;

    *(u16 *)(arg0 + 0xC) |= (u16)(arg1 & 0xFFFF);
    if (arg1 & 1) {
        temp = *(u8 **)(arg0 + 0x54);
        if (temp != NULL) {
            func_003c5760(temp);
            *(s32 *)(arg0 + 0x54) = 0;
        }
    }
    return arg0;
}
#pragma no_branch_likely off
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled and drops the store out of it: MISMATCH nd 15, object 24 bytes in
   a 32-byte window. With it the function matches. */
// FUN_003C2A60
#pragma schedule on
u8 *func_003c2a60(u8 *arg0) {
    ((s16 *)arg0)[7] = (s16)(((s16 *)arg0)[7] + 1);
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 11 -> 0). */

// FUN_003C2C90
/* measured: schedule on fills the four jal/jr delay slots; without it the
   object is 104 bytes against a 96-byte window (nd 58). */
#pragma schedule on
s32 func_003c2c90(u8 *arg0) {
    s32 total;

    total = func_003c2bd0(arg0) + 0xC;
    total += func_003c4c00(arg0 + 0x20) + 0xC;
    return total + (func_003e3370(D_0070AFB0, arg0) + 0xC);
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003C38B0
/* The four floats are copied as one Vec4f assignment because retail loads all
   four before storing any; per-field assignments interleave lwc1/swc1 (nd 8).
   The result blocks are reached by goto so the zero case lands before the
   shared return, as retail lays them out. schedule on plus no_branch_likely
   on are needed for the delay slots and the plain bc1t/bc1f (nd 53 -> 17). */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c38b0(u8 *arg0, Vec4f *arg1) {
    *(Vec4f *)(arg0 + 0x18) = *arg1;
    if (*(f32 *)(arg0 + 0x18) == *(f32 *)(arg0 + 0x1C)) {
        goto chk;
    }
zero:
    arg0[3] = 0;
out:
    return arg0;
chk:
    if (*(f32 *)(arg0 + 0x18) != *(f32 *)(arg0 + 0x20)) {
        goto zero;
    }
    arg0[3] = 1;
    goto out;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above func_003c38b0's marker. */
#pragma schedule off

// FUN_003C3CC0
#pragma schedule on
s32 func_003c3cc0(u8 *arg0) {
    func_003e3c20(D_0070AFD0, arg0);
    func_003efda0(arg0);
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + iGpffffb8d0), arg0);
    return 1;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: swapping the NULL-store and count decrement makes b210 assign
   the tail count to $v1 and the table offset to $a1, matching retail.
   Object/window 128/128, normalized_diff 0. Committed at nd 0. */
// FUN_003C3E10
#pragma schedule on
u8 *func_003c3e10(u8 *arg0) {
    func_003e18c0(*(u8 **)(D_008872E0 + iGpffffb8d0), (void *)func_003c3890, 0);
    func_003e12f0(*(u8 **)(D_008872E0 + iGpffffb8d0));
    *(u8 **)(D_008872E0 + iGpffffb8d0) = NULL;
    iGpffffb8d4 -= 1;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: the explicit-label block order from func_003bd470 in code1_003b.c,
   with schedule on and no_branch_likely on, reproduces retail's block layout
   and call setup. Scoped verify: nd 0, object 120B/window 128B. */
// FUN_003C3F20
/* measured: schedule on and no_branch_likely on are required for the retail
   jal/jr delay slots and plain branch forms. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003c3f20(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_007647CC, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_007647C8, 4) != 0) {
        goto retarg;
    }
    return 0;
}
/* measured: closes the branch and schedule pragmas above at the file baseline. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: C reconstruction with schedule/no_branch_likely pragmas is nd 48,
   object 112B/window 112B; retail's pre-prologue load and movz conditional
   assignment remain compiler residuals; no real C body was retained, so the
   bare INCLUDE_ASM fallback remains. */
// FUN_003C3FA0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3fa0);


// FUN_003C40D0
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c40d0(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + iGpffffb8e0);
    if (p != NULL) {
        func_003e12f0(p);
        *(u8 **)(D_008872E0 + iGpffffb8e0) = NULL;
    }
    iGpffffb8e4 -= 1;
    return arg0;
}
#pragma no_branch_likely off
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003C42B0
/* measured: schedule on fills the branch and jr delay slots (nd 53 -> 4) and
   no_branch_likely on stops b210 emitting beql on the two null tests. */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c42b0(u8 **arg0, u8 *arg1) {
    if (arg1 != NULL) {
        *(s32 *)(arg1 + 0x54) += 1;
    }
    if (*arg0 != NULL) {
        func_003ef3a0(*arg0);
    }
    *arg0 = arg1;
    return (u8 *)arg0;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: schedule on takes this from nd 71 (obj 104B/window 96B)
   to nd 8 (obj 92B/window 96B), with every instruction right; the residual
   is three prologue words -- retail interleaves `move $s1,$a0` between the
   two saved-register stores while b210 emits both stores first. Measured
   identical at nd 8: naming the inner pointer in a local before the guard;
   folding the 0x28 into both arms of an if/else is much worse (nd 42).
   Prologue scheduling floor. Committed at nd 8. */
// FUN_003C47C0 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
s32 func_003c47c0(u8 *arg0) {
    s32 total;

    total = 0x28;
    if (*(u8 **)arg0 != NULL) {
        total += func_003e6240(*(u8 **)arg0) + 0xC;
    }
    return total + (func_003e3370(D_0070AFF0, arg0) + 0xC);
}
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c47c0);
#endif

/* measured: without schedule on, b210 leaves the jr $ra delay slot unfilled
   (nop); retail fills it with the final store (nd 15 -> 0). */
// FUN_003C4A40
#pragma schedule on
u8 *func_003c4a40(u8 *arg0) {
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


extern s32 D_007647EC;

/* measured: the 112B window begins with a six-word absolute jump thunk into
   the shared table; no plain-C body can reproduce that entry sequence under
   the source policy, so the bare INCLUDE_ASM fallback remains. */
// FUN_003C54A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c54a0);

// FUN_003C5700
#pragma schedule on
s32 func_003c5700(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 8);
    if (p != NULL) {
        jtbl_008873EC[0](p);
        *(s32 *)(arg0 + 8) = 0;
    }
    jtbl_008873FC[0](iGpffffb8e8, arg0);
    return 1;
}
/* measured: without schedule on the jalr and jr delay slots stay empty and
   the object misses its window; with it func_003c5700 matches. */
#pragma schedule off

/* measured: the OR chain's five tests all branch POSITIVELY to a shared call
   block placed after the return path, so each test needs its own
   `if (...) goto call;` - written as one `if (a || b || ...)` the last test is
   inverted and the body goes inline (nd 22). The jal delay slot and the
   table's lui/lw need schedule on. The table must also be called through the
   pointer: `jtbl_008873EC()` is an implicit call to the SYMBOL. */
// FUN_003C5760
#pragma schedule on
s32 func_003c5760(u8 *arg0)
{
    if (*(s32 *)arg0 != 0) {
        goto call;
    }
    if (*(u16 *)(arg0 + 4) != 0) {
        goto call;
    }
    if (*(u16 *)(arg0 + 6) != 0) {
        goto call;
    }
    if (*(s32 *)(arg0 + 8) != 0) {
        goto call;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        goto call;
    }
ret:
    return 1;
call:
    (*jtbl_008873EC)();
    goto ret;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: without schedule on, b210 leaves the jr $ra delay slot unfilled
   and colours the increment $v0; retail fills the slot with the store. */
// FUN_003C8CA0
#pragma schedule on
s32 func_003c8ca0(s32 arg0) {
    D_007647EC++;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


void func_003cc460();
void func_003d4e00();
void func_003d4e90();
void func_003d4d70();

/* measured: without #pragma schedule on, MWCC emits ld $ra / addiu $sp /
   jr $ra / nop; retail restores sp in the jr delay slot (nd 6 -> 0). */

// FUN_003C9530
extern s32 iGpffffb7f0;
extern s32 iGpffffb7f4;
extern void func_003cc130(void);
/* measured: probe schedule */
#pragma schedule on
s32 func_003c9530(s32 arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + iGpffffb7f0);
    if (p != NULL) {
        func_003e12f0(p);
        *(u8 **)(D_008872E0 + iGpffffb7f0) = NULL;
    }
    func_003cc130();
    iGpffffb7f4 -= 1;
    return arg0;
}
/* measured: close schedule */
#pragma schedule off

// FUN_003C96D0
extern u8 D_008872E4[];
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
s32 func_003c96d0(s32 (*arg0)(u8 *, s32), s32 arg1) {
    u8 *base;
    u8 *p;
    u8 *end;
    u8 *item;

    base = *(u8 **)(D_008872E4);
    end = base + 0x3C;
    p = *(u8 **)(base + 0x3C);
    if (p == end)
        goto finish;
loop:
    item = p - 0x34;
    p = *(u8 **)(p);
    if (item == NULL)
        goto check;
    if (arg0(item, arg1) == 0)
        return 1;
check:
    if (p != end)
        goto loop;
finish:
    return 1;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close schedule */
#pragma schedule off

/* measured: nd 14 at the retail's 96B window (candidate obj 92B/window 96B).
   Retail materializes the handlers directly as lui/addiu references to
   func_003ca740 + 0, +0x40, and +0x60; it does not load them through a
   function-pointer table. Direct-symbol C is nd 14; table-base/lw probes
   scored nd 64 and nd 59 with object 88B. The remaining three words are the
   order of `move $v0,$a0`, `addu $t0,$a0,$a3`, and the first store; all
   returned-value, pointer/record-local, offset, and schedule variants remain
   nd 14. Committed at nd 14. */
// FUN_003CA830 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
u8 *func_003ca830(u8 *arg0) {
    u8 *f60 = func_003ca7a0;
    u8 *f00 = func_003ca740;
    u8 *f40 = func_003ca780;
    u8 *node = arg0 + iGpffffb708;

    *(s32 *)(node + 0) = 0;
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 8) = 0;
    *(s32 *)(node + 0x10) = *(s32 *)(arg0 + 0x18);
    *(s32 *)(node + 0x14) = *(s32 *)(arg0 + 0x1C);
    *(s32 *)(node + 0x18) = *(s32 *)(arg0 + 0x10);
    *(u8 **)(arg0 + 0x10) = f60;
    *(u8 **)(arg0 + 0x18) = f00;
    *(u8 **)(arg0 + 0x1C) = f40;
    *(s32 *)(node + 0xC) = 0;
    return arg0;
}
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca830);
#endif
// FUN_003CA890
#pragma schedule on
u8 *func_003ca890(u8 *arg0, u8 *arg1) {
    u8 *node = arg1 + iGpffffb708;
    u8 *node0 = arg0 + iGpffffb708;
    s32 guard = *(s32 *)(node + 0xC);
    *(s32 *)(node0 + 0) = 0;
    *(s32 *)(node0 + 4) = 0;
    *(s32 *)(node0 + 8) = 0;
    if (guard != 0)
        func_003cbc10((u8 *)guard, arg0);
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003CA8E0
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003ca8e0(u8 *arg0) {
    u8 *node;
    u8 *p;

    node = arg0 + iGpffffb708;
    p = *(u8 **)node;
    if (p != NULL)
        jtbl_008873EC[0](p);
    *(s32 *)(node + 0) = 0;
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 8) = 0;
    *(s32 *)(arg0 + 0x18) = *(s32 *)(node + 0x10);
    *(s32 *)(arg0 + 0x1C) = *(s32 *)(node + 0x14);
    *(s32 *)(arg0 + 0x10) = *(s32 *)(node + 0x18);
    return arg0;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close schedule */
#pragma schedule off

// FUN_003CA960
/* measured: probe schedule */
#pragma schedule on
s32 func_003ca960(u8 *arg0) {
    u8 *x;
    u8 *y;

    x = *(u8 **)(arg0 + 0xC);
    y = *(u8 **)(arg0 + 0x10);
    *(u8 **)(y + 0) = x;
    x = *(u8 **)(arg0 + 0x10);
    y = *(u8 **)(arg0 + 0xC);
    *(u8 **)(y + 4) = x;
    x = *(u8 **)(arg0 + 0);
    y = *(u8 **)(arg0 + 4);
    *(u8 **)(y + 0) = x;
    y = *(u8 **)(arg0 + 4);
    x = *(u8 **)(arg0 + 0);
    *(u8 **)(x + 4) = y;
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + (s32)iGpffffb8e8 + 4), arg0);
    return 1;
}
/* measured: close schedule */
#pragma schedule off

// FUN_003CA9D0
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
s32 func_003ca9d0(u8 *arg0) {
    u8 *obj;
    u8 *x;
    u8 *y;

    obj = arg0;
    if (*(s32 *)(obj + 8) != 0 && *(s32 *)(obj + 0x14) != 0) {
        x = *(u8 **)(obj + 0xC);
        y = *(u8 **)(obj + 0x10);
        *(u8 **)(y + 0) = x;
        x = *(u8 **)(obj + 0x10);
        y = *(u8 **)(obj + 0xC);
        *(u8 **)(y + 4) = x;
        x = *(u8 **)(obj + 0);
        y = *(u8 **)(obj + 4);
        *(u8 **)(y + 0) = x;
        y = *(u8 **)(obj + 4);
        x = *(u8 **)(obj + 0);
        *(u8 **)(x + 4) = y;
        jtbl_008873FC[0](*(u8 **)(D_008872E0 + (s32)iGpffffb8e8), obj);
    }
    return 1;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close schedule */
#pragma schedule off

/* measured: best plain-C reconstruction with schedule/goto is nd 34,
   object 76B versus the 80B window; call-argument ordering and final
   conditional-move code remain; no real C body was retained, so the bare
   INCLUDE_ASM fallback remains. */
// FUN_003CB720
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb720);



/* measured: retail takes THREE parameters and ignores the second -- arg0
   arrives in $a0 and the object pointer in $a2. With the third parameter
   restored and #pragma schedule on (without it b210 leaves the jal delay slot
   empty, nd 45, and the object overflows the window at 84 bytes) everything
   matches except the order of the last two argument materialisations: retail
   emits `move $a1,$v0` then puts `addiu $a3,$v0,0x10` in the jal delay slot,
   b210 emits the addiu first and the move in the slot (fndiff rows 40/48,
   checklist 9; nd 8, obj 72B/window 80B). The exact raw callee types are
   now represented (`func_003c9c20` returns a pointer and `func_003c5a90`
   takes pointer, pointer, s32, s32). Naming temp_2 + 0x10 in a local,
   pointer-typed temp with pointer arithmetic, a named local for the 0x78
   load, `0x10 + temp_2`, casts, pointer-return variants, and all-s32 or
   old-style callee prototypes were all measured at nd 8. Committed at nd 8. */
// FUN_003CB820 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
void func_003cb820(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *temp_2;

    temp_2 = func_003c9c20((u32)arg2);
    func_003c5a90((u8 *)*(s32 *)(arg2 + 0x78), temp_2, arg0, (s32)(temp_2 + 0x10));
}
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb820);
#endif

/* measured: best C reconstruction with schedule/goto is nd 37,
   object 88B versus the 96B window; call/conditional-move residuals
   remain; no real C body was retained, so the bare INCLUDE_ASM fallback
   remains. */
// FUN_003CB870
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb870);

// FUN_003CBC10
#pragma schedule on
u8 *func_003cbc10(u8 *arg0, u8 *arg1) {
    u8 *node = arg1 + iGpffffb708;
    u8 *v = *(u8 **)(arg1 + 4);
    if (v != 0)
        func_003e9680(v);
    *(s32 *)(node + 0xC) = (s32)arg0;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003CBC90
#pragma schedule on
u8 *func_003cbc90(u8 *arg0, u8 *arg1) {
    u8 *node = arg1 + iGpffffb70c;
    u8 *v = *(u8 **)(arg1 + 4);
    if (v != 0)
        func_003e9680(v);
    *(s32 *)(node + 0x0) = (s32)arg0;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: these three functions are one setter/lookup template. The
   explicit four-block gotos plus schedule on, no_branch_likely on, and
   opt_common_subs off give nd 6 with object 88B/window 96B. fndiff's only
   reloc-masked residual rows are offsets 16 and 20: retail emits
   `addiu $v1,$v1,%lo(D_008872E0)` then `move $v0,$a0`, while b210 emits
   those two words in the opposite order (checklist 9, preheader order).
   The GP/global rows at offsets 8, 12, 36, 40, 44, and 68 are relocation
   differences, not instruction residuals. Named base pointers at store,
   reload, before the guard, lookup-only, initialized, and path-local forms;
   array and `&D_008872E0` forms; base plus loop-invariants; and a separate
   walker/result shared-exit form were all measured without improvement.
   The split-store form grew to nd 40, object 100B/window 96B; the best
   separate walker/result form was nd 25, object 84B/window 96B. Committed at nd 6. */
// FUN_003CC010 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
/* measured: probe CSE */
#pragma opt_common_subs off
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003cc010(u8 *arg0) {
    s32 off;
    u8 *base;

    if (arg0 == NULL)
        goto nullcase;
reload:
    off = iGpffffb9b8;
store:
    base = D_008872E0 + off;
    *(u8 **)(base + 0x40) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x58);
    if (arg0 == NULL)
        goto setnull;
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close CSE */
#pragma opt_common_subs on
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc010);
#endif

/* measured: sibling of func_003cc010; the same template and probes leave
   only the offset-16/20 preheader order residual, nd 6, object 88B/window
   96B. Checklist 9. Committed at nd 6. */
// FUN_003CC070 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
/* measured: probe CSE */
#pragma opt_common_subs off
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003cc070(u8 *arg0) {
    s32 off;
    u8 *base;

    if (arg0 == NULL)
        goto nullcase;
reload:
    off = iGpffffb9b8;
store:
    base = D_008872E0 + off;
    *(u8 **)(base + 0x3C) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x54);
    if (arg0 == NULL)
        goto setnull;
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close CSE */
#pragma opt_common_subs on
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc070);
#endif

/* measured: sibling of func_003cc010; the same template and probes leave
   only the offset-16/20 preheader order residual, nd 6, object 88B/window
   96B. Checklist 9. Committed at nd 6. */
// FUN_003CC0D0 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
/* measured: probe CSE */
#pragma opt_common_subs off
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003cc0d0(u8 *arg0) {
    s32 off;
    u8 *base;

    if (arg0 == NULL)
        goto nullcase;
reload:
    off = iGpffffb9b8;
store:
    base = D_008872E0 + off;
    *(u8 **)(base + 0x44) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x5C);
    if (arg0 == NULL)
        goto setnull;
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close CSE */
#pragma opt_common_subs on
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc0d0);
#endif

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled: MISMATCH nd 6, object 56 bytes in a 64-byte window. */
// FUN_003CC130
#pragma schedule on
void func_003cc130(void) {
    func_003cc460();
    func_003d4e00();
    func_003d4e90();
    func_003d4d70();
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC emits addiu $v0, 1 before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

// FUN_003CC240
#pragma schedule on
s32 func_003cc240(void) {
    return 1;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


void func_003f32d0();

/* measured (merged TU): schedule on was load-bearing per-unit for the
   jal/jr $ra delay slots, but in the merged TU it worsens the near-miss
   (nd 17 with vs nd 15 without), so the pragma was removed.
   NONMATCHING: retail sinks the if-body out of line (bnez/ b exit; ld ra /
   body / b back / jr ra; addiu sp, 15 instr); b210 compiles every honest
   form of this if inline as a beql skip (13 instr) across 30+ probe
   shapes, so the layout is not reproducible.  Residual: nd 15. */

/* measured: explicit out-of-line labels, schedule on, no_branch_likely on,
   and two-argument signature reproduce the complete 112-byte body except
   retail hoists `lw $v1,($a1)` before saving $ra while b210 saves $ra first.
   Prologue scheduling residual is nd 4, obj 104B/window 112B. Moving the
   first pointer use into a nested load, assignment expression, direct
   expression, or positive-branch form did not alter nd 4; the comparison
   `<= 0` versus `< 1` also stayed nd 4. The base body remains the lowest
   park. Committed at nd 4. */
// FUN_003CC250 NONMATCHING
#ifdef NON_MATCHING
extern void (*D_00887300[])(u32, u32);
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
s32 func_003cc250(s32 arg0, u8 **arg1) {
    u8 *p = *arg1;
    if ((s32)*(u16 *)(p + 0) <= 0)
        goto retzero;
    *(s32 *)(p + 0x18) = *(s32 *)(p + 4);
    if ((*(s32 *)(p + 0xC) & 1) == 0)
        goto call;
retone:
    return 1;
retzero:
    return 0;
call:
    D_00887300[0](1, 0);
    goto retone;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc250);
#endif
// FUN_003CC500
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc500);

/* measured: retail uses standalone pexew/ppacw MMI instructions; no plain-C
   equivalent is permitted. Window 96B; no real C body was retained; the bare
   INCLUDE_ASM fallback remains. */
// FUN_003CC680
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc680);

/* measured: the null-first `block_body`/`block_null` graph plus
   no_branch_likely and schedule reproduce retail's out-of-line null branch,
   the ld $ra delay-slot fill, and the backward body branch. Compiled C MATCH,
   object 60B/window 64B. Committed at nd 0. */
// FUN_003CC6E0
/* measured: schedule on for func_003cc6e0. */
#pragma schedule on
/* measured: no_branch_likely on for func_003cc6e0. */
#pragma no_branch_likely on
void func_003cc6e0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x18) != 0)
        goto block_body;
block_null:
    return;
block_body:
    func_003f32d0();
    func_003f32d0();
    goto block_null;
}
/* measured: no_branch_likely off for func_003cc6e0. */
#pragma no_branch_likely off
/* measured: schedule off for func_003cc6e0. */
#pragma schedule off

extern s32 D_0070B110[];

/* measured: without #pragma schedule on, MWCC emits lui / addiu before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

// FUN_003CF9B0
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cf9b0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *sub;

    if (arg0 == NULL)
        goto outer_none;
    sub = *(u8 **)(arg0 + 0x14);
    if (sub == NULL)
        goto sub_none;
    switch (arg1) {
    case 1:
        if (arg2 == 0)
            goto none;
        *(s32 *)(sub + 0x10) = arg2;
        return arg0;
    case 2:
        *(s32 *)(sub + 0x14) = arg2;
        return arg0;
    default:
        return NULL;
    }
outer_none:
    return NULL;
sub_none:
    return NULL;
none:
    return NULL;
}
#pragma no_branch_likely off
#pragma schedule off

// FUN_003CFA70
#pragma schedule on
s32 *func_003cfa70(void) {
    return D_0070B110;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
