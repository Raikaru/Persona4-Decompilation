/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004460F0)
#include "type.h"

s32 func_00446108();

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00446108 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_004460F0 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
void func_004460f0(void) {
    func_00446108();
}
#pragma pop
#endif /* P4_UNIT_004460F0 */

#if defined(P4_UNIT_0044B8D8)
#include "type.h"

s64 func_004470f0(s64 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_004470f0 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B8D8 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
s64 func_0044b8d8(s64 arg0) {
    return func_004470f0(arg0);
}
#pragma pop
#endif /* P4_UNIT_0044B8D8 */

#if defined(P4_UNIT_0044B8F0)
#include "type.h"

s32 func_00447b88(s64 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00447b88 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B8F0 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
s32 func_0044b8f0(s64 arg0) {
    return func_00447b88(arg0);
}
#pragma pop
#endif /* P4_UNIT_0044B8F0 */

#if defined(P4_UNIT_0044B908)
#include "type.h"

s32 func_00447d00(s64 arg0, s32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00447d00 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B908 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
s32 func_0044b908(s64 arg0, s32 arg1) {
    return func_00447d00(arg0, arg1);
}
#pragma pop
#endif /* P4_UNIT_0044B908 */

#if defined(P4_UNIT_0044B920)
#include "type.h"

f32 func_00448d10(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00448d10 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B920 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
f32 func_0044b920(f32 arg0) {
    return func_00448d10(arg0);
}
#pragma pop
#endif /* P4_UNIT_0044B920 */

#if defined(P4_UNIT_0044B938)
#include "type.h"

f32 func_00449120(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449120 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B938 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
f32 func_0044b938(f32 arg0) {
    return func_00449120(arg0);
}
#pragma pop
#endif /* P4_UNIT_0044B938 */

#if defined(P4_UNIT_0044B950)
#include "type.h"

f32 func_004494b8(f32 arg0, f32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_004494b8 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B950 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
f32 func_0044b950(f32 arg0, f32 arg1) {
    return func_004494b8(arg0, arg1);
}
#pragma pop
#endif /* P4_UNIT_0044B950 */

#if defined(P4_UNIT_0044B968)
#include "type.h"

f32 func_00449680(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449680 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B968 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
f32 func_0044b968(f32 arg0) {
    return func_00449680(arg0);
}
#pragma pop
#endif /* P4_UNIT_0044B968 */

#if defined(P4_UNIT_0044B980)
#include "type.h"

f32 func_00449938(f32 arg0, f32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449938 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B980 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
f32 func_0044b980(f32 arg0, f32 arg1) {
    return func_00449938(arg0, arg1);
}
#pragma pop
#endif /* P4_UNIT_0044B980 */

#if defined(P4_UNIT_0044B998)
#include "type.h"

f32 func_0044a4d0(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_0044a4d0 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */
// FUN_0044B998 NONMATCHING
#pragma push
#pragma schedule on
#pragma tailcall on
f32 func_0044b998(f32 arg0) {
    return func_0044a4d0(arg0);
}
#pragma pop
#endif /* P4_UNIT_0044B998 */
