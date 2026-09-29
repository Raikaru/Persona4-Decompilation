/* Consolidated Persona 4 source units. */
/* Original translation unit y_CmbCardEff.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_color.h"
#include "type.h"
#include "effect_update_internal.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "fcl_draw_task.h"
#include "cmb_card_eff.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);
typedef FclVec3 CmbVec3f;
typedef FclVec2 CmbVec2f;
typedef FclDrawColor CmbRGBA;

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
void func_00348a90(u8 *arg0, CmbVec3f src1, f32 f0, f32 f1, f32 f2, f32 f3, CmbRGBA arg2, u16 arg3, u32 arg4, CmbVec3f src2, f32 f4, f32 f5, f32 f6, f32 f7, CmbRGBA arg6);
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
            *(FclVec2 *)&tmp = func_002b2970(0.0f, 0.0f);
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
static inline void cmbSetMove(u8 *arg0, s8 arg1, CmbVec2f arg2, CmbVec2f arg3, u16 arg4) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    p += (s32)arg1 * 0x84;
    *(CmbVec2f *)(p + 0x20) = arg2;
    *(CmbVec2f *)(p + 0x10) = *(CmbVec2f *)(p + 0x20);
    *(CmbVec2f *)(p + 0x18) = arg3;
    *(u16 *)(p + 0x2A) = 0;
    *(u16 *)(p + 0x28) = arg4;
    *(s8 *)(p + 0xC) |= 1;
}
static inline void cmbSetColor(u8 *arg0, s8 arg1, CmbRGBA start, CmbRGBA end, u16 n) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    p += (s32)arg1 * 0x84;
    *(CmbRGBA *)(p + 0x84) = start;
    *(CmbRGBA *)(p + 0x7C) = *(CmbRGBA *)(p + 0x84);
    *(CmbRGBA *)(p + 0x80) = end;
    *(s16 *)(p + 0x88) = 0;
    *(s16 *)(p + 0x8A) = n;
    *(s8 *)(p + 0xC) |= 4;
}
static inline void cmbAddPath(u8 *arg0, s8 arg1, CmbVec2f pos, s16 n) {
    u8 *slot = *(u8 **)(arg0 + 0x38);
    s32 index = *(s8 *)(slot + arg1 * 0x84 + 0x68);
    u8 *table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
    *(CmbVec2f *)(table + arg1 * 0x84 + 0x2C) = pos;
    *(s16 *)(table + arg1 * 0x84 + 0x34) = n;
    *(s8 *)(slot + arg1 * 0x84 + 0xC) |= 8;
    *(s8 *)(slot + arg1 * 0x84 + 0x68) = func_002b2cb0(*(s8 *)(slot + arg1 * 0x84 + 0x68), 1, 5, 0, 1);
}
// FUN_0033FC80
s32 func_0033fc80(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *obj;
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
            cmbSetColor(arg0, i0, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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
            cmbSetMove(arg0, 0, func_002b2970(10.0f, 212.0f), func_002b2970(230.0f, 212.0f), 5);
            cmbSetColor(arg0, 0, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(arg0, 1, func_002b2970(10.0f, 212.0f), func_002b2970(230.0f, 212.0f), 5);
            cmbSetColor(arg0, 1, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 1, func_002b2970(0x19F, 212.0f), 5);
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
        func_003489c0(*(u8 **)(obj + 0x64C), func_002b29a0(0.0f, 5.0f, 30.0f),
                      0.0f, 0.0f, 0.0f, 1.0f,
                      func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
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
                cmbSetMove(arg0, i9, *(CmbVec2f *)(obj + (s32)i9 * 0x84 + 0x20), func_002b2970(323.0f, 217.0f), 3);
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              func_002b2970(339.0f, 217.0f), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        i10 = 0;
        while (i10 < 2) {
            cmbSetColor(arg0, i10, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 || *(s8 *)(obj + 0x114) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 3) {
            cmbSetColor(arg0, i0, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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
            cmbSetMove(arg0, 0, func_002b2970(-86.0f, 297.0f), func_002b2970(185.0f, 297.0f), 5);
            cmbSetColor(arg0, 0, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(arg0, 1, func_002b2970(-86.0f, 297.0f), func_002b2970(185.0f, 297.0f), 5);
            cmbSetColor(arg0, 1, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 1, func_002b2970(456.0f, 297.0f), 5);
            cmbSetMove(arg0, 2, func_002b2970(-86.0f, 297.0f), func_002b2970(185.0f, 297.0f), 5);
            cmbSetColor(arg0, 2, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 2, func_002b2970(456.0f, 297.0f), 5);
            cmbAddPath(arg0, 2, func_002b2970(320.0f, 104.0f), 5);
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
        func_003489c0(*(u8 **)(obj + 0x64C), func_002b29a0(0.0f, -5.0f, 30.0f), 0.0f, 0.0f, 0.0f, iGpffff8360, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
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
                cmbSetMove(arg0, i9, *(CmbVec2f *)(obj + (s32)i9 * 0x84 + 0x20), func_002b2970(323.0f, 217.0f), 3);
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot);
                func_003482d0(*(u8 **)slot, *(CmbVec2f *)(ret + 0x134), func_002b2970(339.0f, 217.0f), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 3) {
            cmbSetColor(arg0, i10, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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

// FUN_00341640
s32 func_00341640(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
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
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 || *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 4) {
            cmbSetColor(arg0, i0, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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
            cmbSetMove(arg0, 0, func_002b2970(-82.0f, 217.0f), func_002b2970(188.0f, 217.0f), 5);
            cmbSetColor(arg0, 0, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(arg0, 1, func_002b2970(-82.0f, 217.0f), func_002b2970(188.0f, 217.0f), 5);
            cmbSetColor(arg0, 1, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 1, func_002b2970(458.0f, 217.0f), 5);
            cmbSetMove(arg0, 2, func_002b2970(-82.0f, 217.0f), func_002b2970(188.0f, 217.0f), 5);
            cmbSetColor(arg0, 2, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 2, func_002b2970(458.0f, 217.0f), 5);
            cmbAddPath(arg0, 2, func_002b2970(323.0f, 337.0f), 5);
            cmbSetMove(arg0, 3, func_002b2970(-82.0f, 217.0f), func_002b2970(188.0f, 217.0f), 5);
            cmbSetColor(arg0, 3, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 3, func_002b2970(458.0f, 217.0f), 5);
            cmbAddPath(arg0, 3, func_002b2970(323.0f, 337.0f), 5);
            cmbAddPath(arg0, 3, func_002b2970(323.0f, 82.0f), 5);
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
        func_003489c0(*(u8 **)(obj + 0x64C), func_002b29a0(0.0f, 5.0f, 30.0f), 0.0f, 0.0f, 0.0f, iGpffff8360, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
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
                cmbSetMove(arg0, i9, *(CmbVec2f *)(obj + (s32)i9 * 0x84 + 0x20), func_002b2970(323.0f, 217.0f), 3);
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot);
                func_003482d0(*(u8 **)slot, *(CmbVec2f *)(ret + 0x134), func_002b2970(339.0f, 217.0f), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 4) {
            cmbSetColor(arg0, i10, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
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

// FUN_003427A0
s32 func_003427a0(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
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
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 || *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 || *(s8 *)(obj + 0x21C) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 5) {
            cmbSetColor(arg0, i0, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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
            cmbSetMove(arg0, 0, func_002b2970(-95.0f, 182.0f), func_002b2970(185.0f, 182.0f), 5);
            cmbSetColor(arg0, 0, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbSetMove(arg0, 1, func_002b2970(-95.0f, 182.0f), func_002b2970(185.0f, 182.0f), 5);
            cmbSetColor(arg0, 1, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 1, func_002b2970(465.0f, 182.0f), 5);
            cmbSetMove(arg0, 2, func_002b2970(-95.0f, 182.0f), func_002b2970(185.0f, 182.0f), 5);
            cmbSetColor(arg0, 2, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 2, func_002b2970(465.0f, 182.0f), 5);
            cmbAddPath(arg0, 2, func_002b2970(239.0f, 343.0f), 5);
            cmbSetMove(arg0, 3, func_002b2970(-95.0f, 182.0f), func_002b2970(185.0f, 182.0f), 5);
            cmbSetColor(arg0, 3, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 3, func_002b2970(465.0f, 182.0f), 5);
            cmbAddPath(arg0, 3, func_002b2970(239.0f, 343.0f), 5);
            cmbAddPath(arg0, 3, func_002b2970(411.0f, 343.0f), 5);
            cmbSetMove(arg0, 4, func_002b2970(-95.0f, 182.0f), func_002b2970(185.0f, 182.0f), 5);
            cmbSetColor(arg0, 4, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 5);
            cmbAddPath(arg0, 4, func_002b2970(465.0f, 182.0f), 5);
            cmbAddPath(arg0, 4, func_002b2970(239.0f, 343.0f), 5);
            cmbAddPath(arg0, 4, func_002b2970(411.0f, 343.0f), 5);
            cmbAddPath(arg0, 4, func_002b2970(325.0f, 83.0f), 5);
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
        func_003489c0(*(u8 **)(obj + 0x64C), func_002b29a0(0.0f, 5.0f, 30.0f), 0.0f, 0.0f, 0.0f, iGpffff8360, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
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
                cmbSetMove(arg0, i9, *(CmbVec2f *)(obj + (s32)i9 * 0x84 + 0x20), func_002b2970(323.0f, 217.0f), 3);
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_003482d0(*(u8 **)slot2, *(CmbVec2f *)(ret + 0x134), func_002b2970(339.0f, 217.0f), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 5) {
            cmbSetColor(arg0, i10, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
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

// FUN_00343CF0
s32 func_00343cf0(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
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
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 || *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 || *(s8 *)(obj + 0x21C) != 0 || *(s8 *)(obj + 0x2A0) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 6) {
            cmbSetColor(arg0, i0, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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
            cmbSetMove(arg0, 0, func_002b2970(421.0f, -43.0f), func_002b2970(321.0f, 70.0f), 4);
            cmbSetColor(arg0, 0, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbSetMove(arg0, 1, func_002b2970(421.0f, -43.0f), func_002b2970(321.0f, 70.0f), 4);
            cmbSetColor(arg0, 1, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(arg0, 1, func_002b2970(186.0f, 143.0f), 4);
            cmbSetMove(arg0, 2, func_002b2970(421.0f, -43.0f), func_002b2970(321.0f, 70.0f), 4);
            cmbSetColor(arg0, 2, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(arg0, 2, func_002b2970(186.0f, 143.0f), 4);
            cmbAddPath(arg0, 2, func_002b2970(186.0f, 285.0f), 4);
            cmbSetMove(arg0, 3, func_002b2970(421.0f, -43.0f), func_002b2970(321.0f, 70.0f), 4);
            cmbSetColor(arg0, 3, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(arg0, 3, func_002b2970(186.0f, 143.0f), 4);
            cmbAddPath(arg0, 3, func_002b2970(186.0f, 285.0f), 4);
            cmbAddPath(arg0, 3, func_002b2970(321.0f, 348.0f), 4);
            cmbSetMove(arg0, 4, func_002b2970(421.0f, -43.0f), func_002b2970(321.0f, 70.0f), 4);
            cmbSetColor(arg0, 4, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(arg0, 4, func_002b2970(186.0f, 143.0f), 4);
            cmbAddPath(arg0, 4, func_002b2970(186.0f, 285.0f), 4);
            cmbAddPath(arg0, 4, func_002b2970(321.0f, 348.0f), 4);
            cmbAddPath(arg0, 4, func_002b2970(456.0f, 285.0f), 4);
            cmbSetMove(arg0, 5, func_002b2970(421.0f, -43.0f), func_002b2970(321.0f, 70.0f), 4);
            cmbSetColor(arg0, 5, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 4);
            cmbAddPath(arg0, 5, func_002b2970(186.0f, 143.0f), 4);
            cmbAddPath(arg0, 5, func_002b2970(186.0f, 285.0f), 4);
            cmbAddPath(arg0, 5, func_002b2970(321.0f, 348.0f), 4);
            cmbAddPath(arg0, 5, func_002b2970(456.0f, 285.0f), 4);
            cmbAddPath(arg0, 5, func_002b2970(456.0f, 143.0f), 4);
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
        func_003489c0(*(u8 **)(obj + 0x64C), func_002b29a0(0.0f, 5.0f, 30.0f), 0.0f, 0.0f, 0.0f, 1.5f, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28);
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
                cmbSetMove(arg0, i9, *(CmbVec2f *)(obj + (s32)i9 * 0x84 + 0x20), func_002b2970(323.0f, 217.0f), 3);
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_003482d0(*(u8 **)slot2, *(CmbVec2f *)(ret + 0x134), func_002b2970(339.0f, 217.0f), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 6) {
            cmbSetColor(arg0, i10, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
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

/* Each of the twelve cards shares the native move, color and path
 * operations used by the smaller combination layouts. */
// FUN_00345700
s32 func_00345700(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *obj;
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
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 || *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 || *(s8 *)(obj + 0x21C) != 0 || *(s8 *)(obj + 0x2A0) != 0 || *(s8 *)(obj + 0x324) != 0 || *(s8 *)(obj + 0x3A8) != 0 || *(s8 *)(obj + 0x42C) != 0 || *(s8 *)(obj + 0x4B0) != 0 || *(s8 *)(obj + 0x534) != 0 || *(s8 *)(obj + 0x5B8) != 0) {
        return 0;
    }
    if (datGetFlag(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 12) {
            cmbSetColor(arg0, i0, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
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
            cmbSetMove(arg0, 0, func_002b2970(326.0f, 224.0f), func_002b2970(0x141, 70.0f), 8);
            cmbSetColor(arg0, 0, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(arg0, 1, func_002b2970(326.0f, 224.0f), func_002b2970(0x141, 70.0f), 8);
            cmbSetColor(arg0, 1, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 1, func_002b2970(250.0f, 95.0f), 5);
            cmbSetMove(arg0, 2, func_002b2970(326.0f, 224.0f), func_002b2970(0x141, 70.0f), 8);
            cmbSetColor(arg0, 2, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 2, func_002b2970(250.0f, 95.0f), 5);
            cmbAddPath(arg0, 2, func_002b2970(175.0f, 141.0f), 5);
            cmbSetMove(arg0, 3, func_002b2970(326.0f, 224.0f), func_002b2970(156.0f, 232.0f), 8);
            cmbSetColor(arg0, 3, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(arg0, 4, func_002b2970(326.0f, 224.0f), func_002b2970(156.0f, 232.0f), 8);
            cmbSetColor(arg0, 4, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 4, func_002b2970(180.0f, 322.0f), 5);
            cmbSetMove(arg0, 5, func_002b2970(326.0f, 224.0f), func_002b2970(156.0f, 232.0f), 8);
            cmbSetColor(arg0, 5, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 5, func_002b2970(180.0f, 322.0f), 5);
            cmbAddPath(arg0, 5, func_002b2970(250.0f, 0x16B), 5);
            cmbSetMove(arg0, 6, func_002b2970(326.0f, 224.0f), func_002b2970(0x141, 388.0f), 8);
            cmbSetColor(arg0, 6, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(arg0, 7, func_002b2970(326.0f, 224.0f), func_002b2970(0x141, 388.0f), 8);
            cmbSetColor(arg0, 7, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 7, func_002b2970(0x187, 0x16B), 5);
            cmbSetMove(arg0, 8, func_002b2970(326.0f, 224.0f), func_002b2970(0x141, 388.0f), 8);
            cmbSetColor(arg0, 8, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 8, func_002b2970(0x187, 0x16B), 5);
            cmbAddPath(arg0, 8, func_002b2970(458.0f, 322.0f), 5);
            cmbSetMove(arg0, 9, func_002b2970(326.0f, 224.0f), func_002b2970(482.0f, 232.0f), 8);
            cmbSetColor(arg0, 9, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbSetMove(arg0, 10, func_002b2970(326.0f, 224.0f), func_002b2970(482.0f, 232.0f), 8);
            cmbSetColor(arg0, 10, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 10, func_002b2970(462.0f, 141.0f), 5);
            cmbSetMove(arg0, 11, func_002b2970(326.0f, 224.0f), func_002b2970(482.0f, 232.0f), 8);
            cmbSetColor(arg0, 11, func_002b2a60(0xFF, 0xFF, 0xFF, 0U), func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 8);
            cmbAddPath(arg0, 11, func_002b2970(462.0f, 141.0f), 5);
            cmbAddPath(arg0, 11, func_002b2970(0x187, 95.0f), 5);
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
                slot = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot + 0x20) + 12.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                fvalue = iGpffff8508;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x1A0) = fvalue;
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_00348a90(*(u8 **)(obj + 0x64C),
                      func_002b29a0(0.0f, -5.0f, 30.0f),
                      0.0f, 0.0f, 0.0f, iGpffff850c,
                      func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), 0, 0x28,
                      func_002b29a0(35.0f, 5.0f, 30.0f),
                      0.0f, 0.0f, 31.5f, iGpffff850c,
                      func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU));
        *(s16 *)(obj + 0x63C) = 8;
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
                cmbSetMove(arg0, i9, *(CmbVec2f *)(obj + (s32)i9 * 0x84 + 0x20), func_002b2970(0x143, 217.0f), 3);
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              func_002b2970(0x153, 217.0f), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 12) {
            cmbSetColor(arg0, i10, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFFU), func_002b2a60(0xFF, 0xFF, 0xFF, 0U), 0);
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
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
void func_003489c0(u8 *arg0, CmbVec3f src, f32 f0, f32 f1, f32 f2, f32 f3, CmbRGBA col, u16 arg3, u32 arg4) {
    CmbVec3f tmp = src;
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
void func_00348a90(u8 *arg0, CmbVec3f src1, f32 f0, f32 f1, f32 f2, f32 f3, CmbRGBA arg2, u16 arg3, u32 arg4, CmbVec3f src2, f32 f4, f32 f5, f32 f6, f32 f7, CmbRGBA arg6) {
    CmbVec3f tmp1 = src1;
    CmbVec3f tmp2 = src2;
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
    u8 red;
    u8 green;
    u8 blue;
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
            *(s32 *)handleSlot = func_002b5c90((s32)task, func_002b2970(0x1D1, 0.0f));
            /* vec: 9.0,480.0 -> 5db0 */
            func_002b5db0((u8 *)*(s32 *)handleSlot, func_002b2970(0x1D1, 0.0f), func_002b29e0(9.0f, 480.0f));
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
        func_002b5fd0((u8 *)*(s32 *)(work + 4), func_002b2970(0x1D1, 0.0f), func_002b2970(0x113, 0.0f),
                      func_002b29e0(8.0f, 480.0f), func_002b29e0(380.0f, 480.0f), 0xF, 0);
        /* group offset 8: same, last 2 */
        func_002b5fd0((u8 *)*(s32 *)(work + 8), func_002b2970(0x1D1, 0.0f), func_002b2970(0x113, 0.0f),
                      func_002b29e0(8.0f, 480.0f), func_002b29e0(380.0f, 480.0f), 0xF, 2);
        /* group offset C: same, last 9 */
        func_002b5fd0((u8 *)*(s32 *)(work + 0xC), func_002b2970(0x1D1, 0.0f), func_002b2970(0x113, 0.0f),
                      func_002b29e0(8.0f, 480.0f), func_002b29e0(380.0f, 480.0f), 0xF, 9);
        /* group offset 0x10: 8,480 + 8,480, last 9 */
        func_002b5fd0((u8 *)*(s32 *)(work + 0x10), func_002b2970(0x1D1, 0.0f), func_002b2970(0x113, 0.0f),
                      func_002b29e0(8.0f, 480.0f), func_002b29e0(8.0f, 480.0f), 0xF, 9);
        /* group offset 0x14: 465,655 + 8,480 + 8,480, last 9 */
        func_002b5fd0((u8 *)*(s32 *)(work + 0x14), func_002b2970(0x1D1, 0.0f), func_002b2970(0x28F, 0.0f),
                      func_002b29e0(8.0f, 480.0f), func_002b29e0(8.0f, 480.0f), 0xF, 9);
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
u8 *func_00349290(u8 *arg0, s8 arg1) {
    u8 *blk;
    u8 *ret;

    func_0044ea90(D_0064A4A0, 0x8B9);
    blk = D_008873F4[0](1, 0x18, 0x40000);
    ret = (u8 *)(s32)func_00451fc0((void *)(arg0), (const void *)(D_0064A600), 0xF, 0, 0, func_00348c40, func_00349260, (u8 *)(blk));
    *(s8 *)(blk + 0) = arg1;
    *(s8 *)(blk + 1) = 0;
    return ret;
}
