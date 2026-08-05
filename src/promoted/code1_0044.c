#include "include_asm.h"
#include "type.h"


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
// FUN_00446ED8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446ed8);

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
