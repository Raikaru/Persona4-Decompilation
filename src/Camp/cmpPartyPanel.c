#include "operand_order_internal.h"
#include "byte_address_internal.h"
/* Original translation unit cmpPartyPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdktask.h"
#include "type.h"
#include "btl_shuffle_draw_internal.h"
#include "rw_camera_internal.h"

void kAssertFail(void*, s32);
void sdkSpriteRelease(u8 *node);
void chkmemAllocSiteTag(void* file, s32 line);

void memset(void* dest, s32 value, s32 size);
void cmpPartyPanelDraw(u8*, u8*);
s32 cmpPartyPanelTaskStep(u8*);
void cmpPartyPanelTaskDestroy(u8*);
s32 cmpPartyPanelStepRowMotion(u8*);
void cmpPartyPanelDrawRow(u8*, s64 );
void sdkRenderStateSetDefault(void);
void sdkSpriteDrawOnceAt(s32, s32, f32, f32,
                   u8, u8, u8, u8);
u32 datCalcGetHpById(s16);
u16 datCalcMaxHpById(s16);
u32 datCalcGetSpById(s16);
u16 datCalcMaxSpById(s16);
u8* kwlnGetCamera(void);
s16 datBuildPartyIdList(s16* ids);
u8 *sdkSpriteRequestLoad(const char *name);
s32 sprintf(char *dst, const char *format, ...);
u32 hMaestroDecodeIsReady(s16 *state);
void PrimAppendNode(u8 *list, u8 *node);
extern u8 D_0064E2A0[];
extern u8 D_0064E2C0[];
extern u8 D_00794960[];
extern f32 D_008872F8[];
extern void (*D_00887300[])(u32, u32);
extern s32 (*D_00887310[])(s32, void*, s32);
extern u8 D_0064E290[];
extern u8 D_0064E2E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void* ptr);

typedef struct { f32 x, y; } Vec2f;

/* Reuse the existing SDK Sky2 fields: four consecutive 0x40-byte vertices.
 * Integer color stores preserve the original floating-point bit patterns. */
typedef struct { BtlShuffleSkyFields vertices[4]; } CmpPartyPanelGaugePacket;



typedef struct {
    Vec2f start;
    Vec2f end;
    Vec2f current;
    s16 frame;
    s16 duration;
} CmpPartyPanelMotion;
typedef struct {
    CmpPartyPanelMotion motion;
    u8 *sprite;
    s32 ready;
    s16 id;
} CmpPartyPanelRow;
typedef struct {
    u32 next;
    u32 tail;
    void (*callback)(u8 *, u8 *);
    u32 unknown0c;
    void *context;
    u8 unknown14[0x1c];
} CmpPartyPanelNode;
typedef struct {
    u16 flags;
    s32 state;
    s16 changed;
    s16 count;
    u8 *sprite;
    CmpPartyPanelRow rows[4];
    CmpPartyPanelNode node;
} CmpPartyPanelWork;
typedef char CmpPartyPanelRowSize[sizeof(CmpPartyPanelRow)==0x28?1:-1];
typedef char CmpPartyPanelWorkSize[sizeof(CmpPartyPanelWork)==0xe0?1:-1];

/* Set a row transition, using the current position when the start is omitted. */
// FUN_00362FD0
void cmpPartyPanelSetRowMotion(u8* motion, f32* start, f32* target, s16 duration) {
    Vec2f *startPosition = (Vec2f *)start;
    Vec2f *targetPosition = (Vec2f *)target;
    if (start == NULL) {
        ((CmpPartyPanelMotion *)motion)->start = ((CmpPartyPanelMotion *)motion)->current;
    } else {
        ((CmpPartyPanelMotion *)motion)->start = *startPosition;
    }
    if (target == NULL) {
        kAssertFail(D_0064E290, 0x92);
    }
    ((CmpPartyPanelMotion *)motion)->end = *targetPosition;
    ((CmpPartyPanelMotion *)motion)->current = ((CmpPartyPanelMotion *)motion)->start;
    ((CmpPartyPanelMotion *)motion)->frame = 0;
    ((CmpPartyPanelMotion *)motion)->duration = duration;
}


/* Draw the unfilled portion of a slanted HP/SP gauge at the supplied position and ratio. */
// FUN_00363080
void cmpPartyPanelDrawGauge(f32 originX, f32 originY, f32 fillRatio) {
    CmpPartyPanelGaugePacket packet;
    f32 z;
    f32 x;
    f32 y;
    f32 depth;
    f32 rightX;
    f32 slantedY;
    f32 leftX;
    f32 reciprocalDepth;
    f32 unfilledRatio;

    x = originX;
    y = originY;
    z = fillRatio;
    depth = D_008872F8[0];
    /* The lightweight SDK layout keeps this Camp TU independent of the full
       camera header configuration; bacamera.h establishes nearPlane at +0x80. */
    reciprocalDepth = 1.0f / ((RwCamera *)kwlnGetCamera())->nearPlane;
    leftX = ((41.0f) * (z));
    rightX = ((x) + (leftX));
    leftX = rightX;
    rightX = operandOrderAddFloat(3.0f, leftX);
    leftX = rightX;
    packet.vertices[0].scrVertex.x = leftX;
    unfilledRatio = 1.0f - z;
    slantedY = unfilledRatio;
    slantedY = operandOrderMultiply(20.0f, slantedY);
    slantedY = operandOrderAddFloat(y, slantedY);
    packet.vertices[0].scrVertex.y = slantedY;
    packet.vertices[0].scrVertex.z = depth;
    *(s32 *)&packet.vertices[0].color.r = 0x41A80000;
    *(s32 *)&packet.vertices[0].color.g = 0x41E80000;
    *(s32 *)&packet.vertices[0].color.b = 0x42080000;
    *(s32 *)&packet.vertices[0].color.a = 0x437F0000;
    packet.vertices[0].recipZ = reciprocalDepth;
    rightX = 3.0f + (41.0f + x);
    packet.vertices[1].scrVertex.x = rightX;
    packet.vertices[1].scrVertex.y = y;
    packet.vertices[1].scrVertex.z = depth;
    *(s32 *)&packet.vertices[1].color.r = 0x41A80000;
    *(s32 *)&packet.vertices[1].color.g = 0x41E80000;
    *(s32 *)&packet.vertices[1].color.b = 0x42080000;
    *(s32 *)&packet.vertices[1].color.a = 0x437F0000;
    packet.vertices[1].recipZ = reciprocalDepth;
    packet.vertices[2].scrVertex.x = leftX;
    packet.vertices[2].scrVertex.y = 4.0f + slantedY;
    packet.vertices[2].scrVertex.z = depth;
    *(s32 *)&packet.vertices[2].color.r = 0x41A80000;
    *(s32 *)&packet.vertices[2].color.g = 0x41E80000;
    *(s32 *)&packet.vertices[2].color.b = 0x42080000;
    *(s32 *)&packet.vertices[2].color.a = 0x437F0000;
    packet.vertices[2].recipZ = reciprocalDepth;
    packet.vertices[3].scrVertex.x = rightX;
    packet.vertices[3].scrVertex.y = 4.0f + y;
    packet.vertices[3].scrVertex.z = depth;
    *(s32 *)&packet.vertices[3].color.r = 0x41A80000;
    *(s32 *)&packet.vertices[3].color.g = 0x41E80000;
    *(s32 *)&packet.vertices[3].color.b = 0x42080000;
    *(s32 *)&packet.vertices[3].color.a = 0x437F0000;
    packet.vertices[3].recipZ = reciprocalDepth;
    D_00887300[0](1, 0);
    D_00887310[0](4, &packet, 4);
}


/* 820/832 bytes; sixteen resolved relocations and twelve zero alignment bytes.
 * The sprite API keeps coordinates before byte colors, as its core does.
 * Snapshot the row position and unsigned HP/SP values before drawing. */
// FUN_00363200
void cmpPartyPanelDrawRow(u8* work, s64 rowIndex)
{
    s32 rowOffset = (s16)rowIndex * 0x28;
    s16 id = ((CmpPartyPanelWork *)((u8*)(rowOffset + (s32)work)))->rows[0].id;
    s32 gaugeSprite = *(s32 *)&((CmpPartyPanelWork *)work)->sprite;
    s32 portraitSprite = *(s32 *)&((CmpPartyPanelWork *)((u8*)(rowOffset + (s32)work)))->rows[0].sprite;

    if (((CmpPartyPanelWork *)((u8*)(rowOffset + (s32)work)))->rows[0].ready != 0) {
        Vec2f xy;
        f32 y;
        u32 hpCur;
        u32 hpMax;
        u32 spCur;
        u32 spMax;
        f32 ratio;
        f32 y35;
        f32 x13;
        f32 y39;

        if (gaugeSprite == 0) {
            kAssertFail(D_0064E290, 0x108);
        }
        if (portraitSprite == 0) {
            kAssertFail(D_0064E290, 0x109);
        }
        xy = ((CmpPartyPanelWork *)(byteAddressAdd(rowOffset, work)))->rows[0].motion.current;
        hpCur = datCalcGetHpById(id) & 0xFFFF;
        hpMax = datCalcMaxHpById(id) & 0xFFFF;
        spCur = datCalcGetSpById(id) & 0xFFFF;
        spMax = datCalcMaxSpById(id) & 0xFFFF;
        y = xy.y;
        sdkSpriteDrawOnceAt(portraitSprite, 0, xy.x, y, 0xFF, 0xFF, 0xFF, 0xFF);
        sdkSpriteDrawOnceAt(gaugeSprite, 0, 8.0f + xy.x, 31.0f + y,
                      0xFF, 0xFF, 0xFF, 0xFF);
        ratio = (f32)hpCur / (f32)hpMax;
        y35 = 35.0f + y;
        x13 = 13.0f + xy.x;
        sdkSpriteDrawOnceAt(gaugeSprite, 1, x13, y35, 0xFF, 0xFF, 0xFF, 0xFF);
        cmpPartyPanelDrawGauge(x13, y35, ratio);
        y39 = 39.0f + y;
        sdkSpriteDrawOnceAt(gaugeSprite, 2, x13, y39, 0xFF, 0xFF, 0xFF, 0xFF);
        ratio = (f32)spCur / (f32)spMax;
        cmpPartyPanelDrawGauge(x13, y39, ratio);
    }
}

/* Advance ready row motions and draw all live party rows when visibility bit 0 is set. */
// FUN_00363540
/* measured: earlier CmpPartyPanelWork typing changed 150 instruction bytes; current typed-local/member forms retain MATCH. */
void cmpPartyPanelDraw(u8* unusedNode, u8* work) {
    CmpPartyPanelWork *menu = (CmpPartyPanelWork *)work;
    s32 motionIndex;
    s32 drawIndex;
    u8* rowBase;

    for (motionIndex = 0; motionIndex < menu->count; motionIndex++) {
        rowBase = work + (s16)motionIndex * 0x28;
        if (((CmpPartyPanelWork *)(rowBase))->rows[0].ready != 0) {
            cmpPartyPanelStepRowMotion(rowBase + 0x10);
        }
    }
    if (menu->flags & 1) {
        sdkRenderStateSetDefault();
        for (drawIndex = 0; drawIndex < menu->count; drawIndex++) {
            cmpPartyPanelDrawRow(work, (s64)(s16)drawIndex);
        }
    }
}


/* Recovered work layout: 0x10-byte header, four 0x28-byte rows, then the
 * 0x30-byte ordering-table node. Animation fields are also read by 00362F00.
 * 00353B50 writes only the compacted live roster. The four-entry comparison
 * below intentionally retains retail's read of the unwritten stack tail,
 * as explicitly authorized for retail recovery on 2026-10-07. Do not clear
 * that tail or limit the removal scan to the compacted roster count.
 * If all four IDs compare equal after a shrink, changed reaches 4. The
 * offset-based update below then aliases the real ordering node at +0xB0
 * inside the 0xE0 allocation; it does not refer to a fifth stored party row.
 * Whole-owner configured compile: 2772 exact live bytes, 12 zero tail bytes;
 * the seven case-table entries at 007528E0 and all six siblings are exact. */
#pragma opt_loop_invariants on
/* Repeated row placement shares the signed roster-count contract. */
/* Place one party row using the bottom-aligned row count and index. */
static inline void cmpPartyPanelSetRowPosition(Vec2f *position, f32 x, s16 count, s32 index)
{
    position->x = x;
    position->y = 338.0f - 63.0f * (f32)((count - 1) - index);
}

/* Track party roster changes, load row sprites and animate row insertion/removal. */
// FUN_00363610
s32 cmpPartyPanelTaskStep(u8 *task)
{
    CmpPartyPanelWork *work = (CmpPartyPanelWork *)((SdkTask *)task)->work;
    s16 roster[4];
    Vec2f position;
    Vec2f startPosition;
    Vec2f removedPosition;
    Vec2f shiftedPosition;
    Vec2f replacedPosition;
    CmpPartyPanelRow removed;
    char initialName[256];
    char addedName[256];
    char replacedName[256];
    s32 ready, count;
    s16 id;
    CmpPartyPanelRow *row;

    work->node.next = 0;
    work->node.tail = 0;
    PrimAppendNode(D_00794960, (u8 *)&work->node);
    switch (work->state) {
    case 0: {
        s32 i;
        work->sprite = sdkSpriteRequestLoad((const char *)D_0064E2C0);
        work->count = datBuildPartyIdList(roster);
        for (i = 0; i < work->count; i++) {
            cmpPartyPanelSetRowPosition(&position, (f32)565, work->count, i);
            id = roster[i];
            cmpPartyPanelSetRowMotion((u8 *)&work->rows[i].motion, &position.x, &position.x, 0);
            work->rows[i].id = id;
            work->rows[i].ready = 0;
            if (id != 0) {
                sprintf(initialName, (const char *)D_0064E2A0, id);
                work->rows[i].sprite = sdkSpriteRequestLoad(initialName);
                if (work->rows[i].sprite == NULL) {
                    kAssertFail(D_0064E290, 0x166);
                }
            }
        }
        work->flags |= 1;
        work->state = 1;
        break;
    }
    case 1:
        if (hMaestroDecodeIsReady((s16 *)work->sprite) == 0) {
            break;
        }
        work->state = 2;
        /* fallthrough */
    case 2: {
        s32 i = 0;
        ready = 0;
        for (; i < work->count; i++) {
            if (hMaestroDecodeIsReady((s16 *)work->rows[i].sprite) != 0) {
                work->rows[i].ready = 1;
                ready++;
            }
        }
        if (ready == work->count) {
            work->state = 3;
            for (i = 0; i < work->count; i++) {
                cmpPartyPanelSetRowPosition(&startPosition, (f32)565, work->count, i);
                cmpPartyPanelSetRowMotion((u8 *)&work->rows[i].motion, NULL, &startPosition.x, 8);
            }
        }
        break;
    }
    case 3: {
        s32 i;
        if (work->flags & 2) {
            work->state = 6;
            break;
        }
        for (i = 0; i < work->count; i++) {
            if (work->rows[i].motion.frame < work->rows[i].motion.duration) {
                return 0;
            }
        }
        count = datBuildPartyIdList(roster);
        if (work->count != count) {
            if (count < work->count) {
                s32 changed;
                for (changed = 0; changed < 4; changed++) {
                    if (work->rows[changed].id != roster[changed]) {
                        break;
                    }
                }
                cmpPartyPanelSetRowPosition(&position, 640.0f, work->count, changed);
                row = (CmpPartyPanelRow *)(byteAddressAdd(changed * sizeof(CmpPartyPanelRow), (u8 *)work) + 0x10);
                row->motion.start = row->motion.current;
                row->motion.end = position;
                row->motion.current = row->motion.start;
                row->motion.frame = 0;
                row->motion.duration = 8;
                work->changed = changed;
                work->state = 4;
            } else {
                s32 changed;
                s32 j;
                for (changed = 0; changed < 4; changed++) {
                    if (work->rows[changed].id != roster[changed]) {
                        break;
                    }
                }
                for (j = work->count; changed < j; j--) {
                    work->rows[j] = work->rows[j - 1];
                }
                work->count++;
                cmpPartyPanelSetRowPosition(&position, 640.0f, work->count, changed);
                id = roster[changed];
                cmpPartyPanelSetRowMotion((u8 *)&work->rows[changed].motion, &position.x, &position.x, 0);
                work->rows[changed].id = id;
                work->rows[changed].ready = 0;
                if (id != 0) {
                    sprintf(addedName, (const char *)D_0064E2A0, id);
                    work->rows[changed].sprite = sdkSpriteRequestLoad(addedName);
                    if (work->rows[changed].sprite == NULL) {
                        kAssertFail(D_0064E290, 0x166);
                    }
                }
                work->state = 2;
            }
        } else {
            s32 changed;
            for (changed = 0; changed < count; changed++) {
                if (work->rows[changed].id != roster[changed]) {
                    break;
                }
            }
            if (changed < count) {
                cmpPartyPanelSetRowPosition(&position, 640.0f, work->count, changed);
                row = (CmpPartyPanelRow *)(byteAddressAdd(changed * sizeof(CmpPartyPanelRow), (u8 *)work) + 0x10);
                row->motion.start = row->motion.current;
                row->motion.end = position;
                row->motion.current = row->motion.start;
                row->motion.frame = 0;
                row->motion.duration = 8;
                work->changed = changed;
                work->state = 5;
            }
        }
        break;
    }
    case 4: {
        s32 j;
        row = &work->rows[work->changed];
        if (!(row->motion.frame < row->motion.duration)) {
            removed = *row;
            work->count--;
            for (j = work->changed; j < work->count; j++) {
                work->rows[j] = work->rows[j + 1];
            }
            work->rows[j] = removed;
            work->rows[j].id = 0;
            work->rows[j].ready = 0;
            if (work->rows[j].sprite != NULL) {
                sdkSpriteRelease(work->rows[j].sprite);
                work->rows[j].sprite = NULL;
            }
            removedPosition = work->rows[j].motion.current;
            cmpPartyPanelSetRowMotion((u8 *)&work->rows[j].motion, &removedPosition.x, &removedPosition.x, 0);
            {
                s32 i;
                for (i = 0; i < work->count; i++) {
                    cmpPartyPanelSetRowPosition(&shiftedPosition, (f32)565, work->count, i);
                    cmpPartyPanelSetRowMotion((u8 *)&work->rows[i].motion, NULL, &shiftedPosition.x, 8);
                }
            }
            work->state = 3;
        }
        break;
    }
    case 5: {
        s32 changed;
        row = &work->rows[work->changed];
        if (!(row->motion.frame < row->motion.duration)) {
            datBuildPartyIdList(roster);
            row = &work->rows[work->changed];
            row->id = 0;
            row->ready = 0;
            if (row->sprite != NULL) {
                sdkSpriteRelease(row->sprite);
                row->sprite = NULL;
            }
            replacedPosition = row->motion.current;
            cmpPartyPanelSetRowMotion((u8 *)&row->motion, &replacedPosition.x, &replacedPosition.x, 0);
            changed = work->changed;
            cmpPartyPanelSetRowPosition(&position, 640.0f, work->count, changed);
            id = roster[changed];
            row = &work->rows[changed];
            cmpPartyPanelSetRowMotion((u8 *)&row->motion, &position.x, &position.x, 0);
            row->id = id;
            row->ready = 0;
            if (id != 0) {
                sprintf(replacedName, (const char *)D_0064E2A0, id);
                row->sprite = sdkSpriteRequestLoad(replacedName);
                if (row->sprite == NULL) {
                    kAssertFail(D_0064E290, 0x166);
                }
            }
            work->state = 2;
        }
        break;
    }
    case 6:
        return -1;
    }
    return 0;
}
#pragma opt_loop_invariants off


/* Release the shared gauge sprite and each party portrait, then free the task work. */
// FUN_003640F0
/* measured: earlier CmpPartyPanelWork typing changed 103 instruction bytes; current typed-local/member forms retain MATCH. */
void cmpPartyPanelTaskDestroy(u8* task) {
    u8* work = ((SdkTask *)task)->work;
    CmpPartyPanelWork *menu = (CmpPartyPanelWork *)work;
    s32 rowIndex;
    u8* rowBase;
    u8* spriteSlot;

    if (*(s32 *)&menu->sprite != 0) {
        sdkSpriteRelease(*(void* *)&menu->sprite);
        *(s32 *)&menu->sprite = 0;
    }
    for (rowIndex = 0; rowIndex < menu->count; rowIndex++) {
        rowBase = work + rowIndex * 0x28;
        spriteSlot = rowBase + 0x2C;
        if (*(s32 *)&((CmpPartyPanelWork *)(rowBase))->rows[0].sprite != 0) {
            sdkSpriteRelease(*(void* *)&((CmpPartyPanelWork *)(rowBase))->rows[0].sprite);
            *(s32*)spriteSlot = 0;
        }
    }
    (*jtbl_008873EC)(work);
}


/* Allocate the four-row panel and register its task and ordering-table draw callback. */
// FUN_003641A0
s32 cmpPartyPanelTaskCreate(s32 parentTask) {
    s32 task;
    u8* work;

    chkmemAllocSiteTag(D_0064E290, 0x253);
    work = D_008873F4[0](1, 0xE0, 0x40000);
    if (work == NULL) {
        kAssertFail(D_0064E290, 0x254);
    }
    task = (s32)kwlnTaskCreateChild((void *)((s32)parentTask), (const void *)(D_0064E2E0), 0xC7, 0, 0, cmpPartyPanelTaskStep, cmpPartyPanelTaskDestroy, (u8 *)(work));
    if (task == 0) {
        kAssertFail(D_0064E290, 0x25E);
    }
    ((CmpPartyPanelWork *)work)->state = 0;
    memset(work + 0xB0, 0, 0x30);
    *(u8 **)&((CmpPartyPanelWork *)work)->node.callback = (u8 *)cmpPartyPanelDraw;
    *(u8 **)&((CmpPartyPanelWork *)work)->node.context = work;
    return task;
}
