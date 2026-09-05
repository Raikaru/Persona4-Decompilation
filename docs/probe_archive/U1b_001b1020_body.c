/* Recovered from the interrupted U1b draft.
 * MWCCPS2 b210: object 408B / window 416B / differing words 19.
 * The scan, clamp and branch layout match; second-phase register allocation
 * differs: one/bound use t2/t1 rather than retail a1/a0, shifting pair and
 * score temporaries. The final 8 retail bytes are zero tail padding.
 * Preserve unsigned count-1 (including the retail empty-list underflow),
 * low-byte helper results, descending stable swaps and per-pass base reloads.
 * Canonical helper declarations below agree with the owning datCalc unit.
 * Scope, flag/score widths, register hints and opt_lifetimes did not improve
 * 19 words. Automatic invariant hoisting without one/bound scored 43.
 * Paired pointer-value and paired byte-score structs also retain 19 words;
 * neither changes the second-phase allocation. Keep the simpler scalar body.
 * This is a reproducible candidate, not an exact match; production stays ASM.
 */
extern u8 func_00232c70(u8 *, s32);
extern u32 func_00231d70(u32);
#pragma push
/* measured: opt_propagation off retains the scan and sort instruction layout. */
#pragma opt_propagation off
void func_001b1020(s32 arg0)
{
    u8 **scan;
    u32 i;
    u8 *obj;
    u8 *p;
    u8 sp50[12];
    u32 temp;
    u32 val;

    scan = (u8 **)(D_0076449C + 0x29C);
    for (i = 0; i < 0xCU; i++) {
        obj = *scan;
        if (obj == NULL) {
            break;
        }
        if (arg0 != 0) {
            p = *(u8 **)(obj + 0x30);
            if (*(u8 *)(p + 0xA2) == 1) {
                temp = (u32)func_00232c70(*(u8 **)(p + 0xA64), 3) & 0xFF;
                val = (u32)(temp * (func_00231d70(0x15) + 0x5A)) / 100U;
                if (val == 0) {
                    val = 1;
                } else if (val > 0x63U) {
                    val = 0x63;
                }
                sp50[i] = (u8)val;
                goto next_i;
            }
        }
        p = *(u8 **)(obj + 0x30);
        sp50[i] = (u8)func_00232c70(*(u8 **)(p + 0xA64), 3);
    next_i:
        scan++;
    }
    {
        s32 swapped;
        u8 **ptr;
        u32 j;
        u8 *p0;
        u8 *p1;
        u8 *cur;
        u8 *next;
        u8 left;
        u8 right;
        s32 one;
        u32 bound;

        one = 1;
        bound = i - 1;
        do {
            swapped = 0;
            ptr = (u8 **)(D_0076449C + 0x29C);
            j = 0;
            while (j < bound) {
                p0 = *ptr;
                p1 = *(ptr + 1);
                if ((p0 != NULL) && (p1 != NULL)) {
                    cur = &sp50[j];
                    left = *cur;
                    next = cur + 1;
                    right = *next;
                    if ((s32)left < (s32)right) {
                        *ptr = p1;
                        *(ptr + 1) = p0;
                        *cur = right;
                        *next = left;
                        swapped = one;
                    }
                }
                j++;
                ptr += 1;
            }
        } while (swapped != 0);
    }
}
/* measured: restore opt_propagation after func_001b1020. */
#pragma opt_propagation on
#pragma pop
