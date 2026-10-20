#ifndef BTL_HUD_INTERNAL_H
#define BTL_HUD_INTERNAL_H

#include "type.h"
#include "btl_unit_internal.h"
#include "btl_action_internal.h"

/* EntryInit clears a 0x20-byte record, then sets owner and reference count. */
typedef struct BtlEntryRecord {
    u8 pad00[4];
    s32 owner;
    u8 pad08[8];
    s32 references;
    u8 pad14[0xC];
} BtlEntryRecord;

/* Damage list readers establish the 0x28-byte node and its linked-list tail. */
typedef struct BtlDamageEntry {
    u8 *unit;
    f32 position[3];
    s32 age;
    u16 flags;
    u8 pad16[2];
    s32 hpAmount;
    s32 spAmount;
    u16 drawFlags;
    u8 pad22[2];
    u8 *next;
} BtlDamageEntry;

typedef struct BtlDamageState {
    u8 *head;
    void *task;
    u16 flags;
    u16 fadeFrame;
    u8 pad0C[2];
    u16 flashFrame;
    s32 source;
    u16 trailFrame;
    u16 trailFlags;
    u8 trailAlpha[4];
} BtlDamageState;

/* BuildTrail initializes nine halfword alphas; DrawGaugeBar consumes them.
 * The caller reserves 0x20 bytes, retaining its existing stack allocation. */
typedef struct BtlDamageTrail {
    f32 scale;
    s32 count;
    u16 alpha[9];
    u8 pad1A[6];
} BtlDamageTrail;


typedef struct BtlEncounterEntry {
    s32 flags;
    s16 messageFrame;
    u8 pad06[2];
    u8 *selectedUnit;
    s32 task;
} BtlEncounterEntry;

/* InitRecord clears 0x40 bytes. Timed-message rendering and its setters
 * establish all fields below; integer handles preserve the existing ABI. */
typedef struct BtlMessagePanel {
    s32 fontList;
    s32 duration;
    s32 elapsed;
    s32 textWidth;
    u16 flags;
    u16 mode;
    u16 state;
    u16 fadeFrame;
    s32 window;
    s32 record;
    s32 unit;
    s32 text;
    s16 result;
    s16 inputDelay;
    s32 choiceWindow;
    s32 choiceRecord;
    s32 choiceFrame;
    s32 choiceStarted;
    void *task;
} BtlMessagePanel;

typedef struct BtlMessageState {
    u16 flags;
    s16 state;
    s16 frame;
    u8 pad06[2];
    s32 value;
} BtlMessageState;

/* Offsets are shared by the task accessors in the owning HUD translation
 * unit. Unknown gaps are intentionally not assigned game semantics. */
typedef struct BtlHudWork {
    u32 flags;
    u8 pad04[0x94];
    s32 messageWindow;
    u8 pad9C[0x6C0];
    BtlDamageState damage;
    void *encounterTask;
    u8 pad77C[0x90];
    BtlEncounterEntry encounter;
    u8 pad81C[0x30];
    BtlMessagePanel message;
    u8 pad88C[0x34];
    BtlMessageState messageState;
} BtlHudWork;

/* Encounter transition constructor allocates exactly 0x48 bytes. */
typedef struct BtlEncounterWork {
    s16 state;
    u8 pad02[2];
    s32 sprite;
    u8 drawNode[0x30];
    s32 animationFrame;
    s32 rotationFrame;
    s32 ready;
    s32 finish;
} BtlEncounterWork;

/* Five RGBA groups followed by the status selector; consumed by PortraitDraw. */
typedef struct BtlStatusIcon {
    u8 colors[5][4];
    s32 status;
} BtlStatusIcon;

typedef char BtlDamageStateSizeCheck[sizeof(BtlDamageState) == 0x1C ? 1 : -1];
typedef char BtlMessagePanelSizeCheck[sizeof(BtlMessagePanel) == 0x40 ? 1 : -1];
typedef char BtlEncounterWorkSizeCheck[sizeof(BtlEncounterWork) == 0x48 ? 1 : -1];

#endif
