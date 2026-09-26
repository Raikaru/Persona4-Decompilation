/* func_0048a980 (code1_0048.c) 2026-09-25: natural matrix-to-quaternion
   rewrite (2D row pointer, u8 i/j/k with (i + 1) % 3, sqrtf intrinsic).
   584B object / 592B window, 16 differing words (reloc-masked) against the
   guarded draft's 5.  Same FPR wall as the draft: retail keeps the else
   branch's 1.0f in $f1 (reused for q[i] = 1.0f) and the root in $f2; this
   body gives the constant $f3 and the root $f1.  The other 11 words are the
   m[j][j]-before-m[i][i] load order in the else branch.
   Measured and inert (16): the root in its own statement, the sum in `trace`,
   1.0f added first, multiply by 2.0f after the sqrt, and opt_lifetimes /
   dead_assignments / loop_invariants / schedule off / strength_reduction.
   Worse: a named `one` local (25 function-wide, 73 in the else branch),
   (m[j][j] + m[k][k]) grouped (29), opt_propagation off (77),
   opt_common_subs off (194).
   Diagnostic: with q[i] storing anything but the 1.0f, the root takes $f1
   in both builds - the colour depends only on whether the constant is
   allocated before or after the root. */
void func_0048a980(f32 *arg0)
{
    extern f32 sqrtf(f32 arg0);
    f32 (*m)[4] = (f32 (*)[4])arg0;
    f32 q[4];
    f32 trace;
    f32 s;
    u8 i;
    u8 j;
    u8 k;

    trace = m[0][0] + m[1][1] + m[2][2] + 1.0f;
    if (trace >= 1.0f) {
        s = 2.0f * sqrtf(trace);
        q[3] = -(s / 4.0f);
        q[0] = (m[1][2] - m[2][1]) / s;
        q[1] = (m[2][0] - m[0][2]) / s;
        q[2] = (m[0][1] - m[1][0]) / s;
    } else {
        i = (m[0][0] > m[1][1]) ? 0 : 1;
        if (m[2][2] > m[i][i]) {
            i = 2;
        }
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        s = 2.0f * sqrtf(m[i][i] - m[j][j] - m[k][k] + 1.0f);
        if (s != 0.0f) {
            q[i] = s / 4.0f;
            q[j] = (m[i][j] + m[j][i]) / s;
            q[k] = (m[i][k] + m[k][i]) / s;
            q[3] = -((m[j][k] - m[k][j]) / s);
        } else {
            q[i] = 1.0f;
            q[j] = 0.0f;
            q[k] = 0.0f;
            q[3] = 0.0f;
        }
    }
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(q) : "$vf10", "memory");
}
