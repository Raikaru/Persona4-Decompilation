#ifndef FIELD_FRAME_INTERNAL_H
#define FIELD_FRAME_INTERNAL_H
#include "type.h"

/* Field frame state, returned by MT_Scene_GetFrameState(). Only the offsets
 * read or written by name in the field code are typed; the rest keep their
 * measured extent and are not assumed to mean anything. A wrong offset changes
 * the generated code and fails the owner verify. */
typedef struct FldFrame {
    u8 unk00[0x04];
    s32 mainTask;          /* 0x04: task passed to FldFrame_SetStateFlags */
    u8 unk08[0x10];
    u8 *smapObject;        /* 0x18: passed to smapRefreshCells / smapSetPhase */
    u8 *frameObject;       /* 0x1C: object whose +0x38 work FldFrameObjSetActive writes */
    u8 unk20[0x10];
    u8 *panelTask;         /* 0x30: panel task, FldPanel2dSetState / FldPanel2dRelease */
    u8 unk34[0x1820];
    u8 *auxBuffer;         /* 0x1854: buffer released by func_00160440 */
    u8 unk1858[0x88];
    u16 *secondaryTable;   /* 0x18E0: NpcTable_InstallSecondaryTable copy */
    u32 secondaryTableSize; /* 0x18E4: byte size of secondaryTable */
    u8 *sceneTable;        /* 0x18E8: NpcTable_InstallSceneTable copy */
    s32 sceneCount;        /* 0x18EC: first word of the scene table */
    u8 *sceneEntries;      /* 0x18F0: sceneTable + 0x20 */
    u8 *sceneEntriesEnd;   /* 0x18F4: sceneEntries + sceneCount * 0x20 */
} FldFrame;

#endif
