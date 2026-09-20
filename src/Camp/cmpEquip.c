#include "include_asm.h"
/* Persona 4 USA decompilation - cmpEquip.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

void func_001437b0(void *arg0, s32 arg1, s32 arg2);
void func_001344d0(u8 *arg0);
void func_00131a00(u8 *arg0);
s16 func_00106cd0(s16 arg0, s16 arg1);
s32 func_00106600(s16 id);
s32 func_00106c30(s16 arg0, s16 arg1);
s32 func_00106c80(s16 arg0);
s16 func_00353ce0(void *arg0);
void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
void *func_0046a770(void *arg0);
s32 func_0046d200(void *arg0, s8 arg1);
void func_0046d730(void *arg0, s32 arg1);
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern s8 D_005E76E0[];
extern u8 D_005E7BA0[];
extern u8 D_005E7720[];
extern u8 D_005E8020[];
extern u8 D_005E84A0[];
extern u8 D_005E8920[];
extern u8 D_005E8DA0[];
extern u8 D_005E9220[];
extern u8 D_005E96A0[];
extern u8 D_005E9B20[];
extern u8 D_005E9FA0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E4[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F4[];
/* measured: both initializers hoist the conversion constants and table bases. */
#pragma opt_loop_invariants on
/* measured: initializer conversion and table setup match the retail window. */
// FUN_001312B0
void func_001312b0(u8 *arg0)
{
    s16 inner_i;
    s16 value;
    s32 offset;
    void *asset0;
    void *asset1;
    void *asset2;
    u8 *base;
    s32 *slot;
    s16 final_i;
    s16 clear_i;
    s16 second_i;
    s16 table_i;
    s16 outer_i;
    s16 inner_value;
    f32 float_value;
    s8 byte;

    func_0043f9c8(arg0, 0, 0x1598);
    base = arg0;
    *(s32 *)(base + 4) = 0;
    *(s32 *)(base + 8) = 0;
    *(u8 *)base = 0xFF;
    *(s32 *)(base + 0x18) = -1;
    *(s32 *)(base + 0x14) = 0;

    for (clear_i = 0; clear_i < 4; clear_i++) {
        *(s16 *)(base + clear_i * 2 + 0x28) = 0;
    }
    for (table_i = 0; table_i < 0x29; table_i++) {
        offset = table_i * 0x1C;
        *(f32 *)(base + table_i * 0x30 + 0xC90) = *(f32 *)(D_005E7BA0 + offset);
        *(f32 *)(base + table_i * 0x30 + 0xC94) = *(f32 *)(D_005E7BA0 + offset + 4);
        *(u8 *)(base + table_i * 0x30 + 0xC9A) = *(u8 *)(D_005E7BA0 + offset + 0x10);
        float_value = *(f32 *)(D_005E7BA0 + offset + 8);
        *(u16 *)(base + table_i * 0x30 + 0xCA0) = (u16)float_value;
        float_value = *(f32 *)(D_005E7BA0 + offset + 0xC);
        *(u16 *)(base + table_i * 0x30 + 0xCA6) = (u16)float_value;
    }
    for (second_i = 0; second_i < 3; second_i++) {
        *(s32 *)(base + second_i * 0x30 + 0x1440) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1430) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x143C) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1434) = 0;
        *(u8 *)(base + second_i * 0x30 + 0x1449) = 0;
        *(u8 *)(base + second_i * 0x30 + 0x1448) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1458) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x145C) = 3;
    }
    value = func_00353ce0(base + 0x38);
    *(s16 *)(base + 0x48) = value;
    for (outer_i = 0; outer_i < *(s16 *)(base + 0x48); outer_i++) {
        value = *(s16 *)(base + outer_i * 2 + 0x38);
        inner_i = 0;
        slot = (s32 *)(base + outer_i * 6);
        while (inner_i < 3) {
            inner_value = func_00106cd0(value, inner_i);
            ((s16 *)slot)[inner_i + 0x624] = inner_value;
            inner_i++;
        }
    }
    func_00134560(base, 0);
    asset0 = func_0046a770(D_005E5830);
    if (asset0 == 0) {
        func_0046d730(D_005E9FA0, 0x26A);
    }
    asset1 = func_0046a770(D_005E5850);
    if (asset1 == 0) {
        func_0046d730(D_005E9FA0, 0x26C);
    }
    *(s32 *)(base + 0x1590) = (s32)(asset2 = func_0046a770(D_005E57F0));
    if (asset2 == 0) {
        func_0046d730(D_005E9FA0, 0x26E);
    }
    for (final_i = 0; final_i < 0x34; final_i++) {
        if (final_i < 0x29) {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset0, byte);
        } else if (final_i < 0x33) {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset1, byte);
        } else {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset2, byte);
        }
        if (*slot == 0) {
            func_0046d730(D_005E9FA0, 0x27B);
        }
    }
}

// FUN_00131730
void func_00131730(s16 *arg0) {
    s16 i;
    s16 count;
    s16 id;
    s32 type;
    s64 call_type;
    s32 found;
    s32 filter;
    s16 value;
    s16 *entry;

    id = arg0[arg0[20] + 28];
    type = arg0[21];
    call_type = type;
    for (i = 0, count = 0; i < 0x2FF; i++) {
        found = i == func_00106cd0(id, call_type);
        if (!found) {
            filter = (u8)func_00106600((s16)i) != 0;
            if (filter) {
                filter = func_00106c30(i, id) != 0;
            }
            if (filter) {
                filter = (s32)type == func_00106c80(i);
            }
            if (!filter) {
                goto skip;
            }
        }
        value = found + (u8)func_00106600((s16)i);
        if (value > 99) {
            value = 99;
        }
        entry = &arg0[2 * count];
        entry[37] = i;
        entry[38] = value;
        count++;
    skip:
        ;
    }
    arg0[1571] = count;
    if (count > 0x2FF) {
        func_0046d730(D_005E9FA0, 0x299);
    }
}
// FUN_001318C0
s32 func_001318c0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00131910
s32 func_00131910(u8 *arg0) {
    s32 i;
    s32 rv;
    u8 *p;

    rv = 1;
    if (*(s16 *)(arg0 + 0x20) < 0x64) {
        *(s16 *)(arg0 + 0x20) = *(s16 *)(arg0 + 0x20) + 1;
    }
    for (i = 0; i < 0x29; i++) {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0xC80, *(s16 *)(arg0 + 0x20), 0);
        if (*(u8 *)(p + 0xC9A) != 0) {
            rv = 0;
        }
    }
    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) + 1;
    if (*(s16 *)(arg0 + 0x22) >= 0x168) {
        *(s16 *)(arg0 + 0x22) = 0;
    }
    func_001344d0(arg0);
    func_00131a00(arg0);
    return rv;
}
/* Cold 00131a00 (2732 instrs, frame -0x110 s17-s23/s30): no probe_archive */
/* entry; m2c (u8*, 1046 lines, switches case 0/1/2 irregular, structs */
/* ->unkXX/saved_reg_s3, no fors) vs romwright (u8*, 686 lines, while + */
/* for<3/for<5 counted fors correct, s16 counters already narrow, u8* + */
/* fixed offsets table-walk where they agree). m2c structs are guessed */
/* (u8*+fixed offsets is retail's shape); rw needs ?-at-line-start (keep */
/* ternary ? :), sbyte->s8, FUN_005e9fa0->D_005E9FA0, FUN_00131a00/func_ */
/* header to void (u8*). Stripped rw skeleton: retail 2732/object 4184 */
/* (+1452,+53%) edits ~1100+ gate outside (needs 2650-2814). Surplus is */
/* replaces where object longer (e.g. [195:202] retail 7 vs object 50, +43 */
/* for (u16)float clamp; s32 vs s16 already s16 per idiom, no 207 here). */
/* Front-load s16 counters, counted fors, if-chains (no jtbl/jr except */
/* return; slti 5/3 bounds are if-chains, not sltiu+j.tbl). Not banked. */
/* measured: candidate object 2567 instrs/retail 2732 instrs (10268B/10928B window 10928B, 165 short 6.0%), probe reloc-masked 2472 words (guard below, NON_MATCHING so production stays ASM; fnalign retail 2729/object 2567). Frame 0x100 vs retail 0x110 (extra f26/f27 saves from 8 live floats); inlined (f32)int for 0x212/0x226/0x1D1/0x195/0x25F/0x171/0x25E + float for rest (was double jal chains, six sites +1407 fixed); explicit (u16)/(u8) guards kept (adds vs single, 3x+43 kept to stay near gate); CONCAT44+fptodp kept for 11 Vec2f ld sites (adds vs ld, 11x~12). Call counts match retail 8x0034f320/20x0034f2e0/4x00274ed0/4x00112300/4x001125d0; block order 0x1000/0x400/0x800/0x80/0x100/0x200/0x04/0x10/0x08/0x02/0x2000/0x01/0x40; s16 counters front-loaded, counted fors for<3/for<5, if-chains (no jtbl). Largest TRUE hole 76 at 0x131C6C (lhu clamp, <100); 1916 hole is difflib misalignment from repeated lbu/mul/c.le blocks (call counts prove no missing functionality). Short by 83 vs 2650 min at 0x33D7C 9-instr site (object 9-15 vs retail 9, now matching, cumulative small diffs); no padding. */
/* measured(2026-09-19): sb->sh at 0x131B44 (u16 0x1c/0x1e): fnalign 4435->4431 (-4), guarded 2472->2466 (-6), tail structure 81->79, object 2567->2565 (-2). Missing retail 0x00132F5C second 0x20 (lw/andi/beqz + sh 0xF6, 15 instrs) absent in object (1 vs 2 andi 0x20); broad opt_common_subs off restores it but moves to 3231 edits/2838 instrs/frame 0xC0, not installed. */
/* measured(2026-09-20): whole-fn opt_dead_assignments off (00131a00 only): fnalign 4431->1833 (-2598), guarded 2466->2456 (-10), object 2565->2561 (-4), retail 2729 unchanged; second andi 0x20 restored (1->2) but sh 0xF6 still 0, frame still 0x100 vs 0x110; mid-fn scoped pragma had no effect. */
/* gate: func_00131a00 is OUTSIDE the +-3% band at 2561 against retail 2729 (-6.2%, band
   2647-2811), 168 instructions short, so its **1833** edits are not comparable to an
   in-band number (handoff 7y).  Recorded anyway because the drop from 4431 is real and
   the cause is worth carrying: retail has a SECOND `0x20` flag test at 0x00132F5C that the
   body simply did not have - the object had one `andi 0x20` where retail has two.  Writing
   that missing test back took 4431 -> 1833, a 59% reduction from ONE absent region.
   This is the clearest evidence in the tree for the rule that a short object is missing
   code rather than mistuned: a full prior session of spelling work on this same function
   found -4 edits.  The remaining shortfall is float spills from the frame gap, 0x100
   against retail's 0x110 with $f26/$f27 spare. */
// FUN_00131A00 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_dead_assignments off
void func_00131a00(u8 *arg0)

{
    extern void func_0034f1e0(void);
    extern void func_0034c270(u64 arg0, s32 arg1, s32 arg2, f32 arg3);
    extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u32 arg4);
    extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u32 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
    extern void func_00112300(u64 arg0, f32 fparg0, u8 arg1, u8 *arg2);
    extern void func_001125d0(u8 *arg0);
    extern s32 func_00106880(s16 arg0);
    extern s16 func_00106cd0(s16 arg0, s16 arg1);
    extern s32 func_0010d6d0(s16 arg0);
    extern s64 func_00134da0(s32 arg0);
    extern void func_00134e50(u8 *arg0, s64 arg1, s64 arg2, s8 arg3);
    extern void func_00134f40(u8 *arg0, s64 arg1, s64 arg2, s8 arg3);
    extern void func_00135130(u8 *arg0, s64 arg1, s8 arg2, u8 *arg3);
    extern void func_00135520(u8 *arg0, s64 arg1, u8 arg2, s32 arg3);
    extern s32 func_00274ed0(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
    extern void func_0034f9d0(u64 arg0, f32 fparg0, u32 arg1, s32 arg2, s32 arg3);
    extern void func_0046d730(void *arg0, s32 arg1);
    typedef struct { f32 x, y; } Vec2f;
/* irregular: 41 native warning(s); review required */
  s16 temp_v2;
  s16 unaff_s3_lo;
  s16 temp_v6;
  s16 temp_v8;
  s16 sStack_40;
  s16 sStack_30;
  s16 sStack_2a;
  s8 temp_v7;
  u8 temp_v0;
  u8 temp_v11;
  u8 *pbVar7;
  u8 *pbVar8;
  u8 *pbVar9;
  u8 *pbVar11;
  u16 temp_v1;
  u16 temp_v12;
  u16 temp_v13;
  u16 uStack_2e;
  u16 uStack_1c;
  u16 uStack_1a;
  u16 uStack_18;
  u32 temp_v3;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  s32 temp_v4;
  char *pcVar5;
  u64 temp_v5;
  f32 temp_v9;
  f32 temp_v10;
  f32 temp_v14;
  f32 temp_v15;
  f32 temp_v16;
  f32 temp_v17;
  f32 temp_v18;
  f32 fStack_8;
  f32 fStack_4;
  
  pbVar8 = (u8 *)arg0;
  temp_v6 = *(s16 *)(pbVar8 + *(s16 *)(pbVar8 + 0x28) * 2 + 0x38);
  func_0034f1e0();
  temp_v15 = *(f32 *)(pbVar8 + 4);
  temp_v16 = *(f32 *)(pbVar8 + 8);
  temp_v17 = (f32)*pbVar8 / 255.0f;
  if (*(s32 *)(pbVar8 + 0x10) != 0) {
    temp_v9 = temp_v17 * 255.0f;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    fStack_8 = temp_v15;
    fStack_4 = temp_v16;
    func_0034c270(*(u64 *)(pbVar8 + 4),(s32)temp_v9 & 0xff,*(s32 *)(pbVar8 + 0x10),0.0f);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x1000) != 0) {
    pbVar7 = *(u8 **)(pbVar8 + 0x157c);
    *(u16 *)(pbVar7 + 0x1c) = 0x3d;
    *(u16 *)(pbVar7 + 0x1e) = 0x3f;
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1260) + (f32)0x212;
    fStack_4 = (temp_v16 + *(f32 *)(pbVar8 + 0x1264)) - 3.0f;
    temp_v9 = (f32)pbVar8[0x126a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    temp_v14 = (f32)*(u16 *)(pbVar8 + 0x1270);
    temp_v10 = (f32)*(u16 *)(pbVar8 + 0x1276);
    if (temp_v14 < 2.1474836e9f) {
      temp_v12 = (u16)(s32)temp_v14;
    }
    else {
      temp_v12 = (u16)(s32)(temp_v14 - 2.1474836e9f);
    }
    if (temp_v10 < 2.1474836e9f) {
      temp_v13 = (u16)(s32)temp_v10;
    }
    else {
      temp_v13 = (u16)(s32)(temp_v10 - 2.1474836e9f);
    }
    func_0034f320(pbVar7,fStack_8,fStack_4,0.0f,0xff,0xff,0x81,(s32)temp_v9 & 0xff,temp_v12,temp_v13,0x3d,
                  (f32)(s32)*(s16 *)(pbVar8 + 0x22),0x3f);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1290) + (f32)0x226;
    fStack_4 = (temp_v16 + *(f32 *)(pbVar8 + 0x1294)) - 22.0f;
    temp_v9 = (f32)pbVar8[0x129a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    temp_v14 = (f32)*(u16 *)(pbVar8 + 0x12a0);
    temp_v10 = (f32)*(u16 *)(pbVar8 + 0x12a6);
    if (temp_v14 < 2.1474836e9f) {
      temp_v12 = (u16)(s32)temp_v14;
    }
    else {
      temp_v12 = (u16)(s32)(temp_v14 - 2.1474836e9f);
    }
    if (temp_v10 < 2.1474836e9f) {
      temp_v13 = (u16)(s32)temp_v10;
    }
    else {
      temp_v13 = (u16)(s32)(temp_v10 - 2.1474836e9f);
    }
    func_0034f320(pbVar7,fStack_8,fStack_4,0.0f,0xfb,0xa2,0,(s32)temp_v9 & 0xff,temp_v12,temp_v13,0x3d,
                  (f32)(s32)*(s16 *)(pbVar8 + 0x22),0x3f);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x400) != 0) {
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0xc90) + 20.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0xc94) + 358.0f;
    temp_v9 = (f32)pbVar8[0xc9a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    func_0034f2e0(*(void **)(pbVar8 + 0x158c),fStack_8,fStack_4,0xff,0xff,0xff,(s32)temp_v9 & 0xff);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x800) != 0) {
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0xcc0) + (f32)0x1D1;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0xcc4) + 20.0f;
    temp_v9 = (f32)pbVar8[0xcca] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    func_0034f2e0(*(void **)(pbVar8 + 0x158c),fStack_8,fStack_4,0xff,0xff,0xff,(s32)temp_v9 & 0xff);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x80) != 0) {
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x12c0) + 20.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x12c4) + (f32)0x195;
    temp_v9 = (f32)pbVar8[0x12ca] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    func_0034f2e0(*(void **)(pbVar8 + 0x1564),fStack_8,fStack_4,0xff,0xff,0xff,(s32)temp_v9 & 0xff);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x100) != 0) {
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x12f0) + 146.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x12f4) + (f32)0x195;
    temp_v9 = (f32)pbVar8[0x12fa] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    func_0034f2e0(*(void **)(pbVar8 + 0x1568),fStack_8,fStack_4,0xff,0xff,0xff,(s32)temp_v9 & 0xff);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x200) != 0) {
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1320) + 20.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1324) + (f32)0x195;
    temp_v9 = (f32)pbVar8[0x132a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    func_0034f2e0(*(void **)(pbVar8 + 0x1564),fStack_8,fStack_4,0xff,0xff,0xff,(s32)temp_v9 & 0xff);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 4) != 0) {
    temp_v4 = 0;
    while (temp_v8 = (s16)temp_v4, temp_v8 < *(s16 *)(pbVar8 + 0x48)) {
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0x1080) + 35.0f;
      temp_v10 = (f32)temp_v4 * 33.0f + temp_v16 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0x1084) + 0.0f +
               20.0f;
      temp_v18 = (f32)*(u16 *)(pbVar8 + temp_v8 * 0x30 + 0x1090);
      temp_v14 = (f32)*(u16 *)(pbVar8 + temp_v8 * 0x30 + 0x1096);
      temp_v9 = (f32)pbVar8[temp_v8 * 0x30 + 0x108a] * temp_v17;
      if (2.1474836e9f <= temp_v9) {
        temp_v9 = temp_v9 - 2.1474836e9f;
      }
      temp_v3 = (s32)temp_v9 & 0xff;
      if (*(s16 *)(pbVar8 + 0x28) == temp_v8) {
        pbVar7 = D_0064B2E8;
        temp_v7 = 8;
      }
      else {
        pbVar7 = D_0064B2E0;
        temp_v7 = 6;
      }
      if (temp_v18 < 2.1474836e9f) {
        temp_v12 = (u16)(s32)temp_v18;
      }
      else {
        temp_v12 = (u16)(s32)(temp_v18 - 2.1474836e9f);
      }
      if (temp_v14 < 2.1474836e9f) {
        temp_v13 = (u16)(s32)temp_v14;
      }
      else {
        temp_v13 = (u16)(s32)(temp_v14 - 2.1474836e9f);
      }
      fStack_4 = temp_v10;
      func_0034f320(*(u8 **)(pbVar8 + 0x14c0),fStack_8,temp_v10,0.0f,*pbVar7,pbVar7[1],pbVar7[2],
                    temp_v3,temp_v12,temp_v13,0,0.0f,0);
      if (temp_v18 < 2.1474836e9f) {
        temp_v12 = (u16)(s32)temp_v18;
      }
      else {
        temp_v12 = (u16)(s32)(temp_v18 - 2.1474836e9f);
      }
      if (temp_v14 < 2.1474836e9f) {
        temp_v13 = (u16)(s32)temp_v14;
      }
      else {
        temp_v13 = (u16)(s32)(temp_v14 - 2.1474836e9f);
      }
      func_0034f320(*(u8 **)(pbVar8 + 0x14c4),fStack_8 + 202.0f,temp_v10,0.0f,*pbVar7,pbVar7[1],
                    pbVar7[2],temp_v3,temp_v12,temp_v13,0,0.0f,0);
      pcVar5 = (char *)func_0010d6d0(*(s16 *)(pbVar8 + temp_v8 * 2 + 0x38));
      func_00274ed0(fStack_8 + 105.0f,temp_v10,0.0f,temp_v3 | 0xffffff00,temp_v7,1,pcVar5,8,0);
      temp_v4 = (s32)(s16)(temp_v8 + 1);
    }
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x10) != 0) {
    for (temp_v8 = 0; temp_v8 < 3; temp_v8 = temp_v8 + 1) {
      temp_v0 = 0;
      if ((*(u32 *)(pbVar8 + 0x1c) & 0x20) != 0) {
        fStack_8 = temp_v15 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0xf90) + 253.0f;
        fStack_4 = temp_v16 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0xf94) + 190.0f +
                   (f32)(temp_v8 * 0x3f);
        temp_v9 = (f32)pbVar8[temp_v8 * 0x30 + 0xf9a] * temp_v17;
        if (2.1474836e9f <= temp_v9) {
          temp_v9 = temp_v9 - 2.1474836e9f;
        }
        temp_v0 = *(s16 *)(pbVar8 + 0x2a) == temp_v8;
        func_00134e50(pbVar8,CONCAT44(fStack_4,fStack_8),(u64)temp_v0,(s32)temp_v9 & 0xff);
      }
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0xf00) + 253.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0xf04) + 190.0f +
                 (f32)(temp_v8 * 0x3f);
      temp_v9 = (f32)pbVar8[temp_v8 * 0x30 + 0xf0a] * temp_v17;
      if (2.1474836e9f <= temp_v9) {
        temp_v9 = temp_v9 - 2.1474836e9f;
      }
      temp_v14 = (f32)*(u16 *)(pbVar8 + temp_v8 * 0x30 + 0xf10);
      temp_v10 = (f32)*(u16 *)(pbVar8 + temp_v8 * 0x30 + 0xf16);
      if (temp_v8 == 2) {
        unaff_s3_lo = 0xf;
      }
      else if (temp_v8 == 1) {
        unaff_s3_lo = 0xe;
      }
      else if (temp_v8 == 0) {
        temp_v2 = func_00106cd0(temp_v6,0);
        temp_v3 = func_00106880(temp_v2);
        temp_v4 = func_00134da0(temp_v3);
        unaff_s3_lo = (s16)temp_v4;
      }
      if (temp_v0) {
        pbVar7 = D_0064B2EC;
        pbVar11 = D_0064B2E8;
      }
      else {
        pbVar7 = D_0064B2E4;
        pbVar11 = D_0064B2E0;
      }
      if (unaff_s3_lo < 0xe) {
        pbVar9 = *(u8 **)(pbVar8 + 0x14c8);
      }
      else {
        pbVar9 = *(u8 **)(pbVar8 + 0x14cc);
      }
      if (temp_v14 < 2.1474836e9f) {
        temp_v12 = (u16)(s32)temp_v14;
      }
      else {
        temp_v12 = (u16)(s32)(temp_v14 - 2.1474836e9f);
      }
      if (temp_v10 < 2.1474836e9f) {
        temp_v13 = (u16)(s32)temp_v10;
      }
      else {
        temp_v13 = (u16)(s32)(temp_v10 - 2.1474836e9f);
      }
      temp_v18 = fStack_4;
      func_0034f320(pbVar9,fStack_8,fStack_4,0.0f,*pbVar7,pbVar7[1],pbVar7[2],(s32)temp_v9 & 0xffU,
                    temp_v12,temp_v13,0,0.0f,0);
      if (temp_v14 < 2.1474836e9f) {
        temp_v12 = (u16)(s32)temp_v14;
      }
      else {
        temp_v12 = (u16)(s32)(temp_v14 - 2.1474836e9f);
      }
      if (temp_v10 < 2.1474836e9f) {
        temp_v13 = (u16)(s32)temp_v10;
      }
      else {
        temp_v13 = (u16)(s32)(temp_v10 - 2.1474836e9f);
      }
      func_0034f320(*(u8 **)(pbVar8 + unaff_s3_lo * 4 + 0x14c0),fStack_8 + 3.0f,temp_v18 + 2.0f,0.0f,
                    *pbVar11,pbVar11[1],pbVar11[2],(s32)temp_v9 & 0xffU,temp_v12,temp_v13,0,0.0f,0);
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0xe70) + 255.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + temp_v8 * 0x30 + 0xe74) + 193.0f +
                 (f32)(temp_v8 * 0x3f);
      temp_v9 = (f32)pbVar8[temp_v8 * 0x30 + 0xe7a] * temp_v17;
      if (2.1474836e9f <= temp_v9) {
        temp_v9 = temp_v9 - 2.1474836e9f;
      }
      if (temp_v0) {
        pbVar7 = D_0064B2EC;
      }
      else {
        pbVar7 = D_0064B2E4;
      }
      func_0034f2e0(*(void **)(pbVar8 + temp_v8 * 4 + 0x14d0),fStack_8 + 42.0f,fStack_4 + 1.0f,*pbVar7,
                    pbVar7[1],pbVar7[2],(s32)temp_v9 & 0xff);
      fStack_8 = fStack_8 + 42.0f;
      fStack_4 = fStack_4 + 24.0f;
      temp_v9 = (f32)pbVar8[temp_v8 * 0x30 + 0xe7a] * temp_v17;
      if (temp_v9 < 2.1474836e9f) {
        temp_v11 = (u8)(s32)temp_v9;
      }
      else {
        temp_v11 = (u8)(s32)(temp_v9 - 2.1474836e9f);
      }
      func_001125d0((u8 *)&sStack_30);
      if ((*(u32 *)(pbVar8 + 0x1c) & 0x20) == 0) {
        uStack_1a = 4;
      }
      else if (temp_v0) {
        uStack_1a = 3;
      }
      else {
        uStack_1a = 2;
      }
      sStack_30 = func_00106cd0(temp_v6,temp_v8);
      uStack_2e = 0xffff;
      uStack_28 = 0xffffffff;
      uStack_24 = 1;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 3;
      func_00112300(CONCAT44(fStack_4,fStack_8),0.0f,temp_v11,(u8 *)&sStack_30);
    }
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 8) != 0) {
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1200) + 35.0f;
    temp_v10 = temp_v16 + *(f32 *)(pbVar8 + 0x1204) + 20.0f;
    temp_v9 = (f32)pbVar8[0x120a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    temp_v18 = (f32)*(u16 *)(pbVar8 + 0x1210);
    temp_v14 = (f32)*(u16 *)(pbVar8 + 0x1216);
    if (temp_v18 < 2.1474836e9f) {
      temp_v12 = (u16)(s32)temp_v18;
    }
    else {
      temp_v12 = (u16)(s32)(temp_v18 - 2.1474836e9f);
    }
    if (temp_v14 < 2.1474836e9f) {
      temp_v13 = (u16)(s32)temp_v14;
    }
    else {
      temp_v13 = (u16)(s32)(temp_v14 - 2.1474836e9f);
    }
    fStack_4 = temp_v10;
    func_0034f320(*(u8 **)(pbVar8 + 0x14c0),fStack_8,temp_v10,0.0f,D_0064B2F4[0],D_0064B2F4[1],
                  D_0064B2F4[2],(s32)temp_v9 & 0xffU,temp_v12,temp_v13,0,0.0f,0);
    if (temp_v18 < 2.1474836e9f) {
      temp_v12 = (u16)(s32)temp_v18;
    }
    else {
      temp_v12 = (u16)(s32)(temp_v18 - 2.1474836e9f);
    }
    if (temp_v14 < 2.1474836e9f) {
      temp_v13 = (u16)(s32)temp_v14;
    }
    else {
      temp_v13 = (u16)(s32)(temp_v14 - 2.1474836e9f);
    }
    func_0034f320(*(u8 **)(pbVar8 + 0x14c4),fStack_8 + 202.0f,temp_v10,0.0f,D_0064B2F4[0],D_0064B2F4[1],
                  D_0064B2F4[2],(s32)temp_v9 & 0xffU,temp_v12,temp_v13,0,0.0f,0);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1230) + 35.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1234) + 20.0f;
    temp_v9 = (f32)pbVar8[0x123a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    pcVar5 = (char *)func_0010d6d0(*(s16 *)(pbVar8 + *(s16 *)(pbVar8 + 0x28) * 2 + 0x38));
    func_00274ed0(fStack_8 + 105.0f,fStack_4,0.0f,((s32)temp_v9 & 0xffU) - 0x100,7,1,pcVar5,8,0);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 2) != 0) {
    temp_v9 = (f32)pbVar8[0x105a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    temp_v3 = (s32)temp_v9 & 0xff;
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1050) + 18.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1054) + 51.0f;
    func_0034f2e0(*(void **)(pbVar8 + 0x1570),fStack_8,fStack_4,D_0064B2F4[0],D_0064B2F4[1],
                  D_0064B2F4[2],temp_v3);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1050) + 186.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1054) + 51.0f;
    func_0034f2e0(*(void **)(pbVar8 + 0x1574),fStack_8,fStack_4,D_0064B2F4[0],D_0064B2F4[1],
                  D_0064B2F4[2],temp_v3);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1050) + (f32)0x25F;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1054) + 90.0f;
    func_0034f2e0(*(void **)(pbVar8 + 0x1578),fStack_8,fStack_4,D_0064B2F4[0],D_0064B2F4[1],
                  D_0064B2F4[2],temp_v3);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1410) + 18.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1414) + 60.0f;
    temp_v9 = (f32)pbVar8[0x141a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    pcVar5 = (char *)func_0010d6d0(*(s16 *)(pbVar8 + 0xc7e));
    func_00274ed0(fStack_8 + 88.0f,fStack_4,0.0f,((s32)temp_v9 & 0xffU) | 0xffffff00,7,1,pcVar5,8,0);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13e0) + 18.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13e4) + 60.0f;
    temp_v9 = (f32)pbVar8[0x13ea] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    pcVar5 = (char *)func_0010d6d0(*(s16 *)(pbVar8 + *(s16 *)(pbVar8 + 0x28) * 2 + 0x38));
    func_00274ed0(fStack_8 + 88.0f,fStack_4,0.0f,((s32)temp_v9 & 0xffU) | 0xffffff00,7,1,pcVar5,8,0);
    temp_v9 = (f32)pbVar8[0x13ba] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    temp_v3 = (s32)temp_v9 & 0xff;
    temp_v8 = *(s16 *)(pbVar8 + 0x2a);
    if (temp_v8 == 2) {
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + 34.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 91.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x1534),fStack_8,fStack_4,(u8)D_0064B2E0[0],
                    D_0064B2E0[1],D_0064B2E0[2],temp_v3);
    }
    else if (temp_v8 == 1) {
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + 33.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 96.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x152c),fStack_8,fStack_4,(u8)D_0064B2E0[0],
                    D_0064B2E0[1],D_0064B2E0[2],temp_v3);
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + 71.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 103.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x1530),fStack_8,fStack_4,(u8)D_0064B2E0[0],
                    D_0064B2E0[1],D_0064B2E0[2],temp_v3);
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + (f32)0x171;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x1514),fStack_8,fStack_4,0xff,0xff,0xff,temp_v3);
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + 460.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x1518),fStack_8,fStack_4,0xff,0xff,0xff,temp_v3);
    }
    else if (temp_v8 == 0) {
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + 48.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 96.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x1528),fStack_8,fStack_4,(u8)D_0064B2E0[0],
                    D_0064B2E0[1],D_0064B2E0[2],temp_v3);
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + (f32)0x171;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x150c),fStack_8,fStack_4,0xff,0xff,0xff,temp_v3);
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x13b0) + 460.0f;
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x13b4) + 66.0f;
      func_0034f2e0(*(void **)(pbVar8 + 0x1510),fStack_8,fStack_4,0xff,0xff,0xff,temp_v3);
    }
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1020) + 122.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1024) + 94.0f;
    temp_v9 = (f32)pbVar8[0x102a] * temp_v17;
    if (temp_v9 < 2.1474836e9f) {
      temp_v11 = (u8)(s32)temp_v9;
    }
    else {
      temp_v11 = (u8)(s32)(temp_v9 - 2.1474836e9f);
    }
    func_001125d0((u8 *)&sStack_30);
    sStack_40 = func_00106cd0(temp_v6,*(s16 *)(pbVar8 + 0x2a));
    uStack_2e = 0xffff;
    uStack_28 = 0xffffffff;
    uStack_24 = 1;
    uStack_20 = 1;
    uStack_1c = 1;
    uStack_1a = 4;
    uStack_18 = 3;
    sStack_30 = sStack_40;
    func_00112300(CONCAT44(fStack_4,fStack_8),0.0f,temp_v11,(u8 *)&sStack_30);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1380) + 122.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1384) + 94.0f;
    temp_v9 = (f32)pbVar8[0x138a] * temp_v17;
    if (temp_v9 < 2.1474836e9f) {
      temp_v11 = (u8)(s32)temp_v9;
    }
    else {
      temp_v11 = (u8)(s32)(temp_v9 - 2.1474836e9f);
    }
    sStack_30 = *(s16 *)(pbVar8 + 0xc7a);
    func_00112300(CONCAT44(fStack_4,fStack_8),0.0f,temp_v11,(u8 *)&sStack_30);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 0x2000) != 0) {
    temp_v10 = *(f32 *)(pbVar8 + 0x1474) + temp_v16 + *(f32 *)(pbVar8 + 0xe14);
    temp_v9 = (f32)pbVar8[0xe1a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    temp_v3 = (s32)temp_v9 & 0xff;
    temp_v9 = *(f32 *)(pbVar8 + 0x1470) + temp_v15 + *(f32 *)(pbVar8 + 0xe10) + (f32)0x25E;
    fStack_4 = temp_v10 + 133.0f;
    fStack_8 = temp_v9;
    func_0034f2e0(*(void **)(pbVar8 + 0x151c),temp_v9,fStack_4,0xff,0xff,0xff,temp_v3);
    fStack_4 = temp_v10 + 298.0f;
    fStack_8 = temp_v9;
    func_0034f2e0(*(void **)(pbVar8 + 0x1520),temp_v9,fStack_4,0xff,0xff,0xff,temp_v3);
    fStack_4 = temp_v10 + 136.0f;
    if (0 < *(s16 *)(pbVar8 + 0xc46) - 5) {
      fStack_4 = fStack_4 +
                 (f32)(((*(s16 *)(pbVar8 + 0x2c) * 0x42 + (s32)*(s16 *)(pbVar8 + 0x2c)) * 2) /
                        (*(s16 *)(pbVar8 + 0xc46) - 5));
    }
    fStack_8 = temp_v9;
    func_0034f2e0(*(void **)(pbVar8 + 0x1524),temp_v9,fStack_4,D_0064B2E8[0],D_0064B2E8[1],D_0064B2E8[2]
                  ,temp_v3);
  }
  if ((*(u32 *)(pbVar8 + 0x1c) & 1) != 0) {
    if (*(s16 *)(pbVar8 + 0xc46) == 0) {
      func_0046d730(D_005E9FA0,0x507);
    }
    if (pbVar8[0x144a] != 0) {
      fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1440);
      fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1444);
      func_00134f40(pbVar8,CONCAT44(fStack_4,fStack_8),0,(u32)pbVar8[0x144a]);
    }
    for (temp_v6 = 0; temp_v6 < 5; temp_v6 = temp_v6 + 1) {
      if ((s32)((s32)temp_v6 + (s32)*(s16 *)(pbVar8 + 0x2c)) < (s32)*(s16 *)(pbVar8 + 0xc46)) {
        fStack_8 = temp_v15 + *(f32 *)(pbVar8 + temp_v6 * 0x30 + 0xd20) + 122.0f;
        fStack_4 = *(f32 *)(pbVar8 + temp_v6 * 0x30 + 0xd24) + temp_v16 + (f32)(temp_v6 * 0x22) +
                   137.0f;
        temp_v9 = (f32)pbVar8[temp_v6 * 0x30 + 0xd2a] * temp_v17;
        if (2.1474836e9f <= temp_v9) {
          temp_v9 = temp_v9 - 2.1474836e9f;
        }
        temp_v3 = (s32)temp_v9 & 0xff;
        temp_v4 = (s32)*(s16 *)(pbVar8 + 0x2c) + (s32)temp_v6;
        temp_v8 = *(s16 *)(pbVar8 + temp_v4 * 4 + 0x4a);
        temp_v1 = *(u16 *)(pbVar8 + temp_v4 * 4 + 0x4c);
        func_001125d0((u8 *)&sStack_30);
        if (*(s16 *)(pbVar8 + 0x2e) == temp_v6) {
          uStack_1a = 3;
          func_00134f40(pbVar8,CONCAT44(fStack_4,fStack_8),1,temp_v3);
        }
        else {
          uStack_1a = 5;
          func_00134f40(pbVar8,CONCAT44(fStack_4,fStack_8),0,temp_v3);
        }
        uStack_28 = 0xffffffff;
        uStack_24 = 1;
        uStack_20 = 1;
        uStack_1c = 1;
        sStack_2a = sStack_40;
        uStack_18 = 3;
        sStack_30 = temp_v8;
        uStack_2e = temp_v1;
        func_00112300(CONCAT44(fStack_4,fStack_8),0.0f,(u8)(s32)temp_v9,(u8 *)&sStack_30);
      }
    }
  }
  if (((*(u32 *)(pbVar8 + 0x1c) & 0x40) != 0) && (0 < *(s16 *)(pbVar8 + 0xc46))) {
    temp_v5 = 0;
    func_001125d0((u8 *)&sStack_30);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x14a0) + 124.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x14a4) + 147.0f;
    uStack_28 = 0xffffffff;
    uStack_1c = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    if (*(f32 *)(pbVar8 + 0x149c) < 0.0f) {
      temp_v5 = 1;
    }
    else if (0.0f < *(f32 *)(pbVar8 + 0x149c)) {
      temp_v5 = 2;
    }
    func_00135520(arg0,CONCAT44(fStack_4,fStack_8),pbVar8[0x14aa],temp_v5);
    fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0xe40) + 124.0f;
    fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0xe44) + 147.0f;
    sStack_30 = *(s16 *)(pbVar8 + ((s32)*(s16 *)(pbVar8 + 0x2c) + (s32)*(s16 *)(pbVar8 + 0x2e)
                                    ) * 4 + 0x4a);
    uStack_2e = *(u16 *)
                 (pbVar8 + ((s32)*(s16 *)(pbVar8 + 0x2c) + (s32)*(s16 *)(pbVar8 + 0x2e)) * 4 +
                           0x4c);
    uStack_28 = 0xffffffff;
    uStack_24 = 1;
    uStack_20 = 1;
    sStack_2a = sStack_40;
    uStack_1a = 3;
    uStack_1c = 1;
    uStack_18 = 3;
    temp_v9 = (f32)pbVar8[0xe4a] * temp_v17;
    if (2.1474836e9f <= temp_v9) {
      temp_v9 = temp_v9 - 2.1474836e9f;
    }
    func_00135130(arg0,CONCAT44(fStack_4,fStack_8),(s32)temp_v9 & 0xff,(u8 *)&sStack_30);
  }
  fStack_8 = temp_v15 + *(f32 *)(pbVar8 + 0x1350) + 640.0f;
  fStack_4 = temp_v16 + *(f32 *)(pbVar8 + 0x1354) + 400.0f;
  temp_v17 = (f32)pbVar8[0x135a] * temp_v17;
  if (2.1474836e9f <= temp_v17) {
    temp_v17 = temp_v17 - 2.1474836e9f;
  }
  func_0034f9d0(CONCAT44(fStack_4,fStack_8),0.0f,(s32)temp_v17 & 0xff,*(u16 *)(pbVar8 + 0xc78),
                *(u32 *)(pbVar8 + 0x1590));
  return;
}
#pragma opt_dead_assignments on
#else
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00131a00);
#endif

// FUN_001344B0
s32 func_001344b0(u8 *arg0, s32 arg1, s16 arg2) {
    /* The offset must be computed before the base is added: writing
       `arg0 + arg1 * 2` makes mwcc emit `addu $v1,$a0,$v0`, retail has
       `addu $v1,$v0,$a0`. */
    s32 off = arg1 * 2;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s16 *)(p + 0x30) = *(s16 *)(p + 0x28);
    *(s16 *)(p + 0x28) = arg2;
    return 1;
}

// FUN_001344D0
void func_001344d0(u8 *arg0) {
    s32 i;
    s16 v;

    v = *(s16 *)(arg0 + 0x24);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x24) = v + 1;
    }
    for (i = 0; i < 3; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x1430, *(s16 *)(arg0 + 0x24), 0);
    }
}

/* measured: equipment-mode switch and table update match the retail window. */
/* measured: common-subexpression elimination is disabled for the setup and switch layout. */
#pragma opt_common_subs off
// FUN_00134560
s32 func_00134560(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    if (arg1 == *(s32 *)(arg0 + 0x18)) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = arg0 + i * 0x30;
        *(f32 *)(dst + 0xC80) = *(f32 *)(dst + 0xC90);
        *(f32 *)(dst + 0xC84) = *(f32 *)(dst + 0xC94);
        *(u8 *)(dst + 0xC98) = *(u8 *)(dst + 0xC9A);
        *(u16 *)(dst + 0xC9C) = *(u16 *)(dst + 0xCA0);
        *(u16 *)(dst + 0xCA2) = *(u16 *)(dst + 0xCA6);
    }
    switch (arg1) {
    case 0:
        table = D_005E7720;
        *(s32 *)(arg0 + 0x1C) = 0x494;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 1:
        table = D_005E7BA0;
        break;
    case 2:
        table = D_005E8020;
        *(s32 *)(arg0 + 0x1C) = 0x494;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 3:
        table = D_005E84A0;
        *(s32 *)(arg0 + 0x1C) = 0x5BC;
        *(s16 *)(arg0 + 0xC78) = 0;
        *(f32 *)(arg0 + 0x11F4) =
            30.0f * (f32)*(s16 *)(arg0 + 0x28);
        *(f32 *)(arg0 + 0x1224) =
            30.0f * (f32)*(s16 *)(arg0 + 0x28);
        break;
    case 4:
        table = D_005E8920;
        *(s32 *)(arg0 + 0x1C) = 0x538;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 5:
        table = D_005E8DA0;
        *(s32 *)(arg0 + 0x1C) = 0x538;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 6:
        table = D_005E9220;
        func_00131730((s16 *)arg0);
        *(s32 *)(arg0 + 0x1C) = 0x3A0B;
        *(s16 *)(arg0 + 0xC78) = 3;
        break;
    case 7:
        table = D_005E96A0;
        *(s32 *)(arg0 + 0x1C) = 0x3A0B;
        *(s16 *)(arg0 + 0xC78) = 3;
        break;
    case 8:
    case 9:
        table = D_005E9B20;
        *(s32 *)(arg0 + 0x1C) = 0x3A4A;
        *(s16 *)(arg0 + 0xC78) = 4;
        break;
    default:
        func_0046d730(D_005E9FA0, 0x5F8);
        break;
    }
    if (table != 0) {
#pragma opt_common_subs on
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32 *)(dst + 0xC88) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0xC8C) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0xC99) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0xC9E) = (u16)value;
            value = *(f32 *)(src + 0xC);
            *(u16 *)(dst + 0xCA4) = (u16)value;
            *(s32 *)(dst + 0xCA8) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0xCAC) = *(s32 *)(src + 0x18);
        }
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0x20) = 0;
    return 1;
}
#pragma opt_loop_invariants off

