#include "type.h"
#include "include_asm.h"

/* ------------------------------------------------------------------ */
/* sdkSnd: Sony SDK PS2 sound library (shared blob with P3 FES).      */
/* Channel table: 6 entries of 0x28 bytes (HsndSlotWork).             */
/* Voice slots: 16 entries of 0x134 bytes (SndCh).                    */
/* ------------------------------------------------------------------ */

typedef struct SndCh
{
    s32 f00;         /* 0x000 */
    s32 f04;         /* 0x004 */
    s16 f08;         /* 0x008 */
    s16 f0A;         /* 0x00A */
    s16 f0C;         /* 0x00C */
    s16 f0E;         /* 0x00E */
    s32 f10;         /* 0x010 */
    s16 f14;         /* 0x014 */
    s16 f16;         /* 0x016 */
    s16 f18;         /* 0x018 */
    s16 f1A;         /* 0x01A */
    s32 f1C;         /* 0x01C */
    u8 pad20[0x110]; /* 0x020 */
    s16 f130;        /* 0x130 */
    s16 f132;        /* 0x132 */
} SndCh;             /* size 0x134 */

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
extern void *(*D_008873F4[])(s32, s32, u32);

/* Shared SDK blob helpers. */
extern void func_0043c0c0(s32, s32, s32, s32);
extern void func_0043f9c8(void *, s32, s32);
extern void func_0044ea90(char *file, s32 line);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close,
                        void *buf);
extern void func_00440b68(s32 fmt, ...);
extern s32 func_00442088(void *buf, void *fmt, ...);
extern void func_00442830();
extern void func_00454bd0(void *handle);
extern void func_00452080(s32 handle);
extern void func_00452570(void *parent, void *child);
extern void func_00456370(s32, s32);
extern void func_00456250();
extern void func_004562e0(s32, s32);
extern s32 func_004c7ef8(s32);
extern void func_004ccb50(void);
extern void func_004d5440(s32);
extern void func_004d8c78(void);
extern s32 func_004d8cc0(void *, s32, s32);
extern s32 func_004d8cf0(s32);
extern s32 func_004d8d10(void *);
extern void func_004d8d30(s32, s32);
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
extern void func_0046d730(s32 file, s32 line);
extern void func_0046d740(s32 msg, s32 file, s32 line, ...);
extern void func_0050b3f8(void *);

extern u32 func_0045a890();
extern void func_00459790(HsndSlotWork *slot);
extern void func_0045c510(void);
extern void func_0045c640(void);

s32 func_004599d0(s32 arg0);
void func_00459ad0(s32 arg0);
extern s32 func_0045b030(void *arg0);
extern void func_0045b120(void *arg0);

/* ================================================================== */
/* FUN_00458FA0                                                        */
/* ================================================================== */

// FUN_00458FA0
/* measured: retail hoists the loop bases/0x134/-1 constants to the
   preheaders; mwcc rematerialises them, so the scoped pragma is required. */
#pragma opt_loop_invariants on
void func_00458fa0(void)
{
    s16 i, j;
    s32 temp, p, h;

    D_008D2B70[0] = D_00761124;
    D_008D2B74[0] = 1;
    D_008D2B78[0] = 1;
    D_008D2B7C[0] = 0;
    func_0050b3f8(D_008D2B70);
    func_004d8c78();
    func_004d90f8();
    func_004d5440(0x1E);
    func_0043f9c8(&D_008D2A60, 0, 0x28);
    D_008D2A74[0] = 1;
    LD32(D_008D2A78, 0) = 0;
    LD32(D_008D2A80, 0) = 0;
    LD32(D_008D2A7C, 0) = 0;
    LD32(D_008D2A60, 0) = 4;
    LD32(D_008D2A64, 0) = 2;
    LD32(D_008D2A68, 0) = 0xBB80;
    LD32(D_008D2A70, 0) = 1;
    temp = func_004d8d10(&D_008D2A60);
    func_0044ea90(D_00712238, 0x94);
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
    func_0043f9c8(&D_008D2A88, 0, 0x28);
    D_008D2A9C[0] = 2;
    LD32(D_008D2AA0, 0) = 0;
    LD32(D_008D2AA8, 0) = 0;
    LD32(D_008D2AA4, 0) = 0;
    LD32(D_008D2A88, 0) = 4;
    LD32(D_008D2A8C, 0) = 1;
    LD32(D_008D2A90, 0) = 0x5DC0;
    LD32(D_008D2A98, 0) = 1;
    temp = func_004d8d10(&D_008D2A88);
    func_0044ea90(D_00712238, 0xAB);
    D_008D2B54[0] = (s32)(*(void *(**)(u32, u32))(s32)jtbl_008873E8)(temp, 0x40000);
    D_008D2B34[0] = temp;
    LD32(D_008D2CD4, 0) = 0;
    func_00440b68((s32)D_00712270, temp);
    func_0043f9c8(&D_008D2AB0, 0, 0x28);
    D_008D2AC4[0] = 3;
    LD32(D_008D2AC8, 0) = 0;
    LD32(D_008D2AD0, 0) = 0;
    LD32(D_008D2ACC, 0) = 0;
    LD32(D_008D2AB0, 0) = 4;
    LD32(D_008D2AB4, 0) = 2;
    LD32(D_008D2AB8, 0) = 0x5DC0;
    LD32(D_008D2AC0, 0) = 1;
    temp = func_004d8d10(&D_008D2AB0);
    func_0044ea90(D_00712238, 0xBA);
    D_008D2B58[0] = (s32)(*(void *(**)(u32, u32))(s32)jtbl_008873E8)(temp, 0x40000);
    D_008D2B38[0] = temp;
    LD32(D_008D2E08, 0) = 0;
    func_00440b68((s32)D_00712290, temp);
    func_0043f9c8(&D_008D2AD8, 0, 0x28);
    D_008D2AEC[0] = 3;
    LD32(D_008D2AF0, 0) = 0;
    LD32(D_008D2AF8, 0) = 0;
    LD32(D_008D2AF4, 0) = 0;
    LD32(D_008D2AD8, 0) = 4;
    LD32(D_008D2ADC, 0) = 2;
    LD32(D_008D2AE0, 0) = 0x5DC0;
    LD32(D_008D2AE8, 0) = 1;
    temp = func_004d8d10(&D_008D2AD8);
    func_0044ea90(D_00712238, 0xC9);
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
        D_008D2B90[j].f00 = 0;
        D_008D2B90[j].f0A = 0;
        D_008D2B90[j].f0C = 0;
        D_008D2B90[j].f130 = -1;
        D_008D2B90[j].f14 = -1;
        D_008D2B90[j].f16 = -1;
    }
}
/* measured: see the annotation above the matching `on` pragma (func_00458fa0). */
#pragma opt_loop_invariants off

// FUN_004594C0
void func_004594c0(void)
{
    s16 i;
    s32 j;
    SndCh *ch;
    s32 *f10;
    s16 *state;
    s16 idx;
    s32 result;

    func_004ccb50();
    func_0043c0c0(3, 0x80, 0x7F, 0x7F);
    for (i = 0; i < 6; i++)
    {
        func_00459790(&D_008D3ED0[i]);
    }
    if (D_008D2B90[0].f00 != 0)
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
            D_008D2B90[0].f00 = 0;
        }
        else if (result == 4)
        {
            func_004599d0(0);
            func_00459ad0(0);
            func_004d8e98(CH_HANDLE(0), 1);
        }
    }
    for (j = 1; (s16)j < 5; j = (s16)(j + 1))
    {
        ch = &D_008D2B90[(s16)j];
        if (ch->f00 != 0)
        {
            f10 = &ch->f10;
            result = func_004d8dd8(*f10);
            if (result == 3 || result == 0)
            {
                ch->f00 = 0;
            }
            else if (result == 4)
            {
                idx = (s16)j;
                func_004599d0(idx);
                func_00459ad0(idx);
                func_004d8e98(*f10, 1);
            }
            else
            {
                state = &ch->f0C;
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
                func_004d8d90(*f10);
                *state = 1;
                goto state_done;
state_three:
                idx = (s16)j;
                func_00459ad0(idx);
                *state = 1;
state_done:
                ;
            }
        }
    }
}

// FUN_00459880
s32 func_00459880(void)
{
    if (D_008D2B90[0].f00 != 0)
    {
        func_004d8d90(CH_HANDLE(0));
        D_008D2B90[0].f00 = 0;
        LD16(D_008D2B9C, 0) = 0;
        LD16(D_008D2B98, 0) = -1;
    }
    return 1;
}

/* ================================================================== */
/* FUN_004598E0                                                        */
/* ================================================================== */

// FUN_004598E0
s32 func_004598e0(s16 arg0)
{
    func_004d8eb0(CH_HANDLE(0), arg0);
    if (D_008D2B90[0].f00 != 0)
    {
        func_004d8d90(CH_HANDLE(0));
        D_008D2B90[0].f00 = 0;
        LD16(D_008D2B9C, 0) = 0;
        LD16(D_008D2B98, 0) = -1;
    }
    return 1;
}

/* ================================================================== */
/* FUN_00459950                                                        */
/* ================================================================== */

// FUN_00459950
void func_00459950(void *arg0)
{
    func_004d8ee0(CH_HANDLE(0), 0xF);
    func_004d8e38(CH_HANDLE(0), (s32)arg0);
}

/* ================================================================== */
/* FUN_004599D0                                                        */
/* ================================================================== */

// FUN_004599D0
s32 func_004599d0(s32 arg0)
{
    if (D_008D2B90[arg0].f00 != 0)
    {
        func_004d8d90(LD32(D_008D2BA0, SND_IDX(arg0)));
        LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
        D_008D2B90[arg0].f00 = 0;
        LD16(D_008D2B98, SND_IDX(arg0)) = -1;
    }
    return 1;
}

/* ================================================================== */
/* FUN_00459A60                                                        */
/* ================================================================== */

// FUN_00459A60
s32 func_00459a60(void)
{
    if (D_008D2B90[0].f00 != 0 && LD32(D_008D2B94, 0) == 0)
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

/* measured: every case body, the dispatch table shape and the arg0==0
   branch compile correctly (nd 448, obj 2216B vs window 2320B), but mwcc
   b210 puts arg0 in $s0 where retail keeps it in $s1, cascading a saved
   register rotation through the whole else-branch/switch (handle ptr,
   switch-value ptr, A80 ptr all shift by one). Tried idx/idx28 locals,
   inline SND_IDX/SLOT_IDX, SND_IDX in the ==0 branch; nd only moved 517
   -> 448. Saved-register rotation floor. */
// FUN_00459AD0
INCLUDE_ASM("asm/nonmatchings/sdkSnd", func_00459ad0);

// FUN_0045A3E0
s32 func_0045a3e0(s16 arg0)
{
    s32 x, cur, v;

    x = (s16)arg0;
    if (!((u32)x < 0x31))
    {
        func_0046d730((s32)D_00712238, 0x295);
    }
    cur = D_008D2B90[0].f00;
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
        D_008D2B90[0].f00 = 1;
        LD16(D_008D2B9C, 0) = 1;
        LD16(D_008D2CC0, 0) = LD16(D_008D2B98, 0);
        LD16(D_008D2B98, 0) = arg0;
        LD16(D_008D2BA6, 0) = LD16(D_008D2BA4, 0);
        LD16(D_008D2BA4, 0) = 0;
        func_00442088(&D_008D2BA8[0], &D_00764008, LD32(D_007118B4, x * 0xC));
        func_00459ad0(0);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045A570                                                        */
/* ================================================================== */

/* measured: retail allocates each branch's sign-ext/index/value temps to
   $v1/$a0/$v1-$v0 while mwcc b210 shifts them to $a0/$a1/$a0-$v1 in all
   three blocks of this 7-arg body (nd 28, ~20 ! rows); the same spelling
   matches the 2-arg sibling func_0045a730. Tried nested else, call-result
   local; identical output. Temp-register rotation floor. */
// FUN_0045A570
INCLUDE_ASM("asm/nonmatchings/sdkSnd", func_0045a570);
/* ================================================================== */
/* FUN_0045A730                                                        */
/* ================================================================== */

// FUN_0045A730
s32 func_0045a730(s16 arg0, s16 arg1)
{
    if (func_0045a890() != 0)
    {
        if (LD16(D_008D3ED2, SLOT_IDX(arg0)) == arg1)
        {
            return 1;
        }
    }
    else
    {
        if (D_008D3ED0[arg0].state == 3 &&
            arg1 != LD16(D_008D3ED2, SLOT_IDX(arg0)))
        {
            func_0046d740((s32)D_007122D0, (s32)D_00712238, 0x2E5);
        }
    }
    LD16(D_008D3EDC, SLOT_IDX(arg0)) = 0;
    LD32(D_008D3ED8, SLOT_IDX(arg0)) = 0;
    LD16(D_008D3ED4, SLOT_IDX(arg0)) = arg0;
    LD16(D_008D3ED2, SLOT_IDX(arg0)) = arg1;
    D_008D3ED0[arg0].state = 2;
    return 1;
}

/* ================================================================== */
/* FUN_0045A8D0                                                        */
/* ================================================================== */

// FUN_0045A8D0
s32 func_0045a8d0(s16 arg0)
{
    if (D_008D2B90[arg0].f00 != 0)
    {
        func_004d8eb0(LD32(D_008D2BA0, SND_IDX(arg0)), 0x1E);
        if (D_008D2B90[arg0].f00 != 0)
        {
            func_004d8d90(LD32(D_008D2BA0, SND_IDX(arg0)));
            LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
            D_008D2B90[arg0].f00 = 0;
            LD16(D_008D2B98, SND_IDX(arg0)) = -1;
        }
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045A9A0                                                        */
/* ================================================================== */

// FUN_0045A9A0
s32 func_0045a9a0(s16 arg0)
{
    if (arg0 < 5)
    {
        if (D_008D2B90[arg0].f00 != 0)
        {
            func_004d8d90(LD32(D_008D2BA0, SND_IDX(arg0)));
            LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
            D_008D2B90[arg0].f00 = 0;
            LD16(D_008D2B98, SND_IDX(arg0)) = -1;
        }
    }
    else
    {
        return 1;
    }
    D_008D2B90[arg0].f00 = 0;
    LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
    return 1;
}

/* ================================================================== */
/* FUN_0045AA90                                                        */
/* ================================================================== */

// FUN_0045AA90
s32 func_0045aa90(void)
{
    func_0045c510();
    return 1;
}

/* ================================================================== */
/* FUN_0045AAC0                                                        */
/* ================================================================== */

/* measured: found by tools/permute_sweep.py --engine ast at a 1200s budget;
   earlier hand probes of direct-table, pointer-temporary, parameter-type,
   remasked and pragma spellings all stalled at normalized_diff 7-12 on the
   argument-materialization order. */
// FUN_0045AAC0
s32 func_0045aac0(s16 arg0, s16 arg1, s32 arg2)
{
  int new_var3;
  unsigned int new_var;
  short new_var7;
  int new_var12;
  s16 new_var10;
  int new_var2;
  s32 *new_var6;
  short new_var8;
  u8 *new_var5;
  int new_var13;
  int new_var11;
  int new_var4;
  int new_var9;
  new_var12 = arg0;
  new_var10 = new_var12;
  new_var = arg1;
  func_00440b68((s32) D_007122F0, new_var10, new_var, arg2);
  if (arg0 < ((5 - 1) + 1))
  {
    new_var = D_008D2B90[arg0].f00;
    new_var13 = 0;
    if (new_var != new_var13)
    {
      new_var5 = &D_008D2BA0[(7 * arg0) * 44];
      new_var6 = (s32 *) new_var5;
      func_004d8eb0(*new_var6, arg2);
      new_var7 = 0x134;
      ;
      new_var3 = D_008D2B90[arg0].f00 != 0;
      if (new_var3)
      {
        func_004d8d90((unsigned long long) (*((s32 *) (&D_008D2BA0[arg0 * new_var7]))));
        new_var2 = (new_var4 = ((new_var8, arg0)) * 0x134);
        new_var4 = -1;
        new_var8 = new_var;
        new_var10 = (0, 0);
        *((s16 *) (&D_008D2B9C[new_var2])) = new_var10;
        new_var9 = 0x134;
        new_var12 = 0x134 * 0;
        D_008D2B90[new_var7 = arg0].f00 = new_var12;
        new_var11 = 0xFFFFFFFFFFFFFFFFu;
        *((s16 *) (&D_008D2B98[arg0 * new_var9])) = (((((((((new_var4 & new_var11) & new_var11) & new_var11) & new_var11) & new_var11) & new_var11) & new_var11) & new_var11) & new_var11) & new_var11;
      }
      new_var = D_008D2B90[arg0].f00;
    }
  }
  return 1;
}

// FUN_0045ABD0
s32 func_0045abd0(s16 arg0, s32 arg1, s16 arg2)
{
    if (arg0 < 5)
    {
        D_008D2B90[arg0].f00 = 1;
        LD32(D_008D2CAC, SND_IDX(arg0)) = arg2;
        LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
        LD16(D_008D2BA6, SND_IDX(arg0)) = LD16(D_008D2BA4, SND_IDX(arg0));
        LD16(D_008D2BA4, SND_IDX(arg0)) = 3;
        LD32(D_008D2CA8, SND_IDX(arg0)) = arg1;
        func_00459ad0(arg0);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045AC90                                                        */
/* ================================================================== */

// FUN_0045AC90
s32 func_0045ac90(s16 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 5)
    {
        D_008D2B90[arg0].f00 = 1;
        LD16(D_008D2B98, SND_IDX(arg0)) = 0x3E7;
        LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
        LD16(D_008D2BA6, SND_IDX(arg0)) = LD16(D_008D2BA4, SND_IDX(arg0));
        LD16(D_008D2BA4, SND_IDX(arg0)) = 2;
        LD32(D_008D2CB0, SND_IDX(arg0)) = arg2;
        LD32(D_008D2CA8, SND_IDX(arg0)) = arg1;
        func_00459ad0(arg0);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045AD50                                                        */
/* ================================================================== */

// FUN_0045AD50
s32 func_0045ad50(s16 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 5)
    {
        D_008D2B90[arg0].f00 = 1;
        LD16(D_008D2B98, SND_IDX(arg0)) = 0x3E7;
        LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
        LD16(D_008D2BA6, SND_IDX(arg0)) = LD16(D_008D2BA4, SND_IDX(arg0));
        LD16(D_008D2BA4, SND_IDX(arg0)) = 4;
        LD32(D_008D2CB0, SND_IDX(arg0)) = arg2;
        LD32(D_008D2CA8, SND_IDX(arg0)) = arg1;
        func_00459ad0(arg0);
    }
    return 1;
}

/* ================================================================== */
/* FUN_0045AE10                                                        */
/* ================================================================== */

// FUN_0045AE10
s32 func_0045ae10(s32 arg0, s32 arg1, s16 arg2)
{
    D_008D2B90[arg1].f00 = 1;
    LD16(D_008D2B98, SND_IDX(arg1)) = arg2;
    LD32(D_008D2CAC, SND_IDX(arg1)) = arg0;
    LD16(D_008D2B9C, SND_IDX(arg1)) = 0;
    LD16(D_008D2BA6, SND_IDX(arg1)) = LD16(D_008D2BA4, SND_IDX(arg1));
    LD16(D_008D2BA4, SND_IDX(arg1)) = 5;
    func_00459ad0(arg1);
    return 1;
}

/* ================================================================== */
/* FUN_0045AEB0                                                        */
/* ================================================================== */

// FUN_0045AEB0
s32 func_0045aeb0(s16 arg0, const char * arg1)
{
    SndCh *ch;

    if (arg0 < 5)
    {
        ch = &D_008D2B90[arg0];
        ch->f00 = 1;
        LD16(D_008D2B98, SND_IDX(arg0)) = 0;
        LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
        LD16(D_008D2BA6, SND_IDX(arg0)) = LD16(D_008D2BA4, SND_IDX(arg0));
        LD16(D_008D2BA4, SND_IDX(arg0)) = 0;
        func_00442830((u8 *)ch + 0x18, arg1, ch, SND_IDX(arg0));
        func_00459ad0(arg0);
    }
    return 1;
}
/* ================================================================== */
/* FUN_0045AF60                                                        */
/* ================================================================== */

// FUN_0045AF60
s32 func_0045af60(void)
{
    func_0045c640();
    return 1;
}

/* ================================================================== */
/* FUN_0045AF90                                                        */
/* ================================================================== */

// FUN_0045AF90
s32 func_0045af90(s16 arg0)
{
    s32 r;

    if (arg0 == 4)
    {
        return 0;
    }
    if (D_008D2B90[arg0].f00 != 0)
    {
        r = func_004d8dd8(LD32(D_008D2BA0, SND_IDX(arg0)));
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

// FUN_0045B030
s32 func_0045b030(void *arg0)
{
    s32 state;
    s32 result;
    u8 *work;
    u8 *callback;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    state = *(s32 *)work;
    switch (state)
    {
    case 0:
        *(s32 *)(work + 0xC) = 0;
        callback = *(u8 **)(work + 0x110);
        if (callback == NULL)
        {
            func_00456250(*(s32 *)(work + 4), work + 0x10, 0, &D_008D1F10);
        }
        else
        {
            func_00456250(*(s32 *)(work + 4), work + 0x10, 0, callback);
        }
        *(s32 *)work = 1;
        break;
    case 1:
        *(s32 *)(work + 0xC) = *(s32 *)(work + 0xC) + 1;
        result = func_004c7ef8(*(s32 *)(work + 4));
        if (result == 4)
        {
            *(s32 *)work = 0;
        }
        else if (result == 3)
        {
            *(s32 *)work = 2;
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

// FUN_0045B120
void func_0045b120(void *arg0)
{
    u8 *w;

    w = *(u8 **)((u8 *)arg0 + 0x38);
    if (*(s32 *)(w + 0x114) != 0)
    {
        func_00454bd0(*(void **)(w + 0x114));
        *(s32 *)(w + 0x114) = 0;
    }
    jtbl_008873EC[0](w);
}

/* ================================================================== */
/* FUN_0045B170                                                        */
/* ================================================================== */

// FUN_0045B170
s32 func_0045b170(void *arg0)
{
    if (*(s32 *)(*(u8 **)((u8 *)arg0 + 0x38)) == 2)
    {
        func_00452080((s32)arg0);
        return 1;
    }
    return 0;
}

/* ================================================================== */
/* FUN_0045B1C0                                                        */
/* ================================================================== */

// FUN_0045B1C0
s32 func_0045b1c0(void *arg0, s32 arg1, s32 arg2, void *arg3)
{
    s32 h;
    u8 *p;

    func_0044ea90(D_00712238, 0x475);
    p = D_008873F4[0](1, 0x118, 0x40000);
    if (p == NULL)
    {
        return 0;
    }
    h = func_00451de0(&D_00712310[0], 0, 0, 0, (void *)func_0045b030, (void *)func_0045b120, p);
    if (h == 0)
    {
        return 0;
    }
    func_00452570(arg0, (void *)h);
    *(s32 *)(p + 4) = arg1;
    *(s32 *)(p + 0x110) = arg2;
    func_00442830((s32)(p + 0x10), (s32)arg3);
    return h;
}

/* ================================================================== */
/* FUN_0045B2E0                                                        */
/* ================================================================== */

// FUN_0045B2E0
s32 func_0045b2e0(s32 arg0)
{
    u8 buf[0x100];

    if (!((u32)arg0 < 0x42))
    {
        func_0046d730((s32)D_00712238, 0x50A);
    }
    if (D_008D2F2C[0] != 0 && arg0 == D_008D2F34[0])
    {
        return 1;
    }
    func_00442088(buf, &D_00764010, LD32(D_00711F24, arg0 * 0xC));
    D_008D2F2C[0] = 1;
    D_008D2F34[0] = 0;
    D_008D2F38[0] = 0;
    D_008D2F42[0] = D_008D2F40[0];
    D_008D2F40[0] = 6;
    func_00442830(&D_008D2F44[0], (char *)buf);
    func_00459ad0(3);
    if (arg0 <= 0)
    {
        func_0046d730((s32)D_00712238, 0x510);
    }
    D_008D2F34[0] = arg0;
    return 1;
}
