/* object_size=160 window=160 normalized_diff=65 differing_offsets=4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158; classification=near-miss/register allocation and control-flow; ruled out: movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, mixed-unit sd/sq floor. */
/* measured no_branch_likely on; pointer-return typed list walk; did not match. */
u8 *func_003eef60(s32 arg0)
{
    typedef struct RwLink {
        struct RwLink *next;
        struct RwLink *prev;
    } RwLink;
    typedef struct RwList {
        u8 padding[4];
        u8 *item;
        RwLink link;
    } RwList;
    typedef struct RwNode {
        u8 padding[16];
        RwLink link;
    } RwNode;
    extern u8 *func_003ef650(u8 *arg0, s32 arg1);
    u8 *var_18;
    s32 temp_2;
    u8 *temp_17;
    u8 *temp_4;

    temp_17 = (u8 *)D_008872E0 + iGpffffb7e0;
    temp_4 = *(u8 **)(temp_17 + 0x10);
    if (temp_4 != NULL) {
        return func_003ef650(temp_4, arg0);
    }
    var_18 = *(u8 **)temp_17;
    if (var_18 == temp_17) {
        goto block_6;
    }
loop_3:
    temp_2 = (s32)func_003ef650(var_18 - 0x10, arg0);
    if (temp_2 != 0) {
        return (u8 *)temp_2;
    }
    var_18 = *(u8 **)var_18;
    if (var_18 == temp_17) {
        goto block_6;
    }
    goto loop_3;
block_6:
    return NULL;
}
