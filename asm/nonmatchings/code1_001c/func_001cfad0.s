.section .text
.set noat
.set noreorder
glabel func_001cfad0
    /* CFAD0 001CFAD0 00FFBD27 */  addiu      $29, $29, -0x100
    /* CFAD4 001CFAD4 4000BFFF */  sd         $31, 0x40($29)
    /* CFAD8 001CFAD8 3000B27F */  sq         $18, 0x30($29)
    /* CFADC 001CFADC 2000B17F */  sq         $17, 0x20($29)
    /* CFAE0 001CFAE0 1000B07F */  sq         $16, 0x10($29)
    /* CFAE4 001CFAE4 0800B6E7 */  swc1       $f22, 0x8($29)
    /* CFAE8 001CFAE8 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CFAEC 001CFAEC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CFAF0 001CFAF0 2D888000 */  daddu      $17, $4, $0
    /* CFAF4 001CFAF4 46650046 */  mov.s      $f21, $f12
    /* CFAF8 001CFAF8 066D0046 */  mov.s      $f20, $f13
    /* CFAFC 001CFAFC E000828C */  lw         $2, 0xE0($4)
    /* CFB00 001CFB00 3000508C */  lw         $16, 0x30($2)
    /* CFB04 001CFB04 640A048E */  lw         $4, 0xA64($16)
    /* CFB08 001CFB08 1000053C */  lui        $5, (0x100000 >> 16)
    /* CFB0C 001CFB0C C4C9080C */  jal        func_00232710
    /* CFB10 001CFB10 00000000 */   nop
    /* CFB14 001CFB14 2D904000 */  daddu      $18, $2, $0
    /* CFB18 001CFB18 2D200002 */  daddu      $4, $16, $0
    /* CFB1C 001CFB1C D000A527 */  addiu      $5, $29, 0xD0
    /* CFB20 001CFB20 7456060C */  jal        func_001959d0
    /* CFB24 001CFB24 00000000 */   nop
    /* CFB28 001CFB28 0D004016 */  bnez       $18, .L001CFB60
    /* CFB2C 001CFB2C 00000000 */   nop
    /* CFB30 001CFB30 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* CFB34 001CFB34 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CFB38 001CFB38 C2080046 */  mul.s      $f3, $f1, $f0
    /* CFB3C 001CFB3C 0C8182C7 */  lwc1       $f2, -0x7EF4($28)
    /* CFB40 001CFB40 D400A1C7 */  lwc1       $f1, 0xD4($29)
    /* CFB44 001CFB44 00008044 */  mtc1       $0, $f0
    /* CFB48 001CFB48 00000000 */  nop
    /* CFB4C 001CFB4C 18000146 */  adda.s     $f0, $f1
    /* CFB50 001CFB50 1C100346 */  madd.s     $f0, $f2, $f3
    /* CFB54 001CFB54 D400A0E7 */  swc1       $f0, 0xD4($29)
    /* CFB58 001CFB58 0B000010 */  b          .L001CFB88
    /* CFB5C 001CFB5C 00000000 */   nop
  .L001CFB60:
    /* CFB60 001CFB60 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* CFB64 001CFB64 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CFB68 001CFB68 C2080046 */  mul.s      $f3, $f1, $f0
    /* CFB6C 001CFB6C 0C8182C7 */  lwc1       $f2, -0x7EF4($28)
    /* CFB70 001CFB70 D400A1C7 */  lwc1       $f1, 0xD4($29)
    /* CFB74 001CFB74 00008044 */  mtc1       $0, $f0
    /* CFB78 001CFB78 00000000 */  nop
    /* CFB7C 001CFB7C 18000146 */  adda.s     $f0, $f1
    /* CFB80 001CFB80 1D100346 */  msub.s     $f0, $f2, $f3
    /* CFB84 001CFB84 D400A0E7 */  swc1       $f0, 0xD4($29)
  .L001CFB88:
    /* CFB88 001CFB88 E000A427 */  addiu      $4, $29, 0xE0
    /* CFB8C 001CFB8C 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* CFB90 001CFB90 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* CFB94 001CFB94 01000624 */  addiu      $6, $0, 0x1
    /* CFB98 001CFB98 1C000726 */  addiu      $7, $16, 0x1C
    /* CFB9C 001CFB9C D0720F0C */  jal        func_003dcb40
    /* CFBA0 001CFBA0 00000000 */   nop
    /* CFBA4 001CFBA4 4843023C */  lui        $2, (0x43480000 >> 16)
    /* CFBA8 001CFBA8 00108244 */  mtc1       $2, $f2
    /* CFBAC 001CFBAC E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* CFBB0 001CFBB0 42110046 */  mul.s      $f5, $f2, $f0
    /* CFBB4 001CFBB4 F000A5E7 */  swc1       $f5, 0xF0($29)
    /* CFBB8 001CFBB8 E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* CFBBC 001CFBBC 42100046 */  mul.s      $f1, $f2, $f0
    /* CFBC0 001CFBC0 F400A1E7 */  swc1       $f1, 0xF4($29)
    /* CFBC4 001CFBC4 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* CFBC8 001CFBC8 02110046 */  mul.s      $f4, $f2, $f0
    /* CFBCC 001CFBCC F800A4E7 */  swc1       $f4, 0xF8($29)
    /* CFBD0 001CFBD0 D400A3C7 */  lwc1       $f3, 0xD4($29)
    /* CFBD4 001CFBD4 40180146 */  add.s      $f1, $f3, $f1
    /* CFBD8 001CFBD8 5C42023C */  lui        $2, (0x425C0000 >> 16)
    /* CFBDC 001CFBDC 00008244 */  mtc1       $2, $f0
    /* CFBE0 001CFBE0 00000000 */  nop
    /* CFBE4 001CFBE4 80080046 */  add.s      $f2, $f1, $f0
    /* CFBE8 001CFBE8 D000A1C7 */  lwc1       $f1, 0xD0($29)
    /* CFBEC 001CFBEC 00080546 */  add.s      $f0, $f1, $f5
    /* CFBF0 001CFBF0 01000146 */  sub.s      $f0, $f0, $f1
    /* CFBF4 001CFBF4 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* CFBF8 001CFBF8 01100346 */  sub.s      $f0, $f2, $f3
    /* CFBFC 001CFBFC E400A0E7 */  swc1       $f0, 0xE4($29)
    /* CFC00 001CFC00 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* CFC04 001CFC04 00080446 */  add.s      $f0, $f1, $f4
    /* CFC08 001CFC08 01000146 */  sub.s      $f0, $f0, $f1
    /* CFC0C 001CFC0C E800A0E7 */  swc1       $f0, 0xE8($29)
    /* CFC10 001CFC10 E000A427 */  addiu      $4, $29, 0xE0
    /* CFC14 001CFC14 2D288000 */  daddu      $5, $4, $0
    /* CFC18 001CFC18 2C900F0C */  jal        func_003e40b0
    /* CFC1C 001CFC1C 00000000 */   nop
    /* CFC20 001CFC20 900001C6 */  lwc1       $f1, 0x90($16)
    /* CFC24 001CFC24 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CFC28 001CFC28 42080046 */  mul.s      $f1, $f1, $f0
    /* CFC2C 001CFC2C 9642023C */  lui        $2, (0x42960000 >> 16)
    /* CFC30 001CFC30 00008244 */  mtc1       $2, $f0
    /* CFC34 001CFC34 00000000 */  nop
    /* CFC38 001CFC38 34080046 */  c.lt.s     $f1, $f0
    /* CFC3C 001CFC3C 02000045 */  bc1f       .L001CFC48
    /* CFC40 001CFC40 00000000 */   nop
    /* CFC44 001CFC44 46000046 */  mov.s      $f1, $f0
  .L001CFC48:
    /* CFC48 001CFC48 820D1546 */  mul.s      $f22, $f1, $f21
    /* CFC4C 001CFC4C 420D1446 */  mul.s      $f21, $f1, $f20
    /* CFC50 001CFC50 02000424 */  addiu      $4, $0, 0x2
    /* CFC54 001CFC54 5CC7080C */  jal        func_00231d70
    /* CFC58 001CFC58 00000000 */   nop
    /* CFC5C 001CFC5C 01000324 */  addiu      $3, $0, 0x1
    /* CFC60 001CFC60 09004310 */  beq        $2, $3, .L001CFC88
    /* CFC64 001CFC64 00000000 */   nop
    /* CFC68 001CFC68 03004010 */  beqz       $2, .L001CFC78
    /* CFC6C 001CFC6C 00000000 */   nop
    /* CFC70 001CFC70 05000010 */  b          .L001CFC88
    /* CFC74 001CFC74 00000000 */   nop
  .L001CFC78:
    /* CFC78 001CFC78 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* CFC7C 001CFC7C 00A08244 */  mtc1       $2, $f20
    /* CFC80 001CFC80 03000010 */  b          .L001CFC90
    /* CFC84 001CFC84 00000000 */   nop
  .L001CFC88:
    /* CFC88 001CFC88 F0C1023C */  lui        $2, (0xC1F00000 >> 16)
    /* CFC8C 001CFC8C 00A08244 */  mtc1       $2, $f20
  .L001CFC90:
    /* CFC90 001CFC90 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CFC94 001CFC94 00088244 */  mtc1       $2, $f1
    /* CFC98 001CFC98 07A00046 */  neg.s      $f0, $f20
    /* CFC9C 001CFC9C 020B0046 */  mul.s      $f12, $f1, $f0
    /* CFCA0 001CFCA0 9000A427 */  addiu      $4, $29, 0x90
    /* CFCA4 001CFCA4 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CFCA8 001CFCA8 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CFCAC 001CFCAC 2D300000 */  daddu      $6, $0, $0
    /* CFCB0 001CFCB0 1C820F0C */  jal        func_003e0870
    /* CFCB4 001CFCB4 00000000 */   nop
    /* CFCB8 001CFCB8 F000A427 */  addiu      $4, $29, 0xF0
    /* CFCBC 001CFCBC E000A527 */  addiu      $5, $29, 0xE0
    /* CFCC0 001CFCC0 9000A627 */  addiu      $6, $29, 0x90
    /* CFCC4 001CFCC4 C8900F0C */  jal        func_003e4320
    /* CFCC8 001CFCC8 00000000 */   nop
    /* CFCCC 001CFCCC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CFCD0 001CFCD0 00088244 */  mtc1       $2, $f1
    /* CFCD4 001CFCD4 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CFCD8 001CFCD8 42080046 */  mul.s      $f1, $f1, $f0
    /* CFCDC 001CFCDC 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CFCE0 001CFCE0 02030146 */  mul.s      $f12, $f0, $f1
    /* CFCE4 001CFCE4 1A2E110C */  jal        func_0044b868
    /* CFCE8 001CFCE8 00000000 */   nop
    /* CFCEC 001CFCEC 00000000 */  nop
    /* CFCF0 001CFCF0 00000000 */  nop
    /* CFCF4 001CFCF4 43B00046 */  div.s      $f1, $f22, $f0
    /* CFCF8 001CFCF8 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CFCFC 001CFCFC C2000146 */  mul.s      $f3, $f0, $f1
    /* CFD00 001CFD00 F000A3E7 */  swc1       $f3, 0xF0($29)
    /* CFD04 001CFD04 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CFD08 001CFD08 82000146 */  mul.s      $f2, $f0, $f1
    /* CFD0C 001CFD0C F400A2E7 */  swc1       $f2, 0xF4($29)
    /* CFD10 001CFD10 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CFD14 001CFD14 42000146 */  mul.s      $f1, $f0, $f1
    /* CFD18 001CFD18 F800A1E7 */  swc1       $f1, 0xF8($29)
    /* CFD1C 001CFD1C D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CFD20 001CFD20 00000346 */  add.s      $f0, $f0, $f3
    /* CFD24 001CFD24 5000A0E7 */  swc1       $f0, 0x50($29)
    /* CFD28 001CFD28 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CFD2C 001CFD2C 00000246 */  add.s      $f0, $f0, $f2
    /* CFD30 001CFD30 5400A0E7 */  swc1       $f0, 0x54($29)
    /* CFD34 001CFD34 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CFD38 001CFD38 00000146 */  add.s      $f0, $f0, $f1
    /* CFD3C 001CFD3C 5800A0E7 */  swc1       $f0, 0x58($29)
    /* CFD40 001CFD40 5C00A427 */  addiu      $4, $29, 0x5C
    /* CFD44 001CFD44 5000A527 */  addiu      $5, $29, 0x50
    /* CFD48 001CFD48 D000A627 */  addiu      $6, $29, 0xD0
    /* CFD4C 001CFD4C 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CFD50 001CFD50 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CFD54 001CFD54 E0F5060C */  jal        func_001bd780
    /* CFD58 001CFD58 00000000 */   nop
    /* CFD5C 001CFD5C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CFD60 001CFD60 00008244 */  mtc1       $2, $f0
    /* CFD64 001CFD64 00000000 */  nop
    /* CFD68 001CFD68 02031446 */  mul.s      $f12, $f0, $f20
    /* CFD6C 001CFD6C 9000A427 */  addiu      $4, $29, 0x90
    /* CFD70 001CFD70 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CFD74 001CFD74 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CFD78 001CFD78 2D300000 */  daddu      $6, $0, $0
    /* CFD7C 001CFD7C 1C820F0C */  jal        func_003e0870
    /* CFD80 001CFD80 00000000 */   nop
    /* CFD84 001CFD84 F000A427 */  addiu      $4, $29, 0xF0
    /* CFD88 001CFD88 E000A527 */  addiu      $5, $29, 0xE0
    /* CFD8C 001CFD8C 9000A627 */  addiu      $6, $29, 0x90
    /* CFD90 001CFD90 C8900F0C */  jal        func_003e4320
    /* CFD94 001CFD94 00000000 */   nop
    /* CFD98 001CFD98 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CFD9C 001CFD9C 00088244 */  mtc1       $2, $f1
    /* CFDA0 001CFDA0 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CFDA4 001CFDA4 42080046 */  mul.s      $f1, $f1, $f0
    /* CFDA8 001CFDA8 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CFDAC 001CFDAC 02030146 */  mul.s      $f12, $f0, $f1
    /* CFDB0 001CFDB0 1A2E110C */  jal        func_0044b868
    /* CFDB4 001CFDB4 00000000 */   nop
    /* CFDB8 001CFDB8 00000000 */  nop
    /* CFDBC 001CFDBC 00000000 */  nop
    /* CFDC0 001CFDC0 43A80046 */  div.s      $f1, $f21, $f0
    /* CFDC4 001CFDC4 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CFDC8 001CFDC8 C2000146 */  mul.s      $f3, $f0, $f1
    /* CFDCC 001CFDCC F000A3E7 */  swc1       $f3, 0xF0($29)
    /* CFDD0 001CFDD0 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CFDD4 001CFDD4 82000146 */  mul.s      $f2, $f0, $f1
    /* CFDD8 001CFDD8 F400A2E7 */  swc1       $f2, 0xF4($29)
    /* CFDDC 001CFDDC F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CFDE0 001CFDE0 42000146 */  mul.s      $f1, $f0, $f1
    /* CFDE4 001CFDE4 F800A1E7 */  swc1       $f1, 0xF8($29)
    /* CFDE8 001CFDE8 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CFDEC 001CFDEC 00000346 */  add.s      $f0, $f0, $f3
    /* CFDF0 001CFDF0 6C00A0E7 */  swc1       $f0, 0x6C($29)
    /* CFDF4 001CFDF4 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CFDF8 001CFDF8 00000246 */  add.s      $f0, $f0, $f2
    /* CFDFC 001CFDFC 7000A0E7 */  swc1       $f0, 0x70($29)
    /* CFE00 001CFE00 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CFE04 001CFE04 00000146 */  add.s      $f0, $f0, $f1
    /* CFE08 001CFE08 7400A0E7 */  swc1       $f0, 0x74($29)
    /* CFE0C 001CFE0C 7800A427 */  addiu      $4, $29, 0x78
    /* CFE10 001CFE10 6C00A527 */  addiu      $5, $29, 0x6C
    /* CFE14 001CFE14 D000A627 */  addiu      $6, $29, 0xD0
    /* CFE18 001CFE18 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CFE1C 001CFE1C E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CFE20 001CFE20 E0F5060C */  jal        func_001bd780
    /* CFE24 001CFE24 00000000 */   nop
    /* CFE28 001CFE28 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* CFE2C 001CFE2C C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CFE30 001CFE30 00008244 */  mtc1       $2, $f0
    /* CFE34 001CFE34 00000000 */  nop
    /* CFE38 001CFE38 34080046 */  c.lt.s     $f1, $f0
    /* CFE3C 001CFE3C 02000045 */  bc1f       .L001CFE48
    /* CFE40 001CFE40 00000000 */   nop
    /* CFE44 001CFE44 5400A0E7 */  swc1       $f0, 0x54($29)
  .L001CFE48:
    /* CFE48 001CFE48 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* CFE4C 001CFE4C C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CFE50 001CFE50 00008244 */  mtc1       $2, $f0
    /* CFE54 001CFE54 00000000 */  nop
    /* CFE58 001CFE58 34080046 */  c.lt.s     $f1, $f0
    /* CFE5C 001CFE5C 02000045 */  bc1f       .L001CFE68
    /* CFE60 001CFE60 00000000 */   nop
    /* CFE64 001CFE64 7000A0E7 */  swc1       $f0, 0x70($29)
  .L001CFE68:
    /* CFE68 001CFE68 2D200002 */  daddu      $4, $16, $0
    /* CFE6C 001CFE6C FCDC060C */  jal        func_001b73f0
    /* CFE70 001CFE70 00000000 */   nop
    /* CFE74 001CFE74 2D202002 */  daddu      $4, $17, $0
    /* CFE78 001CFE78 5000A527 */  addiu      $5, $29, 0x50
    /* CFE7C 001CFE7C 6C00A627 */  addiu      $6, $29, 0x6C
    /* CFE80 001CFE80 01000724 */  addiu      $7, $0, 0x1
    /* CFE84 001CFE84 08EB060C */  jal        func_001bac20
    /* CFE88 001CFE88 00000000 */   nop
    /* CFE8C 001CFE8C 4040023C */  lui        $2, (0x40400000 >> 16)
    /* CFE90 001CFE90 00608244 */  mtc1       $2, $f12
    /* CFE94 001CFE94 2D202002 */  daddu      $4, $17, $0
    /* CFE98 001CFE98 BCEF060C */  jal        func_001bbef0
    /* CFE9C 001CFE9C 00000000 */   nop
    /* CFEA0 001CFEA0 4000BFDF */  ld         $31, 0x40($29)
    /* CFEA4 001CFEA4 3000B27B */  lq         $18, 0x30($29)
    /* CFEA8 001CFEA8 2000B17B */  lq         $17, 0x20($29)
    /* CFEAC 001CFEAC 1000B07B */  lq         $16, 0x10($29)
    /* CFEB0 001CFEB0 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* CFEB4 001CFEB4 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CFEB8 001CFEB8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CFEBC 001CFEBC 0001BD27 */  addiu      $29, $29, 0x100
    /* CFEC0 001CFEC0 0800E003 */  jr         $31
    /* CFEC4 001CFEC4 00000000 */   nop
    /* CFEC8 001CFEC8 00000000 */  nop
    /* CFECC 001CFECC 00000000 */  nop
.size func_001cfad0, 0x400
