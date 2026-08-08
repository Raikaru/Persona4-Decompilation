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
extern f32 D_008872F8[];
extern void (*D_00887300[])(u32, u32);
extern void (*D_00887310[])(s32, void*, s32);
extern u8 D_0064E290[];
extern u8 D_0064E2E0[];
extern u8* (*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void* ptr);

typedef struct { f32 x, y; } Vec2f;
typedef struct {
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2c[0xC];
    f32 f38;
    u8 pad3c[4];
    s32 c40;
    s32 c44;
    s32 c48;
    s32 c4C;
    u8 pad50[0x10];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad6c[0xC];
    f32 f78;
    u8 pad7c[4];
    s32 c80;
    s32 c84;
    s32 c88;
    s32 c8C;
    u8 pad90[0x10];
    f32 fA0;
    f32 fA4;
    f32 fA8;
    u8 padAC[0xC];
    f32 fB8;
    u8 padBC[4];
    s32 cC0;
    s32 cC4;
    s32 cC8;
    s32 cCC;
    u8 padD0[0x10];
    f32 fE0;
    f32 fE4;
    f32 fE8;
    u8 padEC[0xC];
    f32 fF8;
    u8 padFC[4];
    s32 c100;
    s32 c104;
    s32 c108;
    s32 c10C;
    u8 pad110[0x10];
} DrawPacket;
static inline f32 panelAdd(f32 left, f32 right) {
    return left + right;
}
static inline f32 panelMulForward(f32 left, f32 right) {
    return left * right;
}
static inline f32 panelMulReverse(f32 right, f32 left) {
    return right * left;
}

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


// FUN_00363080
void func_00363080(f32 fparg0, f32 fparg1, f32 fparg2) {
    DrawPacket packet;
    f32 z;
    f32 x;
    f32 y;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_mul;

    x = fparg0;
    y = fparg1;
    z = fparg2;
    temp_f20 = D_008872F8[0];
    temp_f6 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f4 = panelMulForward(41.0f, z);
    temp_f2 = panelAdd(x, temp_f4);
    temp_f4 = temp_f2;
    temp_f2 = panelAdd(3.0f, temp_f4);
    temp_f4 = temp_f2;
    packet.f20 = temp_f4;
    temp_mul = 1.0f - z;
    temp_f3 = temp_mul;
    temp_f3 = panelMulForward(20.0f, temp_f3);
    temp_f3 = panelAdd(y, temp_f3);
    packet.f24 = temp_f3;
    packet.f28 = temp_f20;
    packet.c40 = 0x41A80000;
    packet.c44 = 0x41E80000;
    packet.c48 = 0x42080000;
    packet.c4C = 0x437F0000;
    packet.f38 = temp_f6;
    temp_f2 = 3.0f + (41.0f + x);
    packet.f60 = temp_f2;
    packet.f64 = y;
    packet.f68 = temp_f20;
    packet.c80 = 0x41A80000;
    packet.c84 = 0x41E80000;
    packet.c88 = 0x42080000;
    packet.c8C = 0x437F0000;
    packet.f78 = temp_f6;
    packet.fA0 = temp_f4;
    packet.fA4 = 4.0f + temp_f3;
    packet.fA8 = temp_f20;
    packet.cC0 = 0x41A80000;
    packet.cC4 = 0x41E80000;
    packet.cC8 = 0x42080000;
    packet.cCC = 0x437F0000;
    packet.fB8 = temp_f6;
    packet.fE0 = temp_f2;
    packet.fE4 = 4.0f + y;
    packet.fE8 = temp_f20;
    packet.c100 = 0x41A80000;
    packet.c104 = 0x41E80000;
    packet.c108 = 0x42080000;
    packet.c10C = 0x437F0000;
    packet.fF8 = temp_f6;
    D_00887300[0](1, 0);
    D_00887310[0](4, &packet, 4);
}


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
