/* Fresh field-state reconstruction; production remains ASM.
 * MWCC b210 -O2 -Iinclude: 2192/2192 bytes, all 112 code relocations
 * resolved. Three executable words differ at +0x1B0/+0x1B4/+0x1B8:
 * retail moves task to a0 before the two unsigned field/room loads;
 * this candidate emits those loads first. No missing/excess bytes.
 * The complete 76-byte switch table at 0x00746C60 resolves all nineteen
 * targets exactly. Both existing C owner functions retain retail identity.
 * Only compiler/relocation evidence is claimed; no native state-machine
 * execution or hardware equivalence has been established for this candidate.
 * Replay: python tools/probe_archive.py docs/probe_archive/FFS_00155360_body.c src/Kosaka/Field/k_field.c
 */
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
extern s32 func_00106330(s32);
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
extern s32 func_00156640(u8 *, s32, s32, s16, s16, s32, s32, s32);
extern s32 func_00162c30(void);
extern s32 func_00452490(s32);
extern s32 func_001614d0(void);
extern void func_00162e10(void);
extern void func_001658b0(void);
extern s32 func_0014a160(void);
extern s32 func_00442088(char *, const void *, ...);
extern s32 func_00477e80(s32, s32, const char *, s32);
extern s32 func_00165be0(void);
extern s32 func_004782b0(s32);
extern s32 func_001227f0(void);
extern s32 func_002859e0(s32, s32, s32);
extern void func_0016ea40(s32, u16);
extern void func_0016f130(u8 *, s32, s32);
extern s32 func_0014b510(s32);
extern s32 func_00145ac0(s32, s32);
extern void func_0014a0f0(u16, s32);
extern void func_0015a350(f32 *);
extern void func_0047a180(s32, f32 *, s32);
extern u8 *func_00145270(u16);
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
extern void func_00454bd0(u8 *);
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
    if (work->state > 2 && work->state < 11 && func_00106330(0x1470) == 0) {
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
                    func_00442088(filename, D_005EFF20,
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
                object = func_00145270(modelId);
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
                func_00454bd0(work->roomData);
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
