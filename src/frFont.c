#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "fr_font_objects.h"
#include "h_cdvd.h"

extern void frFontSlotLoad(s32 value, u8 *otherValue, u8 *thirdValue);

typedef int (*code)();
extern u32 DAT_00881630_abs[];
extern code DAT_008873ec_abs[];
extern u32 DAT_00881750_abs[];
extern u32 DAT_00881754_abs[];
extern u32 DAT_00881758_abs[];
extern u32 DAT_0088175c_abs[];
extern u8 DAT_00881760_abs[];

extern s16 D_00763810;

extern void frFontDrawListMode(void *value, u32 otherValue);

extern u32 D_00764598;

extern u32 D_007637F8;
extern u32 D_00764594;
extern s32 D_007645A0;
extern void kAssertFail(const void *file, u32 line);
extern char D_0063BAE8[];
extern void frFontRasterEvictExpired(void);
extern u32 DAT_00881528_abs[];
extern u32 DAT_0088152C_abs[];
extern u32 DAT_0088179C_abs[];
extern u32 frFontListRelease(int value);
extern u32 frFontFadeNodes(int value);
extern void *memset(void *dst, s32 value, u32 size);
extern int sdkSndIsChannelPlaying(int value);
extern void nmMesWindowResetRecords(void);
extern int fclBankManagerCreate(void);
extern void fclMiscCreateAssistTask(void);
struct KwlnTask;
extern s32 fclBankManagerUpdate(u8 *task);
extern void frFontTaskDestroy(u8 *task);
extern void frFontInitManager(int value, int otherValue);
extern s8 frFontRunScript(void *value, int otherValue);
extern void frFontSetMode(u32 value);
extern u8 *frFontBuildText(void *data);
extern u8 *frFontBuildTextFull(u32 value, u32 otherValue, u32 thirdValue, u32 fourthValue,
                         u32 fifthValue, u32 sixthValue, u32 seventhValue, u32 eighthValue,
                         u32 ninthValue);
extern u32 D_00763840;
extern u32 D_00763848;
extern u32 D_00763838;
extern u32 DAT_008817A0_abs[];
extern u32 DAT_00881510_abs[];
extern u32 DAT_00881514_abs[];
extern u32 DAT_00881764_abs[];
extern u32 DAT_00881768_abs[];

void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern s8 D_007645B0;

extern u32 DAT_00881518_abs[];
extern u32 DAT_0088151C_abs[];
extern u32 DAT_00881520_abs[];
extern u32 DAT_00881524_abs[];

extern s32 D_007645BC;
extern s32 D_008815B0[];
extern s32 rbRingBufCreate();
extern void frFontRasterCreateCache();
extern void frFontLoadTables(void);

extern u32 DAT_0088176C_abs[];
extern u32 DAT_00881770_abs[];
extern u32 DAT_00881774_abs[];
extern u32 DAT_00881778_abs[];
extern u32 DAT_0088177C_abs[];

extern s32 D_00763830;
extern char D_0063BA00[];
extern char D_00748100[];
extern char D_00748110[];
extern s32 D_007645A4;
extern s32 D_007645A8;
extern u32 DAT_0088164C_abs[];
extern u32 DAT_00881650_abs[];
extern u32 DAT_00881670_abs[];
extern u32 DAT_00881690_abs[];
extern u32 DAT_008816B0_abs[];
extern u32 DAT_008816D0_abs[];
extern u32 DAT_008817B0_abs[];
extern char D_0063BB00[];
extern char D_0063BC10[];
extern s32 H_Cdvd_AcquireDirectory(const void *value, s32 otherValue);
extern void H_Cdvd_ReadSync(s32 value);
extern u8 *H_Cdvd_LookupRequest(void *value, void *otherValue);
extern void fmGslContFreeNode(int value);
extern void frFontRasterDestroyCache(void);
extern void frFontReleaseSlots(void);
extern void kAssertFailAt(const void *msg, const void *file, u32 line);
extern void func_00440b68();
extern char D_0063BBB0[];
extern char D_0063BBF0[];
extern char D_0063BB40[];
extern char D_0063BB80[];

  typedef struct GslListNode {
    int data[6];
    struct GslListNode *prev;
    struct GslListNode *next;
  } GslListNode;
typedef struct FrFontGlyph {
    u8 unknown_00[0xc];
    int advance;
    u8 unknown_10[0x18];
    struct FrFontGlyph *next;
} FrFontGlyph;

typedef struct FrFontNode {
    u8 unknown_00[3];
    s8 line_height;
    u8 unknown_04[0x18];
    FrFontGlyph *glyphs;
    u8 unknown_20[4];
    struct FrFontNode *next;
    u8 unknown_28[0x18];
    int enabled;
} FrFontNode;
typedef struct FrFontScript {
    u8 unknown_00[0x10];
    u8 *data;
    u8 unknown_14[4];
    s32 pos;
} FrFontScript;

typedef struct FrFontSlot4 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 object;
} FrFontSlot4;

typedef struct FrFontManagerData4 {
    FrFontSlot4 slots[9];
    u8 unknown_120[0x60];
    u32 *allocations[9];
} FrFontManagerData4;

extern FrFontManagerData4 gFrFontManagerData_abs[];

extern u32 DAT_00881634_abs[];

/* Glyph metrics are signed edge pairs. The cache provider allocates 0x21C
 * bytes per FrFontRasterEntry, whose +0x10 word holds the acquired raster. */
typedef struct FrFontGlyphMetrics { s8 left, right; } FrFontGlyphMetrics;
typedef struct FrFontRasterEntry {
    u8 pad00[0x10];
    u32 references;
    u8 pad14[0x208];
} FrFontRasterEntry;


/* Builds the slot grid: columns * rows nodes, each with its screen rectangle and optional aux buffer. */
/* measured: signed pool globals, preserved propagation boundaries and loop
   invariants reproduce bare-LUI hoisting without hoisting mutable loads.
   The existing 32-byte GslListNode layout gives all 860 executable bytes
   and 62 resolved relocations; the final retail word is alignment padding. */
// FUN_00270FB0
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
s32 frFontInitSlotGrid(s32 unused, s32 columns, s32 rows, s32 width, s32 height, s32 auxSize)
{
    u8 *aux = 0;
    u32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 index;
    GslListNode *node;
    void *(**alloc)(u32, u32);
    s32 scaledWidth, scaledHeight, rowY;
    void **tab;

    if ((*(s32 *)DAT_0088152C_abs) != 0 && D_007645B0 != 0)
        return 0;
    DAT_00881518_abs[0] = width;
    DAT_0088151C_abs[0] = height;
    DAT_00881520_abs[0] = width * height / 2;
    (*(s32 *)DAT_00881528_abs) = columns * rows;
    DAT_00881524_abs[0] = columns * rows;
    chkmemAllocSiteTag(D_0063BAE8, 0x18C);
    alloc = jtbl_008873E8;
    (*(s32 *)DAT_0088152C_abs) = DAT_00881510_abs[0] = (u32)alloc[0]((*(s32 *)DAT_00881528_abs) * 32, 0x40000);
    if ((*(s32 *)DAT_0088152C_abs) == 0)
        kAssertFail(D_0063BAE8, 0x18E);
    if (auxSize != 0) {
        chkmemAllocSiteTag(D_0063BAE8, 0x192);
        aux = (u8 *)(DAT_00881514_abs[0] = (u32)alloc[0](auxSize * (*(s32 *)DAT_00881528_abs), 0x40000));
        if (aux == 0)
            kAssertFail(D_0063BAE8, 0x194);
    }
    for (i = 0; i < (u32)((*(s32 *)DAT_00881528_abs) - 1); i++) {
        GslListNode *base = (GslListNode *)(*(s32 *)DAT_0088152C_abs);
        base[i].next = &base[i + 1];
    }
    node = (GslListNode *)(*(s32 *)DAT_0088152C_abs);
    (i + node)->next = node;
    for (j = (*(s32 *)DAT_00881528_abs) - 1; j > 0; j--) {
        GslListNode *base = (GslListNode *)(*(s32 *)DAT_0088152C_abs);
        base[j].prev = &base[j - 1];
    }
    ((GslListNode *)(*(s32 *)DAT_0088152C_abs))->prev = &((GslListNode *)(*(s32 *)DAT_0088152C_abs))[(*(s32 *)DAT_00881528_abs) - 1];
    index = 0;
    y = 0;
    scaledWidth = width * 16;
    scaledHeight = height * 16;
    for (; y < rows; y++) {
        x = 0;
        rowY = y * height * 16;
        for (; x < columns; x++) {
            node = &((GslListNode *)(*(s32 *)DAT_0088152C_abs))[index];
            if (node == 0) {
                if ((*(s32 *)DAT_0088152C_abs) != 0) {
                    tab = (void **)DAT_008873ec_abs;
                    ((code)tab[0])(DAT_00881510_abs[0]);
                    ((code)tab[0])(DAT_00881514_abs[0]);
                    (*(s32 *)DAT_0088152C_abs) = 0;
                }
                return 0;
            }
            node->data[0] = index;
            node->data[1] = x * width * 16;
            node->data[2] = rowY;
            node->data[3] = node->data[1] + scaledWidth;
            node->data[4] = node->data[2] + scaledHeight;
            if (aux != 0)
                node->data[5] = (u32)(aux + index * auxSize);
            else
                node->data[5] = 0;
            index++;
        }
    }
    D_007645B0 = 1;
    return 1;
}
#pragma pop
/* Inserts a node after the free-list head and returns the new count. */
// Ported from P3FES FUN_003b4580 (verified MATCH there). The prior nd11
// floor was the RETURN TYPE: retail leaves the incremented count live in $v0
// at the jr, so every void spelling coloured the whole global-load chain
// $v1/$a0 instead of retail's $v0/$v1. Returning s32 count fixes it. The
// caller in this file passes a u8* node, so the param is u8* (not the donor's
// int). Struct offsets prev=0x18/next=0x1C match the donor's data[6] layout.
// FUN_00271310
s32 frFontFreeListInsert(u8 *freeNode)
{
  GslListNode *node = (GslListNode *)freeNode;
  GslListNode *head;
  GslListNode *next;
  s32 count;

  if (node == 0) {
    kAssertFail(D_0063BAE8, 0x1E9);
  }
  head = (GslListNode *)DAT_0088152C_abs[0];
  next = head->next;
  node->prev = head;
  node->next = next;
  head->next = node;
  next->prev = node;
  count = DAT_00881528_abs[0] + 1;
  DAT_00881528_abs[0] = count;
  return count;
}

/* Loads font data into slot arg0 with no separate header buffer (see frFontSlotLoad). */
// FUN_00271380
void frFontSlotLoadData(s32 slot, u8 *fontData)
{
    frFontSlotLoad(slot, 0, fontData);
}



/* Initialises the font manager: slot grid, scratch tables, and a glyph cache of arg1 entries. */
/* measured: pointer locals (FrFontSlot4 *slots / s32 *bb0), a named scaled
   offset, and opt_propagation off reproduce the retail loop guards and
   register coloring. The body is an exact 528-byte match. */

// FUN_002713B0
#pragma push
#pragma opt_propagation off
void frFontInitManager(s32 gridCapacity, s32 cacheCapacity)
{
    FrFontSlot4 *slots;
    s32 *boundSlots;
    s32 rows;
    s32 widthShift;
    u32 heightBits;
    s32 heightShift;
    s32 cacheShift;
    s32 boundIndex;
    s32 slotIndex;
    s32 offset;
    u32 widthBits;
    u32 cacheBits;

    DAT_00881750_abs[0] = 0;
    DAT_00881754_abs[0] = 0;
    DAT_00881758_abs[0] = 0;
    slotIndex = 0;
    slots = (FrFontSlot4 *)DAT_00881630_abs;
    while (slotIndex < 9) {
        offset = slotIndex << 5;
        ((FrFontSlot4 *)((u8 *)slots + offset))->object = 0;
        slotIndex += 1;
    }
    rows = gridCapacity >> 4;
    if (gridCapacity < 0) {
        rows = (gridCapacity + 0xf) >> 4;
    }
    widthBits = 0x200;
    DAT_0088176C_abs[0] = 0x200;
    widthShift = 0;
    if (widthBits == 0) {
    } else {
        while (widthBits != 0) {
            widthBits >>= 1;
            widthShift += 1;
        }
        widthShift = (widthShift - 1) & 0xff;
    }
    DAT_00881770_abs[0] = widthShift & 0xff;
    heightBits = rows << 5;
    heightShift = 0;
    if (heightBits == 0) {
    } else {
        while (heightBits != 0) {
            heightBits >>= 1;
            heightShift += 1;
        }
        heightShift = (heightShift - 1) & 0xff;
    }
    heightShift &= 0xff;
    cacheBits = 1 << (heightShift + 1);
    DAT_00881774_abs[0] = cacheBits;
    cacheShift = 0;
    if (cacheBits == 0) {
    } else {
        while (cacheBits != 0) {
            cacheBits >>= 1;
            cacheShift += 1;
        }
        cacheShift = (cacheShift - 1) & 0xff;
    }
    DAT_00881778_abs[0] = cacheShift & 0xff;
    frFontInitSlotGrid(DAT_0088177C_abs[0], 0x10, rows, 0x20, 0x20, 0x10);
    DAT_0088175c_abs[0] = rbRingBufCreate(0x2c, cacheCapacity * 4);
    *(s32 *)DAT_00881760_abs = rbRingBufCreate(0x44, cacheCapacity);
    frFontLoadTables();
    boundIndex = 0;
    boundSlots = D_008815B0;
    while (boundIndex < 0x20) {
        offset = boundIndex << 2;
        boundSlots[boundIndex] = 0;
        boundIndex += 1;
    }
    D_007645BC = rows * 0x10;
    frFontRasterCreateCache(cacheCapacity);
}
#pragma opt_propagation on
#pragma pop


/* Task destroy callback: releases the manager's tables, slot grid and glyph cache. */
// FUN_002715C0
void frFontTaskDestroy(u8 *unusedTask)
{
    void *(**tab);

    frFontReleaseSlots();
    frFontListRelease(DAT_0088179C_abs[0]);
    frFontListRelease(DAT_008817A0_abs[0]);
    fmGslContFreeNode(DAT_0088175c_abs[0]);
    fmGslContFreeNode(*(u32 *)DAT_00881760_abs);
    if (DAT_0088152C_abs[0] != 0) {
        tab = (void *(**) )DAT_008873ec_abs;
        ((code)tab[0])(DAT_00881510_abs[0]);
        ((code)tab[0])(DAT_00881514_abs[0]);
        DAT_0088152C_abs[0] = 0;
    }
    tab = (void *(**) )DAT_008873ec_abs;
    ((code)tab[0])(DAT_00881764_abs[0]);
    ((code)tab[0])(DAT_00881768_abs[0]);
    frFontRasterDestroyCache();
}

/* Loads one font's header and glyph table into slot arg0; arg1 is the font data (NULL falls back to arg2). */
// FUN_002716B0
void frFontSlotLoad(s32 slotId, u8 *header, u8 *fontData)
{
    FrFontSlot4 *slot;
    s32 offset;
    s32 metricsEnd;
    s32 slotIndex;
    u8 *glyphOffsets;

    if (header == NULL && fontData != NULL) {
        header = fontData;
    }
    if (header == NULL) {
        kAssertFail(D_0063BAE8, 0x2E9);
    }
    slotIndex = slotId & 0xFF;
    slot = &gFrFontManagerData_abs[0].slots[slotIndex];
    if (slotIndex >= 9) {
        kAssertFailAt(D_0063BB40, D_0063BAE8, 0x2ED);
    }
    slot->f00 = (u32)fontData;
    slot->f04 = (u32)header;
    /* Metric chunks are length-prefixed variable-length payloads, not fixed fields. */
    offset = ((FrFontFileHeader *)header)->dataOffset + (((FrFontFileHeader *)header)->blockCount << 6);
    if (((FrFontFileHeader *)header)->hasMetrics != 0) {
        slot->f08 = *(u32 *)(header + offset); /* Length-prefixed variable-size metric chunk. */
        slot->f10 = (u32)(header + (offset + 4));
        metricsEnd = offset + (slot->f08 + 4);
        slot->f0c = *(u32 *)(header + metricsEnd); /* Length-prefixed variable-size metric chunk. */
        slot->f14 = (u32)(header + (metricsEnd + 4));
        offset = metricsEnd + (slot->f0c + 4);
    } else {
        slot->f08 = 0;
        slot->f10 = 0;
        slot->f0c = 0;
        slot->f14 = 0;
    }
    glyphOffsets = header + offset;
    slot->f18 = (u32)glyphOffsets;
    func_00440b68(D_0063BB80, glyphOffsets, offset, ((FrFontFileHeader *)slot->f04)->glyphCount);
    slot->object =
        (u32)(header + (offset + (((FrFontFileHeader *)slot->f04)->glyphCount * 4)));
}

/* Frees the block held by slot param_1. */
// FUN_00271820
void frFontSlotFree(u32 slot)
{
    DAT_008873ec_abs[0](DAT_00881630_abs[(slot & 0xff) * 8]);
}



// fmGslContPushNode and frFontFreeListInsert are intentionally left undeclared
// (implicit old-style calls, as in the P3 donor FUN_003b0030); a typed
// prototype would force an int->pointer cast mwcc rejects, and the P3
// retail form is the implicit call.


/* Loads the font table on first use (synchronous read), then snapshots the manager data into the five backup tables. */
// FUN_00271860
void frFontLoadTables(void)
{
    int requestSize;
    u8 *source;
    u8 *sourceSecond;
    u8 *sourceThird;
    u8 *sourceFourth;
    u8 *sourceFifth;
    u8 *destination;
    u8 *destinationSecond;
    u8 *destinationThird;
    u8 *destinationFourth;
    u8 *destinationFifth;
    s32 request;

    if (DAT_0088164C_abs[0] != 0) {
        func_00440b68(D_0063BB00, NULL);
    }
    if (DAT_008817B0_abs[0] == 0) {
        func_00440b68(&D_00763830, D_0063BAE8, 0x265);
        request = H_Cdvd_AcquireDirectory(D_0063BC10, 0);
        DAT_008817B0_abs[0] = request;
        H_Cdvd_ReadSync(request);
        frFontSlotLoad(0, NULL, H_Cdvd_LookupRequest(D_0063BC10, &requestSize));
    }
    source = (u8 *)gFrFontManagerData_abs;
    destination = (u8 *)DAT_00881650_abs;
    *(FrFontSlot4 *)destination = *(FrFontSlot4 *)source;
    sourceSecond = (u8 *)gFrFontManagerData_abs;
    destinationSecond = (u8 *)DAT_00881670_abs;
    *(FrFontSlot4 *)destinationSecond = *(FrFontSlot4 *)sourceSecond;
    sourceThird = (u8 *)gFrFontManagerData_abs;
    destinationThird = (u8 *)DAT_00881690_abs;
    *(FrFontSlot4 *)destinationThird = *(FrFontSlot4 *)sourceThird;
    sourceFourth = (u8 *)gFrFontManagerData_abs;
    destinationFourth = (u8 *)DAT_008816B0_abs;
    *(FrFontSlot4 *)destinationFourth = *(FrFontSlot4 *)sourceFourth;
    sourceFifth = (u8 *)gFrFontManagerData_abs;
    destinationFifth = (u8 *)DAT_008816D0_abs;
    *(FrFontSlot4 *)destinationFifth = *(FrFontSlot4 *)sourceFifth;
    D_007645A8 = 0;
    D_007645A4 = 0;
    D_007645A0 = 0;
}

/* measured: recipe B retest 2026-08-03 - nd66..71 across four spellings
   (u8* arithmetic, named storep local, struct-element indexing with
   &slots[temp_17], mixed u8/s32 mask locals). Root cause confirmed: retail
   re-issues var_19&0xFF three times (andi $18/$17/$v0) so FOUR values live
   across the jals (frame 0x50, 4 saved regs); mwcc b210 CSEs every spelling
   (var_19&0xFF, (u8)var_19, (u8)(var_19&0xFF), %256, type-split u8/s32 - all
   one AND node) down to 2 andis, dropping to 3 saved regs (frame 0x40) and
   rematerializing the store address after jal func_00454bd0 - the recorded
   nd29 was not reproducible this wave. Struct indexing additionally folds
   0x1C into the base addiu where retail keeps it in the lw. CSE-of-mask
   floor. */

/* Releases every in-use slot's block and clears its entry. */
/* measured: opt_propagation off, three differently spelled masks of the loop index (`i & 0xff`,
   `(u32)i & 0xff`, `(u32)(u8)i`) so none is CSE'd with another (retail andi s2/s1/v0 from s3), and
   the free-slot pointer computed into a saved local BEFORE func_00454bd0 (retail addiu s1 before
   the jal); the table base stays in $a1 for both the par load and the slot address. */
// FUN_00271A40
#pragma opt_propagation off
void frFontReleaseSlots(void)
{
    /* Historical whole-layout typing changed MWCC scheduling; access-site probes now keep matching fields. */

    s32 i;
    s32 mask;
    s32 slotIndex;
    u32 request;
    u8 *slot;
    u8 *allocationCursor;
    u32 *allocationAddress;

    for (i = 0; i < 9; i++) {
        if (((FrFontSlot4 *)((u8 *)DAT_00881630_abs + i * 0x20))->object == 0)
            continue;
        mask = i & 0xff;
        if (mask >= 9)
            kAssertFailAt(D_0063BBB0, D_0063BAE8, 0x319);
        slotIndex = (u32)i & 0xff;
        slot = (u8 *)DAT_00881630_abs + slotIndex * 0x20;
        if (((FrFontSlot4 *)slot)->object == 0)
            kAssertFail(D_0063BAE8, 0x31D);
        allocationCursor = (u8 *)DAT_00881630_abs + slotIndex * 4;
        request = (u32)((FrFontManagerData4 *)allocationCursor)->allocations[0];
        if (request == 0)
            continue;
        allocationAddress = (u32 *)((u8 *)DAT_00881630_abs + (u32)(u8)i * 4 + 0x180);
        H_Cdvd_Destroy((struct HCdvd *)request);
        *allocationAddress = 0;
        func_00440b68(D_0063BBF0, mask);
        ((FrFontSlot4 *)slot)->f00 = 0;
        *(u32 *)(slot + 0x1c) = 0; /* measured: this access-site member rewrite changes instruction bytes. */
    }
}
#pragma opt_propagation on

/* Keeps the list if it is still in use, otherwise releases it. */
// FUN_00271B70
int frFontListKeepOrRelease(int list)
{
    char fading;
    int result;

    fading = (char)frFontFadeNodes(list);
    if (fading != '\0') {
        result = list;
    } else {
        result = frFontListRelease(list);
    }
    return result;
}
/* Releases a list: drops reference counts, frees unused entries back to the free list, and returns 0. */
// FUN_00271BD0
u32 frFontListRelease(int list)
{
    int glyph;
    int nextGlyph;
    int nextList;
    int raster;
    u32 *cacheEntry;

    if (list == 0) {
        return list;
    }

    while (list != 0) {
        glyph = ((FrFontTextRun *)list)->firstGlyph;

        while (glyph != 0) {
            nextGlyph = ((FrFontGlyphData *)glyph)->next;

            if (((FrFontGlyphData *)glyph)->unk20 == 0) {
                ((FrFontGlyphRaster *)((FrFontGlyphData *)glyph)->raster)->references =
                    ((FrFontGlyphRaster *)((FrFontGlyphData *)glyph)->raster)->references + -1;
                raster = ((FrFontGlyphData *)glyph)->raster;

                if ((raster != 0) && (((FrFontGlyphRaster *)raster)->references == 0)) {
                    cacheEntry = (u32 *)((FrFontGlyphRaster *)raster)->cacheEntry;

                    if (cacheEntry != (u32 *)0x0) {
                        *cacheEntry = *cacheEntry & 0xfffffffe;
                        cacheEntry[4] = 0;
                    }

                    frFontFreeListInsert((u8 *)(u32)((FrFontGlyphRaster *)raster)->slot);
                    DAT_00881750_abs[0] = DAT_00881750_abs[0] + -1;
                }
            }

            fmGslContPushNode(glyph, DAT_0088175c_abs[0]);
            glyph = nextGlyph;
            DAT_00881754_abs[0] = DAT_00881754_abs[0] + -1;
        }

        nextList = ((FrFontTextRun *)list)->previous;
        fmGslContPushNode(list, *(u32 *)DAT_00881760_abs);
        list = nextList;
        DAT_00881758_abs[0] = DAT_00881758_abs[0] + -1;
    }

    return 0;
}



/* Eight signed heights; the following halfword at 0x763810 is separate flags. */
extern s8 D_00763808[8];



/* Computes the metrics of one glyph node from the height table and the scale globals. */
/* measured: 576B/576B MATCH (b210). Native /32 and /128 restore the signed
   rounding instruction sequence; unary negation fixes the final mult operand
   order. The complete eight-byte table retains retail GP-relative access. */
// FUN_00271D10
void frFontComputeGlyphMetrics(u8 *glyph, s32 glyphIndex)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    FrFontSlot4 *slot;
    s32 heightOverride;
    s32 advanceOverride;
    s32 scaledAdvance;
    s32 defaultScaledAdvance;
    s32 horizontalScale;
    s32 scaledWidth;
    s32 scaledSpacing;
    s32 verticalScale;
    s32 scaledHeight;
    s32 metricsAddress;
    s32 character;
    s32 scaledOffset;
    s32 defaultScaledOffset;
    s32 extent;
    s32 advance;
    s32 defaultAdvance;
    s32 width;
    s32 spacing;
    s32 height;
    s32 xOffset;
    s32 defaultOffset;
    s32 leftFixed;
    s8 leftEdge;
    s8 rightEdge;
    s32 metricsOffset;

    slot =
        (FrFontSlot4 *)DAT_00881630_abs +
        ((FrFontGlyphData *)glyph)->slot;
    heightOverride = D_007645A8;
    if (heightOverride > 0) {
        ((FrFontGlyphData *)glyph)->width = (s8)heightOverride;
    } else {
        ((FrFontGlyphData *)glyph)->width =
            D_00763808[((FrFontGlyphData *)glyph)->slot];
    }
    ((FrFontGlyphData *)glyph)->height =
        D_00763808[*(u8 *)(glyph + 0x15)]; /* measured: this access-site member rewrite changes instruction bytes. */
    advanceOverride = D_007645A8;
    if (advanceOverride > 0) {
        ((FrFontGlyphData *)glyph)->advance = advanceOverride;
    } else {
        ((FrFontGlyphData *)glyph)->advance =
            D_00763808[*(u8 *)(glyph + 0x15)]; /* measured: this access-site member rewrite changes instruction bytes. */
    }
    if ((((FrFontGlyphData *)glyph)->flags & 1) &&
        ((FrFontFileHeader *)slot->f04)->hasMetrics != 0) {
        metricsOffset = glyphIndex * 2;
        if (metricsOffset < (s32)slot->f08) {
            metricsAddress = (s32)slot->f10;
            rightEdge = *(s8 *)(metricsAddress + 1 + metricsOffset); /* measured: this access-site member rewrite changes instruction bytes. */
            if (rightEdge != 0) {
                leftEdge = ((FrFontGlyphMetrics *)(metricsAddress + metricsOffset))->left;
                leftFixed = leftEdge * 0x10;
                extent = rightEdge - leftEdge;
                character = (metricsOffset >> 1) + 0x20;
                switch (character) {
                case 0x31:
                case 0x21:
                    leftFixed -= 0x20;
                    extent += 4;
                    break;
                default:
                    break;
                }
                if (D_007645A8 > 0) {
                    scaledOffset = -leftFixed * D_007645A8;
                    xOffset = scaledOffset / 32;
                    ((FrFontGlyphData *)glyph)->x = xOffset;
                    scaledAdvance = (extent + 1) * D_007645A8;
                    advance = scaledAdvance / 32;
                    *(s32 *)(glyph + 0xC) = advance; /* measured: this access-site member rewrite changes instruction bytes. */
                } else {
                    defaultScaledOffset =
                        -leftFixed * D_00763808[*(u8 *)(glyph + 0x15)]; /* measured: this access-site member rewrite changes instruction bytes. */
                    defaultOffset = defaultScaledOffset / 32;
                    ((FrFontGlyphData *)glyph)->x = defaultOffset;
                    defaultScaledAdvance =
                        (extent + 1) * D_00763808[*(u8 *)(glyph + 0x15)]; /* measured: this access-site member rewrite changes instruction bytes. */
                    defaultAdvance = defaultScaledAdvance / 32;
                    *(s32 *)(glyph + 0xC) = defaultAdvance; /* measured: this access-site member rewrite changes instruction bytes. */
                }
                horizontalScale = D_007645A0;
                if (horizontalScale > 0) {
                    scaledWidth =
                        (u8)*(s8 *)(glyph + 0x18) * horizontalScale; /* measured: this access-site member rewrite changes instruction bytes. */
                    width = scaledWidth / 128;
                    *(s8 *)(glyph + 0x18) = (s8)width; /* measured: this access-site member rewrite changes instruction bytes. */
                    scaledSpacing = *(s32 *)(glyph + 0xC) * D_007645A0; /* measured: this access-site member rewrite changes instruction bytes. */
                    spacing = scaledSpacing / 128;
                    *(s32 *)(glyph + 0xC) = spacing; /* measured: this access-site member rewrite changes instruction bytes. */
                }
                verticalScale = D_007645A4;
                if (verticalScale > 0) {
                    scaledHeight =
                        (u8)*(s8 *)(glyph + 0x19) * verticalScale; /* measured: this access-site member rewrite changes instruction bytes. */
                    height = scaledHeight / 128;
                    *(s8 *)(glyph + 0x19) = (s8)height; /* measured: this access-site member rewrite changes instruction bytes. */
                }
            }
        }
    }
}
/* Acquires the glyph for character arg1 in a font: uses the cached raster or loads and decodes it, then takes a node off the free list. */
// FUN_00271F50
extern char D_0063BC20[];
extern u32 frFontRasterLookup(u32 value, int otherValue);
extern u32 frFontFindOrLoadEntry(u32 value, u32 otherValue, u32 thirdValue);
extern u16 func_00273910(u32 value);
extern u16 func_00273940(u32 value);

u8 *frFontAcquireGlyph(u8 *glyph, u32 glyphIndex)
{
    /* Historical whole-layout typing changed MWCC scheduling; access-site probes now keep matching fields. */

    u8 *cacheEntry;
    u8 *raster;
    u8 *cachedRaster;
    u8 *freeSlot;
    u8 *decodedGlyph;
    u8 decodeWork[0x10];

    if ((cacheEntry = (u8 *)(u32)frFontRasterLookup(glyphIndex, ((FrFontGlyphData *)glyph)->palette)) != NULL) {
        cachedRaster = (u8 *)(u32)((FrFontRasterEntry *)cacheEntry)->references;
        if (cachedRaster != NULL) {
            ((FrFontGlyphRaster *)cachedRaster)->references += 1;
            return cachedRaster;
        }
    }
    if (cacheEntry == NULL) {
        raster = (u8 *)((u32)gFrFontManagerData_abs + (((FrFontGlyphData *)glyph)->slot << 5));
        chkmemAllocSiteTag(D_0063BAE8, 0x526);
        decodedGlyph = (u8 *)jtbl_008873E8[0](0x200, 0x40000);
        fmGslContSetupSubBlocks((int *)(u32)((FrFontSlot4 *)raster)->object, (int *)decodeWork);
        fmGslContDecodeRun((int)decodedGlyph, (int)glyphIndex, *(int *)(raster + 0x1C), (int *)decodeWork); /* measured: this access-site member rewrite changes instruction bytes. */
        cacheEntry = (u8 *)(u32)frFontFindOrLoadEntry(glyphIndex, (u32)decodedGlyph, glyph[0x14]); /* measured: this access-site member rewrite changes instruction bytes. */
        if (cacheEntry == NULL) {
            kAssertFail(D_0063BAE8, 0x560);
        }
        DAT_008873ec_abs[0](decodedGlyph);
    }
    func_00273910(((FrFontGlyphData *)glyph)->slot);
    func_00273940(glyph[0x15]); /* measured: this access-site member rewrite changes instruction bytes. */
    freeSlot = (u8 *)(u32)((GslListNode *)DAT_0088152C_abs[0])->next;
    if ((s32)((GslListNode *)freeSlot)->data[0] == 0) {
        freeSlot = NULL;
    } else {
        ((GslListNode *)((GslListNode *)freeSlot)->prev)->next = (GslListNode *)(u32)((GslListNode *)freeSlot)->next;
        ((GslListNode *)((GslListNode *)freeSlot)->next)->prev = (GslListNode *)(u32)((GslListNode *)freeSlot)->prev;
        DAT_00881528_abs[0] -= 1;
    }
    if (freeSlot == NULL) {
        kAssertFailAt(D_0063BC20, D_0063BAE8, 0x508);
    }
    raster = (u8 *)(u32)((GslListNode *)freeSlot)->data[5];
    if (raster == NULL) {
        kAssertFail(D_0063BAE8, 0x50D);
    }
    ((FrFontGlyphRaster *)raster)->references = 1;
    ((FrFontGlyphRaster *)raster)->slot = (u32)freeSlot;
    ((FrFontGlyphRaster *)raster)->character = (u16)glyphIndex;
    ((FrFontGlyphRaster *)raster)->cacheEntry = (u32)cacheEntry;
    ((FrFontRasterEntry *)cacheEntry)->references = (u32)raster;
    DAT_00881750_abs[0] += 1;
    return raster;
}
extern char D_0063BC50[];
extern u8 *fmGslContPopNode(s32 value);



/* Creates a text glyph node for character arg0 in slot arg1 with style arg2 and flags arg3, and computes its metrics. */
// FUN_00272170
u8 * frFontCreateGlyphNode(u16 character, u8 slotId, u8 palette, u8 effect)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    u8 *node;
    u16 ch;
    s32 width;
    s32 encodedIndex;
    s32 shiftedIndex;
    u16 glyphCount;
    s8 hit;
    s32 value;

    node = (u8 *)fmGslContPopNode(DAT_0088175c_abs[0]);
    DAT_00881754_abs[0] += 1;
    if (node == NULL) {
        kAssertFailAt(D_0063BC50, D_0063BAE8, 0x5D2);
    }
    ((FrFontGlyphData *)node)->character = character;
    ((FrFontGlyphData *)node)->slot = slotId;
    ((FrFontGlyphData *)node)->x = 0;
    ((FrFontGlyphData *)node)->y = 0;
    ((FrFontGlyphData *)node)->advance = 0;
    ((FrFontGlyphData *)node)->palette = palette;
    ((FrFontGlyphData *)node)->color = -0x100;
    ((FrFontGlyphData *)node)->effect = effect;
    ((FrFontGlyphData *)node)->flags = D_00763810;
    ((FrFontGlyphData *)node)->frame = 0;
    ((FrFontGlyphData *)node)->raster = 0;
    ((FrFontGlyphData *)node)->unk20 = 0;
    ((FrFontGlyphData *)node)->previous = 0;
    ((FrFontGlyphData *)node)->next = 0;
    ch = ((FrFontGlyphData *)node)->character;
    if (ch < 0x80) {
        if (ch == 0x20) {
            width = 0x1F6;
        } else {
            width = ch - 0x20;
        }
    } else {
        encodedIndex = ch - 0x8000;
        shiftedIndex = encodedIndex - 0x80;
        width = ((shiftedIndex & 0xFF00) >> 1) + (shiftedIndex & 0x7F);
    }
    glyphCount = ((FrFontFileHeader *)(u32)((FrFontSlot4 *)((u8 *)DAT_00881630_abs + (slotId & 0xFF) * 0x20))->f04)->glyphCount;
    if (glyphCount > width) {
        goto width_ok;
    }
    width = 0x147;
width_ok:
    *(u32 *)(node + 0x1C) = (u32)frFontAcquireGlyph(node, width); /* measured: this access-site member rewrite changes instruction bytes. */
    frFontComputeGlyphMetrics(node, width);
    if ((*(u8 *)(node + 0x17) & 0x10) == 0) { /* measured: this access-site member rewrite changes instruction bytes. */
        goto zero_store;
    }
    hit = 0;
    switch (width + 0x20) {
    case 0x51:
    case 0x67:
    case 0x6A:
    case 0x70:
    case 0x71:
    case 0x79:
        hit = 1;
        break;
    default:
        break;
    }
    if ((s8)hit == 0) {
        value = 0;
    } else {
        value = 0x10;
    }
    *(u32 *)(node + 8) = (s8)value; /* measured: this access-site member rewrite changes instruction bytes. */
    goto done;
zero_store:
    *(u32 *)(node + 8) = 0; /* measured: this access-site member rewrite changes instruction bytes. */
done:
    return node;
}
/* Returns the x kerning adjustment for a glyph pair (T/Y/V and vowel codes), scaled by D_007645A0. */
// FUN_00272390
int frFontKerningOffset(short *glyph)
{
    u16 *previousGlyph;
    u16 character;
    int offset;
    int scaledOffset;

    previousGlyph = (u16 *)((FrFontGlyphData *)glyph)->previous;
    offset = 0;
    if (((FrFontGlyphData *)glyph)->slot == 0) {
        goto LAB_002723B0;
    }
    if (((FrFontGlyphData *)glyph)->slot != 1) {
        goto LAB_002724C4;
    }
LAB_002723B0:
    if (previousGlyph == (u16 *)0x0) {
        goto LAB_002724C4;
    }
    character = ((FrFontGlyphData *)glyph)->character;
    switch (character) {
    case 0x61:
    case 0x65:
    case 0x6f:
    case 0x75:
    case 0x80c1:
    case 0x80c5:
    case 0x80cf:
    case 0x80d5:
        goto LAB_00272424;
    default:
        goto LAB_002724C4;
    }
LAB_00272424:
    character = *previousGlyph;
    if (character == 0x54) {
        goto LAB_00272458;
    }
    if (character == 0x80b4) {
        goto LAB_00272458;
    }
    if (character == 0x59) {
        goto LAB_00272458;
    }
    if (character == 0x80b9) {
        goto LAB_00272458;
    }
    goto LAB_00272484;
LAB_00272458:
    offset = 3;
    scaledOffset = D_007645A0;
    if (scaledOffset <= 0) {
        goto LAB_00272484;
    }
    scaledOffset = scaledOffset * 3;
    offset = scaledOffset >> 7;
    if (scaledOffset < 0) {
        offset = scaledOffset + 0x7f >> 7;
    }
LAB_00272484:
    if (character == 0x56) {
        goto LAB_0027249C;
    }
    if (character != 0x80b6) {
        goto LAB_002724C4;
    }
LAB_0027249C:
    offset = 2;
    scaledOffset = D_007645A0;
    if (scaledOffset <= 0) {
        goto LAB_002724C4;
    }
    scaledOffset = scaledOffset * 2;
    offset = scaledOffset >> 7;
    if (scaledOffset < 0) {
        offset = scaledOffset + 0x7f >> 7;
    }
LAB_002724C4:
    return offset;
}

extern u8 D_007645B4;
extern u8 *frFontCreateGlyphNode(u16 value, u8 otherValue, u8 thirdValue, u8 fourthValue);



/* Builds a text list from a string: one glyph node per character (1 or 2 bytes), linked and width-summed with kerning. */
/* Converted from INCLUDE_ASM. Retail keeps var16=$s0, var17=$s1,
   var18/i=$s2, arg4=$s3, arg0=$s4, result count=$s5, arg2=$s6,
   and arg3=$s7. The u8 helper arguments are materialized once in
   preheader locals so b210 emits the retail andi sequence. Style is a word,
   character a signed byte; the shared API preserves all 57 owner matches.
   Callers explicitly sequence character loads, and dynamic style before
   character, to retain the retail argument evaluation order. */
// FUN_002724D0
u8 *frFontCreateTextList(u8 *text, s32 style, s8 palette, s32 effect, u8 *existing) {
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    s32 kerning;
    u16 ch;
    u32 length;
    u8 value;
    u8 *previousGlyph;
    u32 i;
    u8 glyphPalette;
    u8 glyphEffect;
    u8 *glyph;
    u8 *lastGlyph;
    u8 *list;

    list = existing;
    length = 0;
    if ((s8)style >= 0) {
        D_007645B4 = (u8)style;
    }
    if (*(u32 *)((u8 *)DAT_0088164C_abs + ((D_007645B4 & 0xFF) << 5)) == 0) { /* Linker interior alias of the slot object column; keep its relocation base. */
        return NULL;
    }
    if (text != NULL) {
        length = strlen(text);
    }
    if (list == NULL) {
        list = fmGslContPopNode(*(u32 *)DAT_00881760_abs);
        DAT_00881758_abs[0] += 1;
        if (list == NULL) {
            kAssertFail(&D_0063BAE8, 0x665);
        }
        memset(list, 0, 0x44);
        ((FrFontTextRun *)list)->intensity = 0xFF;
        ((FrFontTextRun *)list)->code = 0x20;
        ((FrFontTextRun *)list)->root = (s32)list;
    }
    glyph = NULL;
    lastGlyph = (u8 *)(u32)((FrFontTextRun *)list)->lastGlyph;
    i = 0;
    glyphEffect = (u8)effect;
    glyphPalette = (u8)palette;
    while (i < length) {
        value = text[i];
        ch = value;
        if (value >= 0x80) {
            i += 1;
            ch = (u16)(((u16)value << 8) | *(u8 *)(text + i)); /* measured: this access-site member rewrite changes instruction bytes. */
        }
        glyph = frFontCreateGlyphNode(ch, D_007645B4, glyphPalette, glyphEffect);
        if (lastGlyph == NULL) {
            ((FrFontTextRun *)list)->firstGlyph = (s32)glyph;
        } else {
            ((FrFontGlyphData *)lastGlyph)->next = (s32)glyph;
        }
        if (glyph == NULL) {
            kAssertFail(&D_0063BAE8, 0x676);
        }
        ((FrFontGlyphData *)glyph)->previous = (s32)lastGlyph;
        lastGlyph = glyph;
        ((FrFontTextRun *)list)->width += ((FrFontGlyphData *)glyph)->advance;
        ((FrFontTextRun *)list)->glyphCount += 1;
        kerning = frFontKerningOffset((short *)glyph);
        if (kerning != 0) {
            previousGlyph = *(u8 **)(glyph + 0x24); /* measured: this access-site member rewrite changes instruction bytes. */
            if (previousGlyph != NULL) {
                ((FrFontGlyphData *)previousGlyph)->advance -= kerning;
            }
            *(s32 *)(list + 0x0C) -= kerning; /* measured: this access-site member rewrite changes instruction bytes. */
        }
        i += 1;
    }
    if (glyph != NULL) {
        *(u8 **)(list + 0x20) = glyph; /* measured: this access-site member rewrite changes instruction bytes. */
        ((FrFontTextRun *)list)->glyphWidth = ((FrFontGlyphData *)glyph)->width;
        ((FrFontTextRun *)list)->glyphHeight = ((FrFontGlyphData *)glyph)->height;
    }
    return list;
}
/* Sets the byte at +2 of every node in the list. */
// FUN_00272730
void frFontSetListFlag(int list, u8 intensity)
{
    if (list == 0) {
        kAssertFail(D_0063BAE8, 0x69B);
    }
    for (; list != 0; list = ((FrFontTextRun *)list)->previous) {
        ((FrFontTextRun *)list)->intensity = intensity;
    }
}

/* Sets the node's leading 16-bit id (character code). */
// FUN_002727A0
void frFontSetNodeId(u32 list, u16 code)
{
    if (list == 0) {
        kAssertFail(D_0063BAE8, 0x6A7);
    }
    ((FrFontTextRun *)list)->code = code;
}

/* Enables the node and marks every node in its chain with 0xFF at +2. */
// FUN_002727F0
void frFontEnableList(FrFontNode *node)
{
    FrFontNode *iter;

    node->enabled = 1;
    iter = node;
    if (node == NULL) {
        kAssertFail(D_0063BAE8, 0x69B);
    }
    for (; iter != NULL; iter = iter->next) {
        iter->unknown_00[2] = 0xff;
    }
}

/* Sets the byte at +3 of a node and recomputes its width at +0xC. */
// FUN_00272860
void frFontSetCharWidth(int list, int spacing)
{
    if (list == 0) {
        kAssertFail(D_0063BAE8, 0x6C3);
    }
    ((FrFontTextRun *)list)->spacing = spacing;
    ((FrFontTextRun *)list)->width = frFontNodeWidth(list);
}

/* Sets the slot byte (+0x15) of every glyph in every node of the list. */
// FUN_002728C0
void frFontSetListSlot(int list, u8 slot)
{
    int glyph;

    if (list == 0) {
        kAssertFail(D_0063BAE8, 0x6F2);
    }
    for (; list != 0; list = ((FrFontTextRun *)list)->previous) {
        for (glyph = ((FrFontTextRun *)list)->firstGlyph; glyph != 0;
             glyph = ((FrFontGlyphData *)glyph)->next) {
            ((FrFontGlyphData *)glyph)->slot = slot;
        }
    }
}

/* Shifts the whole list so its first node is at (x, y). */
// FUN_00272950
void frFontMoveListTo(int list, int x, int y)
{
    int dy;
    int dx;

    if (list == 0) {
        kAssertFail(D_0063BAE8, 0x708);
    }
    while (((FrFontTextRun *)list)->previous != 0) {
        list = ((FrFontTextRun *)list)->previous;
    }
    dx = x - ((FrFontTextRun *)list)->x;
    dy = y - ((FrFontTextRun *)list)->y;
    while (list != 0) {
        ((FrFontTextRun *)list)->x = ((FrFontTextRun *)list)->x + dx;
        ((FrFontTextRun *)list)->y = ((FrFontTextRun *)list)->y + dy;
        list = ((FrFontTextRun *)list)->next;
    }
}

/* Shifts the whole list to a float position (x * 16, y * 8). */
// FUN_00272A10
void frFontMoveListToFloat(int list, float x, float y)
{
    int dy;
    int dx;

    if (list == 0) {
        kAssertFail(D_0063BAE8, 0x71F);
    }
    while (((FrFontTextRun *)list)->previous != 0) {
        list = ((FrFontTextRun *)list)->previous;
    }
    dx = (int)(16.0f * x) - ((FrFontTextRun *)list)->x;
    dy = (int)(8.0f * y) - ((FrFontTextRun *)list)->y;
    while (list != 0) {
        ((FrFontTextRun *)list)->x = ((FrFontTextRun *)list)->x + dx;
        ((FrFontTextRun *)list)->y = ((FrFontTextRun *)list)->y + dy;
        list = ((FrFontTextRun *)list)->next;
    }
}

/* Sets the aux byte (+0x14) of every glyph in the list. */
/* measured: frFontSetGlyphAux/00272b34 (and frFontSetGlyphColor/00272bd4) are one retail
   code region split by Ghidra at a branch target: b00's entry beq jumps to
   b34's entry, whose bne branches back into b00's body. Portable C cannot
   reproduce the cross-function branch (standalone compiles give b00 15 words
   vs a 13-word window and b34 a full body vs a 7-word window). P3FES donor
   keeps the same pair as asm functions (FUN_003b0dd8/FUN_003b0e04).
   Ghidra split, not a compiler floor. */
/* Was recorded here as a Ghidra split that portable C could not express. It was a
   boundary bug, not a source problem: spimdisasm took the landing point of this
   function's opening `b 0x00272B34` - the bottom test of its rotated loop - as a second
   function, so the window stopped at 52 bytes in the middle of the loop and no body
   could ever fill it. 0x00272B34 has zero jal, zero j and zero pointer references in
   the whole image while this address has 17 jal sites. With the landing point withdrawn
   in reconcile_function_boundaries the window is 80 bytes and the obvious nested-while,
   the same shape as the already-matching frFontReplaceGlyphAux below, is byte-exact. */
// FUN_00272B00
void frFontSetGlyphAux(int list, u8 palette)
{
    FrFontGlyph *glyph;

    while (list != 0) {
        glyph = (FrFontGlyph *)((FrFontTextRun *)list)->firstGlyph;
        while (glyph != NULL) {
            glyph->unknown_10[4] = palette;
            glyph = glyph->next;
        }
        list = ((FrFontTextRun *)list)->previous;
    }
}

/* Replaces the aux byte of every glyph equal to key with value. */
// FUN_00272B50
void frFontReplaceGlyphAux(int list, u8 oldPalette, u8 newPalette)
{
    int key = oldPalette;
    FrFontGlyph *glyph;

    while (list != 0) {
        glyph = (FrFontGlyph *)((FrFontTextRun *)list)->firstGlyph;
        while (glyph != NULL) {
            if (glyph->unknown_10[4] == key) {
                glyph->unknown_10[4] = newPalette;
            }
            glyph = glyph->next;
        }
        list = ((FrFontTextRun *)list)->previous;
    }
}

/* Sets the colour word (+0x10) of every glyph in the list. */
/* measured: s32 twin of the frFontSetGlyphAux/00272b34 split above (stores a
   u32 at +0x10 instead of a u8 at +0x14); 00272bd4's entry bne branches back
   into 00272ba0's body. Same Ghidra split, same impossibility for portable C
   (see the note above FUN_00272B00). */
/* The u32 twin of frFontSetGlyphAux above (stores at +0x10 instead of a u8 at +0x14).
   Same withdrawn branch-landing entry (0x00272BD4, zero callers; this address has 18
   jal sites), same 80-byte window, same nested-while body. */
// FUN_00272BA0
void frFontSetGlyphColor(int list, u32 color)
{
    FrFontGlyph *glyph;

    while (list != 0) {
        glyph = (FrFontGlyph *)((FrFontTextRun *)list)->firstGlyph;
        while (glyph != NULL) {
            ((FrFontGlyphData *)glyph)->color = color;
            glyph = glyph->next;
        }
        list = ((FrFontTextRun *)list)->previous;
    }
}

/* Returns the last node in the list. */
// FUN_00272BF0
int frFontListTail(int list)
{
    if (list == 0) {
        kAssertFail(D_0063BAE8, 0x77B);
    }
    while (((FrFontTextRun *)list)->previous != 0) {
        list = ((FrFontTextRun *)list)->previous;
    }
    return list;
}
/* Sets bits in the global flag word and returns its previous value. */
// FUN_00272C60
u16 frFontSetFlagBits(s16 bits)
{
    u16 previousFlags;

    previousFlags = D_00763810;
    D_00763810 = D_00763810 | bits;
    return previousFlags;
}



/* Clears bits in the global flag word and returns its previous value. */
// FUN_00272C80
u16 frFontClearFlagBits(u16 bits)
{
    u16 previousFlags;
    long mask;

    previousFlags = D_00763810;
    mask = (s16)~bits;
    D_00763810 = D_00763810 & mask;
    return previousFlags;
}


/* Fades every node of type 2 that still has a fade level: lowers the level by 8 and raises the node's +8 by 0x10. Returns 1 if any node changed. */
// Ported from P3FES FUN_003b0ec0 (verified MATCH there). Retail hoists the
// loop-invariant mask/type constants here; removing opt_loop_invariants
// measured nd102 at 136B instead of nd1 at 140B (P3 donor annotation).

// FUN_00272CB0
#pragma push
#pragma opt_loop_invariants on

u32 frFontFadeNodes(int list)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    u32 result = 0;
    u32 mask = ~0xff;
    u32 changed = 1;
    u32 type = 2;

    while (list != 0) {
        int node = ((FrFontTextRun *)list)->firstGlyph;

        while (node != 0) {
            if (((FrFontGlyphData *)node)->effect == type) {
                u32 word = ((FrFontGlyphData *)node)->color;
                u32 fade = word & 0xff;
                u32 merged;

                if (fade != 0) {
                    fade -= 8;
                    if ((s32)fade < 0) {
                        fade = 0;
                    }
                    merged = word & mask;
                    merged |= fade;
                    *(u32 *)(node + 0x10) = merged; /* measured: this access-site member rewrite changes instruction bytes. */
                    ((FrFontGlyphData *)node)->y += 0x10;
                    result = changed;
                }
            }
            node = ((FrFontGlyphData *)node)->next;
        }
        list = ((FrFontTextRun *)list)->previous;
    }
    return result;
}
#pragma opt_loop_invariants off
#pragma pop



/* Returns the node if its type and state say it is ready (or 0). */
// FUN_00272D40
u8 *frFontReadyNode(u8 *list)
{
    s32 stateValue;

    stateValue = ((FrFontTextRun *)list)->command;
    switch (stateValue) {
    case 0xF222:
    case 0xF227:
        stateValue = ((FrFontTextRun *)list)->duration;
        if (stateValue == -1) {
            break;
        }
        if (stateValue > 0) {
            return list;
        }
        break;
    case 0xF223:
    case 0xF226:
        stateValue = ((FrFontTextRun *)list)->duration;
        if (stateValue == -1) {
            if (sdkSndIsChannelPlaying(1) != 0) {
                return list;
            }
        } else if (stateValue > 0) {
            return list;
        }
        break;
    }
    return 0;
}
/* Steps a node's intensity by a scaled amount (saturating at 0xFF) and returns the x shift for type-1 nodes. */
/* measured: retail keeps arg1=$16/arg0=$17/temp_18=$18/var_19=$19/var_20=$20/
   var_21=$21/var_22=$22/arg3=$23; mwcc b210 colors arg3=$16 FIRST and omits
   the arg1+0x10 hoist (nd167). Declaration reorders (4 orders probed), u32
   param widths, ternary float, early hoist, switch-wrapped final if: no
   combination moves it. Float if/else also emits a branch-to-branch where
   retail branches to the join. Re-tested wave 14 (fresh m2c body, nd170):
   confirms the pervasive rotation - retail saves 8 (frame 0x90,
   arg0=$s1/arg1=$s0/arg3=$s7), mwcc saves 7 (frame 0x80, arg0=$s3/arg1=$s2)
   from the very first move; also fixed frFontReadyNode's call to 1 arg (m2c
   draft wrongly shows 2; retail calls with $18 only). Saved-register
   SUPERSEDED: Saved-register rotation floor. */
// FUN_00272E10
s32 frFontStepNodeIntensity(u8 *list, u8 *glyph, u8 threshold, u8 speed)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    s32 result = 0;
    s32 amount;
    u8 normalized;
    u32 value;
    u8 limit;
    u8 type;
    u8 accepted;
    u8 found;
    u8 *previousList;
    u8 *valuep;
    u32 code;

    accepted = 0;
    limit = 0xff;
    type = 0;
    if ((u8 *)(u32)((FrFontGlyphData *)glyph)->previous == 0) {
        if ((u8 *)(u32)((FrFontTextRun *)list)->previous != 0 &&
            (u8 *)(u32)((FrFontTextRun *)((u8 *)(u32)((FrFontTextRun *)list)->previous))->lastGlyph != 0) {
            limit = (u8)((FrFontGlyphData *)((u8 *)(u32)((FrFontTextRun *)((u8 *)(u32)((FrFontTextRun *)list)->previous))->lastGlyph))->color;
            type = ((FrFontGlyphData *)((u8 *)(u32)((FrFontTextRun *)((u8 *)(u32)((FrFontTextRun *)list)->previous))->lastGlyph))->effect;
        }
    } else {
        limit = (u8)((FrFontGlyphData *)((u8 *)(u32)((FrFontGlyphData *)glyph)->previous))->color;
    }
    if (threshold > 0 && *(u16 *)glyph < 0x80) {
        threshold += 0x14;
    }
    valuep = glyph + 0x10;
    if (type == 0 || type == ((FrFontGlyphData *)glyph)->effect) {
        if (limit >= threshold) {
            accepted = 1;
        }
    } else if (limit == 0xff) {
        accepted = 1;
    }
    previousList = (u8 *)(u32)((FrFontTextRun *)list)->previous;
    if (accepted && previousList != 0 &&
        (u8 *)(u32)((FrFontTextRun *)list)->firstGlyph == glyph &&
        ((FrFontTextRun *)list)->enabled == 0) {
        found = 0;
        if (frFontReadyNode(previousList) != 0) {
            found = 1;
            switch (((FrFontTextRun *)previousList)->command) {
            case 0xf222:
            case 0xf227:
                ((FrFontTextRun *)previousList)->duration =
                    ((FrFontTextRun *)previousList)->duration - 1;
                break;
            case 0xf223:
            case 0xf226:
                if (((FrFontTextRun *)previousList)->duration == -1) {
                    sdkSndIsChannelPlaying(1);
                } else {
                    *(s32 *)(previousList + 0x3c) = /* measured: this access-site member rewrite changes instruction bytes. */
                        ((FrFontTextRun *)previousList)->duration - 1;
                }
                break;
            }
        }
        if (found != 0) {
            accepted = 0;
        }
    }
    if (accepted) {
        if (speed < 0xff) {
            amount = (s32)((f32)(speed << 5) /
                           (f32)(((FrFontGlyphData *)glyph)->advance +
                                 ((FrFontTextRun *)list)->spacing));
        } else {
            amount = 0xff;
        }
        if (amount > 0xff) {
            normalized = 0xff;
        } else {
            amount &= 0xff;
            normalized = amount & 0xff;
        }
        value = *(u32 *)valuep;
        if ((u32)(0xff - (value & 0xff)) >= (u32)normalized) {
            *(u32 *)valuep = value + normalized;
        } else {
            *(u32 *)valuep = (value & ~0xff) | 0xff;
        }
    }
    code = ((FrFontGlyphData *)glyph)->frame;
    if (*(u8 *)valuep < 0xff) {
        switch (((FrFontGlyphData *)glyph)->effect) {
        case 1:
            result = -(((((s32)code << 1) % 5) - 2) * 0x10);
            break;
        default:
            break;
        }
    }
    return result;
}
/* Draws a list with the default mode. */
// FUN_00273110
void frFontDrawListDefault(s32 list)
{
    frFontDrawListMode((void *)list, 0);
}



/* Draws a list with the given mode and the default third argument. */
// FUN_00273140
void frFontDrawListMode(void *list, u32 mode)
{
    frFontDrawList(list, mode, D_00764598);
}



extern s32 D_0076459C;
extern void RpSkyRenderStateSet(s32 value, s32 otherValue);
extern s32 frFontStepNodeIntensity(u8 *value, u8 *otherValue, u8 thirdValue, u8 fourthValue);
/* Raster dimensions use full unsigned words; the glyph stores their byte
 * source values. Depth precedes the glyph in the shared mixed-ABI contract. */
extern s32 frFontRasterDrawGlyph(s32 x, s32 y, f32 depth, u8 *glyph,
                         s32 palette, u32 width, u32 height, u32 color);
extern code D_00887300_abs[];



/* Draws every node of a list: glyph by glyph at the node position, with per-glyph animation. Returns the total advance, or 0 while glyphs are still animating. */
/* measured: ordinary s32 spacing preserves its signed-byte load across
   callbacks, while named raster inputs and opt_propagation off preserve
   argument load order. Reversed long-lived declaration order closes the
   saved-register mirrors. All 824 executable bytes and 11 relocations
   match; the remaining eight retail bytes are alignment padding. */
// FUN_00273170
#pragma opt_propagation off
s32 frFontDrawList(void *list, u32 drawMode, u32 unused)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    u8 *node;
    u8 *glyph;
    s32 total;
    s32 x;
    s32 complete;
    s32 mode;
    s32 y;
    s32 spacing;
    s32 offset;
    u8 found;
    u32 states;
    u8 style;
    s32 drawX;
    s32 drawY;
    u8 palette;
    u8 width;
    u8 height;
    f32 scale;

    node = (u8 *)list;
    total = 0;
    complete = 1;
    if (!(D_00763810 & 0x40)) {
        states = (u32)D_00887300_abs;
        ((code)*(u32 *)states)(6, 1);
        ((code)*(u32 *)states)(7, 2);
        ((code)*(u32 *)states)(9, 2);
        ((code)*(u32 *)states)(12, 1);
        ((code)*(u32 *)states)(10, 5);
        ((code)*(u32 *)states)(11, 6);
        ((code)*(u32 *)states)(2, 4);
        ((code)*(u32 *)states)(14, 0);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x5100D);
    }
    if (node == 0) {
        return 0;
    }
    node = (u8 *)(u32)((FrFontTextRun *)node)->root;
    mode = (s8)drawMode;
    while (node != 0) {
        x = ((FrFontTextRun *)node)->x;
        y = ((FrFontTextRun *)node)->y;
        spacing = ((FrFontTextRun *)node)->spacing;
        glyph = (u8 *)(u32)((FrFontTextRun *)node)->firstGlyph;
        while (glyph != 0) {
            if (mode == 0) {
                style = (u8)((FrFontTextRun *)node)->code;
                offset = frFontStepNodeIntensity(node, glyph, style, ((FrFontTextRun *)node)->intensity);
            } else {
                offset = 0;
            }
            drawX = offset + (x + ((FrFontGlyphData *)glyph)->x);
            drawY = y + ((FrFontGlyphData *)glyph)->y;
            palette = ((FrFontGlyphData *)glyph)->palette;
            width = ((FrFontGlyphData *)glyph)->width;
            height = ((FrFontGlyphData *)glyph)->height;
            scale = ((FrFontTextRun *)node)->depth.scale;
            frFontRasterDrawGlyph(drawX, drawY, scale, glyph, palette, width, height,
                         ((FrFontGlyphData *)glyph)->color);
            if (glyph[0x10] != 0) { /* measured: this access-site member rewrite changes instruction bytes. */
                ((FrFontGlyphData *)glyph)->frame += 1;
            }
            if (glyph[0x10] < 255U) { /* measured: this access-site member rewrite changes instruction bytes. */
                complete = 0;
            }
            x += (s32)((u32)(((FrFontGlyphData *)glyph)->advance + spacing) << 4);
            glyph = (u8 *)(u32)((FrFontGlyphData *)glyph)->next;
        }
        if ((u8 *)(u32)((FrFontTextRun *)node)->next == 0 && ((FrFontTextRun *)node)->enabled == 0) {
            found = 0;
            if (frFontReadyNode(node) != 0) {
                found = 1;
                switch (((FrFontTextRun *)node)->command) {
                case 0xF222:
                case 0xF227:
                    ((FrFontTextRun *)node)->duration -= 1;
                    break;
                case 0xF223:
                case 0xF226:
                    if (((FrFontTextRun *)node)->duration == -1) {
                        sdkSndIsChannelPlaying(1);
                    } else {
                        *(s32 *)(node + 0x3C) -= 1; /* measured: this access-site member rewrite changes instruction bytes. */
                    }
                    break;
                }
            }
            if (found != 0) {
                complete = 0;
            }
        }
        total += ((FrFontTextRun *)node)->glyphCount;
        node = *(u8 **)(node + 0x28); /* measured: this access-site member rewrite changes instruction bytes. */
    }
    if (D_0076459C > 0) {
        D_0076459C -= 1;
        return 0;
    }
    if ((s8)complete == 0) {
        total = 0;
    }
    return total;
}
#pragma opt_propagation on
/* Returns the total advance of a list if no node is still animating, otherwise 0. Measures without drawing. */
/* measured: reconstructed from the matched frFontReadyNode case logic. Reusing
   arg0 as the walking node and declaring flag before sum gives retail's
   node=$s2/flag=$s1/sum=$s0 prologue. Assigning the result pointer only after
   each case's call, with explicit result_zero/result_check labels, reproduces
   the shared move/beqz block. MATCH at normalized_diff 0, object 340B/window
   352B; exact body archived at build/WCKFldUnit_734b0_match.c. */
// FUN_002734B0
s32 frFontMeasureList(u8 *list)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    s32 command;
    s32 duration;
    s32 soundDuration;
    u8 *pendingList;
    s32 complete;
    s32 total;

    complete = 1;
    total = 0;
    if (list == NULL) {
        return 0;
    }
    list = (u8 *)(u32)((FrFontTextRun *)list)->root;
    while (list != NULL) {
        if (((u8 *)(u32)((FrFontTextRun *)list)->next == NULL) &&
            (((FrFontTextRun *)list)->enabled == 0)) {
            command = ((FrFontTextRun *)list)->command;
            switch (command) {
            case 0xF222:
            case 0xF227:
                duration = ((FrFontTextRun *)list)->duration;
                if (duration == -1) {
                    goto result_zero;
                }
                if (duration <= 0) {
                    goto result_zero;
                }
                pendingList = list;
                goto result_check;
            case 0xF223:
            case 0xF226:
                soundDuration = ((FrFontTextRun *)list)->duration;
                if (soundDuration == -1) {
                    if (sdkSndIsChannelPlaying(1) != 0) {
                        pendingList = list;
                        goto result_check;
                    }
                    goto result_zero;
                } else if (soundDuration <= 0) {
                    goto result_zero;
                }
                pendingList = list;
                goto result_check;
            default:
                goto result_zero;
            }
result_zero:
            pendingList = NULL;
result_check:
            if (pendingList != NULL) {
                complete = 0;
            }
        }
        total += ((FrFontTextRun *)list)->glyphCount;
        list = *(u8 **)(list + 0x28); /* measured: this access-site member rewrite changes instruction bytes. */
    }
    if ((s8)complete == 0) {
        total = 0;
    }
    return total;
}
/* Cache maintenance task: releases the cached list and evicts expired raster entries. */
// FUN_00273610
s32 frFontMaintainCacheTask(u8 *unusedTask)
{
    DAT_0088179C_abs[0] = frFontListRelease(DAT_0088179C_abs[0]);
    frFontRasterEvictExpired();
    return 0;
}
/* Splices list param_1 onto the tail of param_2 and returns the joined head (either argument if the other is 0). When param_3 is 1 also moves param_2 to just after param_1 (x + width * 16, y). */
// FUN_00273650
int frFontAppendList(int tail, int list, int moveAfter)
{
    if (tail != 0)
    {
        goto checkParam2;
    }
    return list;

checkParam2:
    if (list != 0)
    {
        goto body;
    }
    return tail;

body:
    ((FrFontTextRun *)tail)->next = (u32)((FrFontTextRun *)list)->root;
    ((FrFontTextRun *)((FrFontTextRun *)list)->root)->previous = tail;
    ((FrFontTextRun *)list)->root = (u32)((FrFontTextRun *)tail)->root;

    if (moveAfter == 1)
    {
        ((FrFontTextRun *)list)->x = ((FrFontTextRun *)tail)->x + ((FrFontTextRun *)tail)->width * 0x10;
        ((FrFontTextRun *)list)->y = (u32)((FrFontTextRun *)tail)->y;
    }

    return list;
}



extern int frFontCountRuns(int value);



/* Detaches the run of same-type nodes at index arg1 from *arg0 and returns the run's last node; *arg0 is updated to the remaining head. */
/* measured 2026-08-08: reconstructed the 0x40-byte-linked-list extractor
   with a typed local node and explicit goto CFG. The declaration order
   temp_3,var_18,temp_17,var_7,... plus the forward count guard
   `frFontCountRuns(temp_17) > var_18` yields retail's saved colors and
   `slt $at`; optimization_level 1 with opt_common_subs on is load-bearing.
   MATCH nd 0, object 464/window 464 (O2 nd2; O1 without common-substitutions
   nd36). */
// FUN_002736D0
/* measured: opens the optimization_level 1 scope for frFontSplitRun; the
   common-substitution setting is required for MATCH nd 0. */
#pragma push
#pragma optimization_level 1
#pragma opt_common_subs on
u8 *frFontSplitRun(u8 **listAddress, s32 runIndex)
{
    struct FrFontTreeNode {
        u8 unknown_00[8];
        s32 type;
        u8 unknown_0C[0x18];
        struct FrFontTreeNode *prev;
        struct FrFontTreeNode *next;
        struct FrFontTreeNode *root;
    };
    s32 runType;
    s32 remainingRuns;
    struct FrFontTreeNode *list;
    struct FrFontTreeNode *runStart;
    struct FrFontTreeNode *previous;
    struct FrFontTreeNode *following;
    struct FrFontTreeNode *next;
    struct FrFontTreeNode *runEnd;
    struct FrFontTreeNode *detached;
    struct FrFontTreeNode *remaining;
    struct FrFontTreeNode *root;

    remainingRuns = runIndex;
    if (listAddress == NULL) {
        kAssertFail(&D_0063BAE8, 0x96B);
    }
    list = (struct FrFontTreeNode *)*listAddress;
    if (list == NULL) {
        return NULL;
    }
    if (frFontCountRuns((int)list) < 2) {
        return NULL;
    }
    if (frFontCountRuns((int)list) > remainingRuns) {
        goto count_ok;
    }
    return NULL;
count_ok:
    runStart = list->root;
    goto outer_check;
outer_body:
    runType = runStart->type;
    runStart = runStart->next;
    goto inner_check;
inner_body:
    previous = (struct FrFontTreeNode *)runStart->type;
    if ((s32)previous != runType) {
        goto outer_decrement;
    }
    runStart = runStart->next;
inner_check:
    if (runStart != NULL) {
        goto inner_body;
    }
outer_decrement:
    remainingRuns -= 1;
outer_check:
    if (remainingRuns > 0) {
        goto outer_body;
    }
    if (runStart == NULL) {
        return NULL;
    }
    runEnd = runStart;
    goto result_check;
result_body:
    if (next->type != runStart->type) {
        goto result_done;
    }
    runEnd = next;
result_check:
    next = runEnd->next;
    if (next != NULL) {
        goto result_body;
    }
result_done:
    root = runStart->root;
    if (root != runStart) {
        goto root_done;
    }
    root = next;
root_done:
    previous = runStart->prev;
    if (previous == NULL) {
        goto prev_done;
    }
    previous->next = next;
prev_done:
    following = runEnd->next;
    if (following == NULL) {
        goto next_done;
    }
    following->prev = runStart->prev;
next_done:
    runStart->prev = NULL;
    runEnd->next = NULL;
    detached = runStart;
    goto loop29_check;
loop29_body:
    detached->root = runStart;
    detached = detached->next;
loop29_check:
    if (detached != NULL) {
        goto loop29_body;
    }
    remaining = root;
    goto loop32_check;
loop32_body:
    remaining->root = root;
    remaining = remaining->next;
loop32_check:
    if (remaining->next != NULL) {
        goto loop32_body;
    }
    remaining->root = root;
    *listAddress = (u8 *)remaining;
    return (u8 *)runEnd;
}
/* measured: closes the optimization_level 1 scope; frFontSplitRun remains
   MATCH nd 0, object 464/window 464 at the file's O2 baseline. */
#pragma optimization_level 2
#pragma pop



/* Loads data into the system font slot (slot 8). */
// FUN_002738A0
void frFontLoadSystemSlot(u8 *fontData)
{
    frFontSlotLoad(8, fontData, 0);
}



/* Returns a node's total width: each glyph's advance plus the node's line height. */
// FUN_002738D0
int frFontNodeWidth(FrFontNode *node)
{
    int total = 0;
    FrFontGlyph *glyph;

    for (glyph = node->glyphs; glyph != NULL; glyph = glyph->next) {
        total += glyph->advance;
        total += node->line_height;
    }
    return total;
}




// FUN_00273910
/* Return the font header halfword at +0x10 for the selected slot; its meaning is not established. */
u16 func_00273910(u32 slot)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(slot & 0xff) * 8];
    return ((FrFontFileHeader *)entry)->unk10;
}




// FUN_00273940
/* Return the font header halfword at +0x12 for the selected slot; its meaning is not established. */
u16 func_00273940(u32 slot)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(slot & 0xff) * 8];
    return ((FrFontFileHeader *)entry)->unk12;
}



/* Returns the number of same-type runs in a node's chain. */
// FUN_00273970
int frFontCountRuns(int node)
{
    int result = 0;
    int child;

    if (node == 0) {
        return result;
    }
    node = ((FrFontTextRun *)node)->root;
    while (node != 0) {
        child = ((FrFontTextRun *)node)->next;
        node = ((FrFontTextRun *)node)->y;
        while (child != 0) {
            if (((FrFontTextRun *)child)->y != node) {
                break;
            }
            child = ((FrFontTextRun *)child)->next;
        }
        result++;
        node = child;
    }
    return result;
}

/* Lays out the string stored for slot index (D_008815B0) as glyph nodes appended to context. */
/* measured: 724 executable bytes / 736B retail window, fully relocated exact.
   The real three-byte glyph buffer and the neighboring insertion routine's
   branch settings preserve retail stack storage and helper-branch placement.
   Reuse FrFontNode/FrFontGlyph for linked attributes and signed spacing. */
// FUN_002739E0
#pragma push
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
void frFontLayoutSlotText(u8 index, u8 *context)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    s8 character;
    extern s32 strlen(const void *value);
    extern s8 iGpffffa748;
    extern s8 D_0076380C;
    /* A two-byte glyph plus its NUL terminator. */
    s8 glyph[3];
    u8 *text;
    s32 length;
    s32 position;
    s8 *clear;
    s32 remaining;
    s32 width;
    s32 style;
    s8 spacing;
    s64 byte;
    s8 previousStyle;
    u8 attribute;
    u8 *newNode;
    u8 *firstNode;
    u8 *glyphNode;
    FrFontNode *node;
    FrFontNode *linkedNode;
    FrFontNode *attributeNode;
    FrFontGlyph *child;

    text = (u8 *)D_008815B0[index];
    clear = glyph;
    remaining = 3;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear += 1;
            remaining -= 1;
        } while (remaining != 0);
    }
    if (text != NULL) {
        length = strlen(text);
        if (length <= 0) {
            kAssertFail(D_0063BAE8, 0xB63);
        }
        previousStyle = ((FrFontContext *)context)->style;
        position = 0;
        goto text_test;
text_body:
            byte = *(s8 *)(text + position); /* measured: this access-site member rewrite changes instruction bytes. */
            glyph[0] = byte;
            if (byte == 0x20) {
                glyph[0] = -0x7D;
                glyph[1] = -0xA;
            } else {
                glyph[1] = 0;
                /* Preserve the signed-byte extraction without a signed left shift. */
                if ((((s64)((u64)byte << 56) >> 56) & 0xFF) >= 0x80) {
                    position += 1;
                    glyph[1] = *(s8 *)(text + position); /* measured: this access-site member rewrite changes instruction bytes. */
                }
            }
            style = *(s8 *)(context + 0xC); /* measured: this access-site member rewrite changes instruction bytes. */
            if (style != (s32)previousStyle) {
                /* A style transition needs an empty node before the next glyph. */
                node = (FrFontNode *)(u8 *)(u32)((FrFontContext *)context)->list;
                if (node == NULL) {
                    goto create_first_node;
                }
                if (node->glyphs == NULL) {
                    goto apply_attribute;
                }
                newNode = (character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)&iGpffffa748, 0, character, ((FrFontContext *)context)->effect, NULL));
                if (newNode != NULL) {
                    goto link_new_node;
                }
                linkedNode = node;
                goto store_new_node;
link_new_node:
                linkedNode = (FrFontNode *)frFontAppendList(
                    (s32)node, (s32)newNode, 1);
store_new_node:
                node = linkedNode;
                *(u8 **)(context + 0x14) = (u8 *)node; /* measured: this access-site member rewrite changes instruction bytes. */
                goto apply_attribute;
create_first_node:
                firstNode = (character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)&iGpffffa748, 0, character, ((FrFontContext *)context)->effect, NULL));
                if (firstNode != NULL) {
                    goto link_first_node;
                }
                linkedNode = node;
                goto store_first_node;
link_first_node:
                linkedNode = (FrFontNode *)frFontAppendList(
                    (s32)node, (s32)firstNode, 1);
store_first_node:
                node = linkedNode;
                *(u8 **)(context + 0x14) = (u8 *)node; /* measured: this access-site member rewrite changes instruction bytes. */
apply_attribute:
                attribute = (u8)((FrFontContext *)context)->intensity;
                attributeNode = (FrFontNode *)*(u8 **)(context + 0x14); /* measured: this access-site member rewrite changes instruction bytes. */
                if (attributeNode == NULL) {
                    kAssertFail(&D_0063BAE8, 0x69B);
                }
                while (attributeNode != NULL) {
                    attributeNode->unknown_00[2] = attribute;
                    attributeNode = attributeNode->next;
                }
                previousStyle = (s8)style;
            }
            ((FrFontContext *)context)->list =(s32)
                (character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)glyph, style, character, ((FrFontContext *)context)->effect, *(u8 **)(context + 0x14))); /* measured: this access-site member rewrite changes instruction bytes. */
            spacing = D_0076380C;
            glyphNode = (u8 *)(u32)((FrFontContext *)context)->list;
            if (glyphNode == NULL) {
                kAssertFail(&D_0063BAE8, 0x6C3);
            }
            ((FrFontTextRun *)glyphNode)->spacing = spacing;
            width = 0;
            child = (FrFontGlyph *)(u32)((FrFontTextRun *)glyphNode)->firstGlyph;
            while (child != NULL) {
                width += child->advance;
                width += *(s8 *)(glyphNode + 3); /* measured: this access-site member rewrite changes instruction bytes. */
                child = child->next;
            }
            ((FrFontTextRun *)glyphNode)->width = width;
            position += 1;
            goto text_test;
text_test:
        if (position < length) {
            goto text_body;
        }
    }
}
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma pop

extern s8 D_0076380C;
extern s32 strlen(const void *value);



/* Lays out a text string (arg0) as glyph nodes appended to context (arg1). */
/* measured: MATCH. no_branch_likely on with opt_rebuildconditionals off
   preserves the retail positive helper branches and natural relink loop;
   typed node/child locals preserve the field offsets and tail allocation. */
// FUN_00273CC0
#pragma push
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
void frFontLayoutText(u8 *text, u8 *context)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    s8 character;
    extern s32 strlen(const void *value);
    extern s8 iGpffffa748;
    struct FrFontNode3 {
        u8 unknown_00[0x1C];
        s32 flag_1C;
        u8 unknown_20[4];
        struct FrFontNode3 *next;
    };
    struct FrFontChild3 {
        u8 unknown_00[0x28];
        struct FrFontChild3 *next;
    };
    union {
        s32 value;
        s8 bytes[4];
    } glyphBuffer;
    s32 length;
    s32 position;
    s8 *clear;
    s32 remaining;
    s32 width;
    s32 style;
    s8 spacing;
    s64 byte;
    s8 previousStyle;
    u8 intensity;
    u8 *allocated;
    u8 *firstNode;
    u8 *glyphNode;
    struct FrFontNode3 *node;
    struct FrFontNode3 *linkedNode;
    struct FrFontNode3 *attributeNode;
    struct FrFontChild3 *child;

    clear = glyphBuffer.bytes;
    remaining = 3;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear += 1;
            remaining -= 1;
        } while (remaining != 0);
    }
    if (text != NULL) {
        length = strlen(text);
        previousStyle = ((FrFontContext *)context)->style;
        position = 0;
        goto loop_test_30;
loop_body_30:
            byte = *(s8 *)(text + position); /* measured: this access-site member rewrite changes instruction bytes. */
            glyphBuffer.bytes[0] = byte;
            if (byte == 0x20) {
                glyphBuffer.bytes[0] = -0x7D;
                glyphBuffer.bytes[1] = -0xA;
            } else {
                glyphBuffer.bytes[1] = 0;
                if ((((s64)((u64)byte << 56) >> 56) & 0xFF) >= 0x80) {
                    position += 1;
                    glyphBuffer.bytes[1] = *(s8 *)(text + position); /* measured: this access-site member rewrite changes instruction bytes. */
                }
            }
            style = *(s8 *)(context + 0xC); /* measured: this access-site member rewrite changes instruction bytes. */
            if (style != (s32)previousStyle) {
                node = (struct FrFontNode3 *)(u8 *)(u32)((FrFontContext *)context)->list;
                if (node == NULL) {
                    goto null_node_1;
                }
                if (node->flag_1C == 0) {
                    goto common_node_1;
                }
                allocated = (character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)&iGpffffa748, 0, character, ((FrFontContext *)context)->effect, NULL));
                if (allocated != NULL) {
                    goto call_node_1;
                }
                linkedNode = node;
                goto store_node_1;
call_node_1:
                linkedNode = (struct FrFontNode3 *)frFontAppendList(
                    (s32)node, (s32)allocated, 1);
                goto store_node_1;
store_node_1:
                node = linkedNode;
                *(u8 **)(context + 0x14) = (u8 *)node; /* measured: this access-site member rewrite changes instruction bytes. */
                goto common_node_1;
null_node_1:
                firstNode = (character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)&iGpffffa748, 0, character, ((FrFontContext *)context)->effect, NULL));
                if (firstNode != NULL) {
                    goto call_node_2;
                }
                linkedNode = node;
                goto store_node_2;
call_node_2:
                linkedNode = (struct FrFontNode3 *)frFontAppendList(
                    (s32)node, (s32)firstNode, 1);
                goto store_node_2;
store_node_2:
                node = linkedNode;
                *(u8 **)(context + 0x14) = (u8 *)node; /* measured: this access-site member rewrite changes instruction bytes. */
common_node_1:
                intensity = (u8)((FrFontContext *)context)->intensity;
                attributeNode = (struct FrFontNode3 *)*(u8 **)(context + 0x14); /* measured: this access-site member rewrite changes instruction bytes. */
                if (attributeNode == NULL) {
                    kAssertFail(&D_0063BAE8, 0x69B);
                }
                while (attributeNode != NULL) {
                    ((FrFontTextRun *)attributeNode)->intensity = intensity;
                    attributeNode = attributeNode->next;
                }
                previousStyle = (s8)style;
            }
            ((FrFontContext *)context)->list =(s32)
                (character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)glyphBuffer.bytes, style, character, ((FrFontContext *)context)->effect, *(u8 **)(context + 0x14))); /* measured: this access-site member rewrite changes instruction bytes. */
            spacing = D_0076380C;
            glyphNode = (u8 *)(u32)((FrFontContext *)context)->list;
            if (glyphNode == NULL) {
                kAssertFail(&D_0063BAE8, 0x6C3);
            }
            ((FrFontTextRun *)glyphNode)->spacing = spacing;
            width = 0;
            child = (struct FrFontChild3 *)(u32)((FrFontTextRun *)glyphNode)->firstGlyph;
            while (child != NULL) {
                width += ((FrFontGlyphData *)child)->advance;
                width += *(s8 *)(glyphNode + 3); /* measured: this access-site member rewrite changes instruction bytes. */
                child = child->next;
            }
            ((FrFontTextRun *)glyphNode)->width = width;
            position += 1;
            goto loop_test_30;
loop_test_30:
        if (position < length) {
            goto loop_body_30;
        }
    }
}
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma pop
/* Applies pending text work: when active, builds the text list from the string buffer, appends it, sets its codes and height, then applies the pending values. */
// FUN_00273F70
/* measured: full frFontSplitRun recipe stack. */
#pragma push
#pragma optimization_level 1
#pragma opt_common_subs on
void frFontUpdateTextWork(u8 *context)
{
    s8 character;
    extern u8 iGpffffa748;
    struct FrFontNode2 {
        u16 value_00;
        u8 code_02;
        u8 unknown_03;
        u32 value_04;
        u32 value_08;
        u8 unknown_0C[0x10];
        u32 flag_1C;
        u8 unknown_20[4];
        struct FrFontNode2 *next;
    };
    struct FrFontWork2 {
        u32 value_00;
        u32 value_04;
        u8 unknown_08[5];
        s8 code_0D;
        s8 code_0E;
        u8 code_0F;
        u8 unknown_10[4];
        struct FrFontNode2 *list_14;
        u8 unknown_18[4];
        s8 active_1C;
        s8 pending_1D;
        s16 height_1E;
    };
    struct FrFontWork2 *work;
    s16 height;
    struct FrFontNode2 *node;
    struct FrFontNode2 *list;
    struct FrFontNode2 *updated;
    u8 code;
    u32 pendingValue;
    u8 *result;

    work = (struct FrFontWork2 *)context;
    node = work->list_14;
    if ((node != NULL) && (node->flag_1C == 0)) {
        work->active_1C = 0;
    }
    if (work->active_1C == 0) {
        goto done;
    }
    list = work->list_14;
    result = (u8 *)(character = work->code_0D, frFontCreateTextList(&iGpffffa748, 0, character, work->code_0E, NULL));
    if (result == NULL) {
        updated = list;
        goto call_after;
    }
    updated = (struct FrFontNode2 *)frFontAppendList((int)list, (int)result, 1);
    goto call_after;
call_after:
    list = updated;
    work->list_14 = list;
    code = work->code_0F;
    if (list != NULL) {
        goto loop_check;
    }
    kAssertFail(&D_0063BAE8, 0x69B);
    goto loop_check;
loop_body:
    list->code_02 = code;
    list = list->next;
loop_check:
    if (list != NULL) {
        goto loop_body;
    }
    height = work->height_1E;
    node = work->list_14;
    if (node == NULL) {
        kAssertFail(&D_0063BAE8, 0x6A7);
    }
    node->value_00 = (u32)(s32)height;
    work->active_1C = 0;
done:
    if (work->pending_1D == 0) {
        goto return_point;
    }
    pendingValue = work->value_00;
    node = work->list_14;
    node->value_04 = pendingValue;
    pendingValue = work->value_04;
    node = work->list_14;
    node->value_08 = pendingValue;
    work->pending_1D = 0;
return_point:
    return;
}
/* measured: close recipe stack. */
#pragma optimization_level 2
#pragma pop




/* Builds a text chain from a descriptor (data) and returns its head (the value stored at the context's +0x14). */
/* measured: the neighboring positive insertion-branch recipe, natural u32
   byte temporary and real three-byte glyph buffer close the old placement
   and register floor. Keep the full signed pair for the C080 threshold.
   All 1212 executable bytes and 32 relocations match; the final word is
   alignment. Six real command groups exist; diagnostics are not guards. */
// FUN_002740B0
#pragma push
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
u8 *frFontBuildText(void *data)
{
    /* fr_font_objects.h records the layouts; only individually measured instruction-byte culprits remain raw below. */

    s8 character;
    s32 style;
    typedef int (*FrFontCommand)();
    typedef struct FrFontCommandGroup {
        FrFontCommand *handlers;
        s32 count;
    } FrFontCommandGroup;
    extern void frFontClearStateFlags(void);
    extern u8 iGpffffa748;
    extern s32 D_00763800;
    FrFontScript *script;
    u8 *context;
    u32 code;
    s32 command;
    s32 index;
    FrFontCommandGroup *group;
    s32 result;
    FrFontNode *node;
    FrFontNode *linked;
    u8 *allocated;
    s16 height;
    s8 spacing;
    u32 duration;
    s32 width;
    s32 pair;
    FrFontGlyph *child;
    s8 glyph[3];

    context = data;
    script = data;
    if (((script->data[0] & 0xF0) != 0xF0) && (script->data[1] == 5)) {
        script->pos += 4;
    }
    frFontClearStateFlags();
    D_00763810 = (s16)(D_00763810 | 1) & ~2;
    while ((code = script->data[script->pos++]) != 0) {
        if ((code & 0xF0) == 0xF0) {
            command = (code << 8) | script->data[script->pos++];
            group = (FrFontCommandGroup *)(D_0063BA00 + (((command & 0xE0) >> 5) * 8));
            index = command & 0x1F;
            if (group->count < index) {
                kAssertFail(D_00748110, 0xA5);
            }
            if ((command & 0xFF) <= 0) {
                kAssertFail(D_00748100, 0xA6);
            }
            result = group->handlers[index](command, script);
            script->pos += (((command & 0xF00) >> 8) - 1) * 2;
            if (result != 0) {
                result = 1;
            } else {
                if (((FrFontContext *)context)->active == 0) {
                    *(s8 *)(context + 0x1C) = 1; /* measured: this access-site member rewrite changes instruction bytes. */
                }
                result = 0;
            }
            if (result != 0) {
                break;
            }
        } else if (code == 10) {
            if (D_00763810 & 4) {
                ((FrFontContext *)context)->y += D_00763800 * 8;
                ((FrFontContext *)context)->active = 1;
                ((FrFontContext *)context)->pendingPosition = 1;
            }
        } else {
            node = (FrFontNode *)(u32)((FrFontContext *)context)->list;
            if ((node != NULL) && (node->glyphs == NULL)) {
                ((FrFontContext *)context)->active = 0;
            }
            if (((FrFontContext *)context)->active != 0) {
                node = *(FrFontNode **)(context + 0x14); /* measured: this access-site member rewrite changes instruction bytes. */
                allocated = (character = ((FrFontContext *)context)->palette, frFontCreateTextList(&iGpffffa748, 0, character, ((FrFontContext *)context)->effect, NULL));
                if (allocated != NULL) {
                    goto link_node;
                }
                linked = node;
                goto store_node;
link_node:
                linked = (FrFontNode *)frFontAppendList((s32)node, (s32)allocated, 1);
store_node:
                node = linked;
                *(FrFontNode **)(context + 0x14) = node; /* measured: this access-site member rewrite changes instruction bytes. */
                frFontSetListFlag((int)node, *(u8 *)(context + 0xF)); /* measured: this access-site member rewrite changes instruction bytes. */
                height = ((FrFontContext *)context)->height;
                node = *(FrFontNode **)(context + 0x14); /* measured: this access-site member rewrite changes instruction bytes. */
                if (node == NULL) {
                    kAssertFail(D_0063BAE8, 0x6A7);
                }
                *(s16 *)node = height;
                *(s8 *)(context + 0x1C) = 0; /* measured: this access-site member rewrite changes instruction bytes. */
            }
            if (((FrFontContext *)context)->pendingPosition != 0) {
                ((FrFontTextRun *)((u8 *)(u32)((FrFontContext *)context)->list))->x = ((FrFontContext *)context)->x;
                ((FrFontTextRun *)((u8 *)(u32)((FrFontContext *)context)->list))->y = ((FrFontContext *)context)->y;
                *(s8 *)(context + 0x1D) = 0; /* measured: this access-site member rewrite changes instruction bytes. */
            }
            if ((s32)code < 0x80) {
                if (code == 0x20) {
                    glyph[0] = 0x83;
                    glyph[1] = 0xF6;
                    glyph[2] = 0;
                } else {
                    glyph[0] = code;
                    glyph[1] = 0;
                }
                *(u8 **)(context + 0x14) = (style = ((FrFontContext *)context)->style, character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)glyph, style, character, ((FrFontContext *)context)->effect, *(u8 **)(context + 0x14))); /* measured: this access-site member rewrite changes instruction bytes. */
            } else {
                pair = (code << 8) | script->data[script->pos++];
                if (pair < 0xC080) {
                    glyph[0] = (pair & 0xFF00) >> 8;
                    glyph[1] = pair;
                    glyph[2] = 0;
                    *(u8 **)(context + 0x14) = (style = ((FrFontContext *)context)->style, character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)glyph, style, character, ((FrFontContext *)context)->effect, *(u8 **)(context + 0x14))); /* measured: this access-site member rewrite changes instruction bytes. */
                } else {
                    pair -= 0x4000;
                    glyph[0] = (pair & 0xFF00) >> 8;
                    glyph[1] = pair;
                    glyph[2] = 0;
                    *(u8 **)(context + 0x14) = (character = ((FrFontContext *)context)->palette, frFontCreateTextList((u8 *)glyph, 8, character, ((FrFontContext *)context)->effect, *(u8 **)(context + 0x14))); /* measured: this access-site member rewrite changes instruction bytes. */
                }
            }
            spacing = (-D_00763808[(u8)((FrFontContext *)context)->style] * 2) / 32;
            node = *(FrFontNode **)(context + 0x14); /* measured: this access-site member rewrite changes instruction bytes. */
            if (node == NULL) {
                kAssertFail(D_0063BAE8, 0x6C3);
            }
            node->line_height = spacing;
            width = 0;
            child = node->glyphs;
            while (child != NULL) {
                width += child->advance;
                width += node->line_height;
                child = child->next;
            }
            ((FrFontTextRun *)node)->width = width;
            duration = ((FrFontContext *)context)->duration;
            node = *(FrFontNode **)(context + 0x14); /* measured: this access-site member rewrite changes instruction bytes. */
            if (node == NULL) {
                kAssertFail(D_0063BAE8, 0x735);
            }
            ((FrFontTextRun *)node)->depth.bits = duration >> 4;
        }
    }
    D_00763810 = (s16)(D_00763810 & ~1) | 2;
    return (u8 *)(u32)((FrFontContext *)context)->list;
}
#pragma pop


/* Forward the allocated chain explicitly; callers consume the return value. */
// FUN_00274570
u8 *frFontBuildTextSimple(u32 x, u32 y, u32 style, u32 palette,
                   u32 effect, u32 intensity, u32 stream, u32 list)
{
    return frFontBuildTextFull(x, y, 0, style, palette, effect, intensity, stream, list);
}

/* Builds a text chain from nine parameters: packs them into a descriptor (the third shifted by 4), sets mode 0, and calls frFontBuildText. */
// FUN_002745C0
u8 *frFontBuildTextFull(u32 x, u32 y, u32 duration, u32 style,
                   u32 palette, u32 effect, u32 intensity, u32 stream,
                   u32 list)
{
    struct {
        u32 f00;
        u32 f04;
        u32 f08;
        u8 f0c;
        u8 f0d;
        u8 f0e;
        u8 f0f;
        u32 f10;
        u32 f14;
        u32 f18;
        u8 f1c;
        u8 f1d;
        u16 f1e;
    } data;

    data.f00 = x;
    data.f04 = y;
    data.f08 = duration << 4;
    data.f0c = style;
    data.f0d = palette;
    data.f0e = effect;
    data.f0f = intensity;
    data.f10 = stream;
    data.f14 = list;
    data.f18 = 0;
    data.f1c = 1;
    data.f1d = 1;
    data.f1e = 0x20;
    frFontSetMode(0);
    return frFontBuildText(&data);
}


/* Clears the state flag word. */
// FUN_00274640
void frFontClearStateFlags(void)
{
    D_007637F8 = 0;
}

u32 frFontFlagMask = 0xffffffff;

/* Masks `value` with the font flag mask (all bits set by default). */
// FUN_00274650
u32 frFontMaskFlags(u32 value)
{
    return frFontFlagMask & value;
}

/* Sets (enable != 0) or clears the given bits in the state flag word. */
// FUN_00274660
void frFontSetStateBits(u32 bits, int enable)
{
    if (enable != 0) {
        D_007637F8 |= bits;
    } else {
        D_007637F8 &= ~bits;
    }
}

/* Returns the current mode word. */
// FUN_002746A0
u32 frFontGetMode(void)
{
    return D_00764594;
}

/* Sets the mode word. */
// FUN_002746B0
void frFontSetMode(u32 mode)
{
    D_00764594 = mode;
}

/* Runs a font command script from its current position until a terminator; a nonzero param_2 runs only that command. Returns 0. */
/* measured candidate archived at build/WBYList_frFont_746e0_candidate5.c.
   It compiled as MISMATCH at normalized_diff 102 with object 464B/window
   512B; fndiff reported 50 differing words at byte offsets:
   36,40,60,76,84,92,108,324,332,336,344,348,356,360,364,368,372,376,
   380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,
   448,452,456,464,468,472,476,480,484,488,492,496. Ruled out raw-pointer
   forms (nd363-376 and oversized frames), named callback-result/in-place
   variants (nd104), and direct loop/boolean forms. Bare INCLUDE_ASM is
   retained because this candidate remains above the nd<=25 park threshold. */
// FUN_002746E0
s8 frFontRunScript(void *context, int onlyCommand)
{
    typedef int (*FrFontCommand)();
    typedef struct FrFontCommandGroup {
        FrFontCommand *handlers;
        s32 count;
    } FrFontCommandGroup;
    FrFontScript *script;
    FrFontCommandGroup *group;
    s32 code;
    s32 command;
    s32 result;

    script = (FrFontScript *)context;
    if (((((FrFontScript *)context)->data[0] & 0xf0) != 0xf0) &&
        (((FrFontScript *)context)->data[1] == 5)) {
        ((FrFontScript *)context)->pos += 4;
    }
    D_007637F8 = 0;
    result = 0;
    while ((code = script->data[script->pos++]) != 0) {
        if ((code & 0xf0) == 0xf0) {
            result = 0;
            command = (code << 8) | script->data[script->pos++];
            if ((onlyCommand == 0) || (command == onlyCommand)) {
                group = (FrFontCommandGroup *)
                    (D_0063BA00 + (((command & 0xe0) >> 5) * 8));
                if (group->count < (command & 0x1f)) {
                    kAssertFail(D_00748110, 0xa5);
                }
                if ((command & 0xff) <= 0) {
                    kAssertFail(D_00748100, 0xa6);
                }
                result =
                    group->handlers[command & 0x1f](command, script);
            }
            script->pos += ((((command & 0xf00) >> 8) - 1) * 2);
            if (result != 0) {
                result = 1;
            } else {
                switch (command) {
                case 0xf124:
                    result = 1;
                    break;
                default:
                    result = 0;
                    break;
                }
            }
            if (result != 0) {
                break;
            }
            continue;
        }
        if (code != 0xa) {
            result = (code < 0x80);
            if (result == 0) {
                script->pos += 1;
            }
        }
    }
    return 0;
}
/* Runs one command with the given mode: saves the mode, runs the command through frFontRunScript, then restores it. */
// FUN_002748E0
s8 frFontRunCommand(int stream, int mode, int command)
{
    struct {
        u8 f00[0x10];
        u32 f10;
        u32 f14;
        u32 f18;
        u8 f1c;
        u8 f1d;
        u16 f1e;
    } data;
    u32 old;
    s8 result;

    memset(&data, 0, 0x20);
    data.f10 = stream;
    data.f18 = 0;
    data.f1c = 1;
    data.f1d = 1;
    data.f1e = 0x20;
    old = D_00764594;
    D_00764594 = mode;
    result = frFontRunScript(&data, command);
    D_00764594 = old;
    return result;
}

/* Starts the font subsystem: creates the task pool, initialises the manager, and registers the cache maintenance and destroy callbacks. */
// FUN_00274970
void frFontStartup(void)
{
    int v;

    nmMesWindowResetRecords();
    v = fclBankManagerCreate();
    *(int *)v = (s32)kwlnTaskCreate((const void *)(&D_00763840), 0xC8, 0, 0, fclBankManagerUpdate, 0, (u8 *)(0));
    frFontInitManager(0x100, 0x100);
    kwlnTaskCreate((const void *)(&D_00763848), 0, 0, 0, frFontMaintainCacheTask, frFontTaskDestroy, (u8 *)(0));
    fclMiscCreateAssistTask();
}

