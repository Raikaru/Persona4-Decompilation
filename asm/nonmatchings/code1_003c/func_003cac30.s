.section .text
.set noat
.set noreorder
glabel func_003cac30
    /* 2CAC30 003CAC30 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2CAC34 003CAC34 5000BFFF */  sd         $31, 0x50($29)
    /* 2CAC38 003CAC38 4000B47F */  sq         $20, 0x40($29)
    /* 2CAC3C 003CAC3C 3000B37F */  sq         $19, 0x30($29)
    /* 2CAC40 003CAC40 2DA08000 */  daddu      $20, $4, $0
    /* 2CAC44 003CAC44 2000B27F */  sq         $18, 0x20($29)
    /* 2CAC48 003CAC48 1000B17F */  sq         $17, 0x10($29)
    /* 2CAC4C 003CAC4C 0000B07F */  sq         $16, 0x0($29)
    /* 2CAC50 003CAC50 0CB7828F */  lw         $2, -0x48F4($28)
    /* 2CAC54 003CAC54 21808202 */  addu       $16, $20, $2
    /* 2CAC58 003CAC58 0400028E */  lw         $2, 0x4($16)
    /* 2CAC5C 003CAC5C 09F84000 */  jalr       $2
    /* 2CAC60 003CAC60 00000000 */   nop
    /* 2CAC64 003CAC64 2B004010 */  beqz       $2, .L003CAD14
    /* 2CAC68 003CAC68 00000000 */   nop
    /* 2CAC6C 003CAC6C 0000138E */  lw         $19, 0x0($16)
    /* 2CAC70 003CAC70 26006012 */  beqz       $19, .L003CAD0C
    /* 2CAC74 003CAC74 00000000 */   nop
    /* 2CAC78 003CAC78 6400928E */  lw         $18, 0x64($20)
    /* 2CAC7C 003CAC7C 64009126 */  addiu      $17, $20, 0x64
    /* 2CAC80 003CAC80 1F005112 */  beq        $18, $17, .L003CAD00
    /* 2CAC84 003CAC84 00000000 */   nop
    /* 2CAC88 003CAC88 8800103C */  lui        $16, %hi(jtbl_008873FC)
    /* 2CAC8C 003CAC8C FC731026 */  addiu      $16, $16, %lo(jtbl_008873FC)
  .L003CAC90:
    /* 2CAC90 003CAC90 F4FF4526 */  addiu      $5, $18, -0xC
    /* 2CAC94 003CAC94 0800A28C */  lw         $2, 0x8($5)
    /* 2CAC98 003CAC98 17004010 */  beqz       $2, .L003CACF8
    /* 2CAC9C 003CAC9C 0000528E */   lw        $18, 0x0($18)
    /* 2CACA0 003CACA0 1400A28C */  lw         $2, 0x14($5)
    /* 2CACA4 003CACA4 14004010 */  beqz       $2, .L003CACF8
    /* 2CACA8 003CACA8 00000000 */   nop
    /* 2CACAC 003CACAC 0C00A48C */  lw         $4, 0xC($5)
    /* 2CACB0 003CACB0 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CACB4 003CACB4 1000A28C */  lw         $2, 0x10($5)
    /* 2CACB8 003CACB8 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CACBC 003CACBC 000044AC */  sw         $4, 0x0($2)
    /* 2CACC0 003CACC0 1000A48C */  lw         $4, 0x10($5)
    /* 2CACC4 003CACC4 0C00A28C */  lw         $2, 0xC($5)
    /* 2CACC8 003CACC8 040044AC */  sw         $4, 0x4($2)
    /* 2CACCC 003CACCC 0000A48C */  lw         $4, 0x0($5)
    /* 2CACD0 003CACD0 0400A28C */  lw         $2, 0x4($5)
    /* 2CACD4 003CACD4 000044AC */  sw         $4, 0x0($2)
    /* 2CACD8 003CACD8 0400A48C */  lw         $4, 0x4($5)
    /* 2CACDC 003CACDC 0000A28C */  lw         $2, 0x0($5)
    /* 2CACE0 003CACE0 040044AC */  sw         $4, 0x4($2)
    /* 2CACE4 003CACE4 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CACE8 003CACE8 0000028E */  lw         $2, 0x0($16)
    /* 2CACEC 003CACEC 21186400 */  addu       $3, $3, $4
    /* 2CACF0 003CACF0 09F84000 */  jalr       $2
    /* 2CACF4 003CACF4 0000648C */   lw        $4, 0x0($3)
  .L003CACF8:
    /* 2CACF8 003CACF8 E5FF5116 */  bne        $18, $17, .L003CAC90
    /* 2CACFC 003CACFC 00000000 */   nop
  .L003CAD00:
    /* 2CAD00 003CAD00 2D206002 */  daddu      $4, $19, $0
    /* 2CAD04 003CAD04 942A0F0C */  jal        func_003caa50
    /* 2CAD08 003CAD08 2D288002 */   daddu     $5, $20, $0
  .L003CAD0C:
    /* 2CAD0C 003CAD0C 02000010 */  b          .L003CAD18
    /* 2CAD10 003CAD10 2D108002 */   daddu     $2, $20, $0
  .L003CAD14:
    /* 2CAD14 003CAD14 2D100000 */  daddu      $2, $0, $0
  .L003CAD18:
    /* 2CAD18 003CAD18 5000BFDF */  ld         $31, 0x50($29)
    /* 2CAD1C 003CAD1C 4000B47B */  lq         $20, 0x40($29)
    /* 2CAD20 003CAD20 3000B37B */  lq         $19, 0x30($29)
    /* 2CAD24 003CAD24 2000B27B */  lq         $18, 0x20($29)
    /* 2CAD28 003CAD28 1000B17B */  lq         $17, 0x10($29)
    /* 2CAD2C 003CAD2C 0000B07B */  lq         $16, 0x0($29)
    /* 2CAD30 003CAD30 0800E003 */  jr         $31
    /* 2CAD34 003CAD34 6000BD27 */   addiu     $29, $29, 0x60
    /* 2CAD38 003CAD38 00000000 */  nop
    /* 2CAD3C 003CAD3C 00000000 */  nop
.size func_003cac30, 0x110
