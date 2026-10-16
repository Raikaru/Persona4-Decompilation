#ifndef FIELD_FRAME_INTERNAL_H
#define FIELD_FRAME_INTERNAL_H
#include "type.h"

/* One 0x10-byte entry of the field cell grid. Grid rows are 0x100 bytes, so a
 * cell at (row, col) is at 0x54 + row * 0x100 + col * 0x10 in the frame.
 * Neighbour checks in the grid code add and subtract 0x10 (column) and 0x100
 * (row) from these offsets. */
typedef struct FldFrameCell {
    u8 occupied;           /* 0x00: 1 when the cell holds a placed entry */
    u8 flags;              /* 0x01: low nibble is tested; bit 0x20 is set by neighbour checks */
    u16 resourceId;        /* 0x02: resource index passed to MT_Scene_GetRes */
    u8 type;               /* 0x04: cell type; 2, 3, 6, 7, 8 and 9..14 are tested by name */
    u8 kind;               /* 0x05: quarter-turn orientation; FldUnit reads it as the spawn direction */
    u8 shapeX;             /* 0x06 */
    u8 shapeZ;             /* 0x07 */
    u8 unk08[2];
    u8 exits;              /* 0x0A: exit mask tested against the incoming mask */
    u8 unk0B;              /* 0x0B: copied from the entry table */
    u8 unk0C[4];
} FldFrameCell;

/* Field frame state, returned by MT_Scene_GetFrameState(). Only the offsets
 * read or written by name in the field code are typed; the rest keep their
 * measured extent and are not assumed to mean anything. A wrong offset changes
 * the generated code and fails the owner verify. */
typedef struct FldFrame {
    u8 *loadTask;          /* 0x00: load task passed to FldLoadTaskFieldId / FldLoadTaskRoomId */
    u8 *cameraTask;        /* 0x04: FldCameraTaskCreate result; FldCameraApplyRecord, FldFrame_GetStatus */
    u8 unk08[0x10];
    u8 *smapObject;        /* 0x18: smapCreateSymbols result */
    u8 *supporterTask;     /* 0x1C: FldSupporterTaskCreate result; FldFrameObjSetActive target */
    u8 *unitTask;          /* 0x20: FldUnit_SpawnEncounterTask result; FldUnit_SetMode, FldUnit_IsSettled */
    u8 unk24[0x08];
    u8 *noiseTask;         /* 0x2C: FldNoiseTaskCreate result */
    u8 *panelTask;         /* 0x30: FldPanel2dSetState target */
    u8 unk34[0x10];
    u8 spawnColumn;        /* 0x44: column of the spawn cell; set by the board scan in k_fldResource.c */
    u8 spawnRow;           /* 0x45: row of the spawn cell; set by the board scan in k_fldResource.c */
    u8 cellPick[2];        /* 0x46: picked cell bytes, set by the board scan in k_fldResource.c */
    u8 unk48[0x04];
    s32 boardParam;        /* 0x4C: argument to FldBoardGenerate */
    u8 unk50[0x04];
    FldFrameCell cells[24][16]; /* 0x54: 24 rows of 16 cells, copied from the HBN table */
    u8 *auxBuffer;         /* 0x1854: buffer passed to scrStartProcedureChecked, released by FldAuxBufferRelease */
    u32 auxSize;           /* 0x1858: byte size of auxBuffer */
    u8 unk185C[0x08];
    u8 *hbnHandle;         /* 0x1864: HBN load handle; its +0x110 word is the loaded table */
    u8 unk1868[0x70];
    u32 eventCount;        /* 0x18D8: entry count of eventTable; checked against the event index */
    u8 *eventTable;        /* 0x18DC: FLD_EVT_TABLE, 0x2C-byte FldEvtEntry array */
    u16 *secondaryTable;   /* 0x18E0: NpcTable_InstallSecondaryTable copy */
    u32 secondaryTableSize; /* 0x18E4: byte size of secondaryTable */
    u8 *sceneTable;        /* 0x18E8: NpcTable_InstallSceneTable copy */
    s32 sceneCount;        /* 0x18EC: first word of the scene table */
    u8 *sceneEntries;      /* 0x18F0: sceneTable + 0x20 */
    u8 *sceneEntriesEnd;   /* 0x18F4: sceneEntries + sceneCount * 0x20 */
} FldFrame;

#endif
