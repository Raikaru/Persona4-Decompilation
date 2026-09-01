/* object 148 bytes, retail window 176 bytes, normalized_diff 97.
   Typed self/result reconstruction with schedule and no_branch_likely; explicit
   branch calls reduced the residual versus the shared callback-pointer form
   (obj 152B, nd 101). Retail keeps self in s0/result in s1 and materializes a
   shared jalr dispatch in v1; MWCC keeps self in s1/result in s0 for the local
   callback form, while explicit calls split the dispatch. Declaration order,
   direct callback pointer, and callback-argument assignment order were ruled out.
   No file-scope declarations changed.
*/
u8 *func_003c8bf0(u8 *arg0, s32 arg1) {
    u8 *self;
    u8 *result;

    self = arg0;
    if (self == NULL)
        goto done;
    if (*(s32 *)(self + 4) == 0)
        goto empty;
    if (arg1 & 1)
        result = D_0070B030(self, D_0070B034);
    else
        result = func_003c8920(self, 0);
    if (result == NULL)
        goto done;
    func_003c5700(self);
    return result;
empty:
    func_003c5700(self);
    return D_0070B020;
done:
    return NULL;
}
