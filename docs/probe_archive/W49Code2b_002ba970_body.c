/*
 * func_002ba970 reconstruction floor (W49Code2b).
 *
 * Measured with tools/fndiff.py against the 0x002BA970 retail window:
 * object_size=164B, retail_window=176B, normalized_diff=41 words.
 * Matching words are offsets 0x00, 0x04, and 0x18; the remaining 41 words
 * differ, and the candidate is 12B short of the retail epilogue.  The live
 * source therefore remains INCLUDE_ASM; this archive is not a C closure.
 *
 * Retail evidence and CSP caller search agree that arg0 is the record-root
 * pointer, arg1 is a signed short index, and arg2 is one packed four-byte
 * color value.  The aggregate spelling below reproduces the retail frame and
 * initial `sw $a2,0xC($sp)`, while signed-short offset locals reproduce the
 * two 0x220-stride record calculations.  Retail then reloads the four color
 * bytes from the spilled argument after the offset arithmetic, writes them to
 * 0x179..0x17C of both records, and writes byte 3 to 0x162 of both.  The
 * callers in src/Event/Fcl/y_fclCombineDraw.c declare the legacy call as
 * `(u8 *, s64, s32)`; their assembly sign-extends the narrow index before the
 * call and loads the packed color in $a2.  Generated callers use the same
 * three-register ABI through old-style M2C_UNK declarations.  No caller files
 * were changed for this scoped target.
 *
 * Tried: struct and union/u4 aggregate parameters, scalar u32 plus local
 * packed union, direct aggregate fields and u8* aliases, split and reused
 * destination pointers, opt_propagation, and opt_common_subs.  The best
 * aggregate candidate below is nd41; the alias/liveness variant was also nd41.
 */

typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} u4;

// FUN_002BA970
void func_002ba970(u8 *arg0, s16 arg1, u4 arg2)
{
    s16 dbl;
    s32 offset_a;
    s32 offset_b;
    u8 *p;

    dbl = arg1 * 2;
    offset_a = (s16)dbl * 0x220;
    p = *(u8 **)(arg0 + 0x38) + offset_a;
    p[0x179] = arg2.c0;
    p[0x17A] = arg2.c1;
    p[0x17B] = arg2.c2;
    p[0x17C] = arg2.c3;
    offset_b = (s16)(dbl + 1) * 0x220;
    p = *(u8 **)(arg0 + 0x38) + offset_b;
    p[0x179] = arg2.c0;
    p[0x17A] = arg2.c1;
    p[0x17B] = arg2.c2;
    p[0x17C] = arg2.c3;
    p = *(u8 **)(arg0 + 0x38) + offset_a;
    p[0x162] = arg2.c3;
    p = *(u8 **)(arg0 + 0x38) + offset_b;
    p[0x162] = arg2.c3;
}
