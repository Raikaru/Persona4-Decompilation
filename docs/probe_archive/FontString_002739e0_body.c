/* Exact full-owner recovery: 724 executable bytes / 736B retail window.
 * All 20 relocations applied; twelve retail zero-tail bytes.
 * Uses frFont.c declarations and existing FrFontNode/FrFontGlyph layouts.
 * Legacy D_0076380C resolves to 0x007637FC, not its name-derived address. */
#pragma push
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
void func_002739e0(u8 index, u8 *context)
{
    extern s32 func_00442948(const void *param_1);
    extern s8 iGpffffa748;
    extern s8 D_0076380C;
    /* A two-byte glyph plus its NUL terminator. */
    s8 glyph[3];
    u8 *text;
    s32 length;
    s32 position;
    s8 *clear;
    s32 remaining;
    s32 width;
    s64 style;
    s8 spacing;
    s64 byte;
    s8 previous_style;
    u8 attribute;
    u8 *new_node;
    u8 *first_node;
    u8 *glyph_node;
    FrFontNode *node;
    FrFontNode *linked_node;
    FrFontNode *attribute_node;
    FrFontGlyph *child;

    text = (u8 *)D_008815B0[index];
    clear = glyph;
    remaining = 3;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear += 1;
            remaining -= 1;
        } while (remaining != 0);
    }
    if (text != NULL) {
        length = func_00442948(text);
        if (length <= 0) {
            func_0046d730(D_0063BAE8, 0xB63);
        }
        previous_style = *(s8 *)(context + 0xC);
        position = 0;
        goto text_test;
text_body:
            byte = *(s8 *)(text + position);
            glyph[0] = byte;
            if (byte == 0x20) {
                glyph[0] = -0x7D;
                glyph[1] = -0xA;
            } else {
                glyph[1] = 0;
                /* Preserve the signed-byte extraction without a signed left shift. */
                if ((((s64)((u64)byte << 56) >> 56) & 0xFF) >= 0x80) {
                    position += 1;
                    glyph[1] = *(s8 *)(text + position);
                }
            }
            style = *(s8 *)(context + 0xC);
            if (style != (s64)previous_style) {
                /* A style transition needs an empty node before the next glyph. */
                node = (FrFontNode *)*(u8 **)(context + 0x14);
                if (node == NULL) {
                    goto create_first_node;
                }
                if (node->glyphs == NULL) {
                    goto apply_attribute;
                }
                new_node = func_002724d0((u8 *)&iGpffffa748, 0,
                                       *(s8 *)(context + 0xD),
                                       *(s8 *)(context + 0xE), NULL);
                if (new_node != NULL) {
                    goto link_new_node;
                }
                linked_node = node;
                goto store_new_node;
link_new_node:
                linked_node = (FrFontNode *)func_00273650(
                    (s32)node, (s32)new_node, 1);
store_new_node:
                node = linked_node;
                *(u8 **)(context + 0x14) = (u8 *)node;
                goto apply_attribute;
create_first_node:
                first_node = func_002724d0((u8 *)&iGpffffa748, 0,
                                         *(s8 *)(context + 0xD),
                                         *(s8 *)(context + 0xE), NULL);
                if (first_node != NULL) {
                    goto link_first_node;
                }
                linked_node = node;
                goto store_first_node;
link_first_node:
                linked_node = (FrFontNode *)func_00273650(
                    (s32)node, (s32)first_node, 1);
store_first_node:
                node = linked_node;
                *(u8 **)(context + 0x14) = (u8 *)node;
apply_attribute:
                attribute = *(u8 *)(context + 0xF);
                attribute_node = (FrFontNode *)*(u8 **)(context + 0x14);
                if (attribute_node == NULL) {
                    func_0046d730(&D_0063BAE8, 0x69B);
                }
                while (attribute_node != NULL) {
                    attribute_node->unknown_00[2] = attribute;
                    attribute_node = attribute_node->next;
                }
                previous_style = (s8)style;
            }
            *(u8 **)(context + 0x14) =
                func_002724d0((u8 *)glyph, style,
                              *(s8 *)(context + 0xD),
                              *(s8 *)(context + 0xE),
                              *(u8 **)(context + 0x14));
            spacing = D_0076380C;
            glyph_node = *(u8 **)(context + 0x14);
            if (glyph_node == NULL) {
                func_0046d730(&D_0063BAE8, 0x6C3);
            }
            *(s8 *)(glyph_node + 3) = spacing;
            width = 0;
            child = *(FrFontGlyph **)(glyph_node + 0x1C);
            while (child != NULL) {
                width += child->advance;
                width += *(s8 *)(glyph_node + 3);
                child = child->next;
            }
            *(s32 *)(glyph_node + 0xC) = width;
            position += 1;
            goto text_test;
text_test:
        if (position < length) {
            goto text_body;
        }
    }
}
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma pop
