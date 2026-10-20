/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00380980-00380d80 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_shuffle_state_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"
#include "datPersona_internal.h"
s32 datGetFlag(u32 bit);
extern void memset(void *dst, s32 value, u32 size);
extern void nmMesWindowShowCurrentRecord(s32 recordIndex);
extern void nmMesWindowSetCurrentString(s32 variable, void *text);
/* Build the selected reward roster and populate its message substitutions and trail. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 413..413); retain only the failing byte-base accesses. */
// FUN_00380980
s32 btlShuffleShowRosterMessage(u8 *rosterWork)
{
    typedef struct {
        s32 active;
        u16 value0;
        u16 value1;
        u16 value2;
    } Result;
    extern s32 btlShuffleBuildRoster(s32 selector, s32 *result);
    extern u8 *datCalcGetIdRecord(s32 skillId);
    extern s32 nmMesWindowShowCurrentRecord(s32 recordIndex);
    extern void nmMesWindowSetCurrentString(s32 variable, void *text);
    extern void btlShuffleEffInitTrail(u8 *task, s32 slotIndex);
    extern void sprintf(void *rosterWork, const void *personaId, s32 number);
    extern s32 D_0064EB80[];
    extern s32 D_0064EB84[];
    extern u8 D_0064EC30[];
    extern u8 iGpffffa9E8;
    u8 *base;
    u8 *state;
    u32 id;
    s32 index;
    s32 channel;
    s32 packed;
    s32 result;
    s32 high;
    s32 original;
    s16 *flags;
    s32 *entry;
    u8 *resource;
    u8 text[64];
    Result output;

    base = ((BtlShuffleRosterWork *)rosterWork)->context;
    state = rosterWork + 0x18;
    id = ((BtlShuffleRosterWork *)rosterWork)->rosterId;
    if (id == 1) {
        id = ((BtlShuffleRosterState *)state)->rosterId;
    }
    id &= 0xFF;
    index = id - 1;
    channel = index * 4 + 0x15;
    packed = (id << 16) | ((*(s32 *)(state + 0x10) != 0) ? 1 : 0);
    result = btlShuffleBuildRoster(packed, (s32 *)&output);
    high = ((u32)(result & 0xFFFF0000) >> 16) & 0xFFFF;
    if (high != 0) {
        original = ((u32)(packed & 0xFFFF0000) >> 16) & 0xFFFF;
        if (high != original) {
            ((BtlShuffleRosterState *)state)->result = result;
        }
    }
    if (output.active != 0) {
        flags = (s16 *)(D_0064EC30 + index * 2);
        if ((*flags & 1) != 0) {
            nmMesWindowSetCurrentString(0, datPersonaGetRow(output.value0));
        }
        if ((*flags & 2) != 0) {
            nmMesWindowSetCurrentString(1, datCalcGetIdRecord(output.value1));
            nmMesWindowSetCurrentString(4, datCalcGetIdRecord(output.value2));
        }
        if ((*flags & 4) != 0) {
            sprintf(text, &iGpffffa9E8, (s16)output.value2);
            nmMesWindowSetCurrentString(2, text);
        }
        if ((*flags & 8) != 0) {
            nmMesWindowSetCurrentString(3, datPersonaGetRow(output.value2));
        }
    } else {
        nmMesWindowShowCurrentRecord(channel + 3);
        return 1;
    }
    if (*(s32 *)(state + 0x10) != 0) {
        entry = D_0064EB80 + index * 2;
        resource = ((BtlShuffleContext *)base)->trailTask;
        btlShuffleEffInitTrail(resource, *entry);
        nmMesWindowShowCurrentRecord(channel + 1);
    } else {
        entry = D_0064EB84 + index * 2;
        resource = ((BtlShuffleContext *)base)->trailTask;
        btlShuffleEffInitTrail(resource, *entry);
        nmMesWindowShowCurrentRecord(channel + 2);
    }
    return 1;
}

/* Roll a 12-bit uniform sample against the flag- or stat-derived percent threshold. */
// FUN_00380BD0
s32 btlShuffleRollChance(u8 **rosterWork)
{
    extern u8 datPersonaGetTotalStatById(u16 partyId, s32 statIndex);
    extern s32 datCalcGetLevelById(s32 unitId);
    extern s32 datGetFlag(s32 bit);
    extern u32 RpRandom(void);
    extern u8 D_0064E760[];
    f32 percent;
    f32 rnd;
    u16 rawLevel;
    u16 clamped;
    s32 rollPercent;
    u8 threshold;
    if (((BtlShuffleContext *)*rosterWork)->unk1F30C != 0) {
        return 0;
    }
    rawLevel = datPersonaGetTotalStatById(1, 4) & 0xFF;
    datCalcGetLevelById(1);
    if (datGetFlag(0x1426) != 0) {
        threshold = 0x3C;
    } else if (datGetFlag(0x1427) != 0) {
        threshold = 0xA;
    } else {
        clamped = rawLevel & 0xFF;
        if (clamped == 0) {
            clamped = 1;
        } else if (clamped > 0x63) {
            clamped = 0x63;
        }
        threshold = D_0064E760[((clamped & 0xFF) - 1) / 10];
    }
    rnd = (f32)(u32)(RpRandom() & 0xFFF);
    percent = 100.0f * (rnd / 4096.0f);
    rollPercent = (u8)percent;
    return (rollPercent & 0xFF) < (threshold & 0xFF);
}

/* Reject duplicates, show the full-roster prompt, or add the reward persona. */
// FUN_00380D80
s32 btlShuffleAddRosterMember(u8 *rosterWork, s32 personaId)
{
    u16 count2;
    u16 count1;

    count1 = datPersonaCountValidMembers();
    count2 = datPersonaRosterCapacity();
    if (datPersonaFindRosterRecordById((u16)personaId) != 0) {
        nmMesWindowShowCurrentRecord(2);
        return 6;
    }
    if (count1 == count2) {
        memset(rosterWork + 0x18, 0, 0x7C);
        nmMesWindowSetCurrentString(0, datPersonaGetRow(personaId));
        nmMesWindowShowCurrentRecord(3);
        return 7;
    }
    datPersonaAddRosterMember((u16)personaId);
    nmMesWindowSetCurrentString(0, datPersonaGetRow(personaId));
    nmMesWindowShowCurrentRecord(1);
    return 5;
}
