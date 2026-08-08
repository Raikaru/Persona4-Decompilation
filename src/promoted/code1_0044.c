#include "include_asm.h"
#include "type.h"


s32 func_004447f8();
s32 func_00444870();
s32 func_00421da8();
s32 func_0044a138();
f32 func_0044b018(s32 arg0, f32 fparg0, f32 fparg1);
extern s32 *D_00710070;
extern s32 D_009389E0[];

typedef struct {
    u8 *unk0;      /* 0x0 */
    s32 unk8;      /* 0x8 */
    s16 unkC;      /* 0xC */
    u8 *unk10;     /* 0x10 */
    s32 unk14;     /* 0x14 */
    u8 pad18[0x3C];
    u8 *unk54;     /* 0x54 */
} Mesh048;

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
// Archived C body: build/WBHygiene_func_00446ed8_archive.txt; no current park body remains.
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
// Archived C body: build/WBHygiene_func_0044b868_archive.txt; no current park body remains.
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
