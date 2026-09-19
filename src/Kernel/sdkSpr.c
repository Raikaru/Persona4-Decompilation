/* Original translation unit sdkSpr.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

void func_0044ea90(void *arg0, s32 arg1);
void func_00442830(void *arg0, const char *arg1);
void func_00440b68(char *arg0, const char *arg1, s32 arg2);
void func_0043f810(void *arg0, void *arg1, s32 arg2);
void func_00454bd0(u8 *ptr);
s32 func_004553c0(u8 *ptr);
u8 *func_00455f70(void *arg0, u32 *arg1);
u8 *func_00454a60(void *arg0, s32 arg1);
void func_003ec330(void *ptr);
s32 func_004667d0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
void func_0046b380(u8 *arg0, s32 arg1);

/* Sprite dispatcher slot at 0x008873EC (absolute, outside gp window). */
extern void (*jtbl_008873EC[])(void *node);
/* Allocator slot at 0x008873F4 (absolute, outside gp window). */
extern void *(*D_008873F4[])(size_t, size_t, u32);
/* GP-relative list head at gp -0x44E8 (absolute 0x00764C08). */
extern u8 *iGpffffbb18;
/* GP-relative global at gp -0x4FC8 (absolute 0x00764128). */
extern char iGpffffb038;
extern char D_007130C8[];

static inline u32 sdkAddOffset(u32 offset, u32 base) { return offset + base; }

// FUN_0046AB90
void func_0046ab90(u8 *arg0)
{
    u8 temp[8];
    u8 temp2[8];
    s32 i;
    s32 complete;
    s16 state;

    state = *(s16 *)arg0;
    switch (state) {
    case 0:
        func_00440b68(&iGpffffb038, D_007130C8, 0xB3);
        *(u32 *)(arg0 + 0x208) = (u32)func_00454a60(arg0 + 2, 0);
        *(s16 *)arg0 = 1;
        break;
    case 1:
        if (*(u32 *)(arg0 + 0x208) != 0) {
            if (func_004553c0((u8 *)*(u32 *)(arg0 + 0x208)) != 1) {
                break;
            }
            *(u32 *)(arg0 + 0x20C) =
                *(u32 *)(*(u8 **)(arg0 + 0x208) + 0x110);
        }
        func_0043f810(arg0 + 0x218, (void *)*(u32 *)(arg0 + 0x20C), 0x20);
        *(u32 *)(arg0 + 0x210) += 0x20;
        *(s16 *)arg0 = 2;
        *(s16 *)(arg0 + 0x214) = 0;
        if (*(u16 *)(arg0 + 0x22C) == 0) {
            *(s16 *)arg0 = 4;
            break;
        }
    case 2:
        do {
            func_0043f810(temp, (void *)(*(u32 *)(arg0 + 0x20C) +
                                          *(u32 *)(arg0 + 0x210)), 8);
            *(u32 *)(arg0 + 0x210) += 8;
            *(u32 *)(arg0 + (*(s16 *)(arg0 + 0x214) << 2) + 0x184) =
                func_004667d0(9, 0, 0, 0, 0,
                              *(u32 *)(arg0 + 0x20C) + *(u32 *)(temp + 4),
                              0, 0, 0, 0);
            *(u32 *)(arg0 + (*(s16 *)(arg0 + 0x214) << 2) + 0x104) = 0;
            *(s16 *)(arg0 + 0x214) += 1;
        } while (*(u16 *)(arg0 + 0x22C) !=
                 *(s16 *)(arg0 + 0x214));
        *(s16 *)arg0 = 3;
        break;
    case 3:
        complete = 1;
        for (i = 0; i < *(u16 *)(arg0 + 0x22C); i++) {
            u8 *entry = arg0 + (i << 2);
            u32 *slot = (u32 *)(entry + 0x104);

            if (*slot == 0) {
                *slot = func_004669d0(*(u32 *)(entry + 0x184),
                                      &complete, 0);
                if (complete == 0) {
                    *slot = 0;
                    break;
                }
            }
        }
        if (complete == 0) {
            break;
        }
        *(s16 *)arg0 = 4;
    case 4:
        func_0044ea90(D_007130C8, 0xFD);
        *(u32 *)(arg0 + 0x204) =
            (u32)D_008873F4[0](*(u16 *)(arg0 + 0x22E), 0x80, 0x40000);
        for (i = 0; i < *(u16 *)(arg0 + 0x22E); i++) {
            func_0043f810(temp2, (void *)(*(u32 *)(arg0 + 0x20C) +
                                            *(u32 *)(arg0 + 0x210)), 8);
            *(u32 *)(arg0 + 0x210) += 8;
            func_0043f810((u8 *)(*(u32 *)(arg0 + 0x204) + (i << 7)),
                          (void *)(*(u32 *)(arg0 + 0x20C) + *(u32 *)(temp2 + 4)),
                          0x80);
        }
        if (*(u32 *)(arg0 + 0x208) != 0) {
            func_00454bd0((u8 *)*(u32 *)(arg0 + 0x208));
        }
        *(u32 *)(arg0 + 0x208) = 0;
        *(s16 *)(arg0 + 0x216) = *(u16 *)(arg0 + 0x22E);
        *(s16 *)arg0 = 5;
        break;
    case 5:
        break;
    }
}

// FUN_0046AEA0
u8 *func_0046aea0(const char *name)
{
    u8 *node;
    u8 *last;

    func_0044ea90(D_007130C8, 0x115);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 0;
    func_00442830(node + 2, name);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
    return node;
}

// FUN_0046AF60
void func_0046af60(u32 arg0)
{
    u8 *node;
    u8 *last;

    func_0044ea90(D_007130C8, 0x12D);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 1;
    *(u32 *)(node + 0x20C) = arg0;
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
}

// FUN_0046B000
u8 *func_0046b000(const char *name)
{
    u8 *node;
    u8 *last;
    u32 out;

    func_0044ea90(D_007130C8, 0x146);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 1;
    func_00442830(node + 2, name);
    *(u32 *)(node + 0x20C) = (u32)func_00455f70((void *)name, &out);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
    return node;
}

// FUN_0046B0D0
void func_0046b0d0(u8 *node)
{
    s32 i;

    if (*(u8 **)(node + 0x23C) == NULL) {
        if (*(u8 **)(node + 0x238) == NULL) {
            iGpffffbb18 = NULL;
        } else {
            iGpffffbb18 = *(u8 **)(node + 0x238);
            *(u8 **)(iGpffffbb18 + 0x23C) = NULL;
            *(u8 **)(*(u8 **)(node + 0x238) + 0x23C) = NULL;
        }
    } else {
        *(u8 **)(*(u8 **)(node + 0x23C) + 0x238) = *(u8 **)(node + 0x238);
        if (*(u8 **)(node + 0x238) != NULL) {
            *(u8 **)(*(u8 **)(node + 0x238) + 0x23C) = *(u8 **)(node + 0x23C);
        }
    }
    i = 0;
    while (i < 0x20) {
        if (*(u32 *)(node + 0x104 + (i << 2)) != 0) {
            func_003ec330((void *)*(u32 *)(node + 0x104 + (i << 2)));
            *(u32 *)(node + 0x104 + (i << 2)) = 0;
        }
        i++;
    }
    if (*(u8 **)(node + 0x208) != NULL) {
        func_00454bd0(*(u8 **)(node + 0x208));
        *(u8 **)(node + 0x208) = NULL;
    }
    if (*(u32 *)(node + 0x204) != 0) {
        jtbl_008873EC[0]((void *)*(u32 *)(node + 0x204));
        *(u32 *)(node + 0x204) = 0;
    }
    jtbl_008873EC[0](node);
}

/* Ported from P3FES h_maestro.c func_001126b0 (blob+index scale variant).
   Donor struct fields map onto P4 offsets: output at 0x204, overrideX at 0x74,
   right/left at 0x5c/0x54. The `sdkAddOffset` inline carries the offset-first
   operand order retail emits (addu $v0,$a1,$a0). */
// FUN_0046B1F0
f32 func_0046b1f0(u8 *blob, u32 index)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;

    offset = index * 0x80;
    output = *(u8 **)(blob + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5c) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    return (f32)value;
}
// FUN_0046B260
f32 func_0046b260(u8 *param_1)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = param_1;

    offset = *(u32 *)(sample + 0x4) * 0x80;
    output = *(u8 **)(*(u8 **)(sample + 0x0) + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5c) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x20) != 0)
    {
        value = (s32)(((u32)value * *(u16 *)(sample + 0x20)) >> 12);
    }
    return (f32)value;
}
// FUN_0046B2F0
f32 func_0046b2f0(u8 *param_1)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = (u8 *)param_1;

    offset = *(u32 *)(sample + 0x4) * 0x80;
    output = *(u8 **)(*(u8 **)(sample + 0x0) + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x60) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x58);
    overrideBase = output + 0x76;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x22) != 0)
    {
        value = (s32)(((u32)value * *(u16 *)(sample + 0x22)) >> 12);
    }
    return (f32)value;
}
// measured: retail 1952 object 2007 delta 2.8% band 1893-2011 words 1926 edits 3276(+0 reloc) frame 0x240/0x260 jal 15+30/15+30 hole 396 lump 19 cmds: python3 tools/probe_variants.py src/Kernel/sdkSpr.c func_0046b380 --candidate CAND2=/tmp/cand2.c; python3 tools/fnalign.py src/Kernel/sdkSpr.c func_0046b380 --candidate /tmp/cand2.c --quiet
// measured: pure hole 396 retail[319:715] 0x0046B87C-0x0046BEAC head c.eq.s/bc1t + lui/mtc1 0x43B4/0xC334/0x4334 float-range + c.ole.s, tail srl/andi/or/mtc1/cvt/add/swc1 0x24/0x28 unsigned conversions + stores; second hole 125 retail[719:844] 0x0046BEBC-0x0046C0B0 continuation (swc1 0x28 + bltz); calls exact 15+30/15+30 both streams so stores/branches not missing calls; lump 19 insert [266:266] object[297:316]; conversion check retail 22 bltz/95 mtc1/96 cvt vs object 36/142/120 (+14/+47/+24 already over, adding unsigned would go 2018 over upper 2011, removing would go 1853 under -- leave floor alone)
// FUN_0046B380 NONMATCHING
#ifdef NON_MATCHING
void func_0046b380(u8 *arg0, s32 arg1) {
    extern u8 *func_00457120(void);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void *func_003e0f80(void);
    extern void *func_003e0680(void *mat, void *axis, s32 arg2, f32 fparg0, f32 fparg1);
    extern void func_003e42e0(void *dst, void *src, s32 n, void *mat);
    extern void func_003e0f40(void *mat);
    extern void func_0046a7f0(u8 *arg0, u8 *arg1);
    extern void (*D_00887300[])(u32 state, u32 value);
    extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    void (**tbl300)(u32 state, u32 value);
    s32 (**tbl310)(s32 arg0, void *arg1, s32 arg2);
    extern f32 D_008872F8[];
    extern u8 D_007130D8[];
    extern f32 fGpffff8084;
    extern f32 fGpffff8054;
    extern f32 fGpffff8058;
    extern f32 fGpffff805c;
    extern f32 fGpffff8060;
    extern f32 fGpffff81b0;
    extern f32 fGpffff81b4;
    extern f32 fGpffff81b8;
    extern f32 fGpffff81bc;
    extern f32 fGpffff81c0;
    extern f32 fGpffff81c4;
    extern f32 fGpffff81c8;
    extern f32 fGpffff81cc;
    u8 *parent;
    u8 *rec;
    s32 idx;
    s32 slotidx;
    u8 *slot;
    f32 scale;
    f32 uvA0, uvA4, uvA8, uvAC, uvB0, uvB4, uvB8, uvBC;
    s32 recFlags18;
    s32 tmp;
    s32 w6;
    s32 h6;
    u16 scX, scY;
    s16 ov;
    f32 fw, fh;
    f32 ang;
    f32 x, x2, r, q, h, cosv, sinv;
    void *mat;
    void *rot;
    f32 srcM[4][3];
    f32 dstM[4][3];
    f32 pts[4][2];
    f32 savedPts[4][2];
    f32 pkt[4][16];
    s32 i, j, k, m;
    s32 v14;
    f32 f0, f1;
    u8 *rp;
    s32 col;
    s32 rC, gC, bC, aC;
    s32 r2, g2, b2, a2;
    s32 alpha;
    u8 abit;
    f32 w54, h12, w58, h16, w5c, w60;
    f32 t0, t1;
    f32 negX, negY;
    s32 base;
    u8 *r2p;
    s32 wrapped, over;
    f32 *spD, *dpD, *ppD, *spP;
    u8 *b6;
    s32 extra;
    f32 p80, p84, p88, p8C, p90, p94, p98, p9C;
    s32 wA, wB, wC, wD;
    s16 t7;
    u8 *bb, *bb2;
    s16 ov2;
    f32 pA0;
    parent = *(u8 **)arg0;
    idx = *(s32 *)(arg0 + 4);
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    tbl300 = D_00887300;
    tbl310 = D_00887310;
    if (arg1 != 0) {
        tbl300[0](6, 1);
        tbl300[0](7, 2);
        tbl300[0](8, 1);
        tbl300[0](9, 2);
        tbl300[0](0xC, 1);
        tbl300[0](0xB, 6);
        tbl300[0](0xA, 5);
        tbl300[0](2, 4);
        tbl300[0](0xE, 0);
    }
    rec = *(u8 **)(parent + 0x204) + (idx << 7);
    slotidx = *(s32 *)(rec + 0x14) << 2;
    slot = *(u8 **)(parent + 0x104 + slotidx);
    if (slot != (u8 *)0) {
        w54 = (f32)*(s32 *)(rec + 0x54);
        h12 = (f32)*(s32 *)(slot + 0xC);
        uvA0 = w54 / h12;
        w58 = (f32)*(s32 *)(rec + 0x58);
        h16 = (f32)*(s32 *)(slot + 0x10);
        uvA4 = w58 / h16;
        w5c = (f32)((s32)*(s32 *)(rec + 0x5C) - 1);
        uvB8 = w5c / h12;
        w60 = (f32)((s32)*(s32 *)(rec + 0x60) - 1);
        uvBC = w60 / h16;
        uvA8 = uvB8;
        uvB0 = uvA0;
        uvAC = uvA4;
        uvB4 = uvBC;
    }
    if (arg1 != 0) {
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        if (*(s32 *)(rec + 0x2C) & 1) {
            func_003f6440(2, 0x48);
            func_003f6440(3, 0x71801);
        }
        if (*(s32 *)(rec + 0x2C) & 2) {
            func_003f6440(2, 0x42);
            func_003f6440(3, 0x71801);
        }
    }
    recFlags18 = *(s32 *)(rec + 0x18);
    if (recFlags18 & 2) {
        t0 = uvA0; t1 = uvA4;
        uvA0 = uvB0; uvA4 = uvB4;
        uvB0 = t0; uvB4 = t1;
        t0 = uvA8; t1 = uvAC;
        uvA8 = uvB8; uvAC = uvBC;
        uvB8 = t0; uvBC = t1;
    }
    if (recFlags18 & 1) {
        t0 = uvA0; t1 = uvA4;
        uvA0 = uvA8; uvA4 = uvAC;
        uvA8 = t0; uvAC = t1;
        t0 = uvB0; t1 = uvB4;
        uvB0 = uvB8; uvB4 = uvBC;
        uvB8 = t0; uvBC = t1;
    }
    {
        negX = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1C));
        negY = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1E));
        base = *(s32 *)(parent + 0x204);
        r2p = (u8 *)(base + (idx << 7));
        w6 = *(s32 *)(r2p + 0x5C) - *(s32 *)(r2p + 0x54);
        ov = *(s16 *)(base + 0x74 + (idx << 7));
        if (ov != 0) {
            w6 = ov;
        }
        scX = *(u16 *)(arg0 + 0x20);
        if (scX != 0) {
            w6 = (s32)(((u32)(w6 * scX)) >> 12);
        }
        if ((s32)w6 < 0) {
            fw = 2.0f * (f32)(u32)(((u32)w6 >> 1) | (w6 & 1));
        } else {
            fw = (f32)(u32)w6;
        }
        fw = fw - (f32)*(s16 *)(arg0 + 0x1C);
        h6 = *(s32 *)(r2p + 0x60) - *(s32 *)(r2p + 0x58);
        ov = *(s16 *)(base + 0x76 + (idx << 7));
        if (ov != 0) {
            h6 = ov;
        }
        scY = *(u16 *)(arg0 + 0x22);
        if (scY != 0) {
            h6 = (s32)(((u32)(h6 * scY)) >> 12);
        }
        if ((s32)h6 < 0) {
            fh = 2.0f * (f32)(u32)(((u32)h6 >> 1) | (h6 & 1));
        } else {
            fh = (f32)(u32)h6;
        }
        fh = fh - (f32)*(s16 *)(arg0 + 0x1E);
        srcM[0][0] = fw;
        srcM[0][1] = negY;
        srcM[0][2] = negX;
        srcM[1][0] = fh;
        srcM[1][1] = fw;
        srcM[1][2] = negY;
        srcM[2][0] = negX;
        srcM[2][1] = fh;
        srcM[3][0] = fw;
        srcM[3][1] = fh;
        ang = *(f32 *)(arg0 + 0x18);
        if (ang != 0.0f) {
            /* wrapped hoisted */
            do {
                /* over hoisted */
                wrapped = 0;
                over = !(ang <= 180.0f);
                if (over) {
                    ang -= 360.0f;
                    wrapped = 1;
                } else if (ang < -180.0f) {
                    ang += 360.0f;
                    wrapped = 1;
                }
            } while (wrapped != 0);
            x = (fGpffff8084 * ang) / 180.0f;
            x2 = x * x;
            mat = func_003e0f80();
            r = fGpffff81b0 * x2 + fGpffff81b4;
            r = x2 * r + fGpffff81b8;
            r = x2 * r + fGpffff81bc;
            r = x2 * r + fGpffff81c0;
            r = x2 * r + fGpffff81c4;
            q = x2 * r;
            h = 0.5f * x2 - x2 * q;
            cosv = 1.0f - (1.0f - h);
            r = fGpffff81c8 * x2 + fGpffff8054;
            r = x2 * r + fGpffff8058;
            r = x2 * r + fGpffff805c;
            r = x2 * r + fGpffff8060;
            r = x2 * r + fGpffff81cc;
            sinv = x + (x2 * x) * r;
            rot = func_003e0680(mat, D_007130D8, 0, cosv, sinv);
            func_003e42e0(dstM, srcM, 4, rot);
            func_003e0f40(rot);
            for (k = 0; k < 4; k++) {
                srcM[k][0] = dstM[k][0];
                srcM[k][1] = dstM[k][1];
                srcM[k][2] = dstM[k][2];
            }
        }
        for (j = 0; j < 4; j++) {
            spD = srcM[j];
            dpD = pts[j];
            dpD[0] = *(f32 *)(arg0 + 8) + ((f32)*(s16 *)(arg0 + 0x1C) + spD[0]) + (f32)*(s32 *)(rec + 0x44);
            dpD[1] = *(f32 *)(arg0 + 0xC) + ((f32)*(s16 *)(arg0 + 0x1E) + spD[1]) + (f32)*(s32 *)(rec + 0x48);
        }
        for (i = 0; i < 4; i++) {
            ppD = pkt[i];
            spP = pts[i];
            ppD[2] = D_008872F8[0] - *(f32 *)(arg0 + 0x24);
            ppD[6] = scale;
            ppD[4] = (&uvA0)[i * 2];
            ppD[5] = (&uvA0)[i * 2 + 1];
            rp = rec;
            if (i == 2) {
                col = *(s32 *)(rp + 0x70);
            } else if (i == 3) {
                col = *(s32 *)(rp + 0x6C);
            } else {
                col = *(s32 *)(rp + 0x64 + i * 4);
            }
            rC = (col >> 24) & 0xFF;
            gC = (col >> 16) & 0xFF;
            bC = (col >> 8) & 0xFF;
            aC = col & 0xFF;
            r2 = (rC * *(u8 *)(arg0 + 0x28)) / 255;
            g2 = (gC * *(u8 *)(arg0 + 0x29)) / 255;
            b2 = (bC * *(u8 *)(arg0 + 0x2A)) / 255;
            if ((*(s32 *)(rp + 0x18) & 8) == 0) {
                if ((r2 & 0xFF) < 0x81) {
                    tmp = r2 * 255;
                    if (tmp < 0) {
                        r2 = (tmp + 127) >> 7;
                    } else {
                        r2 = tmp >> 7;
                    }
                    r2 &= 0xFF;
                } else {
                    r2 = 255;
                }
                if ((g2 & 0xFF) < 0x81) {
                    tmp = g2 * 255;
                    if (tmp < 0) {
                        g2 = (tmp + 127) >> 7;
                    } else {
                        g2 = tmp >> 7;
                    }
                    g2 &= 0xFF;
                } else {
                    g2 = 255;
                }
                if ((b2 & 0xFF) < 0x81) {
                    tmp = b2 * 255;
                    if (tmp < 0) {
                        b2 = (tmp + 127) >> 7;
                    } else {
                        b2 = tmp >> 7;
                    }
                    b2 &= 0xFF;
                } else {
                    b2 = 255;
                }
                if ((aC & 0xFF) < 0x81) {
                    tmp = (aC & 0xFF) * 255;
                    if (tmp < 0) {
                        aC = (tmp + 127) >> 7;
                    } else {
                        aC = tmp >> 7;
                    }
                    aC &= 0xFF;
                } else {
                    aC = 255;
                }
            }
            alpha = ((aC & 0xFF) * (255 - *(u8 *)(arg0 + 0x11))) / 255;
            abit = *(u8 *)(arg0 + 0x10);
            if ((s32)abit < (s32)(alpha & 0xFF)) {
                a2 = (alpha - abit) & 0xFF;
            } else {
                a2 = 0;
            }
            if ((s32)r2 < 0) {
                f0 = 2.0f * (f32)(u32)(((u32)r2 >> 1) | (r2 & 1));
            } else {
                f0 = (f32)(u32)r2;
            }
            ppD[8] = f0;
            if ((s32)g2 < 0) {
                f0 = 2.0f * (f32)(u32)(((u32)g2 >> 1) | (g2 & 1));
            } else {
                f0 = (f32)(u32)g2;
            }
            ppD[9] = f0;
            if ((s32)b2 < 0) {
                f0 = 2.0f * (f32)(u32)(((u32)b2 >> 1) | (b2 & 1));
            } else {
                f0 = (f32)(u32)b2;
            }
            ppD[10] = f0;
            if ((s32)a2 < 0) {
                f0 = 2.0f * (f32)(u32)(((u32)a2 >> 1) | (a2 & 1));
            } else {
                f0 = (f32)(u32)a2;
            }
            ppD[11] = f0;
            ppD[0] = spP[0];
            ppD[1] = spP[1];
        }
        if ((*(s32 *)(rec + 0x18) & 8) != 0) {
            tbl300[0](1, 0);
        } else {
            tbl300[0](1, *(s32 *)(parent + 0x104 + slotidx));
        }
        tbl310[0](4, pkt, 4);
        for (m = 0; m < 4; m++) {
            savedPts[m][0] = pts[m][0];
            savedPts[m][1] = pts[m][1];
        }
        {
            b6 = *(u8 **)(parent + 0x204) + (idx << 7);
            extra = *(s32 *)(b6 + 0x34);
            if (extra != 0) {
                /* p hoisted */
                /* w hoisted */
                /* t7 hoisted */
                p80 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1C));
                p84 = (f32)(s32)(-(s16)(*(s16 *)(arg0 + 0x1E) + extra));
                wA = *(s32 *)(b6 + 0x5C) - *(s32 *)(b6 + 0x54);
                ov = *(s16 *)(b6 + 0x74 - 0x00 + 0x00);
                {
                    bb = (u8 *)(*(s32 *)(parent + 0x204) + (idx << 7));
                    ov = *(s16 *)(bb + 0x74);
                    if (ov != 0) {
                        wA = ov;
                    }
                }
                scX = *(u16 *)(arg0 + 0x20);
                if (scX != 0) {
                    wA = (s32)(((u32)(wA * scX)) >> 12);
                }
                if (wA < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wA >> 1) | (wA & 1));
                } else {
                    f1 = (f32)(u32)wA;
                }
                t7 = *(s16 *)(arg0 + 0x1C);
                p88 = f1 - (f32)t7;
                p8C = (f32)(s32)(-(s16)(*(s16 *)(arg0 + 0x1E) + *(s32 *)(b6 + 0x34)));
                p90 = (f32)(s32)(-t7);
                p94 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1E));
                wB = *(s32 *)(b6 + 0x5C) - *(s32 *)(b6 + 0x54);
                {
                    bb2 = (u8 *)(*(s32 *)(parent + 0x204) + (idx << 7));
                    ov2 = *(s16 *)(bb2 + 0x74);
                    if (ov2 != 0) {
                        wB = ov2;
                    }
                }
                if (*(u16 *)(arg0 + 0x20) != 0) {
                    wB = (s32)(((u32)(wB * *(u16 *)(arg0 + 0x20))) >> 12);
                }
                if (wB < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wB >> 1) | (wB & 1));
                } else {
                    f1 = (f32)(u32)wB;
                }
                p98 = f1 - (f32)*(s16 *)(arg0 + 0x1C);
                p9C = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1E));
                {
                    pts[0][0] = p80; pts[0][1] = p84;
                    pts[1][0] = p88; pts[1][1] = p8C;
                    pts[2][0] = p90; pts[2][1] = p94;
                    pts[3][0] = p98; pts[3][1] = p9C;
                    func_0046a7f0(arg0, (u8 *)pts);
                }
                pkt[0][0] = pts[0][0]; pkt[0][1] = pts[0][1];
                pkt[1][0] = pts[1][0]; pkt[1][1] = pts[1][1];
                pkt[2][0] = pts[2][0]; pkt[2][1] = pts[2][1];
                pkt[3][0] = pts[3][0]; pkt[3][1] = pts[3][1];
                pkt[0][4] = uvA0; pkt[0][5] = uvA4;
                pkt[1][4] = uvA8; pkt[1][5] = uvAC;
                pkt[2][4] = uvB0; pkt[2][5] = uvB4;
                pkt[3][4] = uvB8; pkt[3][5] = uvBC;
                if ((*(s32 *)(rec + 0x18) & 8) != 0) {
                    tbl300[0](1, 0);
                } else {
                    tbl300[0](1, *(s32 *)(parent + 0x104 + slotidx));
                }
                tbl310[0](4, pkt, 4);
            }
        }
        {
            b6 = *(u8 **)(parent + 0x204) + (idx << 7);
            if (*(s32 *)(b6 + 0x38) != 0) {
                /* p hoisted */
                /* w hoisted */
                p80 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1C));
                wA = *(s32 *)(b6 + 0x60) - *(s32 *)(b6 + 0x58);
                ov = *(s16 *)(b6 + 0x76);
                if (ov != 0) {
                    wA = ov;
                }
                if (*(u16 *)(arg0 + 0x22) != 0) {
                    wA = (s32)(((u32)(wA * *(u16 *)(arg0 + 0x22))) >> 12);
                }
                if (wA < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wA >> 1) | (wA & 1));
                } else {
                    f1 = (f32)(u32)wA;
                }
                p84 = f1 - (f32)*(s16 *)(arg0 + 0x1E);
                wB = *(s32 *)(b6 + 0x5C) - *(s32 *)(b6 + 0x54);
                ov = *(s16 *)(b6 + 0x74);
                if (ov != 0) {
                    wB = ov;
                }
                if (*(u16 *)(arg0 + 0x20) != 0) {
                    wB = (s32)(((u32)(wB * *(u16 *)(arg0 + 0x20))) >> 12);
                }
                if (wB < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wB >> 1) | (wB & 1));
                } else {
                    f1 = (f32)(u32)wB;
                }
                p88 = f1 - (f32)*(s16 *)(arg0 + 0x1C);
                wC = *(s32 *)(b6 + 0x60) - *(s32 *)(b6 + 0x58);
                ov = *(s16 *)(b6 + 0x76);
                if (ov != 0) {
                    wC = ov;
                }
                if (*(u16 *)(arg0 + 0x22) != 0) {
                    wC = (s32)(((u32)(wC * *(u16 *)(arg0 + 0x22))) >> 12);
                }
                if (wC < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wC >> 1) | (wC & 1));
                } else {
                    f1 = (f32)(u32)wC;
                }
                p8C = f1 - (f32)*(s16 *)(arg0 + 0x1E);
                p90 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1C));
                p94 = (f32)*(s32 *)(b6 + 0x38) + (f1 - (f32)*(s16 *)(arg0 + 0x1E));
                wD = *(s32 *)(b6 + 0x60) - *(s32 *)(b6 + 0x58);
                ov = *(s16 *)(b6 + 0x76);
                if (ov != 0) {
                    wD = ov;
                }
                if (*(u16 *)(arg0 + 0x22) != 0) {
                    wD = (s32)(((u32)(wD * *(u16 *)(arg0 + 0x22))) >> 12);
                }
                if (wD < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wD >> 1) | (wD & 1));
                } else {
                    f1 = (f32)(u32)wD;
                }
                p98 = f1 - (f32)*(s16 *)(arg0 + 0x1C);
                p9C = (f32)*(s32 *)(b6 + 0x38) + (f1 - (f32)*(s16 *)(arg0 + 0x1E));
                {
                    pts[0][0] = p80; pts[0][1] = p84;
                    pts[1][0] = p88; pts[1][1] = p8C;
                    pts[2][0] = p90; pts[2][1] = p94;
                    pts[3][0] = p98; pts[3][1] = p9C;
                    func_0046a7f0(arg0, (u8 *)pts);
                }
                pkt[0][0] = pts[0][0]; pkt[0][1] = pts[0][1];
                pkt[1][0] = pts[1][0]; pkt[1][1] = pts[1][1];
                pkt[2][0] = pts[2][0]; pkt[2][1] = pts[2][1];
                pkt[3][0] = pts[3][0]; pkt[3][1] = pts[3][1];
                pkt[0][4] = uvA0; pkt[0][5] = uvA4;
                pkt[1][4] = uvA8; pkt[1][5] = uvAC;
                pkt[2][4] = uvB0; pkt[2][5] = uvB4;
                pkt[3][4] = uvB8; pkt[3][5] = uvBC;
                if ((*(s32 *)(rec + 0x18) & 8) != 0) {
                    tbl300[0](1, 0);
                } else {
                    tbl300[0](1, *(s32 *)(parent + 0x104 + slotidx));
                }
                tbl310[0](4, pkt, 4);
            }
        }
        {
            b6 = *(u8 **)(parent + 0x204) + (idx << 7);
            extra = *(s32 *)(b6 + 0x3C);
            if (extra != 0) {
                /* p hoisted */
                /* w hoisted */
                p80 = (f32)(s32)(-(s16)(*(s16 *)(arg0 + 0x1C) + extra));
                p84 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1E));
                p88 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1C));
                p8C = p84;
                p90 = (f32)(s32)(-(s16)(*(s16 *)(arg0 + 0x1C) + *(s32 *)(b6 + 0x3C)));
                wA = *(s32 *)(b6 + 0x60) - *(s32 *)(b6 + 0x58);
                ov = *(s16 *)(b6 + 0x76);
                if (ov != 0) {
                    wA = ov;
                }
                if (*(u16 *)(arg0 + 0x22) != 0) {
                    wA = (s32)(((u32)(wA * *(u16 *)(arg0 + 0x22))) >> 12);
                }
                if (wA < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wA >> 1) | (wA & 1));
                } else {
                    f1 = (f32)(u32)wA;
                }
                p94 = f1 - (f32)*(s16 *)(arg0 + 0x1E);
                p98 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1C));
                wB = *(s32 *)(b6 + 0x60) - *(s32 *)(b6 + 0x58);
                ov = *(s16 *)(b6 + 0x76);
                if (ov != 0) {
                    wB = ov;
                }
                if (*(u16 *)(arg0 + 0x22) != 0) {
                    wB = (s32)(((u32)(wB * *(u16 *)(arg0 + 0x22))) >> 12);
                }
                if (wB < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wB >> 1) | (wB & 1));
                } else {
                    f1 = (f32)(u32)wB;
                }
                p9C = (f32)*(s32 *)(b6 + 0x3C) + (f1 - (f32)*(s16 *)(arg0 + 0x1E));
                wC = *(s32 *)(b6 + 0x5C) - *(s32 *)(b6 + 0x54);
                ov = *(s16 *)(b6 + 0x74);
                if (ov != 0) {
                    wC = ov;
                }
                if (*(u16 *)(arg0 + 0x20) != 0) {
                    wC = (s32)(((u32)(wC * *(u16 *)(arg0 + 0x20))) >> 12);
                }
                if (wC < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wC >> 1) | (wC & 1));
                } else {
                    f1 = (f32)(u32)wC;
                }
                {
                    pA0 = f1 - (f32)*(s16 *)(arg0 + 0x1C);
                    pts[0][0] = p80; pts[0][1] = p84;
                    pts[1][0] = p88; pts[1][1] = p8C;
                    pts[2][0] = p90; pts[2][1] = p94;
                    pts[3][0] = p98; pts[3][1] = p9C;
                    func_0046a7f0(arg0, (u8 *)pts);
                    pkt[0][0] = pts[0][0]; pkt[0][1] = pts[0][1];
                    pkt[1][0] = pts[1][0]; pkt[1][1] = pts[1][1];
                    pkt[2][0] = pts[2][0]; pkt[2][1] = pts[2][1];
                    pkt[3][0] = pts[3][0]; pkt[3][1] = pts[3][1];
                    pkt[0][4] = uvA0; pkt[0][5] = uvA4;
                    pkt[1][4] = uvA8; pkt[1][5] = uvAC;
                    pkt[2][4] = uvB0; pkt[2][5] = uvB4;
                    pkt[3][4] = uvB8; pkt[3][5] = uvBC;
                    (void)pA0;
                    if ((*(s32 *)(rec + 0x18) & 8) != 0) {
                        tbl300[0](1, 0);
                    } else {
                        tbl300[0](1, *(s32 *)(parent + 0x104 + slotidx));
                    }
                    tbl310[0](4, pkt, 4);
                }
            }
        }
        {
            b6 = *(u8 **)(parent + 0x204) + (idx << 7);
            if (*(s32 *)(b6 + 0x40) != 0) {
                /* p hoisted */
                /* w hoisted */
                wA = *(s32 *)(b6 + 0x5C) - *(s32 *)(b6 + 0x54);
                ov = *(s16 *)(b6 + 0x74);
                if (ov != 0) {
                    wA = ov;
                }
                if (*(u16 *)(arg0 + 0x20) != 0) {
                    wA = (s32)(((u32)(wA * *(u16 *)(arg0 + 0x20))) >> 12);
                }
                if (wA < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wA >> 1) | (wA & 1));
                } else {
                    f1 = (f32)(u32)wA;
                }
                p80 = f1 - (f32)*(s16 *)(arg0 + 0x1C);
                p84 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1E));
                wB = *(s32 *)(b6 + 0x5C) - *(s32 *)(b6 + 0x54);
                ov = *(s16 *)(b6 + 0x74);
                if (ov != 0) {
                    wB = ov;
                }
                if (*(u16 *)(arg0 + 0x20) != 0) {
                    wB = (s32)(((u32)(wB * *(u16 *)(arg0 + 0x20))) >> 12);
                }
                if (wB < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wB >> 1) | (wB & 1));
                } else {
                    f1 = (f32)(u32)wB;
                }
                p88 = (f32)*(s32 *)(b6 + 0x40) + (f1 - (f32)*(s16 *)(arg0 + 0x1C));
                p8C = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1E));
                wC = *(s32 *)(b6 + 0x60) - *(s32 *)(b6 + 0x58);
                ov = *(s16 *)(b6 + 0x76);
                if (ov != 0) {
                    wC = ov;
                }
                if (*(u16 *)(arg0 + 0x22) != 0) {
                    wC = (s32)(((u32)(wC * *(u16 *)(arg0 + 0x22))) >> 12);
                }
                if (wC < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wC >> 1) | (wC & 1));
                } else {
                    f1 = (f32)(u32)wC;
                }
                p90 = f1 - (f32)*(s16 *)(arg0 + 0x1E);
                p94 = (f32)(s32)(-(s16)*(s16 *)(arg0 + 0x1C));
                wD = *(s32 *)(b6 + 0x60) - *(s32 *)(b6 + 0x58);
                ov = *(s16 *)(b6 + 0x76);
                if (ov != 0) {
                    wD = ov;
                }
                if (*(u16 *)(arg0 + 0x22) != 0) {
                    wD = (s32)(((u32)(wD * *(u16 *)(arg0 + 0x22))) >> 12);
                }
                if (wD < 0) {
                    f1 = 2.0f * (f32)(u32)(((u32)wD >> 1) | (wD & 1));
                } else {
                    f1 = (f32)(u32)wD;
                }
                p98 = f1 - (f32)*(s16 *)(arg0 + 0x1E);
                p9C = p94;
                {
                    pts[0][0] = p80; pts[0][1] = p84;
                    pts[1][0] = p88; pts[1][1] = p8C;
                    pts[2][0] = p90; pts[2][1] = p94;
                    pts[3][0] = p98; pts[3][1] = p9C;
                    func_0046a7f0(arg0, (u8 *)pts);
                }
                pkt[0][0] = pts[0][0]; pkt[0][1] = pts[0][1];
                pkt[1][0] = pts[1][0]; pkt[1][1] = pts[1][1];
                pkt[2][0] = pts[2][0]; pkt[2][1] = pts[2][1];
                pkt[3][0] = pts[3][0]; pkt[3][1] = pts[3][1];
                pkt[0][4] = uvA0; pkt[0][5] = uvA4;
                pkt[1][4] = uvA8; pkt[1][5] = uvAC;
                pkt[2][4] = uvB0; pkt[2][5] = uvB4;
                pkt[3][4] = uvB8; pkt[3][5] = uvBC;
                if ((*(s32 *)(rec + 0x18) & 8) != 0) {
                    tbl300[0](1, 0);
                } else {
                    tbl300[0](1, *(s32 *)(parent + 0x104 + slotidx));
                }
                tbl310[0](4, pkt, 4);
            }
        }
        for (m = 0; m < 4; m++) {
            pts[m][0] = savedPts[m][0];
            pts[m][1] = savedPts[m][1];
        }
        if (*(s16 *)(arg0 + 0x16) != 0) {
            pkt[0][0] = pts[2][0]; pkt[0][1] = pts[2][1];
            pkt[1][0] = pts[3][0]; pkt[1][1] = pts[3][1];
            pkt[2][0] = pts[2][0]; pkt[2][1] = pts[2][1];
            pkt[2][1] = pts[2][1] + (f32)*(s16 *)(arg0 + 0x16);
            pkt[3][0] = pts[3][0]; pkt[3][1] = pts[3][1] + (f32)*(s16 *)(arg0 + 0x16);
            pkt[0][4] = uvB0; pkt[0][5] = uvB4;
            pkt[1][4] = uvB8; pkt[1][5] = uvBC;
            pkt[2][4] = uvB0; pkt[2][5] = uvB4;
            pkt[3][4] = uvB8; pkt[3][5] = uvBC;
            if ((*(s32 *)(rec + 0x18) & 8) != 0) {
                tbl300[0](1, 0);
            } else {
                tbl300[0](1, *(s32 *)(parent + 0x104 + slotidx));
            }
            tbl310[0](4, pkt, 4);
            return;
        }
        if (*(s16 *)(arg0 + 0x14) != 0) {
            pkt[0][0] = pts[1][0]; pkt[0][1] = pts[1][1];
            pkt[1][0] = pts[1][0] + (f32)*(s16 *)(arg0 + 0x14); pkt[1][1] = pts[1][1];
            pkt[2][0] = pts[3][0]; pkt[2][1] = pts[3][1];
            pkt[3][0] = pts[3][0] + (f32)*(s16 *)(arg0 + 0x14); pkt[3][1] = pts[3][1];
            pkt[0][4] = uvA8; pkt[0][5] = uvAC;
            pkt[1][4] = uvA8; pkt[1][5] = uvAC;
            pkt[2][4] = uvB8; pkt[2][5] = uvBC;
            pkt[3][4] = uvB8; pkt[3][5] = uvBC;
            if ((*(s32 *)(rec + 0x18) & 8) != 0) {
                tbl300[0](1, 0);
            } else {
                tbl300[0](1, *(s32 *)(parent + 0x104 + slotidx));
            }
            tbl310[0](4, pkt, 4);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046b380);
#endif

// FUN_0046D200
u8 *func_0046d200(u32 arg0, u32 arg1)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    return node;
}

// FUN_0046D280
void func_0046d280(void *node)
{
    jtbl_008873EC[0](node);
}

// FUN_0046D2B0
void func_0046d2b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, f32 z, s32 arg3)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    func_0046b380(node, arg3);
    jtbl_008873EC[0](node);
}

// FUN_0046D3B0
void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, f32 z, s32 arg4)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    *(u8 *)(node + 0x11) = arg3;
    func_0046b380(node, arg4);
    jtbl_008873EC[0](node);
}

// FUN_0046D4C0
void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 z, s32 arg6)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    *(u8 *)(node + 0x28) = arg3;
    *(u8 *)(node + 0x29) = arg4;
    *(u8 *)(node + 0x2A) = arg5;
    func_0046b380(node, arg6);
    jtbl_008873EC[0](node);
}

/* measured: nd 53 with a full C body (object 172B against a 192B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
/* Measured nd 9 (object 176 / window 192); the body matches the allocation, field initialization, callback, and result path but retains nine normalized instruction differences. */
// FUN_0046D5F0
s32 func_0046d5f0(u8 *arg0, s32 arg1) {
    s32 temp_16;
    u8 *temp_2;
    u8 *temp_5;
    u8 *output;
    s32 index;

    func_0044ea90(D_007130C8, 0x3AF);
    temp_2 = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(temp_2 + 0x28) = 0xFF;
    *(u8 *)(temp_2 + 0x29) = 0xFF;
    *(u8 *)(temp_2 + 0x2A) = 0xFF;
    *(u8 **)temp_2 = arg0;
    *(s32 *)(temp_2 + 4) = arg1;
    temp_5 = *(u8 **)temp_2;
    output = *(u8 **)(temp_5 + 0x204);
    output = (u8 *)sdkAddOffset((u32)(arg1 << 7), (u32)output);
    index = *(s32 *)(output + 0x14);
    temp_16 = *(s32 *)((u8 *)sdkAddOffset((u32)(index << 2), (u32)temp_5) + 0x104);
    jtbl_008873EC[0](temp_2);
    return temp_16;
}
// FUN_0046D6A0
void func_0046d6a0(void)
{
}

