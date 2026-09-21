#include "include_asm.h"
#include "type.h"

extern s32 D_00745AF8;

extern s32 D_00745ABC;

extern s32 D_007609B0[];

extern s32 D_00745C84;

extern s32 D_00745C6C;

extern s32 D_0074613C;

/* Open declaration question (2026-08-09): func_0052c890 candidates all emit
 * sq-style saves at frame 0x40 while retail uses sd saves at frame 0x20.
 * The scalar-only body removed aggregates, arrays, by-value structs, and
 * vector types; deleting either added callee prototype independently did not
 * change the result. The same unexplained inflation appears at
 * func_0050d088 (0x30 vs 0x20) and func_005249b0 (0x30 vs 0x20).
 * This is anomalous, not normal MWCCPS2 behavior: among retail functions
 * saving $ra, 3161 already-MATCHED and 4690 unmatched functions use sd, while
 * exactly one function in the image uses sq $ra. */

typedef void (*Code1B9Callback)(s32 arg0, s32 arg1, void *arg2);
typedef struct {
    Code1B9Callback callback;
    s32 arg1;
    s32 count;
} Code1B9Work;
extern void func_00524318();
extern void func_00524b78(u8 *arg0);
/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
#pragma schedule on

// FUN_00520068
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520068);
// FUN_005200B8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005200b8);
// FUN_00520138
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520138);
// FUN_00520338
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520338);
// FUN_00520438
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520438);
// FUN_00520750
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00520750);
// FUN_005207A8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005207a8);
// FUN_005207F8
void func_005207f8(s32 arg0)
{
    D_00745AF8 = arg0;
}
#pragma schedule off


/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
#pragma schedule on
/* measured: ee-gcc 2.96 -O2 -G0, object 36B/window 40B, normalized_diff 7; sd $ra placement and t0 coloring. Direct-constant, u64, and s64-zero variants all stayed at nd 7. No loop entry-guard or slti $at pattern, so parent (s64)0 and <= levers do not apply. This unit is ee-gcc, MWCC pragmas do not apply. Body at docs/probe_archive/GA52_00522fd0_body.c. */
// FUN_00522FD0 NONMATCHING
#ifdef NON_MATCHING
void func_00522fd0(s32 arg0)
{
    s32 value1 = 7;
    s32 value2 = 6;
    s32 value3 = 0;
    s32 value4 = 0;

    func_005278b0(arg0, value1, value2, value3, value4);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00522fd0);
#endif
// FUN_00523050
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523050);
// FUN_005230B8
void func_005230b8(s32 arg0)
{
    D_00745ABC = arg0;
}
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

#pragma schedule off


/* measured: b210 O2 emits lui/addiu/jr/nop (unfilled return delay slot);
 * retail is lui $v0 / jr $ra / addiu $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill. */
#pragma schedule on

// FUN_005230D8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005230d8);
// FUN_00523138
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523138);
// FUN_00523508
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523508);
// FUN_00523578
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00523578);
// FUN_005242D0
void func_005242d0(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x36B0) == 0) {
        return;
    }
    func_00524318();
    func_00524b78(arg0);
}
// FUN_00524318
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524318);
// FUN_00524480
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524480);
// FUN_00524500
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524500);
// FUN_005245A0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005245a0);
// FUN_00524610
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524610);
// FUN_00524680
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524680);
// FUN_00524720
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524720);
// FUN_00524770
void func_00524770(s32 *arg0, s32 arg1, s32 arg2, s32 *arg3)
{
    *arg3 = 0;
}
// FUN_00524778
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524778);
// FUN_00524820
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524820);
// FUN_005248A8
void func_005248a8(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
    *arg2 = 0;
    *arg3 = 0x3E8;
}
// FUN_005248B8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005248b8);
// FUN_005249B0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005249b0);
// FUN_00524A20
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524a20);
// FUN_00524AA8
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524aa8);
// FUN_00524B18
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524b18);
// FUN_00524B78
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_00524b78);
// FUN_00528C30
s32 *func_00528c30(void)
{
    return D_007609B0;
}
/* measured: closes the schedule-on segment-return bracket through func_00528c30; explicit schedule off restores the following code's baseline state. */
#pragma schedule off



/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
#pragma schedule on
// FUN_0052B950
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b950);
// FUN_0052B9A0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b9a0);
// FUN_0052B9E0
void func_0052b9e0(s32 arg0)
{
    D_00745C84 = arg0;
}
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

#pragma schedule off


/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
#pragma schedule on

// FUN_0052BA00
void func_0052ba00(s32 arg0)
{
    D_00745C6C = arg0;
}
#pragma schedule off


/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
#pragma schedule on

#pragma schedule off


/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
#pragma schedule on

// FUN_0052BA20
s32 *func_0052ba20(u8 *arg0, s32 arg1)
{
    s32 *work = *(s32 **)(arg0 + 0x24);
    work[0x11] = arg1;
    return work;
}
// FUN_0052BA30
s32 *func_0052ba30(u8 *arg0, s32 arg1)
{
    s32 *work = *(s32 **)(arg0 + 0x24);
    work[0x12] = arg1;
    return work;
}
/* measured: ee-gcc 2.96 -O2 -G0, object 44B/window 48B, normalized_diff 7; $f1/$f2 zero coloring and $f0/$f1 load coloring. Reversed-compare and f64-zero variants stayed at nd 7 (f64 at nd 24). No loop or integer range pattern, so parent levers do not apply. This unit is ee-gcc, MWCC pragmas do not apply. Body at docs/probe_archive/GA52_0052c840_body.c. */
// FUN_0052C840 NONMATCHING
#ifdef NON_MATCHING
s32 func_0052c840(u8 *arg0)
{
    f32 zero = 0.0f;
    f32 value0 = *(f32 *)(arg0 + 0x3C);
    f32 value1;
    s32 result = 1;

    if (value0 == zero) {
        value1 = *(f32 *)(arg0 + 0x40);
        if (value1 == zero) {
            result = 0;
        }
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c840);
#endif
// FUN_0052C870
void func_0052c870(s32 arg0)
{
    D_0074613C = arg0;
}
/* measured: closes the schedule-on segment-return bracket through func_0052c870; explicit schedule off restores the following code's baseline state. */
#pragma schedule off

// FUN_0052C880
s32 func_0052c880(void)
{
    return D_0074613C;
}
// FUN_0052C890
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c890);
// FUN_0052C8E0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c8e0);
// FUN_0052C930
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c930);
// FUN_0052C980
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052c980);
// FUN_0052CAB0
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052cab0);
// FUN_0052CC18
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052cc18);
// FUN_0052CD18
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052cd18);
/* Floor: 2 differing words.  This unit is ee-gcc 2.96 -O2 -G0, not MWCC.
   The accumulator is a { s64 total; s64 min; s64 max; s32 count; } struct
   and the body is 60 bytes of code against a 96-byte window whose tail is
   36 zero bytes.  Retail schedules the conditional moves movn-max, daddu,
   movn-min; this build emits movn-max, movn-min, daddu - one adjacent
   swap.  All 24 source orders of min/max/total/count give the same NND
   under 2.96; MWCC b210 and b119 produce branches rather than movn, and
   ee-gcc 3.2 gives NND with different temp colours (14 words).  Body at
   docs/probe_archive/GA52_0052d9a0_body.c. */
// FUN_0052D9A0 NONMATCHING
#ifdef NON_MATCHING
typedef struct {
    s64 total;
    s64 min;
    s64 max;
    s32 count;
} StatAccum52;
void func_0052d9a0(StatAccum52 *arg0, s64 arg1)
{
    s64 total = arg0->total;
    s64 mn = arg0->min;
    s64 mx = arg0->max;
    s32 count = arg0->count;

    if (mx < arg1) {
        mx = arg1;
    }
    if (arg1 < mn) {
        mn = arg1;
    }
    total += arg1;
    count += 1;
    arg0->total = total;
    arg0->min = mn;
    arg0->max = mx;
    arg0->count = count;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052d9a0);
#endif
