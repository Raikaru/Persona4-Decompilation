/* Consolidated Persona 4 source units. */
/* Original translation unit sdkSndcom.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

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
extern u8 D_008E3FD8[];
extern u8 D_008E4090[];
extern u8 D_008E4098[];
extern u8 D_008E409C[];
extern u8 D_008E40A0[];
extern u8 D_008E40A4[];
extern u8 D_008E40A8[];
extern u8 D_008E40AC[];
extern u8 D_008E40B0[];
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
extern void func_0046d740();
extern void func_00421a60();
extern s32 func_00424708();
extern s32 func_00421b80();
extern void func_0043c470();
extern void func_0043c308();
extern void func_00429d90();
extern s32 func_0043c5e8();
extern s32 func_0043c518();
extern s32 func_00429d10();
extern void func_0043c180();
extern s32 func_0043c230();
extern s32 func_0043c3b0();
extern void func_0043f810();
extern s32 func_00454a60();
extern void func_00454bd0();
extern s32 func_004553c0();
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

/* measured: retail func_0045b7c0 rematerializes the per-slot base address
   (lui/addiu/addu of D_008E4090 + i*0x44) after every call and materializes
   store-address registers before calls (addiu $17/$18/$19, slot+0x4/0xC/0x2C/0x30,
   including slot+0x10 reuse for case 8); mwcc b210 CSEs the slot address across
   the calls, keeps it in one callee-saved register, and emits direct lw/sw
   field offsets, producing a structurally leaner object (1908-2536B vs retail
   2416B) with a rotated saved-register set (i in $s5 vs $s4, 7 vs 9 saved regs,
   frame 0x90 vs 0xC0). Tried: slot variable kept/reassigned per case, byte-
   array D_008E4090[i*0x44+k] expressions, SFD() macro per-use expressions,
   split symbols (sSfdDecodeSlots_abs dispatch vs D_008E4090 recomputes),
   declaration-order permutations. Register-allocation/rematerialization floor,
   best nd 1351. */
// FUN_0045B7C0
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045b7c0);
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

/* measured: retail func_0045c640 materializes the outputHandle load (lw $a0)
   BEFORE the s16 argument sign-extensions (dsll32/dsra32 of $s6/$s7) at the
   final func_0043c518 call; mwcc b210 always emits the extensions first,
   then the (sunk) load, in every source form tried (inline load, hoisted
   local, s32 promotion locals, explicit (s16) casts, #pragma schedule on
   which additionally reordered the prologue). Argument-materialisation /
   load-sinking floor, nd 15 (5 words). */
// FUN_0045C640
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045c640);
