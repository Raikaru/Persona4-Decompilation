#include "btl_target_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *config);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
static inline u8 *btlTargetOffsetAddress(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}

extern s32 datCalcThresholdTrigger(u8 *unit, s32 skillId);
extern s32 datCalcDefaultSkillId(u8 *unit);

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern u32 datCalcRandomBelow(u32);


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u32 datCalcRandomBelow(u32);



extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 D_00609E40[];
extern u8 *btlPacketAlloc(s32, s32);
extern u8 *btlFormationGetRecord(s32);
extern s32 scrFindPrcdIdxByName(s32, s32);
extern s32 btlTargetSpawnActionProc(u8 *);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001ebb00-001ebc00 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
#pragma push
#pragma pop
/* measured probe: preserve the retail filter branch chain */
#pragma push
/* measured probe: close the filter branch chain */
#pragma pop
/* measured probe: preserve retail conditional branch shape */
#pragma push
/* measured probe: close conditional branch shape */
#pragma pop
/* measured: optimization_level 1 probe for retail GP-load scheduling. */
/* measured: close optimization_level 1 probe for btlAiGetGlobal. */
/* measured: opt_propagation off probe for e320 GP-load order. */
/* measured: closes opt_propagation probe for btlAiSetGlobal. */
// FUN_001EBB00
/* Resolve a named procedure in the selected script and create a one-shot action task packet. */
u8 *btlTargetCreateProcedurePacket(s32 action, s32 scriptKind, u8 *procedureName) {
    /* measured: typed forms of the retained raw accesses changed code generation;
     * keep byte-pointer aliasing at these sites to preserve the retail sequence. */
    s32 kind;
    u8 *work;
    u8 *packet;

    packet = btlPacketAlloc(0xD00, 0x10);
    ((BtlPacket *)packet)->flags &= 0xEE;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlTargetSpawnActionProc;
    work = (u8 *)(((BtlPacket *)packet)->workData);
    kind = scriptKind & 0xFFFF;
    switch (kind) {
    case 1:
        ((BtlTargetProcedure *)work)->script = (s32)iGpffffb428;
        break;
    case 2:
        ((BtlTargetProcedure *)work)->script = (s32)iGpffffb42c;
        break;
    case 3:
        ((BtlTargetProcedure *)work)->script = (s32)btlFormationGetRecord(0);
        break;
    }
    ((BtlTargetProcedure *)work)->action = action;
    ((BtlTargetProcedure *)work)->procedure = scrFindPrcdIdxByName(((BtlTargetProcedure *)work)->script, (s32)procedureName);
    ((BtlTargetProcedure *)work)->started = 0;
    return packet;
}

/* Pick a random usable skill from the supported set, falling back to the default attack. */
// FUN_001EBC00
/* 1468/1472 bytes; all four call relocations resolve exactly. */
/* measured: func_001ebc00 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* Pick a usable skill from the supported set; fall back to the default attack when none qualify. */
void btlAiChooseUsableAttackSkill(u8 *action, u8 *command)
{
    u16 choices[8];
    u16 *skills;
    s32 index;
    s32 count;
    u32 skill;
    u32 available;

    skills = (u16 *)datCalcSkillList(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit);
    count = 0;
    index = 0;
    while ((index & 0xFFFF) < 8) {
        skill = skills[index & 0xFFFF];
        if (skill != 0) {
            switch (skill) {
            case 0x01:
            case 0x02:
            case 0x03:
            case 0x04:
            case 0x05:
            case 0x06:
            case 0x07:
            case 0x08:
            case 0x0E:
            case 0x0F:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x1A:
            case 0x1B:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
            case 0x20:
            case 0x21:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x58:
            case 0x59:
            case 0x5A:
            case 0x5B:
            case 0x5C:
            case 0x5D:
            case 0x5E:
            case 0x5F:
            case 0x78:
            case 0x79:
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8E:
            case 0x8F:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
            case 0x98:
            case 0x99:
            case 0x9A:
            case 0x9B:
            case 0x9C:
            case 0x9D:
            case 0x9E:
            case 0x9F:
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA8:
            case 0xA9:
            case 0xAB:
            case 0xAC:
            case 0xAD:
                if (datCalcThresholdTrigger((u8 *)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit), skill) == 0) {
                    choices[count & 0xFFFF] = skill;
                    count = (count + 1) & 0xFFFF;
                }
                break;
            }
        }
        index = (index + 1) & 0xFFFF;
    }
    available = count & 0xFFFF;
    if (available == 0) {
        ((BtlTargetRecord *)command)->kind = 1;
        ((BtlTargetRecord *)command)->command = datCalcDefaultSkillId((u8 *)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit));
    } else {
        ((BtlTargetRecord *)command)->kind = 2;
        ((BtlTargetRecord *)command)->command = choices[datCalcRandomBelow(available)];
    }
}

