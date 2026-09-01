/* object 348/window 352/normalized_diff 43; differing instruction offsets 0x24,0x30,0x34,0x3c,0x44,0x4c,0x50,0x54,0x58,0x5c,0x60,0x6c,0x8c,0x90,0x94,0x98,0xa0,0xa4,0xd4,0xdc,0xe0,0xf8,0x10c,0x110,0x114,0x118,0x11c,0x120; fndiff's 30th differing word is the zero 4-byte tail at 0x15c (object ends at 348B while the 352B window continues through alignment padding). Residual is saved-register allocation (retail p=$s0,bound=$s1,id2=$s2,id=$s3 vs candidate p=$s1,bound=$s3,id2=$s0,id=$s2) plus second-loop counter in $v1 vs retail $a0. Both IDA and Ghidra agree on control flow and types. Tried and ruled out W8/W9 declaration permutations, integer-pointer spelling, initialized counter, explicit bound cast, opt_propagation off, opt_loop_invariants off, and equivalent comparison reversals; no size/control-flow regressions in the retained candidate. */
void func_0030f4f0(u8 *arg0, s16 *arg1) {
    s16 i;
    s32 j;
    s64 bound;
    s32 id;
    s32 id2;
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    id = func_0010b460() & 0xFFFF;
    bound = *(s8 *)(p + 0x1A);
    if (bound == 7) {
        bound = 0xC;
    }
    i = 0;
    id2 = id & 0xFFFF;
    while (i < bound) {
        if (id2 != arg1[i]) {
            func_0010ad80(arg1[i] & 0xFFFF);
        }
        i++;
    }
    func_0010b190((u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)));
    j = 0;
    while (j < bound) {
        if (id2 == arg1[j]) {
            func_0010b300(*(u16 *)(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 1));
            func_0010ad80(id);
            break;
        }
        j = (s16)(j + 1);
    }
    func_0010b7f0();
}
