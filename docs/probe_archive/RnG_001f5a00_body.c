/* func_001f5a00 final candidate: object 452B, retail window 464B, normalized_diff 0 words under verify.py.
   Differing non-padding word offsets: none (fndiff reports 3 absent zero-tail padding words).
   Classification: switch case 1/default loop shape, saved-register coloring via i/result
   declaration order, direct repeated u16 limit expression, and fallback global/index load order.
   Ruled out: direct early-goto layouts, natural while/for variants without switch dispatch,
   nested positive/negative equality forms, explicit call labels, opt_rebuildconditionals off
   (scoped), and offset-local forms (frame/register regression). Added references are existing
   placeable functions/globals only; no string, float-pool, or jump-table data reference.
*/
void func_001f5a00(s32 arg0)
{
    extern s32 func_001b1540(void);
    extern s32 func_001b1550(void);
    extern s32 func_001b0e30(s32 arg0);
    s32 i;
    s32 result;
    u8 *current;
    u8 *global;

    result = 0;
    i = 0;
    while (((i & 0xFFFF) <= 0) && (result == 0)) {
        if ((*(u16 *)(iGpffffb3ac + 0xA48) &
             ((1 << (i & 0xFFFF)) & 0xFFFF)) != 0) {
            switch (((1 << (i & 0xFFFF)) & 0xFFFF)) {
            case 1:
                current = (u8 *)func_001b1540();
                if ((current != NULL) &&
                    ((*(u16 *)(current + 0x1A) & 1) != 0) &&
                    (arg0 != 0) &&
                    (*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) == 0)) {
                    *(u16 *)(iGpffffb3ac + ((i & 0xFFFF) * 4) + 0xA44) =
                        (u16)(*(u16 *)(iGpffffb3ac +
                                       ((i & 0xFFFF) * 4) + 0xA44) + 1);
                    if ((arg0 != 0) &&
                        (*(u16 *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA46) >= 4) &&
                        (*(u16 *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA44) ==
                         (*(u16 *)(iGpffffb3ac +
                                   ((i & 0xFFFF) * 4) + 0xA46) >> 1))) {
                        func_001f56d0(
                            *(s32 *)(iGpffffb3ac + 0x170), 4, 0, 0, 4);
                    } else {
                        global = iGpffffb3ac;
                        if ((*(u16 *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA44) >=
                             *(u16 *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA46)) &&
                            (func_00232710(
                                 *(s32 *)(*(u8 **)(*(u8 **)(global + 0x170) +
                                                   0x30) + 0xA64),
                                 0x180010) == 0) &&
                            (func_001b1550() == 0)) {
                            *(u16 *)(*(u8 **)(iGpffffb3ac + 0x170) + 0x16) =
                                0x1C;
                            func_001b0e30(
                                *(s32 *)(iGpffffb3ac + 0x170));
                            result = 1;
                            *(u16 *)(iGpffffb3ac + 0xA48) =
                                (u16)(*(u16 *)(iGpffffb3ac + 0xA48) &
                                      0xFFFE);
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
        i = (i + 1) & 0xFFFF;
    }
}
