/* Source unit: src/Graphics/Model/mdlFile_00230bc0.c (1 function markers) */
#include "type.h"

#define MODEL_TYPE_BTLCHAR 1
#define MODEL_TYPE_ENEMY 2

typedef int (*code)();
extern code DAT_008873ec_abs[];
extern u64 func_004b5f20();
extern u64 func_0047de90_wide(u32 *param_1);
extern u32 func_004b57a0_u32(u64 param_1, u64 param_2);
extern u32 K_Clump_MatUsrDataGetInt();
extern u32 func_004578b0_ptr(u32 param_1,u8 *param_2);
extern u8 DAT_00713200[];
extern u8 DAT_00713200_abs[];
extern u64 func_004586f0();

static inline u8 mdlFileToU8(f32 value)
{
  return (u8)value;
}

/* W409 measured: P3 donor carried NONMATCHING 204/224 nd74 -> MATCH 216/224 nd0 annotation; ported verbatim. */
extern u32 DAT_00922c30;
extern u8 DAT_00922c30_abs[];



// FUN_00230BC0
u8 mdlFileIsTypePac(u16 type)
{
    switch (type)
    {
        case MODEL_TYPE_BTLCHAR: // fallthrough
        case MODEL_TYPE_ENEMY:   return 1;
    }

    return 0;
}



// FUN_0047DCC0
void func_0047dcc0(int *param_1)
{
    if (param_1[1] != 0) {
        func_004b5f20(param_1[1]);
    }
    *(int*)(*param_1 + 4) = *(int*)(*param_1 + 4) - 1;
    if (*(int*)(*param_1 + 4) == 0) {
        ((void (*)())DAT_008873ec_abs[0])(*param_1);
    }
    ((void (*)())DAT_008873ec_abs[0])(param_1);
}




// FUN_0047DE00
void func_0047de00(int param_1,u64 param_2)
{
  u64 uVar1;

  u32 uVar2;

  uVar1 = func_0047de90_wide((u32 *)param_1);

  uVar2 = func_004b57a0_u32(uVar1,param_2);

  *(u32 *)(param_1 + 4) = uVar2;

  return;

}



// FUN_0047DE50
void func_0047de50(int param_1)
{
  if (*(int *)(param_1 + 4) != 0) {
    func_004b5f20(*(int *)(param_1 + 4));
    *(u32 *)(param_1 + 4) = 0;
  }
  return;
}



// FUN_0047F2C0
void func_0047f2c0(f32 *param_1,u32 param_2)
{
  u32 uVar1;
  float fVar2;
  u8 rgba[4];
  u32 alpha;

  uVar1 = func_004578b0_ptr(param_2,DAT_00713200_abs);

  fVar2 = (1.0f - param_1[1]) * 255.0f;

  alpha = mdlFileToU8(fVar2);
  rgba[2] = (u8)uVar1;
  rgba[1] = (u8)((u32)uVar1 >> 8);
  rgba[0] = (u8)((u32)uVar1 >> 0x10);
  rgba[3] = (u8)alpha;

  func_004586f0(param_2,rgba);
  return;
}




// FUN_0047F3A0
u32 * func_0047f3a0(float param_1,int *param_2)
{
  float *key;
  float fraction;
  float start;
  float output;
  float difference;
  int high;
  int low;
  int stride;
  u8 *data;
  int mid;
  u32 address;

  data = (u8 *)param_2[3];
  low = 0;
  high = *param_2 - 1;
  stride = param_2[2];
  do {
    mid = (low + high + 1) >> 1;
    if (param_1 < *(float *)(data + stride * mid)) {
      high = --mid;
    }
    else {
      low = mid;
    }
  } while (low < high);
  if ((u32)mid >= (u32)(*param_2 - 1)) {
    address = mid * 0x10;
    address += (u32)data;
    *(float *)(DAT_00922c30_abs + 4) = *(float *)(address + 4);
    *(float *)(DAT_00922c30_abs + 8) = *(float *)(address + 8);
    *(float *)(DAT_00922c30_abs + 12) = *(float *)(address + 0xc);
  }
  else {
    key = (float *)((u32)(mid * 0x10) + (u32)data);
    start = key[0];
    fraction = param_1 - start;
    fraction /= key[4] - start;
    output = key[1];
    difference = key[5] - output;
    *(float *)(DAT_00922c30_abs + 4) = fraction * difference + output;
    output = key[2];
    difference = key[6] - output;
    *(float *)(DAT_00922c30_abs + 8) = fraction * difference + output;
    output = key[3];
    difference = key[7] - output;
    *(float *)(DAT_00922c30_abs + 12) = fraction * difference + output;
  }
  *(float *)DAT_00922c30_abs = param_1;
  return (u32 *)DAT_00922c30_abs;
}



// FUN_004808B0
void func_004808b0(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) - 1;
  if (*(u16 *)(param_1 + 8) == 0) {
    ((void (*)())(*(u32 *)0x008873ec))();
  }
  return;
}



// FUN_004808F0
u32 func_004808f0(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) + 1;

  return param_1;

}



// FUN_00480910
void func_00480910(int *param_1,u32 param_2)
{
  *(u32 *)(*param_1 + (u32)*(u16 *)(param_1 + 1) * 4) = param_2;

  *(short *)(param_1 + 1) = (u16)param_1[1] + 1;

  return;

}
