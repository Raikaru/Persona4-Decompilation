.section .text
.set noat
.set noreorder
glabel func_003e2ce0
    /* 2E2CE0 003E2CE0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2E2CE4 003E2CE4 2000BFFF */  sd         $31, 0x20($29)
    /* 2E2CE8 003E2CE8 1000B17F */  sq         $17, 0x10($29)
    /* 2E2CEC 003E2CEC 0000B07F */  sq         $16, 0x0($29)
    /* 2E2CF0 003E2CF0 3300A010 */  beqz       $5, .L003E2DC0
    /* 2E2CF4 003E2CF4 2D808000 */   daddu     $16, $4, $0
    /* 2E2CF8 003E2CF8 0000048E */  lw         $4, 0x0($16)
    /* 2E2CFC 003E2CFC 04000224 */  addiu      $2, $0, 0x4
    /* 2E2D00 003E2D00 21008210 */  beq        $4, $2, .L003E2D88
    /* 2E2D04 003E2D04 00000000 */   nop
    /* 2E2D08 003E2D08 03000224 */  addiu      $2, $0, 0x3
    /* 2E2D0C 003E2D0C 13008210 */  beq        $4, $2, .L003E2D5C
    /* 2E2D10 003E2D10 00000000 */   nop
    /* 2E2D14 003E2D14 01000324 */  addiu      $3, $0, 0x1
    /* 2E2D18 003E2D18 06008310 */  beq        $4, $3, .L003E2D34
    /* 2E2D1C 003E2D1C 00000000 */   nop
    /* 2E2D20 003E2D20 02000224 */  addiu      $2, $0, 0x2
    /* 2E2D24 003E2D24 03008210 */  beq        $4, $2, .L003E2D34
    /* 2E2D28 003E2D28 00000000 */   nop
    /* 2E2D2C 003E2D2C 1D000010 */  b          .L003E2DA4
    /* 2E2D30 003E2D30 3800A3AF */   sw        $3, 0x38($29)
  .L003E2D34:
    /* 2E2D34 003E2D34 0C00118E */  lw         $17, 0xC($16)
    /* 2E2D38 003E2D38 3C280500 */  dsll32     $5, $5, 0
    /* 2E2D3C 003E2D3C 3E280500 */  dsrl32     $5, $5, 0
    /* 2E2D40 003E2D40 01000624 */  addiu      $6, $0, 0x1
    /* 2E2D44 003E2D44 08780F0C */  jal        func_003de020
    /* 2E2D48 003E2D48 2D202002 */   daddu     $4, $17, $0
    /* 2E2D4C 003E2D4C 1E004014 */  bnez       $2, .L003E2DC8
    /* 2E2D50 003E2D50 00000000 */   nop
  .L003E2D54:
    /* 2E2D54 003E2D54 34000010 */  b          .L003E2E28
    /* 2E2D58 003E2D58 2D100002 */   daddu     $2, $16, $0
  .L003E2D5C:
    /* 2E2D5C 003E2D5C 0C00028E */  lw         $2, 0xC($16)
    /* 2E2D60 003E2D60 1000038E */  lw         $3, 0x10($16)
    /* 2E2D64 003E2D64 21104500 */  addu       $2, $2, $5
    /* 2E2D68 003E2D68 2B086200 */  sltu       $1, $3, $2
    /* 2E2D6C 003E2D6C 25002014 */  bnez       $1, .L003E2E04
    /* 2E2D70 003E2D70 0C000426 */   addiu     $4, $16, 0xC
    /* 2E2D74 003E2D74 0000838C */  lw         $3, 0x0($4)
    /* 2E2D78 003E2D78 2D100002 */  daddu      $2, $16, $0
    /* 2E2D7C 003E2D7C 21186500 */  addu       $3, $3, $5
    /* 2E2D80 003E2D80 29000010 */  b          .L003E2E28
    /* 2E2D84 003E2D84 000083AC */   sw        $3, 0x0($4)
  .L003E2D88:
    /* 2E2D88 003E2D88 1800028E */  lw         $2, 0x18($16)
    /* 2E2D8C 003E2D8C 09F84000 */  jalr       $2
    /* 2E2D90 003E2D90 1C00048E */   lw        $4, 0x1C($16)
    /* 2E2D94 003E2D94 0A800200 */  movz       $16, $0, $2
    /* 2E2D98 003E2D98 23000010 */  b          .L003E2E28
    /* 2E2D9C 003E2D9C 2D100002 */   daddu     $2, $16, $0
    /* 2E2DA0 003E2DA0 3800A3AF */  sw         $3, 0x38($29)
  .L003E2DA4:
    /* 2E2DA4 003E2DA4 647D0F0C */  jal        func_003df590
    /* 2E2DA8 003E2DA8 0E000424 */   addiu     $4, $0, 0xE
    /* 2E2DAC 003E2DAC 3C00A2AF */  sw         $2, 0x3C($29)
    /* 2E2DB0 003E2DB0 347D0F0C */  jal        func_003df4d0
    /* 2E2DB4 003E2DB4 3800A427 */   addiu     $4, $29, 0x38
    /* 2E2DB8 003E2DB8 1B000010 */  b          .L003E2E28
    /* 2E2DBC 003E2DBC 2D100000 */   daddu     $2, $0, $0
  .L003E2DC0:
    /* 2E2DC0 003E2DC0 19000010 */  b          .L003E2E28
    /* 2E2DC4 003E2DC4 2D100002 */   daddu     $2, $16, $0
  .L003E2DC8:
    /* 2E2DC8 003E2DC8 40780F0C */  jal        func_003de100
    /* 2E2DCC 003E2DCC 2D202002 */   daddu     $4, $17, $0
    /* 2E2DD0 003E2DD0 03004014 */  bnez       $2, .L003E2DE0
    /* 2E2DD4 003E2DD4 00000000 */   nop
  .L003E2DD8:
    /* 2E2DD8 003E2DD8 DEFF0010 */  b          .L003E2D54
    /* 2E2DDC 003E2DDC 2D800000 */   daddu     $16, $0, $0
  .L003E2DE0:
    /* 2E2DE0 003E2DE0 01000224 */  addiu      $2, $0, 0x1
    /* 2E2DE4 003E2DE4 05000424 */  addiu      $4, $0, 0x5
    /* 2E2DE8 003E2DE8 647D0F0C */  jal        func_003df590
    /* 2E2DEC 003E2DEC 4800A2AF */   sw        $2, 0x48($29)
    /* 2E2DF0 003E2DF0 4C00A2AF */  sw         $2, 0x4C($29)
    /* 2E2DF4 003E2DF4 347D0F0C */  jal        func_003df4d0
    /* 2E2DF8 003E2DF8 4800A427 */   addiu     $4, $29, 0x48
    /* 2E2DFC 003E2DFC F6FF0010 */  b          .L003E2DD8
    /* 2E2E00 003E2E00 00000000 */   nop
  .L003E2E04:
    /* 2E2E04 003E2E04 000083AC */  sw         $3, 0x0($4)
    /* 2E2E08 003E2E08 01000224 */  addiu      $2, $0, 0x1
    /* 2E2E0C 003E2E0C 4000A2AF */  sw         $2, 0x40($29)
    /* 2E2E10 003E2E10 647D0F0C */  jal        func_003df590
    /* 2E2E14 003E2E14 05000424 */   addiu     $4, $0, 0x5
    /* 2E2E18 003E2E18 4400A2AF */  sw         $2, 0x44($29)
    /* 2E2E1C 003E2E1C 347D0F0C */  jal        func_003df4d0
    /* 2E2E20 003E2E20 4000A427 */   addiu     $4, $29, 0x40
    /* 2E2E24 003E2E24 2D100000 */  daddu      $2, $0, $0
  .L003E2E28:
    /* 2E2E28 003E2E28 2000BFDF */  ld         $31, 0x20($29)
    /* 2E2E2C 003E2E2C 1000B17B */  lq         $17, 0x10($29)
    /* 2E2E30 003E2E30 0000B07B */  lq         $16, 0x0($29)
    /* 2E2E34 003E2E34 0800E003 */  jr         $31
    /* 2E2E38 003E2E38 5000BD27 */   addiu     $29, $29, 0x50
    /* 2E2E3C 003E2E3C 00000000 */  nop
.size func_003e2ce0, 0x160
