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
extern s32 func_003c9c20(u8 *arg0);
extern void func_003c5a90(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
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

/* measured: the object is exactly its 128-byte window and every instruction
   is right; the residual is which registers hold the reference count, the
   table offset and the D_008872E0 base in the tail -- retail keeps the count
   in $v1 and the offset in $a1, b210 swaps them (2 words, nd 9). Measured
   identical at nd 9: naming the slot pointer in a local before the decrement,
   and splitting the decrement into a read/modify/write through a local.
   Register colouring floor. Committed at nd 9. */
// FUN_003C3E10 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
u8 *func_003c3e10(u8 *arg0) {
    func_003e18c0(*(u8 **)(D_008872E0 + iGpffffb8d0), (void *)func_003c3890, 0);
    func_003e12f0(*(u8 **)(D_008872E0 + iGpffffb8d0));
    iGpffffb8d4 -= 1;
    *(u8 **)(D_008872E0 + iGpffffb8d0) = NULL;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3e10);
#endif

/* measured: same shape as func_003bd470 in code1_003b.c, but NOT the same
   residual - nd 102 here against nd 43 there. The note originally copied the
   sibling's number without measuring this one; in a different translation unit
   with different declarations the same source scores very differently. */
// FUN_003C3F20
#ifdef NON_MATCHING
#pragma no_branch_likely on
s32 func_003c3f20(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_007647CC, 4) == 0) {
        return 0;
    }
    if (arg1 != 8) {
        return arg0;
    }
    if (func_003df360(arg0, &D_007647C8, 4) == 0) {
        return 0;
    }
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3f20);
#endif

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

/* measured: schedule on takes this from nd 71 (obj 104 in a 96-byte window)
   to nd 8 and every instruction is right; the residual is three prologue
   words -- retail interleaves `move $s1,$a0` between the two saved-register
   stores while b210 emits both stores first. Measured identical at nd 8:
   naming the inner pointer in a local before the guard; folding the 0x28
   into both arms of an if/else is much worse (nd 42). Prologue scheduling
   floor. Committed at nd 8. */
// FUN_003C47C0 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
s32 func_003c47c0(u8 *arg0) {
    s32 total;

    total = 0x28;
    if (*(u8 **)arg0 != NULL) {
        total += func_003e6240(*(u8 **)arg0) + 0xC;
    }
    return total + (func_003e3370(D_0070AFF0, arg0) + 0xC);
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
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
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9530);

// FUN_003C96D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c96d0);

/* measured: nd 14 at retail's 96-byte window. Referencing the three handler
   entry points by their own symbols (rather than func_003ca740 plus 0x40 and
   0x60) is what folds each offset into its own relocation and stops b210
   CSEing them into one base plus two unmasked addiu immediates - that alone
   was nd 65, and schedule on then took it to nd 14 by hoisting the three
   addresses above the first store the way retail does. The three words left
   are the order of `move $v0,$a0`, `addu $t0,$a0,$a3` and the first store;
   declaring the returned value first, last, or between the handlers and the
   record pointer all measure nd 14. Committed at nd 14. */
// FUN_003CA830 NONMATCHING
#ifdef NON_MATCHING
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
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca8e0);

// FUN_003CA960
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca960);

// FUN_003CA9D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca9d0);

// FUN_003CB720
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb720);

/* measured: retail takes THREE parameters and ignores the second -- arg0
   arrives in $a0 and the object pointer in $a2 -- so the two-parameter m2c
   draft put the pointer in $a1 and nothing lined up. With the third parameter
   restored and #pragma schedule on (without it b210 leaves the jal delay slot
   empty, nd 45, and the object overflows the window at 84 bytes) everything
   matches except the order of the last two argument materialisations: retail
   emits `move $a1,$v0` then puts `addiu $a3,$v0,0x10` in the jal delay slot,
   b210 emits the addiu first and the move in the slot (2 words, nd 8).
   Measured identical at nd 8: naming temp_2 + 0x10 in a local, pointer-typed
   temp with pointer arithmetic, a named local for the 0x78 load, `0x10 +
   temp_2`, an extra (s32) cast on the second argument, and both an
   all-s32 and an old-style empty callee prototype. Call-argument setup
   order floor (docs/matching.md). */
// FUN_003CB820 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
void func_003cb820(s32 arg0, s32 arg1, u8 *arg2) {
    s32 temp_2;

    temp_2 = (s32)func_003c9c20(arg2);
    func_003c5a90(*(s32 *)(arg2 + 0x78), temp_2, arg0, temp_2 + 0x10);
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb820);
#endif

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

/* One of three identical setters (0x40/0x3C/0x44 written, 0x58/0x54/0x5C
   consulted). The gotos reproduce retail's four-block layout, and schedule on
   plus no_branch_likely on take it from nd 54 to nd 12 (obj 88 in a 96-byte
   window). The 3-word residual is that retail reads the gp offset TWICE in
   the null path -- once into $v1 for the 0x58 lookup and again into $a1 in
   the branch delay slot for the store base -- while b210 common-subexpressions
   the two reads into one; assigning `off` before the lookup instead is worse
   (nd 23). Committed at nd 12. */
// FUN_003CC010 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cc010(u8 *arg0) {
    s32 off;

    if (arg0 == NULL) {
        goto nullcase;
    }
reload:
    off = iGpffffb9b8;
store:
    *(u8 **)(D_008872E0 + off + 0x40) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x58);
    if (arg0 == NULL) {
        goto setnull;
    }
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc010);
#endif

/* Sibling of func_003cc010; see the note there. Committed at nd 12. */
// FUN_003CC070 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cc070(u8 *arg0) {
    s32 off;

    if (arg0 == NULL) {
        goto nullcase;
    }
reload:
    off = iGpffffb9b8;
store:
    *(u8 **)(D_008872E0 + off + 0x3C) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x54);
    if (arg0 == NULL) {
        goto setnull;
    }
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc070);
#endif

/* Sibling of func_003cc010; see the note there. Committed at nd 12. */
// FUN_003CC0D0 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cc0d0(u8 *arg0) {
    s32 off;

    if (arg0 == NULL) {
        goto nullcase;
    }
reload:
    off = iGpffffb9b8;
store:
    *(u8 **)(D_008872E0 + off + 0x44) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x5C);
    if (arg0 == NULL) {
        goto setnull;
    }
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
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

// FUN_003CC250
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc250);

// FUN_003CC500
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc500);

// FUN_003CC680
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc680);

/* measured: the body below is a faithful reconstruction whose residual is
   recorded in the notes above; re-measured for nd_audit coverage.
   Committed at nd 15. */
// FUN_003CC6E0 NONMATCHING
#ifdef NON_MATCHING
void func_003cc6e0(u8 *arg0) {
    if (((s32 *)arg0)[6] != 0) {
        func_003f32d0();
        func_003f32d0();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc6e0);
#endif


extern s32 D_0070B110[];

/* measured: without #pragma schedule on, MWCC emits lui / addiu before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

/* measured: nd 2 of 32 words. schedule on plus no_branch_likely on gets the
   delay slots and the plain bne/bnez; the rest was the shape of the four
   un-merged `return NULL` blocks, which retail keeps separate and in a specific
   order. Reaching the arg2 == 0 case through a goto is what stops case 1's null
   return from pushing case 2's body down - `if (arg2 != 0) {...} return NULL;`
   inside the case costs nd 19 and `break` into a shared tail costs nd 26.
   The residual is two swapped branch targets: retail sends arg0 == NULL to the
   earlier block and arg2 == 0 to the later one, and neither placing the label
   inside the switch nor at the end of the function reverses that. */
// FUN_003CF9B0
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cf9b0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *sub;

    if (arg0 != NULL) {
        sub = *(u8 **)(arg0 + 0x14);
        if (sub != NULL) {
            switch (arg1) {
            case 1:
                if (arg2 == 0) {
                    goto none;
                }
                *(s32 *)(sub + 0x10) = arg2;
                return arg0;
            case 2:
                *(s32 *)(sub + 0x14) = arg2;
                return arg0;
            default:
                return NULL;
            }
none:
            return NULL;
        }
        return NULL;
    }
    return NULL;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf9b0);
#endif

// FUN_003CFA70
#pragma schedule on
s32 *func_003cfa70(void) {
    return D_0070B110;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
