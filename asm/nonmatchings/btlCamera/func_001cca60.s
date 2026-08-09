.section .text
.set noat
.set noreorder
glabel func_001cca60
    /* CCA60 001CCA60 70FFBD27 */  addiu      $29, $29, -0x90
    /* CCA64 001CCA64 3000BFFF */  sd         $31, 0x30($29)
    /* CCA68 001CCA68 2000B17F */  sq         $17, 0x20($29)
    /* CCA6C 001CCA6C 1000B07F */  sq         $16, 0x10($29)
    /* CCA70 001CCA70 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CCA74 001CCA74 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CCA78 001CCA78 2D888000 */  daddu      $17, $4, $0
    /* CCA7C 001CCA7C E000828C */  lw         $2, 0xE0($4)
    /* CCA80 001CCA80 04004010 */  beqz       $2, .L001CCA94
    /* CCA84 001CCA84 00000000 */   nop
    /* CCA88 001CCA88 3000508C */  lw         $16, 0x30($2)
    /* CCA8C 001CCA8C 04000010 */  b          .L001CCAA0
    /* CCA90 001CCA90 00000000 */   nop
  .L001CCA94:
    /* CCA94 001CCA94 ACB3828F */  lw         $2, -0x4C54($28)
    /* CCA98 001CCA98 7001428C */  lw         $2, 0x170($2)
    /* CCA9C 001CCA9C 3000508C */  lw         $16, 0x30($2)
  .L001CCAA0:
    /* CCAA0 001CCAA0 03000424 */  addiu      $4, $0, 0x3
    /* CCAA4 001CCAA4 01000524 */  addiu      $5, $0, 0x1
    /* CCAA8 001CCAA8 8000A627 */  addiu      $6, $29, 0x80
    /* CCAAC 001CCAAC 8C00A727 */  addiu      $7, $29, 0x8C
    /* CCAB0 001CCAB0 2D400000 */  daddu      $8, $0, $0
    /* CCAB4 001CCAB4 2D48A000 */  daddu      $9, $5, $0
    /* CCAB8 001CCAB8 1058060C */  jal        func_00196040
    /* CCABC 001CCABC 00000000 */   nop
    /* CCAC0 001CCAC0 06050046 */  mov.s      $f20, $f0
    /* CCAC4 001CCAC4 2D200002 */  daddu      $4, $16, $0
    /* CCAC8 001CCAC8 7000A527 */  addiu      $5, $29, 0x70
    /* CCACC 001CCACC 3C56060C */  jal        func_001958f0
    /* CCAD0 001CCAD0 00000000 */   nop
    /* CCAD4 001CCAD4 8400A0AF */  sw         $0, 0x84($29)
    /* CCAD8 001CCAD8 7400A0AF */  sw         $0, 0x74($29)
    /* CCADC 001CCADC 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* CCAE0 001CCAE0 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* CCAE4 001CCAE4 32080046 */  c.eq.s     $f1, $f0
    /* CCAE8 001CCAE8 0D000045 */  bc1f       .L001CCB20
    /* CCAEC 001CCAEC 00000000 */   nop
    /* CCAF0 001CCAF0 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* CCAF4 001CCAF4 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CCAF8 001CCAF8 32080046 */  c.eq.s     $f1, $f0
    /* CCAFC 001CCAFC 08000045 */  bc1f       .L001CCB20
    /* CCB00 001CCB00 00000000 */   nop
    /* CCB04 001CCB04 ACB3828F */  lw         $2, -0x4C54($28)
    /* CCB08 001CCB08 7001428C */  lw         $2, 0x170($2)
    /* CCB0C 001CCB0C 3000448C */  lw         $4, 0x30($2)
    /* CCB10 001CCB10 7000A527 */  addiu      $5, $29, 0x70
    /* CCB14 001CCB14 3C56060C */  jal        func_001958f0
    /* CCB18 001CCB18 00000000 */   nop
    /* CCB1C 001CCB1C 7400A0AF */  sw         $0, 0x74($29)
  .L001CCB20:
    /* CCB20 001CCB20 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* CCB24 001CCB24 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* CCB28 001CCB28 01080046 */  sub.s      $f0, $f1, $f0
    /* CCB2C 001CCB2C 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CCB30 001CCB30 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* CCB34 001CCB34 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* CCB38 001CCB38 01080046 */  sub.s      $f0, $f1, $f0
    /* CCB3C 001CCB3C 6400A0E7 */  swc1       $f0, 0x64($29)
    /* CCB40 001CCB40 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* CCB44 001CCB44 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CCB48 001CCB48 01080046 */  sub.s      $f0, $f1, $f0
    /* CCB4C 001CCB4C 6800A0E7 */  swc1       $f0, 0x68($29)
    /* CCB50 001CCB50 6000A427 */  addiu      $4, $29, 0x60
    /* CCB54 001CCB54 2D288000 */  daddu      $5, $4, $0
    /* CCB58 001CCB58 2C900F0C */  jal        func_003e40b0
    /* CCB5C 001CCB5C 00000000 */   nop
    /* CCB60 001CCB60 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* CCB64 001CCB64 C2001446 */  mul.s      $f3, $f0, $f20
    /* CCB68 001CCB68 6000A3E7 */  swc1       $f3, 0x60($29)
    /* CCB6C 001CCB6C 6400A0C7 */  lwc1       $f0, 0x64($29)
    /* CCB70 001CCB70 82001446 */  mul.s      $f2, $f0, $f20
    /* CCB74 001CCB74 6400A2E7 */  swc1       $f2, 0x64($29)
    /* CCB78 001CCB78 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* CCB7C 001CCB7C 42001446 */  mul.s      $f1, $f0, $f20
    /* CCB80 001CCB80 6800A1E7 */  swc1       $f1, 0x68($29)
    /* CCB84 001CCB84 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* CCB88 001CCB88 00000346 */  add.s      $f0, $f0, $f3
    /* CCB8C 001CCB8C 7000A0E7 */  swc1       $f0, 0x70($29)
    /* CCB90 001CCB90 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* CCB94 001CCB94 00000246 */  add.s      $f0, $f0, $f2
    /* CCB98 001CCB98 7400A0E7 */  swc1       $f0, 0x74($29)
    /* CCB9C 001CCB9C 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CCBA0 001CCBA0 00000146 */  add.s      $f0, $f0, $f1
    /* CCBA4 001CCBA4 7800A0E7 */  swc1       $f0, 0x78($29)
    /* CCBA8 001CCBA8 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* CCBAC 001CCBAC 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CCBB0 001CCBB0 42080046 */  mul.s      $f1, $f1, $f0
    /* CCBB4 001CCBB4 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* CCBB8 001CCBB8 00008244 */  mtc1       $2, $f0
    /* CCBBC 001CCBBC 00000000 */  nop
    /* CCBC0 001CCBC0 82000146 */  mul.s      $f2, $f0, $f1
    /* CCBC4 001CCBC4 708181C7 */  lwc1       $f1, -0x7E90($28)
    /* CCBC8 001CCBC8 8C00A0C7 */  lwc1       $f0, 0x8C($29)
    /* CCBCC 001CCBCC 02080046 */  mul.s      $f0, $f1, $f0
    /* CCBD0 001CCBD0 36000246 */  c.le.s     $f0, $f2
    /* CCBD4 001CCBD4 03000145 */  bc1t       .L001CCBE4
    /* CCBD8 001CCBD8 00000000 */   nop
    /* CCBDC 001CCBDC 02000010 */  b          .L001CCBE8
    /* CCBE0 001CCBE0 00000000 */   nop
  .L001CCBE4:
    /* CCBE4 001CCBE4 06100046 */  mov.s      $f0, $f2
  .L001CCBE8:
    /* CCBE8 001CCBE8 7400A0E7 */  swc1       $f0, 0x74($29)
    /* CCBEC 001CCBEC 4C00A427 */  addiu      $4, $29, 0x4C
    /* CCBF0 001CCBF0 7000A527 */  addiu      $5, $29, 0x70
    /* CCBF4 001CCBF4 8000A627 */  addiu      $6, $29, 0x80
    /* CCBF8 001CCBF8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CCBFC 001CCBFC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CCC00 001CCC00 E0F5060C */  jal        func_001bd780
    /* CCC04 001CCC04 00000000 */   nop
    /* CCC08 001CCC08 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CCC0C 001CCC0C 00088244 */  mtc1       $2, $f1
    /* CCC10 001CCC10 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CCC14 001CCC14 42080046 */  mul.s      $f1, $f1, $f0
    /* CCC18 001CCC18 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CCC1C 001CCC1C 02030146 */  mul.s      $f12, $f0, $f1
    /* CCC20 001CCC20 1A2E110C */  jal        func_0044b868
    /* CCC24 001CCC24 00000000 */   nop
    /* CCC28 001CCC28 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* CCC2C 001CCC2C 00088244 */  mtc1       $2, $f1
    /* CCC30 001CCC30 00000000 */  nop
    /* CCC34 001CCC34 42081446 */  mul.s      $f1, $f1, $f20
    /* CCC38 001CCC38 030D0046 */  div.s      $f20, $f1, $f0
    /* CCC3C 001CCC3C 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* CCC40 001CCC40 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* CCC44 001CCC44 01080046 */  sub.s      $f0, $f1, $f0
    /* CCC48 001CCC48 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CCC4C 001CCC4C 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* CCC50 001CCC50 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* CCC54 001CCC54 01080046 */  sub.s      $f0, $f1, $f0
    /* CCC58 001CCC58 6400A0E7 */  swc1       $f0, 0x64($29)
    /* CCC5C 001CCC5C 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* CCC60 001CCC60 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CCC64 001CCC64 01080046 */  sub.s      $f0, $f1, $f0
    /* CCC68 001CCC68 6800A0E7 */  swc1       $f0, 0x68($29)
    /* CCC6C 001CCC6C 6000A427 */  addiu      $4, $29, 0x60
    /* CCC70 001CCC70 2D288000 */  daddu      $5, $4, $0
    /* CCC74 001CCC74 2C900F0C */  jal        func_003e40b0
    /* CCC78 001CCC78 00000000 */   nop
    /* CCC7C 001CCC7C 46050046 */  mov.s      $f21, $f0
    /* CCC80 001CCC80 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CCC84 001CCC84 00088244 */  mtc1       $2, $f1
    /* CCC88 001CCC88 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CCC8C 001CCC8C 42080046 */  mul.s      $f1, $f1, $f0
    /* CCC90 001CCC90 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CCC94 001CCC94 02030146 */  mul.s      $f12, $f0, $f1
    /* CCC98 001CCC98 1A2E110C */  jal        func_0044b868
    /* CCC9C 001CCC9C 00000000 */   nop
    /* CCCA0 001CCCA0 900002C6 */  lwc1       $f2, 0x90($16)
    /* CCCA4 001CCCA4 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* CCCA8 001CCCA8 82100146 */  mul.s      $f2, $f2, $f1
    /* CCCAC 001CCCAC 0040023C */  lui        $2, (0x40000000 >> 16)
    /* CCCB0 001CCCB0 00088244 */  mtc1       $2, $f1
    /* CCCB4 001CCCB4 00000000 */  nop
    /* CCCB8 001CCCB8 42080246 */  mul.s      $f1, $f1, $f2
    /* CCCBC 001CCCBC 03080046 */  div.s      $f0, $f1, $f0
    /* CCCC0 001CCCC0 00000000 */  nop
    /* CCCC4 001CCCC4 00A80046 */  add.s      $f0, $f21, $f0
    /* CCCC8 001CCCC8 36A00046 */  c.le.s     $f20, $f0
    /* CCCCC 001CCCCC 03000145 */  bc1t       .L001CCCDC
    /* CCCD0 001CCCD0 00000000 */   nop
    /* CCCD4 001CCCD4 02000010 */  b          .L001CCCE0
    /* CCCD8 001CCCD8 00000000 */   nop
  .L001CCCDC:
    /* CCCDC 001CCCDC 06050046 */  mov.s      $f20, $f0
  .L001CCCE0:
    /* CCCE0 001CCCE0 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* CCCE4 001CCCE4 C2001446 */  mul.s      $f3, $f0, $f20
    /* CCCE8 001CCCE8 6000A3E7 */  swc1       $f3, 0x60($29)
    /* CCCEC 001CCCEC 6400A0C7 */  lwc1       $f0, 0x64($29)
    /* CCCF0 001CCCF0 82001446 */  mul.s      $f2, $f0, $f20
    /* CCCF4 001CCCF4 6400A2E7 */  swc1       $f2, 0x64($29)
    /* CCCF8 001CCCF8 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* CCCFC 001CCCFC 42001446 */  mul.s      $f1, $f0, $f20
    /* CCD00 001CCD00 6800A1E7 */  swc1       $f1, 0x68($29)
    /* CCD04 001CCD04 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* CCD08 001CCD08 00180046 */  add.s      $f0, $f3, $f0
    /* CCD0C 001CCD0C 4000A0E7 */  swc1       $f0, 0x40($29)
    /* CCD10 001CCD10 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* CCD14 001CCD14 00100046 */  add.s      $f0, $f2, $f0
    /* CCD18 001CCD18 4400A0E7 */  swc1       $f0, 0x44($29)
    /* CCD1C 001CCD1C 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CCD20 001CCD20 00080046 */  add.s      $f0, $f1, $f0
    /* CCD24 001CCD24 4800A0E7 */  swc1       $f0, 0x48($29)
    /* CCD28 001CCD28 4000A427 */  addiu      $4, $29, 0x40
    /* CCD2C 001CCD2C 2D288000 */  daddu      $5, $4, $0
    /* CCD30 001CCD30 E8F0060C */  jal        func_001bc3a0
    /* CCD34 001CCD34 00000000 */   nop
    /* CCD38 001CCD38 00608044 */  mtc1       $0, $f12
    /* CCD3C 001CCD3C 2D200000 */  daddu      $4, $0, $0
    /* CCD40 001CCD40 2D280000 */  daddu      $5, $0, $0
    /* CCD44 001CCD44 2D300000 */  daddu      $6, $0, $0
    /* CCD48 001CCD48 00010724 */  addiu      $7, $0, 0x100
    /* CCD4C 001CCD4C 50F3060C */  jal        func_001bcd40
    /* CCD50 001CCD50 00000000 */   nop
    /* CCD54 001CCD54 2D202002 */  daddu      $4, $17, $0
    /* CCD58 001CCD58 4000A527 */  addiu      $5, $29, 0x40
    /* CCD5C 001CCD5C C0EA060C */  jal        func_001bab00
    /* CCD60 001CCD60 00000000 */   nop
    /* CCD64 001CCD64 9C002426 */  addiu      $4, $17, 0x9C
    /* CCD68 001CCD68 4000A527 */  addiu      $5, $29, 0x40
    /* CCD6C 001CCD6C 68F5060C */  jal        func_001bd5a0
    /* CCD70 001CCD70 00000000 */   nop
    /* CCD74 001CCD74 3000BFDF */  ld         $31, 0x30($29)
    /* CCD78 001CCD78 2000B17B */  lq         $17, 0x20($29)
    /* CCD7C 001CCD7C 1000B07B */  lq         $16, 0x10($29)
    /* CCD80 001CCD80 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CCD84 001CCD84 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CCD88 001CCD88 9000BD27 */  addiu      $29, $29, 0x90
    /* CCD8C 001CCD8C 0800E003 */  jr         $31
    /* CCD90 001CCD90 00000000 */   nop
    /* CCD94 001CCD94 00000000 */  nop
    /* CCD98 001CCD98 00000000 */  nop
    /* CCD9C 001CCD9C 00000000 */  nop
.size func_001cca60, 0x340
