.section .text
.set noat
.set noreorder
glabel func_003cad90
    /* 2CAD90 003CAD90 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2CAD94 003CAD94 5000BFFF */  sd         $31, 0x50($29)
    /* 2CAD98 003CAD98 4000B47F */  sq         $20, 0x40($29)
    /* 2CAD9C 003CAD9C 3000B37F */  sq         $19, 0x30($29)
    /* 2CADA0 003CADA0 2DA08000 */  daddu      $20, $4, $0
    /* 2CADA4 003CADA4 2000B27F */  sq         $18, 0x20($29)
    /* 2CADA8 003CADA8 1000B17F */  sq         $17, 0x10($29)
    /* 2CADAC 003CADAC 0000B07F */  sq         $16, 0x0($29)
    /* 2CADB0 003CADB0 64009126 */  addiu      $17, $20, 0x64
    /* 2CADB4 003CADB4 0CB7828F */  lw         $2, -0x48F4($28)
    /* 2CADB8 003CADB8 6400938C */  lw         $19, 0x64($4)
    /* 2CADBC 003CADBC 20007112 */  beq        $19, $17, .L003CAE40
    /* 2CADC0 003CADC0 21908202 */   addu      $18, $20, $2
    /* 2CADC4 003CADC4 8800103C */  lui        $16, %hi(jtbl_008873FC)
    /* 2CADC8 003CADC8 FC731026 */  addiu      $16, $16, %lo(jtbl_008873FC)
  .L003CADCC:
    /* 2CADCC 003CADCC F4FF6526 */  addiu      $5, $19, -0xC
    /* 2CADD0 003CADD0 0800A28C */  lw         $2, 0x8($5)
    /* 2CADD4 003CADD4 18004010 */  beqz       $2, .L003CAE38
    /* 2CADD8 003CADD8 0000738E */   lw        $19, 0x0($19)
    /* 2CADDC 003CADDC 1400A28C */  lw         $2, 0x14($5)
    /* 2CADE0 003CADE0 15004010 */  beqz       $2, .L003CAE38
    /* 2CADE4 003CADE4 00000000 */   nop
    /* 2CADE8 003CADE8 0C00A48C */  lw         $4, 0xC($5)
    /* 2CADEC 003CADEC 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CADF0 003CADF0 1000A28C */  lw         $2, 0x10($5)
    /* 2CADF4 003CADF4 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CADF8 003CADF8 000044AC */  sw         $4, 0x0($2)
    /* 2CADFC 003CADFC 1000A48C */  lw         $4, 0x10($5)
    /* 2CAE00 003CAE00 0C00A28C */  lw         $2, 0xC($5)
    /* 2CAE04 003CAE04 040044AC */  sw         $4, 0x4($2)
    /* 2CAE08 003CAE08 0000A48C */  lw         $4, 0x0($5)
    /* 2CAE0C 003CAE0C 0400A28C */  lw         $2, 0x4($5)
    /* 2CAE10 003CAE10 000044AC */  sw         $4, 0x0($2)
    /* 2CAE14 003CAE14 0400A48C */  lw         $4, 0x4($5)
    /* 2CAE18 003CAE18 0000A28C */  lw         $2, 0x0($5)
    /* 2CAE1C 003CAE1C 040044AC */  sw         $4, 0x4($2)
    /* 2CAE20 003CAE20 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CAE24 003CAE24 0000028E */  lw         $2, 0x0($16)
    /* 2CAE28 003CAE28 21186400 */  addu       $3, $3, $4
    /* 2CAE2C 003CAE2C 09F84000 */  jalr       $2
    /* 2CAE30 003CAE30 0000648C */   lw        $4, 0x0($3)
    /* 2CAE34 003CAE34 00000000 */  nop
  .L003CAE38:
    /* 2CAE38 003CAE38 E4FF7116 */  bne        $19, $17, .L003CADCC
    /* 2CAE3C 003CAE3C 00000000 */   nop
  .L003CAE40:
    /* 2CAE40 003CAE40 0400438E */  lw         $3, 0x4($18)
    /* 2CAE44 003CAE44 2D108002 */  daddu      $2, $20, $0
    /* 2CAE48 003CAE48 100083AE */  sw         $3, 0x10($20)
    /* 2CAE4C 003CAE4C 5000BFDF */  ld         $31, 0x50($29)
    /* 2CAE50 003CAE50 4000B47B */  lq         $20, 0x40($29)
    /* 2CAE54 003CAE54 3000B37B */  lq         $19, 0x30($29)
    /* 2CAE58 003CAE58 2000B27B */  lq         $18, 0x20($29)
    /* 2CAE5C 003CAE5C 1000B17B */  lq         $17, 0x10($29)
    /* 2CAE60 003CAE60 0000B07B */  lq         $16, 0x0($29)
    /* 2CAE64 003CAE64 0800E003 */  jr         $31
    /* 2CAE68 003CAE68 6000BD27 */   addiu     $29, $29, 0x60
    /* 2CAE6C 003CAE6C 00000000 */  nop
.size func_003cad90, 0xe0
