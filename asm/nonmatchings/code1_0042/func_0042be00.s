.section .text
.set noat
.set noreorder
glabel func_0042be00
    /* 32BE00 0042BE00 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 32BE04 0042BE04 3000BFFF */  sd         $31, 0x30($29)
    /* 32BE08 0042BE08 2000B2FF */  sd         $18, 0x20($29)
    /* 32BE0C 0042BE0C 1000B1FF */  sd         $17, 0x10($29)
    /* 32BE10 0042BE10 66AF100C */  jal        func_0042bd98
    /* 32BE14 0042BE14 0000B0FF */   sd        $16, 0x0($29)
    /* 32BE18 0042BE18 1E004010 */  beqz       $2, .L0042BE94
    /* 32BE1C 0042BE1C 7100023C */   lui       $2, %hi(D_0070D4C0)
    /* 32BE20 0042BE20 02001224 */  addiu      $18, $0, 0x2
    /* 32BE24 0042BE24 C0D45024 */  addiu      $16, $2, %lo(D_0070D4C0)
    /* 32BE28 0042BE28 C0D4448C */  lw         $4, %lo(D_0070D4C0)($2)
    /* 32BE2C 0042BE2C 0400058E */  lw         $5, 0x4($16)
    /* 32BE30 0042BE30 4CAF100C */  jal        func_0042bd30
    /* 32BE34 0042BE34 10001126 */   addiu     $17, $16, 0x10
    /* 32BE38 0042BE38 7100053C */  lui        $5, %hi(D_0070CD18)
    /* 32BE3C 0042BE3C 0780043C */  lui        $4, (0x80074000 >> 16)
    /* 32BE40 0042BE40 A8070624 */  addiu      $6, $0, 0x7A8
    /* 32BE44 0042BE44 18CDA524 */  addiu      $5, $5, %lo(D_0070CD18)
    /* 32BE48 0042BE48 50AF100C */  jal        func_0042bd40
    /* 32BE4C 0042BE4C 00408434 */   ori       $4, $4, (0x80074000 & 0xFFFF)
    /* 32BE50 0042BE50 9886100C */  jal        func_00421a60
    /* 32BE54 0042BE54 2D200000 */   daddu     $4, $0, $0
    /* 32BE58 0042BE58 9886100C */  jal        func_00421a60
    /* 32BE5C 0042BE5C 02000424 */   addiu     $4, $0, 0x2
    /* 32BE60 0042BE60 0800048E */  lw         $4, 0x8($16)
    /* 32BE64 0042BE64 4CAF100C */  jal        func_0042bd30
    /* 32BE68 0042BE68 0C00058E */   lw        $5, 0xC($16)
    /* 32BE6C 0042BE6C 0000248E */  lw         $4, 0x0($17)
  .L0042BE70:
    /* 32BE70 0042BE70 62AF100C */  jal        func_0042bd88
    /* 32BE74 0042BE74 01005226 */   addiu     $18, $18, 0x1
    /* 32BE78 0042BE78 0000248E */  lw         $4, 0x0($17)
    /* 32BE7C 0042BE7C 2D284000 */  daddu      $5, $2, $0
    /* 32BE80 0042BE80 4CAF100C */  jal        func_0042bd30
    /* 32BE84 0042BE84 08003126 */   addiu     $17, $17, 0x8
    /* 32BE88 0042BE88 0300422E */  sltiu      $2, $18, 0x3
    /* 32BE8C 0042BE8C F8FF4054 */  bnel       $2, $0, .L0042BE70
    /* 32BE90 0042BE90 0000248E */   lw        $4, 0x0($17)
  .L0042BE94:
    /* 32BE94 0042BE94 3000BFDF */  ld         $31, 0x30($29)
    /* 32BE98 0042BE98 2000B2DF */  ld         $18, 0x20($29)
    /* 32BE9C 0042BE9C 1000B1DF */  ld         $17, 0x10($29)
    /* 32BEA0 0042BEA0 0000B0DF */  ld         $16, 0x0($29)
    /* 32BEA4 0042BEA4 0800E003 */  jr         $31
    /* 32BEA8 0042BEA8 4000BD27 */   addiu     $29, $29, 0x40
    /* 32BEAC 0042BEAC 00000000 */  nop
.size func_0042be00, 0xb0
