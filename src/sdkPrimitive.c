/* Consolidated Persona 4 source units. */
/* Original translation unit sdkPrimitive.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0044ea90(void *msg, s32 id);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *param, void *work);
extern void func_0045d890(void);
extern void func_0045d370(void *out, void *a1, void *a2, f32 f0, s32 a3, s32 a4, f32 f1, f32 f2, f32 f3);
extern void func_0045dd30(u8 *a0, s32 a1, s32 a2, f32 f0, u32 a3, s32 a4, s32 a5, f32 f1, f32 f2, f32 f3);
extern void func_003f6440(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887304[])(u32 state, void *out);
extern void (*D_00887310[])(s32 primType, void *verts, s32 numVerts);
extern struct {
    s32 state;
    s32 val;
} D_00712490[6];
extern u8 D_007124C0[];
extern u8 *func_00457120(void);
extern f32 func_0044b7b0(f32 x);
extern f32 func_0044b610(f32 x);
extern f32 D_008872F8[];
extern f32 iGpffff81d0;

typedef struct { u8 c[4]; } PrimByte4;
typedef struct { f32 v[4]; } PrimFloat4;
typedef struct { f32 v[2]; } PrimFloat2;

// FUN_0045DA40
void func_0045da40(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 fparg0) {
    PrimFloat4 pos;
    struct {
        PrimByte4 col;
        PrimFloat4 pos;
        f32 scale;
        s32 tag;
    } packet;
    u8 *temp_2;
    u8 *temp_2_2;

    pos = *(PrimFloat4 *)arg1;
    packet.col = *(PrimByte4 *)arg0;
    packet.pos = pos;
    packet.scale = fparg0;
    packet.tag = arg2;
    func_0044ea90(D_007124C0, 0x101);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x1C, 0x40000);
    func_0043f810(temp_2, &packet, 0x1C);
    temp_2_2 = (u8 *)(func_00460990());
    *(void **)(temp_2_2 + 8) = (void *)func_0045d890;
    *(u8 **)(temp_2_2 + 0x10) = temp_2;
    func_00460ac0((void *)arg3, temp_2_2);
}


/* measured: retail evaluates the second argument (stack address/load) of the
   D_00887304/D_00887300 vtable calls before the first argument (the state
   load): `sll/addu` then `lw $a0, ($s0)` then `addiu $a1, $v0, 0x80`; mwcc b210
   emits the `lw $a0` first in both loops (nd 8, exactly two 3-4 instruction
   rotations, everything else byte-identical). Tried direct array spelling,
   deref (*D_00887304)(...) spelling, hoisted out/sv pointers (before and after
   the entry pointer), hoisted state temp, named s32 offset locals, s64 vs s32
   arg3/arg4, interleaved f32 prototype positions, u32/s32 counters, split
   i/j counters: all give identical nd 8 or regress the register allocation to
   7 sregs. Argument-evaluation-order floor. */
// FUN_0045DB40
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045db40);


/* measured: retail FP home-register mapping is {z:f24, sinv:f20, inv:f21,
   ang:f25, fparg0:f24, fparg1:f20, fparg2:f23, fparg3:f22} (mula/madd body
   matches once the sum-of-products is parenthesized and the 2-float base copy
   is a struct); mwcc b210 always emits {z:f20, sinv:f22, inv:f21, ang:f25,
   fparg0:f20, fparg1:f22, fparg2:f24, fparg3:f23} (nd 179-183) regardless of
   local declaration order (tried sinv,inv,z,ang / statement order / base
   first / base last), prototype FP-param position (interleaved 4th vs
   GPRs-first), base as struct vs 2-element array vs plain f32s, and
   x + x vs 2.0f * x. FP register-allocation floor. */
// FUN_0045DD30
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045dd30);


// FUN_0045DFD0
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045dfd0);


// FUN_0045E310
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045e310);


/* measured: same argument-evaluation-order floor as func_0045db40. With the
   correct register allocation (two separate loop counters i/j + locals
   declared (saved[6], p, i, j); pointer-cast D_00712490 entry) everything
   matches except two 3-4 instruction rotations in the D_00887304/D_00887300
   vtable calls: mwcc b210 emits the `lw $a0, ($s0)` state load before the
   `sll/addu` for &saved[i], retail after (nd 9). Tried hoisted out/sv
   pointers, named s32 offset locals, direct vs deref call spelling: identical
   nd 9. */
// FUN_0045E6A0
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045e6a0);


// FUN_0045E8E0
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045e8e0);


// FUN_0045EB20
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045eb20);
