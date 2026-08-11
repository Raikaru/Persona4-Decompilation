#include "include_asm.h"
#include "type.h"
/* Toolchain note: retail saves $s registers with sd; MWCCPS2 3.0.1 emits sq; toolchain-blocked, see build/ORCH_sd_toolchain_blocked.txt. */

s32 func_0041e8d8(); /* old-style: retail callers leave $a0..$a3 materialized */
void func_0041dff8(void);
void func_0041be30(void);
void func_0041e030();
u8 **func_004117b0(s32);
s32 func_00413700(s32);
s32 func_00413b80(s32);
s32 func_00413e50(s32, s32 *);
s32 func_004140f0(u8 *, u8 **);
void func_004143f0(s32, s32);

void func_00415ad0(u8 *, u8 *);
void func_004165a0(u8 *, u8 *, u8 *, f32, f32, f32);
void func_00415bc0(u8 *, u8 *, u8 *, u8 *, f32);
void func_00417310(u8 *, u8 *, u8 *);
void func_00416e10(u8 *, u8 *);
u8 *func_00416bc0(s32, u8 *);
s32 func_00416cf0(u8 *, s32);
s32 func_00416df0(u8 *);
/* measured: baseline -O2 emits lw/sw/srl/andi/jr/nop with the return andi
   before jr (nd 6); schedule-on fills the jr delay slot with the andi but
   reorders the srl ahead of the store (nd 8), so the plain -O2 form is
   kept. Residual vs retail (lw/sw/srl/jr/andi): the andi/jr pair swapped.
   Translation-unit hypothesis: the parked bodies below were audited together;
   eight +0x40 loaders currently active in the probe had nd/object 46/68/72
   (f178), 39/64/72 (f1c0), 2/16/16 (f2a8), 8/32/32 (f2d0), 5/24/24
   (f550), 3/24/24 (f5e0), and 2/36/40 (f788/f7b0). Named locals, parameter
   reassignment, fully inline expressions, declaration orders, pointer and
   scalar types, and pragma wrappers did not move any destination. */
/* measured: compared with matching code1_0048 and code1_0051, this TU has the
   same include set (`include_asm.h`, `type.h`), no data externs/globals, and
   only the three helper declarations. Each pragma is locally closed; none
   spans the file. One-at-a-time probes of old/prototyped helper forms,
   explicit extern, helper widths, include order, and a file-wide schedule
   extension left all eight active rows exactly unchanged. The uniform
   register divergence is therefore not a declaration environment defect. */
/* measured: retail call-site audit confirms func_0041e8d8 is old-style:
   f178/f1c0/f500 enter its jal with the existing a0-a3 values and do not
   materialize a prototype-defined argument list. The promoted TU now uses
   `s32 func_0041e8d8();`; typed one-pointer declarations for 00420e50 and
   00420f38 agree with their retail callers. No data globals are declared in
   this TU, so there is no array-versus-scalar global correction to test.
   Declaration-environment audit left every parked nd unchanged. */

void func_00420e50(u8 *);

void func_00420f38(u8 *);
void func_00420cc8(u8 *, u8 *);
extern u8 D_00753AF0[];
extern u8 D_00753B20[];
extern u8 D_0070C3C0[];
extern u8 D_00753B38[];
extern u8 D_00753B70[];
void func_00418df8(s32 *);

void func_0041ed48(u8 *);
void func_0041eeb8(u8 *);
void func_00418e68(u8 *, u32, s32 *);

// FUN_004125E0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004125e0);

// FUN_00412CA0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00412ca0);

// FUN_00412E90
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00412e90);

// FUN_00412FB0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00412fb0);

// FUN_00413290
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00413290);

// FUN_00413350
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00413350);

// FUN_00413410
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00413410);

// FUN_00413640
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00413640);

// FUN_00413700
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00413700);

// FUN_00413B80
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00413b80);

// FUN_00413E50
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00413e50);

// FUN_004140F0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004140f0);

// FUN_004141E0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004141e0);

// FUN_004142B0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004142b0);


/* measured: no_branch_likely-on preserves retail's plain null branch. */
#pragma no_branch_likely on
/* measured: opt_rebuildconditionals-off preserves the retail two-branch null path. */
#pragma opt_rebuildconditionals off
/* measured: schedule-on reproduces allocator and store delay-slot order. */
#pragma schedule on
// FUN_00414390
void func_00414390(u8 *arg0, u8 *arg1, u8 ***arg2)
{
    u8 **node;

    node = func_004117b0(8);
    switch ((u32)*arg2) {
    case 0:
        goto assign_node;
    default:
        goto write_node;
    }
write_node:
    node[0] = arg0;
    node[1] = *(u8 **)(arg0 + 8);
    goto done;
assign_node:
    *arg2 = node;
    goto write_node;
done:
    ;
}
/* measured: closes schedule-on around func_00414390. */
#pragma schedule off
/* measured: closes no_branch_likely around func_00414390. */
#pragma no_branch_likely off
/* measured: closes opt_rebuildconditionals-off around func_00414390. */
#pragma opt_rebuildconditionals on

// FUN_004143F0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004143f0);

// FUN_004147A0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004147a0);


// FUN_00414820
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414820);

// FUN_00414930
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414930);

// FUN_00414A30
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414a30);


/* Probed: scheduler, no_branch_likely-on and opt_rebuildconditionals-off were
   each measured around a candidate body for func_00414b50, which reached
   object 192B against a 192B window at normalized_diff 19; residual was
   register colouring, float load ordering and branch-delay scheduling.
   The candidate was reverted, so no pragma bracket is kept here: pragmas do
   not affect an INCLUDE_ASM body. Reinstate them only alongside a real body. */
// FUN_00414B50
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414b50);

// FUN_00414C10
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414c10);

// FUN_00414E10
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414e10);

// FUN_00414EF0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414ef0);

// FUN_00414FD0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00414fd0);

// FUN_00415070
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00415070);

// FUN_004151B0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004151b0);

// FUN_00415340
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00415340);

// FUN_00415580
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00415580);

// FUN_004156E0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004156e0);

// FUN_00415920
void func_00415920(void) {}

// FUN_00415930
/* measured: schedule on preserves retail's jr delay-slot return and leaves
   the aligned 16-byte tiny body. */
#pragma schedule on
s32 func_00415930(void) { return 1; }
/* measured: closes the schedule scope for the 16-byte return-one stub. */
#pragma schedule off

// FUN_00415940
void func_00415940(void) {}

// FUN_00415950
/* measured: schedule on preserves retail's jr delay-slot return and leaves
   the aligned 16-byte tiny body. */
#pragma schedule on
s32 func_00415950(void) { return 1; }
/* measured: closes the schedule scope for the 16-byte return-one stub. */
#pragma schedule off

// FUN_00415960
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00415960);
// FUN_00415AD0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00415ad0);

// FUN_00415BC0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00415bc0);

// FUN_004165A0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004165a0);

// FUN_00416BC0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00416bc0);


// FUN_00416CF0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00416cf0);

// FUN_00416DF0
/* measured: schedule-on probe puts the final addiu in the return delay slot. */
#pragma schedule on
/* measured: opt_propagation off retains the multiplier register. */
#pragma opt_propagation off
s32 func_00416df0(u8 *arg0)
{
    s32 mul;
    s32 value;

    mul = 0x16;
    value = *(s32 *)(arg0 + 4);
    return (mul * value) + 0x18;
}
/* measured: close the schedule scope after the multiplier probe. */
#pragma schedule off
/* measured: close the opt_propagation scope after the multiplier probe. */
#pragma opt_propagation on

// FUN_00416E10
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00416e10);

// FUN_00417310
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417310);
// FUN_00417470
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417470);

// FUN_00417510
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417510);

/* measured: schedule-on places the global-address addiu in retail's jr delay slot. */
#pragma schedule on
// FUN_004176A0
u8 *func_004176a0(void)
{
    return D_0070C3C0;
}
/* measured: closes schedule-on for the global-address accessor. */
#pragma schedule off

// FUN_004176B0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004176b0);

// FUN_00417718
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417718);

// FUN_004177B8
asm void func_004177b8(void)
{
    .set noreorder
    .word 0x24030080 /* addiu $v1, $zero, 128 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}


// FUN_004177C8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004177c8);

// FUN_00417B40
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417b40);

// FUN_00417C00
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417c00);

// FUN_00417CC8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417cc8);

// FUN_00417EB0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417eb0);

// FUN_00417F98
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00417f98);

// FUN_00418030
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418030);

// FUN_00418348
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418348);

// FUN_00418488
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418488);

// FUN_00418B18
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418b18);

// FUN_00418BB8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418bb8);

// FUN_00418D98
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418d98);

// FUN_00418DF8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418df8);

// FUN_00418E68
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418e68);
// FUN_00418EF0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418ef0);
// FUN_00418F18
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418f18);
// FUN_00418F50
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418f50);

// FUN_00418F78
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00418f78);
// FUN_00419058
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419058);

// FUN_00419230
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419230);


// FUN_00419268
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419268);

// FUN_00419280
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419280);

// FUN_004192E8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004192e8);
// FUN_00419360
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419360);
// FUN_004193D8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004193d8);

// FUN_00419420
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419420);

// FUN_004194A0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004194a0);

/* measured: schedule-on probe for the conditional helper wrapper. */
#pragma schedule on
// FUN_00419520
s32 func_00419520(u32 *arg0, s32 arg1)
{
    if (arg1 == 1) {
        return ((u32)*arg0 >> 8) & 1;
    }
    func_00418df8((s32 *)arg0);
    return 0;
}
/* measured: closes schedule-on probe for the conditional helper wrapper. */
#pragma schedule off

/* measured: object/window 52/56; conditional helper wrapper reproduces every
   retail instruction, with the retail trailing alignment word left as window
   padding. The opt-propagation-off and schedule-on brackets below are both
   load-bearing for this body. */
// FUN_00419558
/* measured: opt-propagation-off probe for the conditional helper wrapper. */
#pragma opt_propagation off
/* measured: schedule-on probe for the conditional helper wrapper. */
#pragma schedule on
s32 func_00419558(u8 *arg0, u32 arg1, s32 arg2, s32 *arg3)
{
    if (arg2 == 1) {
        return *(u32 *)(arg0 + 0x10) < arg1;
    }
    func_00418e68(arg0, arg1, arg3);
    return 0;
}
/* measured: closes schedule-on probe for the conditional helper wrapper. */
#pragma schedule off
/* measured: closes opt-propagation-off probe for the conditional helper wrapper. */
#pragma opt_propagation on


// FUN_00419590
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419590);

// FUN_00419628
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419628);


/* measured: retail fills the jr delay slot with the return value
   (jr $ra; addiu $v0,$zero,1 = 8 bytes). Scheduling is off at file scope here,
   so without this pragma b210 emits addiu; jr; nop and the object is 12 bytes
   against an 8-byte window. */
/* floor by name: func_0041c2f8 is a R5900 MMI byte-pack loop. Retail uses the
   sequence mtsab $a4,0; qfsrv $a6,$a5,$a4; pextlb $a4,$zero,$a6; pextub
   $a5,$zero,$a6, followed by two 128-bit stores per iteration. The generated
   C records these as unknown MMI instructions; ordinary C cannot express the
   required COP/MIPSI byte-lane operations and inline asm is forbidden. */

// FUN_00419640
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419640);
// FUN_004197C8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_004197c8);

// FUN_00419ED0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_00419ed0);

// FUN_0041A120
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041a120);

// FUN_0041A5A8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041a5a8);

// FUN_0041A7C8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041a7c8);

// FUN_0041AA08
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041aa08);

// FUN_0041AD38
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041ad38);

// FUN_0041B160
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041b160);

// FUN_0041B300
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041b300);

// FUN_0041B858
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041b858);

// FUN_0041B9D0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041b9d0);

// FUN_0041BB38
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041bb38);

// FUN_0041BCB8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041bcb8);

// FUN_0041BDA0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041bda0);

// FUN_0041BE30
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041be30);
// FUN_0041BEC8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041bec8);

/* measured: tailcall-on probe for the direct retail jump wrapper. */
#pragma tailcall on
// FUN_0041BF00
void func_0041bf00(void)
{
    func_0041be30();
}
/* measured: closes tailcall-on probe for func_0041bf00. */
#pragma tailcall off

// FUN_0041BF08
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041bf08);

// FUN_0041BFC8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041bfc8);

// FUN_0041C0B8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c0b8);

// FUN_0041C178
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c178);
// FUN_0041C2F8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c2f8);

/* archived candidates: lowest nd36 tail-return (obj/window 72/80), plain
   void nd37 (72/80), and schedule-off nd59 (96/80). Exact fndiff tables,
   bodies, and ruled-out list: build/WBDatCalc_0041E198_archive.txt. */

// FUN_0041C370
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c370);

// FUN_0041C408
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c408);

// FUN_0041C4C0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c4c0);

// FUN_0041C590
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c590);

// FUN_0041C640
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c640);

// FUN_0041C6F8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c6f8);

// FUN_0041C7F0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c7f0);

// FUN_0041C8F0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c8f0);

// FUN_0041C990
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041c990);

// FUN_0041CA40
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041ca40);

// FUN_0041CB20
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041cb20);

// FUN_0041CC08
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041cc08);

// FUN_0041CCE0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041cce0);

// FUN_0041CDB0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041cdb0);

// FUN_0041CED0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041ced0);

// FUN_0041CFE8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041cfe8);

// FUN_0041D088
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041d088);

// FUN_0041D228
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041d228);

// FUN_0041D540
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041d540);

// FUN_0041D7F0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041d7f0);

// FUN_0041D890
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041d890);

// FUN_0041D9D8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041d9d8);

// FUN_0041DB18
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041db18);

/* measured: schedule-on bracket for func_0041dc00. */
#pragma schedule on
/* measured: tailcall-on bracket for func_0041dc00. */
#pragma tailcall on
// FUN_0041DC00
void func_0041dc00(u8 *arg0) {
    func_00420cc8(arg0, D_00753AF0);
}
/* measured: closes tailcall-on bracket for func_0041dc00. */
#pragma tailcall off
/* measured: closes schedule-on bracket for func_0041dc00. */
#pragma schedule off

/* measured: schedule-on bracket for func_0041dc10. */
#pragma schedule on
/* measured: tailcall-on bracket for func_0041dc10. */
#pragma tailcall on
// FUN_0041DC10
void func_0041dc10(u8 *arg0) {
    func_00420cc8(arg0, D_00753B20);
}
/* measured: closes tailcall-on bracket for func_0041dc10. */
#pragma tailcall off
/* measured: closes schedule-on bracket for func_0041dc10. */
#pragma schedule off

// FUN_0041DC20
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041dc20);

/* measured: schedule-on bracket for func_0041de08. */
#pragma schedule on
/* measured: tailcall-on bracket for func_0041de08. */
#pragma tailcall on
// FUN_0041DE08
void func_0041de08(u8 *arg0) {
    func_00420cc8(arg0, D_00753B38);
}
/* measured: closes tailcall-on bracket for func_0041de08. */
#pragma tailcall off
/* measured: closes schedule-on bracket for func_0041de08. */
#pragma schedule off

/* measured: schedule-on bracket for func_0041de18. */
#pragma schedule on
/* measured: tailcall-on bracket for func_0041de18. */
#pragma tailcall on
// FUN_0041DE18
void func_0041de18(u8 *arg0) {
    func_00420cc8(arg0, D_00753B70);
}
/* measured: closes tailcall-on bracket for func_0041de18. */
#pragma tailcall off
/* measured: closes schedule-on bracket for func_0041de18. */
#pragma schedule off

// FUN_0041DE28
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041de28);

// FUN_0041DFF8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041dff8);

/* measured: tailcall-on probe for the direct retail jump wrapper. */
#pragma tailcall on
// FUN_0041E030
void func_0041e030()
{
    func_0041be30();
}
/* measured: closes tailcall-on probe for func_0041e030. */
#pragma tailcall off

// FUN_0041E038
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e038);

/* measured: schedule-on moves the constant into the retail jump delay slot. */
#pragma schedule on
/* measured: tailcall-on probe for the argument-materializing wrapper. */
#pragma tailcall on
// FUN_0041E190
void func_0041e190(s32 arg0)
{
    func_0041e030(arg0, 0x20);
}
#pragma tailcall off
/* measured: closes schedule-on probe for func_0041e190. */
#pragma schedule off
// Archived C body: build/WBDatCalc_0041E198_archive.txt
// FUN_0041E198
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e198);



// FUN_0041E1E8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e1e8);
// FUN_0041E278
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e278);
// FUN_0041E310
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e310);
// FUN_0041E408
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e408);
// FUN_0041E4D8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e4d8);
// FUN_0041E710
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e710);
// FUN_0041E810
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e810);
// FUN_0041E8D8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041e8d8);
// FUN_0041EA90
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041ea90);
// FUN_0041ED48
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041ed48);
// FUN_0041EEB8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041eeb8);
// FUN_0041F080
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f080);
/* measured: schedule-on bracket for the 8-byte return-one function. */
#pragma schedule on
// FUN_0041F130
s32 func_0041f130(void)
{
    return 1;
}
/* measured: closes schedule-on bracket for func_0041f130. */
#pragma schedule off

/* measured: the whole body is right -- retail's jal passes $a0 and $a1
   untouched from entry (arg0 and the masked tag), the 0x40 pointer lives in
   $a3, and #pragma schedule on puts the last store in the jal delay slot.
   The single residual is how b210 lowers `& 0x0FFFFFFF`: it clears the top
   36 bits of the 64-bit register with `dsll32 4 / dsrl32 4` (2 words) where
   retail materialises the constant and ANDs (`lui 0xfff / ori 0xffff / and`,
   3 words), so the object is 68 bytes in a 72-byte window and everything
   after the mask slides by one. Measured unchanged at nd 45-46: u32 and u8*
   parameter types, `~0xF0000000`, an explicit (u32) cast, splitting the and
   and the or into separate statements, a named s32/u32 local for the result,
   and `(u32)(x << 4) >> 4`; optimization_level 1 reaches nd 37 and level 3
   nd 36 but both shrink the object further. Constant-mask lowering floor. */
/* archived candidate: object/window 68/72, normalized_diff 46 (lower
   optimization probes nd 37/36 shrink the object and were not retained).
   Exact fndiff rows and the complete body are in the archive below. */

// FUN_0041F138
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f138);
// Archived C body: build/WBHygiene_func_0041f178_archive.txt
// FUN_0041F178
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f178);

/* measured: the whole body is right -- retail's jal passes $a0 and $a1
   untouched from entry (arg0 and the masked tag), the 0x40 pointer lives in
   $a3, and #pragma schedule on puts the last store in the jal delay slot.
   The single residual is how b210 lowers `& 0x0FFFFFFF`: it clears the top
   36 bits of the 64-bit register with `dsll32 4 / dsrl32 4` (2 words) where
   retail materialises the constant and ANDs (`lui 0xfff / ori 0xffff / and`,
   3 words), so the object is 68 bytes in a 72-byte window and everything
   after the mask slides by one. Measured unchanged at nd 45-46: u32 and u8*
   parameter types, `~0xF0000000`, an explicit (u32) cast, splitting the and
   and the or into separate statements, a named s32/u32 local for the result,
   and `(u32)(x << 4) >> 4`; optimization_level 1 reaches nd 37 and level 3
   nd 36 but both shrink the object further. Constant-mask lowering floor. */
/* archived candidate: object/window 64/72, normalized_diff 39. Exact
   fndiff evidence and the complete body are in the archive below. */
// Archived C body: build/WBHygiene_func_0041f1c0_archive.txt
// FUN_0041F1C0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f1c0);


// FUN_0041F218
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f218);
// FUN_0041F298
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f298);
// FUN_0041F2A8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2a8);



/* measured: retail sinks the third store into the jr $ra delay slot, which
   b210 only does under schedule on -- and only while the stored-through
   pointer is already in $v0, which needs the discarded `return p`. Without
   the return the pointer colours $v1 and the slot stays a nop (nd 4). */
// FUN_0041F2B8
#pragma schedule on
u8 *func_0041f2b8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s32 *)(p + 0xB0) = arg3;
    *(s32 *)(p + 0xA8) = arg1;
    *(s32 *)(p + 0xAC) = arg2;

    return p;
}
/* measured: closes schedule-on bracket for f1f2b8. */
#pragma schedule off



// FUN_0041F2D0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2d0);
// FUN_0041F2F0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f2f0);

/* measured: schedule-on probe for f1f328 delay-slot/prologue ordering. */
#pragma schedule on
// FUN_0041F328
s32 func_0041f328(u8 *arg0, u32 arg1)
{
    u8 *temp4;
    s32 ret;
    extern void func_0041e408(u8 *);

    temp4 = *(u8 **)(arg0 + 0x40);
    if (arg1 < 2U) {
        goto body;
    }
    ret = -1;
    goto done;
body:
    *(u32 *)(temp4 + 0x87C) = arg1;
    func_0041e408(temp4);
    ret = 1;
done:
    return ret;
}
/* measured: closes schedule-on probe for f1f328. */
#pragma schedule off

// FUN_0041F360
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f360);

// FUN_0041F370
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f370);

// FUN_0041F3E8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f3e8);

// FUN_0041F460
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f460);

// FUN_0041F4A8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f4a8);
// FUN_0041F500
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f500);

// FUN_0041F550
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f550);


/* measured: schedule-on bracket for func_0041f568. */
// FUN_0041F568
#pragma schedule on
s32 func_0041f568(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s64 *)(p + 0x90) = 0;
    *(s32 *)(p + 0x8C) = 0;
    return 1;
}
/* measured: closes schedule-on bracket for func_0041f568. */
#pragma schedule off

/* measured: schedule-on bracket for func_0041f580. */
// FUN_0041F580
#pragma schedule on
s32 func_0041f580(u8 *arg0, s32 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s32 *)(p + 0xEC) = arg1;
    return 1;
}
/* measured: closes schedule-on bracket for func_0041f580. */
#pragma schedule off
// FUN_0041F590
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f590);
// FUN_0041F5A0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f5a0);

/* measured: schedule-on bracket for func_0041f5b0. */
// FUN_0041F5B0
#pragma schedule on
u8 *func_0041f5b0(u8 *arg0)
{
    return *(u8 **)(arg0 + 0x40) + 0xC8;
}
/* measured: closes schedule-on bracket for func_0041f5b0. */
#pragma schedule off

/* measured: schedule-on bracket for func_0041f5c0. */
// FUN_0041F5C0
#pragma schedule on
u8 *func_0041f5c0(u8 *arg0)
{
    return *(u8 **)(arg0 + 0x40) + 0xC8;
}
/* measured: closes schedule-on bracket for func_0041f5c0. */
#pragma schedule off

/* measured: schedule-on bracket for func_0041f5d0. */
// FUN_0041F5D0
#pragma schedule on
s32 func_0041f5d0(u8 *arg0, s32 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);
    s32 value = *(s32 *)(p + 0xFC);

    *(s32 *)(p + 0xFC) = arg1;
    return value;
}
/* measured: closes schedule-on bracket for func_0041f5d0. */
#pragma schedule off


// FUN_0041F5E0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f5e0);


// FUN_0041F5F8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f5f8);
// FUN_0041F6C8
/* measured: schedule-on retains func_0041f6c8 store order. */
#pragma schedule on
void func_0041f6c8(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0xC) = arg1;
    *(s32 *)(arg0 + 4) = arg2;
    *(s32 *)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 8) = arg1;
}
/* measured: closes schedule-on after func_0041f6c8. */
#pragma schedule off
// FUN_0041F700
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f700);

// FUN_0041F770
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f770);



// FUN_0041F788
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f788);


// FUN_0041F7B0
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f7b0);

// FUN_0041F7D8
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041f7d8);
// FUN_0041FA68
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041fa68);
// FUN_0041FD28
INCLUDE_ASM("asm/nonmatchings/code1_0041", func_0041fd28);