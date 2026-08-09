.section .text
.set noat
.set noreorder
glabel func_003bfae0
    /* 2BFAE0 003BFAE0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BFAE4 003BFAE4 2000BFFF */  sd         $31, 0x20($29)
    /* 2BFAE8 003BFAE8 1000B17F */  sq         $17, 0x10($29)
    /* 2BFAEC 003BFAEC 0000B07F */  sq         $16, 0x0($29)
    /* 2BFAF0 003BFAF0 4C00828C */  lw         $2, 0x4C($4)
    /* 2BFAF4 003BFAF4 0400918C */  lw         $17, 0x4($4)
    /* 2BFAF8 003BFAF8 02004230 */  andi       $2, $2, 0x2
    /* 2BFAFC 003BFAFC 03004010 */  beqz       $2, .L003BFB0C
    /* 2BFB00 003BFB00 2D808000 */   daddu     $16, $4, $0
    /* 2BFB04 003BFB04 4CFE0E0C */  jal        func_003bf930
    /* 2BFB08 003BFB08 00000000 */   nop
  .L003BFB0C:
    /* 2BFB0C 003BFB0C 90A40F0C */  jal        func_003e9240
    /* 2BFB10 003BFB10 2D202002 */   daddu     $4, $17, $0
    /* 2BFB14 003BFB14 07004014 */  bnez       $2, .L003BFB34
    /* 2BFB18 003BFB18 00000000 */   nop
    /* 2BFB1C 003BFB1C 03000292 */  lbu        $2, 0x3($16)
    /* 2BFB20 003BFB20 01004230 */  andi       $2, $2, 0x1
    /* 2BFB24 003BFB24 03004014 */  bnez       $2, .L003BFB34
    /* 2BFB28 003BFB28 00000000 */   nop
  .L003BFB2C:
    /* 2BFB2C 003BFB2C 3F000010 */  b          .L003BFC2C
    /* 2BFB30 003BFB30 2C000226 */   addiu     $2, $16, 0x2C
  .L003BFB34:
    /* 2BFB34 003BFB34 C0A50F0C */  jal        func_003e9700
    /* 2BFB38 003BFB38 2D202002 */   daddu     $4, $17, $0
    /* 2BFB3C 003BFB3C 2D884000 */  daddu      $17, $2, $0
    /* 2BFB40 003BFB40 2C000426 */  addiu      $4, $16, 0x2C
    /* 2BFB44 003BFB44 1C000526 */  addiu      $5, $16, 0x1C
    /* 2BFB48 003BFB48 A8900F0C */  jal        func_003e42a0
    /* 2BFB4C 003BFB4C 2D302002 */   daddu     $6, $17, $0
    /* 2BFB50 003BFB50 0C00238E */  lw         $3, 0xC($17)
    /* 2BFB54 003BFB54 03000224 */  addiu      $2, $0, 0x3
    /* 2BFB58 003BFB58 03006330 */  andi       $3, $3, 0x3
    /* 2BFB5C 003BFB5C 30006210 */  beq        $3, $2, .L003BFC20
    /* 2BFB60 003BFB60 00000000 */   nop
    /* 2BFB64 003BFB64 040025C6 */  lwc1       $f5, 0x4($17)
    /* 2BFB68 003BFB68 000024C6 */  lwc1       $f4, 0x0($17)
    /* 2BFB6C 003BFB6C 080023C6 */  lwc1       $f3, 0x8($17)
    /* 2BFB70 003BFB70 140022C6 */  lwc1       $f2, 0x14($17)
    /* 2BFB74 003BFB74 100021C6 */  lwc1       $f1, 0x10($17)
    /* 2BFB78 003BFB78 180020C6 */  lwc1       $f0, 0x18($17)
    /* 2BFB7C 003BFB7C 1A280546 */  mula.s     $f5, $f5
    /* 2BFB80 003BFB80 1E200446 */  madda.s    $f4, $f4
    /* 2BFB84 003BFB84 1C190346 */  madd.s     $f4, $f3, $f3
    /* 2BFB88 003BFB88 1A100246 */  mula.s     $f2, $f2
    /* 2BFB8C 003BFB8C 1E080146 */  madda.s    $f1, $f1
    /* 2BFB90 003BFB90 DC000046 */  madd.s     $f3, $f0, $f0
    /* 2BFB94 003BFB94 240022C6 */  lwc1       $f2, 0x24($17)
    /* 2BFB98 003BFB98 200021C6 */  lwc1       $f1, 0x20($17)
    /* 2BFB9C 003BFB9C 280020C6 */  lwc1       $f0, 0x28($17)
    /* 2BFBA0 003BFBA0 1A100246 */  mula.s     $f2, $f2
    /* 2BFBA4 003BFBA4 1E080146 */  madda.s    $f1, $f1
    /* 2BFBA8 003BFBA8 5C000046 */  madd.s     $f1, $f0, $f0
    /* 2BFBAC 003BFBAC 34180146 */  c.lt.s     $f3, $f1
    /* 2BFBB0 003BFBB0 03000145 */  bc1t       .L003BFBC0
    /* 2BFBB4 003BFBB4 00000000 */   nop
    /* 2BFBB8 003BFBB8 02000010 */  b          .L003BFBC4
    /* 2BFBBC 003BFBBC 06180046 */   mov.s     $f0, $f3
  .L003BFBC0:
    /* 2BFBC0 003BFBC0 06080046 */  mov.s      $f0, $f1
  .L003BFBC4:
    /* 2BFBC4 003BFBC4 34200046 */  c.lt.s     $f4, $f0
    /* 2BFBC8 003BFBC8 03000145 */  bc1t       .L003BFBD8
    /* 2BFBCC 003BFBCC 00000000 */   nop
    /* 2BFBD0 003BFBD0 09000010 */  b          .L003BFBF8
    /* 2BFBD4 003BFBD4 00000000 */   nop
  .L003BFBD8:
    /* 2BFBD8 003BFBD8 34180146 */  c.lt.s     $f3, $f1
    /* 2BFBDC 003BFBDC 03000145 */  bc1t       .L003BFBEC
    /* 2BFBE0 003BFBE0 00000000 */   nop
    /* 2BFBE4 003BFBE4 03000010 */  b          .L003BFBF4
    /* 2BFBE8 003BFBE8 06190046 */   mov.s     $f4, $f3
  .L003BFBEC:
    /* 2BFBEC 003BFBEC C6080046 */  mov.s      $f3, $f1
    /* 2BFBF0 003BFBF0 06190046 */  mov.s      $f4, $f3
  .L003BFBF4:
    /* 2BFBF4 003BFBF4 00000000 */  nop
  .L003BFBF8:
    /* 2BFBF8 003BFBF8 00000000 */  nop
    /* 2BFBFC 003BFBFC 44000446 */  c1         0x40044
    /* 2BFC00 003BFC00 280000C6 */  lwc1       $f0, 0x28($16)
    /* 2BFC04 003BFC04 02000146 */  mul.s      $f0, $f0, $f1
    /* 2BFC08 003BFC08 380000E6 */  swc1       $f0, 0x38($16)
  .L003BFC0C:
    /* 2BFC0C 003BFC0C 03000392 */  lbu        $3, 0x3($16)
    /* 2BFC10 003BFC10 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2BFC14 003BFC14 24106200 */  and        $2, $3, $2
    /* 2BFC18 003BFC18 C4FF0010 */  b          .L003BFB2C
    /* 2BFC1C 003BFC1C 030002A2 */   sb        $2, 0x3($16)
  .L003BFC20:
    /* 2BFC20 003BFC20 280000C6 */  lwc1       $f0, 0x28($16)
    /* 2BFC24 003BFC24 F9FF0010 */  b          .L003BFC0C
    /* 2BFC28 003BFC28 380000E6 */   swc1      $f0, 0x38($16)
  .L003BFC2C:
    /* 2BFC2C 003BFC2C 2000BFDF */  ld         $31, 0x20($29)
    /* 2BFC30 003BFC30 1000B17B */  lq         $17, 0x10($29)
    /* 2BFC34 003BFC34 0000B07B */  lq         $16, 0x0($29)
    /* 2BFC38 003BFC38 0800E003 */  jr         $31
    /* 2BFC3C 003BFC3C 3000BD27 */   addiu     $29, $29, 0x30
.size func_003bfae0, 0x160
