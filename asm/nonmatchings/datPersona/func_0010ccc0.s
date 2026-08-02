.section .text
.set noat
.set noreorder
glabel func_0010ccc0
    /* CCC0 0010CCC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CCC4 0010CCC4 2000BFFF */  sd         $31, 0x20($29)
    /* CCC8 0010CCC8 1000B17F */  sq         $17, 0x10($29)
    /* CCCC 0010CCCC 0000B07F */  sq         $16, 0x0($29)
    /* CCD0 0010CCD0 2D808000 */  daddu      $16, $4, $0
    /* CCD4 0010CCD4 2D88A000 */  daddu      $17, $5, $0
    /* CCD8 0010CCD8 04000012 */  beqz       $16, .L0010CCEC
    /* CCDC 0010CCDC 00000000 */   nop
    /* CCE0 0010CCE0 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* CCE4 0010CCE4 06004014 */  bnez       $2, .L0010CD00
    /* CCE8 0010CCE8 00000000 */   nop
  .L0010CCEC:
    /* CCEC 0010CCEC 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CCF0 0010CCF0 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CCF4 0010CCF4 EE060524 */  addiu      $5, $0, 0x6EE
    /* CCF8 0010CCF8 CCB5110C */  jal        func_0046d730
    /* CCFC 0010CCFC 00000000 */   nop
  .L0010CD00:
    /* CD00 0010CD00 2D280000 */  daddu      $5, $0, $0
    /* CD04 0010CD04 FFFF2432 */  andi       $4, $17, 0xFFFF
    /* CD08 0010CD08 0F000010 */  b          .L0010CD48
    /* CD0C 0010CD0C 00000000 */   nop
  .L0010CD10:
    /* CD10 0010CD10 40100500 */  sll        $2, $5, 1
    /* CD14 0010CD14 21100202 */  addu       $2, $16, $2
    /* CD18 0010CD18 0C004324 */  addiu      $3, $2, 0xC
    /* CD1C 0010CD1C 0C004294 */  lhu        $2, 0xC($2)
    /* CD20 0010CD20 08004414 */  bne        $2, $4, .L0010CD44
    /* CD24 0010CD24 00000000 */   nop
    /* CD28 0010CD28 000060A4 */  sh         $0, 0x0($3)
    /* CD2C 0010CD2C 2D200002 */  daddu      $4, $16, $0
    /* CD30 0010CD30 7832040C */  jal        func_0010c9e0
    /* CD34 0010CD34 00000000 */   nop
    /* CD38 0010CD38 01000224 */  addiu      $2, $0, 0x1
    /* CD3C 0010CD3C 06000010 */  b          .L0010CD58
    /* CD40 0010CD40 00000000 */   nop
  .L0010CD44:
    /* CD44 0010CD44 0100A524 */  addiu      $5, $5, 0x1
  .L0010CD48:
    /* CD48 0010CD48 0800A228 */  slti       $2, $5, 0x8
    /* CD4C 0010CD4C F0FF4014 */  bnez       $2, .L0010CD10
    /* CD50 0010CD50 00000000 */   nop
    /* CD54 0010CD54 2D100000 */  daddu      $2, $0, $0
  .L0010CD58:
    /* CD58 0010CD58 2000BFDF */  ld         $31, 0x20($29)
    /* CD5C 0010CD5C 1000B17B */  lq         $17, 0x10($29)
    /* CD60 0010CD60 0000B07B */  lq         $16, 0x0($29)
    /* CD64 0010CD64 3000BD27 */  addiu      $29, $29, 0x30
    /* CD68 0010CD68 0800E003 */  jr         $31
    /* CD6C 0010CD6C 00000000 */   nop
.size func_0010ccc0, 0xb0
