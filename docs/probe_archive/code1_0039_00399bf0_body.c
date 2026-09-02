/* code1_0039 / func_00399bf0 probe archive.
 * object_size=376B window=400B normalized_diff=236 (m2c-style body).
 * Differing offsets: first if-branch sense/allocator placement (retail beqz to
 * .Lalloc; candidate bnez to .Lbody), dealloc branch layout (arg1==0 vs old!=0),
 * switch jump-table base (retail jtbl_00752C60; candidate local @410/@413),
 * switch case order/placement, tail size.
 * Levers tried: #pragma peephole off, #pragma schedule on, #pragma no_branch_likely on,
 * explicit if/else dealloc, m2c ||-load condition, goto body/alloc block ordering.
 * Still needs: a body/alloc layout that forces the start beqz p,.Lalloc and a
 * switch that emits the jtbl_00752C60 relocation.
 */
#include "include_asm.h"
#include "type.h"

extern u8 *(*D_008873F8[])(s32, s32);
extern s32 D_00884A80[];
extern void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00398410(u8 *arg0);
extern s32 func_0039a590(s32 arg0, s32 arg1, s32 arg2);
extern void func_0039a7f0(s32 arg0);

s32 func_00399bf0(s32 arg0, u32 arg1)
{
    u8 *p;
    u32 temp;

    p = *(u8 **)(arg0 + iGpffffb5e0);
    if (p == NULL) {
        p = D_008873F8[0](D_00884A80[0], 0x30120);
        if (p != NULL) {
            func_0043f9c8(p, 0, 0x90);
            *(u8 **)(arg0 + iGpffffb5e0) = p;
        } else {
            p = NULL;
        }
    }
    if (p != NULL) {
        if ((arg1 == 0) || ((temp = *(u32 *)(p + 0x80), (temp != 0)) && (temp != arg1))) {
            func_00398410(p);
        }
        *(u32 *)(p + 0x80) = arg1;
        switch (*(u32 *)(p + 0x80)) {
        case 1:
            *(u32 *)(p + 0x20) = 1;
            break;
        case 2:
            *(u32 *)(p + 0x20) = 2;
            break;
        case 3:
            *(u32 *)(p + 0x20) = 1;
            *(u32 *)(p + 0x60) = 2;
            break;
        case 4:
            *(u32 *)(p + 0x20) = 4;
            func_0039a590(arg0, 5, 6);
            break;
        case 5:
            *(u32 *)(p + 0x20) = 5;
            break;
        case 6:
            *(u32 *)(p + 0x20) = 5;
            *(u32 *)(p + 0x60) = 4;
            func_0039a590(arg0, 5, 6);
            break;
        }
        func_0039a7f0(arg0);
        return arg0;
    }
    return 0;
}
