/* object 124B / window 128B / normalized_diff 37 / differing word offsets 0x18,0x1C,0x20,0x24,0x28,0x2C,0x30,0x34,0x38,0x44,0x58,0x5C,0x60,0x64,0x68,0x70; ruled out typed/untyped callee declarations, scalar/array global forms, explicit absolute global, switch/if/goto shapes, result local, named pointer/declaration order, O1/O2/O3, schedule, no_branch_likely, and conditional-rebuild probes. */
s32 func_0039f0e0(u8 *arg0, s32 *arg1)
{
    extern void func_003d0fa0(void);
    extern void func_0039c000(u8 *arg0, s32 arg1, s32 arg2);
    extern s32 D_00886498[];
    u8 *p;
    s32 value;

    p = *(u8 **)(*(u8 **)(arg0 + 8) + 0x18);
    switch (*(s32 *)(p + 8) & 0x01000000) {
    case 0:
        value = *(s32 *)(p + D_00886498[0]);
        func_003d0fa0();
        func_0039c000(*(u8 **)(arg0 + 0x2C), value, *arg1);
        break;
    default:
        break;
    }
    return 1;
}
