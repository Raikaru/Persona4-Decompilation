/* func_0048a980 (code1_0048.c) 2026-09-26 round 2: natural matrix-to-quaternion
   body at 5 differing words (584B object / 592B window) - the same floor as the
   guarded helper-based draft, without its code1_0048_add/mul helpers.  The
   natural body's 11 load-order words close by reading m[j][j] first into a
   local (`d = m[j][j]; d = m[i][i] - d;`).  Residual is the FP wall recorded
   in Quat_0048a980_natural_body.c: retail keeps the else branch's 1.0f in $f1
   and the root in $f2; this body gives $f3 / $f1.
   Inert (5): s = sqrtf(..); s = 2.0f * s, s *= 2.0f, d reused for the root,
   trace or s reused for d, d at function scope in all 6 orders with trace/s,
   the constant stored through d (`d = 1.0f; q[i] = d`).  Worse: a named
   `one` local (65 in every declaration order), m[j][j] held in s (27),
   `-m[j][j] + m[i][i]` (77).  permute.py: no improvement. */
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
        {
            f32 d = m[j][j];
            d = m[i][i] - d;
            s = 2.0f * sqrtf(d - m[k][k] + 1.0f);
        }
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
