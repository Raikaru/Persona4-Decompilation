/* NOT MATCHING: candidate432 executable bytes versus retail428 +4 alignment.
 * All16 relocations resolve. One extra daddu a0,s0,zero at+0x2C causes96
 * positional executable differences (86 masked words). Removing that word
 * only for alignment analysis leaves zero differences; production stays ASM.
 * Shared NULL join and opt_common_subs off close the old CFG/address floor.
 * Date-wrapper inline/on still scores86 at432B; moving updates into an
 * inline/off body under outer CSE/on gives416B/56, so neither closes it.
 * Requires cmmMisc.c globals, helpers and existing cmmMiscAddOff. */
/* Fresh canonical-owner replay, 2026-09-09: 432/432 bytes, nd262 byte
 * differences, all sixteen relocations resolved. The retained source,
 * phase-scoped selector/update locals, unsigned comparison snapshot and
 * argument-time date snapshot all tie. A true column-subobject pointer
 * instead reaches 400/432, nd161 and does not cover the retail body.
 * Production remains ASM; these are measured floors, not impossibility.
 *
 * Replay with actual provider declarations, not the owner's stale forms:
 * void func_001104d0(s32,s32*,s32*), u32 func_00106330(s32),
 * u32 func_001064f0(s32), s32 func_00110600(s32,s32),
 * u8 func_00106600(s16), void func_00106620(s32,s32), and
 * void func_0046d730(void*,s32). Deduplicate func_001064f0. Existing callers
 * require separate verification before a production declaration cutover.
 * No ignored/narrowed date parameter was invented to remove the extra copy.
 *
 * Both date outputs are real s32 objects, unconditionally written by the
 * provider and never read here. The resource has an eight-byte header and
 * runtime-counted 36-byte records, not a guessed fixed capacity. Column
 * 0/1 selects the real two-effect subobject. The assertion returns, so
 * failed eligibility/NULL selection and invalid columns are unsupported
 * paths, not invented early returns. Sum is signed byte-value plus signed
 * halfword delta; only the upper cap applies, then &255 before the setter.
 * Keep signed key reloads and the second lookup after the first setter.
 */
// FUN_002494C0
#pragma push
#pragma opt_common_subs off
s32 func_002494c0(s32 date, s32 column)
{
    s32 month;
    s32 day;
    u8 *base;
    u8 *record;
    u8 *selected;
    u16 *key;
    s32 value;
    s32 offset;
    u16 id;

    base = D_008814D0[0] + 8;
    func_001104d0(date, &month, &day);
    if (func_00106330(0xA61) == 0) goto null_record;
    record = base + func_001064f0(0x6D) * 36;
    if ((u32)date < func_00110600(record[2], record[3])) goto null_record;
    selected = record;
    goto selected_record;
null_record:
    record = NULL;
    selected = record;
selected_record:
    if (column != 0 && column != 1) func_0046d730(D_006359D0, 0x4AB);
    if (selected == NULL) func_0046d730(D_006359D0, 0x4AC);
    offset = column * 16;
    key = (u16 *)(cmmMiscAddOff(offset, (s32)selected) + 4);
    id = *key;
    if (id != 0) {
        value = func_00106600((s16)id) & 0xFF;
        value = cmmMiscAddOff(value, *(s16 *)(cmmMiscAddOff(offset, (s32)selected) + 6));
        if (value > 99) value = 99;
        func_00106620(*(s16 *)key, value & 0xFF);
    }
    key = (u16 *)(cmmMiscAddOff(offset, (s32)selected) + 8);
    id = *key;
    if (id != 0) {
        offset = column * 16;
        value = func_00106600((s16)id) & 0xFF;
        value = cmmMiscAddOff(value, *(s16 *)(cmmMiscAddOff(offset, (s32)selected) + 10));
        if (value > 99) value = 99;
        func_00106620(*(s16 *)key, value & 0xFF);
    }
    return 1;
}
#pragma pop
