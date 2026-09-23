/* Original translation unit k_field.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

extern s32 iGpffffb20c;
extern s32 iGpffffb2e4;
extern u8 *iGpffff9db0;
extern s32 D_007E8060[];
extern u8 D_007E80A0[];
extern s32 D_007D2510[];

#define KFIELD_D_007D2540 (*(s32 *)0x007D2540)
#define KFIELD_D_007E8060 (D_007E8060)
#define KFIELD_D_007E80A0 (D_007E80A0)
#define KFIELD_D_007D2510 (D_007D2510)
#define KFIELD_JTBL_008873EC (*(void (**)(s32))((u8 *)0x00880000 + 0x73EC))

extern void func_00123ac0(void);
extern void func_00167530(void);
extern void func_002bd410(void);
extern void func_002bd3e0(void);
extern void func_00149690(s32);
extern void func_00452080(s32);
extern void func_00151f80(s32);
extern s32 func_00102980(void);
extern void func_001622d0(void);
extern void func_00164170(void);
extern void func_001641d0(void);
extern void memset(void *, s32, s32);
extern void func_00156750(u8 *);
extern u8 *func_00457120(void);
extern void func_003e9df0(s32);

/* Fresh reconstruction retained in FFS_00155360_body.c: 2192/2192 bytes,
   112 resolved code relocations and all 19 switch targets match except the
   three argument-setup instructions at +0x1B0..+0x1B8. Retail moves task
   before loading field/room; the candidate loads them first. Remains ASM. */
typedef struct KFieldStateWork {
    s32 state;
    u8 reserved04[4];
    s32 exitRequested;
    s32 eventId;
    s32 eventMajor;
    s32 eventMinor;
    u16 field;
    u16 room;
    u16 entry;
    u8 reserved1e[2];
    s16 spawn;
    s16 direction;
    u8 reserved24[8];
    u8 *roomData;
    s32 loadTask;
    u8 reserved34[8];
    s32 eventReader;
    s32 eventTask;
    s32 scriptTask;
    u8 reserved48[4];
    s32 model;
    u8 reserved50[0x88];
    u8 transition[0x1C];
} KFieldStateWork;

extern s32 iGpffffb210;
extern s32 iGpffffb268;
extern u8 D_005EFF10[];
extern u8 D_005EFF20[];
extern u8 *D_007D3D64[];
extern s32 D_007D3D68[];
extern s32 D_007D2514[];
extern s32 D_007D2518[];
extern s32 D_007D2528[];
extern s32 D_007D252C[];
extern s32 D_007D2530[];
extern s32 D_007D253C[];
extern u16 *D_007EFA04[];
extern s32 datGetFlag(s32);
extern void func_002aaa80(void);
extern void func_002aaaa0(void);
extern s32 func_00293fc0(s32);
extern s32 func_002940a0(s32, s32 *, s32 *, s32 *, s32 *);
extern void func_0046d730(const void *, s32);
extern void func_0014eed0(u16, u16);
extern void func_00162200(s32);
extern void func_001227d0(void);
extern void func_00164230(u16, u16, u16);
extern void func_00149680(s32);
extern s32 func_00156640(u8 *, u16, u16, s16, s16, s32, s32, s32);
extern s32 func_00162c30(void);
extern s32 func_00452490(s32);
extern s32 func_001614d0(void);
extern void func_00162e10(void);
extern void func_001658b0(void);
extern s32 func_0014a160(void);
extern s32 sprintf(char *, const void *, ...);
extern s32 func_00477e80(s32, s32, const char *, s32);
extern s32 func_00165be0(void);
extern s32 func_004782b0(s32);
extern s32 func_001227f0(void);
extern s32 func_002859e0(s32, s32, s32);
extern void func_0016ea40(s32, u16);
extern void func_0016f130(u8 *, s32, s32);
extern u16 func_0014b510(s32);
extern s32 func_00145ac0(u16, s32);
extern void func_0014a0f0(u16, s32);
extern void func_0015a350(f32 *);
extern void func_0047a180(s32, f32 *, s32);
extern u8 *MT_Scene_GetRes(u16);
extern s32 func_0029da90(s32, u8 *, s32);
extern s32 func_0014a200(void);
extern u8 *func_0015a0c0(void);
extern u8 *func_0015c590(u8);
extern s32 func_0015c5f0(u8 *);
extern s32 func_0015a160(void);
extern s32 func_0015a6b0(s32);
extern void func_001664a0(void);
extern void func_001662d0(void);
extern s32 func_00166b40(u8 *, s32);
extern s32 func_0014a270(void);
extern s32 func_002ae630(u8 *);
extern void func_002b2950(s32);
extern s32 func_00186640(u8 *);
extern s32 func_0018ced0(void);
extern void func_0018c7e0(void);
extern void func_00189ec0(void);
extern s32 func_00166c30(s32);
extern void func_00122640(s32, s32);
extern s32 func_00122720(void);
extern s32 func_0029db50(s32, u8 *, s32, s32);
extern void H_Cdvd_Destroy(u8 *);
extern void func_001552a0(u16, u16);
extern s32 func_0018df60(u8 *);
extern s32 func_00174ad0(u8 *);
extern void func_00182310(s32);
extern s32 func_0028b260(void);
extern void func_001029a0(s32, void *, s32, s32);

#pragma opt_propagation off
// FUN_00155360
s32 func_00155360(u8 *task)
{
    s32 field;
    s32 room;
    s32 spawn;
    s32 direction;
    f32 position[3];
    char filename[32];
    s32 index;
    s32 eventMode;
    s32 scriptSize;
    s32 model;
    u16 modelId;
    u16 modelField;
    u8 *object;
    KFieldStateWork *work;

    work = *(KFieldStateWork **)(task + 0x38);
    if (work->state > 2 && work->state < 11 && datGetFlag(0x1470) == 0) {
        func_002aaa80();
    }
    switch (work->state) {
    case 0:
        if (func_00293fc0(work->eventReader) != 0) {
            if (func_002940a0(work->eventReader, &field, &room, &spawn, &direction) == 1) {
                if (field == 0) {
                    func_0046d730(D_005EFF10, 0xD6);
                }
                work->field = field;
                work->room = room;
                work->spawn = spawn;
                work->direction = direction;
                func_0014eed0(work->field, work->room);
                for (index = 0; index < 4; index++) {
                    func_00162200(index);
                }
                func_001227d0();
                work->state = 2;
            } else {
                func_0046d730(D_005EFF10, 0xE8);
            }
        }
        break;
    case 1:
        func_001227d0();
        work->state++;
        /* fallthrough */
    case 2:
        if (work->eventReader == 0) {
            func_00164230(work->field, work->room, work->entry);
        }
        func_00149680(1);
        eventMode = work->eventReader != 0;
        work->loadTask = func_00156640(task, work->field, work->room, work->spawn,
            work->direction, eventMode, work->eventId, work->eventMajor);
        work->state++;
        /* fallthrough */
    case 3:
        if (func_00162c30() != 0 && func_00452490(work->loadTask) != 1) {
            if (func_001614d0() == 3) {
                func_00149690(1);
            }
            work->state = 4;
        }
        break;
    case 4:
        func_00162e10();
        if (work->eventReader == 0) {
            func_001658b0();
            if (func_0014a160() == 1) {
                modelField = work->field;
                if (modelField == 0x2C || modelField == 0x2E || modelField == 0x2F ||
                    modelField == 0x30 || modelField == 0x40 || modelField == 0x42 ||
                    modelField == 0x43 || modelField == 0x44) {
                    sprintf(filename, D_005EFF20,
                        modelField < 0x32 ? modelField : modelField - 0x14);
                    work->model = func_00477e80(4, 0xFFFD, filename, 0);
                }
            }
        }
        work->state++;
        break;
    case 5:
        if (func_00165be0() == 0) break;
        if (work->model != 0 && func_004782b0(work->model) == 0) break;
        if (work->eventReader != 0) {
            if (func_001227f0() != 0) {
                func_00149680(0);
                func_002aaaa0();
                work->eventTask = func_002859e0(work->eventId, work->eventMajor, work->eventMinor);
                work->state = 14;
            }
        } else {
            func_0016ea40(D_007D2514[0], *D_007EFA04[0]);
            func_0016f130(task, 1, -1);
            model = work->model;
            if (model != 0) {
                modelId = func_00145ac0(func_0014b510(10), model);
                func_0014a0f0(modelId, 1);
                func_0015a350(position);
                func_0047a180(work->model, position, 2);
                object = MT_Scene_GetRes(modelId);
                *(u32 *)(object + 0x28) |= 0x02000000;
            }
            work->state++;
        }
        break;
    case 6:
        if (func_001227f0() != 0) {
            func_00149680(0);
            iGpffffb210 = 2;
            if (work->eventReader == 0) {
                if (D_007D3D64[0] != NULL && iGpffffb268 == 0) {
                    work->scriptTask = func_0029da90(15, D_007D3D64[0], work->room - 1);
                }
                if (func_0014a200() == 1) {
                    work->roomData = func_0015c590(*(u8 *)(func_0015a0c0() + 0xC));
                }
            }
            work->state++;
        }
        break;
    case 7:
        if (work->eventReader == 0 && work->scriptTask != 0 && func_00452490(work->scriptTask) == 1) break;
        work->state++;
        /* fallthrough */
    case 8:
        if (func_0015c5f0(work->roomData) == 0) break;
        work->state++;
        /* fallthrough */
    case 9:
        if (func_0015a6b0(func_0015a160()) != 0) {
            func_001664a0();
        } else {
            func_001662d0();
        }
        D_007D2530[0] = func_00166b40(task, -1);
        if ((func_0014a200() == 1 || func_0014a270() == 1) &&
            (*(s32 *)(iGpffff9db0 + 0) != 0x44 || *(s32 *)(iGpffff9db0 + 4) != 1)) {
            D_007D2528[0] = func_002ae630(task);
            func_002b2950(1);
        }
        if (func_0015a160() != 0) {
            D_007D253C[0] = func_00186640(task);
        }
        if (func_0018ced0() == 0) {
            func_0018c7e0();
        }
        func_00189ec0();
        work->state++;
        /* fallthrough */
    case 10:
        if (func_00166c30(D_007D2530[0]) == 0) break;
        func_002aaaa0();
        func_00122640(1, 0);
        work->state++;
        /* fallthrough */
    case 11:
        if (func_00122720() == 0) break;
        iGpffffb210 = 3;
        if (func_0014a200() == 1) {
            work->scriptTask = func_0029db50(15, *(u8 **)(work->roomData + 0x110),
                *(s32 *)(work->roomData + 0x118), 0);
        } else if (D_007D3D64[0] != NULL && iGpffffb268 == 0) {
            scriptSize = D_007D3D68[0];
            work->scriptTask = func_0029db50(15, D_007D3D64[0], scriptSize, work->room - 1);
        }
        work->state++;
        /* fallthrough */
    case 12:
        if (work->scriptTask != 0) {
            if (func_00452490(work->scriptTask) == 1) break;
            if (work->roomData != NULL) {
                H_Cdvd_Destroy(work->roomData);
                work->roomData = NULL;
            }
        }
        func_001552a0(work->field, work->room);
        D_007D252C[0] = func_0018df60(task);
        D_007D2518[0] = func_00174ad0(task);
        func_00182310(0);
        work->state++;
        /* fallthrough */
    case 13:
        if (work->exitRequested != 0) {
            work->state = 18;
        }
        break;
    case 14:
        if (func_00452490(work->eventTask) != 1 && func_0028b260() == 0) {
            work->state = 18;
        }
        break;
    case 17:
        if (func_00122720() != 0) {
            func_001029a0(9, work->transition, 0x1C, 0);
            work->state++;
        }
        break;
    case 18:
        D_007D2510[0] = 0;
        return -1;
    }
    return 0;
}

#pragma opt_propagation on


/* measured: func_00155bf0 now matches at normalized_diff 0 (object 540B/window 544B); spelling the second range as <= 0x1E makes MWCCPS2 use the retail $at branch temporary, with the same trailing window nop. */
// Committed at nd 0.
// FUN_00155BF0
void func_00155bf0(u8 *arg0)
{
    u8 *temp_17;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_16;
    s32 *temp_20;
    s32 *temp_2;
    s32 var_18;

    temp_17 = *(u8 **)(arg0 + 0x38);
    if (iGpffffb20c == 1) {
        func_00123ac0();
    }
    func_00167530();
    func_002bd410();
    func_002bd3e0();
    KFIELD_D_007D2540 = 0;
    func_00149690(0);
    temp_4 = *(s32 *)(temp_17 + 0x3C);
    if (temp_4 != 0) {
        func_00452080(temp_4);
        var_18 = 0;
        while (var_18 < 0x10) {
            temp_16 = var_18 * 4;
            temp_20 = (s32 *)KFIELD_D_007E8060 + var_18;
            temp_4_2 = *temp_20;
            if (temp_4_2 != 0) {
                func_00151f80(temp_4_2);
                *temp_20 = 0;
                *(s32 *)(iGpffff9db0 + temp_16 + 0x28) = 0;
            }
            var_18 += 1;
        }
    }
    if (func_00102980() != 9 &&
        func_00102980() != 0xB &&
        func_00102980() != 0xA) {
        func_001622d0();
    }
    if ((u16)*(u16 *)(temp_17 + 0x18) < 0x15) {
        goto field_special;
    }
    if (*(u16 *)(temp_17 + 0x18) <= 0x1E) {
        goto field_call;
    }
field_special:
    if (*(u16 *)(temp_17 + 0x18) != 6) {
        goto field_done;
    }
    if (*(u16 *)(temp_17 + 0x1A) != 1) {
        goto field_done;
    }
field_call:
    func_001622d0();
field_done:
    func_00164170();
    func_001641d0();
    memset(KFIELD_D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    func_00156750(arg0);
    temp_16 = 0;
    while (temp_16 < 3) {
        temp_2 = (s32 *)KFIELD_D_007D2510 + temp_16;
        temp_4_3 = *(s32 *)((u8 *)temp_2 + 0x34);
        if (temp_4_3 != 0) {
            func_00452080(temp_4_3);
            *(s32 *)((u8 *)temp_2 + 0x34) = 0;
        }
        temp_16 += 1;
    }
    func_003e9df0(*(s32 *)(func_00457120() + 4));
    KFIELD_JTBL_008873EC(*(s32 *)(arg0 + 0x38));
}

extern void func_00451b70(void);
extern u8 *D_007D3D64[];
extern u8 D_005EFF10[];
extern u8 D_005EFF48[];
extern void func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void func_00149680(s32 arg0);
extern s32 func_00293ed0(s32 a, s32 b, s32 c, s32 d);
extern void func_0029ddb0(s32 arg0);
extern void func_0014eed0(u16 arg0, u16 arg1);
extern u8 D_007D255A[];
extern u8 D_007D255B[];
extern s32 D_007D255C[];
typedef struct { f32 x; f32 y; f32 z; } KFieldVec3;
extern s64 D_005EFF38[];
extern f32 D_005EFF40[];
extern void RwEngineGetMatrixTolerances(f32 *arg0);
extern void RwMatrixOptimize(void *arg0, f32 *arg1);
extern void func_003e9680(void *arg0);
extern s32 func_00155360(u8 *arg0);
/* measured: object 648B/window 656B, nd 0. The six stack parameters are s64
   slots read in place through `*(s32 *)&argN` / `*(u8 *)&arg8`: an s32
   stack parameter with several uses gets homed into $s2 at entry and pushes
   the u8 register parameter out to a byte spill, while the address-taken
   slot reads are plain lw/lbu every time exactly as retail reloads them.
   Register parameters colour $s1,$s4,$s3,$s2,$s5-$s8 with the work pointer in
   $s0 and the handle reusing $s1. The camera position constant is copied as
   an s64 + f32 scalar pair (two lui, both loads before both stores, which
   needs opt_propagation off) into a Vec3 local that is then assigned as a
   12-byte aggregate (three lwc1 then three swc1). func_0014eed0 takes the
   two u16 parameters unmasked. */
// FUN_00155E10
/* measured: opt_propagation off keeps the scalar-pair copy's two loads ahead
   of its two stores. */
#pragma opt_propagation off
s32 func_00155e10(u8 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5, s32 arg6, u8 arg7,
                  s64 arg8, s64 arg9, s64 arg10, s64 arg11, s64 arg12, s64 arg13)
{
    f32 matrix[4];
    KFieldVec3 pos;
    s32 handle;
    u8 *work;
    s64 copy_s64;
    f32 copy_f32;
    u8 *cam;

    func_00451b70();
    if (D_007D3D64[0] != NULL) {
        KFIELD_JTBL_008873EC((s32)D_007D3D64[0]);
    }
    memset(D_007D2510, 0, 0x18DC);
    func_0044ea90(D_005EFF10, 0x2AF);
    work = D_008873F4[0](1, 0xF4, 0x40000);
    if (work == NULL) {
        return 0;
    }
    handle = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005EFF48), 0xF, 0, 0, func_00155360, func_00155bf0, (u8 *)(work));
    D_007D2510[0] = handle;
    func_00149680(0);
    if (*(s32 *)&arg10 > 0) {
        *(s32 *)(work + 0x3C) = func_00293ed0(*(s32 *)&arg10, *(s32 *)&arg11, *(s32 *)&arg12, *(s32 *)&arg13);
        *(s32 *)(work + 0) = 0;
        *(s32 *)(work + 0xC) = *(s32 *)&arg10;
        *(s32 *)(work + 0x10) = *(s32 *)&arg11;
        *(s32 *)(work + 0x14) = *(s32 *)&arg12;
    } else {
        func_0029ddb0(*(s32 *)&arg10);
        *(u16 *)(work + 0x18) = arg1;
        *(u16 *)(work + 0x1A) = arg2;
        *(s16 *)(work + 0x20) = arg4;
        *(s16 *)(work + 0x22) = arg5;
        *(u16 *)(work + 0x1C) = arg3;
        *(s32 *)(iGpffff9db0 + 0x88) = arg6;
        D_007D255A[0] = arg7;
        D_007D255B[0] = *(u8 *)&arg8;
        D_007D255C[0] = *(s32 *)&arg9;
        func_0014eed0(arg1, arg2);
        *(s32 *)(work + 0) = 1;
    }
    copy_s64 = D_005EFF38[0];
    copy_f32 = D_005EFF40[0];
    *(s64 *)&pos.x = copy_s64;
    pos.z = copy_f32;
    func_003e9df0(*(s32 *)(func_00457120() + 4));
    cam = *(u8 **)(func_00457120() + 4);
    *(KFieldVec3 *)(cam + 0x40) = pos;
    RwEngineGetMatrixTolerances(matrix);
    RwMatrixOptimize(*(u8 **)(func_00457120() + 4) + 0x10, matrix);
    func_003e9680(*(u8 **)(func_00457120() + 4));
    return handle;
}

/* measured: closes the propagation bracket; the unit default is on. */
#pragma opt_propagation on
