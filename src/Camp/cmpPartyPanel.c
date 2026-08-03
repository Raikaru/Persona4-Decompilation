/* Consolidated Persona 4 source units. */
/* Original translation unit cmpPartyPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

void func_0046d730(void* arg0, s32 arg1);
void func_0046b0d0(void* ptr);
void func_0044ea90(void* file, s32 line);
s32 func_00451fc0(s32 arg0, u8* name, s32 prio, s32 a3, s32 a4,
                  void (*init)(u8*), void (*close)(u8*), u8* work);
void func_0043f9c8(void* dest, s32 value, s32 size);
void func_00363540(u8* arg0, u8* arg1);
s32 func_00363610(u8* arg0);
void func_003640f0(u8* arg0);
s32 func_00362f00(u8* arg0);
void func_00363200(u8* arg0, s64 arg1);
void func_0034f1e0(void);
void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   f32 fparg0, f32 fparg1);
s32 func_00104ce0(s16 arg0);
s32 func_00104dc0(s16 arg0);
s32 func_00104d50(s16 arg0);
s32 func_00104e30(s16 arg0);
u8* func_00457120(void);
s16 func_00353b50(s16* dst);
s32 func_0046aea0(void* arg0);
void func_00442088(void* dst, void* src, s64 idx);
s32 func_0046a750(void* arg0);
void func_00460ac0(void* param, void* work);
extern u8 D_0064E2A0[];
extern u8 D_0064E2C0[];
extern u8 D_00794960[];
extern f32 D_008872F8;
extern void (*D_00887300[])(u32, u32);
extern void (*D_00887310[])(s32, void*, s32);
extern u8 D_0064E290[];
extern u8 D_0064E2E0[];
extern u8* (*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void* ptr);

typedef struct { f32 x, y; } Vec2f;

// FUN_00362FD0
void func_00362fd0(u8* arg0, f32* arg1, f32* arg2, s16 arg3) {
    if (arg1 == NULL) {
        *(Vec2f*)(arg0 + 0x00) = *(Vec2f*)(arg0 + 0x10);
    } else {
        *(Vec2f*)(arg0 + 0x00) = *(Vec2f*)(arg1);
    }
    if (arg2 == NULL) {
        func_0046d730(D_0064E290, 0x92);
    }
    *(Vec2f*)(arg0 + 0x08) = *(Vec2f*)(arg2);
    *(Vec2f*)(arg0 + 0x10) = *(Vec2f*)(arg0 + 0x00);
    *(s16*)(arg0 + 0x18) = 0;
    *(s16*)(arg0 + 0x1A) = arg3;
}


/* measured: retail (MW 2.4.1.01 per ELF .comment) computes the four
   primitive floats with plain mul.s/add.s; mwcc b210 always fuses
   a + b*c into mtc1 $zero + ADDA.s + MADD.s accumulator ops (nd 24+
   every attempt: -O1..-O4, -Op, locals, reordered trees). Toolchain
   FPU-fusion floor; repo verify uses b210. */
// FUN_00363080
INCLUDE_ASM("asm/nonmatchings/cmpPartyPanel", func_00363080);


/* measured: saved-GPR rotation floor. Retail allocates
   s0=idx, s1=arg0, s2=v18, s3=obj3, s4=obj2, s5=f20; b210 emits
   s0=obj3, s1=obj2, s2=f20, s3=idx, s4=arg0, s5=v18 in every
   spelling tried (p local, inline arg0+idx loads, f32 xy[2] spill
   array which b210 promotes back into FPRs), nd 140. Also b210 keeps
   px/py in saved FPRs where retail spills to sp88/sp8C. */
// FUN_00363200
INCLUDE_ASM("asm/nonmatchings/cmpPartyPanel", func_00363200);

// FUN_00363540
void func_00363540(u8* arg0, u8* arg1) {
    s32 i;
    s32 j;
    u8* p;

    for (i = 0; i < *(s16*)(arg1 + 0xA); i++) {
        p = arg1 + (s16)i * 0x28;
        if (*(s32*)(p + 0x30) != 0) {
            func_00362f00(p + 0x10);
        }
    }
    if (*(u16*)(arg1 + 0) & 1) {
        func_0034f1e0();
        for (j = 0; j < *(s16*)(arg1 + 0xA); j++) {
            func_00363200(arg1, (s64)(s16)j);
        }
    }
}


/* measured: mwcc b210 vs retail MW 2.4.1.01 codegen gaps (nd 583):
   (1) case 0 keeps obj+i*0x28 in $s3 for the p[0x2C] store where retail
   re-materializes sll/addu/sll/addu+addiu between the two calls (CSE);
   (2) case 3's readiness-scan loop: retail hoists the lh count before the
   loop, b210 sinks it per-iteration (load-sinking floor); (3) saved/scratch
   register rotations in the case 2/3/4/5 loops (n2/i2, v5, nw) plus
   s16-count extension placement at the n2==c2 compare. Structure, FPU
   ADDA/MSUB fusion (338.0f - 63.0f*x), stack layout (pos pairs, tbl,
   wbufs, cbuf) all match; only these allocation/scheduling residuals. */
// FUN_00363610
INCLUDE_ASM("asm/nonmatchings/cmpPartyPanel", func_00363610);


// FUN_003640F0
void func_003640f0(u8* arg0) {
    u8* obj = *(u8**)(arg0 + 0x38);
    s32 i;
    u8* p;
    u8* q;

    if (*(s32*)(obj + 0xC) != 0) {
        func_0046b0d0(*(void**)(obj + 0xC));
        *(s32*)(obj + 0xC) = 0;
    }
    for (i = 0; i < *(s16*)(obj + 0xA); i++) {
        p = obj + i * 0x28;
        q = p + 0x2C;
        if (*(s32*)(p + 0x2C) != 0) {
            func_0046b0d0(*(void**)(p + 0x2C));
            *(s32*)q = 0;
        }
    }
    (*jtbl_008873EC)(obj);
}


// FUN_003641A0
s32 func_003641a0(s32 arg0) {
    s32 r;
    u8* work;

    func_0044ea90(D_0064E290, 0x253);
    work = D_008873F4[0](1, 0xE0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064E290, 0x254);
    }
    r = func_00451fc0((s32)arg0, D_0064E2E0, 0xC7, 0, 0,
                      (void (*)(u8 *))func_00363610,
                      (void (*)(u8 *))func_003640f0, work);
    if (r == 0) {
        func_0046d730(D_0064E290, 0x25E);
    }
    *(s32 *)(work + 0x4) = 0;
    func_0043f9c8(work + 0xB0, 0, 0x30);
    *(u8 **)(work + 0xB8) = (u8 *)func_00363540;
    *(u8 **)(work + 0xC0) = work;
    return r;
}
