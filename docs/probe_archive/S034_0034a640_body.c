/* object=480 window=480 normalized_diff=0; final MATCH.
 * Register-colouring closure: a scalar Pair-copy macro under measured
 * opt_propagation off emits each global qword into $a0, and <= 2 spells the
 * retail slti $at,$v1,3 branch. The prior direct scalar loads used $v1.
 */
#define COPY_SCALAR_PAIR_0034(dst, src) \
 do { \
     s64 copy_s64; \
     f32 copy_f32; \
     copy_s64 = (src).whole; \
     copy_f32 = (src).tail; \
     (dst).whole = copy_s64; \
     (dst).tail = copy_f32; \
 } while (0)
// FUN_0034A640
/* measured: opt_propagation off preserves scalar Pair-copy source order. */
#pragma push
#pragma opt_propagation off
void func_0034a640(u8 *arg0, u16 arg1, s64 arg2)
{
    extern void func_004787e0(void *arg0);
    extern void func_00104a00(void *arg0);
    extern u8 *func_00104900(s8 arg0);
    extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern void func_003e0c90(void *arg0, void *arg1, s32 arg2);
    extern void func_00452080(void *arg0);
    extern u8 *func_003488d0(void *arg0, void *arg1, s32 arg2);
    extern u8 D_0064A700[];
    extern u8 D_0064A720[];
    extern s32 iGpffffb5a0;
    typedef struct {
        s64 whole;
        f32 tail;
    } Pair;
    u8 *obj;
    Pair sp50;
    Pair sp60;
    obj = *(u8 **)(arg0 + 0x38);
    COPY_SCALAR_PAIR_0034(sp50, *(Pair *)D_0064A6E0);
    COPY_SCALAR_PAIR_0034(sp60, *(Pair *)D_0064A6F0);

    if (((*(u16 *)(obj + 8) != (u16)arg1) ||
         (*(s8 *)(obj + 0x28) != (s8)arg2) ||
         (*(s8 *)(obj + 0) == 0)) &&
        ((u16)arg1 != 0) &&
        ((s8)arg2 < 2))
    {
        if ((*(s8 *)(obj + 0) > 0) && (*(s8 *)(obj + 0) <= 2))
            return;
        if (*(u8 **)(obj + 0xC) != NULL) {
            func_004787e0(*(u8 **)(obj + 0xC));
            *(u8 **)(obj + 0xC) = NULL;
        }
        if (*(u8 **)(obj + 0x14) != NULL) {
            func_00104a00(*(u8 **)(obj + 0x14));
            *(u8 **)(obj + 0x14) = NULL;
        }
        *(u16 *)(obj + 8) = arg1;
        *(s8 *)(obj + 0) = 1;
        *(s8 *)(obj + 0x28) = arg2;
        *(s8 *)(obj + 6) = 0;
        *(u8 **)(obj + 0x14) = func_00104900(*(s8 *)(obj + 0x28));
        *(s32 *)(obj + 0x10) = *(s32 *)(*(u8 **)(obj + 0x14) + 8);
        func_003e0870(obj + 0x30, &sp60, 0, 180.0f);
        func_003e0c90(obj + 0x30, &sp50, 2);
        iGpffffb5a0 = 0;
        if (*(s8 *)(obj + 0x28) == 0) {
            if (*(u8 **)(obj + 0xEC) != NULL) {
                func_00452080(*(u8 **)(obj + 0xEC));
                *(u8 **)(obj + 0xEC) = NULL;
            }
            *(u8 **)(obj + 0xEC) = func_003488d0(arg0, D_0064A700, 0);
            if (*(u8 **)(obj + 0xF0) != NULL) {
                func_00452080(*(u8 **)(obj + 0xF0));
                *(u8 **)(obj + 0xF0) = NULL;
            }
            *(u8 **)(obj + 0xF0) = func_003488d0(arg0, D_0064A720, 7);
        }
    }
}
#undef COPY_SCALAR_PAIR_0034
/* measured: restore pragma state after func_0034a640 probe. */
#pragma pop
