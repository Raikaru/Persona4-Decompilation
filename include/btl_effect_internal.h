#ifndef BTL_EFFECT_INTERNAL_H
#define BTL_EFFECT_INTERNAL_H

#include "type.h"
#include "btl_boss_internal.h"
#include "btl_camera_internal.h"
#include "btl_camera_sequence_internal.h"

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

/* Four 0x10-byte dependency records precede the packet kind. The discriminator
 * selects a UID, elapsed-frame threshold, or halfword packet id at +0x08. */
typedef struct BtlPacketCondition {
    u8 kind;
    u8 pad01[7];
    union {
        u64 uid;
        s32 frame;
        u16 id;
    } value;
} BtlPacketCondition;

/* Three four-byte reward rows at battle + 0xCD0. Defeat accounting first
 * increments an existing id, then fills the first empty row. */
typedef struct BtlRewardEntry {
    u16 id;
    s16 count;
} BtlRewardEntry;

/* Generic packet dispatcher prefix used by all packet constructors here.
 * Callback casts retain the existing declarations at each call site. */
typedef u32 (*BtlPacketFunc)(void *work);
typedef struct BtlPacket {
    u8 dependencyKind;      /* 0x00: 4 waits for dependencyUID */
    u8 pad01[7];
    u64 dependencyUID;      /* 0x08 */
    u8 dependencyKind2;     /* 0x10: second dispatcher condition */
    u8 pad11[7];
    u64 dependencyUID2;     /* 0x18 */
    u8 dependencyKind3;     /* 0x20: third dispatcher condition */
    u8 pad21[7];
    u64 dependencyUID3;     /* 0x28 */
    u8 dependencyKind4;     /* 0x30: second end condition */
    u8 pad31[7];
    u64 dependencyUID4;     /* 0x38 */
    s32 type;               /* 0x40: btlPacketAlloc's packet kind */
    u8 listIndex;           /* 0x44 */
    u8 phase;               /* 0x45: condition/delay/update/end-condition/duration */
    u8 paused;              /* 0x46 */
    u8 flags;               /* 0x47 */
    u16 delay;              /* 0x48: frames before dispatch */
    u16 duration;           /* 0x4A: packet-specific frame interval */
    s32 elapsed;            /* 0x4C: wrapping frame count since enqueue */
    u32 updateFrames;       /* 0x50: frames spent waiting for updateFunc */
    u8 pad54[4];
    u64 uid;                /* 0x58 */
    u64 actionUID;          /* 0x60 */
    BtlPacketFunc initFunc;  /* 0x68 */
    BtlPacketFunc updateFunc;/* 0x6C */
    BtlPacketFunc destroyFunc;/* 0x70 */
    s32 (*conditionFunc)(u8 *work); /* 0x74: optional dependency query */
    void *workData;         /* 0x78 */
    u8 *previous;           /* 0x7C: preceding packet in the list */
} BtlPacket;
/* The public dispatcher prefix stays 0x80 bytes; allocation/list code also
 * accesses a trailing next link at +0x80 in the full 0x90-byte header. */
typedef char BtlPacketConditionSizeCheck[sizeof(BtlPacketCondition) == 0x10 ? 1 : -1];
typedef char BtlPacketWorkOffsetCheck[(u32)&((BtlPacket *)0)->workData == 0x78 ? 1 : -1];
typedef char BtlPacketPreviousOffsetCheck[(u32)&((BtlPacket *)0)->previous == 0x7C ? 1 : -1];
typedef char BtlPacketPrefixSizeCheck[sizeof(BtlPacket) == 0x80 ? 1 : -1];


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

/* Three colors/quaternions form the scene blocks saved by camera setup. */
typedef struct BtlSceneColor { f32 x, y, z, w; } BtlSceneColor;
typedef struct BtlSceneColorBlock {
    BtlSceneColor first;
    BtlSceneColor second;
    BtlCameraQuaternion rotation;
} BtlSceneColorBlock;

/* btlInit allocates and clears 0xE88 bytes. All gaps retain their retail
 * offsets; the lifecycle, action and effect paths share this allocation. */
typedef struct BtlBattleState {
    u8 pad00[0x0C];
    u32 flags;                     /* 0x0C */
    u32 battleFlags;               /* 0x10 */
    u32 resourceFlags;             /* 0x14 */
    u16 actionEndFlags;           /* 0x18: end-action camera/formation requests */
    u16 openingSide;               /* 0x1A */
    s16 endState;                 /* 0x1C: 1 victory, 2 defeat, 3 no party */
    u8 pad1E[2];
    s32 protagonistTurns;         /* 0x20 */
    BtlCamera camera;              /* 0x24..0x16F */
    u8 *selectedAction;            /* 0x170 */
    u8 *actions;                   /* 0x174 */
    u8 *unitLists[8];              /* 0x178: head/tail pairs */
    u8 pad198[0x1B8 - 0x198];
    BtlEffectNode *effectNodes;    /* 0x1B8 */
    BtlSceneColorBlock scene;       /* 0x1BC */
    BtlSceneColorBlock list4;       /* 0x1EC */
    BtlSceneColorBlock savedList4;  /* 0x21C */
    BtlSceneColor colorFactors;    /* 0x24C */
    BtlSceneColor skyColor;        /* 0x25C */
    u16 formation;                /* 0x26C */
    u16 formationVariant;         /* 0x26E */
    BtlSceneColor savedLightA;     /* 0x270 */
    BtlSceneColor savedLightC;     /* 0x280 */
    u16 queueFlags;               /* 0x290: enable, reorder and advance bits */
    u8 pad292[2];
    s32 actionCount;              /* 0x294: dispatched actions this round */
    s32 unk298;
    s32 actionQueue[12];          /* 0x29C: action pointers in execution order */
    s32 activeActions[12];        /* 0x2CC: pending follow-up actions */
    BtlCameraSequenceWork phase;  /* 0x2FC */
    u8 pad318[0xA70 - 0x318];
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
    u8 padB8C[4];
    u32 bossPakHandle;            /* 0xB90: boss resource directory */
    u32 bossEndBgmHandle;         /* 0xB94: end-BGM resource directory */
    BtlBossWork boss;             /* 0xB98 */
    s8 bossCuePrefix[2];          /* 0xC10: signed formation-slot overrides */
    s8 pendingBossCue;            /* 0xC12: reset to -1 for selected bosses */
    s8 bossCueTail[0x1B];         /* 0xC13..0xC2D */
    u8 padC2E[2];
    u8 *bossSlotTable;            /* 0xC30 */
    s16 bossPhase;                /* 0xC34 */
    u8 padC36[2];
    s32 bossMotionCountdown;      /* 0xC38 */
    s32 bossCameraCountdown;      /* 0xC3C */
    s32 bossRecordVariant;        /* 0xC40 */
    s32 unkC44;
    u8 *partyActions[4];          /* 0xC48 */
    u16 partyActionCount;         /* 0xC58 */
    u16 unkC5A;
    u8 padC5C[4];
    s32 messageWindow;            /* 0xC60 */
    u8 unkC64;
    s8 isFieldEncounter;          /* 0xC65: no explicit setup passed */
    u8 padC66[2];
    s32 encounterRecord;          /* 0xC68 */
    u16 encounterIndex;           /* 0xC6C: next encounter slot */
    u8 padC6E[2];
    BtlEncounterSetup encounter;  /* 0xC70 */
    u16 resultFlags;              /* 0xCAC: shuffle eligibility and result mode */
    u8 padCAE[0xCB8 - 0xCAE];
    s32 resultEncounterId;        /* 0xCB8 */
    u16 unkCBC;
    u16 survivingPartyIds[4];     /* 0xCBE: populated from party tail at +0x17C */
    u8 padCC6[2];
    s32 survivingPartyCount;      /* 0xCC8 */
    s32 partyUnitCount;           /* 0xCCC */
    s16 unkCD0;
    u16 unkCD2;
    u8 padCD4[8];
    u32 unkCDC;
    s16 unkCE0;
    u8 padCE2[2];
    s32 unkCE4;
    s32 unkCE8;
    u8 padCEC[0xD04 - 0xCEC];
    u8 *formations[48];           /* 0xD04 */
    u8 *formationHandle;           /* 0xDC4 */
    s32 cutinTaskParent;           /* 0xDC8: owning battle task */
    s32 mcIconTask;               /* 0xDCC */
    s32 shuffleTask;              /* 0xDD0: result/shuffle task */
    s32 uiTask;                   /* 0xDD4 */
    u8 padDD8[0xE18 - 0xDD8];
    BtlRenderNode renderStateNode;/* 0xE18 */
    BtlRenderNode skyNode;        /* 0xE48 */
    s32 skyActive;               /* 0xE78 */
    u8 *sky;                     /* 0xE7C */
    f32 skyScroll;               /* 0xE80 */
    u8 padE84[4];
} BtlBattleState;
/* The embedded work must not move any of the established battle fields. */
typedef char BtlBattleBossOffsetCheck[
    (u32)&((BtlBattleState *)0)->boss == 0xB98 ? 1 : -1];
typedef char BtlBattleBossCueOffsetCheck[
    (u32)&((BtlBattleState *)0)->pendingBossCue == 0xC12 ? 1 : -1];
typedef char BtlBattleCameraOffsetCheck[
    (u32)&((BtlBattleState *)0)->camera == 0x24 ? 1 : -1];
typedef char BtlBattleStateSizeCheck[sizeof(BtlBattleState) == 0xE88 ? 1 : -1];

#endif
