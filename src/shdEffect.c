/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

typedef struct ShdFbuf
{
    u8  b0;
    u8  pad1[3];
    u32 b4;    /* 0x04 */
    u32 b8;    /* 0x08 */
    u32 bC;    /* 0x0C */
    f32 b10;   /* 0x10 */
    u32 b14;   /* 0x14 */
    f32 b18;   /* 0x18 */
    u32 pad1C; /* 0x1C */
    u32 pad20; /* 0x20 */
} ShdFbuf;

typedef struct ShdTask
{
    s32 unk0;   /* 0x00 */
    s32 unk4;   /* 0x04 */
    s32 unk8;   /* 0x08 */
} ShdTask;

typedef struct ShdFarg
{
    s32 b0;    /* 0x00 */
    s32 b4;    /* 0x04 */
    f32 b8;    /* 0x08 */
    f32 bC;    /* 0x0C */
} ShdFarg;

extern void func_0044ea90(void *msg, s32 id);
extern s32 func_00451fc0(s32 window, u8 *data, s32 a, s32 b, s32 c,
                         void *init, void *close, void *buf);
extern s32 func_004ab420(s32 a, void *b);
extern void *func_00452560(void);
extern void func_004b1210(s32 a, s32 b);
extern s32 func_004b1580(s32 a);
extern void func_004b1150(s32 a);
extern s32 func_004b1130(s32 a);
extern void func_0046d730(const void *file, u32 line);
extern void func_0025f960(void *arg);
extern void func_0025fa30(void *arg);
extern s32 func_0025fd80(void);
extern void func_0025fe00(void);

extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_00637290[];
extern char D_006372A0[];
extern char D_00763798;

// FUN_0025FAB0
void func_0025fab0(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4)
{
    u8 *buf;

    func_0044ea90(D_00637290, 0x46);
    buf = D_008873F4[0](1, 0x14, 0x40000);
    *(s32 *)buf = 0;
    if (arg2 != 0)
    {
        *(s32 *)(buf + 4) = arg2;
    }
    else
    {
        *(s32 *)(buf + 4) = func_004ab420(arg1 & 0xFFFF, arg3);
    }
    *(s32 *)(buf + 0xC) = *(s32 *)(arg3 + 0xB8);
    *(s32 *)(buf + 0x10) = arg4;
    func_00451fc0(arg0, (u8 *)D_006372A0, 0xF, 0, 0, (void *)&func_0025f960,
                  (void *)&func_0025fa30, buf);
}

// FUN_0025FBB0
void func_0025fbb0(u8 *dst, u8 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5,
                   f32 farg0, f32 farg1)
{
    ShdFbuf tmp;
    s8 *p;
    s32 n;
    u32 *src;
    u32 *out;
    s32 i;
    u32 t;

    p = (s8 *)&tmp;
    n = 0x24;
    if (p != 0)
    {
        do
        {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    tmp.b0 = arg1;
    tmp.b4 = ((arg2 >> 0x18) & 0xFF) | ((((arg2 >> 0x10) & 0xFF) << 8) |
             (((arg2 & 0xFF) << 0x18) | (((arg2 >> 8) & 0xFF) << 0x10)));
    tmp.b8 = ((arg3 >> 0x18) & 0xFF) | ((((arg3 >> 0x10) & 0xFF) << 8) |
             (((arg3 & 0xFF) << 0x18) | (((arg3 >> 8) & 0xFF) << 0x10)));
    tmp.bC = ((arg4 >> 0x18) & 0xFF) | ((((arg4 >> 0x10) & 0xFF) << 8) |
             (((arg4 & 0xFF) << 0x18) | (((arg4 >> 8) & 0xFF) << 0x10)));
    tmp.b10 = farg0;
    tmp.b14 = ((arg5 >> 0x18) & 0xFF) | ((((arg5 >> 0x10) & 0xFF) << 8) |
              (((arg5 & 0xFF) << 0x18) | (((arg5 >> 8) & 0xFF) << 0x10)));
    tmp.b18 = farg1;
    src = (u32 *)&tmp;
    out = (u32 *)dst;
    i = 9;
    do
    {
        t = *src;
        src++;
        i--;
        *out = t;
        out++;
    } while (i > 0);
}

// FUN_0025FD00
void func_0025fd00(u8 *dst, s32 arg1, s32 arg2, f32 farg0, f32 farg1)
{
    ShdFarg tmp;
    s8 *p;
    s32 n;

    p = (s8 *)&tmp;
    n = 0x10;
    if (p != 0)
    {
        do
        {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    tmp.b0 = arg1;
    tmp.b4 = arg2;
    tmp.b8 = farg0;
    tmp.bC = farg1;
    *(ShdFarg *)(dst + 0x24) = tmp;
}

// FUN_0025FD70
void func_0025fd70(u8 *arg0, s32 arg1, u8 arg2)
{
    *(s32 *)(arg0 + 0xB8) = arg1;
    *(u8 *)(arg0 + 0xBC) = arg2;
}

// FUN_0025FD80
s32 func_0025fd80(void)
{
    ShdTask *t;

    t = func_00452560();
    func_004b1210(t->unk4, t->unk0);
    if (t->unk8 != 0 && func_004b1580(t->unk0) >= t->unk8)
    {
        return -1;
    }
    return 0;
}

// FUN_0025FE00
void func_0025fe00(void)
{
    void *t;

    t = func_00452560();
    func_004b1150(*(s32 *)t);
    (*jtbl_008873EC)(t);
}

// FUN_0025FE50
void func_0025fe50(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *buf;

    if (arg1 == 0)
    {
        func_0046d730(D_00637290, 0xD7);
    }
    if (arg3 == 0)
    {
        func_0046d730(D_00637290, 0xD8);
    }
    func_0044ea90(D_00637290, 0xD9);
    buf = D_008873F4[0](1, 0xC, 0x40000);
    *(s32 *)buf = func_004b1130(arg1);
    *(s32 *)(buf + 4) = arg3;
    *(s32 *)(buf + 8) = arg2;
    func_00451fc0(arg0, (u8 *)&D_00763798, 0xF, 0, 0, (void *)&func_0025fd80,
                  (void *)&func_0025fe00, buf);
}
