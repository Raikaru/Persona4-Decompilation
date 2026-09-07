/* NOT MATCHING: candidate432 executable bytes versus retail428 +4 alignment.
 * All16 relocations resolve. One extra daddu a0,s0,zero at+0x2C causes96
 * positional executable differences (86 masked words). Removing that word
 * only for alignment analysis leaves zero differences; production stays ASM.
 * Shared NULL join and opt_common_subs off close the old CFG/address floor.
 * Date-wrapper inline/on still scores86 at432B; moving updates into an
 * inline/off body under outer CSE/on gives416B/56, so neither closes it.
 * Requires cmmMisc.c globals, helpers and existing cmmMiscAddOff. */
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
#pragma opt_common_subs on
