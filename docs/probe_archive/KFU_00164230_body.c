// func_00164230 (0x00164230-0x00164570, 832B) — guarded floor @160fndiff/800B (32B under; frame/saves agree).
// Wins: setup-dup structure; empty-then beqz null-tests; v-test positive-first (>0);
// j*3*4 index shape; u16 w + (s16)v/(s16)arg extends; e2=b+12 clear shape; s32 args (killed u16-andi pair);
// all 15 calls + GPREL/ABSOLUTE globals present; frame -128 + s0-s6 saves agree.
// Walls: arg-home rotation (s1/s2/s5 vs s4/s3/s6; i/v/w-top-inits DSE-dead so no reserve emulation;
//   use-lookahead absent in mwcc: future p/i/v/w homes not reserved); s0-reuse blocked (reinit-q split neutral);
//   v/i counter/val swap; j-temp home; li-temp (v0 vs a0); GPREL-vs-ABSOLUTE display phantoms (relocs present).
// Prior attempt (guard note, nd~128, no archive) hit the same s-rotation floor. Production stays ASM.
void func_00164230(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *p;
    s32 i;
    s32 j;
    s32 v;
    u16 w;
    u8 *e;
    u8 *b;
    u8 *e2;

    p = func_00162330();
    if (p == NULL) {
    } else {
        *(u8 **)(p + 72) = func_00231580(1);
        *(u8 **)(p + 80) = func_00162680(arg0, arg1, 1);
        *(u16 *)(p + 1832) = 1;
        *(s32 *)(p + 68) = 0;
        *(s32 *)(p + 448) = func_00109400(arg2) & 0xFF;
        *(s32 *)(p + 452) = func_00104c70(1) & 0xFF;
        *(u8 **)(p + 436) = (u8 *)func_0017d070((u8 *)0);
        *(u16 *)(p + 88) = arg2;
    }
    if (func_00162510(arg0, arg1) == 1) {
        i = 0;
        while (i < 3) {
            e = D_007F16F0 + i * 8;
            if (*(u8 **)(e + 12) == NULL) {
            } else {
                j = 0;
                while (j < 5) {
                    b = *(u8 **)(e + 12) + (j * 3) * 4;
                    *(b + 652) = *(b + 652) | 1;
                    j += 1;
                }
                b = D_007F16F0 + i * 8;
                e2 = b + 12;
                func_004787e0(*(s32 *)(b + 12));
                *(s32 *)e2 = 0;
                *(u16 *)(b + 8) = 0;
                *(u16 *)(b + 10) = 0;
            }
            i += 1;
        }
    } else {
        i = 0;
        while (i < 3) {
            v = (s16)func_00105ee0(i);
            if (v > 0) {
                p = func_00162330();
                if (p == NULL) {
                } else {
                    w = (u16)v;
                    *(u8 **)(p + 72) = func_00231580(w);
                    *(u8 **)(p + 80) = func_00162680(arg0, arg1, w);
                    *(u16 *)(p + 1832) = v;
                    *(s32 *)(p + 68) = 0;
                    *(s32 *)(p + 448) = func_00109400(v) & 0xFF;
                    if (w == 1) {
                        *(s32 *)(p + 452) = func_00104c70((s16)v) & 0xFF;
                        *(u8 **)(p + 436) = (u8 *)func_0017d070((u8 *)0);
                    } else {
                        func_00440b68((const char *)D_00763008, D_005F1500, 477);
                        *(u8 **)(p + 1840) = func_00454a60(D_005F13C0 + w * 32, 0);
                    }
                    *(u16 *)(p + 88) = arg2;
                }
            } else {
                e = D_007F16F0 + i * 8;
                if (*(u8 **)(e + 12) == NULL) {
                } else {
                    j = 0;
                    while (j < 5) {
                        b = *(u8 **)(e + 12) + (j * 3) * 4;
                        *(b + 652) = *(b + 652) | 1;
                        j += 1;
                    }
                    b = D_007F16F0 + i * 8;
                    e2 = b + 12;
                    func_004787e0(*(s32 *)(b + 12));
                    *(s32 *)e2 = 0;
                    *(u16 *)(b + 8) = 0;
                    *(u16 *)(b + 10) = 0;
                }
            }
            i += 1;
        }
    }
}
