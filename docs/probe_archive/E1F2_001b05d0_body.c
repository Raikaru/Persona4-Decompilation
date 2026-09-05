/* func_001b05d0 best nonmatching probe: object 492B, retail window 496B, 37 differing words (relocation masked). */
/* Retail saved registers: $s1=arg0, $s0=p=*(arg0+0x30). */
/* Retail caller-saved loop registers: found=$v1, base=$v0, i=$a3; first-loop index=$a0, scaled offset=$a2, entry=$a0; second-loop entry=$a2. */
/* Tried: direct C reconstruction; narrow/s32/u16 counter forms; split and compact scaled offsets; pointer and integer found/base; declaration permutations; while/goto loops; nested versus flat conditions; global/base cache forms; opt_propagation and opt_common_subs pragma scopes; comma and integer offset-first reload expressions. Best retained opt_common_subs off, cached base, s32 found/i/offset, and u16 conversions. */
/* IDA: docs/ida_headstart/src/promoted/code1_001b.c:59-121 confirms the
 * two narrow counters and first-table/fallback-table selection. Its direct
 * if/else reconstruction scores 99 words, or 97 with common subexpressions
 * off. The old archive omitted that setting and replayed at 89 words;
 * the explicit scope below restores the measured 37-word floor.
 * The TU's existing offset helper also gives 37 words; an isolated private
 * inline context getter gives 96 words (496B/496B). Neither is retained.
 */

#pragma push
#pragma opt_common_subs off
void func_001b05d0(u8 *arg0)
{
    u8 *p;
    u8 *temp;
    u8 *base;
    s32 found;
    s32 i;
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
                found = 0;
                i = 0;
                base = D_0076449C;
                while ((u16)i < 4U) {
                    offset = (u16)i * 4;
                    temp = *(u8 **)(base + offset + 0xC74);
                    if (temp != NULL) {
                        if (*(s32 *)(temp + 4) ==
                            *(s32 *)(p + 0xA64)) {
                            found = *(s32 *)(offset + (s32)base + 0xC74);
                            break;
                        }
                    }
                    i = (u16)(i + 1);
                }
                if (found == 0) {
                    i = 0;
                    while ((u16)i < 3U) {
                        offset = (u16)i * 8;
                        temp = *(u8 **)(base + offset + 0xC94);
                        if (temp != NULL &&
                            *(s32 *)(temp + 4) == *(s32 *)(p + 0xA64)) {
                            found = (s32)temp;
                            break;
                        }
                        i = (u16)(i + 1);
                    }
                }
                if (found != 0) {
                    *(u16 *)((u8 *)found + 0xA) &= 0xFFFE;
                }
                func_002326f0(*(s32 *)(p + 0xA64), 0xFFF7FFFF);
                func_002339d0(*(s32 *)(p + 0xA64));
            }
            break;
        case 1:
            if (func_002428f0(*(s32 *)(p + 0xA64), 0) != 0) {
                func_002318c0(*(DatUnitEc **)(D_0076449C + 0xC68),
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
