#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
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
extern u32 datUnitInit(DatUnit *unit, u8 genus, u16 id);

extern void func_00106390(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0045c870(void *arg0, s32 arg1);
extern void func_0048a000(void);
extern f32 fGpffff8474;
extern void func_003c22f0(void *arg0);
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern s32 func_001f0a50(u8 *arg0);
extern s32 func_001f11e0(s16 arg0);
extern s32 func_0023d8e0(u8 *arg0, u16 arg1);
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;
extern s64 btlGetUID(void);

extern s64 scrGetParamInt(s32 arg0);
extern u8 *func_00105510(s16 arg0);
extern void func_00243ec0(u8 *arg0, s16 arg1);
extern s32 func_00243e90(u8 *arg0);
extern void scrSetReturnInt(s32 arg0);

extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern s32 datGetPartyId(s32 arg0);
extern s32 datUnitCreatePc(s32 arg0);
extern s32 datUnitCreateEncounterGroup(s32 arg0);
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
extern s32 btlUpdateDraw2DTask(u8 *task);
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
extern void KMisc_CreateScrShutdown(s32 arg0);
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
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 func_0044b950(f32 x, f32 y);
extern f32 fGpffff8048;
extern void func_003dc740(void *dst, const void *src, s32 mode, f32 angle);
extern u8 D_0060A0E0[];
extern void btlUnitRequestLookAt(u8 *arg0);
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
extern s32 itfMesWindowInstall(u8 *arg0);
extern s32 btlUnitLoadStep(u8 *task);

extern s32 btlUnitLoadBlocksFromFile(u8 *arg0, s32 arg1);
extern void func_0010d480(void);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void func_00195630(u8 *arg0);
extern u8 *kwlnTaskGetTaskByName(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);

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
extern void MT_Scene_DestroyRes(u16 arg0);
extern void func_004787e0(void *arg0);
extern void mdlSetColor(void *arg0, s32 *arg1);
extern void func_0047a0e0(u8 *arg0, s32 arg1, f32 arg2);
extern u8 iGpffffa4d8;
extern void func_001d1540(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001ee430(u8 *arg0);
extern void func_001d7040(s32 arg0);
extern void func_001d6c10(s32 arg0);
extern void func_00194670(u8 *arg0);
extern int mdlHasActiveMode(void *arg0);
extern void mdlSetLookAtActive(void *arg0);
extern void func_0019d550(u8 *arg0);
extern void mdlSetLookAtRequested(void *arg0);
extern u8 *resrcMngFindResById(u8 *arg0, u16 arg1);
extern void func_0019d7a0(u8 *arg0, s32 arg1);
extern void func_0047a810(void *arg0);
extern void mdlSetAlphaBlend(void *arg0);
extern void mdlSetLookStateWord(void *arg0, u16 arg1);
extern u16 mdlGetLookStateWord(void *arg0);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlClearBattleStateFlag(void *arg0);
extern void mdlClearAlphaBlend(void *arg0);
extern void mdlSetBlendWeight(void *arg0, float arg1);
extern void mdlLookAtSetupSetRange(void *arg0, float arg1, float arg2);
extern f32 DAT_0076112c;


extern void func_0019d990(u8 *arg0, s32 arg1);
extern void func_0019d7a0(u8 *arg0, s32 arg1);
extern u8 *func_001f7650(u8 *arg0);
extern void SceneDraw_SetResVisibleChecked(u16 arg0, u32 arg1);

extern u8 *btlUnitCreate(s32 arg0);
extern void func_0019ea60(u8 *arg0, s32 arg1);



extern s32 func_0019be50(u8 *arg0);
extern s32 func_0010d6d0(s16 arg0);
extern u8 *func_00194470(s32 arg0, s32 arg1);
extern float func_001d4380(int arg0);
extern s32 func_00197a80(u8 *arg0);
extern s32 func_0010d740(s16 arg0);
extern u8 *datPersonaGetRow(u16 arg0);
extern s32 iGpffffb444;
extern s32 btlUnitIsMoving(u8 *arg0);
extern s32 func_0019f8a0(u8 *arg0);
extern s32 datCalcIsStandardUnit(s32 arg0, s32 arg1);
extern u8 *btlUnitCreateLookAtPacket(u8 *arg0, f32 *arg1, s32 arg2);
extern s32 datCalcIsLowHp(u8 *arg0);
extern s32 func_00243e30(s32 arg0);
extern void func_0047a120(void *arg0);
extern void func_0047a150(void *arg0);
extern u8 *btlUnitCreateAnimPacket(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern u16 *datPersonaGetRecord(u16 character);
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
extern void btlUnitHoldPendingPacketIfUnit(u8 *arg0);
extern s32 func_0019e850(u8 *arg0);
extern void btlUnitReleasePendingPacketIfUnit(u8 *arg0);
extern u8 *func_00457120(void);
extern s32 func_003e8120(u8 *arg0);
extern void func_003c1bd0(s32 arg0);
extern s32 func_003e8110(u8 *arg0);
extern u8 *kwlnTaskGetTaskByName(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern s32 func_00192cd0(void);
extern void func_00194a30(void);
extern void func_0019d670(void);
extern void datUnitFree(s32 arg0);
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
extern void func_0047d170(void *model);
extern s32 func_0047e6f0(void **owner);
extern void func_0019db40(u8 *arg0);
extern void func_001fc1b0(s16 arg0);
extern s32 func_002300f0();
extern void func_0019acd0(u8 *arg0);
extern s32 func_0019ae20();
extern void func_001d6ee0(s32 arg0);
extern void btlUnitReleaseModel(u8 *arg0);
extern void func_0019d0c0();
extern void func_0019d040(u8 *arg0);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern void func_00479100(void *arg0, void *arg1);
extern u8 D_00794150[];


extern s64 func_001990d0(u8 *arg0, u16 arg1);
extern s16 func_001991c0(u8 *arg0, u16 arg1, f32 fparg0);
extern void func_001949d0(s32 arg0);
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
    return (s32)kwlnTaskCreateChild((void *)((u8 *)arg0), (const void *)(D_005F6020), 0xF, 0, 0, func_0018f950, func_001900a0, (u8 *)(work));
}
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_propagation on




















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
#pragma opt_loop_invariants off

#pragma optimization_level 1
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_propagation on

static inline u32 packetListOffset(u32 offset, u32 base)
{
    return offset + base;
}


typedef struct {
    u8 *head;
    u8 *tail;
} PacketList;
extern s32 func_00193d90(u8 *arg0, s32 arg1);


/* measured: opt_propagation off is scoped to func_001949d0. */
#pragma opt_propagation off

/* measured: closes opt_propagation for func_001949d0. */
#pragma opt_propagation on


#pragma optimization_level 1
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_propagation on





extern void func_001eec50(void *work);
extern s32 func_001eed10(u8 *route, f32 *start, f32 *end, f32 radius);
extern s32 func_001ef110(u8 *route, const f32 *startXZ, const f32 *endXZ, const f32 *centerXZ);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);

#pragma opt_propagation off
#pragma opt_propagation on


extern s32 func_00198810(u8 *arg0);
extern u32 func_00198840(u8 *arg0);
extern u32 func_001988b0(u8 *arg0);
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
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on




#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_propagation off
#pragma pop





















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










/* Retail reloads the 1/255 colour scale (0x3B808081, written here as a
 * literal) for every factor; with default optimisation b210 does the same.
 * `v41` and `chk` are function-scope locals so they keep retail's saved
 * registers. On the `i == 2 && alpha < 0xFE` path retail compares 0xE8
 * against the `mode` left from an earlier entry (0x0019CDE0); the C reads
 * `mode` uninitialised there in the same way. */
#pragma push
typedef struct { u8 r, g, b, a; } Col4_0019;
typedef struct {
    f32 right[3];
    s32 flags;
    f32 up[3];
    s32 pad1;
    f32 at[3];
    s32 pad2;
    f32 pos[3];
    s32 pad3;
} Mtx_0019;

static inline void colMul_0019(Col4_0019 *dst, const u8 *src)
{
    f32 scale;
    f32 bias;
    f32 g = (0.003921569f * (f32)(u32)dst->g) * (0.003921569f * (f32)(u32)src[1]);
    f32 b = (0.003921569f * (f32)(u32)dst->b) * (0.003921569f * (f32)(u32)src[2]);
    f32 a = (0.003921569f * (f32)(u32)dst->a) * (0.003921569f * (f32)(u32)src[3]);
    f32 r = (0.003921569f * (f32)(u32)dst->r) * (0.003921569f * (f32)(u32)src[0]);

    scale = 255.0f;
    bias = 0.5f;
    dst->r = (s32)(scale * r + bias);
    dst->g = (s32)(scale * g + bias);
    dst->b = (s32)(scale * b + bias);
    dst->a = (s32)(scale * a + bias);
}

// FUN_0019C0D0
void func_0019c0d0(void)
{
    extern u32 func_00196610(u8 *arg0);
    extern void func_00230170(u8 *arg0);
    extern void SceneDraw_SetResPersona(u16 arg0, u32 arg1);
    extern void func_001b70c0(u8 *arg0);
    extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
    extern void mdlScale(void *arg0, void *arg1, s32 arg2);
    extern void *func_0047a180(void *arg0, void *arg1, s32 arg2);
    extern void func_00478e70(void *arg0);
    extern s32 func_001ee490(u8 *arg0);
    extern u32 func_0019d130(u8 *arg0);
    extern s32 func_001d72e0(s32 arg0);
    extern s16 func_001d7130(s32 arg0);
    extern void func_001d7400(s32 arg0, u8 *arg1);
    /* Retail passes the sign-extended word from (s16)func_001d72e0() in $a1
     * without narrowing; the s16 definition's prototype adds a re-extension. */
    extern void func_001d7100(u8 *arg0, s32 arg1);
    extern void func_001d72c0(void *arg0, u32 arg1);
    extern void func_001d7140(u8 *arg0);
    u8 *entry;
    u32 i;
    s32 v41;
    s32 chk;

    for (i = 0; i < 4; i++) {
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
                    u16 id;

                    if ((id = *(u16 *)(entry + 0x9FE)) != 0) {
                        SceneDraw_SetResPersona(id, *(u8 *)(entry + 0xAC) == 1);
                    }
                }
                break;
            }
            if ((*(s32 *)(entry + 0x98) & 2) != 0) {
                s32 v;
                s32 n;

                func_001b70c0(entry);
                v = *(u16 *)entry;
                if ((v & 3) != 0 && (v & 4) == 0) {
                    u8 base;
                    s32 t;

                    if ((v & 8) != 0) {
                        base = 0x58;
                    } else {
                        base = 0;
                    }
                    t = *(u8 *)(entry + 0x37);
                    if (base + 0x20 < t) {
                        *(u8 *)(entry + 0x37) = t - 0x20;
                    } else {
                        *(u8 *)(entry + 0x37) = base;
                    }
                    *(s32 *)(entry + 0x98) |= 4;
                } else {
                    s32 t = *(u8 *)(entry + 0x37);

                    if (t < 0xFF) {
                        if (t < 0xDF) {
                            *(u8 *)(entry + 0x37) = t + 0x20;
                        } else {
                            *(u8 *)(entry + 0x37) = 0xFF;
                        }
                        *(s32 *)(entry + 0x98) |= 4;
                    }
                }
                n = *(u16 *)(entry + 0x4C);
                if (n > 0) {
                    f32 fdiv = (f32)(u32)n / 8.0f;
                    u32 b;

                    b = *(u8 *)(entry + 0x48);
                    *(u8 *)(entry + 0x40) = b + (u32)(fdiv * (f32)(s32)(*(u8 *)(entry + 0x44) - b));
                    b = *(u8 *)(entry + 0x49);
                    *(u8 *)(entry + 0x41) = b + (u32)(fdiv * (f32)(s32)(*(u8 *)(entry + 0x45) - b));
                    b = *(u8 *)(entry + 0x4A);
                    *(u8 *)(entry + 0x42) = b + (u32)(fdiv * (f32)(s32)(*(u8 *)(entry + 0x46) - b));
                    *(s32 *)(entry + 0x98) |= 4;
                    *(u16 *)(entry + 0x4C) = *(u16 *)(entry + 0x4C) - 1;
                }
                if ((*(s32 *)(entry + 0x98) & 4) != 0) {
                    Mtx_0019 m;
                    f32 vec[3];
                    Col4_0019 col;
                    s32 mode;
                    u8 *obj;
                    f32 x = *(f32 *)(entry + 0x1C);
                    f32 y = *(f32 *)(entry + 0x20);
                    f32 z = *(f32 *)(entry + 0x24);
                    f32 w = *(f32 *)(entry + 0x28);
                    f32 xx = x * x;
                    f32 yy = y * y;
                    f32 zz = z * z;
                    f32 yz = y * z;
                    f32 zx = z * x;
                    f32 xy = x * y;
                    f32 wx = w * x;
                    f32 wy = w * y;
                    f32 wz = w * z;
                    f32 two = 2.0f;
                    f32 one = 1.0f;

                    m.right[0] = one - two * (yy + zz);
                    m.right[1] = two * (xy + wz);
                    m.right[2] = two * (zx - wy);
                    m.up[0] = two * (xy - wz);
                    m.up[1] = one - two * (xx + zz);
                    m.up[2] = two * (yz + wx);
                    m.at[0] = two * (zx + wy);
                    m.at[1] = two * (yz - wx);
                    m.at[2] = one - two * (xx + yy);
                    m.pos[0] = 0.0f;
                    m.pos[1] = 0.0f;
                    m.pos[2] = 0.0f;
                    m.flags = 3;
                    func_0047a1c0(*(u8 **)(entry + 0xA00), &m, 0);
                    vec[0] = vec[1] = vec[2] = *(f32 *)(entry + 0x2C);
                    mdlScale(*(u8 **)(entry + 0xA00), vec, 2);
                    vec[0] = *(f32 *)(entry + 4) + *(f32 *)(entry + 0x10);
                    vec[1] = *(f32 *)(entry + 8) + *(f32 *)(entry + 0x14);
                    vec[2] = *(f32 *)(entry + 0xC) + *(f32 *)(entry + 0x18);
                    func_0047a180(*(u8 **)(entry + 0xA00), vec, 2);
                    col = *(Col4_0019 *)(entry + 0x30);
                    colMul_0019(&col, entry + 0x34);
                    colMul_0019(&col, entry + 0x3C);
                    colMul_0019(&col, entry + 0x40);
                    if (col.a >= 0xFE) {
                        col.a = 0xFF;
                        mode = 0x737FB;
                        func_0019d990(entry, 2);
                        func_0019d990(entry, 5);
                    } else if (i != 2) {
                        mode = 0x737FB;
                        func_0019d7a0(entry, 2);
                        func_0019d7a0(entry, 5);
                    }
                    {
                        s32 *e8 = (s32 *)(*(u8 **)(entry + 0xA00) + 0xE8);

                        if (*e8 != mode) {
                            u32 j;

                            *e8 = mode;
                        for (j = 0; j < 5; j++) {
                            u8 *sub = *(u8 **)((u32)*(u8 **)(entry + 0xA00) + j * 12 + 0x290);

                            if (sub != NULL) {
                                *(s32 *)(sub + 0xE8) = mode;
                            }
                        }
                        }
                    }
                    {
                        Col4_0019 *cp = &col;

                        *(Col4_0019 *)(entry + 0x4E) = *cp;
                        mdlSetColor(*(u8 **)(entry + 0xA00), (s32 *)cp);
                    }
                    func_001ee490(entry);
                    *(s32 *)(entry + 0x98) &= ~4;
                }
                {
                    u8 *obj2 = *(u8 **)(entry + 0xA00);

                    if ((*(s32 *)(obj2 + 0xD8) & 4) != 0) {
                        func_00478e70(obj2);
                    }
                }
                if (*(s32 *)(entry + 0xA04) != 0 && func_0019d130(entry) != 0) {
                    u8 *p = *(u8 **)(entry + 0xA64);

                    if (p != NULL) {
                        v41 = *(u32 *)(p + 0xC) & 0xFFFFF;
                        chk = (s16)func_001d72e0(v41);

                        if (chk != (s16)func_001d7130(*(s32 *)(entry + 0xA04))) {
                            func_001d7400(v41, entry + 0x48);
                            *(Col4_0019 *)(entry + 0x44) = *(Col4_0019 *)(entry + 0x40);
                            *(u16 *)(entry + 0x4C) = 8;
                            func_001d7100(*(u8 **)(entry + 0xA04), chk);
                        }
                    }
                    func_001d72c0(*(u8 **)(entry + 0xA04), *(u32 *)(entry + 0x4E));
                    func_001d7140(*(u8 **)(entry + 0xA04));
                }
            }
            entry = *(u8 **)(entry + 0xA68);
        }
    }
}
#pragma pop
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
        SceneDraw_SetResVisibleChecked(*(u16 *)(arg0 + 0x9FE), 1);
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
        SceneDraw_SetResVisibleChecked(*(u16 *)(arg0 + 0x9FE), 0);
    }
    *(s32 *)(arg0 + 0x9C) &= ~2;
}



#pragma push
#pragma opt_propagation off
#pragma pop


#pragma opt_propagation off
#pragma opt_propagation on

#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals off
#pragma opt_common_subs off

#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on
