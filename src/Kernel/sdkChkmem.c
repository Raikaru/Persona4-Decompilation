#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit sdkChkmem.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct ChkMemEntry {
    s32 size;   /* 0x00 */
    u16 pad_04; /* 0x04 */
    s16 pad_06; /* 0x06 */
    u8 cls;     /* 0x08 */
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

typedef struct E8Node E8Node;

extern char D_007104E0[];
extern char D_007104F0[];
extern void func_0046d730(void *file, s32 line);
extern void func_0046d700(const char *file, s32 line, const char *msg, ...);
extern s32 func_0043ece8(s32 size);
extern void func_0044e8d0(void *ptr);
extern s32 func_0042ba20(void);
extern void func_0042ba70(void);
extern void func_0043f810(void *dst, void *src, s32 size);
extern void func_0043ed08(void *ptr);
extern void *func_0044e9e0(void *ptr);
extern u8 *func_0044e920(E8Node *ptr);
extern s32 func_0044eaa0(s32 arg0, s32 arg1, u16 arg2, s16 arg3);
extern char iGpffffac30;
extern void func_0043f9c8(void *dst, s32 value, u32 size);

extern ChkMemPool *D_00763D1C; /* sdkChkmem pool */
extern s32 D_00764AC0;         /* sdkChkmem lock */

/* measured: func_0044eaa0 matches with propagation disabled. The explicit
   class-size temporary preserves retail's classBytes load order. */
#pragma opt_propagation off
// FUN_0044EAA0
s32 func_0044eaa0(s32 arg0, s32 arg1, u16 arg2, s16 arg3)
{
    ChkMemEntry *temp_2;
    s32 temp_16;
    s32 temp_18;
    s32 *temp_20;

    if (arg0 == 0) {
        func_0046d730(D_007104E0, 0x4BA);
    }
    if (((u32)arg0 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4BB);
    }
    temp_2 = (ChkMemEntry *)arg0;
    temp_2->size = arg1;
    temp_2->pad_04 = arg2;
    temp_2->pad_06 = arg3;
    temp_16 = (s32)temp_2 + 24 +
              ((temp_2->pad_04 - 1) &
               (temp_2->pad_04 -
                (((s32)temp_2 + 24) & (temp_2->pad_04 - 1))));
    if (((u32)temp_16 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4C0);
    }
    *(ChkMemEntry **)(temp_16 - 4) = temp_2;
    if (((s32)temp_2 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4C4);
    }
    ++D_00763D1C->count;
    D_00763D1C->bytes += temp_2->size;
    if ((u8)D_00763D1C->classes < 8) {
        temp_20 = (s32 *)(((u8)D_00763D1C->classes << 2) +
                          (s32)D_00763D1C);
        temp_18 = temp_2->size;
        temp_20[14] = temp_20[14] + temp_18;
        temp_18 = temp_2->size - (temp_2->pad_04 + 24);
        D_00763D1C->classCount[(u8)D_00763D1C->classes] += temp_18;
    }
    func_0044e8d0((u8 *)temp_2 + 12);
    *(u16 *)((u8 *)temp_2 + 8) = D_00763D1C->classes;
    return temp_16;
}
#pragma opt_propagation on
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
/* measured: preserves retail allocator reload order. */
#pragma opt_propagation off
// FUN_0044EC60
s32 func_0044ec60(u32 arg0)
{
    s32 temp_17;
    s32 temp_16;
    ChkMemEntry *temp_2;
    s32 temp_18;
    s32 *temp_20;

    temp_17 = func_0042ba20();
    if (arg0 == 0) {
        func_0046d730(D_007104E0, 0x653);
    }
    temp_16 = (arg0 + 0x37) & -0x10;
    temp_2 = (ChkMemEntry *)func_0043ece8(temp_16);
    if (temp_2 == NULL) {
        func_0046d700(D_007104E0, 0x65F, D_007104F0, D_00763D1C->bytes,
                      arg0);
    }
    if (temp_2 == NULL) {
        func_0046d730(D_007104E0, 0x4BA);
    }
    if (((u32)temp_2 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4BB);
    }
    temp_2->size = temp_16;
    temp_2->pad_04 = 0x10;
    temp_2->pad_06 = 0;
    temp_16 = (s32)temp_2 + 24 +
              ((temp_2->pad_04 - 1) &
               (temp_2->pad_04 -
                (((s32)temp_2 + 24) & (temp_2->pad_04 - 1))));
    if (((u32)temp_16 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4C0);
    }
    *(ChkMemEntry **)(temp_16 - 4) = temp_2;
    if (((s32)temp_2 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4C4);
    }
    ++D_00763D1C->count;
    D_00763D1C->bytes += temp_2->size;
    if ((u8)D_00763D1C->classes < 8) {
        temp_20 = (s32 *)(((u8)D_00763D1C->classes << 2) +
                          (s32)D_00763D1C);
        temp_18 = temp_2->size;
        temp_20[14] += temp_18;
        temp_18 = temp_2->size - (temp_2->pad_04 + 24);
        D_00763D1C->classCount[(u8)D_00763D1C->classes] += temp_18;
    }
    func_0044e8d0((u8 *)temp_2 + 12);
    *(u16 *)((u8 *)temp_2 + 8) = D_00763D1C->classes;
    if (temp_17 != 0) {
        func_0042ba70();
    }
    return temp_16;
}
/* measured: func_0044ec60 matches with propagation disabled. */
#pragma opt_propagation on

/* measured: 0044ee70 candidate is 256B in the 256B retail window at current normalized_diff 6, differing offsets 0xC8 and 0xCC. Corrected callee parameter declarations to func_0046d730(void *, s32) and func_0044e920(E8Node *); an explicit E8Node * cast is required by MWCC. The result remains the same store-vs-argument order residual: retail stores `sh $0,8($v0)` before copying `$v0` into `$a0`, while b210 emits the move first. Restored assembly fallback; no live mismatch. */
// FUN_0044EE70 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ee70);

/* measured: func_0044ef70 (464B) floor at nd 54 — a saved-register rotation
   plus the classBytes/classCount pool-reload scheduling floor. retail allocates
   class=temp_16_2 in $s0 and block=func_0043ece8 result in $s1; mwcc b210 puts
   block in $s0 and class in $s1 (declaration order, 4 orders, did not move it).
   The alignment computation and the GP-relative msg string iGpffffac30
   (-0x53D0, "%s %d") now MATCH (added to symbol_data_addrs.txt with evidence).
   Same class-block pool-reload-before-delta floor as func_0044eaa0 plus the
   saved-register rotation family of func_0044ec60/func_0044f3a0. */
/* measured: preserves retail expression and class-array reload order. */
#pragma opt_propagation off
// FUN_0044EF70
s32 func_0044ef70(s32 arg0, s32 arg1, s32 arg2)
{
    u16 temp_16_2;
    ChkMemEntry *temp_2;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_19_2;
    s32 temp_16;
    s32 *temp_20;

    temp_16_2 = arg1;
    temp_18 = 2 * temp_16_2 + 24;
    temp_18 += arg0;
    temp_18_2 = temp_18 - 1;
    temp_19_2 = (-temp_16_2) & temp_18_2;
    temp_2 = (ChkMemEntry *)func_0043ece8(temp_19_2);
    if (temp_2 == NULL) {
        func_0046d700(D_007104E0, 0x69B, (const char *)&iGpffffac30,
                      D_00763D1C->bytes);
    }
    if (temp_2 == NULL) {
        func_0046d730(D_007104E0, 0x4BA);
    }
    if (((u32)temp_2 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4BB);
    }
    temp_2->size = temp_19_2;
    temp_2->pad_04 = temp_16_2;
    temp_2->pad_06 = 0;
    temp_16 = (s32)temp_2 + 24 +
              ((temp_2->pad_04 - 1) &
               (temp_2->pad_04 -
                (((s32)temp_2 + 24) & (temp_2->pad_04 - 1))));
    if (((u32)temp_16 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4C0);
    }
    *(ChkMemEntry **)(temp_16 - 4) = temp_2;
    if (((s32)temp_2 & 3) != 0) {
        func_0046d730(D_007104E0, 0x4C4);
    }
    ++D_00763D1C->count;
    D_00763D1C->bytes += temp_2->size;
    if ((u8)D_00763D1C->classes < 8) {
        temp_20 = (s32 *)(((u8)D_00763D1C->classes << 2) +
                          (s32)D_00763D1C);
        temp_18 = temp_2->size;
        temp_20[14] += temp_18;
        temp_18 = temp_2->size - (temp_2->pad_04 + 24);
        D_00763D1C->classCount[(u8)D_00763D1C->classes] += temp_18;
    }
    func_0044e8d0((u8 *)temp_2 + 12);
    *(u16 *)((u8 *)temp_2 + 8) = D_00763D1C->classes;
    return temp_16;
}
/* measured: func_0044ef70 matches with propagation disabled. */
#pragma opt_propagation on

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
#pragma push
/* measured: opt_propagation off preserves retail saved-register mapping and join-block layout. */
#pragma opt_propagation off
s32 func_0044f140(void *arg0, u32 arg1)
{
    u32 var_18;
    s32 temp_2;
    s32 temp_16;
    s32 temp_17;
    s32 temp_2_2;
    s32 temp_16_2;
    s32 temp_17_2;
    s32 temp_21;
    s32 temp_23;
    s32 **temp_3;
    s32 work;
    s32 result;
    s32 *temp_18;

    temp_21 = func_0042ba20();
    if (arg0 == NULL) {
        temp_17 = func_0042ba20();
        if (arg1 == 0) {
            func_0046d730(D_007104E0, 0x653);
        }
        temp_16 = (arg1 + 0x37) & ~0xF;
        temp_2 = func_0043ece8(temp_16);
        if (temp_2 == 0) {
            func_0046d700(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, arg1);
        }
        work = func_0044eaa0(temp_2, temp_16, 0x10, 0);
        if (temp_17 != 0) {
            func_0042ba70();
        }
        result = work;
    } else {
        temp_3 = (s32 **)((u8 *)arg0 - 4);
        var_18 = **temp_3;
        if (arg1 < var_18) {
            var_18 = arg1;
        }
        temp_23 = func_0042ba20();
        if (arg1 == 0) {
            func_0046d730(D_007104E0, 0x653);
        }
        temp_16_2 = (arg1 + 0x37) & ~0xF;
        temp_2_2 = func_0043ece8(temp_16_2);
        if (temp_2_2 == 0) {
            func_0046d700(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, arg1);
        }
        work = func_0044eaa0(temp_2_2, temp_16_2, 0x10, 0);
        if (temp_23 != 0) {
            func_0042ba70();
        }
        func_0043f810((void *)work, arg0, var_18);
        temp_17_2 = func_0042ba20();
        if (arg0 == NULL) {
            func_0046d730(D_007104E0, 0x670);
        }
        temp_18 = *temp_3;
        func_0043ed08(func_0044e9e0((void *)(u64)temp_18));
        if (temp_17_2 != 0) {
            func_0042ba70();
        }
        result = work;
    }
    if (temp_21 != 0) {
        func_0042ba70();
    }
    return result;
}
#pragma pop
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
