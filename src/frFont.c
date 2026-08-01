/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00271820)
/* Source unit: src/frFont_00271820.c */
#include "type.h"

typedef int (*code)(...);

#pragma alias DAT_00881630_abs DAT_00881630
extern u32 DAT_00881630_abs[];
#pragma alias DAT_008873ec_abs DAT_008873ec
extern code DAT_008873ec_abs[];

// FUN_00271820
void func_00271820(u32 param_1)
{
    DAT_008873ec_abs[0](DAT_00881630_abs[(param_1 & 0xff) * 8]);
}
#endif /* P4_UNIT_00271820 */

#if defined(P4_UNIT_00272C60)
/* Source unit: src/frFont_00272c60.c */
#include "type.h"

extern s16 D_00763810;

// FUN_00272C60
u16 func_00272c60(s16 param_1)
{
    u16 uVar1;

    uVar1 = D_00763810;
    D_00763810 = D_00763810 | param_1;
    return uVar1;
}
#endif /* P4_UNIT_00272C60 */

#if defined(P4_UNIT_00272C80)
/* Source unit: src/frFont_00272c80.c */
#include "type.h"

extern s16 D_00763810;

// FUN_00272C80
u16 func_00272c80(u16 param_1)
{
    u16 uVar1;
    long mask;

    uVar1 = D_00763810;
    mask = (s16)~param_1;
    D_00763810 = D_00763810 & mask;
    return uVar1;
}
#endif /* P4_UNIT_00272C80 */

#if defined(P4_UNIT_00272CB0)
/* Source unit: src/frFont_00272cb0.c */
#include "type.h"

// Ported from P3FES FUN_003b0ec0 (verified MATCH there). Retail hoists the
// loop-invariant mask/type constants here; removing opt_loop_invariants
// measured nd102 at 136B instead of nd1 at 140B (P3 donor annotation).
// FUN_00272CB0
#pragma push
#pragma opt_loop_invariants on

u32 func_00272cb0(int list)
{
    u32 result = 0;
    u32 mask = ~0xff;
    u32 changed = 1;
    u32 type = 2;

    while (list != 0) {
        int node = *(int *)(list + 0x1c);

        while (node != 0) {
            if (*(u8 *)(node + 0x16) == type) {
                u32 word = *(u32 *)(node + 0x10);
                u32 fade = word & 0xff;
                u32 merged;

                if (fade != 0) {
                    fade -= 8;
                    if ((s32)fade < 0) {
                        fade = 0;
                    }
                    merged = word & mask;
                    merged |= fade;
                    *(u32 *)(node + 0x10) = merged;
                    *(u32 *)(node + 8) += 0x10;
                    result = changed;
                }
            }
            node = *(int *)(node + 0x28);
        }
        list = *(int *)(list + 0x24);
    }
    return result;
}
#pragma opt_loop_invariants off
#pragma pop
#endif /* P4_UNIT_00272CB0 */

#if defined(P4_UNIT_00273140)
/* Source unit: src/frFont_00273140.c */
#include "type.h"

extern u32 D_00764598;
extern int func_00273170(void *param_1, u32 param_2, u32 param_3);

// FUN_00273140
void func_00273140(void *param_1, u32 param_2)
{
    func_00273170(param_1, param_2, D_00764598);
}
#endif /* P4_UNIT_00273140 */

#if defined(P4_UNIT_00273650)
/* Source unit: src/frFont_00273650.c */
#include "type.h"

// FUN_00273650
int func_00273650(int param_1, int param_2, int param_3)
{
    if (param_1 != 0)
    {
        goto checkParam2;
    }
    return param_2;

checkParam2:
    if (param_2 != 0)
    {
        goto body;
    }
    return param_1;

body:
    *(u32*)(param_1 + 0x28) = *(u32*)(param_2 + 0x2c);
    *(int*)(*(int*)(param_2 + 0x2c) + 0x24) = param_1;
    *(u32*)(param_2 + 0x2c) = *(u32*)(param_1 + 0x2c);

    if (param_3 == 1)
    {
        *(int*)(param_2 + 4) = *(int*)(param_1 + 4) + *(int*)(param_1 + 0xc) * 0x10;
        *(u32*)(param_2 + 8) = *(u32*)(param_1 + 8);
    }

    return param_2;
}
#endif /* P4_UNIT_00273650 */

#if defined(P4_UNIT_002738A0)
/* Source unit: src/frFont_002738a0.c */
#include "type.h"

extern void func_002716b0(u32 param_1, u64 param_2, u32 param_3);

// FUN_002738A0
void func_002738a0(u64 param_1)
{
    func_002716b0(8, param_1, 0);
}
#endif /* P4_UNIT_002738A0 */

#if defined(P4_UNIT_002738D0)
/* Source unit: src/frFont_002738d0.c */
#include "type.h"

typedef struct FrFontGlyph {
    u8 unknown_00[0xc];
    int advance;
    u8 unknown_10[0x18];
    struct FrFontGlyph *next;
} FrFontGlyph;

typedef struct FrFontNode {
    u8 unknown_00[3];
    s8 line_height;
    u8 unknown_04[0x18];
    FrFontGlyph *glyphs;
    u8 unknown_20[4];
    struct FrFontNode *next;
    u8 unknown_28[0x18];
    int enabled;
} FrFontNode;

// FUN_002738D0
int func_002738d0(FrFontNode *node)
{
    int total = 0;
    FrFontGlyph *glyph;

    for (glyph = node->glyphs; glyph != NULL; glyph = glyph->next) {
        total += glyph->advance;
        total += node->line_height;
    }
    return total;
}
#endif /* P4_UNIT_002738D0 */

#if defined(P4_UNIT_00273910)
/* Source unit: src/frFont_00273910.c */
#include "type.h"

#pragma alias DAT_00881634_abs DAT_00881634
extern u32 DAT_00881634_abs[];

// FUN_00273910
u16 func_00273910(u32 param_1)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(param_1 & 0xff) * 8];
    return *(u16 *)((u8 *)entry + 0x10);
}
#endif /* P4_UNIT_00273910 */

#if defined(P4_UNIT_00273940)
/* Source unit: src/frFont_00273940.c */
#include "type.h"

#pragma alias DAT_00881634_abs DAT_00881634
extern u32 DAT_00881634_abs[];

// FUN_00273940
u16 func_00273940(u32 param_1)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(param_1 & 0xff) * 8];
    return *(u16 *)((u8 *)entry + 0x12);
}
#endif /* P4_UNIT_00273940 */

#if defined(P4_UNIT_00274570)
/* Source unit: src/frFont_00274570.c */
#include "type.h"

// func_002745c0 is intentionally left undeclared (implicit old-style call,
// as in the P3 donor): a typed u8 prototype makes mwcc emit andi
// zero-extensions the retail never has.
// FUN_00274570
void func_00274570(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                   u32 param_5, u32 param_6, u32 param_7, u32 param_8)
{
    func_002745c0(param_1, param_2, 0, param_3, param_4, param_5, param_6, param_7, param_8);
}
#endif /* P4_UNIT_00274570 */
