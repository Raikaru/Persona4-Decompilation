#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"

typedef struct BtlPacket BtlPacket;

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;

extern u8 *iGpffffa5f0;

extern void btlBuildNpcModelName(s32 *arg0, s32 arg1);
extern s64 datGetDateIndex(void);
extern s32 func_00110d60(s16 arg0);
extern s32 sprintf(char *buf, char *fmt, ...);
extern void btlBossResolveNpcModelName(s32 arg0, u16 arg1);
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern char D_007636e0;
extern char D_006358D0[];
extern char D_006358F0[];
extern char D_00635910[];
extern char D_00635678[];
extern char D_00635690[];
extern char D_006356B0[];
extern char D_006356D0[];
extern char D_006356F0[];
extern char D_00635710[];
extern char D_00635730[];
extern char D_00635750[];
extern char D_00635770[];
extern char D_00635790[];
extern char D_006357B0[];
extern char D_006357C8[];
extern void mdlAttachSlotModelFromResource(void *model, u16 slot, u32 type, u16 id,
                           void *path, u32 flags);
extern void mdlAttachSlotModelFindOrCreate(void *model, u16 slot, u32 type, u16 id,
                          u32 flags);
extern char D_006357E0[];
extern char D_00635800[];

/* Source unit: src/promoted/code1_0023.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0023.c; members 00231380-00231550 */

// Intent: Writes the NPC model file name for a battle model id: the "npc/" or "npc2/" directory, the id and a variant from its table entry and the current flags [inferred]
// FUN_00231380
void btlBuildNpcModelName(s32 *arg0, s32 arg1)
{
    u32 sp5C;
    s16 var_17;
    s32 var_19;
    s32 temp_18;
    s32 temp_5;
    s32 var_4;
    s32 var_6;
    s64 temp_17;
    s64 temp_3_2;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;

    var_19 = 0;
    var_17 = 0;
    temp_2 = func_00455f70(&D_006358D0, &sp5C);
    temp_5 = *(s32 *)(temp_2 + 4);
    temp_4 = temp_2 + 8;
    temp_18 = arg1 & 0xFFFF;
    var_6 = 0;
    while (var_6 < temp_5)
    {
        temp_3 = temp_4 + (var_6 * 4);
        if (temp_18 == *(u16 *)temp_3)
            var_17 = *(s16 *)(temp_3 + 2);
        else
        {
            var_6++;
            continue;
        }
        break;
    }
    temp_17 = (s64)var_17;
    if (temp_17 > 0)
    {
        temp_3_2 = (s64)(s16)func_00110d60((s16)datGetDateIndex());
        if (!(temp_3_2 & 1))
        {
            if (temp_17 & 3)
                var_4 = 0;
            else
                var_4 = 1;
        }
        else if (temp_17 & 0xC)
            var_4 = 1;
        else
            var_4 = 0;
        if (temp_3_2 & 2)
        {
            if (temp_17 & 0xA)
                var_19 = (var_4 * 2) + 2;
            else
                var_19 = (var_4 * 2) + 1;
        }
        else if (temp_17 & 5)
            var_19 = (var_4 * 2) + 1;
        else
            var_19 = (var_4 * 2) + 2;
    }
    if (temp_18 < 0xC50)
        sprintf((char *)arg0, D_006358F0, &D_007636e0,
                      temp_18, var_19);
    else
        sprintf((char *)arg0, D_00635910, &D_007636e0,
                      temp_18, var_19);
}

// Intent: Boss model name resolver for case 5 (NPC models): forwards to btlBuildNpcModelName [inferred]
// FUN_00231550
void btlBossResolveNpcModelName(s32 arg0, u16 arg1)
{
    btlBuildNpcModelName((s32 *)arg0, arg1 & 0xFFFF);
}

