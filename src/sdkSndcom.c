/* Consolidated Persona 4 source units. */
/* Original translation unit sdkSndcom.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

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
    void* input;           // 0x1C
    u32 inputSize;         // 0x20
    void* intermediate;    // 0x24
    u32 intermediateSize;  // 0x28
    void* output;          // 0x2C
    u32 outputSize;        // 0x30
    void* resource;        // 0x34
    void* aux;             // 0x38
    void* sourceData;      // 0x3C
    void* completion;      // 0x40
} HSfdDecodeSlot;

extern HSfdDecodeSlot sSfdDecodeSlots_abs[];



// FUN_0045B650
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045b650);

// FUN_0045B7C0
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045b7c0);

// FUN_0045C130
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045c130);

// FUN_0045C210
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045c210);
// FUN_0045C390
u32 func_0045c390(s16 index)
{
    return sSfdDecodeSlots_abs[index].state == 1;
}

// FUN_0045C3D0
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045c3d0);

// FUN_0045C510
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045c510);

// FUN_0045C640
INCLUDE_ASM("asm/nonmatchings/sdkSndcom", func_0045c640);
