#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_texStrip.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

extern void func_00428618(s32 arg0);
extern void func_0044ea90(const void *file, u32 line);
extern void func_00440b68(const char *fmt, ...);
extern void *(*D_008873F4[])(s32, s32, s32);
extern s32 func_003ef650(s32 arg0, s32 arg1);
extern void func_003ef610(s32 arg0);
extern void func_003ef5b0(s32 arg0, s32 arg1);
extern s32 func_00451fc0(s32 arg0, const char *arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 (*arg5)(u8 *), void (*arg6)(u8 *),
                         void *arg7);
extern s32 func_00468170(void *arg0, const char *arg1);
extern s32 func_004680f0(s32 arg0, void *arg1);
extern void func_00462eb0(void *arg0);
extern void func_00452080(s32 handle);
extern char D_005F6168[];
extern char D_005F6178[];
extern char D_005F6190[];
extern char D_005F61B0[];
extern char D_005F63E0[];
extern char D_005F6490[];
extern char D_005F64A8[];

extern s32 func_003e2f60(s32 a, s32 b, s32 *c);
extern s32 func_003df3c0(s32 a, s32 *b);
extern void func_003e2910(s32 a, void *b, s32 c);
extern void func_003deff0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_003e2ab0(s32 a, void *b, s32 c);
extern void func_003e2ce0(s32 a, s32 b);
extern void func_003e2e40(s32 a, s32 b);
extern s32 func_003e6a90(s32 a);
extern s32 func_00442088(void *buf, const char *fmt, ...);
extern s32 func_004288d8(void *a, void *b);
extern u8 *func_00454a60(void *path, s32 flags);
extern void func_00456150(void *handle);
extern void func_00454bd0(void *handle);
extern void func_00442428(void *dst, const void *src);
extern void func_003ef1b0(s32 arg0);
extern char D_005F63F0[];
extern char D_005F6430[];
extern char D_005F6450[];
extern char D_005F6470[];
extern char D_00763128;
extern char D_00763130;
extern char D_00763138;
extern char D_0076313C;
extern char D_00763140;
extern char D_00763148;
extern char D_00763150;
extern char D_00763158;
extern s32 D_00764498;

extern s32 func_00428550(const char *path);
extern s32 func_00428780(s32 handle, void *out);
extern s32 func_004426e8(void *a, const void *b);
extern void func_00442830(void *dst, const void *src);
extern u8 *func_00150970(void *path);
extern s32 func_00150c80(void *hdr);
extern void func_00150ce0(void *hdr);
extern s32 func_001510c0(void *hdr);
extern s32 func_004581a0(void *a, const void *b);
extern void func_00458430(s32 *out, void *a, const void *b, s32 c);
extern s32 func_00426cf0(void *path, s32 a, s32 b);
extern s32 func_00442948(void *buf);
extern s32 sceWrite(s32 fd, void *buf, s32 n);
extern s32 sceRead(s32 fd, void *buf, s32 n);
extern void func_00426f80(s32 fd);
extern void func_00428f08(void *a, s32 b);
extern void func_00151f80(void *hdr);
extern void func_00463250(void *a);
extern char D_005F61D0[];
extern char D_005F61F8[];
extern char D_005F6210[];
extern char D_005F6230[];
extern char D_005F6250[];
extern char D_005F6270[];
extern char D_005F62A0[];
extern char D_005F62B0[];
extern char D_005F62C0[];
extern char D_005F62D0[];
extern char D_005F6310[];
extern char D_005F6350[];
extern char D_005F6370[];
extern char D_005F63B0[];

s32 func_00190680(u8 *arg0, void *arg1);
void func_001909f0(u8 *arg0, void *arg1, u8 *arg2);
s32 func_00190c10(u8 *arg0);
s32 func_001916a0(u8 *arg0, void *arg1);
s32 func_00191850(u8 *arg0);



// FUN_00190680
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_00190680);

// FUN_00190920
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_00190920);

// FUN_001909F0
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_001909f0);

// FUN_00190C10
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_00190c10);

// FUN_001915C0
void func_001915c0(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191610
s32 func_00191610(void)
{
    void *mem;

    func_0044ea90(D_005F6168, 0x2ED);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return func_00451fc0(0, D_005F63E0, 0xF, 0, 0, func_00190c10,
                         func_001915c0, mem);
}

// FUN_001916A0
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_001916a0);

// FUN_00191850
s32 func_00191850(u8 *arg0)
{
    char buf240[0x40];
    char buf140[0x100];
    char buf40[0x100];
    s32 *work;
    s32 i;
    u8 *temp1;
    u8 *temp2;

    work = *(s32 **)(arg0 + 0x38);
    switch (work[0])
    {
    case 0:
        work[0x39C] = 2;
        work[0x95] = 0;
        work[0] = work[0] + 1;
        /* fallthrough */
    case 1:
        func_00442088(&work[0x53], D_005F63F0, work[0x39B], work[0x39C]);
        if (func_004288d8(&work[0x53], buf240) == 0)
        {
            func_00442088(&work[0x53], D_005F6430, work[0x39B], work[0x39C]);
            func_00440b68(&D_00763150, D_005F6168, 0x36E);
            temp1 = (u8 *)func_00454a60(&work[0x53], 0);
            work[0x94] = (s32)temp1;
            func_00456150(temp1);
            work[0] = 2;
            work[0x39C] = work[0x39C] + 1;
            func_00440b68(&D_00763128, &work[0x53]);
        }
        else
        {
            work[0x39C] = work[0x39C] + 1;
            if (work[0x39C] > 0xF)
            {
                work[0] = 3;
            }
        }
        break;
    case 2:
        func_00442088(buf140, D_005F6450);
        func_00442428(buf140, &work[0x53]);
        func_00442428(buf140, &D_00763158);
        work[work[0x95] + 0x196] = func_001916a0((u8 *)work[0x94], buf140);
        func_00454bd0((u8 *)work[0x94]);
        work[0x94] = 0;
        work[0x95] = work[0x95] + 1;
        work[0] = 1;
        break;
    case 3:
        func_00442088(&work[0x53], D_005F6470, work[0x39B]);
        func_00440b68(&D_00763150, D_005F6168, 0x39B);
        temp2 = (u8 *)func_00454a60(&work[0x53], 0);
        work[0x94] = (s32)temp2;
        func_00456150(temp2);
        func_00442088(buf40, D_005F6450);
        func_00442428(buf40, &work[0x53]);
        func_00442428(buf40, &D_00763158);
        func_001909f0((u8 *)work[0x94], buf40, (u8 *)work);
        for (i = 0; i < (u32)work[0x95]; i++)
        {
            s32 *elem = (s32 *)((u8 *)work + i * 4 + 0x658);
            if (*(s32 *)((u8 *)work + i * 4 + 0x658) != 0)
            {
                func_003ef1b0(*(s32 *)((u8 *)work + i * 4 + 0x658));
                *elem = 0;
            }
        }
        func_00454bd0((u8 *)work[0x94]);
        work[0x94] = 0;
        work[0x39B] = work[0x39B] + 1;
        if (work[0x39B] > 0x30)
        {
            work[0] = 4;
        }
        else
        {
            work[0] = 0;
        }
        break;
    case 4:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_00191B70
void func_00191b70(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191BC0
s32 func_00191bc0(void)
{
    s32 ret;
    void *mem;

    func_0044ea90(D_005F6168, 0x3D4);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    ret = func_00451fc0(0, D_005F63E0, 0xF, 0, 0, func_00191850,
                        func_00191b70, mem);
    *(s32 *)((u8 *)mem + 0xE6C) = 0x28;
    *(s32 *)((u8 *)mem + 0xE70) = 1;
    return ret;
}

// FUN_00191C70
s32 func_00191c70(u8 *arg0)
{
    s32 *work;
    char buf[0x80];

    work = *(s32 **)(arg0 + 0x38);
    switch (work[0])
    {
    case 0:
        work[1] = func_00468170(arg0, D_005F6490);
        work[0] = work[0] + 1;
        break;
    case 1:
        if (func_004680f0(work[1], buf) == 1)
        {
            if (buf[0] == 0)
            {
                work[0] = 2;
            }
            else
            {
                func_00462eb0(buf);
            }
            func_00452080(work[1]);
            work[0] = 0;
        }
        break;
    case 2:
        return -1;
    }
    return 0;
}

// FUN_00191D60
void func_00191d60(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191D90
s32 func_00191d90(void)
{
    void *mem;

    func_0044ea90(D_005F6168, 0x435);
    mem = D_008873F4[0](1, 0x8, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return func_00451fc0(0, D_005F64A8, 0xF, 0, 0, func_00191c70,
                         func_00191d60, mem);
}
