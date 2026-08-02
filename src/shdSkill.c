#include "include_asm.h"
#include "type.h"

u16 func_00115750(u8 *arg0);
void func_0046d730(const char *file, s32 line);
extern char D_005E4800[];

// FUN_001138C0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_001138c0);

/* measured: retail prologue saves in order `sd $a0,0x48; mov.s $f20,$f12; move $s1,$a1; move $s0,$a2` and sets up the inner call's FP args contiguously (cvt pair then mov.s $f14 before any GPR arg moves). mwcc b210 emits the same four value-saves with the fparg0 instructions last (`sd; move $s1; move $s0; mov.s $f20`) and defers `mov.s $f14,$f20` until after the $a2/$a3/$t0/$t1 setup, for every spelling tried: &arg0 derefs direct, s64 sp48 local, `f32 z = fparg0` first and between, m2c's inline-nested call, and `#pragma schedule on` (which instead reorders the whole body). nd 5, all five words are these two fparg0-scheduling positions; prologue/FP-arg save-order floor. */
// FUN_00113E30
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00113e30);

// FUN_00113EF0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00113ef0);

// FUN_00114460
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114460);

// FUN_00114CB0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114cb0);

/* measured: retail emits its prologue value-saves as `sd $a0,0x30; mov.s $f20,$f12; sw $a1,0x3c; move $s0,$a3`, mwcc b210 emits a rotation of the same four independent saves (`move $s0` first or last, mov.s pinned at slot 2) for every source spelling tried: direct `*(f32 *)&arg0`/`*((u8 *)&arg1+n)` derefs, s64/sp3C locals with decl/assign combined and separated, `f32 z = fparg0` first, alpha split into `alpha = 0xFF; alpha -= byte;` (that split did fix the `subu $v0,$v1,$v0` operand order), and `#pragma schedule on` (which instead if-converts the blez). All give nd 4, all four words are this same rotation; prologue-save scheduling floor. */
// FUN_00114DC0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114dc0);

// FUN_00114E50
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114e50);

// FUN_00115020
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115020);

// FUN_001152B0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_001152b0);


// FUN_00115380
s16 func_00115380(u8 *arg0, s32 arg1) {
    s16 i;
    s32 target;
    s32 count;

    i = 0;
    target = arg1 & 0xFFFF;
    count = *(u16 *)(arg0 + 0x60);
    for (; i < count; i++) {
        if (target == *(u16 *)(arg0 + i * 12 + 2)) {
            return i;
        }
    }
    if (target == (func_00115750(arg0) & 0xFFFF)) {
        return 8;
    }
    return -1;
}

// FUN_00115420
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115420);

// FUN_00115500
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115500);

// FUN_00115760
void func_00115760(u8 *arg0) {
    typedef struct {
        f32 v[3];
    } S3f;
    s32 i;
    s32 off;
    s32 p;

    if (*(u16 *)(arg0 + 0x224) <= 0) {
        func_0046d730(D_005E4800, 0x4B7);
    }
    for (i = 0; i < *(u16 *)(arg0 + 0x224) - 1; i++) {
        *(S3f *)(arg0 + i * 12 + 0x64) = *(S3f *)(arg0 + i * 12 + 0x70);
        *(u16 *)(arg0 + i * 2 + 0x1E4) = *(u16 *)(arg0 + i * 2 + 0x1E6);
    }
    off = *(u16 *)(arg0 + 0x224) * 12;
    p = off + (s32)arg0;
    *(u16 *)(p + 0x5A) = 0;
    off = *(u16 *)(arg0 + 0x224) * 2;
    p = off + (s32)arg0;
    *(u16 *)(p + 0x1E2) = 0;
    *(u16 *)(arg0 + 0x224) -= 1;
}

// FUN_00115670
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115670);

// FUN_00115750
u16 func_00115750(u8 *arg0) {
    return *(u16 *)(arg0 + 0x66);
}

