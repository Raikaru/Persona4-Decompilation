#include "type.h"

typedef void (*BtlPacketCallback)(void* data);

typedef struct BtlPacketCallbackWork BtlPacketCallbackWork;
struct BtlPacketCallbackWork
{
    BtlPacketCallback callback;
    void* data;
};

// FUN_00194C60
void func_00194c60(BtlPacketCallbackWork* work)
{
    work->callback(work->data);
}
