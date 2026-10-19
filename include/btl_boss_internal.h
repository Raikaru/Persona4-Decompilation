#ifndef BTL_BOSS_INTERNAL_H
#define BTL_BOSS_INTERNAL_H

#include "type.h"

/* Battle-state boss work at +0xB98. Setup/teardown and the status-window
 * cache establish these offsets; formation cleanup visits eight slots. */
typedef struct BtlBossWork {
    u8 *recordTable;                /* battle +0xB98 */
    u8 pad04[4];
    u8 *statusTask;                 /* +0xBA0 */
    u16 statusSlot;                 /* +0xBA4 */
    u8 pad0E[2];
    s32 displayedIds[5];            /* +0xBA8 */
    s32 displayedStates[5];         /* +0xBBC */
    u8 pad38[0x10];
    s32 formations[8];              /* +0xBE0 */
    u16 unk68;                     /* +0xC00: camera aim gate compares this with 1 */
    u8 pad6A[2];
    s32 cameraActionId;            /* +0xC04: last action id processed by FrameActionCutscene */
    s32 cameraGeometryActive;      /* +0xC08: cached action-geometry state */
    u8 pad74[4];
} BtlBossWork;
typedef char BtlBossWorkSizeCheck[sizeof(BtlBossWork) == 0x78 ? 1 : -1];

/* Packet 0xE01 allocates exactly eight bytes and initializes both words. */
typedef struct BtlBossEndBgmLoad {
    s32 id;
    s32 state;
} BtlBossEndBgmLoad;

#endif
