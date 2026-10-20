/* Whole-file translation unit: src/Camp/cmpSystem.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"

extern char D_005E57F0[];
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern u8 D_0064A790[];
extern u8 D_0064D460[];
extern u8 D_0064D6B0[];
extern u8 D_0064D900[];
extern u8 D_0064DB50[];
extern u8 D_0064DDA0[];
extern u8 D_0064DFF0[];
extern u8 D_0064E240[];
extern char D_0064E270[];

s8 nmMesWindowAcquire(void *);
s32 datCommunityDefaultSetting(void);
void memset(void *, s32, s32);
void *resourceFindByName(char *);
s32 sdkSpriteNewNode(void *, u8);
void kAssertFail(char *, s32);
s32 cmpSystemSetMode(u8 *, u32);

/* Layout established by the initializer's 0x708-byte clear and the 0x30/0x14/0xA strides.
 * Integer coordinate stores retain their exact bit representation. */
typedef union { f32 value; s32 bits; } CmpSystemCoordinate;
typedef struct {
    CmpSystemCoordinate startX, startY, targetX, targetY, x, y;
    u8 startAlpha, targetAlpha, alpha, unk1B;
    u16 startWidth, targetWidth, width, startHeight, targetHeight, height;
    s32 startFrame, endFrame;
} CmpSystemMotion;
typedef struct {
    f32 x, y;
    u8 alpha;
    u8 pad09[3];
    s32 startFrame, endFrame;
} CmpSystemLayoutRow;
typedef struct {
    s16 target, current, unk04, filled, unk08;
} CmpSystemGraphBar;
typedef struct {
    u8 alpha;
    u8 pad01[3];
    s32 originX, originY;
    u8 pad0C[8];
    s32 phase;
    union { s32 signedValue; u32 value; } mode;
    s32 visible;
    s16 frame, graphFrame, graphFrame2;
    u8 pad26[2];
    s16 selection[3], previousSelection[3];
    s16 footerMode;
    u8 pad36[2];
    s32 unk38;
    u8 messageWindow;
    u8 pad3D[3];
    f32 graphX;
    s32 graphY;
    CmpSystemMotion motion[29];
    CmpSystemMotion tabMotion;
    CmpSystemGraphBar graph[11];
    u8 pad656[2];
    s32 sprites[42];
    s32 footerTexture;
    u8 pad704[4];
} CmpSystemWork;
typedef char CmpSystemWorkSize[sizeof(CmpSystemWork) == 0x708 ? 1 : -1];

// FUN_0035F5B0
/* Initialize the 0x708-byte system menu, its 29 motion records, sprites and message window. */
/* measured: removing this regresses func_0035f5b0 from nd 0 to nd 118
   (loop-invariant hoisting of the D_0064D6B0 base and the store-constant
   3 is required for the retail layout). */
#pragma opt_loop_invariants on
void cmpSystemMenuInit(u8 *work)
{
    void *itemResource;
    void *menuResource;
    void *footerResource;
    void *extraResource;
    s32 *slot;
    s16 spriteIndex;
    s16 selectionIndex;
    s16 tabIndex;
    s16 motionIndex;
    s16 barIndex;
    u8 spriteId;
    u8 *p;
    u8 *src;

    memset(work, 0, 0x708);
    ((CmpSystemWork *)work)->originX = 0;
    ((CmpSystemWork *)work)->originY = 0;
    ((CmpSystemWork *)work)->alpha = 0xFF;
    ((CmpSystemWork *)work)->mode.signedValue = -1;
    ((CmpSystemWork *)work)->phase = 0;
    for (selectionIndex = 0; selectionIndex < 3; selectionIndex++) {
        ((CmpSystemWork *)work)->selection[selectionIndex] = 0;
    }
    ((CmpSystemWork *)work)->graphX = 0x12F;
    ((CmpSystemWork *)work)->graphY = 0x43050000;
    for (motionIndex = 0; motionIndex < 0x1D; motionIndex++) {
        src = &D_0064D6B0[motionIndex * 0x14];
        p = work + motionIndex * 0x30;
        ((CmpSystemWork *)p)->motion[0].x.value = ((CmpSystemLayoutRow *)src)->x;
        ((CmpSystemWork *)p)->motion[0].y.value = ((CmpSystemLayoutRow *)src)->y;
        ((CmpSystemWork *)p)->motion[0].alpha = ((CmpSystemLayoutRow *)src)->alpha;
    }
    for (tabIndex = 0; tabIndex <= 0; tabIndex++) {
        p = work + (s32)(s64)tabIndex * 0x30;
        ((CmpSystemWork *)p)->tabMotion.x.bits = 0;
        ((CmpSystemWork *)p)->tabMotion.startX.bits = 0;
        ((CmpSystemWork *)p)->tabMotion.targetY.bits = 0;
        ((CmpSystemWork *)p)->tabMotion.startY.bits = 0;
        ((CmpSystemWork *)p)->tabMotion.targetAlpha = 0;
        ((CmpSystemWork *)p)->tabMotion.startAlpha = 0;
        ((CmpSystemWork *)p)->tabMotion.startFrame = 0;
        ((CmpSystemWork *)p)->tabMotion.endFrame = 3;
    }
    itemResource = resourceFindByName(D_005E5830);
    if (itemResource == NULL) {
        kAssertFail(D_0064E270, 0x15B);
    }
    menuResource = resourceFindByName(D_005E5850);
    if (menuResource == NULL) {
        kAssertFail(D_0064E270, 0x15D);
    }
    ((CmpSystemWork *)work)->footerTexture = (s32)(footerResource = resourceFindByName(D_005E57F0));
    if (footerResource == NULL) {
        kAssertFail(D_0064E270, 0x15F);
    }
    extraResource = resourceFindByName(D_005E5810);
    if (extraResource == NULL) {
        kAssertFail(D_0064E270, 0x161);
    }
    for (spriteIndex = 0; spriteIndex < 0x2A; spriteIndex++) {
        if (spriteIndex < 0x25) {
            slot = &((CmpSystemWork *)work)->sprites[spriteIndex];
            spriteId = D_0064E240[spriteIndex];
            *slot = sdkSpriteNewNode(menuResource, spriteId);
        } else if (spriteIndex < 0x28) {
            slot = &((CmpSystemWork *)work)->sprites[spriteIndex];
            spriteId = D_0064E240[spriteIndex];
            *slot = sdkSpriteNewNode(itemResource, spriteId);
        } else if (spriteIndex < 0x29) {
            slot = &((CmpSystemWork *)work)->sprites[spriteIndex];
            spriteId = D_0064E240[spriteIndex];
            *slot = sdkSpriteNewNode(footerResource, spriteId);
        } else {
            slot = &((CmpSystemWork *)work)->sprites[spriteIndex];
            spriteId = D_0064E240[spriteIndex];
            *slot = sdkSpriteNewNode(extraResource, spriteId);
        }
        if (*slot == 0) {
            kAssertFail(D_0064E270, 0x171);
        }
    }
    ((CmpSystemWork *)work)->messageWindow = nmMesWindowAcquire(&D_0064A790[0]);
    for (barIndex = 0; barIndex < 0xB; barIndex++) {
        p = work + (s32)(s64)barIndex * 0xA;
        ((CmpSystemWork *)p)->graph[0].target = 1;
        ((CmpSystemWork *)p)->graph[0].filled = 1;
    }
    ((CmpSystemWork *)work)->graphFrame = 0;
    ((CmpSystemWork *)work)->graphFrame2 = 0;
    ((CmpSystemWork *)work)->unk38 = datCommunityDefaultSetting();
    cmpSystemSetMode(work, 0);
}
/* measured: see the annotation above the matching `on` pragma (func_0035f5b0). */
#pragma opt_loop_invariants off

/* Save the previous selection before changing one of the three cursor slots. */
// FUN_0035FA00
s32 cmpSystemSetSelection(s32 work, s32 mode, s16 selection)
{
    u8 *selectionBase;
    s32 selectionOffset;

    selectionOffset = mode * 2;
    selectionBase = (u8 *)(selectionOffset + work);
    ((CmpSystemWork *)selectionBase)->previousSelection[0] = ((CmpSystemWork *)selectionBase)->selection[0];
    ((CmpSystemWork *)selectionBase)->selection[0] = selection;
    return 1;
}

/* Snapshot all current row positions and load the chosen system-menu transition table.
 * measured: access-site-only CmpSystemWork typing
 * changed 362 instruction bytes; a typed root local retains all 544 retail bytes. */
// FUN_0035FA20
s32 cmpSystemSetMode(u8 *work, u32 mode)
{
    CmpSystemWork *menu = (CmpSystemWork *)work;
    u8 *layoutTable;
    s32 rowIndex;
    s32 targetIndex;
    u8 *rowBase;
    u8 *layoutRow;

    layoutTable = NULL;
    if (menu->mode.value == mode) {
        return 0;
    }
    for (rowIndex = 0; rowIndex < 0x1D; rowIndex++) {
        rowBase = work + rowIndex * 0x30;
        ((CmpSystemWork *)(rowBase))->motion[0].startX.value = ((CmpSystemWork *)(rowBase))->motion[0].x.value;
        ((CmpSystemWork *)(rowBase))->motion[0].startY.value = ((CmpSystemWork *)(rowBase))->motion[0].y.value;
        ((CmpSystemWork *)(rowBase))->motion[0].startAlpha = ((CmpSystemWork *)(rowBase))->motion[0].alpha;
    }
    switch (mode) {
    case 0:
        layoutTable = &D_0064D460[0];
        menu->visible = 3;
        menu->footerMode = 0;
        break;
    case 1:
        layoutTable = &D_0064D6B0[0];
        menu->visible = 3;
        menu->footerMode = 0;
        break;
    case 2:
        layoutTable = &D_0064D900[0];
        menu->visible = 3;
        menu->footerMode = 0;
        break;
    case 3:
        layoutTable = &D_0064DB50[0];
        menu->visible = 0xC;
        menu->footerMode = 0xF;
        memset(work + 0x5E8, 0, 0x6E);
        break;
    case 4:
        layoutTable = &D_0064DDA0[0];
        menu->visible = 0xC;
        menu->footerMode = 0xF;
        break;
    case 5:
        layoutTable = &D_0064DFF0[0];
        menu->visible = 0xC;
        menu->footerMode = 0xF;
        break;
    default:
        kAssertFail(D_0064E270, 0x1CF);
        break;
    }
    if (layoutTable != NULL) {
        for (targetIndex = 0; targetIndex < 0x1D; targetIndex++) {
            layoutRow = layoutTable + targetIndex * 0x14;
            rowBase = work + targetIndex * 0x30;
            ((CmpSystemWork *)(rowBase))->motion[0].targetX.value = ((CmpSystemLayoutRow *)(layoutRow))->x;
            ((CmpSystemWork *)(rowBase))->motion[0].targetY.value = ((CmpSystemLayoutRow *)(layoutRow))->y;
            ((CmpSystemWork *)(rowBase))->motion[0].targetAlpha = ((CmpSystemLayoutRow *)(layoutRow))->alpha;
            ((CmpSystemWork *)(rowBase))->motion[0].startFrame = ((CmpSystemLayoutRow *)(layoutRow))->startFrame;
            ((CmpSystemWork *)(rowBase))->motion[0].endFrame = ((CmpSystemLayoutRow *)(layoutRow))->endFrame;
        }
        menu->mode.value = mode;
        menu->frame = 0;
    }
    return 1;
}
