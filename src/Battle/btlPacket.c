/* Source unit: src/Battle/btlPacket.c */
#include "include_asm.h"
#include "type.h"

typedef void (*BtlPacketCallback)(void* data);

typedef struct BtlPacketCallbackWork BtlPacketCallbackWork;
struct BtlPacketCallbackWork
{
    BtlPacketCallback callback;
    void* data;
};

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    RwV3d imag;
    f32 real;
};

typedef struct RwRGBA RwRGBA;
struct RwRGBA
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

typedef struct BtlUnit BtlUnit;
struct BtlUnit
{
    u8 _pad00[0x04];
    RwV3d pos;           // 0x04
    RwV3d posOffset;     // 0x10
    RtQuat rot;          // 0x1c
    f32 scale;           // 0x2c
    RwRGBA cols[5];      // 0x30
    u8 unk_44[0x08];     // 0x44
    u16 unk_4c;          // 0x4c
    u8 unk_4e[0x06];     // 0x4e
    RwV3d unk_54;        // 0x54
    u8 unk_60[0x10];     // 0x60
    RtQuat unk_70;       // 0x70
};

extern RwV3d D_00881430;



// FUN_00194C60
void func_00194c60(BtlPacketCallbackWork* work)
{
    work->callback(work->data);
}



/* measured probe: opt_loop_invariants on hoists the wait-type constant into the loop preheaders. */
#pragma opt_loop_invariants on
// FUN_00194C90
u8 *func_00194c90(void *arg0, void *arg1)
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

    extern void func_0044ea90(const void *file, s32 line);
    extern void func_0043f9c8(void *dst, s32 value, u32 size);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern u8 D_005F6C00[];

    size = sizeof(BtlPacket) + sizeof(BtlPacketCallbackWork);
    func_0044ea90(&D_005F6C00, 0x51);
    packet = (BtlPacket *)jtbl_008873E8[0](size, 0x40000);
    func_0043f9c8(packet, 0, size);
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
    packet->updateFunc = (BtlPacketCallback)func_00194c60;
    callbackWork = (BtlPacketCallbackWork *)packet->workData;
    callbackWork->callback = (BtlPacketCallback)arg0;
    callbackWork->data = arg1;
    return (u8 *)packet;
}
/* measured probe: closes the opt_loop_invariants scope for func_00194c90. */
#pragma opt_loop_invariants off
// FUN_00194DC0
void func_00194dc0(BtlUnit* unit)
{
    unit->scale = 1.0f;
    unit->pos = D_00881430;
    unit->posOffset = D_00881430;

    unit->rot.real = 1.0f;
    unit->rot.imag.x = 0.0f;
    unit->rot.imag.y = 0.0f;
    unit->rot.imag.z = 0.0f;

    unit->cols[0].r = 0xff;
    unit->cols[0].g = 0xff;
    unit->cols[0].b = 0xff;
    unit->cols[0].a = 0xff;
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
