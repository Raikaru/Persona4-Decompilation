/* Main 2026-09-02: object 472B / window 480B / nd13 (4 words). The saved-register rotation
   (retail obj=$s1, colour=$s0, n reusing $s0) is NOT declaration/scope order: the colour is a
   CALL RESULT used directly as the first argument of func_00275820 and parked across the inner
   func_002e48a0 call - a parked temp takes the lowest saved register, below the declared obj.
   Remaining: the last call's pointer chain interleaves with the 64000.0f lui/mtc1 (retail
   chains lw v0/v0/a0 then lui; b210 lw v0/v1, lui v0, mtc1, lw a0) - block-scope
   prototypes, a chain local, propagation off (blows up), schedule off, s32 chain, named f32
   all leave it. */
// FUN_0032C480
void func_0032c480(u8 *arg0)
{
    FclVec2 sp38;

    {
        u8 *obj;
        s32 n;
        extern u8 *func_002e48a0(s8 arg0, s16 arg1);

        obj = *(u8 **)(arg0 + 0x38);
        {
            extern int func_00275820(s32, s32, s32, s32, s32, s32, u8 *, s32, f32, f32, f32);
            func_00275820(func_002b2a30(0, 0, 0, 0xFF), 0, 2, iGpffffb440 + (*(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2)) * 0x11, 0, 0, D_00796310, 0x15, 140.0f, 101.0f, 1.0f);
        }
        n = (s16)((func_00109280(*(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2)) & 0xFF) + 0x1B);
        func_002b2970(&sp38, 54.0f, 103.0f);
        func_00330e50(n, *(s64 *)&sp38, 1.0f, 0xFF000000, 0xFF, 1, 1.0f, 1.0f, D_00796310);
        n = (s16)func_00331640();
        {
            extern s32 func_00279350(f32, f32, f32, s32, s32, s32, s32, s32, s32, u8 *);
            func_00279350(54.0f, 138.0f, 1.0f, -1, 1, 0, 1, n, *(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2), D_00796370);
        }
        func_0034a640(*(s32 *)(obj + 0x254), *(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2), 1);
        *(s8 *)(func_0034a630((u8 *)*(s32 *)(obj + 0x254)) + 1) = 0;
        func_0011d1d0(*(u8 **)(*(u8 **)(*(u8 **)(obj + 0x148) + 0x38) + 4), 64000.0f);
    }
}
