/* Source unit: src/fmGslCont_0026e0e0.c */
#include "type.h"

typedef int (*code)();
extern code DAT_008873ec_abs[];

extern u64 memcpy();
extern u32 DAT_00764590;



/* Both active and free pool lists use two 32-bit link addresses at +0/+4. */
typedef struct FmGslLink {
    s32 previous;
    union { u32 word; s32 address; s32 *pointer; } next;
} FmGslLink;

// Intent: Pop the head node from a singly linked list and return its payload pointer, or NULL when empty [inferred]
// FUN_0026E0E0
int* fmGslContPopNode(int listAddress)
{
    int* node;
    int* list;

    list = (int*)listAddress;
    node = (int*)list[1];

    if (*node == 0) {
        node = (int*)0x0;
    }
    else {
        list[1] = node[1];
        node[1] = 0;
        node = node + 2;
    }

    return node;
}



// Intent: Push a node onto a singly linked list; returns 1 when pushed, 0 when the node is NULL or already linked [inferred]
// FUN_0026E120
u32 fmGslContPushNode(int* payload, int listAddress)
{
    u32 inserted;
    int* node;

    if (payload == 0) {
        inserted = 0;
    }
    else {
        node = payload - 2;

        if (node[1] != 0) {
            inserted = 0;
        }
        else {
            node[1] = ((FmGslLink *)listAddress)->next.word;
            ((FmGslLink *)listAddress)->next.address = (int)node;
            inserted = 1;
        }
    }

    return inserted;
}




// Intent: Free a node's block through the free callback and return 1 [inferred]
// FUN_0026E170
u32 fmGslContFreeNode(int payloadAddress)
{
    /* The allocation pointer is stored one word before the externally returned payload. */
    DAT_008873ec_abs[0](*(u32*)(payloadAddress + -4));
    return 1;
}



// Intent: Compute three sub-block pointers from a block header and store them in the output array [inferred]
// FUN_0026E1A0
void fmGslContSetupSubBlocks(int* block, int* subBlocks)
{
    int secondSize;
    int secondOffset;
    int thirdOffset;

    secondOffset = *block + block[1];
    secondSize = block[6];
    thirdOffset = secondOffset + secondSize;

    *subBlocks = (int)block + *block;
    subBlocks[1] = (int)block + secondOffset;
    subBlocks[2] = (int)block + thirdOffset;
}



// Intent: Decode a bit-packed tree run into output bytes using per-run bit offsets, and record the emitted count [inferred]
// FUN_0026E1E0
/* Packed bit offsets are copied unaligned; six-byte tree records encode branch indices and leaf bytes. The byte/halfword addressing preserves this on-disk encoding. */
int fmGslContDecodeRun(int outputAddress, int runIndex, u64 unused, int* tables)
{
    int treeAddress;
    int bitsAddress;
    int branchAddress;
    int nodeAddress;
    u32 bits;
    int outputCount;
    u32 wordIndex;
    int bitsRemaining;
    int rootBranches;
    u32 startBit;
    int endBit;

    treeAddress = *tables;
    outputCount = 0;
    memcpy(&startBit, tables[1] + runIndex * 4, 4);
    memcpy(&endBit, tables[1] + (runIndex + 1) * 4, 4);
    rootBranches = treeAddress + 2;
    branchAddress = rootBranches;
    bitsAddress = tables[2];
    wordIndex = startBit >> 4;
    bits = (int)(*(u16*)(bitsAddress + wordIndex * 2) | 0x10000) >> (startBit & 0xf);
    bitsRemaining = endBit - startBit;
    do {
        nodeAddress = treeAddress + (u32)*(u16*)(branchAddress + (bits & 1) * 2) * 6;
        branchAddress = nodeAddress + 2;
        if (*(u16*)(nodeAddress + 2) == 0) {
            memcpy(outputAddress + outputCount, branchAddress + 2, 1);
            outputCount = outputCount + 1;
            branchAddress = rootBranches;
        }
        bits = bits >> 1;
        if (bits == 1) {
            wordIndex = wordIndex + 1;
            bits = *(u16*)(bitsAddress + wordIndex * 2) | 0x10000;
        }
        bitsRemaining = bitsRemaining + -1;
    } while (bitsRemaining != 0);

    DAT_00764590 = outputCount;
    return outputCount;
}



// Intent: Build a doubly linked free list at the supplied stride and reset the active pool head and tail [inferred]
// FUN_002850F0
void fmGslContPoolInit(u32* pool, u32* storage, int nodeCount, int stride)
{
    int nodeIndex;
    u32* node;
    u32* previous;
    u32* next;

    nodeIndex = '\0';
    previous = (u32*)0x0;
    node = storage;

    do {
        *node = (u32)previous;
        next = (u32*)((int)node + stride);
        node[1] = (u32)next;
        node[2] = (int)(s8)nodeIndex;
        previous = node;
        node = next;
        nodeCount = nodeCount + -1;
        nodeIndex = (s8)(nodeIndex + 1);
    } while (1 < nodeCount);

    *node = (u32)previous;
    node[1] = 0;
    node[2] = (int)(s8)nodeIndex;
    *pool = 0;
    pool[1] = 0;
    pool[2] = (u32)storage;
    pool[3] = (u32)node;
}



// Intent: Take the next node from a pool and link it at the tail; returns NULL when the pool is empty [inferred]
// FUN_00285170
int* fmGslContPoolAlloc(int* pool)
{
    u32* nextFree;
    int* node;

    node = (int*)pool[2];

    if (node == (int*)0x0) {
        node = (int*)0x0;
    }
    else {
        nextFree = (u32*)node[1];

        if (*pool != 0) {
            *node = pool[1];
            ((FmGslLink *)pool[1])->next.pointer = node;
        }
        else {
            *node = 0;
            *pool = (int)node;
        }

        node[1] = 0;
        pool[1] = (int)node;

        if (nextFree != (u32*)0x0) {
            *nextFree = 0;
        }
        else {
            pool[3] = 0;
        }

        pool[2] = (int)nextFree;
    }

    return node;
}



// Intent: Unlink a node from its pool list, updating the head and tail [inferred]
// FUN_002851F0
void fmGslContPoolUnlink(int* node, u32* pool)
{
    int previousAddress;
    int* next;

    previousAddress = *node;
    next = (int*)node[1];

    if (previousAddress != 0) {
        ((FmGslLink *)previousAddress)->next.pointer = next;
    }
    else {
        *pool = (u32)next;
    }

    if (next != (int*)0x0) {
        *next = previousAddress;
    }
    else {
        pool[1] = previousAddress;
    }

    node[1] = 0;
    previousAddress = pool[3];
    *node = previousAddress;

    if (previousAddress != 0) {
        ((FmGslLink *)previousAddress)->next.pointer = node;
    }

    pool[3] = (u32)node;

    if (pool[2] == 0) {
        pool[2] = (u32)node;
    }
}
