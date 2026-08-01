/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002706F0)
#include "type.h"

extern s32 func_002746a0(void);
extern void func_00273f70(u8 *arg0);
extern void func_00273cc0(u8 *arg0, u8 *arg1);

// FUN_002706F0
s32 func_002706f0(u8 *arg0, u8 *arg1)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    func_00273f70(arg1);
    func_00273cc0(NULL, arg1);
    return 0;
}
#endif /* P4_UNIT_002706F0 */

#if defined(P4_UNIT_00271380)
#include "type.h"

extern void func_002716b0(s32 arg0, s32 arg1, u8 *arg2);

// FUN_00271380
void func_00271380(s32 arg0, u8 *arg1)
{
    func_002716b0(arg0, 0, arg1);
}
#endif /* P4_UNIT_00271380 */

#if defined(P4_UNIT_00273110)
#include "type.h"

extern void func_00273140(s32 arg0, s32 arg1);

// FUN_00273110
void func_00273110(s32 arg0)
{
    func_00273140(arg0, 0);
}
#endif /* P4_UNIT_00273110 */

#if defined(P4_UNIT_002746C0)
#include "type.h"

extern s32 D_008815B0[];

// FUN_002746C0
void func_002746c0(s32 arg0, s32 arg1)
{
    D_008815B0[arg0] = arg1;
}
#endif /* P4_UNIT_002746C0 */

#if defined(P4_UNIT_00278610)
#include "type.h"

extern void func_00278640(s32 arg0, s16 arg1, s32 arg2);

// FUN_00278610
s32 func_00278610(s32 arg0, s16 arg1)
{
    func_00278640(arg0, arg1, 0);
    return 0;
}
#endif /* P4_UNIT_00278610 */

#if defined(P4_UNIT_00278FB0)
#include "type.h"

typedef struct {
    u8 *unk0;
    u8 pad[28];
} D_00881808_t;

extern D_00881808_t D_00881808[];

// FUN_00278FB0
s32 func_00278fb0(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x20);
}
#endif /* P4_UNIT_00278FB0 */

#if defined(P4_UNIT_00278FD0)
#include "type.h"

typedef struct {
    u8 *unk0;
    u8 pad[28];
} D_00881808_t;

extern D_00881808_t D_00881808[];

// FUN_00278FD0
s32 func_00278fd0(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x14);
}
#endif /* P4_UNIT_00278FD0 */

#if defined(P4_UNIT_0027A5E0)
#include "type.h"

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0027bf10(s32 arg0);

// FUN_0027A5E0
void func_0027a5e0(s32 *arg0, s32 arg1)
{
    memset(arg0, 0, 0x1C);
    *arg0 = func_0027bf10(arg1);
}
#endif /* P4_UNIT_0027A5E0 */

#if defined(P4_UNIT_0027A650)
#include "type.h"

// FUN_0027A650
void func_0027a650(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s8 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 9) = 0;
    *(s16 *)(arg0 + 0xE) = 0;
    *(s16 *)(arg0 + 0x10) = 0;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s8 *)(arg0 + 0xA) = 0;
    *(s8 *)(arg0 + 0xB) = 0;
    *(s8 *)(arg0 + 0xC) = 0;
    *(u8 *)(arg0 + 0xD) = 0xFF;
}
#endif /* P4_UNIT_0027A650 */

#if defined(P4_UNIT_0027B4C0)
#include "type.h"

extern u16 D_008817E8[];

// FUN_0027B4C0
void func_0027b4c0(s32 *arg0)
{
    s32 temp;

    temp = *arg0;
    if (!(temp & 0x80000) && ((u32)(temp & 0x300) >= 0x100U)) {
        D_008817E8[0] |= 2;
    }
}
#endif /* P4_UNIT_0027B4C0 */
