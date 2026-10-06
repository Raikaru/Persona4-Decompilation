s32 func_002b6ec0(u8 *arg0)
{
    typedef struct {
        s32 unknown00;
        s16 frame;
        u16 unknown06;
        s32 order;
        s16 originX;
        s16 originY;
        s16 flags;
        u16 unknown12;
        f32 depth;
        u8 unknown18[0x20];
        f32 x;
        f32 y;
        u8 unknown40[7];
        s8 positionFlag;
        u8 unknown48[0x26];
        u8 opacity;
        u8 unknown6F[4];
        s8 opacityFlag;
        u8 unknown74[0x11];
        u8 red;
        u8 green;
        u8 blue;
        u8 unknown88[0x18];
        f32 scaleX;
        u8 unknownA4[8];
        f32 scaleY;
        u8 unknownB0[0x20];
        f32 angle;
        u8 unknownD4[0x2C];
    } YDrawUpdateRecord;
    typedef struct {
        void *resource;
        YDrawUpdateRecord records[0x30C];
        s16 count;
        s16 active[0x30C];
    } YDrawUpdateContext;
    typedef char RecordSizeCheck[sizeof(YDrawUpdateRecord) == 0x100 ? 1 : -1];
    typedef char ContextSizeCheck[sizeof(YDrawUpdateContext) == 0x31220 ? 1 : -1];
    YDrawUpdateContext *table;
    s32 off;
    s16 i;
    s16 bit;
    s16 found;
    s32 flags;
    s32 color;
    s32 animation;
    YDrawUpdateContext *rows;
    YDrawUpdateRecord *e;
    u8 *w;
    s32 renderOffset;
    YDrawUpdateContext *drawRows;

    table = *(YDrawUpdateContext **)(arg0 + 0x38);
    table->count = 0;
    for (i = 0; i < 0x30C; i++) {
        s16 fl;
        table->active[i] = 0;
        rows = *(YDrawUpdateContext **)(iGpffffb574 + 0x38);
        off = (s32)i * 0x100;
        e = (YDrawUpdateRecord *)((u8 *)rows + off + 4);
        if ((s16)(e->flags & 1) != 1) {
            continue;
        }
        animation = func_002b89a0((u8 *)&e->flags);
        memcpy(*(u8 **)(iGpffffb574 + 0x38) + off + 0x14, animation, 0xF0);
        func_002b7cd0(arg0, i, *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + off + 8));
        rows = *(YDrawUpdateContext **)(iGpffffb574 + 0x38);
        e = (YDrawUpdateRecord *)((u8 *)rows + off + 4);
        fl = e->flags;
        if ((s16)((fl & 0x4000) >> 14) == 1) {
            w = func_00460990();
            *(void (**)(void))(w + 8) = func_002b6260;
            *(s32 *)(w + 0x10) = 0;
            rows = *(YDrawUpdateContext **)(iGpffffb574 + 0x38);
            renderOffset = (s32)i * 0x100;
            func_00460ac0(D_00793E80 + ((YDrawUpdateRecord *)((u8 *)rows + renderOffset + 4))->order * 0x30, w);
            drawRows = *(YDrawUpdateContext **)(iGpffffb574 + 0x38);
            if (((YDrawUpdateRecord *)((u8 *)drawRows + renderOffset + 4))->scaleX <= fGpffff8504 ||
                ((YDrawUpdateRecord *)((u8 *)drawRows + off + 4))->scaleY <= fGpffff8504) {
                goto first_scan;
            }
                renderOffset = (s32)i * 0x100;
                e = (YDrawUpdateRecord *)((u8 *)drawRows + renderOffset + 4);
                color = func_002b2a30(0xFF, e->red, e->green, e->blue);
                e = (YDrawUpdateRecord *)((u8 *)drawRows + renderOffset + 4);
                func_0025ecd0(e->x, e->y, e->depth,
                    color, e->opacity, e->frame, table->resource, 0,
                    e->originX, e->originY, e->angle,
                    e->scaleX, e->scaleY, D_00793E80 + e->order * 0x30);
                goto append_active;
first_scan:
                flags = ((YDrawUpdateRecord *)((u8 *)drawRows + off + 4))->flags;
                for (bit = 1; bit < 13; bit++) {
                    if (((flags & (u16)(1 << bit)) >> bit) == 1) {
                        found = 1;
                        goto first_scan_done;
                    }
                }
                found = 0;
first_scan_done:
                if (found == 0) {
                    ((YDrawUpdateRecord *)((u8 *)drawRows + off + 4))->flags &= ~1;
                }

        } else if ((s16)((fl & 0x2000) >> 13) == 1) {
            w = func_00460990();
            *(void (**)(void))(w + 8) = func_002b6180;
            *(s32 *)(w + 0x10) = 0;
            rows = *(YDrawUpdateContext **)(iGpffffb574 + 0x38);
            renderOffset = (s32)i * 0x100;
            func_00460ac0(D_00793E80 + ((YDrawUpdateRecord *)((u8 *)rows + renderOffset + 4))->order * 0x30, w);
            drawRows = *(YDrawUpdateContext **)(iGpffffb574 + 0x38);
            if (((YDrawUpdateRecord *)((u8 *)drawRows + renderOffset + 4))->scaleX <= fGpffff8504 ||
                ((YDrawUpdateRecord *)((u8 *)drawRows + off + 4))->scaleY <= fGpffff8504) {
                goto second_scan;
            }
                renderOffset = (s32)i * 0x100;
                e = (YDrawUpdateRecord *)((u8 *)drawRows + renderOffset + 4);
                color = func_002b2a30(0xFF, e->red, e->green, e->blue);
                e = (YDrawUpdateRecord *)((u8 *)drawRows + renderOffset + 4);
                func_0025ecd0(e->x, e->y, e->depth,
                    color, e->opacity, e->frame, table->resource, 0,
                    e->originX, e->originY, e->angle,
                    e->scaleX, e->scaleY, D_00793E80 + e->order * 0x30);
                goto append_active;
second_scan:
                flags = ((YDrawUpdateRecord *)((u8 *)drawRows + off + 4))->flags;
                for (bit = 1; bit < 13; bit++) {
                    if (((flags & (u16)(1 << bit)) >> bit) == 1) {
                        found = 1;
                        goto second_scan_done;
                    }
                }
                found = 0;
second_scan_done:
                if (found == 0) {
                    ((YDrawUpdateRecord *)((u8 *)drawRows + off + 4))->flags &= ~1;
                }

        } else if (e->opacity != 0 && !(e->scaleX <= fGpffff8504) &&
                   !(e->scaleY <= fGpffff8504)) {
            renderOffset = (s32)i * 0x100;
            e = (YDrawUpdateRecord *)((u8 *)rows + renderOffset + 4);
            color = func_002b2a30(0xFF, e->red, e->green, e->blue);
            e = (YDrawUpdateRecord *)((u8 *)rows + renderOffset + 4);
            func_0025ecd0(e->x, e->y, e->depth,
                color, e->opacity, e->frame, table->resource, 1,
                e->originX, e->originY, e->angle,
                e->scaleX, e->scaleY, D_00793E80 + e->order * 0x30);
        } else {
            e = (YDrawUpdateRecord *)((u8 *)rows + off + 4);
            if (e->flags == 1 && e->opacityFlag == 0 && e->positionFlag == 0) {
                e->flags &= ~1;
            }
        }
append_active:
        table->active[table->count] = i;
        (table->count)++;
    }
    return 0;
}
