.section .text
.set noat
.set noreorder
glabel func_003bb330
    /* 2BB330 003BB330 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BB334 003BB334 0C00838C */  lw         $3, 0xC($4)
    /* 2BB338 003BB338 02000224 */  addiu      $2, $0, 0x2
    /* 2BB33C 003BB33C 09006210 */  beq        $3, $2, .L003BB364
    /* 2BB340 003BB340 0000BFFF */   sd        $31, 0x0($29)
    /* 2BB344 003BB344 01000224 */  addiu      $2, $0, 0x1
    /* 2BB348 003BB348 03006210 */  beq        $3, $2, .L003BB358
    /* 2BB34C 003BB34C 00000000 */   nop
    /* 2BB350 003BB350 07000010 */  b          .L003BB370
    /* 2BB354 003BB354 2D204000 */   daddu     $4, $2, $0
  .L003BB358:
    /* 2BB358 003BB358 0800828C */  lw         $2, 0x8($4)
    /* 2BB35C 003BB35C 0B000010 */  b          .L003BB38C
    /* 2BB360 003BB360 FEFF4224 */   addiu     $2, $2, -0x2
  .L003BB364:
    /* 2BB364 003BB364 0800828C */  lw         $2, 0x8($4)
    /* 2BB368 003BB368 08000010 */  b          .L003BB38C
    /* 2BB36C 003BB36C FDFF4224 */   addiu     $2, $2, -0x3
  .L003BB370:
    /* 2BB370 003BB370 02010224 */  addiu      $2, $0, 0x102
    /* 2BB374 003BB374 647D0F0C */  jal        func_003df590
    /* 2BB378 003BB378 1800A2AF */   sw        $2, 0x18($29)
    /* 2BB37C 003BB37C 1C00A2AF */  sw         $2, 0x1C($29)
    /* 2BB380 003BB380 347D0F0C */  jal        func_003df4d0
    /* 2BB384 003BB384 1800A427 */   addiu     $4, $29, 0x18
    /* 2BB388 003BB388 2D100000 */  daddu      $2, $0, $0
  .L003BB38C:
    /* 2BB38C 003BB38C 0000BFDF */  ld         $31, 0x0($29)
    /* 2BB390 003BB390 0800E003 */  jr         $31
    /* 2BB394 003BB394 2000BD27 */   addiu     $29, $29, 0x20
    /* 2BB398 003BB398 00000000 */  nop
    /* 2BB39C 003BB39C 00000000 */  nop
.size func_003bb330, 0x70
