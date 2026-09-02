/* Re-measured 2026-09-02 (Main): NOT a COP1 floor. This body is instruction-for-instruction
   retail's sequence at the exact size (344B, retail window 352B = body + 2 nops); nd217 is
   FPR colouring only. Findings: retail has scheduling OFF (unfilled `clear f0; nop; mula`
   hazard); the first block loads all eight operands before any arithmetic, which only
   `opt_propagation off` with the eight operands copied into locals reproduces (default
   propagation evaluates the MAC chain before the w product and interleaves loads); the
   chain order y,x,z comes from source order x,y,z (mwcc swaps the first two terms:
   (P+Q)+R -> mula Q, madda P, madd R); the w product must be a named local so its mul.s
   precedes the chain. Remaining: retail allocates f0 to the 0.0f constant and the eight
   locals ascending in pairs (bw f1, aw f2, by f3, ay f4, bx f5, ax f6, bz f7, az f8) while
   b210 colours them f7,f2,f6,f0,f5,f4,f3,f1 regardless of declaration order, struct
   packaging, a-only/b-only locals, or product operand order; opt_common_subs off gives a
   clean descending colouring but grows the function to 388B. */
typedef struct { u8 pad[8]; f32 x, y, z, w; f32 tx, ty, tz; } QFrame39;
#pragma opt_propagation off
// FUN_00396520
void func_00396520(QFrame39 *out, QFrame39 *a, QFrame39 *b)
{
    f32 aw, bw, ay, by, ax, bx, az, bz, ww;

    aw = a->w;
    bw = b->w;
    ay = a->y;
    by = b->y;
    ax = a->x;
    bx = b->x;
    az = a->z;
    bz = b->z;
    ww = aw * bw;
    out->w = ww - (ax * bx + ay * by + az * bz);
    out->x = a->y * b->z - a->z * b->y;
    out->y = a->z * b->x - a->x * b->z;
    out->z = a->x * b->y - a->y * b->x;
    out->x += b->x * a->w;
    out->y += b->y * a->w;
    out->z += b->z * a->w;
    out->x += a->x * b->w;
    out->y += a->y * b->w;
    out->z += a->z * b->w;
    out->tx = a->tx + b->tx;
    out->ty = a->ty + b->ty;
    out->tz = a->tz + b->tz;
}
#pragma opt_propagation on
