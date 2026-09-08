/* UNINITIALIZED_STACK_POINT: retain the 2032-byte retail ASM definition.
 * This supersedes the old COP1_ACCUMULATOR_CHAIN_FLOOR classification.
 * No defined ordinary-C candidate or matching C result is claimed.
 *
 * On the unit+0xA2 == 0 path, 0x002260F8 loads f1 from sp+0x134.
 * No preceding instruction or provider initializes those four bytes.
 * The value contributes to point Y through adda.s/madd.s, and its first
 * store is only at 0x0022610C. It later reaches camera-pose construction.
 *
 * The preceding pose copy writes sp+0xE0..0xFB; group-center output writes
 * sp+0x150..0x15B; unit sphere-center output writes sp+0x140..0x14B.
 * Normalization touches only sp+0x120..0x12B. Explicit Y zero stores are
 * at sp+0x144 and sp+0x154, not sp+0x134. The point's X copy at 0x002260E4
 * does not initialize its Y. Provider extents do not hide the missing write.
 *
 * Direct callers func_00228d50 and func_00228f60 select this very side-zero
 * path. Their calls at 0x00228D7C and 0x00228F88 preserve camera in a0;
 * neither initializes target sp+0x134 (= caller sp-0x2C). No proven
 * precondition requires the earlier mode/UID shortcut on every such call.
 * The action-null arm is not null-safe: it joins a load from action+0x30.
 * Real direct callers already dereference that action and unit.
 *
 * Independently, func_00196040 can leave all outputs unwritten for an empty
 * eligible group. Even a nonempty group does not resolve sp+0x134.
 * Inventing point Y, an input parameter, caller-stack storage or an
 * uninitialized C local is not an honest replacement.
 * The two production C callers now explicitly forward their real camera
 * argument; this input-contract repair does not resolve the stack blocker.
 */
