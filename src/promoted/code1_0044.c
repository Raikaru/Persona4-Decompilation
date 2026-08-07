#include "include_asm.h"
#include "type.h"


s32 func_004447f8();
s32 func_00444870();
s32 func_00421da8();
s32 func_0044a138();
f32 func_0044b018(s32 arg0, f32 fparg0, f32 fparg1);
extern s32 *D_00710070;
extern s32 D_009389E0;

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
// FUN_00446ED8 NONMATCHING
#ifdef NON_MATCHING
void func_00446ed8(s8 *arg0) {
    Mesh048 s;

    s.unk0 = (u8 *)arg0;
    s.unk8 = 0x7FFFFFFF;
    s.unkC = 0x208;
    s.unk10 = (u8 *)arg0;
    s.unk14 = 0x7FFFFFFF;
    s.unk54 = (u8 *)D_00710070;
    func_004447f8(&s);
    *arg0 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446ed8);
#endif




// FUN_00446F30
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446f30);

// FUN_00446F80
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446f80);

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
