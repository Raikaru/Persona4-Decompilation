.section .text
.set noat
.set noreorder
glabel func_0042acf8
    /* 32ACF8 0042ACF8 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 32ACFC 0042ACFC 4000B3FF */  sd         $19, 0x40($29)
    /* 32AD00 0042AD00 3000B2FF */  sd         $18, 0x30($29)
    /* 32AD04 0042AD04 2D988000 */  daddu      $19, $4, $0
    /* 32AD08 0042AD08 1000B0FF */  sd         $16, 0x10($29)
    /* 32AD0C 0042AD0C 2D90A000 */  daddu      $18, $5, $0
    /* 32AD10 0042AD10 5000BFFF */  sd         $31, 0x50($29)
    /* 32AD14 0042AD14 2D80C000 */  daddu      $16, $6, $0
    /* 32AD18 0042AD18 5AA8100C */  jal        func_0042a168
    /* 32AD1C 0042AD1C 2000B1FF */   sd        $17, 0x20($29)
    /* 32AD20 0042AD20 03004104 */  bgez       $2, .L0042AD30
    /* 32AD24 0042AD24 0300022E */   sltiu     $2, $16, 0x3
    /* 32AD28 0042AD28 27000010 */  b          .L0042ADC8
    /* 32AD2C 0042AD2C FFFF023C */   lui       $2, (0xFFFF0000 >> 16)
  .L0042AD30:
    /* 32AD30 0042AD30 20004010 */  beqz       $2, .L0042ADB4
    /* 32AD34 0042AD34 8900113C */   lui       $17, %hi(D_00891140)
    /* 32AD38 0042AD38 8900043C */  lui        $4, %hi(D_00891340)
    /* 32AD3C 0042AD3C 40112226 */  addiu      $2, $17, %lo(D_00891140)
    /* 32AD40 0042AD40 401133AE */  sw         $19, %lo(D_00891140)($17)
    /* 32AD44 0042AD44 2D384000 */  daddu      $7, $2, $0
    /* 32AD48 0042AD48 040050AC */  sw         $16, 0x4($2)
    /* 32AD4C 0042AD4C 40138424 */  addiu      $4, $4, %lo(D_00891340)
    /* 32AD50 0042AD50 03000524 */  addiu      $5, $0, 0x3
    /* 32AD54 0042AD54 0000A0AF */  sw         $0, 0x0($29)
    /* 32AD58 0042AD58 2D300000 */  daddu      $6, $0, $0
    /* 32AD5C 0042AD5C 20000824 */  addiu      $8, $0, 0x20
    /* 32AD60 0042AD60 2D48E000 */  daddu      $9, $7, $0
    /* 32AD64 0042AD64 20000A24 */  addiu      $10, $0, 0x20
    /* 32AD68 0042AD68 2C96100C */  jal        func_004258b0
    /* 32AD6C 0042AD6C 2D580000 */   daddu     $11, $0, $0
    /* 32AD70 0042AD70 04004104 */  bgez       $2, .L0042AD84
    /* 32AD74 0042AD74 00000000 */   nop
    /* 32AD78 0042AD78 FEFF023C */  lui        $2, (0xFFFEFFFF >> 16)
    /* 32AD7C 0042AD7C 12000010 */  b          .L0042ADC8
    /* 32AD80 0042AD80 FFFF4234 */   ori       $2, $2, (0xFFFEFFFF & 0xFFFF)
  .L0042AD84:
    /* 32AD84 0042AD84 04000016 */  bnez       $16, .L0042AD98
    /* 32AD88 0042AD88 01000224 */   addiu     $2, $0, 0x1
    /* 32AD8C 0042AD8C 40112292 */  lbu        $2, %lo(D_00891140)($17)
    /* 32AD90 0042AD90 0C000010 */  b          .L0042ADC4
    /* 32AD94 0042AD94 000042A2 */   sb        $2, 0x0($18)
  .L0042AD98:
    /* 32AD98 0042AD98 04000216 */  bne        $16, $2, .L0042ADAC
    /* 32AD9C 0042AD9C 02000224 */   addiu     $2, $0, 0x2
    /* 32ADA0 0042ADA0 40112296 */  lhu        $2, %lo(D_00891140)($17)
    /* 32ADA4 0042ADA4 07000010 */  b          .L0042ADC4
    /* 32ADA8 0042ADA8 000042A6 */   sh        $2, 0x0($18)
  .L0042ADAC:
    /* 32ADAC 0042ADAC 04000252 */  beql       $16, $2, .L0042ADC0
    /* 32ADB0 0042ADB0 4011228E */   lw        $2, %lo(D_00891140)($17)
  .L0042ADB4:
    /* 32ADB4 0042ADB4 FEFF023C */  lui        $2, (0xFFFEFFFE >> 16)
    /* 32ADB8 0042ADB8 03000010 */  b          .L0042ADC8
    /* 32ADBC 0042ADBC FEFF4234 */   ori       $2, $2, (0xFFFEFFFE & 0xFFFF)
  .L0042ADC0:
    /* 32ADC0 0042ADC0 000042AE */  sw         $2, 0x0($18)
  .L0042ADC4:
    /* 32ADC4 0042ADC4 2D100000 */  daddu      $2, $0, $0
  .L0042ADC8:
    /* 32ADC8 0042ADC8 5000BFDF */  ld         $31, 0x50($29)
    /* 32ADCC 0042ADCC 4000B3DF */  ld         $19, 0x40($29)
    /* 32ADD0 0042ADD0 3000B2DF */  ld         $18, 0x30($29)
    /* 32ADD4 0042ADD4 2000B1DF */  ld         $17, 0x20($29)
    /* 32ADD8 0042ADD8 1000B0DF */  ld         $16, 0x10($29)
    /* 32ADDC 0042ADDC 0800E003 */  jr         $31
    /* 32ADE0 0042ADE0 6000BD27 */   addiu     $29, $29, 0x60
    /* 32ADE4 0042ADE4 00000000 */  nop
.size func_0042acf8, 0xf0
