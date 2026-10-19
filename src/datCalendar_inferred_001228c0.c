/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Camp/h_camp.c; members 001228c0-00124210 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "primitive_queue_internal.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern void (*jtbl_008873EC[])(void *);
extern u8 D_005E50D0[];
extern u8 D_005E5870[];
extern u8 *resourceFindByName(char *filename);
extern void calendarSetMode(s32 input);
extern s32 iGpffffb1e0;
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(char *name, u8 *task);
extern void calendarDrawBackdrop(void *unusedNode, void *work);
extern char D_00795F50[];
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s32 calGetDayTableValue(s16 input, s16 secondInput);
extern s32 FldStepIndex(void);
extern s32 evtHasTaskHandle(void);
extern s32 datGetPendingDateIndex(void);
extern s32 datGetPendingTimeSlot(void);
extern s32 calHasDayEntry();
extern s16 clndGetPeriod(void);
extern s16 clndGetDaysSinceApr5(void);
extern void calendarSyncFromDate(void);
extern void poolFree(s32 input);
extern void func_001029a0(s32 input, void *secondInput, s32 thirdInput, s32 fourthInput);
extern void datCarryOverPersistentState(void);
extern s32 shdWindowTaskCreate(u8 *input, s32 secondInput, s32 thirdInput);
extern s32 shdWindowQueryState(s32 input);
extern s32 mcIconTaskCreate(u8 *input, s32 secondInput);
extern s32 mcIconTaskPoll(void);
extern void sdkSpriteFreeNode(void *node);
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 input, s32 secondInput, f32 x, f32 y,
                          u8 thirdInput, u8 fourthInput, u8 fifthInput, u8 sixthInput, f32 z, s32 seventhInput);
extern s32 kwlnTaskIsLinked();
extern void radarAnimateValue(u8 *input, s32 secondInput, s32 thirdInput);
extern s32 chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 calendarStateTask(u8 *task);
/* Five initialization records at D_005E50D0 have a proven 0x20-byte stride. */
typedef struct CalendarRecordInit {
    f32 firstX, firstY, lastX, lastY;
    s32 kind;
    s32 startFrame;
    s32 endFrame;
    u8 pad1C[4];
} CalendarRecordInit;



typedef struct CalendarSceneWork {
    u32 state;
    u8 pad04[8];
    s32 childTask;
} CalendarSceneWork;

/* Calendar state block at iGpffffb1dc: header fields, five 0x30-byte records from 0x20, owner pointer at 0x110. */
typedef struct CalendarRecord {
    f32 field_00;
    f32 field_04;
    f32 field_08;
    f32 field_0C;
    f32 field_10;
    f32 field_14;
    s8 field_18;
    s8 field_19;
    u8 field_1A;
    u8 pad_1B[0xD];
    s32 field_28;
    s32 field_2C;
} CalendarRecord;

typedef struct CalendarState {
    s32 state; /* 0 init, 1 load, 2 done */
    s16 daysSinceApr5;
    s16 period;
    s16 field_08;
    s16 field_0A;
    s32 field_0C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    CalendarRecord records[5];
    s32 field_110;
} CalendarState;

extern u8 *iGpffffb1dc;
extern s32 clndPromptUpdate(u8 *input);
extern u8 D_005E5170[];
extern u8 D_005E5180[];
extern u8 D_005E5190[];
extern u8 D_005E51A0[];
extern u8 D_005E51B0[];
extern void clndPromptDestroy(u8 *input);
extern u8 *sdkSpriteNewNode(u32 sprites, u32 index);
#pragma push
#pragma opt_propagation on
// FUN_001228C0
/* Load the calendar atlas, initialize its five animations and synchronize the displayed date. */
s32 calendarStateTask(u8 *unusedTask)
{
    s32 state;
    s32 i;
    CalendarState *calendar;
    CalendarState *reloaded;
    CalendarRecord *record;
    u8 *src;
    u8 *table;

    calendar = (CalendarState *)iGpffffb1dc;
    state = calendar->state;
    switch (state) {
    case 0:
        calendar->field_110 = (s32)resourceFindByName((char *)D_005E5870);
        reloaded = (CalendarState *)iGpffffb1dc;
        i = 0;
        table = D_005E50D0;
        while (i < 5) {
            src = table + (i << 5);
            record = &reloaded->records[i];
            record->field_00 = ((CalendarRecordInit *)src)->firstX;
            record->field_04 = ((CalendarRecordInit *)src)->firstY;
            record->field_08 = ((CalendarRecordInit *)src)->lastX;
            record->field_0C = ((CalendarRecordInit *)src)->lastY;
            record->field_28 = ((CalendarRecordInit *)src)->startFrame;
            record->field_2C = ((CalendarRecordInit *)src)->endFrame;
            record->field_19 = ((CalendarRecordInit *)src)->kind;
            record->field_18 = 0;
            i++;
        }
        reloaded->field_10 = 0;
        calendar->state = 1;
        break;
    case 1:
        calendar->daysSinceApr5 = (s16)datGetDateIndex();
        calendar->period = datGetTimeSlot() & 0xFF;
        calendar->field_08 =
            (s8)calGetDayTableValue(calendar->daysSinceApr5, calendar->period);
        calendarSetMode(0);
        calendar->state = 2;
        break;
    case 2:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_00122A10
/* Release calendar work and clear the active global pointer. */
void calendarStateTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
    iGpffffb1dc = 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_00122A40
/* measured: b210 -O2 emits all 3220 executable retail bytes; the
   remaining 12 bytes are zero alignment. Fresh float constants and
   shared integer literals require propagation and constant extraction
   off, with common-subexpression optimization enabled.
   Proof: build/cos20335-continuation/field-ui/review-00122a40-closed. */
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
/* Animate and draw the calendar background, month/day digits and period indicators; restore fog state afterward. */
void calendarDrawBackdrop(void *unusedNode, void *work)
{
    /* Sprite positions (+8/+0xC), alpha (+0x10) and transform fields (+0x18..0x24) retain raw access: typing changed MWCC scheduling. */
    extern s32 (*D_00887304[])(RwRenderState state, void *value);
    extern s32 (*D_00887300[])(RwRenderState state, void *value);
    extern void sdkSpriteDrawOnceAux(s32 parent, s32 sprites, s32 index, f32 x, f32 y, u8 shadowAlpha, u8 alpha, f32 depth, s32 flags);
    extern f32 sdkSpriteScaledHeight(u8 *sprite);
    extern void sdkSpriteDraw(u8 *sprite, s32 flags);
    extern void calSplitDayOfYear(s32 date, s32 *month, s32 *day);
    extern s32 calGetWeekdayOfDay(s32 date);
    extern s32 calHasDayEntry(s32 date);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    s32 (**states)(RwRenderState state, void *value);
    u8 *sprite;
    s32 parent;
    CalendarState *calendar;
    s32 value;
    s32 progress;
    s32 savedFog;
    s32 startFrame;
    s32 elapsed;
    s32 duration;
    s32 i;
    s32 month;
    s32 day;
    s32 height;
    s32 spriteIndex;
    f32 xOffset;
    f32 backgroundX;
    f32 yOffset;
    calendar = (CalendarState *)work;
    parent = 0;
    D_00887304[0](rwRENDERSTATEFOGENABLE, &savedFog);
    states = D_00887300;
    states[0](rwRENDERSTATEFOGENABLE, (void *)0);
    states[0](6, (void *)0);
    states[0](7, (void *)2);
    states[0](8, (void *)0);
    states[0](9, (void *)2);
    states[0](0xC, (void *)1);
    states[0](0xB, (void *)6);
    states[0](0xA, (void *)5);
    states[0](2, (void *)4);
    states[0](rwRENDERSTATEFOGENABLE, (void *)0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    if ((calendar->field_0C & 1) != 0) {
        if (calendar->field_14 != 0) {
            value = calendar->field_10;
            if (value < 0x64) {
                calendar->field_10 = value + 1;
            }
        } else {
            value = calendar->field_10;
            if (value != 0) {
                calendar->field_10 = value - 1;
            }
            if (calendar->field_10 == 0) {
                calendar->field_0C = 0;
            }
        }
        for (i = 0; i < 5; i++) {
            radarAnimateValue((u8 *)&calendar->records[i], calendar->field_10, 0);
        }
        startFrame = calendar->records[1].field_28;
        value = calendar->field_10;
        if (value < startFrame) {
            elapsed = 0;
        } else {
            elapsed = value - startFrame;
        }
        duration = calendar->records[1].field_2C - startFrame;
        if (duration < elapsed) {
            elapsed = duration;
        }
        progress = (elapsed * 0x90) / duration;
        xOffset = (f32)0x23E;
        sdkSpriteDrawOnceAux(0, calendar->field_110, 0x25, xOffset + calendar->records[0].field_10, calendar->records[0].field_14, 0, (0xFF - calendar->records[0].field_1A) & 0xFF, 0.0f, 1);
        if (calendar->field_18 != 0) {
            if (calendar->field_1C == 0) {
                sprite = (u8 *)sdkSpriteNewNode((u32)calendar->field_110, 0x1D);
            } else {
                sprite = (u8 *)sdkSpriteNewNode((u32)calendar->field_110, 0x1E);
            }
        } else if ((FldStepIndex() == 0) && (evtHasTaskHandle() == 0)) {
            sprite = (u8 *)sdkSpriteNewNode((u32)calendar->field_110, 0x1D);
        } else {
            sprite = (u8 *)sdkSpriteNewNode((u32)calendar->field_110, 0x1E);
        }
        *(s32 *)(sprite + 0x24) = 0;
        backgroundX = (f32)0x223;
        *(f32 *)(sprite + 8) = backgroundX + calendar->records[1].field_10;
        *(f32 *)(sprite + 0xC) = -33.0f + calendar->records[1].field_14;
        *(s8 *)(sprite + 0x10) = (s8)(0xFF - calendar->records[1].field_1A);
        *(s16 *)(sprite + 0x1C) = 0x50;
        *(s16 *)(sprite + 0x1E) = 0x2D;
        *(f32 *)(sprite + 0x18) = (f32)(0x90 - progress);
        sdkSpriteDraw(sprite, 1);
        /* Preserve the forwarded word before releasing the temporary sprite. */
        parent = (s32)sprite;
        sdkSpriteFreeNode(sprite);
    }
    if ((calendar->field_0C & 2) != 0) {
        calSplitDayOfYear(calendar->daysSinceApr5, &month, &day);
        value = (s32)calendar->records[2].field_10;
        sdkSpriteDrawOnceTinted(parent, calendar->field_110, 7, (f32)(value + 0x1C2), 17.0f + calendar->records[2].field_14, (0xFF - calendar->records[2].field_1A) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        sdkSpriteDrawOnceTinted(parent, calendar->field_110, 8, (f32)(value + 0x246), 17.0f + calendar->records[2].field_14, (0xFF - calendar->records[2].field_1A) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        value = month / 10 + 9;
        xOffset = (f32)0x1CF;
        xOffset += calendar->records[2].field_10;
        sdkSpriteDrawOnceAux(parent, calendar->field_110, value, 14.0f + xOffset, 17.0f + calendar->records[2].field_14, 0, (0xFF - calendar->records[2].field_1A) & 0xFF, 0.0f, 1);
        sdkSpriteDrawOnceAux(parent, calendar->field_110, month % 10 + 9, 14.0f + (476.0f + calendar->records[2].field_10), 17.0f + calendar->records[2].field_14, 0, (0xFF - calendar->records[2].field_1A) & 0xFF, 0.0f, 1);
        sdkSpriteDrawOnceAux(parent, calendar->field_110, 0x13, 14.0f + (490.0f + calendar->records[2].field_10), 17.0f + calendar->records[2].field_14, 0, (0xFF - calendar->records[2].field_1A) & 0xFF, 0.0f, 1);
        sdkSpriteDrawOnceAux(parent, calendar->field_110, day / 10 + 9, 14.0f + (500.0f + calendar->records[2].field_10), 17.0f + calendar->records[2].field_14, 0, (0xFF - calendar->records[2].field_1A) & 0xFF, 0.0f, 1);
        value = day % 10 + 9;
        xOffset = (f32)0x201;
        xOffset += calendar->records[2].field_10;
        sdkSpriteDrawOnceAux(parent, calendar->field_110, value, 14.0f + xOffset, 17.0f + calendar->records[2].field_14, 0, (0xFF - calendar->records[2].field_1A) & 0xFF, 0.0f, 1);
        if (calHasDayEntry(calendar->daysSinceApr5) != 0) {
            value = calGetWeekdayOfDay(calendar->daysSinceApr5);
            xOffset = (f32)0x219;
            sdkSpriteDrawOnceTinted(parent, calendar->field_110, value, xOffset + calendar->records[2].field_10, 17.0f + calendar->records[2].field_14, (0xFF - calendar->records[2].field_1A) & 0xFF, 0xFF, 0xAC, 0x99, 0.0f, 1);
        } else if (calGetWeekdayOfDay(calendar->daysSinceApr5) == 6) {
            value = calGetWeekdayOfDay(calendar->daysSinceApr5);
            xOffset = (f32)0x219;
            sdkSpriteDrawOnceTinted(parent, calendar->field_110, value, xOffset + calendar->records[2].field_10, 17.0f + calendar->records[2].field_14, (0xFF - calendar->records[2].field_1A) & 0xFF, 0x99, 0xA4, 0xFF, 0.0f, 1);
        } else {
            value = calGetWeekdayOfDay(calendar->daysSinceApr5);
            xOffset = (f32)0x219;
            sdkSpriteDrawOnceTinted(parent, calendar->field_110, value, xOffset + calendar->records[2].field_10, 17.0f + calendar->records[2].field_14, (0xFF - calendar->records[2].field_1A) & 0xFF, 0xFF, 0xFF, 0xFF, 0.0f, 1);
        }
        startFrame = calendar->records[3].field_28;
        value = calendar->field_10;
        if (value < startFrame) {
            elapsed = 0;
        } else {
            elapsed = value - startFrame;
        }
        duration = calendar->records[3].field_2C - startFrame;
        if (duration < elapsed) {
            elapsed = duration;
        }
        progress = (elapsed << 0xC) / duration;
        if (calHasDayEntry(calendar->daysSinceApr5) != 0) {
            value = calendar->period;
            if (value == 3) {
                spriteIndex = 0x1A;
            } else {
                spriteIndex = value + 0x14;
            }
        } else {
            spriteIndex = calendar->period + 0x14;
        }
        if (calendar->field_18 != 0) {
            if (calendar->field_1C == 1) {
                switch (spriteIndex) {
                case 0x18:
                    spriteIndex = 0x1B;
                    break;
                case 0x1A:
                    spriteIndex = 0x1C;
                    break;
                }
            }
        } else if ((FldStepIndex() != 0) || (evtHasTaskHandle() != 0)) {
            switch (spriteIndex) {
                case 0x18:
                    spriteIndex = 0x1B;
                    break;
                case 0x1A:
                    spriteIndex = 0x1C;
                    break;
                }
        }
        sprite = (u8 *)sdkSpriteNewNode((u32)calendar->field_110, spriteIndex);
        *(s32 *)(sprite + 0x24) = 0;
        *(f32 *)(sprite + 8) = 552.0f + calendar->records[3].field_10;
        *(f32 *)(sprite + 0xC) = 31.0f + calendar->records[3].field_14;
        *(s8 *)(sprite + 0x10) = (s8)(0xFF - calendar->records[3].field_1A);
        height = (s32)sdkSpriteScaledHeight(sprite);
        *(s16 *)(sprite + 0x20) = 0xFF6;
        *(s16 *)(sprite + 0x22) = (s16)progress;
        value = (s32)(sdkSpriteScaledHeight(sprite) / 2.0f + (f32)(height / 2));
        yOffset = 31.0f + calendar->records[3].field_14;
        yOffset -= (f32)value;
        *(f32 *)(sprite + 0xC) = (f32)height + yOffset;
        sdkSpriteDraw(sprite, 1);
        /* Preserve the forwarded word before releasing the temporary sprite. */
        parent = (s32)sprite;
        sdkSpriteFreeNode(sprite);
    }
    if ((calendar->field_0C & 4) != 0) {
        if (calendar->field_18 != 0) {
            if (calendar->field_1C == 0) {
                xOffset = (f32)0x247;
                sdkSpriteDrawOnceAux(parent, calendar->field_110, 0x1F, xOffset + calendar->records[4].field_10, 51.0f + calendar->records[4].field_14, 0, (0xFF - calendar->records[4].field_1A) & 0xFF, 0.0f, 1);
                value = calendar->field_08 + 0x20;
                xOffset = (f32)0x247;
                sdkSpriteDrawOnceAux(parent, calendar->field_110, value, xOffset + calendar->records[4].field_10, 51.0f + calendar->records[4].field_14, 0, (0xFF - calendar->records[4].field_1A) & 0xFF, 0.0f, 1);
            }
        } else if ((FldStepIndex() == 0) && (evtHasTaskHandle() == 0)) {
            xOffset = (f32)0x247;
            sdkSpriteDrawOnceAux(parent, calendar->field_110, 0x1F, xOffset + calendar->records[4].field_10, 51.0f + calendar->records[4].field_14, 0, (0xFF - calendar->records[4].field_1A) & 0xFF, 0.0f, 1);
            value = calendar->field_08 + 0x20;
            xOffset = (f32)0x247;
            sdkSpriteDrawOnceAux(parent, calendar->field_110, value, xOffset + calendar->records[4].field_10, 51.0f + calendar->records[4].field_14, 0, (0xFF - calendar->records[4].field_1A) & 0xFF, 0.0f, 1);
        }
    }
    states[0](rwRENDERSTATEFOGENABLE, (void *)savedFog);
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_001236E0
/* Queue the backdrop draw callback with the active calendar work as its payload. */
s32 calendarQueueResult(u8 *unusedTask) {
    u8 *p;
    u8 *q;

    p = PrimAllocQueueNode();
    q = iGpffffb1dc;
    ((PrimQueueNode *)p)->callback = (void *)calendarDrawBackdrop;
    ((PrimQueueNode *)p)->argument.data = q;
    PrimAppendNode(D_00795F50, p);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_00123730
/* Allocate the calendar state and attach update and queued-draw tasks to the parent. */
s32 calendarStartTasks(s32 parentTask)
{
    s32 task;
    s32 work;
    chkmemAllocSiteTag(D_005E5170, 0x179);
    work = (s32)D_008873F4[0](1, 0x114, 0x40000);
    if (work == 0)
        return 0;
    iGpffffb1dc = (u8 *)work;
    task = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005E5180), 0x96, 0, 0, calendarStateTask, calendarStateTaskDestroy, (u8 *)((u8 *)work));
    (s32)kwlnTaskCreateChild((void *)(task), (const void *)(D_005E5190), 0x97, 0, 0, calendarQueueResult, 0, (u8 *)((u8 *)0));
    return task;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_00123810
/* Return the displayed period, or zero when no calendar controller exists. */
s16 clndGetPeriod(void)
{
    CalendarState *p;
    s16 value;

    value = 0;
    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        value = p->period;
    }
    return value;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_00123830
/* Return the displayed date index, or zero when no calendar controller exists. */
s16 clndGetDaysSinceApr5(void)
{
    CalendarState *p;
    s16 value;

    value = 0;
    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        value = p->daysSinceApr5;
    }
    return value;
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* measured: the named first-field load plus -O1 reproduce retail's argument setup order; exact match nd 0 (obj 104B/window 112B). */
// FUN_00123850
/* measured: opens optimization_level 1 to keep the +6 store and +4 load before the call conversion (nd 0). */
#pragma optimization_level 1
/* Refresh the calendar date, period and day-table value from persistent game state. */
void calendarSyncFromDate(void) {
    CalendarState *p;
    s32 t;
    s16 first;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        p->daysSinceApr5 = (s16)datGetDateIndex();
        t = datGetTimeSlot() & 0xFF;
        p->period = (s16)t;
        first = p->daysSinceApr5;
        p->field_08 = (s8)calGetDayTableValue(first, (s16)t);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_001238C0
/* Restart the five record animations when visibility changes; mode 1 starts at frame zero. */
void calendarSetMode(s32 mode)
{
    s32 i;
    s32 j;
    CalendarState *state;
    CalendarState *reloaded;
    CalendarRecord *record;
    CalendarRecord *record2;
    u8 *src;
    u8 *src2;
    u8 *table;

    state = (CalendarState *)iGpffffb1dc;
    if (state != NULL) {
        if (mode != 0) {
            state->field_18 = 0;
        }
        if (state->field_14 != mode) {
            state->field_14 = mode;
            if (mode == 1) {
                reloaded = (CalendarState *)iGpffffb1dc;
                i = 0;
                table = D_005E50D0;
                while (i < 5) {
                    src = table + (i << 5);
                    record = &reloaded->records[i];
                    record->field_00 = ((CalendarRecordInit *)src)->firstX;
                    record->field_04 = ((CalendarRecordInit *)src)->firstY;
                    record->field_08 = ((CalendarRecordInit *)src)->lastX;
                    record->field_0C = ((CalendarRecordInit *)src)->lastY;
                    record->field_28 = ((CalendarRecordInit *)src)->startFrame;
                    record->field_2C = ((CalendarRecordInit *)src)->endFrame;
                    record->field_19 = ((CalendarRecordInit *)src)->kind;
                    record->field_18 = 0;
                    i += 1;
                }
                reloaded->field_10 = 0;
                state->field_0C = 7;
                return;
            }
            reloaded = (CalendarState *)iGpffffb1dc;
            j = 0;
            table = D_005E50D0;
            while (j < 5) {
                src2 = table + (j << 5);
                record2 = &reloaded->records[j];
                record2->field_00 = ((CalendarRecordInit *)src2)->firstX;
                record2->field_04 = ((CalendarRecordInit *)src2)->firstY;
                record2->field_08 = ((CalendarRecordInit *)src2)->lastX;
                record2->field_0C = ((CalendarRecordInit *)src2)->lastY;
                record2->field_28 = ((CalendarRecordInit *)src2)->startFrame;
                record2->field_2C = ((CalendarRecordInit *)src2)->endFrame;
                record2->field_19 = ((CalendarRecordInit *)src2)->kind;
                record2->field_18 = 0;
                j += 1;
            }
            reloaded->field_10 = 0x46;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123A10
/* Latch whether field or event activity selects the alternate prompt sprites. */
void calendarRefreshPromptState(void) {
    CalendarState *p;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        p->field_18 = 1;
        if (FldStepIndex() != 0) {
            goto set1;
        }
        if (evtHasTaskHandle() != 0) {
            goto set1;
        }
        p->field_1C = 0;
        return;
set1:
        p->field_1C = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123A80
/* Clear the calendar visibility request and enabled draw groups. */
void calendarResetPending(void)
{
    CalendarState *p;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        p->field_14 = 0;
        p->field_0C = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123AA0
/* Save the current day-table value before replacing it. */
void calendarPushValue(s16 value) {
    CalendarState *p;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        p->field_0A = p->field_08;
        p->field_08 = value;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123AC0
/* Restore the saved day-table value. */
void calendarPopValue(void) {
    CalendarState *p;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        p->field_08 = p->field_0A;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123AE0
/* Return the signed low byte of the day-table value, or -1 without calendar state. */
s8 calendarGetValueLowByte(void) {
    CalendarState *p;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        return *(s8 *)&p->field_08; /* low byte of field_08 */
    }
    return -1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123B10
/* Return the displayed date index, or -1 without calendar state. */
s16 calendarStateDaysSinceApr5(void) {
    CalendarState *p;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        return p->daysSinceApr5;
    }
    return -1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123B40
/* Return the displayed period, or -1 without calendar state. */
s16 calendarStatePeriod(void) {
    CalendarState *p;

    p = (CalendarState *)iGpffffb1dc;
    if (p != NULL) {
        return p->period;
    }
    return -1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123B70
/* Run the carry-over prompt sequence, retry dialogs and memory-card icon task; return -1 when complete. */
s32 clndPromptUpdate(u8 *task)
{
    /* The 12-byte prompt work stores state/window/icon at +0/+4/+8; typed access changed MWCC allocation. */
    s32 firstChoice;
    s32 retryChoice;
    s32 iconResult;
    u32 state;
    u8 *work;

    work = *(u8 **)(task + 0x38);
    state = *(u32 *)work;
    switch (state) {
    case 0:
        datCarryOverPersistentState();
        *(u32 *)work = 1;
        goto block_20;
    case 1:
        *(s32 *)(work + 4) = shdWindowTaskCreate(task, 1, 0x11);
        *(u32 *)work = 2;
        goto block_20;
    case 2:
        firstChoice = shdWindowQueryState(*(s32 *)(work + 4));
        if (firstChoice == 1) {
            *(s32 *)(work + 4) = shdWindowTaskCreate(task, 1, 0x12);
            *(u32 *)work = 4;
        } else if (firstChoice == 2) {
            *(s32 *)(work + 4) = shdWindowTaskCreate(task, 1, 0x13);
            *(u32 *)work = 3;
        }
        goto block_20;
    case 3:
        retryChoice = shdWindowQueryState(*(s32 *)(work + 4));
        if (retryChoice == 1) {
            return -1;
        }
        if (retryChoice == 2) {
            *(u32 *)work = 1;
        }
        goto block_20;
    case 4:
        if (shdWindowQueryState(*(s32 *)(work + 4)) == 1) {
            *(s32 *)(work + 8) = mcIconTaskCreate(task, 1);
            *(u32 *)work = 5;
        }
        goto block_20;
    case 5:
        iconResult = mcIconTaskPoll();
        if (iconResult == 2) {
            goto case_5_action;
        }
        if (iconResult == 1) {
            goto case_5_error;
        }
        if (iconResult != 0) {
            goto case_5_action;
        }
        goto block_20;
case_5_error:
        return -1;
case_5_action:
        *(s32 *)(work + 4) = shdWindowTaskCreate(task, 1, 0x13);
        *(u32 *)work = 3;
        goto block_20;
    default:
        goto block_20;
    }
block_20:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123D50
void clndPromptDestroy(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123D80
/* Allocate and start the carry-over prompt task, recording its handle. */
s32 clndPromptStart(void)
{
    s32 task;
    chkmemAllocSiteTag(D_005E51A0, 0x84);
    task = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (task == 0) {
        task = 0;
    } else {
        task = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005E51B0), 0xF, 0, 0, clndPromptUpdate, clndPromptDestroy, (u8 *)((u8 *)task));
        if (task == 0)
            task = 0;
    }
    iGpffffb1e0 = task;
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123E30
/* Clear the prompt handle and report completion once its task reaches state 3. */
s32 clndPromptFinished(void)
{
    if (kwlnTaskGetState(iGpffffb1e0) == 3) {
        iGpffffb1e0 = 0;
        return 1;
    }
    return 0;
}
#pragma pop

s32 fadeStatus(void);

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00123E80
/* Sequence fading, logo/movie playback and title results before entering or restoring game state. */
s32 clndSceneUpdate(u8 *task)
{
    extern s32 fadeBeginTransition(s32 task, s32 secondInput);
    extern void calSetDefaultDayFlags(s32 task);
    extern void sdkSndStopMainChannel(void);
    extern void sdkSndFadeOutChannel(s32 task, s32 secondInput);
    extern s32 logoTaskStart(void);
    extern s32 titleSoundReapTask(s32 task);
    extern s32 mwPlayerCreate(void *task, s32 secondInput, void *thirdInput);
    extern void calendarStart(void);
    extern void fadeBeginReturnTransition(s32 task, s32 secondInput);
    extern s32 titleStartLoader(void);
    extern s32 titleLoaderReap(s32 task);
    extern s32 iGpffffb1e4;
    extern s32 iGpffffb1f0;

    extern u8 D_007963A0[];
    extern u8 D_0079B698[];
    extern u8 D_0079B69C[];
    extern u8 D_0079B6A0[];
    u8 *work;
    s32 result;
    s16 pendingDate;
    typedef struct {
        s16 s20;
        s16 s22;
        s16 s24;
        s16 s26;
        s16 s28;
        u8 pad_short[0x1E];
    } ShortWork;
    typedef struct {
        s32 s48;
        s32 s4C;
    } IntWork;
    ShortWork short_work;
    IntWork int_work;

    work = ((struct KwlnTask *)task)->work;
    switch (((CalendarSceneWork *)work)->state) {
    case 0:
        result = fadeStatus();
        if (result == 0)
            break;
        switch (result) {
        case 2:
            ((CalendarSceneWork *)work)->state = 2;
            break;
        default:
            fadeBeginTransition(1, 1);
            ((CalendarSceneWork *)work)->state = 1;
            break;
        }
        break;
    case 1:
        if (fadeStatus() != 0) {
            ((CalendarSceneWork *)work)->state = 2;
        }
        break;
    case 2:
        calSetDefaultDayFlags(1);
        sdkSndStopMainChannel();
        sdkSndFadeOutChannel(3, 0);
        ((CalendarSceneWork *)work)->childTask = logoTaskStart();
        ((CalendarSceneWork *)work)->state = 3;
        break;
    case 3:
        if (titleSoundReapTask(((CalendarSceneWork *)work)->childTask) != 0) {
            ((CalendarSceneWork *)work)->state = 4;
        }
        break;
    case 4:
        if (iGpffffb1e4 == 0) {
            ((CalendarSceneWork *)work)->childTask = mwPlayerCreate(task, 0x15, D_007963A0);
        } else {
            ((CalendarSceneWork *)work)->childTask = mwPlayerCreate(task, 0x16, D_007963A0);
        }
        iGpffffb1e4 = ~iGpffffb1e4;
        ((CalendarSceneWork *)work)->state = 5;
        break;
    case 5:
        if (kwlnTaskIsLinked(((CalendarSceneWork *)work)->childTask) != 1) {
            ((CalendarSceneWork *)work)->state = 6;
        }
        break;
    case 6:
        ((CalendarSceneWork *)work)->childTask = (s32)titleStartLoader();
        ((CalendarSceneWork *)work)->state = 7;
        break;
    case 7:
        result = titleLoaderReap(((CalendarSceneWork *)work)->childTask);
        if (result == 4)
            goto state4;
        if (result == 3)
            goto state3;
        if (result == 2)
            goto state2;
        switch (result) {
        case 1:
            goto state1;
        default:
            goto state_done;
        }
    state1:
        ((CalendarSceneWork *)work)->state = 2;
        goto state_done;
    state2:
        datInitDefaultGameState();
        calRestoreDayFlagMask();
        calendarSyncFromDate();
        calendarSetMode(1);
        func_001029a0(0x19, 0, 0, 0);
        return -1;
    state3:
        iGpffffb1f0 = 1;
        calendarSyncFromDate();
        calendarSetMode(1);
        pendingDate = (s16)datGetPendingDateIndex();
        if ((pendingDate == 9) && ((u8)datGetPendingTimeSlot() == 5)) {
            func_001029a0(0x19, 0, 0, 0);
            return -1;
        }
        if (*(s32 *)D_0079B6A0 != 0) {
            int_work.s48 = *(s32 *)D_0079B6A0;
            int_work.s4C = 0xFF;
            func_001029a0(0xB, &int_work, 8, 2);
        } else {
            short_work.s20 = (s16)*(s32 *)D_0079B698;
            short_work.s22 = (s16)*(s32 *)D_0079B69C;
            short_work.s24 = 0xFF;
            short_work.s26 = 0;
            short_work.s28 = 0;
            func_001029a0(9, &short_work, 0x1C, 0);
        }
        goto state_done;
    state4:
        calendarSetMode(1);
        calendarStart();
        fadeBeginReturnTransition(0, 1);
        ((CalendarSceneWork *)work)->state = 8;
        goto state_done;
    state_done:
    case 8:
    default:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00124210
void taskReleaseSlotModel(u8 *task)
{
    poolFree((s32)((struct KwlnTask *)task)->work);
}
#pragma pop

extern s32 RpSkyRenderStateSet(s32 input, s32 secondInput);
extern void (*D_00887300[])(s32 input, s32 secondInput);
extern s32 RpSkyRenderStateSet(s32 input, s32 secondInput);
#include "btl_shuffle_draw_internal.h"
typedef struct Code12FrameVector { f32 x, y, z; } Code12FrameVector;

typedef union Code12FrameVectorTransfer {
    struct { s64 xy; f32 z; } words;
    f32 value[3];
    Code12FrameVector vector;
} Code12FrameVectorTransfer;
