#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultSimple.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0021dda0(void);
extern u16 *func_00452560();
void func_00454bd0(u8 *ptr);
void func_0046b0d0(void *ptr);
void func_0046d280(s32 arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
void func_0044ea90(const void *msg, s32 id);
void func_0043f9c8(void *dst, s32 value, u32 size);
s32 func_00451fc0(s32 window, const void *data, s32 a, s32 b, s32 c,
                  s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
extern char D_00629628[];
extern char D_006290F0[];
extern char D_00629610[];
extern s64 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
void func_00440b68(void *msg, const void *file, s32 line);
extern u8 *func_00454a60(u8 *param, s32 mode);
void func_0046d730(const void *file, s32 line);
s32 func_0046a770(u32 param);
s32 func_004553c0(u8 *ptr);
s32 func_00455ea0(s32 param, s32 a, s32 b);
s32 func_0046af60(u8 *arg0);
s32 func_0046a750(s32 param);
void func_0021fea0(u8 *work);
void func_002214d0(void);
void func_0034f2e0(void *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, f32 arg5, f32 arg6);
void func_00442088(void *dst, const void *fmt, s32 value);
void func_00460ac0(void *param, void *work);
extern u32 D_00795F20[];
s32 func_0021f520(u8 *arg0);
s32 func_0021de60(void);

/* Work buffer handed to the result state machine (see func_002215c0). */
typedef struct BtlResultWork BtlResultWork;
struct BtlResultWork
{
    u16 flags;         // 0x00
    u16 pad02;         // 0x02
    u32 state;         // 0x04
    s32 field08;       // 0x08
    s32 field0C;       // 0x0C
    u8 pad10[0x2C];    // 0x10..0x3B
    u16 field3C;       // 0x3C
    u8 pad3E[0x3C2];   // 0x3E..0x3FF
    s32 field400[3];   // 0x400..0x40B
    u8 pad40C[8];      // 0x40C..0x413
    s32 field414[0x2A];// 0x414..0x4BB
    s32 field4BC;      // 0x4BC
    u8 pad4C0[0xB0];   // 0x4C0..0x56F
    u8 *field570;      // 0x570
};

s32 func_0021f340(BtlResultWork *work);
void func_0021ef70(BtlResultWork *work);
void func_002baac0(s32 param);
void func_002bad10(s32 param);
void func_002bb4e0(void);
s32 func_00353f50(s32 param);
extern void func_0021f790();

typedef struct BtlResultSubWork BtlResultSubWork;
struct BtlResultSubWork
{
    u8 pad[0x60];
    s32 field60;       // 0x60
    u8 pad64[0x8D0];   // 0x64..0x933
    s32 field934;      // 0x934
};

/* measured: retail allocates B=$s0,A=$s1,arg1=$s2,arg0=$s3,d=$s4,k=$s5,R=$s6,G=$s7
   and emits the float args before the int args at the func_0034f2e0 call sites;
   mwcc b210 allocates A=$s0,arg1=$s1,arg0=$s2,d=$s3,B=$s4 and emits int args
   first (nd 132 bytes, obj 604B vs window 608B; walk-loop switch form matches
   retail's beq-out-of-line shape, frame and stack slots exact). Tried: every
   declaration order of A/R/G/B/d/k/v/i/n/j (6 batches), u8 vs s32 colors,
   if-vs-switch walk; all give the identical rotation + arg order.
   Register-coloring/arg-evaluation-order floor, same family as 214d0/21770/
   21f340. */
// FUN_0021ED10
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021ed10);

// FUN_0021EF70
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021ef70);

/* measured: retail allocates work=$s1, counter=$s2, store-addr=$s0 and hoists
   the indexed store address to the top of the loop body (before the two calls);
   mwcc b210 allocates work=$s2, counter=$s1 and re-derives the store address
   after the calls (nd 273 bytes, rest identical). Tried: all declaration
   orders of i/count/v, loop-local dst pointers (pointer-arith and struct
   member), inline and temp-value store forms; identical output every time.
   Register-coloring/scheduling floor, same family as 214d0/21770. */
// FUN_0021F340
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021f340);

// FUN_0021F520
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021f520);

// FUN_0021F790
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021f790);

// FUN_0021FA40
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fa40);

// FUN_0021FEA0
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fea0);

/* measured: retail allocates p=$s0, loop-addr=$s1, counter=$s2; mwcc b210
   invariantly allocates the named values to $s1/$s0 and the indexed store
   address temp to $s2 (counter<->addr rotation, nd 12, rest byte-identical).
   Tried: struct-vs-pointer arith for the 0x4BC block, every declaration order
   of p/w/i (8 variants), loop-local addr pointers, shared addr var, u16/u32
   counters; all give the identical 12-word rotation. Register-coloring floor. */
// FUN_002214D0
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_002214d0);

// FUN_002215C0
s32 func_002215c0(s32 arg0) {
    u8 *buf;
    u16 *q;
    s32 r;

    func_0044ea90(&D_00629628, 0x3A);
    buf = (u8 *)(*jtbl_008873E8)(0x578, 0x40000);
    func_0043f9c8(buf, 0, 0x578);
    r = func_00451fc0(arg0, D_006290F0, 0xF, 0, 0, (s32 (*)(u8 *))func_0021f790,
                      (void (*)(u8 *))func_002214d0, buf);
    q = func_00452560(arg0);
    *(s32 *)(buf + 4) = 0;
    *(u16 **)(buf + 0x570) = q;
    func_0043f9c8(buf + 8, 0, 0x30);
    *(void (**)(u8 *))(buf + 0x10) = func_0021fea0;
    *(u8 **)(buf + 0x18) = buf;
    return r;
}

// FUN_002216B0
void func_002216b0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    *temp_2 |= 1;
}

// FUN_002216E0
void func_002216e0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    if (temp_2[0] & 0x80) {
        func_0021dda0();
        *(s32 *)(temp_2 + 2) = 5;
        return;
    }
    *(s16 *)((u8 *)temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 2) = 6;
}

// FUN_00221740
u16 func_00221740(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    return temp_2[0] & 1;
}

/* measured: retail allocates p=$s0, t17/counter=$s1, loop store-addr=$s2 and
   computes the indexed store address before the call; mwcc b210 allocates
   p=$s1, t17/counter=$s0, keeps i*4 in $s2 across the call and re-derives the
   store address after it (nd 52, obj 364B vs window 368B). Tried: declaration
   orders of w/t17/i/v1, struct-only and pointer-arith spellings, loop-local
   store pointer, dsll32/dsra32 single-pair cast and boolean idioms (both
   fixed); the register rotation and pre-call store-address hoist are invariant
   under all of them. Register-coloring/scheduling floor. */
// FUN_00221770
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_00221770);
