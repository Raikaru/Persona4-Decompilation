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


/* measured: reconstructed the complete packet-state setup, vertex-generation call, primitive dispatch, and state restore. The candidate has the exact 0x1B0 frame, stack field offsets, register home mapping, and all relocations; b210 evaluates the state load before the stack-address arithmetic in both vtable calls, while retail computes each address first. Tried direct array/deref calls, hoisted pointers, named offset locals, interleaved prototypes, u32/s32 counters, and split counters; the two call-site rotations remained. Committed at nd 21. */
// FUN_0045DB40 NONMATCHING
#ifdef NON_MATCHING
void func_0045db40(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, f32 fparg3) {
    struct { s32 saved[6]; u8 pad1[8]; f32 out; u8 pad2[0xFC]; PrimFloat4 pos; } work;
    u32 i;
    u32 j;
    s32 *p;
    work.pos = *(PrimFloat4 *)arg1;
    if (arg2 != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)((u8 *)work.saved + i * 4));
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    func_0045d370(&work.out, arg0, &work.pos, fparg0, arg3, arg4, fparg1, fparg2, fparg3);
    D_00887310[4](4, &work.out, 4);
    if (arg2 != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], work.saved[j]);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045db40);
#endif


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


/* measured: mwcc b210 allocates 8 saved registers (frame 0xC0, saved[6] at
   0xA0) vs retail's 7 (frame 0xB0, saved[6] at 0x90) -- the extra live value
   (loop counter or pre-jal operand) pushes the frame 0x10 and shifts the
   byte-conversion loop codegen (inv/minus land in $f2/$f1 vs retail $f1/$f2,
   branch inverted to bgez, loads reordered). Tried dedicated v0-v3/c0-c3/f0-f3
   locals, block-scoped temps, bare u8 loads, and both if(x<0)/if(x>=0) branch
   orientations: all nd 200 with the same 8-sreg frame. Register-allocation
   floor. */
// FUN_0045DFD0
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045dfd0);


/* measured: mwcc b210 allocates 8 saved registers (frame 0xC0, saved[6] at
   0xA0) vs retail's 7 (frame 0xB0, saved[6] at 0x90): the first-loop temp
   &D_00712490[j] gets a dedicated $s5 instead of reusing out's register
   ($s0, which is dead until the alloc call), and the D_00887304/00 call
   arguments evaluate in the wrong order (the recorded db40/e6a0 floor). The
   byte-conversion loop is otherwise structurally correct (inv/minus land in
   $f2/$f1 vs retail $f1/$f2). Tried hoisting pos/col/scale all, pos/col only,
   and every declaration order (probe a/b/c): all nd 225-227. Saved-register
   rotation + argument-order floor. */
// FUN_0045E310
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045e310);


/* measured: reconstructed the complete state setup/restore loops, allocator call, delegated vertex emission, primitive dispatch, and packet release. The candidate has the exact register home mapping, frame, stack offsets, call sequence, and relocations; b210 evaluates the state load before the stack-address arithmetic in the two vtable calls, while retail computes each address first. Tried direct array/deref calls, hoisted pointers, named offset locals, interleaved prototypes, u32/s32 counters, split counters, and comma-order expressions; the residual call-site rotations remained. Committed at nd 21. */
// FUN_0045E6A0 NONMATCHING
#ifdef NON_MATCHING
void func_0045e6a0(s32 arg0, s32 arg1, f32 fparg0, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 fparg1, f32 fparg2, f32 fparg3) {
    s32 saved[6];
    s32 *p;
    u32 i;
    u32 j;
    if (arg4 != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)((u8 *)saved + i * 4));
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    func_0044ea90(D_007124C0, 0x355);
    p = (s32 *)jtbl_008873E8[0](arg2 << 6, 0x40000);
    func_0045dd30((u8 *)p, arg0, arg1, fparg0, arg2, arg5, arg6, fparg1, fparg2, fparg3);
    D_00887310[4](arg3, p, arg2);
    if (arg4 != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], saved[j]);
        }
    }
    jtbl_008873EC[0](p);
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045e6a0);
#endif


/* measured: prologue, alloc, w-field setup, both func_0043f810 copies, the
   iGpffff81d0*scale + func_0044b7b0/44b610 calls, and the tail all match
   byte-for-byte (nd 88). The rotation loop's retail FPU-accumulator chain
   (mula.s $f2,$f20; madd.s $f1,$f3,$f0; add.s $f1,$f6,$f1 -- a 2-product
   sum whose ACC is seeded with the dy*f21*f20 product, then the base f6
   added last) is not reproduced: mwcc b210 always seeds the ACC with the
   base addend (mtc1 $zero + adda.s $f4,$f6 + madda.s + madd.s) instead of
   the product, for every term order (x-first/y-first), parenthesized,
   separate rx/ry temps, and dx/dy locals (all nd 88-89). Also the w base
   lands in $s0 vs retail $s2, and the pre-loop pos[0]/pos[1] spB8/spBC
   stack stores are omitted. FPU-accumulate (mula/madd) floor. */
// FUN_0045E8E0
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045e8e0);


/* measured: identical structure to func_0045e8e0 (same rotation loop with
   retail's FPU-accumulator chain mula.s/madd.s/add.s) plus w->prime = 1
   after the loop; hits the same FPU-accumulate floor at nd 88 (the base
   f6/f5 acc-seed vs retail's product seed, and the w base in $s0 vs retail
   $s2). See func_0045e8e0 note. FPU-accumulate (mula/madd) floor. */
// FUN_0045EB20
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045eb20);
