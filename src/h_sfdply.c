/* Source unit: src/h_sfdply_00466580.c */
#include "type.h"

typedef struct EeThreadStatus
{
    s32 status;
    u8 reserved4[0x2C];
} EeThreadStatus;

extern s32 func_0042ba70(void);
extern s32 func_0042ba20(void);
extern void func_004216e0(s32 threadId, EeThreadStatus* status);
extern void func_00421750(s32 threadId);

static s32 sSfdResumePending;
static s32 sSfdResumeThreadId;

#define HSFD_ENTRY_COUNT 256
#define HSFD_QUEUE_COUNT 1

typedef struct HCdvd HCdvd;

typedef struct HSfdAsyncEntry HSfdAsyncEntry;
typedef struct HSfdQueueSlot HSfdQueueSlot;

struct HSfdQueueSlot
{
    s16 state;
    s16 padding02;
    HSfdAsyncEntry* entry;
};

struct HSfdAsyncEntry
{
    HSfdAsyncEntry* next;
    HSfdQueueSlot* queue;
    void* source;
    void* resultC;
    void* resultD;
    void* resultE;
    void* resultF;
    void* resultG;
    u8 reserved20[4];
    char name[128];
    char path[128];
    char cacheName[128];
    s32 state;
    s32 requestFlags;
    s32 kind;
    HCdvd* request;
    void* result0;
    void* result1;
    s32 byteCount;
    void* buffer;
    void* result2;
    void* result3;
    void* result4;
    s16 age;
    u16 padding1D2;
    void* result5;
    u32 padding1D8;
};

typedef struct HSfdQueueEntry
{
    HSfdAsyncEntry* next;
    HSfdQueueSlot* queue;
    u8 reserved08[0x1d0];
} HSfdQueueEntry;

extern s32 func_004215e0(void* threadParam);
extern s32 func_00422920(s32 threadId, void* arg);
extern void func_00466e80(HSfdQueueSlot* slot);
extern u8 D_00902930[];
extern u32 D_007690F0;
extern s32 uGpffffb230;

static HSfdQueueEntry sSfdQueueEntries[1];
static s32 sSfdThreadIds[1];
static HSfdQueueSlot sSfdQueue[1];
static HSfdAsyncEntry sSfdEntries[HSFD_ENTRY_COUNT];



// FUN_00466580
void func_00466580(void)
{
    s32 wasEnabled;
    EeThreadStatus threadStatus;

    wasEnabled = func_0042ba70();
    if (sSfdResumePending != 0)
    {
        func_004216e0(sSfdResumeThreadId, &threadStatus);
        if ((threadStatus.status != 0xc) && (threadStatus.status != 8))
        {
            func_00421750(sSfdResumeThreadId);
        }
    }
    if (wasEnabled == 0)
    {
        func_0042ba20();
    }
}



// FUN_00466680
void func_00466680(void)
{
    typedef struct HSfdThreadParam
    {
        s32 status;
        void (*function)(HSfdQueueSlot*);
        void* stack;
        s32 stackSize;
        void* gpReg;
        s32 initialPriority;
        s32 currentPriority;
        u32 attributes;
        u32 option;
    } HSfdThreadParam;
    HSfdAsyncEntry* entries;
    HSfdQueueEntry* queueEntry;
    s16 entryIndex;
    s16 queueIndex;
    s32* threadIdSlot;
    HSfdThreadParam thread;

    entryIndex = 0;
    entries = sSfdEntries;
    while (entryIndex < HSFD_ENTRY_COUNT)
    {
        entries[entryIndex].next = NULL;
        entryIndex++;
    }

    for (queueIndex = 0; queueIndex < HSFD_QUEUE_COUNT; queueIndex++)
    {
        queueEntry = &sSfdQueueEntries[queueIndex];
        queueEntry->next = NULL;
        queueEntry->queue = NULL;
        sSfdQueue[queueIndex].state = 0;
        thread.function = func_00466e80;
        thread.stack = D_00902930;
        thread.stackSize = 0x20000;
        thread.gpReg = &D_007690F0;
        thread.initialPriority = 0x1C;
        threadIdSlot = &sSfdThreadIds[queueIndex];
        *threadIdSlot = func_004215e0(&thread);
        func_00422920(*threadIdSlot, &sSfdQueue[queueIndex]);
    }
    uGpffffb230 = 1;
}
