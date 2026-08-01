/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0038E6D0)
/* Source unit: src/Main/OpEd/ed_scroll_0038e6d0.c */
#include "type.h"

extern void func_00271b70(u32 resource);

// FUN_0038E6D0
void func_0038e6d0(u32* record)
{
    s32 i;

    for (i = 0; i < (s32)record[0x21]; i++) {
        func_00271b70(*(u32*)((u8*)record + i * 8 + 8));
    }
    record[0] &= ~1u;
}
#endif /* P4_UNIT_0038E6D0 */

#if defined(P4_UNIT_0038EAE0)
/* Source unit: src/Main/OpEd/ed_scroll_0038eae0.c */
#include "type.h"

extern void func_00272950(u32 resource, s32 x, s32 y);
extern void func_00274a20(u32 resource, f32 angle);

// FUN_0038EAE0
void func_0038eae0(u32* work, const f32* pos)
{
    s32 i;

    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        f32* entry = (f32*)((u8*)work + i * 8 + 4);
        func_00272950(*(u32*)(entry + 1), (s32)((pos[0] + entry[0]) * 16.0f),
                      (s32)(pos[1] * 8.0f));
        func_00274a20(*(u32*)(entry + 1), 0.0f);
    }
}
#endif /* P4_UNIT_0038EAE0 */

#if defined(P4_UNIT_0038EBB0)
/* Source unit: src/Main/OpEd/ed_scroll_0038ebb0.c */
#include "type.h"

extern void func_00272ba0(u32 resource, u32 color);

// FUN_0038EBB0
void func_0038ebb0(u32* work, const u8* color)
{
    s32 i;
    u32 packed;

    packed = (u32)color[0] << 24 | (u32)color[1] << 16 |
             (u32)color[2] << 8 | (u32)color[3];
    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        func_00272ba0(*(u32*)((u8*)work + i * 8 + 8), packed);
    }
}
#endif /* P4_UNIT_0038EBB0 */
