/*
 * Archived first-party C floor for src/promoted/y_smap.c: func_002b0250.
 * Result: 7 fully resolved differing words; 1356 executable bytes in 1360.
 * This is not MATCH and is not a production source file.
 *
 * The measured body below is copied without alteration from ready/body.c:
 * c36eb71039db867f6e230eded1b9149457067ca5513dacf5c911d888ecb22f5b
 * Measurements belong to the complete configured owner at 6d950a1, not to
 * a separate compilation of this support wrapper. See the companion .md.
 *
 * Map-neighborhood precondition: every visited 2x2 map byte must lie within
 * the actual provider buffer. Six synthetic states at map row 23, columns
 * 10..15 with no earlier hit exceed 0x18f8 in retail and candidate alike.
 * No universal map-data invariant or no-overread claim is established.
 *
 * Historical API changes remain proposals. The diagnostic's two-argument
 * declaration requires reconciling its old void(void) provider and callers;
 * the map getter, centering mode and initializer caller changes are recorded
 * in the companion notes. This file does not apply those source changes.
 */
#include "../../include/type.h"
#include "../../include/sdk_task_registration.h"

/* Support recovered from the complete measured owner. The PS2 ABI is 32-bit. */
typedef struct YVec2f { f32 x, y; } YVec2f;

extern u8 D_0063EF60[];
extern char D_0063EFD8[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_002b2bd0(f32 *, s64, f32, f32, f32, f32);
extern s32 *func_00155280(void);
extern void func_002b0220(u8 *task);
/* Pending provider contract, retained as measured; see the .md history. */
extern void func_0044ea90(void *file, s32 line);

/* Retained body begins below; its original bytes and pragma scope follow. */
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
                        s32 column = scanColumn;
                        map = (u8 *)func_00155280();
                        if ((s8)(*(u8 *)(rowOffset + (u32)map + (sourceColumn + column) * 0x10 + 0x55) >> 4) == 2) {
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
