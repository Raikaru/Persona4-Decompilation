/* func_003ed850 object=232 window=272 normalized_diff=154 differing_offsets=16,17,18,19,20,22,24,26,28,29,30,31,32,33,34,35 classification=undersized; ruled_out=saved-s-register-count(6), argument-count(2), typed-list-probe */
void func_003ed850(u8 *arg0, s32 arg1)
{
    extern void func_003e05f0(u8 *arg0, u8 *arg1, s32 arg2);
    typedef struct RwLink { struct RwLink *next; struct RwLink *prev; } RwLink;
    typedef struct RwList { u8 padding[3]; u8 flags; s32 value; u8 padding2[0x88]; RwLink link; struct RwList *child; struct RwList *sibling; } RwList;
    s32 temp_19; s32 temp_20; u8 *flagptr; RwList *var_17; RwList *var_21;
    var_17 = (RwList *)arg0;
    if (var_17 != NULL) {
        do {
            temp_19 = arg1 | var_17->flags; flagptr = &var_17->flags;
            if ((temp_19 & 4) != 0) { func_003e05f0((u8 *)var_17 + 0x50, (u8 *)var_17 + 0x10, var_17->value + 0x50); *flagptr &= ~4; }
            var_21 = var_17->child;
            if (var_21 != NULL) {
                do {
                    temp_20 = temp_19 | var_21->flags; flagptr = &var_21->flags;
                    if ((temp_20 & 4) != 0) { func_003e05f0((u8 *)var_21 + 0x50, (u8 *)var_21 + 0x10, var_21->value + 0x50); *flagptr &= ~4; }
                    func_003ed850((u8 *)var_21->child, temp_20); var_21 = var_21->sibling;
                } while (var_21 != NULL);
            }
            var_17 = var_17->sibling;
        } while (var_17 != NULL);
    }
}
