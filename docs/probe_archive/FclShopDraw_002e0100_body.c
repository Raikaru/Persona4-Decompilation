/* Shop drawing candidate; production remains ASM.
 * MWCCPS2 b210 owner profile: 452B / 464B, 37 differing masked words
 * (34 emitted differences plus three omitted zero-tail words).
 * The old declaration-order candidate replays at 45 words. Using the actual
 * func_0025ecd0 definition fixes the float/short/pointer contract:
 *   s32 func_0025ecd0(f32,f32,f32,s32,s32,s32,void*,s32,s16,s16,
 *                     f32,f32,f32,void*);
 * The measured owner also declares func_002b2a30 as s32(s32,s32,s32,s32),
 * matching its definition. These declarations must replace the owning
 * declarations coherently; do not hide them with incompatible local ones.
 * A callee's separate EE integer/FP register files do not establish the
 * lexical order of the original C parameters.
 *
 * Remaining differences: byte color arguments load before the constant
 * a0=255, and the byte opacity-to-word conversion loads a1 before the signed
 * frame/table/initial-float argument sequence. Both branches share this
 * residual. Eight-bit packed color/opacity field spellings also tie at 37
 * words and are not retained; the existing ShopWork layout is unchanged.
 * Preserve the distinct &work->field_4 and byte-pointer spellings to avoid
 * sharing the two retail p+4 address calculations. No production body or
 * declaration is changed by this archive update.
 *
 * Further contract experiment: narrowing all four func_002b2a30 parameters
 * and func_0025ecd0's opacity parameter to u8 produces 452B/464B with zero
 * emitted differences here (three zero-tail words only). The packer remains
 * exact under its narrow signature. The coherently redeclared draw callee
 * initially has three emitted differences at offsets 168/172/176: allocation
 * and evaluation order of 255 - (opacity & 255). Removing that redundant
 * byte mask closes the callee too (588B/592B, only one zero-tail word).
 * All declarations and callers still require migration before installation.
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
