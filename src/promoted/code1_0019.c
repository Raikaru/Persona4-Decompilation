#include "btl_skill_target_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} P4_95730_Vec3;
typedef struct P4_95730_Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4_95730_Vec4;
typedef struct P4_95730_Bytes4 {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
} P4_95730_Bytes4;
typedef struct DatUnit DatUnit;
extern u32 func_00231af0(DatUnit *unit, u8 genus, u16 id);

extern void func_00106390(s32 arg0, s32 arg1);
extern s16 func_0022cb90(void);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0045c870(void *arg0, s32 arg1);
extern void func_0048a000(void);
extern f32 fGpffff8474;
extern u8 *RpGeometryLock(u8 *arg0, s32 arg1);
extern void func_003c22f0(void *arg0);
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern s32 func_001f0a50(u8 *arg0);
extern s32 func_001f11e0(s64 arg0);
extern s32 func_0023d8e0(u8 *arg0, u16 arg1);
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;
extern s64 btlGetUID(void);

extern s64 func_0029cc00(s32 arg0);
extern u8 *func_00105510(s16 arg0);
extern void func_00243ec0(u8 *arg0, s16 arg1);
extern s32 func_00243e90(u8 *arg0);
extern void func_0029cf50(s32 arg0);

extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern s32 datGetPartyId(s32 arg0);
extern s32 func_00231580(s32 arg0);
extern s32 func_00231630(s32 arg0);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);
extern u8 *iGpffffb3e0;
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern void memcpy(void *dst, void *src, s32 size);
extern s32 func_002011c0(s32 arg0);
extern s32 datGetFlag(s32 arg0);
extern void func_001b5f70(s32 arg0);
extern s32 func_00192610(u8 *task);
extern s32 func_001926c0(u8 *task);
extern s32 btlUpdateDraw3DFrontTask(u8 *task);
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern s32 func_0022f520(void);
extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern s32 func_0029d020(void);
extern u8 *func_0029d040(void);
extern void func_00105610(s16 arg0);
extern void func_001056e0(s16 arg0, s16 arg1);
extern void func_00105d50(s16 arg0, s32 arg1);
extern void func_0014b990(s32 arg0);
extern void func_00260510(void);
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern void func_00440b68(void *msg, const void *file, s32 line);
extern s32 func_00454a60(s32 arg0, s32 arg1);
extern void H_Cdvd_ReadSync(s32 arg0);
extern s32 H_Cdvd_IsFileLoaded(s32 arg0);
extern void H_Cdvd_Destroy(s32 arg0);
typedef struct RwV3d RwV3d;
extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void func_001958f0(void *arg0, void *arg1);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 func_0022f7d0(u8 *arg0, f32 *arg1, s32 arg2);
extern u8 *func_001b1510(void);
extern void func_001ec1c0(void *arg0, void *arg1, void *arg2);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void func_00195aa0(void *arg0, void *arg1, void *arg2);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern P4_95730_Vec3 D_0060A0D0;
extern f32 effMiscRandFloat(u32 arg0);
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 func_00196bd0(u8 *arg0, u8 *arg1, u8 *arg2);
extern f32 func_0044b950(f32 x, f32 y);
extern f32 fGpffff8048;
extern void func_003dc740(void *dst, const void *src, s32 mode, f32 angle);
extern u8 D_0060A0E0[];
extern void func_0019dea0(u8 *arg0);
extern P4_95730_Vec3 D_0060A100;
extern u8 *(*D_008873E8[])(s32 arg0, s32 arg1);
extern void func_001ee1c0(void);
extern void func_00194660(void);
extern void func_001bdb60(void);
extern void func_001f7260(void);
extern void func_001f9bf0(void);
extern void func_001d6a60(void);
extern void func_001b1850(void);
extern void func_001b60a0(void);
extern void func_001f6100(void);
extern s32 func_002774d0(u8 *arg0);
extern s32 func_001939e0(u8 *task);

extern s32 func_00193840(u8 *arg0, s32 arg1);
extern void func_0010d480(void);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern f32 func_0022cf00(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_00195630(u8 *arg0);
extern u8 *func_00452380(void *arg0);
extern void func_00452080(s32 arg0);

/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *p4_unit_00195530(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 p4_base_add_0019f050(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *p4_entries_001900a0(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 p4_base_add_00194590(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 p4_one_00194470(void)
{
    return 1;
}
static inline s64 p4_sign16_001991c0(s16 value)
{
    return value;
}
static inline s32 p4_table_001951f0(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 p4_add_0019a680(f32 left, f32 right)
{
    return left + right;
}
static inline void p4_d550_store(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    *(u8 **)(address + offset) = stored;
}

extern f32 func_0047a080(s32 arg0, s32 arg1);
extern void func_00479e60(void *arg0, s32 arg1, f32 arg2);
static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    func_00198920(arg0, arg1, arg2, arg3, arg4);
}
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    func_0029db50(arg0, arg1, arg2, arg3);
}
extern void func_00146630(u16 arg0);
extern void func_004787e0(void *arg0);
extern void mdlSetColor(void *arg0, s32 *arg1);
extern void func_0047a0e0(u8 *arg0, s32 arg1, f32 arg2);
extern u8 iGpffffa4d8;
extern void func_001d1540(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001ee430(u8 *arg0);
extern void func_001d7040(s32 arg0);
extern void func_001d6c10(s32 arg0);
extern void func_00194670(u8 *arg0);
extern int func_0047a9d0(void *arg0);
extern void func_0047a9b0(void *arg0);
extern void func_0019d550(u8 *arg0);
extern void func_0047a990(void *arg0);
extern u8 *func_00147530(u8 *arg0, u16 arg1);
extern void func_0019d7a0(u8 *arg0, s32 arg1);
extern void func_0047a810(void *arg0);
extern void func_0047a850(void *arg0);
extern void func_0047a9f0(void *arg0, u16 arg1);
extern u16 func_0047aa00(void *arg0);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void func_0047a830(void *arg0);
extern void func_0047a870(void *arg0);
extern void func_0047a890(void *arg0, float arg1);
extern void func_0047a8a0(void *arg0, float arg1, float arg2);
extern f32 DAT_0076112c;


extern void func_0019d990(u8 *arg0, s32 arg1);
extern void func_0019d7a0(u8 *arg0, s32 arg1);
extern u8 *func_001f7650(u8 *arg0);
extern void func_0014b0c0(u16 arg0, u32 arg1);

extern u8 *func_0019d210(s32 arg0);
extern void func_0019ea60(u8 *arg0, s32 arg1);



extern s32 func_0019be50(u8 *arg0);
extern s32 func_0010d6d0(s16 arg0);
extern u8 *func_00194470(s32 arg0, s32 arg1);
extern float func_001d4380(int arg0);
extern s32 func_00197a80(u8 *arg0);
extern s32 func_0010d740(s16 arg0);
extern s32 func_00109220(u16 arg0);
extern s32 iGpffffb444;
extern s32 btlUnitIsMoving(u8 *arg0);
extern s32 func_0019f8a0(u8 *arg0);
extern s32 func_00232830(s32 arg0, s32 arg1);
extern u8 *btlUnitCreateLookAtPacket(u8 *arg0, f32 *arg1, s32 arg2);
extern s32 datCalcIsLowHp(u8 *arg0);
extern s32 func_00243e30(s32 arg0);
extern void func_0047a120(void *arg0);
extern void func_0047a150(void *arg0);
extern u8 *btlUnitCreateAnimPacket(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern u32 effMiscRand(u32 arg0);
extern u16 *func_0010a900(u16 character);
extern s32 func_0010f4f0(s32 arg0);
extern void btlActionSetState(u8 *arg0, u32 arg1);
extern void func_001b08d0(void *arg0);
extern void btlActionSetUnit(u8 *arg0, u8 *arg1);
extern u8 *func_001b0930(void);
extern s32 func_001b0d70(u8 *arg0);
extern s32 func_0022e630(u8 *arg0);
extern s32 func_00243d80(u8 *arg0);
extern void func_0019ef30(u8 *arg0, u16 arg1);
extern void func_0019f1d0(u8 *arg0);

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    func_0019ef30(arg0, arg1);
}
extern void func_0019e830(u8 *arg0);
extern s32 func_0019e850(u8 *arg0);
extern void func_0019e9d0(u8 *arg0);
extern u8 *func_00457120(void);
extern s32 func_003e8120(u8 *arg0);
extern void func_003c1bd0(s32 arg0);
extern s32 func_003e8110(u8 *arg0);
extern u8 *func_00452380(void *arg0);
extern void func_00452080(s32 arg0);
extern s32 func_00192cd0(void);
extern void func_00194a30(void);
extern void func_0019d670(void);
extern void func_002319c0(s32 arg0);
extern void func_003ef3a0(s32 arg0);
extern void (*jtbl_008873EC[])(void *arg0);
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 func_0018f950(u8 *task);
extern void func_001d78d0(void);
extern void func_00200cb0(void);
extern void func_001f8480(void);
extern void func_00202be0(void);
extern void func_0047d170();
extern s32 func_0047e6f0(void **owner);
extern void func_0019db40(u8 *arg0);
extern void func_001fc1b0(s16 arg0);
extern s32 func_002300f0();
extern void func_0019acd0(u8 *arg0);
extern s32 func_0019ae20();
extern void func_001d6ee0(s32 arg0);
extern void func_0019d3c0();
extern void func_0019d0c0();
extern void func_0019d040(u8 *arg0);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern void func_00479100(void *arg0, void *arg1);
extern u8 D_00794150[];


// FUN_001900A0
void func_001900a0(u8 *arg0)
{
    s32 *entries;
    s32 value;
    s32 i;

    entries = *(s32 **)(arg0 + 0x38);
    i = 0;
    while (i < 9) {
        value = p4_entries_001900a0(i * 4, entries)[1];
        if (value != 0) {
            func_003ef3a0(value);
        }
        i++;
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
// FUN_00190130
s32 func_00190130(s32 arg0)
{
    s32 *work;

    func_0044ea90(D_005F6010, 0x184);
    work = (s32 *)D_008873F4[0](1, 0x1CD20, 0x40000);
    if (work == NULL) {
        return 0;
    }
    return (s32)func_00451fc0((void *)((u8 *)arg0), (const void *)(D_005F6020), 0xF, 0, 0, func_0018f950, func_001900a0, (u8 *)(work));
}
// FUN_00191E20
void *func_00191e20(void *arg0, void *data) {
    if (func_003e8120(func_00457120()) != 0) {
        func_003c1bd0((s32)(uintptr_t)arg0);
    }
    func_003e8110(func_00457120());
    return arg0;
}
/* measured: opt_propagation off is scoped to func_001927c0. */
#pragma opt_propagation off
// FUN_001927C0
void func_001927c0(void)
{
    u8 color[4];
    void (**base)(s32, s32);

    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
    func_00489f80();
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0xFF;
    func_0045c870(color, 0);
    func_0048a000();
}
/* measured: closes opt_propagation around func_001927c0. */
#pragma opt_propagation on
/* measured: opt_propagation off is scoped to func_001928c0. */
#pragma opt_propagation off
/* measured: opt_loop_invariants on is scoped to func_001928c0. */
#pragma opt_loop_invariants on
// FUN_001928C0
void func_001928c0(void)
{
    f32 delta;
    u32 i;
    u32 j;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_3;
    u8 *temp_4;
    u8 *var_4;
    void (**base)(s32, s32);
    void (*callback)(u8 *);

    if (*(s32 *)(iGpffffb3ac + 0xE78) != 0) {
        RpSkyRenderStateSet(2, 0x54);
        RpSkyRenderStateSet(3, 0x757FB);
        base = D_00887300;
        base[0](7, 2);
        base[0](0xE, 0);
        base[0](6, 1);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        RpGeometryLock(
            *(void **)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0xE7C) + 0x10) + 0x18),
            0xFF0);
        temp_3 = iGpffffb3ac;
        var_4 = *(u8 **)(*(u8 **)(*(u8 **)(temp_3 + 0xE7C) + 0x10) + 0x18);
        var_4 = *(u8 **)(var_4 + 0x34);
        *(f32 *)(temp_3 + 0xE80) =
            *(f32 *)(temp_3 + 0xE80) - (delta = fGpffff8474);
        if (*(f32 *)(iGpffffb3ac + 0xE80) <= -1.0f) {
            i = 0;
            while (i < 0x59U) {
                *(f32 *)(var_4 + 4) = *(f32 *)(var_4 + 4) + 1.0f;
                var_4 += 8;
                i++;
            }
            *(f32 *)(iGpffffb3ac + 0xE80) = 0.0f;
        } else {
            j = 0;
            while (j < 0x59U) {
                *(f32 *)(var_4 + 4) =
                    *(f32 *)(var_4 + 4) - delta;
                var_4 += 8;
                j++;
            }
        }
        temp_17 = *(u8 **)(iGpffffb3ac + 0xE7C);
        temp_16 = *(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18);
        func_003c22f0(temp_16);
        if ((*(u16 *)temp_17 & 4) != 0) {
            *(u16 *)(temp_16 + 0xC) |= 1;
        }
        temp_4 = *(u8 **)(*(u8 **)(iGpffffb3ac + 0xE7C) + 0x10);
        callback = *(void (**)(u8 *))(temp_4 + 0x48);
        callback(temp_4);
    }
}
/* measured: closes opt_loop_invariants around func_001928c0. */
#pragma opt_loop_invariants off
/* measured: closes opt_propagation around func_001928c0. */
#pragma opt_propagation on
// FUN_00192AC0
void func_00192ac0(u8 *unusedTask) {
    func_00192cd0();
}
// FUN_00192AE0
void func_00192ae0(void) {
    if (func_00452380(&iGpffffa088) != 0) {
        func_00452080(*(s32 *)(iGpffffb3ac + 0xDC8));
    }
}
// FUN_00192B20
void func_00192b20(void) {
    s32 i;

    for (i = 0x15C0; i <= 0x15FF; i++) {
        func_00106390(i, 0);
    }
    func_00106390(0x1435, 0);
    func_00106390(0x1438, 0);
}






// FUN_00192B90
void func_00192b90(void)
{
    s32 i;
    *(u64 *)&iGpffffa090 = 1;
    iGpffffa098 = 0x100;
    func_0044ea90(D_005F65D0, 0x3A);
    iGpffffb3ac = (u8 *)D_008873E8[0](0xE88, 0x40000);
    memset(iGpffffb3ac, 0, 0xE88);
    *(s32 *)(iGpffffb3ac + 0xC60) = func_002774d0((u8 *)iGpffffb43c);
    for (i = 0x15C0; i <= 0x15FF; i++) {
        func_00106390(i, 0);
    }
    func_00106390(0x1435, 0);
    func_00106390(0x1438, 0);
    func_001ee1c0();
    func_00194660();
    func_001bdb60();
    func_001f7260();
    func_001f9bf0();
    func_001d6a60();
    func_001b1850();
    func_001b60a0();
    func_001f6100();
    *(s32 *)(iGpffffb3ac + 0xC) |= 0x1480877C;
}
// FUN_00192CD0
s32 func_00192cd0(void)
{
    u32 i;
    s32 temp;
    s32 *base;
    func_001b0bf0();
    func_0019d670();
    func_001b68d0();
    func_001b6110();
    func_001d6a70();
    func_001f9c40();
    func_001f73c0();
    func_001bdd30();
    func_001f61b0();
    func_0022cc90();
    func_00194a30();
    func_002777f0(*(s32 *)(iGpffffb3ac + 0xC60));
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x4000) != 0) {
        for (i = 0; (u16)i < 4; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = *(s32 *)((s32)base + (i & 0xFFFF) * 4 + 0xC74);
            if (temp != 0) {
                func_002319c0(temp);
            }
        }
        for (i = 0; (u16)i < 3; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = *(s32 *)((s32)base + (i & 0xFFFF) * 4 + 0xC84);
            if (temp != 0) {
                func_002319c0(temp);
            }
        }
        for (i = 0; (u16)i < (u32)3; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = *(s32 *)((s32)base + (i & 0xFFFF) * 8 + 0xC94);
            if (temp != 0) {
                func_002319c0(temp);
            }
        }
    }
    if (func_00452380(&iGpffffa088) != 0) {
        func_00452080(*(s32 *)(iGpffffb3ac + 0xDC8));
    }
    jtbl_008873EC[0](iGpffffb3ac);
    iGpffffb3ac = NULL;
    return 0;
}
// FUN_00192E90
s32 func_00192e90(s32 arg0)
{
    s32 temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;

    func_00192b90();
    *(s32 *)(iGpffffb3ac + 0xDC8) =
        (s32)func_00451de0((const void *)(&iGpffffa088), 0x10, arg0 == 0, 0, func_00192610, func_00192ac0, (u8 *)(0));
    (s32)func_00451fc0((void *)(*(u8 **)(iGpffffb3ac + 0xDC8)), (const void *)(D_005F65B0), 0x11, arg0 == 0, 0, func_001926c0, 0, (u8 *)(NULL));
    (s32)func_00451fc0((void *)(*(u8 **)(iGpffffb3ac + 0xDC8)), (const void *)(D_005F65C0), 0x11, arg0 == 0, 0, btlUpdateDraw3DFrontTask, 0, (u8 *)(NULL));
    *(void **)(iGpffffb3ac + 0xE20) = (void *)func_001927c0;
    temp_2 = iGpffffb3ac;
    *(u8 **)(temp_2 + 0xE28) = temp_2;
    *(void **)(iGpffffb3ac + 0xE50) = (void *)func_001928c0;
    temp_2_2 = iGpffffb3ac;
    *(u8 **)(temp_2_2 + 0xE58) = temp_2_2;
    *(s32 *)(iGpffffb3ac + 0xDD4) =
        func_002011c0(*(s32 *)(iGpffffb3ac + 0xDC8));
    temp_3 = iGpffffb3ac;
    temp_16 = *(s32 *)(temp_3 + 0xDC8);
    if (arg0 != 0) {
        *(s8 *)(temp_3 + 0xC65) = 0;
        memcpy(iGpffffb3ac + 0xC70, (void *)arg0, 0x3C);
        temp_3_2 = iGpffffb3ac;
        *(u16 *)(temp_3_2 + 0x26C) = *(u16 *)(temp_3_2 + 0xC90);
        temp_3_3 = iGpffffb3ac;
        *(u16 *)(temp_3_3 + 0x26E) = *(u16 *)(temp_3_3 + 0xC92);
        func_001b5f70(2);
    } else {
        *(s8 *)(temp_3 + 0xC65) = 1;
        if (datGetFlag(0x1436) == 0) {
            func_001b5f70(0x12);
        } else {
            func_001b5f70(0x13);
        }
    }
    temp_3_4 = iGpffffb3ac;
    *(s32 *)(temp_3_4 + 0xC) |= 1;
    return temp_16;
}
// FUN_00193060
s32 func_00193060(void)
{
    u8 *var_20;
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 var_21;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_4;

    *(s16 *)(iGpffffb3ac + 0x1C) = 0;
    var_19 = 0;
    var_18 = 0;
    var_17 = 0;
    var_21 = 1;
    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0x10) & 0x10000000) {
        *(s16 *)(temp_4 + 0x1C) = 2;
        return 1;
    }
    var_20 = *(u8 **)(temp_4 + 0x174);
    goto loop_18_check;
loop_18_body:
    if ((*(u16 *)(var_20 + 0x1A) & 1) &&
        !(*(u16 *)(var_20 + 0x18) & 0x20)) {
        temp_16 = *(u8 **)(var_20 + 0x30);
        if ((datCalcIsDead(*(u8 **)(temp_16 + 0xA64), 0) != 0) &&
            (temp_3 = *(u8 **)(temp_16 + 0xA64),
             (*(u16 *)(temp_3 + 0) & 0x20) == 0)) {
            if (*(u8 *)(temp_16 + 0xA2) == 0 &&
                *(u16 *)(temp_3 + 2) == 1) {
                var_21 = 0;
            }
            var_17 += 1;
        } else {
            temp_3_2 = *(u8 *)(temp_16 + 0xA2);
            switch (temp_3_2) {
            case 0:
                var_19 += 1;
                break;
            case 1:
                if (*(s32 *)(temp_16 + 0x9C) & 8) {
                    var_18 += 1;
                }
                break;
            }
        }
    }
    var_20 = *(u8 **)(var_20 + 0x450);
loop_18_check:
    if (var_20 != NULL) {
        goto loop_18_body;
    }
    if (var_21 == 0 || (var_19 == 0 && var_17 != 0)) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 2;
        return 1;
    }
    if (var_19 == 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 3;
        return 1;
    }
    if (func_0022f520() != 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 1;
        return 1;
    }
    if (var_18 == 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 1;
        return 1;
    }
    return 0;
}
// FUN_00193260
s32 func_00193260(void)
{
    u8 *base;
    s32 flags;

    base = iGpffffb3ac;
    flags = *(s32 *)(base + 0x10);
    if ((flags & 0x20000000) != 0) {
        return 0;
    }
    if ((flags & 0x10000000) != 0) {
        return 0;
    }
    if ((*(s32 *)(base + 0xC) & 0x800000) != 0) {
        return func_00232830(
            *(s32 *)(*(u8 **)(*(u8 **)(base + 0x170) + 0x30) + 0xA64),
            0x31E);
    }
    return 0;
}
// FUN_001932F0
s32 func_001932f0(void)
{
    u8 sp50[0x3C];
    s32 var_19;
    u16 var_18;
    u16 temp_17;
    s32 temp_4;
    u16 temp_4_2;
    u16 temp_3;
    u8 *temp_16;

    func_001fc1b0(1);
    temp_17 = func_0029cc00(0) & 0xFFFF;
    temp_16 = (u8 *)(iGpffffb414 + (temp_17 * 0x18));
    memset(sp50, 0, 0x3C);
    *(s32 *)(sp50 + 4) = func_00231580(1);
    var_18 = 1;
    var_19 = 0;
    goto loop_5_check;
loop_5_body:
    temp_4_2 = datGetPartyId(temp_4) & 0xFFFF;
    if ((temp_4_2 != 0) && (var_18 < 4)) {
        ((s32 *)(sp50 + 4))[var_18++] = func_00231580(temp_4_2);
    }
    var_19 = (var_19 + 1) & 0xFFFF;
loop_5_check:
    temp_4 = var_19 & 0xFFFF;
    if (temp_4 < 4) {
        goto loop_5_body;
    }
    *(s32 *)(sp50 + 0x14) = func_00231630(temp_17);
    temp_3 = *(u16 *)(temp_16 + 0x12);
    if ((temp_3 == 0) && (*(u16 *)(temp_16 + 0x14) == 0)) {
        *(u16 *)(sp50 + 0x20) = 0xF0;
        *(u16 *)(sp50 + 0x22) = 1;
    } else {
        *(u16 *)(sp50 + 0x20) = temp_3;
        *(u16 *)(sp50 + 0x22) = *(u16 *)(temp_16 + 0x14);
    }
    func_001029a0(6, sp50, 0x3C, 4);
    return 1;
}

/* Measured: the archived body compiles to object 356B in the 368B window. Retail words at offsets 356, 360, and 364 are all 00000000 (nop); verify therefore accepts the zero-padded tail and reports MATCH. */
// FUN_00193450
s32 func_00193450(void)
{
    extern s16 datGetPartyId(s32 idx);
    extern u32 func_00105610(s16 character);
    extern void func_001056e0(s16 character, s16 value);
    extern void func_00105d50(s16 character, u32 mask);
    u32 var_16;
    u32 dep;

    if (func_0029d020() > 0xA) {
        if (iGpffffb3ac != NULL) {
            iGpffffb3b0 = 0;
            return 0;
        }
        if (iGpffffb3b0 == 0) {
            if (datCalcIsDead(func_00105510(1), 0) != 0) {
                dep = iGpffffb280;
                func_0029db50(0xF, iGpffffb284, dep, 0);
                func_0014b990(*(s32 *)(func_0029d040() + 0x148));
                func_00260510();
                iGpffffb3b0 = 1;
                goto block_13;
            }
            var_16 = 0;
            goto loop_11_check;
loop_11_body:
            if (((s16)datGetPartyId((s32)var_16) != 0) &&
                (func_00105610(datGetPartyId((s32)var_16)) != 0)) {
                func_001056e0(datGetPartyId((s32)var_16), 1);
                func_00105d50(datGetPartyId((s32)var_16), 0x80000);
            }
            var_16 += 1;
loop_11_check:
            if (var_16 < 3U) {
                goto loop_11_body;
            }
            return 1;
        }
    }
block_13:
    return 0;
}
// FUN_001935C0
s32 func_001935c0(void) {
    func_001fc1b0(1);
    return 1;
}
// FUN_00193630
s32 func_00193630(void) {
    s64 temp_17;
    s64 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_00243ec0(func_00105510((s16)temp_17), (s16)temp_16);
    return 1;
}



// FUN_001936A0
s32 func_001936a0(void) {
    func_0029cf50((s16)func_00243e90(func_00105510((s16)func_0029cc00(0))));
    return 1;
}



// FUN_00193700
s32 func_00193700(void) {
    s32 result;

    if (iGpffffb3ac != NULL) {
        result = *(s32 *)(iGpffffb3ac + 0xDC8);
        goto done_00193700;
    }
    result = 0;
done_00193700:
    return result;
}
// FUN_00193730
void func_00193730(void) {
    *(s32 *)(D_0076449C + 0xC) |= 0x4000;
}



// FUN_00193840
s32 func_00193840(u8 *arg0, s32 arg1)
{
    u8 *var_18;
    s32 var_17;
    u32 temp_16;
    u32 temp_4;
    u8 **temp_2;

    if (iGpffffb434 == 0) {
        func_00440b68(&iGpffffa0a0, D_005F6BE0, 0x4B1);
        iGpffffb434 = func_00454a60(*(s32 *)arg0, 0);
    }
    if (arg1 != 0) {
        H_Cdvd_ReadSync(iGpffffb434);
        goto block_6;
    }
    if (H_Cdvd_IsFileLoaded(iGpffffb434) == 0) {
        return 0;
    }
block_6:
    var_18 = *(u8 **)((u8 *)iGpffffb434 + 0x110);
    var_17 = 0;
    goto loop_8_check;
loop_8_body:
    temp_16 = *(u32 *)var_18;
    temp_4 = iGpffffb430;
    *temp_2 = (u8 *)((s32)D_007F17B0 + temp_4);
    iGpffffb430 +=
        (((temp_16 >> 4) + ((temp_16 & 0xF) != 0)) * 0x10);
    memcpy(*temp_2, var_18 + 4, temp_16);
    temp_4 = temp_16 + 4;
    var_18 +=
        (((temp_4 >> 4) + ((temp_4 & 0xF) != 0)) * 0x10);
    var_17 += 1;
loop_8_check:
    temp_2 = *(u8 ***)((u8 *)arg0 + (var_17 * 8) + 4);
    if (temp_2 != NULL) {
        goto loop_8_body;
    }
    H_Cdvd_Destroy(iGpffffb434);
    iGpffffb434 = 0;
    return 1;
}
// FUN_001939A0
void func_001939a0(void) {
    func_001d78d0();
    func_00200cb0();
    func_001f8480();
    func_00202be0();
}
// FUN_001939E0
s32 func_001939e0(u8 *unusedTask)
{
    s32 result;

    result = func_00193840((u8 *)D_005F66C0 + iGpffffb438 * 0xA4, 0);
    if (result == 0) {
        goto clear;
    }
    iGpffffb438 = iGpffffb438 + 1;
    if (iGpffffb438 != 8) {
        goto clear;
    }
    result = 1;
    goto check;
clear:
    result = 0;
check:
    if (result == 0) {
        goto done;
    }
    func_0010d480();
    result = -1;
    goto end;
done:
    result = 0;
end:
    return result;
}
/* 80/80 bytes; eight resolved relocations. Retail forwards the incoming
 * a0 to the task constructor as the parent; it is not an uninitialized
 * local left in an incidental register. */
// FUN_00193A80
void func_00193a80(u8 *ctx) {
    iGpffffb430 = 0;
    iGpffffb434 = 0;
    iGpffffb438 = 0;
    (s32)func_00451fc0((void *)(ctx), (const void *)(D_005F6BF0), 0x10, 0, 0, func_001939e0, 0, (u8 *)(NULL));
}

// FUN_00193AD0
void func_00193ad0(u8 *arg0)
{
    s16 i;
    s64 index;
    s32 offset;
    u8 *entry;

    i = 0;
    while ((u32)i < 10U) {
        index = i;
        offset = (s32)index * 0x14;
        entry = arg0 + offset;
        memset(entry, 0, 0x14);
        *(u16 *)(entry + 0x0) = 0;
        *(u16 *)(entry + 0x2) = 3;
        i++;
    }
}
// FUN_00193B70
u8 *func_00193b70(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (uid == (*(u64 *)(packet + 0x58) & mask) &&
                (*(u8 *)(packet + 0x47) & 0x20) != 0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
        i++;
    }
    return NULL;
}

// FUN_00193BF0
/* Same packet-list walk as func_00193b70; this P4 packet stores the UID at
   offset 0x60 instead of 0x58. */
u8 *func_00193bf0(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (uid == (*(u64 *)(packet + 0x60) & mask) &&
                (*(u8 *)(packet + 0x47) & 0x20) != 0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
        i++;
    }
    return NULL;
}

// FUN_00193C70
u32 func_00193c70(void)
{
    u32 total;
    u32 i;
    u8 *btl;
    u8 *packet;

    total = 0;
    i = 0;
    btl = iGpffffb3ac;
    for (; i < 4; i++) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            total++;
            packet = *(u8 **)(packet + 0x7C);
        }
    }
    return total;
}
// FUN_00193CD0
u32 func_00193cd0(u32 id)
{
    u8 *packet;
    u8 *btl;
    u32 total;
    u32 i;

    total = 0;
    i = 0;
    btl = iGpffffb3ac;
    id = (u16)id;
    for (; i < 4; i++) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (*(u32 *)(packet + 0x40) == id) {
                total++;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
    }
    return total;
}
// FUN_00193D30
void func_00193d30(void)
{
    u8 *packet;
    u32 i;
    u32 flags;

    i = 0;
    for (; i < 4; i++) {
        packet = *(u8 **)(iGpffffb3ac + i * 8 + 0x19C);
        while (packet != NULL) {
            flags = *(u8 *)(packet + 0x47);
            if ((flags & 1) != 0) {
                *(u8 *)(packet + 0x47) = flags | 4;
            }
            packet = *(u8 **)(packet + 0x80);
        }
    }
}

#pragma opt_loop_invariants on
static inline u8 *search_58_10(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (uid == (*(u64 *)(node + 0x58) & mask) && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
static inline u8 *search_60_10(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (uid == (*(u64 *)(node + 0x60) & mask) && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
static inline u8 *search_40_10(u16 key)
{
    u8 *node;
    u8 *btl;
    u32 i;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (*(u16 *)(node + 0x40) == key && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
// FUN_00193D90
s32 func_00193d90(u8 *arg0, s32 arg1)
{
    s32 result;
    u64 uid;
    u16 key;
    u8 *node;
    s32 (*cb)(u8 *);
    result = 0;
    switch (*(u8 *)arg0) {
    case 1:
        result = 1;
        break;
    case 2:
        if (*(s32 *)(arg0 + 8) <= arg1) {
            result = 1;
        }
        break;
    case 3:
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 4:
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 5:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node != NULL && *(u8 *)(node + 0x45) != 2) {
            result = 0;
        }
        break;
    case 6:
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 7:
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 8:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node != NULL && *(u8 *)(node + 0x45) != 2) {
            result = 0;
        }
        break;
    case 9:
        key = *(u16 *)(arg0 + 8);
        node = search_40_10(key);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 10:
        key = *(u16 *)(arg0 + 8);
        node = search_40_10(key);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 11:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node != NULL) {
            cb = *(s32 (**)(u8 *))(node + 0x74);
            if (cb != NULL) {
                result = cb(*(u8 **)(node + 0x78));
            } else {
                result = 0;
            }
        }
        break;
    case 12:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node != NULL) {
            cb = *(s32 (**)(u8 *))(node + 0x74);
            if (cb != NULL) {
                result = cb(*(u8 **)(node + 0x78));
            } else {
                result = 0;
            }
        }
        break;
    }
    return result;
}
#pragma opt_loop_invariants off

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
#pragma optimization_level 1
// FUN_00194470
u8 *func_00194470(s32 arg0, s32 arg1)
{
    s32 temp_18;
    s32 var_4;
    s32 var_4_2;
    s32 value;
    u8 *temp_2;

    temp_18 = arg1 + 0x90;
    func_0044ea90(D_005F6C00, 0x51);
    temp_2 = D_008873E8[0](temp_18, 0x40000);
    memset(temp_2, 0, temp_18);
    *(s32 *)(temp_2 + 0x40) = arg0;
    var_4 = 0;
    value = 1;
    goto loop1_check;
loop1_body:
    *(u8 *)(temp_2 + ((var_4 & 0xFFFF) << 4)) = value;
    var_4 = (var_4 + 1) & 0xFFFF;
loop1_check:
    if ((var_4 & 0xFFFF) < 2) {
        goto loop1_body;
    }
    var_4_2 = 0;
    value = 1;
    goto loop2_check;
loop2_body:
    *(u8 *)(temp_2 + ((var_4_2 & 0xFFFF) << 4) + 0x20) = value;
    var_4_2 = (var_4_2 + 1) & 0xFFFF;
loop2_check:
    if ((var_4_2 & 0xFFFF) < 2) {
        goto loop2_body;
    }
    if (arg1 > 0) {
        *(u8 **)(temp_2 + 0x78) = temp_2 + 0x90;
    }
    *(u8 *)(temp_2 + 0x47) =
        (u8)(*(u8 *)(temp_2 + 0x47) | 0x31);
    return temp_2;
}
#pragma optimization_level 2
// FUN_00194590
/* measured: opt_propagation off is scoped to func_00194590. */
#pragma opt_propagation off
s64 func_00194590(u8 *arg0, u32 arg1)
{
    u32 index;
    u8 *next;
    void (*callback)(u8 *);

    *(s64 *)(arg0 + 0x58) = btlGetUID();
    *(s32 *)(arg0 + 0x4C) = 0;
    *(s32 *)(arg0 + 0x50) = 0;
    *(u8 *)(arg0 + 0x45) = 0;
    *(u8 *)(arg0 + 0x44) = arg1;
    *(u8 *)(arg0 + 0x47) |= 8;
    callback = *(void (**)(u8 *))(arg0 + 0x68);
    if (callback != NULL) {
        callback(*(u8 **)(arg0 + 0x78));
    }
    *(s32 *)(arg0 + 0x7C) = 0;
    index = ((u8)arg1) * 8;
    next = *(u8 **)((u8 *)p4_entries_001900a0(0x198, (s32 *)iGpffffb3ac) + index);
    if (next != NULL) {
        *(u8 **)(next + 0x7C) = arg0;
        *(u8 **)(arg0 + 0x80) =
            *(u8 **)((u8 *)p4_base_add_00194590(index,
                                                 (s32)iGpffffb3ac) + 0x198);
    } else {
        *(u8 **)((u8 *)p4_base_add_00194590(index,
                                             (s32)iGpffffb3ac) + 0x19C) = arg0;
        *(u8 **)(arg0 + 0x80) = NULL;
    }
    *(u8 **)((u8 *)p4_base_add_00194590(index,
                                         (s32)iGpffffb3ac) + 0x198) = arg0;
    return *(s64 *)(arg0 + 0x58);
}
/* measured: closes opt_propagation around func_00194590. */
#pragma opt_propagation on
// FUN_00194660
void func_00194660(void)
{
}

static inline u32 packetListOffset(u32 offset, u32 base)
{
    return offset + base;
}


typedef struct {
    u8 *head;
    u8 *tail;
} PacketList;
extern s32 func_00193d90(u8 *arg0, s32 arg1);

/* 852/864 bytes; ten resolved relocations; twelve zero alignment bytes.
 * States fall through only after their conditions complete. Destruction
 * reloads the list flag and links after the callback; counters wrap as u32. */
// FUN_00194670
void func_00194670(u8 *arg0)
{
    u8 flags;
    u8 index;
    u8 *next;
    u8 *prev;
    void (*callback)(u8 *);
    s32 count;
    s32 ok;
    s32 i;

    if (*(u8 *)(arg0 + 0x46) != 0) {
        return;
    }
    flags = *(u8 *)(arg0 + 0x47);
    if ((flags & 8) == 0) {
        return;
    }
    if ((flags & 4) != 0) {
        callback = *(void (**)(u8 *))(arg0 + 0x70);
        if (callback != NULL) {
            callback(*(u8 **)(arg0 + 0x78));
        }
        if ((*(u8 *)(arg0 + 0x47) & 8) != 0) {
            index = *(u8 *)(arg0 + 0x44);
            next = *(u8 **)(arg0 + 0x80);
            if (next != NULL) {
                *(u8 **)(next + 0x7C) = *(u8 **)(arg0 + 0x7C);
            } else {
                ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].tail = *(u8 **)(arg0 + 0x7C);
            }
            prev = *(u8 **)(arg0 + 0x7C);
            if (prev != NULL) {
                *(u8 **)(prev + 0x80) = *(u8 **)(arg0 + 0x80);
            } else {
                ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].head = *(u8 **)(arg0 + 0x80);
            }
        }
        jtbl_008873EC[0](arg0);
    } else {
        count = *(s32 *)(arg0 + 0x4C);
        *(s32 *)(arg0 + 0x4C) = (s32)((u32)count + 1U);
        switch (*(u8 *)(arg0 + 0x45)) {
        case 0:
            for (i = 0; (i & 0xFFFF) < 2; i = (i + 1) & 0xFFFF) {
                if (func_00193d90(arg0 + (((u16)i) << 4), count) == 0) {
                    ok = 0;
                    goto state0_done;
                }
            }
            ok = 1;
        state0_done:
            if (ok == 0) {
                return;
            }
            *(u8 *)(arg0 + 0x45) = 1;
        case 1:
            if (*(s16 *)(arg0 + 0x48) <= 0) {
                *(u8 *)(arg0 + 0x45) = 2;
            } else {
                *(s16 *)(arg0 + 0x48) = (s16)(*(s16 *)(arg0 + 0x48) - 1);
                return;
            }
        case 2:
            if ((*(u32 (**)(void *))(arg0 + 0x6C))(*(void **)(arg0 + 0x78)) != 0) {
                *(u8 *)(arg0 + 0x45) = 3;
            } else {
                *(u32 *)(arg0 + 0x50) += 1U;
                return;
            }
        case 3:
            for (i = 0; (i & 0xFFFF) < 2; i = (i + 1) & 0xFFFF) {
                if (func_00193d90((u8 *)((((u16)i) << 4) + (u32)arg0) + 0x20, count) == 0) {
                    ok = 0;
                    goto state3_done;
                }
            }
            ok = 1;
        state3_done:
            if (ok == 0) {
                return;
            }
            *(u8 *)(arg0 + 0x45) = 4;
        case 4:
            if (*(s16 *)(arg0 + 0x4A) <= 0) {
                callback = *(void (**)(u8 *))(arg0 + 0x70);
                if (callback != NULL) {
                    callback(*(u8 **)(arg0 + 0x78));
                }
                if ((*(u8 *)(arg0 + 0x47) & 8) != 0) {
                    index = *(u8 *)(arg0 + 0x44);
                    next = *(u8 **)(arg0 + 0x80);
                    if (next != NULL) {
                        *(u8 **)(next + 0x7C) = *(u8 **)(arg0 + 0x7C);
                    } else {
                        ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].tail = *(u8 **)(arg0 + 0x7C);
                    }
                    prev = *(u8 **)(arg0 + 0x7C);
                    if (prev != NULL) {
                        *(u8 **)(prev + 0x80) = *(u8 **)(arg0 + 0x80);
                    } else {
                        ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].head = *(u8 **)(arg0 + 0x80);
                    }
                }
                jtbl_008873EC[0](arg0);
            } else {
                *(s16 *)(arg0 + 0x4A) = (s16)(*(s16 *)(arg0 + 0x4A) - 1);
            }
            break;
        }
    }
}

/* measured: opt_propagation off is scoped to func_001949d0. */
#pragma opt_propagation off

// FUN_001949D0
void func_001949d0(s32 arg0)
{
    u8 *btl;
    u8 *temp_16;
    u8 *var_4;

    btl = iGpffffb3ac;
    var_4 = *(u8 **)((u8 *)packetListOffset((arg0 & 0xFF) * 8, (u32)btl) + 0x19C);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x7C);
        func_00194670(var_4);
        var_4 = temp_16;
    }
}
/* measured: closes opt_propagation for func_001949d0. */
#pragma opt_propagation on

// FUN_00194A30
void func_00194a30(void)
{
    u8 *entry;
    u8 *next;
    u8 *link;
    void (*callback)(u8 *);
    u8 index;
    u32 i;

    i = 0;
    goto outer_check;
outer:
    entry = *(u8 **)(iGpffffb3ac + i * 8 + 0x19C);
    goto inner_check;
inner:
    next = *(u8 **)(entry + 0x80);
    callback = *(void (**)(u8 *))(entry + 0x70);
    if (callback != NULL) {
        callback(*(u8 **)(entry + 0x78));
    }
    if ((*(u8 *)(entry + 0x47) & 8) != 0) {
        index = *(u8 *)(entry + 0x44);
        link = *(u8 **)(entry + 0x80);
        if (link != NULL) {
            *(u8 **)(link + 0x7C) = *(u8 **)(entry + 0x7C);
        } else {
            *(u8 **)(iGpffffb3ac + ((index & 0xFF) * 8) + 0x19C) =
                *(u8 **)(entry + 0x7C);
        }
        link = *(u8 **)(entry + 0x7C);
        if (link != NULL) {
            *(u8 **)(link + 0x80) = *(u8 **)(entry + 0x80);
        } else {
            *(u8 **)(iGpffffb3ac + ((index & 0xFF) * 8) + 0x198) =
                *(u8 **)(entry + 0x80);
        }
    }
    jtbl_008873EC[0](entry);
    entry = next;
inner_check:
    if (entry != NULL) {
        goto inner;
    }
    i++;
outer_check:
    if (i < 4) {
        goto outer;
    }
}
// FUN_00194B50
s32 func_00194b50(void)
{
    return 1;
}

/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
#pragma optimization_level 1
// FUN_00194B60
u8 *func_00194b60(void)
{
    u8 *temp_16;
    s32 j;
    s32 i;
    u8 *base;
    s32 value;

    func_0044ea90(D_005F6C00, 0x51);
    temp_16 = (u8 *)D_008873E8[0](0x90, 0x40000);
    memset(temp_16, 0, 0x90);
    *(s32 *)(temp_16 + 0x40) = 0xFF00;
    i = 0;
    value = 1;
    goto first_check;
first_body:
    *(u8 *)(temp_16 + ((i & 0xFFFF) << 4)) = (u8)value;
    i = (i + 1) & 0xFFFF;
first_check:
    if ((i & 0xFFFF) < 2) {
        goto first_body;
    }
    base = temp_16 + 0x20;
    j = 0;
    value = 1;
    goto second_check;
second_body:
    *(u8 *)(base + ((j & 0xFFFF) << 4)) = (u8)value;
    j = (j + 1) & 0xFFFF;
second_check:
    if ((j & 0xFFFF) < 2) {
        goto second_body;
    }
    *(u8 *)(temp_16 + 0x47) =
        (u8)(*(u8 *)(temp_16 + 0x47) | 0x31);
    *(s32 *)(temp_16 + 0x6C) = (s32)func_00194b50;
    return temp_16;
}
#pragma optimization_level 2
/* measured: aggregate Vec3 copies and float frame fields reproduce the 500-byte body. */
// FUN_00194FF0
void func_00194ff0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3)
{
    struct Work {
        f32 vec[3];
        u8 gap[4];
        f32 x;
        f32 y;
        f32 z;
    } frame;
    s16 temp_6;
    s32 temp_6_2;
    u8 temp_5;
    u8 *temp_2;
    u8 *temp_4;

    frame.x = (f32)(s32)((*(s16 *)(arg0 + 0x94) * 0x19) - 0x6D6);
    frame.y = 0;
    temp_6 = *(s16 *)(arg0 + 0x96);
    temp_6_2 = temp_6 * 5;
    frame.z = (f32)((temp_6 * 0x19) - 0x6D6);
    if (arg1 != NULL) {
        *(P4_95730_Vec3 *)arg1 = *(P4_95730_Vec3 *)&frame.x;
    }
    if ((arg3 != NULL) || (arg2 != NULL)) {
        temp_5 = *(u8 *)(arg0 + 0xA2);
        switch (temp_5) {
        case 0:
            if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100) == 0) {
                func_00196040(2, 1, (RwV3d *)frame.vec, NULL, NULL, 1);
            } else {
                func_001958f0(
                    *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                    frame.vec);
            }
            break;
        case 1:
            if (func_0022f7d0(arg0, frame.vec, temp_6_2) != 1) {
                temp_2 = func_001b1510();
                if ((temp_2 != NULL) &&
                    ((temp_4 = *(u8 **)(temp_2 + 0x30)),
                     (*(u8 *)(temp_4 + 0xA2) == 0)) &&
                    ((*(u16 *)(temp_2 + 0x18) & 4) == 0 ||
                     *(u16 *)(temp_2 + 0x16) != 0x1E)) {
                    func_001958f0(temp_4, frame.vec);
                } else {
                    func_001958f0(
                        *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                        frame.vec);
                }
            }
            break;
        }
        if (arg3 != NULL) {
            *(P4_95730_Vec3 *)arg3 = *(P4_95730_Vec3 *)frame.vec;
        }
        if (arg2 != NULL) {
            func_001ec1c0(arg2, &frame.x, frame.vec);
        }
    }
}
/* measured: object 832B/window 832B, nd 0. arg6 is an s32 param copied to a u8
   temporary before each use (retail keeps the raw value in $s0 and re-masks);
   `kind` is a plain u16 local (a redundant & 0xFFFF becomes a hoisted $s
   constant under propagation off) and arg3 goes through a u16 temporary. The
   table addresses: `(u8 *)off + (s32)((u8 *)(kind * 0x58) + (s32)iGpffffb3e0)`
   for the deferred GP load with addu kind,base / off,sum; and a `tbl = gp`
   local plus `(u8 *)(kind * 0x58) + (s32)tbl` where retail loads the base first.
   `dist = call; dist += 50.0f` gives the result-first add.s; stack arrays in
   declaration order tmp, pos, scaled, origin, rot. */
// FUN_001951F0
/* measured: opt_propagation off keeps the per-use u8/u16 conversions and the
   named scaled index (`off = k * 6`) from being folded into one address. */
#pragma opt_propagation off
void func_001951f0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 *arg4, f32 *arg5, s32 arg6)
{
    f32 tmp[3];
    f32 pos[3];
    f32 scaled[3];
    f32 origin[3];
    f32 rot[4];
    u16 kind;
    u8 *entry;
    f32 dist;
    f32 fx;
    f32 fz;
    f32 side;
    u8 k;
    f32 sx;
    f32 sz;
    f32 t;
    u8 *tbl;
    s32 off;
    u16 a3;

    kind = *(u16 *)(arg0 + 0xA4);
    k = arg6;
    if (k == 2) {
        if (*(s32 *)(iGpffffb3ac + 0x10) & 0x01000000) {
            arg6 = 0;
        }
    }
    k = arg6;
    if (k != 2) {
        if (arg5 != NULL) {
            *(P4_95730_Vec4 *)arg5 = *(P4_95730_Vec4 *)(arg1 + 0x1C);
        }
        if (arg4 != NULL) {
            btlUnitGetSphereWorldCenter(arg1, origin);
            origin[1] = 0.0f;
            k = arg6;
            off = k * 6;
            entry = (u8 *)off + (s32)((u8 *)(kind * 0x58) + (s32)iGpffffb3e0);
            pos[0] = *(s16 *)(entry + 0xC);
            pos[1] = *(s16 *)(entry + 0xE);
            pos[2] = *(s16 *)(entry + 0x10);
            scaled[0] = pos[0] * *(f32 *)(arg0 + 0x2C);
            scaled[1] = pos[1] * *(f32 *)(arg0 + 0x2C);
            scaled[2] = pos[2] * *(f32 *)(arg0 + 0x2C);
            RtQuatTransformVectors(pos, scaled, 1, arg1 + 0x1C);
            arg4[0] = pos[0] + origin[0];
            arg4[1] = pos[1] + origin[1];
            arg4[2] = pos[2] + origin[2];
        }
    } else {
        func_00195aa0(arg2, arg1, origin);
        a3 = arg3;
        dist = func_00196bd0(arg0, arg2, (u8 *)a3);
        dist = dist + 50.0f;
        func_001ec1c0(rot, arg1 + 4, origin);
        RtQuatTransformVectors(tmp, &D_0060A100, 1, rot);
        fx = tmp[0] * dist;
        fz = tmp[2] * dist;
        tbl = iGpffffb3e0;
        t = *(s16 *)((u8 *)(kind * 0x58) + (s32)tbl + 0xC);
        side = t * *(f32 *)(arg0 + 0x2C);
        RtQuatTransformVectors(tmp, &D_0060A0D0, 1, rot);
        tmp[0] *= side;
        tmp[1] *= side;
        tmp[2] *= side;
        sx = fx + tmp[0];
        sz = fz + tmp[2];
        pos[0] = origin[0] + sx;
        pos[2] = origin[2] + sz;
        pos[1] = 0.0f;
        if (arg4 != NULL) {
            *(P4_95730_Vec3 *)arg4 = *(P4_95730_Vec3 *)pos;
        }
        if (arg5 != NULL) {
            func_001ec1c0(arg5, pos, origin);
        }
    }
}
/* measured: closes the propagation bracket; the file default is on. */
#pragma opt_propagation on
// FUN_00195530
s32 func_00195530(u8 *arg0) {
    u8 *e;

    if (arg0[0xA2] != 2) {
        return -1;
    }
    e = p4_unit_00195530(*(u16 *)(arg0 + 0xA4) * 0x58, iGpffffb3e0);
    return (e[0x56] << 24) | 0xFFFFFF;
}

// FUN_00195610
void func_00195610(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}


// FUN_00195710
void func_00195710(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00195730
void func_00195730(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)func_00194470(0x11C, 0x28);
    *(void (**)(u8 *))(packet + 0x68) = func_00195610;
    *(void (**)(u8 *))(packet + 0x6C) = func_00195630;
    *(void (**)(u8 *))(packet + 0x70) = func_00195710;
    work = *(u8 **)(packet + 0x78);
    *(s32 *)work = arg0;
    *(u16 *)(work + 0x24) = 0;
    if (arg1 != NULL) {
        *(P4_95730_Vec3 *)(work + 4) = *(P4_95730_Vec3 *)arg1;
        *(u16 *)(work + 0x24) |= 1;
    }
    if (arg2 != NULL) {
        *(P4_95730_Vec4 *)(work + 0x10) = *(P4_95730_Vec4 *)arg2;
        *(u16 *)(work + 0x24) |= 2;
    }
    if (arg3 != NULL) {
        *(P4_95730_Bytes4 *)(work + 0x20) = *(P4_95730_Bytes4 *)arg3;
        *(u16 *)(work + 0x24) |= 4;
    }
}
// FUN_00196B70
void func_00196b70(u8 *arg0) {
    *(s32 *)(arg0 + 0xC4) &= ~1;
    *(u16 *)(arg0 + 0xC8) &= ~1;
}
// FUN_00196BA0
void func_00196ba0(u8 *arg0) {
    *(s32 *)(arg0 + 0xC4) &= ~2;
    *(u16 *)(arg0 + 0xC8) &= ~2;
}
// FUN_00196BD0
f32 func_00196bd0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    f32 temp_f20;
    f32 temp_f0;
    u8 *table;
    s32 temp_4;

    temp_4 = (s16)func_001990d0(arg0, (s32)arg2);
    if (temp_4 < (s32)*(u16 *)(arg0 + 0x9E4)) {
        table = *(u8 **)(arg0 + 0x9F8);
        temp_f20 = *(f32 *)(arg0 + 0x2C) *
                   (f32)*(s16 *)((u8 *)p4_base_add_00194590(
                       temp_4 * 0xA, (s32)(table, table)) + 6);
        temp_f0 = func_0022cf00(arg0, arg1, (s32)arg2);
        if (!(temp_f0 < 0.0f)) {
            temp_f20 += temp_f0;
            goto add_base_00196bd0;
        }
        temp_f20 += *(f32 *)(arg1 + 0x90) * *(f32 *)(arg1 + 0x2C);
        temp_f20 += *(f32 *)(arg1 + 0x88) * *(f32 *)(arg1 + 0x2C);
add_base_00196bd0:
        temp_f20 += *(f32 *)(arg0 + 0x88) *
                    *(f32 *)(arg0 + 0x2C);
    } else {
        temp_f20 = 0.0f;
    }
    return temp_f20;
}
// FUN_00196CE0
void func_00196ce0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

extern void func_001eec50(void *work);
extern s32 func_001eed10(u8 *route, f32 *start, f32 *end, f32 radius);
extern s32 func_001ef110(u8 *route, const f32 *startXZ, const f32 *endXZ, const f32 *centerXZ);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
/* The vector snapshot preserves all three coordinates before flattening Y.
   Separate vector/pair objects retain their natural stack lifetimes. Native
   proof: 1736 executable bytes, ten resolved calls, 150 unchanged siblings. */
// FUN_00196D00
u32 func_00196d00(void *workData)
{
    union MovementVector {
        P4_95730_Vec3 vector;
        f32 values[3];
    } direction;
    union MovementVector flatTarget;
    union MovementVector position;
    f32 routeStart[2];
    f32 routeEnd[2];
    f32 routeCenter[2];
    u8 *arg0;
    u8 *unit;
    u16 state;
    s32 flags;
    u16 work_state;
    s32 mask;
    u8 active;
    u8 *work;
    u16 index;

    arg0 = (u8 *)workData;
    unit = *(u8 **)arg0;
    flags = *(s32 *)(arg0 + 0x10);
    if ((flags & 8) != 0) {
        state = *(u16 *)(arg0 + 0x14);
        switch (state) {
        case 0:
            if ((flags & 0x10) != 0) {
                func_00194ff0(unit, (u8 *)position.values, NULL, NULL);
                *(P4_95730_Vec3 *)(arg0 + 4) = position.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            /* fallthrough */
        case 1:
            func_001eec50(unit + 0xEC);
            *(f32 *)(unit + 0xE8) = *(f32 *)(arg0 + 0x1C);
            *(s32 *)(unit + 0xC4) = *(s32 *)(arg0 + 0x10);
            *(f32 *)(unit + 0xCC) = 2.0f * (13.5f * *(f32 *)(arg0 + 0x20));
            if ((*(s32 *)(unit + 0xC4) & 1) == 0) {
                *(f32 *)(unit + 0xEC) = *(f32 *)(unit + 4);
                *(f32 *)(unit + 0xF0) = *(f32 *)(unit + 0xC);
                *(f32 *)(unit + 0xF4) = *(f32 *)(arg0 + 4);
                *(f32 *)(unit + 0xF8) = *(f32 *)(arg0 + 0xC);
                *(u16 *)(unit + 0x4EC) = 2;
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) |= 1;
                *(u16 *)(unit + 0xC8) |= 0x10;
                direction.values[0] = *(f32 *)(unit + 4) - *(f32 *)(arg0 + 4);
                direction.values[1] = *(f32 *)(unit + 8) - *(f32 *)(arg0 + 8);
                direction.values[2] = *(f32 *)(unit + 0xC) - *(f32 *)(arg0 + 0xC);
                direction.values[1] = 0.0f;
                RwV3dNormalize(direction.values, direction.values);
                direction.values[0] *= *(f32 *)(arg0 + 0x1C);
                direction.values[1] *= *(f32 *)(arg0 + 0x1C);
                direction.values[2] *= *(f32 *)(arg0 + 0x1C);
                *(f32 *)(unit + 0xDC) = *(f32 *)(arg0 + 4) + direction.values[0];
                *(f32 *)(unit + 0xE0) = *(f32 *)(arg0 + 8) + direction.values[1];
                *(f32 *)(unit + 0xE4) = *(f32 *)(arg0 + 0xC) + direction.values[2];
            } else {
                if (*(f32 *)(arg0 + 0x1C) != 0.0f) {
                    direction.values[0] = *(f32 *)(unit + 4) - *(f32 *)(arg0 + 4);
                    direction.values[1] = *(f32 *)(unit + 8) - *(f32 *)(arg0 + 8);
                    direction.values[2] = *(f32 *)(unit + 0xC) - *(f32 *)(arg0 + 0xC);
                    direction.values[1] = 0.0f;
                    RwV3dNormalize(direction.values, direction.values);
                    direction.values[0] *= *(f32 *)(arg0 + 0x1C);
                    direction.values[1] *= *(f32 *)(arg0 + 0x1C);
                    direction.values[2] *= *(f32 *)(arg0 + 0x1C);
                    position.values[0] = *(f32 *)(arg0 + 4) + direction.values[0];
                    position.values[1] = *(f32 *)(arg0 + 8) + direction.values[1];
                    position.values[2] = *(f32 *)(arg0 + 0xC) + direction.values[2];
                } else {
                    position.vector = *(P4_95730_Vec3 *)(arg0 + 4);
                }
                position.values[1] = *(f32 *)(unit + 8);
                *(P4_95730_Vec3 *)(unit + 4) = position.vector;
                *(s32 *)(unit + 0x98) |= 4;
                *(s32 *)(unit + 0xC4) &= ~1;
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) &= 0xFFFE;
                *(u16 *)(unit + 0xC8) &= 0xFFEF;
                *(P4_95730_Vec3 *)(unit + 0xDC) = position.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            goto done;
        case 2:
            work_state = *(u16 *)(unit + 0xC8);
            mask = work_state & 1;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            mask = work_state & 2;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            return 1;
        default:
            goto done;
        }
    } else {
        state = *(u16 *)(arg0 + 0x14);
        switch (state) {
        case 0:
            if ((flags & 0x10) != 0) {
                func_00194ff0(unit, (u8 *)position.values, NULL, NULL);
                *(P4_95730_Vec3 *)(arg0 + 4) = position.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            /* fallthrough */
        case 1:
            func_001eec50(unit + 0xEC);
            *(f32 *)(unit + 0xE8) = *(f32 *)(arg0 + 0x1C);
            *(s32 *)(unit + 0xC4) = *(s32 *)(arg0 + 0x10);
            *(f32 *)(unit + 0xCC) = 2.0f * (13.5f * *(f32 *)(arg0 + 0x20));
            routeStart[0] = *(f32 *)(unit + 4);
            routeStart[1] = *(f32 *)(unit + 0xC);
            routeEnd[0] = *(f32 *)(arg0 + 4);
            routeEnd[1] = *(f32 *)(arg0 + 0xC);
            if ((*(s32 *)(arg0 + 0x10) & 0x80) == 0) {
                func_001eed10(unit + 0xEC, routeStart, routeEnd, 50.0f);
            } else {
                func_00196040(3, 1, &position.vector, NULL, NULL, 1);
                routeCenter[0] = position.values[0];
                routeCenter[1] = position.values[2];
                func_001ef110(unit + 0xEC, routeStart, routeEnd, routeCenter);
            }
            index = *(u16 *)(unit + 0x4EC);
            if (index == 0) {
                *(P4_95730_Vec3 *)(unit + 0xDC) = *(P4_95730_Vec3 *)(arg0 + 4);
            } else {
                work = (u8 *)p4_base_add_00194590(index * 8, (s32)unit);
                direction.values[0] = *(f32 *)(work + 0xDC);
                direction.values[1] = 0.0f;
                direction.values[2] = *(f32 *)(work + 0xE0);
                flatTarget.vector = *(P4_95730_Vec3 *)(arg0 + 4);
                flatTarget.values[1] = 0.0f;
                direction.values[0] = direction.values[0] - flatTarget.values[0];
                direction.values[1] = direction.values[1] - flatTarget.values[1];
                direction.values[2] = direction.values[2] - flatTarget.values[2];
                RwV3dNormalize(direction.values, direction.values);
                direction.values[0] *= *(f32 *)(arg0 + 0x1C);
                direction.values[1] *= *(f32 *)(arg0 + 0x1C);
                direction.values[2] *= *(f32 *)(arg0 + 0x1C);
                flatTarget.values[0] += direction.values[0];
                flatTarget.values[1] += direction.values[1];
                flatTarget.values[2] += direction.values[2];
                *(P4_95730_Vec3 *)(unit + 0xDC) = flatTarget.vector;
            }
            *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
            /* fallthrough */
        case 2:
            work_state = *(u8 *)(unit + 0x4F0);
            if (work_state == 2) {
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) |= 1;
                *(u16 *)(unit + 0xC8) |= 0x10;
                *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
                goto done;
            } else if (work_state == 3) {
                *(f32 *)(unit + 0xEC) = *(f32 *)(unit + 4);
                *(f32 *)(unit + 0xF0) = *(f32 *)(unit + 0xC);
                *(f32 *)(unit + 0xF4) = *(f32 *)(arg0 + 4);
                *(f32 *)(unit + 0xF8) = *(f32 *)(arg0 + 0xC);
                *(u16 *)(unit + 0x4EC) = 2;
                *(u16 *)(unit + 0xC8) &= 0xFFDF;
                *(u16 *)(unit + 0xC8) |= 1;
                *(u16 *)(unit + 0xC8) |= 0x10;
                *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0x14) + 1;
                goto done;
            }
            goto done;
        case 3:
            work_state = *(u16 *)(unit + 0xC8);
            mask = work_state & 1;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            mask = work_state & 2;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            return 1;
        default:
            goto done;
        }
    }
done:
    *(s32 *)(arg0 + 0x18) += 1;
    return 0;
}
// FUN_001973D0
void func_001973d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

/* measured: opt_propagation off preserves the COP1 chain's intermediate colouring. */
#pragma opt_propagation off
// FUN_00197A80
s32 func_00197a80(u8 *arg0)
{
    u8 *unit;
    P4_95730_Vec3 transformed;
    P4_95730_Vec3 delta;
    P4_95730_Vec3 position;
    f32 temp_f2;
    f32 progress;
    s32 use_scaled;
    unit = *(u8 **)arg0;
    if (func_0023df70(*(u16 *)(arg0 + 4)) != 0) {
        if (*(u16 *)(arg0 + 6) == 0) {
            *(f32 *)(arg0 + 0x24) = 0.5f;
            *(P4_95730_Vec3 *)(arg0 + 0xC) =
                *(P4_95730_Vec3 *)(unit + 4);
            RtQuatTransformVectors(&transformed, &D_0060A100, 1, unit + 0x1C);
            *(f32 *)(arg0 + 0x18) = 400.0f * transformed.x;
            *(f32 *)(arg0 + 0x1C) = 400.0f * transformed.y;
            *(f32 *)(arg0 + 0x20) = 400.0f * transformed.z;
        }
        progress = *(f32 *)(arg0 + 0x24);
        progress += 0.03125f;
        *(f32 *)(arg0 + 0x24) = progress;
        temp_f2 = 0.0f + (-1.0f) +
                  ((-2.0f * progress) * progress) +
                  (4.0f * progress);
        progress = 2.0f * (temp_f2 - 0.5f);
        if (progress < fGpffff82d4) {
            delta.x = *(f32 *)(arg0 + 0x18) * progress;
            delta.y = *(f32 *)(arg0 + 0x1C) * progress;
            delta.z = *(f32 *)(arg0 + 0x20) * progress;
            use_scaled = 0;
        } else {
            delta = *(P4_95730_Vec3 *)(arg0 + 0x18);
            use_scaled = 1;
        }
        position.x = *(f32 *)(arg0 + 0xC) + delta.x;
        position.y = *(f32 *)(arg0 + 0x10) + delta.y;
        position.z = *(f32 *)(arg0 + 0x14) + delta.z;
        *(P4_95730_Vec3 *)(unit + 4) = position;
        *(s32 *)(unit + 0x98) |= 4;
        *(u16 *)(arg0 + 6) = *(u16 *)(arg0 + 6) + 1;
        return use_scaled;
    }
    *(s32 *)(unit + 0x10) = 0;
    *(f32 *)(unit + 0x14) =
        *(f32 *)(arg0 + 8) * D_005F6C10[*(u16 *)(arg0 + 6)];
    *(s32 *)(unit + 0x18) = 0;
    *(s32 *)(unit + 0x98) |= 4;
    return ++*(u16 *)(arg0 + 6) >= 0x23U;
}
/* measured: restore opt_propagation after func_00197a80 FPR temporary colouring probe. */
#pragma opt_propagation on
// FUN_00197CC0
u8 *func_00197cc0(s32 arg0, s16 arg1, s16 arg2)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)func_00194470(0x10C, 0x28);
    *(void **)(packet + 0x6C) = (void *)func_00197a80;
    work = *(u8 **)(packet + 0x78);
    *(s32 *)work = arg0;
    *(s16 *)(work + 4) = arg1;
    *(s16 *)(work + 6) = arg2;
    *(f32 *)(work + 8) = func_001d4380(arg0);
    return packet;
}
// FUN_00197D50
void func_00197d50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00197D70
s32 func_00197d70(u8 *arg0)
{
    u8 *unit;
    P4_95730_Vec4 rotation;
    P4_95730_Vec3 output;
    f32 dx;
    f32 dz;
    s32 flags;
    s32 mask;
    u8 active;
    s32 result;

    unit = *(u8 **)arg0;
    if (*(s32 *)(arg0 + 0x14) == 0) {
        if ((*(s32 *)(arg0 + 0x10) & 0x1000) != 0) {
            dx = *(f32 *)(arg0 + 4) - *(f32 *)(unit + 4);
            dz = *(f32 *)(arg0 + 0xC) - *(f32 *)(unit + 0xC);
            if ((dx != 0.0f) || (dz != 0.0f)) {
                func_003dc740(&rotation, D_0060A0E0, 0,
                              fGpffff8048 * func_0044b950(dx, dz));
                if ((*(s32 *)(unit + 0x9C) & 0x2000) == 0) {
                    *(P4_95730_Vec4 *)(unit + 0x1C) = rotation;
                    *(s32 *)(unit + 0x98) |= 4;
                }
            }
            *(s32 *)(unit + 0xC4) &= ~2;
            *(u16 *)(unit + 0xC8) &= 0xFFFD;
            func_0019dea0(unit);
        } else {
            if ((*(s32 *)(arg0 + 0x10) & 0x20) != 0) {
                func_00194ff0(unit, NULL, NULL, (f32 *)&output);
                *(P4_95730_Vec3 *)(arg0 + 4) = output;
            }
            flags = *(s32 *)(arg0 + 0x10);
            *(P4_95730_Vec3 *)(unit + 0xD0) =
                *(P4_95730_Vec3 *)(arg0 + 4);
            *(s32 *)(unit + 0x504) = 0;
            *(s32 *)(unit + 0xE8) = 0;
            *(s32 *)(unit + 0xC4) = flags;
            *(u16 *)(unit + 0xC8) |= 2;
        }
    }
    mask = *(u16 *)(unit + 0xC8) & 2;
    active = (mask != 0);
    if (active == 0) {
        result = 1;
    } else {
        *(s32 *)(arg0 + 0x14) += 1;
        result = 0;
    }
    return result;
}
// FUN_00197F30
void func_00197f30(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

extern s32 func_00198810(u8 *arg0);
extern u32 func_00198840(u8 *arg0);
extern u32 func_001988b0(u8 *arg0);
extern s16 func_001991c0(u8 *arg0, u16 arg1, f32 fparg0);
extern s64 func_00199830(u8 *arg0);
static inline u32 p4_add_index_base(u32 offset, u32 base)
{
    return offset + base;
}

/* measured: declaration-corrected C candidate for func_00198380. */
// FUN_00198380
void func_00198380(u8 *arg0) {
    f32 var_f12;
    s16 temp_16_2;
    s16 temp_2;
    u32 temp_4;
    s32 temp_18;
    s32 temp_19;
    u16 temp_3;
    u16 temp_3_2;
    u16 temp_3_3;
    u16 var_6;
    u8 *temp_16;

    if (*(s32 *)(arg0 + 0x98) & 2) {
        temp_16 = (u8 *)(*(u8 **)(arg0 + 0xA00));
        temp_3 = (u16)(*(u16 *)(arg0 + 0x9D8));
        if (temp_3 & 2) {
            func_0047a0e0(temp_16, 0, 0.0f);
            return;
        }
        if ((temp_3 & 4) && ((s16)func_00199830(arg0) >= *(s16 *)(arg0 + 0x9E6)) && (*(s16 *)(arg0 + 0x9E8) > 0)) {
            func_0047a0e0(temp_16, 0, 0.0f);
            *(s16 *)(arg0 + 0x9E8) = (s16) (*(s16 *)(arg0 + 0x9E8) - 1);
            return;
        }
        func_0047a0e0(*(u8 **)(arg0 + 0xA00), 0, *(f32 *)(arg0 + 0x9E0));
        if (!(*(u16 *)(arg0 + 0x9D8) & 8)) {
            temp_3_2 = (u16)(*(u16 *)(arg0 + 0xC8));
            if ((temp_3_2 & 1) && !(temp_3_2 & 4)) {
                if (func_001988b0(arg0) == 0) {
                    if (*(s32 *)(arg0 + 0xC4) & 4) {
                        var_f12 = 2.0f;
                    } else {
                        var_f12 = 1.0f;
                    }
                    func_00198920(arg0, 1, 4U, var_f12, 1);
                }
            } else if ((func_001988b0(arg0) != 0) && (func_00198840(arg0) == 0)) {
                func_00198920(arg0, *(s16 *)(arg0 + 0x9EC), 6U, *(f32 *)(arg0 + 0x9F0), *(s8 *)(arg0 + 0x9F4));
            }
        }
        temp_3_3 = (u16)(*(u16 *)(arg0 + 0x9DC));
        switch (temp_3_3) {
        case 1:
        case 2:
            break;
        case 0:
            if (*(u8 *)(temp_16 + 0xEE) == 1) {
                temp_16_2 = (s16)(*(s16 *)(arg0 + 0x9EC));
                if (temp_16_2 != (s16)func_00198810(arg0)) {
                    temp_2 = (s16)(*(s16 *)(arg0 + 0x9EE));
                    if (temp_2 > 0) {
                        var_6 = temp_2 & 0xFFFF;
                    } else {
                        switch (temp_16_2) {
                        case 3:
                        case 0xE:
                        case 0x12:
                        case 0x18:
                            temp_4 = (u16)func_001990d0(arg0, temp_16_2 & 0xFFFF);
                            if ((s32)temp_4 < (s32)(*(u16 *)(arg0 + 0x9E4))) {
                                var_6 = (u16)(*(u16 *)(p4_add_index_base(temp_4 * 0xA, (u32)*(s32 *)(arg0 + 0x9F8)) + 8));
                            } else {
                                var_6 = 6;
                            }
                            break;
                        default:
                            var_6 = 0;
                            break;
                        }
                    }
                    func_00198920(arg0, *(s16 *)(arg0 + 0x9EC), var_6, *(f32 *)(arg0 + 0x9F0), *(s8 *)(arg0 + 0x9F4));
                }
            }
            break;
        case 3:
            if (!(*(f32 *)(temp_16 + 0x108) < 1.0f)) {
                temp_19 = (s16)func_00198810(arg0);
                temp_18 = (s16)func_00199830(arg0);
                if (temp_18 >= (s16)func_001991c0(arg0, temp_19 & 0xFFFF, 1.0f)) {
                    func_0047a0e0(temp_16, 0, 0.0f);
                }
            }
            break;
        case 4:
            if ((*(u8 *)(temp_16 + 0xEE) == 1) && ((s16)func_00198810(arg0) != 0xE)) {
                func_00198920(arg0, 0xE, 0U, 1.0f, 1);
            }
            break;
        case 5:
            if ((*(u8 *)(temp_16 + 0xEE) == 1) && ((s16)func_00198810(arg0) != 0x10)) {
                func_00198920(arg0, 0x10, 0U, 1.0f, 1);
            }
            break;
        }
        *(u16 *)(arg0 + 0x9D8) = (u16) (*(u16 *)(arg0 + 0x9D8) & 0xFFF7);
    }
}
// FUN_00198810
s32 func_00198810(u8 *arg0) {
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
        return *(s16 *)(arg0 + 0x9DA);
    }
    return 0;
}
// FUN_00198840
/* Ported from P3FES btlUnit00282c60: the P4 genus/flag/value fields retain
   the donor layout at 0xA2/0x98/0x9DA, with the result comparing unk_9EC. */
u32 func_00198840(u8 *unit)
{
    s16 val;

    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
    case 1:
        if ((*(s32 *)(unit + 0x98) & 2) != 0) {
            val = *(s16 *)(unit + 0x9DA);
        } else {
            val = 0;
        }
        return *(s16 *)(unit + 0x9EC) == val;
    }

    return 0;
}

// FUN_001988B0
/* Ported from P3FES btlUnit00282cd0: the P4 genus/flag/value fields retain
   the donor layout at 0xA2/0x98/0x9DA, with the result testing val == 1. */
u32 func_001988b0(u8 *unit)
{
    s16 val;

    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
    case 1:
        if ((*(s32 *)(unit + 0x98) & 2) != 0) {
            val = *(s16 *)(unit + 0x9DA);
        } else {
            val = 0;
        }
        return val == 1;
    }

    return 0;
}

typedef struct MotionTableEntry {
    s16 followMotion;
    s16 ratePercent;
    s16 followFrame;
    s16 unknown6;
    s16 nextMotion;
} MotionTableEntry;
static inline u16 motionModeFlags(u16 option)
{
    switch (option) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        return 0;
    default:
        return 1;
    }
}
/* Measured: 1196 instruction bytes, nine resolved relocations and four zero
 * tail bytes. Animation and blend frames retain their halfword domains through
 * the model dispatcher. The table views keep rate and follow-up lifetimes
 * separate; the shared motion contracts preserve all existing callers. */
// FUN_00198920
void func_00198920(u8 *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4)
{
    extern f32 iGpffff80d4;
    extern f32 iGpffff812c;
    extern u8 *func_0019eda0(u8 *arg0, s32 arg1);
    s32 a1m;
    u16 v11;
    s32 v12;
    s16 *sp;
    MotionTableEntry *base;
    MotionTableEntry *table;

    *(s16 *)(arg0 + 0x9DC) = arg4;
    if ((*(u32 *)(arg0 + 0x98) & 2) != 0) {
        a1m = (u16)arg1;
        *(s16 *)(arg0 + 0x9DA) = arg1;
        v11 = (u16)func_001990d0(arg0, a1m);
        if ((u16)v11 < *(u16 *)(arg0 + 0x9E4)) {
            table = *(MotionTableEntry **)(arg0 + 0x9F8);
            *(f32 *)(arg0 + 0x9E0) = arg3 * ((f32)table[v11].ratePercent / 100.0f);
        } else {
            *(s32 *)(arg0 + 0x9E0) = 0x3F800000;
        }
        arg4 = arg4 & 0xFFFF;
        v12 = motionModeFlags(arg4);
        if (arg3 < iGpffff80d4 || !(arg3 <= iGpffff812c)) {
            switch (arg1) {
            case 4:
            case 12:
            case 8:
                v12 = (u16)(v12 | 0x60);
                break;
            default:
                break;
            }
        }
        if (((*(u16 *)(arg0 + 0x9D8) & 0x10) != 0) || (*(s32 *)(arg0 + 0xA64) != 0 && datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 256) != 0)) {
            v12 = (u16)(v12 | 0x100);
        }
        if (arg1 == 19) {
            func_0047a150(*(u8 **)(arg0 + 0xA00));
        } else {
            func_0047a120(*(u8 **)(arg0 + 0xA00));
        }
        if ((*(u16 *)(arg0 + 0x9D8) & 0x20) != 0) {
            arg2 = 0;
        }
        if ((*(u16 *)(arg0 + 0x9D8) & 0x40) != 0) {
            v11 = 27;
        }
        func_00479940(*(u8 **)(arg0 + 0xA00), 0, (s32)(s16)v11, arg2, v12);
        func_0047a0e0(*(u8 **)(arg0 + 0xA00), 0, *(f32 *)(arg0 + 0x9E0));
        sp = (s16 *)func_0019eda0(arg0, a1m);
        *(f32 *)(arg0 + 0x80) = (f32)sp[0];
        *(f32 *)(arg0 + 0x84) = (f32)sp[1];
        *(f32 *)(arg0 + 0x88) = (f32)sp[2];
        *(f32 *)(arg0 + 0x8C) = (f32)(u16)sp[3];
        *(f32 *)(arg0 + 0x90) = (f32)(u16)sp[4];
        switch (arg1) {
        case 8:
        case 16:
            if ((u16)v11 < *(u16 *)(arg0 + 0x9E4)) {
                base = &((MotionTableEntry *)*(u8 **)(arg0 + 0x9F8))[(u16)v11];
                if (base->followMotion >= 0 && base->followFrame > 0) {
                    *(u16 *)(arg0 + 0x9D8) = *(u16 *)(arg0 + 0x9D8) | 4;
                    *(s16 *)(arg0 + 0x9E6) = ((MotionTableEntry *)*(u8 **)(arg0 + 0x9F8))[(u16)v11].followMotion;
                    *(s16 *)(arg0 + 0x9E8) = ((MotionTableEntry *)p4_base_add_00194590((u16)v11 * sizeof(MotionTableEntry), *(s32 *)(arg0 + 0x9F8)))->followFrame;
                }
            }
            break;
        default:
            *(u16 *)(arg0 + 0x9D8) = *(u16 *)(arg0 + 0x9D8) & 0xFFFB;
            break;
        }
        if (arg4 == 0) {
            switch (arg1) {
            case 2:
            case 8:
            case 12:
            case 9:
            case 11:
            case 22:
            case 23:
            case 20:
                *(s16 *)(arg0 + 0x9EE) = 0;
                break;
            case 4:
                *(s16 *)(arg0 + 0x9EE) = 0;
                break;
            default:
                if ((u16)v11 < *(u16 *)(arg0 + 0x9E4)) {
                    table = *(MotionTableEntry **)(arg0 + 0x9F8);
                    *(s16 *)(arg0 + 0x9EE) = table[v11].nextMotion;
                } else {
                    *(s16 *)(arg0 + 0x9EE) = 0;
                }
                break;
            }
        }
    }
}
/* Recovered.  Two shapes closed it: the availability flag is an if/else
   (`if (r == 1) flag = 0; else flag = 1;`) rather than `flag = 1` with a
   conditional clear - retail reuses the materialised 1 as both the flag
   value and the comparison constant, and keeps the unreachable clear the
   else arm leaves behind - and the kind test is a `switch` with `case 0:
   case 1:` falling into one body, which emits retail's three-branch chain
   (beq 1, beqz, b default) instead of the inverted two-branch form an
   `||` condition produces.  The case labels are written 0 then 1 because
   the compare chain is emitted in reverse label order. */
// FUN_00198DD0
#pragma push
#pragma opt_propagation off
void func_00198dd0(u8 *arg0, u16 arg1)
{
    s16 var_18;
    s64 value;
    u16 var_17;
    u16 var_16;
    s32 same;
    s32 flag;
    s32 r;
    s16 temp;
    extern s32 func_00479dd0(u8 *a, u32 b, s16 c);
    extern s32 datCalcChkBadStatus();

    var_18 = 0;
    if (datCalcIsLowHp(*(u8 **)(arg0 + 0xA64)) != 0) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp = (s16)(func_001990d0(arg0, 0x12) & 0xFFFF);
            if (func_00479d10(*(u8 **)(arg0 + 0xA00), 0, temp) == 0) {
                flag = 0;
            } else {
                r = func_00479dd0(*(u8 **)(arg0 + 0xA00), 0, temp);
                if (r == 1) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
        } else {
            flag = 0;
        }
        if (flag != 0) {
            var_18 = 0x12;
        }
    }
    if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0xFFFFF) != 0) {
        var_18 = 3;
    }
    if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100000) != 0) {
        var_18 = 0xA;
    }
    if (func_00243e30(*(s32 *)(arg0 + 0xA64)) != 0) {
        var_18 = 0x18;
    }
    if (datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100) != 0) {
        var_18 = 0;
    }
    if ((datCalcIsDead(*(u8 **)(arg0 + 0xA64), 0) != 0) && ((*(s32 *)(arg0 + 0x9C) & 0x20) != 0)) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp = (s16)(func_001990d0(arg0, 0x13) & 0xFFFF);
            if (func_00479d10(*(u8 **)(arg0 + 0xA00), 0, temp) == 0) {
                flag = 0;
            } else {
                r = func_00479dd0(*(u8 **)(arg0 + 0xA00), 0, temp);
                if (r == 1) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
        } else {
            flag = 0;
        }
        if (flag != 0) {
            var_18 = 0x13;
        }
    }
    value = (s64)var_18;
    if (value != 0x13) {
        var_17 = 1;
        var_16 = *(u16 *)(arg0 + 0x9EE);
    } else {
        var_17 = 2;
        var_16 = 0;
    }
    {
        u8 kind;
        s16 ref;

        kind = *(u8 *)(arg0 + 0xA2);
        switch (kind) {
        case 0:
        case 1:
            if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
                ref = *(s16 *)(arg0 + 0x9DA);
            } else {
                ref = 0;
            }
            same = (s32)(*(s16 *)(arg0 + 0x9EC) == (s16)ref);
            break;
        default:
            same = 0;
            break;
        }
    }
    if ((same != 0) && ((s64)(*(s16 *)(arg0 + 0x9EC)) != value)) {
        func_00198920(arg0, var_18, arg1, 1.0f, var_17);
    }
    *(s16 *)(arg0 + 0x9EC) = var_18;
    *(u16 *)(arg0 + 0x9EE) = var_16;
    *(f32 *)(arg0 + 0x9F0) = 1.0f;
    *(s8 *)(arg0 + 0x9F4) = var_17;
}
#pragma pop
/* measured: opt_propagation off is scoped to func_001990d0. */
#pragma opt_propagation off
// FUN_001990D0
s64 func_001990d0(u8 *arg0, s32 arg1)
{
    u8 kind;
    s32 index;
    s32 offset;
    u8 *table;
    s64 result;

    kind = *(u8 *)(arg0 + 0xA2);
    switch (kind) {
    case 1:
        result = func_0022cb90();
        if (result != -1) {
            return result;
        }
    case 0:
    case 2:
        kind = *(u8 *)(arg0 + 0xA2);
        index = kind * 0x1E;
        table = D_005F6CA0 + index;
        offset = arg1 & 0xFFFF;
        result = (s64)((s64)*(u8 *)p4_base_add_00194590(
            offset, (s32)table) << 48) >> 48;
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) != 0) {
            if (kind == 0) {
                if (*(u16 *)(arg0 + 0xA4) == 1) {
                    if (offset == 1) {
                        result = 0x1C;
                    }
                }
            }
        }
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
/* measured: closes opt_propagation around func_001990d0. */
#pragma opt_propagation on
// FUN_001991C0
s16 func_001991c0(u8 *arg0, u16 arg1, f32 fparg0)
{
    extern s64 func_0022cb90(void);
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 final_result;
    u8 type;
    u8 *entry;

    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(func_0022cb90());
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            (s32)final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        return (s64)(s32)((f32)*(s16 *)(entry + 0) /
            (fparg0 * ((f32)*(s16 *)(entry + 2) / 100.0f)));
    }
    return 0;
}
// FUN_00199350
s16 func_00199350(u8 *arg0, s32 arg1, f32 fparg0)
{
    extern s64 func_0022cb90(void);
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    u8 type;
    u8 *entry;
    s16 numerator;

    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(func_0022cb90());
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
{
    s32 final_result;
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            (s32)final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        numerator = *(s16 *)(entry + 4);
        if (numerator < 0) {
            return 0;
        }
        return (s64)(s32)((f32)numerator /
            (fparg0 * ((f32)*(s16 *)(entry + 2) / 100.0f)));
    }
}
return 0;
}
// FUN_00199500
s16 func_00199500(u8 *arg0, u16 arg1, f32 fparg0)
{
    extern f32 func_0047a000(s32 arg0, s32 arg1, s64 arg2);
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 final_result;
    f32 temp_f0;
    u8 type;
    u8 *entry;

    if (!(*(s32 *)(arg0 + 0x98) & 2)) {
        return 0;
    }
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(func_0022cb90());
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
    temp_f0 = func_0047a000(*(s32 *)(arg0 + 0xA00), 0, result);
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        return (s64)(s32)(temp_f0 /
            (fparg0 * ((f32)*(s16 *)(entry + 2) / 100.0f)));
    }
    return (s64)(s32)temp_f0;
}
// FUN_001996D0
s16 func_001996d0(u8 *arg0, s32 arg1)
{
    extern s64 func_0022cb90(void);
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 final_result;
    u8 type;
    u8 *entry;

    if (!(*(s32 *)(arg0 + 0x98) & 2)) {
        return 6;
    }
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 1:
        result = p4_sign16_001991c0(func_0022cb90());
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(arg0 + 0xA2);
        table = D_005F6CA0 + (type * 0x1E);
        value = p4_sign16_001991c0(
            *(u8 *)(table + (offset = arg1 & 0xFFFF)));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = p4_sign16_001991c0(value);
finish:
    final_result = (s32)(s16)result;
    if (final_result < *(u16 *)(arg0 + 0x9E4)) {
        entry = (u8 *)p4_base_add_00194590(
            final_result * 10, (s32)*(u8 **)(arg0 + 0x9F8));
        return *(s16 *)(entry + 8);
    }
    return 6;
}
// FUN_00199830
s64 func_00199830(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x98) & 2) {
        return (s64)(s16)(s32)func_0047a080(*(s32 *)(arg0 + 0xA00), 0);
    }
    return 0;
}



// FUN_00199890
void func_00199890(u8 *arg0, s32 arg1)
{
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0)
        func_00479e60(*(u8 **)(arg0 + 0xA00), 0, (f32)arg1);
}

/* measured: opt_propagation off is scoped to func_001998e0. */
#pragma opt_propagation off
// FUN_001998E0
s32 func_001998e0(u8 *arg0, s32 arg1)
{
    s32 index;
    s32 result;
    s64 signedResult;
    u8 kind;
    u16 id;
    s32 offset;
    s32 base;
    s32 finalResult;

    kind = *(u8 *)(arg0 + 0xA2);
    if (kind == 1) {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 4:
        case 5:
        case 6:
        case 7:
            result = 0;
            goto classification_done_001998e0;
        default:
            goto result_invalid_001998e0;
        }
    } else {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 5:
            result = 0;
            goto classification_done_001998e0;
        case 6:
        case 7:
            result = 1;
            goto classification_done_001998e0;
        default:
            goto result_invalid_001998e0;
        }
    }
result_invalid_001998e0:
    result = -1;
classification_done_001998e0:
    signedResult = (s64)(s16)result;
    if (signedResult == -1) {
        return 1;
    }
    if (kind == 1) {
        id = *(u16 *)(arg0 + 0xA4);
        offset = id * 0xE8;
        base = (s32)iGpffffb3cc;
        offset = offset + base;
        index = (s16)result;
        finalResult = *(s16 *)((u8 *)p4_base_add_00194590(
            index * 4, offset) + 0x1A);
        goto function_done_001998e0;
    }
    finalResult = 1;
function_done_001998e0:
    return finalResult;
}
/* measured: closes opt_propagation around func_001998e0. */
#pragma opt_propagation on
/* measured: direct s64-parameter candidate for func_001999f0; propagation off
   keeps the entry mask and per-use narrow conversions as separate values. */
#pragma opt_propagation off
// FUN_001999F0
s16 func_001999f0(u8 *arg0, s32 arg1, f32 fparg0, s64 arg2)
{
    u16 index;
    s16 class_result;
    u8 type;
    s64 value;
    s64 raw_value;
    s32 numerator;
    s16 denominator;
    s32 offset;
    s32 base;
    u16 array_index;

    type = *(u8 *)(arg0 + 0xA2);
    if (type == 1) {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 4:
        case 5:
        case 6:
        case 7:
            class_result = p4_sign16_001991c0(0);
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    } else {
        index = arg1 & 0xFFFF;
        switch (index) {
        case 5:
            class_result = p4_sign16_001991c0(0);
            goto classification_done_001999f0;
        case 6:
        case 7:
            class_result = p4_sign16_001991c0(1);
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    }
result_invalid_001999f0:
    class_result = p4_sign16_001991c0(-1);
classification_done_001999f0:
    if (class_result == -1) {
        return 0;
    }
    switch (type) {
    case 1:
        {
            extern s16 func_0022cb90(u8 *arg0, s32 arg1);
            value = p4_sign16_001991c0(func_0022cb90(arg0, arg1));
        }
        switch (value) {
        case -1:
            goto lookup_001999f0;
        default:
            goto finish_001999f0;
        }
    case 0:
    case 2:
lookup_001999f0:
        type = *(u8 *)(arg0 + 0xA2);
        raw_value = p4_sign16_001991c0(
            *(u8 *)((u8 *)D_005F6CA0 + type * 0x1E + (u16)arg1));
        if ((*(s32 *)(arg0 + 0xC4) & 0x100) &&
            (type == 0) &&
            (*(u16 *)(arg0 + 0xA4) == 1) &&
            (index == 1)) {
            raw_value = p4_sign16_001991c0(0x1C);
        }
        goto value_done_001999f0;
    default:
        value = 0;
        goto finish_001999f0;
    }
value_done_001999f0:
    value = p4_sign16_001991c0(raw_value);
finish_001999f0:
    if (*(u8 *)(arg0 + 0xA2) == 1) {
        {
            s64 product;
            offset = *(u16 *)(arg0 + 0xA4) * 0xE8;
            base = (s32)iGpffffb3cc;
            offset = p4_base_add_00194590(offset, base);
            offset = p4_base_add_00194590(
                (s32)(s16)class_result * 4, offset);
            numerator = *(s16 *)((u8 *)offset + 0x1C);
            product = (s64)(s16)(numerator * (s16)arg2);
            numerator = (s32)product +
                        *(s16 *)((u8 *)(*(s32 *)(arg0 + 0x9F8) +
                                        (u16)arg1 * 0xA));
            product = (s64)(s16)numerator;
            numerator = (s32)product;
        }
    } else {
        offset = *(u16 *)(arg0 + 0xA4) * 0x14C;
        base = (s32)iGpffffb3c0;
        offset = p4_base_add_00194590(offset, base);
        offset = p4_base_add_00194590(
            (s32)class_result * 0x12, offset);
        offset = p4_base_add_00194590(
            (s32)(u16)arg2 * 2, offset);
        numerator = *(s16 *)((u8 *)(offset + 0x1A));
    }
    base = *(s32 *)(arg0 + 0x9F8);
    denominator = *(s16 *)((u8 *)(p4_base_add_00194590(
        (s16)value * 0xA, base) + 2));
    return (s16)(s32)((f32)numerator /
                      (fparg0 * ((f32)denominator / 100.0f)));
}
#pragma opt_propagation on
/* Measured: 336B/336B, nd 0. Keep the full-width ID for the predicate;
   scoped propagation preserves the staged unsigned table offset. */
// FUN_00199D00
#pragma push
#pragma opt_propagation off
s32 func_00199d00(s32 unused, u8 *arg1, s64 arg2, s32 arg3)
{
    s32 temp_16;
    u32 offset;
    u16 temp_3;
    s64 raw_3;
    s16 narrowed_3;

    temp_16 = (s64)(s16)arg2;
    if (temp_16 == -1 || temp_16 >= 0x1B8)
        return 1;
    if (func_001f11e0(arg2) != 0) {
        offset = (u32)temp_16 << 2;
        temp_3 = *(u16 *)((u32)iGpffffb3bc + 2U + offset);
        if ((temp_3 & 0x200) == 0) {
            if ((arg3 == 0) || ((temp_3 & 1) == 0)) {
                return 1;
            }
            return 2;
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0 &&
            arg3 == 0) {
            return 1;
        }
        return 0;
    }
    raw_3 = func_0023d8e0(*(u8 **)(arg1 + 0xA64), (u16)arg2);
    narrowed_3 = (s16)raw_3;
    switch (narrowed_3) {
    case 0x10:
    case 0x11:
        return 1;
    default:
        return 3;
    }
}
#pragma pop
// FUN_00199E50
void func_00199e50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00199E70
u32 func_00199e70(void *workData)
{
    u8 *packet = (u8 *)workData;
    s16 motion;
    s32 frame;
    f32 rate;
    u16 option;

    motion = *(s16 *)(packet + 4);
    if (motion >= 0 && motion < 0x1E) {
        workData = *(u8 **)packet;
        frame = *(u16 *)(packet + 6);
        rate = *(f32 *)(packet + 8);
        option = *(u16 *)(packet + 0xC);
        func_00198920((u8 *)workData, motion, frame, rate, option);
    }
    return 1;
}

// FUN_00199EC0
void func_00199ec0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A010
void func_0019a010(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A030
u32 func_0019a030(void *workData)
{
    u8 *packet = (u8 *)workData;
    s16 requested;
    s16 current;
    u16 option;
    u16 frame;
    f32 rate;

    workData = *(u8 **)workData;
    if ((*(s32 *)((u8 *)workData + 0x98) & 2) != 0)
        current = *(s16 *)((u8 *)workData + 0x9DA);
    else
        current = 0;
    requested = *(s16 *)((u8 *)workData + 0x9EC);
    if (requested != current) {
        option = *(s8 *)((u8 *)workData + 0x9F4);
        frame = *(u16 *)(packet + 4);
        rate = *(f32 *)((u8 *)workData + 0x9F0);
        func_00198920((u8 *)workData, requested, frame, rate, option);
    }
    return 1;
}

// FUN_0019A0A0
void func_0019a0a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A130
void func_0019a130(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A150
s32 func_0019a150(u8 *arg0)
{
    P4_95730_Vec3 sp30;
    f32 var_f1;
    u8 *temp_16;

    temp_16 = *(u8 **)arg0;
    *(s32 *)(temp_16 + 0x98) |= 4;
    if (*(f32 *)(arg0 + 4) <= 0.5f)
        goto block_2;
    RtQuatTransformVectors(&sp30, &D_0060A0D0, 1, temp_16 + 0x1C);
    if ((*(s32 *)(arg0 + 8) & 1) != 0)
        var_f1 = *(f32 *)(arg0 + 4) *
                 (0.5f + (0.5f * effMiscRandFloat(0)));
    else
        var_f1 = (-*(f32 *)(arg0 + 4)) *
                 (0.5f + (0.5f * effMiscRandFloat(0)));
    *(f32 *)(temp_16 + 0x10) = sp30.x * var_f1;
    *(f32 *)(temp_16 + 0x14) = sp30.y * var_f1;
    *(f32 *)(temp_16 + 0x18) = sp30.z * var_f1;
    *(f32 *)(arg0 + 4) = *(f32 *)(arg0 + 4) * fGpffff82d0;
    *(u16 *)(temp_16 + 0x9D8) |= 1;
    goto block_3;
block_2:
    *(s32 *)(temp_16 + 0x10) = 0;
    *(s32 *)(temp_16 + 0x14) = 0;
    *(s32 *)(temp_16 + 0x18) = 0;
    *(u16 *)(temp_16 + 0x9D8) &= 0xFFFE;
    return 1;
block_3:
    *(s32 *)(arg0 + 8) += 1;
    return 0;
}
// FUN_0019A2C0
void func_0019a2c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A660
void func_0019a660(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A680
s32 func_0019a680(u8 *arg0)
{
    P4_95730_Vec3 sp40;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f4;
    f32 var_f20;
    f32 var_f5;
    u8 *temp_16;

    temp_16 = *(u8 **)arg0;
    var_f5 = fGpffff811c *
             (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C));
    if (!(var_f5 <= 100.0f))
        var_f5 = 100.0f;
    if (*(s32 *)(arg0 + 4) == 0) {
        *(f32 *)(arg0 + 8) = 0.0f;
        *(f32 *)(arg0 + 0xC) = fGpffff8198;
    }
    temp_f4 = *(f32 *)(arg0 + 0xC);
    if (!(temp_f4 < 0.0f)) {
        temp_f0 = *(f32 *)(arg0 + 8);
        temp_f1 = (1.0f - temp_f0) * temp_f4;
        *(f32 *)(arg0 + 0xC) = temp_f4 + fGpffff82d8;
        temp_f0 = *(f32 *)(arg0 + 8);
        var_f20 = var_f5 * temp_f0;
        temp_f1 = p4_add_0019a680(temp_f0, temp_f1);
        *(f32 *)(arg0 + 8) = temp_f1;
        if (!(temp_f1 < fGpffff82d4))
            *(f32 *)(arg0 + 0xC) = fGpffff82dc;
        goto block_11;
    }
    temp_f1_2 = -temp_f4;
    temp_f0_2 = *(f32 *)(arg0 + 8);
    temp_f0_3 = temp_f0_2 * temp_f1_2;
    temp_f1_2 = fGpffff80f0;
    *(f32 *)(arg0 + 0xC) = temp_f4 - temp_f1_2;
    temp_f0_2 = *(f32 *)(arg0 + 8);
    var_f20 = var_f5 * temp_f0_2;
    temp_f0_3 = temp_f0_2 - temp_f0_3;
    *(f32 *)(arg0 + 8) = temp_f0_3;
    if (temp_f0_3 <= temp_f1_2) {
        if ((*(s32 *)(temp_16 + 0x9C) & 0x400) == 0) {
            *(f32 *)(temp_16 + 0x10) = 0.0f;
            *(f32 *)(temp_16 + 0x14) = 0.0f;
            *(f32 *)(temp_16 + 0x18) = 0.0f;
            *(s32 *)(temp_16 + 0x98) |= 4;
        }
        return 1;
    }
block_11:
    if ((*(s32 *)(temp_16 + 0x9C) & 0x400) == 0) {
        RtQuatTransformVectors(&sp40, &D_0060A0D0, 1, temp_16 + 0x1C);
        *(f32 *)(temp_16 + 0x10) = sp40.x * var_f20;
        *(f32 *)(temp_16 + 0x14) = sp40.y * var_f20;
        *(f32 *)(temp_16 + 0x18) = sp40.z * var_f20;
        *(s32 *)(temp_16 + 0x98) |= 4;
    }
    *(s32 *)(arg0 + 4) += 1;
    return 0;
}
// FUN_0019A840
void func_0019a840(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A8D0
void func_0019a8d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A8F0
/* Ported from P3FES btlUnitUpdate00284c90Packet: the packet's unit
   pointer is at offset 0 and its comparison field is at offset 0x9EC. */
u32 func_0019a8f0(void *work)
{
    u8 *unit;
    s16 current;

    unit = *(u8 **)work;
    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
    case 1:
        if ((*(s32 *)(unit + 0x98) & 2) != 0)
            current = *(s16 *)(unit + 0x9DA);
        else
            current = 0;
        return *(s16 *)(unit + 0x9EC) == current;
    }
    return 0;
}

// FUN_0019A960
void func_0019a960(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A9E0
void func_0019a9e0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019AA00
s32 func_0019aa00(u8 *arg0)
{
    s16 frame;
    u8 *temp_3;

    frame = *(s16 *)(arg0 + 4);
    temp_3 = *(u8 **)arg0;
    if ((*(s32 *)(temp_3 + 0x98) & 2) != 0)
        func_00479e60(*(u8 **)(temp_3 + 0xA00), 0, (f32)frame);
    return 1;
}

// FUN_0019AA50
void func_0019aa50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019AAE0
void func_0019aae0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019AB00
u32 func_0019ab00(void *workData)
{
    u8 *arg0 = (u8 *)workData;
    u8 *temp_18;
    u16 temp_17;
    u16 temp_16;
    f32 temp_f20;
    s32 temp_19;
    s16 temp_19_low;
    s16 temp_20;

    temp_16 = *(u16 *)(arg0 + 0xC);
    temp_f20 = *(f32 *)(arg0 + 8);
    temp_17 = *(u16 *)(arg0 + 4);
    temp_18 = *(u8 **)arg0;
    if (*(s32 *)(temp_18 + 0x98) & 2) {
        func_0019d990(temp_18, 4);
        if (*(s32 *)(temp_18 + 0x98) & 2)
            temp_19_low = (s32)(s16)(s32)func_0047a080(*(s32 *)(temp_18 + 0xA00), 0);
        else
            temp_19_low = 0;
        temp_19 = temp_19_low;
        p4_call_00198920((temp_20 = *(s16 *)(temp_18 + 0x9DA), temp_20), temp_18, temp_17, temp_f20, temp_16);
        if (*(s32 *)(temp_18 + 0x98) & 2)
            func_00479e60(*(u8 **)(temp_18 + 0xA00), 0, (f32)temp_19);
        func_0019d7a0(temp_18, 4);
    }
    return 1;
}
// FUN_0019AC20
void func_0019ac20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B530
void func_0019b530(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B550
u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2)
{
    u8 *work;
    u8 *packet;

    packet = (u8 *)func_00194470(0x10F, 0x10);
    *(u8 *)(packet + 0x47) &= 0xFE;
    *(void **)(packet + 0x68) = (void *)func_0019acd0;
    *(void **)(packet + 0x6C) = (void *)func_0019ae20;
    *(void **)(packet + 0x70) = (void *)func_0019b530;
    work = *(u8 **)(packet + 0x78);
    *(u8 **)work = arg0;
    *(s16 *)(work + 8) = arg2;
    if (func_002300f0(arg0, (s16 *)(work + 4), (s16 *)(work + 6)) == 0) {
        *(s16 *)(work + 4) = *(u8 *)(arg0 + 0xA2) + 1;
        *(s16 *)(work + 6) = arg1;
    }
    return packet;
}
// FUN_0019B620
void func_0019b620(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019B640
s32 func_0019b640(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    func_0019d3c0(temp);
    func_0019d0c0(temp);
    return 1;
}
// FUN_0019B680
void func_0019b680(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B710
void func_0019b710(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

typedef struct BattlePacketRgba {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} BattlePacketRgba;

typedef struct BattleColorUnit {
    u8 unknown00[0x30];
    BattlePacketRgba color;
    u8 unknown34[0x64];
    u32 flags;
} BattleColorUnit;

typedef struct BattleColorPacket {
    BattleColorUnit *unit;
    u32 startColor;
    u32 targetColor;
    s16 alphaDuration;
    s16 rgbDuration;
    u8 mode;
    u8 flags;
    s16 counter;
} BattleColorPacket;

extern f32 fGpffff81f4;

/* Mirrors the actual color-by-value setter at 00194f60. */
static inline void battleColorPublish(BattleColorUnit *unit, BattlePacketRgba color)
{
    unit->color = color;
    unit->flags |= 4;
}

/* Packed-word/VU bridge, matching model_normalize_packed_color. C owns the
 * source words and packed output; the hardware computes all four color lanes.
 * The final 0x437f0000 bit pattern transfers the real 255.0f scale to VF2.x. */
static inline u32 battleColorBlendWords(const u32 *start, const u32 *target, f32 factor)
{
    u32 targetColor;
    u32 startColor;
    u32 packedColor;
    const u32 *source;
    f32 scale;
    f32 inverse;
    u32 bits;

    targetColor = *target;
    source = &targetColor;
    scale = fGpffff81f4;
    {
        u32 bits;
        __asm__ volatile(
            "lw $2, 0(%1)\n"
            "pextlb $2, $zero, $2\n"
            "pextlh $2, $zero, $2\n"
            "qmtc2 $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            : "=&r"(bits)
            : "r"(source), "f"(scale), "m"(*source)
            : "$2", "$vf2", "$vf11", "memory");
    }
    startColor = *start;
    source = &startColor;
    {
        u32 bits;
        __asm__ volatile(
            "lw $2, 0(%1)\n"
            "pextlb $2, $zero, $2\n"
            "pextlh $2, $zero, $2\n"
            "qmtc2 $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            : "=&r"(bits)
            : "r"(source), "f"(scale), "m"(*source)
            : "$2", "$vf2", "$vf10", "memory");
    }
    inverse = 1.0f - factor;
    {
        u32 bits;
        __asm__ volatile(
            "mfc1 %0, %1\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vadd.xyzw $vf10, $vf10, $vf11\n"
            : "=&r"(bits)
            : "f"(inverse), "f"(factor)
            : "$vf2", "$vf10", "$vf11", "memory");
    }
    bits = 0x437F0000U;
    __asm__ volatile(
        "qmtc2 %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vftoi0.xyzw $vf10, $vf10\n"
        "qmfc2 %0, $vf10\n"
        "ppach %0, $zero, %0\n"
        "ppacb %0, $zero, %0\n"
        "sw %0, packedColor\n"
        : "+r"(bits), "=m"(packedColor)
        : : "$vf2", "$vf10", "memory");
    return packedColor;
}

/* Measured: 1164 instruction bytes in the 1168-byte window, three resolved
 * relocations and a four-byte zero tail. This callback uses the packet creator's
 * u32 (void *) contract. Modes 1..4 initialize every timing value; the retail
 * constructor callers use modes 3 or 4. The packet is 20 bytes.
 * Disabling propagation locally retains the alpha result's memory/merge
 * lifetime. Publication remains the actual four-byte color-by-value operation. */
#pragma push
#pragma opt_propagation off
// FUN_0019B730
u32 func_0019b730(void *workData)
{
    BattleColorPacket *packet = (BattleColorPacket *)workData;
    BattleColorUnit *unit;
    s32 counter;
    s32 alphaDuration;
    s32 rgbDuration;
    s32 alphaStart;
    s32 rgbStart;
    s32 end;
    u32 color;
    BattlePacketRgba published;
    f32 factor;

    unit = packet->unit;
    counter = packet->counter;
    switch (packet->mode) {
    case 1:
        alphaDuration = packet->alphaDuration;
        alphaStart = 0;
        rgbDuration = packet->rgbDuration;
        rgbStart = alphaDuration + 1;
        end = rgbDuration + alphaDuration;
        break;
    case 2:
        rgbDuration = packet->rgbDuration;
        rgbStart = 0;
        alphaDuration = packet->alphaDuration;
        alphaStart = rgbDuration + 1;
        end = rgbDuration + alphaDuration;
        break;
    case 3:
    case 4:
        alphaDuration = packet->alphaDuration;
        alphaStart = 0;
        rgbDuration = packet->rgbDuration;
        rgbStart = 0;
        if (rgbDuration < alphaDuration)
            end = alphaDuration;
        else
            end = rgbDuration;
        break;
    }
    if (counter == 0) {
        color = unit->color.red | (((u32)unit->color.green << 8) |
                (((u32)unit->color.alpha << 24) | ((u32)unit->color.blue << 16)));
        packet->startColor = color;
        if (packet->flags & 1)
            packet->startColor &= 0xFFFFFF;
        if (packet->flags & 2)
            packet->startColor = (packet->startColor & 0xFFFFFF) | 0xFF000000;
        if (packet->flags & 4)
            packet->startColor = 0;
        if (packet->flags & 8)
            packet->startColor = 0xFFFFFFFF;
        func_0019d040((u8 *)unit);
    }
    color = packet->startColor;
    if (counter >= rgbStart) {
        if (rgbDuration > 0 && counter < rgbStart + rgbDuration)
            factor = (f32)(counter - rgbStart) / (f32)rgbDuration;
        else
            factor = 1.0f;
        color = (color & 0xFF000000) |
                (battleColorBlendWords(&packet->startColor, &packet->targetColor, factor) & 0xFFFFFF);
    }
    if (counter >= alphaStart) {
        if (alphaDuration > 0 && counter < alphaStart + alphaDuration)
            factor = (f32)(counter - alphaStart) / (f32)alphaDuration;
        else
            factor = 1.0f;
        color = (color & 0xFFFFFF) |
                (battleColorBlendWords(&packet->startColor, &packet->targetColor, factor) & 0xFF000000);
    }
    published.red = color;
    published.green = color >> 8;
    published.blue = color >> 16;
    published.alpha = color >> 24;
    battleColorPublish(unit, published);
    if (end < counter)
        return 1;
    packet->counter++;
    return 0;
}

#pragma pop

// FUN_0019BBC0
void func_0019bbc0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BC90
void func_0019bc90(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BCB0
s32 func_0019bcb0(u8 *arg0) {
    func_0019d040(*(u8 **)arg0);
    return 1;
}
// FUN_0019BCE0
void func_0019bce0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BD60
void func_0019bd60(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BD80
s32 func_0019bd80(u8 *arg0) {
    func_0019d0c0(*(u8 **)arg0);
    return 1;
}
// FUN_0019BDB0
void func_0019bdb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BE30
void func_0019be30(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BE50
s32 func_0019be50(u8 *arg0) {
    s32 temp;

    temp = *(s32 *)(*(u8 **)arg0 + 0xA08);
    if (temp != 0) {
        func_001d6ee0(temp);
    }
    return 1;
}
// FUN_0019BE90
void func_0019be90(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BEB0
u8 *func_0019beb0(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x11B, 4);
    *(void **)(packet + 0x68) = (void *)func_0019be30;
    *(void **)(packet + 0x6C) = (void *)func_0019be50;
    *(void **)(packet + 0x70) = (void *)func_0019be90;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_0019BF10
void func_0019bf10(u8 *arg0) {
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0));
    *(u16 *)(temp_5 + 0xA0) = (u16) (*(u16 *)(temp_5 + 0xA0) + 1);
    if (!(*(u16 *)(arg0 + 8) & 0x10)) {
        temp_4 = (u8 *)(*(u8 **)(temp_5 + 0xA00));
        if (*(s32 *)(temp_4 + 0x2D0) == 0) {
            func_0047d170(temp_4, temp_5);
        }
        *(s32 *)(arg0 + 0xC) = 1;
    }
}

// FUN_0019BF80
s32 func_0019bf80(u8 *arg0) {
    u8 *temp_3;
    u8 *temp_4;

    temp_3 = *(u8 **)(arg0 + 0);
    if (*(s32 *)(arg0 + 0xC) == 0) {
        temp_4 = *(u8 **)(temp_3 + 0xA00);
        if (*(s32 *)(temp_4 + 0x2D0) == 0) {
            func_0047d170(temp_4);
        }
        *(s32 *)(arg0 + 0xC) = 1;
        goto block_6;
    }
    if (func_0047e6f0((void **)(*(u8 **)(temp_3 + 0xA00) + 0x2D0)) != 0) {
        return 1;
    }
block_6:
    return 0;
}
// FUN_0019C010
void func_0019c010(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

/* measured: restored in-gate 867 (951 retail / 951 object instrs) with 7r-only fix (hoisted xx..wz reused twice -> plain mul/add; ??+18->0, mul-9->0, add-14->-8; single opt_common_subs off). Rejected 853 attempt (951/884, -67, -7.0% outside 922-980 band): stacked opt_propagation off + hoisted one/two/half/f255 vars removed per-use materialisation (lui+31->-1) per 7u mirror. Table-base pass 2026-09-19: lui per immediate retail 17 vs object 48 surplus 31 (2.0f 1->9, 255.0f/0.5f 3->12 each, 0x737FB 2->5; no HI16 tables, all GP); hoisted fGpffff81f4 to inv (24 loads -> 1 base, propagation untouched, accumulator fix kept, no one/two/half/f255 hoist): 867->864 words, 951->930 instrs (in 922-980 band), 1088->1069 edits, lui unchanged 48 vs 17. Banked floor; production stays ASM. */
/* 2026-09-19 composition audit (handoff 7aa).  The count is 951/951 exact
   and the structure is still a third wrong: fnalign shows a pure delete of
   347 instructions at retail[465:812] (0x0019C814-0x0019CD7C) against a pure
   insert of 163 at object[576:739].
   What the missing span is: retail's trailing two colour stages, `u = t * c`
   then `col = u * d`, spilled through SP+0xAC..0xAF as unsigned bytes in
   channel order 1,2,3,0, with the `bltz`/`srl` unsigned conversion and
   `adda`/`madd` rounding.  This body invents a compact s32-register version
   at 0x8C..0x8F in channel order 0,1,2,3.
   Five rewrites measured, all with `opt_common_subs off` only and the 7r fix
   kept: a `u[4]` spill for the u-stage 995 instrs/922 words; a single
   `tmp[4]` with hoisted a/b/c/d 1047/972; an `RwMatrix` frame after the
   btlUnit honest caller 956/887 with edits flat at 1088 and the frame moving
   0x90 -> 0xA0 toward retail's 0xB0; that plus a hoisted spill 1052/980; and
   direct loads with one `tmp[4]` in retail's 1,2,3,0 order (archived as
   docs/probe_archive/C19C0D0_v5_structure.c) which **closes the 347/163 pair
   outright** - largest hole falls to 97, inserts to 28 - and takes edits
   1088 -> 999, but drifts to 1052 instructions, +101 and outside the
   922-980 band.  Not banked for that reason.
   Next step is not more colour logic: the remaining 97-instruction hole is
   the t-stage at the wrong frame slot, `tmp` at 0x9C against retail's 0xAC,
   frame 0xA0 against 0xB0, base 0x50 against 0x60.  Fix the slot and the
   drift together. */
/* measured 0019c0d0 (owner, this session): 930 against retail 951 (inside), 1068 fnalign edits,
   864 differing words.  The dominant defect is a **relocation, not an expression**: one pure
   delete of 347 instructions at retail[465:812] against object[772], with 153 and 43 surplus
   instructions the object emits early at object[568] and object[514].  Retail places that
   material late; the object places it early.
   Three hypotheses measured and rejected, so nobody repeats them:
   (a) moving the `entry + 0x98 & 4` block after the `entry + 0xA00 + 0xD8` test - 1068 -> 1100.
   (b) `(f32)(u32)*(u8 *)` at all sixteen byte-to-float sites - exactly neutral, 1068 and the
       same count.  Retail's conversion at R466-R479 really is the 15-instruction unsigned recipe
       (`lbu 0x3d($s4)`, `bltz`, `srl`, `andi`, `or`, `mtc1`, `cvt.s.w`), but casting a `u8` to
       `u32` does not reach it - MWCC knows the value is non-negative and folds the guard away.
   (c) routing those sites through an inline `f32 f(u32)` helper, which does force a genuine u32
       parameter - 1068 -> 1139, worse.
   So the unsigned recipe in retail comes from a value that is genuinely 32-bit at its source,
   not a widened byte: find the field that is really a `u32` before spending more on the casts.
   Register state: retail saves $s4 the body does not, the body saves a spare $f20, frame 0xA0
   against retail's 0xB0 - one saved GPR, and holding a float where retail holds a pointer is
   the usual reason. */
/* measured 0019c0d0 (owner, 2026-09-19): fnalign edits **1068 -> 1042** by writing the
   `if (i == c) ... else if` chain as a `switch (i)` with the cases ascending and the
   trailing `else` as `default`.  Swept with a brace-aware converter over the 26
   highest-edit first-party floors that carry a chain; seven improved, six got worse and
   the rest have no convertible chain, so this is measured per function. */
/* measured 0019c0d0 (owner, 2026-09-20): helper census 8 `__floatdisf` (object-only,
   `libcall_scan` + `measure_guarded` relocs; retail `asm/nonmatchings/code1_0019/func_0019c0d0.s`
   carries no helper symbols so the census alone proves nothing). Retail shape at all eight
   sites is narrow: `sb v0,0xac(sp)` at 0x0019c7cc (t0 store, no `andi`/64-bit/`jal`) and
   `lbu v0,0xad(sp)` at 0x0019c85c + `bltz`/`srl v1,v0,1`/`andi`/`or`/`mtc1`/`cvt.s.w`
   at 0x0019c860-0x0019c894 (u1 reload, unsigned-32, no `dsll32`/`dsra32`/`jal`; same recipe
   at 0x0019c8a4/0x0019c8e8/0x0019c92c/0x0019c9fc and 0x0019cac0-0x0019cd64 for u2/u3/u0 and
   col), while the object does `dsll32 $a0,$v0,0` + `dsra32` + `jal __floatdisf` at eight
   sites. The two remaining `s64` (`v41`, `chk`) are legitimate: retail is wide there
   (`dsll32 s2,v0,0xc` + `dsrl32` at 0x0019cecc for `& 0xFFFFF` as 64-bit, `dsll32 s1,v0,0x10`
   + `dsra32` at 0x0019cee4 and `dsll32 v0,v0,0x10` + `dsra32` at 0x0019cef8 for `(s16)`
   sign-extend to 64).
   Case per amended gate: object SHORTER (941 against retail 951), so any correct removal must
   move the count away (helpers longer than narrow) - expected, keep inside the +-3% band
   (922-980; brief's 10 down is the 2% view, lower 931). Baseline 981 edits, 951/941.
   All eight helper-free, measured from this baseline (`fnalign --candidate`):
   s32 decls 1029 edits/922 instrs (0 helpers, -19 away, at 3% edge, edits +48 WORSE);
   s16 1045/938 (+64 WORSE); keep-s64 + `(s32)` cast at use 1057/944 (+76 WORSE);
   u32 1259/1010, u16 1259/1010, u8-unsigned 1262/1013, hybrid `u8 tmp[4]` 1,2,3,0 1259/1010,
   V5 structure 999/1052 (all outside and/or edits up WORSE). Reordered s32 1,2,3,0 identical
   to s32 (compiler normalises order). No narrow spelling stays inside and takes edits down:
   helpers are reloc-excluded so removing them reveals counted mismatch (signed/unsigned
   `cvt` + spills vs `jal`), and matching retail's counted spill/order/`madd` needs +70-110
   (outside). Leave the banked compact floor; the spilled 1,2,3,0 structure is the documented
   outside-band fix (header v5). No code change. */
// FUN_0019C0D0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_0019c0d0(void)
{
    extern u32 func_00196610(u8 *arg0);
    extern void func_00230170(u8 *arg0);
    extern void func_0014b150(u16 arg0, u32 arg1);
    extern void func_001b70c0(u8 *arg0);
    extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
    extern void mdlScale(void *arg0, void *arg1, s32 arg2);
    extern void func_0047a180(void *arg0, void *arg1, s32 arg2);
    extern void func_00478e70(void *arg0);
    extern s32 func_001ee490(u8 *arg0);
    extern u32 func_0019d130(u8 *arg0);
    extern s32 func_001d72e0(s32 arg0);
    extern s16 func_001d7130(s32 arg0);
    extern void func_001d7400(s32 arg0, u8 *arg1);
    extern void func_001d7100(u8 *arg0, s16 arg1);
    extern void func_001d72c0(void *arg0, u32 arg1);
    extern void func_001d7140(u8 *arg0);
    extern f32 fGpffff81f4;
    s32 i;
    u8 *entry;
    f32 inv;
    inv = fGpffff81f4;
    i = 0;
    while ((u32)i < 4U) {
        entry = *(u8 **)(D_0076449C + (i * 8) + 0x17C);
        while (entry != NULL) {
            func_00196610(entry);
            func_00198380(entry);
            switch (i) {
            case 1:
                func_00230170(entry);
                break;
            case 2:
                if ((*(s32 *)(entry + 0x98) & 2) != 0) {
                    if (*(u16 *)(entry + 0x9FE) != 0) {
                        func_0014b150(*(u16 *)(entry + 0x9FE), (u32)(*(u8 *)(entry + 0xAC) == 1));
                    }
                }
                break;
            }
            if ((*(s32 *)(entry + 0x98) & 2) != 0) {
                func_001b70c0(entry);
                {
                    s32 v = *(u16 *)entry;
                    if (((v & 3) == 0) || ((v & 4) != 0)) {
                        s32 t = *(u8 *)(entry + 0x37);
                        if (t != 0xFF) {
                            if (t < 0xDF) {
                                *(u8 *)(entry + 0x37) = (u8)(t + 0x20);
                            } else {
                                *(u8 *)(entry + 0x37) = 0xFF;
                            }
                            *(s32 *)(entry + 0x98) |= 4;
                        }
                    } else {
                        s32 base;
                        if ((v & 8) == 0) {
                            base = 0;
                        } else {
                            base = 0x58;
                        }
                        if ((u8)(base + 0x20) < *(u8 *)(entry + 0x37)) {
                            *(u8 *)(entry + 0x37) = (u8)(*(u8 *)(entry + 0x37) - 0x20);
                        } else {
                            *(u8 *)(entry + 0x37) = base;
                        }
                        *(s32 *)(entry + 0x98) |= 4;
                    }
                }
                if (*(u16 *)(entry + 0x4C) > 0) {
                    f32 ft;
                    f32 fdiv;
                    f32 f1;
                    s32 b48;
                    s32 b49;
                    s32 b4a;
                    ft = (f32)*(u16 *)(entry + 0x4C);
                    fdiv = ft / 8.0f;
                    b48 = *(u8 *)(entry + 0x48);
                    f1 = fdiv * (f32)(s32)((s32)*(u8 *)(entry + 0x44) - (s32)b48);
                    *(u8 *)(entry + 0x40) = (u8)((u32)b48 + (u32)f1);
                    b49 = *(u8 *)(entry + 0x49);
                    f1 = fdiv * (f32)(s32)((s32)*(u8 *)(entry + 0x45) - (s32)b49);
                    *(u8 *)(entry + 0x41) = (u8)((u32)b49 + (u32)f1);
                    b4a = *(u8 *)(entry + 0x4A);
                    f1 = fdiv * (f32)(s32)((s32)*(u8 *)(entry + 0x46) - (s32)b4a);
                    *(u8 *)(entry + 0x42) = (u8)((u32)b4a + (u32)f1);
                    *(s32 *)(entry + 0x98) |= 4;
                    *(u16 *)(entry + 0x4C) = (u16)(*(u16 *)(entry + 0x4C) - 1);
                }
                if ((*(s32 *)(entry + 0x98) & 4) != 0) {
                    f32 f14 = *(f32 *)(entry + 0x1C);
                    f32 f15 = *(f32 *)(entry + 0x20);
                    f32 f12 = *(f32 *)(entry + 0x24);
                    f32 f13 = *(f32 *)(entry + 0x28);
                    f32 xx = f14 * f14;
                    f32 yy = f15 * f15;
                    f32 zz = f12 * f12;
                    f32 yz = f15 * f12;
                    f32 zx = f12 * f14;
                    f32 xy = f14 * f15;
                    f32 wx = f13 * f14;
                    f32 wy = f13 * f15;
                    f32 wz = f13 * f12;
                    f32 m[9];
                    s32 z[3];
                    s32 poly;
                    f32 sp[3];
                    u8 col[4];
                    m[0] = 1.0f - (yy + zz) * 2.0f;
                    m[1] = (xy + wz) * 2.0f;
                    m[2] = (zx - wy) * 2.0f;
                    m[3] = (xy - wz) * 2.0f;
                    m[4] = 1.0f - (xx + zz) * 2.0f;
                    m[5] = (yz + wx) * 2.0f;
                    m[6] = (zx + wy) * 2.0f;
                    m[7] = (yz - wx) * 2.0f;
                    m[8] = 1.0f - (xx + yy) * 2.0f;
                    z[0] = 0;
                    z[1] = 0;
                    z[2] = 0;
                    poly = 3;
                    func_0047a1c0(*(u8 **)(entry + 0xA00), m, 0);
                    sp[0] = sp[1] = sp[2] = *(f32 *)(entry + 0x2C);
                    mdlScale(*(u8 **)(entry + 0xA00), sp, 2);
                    sp[0] = *(f32 *)(entry + 4) + *(f32 *)(entry + 0x10);
                    sp[1] = *(f32 *)(entry + 8) + *(f32 *)(entry + 0x14);
                    sp[2] = *(f32 *)(entry + 0xC) + *(f32 *)(entry + 0x18);
                    func_0047a180(*(u8 **)(entry + 0xA00), sp, 2);
                    {
                        f32 a0 = (f32)*(u8 *)(entry + 0x30);
                        f32 a1 = (f32)*(u8 *)(entry + 0x31);
                        f32 a2 = (f32)*(u8 *)(entry + 0x32);
                        f32 a3 = (f32)*(u8 *)(entry + 0x33);
                        f32 b0 = (f32)*(u8 *)(entry + 0x34);
                        f32 b1 = (f32)*(u8 *)(entry + 0x35);
                        f32 b2 = (f32)*(u8 *)(entry + 0x36);
                        f32 b3 = (f32)*(u8 *)(entry + 0x37);
                        f32 c0 = (f32)*(u8 *)(entry + 0x3C);
                        f32 c1 = (f32)*(u8 *)(entry + 0x3D);
                        f32 c2 = (f32)*(u8 *)(entry + 0x3E);
                        f32 c3 = (f32)*(u8 *)(entry + 0x3F);
                        f32 d0 = (f32)*(u8 *)(entry + 0x40);
                        f32 d1 = (f32)*(u8 *)(entry + 0x41);
                        f32 d2 = (f32)*(u8 *)(entry + 0x42);
                        f32 d3 = (f32)*(u8 *)(entry + 0x43);
                        s64 t0 = ((s32)(inv * a0 * inv * b0 * 255.0f + 0.5f)) & 0xFF;
                        s64 t1 = ((s32)(inv * a1 * inv * b1 * 255.0f + 0.5f)) & 0xFF;
                        s64 t2 = ((s32)(inv * a2 * inv * b2 * 255.0f + 0.5f)) & 0xFF;
                        s64 t3 = ((s32)(inv * a3 * inv * b3 * 255.0f + 0.5f)) & 0xFF;
                        s64 u0 = ((s32)(inv * (f32)t0 * inv * c0 * 255.0f + 0.5f)) & 0xFF;
                        s64 u1 = ((s32)(inv * (f32)t1 * inv * c1 * 255.0f + 0.5f)) & 0xFF;
                        s64 u2 = ((s32)(inv * (f32)t2 * inv * c2 * 255.0f + 0.5f)) & 0xFF;
                        s64 u3 = ((s32)(inv * (f32)t3 * inv * c3 * 255.0f + 0.5f)) & 0xFF;
                        col[0] = (u8)(s32)(inv * (f32)u0 * inv * d0 * 255.0f + 0.5f);
                        col[1] = (u8)(s32)(inv * (f32)u1 * inv * d1 * 255.0f + 0.5f);
                        col[2] = (u8)(s32)(inv * (f32)u2 * inv * d2 * 255.0f + 0.5f);
                        col[3] = (u8)(s32)(inv * (f32)u3 * inv * d3 * 255.0f + 0.5f);
                    }
                    if (col[3] < 0xFE) {
                        if (i != 2) {
                            *(s32 *)(*(u8 **)(entry + 0xA00) + 0xE8) = 0x737FB;
                            func_0019d7a0(entry, 2);
                            func_0019d7a0(entry, 5);
                        }
                    } else {
                        col[3] = 0xFF;
                        *(s32 *)(*(u8 **)(entry + 0xA00) + 0xE8) = 0x737FB;
                        func_0019d990(entry, 2);
                        func_0019d990(entry, 5);
                    }
                    {
                        u8 *obj = *(u8 **)(entry + 0xA00);
                        if (*(s32 *)(obj + 0xE8) != 0x737FB) {
                            u32 j;
                            *(s32 *)(obj + 0xE8) = 0x737FB;
                            for (j = 0; j < 5U; j++) {
                                u8 *objR = *(u8 **)(entry + 0xA00);
                                u8 *sub = *(u8 **)(objR + (j * 0xC) + 0x290);
                                if (sub != NULL) {
                                    *(s32 *)(sub + 0xE8) = 0x737FB;
                                }
                            }
                        }
                    }
                    *(u8 *)(entry + 0x4E) = col[0];
                    *(u8 *)(entry + 0x4F) = col[1];
                    *(u8 *)(entry + 0x50) = col[2];
                    *(u8 *)(entry + 0x51) = col[3];
                    mdlSetColor(*(u8 **)(entry + 0xA00), (s32 *)col);
                    func_001ee490(entry);
                    *(s32 *)(entry + 0x98) &= ~4;
                }
                if ((*(s32 *)(*(u8 **)(entry + 0xA00) + 0xD8) & 4) != 0) {
                    func_00478e70(*(u8 **)(entry + 0xA00));
                }
                if ((*(s32 *)(entry + 0xA04) != 0) && (func_0019d130(entry) != 0)) {
                    u8 *p = *(u8 **)(entry + 0xA64);
                    if (p != NULL) {
                        s64 v41 = *(s32 *)(p + 0xC) & 0xFFFFF;
                        s64 chk = (s16)func_001d72e0((s32)v41);
                        s16 cur = func_001d7130(*(s32 *)(entry + 0xA04));
                        if (chk != (s64)cur) {
                            func_001d7400((s32)v41, entry + 0x48);
                            *(u8 *)(entry + 0x44) = *(u8 *)(entry + 0x40);
                            *(u8 *)(entry + 0x45) = *(u8 *)(entry + 0x41);
                            *(u8 *)(entry + 0x46) = *(u8 *)(entry + 0x42);
                            *(u8 *)(entry + 0x47) = *(u8 *)(entry + 0x43);
                            *(u16 *)(entry + 0x4C) = 8;
                            func_001d7100(*(u8 **)(entry + 0xA04), (s16)chk);
                        }
                    }
                    func_001d72c0(*(u8 **)(entry + 0xA04), *(u32 *)(entry + 0x4E));
                    func_001d7140(*(u8 **)(entry + 0xA04));
                }
            }
            entry = *(u8 **)(entry + 0xA68);
        }
        i += 1;
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019c0d0);
#endif
// FUN_0019CFB0
void func_0019cfb0(void) {
    u32 i;
    u8 *entry;

    i = 0;
    goto loop_7;
loop_5:
    entry = *(u8 **)(D_0076449C + (i * 8) + 0x17C);
    goto loop_check;
loop_body:
    if (*(s32 *)(entry + 0x98) & 2) {
        func_0019db40(entry);
    }
    entry = *(u8 **)(entry + 0xA68);
loop_check:
    if (entry != NULL) {
        goto loop_body;
    }
    i += 1;
loop_7:
    if (i < 4U) {
        goto loop_5;
    }
}
// FUN_0019D040
void func_0019d040(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) &= ~0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 1);
        *(s32 *)(arg0 + 0x9C) &= ~2;
        return;
    }
    *(s32 *)(arg0 + 0x9C) |= 2;
}



// FUN_0019D0C0
void func_0019d0c0(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) |= 0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 0);
    }
    *(s32 *)(arg0 + 0x9C) &= ~2;
}

// FUN_0019D150
void func_0019d150(void)
{
    u8 *temp;
    u8 *node;
    u32 i;

    for (i = 0; i < 4; i++) {
        node = *(u8 **)(iGpffffb3ac + i * 8 + 0x17C);
        while (node != NULL) {
            if ((*(s32 *)(node + 0x98) & 2) != 0 &&
                (*(s32 *)(node + 0x9C) & 2) != 0 &&
                *(u8 *)(node + 0x33) > 0) {
                temp = *(u8 **)(node + 0xA00);
                if ((*(s32 *)(temp + 0xD8) & 0x20) == 0) {
                    func_00479100(D_00794150, temp);
                }
            }
            node = *(u8 **)(node + 0xA68);
        }
    }
}
// FUN_0019D210
u8 *func_0019d210(s32 arg0)
{
    f32 var_f1;
    s32 temp_3_2;
    s32 temp_4;
    u32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    func_0044ea90(D_005F6D10, 0x3A);
    temp_2 = (u8 *)D_008873E8[0](0xA70, 0x40000);
    memset(temp_2, 0, 0xA70);
    *(u8 *)(temp_2 + 0xA2) = arg0;
    if (iGpffffa0a8 >= 0x0FFFFFFFU) {
        iGpffffa0a8 = 1;
    }
    temp_3 = iGpffffa0a8;
    iGpffffa0a8 = temp_3 + 1;
    *(u32 *)(temp_2 + 0xA8) = temp_3;
    func_00194dc0(temp_2);
    *(f32 *)(temp_2 + 0x8C) = 150.0f;
    *(s32 *)(temp_2 + 0x90) = 0x42480000;
    *(s32 *)(temp_2 + 0x80) = 0;
    *(f32 *)(temp_2 + 0x84) = 0.5f * *(f32 *)(temp_2 + 0x8C);
    *(s32 *)(temp_2 + 0x88) = 0;
    *(s16 *)(temp_2 + 0xC8) = 0;
    *(s32 *)(temp_2 + 0xCC) = 0x41D80000;
    if (*(u8 *)(temp_2 + 0xA2) == 0) {
        var_f1 = 10.0f;
    } else {
        var_f1 = 14.0f;
    }
    *(f32 *)(temp_2 + 0x4F4) = 0.5f * var_f1;
    *(s32 *)(temp_2 + 0x9E0) = 0x3F800000;
    *(s8 *)(temp_2 + 0x9FC) = -1;
    *(s32 *)(temp_2 + 0xA04) = func_001d6f20(temp_2);
    *(s32 *)(temp_2 + 0xA08) = func_001d6ad0();
    *(s32 *)(temp_2 + 0xA68) = 0;
    temp_4 = (arg0 & 0xFF) * 8;
    temp_3_2 = (s32)iGpffffb3ac;
    temp_2_2 = *(u8 **)((u8 *)p4_entries_001900a0(
        0x178, (s32 *)temp_3_2) + temp_4);
    if (temp_2_2 != NULL) {
        *(u8 **)(temp_2_2 + 0xA68) = temp_2;
        *(u8 **)(temp_2 + 0xA6C) =
            *(u8 **)((u8 *)p4_base_add_00194590(
                temp_4, (s32)iGpffffb3ac) + 0x178);
    } else {
        *(u8 **)((u8 *)p4_base_add_00194590(
            temp_4, temp_3_2) + 0x17C) = temp_2;
        *(u8 **)(temp_2 + 0xA6C) = NULL;
    }
    *(u8 **)((u8 *)p4_base_add_00194590(
        temp_4, (s32)iGpffffb3ac) + 0x178) = temp_2;
    return temp_2;
}
// FUN_0019D3C0
void func_0019d3c0(arg0)
u8 *arg0;
{
    u16 temp_4;
    s32 index;
    u8 *temp_4_2;

    temp_4 = *(u16 *)(arg0 + 0x9FE);
    if (temp_4 != 0) {
        index = ((s32)temp_4 & 0xFFC00) >> 10;
        func_00146630(temp_4);
        if (*(u8 **)(arg0 + 0xA00) != NULL) {
            func_0019d990(arg0, 4);
            func_0019d990(arg0, 1);
            func_0019d990(arg0, 2);
            func_0019d990(arg0, 3);
            mdlSetColor(*(u8 **)(arg0 + 0xA00), (s32 *)&iGpffffa4d8);
            func_0047a0e0(*(u8 **)(arg0 + 0xA00), 0, 1.0f);
            if (index == 1 && (*(s32 *)(arg0 + 0x98) & 8) == 0)
                func_004787e0(*(u8 **)(arg0 + 0xA00));
        }
        *(u16 *)(arg0 + 0x9FE) = 0;
    } else {
        temp_4_2 = *(u8 **)(arg0 + 0xA00);
        if (temp_4_2 != NULL)
            func_004787e0(temp_4_2);
    }
    *(u8 **)(arg0 + 0xA00) = NULL;
    *(s32 *)(arg0 + 0x98) &= ~2;
}
// FUN_0019D4E0
void func_0019d4e0(u8 *arg0)
{
    u8 *node;
    s32 h;

    func_0019d3c0();
    node = *(u8 **)(arg0 + 0xA0C);
    if (node != NULL) {
        func_0019d550(node);
    }
    h = ((s32 *)arg0)[641];
    if (h != 0) {
        func_001d7040(h);
        *(s32 *)(arg0 + 0xA04) = 0;
    }
    h = ((s32 *)arg0)[642];
    if (h != 0) {
        func_001d6c10(h);
        *(s32 *)(arg0 + 0xA08) = 0;
    }
}

// FUN_0019D550
void func_0019d550(u8 *arg0)
{
    u8 *temp_17;
    u8 temp_16;
    s32 temp_4_2;
    s32 temp_4_3;
    s8 temp_5;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4;

    temp_17 = arg0;
    temp_16 = *(u8 *)(arg0 + 0xA2);
    func_0019d3c0();
    temp_4 = *(u8 **)(temp_17 + 0xA0C);
    if (temp_4 != NULL)
        func_0019d550(temp_4);
    temp_4_2 = *(s32 *)(temp_17 + 0xA04);
    if (temp_4_2 != 0) {
        func_001d7040(temp_4_2);
        *(s32 *)(temp_17 + 0xA04) = 0;
    }
    temp_4_3 = *(s32 *)(temp_17 + 0xA08);
    if (temp_4_3 != 0) {
        func_001d6c10(temp_4_3);
        *(s32 *)(temp_17 + 0xA08) = 0;
    }
    func_001ee430(temp_17);
    temp_5 = *(s8 *)(temp_17 + 0x9FC);
    if (temp_5 >= 0)
        func_001d1540(temp_17, temp_5, 0);
    temp_3 = *(u8 **)(temp_17 + 0xA6C);
    if (temp_3 != NULL)
        *(u8 **)(temp_3 + 0xA68) = *(u8 **)(temp_17 + 0xA68);
    else
        p4_d550_store(*(u8 **)(temp_17 + 0xA68), iGpffffb3ac,
                      (u32)temp_16 & 0xFF, 0x17C);
    temp_3_2 = *(u8 **)(temp_17 + 0xA68);
    if (temp_3_2 != NULL)
        *(u8 **)(temp_3_2 + 0xA6C) = *(u8 **)(temp_17 + 0xA6C);
    else
        p4_d550_store(*(u8 **)(temp_17 + 0xA6C), iGpffffb3ac,
                      (u32)temp_16 & 0xFF, 0x178);
    jtbl_008873EC[0](temp_17);
}
// FUN_0019D670
void func_0019d670(void)
{
    u8 *unit;
    u8 *next;
    u32 i;
    u8 *linked;
    u8 *linked2;
    u8 unitType;
    s8 status;

    for (i = 0; i < 4; i++) {
        unit = *(u8 **)(iGpffffb3ac + (i * 8) + 0x178);
        while (unit != NULL) {
            next = *(u8 **)(unit + 0xA6C);
            unitType = *(u8 *)(unit + 0xA2);
            func_0019d4e0(unit);
            func_001ee430(unit);
            status = *(s8 *)(unit + 0x9FC);
            if (status >= 0)
                func_001d1540(unit, status, 0);
            linked = *(u8 **)(unit + 0xA6C);
            if (linked != NULL)
                *(u8 **)(linked + 0xA68) = *(u8 **)(unit + 0xA68);
            else
                *(u8 **)(iGpffffb3ac + ((unitType & 0xFF) * 8) + 0x17C) =
                    *(u8 **)(unit + 0xA68);
            linked2 = *(u8 **)(unit + 0xA68);
            if (linked2 != NULL)
                *(u8 **)(linked2 + 0xA6C) = *(u8 **)(unit + 0xA6C);
            else
                *(u8 **)(iGpffffb3ac + ((unitType & 0xFF) * 8) + 0x178) =
                    *(u8 **)(unit + 0xA6C);
            jtbl_008873EC[0](unit);
            unit = next;
        }
    }
}
/* measured: plain-C switch reconstruction reproduces the 488-byte object against the 496-byte retail window; the jump-table base register remains the residual. Committed at nd 61. */
// FUN_0019D7A0
void func_0019d7a0(u8 *arg0, s32 arg1)
{
    s32 temp_4;
    u16 temp_5;
    u16 temp_3;
    u8 *temp_2;
    u8 *temp_3_2;
    u8 *temp_4_2;
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
        temp_3 = (u16)arg1;
        switch (temp_3) {
        case 6:
            temp_5 = *(u16 *)(arg0 + 0x9FE);
            if ((temp_5 != 0) &&
                (((s32)(temp_5 & 0xFFC00) >> 10) == 1)) {
                temp_2 = func_00147530(*(u8 **)(iGpffff9db0 + 8), temp_5);
                *(s32 *)(temp_2 + 0x22C) = 0x34;
                *(s32 *)(temp_2 + 0x28) |= 0x04000000;
                return;
            }
            break;
        case 1:
            temp_4 = *(s32 *)(iGpffffb3ac + 0x10);
            if (((temp_4 & 0x100) == 0) ||
                (*(u8 *)(arg0 + 0xA2) != 0)) {
                if (((temp_4 & 0x200) == 0) ||
                    (*(u8 *)(arg0 + 0xA2) != 1)) {
                    func_0047a810(*(u8 **)(arg0 + 0xA00));
                    *(u8 **)(*(u8 **)(arg0 + 0xA00) + 0x2F8) =
                        D_007940F0;
                    *(f32 *)(*(u8 **)(arg0 + 0xA00) + 0x274) =
                        fGpffff80fc;
                    temp_3_2 = *(u8 **)(arg0 + 0xA00);
                    *(f32 *)(temp_3_2 + 0x278) =
                        *(f32 *)(temp_3_2 + 0x274);
                    *(s32 *)(*(u8 **)(arg0 + 0xA00) + 0x27C) =
                        0x3F800000;
                    return;
                }
            }
            break;
        case 2:
            func_0047a850(*(u8 **)(arg0 + 0xA00));
            return;
        case 3:
            func_0047a9f0(*(u8 **)(arg0 + 0xA00),
                          (u16)((func_0047aa00(*(u8 **)(arg0 + 0xA00)) &
                                 0xFFFF) | 0x1000));
            func_0047a9f0(*(u8 **)(arg0 + 0xA00),
                          (u16)((func_0047aa00(*(u8 **)(arg0 + 0xA00)) &
                                 0xFFFF) | 0x2000));
            temp_4 = func_0047aa00(*(u8 **)(arg0 + 0xA00)) & 0xFFFF;
            temp_4 = temp_4 & -0x801;
            func_0047a9f0(*(u8 **)(arg0 + 0xA00), (u16)temp_4);
            return;
        case 4:
            *(s32 *)(*(u8 **)(arg0 + 0xA00) + 0x2DC) =
                (s32)func_001f7650(arg0);
            temp_4_2 = *(u8 **)(arg0 + 0xA00);
            *(u16 *)(temp_4_2 + 0x2E0) |= 0x10;
            break;
        case 0:
        case 5:
            break;
        }
    }
}
// FUN_0019D990
void func_0019d990(u8 *arg0, s32 arg1)
{
    s32 temp_4;
    u16 temp_5;
    u32 temp_3;
    u8 *temp_2;
    u8 *temp_4_2;
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
        temp_3 = (u32)arg1 & 0xFFFF;
        switch (temp_3) {
        case 6:
            temp_5 = *(u16 *)(arg0 + 0x9FE);
            if ((temp_5 != 0) &&
                (((s32)(temp_5 & 0xFFC00) >> 10) == 1)) {
                temp_2 = func_00147530(*(u8 **)(iGpffff9db0 + 8), temp_5);
                *(s32 *)(temp_2 + 0x28) &= 0xFBFFFFFF;
                return;
            }
            break;
        case 1:
            func_0047a830(*(u8 **)(arg0 + 0xA00));
            temp_4_2 = *(u8 **)(arg0 + 0xA00);
            *(u8 *)(temp_4_2 + 0x260) &= 0xE2;
            return;
        case 2:
            func_0047a870(*(u8 **)(arg0 + 0xA00));
            return;
        case 3:
            func_0047a890(*(u8 **)(arg0 + 0xA00), DAT_0076112c);
            func_0047a8a0(*(u8 **)(arg0 + 0xA00), 70.0f, 80.0f);
            func_0047a9b0(*(u8 **)(arg0 + 0xA00));
            func_0047a990(*(u8 **)(arg0 + 0xA00));
            temp_4 = func_0047aa00(*(u8 **)(arg0 + 0xA00)) & 0xFFFF;
            temp_4 = temp_4 & -0x2001;
            func_0047a9f0(*(u8 **)(arg0 + 0xA00), (u16)temp_4);
            temp_4 = func_0047aa00(*(u8 **)(arg0 + 0xA00)) & 0xFFFF;
            temp_4 = temp_4 & -0x1001;
            func_0047a9f0(*(u8 **)(arg0 + 0xA00), (u16)temp_4);
            *(s16 *)(arg0 + 0xB0) = 0;
            return;
        case 4:
            temp_4_2 = *(u8 **)(arg0 + 0xA00);
            *(u16 *)(temp_4_2 + 0x2E0) &= 0xFFEF;
            *(s32 *)(*(u8 **)(arg0 + 0xA00) + 0x2DC) = 0;
            break;
        case 0:
        case 5:
            break;
        }
    }
}
// FUN_0019DB40
/* measured: object 812B/window 816B, nd 0. The mode dispatch is an explicit goto
   chain (`== 0x11` -> case11, `!= 0` -> def, fall to case0; a switch sorts the
   zero test first and drops the `b default`). func_00232710 is called with two
   arguments through an unprototyped block-scope extern; func_0019efe0 needs its
   real prototype at block scope (it is defined later in the unit). The scale
   multiplies are inline `*(f32 *)(target + 0x80) * *(f32 *)(target + 0x2C)` so the
   0x80 load precedes the 0x2C load. */
void func_0019db40(u8 *arg0)
{
    extern void func_0047a8b0(void *arg0, void *arg1);
    extern s32 func_0047a6d0(void *arg0, s32 arg1, void *arg2);
    extern f32 DAT_007613f8;
    extern u8 *func_0019efe0(s32 arg0);
    P4_95730_Vec3 pos;
    P4_95730_Vec3 scaled;
    P4_95730_Vec3 rotated;
    P4_95730_Vec3 scaled2;
    P4_95730_Vec3 rotated2;
    s16 mode;
    u8 *target;

    if (*(s32 *)(arg0 + 0x98) & 2) {
        if (*(s32 *)(arg0 + 0x98) & 2) {
            mode = *(s16 *)(arg0 + 0x9DA);
        } else {
            mode = 0;
        }
        if (mode == 0x11) {
            goto case11;
        }
        if (mode != 0) {
            goto def;
        }
        goto case0;
    case11:
        if (func_0047a9d0(*(u8 **)(arg0 + 0xA00)) != 0) {
            func_0047a990(*(u8 **)(arg0 + 0xA00));
        }
        return;
    def:
        if (func_0047a9d0(*(u8 **)(arg0 + 0xA00)) != 0) {
            func_0047a9b0(*(u8 **)(arg0 + 0xA00));
            func_0047a990(*(u8 **)(arg0 + 0xA00));
        }
        return;
    case0:
            if (*(s32 *)(arg0 + 0xA64) != 0 && datCalcChkBadStatus(*(s32 *)(arg0 + 0xA64), 0x100) != 0) {
                if (func_0047a9d0(*(u8 **)(arg0 + 0xA00)) != 0) {
                    func_0047a990(*(u8 **)(arg0 + 0xA00));
                }
                return;
            }
            if (*(u16 *)(arg0 + 0xB0) != 0 && !(*(f32 *)(*(u8 **)(arg0 + 0xA00) + 0x108) < 1.0f) && !(func_0047aa00(*(u8 **)(arg0 + 0xA00)) & 0x200)) {
                switch (*(u16 *)(arg0 + 0xB0)) {
                case 1:
                    func_0047a8b0(*(u8 **)(arg0 + 0xA00), arg0 + 0xB8);
                    return;
                case 2:
                    if (*(s32 *)(arg0 + 0xB4) != 0) {
                        target = func_0019efe0(*(s32 *)(arg0 + 0xB4) & 0xFFFF);
                        if (target != NULL && target != arg0) {
                            if (!(*(s32 *)(target + 0x98) & 2)) {
                                scaled.x = *(f32 *)(target + 0x80) * *(f32 *)(target + 0x2C);
                                scaled.y = *(f32 *)(target + 0x84) * *(f32 *)(target + 0x2C);
                                scaled.z = *(f32 *)(target + 0x88) * *(f32 *)(target + 0x2C);
                                RtQuatTransformVectors(&rotated, &scaled, 1, target + 0x1C);
                                pos.x = rotated.x + *(f32 *)(target + 4);
                                pos.y = rotated.y + *(f32 *)(target + 8);
                                pos.z = rotated.z + *(f32 *)(target + 0xC);
                            } else if (func_0047a6d0(*(u8 **)(target + 0xA00), 0, &pos) == 0) {
                                scaled2.x = *(f32 *)(target + 0x80) * *(f32 *)(target + 0x2C);
                                scaled2.y = *(f32 *)(target + 0x84) * *(f32 *)(target + 0x2C);
                                scaled2.z = *(f32 *)(target + 0x88) * *(f32 *)(target + 0x2C);
                                RtQuatTransformVectors(&rotated2, &scaled2, 1, target + 0x1C);
                                pos.x = rotated2.x + *(f32 *)(target + 4);
                                pos.y = rotated2.y + *(f32 *)(target + 8);
                                pos.z = rotated2.z + *(f32 *)(target + 0xC);
                            }
                            pos.y += *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C) * DAT_007613f8;
                            func_0047a8b0(*(u8 **)(arg0 + 0xA00), &pos);
                            return;
                        }
                        func_0047a990(*(u8 **)(arg0 + 0xA00));
                        *(s32 *)(arg0 + 0xB4) = 0;
                    }
                    break;
                }
            }
    }
}
// FUN_0019DEA0
void func_0019dea0(u8 *arg0)
{
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
        if (func_0047a9d0(*(u8 **)(arg0 + 0xA00)) != 0) {
            func_0047a9b0(*(u8 **)(arg0 + 0xA00));
            func_0047a990(*(u8 **)(arg0 + 0xA00));
        }
    }
}

// FUN_0019DF00
void func_0019df00(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) + 1;
    }
}
/* measured: opt_propagation off plus named call_angle locals preserve retail's stack reloads before func_0047a8a0. */
#pragma push
#pragma opt_propagation off
// FUN_0019DF20
s32 func_0019df20(u8 *arg0)
{
    u8 *unit;

    if ((*(u16 *)(arg0 + 0x10) & 1) != 0) {
        f32 angle1;
        f32 angle2;
        f32 call_angle1;
        f32 call_angle2;
        s32 enabled;

        unit = *(u8 **)(iGpffffb3ac + 0x17C);
        while (unit != NULL) {
            if ((*(s32 *)(unit + 0x9C) & 8) != 0) {
                if (&angle1 != NULL) {
                    angle1 = 70.0f;
                }
                if (&angle2 != NULL) {
                    angle2 =
                        (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) ==
                         unit) ? 70.0f : 60.0f;
                }
                call_angle2 = angle2;
                call_angle1 = angle1;
                enabled = *(s32 *)(unit + 0x98) & 2;
                if (enabled != 0) {
                    func_0047a8a0(*(u8 **)(unit + 0xA00),
                                   call_angle1, call_angle2);
                }
                if ((*(s32 *)(unit + 0x98) & 2) != 0) {
                    func_0047a890(*(u8 **)(unit + 0xA00), 0.25f);
                }
                *(s16 *)(unit + 0xB0) = 1;
                *(P4_95730_Vec3 *)(unit + 0xB8) =
                    *(P4_95730_Vec3 *)(arg0 + 4);
                func_0019d7a0(unit, 3);
            }
            unit = *(u8 **)(unit + 0xA68);
        }
    } else {
        f32 angle1;
        f32 angle2;
        f32 call_angle1;
        f32 call_angle2;
        s32 enabled;

        unit = *(u8 **)arg0;
        if (&angle1 != NULL) {
            angle1 = 70.0f;
        }
        if (&angle2 != NULL) {
            angle2 =
                (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) == unit) ?
                70.0f : 60.0f;
        }
        call_angle2 = angle2;
        call_angle1 = angle1;
        enabled = *(s32 *)(unit + 0x98) & 2;
        if (enabled != 0) {
            func_0047a8a0(*(u8 **)(unit + 0xA00),
                           call_angle1, call_angle2);
        }
        if ((*(s32 *)(unit + 0x98) & 2) != 0) {
            func_0047a890(*(u8 **)(unit + 0xA00), 0.25f);
        }
        *(s16 *)(unit + 0xB0) = 1;
        *(P4_95730_Vec3 *)(unit + 0xB8) =
            *(P4_95730_Vec3 *)(arg0 + 4);
        func_0019d7a0(unit, 3);
    }
    return 1;
}
/* measured: restore pragma state after func_0019df20. */
#pragma pop
// FUN_0019E130
void func_0019e130(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) - 1;
    }
}
// FUN_0019E830
void func_0019e830(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) + 1;
    }
}
// FUN_0019E850
s32 func_0019e850(u8 *arg0)
{
    u16 temp_3;
    u8 *temp_16;
    u8 *var_16;
    u8 *var_16_2;

    temp_3 = *(u16 *)(arg0 + 4);
    if (temp_3 & 3) {
        if (temp_3 & 1) {
            var_16 = *(u8 **)(D_0076449C + 0x17C);
            while (var_16 != NULL) {
                if (((*(s32 *)(var_16 + 0x9C) & 8) != 0) &&
                    ((*(s32 *)(var_16 + 0x98) & 2) != 0) &&
                    (func_0047a9d0(*(u8 **)(var_16 + 0xA00)) != 0)) {
                    func_0047a9b0(*(u8 **)(var_16 + 0xA00));
                    func_0047a990(*(u8 **)(var_16 + 0xA00));
                }
                var_16 = *(u8 **)(var_16 + 0xA68);
            }
        }
        if ((*(u16 *)(arg0 + 4) & 2) != 0) {
            var_16_2 = *(u8 **)(D_0076449C + 0x184);
            while (var_16_2 != NULL) {
                if (((*(s32 *)(var_16_2 + 0x9C) & 8) != 0) &&
                    ((*(s32 *)(var_16_2 + 0x98) & 2) != 0) &&
                    (func_0047a9d0(*(u8 **)(var_16_2 + 0xA00)) != 0)) {
                    func_0047a9b0(*(u8 **)(var_16_2 + 0xA00));
                    func_0047a990(*(u8 **)(var_16_2 + 0xA00));
                }
                var_16_2 = *(u8 **)(var_16_2 + 0xA68);
            }
        }
    } else {
        temp_16 = *(u8 **)arg0;
        if (((*(s32 *)(temp_16 + 0x98) & 2) != 0) &&
            (func_0047a9d0(*(u8 **)(temp_16 + 0xA00)) != 0)) {
            func_0047a9b0(*(u8 **)(temp_16 + 0xA00));
            func_0047a990(*(u8 **)(temp_16 + 0xA00));
        }
    }
    return 1;
}
// FUN_0019E9D0
void func_0019e9d0(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) - 1;
    }
}
// FUN_0019E9F0
u8 *func_0019e9f0(u8 *unit, s16 value)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)func_00194470(0x11A, 8);
    *(void **)(packet + 0x68) = (void *)func_0019e830;
    *(void **)(packet + 0x6C) = (void *)func_0019e850;
    *(void **)(packet + 0x70) = (void *)func_0019e9d0;
    work = *(u8 **)(packet + 0x78);
    *(u8 **)work = unit;
    *(s16 *)(work + 4) = value;

    return packet;
}

// FUN_0019EA60
void func_0019ea60(u8 *arg0, s32 arg1)
{
    extern void func_00201280(u8 *arg0, u8 *arg1);
    u8 *data;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    u16 temp_6;
    s32 temp_4_2;
    s32 temp_4_4;
    s32 temp_4_5;
    u16 temp_2;
    u16 temp_2_2;
    u16 temp_2_3;
    u16 temp_2_4;
    u16 temp_3;
    u8 temp_4;
    u8 *temp_4_3;

    temp_6 = arg1 & 0xFFFF;
    *(u16 *)(arg0 + 0xA4) = arg1;
    temp_4 = *(u8 *)(arg0 + 0xA2);
    switch (temp_4) {
    case 0:
        *(s16 *)(*(u8 **)(arg0 + 0xA64) + 2) = temp_6;
        func_00231af0((DatUnit *)*(u8 **)(arg0 + 0xA64), 0, temp_6);
        temp_4_2 = arg1 * 0x14C;
        temp_2 = *(u16 *)((u8 *)((u32)temp_4_2 + (u32)iGpffffb3c0) + 0x14);
        var_f1 = (f32)(u32)temp_2;
        *(f32 *)(arg0 + 0x2C) = var_f1 / 100.0f;
        *(s32 *)(arg0 + 0x98) |= 4;
        data = iGpffffb3c0 + temp_4_2;
        *(u8 **)(arg0 + 0x9F8) = iGpffffb3c0 + temp_4_2 + 0x3C;
        *(s16 *)(arg0 + 0x9E4) = 0x1B;
        if ((u32)(arg1 - 3) < 3U) {
            temp_4_3 = *(u8 **)(arg0 + 0xA64);
            *(u16 *)(temp_4_3 + 0) |= 0x1000;
        }
        break;
    case 1:
        *(s16 *)(*(u8 **)(arg0 + 0xA64) + 2) = temp_6;
        temp_4_4 = arg1 * 0xE8;
        temp_2_2 = *(u16 *)((u8 *)((u32)temp_4_4 + (u32)iGpffffb3cc) + 0x14);
        var_f1_2 = (f32)(u32)temp_2_2;
        *(f32 *)(arg0 + 0x2C) = var_f1_2 / 100.0f;
        *(s32 *)(arg0 + 0x98) |= 4;
        data = iGpffffb3cc + temp_4_4;
        *(u8 **)(arg0 + 0x9F8) = iGpffffb3cc + temp_4_4 + 0x2A;
        *(s16 *)(arg0 + 0x9E4) = 0x13;
        break;
    case 2:
        temp_4_5 = arg1 * 0x58;
        temp_2_3 = *(u16 *)((u8 *)((u32)temp_4_5 + (u32)iGpffffb3e0) + 0x18);
        var_f1_3 = (f32)(u32)temp_2_3;
        *(f32 *)(arg0 + 0x2C) = var_f1_3 / 100.0f;
        *(s32 *)(arg0 + 0x98) |= 4;
        data = iGpffffb3e0 + temp_4_5 + 2;
        *(u8 **)(arg0 + 0x9F8) = iGpffffb3e0 + temp_4_5 + 0x1A;
        *(s16 *)(arg0 + 0x9E4) = 6;
        break;
    case 3:
    default:
        break;
    }
    *(f32 *)(arg0 + 0x80) = (f32)(s16)*(s16 *)(data + 0);
    *(f32 *)(arg0 + 0x84) = (f32)(s16)*(s16 *)(data + 2);
    *(f32 *)(arg0 + 0x88) = (f32)(s16)*(s16 *)(data + 4);
    temp_3 = *(u16 *)(data + 6);
    var_f0 = (f32)(u32)temp_3;
    *(f32 *)(arg0 + 0x8C) = var_f0;
    temp_2_4 = *(u16 *)(data + 8);
    var_f0_2 = (f32)(u32)temp_2_4;
    *(f32 *)(arg0 + 0x90) = var_f0_2;
    func_00201280(arg0, arg0 + 0xA10);
}
// FUN_0019EDA0
u8 *func_0019eda0(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_3;
    u8 *var_2;
    u8 *var_2_2;
    s32 var_4;
    s32 flags;

    temp_16 = *(u16 *)(arg0 + 0xA4);
    temp_3 = arg1 & 0xFFFF;
    switch (temp_3) {
    case 9:
    case 10:
        var_4 = 1;
        break;
    case 2:
        flags = *(s32 *)(arg0 + 0xA64);
        if ((flags != 0) && (datCalcChkBadStatus(flags, 0x100000) != 0)) {
            var_4 = 1;
            break;
        }
    default:
        var_4 = 0;
    }
    switch (*(u8 *)(arg0 + 0xA2)) {
    case 0:
        if (var_4 != 0) {
            var_2 = iGpffffb3c0 + temp_16 * 0x14C + 0xA;
        } else {
            var_2 = iGpffffb3c0 + temp_16 * 0x14C;
        }
        return var_2;
    case 1:
        if (var_4 != 0) {
            var_2_2 = iGpffffb3cc + temp_16 * 0xE8 + 0xA;
        } else {
            var_2_2 = iGpffffb3cc + temp_16 * 0xE8;
        }
        return var_2_2;
    case 2:
        return iGpffffb3e0 + temp_16 * 0x58 + 2;
    default:
        return NULL;
    }
}
// FUN_0019EF30
void func_0019ef30(u8 *arg0, u16 arg1) {
    extern void func_0019ea60(u8 *arg0, u16 arg1);
    if (*(u8 **)(arg0 + 0xA0C) == NULL) {
        *(u8 **)(arg0 + 0xA0C) = func_0019d210(2);
    }
    func_0019ea60(*(u8 **)(arg0 + 0xA0C), arg1);
}

// FUN_0019EF90
/* measured: opt_propagation off reproduces ef90's retail address setup order. */
#pragma opt_propagation off
u8 *func_0019ef90(s32 arg0, s32 arg1)
{
    u8 *base;
    u8 *packet;
    u32 address;

    base = iGpffffb3ac;
    arg0 = (u16)arg0;
    address = (u32)p4_unit_00195530((u16)arg0 * 8, base) + 0x17C;
    packet = *(u8 **)address;
    arg1 = (u16)arg1;
    while (packet != NULL) {
        if (*(u16 *)(packet + 0xA4) == arg1) {
            return packet;
        }
        packet = *(u8 **)(packet + 0xA68);
    }
    return NULL;
}
/* measured: closes opt_propagation around ef90. */
#pragma opt_propagation on
// FUN_0019EFE0
u8 *func_0019efe0(s32 arg0)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    arg0 = (u16)arg0;
    for (; i < 4; i++) {
        packet = *(u8 **)(btl + i * 8 + 0x17C);
        while (packet != NULL) {
            if (*(s32 *)(packet + 0xA8) == arg0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0xA68);
        }
    }
    return NULL;
}
// FUN_0019F050
s32 func_0019f050(u8 *arg0)
{
    u16 id;
    u8 type;
    s32 result;

    result = 0;
    id = *(u16 *)(arg0 + 0xA4);
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 0:
        result = func_0010d740((s16)id);
        break;
    case 1:
        result = p4_base_add_0019f050((u32)id * 0x15,
                                      (s32)iGpffffb444);
        break;
    case 2:
        result = func_00109220(id);
        break;
    default:
        break;
    }
    return result;
}
// FUN_0019F0F0
s32 func_0019f0f0(u8 *arg0)
{
    u16 id;
    u8 type;
    s32 result;

    result = 0;
    id = *(u16 *)(arg0 + 0xA4);
    type = *(u8 *)(arg0 + 0xA2);
    switch (type) {
    case 0:
        result = func_0010d6d0((s16)id);
        break;
    case 1:
    case 2:
        result = 0;
        switch (type) {
        case 0:
            result = func_0010d740((s16)id);
            break;
        case 1:
            result = p4_base_add_0019f050((u32)id * 0x15,
                                          (s32)iGpffffb444);
            break;
        case 2:
            result = func_00109220(id);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return result;
}

#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals off
#pragma opt_common_subs off
// FUN_0019F1D0
void func_0019f1d0(u8 *unit)
{
    extern u8 *iGpffffb3c4;
    u8 *resource;
    f32 radius;
    f32 height;
    f32 minRadius;
    f32 minHeight;
    f32 factor;
    f32 lower;
    f32 scale;
    f32 upper;
    f32 lowerHeight;
    f32 upperHeight;
    u16 band;
    s32 bound;

    if (*(u8 *)(unit + 0xA2) == 1) {
        resource = *(u8 **)(unit + 0xA64);
        if (resource != NULL &&
            (*(u16 *)(iGpffffb3c4 + *(u16 *)(resource + 2) * 0x3C) & 0x8000)) {
            return;
        }
    }

    scale = *(f32 *)(unit + 0x2C);
    radius = (f32)(s32)(*(f32 *)(unit + 0x90) * scale);
    height = (f32)(s32)(*(f32 *)(unit + 0x8C) * scale);
    lowerHeight = 200.0f;
    if (!(radius <= lowerHeight) || !(height <= 400.0f) ||
        radius < 50.0f || height < 100.0f) {
        return;
    }

    if (height <= lowerHeight) {
        if (radius <= 75.0f) {
            band = 0;
        } else if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= lowerHeight) {
            band = 2;
        }
    } else if (height <= 300.0f) {
        if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= lowerHeight) {
            band = 2;
        }
    } else {
        band = 2;
    }

    switch (band) {
    case 0:
        minRadius = 50.0f;
        minHeight = 100.0f;
        upper = 74.0f;
        lower = 199.0f;
        break;
    case 1:
        minRadius = 76.0f;
        minHeight = 201.0f;
        upper = 124.0f;
        bound = 299;
        lower = (f32)bound;
        break;
    case 2:
        minRadius = 126.0f;
        bound = 301;
        minHeight = (f32)bound;
        upper = 199.0f;
        bound = 399;
        lower = (f32)bound;
        break;
    }

    if (upper <= radius) goto upper_radius_one;
    upper = upper / radius;
    goto upper_radius_done;
upper_radius_one:
    upper = 1.0f;
upper_radius_done:
    if (lower <= height) goto upper_height_one;
    upperHeight = lower / height;
    goto upper_height_done;
upper_height_one:
    upperHeight = 1.0f;
upper_height_done:
    upper = upper < upperHeight ? upper : upperHeight;

    if (minRadius < radius) {
        lower = minRadius / radius;
    } else {
        lower = -1.0f;
    }
    if (minHeight < height) {
        lowerHeight = minHeight / height;
    } else {
        lowerHeight = -1.0f;
    }
    upperHeight = 0.0f;
    if (!(lower <= upperHeight) && !(lowerHeight <= upperHeight)) {
        lower = lower > lowerHeight ? lower : lowerHeight;
    } else {
        lower = 1.0f;
    }

    switch (*(u32 *)(unit + 0xA8) & 3) {
    case 0:
        factor = upper;
        break;
    case 1:
        factor = (0.0f + lower) + 0.5f * (upper - lower);
        break;
    case 2:
        factor = lower;
        break;
    case 3:
        factor = 1.0f;
        break;
    }
    *(f32 *)(unit + 0x2C) = factor * scale;
    *(u32 *)(unit + 0x98) |= 4;
}

#pragma pop
// FUN_0019F5F0
u8 *func_0019f5f0(s32 arg0, u16 arg1, u16 *arg2)
{
    s32 temp_16;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    u8 *temp_3;
    u8 *var_18;
    u8 *var_17;

    var_18 = NULL;
    temp_16 = arg0 & 0xFFFF;
    switch (temp_16) {
    case 0:
        var_17 = func_0019d210(0);
        var_18 = func_001b0930();
        btlActionSetUnit(var_18, var_17);
        func_001b0d70(var_18);
        func_001b08d0(var_18);
        btlActionSetState(var_18, 1);
        if ((arg1 & 0xFFFF) == 1) {
            *(s16 *)(var_18 + 0x14) = 5;
            *(u8 **)(iGpffffb3ac + 0x170) = var_18;
        }
        p4_call_0019ef30(*(u16 *)((u8 *)func_0010a900(arg1) + 2),
                         var_17);
        *(s32 *)(var_18 + 0x3F0) = func_0010f4f0((s16)arg1);
        *(u16 *)(var_18 + 0x1A) |= 0x10;
        break;
    case 1:
        var_17 = func_0019d210(1);
        var_18 = func_001b0930();
        btlActionSetUnit(var_18, var_17);
        func_001b0d70(var_18);
        func_001b08d0(var_18);
        btlActionSetState(var_18, 1);
        break;
    default:
        break;
    }
    if (arg2 != NULL) {
        *(u16 **)(var_17 + 0xA64) = arg2;
        func_0019ea60(var_17, (u16)(arg1 & 0xFFFF));
        if (temp_16 == 1 &&
            (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
            func_0019f1d0(var_17);
        }
        if (datCalcIsDead((u8 *)arg2, 0) != 0) {
            *(s32 *)(var_17 + 0x9C) |= 1;
        }
    }
    temp_3 = *(u8 **)(var_18 + 0x30);
    *(s32 *)(temp_3 + 0x9C) |= 8;
    *(u16 *)(var_18 + 0x1A) |= 8;
    switch (temp_16) {
    case 0:
        *(u16 *)(var_18 + 0x1A) |= 0x200;
        temp_2 = *(s32 *)(var_17 + 0x9C) | 0x20;
        *(s32 *)(var_17 + 0x9C) = temp_2;
        temp_2_2 = temp_2 | 0x40;
        *(s32 *)(var_17 + 0x9C) = temp_2_2;
        temp_2_3 = temp_2_2 | 0x80;
        *(s32 *)(var_17 + 0x9C) = temp_2_3;
        temp_2_4 = temp_2_3 | 0x200;
        *(s32 *)(var_17 + 0x9C) = temp_2_4;
        *(s32 *)(var_17 + 0x9C) = temp_2_4 | 0x4000;
        break;
    case 1:
        if (arg2 != NULL && func_00243d80((u8 *)arg2) != 0) {
            temp_2_5 = *(s32 *)(var_17 + 0x9C) | 0x20;
            *(s32 *)(var_17 + 0x9C) = temp_2_5;
            temp_2_6 = temp_2_5 | 0x100;
            *(s32 *)(var_17 + 0x9C) = temp_2_6;
            temp_2_7 = temp_2_6 | 0x40;
            *(s32 *)(var_17 + 0x9C) = temp_2_7;
            *(s32 *)(var_17 + 0x9C) = temp_2_7 | 0x400;
        }
        break;
    default:
        break;
    }
    func_0022e630(var_18);
    return var_18;
}
// FUN_0019F8A0
s32 func_0019f8a0(u8 *arg0)
{
    s32 temp_2;
    u16 *temp_4;

    if (*(s32 *)(arg0 + 0x24) < 0) {
        *(s32 *)(arg0 + 0x24) = (effMiscRand(0) % 240U) + 0x78;
    }
    temp_2 = *(s32 *)(arg0 + 0x24);
    if (temp_2 == 0) {
        if (func_00198840(*(u8 **)(arg0 + 0x30)) == 0) {
            return 0;
        }
        if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                          0x100000) != 0) {
            return 0;
        }
        if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                          0xFFFFF) != 0) {
            return 0;
        }
        temp_4 = *(u16 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        if ((*temp_4 & 0x200) != 0) {
            return 0;
        }
        if (datCalcIsLowHp((u8 *)temp_4) != 0 ||
            datCalcIsDead(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0) != 0) {
            return 0;
        }
        if ((s16)func_00199830(*(u8 **)(arg0 + 0x30)) < 4) {
            func_00194590(btlUnitCreateAnimPacket(*(u8 **)(arg0 + 0x30),
                                         0x11, 4, 0, 1.0f),
                          0);
            *(s32 *)(arg0 + 0x24) = -1;
        }
        return 1;
    }
    *(s32 *)(arg0 + 0x24) = temp_2 - 1;
    return 0;
}
// FUN_0019FA40
void func_0019fa40(void)
{
    u16 flags;
    u16 type;
    u8 *packet;
    u8 *work;

    work = *(u8 **)(iGpffffb3ac + 0x174);
    while (work != NULL) {
        flags = *(u16 *)(work + 0x1A);
        if ((flags & 0x200) != 0 && (flags & 1) != 0) {
            packet = *(u8 **)(work + 0x30);
            if ((*(s32 *)(packet + 0x9C) & 8) != 0 &&
                btlUnitIsMoving(packet) == 0) {
                type = *(u16 *)(work + 0xC);
                switch (type) {
                case 1:
                case 5:
                    func_0019f8a0(work);
                    break;
                default:
                    break;
                }
            }
        }
        work = *(u8 **)(work + 0x450);
    }
}
// FUN_0019FAF0
void func_0019faf0(u8 *arg0)
{
    f32 sp40[3];
    u16 temp_4;
    u8 *var_17;
    u8 *temp_16;

    var_17 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_17 != NULL) {
        if ((*(u16 *)(var_17 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(var_17 + 0x30);
            if ((*(s32 *)(temp_16 + 0x9C) & 8) != 0 &&
                func_00198840(temp_16) != 0 &&
                btlUnitIsMoving(temp_16) == 0 &&
                datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64), 0x100000) == 0 &&
                datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64), 0xFFFFF) == 0 &&
                datCalcIsLowHp(*(u8 **)(temp_16 + 0xA64)) == 0 &&
                datCalcIsDead(*(u8 **)(temp_16 + 0xA64), 0) == 0) {
                temp_4 = *(u16 *)(var_17 + 0xC);
                switch (temp_4) {
                case 1:
                case 5:
                    if (arg0 != var_17) {
                        func_00194ff0(temp_16, NULL, NULL, sp40);
                        func_00194590(btlUnitCreateLookAtPacket(temp_16, sp40, 0), 1);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        var_17 = *(u8 **)(var_17 + 0x450);
    }
}
// FUN_0019FC60
void func_0019fc60(void) {
}
/* measured: opt_propagation off with named table pointers preserves retail load order. */
#pragma push
#pragma opt_propagation off
// FUN_0019FC70
s32 func_0019fc70(u8 *arg0)
{
    u16 temp_18;
    u16 temp_17;
    s32 temp_16;
    u16 result;
    u8 *temp_4;

    temp_18 = *(u16 *)(arg0 + 0x6E);
    result = (u16)func_001d7f10(arg0, NULL, temp_18, 0);
    temp_4 = *(u8 **)(arg0 + 0x30);
    temp_17 = *(u16 *)(*(u8 **)(temp_4 + 0xA64) + 2);
    if (result != 0)
        goto result_zero_0019fc70;

    temp_16 = temp_18 & 0xFFFF;
    if ((iGpffffb3b8[temp_16 * 0x28] & 2) != 0) {
        switch (*(u8 *)(temp_4 + 0xA2)) {
        case 1:
            goto type_one_0019fc70;
        default:
            goto result_one_0019fc70;
        }
type_one_0019fc70:
        if (func_001f0a50(arg0) != 0) {
            {
                u8 *table18;
                table18 = iGpffffb3cc;
                if ((*(s16 *)(p4_unit_00195530(
                    (u16)temp_17 * 0xE8, table18) + 0x18) &
                     0x100) != 0) {
                    return 1;
                }
            }
        }
        {
            u8 *table22;
            table22 = iGpffffb3cc;
            if (*(s16 *)(p4_unit_00195530(
                (u16)temp_17 * 0xE8, table22) + 0x22) == 1)
                return 0;
        }
result_one_0019fc70:
        return 1;
    }
    if (func_001f11e0((s64)(s16)temp_18) != 0) {
        {
            u8 *flags_table;
            flags_table = (u8 *)iGpffffb3bc;
            if ((*(u16 *)(p4_unit_00195530(
                temp_16 * 4, flags_table) + 2) & 1) == 0)
                return 0;
        }
        /* Deliberately write case 0 before case 1: MWCC tests the last-written case first. */
        switch (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) {
        case 0:
        default:
            goto second_default_0019fc70;
        case 1:
            goto second_type_one_0019fc70;
        }
second_type_one_0019fc70:
        {
            u8 *table26;
            table26 = iGpffffb3cc;
            if (*(s16 *)(p4_unit_00195530(
                (u16)temp_17 * 0xE8, table26) + 0x26) == 1)
                return 0;
        }
second_default_0019fc70:
        return 1;
    }
result_zero_0019fc70:
    return 0;
}
#pragma pop
/* measured: opt_propagation off is scoped to func_0019fe60. */
#pragma opt_propagation off
// FUN_0019FE60
s32 func_0019fe60(u8 *arg0, s32 arg1, s32 arg2)
{
    u16 temp_6;
    u8 *temp_2;
    u8 *temp_4;
    u8 *table;
    u8 *table2;
    u8 kind;
    u8 status;

    temp_2 = *(u8 **)(arg0 + 0x30);
    temp_4 = *(u8 **)(temp_2 + 0xA64);
    temp_6 = *(u16 *)(temp_4 + 2);
    kind = *(u8 *)(temp_2 + 0xA2);
    switch (kind) {
    case 0:
        status = func_0023e1f0(temp_4);
        if (status == 5) {
            return 1;
        }
        if (status == 3) {
            table = (u8 *)iGpffffb3bc;
            if ((*(u16 *)(p4_unit_00195530((arg1 & 0xFFFF) * 4,
                                           table) + 2) &
                 0x8000) != 0 ||
                arg2 == 0) {
                return 1;
            }
        }
        break;
    case 1:
        table2 = iGpffffb3cc;
        if (*(s16 *)(p4_unit_00195530((temp_6 & 0xFFFF) * 0xE8,
                                      table2) + 0x22) == 1) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
/* measured: closes opt_propagation around func_0019fe60. */
#pragma opt_propagation on
// FUN_0019FF60
s32 func_0019ff60(u8 *arg0)
{
    u8 *state;
    u8 *current;
    u8 *unit;
    u16 enemyCount;

    state = *(u8 **)(iGpffffb3ac + 0x170);
    if (datCalcIsDead(*(u8 **)(*(u8 **)(state + 0x30) + 0xA64), 0) != 0 ||
        datCalcChkBadStatus(*(s32 *)(*(u8 **)(state + 0x30) + 0xA64),
                       0x100117) != 0) {
        return 0;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1 &&
        datCalcIsDead(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0) != 0) {
        return 0;
    }
    *(u16 *)(iGpffffb3ac + 0xC58) = 0;
    enemyCount = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    for (; current != NULL; current = *(u8 **)(current + 0x450)) {
        if ((*(u16 *)(current + 0x1A) & 1) == 0) continue;
        unit = *(u8 **)(current + 0x30);
        if ((*(s32 *)(unit + 0x9C) & 8) == 0 ||
            datCalcIsDead(*(u8 **)(unit + 0xA64), 0) != 0) continue;
        if (*(u8 *)(unit + 0xA2) == 1) {
            if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100000) == 0) return 0;
            enemyCount++;
        } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100117) == 0 &&
                   state != current) {
            *(u8 **)(iGpffffb3ac +
                     (*(u16 *)(iGpffffb3ac + 0xC58) * 4) + 0xC48) = current;
            (*(u16 *)(iGpffffb3ac + 0xC58))++;
        }
    }
    if (enemyCount == 0) return 0;
    return *(u16 *)(iGpffffb3ac + 0xC58) >= 1;
}
