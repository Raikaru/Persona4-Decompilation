/* Coherent source-contract candidate; production remains ASM.
 * Current-owner replay: 772/768 bytes, nd341 (337 differing in-window bytes
 * plus four overrun bytes), 22 relocations. Historical 768/768 nd39 used
 * unsupported f32-array/s64/I64 views and is not evidence for this body.
 * The real local objects are a Vec2f and four resource pointers. The retail
 * frame is 0x80; no explicit source padding or enlarged object is supplied.
 * Callback slot zero is reloaded for all eight render-state calls. The last
 * five draw iterations reload resource[0] and the input record's bytes.
 *
 * Required coherent owner migration, not shadow declarations:
 * - Reuse Vec2f. Change 00116190/001162f0/001163e0/00116610/00116820 to
 *   void(Vec2f, f32, s32, u8 *, u8 **). Change 00116d40 to
 *   void(Vec2f, s32, u8, u8, s16, u8 *, f32); remove unused I64.
 * - In the four existing C definitions, use Vec2f arg0 and u8 **arg3;
 *   replace incoming-pair pointer reads with arg0.x/y. Explicitly cast
 *   resource loads to s32 only where existing downstream APIs hold addresses
 *   as integers. Preserve every existing snapshot and call order.
 * - Move u8 *func_0046a770(char *) before all uses and remove its old s32
 *   declaration. Cast the four stored lookup results in 001175e0 and the
 *   result in 0011b6d0 to s32; this body stores pointers without a cast.
 * - Use extern s32 (*D_00887300[])(s32, void *), the real render-state ABI.
 *   Retain the separate literal-only func_003f6440(s32,s32) calls.
 * - Keep this function's existing Vec2f declaration and 00115c40 call.
 *   00119e10, 00116820 and 00116d40 remain ASM; do not migrate generated
 *   archaeology as though it were an active owner. Keep the unrelated
 *   private 001171c0 boundary unchanged in this experiment.
 *
 * Coupled measurements: 00116190 is344/352 nd52; 001162f0 is232/240 nd32;
 * 001163e0 is552/560 nd0; 00116610 is524/528 nd0. Thus even the family
 * migration cannot be promoted independently without regressing neighbors.
 * The actual record initializer establishes0x80 bytes; no larger input
 * allocation or global alias-cleanliness claim follows from this candidate.
 */
#pragma push
#pragma opt_loop_invariants on
void func_00115e90(Vec2f arg0, s32 arg1, s16 *arg2, f32 farg3)
{
    u32 *base;
    f32 y;
    Vec2f position;
    u8 *resources[4];
    s32 i;

    y = arg0.y;
    resources[0] = func_0046a770(D_005E5810);
    resources[1] = func_0046a770(D_005E5830);
    resources[2] = func_0046a770(D_005E5850);
    resources[3] = func_0046a770(D_005E57F0);
    base = (u32 *)D_00887300;
    ((s32 (**)(s32, void *))base)[0](6, (void *)0);
    ((s32 (**)(s32, void *))base)[0](7, (void *)2);
    ((s32 (**)(s32, void *))base)[0](8, (void *)0);
    ((s32 (**)(s32, void *))base)[0](9, (void *)2);
    ((s32 (**)(s32, void *))base)[0](0xC, (void *)1);
    ((s32 (**)(s32, void *))base)[0](0xB, (void *)6);
    ((s32 (**)(s32, void *))base)[0](0xA, (void *)5);
    ((s32 (**)(s32, void *))base)[0](2, (void *)4);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    position.x = arg0.x;
    position.y = 43.0f + y;
    func_00116190(position, farg3, arg1, (u8 *)arg2 + 8, resources);
    position.x = arg0.x - 23.0f;
    position.y = 76.0f + y;
    func_00116610(position, farg3, arg1, (u8 *)arg2 + 8, resources);
    func_001162f0(position, farg3, arg1, (u8 *)arg2 + 8, resources);
    func_001163e0(position, farg3, arg1, (u8 *)arg2 + 8, resources);
    position.x = 305.0f + arg0.x;
    position.y = 139.0f + y;
    func_00116820(position, farg3, arg1, (u8 *)arg2 + 8, resources);
    i = 0;
    while (i < 5) {
        position.x = 88.0f + arg0.x;
        position.y = 203.0f + y + (f32)(i * 19);
        func_00116d40(position, arg1, *((u8 *)arg2 + i + 0xF),
                     *((u8 *)arg2 + i + 0x14), 0, resources[0], 0.0f);
        i++;
    }
}
#pragma pop
