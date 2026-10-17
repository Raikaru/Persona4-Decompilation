#include "include_asm.h"
#include "type.h"
/* Toolchain-blocked: retail saves callee-saved registers with sd; MWCCPS2 3.0.1 emits sq. See build/ORCH_sd_toolchain_blocked.txt. */


s32 vfprintf();
s32 func_00444870();
s32 func_00421da8();
s32 func_0044a138();
f32 func_0044b018(s32 arg0, f32 fparg0, f32 fparg1);
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
s32 func_00446108();

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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0044.c; members 00446108-0044b868 */

s32 func_00447b88(s64 arg0);
s32 func_00447d00(s64 arg0, s32 arg1);
f32 func_00448d10(f32 arg0);
f32 func_00449120(f32 arg0);
f32 func_004494b8(f32 arg0, f32 arg1);
f32 func_00449680(f32 arg0);
f32 func_00449938(f32 arg0, f32 arg1);
// FUN_00446108
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446108);

// FUN_00446D98
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446d98);

// FUN_00446E88
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446e88);

// FUN_00446EB0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446eb0);

// FUN_00446ED8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446ed8);

/* measured: nd 60 against retail's 80-byte object (object_size 80/80 exact).
   Same wall as the parked func_00446ed8: retail builds the partially
   initialised Mesh048 record at the frame base (addiu $sp,-0x70, struct at
   $sp+0x0) and hands &s to func_00444870; b210 lays the same struct out at
   frame offset 0x20 (addiu $sp,-0x80), so every store and the argument setup
   are displaced by 0x20. Probed the natural declaration-order struct init,
   retail's store order (unk10,unk14,unkC,unk54,unk0,unk8), a pointer-to-struct
   local, passing &s.unk0, and scalar field locals — all nd 60. Committed at
   nd 60.
   Committed at nd 60. */
// Archived C body: build/WBHygiene_func_00446f30_archive.txt; no current park body remains.
// FUN_00446F30
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446f30);

/* measured: nd 57 against retail's 96-byte object (object_size 88/96).
   Retail hoists `lui $s0,%hi(D_009389E0)` ONCE into a callee-saved register
   live across the func_00421da8 call and reuses it for both the `sw $zero`
   (before the call) and the `lw` (after), keeping the out pointer in $s1 with
   sd saves (frame 0x20). b210 rematerialises the address twice (once for the
   store, once for the load) and, with only one live s-register, emits a
   quadword `sq $s0` save instead of retail's two `sd`s; a pointer local
   (`p=&D_009389E0[0]`) that forces the address live across the call instead
   doubles it AND inflates the frame to 0x30, and no pragma (opt_loop_invariants,
   opt_common_subs, O3) reproduces the single hoist. The branch polarity is
   also inverted vs retail (bnel+beqz vs bne+bnel) as a consequence of the
   register allocation. Probed the && form, explicit-if in both guard
   polarities, pointer forms, and the three pragmas. Committed at nd 52. */
// Archived C body: build/WBHygiene_func_00446f80_archive.txt; no current park body remains.
// FUN_00446F80
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446f80);

// FUN_00446FE0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00446fe0);

// FUN_004470F0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004470f0);

// FUN_004476B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004476b0);

// FUN_00447B88
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00447b88);

// FUN_00447D00
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00447d00);

// FUN_00448A00
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00448a00);

// FUN_00448D10
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00448d10);

// FUN_00449120
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00449120);

// FUN_004494B8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004494b8);

// FUN_00449680
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00449680);

// FUN_00449938
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00449938);

// FUN_0044A138
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a138);

// FUN_0044A4D0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a4d0);

// FUN_0044A5B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a5b0);

// FUN_0044A700
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044a700);

// FUN_0044AF20
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044af20);

// FUN_0044B018
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b018);

// FUN_0044B310
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b310);

// FUN_0044B340
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b340);

// FUN_0044B610
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b610);

// FUN_0044B6C0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b6c0);

// FUN_0044B6D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b6d8);

// FUN_0044B7B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b7b0);

// FUN_0044B868
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b868);

