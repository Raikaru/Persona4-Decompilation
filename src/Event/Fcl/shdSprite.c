/* Consolidated Persona 4 source units. */
/* Original translation unit shdSprite.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

typedef signed __int128 s128;
typedef void (*shd_cb)(s32, u8, s8 *, s32, s32, s32, f32, f32, f32);

#pragma alias DAT_008873ec_abs DAT_008873ec

// func_0046b0d0 is intentionally left undeclared (implicit old-style call,
// exactly as in the P3 donor FUN_0040e580): a typed prototype makes mwcc
// emit andi zero-extensions the retail never has.

s32 func_00442948(const char *text);
void func_0044ea90(const void *msg, s32 id);
void func_0043f810(void *dst, const void *src, u32 size);
void func_0043f9c8(void *dst, s32 value, u32 size);
u8 *func_00455f70(void *arg0, u32 *arg1);
u8 *func_0046af60(s32 arg0);
u8 *func_0046aea0(const char *name);
s32 func_0046a750(s32 param);
f32 func_0046b1f0(void *ptr, s32 index);
f32 func_0046d5f0(void *ptr, s32 index);
void func_0046d730(const void *file, s32 line);

void func_0025ea20(s32, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
void func_0025ecd0(s32, s32, s32, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);

/* Allocator slot at 0x008873F4 (absolute, outside gp window). */
extern u8 *(*D_008873F4[])(s32, s32, s32);
/* Assert source file string. */
extern u8 D_00637280[];

/* measured: retail computes the alignment `size + (size & 1)` immediately after
   the string-length loop (andi/addu into $a0), then the allocation size sum
   (sll $v1 / lw+sll $v0 / addu / addiu / addu $s1, $v0, $a0).  mwcc b210
   sinks the independent align computation to just before its use and renames
   the sum into $v1 (addiu $v1, $v0, 0x14), giving nd 9 with zero structural
   differences elsewhere.  Tried: inline single expression (nd 93, folds
   count*8+fieldC*8 into (count+fieldC)*8), split statements into size or a
   separate total (nd 9), every saved-register declaration order (nd 9, all
   other rows already byte-identical), align operand swaps, chain/align
   statement orderings, #pragma optimization_level 1 (nd 87).  This is the
   known load-sinking floor. */
// FUN_0025EF20
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025ef20);
// FUN_0025F110
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f110);
// FUN_0025F230
void func_0025f230(u32 param_1)
{
    int i;

    if (param_1 != 0) {
        for (i = 0; i < *(int *)(*(int *)((int)param_1 + 4) + 4); i = i + 1) {
            func_0046b0d0((void *)*(u32 *)(*(int *)((int)param_1 + 8) + i * 4));
        }
        DAT_008873ec_abs[0](param_1);
    }
}

// FUN_0025F2C0
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f2c0);

// FUN_0025F360
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f360);

// FUN_0025F3F0
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f3f0);

// FUN_0025F430
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f430);

// FUN_0025F500
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f500);

// FUN_0025F540
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f540);

// FUN_0025F620
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f620);

// FUN_0025F6B0
INCLUDE_ASM("asm/nonmatchings/shdSprite", func_0025f6b0);
