#include "runtime_integer_internal.h"
#include "include_asm.h"
#include "type.h"
/* Retail saves callee-saved registers with sd, but this compiler emits sq, so those functions
 * cannot match. */

s32 vfprintf();
s32 _vfprintf_r();
s32 func_00421da8();
s32 func_0044a138();
f32 func_0044b018(s32, f32 fparg0, f32 fparg1);
extern s32 D_009389E0[];
s32 kwlnTaskGetCurrent(void);
s32 func_0044d4d0();

typedef struct {
    u8 *unk0;      /* 0x0 */
    s32 unk8;      /* 0x8 */
    s16 unkC;      /* 0xC */
    u8 *unk10;     /* 0x10 */
    s32 unk14;     /* 0x14 */
    u8 pad18[0x3C];
    u8 *unk54;     /* 0x54 */
} Mesh048;

typedef struct E8Node E8Node;
typedef struct {
    E8Node *first;
    E8Node *last;
    E8Node *current;
    u8 padC[0xC];
    s32 count;
    s32 total;
    u8 pad20[0x10];
    s32 (*fn_30)(void);
} E8Pool;
struct E8Node {
    E8Node *next;
    E8Node *prev;
};
extern E8Pool *D_00763D1C;
extern s32 *D_00710070[];
extern s32 (*D_008BE290[])(u32);
extern void (*D_008BE294[])(u8 *);
extern s32 (*D_008BE298[])(void *, u32);
extern s32 (*D_008BE29C[])(s32, s32);
s32 chkmemAllocate(u32);
void chkmemFree(u8 *);
s32 chkmemReallocate(void *, u32);
s32 chkmemAllocZeroed(s32, s32);
s32 chkmemGetCurrentTaskOwner(void);
s32 __svfscanf_r();

/* measured: retail sets up a stack frame around the tail jump, which the compiler's tail-call pass
 * never emits. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

s64 func_004470f0(s64);

/* measured: retail sets up a stack frame around the tail jump, which the compiler's tail-call pass
 * never emits. */

#pragma push
#pragma schedule on
#pragma tailcall on

/* String scanning installs this successful no-op as its stream callback. */
// FUN_004420F8
s32 stdioScanStringStreamNoop(void) {
    return 0;
}

/* strstr. Still one instruction over retail because retail ends with a branchless conditional-move
 * select for the NULL return, and no C spelling produces it. */
// FUN_00443010 NONMATCHING
#ifdef NON_MATCHING
s8 *func_00443010(s8 *arg0, s8 *arg1) {
    s32 counter;
    s8 *result;
    s8 *p2;
    s8 c1;
    s8 c2;

    result = arg0;
    if (*arg0 == 0) {
        return (*arg1 == 0) ? result : NULL;
    }
    counter = 0;
inner:
    c1 = arg1[counter];
    p2 = result + counter;
    if (c1 == 0) {
        goto done;
    }
    c2 = *p2;
    if (c1 != c2) {
        result++;
        if (*result == 0) {
            return NULL;
        }
        counter = 0;
        goto inner;
    }
    counter++;
    goto inner;
done:
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443010);
#endif

/* Newlib's scatter-write request: vector pointer, vector count, bytes pending. */
typedef struct StdioWriteRequest {
    void *vectors;
    s32 vectorCount;
    s32 remainingBytes;
} StdioWriteRequest;

/* Flush a scatter-write request and reset its consumed vector/byte counts. */
// FUN_00444700 NONMATCHING
#ifdef NON_MATCHING
s32 __sprint(u8 *stream, u8 *request) {
    extern s32 __sfvwrite(u8 *, u8 *);
    s32 result;

    if (((StdioWriteRequest *)request)->remainingBytes == 0) {
        ((StdioWriteRequest *)request)->vectorCount = 0;
        return 0;
    }
    result = __sfvwrite(stream, request);
    ((StdioWriteRequest *)request)->vectorCount = 0;
    ((StdioWriteRequest *)request)->remainingBytes = 0;
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444700);
#endif

/* measured: retail tests the float's raw bits with an integer compare against pi/4, which this
 * compiler will not emit from any reinterpret idiom. */

#pragma pop

s32 func_00447b88(s64);

/* measured: retail keeps a stack frame around this tail jump; the compiler always emits a bare jump
 * instead. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

s32 func_00447d00(s64, s32);

/* measured: retail keeps a stack frame around this tail jump; the compiler always emits a bare jump
 * instead. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00448d10(f32);

/* measured: retail keeps a stack frame around this tail jump; the compiler always emits a bare jump
 * instead. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00449120(f32);

/* measured: retail keeps a stack frame around this tail jump, which the compiler always collapses
 * to a bare jump. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_004494b8(f32, f32);

/* measured: retail keeps a stack frame around this tail jump, which the compiler always collapses
 * to a bare jump. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00449680(f32);

/* measured: retail keeps a stack frame around this tail jump, which the compiler always collapses
 * to a bare jump. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00449938(f32, f32);

/* measured: retail keeps a stack frame around this tail jump, which the compiler always collapses
 * to a bare jump. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 __ieee754_sqrtf(f32);

/* measured: retail keeps a stack frame around this tail jump, which the compiler always collapses
 * to a bare jump. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

// Kept here so this multi-run bucket stays link-eligible (has_first_party); see tools/build.py eligible_c_objects.
/* Supplies the current task identifier to the memory-pool owner callback; zero means no task. */
// FUN_0044F4D0
s32 chkmemGetCurrentTaskOwner(void) {
    s32 currentTask;
    currentTask = kwlnTaskGetCurrent();
    if (currentTask != 0) {
        return currentTask;
    }
    return 0;
}
