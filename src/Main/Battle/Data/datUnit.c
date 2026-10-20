#include "include_asm.h"
/* Original translation unit datUnit.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "datUnit_internal.h"
#include "dat_enemy_internal.h"

extern void (*jtbl_008873EC[])(void *);

/* Ported from the P3FES donor src/Main/Battle/Data/datUnit.c (verified MATCH
 * there for 7 of 8 functions); adapted to the P4 build: assert lines
 * (0x1B/0x3F/0x64/0x65/0x75/0x86/0x87/0x93/0xB9/0xD3/0xDA/0xFE) and file
 * string D_00635928, DatUnit stride 0x30 (P3: 0x2C), enemy-table stride
 * 0x3C (P3: 0x3E), chkmemAllocSiteTag location calls, jtbl_008873E8 malloc. */


typedef struct EncountTblEntry
{
    u16 unknown00[4];
    u16 enmIds[5];
    u16 unknown12[3];
} EncountTblEntry;

enum { UNIT_GENUS_PC = 0, UNIT_GENUS_EC = 1 };

extern char D_00635928[];
extern void chkmemAllocSiteTag(const char* file, s32 line);
extern void kAssertFail(const char* file, s32 line);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void memset(void* dest, s32 value, s32 size);
extern u8* datUnitGetRecord(s16 unitId);
extern s32 datCalcIsDead(DatUnit* unit, s32 hpDelta);
extern void datCalcClearBuffLevel(DatUnit* unit, u8 buffIndex);
extern u8* iGpffffb3c4;              /* 0x007644B4 (gp-0x4C3C): enemy data table */
extern u8* iGpffffb414;              /* 0x00764504 (gp-0x4BEC) */


/* Allocate a PC group and initialize its single persistent unit record. */
// FUN_00231580
DatUnitPc* datUnitCreatePc(u16 pcId)
{
    DatUnitPc* pc;

    chkmemAllocSiteTag(D_00635928, 0x1B);
    pc = (DatUnitPc*)(*jtbl_008873E8)(sizeof(DatUnitPc), 0x40000);
    memset(pc, 0, sizeof(DatUnitPc));

    pc->base.genus = UNIT_GENUS_PC;
    pc->base.count = 1;
    pc->base.unit = (DatUnit*)datUnitGetRecord(pcId);

    datUnitInit(pc->base.unit, UNIT_GENUS_PC, pcId);

    return pc;
}

/* measured: canonical iGpffffb414 GP symbol and explicit offset local produce the retail global-load ordering and exact 368-byte object. */
/* measured: baseline differs by 5 words; loop-local and function-local encounter pointers leave nd13/nd12; retain hoisting. */
#pragma opt_loop_invariants on
// FUN_00231630
/* Preserve the measured cursor arithmetic while naming the enemy and encounter row members. */
/* Allocate a six-slot enemy group and initialize the nonempty IDs from the five-entry encounter row. */
DatUnitEc* datUnitCreateEncounterGroup(u16 encountId)
{
    u32 count;
    u16 i;
    DatUnitEc* ec;
    u16 j;
    u32 stride;
    u16 k;
    u32 ioff;

    count = 0;
    i = 0;
    stride = (encountId & 0xFFFF) * 0x18;
    {
        EncountTblEntry* entry;

        entry = (EncountTblEntry*)((u8*)iGpffffb414 + stride);
        for (; (u32)(i & 0xFFFF) < 5U; i++)
        {
            ioff = (u32)i * 2;
            if (((EncountTblEntry *)((u8 *)entry + ioff))->enmIds[0] != 0)
            {
                count = (count + 1) & 0xFFFF;
            }
        }
    }

    chkmemAllocSiteTag(D_00635928, 0x3F);
    ec = (DatUnitEc*)(*jtbl_008873E8)(0x12C, 0x40000);
    memset(ec, 0, 0x12C);

    ec->base.genus = UNIT_GENUS_EC;
    ec->base.count = count;
    ec->encountId = encountId;
    ec->base.unit = ec->units;

    j = 0;
    for (k = 0; (u32)(k & 0xFFFF) < 5U; k++)
    {
        if (((EncountTblEntry*)((u32)stride + (u32)iGpffffb414))->enmIds[k] != 0)
        {
            datUnitInit(&ec->base.unit[j], UNIT_GENUS_EC, ((EncountTblEntry*)((u32)stride + (u32)iGpffffb414))->enmIds[k]);
            j++;
        }
    }

    return ec;
}
#pragma opt_loop_invariants off

/* Initialize the first free enemy slot and increment the encounter group count. */
// FUN_002317A0
DatUnit* datUnitAddEncounterUnit(DatUnitEc* ec, u16 id)
{
    u16 i;
    DatUnit* curr;

    if (ec->base.genus != UNIT_GENUS_EC) kAssertFail(D_00635928, 0x64);
    if (ec->base.count >= 6) kAssertFail(D_00635928, 0x65);

    for (i = 0; i < 6; i++)
    {
        curr = &ec->base.unit[i];

        if (curr->id == 0)
        {
            datUnitInit(curr, UNIT_GENUS_EC, id);
            ec->base.count++;

            break;
        }
    }

    if (i >= 6) kAssertFail(D_00635928, 0x75);

    return curr;
}

/* Clear the matching enemy slot ID and decrement the encounter group count. */
// FUN_002318C0
void datUnitRemoveEncounterUnit(DatUnitEc* ec, DatUnit* unit)
{
    u16 i;
    DatUnit* curr;

    if (ec->base.genus != UNIT_GENUS_EC) kAssertFail(D_00635928, 0x86);
    if (ec->base.count > 6) kAssertFail(D_00635928, 0x87);

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

    if (i >= 6) kAssertFail(D_00635928, 0x93);
}

// FUN_002319C0
void datUnitFree(s32 allocation)
{
    jtbl_008873EC[0]((void *)allocation);
}

/* Return true only when every occupied enemy slot, or the single PC unit, is dead. */
// FUN_002319F0
u32 datUnitGroupIsDefeated(DatUnitGenusBase* genusBase)
{
    u16 i;

    if (genusBase->genus == UNIT_GENUS_EC)
    {
        for (i = 0; i < 6; i++)
        {
            DatUnit* unit = genusBase->unit;
            unit += i;

            if (unit->id != 0 && datCalcIsDead(unit, 0) == 0)
            {
                return 0;
            }
        }
    }
    else
    {
        if (genusBase->count != 1) kAssertFail(D_00635928, 0xB9);

        if (datCalcIsDead(genusBase->unit, 0) == 0)
        {
            return 0;
        }
    }

    return 1;
}

/* measured: retail hoists the 0x1F6/0x1F7/0x1F8 skill constants into the
 * loop preheader and keeps id*0x3C live across the flag tests; without
 * opt_loop_invariants MWCC rematerializes them inside the loop. */
/* measured: baseline differs by 19 words; named skill constants and equivalent comparisons leave nd159; retain hoisting. */
#pragma opt_loop_invariants on
// FUN_00231AF0
/* Preserve the measured cursor arithmetic while naming the enemy and encounter row members. */
/* Initialize PC flags or copy enemy defaults, clear all buff levels and set both unit IDs. */
u32 datUnitInit(DatUnit* unit, u8 genus, u16 id)
{
    u32 i;
    u32 j;

    switch (genus)
    {
    case UNIT_GENUS_PC:
        if ((id & 0xFFFF) >= 0xB) kAssertFail(D_00635928, 0xD3);
        unit->flags &= ~0x4;
        unit->flags &= ~0x8;
        unit->flags &= ~0x10;
        unit->flags &= ~0x200;
        break;
    case UNIT_GENUS_EC:
        if ((id & 0xFFFF) >= 0x150) kAssertFail(D_00635928, 0xDA);
        unit->flags = 4;
        unit->level = iGpffffb3c4[id * 0x3c + 3];
        unit->hp = ((DatEnemyUnitInit *)((u8*)(uintptr_t)((u32)id * 0x3c) +
                          (uintptr_t)iGpffffb3c4))->hp;
        unit->sp = ((DatEnemyUnitInit *)((u8*)(uintptr_t)((u32)id * 0x3c) +
                          (uintptr_t)iGpffffb3c4))->sp;
        unit->bad = 0;
        if (((DatEnemyUnitInit *)(iGpffffb3c4 + id * 0x3c))->flags & 8) unit->flags |= 0x8;
        if (((DatEnemyUnitInit *)(iGpffffb3c4 + id * 0x3c))->flags & 0x10) unit->flags |= 0x10;
        if (((DatEnemyUnitInit *)(iGpffffb3c4 + id * 0x3c))->flags & 0x100) unit->flags |= 0x40;
        if (((DatEnemyUnitInit *)(iGpffffb3c4 + id * 0x3c))->flags & 0x200) unit->flags |= 0x80;
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
        kAssertFail(D_00635928, 0xFE);
        break;
    }
    for (j = 0; j < 0x18; j++) datCalcClearBuffLevel(unit, (u8)j);
    unit->id = id;
    unit->id2 = id;
    unit->flags |= 0x1;
    return 1;
}
#pragma opt_loop_invariants off
