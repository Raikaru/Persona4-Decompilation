.section .text
.set noat
.set noreorder
glabel func_003be9f0
    /* 2BE9F0 003BE9F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BE9F4 003BE9F4 1000BFFF */  sd         $31, 0x10($29)
    /* 2BE9F8 003BE9F8 0000B07F */  sq         $16, 0x0($29)
    /* 2BE9FC 003BE9FC 2D808000 */  daddu      $16, $4, $0
    /* 2BEA00 003BEA00 6C00848C */  lw         $4, 0x6C($4)
    /* 2BEA04 003BEA04 08008010 */  beqz       $4, .L003BEA28
    /* 2BEA08 003BEA08 00000000 */   nop
  .L003BEA0C:
    /* 2BEA0C 003BEA0C 2D280002 */  daddu      $5, $16, $0
    /* 2BEA10 003BEA10 3445100C */  jal        func_004114d0
    /* 2BEA14 003BEA14 01000624 */   addiu     $6, $0, 0x1
    /* 2BEA18 003BEA18 09004010 */  beqz       $2, .L003BEA40
    /* 2BEA1C 003BEA1C 00000000 */   nop
    /* 2BEA20 003BEA20 08000010 */  b          .L003BEA44
    /* 2BEA24 003BEA24 2D100002 */   daddu     $2, $16, $0
  .L003BEA28:
    /* 2BEA28 003BEA28 B8B9838F */  lw         $3, -0x4648($28)
    /* 2BEA2C 003BEA2C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2BEA30 003BEA30 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2BEA34 003BEA34 21104300 */  addu       $2, $2, $3
    /* 2BEA38 003BEA38 F4FF0010 */  b          .L003BEA0C
    /* 2BEA3C 003BEA3C 3C00448C */   lw        $4, 0x3C($2)
  .L003BEA40:
    /* 2BEA40 003BEA40 2D100000 */  daddu      $2, $0, $0
  .L003BEA44:
    /* 2BEA44 003BEA44 1000BFDF */  ld         $31, 0x10($29)
    /* 2BEA48 003BEA48 0000B07B */  lq         $16, 0x0($29)
    /* 2BEA4C 003BEA4C 0800E003 */  jr         $31
    /* 2BEA50 003BEA50 2000BD27 */   addiu     $29, $29, 0x20
    /* 2BEA54 003BEA54 00000000 */  nop
    /* 2BEA58 003BEA58 00000000 */  nop
    /* 2BEA5C 003BEA5C 00000000 */  nop
.size func_003be9f0, 0x70
