#include "type.h"
#include "include_asm.h"


extern u32 RpRandom(void);
extern void func_0046d730(u8 *arg0, s32 arg1);
extern u8 D_00635938[];

extern void memset(void *arg0, s32 arg1, s32 arg2);

typedef struct DatUnit
{
    u16 flags;         // 0x00
    u16 id;            // 0x02
    u16 id2;           // 0x04
    u8 level;          // 0x06
    u16 hp;            // 0x08
    u16 sp;            // 0x0a
    u32 bad;           // 0x0c
    s8 aiTactic;       // 0x10
    u8 unkData1[0x28];
} DatUnit;

extern u16 func_00231f80(DatUnit* unit);

extern u32 func_00232290(DatUnit* unit);

extern s32 func_00106600(s16 arg);

/* gp - 0x4C48 = 0x007690f0 - 0x4c48 = 0x007644a8 */
extern u8 *iGpffffb3b8;
/* gp - 0x4C40 = 0x007690f0 - 0x4c40 = 0x007644b0 */
extern u8 *iGpffffb3c0;

extern u8 *func_00106820(s16 arg0);

/* Old-style declaration: the retail call site at func_00232aa0 passes arg0 raw (no 64-bit extension). */
u16 func_00243920();

extern u32 func_00104dc0();
extern u32 func_001056e0();
extern u32 func_00104e30();
extern u32 func_00105730();
extern u32 func_00105d50();

extern u8 *func_001094e0(u16 arg0);
extern s32 func_0010a900(u16 arg0);
extern s32 func_00109390(s32 arg0);
extern u32 func_00106cd0(s16 arg0, s32 arg1);
extern u32 func_001069d0(u32 arg0);
extern s32 func_00106a30(s16 arg0);
extern u32 func_001069a0(s16 arg0);

extern s32 func_0023a6b0(u8 *arg0, s32 arg1);
extern s32 func_00238940(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
/* Defined below in this file; used at line 184, before its definition. */
extern u8 *func_0023e140(u8 *arg0);

extern u8 *iGpffffb3b4;

extern u8 *iGpffffb3c4;
extern u8 *iGpffffb448;
extern u8 *iGpffffb44c;
extern u8 *iGpffffb3cc;

extern void func_00233370(u8 *arg0, u8 arg1, s32 arg2);
extern void func_00233490(u8 *arg0, u8 arg1, s8 arg2);



// FUN_00231D70
u32 func_00231d70(u32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_00635938, 0x17);
    }
    return RpRandom() % arg0;
}



// FUN_00231DC0
void func_00231dc0(u8 *arg0, s16 arg1)
{
    memset(arg0, 0, 0x30);
    *(s16 *)(arg0 + 2) = arg1;
    *(s8 *)(arg0 + 6) = 1;
    *(s16 *)(arg0 + 8) = 1;
    *(s16 *)(arg0 + 0xA) = 1;
    *(s16 *)(arg0 + 4) = arg1;
    *(s8 *)(arg0 + 0x10) = 0;
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300410 (verified MATCH there). */


// FUN_00231E20
s32 func_00231e20(u8 *arg0)
{
    s32 level;

    if (*(u16 *)arg0 & 4 || *(u16 *)(arg0 + 2) == 1) {
        level = *(u8 *)(arg0 + 6);
    } else {
        level = func_0010a900(*(u16 *)(arg0 + 2));
        if (level == 0) {
            func_0046d730(D_00635938, 0x58);
        }
        level = func_00109390(level) & 0xFF;
    }
    if ((s32)(u8)level <= 0) {
        func_0046d730(D_00635938, 0x5C);
    }
    return level;
}

// FUN_00231EF0
void func_00231ef0(u8 *arg0, u8 arg1)
{
    if (arg1 > 99 && !(*(u16 *)arg0 & 4))
    {
        arg1 = 0x63;
    }
    arg0[6] = arg1;
}

// FUN_00231F80
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00231f80);

// FUN_00232290
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232290);

// FUN_002325A0
s32 func_002325a0(DatUnit* unit, s32 hpDelta)
{
    s32 maxHp;
    s32 newHp;

    newHp = unit->hp + hpDelta;
    if (newHp < 0) {
        newHp = 0;
    }
    maxHp = func_00231f80(unit) & 0xFFFF;
    if (maxHp < newHp) {
        newHp = maxHp;
    }
    unit->hp = (u16)newHp;
    return newHp & 0xFFFF;
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300480 (verified MATCH there). */

// FUN_00232610
s32 func_00232610(DatUnit* unit, s32 spDelta)
{
    s32 maxSp;
    s32 newSp;

    newSp = unit->sp + spDelta;
    if (newSp < 0) {
        newSp = 0;
    }
    maxSp = func_00232290(unit) & 0xFFFF;
    if (maxSp < newSp) {
        newSp = maxSp;
    }
    unit->sp = (u16)newSp;
    return newSp & 0xFFFF;
}




// FUN_00232730
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232730);

// FUN_00232830
s32 func_00232830(u16 *arg0, s64 arg1)
{
    if (*arg0 & 4) {
        return 0;
    }
    return (func_00106600((s16)arg1) & 0xFF) > 0;
}




// FUN_00232880
u16 func_00232880(s32 arg0, s32 arg1)
{
    u16 count;
    s16 id;
    u16 val;

    if ((arg0 & 0xFFFF) >= 0xB) {
        func_0046d730(D_00635938, 0x263);
    }
    count = 0;
    id = (s16)arg0;
    val = (u16)arg1;
    if ((func_001069d0(func_00106cd0(id, 0)) & 0xFFFF) == val) {
        count++;
    }
    if ((func_001069d0(func_00106cd0(id, 1)) & 0xFFFF) == val) {
        count++;
    }
    return count;
}

// FUN_00232950
u16 func_00232950(u8 *arg0, s32 arg1)
{
    u16 count;
    s16 id;
    u16 id16;
    u16 val;

    if (*(u16 *)arg0 & 4) {
        return 0;
    }
    id16 = *(u16 *)(arg0 + 2);
    if (id16 >= 0xB) {
        func_0046d730(D_00635938, 0x263);
    }
    count = 0;
    id = (s16)id16;
    val = (u16)arg1;
    if ((func_001069d0(func_00106cd0(id, 0)) & 0xFFFF) == val) {
        count++;
    }
    if ((func_001069d0(func_00106cd0(id, 1)) & 0xFFFF) == val) {
        count++;
    }
    return count;
}

// FUN_00232A40
s32 func_00232a40(s32 arg0)
{
    s32 id;
    u8 *base;

    id = arg0 & 0xFFFF;
    if (id >= 0x1B8) {
        return 0;
    } else {
        base = iGpffffb3b8 + id * 0x28;
        if (base[0] & 2) {
            return 0;
        }
        return (base[1] & 1) != 0;
    }
}

// FUN_00232AA0
s32 func_00232aa0(s32 arg0)
{
    u16 id16;

    if ((arg0 & 0xFFFF) <= 0x300 || (arg0 & 0xFFFF) >= 0x400) {
        return 0;
    } else {
        id16 = func_00243920(arg0) & 0xFFFF;
        if (id16 == 0) {
            return 0;
        }
        if (id16 >= 0x1B8) {
            return 0;
        }
        return (iGpffffb3b8[id16 * 0x28 + 1] & 2) != 0;
    }
}

// FUN_00232B40
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232b40);

// FUN_00232C70
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232c70);

// FUN_00232D80
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232d80);

// FUN_002332A0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002332a0);

// FUN_00233370
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00233370);

// FUN_00233490
void func_00233490(u8 *arg0, u8 arg1, s8 arg2)
{
    u8 *b;
    u16 idx;
    u8 old;

    if (arg1 >= 0x18) {
        func_0046d730(D_00635938, 0x45E);
    }
    if (arg2 < 0) {
        func_0046d730(D_00635938, 0x45F);
    }
    idx = ((s32)arg1 >> 1) & 0xFFFF;
    b = arg0;
    if (arg1 & 1) {
        old = b[idx + 0x24];
        b[idx + 0x24] = (u8)((old & 0xF) | ((arg2 & 0xF) << 4));
    } else {
        old = b[idx + 0x24];
        b[idx + 0x24] = (u8)((old & 0xF0) | (arg2 & 0xF));
    }
}

// FUN_00233570
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00233570);

// FUN_00233880
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00233880);

// FUN_002339D0
void func_002339d0(u8 *arg0)
{
    u32 i;
    s32 i8;

    for (i = 0; i < 0x18; i++) {
        i8 = i & 0xFF;
        if (i8 >= 0x18) {
            func_0046d730(D_00635938, 0x4A2);
        }
        if (i8 < 0x10) {
            func_00233370(arg0, i, 0);
            func_00233490(arg0, i, 0);
        }
        *(s32 *)(arg0 + 0x14) &= ~(1 << i8);
    }
}

// FUN_00233A90
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00233a90);

// FUN_00233BC0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00233bc0);

// FUN_002340C0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002340c0);

// FUN_00234830
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00234830);

// FUN_00235020
void func_00235020(u8 *arg0)
{
    u32 i;
    s32 i8;
    u32 mask;

    mask = *(s32 *)(arg0 + 0x18);
    if (mask != 0) {
        for (i = 0; i < 0x18; i++) {
            if (mask & (1 << i)) {
                i8 = i & 0xFF;
                if (i8 >= 0x18) {
                    func_0046d730(D_00635938, 0x4A2);
                }
                if (i8 < 0x10) {
                    func_00233370(arg0, i, 0);
                    func_00233490(arg0, i, 0);
                }
                *(s32 *)(arg0 + 0x14) &= ~(1 << i8);
            }
        }
        *(s32 *)(arg0 + 0x18) = 0;
    }
}

// FUN_00235110
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00235110);

// FUN_00235320
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00235320);

// FUN_00235520
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00235520);

// FUN_002384B0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002384b0);

// FUN_00238940
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00238940);

// FUN_002397D0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002397d0);

// FUN_00239E40
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00239e40);

// FUN_00239F50
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00239f50);

// FUN_0023A1E0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023a1e0);

// FUN_0023A490
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023a490);

// FUN_0023A620
s32 func_0023a620(s32 arg0, s32 arg1)
{
    s32 temp_3 = arg1 & 0xFFFF;
    s32 var_2 = ((temp_3 & 0xFF00) << 0x10) | ((temp_3 & 0xFFFF00FF) * 5);
    if (!(var_2 & 0xFFFF)) {
        if (var_2 & 0x08000000) {
            var_2 |= 0x7D;
        } else if (var_2 & 0x27000000) {
            var_2 |= 0x64;
        } else if (var_2 & 0x10000000) {
            var_2 |= 0x32;
        }
    }
    return var_2;
}




// FUN_0023A6B0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023a6b0);

// FUN_0023D6E0
s32 func_0023d6e0(s16 arg0)
{
    if (arg0 >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    return 1 << (arg0 + 1);
}




// FUN_0023D740
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023d740);

// FUN_0023D8E0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023d8e0);

// FUN_0023D9B0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023d9b0);

// FUN_0023DD90
u8 func_0023dd90(u8 *arg0, s32 arg1)
{
    u8 *base = iGpffffb3b8 + 3;
    return *(u8 *)(base + (arg1 & 0xFFFF) * 0x28);
}




// FUN_0023DDC0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023ddc0);

// FUN_0023DF70
s32 func_0023df70(s32 arg0)
{
    u8 *base;

    if ((arg0 & 0xFFFF) >= 0x1B8) {
        func_0046d730(D_00635938, 0xF5E);
    }
    base = iGpffffb3b8 + (u16)arg0 * 0x28;
    return (base[0] & 2) != 0;
}

// FUN_0023DFE0
s32 func_0023dfe0(void)
{
    return 0;
}

// FUN_0023DFF0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023dff0);

// FUN_0023E140
u8 *func_0023e140(u8 *arg0)
{
    if (!(*(u16 *)arg0 & 4)) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        return func_001094e0(*(u16 *)(arg0 + 2));
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0xFA8);
    }
    return iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0xE;
}

// FUN_0023E1F0
u8 func_0023e1f0(u8 *arg0)
{
    u8 *base;
    if (*(u16 *)(arg0 + 0) & 4) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0xB) {
        func_0046d730(D_00635938, 0xFBB);
    }
    base = iGpffffb3c0 + 0x14A;
    return *(u8 *)(base + *(u16 *)(arg0 + 2) * 0x14C);
}




// FUN_0023E270
u16 func_0023e270(u8 *arg0)
{
    if (*(u16 *)arg0 & 4) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0xB) {
        func_0046d730(D_00635938, 0xFCE);
    }
    return func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF;
}

// FUN_0023E2F0
s32 func_0023e2f0(u8 *arg0, s32 arg1)
{
    u8 *b;
    u16 v;
    s32 idx;

    if (*(u16 *)arg0 & 4) {
        if (*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0xFE2);
        }
        idx = *(u16 *)(arg0 + 2) * 0xE8;
        b = (u8 *)iGpffffb3cc;
        return b[idx + 0x1A];
    }
    if (*(u16 *)(arg0 + 2) >= 0xB) {
        func_0046d730(D_00635938, 0xFE6);
    }
    v = (u16)arg1;
    if (v & 6) {
        idx = *(u16 *)(arg0 + 2) * 0x14C;
        b = (u8 *)iGpffffb3c0;
        return b[idx + 0x18];
    }
    return 1;
}

// FUN_0023E3E0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023e3e0);

// FUN_0023E5B0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023e5b0);

// FUN_0023E6F0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023e6f0);

// FUN_002411A0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002411a0);

// FUN_00241BC0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00241bc0);

// FUN_00241DE0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00241de0);

// FUN_00241F00
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00241f00);

// FUN_00242360
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00242360);

// FUN_00242800
s32 func_00242800(u8 *arg0, s32 arg1)
{
    s16 id;
    s32 x;

    id = (s16)arg1;
    if (id == -1) {
        return 0;
    }
    if (id >= 0x13) {
        func_0046d730(D_00635938, 0x13FD);
    }
    if (id >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    x = 1 << (id + 1);
    if (x & 1) {
        return 0;
    }
    if (x & 0xE0000) {
        return 0x64;
    }
    return func_0023a6b0(arg0, arg1);
}

// FUN_00242990
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00242990);

// FUN_00243650
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00243650);

// FUN_00243840
u8 *func_00243840(s32 arg0)
{
    if ((arg0 & 0xFFFF) >= 0x240) {
        func_0046d730(D_00635938, 0x14E4);
    }
    return iGpffffb448 + (u16)arg0 * 0x13;
}

// FUN_002438B0
u8 *func_002438b0(s32 arg0)
{
    if ((arg0 & 0xFF) >= 0x20) {
        func_0046d730(D_00635938, 0x14F2);
    }
    return iGpffffb44c + (u8)arg0 * 0x15;
}

// FUN_00243920
u16 func_00243920(s64 arg0)
{
    return *(u16 *)((u8 *)func_00106820((s16)arg0) + 0x24);
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_0030c490 (verified MATCH there). */


// FUN_00243950
u16 func_00243950(u8 *arg0)
{
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x1515);
    }
    return *(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0x1E);
}

// FUN_002439C0
u16 func_002439c0(u8 *arg0)
{
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x152A);
    }
    return *(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0x20);
}

// FUN_00243A30
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00243a30);

// FUN_00243CE0
s32 func_00243ce0(u8 *arg0)
{
    if (!(*(u16 *)arg0 & 4)) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x15C5);
    }
    if (*(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C) & 4) {
        return 1;
    }
    return 0;
}

// FUN_00243D80
s32 func_00243d80(u8 *arg0)
{
    s16 *b;

    if (!(*(u16 *)arg0 & 4)) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x15D2);
    }
    b = (s16 *)iGpffffb3cc;
    if (b[*(u16 *)(arg0 + 2) * 0x74 + 0xC] & 0x80) {
        return 1;
    }
    return 0;
}

// FUN_00243E30
s32 func_00243e30(u16 *arg0)
{
    return (s32)((*arg0 & 0x200) != 0);
}

// FUN_00243E50
void func_00243e50(u16 *arg0)
{
    *arg0 |= 0x200;
}

// FUN_00243E70
void func_00243e70(u16 *arg0)
{
    *arg0 &= 0xFDFF;
}

// FUN_00243E90
s8 func_00243e90(u8 *arg0)
{
    if (*(u16 *)(arg0 + 2) == 1) {
        return 4;
    }
    return *(s8 *)(arg0 + 0x10);
}

// FUN_00243EC0
void func_00243ec0(u8 *arg0, s8 arg1)
{
    arg0[0x10] = (u8)arg1;
}

// FUN_00243F20
void func_00243f20(u16 characterId)
{
    s16 id;
    s16 value;

    id = (s16)characterId;
    value = (s16)func_00104dc0(id);
    func_001056e0(id, value);
    value = (s16)func_00104e30(id);
    func_00105730(id, value);
    func_00105d50(id, -1);
}

// FUN_00243FA0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00243fa0);

