#include "byte_address_internal.h"
#include "include_asm.h"
/* Original translation unit sdkChkmem.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct E8Node {
    struct E8Node *next;
    struct E8Node *prev;
} E8Node;

typedef struct ChkMemEntry {
    s32 size;   /* 0x00 */
    u16 alignment; /* 0x04 */
    s16 flags;     /* 0x06 */
    union {
        u16 classes;
        struct { u8 index, flags; } bytes;
    } classInfo; /* +0x08: class index in the low byte */
    u8 pad0A[2];
    E8Node link; /* tracking node at +0x0C */
    u8 pad14[4];
} ChkMemEntry;
typedef struct ChkMemPayload {
    ChkMemEntry *block;
    u8 data[];
} ChkMemPayload;

typedef char ChkMemEntrySizeCheck[sizeof(ChkMemEntry) == 0x18 ? 1 : -1];

typedef struct ChkMemPool {
    E8Node *first;           /* 0x00 */
    E8Node *last;            /* 0x04 */
    E8Node *current;         /* 0x08 */
    u8 pad_0C[0x0C];       /* 0x0C */
    s32 count;             /* 0x18 */
    s32 bytes;             /* 0x1C */
    u8 pad_20[0x10];       /* 0x20 */
    void (*fn_30)(void);   /* 0x30 */
    u16 classes;           /* 0x34 */
    s32 classBytes[8];     /* 0x38 */
    s32 classPayloadBytes[8]; /* 0x58 */
} ChkMemPool;

extern char D_007104E0[];
extern char D_007104F0[];
extern void kAssertFail(void *file, s32 line);
extern void kAssertFailMsg(const char *file, s32 line, const char *msg, ...);
extern s32 func_0043ece8(s32 size);
extern s32 func_0042ba20(void);
extern void func_0042ba70(void);
extern void memcpy(void *dst, void *src, s32 size);
extern void func_0043ed08(void *ptr);
extern s32 chkmemRegisterBlock(s32 blockAddress, s32 size, u16 alignment, s16 flags);
extern char iGpffffac30;
extern void memset(void *dst, s32 value, u32 size);

extern ChkMemPool *D_00763D1C; /* sdkChkmem pool */
extern s32 D_00764AC0;         /* sdkChkmem lock */

/* Append an allocation header node to the tracked-block chain. */
// FUN_0044E8D0
void chkmemPoolAppend(E8Node *node)
{
    ChkMemPool *pool;

    pool = D_00763D1C;
    if (pool->first == 0) {
        pool->last = node;
        D_00763D1C->first = node;
        node->prev = 0;
        node->next = 0;
        return;
    }
    node->next = pool->last;
    D_00763D1C->last = node;
    node->next->prev = node;
    node->prev = 0;
}

/* Unlink a tracked block and invalidate the traversal cursor if necessary. */
// FUN_0044E920
static void chkmemPoolUnlink(E8Node *node)
{
    E8Node *next;

    next = node->next;
    if (next == 0) {
        if (node->prev != 0) {
            D_00763D1C->first = node->prev;
            node->prev->next = 0;
            goto done;
        }
        D_00763D1C->last = 0;
        D_00763D1C->first = 0;
        goto done;
    }
    if (node->prev == 0) {
        if (next != 0) {
            D_00763D1C->last = next;
            node->next->prev = 0;
        } else {
            D_00763D1C->last = 0;
            D_00763D1C->first = 0;
        }
    } else {
        next->prev = node->prev;
        node->prev->next = node->next;
    }
done:
    if (node == D_00763D1C->current) {
        D_00763D1C->current = 0;
    }
}

/* Measured: object 168B / retail window 176B / normalized_diff 0; the final
 * 8B are retail zero-tail words. Keeping the allocator unlink helper static
 * in its recovered sdkChkmem translation unit preserves its narrow clobber
 * set. Staging the pool load before byteAddressAdd preserves the retail load and
 * offset-first addu order at both class-index updates. */
/* Remove allocation and class accounting before unlinking its header. */
/* Separate typed header aliases retain the measured class-accounting reload order. */
// FUN_0044E9E0
static void chkmemUntrackBlock(u8 *block)
{
    ChkMemEntry *header = (ChkMemEntry *)block;
    s32 bytes;
    u8 classIndex;
    u8 *classPayload;
    u8 *countPool;
    u8 *classPool;
    u8 *bytesPool;

    countPool = (u8 *)D_00763D1C;
    ((ChkMemPool *)countPool)->count = ((ChkMemPool *)countPool)->count - 1;
    bytesPool = (u8 *)D_00763D1C;
    bytes = ((ChkMemPool *)bytesPool)->bytes;
    ((ChkMemPool *)bytesPool)->bytes = bytes - ((ChkMemEntry *)block)->size;
    classIndex = ((ChkMemEntry *)block)->classInfo.bytes.index;
    if ((s32)classIndex < 8) {
        classPool = (u8 *)D_00763D1C;
        classPool = (u8 *)((u32)byteAddressAdd(classIndex * 4, (u8 *)((u32)classPool)));
        ((ChkMemPool *)classPool)->classBytes[0] =
            ((ChkMemPool *)classPool)->classBytes[0] - ((ChkMemEntry *)block)->size;
        bytes = ((ChkMemEntry *)block)->size - (((ChkMemEntry *)block)->alignment + 0x18);
        classPayload = (u8 *)((u32)byteAddressAdd(header->classInfo.bytes.index * 4, (u8 *)((u32)D_00763D1C)));
        ((ChkMemPool *)classPayload)->classPayloadBytes[0] = ((ChkMemPool *)classPayload)->classPayloadBytes[0] - bytes;
    }
    chkmemPoolUnlink(&((ChkMemEntry *)block)->link);
    header->classInfo.classes = 0;
}

// FUN_0044EA90
void chkmemAllocSiteTag(const void *file, s32 line) {}
/* measured: func_0044eaa0 matches with propagation disabled. The explicit
   class-size temporary preserves retail's classBytes load order. */
/* measured: baseline removal differs in 32 bytes; typed class-pool access; MEMBER block size and alignment reloads also differ. */
#pragma opt_propagation off
/* Register a block and store its header immediately before the aligned payload. */
/* The header back-pointer is payload-4 after variable alignment padding,
 * so it is not a fixed member of ChkMemEntry. */
// FUN_0044EAA0
s32 chkmemRegisterBlock(s32 blockAddress, s32 size, u16 alignment, s16 flags)
{
    ChkMemEntry *block;
    s32 payloadAddress;
    s32 classBytes;
    s32 *classPool;

    if (blockAddress == 0) {
        kAssertFail(D_007104E0, 0x4BA);
    }
    if (((u32)blockAddress & 3) != 0) {
        kAssertFail(D_007104E0, 0x4BB);
    }
    block = (ChkMemEntry *)blockAddress;
    block->size = size;
    block->alignment = alignment;
    block->flags = flags;
    payloadAddress = (s32)block + 24 +
              ((block->alignment - 1) &
               (block->alignment -
                (((s32)block + 24) & (block->alignment - 1))));
    if (((u32)payloadAddress & 3) != 0) {
        kAssertFail(D_007104E0, 0x4C0);
    }
    ((ChkMemPayload *)(payloadAddress - sizeof(ChkMemPayload)))->block = block;
    if (((s32)block & 3) != 0) {
        kAssertFail(D_007104E0, 0x4C4);
    }
    ++D_00763D1C->count;
    D_00763D1C->bytes += block->size;
    if ((u8)D_00763D1C->classes < 8) {
        classPool = (s32 *)(((u8)D_00763D1C->classes << 2) +
                          (s32)D_00763D1C);
        classBytes = block->size;
        ((ChkMemPool *)classPool)->classBytes[0] = ((ChkMemPool *)classPool)->classBytes[0] + classBytes;
        classBytes = block->size - (block->alignment + 24);
        D_00763D1C->classPayloadBytes[(u8)D_00763D1C->classes] += classBytes;
    }
    chkmemPoolAppend(&block->link);
    block->classInfo.classes = D_00763D1C->classes;
    return payloadAddress;
}
#pragma opt_propagation on
// FUN_0044EC30
s32 chkmemGetBytes(void) {
    return D_00763D1C->bytes;
}

// FUN_0044EC40
u16 chkmemGetClasses(void) {
    return D_00763D1C->classes;
}

// FUN_0044EC50
void chkmemSetLock(s32 locked) {
    D_00764AC0 = locked;
}

/* measured: func_0044ec60 (528B) floor at nd 34 — a saved-register rotation
   plus the same classBytes/classCount accounting block floored in func_0044eaa0.
   retail allocates block=temp_2 in $s2, aligned=temp_16_2/$s0 (reused), lock
   in $s1; mwcc b210 puts block in $s0, aligned in $s1, lock in $s2. Declaration
   order (8 orders probed), s32 vs u32 locked, cls local, and m2c decl order all
   stayed at 34 (worse 51 with cls local). Same class-block scheduling floor as
   func_0044eaa0 (locked->size RHS-first, classCount delta-before-pool-reload). */
/* measured: preserves retail allocator reload order. */
/* measured: baseline removal differs in 31 bytes; typed class-pool access; MEMBER block size and alignment reloads also differ. */
#pragma opt_propagation off
/* Allocate a sixteen-byte-aligned payload with tracked header and class totals. */
/* The header back-pointer is payload-4 after variable alignment padding,
 * so it is not a fixed member of ChkMemEntry. */
// FUN_0044EC60
s32 chkmemAllocate(u32 size)
{
    s32 lock;
    s32 allocationAddressOrSize;
    ChkMemEntry *block;
    s32 classBytes;
    s32 *classPool;

    lock = func_0042ba20();
    if (size == 0) {
        kAssertFail(D_007104E0, 0x653);
    }
    allocationAddressOrSize = (size + 0x37) & -0x10;
    block = (ChkMemEntry *)func_0043ece8(allocationAddressOrSize);
    if (block == NULL) {
        kAssertFailMsg(D_007104E0, 0x65F, D_007104F0, D_00763D1C->bytes,
                      size);
    }
    if (block == NULL) {
        kAssertFail(D_007104E0, 0x4BA);
    }
    if (((u32)block & 3) != 0) {
        kAssertFail(D_007104E0, 0x4BB);
    }
    block->size = allocationAddressOrSize;
    block->alignment = 0x10;
    block->flags = 0;
    allocationAddressOrSize = (s32)block + 24 +
              ((block->alignment - 1) &
               (block->alignment -
                (((s32)block + 24) & (block->alignment - 1))));
    if (((u32)allocationAddressOrSize & 3) != 0) {
        kAssertFail(D_007104E0, 0x4C0);
    }
    ((ChkMemPayload *)(allocationAddressOrSize - sizeof(ChkMemPayload)))->block = block;
    if (((s32)block & 3) != 0) {
        kAssertFail(D_007104E0, 0x4C4);
    }
    ++D_00763D1C->count;
    D_00763D1C->bytes += block->size;
    if ((u8)D_00763D1C->classes < 8) {
        classPool = (s32 *)(((u8)D_00763D1C->classes << 2) +
                          (s32)D_00763D1C);
        classBytes = block->size;
        ((ChkMemPool *)classPool)->classBytes[0] += classBytes;
        classBytes = block->size - (block->alignment + 24);
        D_00763D1C->classPayloadBytes[(u8)D_00763D1C->classes] += classBytes;
    }
    chkmemPoolAppend(&block->link);
    block->classInfo.classes = D_00763D1C->classes;
    if (lock != 0) {
        func_0042ba70();
    }
    return allocationAddressOrSize;
}
/* measured: func_0044ec60 matches with propagation disabled. */
#pragma opt_propagation on

/* Measured after restoring the recovered same-TU static func_0044e920:
 * object 256B / retail window 256B / normalized_diff 0. Static clobber
 * visibility keeps `block` live in $v0 across unlink, which emits the clear
 * before the following $a0 move exactly as retail. */
/* Recover the payload header, remove tracking, and free the underlying block. */
/* Separate typed header aliases retain the measured class-accounting reload order. */
// FUN_0044EE70
void chkmemFree(u8 *allocation)
{
    ChkMemEntry *header;
    s32 lock;
    u8 *block;
    u8 *pool;
    u8 *pool2;
    s32 size;
    s32 delta;
    u16 payload;
    s32 blockSize;
    u32 offset;

    lock = func_0042ba20();
    if (allocation == NULL) {
        kAssertFail(D_007104E0, 0x670);
    }
    block = (u8 *)((ChkMemPayload *)(allocation - sizeof(ChkMemPayload)))->block;
    header = (ChkMemEntry *)block;
    pool = (u8 *)D_00763D1C;
    ((ChkMemPool *)pool)->count = ((ChkMemPool *)pool)->count - 1;
    pool2 = (u8 *)D_00763D1C;
    ((ChkMemPool *)pool2)->bytes = ((ChkMemPool *)pool2)->bytes - ((ChkMemEntry *)block)->size;
    if ((s32)((ChkMemEntry *)block)->classInfo.bytes.index < 8) {
        pool = (u8 *)D_00763D1C;
        offset = ((ChkMemEntry *)block)->classInfo.bytes.index * 4;
        pool2 = (u8 *)(offset + (u32)pool);
        ((ChkMemPool *)pool2)->classBytes[0] =
            ((ChkMemPool *)pool2)->classBytes[0] - ((ChkMemEntry *)block)->size;
        payload = ((ChkMemEntry *)block)->alignment;
        size = payload + 0x18;
        blockSize = ((ChkMemEntry *)block)->size;
        size = blockSize - size;
        offset = header->classInfo.bytes.index * 4;
        pool2 = (u8 *)(offset + (u32)D_00763D1C);
        delta = ((ChkMemPool *)pool2)->classPayloadBytes[0] - size;
        ((ChkMemPool *)pool2)->classPayloadBytes[0] = delta;
    }
    chkmemPoolUnlink(&((ChkMemEntry *)block)->link);
    header->classInfo.classes = 0;
    func_0043ed08(block);
    if (lock != 0) {
        func_0042ba70();
    }
}

/* measured: func_0044ef70 (464B) floor at nd 54 — a saved-register rotation
   plus the classBytes/classCount pool-reload scheduling floor. retail allocates
   class=temp_16_2 in $s0 and block=func_0043ece8 result in $s1; mwcc b210 puts
   block in $s0 and class in $s1 (declaration order, 4 orders, did not move it).
   The alignment computation and the GP-relative msg string iGpffffac30
   (-0x53D0, "%s %d") now MATCH (added to symbol_data_addrs.txt with evidence).
   Same class-block pool-reload-before-delta floor as func_0044eaa0 plus the
   saved-register rotation family of func_0044ec60/func_0044f3a0. */
/* measured: preserves retail expression and class-array reload order. */
/* measured: baseline removal differs in 23 bytes; typed class-pool access; MEMBER block size and alignment reloads also differ. */
#pragma opt_propagation off
/* Allocate and register a payload with caller-specified alignment. */
/* The header back-pointer is payload-4 after variable alignment padding,
 * so it is not a fixed member of ChkMemEntry. */
// FUN_0044EF70
s32 chkmemAllocAligned(s32 size, s32 alignment, s32 flags)
{
    u16 blockAlignment;
    ChkMemEntry *block;
    s32 sizeOrClassBytes;
    s32 roundingSize;
    s32 allocationSize;
    s32 payloadAddress;
    s32 *classPool;

    blockAlignment = alignment;
    sizeOrClassBytes = 2 * blockAlignment + 24;
    sizeOrClassBytes += size;
    roundingSize = sizeOrClassBytes - 1;
    allocationSize = (-blockAlignment) & roundingSize;
    block = (ChkMemEntry *)func_0043ece8(allocationSize);
    if (block == NULL) {
        kAssertFailMsg(D_007104E0, 0x69B, (const char *)&iGpffffac30,
                      D_00763D1C->bytes);
    }
    if (block == NULL) {
        kAssertFail(D_007104E0, 0x4BA);
    }
    if (((u32)block & 3) != 0) {
        kAssertFail(D_007104E0, 0x4BB);
    }
    block->size = allocationSize;
    block->alignment = blockAlignment;
    block->flags = 0;
    payloadAddress = (s32)block + 24 +
              ((block->alignment - 1) &
               (block->alignment -
                (((s32)block + 24) & (block->alignment - 1))));
    if (((u32)payloadAddress & 3) != 0) {
        kAssertFail(D_007104E0, 0x4C0);
    }
    ((ChkMemPayload *)(payloadAddress - sizeof(ChkMemPayload)))->block = block;
    if (((s32)block & 3) != 0) {
        kAssertFail(D_007104E0, 0x4C4);
    }
    ++D_00763D1C->count;
    D_00763D1C->bytes += block->size;
    if ((u8)D_00763D1C->classes < 8) {
        classPool = (s32 *)(((u8)D_00763D1C->classes << 2) +
                          (s32)D_00763D1C);
        sizeOrClassBytes = block->size;
        ((ChkMemPool *)classPool)->classBytes[0] += sizeOrClassBytes;
        sizeOrClassBytes = block->size - (block->alignment + 24);
        D_00763D1C->classPayloadBytes[(u8)D_00763D1C->classes] += sizeOrClassBytes;
    }
    chkmemPoolAppend(&block->link);
    block->classInfo.classes = D_00763D1C->classes;
    return payloadAddress;
}
/* measured: func_0044ef70 matches with propagation disabled. */
#pragma opt_propagation on

/* measured: typed header access and per-arm result joins preserve the
   retail branch chain: 596 executable bytes / 608B, all 36 relocations
   exact. Keep the unlink helper static void; its physical v0 preservation
   is not a pointer-return contract. Retail copies up to the old header's
   total size, not payload capacity, and returning failure diagnostics still
   lead to a NULL-header write. These defects are intentionally preserved. */
/* Replace an optional payload and copy the smaller of its old total size and size. */
// FUN_0044F140
#pragma push
/* measured: preserve retail scheduling and the branch join after nested restore. */
#pragma schedule off
s32 chkmemReallocate(void *allocationPointer, u32 size)
{
    u32 copySize;
    s32 block;
    s32 allocationSize;
    s32 allocateLock;
    s32 newBlock;
    s32 newAllocationSize;
    s32 freeLock;
    s32 outerLock;
    s32 resizeLock;
    ChkMemEntry **oldHeaderSlot;
    s32 allocation;
    s32 result;
    ChkMemEntry *oldHeader;

    outerLock = func_0042ba20();
    if (allocationPointer == NULL) {
        allocateLock = func_0042ba20();
        if (size == 0) {
            kAssertFail(D_007104E0, 0x653);
        }
        allocationSize = (size + 0x37) & ~0xF;
        block = func_0043ece8(allocationSize);
        if (block == 0) {
            kAssertFailMsg(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, size);
        }
        allocation = chkmemRegisterBlock(block, allocationSize, 0x10, 0);
        if (allocateLock != 0) {
            func_0042ba70();
        }
        result = allocation;
    } else {
        oldHeaderSlot = &((ChkMemPayload *)((u8 *)allocationPointer - sizeof(ChkMemPayload)))->block;
        copySize = (*oldHeaderSlot)->size;
        if (size < copySize) {
            copySize = size;
        }
        resizeLock = func_0042ba20();
        if (size == 0) {
            kAssertFail(D_007104E0, 0x653);
        }
        newAllocationSize = (size + 0x37) & ~0xF;
        newBlock = func_0043ece8(newAllocationSize);
        if (newBlock == 0) {
            kAssertFailMsg(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, size);
        }
        allocation = chkmemRegisterBlock(newBlock, newAllocationSize, 0x10, 0);
        if (resizeLock != 0) {
            func_0042ba70();
        }
        memcpy((void *)allocation, allocationPointer, copySize);
        freeLock = func_0042ba20();
        if (allocationPointer == NULL) {
            kAssertFail(D_007104E0, 0x670);
        }
        oldHeader = *oldHeaderSlot;
        chkmemUntrackBlock((u8 *)oldHeader);
        func_0043ed08(oldHeader);
        if (freeLock != 0) {
            func_0042ba70();
        }
        result = allocation;
    }
    if (outerLock != 0) {
        func_0042ba70();
    }
    return result;
}
#pragma pop
/* Allocate count times elementSize bytes and zero the registered payload. */
// FUN_0044F3A0
s32 chkmemAllocZeroed(s32 count, s32 elementSize)
{
    s32 allocateLock;
    s32 outerLock;
    s32 block;
    s32 allocationAddressOrSize;
    u32 size;

    outerLock = func_0042ba20();
    allocateLock = func_0042ba20();
    size = elementSize * count;
    if (size == 0) {
        kAssertFail(D_007104E0, 0x653);
    }
    allocationAddressOrSize = (size + 0x37) & ~0xF;
    block = func_0043ece8(allocationAddressOrSize);
    if (block == 0) {
        kAssertFailMsg(D_007104E0, 0x65F, D_007104F0, D_00763D1C->bytes, size);
    }
    allocationAddressOrSize = chkmemRegisterBlock(block, allocationAddressOrSize, 0x10, 0);
    if (allocateLock != 0) {
        func_0042ba70();
    }
    if (allocationAddressOrSize != 0) {
        memset((void *)allocationAddressOrSize, 0, size);
    }
    if (outerLock != 0) {
        func_0042ba70();
    }
    return allocationAddressOrSize;
}
