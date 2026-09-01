/* object_size=536B; window=496B; normalized_diff=319; first_diffs=0x2E,0x30,0x33,0x34,0x36,0x37,0x3E,0x40,0x43,0x44,0x46,0x47,0x60,0x68,0x70,0x72; oversized candidate (automatic archive condition). */
/* Reconstructed from retail window and generated candidate. The body exceeded the 496-byte retail window, so it was restored to INCLUDE_ASM. */
void func_0035c480(u8 *arg0, u16 arg1, s32 arg2)
{
    u8 *base;
    s64 style;
    u32 code;
    u8 text[264];
    s8 short_text;
    extern u8 D_0064CD60[];

    base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x22) = 0;
    *(f32 *)(base + 0x18) = *(f32 *)(base + 8);
    *(f32 *)(base + 0x1C) = *(f32 *)(base + 0xC);
    *(f32 *)(base + 0x0) = *(f32 *)(base + 8);
    *(f32 *)(base + 0x4) = *(f32 *)(base + 0xC);
    code = (u32)arg1 & 0xFFFF;
    if (*(u16 *)(base + 0x20) != code || *(s32 *)(base + 0x24) != arg2) {
        if (code != 0) {
            if (arg2 & 1) {
                *(s32 *)(base + 0x28) = 0xF6001600;
                style = 98;
            } else if (arg2 & 2) {
                *(s32 *)(base + 0x28) = 0xF600B000;
                style = 99;
            } else {
                *(s32 *)(base + 0x28) = 0xFFD13400;
                style = 97;
            }
            if (code < 31) {
                switch (code) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 19:
                case 21:
                case 24:
                case 26:
                case 27:
                case 29:
                    if (func_00110d60((s64)(s8)func_001060b0()) & 1) {
                        func_00442088(&text, &D_0064CD60[-0x5698], 0);
                    } else {
                        func_00442088(&text, &D_0064CD60[-0x5694], 0);
                    }
                    break;
                case 8:
                case 16:
                case 17:
                case 18:
                case 20:
                case 22:
                case 23:
                case 25:
                case 28:
                case 30:
                    short_text = 0;
                    break;
                default:
                    func_0046d730(&D_0064CC98, 0xA05);
                    break;
                }
            } else {
                func_0046d730(&D_0064CC98, 0xA05);
            }
            func_00442088(&short_text, &D_0064CD60, code, (s8)style, &text);
            func_003547c0((s32 *)(base + 0x30), (u8 *)&short_text);
        } else {
            func_003547c0((s32 *)(base + 0x30), NULL);
        }
        *(u16 *)(base + 0x20) = arg1;
        *(s32 *)(base + 0x24) = arg2;
        *(s32 *)(base + 0x2C) = 0;
    }
}
