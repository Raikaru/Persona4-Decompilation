.section .text
.set noat
.set noreorder
glabel func_001e1db0
    /* E1DB0 001E1DB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E1DB4 001E1DB4 1000BFFF */  sd         $31, 0x10($29)
    /* E1DB8 001E1DB8 0000B07F */  sq         $16, 0x0($29)
    /* E1DBC 001E1DBC 14740A0C */  jal        func_0029d050
    /* E1DC0 001E1DC0 00000000 */   nop
    /* E1DC4 001E1DC4 2D804000 */  daddu      $16, $2, $0
    /* E1DC8 001E1DC8 2D200000 */  daddu      $4, $0, $0
    /* E1DCC 001E1DCC 00730A0C */  jal        func_0029cc00
    /* E1DD0 001E1DD0 00000000 */   nop
    /* E1DD4 001E1DD4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E1DD8 001E1DD8 3000028E */  lw         $2, 0x30($16)
    /* E1DDC 001E1DDC A2004390 */  lbu        $3, 0xA2($2)
    /* E1DE0 001E1DE0 01000224 */  addiu      $2, $0, 0x1
    /* E1DE4 001E1DE4 04106200 */  sllv       $2, $2, $3
    /* E1DE8 001E1DE8 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E1DEC 001E1DEC 0800063C */  lui        $6, (0x80000 >> 16)
    /* E1DF0 001E1DF0 A064070C */  jal        func_001d9280
    /* E1DF4 001E1DF4 00000000 */   nop
    /* E1DF8 001E1DF8 2D804000 */  daddu      $16, $2, $0
    /* E1DFC 001E1DFC 1E000012 */  beqz       $16, .L001E1E78
    /* E1E00 001E1E00 00000000 */   nop
    /* E1E04 001E1E04 01000424 */  addiu      $4, $0, 0x1
    /* E1E08 001E1E08 00730A0C */  jal        func_0029cc00
    /* E1E0C 001E1E0C 00000000 */   nop
    /* E1E10 001E1E10 3C1A0200 */  dsll32     $3, $2, 8
    /* E1E14 001E1E14 3E1A0300 */  dsrl32     $3, $3, 8
    /* E1E18 001E1E18 0022023C */  lui        $2, (0x22000000 >> 16)
    /* E1E1C 001E1E1C 25206200 */  or         $4, $3, $2
    /* E1E20 001E1E20 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E1E24 001E1E24 24108200 */  and        $2, $4, $2
    /* E1E28 001E1E28 021E0200 */  srl        $3, $2, 24
    /* E1E2C 001E1E2C 3C2A0400 */  dsll32     $5, $4, 8
    /* E1E30 001E1E30 3E2A0500 */  dsrl32     $5, $5, 8
    /* E1E34 001E1E34 04006014 */  bnez       $3, .L001E1E48
    /* E1E38 001E1E38 00000000 */   nop
    /* E1E3C 001E1E3C 2D100000 */  daddu      $2, $0, $0
    /* E1E40 001E1E40 0B000010 */  b          .L001E1E70
    /* E1E44 001E1E44 00000000 */   nop
  .L001E1E48:
    /* E1E48 001E1E48 2D200002 */  daddu      $4, $16, $0
    /* E1E4C 001E1E4C 40100300 */  sll        $2, $3, 1
    /* E1E50 001E1E50 21104300 */  addu       $2, $2, $3
    /* E1E54 001E1E54 80180200 */  sll        $3, $2, 2
    /* E1E58 001E1E58 6100023C */  lui        $2, %hi(D_00609850)
    /* E1E5C 001E1E5C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E1E60 001E1E60 21104300 */  addu       $2, $2, $3
    /* E1E64 001E1E64 0000428C */  lw         $2, 0x0($2)
    /* E1E68 001E1E68 09F84000 */  jalr       $2
    /* E1E6C 001E1E6C 00000000 */   nop
  .L001E1E70:
    /* E1E70 001E1E70 02000010 */  b          .L001E1E7C
    /* E1E74 001E1E74 00000000 */   nop
  .L001E1E78:
    /* E1E78 001E1E78 2D100000 */  daddu      $2, $0, $0
  .L001E1E7C:
    /* E1E7C 001E1E7C 2B200200 */  sltu       $4, $0, $2
    /* E1E80 001E1E80 D4730A0C */  jal        func_0029cf50
    /* E1E84 001E1E84 00000000 */   nop
    /* E1E88 001E1E88 01000224 */  addiu      $2, $0, 0x1
    /* E1E8C 001E1E8C 1000BFDF */  ld         $31, 0x10($29)
    /* E1E90 001E1E90 0000B07B */  lq         $16, 0x0($29)
    /* E1E94 001E1E94 2000BD27 */  addiu      $29, $29, 0x20
    /* E1E98 001E1E98 0800E003 */  jr         $31
    /* E1E9C 001E1E9C 00000000 */   nop
.size func_001e1db0, 0xf0
