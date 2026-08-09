.section .text
.set noat
.set noreorder
glabel func_0027bb00
    /* 17BB00 0027BB00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BB04 0027BB04 1000BFFF */  sd         $31, 0x10($29)
    /* 17BB08 0027BB08 0000B07F */  sq         $16, 0x0($29)
    /* 17BB0C 0027BB0C 2D808000 */  daddu      $16, $4, $0
    /* 17BB10 0027BB10 10DE090C */  jal        func_00277840
    /* 17BB14 0027BB14 00000000 */   nop
    /* 17BB18 0027BB18 2D200002 */  daddu      $4, $16, $0
    /* 17BB1C 0027BB1C 10DE090C */  jal        func_00277840
    /* 17BB20 0027BB20 00000000 */   nop
    /* 17BB24 0027BB24 0000428C */  lw         $2, 0x0($2)
    /* 17BB28 0027BB28 07004010 */  beqz       $2, .L0027BB48
    /* 17BB2C 0027BB2C 00000000 */   nop
    /* 17BB30 0027BB30 2D200002 */  daddu      $4, $16, $0
    /* 17BB34 0027BB34 08000524 */  addiu      $5, $0, 0x8
    /* 17BB38 0027BB38 09F84000 */  jalr       $2
    /* 17BB3C 0027BB3C 00000000 */   nop
    /* 17BB40 0027BB40 02000010 */  b          .L0027BB4C
    /* 17BB44 0027BB44 00000000 */   nop
  .L0027BB48:
    /* 17BB48 0027BB48 01000224 */  addiu      $2, $0, 0x1
  .L0027BB4C:
    /* 17BB4C 0027BB4C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BB50 0027BB50 0000B07B */  lq         $16, 0x0($29)
    /* 17BB54 0027BB54 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BB58 0027BB58 0800E003 */  jr         $31
    /* 17BB5C 0027BB5C 00000000 */   nop
.size func_0027bb00, 0x60
