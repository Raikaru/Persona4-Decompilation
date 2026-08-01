/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00109220)
/* Source unit: src/Main/Battle/Data/datPersona_00109220.c (1 function markers) */
#include "type.h"

extern void FUN_0046d730(const char* file, s32 line);

#define K_ASSERT(condition, line)           \
    do                                      \
    {                                       \
        if (!(condition))                   \
        {                                   \
            FUN_0046d730(__FILE__, (line)); \
        }                                   \
    } while (0)

extern u8* DAT_00764530;

// FUN_00109220
u8* func_00109220(s32 personaId)
{
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x18);
    id = personaId;
    return DAT_00764530 + id * 0x11;
}
#endif /* P4_UNIT_00109220 */

#if defined(P4_UNIT_00109280)
/* Source unit: src/Main/Battle/Data/datPersona_00109280.c (1 function markers) */
#include "type.h"

extern void FUN_0046d730(const char* file, s32 line);

#define K_ASSERT(condition, line)           \
    do                                      \
    {                                       \
        if (!(condition))                   \
        {                                   \
            FUN_0046d730(__FILE__, (line)); \
        }                                   \
    } while (0)

extern u8* DAT_007644c4;

// FUN_00109280
u8 func_00109280(s32 personaId)
{
    u8* table;
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x26);
    table = DAT_007644c4;
    id = personaId;
    return table[id * 0xE + 2];
}
#endif /* P4_UNIT_00109280 */

#if defined(P4_UNIT_0010D490)
/* Source unit: src/Main/Battle/Data/datPersona_0010d490.c (1 function markers) */
#include "type.h"

extern void FUN_0043f9c8(void* destination, s32 value, u32 size);
extern void func_0010d560(void);
extern u8 DAT_007973a0[0x24];

/* Ported from the P3FES donor func_00177410, which carries opt_loop_invariants on
 * around this function to hoist the gGlobalWork base out of both copy loops.
 * Removing this loses func_0010d490 (MATCH nd0 -> MISMATCH nd59, size 200 -> 200)
 * - measured W161 (donor's own P3 measurement: nd89). */
#pragma opt_loop_invariants on

// FUN_0010D490
void func_0010d490(u8* param_1, u8* param_2)
{
    s32 index;
    s8 value;

    FUN_0043f9c8(DAT_007973a0, 0, 0x24);
    index = 0;

    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_1 + index);
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index] = value;
    }

    index = 0;
    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_2 + index);
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index + 0x12] = value;
    }

    func_0010d560();
}
#pragma opt_loop_invariants off
#endif /* P4_UNIT_0010D490 */

#if defined(P4_UNIT_0010D560)
/* Source unit: src/Main/Battle/Data/datPersona_0010d560.c (1 function markers) */
#include "type.h"

extern void FUN_0043f9c8(void* destination, s32 value, u32 size);
extern u32 func_0043f810();
extern u32 func_00442088();
extern u8 DAT_00796de0[];
extern u8 DAT_00796e00[];
extern u8 DAT_00796e20[];
extern u8 DAT_007973a0[];
extern u8 DAT_007973b2[];
extern u32 DAT_00762ca0;

// FUN_0010D560
void func_0010d560(void)
{
    FUN_0043f9c8(DAT_00796de0, 0, 0x12);
    FUN_0043f9c8(DAT_00796e00, 0, 0x12);
    FUN_0043f9c8(DAT_00796e20, 0, 0x24);
    func_0043f810(DAT_00796de0, DAT_007973a0, 0x12);
    func_0043f810(DAT_00796e00, DAT_007973b2, 0x12);
    func_00442088(DAT_00796e20, &DAT_00762ca0, DAT_00796e00, DAT_00796de0);
}
#endif /* P4_UNIT_0010D560 */
