/* Consolidated Persona 4 source units. */
/* Original translation unit mdlMatAnim.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
#include "Kosaka/k_clump_internal.h"

typedef int (*code)();
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
extern s32 func_003bd0b0(u8 *userData, s32 index);
extern s32 strcmp(const char *left, const char *right);
extern void func_00480910(int *param_1,u32 param_2);
extern u8 DAT_007641e0;

extern void *func_00480430(void *object, void *data);

extern void *func_00480580(void *object, void *data);

extern void *func_00480670(void *object, void *data);





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
        ((void (*)())DAT_008873ec_abs[0])(puVar3[3]);
        puVar3[3] = 0;
      }
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
    }
    func_004808b0(*(u32 *)(iVar2 + 0x50));
    ((void (*)())DAT_008873ec_abs[0])(iVar2);
    iVar2 = iVar1;
  }
  ((void (*)())DAT_008873ec_abs[0])(param_1);
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



// FUN_0047FBF0
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
            if (*(u32 *)((u8 *)D_00713220 + i * 0x10 + 0xC) == 0) continue;
            if (*(u32 *)(node + i * 0x10 + 0xC) == 0) continue;
            init = (u8 *(*)(u8 *, f32))*(u32 *)((u8 *)D_00713220 + i * 0x10);
            work = init(node + i * 0x10, scale);
            entry = (u8 *)D_00713220 + i * 0x10;
            for (j = 0; j < count; j++) {
                apply = (void (*)(u8 *, u32))*(u32 *)(entry + 0xC);
                apply(work, *(u32 *)(*(u8 **)tbl + j * 4));
            }
        }
        node = *(u8 **)(node + 0x54);
    }
}


// FUN_0047FD10
void func_0047fd10(u8 **arg0, f32 scale1, u8 **arg1, f32 scale2, f32 scale3)
{
    u8 *node;
    u8 *match;
    u8 *tbl;
    u8 *entry;
    u32 i;
    u32 j;
    u8 *work;
    u32 count;
    u8 *(*init)(u8 *, f32, u8 *, f32);
    void (*apply)(u8 *, u32);

    node = *arg0;
    while (node != NULL) {
        match = func_0047fb50(arg1, (s32 *)*(u8 **)(node + 0x50));
        if (match != NULL) {
            func_0047f850(node, match, scale1, scale2, scale3);
        } else {
            tbl = *(u8 **)(node + 0x50);
            count = *(u16 *)(tbl + 4);
            for (i = 0; i < 4; i++) {
                if (*(u32 *)((u8 *)D_00713220 + i * 0x10 + 0xC) == 0) continue;
                if (*(u32 *)(node + i * 0x10 + 0xC) == 0) continue;
                init = (u8 *(*)(u8 *, f32, u8 *, f32))*(u32 *)((u8 *)D_00713220 + i * 0x10 + 8);
                work = init(node + i * 0x10, scale1, node + 0x40, scale3);
                entry = (u8 *)D_00713220 + i * 0x10;
                for (j = 0; j < count; j++) {
                    apply = (void (*)(u8 *, u32))*(u32 *)(entry + 0xC);
                    apply(work, *(u32 *)(*(u8 **)tbl + j * 4));
                }
            }
        }
        node = *(u8 **)(node + 0x54);
    }
}




// FUN_0047FE90
void func_0047fe90(u8 **arg0, f32 scale1, f32 scale2)
{
    u8 *node;
    u8 *tbl;
    u8 *entry;
    u32 i;
    u32 j;
    u8 *work;
    u32 count;
    u8 *(*init)(u8 *, f32, u8 *, f32);
    void (*apply)(u8 *, u32);

    node = *arg0;
    while (node != NULL) {
        tbl = *(u8 **)(node + 0x50);
        count = *(u16 *)(tbl + 4);
        for (i = 0; i < 4; i++) {
            if (*(u32 *)((u8 *)D_00713220 + i * 0x10 + 0xC) == 0) continue;
            if (*(u32 *)(node + i * 0x10 + 0xC) == 0) continue;
            init = (u8 *(*)(u8 *, f32, u8 *, f32))*(u32 *)((u8 *)D_00713220 + i * 0x10 + 8);
            work = init(node + i * 0x10, scale1, node + 0x40, scale2);
            entry = (u8 *)D_00713220 + i * 0x10;
            for (j = 0; j < count; j++) {
                apply = (void (*)(u8 *, u32))*(u32 *)(entry + 0xC);
                apply(work, *(u32 *)(*(u8 **)tbl + j * 4));
            }
        }
        node = *(u8 **)(node + 0x54);
    }
}


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



/* 864/864 bytes; 27 resolved relocations; no alignment tail.
 * Aggregate material copies and a separate search result preserve retail
 * scheduling. Reuse the counter to stage the name length before reading.
 * Both loader paths supply only material chunk tags 0xF0F00080..83. */
// FUN_004800D0
s32 func_004800d0(void *arg0, u8 **arg1, u32 arg2, void *arg3)
{
    typedef struct { u32 count; f32 duration; u32 stride; u32 nameLength; u32 unk10; } Hdr;
    typedef struct { u8 r, g, b, a; } MatColor;
    typedef struct { f32 ambient, specular, diffuse; } MatSurface;
    Hdr header;
    u32 search[2];
    u8 nameBuf[0x80];
    u8 *channel;
    u8 *name;
    s32 allocated;
    u8 *node;
    u8 *table;
    u32 i;
    u8 *entry;
    u8 *mat;
    u8 *tmp;
    extern u32 func_003e2910(void *a, void *b, u32 c);
    extern void *func_003e2ce0(void *a, u32 b);
    extern u16 func_00480800(void *a, u32 b);
    extern u8 *func_00480840(s32 a);
    extern void *func_00480630(void *a, void *b);
    extern u32 func_004808f0(s32 a);

    func_003e2910(arg0, &header, 0x14);
    if (header.nameLength < 0x80U) {
        name = nameBuf;
        allocated = 0;
    } else {
        func_0044ea90(D_00713260, 0x307);
        name = jtbl_008873E8[0](header.nameLength + 1, 0x40000);
        allocated = 1;
    }
    i = header.nameLength;
    func_003e2910(arg0, name, i);
    name[header.nameLength] = 0;
    search[0] = (u32)func_00480840(func_00480800(arg3, (u32)name) & 0xFFFFU);
    search[1] = (u32)name;
    func_00480630(arg3, search);
    if (allocated != 0) {
        DAT_008873ec_abs[0](name);
    }
    table = (u8 *)search[0];
    for (tmp = *arg1; tmp != NULL; tmp = *(u8 **)(tmp + 0x54)) {
        if (*(u8 **)(tmp + 0x50) == table) {
            node = tmp;
            goto found;
        }
    }
    node = NULL;
found:
    if (node == NULL) {
        func_0044ea90(D_00713260, 0x19C);
        node = jtbl_008873E8[0](0x58, 0x40000);
        func_0043f9c8(node, 0, 0x58);
        i = 0;
        goto looptest2;
loop2:
        tmp = node + (i * 0x10);
        *(u32 *)(tmp + 0) = 0;
        *(u32 *)(tmp + 4) = 0;
        *(u32 *)(tmp + 8) = 0;
        *(u32 *)(tmp + 0xC) = 0;
        i += 1;
looptest2:
        if (i < 4U) {
            goto loop2;
        }
        *(u8 **)(node + 0x54) = NULL;
        entry = (u8 *)func_004808f0((s32)table);
        *(u8 **)(node + 0x50) = entry;
        mat = *(u8 **)entry;
        mat = *(u8 **)mat;
        *(MatColor *)(node + 0x40) = *(MatColor *)(mat + 4);
        *(MatSurface *)(node + 0x44) = *(MatSurface *)(mat + 0xC);
        tmp = *arg1;
        if (tmp == NULL) {
            *(u8 **)(node + 0x54) = NULL;
            *arg1 = node;
        } else {
            *(u8 **)(node + 0x54) = tmp;
            *arg1 = node;
        }
    }
    func_004808b0((s32)search[0]);
    switch (arg2) {
    case 0xF0F00080:
        channel = node;
        break;
    case 0xF0F00081:
        channel = node + 0x10;
        break;
    case 0xF0F00082:
        channel = node + 0x20;
        break;
    case 0xF0F00083:
        channel = node + 0x30;
        break;
    }
    {
        u32 dataSize = header.count * header.stride;
        if (*(u8 **)(channel + 0xC) == NULL) {
            *(u32 *)channel = header.count;
            *(f32 *)(channel + 4) = header.duration;
            *(u32 *)(channel + 8) = header.stride;
            func_0044ea90(D_00713260, 0x349);
            *(u8 **)(channel + 0xC) = jtbl_008873E8[0](dataSize, 0x40000);
            func_003e2910(arg0, *(u8 **)(channel + 0xC), dataSize);
        } else {
            func_003e2ce0(arg0, dataSize);
        }
    }
    return 1;
}



// FUN_00480430
void *func_00480430(void *param_1, void *context)
{
  u32 *param_2 = context;
  s32 arrayCount;
  s32 dataCount;
  s32 arrayIndex;
  s32 dataIndex;
  RpUserDataArray *userData;
  char *name;
  char *data;

  arrayCount = func_003bcfb0(param_1);

  arrayIndex = 0;
  while (arrayIndex < arrayCount) {
    userData = func_003bd000(param_1,arrayIndex);
    name = func_003bd040(userData);
    if (strcmp(name,(char *)&DAT_007641e0) == 0) {
      dataCount = func_003bd060(userData);
      dataIndex = 0;
      while (dataIndex < dataCount) {
        if (func_003bd050(userData) == 3) {
          data = (char *)func_003bd0b0((u8 *)userData,dataIndex);
          if (strcmp((char *)param_2[1],data) == 0) {
            func_00480910((int *)*param_2,(u32)param_1);
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
void *func_00480580(void *param_1, void *param_2)
{
  u8 *iVar1;
  int iVar2;
  void *lVar3;
  int iVar4;

  iVar1 = *(u8 **)((u8 *)param_1 + 0x18);
  iVar2 = *(int *)(iVar1 + 0x24);
  iVar4 = 0;
  goto check;
loop:
  lVar3 = func_00480430((void *)(*(u32 *)(*(u8 **)(iVar1 + 0x20) + iVar4 * 4)),param_2);
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
void *func_00480630(void *param_1, void *param_2)
{
  func_003bff30(param_1,func_00480580,param_2);
  return param_1;
}





// FUN_00480670
void *func_00480670(void *arg0, void *arg1)
{
    s32 spB0;
    s32 spA0;
    RpMaterial *temp_21;
    RpUserDataArray *temp_2;
    s32 temp_30;
    s32 i;
    s32 j;
    s32 k;
    u8 *list;

    list = *(u8 **)((u8 *)arg0 + 0x18);
    temp_30 = *(s32 *)(list + 0x24);
    i = 0;
    while (i < temp_30) {
        temp_21 = (RpMaterial *)*(u32 *)(*(u8 **)(list + 0x20) + i * 4);
        spB0 = func_003bcfb0(temp_21);
        j = 0;
        while (j < spB0) {
            temp_2 = func_003bd000(temp_21, j);
            if (strcmp((char *)func_003bd040(temp_2), (char *)&DAT_007641e0) == 0) {
                spA0 = func_003bd060(temp_2);
                k = 0;
                while (k < spA0) {
                    if (func_003bd050(temp_2) == 3 &&
                        strcmp((char *)*(u32 *)arg1,
                               (char *)func_003bd0b0((u8 *)temp_2, k)) == 0) {
                        *(u16 *)((u8 *)arg1 + 4) = *(u16 *)((u8 *)arg1 + 4) + 1;
                        break;
                    } else {
                        k++;
                    }
                }
            }
            j++;
        }
        i++;
    }
    return arg0;
}

// FUN_00480800
u16 func_00480800(void *param_1,u32 param_2)
{
  struct {
    u32 input;
    u16 output;
  } stack;

  stack.input = param_2;
  stack.output = 0;
  func_003bff30(param_1,func_00480670,&stack);
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
