/* ARCHIVE: func_002e0100 reconstruction attempt
   Source: src/Event/Fcl/y_fclShopDraw.c
   Lane: FclShopDraw
   Address: 0x002e0100
   Object size: 452 bytes
   Window: 464 bytes
   normalized_diff: 132
   First differing offsets: 192, 194, 195, 196, 198, 200, 202, 204, 206, 207,
                            216, 218, 219, 220, 222, 223, ...
   Differing words (reloc-masked): 45
   Status: MISMATCH

   Levers / source variants tried:
   - Field-spelling `&work->field_4` for func_002b89a0 + `(u8 *)work + 4` for
     func_0043f810 to break p+4 CSE (two addiu a0,s0,4 are produced, nd 132).
   - `func_0025ecd0` declared as `7 x s32, 6 x f32, void *` with the pointer
     last (the current file's "fixed" declaration).  nd 132.
   - `func_0025ecd0` declared as `7 x s32, void *, 6 x f32` with the pointer
     in position 8 (the "old" declaration).  nd 215; strictly worse.
   - `#pragma opt_propagation off` and `#pragma opt_common_subs off` scoped
     around the function.  No improvement; nd 132.

   Residual mismatch families:
   - func_002b2a30 constant-first argument order: retail emits
     `addiu a0, zero, 0xff` before the `lbu a1/a2/a3` color loads, while
     b210 emits the lbu loads first.
   - func_0025ecd0 14-argument materialisation order: retail loads
     [3 (field_F8), 8 (base pointer), f12-f14, 1 (color), 2 (field_62),
      4 (field_F4), 5 (flag), 6 (field_100), 7 (field_102), f15-f17],
     while b210 emits a different GPR/FPR interleaving.

   This matches the documented "argument-evaluation-order scheduling floor"
   noted in y_fclItemShopDraw.c (func_0033cc40, nd 40) and
   promoted/y_draw.c (func_002b7cd0, nd 133).  The file's own existing note
   records a previous best of nd 65 for this function with the same two
   residual families.
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
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                work->field_F4,
                0,
                work->field_100,
                work->field_102,
                work->field_2C,
                work->field_30,
                work->field_8,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        } else {
            func_0025ecd0(
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                work->field_F4,
                1,
                work->field_100,
                work->field_102,
                work->field_2C,
                work->field_30,
                work->field_8,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        }
    }
    return 0;
}
