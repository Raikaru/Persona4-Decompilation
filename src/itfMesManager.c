/* Source unit: src/itfMesManager_002770d0.c */
#include "type.h"
#include "include_asm.h"

s32 func_0029d030(void);
s32 func_0029cc00(s32 index);
void func_00277f70(s32 mesHandleIdx, u32 param_2);
void func_00440b68();
extern char D_0063BE20[];
void func_002782c0(int param_1,int param_2,int param_3,u32 param_4);
u32 func_002786c0(int param_1,int param_2,int param_3);

extern void func_00278640(s32 arg0, s16 arg1, s32 arg2);

typedef struct {
    u8 *unk0;
    u8 pad[28];
} D_00881808_t;

extern D_00881808_t D_00881808[];

void func_002746c0(int param_1, u32 param_2);

void func_002727f0(int param_1);
extern u8 DAT_008817EC_abs[];
extern u8 DAT_008817E4_abs[];
void func_0027b310(u32 param_1);
extern char D_0063BE10[];
void func_0046d730(const char *file, s32 line);
s32 func_002778c0(s32 arg0, s32 arg1, s32 arg2);
s32 func_00278610(s32 arg0, s16 arg1);
void func_00277250(s32 arg0);
void func_00278170(s32 arg0, s32 arg1);
void func_002781e0(s32 arg0, s32 arg1);
extern s32 DAT_007245C4;
void func_0027b750(s32 arg0, s32 arg1, s32 arg2);
void func_0027b8a0(s32 arg0);
void func_00277ad0(s32 arg0, s32 arg1);
void func_00277be0(s32 arg0, s32 arg1);
void func_00277e80(s32 arg0);
void func_0029cf50(s32 arg0);
void func_00278a70(s32 arg0);
s32 func_00278da0(void);
extern u8 DAT_008817E0_abs[];
void func_00271b70(s32 arg0);
void func_0027a630(void *arg0, s32 arg1);
void func_0027a650(void *arg0, s32 arg1);
void func_0027baa0(s32 arg0);
void func_00277b10(u8 *arg0, s32 arg1);
void func_00272950(s32 arg0, s32 arg1, s32 arg2);
void func_00277ec0(u8 *arg0);
void func_00279a80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_00279c00(u8 *arg0, s32 arg1, s32 arg2);
void func_00278d50(u8 *arg0);
void func_0027a5e0(void *arg0, s16 arg1);
extern char D_0063BED0[];
s32 func_00454a60(char *arg0, s32 arg1);
void func_00456150(s32 arg0);
void func_0027d2f0(s32 arg0);
extern char D_0063BF00[];
extern char DAT_00723858;


// FUN_00276630
s32 func_00276630(void)
{
    s32 index;
    s32 handle;
    u8 *object;
    u8 *base;
    s8 flag;

    index = func_0029d030();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x165);

    handle = func_0029cc00(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        func_00278610(index, 0);
        if (func_002778c0(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        *(s8 *)(base + 8) = 0;
        return 1;
    }
    return 0;
}

// FUN_00276730
s32 func_00276730(void)
{
    s32 index;
    s32 handle;
    s32 count;
    u8 *object;
    u8 *base;
    s8 flag;

    index = func_0029d030();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x18F);

    handle = func_0029cc00(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        func_00278610(index, 1);
        func_00278170(index, 0x200000);
        if (func_002778c0(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            func_00277250(index);
            *(s8 *)(base + 8) = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0xA) {
                *(s8 *)(base + 8) = 0;
                return 1;
            }
        } else if ((*(u32 *)object & 0x300) == 0) {
            func_00277250(index);
            func_00278610(index, 0);
            func_002781e0(index, 0x400000);
            *(s8 *)(base + 8) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_002768E0
s32 func_002768e0(void)
{
    s32 index;
    s32 handle;
    s32 count;
    s32 result;
    u8 *object;
    u8 *base;
    s8 flag;

    index = func_0029d030();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x1CE);

    handle = func_0029cc00(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        func_00278610(index, 1);
        func_00278170(index, 0x200000);
        result = func_002778c0(index, handle, 0);
        func_0027b750(index, 0, func_0029cc00(1));
        func_0027b8a0(index);
        if (result == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            func_00277250(index);
            *(s8 *)(base + 8) = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0xA) {
                *(s8 *)(base + 8) = 0;
                return 1;
            }
        } else if ((*(u32 *)object & 0x300) == 0) {
            func_00277250(index);
            func_00278610(index, 0);
            func_002781e0(index, 0x400000);
            *(s8 *)(base + 8) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00276AC0
s32 func_00276ac0(void)
{
    s32 index;
    s32 h0;
    s32 h1;
    s32 h2;
    u8 *object;
    u8 *base;
    s16 f;

    index = func_0029d030();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x210);

    h0 = func_0029cc00(0);
    h1 = func_0029cc00(1);
    h2 = func_0029cc00(2);
    base = object + 0x3C;
    f = *(s16 *)(object + 0x48);
    if (f == 0) {
        func_00278610(index, 3);
        func_00278170(index, 0x200000);
        if (func_002778c0(index, h0, 0) == 0)
            return 1;
        func_00277f70(index, h2);
        func_00277be0(index, h1);
    } else if (f < 0) {
        *(s16 *)(base + 0xC) = 0;
        func_00277ad0(index, 0);
        *(s8 *)(object + 0x24) = 0;
        func_0029cf50(*(s16 *)(base + 0x10));
        func_00277e80(index);
        func_00277250(index);
        return 1;
    }
    return 0;
}

// FUN_00276C60
s32 func_00276c60(void)
{
    s32 index;
    s32 handle;
    s32 count;
    u8 *object;
    u8 *base;
    s8 flag;

    index = func_0029d030();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x249);

    handle = func_0029cc00(0);
    base = object + 0x1C;
    flag = *(s8 *)(object + 0x24);
    if (flag == 0) {
        func_00278610(index, 4);
        func_00278170(index, 0x200000);
        if (func_002778c0(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            func_00277250(index);
            *(s8 *)(base + 8) = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0x14) {
                *(s8 *)(base + 8) = 0;
                return 1;
            }
        } else if ((*(u32 *)object & 0x300) == 0) {
            func_00277250(index);
            func_00278610(index, 0);
            func_002781e0(index, 0x400000);
            *(s8 *)(base + 8) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00276E10
s8 func_00276e10(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x284);
    return *(s8 *)(object + 0x24);
}

// FUN_00276E70
void func_00276e70(s32 arg0, s8 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x29F);
    *(s8 *)(object + 0x24) = arg1;
}

// FUN_00276ED0
s32 func_00276ed0(void)
{
    s32 index;
    s32 h;
    u8 *object;
    u8 *base;
    s16 f;

    index = func_0029d030();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x2C2);

    h = func_0029cc00(0);
    base = object + 0x3C;
    f = *(s16 *)(object + 0x48);
    if (f == 0) {
        func_00277be0(index, h);
    } else if (f < 0) {
        *(s16 *)(base + 0xC) = 0;
        func_0029cf50(*(s16 *)(base + 0x10));
        func_00277e80(index);
        return 1;
    }
    return 0;
}

// FUN_00276FB0
s16 func_00276fb0(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x2F0);
    return *(s16 *)(object + 0x48);
}

// FUN_00277010
void func_00277010(s32 arg0, s16 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x306);
    *(s16 *)(object + 0x48) = arg1;
}

// FUN_00277070
s16 func_00277070(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x31F);
    return *(s16 *)(object + 0x4A);
}
// FUN_002770D0
u32 func_002770d0(void)
{
  int value;
  u32 other;

  value = func_0029d030();
  if (value < 0)
    return 1;

  other = func_0029cc00(0);
  func_00277f70(value, other);
  return 1;
}



// FUN_00277130
s32 func_00277130(void)
{
    s32 index;

    index = func_0029d030();
    if (index < 0)
        return 1;
    func_00278640(index, 0, 0);
    func_00278170(index, 0x200000);
    return 1;
}

// FUN_002771A0
s32 func_002771a0(void)
{
    s32 index;
    u8 *object;
    s32 flags;

    index = func_0029d030();
    if (index < 0)
        return 1;

    object = D_00881808[index].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x398);

    flags = *(s32 *)object & 0x300;
    if (flags == 0x100 || flags == 0x200)
        func_00277250(index);
    return flags == 0;
}

// FUN_00277250
void func_00277250(s32 arg0)
{
    s32 v;
    s32 w;
    u8 *node;
    u8 *obj;

    obj = D_00881808[arg0].unk0;
    if (obj == NULL)
        func_0046d730(D_0063BE10, 0x3B8);

    node = *(u8 **)DAT_008817EC_abs;
    while (node != NULL) {
        if (*(u32 *)(node + 0xC) == (u32)obj) {
            v = *(s32 *)(node + 8);
            goto out;
        } else {
            node = *(u8 **)(node + 4);
        }
    }
    v = -1;
out:
    func_0027baa0(v);

    w = *(u32 *)obj;
    if (w & 0x300) {
        w = w & ~0x300;
        *(u32 *)obj = w;
        *(u32 *)obj = w | 0x300;
    }
    w = *(u32 *)obj;
    if (w & 0x3000) {
        w = w & ~0x3000;
        *(u32 *)obj = w;
        *(u32 *)obj = w | 0x3000;
    }
    func_00277ad0(arg0, 1);
    func_00277e80(arg0);
    *(u32 *)obj &= 0xFFDFFFFF;
}
// FUN_00277370
u32 func_00277370(void)
{
  int lVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;

  lVar1 = func_0029d030();
  if (lVar1 < 0) {
    return 1;
  }
  uVar2 = func_0029cc00(0);
  uVar3 = func_0029cc00(1);
  uVar4 = func_0029cc00(2);
  func_00440b68(D_0063BE20,uVar2,uVar3,uVar4);
  uVar2 = func_0029cc00(0);
  uVar3 = func_0029cc00(1);
  uVar4 = func_0029cc00(2);
  func_002782c0(lVar1,uVar2,uVar3,uVar4);
  return 1;
}



// FUN_00277450
u32 func_00277450(void)
{
  s32 lVar1;
  u32 uVar2;
  u32 uVar3;

  lVar1 = func_0029d030();
  if (lVar1 < 0) {
    return 1;
  }
  uVar2 = func_0029cc00(0);
  uVar3 = func_0029cc00(1);
  func_002786c0(lVar1,uVar2,uVar3);
  return 1;
}



// FUN_002774D0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_002774d0);

// FUN_002776A0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_002776a0);

// FUN_002777A0
s32 func_002777a0(u8 *arg0)
{
    if (func_00278da0() != 1)
        func_0046d730(D_0063BE10, 0x589);
    return *(s32 *)(arg0 + 0x18);
}

// FUN_002777F0
void func_002777f0(s32 arg0)
{
    if (arg0 >= 0) {
        if (*(s32 *)(DAT_008817E0_abs + (arg0 << 5) + 0x28) != 0)
            func_00278a70(arg0);
    }
}

// FUN_00277840
s32 func_00277840(s32 arg0)
{
    u8 *object;

    if (arg0 < 0 || arg0 >= 0x40)
        func_0046d730(D_0063BE10, 0x134);
    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x5C7);
    return (s32)object + 0x114;
}

// FUN_002778C0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_002778c0);

// FUN_00277AD0
void func_00277ad0(s32 arg0, s32 arg1)
{
    if (arg0 >= 0)
        func_00277b10(D_00881808[arg0].unk0, arg1);
}

// FUN_00277B10
void func_00277b10(u8 *arg0, s32 arg1)
{
    u8 *base;
    u8 *base2;
    s32 v;

    base = arg0 + 0x1C;
    if (*(s32 *)(arg0 + 0x20) != 0) {
        func_00271b70(*(s32 *)(arg0 + 0x20));
        *(s32 *)(base + 4) = 0;
    }
    func_0027a650(base, 0);
    v = *(s32 *)arg0 & ~7;
    *(s32 *)arg0 = v;
    v = v & ~0x300;
    *(s32 *)arg0 = v;
    *(s32 *)arg0 = v & 0xFFFDFFFF;
    if (arg1 != 0) {
        base2 = arg0 + 0x14;
        if (*(s32 *)base2 != 0) {
            func_00271b70(*(s32 *)base2);
            *(s32 *)base2 = 0;
        }
        func_0027a630(arg0 + 0x14, 0);
    }
}

// FUN_00277BE0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00277be0);

// FUN_00277E80
void func_00277e80(s32 arg0)
{
    func_00277ec0(D_00881808[arg0].unk0);
}

// FUN_00277EC0
void func_00277ec0(u8 *arg0)
{
    u8 *base;
    s32 v;

    if (arg0 == NULL)
        func_0046d730(D_0063BE10, 0x6F0);
    base = arg0 + 0x3C;
    if (*(s32 *)(arg0 + 0x40) != 0) {
        func_00271b70(*(s32 *)(arg0 + 0x40));
        *(s32 *)(base + 4) = 0;
    }
    *(s16 *)(base + 0xC) = 0;
    *(s16 *)(base + 0x12) = 0;
    *(s16 *)(base + 0xE) = -1;
    *(s32 *)(base + 8) = 0;
    v = *(s32 *)arg0 & ~0x38;
    *(s32 *)arg0 = v;
    v = v & ~0xC00;
    *(s32 *)arg0 = v;
    *(s32 *)arg0 = v & 0xFFFBFFFF;
}

// FUN_00277F70
void func_00277f70(s32 arg0, u32 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x714);
    *(u32 *)(object + 0x44) = arg1;
}

// FUN_00277FD0
void func_00277fd0(s32 arg0, s32 arg1)
{
    u8 *object;
    u8 *base;
    u32 bits;
    s32 i;
    s32 zeros;
    s32 bit;
    s32 v;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x729);
    base = object + 0x3C;
    zeros = 0;
    bits = *(u32 *)(object + 0x44);
    i = 0;
    while (1) {
        bit = bits & 1;
        if (bit == 0)
            zeros += 1;
        if (i >= arg1)
            break;
        i += 1;
        bits >>= 1;
    }
    if (bit != 0)
        v = 0;
    else
        v = zeros - 1;
    *(s16 *)(base + 0xE) = (s16)v;
    *(s16 *)(base + 0x10) = (s16)v;
}

// FUN_00278090
void func_00278090(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x769);
    func_00272950(*(s32 *)(object + 0x20), arg1, arg2);
}

// FUN_00278110
s32 func_00278110(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x7A7);
    return *(s32 *)object;
}

// FUN_00278170
void func_00278170(s32 arg0, s32 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x7E8);
    *(u32 *)object |= (u32)arg1 & 0xFFFF0000;
}

// FUN_002781E0
void func_002781e0(s32 arg0, s32 arg1)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x7FD);
    *(u32 *)object &= ~((u32)arg1 & 0xFFFF0000);
}

// FUN_00278260
s16 func_00278260(s32 arg0)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x810);
    return *(s16 *)(object + 0x4A);
}

// FUN_002782C0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_002782c0);

// FUN_00278450
void func_00278450(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 0 || arg0 >= 0x40)
        func_0046d730(D_0063BE10, 0x134);
    func_00279a80(D_00881808[arg0].unk0, arg1, arg2, 0);
}

// FUN_002784E0
void func_002784e0(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 0 || arg0 >= 0x40)
        func_0046d730(D_0063BE10, 0x134);
    func_00279c00(D_00881808[arg0].unk0, arg1, arg2);
}

// FUN_00278570
u8 *func_00278570(u8 *arg0, u8 *arg1)
{
    u8 *old;
    u8 *temp;
    s32 v;

    if (arg0 == NULL)
        func_0046d730(D_0063BE10, 0x8F4);
    old = *(u8 **)(arg0 + 4);
    *(u8 **)(arg0 + 4) = arg1;
    func_00278d50(arg1);
    temp = (u8 *)func_00278e00((int)arg1);
    if (*(u32 *)(arg1 + 8) == 0x3147534D)
        v = *(s32 *)(temp + 8);
    else
        v = 0;
    *(s32 *)(arg0 + 8) = v;
    return old;
}

// FUN_00278610
s32 func_00278610(s32 arg0, s16 arg1)
{
    func_00278640(arg0, arg1, 0);
    return 0;
}

// FUN_00278640
void func_00278640(s32 arg0, s16 arg1, s32 arg2)
{
    u8 *object;

    object = D_00881808[arg0].unk0;
    if (!(*(u32 *)object & 0x3300)) {
        *(s32 *)(object + 0x10) = arg1;
        func_00440b68(D_0063BED0);
        func_0027a5e0(object + 0x114, arg1);
    }
}

// FUN_002786C0
u32 func_002786c0(int arg0, int arg1, int arg2)
{
    s32 count;
    u8 *slot;
    u8 *base;
    s32 i;

    base = D_00881808[arg0].unk0 + 0x3C;
    slot = NULL;
    if (arg1 < 0 || arg1 >= 0x10)
        return 0;
    if (arg1 == 6)
        arg1 = 5;
    if (arg1 == 0x40 || arg1 == 0x1000 || arg1 == 0x4000)
        return 0;
    i = 0;
    count = *(s16 *)(base + 0x16);
    while (i < count) {
        u8 *entry = base + i * 4;
        if (*(s16 *)(entry + 0x18) == arg1) {
            slot = entry + 0x18;
            break;
        }
        i += 1;
    }
    if (slot == NULL) {
        if (count >= 0xF)
            return 0;
        slot = base + count * 4 + 0x18;
        *(s16 *)(base + 0x16) += 1;
    }
    *(s16 *)slot = (s16)arg1;
    *(s16 *)(slot + 2) = (s16)arg2;
    return 1;
}

// FUN_002787D0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_002787d0);

// FUN_00278940
void func_00278940(void)
{
    func_00440b68(&DAT_00723858, D_0063BE10, 0xA00);
    func_00456150(func_00454a60(D_0063BF00, 1));
    func_0027d2f0(0);
}

// FUN_002789A0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_002789a0);

// FUN_00278A70
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00278a70);

// FUN_00278B80
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00278b80);
// FUN_00278C60
void func_00278c60(int *param_1, int param_2, u8 *param_3, int param_4)
{
  u8 bVar1;
  u8 *pbVar3;
  int iVar4;
  int iVar5;
  int updateOffset;

  pbVar3 = param_3;
  goto check;
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    if ((bVar1 & 1) == 0) {
      updateOffset = (int)(u32)bVar1 >> 1;
      goto update;
    }
    if ((bVar1 & 2) == 0) {
      updateOffset = (bVar1 | ((int)*pbVar3 << 8)) >> 2;
      pbVar3 = pbVar3 + 1;
      goto update;
    }
    if ((bVar1 & 4) == 0) {
      updateOffset = ((bVar1 | ((int)*pbVar3 << 8)) | ((int)pbVar3[1] << 16)) >> 3;
      pbVar3 = pbVar3 + 2;
      goto update;
    }
    iVar5 = ((int)(u32)bVar1 >> 3) + 2;
    for (iVar4 = 0; iVar4 < iVar5; iVar4 = iVar4 + 1) {
      param_1 = param_1 + 1;
      *param_1 = *param_1 + param_2;
    }
    goto check;
update:
    param_1 = param_1 + updateOffset;
    *param_1 = *param_1 + param_2;
check:
    updateOffset = ((int)pbVar3 - (int)param_3 < param_4);
    if (updateOffset == 0) {
      return;
    }
  } while (1);
}



// FUN_00278D50
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00278d50);

// FUN_00278DA0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00278da0);
// FUN_00278DE0
int func_00278de0(int param_1,int param_2)
{
  s32 base;
  s32 index;

  base = *(volatile /* Removing this qualifier loses FUN_00278DE0 (MATCH nd0 -> MISMATCH nd9, size 24 -> 24) - measured W170. */ s32 *)(param_1 + 4);
  index = param_2 * 8;
  return index + base + 0x20;
}



// FUN_00278E00
int func_00278e00(int param_1)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x18) * 8;
  return iVar1 + param_1 + 0x20;
}



// FUN_00278E20
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00278e20);

// FUN_00278E90
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00278e90);

// FUN_00278EF0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00278ef0);
// FUN_00278FB0
s32 func_00278fb0(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x20);
}



// FUN_00278FD0
s32 func_00278fd0(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x14);
}



// FUN_00278FF0
s32 func_00278ff0(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x40);
}

// FUN_00279010
s32 func_00279010(s32 arg0)
{
    return *(s16 *)(D_00881808[arg0].unk0 + 0x4E);
}

// FUN_00279030
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279030);

// FUN_002791F0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_002791f0);

// FUN_00279300
void func_00279300(u8 *arg0, s32 arg1) {
    func_00273170(arg1, 1, 0);
    func_00271b70(arg1);
}

// FUN_00279350
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279350);

// FUN_00279470
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279470);

// FUN_00279690
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279690);
// FUN_00279740
u32 func_00279740(int param_1,int param_2)
{
  u32 uVar1;
  int count = *(short *)(param_1 + 0x18);

  if ((param_2 < 0) || (param_2 >= count)) {
    uVar1 = 0;
  }
  else {
    int address = param_2 * 4;
    address = address + param_1;
    uVar1 = *(u32 *)(address + 0x1c);
  }
  return uVar1;
}



// FUN_00279780
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279780);

// FUN_00279A80
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279a80);

// FUN_00279C00
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279c00);
// FUN_00279CE0
void func_00279ce0(int param_1)
{
  int iVar1;

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {
    func_002746c0(iVar1,*(u32 *)(param_1 + iVar1 * 4));
  }

  return;
}



// FUN_00279D40
void func_00279d40(s32 arg0)
{
    u8 *entry;
    s32 i;

    entry = D_00881808[arg0].unk0;
    if (entry == 0) {
        func_0046d730(D_0063BE10, 0xD76);
    }
    for (i = 0; i < 0x20; i++) {
        func_002746c0(i, *(u32 *)(entry + i * 4 + 0x94));
    }
}

// FUN_00279DD0
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279dd0);

// FUN_00279E90
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_00279e90);
// FUN_00279FD0
int func_00279fd0(int param_1,u32 param_2)
{
  int iVar1;

  iVar1 = 0;
  for (; 0 < param_1;) {
    if ((param_2 & 1) == 0) {
      iVar1 = iVar1 + 1;
    }
    param_1 = param_1 + -1;
    param_2 = param_2 >> 1;
  }
  return iVar1;
}



// FUN_0027A010
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_0027a010);

// FUN_0027A150
INCLUDE_ASM("asm/nonmatchings/itfMesManager", func_0027a150);

// FUN_0027A2A0
void func_0027a2a0(int param_1, int param_2)
{
    int ptr;

    ptr = *(int *)(param_1 + 0x20);
    *(char *)(param_2 + 0xD) = (char)((int)(u32)*(u8 *)(param_1 + 2) >> 1);
    *(u8 *)(param_2 + 0xA) = *(u8 *)(ptr + 0x15);
    *(u8 *)(param_2 + 0xB) = *(u8 *)(ptr + 0x14);
    *(u8 *)(param_2 + 0xC) = *(u8 *)(ptr + 0x16);
}

// FUN_0027A2D0
s32 func_0027a2d0(u8 *arg0, u8 *arg1)
{
    if (*(s16 *)(arg1 + 0x12) <= 0) {
        func_0046d730(D_0063BE10, 0xE9F);
    }
    return ((*(s32 *)(arg1 + 8) - *(s32 *)(arg0 + 8)) >> 3) /
               *(s16 *)(arg1 + 0x12) + 1;
}

// FUN_0027A370
/* Not `static`: the symbol must stay global so the linker can resolve the
 * retail asm blob's jal to this address (measured: mwldps2 reports Undefined
 * "func_0027a370" if local).
 * The K&R parameter list below is the donor's form and is load-bearing. */
int func_0027a370(param_1,param_2,param_3,param_4)
int param_1;
int param_2;
int param_3;
u8 param_4;
{
  int color;
  int diff;
  int cat;
  int candidate;

  diff = param_3 - param_2;
  param_2 = diff - 1;
  cat = *(int *)(param_1 + 8);
  goto count_check;

advance:
  param_1 = *(int *)(param_1 + 0x24);
  if (param_1 == 0) {
    goto done;
  }

load:
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto advance;
  }
  param_2 = param_2 - 1;
  cat = candidate;

count_check:
  if (param_2 > 0) {
    goto load;
  }

set_start:
  color = (u8)param_4;
set_load:
  candidate = *(int *)(param_1 + 0x1c);
  goto set_check;

set_store:
  *(u8 *)(candidate + 0x14) = (u8)color;
  candidate = *(int *)(candidate + 0x28);

set_check:
  if (candidate != 0) {
    goto set_store;
  }
  param_1 = *(int *)(param_1 + 0x24);
  switch (param_1) {
  case 0:
    goto done;
  }
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto set_load;
  }
  goto done;
done:
  return;
}


/* Removing this loses FUN_0027A4D0 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
#pragma opt_loop_invariants on

// FUN_0027A4D0
void func_0027a4d0(int param_1,u32 param_2)
{
  int iVar1;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {
      *(u32 *)(iVar1 + 0x10) = *(u32 *)(iVar1 + 0x10) & 0xffffff00 | param_2;
    }
  }
  return;
}
#pragma opt_loop_invariants off



// FUN_0027A520
int func_0027a520(int param_1)
{
  int iVar3;
  int iVar1;
  int iVar2;

  iVar3 = 0;
  goto outer_test;
outer_body:
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  do {
    iVar2 += *(int *)(param_1 + 0xc);
    param_1 = *(int *)(param_1 + 0x24);
    if (param_1 == 0) {
      break;
    }
  } while (iVar1 == *(int *)(param_1 + 8));
  if (iVar3 < iVar2) {
    iVar3 = iVar2;
  }
outer_test:
  if (param_1 != 0) {
    goto outer_body;
  }
  return iVar3 << 4;
}



// FUN_0027A580
void func_0027a580(int param_1)
{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    if (*(u8 *)(*(int *)(param_1 + 0x1c) + 0x16) == '\0') {
      func_002727f0(param_1);
    }
  }

  return;
}



// FUN_0027A6C0
void func_0027a6c0(int param_1)
{
  int iVar1;

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {
    *(u32 *)(param_1 + iVar1 * 4) = 0;
  }

  return;
}


#pragma alias DAT_008817EC_abs DAT_008817EC
#pragma alias DAT_008817E4_abs DAT_008817E4
#pragma alias DAT_008817E0_abs D_008817E0


// FUN_0027B620
u64 func_0027b620(void)
{
    int current;
    u32 count;

    current = *(int*)DAT_008817EC_abs;
    while (current != 0) {
        func_0027b310(*(u32*)(current + 0xc));
        current = *(int*)(current + 4);
    }
    count = *(u32*)DAT_008817E4_abs;
    *(u32*)DAT_008817E4_abs = count + 1;
    return 0;
}
