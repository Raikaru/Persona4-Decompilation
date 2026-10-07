#ifndef EFFECT_VU0_INTERNAL_H
#define EFFECT_VU0_INTERNAL_H

#include "type.h"

/* Ordered VU0 operations used by the Effect geometry and color passes.
 * Inputs and outputs name complete C objects; the compiler owns GPRs, FPRs,
 * and local storage. VF10/VF11 remain live between these volatile operations.
 */
typedef struct EffectVuVector {
    f32 lane[4];
} __attribute__((aligned(16))) EffectVuVector;

static inline void effectVuUnpackColor10(const u32 *word, f32 scale)
{
    u32 transfer = (u32)word;
    __asm__ volatile(
        "lw %0, 0(%0)\n"
        "pextlb %0, $zero, %0\n"
        "pextlh %0, $zero, %0\n"
        "qmtc2.ni %0, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        : "+r"(transfer) : "m"(*word) : "$vf10");
    __asm__ volatile(
        "qmtc2.ni %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : : "r"(scale) : "$vf2", "$vf10");
}

/* The same unpack with the transfer named $2. Retail writes some unpacks
 * this way: $v0 is free just before the unpack, used inside it, and avoided
 * by values live across it (an earlier call result moves to $v1). */
static inline void effectVuUnpackColor10V0(const u32 *word, f32 scale)
{
    __asm__ volatile(
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        : : "r"(word), "m"(*word) : "$2", "$vf10");
    __asm__ volatile(
        "qmtc2.ni %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : : "r"(scale) : "$vf2", "$vf10");
}

static inline void effectVuLoad10(const EffectVuVector *value)
{
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(value), "m"(*value) : "$vf10");
}

static inline void effectVuLoad11(const EffectVuVector *value)
{
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(value), "m"(*value) : "$vf11");
}

static inline void effectVuStore10(EffectVuVector *value)
{
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*value) : "r"(value) : "memory");
}

static inline void effectVuStore11(EffectVuVector *value)
{
    __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*value) : "r"(value) : "memory");
}

static inline void effectVuScale10(f32 scale)
{
    __asm__ volatile(
        "qmtc2.ni %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : : "r"(scale) : "$vf2", "$vf10");
}

static inline void effectVuScale11(f32 scale)
{
    __asm__ volatile(
        "qmtc2.ni %0, $vf2\n"
        "vmulx.xyzw $vf11, $vf11, $vf2x\n"
        : : "r"(scale) : "$vf2", "$vf11");
}

static inline f32 effectVuGetX10(void)
{
    f32 value;
    __asm__ volatile("qmfc2.ni %0, $vf10" : "=r"(value));
    return value;
}

static inline f32 effectVuGetZ10(void)
{
    f32 value;
    u32 transfer;
    __asm__ volatile(
        "qmfc2.ni %0, $vf10 \n"
        "pexew %0, %0 \n"
        "mtc1 %0, %1 \n"
        "nop \n"
        : "=&r"(transfer), "=f"(value));
    return value;
}

static inline void effectVuSetX10(f32 value)
{
    u32 transfer;
    __asm__ volatile(
        "mfc1 %0, %1 \n"
        "nop \n"
        "qmtc2.ni %0, $vf2 \n"
        "vaddx.x $vf10, $vf0, $vf2x \n"
        : "=r"(transfer) : "f"(value) : "$vf2", "$vf10");
}

static inline void effectVuSetZ10(f32 value)
{
    __asm__ volatile("qmtc2.ni %0, $vf2\nvaddx.z $vf10, $vf0, $vf2x"
        : : "r"(value) : "$vf2", "$vf10");
}


#endif
