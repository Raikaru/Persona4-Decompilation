.section .text
.set noat
.set noreorder
glabel func_001bc980
    /* BC980 001BC980 70FFBD27 */  addiu      $29, $29, -0x90
    /* BC984 001BC984 2000BFFF */  sd         $31, 0x20($29)
    /* BC988 001BC988 1000B17F */  sq         $17, 0x10($29)
    /* BC98C 001BC98C 0000B07F */  sq         $16, 0x0($29)
    /* BC990 001BC990 2D808000 */  daddu      $16, $4, $0
    /* BC994 001BC994 01000424 */  addiu      $4, $0, 0x1
    /* BC998 001BC998 0000058E */  lw         $5, 0x0($16)
    /* BC99C 001BC99C 2D308000 */  daddu      $6, $4, $0
    /* BC9A0 001BC9A0 98F1060C */  jal        func_001bc660
    /* BC9A4 001BC9A4 00000000 */   nop
    /* BC9A8 001BC9A8 4000028E */  lw         $2, 0x40($16)
    /* BC9AC 001BC9AC 08004010 */  beqz       $2, .L001BC9D0
    /* BC9B0 001BC9B0 00000000 */   nop
    /* BC9B4 001BC9B4 ACB3828F */  lw         $2, -0x4C54($28)
    /* BC9B8 001BC9B8 5000A427 */  addiu      $4, $29, 0x50
    /* BC9BC 001BC9BC C0004524 */  addiu      $5, $2, 0xC0
    /* BC9C0 001BC9C0 58F5060C */  jal        func_001bd560
    /* BC9C4 001BC9C4 00000000 */   nop
    /* BC9C8 001BC9C8 0E000010 */  b          .L001BCA04
    /* BC9CC 001BC9CC 00000000 */   nop
  .L001BC9D0:
    /* BC9D0 001BC9D0 5C00A427 */  addiu      $4, $29, 0x5C
    /* BC9D4 001BC9D4 04000526 */  addiu      $5, $16, 0x4
    /* BC9D8 001BC9D8 10000626 */  addiu      $6, $16, 0x10
    /* BC9DC 001BC9DC 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BC9E0 001BC9E0 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BC9E4 001BC9E4 E0F5060C */  jal        func_001bd780
    /* BC9E8 001BC9E8 00000000 */   nop
    /* BC9EC 001BC9EC 040002C6 */  lwc1       $f2, 0x4($16)
    /* BC9F0 001BC9F0 080001C6 */  lwc1       $f1, 0x8($16)
    /* BC9F4 001BC9F4 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* BC9F8 001BC9F8 5000A2E7 */  swc1       $f2, 0x50($29)
    /* BC9FC 001BC9FC 5400A1E7 */  swc1       $f1, 0x54($29)
    /* BCA00 001BCA00 5800A0E7 */  swc1       $f0, 0x58($29)
  .L001BCA04:
    /* BCA04 001BCA04 7800A427 */  addiu      $4, $29, 0x78
    /* BCA08 001BCA08 1C000526 */  addiu      $5, $16, 0x1C
    /* BCA0C 001BCA0C 28000626 */  addiu      $6, $16, 0x28
    /* BCA10 001BCA10 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BCA14 001BCA14 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BCA18 001BCA18 E0F5060C */  jal        func_001bd780
    /* BCA1C 001BCA1C 00000000 */   nop
    /* BCA20 001BCA20 1C0002C6 */  lwc1       $f2, 0x1C($16)
    /* BCA24 001BCA24 200001C6 */  lwc1       $f1, 0x20($16)
    /* BCA28 001BCA28 240000C6 */  lwc1       $f0, 0x24($16)
    /* BCA2C 001BCA2C 6C00A2E7 */  swc1       $f2, 0x6C($29)
    /* BCA30 001BCA30 7000A1E7 */  swc1       $f1, 0x70($29)
    /* BCA34 001BCA34 7400A0E7 */  swc1       $f0, 0x74($29)
    /* BCA38 001BCA38 ACB3838F */  lw         $3, -0x4C54($28)
    /* BCA3C 001BCA3C 24007124 */  addiu      $17, $3, 0x24
    /* BCA40 001BCA40 01000224 */  addiu      $2, $0, 0x1
    /* BCA44 001BCA44 240062A4 */  sh         $2, 0x24($3)
    /* BCA48 001BCA48 980060A4 */  sh         $0, 0x98($3)
    /* BCA4C 001BCA4C 9A0060A4 */  sh         $0, 0x9A($3)
    /* BCA50 001BCA50 9C0060A4 */  sh         $0, 0x9C($3)
    /* BCA54 001BCA54 A40060AC */  sw         $0, 0xA4($3)
    /* BCA58 001BCA58 A00060AC */  sw         $0, 0xA0($3)
    /* BCA5C 001BCA5C 2D202002 */  daddu      $4, $17, $0
    /* BCA60 001BCA60 5000A527 */  addiu      $5, $29, 0x50
    /* BCA64 001BCA64 5C00A627 */  addiu      $6, $29, 0x5C
    /* BCA68 001BCA68 78EA060C */  jal        func_001ba9e0
    /* BCA6C 001BCA6C 00000000 */   nop
    /* BCA70 001BCA70 3000A427 */  addiu      $4, $29, 0x30
    /* BCA74 001BCA74 5000A527 */  addiu      $5, $29, 0x50
    /* BCA78 001BCA78 6C00A627 */  addiu      $6, $29, 0x6C
    /* BCA7C 001BCA7C F8828CC7 */  lwc1       $f12, -0x7D08($28)
    /* BCA80 001BCA80 E4E9060C */  jal        func_001ba790
    /* BCA84 001BCA84 00000000 */   nop
    /* BCA88 001BCA88 2D202002 */  daddu      $4, $17, $0
    /* BCA8C 001BCA8C 3000A527 */  addiu      $5, $29, 0x30
    /* BCA90 001BCA90 3C00A627 */  addiu      $6, $29, 0x3C
    /* BCA94 001BCA94 78EA060C */  jal        func_001ba9e0
    /* BCA98 001BCA98 00000000 */   nop
    /* BCA9C 001BCA9C 3000A427 */  addiu      $4, $29, 0x30
    /* BCAA0 001BCAA0 5000A527 */  addiu      $5, $29, 0x50
    /* BCAA4 001BCAA4 6C00A627 */  addiu      $6, $29, 0x6C
    /* BCAA8 001BCAA8 C8808CC7 */  lwc1       $f12, -0x7F38($28)
    /* BCAAC 001BCAAC E4E9060C */  jal        func_001ba790
    /* BCAB0 001BCAB0 00000000 */   nop
    /* BCAB4 001BCAB4 2D202002 */  daddu      $4, $17, $0
    /* BCAB8 001BCAB8 3000A527 */  addiu      $5, $29, 0x30
    /* BCABC 001BCABC 3C00A627 */  addiu      $6, $29, 0x3C
    /* BCAC0 001BCAC0 78EA060C */  jal        func_001ba9e0
    /* BCAC4 001BCAC4 00000000 */   nop
    /* BCAC8 001BCAC8 2D202002 */  daddu      $4, $17, $0
    /* BCACC 001BCACC 6C00A527 */  addiu      $5, $29, 0x6C
    /* BCAD0 001BCAD0 7800A627 */  addiu      $6, $29, 0x78
    /* BCAD4 001BCAD4 78EA060C */  jal        func_001ba9e0
    /* BCAD8 001BCAD8 00000000 */   nop
    /* BCADC 001BCADC ACB3838F */  lw         $3, -0x4C54($28)
    /* BCAE0 001BCAE0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* BCAE4 001BCAE4 00108244 */  mtc1       $2, $f2
    /* BCAE8 001BCAE8 3C0000C6 */  lwc1       $f0, 0x3C($16)
    /* BCAEC 001BCAEC 42100046 */  mul.s      $f1, $f2, $f0
    /* BCAF0 001BCAF0 7042023C */  lui        $2, (0x42700000 >> 16)
    /* BCAF4 001BCAF4 00008244 */  mtc1       $2, $f0
    /* BCAF8 001BCAF8 00000000 */  nop
    /* BCAFC 001BCAFC 02000146 */  mul.s      $f0, $f0, $f1
    /* BCB00 001BCB00 03000246 */  div.s      $f0, $f0, $f2
    /* BCB04 001BCB04 A80060E4 */  swc1       $f0, 0xA8($3)
    /* BCB08 001BCB08 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BCB0C 001BCB0C B80062AC */  sw         $2, 0xB8($3)
    /* BCB10 001BCB10 24006294 */  lhu        $2, 0x24($3)
    /* BCB14 001BCB14 F5FF4230 */  andi       $2, $2, 0xFFF5
    /* BCB18 001BCB18 240062A4 */  sh         $2, 0x24($3)
    /* BCB1C 001BCB1C 24006294 */  lhu        $2, 0x24($3)
    /* BCB20 001BCB20 04004234 */  ori        $2, $2, 0x4
    /* BCB24 001BCB24 240062A4 */  sh         $2, 0x24($3)
    /* BCB28 001BCB28 01000224 */  addiu      $2, $0, 0x1
    /* BCB2C 001BCB2C 2000BFDF */  ld         $31, 0x20($29)
    /* BCB30 001BCB30 1000B17B */  lq         $17, 0x10($29)
    /* BCB34 001BCB34 0000B07B */  lq         $16, 0x0($29)
    /* BCB38 001BCB38 9000BD27 */  addiu      $29, $29, 0x90
    /* BCB3C 001BCB3C 0800E003 */  jr         $31
    /* BCB40 001BCB40 00000000 */   nop
    /* BCB44 001BCB44 00000000 */  nop
    /* BCB48 001BCB48 00000000 */  nop
    /* BCB4C 001BCB4C 00000000 */  nop
.size func_001bc980, 0x1d0
