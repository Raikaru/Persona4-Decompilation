.section .text
.set noat
.set noreorder
glabel func_001e1cc0
    /* E1CC0 001E1CC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E1CC4 001E1CC4 1000BFFF */  sd         $31, 0x10($29)
    /* E1CC8 001E1CC8 0000B07F */  sq         $16, 0x0($29)
    /* E1CCC 001E1CCC 14740A0C */  jal        func_0029d050
    /* E1CD0 001E1CD0 00000000 */   nop
    /* E1CD4 001E1CD4 2D804000 */  daddu      $16, $2, $0
    /* E1CD8 001E1CD8 2D200000 */  daddu      $4, $0, $0
    /* E1CDC 001E1CDC 00730A0C */  jal        func_0029cc00
    /* E1CE0 001E1CE0 00000000 */   nop
    /* E1CE4 001E1CE4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E1CE8 001E1CE8 3000028E */  lw         $2, 0x30($16)
    /* E1CEC 001E1CEC A2004390 */  lbu        $3, 0xA2($2)
    /* E1CF0 001E1CF0 01000224 */  addiu      $2, $0, 0x1
    /* E1CF4 001E1CF4 04106200 */  sllv       $2, $2, $3
    /* E1CF8 001E1CF8 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E1CFC 001E1CFC 0800063C */  lui        $6, (0x80000 >> 16)
    /* E1D00 001E1D00 A064070C */  jal        func_001d9280
    /* E1D04 001E1D04 00000000 */   nop
    /* E1D08 001E1D08 2D804000 */  daddu      $16, $2, $0
    /* E1D0C 001E1D0C 1E000012 */  beqz       $16, .L001E1D88
    /* E1D10 001E1D10 00000000 */   nop
    /* E1D14 001E1D14 01000424 */  addiu      $4, $0, 0x1
    /* E1D18 001E1D18 00730A0C */  jal        func_0029cc00
    /* E1D1C 001E1D1C 00000000 */   nop
    /* E1D20 001E1D20 3C1A0200 */  dsll32     $3, $2, 8
    /* E1D24 001E1D24 3E1A0300 */  dsrl32     $3, $3, 8
    /* E1D28 001E1D28 0019023C */  lui        $2, (0x19000000 >> 16)
    /* E1D2C 001E1D2C 25206200 */  or         $4, $3, $2
    /* E1D30 001E1D30 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E1D34 001E1D34 24108200 */  and        $2, $4, $2
    /* E1D38 001E1D38 021E0200 */  srl        $3, $2, 24
    /* E1D3C 001E1D3C 3C2A0400 */  dsll32     $5, $4, 8
    /* E1D40 001E1D40 3E2A0500 */  dsrl32     $5, $5, 8
    /* E1D44 001E1D44 04006014 */  bnez       $3, .L001E1D58
    /* E1D48 001E1D48 00000000 */   nop
    /* E1D4C 001E1D4C 2D100000 */  daddu      $2, $0, $0
    /* E1D50 001E1D50 0B000010 */  b          .L001E1D80
    /* E1D54 001E1D54 00000000 */   nop
  .L001E1D58:
    /* E1D58 001E1D58 2D200002 */  daddu      $4, $16, $0
    /* E1D5C 001E1D5C 40100300 */  sll        $2, $3, 1
    /* E1D60 001E1D60 21104300 */  addu       $2, $2, $3
    /* E1D64 001E1D64 80180200 */  sll        $3, $2, 2
    /* E1D68 001E1D68 6100023C */  lui        $2, %hi(D_00609850)
    /* E1D6C 001E1D6C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E1D70 001E1D70 21104300 */  addu       $2, $2, $3
    /* E1D74 001E1D74 0000428C */  lw         $2, 0x0($2)
    /* E1D78 001E1D78 09F84000 */  jalr       $2
    /* E1D7C 001E1D7C 00000000 */   nop
  .L001E1D80:
    /* E1D80 001E1D80 02000010 */  b          .L001E1D8C
    /* E1D84 001E1D84 00000000 */   nop
  .L001E1D88:
    /* E1D88 001E1D88 2D100000 */  daddu      $2, $0, $0
  .L001E1D8C:
    /* E1D8C 001E1D8C 2B200200 */  sltu       $4, $0, $2
    /* E1D90 001E1D90 D4730A0C */  jal        func_0029cf50
    /* E1D94 001E1D94 00000000 */   nop
    /* E1D98 001E1D98 01000224 */  addiu      $2, $0, 0x1
    /* E1D9C 001E1D9C 1000BFDF */  ld         $31, 0x10($29)
    /* E1DA0 001E1DA0 0000B07B */  lq         $16, 0x0($29)
    /* E1DA4 001E1DA4 2000BD27 */  addiu      $29, $29, 0x20
    /* E1DA8 001E1DA8 0800E003 */  jr         $31
    /* E1DAC 001E1DAC 00000000 */   nop
.size func_001e1cc0, 0xf0
