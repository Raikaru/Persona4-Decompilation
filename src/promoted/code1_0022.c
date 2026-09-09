#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
typedef struct BtlTarget BtlTarget;
typedef struct BtlCamera BtlCamera;
typedef struct BtlUnitStateWork BtlUnitStateWork;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct RwV3d RwV3d;
typedef struct DatUnit DatUnit;
typedef struct KwlnTask KwlnTask;
typedef struct Model Model;
typedef struct RwMatrix RwMatrix;
extern u8 *iGpffff9db0;
extern u8 D_006355C0[], D_006355E0[], D_00635600[];
extern u8 *func_00147530(u8 *lists, u16 id);
extern u16 func_00231f80(DatUnit *unit);
extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
extern u32 func_001064f0(s32 counter);
extern void func_00106550(s32 counter, u32 value);
extern void func_001fae60(s32 initialize, s32 update, s32 packet);
extern s32 func_001d9740(u8 *packet, s32 percentage);
extern void mdlScale(Model *model, const RwV3d *scale, int combineOp);
/* Retail forwards the matrix result as well as all three inputs. */
extern RwMatrix *func_0047a180(RwMatrix *matrix, const RwV3d *translation, int combineOp);
typedef struct BtlAction BtlAction;
extern void btlActionSetState(BtlAction *action, u16 state);
extern void func_00229da0(u8 *packet);
extern void func_0022a730(u8 *packet);
struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
};
typedef struct RtQuat {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} RtQuat;
typedef struct RwRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;
extern RwRGBA iGpffffb45c;
extern char D_007636C0[8];
extern char D_007636C8[8];
extern char D_007636D0[8];
extern u8 D_0062E070[];
extern void func_004777d0(void *model, s32 name, u8 alpha);
extern s32 func_002325a0(DatUnit *unit, s32 hpDelta);
extern void func_00233880(u8 *unit, s32 effect);
extern RtQuat *func_003dc740(RtQuat *out, const RwV3d *axis, f32 angle, s32 mode);
extern void btlUnitSetRot(BtlUnit *unit, const RtQuat *rotation);
extern void btlUnitSetColor(BtlUnit *unit, RwRGBA color);
extern u32 datCalcClearBadStatus(s32 unit, u32 mask);
extern void func_0019d040(u8 *unit);
extern u32 func_00106330(s32 bit);
extern void func_001bdeb0();

u8 *func_00452380(s8 *name);

extern u8 D_006290F0[];

u32 func_00452560(void *task);
extern u8 D_00629698[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0044ea90();
extern void func_0043f9c8();
extern s32 func_00451fc0();
extern void func_00221f40();
extern void func_002230a0();
extern void func_00222d20();
extern s32 func_002232a0(KwlnTask *task);
extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[0x94];
extern void func_00460ac0(u8 *list, u8 *node);
extern u16 func_0010b6f0(void);
extern u16 *func_0010ace0(s16 slot);
extern u8 *func_00117780(s32 parent, s32 priority, s32 mode, s32 layout, s32 option);
extern void func_00117580(u8 *window, s32 value);
extern void func_0011d100(u8 *window, f32 *position);
extern void func_0011bb90(u8 *window);
extern void func_0011b480(u8 *window, s32 mode, u32 persona, s32 option);
extern u8 *func_0011f410(s32 parent, s32 window, u8 *record, s32 payload, s32 option, s32 *messages);
extern u32 func_0011f560(u8 *child);
extern s32 func_0011f580(u8 *child);
extern s32 func_00353f50(s32 mode);
extern s32 func_0021de60(void);
extern void func_0046d730(const void *file, u32 line);
extern u8 D_00635560[], D_00635580[];
extern u8 iGpffffa4d8[4];
extern u8 *func_001ebb00(s32 action, s32 kind, u8 *name);
extern u8 *func_00194c90(void *callback, void *data);
extern BtlPacket *func_001d7ab0(u8 *values, u16 duration);
extern BtlPacket *func_001d7b60(u16 duration);
extern BtlPacket *func_0019b6a0(BtlUnit *unit);
extern u8 *func_0019b550(u8 *unit, s16 id, s16 animation);
extern BtlPacket *func_002305c0(s32 id);
extern BtlPacket *func_00230650(void);
extern BtlPacket *func_002306d0(void);
extern BtlPacket *func_00230750(void);
extern BtlPacket *func_001b7e20(u32 duration);
extern BtlPacket *func_001b9360(s32 duration, s16 mode);
extern BtlPacket *func_001b99a0(s32 duration);
extern BtlPacket *func_001ba090(s32 duration);
extern void func_002236b0();
extern void func_002236c0(KwlnTask *task);

extern u8 D_00629640[];
extern u8 D_00629738[];
extern void func_002239a0();
extern void func_00223ed0();
extern void func_00223ee0(KwlnTask *task);
extern s32 func_001998e0(u8 *arg0, s32 arg1);
extern s64 func_001999f0(u8 *arg0, s32 arg1, f32 arg2, s64 arg3);
extern s32 func_0019fe60(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001cbf80(u8 *arg0);
extern void func_001cbfe0(int param_1);
extern s32 func_00243ce0(u8 *arg0);
extern void func_002250a0(u8 *arg0, f32 arg1, f32 arg2);
extern void func_002258b0(u8 *arg0, f32 arg1, f32 arg2);
extern u16 func_001eb440(BtlTarget *target);
extern s32 func_001f0a50(u8 *arg0);
extern void func_001c9750(u8 *arg0);
extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
extern void func_001ec1c0(void *out, void *first, void *second);
extern void func_001bd5e0(f32 *out, f32 *in);
extern f32 fGpffff80fc;
extern f32 fGpffff80dc;
extern f32 tanf(f32 angle);
extern u32 func_001bc3a0(f32 *pose, f32 *out);
extern f32 fGpffff8110;
extern u8 D_0060A100[];
extern f32 fGpffff8100;
extern f32 fGpffff810c;
extern f32 fGpffff8128;
extern f32 fGpffff813c;
extern f32 fGpffff809c;
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8098;
extern f32 fGpffff8118;
extern f32 fGpffff8174;
extern f32 fGpffff8178;
extern f32 fGpffff817c;
extern void func_001c9820(u8 *camera, s32 reverseSide, s32 forceActorSide, f32 angleLimit);
extern void func_002266b0(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration);
extern s32 func_0019fc70(u8 *action);

extern u8 D_006296B0[];
extern u8 D_006296E8[];

extern u8 D_00629700[];

void func_001c8d50(void);

extern u8 *DAT_0076449c;
extern void func_001c97b0(u8 *arg0);
extern s32 func_001bc560(u8 *arg0, u8 *arg1);
extern void func_0019de70(BtlUnitStateWork *work, u16 value);
extern void func_00195590(BtlUnit *unit, const RwV3d *target);
extern s32 func_001c0e50(u8 *camera);
extern void func_001c5110(u8 *camera);
extern s32 func_0022f950(u8 *action, u8 *subordinate);
extern void func_002240e0(u8 *camera);

extern u8 *func_00193bf0(u64 uid, u64 mask);
extern void func_00106390(s32 arg0, s32 arg1);
extern s32 func_00452490(void *target);
extern u8 *func_001b0c80(s32 arg0);
extern void func_001f2eb0(u8 *arg0, s32 arg1);
extern void func_001f7530(void);


u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);



extern void (*jtbl_008873EC[])(void *arg0);
extern void func_0011b360(u8 *arg0);
extern void func_001f7570(s16 fadeDuration);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void func_001bd780(void *out, const void *first, const void *second, const void *config);
extern void func_001bab00(u16 *param_1, f32 *param_2);
extern void func_001bd5a0(f32 *arg0, f32 *arg1);
extern void func_001bd560(f32 *arg0, f32 *arg1);
extern void func_001bac20(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4);
extern void func_001bbef0(u8 *arg0, f32 arg1);
extern u32 func_00231d70(u32 arg0);
extern u8 D_0060A0E0[];
extern s32 func_001ef9a0(void);
extern u8 D_006348B0[];
extern u8 D_00634CB0[];
extern u8 D_006350B0[];
extern u8 *iGpffffb414;
extern u8 D_0062A5F0[];
extern u8 D_0062AD40[];
extern u8 D_0062B490[];
extern u8 D_0062BBE0[];
extern u8 D_0062C330[];
extern s32 func_001b1510(void);
extern s32 func_00232710(u8 *arg0, s32 arg1);
extern f32 fGpffff834c;
extern void func_001958f0(BtlUnit *unit, RwV3d *dst);
extern void func_00194ee0(u8 *arg0, s32 *arg1);
extern void func_001ec6d0(s16 *outX, s16 *outZ, f32 *position);
extern u8 *iGpffffb3e0;
extern s32 func_001f0ff0();
extern s32 func_001f1210(u8 *arg0, s64 arg1, s32 arg2);
extern s32 func_0022fc00(u8 *arg0);
extern s32 func_0022ff70(u8 *arg0);

extern u8 *func_001bc920(u8 *arg0, s32 arg1);
extern s64 func_00194590(u8 *arg0, u32 arg1);
extern u8 *func_00202400(s32 arg0, s32 arg1);
extern s32 func_004bd050(s32 arg0);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, u16 arg3, f32 arg4);
extern u8 D_00632240[];
extern u8 *func_0019ef90(s32 arg0, s32 arg1);
extern void func_0019d0c0(u8 *arg0);
extern void func_00198dd0(u8 *arg0, s32 arg1);
extern void func_00198920(u8 *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4);
extern void func_002339d0(u8 *arg0);
extern u8 D_0062D920[];
extern void func_001a03b0(s64 *arg0);
extern s32 func_001d3d50(u32 param_1);
extern void func_001d4490(s32 formation, u32 data);
extern u8 *func_0022ced0(s32 arg0);
extern void func_001d3ea0(int destination, u32 source);
extern BtlPacket *func_0019bbe0(BtlUnit *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
extern void func_001f0a10(u8 *arg0);
extern BtlPacket *func_001f36e0(s32 param_1, s32 param_2, void *param_3, s16 param_4, s16 param_5);
extern u8 *func_00199ee0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern BtlPacket *func_0019a980(BtlUnit *unit);
extern BtlPacket *func_001f81f0(u16 channel, const char *streamName);
extern BtlPacket *func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern void func_001d3e00(u32 arg0);
extern u8 D_006354B0[];
extern u8 *iGpffffb444;
extern u8 *iGpffffb3ac;
extern u8 *func_0029da90(s32 arg0, u8 *arg1, s32 arg2);
extern void func_0029dfe0(u8 *arg0, u8 *arg1);
extern u8 *func_0010d740(s16 arg0);
extern void func_00278450(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_00452570(u8 *arg0, u8 *arg1);
extern void func_00225ec0(u8 *camera);
extern u8 D_00629750[], D_00629EA0[], D_0062CA80[], D_0062D1D0[];
extern u8 D_0062E7C0[], D_0062EF10[], D_0062F660[], D_0062FDB0[];
extern u8 D_00630500[], D_00630C50[], D_006313A0[], D_00631AF0[];
extern u8 D_006355A0[];
extern void func_0010b7c0(void);
extern u8 *func_0010b010(u16 personaId);
extern s32 func_0010b300(s32 personaId);
extern void func_0019ef30(u8 *unit, u16 action);
extern void func_00106d40(s16 character, s16 slot, s16 value);
extern u16 func_00104dc0(s32 character);
extern u32 func_00104e30(s32 character);
extern void func_001056e0(s16 character, s16 value);
extern void func_00105730(s16 character, s16 value);
extern void func_00105d50(s16 character, u32 mask);
extern s32 func_001b0d70(u8 *target);

extern BtlPacket *func_00202010(u32 unit, u16 effect);
extern BtlPacket *func_001f7c20(u16 channel, u16 cue, u16 variant);
extern BtlPacket *btlUnitCreateRotateTowardUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u32 flags);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rotation, u32 flags);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *targetPosition, f32 speed, u32 flags);
extern s16 func_00199500(u8 *unit, s32 animation, f32 scale);
extern u32 func_002428f0(void *unit, s32 hpDelta);
extern s32 func_00243e30(u16 *unit);
extern s32 func_001ef4a0(s32 action);
extern u8 D_006354C0[], D_006354D0[], D_00635500[];
extern BtlPacket *func_001d3700(u16 group, u16 mask);
extern f32 fGpffff80e4;
extern f32 func_001ec2b0(void *first, void *second);
extern s32 func_004b3110(s16 frames);

// FUN_002218E0
s32 func_002218e0(KwlnTask *task)
{
    return (*(u16 *)func_00452560(task) & 4) != 0;
}
// FUN_00221910
s32 func_00221910(void)
{
    return func_00452380((s8 *)D_006290F0) != 0;
}

// FUN_00221940
s32 func_00221940(KwlnTask *task)
{
    return ((*(u16 *)func_00452560(task) & 0x10) != 0) ^ 1;
}
// FUN_00221970
s32 func_00221970(u8 *arg0)
{
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;

    temp_2 = func_00104c70(1) & 0xFF;
    temp_3 = 0;
    if (temp_2 >= 0x1E) {
        if (func_00106330(0x1202) == 0) {
            arg0[0x44] = 0xC;
            func_00106390(0x1202, 1);
            func_00106390(0x1201, 1);
            func_00106390(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x19) {
        if (func_00106330(0x1201) == 0) {
            arg0[0x44] = 0xA;
            func_00106390(0x1201, 1);
            func_00106390(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x14) {
        if (func_00106330(0x1200) == 0) {
            arg0[0x44] = 8;
            func_00106390(0x1200, 1);
            temp_3 = 1;
        }
    }
exit:
    temp_4 = temp_3;
    return temp_4;
}
// FUN_00222210
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00222210);
// FUN_00222D20 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00222d20);
// FUN_002230E0
s32 func_002230e0(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    func_0044ea90(&D_00629698, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x74, 0x40000);
    func_0043f9c8(temp_2, 0, 0x74);
    temp_16 = (s32)(func_00451fc0(arg0, &D_00629640, 0xF, 0, 0,
                                  (void *)func_00221f40,
                                  (void *)func_002230a0, temp_2));
    temp_2_2 = (u16 *)(func_00452560((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    func_0043f9c8((u8 *)(temp_2) + 0xC, 0, 0x30);
    *(void (**)(u8 *))((u8 *)(temp_2) + 0x14) = (void (*)(u8 *))(func_00222d20);
    *(u8 **)((u8 *)(temp_2) + 0x1C) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
// FUN_002231E0
void func_002231e0(KwlnTask *task) {
    u16 *temp_2;

    temp_2 = (u16 *)(func_00452560(task));
    *(s32 *)((u8 *)(temp_2) + 8) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        func_0021dda0();
        *(s32 *)((u8 *)(temp_2) + 4) = 4;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 5;
}

// FUN_00223240
s32 func_00223240(KwlnTask *task)
{
    return *(u16 *)func_00452560(task) & 1;
}
// FUN_00223270
s32 func_00223270(void)
{
    return func_00452380((s8 *)D_00629640) != 0;
}

// FUN_002232A0
/* 1036/1040 bytes; 26 code relocations and all nine switch entries exact. */
#pragma opt_propagation off
s32 func_002232a0(KwlnTask *task)
{
    u8 *work;
    u8 *results;
    u8 *persona;
    u8 *payload;
    s32 index;
    s32 messages[11];
    f32 position[2];

    work = (u8 *)func_00452560(task);
    results = *(u8 **)(work + 0x40);
    *(u32 *)(work + 8) = 0;
    *(u32 *)(work + 0xC) = 0;
    func_00460ac0(D_00795F20, work + 8);

    switch (*(u32 *)(work + 4)) {
    case 0:
        *(s32 *)(work + 0x3C) = 0;
        *(s32 *)(work + 0x38) = (u16)func_0010b6f0();
        *(u8 **)(work + 0x4C) = func_00117780(0, 15, 4, 5, 0);
        if (*(u8 **)(work + 0x4C) == 0) {
            func_0046d730(D_006296D0, 0x2F);
        }
        func_00117580(*(u8 **)(work + 0x4C), 0xAE);
        position[0] = 0.0f;
        position[1] = 19.0f;
        func_0011d100(*(u8 **)(work + 0x4C), position);
        func_0011bb90(*(u8 **)(work + 0x4C));
        *(s32 *)(work + 4) = 1;
        /* fall through */
    case 1:
        results += 0x60;
        while ((index = *(s32 *)(work + 0x3C)) < *(s32 *)(work + 0x38)) {
            u32 reward;

            persona = (u8 *)func_0010ace0((s16)index);
            reward = *(u32 *)(results + 8 + *(s32 *)(work + 0x3C) * 4);
            *(u32 *)(persona + 8) += reward;
            index = *(s32 *)(work + 0x3C);
            if (*(u8 *)(index * 0x88 + results + 0x38) > 0) {
                break;
            }
            *(s32 *)(work + 0x3C) = index + 1;
        }
        /* Constructor and transitions maintain 0 <= index <= count <= 12.
         * Consequently this arm always has a persona produced by the loop. */
        if (index != *(s32 *)(work + 0x38)) {
            s32 recordIndex;

            func_0011b480(*(u8 **)(work + 0x4C), 1, (u32)persona, 0);
            messages[0] = 12;
            messages[1] = 0;
            messages[2] = 6;
            messages[3] = 9;
            messages[4] = 10;
            messages[5] = 11;
            messages[6] = 13;
            messages[7] = 14;
            messages[8] = 19;
            messages[9] = 20;
            messages[10] = 21;
            payload = func_00455ea0(
                *(u8 **)(*(u8 **)(work + 0x40) + 0x934), 0, 0);
            recordIndex = *(s32 *)(work + 0x3C);
            *(u8 **)(work + 0x50) = func_0011f410(
                (s32)task, *(s32 *)(work + 0x4C),
                results + recordIndex * 0x88 + 0x38,
                (s32)payload, 0, messages);
            *(u16 *)work |= 2;
            *(s32 *)(work + 4) = 2;
        } else if (*(u32 *)(*(u8 **)(work + 0x40) + 0x60) & 0x10) {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
        } else {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
            *(u16 *)work |= 4;
        }
        break;
    case 2:
        *(s32 *)(work + 4) = 3;
        /* fall through */
    case 3:
        if (func_0011f560(*(u8 **)(work + 0x50)) == 0) {
            break;
        }
        func_0011f580(*(u8 **)(work + 0x50));
        *(s32 *)(work + 4) = 4;
        *(u16 *)(work + 0x48) = 0;
        /* fall through */
    case 4:
        if (++*(u16 *)(work + 0x48) < 45) {
            if ((*(u16 *)(D_008C0240 + 0xE) & 0x50) == 0) {
                if ((*(u16 *)(D_008C0240 + 0xC) & 0x10) == 0) {
                    break;
                }
                if (*(u16 *)(work + 0x48) < 4) {
                    break;
                }
            }
        }
        *(s32 *)(work + 0x3C) += 1;
        *(s32 *)(work + 4) = 1;
        break;
    case 5:
        if (func_00353f50(1) != 0) {
            break;
        }
        *(u16 *)work &= 0xFFFE;
        *(s32 *)(work + 4) = 8;
        break;
    case 6:
        if (func_0021de60() == 0) {
            break;
        }
        *(s32 *)(work + 4) = 7;
        /* fall through */
    case 7:
        if ((*(u16 *)work & 4) == 0) {
            if (++*(u16 *)(work + 0x48) < 5) {
                break;
            }
        }
        *(u16 *)work &= 0xFFFD;
        return -1;
    case 8:
    default:
        break;
    }
    return 0;
}
#pragma opt_propagation on
// FUN_002236B0
void func_002236b0(s32 arg0, u16 *arg1, s32 arg2)
{
    if ((*arg1 & 2) != 0) {
        return;
    }
}
// FUN_002236C0
void func_002236c0(KwlnTask *task)
{
    u8 *p;
    s32 h;

    p = (u8 *)func_00452560(task);
    if (*(u16 *)p & 4) {
        h = *(s32 *)(p + 0x4C);
        if (h != 0) {
            func_0011b360((u8 *)h);
            *(s32 *)(p + 0x4C) = 0;
        }
    }
    (*jtbl_008873EC)(p);
}

// FUN_00223730
s32 func_00223730(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    func_0044ea90(&D_006296E8, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x54, 0x40000);
    func_0043f9c8(temp_2, 0, 0x54);
    temp_16 = (s32)(func_00451fc0(arg0, &D_006296B0, 0xF, 0, 0,
                                  (void *)func_002232a0,
                                  (void *)func_002236c0, temp_2));
    temp_2_2 = (u16 *)(func_00452560((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x40) = (u16 *)(temp_2_2);
    func_0043f9c8((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(func_002236b0);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
// FUN_00223830
void func_00223830(KwlnTask *task) {
    u16 *temp_2;

    temp_2 = (u16 *)(func_00452560(task));
    *(s16 *)((u8 *)(temp_2) + 0x48) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        func_0021dda0();
        *(s32 *)((u8 *)(temp_2) + 4) = 6;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 7;
}

// FUN_00223890
s32 func_00223890(KwlnTask *task)
{
    return *(u16 *)func_00452560(task) & 1;
}
// FUN_002238C0
s32 func_002238c0(void)
{
    return func_00452380((s8 *)D_006296B0) != 0;
}



// FUN_00223ED0
void func_00223ed0(s32 arg0, u16 *arg1, s32 arg2)
{
    if ((*arg1 & 2) != 0) {
        return;
    }
}
// FUN_00223EE0
void func_00223ee0(KwlnTask *task)
{
    u8 *p;
    s32 h;

    p = (u8 *)func_00452560(task);
    h = *(s32 *)(p + 0x44);
    if (h != 0) {
        func_0011b360((u8 *)h);
        *(s32 *)(p + 0x44) = 0;
    }
    (*jtbl_008873EC)(p);
}

// FUN_00223F40
s32 func_00223f40(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    func_0044ea90(&D_00629738, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x4C, 0x40000);
    func_0043f9c8(temp_2, 0, 0x4C);
    temp_16 = (s32)(func_00451fc0(arg0, &D_00629700, 0xF, 0, 0,
                                  (void *)func_002239a0,
                                  (void *)func_00223ee0, temp_2));
    temp_2_2 = (u16 *)(func_00452560((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    func_0043f9c8((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(func_00223ed0);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
// FUN_00224040
void func_00224040(KwlnTask *task)
{
    u16 *temp_16;

    temp_16 = (u16 *)func_00452560(task);
    func_0021dda0();
    *(s32 *)(temp_16 + 2) = 5;
}
// FUN_00224080
s32 func_00224080(KwlnTask *task)
{
    return *(u16 *)func_00452560(task) & 1;
}
// FUN_002240B0
s32 func_002240b0(void)
{
    return func_00452380((s8 *)D_00629700) != 0;
}



// FUN_002240E0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_002240e0);
// FUN_00224450
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00224450);
// FUN_00224970
void func_00224970(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC0C) != 0) {
        func_001c8d50();
    }
}



// FUN_002249A0
/* measured: ordinary C, 1780/1792 bytes, 32 code relocations and zero
 * normalized differences; the remaining 12 bytes are zero tail alignment. */
f32 func_002249a0(u8 *actor, u8 *target, RwV3d *actorPosition, RwV3d *targetPosition)
{
    u32 actorKind;
    f32 height;

    btlUnitGetSphereWorldCenter((BtlUnit *)actor, actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, targetPosition);

    actorKind = actor[0xA2];
    if (actorKind == 0 && target[0xA2] == 1) {
        switch (*(u16 *)(target + 0xA4)) {
        case 0x100:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 3.5f;
        case 0x101:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8100 * height;
            return 4.5f;
        case 0x103:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 5.0f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 5.0f;
        case 0x104:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8128 * height;
            return 4.5f;
        case 0x105:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x106:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.75f * height;
            return 5.0f;
        case 0x10F:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x107:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff813c * height;
            return 4.5f;
        case 0x108:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 5.0f;
        case 0x10A:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x112:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 4.5f;
        case 0x113:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 6.5f;
        }
    } else if (actorKind == 1 && target[0xA2] == 0) {
        switch (*(u16 *)(actor + 0xA4)) {
        case 0x100: {
            f32 coefficient;
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            coefficient = fGpffff8100;
            actorPosition->y = (0.0f + actorPosition->y) - coefficient * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + coefficient * height;
            return 4.5f;
        }
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8100 * height;
            return 5.5f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8128 * height;
            return 5.0f;
        }
    }
    return 3.5f;
}
// FUN_002250A0
/* 1688/1696 bytes; all 36 resolved code relocations exact. */
#pragma opt_scalarize off
void func_002250a0(u8 *camera, f32 distanceOffset, f32 duration)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d offset;
    RwV3d direction;
    RwV3d eye;
    f32 baseXZ[2];
    f32 projectionXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
        RtQuat yaw;
    } geometry;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *farUnit;
    u8 *nearUnit;
    f32 framingScale;
    f32 actorRadius;
    f32 targetRadius;
    f32 length;
    f32 sideOffset;
    f32 along;
    f32 baseZ;
    f32 baseHeight;
    f32 side;
    f32 extent;
    f32 halfAngle;
    f32 distance;
    u16 flags;

    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    framingScale = func_002249a0(actor, target, &actorPosition, &targetPosition);
    actorRadius = *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    targetRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    geometry.horizontal[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    if (*(u8 *)(actor + 0xA2) == 0) {
        func_001ec1c0((u8 *)&geometry.yaw, (u8 *)&actorPosition, (u8 *)&targetPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * targetRadius;
        offset.y = offset.y * targetRadius;
        offset.z = offset.z * targetRadius;
        targetPosition.x = targetPosition.x + offset.x;
        targetPosition.y = targetPosition.y + offset.y;
        targetPosition.z = targetPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = actor;
        farUnit = target;
        basePosition = actorPosition;
        sideOffset = 1.25f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        along = fGpffff8128 * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    } else {
        func_001ec1c0((u8 *)&geometry.yaw, (u8 *)&targetPosition, (u8 *)&actorPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * actorRadius;
        offset.y = offset.y * actorRadius;
        offset.z = offset.z * actorRadius;
        actorPosition.x = actorPosition.x + offset.x;
        actorPosition.y = actorPosition.y + offset.y;
        actorPosition.z = actorPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = target;
        farUnit = actor;
        basePosition = targetPosition;
        sideOffset = 0.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        along = fGpffff80fc * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    }
    focus.x = focus.x + targetPosition.x;
    focus.y = focus.y + targetPosition.y;
    focus.z = focus.z + targetPosition.z;
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    side = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    if (!(side < 0.0f)) {
        eye.x = (0.0f + basePosition.x) + direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) - direction.x * sideOffset;
    } else {
        eye.x = (0.0f + basePosition.x) - direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) + direction.x * sideOffset;
    }
    func_001bd780(&poses.secondRotation, &eye, &focus, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                           &poses.secondRotation);
    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    extent = func_001ec3d0((u8 *)geometry.focusXZ, (u8 *)geometry.eyeXZ,
                          (u8 *)baseXZ, (u8 *)projectionXZ);
    extent = (0.0f + extent) + framingScale *
        (*(f32 *)(nearUnit + 0x90) * *(f32 *)(nearUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = baseHeight;
    eye.z = projectionXZ[1];
    halfAngle = 0.5f * *(f32 *)(camera + 0xB8);
    distance = extent / tanf(fGpffff8110 * halfAngle);
    distance = distance + distanceOffset;
    if (distance < 100.0f) {
        distance = 100.0f;
    }
    direction.x = direction.x * distance;
    direction.y = direction.y * distance;
    direction.z = direction.z * distance;
    poses.second.x = eye.x + direction.x;
    poses.second.y = eye.y + direction.y;
    poses.second.z = eye.z + direction.z;
    if (poses.second.y < 22.5f) {
        poses.second.y = 22.5f;
    }
    func_001bd560((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (!(func_001ec2b0(&poses.firstRotation,
                        &poses.secondRotation) <= fGpffff80dc)) {
        func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second);
        flags = 3;
    } else {
        flags = 0xC3;
    }
    func_001bcd40(*(u8 **)(camera + 0xE0), farUnit + 4,
                  (f32 *)&poses.second, flags, 50.0f);
    if (duration == 0.0f) {
        func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second);
        RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                               &poses.firstRotation);
        direction.x = direction.x * 150.0f;
        direction.y = direction.y * 150.0f;
        direction.z = direction.z * 150.0f;
        poses.second.x = poses.first.x + direction.x;
        poses.second.y = poses.first.y + direction.y;
        poses.second.z = poses.first.z + direction.z;
        if (poses.second.y < 22.5f) {
            poses.second.y = 22.5f;
        }
        func_001bac20((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        func_001bbef0(camera, 2.0f);
    } else {
        func_001bac20((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        func_001bbef0(camera, duration);
    }
}
#pragma opt_scalarize on
// FUN_00225740
void func_00225740(u8 *arg0)
{
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_16;
    u8 *base;
    extern s32 func_00243ce0(u8 *arg0);
    base = arg0;
    *(u16 *)(DAT_0076449c + 0xC00) = 0;
    temp_2 = *(u8 **)(base + 0xE0);
    temp_16 = *(u8 **)(temp_2 + 0x30);
    temp_4 = func_001eb440((BtlTarget *)(temp_2 + 0x38));
    if (*(u8 *)(temp_16 + 0xA2) == 0) {
        if ((temp_4 & 0xFFFF & 1) == 0) {
            if (func_001f0a50(*(u8 **)(base + 0xE0)) == 0) {
                func_002250a0(base, 0.0f, 1.0f);
            }
        } else {
            func_001c9750(base);
            *(u16 *)(DAT_0076449c + 0xC00) = 1;
        }
    } else if ((temp_4 & 0xFFFF & 2) == 0) {
        if (func_00243ce0((u8 *)*(s32 *)(temp_16 + 0xA64)) != 0) {
            func_002250a0(base, 0.0f, 1.0f);
            return;
        }
        func_001c9750(base);
        *(u16 *)(DAT_0076449c + 0xC00) = 1;
    }
}
// FUN_00225860
void func_00225860(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    if ((temp_3 != NULL) && ((*(u16 *)(temp_3 + 0x1A) & 1) != 0)) {
        temp_5 = *(u16 *)(DAT_0076449c + 0xC00);
        if (temp_5 == 1) {
            func_001c97b0(arg0);
        }
    }
}

// FUN_002258B0
/* Measured: 800/800 bytes, 20 resolved relocations, zero differences.
 * Disabling common-subexpression folding preserves the wrapping target walk. */
#pragma opt_common_subs off
void func_002258b0(u8 *camera, f32 distanceOffset, f32 duration)
{
    u8 *action;
    u8 *unit;
    u8 *target;
    u32 index;
    f32 scale;
    f32 heightScale;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL && (*(u16 *)(action + 0x1A) & 1) != 0) {
        if (action != NULL &&
            *(u8 *)((unit = *(u8 **)(action + 0x30)) + 0xA2) == 0) {
            index = 0;
            while ((action = *(u8 **)(camera + 0xE0)),
                   (u16)index < *(u16 *)(action + 0x6A)) {
                target = *(u8 **)(action + 0x38 + (u16)index * 4);
                target = *(u8 **)(target + 0x30);
                if (*(u8 *)(target + 0xA2) == 1) {
                    func_00195590((BtlUnit *)target, (const RwV3d *)(unit + 4));
                }
                index = (u16)(index + 1);
            }
        }
        unit = *(u8 **)(action + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            func_001c9820(camera, 0, 1, 0.0f);
            return;
        }
        target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
        scale = 1.5f;
        heightScale = fGpffff803c;
        switch (*(u16 *)(unit + 0xA4)) {
        case 0x100:
            scale = 1.75f;
            heightScale = 0.0f;
            break;
        case 0x101:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x102:
            scale = 3.75f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8174;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x103:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x104:
            scale = 4.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8030;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x105:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x106:
            scale = 2.25f;
            heightScale = 0.0f;
            break;
        case 0x10F:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x107:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x108:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = 0.0f;
            } else {
                heightScale = fGpffff817c;
            }
            break;
        case 0x10A:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x10B:
            scale = 3.5f;
            heightScale = 0.0f;
            break;
        case 0x112:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        default:
            break;
        }
        func_002266b0(camera, heightScale, scale, distanceOffset, duration);
    }
}
#pragma opt_common_subs on
// FUN_00225BD0
void func_00225bd0(u8 *arg0)
{
    func_002258b0(arg0, 0.0f, 2.0f);
}



// FUN_00225C00
void func_00225c00(u8 *arg0)
{
    u8 *self;
    u8 *temp_3;

    self = arg0;
    temp_3 = *(u8 **)(self + 0xE0);
    if (temp_3 != NULL) {
        if (func_00243ce0((u8 *)*(s32 *)(*(u8 **)(temp_3 + 0x30) + 0xA64)) != 0) {
            if (func_0019fe60(*(u8 **)(self + 0xE0), 0, 0) != 0) {
                func_002258b0(self, 0.0f, 0.75f);
            } else {
                func_002250a0(self, 0.0f, 0.75f);
            }
            arg0 = (u8 *)(s64)(s16)func_001998e0(
                *(u8 **)(*(u8 **)(self + 0xE0) + 0x30), 4);
            *(s16 *)(self + 0x10E) =
                func_001999f0(*(u8 **)(*(u8 **)(self + 0xE0) + 0x30),
                              4, 1.0f, (s64)((u32)arg0 & 0xFFFF));
            *(s16 *)(self + 0x10C) = 0;
            *(s32 *)(self + 0x100) = *(s32 *)(*(u8 **)(self + 0xE0) + 0x38);
            return;
        }
        func_001cbf80(self);
    }
}
/* measured 00225d00 plain-C reconstruction matches the complete 256-byte retail window at normalized_diff 0. */
#pragma optimization_level 1
// FUN_00225D00
void func_00225d00(u8 *arg0)
{
    u32 temp_4;
    s32 temp_3;
    u8 *temp_5;
    extern s32 func_00243ce0(u8 *arg0);

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x100) == *(s32 *)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (func_00243ce0((u8 *)*(s32 *)(*(u8 **)(temp_5 + 0x30) + 0xA64)) == 0) {
            func_001cbfe0((int)arg0);
            return;
        }
        temp_4 = *(u16 *)(arg0 + 0x10E);
        temp_3 = *(u16 *)(arg0 + 0x10C) + 1;
        *(u16 *)(arg0 + 0x10C) = temp_3;
        temp_3 = (u16)temp_3;
        if (temp_4 != temp_3) {
            return;
        }
        if (func_0019fe60(*(u8 **)(arg0 + 0xE0), 0, 0) != 0) {
            func_002258b0(arg0, 400.0f, fGpffff809c);
            return;
        }
        func_002250a0(arg0, 400.0f, fGpffff809c);
    }
}
#pragma optimization_level 2
// FUN_00225E50
void func_00225e50(u8 *arg0)
{
    s32 iVar1;

    iVar1 = *(s32 *)(arg0 + 0xE0);
    if ((((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u8 *)(*(s32 *)(iVar1 + 0x30) + 0xA2) != 0)) &&
        (((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u16 *)(DAT_0076449c + 0xC00) == 1))) {
        func_001c97b0(arg0);
    }
}

// FUN_00225EC0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225ec0);
// FUN_002266B0
/* measured: opt_scalarize off retains the real horizontal vector stores.
 * Staged radius scaling and the scoped two-halfword skill table give
 * 1420/1424 bytes, 21 code relocations and zero normalized differences. */
#pragma opt_scalarize off
void func_002266b0(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d targetSnapshot;
    RwV3d center;
    RwV3d direction;
    RwV3d eye;
    RwV3d originalDirection;
    f32 targetXZ[2];
    f32 projected[2];
    f32 eyeXZ[2];
    f32 centerXZ[2];
    f32 previousView[2];
    f32 perpendicular[2];
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *actor;
    u8 *target;
    u16 skill;
    f32 actorHeight;
    f32 separation;
    f32 centerOffset;
    f32 targetRadius;
    f32 lateralRadius;
    f32 side;
    f32 targetZ;
    f32 targetY;
    f32 fitRadius;
    f32 distance;
    f32 stepX;
    f32 stepY;
    f32 stepZ;
    f32 endDistance;

    actor = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    target = *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetPosition);
    actorHeight = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
    actorPosition.y = (0.0f + actorPosition.y) + heightScale * actorHeight;
    if (!((0.0f + actorPosition.y) + 0.5f * actorHeight < 450.0f)) {
        actorPosition.y = (0.0f + actorPosition.y) - fGpffff8030 * actorHeight;
    }
    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    separation = RwV3dNormalize(&direction, &direction);
    previousView[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    previousView[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(previousView, previousView);
    centerOffset = fGpffff8128 * separation;
    center.x = direction.x * centerOffset;
    center.y = direction.y * centerOffset;
    center.z = direction.z * centerOffset;
    center.x = center.x + targetPosition.x;
    center.y = center.y + targetPosition.y;
    center.z = center.z + targetPosition.z;
    perpendicular[0] = direction.x;
    perpendicular[1] = direction.z;
    targetSnapshot = targetPosition;
    targetRadius = *(f32 *)(target + 0x90);
    targetRadius = targetRadius * *(f32 *)(target + 0x2C);
    lateralRadius = 1.5f * targetRadius;
    {
        f32 x = perpendicular[0];
        perpendicular[0] = perpendicular[1];
        perpendicular[1] = -x;
    }
    side = perpendicular[0] * previousView[0] + perpendicular[1] * previousView[1];
    targetY = targetSnapshot.y;
    eye.y = (0.0f + targetY) + 0.25f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    if (!(side < 0.0f)) {
        eye.x = (0.0f + targetSnapshot.x) + direction.z * lateralRadius;
        targetZ = targetSnapshot.z;
        eye.z = (0.0f + targetZ) - direction.x * lateralRadius;
    } else {
        eye.x = (0.0f + targetSnapshot.x) - direction.z * lateralRadius;
        targetZ = targetSnapshot.z;
        eye.z = (0.0f + targetZ) + direction.x * lateralRadius;
    }
    originalDirection = direction;
    func_001bd780(&poses.firstRotation, &eye, &center, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &poses.firstRotation);
    centerXZ[0] = center.x;
    centerXZ[1] = center.z;
    eyeXZ[0] = eye.x;
    eyeXZ[1] = eye.z;
    targetXZ[0] = targetSnapshot.x;
    targetXZ[1] = targetZ;
    fitRadius = func_001ec3d0((u8 *)centerXZ, (u8 *)eyeXZ, (u8 *)targetXZ, (u8 *)projected);
    fitRadius = (0.0f + fitRadius) + scale * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
    eye.x = projected[0];
    eye.y = targetY;
    eye.z = projected[1];
    distance = fitRadius / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    if (distance < 200.0f) {
        distance = 200.0f;
    }
    skill = *(u16 *)(*(u8 **)(camera + 0xE0) + 0x6E);
    if (skill < 0x1B8) {
        u16 (*table)[2] = (u16 (*)[2])iGpffffb3bc;
        if ((table[skill][1] & 0x400) != 0) {
            distance = distance + 150.0f;
        }
    }
    stepX = direction.x * (distance - 15.0f);
    stepY = direction.y * (distance - 15.0f);
    stepZ = direction.z * (distance - 15.0f);
    if (!(side < 0.0f)) {
        f32 radius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
        eye.x = (0.0f + eye.x) - originalDirection.z * radius;
        eye.z = (0.0f + eye.z) + originalDirection.x * radius;
    }
    eye.y = (0.0f + targetY) + 0.25f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    poses.first.x = eye.x + stepX;
    poses.first.y = eye.y + stepY;
    poses.first.z = eye.z + stepZ;
    poses.secondRotation = poses.firstRotation;
    endDistance = 100.0f + (distance + distanceOffset);
    poses.second.x = (0.0f + eye.x) + direction.x * endDistance;
    poses.second.y = (0.0f + eye.y) + direction.y * endDistance;
    poses.second.z = (0.0f + eye.z) + direction.z * endDistance;
    if (poses.first.y < 25.0f) {
        poses.first.y = 25.0f;
    }
    if (poses.second.y < 25.0f) {
        poses.second.y = 25.0f;
    }
    func_001bc3a0((f32 *)&poses.first, (f32 *)&poses.first);
    func_001bc3a0((f32 *)&poses.second, (f32 *)&poses.second);
    func_001bcd40(*(u8 **)(camera + 0xE0), actor + 4, (f32 *)(target + 4), 3, 50.0f);
    func_001bac20((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    func_001bbef0(camera, duration);
}
#pragma opt_scalarize on
// FUN_00226C40
/* 1516/1520 bytes, 48 resolved code relocations and all
 * seven switch targets match retail; four zero tail-alignment bytes. */
#pragma opt_common_subs off
void func_00226c40(u8 *camera)
{
    RwRGBA color;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *subordinate;
    u8 *target;
    u8 *node;
    u8 *record;
    u32 index;
    u32 ordinal;
    u16 partyIndex;
    u16 variant;
    u32 frames;
    s32 matchesSubordinate;

    action = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(action + 0x30);
    subordinate = *(u8 **)(unit + 0xA0C);
    if (action != NULL && *(u8 *)(unit + 0xA2) == 0) {
        index = 0;
        while ((action = *(u8 **)(camera + 0xE0)),
               (u16)index < *(u16 *)(action + 0x6A)) {
            target = *(u8 **)(action + 0x38 + (u16)index * 4);
            target = *(u8 **)(target + 0x30);
            if (*(u8 *)(target + 0xA2) == 1) {
                func_00195590((BtlUnit *)target, (const RwV3d *)(unit + 4));
            }
            index = (u16)(index + 1);
        }
    }
    *(u16 *)(camera + 0x110) = func_001c0e50(camera);
    matchesSubordinate = subordinate != NULL &&
        func_0022f950(*(u8 **)(camera + 0xE0), subordinate) != 0;
    if (matchesSubordinate && *(u16 *)(camera + 0x110) != 1) {
        func_0019d0c0(subordinate);
        color.red = *(u8 *)(subordinate + 0x30);
        color.green = *(u8 *)(subordinate + 0x31);
        color.blue = *(u8 *)(subordinate + 0x32);
        color.alpha = 0;
        btlUnitSetColor((BtlUnit *)subordinate, color);
    }
    func_0019de70((BtlUnitStateWork *)subordinate, 0);
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
    case 1:
    case 2:
    case 4:
        func_001c5110(camera);
        action = *(u8 **)(camera + 0xE0);
        if (*(u16 *)(action + 0x6A) != 1) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) != 0) {
            break;
        }
        target = *(u8 **)(action + 0x38);
        if (action == target) {
            break;
        }
        if (*(u8 *)(*(u8 **)(target + 0x30) + 0xA2) != 0) {
            break;
        }
        func_001bcd40(action, NULL, NULL, 8, 0.0f);
        break;
    case 3:
    case 5:
        action = *(u8 **)(camera + 0xE0);
        unit = *(u8 **)(action + 0x30);
        variant = func_00231d70(2);
        if (*(u8 *)(unit + 0xA2) != 0) {
            partyIndex = 0;
        } else {
            ordinal = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node) {
                    break;
                }
                ordinal = (u16)(ordinal + 1);
                node = *(u8 **)(node + 0xA68);
            }
            partyIndex = (u16)ordinal;
        }
        record = *(u8 **)(iGpffffb3ac + 0xB98) +
                 (u16)partyIndex * 0x68 + (u16)variant * 0x34 + 0x3A8;
        func_001bd780(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
        selected.first = *(RwV3d *)(record + 4);
        func_001bd780(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
        selected.second = *(RwV3d *)(record + 0x1C);
        frames = *(u16 *)record;
        duration = (f32)frames / 30.0f;
        func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                      (f32 *)&selected.first, (f32 *)&selected.second, 1);
        func_001bbef0(iGpffffb3ac + 0x24, duration);
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            func_001bd780(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            func_001bd780(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        } else {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            func_001bd780(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            func_001bd780(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    default:
        break;
    }
}
#pragma opt_common_subs on
// FUN_00227230
/* 1336/1344 bytes, 48 resolved code relocations and all
 * seven switch targets match retail; eight zero tail-alignment bytes. */
void func_00227230(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *record;
    u16 targetFlags;
    u16 variant;
    u32 frames;

    *(u16 *)(camera + 0x110) = func_001c0e50(camera);
    targetFlags = func_001eb440((BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38));
    *(u32 *)(camera + 0x12C) = 0;
    action = *(u8 **)(camera + 0xE0);
    if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
        func_0019de70(*(BtlUnitStateWork **)(*(u8 **)(action + 0x30) + 0xA0C), 1);
    }
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
        break;
    case 1:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
            func_001c5110(camera);
            break;
        }
    case 2:
        if (((u16)targetFlags & 2) == 0) {
            func_002266b0(camera, 0.0f, 3.0f, 0.0f, 2.0f);
            break;
        }
    case 4:
        if (((u16)targetFlags & 2) == 0) {
            if (func_00243ce0(*(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x30) + 0xA64)) != 0 &&
                func_0019fc70(*(u8 **)(camera + 0xE0)) != 0) {
                func_002250a0(camera, 0.0f, 0.75f);
                break;
            }
            func_002266b0(camera, 0.0f, 3.0f, 0.0f, 2.0f);
            break;
        }
    case 3:
    case 5:
        if (((u16)targetFlags & 2) != 0) {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
            func_001bd780(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            selected.first = *(RwV3d *)(record + 4);
            func_001bd780(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            selected.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&selected.first, (f32 *)&selected.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
            func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
            break;
        }
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            func_001bd780(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            func_001bd780(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        } else {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            func_001bd780(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            func_001bd780(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    default:
        break;
    }
}
// FUN_00227770
void func_00227770(u8 *arg0)
{
    u8 *temp_3;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0x12C);
    if (temp_5 != NULL) {
        temp_3 = *(u8 **)(arg0 + 0xE0);
        if ((temp_3 != NULL) &&
            ((*(u16 *)(temp_3 + 0x1A) & 1) != 0) &&
            (func_001bc560(arg0, temp_5) != 0)) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}


// FUN_002277E0
/* measured: opt_common_subs off preserves per-use 16-bit ordinal masks.
 * Independent target/party ordinals and the materialized subordinate predicate
 * give 1620/1632 bytes, 50 code relocations and zero normalized differences.
 * Each pose pair is two contiguous seven-float poses, without padding. */
#pragma opt_common_subs off
void func_002277e0(u8 *camera)
{
    RwRGBA color;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *subordinate;
    u8 *target;
    u8 *node;
    u8 *record;
    u32 index;
    u32 ordinal;
    u16 partyIndex;
    u16 variant;
    u32 frames;
    s32 matchesSubordinate;

    action = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(action + 0x30);
    subordinate = *(u8 **)(unit + 0xA0C);
    if (action != NULL && *(u8 *)(unit + 0xA2) == 0) {
        index = 0;
        while ((action = *(u8 **)(camera + 0xE0)),
               (u16)index < *(u16 *)(action + 0x6A)) {
            target = *(u8 **)(action + 0x38 + (u16)index * 4);
            target = *(u8 **)(target + 0x30);
            if (*(u8 *)(target + 0xA2) == 1) {
                func_00195590((BtlUnit *)target, (const RwV3d *)(unit + 4));
            }
            index = (u16)(index + 1);
        }
    }
    *(u16 *)(camera + 0x110) = func_001c0e50(camera);
    matchesSubordinate = subordinate != NULL &&
        func_0022f950(*(u8 **)(camera + 0xE0), subordinate) != 0;
    if (matchesSubordinate && *(u16 *)(camera + 0x110) != 1) {
        func_0019d0c0(subordinate);
        color.red = *(u8 *)(subordinate + 0x30);
        color.green = *(u8 *)(subordinate + 0x31);
        color.blue = *(u8 *)(subordinate + 0x32);
        color.alpha = 0;
        btlUnitSetColor((BtlUnit *)subordinate, color);
    }
    func_0019de70((BtlUnitStateWork *)subordinate, 0);
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
    case 1:
        func_001c5110(camera);
        action = *(u8 **)(camera + 0xE0);
        if (*(u16 *)(action + 0x6A) != 1) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) != 0) {
            break;
        }
        target = *(u8 **)(action + 0x38);
        if (*(u8 *)(*(u8 **)(target + 0x30) + 0xA2) != 0) {
            break;
        }
        func_001bcd40(action, NULL, NULL, 8, 0.0f);
        break;
    case 2:
    case 4:
        action = *(u8 **)(camera + 0xE0);
        if (*(u16 *)(action + 0x6A) == 1 &&
            *(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0 &&
            (target = *(u8 **)(action + 0x38), action != target) &&
            *(u8 *)(*(u8 **)(target + 0x30) + 0xA2) == 0) {
            func_001c5110(camera);
            func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 8, 0.0f);
            break;
        }
    case 3:
    case 5:
        action = *(u8 **)(camera + 0xE0);
        unit = *(u8 **)(action + 0x30);
        variant = func_00231d70(2);
        if (*(u8 *)(unit + 0xA2) != 0) {
            partyIndex = 0;
        } else {
            ordinal = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node) {
                    break;
                }
                ordinal = (u16)(ordinal + 1);
                node = *(u8 **)(node + 0xA68);
            }
            partyIndex = (u16)ordinal;
        }
        record = *(u8 **)(iGpffffb3ac + 0xB98) +
                 (u16)partyIndex * 0x68 + (u16)variant * 0x34 + 0x3A8;
        func_001bd780(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
        selected.first = *(RwV3d *)(record + 4);
        func_001bd780(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
        selected.second = *(RwV3d *)(record + 0x1C);
        frames = *(u16 *)record;
        duration = (f32)frames / 30.0f;
        func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                      (f32 *)&selected.first, (f32 *)&selected.second, 1);
        func_001bbef0(iGpffffb3ac + 0x24, duration);
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            func_001bd780(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            func_001bd780(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        } else {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            func_001bd780(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            func_001bd780(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    default:
        break;
    }
}
/* measured: closing opt_common_subs off for func_002277e0. */
#pragma opt_common_subs on
// FUN_00227E40
/* measured: 1168/1168 bytes, 44 code relocations and zero differences.
 * Preserve the switch fallthrough's repeated target-kind tests and the
 * three distinct, contiguous seven-float pose pairs. No extra pragma. */
void func_00227e40(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *record;
    u16 targetFlags;
    u16 variant;
    u32 frames;

    *(u16 *)(camera + 0x110) = func_001c0e50(camera);
    targetFlags = func_001eb440((BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38));
    *(u32 *)(camera + 0x12C) = 0;
    action = *(u8 **)(camera + 0xE0);
    if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
        func_0019de70(*(BtlUnitStateWork **)(*(u8 **)(action + 0x30) + 0xA0C), 1);
    }
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
        break;
    case 1:
    case 2:
        if (((u16)targetFlags & 2) == 0) {
            func_002240e0(camera);
            break;
        }
        /* Fall through: state 4 has its own identical target-kind test. */
    case 4:
        if (((u16)targetFlags & 2) == 0) {
            func_002240e0(camera);
            break;
        }
        /* Fall through to the shared selected-target camera. */
    case 3:
    case 5:
        if (((u16)targetFlags & 2) != 0) {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
            func_001bd780(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            selected.first = *(RwV3d *)(record + 4);
            func_001bd780(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            selected.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&selected.first, (f32 *)&selected.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
            func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
            break;
        }
        /* Fall through: absent genus-1 targets use the state-6 camera. */
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            func_001bd780(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            func_001bd780(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        } else {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            func_001bd780(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            func_001bd780(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    default:
        break;
    }
}
// FUN_002282D0
void func_002282d0(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 index;
    u32 temp_2_2;
    u8 *base;
    u16 *raw;
    u8 *temp_17;
    extern void func_001b73f0(u8 *arg0);
    extern void func_001bf5e0();

    if (func_00243ce0(
            (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA64)) != 0) {
        func_001b73f0(0);
        index = (u32)(func_00231d70(2) & 0xFFFF);
        base = *(u8 **)(DAT_0076449c + 0xB98);
        temp_17 = base + index * 0x34 + 0x548;
        func_001bd780(work.quat1, temp_17 + 4, temp_17 + 0x10,
                      D_0060A0E0);
        work.first = *(Vec3 *)(temp_17 + 4);
        func_001bd780(work.quat2, temp_17 + 0x1C, temp_17 + 0x28,
                      D_0060A0E0);
        work.second = *(Vec3 *)(temp_17 + 0x1C);
        raw = (u16 *)temp_17;
        temp_2_2 = *raw;
        if (temp_2_2 >= 0) {
            var_f1 = (f32)temp_2_2;
        } else {
            temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
            var_f1 = (f32)(s32)temp_2_2;
            var_f1 = var_f1 + var_f1;
        }
        var_f1 = var_f1 / 30.0f;
        func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                      (f32 *)&work.second, 1);
        func_001bbef0(DAT_0076449c + 0x24, var_f1);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 1, 0);
        return;
    }
    func_001bf5e0(arg0);
}
// FUN_00228480
void func_00228480(u8 *arg0) {
    if (func_00243ce0((u8 *)*(s32 *)((u8 *)(*(u8 **)((u8 *)(*(u8 **)((u8 *)(arg0) + 0xE0)) + 0x30)) + 0xA64)) == 0) {
        func_001bfb70(arg0);
    }
}

// FUN_002284D0
void func_002284d0(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        f32 first[7];
        Vec3 second;
        f32 third[4];
    } work;
    f32 *temp_16;
    u8 *temp_2;

    func_001bd560((f32 *)&work.first, (f32 *)(arg0 + 0x9C));
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98);
    temp_16 = (f32 *)(temp_2 + 0x6B4);
    func_001bd780(work.third, temp_16, (u8 *)temp_16 + 0xC, D_0060A0E0);
    work.second = *(Vec3 *)temp_16;
    func_001bac20((u16 *)arg0, (f32 *)&work.first, (f32 *)&work.second, 1);
    func_001bbef0(arg0, 0.75f);
}
// FUN_00228580
void func_00228580(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 index;
    u16 temp_2_2;
    u8 *base;
    u8 *temp_16;
    u8 *temp_2;

    index = (u32)(func_00231d70(2) & 0xFFFF);
    base = *(u8 **)(DAT_0076449c + 0xB98);
    temp_2 = base + index * 0x34;
    temp_16 = temp_2 + 0x64C;
    func_001bd780(work.quat1, temp_16 + 4, temp_16 + 0x10, D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    func_001bd780(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
        D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    var_f1 = (f32)temp_2_2 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
}
// FUN_002286C0
void func_002286c0(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 index;
    u16 temp_2_2;
    u8 *base;
    u8 *temp_16;
    u8 *temp_2;

    index = (u32)(func_00231d70(2) & 0xFFFF);
    base = *(u8 **)(DAT_0076449c + 0xB98);
    temp_2 = base + index * 0x34;
    temp_16 = temp_2 + 0x5B0;
    func_001bd780(work.quat1, temp_16 + 4, temp_16 + 0x10, D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    func_001bd780(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
        D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    var_f1 = (f32)temp_2_2 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
}
// FUN_00228800
void func_00228800(s32 arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vector3;
    struct {
        Vector3 position;
        u8 transform[20];
    } values;
    f32 *temp;

    temp = (f32 *)(*(u8 **)(DAT_0076449c + 0xB98) + 0x6CC);
    func_001bd780(values.transform, temp, temp + 3, D_0060A0E0);
    values.position = *(Vector3 *)temp;
    func_001bab00((u16 *)(DAT_0076449c + 0x24), (f32 *)&values.position);
    func_001bd5a0((f32 *)((u8 *)arg0 + 0x9C), (f32 *)&values.position);
}
// FUN_00228890
void func_00228890(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 temp_2_2;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = *(u8 **)(DAT_0076449c + 0xB98);
    temp_16 = temp_2 + 0x6E4;
    func_001bd780(work.quat1, temp_16 + 4, temp_16 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    func_001bd780(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
}
// FUN_002289B0
void func_002289b0(u8 *arg0)
{
    u16 temp_16;
    u32 flag_offset;
    u32 index_offset;
    u8 *temp_2;
    u8 *target;

    temp_2 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(temp_2 + 0x30);
    temp_16 = *(u16 *)(temp_2 + 0xA4);
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = (temp_16 & 0xFFFF) * 0x1E8;
    target = (u8 *)&D_00632240 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 8);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 3, 0.0f);
}
// FUN_00228A60
void func_00228a60(void)
{
    func_001bdeb0();
}

// FUN_00228A80
void func_00228a80(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    s32 temp_5;
    s32 var_2;
    u8 *var_4;
    s32 var_3;
    u16 temp_16;
    u32 flag_offset;
    u32 index_offset;
    u32 temp_2_2;
    u8 *temp_16_2;
    u8 *temp_17;
    u8 *temp_2;
    extern u8 D_00633740[];

    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp_16 = *(u16 *)(temp_17 + 0xA4);
    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        flag_offset = (func_004bd050(0) & 1) * 0xF4;
        index_offset = ((temp_16 & 0xFFFF) - 2) * 0x1E8;
        func_001bdd80(arg0, (u8 *)&D_00633740 + index_offset + flag_offset, 8);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 3, 0);
        return;
    }
    temp_5 = func_00231d70(2) & 0xFFFF;
    if (*(u8 *)(temp_17 + 0xA2) != 0) {
        var_2 = 0;
    } else {
        var_3 = 0;
        var_4 = *(u8 **)(DAT_0076449c + 0x17C);
        goto loop_7_check;
loop_7:
        if (temp_17 == var_4) {
            goto loop_7_done;
        }
        var_3 = (var_3 + 1) & 0xFFFF;
        var_4 = *(u8 **)(var_4 + 0xA68);
        goto loop_7_check;
loop_7_check:
        if (var_4 != NULL) {
            goto loop_7;
        }
loop_7_done:
        var_2 = var_3 & 0xFFFF;
    }
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98) +
             ((var_2 & 0xFFFF) * 0x68) +
             ((temp_5 & 0xFFFF) * 0x34);
    temp_16_2 = temp_2 + 0x3A8;
    func_001bd780(work.quat1, temp_16_2 + 4, temp_16_2 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16_2 + 4);
    func_001bd780(work.quat2, temp_16_2 + 0x1C, temp_16_2 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16_2 + 0x1C);
    temp_2_2 = *(u16 *)temp_16_2;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
}
// FUN_00228D00
void func_00228d00(u8 *arg0) {
    if (func_001f0ff0(*(u8 **)((u8 *)(arg0) + 0xE0)) != 0) {
        func_001bdeb0(arg0);
    }
}

// FUN_00228D50
void func_00228d50(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    s32 temp_5;
    s32 var_2;
    u8 *var_4;
    s32 var_3;
    u32 temp_2_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_2;

    if (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA2) == 0) {
        func_00225ec0(arg0);
        return;
    }
    temp_16 = *(u8 **)(*(u8 **)(DAT_0076449c + 0x170) + 0x30);
    temp_5 = func_00231d70(2) & 0xFFFF;
    if (*(u8 *)(temp_16 + 0xA2) != 0) {
        var_2 = 0;
    } else {
        var_3 = 0;
        var_4 = *(u8 **)(DAT_0076449c + 0x17C);
        goto loop_7_check;
loop_7:
        if (temp_16 == var_4) {
            goto loop_7_done;
        }
        var_3 = (var_3 + 1) & 0xFFFF;
        var_4 = *(u8 **)(var_4 + 0xA68);
        goto loop_7_check;
loop_7_check:
        if (var_4 != NULL) {
            goto loop_7;
        }
loop_7_done:
        var_2 = var_3 & 0xFFFF;
    }
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98) +
             ((var_2 & 0xFFFF) * 0x68) +
             ((temp_5 & 0xFFFF) * 0x34);
    temp_16_2 = temp_2 + 0x3A8;
    func_001bd780(work.quat1, temp_16_2 + 4, temp_16_2 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16_2 + 4);
    func_001bd780(work.quat2, temp_16_2 + 0x1C, temp_16_2 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16_2 + 0x1C);
    temp_2_2 = *(u16 *)temp_16_2;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    func_001bac20((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    func_001bbef0(DAT_0076449c + 0x24, var_f1);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
}
// FUN_00228F60
void func_00228f60(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vector3;
    struct {
        Vector3 position;
        u8 transform[20];
    } values;
    f32 *temp;
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(temp_2 + 0x30);
    if (*(u8 *)(temp_2 + 0xA2) != 0) {
        goto body;
    }
    func_00225ec0(arg0);
    return;
body:
    temp = (f32 *)(*(u8 **)(DAT_0076449c + 0xB98) + 0x6CC);
    func_001bd780(values.transform, temp, temp + 3, D_0060A0E0);
    values.position = *(Vector3 *)temp;
    func_001bab00((u16 *)(DAT_0076449c + 0x24), (f32 *)&values.position);
    func_001bd5a0((f32 *)((u8 *)arg0 + 0x9C), (f32 *)&values.position);
}

/* 2444/2448 bytes; all 56 resolved code relocations exact. */
#pragma opt_scalarize off
// FUN_00229020
void func_00229020(u8 *camera)
{
    RwV3d firstCenter;
    RwV3d secondCenter;
    RwV3d lookAt;
    RwV3d anchor;
    RwV3d direction;
    f32 firstXZ[2];
    f32 projectedXZ[2];
    f32 sideXZ[2];
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    };
    struct {
        f32 lookAtXZ[2];
        f32 anchorXZ[2];
        f32 perpendicular[2];
        f32 cameraSide[2];
        struct CameraPosePair poses;
    } geometry;
    struct CameraPosePair player, other;
    f32 side;
    f32 radius;
    f32 firstHeight;
    f32 secondHeight;
    f32 distance;
    f32 scale;
    f32 angle;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *first;
    u8 *second;
    u8 *target;
    u8 *record;
    u32 index;
    u32 frames;
    u16 variant;
    s32 reverseSide;
    s32 allowCut;
    s32 forceActorSide;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL) {
        unit = *(u8 **)(action + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            index = 0;
            while ((action = *(u8 **)(camera + 0xE0)),
                   (u16)index < *(u16 *)(action + 0x6A)) {
                target = *(u8 **)(action + 0x38 + (index & 0xFFFF) * 4);
                target = *(u8 **)(target + 0x30);
                if (*(u8 *)(target + 0xA2) == 1) {
                    func_00195590((BtlUnit *)target, (const RwV3d *)(unit + 4));
                }
                index = (u16)(index + 1);
            }
        }
    }
    if (action == NULL) {
        allowCut = 1;
    } else if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
        switch (*(u16 *)(iGpffffb3ac + 0x108)) {
        case 0x21:
        case 0x22:
            allowCut = 0;
            break;
        default:
            goto allow_cut;
        }
    } else {
        switch (*(u16 *)(iGpffffb3ac + 0x108)) {
        case 0x16:
        case 0x24:
            allowCut = 0;
            break;
        default:
allow_cut:
            allowCut = 1;
            break;
        }
    }
    second = *(u8 **)(action + 0x30);
    if (*(u8 *)(second + 0xA2) == 0) {
        target = (u8 *)*(u32 *)(camera + 0xE0);
        first = second;
        target = *(u8 **)(target + 0x38);
        second = *(u8 **)(target + 0x30);
        reverseSide = 0;
        forceActorSide = 1;
    } else {
        target = *(u8 **)((u8 *)*(u32 *)(camera + 0xE0) + 0x38);
        first = *(u8 **)(target + 0x30);
        reverseSide = 1;
        forceActorSide = 0;
    }
    if (*(u8 *)(first + 0xA2) == *(u8 *)(second + 0xA2)) {
        if (*(u8 *)(first + 0xA2) == 0) {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            func_001bd780(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            func_001bd780(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        } else {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
            func_001bd780(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            func_001bd780(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        }
        return;
    }

    func_001bd560((f32 *)&geometry.poses.first, (f32 *)(camera + 0x9C));
    func_001958f0((BtlUnit *)first, &firstCenter);
    func_001958f0((BtlUnit *)second, &secondCenter);
    radius = *(f32 *)(first + 0x90) * *(f32 *)(first + 0x2C);
    firstHeight = (0.0f + firstCenter.y) + 0.5f *
        (*(f32 *)(first + 0x8C) * *(f32 *)(first + 0x2C));
    secondHeight = (0.0f + secondCenter.y) + 0.5f *
        (*(f32 *)(second + 0x8C) * *(f32 *)(second + 0x2C));
    direction.x = firstCenter.x - secondCenter.x;
    direction.y = firstCenter.y - secondCenter.y;
    direction.z = firstCenter.z - secondCenter.z;
    scale = fGpffff8118 * RwV3dNormalize(&direction, &direction);
    lookAt.x = direction.x * scale;
    lookAt.y = direction.y * scale;
    lookAt.z = direction.z * scale;
    lookAt.x += secondCenter.x;
    lookAt.y += secondCenter.y;
    lookAt.z += secondCenter.z;
    geometry.cameraSide[0] = *(f32 *)(camera + 0x9C) - lookAt.x;
    geometry.cameraSide[1] = *(f32 *)(camera + 0xA4) - lookAt.z;
    func_003e41e0(geometry.cameraSide, geometry.cameraSide);
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    side = geometry.perpendicular[0] * geometry.cameraSide[0] + geometry.perpendicular[1] * geometry.cameraSide[1];
    if (reverseSide == 0) {
        scale = 1.5f * radius;
    } else {
        scale = 2.5f * radius;
    }
    if (!(side < 0.0f)) {
        anchor.x = (0.0f + firstCenter.x) + direction.z * scale;
        anchor.z = (0.0f + firstCenter.z) - direction.x * scale;
    } else {
        anchor.x = (0.0f + firstCenter.x) - direction.z * scale;
        anchor.z = (0.0f + firstCenter.z) + direction.x * scale;
    }
    if (reverseSide == 0) {
        if (firstHeight < secondHeight) {
            anchor.y = firstHeight;
            lookAt.y = (0.0f + lookAt.y) - fGpffff8118 * secondHeight;
        } else {
            anchor.y = (0.0f + firstCenter.y) - fGpffff8030 * firstHeight;
            lookAt.y = (0.0f + lookAt.y) + fGpffff8030 * secondHeight;
        }
        distance = 2.5f * radius;
    } else {
        anchor.y = firstHeight;
        lookAt.y = (0.0f + lookAt.y) - fGpffff8118 * secondHeight;
        distance = 3.5f * radius;
    }
    func_001bd780(&geometry.poses.secondRotation, &anchor, &lookAt, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &geometry.poses.secondRotation);
    geometry.lookAtXZ[0] = lookAt.x;
    geometry.lookAtXZ[1] = lookAt.z;
    geometry.anchorXZ[0] = anchor.x;
    geometry.anchorXZ[1] = anchor.z;
    firstXZ[0] = firstCenter.x;
    firstXZ[1] = firstCenter.z;
    scale = func_001ec3d0((u8 *)geometry.lookAtXZ, (u8 *)geometry.anchorXZ, (u8 *)firstXZ, (u8 *)projectedXZ);
    scale += distance;
    distance = scale;
    anchor.x = projectedXZ[0];
    anchor.z = projectedXZ[1];
    distance /= tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    direction.x *= distance;
    direction.y *= distance;
    direction.z *= distance;
    if (side < 0.0f) {
        scale = distance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        scale *= 0.21875f;
        firstHeight = scale;
        firstHeight *= 1.25f;
        sideXZ[0] = direction.x;
        sideXZ[1] = direction.z;
        func_003e41e0(sideXZ, sideXZ);
        anchor.x = (0.0f + anchor.x) + sideXZ[1] * firstHeight;
        anchor.z = (0.0f + anchor.z) - sideXZ[0] * firstHeight;
    }
    geometry.poses.second.x = anchor.x + direction.x;
    geometry.poses.second.y = anchor.y + direction.y;
    geometry.poses.second.z = anchor.z + direction.z;
    if (geometry.poses.second.y < 25.0f) {
        geometry.poses.second.y = 25.0f;
    }
    angle = func_001ec2b0(&geometry.poses.firstRotation, &geometry.poses.secondRotation);
    if (forceActorSide == 1 || !(angle <= fGpffff80e4)) {
        if (allowCut == 1) {
            geometry.poses.firstRotation = geometry.poses.secondRotation;
            RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &geometry.poses.secondRotation);
            scale = 200.0f + distance;
            direction.x *= scale;
            direction.y *= scale;
            direction.z *= scale;
            geometry.poses.first.x = anchor.x + direction.x;
            geometry.poses.first.y = anchor.y + direction.y;
            geometry.poses.first.z = anchor.z + direction.z;
            if (geometry.poses.first.y < 25.0f) {
                geometry.poses.first.y = 25.0f;
            }
            func_004b3110(5);
        }
    }
    func_001bac20((u16 *)camera, (f32 *)&geometry.poses.first, (f32 *)&geometry.poses.second, 1);
    func_001bbef0(camera, 1.5f);
}
#pragma opt_scalarize on
/* measured: opt_propagation off preserves func_002299b0's initial GP-load/store order (nd 0). */
#pragma opt_propagation off
// FUN_002299B0
void func_002299b0(u8 *arg0)
{
    u8 *saved_arg0;
    u32 payload[8];
    s32 temp_17;
    u8 *var_16;
    u8 *temp_5;
    temp_5 = DAT_0076449c;
    *(s16 *)(temp_5 + 0xC34) = 0;
    saved_arg0 = arg0;
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(s32 *)(temp_3 + 0xC) |= 0x400000;
    }
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(u16 *)(temp_3 + 0x18) =
            (u16)(*(u16 *)(temp_3 + 0x18) | 0x23);
    }
    func_001a03b0((s64 *)saved_arg0);
    temp_17 = func_001d3d50(0);
    func_001d3ea0((int)temp_17, (u32)func_0022ced0(0xC));
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001b1510();
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 0x18) =
                (u16)(*(u16 *)(temp_2 + 0x18) | 8);
        }
    }
    {
        u8 *temp_4;
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) |= 0x80000;
    }
    {
        u8 *temp_2;
        temp_2 = func_001bc920(saved_arg0, 0x2D);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 0);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_0019bbe0((BtlUnit *)(*(u8 **)(saved_arg0 + 0x30)),
                              0xFFFFFF, 0x50, 0, 4, 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 1);
    }
    var_16 = saved_arg0;
    {
        s32 temp_2;
        u8 *temp_2_5;

        temp_2 = (s32)func_0019ef90(1, 0x106);
        if (temp_2 == 0) {
            goto after_ef90;
        }
        var_16 = (u8 *)func_001b0c80(temp_2);
        func_001f0a10((u8 *)payload);
        payload[2] = 0x100000;
        temp_2_5 = (u8 *)func_001f36e0((s32)(u32)var_16, (s32)(u32)var_16,
                                      (void *)payload, 1, 1);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2_5, 1);
        temp_2_5 = func_00199ee0(*(u8 **)(var_16 + 0x30),
                                 9, 0, 0, 1.0f);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2_5, 0);
after_ef90:
        ;
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001f81f0(2, (const char *)D_006354B0);
        *(u16 *)(temp_2 + 0x48) = 2;
        func_00194590(temp_2, 1);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001d6240((u32)temp_17,
                                    *(u32 *)(saved_arg0 + 0x30),
                                    *(u32 *)(var_16 + 0x30), 0, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 2);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001d6240((u32)temp_17,
                                    *(u32 *)(saved_arg0 + 0x30),
                                    *(u32 *)(var_16 + 0x30), 1, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        func_00194590(temp_2, 2);
    }
    func_001d3e00(temp_17);
}
/* measured: close opt_propagation after func_002299b0 (nd 0). */
#pragma opt_propagation on
// FUN_00229C40
s32 func_00229c40(u8 *arg0)
{
    u8 *temp_2_2;
    u8 *temp_2;
    u8 *temp_4_3;

    if (func_00193bf0(*(u64 *)arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        temp_2 = (u8 *)func_0019ef90(1, 0x106);
        if (temp_2 != NULL) {
            temp_2_2 = (u8 *)func_001b0c80((s32)temp_2);
            *(u16 *)(temp_2_2 + 0x1A) =
                (u16)(*(u16 *)(temp_2_2 + 0x1A) | 8);
            *(s32 *)(*(u8 **)(temp_2_2 + 0x30) + 0x9C) |= 8;
            *(u16 *)(*(u8 **)(*(u8 **)(temp_2_2 + 0x30) + 0xA64)) &= 0xFFDF;
        }
        *(u16 *)(arg0 + 0x1A) =
            (u16)(*(u16 *)(arg0 + 0x1A) & 0xFFF7);
        *(u16 *)(arg0 + 0x1A) =
            (u16)(*(u16 *)(arg0 + 0x1A) | 0x400);
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= ~8;
        func_0019d0c0(*(u8 **)(arg0 + 0x30));
        func_002339d0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
        func_00198dd0(*(u8 **)(arg0 + 0x30), 0);
        func_00198920(*(u8 **)(arg0 + 0x30), 0, 0, 1.0f, 1);
        *(u8 **)(DAT_0076449c + 0xB98) = &D_0062D920[0];
        temp_4_3 = DAT_0076449c;
        *(s32 *)(temp_4_3 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}
// FUN_00229DA0
/* 2312/2320 bytes; 75 resolved code relocations and nine switch entries exact. */
void func_00229da0(u8 *action)
{
    s32 formation;
    u8 *packet;
    u8 *initialAnimation;
    u8 *formationPacket;
    u8 *sequencePacket;
    u8 *statusAnimation;
    u8 *returnPacket;
    u8 *finishPacket;
    u8 *returnTarget;
    u8 *unit;
    u8 *returnUnit;
    u8 *node;
    u8 *returnNode;
    u32 targetIndex;
    u32 returnIndex;
    u16 slot;
    u32 rosterIndex;
    u32 delay;
    u32 positionOffset;
    s16 animationFrames;
    union {
        u32 words[8];
        u16 halves[16];
        u8 bytes[0x20];
    } targetParams, statusParams;

    formation = func_001d3d50(0);
    func_001d3ea0(formation, (u32)func_0022ced0(0xC));
    *(u32 *)(iGpffffb3ac + 0xC) |= 0x80000;

    packet = (u8 *)func_00202010(*(u32 *)(action + 0x30),
                                *(u16 *)(action + 0x6E));
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 3);

    packet = func_001bc920(action, 0x1A);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    initialAnimation = func_00199ee0(*(u8 **)(action + 0x30), 0xF, 0, 2, 1.0f);
    *(u64 *)(initialAnimation + 0x60) = *(u64 *)action;
    *(u16 *)(initialAnimation + 0x4A) = 0xC8;
    func_00194590(initialAnimation, 0);

    if (*(u16 *)(action + 0x6A) == 1) {
        packet = (u8 *)btlUnitCreateRotateTowardUnitPacket(
            *(BtlUnit **)(action + 0x30),
            *(BtlUnit **)(*(u8 **)(action + 0x38) + 0x30), 2);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 0);
    } else {
        packet = (u8 *)btlUnitCreateRotatePacket(
            *(BtlUnit **)(action + 0x30), (const RwV3d *)D_006354C0, 2);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);
    }

    unit = *(u8 **)(action + 0x30);
    formationPacket = (u8 *)func_001d6240((u32)formation, (u32)unit,
                                         (u32)unit, 0, 0x200);
    *(u64 *)(formationPacket + 0x60) = *(u64 *)action;
    func_00194590(formationPacket, 2);

    packet = (u8 *)func_001f7c20(0xC, 5, 0xE);
    *(u16 *)(packet + 0x48) = 0x5A;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    func_001f0a10(targetParams.bytes);
    targetParams.words[2] = 0x100;
    func_001f0a10(statusParams.bytes);
    statusParams.words[3] = 0x100001;
    delay = 0;
    targetIndex = 0;
    while ((u16)targetIndex < *(u16 *)(action + 0x6A)) {
        u8 *target = *(u8 **)(action + (u32)(u16)targetIndex * 4 + 0x38);
        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0)
            goto next_target;
        if (*(u16 *)(unit + 0xA4) == 1)
            goto next_target;
        if ((*(u16 *)(target + 0x1A) & 1) == 0)
            goto next_target;
        if (func_002428f0(*(u8 **)(unit + 0xA64), 0) != 0)
            goto next_target;

        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0) {
            slot = 0;
        } else {
            rosterIndex = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node)
                    break;
                rosterIndex = (u16)(rosterIndex + 1);
                node = *(u8 **)(node + 0xA68);
            }
            slot = (u16)rosterIndex;
        }

        formationPacket = (u8 *)func_001d6240((u32)formation,
            *(u32 *)(action + 0x30), (u32)unit, 1, 0x200);
        *(u16 *)(formationPacket + 0x48) = (u16)delay;
        *(u64 *)(formationPacket + 0x60) = *(u64 *)action;
        func_00194590(formationPacket, 2);

        packet = (u8 *)func_001f7c20(0xC, 5, 0xE);
        *(u16 *)(packet + 0x48) = 0x6C;
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);

        positionOffset = (u32)slot * 12;
        unit = *(u8 **)(target + 0x30);
        func_001ec6d0((s16 *)(unit + 0x94), (s16 *)(unit + 0x96),
                      (f32 *)(D_00635500 + positionOffset));
        *(u16 *)(target + 0x1A) &= 0xFFF7;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x20;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 8;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x10;

        if (func_00232710(*(u8 **)(*(u8 **)(target + 0x30) + 0xA64),
                          0x100000) != 0) {
            statusAnimation = func_00199ee0(*(u8 **)(target + 0x30),
                                            0xB, 0, 0, 1.0f);
            statusAnimation[0] = 0xB;
            *(u64 *)(statusAnimation + 8) = *(u64 *)(formationPacket + 0x58);
            *(u64 *)(statusAnimation + 0x60) = *(u64 *)action;
            func_00194590(statusAnimation, 0);

            packet = (u8 *)func_001f36e0((s32)(u32)target, (s32)(u32)target,
                                         statusParams.bytes, 1, 1);
            packet[0] = 4;
            *(u64 *)(packet + 8) = *(u64 *)(statusAnimation + 0x58);
            *(u64 *)(packet + 0x60) = *(u64 *)action;
            func_00194590(packet, 1);
            animationFrames = func_00199500(*(u8 **)(target + 0x30), 0xB, 1.0f);
        } else {
            animationFrames = 0;
        }

        sequencePacket = (u8 *)btlUnitCreateMovePacket(
            *(BtlUnit **)(target + 0x30),
            (const RwV3d *)(D_006354D0 + positionOffset), 0.5f, 8);
        sequencePacket[0] = 0xB;
        *(u64 *)(sequencePacket + 8) = *(u64 *)(formationPacket + 0x58);
        *(s16 *)(sequencePacket + 0x48) = animationFrames;
        *(u64 *)(sequencePacket + 0x60) = *(u64 *)action;
        func_00194590(sequencePacket, 1);

        packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(target + 0x30),
                                                 (const RwV3d *)D_006354C0, 0);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(sequencePacket + 0x58);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);

        if (func_00243e30(*(u16 **)(*(u8 **)(target + 0x30) + 0xA64)) != 0)
            targetParams.halves[15] |= 0x80;
        else
            targetParams.halves[15] &= 0xFF7F;
        packet = (u8 *)func_001f36e0((s32)(u32)target, (s32)(u32)target,
                                     targetParams.bytes, 1, 1);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(sequencePacket + 0x58);
        *(u16 *)(packet + 0x48) = 8;
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);

        switch (*(u16 *)(*(u8 **)(target + 0x30) + 0xA4)) {
        case 2:
            func_00106390(0x15CF, 1);
            break;
        case 3:
            func_00106390(0x15D0, 1);
            break;
        case 4:
            func_00106390(0x15D1, 1);
            break;
        case 6:
            func_00106390(0x15D2, 1);
            break;
        case 8:
            func_00106390(0x15D3, 1);
            break;
        case 7:
            func_00106390(0x15D4, 1);
            break;
        }
        delay += (u16)func_001ef4a0(0x17B);
next_target:
        targetIndex = (u16)(targetIndex + 1);
    }

    *(u16 *)(iGpffffb3ac + 0x18) = 0;
    *(u32 *)(iGpffffb3ac + 0xC) &= 0xFFBFFFFF;
    finishPacket = func_001bc920(action, 0x2C);
    finishPacket[0] = 4;
    *(u64 *)(finishPacket + 8) = *(u64 *)(initialAnimation + 0x58);
    if (formationPacket != NULL) {
        finishPacket[0x10] = 4;
        *(u64 *)(finishPacket + 0x18) = *(u64 *)(formationPacket + 0x58);
    }
    *(u64 *)(finishPacket + 0x60) = *(u64 *)action;
    func_00194590(finishPacket, 0);

    packet = (u8 *)func_001d3700(2, 0xFFF);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(finishPacket + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    packet = func_00199ee0(*(u8 **)(action + 0x30), 0xB, 0, 0, 1.0f);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(finishPacket + 0x58);
    *(u16 *)(packet + 0x4A) = 0x60;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    returnIndex = 0;
    while ((u16)returnIndex < *(u16 *)(action + 0x6A)) {
        returnTarget = *(u8 **)(action + (u32)(u16)returnIndex * 4 + 0x38);
        returnUnit = *(u8 **)(returnTarget + 0x30);
        if (returnUnit[0xA2] != 0)
            goto next_return_target;
        if (*(u16 *)(returnUnit + 0xA4) == 1)
            goto next_return_target;
        if ((*(u16 *)(returnTarget + 0x1A) & 1) == 0)
            goto next_return_target;
        if (func_002428f0(*(u8 **)(returnUnit + 0xA64), 0) != 0)
            goto next_return_target;

        returnUnit = *(u8 **)(returnTarget + 0x30);
        if (returnUnit[0xA2] == 0) {
            returnNode = *(u8 **)(iGpffffb3ac + 0x17C);
            while (returnNode != NULL) {
                if (returnUnit == returnNode)
                    break;
                returnNode = *(u8 **)(returnNode + 0xA68);
            }
        }

        returnPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)returnUnit,
                                                       NULL, fGpffff809c, 0x18);
        returnPacket[0] = 4;
        *(u64 *)(returnPacket + 8) = *(u64 *)(finishPacket + 0x58);
        *(u64 *)(returnPacket + 0x60) = *(u64 *)action;
        func_00194590(returnPacket, 1);

        packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(returnTarget + 0x30),
                                                 (const RwV3d *)D_006354C0, 0);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(returnPacket + 0x58);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        func_00194590(packet, 1);
next_return_target:
        returnIndex = (u16)(returnIndex + 1);
    }
    func_001d3e00((u32)formation);
}
// FUN_0022A6B0
s32 func_0022a6b0(s64 *arg0) {
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        func_00106390(0x15FF, 1);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

// FUN_0022A730
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022a730);
// FUN_0022ABD0
s32 func_0022abd0(s64 *arg0) {
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        func_00106390(0x15FF, 0);
        func_00106390(0x15CF, 0);
        func_00106390(0x15D0, 0);
        func_00106390(0x15D1, 0);
        func_00106390(0x15D2, 0);
        func_00106390(0x15D3, 0);
        func_00106390(0x15D4, 0);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}
// FUN_0022ACB0
void func_0022acb0(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_2_2;

    *(s32 *)(DAT_0076449c + 0xC) |= 0x80000;
    temp_2 = func_001bc920(arg0, 0x2C);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    temp_2_2 = func_00202400(*(s32 *)(arg0 + 0x30), 0xAF);
    *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_2, 3);
}
// FUN_0022AD40
s32 func_0022ad40(s64 *arg0) {
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        func_00106390(0x1435, 0);
        func_00106390(0x15C5, 0);
        func_00106390(0x15C6, 0);
        func_00106390(0x15C7, 0);
        func_00106390(0x15C8, 0);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}
// FUN_0022AE00
void func_0022ae00(u8 *arg0)
{
    struct {
        u8 data[0x10];
        u8 pad[0x10];
    } sp;
    s32 sp38;
    s32 temp_16;

    func_00106390(0x15C0, 0);
    *(s8 *)(DAT_0076449c + 0xC10) = -1;
    *(s8 *)(DAT_0076449c + 0xC13) = -1;
    *(s8 *)(DAT_0076449c + 0xC28) = -1;
    *(s8 *)(DAT_0076449c + 0xC22) = -1;
    *(s8 *)(DAT_0076449c + 0xC1A) = -1;
    *(s8 *)(DAT_0076449c + 0xC12) = -1;
    *(s8 *)(DAT_0076449c + 0xC18) = -1;
    {
        u8 *temp_3;
        temp_3 = *(u8 **)(arg0 + 0x30);
        *(u16 *)(temp_3 + 0x9D8) =
            (u16)(*(u16 *)(temp_3 + 0x9D8) & 0xFFDF);
    }
    {
        u8 *temp_4;
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) |= 0x400000;
    }
    {
        u8 *temp_3_2;
        temp_3_2 = DAT_0076449c;
        *(u16 *)(temp_3_2 + 0x18) =
            (u16)(*(u16 *)(temp_3_2 + 0x18) | 0x23);
    }
    func_001a03b0((s64 *)arg0);
    temp_16 = func_001d3d50(0);
    func_001d3ea0((int)temp_16, (u32)func_0022ced0(0xC));
    {
        u8 *temp_2;
        temp_2 = (u8 *)func_001b1510();
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 0x18) =
                (u16)(*(u16 *)(temp_2 + 0x18) | 8);
        }
    }
    {
        u8 *temp_4_2;
        temp_4_2 = DAT_0076449c;
        *(s32 *)(temp_4_2 + 0xC) |= 0x80000;
    }
    {
        u8 *temp_2_2;
        temp_2_2 = func_00199ee0(*(u8 **)(arg0 + 0x30),
                                 0xC, 0, 0, 1.0f);
        *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_2, 0);
    }
    {
        u8 *temp_2_3;
        temp_2_3 = (u8 *)func_0019a980((BtlUnit *)(*(u8 **)(arg0 + 0x30)));
        *(s16 *)(temp_2_3 + 0x48) = 1;
        *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_3, 0);
    }
    func_001f0a10((u8 *)sp.data);
    *(s32 *)(sp.data + 8) = 0x100000;
    {
        u8 *temp_2_4;
        temp_2_4 = (u8 *)func_001f36e0((s32)(u32)arg0, (s32)(u32)arg0,
                                      (void *)sp.data, 1, 1);
        *(s64 *)(temp_2_4 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_4, 1);
    }
    {
        u8 *temp_5;
        u8 *temp_2_5;
        temp_5 = *(u8 **)(arg0 + 0x30);
        temp_2_5 = (u8 *)func_001d6240((u32)temp_16, (u32)temp_5, (u32)temp_5, 0, 0x200);
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_5, 2);
    }
    {
        u8 *temp_5_2;
        u8 *temp_2_6;
        temp_5_2 = *(u8 **)(arg0 + 0x30);
        temp_2_6 = (u8 *)func_001d6240((u32)temp_16, (u32)temp_5_2, (u32)temp_5_2, 1, 0x200);
        *(s64 *)(temp_2_6 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_6, 2);
    }
    func_001d3e00(temp_16);
}
// FUN_0022B040
s32 func_0022b040(s64 *arg0)
{
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

 
// FUN_0022B0B0
s32 func_0022b0b0(void)
{
    func_001f7570(0x2D);
    return 1;
}
// FUN_0022B0E0
s32 func_0022b0e0(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC) & 0x40) {
        func_0045a3e0(6, 1);
    }
    return 1;
}
// FUN_0022B120
/* 1860/1872 bytes; all 67 resolved code relocations exact. */
void func_0022b120(u8 *action)
{
    u8 *actor;
    s32 openingFormation;
    s32 closingFormation;
    u8 *wait1;
    u8 *wait0;
    u8 *anchor;
    u8 *cleanup;
    u8 *packet;
    RwV3d rotation;

    actor = *(u8 **)(action + 0x30);
    *(u32 *)(DAT_0076449c + 0xC) |= 0x400000;
    *(u16 *)(DAT_0076449c + 0x18) |= 0x23;
    func_001a03b0((s64 *)action);
    openingFormation = func_001d3d50(0);
    closingFormation = func_001d3d50(0);
    func_001d3ea0(openingFormation, (u32)func_0022ced0(0xC));
    func_001d3ea0(closingFormation, (u32)func_0022ced0(0xD));
    *(u32 *)(DAT_0076449c + 0xC) |= 0x80000;

    anchor = func_001ebb00((s32)action, 3, D_00635560);
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    func_00194590(anchor, 1);

    packet = func_00194c90((void *)func_0022b0b0, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = func_00199ee0(actor, 0x13, 0, 2, 1.0f);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    packet = (u8 *)func_002306d0();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 0x33;
    func_00194590(packet, 1);

    wait1 = (u8 *)func_001d6240((u32)openingFormation, (u32)actor, (u32)actor, 0, 0x200);
    wait1[0] = 4;
    *(u64 *)(wait1 + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(wait1 + 0x60) = *(u64 *)action;
    func_00194590(wait1, 2);

    wait0 = (u8 *)func_001d6240((u32)openingFormation, (u32)actor, (u32)actor, 1, 0x200);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    func_00194590(wait0, 2);

    packet = (u8 *)func_001d7ab0(iGpffffa4d8, 0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 0x19A;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = (f32)3000;
    packet = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)actor, &rotation, 2);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    anchor = (u8 *)func_0019b6a0((BtlUnit *)actor);
    anchor[0] = 4;
    *(u64 *)(anchor + 8) = *(u64 *)(wait1 + 0x58);
    anchor[0x10] = 4;
    *(u64 *)(anchor + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(anchor + 0x48) = 1;
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    func_00194590(anchor, 1);

    packet = (u8 *)func_00230750();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    cleanup = (u8 *)func_00230650();
    cleanup[0] = 4;
    *(u64 *)(cleanup + 8) = *(u64 *)(wait1 + 0x58);
    cleanup[0x10] = 4;
    *(u64 *)(cleanup + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(cleanup + 0x48) = 3;
    *(u64 *)(cleanup + 0x60) = *(u64 *)action;
    func_00194590(cleanup, 1);

    wait0 = func_0019b550(actor, 0x10E, 0x216);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait0 + 0x48) = 2;
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    func_00194590(wait0, 1);

    anchor = func_001ebb00((s32)action, 3, D_00635580);
    anchor[0] = 4;
    *(u64 *)(anchor + 8) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(anchor + 0x48) = 2;
    *(u16 *)(anchor + 0x4A) = 0xC;
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    func_00194590(anchor, 1);

    packet = func_00194c90((void *)func_0022b0e0, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_002305c0(0x10E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(cleanup + 0x58);
    *(u16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_0019bbe0((BtlUnit *)actor, 0xFFFFFFFFU, 1, 0, 3, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001d7b60(0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 4;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    wait0 = (u8 *)func_001d6240((u32)closingFormation, (u32)actor, (u32)actor, 0, 0x200);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait0 + 0x48) = 2;
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    func_00194590(wait0, 2);

    wait1 = (u8 *)func_001d6240((u32)closingFormation, (u32)actor, (u32)actor, 1, 0x200);
    wait1[0] = 4;
    *(u64 *)(wait1 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait1 + 0x48) = 2;
    *(u64 *)(wait1 + 0x60) = *(u64 *)action;
    func_00194590(wait1, 2);

    packet = (u8 *)func_001b7e20(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001b9360(0x10, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001b99a0(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001ba090(8);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    func_001d3e00((u32)closingFormation);
    func_001d3e00((u32)openingFormation);
}
/* measured: opt_loop_invariants on probe for func_0022b870. */
#pragma opt_loop_invariants on
// FUN_0022B870
s32 func_0022b870(u8 *arg0)
{
    extern void func_0019ea60(u8 *arg0, s32 arg1);
    extern u32 func_00231af0(DatUnit *unit, u8 genus, u16 id);
    extern s32 func_001b0d70(u8 *arg0);
    extern s32 func_001b1540(void);
    extern void func_0022fdc0(u8 *arg0);
    extern u8 *func_001f7650(u8 *arg0);
    extern void func_00198dd0(u8 *arg0, s32 arg1);
    extern u8 D_00630C50[];
    u32 index;
    s32 value;
    s32 fill;
    u8 *temp;

    if (func_00193bf0(*(u64 *)arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        *(s32 *)(DAT_0076449c + 0xC) &= 0xFFF7FFFF;
        func_0019ea60(*(u8 **)(arg0 + 0x30), 0x10E);
        func_00231af0((DatUnit *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)), 1, 0x10E);
        func_00106390(0x15FF, 1);
        *(u8 **)(DAT_0076449c + 0xB98) = &D_00630C50[0];
        *(s32 *)(DAT_0076449c + 0xC40) = 1;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) |= 0x2000;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= 0xFFFF7FFF;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= ~0x20;
        temp = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp |= 0x20;
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        func_001b0d70(arg0);
        func_0022fdc0((u8 *)func_001b1540());
        index = 0;
        fill = -1;
        goto loop_test;
loop_body:
        *(s8 *)(DAT_0076449c + index + 0xC10) = fill;
        index++;
loop_test:
        if (index < 0x1E) {
            goto loop_body;
        }
        value = (s32)func_001f7650(*(u8 **)(arg0 + 0x30));
        *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA00) + 0x2DC) = value;
        func_00198dd0(*(u8 **)(arg0 + 0x30), 6);
        func_00106390(0x15C0, 0);
        *(s32 *)(DAT_0076449c + 0xBB4) = 0;
        *(s32 *)(DAT_0076449c + 0xBC8) = 0;
        *(u16 *)(DAT_0076449c + 0x290) |= 0x10;
        return 0;
    }
    return 1;
}
/* measured: closes opt_loop_invariants around func_0022b870. */
#pragma opt_loop_invariants off
/* measured: optimization_level 1 preserves func_0022ba40's loop branch. */
#pragma optimization_level 1
// FUN_0022BA40
void func_0022ba40(u16 arg1)
{
    s32 value;
    s32 id;
    u8 *p;

    p = *(u8 **)(DAT_0076449c + 0x180);
    id = 0x10E;
    goto check;
body:
    value = *(u16 *)(p + 0xA4);
    if (value == id) {
        goto found;
    }
    p = *(u8 **)(p + 0xA6C);
check:
    if (p != NULL) {
        goto body;
    }
found:
    if (p != NULL) {
        p = (u8 *)func_001b0c80((s32)p);
        if (p != NULL) {
            func_001f2eb0(p, 0);
            func_001f7530();
        }
    }
}
/* measured: closes optimization_level 1 around func_0022ba40. */
#pragma optimization_level 2

// FUN_0022BAC0
s32 func_0022bac0(void)
{
    return 0;
}

// FUN_0022BAD0
s32 func_0022bad0(u8 *arg0, u16 arg1)
{
    u8 *target;
    u8 *handle;
    u8 *state;
    u8 *unit;
    u8 *slot;
    u8 *temp;

    slot = &((u8 *)(((u32)arg1 & 0xFFFF) * 4))
        [(u32)iGpffffb3ac];
    if (*(s32 *)(slot + 0xBA8) != *(s32 *)(arg0 + 8)) {
        goto changed;
    }
    if (*(s32 *)(slot + 0xBBC) != *(s32 *)(arg0 + 0x20)) {
        goto changed;
    }
    return 0;
changed:
    if (arg0 == NULL) {
        target = *(u8 **)(iGpffffb3ac + 0x170);
    } else {
        target = arg0;
    }
    temp = func_0022ced0(0);
    handle = func_0029da90(
        *(s32 *)(*(u8 **)(iGpffffb3ac + 0xDC8) + 0x20) - 1,
        temp, arg1);
    func_0029dfe0(handle, target);
    state = (u8 *)func_00452560(handle);
    if (*(s32 *)(state + 0x130) >= 0) {
        unit = *(u8 **)(target + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            func_00278450(
                *(u8 **)(state + 0x130), 0,
                func_0010d740(*(s16 *)(unit + 0xA4)));
        } else {
            func_00278450(
                *(u8 **)(state + 0x130), 0,
                iGpffffb444 + (u16)(*(u16 *)(unit + 0xA4)) * 0x15);
        }
    }
    func_00452570(*(u8 **)(iGpffffb3ac + 0xDC8), handle);
    *(u8 **)(iGpffffb3ac + 0xBA0) = handle;
    *(u16 *)(iGpffffb3ac + 0xBA4) = arg1;
    *(s32 *)(&((u8 *)(((u32)arg1 & 0xFFFF) * 4))
              [(u32)iGpffffb3ac] + 0xBA8) =
        *(s32 *)(arg0 + 8);
    *(s32 *)(&((u8 *)(((u32)arg1 & 0xFFFF) * 4))
              [(u32)iGpffffb3ac] + 0xBBC) =
        *(s32 *)(arg0 + 0x20);
    return 1;
}
// FUN_0022BC80
s32 func_0022bc80(s32 arg0) {
    u8 *b = DAT_0076449c;
    u8 *o = *(u8 **)(b + 0xBA0);

    if (o == NULL) {
        return 0;
    }
    if (*(u16 *)(b + 0xBA4) != (arg0 & 0xFFFF)) {
        return 0;
    }
    if (func_00452490(o) == 0) {
        *(s32 *)(DAT_0076449c + 0xBA0) = 0;
        return 0;
    }
    return 1;
}

// FUN_0022BD00
s32 func_0022bd00(void)
{
    return *(s32 *)(DAT_0076449c + 0xBA0) != 0;
}



// FUN_0022BD20
s32 func_0022bd20(void)
{
    return (*(s32 *)(iGpffffb414 +
                     *(u16 *)(*(u8 **)(DAT_0076449c + 0xC68) + 8) * 0x18) &
            0x20) != 0;
}
/* measured: 1744/1744 bytes, all 152 code relocations and 22 switch-table
   targets exact. Loop-invariant motion keeps the signed empty-slot sentinel
   in the clearing-loop preheader. The pragma does not affect other functions. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0022BD60
void func_0022bd60(void)
{
    u32 i;

    *(u32 *)(DAT_0076449c + 0xC) |= 0x200000;
    *(u32 *)(DAT_0076449c + 0x10) |= 1;
    switch (func_001ef9a0()) {
    case 0x200:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_00629750;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x201:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_00629EA0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x202:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062A5F0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x203:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x400;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062B490;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x204:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062CA80;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x205:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062D1D0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x206:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062D920;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        *(u16 *)(DAT_0076449c + 0xC34) = 0;
        break;
    case 0x207:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062E7C0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x208:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062EF10;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x209:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x80;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x800;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062F660;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x20A:
        *(u32 *)(DAT_0076449c + 0xC) &= ~0x400U;
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x100;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062FDB0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x20B:
    case 0x215:
        *(u32 *)(DAT_0076449c + 0xC) &= ~0x400U;
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x2000;
        if (func_001ef9a0() == 0x20B) {
            *(u8 **)(DAT_0076449c + 0xB98) = D_00630500;
        } else {
            *(u8 **)(DAT_0076449c + 0xB98) = D_00630C50;
        }
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x20C:
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        break;
    case 0x20D:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x80;
        *(u8 **)(DAT_0076449c + 0xB98) = D_006313A0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x214:
        *(u32 *)(DAT_0076449c + 0xC) &= ~0x400U;
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x100;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u8 **)(DAT_0076449c + 0xB98) = D_00631AF0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        func_00106390(0x1438, 1);
        break;
    }
    for (i = 0; i < 30; i++) {
        *(s8 *)(DAT_0076449c + i + 0xC10) = -1;
    }
}
#pragma pop
/* measured: 1876B / 1888B window; 123 code relocations and all 22 table
   relocations resolve exactly. The omitted 12B are zero alignment.
   Keep each lookup/allocation/set/store sequence and its global reload. */
// FUN_0022C430
void func_0022c430(void)
{
    u8 *data;
    s32 formation;

    switch (func_001ef9a0()) {
    case 0x200:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x201:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        break;
    case 0x202:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        break;
    case 0x203:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x204:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x205:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x206:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        data = func_0022ced0(9);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF4) = formation;
        break;
    case 0x207:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        break;
    case 0x208:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x209:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(5);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE4) = formation;
        data = func_0022ced0(6);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE8) = formation;
        data = func_0022ced0(7);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBEC) = formation;
        break;
    case 0x20A:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x20B:
    case 0x215:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x20D:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(5);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE4) = formation;
        data = func_0022ced0(6);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE8) = formation;
        data = func_0022ced0(7);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBEC) = formation;
        break;
    case 0x214:
        data = func_0022ced0(4);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = func_0022ced0(8);
        formation = func_001d3d50(2);
        func_001d4490(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    }
}
static inline u8 *cb90AddBaseIndex(u32 base, u32 index)
{
    return (u8 *)(base + index);
}
// FUN_0022CB90
s32 func_0022cb90(u8 *arg0, s32 arg1)
{
    s32 temp_6;
    s8 temp_2;
    u16 temp_3_2;
    u8 *temp_7;
    u16 temp_3_3;

    if (*(u8 *)(arg0 + 0xA2) != 1) {
        return -1;
    }
    temp_7 = DAT_0076449c;
    temp_6 = *(s32 *)(temp_7 + 0xC30);
    if (temp_6 == 0) {
        return -1;
    }
    temp_3_2 = *(u16 *)(arg0 + 0xA4);
    switch (temp_3_2) {
    case 0x10D:
    case 0x110:
    case 0x111:
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    case 0x10F:
        temp_3_3 = (u16)arg1;
        if (((temp_3_3 == 0) || (temp_3_3 == 0x12)) &&
            (*(s16 *)(temp_7 + 0xC34) != 3)) {
            return 0xB;
        }
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    default:
        temp_2 = *(s8 *)cb90AddBaseIndex((u32)temp_7 + 0xC10,
                                         (u32)(arg1 & 0xFFFF));
        if (temp_2 >= 0) {
            return temp_2;
        }
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    }
}
#pragma opt_propagation off
// FUN_0022CC90
void func_0022cc90(void)
{
    extern void func_00454bd0(s32 arg0);
    extern void func_001d3e00(s32 arg0, u8 *arg1);
    s16 i;
    s32 value;
    s32 temp_index;
    s32 index;
    s16 index16;
    u8 *slot;
    u8 *base;

    switch (func_001ef9a0()) {
    case 0x214:
        func_0010b7c0();
        func_0010b010(1);
        func_0010b300(1);
        func_00106d40(1, 0, 1);
        break;
    }
    i = 0;
    while (i < 8) {
        base = DAT_0076449c;
        slot = base + i * 4;
        value = *(s32 *)(slot + 0xBE0);
        if (value != 0) {
            index16 = i;
            temp_index = (s32)(s64)(s16)index16;
            index = temp_index * 4;
            func_001d3e00(value, base);
            base = DAT_0076449c;
            *(s32 *)(base + index + 0xBE0) = 0;
        }
        i++;
    }
    value = *(s32 *)(DAT_0076449c + 0xB94);
    if (value != 0) {
        func_00454bd0(value);
        *(s32 *)(DAT_0076449c + 0xB94) = 0;
    }
    value = *(s32 *)(DAT_0076449c + 0xB90);
    if (value != 0) {
        func_00454bd0(value);
        *(s32 *)(DAT_0076449c + 0xB90) = 0;
    }
}
#pragma opt_propagation on
// FUN_0022CDB0
u8 *func_0022cdb0(s32 arg0)
{
    s32 temp_2;
    u8 *var_2;

    if ((*(s32 *)(DAT_0076449c + 0x10) & 0x10) == 0) {
        return NULL;
    }
    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x20B:
        if (*(s32 *)(DAT_0076449c + 0xC40) == 0) {
            var_2 = (u8 *)((s32)&D_00634CB0 +
                           ((arg0 & 0xFFFF) * 0x14));
        } else {
            var_2 = (u8 *)((s32)&D_006350B0 +
                           ((arg0 & 0xFFFF) * 0x14));
        }
        break;
    case 0x215:
        var_2 = (u8 *)((s32)&D_006350B0 +
                       ((arg0 & 0xFFFF) * 0x14));
        break;
    default:
        var_2 = (u8 *)((s32)&D_006348B0 +
                       ((arg0 & 0xFFFF) * 0x14));
        break;
    }
    if ((*(s32 *)(var_2 + 0) == 0) &&
        (*(s32 *)(var_2 + 4) == 0)) {
        var_2 = NULL;
    }
    return var_2;
}
// FUN_0022CED0
u8 *func_0022ced0(s32 arg0)
{
    return func_00455ea0(*(u8 **)(DAT_0076449c + 0xB90), arg0 & 0xFFFF, 0);
}

// FUN_0022CF00
f32 func_0022cf00(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 temp_3;
    u16 temp_2;

    if (!(*(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return -1.0f;
    }
    if (*(u8 *)(arg1 + 0xA2) != 1) {
        return -1.0f;
    }
    temp_3 = arg2 & 0xFFFF;
    if ((temp_3 != 4) && (temp_3 != 0xC) &&
        (temp_3 != 5) && (temp_3 != 7)) {
        return -1.0f;
    }
    temp_2 = *(u16 *)(arg1 + 0xA4);
    switch (temp_2) {
    case 0x100:
        return 100.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x101:
        return 25.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x102:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x103:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x110:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x111:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x104:
        return 50.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x105:
        return 200.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x106:
        return 250.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x10F:
        return 250.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x107:
        return 200.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x108:
        return 300.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x10A:
        return 500.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x113:
        return 75.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x109:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x112:
    default:
        goto fail;
    }
fail:
    return -1.0f;
}
// FUN_0022D200
/* Measured: 824/832 bytes, one resolved relocation, zero differences;
 * the remaining eight retail bytes are zero alignment. */
s32 func_0022d200(u8 *action)
{
    u8 *global;
    u8 *unit;
    u16 unitId;
    u16 skill;

    global = iGpffffb3ac;
    if ((*(u32 *)(global + 0xC) & 0x200000) == 0) {
        return 0;
    }
    if ((*(u16 *)(action + 0x1A) & 1) == 0) {
        return 0;
    }
    unit = *(u8 **)(action + 0x30);
    if (*(u8 *)(unit + 0xA2) != 1) {
        return 0;
    }
    unitId = *(u16 *)(unit + 0xA4);
    switch (unitId) {
    case 0x100:
        skill = *(u16 *)(action + 0x6E);
        return skill == 0x160 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x103:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x166 || skill == 0x167 || skill == 0x168) {
            return *(s32 *)(global + 0xBF0);
        }
        return *(s32 *)(global + 0xBE0);
    case 0x104:
        skill = *(u16 *)(action + 0x6E);
        return skill == 0x169 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x106:
    case 0x10F:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x16D || skill == 0x173 || skill == 0x174 ||
            skill == 0x175 || skill == 0x176 || skill == 0x177) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x172 ? *(s32 *)(global + 0xBF4) : *(s32 *)(global + 0xBE0);
    case 0x105:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x16B) {
            return *(s32 *)(global + 0xBF0);
        }
        if (skill == 0x16A) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x16C ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x108:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x17A) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x17C ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x10A:
    case 0x113:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x17F || skill == 0x186) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x180 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x10B:
    case 0x10E:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x181 || skill == 0x18B || skill == 0x182 || skill == 0x185) {
            return *(s32 *)(global + 0xBF0);
        }
        return *(s32 *)(global + 0xBE0);
    default:
        return *(s32 *)(global + 0xBE0);
    }
}
// FUN_0022D540
s32 func_0022d540(u8 *arg0, u8 *arg1) {
    u16 temp_3;
    u8 *temp_4;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 0;
    }
    if (!(*(u16 *)(arg0 + 0x1A) & 1)) {
        return 0;
    }
    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) != 1) {
        return 0;
    }
    temp_3 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_3) {
    case 0x112:
    case 0x109:
        *(s32 *)(arg1 + 0) = *(s32 *)(temp_6 + 0xBE4);
        *(s32 *)(arg1 + 4) = *(s32 *)(DAT_0076449c + 0xBE8);
        *(s32 *)(arg1 + 8) = *(s32 *)(DAT_0076449c + 0xBEC);
        return 1;
    default:
        return 0;
    }
}
/* measured: 1412B / 1424B window, all 59 relocations exact; twelve
   retail zero-alignment bytes. Keep the real unused source input and the
   explicit unsigned counter update with its signed clamp interpretation. */
// FUN_0022D600
void func_0022d600(void *source, u8 *packet, s32 *hpDelta)
{
    u8 *unit;
    u8 *resource;
    void *model;
    u32 hp;
    u32 maxHp;
    u32 remaining;
    s32 percentage;
    RwV3d scale;
    RwV3d translation;

    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)
        return;
    unit = *(u8 **)(packet + 0x30);
    if (*(u8 *)(unit + 0xA2) != 1)
        return;
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x102:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x103:
        resource = func_00147530(*(u8 **)(iGpffff9db0 + 8), 0x2804);
        if (resource == NULL || *(void **)(resource + 0x144) == NULL)
            break;
        hp = *(u16 *)(*(u8 **)(*(u8 **)(packet + 0x30) + 0xA64) + 8);
        maxHp = func_00231f80(*(DatUnit **)(*(u8 **)(packet + 0x30) + 0xA64));
        scale.x = *(f32 *)(*(u8 **)(packet + 0x30) + 0x2C);
        scale.y = *(f32 *)(*(u8 **)(packet + 0x30) + 0x2C);
        scale.z = *(f32 *)(*(u8 **)(packet + 0x30) + 0x2C);
        translation.x = 0.0f;
        translation.y = 0.0f;
        translation.z = -450.0f;
        if (hp < maxHp) {
            mdlScale(*(Model **)(resource + 0x144), &scale, 0);
            func_0047a180(*(RwMatrix **)(resource + 0x144), &translation, 2);
            model = *(void **)(resource + 0x144);
            func_004777d0(model, (s32)D_006355C0, 0xFF);
        }
        if (hp * 100 <= maxHp * 50) {
            mdlScale(*(Model **)(resource + 0x144), &scale, 0);
            func_0047a180(*(RwMatrix **)(resource + 0x144), &translation, 2);
            model = *(void **)(resource + 0x144);
            func_004777d0(model, (s32)D_006355E0, 0xFF);
        }
        if (hp * 100 <= maxHp * 75) {
            mdlScale(*(Model **)(resource + 0x144), &scale, 0);
            func_0047a180(*(RwMatrix **)(resource + 0x144), &translation, 2);
            model = *(void **)(resource + 0x144);
            func_004777d0(model, (s32)D_00635600, 0xFF);
        }
        break;
    case 0x104:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x105:
        if (!func_00106330(0x15C0)) {
            if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
                *(s8 *)(iGpffffb3ac + 0xC12) = 3;
            else
                *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        } else {
            remaining = func_001064f0(0x7A);
            remaining += (u32)*hpDelta;
            if ((s32)remaining <= 0) {
                func_001fae60((s32)func_0022ae00, (s32)func_0022b040, (s32)packet);
                remaining = 0;
            }
            func_00106550(0x7A, remaining);
        }
        break;
    case 0x106:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000) &&
            *(s16 *)(iGpffffb3ac + 0xC34) == 0)
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        if (*(s16 *)(iGpffffb3ac + 0xC34) == 0 || *hpDelta >= 0)
            break;
        packet = func_0019ef90(1, 0x10F);
        if (packet == NULL)
            break;
        func_002325a0(*(DatUnit **)(packet + 0xA64), *hpDelta);
        packet = func_001b0c80((s32)packet);
        /* The paired unit has an active packet; retail deliberately falls through. */
    case 0x10F:
        if (*(s16 *)(iGpffffb3ac + 0xC34) == 0)
            break;
        if (*(s16 *)(iGpffffb3ac + 0xC34) == 1)
            percentage = 40;
        else if (*(s16 *)(iGpffffb3ac + 0xC34) == 2)
            percentage = 60;
        else
            percentage = 100;
        if (func_001d9740(packet, 100 - percentage) ||
            *(u16 *)(*(u8 **)(*(u8 **)(packet + 0x30) + 0xA64) + 8) < 2)
            func_001fae60((s32)func_002299b0, (s32)func_00229c40, (s32)packet);
        break;
    case 0x107:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x10B:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x112:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    }
}
// FUN_0022DB90
void func_0022db90(u8 *arg0) {
    u16 id;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if ((*(s32 *)(temp_6 + 0xC) & 0x200000) &&
        (temp_5 = *(u8 **)(arg0 + 0x30), *(u8 *)(temp_5 + 0xA2) == 1)) {
        id = *(u16 *)(temp_5 + 0xA4);
        switch (id) {
        case 0x102:
            *(u8 **)(temp_6 + 0xB98) = D_0062A5F0;
            return;
        case 0x10D:
            *(u8 **)(temp_6 + 0xB98) = D_0062AD40;
            return;
        case 0x103:
            *(u8 **)(temp_6 + 0xB98) = D_0062B490;
            return;
        case 0x110:
            *(u8 **)(temp_6 + 0xB98) = D_0062BBE0;
            return;
        case 0x111:
            *(u8 **)(temp_6 + 0xB98) = D_0062C330;
            break;
        }
    }
}
/* measured: 2164B / 2176B window, 74 code and 20 table relocations exact.
   Twelve bytes are retail zero alignment. Keep node declared before started:
   reversing them swaps saved-register uses in nine retail instructions. */
// FUN_0022DC70
void func_0022dc70(u8 *packet)
{
    u8 *node;
    s32 started;
    u8 *unit;
    s32 *counter;

    if ((*(u32 *)(DAT_0076449c + 0xC) & 0x200000) == 0)
        return;
    unit = *(u8 **)(packet + 0x30);
    if (unit[0xA2] != 1) {
        switch (func_001ef9a0()) {
        case 0x215:
            if (*(u16 *)(packet + 0x6C) == 2 && *(u16 *)(packet + 0x6E) == 0x115)
                func_001fae60((s32)func_0022ba40, (s32)func_0022bac0, (s32)packet);
            break;
        }
        return;
    }
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x100:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x160)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x101:
        if (*(u16 *)(packet + 0x6C) == 2 || *(u16 *)(packet + 0x6C) == 1) {
            if (*(u16 *)(packet + 0x6E) == 0x161)
                *(s8 *)(DAT_0076449c + 0xC14) = 12;
            else
                *(s8 *)(DAT_0076449c + 0xC14) = -1;
        }
        break;
    case 0x102:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062A5F0;
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x163)
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
            else if (*(u16 *)(packet + 0x6E) == 0x162)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x10D:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062AD40;
        break;
    case 0x103:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062B490;
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x166)
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
            else if (*(u16 *)(packet + 0x6E) == 0x167)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else if (*(u16 *)(packet + 0x6E) == 0x168)
                *(s8 *)(DAT_0076449c + 0xC18) = 14;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x110:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062BBE0;
        break;
    case 0x111:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062C330;
        break;
    case 0x104:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x169)
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x105:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x16B:
                *(s8 *)(DAT_0076449c + 0xC10) = 14;
                *(s8 *)(DAT_0076449c + 0xC13) = 14;
                *(s8 *)(DAT_0076449c + 0xC28) = 14;
                *(s8 *)(DAT_0076449c + 0xC22) = 14;
                *(s8 *)(DAT_0076449c + 0xC1A) = 14;
                *(s8 *)(DAT_0076449c + 0xC12) = 15;
                *(s8 *)(DAT_0076449c + 0xC18) = 17;
                *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) |= 0x20;
                break;
            case 0x16A:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            case 0x16C:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            default:
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            }
        }
        break;
    case 0x106:
        if (*(u16 *)(packet + 0x6C) == 2 || *(u16 *)(packet + 0x6C) == 1) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x16E:
            case 0x16F:
            case 0x170:
            case 0x171:
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
                *(s8 *)(DAT_0076449c + 0xC14) = -1;
                *(u32 *)(DAT_0076449c + 0xC) |= 0x400000;
                *(u16 *)(DAT_0076449c + 0x18) |= 2;
                break;
            default:
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                *(s8 *)(DAT_0076449c + 0xC14) = -1;
                break;
            }
        }
        break;
    case 0x107:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x178)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x108:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x17B:
            case 0x184:
                func_001fae60((s32)func_00229da0, (s32)func_0022a6b0, (s32)packet);
                *(u16 *)(packet + 0x6C) = 8;
                btlActionSetState((BtlAction *)packet, 25);
                *(s32 *)(DAT_0076449c + 0xC38) = 3;
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            case 0x17A:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            case 0x17C:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            default:
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            }
        }
        started = 0;
        counter = (s32 *)(DAT_0076449c + 0xC38);
        if (*counter > 0) {
            *counter -= 1;
            if (*(s32 *)(DAT_0076449c + 0xC38) <= 0) {
                node = *(u8 **)(DAT_0076449c + 0x174);
                while (node != NULL) {
                    if ((*(u16 *)(node + 0x1A) & 1) != 0) {
                        unit = *(u8 **)(node + 0x30);
                        if ((*(u32 *)(unit + 0x9C) & 8) != 0 &&
                            datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100) == 0)
                            break;
                    }
                    node = *(u8 **)(node + 0x450);
                }
                if (node != NULL) {
                    func_001fae60((s32)func_0022a730, (s32)func_0022abd0, (s32)packet);
                    started = 1;
                }
            }
        }
        counter = (s32 *)(DAT_0076449c + 0xC3C);
        if (*counter > 0 && started == 0) {
            *counter -= 1;
            if (*(s32 *)(DAT_0076449c + 0xC3C) <= 0 && func_00106330(0x1435) != 0)
                func_001fae60((s32)func_0022acb0, (s32)func_0022ad40, (s32)packet);
        }
        break;
    case 0x10A:
    case 0x113:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x17D:
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
                break;
            case 0x17E:
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
                break;
            case 0x17F:
            case 0x186:
                *(s8 *)(DAT_0076449c + 0xC10) = 14;
                *(s8 *)(DAT_0076449c + 0xC13) = 14;
                *(s8 *)(DAT_0076449c + 0xC28) = 14;
                *(s8 *)(DAT_0076449c + 0xC22) = 14;
                *(s8 *)(DAT_0076449c + 0xC1A) = 14;
                *(s8 *)(DAT_0076449c + 0xC12) = 14;
                *(s8 *)(DAT_0076449c + 0xC18) = 18;
                *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) |= 0x20;
                break;
            case 0x180:
                *(s8 *)(DAT_0076449c + 0xC10) = -1;
                *(s8 *)(DAT_0076449c + 0xC13) = -1;
                *(s8 *)(DAT_0076449c + 0xC28) = -1;
                *(s8 *)(DAT_0076449c + 0xC22) = -1;
                *(s8 *)(DAT_0076449c + 0xC1A) = -1;
                *(s8 *)(DAT_0076449c + 0xC12) = -1;
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) &= ~0x20;
                break;
            default:
                if (*(s8 *)(DAT_0076449c + 0xC10) == 14)
                    *(s8 *)(DAT_0076449c + 0xC18) = 17;
                else
                    *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            }
        }
        break;
    case 0x10B:
    case 0x10E:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x10B) {
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
                *(u32 *)(DAT_0076449c + 0xC) |= 0x400000;
                *(u16 *)(DAT_0076449c + 0x18) |= 7;
            } else if (*(u16 *)(packet + 0x6E) == 0x185)
                *(s8 *)(DAT_0076449c + 0xC18) = 4;
            else if (*(u16 *)(packet + 0x6E) == 0x182)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    }
}
// FUN_0022E4F0
s32 func_0022e4f0(u8 *arg0, s32 arg1) {
    u16 temp_4_2;
    u8 *temp_4;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 0;
    }
    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) != 1) {
        return 0;
    }
    temp_4_2 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_4_2) {
    case 0x102:
        if (arg1 == 0x163) {
            return 1;
        }
        goto block_25;
    case 0x100:
        if (arg1 == 0x160) {
            return 1;
        }
        goto block_25;
    case 0x103:
        if (arg1 == 0x166) {
            return 1;
        }
        if (arg1 == 0x167) {
            return 1;
        }
        goto block_25;
    case 0x10A:
    case 0x113:
        if (*(s8 *)(temp_6 + 0xC10) == 0xE) {
            return 1;
        }
        if (arg1 == 0x17E) {
            return 1;
        }
        goto block_25;
    case 0x108:
        if (arg1 == 0x17C) {
            return 1;
        }
        goto block_25;
    }
block_25:
    return 0;
}
/* measured: first complete C candidate, 1172/1184 bytes with twelve zero
   alignment bytes; all 28 relocations resolved and no executable differences.
   Enqueue always receives the target, including the four unconditional calls
   for battle 0x215. Stat results and the status-clear mask are explicit. */
// FUN_0022E630
s32 func_0022e630(u8 *arg0)
{
    u8 *unit;
    if ((*(s32 *)(DAT_0076449c + 0xC) & 0x200000) == 0) {
        return 0;
    }
    unit = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(unit + 0xA2) != 1) {
        switch (func_001ef9a0()) {
        case 0x214:
            func_0010b7c0();
            func_0010b010(0xE0);
            func_0010b300(0xE0);
            func_0019ef30(unit, 0xE0);
            func_00106d40(1, 0, 4);
            *(u16 *)(arg0 + 0x18) |= 0x40;
            break;
        case 0x215:
            func_0010b7c0();
            func_0010b010(0xE1);
            func_0010b300(0xE1);
            func_0019ef30(unit, 0xE1);
            func_001056e0(1, (s16)func_00104dc0(1));
            func_00105730(1, (s16)func_00104e30(1));
            func_00105d50(1, -1);
            *(u16 *)(arg0 + 0x18) |= 0x40;
            break;
        }
        return 0;
    }
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x100:
        *(u32 *)(unit + 0x9C) |= 0x4000;
        break;
    case 0x102:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x104:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        **(u16 **)(unit + 0xA64) |= 0x20;
        break;
    case 0x105:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x106:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        **(u16 **)(unit + 0xA64) |= 0x20;
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        func_001b0d70(arg0);
        break;
    case 0x10F:
        *(u16 *)(arg0 + 0x1A) &= ~8;
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        *(u32 *)(unit + 0x9C) &= ~8;
        *(u32 *)(unit + 0x9C) |= 0x2000;
        **(u16 **)(unit + 0xA64) |= 0x20;
        *(u16 *)(unit + 0x9D8) |= 0x20;
        func_001b0d70(arg0);
        break;
    case 0x107:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x109:
        *(u16 *)(arg0 + 0x1A) |= 0x200;
        *(u16 *)(arg0 + 0x1A) |= 0x10;
        func_0019ef30(unit, 0xCE);
        break;
    case 0x10A:
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        func_001b0d70(arg0);
        break;
    case 0x10B:
        **(u16 **)(unit + 0xA64) |= 0x20;
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x10E:
        *(u32 *)(unit + 0x9C) |= 0x2000;
        *(u32 *)(unit + 0x9C) &= ~0x8000;
        if (func_001ef9a0() != 0x215) {
            **(u16 **)(unit + 0xA64) |= 0x20;
            *(u16 *)(arg0 + 0x1A) |= 0x100;
            func_001b0d70(arg0);
        } else {
            func_00106390(0x15C0, 1);
            *(u16 *)(arg0 + 0x1A) |= 0x2000;
            func_001b0d70(arg0);
            func_001b0d70(arg0);
            func_001b0d70(arg0);
            func_001b0d70(arg0);
        }
        break;
    case 0x112:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        *(u16 *)(arg0 + 0x1A) |= 0x10;
        func_0019ef30(unit, 7);
        break;
    case 0x113:
        **(u16 **)(unit + 0xA64) |= 0x20;
        break;
    }
    return 1;
}
// FUN_0022EAD0
s32 func_0022ead0(void) {
    struct {
        s32 sp20;
        s32 sp24;
        f32 sp28;
    } temps;
    u8 *var_16;

    if (!( *(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return 0;
    }
    switch (func_001ef9a0()) {
    case 0x202:
        var_16 = *(u8 **)(DAT_0076449c + 0x180);
        goto loop_check;
loop_body:
        if (*(u16 *)(var_16 + 0xA4) == 0x10D) {
            temps.sp20 = 0x439B0000;
            temps.sp24 = 0;
            temps.sp28 = fGpffff834c;
            func_001ec6d0((s16 *)(var_16 + 0x94), (s16 *)(var_16 + 0x96),
                          (f32 *)&temps.sp20);
            func_00194ee0(var_16, &temps.sp20);
        }
        var_16 = *(u8 **)(var_16 + 0xA6C);
loop_check:
        if (var_16 != NULL) {
            goto loop_body;
        }
        break;
    default:
        break;
    }
    return 1;
}
/* measured: 2428B / 2432B window; all 115 relocations resolve exactly.
   The remaining four bytes are retail zero alignment. Keep the single-case
   action switch, model reloads before each callback, and structured list loop. */
// FUN_0022EBA0
s32 func_0022eba0(u8 *packet)
{
    u8 *unit;
    u8 *other;
    u8 *target;
    u8 *node;
    void *model;
    u32 index;
    RtQuat rotation;

    if ((*(u32 *)(DAT_0076449c + 0xC) & 0x200000) == 0)
        return 1;
    unit = *(u8 **)(packet + 0x30);
    if (unit[0xA2] != 1)
        return 1;
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x105:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x16A:
                *(s8 *)(DAT_0076449c + 0xC10) = -1;
                *(s8 *)(DAT_0076449c + 0xC13) = -1;
                *(s8 *)(DAT_0076449c + 0xC28) = -1;
                *(s8 *)(DAT_0076449c + 0xC22) = -1;
                *(s8 *)(DAT_0076449c + 0xC1A) = -1;
                *(s8 *)(DAT_0076449c + 0xC12) = -1;
                break;
            }
        }
        if (*(s8 *)(DAT_0076449c + 0xC10) == 0xE)
            *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) |= 0x20;
        else
            *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) &= ~0x20;
        break;
    case 0x106:
        if (*(u16 *)(packet + 0x6C) != 2)
            break;
        other = func_0019ef90(1, 0x10F);
        if (other == 0 || *(u8 **)(other + 0xA00) == 0)
            break;
        switch (*(u16 *)(packet + 0x6E)) {
        case 0x16E:
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636C0, 0);
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636C8, 0);
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636D0, 255);
            *(s16 *)(DAT_0076449c + 0xC34) = 1;
            **(u16 **)(unit + 0xA64) |= 0x20;
            target = func_001b0c80((s32)other);
            *(u16 *)(target + 0x1A) &= ~0x400;
            func_002325a0(*(DatUnit **)(other + 0xA64), 0xFFFFFFF);
            func_00198920(other, 0, 0, 1.0f, 1);
            func_0019d040(other);
            break;
        case 0x16F:
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636C0, 0);
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636C8, 255);
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636D0, 255);
            *(s16 *)(DAT_0076449c + 0xC34) = 2;
            **(u16 **)(unit + 0xA64) |= 0x20;
            target = func_001b0c80((s32)other);
            *(u16 *)(target + 0x1A) &= ~0x400;
            func_002325a0(*(DatUnit **)(other + 0xA64), 0xFFFFFFF);
            func_00198920(other, 0, 0, 1.0f, 1);
            func_0019d040(other);
            break;
        case 0x170:
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636C0, 255);
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636C8, 255);
            model = *(void **)(other + 0xA00);
            func_004777d0(model, (s32)D_007636D0, 255);
            /* fall through */
        case 0x171:
            *(s16 *)(DAT_0076449c + 0xC34) = 3;
            **(u16 **)(unit + 0xA64) |= 0x20;
            func_002325a0(*(DatUnit **)(other + 0xA64), 0xFFFFFFF);
            func_00198dd0(other, 0);
            func_00198920(other, 0, 0, 1.0f, 1);
            *(u8 **)(DAT_0076449c + 0xB98) = D_0062E070;
            target = func_001b0c80((s32)other);
            *(u16 *)(packet + 0x1A) &= ~8;
            *(u32 *)(unit + 0x9C) &= ~8;
            *(u16 *)(target + 0x1A) |= 8;
            *(u16 *)(target + 0x1A) &= ~0x400;
            *(u32 *)(other + 0x9C) |= 8;
            if (*(u16 *)(packet + 0x6E) == 0x171) {
                *(u32 *)(other + 0x9C) &= ~0x2000;
                func_003dc740(&rotation, (const RwV3d *)D_0060A0E0, 180.0f, 0);
                btlUnitSetRot((BtlUnit *)other, &rotation);
                *(u32 *)(other + 0x9C) |= 0x2000;
                func_0019d040(other);
            }
            break;
        }
        break;
    case 0x108:
        if (*(u16 *)(packet + 0x6C) != 2 || *(u16 *)(packet + 0x6E) != 0x17A)
            break;
        if (func_00106330(0x15C0) != 0) {
            func_00106390(0x15C5, 1);
            func_00106390(0x15C6, 0);
            func_00106390(0x15C7, 0);
            func_00106390(0x15C8, 0);
            func_00106390(0x1435, 1);
        }
        if (func_00106330(0x15C1) != 0) {
            func_00106390(0x15C5, 0);
            func_00106390(0x15C6, 1);
            func_00106390(0x15C7, 0);
            func_00106390(0x15C8, 0);
            func_00106390(0x1435, 1);
        }
        if (func_00106330(0x15C2) != 0) {
            func_00106390(0x15C5, 0);
            func_00106390(0x15C6, 0);
            func_00106390(0x15C7, 1);
            func_00106390(0x15C8, 0);
            func_00106390(0x1435, 1);
        }
        if (func_00106330(0x15C3) != 0) {
            func_00106390(0x15C5, 0);
            func_00106390(0x15C6, 0);
            func_00106390(0x15C7, 0);
            func_00106390(0x15C8, 1);
            func_00106390(0x1435, 1);
        }
        if (func_00106330(0x15C4) != 0) {
            func_00106390(0x15C5, 0);
            func_00106390(0x15C6, 0);
            func_00106390(0x15C7, 0);
            func_00106390(0x15C8, 0);
            func_00106390(0x15C5 + func_00231d70(4), 1);
            func_00106390(0x1435, 1);
        }
        if (func_00106330(0x1435) != 0)
            *(s32 *)(DAT_0076449c + 0xC3C) = 3;
        break;
    case 0x10A:
    case 0x113:
        if (*(u16 *)(packet + 0x6E) != 0x180)
            break;
        node = *(u8 **)(DAT_0076449c + 0x174);
        while (node != 0) {
            if ((*(u16 *)(node + 0x1A) & 1) != 0) {
                unit = *(u8 **)(node + 0x30);
                if ((*(u32 *)(unit + 0x9C) & 8) != 0 && *(u8 **)(unit + 0xA64) != 0)
                    func_00233880(*(u8 **)(unit + 0xA64), 0x14);
            }
            node = *(u8 **)(node + 0x450);
        }
        break;
    case 0x10E:
        if (*(u16 *)(packet + 0x6E) != 0x181)
            break;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x20000000;
        target = *(u8 **)(packet + 0x88);
        if (target != 0) {
            *(u32 *)(*(u8 **)(target + 0x30) + 0x9C) &= ~8;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x40) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x44) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x48) = iGpffffb45c;
            btlUnitSetColor((BtlUnit *)*(u8 **)(target + 0x30), iGpffffb45c);
            datCalcClearBadStatus((s32)*(u8 **)(*(u8 **)(target + 0x30) + 0xA64), 0xFFF7FFFF);
            unit = *(u8 **)(target + 0x30);
            if ((*(u32 *)(unit + 0x98) & 2) != 0)
                *(u16 *)(unit + 0x9D8) |= 0x10;
        } else {
            index = 0;
            goto targets_check;
targets_body:
            target = *(u8 **)(packet + index * 4 + 0x38);
            if (*(u8 **)(DAT_0076449c + 0x170) == target)
                *(u32 *)(DAT_0076449c + 0x10) |= 0x10000000;
            *(u32 *)(*(u8 **)(target + 0x30) + 0x9C) &= ~8;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x40) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x44) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x48) = iGpffffb45c;
            btlUnitSetColor((BtlUnit *)*(u8 **)(target + 0x30), iGpffffb45c);
            datCalcClearBadStatus((s32)*(u8 **)(*(u8 **)(target + 0x30) + 0xA64), 0xFFF7FFFF);
            unit = *(u8 **)(target + 0x30);
            if ((*(u32 *)(unit + 0x98) & 2) != 0)
                *(u16 *)(unit + 0x9D8) |= 0x10;
            index++;
targets_check:
            if (index < *(u16 *)(packet + 0x6A))
                goto targets_body;
        }
        break;
    }
    return 1;
}
// FUN_0022F520
s32 func_0022f520(void)
{
    struct {
        s64 a;
        s64 b;
        s64 c;
    } sp30;
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    if ((*(s32 *)(DAT_0076449c + 0xC) & 0x200000) == 0) {
        return 0;
    }
    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x202: {
        u8 *var_17;
        u8 *temp_16;
        temp_2_2 = func_0019ef90(1, 0x102);
        if ((temp_2_2 == NULL) ||
            (func_002428f0(*(s32 **)(temp_2_2 + 0xA64), 0) != 0)) {
            func_001f0a10((u8 *)&sp30);
            *(s32 *)&sp30 = 0xFFF00001;
            var_17 = *(u8 **)(DAT_0076449c + 0x174);
            goto loop_0022f520_14_check;
loop_0022f520_14_body:
            if ((*(u16 *)(var_17 + 0x1A) & 1) != 0) {
                temp_16 = *(u8 **)(var_17 + 0x30);
                if ((*(u8 *)(temp_16 + 0xA2) == 1) &&
                    (*(u16 *)(temp_16 + 0xA4) != 0x102) &&
                    (func_002428f0(*(s32 **)(temp_16 + 0xA64), 0) == 0)) {
                    func_00194590(
                        (u8 *)func_001f36e0((s32)(u32)var_17, (s32)(u32)var_17,
                                            (void *)&sp30, 1, 1),
                        1);
                    func_00194590(
                        func_00199ee0(temp_16, 2, 0, 0, 1.0f),
                        1);
                }
            }
            var_17 = *(u8 **)(var_17 + 0x450);
loop_0022f520_14_check:
            if (var_17 != NULL) {
                goto loop_0022f520_14_body;
            }
            return 1;
        }
        goto block_0022f520_27;
    }
    case 0x203: {
        u8 *temp_17;
        u8 *var_16;
        temp_2_3 = func_0019ef90(1, 0x103);
        if ((temp_2_3 == NULL) ||
            (func_002428f0(*(s32 **)(temp_2_3 + 0xA64), 0) != 0)) {
            func_001f0a10((u8 *)&sp30);
            *(s32 *)&sp30 = 0xFFF00001;
            var_16 = *(u8 **)(DAT_0076449c + 0x174);
            goto loop_0022f520_25_check;
loop_0022f520_25_body:
            if ((*(u16 *)(var_16 + 0x1A) & 1) != 0) {
                temp_17 = *(u8 **)(var_16 + 0x30);
                if ((*(u8 *)(temp_17 + 0xA2) == 1) &&
                    (*(u16 *)(temp_17 + 0xA4) != 0x103) &&
                    (func_002428f0(*(s32 **)(temp_17 + 0xA64), 0) == 0)) {
                    func_00194590(
                        (u8 *)func_001f36e0((s32)(u32)var_16, (s32)(u32)var_16,
                                            (void *)&sp30, 1, 1),
                        1);
                    func_00194590(
                        func_00199ee0(temp_17, 2, 0, 0, 1.0f),
                        1);
                }
            }
            var_16 = *(u8 **)(var_16 + 0x450);
loop_0022f520_25_check:
            if (var_16 != NULL) {
                goto loop_0022f520_25_body;
            }
            return 1;
        }
        goto block_0022f520_27;
    }
    default:
        goto block_0022f520_27;
    }
block_0022f520_27:
    return 0;
}
// FUN_0022F7D0
s32 func_0022f7d0(u8 *arg0, u8 *arg1) {
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_4;

    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x208:
        temp_2_2 = (u8 *)func_001b1510();
        if (temp_2_2 != NULL) {
            temp_4 = *(u8 **)(*(u8 **)(temp_2_2 + 0x30) + 0xA64);
            if ((temp_4 != NULL) && (func_00232710(temp_4, 0x100) == 0)) {
                return 0;
            }
        }
        func_001958f0((BtlUnit *)(*(u8 **)(*(u8 **)(DAT_0076449c + 0x170) + 0x30)),
                      (RwV3d *)arg1);
        return 1;
    case 0x10E:
        *(s32 *)(arg1 + 0) = 0;
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)0xBB8;
        return 1;
    default:
        return 0;
    }
}
// FUN_0022F8B0
s32 func_0022f8b0(u8 *arg0, s32 arg1)
{
    u8 *temp_2;

    if (*(s32 *)(DAT_0076449c + 0xC) & 0x200000) {
        goto check_flag;
    }
    return 0;
check_flag:
    if (*(u16 *)(arg0 + 0x1A) & 1) {
        goto load_temp;
    }
    return 0;
load_temp:
    temp_2 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_2 + 0xA2) == 1) {
        goto check_id;
    }
    return 0;
check_id:
    switch (*(u16 *)(temp_2 + 0xA4)) {
    case 0x104:
        if (arg1 != 0x169) {
            goto fail;
        }
        goto done;
    default:
        goto fail;
    }
done:
    return 1;
fail:
    return 0;
}
// FUN_0022F950
s32 func_0022f950(u8 *arg0, u8 *arg1) {
    if (*(s32 *)(DAT_0076449c + 0xC) & 0x200000) {
        if (*(u16 *)(iGpffffb3e0 +
                    (*(u16 *)(arg1 + 0xA4) * 0x58)) & 1) {
            return (func_001f1210(arg1, *(s16 *)(arg0 + 0x6E),
                                  func_001f0ff0()) != 0) ^ 1;
        }
        if ((func_001f0ff0() == 0) &&
            (*(u16 *)(iGpffffb3e0 +
                     (*(u16 *)(arg1 + 0xA4) * 0x58)) & 0x20)) {
            return 1;
        }
        if (func_0022ff70(arg0) == 1) {
            return 1;
        }
        if (func_0022fc00(arg0) == 0) {
            return 1;
        }
    }
    return 0;
}
// FUN_0022FA90
s32 func_0022fa90(u8 *arg0, s64 arg1)
{
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 1;
    }
    if (!(*(u16 *)(arg0 + 0x1A) & 1)) {
        return 1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 1) {
        return 1;
    }
    return *(s8 *)((u8 *)(s16)arg1 + (u32)temp_6 + 0xC10) != -2;
}
// FUN_0022FB10
s32 func_0022fb10(void)
{
    s32 temp_2;

    if (!(*(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return 1;
    }
    temp_2 = func_001ef9a0();
    switch (temp_2) {
    case 0x209:
    case 0x20C:
    case 0x20D:
        return 1;
    default:
        return 0;
    }
}