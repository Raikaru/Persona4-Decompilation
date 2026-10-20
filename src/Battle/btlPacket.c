#include "include_asm.h"
#include "type.h"
#include "btl_unit_internal.h"

typedef void (*BtlPacketCallback)(void* data);

typedef struct BtlPacketCallbackWork BtlPacketCallbackWork;
struct BtlPacketCallbackWork
{
    BtlPacketCallback callback;
    void* data;
};


extern RwV3d D_00881430;


// FUN_00194C60
void btlPacketCallbackRun(BtlPacketCallbackWork* work)
{
    work->callback(work->data);
}


/* measured: opt_loop_invariants on hoists the wait-type constant into the loop preheaders as retail
 * does. */
#pragma opt_loop_invariants on
/* Allocate and zero a battle packet with attached callback work, initialise its wait conditions,
 * and set it to run the given callback with data on update. */
// FUN_00194C90
/* Allocate a callback packet and its payload, initialize wait modes, and install the callback
 * dispatcher. */
u8 *btlPacketAllocZeroed(void *callback, void *data)
{
    typedef struct BtlPacketWaitCondition BtlPacketWaitCondition;
    struct BtlPacketWaitCondition
    {
        u8 type;
        u8 unk_01[7];
        u64 value;
    };
    typedef struct BtlPacket BtlPacket;
    struct BtlPacket
    {
        u8 unk_00;
        u8 unk_01[7];
        u64 parentUID;
        BtlPacketWaitCondition preUpdateWait;
        BtlPacketWaitCondition postUpdateWaits[2];
        u32 id;
        u8 type;
        u8 unk_45;
        u8 unk_46;
        u8 unk_47;
        s16 preUpdateDelay;
        s16 postUpdateDelay;
        s32 unk_4c;
        s32 unk_50;
        s32 unk_54;
        u64 uid;
        u64 actionUID;
        void *initFunc;
        BtlPacketCallback updateFunc;
        void *destroyFunc;
        void *conditionFunc;
        void *workData;
        void *next;
        void *prev;
        u8 unkData3[0x0c];
    };
    BtlPacket *packet;
    BtlPacketCallbackWork *callbackWork;
    u16 i;
    u16 j;
    u8 waitType;
    s32 size;

    extern void chkmemAllocSiteTag(const void *file, s32 line);
    extern void memset(void *dst, s32 value, u32 size);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern u8 D_005F6C00[];

    size = sizeof(BtlPacket) + sizeof(BtlPacketCallbackWork);
    chkmemAllocSiteTag(&D_005F6C00, 0x51);
    packet = (BtlPacket *)jtbl_008873E8[0](size, 0x40000);
    memset(packet, 0, size);
    packet->id = 0xFF01;
    waitType = 1;
    for (i = 0; i < 2; i++) {
        ((BtlPacketWaitCondition *)packet)[i].type = waitType;
    }
    {
        BtlPacketWaitCondition *wait;

        wait = packet->postUpdateWaits;
        for (j = 0; j < 2; j++) {
            wait[j].type = waitType;
        }
    }
    packet->workData = (u8 *)packet + sizeof(BtlPacket);
    packet->unk_47 |= 0x31;
    packet->updateFunc = (BtlPacketCallback)btlPacketCallbackRun;
    callbackWork = (BtlPacketCallbackWork *)packet->workData;
    callbackWork->callback = (BtlPacketCallback)callback;
    callbackWork->data = data;
    return (u8 *)packet;
}
/* measured: restores the unit setting after btlPacketAllocZeroed. */
#pragma opt_loop_invariants off
/* Reset a unit's scale, position, offset, rotation and colours to their default values. */
// FUN_00194DC0
/* Reset unit transform, color sets, light orientation and associated mode fields to their initial
 * values. */
void btlPacketResetUnit(BtlUnit* unit)
{
    unit->scale = 1.0f;
    unit->pos = D_00881430;
    unit->posOffset = D_00881430;

    unit->rot.real = 1.0f;
    unit->rot.imag.x = 0.0f;
    unit->rot.imag.y = 0.0f;
    unit->rot.imag.z = 0.0f;

    unit->cols[0].red = 0xff;
    unit->cols[0].green = 0xff;
    unit->cols[0].blue = 0xff;
    unit->cols[0].alpha = 0xff;
    unit->cols[1] = unit->cols[0];
    unit->cols[3] = unit->cols[0];
    unit->cols[4] = unit->cols[0];

    unit->unk_4c = 0;
    unit->unk_54 = D_00881430;
    unit->unk_70.imag.x = 0.0f;
    unit->unk_70.imag.y = 0.0f;
    unit->unk_70.imag.z = 0.0f;
    unit->unk_70.real = 0.5f;
}
