/* Lane C3D archive of func_003ce840 (retail window 416B) - best measured:
   normalized_diff 309, object 368/416 (ne0_nolim_ptr).
   Confirmed semantics (disassembly-verified):
     - NO call in the retail window; returns running total in $v0
       (daddu $v0,$zero,$zero before the flag branch; addu $v0,$t2,$v0 in the
       bnez delay slot at 003ce980).
     - total += e[8] - (e[0x20] - (int)e) + 8 per element; elements at
       list[i+1] because word 0 of the list is the count.
     - NEW vs dead lane C3C: 'addiu $v0,$v0,0x10' at 003ce868 adds +16 to the
       total inside the flag branch, between the gp-rel list load and its use.
     - Prologue/epilogue use SQ/LQ ($s0-$s2, frame 0x30, no $ra save); retail
       spills because element-pointer lifetimes span term sums. Retail unroll:
       p[1..6] loads, terms 1-4, p[7..8] loads, terms 5-8, i+=8 first,
       count-8 hoisted via bnez delay slot, moving pointer p += 0x20/iter;
       tail loop is indexed list[i+1] strength-reduced to t1 += 4.
   Residual: register allocation/scheduling only (no structural diff);
   every spelling tried for the sltu-at count test and spill-forcing locals
   kept temps. Pragmas schedule on / no_branch_likely on are required to
   fill delay slots (without them nd was worse and obj smaller). */
/* measured: schedule on fills branch delay slots with sq/lq and arg moves. */
#pragma schedule on
/* measured: no_branch_likely on keeps count tests plain. */
#pragma no_branch_likely on
s32 func_003ce840(u8 *arg0) {
    u8 **list;
    u8 **p;
    u8 *e;
    u32 count;
    u32 i;
    u8 **q;
    s32 total;

    total = 0;
    if (*(s32 *)(arg0 + 8) & 0x01000000) {
        total += 0x10;
        list = *(u8 ***)(arg0 + iGpffffb730);
        count = *(u32 *)list;
        if (count != 0U) {
            i = 0;
            if (count >= 9U) {
                p = list;
                do {
                    e = p[1];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    e = p[2];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    e = p[3];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    e = p[4];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    e = p[5];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    e = p[6];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    e = p[7];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    e = p[8];
                    total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                    p += 8;
                    i += 8U;
                } while (i < count - 8U);
            }
            q = list;
            while (i < count) {
                e = q[1];
                total += *(s32 *)(e + 8) - (*(s32 *)(e + 0x20) - (s32)e) + 8;
                q += 1;
                i += 1U;
            }
        }
    }
    return total;
}
/* measured: restore file defaults after the probe. */
#pragma no_branch_likely off
#pragma schedule off
