#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "type.h"
#include "field_light_internal.h"
typedef struct RwRGBA
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RwRGBA;
typedef struct P4_0015_Vec3
{
    f32 x;
    f32 y;
    f32 z;
} P4_0015_Vec3;
extern s32 iGpffffb210;
extern void H_Cdvd_Destroy();

extern void (*DAT_008873EC[])(void *);

extern s32 func_00102980(void);
extern void func_00145080();
extern void func_00160440(void);

extern u8 *D_00764334;
extern s32 D_00764384;
extern u32 D_0076438C;
extern void func_00440b68();
extern s32 iGpffff9e28;
extern s32 iGpffffb218;
extern u8 D_007D3E10[];
extern u8 D_007E36E4[];
extern u8 D_007E36F8[];
extern u8 D_005F05E8[];
extern u8 D_005F06C0[];
extern u8 D_005F0740[];
extern u8 D_005F0760[];
extern u8 D_005F06E0[];
extern u8 D_005F0700[];
extern u8 D_005F0770[];
extern u8 D_005F0720[];
extern u8 D_005F0670[];
extern s16 D_005F05D0[];
extern u8 D_005F05CE[];
extern u8 D_007D3E2B[];
extern void memset(void *dst, s32 value, u32 size);
extern void sprintf(void *dst, const char *fmt, ...);
extern void strcpy(void *dst, const char *fmt);
extern u8 *iGpffffb244;
extern s32 D_007E8060[];
extern u8 *iGpffff9db0;
extern s32 func_0014a200();
extern s32 func_0014a270(void);
extern void func_00151f80(s32 arg0);
extern s32 func_0014e710();
extern void func_0046d730();
extern void memcpy();
extern void func_0044ea90(const void *msg, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 func_0014e5e0();
extern s32 H_Cdvd_FileExists(void *arg0);
extern f32 iGpffff853c;
extern f32 iGpffffb290;
extern f32 iGpffffb28c;
extern s32 iGpffffb288;
extern f32 iGpffff8218;
extern f32 iGpffff830c;
extern s32 func_00454a60(void *arg0, s32 arg1);
extern u8 D_005EFF60[];
extern void func_00160880(void);
extern s32 D_007D2510[];
extern u8 D_007D24F0[];
extern u8 D_005EFFE0[];
extern s32 func_001561a0(u8 *arg0);
extern void func_00156630(u8 *task);
extern s32 H_Cdvd_IsFileLoaded();
extern void func_003642e0(s32 arg0, s32 arg1);
extern u8 D_007E31E4[];
extern u8 D_005F0650[];
extern u32 datGetFlag(s32 arg0);

extern s32 func_00106390(s32 arg0, s32 arg1);
extern s32 func_00159a60(u8 *arg0);
extern void func_00159d50(u8 *task);
extern void func_001587d0(u16 arg0, u32 arg1, u32 arg2);
extern s32 func_0014a160(void);
extern void func_0016e540(s32 arg0, s32 arg1);
extern void func_003642a0(s32 arg0);
extern void func_004787e0(s32 arg0);
/* Forces b210's offset-first addu operand order. */
static inline u32 wg0035_add_offset(u32 offset, u32 base)
{
    return offset + base;
}
static inline u8 *wg0015_add_ptr(u8 *base, s32 offset)
{
    return base + offset;
}


extern u8 *func_001452b0(s32 arg0);
extern void func_00458f40(s32 arg0, s32 arg1);
extern void func_00458f70(s32 arg0, s32 arg1);
extern s32 mdlGetClump(s32 arg0);
extern s32 *func_00155280(void);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern void func_003e0670(void *arg0, s32 arg1);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern void func_0016e590(s32 arg0, s32 arg1);
extern void func_0016e9f0(s32 arg0, void *arg1);
extern void func_0016ea20(s32 arg0, f32 arg1);
extern void func_0016ea30(s32 arg0, f32 arg1);
extern void func_0016eaa0(s32 arg0, s8 arg1, void *arg2);
extern u8 *func_0016eaf0(s32 arg0);
extern u8 *mdlGetMatrix(s32 arg0);
extern s32 func_00457c90(s32 arg0, const void *arg1);
extern u8 D_005F0690[];
extern u8 D_005F06A0[];
extern void func_0016eb00(s32 arg0);
extern u8 *MT_Scene_GetRes(s32 arg0);
extern s32 func_001687d0(s32 arg0);
extern s32 func_001687e0(s32 arg0);
extern f32 func_0014b5d0(u8 *arg0);
extern void func_0015b3e0(s32 arg0, s32 arg1, u8 arg2, u8 arg3,
                          s32 arg4, s32 arg5, u8 arg6, s32 *arg7);
extern s32 D_0076430C;
extern u8 D_007E8C00[];
extern s32 D_007E8020[];
extern u8 D_005F057C[];
extern u8 D_005F0590[];
extern u8 D_007E80A0[];
extern s32 D_0076432C;
extern s32 iGpffffb2e4;
extern void func_002ac360(void);
extern u8 *func_002ac3b0(void);
extern u8 *func_00161c80(s32 field, s32 room, u16 index, u16 mode);
extern u8 D_005F0080[];
extern u8 D_005F0591[];
extern u8 D_005F0592[];
extern u32 D_00764314;
extern u32 D_00764324;
extern u32 D_00764328;
extern u32 RpRandom(void);
extern void func_00156800(void *arg0, u32 arg1);
extern s32 func_00156cf0(void *arg0, u32 *arg1, u32 *arg2);
extern void func_00157310(u8 *arg0, u16 arg1, u16 arg2, s16 arg3);
extern void func_00157700(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 *arg5, s32 *arg6);
static inline void wg0015_place_special(u8 special_direction, s32 x, s32 y,
                                        u8 *tile)
{
    func_00157310(tile, (u16)x, (u16)y, special_direction);
}

/* measured: opt_loop_invariants hoists the 0x10000000 mask before the loop
 * test and colours it $a0 with the field in $v1 (nd 15 -> 0). */
#pragma opt_loop_invariants on
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 func_00457120(void);
extern s32 func_004782b0(s32 arg0);



extern void (*jtbl_008873EC[])(void *);

// FUN_001537C0
void func_001537c0(u8 *arg0, s32 arg1)
{
    s32 index;
    u8 *work;

    work = func_001452b0(0xA);
    if ((*(s32 *)(arg0 + 0) & 1) != 0) {
        func_00458f70(*(s32 *)(arg0 + 8), arg1);
    }
    index = 0;
    while ((u32)index < *(u32 *)(arg0 + 0x18)) {
        func_00458f40(*(s32 *)(arg0 + (index * 4) + 0x1C), arg1);
        index += 1;
    }
    while (work != NULL) {
        func_00458f40(mdlGetClump(*(s32 *)(work + 0x144)), arg1);
        work = *(u8 **)(work + 0x138);
    }
}
// FUN_001538A0
void func_001538a0(u32 *resource, const f32 *color)
{
    u32 i;
    s32 node;
    RwRGBA rgba;
    u32 model;

    node = (s32)func_001452b0(10);
    if ((*resource & 1) != 0)
    {
        func_00458cb0(resource[2], color);
    }
    for (i = 0; i < resource[6]; i++)
    {
        func_00458c80(*(u32 *)((u8 *)resource + i * 4 + 0x1C), color);
    }
    while (node != 0)
    {
        rgba.r = (s32)(color[0] * 255.0f + 0.5f);
        rgba.g = (s32)(color[1] * 255.0f + 0.5f);
        rgba.b = (s32)(color[2] * 255.0f + 0.5f);
        rgba.a = (s32)(color[3] * 255.0f + 0.5f);
        model = *(u32 *)(node + 0x144);
        mdlSetColor(model, &rgba);
        node = *(s32 *)(node + 0x138);
    }
}
// FUN_00153A00
s32 func_00153a00(u8 *unusedTask)
{
    func_00160880();
    return 0;
}
// FUN_00153A30
void func_00153a30(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}



// FUN_00155070
void func_00155070(void)
{
    u8 sp30[0x40];
    u8 *temp_2;
    u8 *var_2;
    u8 *var_6;
    s16 *temp_4;
    s32 temp_3;
    s32 var_5;
    s32 var_17;

    temp_2 = func_001452b0(0x14);
    if (temp_2 != NULL) {
        K_View_SetFov((void *)func_00457120(), *(f32 *)(temp_2 + 0x144));
        func_003e0670(sp30, *(s32 *)(temp_2 + 0x148));
        func_003e9cb0(*(s32 *)(func_00457120() + 4), sp30, 0);
        func_0016e590(func_00155280()[1], *(s32 *)(temp_2 + 0x140));
        func_0016e9f0(func_00155280()[1], temp_2 + 0x150);
        if ((*(f32 *)(temp_2 + 0x15C) == 0.0f) &&
            (func_0014a160() == 1)) {
            *(f32 *)(temp_2 + 0x15C) = 20.0f;
        }
        func_0016ea20(func_00155280()[1], *(f32 *)(temp_2 + 0x15C));
        func_0016ea30(func_00155280()[1], *(f32 *)(temp_2 + 0x160));
        var_17 = 0;
        goto loop_test;
loop_body:
        if (*(s8 *)(temp_2 + var_17 + 0x164) != 0) {
            func_0016eaa0(func_00155280()[1],
                          (s8)var_17,
                          temp_2 + var_17 * 0xC + 0x184);
        }
        var_17 += 1;
loop_test:
        if (var_17 < 0x20) {
            goto loop_body;
        }
        func_003e0670(sp30, *(s32 *)(temp_2 + 0x14C));
        var_2 = func_0016eaf0(func_00155280()[1]);
        var_6 = sp30;
        var_5 = 8;
        do {
            temp_4 = *(s16 **)var_6;
            temp_3 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_5 -= 1;
            *(s16 **)var_2 = temp_4;
            *(s32 *)(var_2 + 4) = temp_3;
            var_2 += 8;
        } while (var_5 > 0);
        func_0016eb00(func_00155280()[1]);
    }
}
// FUN_00155250
void func_00155250(void)
{
    memset(D_007D2510, 0, 0x18F8);
}
// FUN_00155280
s32 *func_00155280(void)
{
    return D_007D2510;
}
// FUN_00155290
s32 func_00155290(void)
{
    return iGpffffb210;
}

// FUN_001552A0
void func_001552a0(u16 arg0, u16 arg1) {
    f32 value;

    value = 0.0f;
    if ((arg0 == 7) && (arg1 != 1)) {
        value = iGpffff853c;
    }
    if ((arg0 == 6) && (arg1 == 6)) {
        value = iGpffff853c;
    }
    if ((arg0 == 0x15) && (arg1 == 1)) {
        value = iGpffff853c;
    }
    if (!(value <= 0.0f)) {
        iGpffffb290 = value;
        iGpffffb28c = 128.0f * value;
        iGpffffb288 = 0x40400000;
        return;
    }
    iGpffffb290 = iGpffff8218;
    iGpffffb28c = iGpffff830c;
    iGpffffb288 = 0x40400000;
}
// FUN_001560A0
void func_001560a0(u8 *arg0, u16 arg1, u16 arg2, u16 arg3) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_16 + 0xD8) = arg1;
    *(s16 *)(temp_16 + 0xDA) = arg2;
    *(s16 *)(temp_16 + 0xDC) = arg3;
    *(s16 *)(temp_16 + 0xDE) = 0;
    *(s16 *)(temp_16 + 0xE0) = 0;
    func_00122520(1, 0);
    *(s32 *)(temp_16 + 0) = 0x11;
}

// FUN_001560F0
void func_001560f0(u8 *arg0, s32 arg1) {
    u8 *p;

    if (arg0 != NULL) {
        p = *(u8 **)(arg0 + 0x38);
        func_00440b68(D_005EFF60);
        *(s32 *)(p + 8) = arg1;
    }
}

// FUN_00156140
s32 func_00156140(u8 *arg0)
{
    if (arg0 == NULL) {
        return 1;
    }
    return *(s32 *)(*(u8 **)(arg0 + 0x38)) >= 0xD;
}
// FUN_00156170
u16 func_00156170(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x18);
}

// FUN_00156180
u16 func_00156180(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A);
}

// FUN_00156190
u16 func_00156190(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20);
}

typedef struct FldLoadWork {
    s32 state;
    s32 mode;
    u16 fieldId;
    u16 roomId;
    s16 mapState;
    s16 environmentState;
    s32 storyGroup;
    s32 storyEntry;
    u8 *file;
    s32 scriptTask;
} FldLoadWork;
typedef char FldLoadWorkSizeCheck[sizeof(FldLoadWork) == 0x20 ? 1 : -1];

/* Measured: all 1168 code bytes and the nine-entry state table match retail.
 * Scoped propagation control preserves file and script argument snapshots. */
#pragma push
#pragma opt_propagation off
// FUN_001561A0
s32 func_001561a0(u8 *task)
{
    extern s16 func_001060b0(void);
    extern u8 func_001060c0(void);
    extern s64 func_00110960(s32 day, u32 period);
    extern s32 func_00248e20(s32 group, s32 entry, s32 condition);
    extern void func_00123aa0(s16 selection);
    extern void func_002aaa80(void);
    extern s32 func_0014ef40(void);
    extern s32 func_0014a230(s32 fieldId, s32 roomId);
    extern u8 *func_001601e0(s32 fieldId);
    extern s32 func_001602a0(u8 *file, s32 fieldId);
    extern s32 func_0029db50(s32 priority, s32 memory, s32 bytes, s32 procedure);
    extern s32 func_00452490(void *task);
    extern u8 *func_0015ff20(u16 fieldId, s32 roomId);
    extern void func_00144c90(s32 fieldId, s32 roomId);
    extern void func_00144e10(s64 mapState);
    extern void func_00144ed0(s64 environmentState);
    extern s32 func_00154720(u16 fieldId, u16 roomId, s32 condition);
    extern s32 func_00160000(u8 *file);
    extern s32 func_00144f60(void);
    extern s32 func_0014a190(s32 fieldId, s32 roomId);
    extern s32 func_0014e5e0(u8 *parent, u8 *path, s32 index, s32 file);
    extern s32 func_0014e710(u8 *task);
    extern s32 func_0016e2e0(s32 parent);
    extern s32 D_007D3D64[];
    extern s32 D_007D3D68[];
    extern s32 iGpffffb268;
    extern s32 iGpffffb20c;
    extern s32 D_007D2544[];
    extern u8 D_005EFF80[];
    extern u8 D_005EFFA0[];
    extern u8 D_005EFFC0[];
    extern s32 D_007D2514[];
    extern s32 D_007D2548[];
    extern s32 D_007D254C[];
    extern s32 D_007E3710[];
    extern s32 D_007E3714[];
    extern s32 D_007E3718[];
    s32 selection;
    s32 selectedEnvironment;
    s32 day;
    s32 initialDay;
    s32 condition;
    s32 script;
    s32 scriptSize;
    u8 *file;
    s32 fieldId;
    FldLoadWork *work;

    work = (FldLoadWork *)((SdkTask *)task)->work;
    if (work->state > 2 && datGetFlag(0x1470) == 0) {
        func_002aaa80();
    }
    switch (work->state) {
    case 0:
        if (func_0014ef40() == 0) {
            break;
        }
        if (func_0014a230(work->fieldId, work->roomId) == 0) {
            work->file = func_001601e0(work->fieldId);
        }
        work->state = 1;
        /* Begin polling the request submitted above. */
    case 1:
        file = work->file;
        if (func_001602a0(file, work->fieldId) == 0) {
            break;
        }
        work->file = NULL;
        iGpffffb210 = 0;
        if (work->mode == 0 && D_007D3D64[0] != 0 && iGpffffb268 == 0) {
            scriptSize = D_007D3D68[0];
            work->scriptTask = func_0029db50(0xF, D_007D3D64[0], scriptSize, work->roomId - 1);
        }
        work->state++;
    case 2:
        if (work->mode == 0) {
            script = work->scriptTask;
            if (script != 0 && func_00452490((void *)script) == 1) {
                break;
            }
        }
        fieldId = work->fieldId;
        work->file = func_0015ff20(fieldId, work->roomId);
        func_00144c90(work->fieldId, work->roomId);
        func_00144e10(work->mapState);
        if (work->environmentState != 0) {
            func_00144ed0(work->environmentState);
        } else {
            selection = -1;
            selectedEnvironment = 0;
            if (work->mode == 1) {
                initialDay = (s16)func_001060b0();
                condition = (s8)func_00110960(initialDay, func_001060c0() & 0xFF);
                selection = func_00248e20(work->storyGroup, work->storyEntry, condition);
                if (selection != -1) {
                    if ((selection & 0x8000) != 0) {
                        selectedEnvironment = selection & 0x7FF;
                    } else {
                        iGpffffb20c = 1;
                        func_00123aa0((s16)selection);
                    }
                }
            }
            if (selectedEnvironment == 0) {
                if (selection == -1) {
                    day = (s16)func_001060b0();
                    selection = (s8)func_00110960(day, func_001060c0() & 0xFF);
                }
                work->environmentState = func_00154720(work->fieldId, work->roomId, selection);
            } else {
                work->environmentState = selectedEnvironment;
            }
            func_00144ed0(work->environmentState);
        }
        work->state++;
    case 3:
        if (func_00160000(work->file) == 0) {
            break;
        }
        work->file = NULL;
        if (func_00144f60() == 0) {
            break;
        }
        iGpffffb210 = 1;
        if (D_007D3D64[0] != 0) {
            scriptSize = D_007D3D68[0];
            work->scriptTask = func_0029db50(0xF, D_007D3D64[0], scriptSize, work->roomId - 1);
        }
        work->state++;
    case 4:
        script = work->scriptTask;
        if (script != 0 && func_00452490((void *)script) == 1) {
            break;
        }
        if (func_0014a190(work->fieldId, work->roomId) == 0) {
            D_007D2544[0] = func_0014e5e0(NULL, D_005EFF80, -1, D_007E3710[0]);
            D_007D2548[0] = func_0014e5e0(NULL, D_005EFFA0, -1, D_007E3714[0]);
            D_007D254C[0] = func_0014e5e0(NULL, D_005EFFC0, -1, D_007E3718[0]);
        }
        work->state++;
    case 5:
        if (func_0014a190(work->fieldId, work->roomId) == 0 &&
            (func_0014e710((u8 *)D_007D2544[0]) == 0 ||
             func_0014e710((u8 *)D_007D2548[0]) == 0 ||
             func_0014e710((u8 *)D_007D254C[0]) == 0)) {
            break;
        }
        /* The camera task is parented to the active field task. */
        D_007D2514[0] = func_0016e2e0(D_007D2510[0]);
        func_00155070();
        work->state = 8;
    case 8:
        return -1;
    default:
        break;
    }
    return 0;
}
#pragma pop
// FUN_00156630
void func_00156630(u8 *unusedTask)
{
}
/* measured: opt_propagation off preserves the callback work-area base. */
#pragma opt_propagation off
// FUN_00156640
s32 func_00156640(u8 *arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4,
                  s32 arg5, s32 arg6, s32 arg7)
{
    u8 *base;
    s32 temp_21;

    memset(D_007D24F0, 0, 0x20);
    base = D_007D24F0;
    temp_21 = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005EFFE0), 0xF, 0, 0, func_001561a0, func_00156630, (u8 *)(base));
    *(u16 *)(base + 8) = arg1;
    *(u16 *)(base + 0xA) = arg2;
    *(s16 *)(base + 0xC) = arg3;
    *(s16 *)(base + 0xE) = arg4;
    *(s32 *)(base + 4) = arg5;
    *(s32 *)(base + 0x10) = arg6;
    *(s32 *)(base + 0x14) = arg7;
    func_0014eed0(arg1, arg2);
    return temp_21;
}
/* measured: closes the callback work-area base probe. */
#pragma opt_propagation on
// FUN_00156750
void func_00156750(u8 *arg0)
{
    u8 *work;
    u16 value;

    work = *(u8 **)(arg0 + 0x38);
    func_00160440();
    if ((func_00102980() != 9) && (func_00102980() != 0xB) && (func_00102980() != 0xA)) {
        func_00145080();
    }
    value = *(u16 *)(work + 0x18);
    if ((((s32)value >= 0x15) && ((s32)value <= 0x1E)) ||
        ((value == 6) && (value = *(u16 *)(work + 0x1A), value == 1))) {
        func_00145080(value);
    }
}



typedef struct FldTileAttributePair {
    s16 directions;
    s16 attributes;
} FldTileAttributePair;

typedef char FldTileAttributePairSizeCheck[sizeof(FldTileAttributePair) == 4 ? 1 : -1];

static inline u32 fldTileRotateNibble(u32 bits, s32 turns)
{
    u32 shifted = (bits & 0xF) << turns;
    return (shifted & 0xF) | (shifted >> 4);
}

/* Measured with configured b210 -O2: all 1264 bytes match retail.
 * Each saved pair is the actual record displaced by its rotation cycle. */
// FUN_00156800
void func_00156800(void *templateData, u32 directionMask)
{
    extern u8 D_005F0000[];
    FldTileAttributePair savedSmall;
    FldTileAttributePair savedLarge;
    s32 turnCount;
    u8 *tile;
    s32 sourceRow;
    s32 sourceColumn;
    s32 direction;
    s32 smallStep;
    s32 largeStep;
    s32 attributeRow;
    s32 attributeColumn;
    s32 outerStep;
    s32 innerStep;
    u8 width;
    u8 *attribute;
    u8 attributeId;
    u8 *cell;
    u8 firstDirections;
    u8 secondDirections;
    u8 outerCorner;
    u8 innerCorner;

    tile = (u8 *)templateData;
    turnCount = 0;
    for (sourceRow = 0; sourceRow < 3; sourceRow = sourceRow + 1) {
        for (sourceColumn = 0; sourceColumn < 3; sourceColumn = sourceColumn + 1) {
            attributeId = *(tile + sourceRow * 3 + sourceColumn + 4);
            attribute = D_005F0000 + attributeId * 4;
            *(FldTileAttributePair *)(tile + sourceRow * 12 + sourceColumn * 4 + 0x32) = *(FldTileAttributePair *)attribute;
        }
    }
    for (direction = 0; direction < 4; direction = direction + 1) {
        if ((1U << direction) == directionMask) {
            turnCount = direction;
            break;
        }
    }
    width = *(tile + 1);
    if (width != 1 || *(tile + 2) != 1) {
        if (width == 2 && *(tile + 2) == 2) {
            for (smallStep = 0; smallStep < turnCount; smallStep = smallStep + 1) {
                u8 savedFlags;
                savedSmall = *(FldTileAttributePair *)(tile + 0x32);
                *(FldTileAttributePair *)(tile + 0x32) =
                    *(FldTileAttributePair *)(tile + 0x36);
                *(FldTileAttributePair *)(tile + 0x36) =
                    *(FldTileAttributePair *)(tile + 0x42);
                *(FldTileAttributePair *)(tile + 0x42) =
                    *(FldTileAttributePair *)(tile + 0x3E);
                *(FldTileAttributePair *)(tile + 0x3E) = savedSmall;
                savedFlags = *(tile + 0xD);
                *(tile + 0xD) = *(tile + 0xE);
                *(tile + 0xE) = *(tile + 0x11);
                *(tile + 0x11) = *(tile + 0x10);
                *(tile + 0x10) = savedFlags;
            }
        } else if (width == 3 && *(tile + 2) == 3) {
            for (largeStep = 0; largeStep < turnCount * 2; largeStep = largeStep + 1) {
                u8 savedFlags;
                savedLarge = *(FldTileAttributePair *)(tile + 0x32);
                *(FldTileAttributePair *)(tile + 0x32) =
                    *(FldTileAttributePair *)(tile + 0x36);
                *(FldTileAttributePair *)(tile + 0x36) =
                    *(FldTileAttributePair *)(tile + 0x3A);
                *(FldTileAttributePair *)(tile + 0x3A) =
                    *(FldTileAttributePair *)(tile + 0x46);
                *(FldTileAttributePair *)(tile + 0x46) =
                    *(FldTileAttributePair *)(tile + 0x52);
                *(FldTileAttributePair *)(tile + 0x52) =
                    *(FldTileAttributePair *)(tile + 0x4E);
                *(FldTileAttributePair *)(tile + 0x4E) =
                    *(FldTileAttributePair *)(tile + 0x4A);
                *(FldTileAttributePair *)(tile + 0x4A) =
                    *(FldTileAttributePair *)(tile + 0x3E);
                *(FldTileAttributePair *)(tile + 0x3E) = savedLarge;
                savedFlags = *(tile + 0xD);
                *(tile + 0xD) = *(tile + 0xE);
                *(tile + 0xE) = *(tile + 0xF);
                *(tile + 0xF) = *(tile + 0x12);
                *(tile + 0x12) = *(tile + 0x15);
                *(tile + 0x15) = *(tile + 0x14);
                *(tile + 0x14) = *(tile + 0x13);
                *(tile + 0x13) = *(tile + 0x10);
                *(tile + 0x10) = savedFlags;
            }
        }
    }
    /* Rotate both independent direction nibbles for every attribute pair. */
    for (attributeRow = 0; attributeRow < 3; attributeRow = attributeRow + 1) {
        for (attributeColumn = 0; attributeColumn < 3; attributeColumn = attributeColumn + 1) {
            cell = tile + attributeRow * 12 + attributeColumn * 4;
            firstDirections = *(cell + 0x32);
            {
                u32 low;
                u32 high;
                low = fldTileRotateNibble(firstDirections & 0xF, turnCount);
                high = fldTileRotateNibble((firstDirections & 0xF0) >> 4, turnCount);
                *(cell + 0x32) = low | (high << 4);
            }
            secondDirections = *(cell + 0x33);
            {
                u32 low;
                u32 high;
                low = fldTileRotateNibble(secondDirections & 0xF, turnCount);
                high = fldTileRotateNibble((secondDirections & 0xF0) >> 4, turnCount);
                *(cell + 0x33) = low | (high << 4);
            }
        }
    }
    if (*(tile + 1) == 2 && *(tile + 2) == 2) {
        switch (turnCount) {
        case 0:
            break;
        case 1:
            *(s8 *)(tile + 0x16) = -2;
            *(s8 *)(tile + 0x17) = -1;
            break;
        case 2:
            *(s8 *)(tile + 0x16) = -1;
            *(s8 *)(tile + 0x17) = -1;
            break;
        case 3:
            *(s8 *)(tile + 0x16) = -1;
            *(s8 *)(tile + 0x17) = -2;
            break;
        }
    }
    /* A quarter turn advances the outer ring four cells and the inner ring two. */
    for (outerStep = 0; outerStep < turnCount * 4; outerStep = outerStep + 1) {
        outerCorner = *(tile + 24);
        *(tile + 24) = *(tile + 25);
        *(tile + 25) = *(tile + 26);
        *(tile + 26) = *(tile + 27);
        *(tile + 27) = *(tile + 28);
        *(tile + 28) = *(tile + 33);
        *(tile + 33) = *(tile + 38);
        *(tile + 38) = *(tile + 43);
        *(tile + 43) = *(tile + 48);
        *(tile + 48) = *(tile + 47);
        *(tile + 47) = *(tile + 46);
        *(tile + 46) = *(tile + 45);
        *(tile + 45) = *(tile + 44);
        *(tile + 44) = *(tile + 39);
        *(tile + 39) = *(tile + 34);
        *(tile + 34) = *(tile + 29);
        *(tile + 29) = outerCorner;
    }
    for (innerStep = 0; innerStep < turnCount * 2; innerStep = innerStep + 1) {
        innerCorner = *(tile + 30);
        *(tile + 30) = *(tile + 31);
        *(tile + 31) = *(tile + 32);
        *(tile + 32) = *(tile + 37);
        *(tile + 37) = *(tile + 42);
        *(tile + 42) = *(tile + 41);
        *(tile + 41) = *(tile + 40);
        *(tile + 40) = *(tile + 35);
        *(tile + 35) = innerCorner;
    }
}
/* MATCHED: the m2c draft typed arg0 as s16 *, which turned retail's
   row stride of 5 into 10 and the rule stride of 0xC into 0x18; it is a
   u8 *.  Three layout facts finished it: the success half is reached by
   falling out of the 5x5 scan, so it belongs after `return 0` behind a
   label rather than inside the column loop; the second pass needs its own
   counter (a shared one with the scan costs 72 words); and each loop's
   induction variable is zeroed before the invariants beside it, which is
   the comma-initialiser in the three `for` headers. */
// FUN_00156CF0
s32 func_00156cf0(void *arg0, u32 *arg1, u32 *arg2)
{
    u8 *shape;
    u8 *row;
    u8 *rule;
    u8 *board;
    s32 x;
    s32 y;
    s32 saved_y;
    s32 by;
    s32 ry;
    s32 bx;
    s32 rowbase;
    s32 colofs;
    s32 i;
    s32 k;
    s32 j;
    s32 r;
    s32 c;
    u8 cell;

    shape = (u8 *)arg0;
    for (i = 0, y = *arg2; i < shape[2]; i++, y--) {
        for (j = 0, x = *arg1; j < shape[1]; j++, x--) {
            for (r = 0; r < 5; r++) {
                for (c = 0, row = shape + r * 5, ry = y + r; c < 5; c++) {
                    cell = row[c + 0x18];
                    if (cell == 0) {
                        continue;
                    }
                    bx = *(s8 *)(shape + 0x16) + (x + c);
                    by = *(s8 *)(shape + 0x17) + ry;
                    if (cell == 1) {
                        board = (u8 *)func_00155280() + (by << 8) + (bx * 0x10);
                        if (board[0x54] != 0) {
                            goto next_x;
                        }
                    }
                    if (row[c + 0x18] == 2) {
                        if (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) + 0x54) == 1) {
                            goto next_x;
                        }
                        if (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) + 0x64) == 1 &&
                            (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) + 0x6E) & 0x20)) {
                            goto next_x;
                        }
                        if (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) + 0x44) == 1 &&
                            (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) + 0x4E) & 0x80)) {
                            goto next_x;
                        }
                        if (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) + 0x154) == 1 &&
                            (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) + 0x15E) & 0x10)) {
                            goto next_x;
                        }
                        if (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) - 0xAC) == 1 &&
                            (*((u8 *)func_00155280() + (by << 8) + (bx * 0x10) - 0xA2) & 0x40)) {
                            goto next_x;
                        }
                    }
                }
            }
            goto fits;
        next_x:
            ;
        }
    }
    return 0;
fits:
    saved_y = y;
    for (k = 0; k < shape[2]; k++, y++) {
        for (r = 0, bx = x, rule = shape + k * 0xC, rowbase = y << 8; r < shape[1]; r++, bx++) {
            if (y == 0x16 && (rule[r * 4 + 0x32] & 0x40)) {
                return 0;
            }
            if (y == 1 && (rule[r * 4 + 0x32] & 0x10)) {
                return 0;
            }
            if (bx == 0xE && (rule[r * 4 + 0x32] & 0x80)) {
                return 0;
            }
            if (bx == 1 && (rule[r * 4 + 0x32] & 0x20)) {
                return 0;
            }
            colofs = bx * 0x10;
            if (*((u8 *)func_00155280() + rowbase + colofs - 0xAC) != 0) {
                if (*((u8 *)func_00155280() + rowbase + colofs - 0xA2) & 0x40) {
                    if (!(rule[r * 4 + 0x32] & 0x10)) {
                        return 0;
                    }
                } else if (rule[r * 4 + 0x32] & 0x10) {
                    return 0;
                }
            }
            if (*((u8 *)func_00155280() + rowbase + colofs + 0x44) != 0) {
                if (*((u8 *)func_00155280() + rowbase + colofs + 0x4E) & 0x80) {
                    if (!(rule[r * 4 + 0x32] & 0x20)) {
                        return 0;
                    }
                } else if (rule[r * 4 + 0x32] & 0x20) {
                    return 0;
                }
            }
            if (*((u8 *)func_00155280() + rowbase + colofs + 0x154) != 0) {
                if (*((u8 *)func_00155280() + rowbase + colofs + 0x15E) & 0x10) {
                    if (!(rule[r * 4 + 0x32] & 0x40)) {
                        return 0;
                    }
                } else if (rule[r * 4 + 0x32] & 0x40) {
                    return 0;
                }
            }
            if (*((u8 *)func_00155280() + rowbase + colofs + 0x64) != 0) {
                if (*((u8 *)func_00155280() + rowbase + colofs + 0x6E) & 0x20) {
                    if (!(rule[r * 4 + 0x32] & 0x80)) {
                        return 0;
                    }
                } else if (rule[r * 4 + 0x32] & 0x80) {
                    return 0;
                }
            }
        }
    }
    *arg1 = x;
    *arg2 = saved_y;
    return 1;
}
/* Measured with configured b210 -O2: 1004 code bytes and four zero tail
 * bytes match retail. Scoped propagation/common-subexpression controls
 * preserve coordinate reloads and the mask load before occupancy tests.
 * The signed-byte occupied value converts to the board's unsigned byte. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00157310
void func_00157310(u8 *shape, u16 x0, u16 y0, s16 kind)
{
    extern s32 iGpffffb230;
    extern s32 iGpffffb22c;
    extern s32 iGpffffb228;
    extern s32 iGpffffb224;
    s32 placed;
    s32 px;
    s32 py;
    s32 y;
    s32 x;
    s32 rowbase;
    s32 rowSpan;
    s32 colofs;
    s8 occupied;
    u8 *flags;
    u8 *rule;
    u8 *entry;
    s32 r;
    s32 c;
    s32 by;
    s32 bx;
    u8 *row;
    u32 maskValue;

    placed = 0;
    px = x0 & 0xFFFF;
    if (px + shape[1] - 1 >= 0x10) {
        func_0046d730(D_005F05E8, 0x20B);
    }
    py = y0 & 0xFFFF;
    if (py + shape[2] - 1 >= 0x18) {
        func_0046d730(D_005F05E8, 0x20C);
    }
    *((u8 *)func_00155280() + (y0 << 8) + (x0 * 0x10) + 0x55) = 1;
    for (y = 0; y < shape[2]; y++) {
        for (x = 0, rowbase = (py + y) << 8, rowSpan = y * 3, flags = shape + rowSpan, rule = shape + rowSpan * 4; x < shape[1]; x++) {
            colofs = (px + x) * 0x10;
            if (*((u8 *)func_00155280() + rowbase + colofs + 0x54) == 0) {
                row = shape + (y - *(s8 *)(shape + 0x17)) * 5;
                maskValue = row[(x - *(s8 *)(shape + 0x16)) + 0x18];
                occupied = 1;
                if (maskValue == occupied) {
                    colofs = (px + x) * 0x10;
                    *((u8 *)func_00155280() + rowbase + colofs + 0x54) = occupied;
                    *((u8 *)func_00155280() + rowbase + colofs + 0x55) |= flags[x + 0xD];
                    entry = rule + x * 4;
                    *((u8 *)func_00155280() + rowbase + colofs + 0x5E) = entry[0x32];
                    *((u8 *)func_00155280() + rowbase + colofs + 0x5A) = shape[1];
                    *((u8 *)func_00155280() + rowbase + colofs + 0x5B) = shape[2];
                    *((u8 *)func_00155280() + rowbase + colofs + 0x58) = *(s8 *)(shape + 0);
                    *((u8 *)func_00155280() + rowbase + colofs + 0x59) = (u8)kind;
                    *((u8 *)func_00155280() + rowbase + colofs + 0x5F) = entry[0x33];
                    placed = 1;
                }
            }
        }
    }
    if (placed == 1) {
        for (r = 0; r < 5; r++) {
            for (c = 0, by = py + r, row = shape + r * 5; c < 5; c++) {
                if (*(s8 *)(shape + 0x17) + by < 0x18) {
                    bx = px + c;
                    if (*(s8 *)(shape + 0x16) + bx < 0x10) {
                        if (*((u8 *)func_00155280() + ((*(s8 *)(shape + 0x17) + by) << 8) + ((*(s8 *)(shape + 0x16) + bx) * 0x10) + 0x54) == 0 &&
                            row[c + 0x18] != 0) {
                            *((u8 *)func_00155280() + ((*(s8 *)(shape + 0x17) + by) << 8) + ((*(s8 *)(shape + 0x16) + bx) * 0x10) + 0x54) = 2;
                        }
                    }
                }
            }
        }
    }
    iGpffffb230 += 1;
    if (*(s8 *)(shape + 0) == 2) {
        iGpffffb228 += 1;
    }
    if (*(s8 *)(shape + 0) >= 9) {
        iGpffffb22c += 1;
    }
    iGpffffb224 += shape[1] * shape[2];
}
#pragma pop
/* Measured: 684/688 bytes, 12 resolved call relocations and four zero tail bytes.
 * Capture exits before output writes; reload categories after earlier recursion. */
// FUN_00157700
void func_00157700(s32 x, s32 y, s32 incoming, s32 depth,
                  s32 limit, s32 *found_two, s32 *found_high)
{
    s32 exits;
    s32 next_depth;
    s32 right_depth;

    if (depth < limit) {
        if (((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x54] == 1) {
            exits = ~incoming & ((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x5E];
            if (((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x58] == 2) {
                *found_two = 1;
            }
            if (((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x58] >= 9) {
                *found_high = 1;
            }
            if (exits & 1) {
                func_00157700(x, y - 1, 4, depth + 1, limit, found_two, found_high);
            }
            if (exits & 2) {
                if ((((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x58] == 7 ||
                     ((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x58] == 8) &&
                    limit == 4) {
                    next_depth = depth;
                } else {
                    next_depth = depth + 1;
                }
                func_00157700(x - 1, y, 8, next_depth, limit, found_two, found_high);
            }
            if (exits & 4) {
                func_00157700(x, y + 1, 1, depth + 1, limit, found_two, found_high);
            }
            if (exits & 8) {
                if ((((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x58] == 7 ||
                     ((u8 *)func_00155280() + y * 0x100 + x * 0x10)[0x58] == 8) &&
                    limit == 4) {
                    right_depth = depth;
                } else {
                    right_depth = depth + 1;
                }
                func_00157700(x + 1, y, 2, right_depth, limit, found_two, found_high);
            }
        }
    }
}
/* measured: opt_propagation off keeps the special-call $a3 load before the coordinate masks (nd 9 -> 0). */
#pragma opt_propagation off
// FUN_001579B0
void func_001579b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 tile[0x56];
    u8 *work;
    u8 *choice_ptr;
    s16 *src;
    s16 *dst;
    s32 copy_count;
    s32 main_cell_offset;
    u32 prop_cell_offset;
    u32 temp_x;
    u32 temp_y;
    s32 flag_a;
    s32 flag_b;
    s32 mode;
    s8 template_id;
    s16 copy_value;
    u32 choice;
    u32 direction;
    u32 random_value;
    u32 attempt;
    u32 found;
    u32 x_offset;
    u32 y_offset;
    s32 y;
    s32 x;
    u32 edge;
    s32 previous_y;
    s32 next_y;
    s32 previous_x;
    s32 next_x;
    u32 row_offset;

    work = (u8 *)func_00155280();
    work = wg0015_add_ptr(work, arg1 << 8);
    work = wg0015_add_ptr(work, arg0 << 4);
    if (work[0x54] != 0) {
        return;
    }
    if (D_00764328 == 1) {
        return;
    }

    work = (u8 *)func_00155280();
    if (arg0 == work[0x46]) {
        work = (u8 *)func_00155280();
        if (arg1 == work[0x47]) {
            mode = D_0076432C;
            template_id = *(s8 *)(D_005F0591 + mode * 0xC +
                                  D_005F0590[mode * 0xC]);
            src = (s16 *)(D_005F0080 + template_id * 0x56);
            dst = (s16 *)tile;
            copy_count = 0x2B;
copy_special:
            copy_value = *src;
            src++;
            copy_count--;
            *dst = copy_value;
            dst++;
            if (copy_count > 0) {
                goto copy_special;
            }
            work = (u8 *)func_00155280();
            func_00156800(tile, 1U << work[0x49]);
            work = (u8 *)func_00155280();
            wg0015_place_special(work[0x49], arg0, arg1, tile);
            goto propagate;
        }
    }

    D_00764324 = 0;
    flag_a = 0;
    flag_b = 0;
    main_cell_offset = (arg3 << 8) + (arg2 << 4);
main_loop:
    D_00764324++;
    if (D_00764324 > 0x32) {
        D_00764328 = 1;
        return;
    }

    if ((arg2 == arg0) && (arg3 < arg1)) {
        func_00157700(arg0, arg1 - 1, 4, 0, 5, &flag_a, &flag_b);
    }
    if ((arg2 < arg0) && (arg3 == arg1)) {
        func_00157700(arg0 - 1, arg1, 8, 0, 5, &flag_a, &flag_b);
    }
    if ((arg2 == arg0) && (arg1 < arg3)) {
        func_00157700(arg0, arg1 + 1, 1, 0, 5, &flag_a, &flag_b);
    }
    if ((arg0 < arg2) && (arg3 == arg1)) {
        func_00157700(arg0 + 1, arg1, 2, 0, 5, &flag_a, &flag_b);
    }

    work = (u8 *)func_00155280();
    if (work[main_cell_offset + 0x58] == 3) {
        mode = *(s32 *)iGpffff9db0;
        if ((mode == 0x2E) || (mode == 0x42) ||
            (mode == 0x2C) || (mode == 0x40)) {
            flag_a = 1;
        }
    }

    random_value = RpRandom();
    if (((random_value % 100) < 0x1E) && (flag_a == 0)) {
        choice = 1;
        direction = RpRandom() & 3;
        goto try_choice;
    }

    work = (u8 *)func_00155280();
    if (work[main_cell_offset + 0x58] == 2) {
        mode = *(s32 *)iGpffff9db0;
        if ((mode == 0x2E) || (mode == 0x42) ||
            (mode == 0x2C) || (mode == 0x40)) {
            choice = 0;
            direction = RpRandom() & 3;
            goto try_choice;
        }
    }

    if (D_0076432C == 0) {
        work = (u8 *)func_00155280();
        if (work[main_cell_offset + 0x58] == 2) {
            choice = 0;
            direction = RpRandom() & 3;
            goto try_choice;
        }
    }

    work = (u8 *)func_00155280();
    if (work[main_cell_offset + 0x58] < 9) {
        goto choose_limited;
    }
    mode = D_0076432C;

    random_value = RpRandom();
    choice = random_value % (u32)(D_005F0590[mode * 0xC] - 2);
    if (mode == 0) {
        choice = 0;
    }
    direction = RpRandom() & 3;
    if (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 6) {
        goto main_loop;
    }
    goto try_choice;

choose_limited:
    mode = D_0076432C;
    random_value = RpRandom();
    choice = random_value % (u32)(D_005F0590[mode * 0xC] - 2);
    if (mode == 0) {
        random_value = D_00764314;
        work = (u8 *)func_00155280();
        if (random_value < ((u32)work[0x4A] >> 1)) {
            if ((choice == 3) || (choice == 6)) {
                goto main_loop;
            }
        }
    }

    random_value = RpRandom();
    if (((random_value % 100) < 0x32) && (flag_b == 0)) {
        choice = D_005F0590[D_0076432C * 0xC] - 2;
    }
    direction = RpRandom() & 3;
    if (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 6) {
        goto main_loop;
    }
    if ((choice == 1) && (flag_a == 1)) {
        goto main_loop;
    }

    work = (u8 *)func_00155280();
    if ((work[main_cell_offset + 0x58] == 3) &&
        (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 3)) {
        goto main_loop;
    }
    work = (u8 *)func_00155280();
    if ((work[main_cell_offset + 0x58] == 7) &&
        (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 7)) {
        goto main_loop;
    }
    work = (u8 *)func_00155280();
    if ((work[main_cell_offset + 0x58] == 8) &&
        (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 8)) {
        goto main_loop;
    }

try_choice:
    found = 0;
    attempt = 0;
    choice_ptr = D_005F0590 + choice;
    goto attempt_test;
attempt_body:
    mode = D_0076432C;
    template_id = *(s8 *)(choice_ptr + mode * 0xC + 2);
    src = (s16 *)(D_005F0080 + template_id * 0x56);
    dst = (s16 *)tile;
    copy_count = 0x2B;
copy_candidate:
    copy_value = *src;
    src++;
    copy_count--;
    *dst = copy_value;
    dst++;
    if (copy_count > 0) {
        goto copy_candidate;
    }
    func_00156800(tile, 1U << direction);
    temp_x = arg0;
    temp_y = arg1;
    if (func_00156cf0(tile, &temp_x, &temp_y) == 1) {
        func_00157310(tile, (u16)temp_x, (u16)temp_y, (s16)direction);
        found = 1;
        arg0 = temp_x;
        arg1 = temp_y;
        goto attempt_done;
    }
    direction++;
    if (direction >= 4) {
        direction = 0;
    }
    attempt++;
attempt_test:
    if (attempt < 4) {
        goto attempt_body;
    }
attempt_done:
    if (found != 0) {
        goto propagate;
    }
    if (choice == 1) {
        flag_a = 1;
    }
    if (choice < (u32)(D_005F0590[D_0076432C * 0xC] - 2)) {
        goto main_loop;
    }
    flag_b = 1;
    goto main_loop;

propagate:
    y_offset = 0;
    goto y_test;
y_body:
    x_offset = 0;
    y = arg1 + y_offset;
    row_offset = y << 8;
    previous_y = y - 1;
    next_y = y + 1;
    goto x_test;
x_body:
    edge = 0;
    x = arg0 + x_offset;
    prop_cell_offset = row_offset + (x << 4);
    previous_x = x - 1;
    next_x = x + 1;
    goto edge_test;
edge_body:
    work = (u8 *)func_00155280();
    if ((work[prop_cell_offset + 0x5E] &
         (1U << (edge + 4))) != 0) {
        switch (edge) {
        case 0:
            func_001579b0(x, previous_y, x, y);
            break;
        case 1:
            func_001579b0(previous_x, y, x, y);
            break;
        case 2:
            func_001579b0(x, next_y, x, y);
            break;
        case 3:
            func_001579b0(next_x, y, x, y);
            break;
        }
    }
    edge++;
edge_test:
    if (edge < 4) {
        goto edge_body;
    }
    x_offset++;
x_test:
    if (x_offset < tile[1]) {
        goto x_body;
    }
    y_offset++;
y_test:
    if (y_offset < tile[2]) {
        goto y_body;
    }
}
/* measured: closes the opt_propagation bracket for func_001579b0. */
#pragma opt_propagation on
/* Configured b210 -O2: 1240 exact code bytes and eight zero-tail bytes.
 * The room list supplies its own count and following start-template ID.
 * Copy all 43 signed halfwords before rotating the complete template.
 * Tail-tested border passes retain each word-valued wall state across
 * both board lookups. Scoped propagation preserves byte-coordinate
 * snapshots and the fresh area-count reads in the retry checks. */
#pragma push
#pragma opt_propagation off
// FUN_001582F0
void func_001582f0(s32 arg0, s32 arg1, s32 arg2)
{
    extern void RpRandomSeed(s32 seed);
    extern s32 func_0043c6a0(s32 value);
    extern u8 D_005F05B8[];
    extern u8 D_005F0600[];
    extern u8 D_005F0620[];
    extern s32 iGpffffb240;
    extern s32 iGpffffb1a0;
    extern s32 iGpffffb214;
    extern s32 iGpffffb220;
    extern s32 iGpffffb238;
    extern s32 iGpffffb230;
    extern s32 iGpffffb22c;
    extern s32 iGpffffb228;
    extern s32 iGpffffb224;
    extern s32 iGpffffb23c;
    s16 buf[43];
    u32 u4;
    u32 u8v;
    u8 *t;
    s16 *tab;
    u8 *roomSet;
    s16 *dst;
    s32 n;
    u32 i;
    u32 borderIndex;
    s32 bestx;
    s32 besty;
    u32 maxv;
    u32 j;
    s32 r1;
    s32 r2;
    u8 b0;
    u8 r;
    s32 border;
    s32 offset;
    s16 copyValue;
    s32 startX;
    u32 areaCount;

    if (arg1 == 0) {
        iGpffffb240 = iGpffffb1a0;
    } else {
        iGpffffb240 = arg1;
    }
    if (iGpffffb214 != 0) {
        iGpffffb240 = iGpffffb214;
    }
    RpRandomSeed(iGpffffb240);
    iGpffffb220 = 0;
    iGpffffb238 = 1;
    while (iGpffffb238 == 1) {
        iGpffffb220 = iGpffffb220 + 1;
        iGpffffb238 = 0;
        iGpffffb230 = 0;
        iGpffffb22c = 0;
        iGpffffb228 = 0;
        iGpffffb224 = 0;
        t = (u8 *)func_00155280();
        *(t + 0x44) = 0;
        t = (u8 *)func_00155280();
        *(t + 0x45) = 0;
        iGpffffb23c = D_005F05B8[arg0];
        t = (u8 *)func_00155280();
        memset(t + 0x54, 0, 6144);
        borderIndex = 0;
        goto border_columns_test;
border_columns_body:
        offset = borderIndex * 0x10;
        border = 2;
        t = (u8 *)func_00155280();
        *(t + offset + 0x54) = border;
        t = (u8 *)func_00155280();
        *(t + offset + 0x1754) = border;
        borderIndex += 1;
border_columns_test:
        if (borderIndex < 0x10) {
            goto border_columns_body;
        }
        borderIndex = 0;
        goto border_rows_test;
border_rows_body:
        offset = borderIndex * 0x100;
        border = 2;
        t = (u8 *)func_00155280();
        *(t + offset + 0x54) = border;
        t = (u8 *)func_00155280();
        *(t + offset + 0x144) = border;
        borderIndex += 1;
border_rows_test:
        if (borderIndex < 0x18) {
            goto border_rows_body;
        }
        do {
            r = (RpRandom() % 0xB) + 2;
            t = (u8 *)func_00155280();
            *(t + 0x46) = (u8)r;
            u4 = r & 0xFF;
            r = (RpRandom() % 0x13) + 2;
            t = (u8 *)func_00155280();
            *(t + 0x47) = (u8)r;
            u8v = r & 0xFF;
            b0 = (u8)(RpRandom() & 3);
            t = (u8 *)func_00155280();
            *(t + 0x49) = b0;
            roomSet = D_005F0590 + iGpffffb23c * 12;
            tab = (s16 *)(D_005F0080 + *(s8 *)(roomSet + roomSet[0] + 1) * 0x56);
            dst = buf;
            n = 43;
            do {
                copyValue = *tab;
                tab = tab + 1;
                n = n - 1;
                *dst = copyValue;
                dst = dst + 1;
            } while (n > 0);
            t = (u8 *)func_00155280();
            func_00156800(buf, 1U << *(t + 0x49));
        } while (func_00156cf0(buf, &u4, &u8v) == 0);
        b0 = (u8)u4;
        t = (u8 *)func_00155280();
        *(t + 0x46) = b0;
        b0 = (u8)u8v;
        t = (u8 *)func_00155280();
        *(t + 0x47) = b0;
        t = (u8 *)func_00155280();
        startX = *(t + 0x46);
        t = (u8 *)func_00155280();
        func_001579b0(startX, *(t + 0x47), 0, 0);
        maxv = 0;
        for (j = 0; j < 0x18; j = j + 1) {
            for (i = 0; i < 0x10; i = i + 1) {
                offset = i * 0x10;
                t = (u8 *)func_00155280();
                if (*(t + j * 0x100 + offset + 0x54) == 1) {
                    t = (u8 *)func_00155280();
                    if (*(t + j * 0x100 + offset + 0x58) == 5) {
                        t = (u8 *)func_00155280();
                        r1 = func_0043c6a0(*(t + 0x46) - i);
                        t = (u8 *)func_00155280();
                        r2 = func_0043c6a0(*(t + 0x47) - j);
                        if (maxv < (u32)(r1 + r2)) {
                            bestx = i;
                            besty = j;
                            maxv = r1 + r2;
                        }
                    }
                }
            }
        }
        if (maxv != 0) {
            b0 = (u8)bestx;
            t = (u8 *)func_00155280();
            *(t + 0x44) = b0;
            b0 = (u8)besty;
            t = (u8 *)func_00155280();
            *(t + 0x45) = b0;
            border = 6;
            t = (u8 *)func_00155280();
            *(t + besty * 0x100 + bestx * 0x10 + 0x58) = border;
        } else {
            iGpffffb238 = 1;
        }
        if (iGpffffb228 == 0) {
            iGpffffb238 = 1;
        }
        areaCount = iGpffffb224;
        t = (u8 *)func_00155280();
        if ((areaCount > *(t + 0x4B)) ||
            (areaCount = iGpffffb224, t = (u8 *)func_00155280(),
             areaCount < (u32)*(t + 0x4A))) {
            iGpffffb238 = 1;
        }
        if ((u32)iGpffffb22c < 2U) {
            iGpffffb238 = 1;
        }
    }
    func_00440b68(D_005F0600, iGpffffb224, iGpffffb230, iGpffffb220);
    func_00440b68(D_005F0620, iGpffffb22c, iGpffffb228, iGpffffb224);
}

#pragma pop
#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"
/* Serialized light records occupy 32 bytes. Creators convert their legacy
 * f32 pointer argument back to SVec3 and copy the complete object. Pass
 * complete SVec3 addresses, never an address of one scalar member. */
typedef struct FieldSerializedLightRecord {
    u8 header[4];
    FieldRgba8 color;
    SVec3 position;
    f32 parameters[3];
} FieldSerializedLightRecord;
/* Complete clone and child layouts from the field resource provider. */
typedef struct {
    u16 type;
    u16 flags;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} k_fldSubEntry;

typedef struct {
    u32 flags;
    s16 field_04;
    s16 field_06;
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    u32 count1;
    s32 arr1[32];
    s32 arr2[32];
    u32 count2;
    k_fldSubEntry entries[96];
    s32 field_a20;
    RwV3d scale;
} k_fldResource;

typedef struct RuntimeVec3 { f32 x; f32 y; f32 z; } RuntimeVec3;
typedef struct Resrc Resrc;
/* Recovered placement uses full coordinate words for world conversion and
 * their low halfwords for grid addressing. Each serialized group retains its
 * original mode checks, record stride, vector transform and creation call.
 * Native b210 -O2 with this scoped level-1 model emits 4596 exact bytes;
 * the remaining 12 retail bytes are zero alignment. Plain coordinate words
 * preserve the actual snapshot stores and complete 0x150-byte frame. */
#pragma push
#pragma optimization_level 1
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_001587D0
void func_001587d0(u16 arg0, u32 arg1, u32 arg2)
{
    extern u8 D_005F0590[];
    extern u8 D_005F0591[];
    extern u8 D_005F05E8[];
    extern u8 D_00756510[];
    extern s32 D_0076432C;
    extern u8 *iGpffff9db0;
    extern s32 *func_00155280(void);
    extern k_fldResource *func_001534a0(k_fldResource *src, void *arg1, u32 arg2);
    extern s32 func_00145ac0(u16 arg0, s32 arg1);
    extern s32 func_00145ba0(u16 arg0, s32 arg1);
    extern s32 func_00145c80(u16 arg0, s32 arg1);
    extern s32 func_00145fc0(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_00146080(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_00146140(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_00146200(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_001462c0(u16 arg0, f32 *arg1, f32 fparg0);
    extern void func_00149ea0(void);
    extern void func_0014a0f0(u16 arg0, u32 arg1);
    extern s32 func_0014a200(void);
    extern s32 func_0014a270(void);
    extern u16 func_0014b510(s32 arg0);
    extern Resrc *MT_Scene_GetRes(u16 resTypeId);
    extern void func_0015f720(RuntimeVec3 *vertices, const RuntimeVec3 *translation, f32 width, f32 depth, f32 angle);
    extern void *RwMatrixRotate(void *matrix, const void *axis, f32 angle, s32 combine);
    extern void *func_003e42a0(void *out, const void *in, const void *matrix);
    extern void *func_003e0f80(void);
    extern s32 func_003e0f40(void *matrix);
    extern void func_0046d730(const void *file, s32 line);
  s32 templateKind;
  s32 volumeId;
  u32 templateCount;
  s32 checkedY;
  s32 checkedX;
  u8 *grid;
  s32 validExtent;
  s32 validTemplate;
  s32 cloneRow;
  s32 cloneColumn;
  u32 rotation;
  u32 childType;
  u16 resourceId;
  u16 *resourceSlot;
  f32 worldScale;
  k_fldResource *clonedModel;
  s32 columnIndex;
  u8 *parentUnit;
  u32 templateIndex;
  s32 occupiedRowOffset;
  u32 childIndex;
  u32 volumeIndex;
  u32 recordIndex;
  u8 *record;
  s32 rowIndex;
  s32 worldColumnOffset;
  s32 templateOffset;
  s32 occupiedColumnOffset;
  f32 worldCoordinate;
  f32 angle;
  RwV3d worldPosition;
  SVec3 point_20;
  SVec3 point_30;
  SVec3 point_40;
  SVec3 point_50;
  SVec3 point_60;
  u16 placedResourceIds [4];
  SVec3 point_78;
  enum { c10000 = 0x10000, c10001 = 0x10001, c10002 = 0x10002 };
  
  /* These values belong to the placement operation. templateScan first
   * carries the world-row displacement, then the template-list index.
   * gridOffset gains rowOffset once and survives all record groups. */
  {
  s32 rowOffset;
  s32 gridOffset;
  u32 placementX;
  u32 placementY;
  u32 templateScan;
  placementX = arg1;
  placementY = arg2;
  templateIndex = 0xffffffff;
  rowOffset = (placementY & 0xffff) * 0x100;
  gridOffset = (placementX & 0xffff) * 0x10;
  grid = (u8 *)func_00155280();
  if ((*(u8 *)(grid + rowOffset + gridOffset + 0x54) == '\x01') &&
     (grid = (u8 *)func_00155280(), (*(u8 *)(grid + rowOffset + gridOffset + 0x55) & 0xf) != 0)) {
    checkedX = (s32)(placementX & 0xffff);
    grid = (u8 *)func_00155280();
    validExtent = (s32)(checkedX + *(u8 *)(grid + rowOffset + gridOffset + 0x5a) - 1) < 0x10;
    if (!validExtent) {
      func_0046d730(D_005F05E8,0x40d);
    }
    checkedY = (s32)(placementY & 0xffff);
    grid = (u8 *)func_00155280();
    validExtent = (s32)(checkedY + *(u8 *)(grid + rowOffset + gridOffset + 0x5b) - 1) < 0x18;
    if (!validExtent) {
      func_0046d730(D_005F05E8,0x40e);
    }
    templateScan = (placementY & 0xffff) * 0x100;
    worldColumnOffset = (placementX & 0xffff) * 0x10;
    worldScale = 1200.0f;
    worldCoordinate = (f32)(u32)placementX;
    grid = (u8 *)func_00155280();
    worldPosition.x = worldScale * worldCoordinate + (f32)(s32)(*(u8 *)(grid + templateScan + worldColumnOffset + 0x5a) - 1) * 600.0f
    ;
    grid = (u8 *)func_00155280();
    worldPosition.y = (f32)(s32)*(s8 *)(grid + templateScan + worldColumnOffset + 0x5d) * 300.0f;
    worldScale = 1200.0f;
    worldCoordinate = (f32)(u32)placementY;
    grid = (u8 *)func_00155280();
    worldPosition.z = worldScale * worldCoordinate + (f32)(s32)(*(u8 *)(grid + templateScan + worldColumnOffset + 0x5b) - 1) * 600.0f;
    templateCount = D_005F0590[D_0076432C * 0xc];
    if (func_0014a270() != 0) {
      templateCount = D_005F0591[D_0076432C * 0xc];
    }
    templateScan = 0;
    gridOffset = wg0035_add_offset((u32)rowOffset, (u32)gridOffset);
    while (templateScan < templateCount) {
      templateKind = *(s8 *)(D_005F0590 + D_0076432C * 0xc + templateScan + 2);
      grid = (u8 *)func_00155280();
      if (templateKind == *(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x58)) {
        templateIndex = templateScan;
        break;
      }
      templateScan = templateScan + 1;
    }
    validTemplate = templateIndex < templateCount;
    if (!validTemplate) {
      func_0046d730(D_005F05E8,0x42a);
    }
    cloneRow = (u16)placementY * 0x100;
    cloneColumn = (u16)placementX * 0x10;
    templateOffset = templateIndex * 4;
    grid = (u8 *)func_00155280();
    rotation = (u16)((*(u8 *)(grid + cloneRow + cloneColumn + 0x59) + 4) % 4);
    clonedModel = func_001534a0((k_fldResource *)(s32)*(u32 *)(wg0035_add_offset((u32)templateOffset, (u32)iGpffff9db0) + 0x28), &worldPosition, rotation);
    resourceId = (u16)func_00145c80(arg0,(s32)clonedModel);
    parentUnit = (u8 *)MT_Scene_GetRes(resourceId);
    func_0014a0f0((u16)resourceId,1);
    func_00149ea0();
    for (rowIndex = 0; grid = (u8 *)func_00155280(), rowIndex < (s32)(u32)*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x5b);
        rowIndex = rowIndex + 1) {
      columnIndex = 0;
      occupiedRowOffset = (checkedY + rowIndex) * 0x100;
      for (; grid = (u8 *)func_00155280(), columnIndex < (s32)(u32)*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x5a);
          columnIndex = columnIndex + 1) {
        occupiedColumnOffset = (checkedX + columnIndex) * 0x10;
        grid = (u8 *)func_00155280();
        *(u16 *)((u8 *)wg0035_add_offset((u32)occupiedRowOffset, (u32)grid) + occupiedColumnOffset + 0x56) = (u16)resourceId;
        grid = (u8 *)func_00155280();
        {
          u8 *cell = (u8 *)wg0035_add_offset((u32)occupiedRowOffset, (u32)grid) + occupiedColumnOffset;
          cell[0x5c] = 1;
        }
      }
    }
    /* For unrecognized child kinds, retail retains the preceding resource ID. */
    for (childIndex = 0; childIndex < clonedModel->count2; childIndex = childIndex + 1) {
      u8 *child = (u8 *)clonedModel + childIndex * 0x18;
      childType = ((k_fldSubEntry *)(child + 0x120))->type;
      if (childType == 0) {
        u8 *unit;
        resourceId = func_00145ac0(func_0014b510(10),((k_fldSubEntry *)(child + 0x120))->field_c);
        unit = (u8 *)MT_Scene_GetRes(resourceId);
        *(u32 *)(unit + 0x140) = (u32)parentUnit;
        if ((((k_fldSubEntry *)(child + 0x120))->flags & 2) != 0) {
          *(u32 *)(unit + 0x150) = 1;
        }
      }
      else if (childType == 1) {
        resourceId = func_00145ba0(func_0014b510(0xb),((k_fldSubEntry *)(child + 0x120))->field_10);
        child = (u8 *)MT_Scene_GetRes(resourceId);
        *(u32 *)(child + 0x140) = (u32)parentUnit;
      }
      func_0014a0f0((u16)resourceId,1);
    }
    clonedModel->count2 = 0;
    if (*(s32 *)(*(s32 *)(wg0035_add_offset((u32)templateOffset, (u32)iGpffff9db0) + 0x28) + 0xa40) != 0) {
      u32 *matrix;
      s32 cornerIndex;
      u8 *data;
      u32 format;
      u32 versionBase;
      matrix = (u32 *)func_003e0f80();
      data = (u8 *)*(s32 *)(*(s32 *)(wg0035_add_offset((u32)templateOffset, (u32)iGpffff9db0) + 0x28) + 0xa40);
      format = *(u32 *)(data + 4);
      versionBase = 0x10000;
      if (format == versionBase) {
        record = data + 0x28;
      }
      else if (format == (versionBase | 1)) {
        record = data + 0x30;
      }
      else if (format == (versionBase | 2)) {
        record = data + 0x38;
      }
      else {
        record = data + 0x48;
      }
      for (volumeIndex = 0; volumeIndex < *(u32 *)(data + 8);
          volumeIndex = volumeIndex + 1, record = record + 0x20) {
        u8 *volumeUnit;
        if ((func_0014a200() == 1) || (func_0014a270() == 1)) {
          grid = (u8 *)func_00155280();
          if (*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x58) == '\x06') {
            volumeId = 0x3fe;
          }
          else {
            volumeId = 0x3ff;
          }
          volumeUnit = (u8 *)MT_Scene_GetRes((u16)func_00145d60(volumeId, (f32 *)&((FieldSerializedLightRecord *)record)->position, ((FieldSerializedLightRecord *)record)->parameters[0],
                                 ((FieldSerializedLightRecord *)record)->parameters[1], ((FieldSerializedLightRecord *)record)->parameters[2], ((FieldSerializedLightRecord *)record)->color));
          func_0015f720((RuntimeVec3 *)(volumeUnit + 0x15c),(const RuntimeVec3 *)(volumeUnit + 0x144),*(f32 *)(volumeUnit + 0x150)
                        ,*(f32 *)(volumeUnit + 0x154),*(f32 *)(volumeUnit + 0x158));
          for (cornerIndex = 0; cornerIndex < 4; cornerIndex = cornerIndex + 1) {
            f32 cornerAngle;
            u8 *cornerBase;
            grid = (u8 *)func_00155280();
            cornerAngle = (f32)((*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x59) + 4) % 4) * 90.0f;
            *matrix = matrix[5] = matrix[10] = 0x3f800000;
            matrix[4] = 0;
            matrix[2] = 0;
            matrix[1] = 0;
            matrix[9] = 0;
            matrix[8] = 0;
            matrix[6] = 0;
            matrix[0xe] = 0;
            matrix[0xd] = 0;
            matrix[0xc] = 0;
            matrix[3] = matrix[3] | 0x20003;
            RwMatrixRotate(matrix, D_00756510, cornerAngle, 2);
            cornerBase = volumeUnit + cornerIndex * 0xc;
            {
              RwV3d *corner = (RwV3d *)(cornerBase + 0x15c);
              func_003e42a0(corner, corner, matrix);
            }
            *(f32 *)(cornerBase + 0x15c) = *(f32 *)(cornerBase + 0x15c) + worldPosition.x;
            *(f32 *)(cornerBase + 0x160) = *(f32 *)(cornerBase + 0x160) + worldPosition.y;
            *(f32 *)(cornerBase + 0x164) = *(f32 *)(cornerBase + 0x164) + worldPosition.z;
          }
        }
      }
      for (recordIndex = 0; recordIndex < *(u32 *)(data + 0x10); recordIndex = recordIndex + 1, record = record + 0x14) {
        if ((func_0014a200() == 1) || (func_0014a270() == 1)) {
          point_20 = *(SVec3 *)(record + 4);
          grid = (u8 *)func_00155280();
          angle = (f32)((*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x59) + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &point_20; func_003e42a0(position, position, matrix); }
          point_20.x = point_20.x + worldPosition.x;
          point_20.y = point_20.y + worldPosition.y;
          point_20.z = point_20.z + worldPosition.z;
          angle = angle + *(f32 *)(record + 0x10);
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          func_00145fc0(0x3ff,(f32 *)&point_20,angle);
        }
      }
      for (recordIndex = 0; recordIndex < *(u32 *)(data + 0x18); recordIndex = recordIndex + 1, record = record + 0x14) {
        if (func_0014a200() == 1) {
          point_30 = *(SVec3 *)(record + 4);
          grid = (u8 *)func_00155280();
          angle = (f32)((*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x59) + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &point_30; func_003e42a0(position, position, matrix); }
          point_30.x = point_30.x + worldPosition.x;
          point_30.y = point_30.y + worldPosition.y;
          point_30.z = point_30.z + worldPosition.z;
          angle = angle + *(f32 *)(record + 0x10);
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          func_00146080(func_0014b510(0xf),(f32 *)&point_30,angle);
        }
      }
      for (recordIndex = 0; recordIndex < *(u32 *)(data + 0x20); recordIndex = recordIndex + 1, record = record + 0x14) {
        if (func_0014a200() == 1) {
          point_40 = *(SVec3 *)(record + 4);
          grid = (u8 *)func_00155280();
          angle = (f32)((*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x59) + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &point_40; func_003e42a0(position, position, matrix); }
          point_40.x = point_40.x + worldPosition.x;
          point_40.y = point_40.y + worldPosition.y;
          point_40.z = point_40.z + worldPosition.z;
          angle = angle + *(f32 *)(record + 0x10);
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          func_00146140(func_0014b510(0x10),(f32 *)&point_40,angle);
        }
      }
      if (c10000 < *(u32 *)(data + 4)) {
        for (recordIndex = 0; recordIndex < *(u32 *)(data + 0x28); recordIndex = recordIndex + 1, record = record + 0x14) {
          if (func_0014a200() == 1) {
            point_50 = *(SVec3 *)(record + 4);
            grid = (u8 *)func_00155280();
            angle = (f32)((*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x59) + 4) % 4) * 90.0f;
            *matrix = matrix[5] = matrix[10] = 0x3f800000;
            matrix[4] = 0;
            matrix[2] = 0;
            matrix[1] = 0;
            matrix[9] = 0;
            matrix[8] = 0;
            matrix[6] = 0;
            matrix[0xe] = 0;
            matrix[0xd] = 0;
            matrix[0xc] = 0;
            matrix[3] = matrix[3] | 0x20003;
            RwMatrixRotate(matrix, D_00756510, angle, 2);
            { SVec3 *position = &point_50; func_003e42a0(position, position, matrix); }
            point_50.x = point_50.x + worldPosition.x;
            point_50.y = point_50.y + worldPosition.y;
            point_50.z = point_50.z + worldPosition.z;
            angle = angle + *(f32 *)(record + 0x10);
            { f32 f360 = 360.0f;
            for (; angle > f360;
                angle = angle - f360) {
            }
            }
            func_00146200(func_0014b510(0x11),(f32 *)&point_50,angle);
          }
        }
      }
      if (c10001 < *(u32 *)(data + 4)) {
        for (recordIndex = 0; recordIndex < *(u32 *)(data + 0x30); recordIndex = recordIndex + 1, record = record + 0x20) {
          u8 *lightUnit;
          point_60 = ((FieldSerializedLightRecord *)record)->position;
          grid = (u8 *)func_00155280();
          angle = (f32)((*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x59) + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &point_60; func_003e42a0(position, position, matrix); }
          point_60.x = point_60.x + worldPosition.x;
          point_60.y = point_60.y + worldPosition.y;
          point_60.z = point_60.z + worldPosition.z;
          angle = angle + ((FieldSerializedLightRecord *)record)->parameters[2];
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          lightUnit = (u8 *)MT_Scene_GetRes((u16)func_00145e90(func_0014b510(0x15), (f32 *)&point_60, ((FieldSerializedLightRecord *)record)->parameters[0],
                                 ((FieldSerializedLightRecord *)record)->parameters[1], angle, ((FieldSerializedLightRecord *)record)->color));
          *(u32 *)(lightUnit + 0x18c) = (u32)*(u16 *)(record + 2);
        }
      }
      if (c10002 < *(u32 *)(data + 4)) {
        if (4 < *(u32 *)(data + 0x38)) {
          func_0046d730(D_005F05E8,0x541);
        }
        for (recordIndex = 0; recordIndex < *(u32 *)(data + 0x38); recordIndex = recordIndex + 1, record = record + 0x14) {
          point_78 = *(SVec3 *)(record + 4);
          grid = (u8 *)func_00155280();
          angle = (f32)((*(u8 *)(wg0035_add_offset((u32)gridOffset, (u32)grid) + 0x59) + 4) % 4) * 90.0f;
          *matrix = matrix[5] = matrix[10] = 0x3f800000;
          matrix[4] = 0;
          matrix[2] = 0;
          matrix[1] = 0;
          matrix[9] = 0;
          matrix[8] = 0;
          matrix[6] = 0;
          matrix[0xe] = 0;
          matrix[0xd] = 0;
          matrix[0xc] = 0;
          matrix[3] = matrix[3] | 0x20003;
          RwMatrixRotate(matrix, D_00756510, angle, 2);
          { SVec3 *position = &point_78; func_003e42a0(position, position, matrix); }
          point_78.x = point_78.x + worldPosition.x;
          point_78.y = point_78.y + worldPosition.y;
          point_78.z = point_78.z + worldPosition.z;
          angle = angle + *(f32 *)(record + 0x10);
          { f32 f360 = 360.0f;
          for (; angle > f360; angle = angle - f360)
          {
          }
          }
          resourceSlot = &placedResourceIds[recordIndex];
          *resourceSlot = func_0014b510(0x12);
          func_001462c0(*resourceSlot,(f32 *)&point_78,angle);
        }
      }
      func_003e0f40(matrix);
    }
  }
  }
  return;
}
#pragma opt_propagation on
#pragma opt_common_subs on

#pragma pop
/* measured: opt_propagation off probe for func_001599d0. */
#pragma opt_propagation off
/* measured: loop-invariant callback masks remain at call site in func_001599d0. */
#pragma opt_loop_invariants off
// FUN_001599D0
void func_001599d0(void)
{
    s32 var_18;
    s32 var_17;
    s32 var_16;

    var_18 = 0;
    goto loop_5_test;
loop_5_body:
    var_17 = 0;
    var_16 = var_18 * 0x10;
    goto loop_3_test;
loop_3_body:
    func_001587d0((u16)(var_17 + var_16),
                  (u16)var_17, (u16)var_18);
    var_17 += 1;
loop_3_test:
    if (var_17 < 0x10) {
        goto loop_3_body;
    }
    var_18 += 1;
loop_5_test:
    if (var_18 < 0x18) {
        goto loop_5_body;
    }
}
/* measured: restores loop-invariant hoisting after func_001599d0. */
#pragma opt_loop_invariants on
/* measured: closes opt_propagation off probe for func_001599d0. */
#pragma opt_propagation on
// FUN_00159A60
/* measured: object 748B/window 752B, nd 0. Shape: the case-1 conditions are nested
   ifs that fall out to `break` (every early exit shares the single `return 0` after
   the switch; `default:` is the last label so the out-of-range jump lands there
   too). The two record-address forms differ: the flag read is `base = ...;
   (u8 *)(idx * 0x10) + (s32)base` (base loaded first, addu idx,base) and `rec`
   is the same cast form inline (idx loaded first). func_00155e10's 4th parameter
   is s32 at block scope so the u16 load is a conversion materialised before $a0.
   Zeroing loop: u32 counter for bnez. */
s32 func_00159a60(u8 *arg0)
{
    extern s32 func_00155e10(u8 *arg0, u16 arg1, u16 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6, u8 arg7, s64 arg8, s64 arg9, s64 arg10, s64 arg11, s64 arg12, s64 arg13);
    extern s32 func_00477e80(s32 arg0, s32 arg1, const char *arg2, s32 arg3);
    extern s32 func_003641a0(s32 arg0);
    extern void func_0015bae0(void);
    extern void func_0015c210(void);
    extern s32 func_0015c280(void);
    extern s32 func_0015c360(void);
    extern s32 func_0015c440(void);
    extern s32 func_0015c4b0(u8 *arg0);
    extern char D_005F0630[];
    extern u8 D_007E3720[];
    u8 sp60[12];
    u8 *work;
    u8 *rec;
    u8 *p;
    u32 n;
    u8 *base;

    work = *(u8 **)(arg0 + 0x38);
    func_0015bae0();
    switch (*(s32 *)work) {
    case 0:
        *(s32 *)(work + 0x14) = func_0015c440();
        *(s32 *)(work + 0x38) = func_00477e80(4, 0xFFFF, D_005F0630, 0);
        func_0015c210();
        *(s32 *)work += 1;
    case 1:
        if (func_0015c4b0(*(u8 **)(work + 0x14)) != 0) {
            *(s32 *)(work + 0x14) = 0;
            if (*(s32 *)(work + 0x38) == 0 || func_004782b0(*(s32 *)(work + 0x38)) != 0) {
                if (func_0015c280() != 0 && func_0015c360() != 0) {
                    *(u8 **)(work + 0x20) = D_007E3720;
                    if (*(s32 *)(work + 4) != 0x9F) {
                        *(s32 *)(work + 0x1C) = func_003641a0(0);
                    }
                    *(s32 *)work += 1;
    case 2:
                    *(s32 *)work += 1;
    case 3:
                    base = *(u8 **)(work + 0x20);
                    *(s32 *)(work + 0x24) = *((u16 *)((u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)base) + 5) | 0x80000000;
                    rec = (u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)*(u8 **)(work + 0x20);
                    *(s32 *)(work + 0x18) = func_00155e10(arg0, *(u16 *)rec, *(u16 *)(rec + 2), *(u16 *)(work + 8), 0, 0,
                                                          *(s32 *)(work + 0x24), *(u8 *)(rec + 8), *(u8 *)(rec + 9),
                                                          *(s32 *)(rec + 4), -1, -1, -1, -1);
                    *(s32 *)(work + 0x24) = 0;
                    *(s32 *)work += 1;
                }
            }
        }
        break;
    case 4:
        if (*(s32 *)(work + 0xC) == 1) {
            *(s32 *)work = 0xC;
        }
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        *(s32 *)work += 1;
        break;
    case 10:
        p = sp60;
        n = 12;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        if (func_0015c4b0(*(u8 **)(work + 0x14)) != 0) {
            *(s32 *)(work + 0x14) = 0;
            base = *(u8 **)(work + 0x20);
            *(s32 *)(work + 0x24) |= *((u16 *)((u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)base) + 5);
            rec = (u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)*(u8 **)(work + 0x20);
            *(s32 *)(work + 0x18) = func_00155e10(arg0, *(u16 *)rec, *(u16 *)(rec + 2), *(u16 *)(work + 8), 0, 0,
                                                  *(s32 *)(work + 0x24), *(u8 *)(rec + 8), *(u8 *)(rec + 9),
                                                  *(s32 *)(rec + 4), -1, -1, -1, -1);
            *(s32 *)(work + 0x24) = 0;
            *(s32 *)work = 4;
        }
        break;
    case 12:
        return -1;
    default:
        break;
    }
    return 0;
}
// FUN_00159D50
void func_00159d50(u8 *arg0)
{
    s32 *temp_19;
    s32 temp_16_2;
    s32 temp_4;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_17;
    u8 *temp_16;
    u8 *temp_4_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (func_0014a160() == 1) {
        func_0015a7c0(*(s32 *)(temp_16 + 4));
    }
    temp_4 = *(s32 *)(temp_16 + 0x1C);
    if (temp_4 != 0) {
        func_003642a0(temp_4);
    }
    temp_4_2 = *(u8 **)(temp_16 + 0x2C);
    if (temp_4_2 != NULL) {
        jtbl_008873EC[0](temp_4_2);
    }
    if (*(func_00155280() + 1) != 0) {
        func_0016e540(*(func_00155280() + 1), 1);
    }
    temp_4_3 = *(s32 *)(temp_16 + 0x38);
    if (temp_4_3 != 0) {
        func_004787e0(temp_4_3);
    }
    var_17 = 0;
    goto loop_14_test;
loop_14_body:
    temp_16_2 = var_17 * 4;
    temp_19 = (s32 *)((u8 *)D_007E8060 + temp_16_2);
    temp_4_4 = *temp_19;
    if (temp_4_4 != 0) {
        func_00151f80(temp_4_4);
        *temp_19 = 0;
        *(s32 *)(iGpffff9db0 + temp_16_2 + 0x28) = 0;
    }
    var_17++;
loop_14_test:
    if (var_17 < 0x10) {
        goto loop_14_body;
    }
    *(s32 *)iGpffff9db0 = 0;
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_00159E90
s32 func_00159e90(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(D_005F05E8, 0x718);
    temp_2 = (u8 *)D_008873F4[0](1, 0x48, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    temp_17 = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005F0650), 0xF, 0, 0, func_00159a60, func_00159d50, (u8 *)(temp_2));
    *(s32 *)(temp_2 + 4) = arg1;
    *(s32 *)(temp_2 + 8) = arg2;
    func_00106390(0xC25, 0);
    return temp_17;
}
// FUN_00159F70
void func_00159f70(s32 arg0)
{
    u8 *root;
    u8 *state;
    s32 arg_offset;
    s32 base_offset;
    s32 base;
    s32 index;
    s32 *entry;
    u8 *first;

    root = D_00764334;
    if (root != NULL) {
        state = *(u8 **)(root + 0x38);
        if (arg0 < 0) {
            *(s32 *)(state + 8) = 0x3FF;
        } else {
            *(s32 *)(state + 8) = 0xFFFF;
        }
        arg_offset = arg0 * 0x10;
        base_offset = *(s32 *)(state + 4) * 0x10;
        base = *(s32 *)(state + 0x20);
        first = (u8 *)(base + base_offset);
        if (((*(u16 *)first != *(u16 *)(first + arg_offset)) ||
             (*(u16 *)(base + 2 + base_offset) !=
              *(u16 *)wg0015_add_ptr((u8 *)(base + 2 + base_offset), arg_offset))) &&
            (((*(s32 *)(state + 0x24) |= 0x80000000),
              func_0014a200(base, base_offset, arg_offset) == 1) ||
             (func_0014a270() == 1))) {
            index = 0;
            while (index < 0x10) {
                entry = &D_007E8060[index];
                if (*entry != 0) {
                    func_00151f80(*entry);
                    *entry = 0;
                }
                index += 1;
            }
        }
        *(s32 *)(state + 4) += arg0;
        func_001560f0(*(u8 **)(state + 0x18), 1);
        *(s32 *)state = 5;
    }
}
// FUN_0015A0C0
s32 func_0015a0c0(void)
{
    u8 *work;
    u8 *p;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    p = *(u8 **)(work + 0x38);
    return *(s32 *)(p + 0x20) + (*(s32 *)(p + 4) * 0x10);
}
// FUN_0015A100
s32 func_0015a100(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 0x2C);
}



// FUN_0015A130
s32 func_0015a130(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 0x30);
}


// FUN_0015A160
s32 func_0015a160(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 4);
}
// FUN_0015A190
s32 func_0015a190(void)
{
    s32 result;
    u32 value;
    u8 *work;

    result = 0;
    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    value = *(u32 *)(*(u8 **)(work + 0x38) + 4);
    if (value < 0x14U) {
        if (datGetFlag(0x11) == 1) {
            result = 1;
        }
    } else if (value < 0x28U) {
        if (datGetFlag(0x12) == 1) {
            result = 1;
        }
    } else if (value < 0x3CU) {
        if (datGetFlag(0x13) == 1) {
            result = 1;
        }
    } else if (value < 0x50U) {
        if (datGetFlag(0x14) == 1) {
            result = 1;
        }
    } else if (value < 0x64U) {
        if (datGetFlag(0x15) == 1) {
            result = 1;
        }
    } else if (value < 0x78U) {
        if (datGetFlag(0x16) == 1) {
            result = 1;
        }
    } else if (value < 0x8CU) {
        if (datGetFlag(0x17) == 1) {
            result = 1;
        }
    }
    return result;
}
// FUN_0015A320
s32 func_0015a320(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(work + 0x38) + 0x38;
}
// FUN_0015A350
void func_0015a350(P4_0015_Vec3 *arg0)
{
    P4_0015_Vec3 out;
    f32 temp_x;
    f32 temp_z;
    s32 y;
    s32 x;
    s32 min_x;
    s32 min_y;
    s32 max_x;
    s32 max_y;
    s32 row;

    out.z = 0.0f;
    out.y = 0.0f;
    out.x = 0.0f;
    min_x = 0x10;
    min_y = 0x18;
    max_x = 0;
    max_y = 0;
    y = 0;
    while (y < 0x18) {
        x = 0;
        row = y << 8;
        while (x < 0x10) {
            if (*(u8 *)(wg0015_add_ptr(
                            (u8 *)(row + (s32)(u8 *)func_00155280()),
                            x << 4) + 0x54) == 1) {
                if (x <= min_x) {
                    min_x = x;
                }
                if (y <= min_y) {
                    min_y = y;
                }
                if (x >= max_x) {
                    max_x = x;
                }
                if (y >= max_y) {
                    max_y = y;
                }
            }
            x += 1;
        }
        y += 1;
    }
    temp_x = 1200.0f * (f32)min_x;
    out.x = temp_x + (((1200.0f * (f32)max_x) - temp_x) / 2.0f);
    temp_z = 1200.0f * (f32)min_y;
    out.z = temp_z + (((1200.0f * (f32)max_y) - temp_z) / 2.0f);
    func_00440b68(D_005F0670, min_x, min_y, max_x, max_y);
    *arg0 = out;
}
// FUN_0015A520
void func_0015a520(s32 arg0)
{
    u8 *work;
    s32 value;

    work = D_00764334;
    if (work != NULL) {
        value = *(s32 *)(*(u8 **)(work + 0x38) + 0x1C);
        if (value != 0) {
            func_003642e0(value, arg0);
        }
    }
}
// FUN_0015A560
s32 func_0015a560(void) {
    s32 var_2;
    s32 var_4;
    u8 *temp_3;

    var_2 = 1;
    temp_3 = iGpffffb244;
    if (temp_3 == NULL) {
        var_4 = 0;
    } else {
        var_4 = *(s32 *)(*(u8 **)(temp_3 + 0x38) + 4);
    }
    if ((var_4 == 0) || (var_4 == 1) || (var_4 == 2) ||
        (var_4 == 3) || (var_4 == 4) || (var_4 == 5) ||
        (var_4 == 0x14) || (var_4 == 0x28) || (var_4 == 0x3C) ||
        (var_4 == 0x50) || (var_4 == 0x64) || (var_4 == 0x78) ||
        (var_4 == 0x8C)) {
        var_2 = 0;
    }
    return var_2;
}
// FUN_0015A630
void func_0015a630(void) {
    memset(D_007D3E10, 0, 0xF8FC);
    memset(D_007E36E4, 0xFF, 0x14);
    memset(D_007E36F8, 0xFF, 0x14);
}

// FUN_0015A690
u8 *func_0015a690(void)
{
    return D_007D3E10;
}
// FUN_0015A6A0
s32 func_0015a6a0(void)
{
    return 0xF8FC;
}
/* measured: opt_rebuildconditionals off preserves the nested loop branch shape. */
#pragma opt_rebuildconditionals off
// FUN_0015A6B0
s32 func_0015a6b0(s32 arg0)
{
    s16 threshold;
    s32 offset;
    s32 result;
    s32 index;

    result = 0;
    index = 0;
    goto load;
compare:
    if (arg0 < threshold) {
        goto done;
    }
    index++;
load:
    offset = index * 2;
    threshold = *(s16 *)((u8 *)D_005F05D0 + offset);
    if (threshold >= 0) {
        goto compare;
    }
done:
    if (index == 0) {
        return 0;
    }
    if (*(u8 *)((u8 *)D_007E31E4 + ((arg0 - (s32)*(s16 *)((u8 *)D_005F05CE + offset)) << 6)) != 0) {
        result = 1;
    }
    return result;
}
/* measured: restore conditional rebuilding after the loop function. */
#pragma opt_rebuildconditionals on
// FUN_0015A740
u8 func_0015a740(s32 arg0) {
    s32 i = 0;

    while (D_005F05D0[i] >= 0) {
        if (arg0 < D_005F05D0[i]) {
            break;
        }
        i++;
    }
    if (i == 0) {
        return 0xFF;
    }
    return D_007E36E4[arg0 - *(s16 *)(D_005F05CE + i * 2)];
}

// FUN_0015A7C0
s32 func_0015a7c0(s32 arg0)
{
    s32 threshold_index;
    s32 threshold_offset;
    s16 threshold;
    s32 map_index;
    s32 copy_inner;
    s32 copy_outer;
    s32 source_row;
    s32 source_col;
    u8 *dest_cell;
    s32 slot_index;
    u8 *slot;
    u8 *slot_entry;
    extern s32 func_00164f40();

    threshold_index = 0;
    goto threshold_test;
threshold_body:
    if (arg0 < threshold) {
        goto threshold_done;
    }
    threshold_index++;
threshold_test:
    threshold_offset = threshold_index * 2;
    threshold = *(s16 *)((u8 *)D_005F05D0 + threshold_offset);
    if (threshold >= 0) {
        goto threshold_body;
    }
threshold_done:
    if (threshold_index == 0) {
        return 0;
    }

    map_index = arg0 - *(s16 *)(D_005F05CE + threshold_offset);
    if (map_index >= 0x14) {
        func_0046d730(D_005F05E8, 0x889);
    }

    if (D_007D3E10[map_index] == 0) {
        D_007D3E10[map_index] = 1;

        copy_outer = 0;
        goto copy_outer_test;
copy_outer_body:
        copy_inner = 0;
        source_row = copy_outer * 0x100;
        goto copy_inner_test;
copy_inner_body:
        source_col = copy_inner * 0x10;
        dest_cell = (u8 *)D_007D3E10 + map_index * 0xC00 + (copy_outer * 0x80) + (copy_inner * 8);
        dest_cell[0x14] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x54);
        dest_cell[0x15] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x55);
        dest_cell[0x16] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x58);
        dest_cell[0x17] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x59);
        dest_cell[0x18] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5A);
        dest_cell[0x19] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5B);
        dest_cell[0x1A] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5E);
        dest_cell[0x1B] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5F);
        copy_inner++;
copy_inner_test:
        if (copy_inner < 0x10) {
            goto copy_inner_body;
        }
        copy_outer++;
copy_outer_test:
        if (copy_outer < 0x18) {
            goto copy_outer_body;
        }
        return 1;
    }

    memcpy(D_007D3E10 + map_index * 0x30 + 0xF014, func_002ac3b0(), 0x30);

    slot_index = 0;
    goto slot_test;
slot_body:
    slot = D_007E80A0 + slot_index * 0x168;
    if (*(s32 *)slot == 0) {
        *(s8 *)(D_007D3E10 + map_index * 0x40 + slot_index * 8 + 0xF3D4) = 0;
    } else {
        slot_entry = (u8 *)(D_007D3E10 + map_index * 0x40 + slot_index * 8);
        slot_entry[0xF3D4] = 1;
        slot_entry[0xF3D5] = (s8)(*(s32 *)(slot + 8) != 0);
        *(u16 *)(slot_entry + 0xF3D6) = *(u16 *)(slot + 0xE);
        if ((*(u8 *)(*(u8 **)(slot + 0x160) + 7) & 1) != 0) {
            *(s32 *)(slot_entry + 0xF3D8) = 1;
        } else {
            *(s32 *)(slot_entry + 0xF3D8) = 0;
        }
    }
    slot_index++;
slot_test:
    if (slot_index < 8) {
        goto slot_body;
    }

    D_007E36E4[map_index] = (u8)func_00164f40(slot_index, slot_index < 8);
    return 0;
}

/* measured: opt_rebuildconditionals off preserves the retail threshold loop branch shape in func_0015ab20. */
#pragma opt_rebuildconditionals off
// FUN_0015AB20
s32 func_0015ab20(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_2;
    s32 temp_16;
    s32 temp_5;
    s32 var_6;
    u8 *work;

    var_6 = 0;
    goto loop_test;
loop_body:
    if (arg0 < temp_2) {
        goto done;
    }
    var_6 += 1;
loop_test:
    temp_5 = var_6 * 2;
    temp_2 = *(s16 *)((u8 *)D_005F05D0 + temp_5);
    if (temp_2 >= 0) {
        goto loop_body;
    }
done:
    if (var_6 == 0) {
        return 0;
    }
    temp_16 = arg0 - *(s16 *)(D_005F05CE + temp_5);
    if (temp_16 >= 0x14) {
        func_0046d730(D_005F05E8, 0x8E3, var_6);
    }
    if (*(u8 *)(D_007D3E10 + temp_16) == 1) {
        work = (u8 *)func_00155280();
        work += arg2 << 8;
        work += arg1 << 4;
        *(u8 *)(D_007D3E2B + temp_16 * 0xC00 +
                (arg2 << 7) + (arg1 << 3)) = *(u8 *)(work + 0x5F);
        return 1;
    }
    func_0046d730(D_005F05E8, 0x8ED);
    return 0;
}
/* measured: closes opt_rebuildconditionals bracket for func_0015ab20. */
#pragma opt_rebuildconditionals on
// FUN_0015AC60
s32 func_0015ac60(s32 arg0)
{
    s32 threshold_index;
    s32 threshold_offset;
    s16 threshold;
    s32 map_index;
    s32 copy_inner;
    s32 copy_outer;
    s32 scan_outer;
    s32 scan_inner;
    s32 slot_index;
    s32 dest_row;
    s32 dest_column;
    u8 *source_base;
    u8 *source_row;
    u8 *source_cell;
    s32 *slot_source;
    u8 *dest;
    u8 value;
    s32 mode;
    s32 field;
    u16 h0;
    u16 h4;

    if (func_0014a200(arg0) != 0) {
        D_0076432C = D_005F0590[*(s32 *)iGpffff9db0];
    } else {
        D_0076432C = D_005F057C[*(s32 *)iGpffff9db0];
    }

    threshold_index = 0;
    goto threshold_test;
threshold_body:
    if (arg0 < threshold) {
        goto threshold_done;
    }
    threshold_index++;
threshold_test:
    threshold_offset = threshold_index * 2;
    threshold = *(s16 *)((u8 *)D_005F05D0 + threshold_offset);
    if (threshold >= 0) {
        goto threshold_body;
    }
threshold_done:
    if (threshold_index == 0) {
        return 0;
    }

    map_index = arg0 - *(s16 *)(D_005F05CE + threshold_offset);
    if (map_index >= 0x14) {
        func_0046d730(D_005F05E8, 0x906);
    }
    memset(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    func_002ac360();
    if (D_007D3E10[map_index] != 1) {
        goto fail;
    }
    if (func_00102980() == 0xA) {
        goto fail;
    }

    copy_outer = 0;
    source_base = D_007D3E10 + map_index * 0xC00;
    goto copy_outer_test;
copy_outer_body:
    copy_inner = 0;
    source_row = source_base + copy_outer * 0x80;
    dest_row = copy_outer * 0x100;
    goto copy_inner_test;
copy_inner_body:
    source_cell = source_row + copy_inner * 8;
    dest_column = copy_inner * 0x10;

    value = source_cell[0x14];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x54) = value;
    value = source_cell[0x15];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x55) = value;
    value = source_cell[0x16];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x58) = value;
    value = source_cell[0x17];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x59) = value;
    value = source_cell[0x18];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5A) = value;
    value = source_cell[0x19];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5B) = value;
    value = source_cell[0x1A];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5E) = value;
    value = source_cell[0x1B];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5F) = value;

    copy_inner++;
copy_inner_test:
    if (copy_inner < 0x10) {
        goto copy_inner_body;
    }
    copy_outer++;
copy_outer_test:
    if (copy_outer < 0x18) {
        goto copy_outer_body;
    }

    memcpy(func_002ac3b0(),
                  D_007D3E10 + map_index * 0x30 + 0xF014, 0x30);

    scan_outer = 0;
    goto scan_outer_test;
scan_outer_body:
    scan_inner = 0;
    dest_row = scan_outer * 0x100;
    goto scan_inner_test;
scan_inner_body:
    dest_column = scan_inner * 0x10;
    if ((((u8 *)func_00155280())[dest_row + dest_column + 0x54] == 1) &&
        ((((u8 *)func_00155280())[dest_row + dest_column + 0x55] & 0xF) != 0)) {
        if (((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 6) {
            *(u8 *)((u8 *)func_00155280() + 0x44) = (u8)scan_inner;
            *(u8 *)((u8 *)func_00155280() + 0x45) = (u8)scan_outer;
        }
        if ((((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 0xA) ||
            (((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 0xC) ||
            (((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 0xE)) {
            *(u8 *)((u8 *)func_00155280() + 0x46) = (u8)scan_inner;
            *(u8 *)((u8 *)func_00155280() + 0x47) = (u8)scan_outer;
            value = ((u8 *)func_00155280())[dest_row + dest_column + 0x59];
            *(u8 *)((u8 *)func_00155280() + 0x49) = value;
        }
    }
    scan_inner++;
scan_inner_test:
    if (scan_inner < 0x10) {
        goto scan_inner_body;
    }
    scan_outer++;
scan_outer_test:
    if (scan_outer < 0x18) {
        goto scan_outer_body;
    }

    slot_index = 0;
    source_base = D_007D3E10 + map_index * 0x40;
    goto slots_test;
slots_body:
    slot_source = (s32 *)(source_base + slot_index * 8);
    if (((u8 *)slot_source)[0xF3D4] != 0) {
        dest = D_007E80A0 + slot_index * 0x168;
        *(s32 *)dest = 1;
        *(u32 *)(dest + 8) = ((u8 *)slot_source)[0xF3D5];
        *(u16 *)(dest + 0xE) = *(u16 *)((u8 *)slot_source + 0xF3D6);
        slot_source = (s32 *)((u8 *)slot_source + 0xF3D8);
        mode = *slot_source;
        if (mode == 0) {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = *(s32 *)(*(u8 **)(D_00764334 + 0x38) + 4);
            }
            h0 = *(u16 *)iGpffff9db0;
            h4 = *(u16 *)(iGpffff9db0 + 4);
            *(u8 **)(dest + 0x160) =
                func_00161c80(h0, h4, field, 0);
        } else if (mode == 1) {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = *(s32 *)(*(u8 **)(D_00764334 + 0x38) + 4);
            }
            h0 = *(u16 *)iGpffff9db0;
            h4 = *(u16 *)(iGpffff9db0 + 4);
            *(u8 **)(dest + 0x160) =
                func_00161c80(h0, h4, field, 1);
        } else {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = *(s32 *)(*(u8 **)(D_00764334 + 0x38) + 4);
            }
            h0 = *(u16 *)iGpffff9db0;
            h4 = *(u16 *)(iGpffff9db0 + 4);
            *(u8 **)(dest + 0x160) =
                func_00161c80(h0, h4, field, 2);
        }
    }
    slot_index++;
slots_test:
    if (slot_index < 8) {
        goto slots_body;
    }
    return 1;
fail:
    return 0;
}
// FUN_0015B240
void func_0015b240(void)
{
    u8 *entry;
    s32 flag;
    s32 field_x;
    s32 field_y;

    entry = func_001452b0(0xA);
    if (func_0014a200() == 0) {
        if (func_0014a270() == 0) {
            return;
        }
    }
    while (entry != NULL) {
body:
            field_x = (s32)((*(f32 *)(mdlGetMatrix(*(s32 *)(entry + 0x144)) + 0x30) +
                             600.0f) /
                            1200.0f);
            field_y = (s32)((*(f32 *)(mdlGetMatrix(*(s32 *)(entry + 0x144)) + 0x38) +
                             600.0f) /
                            1200.0f);
            flag = 0;
            if ((*(u8 *)((u8 *)func_00155280() + (field_y << 8) +
                         (field_x << 4) + 0x5F) &
                 0xF0) != 0) {
                flag = 1;
            }
            if (flag == 1) {
                if (func_00457c90(
                        mdlGetClump(*(s32 *)(entry + 0x144)),
                        D_005F0690) != 0) {
                    func_00479940((u8*)*(s32 *)(entry + 0x144), 0, 2, 0, 0);
                }
                if (func_00457c90(
                        mdlGetClump(*(s32 *)(entry + 0x144)),
                        D_005F06A0) != 0) {
                    *(s32 *)(entry + 0x150) = 0;
                }
            }
            entry = *(u8 **)(entry + 0x138);
        }
}
/* Configured b210 -O2 matches 1780 code bytes and the 12-byte zero tail.
 * For kinds 7/8, axis mask 0xA and depth zero, retail extends the north
 * or south limit without writing next_depth (0015B5DC and 0015B8C0).
 * Calls at 0015B654/0015B938 consume that retained or unwritten value.
 * Preserve this original omission; no default depth or unreachable-path
 * claim is introduced. This is configured-native reconstruction, not a
 * claim of portable defined behavior on the omitted-assignment path. */
// FUN_0015B3E0
void func_0015b3e0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, s32 arg5, u8 arg6, s32 *arg7)
{
    extern void func_0014a0f0(u16 resTypeId, u32 visible);
    s32 depth_low;
    s32 limit_low;
    u8 north_limit;
    u8 south_limit;
    u8 west_limit;
    s32 east_tmp;
    /* Retail leaves this unwritten on the limit-extension paths below. */
    s32 next_depth;
    s32 mode;
    s32 exits;

    limit_low = arg6 & 0xFF;
    depth_low = arg5 & 0xFF;
    if (depth_low < limit_low) {
        if (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x54] == 1) {
            func_0014a0f0(*(u16 *)(((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10)) + 0x56), 1);
            *arg7 += 1;
            exits = (~arg2 & ((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x5E]) & 0xFF;
            if (exits & 1) {
                north_limit = (arg3 & 1) ? 3 : limit_low;
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (((u8)arg4 & 0xA) != 0) && (depth_low == 0)) {
                    /* 0015B5DC..0015B5E8: no next_depth assignment. */
                    north_limit += 1;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((u8)arg4 & 1) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (u8)(depth_low + 1);
                }
                func_0015b3e0(arg0, arg1 - 1, 4, 0, arg4, next_depth, north_limit, arg7);
            }
            if (exits & 2) {
                west_limit = (arg3 & 2) ? 3 : limit_low;
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (limit_low == 4)) {
                    next_depth = (u8)arg5;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((u8)arg4 & 2) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (u8)(depth_low + 1);
                }
                func_0015b3e0(arg0 - 1, arg1, 8, 0, arg4, next_depth, west_limit, arg7);
            }
            if (exits & 4) {
                south_limit = (arg3 & 4) ? 3 : limit_low;
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (((u8)arg4 & 0xA) != 0) && (depth_low == 0)) {
                    /* 0015B8C0..0015B8CC: retain the prior next_depth. */
                    south_limit += 1;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((u8)arg4 & 4) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (u8)(depth_low + 1);
                }
                func_0015b3e0(arg0, arg1 + 1, 1, 0, arg4, next_depth, south_limit, arg7);
            }
            if (exits & 8) {
                east_tmp = arg3 & 8;
                if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 2) && (((mode = *(s32 *)iGpffff9db0) == 0x2C) || (mode == 0x40)) && (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x55] & 0x20)) {
                    next_depth = (u8)arg5;
                } else if (((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 7) || (((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 8)) && (limit_low == 4)) {
                    next_depth = (u8)arg5;
                } else if ((((u8 *)func_00155280() + (arg1 << 8) + (arg0 * 0x10))[0x58] == 3) && (((u8)arg4 & 8) != 0)) {
                    next_depth = (u8)arg5;
                } else {
                    next_depth = (u8)(depth_low + 1);
                }
                if (east_tmp != 0) {
                    limit_low = 3;
                }
                arg6 = (u8)limit_low;
                arg0 = arg0 + 1;
                func_0015b3e0(arg0, arg1, 2, 0, arg4, next_depth, arg6, arg7);
            }
        }
    }
}
// FUN_0015BAE0
void func_0015bae0(void)
{
    u8 *var_19;
    u8 *temp_s5;
    u8 *var_18;
    u8 *var_17;
    s32 var_16;
    s32 var_15;
    f32 angle;
    s32 i;
    s32 j;
    u8 *work;
    u8 *object;

    var_19 = func_001452b0(0xC);
    temp_s5 = MT_Scene_GetRes(0x400);
    var_18 = func_001452b0(0xA);
    var_17 = func_001452b0(0xB);
    var_16 = 0;
    var_15 = 0;
    if (func_0014a160() != 0) {
        if (temp_s5 != NULL) {
            var_16 = func_001687d0(*(s32 *)(temp_s5 + 0x220));
            var_15 = func_001687e0(*(s32 *)(temp_s5 + 0x220));
            goto clear_test;
clear_body:
            *(u32 *)(var_19 + 0x28) &= ~2U;
            var_19 = *(u8 **)(var_19 + 0x138);
clear_test:
            if (var_19 != NULL) {
                goto clear_body;
            }
            func_001452b0(0xC);
        } else {
            goto set_test;
set_body:
            *(u32 *)(var_19 + 0x28) |= 2;
            var_19 = *(u8 **)(var_19 + 0x138);
set_test:
            if (var_19 != NULL) {
                goto set_body;
            }
            func_001452b0(0xC);
        }

        work = (u8 *)func_00457120();
        angle = func_0014b5d0(*(u8 **)(work + 4) + 0x10);
        D_0076430C = 0;
        if ((angle <= 45.0f) && !(angle < -45.0f)) {
            if ((angle <= 25.0f) && !(angle < -25.0f)) {
                func_0015b3e0(var_16, var_15, 0, 0xB, 4, 0, 4,
                              &D_0076430C);
            } else if (!(angle < 25.0f)) {
                func_0015b3e0(var_16, var_15, 0, 3, 4, 0, 4,
                              &D_0076430C);
            } else if (angle <= -25.0f) {
                func_0015b3e0(var_16, var_15, 0, 9, 4, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= 135.0f) && !(angle <= 45.0f)) {
            if ((angle <= 115.0f) && !(angle < 65.0f)) {
                func_0015b3e0(var_16, var_15, 0, 7, 8, 0, 4,
                              &D_0076430C);
            } else if (!(angle < 115.0f)) {
                func_0015b3e0(var_16, var_15, 0, 6, 8, 0, 4,
                              &D_0076430C);
            } else if (angle <= 65.0f) {
                func_0015b3e0(var_16, var_15, 0, 3, 8, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= -45.0f) && !(angle < -135.0f)) {
            if ((angle <= -65.0f) && !(angle < -115.0f)) {
                func_0015b3e0(var_16, var_15, 0, 0xD, 2, 0, 4,
                              &D_0076430C);
            } else if (!(angle < -65.0f)) {
                func_0015b3e0(var_16, var_15, 0, 9, 2, 0, 4,
                              &D_0076430C);
            } else if (angle <= -115.0f) {
                func_0015b3e0(var_16, var_15, 0, 0xC, 2, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= -155.0f) || !(angle < 155.0f)) {
            func_0015b3e0(var_16, var_15, 0, 0xE, 1, 0, 4,
                          &D_0076430C);
        } else if (!(angle < -155.0f) && (angle < 0.0f)) {
            func_0015b3e0(var_16, var_15, 0, 0xC, 1, 0, 4,
                          &D_0076430C);
        } else if ((angle <= 155.0f) && !(angle <= 0.0f)) {
            func_0015b3e0(var_16, var_15, 0, 6, 1, 0, 4,
                          &D_0076430C);
        }

        goto list_a_test;
list_a_body:
        object = *(u8 **)(var_18 + 0x140);
        if (object != NULL) {
            if ((*(u32 *)(object + 0x28) & 2) != 0) {
                *(u32 *)(var_18 + 0x28) |= 2;
            } else {
                *(u32 *)(var_18 + 0x28) &= ~2U;
            }
        }
        var_18 = *(u8 **)(var_18 + 0x138);
list_a_test:
        if (var_18 != NULL) {
            goto list_a_body;
        }

        goto list_b_test;
list_b_body:
        object = *(u8 **)(var_17 + 0x140);
        if ((*(u32 *)(object + 0x28) & 2) != 0) {
            *(u32 *)(var_17 + 0x28) |= 2;
        } else {
            *(u32 *)(var_17 + 0x28) &= ~2U;
        }
        var_17 = *(u8 **)(var_17 + 0x138);
list_b_test:
        if (var_17 != NULL) {
            goto list_b_body;
        }

        i = 0;
        goto array_a_test;
array_a_body:
        work = D_007E8C00 + i * 0x750;
        if (*(s32 *)(work + 0x48) != 0) {
            object = *(u8 **)(work + 0x54);
            if (object != NULL) {
                *(u32 *)(object + 0x28) &= ~2U;
            }
        }
        i++;
array_a_test:
        if (i < 0xF) {
            goto array_a_body;
        }

        j = 0;
        goto array_b_test;
array_b_body:
        work = (u8 *)D_007E8020[j];
        if (work != NULL) {
            object = *(u8 **)(work + 0x54);
            if (object != NULL) {
                *(u32 *)(object + 0x28) |= 2;
            }
        }
        j++;
array_b_test:
        if (j < 8) {
            goto array_b_body;
        }
    }
}
// FUN_0015C1E0
s32 func_0015c1e0(s32 arg0)
{
    u8 *work;
    u8 *p;
    u32 offset;
    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    p = *(u8 **)(work + 0x38);
    p = (u8 *)wg0035_add_offset((u32)(arg0 * 4), (u32)p);
    return *(s32 *)(p + 0x40);
}
// FUN_0015C210
void func_0015c210(void) {
    if (D_00764334 == NULL) {
        return;
    }
    if (*(s32 *)(*(u8 **)(D_00764334 + 0x38) + 0x40) != 0) {
        return;
    }
    if (iGpffffb218 != 0) {
        return;
    }
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xB48);
    iGpffffb218 = func_00454a60(D_005F06C0, 1);
}

// FUN_0015C280
s32 func_0015c280(void) {
    u8 *temp_16;

    if (iGpffffb218 == 0) {
        return 1;
    }
    if (iGpffffb244 == NULL) {
        func_0046d730(D_005F05E8, 0xB58);
        return 1;
    }
    temp_16 = *(u8 **)(iGpffffb244 + 0x38);
    if (H_Cdvd_IsFileLoaded(iGpffffb218) == 0) {
        return 0;
    }
    if (*(s32 *)(temp_16 + 0x40) == 0) {
        *(s32 *)(temp_16 + 0x40) =
            func_0014e5e0(iGpffffb244, D_005F06E0, 0x1E, iGpffffb218);
    }
    if (*(s32 *)(temp_16 + 0x44) == 0) {
        *(s32 *)(temp_16 + 0x44) =
            func_0014e5e0(iGpffffb244, D_005F0700, 0x14, iGpffffb218);
    }
    return 1;
}
// FUN_0015C360
s32 func_0015c360(void) {
    u8 *temp_16;
    s32 i;

    if (iGpffffb218 == 0) {
        return 1;
    }
    if (iGpffffb244 == NULL) {
        func_0046d730(D_005F05E8, 0xB79);
        return 1;
    }
    temp_16 = *(u8 **)(iGpffffb244 + 0x38);
    i = 0;
    while (i < 2) {
        if (*(s32 *)(temp_16 + i * 4 + 0x40) != 0 &&
            func_0014e710(*(s32 *)(temp_16 + i * 4 + 0x40)) == 0) {
            return 0;
        }
        i++;
    }
    if (iGpffffb218 != 0) {
        H_Cdvd_Destroy(iGpffffb218);
        iGpffffb218 = 0;
    }
    return 1;
}
// FUN_0015C440
s32 func_0015c440(void)
{
    s32 r = 0;
    u8 *p = D_00764334;
    if (p == NULL) {
        return r;
    }
    if (*(u32 *)(*(u8 **)(p + 0x38) + 0x2C) == 0) {
        func_00440b68(&iGpffff9e28, D_005F05E8, 0xC19);
        r = func_00454a60(D_005F0720, 0);
    }
    return r;
}


/* measured: opt_propagation off preserves the retail argument materialization
 * order in the resource copy call. */
#pragma opt_propagation off
// FUN_0015C4B0
s32 func_0015c4b0(u8 *arg0) {
    u8 *temp_17;
    u8 *copy_dst;
    u8 *copy_src;
    s32 size;
    if (iGpffffb244 == NULL) {
        return 1;
    }
    temp_17 = *(u8 **)(iGpffffb244 + 0x38);
    if (arg0 == NULL) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded() != 0) {
        func_0044ea90(D_005F05E8, 0xC30);
        size = *(s32 *)(arg0 + 0x118);
        *(u8 **)(temp_17 + 0x2C) =
            (u8 *)D_008873F4[0](1, size, 0x40000);
        *(s32 *)(temp_17 + 0x30) = *(s32 *)(arg0 + 0x118);
        size = *(s32 *)(arg0 + 0x118);
        copy_dst = *(u8 **)(temp_17 + 0x2C);
        copy_src = *(u8 **)(arg0 + 0x110);
        memcpy(copy_dst, copy_src, size);
        H_Cdvd_Destroy(arg0);
        return 1;
    }
    return 0;
}
/* measured: close the single-function opt_propagation bracket. */
#pragma opt_propagation on
// FUN_0015C590
void func_0015c590(s32 arg0) {
    u8 sp10[0x80];

    sprintf(sp10, (const char *)D_005F0740, arg0);
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xC49);
    func_00454a60(sp10, 0);
}

// FUN_0015C5F0
s32 func_0015c5f0(s32 arg0)
{
    if (arg0 == 0) {
        return 1;
    }
    return H_Cdvd_IsFileLoaded() != 0;
}
// FUN_0015C630
s32 func_0015c630(u8 *arg0)
{
    return 1;
}

// FUN_0015C640
u8 *func_0015c640(s32 arg0, s32 arg1) {
    u8 spB0[0x80];
    u8 sp30[0x80];

    strcpy(spB0, (const char *)D_005F0760);
    sprintf(sp30, (const char *)D_005F0770, arg0 & 0xFFFF, arg1 & 0xFFFF);
    if (H_Cdvd_FileExists(sp30) == 0) {
        return NULL;
    }
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xC9E);
    return (u8 *)func_00454a60(sp30, 0);
}
// FUN_0015C6F0
s32 func_0015c6f0(u8 *arg0)
{
    if (arg0 == NULL) {
        return 1;
    }
    return H_Cdvd_IsFileLoaded(arg0) != 0;
}
// FUN_0015C730
void func_0015c730(u8 *arg0)
{
    H_Cdvd_Destroy(arg0);
}

// FUN_0015D270
void func_0015d270(u8 *arg0)
{
    s32 h;

    h = *(s32 *)(arg0 + 0x14);
    if (h != 0) {
        (*jtbl_008873EC)((void *)h);
        *(s32 *)(arg0 + 0x14) = 0;
    }
}

// FUN_0015D2C0
u16 *func_0015d2c0(u32 arg0)
{
    u16 *record;
    u32 i;
    s32 emptyCount;
    u32 recordCount;
    u16 emptyId;

    record = (u16 *)D_00764384;
    emptyCount = 0;
    i = 0;
    recordCount = D_0076438C;
    emptyId = 0xFFFF;
    while (i < recordCount) {
        if (emptyCount != arg0) {
            if (*record == emptyId) {
                emptyCount++;
            }
            i++;
            record = (u16 *)((u8 *)record + 0x84);
        } else {
            break;
        }
    }
    return record;
}

/* HBN-record floor (1056B window). Counted-for inner loops (Main order #1): 97wd / 48+1 edits (267 vs 264 3-long) -> 14wd / 14+1 edits (261/261 exact). Entry-guard blez (#2) ties 97, incr-order swap (#3) ties 97, s16 counters (#4) explode 255. s32 for s64 temps ties 14. Remnant is pure $v0/$v1 + addiu/daddiu in the (s8)func_00110960 &1/-2 adjust (6 sites). Frame -0x90 exact, 7/7 pairs balanced, opclass clean. Production stays ASM. */
/* MATCHED.  The last 14 differing words were the hand-expanded signed modulo: the body
   lowered `x % 2` itself as `x & 1` plus a negative correction and a `-= 2`, which left six
   sites of $v0/$v1 and addiu/daddiu churn.  Writing `(s32)var_2 % 2` with s32 temporaries
   lets the compiler emit its own sequence and the function goes to zero. */
// FUN_0015D310
u8 *func_0015d310(u16 *arg0)
{
    extern s16 func_001060b0(void);
    extern s64 func_00110960(s32 arg0, u32 arg1);
    extern u8 func_001060c0(void);
    extern void func_001104d0(s32 date, s32 *month, s32 *day);
    extern s32 func_00110580(s32 date);
    extern s32 func_00110d30(s32 date);
    extern u32 clndIsDateInRange(u32 firstMonth, u32 firstDay, u32 lastMonth, u32 lastDay);
    extern u32 datGetFlag(s32 bit);
    s32 sp8C;
    s32 sp88;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 var_18;
    s32 var_19_2;
    s32 temp_3_2;
    s32 temp_3_3;
    s64 var_2;
    s64 var_2_2;
    s32 temp_22;
    s32 temp_22_2;
    u16 *var_5;
    u32 temp_4_2;
    s32 var_19;
    s32 var_20;
    u32 var_17;
    u32 var_18_2;
    u32 var_18_3;
    u32 var_21;
    u8 temp_3;
    u8 *temp_20;
    u8 *temp_4;
    uintptr_t recordAddress;

    var_5 = arg0;
    if (arg0 == NULL) {
        return NULL;
    }
    var_17 = 0;
loop_3:
    if (*var_5 != 0xFFFF) {
        var_17 += 1;
        var_5 += 0x42;
        goto loop_3;
    }
    recordAddress = (uintptr_t)((u8 *)arg0 + var_17 * 0x84) - 0x84;
    var_18 = 3;
    var_19 = 0x1F;
    var_20 = 0;
    func_001104d0((s16)func_001060b0(), &sp8C, &sp88);
    var_21 = 0;
    goto loop_test;
loop_body:
        temp_4 = iGpffff9db0;
        if ((*(s32 *)(temp_4 + 0) == *(u16 *)(recordAddress + 0x64)) &&
            (*(s32 *)(temp_4 + 4) == *(u16 *)(recordAddress + 0x66))) {
            temp_4_2 = *(u16 *)(recordAddress + 2);
            if ((temp_4_2 == var_18) &&
                (*(u16 *)(recordAddress + 4) == var_19) &&
                (*(u16 *)(recordAddress + 6) == var_20)) {
                var_18 = 3;
                var_19 = 0x1F;
                var_20 = 0;
            }
            if (clndIsDateInRange(temp_4_2, *(u16 *)(recordAddress + 4),
                             var_18, var_19) == 1) {
                if ((*(u16 *)(recordAddress + 2) == sp8C) &&
                    (*(u16 *)(recordAddress + 4) == sp88) &&
                    ((func_001060c0() & 0xFF) < var_20)) {
                    var_18 = *(u16 *)(recordAddress + 2);
                    var_19 = *(u16 *)(recordAddress + 4);
                    var_20 = *(u16 *)(recordAddress + 6);
                    goto block_50;
                }
                if (((*(u8 *)(recordAddress + 8) == 0) ||
                     (*(u8 *)(recordAddress + 8) &
                      (1U << func_00110d30((s16)func_001060b0())))) &&
                    ((*(u8 *)(recordAddress + 9) == 0) ||
                     (*(u8 *)(recordAddress + 9) &
                      (1U << func_00110580((s16)func_001060b0())))) &&
                    ((*(u8 *)(recordAddress + 0xA) == 0) ||
                     (*(u8 *)(recordAddress + 0xA) &
                      (1U << (func_001060c0() & 0xFF))))) {
                    temp_3 = *(u8 *)(recordAddress + 0xB);
                    if (temp_3 == 1) {
                        temp_22 = (s16)func_001060b0();
                        var_2 = (s64)(s8)func_00110960(temp_22,
                                                     func_001060c0() & 0xFF);
                        temp_3_2 = (s32)var_2 % 2;
                        if (temp_3_2 != 0) {
                            goto block_50;
                        }
                        goto block_34;
                    }
                    if (temp_3 == 2) {
                        temp_22_2 = (s16)func_001060b0();
                        var_2_2 = (s64)(s8)func_00110960(temp_22_2,
                                                       func_001060c0() & 0xFF);
                        temp_3_3 = (s32)var_2_2 % 2;
                        if (temp_3_3 != 0) {
                            goto block_34;
                        }
                        goto block_50;
                    }
block_34:
                    for (var_18_2 = 0; var_18_2 < 0xC; var_18_2++) {
                        temp_4_3 = *(s32 *)(recordAddress + (var_18_2 * 4) + 0x34);
                        if ((temp_4_3 != -1) &&
                            (datGetFlag(temp_4_3) == 1)) {
                            break;
                        }
                    }
                    if (var_18_2 >= 0xC) {
                        var_19_2 = 0;
                        for (var_18_3 = 0; var_18_3 < 5; var_18_3++) {
                            temp_20 = (u8 *)(recordAddress + (var_18_3 * 8));
                            temp_4_4 = *(s32 *)(temp_20 + 0xC);
                            if (temp_4_4 == -1) {
                                continue;
                            }
                            var_19_2 = 1;
                            if (datGetFlag(temp_4_4) != 1) {
                                continue;
                            }
                            temp_4_5 = *(s32 *)(temp_20 + 0x10);
                            if (temp_4_5 != -1) {
                                if (datGetFlag(temp_4_5) != 1) {
                                    continue;
                                }
                            }
                            break;
                        }
                        if ((var_18_3 >= 5) && (var_19_2 != 0)) {
                            goto block_49;
                        }
                    } else {
                        goto block_49;
                    }
                } else {
                    goto block_50;
                }
            } else {
block_49:
                var_18 = *(u16 *)(recordAddress + 2);
                var_19 = *(u16 *)(recordAddress + 4);
                var_20 = *(u16 *)(recordAddress + 6);
                goto block_50;
            }
        } else {
block_50:
            var_21 += 1;
            recordAddress -= 0x84;
loop_test:
            if (var_21 < var_17) {
                goto loop_body;
            }
        }
    if (var_21 >= var_17) {
        recordAddress = 0;
    }
    return (u8 *)recordAddress;
}
// FUN_0015F600
s32 func_0015f600(void)
{
    u8 *work;
    s32 result;

    work = func_001452b0(3);
    result = 1;
    while (work != NULL) {
        if (!(*(s32 *)(work + 0x28) & 0x10000000)) {
            result = 0;
            break;
        }
        work = *(u8 **)(work + 0x138);
    }
    return result;
}
/* measured: see the annotation above the matching `on` pragma (func_0015f600). */
#pragma opt_loop_invariants off



// FUN_0015F660
s32 func_0015f660(void)
{
    u8 *work;
    s32 result;

    work = func_001452b0(3);
    result = 1;
    while (work != NULL) {
        if (!(*(s32 *)(work + 0x28) & 0x10000000)) {
            if (func_004782b0(*(s32 *)(work + 0x164)) != 0) {
                *(s32 *)(work + 0x28) |= 0x10000000;
            }
            result = 0;
        }
        work = *(u8 **)(work + 0x138);
    }
    if (func_003e8120(func_00457120()) != 0) {
        func_003e8110(func_00457120());
    }
    return result;
}
