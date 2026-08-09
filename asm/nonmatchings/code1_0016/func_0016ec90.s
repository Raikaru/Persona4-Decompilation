.section .text
.set noat
.set noreorder
glabel func_0016ec90
    /* 6EC90 0016EC90 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 6EC94 0016EC94 3000BFFF */  sd         $31, 0x30($29)
    /* 6EC98 0016EC98 2000B27F */  sq         $18, 0x20($29)
    /* 6EC9C 0016EC9C 1000B17F */  sq         $17, 0x10($29)
    /* 6ECA0 0016ECA0 0000B07F */  sq         $16, 0x0($29)
    /* 6ECA4 0016ECA4 3800908C */  lw         $16, 0x38($4)
    /* 6ECA8 0016ECA8 0800048E */  lw         $4, 0x8($16)
    /* 6ECAC 0016ECAC 06000324 */  addiu      $3, $0, 0x6
    /* 6ECB0 0016ECB0 4A008314 */  bne        $4, $3, .L0016EDDC
    /* 6ECB4 0016ECB4 00000000 */   nop
    /* 6ECB8 0016ECB8 485C110C */  jal        func_00457120
    /* 6ECBC 0016ECBC 00000000 */   nop
    /* 6ECC0 0016ECC0 0400528C */  lw         $18, 0x4($2)
    /* 6ECC4 0016ECC4 0400448E */  lw         $4, 0x4($18)
    /* 6ECC8 0016ECC8 C0A50F0C */  jal        func_003e9700
    /* 6ECCC 0016ECCC 00000000 */   nop
    /* 6ECD0 0016ECD0 2D884000 */  daddu      $17, $2, $0
    /* 6ECD4 0016ECD4 10004626 */  addiu      $6, $18, 0x10
    /* 6ECD8 0016ECD8 C002058E */  lw         $5, 0x2C0($16)
    /* 6ECDC 0016ECDC 08000424 */  addiu      $4, $0, 0x8
  .L0016ECE0:
    /* 6ECE0 0016ECE0 0000C38C */  lw         $3, 0x0($6)
    /* 6ECE4 0016ECE4 0400C28C */  lw         $2, 0x4($6)
    /* 6ECE8 0016ECE8 0800C624 */  addiu      $6, $6, 0x8
    /* 6ECEC 0016ECEC FFFF8424 */  addiu      $4, $4, -0x1
    /* 6ECF0 0016ECF0 0000A3AC */  sw         $3, 0x0($5)
    /* 6ECF4 0016ECF4 0400A2AC */  sw         $2, 0x4($5)
    /* 6ECF8 0016ECF8 0800A524 */  addiu      $5, $5, 0x8
    /* 6ECFC 0016ECFC F8FF801C */  bgtz       $4, .L0016ECE0
    /* 6ED00 0016ED00 00000000 */   nop
    /* 6ED04 0016ED04 C002028E */  lw         $2, 0x2C0($16)
    /* 6ED08 0016ED08 4000A427 */  addiu      $4, $29, 0x40
    /* 6ED0C 0016ED0C 200042C4 */  lwc1       $f2, 0x20($2)
    /* 6ED10 0016ED10 240041C4 */  lwc1       $f1, 0x24($2)
    /* 6ED14 0016ED14 280040C4 */  lwc1       $f0, 0x28($2)
    /* 6ED18 0016ED18 4000A2E7 */  swc1       $f2, 0x40($29)
    /* 6ED1C 0016ED1C 4400A1E7 */  swc1       $f1, 0x44($29)
    /* 6ED20 0016ED20 4800A0E7 */  swc1       $f0, 0x48($29)
    /* 6ED24 0016ED24 2D288000 */  daddu      $5, $4, $0
    /* 6ED28 0016ED28 2C900F0C */  jal        func_003e40b0
    /* 6ED2C 0016ED2C 00000000 */   nop
    /* 6ED30 0016ED30 4000A0C7 */  lwc1       $f0, 0x40($29)
    /* 6ED34 0016ED34 07010046 */  neg.s      $f4, $f0
    /* 6ED38 0016ED38 4000A4E7 */  swc1       $f4, 0x40($29)
    /* 6ED3C 0016ED3C 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* 6ED40 0016ED40 C7000046 */  neg.s      $f3, $f0
    /* 6ED44 0016ED44 4400A3E7 */  swc1       $f3, 0x44($29)
    /* 6ED48 0016ED48 4800A0C7 */  lwc1       $f0, 0x48($29)
    /* 6ED4C 0016ED4C 87000046 */  neg.s      $f2, $f0
    /* 6ED50 0016ED50 4800A2E7 */  swc1       $f2, 0x48($29)
    /* 6ED54 0016ED54 8C0201C6 */  lwc1       $f1, 0x28C($16)
    /* 6ED58 0016ED58 02200146 */  mul.s      $f0, $f4, $f1
    /* 6ED5C 0016ED5C 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 6ED60 0016ED60 02180146 */  mul.s      $f0, $f3, $f1
    /* 6ED64 0016ED64 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 6ED68 0016ED68 02100146 */  mul.s      $f0, $f2, $f1
    /* 6ED6C 0016ED6C 4800A0E7 */  swc1       $f0, 0x48($29)
    /* 6ED70 0016ED70 940201E6 */  swc1       $f1, 0x294($16)
    /* 6ED74 0016ED74 C002048E */  lw         $4, 0x2C0($16)
    /* 6ED78 0016ED78 4000A527 */  addiu      $5, $29, 0x40
    /* 6ED7C 0016ED7C 2D300000 */  daddu      $6, $0, $0
    /* 6ED80 0016ED80 24830F0C */  jal        func_003e0c90
    /* 6ED84 0016ED84 00000000 */   nop
    /* 6ED88 0016ED88 C002028E */  lw         $2, 0x2C0($16)
    /* 6ED8C 0016ED8C 300042C4 */  lwc1       $f2, 0x30($2)
    /* 6ED90 0016ED90 340041C4 */  lwc1       $f1, 0x34($2)
    /* 6ED94 0016ED94 380040C4 */  lwc1       $f0, 0x38($2)
    /* 6ED98 0016ED98 5000A2E7 */  swc1       $f2, 0x50($29)
    /* 6ED9C 0016ED9C 5400A1E7 */  swc1       $f1, 0x54($29)
    /* 6EDA0 0016EDA0 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 6EDA4 0016EDA4 C002048E */  lw         $4, 0x2C0($16)
    /* 6EDA8 0016EDA8 2D282002 */  daddu      $5, $17, $0
    /* 6EDAC 0016EDAC 02000624 */  addiu      $6, $0, 0x2
    /* 6EDB0 0016EDB0 88830F0C */  jal        func_003e0e20
    /* 6EDB4 0016EDB4 00000000 */   nop
    /* 6EDB8 0016EDB8 485C110C */  jal        func_00457120
    /* 6EDBC 0016EDBC 00000000 */   nop
    /* 6EDC0 0016EDC0 2D204000 */  daddu      $4, $2, $0
    /* 6EDC4 0016EDC4 5000A527 */  addiu      $5, $29, 0x50
    /* 6EDC8 0016EDC8 7F00063C */  lui        $6, %hi(D_007F1730)
    /* 6EDCC 0016EDCC 3017C624 */  addiu      $6, $6, %lo(D_007F1730)
    /* 6EDD0 0016EDD0 2D380000 */  daddu      $7, $0, $0
    /* 6EDD4 0016EDD4 8C5D110C */  jal        func_00457630
    /* 6EDD8 0016EDD8 00000000 */   nop
  .L0016EDDC:
    /* 6EDDC 0016EDDC 3000BFDF */  ld         $31, 0x30($29)
    /* 6EDE0 0016EDE0 2000B27B */  lq         $18, 0x20($29)
    /* 6EDE4 0016EDE4 1000B17B */  lq         $17, 0x10($29)
    /* 6EDE8 0016EDE8 0000B07B */  lq         $16, 0x0($29)
    /* 6EDEC 0016EDEC 6000BD27 */  addiu      $29, $29, 0x60
    /* 6EDF0 0016EDF0 0800E003 */  jr         $31
    /* 6EDF4 0016EDF4 00000000 */   nop
    /* 6EDF8 0016EDF8 00000000 */  nop
    /* 6EDFC 0016EDFC 00000000 */  nop
.size func_0016ec90, 0x170
