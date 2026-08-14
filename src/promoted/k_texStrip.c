#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_texStrip.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

extern void func_00428618(s32 arg0);
extern void func_0044ea90(const void *file, u32 line);
extern void func_00440b68(const char *fmt, ...);
extern void *(*D_008873F4[])(s32, s32, s32);
extern s32 func_003ef650(s32 arg0, s32 arg1);
extern void func_003ef610(s32 arg0);
extern void func_003ef5b0(s32 arg0, s32 arg1);
extern s32 func_00451fc0(s32 arg0, const char *arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 (*arg5)(u8 *), void (*arg6)(u8 *),
                         void *arg7);
extern s32 func_00468170(void *arg0, const char *arg1);
extern s32 func_004680f0(s32 arg0, void *arg1);
extern void func_00462eb0(void *arg0);
extern void func_00452080(s32 handle);
extern char D_005F6168[];
extern char D_005F6178[];
extern char D_005F6190[];
extern char D_005F61B0[];
extern char D_005F63E0[];
extern char D_005F6490[];
extern char D_005F64A8[];

extern s32 func_003e2f60(s32 a, s32 b, s32 *c);
extern s32 func_003df3c0(s32 a, s32 *b);
extern void func_003e2910(s32 a, void *b, s32 c);
extern void func_003deff0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_003e2ab0(s32 a, void *b, s32 c);
extern void func_003e2ce0(s32 a, s32 b);
extern void func_003e2e40(s32 a, s32 b);
extern s32 func_003e6a90(s32 a);
extern s32 func_00442088(void *buf, const char *fmt, ...);
extern s32 func_004288d8(void *a, void *b);
extern u8 *func_00454a60(void *path, s32 flags);
extern void func_00456150(void *handle);
extern void func_00454bd0(void *handle);
extern void func_00442428(void *dst, const void *src);
extern void func_003ef1b0(s32 arg0);
extern void func_003ef260(s32 arg0, s32 (*arg1)(s32, s32), s32 arg2);
extern void func_003e6870(void *arg0, void *arg1);
extern s32 func_00190920(s32 arg0, s32 arg1);
extern char D_005F63F0[];
extern char D_005F6430[];
extern char D_005F6450[];
extern char D_005F6470[];
extern char D_00763128;
extern char D_00763130;
extern char D_00763138;
extern char D_0076313C;
extern char D_00763140;
extern char D_00763148;
extern char D_00763150;
extern char D_00763158;
extern s32 D_00764498;

extern s32 func_00428550(const char *path);
extern s32 func_00428780(s32 handle, void *out);
extern s32 func_004426e8(void *a, const void *b);
extern void func_00442830(void *dst, const void *src);
extern u8 *func_00150970(void *path);
extern s32 func_00150c80(void *hdr);
extern void func_00150ce0(void *hdr);
extern s32 func_001510c0(void *hdr);
extern s32 func_004581a0(void *a, const void *b);
extern void func_00458430(s32 *out, void *a, const void *b, s32 c);
extern s32 func_00426cf0(void *path, s32 a, s32 b);
extern s32 func_00442948(void *buf);
extern s32 sceWrite(s32 fd, void *buf, s32 n);
extern s32 sceRead(s32 fd, void *buf, s32 n);
extern void func_00426f80(s32 fd);
extern void func_00428f08(void *a, s32 b);
extern void func_00151f80(void *hdr);
extern void func_00463250(void *a);
extern char D_005F61D0[];
extern char D_005F61F8[];
extern char D_005F6210[];
extern char D_005F6230[];
extern char D_005F6250[];
extern char D_005F6270[];
extern char D_005F62A0[];
extern char D_005F62B0[];
extern char D_005F62C0[];
extern char D_005F62D0[];
extern char D_005F6310[];
extern char D_005F6350[];
extern char D_005F6370[];
extern char D_005F63B0[];

s32 func_00190680(u8 *arg0, void *arg1);
void func_001909f0(u8 *arg0, void *arg1, u8 *arg2);
s32 func_00190c10(u8 *arg0);
s32 func_001916a0(u8 *arg0, void *arg1);
s32 func_00191850(u8 *arg0);



// measured: nd 115 after 4 attempts (best). Spill-slot rule as func_001916a0: the four
// func_003df3c0 spill slots MUST be `s32 spill[4]`. Switch `case 0x16 / case 0xF0F000E0 /
// default` compiles the dispatch comparison in the correct order (0xF0F000E0 first, then 0x16)
// and matches retail exactly. Residual nd 115 is dominated by register allocation: retail keeps
// sp60/sp64/sp68 (the 0x14-byte func_003e2910 buffer + sp64/sp68) on the STACK at 0x60/0x64/
// 0x68, but mwcc promotes sp64/sp68 to $s5/$s6 (sp68 folded with `sll $s6,2` / `addu $s0,$s6,$s6`)
// adding a 5th/6th saved reg, so the whole allocation shifts (retail wants var_16->$s0, arg1/
// temp_2->$s1, temp_18->$s2, temp_19->$s3, var_20->$s4). Making sp60/sp64/sp68 overlap via a
// 5-word array (nd 138) or a 3-field struct (nd 141) is worse. Core regs are otherwise right.
// QTEX lane: plain-C candidate reached object 668/window 672, normalized_diff 20.
// s32 sp[2], s32 spill[4], and buffer[5] reproduce the 0xA0 frame and saved-register
// coloring; only two func_003deff0 calls retain b210's move-before-stack-load order.
// Shared-callee probe: retail func_003deff0 first-uses a0 as a forwarded pointer,
// saves a1/a2, and masks a3/t0, proving five args `(void *,s32,s32,s32,s32)`.
// Existing calls already pass all five; block-scope pointer declarations, explicit
// pointer casts, and the canonical s32 return produced no nd change.
// FUN_00190680
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_00190680);

// measured: nd 16 after 4 attempts (baseline edit-fndiff, hoisted-local probe, u8*-ptr probe, struct-field probe).
// Residual is pure argument MATERIALIZATION order: retail emits the first arg (move $a0,$s0)
// then the second (addiu $a1,$s1,0x10); mwcc b210 always emits the `addiu $s1,0x10` (last arg)
// first. Call sites: func_003ef650(arg1, arg0+0x10), func_00440b68(str, arg0+0x10). The named
// "argument order / struct field" recipe (mgr->size) does not apply: the second arg is an
// ADDIU address computation, not a memory load, so reaching it through a struct field produces
// a hoisted base local (nd 32+) and the u8* pointer spelling rotates the whole frame (nd 46).
// Floor appears to be mwcc right-to-left arg scheduling for a computed address operand.
// QTEX lane: baseline candidate object 196/window 208, normalized_diff 37; the 12-byte
// tail is zero padding. Pointer-signature/block-prototype probe was a redeclaration error;
// hoisted address local was optimized away or produced nd 120. Archived in build/QTEX_00190920_body.c.
// FUN_00190920
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_00190920);


// measured: nd 102 after 5 attempts (best). Same spill-slot rule as func_001916a0: the four
// func_003df3c0 spill slots MUST be `s32 spill[4]` (else sp74 promotes to a 5th saved reg).
// Register order that works: declare temp_20,temp_19,temp_18,temp_4,var_17,var_16 (first-declared
// -> highest saved reg) giving arg1->$s1, arg2->$s5, temp_20->$s4, temp_19->$s3, temp_18->$s2,
// var_17->$s1, var_16->$s0 -- all matching retail. Residual nd 102 is three floors: (1) the
// sp88/sp8C stack offset swap (arg0[0x110]->sp88 and [0x118]->sp8C land at 0x8C/0x88 reversed;
// declaration order does not move it, same as sp68/sp6C in func_001916a0); (2) the case-0x16
// dispatch: `if (spill[0]==0x16)` emits `bne` skip where retail emits `beq`+`b` (both the switch
// form and the reversed `!=0x16` form are worse, nd 108/104); (3) the same argument-order floor
// as func_00190920/func_001916a0 (func_003deff0/func_003e2910/func_003e2ab0 emit the last arg
// first).
// QTEX lane: switch/goto candidate object 532/window 544, normalized_diff 10; all six
// differing words are the same func_003deff0 move-before-stack-load order. Archived in
// build/QTEX_001909f0_body.c.
// Shared-callee probe confirmed the same canonical five-argument signature and no
// improvement (nd remained 10), so this is not an argument-count/width defect.
// FUN_001909F0
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_001909f0);

// measured: not attempted to a measured nd (m2c draft written but the measurement was lost to a
// file-overwrite accident; reverted to INCLUDE_ASM). Largest function in the file (2480 B).
// State machine dispatched by a jump table (jtbl_00746EC0) on *(u32*)(*arg0+0x38) with 9 cases
// (0..8). gp-relative symbols verified: `saved_reg_gp - 0x5FB8/0x5FB4/0x5FB0/0x5FA8/0x5FA0/0x5FC0`
// = 0x00763138/0x13C/0x140/0x148/0x150/0x130 = &D_00763138/3C/40/48/50/30, and `-0x4C58` = 0x00764498
// = &D_00764498. Complex: nested loops over 0x254/0xA58 element lists, sceRead/sceWrite file I/O,
// and the func_00190680/func_001909f0/func_00190c10 cross-call chain. High risk of the same
// argument-order floor as the other four functions; left for a dedicated pass.
// QTEX lane: full state-machine candidate object 2444/window 2480, normalized_diff 1628;
// its 0x8F0 frame versus retail 0x6F0 triggered automatic archive as a materially
// different reconstruction. No confirmed compiler-floor instruction was present.
// FUN_00190C10
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_00190c10);

// FUN_001915C0
void func_001915c0(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191610
s32 func_00191610(void)
{
    void *mem;

    func_0044ea90(D_005F6168, 0x2ED);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return func_00451fc0(0, D_005F63E0, 0xF, 0, 0, func_00190c10,
                         func_001915c0, mem);
}

// measured: nd 80 after 7 attempts. Spill-slot fix: the four func_003df3c0 spill slots
// (sp50/sp54/sp58/sp5C) MUST be a 4-element array `s32 spill[4]` passed as &spill[0] and read
// as spill[1..3] -- naming them as separate s32 scalars promotes sp54 to a saved reg $s4 and
// adds a 5th saved reg (nd 92). With the array they stay on the stack at 0x50-0x5C (nd 82).
// Register order that reproduces retail: arg0[0x110]->sp68, arg0[0x118]->sp6C, arg1->$s1,
// var_19->$s3, temp_18->$s2, temp_17->$s1, var_16->$s0. Remaining nd 80 is the SAME
// argument-materialization floor as func_00190920 (mwcc emits the last arg first for calls
// taking a computed address/lvalue, e.g. func_003deff0(temp_17,spill[0],spill[1],spill[2],
// spill[3]) and func_003e2910(temp_18,var_16,spill[1])), plus a stubborn sp68/sp6C stack
// offset swap (declaration order does not move it).
// QTEX lane: s32 sp[2] plus s32 spill[4], switch/goto loop layout, and declaration
// order reached object 420/window 432, normalized_diff 10; the six differing words
// are only func_003deff0 argument materialization. Archived in build/QTEX_001916a0_body.c.
// Shared-callee probe confirmed the same canonical five-argument signature and no
// improvement (nd remained 10), so this is not an argument-count/width defect.
// FUN_001916A0
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_001916a0);

// FUN_00191850
s32 func_00191850(u8 *arg0)
{
    char buf240[0x40];
    char buf140[0x100];
    char buf40[0x100];
    s32 *work;
    s32 i;
    u8 *temp1;
    u8 *temp2;

    work = *(s32 **)(arg0 + 0x38);
    switch (work[0])
    {
    case 0:
        work[0x39C] = 2;
        work[0x95] = 0;
        work[0] = work[0] + 1;
        /* fallthrough */
    case 1:
        func_00442088(&work[0x53], D_005F63F0, work[0x39B], work[0x39C]);
        if (func_004288d8(&work[0x53], buf240) == 0)
        {
            func_00442088(&work[0x53], D_005F6430, work[0x39B], work[0x39C]);
            func_00440b68(&D_00763150, D_005F6168, 0x36E);
            temp1 = (u8 *)func_00454a60(&work[0x53], 0);
            work[0x94] = (s32)temp1;
            func_00456150(temp1);
            work[0] = 2;
            work[0x39C] = work[0x39C] + 1;
            func_00440b68(&D_00763128, &work[0x53]);
        }
        else
        {
            work[0x39C] = work[0x39C] + 1;
            if (work[0x39C] > 0xF)
            {
                work[0] = 3;
            }
        }
        break;
    case 2:
        func_00442088(buf140, D_005F6450);
        func_00442428(buf140, &work[0x53]);
        func_00442428(buf140, &D_00763158);
        work[work[0x95] + 0x196] = func_001916a0((u8 *)work[0x94], buf140);
        func_00454bd0((u8 *)work[0x94]);
        work[0x94] = 0;
        work[0x95] = work[0x95] + 1;
        work[0] = 1;
        break;
    case 3:
        func_00442088(&work[0x53], D_005F6470, work[0x39B]);
        func_00440b68(&D_00763150, D_005F6168, 0x39B);
        temp2 = (u8 *)func_00454a60(&work[0x53], 0);
        work[0x94] = (s32)temp2;
        func_00456150(temp2);
        func_00442088(buf40, D_005F6450);
        func_00442428(buf40, &work[0x53]);
        func_00442428(buf40, &D_00763158);
        func_001909f0((u8 *)work[0x94], buf40, (u8 *)work);
        for (i = 0; i < (u32)work[0x95]; i++)
        {
            s32 *elem = (s32 *)((u8 *)work + i * 4 + 0x658);
            if (*(s32 *)((u8 *)work + i * 4 + 0x658) != 0)
            {
                func_003ef1b0(*(s32 *)((u8 *)work + i * 4 + 0x658));
                *elem = 0;
            }
        }
        func_00454bd0((u8 *)work[0x94]);
        work[0x94] = 0;
        work[0x39B] = work[0x39B] + 1;
        if (work[0x39B] > 0x30)
        {
            work[0] = 4;
        }
        else
        {
            work[0] = 0;
        }
        break;
    case 4:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_00191B70
void func_00191b70(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191BC0
s32 func_00191bc0(void)
{
    s32 ret;
    void *mem;

    func_0044ea90(D_005F6168, 0x3D4);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    ret = func_00451fc0(0, D_005F63E0, 0xF, 0, 0, func_00191850,
                        func_00191b70, mem);
    *(s32 *)((u8 *)mem + 0xE6C) = 0x28;
    *(s32 *)((u8 *)mem + 0xE70) = 1;
    return ret;
}

// FUN_00191C70
s32 func_00191c70(u8 *arg0)
{
    s32 *work;
    char buf[0x80];

    work = *(s32 **)(arg0 + 0x38);
    switch (work[0])
    {
    case 0:
        work[1] = func_00468170(arg0, D_005F6490);
        work[0] = work[0] + 1;
        break;
    case 1:
        if (func_004680f0(work[1], buf) == 1)
        {
            if (buf[0] == 0)
            {
                work[0] = 2;
            }
            else
            {
                func_00462eb0(buf);
            }
            func_00452080(work[1]);
            work[0] = 0;
        }
        break;
    case 2:
        return -1;
    }
    return 0;
}

// FUN_00191D60
void func_00191d60(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191D90
s32 func_00191d90(void)
{
    void *mem;

    func_0044ea90(D_005F6168, 0x435);
    mem = D_008873F4[0](1, 0x8, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return func_00451fc0(0, D_005F64A8, 0xF, 0, 0, func_00191c70,
                         func_00191d60, mem);
}
