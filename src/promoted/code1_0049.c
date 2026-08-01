/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00492CD0)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00492CD0
void func_00492cd0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x28));
}
#endif /* P4_UNIT_00492CD0 */

#if defined(P4_UNIT_00493320)
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
#endif /* P4_UNIT_00493320 */

#if defined(P4_UNIT_00494680)
#include "type.h"

extern void func_004841c0(void *arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_00494680
void func_00494680(void *arg0)
{
    func_004841c0(*(void **)((u8 *)arg0 + 0x10));
    func_004841c0(*(void **)((u8 *)arg0 + 0x14));
    jtbl_008873EC[0](arg0);
}
#endif /* P4_UNIT_00494680 */

#if defined(P4_UNIT_00495090)
#include "type.h"

extern void func_00484280();

// FUN_00495090
void func_00495090(u8 *arg0, u32 arg1)
{
    func_00484280(*(void **)(arg0 + 0x10));
    func_00484280(*(void **)(arg0 + 0x14), arg1);
}
#endif /* P4_UNIT_00495090 */

#if defined(P4_UNIT_00498EC0)
#include "type.h"

extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_00498EC0
void func_00498ec0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}
#endif /* P4_UNIT_00498EC0 */

#if defined(P4_UNIT_004996E0)
#include "type.h"

extern void func_004833f0(void *arg0);
extern void func_0049a570(void *arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_004996E0
void func_004996e0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 8));
    func_0049a570(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 0xC));
}
#endif /* P4_UNIT_004996E0 */

#if defined(P4_UNIT_00499DF0)
#include "type.h"

extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_00499DF0
void func_00499df0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}
#endif /* P4_UNIT_00499DF0 */

#if defined(P4_UNIT_0049A9E0)
#include "type.h"

extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_0049A9E0
void func_0049a9e0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
#endif /* P4_UNIT_0049A9E0 */

#if defined(P4_UNIT_0049B640)
#include "type.h"

extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_0049B640
void func_0049b640(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
#endif /* P4_UNIT_0049B640 */

#if defined(P4_UNIT_0049C380)
#include "type.h"

extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);

// FUN_0049C380
void func_0049c380(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
#endif /* P4_UNIT_0049C380 */
