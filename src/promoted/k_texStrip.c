#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_texStrip.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_00428618(s32 arg0);
extern void func_0044ea90(const void *file, u32 line);
extern void func_00440b68(const char *fmt, ...);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void *func_003ef650(void *arg0, const char *arg1);
extern void func_003ef610(s32 arg0);
extern void func_003ef5b0(s32 arg0, s32 arg1);
extern s32 func_00451fc0(s32 arg0, const void *arg1, s32 arg2, s32 arg3,
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
extern s32 func_00427338(s32 fd, void *buf, s32 n);
extern s32 func_004275a8(s32 fd, void *buf, s32 n);
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



// measured: nd 115 after 4 attempts (best). Spill-slot rule as func_001916a0:
// func_003df3c0 writes four signed header words in spill.s. Switch `case 0x16 / case 0xF0F000E0 /
// default` compiles the dispatch comparison in the correct order (0xF0F000E0 first, then 0x16)
// and matches retail exactly. Residual nd 115 is dominated by register allocation: retail keeps
// sp60/sp64/sp68 (the 0x14-byte func_003e2910 buffer + sp64/sp68) on the STACK at 0x60/0x64/
// 0x68, but mwcc promotes sp64/sp68 to $s5/$s6 (sp68 folded with `sll $s6,2` / `addu $s0,$s6,$s6`)
// adding a 5th/6th saved reg, so the whole allocation shifts (retail wants var_16->$s0, arg1/
// temp_2->$s1, temp_18->$s2, temp_19->$s3, var_20->$s4). Making sp60/sp64/sp68 overlap via a
// 5-word array (nd 138) or a 3-field struct (nd 141) is worse. Core regs are otherwise right.
// QTEX lane: plain-C candidate object 668/window 672; baseline fndiff was nd 20
// (six differing instruction words plus one zero-padding tail word), with both
// func_003deff0 calls materializing move $a0 before the spill.s[0]/spill.s[1] loads.
// The targeted `(u32)` casts on spill.s[0] and spill.s[1] at both calls produce nd 0.
// s32 sp[2], the 16-byte spill union, and buffer[5] reproduce the 0xA0 frame and saved-register
// coloring. Shared-callee probe: retail func_003deff0 first-uses a0 as a forwarded
// pointer, saves a1/a2, and masks a3/t0, proving five args `(void *,s32,s32,s32,s32)`;
// existing calls already pass all five, so no prototype change was needed.
// FUN_00190680
s32 func_00190680(u8 *arg0, void *arg1) {
    s32 sp[2];
    union { s32 s[4]; u32 u[4]; } spill;
    s32 buffer[5];
    s32 var_20;
    s32 temp_19;
    s32 temp_18;
    u8 *temp_2;
    u8 *var_16;

    var_20 = 0;
    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_19 = func_003e2f60(3, 1, &sp[0]);
    temp_18 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_19 != 0) && (temp_18 != 0)) {
        goto loop_check;
loop_body:
        switch (spill.s[0]) {
        case 0x16:
            var_20 = func_003e6a90(temp_19);
            break;
        case 0xF0F000E0:
            func_003e2910(temp_19, &buffer[0], 0x14);
            func_003deff0(temp_18, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            func_003e2ab0(temp_18, &buffer[0], 0x14);
            func_003e2ce0(temp_19, buffer[2]);
            func_0044ea90(D_005F6168, 0xBB);
            temp_2 = D_008873F4[0](1, buffer[1] + buffer[2], 0x40000);
            func_003e2910(temp_19, temp_2 + buffer[2], buffer[1]);
            func_003e2ab0(temp_18, temp_2, buffer[1] + buffer[2]);
            jtbl_008873EC[0](temp_2);
            break;
        default:
            if (spill.s[1] != 0) {
                func_0044ea90(D_005F6168, 0xCA);
                var_16 = D_008873F4[0](1, spill.u[1], 0x40000);
                func_003e2910(temp_19, var_16, spill.s[1]);
            }
            func_003deff0(temp_18, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            if (spill.s[1] != 0) {
                func_003e2ab0(temp_18, var_16, spill.s[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_19, &spill.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_19, 0);
        func_003e2e40(temp_18, 0);
    }
    return var_20;
}

/* Look up the texture name, detach and insert it when absent, then report
   the lookup result. Pointer-typed lookup/print arguments and disabled CSE
   preserve retail's first-argument-before-name-address materialization.
   measured: object 196B/window 208B; exact instructions, 12B zero tail. */
#pragma opt_common_subs off
// FUN_00190920
s32 func_00190920(s32 arg0, s32 arg1) {
    if (func_003ef650((void *)arg1, (char *)arg0 + 0x10) == 0) {
        func_003ef610(arg0);
        func_003ef5b0(arg1, arg0);
        func_00440b68(D_005F6178, (char *)arg0 + 0x10);
        if (func_003ef650((void *)arg1, (char *)arg0 + 0x10) != 0) {
            func_00440b68(D_005F6190, (char *)arg0 + 0x10);
        }
    } else {
        func_00440b68(D_005F61B0, (char *)arg0 + 0x10);
    }
    return arg0;
}
/* measured: restore CSE after the exact 00190920 call sequence. */
#pragma opt_common_subs on


// measured: candidate frame, spill arrays, saved-register order, switch/goto layout, and
// shared-callee five-argument signature reached object 532/window 544 with normalized_diff 10.
// fndiff isolated the residual to func_003deff0 setup: retail loads spill.s[0] and spill.s[1]
// into $a1/$a2 before moving temp_19 into $a0, while b210 materializes the first argument
// first. Casting those two stack values to u32 reproduces the retail order and closes this
// function (normalized_diff 0).
// FUN_001909F0
void func_001909f0(u8 *arg0, void *arg1, u8 *arg2) {
    s32 sp[2];
    union { s32 s[4]; u32 u[4]; } spill;
    s32 temp_20;
    s32 temp_19;
    s32 temp_18;
    s32 temp_4;
    u32 var_17;
    u8 *var_16;

    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_20 = func_003e2f60(3, 1, &sp[0]);
    temp_19 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_20 != 0) && (temp_19 != 0)) {
        goto loop_check;
loop_body:
        switch (spill.s[0]) {
        case 0x16:
            temp_18 = func_003e6a90(temp_20);
            var_17 = 0;
            goto item_check;
item_body:
            temp_4 = *(s32 *)(arg2 + var_17 * 4 + 0x658);
            if (temp_4 != 0) {
                func_003ef260(temp_4, func_00190920, temp_18);
            }
            var_17++;
item_check:
            if (var_17 < *(u32 *)(arg2 + 0x254)) {
                goto item_body;
            }
            func_003e6870((void *)temp_18, (void *)temp_19);
            func_003ef1b0(temp_18);
            break;
        default:
            if (spill.s[1] != 0) {
                func_0044ea90(D_005F6168, 0x141);
                var_16 = D_008873F4[0](1, spill.u[1], 0x40000);
                func_003e2910(temp_20, var_16, spill.s[1]);
            }
            func_003deff0(temp_19, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            if (spill.s[1] != 0) {
                func_003e2ab0(temp_19, var_16, spill.s[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_20, &spill.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_20, 0);
        func_003e2e40(temp_19, 0);
    }
}

/* measured: GUARDED_SCORE 518 (retail 618 instrs / object 617 instrs; obj 2468B/window 2480B). 9-case switch on work[0] (jtbl_00746EC0, cases 0..8), 6x0x100 char buffers, s32 temps for func_00458430 integer compare (0/1), wrappers func_00427338/004275a8 for file I/O (nonmatchings asm mislabels as sceRead/sceWrite; code1.s confirms wrapper addrs). Levers tried, all recorded: opt_loop_invariants on 519->518 (kept, scoped); opt_unroll_loops off tie 519; schedule off tie 519; subscript hdr[i+7] vs ent[7] tie 518; byte-base ((s32*)((u8*)work+off))[i] vs work[i+k] tie 518; explicit off=i*4 tie 518; decl-order swaps (work-first, full reverse) tie 518; stat-size frame probes (64/64,48/48 tie 518; mismatched 64+48 hits 517 but rejected as unfaithful different-sized same-struct). Frame 0x6A0 vs retail 0x6F0 (80 short; stat struct size unknown, kept minimal matched [4]). Biggest remaining classes: saved-reg coloring (work in $s4 vs retail $s0, all branch displacements cascade) and stack-offset immediates from frame; only 2 insert (surplus) rows, rest replaces. m2c failed (jump table not provided, log in /var/tmp/cold190c10/m2c_log.txt); romwright gave complete 9-case structure, stack extents, and wrapper arities in /var/tmp/cold190c10/rw.c. */
// FUN_00190C10 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
s32 func_00190c10(u8 *arg0)
{
    char bufA0[0x100];
    char buf1A0[0x100];
    char buf2A0[0x100];
    char buf3A0[0x100];
    char buf4A0[0x100];
    char buf5A0[0x100];
    s32 outA[2];
    s32 outB[2];
    s32 stat1[4];
    s32 stat2[4];
    s32 *work;
    s32 i;
    s32 j;
    s32 k;
    s32 tmp;
    s32 *hdr;
    s8 *p;
    s8 *q;

    work = *(s32 **)(arg0 + 0x38);
    switch (work[0]) {
    case 0:
        work[1] = func_00428550(D_005F61D0);
        if (work[1] < 0) {
            return -1;
        }
        work[0]++;
        break;
    case 1:
        tmp = func_00428780(work[1], (void *)&work[2]);
        if (tmp <= 0) {
            work[0] = 8;
        } else {
            if (func_004426e8((void *)&work[0x12], &D_00763138) != 0 &&
                func_004426e8((void *)&work[0x12], &D_0076313C) != 0) {
                for (p = (s8 *)&work[0x12]; *p != '.' && *p != 0; p++) {
                }
                if (func_004426e8(p, &D_00763140) == 0) {
                    func_00442830((void *)&work[0x53], D_005F61F8);
                    func_00442428((void *)&work[0x53], (void *)&work[0x12]);
                    work[0x93] = (s32)func_00150970((void *)&work[0x53]);
                    func_00440b68(D_005F6210, &work[0x53]);
                    work[0] = 2;
                }
            }
        }
        break;
    case 2:
        if (func_00150c80((void *)work[0x93]) != 0) {
            func_00150ce0((void *)work[0x93]);
            work[0] = 3;
        }
        break;
    case 3:
        if (func_001510c0((void *)work[0x93]) != 0) {
            work[0x95] = 0;
            work[0x296] = 0;
            hdr = (s32 *)work[0x93];
            for (i = 0; i < hdr[6]; i++) {
                s32 *ent = (s32 *)((u8 *)hdr + i * 4);
                tmp = func_004581a0((void *)ent[7], D_005F6230);
                for (j = 0; j < tmp; j++) {
                    func_00458430(outA, (void *)ent[7], D_005F6230, j);
                    if (outA[0] == 0) {
                        func_00458430(outB, (void *)ent[7], D_005F6250, j);
                        work[work[0x95] + 0x96] = outB[0];
                        work[0x95]++;
                    } else if (outA[0] == 1) {
                        func_00458430(outB, (void *)ent[7], D_005F6250, j);
                        work[work[0x296] + 0x297] = outB[0];
                        work[0x296]++;
                    }
                }
            }
            work[0] = 4;
        }
        break;
    case 4:
        func_00442830(buf5A0, D_005F6270);
        for (p = (s8 *)&work[0x53]; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        func_00442428(buf5A0, p + 1);
        for (q = (s8 *)buf5A0; *q != '.'; q++) {
        }
        func_00442830(q, &D_00763148);
        D_00764498 = func_00426cf0(buf5A0, 0x603, 0x1FF);
        if (D_00764498 >= 0) {
            work[0x399] = 0;
            work[0x39A] = 0;
            hdr = (s32 *)work[0x93];
            func_00442088(buf4A0, D_005F62A0, ((s16 *)hdr)[2], ((s16 *)hdr)[3]);
            tmp = func_00442948(buf4A0);
            func_004275a8(D_00764498, buf4A0, tmp);
            for (i = 0; i < work[0x95]; i++) {
                if (work[i + 0x96] != 0) {
                    func_00442088(buf4A0, D_005F62B0, ((s16 *)hdr)[2]);
                    tmp = func_00442948(buf4A0);
                    func_004275a8(D_00764498, buf4A0, tmp);
                }
            }
            for (i = 0; i < work[0x296]; i++) {
                func_00442088(buf4A0, D_005F62C0, ((s16 *)hdr)[2], work[i + 0x297]);
                tmp = func_00442948(buf4A0);
                func_004275a8(D_00764498, buf4A0, tmp);
                func_00442088(buf5A0, D_005F62D0, ((s16 *)hdr)[2], work[i + 0x297]);
                func_004288d8(buf5A0, stat1);
                func_00442088(buf3A0, D_005F6310, ((s16 *)hdr)[2], work[i + 0x297]);
                func_004288d8(buf5A0, stat2);
                func_0044ea90(D_005F6168, 0x166);
                tmp = (s32)D_008873F4[0](1, stat2[2], 0x40000);
                if (tmp != 0) {
                    k = func_00426cf0(buf5A0, 1, 0x1FF);
                    if (k >= 0) {
                        func_00427338(k, (void *)tmp, stat2[2]);
                        func_00426f80(k);
                        func_00428f08(&D_00763130, 0);
                    }
                    k = func_00426cf0(buf3A0, 0x603, 0x1FF);
                    if (k >= 0) {
                        func_004275a8(k, (void *)tmp, stat2[2]);
                        func_00426f80(k);
                        func_00428f08(&D_00763130, 0);
                    }
                    jtbl_008873EC[0]((void *)tmp);
                }
            }
        }
        work[0x397] = 0;
        work[0] = 5;
        break;
    case 5:
        if (work[0x397] < work[0x95]) {
            if (work[work[0x397] + 0x96] == 0) {
                work[0x397]++;
            } else {
                func_00442088(buf2A0, D_005F6350, ((s16 *)((s32 *)work[0x93]))[2]);
                func_00440b68(&D_00763150, D_005F6168, 0x263);
                p = (s8 *)func_00454a60(buf2A0, 0);
                work[0x398] = (s32)p;
                func_00456150(p);
                work[0] = 6;
            }
        } else {
            func_00151f80((void *)work[0x93]);
            hdr = (s32 *)work[0x93];
            hdr = (s32 *)hdr[0x291];
            func_00463250((void *)hdr[0x4A]);
            hdr = (s32 *)work[0x93];
            jtbl_008873EC[0]((void *)hdr[0x291]);
            hdr = (s32 *)work[0x93];
            hdr[0x291] = 0;
            work[0x93] = 0;
            work[0] = 7;
        }
        break;
    case 6:
        hdr = (s32 *)work[0x93];
        func_00442088(buf1A0, D_005F6370, ((s16 *)hdr)[2], work[work[0x397] + 0x96]);
        tmp = func_00190680((u8 *)work[0x398], buf1A0);
        work[work[0x397] + 0x196] = tmp;
        func_00454bd0((void *)work[0x398]);
        work[0x398] = 0;
        work[0x397]++;
        work[0] = 5;
        break;
    case 7:
        func_00440b68(&D_00763150, D_005F6168, 0x2A0);
        p = (s8 *)func_00454a60((void *)&work[0x53], 0);
        work[0x94] = (s32)p;
        func_00456150(p);
        func_00442830(bufA0, D_005F63B0);
        for (p = (s8 *)&work[0x53]; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        func_00442428(bufA0, p + 1);
        func_001909f0((u8 *)work[0x94], bufA0, (u8 *)work);
        func_00454bd0((void *)work[0x94]);
        func_00442830(bufA0, D_005F63B0);
        for (p = (s8 *)&work[0x53]; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        func_00442428(bufA0, p + 1);
        func_004288d8(bufA0, stat1);
        work[0x39A] += stat1[2];
        for (i = 0; i < work[0x95]; i++) {
            if (work[i + 0x196] != 0) {
                func_003ef1b0(work[i + 0x196]);
                work[i + 0x196] = 0;
            }
        }
        func_00426f80(D_00764498);
        work[0] = 1;
        break;
    case 8:
        return -1;
    }
    return 0;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/k_texStrip", func_00190c10);
#endif

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

// measured: MATCH (object 420/window 432). The four func_003df3c0 spill slots
// use a 16-byte union: producer &spill.s[0], signed reads spill.s[1..3],
// and unsigned allocation length spill.u[1]. The stack slots at 0x50-0x5C
// and retail saved-register allocation are unchanged.
// The `(u32)` casts on spill.s[0] and spill.s[1] in func_003deff0 reproduce retail's
// argument-materialization order (loads before the first-argument move).
// FUN_001916A0
s32 func_001916a0(u8 *arg0, void *arg1)
{
    s32 sp[2];
    union { s32 s[4]; u32 u[4]; } spill;
    s32 var_19;
    s32 temp_18;
    s32 temp_17;
    u8 *var_16;

    var_19 = 0;
    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_18 = func_003e2f60(3, 1, &sp[0]);
    temp_17 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_18 != 0) && (temp_17 != 0)) {
        goto loop_check;
loop_body:
        switch (spill.s[0]) {
        case 0x16:
            var_19 = func_003e6a90(temp_18);
            break;
        default:
            if (spill.s[1] != 0) {
                func_0044ea90(D_005F6168, 0x330);
                var_16 = D_008873F4[0](1, spill.u[1], 0x40000);
                func_003e2910(temp_18, var_16, spill.s[1]);
            }
            func_003deff0(temp_17, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            if (spill.s[1] != 0) {
                func_003e2ab0(temp_17, var_16, spill.s[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_18, &spill.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_18, 0);
        func_003e2e40(temp_17, 0);
    }
    return var_19;
}

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
