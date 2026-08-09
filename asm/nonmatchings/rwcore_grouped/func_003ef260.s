.section .text
.set noat
.set noreorder
glabel func_003ef260
    /* 2EF260 003EF260 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2EF264 003EF264 0800828C */  lw         $2, 0x8($4)
    /* 2EF268 003EF268 5000BFFF */  sd         $31, 0x50($29)
    /* 2EF26C 003EF26C 4000B47F */  sq         $20, 0x40($29)
    /* 2EF270 003EF270 3000B37F */  sq         $19, 0x30($29)
    /* 2EF274 003EF274 2DA08000 */  daddu      $20, $4, $0
    /* 2EF278 003EF278 2000B27F */  sq         $18, 0x20($29)
    /* 2EF27C 003EF27C 2D98A000 */  daddu      $19, $5, $0
    /* 2EF280 003EF280 1000B17F */  sq         $17, 0x10($29)
    /* 2EF284 003EF284 2D90C000 */  daddu      $18, $6, $0
    /* 2EF288 003EF288 08009126 */  addiu      $17, $20, 0x8
    /* 2EF28C 003EF28C 0A005110 */  beq        $2, $17, .L003EF2B8
    /* 2EF290 003EF290 0000B07F */   sq        $16, 0x0($29)
  .L003EF294:
    /* 2EF294 003EF294 0000508C */  lw         $16, 0x0($2)
    /* 2EF298 003EF298 F8FF4424 */  addiu      $4, $2, -0x8
    /* 2EF29C 003EF29C 09F86002 */  jalr       $19
    /* 2EF2A0 003EF2A0 2D284002 */   daddu     $5, $18, $0
    /* 2EF2A4 003EF2A4 04004010 */  beqz       $2, .L003EF2B8
    /* 2EF2A8 003EF2A8 00000000 */   nop
    /* 2EF2AC 003EF2AC F9FF1116 */  bne        $16, $17, .L003EF294
    /* 2EF2B0 003EF2B0 2D100002 */   daddu     $2, $16, $0
    /* 2EF2B4 003EF2B4 00000000 */  nop
  .L003EF2B8:
    /* 2EF2B8 003EF2B8 2D108002 */  daddu      $2, $20, $0
    /* 2EF2BC 003EF2BC 5000BFDF */  ld         $31, 0x50($29)
    /* 2EF2C0 003EF2C0 4000B47B */  lq         $20, 0x40($29)
    /* 2EF2C4 003EF2C4 3000B37B */  lq         $19, 0x30($29)
    /* 2EF2C8 003EF2C8 2000B27B */  lq         $18, 0x20($29)
    /* 2EF2CC 003EF2CC 1000B17B */  lq         $17, 0x10($29)
    /* 2EF2D0 003EF2D0 0000B07B */  lq         $16, 0x0($29)
    /* 2EF2D4 003EF2D4 0800E003 */  jr         $31
    /* 2EF2D8 003EF2D8 6000BD27 */   addiu     $29, $29, 0x60
    /* 2EF2DC 003EF2DC 00000000 */  nop
.size func_003ef260, 0x80
