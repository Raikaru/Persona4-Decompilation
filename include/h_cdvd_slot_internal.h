#ifndef H_CDVD_SLOT_INTERNAL_H
#define H_CDVD_SLOT_INTERNAL_H

#include "type.h"

/* File-device slots are allocated with a 0x90 stride. Open/read/write/seek
 * establish the 64-bit length and position and the descriptor at 0x74. */
typedef struct HCdvdFileSlot {
    s64 length;
    u8 pad08[8];
    s64 position;
    u8 pad18[0x18];
    u32 unk30;
    u8 pad34[4];
    u32 operation;
    u32 active;
    u8 pad40[0x10];
    void *context;
    u8 pad54[0x14];
    u8 *buffer;
    s32 bufferSize;
    u8 pad70[4];
    s32 descriptor;
    u8 pad78[0x18];
} HCdvdFileSlot;

/* The cache attachment copies 0x94 bytes at 0x70 of a 0x110-byte slot.
 * The stream reader addresses its payload pointer/size/cursor at F8/FC/100. */
typedef struct HCdvdMemorySlot {
    u64 length;
    u8 pad08[8];
    u64 position;
    u8 pad18[8];
    u64 unk20;
    u8 pad28[8];
    u32 unk30;
    u8 pad34[4];
    u32 operation;
    u32 active;
    u8 pad40[0xB8];
    u8 *fileMemory;
    s32 fileSize;
    s32 fileOffset;
    u8 pad104[0xC];
} HCdvdMemorySlot;

/* The file-device constructor allocates 0x5C and installs these callbacks. */
typedef struct HCdvdFileDevice {
    u8 pad00[0x14];
    void *slot;
    void *release;
    void *path;
    u8 pad20[8];
    void *open;
    void *close;
    void *read;
    void *write;
    void *seek;
    u8 pad3C[8];
    void *exitTest;
    u8 pad48[4];
    void *probe;
    u8 pad50[8];
    u8 *slots;
} HCdvdFileDevice;

#endif
