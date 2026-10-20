#ifndef BTL_UI_TASK_INTERNAL_H
#define BTL_UI_TASK_INTERNAL_H

#include "type.h"
#include "btl_effect_internal.h"
#include "btl_unit_internal.h"

/* btlUiCreateTask clears 0xA20 bytes. Component initializers and draw-node
 * registration agree on the boundaries below; opaque component bytes are not
 * interpreted here. The leading sprite state is shared by the draw helpers. */
typedef struct BtlUiSprite {
    u8 pad00[4];
    s32 originX;                 /* 0x04 */
    s32 originY;                 /* 0x08 */
    s32 width;                   /* 0x0C */
    s32 height;                  /* 0x10 */
    f32 factorX;                 /* 0x14 */
    f32 factorY;                 /* 0x18 */
    f32 scaleX;                  /* 0x1C */
    f32 scaleY;                  /* 0x20 */
    f32 tileOffsetX;             /* 0x24 */
    f32 tileOffsetY;             /* 0x28 */
    s32 sprites[12];             /* 0x2C */
    u8 pad5C[0x10];
    s32 sprite;                  /* 0x6C: sdkSpriteDraw payload */
    s32 segment;                 /* 0x70 */
    f32 x;                       /* 0x74 */
    f32 y;                       /* 0x78 */
    u8 unk7C;
    u8 fade;                     /* 0x7D: inverse opacity */
    u8 pad7E[6];
    f32 tileFactor;              /* 0x84 */
    s16 tileX;                   /* 0x88 */
    s16 tileY;                   /* 0x8A */
    u16 fixedScaleX;             /* 0x8C: 12 fractional bits; zero means unity */
    u16 fixedScaleY;             /* 0x8E */
    f32 alpha;                   /* 0x90 */
    u8 red;                      /* 0x94 */
    u8 green;
    u8 blue;
    u8 pad97;
} BtlUiSprite;

typedef struct BtlUiTaskWork {
    BtlUiSprite sprite;
    s32 messageWindow;           /* 0x98 */
    u8 panel[0x650 - 0x9C];
    BtlRenderNode frameNode;      /* 0x650 */
    BtlRenderNode backdropNode;   /* 0x680 */
    BtlRenderNode detailNode;     /* 0x6B0 */
    BtlRenderNode skyFrameNode;   /* 0x6E0 */
    u8 selection[0x1C];           /* 0x710 */
    BtlRenderNode selectionNode;  /* 0x72C */
    u8 damage[0x20];             /* 0x75C */
    BtlRenderNode damageNode;     /* 0x77C */
    BtlRenderNode badStatusNode;  /* 0x7AC */
    BtlRenderNode barsNode;       /* 0x7DC */
    u8 encounter[0x10];          /* 0x80C */
    BtlRenderNode portraitNode;   /* 0x81C */
    u8 message[0x40];            /* 0x84C */
    BtlRenderNode messageNode;    /* 0x88C */
    u8 pad8BC[4];
    u8 models[0x90];             /* 0x8C0 */
    BtlRenderNode animateNode;    /* 0x950 */
    BtlRenderNode flourishNode;   /* 0x980 */
    u8 gauge[4];                 /* 0x9B0 */
    BtlRenderNode gaugeNode;      /* 0x9B4 */
    u8 advantage[0x0C];          /* 0x9E4 */
    BtlRenderNode advantageNode;  /* 0x9F0 */
} BtlUiTaskWork;

/* Work of the 0x50A packet: the constructor copies the 0x20-byte result
 * verbatim, and its callbacks interpret the first five result words. */
typedef struct BtlHitDisplayWork {
    s32 source;                  /* 0x00: BtlUnit pointer in the retail ABI */
    s32 target;                  /* 0x04: BtlUnit pointer */
    s32 value0;
    s32 value1;
    s32 status;
    s32 value3;
    s32 value4;
    u8 pad1C[0x0C];
    s32 skill;                   /* 0x28 */
    u16 effect;
    u16 targetFlags;
    u16 hitIndex;
    u16 hitCount;
    s32 useHudAnchor;            /* 0x34 */
    u16 flags;
    u8 pad3A[2];
} BtlHitDisplayWork;

/* Sprite/message callbacks share an elapsed word at +8. The selector is
 * read as a word, halfword or signed item id by the respective callback. */
typedef struct BtlPanelPacketWork {
    s32 unit;
    union { u32 value; u16 index; s16 item; } selector;
    u32 elapsed;
} BtlPanelPacketWork;

typedef struct BtlHpRatioWork {
    u8 *unit;
    u8 mode;
    u8 pad05;
    s16 delta;
} BtlHpRatioWork;

/* btlUiAdjustTileOffset indexes resource segments at a 0x80-byte stride.
 * Attachment translation reads the XY words before the tile-offset words. */
typedef struct SdkSpriteSegment {
    u8 pad00[0x44];
    s32 offsetX, offsetY;
    u8 pad4C[8];
    s32 originalTileOffset;
    u8 pad58[4];
    s32 tileOffset;
    u8 pad60[0x20];
} SdkSpriteSegment;

typedef struct SdkSpriteResource {
    u8 pad00[0x204];
    u8 *segments;
} SdkSpriteResource;

typedef char BtlUiTaskWorkSizeCheck[sizeof(BtlUiTaskWork) == 0xA20 ? 1 : -1];
typedef char BtlHitDisplayWorkSizeCheck[sizeof(BtlHitDisplayWork) == 0x3C ? 1 : -1];

#endif
