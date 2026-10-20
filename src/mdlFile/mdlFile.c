/* Source unit: src/mdlFile/mdlFile_001fc2c0.c (1 function markers) */
#include "type.h"
extern u32 DAT_00881440_abs[];
extern u32 DAT_00881444_abs[];
extern u32 DAT_00881448_abs[];
extern u32 DAT_0088144c_abs[];
extern u32 DAT_00881450_abs[];
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef int (*MdlCallback)();

typedef struct MdlStridedCallback24 {
    MdlCallback callback;
    u8 next[0x14];
} MdlStridedCallback24;

extern MdlStridedCallback24 D_00713e7c[];
extern MdlStridedCallback24 D_00713e80[];

extern MdlStridedCallback24 D_00713f1c[];
extern MdlStridedCallback24 D_00713f20[];


/* Partial layouts: only the fields accessed by these helpers are established. */
typedef struct MdlEffectObject {
    u8 pad00[0x40];
    u_long128 position;
    u_long128 orientation;
    u8 pad60[4];
    u32 packedColor;
} MdlEffectObject;

typedef struct MdlCallbackObject {
    u8 pad00[4];
    u32 unk04;
    u8 pad08[0x20];
    s32 count;
    s32 callbackIndex;
} MdlCallbackObject;

typedef struct MdlCallbackState {
    u8 pad00[0x34];
    s32 count;
    s32 callbackIndex;
} MdlCallbackState;




/* Publish the paired file-state words without changing the adjacent triple. */
// FUN_001FC2C0
void mdlSetFileStatePair(u32 first, u32 second)
{
    DAT_00881440_abs[0] = first;
    DAT_00881444_abs[0] = second;
}




/* Publish the three-word file state independently of the paired state. */
// FUN_001FC2E0
void mdlSetFileStateTriple(u32 first, u32 second, u32 third)
{
    DAT_00881448_abs[0] = first;
    DAT_0088144c_abs[0] = second;
    DAT_00881450_abs[0] = third;
}



// FUN_0047DE90
/* Dereferences the resource pointer then returns the first word of its payload. */
u32 mdlReadResourceHeaderWord(u32* resource)
{
    return *(u32*)*resource;
}



// Copies the 16-byte value at +0x40, the position (callers use its first three floats), into output and returns it.
// FUN_004866E0
u_long128 mdlEffectGetPositionVec(int object, u32 *output)
{
    u_long128 value = ((MdlEffectObject*)object)->position;
    *(u_long128 *)output = value;
    return value;
}



// Copies the 16-byte value at +0x50, the orientation vector that mdlEffectBuildObjectMatrix passes to mdlEffectBuildBasisRows, into output and returns it.
// FUN_004866F0
u_long128 mdlEffectGetOrientationVec(int object, u32 *output)
{
    u_long128 value = ((MdlEffectObject*)object)->orientation;
    *(u_long128 *)output = value;
    return value;
}



// Returns the packed colour word at +0x64. mdlEffectGetPackedColor reads it through this accessor.
// FUN_00486700
u32 mdlEffectGetPackedColorWord(void* object)
{
    return ((MdlEffectObject*)object)->packedColor;
}



// FUN_00489F40
/* Writes the object word at offset four. */
void mdlSetObjectHeaderValue(void* object, u32 value)
{
    ((MdlCallbackObject*)object)->unk04 = value;
}



/* Invoke the selected pre-callback, increment the count, then invoke its object callback when positive. */
// FUN_00498C50
void mdlAdvanceObjectCallback(int object)
{
    int count;
    int address;
    MdlCallbackObject *callbackObject = (MdlCallbackObject *)object;

    address = object;
    D_00713e7c[((MdlCallbackObject *)address)->callbackIndex].callback();
    count = ((MdlCallbackObject *)address)->count + 1;
    ((MdlCallbackObject *)address)->count = count;
    if (count > 0)
    {
        D_00713e80[callbackObject->callbackIndex].callback(object);
    }
}



/* Advance the alternate callback state's count between its two callback stages. */
// FUN_0049A710
void mdlAdvanceStateCallback(int object)
{
    int count;
    int address;
    MdlCallbackState *callbackState = (MdlCallbackState *)object;

    address = object;
    D_00713f1c[((MdlCallbackState *)address)->callbackIndex].callback();
    count = ((MdlCallbackState *)address)->count + 1;
    ((MdlCallbackState *)address)->count = count;
    if (count > 0)
    {
        D_00713f20[callbackState->callbackIndex].callback(object);
    }
}
