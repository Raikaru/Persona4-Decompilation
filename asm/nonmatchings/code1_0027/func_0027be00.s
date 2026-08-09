.section .text
.set noat
.set noreorder
glabel func_0027be00
    /* 17BE00 0027BE00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BE04 0027BE04 1000BFFF */  sd         $31, 0x10($29)
    /* 17BE08 0027BE08 0000B07F */  sq         $16, 0x0($29)
    /* 17BE0C 0027BE0C 2D808000 */  daddu      $16, $4, $0
    /* 17BE10 0027BE10 10DE090C */  jal        func_00277840
    /* 17BE14 0027BE14 00000000 */   nop
    /* 17BE18 0027BE18 2D200002 */  daddu      $4, $16, $0
    /* 17BE1C 0027BE1C 10DE090C */  jal        func_00277840
    /* 17BE20 0027BE20 00000000 */   nop
    /* 17BE24 0027BE24 0000428C */  lw         $2, 0x0($2)
    /* 17BE28 0027BE28 07004010 */  beqz       $2, .L0027BE48
    /* 17BE2C 0027BE2C 00000000 */   nop
    /* 17BE30 0027BE30 2D200002 */  daddu      $4, $16, $0
    /* 17BE34 0027BE34 12000524 */  addiu      $5, $0, 0x12
    /* 17BE38 0027BE38 09F84000 */  jalr       $2
    /* 17BE3C 0027BE3C 00000000 */   nop
    /* 17BE40 0027BE40 02000010 */  b          .L0027BE4C
    /* 17BE44 0027BE44 00000000 */   nop
  .L0027BE48:
    /* 17BE48 0027BE48 01000224 */  addiu      $2, $0, 0x1
  .L0027BE4C:
    /* 17BE4C 0027BE4C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BE50 0027BE50 0000B07B */  lq         $16, 0x0($29)
    /* 17BE54 0027BE54 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BE58 0027BE58 0800E003 */  jr         $31
    /* 17BE5C 0027BE5C 00000000 */   nop
.size func_0027be00, 0x60
