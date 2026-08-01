/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonRing.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void func_0049a570(void *arg0);



// FUN_00498EC0
void func_00498ec0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}



// FUN_004996E0
void func_004996e0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 8));
    func_0049a570(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 0xC));
}



// FUN_00499DF0
void func_00499df0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}
