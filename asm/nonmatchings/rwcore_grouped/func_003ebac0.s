.section .text
.set noat
.set noreorder
glabel func_003ebac0
    /* 2EBAC0 003EBAC0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2EBAC4 003EBAC4 0C00A38C */  lw         $3, 0xC($5)
    /* 2EBAC8 003EBAC8 6000BFFF */  sd         $31, 0x60($29)
    /* 2EBACC 003EBACC 5000B57F */  sq         $21, 0x50($29)
    /* 2EBAD0 003EBAD0 4000B47F */  sq         $20, 0x40($29)
    /* 2EBAD4 003EBAD4 2DA88000 */  daddu      $21, $4, $0
    /* 2EBAD8 003EBAD8 3000B37F */  sq         $19, 0x30($29)
    /* 2EBADC 003EBADC 2000B27F */  sq         $18, 0x20($29)
    /* 2EBAE0 003EBAE0 1000B17F */  sq         $17, 0x10($29)
    /* 2EBAE4 003EBAE4 0000B07F */  sq         $16, 0x0($29)
    /* 2EBAE8 003EBAE8 0C00828C */  lw         $2, 0xC($4)
    /* 2EBAEC 003EBAEC 31004314 */  bne        $2, $3, .L003EBBB4
    /* 2EBAF0 003EBAF0 2DA0A000 */   daddu     $20, $5, $0
    /* 2EBAF4 003EBAF4 1800A48E */  lw         $4, 0x18($21)
    /* 2EBAF8 003EBAF8 0B008010 */  beqz       $4, .L003EBB28
    /* 2EBAFC 003EBAFC 00000000 */   nop
    /* 2EBB00 003EBB00 1800858E */  lw         $5, 0x18($20)
    /* 2EBB04 003EBB04 0800A010 */  beqz       $5, .L003EBB28
    /* 2EBB08 003EBB08 00000000 */   nop
    /* 2EBB0C 003EBB0C 09006128 */  slti       $1, $3, 0x9
    /* 2EBB10 003EBB10 05002010 */  beqz       $1, .L003EBB28
    /* 2EBB14 003EBB14 00000000 */   nop
    /* 2EBB18 003EBB18 01000224 */  addiu      $2, $0, 0x1
    /* 2EBB1C 003EBB1C 04106200 */  sllv       $2, $2, $3
    /* 2EBB20 003EBB20 04FE100C */  jal        func_0043f810
    /* 2EBB24 003EBB24 80300200 */   sll       $6, $2, 2
  .L003EBB28:
    /* 2EBB28 003EBB28 0C00A38E */  lw         $3, 0xC($21)
    /* 2EBB2C 003EBB2C 0400A28E */  lw         $2, 0x4($21)
    /* 2EBB30 003EBB30 07006324 */  addiu      $3, $3, 0x7
    /* 2EBB34 003EBB34 C3180300 */  sra        $3, $3, 3
    /* 2EBB38 003EBB38 18806200 */  mult       $16, $3, $2
    /* 2EBB3C 003EBB3C 1400928E */  lw         $18, 0x14($20)
    /* 2EBB40 003EBB40 1400B18E */  lw         $17, 0x14($21)
    /* 2EBB44 003EBB44 0800A28E */  lw         $2, 0x8($21)
    /* 2EBB48 003EBB48 2A080200 */  slt        $1, $0, $2
    /* 2EBB4C 003EBB4C 0E002010 */  beqz       $1, .L003EBB88
    /* 2EBB50 003EBB50 2D980000 */   daddu     $19, $0, $0
  .L003EBB54:
    /* 2EBB54 003EBB54 2D202002 */  daddu      $4, $17, $0
    /* 2EBB58 003EBB58 2D284002 */  daddu      $5, $18, $0
    /* 2EBB5C 003EBB5C 04FE100C */  jal        func_0043f810
    /* 2EBB60 003EBB60 2D300002 */   daddu     $6, $16, $0
    /* 2EBB64 003EBB64 0800A28E */  lw         $2, 0x8($21)
    /* 2EBB68 003EBB68 01007326 */  addiu      $19, $19, 0x1
    /* 2EBB6C 003EBB6C 1000A48E */  lw         $4, 0x10($21)
    /* 2EBB70 003EBB70 1000838E */  lw         $3, 0x10($20)
    /* 2EBB74 003EBB74 2A106202 */  slt        $2, $19, $2
    /* 2EBB78 003EBB78 21882402 */  addu       $17, $17, $4
    /* 2EBB7C 003EBB7C F5FF4014 */  bnez       $2, .L003EBB54
    /* 2EBB80 003EBB80 21904302 */   addu      $18, $18, $3
    /* 2EBB84 003EBB84 00000000 */  nop
  .L003EBB88:
    /* 2EBB88 003EBB88 0000838E */  lw         $3, 0x0($20)
    /* 2EBB8C 003EBB8C 0000A68E */  lw         $6, 0x0($21)
    /* 2EBB90 003EBB90 FDFF0524 */  addiu      $5, $0, -0x3
    /* 2EBB94 003EBB94 2D10A002 */  daddu      $2, $21, $0
    /* 2EBB98 003EBB98 02006430 */  andi       $4, $3, 0x2
    /* 2EBB9C 003EBB9C 2418C500 */  and        $3, $6, $5
    /* 2EBBA0 003EBBA0 0000A3AE */  sw         $3, 0x0($21)
    /* 2EBBA4 003EBBA4 0000A38E */  lw         $3, 0x0($21)
    /* 2EBBA8 003EBBA8 25186400 */  or         $3, $3, $4
    /* 2EBBAC 003EBBAC 07000010 */  b          .L003EBBCC
    /* 2EBBB0 003EBBB0 0000A3AE */   sw        $3, 0x0($21)
  .L003EBBB4:
    /* 2EBBB4 003EBBB4 C0AD0F0C */  jal        func_003eb700
    /* 2EBBB8 003EBBB8 00000000 */   nop
    /* 2EBBBC 003EBBBC F2FF4014 */  bnez       $2, .L003EBB88
    /* 2EBBC0 003EBBC0 00000000 */   nop
    /* 2EBBC4 003EBBC4 F0FF0010 */  b          .L003EBB88
    /* 2EBBC8 003EBBC8 2DA80000 */   daddu     $21, $0, $0
  .L003EBBCC:
    /* 2EBBCC 003EBBCC 6000BFDF */  ld         $31, 0x60($29)
    /* 2EBBD0 003EBBD0 5000B57B */  lq         $21, 0x50($29)
    /* 2EBBD4 003EBBD4 4000B47B */  lq         $20, 0x40($29)
    /* 2EBBD8 003EBBD8 3000B37B */  lq         $19, 0x30($29)
    /* 2EBBDC 003EBBDC 2000B27B */  lq         $18, 0x20($29)
    /* 2EBBE0 003EBBE0 1000B17B */  lq         $17, 0x10($29)
    /* 2EBBE4 003EBBE4 0000B07B */  lq         $16, 0x0($29)
    /* 2EBBE8 003EBBE8 0800E003 */  jr         $31
    /* 2EBBEC 003EBBEC 7000BD27 */   addiu     $29, $29, 0x70
.size func_003ebac0, 0x130
