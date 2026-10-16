/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0044f510-0044f510 */

#include "include_asm.h"
#include "type.h"
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
extern s32 (*D_008BE290[])(u32);
extern void (*D_008BE294[])(u8 *);
extern s32 (*D_008BE298[])(void *, u32);
extern s32 (*D_008BE29C[])(s32, s32);
s32 chkmemAllocate(u32);
void chkmemFree(u8 *);
s32 chkmemReallocate(void *, u32);
s32 chkmemAllocZeroed(s32, s32);
s32 func_0044f4d0(void);
// FUN_0044F510
s32 (**func_0044f510(void))(u32) {
    D_00763D1C->fn_30 = func_0044f4d0;
    D_008BE290[0] = chkmemAllocate;
    D_008BE294[0] = chkmemFree;
    D_008BE298[0] = chkmemReallocate;
    D_008BE29C[0] = chkmemAllocZeroed;
    return D_008BE290;
}
