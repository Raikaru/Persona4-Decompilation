#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "sdk_snd_internal.h"
#include "sdktask.h"

/* ------------------------------------------------------------------ */
/* sdkSnd: Atlus sound wrapper over the PS2/CRI sound interfaces.     */
/* Channel table: 6 entries of 0x28 bytes (HsndSlotWork).             */
/* Voice slots: 16 entries of 0x134 bytes (SndCh).                    */
/* ------------------------------------------------------------------ */

typedef struct SndCh
{
    s32 active;       /* 0x000 */
    s32 fading;       /* 0x004 */
    s16 cueId;        /* 0x008 */
    s16 unkA;
    s16 state;        /* 0x00C */
    s16 unkE;
    s32 handle;       /* 0x010 */
    s16 requestMode;  /* 0x014 */
    s16 previousMode; /* 0x016 */
    char path[0x100]; /* 0x018 */
    s32 source;       /* 0x118 */
    s32 sourceAux;    /* 0x11C */
    s32 sourceSize;   /* 0x120 */
    u8 pad124[0xC];
    s16 previousCue;  /* 0x130 */
    s16 fadeFrames;   /* 0x132 */
} SndCh;              /* size 0x134 */

typedef struct HsndSlotWork
{
    s16 state;        /* 0x00 */
    s16 param2;       /* 0x02 */
    s16 param1;       /* 0x04 */
    s16 pad6;         /* 0x06 */
    u32 completed;    /* 0x08 */
    s16 callbackMode; /* 0x0C */
    s16 padE;         /* 0x0E */
    void* data0;      /* 0x10 */
    void* data1;      /* 0x14 */
    void* data2;      /* 0x18 */
    u32 data3;        /* 0x1C */
    u32 data4;        /* 0x20 */
    u32 data5;        /* 0x24 */
} HsndSlotWork;       /* size 0x28 */

/* The task constructor allocates 0x118 bytes and stores the path inline. */
typedef struct SdkSndStreamWork {
    s32 state;
    s32 stream;
    s32 unk8;
    s32 frame;
    u8 path[0x100];
    s32 callbackAddress;
    s32 requestAddress;
} SdkSndStreamWork;

#define SND_IDX(i) ((i) * 0x134)
#define SLOT_IDX(i) ((i) * 0x28)
#define LD16(a, i) (*(s16 *)&(a)[(i)])
#define LD32(a, i) (*(s32 *)&(a)[(i)])
#define CH_HANDLE(i) LD32(D_008D2BA0, (i))

/* Voice-slot table (16 x 0x134). */
extern SndCh D_008D2B90[];
extern u8 D_008D2B94[];
extern u8 D_008D2B98[];
extern u8 D_008D2B9C[];
extern u8 D_008D2BA0[];
extern u8 D_008D2BA4[];
extern u8 D_008D2BA6[];
extern u8 D_008D2BA8[];
extern u8 D_008D2CAC[];
extern u8 D_008D2CA8[];
extern u8 D_008D2CB0[];
extern u8 D_008D2CC0[];
extern u8 D_008D2CC2[];

/* Sound-channel table (6 x 0x28). */
extern HsndSlotWork D_008D3ED0[];
extern u8 D_008D3ED2[];
extern u8 D_008D3ED4[];
extern u8 D_008D3ED8[];
extern u8 D_008D3EDC[];
extern u8 D_008D3EE0[];
extern u8 D_008D3EE4[];
extern u8 D_008D3EE8[];
extern u8 D_008D3EEC[];
extern u8 D_008D3EF0[];
extern u8 D_008D3EF4[];

/* Channel control structures (4 x 0x28). */
extern u8 D_008D2A60[];
extern u8 D_008D2A64[];
extern u8 D_008D2A68[];
extern u8 D_008D2A70[];
extern u8 D_008D2A74[];
extern u8 D_008D2A78[];
extern u8 D_008D2A7C[];
extern u8 D_008D2A80[];
extern u8 D_008D2A88[];
extern u8 D_008D2A8C[];
extern u8 D_008D2A90[];
extern u8 D_008D2A98[];
extern u8 D_008D2A9C[];
extern u8 D_008D2AA0[];
extern u8 D_008D2AA4[];
extern u8 D_008D2AA8[];
extern u8 D_008D2AB0[];
extern u8 D_008D2AB4[];
extern u8 D_008D2AB8[];
extern u8 D_008D2AC0[];
extern u8 D_008D2AC4[];
extern u8 D_008D2AC8[];
extern u8 D_008D2ACC[];
extern u8 D_008D2AD0[];
extern u8 D_008D2AD8[];
extern u8 D_008D2ADC[];
extern u8 D_008D2AE0[];
extern u8 D_008D2AE8[];
extern u8 D_008D2AEC[];
extern u8 D_008D2AF0[];
extern u8 D_008D2AF4[];
extern u8 D_008D2AF8[];

/* Handles. */
extern s32 D_008D2B30[];
extern s32 D_008D2B34[];
extern s32 D_008D2B38[];
extern s32 D_008D2B3C[];
extern s32 D_008D2B50[];
extern s32 D_008D2B54[];
extern s32 D_008D2B58[];
extern s32 D_008D2B5C[];

/* Master control. */
extern f32 D_008D2B70[];
extern s32 D_008D2B74[];
extern s32 D_008D2B78[];
extern s32 D_008D2B7C[];

extern u8 D_008D2CD4[];
extern u8 D_008D2E08[];
extern u8 D_008D2F3C[];

/* Noise table. */
extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];
extern s16 D_008D2F38[];
extern s16 D_008D2F40[];
extern s16 D_008D2F42[];
extern s16 D_008D2F44[];

/* Sound-data tables (in .rodata/.data of this blob). */
extern u8 D_007118B4[];
extern u8 D_00711F24[];
extern char D_00712238[];
extern char D_00712250[];
extern char D_00712270[];
extern char D_00712290[];
extern char D_007122B0[];
extern char D_007122D0[];
extern char D_007122F0[];
extern char D_00712310[];
extern char D_008D1F10[];

/* Small-data (gp-relative) format strings and master volume. */
extern char D_00764000;
extern char D_00764008;
extern char D_00764010;
extern f32 D_00761124;

/* Allocator / task / debug tables. */
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);

/* Shared SDK blob helpers. */
extern void func_0043c0c0(s32, s32, s32, s32);
extern void memset(void *, s32, s32);
extern void chkmemAllocSiteTag(char *file, s32 line);

extern void func_00440b68(s32 fmt, ...);
extern s32 sprintf(void *buf, void *fmt, ...);
extern void strcpy();
extern void H_Cdvd_Destroy(void *handle);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern void kwlnTaskAddChild(void *parent, void *child);
extern void H_Cdvd_StreamOpenHandle(void*, const char*);
extern void H_Cdvd_StartStreamLoad();
extern void H_Cdvd_StreamOpenByPath(void*, const char*);
extern s32 func_004c7ef8(s32);
extern void func_004ccb50(void);
extern void func_004d5440(s32);
extern void func_004d8c78(void);
extern s32 func_004d8cc0(void *, s32, s32);
extern s32 func_004d8cf0(s32);
extern s32 func_004d8d10(void *);
extern void func_004d8d30(void*, const char*);
extern void func_004d8d48(s32, s32, s32);
extern void func_004d8d60(s32, s32, s32);
extern void func_004d8d78(s32, s32, s32);
extern void func_004d8d90(s32);
extern s32 func_004d8da8(s32, s32);
extern s32 func_004d8dc0(s32);
extern s32 func_004d8dd8(s32);
extern void func_004d8eb0(s32, s32);
extern void func_004d8ec8(s32, s32);
extern void func_004d8ee0(s32, s32);
extern void func_004d8e38(s32, s32);
extern void func_004d8e98(s32, s32);
extern void func_004d8f40(s32, s32);
extern void func_004d8f70(s32, s32);
extern void func_004d8fb8(s32);
extern void func_004d9038(s32, s32);
extern void func_004d90f8(void);
extern void func_004d9148(s32);
extern void func_004d9180(s32);
extern void func_004d91b8(s32);
extern void kAssertFail(void *file, s32 line);
extern void kAssertFailAt(const void *msg, const void *file, u32 line);
extern void mwPlyInitSfdFx(void *);

extern u32 hsndSlotIsStarting();
extern void hsndSlotUpdate(HsndSlotWork *slot);

s32 sdkSndStopChannelSlot(s32 channelIndex);
s32 sdkSndStartRequest(s32 channelIndex);
extern s32 sdkSndStreamTaskUpdate(u8 *task);
extern void sdkSndStreamTaskDestroy(u8 *task);

/* ================================================================== */
/* FUN_00458FA0                                                        */
/* ================================================================== */

// Intent: initialises the sound driver: the five channel records, their handles and buffers, and the default track table.
// FUN_00458FA0
/* measured: retail hoists the loop bases/0x134/-1 constants to the
   preheaders; mwcc rematerialises them, so the scoped pragma is required. */
#pragma opt_loop_invariants on
void sdkSndInit(void)
{
    s16 i, j;
    s32 temp, p, h;

    D_008D2B70[0] = D_00761124;
    D_008D2B74[0] = 1;
    D_008D2B78[0] = 1;
    D_008D2B7C[0] = 0;
    mwPlyInitSfdFx(D_008D2B70);
    func_004d8c78();
    func_004d90f8();
    func_004d5440(0x1E);
    memset(&D_008D2A60, 0, 0x28);
    D_008D2A74[0] = 1;
    LD32(D_008D2A78, 0) = 0;
    LD32(D_008D2A80, 0) = 0;
    LD32(D_008D2A7C, 0) = 0;
    LD32(D_008D2A60, 0) = 4;
    LD32(D_008D2A64, 0) = 2;
    LD32(D_008D2A68, 0) = 0xBB80;
    LD32(D_008D2A70, 0) = 1;
    temp = func_004d8d10(&D_008D2A60);
    chkmemAllocSiteTag(D_00712238, 0x94);
    p = (s32)(*(void *(**)(u32, u32))(s32)jtbl_008873E8)(temp, 0x40000);
    D_008D2B50[0] = p;
    D_008D2B30[0] = temp;
    h = (s32)func_004d8cc0(&D_008D2A60, p, temp);
    LD32(D_008D2BA0, 0) = h;
    func_004d8ec8(h, 1);
    func_004d8eb0(CH_HANDLE(0), 0x1E);
    func_004d8f40(CH_HANDLE(0), 0x23);
    func_004d8ee0(CH_HANDLE(0), 0xF);
    func_004d91b8(0x3C);
    func_004d9148(0xF);
    func_004d9180(0xB4);
    func_004d8f70(CH_HANDLE(0), 0xA);
    func_00440b68((s32)D_00712250, temp);
    memset(&D_008D2A88, 0, 0x28);
    D_008D2A9C[0] = 2;
    LD32(D_008D2AA0, 0) = 0;
    LD32(D_008D2AA8, 0) = 0;
    LD32(D_008D2AA4, 0) = 0;
    LD32(D_008D2A88, 0) = 4;
    LD32(D_008D2A8C, 0) = 1;
    LD32(D_008D2A90, 0) = 0x5DC0;
    LD32(D_008D2A98, 0) = 1;
    temp = func_004d8d10(&D_008D2A88);
    chkmemAllocSiteTag(D_00712238, 0xAB);
    D_008D2B54[0] = (s32)(*(void *(**)(u32, u32))(s32)jtbl_008873E8)(temp, 0x40000);
    D_008D2B34[0] = temp;
    LD32(D_008D2CD4, 0) = 0;
    func_00440b68((s32)D_00712270, temp);
    memset(&D_008D2AB0, 0, 0x28);
    D_008D2AC4[0] = 3;
    LD32(D_008D2AC8, 0) = 0;
    LD32(D_008D2AD0, 0) = 0;
    LD32(D_008D2ACC, 0) = 0;
    LD32(D_008D2AB0, 0) = 4;
    LD32(D_008D2AB4, 0) = 2;
    LD32(D_008D2AB8, 0) = 0x5DC0;
    LD32(D_008D2AC0, 0) = 1;
    temp = func_004d8d10(&D_008D2AB0);
    chkmemAllocSiteTag(D_00712238, 0xBA);
    D_008D2B58[0] = (s32)(*(void *(**)(u32, u32))(s32)jtbl_008873E8)(temp, 0x40000);
    D_008D2B38[0] = temp;
    LD32(D_008D2E08, 0) = 0;
    func_00440b68((s32)D_00712290, temp);
    memset(&D_008D2AD8, 0, 0x28);
    D_008D2AEC[0] = 3;
    LD32(D_008D2AF0, 0) = 0;
    LD32(D_008D2AF8, 0) = 0;
    LD32(D_008D2AF4, 0) = 0;
    LD32(D_008D2AD8, 0) = 4;
    LD32(D_008D2ADC, 0) = 2;
    LD32(D_008D2AE0, 0) = 0x5DC0;
    LD32(D_008D2AE8, 0) = 1;
    temp = func_004d8d10(&D_008D2AD8);
    chkmemAllocSiteTag(D_00712238, 0xC9);
    D_008D2B5C[0] = (s32)(*(void *(**)(u32, u32))(s32)jtbl_008873E8)(temp, 0x40000);
    D_008D2B3C[0] = temp;
    LD32(D_008D2F3C, 0) = 0;
    func_00440b68((s32)D_007122B0, temp);
    for (i = 0; i < 6; i++)
    {
        D_008D3ED0[i].state = 0;
        D_008D3ED0[i].completed = 0;
    }
    for (j = 0; j < 0x10; j++)
    {
        D_008D2B90[j].active = 0;
        D_008D2B90[j].unkA = 0;
        D_008D2B90[j].state = 0;
        D_008D2B90[j].previousCue = -1;
        D_008D2B90[j].requestMode = -1;
        D_008D2B90[j].previousMode = -1;
    }
}
/* measured: see the annotation above the matching `on` pragma (func_00458fa0). */
#pragma opt_loop_invariants off

// Intent: per-frame update of channels 1 to 4: advances each active channel's request state.
// FUN_004594C0
void sdkSndUpdate(void)
{
    s16 i;
    s32 j;
    SndCh *ch;
    s32 *handlePointer;
    s16 *state;
    s16 idx;
    s32 result;

    func_004ccb50();
    func_0043c0c0(3, 0x80, 0x7F, 0x7F);
    for (i = 0; i < 6; i++)
    {
        hsndSlotUpdate(&D_008D3ED0[i]);
    }
    if (D_008D2B90[0].active != 0)
    {
        if (LD32(D_008D2B94, 0) != 0 && LD16(D_008D2CC2, 0) != 0)
        {
            LD16(D_008D2CC2, 0)--;
            if (LD16(D_008D2CC2, 0) == 0)
            {
                func_004d8da8(CH_HANDLE(0), 1);
            }
        }
        func_004d9038(CH_HANDLE(0), 0);
        result = func_004d8dd8(CH_HANDLE(0));
        if (result == 3 || result == 0)
        {
            D_008D2B90[0].active = 0;
        }
        else if (result == 4)
        {
            sdkSndStopChannelSlot(0);
            sdkSndStartRequest(0);
            func_004d8e98(CH_HANDLE(0), 1);
        }
    }
    for (j = 1; (s16)j < 5; j = (s16)(j + 1))
    {
        ch = &D_008D2B90[(s16)j];
        if (ch->active != 0)
        {
            handlePointer = &ch->handle;
            result = func_004d8dd8(*handlePointer);
            if (result == 3 || result == 0)
            {
                ch->active = 0;
            }
            else if (result == 4)
            {
                idx = (s16)j;
                sdkSndStopChannelSlot(idx);
                sdkSndStartRequest(idx);
                func_004d8e98(*handlePointer, 1);
            }
            else
            {
                state = &ch->state;
                if (*state == 3)
                {
                    goto state_three;
                }
                switch (*state)
                {
                case 2:
                    goto state_two;
                default:
                    goto state_done;
                }
state_two:
                func_004d8d90(*handlePointer);
                *state = 1;
                goto state_done;
state_three:
                idx = (s16)j;
                sdkSndStartRequest(idx);
                *state = 1;
state_done:
                ;
            }
        }
    }
}

// Intent: stops channel 0 if it is active and clears its record. Returns 1.
// FUN_00459880
s32 sdkSndStopMainChannel(void)
{
    if (D_008D2B90[0].active != 0)
    {
        func_004d8d90(CH_HANDLE(0));
        D_008D2B90[0].active = 0;
        LD16(D_008D2B9C, 0) = 0;
        LD16(D_008D2B98, 0) = -1;
    }
    return 1;
}

/* ================================================================== */
/* FUN_004598E0                                                        */
/* ================================================================== */

/* Set the main channel fade duration, stop playback and clear its active request. */
// FUN_004598E0
s32 sdkSndStopChannel(s16 fadeFrames)
{
    func_004d8eb0(CH_HANDLE(0), fadeFrames);
    if (D_008D2B90[0].active != 0)
    {
        func_004d8d90(CH_HANDLE(0));
        D_008D2B90[0].active = 0;
        LD16(D_008D2B9C, 0) = 0;
        LD16(D_008D2B98, 0) = -1;
    }
    return 1;
}

/* ================================================================== */
/* FUN_00459950                                                        */
/* ================================================================== */

// Intent: sets channel 0's parameter word and the data pointer passed in.
// FUN_00459950
void sdkSndSetMainChannelData(void *data)
{
    func_004d8ee0(CH_HANDLE(0), 0xF);
    func_004d8e38(CH_HANDLE(0), (s32)data);
}

/* ================================================================== */
/* FUN_004599D0                                                        */
/* ================================================================== */

// Intent: stops the channel at the given index if it is active and clears its record. Returns 1.
// FUN_004599D0
s32 sdkSndStopChannelSlot(s32 channelIndex)
{
    if (D_008D2B90[channelIndex].active != 0)
    {
        func_004d8d90(LD32(D_008D2BA0, SND_IDX(channelIndex)));
        LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
        D_008D2B90[channelIndex].active = 0;
        LD16(D_008D2B98, SND_IDX(channelIndex)) = -1;
    }
    return 1;
}

/* ================================================================== */
/* FUN_00459A60                                                        */
/* ================================================================== */

// Intent: starts a fade on channel 0 once, when it is active and not already fading. Returns 0.
// FUN_00459A60
s32 sdkSndFadeMainChannel(void)
{
    if (D_008D2B90[0].active != 0 && LD32(D_008D2B94, 0) == 0)
    {
        func_004d8e38(CH_HANDLE(0), -0x3C0);
        LD32(D_008D2B94, 0) = 1;
        LD16(D_008D2CC2, 0) = 0x14;
    }
    return 0;
}

/* ================================================================== */
/* FUN_00459AD0                                                        */
/* ================================================================== */

/* MATCH: 2316B instructions plus one zero-tail word. Retail returns 1
   on both exits; a void declaration incorrectly keeps v0 live backward
   through call-free paths. Preserve the pre-destructor destination and
   constructor-record address lifetimes with dead assignments disabled. */
#pragma push
#pragma opt_dead_assignments off
typedef struct SndHandleRecord { s32 handle; u8 rest[0x130]; } SndHandleRecord;
typedef struct SndCreateRecord { u32 words[10]; } SndCreateRecord;
// Intent: starts the pending request for channelIndex (a stream open, a track or a handle create) according to its request mode. Returns 1.
// FUN_00459AD0
s32 sdkSndStartRequest(s32 channelIndex)
{
    char path[0x100];
    s32 handleValue;
    s16 modeValue;

    if (channelIndex == 0)
    {
        func_004d8e38(CH_HANDLE(0), -0x3C);
        sprintf(path, &D_00764000,
                     LD32(D_007118B4,
                          LD16(D_008D2B98, SND_IDX(channelIndex)) * 0xC));
        if (func_004d8dc0(CH_HANDLE(0)) != 0)
        {
            func_004d8da8(CH_HANDLE(0), 0);
        }
        if (LD16(D_008D2B98, 0) == 0x3D)
        {
            func_004d8ec8(CH_HANDLE(0), 1);
            func_004d8eb0(CH_HANDLE(0), 1);
            func_004d8f40(CH_HANDLE(0), 0xA);
        }
        else
        {
            func_004d8ec8(CH_HANDLE(0), 1);
            func_004d8eb0(CH_HANDLE(0), 0x1E);
            func_004d8f40(CH_HANDLE(0), 0x37);
        }
        func_004d8d30((void*)CH_HANDLE(0), path);
        func_004d8e98(CH_HANDLE(0), 1);
        D_008D2B90[channelIndex].active = 1;
        LD16(D_008D2B9C, SND_IDX(channelIndex)) = 1;
        return 1;
    }

    handleValue = CH_HANDLE(SND_IDX(channelIndex));
    if (handleValue != 0 &&
        (channelIndex != 2 || LD16(D_008D2BA6, SND_IDX(channelIndex)) != 0 ||
         LD16(D_008D2BA4, SND_IDX(channelIndex)) != 0))
    {
        s32* destination = &((SndHandleRecord*)D_008D2BA0)[channelIndex].handle;
        func_004d8cf0(handleValue);
        *destination = 0;
    }

    if (channelIndex == 1)
    {
        D_008D2A74[SLOT_IDX(channelIndex)] = 2;
    }
    else
    {
        D_008D2A74[SLOT_IDX(channelIndex)] = 3;
    }
    LD32(D_008D2A78, SLOT_IDX(channelIndex)) = 0;
    LD32(D_008D2A80, SLOT_IDX(channelIndex)) = 0;
    LD32(D_008D2A7C, SLOT_IDX(channelIndex)) = 0;
    LD32(D_008D2A60, SLOT_IDX(channelIndex)) = 2;
    LD32(D_008D2A64, SLOT_IDX(channelIndex)) = 2;
    LD32(D_008D2A68, SLOT_IDX(channelIndex)) = 0x5DC0;
    if (channelIndex == 1)
    {
        LD32(D_008D2A60, SLOT_IDX(channelIndex)) = 3;
        LD32(D_008D2A64, SLOT_IDX(channelIndex)) = 1;
    }

    modeValue = LD16(D_008D2BA4, SND_IDX(channelIndex));
    switch (modeValue)
    {
    case 6:
        LD32(D_008D2A80, SLOT_IDX(channelIndex)) = 0;
        LD32(D_008D2A70, SLOT_IDX(channelIndex)) = 1;
        CH_HANDLE(SND_IDX(channelIndex)) = func_004d8cc0(&((SndCreateRecord*)D_008D2A60)[channelIndex],
                                   D_008D2B50[channelIndex], D_008D2B30[channelIndex]);
        func_004d8ec8(CH_HANDLE(SND_IDX(channelIndex)), 0);
        if (channelIndex == 3)
        {
            func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0x5A);
        }
        else
        {
            func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0);
        }
        func_004d8f40(CH_HANDLE(SND_IDX(channelIndex)), 0);
        func_004d8f70(CH_HANDLE(SND_IDX(channelIndex)), 0);
        func_004d8d30((void*)CH_HANDLE(SND_IDX(channelIndex)),
                     ((char *)&D_008D2B90[channelIndex] + 0x18));
        func_004d8e98(CH_HANDLE(SND_IDX(channelIndex)), 1);
        break;

    case 0:
    case 1:
    case 5:
        if (channelIndex > 0)
        {
            if (modeValue == 0 || modeValue == 5)
            {
                LD32(D_008D2A80, SLOT_IDX(channelIndex)) = 0;
            }
            else
            {
                LD32(D_008D2A80, SLOT_IDX(channelIndex)) = 1;
            }
            LD32(D_008D2A70, SLOT_IDX(channelIndex)) = 1;
            if (CH_HANDLE(SND_IDX(channelIndex)) == 0)
            {
                CH_HANDLE(SND_IDX(channelIndex)) = func_004d8cc0(&((SndCreateRecord*)D_008D2A60)[channelIndex],
                                       D_008D2B50[channelIndex], D_008D2B30[channelIndex]);
                if (LD32(D_008D2A80, SLOT_IDX(channelIndex)) != 0)
                {
                    func_004d8fb8(CH_HANDLE(SND_IDX(channelIndex)));
                }
                func_004d8ec8(CH_HANDLE(SND_IDX(channelIndex)), 0);
                if (channelIndex == 3)
                {
                    func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0x5A);
                }
                else
                {
                    func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0);
                }
            }
        }
        func_004d8f40(CH_HANDLE(SND_IDX(channelIndex)), 0);
        func_004d8f70(CH_HANDLE(SND_IDX(channelIndex)), 0);
        if (LD16(D_008D2BA4, SND_IDX(channelIndex)) == 5)
        {
            func_004d8d48(CH_HANDLE(SND_IDX(channelIndex)), LD32(D_008D2CAC, SND_IDX(channelIndex)),
                         LD16(D_008D2B98, SND_IDX(channelIndex)));
        }
        else if (channelIndex != 0)
        {
            H_Cdvd_StreamOpenHandle((void*)CH_HANDLE(SND_IDX(channelIndex)),
                         ((char *)&D_008D2B90[channelIndex] + 0x18));
        }
        else
        {
            H_Cdvd_StreamOpenByPath((void*)CH_HANDLE(SND_IDX(channelIndex)),
                         ((char *)&D_008D2B90[channelIndex] + 0x18));
        }
        func_004d8e98(CH_HANDLE(SND_IDX(channelIndex)), 1);
        break;

    case 2:
    case 4:
        if (channelIndex > 0)
        {
            if (channelIndex == 1)
            {
                D_008D2A74[SLOT_IDX(channelIndex)] = 2;
            }
            else
            {
                D_008D2A74[SLOT_IDX(channelIndex)] = 3;
            }
            LD32(D_008D2A64, SLOT_IDX(channelIndex)) = 1;
            if (modeValue == 4)
            {
                LD32(D_008D2A80, SLOT_IDX(channelIndex)) = 0;
                LD32(D_008D2A64, SLOT_IDX(channelIndex)) = 2;
            }
            else
            {
                LD32(D_008D2A80, SLOT_IDX(channelIndex)) = 1;
            }
            LD32(D_008D2A70, SLOT_IDX(channelIndex)) = 0;
            CH_HANDLE(SND_IDX(channelIndex)) = func_004d8cc0(&((SndCreateRecord*)D_008D2A60)[channelIndex],
                                   D_008D2B50[channelIndex], D_008D2B30[channelIndex]);
            if (LD32(D_008D2A80, SLOT_IDX(channelIndex)) != 0)
            {
                func_004d8fb8(CH_HANDLE(SND_IDX(channelIndex)));
            }
            func_004d8ec8(CH_HANDLE(SND_IDX(channelIndex)), 0);
            if (channelIndex == 3)
            {
                func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0x5A);
            }
            else
            {
                func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0);
            }
        }
        func_004d8f40(CH_HANDLE(SND_IDX(channelIndex)), 0);
        func_004d8f70(CH_HANDLE(SND_IDX(channelIndex)), 0);
        func_004d8d60(CH_HANDLE(SND_IDX(channelIndex)), LD32(D_008D2CA8, SND_IDX(channelIndex)),
                     LD32(D_008D2CB0, SND_IDX(channelIndex)));
        break;

    case 3:
        if (channelIndex > 0)
        {
            D_008D2A74[SLOT_IDX(channelIndex)] = 3;
            LD32(D_008D2A64, SLOT_IDX(channelIndex)) = 2;
            LD32(D_008D2A70, SLOT_IDX(channelIndex)) = 0;
            CH_HANDLE(SND_IDX(channelIndex)) = func_004d8cc0(&((SndCreateRecord*)D_008D2A60)[channelIndex],
                                   D_008D2B50[channelIndex], D_008D2B30[channelIndex]);
            if (LD32(D_008D2A80, SLOT_IDX(channelIndex)) != 0)
            {
                func_004d8fb8(CH_HANDLE(SND_IDX(channelIndex)));
            }
            func_004d8ec8(CH_HANDLE(SND_IDX(channelIndex)), 0);
            if (channelIndex == 3)
            {
                func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0x1E);
            }
            else
            {
                func_004d8eb0(CH_HANDLE(SND_IDX(channelIndex)), 0);
            }
        }
        func_004d8f40(CH_HANDLE(SND_IDX(channelIndex)), 0);
        func_004d8f70(CH_HANDLE(SND_IDX(channelIndex)), 0);
        func_004d8d78(CH_HANDLE(SND_IDX(channelIndex)), LD32(D_008D2CA8, SND_IDX(channelIndex)),
                     LD32(D_008D2CAC, SND_IDX(channelIndex)));
        break;
    }
    D_008D2B90[channelIndex].active = 1;
    LD16(D_008D2B9C, SND_IDX(channelIndex)) = 1;
    return 1;
}
#pragma pop

/* Select a main-channel cue, restoring its volume if the same cue was fading. */
// FUN_0045A3E0
s32 sdkSndPlayCue(s16 cueId)
{
    s32 x, cur, v;

    x = (s16)cueId;
    if (!((u32)x < 0x31))
    {
        kAssertFail(D_00712238, 0x295);
    }
    cur = D_008D2B90[0].active;
    if (cur == 0)
    {
        v = -1;
    }
    else
    {
        v = LD16(D_008D2B98, 0);
    }
    if (x == v)
    {
        if (cur != 0 && LD32(D_008D2B94, 0) != 0)
        {
            LD32(D_008D2B94, 0) = 0;
            func_004d8e38(CH_HANDLE(0), -0x3C);
            if (func_004d8dc0(CH_HANDLE(0)) != 0)
            {
                func_004d8da8(CH_HANDLE(0), 0);
            }
        }
    }
    else
    {
        func_004d8e98(CH_HANDLE(0), 1);
        LD32(D_008D2B94, 0) = 0;
        D_008D2B90[0].active = 1;
        LD16(D_008D2B9C, 0) = 1;
        LD16(D_008D2CC0, 0) = LD16(D_008D2B98, 0);
        LD16(D_008D2B98, 0) = cueId;
        LD16(D_008D2BA6, 0) = LD16(D_008D2BA4, 0);
        LD16(D_008D2BA4, 0) = 0;
        sprintf(&D_008D2BA8[0], &D_00764008, LD32(D_007118B4, x * 0xC));
        sdkSndStartRequest(0);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045A570                                                        */
/* ================================================================== */

/* measured: 448/448B MATCH. Forward the raw slot word to readiness, narrow
   only for table access, and retain the constant success return. A void
   return changes register allocation (28 differing words). */
// Intent: queues a request on slotIndex by storing its six data words and marking it queued. Returns 1.
// FUN_0045A570
s32 sdkSndQueueSlotRequest(s32 slotIndex, void *input, u32 inputSize, void *intermediate, u32 intermediateSize, void *output, u32 outputSize)
{
    if (hsndSlotIsStarting(slotIndex) != 0)
    {
        D_008D3ED0[(s16)slotIndex].param2 = 999;
    }
    else if (D_008D3ED0[(s16)slotIndex].state == 3)
    {
        kAssertFail(D_00712238, 713);
    }
    D_008D3ED0[(s16)slotIndex].callbackMode = 1;
    D_008D3ED0[(s16)slotIndex].completed = 0;
    D_008D3ED0[(s16)slotIndex].param1 = (s16)slotIndex;
    D_008D3ED0[(s16)slotIndex].param2 = 999;
    D_008D3ED0[(s16)slotIndex].state = 2;
    D_008D3ED0[(s16)slotIndex].data0 = input;
    D_008D3ED0[(s16)slotIndex].data1 = intermediate;
    D_008D3ED0[(s16)slotIndex].data2 = output;
    D_008D3ED0[(s16)slotIndex].data3 = inputSize;
    D_008D3ED0[(s16)slotIndex].data4 = intermediateSize;
    D_008D3ED0[(s16)slotIndex].data5 = outputSize;
    return 1;
}
/* ================================================================== */
/* FUN_0045A730                                                        */
/* ================================================================== */

// Intent: sets the track id on slotIndex and marks it queued. Returns 1.
// FUN_0045A730
s32 sdkSndSetSlotTrack(s16 slotIndex, s16 trackId)
{
    if (hsndSlotIsStarting() != 0)
    {
        if (LD16(D_008D3ED2, SLOT_IDX(slotIndex)) == trackId)
        {
            return 1;
        }
    }
    else
    {
        if (D_008D3ED0[slotIndex].state == 3 &&
            trackId != LD16(D_008D3ED2, SLOT_IDX(slotIndex)))
        {
            kAssertFailAt(D_007122D0, D_00712238, 0x2E5);
        }
    }
    LD16(D_008D3EDC, SLOT_IDX(slotIndex)) = 0;
    LD32(D_008D3ED8, SLOT_IDX(slotIndex)) = 0;
    LD16(D_008D3ED4, SLOT_IDX(slotIndex)) = slotIndex;
    LD16(D_008D3ED2, SLOT_IDX(slotIndex)) = trackId;
    D_008D3ED0[slotIndex].state = 2;
    return 1;
}

/* ================================================================== */
/* FUN_0045A8D0                                                        */
/* ================================================================== */

/* Apply the default fade duration before stopping and resetting an active channel. */
// FUN_0045A8D0
s32 sdkSndFadeOutChannel(s16 channelIndex)
{
    if (D_008D2B90[channelIndex].active != 0)
    {
        func_004d8eb0(LD32(D_008D2BA0, SND_IDX(channelIndex)), 0x1E);
        if (D_008D2B90[channelIndex].active != 0)
        {
            func_004d8d90(LD32(D_008D2BA0, SND_IDX(channelIndex)));
            LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
            D_008D2B90[channelIndex].active = 0;
            LD16(D_008D2B98, SND_IDX(channelIndex)) = -1;
        }
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045A9A0                                                        */
/* ================================================================== */

// Intent: stops the channel at index arg0 if it is active and resets its record. Indexes of 5 or more are ignored. Returns 1.
// FUN_0045A9A0
s32 sdkSndResetChannel(s16 channelIndex)
{
    if (channelIndex < 5)
    {
        if (D_008D2B90[channelIndex].active != 0)
        {
            func_004d8d90(LD32(D_008D2BA0, SND_IDX(channelIndex)));
            LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
            D_008D2B90[channelIndex].active = 0;
            LD16(D_008D2B98, SND_IDX(channelIndex)) = -1;
        }
    }
    else
    {
        return 1;
    }
    D_008D2B90[channelIndex].active = 0;
    LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
    return 1;
}

/* ================================================================== */
/* FUN_0045AA90                                                        */
/* ================================================================== */

/* Forward a stop request to the selected decode-slot stream. */
// FUN_0045AA90
s32 sdkSndStopStream(s16 index, s16 stream)
{
    sdkSndStopStreamSlot(index, stream);
    return 1;
}

/* ================================================================== */
/* FUN_0045AAC0                                                        */
/* ================================================================== */

/* measured: found by tools/permute_sweep.py --engine ast at a 1200s budget;
   earlier hand probes of direct-table, pointer-temporary, parameter-type,
   remasked and pragma spellings all stalled at normalized_diff 7-12 on the
   argument-materialization order. */
/* Inherited matching-required source shape: retain its casts, comma expressions and reset carriers; only local names are recovered here. */
// FUN_0045AAC0
s32 sdkSndFadeOutChannelFrames(s16 channelIndex, s16 requestValue, s32 fadeFrames)
{
  int isActive;
  unsigned int channelValue;
  short channelValueShort;
  int indexOrReset;
  s16 channelOrReset;
  int channelOffset;
  s32 *handlePointer;
  short savedChannelValue;
  u8 *handleBytes;
  int inactive;
  int invalidCueMask;
  int indexOrInvalidCue;
  int channelStride;
  indexOrReset = channelIndex;
  channelOrReset = indexOrReset;
  channelValue = requestValue;
  func_00440b68((s32) D_007122F0, channelOrReset, channelValue, fadeFrames);
  if (channelIndex < ((5 - 1) + 1))
  {
    channelValue = D_008D2B90[channelIndex].active;
    inactive = 0;
    if (channelValue != inactive)
    {
      handleBytes = &D_008D2BA0[(7 * channelIndex) * 44];
      handlePointer = (s32 *) handleBytes;
      func_004d8eb0(*handlePointer, fadeFrames);
      channelValueShort = 0x134;
      ;
      isActive = D_008D2B90[channelIndex].active != 0;
      if (isActive)
      {
        func_004d8d90((unsigned long long) (*((s32 *) (&D_008D2BA0[channelIndex * channelValueShort]))));
        channelOffset = (indexOrInvalidCue = ((savedChannelValue, channelIndex)) * 0x134);
        indexOrInvalidCue = -1;
        savedChannelValue = channelValue;
        channelOrReset = (0, 0);
        *((s16 *) (&D_008D2B9C[channelOffset])) = channelOrReset;
        channelStride = 0x134;
        indexOrReset = 0x134 * 0;
        D_008D2B90[channelValueShort = channelIndex].active = indexOrReset;
        invalidCueMask = 0xFFFFFFFFFFFFFFFFu;
        *((s16 *) (&D_008D2B98[channelIndex * channelStride])) = (((((((((indexOrInvalidCue & invalidCueMask) & invalidCueMask) & invalidCueMask) & invalidCueMask) & invalidCueMask) & invalidCueMask) & invalidCueMask) & invalidCueMask) & invalidCueMask) & invalidCueMask;
      }
      channelValue = D_008D2B90[channelIndex].active;
    }
  }
  return 1;
}

/* Starts request mode three with the supplied source and auxiliary source value. */
// FUN_0045ABD0
s32 sdkSndStartSourceStream(s16 channelIndex, s32 source, s16 sourceAux)
{
    if (channelIndex < 5)
    {
        D_008D2B90[channelIndex].active = 1;
        LD32(D_008D2CAC, SND_IDX(channelIndex)) = sourceAux;
        LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
        LD16(D_008D2BA6, SND_IDX(channelIndex)) = LD16(D_008D2BA4, SND_IDX(channelIndex));
        LD16(D_008D2BA4, SND_IDX(channelIndex)) = 3;
        LD32(D_008D2CA8, SND_IDX(channelIndex)) = source;
        sdkSndStartRequest(channelIndex);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045AC90                                                        */
/* ================================================================== */

/* Starts buffer request mode two, whose creation record selects one channel. */
// FUN_0045AC90
s32 sdkSndStartMonoBuffer(s16 channelIndex, s32 source, s32 sourceSize)
{
    if (channelIndex < 5)
    {
        D_008D2B90[channelIndex].active = 1;
        LD16(D_008D2B98, SND_IDX(channelIndex)) = 0x3E7;
        LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
        LD16(D_008D2BA6, SND_IDX(channelIndex)) = LD16(D_008D2BA4, SND_IDX(channelIndex));
        LD16(D_008D2BA4, SND_IDX(channelIndex)) = 2;
        LD32(D_008D2CB0, SND_IDX(channelIndex)) = sourceSize;
        LD32(D_008D2CA8, SND_IDX(channelIndex)) = source;
        sdkSndStartRequest(channelIndex);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045AD50                                                        */
/* ================================================================== */

/* Starts buffer request mode four, whose creation record selects two channels. */
// FUN_0045AD50
s32 sdkSndStartStereoBuffer(s16 channelIndex, s32 source, s32 sourceSize)
{
    if (channelIndex < 5)
    {
        D_008D2B90[channelIndex].active = 1;
        LD16(D_008D2B98, SND_IDX(channelIndex)) = 0x3E7;
        LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
        LD16(D_008D2BA6, SND_IDX(channelIndex)) = LD16(D_008D2BA4, SND_IDX(channelIndex));
        LD16(D_008D2BA4, SND_IDX(channelIndex)) = 4;
        LD32(D_008D2CB0, SND_IDX(channelIndex)) = sourceSize;
        LD32(D_008D2CA8, SND_IDX(channelIndex)) = source;
        sdkSndStartRequest(channelIndex);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045AE10                                                        */
/* ================================================================== */

/* Starts request mode five with a source value and cue index. */
// FUN_0045AE10
s32 sdkSndStartIndexedSource(s32 sourceAux, s32 channelIndex, s32 cueId)
{
    D_008D2B90[channelIndex].active = 1;
    LD16(D_008D2B98, SND_IDX(channelIndex)) = cueId;
    LD32(D_008D2CAC, SND_IDX(channelIndex)) = sourceAux;
    LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
    LD16(D_008D2BA6, SND_IDX(channelIndex)) = LD16(D_008D2BA4, SND_IDX(channelIndex));
    LD16(D_008D2BA4, SND_IDX(channelIndex)) = 5;
    sdkSndStartRequest(channelIndex);
    return 1;
}

/* ================================================================== */
/* FUN_0045AEB0                                                        */
/* ================================================================== */

/* Copy a path into the selected channel and start its file-backed request. */
// FUN_0045AEB0
s32 sdkSndStartChannel(s16 channelIndex, const char * path)
{
    SndCh *ch;

    if (channelIndex < 5)
    {
        ch = &D_008D2B90[channelIndex];
        ch->active = 1;
        LD16(D_008D2B98, SND_IDX(channelIndex)) = 0;
        LD16(D_008D2B9C, SND_IDX(channelIndex)) = 0;
        LD16(D_008D2BA6, SND_IDX(channelIndex)) = LD16(D_008D2BA4, SND_IDX(channelIndex));
        LD16(D_008D2BA4, SND_IDX(channelIndex)) = 0;
        strcpy((u8 *)ch + 0x18, path, ch, SND_IDX(channelIndex));
        sdkSndStartRequest(channelIndex);
    }
    return 1;
}
/* ================================================================== */
/* FUN_0045AF60                                                        */
/* ================================================================== */

/* Forward the stream start parameters to the selected decode slot. */
// FUN_0045AF60
s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags)
{
    sdkSndStartStreamSlot(index, stream, value, flags);
    return 1;
}

/* ================================================================== */
/* FUN_0045AF90                                                        */
/* ================================================================== */

// Intent: returns 1 while channelIndex's handle is playing; the fourth channel never reports playing.
// FUN_0045AF90
s32 sdkSndIsChannelPlaying(s16 channelIndex)
{
    s32 r;

    if (channelIndex == 4)
    {
        return 0;
    }
    if (D_008D2B90[channelIndex].active != 0)
    {
        r = func_004d8dd8(LD32(D_008D2BA0, SND_IDX(channelIndex)));
        if (r == 3 || r == 0)
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

/* ================================================================== */
/* FUN_0045B030                                                        */
/* ================================================================== */

// Intent: state machine of a stream-load task: opens the stream, waits for it to finish, and marks the task done or failed.
// FUN_0045B030
s32 sdkSndStreamTaskUpdate(u8 *task)
{
    s32 state;
    s32 result;
    u8 *work;
    u8 *callback;

    work = ((SdkTask *)task)->work;
    state = ((SdkSndStreamWork *)work)->state;
    switch (state)
    {
    case 0:
        ((SdkSndStreamWork *)work)->frame = 0;
        callback = (u8 *)((SdkSndStreamWork *)work)->callbackAddress;
        if (callback == NULL)
        {
            H_Cdvd_StartStreamLoad(((SdkSndStreamWork *)work)->stream, work + 0x10, 0, &D_008D1F10);
        }
        else
        {
            H_Cdvd_StartStreamLoad(((SdkSndStreamWork *)work)->stream, work + 0x10, 0, callback);
        }
        ((SdkSndStreamWork *)work)->state = 1;
        break;
    case 1:
        ((SdkSndStreamWork *)work)->frame = ((SdkSndStreamWork *)work)->frame + 1;
        result = func_004c7ef8(((SdkSndStreamWork *)work)->stream);
        if (result == 4)
        {
            ((SdkSndStreamWork *)work)->state = 0;
        }
        else if (result == 3)
        {
            ((SdkSndStreamWork *)work)->state = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}
/* ================================================================== */
/* FUN_0045B120                                                        */
/* ================================================================== */

// Intent: destroy callback for a stream-load task: frees its handle and its work block.
/* measured: typing the final request-address clear loses MATCH; the preceding request test and release remain typed. */
// FUN_0045B120
void sdkSndStreamTaskDestroy(u8 *task)
{
    u8 *w;

    w = ((SdkTask *)task)->work;
    if (((SdkSndStreamWork *)w)->requestAddress != 0)
    {
        H_Cdvd_Destroy((void *)((SdkSndStreamWork *)w)->requestAddress);
        *(s32 *)(w + 0x114) = 0;
    }
    jtbl_008873EC[0](w);
}

/* ================================================================== */
/* FUN_0045B170                                                        */
/* ================================================================== */

// Intent: destroys the stream-load task and its hierarchy once it is done. Returns 1 when it destroyed the task.
// FUN_0045B170
s32 sdkSndStreamTaskReap(void *task)
{
    if (((SdkSndStreamWork *)((SdkTask *)task)->work)->state == 2)
    {
        kwlnTaskDestroyWithHierarchy((s32)task);
        return 1;
    }
    return 0;
}

/* ================================================================== */
/* FUN_0045B1C0                                                        */
/* ================================================================== */

// Intent: creates a stream-load task under parent for the given stream and copies the path into its record.
// FUN_0045B1C0
s32 sdkSndCreateStreamTask(void *parent, s32 stream, s32 callbackAddress, void *path)
{
    s32 h;
    u8 *p;

    chkmemAllocSiteTag(D_00712238, 0x475);
    p = D_008873F4[0](1, 0x118, 0x40000);
    if (p == NULL)
    {
        return 0;
    }
    h = (s32)kwlnTaskCreate((const void *)(&D_00712310[0]), 0, 0, 0, sdkSndStreamTaskUpdate, sdkSndStreamTaskDestroy, (u8 *)(p));
    if (h == 0)
    {
        return 0;
    }
    kwlnTaskAddChild(parent, (void *)h);
    ((SdkSndStreamWork *)p)->stream = stream;
    ((SdkSndStreamWork *)p)->callbackAddress = callbackAddress;
    strcpy((s32)(p + 0x10), (s32)path);
    return h;
}

/* ================================================================== */
/* FUN_0045B2E0                                                        */
/* ================================================================== */

/* Resolve a track path, select the stream request mode and start channel three. */
// FUN_0045B2E0
s32 sdkSndRequestTrack(s32 trackId)
{
    u8 buf[0x100];

    if (!((u32)trackId < 0x42))
    {
        kAssertFail(D_00712238, 0x50A);
    }
    if (D_008D2F2C[0] != 0 && trackId == D_008D2F34[0])
    {
        return 1;
    }
    sprintf(buf, &D_00764010, LD32(D_00711F24, trackId * 0xC));
    D_008D2F2C[0] = 1;
    D_008D2F34[0] = 0;
    D_008D2F38[0] = 0;
    D_008D2F42[0] = D_008D2F40[0];
    D_008D2F40[0] = 6;
    strcpy(&D_008D2F44[0], (char *)buf);
    sdkSndStartRequest(3);
    if (trackId <= 0)
    {
        kAssertFail(D_00712238, 0x510);
    }
    D_008D2F34[0] = trackId;
    return 1;
}
