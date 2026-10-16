/* Source unit: src/Graphics/Model/mdlFile_00230bc0.c (1 function markers) */
#include "type.h"

#define MODEL_TYPE_BTLCHAR 1
#define MODEL_TYPE_ENEMY 2

typedef int (*code)();
extern code DAT_008873ec_abs[];
extern u64 Vpad_Activate();
extern u64 func_0047de90_wide(u32 *param_1);
extern u32 func_004b57a0_u32(u64 param_1, u64 param_2);
extern u32 K_Clump_MatUsrDataGetInt();
extern u32 func_004578b0_ptr(u32 param_1,u8 *param_2);
extern u8 DAT_00713200[];
extern u8 DAT_00713200_abs[];
extern u64 K_ClumpMatColorStore();

static inline u8 mdlFileToU8(f32 value)
{
  return (u8)value;
}

/* W409 measured: P3 donor carried NONMATCHING 204/224 nd74 -> MATCH 216/224 nd0 annotation; ported verbatim. */
extern u32 DAT_00922c30;
extern u8 DAT_00922c30_abs[];



// FUN_00230BC0
s32 mdlFileIsTypePac(u32 type, u16 id)
{
    switch ((u16)type)
    {
        case MODEL_TYPE_BTLCHAR: // fallthrough
        case MODEL_TYPE_ENEMY:   return 1;
    }

    return 0;
}



/* Releases one reference on a shared wrapper: frees the handle at +4, decrements the object's count at +0 (freeing the object at zero) and frees the wrapper. */
// FUN_0047DCC0
void mdlReleaseSharedWrapper(int *param_1)
{
    if (param_1[1] != 0) {
        Vpad_Activate(param_1[1]);
    }
    *(int*)(*param_1 + 4) = *(int*)(*param_1 + 4) - 1;
    if (*(int*)(*param_1 + 4) == 0) {
        ((void (*)())DAT_008873ec_abs[0])(*param_1);
    }
    ((void (*)())DAT_008873ec_abs[0])(param_1);
}




/* Stores a value at +4 of the wrapper, computed from the wrapper and the 64-bit argument through two helpers. */
// FUN_0047DE00
void mdlSetWrapperValue(int param_1,u64 param_2)
{
  u64 uVar1;

  u32 uVar2;

  uVar1 = func_0047de90_wide((u32 *)param_1);

  uVar2 = func_004b57a0_u32(uVar1,param_2);

  *(u32 *)(param_1 + 4) = uVar2;

  return;

}



/* Releases the handle at +4 of the wrapper and clears it to zero. */
// FUN_0047DE50
void mdlClearWrapperHandle(int param_1)
{
  if (*(int *)(param_1 + 4) != 0) {
    Vpad_Activate(*(int *)(param_1 + 4));
    *(u32 *)(param_1 + 4) = 0;
  }
  return;
}



/* Apply callback for the colour row: takes the RGB word for the target and an alpha byte (1 minus the row's second float, scaled to 255), then writes the four bytes to the target material's colour user data. */
// FUN_0047F2C0
void mdlApplyMaterialColorRow(void *param_1,void *param_2)
{
  u32 uVar1;
  float fVar2;
  u8 rgba[4];
  u32 alpha;

  uVar1 = func_004578b0_ptr((u32)param_2,DAT_00713200_abs);

  fVar2 = (1.0f - ((f32 *)param_1)[1]) * 255.0f;

  alpha = mdlFileToU8(fVar2);
  rgba[2] = (u8)uVar1;
  rgba[1] = (u8)((u32)uVar1 >> 8);
  rgba[0] = (u8)((u32)uVar1 >> 0x10);
  rgba[3] = (u8)alpha;

  K_ClumpMatColorStore((u32)param_2,rgba);
  return;
}







/* 64/64 bytes; two resolved relocations. Pass the released object explicitly
 * rather than relying on an incidental live argument register. */
/* Drops one u16 reference at +8 and frees the object at zero. */
// FUN_004808B0
void mdlReleaseU16Ref(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) - 1;
  if (*(u16 *)(param_1 + 8) == 0) {
    ((void (*)(void *))DAT_008873ec_abs[0])((void *)param_1);
  }
  return;
}



/* Adds one u16 reference at +8 and returns the object. */
// FUN_004808F0
u32 mdlRetainU16Ref(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) + 1;

  return param_1;

}



/* Appends one u32 to the table at *param_1: stores it at the index given by the u16 count at +4, then increments the count. */
// FUN_00480910
void mdlAppendU32Entry(int *param_1,u32 param_2)
{
  *(u32 *)(*param_1 + (u32)*(u16 *)(param_1 + 1) * 4) = param_2;

  *(short *)(param_1 + 1) = (u16)param_1[1] + 1;

  return;

}
