/* func_001b1020 lane U1b draft (2026-09-03, lane killed mid-edit): does not compile as left (missing block brace);
   shape: scan loop filling sp50[12] percentages, then bubble sort of the 0x29C pointer table by sp50. Untested. */
#pragma push
/* measured: opt_propagation off preserves the retail one/bound locals and second-loop register coloring. */
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
                } else if (val >= 0x64U) {
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
        u32 bound;
        s32 one;
        s32 swapped;
        u8 **ptr;
        u32 j;
        u8 *p0;
        u8 *p1;
        u8 *cur;
        u8 *next;
        u8 left;
        u8 right;

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
                    next = cur + 1;
                    left = *cur;
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
