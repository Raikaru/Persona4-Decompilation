/* func_003ed540 object=244 window=272 normalized_diff=158 differing_offsets=20,21,22,23,24,25,26,27,28,30,31,32,34,35,38,39 classification=undersized; ruled_out=saved-s-register-count(4), argument-count(1), typed-self-referential-list-and-no_branch_likely-attempted */
void func_003ed540(u8 *arg0)
{
    typedef struct RwLink { struct RwLink *next; struct RwLink *prev; } RwLink;
    typedef struct RwCallbackNode { u8 padding[8]; RwLink link; void (*callback)(void *arg); } RwCallbackNode;
    typedef struct RwObject { u8 padding[3]; u8 flags; s32 value; u8 padding2[0x88]; RwLink list; struct RwObject *child; struct RwObject *sibling; } RwObject;
    RwLink *temp_16; RwLink *temp_18; RwObject *var_16; RwObject *var_17; RwLink *var_18; RwLink *var_19;
    var_17 = (RwObject *)arg0;
    if (var_17 != NULL) {
        do {
            var_18 = var_17->list.next; temp_16 = &var_17->list;
            if ((var_18 != temp_16) && (var_18 != temp_16)) {
                do { ((RwCallbackNode *)((u8 *)var_18 - 8))->callback((u8 *)var_18 - 8); var_18 = var_18->next; } while (var_18 != temp_16);
            }
            var_17->flags = var_17->flags & ~8; var_16 = var_17->child;
            if (var_16 != NULL) {
                do {
                    var_19 = var_16->list.next; temp_18 = &var_16->list;
                    if ((var_19 != temp_18) && (var_19 != temp_18)) {
                        do { ((RwCallbackNode *)((u8 *)var_19 - 8))->callback((u8 *)var_19 - 8); var_19 = var_19->next; } while (var_19 != temp_18);
                    }
                    var_16->flags = var_16->flags & ~8; func_003ed540((u8 *)var_16->child); var_16 = var_16->sibling;
                } while (var_16 != NULL);
            }
            var_17 = var_17->sibling;
        } while (var_17 != NULL);
    }
}
