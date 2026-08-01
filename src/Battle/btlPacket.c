/* Source unit: src/Battle/btlPacket.c */
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
