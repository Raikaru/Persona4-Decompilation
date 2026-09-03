#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_003a. */

extern s32 iGpffffb610;
extern void func_003f32d0(void);

// FUN_003A3DE0
#pragma schedule on
void func_003a3de0(u8 *arg0)
{
    u32 count;
    u8 *base;
    u8 *list;
    u8 *node;

    base = *(u8 **)(arg0 + iGpffffb610);
    if ((*(s32 *)(base + 0x44) & 0x10) == 0) {
        list = *(u8 **)(base + 0x9C);
        if (*(s32 *)(list + 0xD8) != 0) {
            count = 0;
            node = list;
            do {
                if (*(s32 *)(node + 0x10) != 0) {
                    func_003f32d0();
                    func_003f32d0();
                }
                count++;
                node += 0x20;
            } while ((u32)*(s32 *)(list + 0xE8) >= count);
        }
    }
}
/* measured: closing bracket for the schedule-on above; satisfies decomp_lint
   P001 balance and restores the -O2 default for any following code. */
#pragma schedule off