/* Closest clean-C probe for FUN_001D01C0; retained as ASM because it did not match.
 * Measured object 988B/window 1008B, normalized_diff 587. Prologue and stack
 * layout matched; the residual is the FPU-register scheduling and accumulator
 * (adda/msub/madd) sequence in the vector projection math.
 */
