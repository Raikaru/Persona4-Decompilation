#ifndef FIELD_FRAME_INTERNAL_H
#define FIELD_FRAME_INTERNAL_H
#include "type.h"

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
    u8 unk34[0x1820];
    u8 *auxBuffer;         /* 0x1854: buffer passed to scrStartProcedureChecked, released by FldAuxBufferRelease */
    u32 auxSize;           /* 0x1858: byte size of auxBuffer */
    u8 unk185C[0x7C];
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
