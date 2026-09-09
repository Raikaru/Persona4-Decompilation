/* Exact panel selection dispatcher func_0020a640, src/promoted/code1_0020.c.
 * 1064/1072 executable/retail bytes,35 independently resolved relocations,8 zero alignment bytes.
 * Initial complete candidate1064 bytes/nd129. Retail confirmation-branch ordering reducednd24.
 * Projecting the stats pointer alone or loading the task through an integer tiednd24; separate
 * stats and task pointer snapshots close the three argument-load pairs at0020A7B0,0020A9D4,0020A9FC.
 * func0010b510 really returns s32; preserve explicit caller-side s16 projection rather than
 * changing the declaration to s16. Persona record and task pointers use the current owner contracts.
 * func00202e70 consumes selection at incominga0; canonical header now takesu8* and all three
 * existing compiled callers passarg0 explicitly. The old zero-argument declarations were removed.
 * func00213c70/func00213ca0 consume the forwarded view task through func00452560(view),which reads
 * work at task+0x38. Both44/48-byte bodies remain exact. These are not ignored arguments.
 * The existing owner21 instruction bodies remain identical; one40-byte switch table is renamed
 * @1002->@1004,with identical contents and all10 relocation targets/addends unchanged.
 * Actual integrated panel source passed229376 Wasm32 cases,ordinary and sanitizer-trap builds:
 * all65536 low-halfword command values,then256 seeds x64 mutation modes x10 focused commands.
 * An independent transition model compares full guarded fixtures,return statuses,and ordered
 * provider arguments/packets. Mutations cover selection snapshots/reloads,task/subwork/view/global
 * pointer changes,active indices and flags. Actual timing and view bodies plus the actual task
 * work-accessor expression are exercised; remaining providers are opaque mutation boundaries.
 * Sanitizer builds enable undefined-behavior,float-cast-overflow and float-divide-by-zero traps.
 * No PS2 graphical presentation claim. No source ASM,register pinning or invented inputs.
 *
 */

#include "type.h"
#include "sdk_snd_internal.h"
#include "btl_panel_internal.h"
extern u8 *func_0010ace0(s16 arg0);
extern s32 func_0010b510(void);
extern void func_0011b360(u8 *arg0);
extern void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s32 arg3);
extern s32 func_0011ba00(u8 *arg0);
extern void func_0011bb90(u8 *arg0);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0011c2c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u32 func_0011c610(u8 *arg0);
extern void func_0011c630(u8 *arg0);
extern void func_0011c6e0(u8 *arg0, s32 arg1);
extern void func_0011caf0(u8 *arg0);
extern void func_00202e00(u8 *arg0, s16 *arg1);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern u8 *iGpffffb3ac;

// FUN_0020A640
u16 func_0020a640(u8 *arg0, u8 *arg1)
{
    s16 sp48[4];
    s16 temp_16;
    u8 *temp_2;
    u16 var_16;
    u8 *stats;
    u8 *task;

    var_16 = (u16)(func_00202e70(arg0) & 0xFFFF);
    switch (var_16) {
    case 2:
        temp_16 = *(s16 *)(arg0 + 4);
        if (temp_16 != (s16)func_0010b510()) {
            temp_2 = func_0010ace0(temp_16);
            *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 5;
            *(u16 *)(*(u8 **)(arg1 + 0x178) + 0x74) = *(u16 *)((u8 *)temp_2 + 2);
            func_0011b360(*(u8 **)(arg1 + 0x5A8));
            *(u8 **)(arg1 + 0x5A8) = NULL;
            *(s16 *)(arg1 + 0x5AC) = -1;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
            func_00213c70(*(u8 **)(arg1 + 0x5B0));
            var_16 = 4;
        } else {
            func_0045af60(0, 15, 0, 8);
            var_16 = 1;
        }
        break;

    case 3:
        if (*(s16 *)(arg1 + 0x5AC) == -1) {
            if (func_0011ba00(*(u8 **)(arg1 + 0x5A8)) == 0) {
                temp_2 = func_0010ace0(*(s16 *)(arg0 + 4));
                *(s32 *)(iGpffffb3ac + 0xC) &= ~0x2000;
                *(s32 *)(iGpffffb3ac + 0xC) &= ~0x20000;
                stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                task = *(u8 **)(arg1 + 0x5A8);
                func_0011b480(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                func_0011bb90(*(u8 **)(arg1 + 0x5A8));
                func_00213ca0(*(u8 **)(arg1 + 0x5B0));
                func_0043f9c8(sp48, 0, 8);
                sp48[0] = 4;
                sp48[1] = 8;
                func_00202e00(arg0, sp48);
                *(u16 *)arg0 &= ~2;
                *(u16 *)arg0 &= ~1;
                *(u16 *)arg0 &= ~8;
                *(s16 *)(arg1 + 0x5AC) = *(s16 *)(arg0 + 4);
            }
        } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) == 0) {
            func_0011c630(*(u8 **)(arg1 + 0x5A8));
        } else {
            func_0011c6e0(*(u8 **)(arg1 + 0x5A8), 1);
        }
        break;

    case 1:
        if (*(s16 *)(arg1 + 0x5AC) == -1) {
            func_0011b360(*(u8 **)(arg1 + 0x5A8));
            *(u8 **)(arg1 + 0x5A8) = NULL;
            *(s16 *)(arg1 + 0x5AC) = -1;
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) == 0) {
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
            func_0011bc70(*(u8 **)(arg1 + 0x5A8));
            *(s16 *)(arg1 + 0x5AC) = -1;
            func_00202e00(arg0, NULL);
            func_00213c70(*(u8 **)(arg1 + 0x5B0));
            *(u16 *)arg0 |= 2;
            *(u16 *)arg0 |= 1;
            *(u16 *)arg0 |= 8;
            func_0045af60(0, 0, 0, 4);
            var_16 = 1;
        } else {
            func_0011c6e0(*(u8 **)(arg1 + 0x5A8), 1);
        }
        break;

    default:
        if (*(s16 *)(arg1 + 0x5AC) != -1) {
            if (*(s16 *)(arg1 + 0x5AC) != *(s16 *)(arg0 + 4)) {
                temp_2 = func_0010ace0(*(s16 *)(arg0 + 4));
                if (var_16 == 5) {
                    stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                    task = *(u8 **)(arg1 + 0x5A8);
                    func_0011c180(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                } else {
                    stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                    task = *(u8 **)(arg1 + 0x5A8);
                    func_0011c2c0(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                }
                *(s16 *)(arg1 + 0x5AC) = *(s16 *)(arg0 + 4);
            } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) != 0) {
                func_0011caf0(*(u8 **)(arg1 + 0x5A8));
            }
        }
        var_16 = 1;
        break;
    }

    return var_16;
}