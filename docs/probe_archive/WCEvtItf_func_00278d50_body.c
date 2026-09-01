/* Verbatim candidate body archived before un-parking. */
void func_00278d50(u8 *arg0)
{
    u8 *base;

    if (*(u8 *)(arg0 + 0x1C) == 0) {
        base = arg0 + 0x20;
        func_00278c60((int *)base, (int)base, arg0 + *(s32 *)(arg0 + 0x10), *(s32 *)(arg0 + 0x14));
        *(u8 *)(arg0 + 0x1C) = 1;
    }
}

/* Measurements: verify normalized_diff 58; tools/fndiff.py differing-word count 19;
   object 84 B versus retail window 80 B. The candidate frame is -0x20 while
   retail is -0x10: MWCC saves arg0 in $s0 across func_00278c60, while retail
   keeps it in caller-saved $t3. This is an oversized spill and is NOT a valid
   park under the verify normalized_diff <=25 threshold.

   Full fndiff residual row offsets (reloc-masked output):
   0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 44, 52, 56, 60, 64, 68, 72, 76, 80.
   Exact residual instruction pairs are preserved in
   build/WCEvtItf_itfMesManager_78d50_nd19_body_fndiff.txt.
*/
