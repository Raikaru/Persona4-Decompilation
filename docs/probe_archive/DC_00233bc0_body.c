// func_00233bc0 (0x00233bc0-0x002340c0, 1280B) — guarded floor @244fndiff/1236B (44B under; frame/saves agree).
// Wins: recipe-A byte-conv (s32 t3, (u32)srl, (f32)(s32), f1+f1 doubling); s32 arg1; temp_16>1 slti-form;
// desc if/else beq-dispatch; f32 f20; full case coverage; all calls.
// Walls: 5 prior residuals confirmed neutral (call-path extend pair; merge-pair split; else-mask rotate;
//   (t2!=0)&mask fold; OR-dest v1-vs-a0); tbl-hoist/index-reorder neutral; GPREL phantoms.
// Prior attempts (guard notes, nd 276-290) hit the same walls. Production stays ASM.
f32 func_00233bc0(u8 *arg0, s32 arg1)
{
    s32 disc;
    s64 v2;
    s8 b;
    s32 t2;
    u32 t4;
    f32 f20;
    f32 f1;
    s32 t3;
    u8 *tbl;
    s16 m;

    disc = arg1 & 0xFF;
    if (disc >= 24) {
        func_0046d730(D_00635938, 1265);
    }
    if (disc >= 24) {
        func_0046d730(D_00635938, 1217);
    }
    if (disc < 16) {
        v2 = (s64)(s32)func_002332a0(arg0, arg1);
    } else {
        v2 = (s64)(((*(s32 *)(arg0 + 20) & (1 << disc)) != 0) << 24) >> 24;
    }
    m = (s16)v2;
    if (m < -1 || m > 1) {
        func_0046d730(D_00635938, 1269);
    }
    t2 = (*(u16 *)arg0 & 4);
    t4 = (t2 != 0) & 0xFFFF;
    f20 = 1.0f;
    tbl = iGpffffb408;
    if (disc == 19) {
        if (m > 0) {
            f20 = 2.5f;
        }
    } else if (disc == 18) {
        if (m > 0) {
            f20 = 2.5f;
        }
    } else if (disc == 4) {
        t3 = *(tbl + ((t4 & 0xFFFF) * 3) + m);
        {
            s32 u = t3 + 0;
            u8 raw = (u8)u;
            if ((s32)raw >= 0) {
                f1 = (f32)(s32)raw;
            } else {
                s32 o = ((u32)raw >> 1) | (raw & 1);
                f1 = (f32)(s32)o;
                f1 = f1 + f1;
            }
        }
        f20 = f1 / 100.0f;
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * iGpffff8110;
        }
    } else if (disc == 3) {
        t3 = *(((t4 & 0xFFFF) * 3) + tbl + 1 - m);
        {
            u8 raw = (u8)t3;
            if ((s32)raw >= 0) {
                f1 = (f32)(s32)raw;
            } else {
                s32 o = ((u32)raw >> 1) | (raw & 1);
                f1 = (f32)(s32)o;
                f1 = f1 + f1;
            }
        }
        f20 = f1 / 100.0f;
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * 0.75f;
        }
    } else if (disc == 2) {
        t3 = *(((t4 & 0xFFFF) * 3) + tbl + 7 - m);
        {
            u8 raw = (u8)t3;
            if ((s32)raw >= 0) {
                f1 = (f32)(s32)raw;
            } else {
                s32 o = ((u32)raw >> 1) | (raw & 1);
                f1 = (f32)(s32)o;
                f1 = f1 + f1;
            }
        }
        f20 = f1 / 100.0f;
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * 0.75f;
        }
    } else if (disc == 1) {
        t3 = *(m + ((t4 & 0xFFFF) * 3) + tbl + 1);
        {
            u8 raw = (u8)t3;
            if ((s32)raw >= 0) {
                f1 = (f32)(s32)raw;
            } else {
                s32 o = ((u32)raw >> 1) | (raw & 1);
                f1 = (f32)(s32)o;
                f1 = f1 + f1;
            }
        }
        f20 = f1 / 100.0f;
        if (((*(s32 *)(arg0 + 20) & 0x80000) != 0)) {
            f1 = f1;
            f20 = f20 * 2.5f;
        }
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * iGpffff8110;
        }
    } else if (disc == 0) {
        t3 = *(m + ((t4 & 0xFFFF) * 3) + tbl + 1);
        {
            u8 raw = (u8)t3;
            if ((s32)raw >= 0) {
                f1 = (f32)(s32)raw;
            } else {
                s32 o = ((u32)raw >> 1) | (raw & 1);
                f1 = (f32)(s32)o;
                f1 = f1 + f1;
            }
        }
        f20 = f1 / 100.0f;
        if (((*(s32 *)(arg0 + 20) & 0x40000) != 0)) {
            f20 = f20 * 2.5f;
        }
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * iGpffff8110;
        }
    }
    return f20;
}
