#ifndef P4_INCLUDE_ASM_H
#define P4_INCLUDE_ASM_H

/* mwccgap consumes these markers before invoking mwcc.  They remain empty
 * for direct MWCC builds so source files can carry the same placeholders. */
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

/* SKIP_ASM builds (decomp.dev's "-DSKIP_ASM=1" convention):
 *
 * Passing --skip-asm to tools/mwccgap (the Makefile's objdiff-objects target
 * does this) makes the wrapper skip the assembly splice entirely, so these
 * macros expand to nothing and INCLUDE_ASM functions are absent from the
 * object.  That is the honest base for progress purposes: an assembly
 * fallback is byte-correct by construction and must never score as matched
 * code, so the progress objects are built with SKIP_ASM semantics while the
 * real linked build still splices the assembly.
 */

#endif /* P4_INCLUDE_ASM_H */
