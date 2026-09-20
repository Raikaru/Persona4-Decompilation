/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

typedef struct RuntimeWork RuntimeWork;

typedef struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    void* vertices;
    void* renderObjects;
    u8 reserved[8];
    struct RuntimeListNode* previous;
    struct RuntimeListNode* next;
} RuntimeListNode;

extern void* D_00764C98;
extern s32 D_00922DB0[];
extern s32 D_00922DB4[];
extern void func_00460ac0(void* arg0, s32* arg1);
extern void* D_00764C9C;
extern RuntimeListNode* D_00764CA0;
extern void func_004baea0(void* arg0, void* arg1);
extern void func_004baed0(void* arg0, void* arg1);
extern void func_00440b68(const void* msg, const void* file, s32 line);
extern u8* func_00454a60(u8* param, s32 mode);
extern void func_00456150(void* handle);
extern s32 func_003ef740(u8* param, s32 mode);
extern void func_00454bd0(u8* ptr);

extern void func_0043f9c8(void* dst, s32 value, u32 size);
extern u8 D_00764210;
extern s32 D_00764CA4;
extern s32 D_00764CA8;
extern u8 D_007146B0[];
extern u8 D_007146C0[];
extern u8 D_007146D0[];
extern void* D_00922DB8[];
extern s32 D_00922DC0[];
extern void func_004b6e80(void);
extern s32 func_004b6e40(u8 *task);
extern void func_0046d730(const void* file, s32 line);
extern void func_003e9390(void* frame);
extern void func_003c02e0(void* arg);
extern void func_003c4220(void* arg);
extern void func_004b8f10(void* arg0);
extern void (*jtbl_008873EC[])(void* ptr);
extern void func_0044ea90(const void* file, s32 line);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void func_004b8df0(void* arg0, void* arg1);
extern s32 func_003c4140(void);
extern void func_003c42b0(void* a, void* b);
extern u8* func_004b8350(void* a, void* b);
extern s32 func_003c00e0(void);
extern void func_003c0210(void* a, void* b, s32 c);
extern s32 func_003e9320(void);
extern void func_003c1b90(void* a, void* b);
extern void func_003c2a80(void* a);
extern void func_004bccf0(void* a, void* b);
extern void func_003c22f0(void* a);

/* measured: floor for func_004b6030 (obj 2112B vs window 2256B, probe_variants 534 differing words reloc-masked, normalized_diff 1650).
   Frame 0x1B0 matches retail; prologue (addiu/sd/sq x6) matches for the first 32B, then saved-reg rotation diverges.
   Logic confirmed against retail asm (asm/nonmatchings/eff_afpack/func_004b6030.s via `grep -rl func_004b6030 asm/`),
   IDA sub_4B6030, Ghidra FUN_004b6030, and M2C P4_UNIT_004B6030 (327 draft lines, noise 6): 5 stack temp arrays
   (aTmp/cTmp1/cTmp2/bTmp1/bTmp2, 16 entries each = 0x40 gaps at sp+0x170/0x130/0xF0/0xB0/0x70), 3-phase bump walk
   from arg0+0x10 (0x38 / 8+4+0x10 / 0x20+extra vs 0x18+extra), size = 0x24+n8*0x18+nA*0x34+nC*0x18+n8*4+extras+n8*8,
   node layout +0xC(n8*0x18)/+0x10(nA*0x34)/+0x14(nC*0x18)/+0x1C(n8*4)/+0x18(n8*8) + header (+0/+4/+6/+8),
   A-copy 13 f32 with 0x24/0x20 shuffle, C-copy id+(id&1?D_00764CA8:0)+16B, final 0x18 records with A/C index
   searches and kind-split fields (0x10: u16 vs 0 / 0x14: f32 vs 0x41200000) plus trailing 8B and func_0043f810.
   Sibling conventions read first: eff_afpack.c func_004b6900 (u8*+offsets, s16 counts, jtbl_008873E8 alloc,
   D_007146B0 asserts 0x1AE/0x1BA/0x1C8/0x1E4/0x22E) and eff_after.c EffAfterVec/f32 patterns.
   Residual is compiler floor per docs/matching.md: rotated saved regs (arg0/bump/counter in $s2/$s1/$v1 vs
   retail $s1/$s0/$a0 for the no-call first loop), scheduling of kind reloads vs single lw+2x beq, and FPU
   choice/byte-copy planning (lbu/sb x16 vs word). Exhausted separate-counter scoping (v6), f32 A-copy (v4),
   byte-wise C-copy with (k>>1)*8+(k&1)*4 addressing (v4), and if/else-if duplication (v3); v1 532 -> v2 521
   -> v3 520/2068B -> v4/v5/v6 534/2112B. Shortfall 144B (6.4%) is the merged identical kind branches
   (id/dst+8/dst+0xC/trailing emit once where retail keeps two lhu) and compact search-loop codegen.
   No pooled float constants to bank (noise 6 needs no lit pool: 10.0f is lui $4,0x4120 immediate 0x41200000,
   stored via sw, value 10.0f confirmed; single gp load lw -0x4448($28) is D_00764CA8 = 0x00764CA8
   = gp 0x007690F0-0x4448, already extern s32, initial 0 in orig/SLUS_217.82; D_007146B0 bytes are
   "eff_afpack.c" in SLUS_217.82). Banked per batch contract: production stays INCLUDE_ASM fallback;
   body preserved here as NON_MATCHING seed. Unit confirmed via `grep -rl func_004b6030 asm/`
   -> asm/nonmatchings/eff_afpack/func_004b6030.s. */
/* measured 004b6030: `opt_common_subs off` inside the guard is worth 6 words (534 -> 528); retail rematerialises what b210 hoists. */
// FUN_004B6030 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
u8* func_004b6030(u8* arg0)
{
    extern void func_0043f810(void* dst, void* src, u32 size);
    u8* aTmp[16];
    u8* cTmp1[16];
    u8* cTmp2[16];
    u8* bTmp1[16];
    u8* bTmp2[16];
    u8* p;
    p = arg0 + 0x10;
    {
        s32 i0;
        for (i0 = 0; i0 < (s32)*(u16*)(arg0 + 0xA); i0++) {
            aTmp[i0] = p;
            p += 0x38;
        }
    }
    {
        s32 i1;
        for (i1 = 0; i1 < (s32)*(u16*)(arg0 + 0xC); i1++) {
            u8* cur;
            cTmp1[i1] = p;
            p += 8;
            cur = cTmp1[i1];
            if (*(u16*)(cur + 4) != 0) {
                func_0046d730(D_007146B0, 0x1AE);
            } else {
                p += 4;
            }
            cTmp2[i1] = p;
            if (*(u16*)(cur + 6) != 0) {
                func_0046d730(D_007146B0, 0x1BA);
            } else {
                p += 0x10;
            }
        }
    }
    {
        s32 i2;
        for (i2 = 0; i2 < (s32)*(u16*)(arg0 + 8); i2++) {
            bTmp1[i2] = p;
            if (*(s32*)arg0 == 0x65) {
                p += 0x20;
            } else if (*(s32*)arg0 == 0x64) {
                p += 0x18;
            } else {
                func_0046d730(D_007146B0, 0x1C8);
            }
            bTmp2[i2] = p;
            if (*(s32*)arg0 == 0x65) {
                p += *(s32*)(bTmp1[i2] + 0x1C);
            } else if (*(s32*)arg0 == 0x64) {
                p += *(s32*)(bTmp1[i2] + 0x14);
            }
        }
    }
    {
        s32 size;
        u8* node;
        u8* base;
        size = 0x24 + (s32)*(u16*)(arg0 + 8) * 0x18 + (s32)*(u16*)(arg0 + 0xA) * 0x34 + (s32)*(u16*)(arg0 + 0xC) * 0x18 + (s32)*(u16*)(arg0 + 8) * 4;
        {
            s32 i3;
            for (i3 = 0; i3 < (s32)*(u16*)(arg0 + 8); i3++) {
                if (*(s32*)arg0 == 0x65) {
                    size += *(s32*)(bTmp1[i3] + 0x1C);
                } else if (*(s32*)arg0 == 0x64) {
                    size += *(s32*)(bTmp1[i3] + 0x14);
                }
            }
        }
        size += (s32)*(u16*)(arg0 + 8) * 8;
        func_0044ea90(D_007146B0, 0x1E4);
        node = (u8*)(*jtbl_008873E8)(size, 0x40000);
        base = node + 0x24;
        *(u8**)(node + 0xC) = base;
        base += (s32)*(u16*)(arg0 + 8) * 0x18;
        *(u8**)(node + 0x10) = base;
        base += (s32)*(u16*)(arg0 + 0xA) * 0x34;
        *(u8**)(node + 0x14) = base;
        base += (s32)*(u16*)(arg0 + 0xC) * 0x18;
        *(u8**)(node + 0x1C) = base;
        base += (s32)*(u16*)(arg0 + 8) * 4;
        {
            s32 i4;
            for (i4 = 0; i4 < (s32)*(u16*)(arg0 + 8); i4++) {
                *(u8**)(*(u8**)(node + 0x1C) + i4 * 4) = base;
                if (*(s32*)arg0 == 0x65) {
                    base += *(s32*)(bTmp1[i4] + 0x1C);
                } else if (*(s32*)arg0 == 0x64) {
                    base += *(s32*)(bTmp1[i4] + 0x14);
                }
            }
        }
        *(u8**)(node + 0x18) = base;
        *(s32*)(node + 0) = *(s32*)(arg0 + 4);
        *(u16*)(node + 4) = *(u16*)(arg0 + 8);
        *(u16*)(node + 6) = *(u16*)(arg0 + 0xA);
        *(u16*)(node + 8) = *(u16*)(arg0 + 0xC);
        {
            s32 i5;
            for (i5 = 0; i5 < (s32)*(u16*)(arg0 + 0xA); i5++) {
                u8* dst = *(u8**)(node + 0x10) + i5 * 0x34;
                u8* src = aTmp[i5];
                *(f32*)(dst + 0) = *(f32*)(src + 4);
                *(f32*)(dst + 4) = *(f32*)(src + 8);
                *(f32*)(dst + 8) = *(f32*)(src + 0xC);
                *(f32*)(dst + 0xC) = *(f32*)(src + 0x10);
                *(f32*)(dst + 0x10) = *(f32*)(src + 0x14);
                *(f32*)(dst + 0x14) = *(f32*)(src + 0x18);
                *(f32*)(dst + 0x18) = *(f32*)(src + 0x1C);
                *(f32*)(dst + 0x1C) = *(f32*)(src + 0x20);
                *(f32*)(dst + 0x24) = *(f32*)(src + 0x24);
                *(f32*)(dst + 0x20) = *(f32*)(src + 0x28);
                *(f32*)(dst + 0x28) = *(f32*)(src + 0x2C);
                *(f32*)(dst + 0x2C) = *(f32*)(src + 0x30);
                *(f32*)(dst + 0x30) = *(f32*)(src + 0x34);
            }
        }
        {
            s32 i6;
            for (i6 = 0; i6 < (s32)*(u16*)(arg0 + 0xC); i6++) {
                u8* dst = *(u8**)(node + 0x14) + i6 * 0x18;
                u8* src = cTmp1[i6];
                u16 id = *(u16*)(src + 2);
                s32 k;
                *(s32*)dst = (s32)id;
                if ((id & 1) != 0) {
                    *(s32*)(dst + 4) = D_00764CA8;
                } else {
                    *(s32*)(dst + 4) = 0;
                }
                if (*(u16*)(src + 6) != 0) {
                    func_0046d730(D_007146B0, 0x22E);
                } else {
                    u8* s2 = cTmp2[i6];
                    for (k = 0; k < 4; k++) {
                        u8* d = dst + 8 + (k >> 1) * 8 + (k & 1) * 4;
                        u8* s = s2 + k * 4;
                        *(u8*)(d + 0) = *(u8*)(s + 0);
                        *(u8*)(d + 1) = *(u8*)(s + 1);
                        *(u8*)(d + 2) = *(u8*)(s + 2);
                        *(u8*)(d + 3) = *(u8*)(s + 3);
                    }
                }
            }
        }
        {
            s32 i7;
            for (i7 = 0; i7 < (s32)*(u16*)(arg0 + 8); i7++) {
                u8* dst = *(u8**)(node + 0xC) + i7 * 0x18;
                u8* src = bTmp1[i7];
                u16 id;
                s32 ai;
                s32 ci;
                if (*(s32*)arg0 == 0x65) {
                    id = *(u16*)(src + 2);
                } else if (*(s32*)arg0 == 0x64) {
                    id = *(u16*)(src + 2);
                }
                ai = 0;
                while (ai < (s32)*(u16*)(arg0 + 0xA) && id != *(u16*)aTmp[ai]) {
                    ai++;
                }
                *(u8**)(dst + 0) = *(u8**)(node + 0x10) + ai * 0x34;
                if (*(s32*)arg0 == 0x65) {
                    id = *(u16*)(src + 4);
                } else if (*(s32*)arg0 == 0x64) {
                    id = *(u16*)(src + 4);
                }
                ci = 0;
                while (ci < (s32)*(u16*)(arg0 + 0xC) && id != *(u16*)cTmp1[ci]) {
                    ci++;
                }
                *(u8**)(dst + 4) = *(u8**)(node + 0x14) + ci * 0x18;
                if (*(s32*)arg0 == 0x65) {
                    *(s32*)(dst + 8) = (s32)*(u16*)(src + 0x10);
                } else if (*(s32*)arg0 == 0x64) {
                    *(s32*)(dst + 8) = (s32)*(u16*)(src + 0x10);
                }
                if (*(s32*)arg0 == 0x65) {
                    *(s32*)(dst + 0xC) = (s32)*(u16*)(src + 0x12);
                } else if (*(s32*)arg0 == 0x64) {
                    *(s32*)(dst + 0xC) = (s32)*(u16*)(src + 0x12);
                }
                if (*(s32*)arg0 == 0x65) {
                    *(s32*)(dst + 0x10) = (s32)*(u16*)(src + 0x14);
                } else if (*(s32*)arg0 == 0x64) {
                    *(s32*)(dst + 0x10) = 0;
                }
                if (*(s32*)arg0 == 0x65) {
                    *(f32*)(dst + 0x14) = *(f32*)(src + 0x18);
                } else if (*(s32*)arg0 == 0x64) {
                    *(s32*)(dst + 0x14) = 0x41200000;
                }
                if (*(s32*)arg0 == 0x65) {
                    *(s32*)(*(u8**)(node + 0x18) + i7 * 8) = *(s32*)(src + 8);
                    *(s32*)(*(u8**)(node + 0x18) + i7 * 8 + 4) = *(s32*)(src + 0xC);
                } else if (*(s32*)arg0 == 0x64) {
                    *(s32*)(*(u8**)(node + 0x18) + i7 * 8) = *(s32*)(src + 8);
                    *(s32*)(*(u8**)(node + 0x18) + i7 * 8 + 4) = *(s32*)(src + 0xC);
                }
                if (*(s32*)arg0 == 0x65) {
                    func_0043f810(*(u8**)(*(u8**)(node + 0x1C) + i7 * 4), bTmp2[i7], *(s32*)(src + 0x1C));
                } else if (*(s32*)arg0 == 0x64) {
                    func_0043f810(*(u8**)(*(u8**)(node + 0x1C) + i7 * 4), bTmp2[i7], *(s32*)(src + 0x14));
                }
            }
        }
        return node;
    }
}


#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6030);
#endif
// FUN_004B6900
u8* func_004b6900(u8* arg0)
{
    u8* node;
    u8* base;
    u8* temp;
    s32 i;
    s32 size;
    typedef struct
    {
        u8 c[4];
    } Color4;
    Color4 color;

    size = 0;
    size += 0x24;
    size += *(s16*)(arg0 + 4) * 0x3C;
    size += *(s16*)(arg0 + 4) * 8;
    size += *(s16*)(arg0 + 4) * 0x20;
    size += *(s16*)(arg0 + 4) * 0x18;
    func_0044ea90(D_007146B0, 0x287);
    node = (u8*)(*jtbl_008873E8)(size, 0x40000);
    base = node + 0x24;
    *(u8**)(node + 8) = base;
    base += *(s16*)(arg0 + 4) * 0x3C;
    *(u8**)(node + 0xC) = base;
    base += *(s16*)(arg0 + 4) * 8;
    *(u8**)(node + 0x10) = base;
    base += *(s16*)(arg0 + 4) * 0x20;
    *(u8**)(node + 0x14) = base;
    *(s32*)node = 0;
    *(u8**)(node + 4) = arg0;
    node[0x20] = 0xFF;
    node[0x21] = 0xFF;
    node[0x22] = 0xFF;
    node[0x23] = 0xFE;

    i = 0;
    if (*(s16*)(arg0 + 4) > 0)
    {
        color.c[0] = 0xFF;
        color.c[1] = 0xFF;
        color.c[2] = 0xFF;
        color.c[3] = 0xFE;
        while (i < *(s16*)(arg0 + 4))
        {
            func_004b8df0(*(u8**)(node + 8) + i * 0x3C,
                          *(u8**)(arg0 + 0xC) + i * 0x18);
            *(s32*)(*(u8**)(node + 0xC) + i * 8 + 4) = func_003c4140();
            {
                u8* obj;
                u8* material;
                obj = *(u8**)(*(u8**)(node + 8) + i * 0x3C);
                material = *(u8**)(obj + 4);
                if ((*(s32*)material & 1) != 0)
                {
                    func_003c42b0(*(u8**)(*(u8**)(node + 0xC) + i * 8 + 4),
                                  *(u8**)(material + 4));
                }
            }
            *(Color4*)(*(u8**)(*(u8**)(node + 0xC) + i * 8 + 4) + 4) = color;
            temp = func_004b8350(*(u8**)(node + 8) + i * 0x3C,
                                 *(u8**)(*(u8**)(node + 0xC) + i * 8 + 4));
            *(s32*)(*(u8**)(node + 0xC) + i * 8) = func_003c00e0();
            func_003c0210(*(u8**)(*(u8**)(node + 0xC) + i * 8), temp, 0);
            func_003c1b90(*(u8**)(*(u8**)(node + 0xC) + i * 8),
                          (void*)func_003e9320());
            func_003c2a80(temp);
            func_004bccf0(*(u8**)(node + 8) + i * 0x3C, temp);
            func_003c22f0(temp);
            i++;
        }
    }
    return node;
}

// FUN_004B6BB0
void func_004b6bb0(RuntimeListNode* node)
{
    s32 i;
    s32 sp3C;
    s32 off;
    u8* work;
    u8* out;

    i = 0;
    while (i < *(s16*)((u8*)node->work + 4))
    {
        work = (u8*)node->work;
        out = *(u8**)((u8*)node + 0x10) + i * 0x20;
        *(s32*)(out + 8) = *(s32*)(*(s32**)(work + 0x1C) + i);
        off = i * 0x3C;
        *(s32*)(out + 0x10) = (s32)((u8*)node->vertices + off);
        func_004baea0(out, work);
        i++;
    }
    node->flags |= 1;
    i = 0;
    while (i < *(s16*)((u8*)node->work + 4))
    {
        func_004baed0(*(u8**)((u8*)node + 0x10) + i * 0x20, &sp3C);
        i++;
    }
}

// FUN_004B6C90
void func_004b6c90(s32 arg0, s32 arg1)
{
    s32 temp_2;

    func_00440b68(&D_00764210, D_007146B0, 0x2DA);
    temp_2 = (s32)func_00454a60(D_007146C0, 0);
    func_00456150((void*)temp_2);
    D_00764CA8 = (s32)func_003ef740(D_007146C0, 0);
    func_00454bd0((u8*)temp_2);
    D_00764CA0 = NULL;
    D_00764C9C = NULL;
    D_00764CA4 = (s32)func_00451de0((const void *)(D_007146D0), arg1, 0, 0, func_004b6e40, 0, (u8 *)(NULL));
    func_0043f9c8(D_00922DB0, 0, 0x30);
    D_00922DB8[0] = (void*)func_004b6e80;
    D_00922DC0[0] = 0;
    D_00764C98 = (void*)arg0;
}

// FUN_004B6DE0
s32 func_004b6de0(RuntimeListNode* node)
{
    RuntimeListNode* current;

    current = D_00764CA0;
    while (current != NULL)
    {
        if (current == node)
        {
            break;
        }
        current = *(RuntimeListNode**)((u8*)current + 0x1c);
    }
    if (current == NULL)
    {
        return 0;
    }
    return !(node->flags & 8);
}

// FUN_004B6DA0
void func_004b6da0(void* node)
{
    if (D_00764C9C == NULL)
    {
        *(void**)((u8*)node + 0x18) = NULL;
        *(void**)((u8*)node + 0x1c) = NULL;
        D_00764CA0 = (RuntimeListNode*)node;
        D_00764C9C = node;
        return;
    }
    else
    {
        *(void**)((u8*)node + 0x18) = D_00764C9C;
        *(void**)((u8*)node + 0x1c) = NULL;
        *(void**)((u8*)D_00764C9C + 0x1c) = node;
    }
    D_00764C9C = node;
}
// FUN_004B6E40
s32 func_004b6e40(u8 *unusedTask)
{
    D_00922DB0[0] = 0;
    D_00922DB4[0] = 0;
    func_00460ac0(D_00764C98, D_00922DB0);
    return 0;
}

// FUN_004B6E80
void func_004b6e80(void) {
    typedef int (*code)();
    extern code DAT_008873ec_abs[];
    void *(**table);
    extern void func_004b5950(void *arg0);
    extern void func_004b5c60(void *arg0);
    extern s32 func_004bce30(void *arg0);
    s32 flags;
    u8 *first;
    u8 *prev;
    u8 *next;
    s32 off;
    u8 *temp;
    s32 bits;
    u8 *work;
    s32 i;
    u8 *node;

    first = (u8 *)D_00764CA0;
    if (first != NULL) {
        while (first != NULL) {
            flags = *(s32 *)(first + 0);
            if (flags & 8) {
                func_004b5950(first);
            } else if (flags & 2) {
                func_004b5950(first);
                *(s32 *)(first + 0) = *(s32 *)(first + 0) & ~2;
            }
            first = *(u8 **)(first + 0x1C);
        }
        node = (u8 *)D_00764CA0;
        while (node != NULL) {
            temp = node;
            node = *(u8 **)(node + 0x1C);
            bits = 0;
            i = 0;
            while (i < *(s16 *)(*(u8 **)(temp + 4) + 4)) {
                bits |= func_004bce30(*(u8 **)(temp + 0x10) + (i << 5));
                i++;
            }
            if (bits == 0) {
                if (D_00764CA0 == NULL) {
                    func_0046d730(D_007146B0, 0x326);
                }
                if (D_00764C9C == NULL) {
                    func_0046d730(D_007146B0, 0x327);
                }
                next = *(u8 **)(temp + 0x1C);
                if (next != NULL) {
                    *(u8 **)(next + 0x18) = *(u8 **)(temp + 0x18);
                }
                prev = *(u8 **)(temp + 0x18);
                if (prev != NULL) {
                    *(u8 **)(prev + 0x1C) = *(u8 **)(temp + 0x1C);
                }
                if (temp == (u8 *)D_00764C9C) {
                    D_00764C9C = *(u8 **)(temp + 0x18);
                }
                if (temp == (u8 *)D_00764CA0) {
                    D_00764CA0 = (RuntimeListNode *)*(u8 **)(temp + 0x1C);
                }
                work = *(u8 **)(temp + 4);
                i = 0;
                while (i < *(s16 *)(*(u8 **)(temp + 4) + 4)) {
                    func_004b8f10(*(u8 **)(temp + 8) + i * 0x3C);
                    off = i * 8;
                    func_003e9390(*(u8 **)(*(u8 **)(*(u8 **)(temp + 0xC) + off) + 4));
                    func_003c02e0(*(u8 **)(*(u8 **)(temp + 0xC) + off));
                    func_003c4220(*(u8 **)(*(u8 **)(temp + 0xC) + off + 4));
                    i++;
                }
                table = (void *(**) )DAT_008873ec_abs;
                ((code)table[0])(temp);
                ((code)table[0])(work);
            }
        }
        first = (u8 *)D_00764CA0;
        while (first != NULL) {
            flags = *(s32 *)(first + 0);
            if (flags & 8) {
                func_004b5c60(first);
            } else if (flags & 4) {
                func_004b5c60(first);
                *(s32 *)(first + 0) = *(s32 *)(first + 0) & ~4;
            }
            first = *(u8 **)(first + 0x1C);
        }
    }
}

// FUN_004B7140
void func_004b7140(s32 arg0)
{
    s32 temp_16;
    u8* var_19;
    u8* temp_18;
    u8* temp_21;
    u8* temp_3;
    u8* temp_3_2;
    s32 var_17;
    u32 base;

    var_19 = (u8*)D_00764CA0;
    while (var_19 != NULL)
    {
        temp_18 = var_19;
        var_19 = *(u8**)(var_19 + 0x1C);
        if (*(s32*)(*(u8**)(temp_18 + 4) + 0x20) == arg0)
        {
            if (D_00764CA0 == NULL)
            {
                func_0046d730(D_007146B0, 0x326);
            }
            if (D_00764C9C == NULL)
            {
                func_0046d730(D_007146B0, 0x327);
            }
            temp_3 = *(u8**)(temp_18 + 0x1C);
            if (temp_3 != NULL)
            {
                *(u8**)(temp_3 + 0x18) = *(u8**)(temp_18 + 0x18);
            }
            temp_3_2 = *(u8**)(temp_18 + 0x18);
            if (temp_3_2 != NULL)
            {
                *(u8**)(temp_3_2 + 0x1C) = *(u8**)(temp_18 + 0x1C);
            }
            if (temp_18 == (u8*)D_00764C9C)
            {
                D_00764C9C = *(void**)(temp_18 + 0x18);
            }
            if (temp_18 == (u8*)D_00764CA0)
            {
                D_00764CA0 = *(RuntimeListNode**)(temp_18 + 0x1C);
            }
            temp_21 = *(u8**)(temp_18 + 4);
            var_17 = 0;
            while (var_17 < *(s16*)(*(u8**)(temp_18 + 4) + 4))
            {
                func_004b8f10(*(u8**)(temp_18 + 8) + var_17 * 0x3C);
                temp_16 = var_17 * 8;
                func_003e9390(*(void**)(*(u8**)(*(u8**)(temp_18 + 0xC) + temp_16) + 4));
                func_003c02e0(*(u8**)(*(u8**)(temp_18 + 0xC) + temp_16));
                func_003c4220(*(void**)(*(u8**)(temp_18 + 0xC) + temp_16 + 4));
                var_17++;
            }
            base = (u32)jtbl_008873EC;
            ((void (*)(void*))*(u32*)base)(temp_18);
            ((void (*)(void*))*(u32*)base)(temp_21);
        }
    }
}

