#include "include_asm.h"
#include "type.h"
/* Toolchain-blocked: retail saves callee-saved registers with sd; MWCCPS2 3.0.1 emits sq. See build/ORCH_sd_toolchain_blocked.txt. */


s32 func_004447f8();
s32 func_00444870();
s32 func_00421da8();
s32 func_0044a138();
f32 func_0044b018(s32 arg0, f32 fparg0, f32 fparg1);
extern s32 D_009389E0[];
s32 func_004526e0(void);
s32 func_0044d4d0();
u64 func_00443fd0(s32 *arg0, s8 *arg1, s8 **arg2, s16 arg3);

typedef struct {
    u8 *unk0;      /* 0x0 */
    s32 unk8;      /* 0x8 */
    s16 unkC;      /* 0xC */
    u8 *unk10;     /* 0x10 */
    s32 unk14;     /* 0x14 */
    u8 pad18[0x3C];
    u8 *unk54;     /* 0x54 */
} Mesh048;

typedef struct E8Node E8Node;
typedef struct {
    E8Node *first;
    E8Node *last;
    E8Node *current;
    u8 padC[0xC];
    s32 count;
    s32 total;
    u8 pad20[0x10];
    s32 (*fn_30)(void);
} E8Pool;
struct E8Node {
    E8Node *next;
    E8Node *prev;
};
extern E8Pool *D_00763D1C;
extern s32 *D_00710070[];
extern s32 (*D_008BE290[])(u32);
extern void (*D_008BE294[])(u8 *);
extern s32 (*D_008BE298[])(void *, u32);
extern s32 (*D_008BE29C[])(s32, s32);
s32 func_0044ec60(u32);
void func_0044ee70(u8 *);
s32 func_0044f140(void *, u32);
s32 func_0044f3a0(s32, s32);
s32 func_0044f4d0(void);
s32 func_00446108();

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00446108 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


s64 func_004470f0(s64 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_004470f0 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
/* measured: nd 45 against retail's 88-byte object. Retail builds a partially
   initialised 0x58-byte record at the frame base and hands its address to
   func_004447f8; b210 lays the same struct out at frame offset 0x20, so every
   store and the argument setup are displaced. Probed a bare local struct
   (mwccps2 rejects a struct type defined inside a function), the file-scope
   Mesh048 typedef used here, individual scalar locals (dead-store eliminated
   down to one), and taking the address of the first member instead of the
   struct. Committed at nd 45. */

// FUN_004401C8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004401c8);

// FUN_004402D0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004402d0);

// FUN_00440430
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440430);

// FUN_00440498
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440498);

// FUN_00440618
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440618);

// FUN_004406D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004406d8);

// FUN_00440880
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440880);

// FUN_00440A00
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440a00);

// FUN_00440B68
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440b68);

// FUN_00440BB8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440bb8);
// FUN_004414F8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004414f8);

// FUN_00441558
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441558);

// FUN_00441580
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441580);

// FUN_00441B40
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441b40);

// FUN_00441CB0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441cb0);

// FUN_00441CF0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441cf0);

// FUN_00441D38
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441d38);


// FUN_00441D70
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441d70);

// FUN_00441EF0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441ef0);

// FUN_00441F40
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441f40);
// FUN_00441F68
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441f68);


// FUN_00442088
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442088);

// FUN_004420F8
s32 func_004420f8(void) {
    return 0;
}

// FUN_00442100
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442100);

// FUN_00442188
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442188);

// FUN_00442220
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442220);

// FUN_00442300
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442300);

// FUN_00442388
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442388);

// FUN_00442428
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442428);

// FUN_00442558
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442558);

// FUN_004426E8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004426e8);

// FUN_00442830
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442830);

// FUN_00442948
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442948);

// FUN_00442A80
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442a80);

// FUN_00442C30
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442c30);

// FUN_00442DE8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442de8);

// FUN_00442FA8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442fa8);

// FUN_00443010
#ifdef NON_MATCHING
s8 *func_00443010(s8 *arg0, s8 *arg1) {
    s32 counter;
    s8 *result;
    s8 c1;
    s8 c2;

    result = arg0;
    if (*arg0 != 0) {
        goto outer;
    }
    if (*arg1 == 0) {
        return result;
    }
    return NULL;
outer:
    counter = 0;
inner:
    c1 = arg1[counter];
    if (c1 == 0) {
        return result;
    }
    c2 = result[counter];
    if (c1 == c2) {
        counter++;
        goto inner;
    }
    result++;
    if (*result != 0) {
        counter = 0;
        goto outer;
    }
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443010);
#endif

// FUN_00443068
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443068);


// FUN_00443EE0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443ee0);


// FUN_00443F18
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443f18);

// FUN_00443F38
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443f38);

// FUN_00443FD0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443fd0);

// FUN_00444210
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444210);

// FUN_00444240
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444240);

// FUN_00444458
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444458);

// FUN_00444488
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444488);

// FUN_00444570
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444570);

// FUN_00444700
#ifdef NON_MATCHING
s32 func_00444700(u8 *arg0, u8 *arg1) {
    extern s32 func_0043e608(u8 *arg0, u8 *arg1);
    s32 result;

    if (*(s32 *)(arg1 + 8) == 0) {
        *(s32 *)(arg1 + 4) = 0;
        return 0;
    }
    result = func_0043e608(arg0, arg1);
    *(s32 *)(arg1 + 4) = 0;
    *(s32 *)(arg1 + 8) = 0;
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444700);
#endif

// FUN_00444748
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444748);

// FUN_004447F8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004447f8);

// FUN_00444870
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444870);

// FUN_00445DD0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00445dd0);

// FUN_00445F78
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00445f78);

// FUN_004460C0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004460c0);

// FUN_00446108
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446108);

// FUN_00446D98
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446d98);

// FUN_00446E88
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446e88);

// FUN_00446EB0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446eb0);
// FUN_00446ED8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446ed8);




/* measured: nd 60 against retail's 80-byte object (object_size 80/80 exact).
   Same wall as the parked func_00446ed8: retail builds the partially
   initialised Mesh048 record at the frame base (addiu $sp,-0x70, struct at
   $sp+0x0) and hands &s to func_00444870; b210 lays the same struct out at
   frame offset 0x20 (addiu $sp,-0x80), so every store and the argument setup
   are displaced by 0x20. Probed the natural declaration-order struct init,
   retail's store order (unk10,unk14,unkC,unk54,unk0,unk8), a pointer-to-struct
   local, passing &s.unk0, and scalar field locals — all nd 60. Committed at
   nd 60.
   Committed at nd 60. */
// Archived C body: build/WBHygiene_func_00446f30_archive.txt; no current park body remains.
// FUN_00446F30
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446f30);

/* measured: nd 57 against retail's 96-byte object (object_size 88/96).
   Retail hoists `lui $s0,%hi(D_009389E0)` ONCE into a callee-saved register
   live across the func_00421da8 call and reuses it for both the `sw $zero`
   (before the call) and the `lw` (after), keeping the out pointer in $s1 with
   sd saves (frame 0x20). b210 rematerialises the address twice (once for the
   store, once for the load) and, with only one live s-register, emits a
   quadword `sq $s0` save instead of retail's two `sd`s; a pointer local
   (`p=&D_009389E0[0]`) that forces the address live across the call instead
   doubles it AND inflates the frame to 0x30, and no pragma (opt_loop_invariants,
   opt_common_subs, O3) reproduces the single hoist. The branch polarity is
   also inverted vs retail (bnel+beqz vs bne+bnel) as a consequence of the
   register allocation. Probed the && form, explicit-if in both guard
   polarities, pointer forms, and the three pragmas. Committed at nd 52. */
// Archived C body: build/WBHygiene_func_00446f80_archive.txt; no current park body remains.
// FUN_00446F80
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446f80);

/* measured: nd 83 against retail's 112-byte object (object_size 104/112).
   Retail reads the incoming float's bits via `mfc1 $t7,$f12` then `and`s with
   0x7FFFFFFF and does an integer `slt` against 0x3F490FDA (pi/4) to pick the
   reduction path. b210 will NOT emit that mfc1 from any reinterpret idiom --
   *s32*&x, a union, u32 casts all compile to a stack round-trip
   (swc1/lw + dsll32/dsrl32 sign-extend) -- and fabsf() inlines to abs.s with a
   float c.le.s compare instead of the integer path. On top of that the local
   f32[2] reduction buffer lands at frame offset 0x18 where retail puts it at
   the frame base (the same aggregate-frame-displacement wall as the parked
   func_00446ed8 / func_00446f30), shifting every lwc1 and the arg setup.
   Probed mfc1 idioms (pointer/union/u32/direct), fabsf with a declared
   prototype, comparison polarity (>, >=, constant-left, <=/inv), shared-call
   vs two-return layout, and function-scope vs if-scope local array. Committed
   at nd 83.
   Committed at nd 83. */

// FUN_00446FE0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446fe0);

// FUN_004470F0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004470f0);

// FUN_004476B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004476b0);

// FUN_00447B88
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00447b88);

// FUN_00447D00
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00447d00);

// FUN_00448A00
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00448a00);

// FUN_00448D10
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00448d10);

// FUN_00449120
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00449120);

// FUN_004494B8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004494b8);

// FUN_00449680
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00449680);

// FUN_00449938
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00449938);

// FUN_0044A138
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a138);

// FUN_0044A4D0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a4d0);

// FUN_0044A5B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a5b0);

// FUN_0044A700
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a700);

// FUN_0044AF20
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044af20);

// FUN_0044B018
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b018);

// FUN_0044B310
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b310);

// FUN_0044B340
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b340);

// FUN_0044B610
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b610);

// FUN_0044B6C0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b6c0);

// FUN_0044B6D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b6d8);

// FUN_0044B7B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b7b0);
// FUN_0044B868
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b868);

#pragma pop


s32 func_00447b88(s64 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00447b88 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


s32 func_00447d00(s64 arg0, s32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00447d00 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


f32 func_00448d10(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00448d10 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


f32 func_00449120(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449120 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


f32 func_004494b8(f32 arg0, f32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_004494b8 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


f32 func_00449680(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449680 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


f32 func_00449938(f32 arg0, f32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449938 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop


f32 func_0044a4d0(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_0044a4d0 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

// FUN_0044B9B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b9b0);
// FUN_0044BA00
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044ba00);
// FUN_0044BA98
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044ba98);
// FUN_0044BB60
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044bb60);
// FUN_0044BC68
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044bc68);
// FUN_0044BCD8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044bcd8);
// FUN_0044BDE8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044bde8);
// FUN_0044BF10
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044bf10);
// FUN_0044C5D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044c5d8);
// FUN_0044C708
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044c708);
// FUN_0044CDD0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044cdd0);
// FUN_0044CDE8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044cde8);
// FUN_0044D4B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044d4b0);
// FUN_0044D4D0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044d4d0);
// FUN_0044E608
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044e608);
// FUN_0044E658
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044e658);
// FUN_0044E708
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044e708);
// FUN_0044E7A8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044e7a8);
// FUN_0044E7D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044e7d8);
/* measured: declaration-corrected body archived in build/K1DA_0044e830_body.c; object 204B exceeds retail window 160B, normalized_diff 167; differing offsets 0x0,0x4,0x6,0x8-0xC,0xE,0x10-0x14,0x16,0x1C. */
// FUN_0044E830
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044e830);
// FUN_0044E8D0
void func_0044e8d0(E8Node *node) {
    E8Pool *pool;
    pool = D_00763D1C;
    if (pool->first == 0) {
        pool->last = node;
        D_00763D1C->first = node;
        node->prev = 0;
        node->next = 0;
        return;
    }
    node->next = pool->last;
    D_00763D1C->last = node;
    node->next->prev = node;
    node->prev = 0;
}
// FUN_0044E920
void func_0044e920(E8Node *node) {
    E8Node *next;
    next = node->next;
    if (next == 0) {
        if (node->prev != 0) {
            D_00763D1C->first = node->prev;
            node->prev->next = 0;
            goto done;
        }
        D_00763D1C->last = 0;
        D_00763D1C->first = 0;
        goto done;
    }
    if (node->prev == 0) {
        if (next != 0) {
            D_00763D1C->last = next;
            node->next->prev = 0;
        } else {
            D_00763D1C->last = 0;
            D_00763D1C->first = 0;
        }
    } else {
        next->prev = node->prev;
        node->prev->next = node->next;
    }
done:
    if (node == D_00763D1C->current) {
        D_00763D1C->current = 0;
    }
}
/* measured: declaration-corrected body archived in build/K1DA_0044e9e0_body.c; object 176B equals retail window, normalized_diff 133; differing offsets 0x0,0x4,0x8-0xF,0x12-0x17. */
// FUN_0044E9E0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044e9e0);
// FUN_0044EA90
void func_0044ea90(void) {}
// FUN_0044F4D0
s32 func_0044f4d0(void) {
    s32 temp;
    temp = func_004526e0();
    if (temp != 0) {
        return temp;
    }
    return 0;
}
// FUN_0044F510
s32 (**func_0044f510(void))(u32) {
    D_00763D1C->fn_30 = func_0044f4d0;
    D_008BE290[0] = func_0044ec60;
    D_008BE294[0] = func_0044ee70;
    D_008BE298[0] = func_0044f140;
    D_008BE29C[0] = func_0044f3a0;
    return D_008BE290;
}
