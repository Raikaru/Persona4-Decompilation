#include "include_asm.h"
/* Persona 4 USA decompilation - cmmCommunity.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_00452380(void *path);
extern u32 func_00452560(s32 task);
extern void func_0046d730(const void *file, u32 line);
extern void func_0044ea90(void *arg0, s32 arg1);
extern s8 func_00248760();
extern s32 func_00247dd0(s32 arg0);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern void func_0026bc10(u16 resourceId, u8 value);
extern s32 func_001077f0();
extern u16 func_00107ac0(s32 arg0);
extern s32 func_00107c80();
extern s32 func_00107ea0();
extern s32 func_001070e0();
extern void func_00108b60(s32 arg0, s32 arg1);
extern s32 func_00108e10(void);
extern f32 D_005E42D8[];
extern f32 D_005E42DC[];
extern f32 D_005E42E0[];
extern f32 D_005E42E8[];
extern f32 D_005E42EC[];
extern f32 D_005E42F0[];
extern f32 D_005E42F8[];
extern f32 D_005E42FC[];
extern f32 D_005E4300[];
extern s32 func_00247c20(s32 arg0);
extern void *func_00246b80(void);
extern u8 *func_00246ba0(void);
extern s32 func_00104f50(s16 arg0, s16 arg1);
extern s16 D_007973F4[];
extern u32 D_0079B1CC[];
extern u8 D_007973A0[];
extern void *func_002467b0(s32 arg0);
extern void func_001076e0(s32 arg0);
extern void func_00106390(s32 a, s32 b);
extern void func_00106db0(s32 a, s32 b);
extern void func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern void func_00108d80(void);
extern void func_00108cb0(void);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u16 D_0079740C[];
extern u8 D_00797410[];
extern s32 D_00797560[];
extern char D_005E42C8[];
extern char D_005E4308[];

// FUN_00106DB0
void func_00106db0(s32 a, s32 b)
{
    s32 id = a & 0xFFFF;
    s32 i;

    if (id <= 0)
    {
        func_0046d730(D_005E42C8, 0x31);
    }
    if (b < 4 || b > 0xC)
    {
        if (b == 1)
        {
            goto bpath;
        }
        goto cpath;
    }
bpath:
    i = 4;
    while (i <= 0xC)
    {
        if (id <= 0)
        {
            func_0046d730(D_005E42C8, 0x1E);
        }
        func_00106390(id + ((i << 5) + 0x3FF), 0);
        i++;
    }
    if (id <= 0)
    {
        func_0046d730(D_005E42C8, 0x1E);
    }
    func_00106390(id + 0x41F, 0);
    goto end;
cpath:
    if ((u32)(b - 2) >= 2)
    {
        goto end;
    }
    if (id <= 0)
    {
        func_0046d730(D_005E42C8, 0x1E);
    }
    func_00106390((a & 0xFFFF) + 0x43F, 0);
    if ((a & 0xFFFF) <= 0)
    {
        func_0046d730(D_005E42C8, 0x1E);
    }
    func_00106390(id + 0x45F, 0);
end:
    func_00106390(id + ((b << 5) + 0x3FF), 1);
}

/* measured: retail keeps func_001070e0()'s result in $s0 and the arg0&0xFFFF
   mask in $s1; mwcc b210 allocates the first-assigned local to $s1 and the
   second to $s0, so return-first source gives the right instruction order
   (jal;nop;move;andi) with the registers swapped, and mask-first source gives
   the right registers with andi emitted before the jal. Tried all declaration
   orders, inline-CSE mask, u16* result type (all nd 10), and mask-first source
   order (best nd 6). Saved-register rotation floor. */
/* measured: nd 7. Reconstructed this wave; the body is right and the residual
   is entirely which of two values gets $s0 - retail keeps func_001070e0's
   result there and the masked id in $s1, b210 the other way round. Probed four
   declaration orders, both assignment orders (id-first is worse at nd 11) and
   opt_common_subs off (nd 224). Committed at nd 7. */
// FUN_00106F40 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/cmmCommunity", func_00106f40);
// FUN_001070B0
void func_001070b0(void)
{
    func_0043f9c8(D_0079740C, 0, 0x158);
}

// FUN_001070E0
s32 func_001070e0(arg0)
s32 arg0;
{
    s32 id = arg0 & 0xFFFF;
    s32 ptr;
    s32 i;

    if (id >= 0x1F)
    {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0)
    {
        return 0;
    }
    ptr = (s32)D_00797410;
    i = 0;
    while (i < 0x15)
    {
        if (*(u16 *)(ptr + 4) == id)
        {
            return ptr;
        }
        ptr += 0x10;
        i++;
    }
    return 0;
}

// FUN_00107180
s32 func_00107180(s16 arg0)
{
    s32 i;
    s32 result;

    result = 0;
    if (arg0 >= 0x15)
    {
        func_0046d730(D_005E42C8, 0x77);
    }
    for (i = 1; i < 0x1F; i++)
    {
        if (arg0 == *(s32 *)func_002467b0(i & 0xFFFF))
        {
            if (func_001077f0((u16)i) != 0)
            {
                result = i;
                break;
            }
        }
    }
    return result & 0xFFFF;
}

// FUN_00107240
s16 func_00107240(s32 arg0)
{
    u32 id = arg0 & 0xFFFF;

    switch (id)
    {
    case 3:
        return 4;
    case 4:
        return 3;
    case 5:
        return 6;
    case 6:
        return 5;
    case 0xB:
        return 0xC;
    case 0xC:
        return 0xB;
    case 0xE:
        return 0xF;
    case 0xF:
        return 0xE;
    case 0x15:
        return 0x16;
    case 0x16:
        return 0x15;
    case 0x19:
        return 0x1A;
    case 0x1B:
        return 0x1C;
    }
    return (s16)arg0;
}

// FUN_00107370
void func_00107370(s32 arg0)
{
    u32 id = arg0 & 0xFFFF;

    switch (id)
    {
    case 3:
        func_001076e0(4);
        break;
    case 4:
        func_001076e0(3);
        break;
    case 5:
        func_001076e0(6);
        break;
    case 6:
        func_001076e0(5);
        break;
    case 0xB:
        func_001076e0(0xC);
        break;
    case 0xC:
        func_001076e0(0xB);
        break;
    case 0xE:
        func_001076e0(0xF);
        break;
    case 0xF:
        func_001076e0(0xE);
        break;
    case 0x15:
        func_001076e0(0x16);
        break;
    case 0x16:
        func_001076e0(0x15);
        break;
    case 0x19:
        func_001076e0(0x1A);
        func_001076e0(0x1C);
        func_001076e0(0x1B);
        break;
    case 0x1A:
        func_001076e0(0x19);
        func_001076e0(0x1C);
        func_001076e0(0x1B);
        break;
    case 0x1B:
        func_001076e0(0x1C);
        func_001076e0(0x1A);
        func_001076e0(0x19);
        break;
    case 0x1C:
        func_001076e0(0x1B);
        func_001076e0(0x1A);
        func_001076e0(0x19);
        break;
    case 0x10:
        func_001076e0(0x11);
        break;
    case 0x11:
        func_001076e0(0x10);
        break;
    }
}

/* measured: retail's slot search keeps the found-exit as an inline
   unconditional branch (bne->advance; b found; advance out-of-line), the same
   shape mwcc b210 emits for `if (cond) return;` in func_001070e0. mwcc merges
   `if (cond) goto found;` (any if/else polarity) into a single beqz->found with
   the advance inline. Tried while+break+retest (re-test not folded), goto,
   both if/else orders — all nd 10. Branch-shape floor. */
// FUN_001075D0
void func_001075d0(s32 arg0) {
    u8 *r;
    u8 *p;
    s32 i;

    if (func_001077f0(arg0) != 0) {
        return;
    }
    func_00107370(arg0);
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == 0) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        func_0046d730(D_005E42C8, 0x107);
    }
    if ((arg0 & 0xFFFF) == 0) {
        func_0046d730(D_005E42C8, 0x108);
    }
    func_0043f9c8(r, 0, 0x10);
    *(s32 *)r = 0;
    *(s16 *)(r + 4) = arg0;
    *(s16 *)(r + 6) = 1;
    func_00106db0(arg0, 0);
    func_00106db0(arg0, 4);
}

/* measured: retail's slot search emits the found-exit as an inline
   unconditional branch (bne->advance; b found) exactly like func_001070e0's
   `if (cond) return;`, but this is void with shared tail code. mwcc b210 merges
   any single-goto if/else branch into a conditional branch to the target
   (beq->found), and a post-loop NULL retest is only free (reuses the loop slti)
   when kept off the found path via goto; ==/> retest forms regress. Best nd 10
   (goto + >= retest); 4 attempts. Branch-shape + retest floor. */
/* Community-slot scan family (func_001076e0/1077f0/107a00/107bd0/107ce0/107dc0/
   107f00/107fe0): walk 21 records of stride 16 from D_007973A0[0x70] looking for a
   matching id. All eight sit at nd 38 with the body below, recovered from the m2c
   draft via tools/draft_probe.py. Two m2c defects had to be repaired first: the
   pointer is typed `s32 *` and advanced by `+= 0x10`, which walks 64 bytes per record
   instead of 16 (silently wrong, still compiles), and the base is emitted as a bare
   address literal D_00797410 that no file declares.
   The residual is one branch shape: retail leaves the loop on a match with a
   bne-to-advance plus b-to-exit PAIR, b210 with a single beq-to-exit. Measured NOT
   reachable via goto, break, inverted test with continue, advance-in-else, an
   explicit entry-goto mirroring retail block order, do/while, a single-case switch
   (right size, booleanised compare), while+break (nd 48-65, and it is what fixed
   evtMain func_00288020, so it is shape-specific not universal), s16/s32/u16
   signatures, and eleven control-flow pragmas including opt_rotateloops both ways.
   An in-loop `return` DOES produce the pair at the exact window size but then
   materialises its own return value where retail falls into the shared block.
   Committed at nd 72. */
// FUN_001076E0
void func_001076e0(s32 arg0) {
    s32 j;
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        func_0043f9c8(r, 0, 0x10);
        if (id <= 0) {
            func_0046d730(D_005E42C8, 0x27);
        }
        j = 0;
        while (j < 0xD) {
            func_00106390(id + ((j << 5) + 0x3FF), 0);
            j++;
        }
    }
}

/* measured: retail slot search emits found-exit as inline unconditional b
   (bne->advance; b found) which mwcc b210 only produces for return-thens
   (func_001070e0); goto/break/switch/continue/m2c-goto-loop spellings all
   merge to a single conditional branch (best nd 14, m2c verbatim form has
   test-at-top layout). Shared tail after the loop blocks the return idiom.
   Branch-shape floor. */
/* measured: retail's slot search found-exit (bne->advance; b found) is the
   return-then shape: an in-loop `return var_4 != NULL;` reproduces the branch
   pair exactly but duplicates the sltu value computation at the loop site
   (nd 17); goto/break/switch forms merge into a single conditional branch
   (best nd 14 m2c-goto form). The found path must jump to the shared return
   block, which mwcc b210 only does for the merged goto. Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_001077F0
s32 func_001077f0(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    return r != NULL;
}

// FUN_00107890
s32 func_00107890(s32 arg0)
{
    s32 i;
    s32 id;

    i = 0;
    id = arg0 & 0xFFFF;
    while (i < 0x1F)
    {
        if ((id == func_00248760(i & 0xFFFF)) && (func_001070e0(i & 0xFFFFu) != 0))
        {
            return func_00107ac0((u16)i) & 0xFFFF;
        }
        i++;
    }
    return 0;
}

// FUN_00107930
s32 func_00107930(s32 arg0)
{
    switch (arg0)
    {
    case 0:
        if (func_00247dd0(1) & 0xFFFF)
        {
            return 1;
        }
        if (func_00247dd0(2) & 0xFFFF)
        {
            return 2;
        }
        break;
    case 1:
        if (func_00247dd0(3) & 0xFFFF)
        {
            return 3;
        }
        if (func_00247dd0(4) & 0xFFFF)
        {
            return 4;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* measured: same slot-search floor as func_001075d0: retail's found-exit is
   bne->advance; b found, jumping to a shared NULL-retest tail; mwcc b210
   merges the goto spelling into a single beq->found (nd 24) and the
   return-then spelling inlines the found lw/and block into the loop instead
   of the shared retest tail (nd 25). Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_00107A00
s32 func_00107a00(s32 arg0, s32 arg1) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    return *(s32 *)r & arg1;
}

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 22.
   Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_00107AC0
u16 func_00107ac0(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    return *(u16 *)(r + 6);
}

// FUN_00107B70
s32 func_00107b70(void)
{
    s32 r = func_001070e0();
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = *(s32 *)r & 4;
    }
    if (r != 0)
    {
        return 1;
    }
    return 0;
}

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 22.
   Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_00107BD0
void func_00107bd0(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        *(s32 *)r |= 4;
    }
}

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 31.
   Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_00107CE0
void func_00107ce0(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        *(s32 *)r |= 1;
        *(s32 *)r &= ~2;
        func_00106db0(arg0, 2);
    }
}

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 32.
   Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_00107DC0
void func_00107dc0(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        *(s32 *)r &= ~1;
        if (id <= 0) {
            func_0046d730(D_005E42C8, 0x1E);
        }
        func_00106390(id + 0x43F, 0);
    }
}

// FUN_00107C80
s32 func_00107c80(void)
{
    s32 r = func_001070e0();
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = *(s32 *)r & 1;
    }
    if (r != 0)
    {
        return 1;
    }
    return 0;
}

// FUN_00107EA0
s32 func_00107ea0(void)
{
    s32 r = func_001070e0();
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = *(s32 *)r & 2;
    }
    if (r != 0)
    {
        return 1;
    }
    return 0;
}

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 31.
   Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_00107F00
void func_00107f00(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        *(s32 *)r |= 2;
        *(s32 *)r &= ~1;
        func_00106db0(arg0, 3);
    }
}

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 32.
   Branch-shape floor. */
/* Community-slot scan family; see the note above func_001076e0. nd 38.
   Committed at nd 38. */
// FUN_00107FE0
void func_00107fe0(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        *(s32 *)r &= ~2;
        if (id <= 0) {
            func_0046d730(D_005E42C8, 0x1E);
        }
        func_00106390(id + 0x45F, 0);
    }
}

/* measured: retail booleanizes the variable-mask bit check (lw; and; sltu
   $v0,$zero,$v0; beqz) and mwcc b210 folds `!= 0`, `(u32)x > 0`, boolean-local,
   u32-typed and `0 < x` spellings into a direct and;beqz (2 missing sltu words
   shift the whole tail; nd 64). Everything else matched on the first draft.
   Booleanize floor. */
// FUN_001080C0
/* measured: -O1 is load-bearing here - at -O2 b210 reorders the bit-array
   word index and bit index computations and loses four instructions. */
#pragma optimization_level 1
f32 func_001080c0(s32 arg0) {
    f32 v;
    s32 i;
    s32 b;
    s32 off;
    u32 *w;
    s32 *q;
    s32 hit;

    v = 1.0f;
    if (func_00247c20(func_00248760()) != 0) {
        v = v * *(f32 *)func_00246b80();
    }
    if (*(s32 *)((u8 *)func_00246b80() + 4) != 0) {
        b = *(s32 *)((u8 *)func_00246b80() + 4);
        w = &D_0079B1CC[b / 32];
        hit = (*w & (1 << (b % 32))) != 0;
        if (hit != 0) {
            v = v * *(f32 *)((u8 *)func_00246b80() + 8);
        }
    }
    if ((*(s32 *)((u8 *)func_002467b0(arg0) + 4) & 0x20) != 0) {
        i = 0;
        while (i < 3) {
            off = i * 8;
            if (*(s32 *)((u8 *)func_00246b80() + off + 0xC) != 0) {
                b = *(s32 *)((u8 *)func_00246b80() + off + 0xC);
                q = (s32 *)(D_007973A0 + (b / 32) * 4);
                hit = (*(s32 *)((u8 *)q + 0x3E2C) & (1 << (b % 32))) != 0;
                if (hit != 0) {
                    v = v * *(f32 *)((u8 *)func_00246b80() + off + 0x10);
                }
            }
            i++;
        }
    }
    return v;
}
/* measured: closes the -O1 bracket above at the file's -O2 baseline. */
#pragma optimization_level 2


/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 151
   (loop floor plus tail register-allocation noise). Branch-shape floor. */
// FUN_00108290
s32 func_00108290(s32 arg0, u32 arg1) {
    f32 v;
    u8 *r;
    u8 *p;
    s32 x;
    s32 id;
    s32 i;
    s32 b;
    u32 *w;
    s32 *q;
    s32 hit;
    u16 n;

    x = arg0;
    id = x & 0xFFFF;
    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    v = 1.0f;
    if (func_00247c20(func_00248760(x)) != 0) {
        v = v * *(f32 *)func_00246b80();
    }
    if (*(s32 *)((u8 *)func_00246b80() + 4) != 0) {
        b = *(s32 *)((u8 *)func_00246b80() + 4);
        w = &D_0079B1CC[b / 32];
        hit = (*w & (1 << (b % 32))) != 0;
        if (hit != 0) {
            v = v * *(f32 *)((u8 *)func_00246b80() + 8);
        }
    }
    if ((*(s32 *)((u8 *)func_002467b0(x) + 4) & 0x20) != 0) {
        x = 0;
        while (x < 3) {
            id = x * 8;
            if (*(s32 *)((u8 *)func_00246b80() + id + 0xC) != 0) {
                b = *(s32 *)((u8 *)func_00246b80() + id + 0xC);
                q = (s32 *)(D_007973A0 + (b / 32) * 4);
                hit = (*(s32 *)((u8 *)q + 0x3E2C) & (1 << (b % 32))) != 0;
                if (hit != 0) {
                    v = v * *(f32 *)((u8 *)func_00246b80() + id + 0x10);
                }
            }
            x++;
        }
    }
    n = (u16)((f32)arg1 * v);
    *(u16 *)(r + 8) = *(u16 *)(r + 8) + n;
    return n;
}


/* measured: retail groups the three float-constant loads (lui/lwc1 f2,f1,f0)
   before the three stack stores (swc1 0x70/74/78); mwcc b210's scheduler always
   interleaves them into load/store pairs (one $f0 reused) whether written as
   direct assignments, temp float locals, struct field stores, or struct
   initializers (init also emits a zero-fill loop). Arg saved registers also
   rotate ($s3=a1 vs retail $s3=a0). Tried 4+ spellings; nd 125. Scheduler
   load-grouping floor. */
// FUN_00108590
INCLUDE_ASM("asm/nonmatchings/cmmCommunity", func_00108590);

// FUN_001087E0
s32 func_001087e0(s32 arg0) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;
    s32 t;
    s32 rank;
    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    t = func_001070e0(arg0);
    if (t == 0) {
        t = 0;
    } else {
        t = *(u16 *)(t + 6);
    }
    if ((t & 0xFFFF) == 0xA) {
        return 0;
    }
    t = func_001070e0(arg0);
    if (t == 0) {
        t = 0;
    } else {
        t = *(u16 *)(t + 6);
    }
    id = t & 0xFFFF;
    rank = *(u16 *)(r + 8);
    if (rank >= *(u16 *)((u8 *)func_002467b0(arg0) + (id & 0xFFFF) * 2 + 0x10)) {
        return 1;
    }
    return 0;
}


/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 93
   (loop floor plus tail noise). Branch-shape floor. */
/* measured: reconstructed this wave. Slot-search head plus the community
   rank-up predicate. Three levers took it from nd 163 to nd 1: reusing the
   masked-id local for the func_001070e0 result (retail reuses $s0 for both),
   declaring the slot pointer before the id so the pair lands $s1/$s0 rather
   than $s0/$s1, and #pragma optimization_level 1, which stops b210 folding
   the third guarded load into the level register and restores retail's
   andi. The single residual word is retail's `daddiu $v0,$zero,1` for the
   predicate's true value where b210 emits `addiu`. Probed for that one word:
   ok as s32, u32, long, unsigned long, s64, u64, and both
   pointer types, with 1, 1U, 1LL,
   (s64)1, (u8 *)1, !0 and -(-1); inverted and pre-set branch polarity
   (nd 11 and nd 343); goto/switch/result-variable tail layouts (all
   identical); schedule on/off, no_branch_likely, opt_common_subs off,
   opt_propagation off, opt_rebuildconditionals, opt_loop_invariants at -O1
   return-merge, which b210 does not inline (object collapses to 324).
   New comparison-spelling probes changed `id >= 0x1F` to `id > 0x1E`
   and `i < 0x15` to `i <= 0x14`; each scored nd 3, so the nd 1 base
   remains the lowest body. The daddiu residual did not move; this is a
   settled floor after the comparison lever. Committed at nd 1. */
// FUN_00108950
/* measured: -O1 is load-bearing for this body - at -O2 mwcc coalesces the
   third func_001070e0 result straight into the level saved register and
   drops retail's andi, costing nd 162. */
#pragma optimization_level 1
s32 func_00108950(s32 arg0) {
    u8 *r;
    u8 *p;
    s32 id;
    s32 i;
    s32 t;
    s32 u;
    s32 lv;
    u8 ok;
    id = arg0 & 0xFFFF;
    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    id = func_001070e0(arg0);
    if (id == 0) {
        ok = 0;
    } else {
        t = func_001070e0(arg0);
        if (t == 0) {
            t = 0;
        } else {
            t = *(u16 *)(t + 6);
        }
        if ((t & 0xFFFF) == 0xA) {
            ok = 0;
        } else {
            u = func_001070e0(arg0);
            if (u == 0) {
                u = 0;
            } else {
                u = *(u16 *)(u + 6);
            }
            lv = u & 0xFFFF;
            id = *(u16 *)(id + 8);
            if (id >= *(u16 *)((u8 *)func_002467b0(arg0) + (lv & 0xFFFF) * 2 + 0x10)) {
                ok = (u8)1;
            } else {
                ok = 0;
            }
        }
    }
    if (!ok) {
        goto ret0;
    }
    t = func_001070e0(arg0);
    if (t == 0) {
        t = 0;
    } else {
        t = *(u16 *)(t + 6);
    }
    func_00108b60(arg0, (t & 0xFFFF) + 1);
    *(s16 *)(r + 8) = 0;
    t = func_001070e0(arg0);
    if (t != 0) {
        *(s32 *)t = *(s32 *)t & -5;
    }
    return 1;
ret0:
    return 0;
}
/* measured: closes the -O1 bracket above at the file's -O2 baseline. */
#pragma optimization_level 2

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 18
   (tail matched; s16 arg1 variant only differs by mwcc's post-jal
   re-extension, nd 47 with s32 arg1 from assert-block scheduling).
   Branch-shape floor. */
// FUN_00108B60
void func_00108b60(s32 arg0, s32 arg1) {
    s32 id = arg0 & 0xFFFF;
    u8 *r;
    u8 *p;
    s32 i;

    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return;
    }
    if (arg1 == 0) {
        func_0046d730(D_005E42C8, 0x254);
    }
    if (arg1 > 0xA) {
        func_0046d730(D_005E42C8, 0x255);
    }
    *(s16 *)(r + 6) = arg1;
    if (*(u16 *)(r + 6) == 0xA) {
        func_00106db0(arg0, 1);
        return;
    }
    func_00106db0(arg0, *(u16 *)(r + 6) + 3);
}

// FUN_00108CA0
s32 func_00108ca0(void)
{
    return 0;
}

// FUN_00108CF0
void func_00108cf0(s32 arg0)
{
    void *temp_2;

    func_00108d80();
    func_0044ea90(D_005E42C8, 0x271);
    temp_2 = D_008873F4[0](1, 0x20, 0x40000);
    *(s16 *)temp_2 = arg0;
    func_00451de0(D_005E4308, 0xF, 0, 0, (void *)func_00108ca0, (void *)func_00108cb0, temp_2);
}

// FUN_00108DC0
s32 func_00108dc0(void)
{
    s32 ret = func_00452380(D_005E4308);
    if (ret != 0)
    {
        return (s32)func_00452560(ret);
    }
    return 0;
}

// FUN_00108E10
s32 func_00108e10(void)
{
    s32 r = func_00452380(D_005E4308);
    if (r != 0)
    {
        r = (s32)func_00452560(r);
    }
    else
    {
        r = 0;
    }
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = *(u16 *)r;
    }
    return r;
}

// FUN_00108E70
s32 func_00108e70(void)
{
    s32 r = func_00452380(D_005E4308);
    if (r != 0)
    {
        r = (s32)func_00452560(r);
    }
    else
    {
        r = 0;
    }
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = *(u16 *)(r + 0x10);
    }
    return r;
}

// FUN_00108ED0
void func_00108ed0(u16 arg0)
{
    D_0079740C[0] = arg0;
}

// FUN_00108EE0
u16 func_00108ee0(void)
{
    return D_0079740C[0];
}

/* measured: same slot-search floor as func_00107a00/001075d0 (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 93
   (loop floor; the descending switch and call loop match otherwise).
   Branch-shape floor. */
// FUN_00108EF0
void func_00108ef0(s32 arg0) {
    s32 id;
    u8 *r;
    u8 *p;
    s32 i;
    s32 j;

    id = arg0 & 0xFFFF;
    if (id >= 0x1F) {
        func_0046d730(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (*(u16 *)(p + 4) == id) {
            r = p;
            goto ret;
        }
        p += 0x10;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return;
    }
    switch (id) {
    case 3:
        *(s16 *)(r + 4) = 4;
        break;
    case 5:
        *(s16 *)(r + 4) = 6;
        break;
    case 0xB:
        *(s16 *)(r + 4) = 0xC;
        break;
    case 0xE:
        *(s16 *)(r + 4) = 0xF;
        break;
    case 0x15:
        *(s16 *)(r + 4) = 0x16;
        break;
    case 0x19:
        *(s16 *)(r + 4) = 0x1A;
        break;
    case 0x1B:
        *(s16 *)(r + 4) = 0x1C;
        break;
    }
    if (id <= 0) {
        func_0046d730(D_005E42C8, 0x27);
    }
    j = 0;
    while (j < 0xD) {
        func_00106390(id + ((j << 5) + 0x3FF), 0);
        j++;
    }
    func_00106f40(*(u16 *)(r + 4));
}


// FUN_001090C0
void func_001090c0(s32 arg0)
{
    D_00797560[0] += arg0;
}

// FUN_001090E0
s32 func_001090e0(void)
{
    return D_00797560[0];
}

// FUN_00109100
s32 func_00109100(void)
{
    u8 *work;
    s16 id;
    s32 index;

    work = func_00246ba0();
    id = *(s16 *)work;
    index = (s16)func_00104f50(id, D_007973F4[id]);
    if (index <= 0) {
        func_0046d730(D_005E42C8, 0x2F6);
    }
    return *(s32 *)(work + index * 4);
}
