/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonTrack.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00486e10(void *arg0);
extern void func_00494680(void *arg0);
extern void func_00492cd0(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);



// FUN_00493320
void func_00493320(u8 *arg0)
{
    u32 temp_4;
    u32 temp_4_2;
    u8 *temp_4_3;

    temp_4 = *(u32 *)(arg0 + 0x2C);
    if (temp_4 != 0) {
        func_00486e10((void *)temp_4);
    }
    temp_4_2 = *(u32 *)(arg0 + 0x28);
    if (temp_4_2 != 0) {
        func_00494680((void *)temp_4_2);
    }
    temp_4_3 = *(u8 **)(arg0 + 0x30);
    if (temp_4_3 != NULL) {
        func_00492cd0(temp_4_3);
    }
    jtbl_008873EC[0](arg0);
}
