/* MATCH: obj 1852B/window 1856B/normalized_diff 0 (4B zero tail); fnalign 6 edit (10 reloc-only) -> 0 after value/end_date swap and count-mask reorder.
 * Target: src/promoted/code1_0011.c, func_00111bc0, 0x00111bc0, frame 0x5E0.
 * Candidate: source/Persona4-Decompilation/local/cand_111bc0_v4.c sha256 d79cca22956d65aea67b521711c7c680a8c10f61697e85a20accd5949f385181; owner sha256 81fd5fc6ec06cc4bc805385bc46461a7dc1cd1f4e7f30b42a9a9830439ea2d68.
 * Compiler: MWCCPS2 3.0.1 b210 -O2 -Iinclude, scoped #pragma opt_propagation off/on around function.
 * Commands: python3 source/Persona4-Decompilation/tools/probe_variants.py source/Persona4-Decompilation/src/promoted/code1_0011.c func_00111bc0 --candidate v4=source/Persona4-Decompilation/local/cand_111bc0_v4.c (0 differing words);
 *   python3 source/Persona4-Decompilation/tools/verify.py source/Persona4-Decompilation/src/promoted/code1_0011.c (45 MATCH/2 ASM, no MISMATCH);
 *   python3 source/Persona4-Decompilation/tools/fndiff.py source/Persona4-Decompilation/src/promoted/code1_0011.c func_00111bc0 (0 reloc-masked);
 *   python3 source/Persona4-Decompilation/tools/build.py --progress-report build/linked_report.json (image 3d1d3d2b9d6ccb60836db239ab49674223025a78 OK, SLUS 4eeec0360cf2715535d9f7e52eb69d786fb0158c OK).
 * TU eligibility: target MATCH; owner 45 MATCH/2 ASM (was 44/3); TU not fully C-linked (2 ASM remain) but link hashes OK (no regression).
 * Stack resolution (from asm, only fixed sp offsets 0x80,0x84,0x88,0x8C,0x90, rest computed):
 *   single s32 buf[344] at sp+0x80 (0x560 bytes, 0x80..0x5DF, 16-aligned windows, tight packing, no live overlap).
 *   windows: buf[0..3] floats via (Vec4*) copy from D_005E4700[4] (0x1200,0x1201,0x1202,0x0000; zero at [3] terminates 200-loops at j=3, before flags at [4..]);
 *   buf[4+count] flags (max 21: 0x4A0..0x4B3 +0x418) at 0x90+count*4, count s32 with (count+1)&0xFF (addiu+andi, not li) and (count&0xFF) indexing;
 *   buf[132+j] results at 0x290+j*4 (132*4=528, 0x80+528=0x290); buf[332+i] 7-flags at 0x5B0+i*4 (332*4=1328); ((s16*)buf)[680+i] 5-halfwords at 0x5D0+i*2 (680*2=1360).
 *   source reads via pointer-temp (p=&buf[j]; v=*p -> addiu+lw 0(p)) vs dest via direct index (sw 0x290(t)), both from same buf; flag loads via ((s16*)buf)[8+i*2] (lh 0x90(t)).
 *   m2c overlap resolved: four f32 locals + flag list at 0x90 + 200-reads from 0x80 are one buf (head + middle + full-window views), not three objects.
 * Semantic review: no UB beyond live (200-loops break at initialized zero [3], never read uninitialized; flags/results/7/5 all in-bounds for live counts 3/21/7/5);
 *   true callee widths used (00106600(s16)->s32 &0xFF, 00106620(s32,s32), 00104ea0(s16,s16)->s16, 001051a0(s16,s16,s16), 00105ed0()->u32, 00105fa0(u32), 001064f0(s32)->u32, 00106550(s32,u32), 00110460()->u32, 00110470(u32));
 *   declaration order saved,value,end_date,result,count,flag,i gives retail $s6..$s0 (reverse); i=0 then count&=0xFF matches retail scheduling; Vec4 struct copy gives batched lwc1 f3,f2,f1,f0 in order (not rotated/interleaved).
 * Rejected: separate f32 locals + s32 flag list + s32 200-array (overlap, 397-417 diff, GP loads, rotated/interleaved floats, $s4/$s5 swap, extra andi).
 */
#pragma opt_propagation off
void func_00111bc0(void)
{
    s32 saved;
    s32 value;
    s32 end_date;
    s32 result;
    s32 count;
    s8 flag;
    s32 i;
    s32 buf[344];
    s32 func_001064f0(s32);
    void func_00106550(s32, u32);
    s32 func_00106600(s16);
    s32 func_00106330(s32);
    void func_00106390(s32, s32);
    s16 func_00104ea0(s16, s16);
    u32 func_00105ed0(void);
    void func_00105fa0(u32);
    void func_00106620(s32, s32);
    void func_001051a0(s16, s16, s16);
    u32 func_00110460(void);
    void func_00110470(u32);
    void func_00310700(void);
    void func_00310850(void);
    extern float D_005E4700[4];
    typedef struct { float a; float b; float c; float d; } Vec4;
    saved = iGpffffb19c;
    count = 0;
    flag = 0;
    *(Vec4 *)buf = *(Vec4 *)D_005E4700;
    value = func_001064f0(0x7C);
    end_date = (s32)func_00110460() + 1;
    if ((func_00106600(0x4A0) & 0xFF) > 0) {
        buf[4] = 0x4A0;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A4) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A4;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A5) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A5;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A6) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A6;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A7) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A7;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A8) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A8;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A9) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A9;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AA) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AA;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AB) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AB;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AC) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AC;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AD) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AD;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AE) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AE;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AF) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AF;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B0) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B0;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x418) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x418;
        count = (count + 1) & 0xFF;
    }
    if (func_00106330(0x2F) != 0) {
        flag = 1;
    }
    if (func_00106330(0x1DD) != 0) {
        flag = 1;
    }
    i = 0;
    goto loop1_check;
loop1:
    buf[332 + i] = func_00106330(i + 0x39);
    i++;
loop1_check:
    if (i < 7) {
        goto loop1;
    }
    result = 0;
    goto loop2_check;
loop2:
    {
        s32 *p = &buf[result];
        s32 v = *p;
        if (v == 0) {
            goto loop2_done;
        }
        buf[132 + result] = func_00106330(v);
        result++;
    }
loop2_check:
    if (result < 200) {
        goto loop2;
    }
loop2_done:
    func_00310700();
    i = 0;
    goto loop3_check;
loop3:
    ((s16 *)buf)[680 + i] = func_00104ea0(1, (s16)i);
    i++;
loop3_check:
    if (i < 5) {
        goto loop3;
    }
    result = (s32)func_00105ed0();
    func_001113b0();
    i = 0;
    goto loop4_check;
loop4:
    func_00106390(i + 0x39, buf[332 + i]);
    i++;
loop4_check:
    if (i < 7) {
        goto loop4;
    }
    i = 0;
    goto loop5_check;
loop5:
    {
        s32 *p = &buf[i];
        s32 v = *p;
        if (v == 0) {
            goto loop5_done;
        }
        func_00106390(v, buf[132 + i]);
        i++;
    }
loop5_check:
    if (i < 200) {
        goto loop5;
    }
loop5_done:
    i = 0;
    count &= 0xFF;
    goto loop6_check;
loop6:
    func_00106620(((s16 *)buf)[8 + i * 2], 1);
    i++;
loop6_check:
    if (i < count) {
        goto loop6;
    }
    if (flag == 1) {
        func_00106390(0x1DD, 1);
    }
    func_00310850();
    func_00106390(0x1210, 1);
    func_00106550(0x7C, (u32)value);
    func_00110470((u32)end_date);
    i = 0;
    goto loop7_check;
loop7:
    func_001051a0(1, (s16)i, ((s16 *)buf)[680 + i]);
    i++;
loop7_check:
    if (i < 5) {
        goto loop7;
    }
    func_00105fa0((u32)result);
    func_00106390(0x800, 1);
    iGpffffb19c = saved;
}
#pragma opt_propagation on
