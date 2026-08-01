/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

typedef struct MdlAppObj
{
    u8  pad0[0xD4];
    u16 id;          /* 0xD4 */
    u16 subId;       /* 0xD6 */
    u8  pad1[0x2D0 - 0xD8];
    void *bc;        /* 0x2D0 */
} MdlAppObj;

typedef struct MdlAppBc
{
    u32 unk0;
    s32 unk4;
    u8  pad8[0x12 - 0x08];
    u16 unk12;       /* 0x12 */
    s32 unk14;       /* 0x14 */
    s32 unk18;       /* 0x18 */
} MdlAppBc;

extern s32 func_0047e440(u16 id, u16 subId);
extern void *func_0047dea0(u16 id, u16 subId, s32 kind);
extern s32 func_0047df40(u16 id, u16 subId);
extern void func_0047d090(void *fn0, void *fn1, void *fn2, void *fn3, void *fn4);
extern s32 func_00106330(s32 id);
extern s64 func_001060b0(void);
extern s32 func_00110d60(s16 value);
extern s32 func_00442088(char *buf, char *fmt, ...);
extern void func_00440b68(char *fmt, ...);
extern s32 func_00454a60(void *msg, s32 kind);
extern void func_00456150(s32 handle);
extern void func_002308a0(void);
extern void func_00230bc0(void);
extern void func_00230c00(void);
extern void func_00230d30(void);
extern void func_002311a0(MdlAppObj *obj);

extern char D_00635820[];
extern char D_00635840[];
extern char D_00635860[];
extern char D_00635878[];
extern char D_00635890[];
extern char D_00635678[];
extern char D_006358B0[];
extern char D_006358D0[];
extern char D_007636e0;
extern char D_007636e8;

// FUN_00230F20
s32 func_00230f20(MdlAppObj *obj)
{
    char buf[0x100];
    void **bcp = &obj->bc;
    u16 id = obj->id;
    u16 subId = obj->subId;

    if (func_0047e440(id, subId) != 0)
        return 1;
    if (*bcp != 0 && (*(u16 *)((u8 *)*bcp + 0x12) & 1))
        return 1;
    switch (id & 0xFFFF)
    {
    case 1:
        if (*bcp == 0)
            *bcp = func_0047dea0(id, subId, 1);
        if (func_00106330(0x1438) != 0 && (subId & 0xFFFF) == 1)
            func_00442088(buf, D_00635820, &D_007636e0, subId & 0xFFFF);
        else if (func_00110d60((s16)func_001060b0()) & 1)
            func_00442088(buf, D_00635840, &D_007636e0, subId & 0xFFFF);
        else
            func_00442088(buf, D_00635860, &D_007636e0, subId & 0xFFFF);
        func_00440b68(&D_007636e8, D_00635878, 0x10F);
        *(s32 *)((u8 *)*bcp + 0x14) = func_00454a60(buf, 0);
        *(u16 *)((u8 *)*bcp + 0x12) |= 2;
        break;
    case 2:
        if (*bcp == 0)
            *bcp = func_0047dea0(id, subId, 2);
        func_002311a0(obj);
        *(s32 *)((u8 *)*bcp + 0x04) = func_0047df40(id, subId);
        func_00442088(buf, D_00635890, D_00635678, subId & 0xFFFF);
        func_00440b68(&D_007636e8, D_00635878, 0x12F);
        *(s32 *)((u8 *)*bcp + 0x14) = func_00454a60(buf, 1);
        *(u16 *)((u8 *)*bcp + 0x12) |= 2;
        break;
    default:
        return 0;
    }
    return 1;
}

// FUN_002311A0
void func_002311a0(MdlAppObj *obj)
{
    char buf[0x100];
    void **bcp = &obj->bc;
    u16 id = obj->id;
    u16 subId = obj->subId;
    void *bc;

    if (func_0047e440(id, subId) != 0)
        return;
    bc = *bcp;
    if (bc != 0 && (*(u16 *)((u8 *)bc + 0x12) & 1))
        return;
    switch (id & 0xFFFF)
    {
    case 1:
        break;
    case 2:
        if (bc == 0)
            *bcp = func_0047dea0(id, subId, 2);
        switch (subId & 0xFFFF)
        {
        case 0x100:
        case 0x101:
        case 0x102:
        case 0x103:
        case 0x104:
        case 0x105:
        case 0x106:
        case 0x107:
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
        case 0x10E:
        case 0x112:
            func_00442088(buf, D_006358B0, D_00635678, subId & 0xFFFF);
            func_00440b68(&D_007636e8, D_00635878, 0x16E);
            *(s32 *)((u8 *)*bcp + 0x18) = func_00454a60(buf, 0);
            break;
        default:
            *(s32 *)((u8 *)*bcp + 0x18) = 0;
            break;
        }
        break;
    default:
        break;
    }
}

// FUN_002312E0
void func_002312e0(void)
{
    func_0047d090(&func_002308a0, &func_00230bc0, &func_00230c00, &func_00230d30,
                  &func_00230f20);
}

// FUN_00231330
void func_00231330(void)
{
    func_00440b68(&D_007636e8, D_00635878, 0x1A2);
    func_00456150(func_00454a60(D_006358D0, 0));
}
