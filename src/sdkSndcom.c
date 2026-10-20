/* Original translation unit sdkSndcom.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
#include "sdk_snd_internal.h"

typedef struct HCdvd HCdvd;

typedef struct HSfdDecodeSlot
{
    s16 state;
    s16 padding02;
    HCdvd* request;
    s16 fileIndex;
    s16 index;
    s32 queueHandle;       // 0x0C
    s32 outputHandle;      // 0x10
    s32 decodeHandle;      // 0x14
    s32 status;            // 0x18
    s32 input;            // 0x1C: IOP address, not an EE pointer
    u32 inputSize;         // 0x20
    s32 intermediate;     // 0x24: IOP address
    u32 intermediateSize;  // 0x28
    s32 output;           // 0x2C: IOP address
    u32 outputSize;        // 0x30
    void* resource;        // 0x34
    void* aux;             // 0x38
    void* sourceData;      // 0x3C
    s32 completion;       // 0x40: command result
} HSfdDecodeSlot;

extern HSfdDecodeSlot sSfdDecodeSlots_abs[];

typedef struct HSfdFileEntry
{
    u8 *path[3];
} HSfdFileEntry;


typedef struct SdkSndTransfer {
    void *data;
    s32 destination;
    s32 size;
    s32 status;
} SdkSndTransfer;

typedef struct SdkSndCommandStream {
    s32 active;
    s16 slotIndex;
    u8 pad6[2];
    s32 handle;
} SdkSndCommandStream;
/* Per-stream state tables (byte-indexed; stride 0x44 for the slot tables). */
extern u8 D_008E3FC0[];
extern u8 D_008E3FC4[];
extern u8 D_008E3FC8[];
extern u8 D_008E3FCC[];
extern u8 D_008E3FD0[];
extern u8 D_008E3FD4[];
extern u8 D_008E3FD8[];
extern u8 D_008E4090[];
extern u8 D_008E4098[];
extern u8 D_008E409C[];
extern u8 D_008E40A0[];
extern u8 D_008E40A4[];
extern u8 D_008E40A8[];
extern u8 D_008E40AC[];
extern u8 D_008E40B0[];
extern u8 D_008E40B8[];
extern u8 D_008E40BC[];
extern u8 D_008E40C0[];
extern u8 D_008E40C4[];
extern u8 D_008E40C8[];
extern u8 D_008E40CC[];
extern u8 D_008E40D0[];
extern u8 D_008D3FD0[];
extern HSfdFileEntry D_00712390[];

/* Debug strings (absolute) and small-data format strings (gp-relative). */
extern char D_007123C0[];
extern char D_007123E8[];
extern char D_007123F8[];
extern char D_00712408[];
extern char D_00712418[];
extern char D_00712428[];
extern char D_00712440[];
extern char D_00712458[];
extern char D_00712470[];
extern char D_00764020;
extern char D_00764028;
extern char D_00764030;

/* Sony SDK PS2 sound-library helpers (shared blob). */
extern void func_00440b68(const void *format, ...);
extern void kAssertFail(void *file, s32 line);
extern void kAssertFailAt(const void *msg, const void *file, u32 line);
extern void func_00421a60();
extern s32 func_00424708();
extern s32 func_00421b80();
extern void func_0043c470();
extern void func_0043c308();
extern s32 func_00429d90(s32 address);
extern s32 func_0043c5e8(s32 handle, ...);
extern s32 func_0043c518(s32 handle, ...);
extern s32 func_00429d10(s32 mode, u32 size, s32 address);
extern s32 func_0043c180(s32 command, ...);
extern s32 func_0043c230(s32 command, ...);
extern s32 func_0043c3b0(s32 command, ...);
extern void memcpy(void *destination, const void *source, u32 size);
extern HCdvd *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern u32 H_Cdvd_Destroy(HCdvd *cdvd);
extern u32 H_Cdvd_IsFileLoaded(const HCdvd *cdvd);
/* The existing file-cache API encodes both paths/sentinels and returned EE addresses as s32. */
extern s32 H_Cdvd_LookupRequest(s32 pathAddress, s32 *slot);

s32 sdkSndTransferToIop(s32 handle, void *data, s32 size);
void sdkSndReleaseDecodeSlot(s16 index);

/* Submits a transfer command for the supplied IOP destination and EE source data and waits for completion. */
/* measured: normalizing the remaining interior-symbol slot accesses changes owner instructions; retain their absolute field aliases. */
// FUN_0045B650
s32 sdkSndTransferToIop(s32 handle, void *data, s32 size)
{
    s32 status;
    s32 queueHandle;

    if (size <= 0) {
        return 0;
    }
    *(void **)&D_008E3FC0[0] = data;
    ((SdkSndTransfer *)D_008E3FC0)->destination = handle;
    ((SdkSndTransfer *)D_008E3FC0)->size = size;
    ((SdkSndTransfer *)D_008E3FC0)->status = 0;
    func_00440b68(D_007123C0, data, handle, size);
    func_00440b68(&D_00764020);
    func_00421a60(0);
    func_00440b68(D_007123E8);
    queueHandle = func_00424708(&D_008E3FC0[0], 1);
    func_00440b68(D_007123F8, queueHandle);
    if (queueHandle == 0) {
        kAssertFail(D_00712408, 0xF0);
    }
    do {
        status = func_00421b80(queueHandle);
    } while (status >= 0);
    for (;;) {
        status = func_00421b80(queueHandle);
        if (status > 0) {
            func_00440b68(&D_00764028);
            continue;
        }
        if (status == 0) {
            func_00440b68(D_00712418);
            continue;
        }
        break;
    }
    func_00440b68(D_00712428);
    return size;
}

/* measured: b210 -O2, 2408B body/2416B window, eight zero alignment bytes.
 * Explicit state/payload scopes preserve the request and payload-field addresses
 * across calls. CSE off retains the retail slot-base rematerialization; propagation
 * off preserves the signed index and transfer-size snapshots rather than duplicating
 * their loads. The three payload stages have independent transfer cursors. */
/* Advances six decode slots through file or memory payload transfers and decoder creation. */
// FUN_0045B7C0
#pragma push
/* measured: baseline removal differs by 509 words; indexed-slot and single-toggle probes also fail. */
#pragma opt_propagation off
#pragma opt_common_subs off
void sdkSndUpdateDecodeSlots(void)
{
    s32 size;
    s16 fileIndex;
    HSfdFileEntry *fileEntry;
    s16 i;
    s32 slotIndex;
    HSfdDecodeSlot *slot;

    for (i = 0; (slotIndex = i) < 6; i++) {
        s32 slotOffset = slotIndex * (s32)sizeof(HSfdDecodeSlot);
        HSfdDecodeSlot *slotBase = sSfdDecodeSlots_abs;
        slot = (HSfdDecodeSlot *)((u8 *)slotBase + slotOffset);
        switch (slot->state) {
        case 0:
            slot->state = 1;
            break;
        case 2:
            func_00440b68(&D_00764030, D_00712408, 0x11F);
            slot = &sSfdDecodeSlots_abs[i];
            fileIndex = slot->fileIndex;
            fileEntry = &D_00712390[fileIndex];
            slot->request = H_Cdvd_AcquireDirectory(fileEntry->path[0], 0);
            slot->state = 3;
            break;
        case 3:
            if (H_Cdvd_IsFileLoaded(slot->request)) {
                u8 *source;
                s32 address;
                HCdvd **request;

                fileIndex = slot->fileIndex;
                fileEntry = &D_00712390[fileIndex];
                source = (u8 *)H_Cdvd_LookupRequest((s32)fileEntry->path[0], &size);
                address = func_00429d10(0, size, 0);
                if (!address) {
                    kAssertFail(D_00712408, 0x129);
                }
                memcpy(D_008D3FD0, source, size);
                sdkSndTransferToIop(address, D_008D3FD0, size);
                slot = &sSfdDecodeSlots_abs[i];
                request = &slot->request;
                H_Cdvd_Destroy(*request);
                slot->input = address;
                slot->inputSize = size;
                *request = 0;
                slot->state = 4;
            }
            break;
        case 4:
            func_00440b68(&D_00764030, D_00712408, 0x136);
            slot = &sSfdDecodeSlots_abs[i];
            fileIndex = slot->fileIndex;
            fileEntry = &D_00712390[fileIndex];
            slot->request = H_Cdvd_AcquireDirectory(fileEntry->path[1], 0);
            slot->state = 5;
            break;
        case 5:
            if (H_Cdvd_IsFileLoaded(slot->request)) {
                s32 destination;
                s32 remaining;
                s32 address;
                u8 *source;
                s32 transferred;
                HCdvd **request;

                fileIndex = slot->fileIndex;
                fileEntry = &D_00712390[fileIndex];
                source = (u8 *)H_Cdvd_LookupRequest((s32)fileEntry->path[1], &size);
                address = func_00429d10(0, 0x1000, 0);
                if (!address) {
                    kAssertFail(D_00712408, 0x140);
                }
                slot = &sSfdDecodeSlots_abs[i];
                destination = slot->intermediate;
                remaining = size;
                slot->intermediateSize = remaining;
                do {
                    if (remaining > 0x1000) {
                        size = 0x1000;
                        remaining -= 0x1000;
                    } else {
                        size = remaining;
                        remaining = 0;
                    }
                    sdkSndTransferToIop(address, source, size);
                    func_0043c180(1, address, destination, size);
                    transferred = size;
                    source += transferred;
                    destination += transferred;
                } while (remaining);
                slot = &sSfdDecodeSlots_abs[i];
                request = &slot->request;
                H_Cdvd_Destroy(*request);
                *request = 0;
                func_00429d90(address);
                slot->state = 6;
            }
            break;
        case 6:
            func_00440b68(&D_00764030, D_00712408, 0x15B);
            slot = &sSfdDecodeSlots_abs[i];
            fileIndex = slot->fileIndex;
            fileEntry = &D_00712390[fileIndex];
            slot->request = H_Cdvd_AcquireDirectory(fileEntry->path[2], 0);
            slot->state = 7;
            break;
        case 7:
            if (H_Cdvd_IsFileLoaded(slot->request)) {
                u8 *source;
                s32 address;
                HCdvd **request;
                s32 *output;
                u32 *outputSize;
                s32 *queue;
                s32 *handle;
                s32 *decode;

                fileIndex = slot->fileIndex;
                fileEntry = &D_00712390[fileIndex];
                source = (u8 *)H_Cdvd_LookupRequest((s32)fileEntry->path[2], &size);
                address = func_00429d10(0, size, 0);
                if (!address) {
                    kAssertFail(D_00712408, 0x165);
                }
                sdkSndTransferToIop(address, source, size);
                slot = &sSfdDecodeSlots_abs[i];
                request = &slot->request;
                H_Cdvd_Destroy(*request);
                output = &slot->output;
                *output = address;
                outputSize = &slot->outputSize;
                *outputSize = size;
                *request = 0;
                queue = &slot->queueHandle;
                if ((*queue = func_0043c230(3, -1, slot->input, slot->inputSize,
                                           slot->intermediate, slot->intermediateSize)) < 0) {
                    kAssertFail(D_00712408, 0x16F);
                }
                slot = &sSfdDecodeSlots_abs[i];
                handle = &slot->outputHandle;
                if ((*handle = func_0043c230(5, -1, *queue, 0)) < 0) {
                    kAssertFail(D_00712408, 0x174);
                }
                slot = &sSfdDecodeSlots_abs[i];
                decode = &slot->decodeHandle;
                if ((*decode = func_0043c3b0(0, -1, *output, *outputSize)) < 0) {
                    kAssertFail(D_00712408, 0x178);
                }
                slot = &sSfdDecodeSlots_abs[i];
                slot->completion = func_0043c3b0(5, *handle, *decode);
                slot->state = slot->status = 1;
            }
            break;
        case 8:
            {
                HSfdDecodeSlot *initial = slot;
                s32 *input;
                u32 *inputSize;
                s32 *intermediate;
                u32 *intermediateSize;
                s32 *output;
                u32 *outputSize;
                s32 *queue;
                s32 *handle;
                s32 *decode;
                {
                    u8 *source;
                    s32 address;
                    slot = &slotBase[i];
                    source = slot->resource;
                    inputSize = &slot->inputSize;
                    size = *inputSize;
                    address = func_00429d10(0, size, 0);
                    if (!address) {
                        kAssertFail(D_00712408, 0x189);
                    }
                    sdkSndTransferToIop(address, source, size);
                    slot = &sSfdDecodeSlots_abs[i];
                    input = &slot->input;
                    *input = address;
                    *inputSize = size;
                }
                {
                    s32 remaining;
                    s32 address;
                    u8 *source;
                    s32 destination;
                    s32 transferred;
                    source = slot->aux;
                    intermediateSize = &slot->intermediateSize;
                    size = *intermediateSize;
                    address = func_00429d10(0, 0x1000, 0);
                    if (!address) {
                        kAssertFail(D_00712408, 0x193);
                    }
                    intermediate = &initial->intermediate;
                    destination = *intermediate;
                    remaining = size;
                    do {
                        if (remaining > 0x1000) {
                            size = 0x1000;
                            remaining -= 0x1000;
                        } else {
                            size = remaining;
                            size = ((size + 0x7F) / 128) * 128;
                            remaining = 0;
                        }
                        sdkSndTransferToIop(address, source, size);
                        func_0043c180(1, address, destination, size);
                        transferred = size;
                        source += transferred;
                        destination += transferred;
                    } while (remaining);
                    func_00429d90(address);
                }
                {
                    u8 *source;
                    s32 address;
                    slot = &sSfdDecodeSlots_abs[i];
                    source = slot->sourceData;
                    outputSize = &slot->outputSize;
                    size = *outputSize;
                    address = func_00429d10(0, size, 0);
                    if (!address) {
                        kAssertFail(D_00712408, 0x1AB);
                    }
                    sdkSndTransferToIop(address, source, size);
                    slot = &sSfdDecodeSlots_abs[i];
                    output = &slot->output;
                    *output = address;
                }
                queue = &slot->queueHandle;
                *queue = func_0043c230(3, -1, *input, *inputSize, *intermediate, *intermediateSize);
                handle = &slot->outputHandle;
                *handle = func_0043c230(5, -1, *queue, 0);
                decode = &slot->decodeHandle;
                *decode = func_0043c3b0(0, -1, *output, *outputSize);
                slot->completion = func_0043c3b0(5, *handle, *decode);
                slot->state = slot->status = 1;
            }
            break;
        default:
            break;
        }
    }
}
#pragma pop

/* Queues the selected file-entry triplet on a ready decode slot. */
/* measured: normalizing the remaining interior-symbol slot accesses changes owner instructions; retain their absolute field aliases. */
// FUN_0045C130
void sdkSndLoadDecodeFiles(s16 index, s16 fileIndex)
{
    if (*(s16 *)&D_008E4090[index * 0x44] == 1) {
        if (*(void **)&D_008E40A8[index * 0x44] != 0) {
            sdkSndReleaseDecodeSlot(index);
        }
        sSfdDecodeSlots_abs[index].fileIndex = fileIndex;
        *(s16 *)&D_008E4090[index * 0x44] = 2;
        return;
    }
    kAssertFailAt(D_00712440, D_00712408, 0x1D0);
}

/* Queues three supplied memory payloads and their sizes on a ready decode slot. */
/* measured: normalizing the remaining interior-symbol slot accesses changes owner instructions; retain their absolute field aliases. */
// FUN_0045C210
void sdkSndLoadDecodeBuffers(s16 index, s16 fileIndex, void *data0, u32 data0Size, void *data1, u32 data1Size,
                   void *data2, u32 data2Size)
{
    if (*(s16 *)&D_008E4090[index * 0x44] == 1) {
        if (*(void **)&D_008E40A8[index * 0x44] != 0) {
            sdkSndReleaseDecodeSlot(index);
        }
        sSfdDecodeSlots_abs[index].fileIndex = fileIndex;
        *(s16 *)&D_008E4090[index * 0x44] = 8;
        *(void **)&D_008E40C4[index * 0x44] = data0;
        *(void **)&D_008E40C8[index * 0x44] = data1;
        *(void **)&D_008E40CC[index * 0x44] = data2;
        sSfdDecodeSlots_abs[index].inputSize = data0Size;
        sSfdDecodeSlots_abs[index].intermediateSize = data1Size;
        sSfdDecodeSlots_abs[index].outputSize = data2Size;
        return;
    }
    kAssertFailAt(D_00712440, D_00712408, 0x1E9);
}

// FUN_0045C390
u32 sdkSndIsDecodeSlotReady(s16 index)
{
    return sSfdDecodeSlots_abs[index].state == 1;
}

/* Releases a ready slot decoder and its queue and IOP payload allocations. */
/* measured: normalizing the remaining interior-symbol slot accesses changes owner instructions; retain their absolute field aliases. */
// FUN_0045C3D0
void sdkSndReleaseDecodeSlot(s16 index)
{
    s32 slotOffset;
    void **statusPointer;

    slotOffset = index * 0x44;
    if (((HSfdDecodeSlot *)((u8 *)sSfdDecodeSlots_abs + slotOffset))->state == 1) {
        statusPointer = (void **)&D_008E40A8[slotOffset];
        if (*statusPointer != 0) {
            func_0043c470(5, *(s32 *)&D_008E40D0[slotOffset]);
            func_0043c470(0, *(s32 *)&D_008E40A4[slotOffset]);
            func_0043c308(5, *(s32 *)&D_008E40A0[slotOffset]);
            func_0043c308(3, *(s32 *)&D_008E409C[slotOffset]);
            *statusPointer = 0;
            func_00429d90((s32)*(void **)&D_008E40AC[slotOffset]);
            func_00429d90((s32)*(void **)&D_008E40BC[slotOffset]);
        }
        *statusPointer = 0;
        return;
    }
    kAssertFailAt(D_00712440, D_00712408, 0x21C);
}

/* Stop an active decoder stream and clear its per-stream active flag. */
/* measured: normalizing the remaining interior-symbol slot accesses changes owner instructions; retain their absolute field aliases. */
// FUN_0045C510
void sdkSndStopStreamSlot(s16 index, s16 stream)
{
    s32 slotOffset;
    s32 *activePointer;
    s32 result;

    slotOffset = index * 0x44;
    if (*(s16 *)&D_008E4090[slotOffset] == 1 && *(void **)&D_008E40A8[slotOffset] != 0) {
        activePointer = &((SdkSndCommandStream *)(D_008E3FD0 + stream * 0xC))->active;
        if (*activePointer != 0) {
            result = func_0043c5e8(*(s32 *)&D_008E40A0[slotOffset], 1, 0xA, *(s32 *)&D_008E3FD8[stream * 0xC]);
            switch (result) {
            case 0:
            case -0x12B:
                func_0043c518(*(s32 *)&D_008E40A0[slotOffset], 2, 0xA,
                              *(s32 *)&D_008E3FD8[stream * 0xC]);
                break;
            default:
                func_00440b68(D_00712458, result);
                break;
            }
            *activePointer = 0;
        }
    }
}

/* measured: 552B/560B, all 32 relocations resolved; eight zero-tail bytes.
   Preserve the separate pre-stop and post-stop address computations and
   the output-handle load before the final halfword argument promotions. */
#pragma push
/* measured: baseline removal differs by 98 words; sizeof indexing and either single-toggle probe also fail. */
#pragma opt_propagation off
#pragma opt_common_subs off
/* measured: normalizing the remaining interior-symbol slot accesses changes owner instructions; retain their absolute field aliases. */
// FUN_0045C640
void sdkSndStartStreamSlot(s16 index, s16 stream, s16 value, s16 flags)
{
    s32 slotOffset;
    s32 state;
    s32 status;
    s32 *streamActive;
    s32 *streamHandle;
    s32 *handlePointer;
    s32 result;
    s32 streamOffset;
    s32 outputHandle;
    s32 active;
    s32 ready;
    s32 previousOffset;

    slotOffset = index * 0x44;
    state = ((HSfdDecodeSlot *)((u8 *)sSfdDecodeSlots_abs + slotOffset))->state;
    ready = 1;
    if (state == ready) {
        status = *(s32 *)&D_008E40A8[slotOffset];
        if (status != 0) {
            previousOffset = stream * 0xC;
            streamActive = &((SdkSndCommandStream *)(D_008E3FD0 + previousOffset))->active;
            active = *streamActive;
            if ((active != 0) && (state == ready) && (status != 0) && (active != 0)) {
                streamHandle = (s32 *)&D_008E3FD8[previousOffset];
                handlePointer = (s32 *)&D_008E40A0[slotOffset];
                result = func_0043c5e8(*handlePointer, ready, 0xA, *streamHandle);
                switch (result) {
                case 0:
                case -0x12B:
                    func_0043c518(*handlePointer, 2, 0xA, *streamHandle);
                    break;
                default:
                    func_00440b68(D_00712458, result);
                    break;
                }
                *streamActive = 0;
            }
            streamOffset = stream * 0xC;
            *(s16 *)&D_008E3FD4[streamOffset] = index;
            *streamActive = 1;
            outputHandle = *(s32 *)&D_008E40A0[slotOffset];
            *(s32 *)&D_008E3FD8[streamOffset] = func_0043c518(
                outputHandle, 0, 0xA, (s32)value, (s32)flags);
            return;
        }
        kAssertFailAt(D_00712470, D_00712408, 0x283);
        return;
    }
    kAssertFailAt(D_00712470, D_00712408, 0x286);
}
#pragma pop
