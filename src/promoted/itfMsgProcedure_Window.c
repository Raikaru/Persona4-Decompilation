/* Consolidated Persona 4 source units. */
/* Original translation unit itfMsgProcedure_Window.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

s32 *func_0027be60(void);
extern s32 func_00452380(void *path);
extern void func_0046d730(const void *file, u32 line);
extern s32 func_0025f110(void *arg);
extern void func_0025f230(u32 arg);
extern void func_00366380();
extern void func_0046a750(void *arg);
extern s32 func_00455f70(char *str, void *out);
extern s32 func_0046af60(void *arg);
extern s32 func_00451fc0(void *a0, char *a1, s32 a2, s32 a3, s32 a4, void *a5, void *a6, void *a7);
extern s32 func_0027cae0(void *arg);
extern s32 func_0025ef20(char *str);
extern s32 func_00266b70(void);
extern s32 func_0043f9c8(void *a0, s32 a1, s32 a2);

extern void func_00460b60(void *a0, s32 a1, s32 a2);
extern void func_00460c70(void *a0, s32 a1, s32 a2);
extern void func_00489f80(void);
extern void func_0045da40(float *a0, void *a1, float a2, s32 a3, void *a4);
extern void func_0048a000(void);
extern float func_0044b7b0(float angle);
extern float func_0044b610(float angle);
extern s32 func_0045eb20(void *a0, void *a1, float a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, float a8, float a9, float a10, s32 a11);
extern float D_007612D0;

typedef struct MsgProcWindowWork {
    s16 field0;
    s16 field2;
    u32 field4;
    u32 field8;
} MsgProcWindowWork;

typedef struct MsgProcWindowEntry {
    s32 field0;
    u8 pad[20];
} MsgProcWindowEntry;

typedef struct MsgProcWindowF2 {
    float x;
    float y;
} MsgProcWindowF2;

typedef struct MsgProcWindowRGBA {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} MsgProcWindowRGBA;

typedef struct MsgProcWindowU32Pair {
    u32 a;
    u32 b;
} MsgProcWindowU32Pair;

typedef struct MsgProcWindowQuad {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} MsgProcWindowQuad;

extern u8 D_007245D0;
extern u32 D_007245D4;
extern MsgProcWindowWork D_00882098;
extern MsgProcWindowEntry D_008820B0[];
extern u32 D_0088209C[];
extern u32 D_007245C8;
extern u32 D_007245CC;
extern char D_00723868;
extern char D_0063BFC0[];
extern char D_0063C180[];
extern char D_0063BFE0[];
extern char D_0063C000[];
extern char D_0063C018[];
extern char D_0063C120[];
extern char D_0063C170[];
extern MsgProcWindowF2 D_0063C030[10];



// FUN_0027CAE0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027cae0);

// FUN_0027D230
s32 func_0027d230(void)
{
    s32 i;

    if (D_007245C8 != 0) {
        func_0046a750((void *)D_007245C8);
    }
    if (D_007245CC != 0) {
        func_0046a750((void *)D_007245CC);
    }
    for (i = 0; i < 8; i++) {
        if ((D_008820B0[i].field0 & 1) != 0) {
            if (func_0027cae0(&D_008820B0[i]) != 0) {
                D_008820B0[i].field0 &= ~1;
            }
        }
    }
    return 0;
}

// FUN_0027D2F0
void func_0027d2f0(void *arg0)
{
    s32 local;
    s32 tmp;

    tmp = func_00455f70(D_0063BFE0, &local);
    if (tmp != 0) {
        D_007245C8 = func_0046af60((void *)tmp);
    } else {
        D_007245C8 = 0;
    }
    tmp = func_00455f70(D_0063C000, &local);
    if (tmp != 0) {
        D_007245CC = func_0046af60((void *)tmp);
    } else {
        D_007245CC = 0;
    }
    func_00451fc0(arg0, D_0063C018, 0xF, 0, 0, (void *)func_0027d230, (void *)0, (void *)0);
}

// FUN_0027D3C0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027d3c0);

// FUN_0027D620
void func_0027d620(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, u32 s0)
{
    func_00366380(a0, a1, a2, a3, t0, t1, 1, t2, t3, s0);
}

// FUN_0027D660
void func_0027d660(s32 arg0, s32 arg1, s32 arg2, s32 arg3, float f0, void *arg4)
{
    float f;
    u32 pad;
    MsgProcWindowQuad q2;
    MsgProcWindowQuad q1;
    u8 *p;
    u32 n;

    p = (u8 *)&pad;
    n = 4;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    f = *(float *)&pad;
    p = (u8 *)&q1;
    n = 0x10;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    q1.a = arg0;
    q1.b = arg1;
    q1.c = arg2;
    q1.d = arg3;
    q2 = q1;
    func_00460b60(arg4, 0x6, 0x1);
    func_00460b60(arg4, 0xE, 0x0);
    func_00460b60(arg4, 0xC, 0x1);
    func_00460b60(arg4, 0x7, 0x2);
    func_00460b60(arg4, 0x9, 0x1);
    func_00460b60(arg4, 0x14, 0x1);
    func_00460b60(arg4, 0x6, 0x0);
    func_00460b60(arg4, 0x8, 0x1);
    func_00460c70(arg4, 0x3, 0x31003);
    func_00460c70(arg4, 0x2, 0x44);
    func_00489f80();
    func_0045da40(&f, &q2, f0, 0, arg4);
    func_0048a000();
}

// FUN_0027D800
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027d800);

// FUN_0027D970
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027d970);

// FUN_0027F560
s32 func_0027f560(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    switch (*(s16 *)&D_007245D0) {
    case 0:
        work->field4 = func_0025ef20(D_0063C120);
        work->field0 = 1;
    case 1:
        if (func_0025f110((void *)work->field4) != 0) {
            work->field0 = 2;
        }
        break;
    case 2:
        if ((work->field2 & 1) != 0) {
            work->field0 = 3;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0027F630
void func_0027f630(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    if (D_007245D4 != 0) {
        if (func_0025f110((void *)work->field4) == 0) {
            func_0046d730(D_0063BFC0, 0x3D9);
        }
        func_0025f230(work->field4);
        work->field4 = 0;
    }
}

// FUN_0027F6A0
void func_0027f6a0(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    if (func_00452380(&D_00723868) != 0) {
        work->field2 |= 1;
    }
}

// FUN_0027F6F0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027f6f0);
// FUN_002818A0
void func_002818a0(u32 arg0, s32 arg1) {
    s32 *temp_2;

    temp_2 = func_0027be60();
    if (temp_2 != NULL) {
        *temp_2 = arg1;
    }
}

// FUN_002818E0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_002818e0);

// FUN_00282250
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_00282250);

// FUN_002831C0
s32 func_002831c0(void)
{
    MsgProcWindowWork *work = &D_00882098;

    switch (*(s16 *)&D_00882098) {
    case 0:
        work->field4 = func_0025ef20(D_0063C170);
        work->field8 = func_00266b70();
        work->field0 = 1;
    case 1:
        if (func_0025f110((void *)work->field4) != 0 && func_0025f110((void *)work->field8) != 0) {
            work->field0 = 2;
        }
        break;
    case 2:
        if ((work->field2 & 1) != 0) {
            work->field0 = 3;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_002832B0
void func_002832b0(void)
{
    MsgProcWindowWork *work = &D_00882098;

    if (D_0088209C[0] != 0) {
        if (func_0025f110((void *)work->field4) == 0) {
            func_0046d730(D_0063BFC0, 0x7AA);
        }
        func_0025f230(work->field4);
        work->field4 = 0;
    }
    if (work->field8 != 0) {
        if (func_0025f110((void *)work->field8) == 0) {
            func_0046d730(D_0063BFC0, 0x7B0);
        }
        func_0025f230(work->field8);
        work->field8 = 0;
    }
}

// FUN_00283360
void func_00283360(void)
{
    u8 *work = (u8 *)&D_00882098;

    if (func_00452380(D_0063C180) != 0) {
        *(s16 *)(work + 2) |= 1;
    }
}

// FUN_002833B0
s32 func_002833b0(s32 arg0)
{
    MsgProcWindowWork *work = &D_00882098;

    if (func_00452380(D_0063C180) != 0) {
        if (work->field0 >= 2) {
            u32 *arr = (u32 *)((u8 *)work + 4);
            return arr[arg0];
        }
    } else if (func_00452380(D_0063C180) == 0) {
        func_0043f9c8(work, 0, 0xC);
        func_00451fc0((void *)0, D_0063C180, 0xF, 0, 0, (void *)func_002831c0, (void *)func_002832b0, (void *)0);
    }
    return 0;
}

// FUN_00283490
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_00283490);

// FUN_002848C0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_002848c0);
