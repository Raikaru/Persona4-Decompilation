/* Current action transition floor: 492B/496B, 42 differing bytes in 36
 * emitted words; nine relocations resolved and four zero-tail bytes.
 * The former 37-word fndiff score included that tail, not another instruction.
 * Natural u16 induction and pointer identity retain the same instruction floor.
 * Retail scan allocation: found=v1, base=v0, i=a3; first scaled offset=a2,
 * first entry=a0, second entry=a2. Production remains ASM.
 * IDA: docs/ida_headstart/src/promoted/code1_001b.c:59-121.
 * Uses the owner's existing unsigned offset-first helper and declarations.
 * All 104 existing owner C matches and relocation lists remain intact.
 *
 * Native32 UB-trap smoke: 16,896 deferral, genus, table-precedence, pointer
 * reload and final-flag cases. Real bad-status/death/final-flag operations
 * run behind trace hooks; reset, camera and destruction are instrumented.
 * No resource-destruction or callback-table ABI claim.
 * 0xFFF7FFFF clears other bad-status bits, retaining death bit 0x80000.
 *
 * Before promotion, reconcile pre-existing owner/provider declarations:
 * 002326f0 is u32(int,u32), not void(s32,s32); 002428f0 returns u32, not s32.
 * Canonical-return probes retain this floor. No private prototype workaround.
 */

#pragma push
#pragma opt_common_subs off
void func_001b05d0(u8 *arg0)
{
    u8 *p;
    u8 *temp;
    u8 *base;
    u8 *found;
    u16 i;
    s32 offset;
    u8 status;

    if (*(u16 *)(arg0 + 0x1A) & 1) {
        p = *(u8 **)(arg0 + 0x30);
        if (*(u16 *)(p + 0xA0) != 0) {
            return;
        }
        status = *(u8 *)(p + 0xA2);
        switch (status) {
        case 0:
            if (*(u16 *)(arg0 + 0x18) & 0x20) {
                found = NULL;
                i = 0;
                base = (u8 *)iGpffffb3ac;
                while (i < 4U) {
                    offset = i * 4;
                    temp = *(u8 **)(base + offset + 0xC74);
                    if (temp != NULL) {
                        if (*(DatUnit **)(temp + 4) ==
                            *(DatUnit **)(p + 0xA64)) {
                            found = *(u8 **)(func_001bf3a0_add(offset, base) + 0xC74);
                            break;
                        }
                    }
                    i++;
                }
                if (found == NULL) {
                    i = 0;
                    while (i < 3U) {
                        offset = i * 8;
                        temp = *(u8 **)(base + offset + 0xC94);
                        if (temp != NULL &&
                            *(DatUnit **)(temp + 4) == *(DatUnit **)(p + 0xA64)) {
                            found = temp;
                            break;
                        }
                        i++;
                    }
                }
                if (found != NULL) {
                    *(u16 *)(found + 0xA) &= 0xFFFE;
                }
                func_002326f0(*(s32 *)(p + 0xA64), 0xFFF7FFFF);
                func_002339d0(*(s32 *)(p + 0xA64));
            }
            break;
        case 1:
            if (func_002428f0(*(s32 *)(p + 0xA64), 0) != 0) {
                func_002318c0(*(DatUnitEc **)((u8 *)iGpffffb3ac + 0xC68),
                              *(DatUnit **)(*(u8 **)(arg0 + 0x30) + 0xA64));
            }
            break;
        }
        func_0019d550(*(u8 **)(arg0 + 0x30));
        *(u8 **)(arg0 + 0x30) = NULL;
        *(u16 *)(arg0 + 0x1A) &= 0xFFFE;
    }
    func_001b08f0(arg0);
    func_001bc800(arg0);
    *(u16 *)(arg0 + 0x1A) |= 2;
}
#pragma pop
