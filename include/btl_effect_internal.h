#ifndef BTL_EFFECT_INTERNAL_H
#define BTL_EFFECT_INTERNAL_H

#include "type.h"

/* Allocated as 0x24 bytes by btlEffectAllocNodePool and CreatePlacementEntry.
 * Reset/release and fade update agree on the resource slots and list links. */
typedef struct BtlEffectNode {
    u16 flags;              /* 0x00: 0x200 active, 0x40 frozen, 0x80/0x100 fade in/out */
    u16 unk02;
    u32 color;              /* 0x04: packed RGBA, alpha in the high byte */
    u8 fadeStep;            /* 0x08: alpha change per update, initially 20 */
    u8 pad09[3];
    u32 counter;            /* 0x0C: wrapping update count */
    u8 *formation;          /* 0x10: released by btlFormationResetState */
    u8 *effect;             /* 0x14: released by mdlEffectDestroyWithNodes */
    u8 *model;              /* 0x18: released by mdlDestroyModelObject */
    struct BtlEffectNode *previous; /* 0x1C */
    struct BtlEffectNode *next;     /* 0x20 */
} BtlEffectNode;

/* The pool allocation is 0xC8 bytes, with 48 pointers and a used-bit word.
 * The retail loop shifts a 32-bit mask through all 48 slots; preserve that wrap. */
typedef struct BtlEffectNodePool {
    BtlEffectNode *nodes[48];
    u32 usedMask;           /* 0xC0 */
    u32 unkC4;
} BtlEffectNodePool;

/* Allocated as 0x18 bytes by btlEffectCreatePlacementEntry. */
typedef struct BtlEffectPlacement {
    u8 flags;              /* 0x00: bit 0 requests a refresh */
    u8 pad01[3];
    s32 unit;              /* 0x04 */
    BtlEffectNode *node;    /* 0x08 */
    u8 *formation;          /* 0x0C */
    s16 slotIndex;          /* 0x10: -1 hides the entry */
    u8 pad12[2];
    u32 color;             /* 0x14 */
} BtlEffectPlacement;

/* Work allocation of packet 0x302 (0x28 bytes). */
typedef struct BtlEffectFormationStep {
    u8 *formation;          /* 0x00 */
    u8 *unit;               /* 0x04 */
    s32 duration;           /* 0x08 */
    u8 pad0C[4];
    s64 key;                /* 0x10 */
    BtlEffectNode *node;    /* 0x18 */
    s32 elapsed;            /* 0x1C: advances by two */
    u32 flags;              /* 0x20 */
    u8 pad24[4];
} BtlEffectFormationStep;

/* Generic packet dispatcher prefix used by all packet constructors here.
 * Callback casts retain the existing declarations at each call site. */
typedef u32 (*BtlPacketFunc)(void *work);
typedef struct BtlPacket {
    u8 dependencyKind;      /* 0x00: 4 waits for dependencyUID */
    u8 pad01[7];
    u64 dependencyUID;      /* 0x08 */
    u8 pad10[0x37];
    u8 flags;               /* 0x47 */
    u8 pad48[0x10];
    u64 uid;                /* 0x58 */
    u64 actionUID;          /* 0x60 */
    BtlPacketFunc initFunc;  /* 0x68 */
    BtlPacketFunc updateFunc;/* 0x6C */
    BtlPacketFunc destroyFunc;/* 0x70 */
    u8 pad74[4];
    void *workData;         /* 0x78 */
} BtlPacket;

/* Target collectors clear twelve pointer slots; the UID occupies the next
 * eight bytes. The count, cursor and flags follow at 0x38/0x3A/0x3C. */
typedef struct BtlTargetSelection {
    u8 *entries[12];
    u64 key;                /* 0x30 */
    u16 count;              /* 0x38 */
    u16 selected;           /* 0x3A */
    u8 flags;               /* 0x3C */
} BtlTargetSelection;

/* Six-byte work of packet 0x30A, filled by btlEffectCreateMessagePacket. */
typedef struct BtlEffectFadeColor {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    u16 mode;
} BtlEffectFadeColor;

/* The setup copied by btlTaskCreate is 0x3C bytes (battle+0xC70).
 * Teardown releases the four party, three enemy and three paired unit slots. */
typedef struct BtlEncounterUnitSlot {
    s32 unit;
    u32 unk04;
} BtlEncounterUnitSlot;
typedef struct BtlEncounterSetup {
    u32 unk00;
    s32 partyUnits[4];             /* 0x04 */
    s32 enemyUnits[3];             /* 0x14 */
    u16 formation;                /* 0x20 */
    u16 formationVariant;         /* 0x22 */
    BtlEncounterUnitSlot units[3]; /* 0x24 */
} BtlEncounterSetup;

/* Embedded SDK primitive nodes begin at E18/E48. Their callback and work
 * slots agree with PrimQueueRectangle; only the fields used here are named. */
typedef struct BtlRenderNode {
    s32 unk00;
    s32 unk04;
    void *callback;               /* 0x08 */
    u8 pad0C[4];
    void *work;                   /* 0x10 */
    u8 pad14[0x1C];
} BtlRenderNode;

/* btlInit allocates and clears 0xE88 bytes. All gaps retain their retail
 * offsets; the lifecycle, action and effect paths share this allocation. */
typedef struct BtlBattleState {
    u8 pad00[0x0C];
    u32 flags;                     /* 0x0C */
    u32 battleFlags;               /* 0x10 */
    u32 resourceFlags;             /* 0x14 */
    u8 pad18[2];
    u16 openingSide;               /* 0x1A */
    s16 endState;                 /* 0x1C: 1 victory, 2 defeat, 3 no party */
    u8 pad1E[2];
    s32 protagonistTurns;         /* 0x20 */
    u8 pad24[0x170 - 0x24];
    u8 *selectedAction;            /* 0x170 */
    u8 *actions;                   /* 0x174 */
    u8 *unitLists[8];              /* 0x178: head/tail pairs */
    u8 pad198[0x1B8 - 0x198];
    BtlEffectNode *effectNodes;    /* 0x1B8 */
    u8 pad1BC[0x26C - 0x1BC];
    u16 formation;                /* 0x26C */
    u16 formationVariant;         /* 0x26E */
    u8 pad270[0xA70 - 0x270];
    s16 unkA70;
    s16 unkA72;
    u8 padA74[0xB4C - 0xA74];
    u32 cutinFlags;                /* 0xB4C */
    u16 cutinKind;                 /* 0xB50 */
    u8 padB52[2];
    u8 *cutinEffect;               /* 0xB54 */
    u8 *cutinHandle;               /* 0xB58 */
    u8 *cutinEffects[4];           /* 0xB5C */
    u8 *cutinHandles[4];           /* 0xB6C */
    u16 cutinNameKind;             /* 0xB7C */
    u8 padB7E[6];
    u8 *cutinNameHandle;           /* 0xB84 */
    s32 cutinNameTask;             /* 0xB88 */
    u8 padB8C[0xC60 - 0xB8C];
    s32 messageWindow;            /* 0xC60 */
    u8 unkC64;
    s8 isFieldEncounter;          /* 0xC65: no explicit setup passed */
    u8 padC66[0xC70 - 0xC66];
    BtlEncounterSetup encounter;  /* 0xC70 */
    u8 padCAC[0xD04 - 0xCAC];
    u8 *formations[48];           /* 0xD04 */
    u8 *formationHandle;           /* 0xDC4 */
    s32 cutinTaskParent;           /* 0xDC8: owning battle task */
    u8 padDCC[8];
    s32 uiTask;                   /* 0xDD4 */
    u8 padDD8[0xE18 - 0xDD8];
    BtlRenderNode renderStateNode;/* 0xE18 */
    BtlRenderNode skyNode;        /* 0xE48 */
    s32 skyActive;               /* 0xE78 */
    u8 *sky;                     /* 0xE7C */
    f32 skyScroll;               /* 0xE80 */
    u8 padE84[4];
} BtlBattleState;

#endif
