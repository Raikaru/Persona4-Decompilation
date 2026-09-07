/* Full-owner exact recovery: 824 executable bytes / 832B retail window.
 * All 11 relocations resolved; two unreachable alignment words.
 * Requires frFont.c globals/helpers and fr_font_internal.h interface.
 * s32 spacing, reverse long-lived declaration order, integer-domain callback
 * base and staged raster inputs close the old register/scheduling floor. */
#pragma opt_propagation off
s32 func_00273170(void *arg0, u32 arg1, u32 arg2)
{
    u8 *node;
    u8 *glyph;
    s32 total;
    s32 x;
    s32 complete;
    s32 mode;
    s32 y;
    s32 spacing;
    s32 offset;
    u8 found;
    u32 states;
    u8 style;
    s32 draw_x;
    s32 draw_y;
    u8 palette_index;
    u8 width;
    u8 height;
    f32 scale;

    node = (u8 *)arg0;
    total = 0;
    complete = 1;
    if (!(D_00763810 & 0x40)) {
        states = (u32)D_00887300_abs;
        ((code)*(u32 *)states)(6, 1);
        ((code)*(u32 *)states)(7, 2);
        ((code)*(u32 *)states)(9, 2);
        ((code)*(u32 *)states)(12, 1);
        ((code)*(u32 *)states)(10, 5);
        ((code)*(u32 *)states)(11, 6);
        ((code)*(u32 *)states)(2, 4);
        ((code)*(u32 *)states)(14, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x5100D);
    }
    if (node == 0) {
        return 0;
    }
    node = *(u8 **)(node + 0x2C);
    mode = (s8)arg1;
    while (node != 0) {
        x = *(s32 *)(node + 4);
        y = *(s32 *)(node + 8);
        spacing = *(s8 *)(node + 3);
        glyph = *(u8 **)(node + 0x1C);
        while (glyph != 0) {
            if (mode == 0) {
                style = node[0];
                offset = func_00272e10(node, glyph, style, node[2]);
            } else {
                offset = 0;
            }
            draw_x = offset + (x + *(s32 *)(glyph + 4));
            draw_y = y + *(s32 *)(glyph + 8);
            palette_index = glyph[0x14];
            width = glyph[0x18];
            height = glyph[0x19];
            scale = *(f32 *)(node + 0x14);
            func_00275d80(draw_x, draw_y, glyph, palette_index, width, height,
                         *(s32 *)(glyph + 0x10), scale);
            if (glyph[0x10] != 0) {
                *(u16 *)(glyph + 2) += 1;
            }
            if (glyph[0x10] < 255U) {
                complete = 0;
            }
            x += (s32)((u32)(*(s32 *)(glyph + 0xC) + spacing) << 4);
            glyph = *(u8 **)(glyph + 0x28);
        }
        if (*(u8 **)(node + 0x28) == 0 && *(s32 *)(node + 0x40) == 0) {
            found = 0;
            if (func_00272d40(node) != 0) {
                found = 1;
                switch (*(s32 *)(node + 0x30)) {
                case 0xF222:
                case 0xF227:
                    *(s32 *)(node + 0x3C) -= 1;
                    break;
                case 0xF223:
                case 0xF226:
                    if (*(s32 *)(node + 0x3C) == -1) {
                        func_0045af90(1);
                    } else {
                        *(s32 *)(node + 0x3C) -= 1;
                    }
                    break;
                }
            }
            if (found != 0) {
                complete = 0;
            }
        }
        total += *(s32 *)(node + 0x18);
        node = *(u8 **)(node + 0x28);
    }
    if (D_0076459C > 0) {
        D_0076459C -= 1;
        return 0;
    }
    if ((s8)complete == 0) {
        total = 0;
    }
    return total;
}
#pragma opt_propagation on
