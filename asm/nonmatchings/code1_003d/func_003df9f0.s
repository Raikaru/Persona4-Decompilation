.section .text
.set noat
.set noreorder
glabel func_003df9f0
    /* 2DF9F0 003DF9F0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2DF9F4 003DF9F4 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 2DF9F8 003DF9F8 3400A927 */  addiu      $9, $29, 0x34
    /* 2DF9FC 003DF9FC 2000A2C4 */  lwc1       $f2, 0x20($5)
    /* 2DFA00 003DFA00 3800A827 */  addiu      $8, $29, 0x38
    /* 2DFA04 003DFA04 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 2DFA08 003DFA08 0000A6C4 */  lwc1       $f6, 0x0($5)
    /* 2DFA0C 003DFA0C 1000A5C4 */  lwc1       $f5, 0x10($5)
    /* 2DFA10 003DFA10 1400A4C4 */  lwc1       $f4, 0x14($5)
    /* 2DFA14 003DFA14 3400A0E7 */  swc1       $f0, 0x34($29)
    /* 2DFA18 003DFA18 2400A0C4 */  lwc1       $f0, 0x24($5)
    /* 2DFA1C 003DFA1C 1000A2E7 */  swc1       $f2, 0x10($29)
    /* 2DFA20 003DFA20 000022C5 */  lwc1       $f2, 0x0($9)
    /* 2DFA24 003DFA24 3800A1E7 */  swc1       $f1, 0x38($29)
    /* 2DFA28 003DFA28 1800A3C4 */  lwc1       $f3, 0x18($5)
    /* 2DFA2C 003DFA2C 2800A1C4 */  lwc1       $f1, 0x28($5)
    /* 2DFA30 003DFA30 1400A0E7 */  swc1       $f0, 0x14($29)
    /* 2DFA34 003DFA34 000000C5 */  lwc1       $f0, 0x0($8)
    /* 2DFA38 003DFA38 1A100246 */  mula.s     $f2, $f2
    /* 2DFA3C 003DFA3C 1E300646 */  madda.s    $f6, $f6
    /* 2DFA40 003DFA40 2000A5E7 */  swc1       $f5, 0x20($29)
    /* 2DFA44 003DFA44 2400A4E7 */  swc1       $f4, 0x24($29)
    /* 2DFA48 003DFA48 2800A3E7 */  swc1       $f3, 0x28($29)
    /* 2DFA4C 003DFA4C 1C000046 */  madd.s     $f0, $f0, $f0
    /* 2DFA50 003DFA50 04000046 */  c1         0x4
    /* 2DFA54 003DFA54 3000A5C4 */  lwc1       $f5, 0x30($5)
    /* 2DFA58 003DFA58 3400A4C4 */  lwc1       $f4, 0x34($5)
    /* 2DFA5C 003DFA5C 3800A3C4 */  lwc1       $f3, 0x38($5)
    /* 2DFA60 003DFA60 1800A1E7 */  swc1       $f1, 0x18($29)
    /* 2DFA64 003DFA64 00088044 */  mtc1       $0, $f1
    /* 2DFA68 003DFA68 3000A6E7 */  swc1       $f6, 0x30($29)
    /* 2DFA6C 003DFA6C 0000A5E7 */  swc1       $f5, 0x0($29)
    /* 2DFA70 003DFA70 0400A4E7 */  swc1       $f4, 0x4($29)
    /* 2DFA74 003DFA74 0800A3E7 */  swc1       $f3, 0x8($29)
    /* 2DFA78 003DFA78 00000000 */  nop
    /* 2DFA7C 003DFA7C 00000000 */  nop
    /* 2DFA80 003DFA80 36000146 */  c.le.s     $f0, $f1
    /* 2DFA84 003DFA84 08000145 */  bc1t       .L003DFAA8
    /* 2DFA88 003DFA88 00000000 */   nop
    /* 2DFA8C 003DFA8C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DFA90 003DFA90 00088244 */  mtc1       $2, $f1
    /* 2DFA94 003DFA94 00000000 */  nop
    /* 2DFA98 003DFA98 03080046 */  div.s      $f0, $f1, $f0
    /* 2DFA9C 003DFA9C 00000000 */  nop
    /* 2DFAA0 003DFAA0 00000000 */  nop
    /* 2DFAA4 003DFAA4 00000000 */  nop
  .L003DFAA8:
    /* 2DFAA8 003DFAA8 2400A727 */  addiu      $7, $29, 0x24
    /* 2DFAAC 003DFAAC 2800A627 */  addiu      $6, $29, 0x28
    /* 2DFAB0 003DFAB0 0000E4C4 */  lwc1       $f4, 0x0($7)
    /* 2DFAB4 003DFAB4 2000A1C7 */  lwc1       $f1, 0x20($29)
    /* 2DFAB8 003DFAB8 0000C3C4 */  lwc1       $f3, 0x0($6)
    /* 2DFABC 003DFABC 3000A7C7 */  lwc1       $f7, 0x30($29)
    /* 2DFAC0 003DFAC0 000026C5 */  lwc1       $f6, 0x0($9)
    /* 2DFAC4 003DFAC4 000005C5 */  lwc1       $f5, 0x0($8)
    /* 2DFAC8 003DFAC8 1A200446 */  mula.s     $f4, $f4
    /* 2DFACC 003DFACC 1E080146 */  madda.s    $f1, $f1
    /* 2DFAD0 003DFAD0 5C180346 */  madd.s     $f1, $f3, $f3
    /* 2DFAD4 003DFAD4 84020146 */  c1         0x10284
    /* 2DFAD8 003DFAD8 C2300046 */  mul.s      $f3, $f6, $f0
    /* 2DFADC 003DFADC 000023E5 */  swc1       $f3, 0x0($9)
    /* 2DFAE0 003DFAE0 C2390046 */  mul.s      $f7, $f7, $f0
    /* 2DFAE4 003DFAE4 C2280046 */  mul.s      $f3, $f5, $f0
    /* 2DFAE8 003DFAE8 00108044 */  mtc1       $0, $f2
    /* 2DFAEC 003DFAEC 3000A7E7 */  swc1       $f7, 0x30($29)
    /* 2DFAF0 003DFAF0 000003E5 */  swc1       $f3, 0x0($8)
    /* 2DFAF4 003DFAF4 00000000 */  nop
    /* 2DFAF8 003DFAF8 00000000 */  nop
    /* 2DFAFC 003DFAFC 36500246 */  c.le.s     $f10, $f2
    /* 2DFB00 003DFB00 08000145 */  bc1t       .L003DFB24
    /* 2DFB04 003DFB04 00000000 */   nop
    /* 2DFB08 003DFB08 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DFB0C 003DFB0C 00088244 */  mtc1       $2, $f1
    /* 2DFB10 003DFB10 00000000 */  nop
    /* 2DFB14 003DFB14 830A0A46 */  div.s      $f10, $f1, $f10
    /* 2DFB18 003DFB18 00000000 */  nop
    /* 2DFB1C 003DFB1C 00000000 */  nop
    /* 2DFB20 003DFB20 00000000 */  nop
  .L003DFB24:
    /* 2DFB24 003DFB24 1400A527 */  addiu      $5, $29, 0x14
    /* 2DFB28 003DFB28 1800A327 */  addiu      $3, $29, 0x18
    /* 2DFB2C 003DFB2C 0000A4C4 */  lwc1       $f4, 0x0($5)
    /* 2DFB30 003DFB30 1000A1C7 */  lwc1       $f1, 0x10($29)
    /* 2DFB34 003DFB34 000063C4 */  lwc1       $f3, 0x0($3)
    /* 2DFB38 003DFB38 0000E6C4 */  lwc1       $f6, 0x0($7)
    /* 2DFB3C 003DFB3C 2000A7C7 */  lwc1       $f7, 0x20($29)
    /* 2DFB40 003DFB40 0000C5C4 */  lwc1       $f5, 0x0($6)
    /* 2DFB44 003DFB44 1A200446 */  mula.s     $f4, $f4
    /* 2DFB48 003DFB48 1E080146 */  madda.s    $f1, $f1
    /* 2DFB4C 003DFB4C 5C180346 */  madd.s     $f1, $f3, $f3
    /* 2DFB50 003DFB50 C2300A46 */  mul.s      $f3, $f6, $f10
    /* 2DFB54 003DFB54 0000E3E4 */  swc1       $f3, 0x0($7)
    /* 2DFB58 003DFB58 C2280A46 */  mul.s      $f3, $f5, $f10
    /* 2DFB5C 003DFB5C 44010146 */  c1         0x10144
    /* 2DFB60 003DFB60 C2390A46 */  mul.s      $f7, $f7, $f10
    /* 2DFB64 003DFB64 00108044 */  mtc1       $0, $f2
    /* 2DFB68 003DFB68 2000A7E7 */  swc1       $f7, 0x20($29)
    /* 2DFB6C 003DFB6C 0000C3E4 */  swc1       $f3, 0x0($6)
    /* 2DFB70 003DFB70 00000000 */  nop
    /* 2DFB74 003DFB74 00000000 */  nop
    /* 2DFB78 003DFB78 36280246 */  c.le.s     $f5, $f2
    /* 2DFB7C 003DFB7C 08000145 */  bc1t       .L003DFBA0
    /* 2DFB80 003DFB80 00000000 */   nop
    /* 2DFB84 003DFB84 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DFB88 003DFB88 00088244 */  mtc1       $2, $f1
    /* 2DFB8C 003DFB8C 00000000 */  nop
    /* 2DFB90 003DFB90 43090546 */  div.s      $f5, $f1, $f5
    /* 2DFB94 003DFB94 00000000 */  nop
    /* 2DFB98 003DFB98 00000000 */  nop
    /* 2DFB9C 003DFB9C 00000000 */  nop
  .L003DFBA0:
    /* 2DFBA0 003DFBA0 1000A4C7 */  lwc1       $f4, 0x10($29)
    /* 2DFBA4 003DFBA4 0000A3C4 */  lwc1       $f3, 0x0($5)
    /* 2DFBA8 003DFBA8 000062C4 */  lwc1       $f2, 0x0($3)
    /* 2DFBAC 003DFBAC 00088044 */  mtc1       $0, $f1
    /* 2DFBB0 003DFBB0 00000000 */  nop
    /* 2DFBB4 003DFBB4 36000146 */  c.le.s     $f0, $f1
    /* 2DFBB8 003DFBB8 02210546 */  mul.s      $f4, $f4, $f5
    /* 2DFBBC 003DFBBC 421A0546 */  mul.s      $f9, $f3, $f5
    /* 2DFBC0 003DFBC0 02120546 */  mul.s      $f8, $f2, $f5
    /* 2DFBC4 003DFBC4 1000A4E7 */  swc1       $f4, 0x10($29)
    /* 2DFBC8 003DFBC8 0000A9E4 */  swc1       $f9, 0x0($5)
    /* 2DFBCC 003DFBCC 4D000145 */  bc1t       .L003DFD04
    /* 2DFBD0 003DFBD0 000068E4 */   swc1      $f8, 0x0($3)
    /* 2DFBD4 003DFBD4 36500146 */  c.le.s     $f10, $f1
    /* 2DFBD8 003DFBD8 46000145 */  bc1t       .L003DFCF4
    /* 2DFBDC 003DFBDC 00000000 */   nop
    /* 2DFBE0 003DFBE0 36280146 */  c.le.s     $f5, $f1
    /* 2DFBE4 003DFBE4 3F000145 */  bc1t       .L003DFCE4
    /* 2DFBE8 003DFBE8 00000000 */   nop
    /* 2DFBEC 003DFBEC 0000E7C4 */  lwc1       $f7, 0x0($7)
    /* 2DFBF0 003DFBF0 2000A2C7 */  lwc1       $f2, 0x20($29)
    /* 2DFBF4 003DFBF4 0000C5C4 */  lwc1       $f5, 0x0($6)
    /* 2DFBF8 003DFBF8 02380946 */  mul.s      $f0, $f7, $f9
    /* 2DFBFC 003DFBFC 18080046 */  adda.s     $f1, $f0
    /* 2DFC00 003DFC00 1C100446 */  madd.s     $f0, $f2, $f4
    /* 2DFC04 003DFC04 18080046 */  adda.s     $f1, $f0
    /* 2DFC08 003DFC08 9C2A0846 */  madd.s     $f10, $f5, $f8
    /* 2DFC0C 003DFC0C 34500146 */  c.lt.s     $f10, $f1
    /* 2DFC10 003DFC10 03000145 */  bc1t       .L003DFC20
    /* 2DFC14 003DFC14 00000000 */   nop
    /* 2DFC18 003DFC18 03000010 */  b          .L003DFC28
    /* 2DFC1C 003DFC1C 000026C5 */   lwc1      $f6, 0x0($9)
  .L003DFC20:
    /* 2DFC20 003DFC20 87520046 */  neg.s      $f10, $f10
    /* 2DFC24 003DFC24 000026C5 */  lwc1       $f6, 0x0($9)
  .L003DFC28:
    /* 2DFC28 003DFC28 3000A1C7 */  lwc1       $f1, 0x30($29)
    /* 2DFC2C 003DFC2C 000003C5 */  lwc1       $f3, 0x0($8)
    /* 2DFC30 003DFC30 00008044 */  mtc1       $0, $f0
    /* 2DFC34 003DFC34 1A480646 */  mula.s     $f9, $f6
    /* 2DFC38 003DFC38 1E200146 */  madda.s    $f4, $f1
    /* 2DFC3C 003DFC3C 1C410346 */  madd.s     $f4, $f8, $f3
    /* 2DFC40 003DFC40 34200046 */  c.lt.s     $f4, $f0
    /* 2DFC44 003DFC44 03000145 */  bc1t       .L003DFC54
    /* 2DFC48 003DFC48 00000000 */   nop
    /* 2DFC4C 003DFC4C 03000010 */  b          .L003DFC5C
    /* 2DFC50 003DFC50 1A300746 */   mula.s    $f6, $f7
  .L003DFC54:
    /* 2DFC54 003DFC54 07210046 */  neg.s      $f4, $f4
    /* 2DFC58 003DFC58 1A300746 */  mula.s     $f6, $f7
  .L003DFC5C:
    /* 2DFC5C 003DFC5C 1E080246 */  madda.s    $f1, $f2
    /* 2DFC60 003DFC60 00088044 */  mtc1       $0, $f1
    /* 2DFC64 003DFC64 1C180546 */  madd.s     $f0, $f3, $f5
    /* 2DFC68 003DFC68 34000146 */  c.lt.s     $f0, $f1
    /* 2DFC6C 003DFC6C 03000145 */  bc1t       .L003DFC7C
    /* 2DFC70 003DFC70 00000000 */   nop
    /* 2DFC74 003DFC74 02000010 */  b          .L003DFC80
    /* 2DFC78 003DFC78 00000000 */   nop
  .L003DFC7C:
    /* 2DFC7C 003DFC7C 07000046 */  neg.s      $f0, $f0
  .L003DFC80:
    /* 2DFC80 003DFC80 34500446 */  c.lt.s     $f10, $f4
    /* 2DFC84 003DFC84 0C000045 */  bc1f       .L003DFCB8
    /* 2DFC88 003DFC88 00000000 */   nop
    /* 2DFC8C 003DFC8C 34500046 */  c.lt.s     $f10, $f0
    /* 2DFC90 003DFC90 05000045 */  bc1f       .L003DFCA8
    /* 2DFC94 003DFC94 00000000 */   nop
    /* 2DFC98 003DFC98 2000A627 */  addiu      $6, $29, 0x20
    /* 2DFC9C 003DFC9C 1000A527 */  addiu      $5, $29, 0x10
    /* 2DFCA0 003DFCA0 1B000010 */  b          .L003DFD10
    /* 2DFCA4 003DFCA4 3000A327 */   addiu     $3, $29, 0x30
  .L003DFCA8:
    /* 2DFCA8 003DFCA8 3000A627 */  addiu      $6, $29, 0x30
    /* 2DFCAC 003DFCAC 2000A527 */  addiu      $5, $29, 0x20
    /* 2DFCB0 003DFCB0 17000010 */  b          .L003DFD10
    /* 2DFCB4 003DFCB4 1000A327 */   addiu     $3, $29, 0x10
  .L003DFCB8:
    /* 2DFCB8 003DFCB8 34200046 */  c.lt.s     $f4, $f0
    /* 2DFCBC 003DFCBC 05000045 */  bc1f       .L003DFCD4
    /* 2DFCC0 003DFCC0 00000000 */   nop
    /* 2DFCC4 003DFCC4 1000A627 */  addiu      $6, $29, 0x10
    /* 2DFCC8 003DFCC8 3000A527 */  addiu      $5, $29, 0x30
    /* 2DFCCC 003DFCCC 10000010 */  b          .L003DFD10
    /* 2DFCD0 003DFCD0 2000A327 */   addiu     $3, $29, 0x20
  .L003DFCD4:
    /* 2DFCD4 003DFCD4 3000A627 */  addiu      $6, $29, 0x30
    /* 2DFCD8 003DFCD8 2000A527 */  addiu      $5, $29, 0x20
    /* 2DFCDC 003DFCDC 0C000010 */  b          .L003DFD10
    /* 2DFCE0 003DFCE0 1000A327 */   addiu     $3, $29, 0x10
  .L003DFCE4:
    /* 2DFCE4 003DFCE4 3000A627 */  addiu      $6, $29, 0x30
    /* 2DFCE8 003DFCE8 2000A527 */  addiu      $5, $29, 0x20
    /* 2DFCEC 003DFCEC 08000010 */  b          .L003DFD10
    /* 2DFCF0 003DFCF0 1000A327 */   addiu     $3, $29, 0x10
  .L003DFCF4:
    /* 2DFCF4 003DFCF4 1000A627 */  addiu      $6, $29, 0x10
    /* 2DFCF8 003DFCF8 3000A527 */  addiu      $5, $29, 0x30
    /* 2DFCFC 003DFCFC 04000010 */  b          .L003DFD10
    /* 2DFD00 003DFD00 2000A327 */   addiu     $3, $29, 0x20
  .L003DFD04:
    /* 2DFD04 003DFD04 2000A627 */  addiu      $6, $29, 0x20
    /* 2DFD08 003DFD08 1000A527 */  addiu      $5, $29, 0x10
    /* 2DFD0C 003DFD0C 3000A327 */  addiu      $3, $29, 0x30
  .L003DFD10:
    /* 2DFD10 003DFD10 0400C1C4 */  lwc1       $f1, 0x4($6)
    /* 2DFD14 003DFD14 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2DFD18 003DFD18 0800C3C4 */  lwc1       $f3, 0x8($6)
    /* 2DFD1C 003DFD1C 0400A2C4 */  lwc1       $f2, 0x4($5)
    /* 2DFD20 003DFD20 00208044 */  mtc1       $0, $f4
    /* 2DFD24 003DFD24 1A080046 */  mula.s     $f1, $f0
    /* 2DFD28 003DFD28 1D180246 */  msub.s     $f0, $f3, $f2
    /* 2DFD2C 003DFD2C 000060E4 */  swc1       $f0, 0x0($3)
    /* 2DFD30 003DFD30 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* 2DFD34 003DFD34 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 2DFD38 003DFD38 0000C3C4 */  lwc1       $f3, 0x0($6)
    /* 2DFD3C 003DFD3C 0800A2C4 */  lwc1       $f2, 0x8($5)
    /* 2DFD40 003DFD40 1A080046 */  mula.s     $f1, $f0
    /* 2DFD44 003DFD44 1D180246 */  msub.s     $f0, $f3, $f2
    /* 2DFD48 003DFD48 040060E4 */  swc1       $f0, 0x4($3)
    /* 2DFD4C 003DFD4C 0000C1C4 */  lwc1       $f1, 0x0($6)
    /* 2DFD50 003DFD50 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 2DFD54 003DFD54 0400C3C4 */  lwc1       $f3, 0x4($6)
    /* 2DFD58 003DFD58 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 2DFD5C 003DFD5C 1A080046 */  mula.s     $f1, $f0
    /* 2DFD60 003DFD60 1D180246 */  msub.s     $f0, $f3, $f2
    /* 2DFD64 003DFD64 080060E4 */  swc1       $f0, 0x8($3)
    /* 2DFD68 003DFD68 040062C4 */  lwc1       $f2, 0x4($3)
    /* 2DFD6C 003DFD6C 000061C4 */  lwc1       $f1, 0x0($3)
    /* 2DFD70 003DFD70 080060C4 */  lwc1       $f0, 0x8($3)
    /* 2DFD74 003DFD74 1A100246 */  mula.s     $f2, $f2
    /* 2DFD78 003DFD78 1E080146 */  madda.s    $f1, $f1
    /* 2DFD7C 003DFD7C 1C000046 */  madd.s     $f0, $f0, $f0
    /* 2DFD80 003DFD80 44000046 */  c1         0x44
    /* 2DFD84 003DFD84 00000000 */  nop
    /* 2DFD88 003DFD88 00000000 */  nop
    /* 2DFD8C 003DFD8C 36080446 */  c.le.s     $f1, $f4
    /* 2DFD90 003DFD90 08000145 */  bc1t       .L003DFDB4
    /* 2DFD94 003DFD94 00000000 */   nop
    /* 2DFD98 003DFD98 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DFD9C 003DFD9C 00008244 */  mtc1       $2, $f0
    /* 2DFDA0 003DFDA0 00000000 */  nop
    /* 2DFDA4 003DFDA4 43000146 */  div.s      $f1, $f0, $f1
    /* 2DFDA8 003DFDA8 00000000 */  nop
    /* 2DFDAC 003DFDAC 00000000 */  nop
    /* 2DFDB0 003DFDB0 00000000 */  nop
  .L003DFDB4:
    /* 2DFDB4 003DFDB4 000060C4 */  lwc1       $f0, 0x0($3)
    /* 2DFDB8 003DFDB8 00208044 */  mtc1       $0, $f4
    /* 2DFDBC 003DFDBC 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DFDC0 003DFDC0 000060E4 */  swc1       $f0, 0x0($3)
    /* 2DFDC4 003DFDC4 040060C4 */  lwc1       $f0, 0x4($3)
    /* 2DFDC8 003DFDC8 02000146 */  mul.s      $f0, $f0, $f1
    /* 2DFDCC 003DFDCC 040060E4 */  swc1       $f0, 0x4($3)
    /* 2DFDD0 003DFDD0 080060C4 */  lwc1       $f0, 0x8($3)
    /* 2DFDD4 003DFDD4 C2000146 */  mul.s      $f3, $f0, $f1
    /* 2DFDD8 003DFDD8 080063E4 */  swc1       $f3, 0x8($3)
    /* 2DFDDC 003DFDDC 040061C4 */  lwc1       $f1, 0x4($3)
    /* 2DFDE0 003DFDE0 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 2DFDE4 003DFDE4 0400C2C4 */  lwc1       $f2, 0x4($6)
    /* 2DFDE8 003DFDE8 1A080046 */  mula.s     $f1, $f0
    /* 2DFDEC 003DFDEC 1D180246 */  msub.s     $f0, $f3, $f2
    /* 2DFDF0 003DFDF0 0000A0E4 */  swc1       $f0, 0x0($5)
    /* 2DFDF4 003DFDF4 080061C4 */  lwc1       $f1, 0x8($3)
    /* 2DFDF8 003DFDF8 0000C0C4 */  lwc1       $f0, 0x0($6)
    /* 2DFDFC 003DFDFC 000063C4 */  lwc1       $f3, 0x0($3)
    /* 2DFE00 003DFE00 0800C2C4 */  lwc1       $f2, 0x8($6)
    /* 2DFE04 003DFE04 1A080046 */  mula.s     $f1, $f0
    /* 2DFE08 003DFE08 1D180246 */  msub.s     $f0, $f3, $f2
    /* 2DFE0C 003DFE0C 0400A0E4 */  swc1       $f0, 0x4($5)
    /* 2DFE10 003DFE10 000061C4 */  lwc1       $f1, 0x0($3)
    /* 2DFE14 003DFE14 0400C0C4 */  lwc1       $f0, 0x4($6)
    /* 2DFE18 003DFE18 040063C4 */  lwc1       $f3, 0x4($3)
    /* 2DFE1C 003DFE1C 0000C2C4 */  lwc1       $f2, 0x0($6)
    /* 2DFE20 003DFE20 1A080046 */  mula.s     $f1, $f0
    /* 2DFE24 003DFE24 1D180246 */  msub.s     $f0, $f3, $f2
    /* 2DFE28 003DFE28 0800A0E4 */  swc1       $f0, 0x8($5)
    /* 2DFE2C 003DFE2C 0400A2C4 */  lwc1       $f2, 0x4($5)
    /* 2DFE30 003DFE30 0000A1C4 */  lwc1       $f1, 0x0($5)
    /* 2DFE34 003DFE34 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2DFE38 003DFE38 1A100246 */  mula.s     $f2, $f2
    /* 2DFE3C 003DFE3C 1E080146 */  madda.s    $f1, $f1
    /* 2DFE40 003DFE40 1C000046 */  madd.s     $f0, $f0, $f0
    /* 2DFE44 003DFE44 44010046 */  c1         0x144
    /* 2DFE48 003DFE48 00000000 */  nop
    /* 2DFE4C 003DFE4C 00000000 */  nop
    /* 2DFE50 003DFE50 36280446 */  c.le.s     $f5, $f4
    /* 2DFE54 003DFE54 08000145 */  bc1t       .L003DFE78
    /* 2DFE58 003DFE58 00000000 */   nop
    /* 2DFE5C 003DFE5C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DFE60 003DFE60 00008244 */  mtc1       $2, $f0
    /* 2DFE64 003DFE64 00000000 */  nop
    /* 2DFE68 003DFE68 43010546 */  div.s      $f5, $f0, $f5
    /* 2DFE6C 003DFE6C 00000000 */  nop
    /* 2DFE70 003DFE70 00000000 */  nop
    /* 2DFE74 003DFE74 00000000 */  nop
  .L003DFE78:
    /* 2DFE78 003DFE78 0000A3C4 */  lwc1       $f3, 0x0($5)
    /* 2DFE7C 003DFE7C FDFF023C */  lui        $2, (0xFFFDFFFF >> 16)
    /* 2DFE80 003DFE80 FFFF4334 */  ori        $3, $2, (0xFFFDFFFF & 0xFFFF)
    /* 2DFE84 003DFE84 0000A2C7 */  lwc1       $f2, 0x0($29)
    /* 2DFE88 003DFE88 2D108000 */  daddu      $2, $4, $0
    /* 2DFE8C 003DFE8C 0400A1C7 */  lwc1       $f1, 0x4($29)
    /* 2DFE90 003DFE90 0800A0C7 */  lwc1       $f0, 0x8($29)
    /* 2DFE94 003DFE94 C2180546 */  mul.s      $f3, $f3, $f5
    /* 2DFE98 003DFE98 0000A3E4 */  swc1       $f3, 0x0($5)
    /* 2DFE9C 003DFE9C 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2DFEA0 003DFEA0 C2180546 */  mul.s      $f3, $f3, $f5
    /* 2DFEA4 003DFEA4 0400A3E4 */  swc1       $f3, 0x4($5)
    /* 2DFEA8 003DFEA8 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2DFEAC 003DFEAC C2180546 */  mul.s      $f3, $f3, $f5
    /* 2DFEB0 003DFEB0 0800A3E4 */  swc1       $f3, 0x8($5)
    /* 2DFEB4 003DFEB4 3000A5C7 */  lwc1       $f5, 0x30($29)
    /* 2DFEB8 003DFEB8 3400A4C7 */  lwc1       $f4, 0x34($29)
    /* 2DFEBC 003DFEBC 3800A3C7 */  lwc1       $f3, 0x38($29)
    /* 2DFEC0 003DFEC0 000085E4 */  swc1       $f5, 0x0($4)
    /* 2DFEC4 003DFEC4 040084E4 */  swc1       $f4, 0x4($4)
    /* 2DFEC8 003DFEC8 080083E4 */  swc1       $f3, 0x8($4)
    /* 2DFECC 003DFECC 2000A5C7 */  lwc1       $f5, 0x20($29)
    /* 2DFED0 003DFED0 2400A4C7 */  lwc1       $f4, 0x24($29)
    /* 2DFED4 003DFED4 2800A3C7 */  lwc1       $f3, 0x28($29)
    /* 2DFED8 003DFED8 100085E4 */  swc1       $f5, 0x10($4)
    /* 2DFEDC 003DFEDC 140084E4 */  swc1       $f4, 0x14($4)
    /* 2DFEE0 003DFEE0 180083E4 */  swc1       $f3, 0x18($4)
    /* 2DFEE4 003DFEE4 1000A5C7 */  lwc1       $f5, 0x10($29)
    /* 2DFEE8 003DFEE8 1400A4C7 */  lwc1       $f4, 0x14($29)
    /* 2DFEEC 003DFEEC 1800A3C7 */  lwc1       $f3, 0x18($29)
    /* 2DFEF0 003DFEF0 200085E4 */  swc1       $f5, 0x20($4)
    /* 2DFEF4 003DFEF4 240084E4 */  swc1       $f4, 0x24($4)
    /* 2DFEF8 003DFEF8 280083E4 */  swc1       $f3, 0x28($4)
    /* 2DFEFC 003DFEFC 300082E4 */  swc1       $f2, 0x30($4)
    /* 2DFF00 003DFF00 340081E4 */  swc1       $f1, 0x34($4)
    /* 2DFF04 003DFF04 380080E4 */  swc1       $f0, 0x38($4)
    /* 2DFF08 003DFF08 0C00858C */  lw         $5, 0xC($4)
    /* 2DFF0C 003DFF0C 0300A534 */  ori        $5, $5, 0x3
    /* 2DFF10 003DFF10 2418A300 */  and        $3, $5, $3
    /* 2DFF14 003DFF14 0C0083AC */  sw         $3, 0xC($4)
    /* 2DFF18 003DFF18 0800E003 */  jr         $31
    /* 2DFF1C 003DFF1C 4000BD27 */   addiu     $29, $29, 0x40
.size func_003df9f0, 0x530
