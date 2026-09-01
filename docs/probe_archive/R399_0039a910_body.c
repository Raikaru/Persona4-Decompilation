/* object 276 / window 288 / normalized_diff 48; differing offsets 0x0e,0x12,0x29,0x2d-0x32,0x61,0x6a,0x72,0x7a,0x82,0x86,0x8a,0xe1-0x113; undersized 12 bytes: retail prologue/branches/jump-table dispatch match, but base/entry/index0 register colors, final address recomputation and jump-table relocations differ; classification declaration/register coloring plus final expression/address; ruled out exhaustive switch without case reordering, no_branch_likely alone, and conditional rebuild without no_branch_likely. */
void func_0039a910(s32 arg0)
{
    s32 type;
    s32 state;
    s32 index1;
    u32 index0;
    u8 **holder;
    u8 *entry;
    u8 *base;
    extern u8 D_0064F280[];
    holder = (u8 **)(arg0 + iGpffffb5e0);
    base = *holder;
    state = *(s32 *)(base + 0x80);
    if (state != 4) goto state_one;
    type = 0;
    goto state_done;
state_one:
    type = 1;
state_done:
    entry = base + (type << 6);
    switch (*(s32 *)(entry + 4)) {
    case 1: index0=0; break; case 2:index0=1; break; case 5:index0=2; break;
    case 6:index0=3; break; case 7:index0=4; break;
    case 0: case 3: case 4: case 8: default: index0=5; break;
    }
    switch (*(s32 *)(entry + 8)) {
    case 1: index1=0; break; case 2:index1=1; break; case 5:index1=2; break;
    case 6:index1=3; break; case 7:index1=4; break;
    case 0: case 3: case 4: case 8: default: index1=5; break;
    }
    *(u64 *)((type << 6) + base + 0x28) =
        (u64)*(u8 *)(D_0064F280 + index1 * 6 + index0) | ((u64)0x80 << 32);
}
