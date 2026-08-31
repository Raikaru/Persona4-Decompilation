#include "include_asm.h"
/* Source unit: src/Kosaka/k_clump/k_clumpInstance.c */
#include "type.h"

typedef struct ClumpWork
{
    u32 state;        /* 0x00 */
    s32 field_4;      /* 0x04 */
    u8  field_8[0x40]; /* 0x08 */
    char name[0x40];  /* 0x48 */
    u32 field_88[0x31]; /* 0x88 */
    s32 count;        /* 0x14C */
    u32 items[0x80];  /* 0x150 */
    char path[0x100]; /* 0x350 */
    u8 *field_450;    /* 0x450 */
} ClumpWork;

extern void *func_003e2f60(s32 arg0, s32 arg1, void *arg2);
extern s32 func_003df3c0(void *arg0, s32 *arg1);
extern void *func_003e6a90(void *arg0);
extern void func_003e6870(void *arg0, void *arg1);
extern void func_003ef260(void *arg0, void (*arg1)(void), s32 *arg2);
extern void func_003ef1b0(void *arg0);
extern void *func_003c0f20(void *arg0);
extern s32 func_00457c90(void *arg0, const char *arg1);
extern void func_003bff30(void *arg0, void (*callback)(void), void *arg2);
extern void func_003c0960(void *arg0, void *arg1);
extern void func_0046d730(const char *arg0, s32 arg1);
extern void func_0044ea90(const char *arg0, s32 arg1);
extern void *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *);
extern void func_003e2910(void *arg0, void *arg1, s32 arg2);
extern void func_003deff0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_003e2ab0(void *arg0, void *arg1, s32 arg2);
extern void func_00463250(void *arg0);
extern void func_003e2e40(void *arg0, s32 arg1);
extern void func_00191e20(void);
extern void func_00463100(void);
extern void func_00191e90(u8 *arg0, s32 *arg1, u8 *arg2);
extern s32 func_001921a0(u8 *arg0);
extern void func_00192480(u8 *arg0);
extern char D_005F64C0[];
extern char D_005F64E0[];
extern char D_005F6500[];
extern s32 func_00428550(const char *arg0);
extern s32 func_00428780(s32 arg0, void *arg1);
extern s32 func_004426e8(const char *arg0, const char *arg1);
extern s32 func_0043c6b0(const char *arg0);
extern void func_00442830(void *arg0, const char *arg1);
extern void func_00442428(void *arg0, const char *arg1);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern void func_00456150(void *arg0);
extern void func_00454bd0(void *arg0);
extern void func_003c0700(void *arg0);
extern s32 func_00451fc0(s32 arg0, const char *arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 (*arg5)(u8 *), void (*arg6)(u8 *),
                         void *arg7);
extern s32 func_00428618(s32 arg0);
extern char D_005F6520[];
extern char D_005F6550[];
extern char D_005F6570[];
extern char D_005F65A0[];
extern char iGpffffa06c;
extern char iGpffffa070;
extern char iGpffffa078;
extern char iGpffffa080;

/* measured floor (nd 10): func_003deff0's 5-arg setup emits [move $a0; lw; lw; lw; lw]
 * where retail emits [lw; lw; move $a0; lw; lw] -- call-argument setup order, a
 * b210 scheduling floor (all other bytes of the function match).
   Committed at nd 10. */


// FUN_00191E90
void func_00191e90(u8 *arg0, s32 *arg1, u8 *arg2)
{
    s32 sp70[8];
    s32 sp50[4];
    s32 i;
    void *s1;
    void *s0;
    void *s3;

    sp70[7] = 0;
    sp70[4] = *(s32 *)(arg0 + 0x110);
    sp70[5] = *(s32 *)(arg0 + 0x118);
    s1 = func_003e2f60(3, 1, &sp70[4]);
    s0 = func_003e2f60(2, 2, arg1);
    *(s32 *)(arg2 + 0x14C) = 0;
    for (i = 0; i < 0x80; i++)
    {
        *(s32 *)(arg2 + i * 4 + 0x150) = 0;
    }
    if (s1 != NULL && s0 != NULL)
    {
        while (func_003df3c0(s1, &sp50[0]) != 0)
        {
            switch (sp50[0])
            {
            case 0x16:
                s3 = func_003e6a90(s1);
                func_003e6870(s3, s0);
                func_003ef260(s3, &func_00463100, &sp70[7]);
                func_003ef1b0(s3);
                break;
            case 0x10:
                *(s32 *)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150) =
                    (s32)func_003c0f20(s1);
                if (func_00457c90(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150),
                                  D_005F64C0) == 0 &&
                    func_00457c90(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150),
                                  D_005F64E0) == 0)
                {
                    if (*(s32 *)(arg2 + 0x14C) != 0)
                    {
                        func_003bff30(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150),
                                      func_00191e20, NULL);
                    }
                }
                func_003c0960(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150), s0);
                *(s32 *)(arg2 + 0x14C) = *(s32 *)(arg2 + 0x14C) + 1;
                break;
            case 0xF0F000E0:
                func_0046d730(D_005F6500, 0x93);
                break;
            default:
                func_0044ea90(D_005F6500, 0x9A);
                s3 = D_008873F4[0](1, sp50[1], 0x40000);
                func_003e2910(s1, s3, sp50[1]);
                func_003deff0((void *)s0, (u32)sp50[0], (u32)sp50[1], sp50[2], sp50[3]);
                func_003e2ab0(s0, s3, sp50[1]);
                jtbl_008873EC[0](s3);
                break;
            }
        }
        if (sp70[7] != 0)
        {
            func_00463250((void *)sp70[7]);
        }
        func_003e2e40(s1, 0);
        func_003e2e40(s0, 0);
    }
}


/* measured: opt_loop_invariants hoists the '.' and '/' loop constants. */
#pragma opt_loop_invariants on
// FUN_001921A0
s32 func_001921a0(u8 *arg0)
{
    ClumpWork *work;
    char *name_cursor;
    char *path_cursor;
    s32 i;
    s32 result;
    struct Local {
        char buffer[0x100];
        char suffix[4];
        char pad[0x30];
    } local;

    work = *(ClumpWork **)(arg0 + 0x38);
    switch (work->state)
    {
    case 0:
        result = func_00428550(D_005F6520);
        work->field_4 = result;
        if (result < 0)
        {
            return -1;
        }
        work->state++;
        break;
    case 1:
        result = func_00428780(work->field_4, work->field_8);
        if (result > 0)
        {
            if (func_004426e8(work->name, &iGpffffa06c) != 0 &&
                func_004426e8(work->name, &iGpffffa070) != 0)
            {
                name_cursor = work->name;
                while (*name_cursor != '.' && *name_cursor != '\0')
                {
                    name_cursor++;
                }
                if (func_004426e8(name_cursor, &iGpffffa078) == 0)
                {
                    local.suffix[0] = work->name[1];
                    local.suffix[1] = work->name[2];
                    local.suffix[2] = work->name[3];
                    local.suffix[3] = '\0';
                    if (func_0043c6b0(local.suffix) < 0x14)
                    {
                        func_00442830(work->path, D_005F6550);
                        func_00442428(work->path, work->name);
                        work->state = 2;
                    }
                }
            }
        }
        else
        {
            work->state = 6;
        }
        break;
    case 2:
        func_00440b68(&iGpffffa080, D_005F6500, 0xEB);
        work->field_450 = func_00454a60(work->path, 0);
        func_00456150(work->field_450);
        func_00442830(local.buffer, D_005F6570);
        path_cursor = work->path;
        while (*path_cursor != '\0')
        {
            path_cursor++;
        }
        for (; *path_cursor != '/'; path_cursor--)
        {
        }
        func_00442428(local.buffer, path_cursor + 1);
        func_00191e90(work->field_450, (s32 *)local.buffer, (u8 *)work);
        func_00454bd0(work->field_450);
        work->state = 3;
        break;
    case 3:
    case 4:
        work->state++;
        break;
    case 5:
        for (i = 0; i < work->count; i++)
        {
            if (*(s32 *)((u8 *)work + i * 4 + 0x150) != 0)
            {
                func_003c0700((void *)*(s32 *)((u8 *)work + i * 4 + 0x150));
            }
        }
        work->state = 1;
        break;
    case 6:
        return -1;
    }
    return 0;
}
/* measured: close the loop-invariant optimization scope for func_001921a0. */
#pragma opt_loop_invariants off



// FUN_00192480
void func_00192480(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_001924D0
s32 func_001924d0(void)
{
    void *mem;

    func_0044ea90(D_005F6500, 0x126);
    mem = D_008873F4[0](1, 0x454, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return func_00451fc0(0, D_005F65A0, 0xF, 0, 0, func_001921a0,
                         func_00192480, mem);
}
