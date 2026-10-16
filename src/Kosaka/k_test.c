/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "sdk_task_registration.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005F5718[];
extern u8 D_00763098;

extern void chkmemAllocSiteTag(void *msg, s32 id);

extern void mdlDestroyModelObject(s32 handle);
extern void *memset(void *dest, s32 value, s32 size);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);
extern s32 *MT_Scene_GetFrameState(void);
extern s32 FldLoadTaskIsDone(s32 handle);
extern s32 func_0015f660(void);

extern s32 func_0018e450(u8 *arg0);
extern void func_0018e4d0(u8 *arg0);

typedef struct
{
    u16 field0;    // 0x00
    u16 field1;    // 0x02
    s16 field2;    // 0x04
    s16 field3;    // 0x06
    s16 field4;    // 0x08
    u8 pad[0x12];  // 0x0A
} TestMenuMsg;

// FUN_0018E520
void K_Test_CreateLauncher(s32 arg0)
{
    chkmemAllocSiteTag(D_005F5718, 0x7A);
    (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_00763098), 0xF, 0, 0, func_0018e450, func_0018e4d0, (u8 *)(D_008873F4[0](1, 0x1C, 0x40000)));
}

// FUN_0018E5B0
s32 K_Test_Update(u8 *arg0)
{
    u32 *p;
    u32 state;
    TestMenuMsg msg;

    p = *(u32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
        *p = state + 1;
        break;
    case 1:
    case 2:
    case 3:
        *p = state + 1;
        break;
    case 4:
        if (FldLoadTaskIsDone(*MT_Scene_GetFrameState()) != 0 && func_0015f660() != 0) {
            memset(&msg, 0, 0x1C);
            msg.field0 = 6;
            msg.field1 = 6;
            msg.field2 = 0;
            msg.field4 = 0;
            func_001029a0(9, &msg, 0x1C, 3);
            *p += 1;
        }
        break;
    case 5:
    case 6:
    case 7:
        *p = state + 1;
        break;
    case 8:
        if (FldLoadTaskIsDone(*MT_Scene_GetFrameState()) != 0 && func_0015f660() != 0) {
            memset(&msg, 0, 0x1C);
            msg.field0 = 6;
            msg.field1 = 2;
            msg.field2 = 5;
            msg.field4 = 0;
            func_001029a0(9, &msg, 0x1C, 3);
            *p = 1;
        }
        break;
    }
    return 0;
}

// FUN_0018E730
void K_Test_Destroy(u8 *arg0)
{
    u8 *p;
    s32 v;

    p = *(u8 **)(arg0 + 0x38);
    v = *(s32 *)(p + 4);
    if (v != 0) {
        mdlDestroyModelObject(v);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018E780
void K_Test_Create(s32 arg0)
{
    chkmemAllocSiteTag(D_005F5718, 0xE0);
    (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_00763098), 0x12, 0, 0, K_Test_Update, K_Test_Destroy, (u8 *)(D_008873F4[0](1, 0x1C, 0x40000)));
}
