#include "include_asm.h"
#include "type.h"
extern u8 D_008872E0[];
extern u8 D_00885A90[];
extern s32 iGpffffb680;
extern s32 iGpffffb618;
extern s32 func_003b6e70(s32 arg0);
extern u64 func_003b7060(void);
extern s32 func_003b6e00(s32 arg0);
extern void func_003b6f00(s32 arg0, u8 *arg1);
extern s32 iGpffffb6c0;
extern s32 iGpffffb6c4;
extern void func_003e18c0(u8 *arg0, void *arg1, s32 arg2);
extern void func_003e12f0(u8 *arg0);
extern s32 D_00764758;

extern s32 iGpffffb668;

extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 func_003df240(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003df590(s64 arg0, ...);
extern void func_003df4d0(s32 *arg0);
extern void func_003bbea0(u8 *arg0);
extern void func_003c2a80(s32 arg0);
extern s32 D_00764794;
extern s32 D_00764790;
extern s32 D_0076478C;
extern s32 D_00764788;
extern s32 D_007647AC;
extern s32 D_007647A8;
extern s32 D_00764784;

extern s32 D_0076479C;
extern u8 D_00886498[];
extern u8 **func_003c22f0(u8 *arg0);
extern s32 func_003c0700(u8 *arg0);
extern s32 func_003c02e0(u8 *arg0);
extern s32 iGpffffb6b0;
extern s32 func_003bc880(s32 arg0, s32 arg1);
extern s32 func_003bff30(void *arg0, s32 (*arg1)(s32, s32 *), s32 *arg2);
extern s32 D_00764770;
extern s32 func_003e8930(s32 a, s32 b, void *c, void *d);
extern s32 func_003bb0d0(s32 arg0);
extern s32 func_003bb030(s32 arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_003bf930(void);
extern u64 func_003b88c0(void);
extern s32 func_003b84a0(u8 *arg0);
extern s32 iGpffffb654;
extern s32 iGpffffb61c;
extern u8 D_008864E8[];
extern s32 func_003e8960(s32 arg0);
extern u8 *func_003b8d40(u8 *arg0, s32 arg1);
extern s32 func_003e8410(s32 arg0, s32 arg1, void *arg2, void *arg3, s32 arg4);
extern s32 func_003c3920(s32 arg0, s32 arg1, void *arg2, void *arg3, s32 arg4);
extern u64 func_003bf1c0(u64 value);
extern s32 func_003bf1d0(s32 arg0);
extern u64 func_003bf1f0(u64 value);
extern s32 iGpffffb6b4;
extern void (*D_00887300[])(s32, s32);
extern void (*D_00887304[])(s32, void *);
extern s32 iGpffffb6f0;


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).
// FUN_003B0B80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b0b80);
// FUN_003B12A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b12a0);
// FUN_003B1A10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b1a10);
/* measured: best fresh plain-C attempt object 164B/window 160B, normalized_diff 34; archived at build/K3B6_003b31a0_nd34.c and restored to INCLUDE_ASM because object exceeded the retail window. */
// FUN_003B31A0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b31a0);
/* measured P3B: best current-TU body object 164B/window 160B, normalized_diff 34; archived at build/P3B_003b31a0_nd34.c and restored to INCLUDE_ASM (one word over window). K3B6 nd34 archive does not reproduce under the current TU (schedule on gives 144B/nd103); knob sweeps and sequential-pointer chains probed 140-148B/nd94-103. Retail computes loop pointers t0/t5/t6 before the slt $at,$zero,$a1 + beqz entry guard and fills every delay slot; ours colors a-regs differently, leaves three nops, and the $at guard never reproduces from C - the documented entry-guard floor. */
// FUN_003B3240
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3240);
// FUN_003B3570
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3570);
// FUN_003B3880
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3880);
/* measured: current-TU reconstructed body object 208B/window 208B, normalized_diff 124; differing word offsets 20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,180,188,192,196,200. Retail's pointer-load/loop ordering, register coloring, and callback branch layout remain mismatched; branch-local pointer-order probe enlarged to 212B, so restored fallback. */
// FUN_003B3F50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3f50);
/* measured: current-TU f32 aggregate candidate object 240B/window 256B, normalized_diff 140; fndiff reports 58 differing words. Scalar f32 locals were undersized (204B/nd132); aggregate stack restored frame 0x30 but retail pointer-load ordering and loop/else epilogue layout remain different. Explicit special-label/goto layout did not move the residual; restored fallback. */
// FUN_003B4020
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4020);
/* measured: schedule/no_branch_likely/opt_common_subs/opt_rebuildconditionals/optimization_level probes for 003b4120. */
#pragma schedule on
#pragma no_branch_likely on
#pragma opt_common_subs off
#pragma opt_rebuildconditionals off
#pragma optimization_level 3
// FUN_003B4120
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4120);
/* measured: close schedule/no_branch_likely/opt_common_subs/opt_rebuildconditionals/optimization_level around 003b4120. */
#pragma optimization_level 2
#pragma opt_rebuildconditionals on
#pragma opt_common_subs on
#pragma no_branch_likely off
#pragma schedule off
/* measured: best current-TU body object 164B/window 176B, normalized_diff 9; differing word offsets 4,20-24,156-160. Retail's entry guard is slt $at,$zero,$a1 + beqz with i=0 in the delay slot and one extra nop before jr. Every literal/boolean spelling probed colors $v1 or folds to blez/bltz instead (>=0 form reaches bltz nd13); named boolean go = 0 < arg1 under rc-off+propagation-off is the floor at nd9. Levers: schedule on, no_branch_likely on, opt_rebuildconditionals off, opt_propagation off, unrotated do-while with bottom i < arg1. Body archived at build/B3B_003b4230_body.c and restored to INCLUDE_ASM. */
// FUN_003B4230
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4230);
// FUN_003B42E0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b42e0);
// FUN_003B4470
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4470);
// FUN_003B47F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b47f0);
// FUN_003B4AB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4ab0);
// FUN_003B4C10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4c10);
// FUN_003B4DB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4db0);
// FUN_003B4FF0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4ff0);
// FUN_003B5160
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5160);
// FUN_003B53B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b53b0);
// FUN_003B5650
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5650);
// FUN_003B5820
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5820);
// FUN_003B5AC0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5ac0);
// FUN_003B5BF0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5bf0);
// FUN_003B5D20
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5d20);
/* measured: best current-TU body object 112B/window 112B, normalized_diff 26;
   differing word offsets 0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,104;
   archived at build/F3B0_003b5fb0_body.c and restored to INCLUDE_ASM. */
// FUN_003B5FB0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5fb0);
// FUN_003B6020
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6020);
// FUN_003B61E0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b61e0);
// FUN_003B6390
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6390);
/* measured: best fresh plain-C attempt object 152B/window 160B, normalized_diff 35; archived at build/K3B6_003b6420_nd35.c and restored to INCLUDE_ASM. */
// FUN_003B6420 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6420);
/* measured: best plain-C attempt object 124B/window 128B, normalized_diff 94; archived at build/F3B1_003b64c0_body.c and restored to INCLUDE_ASM. */
// FUN_003B64C0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b64c0);
/* measured: current-TU best archived body object 140B/window 144B, normalized_diff 96; differing word offsets 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132. The archived nd31/object144 result is stale under the current declaration environment. Direct field/address forms, named positive guard, and opt_propagation-off probe did not reproduce retail's register allocation or load/store order; restored fallback. */
// FUN_003B6540
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6540);
/* measured: current-TU reconstructed do-while body object 168B/window 176B, normalized_diff 109; differing word offsets 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152. Reconstructed retail logic from disassembly; +4/+8 float offsets and do-while shape are correct, but register/scheduling residual remains and named-positive probe was optimized away. Restored fallback. */
/* measured: current-TU duplicate-loop candidate object 168B/window 176B, normalized_diff 109; same retail slt/beqz prologue, pointer-lifetime coloring, and store order residual as func_003b4230; restored fallback. */
// FUN_003B65D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b65d0);
// FUN_003B6680
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6680);
// FUN_003B6CB0
/* measured: probe schedule with tailcall for retail's trailing nops. */
#pragma schedule on
#pragma tailcall on
u8 **func_003b6cb0(void *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003c22f0(*(u8 **)(arg1 + 0x18));
}
/* measured: close tailcall and schedule probes. */
#pragma tailcall off
#pragma schedule off
/* measured: schedule on, no_branch_likely on, opt_rebuildconditionals off, and opt_propagation off reproduce retail's hoisted table pointer (one s-reg reused for D_00887304 then D_00887300), the sq save of s0-s2, and the delay-slot calls; sp4C declared before sp48 places the slots at 0x48/0x4C. */
#pragma schedule on
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
#pragma opt_propagation off
// FUN_003B6CC0
s32 func_003b6cc0(s32 arg0, u8 *arg1) {
    void (**cb)(s32, void *);
    s32 sp4C;
    s32 sp48;

    cb = D_00887304;
    cb[0](0xB, &sp48);
    cb[0](0xA, &sp4C);
    if (*(s32 *)(arg1 + 0x64) == 0) {
        return 1;
    }
    cb = (void (**)(s32, void *))D_00887300;
    cb[0](0xB, (void *)*(s32 **)(arg1 + 0x60));
    cb[0](0xA, (void *)*(s32 **)(arg1 + 0x5C));
    (*(void (**)(s32))(*(u8 **)(arg0 + iGpffffb6f0) + 0x10))(arg0);
    cb[0](0xB, (void *)sp48);
    cb[0](0xA, (void *)sp4C);
    return 0;
}
/* measured: close schedule/no_branch_likely/opt_rebuildconditionals/opt_propagation probes around func_003b6cc0. */
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
#pragma schedule off
/* measured: current recheck object 84B/window 96B, normalized_diff 7; differing offsets 32,76,78-80,82-83. Best body archived in build/Z3BF_003b6da0_nd7_body.c; the prior nd6 archive was stale under the current TU. */
// FUN_003B6DA0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6da0);
/* measured N3B: exact Z3BF archive text reproduces nd7 84B/96B under the current TU (schedule on + opt_propagation off; storing through the D_00885A90 SYMBOL, not a base local, is load-bearing — base-local store scores nd45). Residual is 2 words: retail puts jr $ra in beqz's delay slot and pads after the loop with nop;nop;nop vs our nop;jr;nop — b210 never places an epilogue instruction in that delay slot. All 156 archived 84B shapes sit at nd>=7; dead-multiply spellings (value*factor as statement/comma) score nd44-53. */
/* measured: schedule on is required for func_003b6e00's callback delay slot. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003B6E00
s32 func_003b6e00(s32 arg0) {
    u8 *temp;

    temp = *(u8 **)(D_008872E0 + iGpffffb618);
    if (temp != NULL) {
        jtbl_008873EC[0](temp);
        *(u8 **)(D_008872E0 + iGpffffb618) = NULL;
    }
    return arg0;
}
/* measured: close no_branch_likely and schedule around func_003b6e00. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: current-TU archived body object 164B/window 144B, normalized_diff 122; differing word offsets 0,4,6,7,10,11,12,13,14,15,16,17,18,19,22,23,24,25,26,27,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160. Object exceeds the retail window, so the archived body was restored immediately. Current mismatch is dominated by frame size/addressing, callback/table materialization, and branch/epilogue layout; prior schedule/O1/reload-preserving-base probes remain ruled out. */
// FUN_003B6E70 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6e70);
/* measured: in-file body recheck is object 280B/window 352B with
   normalized_diff 210, over the park threshold; body archived at
   build/WS19_003b6f00_nd210.c and restored to INCLUDE_ASM. */
// FUN_003B6F00
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6f00);
/* measured: current-TU archived body object 172B/window 176B, normalized_diff 78; differing offsets 24,28,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164. Current body confirms the archived nd30 is stale; global array addressing is correct, while load order, counter/address materialization, signed-compare shape, and branch/return layout remain mismatched; restored fallback. */
// FUN_003B7060 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7060);
/* measured: schedule on reproduces func_003b7110's callback-address setup and return compare. */
#pragma schedule on
// FUN_003B7110
s32 func_003b7110(void) {
    s32 result;

    result = func_003e8930(0x10, 0x10C, (void *)func_003b6e70, (void *)func_003b6e00);
    iGpffffb618 = result;
    return result >= 0;
}
#pragma schedule off
/* measured: schedule on reproduces the callback and linked-object clear order. */
#pragma schedule on
/* measured: no_branch_likely on preserves retail's plain null branch. */
#pragma no_branch_likely on
// FUN_003B7150
s32 func_003b7150(u8 *arg0) {
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = arg0 + 0x2C;
    temp_4 = *(u8 **)(arg0 + 0x38);
    if (temp_4 != NULL) {
        jtbl_008873EC[0](temp_4);
    }
    *(s32 *)(temp_16 + 0) = 0;
    *(s32 *)(temp_16 + 4) = 0;
    *(s32 *)(temp_16 + 8) = 0;
    *(s32 *)(temp_16 + 0xC) = 0;
    *(s32 *)(temp_16 + 0x10) = 0;
    *(s32 *)(temp_16 + 0x14) = 0;
    return 1;
}
/* measured: no_branch_likely off closes the branch-form probe. */
#pragma no_branch_likely off
/* measured: schedule off closes the linked-object clear bracket. */
#pragma schedule off
/* measured: current-TU reconstructed body object 268B/window 224B, normalized_diff 196; fndiff reports 59 differing words. Early-return source shape duplicates branches versus retail's shared return, and argument/register setup, loop tail, and frame layout remain mismatched; object exceeds window, so restored fallback. */
// FUN_003B71B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b71b0);
// FUN_003B7290
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7290);
static inline s32 add003b(s32 left, s32 right) {
    return left + right;
}
// FUN_003B7450
/* measured: schedule on places the initial 0xC in the beqz delay slot. */
#pragma schedule on
/* measured: no_branch_likely probe around func_003b7450. */
#pragma no_branch_likely on
/* measured: O3 probe around func_003b7450. */
#pragma optimization_level 3
/* measured: opt_propagation off probe around func_003b7450. */
#pragma opt_propagation off
s32 func_003b7450(s32 *arg0) {
    s32 temp_3;
    s32 var_2;
    s32 field34;
    s32 base;
    s32 scaled;
    s32 sum;

    temp_3 = *(s32 *)((u8 *)arg0 + 0x30);
    var_2 = 0xC;
    if (temp_3 != 0) {
        scaled = temp_3 * 2;
        base = *(s32 *)((u8 *)arg0 + 0);
        field34 = *(s32 *)((u8 *)arg0 + 0x34);
        sum = add003b(base, scaled);
        field34 = field34 * 2;
        sum = add003b(sum, field34);
        var_2 = add003b(var_2, sum);
    }
    return var_2;
}
/* measured: close opt_propagation around func_003b7450. */
#pragma opt_propagation on
/* measured: close optimization_level 3 around func_003b7450. */
#pragma optimization_level 2
/* measured: close no_branch_likely around func_003b7450. */
#pragma no_branch_likely off
/* measured: close schedule around func_003b7450. */
#pragma schedule off
/* measured: schedule restores func_003b7480's call delay slots and joins. */
#pragma schedule on
/* measured: no_branch_likely on selects retail's plain comparisons. */
#pragma no_branch_likely on
// FUN_003B7480
void func_003b7480(u8 *arg0, s32 arg1) {
    s32 var_16;

    var_16 = arg1;
    if (func_003e8960(0x120) != -1) {
        goto second;
    }
    if (var_16 != 2) {
        goto second;
    }
set_one:
    var_16 = 1;
final:
    func_003b8d40(arg0, var_16);
    return;
second:
    if (func_003e8960(0x12E) != -1) {
        goto final;
    }
    if (var_16 == 3) {
        goto set_one;
    }
    goto final;
}
/* measured: close schedule around func_003b7480. */
#pragma schedule off
/* measured: close no_branch_likely around func_003b7480. */
#pragma no_branch_likely off
/* measured: current-TU named-boolean probe object 132B/window 128B, normalized_diff 63; differing word offsets 4,5,6,7,8,9,10,11,12,14,16,17,20,21,22,23,24,26,40,44,48,64,68,72,76,84,88,92,96,104,108,112,116,120,124,128. Object exceeds the retail window, so the archived body was restored immediately. The named boolean materialization did produce retail's sltu shape but introduced a four-byte overrun and did not resolve the register/loop ordering residual. */
// FUN_003B7510
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7510);
/* measured: current-TU generated-style six-argument body object 236B/window 240B, normalized_diff 174; fndiff reports 58 differing words at offsets 4-220. Unsigned >0 guards and an invariant flag did not alter codegen. Retail custom ABI uses a0-a3/t0-t1 and frame 0x10, but register/lifetime/branch scheduling remains substantially different; restored fallback. */
// FUN_003B7590
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7590);
// FUN_003B7680
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7680);
/* probe failed at translation/link stage after introducing unknown GP aliases iGpffffaa80/aa84; restore fallback without measuring object. Retail body frame is 0x30 with s0/s1 saves; generated logic otherwise follows initialization path. */
// FUN_003B7860
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7860);
/* measured: schedule and no_branch_likely reproduce the countdown callback path. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003B7970
s32 func_003b7970(s32 arg0) {
    s32 temp_3;
    extern void func_003b8d30(void);
    extern void func_003e12f0(s32 arg0);
    extern s32 D_008864B0[];
    extern s32 D_008864A8[];
    extern u8 *D_008864A0[];

    temp_3 = D_008864B0[0] - 1;
    D_008864B0[0] = temp_3;
    if (temp_3 == 0) {
        goto cleanup;
    }
done:
    return arg0;
cleanup:
    func_003b8d30();
    func_003e12f0(D_008864A8[0]);
    D_008864A8[0] = 0;
    jtbl_008873EC[0](D_008864A0[0]);
    D_008864A0[0] = NULL;
    goto done;
}
/* measured: no_branch_likely off restores the file setting after func_003b7970. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket opened above func_003b7970. */
#pragma schedule off
/* measured: declaring D_00886498 as s32 produced GP-relative addressing;
   declaring it as extern u8 [] and reading through the array forced retail's
   absolute lui/lw pair. Array-vs-scalar global declarations are load-bearing. */
// FUN_003B79F0
/* measured: schedule fills the store in the jr delay slot. */
#pragma schedule on
s32 func_003b79f0(s32 arg0) {
    *(s32 *)(arg0 + *(s32 *)D_00886498) = 0;
    return arg0;
}
/* measured: closes schedule around func_003b79f0. */
#pragma schedule off
/* measured: schedule on probe for 003b7a10 call/store order. */
#pragma schedule on
/* measured: no_branch_likely on selects retail's beqz null branch. */
#pragma no_branch_likely on
// FUN_003B7A10
s32 func_003b7a10(s32 arg0) {
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + *(s32 *)D_00886498);
    if (temp_17 != NULL) {
        func_003b88c0();
        *(u8 **)(arg0 + *(s32 *)D_00886498) =
            (u8 *)func_003b84a0(temp_17);
    }
    return arg0;
}
/* measured: close no_branch_likely around func_003b7a10. */
#pragma no_branch_likely off
/* measured: close schedule probe for 003b7a10. */
#pragma schedule off
/* measured: live-result propagation probe for func_003b88d0. */
#pragma schedule on
/* measured: opt_propagation off probe for func_003b88d0. */
#pragma opt_propagation off
// FUN_003B88D0
s32 func_003b88d0(s32 arg0) {
    s32 *var_10;
    s32 base;
    s32 sum;
    s32 temp_16;
    s32 result;
    u8 *temp_4;

    var_10 = (s32 *)0x10;
    base = (s32)(var_10 + 1);
    temp_4 = *(u8 **)(arg0 + *(s32 *)D_00886498);
    sum = base + (*(s32 *)(temp_4 + 0) << 6);
    temp_16 = add003b(sum, *(s32 *)(temp_4 + 4));
    temp_16 += 0x10;
    result = func_003b7450((s32 *)temp_4);
    return temp_16 + result;
}
/* measured: close opt_propagation off probe for func_003b88d0. */
#pragma opt_propagation on
/* measured: close schedule probe for func_003b88d0. */
#pragma schedule off
// FUN_003B8930
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8930);
// FUN_003B8AD0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8ad0);
// FUN_003B8D20
/* measured: probe schedule for retail's 16-byte return body. */
#pragma schedule on
s32 func_003b8d20(void) {
    return 1;
}
/* measured: close schedule probe. */
#pragma schedule off
// FUN_003B8D30
/* measured: probe schedule for retail's 16-byte return body. */
#pragma schedule on
s32 func_003b8d30(void) {
    return 1;
}
/* measured: close schedule probe. */
#pragma schedule off
// FUN_003B8D40
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8d40);
// FUN_003B8E50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8e50);
// FUN_003B90B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b90b0);
// FUN_003B9A40
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b9a40);
/* measured: schedule restores func_003bb030's loop and return slots. */
#pragma schedule on
// FUN_003BB030
s32 func_003bb030(s32 arg0) {
    s32 temp_2;
    s32 var_19;
    u32 **var_18;
    void (**var_17)(u8 *arg0);

    temp_2 = iGpffffb654 - 1;
    iGpffffb654 = temp_2;
    if (temp_2 == 0) {
        goto clear;
    }
    goto done;
done:
    return arg0;
clear:
    var_19 = 0xA;
    var_18 = (u32 **)D_008864E8;
    var_17 = jtbl_008873EC;
    do {
        var_17[0]((u8 *)*var_18);
        var_19 -= 1;
        *var_18 = NULL;
        var_18 -= 1;
    } while (var_19 >= 4);
    var_17[0]((u8 *)iGpffffb61c);
    iGpffffb61c = 0;
    goto done;
}
/* measured: close schedule around func_003bb030. */
#pragma schedule off
// FUN_003BB0D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb0d0);
// FUN_003BB210
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb210);
/* measured: best current-TU body object 104B/window 112B, normalized_diff 20;
   differing word offsets 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,84;
   archived at build/F3B0_003bb330_body.c and restored to INCLUDE_ASM. */
#pragma optimization_level 1
#pragma no_branch_likely on
#pragma schedule on
// FUN_003BB330 NONMATCHING
#ifdef NON_MATCHING
s32 func_003bb330(u8 *arg0) {
    s32 pair[2];
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0xC);
    if (temp_3 == 2) {
        return *(s32 *)(arg0 + 8) - 3;
    }
    if (temp_3 == 1) {
        return *(s32 *)(arg0 + 8) - 2;
    }
    pair[0] = 0x102;
    pair[1] = func_003df590(1);
    func_003df4d0(pair);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb330);
#endif
/* measured: close schedule/no_branch_likely/optimization probes around func_003bb330. */
#pragma schedule off
#pragma no_branch_likely off
#pragma optimization_level 2
/* measured: current-TU generated switch candidate object 288B/window 256B, normalized_diff 200; object exceeded window and was immediately archived/restored. Generated logic matches retail's switch/error paths, but current schedule/no_branch_likely/optimization environment and stack/register layout over-expand the body. */
// FUN_003BB3A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb3a0);
// FUN_003BB4A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb4a0);
// FUN_003BB5B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb5b0);
/* measured: current-TU reconstructed body object 240B/window 208B, normalized_diff 177; fndiff reports 50 differing words concentrated at offsets 4-24, 32-60, 76-168, 176-184, 192-200, and 208-236. The setup-order probe (call before result initialization) improved nd184 to nd177 but object still exceeds the retail window, so restored fallback. */
// FUN_003BBA90
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bba90);
/* measured: schedule on fills the final callback argument and epilogue slots. */
#pragma schedule on
/* measured: no_branch_likely on preserves retail's plain null tests. */
#pragma no_branch_likely on
// FUN_003BBB60
s32 func_003bbb60(u8 *arg0) {
    u8 *temp_4;
    u8 *temp_4_2;
    void (*callback)(u8 *);

    temp_4 = *(u8 **)(arg0 + 0x14);
    if (temp_4 != NULL) {
        jtbl_008873EC[0](temp_4);
        *(u8 **)(arg0 + 0x14) = NULL;
    }
    temp_4_2 = *(u8 **)(arg0 + 0x10);
    if (temp_4_2 != NULL) {
        jtbl_008873EC[0](temp_4_2);
        *(u8 **)(arg0 + 0x10) = NULL;
    }
    callback = jtbl_008873EC[0];
    callback(arg0);
    return 1;
}
/* measured: no_branch_likely off closes func_003bbb60's branch bracket. */
#pragma no_branch_likely off
/* measured: schedule off closes func_003bbb60's scheduling bracket. */
#pragma schedule off
// FUN_003BBBE0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbbe0);
/* measured: schedule on restores retail's callback-address materialization order. */
#pragma schedule on
// FUN_003BBE20
s32 func_003bbe20(void) {
    return func_003e8930(0, 0x102, (void *)func_003bb0d0, (void *)func_003bb030) >= 0;
}
/* measured: schedule off closes func_003bbe20's callback-order probe. */
#pragma schedule off
// FUN_003BBE60
/* measured: schedule on is required for func_003bbe60's store delay slot. */
#pragma schedule on
s32 func_003bbe60(s32 arg0) {
    D_00764784 += 1;
    return arg0;
}
/* measured: close schedule around func_003bbe60. */
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BBE80
/* measured: schedule on is required for func_003bbe80's store delay slot. */
#pragma schedule on
s32 func_003bbe80(s32 arg0) {
    D_00764784 -= 1;
    return arg0;
}
/* measured: close schedule around func_003bbe80. */
#pragma schedule off


// measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
//   b's delay slot unfilled (12 instr, 48B, nd 17).  schedule on
//   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
//   the first beqz into a beql with move $v0, $zero hoisted into its delay
//   slot and retargets it past the shared move; retail keeps beqz + nop.
//   NONMATCHING: b210 converts the first branch of a two-test chain whose
//   shared single-instruction return-0 target feeds a leaf [jr; nop]
//   epilogue; every honest source shape (&&, ||, nested ifs, early
//   returns, ternary, switch, result variable, goto forms) and every
//   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
//   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
//   beql; a whole-ELF scan shows retail never hoists a shared return-move
//   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
//   all have non-shared targets with multi-instruction epilogues).
//   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
//   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17).

/* measured: nd 47 at retail's real 68-byte body. Counts the entries of the
   gp-based descriptor at iGpffffb668 whose +0xC word is set. Retail hoists the
   zeroed accumulator and the loop index into the guard's delay slots and walks
   the entry pointer with the stride in the back-edge slot; b210 keeps the
   accumulator in a different register class and orders the guard the other
   way. schedule on does not move it (nd 47). Committed at nd 46. */

/* measured: current-TU candidates: local-base body object 220B/window 224B, normalized_diff 118; pointer-typed generated candidate object 204B/window 224B, normalized_diff 146. Retail frame is 0x50; local-base source adds an s4/base frame and pointer-typed source changes register/control-flow order. Restored original fallback; no candidate matched. */
// FUN_003BBEA0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbea0);

// FUN_003BBF80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbf80);

// FUN_003BC150
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc150);

// FUN_003BC400
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc400);

// FUN_003BC620
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc620);

// FUN_003BC740
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc740);

// FUN_003BC880
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc880);

// FUN_003BC9C0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc9c0);

// FUN_003BCBC0
/* measured: schedule fills the second zero store in the jr delay slot. */
#pragma schedule on
s32 func_003bcbc0(s32 arg0, s32 arg1) {
    u8 *temp_3;

    temp_3 = (u8 *)(arg0 + arg1);
    *(s32 *)(temp_3 + 0) = 0;
    *(s32 *)(temp_3 + 4) = 0;
    return arg0;
}
/* measured: closes schedule around func_003bcbc0. */
#pragma schedule off
/* measured N3B: archived W3C3B body no longer compiles as written — its implicit int->u8* call argument predates the typed func_003bbea0(u8*) prototype; with the required cast it compiles 168B/160B nd91 (object overflows window). ~40 distinct mined shapes all measure 152B/nd7 (guard register + loop-tail swap + trailing nop) or overflow; fresh guard spellings (`count>0`, `>=1`, while-form, cached-count) all land in that same tier. Retail needs slt $at,$zero,$v0;beqz $at with s2=0 in the delay slot, and lw v0,4(s0) reloaded AFTER the loop before jalr. Restored fallback; best archive build/WV08_003b_bcbe0_nd5.c is stale under the current TU (172B/105). */
// FUN_003BCBE0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcbe0);
/* measured: current-TU WT05 candidate object 224B/window 208B, normalized_diff 135; fndiff reports 46 differing words. Frame size matches retail, but saved-register/prologue order, allocation/table call materialization, branch layout, and loop tail remain mismatched; object exceeds window, so restored fallback. */
// FUN_003BCC80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcc80);

/* measured: best current-TU body object 204B/window 208B, normalized_diff 42; differing words are the entry guard register (slt $v0 vs retail slt $at,$zero,$v0 + beqz, the same $at-guard floor as func_003b4230), i=0 landing after the branch instead of in its delay slot, and one trailing nop. Levers: schedule on, no_branch_likely on, opt_rebuildconditionals off, opt_propagation off, goto done, cur = arg0 with return arg0 (arg0 stays live in $s4), volatile work reads for fresh loop-test reloads, decl order sp6C/work/go/cur/i/row. Body archived at build/B3B_003bcd50_body.c and restored to INCLUDE_ASM. */
// FUN_003BCD50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcd50);
// FUN_003BCE20
/* measured: schedule on is required for func_003bce20's callback delay slot. */
#pragma schedule on
s32 func_003bce20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003bc880(arg2 + arg3, arg0);
    return arg0;
}
/* measured: close schedule around func_003bce20. */
#pragma schedule off

/* measured: best current-TU body object 164B/window 192B, normalized_diff 71; differing words are the entry guard register (slt $v0 vs retail slt $at,$zero,$v0 + beqz, the same $at-guard floor as func_003b4230/003bcd50), retail's out-of-line func_003bc620 call placed after the loop exit and reached by bnez while every spelling compiles inline with beqz-skip, i=0 landing after the guard branch instead of in its delay slot, and one trailing nop. Levers: schedule on, no_branch_likely on, opt_rebuildconditionals off, opt_propagation off, cached count with volatile loop-tail reload, single-case switch wrap (skill sub-pattern 5), goto next, role-swapped counters, declaration permutations. Body archived at build/B3B_003bce50_body.c and restored to INCLUDE_ASM. */
// FUN_003BCE50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bce50);
// FUN_003BCF10 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcf10);
/* measured N3B: archive nd2 claims were never reproducible with a live C body (all historical verify JSONs show nd>=31; nd0 rows are INCLUDE_ASM self-compares). Best fresh: while-form `index=0; if (length>0) while(index<length){...}` nd29 76B/80B; plain do-while nd32; schedule-on folds the guard to bgezal $zero (68-84B). Residual: guard colours a named register instead of retail slt $at,$zero,$a0;beqz $at, and body-head order. */
/* measured: schedule on preserves func_003bcf60's field-load delay slot; object 56B/window 64B, nd 0. */
#pragma schedule on
/* measured: no_branch_likely on restores the plain guard form in func_003bcf60. */
#pragma no_branch_likely on
// FUN_003BCF60
s32 func_003bcf60(s32 arg0, s32 arg1) {
    s32 result;
    s32 value;
    u8 *temp_4;

    temp_4 = (u8 *)(arg0 + iGpffffb668);
    if (arg1 < *(s32 *)(temp_4 + 0)) {
        value = *(s32 *)(temp_4 + 4);
        result = value + (arg1 * 0x10);
        goto done;
    }
    result = 0;
done:
    return result;
}
/* measured: schedule off closes the one-function field-order probe. */
#pragma schedule off
/* measured: no_branch_likely off closes the one-function 003bcf60 probe. */
#pragma no_branch_likely off
/* measured: current-TU body object 76B/window 80B, normalized_diff 32; differing word offsets 0,4,16,20,24,52,56,60,64,68; archived at build/F3B0_003bcfb0_body.c. */
// FUN_003BCFB0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcfb0);
#pragma schedule on
/* measured: no_branch_likely on restores the plain guard form in func_003bd000. */
#pragma no_branch_likely on
// FUN_003BD000
s32 func_003bd000(s32 arg0, s32 arg1) {
    s32 result;
    s32 value;
    u8 *temp_4;

    temp_4 = (u8 *)(arg0 + D_00764770);
    if (arg1 < *(s32 *)(temp_4 + 0)) {
        value = *(s32 *)(temp_4 + 4);
        result = value + (arg1 * 0x10);
        goto done;
    }
    result = 0;
done:
    return result;
}
/* measured: schedule off closes the one-function field-order probe. */
#pragma schedule off
/* measured: no_branch_likely off closes the one-function 003bd000 probe. */
#pragma no_branch_likely off

/* measured: schedule on is required for func_003bd040's return delay slot. */
#pragma schedule on
// FUN_003BD040
s32 func_003bd040(s32 *arg0) {
    return *arg0;
}
/* measured: close schedule around func_003bd040. */
#pragma schedule off

/* measured: schedule on is required for func_003bd050's return delay slot. */
#pragma schedule on
// FUN_003BD050
s32 func_003bd050(u8 *arg0) {
    return *(s32 *)(arg0 + 4);
}
/* measured: close schedule around func_003bd050. */
#pragma schedule off

// FUN_003BD070
/* measured: schedule fills the return load in the jr delay slot. */
#pragma schedule on
s32 func_003bd070(u8 *arg0, s32 arg1) {
    return *(s32 *)(*(u8 **)(arg0 + 0xC) + (arg1 * 4));
}
/* measured: closes schedule around func_003bd070. */
#pragma schedule off

// FUN_003BD090
/* measured: schedule fills the floating return load in the jr delay slot. */
#pragma schedule on
f32 func_003bd090(u8 *arg0, s32 arg1) {
    return *(f32 *)(*(u8 **)(arg0 + 0xC) + (arg1 * 4));
}
/* measured: closes schedule around func_003bd090. */
#pragma schedule off

// FUN_003BD0B0
/* measured: schedule fills the return load in the jr delay slot. */
#pragma schedule on
s32 func_003bd0b0(u8 *arg0, s32 arg1) {
    return *(s32 *)(*(u8 **)(arg0 + 0xC) + (arg1 * 4));
}
/* measured: closes schedule around func_003bd0b0. */
#pragma schedule off

// FUN_003BD0D0
/* measured: schedule fills the store in the jr delay slot. */
#pragma schedule on
void func_003bd0d0(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(*(u8 **)(arg0 + 0xC) + (arg1 * 4)) = arg2;
}
/* measured: closes schedule around func_003bd0d0. */
#pragma schedule off

// FUN_003BD0F0
/* measured: schedule fills the floating store in the jr delay slot. */
#pragma schedule on
void func_003bd0f0(u8 *arg0, s32 arg1, f32 fparg0) {
    *(f32 *)(*(u8 **)(arg0 + 0xC) + (arg1 * 4)) = fparg0;
}
/* measured: closes schedule around func_003bd0f0. */
#pragma schedule off
/* measured: schedule on is required for func_003bd110's return delay slot. */
#pragma schedule on
/* measured: no_branch_likely on restores the plain switch branches in func_003bd110. */
#pragma no_branch_likely on
// FUN_003BD110
s32 func_003bd110(s32 arg0)
{
    switch (arg0) {
    case 1:
        return 4;
    case 2:
        return 4;
    case 3:
        return 4;
    default:
        return 0;
    }
}
/* measured: close schedule around func_003bd110. */
#pragma schedule off
/* measured: no_branch_likely off closes the one-function 003bd110 probe. */
#pragma no_branch_likely off

/* measured: the flat early-return chain is nd 43 -- b210 inverts every test
   and lays the early exits inline, while retail orders the blocks
   [func1 test][retarg][ret0][do2].  Writing that exact block order with
   explicit label targets (retarg = shared `return arg0`, ret0 = `return 0`,
   do2 = second guarded call) makes it byte-exact (nd 43 -> MATCH).
   #pragma no_branch_likely is load-bearing: without it the same body measures
   nd 46 (b210 emits bnel/beql).  Three functions in this file share the shape,
   differing only in the two gp-relative operands. */

// FUN_003BD160
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd160);
/* measured: schedule on is required for func_003bd470's call delay slots. */
#pragma schedule on
// FUN_003BD470
#pragma no_branch_likely on
s32 func_003bd470(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_00764794, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_00764790, 4) != 0) {
        goto retarg;
    }
    return 0;
}
/* measured: close schedule around func_003bd470. */
#pragma schedule off
#pragma no_branch_likely off
// FUN_003BD4F0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd4f0);

/* measured: schedule on is required for func_003bd560's return delay slot. */
#pragma schedule on
// FUN_003BD560
/* measured: b210 emits a branch-likely (beql) where retail uses a plain beqz.
   The retail window for func_003bd560 contains no branch-likely instruction at all, so the
   likely form is simply wrong here; nd 4 -> MATCH with this pragma. */
#pragma no_branch_likely on
s32 func_003bd560(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x6C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_003bd560). */
#pragma no_branch_likely off
/* measured: close schedule around func_003bd560. */
#pragma schedule off


// measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
//   b's delay slot unfilled (12 instr, 48B, nd 17).  schedule on
//   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
//   the first beqz into a beql with move $v0, $zero hoisted into its delay
//   slot and retargets it past the shared move; retail keeps beqz + nop.
//   NONMATCHING: b210 converts the first branch of a two-test chain whose
//   shared single-instruction return-0 target feeds a leaf [jr; nop]
//   epilogue; every honest source shape (&&, ||, nested ifs, early
//   returns, ternary, switch, result variable, goto forms) and every
//   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
//   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
//   beql; a whole-ELF scan shows retail never hoists a shared return-move
//   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
//   all have non-shared targets with multi-instruction epilogues).
//   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
//   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17).

#pragma schedule on
// FUN_003BD590
/* measured: no_branch_likely on preserves the retail plain beq branches. */
#pragma no_branch_likely on
s32 func_003bd590(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_0076478C, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_00764788, 4) != 0) {
        goto retarg;
    }
    return 0;
}
/* measured: no_branch_likely off closes func_003bd590's branch bracket. */
#pragma no_branch_likely off
/* measured: schedule off closes func_003bd590 before the archived ASM sibling. */
#pragma schedule off

// FUN_003BD610 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd610);

/* measured: schedule on opens func_003bd680's independent probe. */
#pragma schedule on
// FUN_003BD680
/* measured: b210 emits a branch-likely (beql) where retail uses a plain beqz.
   The retail window for func_003bd680 contains no branch-likely instruction at all, so the
   likely form is simply wrong here; nd 4 -> MATCH with this pragma. */
#pragma no_branch_likely on
s32 func_003bd680(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x7C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_003bd680). */
#pragma no_branch_likely off
/* measured: close schedule around func_003bd680/003bd590 scope. */
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 16 -> 0).

// FUN_003BD6B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd6b0);
// FUN_003BDD00
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bdd00);
// FUN_003BE180
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be180);
// FUN_003BE7C0
/* measured: schedule on is required for func_003be7c0's store delay slot. */
#pragma schedule on
s32 func_003be7c0(s32 arg0) {
    D_0076479C -= 1;
    return arg0;
}
/* measured: close schedule around func_003be7c0. */
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 16 -> 0).

// FUN_003BE7E0
/* measured: schedule on is required for func_003be7e0's store delay slot. */
#pragma schedule on
s32 func_003be7e0(s32 arg0) {
    D_0076479C += 1;
    return arg0;
}
/* measured: close schedule around func_003be7e0. */
#pragma schedule off


// measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
//   b's delay slot unfilled (12 instr, 48B, nd 17).  schedule on
//   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
//   the first beqz into a beql with move $v0, $zero hoisted into its delay
//   slot and retargets it past the shared move; retail keeps beqz + nop.
//   NONMATCHING: b210 converts the first branch of a two-test chain whose
//   shared single-instruction return-0 target feeds a leaf [jr; nop]
//   epilogue; every honest source shape (&&, ||, nested ifs, early
//   returns, ternary, switch, result variable, goto forms) and every
//   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
//   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
//   beql; a whole-ELF scan shows retail never hoists a shared return-move
//   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
//   all have non-shared targets with multi-instruction epilogues).
//   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
//   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17).

// FUN_003BE800
/* measured: probe tailcall for direct wrapper. */
#pragma tailcall on
s32 func_003be800(u8 *arg0) {
    return func_003c0700(arg0);
}
/* measured: close tailcall probe. */
#pragma tailcall off

// FUN_003BE810
/* measured: probe tailcall for direct wrapper. */
#pragma tailcall on
s32 func_003be810(u8 *arg0) {
    return func_003c02e0(arg0);
}
/* measured: close tailcall probe. */
#pragma tailcall off

/* measured: restore schedule scope for func_003be820 and func_003be910. */
#pragma schedule on
// FUN_003BE820
#pragma no_branch_likely on
s32 func_003be820(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_007647AC, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_007647A8, 4) != 0) {
        goto retarg;
    }
    return 0;
}
/* measured: no_branch_likely off closes func_003be820's branch bracket. */
#pragma no_branch_likely off
/* measured: schedule off closes func_003be820 before the archived ASM sibling. */
#pragma schedule off

// FUN_003BE8A0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be8a0);

/* measured: schedule on opens func_003be910's independent probe. */
#pragma schedule on
// FUN_003BE910
/* measured: b210 emits a branch-likely (beql) where retail uses a plain beqz.
   The retail window for func_003be910 contains no branch-likely instruction at all, so the
   likely form is simply wrong here; nd 4 -> MATCH with this pragma. */
#pragma no_branch_likely on
s32 func_003be910(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x6C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_003be910). */
#pragma no_branch_likely off
/* measured: close schedule around func_003be910/003be820 scope. */
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BE940
/* measured: schedule on is required for func_003be940's store delay slot. */
#pragma schedule on
s32 func_003be940(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
/* measured: close schedule around func_003be940. */
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BE960
/* measured: schedule on is required for func_003be960's store delay slot. */
#pragma schedule on
s32 func_003be960(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
/* measured: close schedule around func_003be960. */
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BE980
/* measured: schedule on is required for func_003be980's store delay slot. */
#pragma schedule on
s32 func_003be980(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
/* measured: close schedule around func_003be980. */
#pragma schedule off

/* measured: schedule on reproduces the shared load/store and callback order. */
#pragma schedule on
// FUN_003BE9A0
u8 *func_003be9a0(u8 *arg0) {
    s32 value;

    if ((*(s32 *)(arg0 + 0x4C) & 2) != 0) {
        goto callback;
    }
load:
    value = *(u8 *)(arg0 + 3);
update:
    value |= 1;
    *(u8 *)(arg0 + 3) = (u8)value;
    return arg0;
callback:
    func_003bf930();
    goto load;
}
/* measured: schedule off closes the callback bracket. */
#pragma schedule off
/* measured: schedule and no_branch_likely reproduce the callback dispatch and return blocks. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003BE9F0
u8 *func_003be9f0(u8 *arg0) {
    s32 value;
    extern s32 func_004114d0(s32 arg0, u8 *arg1, s32 arg2);
    extern s32 iGpffffb9b8;

    value = *(s32 *)(arg0 + 0x6C);
    if (value == 0) {
        goto fallback;
    }
call:
    if (func_004114d0(value, arg0, 1) != 0) {
        goto done;
    }
    goto zero;
fallback:
    value = *(s32 *)(D_008872E0 + iGpffffb9b8 + 0x3C);
    goto call;
zero:
    return NULL;
done:
    return arg0;
}
/* measured: closes the schedule bracket opened above func_003be9f0. */
#pragma schedule off
/* measured: schedule on preserves func_003bea60's call and store ordering;
   no_branch_likely stays on from the bracket opened above func_003be9f0. */
#pragma schedule on
// FUN_003BEA60
u8 *func_003bea60(u8 *arg0, u8 *arg1) {
    u8 *temp_2;
    u8 *temp_2_2;
    s32 pair[2];
    extern s32 func_003c02e0(u8 *arg0);
    extern u8 *func_003c03a0(u8 *arg0);
    extern u8 *func_003c0850(u8 *arg0, u8 *arg1);
    extern void func_003c1b90(u8 *arg0, s32 arg1);
    extern void func_003df4d0(s32 *arg0);
    extern s32 func_003df590(s64 arg0, ...);

    temp_2 = func_003c03a0(arg0);
    if (temp_2 == NULL) {
        goto setzero;
    }
    temp_2_2 = *(u8 **)(arg0 + 4);
    if (temp_2_2 == NULL) {
        goto error;
    }
    func_003c1b90(temp_2, *(s32 *)(temp_2_2 + 0xA0));
    func_003c0850((u8 *)*(s32 *)(arg1 + 4), temp_2);
    return arg0;
setzero:
    *(s32 *)(arg1 + 8) = 0;
    return NULL;
error:
    func_003c02e0(temp_2);
    pair[0] = 2;
    pair[1] = func_003df590(5);
    func_003df4d0(pair);
zero:
    return NULL;
}
/* measured: closes the schedule bracket opened above func_003bea60. */
#pragma schedule off
/* measured: closes the no_branch_likely bracket opened above func_003be9f0. */
#pragma no_branch_likely off
/* measured: schedule and plain-branch probes for func_003beb10. */
#pragma schedule on
#pragma no_branch_likely on
/* measured: opt_propagation off probe for the explicit count boolean. */
#pragma opt_propagation off
// FUN_003BEB10
u8 *func_003beb10(u8 *arg0) {
    s32 *temp_4;
    s32 var_15;
    s32 var_17;
    s32 var_16;

    var_17 = 0;
    var_15 = 0 < *(s32 *)(arg0 + 4);
    if (var_15 != 0) {
        goto loop_entry;
    }
cleanup:
    temp_4 = *(s32 **)(arg0 + 0);
    if (temp_4 != NULL) {
        jtbl_008873EC[0]((u8 *)temp_4);
        *(s32 **)(arg0 + 0) = NULL;
    }
    return arg0;
loop_entry:
    var_16 = 0;
    do {
        func_003c2a80(*(s32 *)(*(u8 **)(arg0 + 0) + var_16));
        var_17 += 1;
        var_16 += 4;
    } while (var_17 < *(s32 *)(arg0 + 4));
    goto cleanup;
}
/* measured: close opt_propagation probe for func_003beb10. */
#pragma opt_propagation on
/* measured: close plain-branch and schedule probes for func_003beb10. */
#pragma no_branch_likely off
#pragma schedule off
// FUN_003BEBB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bebb0);
// FUN_003BED10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bed10);
// FUN_003BEE80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bee80);
/* measured: -0x4950($gp) is registered as iGpffffb6b0. The scalar GP
   declaration reproduces retail's single gp-relative load before the three
   zero stores. */
// FUN_003BF1A0
/* measured: schedule on is required for func_003bf1a0's store delay slot. */
#pragma schedule on
s32 func_003bf1a0(s32 arg0) {
    u8 *temp_3;

    temp_3 = (u8 *)(arg0 + iGpffffb6b0);
    *(s32 *)(temp_3 + 8) = 0;
    *(s32 *)(temp_3 + 4) = 0;
    *(s32 *)(temp_3 + 0) = 0;
    return arg0;
}
/* measured: closes schedule around func_003bf1a0. */
#pragma schedule off
/* measured: schedule on is required for func_003bf330's call delay slot. */
#pragma schedule on
// FUN_003BF330
s32 func_003bf330(s32 arg0) {
    func_003c02e0((u8 *)arg0);
    return arg0;
}
/* measured: close schedule around func_003bf330. */
#pragma schedule off
/* measured: best plain-C attempt object 100B/window 112B, normalized_diff 43; archived at build/F3B1_003bf360_body.c and restored to INCLUDE_ASM. */
/* measured: schedule on, opt_common_subs off, and opt_propagation off were probed. */
#pragma schedule on
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_003BF360 NONMATCHING
#ifdef NON_MATCHING
extern u8 D_0070AF70[];
u8 *func_003bf360(u8 *arg0, s32 *arg1) {
    struct A {
        s32 value;
    };
    struct B {
        s32 value;
    };

    ((struct A *)arg1)->value += 0xC;
    ((struct B *)arg1)->value += 0x1C;
    ((struct B *)arg1)->value += func_003e3370(D_0070AF70, (s32)arg0) + 0xC;
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf360);
#endif
/* measured: close opt_common_subs/opt_propagation/schedule probes around func_003bf360. */
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma schedule off
// FUN_003BF3D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf3d0);
// FUN_003BF5F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf5f0);
// FUN_003BF930
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf930);
// FUN_003BFAE0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfae0);
/* measured: schedule on probe for func_003bfc40 call setup and cleanup. */
#pragma schedule on
// FUN_003BFC40
s32 func_003bfc40(s32 arg0) {
    u8 *temp_4;

    func_003e18c0(*(u8 **)(D_008872E0 + iGpffffb6c0 + 4), (void *)func_003be800, 0);
    func_003e18c0(*(u8 **)(D_008872E0 + iGpffffb6c0), (void *)func_003be810, 0);
    func_003e12f0(*(u8 **)(D_008872E0 + iGpffffb6c0));
    func_003e12f0(*(u8 **)(D_008872E0 + iGpffffb6c0 + 4));
    temp_4 = (u8 *)(D_008872E0 + iGpffffb6c0);
    *(s32 *)(temp_4 + 0) = 0;
    *(s32 *)(temp_4 + 4) = 0;
    iGpffffb6c4 -= 1;
    return arg0;
}
/* measured: close schedule around func_003bfc40. */
#pragma schedule off
/* measured: generated body with named slot pointer object 224B/window 240B, normalized_diff 136; inline slot recomputation with scalar D_0070AF70 object 248B/window 240B, normalized_diff 127 and was immediately archived for oversized output. Retail frame 0x20 versus named-pointer frame 0x30; inline recomputation removed saved s1 but over-expanded call/address materialization. Restored fallback; no match. */
// FUN_003BFD00
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfd00);
// FUN_003BFDF0
/* measured: schedule restores func_003bfdf0's call and branch delay slots. */
#pragma schedule on
s32 func_003bfdf0(void) {
    s32 result;

    result = func_003e8410(0xC, 0x10, (void *)func_003bf1a0, (void *)func_003bf1c0, 0);
    iGpffffb6b0 = result;
    if (result < 0) {
        return 0;
    }
    result = func_003c3920(0xC, 0x10, (void *)func_003bf1d0, (void *)func_003bf1f0, 0);
    iGpffffb6b4 = result;
    return result >= 0;
}
/* measured: close schedule around func_003bfdf0. */
#pragma schedule off
/* measured: schedule on is required for func_003bfe60's callback setup. */
#pragma schedule on
// FUN_003BFE60
s32 func_003bfe60(void *arg0) {
    s32 result;

    result = 0;
    func_003bff30(arg0, func_003be940, &result);
    return result;
}
/* measured: close schedule around func_003bfe60. */
#pragma schedule off
/* measured: current recheck object 168B/window 160B, normalized_diff 114; object exceeded the retail window. Body archived in build/Z3BF_003bfe90_oversize_body.c; prior object-140/nd24 archive was stale under the current TU. */
// FUN_003BFE90 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfe90);
/* measured: current-TU archived body object 136B/window 144B, normalized_diff 65; differing word offsets 16,20,24,28,32,36,40,44,48,52,56,60,68,76,80,84,88,124,128. Declaration swap and callback switch-shape probes did not move the residual; restored fallback. */
// FUN_003BFF30
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bff30);
/* measured P3B: best current-TU body object 136B/window 144B, normalized_diff 54; archived at build/P3B_003bff30_nd54.c and restored to INCLUDE_ASM. Requires schedule on + no_branch_likely on. Same floor family as func_003bffc0: retail materializes addiu s1,s4,0x8 after the guard branch and colors sentinel s1/next s0 with the loop-back bne carrying the move in its delay slot; every spelling colors s0/s1 and hoists the addiu. goto-done nested form reaches nd41 but at 120B is structurally undersized (merged guard); declaration permutations probed identical. Saved-register coloring + loop-back delay-slot fill are compiler floors per campaign census. */
/* measured: best fresh plain-C attempt object 156B/window 144B, normalized_diff 32; archived at build/K3B6_003bffc0_nd32.c and restored to INCLUDE_ASM because object exceeded the retail window. */
/* measured P3B: best current-TU body object 140B/window 144B, normalized_diff 22; archived at build/P3B_003bffc0_nd22.c and restored to INCLUDE_ASM. Requires schedule on + no_branch_likely on (K3B6 nd18 archive does not reproduce: exact text 156B/nd106, schedule-on-only 136B/nd45). Residual: retail materializes addiu s1,s4,0x18 before the head load and colors sentinel s1/next s0 (ours s0/s1, addiu sunk after the guard), and the loop-back bne carries the pointer move in its delay slot; declaration permutations, goto/nested-if/for-break shapes, chained-load cast, and named return-local all probed (9 variants) without moving it - saved-register first-use coloring + loop-back delay-slot fill, compiler floors per campaign census. */
// FUN_003BFFC0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bffc0);
