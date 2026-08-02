.section .text
.set noat
.set noreorder
glabel func_0047ac90
    /* 37AC90 0047AC90 90FEBD27 */  addiu      $29, $29, -0x170
    /* 37AC94 0047AC94 6000BFFF */  sd         $31, 0x60($29)
    /* 37AC98 0047AC98 5000B57F */  sq         $21, 0x50($29)
    /* 37AC9C 0047AC9C 4000B47F */  sq         $20, 0x40($29)
    /* 37ACA0 0047ACA0 3000B37F */  sq         $19, 0x30($29)
    /* 37ACA4 0047ACA4 2000B27F */  sq         $18, 0x20($29)
    /* 37ACA8 0047ACA8 1000B17F */  sq         $17, 0x10($29)
    /* 37ACAC 0047ACAC 0000B07F */  sq         $16, 0x0($29)
    /* 37ACB0 0047ACB0 2D908000 */  daddu      $18, $4, $0
    /* 37ACB4 0047ACB4 2D88A000 */  daddu      $17, $5, $0
    /* 37ACB8 0047ACB8 2DA8C000 */  daddu      $21, $6, $0
    /* 37ACBC 0047ACBC 2DA0E000 */  daddu      $20, $7, $0
    /* 37ACC0 0047ACC0 2D980001 */  daddu      $19, $8, $0
    /* 37ACC4 0047ACC4 2D20A002 */  daddu      $4, $21, $0
    /* 37ACC8 0047ACC8 2D288002 */  daddu      $5, $20, $0
    /* 37ACCC 0047ACCC 2D300000 */  daddu      $6, $0, $0
    /* 37ACD0 0047ACD0 10DF110C */  jal        func_00477c40
    /* 37ACD4 0047ACD4 00000000 */   nop
    /* 37ACD8 0047ACD8 19004014 */  bnez       $2, .L0047AD40
    /* 37ACDC 0047ACDC 00000000 */   nop
    /* 37ACE0 0047ACE0 2D20A002 */  daddu      $4, $21, $0
    /* 37ACE4 0047ACE4 2D288002 */  daddu      $5, $20, $0
    /* 37ACE8 0047ACE8 7000A627 */  addiu      $6, $29, 0x70
    /* 37ACEC 0047ACEC 44F4110C */  jal        func_0047d110
    /* 37ACF0 0047ACF0 00000000 */   nop
    /* 37ACF4 0047ACF4 2D20A002 */  daddu      $4, $21, $0
    /* 37ACF8 0047ACF8 2D288002 */  daddu      $5, $20, $0
    /* 37ACFC 0047ACFC 7000A627 */  addiu      $6, $29, 0x70
    /* 37AD00 0047AD00 2D386002 */  daddu      $7, $19, $0
    /* 37AD04 0047AD04 A0DF110C */  jal        func_00477e80
    /* 37AD08 0047AD08 00000000 */   nop
    /* 37AD0C 0047AD0C 2D804000 */  daddu      $16, $2, $0
    /* 37AD10 0047AD10 2D20A002 */  daddu      $4, $21, $0
    /* 37AD14 0047AD14 2D288002 */  daddu      $5, $20, $0
    /* 37AD18 0047AD18 38F4110C */  jal        func_0047d0e0
    /* 37AD1C 0047AD1C 00000000 */   nop
    /* 37AD20 0047AD20 05004010 */  beqz       $2, .L0047AD38
    /* 37AD24 0047AD24 00000000 */   nop
    /* 37AD28 0047AD28 2D200002 */  daddu      $4, $16, $0
    /* 37AD2C 0047AD2C 01000524 */  addiu      $5, $0, 0x1
    /* 37AD30 0047AD30 14EC110C */  jal        func_0047b050
    /* 37AD34 0047AD34 00000000 */   nop
  .L0047AD38:
    /* 37AD38 0047AD38 12000010 */  b          .L0047AD84
    /* 37AD3C 0047AD3C 00000000 */   nop
  .L0047AD40:
    /* 37AD40 0047AD40 2D20A002 */  daddu      $4, $21, $0
    /* 37AD44 0047AD44 2D288002 */  daddu      $5, $20, $0
    /* 37AD48 0047AD48 6CDE110C */  jal        func_004779b0
    /* 37AD4C 0047AD4C 00000000 */   nop
    /* 37AD50 0047AD50 2D804000 */  daddu      $16, $2, $0
    /* 37AD54 0047AD54 01006232 */  andi       $2, $19, 0x1
    /* 37AD58 0047AD58 04004010 */  beqz       $2, .L0047AD6C
    /* 37AD5C 0047AD5C 00000000 */   nop
    /* 37AD60 0047AD60 D800028E */  lw         $2, 0xD8($16)
    /* 37AD64 0047AD64 00404234 */  ori        $2, $2, 0x4000
    /* 37AD68 0047AD68 D80002AE */  sw         $2, 0xD8($16)
  .L0047AD6C:
    /* 37AD6C 0047AD6C D800028E */  lw         $2, 0xD8($16)
    /* 37AD70 0047AD70 00204234 */  ori        $2, $2, 0x2000
    /* 37AD74 0047AD74 D80002AE */  sw         $2, 0xD8($16)
    /* 37AD78 0047AD78 2D200002 */  daddu      $4, $16, $0
    /* 37AD7C 0047AD7C ACE0110C */  jal        func_004782b0
    /* 37AD80 0047AD80 00000000 */   nop
  .L0047AD84:
    /* 37AD84 0047AD84 FFFF2432 */  andi       $4, $17, 0xFFFF
    /* 37AD88 0047AD88 40180400 */  sll        $3, $4, 1
    /* 37AD8C 0047AD8C 21186400 */  addu       $3, $3, $4
    /* 37AD90 0047AD90 80180300 */  sll        $3, $3, 2
    /* 37AD94 0047AD94 21287200 */  addu       $5, $3, $18
    /* 37AD98 0047AD98 9002B0AC */  sw         $16, 0x290($5)
    /* 37AD9C 0047AD9C D800038E */  lw         $3, 0xD8($16)
    /* 37ADA0 0047ADA0 04006334 */  ori        $3, $3, 0x4
    /* 37ADA4 0047ADA4 D80003AE */  sw         $3, 0xD8($16)
    /* 37ADA8 0047ADA8 9002A48C */  lw         $4, 0x290($5)
    /* 37ADAC 0047ADAC D800838C */  lw         $3, 0xD8($4)
    /* 37ADB0 0047ADB0 00806334 */  ori        $3, $3, 0x8000
    /* 37ADB4 0047ADB4 D80083AC */  sw         $3, 0xD8($4)
    /* 37ADB8 0047ADB8 8C02A390 */  lbu        $3, 0x28C($5)
    /* 37ADBC 0047ADBC 01006334 */  ori        $3, $3, 0x1
    /* 37ADC0 0047ADC0 8C02A3A0 */  sb         $3, 0x28C($5)
    /* 37ADC4 0047ADC4 6000BFDF */  ld         $31, 0x60($29)
    /* 37ADC8 0047ADC8 5000B57B */  lq         $21, 0x50($29)
    /* 37ADCC 0047ADCC 4000B47B */  lq         $20, 0x40($29)
    /* 37ADD0 0047ADD0 3000B37B */  lq         $19, 0x30($29)
    /* 37ADD4 0047ADD4 2000B27B */  lq         $18, 0x20($29)
    /* 37ADD8 0047ADD8 1000B17B */  lq         $17, 0x10($29)
    /* 37ADDC 0047ADDC 0000B07B */  lq         $16, 0x0($29)
    /* 37ADE0 0047ADE0 7001BD27 */  addiu      $29, $29, 0x170
    /* 37ADE4 0047ADE4 0800E003 */  jr         $31
    /* 37ADE8 0047ADE8 00000000 */   nop
    /* 37ADEC 0047ADEC 00000000 */  nop
.size func_0047ac90, 0x160
