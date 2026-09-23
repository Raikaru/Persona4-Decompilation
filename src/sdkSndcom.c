/* Consolidated Persona 4 source units. */
/* Original translation unit sdkSndcom.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
#include "sdk_snd_internal.h"

typedef struct HCdvd HCdvd;

typedef struct HSfdDecodeSlot
{
    s16 state;
    s16 padding02;
    HCdvd* request;
    s16 fileIndex;
    s16 index;
    s32 queueHandle;       // 0x0C
    s32 outputHandle;      // 0x10
    s32 decodeHandle;      // 0x14
    s32 status;            // 0x18
    void* input;           // 0x1C
    u32 inputSize;         // 0x20
    void* intermediate;    // 0x24
    u32 intermediateSize;  // 0x28
    void* output;          // 0x2C
    u32 outputSize;        // 0x30
    void* resource;        // 0x34
    void* aux;             // 0x38
    void* sourceData;      // 0x3C
    void* completion;      // 0x40
} HSfdDecodeSlot;

extern HSfdDecodeSlot sSfdDecodeSlots_abs[];

/* Per-stream state tables (byte-indexed; stride 0x44 for the slot tables). */
extern u8 D_008E3FC0[];
extern u8 D_008E3FC4[];
extern u8 D_008E3FC8[];
extern u8 D_008E3FCC[];
extern u8 D_008E3FD0[];
extern u8 D_008E3FD4[];
extern u8 D_008E3FD8[];
extern u8 D_008E4090[];
extern u8 D_008E4094[];
extern u8 D_008E4098[];
extern u8 D_008E409C[];
extern u8 D_008E40A0[];
extern u8 D_008E40A4[];
extern u8 D_008E40A8[];
extern u8 D_008E40AC[];
extern u8 D_008E40B0[];
extern u8 D_008E40B4[];
extern u8 D_008E40B8[];
extern u8 D_008E40BC[];
extern u8 D_008E40C0[];
extern u8 D_008E40C4[];
extern u8 D_008E40C8[];
extern u8 D_008E40CC[];
extern u8 D_008E40D0[];
extern u8 D_008D3FD0[];
extern u8 D_00712390[];   /* stream setup table (stride 0xC) */

/* Debug strings (absolute) and small-data format strings (gp-relative). */
extern char D_007123C0[];
extern char D_007123E8[];
extern char D_007123F8[];
extern char D_00712408[];
extern char D_00712418[];
extern char D_00712428[];
extern char D_00712440[];
extern char D_00712458[];
extern char D_00712470[];
extern char D_00764020;
extern char D_00764028;
extern char D_00764030;

/* Sony SDK PS2 sound-library helpers (shared blob). */
extern void func_00440b68();
extern void func_0046d730();
extern void func_0046d740(const void *msg, const void *file, u32 line);
extern void func_00421a60();
extern s32 func_00424708();
extern s32 func_00421b80();
extern void func_0043c470();
extern void func_0043c308();
extern void func_00429d90();
extern s32 func_0043c5e8(s32 handle, ...);
extern s32 func_0043c518(s32 handle, ...);
extern s32 func_00429d10();
extern void func_0043c180();
extern s32 func_0043c230();
extern s32 func_0043c3b0();
extern void memcpy();
extern s32 func_00454a60();
extern void H_Cdvd_Destroy();
extern s32 H_Cdvd_IsFileLoaded();
extern void *func_00455f70();

s32 func_0045b650(s32 handle, void *data, s32 size);
void func_0045c3d0(s16 index);

// FUN_0045B650
s32 func_0045b650(s32 handle, void *data, s32 size)
{
    s32 r;
    s32 q;

    if (size <= 0) {
        return 0;
    }
    *(void **)&D_008E3FC0[0] = data;
    *(s32 *)&D_008E3FC4[0] = handle;
    *(s32 *)&D_008E3FC8[0] = size;
    *(s32 *)&D_008E3FCC[0] = 0;
    func_00440b68(D_007123C0, data, handle, size);
    func_00440b68(&D_00764020);
    func_00421a60(0);
    func_00440b68(D_007123E8);
    q = func_00424708(&D_008E3FC0[0], 1);
    func_00440b68(D_007123F8, q);
    if (q == 0) {
        func_0046d730(D_00712408, 0xF0);
    }
    do {
        r = func_00421b80(q);
    } while (r >= 0);
    for (;;) {
        r = func_00421b80(q);
        if (r > 0) {
            func_00440b68(&D_00764028);
            continue;
        }
        if (r == 0) {
            func_00440b68(D_00712418);
            continue;
        }
        break;
    }
    func_00440b68(D_00712428);
    return size;
}

/* measured: guarded 504 words (reloc-masked), obj 2444B/window 2416B (+28B, 1.2% within 3% gate), */
/* fnalign retail 604/object 611 instrs (+7, 23 reloc-only, 556 edits). Retail rematerializes */
/* the slot base (lui/addiu/addu D_008E4090+i*0x44 with dsll32/dsra32) after every call */
/* (wscan retail 16 dsll32 pairs + 51 daddu vs object 2 + 0); b210 CSEs the slot into one */
/* saved reg with direct offsets, frame 0xD0 vs 0xC0 (i in $s7 vs $s4). Pragma sweep ties */
/* at 504 (all singles neutral/regress). Switch keeps jtbl_00756550 order 0,2-8 */
/* (case 1 falls to tail); m2c with hand-supplied jtbl + romwright second opinion; */
/* file byte-array idiom with D_008E4094/D_008E40B4 completing the split table. */
/* 2026-09-18 addressing pass (7k/7p), base 504, reloc-masked words: slot_cast 439 (69 slot */
/* addrs to (char*)D_008E4090+i*0x44+off, off hoist removed); both_cast 257 (+6 setup addrs to */
/* (char*)D_00712390+fi*0xC[+4/8]); rounding_clean_census 259 (t+0x7F sra before/after branch, */
/* spBC=rem first); decl_i_late 228 (kept: [spBC,fileIndex,src,p1,p2,i,h,h2,dst,rem] and later, */
/* h2 removal neutral, i in $s4 like retail, slot still $s1 vs $s0, frame 0xB0 vs 0xC0); */
/* decl_i_early 259 tie; decl_i_mid 276 regress; reorder tie 228 (seven other-local singles); */
/* slot_hold_per_loop 523: per-loop slotBase hold is the 7k hoist, cost 295 words over kept 228. */
/* Census before (opclass, unusually clean, seven classes, no float noise): lui +31, sll -29, */
/* addiu +19, addu +16, dsra32 -14, dsll32 -14, sra -2. After: both_cast leaves sra -2/sll -1 */
/* only (obj 2384B, lui/addu/dsll32/dsra32 deltas gone); rounding_dup leaves zero INTERESTING */
/* surplus (obj 2388B); kept decl_i_late inherits the clean census (decl order shifts coloring, */
/* frame 0xB0 vs 0xC0, not opcode counts). */
// FUN_0045B7C0 NONMATCHING
#ifdef NON_MATCHING
void func_0045b7c0(void)
{
    s32 spBC;
    s16 fileIndex;
    void *src;
    u8 *p1;
    u8 *p2;
    s32 h;
    s32 h2;
    s32 dst;
    s32 rem;
    s16 i;
    for (i = 0; i < 6; i++) {
        switch (*(s16 *)((char*)D_008E4090 + i * 0x44)) {
        case 0:
            *(s16 *)((char*)D_008E4090 + i * 0x44) = 1;
            break;
        case 2:
            func_00440b68(&D_00764030, D_00712408, 0x11F);
            fileIndex = *(s16 *)((char*)D_008E4090 + i * 0x44 + 0x8);
            *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4) = func_00454a60(*(void **)((char*)D_00712390 + fileIndex * 0xC), 0);
            *(s16 *)((char*)D_008E4090 + i * 0x44) = 3;
            break;
        case 3:
            if (H_Cdvd_IsFileLoaded(*(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4)) != 0) {
                fileIndex = *(s16 *)((char*)D_008E4090 + i * 0x44 + 0x8);
                src = func_00455f70(*(void **)((char*)D_00712390 + fileIndex * 0xC), &spBC);
                h = func_00429d10(0, spBC, 0);
                if (h == 0) {
                    func_0046d730(D_00712408, 0x129);
                }
                memcpy(D_008D3FD0, src, spBC);
                func_0045b650(h, D_008D3FD0, spBC);
                H_Cdvd_Destroy(*(void **)((char*)D_008E4090 + i * 0x44 + 0x4));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x1C) = h;
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x20) = spBC;
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4) = 0;
                *(s16 *)((char*)D_008E4090 + i * 0x44) = 4;
            }
            break;
        case 4:
            func_00440b68(&D_00764030, D_00712408, 0x136);
            fileIndex = *(s16 *)((char*)D_008E4090 + i * 0x44 + 0x8);
            *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4) = func_00454a60(*(void **)((char*)D_00712390 + fileIndex * 0xC + 4), 0);
            *(s16 *)((char*)D_008E4090 + i * 0x44) = 5;
            break;
        case 5:
            if (H_Cdvd_IsFileLoaded(*(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4)) != 0) {
                fileIndex = *(s16 *)((char*)D_008E4090 + i * 0x44 + 0x8);
                src = func_00455f70(*(void **)((char*)D_00712390 + fileIndex * 0xC + 4), &spBC);
                h = func_00429d10(0, 0x1000, 0);
                if (h == 0) {
                    func_0046d730(D_00712408, 0x140);
                }
                dst = *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x24);
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x28) = spBC;
                rem = spBC;
                p1 = (u8 *)src;
                do {
                    if (rem < 0x1001) {
                        spBC = rem;
                        rem = 0;
                    } else {
                        spBC = 0x1000;
                        rem -= 0x1000;
                    }
                    func_0045b650(h, p1, spBC);
                    func_0043c180(1, h, dst, spBC);
                    p1 += spBC;
                    dst += spBC;
                } while (rem != 0);
                H_Cdvd_Destroy(*(void **)((char*)D_008E4090 + i * 0x44 + 0x4));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4) = 0;
                func_00429d90(h);
                *(s16 *)((char*)D_008E4090 + i * 0x44) = 6;
            }
            break;
        case 6:
            func_00440b68(&D_00764030, D_00712408, 0x15B);
            fileIndex = *(s16 *)((char*)D_008E4090 + i * 0x44 + 0x8);
            *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4) = func_00454a60(*(void **)((char*)D_00712390 + fileIndex * 0xC + 8), 0);
            *(s16 *)((char*)D_008E4090 + i * 0x44) = 7;
            break;
        case 7:
            if (H_Cdvd_IsFileLoaded(*(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4)) != 0) {
                s32 r1;
                s32 r2;
                s32 r3;
                s32 r4;
                fileIndex = *(s16 *)((char*)D_008E4090 + i * 0x44 + 0x8);
                src = func_00455f70(*(void **)((char*)D_00712390 + fileIndex * 0xC + 8), &spBC);
                h = func_00429d10(0, spBC, 0);
                if (h == 0) {
                    func_0046d730(D_00712408, 0x165);
                }
                func_0045b650(h, src, spBC);
                H_Cdvd_Destroy(*(void **)((char*)D_008E4090 + i * 0x44 + 0x4));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x2C) = h;
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x30) = spBC;
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x4) = 0;
                r1 = func_0043c230(3, -1, *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x1C), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x20), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x24), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x28));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0xC) = r1;
                if (r1 < 0) {
                    func_0046d730(D_00712408, 0x16F);
                }
                r2 = func_0043c230(5, -1, *(s32 *)((char*)D_008E4090 + i * 0x44 + 0xC), 0);
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x10) = r2;
                if (r2 < 0) {
                    func_0046d730(D_00712408, 0x174);
                }
                r3 = func_0043c3b0(0, -1, *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x2C), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x30));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x14) = r3;
                if (r3 < 0) {
                    func_0046d730(D_00712408, 0x178);
                }
                r4 = func_0043c3b0(5, *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x10), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x14));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x40) = r4;
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x18) = 1;
                *(s16 *)((char*)D_008E4090 + i * 0x44) = 1;
            }
            break;
        case 8:
            {
                void *res;
                s32 sz;
                s32 h1;
                void *s2;
                s32 sz2;
                s32 hb;
                s32 d2;
                s32 rem2;
                void *s3;
                s32 sz3;
                s32 hc;
                s32 q;
                s32 o;
                s32 d;
                s32 c;
                res = *(void **)((char*)D_008E4090 + i * 0x44 + 0x34);
                sz = *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x20);
                spBC = sz;
                h1 = func_00429d10(0, sz, 0);
                if (h1 == 0) {
                    func_0046d730(D_00712408, 0x189);
                }
                func_0045b650(h1, res, spBC);
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x1C) = h1;
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x20) = spBC;
                s2 = *(void **)((char*)D_008E4090 + i * 0x44 + 0x38);
                sz2 = *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x28);
                spBC = sz2;
                hb = func_00429d10(0, 0x1000, 0);
                if (hb == 0) {
                    func_0046d730(D_00712408, 0x193);
                }
                d2 = *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x24);
                rem2 = sz2;
                p1 = (u8 *)s2;
                p2 = (u8 *)d2;
                do {
                    if (rem2 < 0x1001) {
                        s32 t;
                        s32 q;
                        spBC = rem2;
                        t = rem2 + 0x7F;
                        q = t >> 7;
                        if (t < 0) {
                            q = (t + 0x7F) >> 7;
                        }
                        spBC = q << 7;
                        rem2 = 0;
                    } else {
                        spBC = 0x1000;
                        rem2 -= 0x1000;
                    }
                    func_0045b650(hb, p1, spBC);
                    func_0043c180(1, hb, p2, spBC);
                    p1 += spBC;
                    p2 += spBC;
                } while (rem2 != 0);
                func_00429d90(hb);
                s3 = *(void **)((char*)D_008E4090 + i * 0x44 + 0x3C);
                sz3 = *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x30);
                spBC = sz3;
                hc = func_00429d10(0, sz3, 0);
                if (hc == 0) {
                    func_0046d730(D_00712408, 0x1AB);
                }
                func_0045b650(hc, s3, spBC);
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x2C) = hc;
                q = func_0043c230(3, -1, *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x1C), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x20), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x24), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x28));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0xC) = q;
                o = func_0043c230(5, -1, q, 0);
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x10) = o;
                d = func_0043c3b0(0, -1, *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x2C), *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x30));
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x14) = d;
                c = func_0043c3b0(5, *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x10), d);
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x40) = c;
                *(s32 *)((char*)D_008E4090 + i * 0x44 + 0x18) = 1;
                *(s16 *)((char*)D_008E4090 + i * 0x44) = 1;
            }
            break;
        default:
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045b7c0);
#endif
// FUN_0045C130
void func_0045c130(s16 index, s16 fileIndex)
{
    if (*(s16 *)&D_008E4090[index * 0x44] == 1) {
        if (*(void **)&D_008E40A8[index * 0x44] != 0) {
            func_0045c3d0(index);
        }
        *(s16 *)&D_008E4098[index * 0x44] = fileIndex;
        *(s16 *)&D_008E4090[index * 0x44] = 2;
        return;
    }
    func_0046d740(D_00712440, D_00712408, 0x1D0);
}

// FUN_0045C210
void func_0045c210(s16 index, s16 fileIndex, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, s32 arg7)
{
    if (*(s16 *)&D_008E4090[index * 0x44] == 1) {
        if (*(void **)&D_008E40A8[index * 0x44] != 0) {
            func_0045c3d0(index);
        }
        *(s16 *)&D_008E4098[index * 0x44] = fileIndex;
        *(s16 *)&D_008E4090[index * 0x44] = 8;
        *(s32 *)&D_008E40C4[index * 0x44] = arg2;
        *(s32 *)&D_008E40C8[index * 0x44] = arg4;
        *(s32 *)&D_008E40CC[index * 0x44] = arg6;
        *(s32 *)&D_008E40B0[index * 0x44] = arg3;
        *(s32 *)&D_008E40B8[index * 0x44] = arg5;
        *(s32 *)&D_008E40C0[index * 0x44] = arg7;
        return;
    }
    func_0046d740(D_00712440, D_00712408, 0x1E9);
}

// FUN_0045C390
u32 func_0045c390(s16 index)
{
    return sSfdDecodeSlots_abs[index].state == 1;
}

// FUN_0045C3D0
void func_0045c3d0(s16 index)
{
    s32 off;
    void **inp;

    off = index * 0x44;
    if (*(s16 *)&D_008E4090[off] == 1) {
        inp = (void **)&D_008E40A8[off];
        if (*inp != 0) {
            func_0043c470(5, *(s32 *)&D_008E40D0[off]);
            func_0043c470(0, *(s32 *)&D_008E40A4[off]);
            func_0043c308(5, *(s32 *)&D_008E40A0[off]);
            func_0043c308(3, *(s32 *)&D_008E409C[off]);
            *inp = 0;
            func_00429d90(*(void **)&D_008E40AC[off]);
            func_00429d90(*(void **)&D_008E40BC[off]);
        }
        *inp = 0;
        return;
    }
    func_0046d740(D_00712440, D_00712408, 0x21C);
}

// FUN_0045C510
void func_0045c510(s16 index, s16 stream)
{
    s32 off;
    s32 *p;
    s32 r;

    off = index * 0x44;
    if (*(s16 *)&D_008E4090[off] == 1 && *(void **)&D_008E40A8[off] != 0) {
        p = (s32 *)&D_008E3FD0[stream * 0xC];
        if (*p != 0) {
            r = func_0043c5e8(*(s32 *)&D_008E40A0[off], 1, 0xA, *(s32 *)&D_008E3FD8[stream * 0xC]);
            switch (r) {
            case 0:
            case -0x12B:
                func_0043c518(*(s32 *)&D_008E40A0[off], 2, 0xA,
                              *(s32 *)&D_008E3FD8[stream * 0xC]);
                break;
            default:
                func_00440b68(D_00712458, r);
                break;
            }
            *p = 0;
        }
    }
}

/* measured: 552B/560B, all 32 relocations resolved; eight zero-tail bytes.
   Preserve the separate pre-stop and post-stop address computations and
   the output-handle load before the final halfword argument promotions. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_0045C640
void func_0045c640(s16 index, s16 stream, s16 arg2, s16 arg3)
{
    s32 slotOffset;
    s32 state;
    s32 status;
    s32 *streamActive;
    s32 *streamHandle;
    s32 *handlePointer;
    s32 result;
    s32 streamOffset;
    s32 outputHandle;
    s32 active;
    s32 ready;
    s32 previousOffset;

    slotOffset = index * 0x44;
    state = *(s16 *)&D_008E4090[slotOffset];
    ready = 1;
    if (state == ready) {
        status = *(s32 *)&D_008E40A8[slotOffset];
        if (status != 0) {
            previousOffset = stream * 0xC;
            streamActive = (s32 *)&D_008E3FD0[previousOffset];
            active = *streamActive;
            if ((active != 0) && (state == ready) && (status != 0) && (active != 0)) {
                streamHandle = (s32 *)&D_008E3FD8[previousOffset];
                handlePointer = (s32 *)&D_008E40A0[slotOffset];
                result = func_0043c5e8(*handlePointer, ready, 0xA, *streamHandle);
                switch (result) {
                case 0:
                case -0x12B:
                    func_0043c518(*handlePointer, 2, 0xA, *streamHandle);
                    break;
                default:
                    func_00440b68(D_00712458, result);
                    break;
                }
                *streamActive = 0;
            }
            streamOffset = stream * 0xC;
            *(s16 *)&D_008E3FD4[streamOffset] = index;
            *streamActive = 1;
            outputHandle = *(s32 *)&D_008E40A0[slotOffset];
            *(s32 *)&D_008E3FD8[streamOffset] = func_0043c518(
                outputHandle, 0, 0xA, (s32)arg2, (s32)arg3);
            return;
        }
        func_0046d740(D_00712470, D_00712408, 0x283);
        return;
    }
    func_0046d740(D_00712470, D_00712408, 0x286);
}
#pragma pop
