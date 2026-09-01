/* object=480 window=480 normalized_diff=18 differing_offsets=[46,48,50,51,54,55,58,59,70,72,74,75,78,79,82,83] instruction_deficit=0 surplus=0 classification=register-colouring (four global ld/sd destinations v1 vs retail a0; slti destination v1 vs retail at); ruled_out=floors movz/movn,COP1 accumulator,standalone MMI,framed tail-jump,sd-vs-sq; prologue_saved_s=4 ($s3,$s2,$s1,$s0); params=(u8*,u16,s64) interleaved; declarations=callee prototypes block-scope, globals file-scope arrays */
// FUN_0034A640
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
    *(s64 *)&sp50 = *(s64 *)D_0064A6E0;
    *(f32 *)((u8 *)&sp50 + 8) = *(f32 *)D_0064A6E8;
    *(s64 *)&sp60 = *(s64 *)D_0064A6F0;
    *(f32 *)((u8 *)&sp60 + 8) = *(f32 *)D_0064A6F8;

    if (((*(u16 *)(obj + 8) != (u16)arg1) ||
         (*(s8 *)(obj + 0x28) != (s8)arg2) ||
         (*(s8 *)(obj + 0) == 0)) &&
        ((u16)arg1 != 0) &&
        ((s8)arg2 < 2))
    {
        if ((*(s8 *)(obj + 0) > 0) && (*(s8 *)(obj + 0) < 3))
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
