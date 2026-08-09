.section .text
.set noat
.set noreorder
glabel func_004e1cd8
    /* 3E1CD8 004E1CD8 70FDBD27 */  addiu      $29, $29, -0x290
    /* 3E1CDC 004E1CDC 6802B1FF */  sd         $17, 0x268($29)
    /* 3E1CE0 004E1CE0 2D888000 */  daddu      $17, $4, $0
    /* 3E1CE4 004E1CE4 7802B3FF */  sd         $19, 0x278($29)
    /* 3E1CE8 004E1CE8 2D98A000 */  daddu      $19, $5, $0
    /* 3E1CEC 004E1CEC 8002B4FF */  sd         $20, 0x280($29)
    /* 3E1CF0 004E1CF0 2DA0C000 */  daddu      $20, $6, $0
    /* 3E1CF4 004E1CF4 6002B0FF */  sd         $16, 0x260($29)
    /* 3E1CF8 004E1CF8 7002B2FF */  sd         $18, 0x270($29)
    /* 3E1CFC 004E1CFC 04002016 */  bnez       $17, .L004E1D10
    /* 3E1D00 004E1D00 8802BFFF */   sd        $31, 0x288($29)
    /* 3E1D04 004E1D04 7600043C */  lui        $4, %hi(D_00759EA0)
    /* 3E1D08 004E1D08 32000010 */  b          .L004E1DD4
    /* 3E1D0C 004E1D0C A09E8424 */   addiu     $4, $4, %lo(D_00759EA0)
  .L004E1D10:
    /* 3E1D10 004E1D10 3001B227 */  addiu      $18, $29, 0x130
    /* 3E1D14 004E1D14 2D20A003 */  daddu      $4, $29, $0
    /* 3E1D18 004E1D18 2D284002 */  daddu      $5, $18, $0
    /* 3E1D1C 004E1D1C 9E87130C */  jal        func_004e1e78
    /* 3E1D20 004E1D20 2D302002 */   daddu     $6, $17, $0
    /* 3E1D24 004E1D24 3001A283 */  lb         $2, 0x130($29)
    /* 3E1D28 004E1D28 03004014 */  bnez       $2, .L004E1D38
    /* 3E1D2C 004E1D2C 7600043C */   lui       $4, %hi(D_00759EA0)
    /* 3E1D30 004E1D30 28000010 */  b          .L004E1DD4
    /* 3E1D34 004E1D34 A09E8424 */   addiu     $4, $4, %lo(D_00759EA0)
  .L004E1D38:
    /* 3E1D38 004E1D38 8087130C */  jal        func_004e1e00
    /* 3E1D3C 004E1D3C 00000000 */   nop
    /* 3E1D40 004E1D40 2D804000 */  daddu      $16, $2, $0
    /* 3E1D44 004E1D44 04000016 */  bnez       $16, .L004E1D58
    /* 3E1D48 004E1D48 2D302002 */   daddu     $6, $17, $0
    /* 3E1D4C 004E1D4C 7600043C */  lui        $4, %hi(D_00759EC0)
    /* 3E1D50 004E1D50 20000010 */  b          .L004E1DD4
    /* 3E1D54 004E1D54 C09E8424 */   addiu     $4, $4, %lo(D_00759EC0)
  .L004E1D58:
    /* 3E1D58 004E1D58 2D20A003 */  daddu      $4, $29, $0
    /* 3E1D5C 004E1D5C 0C87130C */  jal        func_004e1c30
    /* 3E1D60 004E1D60 2D284002 */   daddu     $5, $18, $0
    /* 3E1D64 004E1D64 06004014 */  bnez       $2, .L004E1D80
    /* 3E1D68 004E1D68 000002AE */   sw        $2, 0x0($16)
    /* 3E1D6C 004E1D6C 9A87130C */  jal        func_004e1e68
    /* 3E1D70 004E1D70 2D200002 */   daddu     $4, $16, $0
    /* 3E1D74 004E1D74 7600043C */  lui        $4, %hi(D_00759F08)
    /* 3E1D78 004E1D78 16000010 */  b          .L004E1DD4
    /* 3E1D7C 004E1D7C 089F8424 */   addiu     $4, $4, %lo(D_00759F08)
  .L004E1D80:
    /* 3E1D80 004E1D80 1000428C */  lw         $2, 0x10($2)
    /* 3E1D84 004E1D84 06004010 */  beqz       $2, .L004E1DA0
    /* 3E1D88 004E1D88 2D286002 */   daddu     $5, $19, $0
    /* 3E1D8C 004E1D8C 2D204002 */  daddu      $4, $18, $0
    /* 3E1D90 004E1D90 09F84000 */  jalr       $2
    /* 3E1D94 004E1D94 2D308002 */   daddu     $6, $20, $0
    /* 3E1D98 004E1D98 07000010 */  b          .L004E1DB8
    /* 3E1D9C 004E1D9C 040002AE */   sw        $2, 0x4($16)
  .L004E1DA0:
    /* 3E1DA0 004E1DA0 9A87130C */  jal        func_004e1e68
    /* 3E1DA4 004E1DA4 2D200002 */   daddu     $4, $16, $0
    /* 3E1DA8 004E1DA8 7600043C */  lui        $4, %hi(D_00759F28)
    /* 3E1DAC 004E1DAC 09000010 */  b          .L004E1DD4
    /* 3E1DB0 004E1DB0 289F8424 */   addiu     $4, $4, %lo(D_00759F28)
    /* 3E1DB4 004E1DB4 00000000 */  nop
  .L004E1DB8:
    /* 3E1DB8 004E1DB8 0400028E */  lw         $2, 0x4($16)
    /* 3E1DBC 004E1DBC 08004054 */  bnel       $2, $0, .L004E1DE0
    /* 3E1DC0 004E1DC0 2D100002 */   daddu     $2, $16, $0
    /* 3E1DC4 004E1DC4 9A87130C */  jal        func_004e1e68
    /* 3E1DC8 004E1DC8 2D200002 */   daddu     $4, $16, $0
    /* 3E1DCC 004E1DCC 7600043C */  lui        $4, %hi(D_00759F40)
    /* 3E1DD0 004E1DD0 409F8424 */  addiu      $4, $4, %lo(D_00759F40)
  .L004E1DD4:
    /* 3E1DD4 004E1DD4 6A85130C */  jal        func_004e15a8
    /* 3E1DD8 004E1DD8 00000000 */   nop
    /* 3E1DDC 004E1DDC 2D100000 */  daddu      $2, $0, $0
  .L004E1DE0:
    /* 3E1DE0 004E1DE0 6002B0DF */  ld         $16, 0x260($29)
    /* 3E1DE4 004E1DE4 6802B1DF */  ld         $17, 0x268($29)
    /* 3E1DE8 004E1DE8 7002B2DF */  ld         $18, 0x270($29)
    /* 3E1DEC 004E1DEC 7802B3DF */  ld         $19, 0x278($29)
    /* 3E1DF0 004E1DF0 8002B4DF */  ld         $20, 0x280($29)
    /* 3E1DF4 004E1DF4 8802BFDF */  ld         $31, 0x288($29)
    /* 3E1DF8 004E1DF8 0800E003 */  jr         $31
    /* 3E1DFC 004E1DFC 9002BD27 */   addiu     $29, $29, 0x290
.size func_004e1cd8, 0x128
