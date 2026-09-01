/* func_003ed7e0 object=96 window=112 normalized_diff=27 differing_offsets=28,31,34,35,64,66,67,68,70,71,74,75,76,77,78,79 classification=near-miss; frame=48 bytes, saved-s=2, args=0; ruled_out=missing-body */
s32 func_003ed7e0(void)
{
    extern void func_003ed650(u8 *arg0);
    extern u8 *D_008873A0;
    typedef struct RwLink { struct RwLink *next; struct RwLink *prev; } RwLink;
    RwLink *sentinel; RwLink *node;
    sentinel = (RwLink *)&D_0088739C[0]; node = sentinel->next;
    if (node != sentinel) do { func_003ed650((u8 *)node - 8); node = node->next; } while (node != sentinel);
    sentinel->next = sentinel; D_008873A0 = (u8 *)sentinel; return 1;
}
