/* Consolidated Persona 4 source units. */
/* Original translation unit cmpPartyPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

void func_0046d730(void* arg0, s32 arg1);
void func_0046b0d0(void* ptr);
void func_0044ea90(void* file, s32 line);
s32 func_00451fc0(s32 arg0, const void* name, s32 prio, s32 a3, s32 a4,
                  void (*init)(u8*), void (*close)(u8*), u8* work);
void func_0043f9c8(void* dest, s32 value, s32 size);
void func_00363540(u8* arg0, u8* arg1);
s32 func_00363610(u8* arg0);
void func_003640f0(u8* arg0);
s32 func_00362f00(u8* arg0);
void func_00363200(u8* arg0, s64 arg1);
void func_0034f1e0(void);
void func_0034f460(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   u8 arg2, u8 arg3, u8 arg4, u32 arg5);
u32 func_00104ce0(s16 arg0);
u16 func_00104dc0(s16 arg0);
u32 func_00104d50(s16 arg0);
u16 func_00104e30(s16 arg0);
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
extern s32 (*D_00887310[])(s32, void*, s32);
extern u8 D_0064E290[];
extern u8 D_0064E2E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void* ptr);

typedef struct { f32 x, y; } Vec2f;
static inline u8 *panelSlot(u32 offset, u8 *base) {
    return (u8 *)(offset + (u32)base);
}
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


/* 820/832 bytes; sixteen resolved relocations and twelve zero alignment bytes.
 * The sprite API keeps coordinates before byte colors, as its core does.
 * Snapshot the row position and unsigned HP/SP values before drawing. */
// FUN_00363200
void func_00363200(u8* arg0, s64 arg1)
{
    s32 off = (s16)arg1 * 0x28;
    s16 id = *(s16*)((u8*)(off + (s32)arg0) + 0x34);
    s32 sprB = *(s32*)(arg0 + 0x0C);
    s32 sprA = *(s32*)((u8*)(off + (s32)arg0) + 0x2C);

    if (*(s32*)((u8*)(off + (s32)arg0) + 0x30) != 0) {
        Vec2f xy;
        f32 y;
        u32 hpCur;
        u32 hpMax;
        u32 spCur;
        u32 spMax;
        f32 ratio;
        f32 y35;
        f32 x13;
        f32 y39;

        if (sprB == 0) {
            func_0046d730(D_0064E290, 0x108);
        }
        if (sprA == 0) {
            func_0046d730(D_0064E290, 0x109);
        }
        xy = *(Vec2f*)(panelSlot(off, arg0) + 0x20);
        hpCur = func_00104ce0(id) & 0xFFFF;
        hpMax = func_00104dc0(id) & 0xFFFF;
        spCur = func_00104d50(id) & 0xFFFF;
        spMax = func_00104e30(id) & 0xFFFF;
        y = xy.y;
        func_0034f460(sprA, 0, xy.x, y, 0xFF, 0xFF, 0xFF, 0xFF);
        func_0034f460(sprB, 0, 8.0f + xy.x, 31.0f + y,
                      0xFF, 0xFF, 0xFF, 0xFF);
        ratio = (f32)hpCur / (f32)hpMax;
        y35 = 35.0f + y;
        x13 = 13.0f + xy.x;
        func_0034f460(sprB, 1, x13, y35, 0xFF, 0xFF, 0xFF, 0xFF);
        func_00363080(x13, y35, ratio);
        y39 = 39.0f + y;
        func_0034f460(sprB, 2, x13, y39, 0xFF, 0xFF, 0xFF, 0xFF);
        ratio = (f32)spCur / (f32)spMax;
        func_00363080(x13, y39, ratio);
    }
}

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


/* measured: probe 614 words, retail 692 vs object 677 instrs (15 short, 2.2% inside gate;
   fnalign 760 edits +14 reloc-only). Stack 0x3B0 matches via reverse decl order
   tbl,p4,p3,p2,p1,p0,wbuf,b2,b1,b0 giving 80,336,592,848,896,904,912,920,928,936;
   FPU ADDA/MSUB fusion via 338.0f-63.0f*(f32)((count-1)-i) with (f32)565 and 640.0f.
   Free pragmas: loopInv 618->614 (-4, kept), unrollOff/schedOff neutral,
   commonSubsOff 612->707 worse, propOff neutral. Subscript p vs recomputed neutral.
   Register swaps (i/ready etc.) neutral. s64 loops 612->643 worse. Prior nd583 gaps
   remain: case0 CSE recompute (5), count hoist, saved/scratch rotations, s16 ext,
   lwc1 vs lw, bnez vs beqz. m2c needs jtbl (fails); romwright+IDA/Ghidra used. */
// FUN_00363610 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
s32 func_00363610(u8* arg0)
{
    u8* obj = *(u8**)(arg0 + 0x38);
    s16 tbl[4];
    f32 p4[2];
    f32 p3[2];
    f32 p2[2];
    f32 p1[2];
    f32 p0[2];
    s32 wbuf[10];
    u8 b2[256];
    u8 b1[256];
    u8 b0[256];
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 c;
    s32 q;
    s16 id;
    s32 h;
    s32 ready;
    u8* p;
    u8* dst;
    u8* src;
    s32* d32;
    s32* s32p;
    s32* w;
    s32* w2;
    u8* e;
    s32 a;
    s32 b;

    *(s32*)(obj + 0xB0) = 0;
    *(s32*)(obj + 0xB4) = 0;
    func_00460ac0(D_00794960, obj + 0xB0);
    switch (*(s32*)(obj + 0x4)) {
    case 0:
        *(s32*)(obj + 0xC) = func_0046aea0(D_0064E2C0);
        *(s16*)(obj + 0xA) = func_00353b50(tbl);
        for (i = 0; i < *(s16*)(obj + 0xA); i++) {
            p4[0] = (f32)565;
            p4[1] = 338.0f - 63.0f * (f32)((*(s16*)(obj + 0xA) - 1) - i);
            id = tbl[i];
            func_00362fd0(obj + i * 0x28 + 0x10, p4, p4, 0);
            *(s16*)(obj + i * 0x28 + 0x34) = id;
            *(s32*)(obj + i * 0x28 + 0x30) = 0;
            if (id != 0) {
                func_00442088(b2, D_0064E2A0, (s64)id);
                h = func_0046aea0(b2);
                *(s32*)(obj + i * 0x28 + 0x2C) = h;
                if (h == 0) {
                    func_0046d730(D_0064E290, 0x166);
                }
            }
        }
        *(u16*)(obj + 0x0) |= 1;
        *(s32*)(obj + 0x4) = 1;
        break;
    case 1:
        if (func_0046a750(*(void**)(obj + 0xC)) == 0) {
            return 0;
        }
        *(s32*)(obj + 0x4) = 2;
        /* fallthrough */
    case 2:
        ready = 0;
        for (i = 0; i < *(s16*)(obj + 0xA); i++) {
            if (func_0046a750(*(void**)(obj + i * 0x28 + 0x2C)) != 0) {
                *(s32*)(obj + i * 0x28 + 0x30) = 1;
                ready++;
            }
        }
        if (ready == *(s16*)(obj + 0xA)) {
            *(s32*)(obj + 0x4) = 3;
            for (j = 0; j < *(s16*)(obj + 0xA); j++) {
                p3[0] = (f32)565;
                p3[1] = 338.0f - 63.0f * (f32)((*(s16*)(obj + 0xA) - 1) - j);
                func_00362fd0(obj + j * 0x28 + 0x10, NULL, p3, 8);
            }
        }
        break;
    case 3:
        if ((*(u16*)(obj + 0x0) & 2) != 0) {
            *(s32*)(obj + 0x4) = 6;
            break;
        }
        for (i = 0; i < *(s16*)(obj + 0xA); i++) {
            if (*(s16*)(obj + i * 0x28 + 0x28) < *(s16*)(obj + i * 0x28 + 0x2A)) {
                return 0;
            }
        }
        c = func_00353b50(tbl);
        if (*(s16*)(obj + 0xA) == c) {
            for (m = 0; m < c && *(s16*)(obj + m * 0x28 + 0x34) == tbl[m]; m++) {
            }
            if (m < c) {
                p = obj + m * 0x28;
                p4[0] = 640.0f;
                p4[1] = 338.0f - 63.0f * (f32)((*(s16*)(obj + 0xA) - 1) - m);
                *(f32*)(p + 0x10) = *(f32*)(p + 0x20);
                *(f32*)(p + 0x14) = *(f32*)(p + 0x24);
                *(f32*)(p + 0x18) = p4[0];
                *(f32*)(p + 0x1C) = p4[1];
                *(f32*)(p + 0x20) = *(f32*)(p + 0x10);
                *(f32*)(p + 0x24) = *(f32*)(p + 0x14);
                *(s16*)(p + 0x28) = 0;
                *(s16*)(p + 0x2A) = 8;
                *(s16*)(obj + 0x8) = (s16)m;
                *(s32*)(obj + 0x4) = 5;
            }
        } else if (c < *(s16*)(obj + 0xA)) {
            for (n = 0; n < 4 && *(s16*)(obj + n * 0x28 + 0x34) == tbl[n]; n++) {
            }
            p = obj + n * 0x28;
            p4[0] = 640.0f;
            p4[1] = 338.0f - 63.0f * (f32)((*(s16*)(obj + 0xA) - 1) - n);
            *(f32*)(p + 0x10) = *(f32*)(p + 0x20);
            *(f32*)(p + 0x14) = *(f32*)(p + 0x24);
            *(f32*)(p + 0x18) = p4[0];
            *(f32*)(p + 0x1C) = p4[1];
            *(f32*)(p + 0x20) = *(f32*)(p + 0x10);
            *(f32*)(p + 0x24) = *(f32*)(p + 0x14);
            *(s16*)(p + 0x28) = 0;
            *(s16*)(p + 0x2A) = 8;
            *(s16*)(obj + 0x8) = (s16)n;
            *(s32*)(obj + 0x4) = 4;
        } else {
            for (m = 0; m < 4 && *(s16*)(obj + m * 0x28 + 0x34) == tbl[m]; m++) {
            }
            k = *(s16*)(obj + 0xA);
            while (m < k) {
                dst = obj + k * 0x28 + 0x10;
                src = obj + k * 0x28 - 0x18;
                d32 = (s32*)dst;
                s32p = (s32*)src;
                q = 5;
                do {
                    s32 a = s32p[0];
                    s32 b = s32p[1];
                    s32p += 2;
                    q--;
                    d32[0] = a;
                    d32[1] = b;
                    d32 += 2;
                } while (q > 0);
                k--;
            }
            *(s16*)(obj + 0xA) += 1;
            p4[0] = 640.0f;
            p4[1] = 338.0f - 63.0f * (f32)((*(s16*)(obj + 0xA) - 1) - m);
            id = tbl[m];
            func_00362fd0(obj + m * 0x28 + 0x10, p4, p4, 0);
            *(s16*)(obj + m * 0x28 + 0x34) = id;
            *(s32*)(obj + m * 0x28 + 0x30) = 0;
            if (id != 0) {
                func_00442088(b1, D_0064E2A0, (s64)id);
                h = func_0046aea0(b1);
                *(s32*)(obj + m * 0x28 + 0x2C) = h;
                if (h == 0) {
                    func_0046d730(D_0064E290, 0x166);
                }
            }
            *(s32*)(obj + 0x4) = 2;
        }
        break;
    case 4: {
        e = obj + *(s16*)(obj + 0x8) * 0x28;
        if (*(s16*)(e + 0x2A) <= *(s16*)(e + 0x28)) {
            d32 = (s32*)(e + 0x10);
            w = wbuf;
            q = 5;
            do {
                a = d32[0];
                b = d32[1];
                d32 += 2;
                q--;
                w[0] = a;
                w[1] = b;
                w += 2;
            } while (q > 0);
            *(s16*)(obj + 0xA) -= 1;
            for (k = *(s16*)(obj + 0x8); k < *(s16*)(obj + 0xA); k++) {
                dst = obj + k * 0x28 + 0x10;
                src = obj + k * 0x28 + 0x38;
                d32 = (s32*)dst;
                s32p = (s32*)src;
                q = 5;
                do {
                    s32 a = s32p[0];
                    s32 b = s32p[1];
                    s32p += 2;
                    q--;
                    d32[0] = a;
                    d32[1] = b;
                    d32 += 2;
                } while (q > 0);
            }
            dst = obj + k * 0x28 + 0x10;
            w2 = wbuf;
            d32 = (s32*)dst;
            q = 5;
            do {
                a = w2[0];
                b = w2[1];
                w2 += 2;
                q--;
                d32[0] = a;
                d32[1] = b;
                d32 += 2;
            } while (q > 0);
            *(s16*)(obj + k * 0x28 + 0x34) = 0;
            *(s32*)(obj + k * 0x28 + 0x30) = 0;
            if (*(s32*)(obj + k * 0x28 + 0x2C) != 0) {
                func_0046b0d0(*(void**)(obj + k * 0x28 + 0x2C));
                *(s32*)(obj + k * 0x28 + 0x2C) = 0;
            }
            p2[0] = *(f32*)(obj + k * 0x28 + 0x20);
            p2[1] = *(f32*)(obj + k * 0x28 + 0x24);
            func_00362fd0(obj + k * 0x28 + 0x10, p2, p2, 0);
            for (i = 0; i < *(s16*)(obj + 0xA); i++) {
                p1[0] = (f32)565;
                p1[1] = 338.0f - 63.0f * (f32)((*(s16*)(obj + 0xA) - 1) - i);
                func_00362fd0(obj + i * 0x28 + 0x10, NULL, p1, 8);
            }
            *(s32*)(obj + 0x4) = 3;
        }
        break;
    }
    case 5: {
        e = obj + *(s16*)(obj + 0x8) * 0x28;
        if (*(s16*)(e + 0x2A) <= *(s16*)(e + 0x28)) {
            (void)func_00353b50(tbl);
            p = obj + *(s16*)(obj + 0x8) * 0x28;
            *(s16*)(p + 0x34) = 0;
            *(s32*)(p + 0x30) = 0;
            if (*(s32*)(p + 0x2C) != 0) {
                func_0046b0d0(*(void**)(p + 0x2C));
                *(s32*)(p + 0x2C) = 0;
            }
            p0[0] = *(f32*)(p + 0x20);
            p0[1] = *(f32*)(p + 0x24);
            func_00362fd0(p + 0x10, p0, p0, 0);
            n = *(s16*)(obj + 0x8);
            p4[0] = 640.0f;
            p4[1] = 338.0f - 63.0f * (f32)((*(s16*)(obj + 0xA) - 1) - n);
            id = tbl[n];
            func_00362fd0(obj + n * 0x28 + 0x10, p4, p4, 0);
            *(s16*)(obj + n * 0x28 + 0x34) = id;
            *(s32*)(obj + n * 0x28 + 0x30) = 0;
            if (id != 0) {
                func_00442088(b0, D_0064E2A0, (s64)id);
                h = func_0046aea0(b0);
                *(s32*)(obj + n * 0x28 + 0x2C) = h;
                if (h == 0) {
                    func_0046d730(D_0064E290, 0x166);
                }
            }
            *(s32*)(obj + 0x4) = 2;
        }
        break;
    }
    case 6:
        return -1;
    default:
        break;
    }
    return 0;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/cmpPartyPanel", func_00363610);
#endif


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
