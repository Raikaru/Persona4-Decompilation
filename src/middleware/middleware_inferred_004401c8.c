#include "include_asm.h"
#include "type.h"
/* Toolchain-blocked: retail saves callee-saved registers with sd; MWCCPS2 3.0.1 emits sq. See build/ORCH_sd_toolchain_blocked.txt. */


s32 vfprintf();
extern s32 D_009389E0[];

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
s32 __svfscanf_r();

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00446108 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma tailcall on
#pragma pop


s64 func_004470f0(s64 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_004470f0 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma tailcall on
/* measured: nd 45 against retail's 88-byte object. Retail builds a partially
   initialised 0x58-byte record at the frame base and hands its address to
   func_004447f8; b210 lays the same struct out at frame offset 0x20, so every
   store and the argument setup are displaced. Probed a bare local struct
   (mwccps2 rejects a struct type defined inside a function), the file-scope
   Mesh048 typedef used here, individual scalar locals (dead-store eliminated
   down to one), and taking the address of the first member instead of the
   struct. Committed at nd 45. */

/* Source unit: src/promoted/code1_0044.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0044.c; members 004401c8-00442088 */

// FUN_004401C8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004401c8);

// FUN_004402D0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004402d0);

// FUN_00440430
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440430);

// FUN_00440498
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440498);

// FUN_00440618
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440618);

// FUN_004406D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004406d8);

// FUN_00440880
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440880);

// FUN_00440A00
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440a00);

// FUN_00440B68
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440b68);

// FUN_00440BB8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00440bb8);

// FUN_004414F8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004414f8);

// FUN_00441558
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441558);

// FUN_00441580
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441580);

// FUN_00441B40
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441b40);

// FUN_00441CB0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441cb0);

// FUN_00441CF0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441cf0);

// FUN_00441D38
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441d38);

// FUN_00441D70
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441d70);

// FUN_00441EF0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441ef0);

// FUN_00441F40
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441f40);

// FUN_00441F68
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00441f68);

// FUN_00442088
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00442088);

