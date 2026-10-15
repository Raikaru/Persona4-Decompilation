#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_0038. */

extern s32 func_003df050(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
extern u8 *func_003df2a0(u8 *arg0, void *arg1, u32 arg2);
extern u8 *func_0038f990(u16, u16, f32 *, s32);
extern void (*jtbl_008873EC[])(void *);

typedef struct {
    f32 x, y, z;
} Vec3;

struct Input {
    s32 size;
    Vec3 min;
    Vec3 max;
    u16 count1;
    u8 pad7E[2];
    u16 count2;
    u8 padding[8];
};

struct Output {
    Vec3 min;
    Vec3 max;
};

// FUN_0038FD30
#pragma schedule on
#pragma no_branch_likely on
u8 *func_0038fd30(u8 *arg0)
{
    struct Input input;
    struct Output output;
    u8 status[4];
    s32 temp_18;
    u16 temp_2_2;
    u8 *temp_2;

    if (func_003df050(arg0, 1, 0, status) != 0) {
        goto read_header;
    }
    return NULL;

read_header:
    if (func_003e2910(arg0, &input, 0x24) == 0x24) {
        goto make_output;
    }
    return NULL;

make_output:
    output.max = input.min;
    output.min = input.max;
    temp_2 = func_0038f990(input.count1, input.count2,
                            (f32 *)&output.min, input.size);
    if (temp_2 == NULL) {
        goto result_null;
    }
    temp_2_2 = *(u16 *)(temp_2 + 0x1E);
    if ((s32)temp_2_2 > 0) {
        goto read_data;
    }

check_flags:
    if ((*(s32 *)temp_2 & 1) != 0) {
        goto read_flags;
    }

return_result:
    return temp_2;

result_null:
    return NULL;

read_data:
    temp_18 = (s32)temp_2_2 * 0x10;
    if (func_003e2910(arg0, *(void **)(temp_2 + 0x20), temp_18) == temp_18) {
        goto check_flags;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;

read_flags:
    if (func_003df2a0(arg0, *(void **)(temp_2 + 0x24),
                      (s32)*(u16 *)(temp_2 + 0x1C) * 2) != 0) {
        goto return_result;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;
}
/* measured: closing bracket for the schedule-on above; satisfies decomp_lint
   P001 balance and restores the -O2 default for any following code. */
#pragma schedule off
#pragma no_branch_likely off
