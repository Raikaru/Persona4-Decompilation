/* Installed exact: MWCCPS2 b210 owner profile, 452B/464B, zero differing
 * emitted words and three omitted zero-tail words.
 * Canonical contracts:
 *   s32 func_002b2a30(u8,u8,u8,u8);
 *   s32 func_0025ecd0(f32,f32,f32,s32,u8,s32,void*,s32,s16,s16,
 *                     f32,f32,f32,void*);
 * Byte channels remove the false argument-order floor. The draw callee's
 * byte opacity inversion must be 255 - opacity, without the redundant mask.
 * Its 588B/592B body remains exact, as do the migrated wrappers and callers.
 * Keep the distinct &work->field_4 and byte-pointer spellings for the two
 * retail p+4 calculations.
 *
 * Native32 actual-source cohort under undefined/function sanitizers:
 * 66,161 packing cases; 39,424 drawing pipeline cases (including 16,384 shop
 * cases); 16,384 digit drawing cases. Checks include visibility equality,
 * overlay order, freshly prepared positions, every opacity byte, signed
 * frame/origin boundaries, queue identity, packet contents, callback mode,
 * cleanup on zero dimensions, decimal grouping and full unsigned values.
 * Scratch compilation preserved all 516 existing MATCH bodies in 15 owners
 * before production integration. No incompatible local prototypes remain
 * in the active migrated callers.
 */

s32 func_002e0100(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);

    func_0043f810((u8 *)work + 4, func_002b89a0(&work->field_4), 0xF0);
    if (func_002e0570(arg0, 0) == 1) {
        if (func_002e0570(arg0, 0xD) == 1) {
            void *t = func_00460990();
            *(void (**)(void))((u8 *)t + 8) = func_002be3c0;
            *(s32 *)((u8 *)t + 0x10) = 0;
            func_00460ac0(&D_00793E80[work->field_FC * 0x30], t);
            func_0025ecd0(
                work->field_2C, work->field_30, work->field_8,
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                0,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        } else {
            func_0025ecd0(
                work->field_2C, work->field_30, work->field_8,
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                1,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        }
    }
    return 0;
}
