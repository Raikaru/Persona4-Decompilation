#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit sdkChkmem.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct ChkMemEntry {
    s32 size;   /* 0x00 */
    u16 pad_04; /* 0x04 */
    s16 pad_06; /* 0x06 */
    u8  cls;    /* 0x08 */
} ChkMemEntry;

typedef struct ChkMemPool {
    ChkMemEntry *first;    /* 0x00 */
    ChkMemEntry *last;     /* 0x04 */
    s32 total;             /* 0x08 */
    u8 pad_0C[0x0C];       /* 0x0C */
    s32 count;             /* 0x18 */
    s32 bytes;             /* 0x1C */
    u8 pad_20[0x10];       /* 0x20 */
    void (*fn_30)(void);   /* 0x30 */
    u16 classes;           /* 0x34 */
    s32 classBytes[8];     /* 0x38 */
    s32 classCount[8];     /* 0x58 */
} ChkMemPool;

extern char D_007104E0[];
extern char D_007104F0[];
extern void func_0046d730(const char *file, s32 line);
extern void func_0046d700(const char *file, s32 line, const char *msg, ...);
extern s32 func_0043ece8(s32 size);
extern void func_0044e8d0(void *ptr);
extern s32 func_0042ba20(void);
extern void func_0042ba70(void);
extern void func_0043f810(void *dst, void *src, s32 size);
extern void func_0043ed08(void *ptr);
extern void *func_0044e9e0(void *ptr);
extern u8 *func_0044e920(u8 *ptr);
extern s32 func_0044eaa0(s32 arg0, s32 arg1, u16 arg2, s16 arg3);
extern char iGpffffac30;
extern void func_0043f9c8(void *dst, s32 value, u32 size);

extern ChkMemPool *D_00763D1C; /* sdkChkmem pool */
extern s32 D_00764AC0;         /* sdkChkmem lock */

/* measured: func_0044eaa0 (400B) floor at nd 12 in the classBytes/classCount
   accounting block. retail loads arg0->size (RHS) BEFORE classBytes[cls] and
   computes classCount's delta BEFORE reloading the pool; mwcc b210 always loads
   the compound-assignment LHS (classBytes[cls]) first and hoists the classCount
   index's pool load above the delta. Tried compound +=, `= rhs + lhs`, named
   val/delta locals, `(u8)classes` index casts, raw-classBytes-pointer, and
   arg0-as-ChkMemEntry* forms; all nd 12 (worse: 29/34 with extra locals).
   Later attempts retried the parent's struct-field load-order lever but the
   residual is a compound-assignment LHS schedule, not a pre-jal arg order. */
// FUN_0044EAA0
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044eaa0);
// FUN_0044EC30
s32 func_0044ec30(void) {
    return D_00763D1C->bytes;
}

// FUN_0044EC40
u16 func_0044ec40(void) {
    return D_00763D1C->classes;
}

// FUN_0044EC50
void func_0044ec50(s32 arg0) {
    D_00764AC0 = arg0;
}

/* measured: func_0044ec60 (528B) floor at nd 34 — a saved-register rotation
   plus the same classBytes/classCount accounting block floored in func_0044eaa0.
   retail allocates block=temp_2 in $s2, aligned=temp_16_2/$s0 (reused), lock
   in $s1; mwcc b210 puts block in $s0, aligned in $s1, lock in $s2. Declaration
   order (8 orders probed), s32 vs u32 arg0, cls local, and m2c decl order all
   stayed at 34 (worse 51 with cls local). Same class-block scheduling floor as
   func_0044eaa0 (arg0->size RHS-first, classCount delta-before-pool-reload). */
// FUN_0044EC60
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ec60);

/* measured: 0044ee70 candidate is 256B in the 256B retail window at verify normalized_diff 6. The header lookup, pool counters, direct class-byte loads, class accounting, free transition, and lock cleanup match; the only remaining residual is retail storing `sh $0,8($v0)` before copying the result into `$a0`, while b210 emits the argument move first. Named offset/pointer forms and field-load split variants were probed; plain C cannot force that store-vs-argument schedule. Committed at nd 6. */
// FUN_0044EE70 NONMATCHING
#ifdef NON_MATCHING
void func_0044ee70(u8 *arg0) {
    s32 lock;
    u8 *block;
    u8 *pool;
    u8 *pool2;
    u8 *result;
    s32 size;
    s32 delta;
    u16 payload;
    s32 block_size;
    u32 offset;

    lock = func_0042ba20();
    if (arg0 == NULL) {
        func_0046d730(D_007104E0, 0x670);
    }
    block = *(u8 **)(arg0 - 4);
    pool = (u8 *)D_00763D1C;
    *(s32 *)(pool + 0x18) = *(s32 *)(pool + 0x18) - 1;
    pool2 = (u8 *)D_00763D1C;
    *(s32 *)(pool2 + 0x1C) = *(s32 *)(pool2 + 0x1C) - *(s32 *)block;
    if ((s32)*(u8 *)(block + 8) < 8) {
        pool = (u8 *)D_00763D1C;
        offset = *(u8 *)(block + 8) * 4;
        pool2 = (u8 *)(offset + (u32)pool);
        *(s32 *)(pool2 + 0x38) = *(s32 *)(pool2 + 0x38) - *(s32 *)block;
        payload = *(u16 *)(block + 4);
        size = payload + 0x18;
        block_size = *(s32 *)block;
        size = block_size - size;
        offset = *(u8 *)(block + 8) * 4;
        pool2 = (u8 *)(offset + (u32)D_00763D1C);
        delta = *(s32 *)(pool2 + 0x58) - size;
        *(s32 *)(pool2 + 0x58) = delta;
    }
    result = func_0044e920(block + 0xC);
    *(s16 *)(result + 8) = 0;
    func_0043ed08(result);
    if (lock != 0) {
        func_0042ba70();
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ee70);
#endif
/* measured: func_0044ef70 (464B) floor at nd 54 — a saved-register rotation
   plus the classBytes/classCount pool-reload scheduling floor. retail allocates
   class=temp_16_2 in $s0 and block=func_0043ece8 result in $s1; mwcc b210 puts
   block in $s0 and class in $s1 (declaration order, 4 orders, did not move it).
   The alignment computation and the GP-relative msg string iGpffffac30
   (-0x53D0, "%s %d") now MATCH (added to symbol_data_addrs.txt with evidence).
   Same class-block pool-reload-before-delta floor as func_0044eaa0 plus the
   saved-register rotation family of func_0044ec60/func_0044f3a0. */
// FUN_0044EF70
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ef70);

/* measured: func_0044f140 (608B) floor at nd 87 — a pervasive saved-register
   rotation across the two-branch alloc/relocate body. retail: outer lock
   temp_21=$s5, first-branch lock=$s1, aligned=$s0, block=$s2, else-branch base
   arg0-4=$s6, temp_23=$s7; mwcc b210 puts outer lock in $s6, first lock in $s0,
   and caches the else block in $s5 instead of keeping arg0-4 in $s6. Declaration
   order (3 orders), block-cache vs inline `*(u8**)(arg0-4)` (raw inline went to
   128), all failed. Logic (func_0044eaa0/0043f810/0044e9e0/0043ed08 calls,
   min-size, GP-relative strings) is correct; same saved-register rotation family
   as func_0044ec60/func_0044f3a0/func_0044ef70. */
// FUN_0044F140
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044f140);

// FUN_0044F3A0
s32 func_0044f3a0(s32 arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 temp_19_2;
    u32 temp_18;

    temp_17 = func_0042ba20();
    temp_16 = func_0042ba20();
    temp_18 = arg1 * arg0;
    if (temp_18 == 0) {
        func_0046d730(D_007104E0, 0x653);
    }
    temp_19_2 = (temp_18 + 0x37) & ~0xF;
    temp_2 = func_0043ece8(temp_19_2);
    if (temp_2 == 0) {
        func_0046d700(D_007104E0, 0x65F, D_007104F0, D_00763D1C->bytes, temp_18);
    }
    temp_19_2 = func_0044eaa0(temp_2, temp_19_2, 0x10, 0);
    if (temp_16 != 0) {
        func_0042ba70();
    }
    if (temp_19_2 != 0) {
        func_0043f9c8((void *)temp_19_2, 0, temp_18);
    }
    if (temp_17 != 0) {
        func_0042ba70();
    }
    return temp_19_2;
}
