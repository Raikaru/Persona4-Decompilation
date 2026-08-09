.section .text
.set noat
.set noreorder
glabel func_0052baf0
    /* 42BAF0 0052BAF0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 42BAF4 0052BAF4 2D408000 */  daddu      $8, $4, $0
    /* 42BAF8 0052BAF8 2800B1FF */  sd         $17, 0x28($29)
    /* 42BAFC 0052BAFC 14001125 */  addiu      $17, $8, 0x14
    /* 42BB00 0052BB00 2000B0FF */  sd         $16, 0x20($29)
    /* 42BB04 0052BB04 2D10A000 */  daddu      $2, $5, $0
    /* 42BB08 0052BB08 3000BFFF */  sd         $31, 0x30($29)
    /* 42BB0C 0052BB0C 2D18C000 */  daddu      $3, $6, $0
    /* 42BB10 0052BB10 040022AE */  sw         $2, 0x4($17)
    /* 42BB14 0052BB14 7600053C */  lui        $5, %hi(D_00760E30)
    /* 42BB18 0052BB18 080023AE */  sw         $3, 0x8($17)
    /* 42BB1C 0052BB1C 7600063C */  lui        $6, %hi(D_00760E38)
    /* 42BB20 0052BB20 2D20A003 */  daddu      $4, $29, $0
    /* 42BB24 0052BB24 300EA524 */  addiu      $5, $5, %lo(D_00760E30)
    /* 42BB28 0052BB28 380EC624 */  addiu      $6, $6, %lo(D_00760E38)
    /* 42BB2C 0052BB2C 2400108D */  lw         $16, 0x24($8)
    /* 42BB30 0052BB30 1000A727 */  addiu      $7, $29, 0x10
    /* 42BB34 0052BB34 0000A2AF */  sw         $2, 0x0($29)
    /* 42BB38 0052BB38 BEBE130C */  jal        func_004efaf8
    /* 42BB3C 0052BB3C 0400A3AF */   sw        $3, 0x4($29)
    /* 42BB40 0052BB40 2D280000 */  daddu      $5, $0, $0
    /* 42BB44 0052BB44 2D300000 */  daddu      $6, $0, $0
    /* 42BB48 0052BB48 05004014 */  bnez       $2, .L0052BB60
    /* 42BB4C 0052BB4C 2D200002 */   daddu     $4, $16, $0
    /* 42BB50 0052BB50 10B0140C */  jal        func_0052c040
    /* 42BB54 0052BB54 00000000 */   nop
    /* 42BB58 0052BB58 05000010 */  b          .L0052BB70
    /* 42BB5C 0052BB5C 01000224 */   addiu     $2, $0, 0x1
  .L0052BB60:
    /* 42BB60 0052BB60 1000A58F */  lw         $5, 0x10($29)
    /* 42BB64 0052BB64 10B0140C */  jal        func_0052c040
    /* 42BB68 0052BB68 1400A68F */   lw        $6, 0x14($29)
    /* 42BB6C 0052BB6C 01000224 */  addiu      $2, $0, 0x1
  .L0052BB70:
    /* 42BB70 0052BB70 2000B0DF */  ld         $16, 0x20($29)
    /* 42BB74 0052BB74 000022AE */  sw         $2, 0x0($17)
    /* 42BB78 0052BB78 3000BFDF */  ld         $31, 0x30($29)
    /* 42BB7C 0052BB7C 2800B1DF */  ld         $17, 0x28($29)
    /* 42BB80 0052BB80 0800E003 */  jr         $31
    /* 42BB84 0052BB84 4000BD27 */   addiu     $29, $29, 0x40
.size func_0052baf0, 0x98
