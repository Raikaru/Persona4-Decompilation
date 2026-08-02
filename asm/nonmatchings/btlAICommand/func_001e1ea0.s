.section .text
.set noat
.set noreorder
glabel func_001e1ea0
    /* E1EA0 001E1EA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E1EA4 001E1EA4 1000BFFF */  sd         $31, 0x10($29)
    /* E1EA8 001E1EA8 0000B07F */  sq         $16, 0x0($29)
    /* E1EAC 001E1EAC 14740A0C */  jal        func_0029d050
    /* E1EB0 001E1EB0 00000000 */   nop
    /* E1EB4 001E1EB4 2D804000 */  daddu      $16, $2, $0
    /* E1EB8 001E1EB8 2D200000 */  daddu      $4, $0, $0
    /* E1EBC 001E1EBC 00730A0C */  jal        func_0029cc00
    /* E1EC0 001E1EC0 00000000 */   nop
    /* E1EC4 001E1EC4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E1EC8 001E1EC8 3000028E */  lw         $2, 0x30($16)
    /* E1ECC 001E1ECC A2004390 */  lbu        $3, 0xA2($2)
    /* E1ED0 001E1ED0 01000224 */  addiu      $2, $0, 0x1
    /* E1ED4 001E1ED4 04106200 */  sllv       $2, $2, $3
    /* E1ED8 001E1ED8 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E1EDC 001E1EDC 0800063C */  lui        $6, (0x80000 >> 16)
    /* E1EE0 001E1EE0 A064070C */  jal        func_001d9280
    /* E1EE4 001E1EE4 00000000 */   nop
    /* E1EE8 001E1EE8 2D804000 */  daddu      $16, $2, $0
    /* E1EEC 001E1EEC 1E000012 */  beqz       $16, .L001E1F68
    /* E1EF0 001E1EF0 00000000 */   nop
    /* E1EF4 001E1EF4 01000424 */  addiu      $4, $0, 0x1
    /* E1EF8 001E1EF8 00730A0C */  jal        func_0029cc00
    /* E1EFC 001E1EFC 00000000 */   nop
    /* E1F00 001E1F00 3C1A0200 */  dsll32     $3, $2, 8
    /* E1F04 001E1F04 3E1A0300 */  dsrl32     $3, $3, 8
    /* E1F08 001E1F08 0025023C */  lui        $2, (0x25000000 >> 16)
    /* E1F0C 001E1F0C 25206200 */  or         $4, $3, $2
    /* E1F10 001E1F10 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E1F14 001E1F14 24108200 */  and        $2, $4, $2
    /* E1F18 001E1F18 021E0200 */  srl        $3, $2, 24
    /* E1F1C 001E1F1C 3C2A0400 */  dsll32     $5, $4, 8
    /* E1F20 001E1F20 3E2A0500 */  dsrl32     $5, $5, 8
    /* E1F24 001E1F24 04006014 */  bnez       $3, .L001E1F38
    /* E1F28 001E1F28 00000000 */   nop
    /* E1F2C 001E1F2C 2D100000 */  daddu      $2, $0, $0
    /* E1F30 001E1F30 0B000010 */  b          .L001E1F60
    /* E1F34 001E1F34 00000000 */   nop
  .L001E1F38:
    /* E1F38 001E1F38 2D200002 */  daddu      $4, $16, $0
    /* E1F3C 001E1F3C 40100300 */  sll        $2, $3, 1
    /* E1F40 001E1F40 21104300 */  addu       $2, $2, $3
    /* E1F44 001E1F44 80180200 */  sll        $3, $2, 2
    /* E1F48 001E1F48 6100023C */  lui        $2, %hi(D_00609850)
    /* E1F4C 001E1F4C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E1F50 001E1F50 21104300 */  addu       $2, $2, $3
    /* E1F54 001E1F54 0000428C */  lw         $2, 0x0($2)
    /* E1F58 001E1F58 09F84000 */  jalr       $2
    /* E1F5C 001E1F5C 00000000 */   nop
  .L001E1F60:
    /* E1F60 001E1F60 02000010 */  b          .L001E1F6C
    /* E1F64 001E1F64 00000000 */   nop
  .L001E1F68:
    /* E1F68 001E1F68 2D100000 */  daddu      $2, $0, $0
  .L001E1F6C:
    /* E1F6C 001E1F6C 2B200200 */  sltu       $4, $0, $2
    /* E1F70 001E1F70 D4730A0C */  jal        func_0029cf50
    /* E1F74 001E1F74 00000000 */   nop
    /* E1F78 001E1F78 01000224 */  addiu      $2, $0, 0x1
    /* E1F7C 001E1F7C 1000BFDF */  ld         $31, 0x10($29)
    /* E1F80 001E1F80 0000B07B */  lq         $16, 0x0($29)
    /* E1F84 001E1F84 2000BD27 */  addiu      $29, $29, 0x20
    /* E1F88 001E1F88 0800E003 */  jr         $31
    /* E1F8C 001E1F8C 00000000 */   nop
.size func_001e1ea0, 0xf0
