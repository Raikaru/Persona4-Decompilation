/* TRSL 2026-08-14: object 604B / window 608B / normalized_diff 84; differing offsets 124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,220,224,232,244,248,256,264,272,284,288,300,304,352,356,360,376,388,408,420,424,432,436,540; deficit 1 instruction; classification register-coloring + constant-hoist floor; ruled out correct ABI order, u8 extraction fields, signed buffers, shared-loop switch, split formatting index, unsigned shifts, pointer aliases, and constant locals. */
void func_0021ed10(u8 *arg0, f32 *arg1, s32 arg2, u32 arg3, s32 arg4)
{
    s8 buf[0x40];
    s8 rev[0x40];
    u8 hi;
    u8 mid;
    u8 lo;
    u8 ch;
    s32 i;
    s32 j;
    s32 k;
    s32 digit;
    s32 n;
    s32 tmp;

    hi = (u8)((arg2 & 0xFF000000) >> 24);
    mid = (u8)((u32)(arg2 & 0xFF0000) >> 16);
    lo = (u8)((u32)(arg2 & 0xFF00) >> 8);
    ch = (u8)arg2;
    if (ch != 0) {
        if (arg3 >= 1000 && arg4 != 0) {
            k = 0;
            j = 0;
            do {
                buf[k] = (u8)((arg3 % 10) + 0x30);
                k += 1;
                arg3 /= 10;
                if (arg3 != 0 && j == 2) {
                    buf[k] = 0x2E;
                    k += 1;
                }
                j += 1;
                if (j >= 3) {
                    j = 0;
                }
            } while (arg3 != 0);
            n = 0;
            while (n < k) {
                tmp = n + 1;
                rev[n] = buf[k - tmp];
                n = tmp;
            }
            rev[n] = 0;
        } else {
            func_00442088(rev, &iGpffffa5b4, arg3);
        }
        i = 0;
        while (rev[i] != 0) {
            switch (rev[i]) {
            case 0x2E:
                func_0034f2e0(*(void **)(arg0 + 0x4A0),
                              arg1[0], arg1[1], hi, mid, lo, ch);
                arg1[0] += 8.0f;
                break;
            default:
                digit = rev[i] - 0x30;
                if (digit < 0 || digit >= 10) {
                    func_0046d730(&D_00629610, 0x119);
                }
                func_0034f2e0(
                    *(void **)(arg0 + digit * 4 + 0x478),
                    arg1[0], arg1[1], hi, mid, lo, ch);
                arg1[0] += 22.0f;
                break;
            }
            i += 1;
        }
    }
}
