#include "include_asm.h"
/* Source unit: src/Graphics/Model/mdlFile_0047d2d0.c (1 function markers) */
#include "type.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];
extern void func_0047d990(u32 *param_1);

extern void func_004b11d0(s32 arg0, s32 arg1);

extern void func_004b1170();

extern void func_004b13f0(s32 arg0, s32 arg1);

extern void func_004b13d0(float param_1, u8 param_2[][16]);
extern void func_0047dae0(u32 *param_1);
extern void func_004b1150_i(int param_1);
extern u32 func_004b1130_u32(u32 param_1);
extern u32 func_004b11b0();

extern void func_004824a0(int *param_1, u8 *param_2, float *param_3);

extern u64 memcpy();

extern void func_00487fb0(float param_1, int param_2);
extern void func_00487fb0_evt(float param_1);

extern void func_00492e30(u16 *param_1);

typedef unsigned int u_long128 __attribute__((mode(TI)));

extern void func_0044ea90(u8 *file, s32 line);
extern u8 D_007131E8[];
/* Defined below in this file; called at line 54, above its definition. */
extern void func_0047d310(u32 *param_1);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_0047a510(void *arg0, s32 arg1, void *arg2);
extern void func_003e0670(void *matrixOut, void *matrixIn);
extern void func_003dc610(void *arg0, void *arg1);
extern void func_004b12e0(s32 arg0, void *arg1);
extern void func_004b1190(s32 arg0);




// FUN_0047D1A0
u32 func_0047d1a0(void)
{
    u32 temp_2;

    func_0044ea90(D_007131E8, 0x2D);
    temp_2 = (u32)(*jtbl_008873E8)(4, 0x40000);
    func_0047d310((u32 *)temp_2);
    return temp_2;
}

/* Defined below in this file; called at line 61, above its definition. */
extern u32 *func_0047d460(u32 *list, u32 *arg1, u16 arg2);

// FUN_0047D200
u32 *func_0047d200(u32 **arg0)
{
    u32 *temp;
    u32 *cur;

    func_0044ea90(D_007131E8, 0x2D);
    temp = (u32 *)(*jtbl_008873E8)(4, 0x40000);
    func_0047d310(temp);
    cur = (u32 *)*arg0;
    if (cur == NULL) {
        return temp;
    }
    while (cur[4] != 0) {
        cur = (u32 *)cur[4];
    }
    while (cur != NULL) {
        func_0047d460(temp, cur, *(u16 *)((u8 *)cur + 4));
        cur = (u32 *)cur[3];
    }
    return temp;
}
// FUN_0047D2D0
void func_0047d2d0(u32 *param_1)
{
  func_0047d990(param_1);

  DAT_008873ec_abs[0](param_1);
}




// FUN_0047D310
void func_0047d310(u32 *param_1)
{
    *param_1 = 0;
}

// FUN_0047D320
u32 *func_0047d320(u32 **arg0, s32 arg1, u32 arg2, u16 arg3, u32 arg4)
{
    u32 base;
    u32 head;
    u32 *data;
    u32 *node;

    func_0044ea90(D_007131E8, 0x7F);
    data = (u32 *)(base = (u32)jtbl_008873E8,
                   ((void *(*)(u32, u32))*(u32 *)base)(arg2 + 0x10, 0x40000));
    data[0] = (u32)((u8 *)data + 0x10);
    data[1] = 0;
    data[3] = arg4;
    data[2] = 1;
    func_0043f810((void *)data[0], (const void *)arg1, arg2);
    func_0044ea90(D_007131E8, 0x66);
    node = (u32 *)((void *(*)(u32, u32))*(u32 *)base)(0x14, 0x40000);
    func_0043f9c8(node, 0, 0x14);
    node[3] = 0;
    head = (u32)*arg0;
    if (head != 0) {
        ((u32 *)head)[3] = (u32)node;
        head = (u32)*arg0;
        node[4] = head;
    } else {
        node[4] = 0;
    }
    *arg0 = node;
    node[0] = (u32)data;
    *(u16 *)((u8 *)node + 4) = arg3;
    return node;
}

// FUN_0047D460
u32 *func_0047d460(u32 *list, u32 *arg1, u16 arg2)
{
    u32 head;
    u32 *data;
    u32 *node;

    func_0044ea90(D_007131E8, 0x66);
    node = (u32 *)(*jtbl_008873E8)(0x14, 0x40000);
    func_0043f9c8(node, 0, 0x14);
    node[3] = 0;
    head = *list;
    if (head != 0) {
        ((u32 *)head)[3] = (u32)node;
        head = *list;
        node[4] = head;
    } else {
        node[4] = 0;
    }
    *list = (u32)node;
    node[0] = arg1[0];
    *(u16 *)((u8 *)node + 4) = arg2;
    data = *(u32 **)arg1;
    data[2] = data[2] + 1;
    return node;
}

/* measured: nd 14 floor. ALL non-float code matches byte-for-byte, including
   the MtxRow {f32 x,y,z; s32 flag;} out[4] layout (holes at 0x5C/0x6C/0x7C),
   the 8x8-byte copy loop (t0/t1 temps, dst/count/src preheader), the identity
   branch, sp4C |= 0x20003, and the in[12..14] -> f2/f1/f0 temp loads. Residual
   is only the FP math: (1) BOTH sqrt/mula chains emit mula x, madda y where
   retail has mula y, madda x -- same loads, same regs (x->f5, y->f6), and the
   term order is compiler-canonical in my compile regardless of source
   expression order (y*y + x*x + z*z + w*w) or decl order (tried x,y,z,w and
   y,x,z,w); (2) block-2 reloads: mwcc loads y,z,w,x assigning x->f11, z->f12
   where retail loads y,x,z,w with x->f12, z->f11 -- the fresh-reg assignment
   order flips, cascading into 6 mul.s rows. Also tried id-local vs inline
   node+8 loads, out as f32[16], and three copy-loop spellings; the retained
   shapes are the best. mula/madda term-order floor, cf. btlShuffleDraw
   func_00377930 note. */
// FUN_0047D540
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0047d540);
// FUN_0047D7E0
void func_0047d7e0(s32 arg0, u8 **arg1)
{
    s32 temp_5;
    u8 *var_16;

    var_16 = *arg1;
    while (var_16 != NULL) {
        temp_5 = *(s32 *)(var_16 + 8);
        if (temp_5 != 0) {
            func_004b11d0(arg0, temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0x10);
    }
}



// FUN_0047D840
void func_0047d840(u32 *param_1)
{
  int *piVar1;

  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {

    if ((piVar1[2] != 0) && ((*(u32 *)(*piVar1 + 0xc) & 1) != 0)) {

      func_004b1170(piVar1[2]);
    }


  }

  return;

}



// FUN_0047D8A0
void func_0047d8a0(u8 **arg0, s32 arg1)
{
    s32 temp_4;
    u8 *var_16;

    var_16 = *arg0;
    while (var_16 != NULL) {
        temp_4 = *(s32 *)(var_16 + 8);
        if (temp_4 != 0) {
            func_004b13f0(temp_4, arg1);
        }
        var_16 = *(u8 **)(var_16 + 0x10);
    }
}



// FUN_0047D900
void func_0047d900(int *param_1,float *param_2)
{
    int current;
    float average;

    average = (param_2[0] + param_2[1] + param_2[2]) / 3.0f;
    for (current = *param_1; current != 0; current = *(int*)(current + 0x10)) {
        if (*(int*)(current + 8) != 0) {
            func_004b13d0(average,(u8 (*)[16])*(u32*)(current + 8));
        }
    }
}



// FUN_0047D990
void func_0047d990(u32 *param_1)
{
    int *current;
    int *next;

    func_0047dae0(param_1);
    current = (int*)*param_1;
    while (current != 0) {
        next = (int*)current[4];
        *(int*)(*current + 8) = *(int*)(*current + 8) - 1;
        if (*(int*)(*current + 8) == 0) {
            ((void (*)(...))DAT_008873ec_abs[0])(*current);
        }
        ((void (*)(...))DAT_008873ec_abs[0])(current);
        current = next;
    }
    *param_1 = 0;
}




// FUN_0047DA30
void func_0047da30(u32 *param_1)
{
    int *current;
    u32 value;

    for (current = (int*)*param_1; current != 0; current = (int*)current[4]) {
        if (current[2] != 0) {
            if (current[2] == *(int*)(*current + 4)) {
                *(u32*)(*current + 4) = 0;
            }
            func_004b1150_i(current[2]);
        }
        if (((u32*)*current)[1] == 0) {
            value = func_004b1130_u32(*(u32*)*current);
            current[2] = value;
            *(u32*)(*current + 4) = value;
        } else {
            value = func_004b11b0((u64*)((u32*)*current)[1]);
            current[2] = value;
        }
    }
}




// FUN_0047DAE0
void func_0047dae0(u32 *param_1)
{
  int *piVar1;

  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {

    if (piVar1[2] != 0) {

      if (piVar1[2] == *(int *)(*piVar1 + 4)) {

        *(u32 *)(*piVar1 + 4) = 0;

      }

      func_004b1150_i(piVar1[2]);

      piVar1[2] = 0;

    }

  }

  return;

}




// FUN_0047DB50
u32 *func_0047db50(s32 arg0, s32 arg1)
{
    u32 *node;
    u32 *wrap;
    u32 base;

    func_0044ea90(D_007131E8, 0x18A);
    node = (u32 *)(base = (u32)jtbl_008873E8,
                   ((void *(*)(u32, u32))*(u32 *)base)(arg1 + 0x10, 0x40000));
    node[0] = (u32)((u8 *)node + 0x10);
    node[1] = 1;
    func_0043f810((void *)node[0], (void *)arg0, (u32)arg1);
    func_0044ea90(D_007131E8, 0x17C);
    wrap = (u32 *)((void *(*)(u32, u32))*(u32 *)base)(8, 0x40000);
    func_0043f9c8(wrap, 0, 8);
    wrap[0] = (u32)node;
    return wrap;
}
// FUN_0047DC30
u32 *func_0047dc30(u32 **arg0)
{
    u32 *obj;
    u32 *temp;

    func_0044ea90(D_007131E8, 0x17C);
    temp = (u32 *)(*jtbl_008873E8)(8, 0x40000);
    func_0043f9c8(temp, 0, 8);
    obj = *arg0;
    temp[0] = (u32)obj;
    obj[1] = obj[1] + 1;
    return temp;
}
// FUN_00482700
void func_00482700(int param_1, float *param_2)
{
  func_004824a0((int *)(u32)param_1, (u8 *)(u32)*(u32 *)(param_1 + 0x10), param_2);
}


/* Removing this loses FUN_00482730 (MATCH nd0 -> MISMATCH nd45) - measured W161. */

// FUN_00482730
/* measured: opt_loop_invariants on is required for func_00482730 (MATCH nd0). */
#pragma opt_loop_invariants on
void func_00482730(int param_1, u32 param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = *(int *)(param_1 + 0xc);
  for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    iVar2 = *(int *)(param_1 + 0x10) + iVar3 * 0x14;
    *(u32 *)(iVar2 + 4) = param_2 % *(u32 *)(*(int *)(iVar2 + 0xc) + 0xc);
    *(u32 *)(iVar2 + 8) = 1;
  }
  return;
}


/* measured: opt_loop_invariants off closes the func_00482730 bracket. */
#pragma opt_loop_invariants off

// FUN_00484490
int func_00484490(int param_1)
{
  int value;

  if (*(int *)(param_1 + 0x18) == 0) {
    goto check;
  }

  value = *(int *)(param_1 + 0x10);
  goto done;
check:
  value = *(int *)(param_1 + 0x10);
  if (value == 0) {
    goto zero;
  }

  value = (int)((u8 *)param_1 + value);
  goto done;
zero:
  value = 0;
done:
  return value;
}



// FUN_004844D0
int func_004844d0(int param_1)
{
  int value;

  if (*(int *)(param_1 + 0x28) == 0) {
    goto check;
  }

  value = *(int *)(param_1 + 0x20);
  goto done;
check:
  value = *(int *)(param_1 + 0x20);
  if (value == 0) {
    goto zero;
  }

  value = (int)((u8 *)param_1 + value);
  goto done;
zero:
  value = 0;
done:
  return value;
}



// FUN_00486710
void func_00486710(u64 param_1, u64 param_2)
{
  memcpy(param_1, param_2, 0x90);
  return;
}



// FUN_00486740
int func_00486740(int param_1, int param_2)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x8c);
  while (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x90) == param_2) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar1 + 0xac);
  }

  return 0;
}



// FUN_00489E50
void func_00489e50(void)
{
  func_00487fb0_evt(1.0f);
}



// FUN_00489F50
void func_00489f50(f32 param_1, int param_2)
{
  *(f32 *)(param_2 + 8) = param_1;
  func_00492e30((u16 *)*(u32 *)(param_2 + 0x4c));
  return;
}


/* Retail's 368-byte Catmull-Rom interpolator builds tangents and returns its VU0 vector in vf10. */

// FUN_00489F80
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_00489f80);
// FUN_0048A000
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a000);
// FUN_0048A070
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a070);
// FUN_0048A0E0
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a0e0);
// FUN_0048A150
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a150);
// FUN_0048A1F0
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a1f0);
// FUN_0048A250
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a250);
// FUN_0048A2B0
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a2b0);
// FUN_0048A340
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a340);
// FUN_0048A460
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a460);
// FUN_0048A510
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a510);
// FUN_0048A650
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_0048a650);
// FUN_0048A810
void func_0048a810(float param_1, u8 (*param_2)[16])
{
  float work[7][4];
  float square;
  float cube;
  float coefficient;

  square = param_1 * param_1;
  cube = square * param_1;

  work[4][0] = 0.5f;
  work[4][1] = 0.5f;
  work[4][2] = 0.5f;

  /* VU0 builds the two Catmull-Rom tangent vectors in work[6] and work[5]. */
  asm volatile (
      ".set noreorder                         \n"
      "lqc2        $vf10, 0x10($a0)           \n"
      "lqc2        $vf11, 0x0($a0)            \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "lqc2        $vf10, 0x20($a0)           \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      "addiu       $v1, $sp, 0x40              \n"
      "lqc2        $vf11, 0x0($v1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "addiu       $a2, $sp, 0x60              \n"
      "sqc2        $vf10, 0x0($a2)            \n"
      "lqc2        $vf10, 0x20($a0)           \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "lqc2        $vf10, 0x30($a0)           \n"
      "lqc2        $vf11, 0x20($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      "lqc2        $vf11, 0x0($v1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "addiu       $a1, $sp, 0x50              \n"
      "sqc2        $vf10, 0x0($a1)            \n"
      ".set reorder"
      :
      :
      : "memory"
  );

  coefficient = cube * 2.0f - square * 3.0f + 1.0f;
  work[0][0] = coefficient;
  work[0][1] = coefficient;
  work[0][2] = coefficient;

  coefficient = param_1 + (cube - square * 2.0f);
  work[1][0] = coefficient;
  work[1][1] = coefficient;
  work[1][2] = coefficient;

  coefficient = cube - square;
  work[2][0] = coefficient;
  work[2][1] = coefficient;
  work[2][2] = coefficient;

  coefficient = cube * -2.0f + square * 3.0f;
  work[3][0] = coefficient;
  work[3][1] = coefficient;
  work[3][2] = coefficient;

  /* VU0 evaluates the Hermite basis and leaves the interpolated vector in vf10. */
  asm volatile (
      ".set noreorder                         \n"
      "addiu       $v1, $sp, 0x0               \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "addiu       $v1, $sp, 0x10              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x0($a2)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf12, $vf12, $vf10        \n"
      "addiu       $v1, $sp, 0x20              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x0($a1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf12, $vf12, $vf10        \n"
      "addiu       $v1, $sp, 0x30              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x20($a0)           \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      ".set reorder"
      :
      :
      : "memory"
  );
}



// FUN_00492DB0
u_long128 func_00492db0(int param_1, u32 *param_2)
{
  u_long128 value = *(u_long128 *)(*(int *)(param_1 + 0x20));
  *(u_long128 *)param_2 = value;
  return value;
}


/* measured: opt_propagation off preserves func_00492dd0's 128-bit load/store ordering (MATCH nd0). */
#pragma opt_propagation off

// FUN_00492DD0
u_long128 func_00492dd0(int param_1, u32 *param_2)
{
  u_long128 *dst;
  u_long128 value;

  dst = *(u_long128 **)(param_1 + 0x20);
  value = *(u_long128 *)param_2;
  *dst = value;
  return value;
}

/* measured: opt_propagation on closes the func_00492dd0 bracket. */
#pragma opt_propagation on


// FUN_00492DF0
u_long128 func_00492df0(int param_1, u32 *param_2)
{
  return *(u_long128 *)param_2 =
      *(u_long128 *)(*(int *)(param_1 + 0x20) + 0x10);
}


/* measured: opt_propagation off preserves func_00492e10's 128-bit load/store ordering (MATCH nd0). */
#pragma opt_propagation off

// FUN_00492E10
u_long128 func_00492e10(int param_1, u32 *param_2)
{
  u_long128 *dst;
  u_long128 value;

  dst = (u_long128 *)(*(int *)(param_1 + 0x20) + 0x10);
  value = *(u_long128 *)param_2;
  *dst = value;
  return value;
}
/* measured: opt_propagation on closes the func_00492e10 bracket. */
#pragma opt_propagation on



// FUN_004946D0
void func_004946d0(int param_1, u32 param_2)
{
  u32 index;
  u8 *base;

  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  *(u16 *)(base + index) = 0;

  return;
}



// FUN_004946F0
void func_004946f0(int param_1, u32 param_2)
{
  s16 value;
  u32 index;
  u8 *base;

  value = -1;
  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  *(s16 *)(base + index) = value;

  return;

}



// FUN_00494710
u8 func_00494710(int param_1, u32 param_2)
{
  u32 index;
  u8 *base;
  s16 value;

  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  value = *(s16 *)(base + index);

  return value == -1;
}



// FUN_004A6E50
void func_004a6e50(int param_1)
{
  *(u32 *)(param_1 + 0x10) = *(u32 *)(param_1 + 0x10) + 1;
}



// FUN_004A6E70
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_004a6e70);
// FUN_004A7760
INCLUDE_ASM("asm/nonmatchings/mdlEffect", func_004a7760);
// FUN_004A7790
u_long128 func_004a7790(u_long128 *arg0, u_long128 *arg1)
{
    return *arg0 = *arg1;
}
// FUN_004A77A0
void func_004a77a0(u32 *param_1, u32 param_2)
{
  param_1[5] = param_2;
}



// FUN_004AE020
u32 *func_004ae020(u32 *param_1, u8 *param_2)
{
  u32 *t2;
  int t1;
  int t3;
  u8 *t0;

  u8 c0;
  u8 c1;
  u8 c2;
  u8 c3;

  t2 = *(u32 **)((u8 *)param_1 + 0x18);
  t1 = t2[9];
  t3 = 0;
  goto check;
loop:
  t0 = *(u8 **)(t2[8] + t3 * 4);
  c0 = param_2[0];
  c1 = param_2[1];
  c2 = param_2[2];
  c3 = param_2[3];
  c0 = c0;
  c1 = c1;
  c2 = c2;
  c3 = c3;
  t0[4] = c0;
  t0[5] = c1;
  t0[6] = c2;
  t0[7] = c3;
  t3 = t3 + 1;
check:
  if (t3 < t1) goto loop;
  return param_1;
}



// FUN_004AE080
u32 *func_004ae080(u32 *param_1)
{
  u32 *p;

  p = *(u32 **)((u8 *)param_1 + 0x18);
  p[2] = p[2] | 0x40;
  return param_1;
}



// FUN_004B1580
u32 func_004b1580(int param_1)
{
  return *(u32 *)(param_1 + 0x84);
}



// FUN_004B2770
void func_004b2770(u32 *param_1, u32 param_2)
{
  *param_1 = param_2;
}
