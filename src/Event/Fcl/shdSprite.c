/* Consolidated Persona 4 source units. */
/* Original translation unit shdSprite.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

typedef signed __int128 s128;
typedef void (*shd_cb)(s32, u8, s8 *, s32, s32, s32, f32, f32, f32);
typedef void (*shd_cb_f)(f32, f32, f32, s32, u8, s8 *, s32, s32, s32);


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
s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
s32 func_0025f540(s32, s32, s32, s32, u8 *, s32, s32, s32, s64, f32, f32, f32, f32, f32, f32);
u32 func_0025f6b0(f32, f32, f32, s32, u8, s32, s32, s16 *, shd_cb, s32);

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
/* measured: retail schedules the loop's array load (lw $v0, 8($s2)) BEFORE the
   CSE'd index*4 (sll $s0, $s1, 2); mwcc b210 always hoists the sll above the
   independent load. nd 2, every other word byte-identical (70 words). Tried
   arr-local + arr[index], arr-local + off local, single inline index*4
   expression, pointer-addition statement (p = arr + index), and if+do-while /
   for(;;)+break shapes (the for(;;)+break shape fixed the return-0 block
   layout, the rest was already exact). Scheduling-order floor. */
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
s32 func_0025f2c0(s32 arg0, s32 arg1, u8 *arg2)
{
    s32 temp_3;
    u8 *temp_7;
    u8 *elem;

    temp_3 = *(s32 *)(arg2 + 0xC);
    if (temp_3 != 0) {
        temp_7 = (u8 *)(temp_3 + ((arg0 & 0xFFFF) * 8));
        elem = *(u8 **)(*(u32 *)(arg2 + 8) + (*(s8 *)temp_7 * 4));
        return (s32)func_0046b1f0(elem, *(s16 *)(temp_7 + 2) + arg1);
    }
    elem = *(u8 **)(*(u32 *)(arg2 + 8) + (((arg0 >> 16) & 0xFFFF) * 4));
    return (s32)func_0046b1f0(elem, (arg0 & 0xFFFF) + arg1);
}

// FUN_0025F360
f32 func_0025f360(s32 arg0, s32 arg1, u8 *arg2)
{
    s32 temp_3;
    u8 *temp_7;
    u8 *elem;

    temp_3 = *(s32 *)(arg2 + 0xC);
    if (temp_3 != 0) {
        temp_7 = (u8 *)(temp_3 + ((arg0 & 0xFFFF) * 8));
        elem = *(u8 **)(*(u32 *)(arg2 + 8) + (*(s8 *)temp_7 * 4));
        return func_0046d5f0(elem, *(s16 *)(temp_7 + 2) + arg1);
    }
    elem = *(u8 **)(*(u32 *)(arg2 + 8) + (((arg0 >> 16) & 0xFFFF) * 4));
    return func_0046d5f0(elem, (arg0 & 0xFFFF) + arg1);
}

// FUN_0025F3F0
s32 func_0025f3f0(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, f32 f0, f32 f1, f32 f2)
{
    func_0025f430(a0, a1, a2, a3, a4, a5, 0, 0, f0, f1, f2, 0.0f, 1.0f, 1.0f);
    return 0;
}

// FUN_0025F430
s32 func_0025f430(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s32 a6, s32 a7, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5)
{
    s32 temp_3;
    u8 *temp_6;
    u8 *elem;

    temp_3 = *(s32 *)(a4 + 0xC);
    if (temp_3 != 0) {
        temp_6 = (u8 *)(temp_3 + ((a2 & 0xFFFF) * 8));
        elem = *(u8 **)(*(u32 *)(a4 + 8) + (*(s8 *)temp_6 * 4));
        func_0025ea20(a0, a1, *(s16 *)(temp_6 + 2) + a3, elem, a5, a6, a7, f0 + (f32)*(s16 *)(temp_6 + 4), f1 + (f32)*(s16 *)(temp_6 + 6), f2, f3, f4, f5);
    } else {
        elem = *(u8 **)(*(u32 *)(a4 + 8) + (((a2 >> 16) & 0xFFFF) * 4));
        func_0025ea20(a0, a1, (a2 & 0xFFFF) + a3, elem, a5, a6, a7, f0, f1, f2, f3, f4, f5);
    }
    return 0;
}

// FUN_0025F500
s32 func_0025f500(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s64 a6, f32 f0, f32 f1, f32 f2)
{
    func_0025f540(a0, a1, a2, a3, a4, a5, 0, 0, a6, f0, f1, f2, 0.0f, 1.0f, 1.0f);
    return 0;
}

// FUN_0025F540
s32 func_0025f540(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s32 a6, s32 a7, s64 a8, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5)
{
    s32 temp_3;
    u8 *temp_6;
    u8 *elem;

    temp_3 = *(s32 *)(a4 + 0xC);
    if (temp_3 != 0) {
        temp_6 = (u8 *)(temp_3 + ((a2 & 0xFFFF) * 8));
        elem = *(u8 **)(*(u32 *)(a4 + 8) + (*(s8 *)temp_6 * 4));
        func_0025ecd0(a0, a1, *(s16 *)(temp_6 + 2) + a3, elem, a5, a6, a7, *(s32 *)&a8, f0 + (f32)*(s16 *)(temp_6 + 4), f1 + (f32)*(s16 *)(temp_6 + 6), f2, f3, f4, f5);
    } else {
        elem = *(u8 **)(*(u32 *)(a4 + 8) + (((a2 >> 16) & 0xFFFF) * 4));
        func_0025ecd0(a0, a1, (a2 & 0xFFFF) + a3, elem, a5, a6, a7, *(s32 *)&a8, f0, f1, f2, f3, f4, f5);
    }
    return 0;
}

// FUN_0025F620
void func_0025f620(s32 a0, u8 a1, s32 a2, s32 a3, s16 a4, s16 a5, shd_cb cb, s32 a7, f32 f0, f32 f1, f32 f2)
{
    s16 buf[0xC];
    u8 *p;
    s32 n;

    p = (u8 *)buf;
    n = 0x18;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    buf[0] = a4;
    buf[1] = a4;
    buf[2] = a4;
    buf[3] = a4;
    buf[4] = a4;
    buf[5] = a4;
    buf[6] = a4;
    buf[7] = a4;
    buf[8] = a4;
    buf[9] = a4;
    buf[10] = a5;
    buf[11] = a4;
    func_0025f6b0(f0, f1, f2, a0, a1, a2, a3, (s16 *)buf, cb, a7);
}

// FUN_0025F6B0
u32 func_0025f6b0(f32 f0, f32 f1, f32 f2, s32 a0, u8 a1, s32 a2, s32 a3, s16 *a4, shd_cb cb, s32 a6)
{
    s8 buf[0x20];
    s32 j;
    s32 off;
    u32 i;
    s32 width;
    u32 len;
    s32 k;
    s32 flag8;

    off = 0;
    func_0043f9c8(buf, 0, 0x20);
    len = (u32)func_00442948((const char *)a2);
    width = 0;
    i = 0;
    j = 0;
    flag8 = a3 & 8;
    do {
        s8 *sp;
        s8 *bp;

        sp = (s8 *)a2 + i;
        if (*sp == 0x20) {
            buf[j] = 0xB;
            width += (u32)a4[0xB];
            i++;
        } else {
            if (flag8 != 0 && len > 3 && i != 0 && (len - i) % 3 == 0) {
                buf[j] = 0xA;
                width += (u32)a4[0xA];
                j++;
            }
            bp = &buf[j];
            *bp = (s8)(*sp - 0x30);
            if ((s8)*bp < 0) {
                func_0046d730(D_00637280, 0x1B9);
            }
            if (*bp >= 0xA) {
                func_0046d730(D_00637280, 0x1BA);
            }
            width += (u32)a4[*bp];
            i++;
        }
        j++;
    } while (i < len);
    if (a3 & 1) {
        f0 -= (f32)width;
    } else if (a3 & 2) {
        f0 -= (f32)(s32)((u32)width >> 1);
    }
    k = 0;
    while (k < j) {
        if (buf[k] != 0xB) {
            ((shd_cb_f)cb)(f0 + (f32)off, f1, f2, a0, a1, (s8 *)buf, k, j, a6);
        }
        off += (s32)a4[buf[k]];
        k++;
    }
    return width;
}
