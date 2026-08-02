.section .text
.set noat
.set noreorder
glabel func_001e2d20
    /* E2D20 001E2D20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E2D24 001E2D24 1000BFFF */  sd         $31, 0x10($29)
    /* E2D28 001E2D28 0000B07F */  sq         $16, 0x0($29)
    /* E2D2C 001E2D2C 14740A0C */  jal        func_0029d050
    /* E2D30 001E2D30 00000000 */   nop
    /* E2D34 001E2D34 3000428C */  lw         $2, 0x30($2)
    /* E2D38 001E2D38 A2004290 */  lbu        $2, 0xA2($2)
    /* E2D3C 001E2D3C 04004014 */  bnez       $2, .L001E2D50
    /* E2D40 001E2D40 00000000 */   nop
    /* E2D44 001E2D44 01001024 */  addiu      $16, $0, 0x1
    /* E2D48 001E2D48 02000010 */  b          .L001E2D54
    /* E2D4C 001E2D4C 00000000 */   nop
  .L001E2D50:
    /* E2D50 001E2D50 2D800000 */  daddu      $16, $0, $0
  .L001E2D54:
    /* E2D54 001E2D54 2D200000 */  daddu      $4, $0, $0
    /* E2D58 001E2D58 00730A0C */  jal        func_0029cc00
    /* E2D5C 001E2D5C 00000000 */   nop
    /* E2D60 001E2D60 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E2D64 001E2D64 01000224 */  addiu      $2, $0, 0x1
    /* E2D68 001E2D68 04100202 */  sllv       $2, $2, $16
    /* E2D6C 001E2D6C FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E2D70 001E2D70 0800063C */  lui        $6, (0x80000 >> 16)
    /* E2D74 001E2D74 A064070C */  jal        func_001d9280
    /* E2D78 001E2D78 00000000 */   nop
    /* E2D7C 001E2D7C 2D804000 */  daddu      $16, $2, $0
    /* E2D80 001E2D80 1E000012 */  beqz       $16, .L001E2DFC
    /* E2D84 001E2D84 00000000 */   nop
    /* E2D88 001E2D88 01000424 */  addiu      $4, $0, 0x1
    /* E2D8C 001E2D8C 00730A0C */  jal        func_0029cc00
    /* E2D90 001E2D90 00000000 */   nop
    /* E2D94 001E2D94 3C1A0200 */  dsll32     $3, $2, 8
    /* E2D98 001E2D98 3E1A0300 */  dsrl32     $3, $3, 8
    /* E2D9C 001E2D9C 0017023C */  lui        $2, (0x17000000 >> 16)
    /* E2DA0 001E2DA0 25206200 */  or         $4, $3, $2
    /* E2DA4 001E2DA4 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E2DA8 001E2DA8 24108200 */  and        $2, $4, $2
    /* E2DAC 001E2DAC 021E0200 */  srl        $3, $2, 24
    /* E2DB0 001E2DB0 3C2A0400 */  dsll32     $5, $4, 8
    /* E2DB4 001E2DB4 3E2A0500 */  dsrl32     $5, $5, 8
    /* E2DB8 001E2DB8 04006014 */  bnez       $3, .L001E2DCC
    /* E2DBC 001E2DBC 00000000 */   nop
    /* E2DC0 001E2DC0 2D100000 */  daddu      $2, $0, $0
    /* E2DC4 001E2DC4 0B000010 */  b          .L001E2DF4
    /* E2DC8 001E2DC8 00000000 */   nop
  .L001E2DCC:
    /* E2DCC 001E2DCC 2D200002 */  daddu      $4, $16, $0
    /* E2DD0 001E2DD0 40100300 */  sll        $2, $3, 1
    /* E2DD4 001E2DD4 21104300 */  addu       $2, $2, $3
    /* E2DD8 001E2DD8 80180200 */  sll        $3, $2, 2
    /* E2DDC 001E2DDC 6100023C */  lui        $2, %hi(D_00609850)
    /* E2DE0 001E2DE0 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E2DE4 001E2DE4 21104300 */  addu       $2, $2, $3
    /* E2DE8 001E2DE8 0000428C */  lw         $2, 0x0($2)
    /* E2DEC 001E2DEC 09F84000 */  jalr       $2
    /* E2DF0 001E2DF0 00000000 */   nop
  .L001E2DF4:
    /* E2DF4 001E2DF4 02000010 */  b          .L001E2E00
    /* E2DF8 001E2DF8 00000000 */   nop
  .L001E2DFC:
    /* E2DFC 001E2DFC 2D100000 */  daddu      $2, $0, $0
  .L001E2E00:
    /* E2E00 001E2E00 2B200200 */  sltu       $4, $0, $2
    /* E2E04 001E2E04 D4730A0C */  jal        func_0029cf50
    /* E2E08 001E2E08 00000000 */   nop
    /* E2E0C 001E2E0C 01000224 */  addiu      $2, $0, 0x1
    /* E2E10 001E2E10 1000BFDF */  ld         $31, 0x10($29)
    /* E2E14 001E2E14 0000B07B */  lq         $16, 0x0($29)
    /* E2E18 001E2E18 2000BD27 */  addiu      $29, $29, 0x20
    /* E2E1C 001E2E1C 0800E003 */  jr         $31
    /* E2E20 001E2E20 00000000 */   nop
    /* E2E24 001E2E24 00000000 */  nop
    /* E2E28 001E2E28 00000000 */  nop
    /* E2E2C 001E2E2C 00000000 */  nop
.size func_001e2d20, 0x110
