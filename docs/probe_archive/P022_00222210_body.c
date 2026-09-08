/* UNDEFINED_LIVE_IN_PHASE: retain the 2832-byte retail ASM definition.
 * This supersedes the old COP1_ACCUMULATOR_CHAIN_FLOOR classification.
 * No ordinary-C candidate is supplied, and no C match is claimed.
 *
 * Actual inputs are work in a0 and alpha in a1. At 0x00222244 the
 * incoming f20 is only saved, not assigned. With flag 0x8 clear,
 * four easing calls define f24/f22/f21/f23, never f20. The frame46<7
 * branch at 0x00222400 reaches 0x00222514, bypassing both assignments
 * to f20 at 0x0022247C and 0x00222510.
 * At 0x0022272C, 394.0f is multiplied by this undefined phase.
 * The result reaches twelve gold sprite draws; it is not dead state.
 * Easing and primitive providers preserve f20, and intervening render
 * wrappers do not establish a phase input.
 *
 * The actual direct caller func_00222d20 preserves but never assigns
 * f20 before the call at 0x00222E90. Its first f20 assignment is at
 * 0x00222F28, after this target returns. It gates on flag 0x2, not
 * frame>=7, and supplies only work and alpha as the target's inputs.
 * Constructor func_002230e0 allocates and clears the full 0x74-byte work
 * object. Actual updater func_00221f40 enables flag 0x2 without advancing
 * frame46, so draw frames 1..6 reach the undefined-phase path.
 *
 * An invented FP parameter, register pin, uninitialized C local,
 * phase substitution or early-frame suppression would not be an honest
 * reconstruction. No proven source-level precondition excludes the path.
 * The independently discovered func_0046d280 descriptor-release input
 * defect is corrected in production; it does not resolve this blocker.
 */
