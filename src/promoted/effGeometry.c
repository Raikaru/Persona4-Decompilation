/* Consolidated Persona 4 source units. */
/* Original translation unit effGeometry.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483700();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

void func_00483810();



// FUN_00483660
void func_00483660(u8 *arg0)
{
    RwMatrix matrix;

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_004836B0
void func_004836b0(u8 *arg0)
{
    RwMatrix matrix;

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_004839D0
void func_004839d0(int param_1, u32 *param_2)
{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)**(int **)(param_1 + 0x14);
  param_2[2] = (u32)piVar1;

  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    *param_2 = *(u32 *)(iVar2 + 0xc);
    param_2[1] = *(u32 *)(iVar2 + 0x10);
  }

  return;
}
