.section .text
.set noat
.set noreorder
glabel func_004d0e40
    /* 3D0E40 004D0E40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D0E44 004D0E44 7200023C */  lui        $2, %hi(D_00721D78)
    /* 3D0E48 004D0E48 0000BFFF */  sd         $31, 0x0($29)
    /* 3D0E4C 004D0E4C 781D4224 */  addiu      $2, $2, %lo(D_00721D78)
    /* 3D0E50 004D0E50 0000438C */  lw         $3, 0x0($2)
    /* 3D0E54 004D0E54 FFFF6324 */  addiu      $3, $3, -0x1
    /* 3D0E58 004D0E58 000043AC */  sw         $3, 0x0($2)
    /* 3D0E5C 004D0E5C 0000448C */  lw         $4, 0x0($2)
    /* 3D0E60 004D0E60 0B008014 */  bnez       $4, .L004D0E90
    /* 3D0E64 004D0E64 0000BFDF */   ld        $31, 0x0($29)
    /* 3D0E68 004D0E68 383C130C */  jal        func_004cf0e0
    /* 3D0E6C 004D0E6C 00000000 */   nop
    /* 3D0E70 004D0E70 7200043C */  lui        $4, %hi(D_00721D88)
    /* 3D0E74 004D0E74 0000BFDF */  ld         $31, 0x0($29)
    /* 3D0E78 004D0E78 881D8424 */  addiu      $4, $4, %lo(D_00721D88)
    /* 3D0E7C 004D0E7C 2D280000 */  daddu      $5, $0, $0
    /* 3D0E80 004D0E80 C0170624 */  addiu      $6, $0, 0x17C0
    /* 3D0E84 004D0E84 72FE1008 */  j          func_0043f9c8
    /* 3D0E88 004D0E88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D0E8C 004D0E8C 00000000 */  nop
  .L004D0E90:
    /* 3D0E90 004D0E90 0800E003 */  jr         $31
    /* 3D0E94 004D0E94 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d0e40, 0x58
