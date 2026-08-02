.section .text
.set noat
.set noreorder
glabel func_0028ad90
    /* 18AD90 0028AD90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 18AD94 0028AD94 4000BFFF */  sd         $31, 0x40($29)
    /* 18AD98 0028AD98 3000B37F */  sq         $19, 0x30($29)
    /* 18AD9C 0028AD9C 2000B27F */  sq         $18, 0x20($29)
    /* 18ADA0 0028ADA0 1000B17F */  sq         $17, 0x10($29)
    /* 18ADA4 0028ADA4 0000B07F */  sq         $16, 0x0($29)
    /* 18ADA8 0028ADA8 2D908000 */  daddu      $18, $4, $0
    /* 18ADAC 0028ADAC 2D88A000 */  daddu      $17, $5, $0
    /* 18ADB0 0028ADB0 3C3D0A0C */  jal        func_0028f4f0
    /* 18ADB4 0028ADB4 00000000 */   nop
    /* 18ADB8 0028ADB8 9C4C0A0C */  jal        func_00293270
    /* 18ADBC 0028ADBC 00000000 */   nop
    /* 18ADC0 0028ADC0 2D800000 */  daddu      $16, $0, $0
    /* 18ADC4 0028ADC4 10000010 */  b          .L0028AE08
    /* 18ADC8 0028ADC8 00000000 */   nop
  .L0028ADCC:
    /* 18ADCC 0028ADCC 80101000 */  sll        $2, $16, 2
    /* 18ADD0 0028ADD0 21104202 */  addu       $2, $18, $2
    /* 18ADD4 0028ADD4 C4065324 */  addiu      $19, $2, 0x6C4
    /* 18ADD8 0028ADD8 C406448C */  lw         $4, 0x6C4($2)
    /* 18ADDC 0028ADDC 09008010 */  beqz       $4, .L0028AE04
    /* 18ADE0 0028ADE0 00000000 */   nop
    /* 18ADE4 0028ADE4 2449110C */  jal        func_00452490
    /* 18ADE8 0028ADE8 00000000 */   nop
    /* 18ADEC 0028ADEC 04004010 */  beqz       $2, .L0028AE00
    /* 18ADF0 0028ADF0 00000000 */   nop
    /* 18ADF4 0028ADF4 0000648E */  lw         $4, 0x0($19)
    /* 18ADF8 0028ADF8 2048110C */  jal        func_00452080
    /* 18ADFC 0028ADFC 00000000 */   nop
  .L0028AE00:
    /* 18AE00 0028AE00 000060AE */  sw         $0, 0x0($19)
  .L0028AE04:
    /* 18AE04 0028AE04 01001026 */  addiu      $16, $16, 0x1
  .L0028AE08:
    /* 18AE08 0028AE08 0300022A */  slti       $2, $16, 0x3
    /* 18AE0C 0028AE0C EFFF4014 */  bnez       $2, .L0028ADCC
    /* 18AE10 0028AE10 00000000 */   nop
    /* 18AE14 0028AE14 74830B0C */  jal        func_002e0dd0
    /* 18AE18 0028AE18 00000000 */   nop
    /* 18AE1C 0028AE1C 404D040C */  jal        func_00113500
    /* 18AE20 0028AE20 00000000 */   nop
    /* 18AE24 0028AE24 04B6090C */  jal        func_0026d810
    /* 18AE28 0028AE28 00000000 */   nop
    /* 18AE2C 0028AE2C DC300A0C */  jal        func_0028c370
    /* 18AE30 0028AE30 00000000 */   nop
    /* 18AE34 0028AE34 0400428E */  lw         $2, 0x4($18)
    /* 18AE38 0028AE38 09004010 */  beqz       $2, .L0028AE60
    /* 18AE3C 0028AE3C 00000000 */   nop
    /* 18AE40 0028AE40 78064426 */  addiu      $4, $18, 0x678
    /* 18AE44 0028AE44 68420A0C */  jal        func_002909a0
    /* 18AE48 0028AE48 00000000 */   nop
    /* 18AE4C 0028AE4C 04004010 */  beqz       $2, .L0028AE60
    /* 18AE50 0028AE50 00000000 */   nop
    /* 18AE54 0028AE54 78064426 */  addiu      $4, $18, 0x678
    /* 18AE58 0028AE58 C0420A0C */  jal        func_00290b00
    /* 18AE5C 0028AE5C 00000000 */   nop
  .L0028AE60:
    /* 18AE60 0028AE60 2D204002 */  daddu      $4, $18, $0
    /* 18AE64 0028AE64 28340A0C */  jal        func_0028d0a0
    /* 18AE68 0028AE68 00000000 */   nop
    /* 18AE6C 0028AE6C 02000424 */  addiu      $4, $0, 0x2
    /* 18AE70 0028AE70 2D280000 */  daddu      $5, $0, $0
    /* 18AE74 0028AE74 64600A0C */  jal        func_00298190
    /* 18AE78 0028AE78 00000000 */   nop
    /* 18AE7C 0028AE7C 6007448E */  lw         $4, 0x760($18)
    /* 18AE80 0028AE80 09008010 */  beqz       $4, .L0028AEA8
    /* 18AE84 0028AE84 00000000 */   nop
    /* 18AE88 0028AE88 2449110C */  jal        func_00452490
    /* 18AE8C 0028AE8C 00000000 */   nop
    /* 18AE90 0028AE90 05004010 */  beqz       $2, .L0028AEA8
    /* 18AE94 0028AE94 00000000 */   nop
    /* 18AE98 0028AE98 6007448E */  lw         $4, 0x760($18)
    /* 18AE9C 0028AE9C 2048110C */  jal        func_00452080
    /* 18AEA0 0028AEA0 00000000 */   nop
    /* 18AEA4 0028AEA4 600740AE */  sw         $0, 0x760($18)
  .L0028AEA8:
    /* 18AEA8 0028AEA8 6807448E */  lw         $4, 0x768($18)
    /* 18AEAC 0028AEAC 09008010 */  beqz       $4, .L0028AED4
    /* 18AEB0 0028AEB0 00000000 */   nop
    /* 18AEB4 0028AEB4 2449110C */  jal        func_00452490
    /* 18AEB8 0028AEB8 00000000 */   nop
    /* 18AEBC 0028AEBC 05004010 */  beqz       $2, .L0028AED4
    /* 18AEC0 0028AEC0 00000000 */   nop
    /* 18AEC4 0028AEC4 6807448E */  lw         $4, 0x768($18)
    /* 18AEC8 0028AEC8 2048110C */  jal        func_00452080
    /* 18AECC 0028AECC 00000000 */   nop
    /* 18AED0 0028AED0 680740AE */  sw         $0, 0x768($18)
  .L0028AED4:
    /* 18AED4 0028AED4 03002012 */  beqz       $17, .L0028AEE4
    /* 18AED8 0028AED8 00000000 */   nop
    /* 18AEDC 0028AEDC 2066110C */  jal        func_00459880
    /* 18AEE0 0028AEE0 00000000 */   nop
  .L0028AEE4:
    /* 18AEE4 0028AEE4 5C07448E */  lw         $4, 0x75C($18)
    /* 18AEE8 0028AEE8 04008010 */  beqz       $4, .L0028AEFC
    /* 18AEEC 0028AEEC 00000000 */   nop
    /* 18AEF0 0028AEF0 2048110C */  jal        func_00452080
    /* 18AEF4 0028AEF4 00000000 */   nop
    /* 18AEF8 0028AEF8 5C0740AE */  sw         $0, 0x75C($18)
  .L0028AEFC:
    /* 18AEFC 0028AEFC 06004016 */  bnez       $18, .L0028AF18
    /* 18AF00 0028AF00 00000000 */   nop
    /* 18AF04 0028AF04 6400043C */  lui        $4, %hi(D_0063C3B0)
    /* 18AF08 0028AF08 B0C38424 */  addiu      $4, $4, %lo(D_0063C3B0)
    /* 18AF0C 0028AF0C F4000524 */  addiu      $5, $0, 0xF4
    /* 18AF10 0028AF10 CCB5110C */  jal        func_0046d730
    /* 18AF14 0028AF14 00000000 */   nop
  .L0028AF18:
    /* 18AF18 0028AF18 40460A0C */  jal        func_00291900
    /* 18AF1C 0028AF1C 00000000 */   nop
    /* 18AF20 0028AF20 78460A0C */  jal        func_002919e0
    /* 18AF24 0028AF24 00000000 */   nop
    /* 18AF28 0028AF28 D005448E */  lw         $4, 0x5D0($18)
    /* 18AF2C 0028AF2C E8430A0C */  jal        func_00290fa0
    /* 18AF30 0028AF30 00000000 */   nop
    /* 18AF34 0028AF34 D00540AE */  sw         $0, 0x5D0($18)
    /* 18AF38 0028AF38 17000010 */  b          .L0028AF98
    /* 18AF3C 0028AF3C 00000000 */   nop
  .L0028AF40:
    /* 18AF40 0028AF40 04000010 */  b          .L0028AF54
    /* 18AF44 0028AF44 00000000 */   nop
  .L0028AF48:
    /* 18AF48 0028AF48 2D200002 */  daddu      $4, $16, $0
    /* 18AF4C 0028AF4C 181B0A0C */  jal        func_00286c60
    /* 18AF50 0028AF50 00000000 */   nop
  .L0028AF54:
    /* 18AF54 0028AF54 6800058E */  lw         $5, 0x68($16)
    /* 18AF58 0028AF58 00000000 */  nop
    /* 18AF5C 0028AF5C 00000000 */  nop
    /* 18AF60 0028AF60 F9FFA014 */  bnez       $5, .L0028AF48
    /* 18AF64 0028AF64 00000000 */   nop
    /* 18AF68 0028AF68 2D200002 */  daddu      $4, $16, $0
    /* 18AF6C 0028AF6C 2D284002 */  daddu      $5, $18, $0
    /* 18AF70 0028AF70 A41B0A0C */  jal        func_00286e90
    /* 18AF74 0028AF74 00000000 */   nop
    /* 18AF78 0028AF78 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 18AF7C 0028AF7C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 18AF80 0028AF80 09F84000 */  jalr       $2
    /* 18AF84 0028AF84 00000000 */   nop
    /* 18AF88 0028AF88 07000424 */  addiu      $4, $0, 0x7
    /* 18AF8C 0028AF8C 68FF0524 */  addiu      $5, $0, -0x98
    /* 18AF90 0028AF90 A8140A0C */  jal        func_002852a0
    /* 18AF94 0028AF94 00000000 */   nop
  .L0028AF98:
    /* 18AF98 0028AF98 4C00508E */  lw         $16, 0x4C($18)
    /* 18AF9C 0028AF9C E8FF0016 */  bnez       $16, .L0028AF40
    /* 18AFA0 0028AFA0 00000000 */   nop
    /* 18AFA4 0028AFA4 0400448E */  lw         $4, 0x4($18)
    /* 18AFA8 0028AFA8 05008010 */  beqz       $4, .L0028AFC0
    /* 18AFAC 0028AFAC 00000000 */   nop
    /* 18AFB0 0028AFB0 78064526 */  addiu      $5, $18, 0x678
    /* 18AFB4 0028AFB4 1C410A0C */  jal        func_00290470
    /* 18AFB8 0028AFB8 00000000 */   nop
    /* 18AFBC 0028AFBC 040040AE */  sw         $0, 0x4($18)
  .L0028AFC0:
    /* 18AFC0 0028AFC0 4000BFDF */  ld         $31, 0x40($29)
    /* 18AFC4 0028AFC4 3000B37B */  lq         $19, 0x30($29)
    /* 18AFC8 0028AFC8 2000B27B */  lq         $18, 0x20($29)
    /* 18AFCC 0028AFCC 1000B17B */  lq         $17, 0x10($29)
    /* 18AFD0 0028AFD0 0000B07B */  lq         $16, 0x0($29)
    /* 18AFD4 0028AFD4 5000BD27 */  addiu      $29, $29, 0x50
    /* 18AFD8 0028AFD8 0800E003 */  jr         $31
    /* 18AFDC 0028AFDC 00000000 */   nop
.size func_0028ad90, 0x250
