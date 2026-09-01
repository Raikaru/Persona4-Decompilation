/* Best candidate: object 212B, window 240B, normalized_diff 158 -- still a
   real gap (~7 instructions), NOT closed, but the ALGORITHM is fully and
   confidently decoded from raw disassembly (frustum-vs-AABB test):

     *arg1 = 2 (assume fully inside);
     for each of 5 planes at D_008872E0-relative base + 0x60, stride 0x14:
       pick the box "positive vertex" component per axis using the plane's
       3 sign-flag bytes at +0x10/+0x11/+0x12: component = box[axis_lo] if
       flag==1, box[axis_hi] if flag==0, where box_lo/box_hi are two Vec3
       corners at arg0+0x60 and arg0+0x6C (stride 12, one flag-scaled
       (1-flag)*12 offset picks between them);
       dot = plane.x*bx + plane.y*by + plane.z*bz - plane.d, via the
       mula.s/madda.s/madd.s accumulator chain (same family documented
       elsewhere: b210 seeds the accumulator with the middle term);
       if dot > 0, *arg1 = 1 and return early (box is outside this plane).
     if all 5 planes pass, *arg1 stays 2.

   Every load/store/branch in the raw disassembly maps cleanly onto this
   description; both the corner-selection arithmetic and the dot-product
   accumulator chain read as a textbook frustum culling test.

   The remaining gap: the object is undersized by ~28 bytes even after
   fixing the base pointer to *(u8 **)(D_008872E0 + iGpffffb934) + 0x60
   (established campaign convention for dereferencing a pointer stored in
   this byte array, confirmed by usage elsewhere in code1_003c.c) rather
   than treating D_008872E0 as a fixed array address. Retail also carries a
   redundant top-of-loop `li v1,6; beqz v1,...` check before the real
   do-while, tried as while/for/guarded-do-while (best nd 156, still
   heavily undersized). The 3-index (1-flag)*12 computation is
   hand-unrolled by retail into a much longer chain of register-reused
   shift/add ((1-flag)*2 + (1-flag), then <<2) rather than a plain
   multiply; not yet tried as a matching hand-unrolled C expression.
   Next lead for a future attempt: write the index arithmetic as
   `t = 1 - flag; idx = (t + t + t) << 2;` matching retail's exact
   operation count instead of `(1-flag)*12`, and retry both loop shapes
   against that. */
void func_003d3ae0(u8 *arg0, s32 *arg1)
{
    u8 *plane;
    s32 count;
    f32 bx, by, bz;
    f32 dot;

    *arg1 = 2;
    plane = *(u8 **)(D_008872E0 + iGpffffb934) + 0x60;
    count = 5;
    do {
        bx = *(f32 *)(arg0 + 0x60 + (1 - *(u8 *)(plane + 0x10)) * 12);
        by = *(f32 *)(arg0 + 0x64 + (1 - *(u8 *)(plane + 0x11)) * 12);
        bz = *(f32 *)(arg0 + 0x68 + (1 - *(u8 *)(plane + 0x12)) * 12);
        dot = *(f32 *)plane * bx + *(f32 *)(plane + 4) * by + *(f32 *)(plane + 8) * bz
            - *(f32 *)(plane + 0xc);
        if (dot > 0.0f) {
            *arg1 = 1;
            return;
        }
        plane += 0x14;
        count -= 1;
    } while (count != 0);
}
