.section .text
.set noat
.set noreorder
glabel func_0027bd40
    /* 17BD40 0027BD40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BD44 0027BD44 1000BFFF */  sd         $31, 0x10($29)
    /* 17BD48 0027BD48 0000B07F */  sq         $16, 0x0($29)
    /* 17BD4C 0027BD4C 2D808000 */  daddu      $16, $4, $0
    /* 17BD50 0027BD50 10DE090C */  jal        func_00277840
    /* 17BD54 0027BD54 00000000 */   nop
    /* 17BD58 0027BD58 2D200002 */  daddu      $4, $16, $0
    /* 17BD5C 0027BD5C 10DE090C */  jal        func_00277840
    /* 17BD60 0027BD60 00000000 */   nop
    /* 17BD64 0027BD64 0000428C */  lw         $2, 0x0($2)
    /* 17BD68 0027BD68 07004010 */  beqz       $2, .L0027BD88
    /* 17BD6C 0027BD6C 00000000 */   nop
    /* 17BD70 0027BD70 2D200002 */  daddu      $4, $16, $0
    /* 17BD74 0027BD74 10000524 */  addiu      $5, $0, 0x10
    /* 17BD78 0027BD78 09F84000 */  jalr       $2
    /* 17BD7C 0027BD7C 00000000 */   nop
    /* 17BD80 0027BD80 02000010 */  b          .L0027BD8C
    /* 17BD84 0027BD84 00000000 */   nop
  .L0027BD88:
    /* 17BD88 0027BD88 01000224 */  addiu      $2, $0, 0x1
  .L0027BD8C:
    /* 17BD8C 0027BD8C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BD90 0027BD90 0000B07B */  lq         $16, 0x0($29)
    /* 17BD94 0027BD94 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BD98 0027BD98 0800E003 */  jr         $31
    /* 17BD9C 0027BD9C 00000000 */   nop
.size func_0027bd40, 0x60
