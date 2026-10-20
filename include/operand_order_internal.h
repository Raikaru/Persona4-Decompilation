#ifndef OPERAND_ORDER_INTERNAL_H
#define OPERAND_ORDER_INTERNAL_H

#include "type.h"

/* Multiply two single-precision values before their caller combines the result. */
/* measured: expanding battle camera products changes mul.s operands and FPR allocation. */
static inline f32 operandOrderMultiply(f32 left, f32 right)
{
    return left * right;
}

/* Add two single-precision values in argument order. */
/* measured: plain additions commute add.s operands; nested panel sums also change allocation. */
static inline f32 operandOrderAddFloat(f32 left, f32 right)
{
    return left + right;
}

/* Add signed word operands without changing their expression evaluation boundary. */
/* measured: expansion changes addu operands; pointer-return helpers also alter motion-index allocation. */
static inline s32 operandOrderAdd(s32 left, s32 right)
{
    return left + right;
}

/* Evaluate the offset before the base while retaining base-first addition. */
/* measured: plain base + offset schedules the base load before index masking and shifting. */
static inline s32 operandOrderAddReversed(s32 offset, s32 base)
{
    return base + offset;
}

/* Multiply two values and add the third within one inline expression. */
/* measured: expanded camera expressions change multiply/add operand ordering and allocation. */
static inline f32 operandOrderMultiplyAdd(f32 left, f32 right, f32 addend)
{
    return left * right + addend;
}

/* Combine signed word bit patterns using exclusive-or. */
/* measured: expanding the battle condition xor changes the whole-owner instruction bytes. */
static inline s32 operandOrderXor(s32 left, s32 right)
{
    return left ^ right;
}

/* Subtract a single-precision displacement from its origin. */
/* measured: expanded model-coordinate subtraction changes whole-owner code generation. */
static inline f32 operandOrderSubtract(f32 origin, f32 distance)
{
    return origin - distance;
}

/* Add an offset to a coordinate loaded through its original pointer. */
/* measured: expanded model plane/coordinate additions change load and arithmetic ordering. */
static inline f32 operandOrderAddLoaded(const f32 *coordinate, f32 offset)
{
    return offset + *coordinate;
}

/* Add unsigned address words with their original wraparound semantics. */
/* measured: expanding the camera table sums changes the whole-owner addu instruction sequence. */
static inline u32 operandOrderAddUnsigned(u32 left, u32 right)
{
    return left + right;
}

/* Merge word-sized flags with the supplied mask. */
/* measured: plain nested roster ORs change allocation and the intermediate OR sequence; packed color ORs swap sources. */
static inline s32 operandOrderOr(s32 flags, s32 mask)
{
    return flags | mask;
}

/* Multiply values with the second argument as the first expression operand. */
/* measured: expansion in ease interpolation changes two bytes at each retained multiply site. */
static inline f32 operandOrderMultiplyReversed(f32 left, f32 right)
{
    return right * left;
}

/* Add a scaled delta after evaluating the addend argument first. */
/* measured: expanded time-track and scene-resource expressions change two bytes per retained site. */
static inline f32 operandOrderAddProduct(f32 addend, f32 delta, f32 factor)
{
    return addend + delta * factor;
}

/* Add a scaled delta after evaluating the product arguments first. */
/* measured: expanding the title palette-channel expression changes its instruction bytes. */
static inline f32 operandOrderProductAddend(f32 delta, f32 factor, f32 addend)
{
    return addend + delta * factor;
}

/* Convert a single-precision product to an unsigned word. */
/* measured: expanding sparkle spans changes the multiply/conversion sequence and FPR allocation. */
static inline u32 operandOrderUnsignedProduct(f32 left, f32 right)
{
    return (u32)(left * right);
}

/* Multiply signed word operands in argument order. */
/* measured: plain selection-column multiplication reverses the mult source operands. */
static inline s32 operandOrderMultiplyWord(s32 left, s32 right)
{
    return left * right;
}

/* Compute a signed remainder before the caller converts its result. */
/* measured: expanding atlas-column remainders changes correction-path allocation and conversion scheduling. */
static inline s32 operandOrderRemainder(s32 value, s32 divisor)
{
    return value % divisor;
}

/* Accumulate a weighted single-precision contribution through its destination. */
/* measured: expanding portrait projections changes madda.s/madd.s scheduling and accumulator FPR allocation. */
static inline void operandOrderAccumulateProduct(f32 *total, f32 weight, f32 projection)
{
    *total += weight * projection;
}

/* Compare signed words before the caller tests the predicate. */
/* measured: expanding the fusion-material comparison changes the comparison/branch instruction bytes. */
static inline s32 operandOrderNotEqual(s32 value, s32 target)
{
    return value != target;
}

/* Round a displacement product to single precision before its caller adds an anchor. */
/* measured: a direct return fuses the score baseline into adda.s/madd.s; this assignment retains mul.s/add.s. */
static inline f32 operandOrderRoundedProduct(f32 phase, f32 scale)
{
    f32 product;
    product = scale * phase;
    return product;
}

#endif
