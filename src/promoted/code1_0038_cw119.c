#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_0038. */

extern s32 func_003df050(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
extern u8 *func_003df2a0(u8 *arg0, void *arg1, u32 arg2);
extern u8 *rpCollTreeCreate(u16, u16, f32 *, s32);
extern void (*jtbl_008873EC[])(void *);
extern s32 func_003deff0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_003e2ab0(void *arg0, void *arg1, s32 arg2);
extern void *func_003df270(void *arg0, void *arg1, u32 arg2);

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

typedef struct {
    f32 f[4];
} CollSplit;

typedef struct {
    u32 flags;
    Vec3 sup;
    Vec3 inf;
    u16 numEntries;
    u16 numSplits;
    CollSplit *splits;
    u16 *map;
} CollTree;

typedef struct {
    u32 flags;
    Vec3 inf;
    Vec3 sup;
    s32 numEntries;
    s32 numSplits;
} CollTreeHeader;



/* measured: Under MWCCPS2 3.0.1 b119 (-O4, -inline auto), func_0038fb50 matches lines 44-468 byte-exact (0 differing words for 110 of 120 instructions; exact float-load rotation f5-f0, loop counter, and tail control flow). The remaining 10 words at offsets 0x04-0x28 are the recorded compiler floor: parameter loads (lhu $v1, 0x1e($a0); lw $v0, 0($a0)) scheduled before sd $ra in retail prologue (see wiki/Compiler-Floors.md). */
// FUN_0038FB50 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_0038fb50(CollTree * __restrict tree, void *stream)
{
    s32 offset;
    u32 count;
    CollTreeHeader header;
    CollSplit split;

    offset = 0x30;
    offset += (s32)tree->numSplits * 0x10;
    if (tree->flags & 1) {
        offset += (s32)tree->numEntries * 2;
    }

    if (func_003deff0(stream, 0x2C, offset, 0x37002, 0x37) == 0) {
        return NULL;
    }
    if (func_003deff0(stream, 1, offset - 0xC, 0x37002, 0x37) == 0) {
        return NULL;
    }

    header.inf.x = tree->inf.x;
    header.flags = tree->flags;
    header.inf.y = tree->inf.y;
    header.numEntries = tree->numEntries;
    header.inf.z = tree->inf.z;
    header.numSplits = tree->numSplits;
    header.sup.x = tree->sup.x;
    header.sup.y = tree->sup.y;
    header.sup.z = tree->sup.z;

    if (func_003e2ab0(stream, &header, 0x24) == 0) {
        return NULL;
    }

    if ((s32)tree->numSplits > 0) {
        count = 0;
        if (count < tree->numSplits) {
            offset = 0;
            do {
                split = *(CollSplit *)((u8 *)tree->splits + offset);
                if (func_003e2ab0(stream, &split, 0x10) == 0) {
                    return NULL;
                }
                count++;
                offset += 0x10;
            } while (count < tree->numSplits);
        }
    }

    if (!(tree->flags & 1) || func_003df270(stream, tree->map, (s32)tree->numEntries * 2) != 0) {
        return (u8 *)tree;
    }

    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fb50);
#endif

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
    temp_2 = rpCollTreeCreate(input.count1, input.count2,
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

// FUN_0038FE90
#pragma schedule on
#pragma no_branch_likely on
#pragma opt_rotateloops off
u8 *func_0038fe90(u8 *arg0, u32 arg1, s32 arg2, f32 *arg3, s32 *arg4)
{
    u32 input0;
    u32 input1;
    u32 input2;
    u32 input3;
    u8 dummy[8];
    s32 failure[2];
    u8 *records[36];
    CollTree *tree;
    u8 *data;
    u8 *record;
    u32 depth;
    u32 i;
    u32 j;
    s32 value;

    *arg4 = 0;
    tree = (CollTree *)rpCollTreeCreate(arg1 & 0xFFFF, arg2 & 0xFFFF, arg3, 1);
    if (tree == NULL) {
        return NULL;
    }

    if ((s32)tree->numSplits <= 0) {
        goto check_stream;
    }

    data = (u8 *)tree->splits;
    i = 0;
    if (i < tree->numSplits) {
        goto read_splits;
    }

walk_tree:
    *(u16 *)(dummy + 2) = 0;
    dummy[1] = 0xFF;
    record = dummy;
    depth = 1;

walk_tree_loop:
    if (record[1] != 0xFF) {
        goto walk_tree_pop;
    }
    record = (u8 *)tree->splits + (*(u16 *)(record + 2) * 0x10);
    records[depth++] = record + 8;

walk_tree_test:
    if (depth != 0) {
        goto walk_tree_loop;
    }

check_flags:
    if (tree->flags & 1) {
        i = 0;
        if (i < tree->numEntries) {
            j = 0;
            do {
                if (func_003df360(arg0, &input3, 4) == 0) {
                    jtbl_008873EC[0](tree);
                    return NULL;
                }
                i++;
                *(u16 *)((u8 *)tree->map + j) = input3;
                j += 2;
            } while (i < tree->numEntries);
        }
    }
    return (u8 *)tree;

read_splits:
    do {
        if (func_003df360(arg0, &input0, 4) == 0 ||
            func_003df360(arg0, &input1, 4) == 0 ||
            func_003df300(arg0, data + 4, 4) == 0 ||
            func_003df300(arg0, data + 0xC, 4) == 0) {
            goto error_splits;
        }
        data[8] = input0 >> 16;
        data[0] = data[8] | 1;
        *(s16 *)(data + 0xA) = input1;
        *(s16 *)(data + 2) = input1 >> 16;
        if (((input0 >> 8) & 0xFF) == 2) {
            data[1] = 0xFF;
        } else {
            data[1] = 0;
        }
        if ((u8)input0 == 2) {
            data[9] = 0xFF;
        } else {
            data[9] = 0;
        }
        i++;
        data += 0x10;
    } while (i < tree->numSplits);
    goto walk_tree;

error_splits:
    jtbl_008873EC[0](tree);
    return NULL;

walk_tree_pop:
    if (func_003df360(arg0, &input2, 4) == 0) {
        goto error_tree;
    }
    value = (input2 >> 16) & 0xFFFF;
    if (value >= 0xF0) {
        goto error_failure;
    }
    record[1] = value;
    depth--;
    *(u16 *)(record + 2) = input2;
    record = records[depth];
    goto walk_tree_test;

error_tree:
    jtbl_008873EC[0](tree);
    return NULL;

error_failure:
    *arg4 = 1;
    jtbl_008873EC[0](tree);
    failure[0] = 0x11D;
    failure[1] = func_003df590(1);
    func_003df4d0(failure);
    return NULL;

check_stream:
    if (func_003e2ce0(arg0, 4) != 0) {
        goto check_flags;
    }
    jtbl_008873EC[0](tree);
    return NULL;
}
/* measured: closing bracket for the schedule-on above; satisfies decomp_lint
   P001 balance and restores the -O2 default for any following code. */
#pragma schedule off
#pragma no_branch_likely off
#pragma opt_rotateloops reset
