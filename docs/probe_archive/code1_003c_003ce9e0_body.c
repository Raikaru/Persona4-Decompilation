/* code1_003c_003ce9e0 probe archive
 * lane:      code1_003c (plain -O2)
 * function:  func_003ce9e0 @ 0x003ce9e0
 * status:    NOT CLOSED (reverted to INCLUDE_ASM)
 * best body: object 456B, window 464B, 54 differing 4-byte words (reloc-masked)
 * key residual offsets: 60 (outer bit-test branch target mismatch),
 *   84-96 (first loop sltu/beqz vs beqz s5 plus i/p allocation),
 *   196-260 (second loop prologue/branch/field-load allocation),
 *   268-412 (second loop sp7c/sp78/e2ab0/ce230/004220d8 schedule)
 * levers ruled out:
 *   - #pragma no_branch_likely on/off (did not fix branch forms)
 *   - #pragma schedule on/off (did not fix second loop prologue)
 *   - u32 vs s32 for counters and pointers
 *   - if (count) vs if (count != 0) vs if (count == 0U)
 *   - do { ... } while vs while loops
 *   - goto fallthrough for branch delay scheduling
 *   - &iGpffffaa9c + 8 and arg1 + iGpffffb728 pointer forms
 * not tried:
 *   - #pragma peephole off (retail may have used this for the sltu zero tests)
 *   - block-scoped declarations to force s0/s5 register reuse in second loop
 */

extern s32 func_003c9c20(u8 *arg0);
extern void func_003cc6e0(u8 *arg0);
extern s32 func_003ceeb0(u8 *arg0);
extern s32 func_003deff0(s32, s32, s32, s32, s32);
extern s32 func_003e2ab0(s32, s32, s32);
extern s32 func_003ce170(u8 *arg0);
extern void func_003ce230(u8 *arg0);
extern void func_004220d8(u8 *arg0, u8 *arg1);
extern s32 iGpffffb728;
extern s32 iGpffffaa9c;

s32 func_003ce9e0(s32 arg0, u8 *arg1) {
    u8 *v;
    u32 *arr;
    u32 count;
    u32 i;
    u32 *p;
    u32 i2;
    u32 *q;
    u8 *s0;
    u8 *s5;
    s32 sp7c;
    s32 sp78;

    v = func_003c9c20((u8 *)(u32)arg1);
    if ((*(u32 *)(v + 8) & 0x01000000) != 0) {
        arr = *(u32 **)(arg1 + iGpffffb728);
        count = *arr;
        if (count == 0U)
            goto after_first;
        i = 0;
        p = arr;
        do {
            func_003cc6e0((u8 *)p[1]);
            i++;
            p++;
        } while (i < count);
after_first:

        if (func_003deff0(arg0, 1, func_003ceeb0(arg1) - 0xC, 0x37002, 0x37) == 0)
            return 0;

        if (func_003e2ab0(arg0, (s32)(&iGpffffaa9c + 8), 4) == 0)
            return 0;

        if (*arr == 0U)
            goto end;
        i2 = 0;
        q = arr;
        do {
            s0 = (u8 *)q[1];
            s5 = s0 + 0x18;
            sp7c = *(s32 *)(s0 + 8) - (*(s32 *)(s0 + 0x20) - (s32)s0);
            if (func_003e2ab0(arg0, &sp7c, 4) == 0)
                return 0;

            sp78 = func_003ce170(s5);
            if (func_003e2ab0(arg0, &sp78, 4) == 0)
                return 0;

            if (func_003e2ab0(arg0, *(s32 *)(s5 + 8), sp7c) == 0)
                return 0;

            func_003ce230(s5);
            func_004220d8(s0, (u8 *)(s0 + *(s32 *)(s0 + 8) + 0x18));

            i2++;
            q++;
        } while (i2 < *arr);
    }
end:
    return arg0;
}
