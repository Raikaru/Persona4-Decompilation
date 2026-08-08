/* Consolidated Persona 4 source units. */
/* Original translation unit mdlMatAnim.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];
extern void func_004808b0(int param_1);
extern void func_0044ea90(u8 *file, s32 line);
extern void func_0047f850(u8 *param_1, u8 *param_2, f32 param_3, f32 param_4, f32 param_5);
extern u8 D_00713260[];
extern u32 D_00713220[];

typedef struct {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_C;
} MdlFrameDispatch;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0043f9c8(void *dest, s32 value, s32 size);

extern s32 func_003bcfb0();
extern s32 func_003bd000();
extern s32 func_003bd040();
extern s32 func_003bd050();
extern s32 func_003bd060();
extern s32 func_003bd0b0();
extern s32 strcmp();
extern void func_00480910(int *param_1,u32 param_2);
extern u8 DAT_007641e0;

extern u32 func_00480430(u32 param_1,u32 *param_2);

extern u64 func_003bff30();
extern u32 func_00480580(u32 param_1,u32 param_2);

extern u8 *func_00480670(u8 *param_1, u8 *param_2);
extern void func_003bff30_typed(u64 param_1,void *param_2,void *param_3);





// FUN_0047F9F0
s32 *func_0047f9f0(void)
{
    s32 *anim;

    func_0044ea90(D_00713260, 0x22C);
    anim = (s32 *)jtbl_008873E8[0](4, 0x40000);
    func_0043f9c8(anim, 0, 4);
    *anim = 0;
    return anim;
}

// FUN_0047FA60
void func_0047fa60(int param_1)
{
  int iVar2;
  int iVar1;
  u32 uVar4;
  u32 *puVar3;

  iVar2 = *(int *)param_1;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x54);
    for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
      puVar3 = (u32 *)(iVar2 + uVar4 * 0x10);
      if (puVar3[3] != 0) {
        ((void (*)(...))DAT_008873ec_abs[0])(puVar3[3]);
        puVar3[3] = 0;
      }
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
    }
    func_004808b0(*(u32 *)(iVar2 + 0x50));
    ((void (*)(...))DAT_008873ec_abs[0])(iVar2);
    iVar2 = iVar1;
  }
  ((void (*)(...))DAT_008873ec_abs[0])(param_1);
  return;
}





// FUN_0047FB50
u8 *func_0047fb50(u8 **arg0, s32 *arg1)
{
    s32 temp_6;
    s32 var_9;
    s32 temp_8;
    u8 *temp_7;
    u8 *var_2;

    temp_8 = *(u16 *)(arg1 + 1);
    var_2 = (u8 *)(*arg0);
    while (var_2 != NULL) {
        temp_7 = (u8 *)(*(u8 **)(var_2 + 0x50));
        if (temp_7 == (u8 *)arg1) {
            return var_2;
        }
        if (*(u16 *)(temp_7 + 4) == temp_8) {
            var_9 = 0;
            while (var_9 < temp_8) {
                temp_6 = (var_9 & 0xFFFF) * 4;
                if (*(u32 *)(*(u8 **)temp_7 + temp_6) == *(u32 *)(*(u8 **)arg1 + temp_6)) {
                    var_9 += 1;
                } else {
                    break;
                }
            }
            if (var_9 == temp_8) {
                return var_2;
            }
        }
        var_2 = (u8 *)(*(u8 **)(var_2 + 0x54));
    }
    return NULL;
}



/* measured: declaration permutation {node, tbl, entry, i, j, work, count, init,
   apply} preserves the full 276-byte control-flow body and improves the parked
   candidate from nd 17 to nd 7 (obj 276B/window 288B). Remaining fndiff rows
   are offsets 0x38/0x3C (tbl/entry saved-register swap), 0x58/0x5C
   (entry load), 0x7C (init pointer load), 0x9C (table load), and 0xAC
   (apply pointer load): checklist item 4, live-range/saved-register coloring.
   Committed at nd 7. */
// FUN_0047FBF0 NONMATCHING
#ifdef NON_MATCHING
void func_0047fbf0(u8 **arg0, f32 scale)
{
    u8 *node;
    u8 *tbl;
    u8 *entry;
    u32 i;
    u32 j;
    u8 *work;
    u32 count;
    u8 *(*init)(u8 *, f32);
    void (*apply)(u8 *, u32);

    node = *arg0;
    while (node != NULL) {
        tbl = *(u8 **)(node + 0x50);
        count = *(u16 *)(tbl + 4);
        for (i = 0; i < 4; i++) {
            entry = (u8 *)D_00713220 + i * 0x10;
            if (*(u32 *)(entry + 0xC) == 0) {
                continue;
            }
            if (*(u32 *)(node + i * 0x10 + 0xC) == 0) {
                continue;
            }
            init = (u8 *(*)(u8 *, f32))*(u32 *)entry;
            work = init(node + i * 0x10, scale);
            for (j = 0; j < count; j++) {
                apply = (void (*)(u8 *, u32))*(u32 *)(entry + 0xC);
                apply(work, *(u32 *)(*(u8 **)tbl + j * 4));
            }
        }
        node = *(u8 **)(node + 0x54);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mdlMatAnim", func_0047fbf0);
#endif



/* measured: retail colors node-ptr temp_16 -> $s0 and D-table entry temp_17 -> $s1;
   mwcc b210 always colors the entry pointer $s0 / node pointer $s1 (identity-based,
   decl-order independent), and then swaps the apply-call move/lw order. With the
   correct 4-arg interleaved create prototype everything else matches; best nd 10.
   Same pair wall as FUN_0047FBF0 / FUN_0047FE90. */
// FUN_0047FD10
INCLUDE_ASM("asm/nonmatchings/mdlMatAnim", func_0047fd10);



/* measured: retail colors node-ptr temp_16 -> $s0 and D-table entry temp_17 -> $s1;
   mwcc b210 always colors the entry pointer $s0 / node pointer $s1 no matter the
   declaration order (10 orders tried, best nd 11), and swaps the apply-call move/lw
   order as a consequence. Correct create prototype is 4-arg interleaved
   (u8*,f32,u8*,f32) with temp_4_2 as first arg (already in $a0 from the guard check);
   with that, everything else matches. Same pair wall as FUN_0047FBF0/FUN_0047FD10. */
// FUN_0047FE90
INCLUDE_ASM("asm/nonmatchings/mdlMatAnim", func_0047fe90);

// FUN_0047FFC0
void func_0047ffc0(int *param_1)
{
  u8 uVar0;

  u8 uVar1;

  u8 uVar2;

  u8 uVar3;

  u32 uVar4;

  int *piVar5;

  int iVar6;

  int iVar8;

  u32 uVar7;

  f32 fVar9;

  f32 fVar11;
  f32 fVar10;

  iVar8 = *param_1;
  for (; iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x54)) {

    piVar5 = *(int **)(iVar8 + 0x50);

    uVar4 = *(u16 *)(piVar5 + 1);

    for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
      iVar6 = *(int *)(*piVar5 + uVar7 * 4);
      uVar0 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x40);
      uVar1 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x41);
      uVar2 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x42);
      uVar3 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x43);
      *(u8 *)(iVar6 + 4) = uVar0;
      *(u8 *)(iVar6 + 5) = uVar1;
      *(u8 *)(iVar6 + 6) = uVar2;
      *(u8 *)(iVar6 + 7) = uVar3;
      iVar6 = *(int *)(*piVar5 + uVar7 * 4);
      fVar9 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ f32 *)(iVar8 + 0x44);
      fVar10 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ f32 *)(iVar8 + 0x48);
      fVar11 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ f32 *)(iVar8 + 0x4c);
      *(f32 *)(iVar6 + 0xc) = fVar9;
      *(f32 *)(iVar6 + 0x10) = fVar10;
      *(f32 *)(iVar6 + 0x14) = fVar11;
    }


  }

  return;

}





// FUN_00480060
f32 func_00480060(u8 **arg0)
{
    f32 var_f0;
    f32 temp_f1;
    u8 *var_5;
    u32 var_4;

    var_f0 = 0.0f;
    var_5 = (u8 *)(*arg0);
    while (var_5 != NULL) {
        var_4 = 0;
        while (var_4 < 4U) {
            if (*(s32 *)(var_5 + var_4 * 0x10 + 0xC) != 0) {
                temp_f1 = *(f32 *)(var_5 + var_4 * 0x10 + 4);
                if (temp_f1 > var_f0) {
                    var_f0 = temp_f1;
                }
            }
            var_4 += 1;
        }
        var_5 = (u8 *)(*(u8 **)(var_5 + 0x54));
    }
    return var_f0;
}



/* measured: best C (m2c-style loop + batched u8/f32 copies + old-style externs for the
   u64-param calls func_00480800/00480840/00480630 with (u32) casts) reaches nd 103;
   retail allocates args $s5..$s2 + bVar5 $s6 with var_17 at $s1, mwcc b210 always puts
   the args one reg lower ($s4..$s1, bVar5 $s5, var_17 last) no matter the declaration
   order, and the search loop's exit-edge NULL plus the lbu/lwc1 copy register rotation
   resist all loop spellings (while+break, if/else, goto-found, m2c goto: nd 103..149).
   P3 twin FUN_00320880 is NONMATCHING for the same family. */
// FUN_004800D0
INCLUDE_ASM("asm/nonmatchings/mdlMatAnim", func_004800d0);



// FUN_00480430
u32 func_00480430(u32 param_1,u32 *param_2)
{
  s32 arrayCount;
  s32 dataCount;
  s32 arrayIndex;
  s32 dataIndex;
  void *userData;
  char *name;
  char *data;

  arrayCount = func_003bcfb0();
  arrayIndex = 0;
  while (arrayIndex < arrayCount) {
    userData = (void *)func_003bd000(param_1,arrayIndex);
    name = (char *)func_003bd040((u32)userData);
    if (strcmp(name,(char *)&DAT_007641e0) == 0) {
      dataCount = func_003bd060((u32)userData);
      dataIndex = 0;
      while (dataIndex < dataCount) {
        if (func_003bd050((u32)userData) == 3) {
          data = (char *)func_003bd0b0((u32)userData,dataIndex);
          if (strcmp((char *)param_2[1],data) == 0) {
            func_00480910((int *)*param_2,param_1);
            return 0;
          }
        }
        dataIndex++;
      }
    }
    arrayIndex++;
  }
  return param_1;
}



// FUN_00480580
u32 func_00480580(u32 param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  u32 lVar3;
  int iVar4;

  iVar1 = *(int *)((int)param_1 + 0x18);
  iVar2 = *(int *)(iVar1 + 0x24);
  iVar4 = 0;
  goto check;
loop:
  lVar3 = func_00480430((int)(*(u32 *)(*(int *)(iVar1 + 0x20) + iVar4 * 4)),(u32 *)(param_2));
  if (lVar3 != 0) {
    goto increment;
  }
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 0x40;
  goto done;
increment:
  iVar4 = iVar4 + 1;
check:
  if (iVar4 < iVar2) {
    goto loop;
  }
done:
  return param_1;
}



// FUN_00480630
u64 func_00480630(u64 param_1,u64 param_2)
{
  func_003bff30(param_1,(void (*)())func_00480580,param_2);
  return param_1;
}





/* measured: retail stores the s128-returning func_003bcfb0/func_003bd060 results with
   sq and reloads them with lq, then compares raw (lq $v0; slt $v0, $s0, $v0). The sq/lq
   side matches with u_long128/u64 locals + aliased s128-returning externs, but mwcc b210
   ALWAYS emits a dsll32/dsra32 sign-extension for the mixed-width loop compare that
   retail lacks (tried s128 signed/unsigned, u64, u_long128; direct, (s32)/(s64)/(u32)
   casts; s32/u32/s64 counters; 8 decl orders; best nd 38). Same wall as P3 FUN_00320de0
   (W414, nd17). Also a 3-way saved-reg rotation (var_18/var_17/temp_2). */
// FUN_00480670
INCLUDE_ASM("asm/nonmatchings/mdlMatAnim", func_00480670);

// FUN_00480800
u16 func_00480800(u64 param_1,u32 param_2)
{
  struct {
    u32 input;
    u16 output;
  } stack;

  stack.input = param_2;
  stack.output = 0;
  func_003bff30_typed(param_1,(void *)&func_00480670,&stack);
  return stack.output;
}



// FUN_00480840
u8 *func_00480840(s32 arg0)
{
    u8 *anim;

    func_0044ea90(D_00713260, 0x3E1);
    anim = (u8 *)jtbl_008873E8[0]((u16)arg0 * 4 + 0xC, 0x40000);
    *(s32 *)anim = (s32)(anim + 0xC);
    *(u16 *)(anim + 4) = 0;
    *(u16 *)(anim + 8) = 1;
    *(u16 *)(anim + 6) = arg0;
    return anim;
}
