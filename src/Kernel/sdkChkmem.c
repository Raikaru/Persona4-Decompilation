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

/* measured: func_0044ee70 (256B) floor at nd 2 — the classBytes/classCount
   accounting now MATCHES (the `cls` byte must be read DIRECTLY as
   `*(u8 *)(block + 8)` at each use, NOT cached in a u8 local: caching put the
   pool reload/classCount re-read in the wrong place, nd 23). The residual is a
   pure store-vs-arg-copy schedule before `func_0043ed08`: retail emits
   `sh $0, 8($v0)` (store to the func_0044e920 result) THEN `move $a0, $v0`;
   mwcc b210 always emits the arg move first. Tried s16/u16 store, index store
   `((s16 *)r)[4]`, fresh result var r, and lock/block decl swap — all nd 2.
   Parent's struct-field load-order lever does not apply (arg is a register
   value, not a memory load). */
// FUN_0044EE70
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044ee70);

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

/* measured: func_0044f3a0 (304B) floor at nd 8 — a persistent saved-register
   swap: retail puts block=func_0043ece8 result in $s4 and aligned=temp_19_2 in
   $s3 (reusing dead arg0's register); mwcc b210 always puts block in $s3 and
   aligned in $s4. Whole function body otherwise byte-identical (the
   func_0044eaa0, func_0043f9c8, lock calls all match). Declaration order (5+
   orders incl. temp_18 positioned), mult operand order (`arg1*arg0` vs
   `arg0*arg1`), and split aligned computation all failed (nd 8, worse 9/32).
   Same saved-register rotation family as func_0044ec60. */
// FUN_0044F3A0
INCLUDE_ASM("asm/nonmatchings/sdkChkmem", func_0044f3a0);
