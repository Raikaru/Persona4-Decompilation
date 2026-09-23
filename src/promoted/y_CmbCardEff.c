/* Consolidated Persona 4 source units. */
/* Original translation unit y_CmbCardEff.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_color.h"
#include "type.h"
#include "effect_update_internal.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "fcl_draw_task.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);
typedef struct { f32 x, y, z; } CmbVec3f;
typedef struct { f32 x, y; } CmbVec2f;
typedef FclDrawColor CmbRGBA;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    CmbVec2f a0, a8;
    CmbVec3f b0;
    u32 pad_bc;
    CmbVec2f c0, c8, d0, d8, e0;
    u32 pad_e8;
    union {
        u8 bytes[0x20];
        struct { FclDrawColor c000, c004, c008, c00C, c010, c014, c018, c01C; } colors;
    } storage;
} CmbFc80Work;
typedef CmbVec2f CmbWorkPair;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    CmbWorkPair pA0, pA8, pB0, pB8, pC0, pC8;
    CmbVec3f d0;
    u32 pad_dc;
    CmbWorkPair pE0, pE8, pF0, pF8, p100, p108, p110, p118, p120;
    union {
        u8 bytes[0x2c];
        struct { FclDrawColor c000, c004, c008, c00C, c010, c014, c018, c01C, c020, c024, c028; } colors;
    } storage;
} Cmb407Work;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    CmbWorkPair pA0, pA8, pB0, pB8, pC0, pC8, pD0, pD8,
                pE0, pE8, pF0;
    CmbVec3f vecF8;
    u32 pad104;
    CmbWorkPair p108, p110, p118, p120, p128, p130, p138, p140,
                p148, p150, p158, p160, p168, p170;
    union {
        u8 bytes[0x34];
        struct { FclDrawColor c000, c004, c008, c00C, c010, c014, c018, c01C, c020, c024, c028, c02C, c030; } colors;
    } storage;
} Cmb416Work;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    union {
        u8 bytes[0x174];
        struct { FclDrawColor c000, c004, c008, c00C, c010, c014, c018, c01C, c020, c024, c028, c02C, c030, c034, c038, c03C, c040, c044, c048, c04C, c050, c054, c058, c05C, c060, c064, c068, c06C, c070, c074, c078, c07C, c080, c084, c088, c08C, c090, c094, c098, c09C, c0A0, c0A4, c0A8, c0AC, c0B0, c0B4, c0B8, c0BC, c0C0, c0C4, c0C8, c0CC, c0D0, c0D4, c0D8, c0DC, c0E0, c0E4, c0E8, c0EC, c0F0, c0F4, c0F8, c0FC, c100, c104, c108, c10C, c110, c114, c118, c11C, c120, c124, c128, c12C, c130, c134, c138, c13C, c140, c144, c148, c14C, c150, c154, c158, c15C, c160, c164, c168, c16C, c170; } colors;
    } storage;
} Cmb427Work;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    f32 fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4, fc8, fcc;
    f32 fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0, ff4, ff8, ffc;
    f32 f100, f104, f108, f10c, f110, f114, f118, f11c, f120, f124;
    f32 f128, f12c, f130, f134, f138, f13c, f140, f144, f148, f14c;
    union {
        u8 bytes[0x13c];
        struct { FclDrawColor c000, c004, c008, c00C, c010, c014, c018, c01C, c020, c024, c028, c02C, c030, c034, c038, c03C, c040, c044, c048, c04C, c050, c054, c058, c05C, c060, c064, c068, c06C, c070, c074, c078, c07C, c080, c084, c088, c08C, c090, c094, c098, c09C, c0A0, c0A4, c0A8, c0AC, c0B0, c0B4, c0B8, c0BC, c0C0, c0C4, c0C8, c0CC, c0D0, c0D4, c0D8, c0DC, c0E0, c0E4, c0E8, c0EC, c0F0, c0F4, c0F8, c0FC, c100, c104, c108, c10C, c110, c114, c118, c11C, c120, c124, c128, c12C, c130, c134, c138; } colors;
    } storage;
} Cmb43Work;
typedef struct {
    FclBoundsPacket fifthEndBounds;
    FclBoundsPacket fifthStartBounds;
    FclBoundsPacket fourthEndBounds;
    FclBoundsPacket fourthStartBounds;
    FclBoundsPacket thirdEndBounds;
    FclBoundsPacket thirdStartBounds;
    FclBoundsPacket secondEndBounds;
    FclBoundsPacket secondStartBounds;
    FclBoundsPacket firstEndBounds;
    FclBoundsPacket firstStartBounds;
    FclBoundsPacket initialBounds;
    FclPackedPosition fifthEndPosition;
    FclPackedPosition fifthStartPosition;
    FclPackedPosition fourthEndPosition;
    FclPackedPosition fourthStartPosition;
    FclPackedPosition thirdEndPosition;
    FclPackedPosition thirdStartPosition;
    FclPackedPosition secondEndPosition;
    FclPackedPosition secondStartPosition;
    FclPackedPosition firstEndPosition;
    FclPackedPosition firstStartPosition;
    FclPackedPosition initialPosition;
    FclPackedPosition spawnPosition;
} CmbFiveSpriteSetup;

static inline u8 *cmbAddPtrRev(u32 base, u32 index) { return (u8 *)(index + base); }

void func_0044ea90(void *arg0, u32 arg1);

struct HCdvd;
s32 func_00440b68(const char *format, ...);
u8 *func_00454a60(u8 *arg0, s32 arg1);
s32 func_00348330(u8 *arg0);
s32 func_00348c40(u8 *arg0);
u32 H_Cdvd_IsFileLoaded(struct HCdvd *ptr);
void func_004b1150(u32 arg0);
u32 H_Cdvd_Destroy(struct HCdvd *ptr);
void func_0036d940(void *arg0);
void func_0036d860(u8 *arg0, s32 arg1);
void func_0036d230(u8 *arg0);
s32 func_0036d960(void);
void func_0036da40(u8 *arg0, s32 arg1);
s32 func_00347c70(u8 *arg0);
u8 *func_00348160(u8 *arg0, s32 *arg1);
void *func_00348290(u8 *arg0);
void func_003482a0(u8 *arg0, u8 arg1, u8 arg2, u16 arg3);
void func_003482d0(u8 *arg0, CmbVec2f arg1, CmbVec2f arg2, u16 arg3);
void func_003489c0(u8 *arg0, CmbVec3f *src, f32 f0, f32 f1, f32 f2, f32 f3, CmbRGBA col, u16 arg3, u32 arg4);
void func_00348a90(u8 *arg0, CmbVec3f *src1, CmbRGBA arg2, u16 arg3, u32 arg4, CmbVec3f *src2, CmbRGBA arg6, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7);
s32 *func_00331620(void);
void RpSkyRenderStateSet(u32 arg0, u32 arg1);
struct RtQuat;
struct RwV3d;
struct RtQuat *func_003dc740(struct RtQuat *rotation, const struct RwV3d *axis,
                           f32 angle, s32 mode);
void func_0036de20(void *arg0, void *arg1);
void func_0036dd10(void *arg0, void *arg1, f32 arg2);
s32 func_00285b30(void);
f32 func_002b2aa0(s64, f32, f32, f32, f32);
s32 func_002b2cb0(s32, s32, s32, s32, s8);
s32 func_00457120(void);
u8 *func_00461390(void *list, s32 primitive, void *vertices, s32 count);
extern f32 iGpffff8360;
extern f32 iGpffff8508;
extern f32 iGpffff850c;
extern f32 D_008872F8[];
extern u8 D_00794F00[];
s32 datGetFlag(s32 id);
void func_00106390(s32, s32);
void func_002b2970(u8 *out, f32 x, f32 y);
void func_002b29a0(u8 *arg0, f32 f0, f32 f1, f32 f2);
u8 func_0045aeb0(s16 channelIndex, u8 *name);
s32 func_00452490(s32 handle);
extern u8 D_0064A5B0[];
s16 func_002b2d00(s32, s32, s32, s32, s32);
s32 func_004b1130(s32);
s32 func_004b11b0(s32);

void func_004b11d0(s32, s32);
void func_004b1250(s32, u8 *);
void func_004b1290(s32, f32, f32, f32);
void func_004b13d0(s32, f32);
void func_004b13f0(s32, u8 *);
s32 func_004b1520(s32);
extern u8 D_005DC7D0[];



void func_002b6130(u8 *, u32);
void func_002b5e20(u8 *, f32);



extern u8 D_0064E590[];
extern u8 D_0064A4A0[];
extern u8 D_0064A5E8[];
extern u8 D_0064A600[];
extern u8 D_0064A5D0[];
extern u8 D_0064A4E0[];
extern u8 D_0064A4B0[];
extern u8 D_0064A500[];
extern u8 D_0064A520[];
extern u8 D_0064A540[];
extern u8 D_0064A560[];
extern u8 D_0064A580[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
s32 func_0033e810(u8 *arg0);
s32 func_0033e5c0(u8 *arg0);
u8 *func_003488d0(u8 *arg0, u8 *arg1, s8 arg2);
/* Retail's six-byte "%s %d" diagnostic format, addressed at GP - 0x56C8. */
extern char D_00763A28[6];
extern s64 D_0064A5A0[];
extern f32 D_0064A5A8[];
extern void (*D_00887300[])(s32, s32);



typedef struct { u8 data[0xFB0]; } CmbLoaderCard;
typedef struct {
    s8 state;
    u8 reserved01;
    u16 ids[12];
    u8 reserved1a[2];
    u8 *file;
    u8 environment[0x2738];
    CmbLoaderCard cards[2][12];
    s8 loaded;
    u8 reserved_end[3];
} CmbLoaderState;
typedef char CmbLoaderSizeCheck[sizeof(CmbLoaderState) == 0x19FDC ? 1 : -1];

/* Both twelve-card banks share the caller-owned ID slots. Reload the
 * second ID after initialization, which can update caller-visible state. */
// FUN_0033E5C0
#pragma push
#pragma opt_propagation off
s32 func_0033e5c0(u8 *arg0) {
    s16 i;
    CmbLoaderState *obj;
    s8 type;

    obj = *(CmbLoaderState **)(arg0 + 0x38);
    type = obj->state;
    if (type != 4) {
        switch (type) {
        case 0:
            func_0036d860(obj->environment, 0);
            func_00440b68((const char *)D_00763A28, D_0064A4A0, 0x63);
            obj->file = func_00454a60(D_0064E590, 0);
            obj->state += 1;
            break;
        case 1:
            if (H_Cdvd_IsFileLoaded((struct HCdvd *)obj->file) != 0) {
                func_0036d230(*(u8 **)(obj->file + 0x110));
                H_Cdvd_Destroy((struct HCdvd *)obj->file);
                obj->state += 1;
            }
            break;
        case 2:
            for (i = 0; i < 0xC; i++) {
                if (*(u16 *)((u8 *)obj + (s32)i * 2 + 2) == 0)
                    goto next_card;
                func_0036da40((u8 *)&obj->cards[0][i],
                              *(u16 *)((u8 *)obj + (s32)i * 2 + 2));
                {
                    CmbLoaderCard *second;
                    s32 id;
                    second = &obj->cards[1][i];
                    id = *(u16 *)((u8 *)obj + (s32)i * 2 + 2);
                    func_0036da40((u8 *)second, id);
                }
                obj->loaded += 1;
            next_card:
                ;
            }
            obj->state += 1;
            break;
        case 3:
            if (func_0036d960() != 0) {
                obj->state += 1;
            }
            break;
        }
    }
    return 0;
}

#pragma pop
// FUN_0033E7C0
void func_0033e7c0(u8 *arg0) {
    func_0036d940((u8 *)(*(u8 **)(arg0 + 0x38)) + 0x20);
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* measured: rule 1 refined — the three `ldr $6,0($18/30)/ldl $6,7(...)` pairs (s64
   args to func_0033fc00/0033fb10/0033fb90 at pointer = slot+0x20, disp 0 but base is
   4-mod-8 via the 0x84 stride) come from CmbVec2f BY-VALUE args: probe-verified
   `*(CmbVec2f *)p` at disp 0 emits ldr/ldl while `*(s64 *)p` at disp 0 emits plain ld
   (and `*(s64 *)(p+0x2C)` emits ldr/ldl per the brief's rule). The func_0033fc00 arg3
   `*(CmbVec2f *)(slot + b*0xC + 0x2C)` and s16 arg4 match too. Full-function match
   blocked by the same stack-alloc/register wall as func_0033fc80 (0x84-stride state
   machine, 970-line dispatcher). */
/* measured: cold reconstruction banked 806 (reloc-masked), retail 912 instrs / object 896 instrs (1.8% inside 3% gate), 166 fnalign edits +6 reloc-only. v1 817 (912/804, 11.8% short: hoisted slot/c, shared rgba, plain 0xFB0) -> v3 810 (912/895, 1.9%: unhoisted per-use obj+k*0x84 and (s8)k, separate rgba0/rgba1, block-scope true protos for 4-arg 003dc740 and 3-arg 0033fa30, D_00794E70/EA0 and D_0064A4C8/D_0064A4D0 externs) -> v3_loopinv 806 (912/896) with #pragma opt_loop_invariants on. Pragmas: commons off 1256 regress, unroll off 810 tie, schedule off 810 tie. Colour: register obj 806 tie, reversed decl order 806 tie. Residual: stack-alloc (frame -0x160 vs -0x170, sp 0x138->0x158, 0x154->0x16C), saved-reg rotation (s2/s3, s1/s2), RGBA lbu/sb interleave vs pairs, D_0064A4C8/D0 lui+ld/lwc1 vs gp ld. m2c plus romwright base, CmbVec2f by-value for 0033fc00 per prior note. */
/* 2026-09-18 `tools/solve_signedness.py`: the read at `obj + k*0x84 + 0xC`
   was `u8` where retail loads it signed; flipping it took the census
   mismatch from 21 to 7 with the instruction count unchanged.  The word
   score stays 806 because those positions already differ for other reasons -
   the census is the objective for signedness, not the score.  Two tables,
   D_00794E70 and D_00794EA0, are free: both spellings compile identically,
   so their signedness is unobservable here and should not be churned. */
// FUN_0033E810 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
s32 func_0033e810(u8 *arg0) {
    void func_0033fa30(u8 *, s8, f32);
    void func_0033fb10(u8 *, s8, s64);
    void func_0033fb90(u8 *, s8, s64, f32);
    void func_0033fc00(u8 *, s8, CmbVec2f, CmbVec2f, u16);
    s32 func_0033fc80(u8 *);
    s32 func_003407f0(u8 *);
    s32 func_00341640(u8 *);
    s32 func_003427a0(u8 *);
    s32 func_00343cf0(u8 *);
    void func_00347940(u8 *);
    s32 func_00348be0(u8 *);
    void func_0036de20(void *, void *);
    void func_0036de40(void *, void *);
    void func_0036df90(void *, void *);
    extern s64 D_0064A4C8;
    extern f32 D_0064A4D0;
    extern u8 D_00794E70[];
    extern u8 D_00794EA0[];
    u8 *obj;
    s16 i;
    s16 j;
    s16 k;
    s64 tmp;
    u8 rgba0[4];
    u8 cpy0[4];
    u8 rgba1[4];
    u8 cpy1[4];
    s64 st64;
    f32 stf;
    u8 buf[24];
    u8 cv;
    f32 f0;
    f32 f20save;
    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(*(u8 **)(obj + 4) + 0x38) != 4) {
        return 0;
    }
    if (func_00285b30() >= 1000 && func_00285b30() < 1011) {
        func_00106390(0x5C, 0);
    }
    switch (*(s8 *)obj) {
    case 0:
        if (func_00348be0(*(u8 **)(obj + 0x64C)) == 0) {
            return 0;
        }
        for (i = 0; i < *(s8 *)(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + 0x19FD8); i++) {
            func_002b2970((u8 *)(&tmp), 0.0f, 0.0f);
            func_0033fb10(arg0, (s8)i, tmp);
            func_0033fa30(arg0, (s8)i, 0.0f);
            fclWriteColorBytes(rgba0, 0xFF, 0xFF, 0xFF, 0);
            cpy0[0] = rgba0[0];
            cpy0[1] = rgba0[1];
            cpy0[2] = rgba0[2];
            cpy0[3] = rgba0[3];
            func_0036de40(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)i * 0xFB0 + 0xE398, cpy0);
            *(f32 *)(obj + (s32)i * 0x84 + 0x8C) = 1.0f;
            st64 = D_0064A4C8;
            stf = D_0064A4D0;
            func_003dc740((struct RtQuat *)buf, (const struct RwV3d *)&st64, 180.0f, 0);
            func_0036de20(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)i * 0xFB0 + 0xE398, buf);
        }
        *(s16 *)(obj + 0x63C) = 0;
        *obj = *(obj + 0x63E);
        func_00347940(arg0);
        break;
    case 1:
        func_0033fc80(arg0);
        break;
    case 2:
        func_003407f0(arg0);
        break;
    case 3:
        func_00341640(arg0);
        break;
    case 4:
        func_003427a0(arg0);
        break;
    case 5:
        func_00343cf0(arg0);
        break;
    case 6:
        for (j = 0; j < *(s8 *)(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + 0x19FD8); j++) {
            *(f32 *)(obj + (s32)j * 0x84 + 0x8C) = 0.75f;
        }
        func_00345700(arg0);
        break;
    case 7:
        return -1;
    }
    if (*(s16 *)(obj + 0x63C) == 9 && func_00285b30() < 490) {
        f20save = func_002b2aa0(0, *(f32 *)(obj + 0x8C), *(f32 *)(obj + 0x8C) + 0.125f, (f32)*(s16 *)(obj + 0x6BC), 60.0f);
        f0 = func_002b2aa0(1, 0.0f, 168.0f, (f32)*(s16 *)(obj + 0x6BC), 30.0f);
        cv = (u8)(s32)f0;
        *(s16 *)(obj + 0x6BC) = func_002b2cb0(*(s16 *)(obj + 0x6BC), 1, 60, 0, 2);
    }
    for (k = 0; k < *(s8 *)(obj + 0x6B9); k++) {
        if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 1) != 0) {
            *(f32 *)(obj + (s32)k * 0x84 + 0x20) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x10), *(f32 *)(obj + (s32)k * 0x84 + 0x18), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
            *(f32 *)(obj + (s32)k * 0x84 + 0x24) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x14), *(f32 *)(obj + (s32)k * 0x84 + 0x1C), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
            if (*(s16 *)(obj + (s32)k * 0x84 + 0x2A) < *(s16 *)(obj + (s32)k * 0x84 + 0x28)) {
                *(s16 *)(obj + (s32)k * 0x84 + 0x2A) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x2A), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x28), 0, 1);
            } else if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 8) == 0) {
                *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 1;
            } else {
                func_0033fc00(arg0, (s8)k, *(CmbVec2f *)(obj + (s32)k * 0x84 + 0x20), *(CmbVec2f *)(obj + (s32)*(s8 *)(obj + (s32)k * 0x84 + 0x69) * 0xC + (s32)k * 0x84 + 0x2C), *(u16 *)(obj + (s32)*(s8 *)(obj + (s32)k * 0x84 + 0x69) * 0xC + (s32)k * 0x84 + 0x34));
                *(f32 *)(obj + (s32)k * 0x84 + 0x20) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x10), *(f32 *)(obj + (s32)k * 0x84 + 0x18), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
                *(f32 *)(obj + (s32)k * 0x84 + 0x24) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x14), *(f32 *)(obj + (s32)k * 0x84 + 0x1C), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
                *(s16 *)(obj + (s32)k * 0x84 + 0x2A) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x2A), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x28), 0, 1);
                *(s8 *)(obj + (s32)k * 0x84 + 0x69) += 1;
                if (*(s8 *)(obj + (s32)k * 0x84 + 0x68) <= *(s8 *)(obj + (s32)k * 0x84 + 0x69)) {
                    *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 8;
                }
            }
        }
        func_0033fb10(arg0, (s8)k, *(s64 *)(obj + (s32)k * 0x84 + 0x20));
        if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 2) != 0) {
            *(f32 *)(obj + (s32)k * 0x84 + 0x74) = (f32)(s16)(s32)func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x6C), *(f32 *)(obj + (s32)k * 0x84 + 0x70), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x78), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x7A));
            if (*(s16 *)(obj + (s32)k * 0x84 + 0x78) < *(s16 *)(obj + (s32)k * 0x84 + 0x7A)) {
                *(s16 *)(obj + (s32)k * 0x84 + 0x78) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x78), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x7A), 0, 1);
            } else {
                *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 2;
            }
            func_0033fa30(arg0, (s8)k, *(f32 *)(obj + (s32)k * 0x84 + 0x74));
        }
        if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 4) != 0) {
            *(u8 *)(obj + (s32)k * 0x84 + 0x84) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7C), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x80), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            *(u8 *)(obj + (s32)k * 0x84 + 0x85) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7D), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x81), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            *(u8 *)(obj + (s32)k * 0x84 + 0x86) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7E), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x82), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            *(u8 *)(obj + (s32)k * 0x84 + 0x87) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7F), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x83), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            if (*(s16 *)(obj + (s32)k * 0x84 + 0x88) < *(s16 *)(obj + (s32)k * 0x84 + 0x8A)) {
                *(s16 *)(obj + (s32)k * 0x84 + 0x88) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x88), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x8A), 0, 1);
            } else {
                *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 4;
            }
            func_0036de40(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0x2758, obj + (s32)k * 0x84 + 0x84);
        }
        if (*(u8 *)(obj + (s32)k * 0x84 + 0x87) != 0 && *(obj + 0x6B8) == 0) {
            func_0036df90(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0x2758, D_00794E70);
        }
        if (*(s16 *)(obj + 0x63C) == 9 && func_00285b30() < 490 && *(obj + 0x6B8) == 0) {
            func_0033fb90(arg0, (s8)k, *(s64 *)(obj + (s32)k * 0x84 + 0x20), f20save);
            fclWriteColorBytes(rgba1, 0xFF, 0xFF, 0xFF, cv);
            cpy1[0] = rgba1[0];
            cpy1[1] = rgba1[1];
            cpy1[2] = rgba1[2];
            cpy1[3] = rgba1[3];
            func_0036de40(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0xE398, cpy1);
            func_0036df90(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0xE398, D_00794EA0);
        }
    }
    return 0;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033e810);
#endif

// FUN_0033F660
void func_0033f660(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* measured: MATCHED this wave — the recorded nd-22 copy-loop rotation floor is broken
   by three spellings together: (1) recipe B (u32 cast base `u32 base = (u32)D_008873F4;`
   + per-call `((u8 *(*)(s32,s32,s32))*(u32 *)base)()`) for the saved-$20 lui/addiu
   base hoist (typed-pointer local and array spelling still fold to per-call lui/lw);
   (2) `ret` declared FIRST (before blk1/base) — any other order puts ret in $s0 and
   blk1 in $s1, retail has ret=$s1/blk1=$s0, a pure 40-word rotation; (3) a SEPARATE
   `s16 j` counter for the second 0x84-stride loop — reusing i makes b210 pick $a2
   where retail's second loop counter is $a0 (the first loop holds $a2). nd path:
   68 (plain array spelling) -> 40 (recipe B) -> 8 (ret-first) -> 0 (separate j).
   Callbacks func_0033e810/0033e5c0 need file-scope prototypes for the arg passing. */
// FUN_0033F690
u8 *func_0033f690(u8 *arg0, u8 *arg1, s8 arg2) {
    u8 *ret;
    u8 *blk1;
    u32 base;
    u8 *blk2;
    u8 *ret2;
    s16 i;
    s16 j;
    func_0044ea90(D_0064A4A0, 0x1B8);
    base = (u32)D_008873F4;
    blk1 = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x6E0, 0x40000);
    ret = (u8 *)(s32)func_00451fc0((void *)(arg0), (const void *)(D_0064A4E0), 0xF, 0, 0, func_0033e810, func_0033f660, (u8 *)(blk1));
    func_0044ea90(D_0064A4A0, 0xAD);
    blk2 = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x19FDC, 0x40000);
    ret2 = (u8 *)(s32)func_00451fc0((void *)(ret), (const void *)(D_0064A4B0), 0xF, 0, 0, func_0033e5c0, func_0033e7c0, (u8 *)(blk2));
    for (i = 0; i < 0xC; i++) {
        *(s16 *)(blk2 + 2 + (s32)i * 2) = *(s16 *)(arg1 + (s32)i * 2);
    }
    *(u8 *)(blk2 + 0) = 0;
    *(u8 *)(blk2 + 0x19FD8) = 0;
    *(u32 *)(blk1 + 4) = (u32)ret2;
    for (j = 0; j < 0xC; j++) {
        *(s8 *)(blk1 + (s32)j * 0x84 + 0xC) = 0;
    }
    *(s8 *)(blk1 + 0) = 0;
    *(s8 *)(blk1 + 0x63E) = arg2;
    *(s8 *)(blk1 + 8) = 0;
    *(s8 *)(blk1 + 1) = 0;
    *(s8 *)(blk1 + 0x6B8) = 0;
    switch (arg2) {
    case 1:
        *(s8 *)(blk1 + 0x6B9) = 2;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A500, 6);
        break;
    case 2:
        *(s8 *)(blk1 + 0x6B9) = 3;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A520, 6);
        break;
    case 3:
        *(s8 *)(blk1 + 0x6B9) = 4;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A540, 6);
        break;
    case 4:
        *(s8 *)(blk1 + 0x6B9) = 5;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A560, 6);
        break;
    case 5:
        *(s8 *)(blk1 + 0x6B9) = 6;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A580, 6);
        break;
    case 6:
        *(s8 *)(blk1 + 0x6B9) = 0xC;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A580, 6);
        break;
    }
    func_00106390(0x58, 0);
    func_00106390(0x59, 0);
    func_00106390(0x5A, 0);
    func_00106390(0x5B, 0);
    func_00106390(0x5C, 0);
    func_00106390(0x5D, 0);
    func_00106390(0x5E, 0);
    func_00106390(0x5F, 0);
    return ret;
}
// FUN_0033FA20
void *func_0033fa20(u8 *arg0) {
    return *(void **)(arg0 + 0x38);
}

/* The angle arrives in the independent floating-point argument register and
 * is forwarded to the quaternion constructor before the draw scale is formed.
 * The task callback caller supplies zero or its current animation angle.
 * Native b210 -O2 remains 224/224 bytes; contract and controlled-provider proof:
 * docs/probe_archive/yCmb_angle_forwarding_20260922.md. */
// FUN_0033FA30
#pragma push
/* measured: opt_propagation off keeps &sp40 in $a1 before the D_0064A5A0/D_0064A5A8
   staging loads and the p84 multiply below the arg0 chain (the "scheduler-CSE floor"
   above was propagation, not scheduling). */
#pragma opt_propagation off
void func_0033fa30(u8 *arg0, s8 arg1, f32 angle) {
    struct { f32 sp30[4]; s64 sp40; f32 sp48; } sp;
    s64 txy;
    f32 tz;
    f32 *p40;
    u8 *obj;
    u8 *table;
    u8 *pFB0;
    u8 *arg0_for_dd;
    u8 *p84;

    obj = *(u8 **)(arg0 + 0x38);
    p40 = (f32 *)&sp.sp40;
    txy = D_0064A5A0[0];
    tz = *(f32 *)&D_0064A5A0[1];
    sp.sp40 = txy;
    sp.sp48 = tz;
    func_003dc740((struct RtQuat *)&sp.sp30, (const struct RwV3d *)p40, angle, 0);
    table = *(u8 **)(*(u8 **)(obj + 4) + 0x38);
    if ((s8)*table == 4) {
        pFB0 = table + (s32)arg1 * 0xFB0;
        arg0_for_dd = pFB0 + 0x2758;
        p84 = obj + (s32)arg1 * 0x84;
        func_0036dd10(arg0_for_dd, p84 + 0x20, 90.0f * *(f32 *)(p84 + 0x8C));
        func_0036de20(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)arg1 * 0xFB0 + 0x2758, &sp.sp30);
    }
}
#pragma pop

// FUN_0033FB10
void func_0033fb10(u8 *arg0, s8 arg1, s64 arg2) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    u32 scaled = (s32)arg1 * 0x84;
    func_0036dd10((u8 *)(*(u32 *)(*(u8 **)(obj + 4) + 0x38) + (s32)arg1 * 0xFB0 + 0x2758), &arg2, 90.0f * *(f32 *)(scaled + (u32)obj + 0x8C));
}
/* measured: MATCHED this wave. The nd-8 candidate had the correct 0xFB0 stride,
   stack s64 argument, and 90.0f scaling, but fndiff showed the final 0xE398
   address operation after the float setup (`lui/mtc1/nop/mul.s`) and with the
   wrong intermediate destination register. Applying the matching guide's
   pointer-typed staging lever — first compute `tmp = ptr + 0xE398`, then cast
   that pointer through a u32 local before the call — forces retail's
   `ori $at,$zero,0xE398; addu $a0,$v0,$at` before the float setup. The residual
   changed from 8 words (obj 108B/window 112B) to padding-only nd 1, and scoped
   lverify reports MATCH (normalized_diff 0). */
// FUN_0033FB90
void func_0033fb90(u8 *arg0, s8 arg1, s64 arg2, f32 fparg0) {
    s64 sp18;
    u8 *obj;
    u8 *table;
    u32 scaled;
    u8 *ptr;
    u8 *tmp;
    u32 dst;

    sp18 = arg2;
    obj = *(u8 **)(arg0 + 0x38);
    table = *(u8 **)(*(u8 **)(obj + 4) + 0x38);
    scaled = (s32)arg1 * 0xFB0;
    ptr = table + scaled;
    tmp = ptr + 0xE398;
    dst = (u32)tmp;
    func_0036dd10((u8 *)dst, &sp18, 90.0f * fparg0);
}
/* measured: MATCHED this wave — the old nd-1 "load-sinking + addu-order floor" is broken by
   lever 3 + opt_propagation: the inline helper cmbAddPtrRev carries the index-first addu
   (`addu $a0,$v1,$a2` vs the old base-first `addu $a0,$a2,$v1`) through its parameters,
   and `#pragma opt_propagation off` forces the single-use base load early into $a2
   (helper alone: nd 9, load sinks to $v1 and the sign-ext chain shifts to $a1;
   pragma alone on the plain expression: nd 3, still base-first addu). */
// FUN_0033FC00
#pragma opt_propagation off /* measured: see above; forces the base load early (lw $a2,0x38($a0) first) */
void func_0033fc00(u8 *arg0, s8 arg1, CmbVec2f arg2, CmbVec2f arg3, u16 arg4) {
    u8 *p = cmbAddPtrRev((u32)*(u8 **)(arg0 + 0x38), (u32)((s32)arg1 * 0x84));
    *(CmbVec2f *)(p + 0x20) = arg2;
    *(CmbVec2f *)(p + 0x10) = *(CmbVec2f *)(p + 0x20);
    *(CmbVec2f *)(p + 0x18) = arg3;
    *(u16 *)(p + 0x2A) = 0;
    *(u16 *)(p + 0x28) = arg4;
    *(s8 *)(p + 0xC) |= 1;
}
#pragma opt_propagation on
// FUN_0033FC80
s32 func_0033fc80(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *obj;
    CmbFc80Work work;
    FclDrawColor colorSource040, colorSource03C, colorSource038, colorSource034, colorSource030, colorSource02C, colorSource028, colorSource024, colorSource020;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 value;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 2) {
            colorSource03C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c018 = colorSource03C;
            colorSource040 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c01C = colorSource040;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) = work.storage.colors.c01C;
            *(CmbRGBA *)(slot + 0x7C) = *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) = work.storage.colors.c018;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 && func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970((u8 *)(&work.d8), 230.0f, 212.0f);
            *(CmbVec2f *)&work.f90 = *(CmbVec2f *)&work.d8;
            func_002b2970((u8 *)(&work.e0), 10.0f, 212.0f);
            *(CmbVec2f *)&work.f98 = *(CmbVec2f *)&work.e0;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) = *(CmbVec2f *)&work.f98;
            *(CmbVec2f *)(slot + 0x10) = *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) = *(CmbVec2f *)&work.f90;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            colorSource034 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c010 = colorSource034;
            colorSource038 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c014 = colorSource038;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) = work.storage.colors.c014;
            *(CmbRGBA *)(slot + 0x7C) = *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) = work.storage.colors.c010;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970((u8 *)(&work.c8), 230.0f, 212.0f);
            *(CmbVec2f *)&work.f80 = *(CmbVec2f *)&work.c8;
            func_002b2970((u8 *)(&work.d0), 10.0f, 212.0f);
            *(CmbVec2f *)&work.f88 = *(CmbVec2f *)&work.d0;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) = *(CmbVec2f *)&work.f88;
            *(CmbVec2f *)(slot + 0x94) = *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) = *(CmbVec2f *)&work.f80;
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 5;
            *(s8 *)(slot + 0x90) |= 1;
            colorSource02C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c008 = colorSource02C;
            colorSource030 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c00C = colorSource030;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) = work.storage.colors.c00C;
            *(CmbRGBA *)(slot + 0x100) = *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) = work.storage.colors.c008;
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970((u8 *)(&work.c0), 0x19F, 212.0f);
            *(CmbVec2f *)&work.f78 = *(CmbVec2f *)&work.c0;
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) = *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) = func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 2) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x3C);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0((u8 *)&work.b0, 0.0f, 5.0f, 30.0f);
        colorSource028 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C), &work.b0,
                      0.0f, 0.0f, 0.0f, 1.0f,
                      colorSource028, 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 2) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 2) {
                func_002b2970((u8 *)(&work.a8), 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 = *(CmbVec2f *)&work.a8;
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) = *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) = *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) = *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                func_002b2970((u8 *)(&work.a0), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)&work.a0, 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        i10 = 0;
        while (i10 < 2) {
            colorSource020 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c000 = colorSource020;
            colorSource024 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c004 = colorSource024;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) = work.storage.colors.c004;
            *(CmbRGBA *)(slot + 0x7C) = *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) = work.storage.colors.c000;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(u8 *)(obj + 0x6B8) = 1;
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 && func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_003407F0
s32 func_003407f0(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb407Work work;
    FclDrawColor colorSource054, colorSource050, colorSource04C, colorSource048, colorSource044, colorSource040, colorSource03C, colorSource038, colorSource034, colorSource030, colorSource02C;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 3) {
            colorSource050 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c024 =
                colorSource050;
            colorSource054 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c028 =
                colorSource054;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c028;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c024;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970((u8 *)(&work.p118), 185.0f, 297.0f);
            work.pB0 = work.p118;
            func_002b2970((u8 *)(&work.p120), -86.0f, 297.0f);
            work.pB8 = work.p120;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) = work.pB8;
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) = work.pB0;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            colorSource048 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c01C =
                colorSource048;
            colorSource04C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c020 =
                colorSource04C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c020;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c01C;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970((u8 *)(&work.p108), 185.0f, 297.0f);
            work.pA0 = work.p108;
            func_002b2970((u8 *)(&work.p110), -86.0f, 297.0f);
            work.pA8 = work.p110;
            slot2 = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot2 + 0xA4) = work.pA8;
            *(CmbVec2f *)(slot2 + 0x94) =
                *(CmbVec2f *)(slot2 + 0xA4);
            *(CmbVec2f *)(slot2 + 0x9C) = work.pA0;
            *(s16 *)(slot2 + 0xAE) = 0;
            *(s16 *)(slot2 + 0xAC) = 5;
            *(s8 *)(slot2 + 0x90) |= 1;
            colorSource040 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c014 =
                colorSource040;
            colorSource044 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c018 =
                colorSource044;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                work.storage.colors.c018;
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                work.storage.colors.c014;
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970((u8 *)(&work.p100), 456.0f, 297.0f);
            *(CmbVec2f *)&work.f98 = work.p100;
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) =
                *(CmbVec2f *)&work.f98;
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970((u8 *)(&work.pF0), 185.0f, 297.0f);
            *(CmbVec2f *)&work.f88 = work.pF0;
            func_002b2970((u8 *)(&work.pF8), -86.0f, 297.0f);
            *(CmbVec2f *)&work.f90 = work.pF8;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) =
                *(CmbVec2f *)&work.f90;
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 5;
            *(s8 *)(slot + 0x114) |= 1;
            colorSource038 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c00C =
                colorSource038;
            colorSource03C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c010 =
                colorSource03C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                work.storage.colors.c010;
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                work.storage.colors.c00C;
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 5;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970((u8 *)(&work.pE8), 456.0f, 297.0f);
            *(CmbVec2f *)&work.f80 = work.pE8;
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((u8 *)(&work.pE0), 320.0f, 104.0f);
            *(CmbVec2f *)&work.f78 = work.pE0;
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x170);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot + 0x114) |= 8;
            *(s8 *)(slot + 0x170) =
                func_002b2cb0(*(s8 *)(slot + 0x170), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 3) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0((u8 *)&work.d0, 0.0f, -5.0f, 30.0f);
        colorSource034 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C), &work.d0,
                      0.0f, 0.0f, 0.0f, iGpffff8360,
                      colorSource034, 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 3) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 3) {
                func_002b2970((u8 *)(&work.pC8), 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 = work.pC8;
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot);
                func_002b2970((u8 *)(&work.pC0), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              work.pC0, 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 3) {
            colorSource02C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c004 =
                colorSource02C;
            colorSource030 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c008 =
                colorSource030;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c008;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c004;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(u8 *)(obj + 0x6B8) = 1;
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_00341640
s32 func_00341640(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb416Work work;
    FclDrawColor colorSource064, colorSource060, colorSource05C, colorSource058, colorSource054, colorSource050, colorSource04C, colorSource048, colorSource044, colorSource040, colorSource03C, colorSource038, colorSource034;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    s32 index3;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 4) {
            colorSource060 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c02C =
                colorSource060;
            colorSource064 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c030 =
                colorSource064;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c030;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c02C;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970((u8 *)(&work.p168), 188.0f, 217.0f);
            work.pD8 = work.p168;
            func_002b2970((u8 *)(&work.p170), -82.0f, 217.0f);
            work.pE0 = work.p170;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) = work.pE0;
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) = work.pD8;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            colorSource058 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c024 =
                colorSource058;
            colorSource05C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c028 =
                colorSource05C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c028;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c024;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970((u8 *)(&work.p158), 188.0f, 217.0f);
            work.pC8 = work.p158;
            func_002b2970((u8 *)(&work.p160), -82.0f, 217.0f);
            work.pD0 = work.p160;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) = work.pD0;
            *(CmbVec2f *)(slot + 0x94) =
                *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) = work.pC8;
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 5;
            *(s8 *)(slot + 0x90) |= 1;
            colorSource050 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c01C =
                colorSource050;
            colorSource054 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c020 =
                colorSource054;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                work.storage.colors.c020;
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                work.storage.colors.c01C;
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970((u8 *)(&work.p150), 458.0f, 217.0f);
            work.pC0 = work.p150;
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) = work.pC0;
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970((u8 *)(&work.p140), 188.0f, 217.0f);
            work.pB0 = work.p140;
            func_002b2970((u8 *)(&work.p148), -82.0f, 217.0f);
            work.pB8 = work.p148;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) = work.pB8;
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) = work.pB0;
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 5;
            *(s8 *)(slot + 0x114) |= 1;
            colorSource048 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c014 =
                colorSource048;
            colorSource04C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c018 =
                colorSource04C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                work.storage.colors.c018;
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                work.storage.colors.c014;
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 5;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970((u8 *)(&work.p138), 458.0f, 217.0f);
            work.pA8 = work.p138;
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) = work.pA8;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((u8 *)(&work.p130), 323.0f, 337.0f);
            work.pA0 = work.p130;
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x170);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) = work.pA0;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot + 0x114) |= 8;
            *(s8 *)(slot + 0x170) =
                func_002b2cb0(*(s8 *)(slot + 0x170), 1, 5, 0, 1);
            func_002b2970((u8 *)(&work.p120), 188.0f, 217.0f);
            *(CmbVec2f *)&work.f90 = work.p120;
            func_002b2970((u8 *)(&work.p128), -82.0f, 217.0f);
            *(CmbVec2f *)&work.f98 = work.p128;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x1AC) =
                *(CmbVec2f *)&work.f98;
            *(CmbVec2f *)(slot + 0x19C) =
                *(CmbVec2f *)(slot + 0x1AC);
            *(CmbVec2f *)(slot + 0x1A4) =
                *(CmbVec2f *)&work.f90;
            *(s16 *)(slot + 0x1B6) = 0;
            *(s16 *)(slot + 0x1B4) = 5;
            *(s8 *)(slot + 0x198) |= 1;
            colorSource040 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c00C =
                colorSource040;
            colorSource044 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c010 =
                colorSource044;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x210) =
                work.storage.colors.c010;
            *(CmbRGBA *)(slot + 0x208) =
                *(CmbRGBA *)(slot + 0x210);
            *(CmbRGBA *)(slot + 0x20C) =
                work.storage.colors.c00C;
            *(s16 *)(slot + 0x214) = 0;
            *(s16 *)(slot + 0x216) = 5;
            *(s8 *)(slot + 0x198) |= 4;
            func_002b2970((u8 *)(&work.p118), 458.0f, 217.0f);
            *(CmbVec2f *)&work.f88 = work.p118;
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)(&work.p110), 323.0f, 337.0f);
            *(CmbVec2f *)&work.f80 = work.p110;
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)(&work.p108), 323.0f, 82.0f);
            *(CmbVec2f *)&work.f78 = work.p108;
            slot = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot + 0x1F4);
            table = cmbAddPtrRev((u32)slot, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot + 0x198) |= 8;
            *(s8 *)(slot + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot + 0x1F4), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 4) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0((u8 *)&work.vecF8, 0.0f, 5.0f, 30.0f);
        colorSource03C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C), &work.vecF8,
                      0.0f, 0.0f, 0.0f, iGpffff8360,
                      colorSource03C, 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 4) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 4) {
                func_002b2970((u8 *)(&work.pF0), 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 = work.pF0;
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot);
                func_002b2970((u8 *)(&work.pE8), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              work.pE8, 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 4) {
            colorSource034 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c004 =
                colorSource034;
            colorSource038 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c008 =
                colorSource038;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c008;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c004;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_003427A0
s32 func_003427a0(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb427Work work;
    FclDrawColor colorSource1AC, colorSource1A8, colorSource1A4, colorSource1A0, colorSource19C, colorSource198, colorSource194, colorSource190, colorSource18C, colorSource188, colorSource184, colorSource180, colorSource17C, colorSource178, colorSource174;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    s32 index3;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 ||
        *(s8 *)(obj + 0x21C) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 5) {
            colorSource1A8 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c16C =
                colorSource1A8;
            colorSource1AC = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c170 =
                colorSource1AC;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c170;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c16C;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x128)), 185.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x68) =
                *(CmbVec2f *)(work.storage.bytes + 0x128);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x130)), -95.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x70) =
                *(CmbVec2f *)(work.storage.bytes + 0x130);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) =
                *(CmbVec2f *)(work.storage.bytes + 0x70);
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) =
                *(CmbVec2f *)(work.storage.bytes + 0x68);
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            colorSource1A0 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c164 =
                colorSource1A0;
            colorSource1A4 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c168 =
                colorSource1A4;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c168;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c164;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x118)), 185.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x58) =
                *(CmbVec2f *)(work.storage.bytes + 0x118);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x120)), -95.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x60) =
                *(CmbVec2f *)(work.storage.bytes + 0x120);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) =
                *(CmbVec2f *)(work.storage.bytes + 0x60);
            *(CmbVec2f *)(slot + 0x94) =
                *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) =
                *(CmbVec2f *)(work.storage.bytes + 0x58);
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 5;
            *(s8 *)(slot + 0x90) |= 1;
            colorSource198 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c15C =
                colorSource198;
            colorSource19C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c160 =
                colorSource19C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                work.storage.colors.c160;
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                work.storage.colors.c15C;
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x110)), 465.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x50) =
                *(CmbVec2f *)(work.storage.bytes + 0x110);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) =
                *(CmbVec2f *)(work.storage.bytes + 0x50);
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x100)), 185.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x40) =
                *(CmbVec2f *)(work.storage.bytes + 0x100);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x108)), -95.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x48) =
                *(CmbVec2f *)(work.storage.bytes + 0x108);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) =
                *(CmbVec2f *)(work.storage.bytes + 0x48);
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) =
                *(CmbVec2f *)(work.storage.bytes + 0x40);
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 5;
            *(s8 *)(slot + 0x114) |= 1;
            colorSource190 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c154 =
                colorSource190;
            colorSource194 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c158 =
                colorSource194;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                work.storage.colors.c158;
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                work.storage.colors.c154;
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 5;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xF8)), 465.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x38) =
                *(CmbVec2f *)(work.storage.bytes + 0xF8);
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)(work.storage.bytes + 0x38);
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xF0)), 239.0f, 343.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x30) =
                *(CmbVec2f *)(work.storage.bytes + 0xF0);
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)(work.storage.bytes + 0x30);
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xE0)), 185.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x20) =
                *(CmbVec2f *)(work.storage.bytes + 0xE0);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xE8)), -95.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x28) =
                *(CmbVec2f *)(work.storage.bytes + 0xE8);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x1AC) =
                *(CmbVec2f *)(work.storage.bytes + 0x28);
            *(CmbVec2f *)(slot + 0x19C) =
                *(CmbVec2f *)(slot + 0x1AC);
            *(CmbVec2f *)(slot + 0x1A4) =
                *(CmbVec2f *)(work.storage.bytes + 0x20);
            *(s16 *)(slot + 0x1B6) = 0;
            *(s16 *)(slot + 0x1B4) = 5;
            *(s8 *)(slot + 0x198) |= 1;
            colorSource188 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c14C =
                colorSource188;
            colorSource18C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c150 =
                colorSource18C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x210) =
                work.storage.colors.c150;
            *(CmbRGBA *)(slot + 0x208) =
                *(CmbRGBA *)(slot + 0x210);
            *(CmbRGBA *)(slot + 0x20C) =
                work.storage.colors.c14C;
            *(s16 *)(slot + 0x214) = 0;
            *(s16 *)(slot + 0x216) = 5;
            *(s8 *)(slot + 0x198) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xD8)), 465.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x18) =
                *(CmbVec2f *)(work.storage.bytes + 0xD8);
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)(work.storage.bytes + 0x18);
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xD0)), 239.0f, 343.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x10) =
                *(CmbVec2f *)(work.storage.bytes + 0xD0);
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)(work.storage.bytes + 0x10);
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xC8)), 411.0f, 343.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x8) =
                *(CmbVec2f *)(work.storage.bytes + 0xC8);
            slot = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot + 0x1F4);
            table = cmbAddPtrRev((u32)slot, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)(work.storage.bytes + 0x8);
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot + 0x198) |= 8;
            *(s8 *)(slot + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xB8)), 185.0f, 182.0f);
            *(CmbVec2f *)&work.f98 =
                *(CmbVec2f *)(work.storage.bytes + 0xB8);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xC0)), -95.0f, 182.0f);
            *(CmbVec2f *)(work.storage.bytes + 0x0) =
                *(CmbVec2f *)(work.storage.bytes + 0xC0);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x230) =
                *(CmbVec2f *)(work.storage.bytes + 0x0);
            *(CmbVec2f *)(slot + 0x220) =
                *(CmbVec2f *)(slot + 0x230);
            *(CmbVec2f *)(slot + 0x228) =
                *(CmbVec2f *)&work.f98;
            *(s16 *)(slot + 0x23A) = 0;
            *(s16 *)(slot + 0x238) = 5;
            *(s8 *)(slot + 0x21C) |= 1;
            colorSource180 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c144 =
                colorSource180;
            colorSource184 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c148 =
                colorSource184;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x294) =
                work.storage.colors.c148;
            *(CmbRGBA *)(slot + 0x28C) =
                *(CmbRGBA *)(slot + 0x294);
            *(CmbRGBA *)(slot + 0x290) =
                work.storage.colors.c144;
            *(s16 *)(slot + 0x298) = 0;
            *(s16 *)(slot + 0x29A) = 5;
            *(s8 *)(slot + 0x21C) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xB0)), 465.0f, 182.0f);
            *(CmbVec2f *)&work.f90 =
                *(CmbVec2f *)(work.storage.bytes + 0xB0);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f90;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xA8)), 239.0f, 343.0f);
            *(CmbVec2f *)&work.f88 =
                *(CmbVec2f *)(work.storage.bytes + 0xA8);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xA0)), 411.0f, 343.0f);
            *(CmbVec2f *)&work.f80 =
                *(CmbVec2f *)(work.storage.bytes + 0xA0);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x98)), 325.0f, 83.0f);
            *(CmbVec2f *)&work.f78 =
                *(CmbVec2f *)(work.storage.bytes + 0x98);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 5) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot2 = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot2 + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot2 + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0(work.storage.bytes + 0x88, 0.0f, 5.0f, 30.0f);
        colorSource17C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C),
                      (CmbVec3f *)(work.storage.bytes + 0x88),
                      0.0f, 0.0f, 0.0f, iGpffff8360,
                      colorSource17C, 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 5) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 5) {
                func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x80)), 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 =
                    *(CmbVec2f *)(work.storage.bytes + 0x80);
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x78)), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot2,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)(work.storage.bytes + 0x78), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 5) {
            colorSource174 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c13C =
                colorSource174;
            colorSource178 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c140 =
                colorSource178;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c140;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c13C;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_00343CF0
s32 func_00343cf0(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb43Work work;
    FclDrawColor colorSource17C, colorSource178, colorSource174, colorSource170, colorSource16C, colorSource168, colorSource164, colorSource160, colorSource15C, colorSource158, colorSource154, colorSource150, colorSource14C, colorSource148, colorSource144, colorSource140, colorSource13C;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 ||
        *(s8 *)(obj + 0x21C) != 0 || *(s8 *)(obj + 0x2A0) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 6) {
            colorSource178 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c134 =
                colorSource178;
            colorSource17C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c138 =
                colorSource17C;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c138;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c134;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xE8)), 321.0f, 70.0f);
            *(CmbVec2f *)&work.f140 =
                *(CmbVec2f *)(work.storage.bytes + 0xE8);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xF0)), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f148 =
                *(CmbVec2f *)(work.storage.bytes + 0xF0);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) =
                *(CmbVec2f *)&work.f148;
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) =
                *(CmbVec2f *)&work.f140;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 4;
            *(s8 *)(slot + 0xC) |= 1;
            colorSource170 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c12C =
                colorSource170;
            colorSource174 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c130 =
                colorSource174;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c130;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c12C;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 4;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xD8)), 321.0f, 70.0f);
            *(CmbVec2f *)&work.f130 =
                *(CmbVec2f *)(work.storage.bytes + 0xD8);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xE0)), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f138 =
                *(CmbVec2f *)(work.storage.bytes + 0xE0);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) =
                *(CmbVec2f *)&work.f138;
            *(CmbVec2f *)(slot + 0x94) =
                *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) =
                *(CmbVec2f *)&work.f130;
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 4;
            *(s8 *)(slot + 0x90) |= 1;
            colorSource168 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c124 =
                colorSource168;
            colorSource16C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c128 =
                colorSource16C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                work.storage.colors.c128;
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                work.storage.colors.c124;
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 4;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xD0)), 186.0f, 143.0f);
            *(CmbVec2f *)&work.f128 =
                *(CmbVec2f *)(work.storage.bytes + 0xD0);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) =
                *(CmbVec2f *)&work.f128;
            *(s16 *)(table + 0xB8) = 4;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xC0)), 321.0f, 70.0f);
            *(CmbVec2f *)&work.f118 =
                *(CmbVec2f *)(work.storage.bytes + 0xC0);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xC8)), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f120 =
                *(CmbVec2f *)(work.storage.bytes + 0xC8);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) =
                *(CmbVec2f *)&work.f120;
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) =
                *(CmbVec2f *)&work.f118;
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 4;
            *(s8 *)(slot + 0x114) |= 1;
            colorSource160 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c11C =
                colorSource160;
            colorSource164 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c120 =
                colorSource164;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                work.storage.colors.c120;
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                work.storage.colors.c11C;
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 4;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xB8)), 186.0f, 143.0f);
            *(CmbVec2f *)&work.f110 =
                *(CmbVec2f *)(work.storage.bytes + 0xB8);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f110;
            *(s16 *)(table + 0x13C) = 4;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xB0)), 186.0f, 285.0f);
            *(CmbVec2f *)&work.f108 =
                *(CmbVec2f *)(work.storage.bytes + 0xB0);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f108;
            *(s16 *)(table + 0x13C) = 4;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xA0)), 321.0f, 70.0f);
            *(CmbVec2f *)&work.ff8 =
                *(CmbVec2f *)(work.storage.bytes + 0xA0);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0xA8)), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f100 =
                *(CmbVec2f *)(work.storage.bytes + 0xA8);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x1AC) =
                *(CmbVec2f *)&work.f100;
            *(CmbVec2f *)(slot + 0x19C) =
                *(CmbVec2f *)(slot + 0x1AC);
            *(CmbVec2f *)(slot + 0x1A4) =
                *(CmbVec2f *)&work.ff8;
            *(s16 *)(slot + 0x1B6) = 0;
            *(s16 *)(slot + 0x1B4) = 4;
            *(s8 *)(slot + 0x198) |= 1;
            colorSource158 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c114 =
                colorSource158;
            colorSource15C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c118 =
                colorSource15C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x210) =
                work.storage.colors.c118;
            *(CmbRGBA *)(slot + 0x208) =
                *(CmbRGBA *)(slot + 0x210);
            *(CmbRGBA *)(slot + 0x20C) =
                work.storage.colors.c114;
            *(s16 *)(slot + 0x214) = 0;
            *(s16 *)(slot + 0x216) = 4;
            *(s8 *)(slot + 0x198) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x98)), 186.0f, 143.0f);
            *(CmbVec2f *)&work.ff0 =
                *(CmbVec2f *)(work.storage.bytes + 0x98);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.ff0;
            *(s16 *)(table + 0x1C0) = 4;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x90)), 186.0f, 285.0f);
            *(CmbVec2f *)&work.fe8 =
                *(CmbVec2f *)(work.storage.bytes + 0x90);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.fe8;
            *(s16 *)(table + 0x1C0) = 4;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x88)), 321.0f, 348.0f);
            *(CmbVec2f *)&work.fe0 =
                *(CmbVec2f *)(work.storage.bytes + 0x88);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.fe0;
            *(s16 *)(table + 0x1C0) = 4;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x78)), 321.0f, 70.0f);
            *(CmbVec2f *)&work.fd0 =
                *(CmbVec2f *)(work.storage.bytes + 0x78);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x80)), 421.0f, -43.0f);
            *(CmbVec2f *)&work.fd8 =
                *(CmbVec2f *)(work.storage.bytes + 0x80);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x230) =
                *(CmbVec2f *)&work.fd8;
            *(CmbVec2f *)(slot + 0x220) =
                *(CmbVec2f *)(slot + 0x230);
            *(CmbVec2f *)(slot + 0x228) =
                *(CmbVec2f *)&work.fd0;
            *(s16 *)(slot + 0x23A) = 0;
            *(s16 *)(slot + 0x238) = 4;
            *(s8 *)(slot + 0x21C) |= 1;
            colorSource150 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c10C =
                colorSource150;
            colorSource154 = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c110 =
                colorSource154;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x294) =
                work.storage.colors.c110;
            *(CmbRGBA *)(slot + 0x28C) =
                *(CmbRGBA *)(slot + 0x294);
            *(CmbRGBA *)(slot + 0x290) =
                work.storage.colors.c10C;
            *(s16 *)(slot + 0x298) = 0;
            *(s16 *)(slot + 0x29A) = 4;
            *(s8 *)(slot + 0x21C) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x70)), 186.0f, 143.0f);
            *(CmbVec2f *)&work.fc8 =
                *(CmbVec2f *)(work.storage.bytes + 0x70);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fc8;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x68)), 186.0f, 285.0f);
            *(CmbVec2f *)&work.fc0 =
                *(CmbVec2f *)(work.storage.bytes + 0x68);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fc0;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x60)), 321.0f, 348.0f);
            *(CmbVec2f *)&work.fb8 =
                *(CmbVec2f *)(work.storage.bytes + 0x60);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fb8;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x58)), 456.0f, 285.0f);
            *(CmbVec2f *)&work.fb0 =
                *(CmbVec2f *)(work.storage.bytes + 0x58);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fb0;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x48)), 321.0f, 70.0f);
            *(CmbVec2f *)&work.fa0 =
                *(CmbVec2f *)(work.storage.bytes + 0x48);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x50)), 421.0f, -43.0f);
            *(CmbVec2f *)&work.fa8 =
                *(CmbVec2f *)(work.storage.bytes + 0x50);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x2B4) =
                *(CmbVec2f *)&work.fa8;
            *(CmbVec2f *)(slot + 0x2A4) =
                *(CmbVec2f *)(slot + 0x2B4);
            *(CmbVec2f *)(slot + 0x2AC) =
                *(CmbVec2f *)&work.fa0;
            *(s16 *)(slot + 0x2BE) = 0;
            *(s16 *)(slot + 0x2BC) = 4;
            *(s8 *)(slot + 0x2A0) |= 1;
            colorSource148 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c104 =
                colorSource148;
            colorSource14C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c108 =
                colorSource14C;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x318) =
                work.storage.colors.c108;
            *(CmbRGBA *)(slot + 0x310) =
                *(CmbRGBA *)(slot + 0x318);
            *(CmbRGBA *)(slot + 0x314) =
                work.storage.colors.c104;
            *(s16 *)(slot + 0x31C) = 0;
            *(s16 *)(slot + 0x31E) = 4;
            *(s8 *)(slot + 0x2A0) |= 4;
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x40)), 186.0f, 143.0f);
            *(CmbVec2f *)&work.f98 =
                *(CmbVec2f *)(work.storage.bytes + 0x40);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f98;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x38)), 186.0f, 285.0f);
            *(CmbVec2f *)&work.f90 =
                *(CmbVec2f *)(work.storage.bytes + 0x38);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f90;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x30)), 321.0f, 348.0f);
            *(CmbVec2f *)&work.f88 =
                *(CmbVec2f *)(work.storage.bytes + 0x30);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x28)), 456.0f, 285.0f);
            *(CmbVec2f *)&work.f80 =
                *(CmbVec2f *)(work.storage.bytes + 0x28);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x20)), 456.0f, 143.0f);
            *(CmbVec2f *)&work.f78 =
                *(CmbVec2f *)(work.storage.bytes + 0x20);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 6) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot2 = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot2 + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot2 + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0(work.storage.bytes + 0x10, 0.0f, 5.0f, 30.0f);
        colorSource144 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C),
                      (CmbVec3f *)(work.storage.bytes + 0x10),
                      0.0f, 0.0f, 0.0f, 1.5f,
                      colorSource144, 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 6) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 6) {
                func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x8)), 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 =
                    *(CmbVec2f *)(work.storage.bytes + 0x8);
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_002b2970((u8 *)((s64 *)(work.storage.bytes + 0x0)), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot2,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)(work.storage.bytes + 0x0), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 6) {
            colorSource13C = func_002b2a60(0xFF, 0xFF, 0xFF, 0U);
            work.storage.colors.c0FC =
                colorSource13C;
            colorSource140 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU);
            work.storage.colors.c100 =
                colorSource140;
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                work.storage.colors.c100;
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                work.storage.colors.c0FC;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

/* cold target: faithful v4 (759 lines, file idioms s8/lb s16/switch s32/daddu, file-scope protos incl. new 00348a90 + iGpffff8508/850c, 104 jal/0 jalr exact, 0 unsigned (0 bltz) / 14 signed int->float via 0x141/0x143/0x153/0x16B/0x187 bare mtc1/cvt) probes 1911 differing words (reloc-masked; skeleton v1 2031), fnalign retail 2190/object 2038 (152 short, 6.9%, band 2126-2258), 997 edits +2 reloc-only, frame retail -0x3D0 vs object -0x6D0, no large pure hole/lump (52 deletes max 4-5, 1 insert; e.g. retail[198:202] 0x00345A18-0x00345A28, retail[209:213] 0x00345A44-0x00345A54, retail[302:306] 0x00345BB8-0x00345BC8). Exact: python3 tools/probe_variants.py src/promoted/y_CmbCardEff.c func_00345700 --candidate v4=/tmp/cmb45700_v4.c (1911); python3 tools/fnalign.py src/promoted/y_CmbCardEff.c func_00345700 --candidate /tmp/cmb45700_v4.c (2190/2038, 997+2, -0x3D0/-0x6D0). Production stays INCLUDE_ASM (short, do not bank). */
// checked per Main: read retail at all fourteen int->float sites first -- retail has 0 bltz, 85 mtc1, 14 cvt.s.w (bare signed); object v4 has 0 bltz, 85 mtc1, 14 cvt.s.w (identical); all fourteen genuinely signed, fix 0, count stays 2038/2190 -152 -6.9% outside 2126-2258 (applying (f32)(u32) would invent 14x11=154 bltz retail lacks, fake exact 2192 with worse words per 7u, rejected); frame preserved: object -0x6D0 vs retail -0x3D0 (+768 surplus, big buffers held where retail computes in place, attack after conversions, same story); production stays INCLUDE_ASM.
/* measured: rule 1 applies verbatim (same clone site as func_0033fc80): the single */
/* ldr $a1,0x134/ldl $a1,0x13B pair is `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), v, 3)` */
/* with ret = func_00348290 result — 8-byte by-value read at 4-mod-8 offset, verified */
/* emitting the exact pair on func_0033fc80. Not re-attempted individually: the whole */
/* 0x84-stride state-machine family shares func_0033fc80's stack-alloc floor. */
// v5 aggregate-removal alone (2026-09-19): v4->v5 retail 2190/object 2038->2038 (+0, still 152 short, 6.9%, outside band 2126-2258; predicted +162 via 50x lwc1 reappearing did NOT materialize), frame -0x6D0->-0x410 (1744->1040, -704, still +64 over retail -0x3D0=976; added 920 vs 864 target +56), words 1911->1911 (+0), edits 997->1009 (+12), jal 104/0 exact, 0 bltz; exact: python3 tools/fnalign.py src/promoted/y_CmbCardEff.c func_00345700 --candidate /tmp/cmb45700_v5.c --quiet + python3 tools/probe_variants.py src/promoted/y_CmbCardEff.c func_00345700 --candidate v5=/tmp/cmb45700_v5.c; residual 49 pure deletes (max 14 at retail[211:225] 0x00345A4C-0x00345A84, e.g. retail[198:202] 0x00345A18-0x00345A28, retail[302:306] 0x00345BB8-0x00345BC8), 1 real insert + tail, no large hole/lump (>=25); production stays INCLUDE_ASM (short, do not bank).
// storage shape, not arithmetic: retail spills each func_002b2970 scratch result to a low stack slot as it goes (e.g. 0x2D8->0x188, 0x2E0->0x190, 50 sites of 8-byte lwc1/lwc1/swc1/swc1 with varying indices, sequential distinct), where v4/v5 keep one big buffer (Cmb43Work + twork, +768 frame); retail uses a rolling pair of small slots and copies out -- fix is storage shape (smaller slots + per-result copies, +162 to 2200) not conversions (all fourteen genuinely signed, 0 changed).
/* measured 00345700 (owner, 2026-09-19): the storage-shape hypothesis in the note above is
   **disproved at this granularity**.  All 36 `func_002b2970` scratch destinations in the
   0x210-byte `ttmp` buffer are written once and read exactly twice, so each was replaced
   with its own `CmbVec2f` local - 36 separate two-float objects instead of disjoint slices
   of one array.  Result: object 2138 and 1141 fnalign edits, **identical to the buffer
   form**.  MWCC already treats provably disjoint slices of a local array as separate
   values, so splitting them changes nothing.  If retail's low stack offsets are still the
   answer, the difference has to come from the *order* the slots are allocated in or from
   the other 229 `ttmp` offsets, not from the 36 scratch pairs. */
/* measured 00345700 (owner, 2026-09-19): 2138 against retail 2190 (-2.4%, inside), and
   deficit_scan gives an unusually clean answer - the ONLY opcodes retail has more of are
   `lwc1 +46` and `lbu +12`, with two adjacent retail-only runs at 0x00346edc-0x00346f80
   (41) and 0x00346f84-0x00347078 (61) that are really one 102-instruction region.
   Reading it: retail round-trips every computed pair through the stack and RELOADS it.
   At 0x00346efc it copies the func_002b2970 result from 0x1F0($sp) to 0xA0($sp), at
   0x00346f3c it loads 0xA8($sp) back to store into slot+0x548, and at 0x00346f4c it
   reloads slot+0x548 itself to write slot+0x538.  The body already spells that last
   reload (`*(f32 *)(slot + 0x538) = *(f32 *)(slot + 0x548);`) and b210 honours it, so the
   46 missing loads are the OTHER round-trips, where the value is still live in a register
   and the compiler declines to reload it.
   That is the same wall as func_00476e90, where the only spelling that forced the reloads
   was a banned `volatile`.  Do not spend spelling effort here until someone finds an
   honest construct that defeats b210's CSE on a stack round-trip; the structure is right
   and the residual is the compiler keeping what retail reloads. */
/* measured 00345700 (2026-09-20): honest reload for the 46 missing lwc1 - spelling each */
/* scratch pair as one 8-byte struct copy `flow[i] = (*(CmbVec2f*)&ttmp[off]);` (37 sites, */
/* incl. flow[36] from workB+0x8) instead of per-field `flow[i].x/y = (*(f32*)&ttmp[..]);` */
/* forces b210 to reload the second value from the stack for the slot store, exactly like */
/* banned `volatile` but without lying about storage (8B copy, all scratch offs 8-aligned, */
/* same aliasing, no extra jal, no pragma/asm). Baseline 1912 words / 2138 vs retail 2190 */
/* (-2.4%, deficit 52, lwc1+46 lbu+12, runs 41 ABSENT + 30 ABSENT) -> now 1821 words (-91) / */
/* 2186 vs 2190 (-0.2% inside, deficit 4, lwc1 balanced +2 obj surplus, lbu+12 only, all three */
/* runs CROSS). Banned volatile flow ties at 1821/2186 (+48); RGBA struct for the 12 byte */
/* blocks regresses to 1836 (+15) so per-byte stays. Remaining wall is 12x first-byte lbu */
/* ($a0 forwarded vs retail reload) + stack-offset/scheduling color; production stays ASM. */
/* Commands: measure_guarded, deficit_scan, probe_variants vol/struct/struct2/structFull, */
/* fnalign base/vol/struct, pragma_sweep (best tie 1912, prop-off 2051), micro1-7/C/Cb. TU */
/* link + retail identity unverified (fnalign/probe only). */
// FUN_00345700 NONMATCHING
#ifdef NON_MATCHING
s32 func_00345700(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    u8 ttmp[0x210];
    u8 workB[0x180];
    CmbVec2f workF70;
    CmbVec2f flow[37];
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    f32 fvalue;
    s32 tmpI;
    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 || *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 || *(s8 *)(obj + 0x21C) != 0 || *(s8 *)(obj + 0x2A0) != 0 || *(s8 *)(obj + 0x324) != 0 || *(s8 *)(obj + 0x3A8) != 0 || *(s8 *)(obj + 0x42C) != 0 || *(s8 *)(obj + 0x4B0) != 0 || *(s8 *)(obj + 0x534) != 0 || *(s8 *)(obj + 0x5B8) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 12) {
            fclWriteColorBytes(workB + 0x178,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(workB + 0x134) =
                *(CmbRGBA *)(workB + 0x178);
            fclWriteColorBytes(workB + 0x17C,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(workB + 0x138) =
                *(CmbRGBA *)(workB + 0x17C);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(workB + 0x138);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(workB + 0x134);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
        func_002b2970((u8 *)((s64*)&ttmp[0xf8]), 0x141, 70.0f);
        flow[0] = (*(CmbVec2f*)&ttmp[0xf8]);
        func_002b2970((u8 *)((s64*)&ttmp[0xf0]), 326.0f, 224.0f);
        flow[1] = (*(CmbVec2f*)&ttmp[0xf0]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x20) = flow[1].x;
        *(f32 *)(slot + 0x24) = flow[1].y;
        *(f32 *)(slot + 0x10) = *(f32 *)(slot + 0x20);
        *(f32 *)(slot + 0x14) = *(f32 *)(slot + 0x24);
        *(f32 *)(slot + 0x18) = flow[0].x;
        *(f32 *)(slot + 0x1c) = flow[0].y;
        *(s16 *)(slot + 0x2a) = 0;
        *(s16 *)(slot + 0x28) = 8;
        *(s8 *)(slot + 0xc) = *(s8 *)(slot + 0xc) | 1;
        fclWriteColorBytes(&ttmp[0x10],0xff,0xff,0xff,0xff);
        (ttmp[0x88]) = (ttmp[0x10]);
        (ttmp[0x87]) = (ttmp[0xf]);
        (ttmp[0x86]) = (ttmp[0xe]);
        (ttmp[0x85]) = (ttmp[0xd]);
        fclWriteColorBytes(&ttmp[0xc],0xff,0xff,0xff,0);
        (ttmp[0x84]) = (ttmp[0xc]);
        (ttmp[0x83]) = (ttmp[0xb]);
        (ttmp[0x82]) = (ttmp[0xa]);
        (ttmp[0x81]) = (ttmp[0x9]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x84) = (ttmp[0xc]);
        *(u8 *)(slot + 0x85) = (ttmp[0xb]);
        *(u8 *)(slot + 0x86) = (ttmp[0xa]);
        *(u8 *)(slot + 0x87) = (ttmp[0x9]);
        *(u8 *)(slot + 0x7c) = *(u8 *)(slot + 0x84);
        *(u8 *)(slot + 0x7d) = *(u8 *)(slot + 0x85);
        *(u8 *)(slot + 0x7e) = *(u8 *)(slot + 0x86);
        *(u8 *)(slot + 0x7f) = *(u8 *)(slot + 0x87);
        *(u8 *)(slot + 0x80) = (ttmp[0x88]);
        *(u8 *)(slot + 0x81) = (ttmp[0x87]);
        *(u8 *)(slot + 0x82) = (ttmp[0x86]);
        *(u8 *)(slot + 0x83) = (ttmp[0x85]);
        *(s16 *)(slot + 0x88) = 0;
        *(s16 *)(slot + 0x8a) = 8;
        *(s8 *)(slot + 0xc) = *(s8 *)(slot + 0xc) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x108]), 0x141, 70.0f);
        flow[2] = (*(CmbVec2f*)&ttmp[0x108]);
        func_002b2970((u8 *)((s64*)&ttmp[0x100]), 326.0f, 224.0f);
        flow[3] = (*(CmbVec2f*)&ttmp[0x100]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0xa4) = flow[3].x;
        *(f32 *)(slot + 0xa8) = flow[3].y;
        *(f32 *)(slot + 0x94) = *(f32 *)(slot + 0xa4);
        *(f32 *)(slot + 0x98) = *(f32 *)(slot + 0xa8);
        *(f32 *)(slot + 0x9c) = flow[2].x;
        *(f32 *)(slot + 0xa0) = flow[2].y;
        *(s16 *)(slot + 0xae) = 0;
        *(s16 *)(slot + 0xac) = 8;
        *(s8 *)(slot + 0x90) = *(s8 *)(slot + 0x90) | 1;
        fclWriteColorBytes(&ttmp[0x18],0xff,0xff,0xff,0xff);
        (ttmp[0x90]) = (ttmp[0x18]);
        (ttmp[0x8f]) = (ttmp[0x17]);
        (ttmp[0x8e]) = (ttmp[0x16]);
        (ttmp[0x8d]) = (ttmp[0x15]);
        fclWriteColorBytes(&ttmp[0x14],0xff,0xff,0xff,0);
        (ttmp[0x8c]) = (ttmp[0x14]);
        (ttmp[0x8b]) = (ttmp[0x13]);
        (ttmp[0x8a]) = (ttmp[0x12]);
        (ttmp[0x89]) = (ttmp[0x11]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x108) = (ttmp[0x14]);
        *(u8 *)(slot + 0x109) = (ttmp[0x13]);
        *(u8 *)(slot + 0x10a) = (ttmp[0x12]);
        *(u8 *)(slot + 0x10b) = (ttmp[0x11]);
        *(u8 *)(slot + 0x100) = *(u8 *)(slot + 0x108);
        *(u8 *)(slot + 0x101) = *(u8 *)(slot + 0x109);
        *(u8 *)(slot + 0x102) = *(u8 *)(slot + 0x10a);
        *(u8 *)(slot + 0x103) = *(u8 *)(slot + 0x10b);
        *(u8 *)(slot + 0x104) = (ttmp[0x90]);
        *(u8 *)(slot + 0x105) = (ttmp[0x8f]);
        *(u8 *)(slot + 0x106) = (ttmp[0x8e]);
        *(u8 *)(slot + 0x107) = (ttmp[0x8d]);
        *(s16 *)(slot + 0x10c) = 0;
        *(s16 *)(slot + 0x10e) = 8;
        *(s8 *)(slot + 0x90) = *(s8 *)(slot + 0x90) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x110]), 250.0f, 95.0f);
        flow[4] = (*(CmbVec2f*)&ttmp[0x110]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0xec) * 0xc + slot;
        *(f32 *)(table + 0xb0) = flow[4].x;
        *(f32 *)(table + 0xb4) = flow[4].y;
        *(s16 *)(table + 0xb8) = 5;
        *(s8 *)(slot + 0x90) = *(s8 *)(slot + 0x90) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0xec),1,5,0,1);
        *(s8 *)(slot + 0xec) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x120]), 0x141, 70.0f);
        flow[5] = (*(CmbVec2f*)&ttmp[0x120]);
        func_002b2970((u8 *)((s64*)&ttmp[0x118]), 326.0f, 224.0f);
        flow[6] = (*(CmbVec2f*)&ttmp[0x118]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x128) = flow[6].x;
        *(f32 *)(slot + 0x12C) = flow[6].y;
        *(f32 *)(slot + 0x118) = *(f32 *)(slot + 0x128);
        *(s32 *)(slot + 0x11c) = *(f32 *)(slot + 0x12C);
        *(f32 *)(slot + 0x120) = flow[5].x;
        *(f32 *)(slot + 0x124) = flow[5].y;
        *(s16 *)(slot + 0x132) = 0;
        *(s16 *)(slot + 0x130) = 8;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 1;
        fclWriteColorBytes(&ttmp[0x20],0xff,0xff,0xff,0xff);
        (ttmp[0x98]) = (ttmp[0x20]);
        (ttmp[0x97]) = (ttmp[0x1f]);
        (ttmp[0x96]) = (ttmp[0x1e]);
        (ttmp[0x95]) = (ttmp[0x1d]);
        fclWriteColorBytes(&ttmp[0x1c],0xff,0xff,0xff,0);
        (ttmp[0x94]) = (ttmp[0x1c]);
        (ttmp[0x93]) = (ttmp[0x1b]);
        (ttmp[0x92]) = (ttmp[0x1a]);
        (ttmp[0x91]) = (ttmp[0x19]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x18c) = (ttmp[0x1c]);
        *(u8 *)(slot + 0x18d) = (ttmp[0x1b]);
        *(u8 *)(slot + 0x18e) = (ttmp[0x1a]);
        *(u8 *)(slot + 0x18F) = (ttmp[0x19]);
        *(u8 *)(slot + 0x184) = *(u8 *)(slot + 0x18c);
        *(u8 *)(slot + 0x185) = *(u8 *)(slot + 0x18d);
        *(u8 *)(slot + 0x186) = *(u8 *)(slot + 0x18e);
        *(u8 *)(slot + 0x187) = *(u8 *)(slot + 0x18F);
        *(u8 *)(slot + 0x188) = (ttmp[0x98]);
        *(u8 *)(slot + 0x189) = (ttmp[0x97]);
        *(u8 *)(slot + 0x18a) = (ttmp[0x96]);
        *(u8 *)(slot + 0x18b) = (ttmp[0x95]);
        *(s16 *)(slot + 0x190) = 0;
        *(s16 *)(slot + 0x192) = 8;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x128]), 250.0f, 95.0f);
        flow[7] = (*(CmbVec2f*)&ttmp[0x128]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x170) * 0xc + slot;
        *(f32 *)(table + 0x134) = flow[7].x;
        *(f32 *)(table + 0x138) = flow[7].y;
        *(s16 *)(table + 0x13c) = 5;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x170),1,5,0,1);
        *(s8 *)(slot + 0x170) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x130]), 175.0f, 141.0f);
        flow[8] = (*(CmbVec2f*)&ttmp[0x130]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x170) * 0xc + slot;
        *(f32 *)(table + 0x134) = flow[8].x;
        *(f32 *)(table + 0x138) = flow[8].y;
        *(s16 *)(table + 0x13c) = 5;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x170),1,5,0,1);
        *(s8 *)(slot + 0x170) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x140]), 156.0f, 232.0f);
        flow[9] = (*(CmbVec2f*)&ttmp[0x140]);
        func_002b2970((u8 *)((s64*)&ttmp[0x138]), 326.0f, 224.0f);
        flow[10] = (*(CmbVec2f*)&ttmp[0x138]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x1ac) = flow[10].x;
        *(f32 *)(slot + 0x1b0) = flow[10].y;
        *(f32 *)(slot + 0x19c) = *(f32 *)(slot + 0x1ac);
        *(f32 *)(slot + 0x1a0) = *(f32 *)(slot + 0x1b0);
        *(f32 *)(slot + 0x1a4) = flow[9].x;
        *(f32 *)(slot + 0x1a8) = flow[9].y;
        *(s16 *)(slot + 0x1b6) = 0;
        *(s16 *)(slot + 0x1b4) = 8;
        *(s8 *)(slot + 0x198) = *(s8 *)(slot + 0x198) | 1;
        fclWriteColorBytes(&ttmp[0x28],0xff,0xff,0xff,0xff);
        (ttmp[0xa0]) = (ttmp[0x28]);
        (ttmp[0x9f]) = (ttmp[0x27]);
        (ttmp[0x9e]) = (ttmp[0x26]);
        (ttmp[0x9d]) = (ttmp[0x25]);
        fclWriteColorBytes(&ttmp[0x24],0xff,0xff,0xff,0);
        (ttmp[0x9c]) = (ttmp[0x24]);
        (ttmp[0x9b]) = (ttmp[0x23]);
        (ttmp[0x9a]) = (ttmp[0x22]);
        (ttmp[0x99]) = (ttmp[0x21]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x210) = (ttmp[0x24]);
        *(u8 *)(slot + 0x211) = (ttmp[0x23]);
        *(u8 *)(slot + 0x212) = (ttmp[0x22]);
        *(u8 *)(slot + 0x213) = (ttmp[0x21]);
        *(u8 *)(slot + 0x208) = *(u8 *)(slot + 0x210);
        *(u8 *)(slot + 0x209) = *(u8 *)(slot + 0x211);
        *(u8 *)(slot + 0x20a) = *(u8 *)(slot + 0x212);
        *(u8 *)(slot + 0x20b) = *(u8 *)(slot + 0x213);
        *(u8 *)(slot + 0x20c) = (ttmp[0xa0]);
        *(u8 *)(slot + 0x20d) = (ttmp[0x9f]);
        *(u8 *)(slot + 0x20e) = (ttmp[0x9e]);
        *(u8 *)(slot + 0x20f) = (ttmp[0x9d]);
        *(s16 *)(slot + 0x214) = 0;
        *(s16 *)(slot + 0x216) = 8;
        *(s8 *)(slot + 0x198) = *(s8 *)(slot + 0x198) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x150]), 156.0f, 232.0f);
        flow[11] = (*(CmbVec2f*)&ttmp[0x150]);
        func_002b2970((u8 *)((s64*)&ttmp[0x148]), 326.0f, 224.0f);
        flow[12] = (*(CmbVec2f*)&ttmp[0x148]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x230) = flow[12].x;
        *(f32 *)(slot + 0x234) = flow[12].y;
        *(f32 *)(slot + 0x220) = *(f32 *)(slot + 0x230);
        *(f32 *)(slot + 0x224) = *(f32 *)(slot + 0x234);
        *(f32 *)(slot + 0x228) = flow[11].x;
        *(f32 *)(slot + 0x22c) = flow[11].y;
        *(s16 *)(slot + 0x23a) = 0;
        *(s16 *)(slot + 0x238) = 8;
        *(s8 *)(slot + 0x21c) = *(s8 *)(slot + 0x21c) | 1;
        fclWriteColorBytes(&ttmp[0x30],0xff,0xff,0xff,0xff);
        (ttmp[0xa8]) = (ttmp[0x30]);
        (ttmp[0xa7]) = (ttmp[0x2f]);
        (ttmp[0xa6]) = (ttmp[0x2e]);
        (ttmp[0xa5]) = (ttmp[0x2d]);
        fclWriteColorBytes(&ttmp[0x2c],0xff,0xff,0xff,0);
        (ttmp[0xa4]) = (ttmp[0x2c]);
        (ttmp[0xa3]) = (ttmp[0x2b]);
        (ttmp[0xa2]) = (ttmp[0x2a]);
        (ttmp[0xa1]) = (ttmp[0x29]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x294) = (ttmp[0x2c]);
        *(u8 *)(slot + 0x295) = (ttmp[0x2b]);
        *(u8 *)(slot + 0x296) = (ttmp[0x2a]);
        *(u8 *)(slot + 0x297) = (ttmp[0x29]);
        *(u8 *)(slot + 0x28c) = *(u8 *)(slot + 0x294);
        *(u8 *)(slot + 0x28d) = *(u8 *)(slot + 0x295);
        *(u8 *)(slot + 0x28e) = *(u8 *)(slot + 0x296);
        *(u8 *)(slot + 0x28f) = *(u8 *)(slot + 0x297);
        *(u8 *)(slot + 0x290) = (ttmp[0xa8]);
        *(u8 *)(slot + 0x291) = (ttmp[0xa7]);
        *(u8 *)(slot + 0x292) = (ttmp[0xa6]);
        *(u8 *)(slot + 0x293) = (ttmp[0xa5]);
        *(s16 *)(slot + 0x298) = 0;
        *(s16 *)(slot + 0x29a) = 8;
        *(s8 *)(slot + 0x21c) = *(s8 *)(slot + 0x21c) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x158]), 180.0f, 322.0f);
        flow[13] = (*(CmbVec2f*)&ttmp[0x158]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x278) * 0xc + slot;
        *(f32 *)(table + 0x23c) = flow[13].x;
        *(f32 *)(table + 0x240) = flow[13].y;
        *(s16 *)(table + 0x244) = 5;
        *(s8 *)(slot + 0x21c) = *(s8 *)(slot + 0x21c) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x278),1,5,0,1);
        *(s8 *)(slot + 0x278) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x168]), 156.0f, 232.0f);
        flow[14] = (*(CmbVec2f*)&ttmp[0x168]);
        func_002b2970((u8 *)((s64*)&ttmp[0x160]), 326.0f, 224.0f);
        flow[15] = (*(CmbVec2f*)&ttmp[0x160]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x2b4) = flow[15].x;
        *(f32 *)(slot + 0x2b8) = flow[15].y;
        *(f32 *)(slot + 0x2a4) = *(f32 *)(slot + 0x2b4);
        *(f32 *)(slot + 0x2a8) = *(f32 *)(slot + 0x2b8);
        *(f32 *)(slot + 0x2ac) = flow[14].x;
        *(f32 *)(slot + 0x2b0) = flow[14].y;
        *(s16 *)(slot + 0x2be) = 0;
        *(s16 *)(slot + 0x2BC) = 8;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 1;
        fclWriteColorBytes(&ttmp[0x38],0xff,0xff,0xff,0xff);
        (ttmp[0xb0]) = (ttmp[0x38]);
        (ttmp[0xaf]) = (ttmp[0x37]);
        (ttmp[0xae]) = (ttmp[0x36]);
        (ttmp[0xad]) = (ttmp[0x35]);
        fclWriteColorBytes(&ttmp[0x34],0xff,0xff,0xff,0);
        (ttmp[0xac]) = (ttmp[0x34]);
        (ttmp[0xab]) = (ttmp[0x33]);
        (ttmp[0xaa]) = (ttmp[0x32]);
        (ttmp[0xa9]) = (ttmp[0x31]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x318) = (ttmp[0x34]);
        *(u8 *)(slot + 0x319) = (ttmp[0x33]);
        *(u8 *)(slot + 0x31a) = (ttmp[0x32]);
        *(u8 *)(slot + 0x31b) = (ttmp[0x31]);
        *(u8 *)(slot + 0x310) = *(u8 *)(slot + 0x318);
        *(u8 *)(slot + 0x311) = *(u8 *)(slot + 0x319);
        *(u8 *)(slot + 0x312) = *(u8 *)(slot + 0x31a);
        *(u8 *)(slot + 0x313) = *(u8 *)(slot + 0x31b);
        *(u8 *)(slot + 0x314) = (ttmp[0xb0]);
        *(u8 *)(slot + 0x315) = (ttmp[0xaf]);
        *(u8 *)(slot + 0x316) = (ttmp[0xae]);
        *(u8 *)(slot + 0x317) = (ttmp[0xad]);
        *(s16 *)(slot + 0x31c) = 0;
        *(s16 *)(slot + 0x31e) = 8;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x170]), 180.0f, 322.0f);
        flow[16] = (*(CmbVec2f*)&ttmp[0x170]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x2fc) * 0xc + slot;
        *(f32 *)(table + 0x2c0) = flow[16].x;
        *(f32 *)(table + 0x2c4) = flow[16].y;
        *(s16 *)(table + 0x2c8) = 5;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x2fc),1,5,0,1);
        *(s8 *)(slot + 0x2fc) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x178]), 250.0f, 0x16B);
        flow[17] = (*(CmbVec2f*)&ttmp[0x178]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x2fc) * 0xc + slot;
        *(f32 *)(table + 0x2c0) = flow[17].x;
        *(f32 *)(table + 0x2c4) = flow[17].y;
        *(s16 *)(table + 0x2c8) = 5;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x2fc),1,5,0,1);
        *(s8 *)(slot + 0x2fc) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x188]), 0x141, 388.0f);
        flow[18] = (*(CmbVec2f*)&ttmp[0x188]);
        func_002b2970((u8 *)((s64*)&ttmp[0x180]), 326.0f, 224.0f);
        flow[19] = (*(CmbVec2f*)&ttmp[0x180]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x338) = flow[19].x;
        *(f32 *)(slot + 0x33c) = flow[19].y;
        *(f32 *)(slot + 0x328) = *(f32 *)(slot + 0x338);
        *(f32 *)(slot + 0x32c) = *(f32 *)(slot + 0x33c);
        *(f32 *)(slot + 0x330) = flow[18].x;
        *(f32 *)(slot + 0x334) = flow[18].y;
        *(s16 *)(slot + 0x342) = 0;
        *(s16 *)(slot + 0x340) = 8;
        *(s8 *)(slot + 0x324) = *(s8 *)(slot + 0x324) | 1;
        fclWriteColorBytes(&ttmp[0x40],0xff,0xff,0xff,0xff);
        (ttmp[0xb8]) = (ttmp[0x40]);
        (ttmp[0xb7]) = (ttmp[0x3f]);
        (ttmp[0xb6]) = (ttmp[0x3e]);
        (ttmp[0xb5]) = (ttmp[0x3d]);
        fclWriteColorBytes(&ttmp[0x3c],0xff,0xff,0xff,0);
        (ttmp[0xb4]) = (ttmp[0x3c]);
        (ttmp[0xb3]) = (ttmp[0x3b]);
        (ttmp[0xb2]) = (ttmp[0x3a]);
        (ttmp[0xb1]) = (ttmp[0x39]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x39c) = (ttmp[0x3c]);
        *(u8 *)(slot + 0x39d) = (ttmp[0x3b]);
        *(u8 *)(slot + 0x39e) = (ttmp[0x3a]);
        *(u8 *)(slot + 0x39f) = (ttmp[0x39]);
        *(u8 *)(slot + 0x394) = *(u8 *)(slot + 0x39c);
        *(u8 *)(slot + 0x395) = *(u8 *)(slot + 0x39d);
        *(u8 *)(slot + 0x396) = *(u8 *)(slot + 0x39e);
        *(u8 *)(slot + 0x397) = *(u8 *)(slot + 0x39f);
        *(u8 *)(slot + 0x398) = (ttmp[0xb8]);
        *(u8 *)(slot + 0x399) = (ttmp[0xb7]);
        *(u8 *)(slot + 0x39a) = (ttmp[0xb6]);
        *(u8 *)(slot + 0x39b) = (ttmp[0xb5]);
        *(s16 *)(slot + 0x3a0) = 0;
        *(s16 *)(slot + 0x3a2) = 8;
        *(s8 *)(slot + 0x324) = *(s8 *)(slot + 0x324) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x198]), 0x141, 388.0f);
        flow[20] = (*(CmbVec2f*)&ttmp[0x198]);
        func_002b2970((u8 *)((s64*)&ttmp[0x190]), 326.0f, 224.0f);
        flow[21] = (*(CmbVec2f*)&ttmp[0x190]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x3bc) = flow[21].x;
        *(f32 *)(slot + 0x3c0) = flow[21].y;
        *(f32 *)(slot + 0x3ac) = *(f32 *)(slot + 0x3bc);
        *(f32 *)(slot + 0x3b0) = *(f32 *)(slot + 0x3c0);
        *(f32 *)(slot + 0x3b4) = flow[20].x;
        *(f32 *)(slot + 0x3b8) = flow[20].y;
        *(s16 *)(slot + 0x3c6) = 0;
        *(s16 *)(slot + 0x3c4) = 8;
        *(s8 *)(slot + 0x3a8) = *(s8 *)(slot + 0x3a8) | 1;
        fclWriteColorBytes(&ttmp[0x48],0xff,0xff,0xff,0xff);
        (ttmp[0xc0]) = (ttmp[0x48]);
        (ttmp[0xbf]) = (ttmp[0x47]);
        (ttmp[0xbe]) = (ttmp[0x46]);
        (ttmp[0xbd]) = (ttmp[0x45]);
        fclWriteColorBytes(&ttmp[0x44],0xff,0xff,0xff,0);
        (ttmp[0xbc]) = (ttmp[0x44]);
        (ttmp[0xbb]) = (ttmp[0x43]);
        (ttmp[0xba]) = (ttmp[0x42]);
        (ttmp[0xb9]) = (ttmp[0x41]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x420) = (ttmp[0x44]);
        *(u8 *)(slot + 0x421) = (ttmp[0x43]);
        *(u8 *)(slot + 0x422) = (ttmp[0x42]);
        *(u8 *)(slot + 0x423) = (ttmp[0x41]);
        *(u8 *)(slot + 0x418) = *(u8 *)(slot + 0x420);
        *(u8 *)(slot + 0x419) = *(u8 *)(slot + 0x421);
        *(u8 *)(slot + 0x41a) = *(u8 *)(slot + 0x422);
        *(u8 *)(slot + 0x41b) = *(u8 *)(slot + 0x423);
        *(u8 *)(slot + 0x41c) = (ttmp[0xc0]);
        *(u8 *)(slot + 0x41d) = (ttmp[0xbf]);
        *(u8 *)(slot + 0x41e) = (ttmp[0xbe]);
        *(u8 *)(slot + 0x41f) = (ttmp[0xbd]);
        *(s16 *)(slot + 0x424) = 0;
        *(s16 *)(slot + 0x426) = 8;
        *(s8 *)(slot + 0x3a8) = *(s8 *)(slot + 0x3a8) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x1a0]), 0x187, 0x16B);
        flow[22] = (*(CmbVec2f*)&ttmp[0x1a0]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x404) * 0xc + slot;
        *(f32 *)(table + 0x3c8) = flow[22].x;
        *(f32 *)(table + 0x3cc) = flow[22].y;
        *(s16 *)(table + 0x3d0) = 5;
        *(s8 *)(slot + 0x3a8) = *(s8 *)(slot + 0x3a8) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x404),1,5,0,1);
        *(s8 *)(slot + 0x404) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x1b0]), 0x141, 388.0f);
        flow[23] = (*(CmbVec2f*)&ttmp[0x1b0]);
        func_002b2970((u8 *)((s64*)&ttmp[0x1a8]), 326.0f, 224.0f);
        flow[24] = (*(CmbVec2f*)&ttmp[0x1a8]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x440) = flow[24].x;
        *(f32 *)(slot + 0x444) = flow[24].y;
        *(f32 *)(slot + 0x430) = *(f32 *)(slot + 0x440);
        *(f32 *)(slot + 0x434) = *(f32 *)(slot + 0x444);
        *(f32 *)(slot + 0x438) = flow[23].x;
        *(f32 *)(slot + 0x43c) = flow[23].y;
        *(s16 *)(slot + 0x44a) = 0;
        *(s16 *)(slot + 0x448) = 8;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 1;
        fclWriteColorBytes(&ttmp[0x50],0xff,0xff,0xff,0xff);
        (ttmp[0xc8]) = (ttmp[0x50]);
        (ttmp[0xc7]) = (ttmp[0x4f]);
        (ttmp[0xc6]) = (ttmp[0x4e]);
        (ttmp[0xc5]) = (ttmp[0x4d]);
        fclWriteColorBytes(&ttmp[0x4c],0xff,0xff,0xff,0);
        (ttmp[0xc4]) = (ttmp[0x4c]);
        (ttmp[0xc3]) = (ttmp[0x4b]);
        (ttmp[0xc2]) = (ttmp[0x4a]);
        (ttmp[0xc1]) = (ttmp[0x49]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x4a4) = (ttmp[0x4c]);
        *(u8 *)(slot + 0x4a5) = (ttmp[0x4b]);
        *(u8 *)(slot + 0x4a6) = (ttmp[0x4a]);
        *(u8 *)(slot + 0x4a7) = (ttmp[0x49]);
        *(u8 *)(slot + 0x49c) = *(u8 *)(slot + 0x4a4);
        *(u8 *)(slot + 0x49d) = *(u8 *)(slot + 0x4a5);
        *(u8 *)(slot + 0x49e) = *(u8 *)(slot + 0x4a6);
        *(u8 *)(slot + 0x49f) = *(u8 *)(slot + 0x4a7);
        *(u8 *)(slot + 0x4a0) = (ttmp[0xc8]);
        *(u8 *)(slot + 0x4a1) = (ttmp[0xc7]);
        *(u8 *)(slot + 0x4a2) = (ttmp[0xc6]);
        *(u8 *)(slot + 0x4a3) = (ttmp[0xc5]);
        *(s16 *)(slot + 0x4a8) = 0;
        *(s16 *)(slot + 0x4aa) = 8;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x1b8]), 0x187, 0x16B);
        flow[25] = (*(CmbVec2f*)&ttmp[0x1b8]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x488) * 0xc + slot;
        *(f32 *)(table + 0x44c) = flow[25].x;
        *(f32 *)(table + 0x450) = flow[25].y;
        *(s16 *)(table + 0x454) = 5;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x488),1,5,0,1);
        *(s8 *)(slot + 0x488) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x1c0]), 458.0f, 322.0f);
        flow[26] = (*(CmbVec2f*)&ttmp[0x1c0]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x488) * 0xc + slot;
        *(f32 *)(table + 0x44c) = flow[26].x;
        *(f32 *)(table + 0x450) = flow[26].y;
        *(s16 *)(table + 0x454) = 5;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x488),1,5,0,1);
        *(s8 *)(slot + 0x488) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x1d0]), 482.0f, 232.0f);
        flow[27] = (*(CmbVec2f*)&ttmp[0x1d0]);
        func_002b2970((u8 *)((s64*)&ttmp[0x1c8]), 326.0f, 224.0f);
        flow[28] = (*(CmbVec2f*)&ttmp[0x1c8]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x4c4) = flow[28].x;
        *(f32 *)(slot + 0x4c8) = flow[28].y;
        *(f32 *)(slot + 0x4b4) = *(f32 *)(slot + 0x4c4);
        *(f32 *)(slot + 0x4b8) = *(f32 *)(slot + 0x4c8);
        *(f32 *)(slot + 0x4bc) = flow[27].x;
        *(f32 *)(slot + 0x4c0) = flow[27].y;
        *(s16 *)(slot + 0x4ce) = 0;
        *(s16 *)(slot + 0x4cc) = 8;
        *(s8 *)(slot + 0x4b0) = *(s8 *)(slot + 0x4b0) | 1;
        fclWriteColorBytes(&ttmp[0x58],0xff,0xff,0xff,0xff);
        (ttmp[0xd0]) = (ttmp[0x58]);
        (ttmp[0xcf]) = (ttmp[0x57]);
        (ttmp[0xce]) = (ttmp[0x56]);
        (ttmp[0xcd]) = (ttmp[0x55]);
        fclWriteColorBytes(&ttmp[0x54],0xff,0xff,0xff,0);
        (ttmp[0xcc]) = (ttmp[0x54]);
        (ttmp[0xcb]) = (ttmp[0x53]);
        (ttmp[0xca]) = (ttmp[0x52]);
        (ttmp[0xc9]) = (ttmp[0x51]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x528) = (ttmp[0x54]);
        *(u8 *)(slot + 0x529) = (ttmp[0x53]);
        *(u8 *)(slot + 0x52a) = (ttmp[0x52]);
        *(u8 *)(slot + 0x52b) = (ttmp[0x51]);
        *(u8 *)(slot + 0x520) = *(u8 *)(slot + 0x528);
        *(u8 *)(slot + 0x521) = *(u8 *)(slot + 0x529);
        *(u8 *)(slot + 0x522) = *(u8 *)(slot + 0x52a);
        *(u8 *)(slot + 0x523) = *(u8 *)(slot + 0x52b);
        *(u8 *)(slot + 0x524) = (ttmp[0xd0]);
        *(u8 *)(slot + 0x525) = (ttmp[0xcf]);
        *(u8 *)(slot + 0x526) = (ttmp[0xce]);
        *(u8 *)(slot + 0x527) = (ttmp[0xcd]);
        *(s16 *)(slot + 0x52c) = 0;
        *(s16 *)(slot + 0x52e) = 8;
        *(s8 *)(slot + 0x4b0) = *(s8 *)(slot + 0x4b0) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x1e0]), 482.0f, 232.0f);
        flow[29] = (*(CmbVec2f*)&ttmp[0x1e0]);
        func_002b2970((u8 *)((s64*)&ttmp[0x1d8]), 326.0f, 224.0f);
        flow[30] = (*(CmbVec2f*)&ttmp[0x1d8]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x548) = flow[30].x;
        *(f32 *)(slot + 0x54c) = flow[30].y;
        *(f32 *)(slot + 0x538) = *(f32 *)(slot + 0x548);
        *(f32 *)(slot + 0x53c) = *(f32 *)(slot + 0x54c);
        *(f32 *)(slot + 0x540) = flow[29].x;
        *(f32 *)(slot + 0x544) = flow[29].y;
        *(s16 *)(slot + 0x552) = 0;
        *(s16 *)(slot + 0x550) = 8;
        *(s8 *)(slot + 0x534) = *(s8 *)(slot + 0x534) | 1;
        fclWriteColorBytes(&ttmp[0x60],0xff,0xff,0xff,0xff);
        (ttmp[0xd8]) = (ttmp[0x60]);
        (ttmp[0xd7]) = (ttmp[0x5f]);
        (ttmp[0xd6]) = (ttmp[0x5e]);
        (ttmp[0xd5]) = (ttmp[0x5d]);
        fclWriteColorBytes(&ttmp[0x5c],0xff,0xff,0xff,0);
        (ttmp[0xd4]) = (ttmp[0x5c]);
        (ttmp[0xd3]) = (ttmp[0x5b]);
        (ttmp[0xd2]) = (ttmp[0x5a]);
        (ttmp[0xd1]) = (ttmp[0x59]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x5ac) = (ttmp[0x5c]);
        *(u8 *)(slot + 0x5ad) = (ttmp[0x5b]);
        *(u8 *)(slot + 0x5ae) = (ttmp[0x5a]);
        *(u8 *)(slot + 0x5af) = (ttmp[0x59]);
        *(u8 *)(slot + 0x5a4) = *(u8 *)(slot + 0x5ac);
        *(u8 *)(slot + 0x5a5) = *(u8 *)(slot + 0x5ad);
        *(u8 *)(slot + 0x5a6) = *(u8 *)(slot + 0x5ae);
        *(u8 *)(slot + 0x5a7) = *(u8 *)(slot + 0x5af);
        *(u8 *)(slot + 0x5a8) = (ttmp[0xd8]);
        *(u8 *)(slot + 0x5a9) = (ttmp[0xd7]);
        *(u8 *)(slot + 0x5aa) = (ttmp[0xd6]);
        *(u8 *)(slot + 0x5ab) = (ttmp[0xd5]);
        *(s16 *)(slot + 0x5b0) = 0;
        *(s16 *)(slot + 0x5b2) = 8;
        *(s8 *)(slot + 0x534) = *(s8 *)(slot + 0x534) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x1e8]), 462.0f, 141.0f);
        flow[31] = (*(CmbVec2f*)&ttmp[0x1e8]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x590) * 0xc + slot;
        *(f32 *)(table + 0x554) = flow[31].x;
        *(f32 *)(table + 0x558) = flow[31].y;
        *(s16 *)(table + 0x55c) = 5;
        *(s8 *)(slot + 0x534) = *(s8 *)(slot + 0x534) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x590),1,5,0,1);
        *(s8 *)(slot + 0x590) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x1f8]), 482.0f, 232.0f);
        flow[32] = (*(CmbVec2f*)&ttmp[0x1f8]);
        func_002b2970((u8 *)((s64*)&ttmp[0x1f0]), 326.0f, 224.0f);
        flow[33] = (*(CmbVec2f*)&ttmp[0x1f0]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x5cc) = flow[33].x;
        *(f32 *)(slot + 0x5d0) = flow[33].y;
        *(f32 *)(slot + 0x5bc) = *(f32 *)(slot + 0x5cc);
        *(f32 *)(slot + 0x5c0) = *(f32 *)(slot + 0x5d0);
        *(f32 *)(slot + 0x5c4) = flow[32].x;
        *(f32 *)(slot + 0x5c8) = flow[32].y;
        *(s16 *)(slot + 0x5d6) = 0;
        *(s16 *)(slot + 0x5d4) = 8;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 1;
        fclWriteColorBytes(&ttmp[0x68],0xff,0xff,0xff,0xff);
        (ttmp[0xe0]) = (ttmp[0x68]);
        (ttmp[0xdf]) = (ttmp[0x67]);
        (ttmp[0xde]) = (ttmp[0x66]);
        (ttmp[0xdd]) = (ttmp[0x65]);
        fclWriteColorBytes(&ttmp[0x64],0xff,0xff,0xff,0);
        (ttmp[0xdc]) = (ttmp[0x64]);
        (ttmp[0xdb]) = (ttmp[0x63]);
        (ttmp[0xda]) = (ttmp[0x62]);
        (ttmp[0xd9]) = (ttmp[0x61]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x630) = (ttmp[0x64]);
        *(u8 *)(slot + 0x631) = (ttmp[0x63]);
        *(u8 *)(slot + 0x632) = (ttmp[0x62]);
        *(u8 *)(slot + 0x633) = (ttmp[0x61]);
        *(u8 *)(slot + 0x628) = *(u8 *)(slot + 0x630);
        *(u8 *)(slot + 0x629) = *(u8 *)(slot + 0x631);
        *(u8 *)(slot + 0x62a) = *(u8 *)(slot + 0x632);
        *(u8 *)(slot + 0x62b) = *(u8 *)(slot + 0x633);
        *(u8 *)(slot + 0x62c) = (ttmp[0xe0]);
        *(u8 *)(slot + 0x62d) = (ttmp[0xdf]);
        *(u8 *)(slot + 0x62e) = (ttmp[0xde]);
        *(u8 *)(slot + 0x62f) = (ttmp[0xdd]);
        *(s16 *)(slot + 0x634) = 0;
        *(s16 *)(slot + 0x636) = 8;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 4;
        func_002b2970((u8 *)((s64*)&ttmp[0x200]), 462.0f, 141.0f);
        flow[34] = (*(CmbVec2f*)&ttmp[0x200]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x614) * 0xc + slot;
        *(f32 *)(table + 0x5d8) = flow[34].x;
        *(f32 *)(table + 0x5dc) = flow[34].y;
        *(s16 *)(table + 0x5e0) = 5;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x614),1,5,0,1);
        *(s8 *)(slot + 0x614) = tmpI;
        func_002b2970((u8 *)((s64*)&ttmp[0x208]), 0x187, 95.0f);
        flow[35] = (*(CmbVec2f*)&ttmp[0x208]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x614) * 0xc + slot;
        *(f32 *)(table + 0x5d8) = flow[35].x;
        *(f32 *)(table + 0x5dc) = flow[35].y;
        *(s16 *)(table + 0x5e0) = 5;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x614),1,5,0,1);
        *(s8 *)(slot + 0x614) = tmpI;
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 12) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot2 = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot2 + 0x20) + 12.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot2 + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x1A0) = iGpffff8508;
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0(workB + 0x10, 0.0f, -5.0f, 30.0f);
        fclWriteColorBytes(workB + 0x144,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_002b29a0(workB + 0x20, 35.0f, 5.0f, 30.0f);
        fclWriteColorBytes(workB + 0x148,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_00348a90(*(u8 **)(obj + 0x64C),
                      (CmbVec3f *)(workB + 0x10),
                      *(CmbRGBA *)(workB + 0x144), 0, 0x28,
                      (CmbVec3f *)(workB + 0x20),
                      *(CmbRGBA *)(workB + 0x148),
                      0.0f, 0.0f, 0.0f, iGpffff850c,
                      0.0f, 0.0f, 31.5f, iGpffff850c);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 12) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 12) {
                func_002b2970((u8 *)((s64 *)(workB + 0x8)), 323.0f, 217.0f);
                flow[36] = (*(CmbVec2f*)(workB + 0x8));
                *(CmbVec2f *)&workF70 = flow[36];
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&workF70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_002b2970((u8 *)((s64 *)(workB + 0x0)), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot2,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)(workB + 0x0), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 12) {
            fclWriteColorBytes(workB + 0x13C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(workB + 0xFC) =
                *(CmbRGBA *)(workB + 0x13C);
            fclWriteColorBytes(workB + 0x140,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(workB + 0x100) =
                *(CmbRGBA *)(workB + 0x140);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(workB + 0x100);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(workB + 0xFC);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00345700);
#endif

// FUN_00347940
void func_00347940(u8 *arg0) {
    u8 *obj;
    s16 i;

    obj = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 0xC; i++) {
        *(s32 *)(obj + (s32)i * 4 + 0x658) = 0;
    }
    switch (*(s8 *)(obj + 0x63E)) {
    case 6:
        *(u32 *)(obj + 0x670) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x674) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x678) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x67C) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x680) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x684) = (u32)func_00348160(arg0, func_00331620());
    case 5:
        *(u32 *)(obj + 0x66C) = (u32)func_00348160(arg0, func_00331620());
    case 4:
        *(u32 *)(obj + 0x668) = (u32)func_00348160(arg0, func_00331620());
    case 3:
        *(u32 *)(obj + 0x664) = (u32)func_00348160(arg0, func_00331620());
    case 2:
        *(u32 *)(obj + 0x660) = (u32)func_00348160(arg0, func_00331620());
    case 1:
        *(u32 *)(obj + 0x658) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x65C) = (u32)func_00348160(arg0, func_00331620());
        break;
    }
}

// FUN_00347B30
void func_00347b30(u8 *arg0, u8 *arg1) {
    u32 base = (u32)D_00887300;

    ((void (*)(s32, s32))*(u32 *)base)(6, 1);
    ((void (*)(s32, s32))*(u32 *)base)(7, 2);
    ((void (*)(s32, s32))*(u32 *)base)(8, 1);
    ((void (*)(s32, s32))*(u32 *)base)(9, 2);
    ((void (*)(s32, s32))*(u32 *)base)(0xC, 1);
    ((void (*)(s32, s32))*(u32 *)base)(2, 3);
    ((void (*)(s32, s32))*(u32 *)base)(0xB, 6);
    ((void (*)(s32, s32))*(u32 *)base)(0xA, 5);
    RpSkyRenderStateSet(2, 0x48);
    RpSkyRenderStateSet(3, 0x71801);
    *(s32 *)(arg1 + 0x20) = 0;
    *(s32 *)(arg1 + 0x24) = 0;
    *(u32 *)(arg1 + 0x60) = 0x3F800000;
    *(s32 *)(arg1 + 0x64) = 0;
    *(s32 *)(arg1 + 0xA0) = 0;
    *(u32 *)(arg1 + 0xA4) = 0x3F800000;
    *(u32 *)(arg1 + 0xE0) = 0x3F800000;
    *(u32 *)(arg1 + 0xE4) = 0x3F800000;
    ((void (*)(s32, s32))*(u32 *)base)(1, *func_00331620());
}

/* Update the enabled card quad, queue its draw packet, then advance position
 * and alpha animation. The enable bit gates the entire update after the camera
 * read. The four-vertex index copy retains the signed-halfword loop domain.
 *
 * Native b210 -O2: 1204/1216 bytes, with a verified 12-byte zero suffix.
 * Loop invariants retain the depth-symbol base; propagation is disabled so the
 * camera result, first scale read and packet arguments keep retail's order.
 * Recovery history and full relocation/sibling proof:
 * docs/probe_archive/yCmb_00347c70_recovery_20260922.md. */
// FUN_00347C70
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
s32 func_00347c70(u8 *task)
{
    u8 *work;
    f32 reciprocalDepth;
    u8 *vertex;
    s16 index;
    s64 wideIndex;
    f32 depth;
    f32 scale;
    u8 *camera;

    work = *(u8 **)(task + 0x38);
    camera = (u8 *)(u32)func_00457120();
    reciprocalDepth = 1.0f / *(f32 *)(camera + 0x80);
    if (((( *(s32 *)(work + 0x11C) & 2) >> 1) == 1)) {
        for (index = 0; index < 4; index++) {
            wideIndex = index;
            vertex = work;
            vertex = (u8 *)((u32)vertex + ((u32)wideIndex << 6));
            depth = *(f32 *)D_008872F8;
            *(f32 *)(vertex + 0x18) = depth - 1.0f;
            *(f32 *)(vertex + 0x28) = reciprocalDepth;
            *(f32 *)(vertex + 0x30) = (f32)*(u8 *)(work + 0x198);
            *(f32 *)(vertex + 0x34) = (f32)*(u8 *)(work + 0x199);
            *(f32 *)(vertex + 0x38) = (f32)*(u8 *)(work + 0x19A);
            *(f32 *)(vertex + 0x3C) = (f32)*(u8 *)(work + 0x19B);
        }
        /* Four corners of a square with an unscaled half-width of 64. */
        scale = *(f32 *)(work + 0x1A0);
        *(f32 *)(work + 0x10) = *(f32 *)(work + 0x134) - 64.0f * scale;
        *(f32 *)(work + 0x14) = *(f32 *)(work + 0x138) - 64.0f * *(f32 *)(work + 0x1A0);
        *(f32 *)(work + 0x50) = *(f32 *)(work + 0x134) + 64.0f * *(f32 *)(work + 0x1A0);
        *(f32 *)(work + 0x54) = *(f32 *)(work + 0x138) - 64.0f * *(f32 *)(work + 0x1A0);
        *(f32 *)(work + 0x90) = *(f32 *)(work + 0x134) - 64.0f * *(f32 *)(work + 0x1A0);
        *(f32 *)(work + 0x94) = *(f32 *)(work + 0x138) + 64.0f * *(f32 *)(work + 0x1A0);
        *(f32 *)(work + 0xD0) = *(f32 *)(work + 0x134) + 64.0f * *(f32 *)(work + 0x1A0);
        *(f32 *)(work + 0xD4) = *(f32 *)(work + 0x138) + 64.0f * *(f32 *)(work + 0x1A0);
        if (func_00285b30() < 0x208) {
            u8 *list;
            s32 primitive;
            void *vertices;
            s32 count;
            u8 *alloc;
            list = D_00794F00;
            primitive = 4;
            vertices = work + 0x10;
            count = primitive;
            alloc = func_00461390(list, primitive, vertices, count);
            *(u32 *)(alloc + 8) = (u32)func_00347b30;
            *(u8 **)(alloc + 0x10) = work;
        }
        if (((( *(s32 *)(work + 0x11C) & 4) >> 2) == 1)) {
            f32 f14 = (f32)*(s16 *)(work + 0x13E);
            f32 f15 = (f32)*(s16 *)(work + 0x13C);
            *(f32 *)(work + 0x134) = func_002b2aa0(0, *(f32 *)(work + 0x124), *(f32 *)(work + 0x12C), f14, f15);
            f14 = (f32)*(s16 *)(work + 0x13E);
            f15 = (f32)*(s16 *)(work + 0x13C);
            *(f32 *)(work + 0x138) = func_002b2aa0(0, *(f32 *)(work + 0x128), *(f32 *)(work + 0x130), f14, f15);
            if (*(s16 *)(work + 0x13E) < *(s16 *)(work + 0x13C)) {
                *(s16 *)(work + 0x13E) = func_002b2cb0(*(s16 *)(work + 0x13E), 1, *(s16 *)(work + 0x13C), 0, 1);
            } else {
                *(s32 *)(work + 0x11C) &= 0xFFFB;
            }
        }
        if (((( *(s32 *)(work + 0x11C) & 0x10) >> 4) == 1)) {
            f32 f12 = (f32)*(u8 *)(work + 0x193);
            f32 f13 = (f32)*(u8 *)(work + 0x197);
            f32 f14 = (f32)*(s16 *)(work + 0x19C);
            f32 f15 = (f32)(*(s16 *)(work + 0x19E) / 2);
            f32 fres = func_002b2aa0(1, f12, f13, f14, f15);
            *(u8 *)(work + 0x19B) = (u8)fres;
            if (*(s16 *)(work + 0x19C) < *(s16 *)(work + 0x19E)) {
                *(s16 *)(work + 0x19C) = func_002b2cb0(*(s16 *)(work + 0x19C), 1, *(s16 *)(work + 0x19E), 0, 1);
            } else {
                *(s16 *)(work + 0x19C) = 0;
            }
        }
    }
    return 0;
}
#pragma pop
// FUN_00348130
void func_00348130(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00348160
u8 *func_00348160(u8 *arg0, s32 *arg1) {
    FclDrawColor sp5C;
    u8 *ret;
    u8 *blk;
    s16 i;

    func_0044ea90(D_0064A4A0, 0x702);
    blk = D_008873F4[0](1, 0x1B0, 0x40000);
    ret = (u8 *)(s32)func_00451fc0((void *)(arg0), (const void *)(D_0064A5D0), 0xF, 0, 0, func_00347c70, func_00348130, (u8 *)(blk));
    *(s32 **)(blk + 0x118) = arg1;
    *(s32 *)(blk + 0x11C) = 0;
    for (i = 0; i < 3; i++) {
        sp5C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        *(CmbRGBA *)(blk + (s32)i * 4 + 0x190) = sp5C;
    }
    *(u32 *)(blk + 0x1A0) = 0x3F800000;
    return ret;
}

// FUN_00348290
void *func_00348290(u8 *arg0) {
    return *(void **)(arg0 + 0x38);
}

// FUN_003482A0
void func_003482a0(u8 *arg0, u8 arg1, u8 arg2, u16 arg3) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(u32 *)(obj + 0x11C) |= 0x10;
    *(u8 *)(obj + 0x19B) = arg1;
    *(u8 *)(obj + 0x193) = arg1;
    *(u8 *)(obj + 0x197) = arg2;
    *(u16 *)(obj + 0x19C) = 0;
    *(u16 *)(obj + 0x19E) = arg3;
}

// FUN_003482D0
void func_003482d0(u8 *arg0, CmbVec2f arg1, CmbVec2f arg2, u16 arg3) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(u32 *)(obj + 0x11C) |= 4;
    *(CmbVec2f *)(obj + 0x134) = arg1;
    *(CmbVec2f *)(obj + 0x124) = *(CmbVec2f *)(obj + 0x134);
    *(CmbVec2f *)(obj + 0x12C) = arg2;
    *(u16 *)(obj + 0x13E) = 0;
    *(u16 *)(obj + 0x13C) = arg3;
}

/* measured: nd 15, obj 1296B = window (323 instrs both) — dispatch (lb 0x4, beq 3,2,1 + beqz 0 + b default), 004553c0/004b11xx/002b2d00 branches and float loads all match; EVERYTHING matches except the guarded-conversion result register: three `if (2.1474836e9f > f0) { v = (s32)f0; v &= 0xFF; } else { v = (s32)(f0-K)|0x80000000; v &= 0xFF; }` keep b210 mfc1/or/sb in $v0 where retail coalesces into $v1 (3 sites x 5 = 15 words; tried u8 locals, f0/v order, inline stores — no shift, same family as cmmScript func_0024c0e0). Recipe (correct-tree, top-down fnalign): outer switch cases 0,1,2,3 ascending (reverse beq chain 3,2,1,0+beqz) with case0/default break-shared to single return 0 (explicit return 0 in case1/2 regresses to 275; order 1,0,2,3 regresses dispatch to 39); inner 0x39 3-way if/else-if (x==0/1/2) reusing $a1=2; D_005DC7D0 indexed `&D_005DC7D0[idx*0x54]` (reloc-only); half via `h/2` (manual sra+bgez keeps $v0/$v1 swap, 29); nv via reload `*(s16*)=func...; if (*(s16*)<...)` (nv-local + explicit (s32)(s16) cast mis-schedules sh, 18). func_004553c0 takes ONE arg (m2c 2nd arg wrong); guard must be `2.1474836e9f > f0` with normal-first to keep c.le.s/bc1t + per-arm andi. Path 275->39->29->18->15. Production stays ASM. */
/* measured: nd 16, obj 1292B vs 1296B window — EVERYTHING matches byte-for-byte
   except the guarded-conversion result register: the three
   `if (2.1474836e9f > f0) { v = (u8)(s32)f0; } else { v = (u8)((s32)(f0-2.1474836e9f)|0x80000000); }`
   chains (explicit guard needed — implicit (u8)(s32) deletes the c.ole.s/bc1t guard
   AND the per-arm andi) keep b210's mfc1/or/sb chain in $v0 where retail coalesces
   into $v1 (3 sites x 5 words; tried u8 locals, f0/v declaration orders, inline
   stores — no shift). Same family as cmmScript func_0024c0e0's conversion-coloring
   floor. Also measured: outer state switch needs cases declared 0,1,2,3 ascending
   (reversed beq chain 3,2,1,0 + beqz); inner 0x39 dispatch is a 3-way if/else-if
   chain (x==0 / x==1 / x==2) whose x==2 test reuses the dispatch's $a1=2 constant;
   D_005DC7D0 must be indexed (`&D_005DC7D0[idx*0x54]`) or b210 hoists the base into
   a saved reg and rotates obj to $s1. All verified against this function's retail.
   Re-measured this wave: two fresh m2c-draft-based reconstructions (285, then the
   same with 3-way if/else-if dispatch + indexed D_005DC7D0, 279) both far above
   the recorded 16 — the exact winning recipe is not recoverable from the
   truncated note; confirmed func_004553c0 takes ONE arg (the m2c draft's 2nd arg
   is wrong), and the gated conversion needs the explicit `2.1474836e9f > f0`
   guard to keep the c.ole.s/bc1t + per-arm andi. 16 remains the measured best. */
/* measured 2026-09-17 full pragma_sweep --pairs: banked 15 via measure_guarded; */
/* best stays 15 (ties: loopinv on, strength off, unroll off and pairs; 26-group */
/* prop/dead pairs; 234-235 csoff group, 277-281 schedule group, 310-331 peephole */
/* group). No pair wins; floor stands. */
/* MATCHED 2026-09-18.  The three `*(u8 *)(obj + 0x38) = ...` sites had the
   float-to-unsigned-byte conversion written out by hand (compare against
   2.1474836e9f, subtract, or in 0x80000000, mask).  b210 generates exactly
   that sequence for a plain `(u8)f0` cast, and its own version colours the
   result $v1 with the constant in $v0 - the hand-written form does the
   reverse, which was the whole 15-word residual.  Writing the cast fixes all
   three at once; fixing only the two shallow sites leaves 5. */
// FUN_00348330
s32 func_00348330(u8 *arg0) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    switch (*(s8 *)(obj + 4)) {
    case 0:
        break;
    case 1: {
        if (H_Cdvd_IsFileLoaded(*(struct HCdvd **)(obj + 0)) == 0) {
            return 0;
        }
        {
            u32 h = *(u32 *)(obj + 8);
            if (h != 0) {
                func_004b1150(h);
                *(u32 *)(obj + 8) = 0;
            }
        }
        {
            s32 nv = func_004b1130(*(s32 *)(*(u8 **)(obj + 0) + 0x110));
            *(s32 *)(obj + 8) = nv;
            func_004b1250(nv, obj + 0x18);
            func_004b1290(*(s32 *)(obj + 8), *(f32 *)(obj + 0x24), *(f32 *)(obj + 0x28), *(f32 *)(obj + 0x2C));
            func_004b13d0(*(s32 *)(obj + 8), *(f32 *)(obj + 0x30));
            func_004b13f0(*(s32 *)(obj + 8), obj + 0x34);
            if (*(u8 *)(obj + 0x48) == 1) {
                s32 nv2 = func_004b11b0(*(s32 *)(obj + 8));
                *(s32 *)(obj + 0x44) = nv2;
                func_004b1250(nv2, obj + 0x4C);
                func_004b1290(*(s32 *)(obj + 0x44), *(f32 *)(obj + 0x58), *(f32 *)(obj + 0x5C), *(f32 *)(obj + 0x60));
                func_004b13d0(*(s32 *)(obj + 0x44), *(f32 *)(obj + 0x64));
                func_004b13f0(*(s32 *)(obj + 0x44), obj + 0x68);
            }
        }
        *(u16 *)(obj + 0xC) = 0;
        *(s8 *)(obj + 4) += 1;
        break;
    }
    case 2: {
        s16 cnt = *(s16 *)(obj + 0x3E);
        if (cnt > 0) {
            *(s16 *)(obj + 0x3E) = func_002b2d00(cnt, 1, 0, 0, 1);
            return 0;
        }
        {
            u8 mode = *(u8 *)(obj + 0x39);
            if (mode == 0) {
                f32 f0 = func_002b2aa0(0, 0.0f, *(f32 *)(obj + 0x40), (f32)*(s16 *)(obj + 0x3C), (f32)*(s16 *)(obj + 0x3A));
                *(u8 *)(obj + 0x38) = (u8)f0;
            } else if (mode == 1) {
                f32 f0 = func_002b2aa0(0, *(f32 *)(obj + 0x40), 0.0f, (f32)*(s16 *)(obj + 0x3C), (f32)*(s16 *)(obj + 0x3A));
                *(u8 *)(obj + 0x38) = (u8)f0;
                if (*(s16 *)(obj + 0x3C) >= *(s16 *)(obj + 0x3A)) {
                    *(s8 *)(obj + 4) = 3;
                }
            } else if (mode == 2) {
                s16 h = *(s16 *)(obj + 0x3A);
                s32 half = h / 2;
                {
                    f32 f0 = func_002b2aa0(1, 0.0f, 255.0f, (f32)*(s16 *)(obj + 0x3C), (f32)half);
                    *(u8 *)(obj + 0x38) = (u8)f0;
                }
            }
        }
        {
            *(s16 *)(obj + 0x3C) = func_002b2cb0(*(s16 *)(obj + 0x3C), 1, *(s16 *)(obj + 0x3A), 0, 1);
            if (*(s16 *)(obj + 0x3C) < *(s16 *)(obj + 0x3A)) {
                *(u8 *)(obj + 0x37) = *(u8 *)(obj + 0x38);
                func_004b13f0(*(s32 *)(obj + 8), obj + 0x34);
                if (*(u8 *)(obj + 0x48) == 1) {
                    *(u8 *)(obj + 0x6B) = *(u8 *)(obj + 0x38);
                    func_004b13f0(*(s32 *)(obj + 0x44), obj + 0x68);
                }
            }
        }
        func_004b1190(*(u8 **)(obj + 8));
        func_004b11d0((s32)&D_005DC7D0[*(u8 *)(obj + 0x14) * 0x54], *(s32 *)(obj + 8));
        if (*(u8 *)(obj + 0x48) == 1) {
            func_004b1190(*(u8 **)(obj + 0x44));
            func_004b11d0((s32)&D_005DC7D0[*(u8 *)(obj + 0x14) * 0x54], *(s32 *)(obj + 0x44));
        }
        {
            s32 lim = *(s32 *)(obj + 0x10);
            if (lim == -1) {
                if (func_004b1520(*(s32 *)(obj + 8)) == 0) {
                    *(s8 *)(obj + 4) = 3;
                }
            } else {
                *(u16 *)(obj + 0xC) = func_002b2cb0(*(u16 *)(obj + 0xC), 1, lim, 0, 1);
                if (*(u16 *)(obj + 0xC) >= *(s32 *)(obj + 0x10)) {
                    *(s8 *)(obj + 4) = 3;
                }
            }
        }
        break;
    }
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}
// FUN_00348840
void func_00348840(u8 *arg0) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    u32 p = *(u32 *)(obj + 8);
    if (p != 0) {
        func_004b1150(p);
        *(u32 *)(obj + 8) = 0;
    }
    if (*(u8 *)(obj + 0x48) == 1) {
        u32 q = *(u32 *)(obj + 0x44);
        if (q != 0) {
            func_004b1150(q);
            *(u32 *)(obj + 0x44) = 0;
        }
    }
    H_Cdvd_Destroy(*(struct HCdvd **)obj);
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_003488D0
u8 *func_003488d0(u8 *arg0, u8 *arg1, s8 arg2) {
    u8 *ret;
    u8 *blk;

    func_0044ea90(D_0064A4A0, 0x7F5);
    blk = D_008873F4[0](1, 0x70, 0x40000);
    ret = (u8 *)(s32)func_00451fc0((void *)(arg0), (const void *)(D_0064A5E8), 0xF, 0, 0, func_00348330, func_00348840, (u8 *)(blk));
    *(s8 *)(blk + 4) = 0;
    *(s8 *)(blk + 0x14) = arg2;
    func_00440b68(D_00763A28, D_0064A4A0, 0x805);
    *(u8 **)(blk + 0) = func_00454a60(arg1, 0);
    *(u32 *)(blk + 0x40) = 0x437F0000;
    return ret;
}
// FUN_003489C0
void func_003489c0(u8 *arg0, CmbVec3f *src, f32 f0, f32 f1, f32 f2, f32 f3, CmbRGBA col, u16 arg3, u32 arg4) {
    CmbVec3f tmp = *src;
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(s8 *)(obj + 4) = 1;
    *(CmbVec3f *)(obj + 0x18) = tmp;
    *(f32 *)(obj + 0x24) = f0;
    *(f32 *)(obj + 0x28) = f1;
    *(f32 *)(obj + 0x2C) = f2;
    *(f32 *)(obj + 0x30) = f3;
    *(CmbRGBA *)(obj + 0x34) = col;
    *(f32 *)(obj + 0x40) = (f32)col.c3;
    *(u16 *)(obj + 0x3C) = 0;
    *(u16 *)(obj + 0x3A) = arg3;
    *(u8 *)(obj + 0x39) = 0;
    *(u32 *)(obj + 0x10) = arg4;
}

// FUN_00348A90
void func_00348a90(u8 *arg0, CmbVec3f *src1, CmbRGBA arg2, u16 arg3, u32 arg4, CmbVec3f *src2, CmbRGBA arg6, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7) {
    CmbVec3f tmp1 = *src1;
    CmbVec3f tmp2 = *src2;
    u8 *obj = *(u8 **)(arg0 + 0x38);
    f32 farg2 = *(f32 *)&arg2;
    *(s8 *)(obj + 4) = 1;
    *(CmbVec3f *)(obj + 0x18) = tmp1;
    *(f32 *)(obj + 0x24) = f0;
    *(f32 *)(obj + 0x28) = f1;
    *(f32 *)(obj + 0x2C) = f2;
    *(f32 *)(obj + 0x30) = f3;
    *(CmbRGBA *)(obj + 0x34) = arg2;
    *(f32 *)(obj + 0x40) = (f32)((u8 *)&farg2)[3];
    *(u16 *)(obj + 0x3C) = 0;
    *(u16 *)(obj + 0x3A) = arg3;
    *(u8 *)(obj + 0x39) = 0;
    *(u32 *)(obj + 0x10) = arg4;
    *(CmbVec3f *)(obj + 0x4C) = tmp2;
    *(f32 *)(obj + 0x58) = f4;
    *(f32 *)(obj + 0x5C) = f5;
    *(f32 *)(obj + 0x60) = f6;
    *(f32 *)(obj + 0x64) = f7;
    *(CmbRGBA *)(obj + 0x68) = arg6;
    *(u8 *)(obj + 0x48) = 1;
}

// FUN_00348BE0
s32 func_00348be0(u8 *arg0) {
    return H_Cdvd_IsFileLoaded(*(struct HCdvd **)(*(u8 **)(arg0 + 0x38))) != 0;
}

// FUN_00348C10
u32 func_00348c10(u8 *arg0) {
    return *(s8 *)(*(u8 **)(arg0 + 0x38) + 4) == 2;
}
// FUN_00348C30
void func_00348c30(u8 *arg0, u16 arg1) {
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x3E) = arg1;
}

/* Build the channel gradient in its own value scope. This genuine inline
 * color constructor preserves the channel/base lifetimes without sharing the
 * controller's handle and index temporaries. */
static inline FclDrawColor cmbFiveSpriteColor(s32 base)
{
    s32 red;
    s32 green;
    s32 blue;
    red = func_002b2cb0(base, 10, 0xFF, 0, 1) & 0xFF;
    green = func_002b2cb0(base + 0x37, 10, 0xFF, 0, 1) & 0xFF;
    blue = func_002b2cb0(base + 0xF2, 10, 0xFF, 0, 1) & 0xFF;
    return func_002b2a60(red, green, blue, 0xFF);
}

/* Create five colored sprites and configure their bounds animations. The
 * final sprite's completion state controls this task's -1 completion return.
 * Native b210 -O2: 1560/1568 bytes plus eight verified zero alignment bytes.
 * Full source, contract and sibling proof:
 * docs/probe_archive/yCmb_angle_forwarding_20260922.md. */
// FUN_00348C40
#pragma push
s32 func_00348c40(u8 *task) {
    s32 index;
    u8 *handleSlot;
    u8 *updatedHandleSlot;
    u8 *work;
    CmbFiveSpriteSetup setup;
    FclDrawColor gradientColor;
    FclDrawColor lastGradientColor;
    FclDrawColor solidColor;
    /* Initialize once, then wait for the fifth sprite to finish. */
    work = *(u8 **)(task + 0x38);
    switch (*(s8 *)(work + 1)) {
    case 0:
        /* The task work owns five consecutive sprite handles. */
        index = 0;
        while (index < 5) {
            /* handle create: 465,0 -> 5c90 */
            handleSlot = work + index * 4 + 4;
            func_002b2970((u8 *)(&setup.spawnPosition.bits), 0x1D1, 0.0f);
            *(s32 *)handleSlot = func_002b5c90((s32)task, setup.spawnPosition.position);
            /* vec: 9.0,480.0 -> 5db0 */
            func_002b2970((u8 *)(&setup.initialPosition.bits), 0x1D1, 0.0f);
            func_002b29e0((u8 *)(&setup.initialBounds), 9.0f, 480.0f);
            func_002b5db0((u8 *)*(s32 *)handleSlot, setup.initialPosition.position, &setup.initialBounds);
            /* Mode one uses a gradient; other modes use solid blue. */
            if (*(s8 *)work == 1) {
                gradientColor = cmbFiveSpriteColor((index + 2) * 10);
                func_002b5e30((u8 *)*(s32 *)handleSlot, gradientColor);
                if (index == 4) {
                    lastGradientColor = cmbFiveSpriteColor((index + 1) * 10);
                    func_002b5e30((u8 *)*(s32 *)handleSlot, lastGradientColor);
                }
            } else {
                solidColor = func_002b2a60(0, 0x37, 0xF2, 0xFF);
                func_002b5e30((u8 *)*(s32 *)handleSlot, solidColor);
            }
            /* Recompute the handle slot for flags and draw depth. */
            updatedHandleSlot = work + (u32)index * 4U + 4;
            func_002b6130(*(u8 **)updatedHandleSlot, 0xBB);
            func_002b5e20(*(u8 **)updatedHandleSlot, 50.0f);
            index++;
        }
        /* --- five post-loop 5fd0 groups --- */
        /* group offset 4: 465,275 + 8,480 + 380,480, last 0 */
        func_002b2970((u8 *)(&setup.firstStartPosition.bits), 0x1D1, 0.0f);
        func_002b2970((u8 *)(&setup.firstEndPosition.bits), 0x113, 0.0f);
        func_002b29e0((u8 *)(&setup.firstStartBounds), 8.0f, 480.0f);
        func_002b29e0((u8 *)(&setup.firstEndBounds), 380.0f, 480.0f);
        func_002b5fd0((u8 *)*(s32 *)(work + 4), setup.firstStartPosition.position, setup.firstEndPosition.position, &setup.firstStartBounds, &setup.firstEndBounds, 0xF, 0);
        /* group offset 8: same, last 2 */
        func_002b2970((u8 *)(&setup.secondStartPosition.bits), 0x1D1, 0.0f);
        func_002b2970((u8 *)(&setup.secondEndPosition.bits), 0x113, 0.0f);
        func_002b29e0((u8 *)(&setup.secondStartBounds), 8.0f, 480.0f);
        func_002b29e0((u8 *)(&setup.secondEndBounds), 380.0f, 480.0f);
        func_002b5fd0((u8 *)*(s32 *)(work + 8), setup.secondStartPosition.position, setup.secondEndPosition.position, &setup.secondStartBounds, &setup.secondEndBounds, 0xF, 2);
        /* group offset C: same, last 9 */
        func_002b2970((u8 *)(&setup.thirdStartPosition.bits), 0x1D1, 0.0f);
        func_002b2970((u8 *)(&setup.thirdEndPosition.bits), 0x113, 0.0f);
        func_002b29e0((u8 *)(&setup.thirdStartBounds), 8.0f, 480.0f);
        func_002b29e0((u8 *)(&setup.thirdEndBounds), 380.0f, 480.0f);
        func_002b5fd0((u8 *)*(s32 *)(work + 0xC), setup.thirdStartPosition.position, setup.thirdEndPosition.position, &setup.thirdStartBounds, &setup.thirdEndBounds, 0xF, 9);
        /* group offset 0x10: 8,480 + 8,480, last 9 */
        func_002b2970((u8 *)(&setup.fourthStartPosition.bits), 0x1D1, 0.0f);
        func_002b2970((u8 *)(&setup.fourthEndPosition.bits), 0x113, 0.0f);
        func_002b29e0((u8 *)(&setup.fourthStartBounds), 8.0f, 480.0f);
        func_002b29e0((u8 *)(&setup.fourthEndBounds), 8.0f, 480.0f);
        func_002b5fd0((u8 *)*(s32 *)(work + 0x10), setup.fourthStartPosition.position, setup.fourthEndPosition.position, &setup.fourthStartBounds, &setup.fourthEndBounds, 0xF, 9);
        /* group offset 0x14: 465,655 + 8,480 + 8,480, last 9 */
        func_002b2970((u8 *)(&setup.fifthStartPosition.bits), 0x1D1, 0.0f);
        func_002b2970((u8 *)(&setup.fifthEndPosition.bits), 0x28F, 0.0f);
        func_002b29e0((u8 *)(&setup.fifthStartBounds), 8.0f, 480.0f);
        func_002b29e0((u8 *)(&setup.fifthEndBounds), 8.0f, 480.0f);
        func_002b5fd0((u8 *)*(s32 *)(work + 0x14), setup.fifthStartPosition.position, setup.fifthEndPosition.position, &setup.fifthStartBounds, &setup.fifthEndBounds, 0xF, 9);
        *(s8 *)(work + 1) = 1;
        break;
    case 1:
        /* --- state-1 check: 5th handle via 5da0, -1 if byte==1 else 0 --- */
        if (*(s8 *)func_002b5da0((u8 *)*(s32 *)(work + 0x14)) == 1) {
            return -1;
        }
        break;
    default:
        break;
    }
    return 0;
}

#pragma pop
// FUN_00349260
void func_00349260(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

extern u8 D_0064A600[];
s32 func_00348c40(u8 *arg0);

// FUN_00349290
u8 *func_00349290(u8 *arg0, u8 arg1) {
    u8 *blk;
    u8 *ret;

    func_0044ea90(D_0064A4A0, 0x8B9);
    blk = D_008873F4[0](1, 0x18, 0x40000);
    ret = (u8 *)(s32)func_00451fc0((void *)(arg0), (const void *)(D_0064A600), 0xF, 0, 0, func_00348c40, func_00349260, (u8 *)(blk));
    *(s8 *)(blk + 0) = arg1;
    *(s8 *)(blk + 1) = 0;
    return ret;
}
