#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit datUnit.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void);

/* Ported from the P3FES donor src/Main/Battle/Data/datUnit.c (verified MATCH
 * there for 7 of 8 functions); adapted to the P4 build: assert lines
 * (0x1B/0x3F/0x64/0x65/0x75/0x86/0x87/0x93/0xB9/0xD3/0xDA/0xFE) and file
 * string D_00635928, DatUnit stride 0x30 (P3: 0x2C), enemy-table stride
 * 0x3C (P3: 0x3E), func_0044ea90 location calls, jtbl_008873E8 malloc. */

typedef struct DatUnit
{
    u16 flags;          // 0x00
    u16 id;             // 0x02
    u16 id2;            // 0x04
    u8 level;           // 0x06
    u16 hp;             // 0x08
    u16 sp;             // 0x0A
    u32 bad;            // 0x0C
    u8 unknown10[0x20]; // 0x10
} DatUnit;

typedef struct DatUnitGenusBase
{
    u16 genus;     // 0x00
    u16 count;     // 0x02
    DatUnit* unit; // 0x04
} DatUnitGenusBase;

typedef struct DatUnitPc
{
    DatUnitGenusBase base;
    u32 unknown08;
} DatUnitPc;

typedef struct DatUnitEc
{
    DatUnitGenusBase base; // 0x00
    u16 encountId;         // 0x08
    u16 unknown0A;         // 0x0A
    DatUnit units[6];      // 0x0C
} DatUnitEc;

typedef struct DatEnemyUnitInit
{
    u16 flags;
    u8 unknown02;
    u8 level;
    u16 hp;
    u16 sp;
    u8 unknown08[6];
    u16 skills[8];
    u8 unknown1E[0x1E];
} DatEnemyUnitInit;

typedef struct EncountTblEntry
{
    u16 unknown00[4];
    u16 enmIds[5];
    u16 unknown12[3];
} EncountTblEntry;

enum { UNIT_GENUS_PC = 0, UNIT_GENUS_EC = 1 };

extern char D_00635928[];
extern void func_0044ea90(const char* file, s32 line);
extern void func_0046d730(const char* file, s32 line);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0043f9c8(void* dest, s32 value, s32 size);
extern u8* func_00105510(s16 arg0);
extern s32 func_002428f0(DatUnit* unit, s32 arg1);
extern void func_00233880(DatUnit* unit, u8 index);
extern u8* iGpffffb3c4;              /* 0x007644B4 (gp-0x4C3C): enemy data table */
extern EncountTblEntry* gEncountTbl; /* 0x00764504 (gp-0x4BEC) */

extern u32 func_00231af0(DatUnit* unit, u8 genus, u16 id);

// FUN_00231580
DatUnitPc* func_00231580(u16 pcId)
{
    DatUnitPc* pc;

    func_0044ea90(D_00635928, 0x1B);
    pc = (DatUnitPc*)(*jtbl_008873E8)(sizeof(DatUnitPc), 0x40000);
    func_0043f9c8(pc, 0, sizeof(DatUnitPc));

    pc->base.genus = UNIT_GENUS_PC;
    pc->base.count = 1;
    pc->base.unit = (DatUnit*)func_00105510(pcId);

    func_00231af0(pc->base.unit, UNIT_GENUS_PC, pcId);

    return pc;
}

// FUN_00231630
INCLUDE_ASM("asm/nonmatchings/datUnit", func_00231630);

// FUN_002317A0
DatUnit* func_002317a0(DatUnitEc* ec, u16 id)
{
    u16 i;
    DatUnit* curr;

    if (ec->base.genus != UNIT_GENUS_EC) func_0046d730(D_00635928, 0x64);
    if (ec->base.count >= 6) func_0046d730(D_00635928, 0x65);

    for (i = 0; i < 6; i++)
    {
        curr = &ec->base.unit[i];

        if (curr->id == 0)
        {
            func_00231af0(curr, UNIT_GENUS_EC, id);
            ec->base.count++;

            break;
        }
    }

    if (i >= 6) func_0046d730(D_00635928, 0x75);

    return curr;
}

// FUN_002318C0
void func_002318c0(DatUnitEc* ec, DatUnit* unit)
{
    u16 i;
    DatUnit* curr;

    if (ec->base.genus != UNIT_GENUS_EC) func_0046d730(D_00635928, 0x86);
    if (ec->base.count > 6) func_0046d730(D_00635928, 0x87);

    for (i = 0; i < 6; i++)
    {
        curr = &ec->base.unit[i];

        if (unit == curr)
        {
            curr->id = 0;
            ec->base.count--;

            break;
        }
    }

    if (i >= 6) func_0046d730(D_00635928, 0x93);
}

// FUN_002319F0
u32 func_002319f0(DatUnitGenusBase* genusBase)
{
    u16 i;

    if (genusBase->genus == UNIT_GENUS_EC)
    {
        for (i = 0; i < 6; i++)
        {
            DatUnit* unit = genusBase->unit;
            unit += i;

            if (unit->id != 0 && func_002428f0(unit, 0) == 0)
            {
                return 0;
            }
        }
    }
    else
    {
        if (genusBase->count != 1) func_0046d730(D_00635928, 0xB9);

        if (func_002428f0(genusBase->unit, 0) == 0)
        {
            return 0;
        }
    }

    return 1;
}

/* measured: retail hoists the 0x1F6/0x1F7/0x1F8 skill constants into the
 * loop preheader and keeps id*0x3C live across the flag tests; without
 * opt_loop_invariants MWCC rematerializes them inside the loop. */
#pragma opt_loop_invariants on
// FUN_00231AF0
u32 func_00231af0(DatUnit* unit, u8 genus, u16 id)
{
    u32 i;
    u32 j;

    switch (genus)
    {
    case UNIT_GENUS_PC:
        if ((id & 0xFFFF) >= 0xB) func_0046d730(D_00635928, 0xD3);
        unit->flags &= ~0x4;
        unit->flags &= ~0x8;
        unit->flags &= ~0x10;
        unit->flags &= ~0x200;
        break;
    case UNIT_GENUS_EC:
        if ((id & 0xFFFF) >= 0x150) func_0046d730(D_00635928, 0xDA);
        unit->flags = 4;
        unit->level = iGpffffb3c4[id * 0x3c + 3];
        unit->hp = *(u16*)((u8*)(uintptr_t)((u32)id * 0x3c) +
                          (uintptr_t)iGpffffb3c4 + 4);
        unit->sp = *(u16*)((u8*)(uintptr_t)((u32)id * 0x3c) +
                          (uintptr_t)iGpffffb3c4 + 6);
        unit->bad = 0;
        if (*(u16*)(iGpffffb3c4 + id * 0x3c) & 8) unit->flags |= 0x8;
        if (*(u16*)(iGpffffb3c4 + id * 0x3c) & 0x10) unit->flags |= 0x10;
        if (*(u16*)(iGpffffb3c4 + id * 0x3c) & 0x100) unit->flags |= 0x40;
        if (*(u16*)(iGpffffb3c4 + id * 0x3c) & 0x200) unit->flags |= 0x80;
        for (i = 0; i < 8; i++)
        {
            u16 skill = ((DatEnemyUnitInit*)iGpffffb3c4)[id].skills[i];
            switch (skill)
            {
            case 0x1F6:
            case 0x1F7:
            case 0x1F8:
                unit->flags |= 0x100;
                break;
            }
        }
        break;
    default:
        func_0046d730(D_00635928, 0xFE);
        break;
    }
    for (j = 0; j < 0x18; j++) func_00233880(unit, (u8)j);
    unit->id = id;
    unit->id2 = id;
    unit->flags |= 0x1;
    return 1;
}
#pragma opt_loop_invariants off

// FUN_002319C0
void func_002319c0(void)
{
    jtbl_008873EC[0]();
}
