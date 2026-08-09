.section .text
.set noat
.set noreorder
glabel func_003d5e90
    /* 2D5E90 003D5E90 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2D5E94 003D5E94 5000BFFF */  sd         $31, 0x50($29)
    /* 2D5E98 003D5E98 4000B37F */  sq         $19, 0x40($29)
    /* 2D5E9C 003D5E9C 3000B27F */  sq         $18, 0x30($29)
    /* 2D5EA0 003D5EA0 2D988000 */  daddu      $19, $4, $0
    /* 2D5EA4 003D5EA4 2000B17F */  sq         $17, 0x20($29)
    /* 2D5EA8 003D5EA8 2D90A000 */  daddu      $18, $5, $0
    /* 2D5EAC 003D5EAC 1000B07F */  sq         $16, 0x10($29)
    /* 2D5EB0 003D5EB0 2D88C000 */  daddu      $17, $6, $0
    /* 2D5EB4 003D5EB4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2D5EB8 003D5EB8 2D800000 */  daddu      $16, $0, $0
    /* 2D5EBC 003D5EBC 2C00828C */  lw         $2, 0x2C($4)
    /* 2D5EC0 003D5EC0 2A100200 */  slt        $2, $0, $2
    /* 2D5EC4 003D5EC4 03004014 */  bnez       $2, .L003D5ED4
    /* 2D5EC8 003D5EC8 06650046 */   mov.s     $f20, $f12
  .L003D5ECC:
    /* 2D5ECC 003D5ECC 17000010 */  b          .L003D5F2C
    /* 2D5ED0 003D5ED0 01000224 */   addiu     $2, $0, 0x1
  .L003D5ED4:
    /* 2D5ED4 003D5ED4 2400628E */  lw         $2, 0x24($19)
    /* 2D5ED8 003D5ED8 18180202 */  mult       $3, $16, $2
    /* 2D5EDC 003D5EDC 2400428E */  lw         $2, 0x24($18)
    /* 2D5EE0 003D5EE0 21207300 */  addu       $4, $3, $19
    /* 2D5EE4 003D5EE4 18180272 */  mult1      $3, $16, $2
    /* 2D5EE8 003D5EE8 2400228E */  lw         $2, 0x24($17)
    /* 2D5EEC 003D5EEC 21287200 */  addu       $5, $3, $18
    /* 2D5EF0 003D5EF0 18180202 */  mult       $3, $16, $2
    /* 2D5EF4 003D5EF4 4C008424 */  addiu      $4, $4, 0x4C
    /* 2D5EF8 003D5EF8 4C00A524 */  addiu      $5, $5, 0x4C
    /* 2D5EFC 003D5EFC 06A30046 */  mov.s      $f12, $f20
    /* 2D5F00 003D5F00 4000628E */  lw         $2, 0x40($19)
    /* 2D5F04 003D5F04 21187100 */  addu       $3, $3, $17
    /* 2D5F08 003D5F08 09F84000 */  jalr       $2
    /* 2D5F0C 003D5F0C 4C006624 */   addiu     $6, $3, 0x4C
    /* 2D5F10 003D5F10 2C00628E */  lw         $2, 0x2C($19)
    /* 2D5F14 003D5F14 01001026 */  addiu      $16, $16, 0x1
    /* 2D5F18 003D5F18 2A100202 */  slt        $2, $16, $2
    /* 2D5F1C 003D5F1C EDFF4014 */  bnez       $2, .L003D5ED4
    /* 2D5F20 003D5F20 00000000 */   nop
    /* 2D5F24 003D5F24 E9FF0010 */  b          .L003D5ECC
    /* 2D5F28 003D5F28 00000000 */   nop
  .L003D5F2C:
    /* 2D5F2C 003D5F2C 5000BFDF */  ld         $31, 0x50($29)
    /* 2D5F30 003D5F30 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2D5F34 003D5F34 4000B37B */  lq         $19, 0x40($29)
    /* 2D5F38 003D5F38 3000B27B */  lq         $18, 0x30($29)
    /* 2D5F3C 003D5F3C 2000B17B */  lq         $17, 0x20($29)
    /* 2D5F40 003D5F40 1000B07B */  lq         $16, 0x10($29)
    /* 2D5F44 003D5F44 0800E003 */  jr         $31
    /* 2D5F48 003D5F48 6000BD27 */   addiu     $29, $29, 0x60
    /* 2D5F4C 003D5F4C 00000000 */  nop
.size func_003d5e90, 0xc0
