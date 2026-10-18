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




// FUN_001FC2C0
/* Stores two words in the file-state globals at 0x881440 and 0x881444. */
void mdlSetFileStatePair(u32 first, u32 second)
{
    DAT_00881440_abs[0] = first;
    DAT_00881444_abs[0] = second;
}




// FUN_001FC2E0
/* Stores three words in the next three file-state globals. */
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
/* Raw fields retain MATCH: typed count/index accesses enlarged this body from 144 to 152 bytes.
 * The proven s32 count/index pair is at 0x28/0x2C. */
// FUN_00498C50
void mdlAdvanceObjectCallback(int object)
{
    int count;
    int address;

    address = object;
    D_00713e7c[*(int *)(address + 0x2c)].callback();
    count = *(int *)(address + 0x28) + 1;
    *(int *)(address + 0x28) = count;
    if (count > 0)
    {
        D_00713e80[*(int *)(address + 0x2c)].callback(object);
    }
}



/* Advance the alternate callback state's count between its two callback stages. */
/* Raw fields retain MATCH: typed count/index accesses enlarged this body from 144 to 152 bytes.
 * The proven s32 count/index pair is at 0x34/0x38. */
// FUN_0049A710
void mdlAdvanceStateCallback(int object)
{
    int count;
    int address;

    address = object;
    D_00713f1c[*(int *)(address + 0x38)].callback();
    count = *(int *)(address + 0x34) + 1;
    *(int *)(address + 0x34) = count;
    if (count > 0)
    {
        D_00713f20[*(int *)(address + 0x38)].callback(object);
    }
}
