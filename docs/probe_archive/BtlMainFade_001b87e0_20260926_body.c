/* func_001b87e0 (src/Battle/btlMain.c), 2026-09-26 round 4: fresh rewrite
   from the retail listing. 13 fnalign edits at 735/736 instructions; the
   guarded draft had 287. To test it, put it in place of the NONMATCHING
   block. It needs RwV4d, iGpffffb3ac, func_00149ca0/ce0 and func_001496c0
   from the file.
   What moved it:
   - first*/second* temporaries, as in the sibling: only the last component
     fuses into mula/madd;
   - each group/unit loop pair in its own block (287 -> 91, register colour);
   - a colour-to-vector helper that reads the pooled 1/255 literal. Retail
     reloads the literal for each component (83 -> 17);
   - `firstX = scale * b; firstX *= inv;` (multiply operand order, 17 -> 13).
   Residual 13: the hoisted loop constants. Retail materialises 255.0, 0.5
   and the adda zero in that order (f4/f3/f2). b210 always creates the
   fused-madd zero first (f4). No spelling changed that: an explicit 0.0f,
   x*255+0.5, 0.5+255*x, named locals, or a V4d-to-colour helper. The
   scheduling, strength_reduction and lifetimes pragmas were inert.
   Propagation off gives 184, common_subs off 400, and without loop
   invariants it is 150. permute.py ran 107 s with no improvement. */
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} BtlMainFadeColor;

typedef struct {
    RwV4d from0;
    RwV4d from1;
    RwV4d from2;
    RwV4d from3;
    RwV4d from4;
    u32 totalFrames;
    u32 currentFrame;
    u16 flags;
} BtlMainFadeWork;

static inline void btlMainColorToV4d(RwV4d *out, BtlMainFadeColor *color)
{
    out->x = color->r * (1.0f / 255.0f);
    out->y = color->g * (1.0f / 255.0f);
    out->z = color->b * (1.0f / 255.0f);
    out->w = color->a * (1.0f / 255.0f);
}

#pragma push
#pragma opt_loop_invariants on
// FUN_001B87E0
u32 func_001b87e0(void *workRaw)
{
    extern BtlMainFadeColor iGpffffa4d8;
    extern BtlMainFadeColor iGpffffb45c;
    BtlMainFadeWork *work = (BtlMainFadeWork *)workRaw;
    u8 *global;
    f32 ratio;
    f32 inv;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    RwV4d tmp;
    RwV4d target;

    global = iGpffffb3ac;
    if ((*(u32 *)(global + 0xc) & 2) == 0) {
        return 1;
    }
    if ((*(u32 *)(global + 0xc) & 0x2000000) == 0) {
        return 1;
    }
    if (work->currentFrame == 0) {
        work->from0 = *(RwV4d *)(global + 0x24c);
        work->from3 = *(RwV4d *)(global + 0x1ec);
        work->from4 = *(RwV4d *)(global + 0x1fc);
        work->from1 = *func_00149ca0();
        work->from2 = *func_00149ce0();
        {
            u8 *unit;
            u32 group;

            for (group = 0; group < 4; group++) {
                for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                     unit = *(u8 **)(unit + 0xa6c)) {
                    *(BtlMainFadeColor *)(unit + 0x38) = *(BtlMainFadeColor *)(unit + 0x3c);
                    *(RwV4d *)(unit + 0x60) = *(RwV4d *)(unit + 0x70);
                }
            }
        }
    }
    if (work->currentFrame == work->totalFrames >> 1 && (work->flags & 4) == 0) {
        {
            u32 group;
            u8 *unit;

            for (group = 0; group < 4; group++) {
                for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                     unit = *(u8 **)(unit + 0xa6c)) {
                    if ((*(u32 *)(unit + 0x98) & 2) != 0 &&
                        (*(*(u8 **)(unit + 0xa00) + 0x260) & 0x10) == 0) {
                        f32 *scale;

                        (*(u8 **)(unit + 0xa00))[0x281] = 0x70;
                        (*(u8 **)(unit + 0xa00))[0x282] = 6;
                        scale = (f32 *)(*(u8 **)(unit + 0xa00) + 0x274);
                        if (*scale > 1.0f) {
                            *scale = 1.0f;
                        }
                    }
                }
            }
        }
    }
    btlMainColorToV4d(&target, &iGpffffa4d8);
    if (work->currentFrame < work->totalFrames) {
        ratio = (f32)work->currentFrame / (f32)work->totalFrames;
        inv = 1.0f - ratio;
        firstX = work->from0.x * inv;
        firstY = work->from0.y * inv;
        firstZ = work->from0.z * inv;
        secondX = target.x * ratio;
        secondY = target.y * ratio;
        secondZ = target.z;
        tmp.x = firstX + secondX;
        tmp.y = firstY + secondY;
        tmp.z = firstZ + secondZ * ratio;
        tmp.w = 1.0f;
        *(RwV4d *)(iGpffffb3ac + 0x24c) = tmp;
        func_001496c0(&tmp);
        firstX = work->from1.x * inv;
        firstY = work->from1.y * inv;
        firstZ = work->from1.z * inv;
        firstW = work->from1.w * inv;
        secondX = *(f32 *)(iGpffffb3ac + 0x1bc) * ratio;
        secondY = *(f32 *)(iGpffffb3ac + 0x1c0) * ratio;
        secondZ = *(f32 *)(iGpffffb3ac + 0x1c4) * ratio;
        secondW = *(f32 *)(iGpffffb3ac + 0x1c8);
        tmp.x = firstX + secondX;
        tmp.y = firstY + secondY;
        tmp.z = firstZ + secondZ;
        tmp.w = firstW + secondW * ratio;
        *func_00149ca0() = tmp;
        firstX = work->from2.x * inv;
        firstY = work->from2.y * inv;
        firstZ = work->from2.z * inv;
        firstW = work->from2.w * inv;
        secondX = *(f32 *)(iGpffffb3ac + 0x1cc) * ratio;
        secondY = *(f32 *)(iGpffffb3ac + 0x1d0) * ratio;
        secondZ = *(f32 *)(iGpffffb3ac + 0x1d4) * ratio;
        secondW = *(f32 *)(iGpffffb3ac + 0x1d8);
        tmp.x = firstX + secondX;
        tmp.y = firstY + secondY;
        tmp.z = firstZ + secondZ;
        tmp.w = firstW + secondW * ratio;
        *func_00149ce0() = tmp;
        firstX = work->from3.x * inv;
        firstY = work->from3.y * inv;
        firstZ = work->from3.z * inv;
        firstW = work->from3.w * inv;
        secondX = *(f32 *)(iGpffffb3ac + 0x21c) * ratio;
        secondY = *(f32 *)(iGpffffb3ac + 0x220) * ratio;
        secondZ = *(f32 *)(iGpffffb3ac + 0x224) * ratio;
        secondW = *(f32 *)(iGpffffb3ac + 0x228);
        *(f32 *)(iGpffffb3ac + 0x1ec) = firstX + secondX;
        *(f32 *)(iGpffffb3ac + 0x1f0) = firstY + secondY;
        *(f32 *)(iGpffffb3ac + 0x1f4) = firstZ + secondZ;
        *(f32 *)(iGpffffb3ac + 0x1f8) = firstW + secondW * ratio;
        firstX = work->from4.x * inv;
        firstY = work->from4.y * inv;
        firstZ = work->from4.z * inv;
        firstW = work->from4.w * inv;
        secondX = *(f32 *)(iGpffffb3ac + 0x22c) * ratio;
        secondY = *(f32 *)(iGpffffb3ac + 0x230) * ratio;
        secondZ = *(f32 *)(iGpffffb3ac + 0x234) * ratio;
        secondW = *(f32 *)(iGpffffb3ac + 0x238);
        *(f32 *)(iGpffffb3ac + 0x1fc) = firstX + secondX;
        *(f32 *)(iGpffffb3ac + 0x200) = firstY + secondY;
        *(f32 *)(iGpffffb3ac + 0x204) = firstZ + secondZ;
        *(f32 *)(iGpffffb3ac + 0x208) = firstW + secondW * ratio;
        if ((work->flags & 2) == 0) {
            f32 scale = 1.0f / 255.0f;

            {
                u32 group;
                u8 *unit;

                for (group = 0; group < 4; group++) {
                    for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                         unit = *(u8 **)(unit + 0xa6c)) {
                        firstX = scale * unit[0x38];
                        firstX *= inv;
                        firstY = scale * unit[0x39];
                        firstY *= inv;
                        firstZ = scale * unit[0x3a];
                        firstZ *= inv;
                        firstW = scale * unit[0x3b];
                        firstW *= inv;
                        secondX = target.x * ratio;
                        secondY = target.y * ratio;
                        secondZ = target.z * ratio;
                        secondW = target.w;
                        tmp.x = firstX + secondX;
                        tmp.y = firstY + secondY;
                        tmp.z = firstZ + secondZ;
                        tmp.w = firstW + secondW * ratio;
                        unit[0x3c] = (s32)(0.0f + 0.5f + 255.0f * tmp.x);
                        unit[0x3d] = (s32)(0.0f + 0.5f + 255.0f * tmp.y);
                        unit[0x3e] = (s32)(0.0f + 0.5f + 255.0f * tmp.z);
                        unit[0x3f] = (s32)(0.0f + 0.5f + 255.0f * tmp.w);
                        *(f32 *)(unit + 0x70) = *(f32 *)(unit + 0x60) * inv;
                        *(f32 *)(unit + 0x74) = *(f32 *)(unit + 0x64) * inv;
                        *(f32 *)(unit + 0x78) = *(f32 *)(unit + 0x68) * inv;
                        *(f32 *)(unit + 0x7c) = *(f32 *)(unit + 0x6c) * inv;
                    }
                }
            }
        }
    } else {
        func_001496c0(&target);
        *(RwV4d *)(iGpffffb3ac + 0x24c) = target;
        *func_00149ca0() = *(RwV4d *)(iGpffffb3ac + 0x1bc);
        *func_00149ce0() = *(RwV4d *)(iGpffffb3ac + 0x1cc);
        *(RwV4d *)(iGpffffb3ac + 0x1ec) = *(RwV4d *)(iGpffffb3ac + 0x21c);
        *(RwV4d *)(iGpffffb3ac + 0x1fc) = *(RwV4d *)(iGpffffb3ac + 0x22c);
        if ((work->flags & 2) == 0) {
            btlMainColorToV4d(&tmp, &iGpffffb45c);
            {
                u32 group;
                u8 *unit;

                for (group = 0; group < 4; group++) {
                    for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                         unit = *(u8 **)(unit + 0xa6c)) {
                        *(BtlMainFadeColor *)(unit + 0x3c) = iGpffffa4d8;
                        *(RwV4d *)(unit + 0x70) = tmp;
                    }
                }
            }
        }
        return 1;
    }
    work->currentFrame++;
    return 0;
}
#pragma pop
