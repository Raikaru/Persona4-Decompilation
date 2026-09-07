/* Fully relocated exact:1212 executable bytes/1216 retail window,32 resolved
 * relocations,zero differences; final word is unreachable alignment.
 * Reuses existing FrFontScript/FrFontNode/FrFontGlyph layouts in frFont.c.
 * Positive insertion branches plus a natural u32 byte and real glyph[3]
 * close the old217-word floor. Preserve the full signed glyph pair.
 * Only six real descriptor groups exist, counts8/8/8/2/10/14. The mask
 * reaches adjacent data for groups6/7. Diagnostics are not bounds guards:
 * count<index and the full low command byte are intentional retail checks.
 * Native consumer:166 cases/1384 checks at each O0/O2, plus three isolated
 * invalid-domain faults per optimization; no MIPS/graphical execution. */
#pragma push
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
u8 *func_002740b0(void *data)
{
    typedef int (*FrFontCommand)();
    typedef struct FrFontCommandGroup {
        FrFontCommand *handlers;
        s32 count;
    } FrFontCommandGroup;
    extern void func_00274640(void);
    extern u8 iGpffffa748;
    extern s32 D_00763800;
    FrFontScript *script;
    u8 *context;
    u32 code;
    s32 command;
    s32 index;
    FrFontCommandGroup *group;
    s32 result;
    FrFontNode *node;
    FrFontNode *linked;
    u8 *allocated;
    s16 height;
    s8 spacing;
    u32 duration;
    s32 width;
    s32 pair;
    FrFontGlyph *child;
    s8 glyph[3];

    context = data;
    script = data;
    if (((script->data[0] & 0xF0) != 0xF0) && (script->data[1] == 5)) {
        script->pos += 4;
    }
    func_00274640();
    D_00763810 = (s16)(D_00763810 | 1) & ~2;
    while ((code = script->data[script->pos++]) != 0) {
        if ((code & 0xF0) == 0xF0) {
            command = (code << 8) | script->data[script->pos++];
            group = (FrFontCommandGroup *)(D_0063BA00 + (((command & 0xE0) >> 5) * 8));
            index = command & 0x1F;
            if (group->count < index) {
                func_0046d730(D_00748110, 0xA5);
            }
            if ((command & 0xFF) <= 0) {
                func_0046d730(D_00748100, 0xA6);
            }
            result = group->handlers[index](command, script);
            script->pos += (((command & 0xF00) >> 8) - 1) * 2;
            if (result != 0) {
                result = 1;
            } else {
                if (*(s8 *)(context + 0x1C) == 0) {
                    *(s8 *)(context + 0x1C) = 1;
                }
                result = 0;
            }
            if (result != 0) {
                break;
            }
        } else if (code == 10) {
            if (D_00763810 & 4) {
                *(s32 *)(context + 4) += D_00763800 * 8;
                *(s8 *)(context + 0x1C) = 1;
                *(s8 *)(context + 0x1D) = 1;
            }
        } else {
            node = *(FrFontNode **)(context + 0x14);
            if ((node != NULL) && (node->glyphs == NULL)) {
                *(s8 *)(context + 0x1C) = 0;
            }
            if (*(s8 *)(context + 0x1C) != 0) {
                node = *(FrFontNode **)(context + 0x14);
                allocated = func_002724d0(&iGpffffa748, 0, *(s8 *)(context + 0xD), *(s8 *)(context + 0xE), NULL);
                if (allocated != NULL) {
                    goto link_node;
                }
                linked = node;
                goto store_node;
link_node:
                linked = (FrFontNode *)func_00273650((s32)node, (s32)allocated, 1);
store_node:
                node = linked;
                *(FrFontNode **)(context + 0x14) = node;
                func_00272730((int)node, *(u8 *)(context + 0xF));
                height = *(s16 *)(context + 0x1E);
                node = *(FrFontNode **)(context + 0x14);
                if (node == NULL) {
                    func_0046d730(D_0063BAE8, 0x6A7);
                }
                *(s16 *)node = height;
                *(s8 *)(context + 0x1C) = 0;
            }
            if (*(s8 *)(context + 0x1D) != 0) {
                *(s32 *)(*(u8 **)(context + 0x14) + 4) = *(s32 *)context;
                *(s32 *)(*(u8 **)(context + 0x14) + 8) = *(s32 *)(context + 4);
                *(s8 *)(context + 0x1D) = 0;
            }
            if ((s32)code < 0x80) {
                if (code == 0x20) {
                    glyph[0] = 0x83;
                    glyph[1] = 0xF6;
                    glyph[2] = 0;
                } else {
                    glyph[0] = code;
                    glyph[1] = 0;
                }
                *(u8 **)(context + 0x14) = func_002724d0((u8 *)glyph, *(s8 *)(context + 0xC), *(s8 *)(context + 0xD), *(s8 *)(context + 0xE), *(u8 **)(context + 0x14));
            } else {
                pair = (code << 8) | script->data[script->pos++];
                if (pair < 0xC080) {
                    glyph[0] = (pair & 0xFF00) >> 8;
                    glyph[1] = pair;
                    glyph[2] = 0;
                    *(u8 **)(context + 0x14) = func_002724d0((u8 *)glyph, *(s8 *)(context + 0xC), *(s8 *)(context + 0xD), *(s8 *)(context + 0xE), *(u8 **)(context + 0x14));
                } else {
                    pair -= 0x4000;
                    glyph[0] = (pair & 0xFF00) >> 8;
                    glyph[1] = pair;
                    glyph[2] = 0;
                    *(u8 **)(context + 0x14) = func_002724d0((u8 *)glyph, 8, *(s8 *)(context + 0xD), *(s8 *)(context + 0xE), *(u8 **)(context + 0x14));
                }
            }
            spacing = (-D_00763808[*(u8 *)(context + 0xC)] * 2) / 32;
            node = *(FrFontNode **)(context + 0x14);
            if (node == NULL) {
                func_0046d730(D_0063BAE8, 0x6C3);
            }
            node->line_height = spacing;
            width = 0;
            child = node->glyphs;
            while (child != NULL) {
                width += child->advance;
                width += node->line_height;
                child = child->next;
            }
            *(s32 *)((u8 *)node + 0xC) = width;
            duration = *(u32 *)(context + 8);
            node = *(FrFontNode **)(context + 0x14);
            if (node == NULL) {
                func_0046d730(D_0063BAE8, 0x735);
            }
            *(u32 *)((u8 *)node + 0x14) = duration >> 4;
        }
    }
    D_00763810 = (s16)(D_00763810 & ~1) | 2;
    return *(u8 **)(context + 0x14);
}
#pragma pop
