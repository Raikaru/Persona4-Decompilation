.section .text
.set noat
.set noreorder
glabel func_0027b9e0
    /* 17B9E0 0027B9E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17B9E4 0027B9E4 1000BFFF */  sd         $31, 0x10($29)
    /* 17B9E8 0027B9E8 0000B07F */  sq         $16, 0x0($29)
    /* 17B9EC 0027B9EC 2D808000 */  daddu      $16, $4, $0
    /* 17B9F0 0027B9F0 10DE090C */  jal        func_00277840
    /* 17B9F4 0027B9F4 00000000 */   nop
    /* 17B9F8 0027B9F8 2D200002 */  daddu      $4, $16, $0
    /* 17B9FC 0027B9FC 10DE090C */  jal        func_00277840
    /* 17BA00 0027BA00 00000000 */   nop
    /* 17BA04 0027BA04 0000428C */  lw         $2, 0x0($2)
    /* 17BA08 0027BA08 07004010 */  beqz       $2, .L0027BA28
    /* 17BA0C 0027BA0C 00000000 */   nop
    /* 17BA10 0027BA10 2D200002 */  daddu      $4, $16, $0
    /* 17BA14 0027BA14 05000524 */  addiu      $5, $0, 0x5
    /* 17BA18 0027BA18 09F84000 */  jalr       $2
    /* 17BA1C 0027BA1C 00000000 */   nop
    /* 17BA20 0027BA20 02000010 */  b          .L0027BA2C
    /* 17BA24 0027BA24 00000000 */   nop
  .L0027BA28:
    /* 17BA28 0027BA28 01000224 */  addiu      $2, $0, 0x1
  .L0027BA2C:
    /* 17BA2C 0027BA2C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BA30 0027BA30 0000B07B */  lq         $16, 0x0($29)
    /* 17BA34 0027BA34 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BA38 0027BA38 0800E003 */  jr         $31
    /* 17BA3C 0027BA3C 00000000 */   nop
.size func_0027b9e0, 0x60
