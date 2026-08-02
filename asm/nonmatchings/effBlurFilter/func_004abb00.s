.section .text
.set noat
.set noreorder
glabel func_004abb00
    /* 3ABB00 004ABB00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ABB04 004ABB04 1000BFFF */  sd         $31, 0x10($29)
    /* 3ABB08 004ABB08 0000B07F */  sq         $16, 0x0($29)
    /* 3ABB0C 004ABB0C 2D808000 */  daddu      $16, $4, $0
    /* 3ABB10 004ABB10 0400828C */  lw         $2, 0x4($4)
    /* 3ABB14 004ABB14 06004014 */  bnez       $2, .L004ABB30
    /* 3ABB18 004ABB18 00000000 */   nop
    /* 3ABB1C 004ABB1C 7100043C */  lui        $4, %hi(D_00714380)
    /* 3ABB20 004ABB20 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3ABB24 004ABB24 D7070524 */  addiu      $5, $0, 0x7D7
    /* 3ABB28 004ABB28 CCB5110C */  jal        func_0046d730
    /* 3ABB2C 004ABB2C 00000000 */   nop
  .L004ABB30:
    /* 3ABB30 004ABB30 0400028E */  lw         $2, 0x4($16)
    /* 3ABB34 004ABB34 01004224 */  addiu      $2, $2, 0x1
    /* 3ABB38 004ABB38 040002AE */  sw         $2, 0x4($16)
    /* 3ABB3C 004ABB3C 2D100002 */  daddu      $2, $16, $0
    /* 3ABB40 004ABB40 1000BFDF */  ld         $31, 0x10($29)
    /* 3ABB44 004ABB44 0000B07B */  lq         $16, 0x0($29)
    /* 3ABB48 004ABB48 2000BD27 */  addiu      $29, $29, 0x20
    /* 3ABB4C 004ABB4C 0800E003 */  jr         $31
    /* 3ABB50 004ABB50 00000000 */   nop
    /* 3ABB54 004ABB54 00000000 */  nop
    /* 3ABB58 004ABB58 00000000 */  nop
    /* 3ABB5C 004ABB5C 00000000 */  nop
.size func_004abb00, 0x60
