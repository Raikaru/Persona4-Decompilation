/* Consolidated Persona 4 source units. */
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
extern void func_0046d730(void *file, s32 line);
extern void func_0046d740(const void *msg, const void *file, u32 line);
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
extern HCdvd *func_00454a60(u8 *path, s32 mode);
extern u32 H_Cdvd_Destroy(HCdvd *request);
extern u32 H_Cdvd_IsFileLoaded(const HCdvd *request);
/* The existing file-cache API encodes both paths/sentinels and returned EE addresses as s32. */
extern s32 func_00455f70(s32 pathOrMode, s32 *size);

s32 func_0045b650(s32 handle, void *data, s32 size);
void func_0045c3d0(s16 index);

// FUN_0045B650
s32 func_0045b650(s32 handle, void *data, s32 size)
{
    s32 r;
    s32 q;

    if (size <= 0) {
        return 0;
    }
    *(void **)&D_008E3FC0[0] = data;
    *(s32 *)&D_008E3FC4[0] = handle;
    *(s32 *)&D_008E3FC8[0] = size;
    *(s32 *)&D_008E3FCC[0] = 0;
    func_00440b68(D_007123C0, data, handle, size);
    func_00440b68(&D_00764020);
    func_00421a60(0);
    func_00440b68(D_007123E8);
    q = func_00424708(&D_008E3FC0[0], 1);
    func_00440b68(D_007123F8, q);
    if (q == 0) {
        func_0046d730(D_00712408, 0xF0);
    }
    do {
        r = func_00421b80(q);
    } while (r >= 0);
    for (;;) {
        r = func_00421b80(q);
        if (r > 0) {
            func_00440b68(&D_00764028);
            continue;
        }
        if (r == 0) {
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
// FUN_0045B7C0
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_0045b7c0(void)
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
            slot->request = func_00454a60(fileEntry->path[0], 0);
            slot->state = 3;
            break;
        case 3:
            if (H_Cdvd_IsFileLoaded(slot->request)) {
                u8 *source;
                s32 address;
                HCdvd **request;

                fileIndex = slot->fileIndex;
                fileEntry = &D_00712390[fileIndex];
                source = (u8 *)func_00455f70((s32)fileEntry->path[0], &size);
                address = func_00429d10(0, size, 0);
                if (!address) {
                    func_0046d730(D_00712408, 0x129);
                }
                memcpy(D_008D3FD0, source, size);
                func_0045b650(address, D_008D3FD0, size);
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
            slot->request = func_00454a60(fileEntry->path[1], 0);
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
                source = (u8 *)func_00455f70((s32)fileEntry->path[1], &size);
                address = func_00429d10(0, 0x1000, 0);
                if (!address) {
                    func_0046d730(D_00712408, 0x140);
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
                    func_0045b650(address, source, size);
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
            slot->request = func_00454a60(fileEntry->path[2], 0);
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
                source = (u8 *)func_00455f70((s32)fileEntry->path[2], &size);
                address = func_00429d10(0, size, 0);
                if (!address) {
                    func_0046d730(D_00712408, 0x165);
                }
                func_0045b650(address, source, size);
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
                    func_0046d730(D_00712408, 0x16F);
                }
                slot = &sSfdDecodeSlots_abs[i];
                handle = &slot->outputHandle;
                if ((*handle = func_0043c230(5, -1, *queue, 0)) < 0) {
                    func_0046d730(D_00712408, 0x174);
                }
                slot = &sSfdDecodeSlots_abs[i];
                decode = &slot->decodeHandle;
                if ((*decode = func_0043c3b0(0, -1, *output, *outputSize)) < 0) {
                    func_0046d730(D_00712408, 0x178);
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
                        func_0046d730(D_00712408, 0x189);
                    }
                    func_0045b650(address, source, size);
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
                        func_0046d730(D_00712408, 0x193);
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
                        func_0045b650(address, source, size);
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
                        func_0046d730(D_00712408, 0x1AB);
                    }
                    func_0045b650(address, source, size);
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

// FUN_0045C130
void func_0045c130(s16 index, s16 fileIndex)
{
    if (*(s16 *)&D_008E4090[index * 0x44] == 1) {
        if (*(void **)&D_008E40A8[index * 0x44] != 0) {
            func_0045c3d0(index);
        }
        *(s16 *)&D_008E4098[index * 0x44] = fileIndex;
        *(s16 *)&D_008E4090[index * 0x44] = 2;
        return;
    }
    func_0046d740(D_00712440, D_00712408, 0x1D0);
}

// FUN_0045C210
void func_0045c210(s16 index, s16 fileIndex, void *data0, u32 data0Size, void *data1, u32 data1Size,
                   void *data2, u32 data2Size)
{
    if (*(s16 *)&D_008E4090[index * 0x44] == 1) {
        if (*(void **)&D_008E40A8[index * 0x44] != 0) {
            func_0045c3d0(index);
        }
        *(s16 *)&D_008E4098[index * 0x44] = fileIndex;
        *(s16 *)&D_008E4090[index * 0x44] = 8;
        *(void **)&D_008E40C4[index * 0x44] = data0;
        *(void **)&D_008E40C8[index * 0x44] = data1;
        *(void **)&D_008E40CC[index * 0x44] = data2;
        *(u32 *)&D_008E40B0[index * 0x44] = data0Size;
        *(u32 *)&D_008E40B8[index * 0x44] = data1Size;
        *(u32 *)&D_008E40C0[index * 0x44] = data2Size;
        return;
    }
    func_0046d740(D_00712440, D_00712408, 0x1E9);
}

// FUN_0045C390
u32 func_0045c390(s16 index)
{
    return sSfdDecodeSlots_abs[index].state == 1;
}

// FUN_0045C3D0
void func_0045c3d0(s16 index)
{
    s32 off;
    void **inp;

    off = index * 0x44;
    if (*(s16 *)&D_008E4090[off] == 1) {
        inp = (void **)&D_008E40A8[off];
        if (*inp != 0) {
            func_0043c470(5, *(s32 *)&D_008E40D0[off]);
            func_0043c470(0, *(s32 *)&D_008E40A4[off]);
            func_0043c308(5, *(s32 *)&D_008E40A0[off]);
            func_0043c308(3, *(s32 *)&D_008E409C[off]);
            *inp = 0;
            func_00429d90((s32)*(void **)&D_008E40AC[off]);
            func_00429d90((s32)*(void **)&D_008E40BC[off]);
        }
        *inp = 0;
        return;
    }
    func_0046d740(D_00712440, D_00712408, 0x21C);
}

// FUN_0045C510
void func_0045c510(s16 index, s16 stream)
{
    s32 off;
    s32 *p;
    s32 r;

    off = index * 0x44;
    if (*(s16 *)&D_008E4090[off] == 1 && *(void **)&D_008E40A8[off] != 0) {
        p = (s32 *)&D_008E3FD0[stream * 0xC];
        if (*p != 0) {
            r = func_0043c5e8(*(s32 *)&D_008E40A0[off], 1, 0xA, *(s32 *)&D_008E3FD8[stream * 0xC]);
            switch (r) {
            case 0:
            case -0x12B:
                func_0043c518(*(s32 *)&D_008E40A0[off], 2, 0xA,
                              *(s32 *)&D_008E3FD8[stream * 0xC]);
                break;
            default:
                func_00440b68(D_00712458, r);
                break;
            }
            *p = 0;
        }
    }
}

/* measured: 552B/560B, all 32 relocations resolved; eight zero-tail bytes.
   Preserve the separate pre-stop and post-stop address computations and
   the output-handle load before the final halfword argument promotions. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_0045C640
void func_0045c640(s16 index, s16 stream, s16 arg2, s16 arg3)
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
    state = *(s16 *)&D_008E4090[slotOffset];
    ready = 1;
    if (state == ready) {
        status = *(s32 *)&D_008E40A8[slotOffset];
        if (status != 0) {
            previousOffset = stream * 0xC;
            streamActive = (s32 *)&D_008E3FD0[previousOffset];
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
                outputHandle, 0, 0xA, (s32)arg2, (s32)arg3);
            return;
        }
        func_0046d740(D_00712470, D_00712408, 0x283);
        return;
    }
    func_0046d740(D_00712470, D_00712408, 0x286);
}
#pragma pop
