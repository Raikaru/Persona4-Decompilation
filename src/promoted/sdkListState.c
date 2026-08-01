/* Consolidated Persona 4 source units. */
/* Original translation unit sdkListState.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_0046d730(void* message, u32 code);
extern s32 func_00453eb0(u8* obj, s32 value);
extern u32 D_007105E8[];



// FUN_00453CE0
void func_00453ce0(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0xF4);
    }
    if (arg1 < *(s32*)(arg0 + 0x20)) {
        *(s32*)(arg0 + 0x20) = arg1;
        func_00453eb0(arg0, *(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24));
        return;
    }
    *(s32*)(arg0 + 0x20) = arg1;
}



// FUN_00453D70
s32 func_00453d70(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x101);
    }
    return *(s32*)(arg0 + 0x28);
}



// FUN_00453DC0
s32 func_00453dc0(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x108);
    }
    return *(s32*)(arg0 + 0x24);
}



// FUN_00453E10
s32 func_00453e10(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x10F);
    }
    return *(s32*)(arg0 + 0x20);
}



// FUN_00453E60
s32 func_00453e60(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x116);
    }
    return *(s32*)(arg0 + 0x14);
}
