#include "operand_order_internal.h"
#include "include_asm.h"
#include "member_access.h"
#include "kwln_task_internal.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
/* Original translation unit btlResultSimple.c (from __FILE__ assert strings). */
#include "type.h"
#include "btl_result_ui_internal.h"

void btlShuffleStartOverlay(void);
extern u16 *kwlnTaskGetWork();
void radarAnimateValue(void *work, s32 frame, s32 mode);
s32 btlMainGetPhase(void);
void shdScriptCategoryTaskCreate(void *parentTask, s32 categoryIndex, s32 increment);
s32 shdScriptIsCategoryTaskActive(void);
u8 *sdkSpriteNewNode(u32 packAddress, u32 recordIndex);
u32 RpRandom(void);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 D_00629380[];
extern s32 D_006291A0[];
extern s8 D_00629170[];
extern s32 D_00629560[];
extern s32 D_006295F0[];
void H_Cdvd_Destroy(u8 *cdvd);
void sdkSpriteRelease(void *node);
void sdkSpriteFreeNode(void *node);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
void chkmemAllocSiteTag(const void *file, s32 line);
void memset(void *dst, s32 value, u32 size);

extern char D_00629628[];
extern char D_006290F0[];
extern char D_00629610[];
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32 day);
void func_00440b68(void *msg, const void *file, s32 line);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
void kAssertFail(const void *file, s32 line);
s32 resourceFindByName(u32 name);
s32 H_Cdvd_IsFileLoaded(u8 *cdvd);
u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);
s32 hMaestroDecodeIsReady(s32 state);
void btlResultSimpleDraw(u8 *unusedTask, u8 *work);
void btlResultSimpleTaskDestroy(u8 *unusedTask);
void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
extern s32 sprintf(void *dst, const void *fmt, ...);
void PrimAppendNode(void *list, void *node);
extern u32 D_00795F20[];
s32 btlResultSimpleStepPhase(u8 *task);
s32 btlShuffleOverlayIdle(void);

extern char iGpffffa5b8;
extern u8 *iGpffffa5a0[2];

/* Resource-name alias starts at the first of two adjacent handles. */
typedef struct BtlResultResourceName { s32 name; } BtlResultResourceName;
extern BtlResultResourceName iGpffffa5a8[2];
extern s32 iGpffffa5b0;
extern char iGpffffa5b4;
typedef struct ResultParticleStyle {
    f32 originX;
    s32 resource;
    u32 minimumDuration;
    u32 durationRange;
    s32 motion;
    f32 minimumAmplitude;
    f32 maximumAmplitude;
} ResultParticleStyle;

/* Twenty 0x30-byte records are initialized from the 0x18-byte style tables. */
typedef struct BtlResultAnimRecord {
    f32 start[2];
    f32 target[2];
    f32 current[2];
    u8 startOpacity, targetOpacity, opacity;
    u8 pad1B[0x0D];
    s32 unk28, unk2C;
} BtlResultAnimRecord;

/* Both position tables use a 0x18-byte stride; phase stepping tests +0x14. */
typedef struct BtlResultAnimStyle {
    f32 position[2];
    u8 opacity;
    u8 pad09[3];
    s32 unk0C;
    s32 unk10;
    s32 motion;
} BtlResultAnimStyle;

/* Five independently timed particles occupy result work + 0x4C0. */
typedef struct ResultParticleState {
    u16 age;
    u16 duration;
    f32 amplitude;
    f32 position[2];
    f32 previous[2];
    f32 next[2];
} ResultParticleState;

typedef struct BtlResultPulse {
    f32 offset;
    u16 frame;
    u8 pad06[2];
} BtlResultPulse;

/* Twelve-byte pulse table rows provide a duration and the two offset endpoints. */
typedef struct BtlResultPulseStyle {
    u16 duration;
    u8 pad02[2];
    f32 start, end;
} BtlResultPulseStyle;
/* Work buffer handed to the result state machine (see btlResultSimpleCreateTask). */
typedef struct BtlResultSimpleWork BtlResultSimpleWork;
struct BtlResultSimpleWork
{
    u16 flags;         // 0x00
    u16 pad02;         // 0x02
    u32 state;         // 0x04
    s32 field08;       // 0x08
    s32 field0C;       // 0x0C
    void *drawCallback; // 0x10
    u8 pad14[4];
    void *drawWork;     // 0x18
    u8 pad1C[0x1C];
    u32 phase;         // 0x38
    u16 field3C;       // 0x3C
    u8 pad3E[2];
    BtlResultAnimRecord animation[20]; // 0x40..0x3FF
    s32 field400[3];   // 0x400..0x40B
    s32 sharedBanks[2];// 0x40C..0x413
    s32 field414[0x2A];// 0x414..0x4BB
    union { s32 archiveAddress; u8 *archive; }; // 0x4BC
    ResultParticleState particles[5]; // 0x4C0..0x55F
    BtlResultPulse pulses[2];         // 0x560..0x56F
    u8 *field570;      // 0x570
};

s32 btlResultSimpleLoadAssets(BtlResultSimpleWork *work);
void btlResultSimpleCreateSprites(BtlResultSimpleWork *work);
extern u8 nmMesWindowOpenCurrent(u8 *message);
void nmMesWindowShowCurrentRecord(s32 recordIndex);
void nmMesWindowResetCurrent(void);
s32 datMemberNoticeTryBegin(s32 stepMode);
extern s32 btlResultSimpleUpdate(u8 *task);


/* Grouped values are unsigned; the plain format is signed "%d". */
// FUN_0021ED10
/* measured: retail hoists the digit-loop constants out of the loop, which needs opt_loop_invariants
 * on. */
#pragma opt_loop_invariants on
/* Draw a signed decimal or grouped unsigned number using digit sprites, updating the supplied pen
 * position. */
void btlResultSimpleDrawLabel(u8 *work, f32 *position, f32 unusedDepth, s32 color, u32 value, s32 groupDigits)
{
    s8 rev[0x40];
    s8 buf[0x40];
    u8 hi;
    u8 mid;
    u8 lo;
    u8 ch;
    s32 i;
    s32 n;
    s32 tmp;
    s32 k;
    s32 j;
    s32 digit;
    (void)unusedDepth;

    hi = (u8)((color & 0xFF000000) >> 24);
    mid = (u8)((u32)(color & 0xFF0000) >> 16);
    lo = (u8)((u32)(color & 0xFF00) >> 8);
    ch = color & 0xFF;
    if (ch != 0) {
        if (value >= 1000 && groupDigits != 0) {
            k = 0;
            j = 0;
            do {
                buf[k] = (u8)((value % 10) + 0x30);
                k += 1;
                value /= 10;
                if (value != 0 && j == 2) {
                    buf[k] = 0x2E;
                    k += 1;
                }
                j += 1;
                if (j > 2) {
                    j = 0;
                }
            } while (value != 0);
            n = 0;
            while (n < k) {
                tmp = n + 1;
                rev[n] = buf[k - tmp];
                n = tmp;
            }
            rev[n] = 0;
        } else {
            sprintf(rev, &iGpffffa5b4, (s32)value);
        }
        i = 0;
        while (rev[i] != 0) {
            switch (rev[i]) {
            case 0x2E:
                sdkSpriteDrawAt((void *)((BtlResultSimpleWork *)work)->field414[35],
                              position[0], position[1], hi, mid, lo, ch);
                position[0] += 8.0f;
                break;
            default:
                digit = rev[i] - 0x30;
                if (digit < 0 || digit > 9) {
                    kAssertFail(&D_00629610, 0x119);
                }
                sdkSpriteDrawAt(
                    MEMBER(void *, work + digit * 4, BtlResultSimpleWork, field414[25]),
                    position[0], position[1], hi, mid, lo, ch);
                position[0] += 22.0f;
                break;
            }
            i += 1;
        }
    }
}
#pragma opt_loop_invariants off


/* Pointer slots and resource-bank loads are unsigned, matching the real constructor contract. */
// FUN_0021EF70
/* measured: retail hoists the table bases out of the loops, which needs opt_loop_invariants on. */
#pragma opt_loop_invariants on
/* Initialize twenty animation rows, create forty-two sprites, and seed five particle timers and two
 * pulses; the particle traversal keeps a shifted cursor. */
void btlResultSimpleCreateSprites(BtlResultSimpleWork *work)
{
    BtlResultSimpleWork *result;
    u8 *base;
    u8 *row;
    u8 *src;
    u8 *p;
    u8 **out;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    f32 base_value;
    f32 x;
    f32 y;
    u8 c;

    base = (u8 *)work;
    result = (BtlResultSimpleWork *)base;
    for (i = 0; i < 20; i++) {
        src = (u8 *)D_006291A0 + i * 0x18;
        row = (u8 *)&((BtlResultSimpleWork *)base)->animation[i];
        x = ((BtlResultAnimStyle *)src)->position[0];
        ((BtlResultAnimRecord *)row)->start[0] = x;
        ((BtlResultAnimRecord *)row)->current[0] = x;
        y = ((BtlResultAnimStyle *)src)->position[1];
        ((BtlResultAnimRecord *)row)->start[1] = y;
        ((BtlResultAnimRecord *)row)->current[1] = y;
        c = ((BtlResultAnimStyle *)src)->opacity;
        ((BtlResultAnimRecord *)row)->startOpacity = c;
        ((BtlResultAnimRecord *)row)->opacity = c;
        src = (u8 *)D_00629380 + i * 0x18;
        ((BtlResultAnimRecord *)row)->target[0] = ((BtlResultAnimStyle *)src)->position[0];
        ((BtlResultAnimRecord *)row)->target[1] = ((BtlResultAnimStyle *)src)->position[1];
        ((BtlResultAnimRecord *)row)->targetOpacity = ((BtlResultAnimStyle *)src)->opacity;
        ((BtlResultAnimRecord *)row)->unk28 = ((BtlResultAnimStyle *)src)->unk0C;
        ((BtlResultAnimRecord *)row)->unk2C = ((BtlResultAnimStyle *)src)->unk10;
    }
    for (j = 0; j < 42; j++) {
        if (j < 13) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = sdkSpriteNewNode(*(u32 *)&((BtlResultSimpleWork *)base)->field400[0], (u32)D_00629170[j]);
        } else if (j < 15) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = sdkSpriteNewNode(*(u32 *)&((BtlResultSimpleWork *)base)->field400[1], (u32)D_00629170[j]);
        } else if (j < 25) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = sdkSpriteNewNode(*(u32 *)&((BtlResultSimpleWork *)base)->sharedBanks[0], (u32)D_00629170[j]);
        } else if (j < 36) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = sdkSpriteNewNode(*(u32 *)&((BtlResultSimpleWork *)base)->sharedBanks[1], (u32)D_00629170[j]);
        } else {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = sdkSpriteNewNode(*(u32 *)&((BtlResultSimpleWork *)base)->field400[2], (u32)D_00629170[j]);
        }
        if (*out == 0) {
            kAssertFail(&D_00629610, 0x159);
        }
    }
    for (k = 0; k < 5; k++) {
        p = base + k * 0x20;
        *(u32 *)&((BtlResultSimpleWork *)p)->particles[0].position[0] = 0x43560000;
        row = p + 0x4C0;
        ((BtlResultSimpleWork *)p)->particles[0].previous[0] = ((BtlResultSimpleWork *)p)->particles[0].position[0];
        ((ResultParticleState *)row)->next[0] =
            (f32)((RpRandom() & 0xFFF) * 214) / 4096.0f;
        src = (u8 *)D_00629560 + k * 0x1C;
        base_value = ((ResultParticleStyle *)src)->minimumAmplitude;
        ((ResultParticleState *)row)->amplitude = base_value +
            ((((ResultParticleStyle *)src)->maximumAmplitude - base_value) *
             (f32)(RpRandom() & 0xFFF)) / 4096.0f;
        ((ResultParticleState *)row)->age = 0;
        ((ResultParticleState *)row)->duration =
            *(s32 *)&((ResultParticleStyle *)src)->minimumDuration + RpRandom() % ((ResultParticleStyle *)src)->durationRange;
    }
    for (m = 0; m < 2; m++) {
        row = base + m * 8;
        *(s16 *)&((BtlResultSimpleWork *)row)->pulses[0].frame = 0;
        ((BtlResultSimpleWork *)row)->pulses[0].offset = ((BtlResultPulseStyle *)D_006295F0)[m].start;
    }
    *(s16 *)&result->field3C = 0;
    *(s32 *)&result->phase = 0;
}
#pragma opt_loop_invariants off
/* measured: retail computes the indexed field400 store address before calling func_0046af60, but
 * the compiler recomputes it after the call, so this function is left without a matching body. */
// FUN_0021F340
/* Adopt three sprite banks, poll their readiness and the message archive, and set the corresponding
 * work flags. Measured: the archive-entry reload and clear store still change allocation when typed;
 * MEMBER preserves those two accesses. */
s32 btlResultSimpleLoadAssets(BtlResultSimpleWork *work)
{
    s32 spriteBank;
    s32 archive;
    s32 messageArchive;
    s32 readyCount;
    s32 archiveIndex;
    s32 bankIndex;
    u16 flags;
    u8 *workBytes;
    s32 *dest;

    workBytes = (u8 *)work;
    if (!(((BtlResultSimpleWork *)workBytes)->flags & 0x100)) {
        if (*(s32 *)&((BtlResultSimpleWork *)workBytes)->archive != 0 &&
            H_Cdvd_IsFileLoaded((u8 *)*(s32 *)&((BtlResultSimpleWork *)workBytes)->archive) != 0) {
            archiveIndex = 0;
            while (archiveIndex < 3) {
                dest = (s32 *)(workBytes + archiveIndex * 4 + 0x400);
                *dest = (s32)sdkSpriteAdoptBlob((u32)H_Cdvd_GetArchiveEntry(MEMBER(u8 *, workBytes, BtlResultSimpleWork, archive), archiveIndex, 0));
                if (*dest == 0) {
                    kAssertFail(&D_00629610, 0x181);
                }
                archiveIndex += 1;
            }
            ((BtlResultSimpleWork *)workBytes)->flags |= 0x100;
        } else {
            return 0;
        }
    }
    if (!(((BtlResultSimpleWork *)workBytes)->flags & 0x20)) {
        bankIndex = 0;
        readyCount = 0;
        while (bankIndex < 3) {
            spriteBank = ((BtlResultSimpleWork *)workBytes)->field400[bankIndex];
            if (spriteBank != 0 && hMaestroDecodeIsReady(spriteBank) != 0) {
                readyCount += 1;
            }
            bankIndex += 1;
        }
        if (readyCount == 3) {
            ((BtlResultSimpleWork *)workBytes)->flags |= 0x20;
            archive = *(s32 *)&((BtlResultSimpleWork *)workBytes)->archive;
            if (archive != 0) {
                H_Cdvd_Destroy((u8 *)archive);
                MEMBER(s32, workBytes, BtlResultSimpleWork, archiveAddress) = 0;
            }
        }
    }
    if (!(((BtlResultSimpleWork *)workBytes)->flags & 0x40)) {
        messageArchive = ((BtlResultWork *)((BtlResultSimpleWork *)workBytes)->field570)->file;
        if (messageArchive != 0 && H_Cdvd_IsFileLoaded((u8 *)messageArchive) != 0) {
            ((BtlResultSimpleWork *)workBytes)->flags |= 0x40;
        }
    }
    flags = ((BtlResultSimpleWork *)workBytes)->flags;
    if ((flags & 0x20) && (flags & 0x40)) {
        return 1;
    }
    return 0;
}


/* Animate result rows, wait for confirmation, then sequence the optional notice before completion.
 * The dedicated work alias preserves frame reloads across row callbacks; the parent uses its shared
 * result layout. */
// FUN_0021F520
s32 btlResultSimpleStepPhase(u8 *task) {
    BtlResultSimpleWork *result;
    u8 *work;
    u8 *sub;
    u32 state;
    s32 i;
    s32 v;

    work = ((struct KwlnTask *)task)->work;
    result = (BtlResultSimpleWork *)work;
    sub = ((BtlResultSimpleWork *)work)->field570;
    state = ((BtlResultSimpleWork *)work)->phase;
    switch (state) {
    case 0:
        v = result->field3C;
        if (v >= 0x1E) {
            goto L;
        }
        result->field3C = v + 1;
        for (i = 0; i < 0x14; i++) {
            switch (((BtlResultAnimStyle *)D_00629380)[i].motion) {
            case 0:
                radarAnimateValue(work + i * 0x30 + 0x40, result->field3C, 0);
                break;
            case 1:
                radarAnimateValue(work + i * 0x30 + 0x40, result->field3C, 1);
                break;
            }
        }
        if (result->field3C != 0x1E) {
            goto L;
        }
        ((BtlResultSimpleWork *)work)->flags |= 0x10;
        result->field3C = 0;
        result->phase = 1;
        goto L;
    case 1:
        v = (result->field3C += 1);
        if ((v & 0xFFFF) < 4) {
            goto L;
        }
        if (btlMainGetPhase() != 0x10) {
            goto L;
        }
        result->phase = 2;
        goto L;
    case 2:
        if ((D_008C024E[0] & 0x40) || (D_008C024C[0] & 0x10)) {
            if (((BtlResultWork *)sub)->awards.unk698 > 0) {
                nmMesWindowOpenCurrent((u8 *)((s32)H_Cdvd_GetArchiveEntry(*(u8 **)&((BtlResultWork *)sub)->file, 0, 0)));
                nmMesWindowShowCurrentRecord(0x17);
                result->phase = 3;
            } else {
                result->phase = 5;
            }
        }
        goto L;
    case 3:
        if (datMemberNoticeTryBegin(1) != 0) {
            goto L;
        }
        nmMesWindowResetCurrent();
        shdScriptCategoryTaskCreate(task, 0, ((BtlResultWork *)sub)->awards.unk698);
        result->phase = 4;
        goto L;
    case 4:
        if (shdScriptIsCategoryTaskActive() != 0) {
            goto L;
        }
        result->phase = 5;
        goto L;
    case 5:
        return 1;
    default:
    L:
        return 0;
    }
}
/* Drive result asset readiness, drawing setup, notice windows and final shutdown flags. Parent
 * fields use the shared result payload representation. */
// FUN_0021F790
s32 btlResultSimpleUpdate(u8 *task) {
    BtlResultSimpleWork *work;
    u32 state;
    s32 v;

    work = (BtlResultSimpleWork *)kwlnTaskGetWork();
    work->field08 = 0;
    work->field0C = 0;
    PrimAppendNode(&D_00795F20, &work->field08);
    state = work->state;
    switch (state) {
    case 0:
        work->state = 1;
        goto L;
    case 1:
        v = work->flags;
        if ((v & 1) && (v & 8)) {
            goto case2;
        }
        if ((v & 4) && (btlResultSimpleLoadAssets(work) != 0)) {
            work->flags &= 0xFFFB;
            work->flags |= 8;
        }
        goto L;
    case 2:
    case2:
        btlResultSimpleCreateSprites(work);
        work->flags |= 2;
        work->state = 3;
        goto L;
    case 3:
        if (btlResultSimpleStepPhase(task) != 0) {
            v = *(s32 *)&((BtlResultWork *)work->field570)->awards.flags;
            if (v & 2) {
                work->state = 4;
                nmMesWindowOpenCurrent((u8 *)((s32)H_Cdvd_GetArchiveEntry(*(u8 **)&((BtlResultWork *)work->field570)->file, 0, 0)));
                nmMesWindowShowCurrentRecord(2);
            } else if (v & 8) {
                work->state = 4;
                nmMesWindowOpenCurrent((u8 *)((s32)H_Cdvd_GetArchiveEntry(*(u8 **)&((BtlResultWork *)work->field570)->file, 0, 0)));
                nmMesWindowShowCurrentRecord(1);
            } else if (v & 0x10) {
                work->flags &= 0xFFFE;
                work->state = 7;
            } else {
                work->flags &= 0xFFFE;
                work->state = 7;
                work->flags |= 0x80;
            }
        }
        goto L;
    case 4:
        if (datMemberNoticeTryBegin(1) == 0) {
            nmMesWindowResetCurrent();
            work->flags &= 0xFFFE;
            work->state = 7;
        }
        goto L;
    case 5:
        if (btlShuffleOverlayIdle() != 0) {
            work->state = 6;
        case 6:
            if (work->flags & 0x80) {
                goto R1;
            }
            v = (work->field3C += 1);
            if ((v & 0xFFFF) < 5) {
                goto L;
            }
        R1:
            work->flags &= 0xFFFD;
            return -1;
        }
        goto L;
    case 7:
        goto L;
    default:
    L:
        return 0;
    }
}


/* measured: the shared product keeps range before sample in the native mul.s operands. */


/* Update and draw the five result-screen sprites using their individual motion and random-duration
 * styles. */
// FUN_0021FA40
/* Advance and draw the five independently timed result particles from their style rows. Parent
 * flags use the shared reward layout. */
void btlResultSimpleInitAnimRecords(u8 *work)
{
    BtlResultSimpleWork *result = (BtlResultSimpleWork *)work;
    extern void shdEnableBlendFlag(void);
    extern void shdDisableBlendFlag(void);
    extern f32 sinf(f32 angle);
    extern f32 iGpffff83d8;
    extern f32 fGpffff81e0;
    u8 opacity;
    ResultParticleState *particle;
    const ResultParticleStyle *style;
    s32 i;
    void *resource;
    f32 x;
    f32 y;
    f32 amount;
    f32 minimum;
    u32 random;
    s32 nextAge;

    shdEnableBlendFlag();
    for (i = 0; i < 5; i++) {
        particle = (ResultParticleState *)(work + 0x4C0 + i * sizeof(ResultParticleState));
        if ((((BtlXpReward *)((BtlResultWork *)((BtlResultSimpleWork *)work)->field570)->parameters)->flags & 4) == 0 && *(s32 *)&result->phase != 0) {
            /* Use the stored halfword result, including its wrap at 65535. */
            nextAge = (particle->age += 1);
            if (nextAge >= particle->duration) {
                particle->previous[0] = particle->position[0];
                random = RpRandom();
                particle->next[0] = (f32)((random & 0xFFF) * 214U) / 4096.0f;
                style = (const ResultParticleStyle *)((u8 *)D_00629560 + i * sizeof(ResultParticleStyle));
                minimum = style->minimumAmplitude;
                random = RpRandom();
                amount = (f32)(random & 0xFFF);
                amount = operandOrderMultiply(style->maximumAmplitude - minimum, amount);
                /* The low twelve random bits select a fraction in [0, 1). */
                particle->amplitude = minimum + amount / 4096.0f;
                particle->age = 0;
                random = RpRandom();
                particle->duration = style->minimumDuration + random % style->durationRange;
            }
        }
        x = ((BtlResultSimpleWork *)work)->animation[14].current[0] + (((BtlResultSimpleWork *)work)->animation[12].current[0] + ((BtlResultSimpleWork *)work)->animation[13].current[0]);
        y = ((BtlResultSimpleWork *)work)->animation[12].current[1] + ((BtlResultSimpleWork *)work)->animation[13].current[1];
        opacity = ((BtlResultSimpleWork *)work)->animation[12].opacity;
        style = (const ResultParticleStyle *)((u8 *)D_00629560 + i * sizeof(ResultParticleStyle));
        /* The sprite and opacity are captured before either motion callback. */
        resource = *(void **)&((BtlResultSimpleWork *)work)->field414[style->resource];
        switch (style->motion) {
        case 0:
            amount = sinf((iGpffff83d8 * (f32)(u32)particle->age) / (f32)(u32)particle->duration);
            particle->position[0] = 0.0f + particle->previous[0] + amount * (particle->next[0] - particle->previous[0]);
            particle->position[1] = 0.0f + particle->previous[1] + amount * (particle->next[1] - particle->previous[1]);
            x += (f32)0x19F + particle->position[0];
            y += particle->position[1];
            break;
        case 1:
            amount = sinf((fGpffff81e0 * (f32)(u32)particle->age) / (f32)(u32)particle->duration);
            amount = -amount;
            x += 0.0f + style->originX + particle->amplitude * amount;
            break;
        default:
            kAssertFail(D_00629610, 0x2AD);
            break;
        }
        sdkSpriteDrawAt(resource, x, y, 0xFF, 0xFF, 0xFF, opacity);
    }
    shdDisableBlendFlag();
}

/* Separate position snapshots and per-dimension scale views keep the retail reloads; const draw
 * coordinates keep the anchor across both sprites. */
// FUN_0021FEA0
#pragma push
/* measured: loop invariants must be hoisted to keep the interpolation constants out of the loop as
 * retail does. */
#pragma opt_loop_invariants on
/* Draw the animated result headings, reward values, particles and conditional banners. Measured: a dedicated
 * work alias preserves coordinate and opacity reloads; only the indexed level-digit lookup needs
 * the named offset fallback. */
void btlResultSimpleDraw(u8 *unusedTask, u8 *work)
{
    BtlResultSimpleWork *result = (BtlResultSimpleWork *)work;
    typedef struct { f32 x, y; } Vec2f;
    typedef union { Vec2f xy; f32 v[2]; s64 bits; } ResultPosition;
    u8 *w;
    u8 *sprite;
    struct ResultSubHeader { u8 pad[8]; u16 flags; } *p16;
    u8 labelRed;
    u8 labelGreen;
    u8 labelBlue;
    u8 headingRed;
    u8 headingGreen;
    u8 headingBlue;
    s32 digitIndex;
    u8 heroOpacity;
    u32 renderStates;
    u8 moneyOpacity;
    u8 experienceOpacity;
    u8 itemOpacity;
    u8 firstBannerOpacity;
    u8 secondBannerOpacity;
    u8 shadowOpacity;
    u8 thirdBannerOpacity;
    u8 secondaryShadowOpacity;
    s32 emptyRewardSprite;
    s32 firstBannerSprite;
    s32 secondBannerSprite;
    s32 thirdBannerSprite;
    s32 itemIndex;
    s32 pulseIndex;
    s32 shadowIndex;
    s32 secondaryShadowIndex;
    s32 awardValue;
    u32 experience;
    s8 digitCharacter;
    u8 *itemRecord;
    u8 *pulseBase;
    u8 *pulse;
    u8 *pulseStyle;
    u32 elapsed;
    u32 duration;
    f32 elapsedFloat;
    f32 durationFloat;
    f32 startOffset;
    f32 endOffset;
    f32 scale;
    f32 coordinate;

    f32 nextDrawX;
    f32 secondaryNextX;
    u8 color[4];
    u8 opacity;
    ResultPosition position;
    ResultPosition basePosition;
    ResultPosition offsetSnapshot;
    /* Separate copies correspond to the retail stack snapshots at F8, F0 and E8. */
    ResultPosition shadowBase;
    ResultPosition secondaryOffset;
    ResultPosition secondaryBase;
    s8 numberText[0x18];
    s32 rectangle[4];
    struct {
        u16 a0;
        s16 a2;
        u8 _pad[18];
        s16 b6;
        s16 b8;
    } itemRow;
    extern f32 fGpffff8410;
    extern f32 fGpffff8414;
    extern f32 fGpffff8418;
    extern s32 (*D_00887300[])(s32, void *);
    void sdkSpriteDrawSized(u8 *, f32, f32, f32, u8, u8, u8, u8, u16, u16, s16, f32, s16);
    void PrimDrawRectangle(u8 *, u8 *, f32, s32, s32, s32, f32, f32, f32);
    void PrimDrawFlatRectangle(u8 *, f32 *, f32, s32);
    s32 RpSkyRenderStateSet(s32, void *);
    void shdEnableBlendFlag(void);
    void shdDisableBlendFlag(void);
    s32 datCalcGetLevelById(s32);
    u32 datPersonaNamePart1(s16);
    s32 btlXpBaseAward(u8 *);
    void datEntryReset(u8 *);
    void datEntryDrawRow(Vec2f, f32, u8, u8 *);
    int frFontExDrawText(f32, f32, f32, s32, s8, s32, const char *, s32, s32);

    (void)unusedTask;
    w = work;
    if ((*(u16 *)w) & 2) {
        p16 = (*(struct ResultSubHeader **)&((BtlResultSimpleWork *)w)->field570);
        renderStates = (u32)D_00887300;
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(6, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(8, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(7, (void *)2);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(9, (void *)2);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(0xC, (void *)1);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(0xB, (void *)6);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(0xA, (void *)5);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(2, (void *)4);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(0xE, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(3, (void *)1);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(4, (void *)1);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        rectangle[0] = (s32)(-224.0f + (result->animation[8].current[0]));
        rectangle[1] = (s32)(224.0f + (result->animation[8].current[1]));
        rectangle[2] = 0x30C;
        rectangle[3] = 0x30C;
        color[0] = 0xFF;
        color[1] = 0xEA;
        color[2] = 0x2C;
        color[3] = 0xFF;
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(1, (void *)0);
        shdEnableBlendFlag();
        PrimDrawRectangle(&color[0], (u8 *)&rectangle[0], 0.0f, 0, 0, 0, 45.0f, 1.0f, 1.0f);
        shdDisableBlendFlag();
        rectangle[0] = (s32)(-224.0f + (result->animation[9].current[0]));
        rectangle[1] = (s32)(224.0f + (result->animation[9].current[1]));
        rectangle[2] = 0x30C;
        rectangle[3] = 0x30C;
        color[0] = 0xFF;
        color[1] = 0xAE;
        color[2] = 0x20;
        color[3] = 0xFF;
        shdEnableBlendFlag();
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(1, (void *)0);
        PrimDrawRectangle(&color[0], (u8 *)&rectangle[0], 0.0f, 0, 0, 0, 45.0f, 1.0f, 1.0f);
        shdDisableBlendFlag();
        position.v[0] =(386.0f + (result->animation[7].current[0]));
        position.v[1] =(35.0f + (result->animation[7].current[1]));
        opacity = result->animation[7].opacity;
        sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[36];
        sdkSpriteDrawAt(sprite, position.v[0], position.v[1], 0x32, 0x32, 0x32, opacity);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(1, (void *)0);
        rectangle[0] = (s32)((result->animation[8].current[0]));
        rectangle[1] = (s32)((result->animation[8].current[1]));
        rectangle[2] = 0x19F;
        rectangle[3] = 0x1C0;
        color[0] = 0xFF;
        color[1] = 0xEA;
        color[2] = 0x2C;
        color[3] = 0xFF;
        PrimDrawFlatRectangle(&color[0], (f32 *)&rectangle[0], 0.0f, 0);
        coordinate = (f32)0x275;
        coordinate += (result->animation[8].current[0]);
        rectangle[0] = (s32)(coordinate);
        rectangle[1] = (s32)((result->animation[8].current[1]));
        rectangle[2] = 0x12;
        rectangle[3] = 0x1C0;
        color[0] = 0xFF;
        color[1] = 0xEA;
        color[2] = 0x2C;
        color[3] = 0xFF;
        PrimDrawFlatRectangle(&color[0], (f32 *)&rectangle[0], 0.0f, 0);
        btlResultSimpleInitAnimRecords(w);
        RpSkyRenderStateSet(3, (void *)0x32801);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(8, (void *)1);
        rectangle[0] = 0;
        rectangle[1] = 0;
        rectangle[2] = 0x280;
        rectangle[3] = 0x1C0;
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        color[3] = 0;
        PrimDrawFlatRectangle(&color[0], (f32 *)&rectangle[0], 20.0f, 0);
        coordinate = (f32)0x19F;
        coordinate += (result->animation[11].current[0]);
        rectangle[0] = (s32)(coordinate);
        rectangle[1] = (s32)(35.0f + (result->animation[11].current[1]));
        rectangle[2] = 0xFE;
        rectangle[3] = 0x1F4;
        color[0] = 0xFF;
        color[1] = 0xFF;
        color[2] = 0xFF;
        color[3] = 0;
        PrimDrawFlatRectangle(&color[0], (f32 *)&rectangle[0], 0.0f, 0);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(8, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(6, (void *)1);
        heroOpacity = (result->animation[6].opacity);
        position.v[0] =(73.0f + (result->animation[6].current[0]));
        coordinate = (f32)0x187;
        coordinate += (result->animation[6].current[1]);
        position.v[1] = coordinate;
                sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[13];
                sdkSpriteDrawSized(sprite, position.v[0], position.v[1], 10.0f, 0x2DU, 0x2DU, 0x2DU,
                    heroOpacity, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        coordinate = (f32)0x111;
        coordinate += (result->animation[6].current[0]);
        position.v[0] = coordinate;
        coordinate = (f32)0x187;
        coordinate += (result->animation[6].current[1]);
        position.v[1] = coordinate;
                sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[14];
                sdkSpriteDrawSized(sprite, position.v[0], position.v[1], 10.0f, 0x2DU, 0x2DU, 0x2DU,
                    heroOpacity, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(6, (void *)0);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(6, (void *)1);
        position.v[0] =(76.0f + (result->animation[6].current[0]));
        coordinate = (f32)0x171;
        coordinate += (result->animation[6].current[1]);
        position.v[1] = coordinate;
                sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[8];
                sdkSpriteDrawSized(sprite, position.v[0], position.v[1], 10.0f, 0x2DU, 0x2DU, 0x2DU,
                    heroOpacity, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        if (p16->flags & 4) {
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
        } else {
            color[0] = 0xEC;
            color[1] = 0x7C;
            color[2] = 0;
        }
        position.v[0] =(1.0f + (117.0f + (result->animation[6].current[0])));
        coordinate = (f32)0x175;
        coordinate += (result->animation[6].current[1]);
        position.v[1] = coordinate;
        sprintf(numberText, &iGpffffa5b4, datCalcGetLevelById(1) & 0xFF);
        digitIndex = 0;
        while (numberText[digitIndex] != 0) {
            digitCharacter = numberText[digitIndex];
                sprite = *(u8 **)(w + digitCharacter * 4 + MEMBER_OFFSET(BtlResultSimpleWork, field414[15]) - 48 * sizeof(s32));
            sdkSpriteDrawSized(sprite, position.v[0], position.v[1], 10.0f,
                    color[0], color[1], color[2], heroOpacity, 0x1000, 0x1000, 0, 0.0f, (s64)0);
            position.v[0] += 16.0f;
            digitIndex += 1;
        }
        position.v[0] =(157.0f + (result->animation[6].current[0]));
        position.v[1] =((366.0f + (result->animation[6].current[1])) - 2.0f);
        frFontExDrawText(position.v[0], position.v[1], 10.0f, (((u8)heroOpacity & 0xFF) | ~0xFF), 5, 1, (const char *)datPersonaNamePart1(1), 0, 0);
        ((s32 (*)(s32, void *))*(u32 *)renderStates)(6, (void *)0);
        if (p16->flags & 4) {
            labelRed = 0x67;
            labelGreen = 0x5F;
            labelBlue = 0x1F;
            emptyRewardSprite = (s32)(((BtlResultSimpleWork *)w)->field414[12]);
            position.v[0] =(78.0f + (result->animation[3].current[0]));
            position.v[1] =(53.0f + (result->animation[3].current[1]));
            opacity = result->animation[3].opacity;
            sdkSpriteDrawAt((void *)(emptyRewardSprite), position.v[0], position.v[1], 0x95, 0x88, 0x17, opacity);
            position.v[0] =(75.0f + (result->animation[4].current[0]));
            position.v[1] =(113.0f + (result->animation[4].current[1]));
            opacity = result->animation[4].opacity;
            sdkSpriteDrawAt((void *)(emptyRewardSprite), position.v[0], position.v[1], 0x95, 0x88, 0x17, opacity);
            position.v[0] =(75.0f + (result->animation[5].current[0]));
            position.v[1] =(172.0f + (result->animation[5].current[1]));
            opacity = result->animation[5].opacity;
            sdkSpriteDrawAt((void *)(emptyRewardSprite), position.v[0], position.v[1], 0x95, 0x88, 0x17, opacity);
        } else {
            labelGreen = 0;
            labelBlue = 0;
            labelRed = 0;
            awardValue = (((BtlResultWork *)p16)->awards.heroExp);
            position.v[0] =(75.0f + (result->animation[3].current[0]));
            position.v[1] =(52.0f + (result->animation[3].current[1]));
            moneyOpacity = (u8)((result->animation[3].opacity));
            btlResultSimpleDrawLabel(w, &position.v[0], 0.0f, moneyOpacity | (s32)0xEC7C0000, awardValue, 0);
            sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[6];
            sdkSpriteDrawAt(sprite, 5.0f + position.v[0], 9.0f + position.v[1], 0xEC, 0x7C, 0, moneyOpacity);
            experience = (u32)(btlXpBaseAward((u8 *)&p16->flags));
            position.v[0] =(75.0f + (result->animation[4].current[0]));
            position.v[1] =(112.0f + (result->animation[4].current[1]));
            experienceOpacity = (u8)((result->animation[4].opacity));
            btlResultSimpleDrawLabel(w, &position.v[0], 0.0f, experienceOpacity | (s32)0xEC7C0000, experience, 1);
            sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[7];
            sdkSpriteDrawAt(sprite, 5.0f + position.v[0], 9.0f + position.v[1], 0xEC, 0x7C, 0, experienceOpacity);
            position.v[0] =(73.0f + (result->animation[5].current[0]));
            position.v[1] =(162.0f + (result->animation[5].current[1]));
            itemOpacity = (u8)((result->animation[5].opacity));
            itemIndex = 0;
            while (itemIndex < (((BtlXpReward *)((BtlResultWork *)(u8 *)p16)->parameters)->itemCount)) {
                datEntryReset((u8 *)&itemRow);
                itemRecord = (u8 *)((u8 *)p16 + (itemIndex * 4));
                itemRow.a0 = (u16)((*(u16 *)&((BtlXpReward *)((BtlResultWork *)(u8 *)itemRecord)->parameters)->items[0].id));
                itemRow.a2 = (s16)((((BtlXpReward *)((BtlResultWork *)(u8 *)itemRecord)->parameters)->items[0].count));
                itemRow.b6 = 6;
                itemRow.b8 = 5;
                datEntryDrawRow(position.xy, 0.0f, itemOpacity, (u8 *)&itemRow);
                position.v[1] += 34.0f;
                itemIndex += 1;
            }
        }
        position.v[0] =(68.0f + (result->animation[3].current[0]));
        position.v[1] =(20.0f + (result->animation[3].current[1]));
        opacity = result->animation[3].opacity;
        sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[1];
        sdkSpriteDrawAt(sprite, position.v[0], position.v[1], labelRed, labelGreen, labelBlue, opacity);
        position.v[0] =(67.0f + (result->animation[4].current[0]));
        position.v[1] =(80.0f + (result->animation[4].current[1]));
        opacity = result->animation[4].opacity;
        sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[0];
        sdkSpriteDrawAt(sprite, position.v[0], position.v[1], labelRed, labelGreen, labelBlue, opacity);
        position.v[0] =(68.0f + (result->animation[5].current[0]));
        position.v[1] =(139.0f + (result->animation[5].current[1]));
        opacity = result->animation[5].opacity;
        sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[2];
        sdkSpriteDrawAt(sprite, position.v[0], position.v[1], labelRed, labelGreen, labelBlue, opacity);
        rectangle[0] = 0;
        rectangle[1] = 0x14;
        rectangle[2] = 0x46;
        rectangle[3] = 0xFA;
        color[0] = 0xFF;
        color[1] = 0xE9;
        color[2] = 0xE;
        color[3] = (u8)((result->animation[10].opacity));
        PrimDrawFlatRectangle(&color[0], (f32 *)&rectangle[0], 0.0f, 1);
        if (p16->flags & 4) {
            headingRed = 0x67;
            headingGreen = 0x5F;
            headingBlue = 0x1F;
        } else {
            headingRed = 0;
            headingGreen = 0;
            headingBlue = 0;
        }
        position.v[0] =(17.0f + (result->animation[0].current[0]));
        position.v[1] =(20.0f + (result->animation[0].current[1]));
        opacity = result->animation[0].opacity;
        sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[3];
        sdkSpriteDrawAt(sprite, position.v[0], position.v[1], headingRed, headingGreen, headingBlue, opacity);
        position.v[0] =(17.0f + (result->animation[1].current[0]));
        position.v[1] =(80.0f + (result->animation[1].current[1]));
        opacity = result->animation[1].opacity;
        sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[4];
        sdkSpriteDrawAt(sprite, position.v[0], position.v[1], headingRed, headingGreen, headingBlue, opacity);
        position.v[0] =(17.0f + (result->animation[2].current[0]));
        position.v[1] =(139.0f + (result->animation[2].current[1]));
        opacity = result->animation[2].opacity;
        sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[5];
        sdkSpriteDrawAt(sprite, position.v[0], position.v[1], headingRed, headingGreen, headingBlue, opacity);
        if (p16->flags & 4) {
            pulseIndex = 0;
            while (pulseIndex < 2) {
                pulseBase = (u8 *)(w + (pulseIndex * 8));
                pulse = (u8 *)(pulseBase + 0x560);
                pulseStyle = (u8 *)D_006295F0 + pulseIndex * 0xC;
                if (++(((BtlResultSimpleWork *)pulseBase)->pulses[0].frame) < (*(u16 *)pulseStyle)) {
                    goto skip_zero;
                }
                (((BtlResultPulse *)pulse)->frame) = 0;
            skip_zero:
                startOffset = (((BtlResultPulseStyle *)pulseStyle)->start);
                elapsed = (((BtlResultPulse *)pulse)->frame);
                elapsedFloat = (f32)elapsed;
                duration = (*(u16 *)pulseStyle);
                durationFloat = (f32)duration;
                endOffset = (((BtlResultPulseStyle *)pulseStyle)->end);
                (*(f32 *)pulse) = startOffset + (elapsedFloat / durationFloat) * (endOffset - startOffset);
                pulseIndex += 1;
            }
            coordinate = (f32)0x1D7;
            coordinate += (result->animation[15].current[0]);
            position.v[0] = coordinate;
            position.v[1] =(506.0f + (result->animation[15].current[1]));
            firstBannerOpacity = (result->animation[15].opacity);
            firstBannerSprite = (s32)(((BtlResultSimpleWork *)w)->field414[39]);
            shdEnableBlendFlag();
            sdkSpriteDrawSized((u8 *)firstBannerSprite, position.v[0], position.v[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, firstBannerOpacity, 0x1000, 0x1000, 0, -72.0f, (s64)0);
            shdDisableBlendFlag();
            coordinate = (f32)0x107;
            coordinate += (result->animation[16].current[0]);
            position.v[0] = coordinate;
            basePosition.v[0] = position.v[0];
            position.v[1] = (464.0f + (result->animation[16].current[1]));
            basePosition.v[1] = position.v[1];
            secondBannerOpacity = (result->animation[16].opacity);
            secondBannerSprite = (s32)(((BtlResultSimpleWork *)w)->field414[40]);
            shdEnableBlendFlag();
            sdkSpriteDrawSized((u8 *)secondBannerSprite, position.v[0], position.v[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, secondBannerOpacity, 0x1000, 0x1000, 0, -30.0f, (s64)0);
            shdDisableBlendFlag();
            position.v[0] =((result->animation[18].current[0]) + (((BtlResultSimpleWork *)w)->pulses[0].offset));
            position.v[1] =((result->animation[18].current[1]));
            shadowOpacity = (result->animation[18].opacity);
            shadowIndex = 0;
            while (shadowIndex < 3) {
                shadowBase = basePosition;
                offsetSnapshot = position;
                shadowBase.xy.y += 5.5f;
                /* Immutable snapshots keep the two draws on the same origin. */
                {
                    const f32 anchorY = shadowBase.xy.y;
                    const f32 drawX = offsetSnapshot.v[0] + shadowBase.xy.x;
                    const f32 drawY = offsetSnapshot.v[1] + anchorY;
                    sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[37];
                    sdkSpriteDrawSized(sprite, drawX, drawY, 0.0f, 0, 0, 0, shadowOpacity, (u16)fGpffff8410,
                        (u16)*(f32 *)&fGpffff8410, (s16)(shadowBase.xy.x - drawX), -30.0f, (s16)(shadowBase.xy.y - drawY));
                    nextDrawX = (fGpffff8414 + drawX);
                    sdkSpriteDrawSized((u8 *)((BtlResultSimpleWork *)w)->field414[38], nextDrawX, drawY, 0.0f, 0, 0, 0, shadowOpacity, (u16)fGpffff8410,
                        (u16)*(f32 *)&fGpffff8410, (s16)(shadowBase.xy.x - nextDrawX), -30.0f, (s16)(anchorY - drawY));
                }
                position.v[0] += fGpffff8418;
                shadowIndex += 1;
            }
            position.v[0] = ((result->animation[17].current[0]) - 88.0f);
            basePosition.v[0] = position.v[0];
            position.v[1] = (200.0f + (result->animation[17].current[1]));
            basePosition.v[1] = position.v[1];
            thirdBannerOpacity = (result->animation[17].opacity);
            thirdBannerSprite = (s32)(((BtlResultSimpleWork *)w)->field414[41]);
            shdEnableBlendFlag();
            sdkSpriteDrawSized((u8 *)thirdBannerSprite, position.v[0], position.v[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, thirdBannerOpacity, 0x1000, 0x1000, 0, 15.0f, (s64)0);
            shdDisableBlendFlag();
            position.v[0] =((result->animation[19].current[0]) + (((BtlResultSimpleWork *)w)->pulses[1].offset));
            position.v[1] =((result->animation[19].current[1]));
            secondaryShadowOpacity = (result->animation[19].opacity);
            secondaryShadowIndex = 0;
            while (secondaryShadowIndex < 3) {
                secondaryBase = basePosition;
                secondaryOffset = position;
                secondaryBase.xy.y += 10.0f;
                {
                    const f32 secondaryAnchorY = secondaryBase.xy.y;
                    const f32 secondaryDrawX = secondaryOffset.xy.x + secondaryBase.xy.x;
                    const f32 secondaryDrawY = secondaryOffset.xy.y + secondaryAnchorY;
                    /* A named floating scale preserves the per-argument conversion. */
                    scale = 4096.0f;
                    sprite = (u8 *)((BtlResultSimpleWork *)w)->field414[37];
                    sdkSpriteDrawSized(sprite, secondaryDrawX, secondaryDrawY, 0.0f, 0, 0, 0, secondaryShadowOpacity,
                        (u16)scale, (u16)scale, (s16)(secondaryBase.xy.x - secondaryDrawX), 15.0f,
                        (s16)(secondaryBase.xy.y - secondaryDrawY));
                    secondaryNextX = 225.0f + secondaryDrawX;
                    sdkSpriteDrawSized((u8 *)((BtlResultSimpleWork *)w)->field414[38], secondaryNextX, secondaryDrawY, 0.0f, 0, 0, 0, secondaryShadowOpacity,
                        (u16)scale, (u16)scale, (s16)(secondaryBase.xy.x - secondaryNextX), 15.0f,
                        (s16)(secondaryAnchorY - secondaryDrawY));
                }
                position.v[0] -= (f32) 0x157;
                secondaryShadowIndex += 1;
            }
        }
    }

}

#pragma pop
/* Release the result archive, adopted sprite banks, all sprite nodes and the work allocation. */
// FUN_002214D0
void btlResultSimpleTaskDestroy(u8 *unusedTask) {
    BtlResultSimpleWork *p;
    s32 i;
    s32 j;

    p = (BtlResultSimpleWork *)kwlnTaskGetWork();
    if (p->archiveAddress != 0) {
        H_Cdvd_Destroy((void *)p->archiveAddress);
        p->archiveAddress = 0;
    }
    for (i = 0; i < 3; i++) {
        s32 *el = (s32 *)((((u32)p) + ((u32)(i * 4))) + 0x400);
        if (*el != 0) {
            sdkSpriteRelease((void *)*el);
            *el = 0;
        }
    }
    for (j = 0; j < 0x2A; j++) {
        s32 *el = (s32 *)((((u32)p) + ((u32)(j * 4))) + 0x414);
        if (*el != 0) {
            sdkSpriteFreeNode((void *)*el);
            *el = 0;
        }
    }
    jtbl_008873EC[0](p);
}
// FUN_002215C0
/* Allocate the 0x578-byte simple-result work, register callbacks, and attach the parent result
 * work. */
s32 btlResultSimpleCreateTask(s32 parentTask) {
    BtlResultSimpleWork *result;
    u8 *work;
    u16 *parentWork;
    s32 task;

    chkmemAllocSiteTag(&D_00629628, 0x3A);
    work = (u8 *)(*jtbl_008873E8)(0x578, 0x40000);
    result = (BtlResultSimpleWork *)work;
    memset(work, 0, 0x578);
    task = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_006290F0), 0xF, 0, 0, btlResultSimpleUpdate, btlResultSimpleTaskDestroy, (u8 *)(work));
    parentWork = kwlnTaskGetWork(parentTask);
    *(s32 *)&result->state = 0;
    *(u16 * *)&result->field570 = parentWork;
    memset(work + 8, 0, 0x30);
    *(void (**)(u8 *, u8 *))&((BtlResultSimpleWork *)work)->drawCallback = btlResultSimpleDraw;
    *(u8 * *)&result->drawWork = work;
    return task;
}

// FUN_002216B0
void btlResultSimpleSetDoneFlag(void) {
    u16 *work;

    work = kwlnTaskGetWork();
    *work |= 1;
}

// FUN_002216E0
/* Choose the overlay or delayed-close path from the result flags. Typed frame/state stores retain the
 * existing halfword/word work-pointer representation. */
void btlResultSimpleOnConfirm(void) {
    u16 *work;

    work = kwlnTaskGetWork();
    if (work[0] & 0x80) {
        btlShuffleStartOverlay();
        *(s32 *)&((BtlResultSimpleWork *)work)->state = 5;
        return;
    }
    *(s16 *)&((BtlResultSimpleWork *)work)->field3C = 0;
    *(s32 *)&((BtlResultSimpleWork *)work)->state = 6;
}

// FUN_00221740
u16 btlResultSimpleIsDone(void) {
    u16 *work;

    work = kwlnTaskGetWork();
    return work[0] & 1;
}

// FUN_00221770
/* Choose date-dependent result resources, acquire both archives and request asynchronous asset setup. */
void btlResultSimpleSetupEntries(void) {
    s32 *dst;
    s32 i;
    BtlResultSimpleWork *work;

    work = (BtlResultSimpleWork *)kwlnTaskGetWork();
    {
        u32 r;
        r = (u32)calGetDayWindowFlags((s16)datGetDateIndex()) & 1;
        i = (0U < r) ^ 1U;
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1410);
    work->archiveAddress = (s32)H_Cdvd_AcquireDirectory(iGpffffa5a0[i], 1);
    if (work->archiveAddress == 0) {
        kAssertFail(&D_00629610, 1411);
    }
    i = 3;
    for (; i < 5; i++) {
        dst = (s32 *)((u8 *)work + i * 4 + 0x400);
        /* measured: the alias base is relative to slot three because plain array indexing changes
         * the address form. */
        *dst = resourceFindByName(((BtlResultResourceName *)((u8 *)iGpffffa5a8 + i * 4 - 12))->name);
        if (*dst == 0) {
            kAssertFail(&D_00629610, 1419);
        }
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1423);
    ((BtlResultWork *)work->field570)->file =
        (s32)H_Cdvd_AcquireDirectory((u8 *)iGpffffa5b0, 1);
    if (((BtlResultWork *)work->field570)->file == 0) {
        kAssertFail(&D_00629610, 1424);
    }
    work->flags |= 4;
}
