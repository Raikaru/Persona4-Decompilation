// FUN_0047D540
void func_0047d540(u8 **arg0, u8 *arg1)
{
    struct MtxRow { f32 x; f32 y; f32 z; s32 flag; } out[4];
    f32 *in;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 wx;
    f32 wy;
    f32 wz;
    u8 *node;

    node = *arg0;
    while (node != NULL) {
        if (*(u32 *)(node + 8) != 0) {
            if (func_0047a510(arg1, *(u16 *)(node + 4), out) == 0) {
                u8 *dst = (u8 *)out;
                u8 *src = arg1;
                s32 count = 8;
                do {
                    *(u32 *)dst = *(u32 *)src;
                    *(u32 *)(dst + 4) = *(u32 *)(src + 4);
                    dst += 8;
                    src += 8;
                    count--;
                } while (count > 0);
            }
            in = (f32 *)(u8 *)out;
            if (*(u16 *)(node + 4) >= 1000) {
                out[0].x = 1.0f; out[1].x = 1.0f; out[2].x = 1.0f;
                out[0].y = 0.0f; out[0].z = 0.0f; out[1].y = 0.0f;
                out[2].y = 0.0f; out[2].z = 0.0f; out[3].x = 0.0f;
                out[3].y = 0.0f; out[3].z = 0.0f;
                out[1].z = (f32)(out[1].z) ;
                out[1].flag |= 0x20003;
                out[3].x = *(f32 *)(arg1 + 176);
                out[3].y = *(f32 *)(arg1 + 180);
                out[3].z = *(f32 *)(arg1 + 184);
            } else {
                func_003e0670(out, out);
                func_003dc610((u8 *)out + 48, out);
                x = *(f32 *)((u8 *)out + 48);
                y = *(f32 *)((u8 *)out + 52);
                z = *(f32 *)((u8 *)out + 56);
                w = *(f32 *)((u8 *)out + 60);
                if ((x*x + y*y + z*z + w*w) != 0.0f) {
                    f32 len = __builtin_sqrtf(x*x + y*y + z*z + w*w);
                    x /= len; y /= len; z /= len; w /= len;
                }
                xx = x*x; yy = y*y; zz = z*z;
                xy = x*y; xz = x*z; yz = y*z;
                wx = w*x; wy = w*y; wz = w*z;
                out[0].x = 1.0f - 2.0f * (yy + zz);
                out[0].y = 2.0f * (xy + wz);
                out[0].z = 2.0f * (xz - wy);
                out[1].x = 2.0f * (xy - wz);
                out[1].y = 1.0f - 2.0f * (zz + xx);
                out[1].z = 2.0f * (yz + wx);
                out[2].x = 2.0f * (xz + wy);
                out[2].y = 2.0f * (yz - wx);
                out[2].z = 1.0f - 2.0f * (xx + yy);
                out[3].x = 0.0f; out[3].y = 0.0f; out[3].z = 0.0f;
                out[3].flag = 3;
                out[3].x = *(f32 *)(arg1 + 176);
                out[3].y = *(f32 *)(arg1 + 180);
                out[3].z = *(f32 *)(arg1 + 184);
            }
            func_004b12e0(*(u32 *)(node + 8), (u8 *)out);
            func_004b1190(*(u32 *)(node + 8));
            node = *(u8 **)(node + 16);
        }
    }
}
