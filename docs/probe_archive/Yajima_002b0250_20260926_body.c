/* func_002b0250 (y_smap, window 1360B) -- best draft 2026-09-26, 6 words.
 * Starts from Yajima_002b0250_typed_floor_20260920.c (7 words; see its .md for
 * the provider/caller contracts it assumes: u8 piece instead of the owner's
 * s8 arg4, func_0044ea90(void *, s32) which y_smap.c already declares).
 * Change: drop the `column` snapshot and index the map with scanColumn
 * directly; the loop-condition sign extension then lands in retail's $s1.
 * Residual (6 words at +0x424,+0x434,+0x440,+0x450,+0x468,+0x484): the two
 * byte parameters copied out of their stack homes swap -- retail mapColumn
 * $s2 / mapRow $s3, b210 $s3 / $s2.
 * Measured flat at 6: declaring sourceRow/sourceColumn in every order at block
 * and function scope, using the parameters directly, all 24 s32/u32/s16/u16/u8
 * type pairs for the two copies (others 70-77), operand order of both adds,
 * dropping `row`. Worse: fused && guard (10), inline row offset (20), no
 * opt_propagation off (299). Assigning sourceRow before the first map getter
 * call gives retail's colouring exactly but moves its lbu ahead of the call
 * (8): the row copy must be live at that call to outrank the column copy,
 * which suggests a source shape where the row value is already held there. */
typedef struct SmapTileWork {
    struct SmapTileWork *self;
    u8 kind;
    u8 orientation;
    u8 fields06[2];
    YVec2f position;
    YVec2f displacement;
    u8 variant;
    u8 fields19[3];
    f32 uRight;
    f32 vBottom;
    f32 uLeft;
    f32 vTop;
    YVec2f extent;
    f32 scale;
    u8 fields38[0x108];
    u8 column;
    u8 row;
    u8 layout;
    u8 flag143;
    u8 flag144;
    u8 fields145[7];
    u8 hasSpecialCell;
    u8 fields14d[3];
    YVec2f specialOffset;
    u8 specialColumn;
    u8 specialRow;
    u8 fields15a[6];
} SmapTileWork;
typedef char SmapTileWorkSize[sizeof(SmapTileWork) == 0x160 ? 1 : -1];

/* The 0x160-byte allocation includes the draw state and special-cell fields.
* The diagnostic's filename/line contract is supplied in the provider proposal. */
#pragma push
/* Preserve retail's redundant -1 kind guard and its load-before-span sequence. */
#pragma opt_propagation off
s32 func_002afbc0(u8 *arg0);
u8 *func_002b0250(u8 *parent, u8 drawColumn, u8 drawRow, u8 kind, u8 piece, u8 variant, u8 mapColumn, u8 mapRow) {
    f32 center[2];
    u8 *task;
    SmapTileWork *work;
    s32 kindValue;
    s16 scanRow;
    s16 scanColumn;
    u8 *map;
    func_002b2bd0(center, 0, 126.0f, 126.0f, 21.0f, 22.0f);
    kindValue = kind & 0xFF;
    /* Retail compares the zero-extended byte with -1, so 255 still allocates. */
    if (kindValue == -1) {
        return NULL;
    }
    func_0044ea90(D_0063EF60, 0x5C4);
    work = (SmapTileWork *)D_008873F4[0](1, 0x160, 0x40000);
    task = (u8 *)func_00451fc0(parent, D_0063EFD8, 0xF, 0, 0, func_002afbc0, func_002b0220, (u8 *)work);
    work->self = work;
    work->kind = kind;
    work->orientation = piece;
    work->variant = variant;
    work->scale = 1.0f;
    work->column = drawColumn;
    work->row = drawRow;
    work->layout = 0;
    work->flag143 = 0;
    work->flag144 = 0;
    work->displacement.y = 0.0f;
    work->displacement.x = 0.0f;
    if (kindValue >= 9) {
        switch (kindValue) {
            case 9:
            case 10: {
                s32 orientation = piece & 0xFF;

                if (orientation == 1) {
                    work->vTop = 0.03125f;
                    work->uLeft = 0.03125f;
                    work->vBottom = 0.59375f;
                    work->uRight = 0.59375f;
                    work->extent.y = 19.0f;
                    work->extent.x = 19.0f;
                } else if (orientation == 2) {
                    work->uLeft = 0.296875f;
                    work->vTop = 0.015625f;
                    {
                        f32 left = work->uLeft;
                        f32 span = 0.578125f;
                        work->uRight = span + left;
                        work->vBottom = span + work->vTop;
                    }
                    work->extent.y = 37.0f;
                    work->extent.x = 37.0f;
                }

                break;
            }
            case 11:
            case 12: {
                s32 orientation = piece & 0xFF;

                if (orientation == 1) {
                    work->vTop = 0.015625f;
                    work->uLeft = 0.015625f;
                    work->uRight = 0.296875f;
                    work->vBottom = 0.859375f;
                    work->extent.x = 19.0f;
                    work->extent.y = 55.0f;
                    work->layout = 1;
                } else if (orientation == 2) {
                    work->uLeft = 0.296875f;
                    work->vTop = 0.015625f;
                    {
                        f32 left = work->uLeft;
                        f32 span = 0.578125f;
                        work->uRight = span + left;
                        work->vBottom = span + work->vTop;
                    }
                    work->extent.y = 37.0f;
                    work->extent.x = 37.0f;
                }

                break;
            }
            case 13:
            case 14: {
                s32 orientation = piece & 0xFF;

                if (orientation == 1 || orientation == 3) {
                    work->vTop = 0.03125f;
                    work->uLeft = 0.03125f;
                    work->vBottom = 0.59375f;
                    work->uRight = 0.59375f;
                    work->extent.y = 19.0f;
                    work->extent.x = 19.0f;
                } else if (orientation == 2) {
                    work->uLeft = 0.296875f;
                    work->vTop = 0.296875f;
                    work->uRight = 0.859375f;
                    work->vBottom = 0.859375f;
                    work->extent.y = 37.0f;
                    work->extent.x = 37.0f;
                }

                break;
            }
        }
    } else {
        if (kindValue >= 7) {
            work->uLeft = 0.015625f;
            work->vTop = 0.015625f;
            work->vBottom = 0.578125f;
            work->uRight = 0.578125f;
            work->extent.y = 37.0f;
            work->extent.x = 37.0f;

        } else {
            if (kindValue == 2) {
                if ((piece & 0xFF) == 1) {
                    work->uLeft = 0.015625f;
                    work->vTop = 0.015625f;
                    work->uRight = 0.578125f;
                    work->vBottom = 0.578125f;
                    work->extent.x = 37.0f;
                    work->extent.y = 37.0f;
                    if (variant == 2 || variant == 1) {
                        work->layout = 2;
                    }
                } else if ((piece & 0xFF) == 2) {
                    work->vTop = 0.296875f;
                    work->uLeft = 0.296875f;
                    work->vBottom = 0.578125f;
                    work->uRight = 0.578125f;
                    work->extent.y = 19.0f;
                    work->extent.x = 19.0f;
                }
            } else {
                work->uLeft = 0.03125f;
                work->vTop = 0.03125f;
                work->vBottom = 0.59375f;
                work->uRight = 0.59375f;
                work->extent.y = 19.0f;
                work->extent.x = 19.0f;
            }

        }

    }
    /* Each getter is reissued at its original boundary. The 2x2 scan uses
    * the source map cell, not the possibly shifted draw coordinates. */
    work->hasSpecialCell = 0;
    if ((piece & 0xFF) == 2) {
        s32 sourceColumn = mapColumn;
        if (sourceColumn == *(u8 *)((u8 *)func_00155280() + 0x46)) {
            s32 sourceRow = mapRow;
            if (sourceRow == *(u8 *)((u8 *)func_00155280() + 0x47)) {
                for (scanRow = 0; scanRow < 2; scanRow++) {
                    s32 row = scanRow;
                    s32 rowOffset;
                    scanColumn = 0;
                    rowOffset = (sourceRow + row) * 256;
                    for (; scanColumn < 2; scanColumn++) {
                        map = (u8 *)func_00155280();
                        if ((s8)(*(u8 *)(rowOffset + (u32)map + (sourceColumn + scanColumn) * 0x10 + 0x55) >> 4) == 2) {
                            work->specialOffset.x = 9.0f;
                            work->specialOffset.y = 9.0f;
                            work->specialColumn = (u8)scanColumn;
                            work->specialRow = (u8)scanRow;
                            work->hasSpecialCell = 1;
                            return task;
                        }
                    }
                }
            }
        }
    }
    return task;
}

#pragma pop
