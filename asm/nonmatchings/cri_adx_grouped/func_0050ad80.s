.section .text
.set noat
.set noreorder
glabel func_0050ad80
    /* 40AD80 0050AD80 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 40AD84 0050AD84 FFFF0224 */  addiu      $2, $0, -0x1
    /* 40AD88 0050AD88 3800B5FF */  sd         $21, 0x38($29)
    /* 40AD8C 0050AD8C 2DA8A000 */  daddu      $21, $5, $0
    /* 40AD90 0050AD90 1800B1FF */  sd         $17, 0x18($29)
    /* 40AD94 0050AD94 2D88C000 */  daddu      $17, $6, $0
    /* 40AD98 0050AD98 0008A32A */  slti       $3, $21, 0x800
    /* 40AD9C 0050AD9C 2800B3FF */  sd         $19, 0x28($29)
    /* 40ADA0 0050ADA0 1000B0FF */  sd         $16, 0x10($29)
    /* 40ADA4 0050ADA4 2D988000 */  daddu      $19, $4, $0
    /* 40ADA8 0050ADA8 2000B2FF */  sd         $18, 0x20($29)
    /* 40ADAC 0050ADAC 3000B4FF */  sd         $20, 0x30($29)
    /* 40ADB0 0050ADB0 4000B6FF */  sd         $22, 0x40($29)
    /* 40ADB4 0050ADB4 4800B7FF */  sd         $23, 0x48($29)
    /* 40ADB8 0050ADB8 5000BFFF */  sd         $31, 0x50($29)
    /* 40ADBC 0050ADBC 2F006014 */  bnez       $3, .L0050AE7C
    /* 40ADC0 0050ADC0 140022AE */   sw        $2, 0x14($17)
    /* 40ADC4 0050ADC4 2D006012 */  beqz       $19, .L0050AE7C
    /* 40ADC8 0050ADC8 02001424 */   addiu     $20, $0, 0x2
    /* 40ADCC 0050ADCC 01001724 */  addiu      $23, $0, 0x1
    /* 40ADD0 0050ADD0 FFFF1624 */  addiu      $22, $0, -0x1
    /* 40ADD4 0050ADD4 00081224 */  addiu      $18, $0, 0x800
    /* 40ADD8 0050ADD8 21207202 */  addu       $4, $19, $18
    /* 40ADDC 0050ADDC 00000000 */  nop
  .L0050ADE0:
    /* 40ADE0 0050ADE0 4AA3140C */  jal        func_00528d28
    /* 40ADE4 0050ADE4 2328B202 */   subu      $5, $21, $18
    /* 40ADE8 0050ADE8 00085226 */  addiu      $18, $18, 0x800
    /* 40ADEC 0050ADEC 2D804000 */  daddu      $16, $2, $0
    /* 40ADF0 0050ADF0 2D28A003 */  daddu      $5, $29, $0
    /* 40ADF4 0050ADF4 1D000012 */  beqz       $16, .L0050AE6C
    /* 40ADF8 0050ADF8 2D200002 */   daddu     $4, $16, $0
    /* 40ADFC 0050ADFC D0A3140C */  jal        func_00528f40
    /* 40AE00 0050AE00 00000000 */   nop
    /* 40AE04 0050AE04 2D184000 */  daddu      $3, $2, $0
    /* 40AE08 0050AE08 15007714 */  bne        $3, $23, .L0050AE60
    /* 40AE0C 0050AE0C 2D200002 */   daddu     $4, $16, $0
    /* 40AE10 0050AE10 0000A28F */  lw         $2, 0x0($29)
    /* 40AE14 0050AE14 13004354 */  bnel       $2, $3, .L0050AE64
    /* 40AE18 0050AE18 140036AE */   sw        $22, 0x14($17)
    /* 40AE1C 0050AE1C 542B140C */  jal        func_0050ad50
    /* 40AE20 0050AE20 00000000 */   nop
    /* 40AE24 0050AE24 2D200002 */  daddu      $4, $16, $0
    /* 40AE28 0050AE28 BA2B140C */  jal        func_0050aee8
    /* 40AE2C 0050AE2C 140022AE */   sw        $2, 0x14($17)
    /* 40AE30 0050AE30 2D200002 */  daddu      $4, $16, $0
    /* 40AE34 0050AE34 E22B140C */  jal        func_0050af88
    /* 40AE38 0050AE38 180022AE */   sw        $2, 0x18($17)
    /* 40AE3C 0050AE3C 2D200002 */  daddu      $4, $16, $0
    /* 40AE40 0050AE40 D62B140C */  jal        func_0050af58
    /* 40AE44 0050AE44 1C0022AE */   sw        $2, 0x1C($17)
    /* 40AE48 0050AE48 2D200002 */  daddu      $4, $16, $0
    /* 40AE4C 0050AE4C 7CA3140C */  jal        func_00528df0
    /* 40AE50 0050AE50 200022AE */   sw        $2, 0x20($17)
    /* 40AE54 0050AE54 0A000010 */  b          .L0050AE80
    /* 40AE58 0050AE58 1000B0DF */   ld        $16, 0x10($29)
    /* 40AE5C 0050AE5C 00000000 */  nop
  .L0050AE60:
    /* 40AE60 0050AE60 140036AE */  sw         $22, 0x14($17)
  .L0050AE64:
    /* 40AE64 0050AE64 7CA3140C */  jal        func_00528df0
    /* 40AE68 0050AE68 180036AE */   sw        $22, 0x18($17)
  .L0050AE6C:
    /* 40AE6C 0050AE6C 01009426 */  addiu      $20, $20, 0x1
    /* 40AE70 0050AE70 0400822A */  slti       $2, $20, 0x4
    /* 40AE74 0050AE74 DAFF4014 */  bnez       $2, .L0050ADE0
    /* 40AE78 0050AE78 21207202 */   addu      $4, $19, $18
  .L0050AE7C:
    /* 40AE7C 0050AE7C 1000B0DF */  ld         $16, 0x10($29)
  .L0050AE80:
    /* 40AE80 0050AE80 1800B1DF */  ld         $17, 0x18($29)
    /* 40AE84 0050AE84 2000B2DF */  ld         $18, 0x20($29)
    /* 40AE88 0050AE88 2800B3DF */  ld         $19, 0x28($29)
    /* 40AE8C 0050AE8C 3000B4DF */  ld         $20, 0x30($29)
    /* 40AE90 0050AE90 3800B5DF */  ld         $21, 0x38($29)
    /* 40AE94 0050AE94 4000B6DF */  ld         $22, 0x40($29)
    /* 40AE98 0050AE98 4800B7DF */  ld         $23, 0x48($29)
    /* 40AE9C 0050AE9C 5000BFDF */  ld         $31, 0x50($29)
    /* 40AEA0 0050AEA0 0800E003 */  jr         $31
    /* 40AEA4 0050AEA4 6000BD27 */   addiu     $29, $29, 0x60
.size func_0050ad80, 0x128
