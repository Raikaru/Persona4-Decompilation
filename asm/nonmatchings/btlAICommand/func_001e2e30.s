.section .text
.set noat
.set noreorder
glabel func_001e2e30
    /* E2E30 001E2E30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E2E34 001E2E34 1000BFFF */  sd         $31, 0x10($29)
    /* E2E38 001E2E38 0000B07F */  sq         $16, 0x0($29)
    /* E2E3C 001E2E3C 14740A0C */  jal        func_0029d050
    /* E2E40 001E2E40 00000000 */   nop
    /* E2E44 001E2E44 3000428C */  lw         $2, 0x30($2)
    /* E2E48 001E2E48 A2004290 */  lbu        $2, 0xA2($2)
    /* E2E4C 001E2E4C 04004014 */  bnez       $2, .L001E2E60
    /* E2E50 001E2E50 00000000 */   nop
    /* E2E54 001E2E54 01001024 */  addiu      $16, $0, 0x1
    /* E2E58 001E2E58 02000010 */  b          .L001E2E64
    /* E2E5C 001E2E5C 00000000 */   nop
  .L001E2E60:
    /* E2E60 001E2E60 2D800000 */  daddu      $16, $0, $0
  .L001E2E64:
    /* E2E64 001E2E64 2D200000 */  daddu      $4, $0, $0
    /* E2E68 001E2E68 00730A0C */  jal        func_0029cc00
    /* E2E6C 001E2E6C 00000000 */   nop
    /* E2E70 001E2E70 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E2E74 001E2E74 01000224 */  addiu      $2, $0, 0x1
    /* E2E78 001E2E78 04100202 */  sllv       $2, $2, $16
    /* E2E7C 001E2E7C FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E2E80 001E2E80 0800063C */  lui        $6, (0x80000 >> 16)
    /* E2E84 001E2E84 A064070C */  jal        func_001d9280
    /* E2E88 001E2E88 00000000 */   nop
    /* E2E8C 001E2E8C 2D804000 */  daddu      $16, $2, $0
    /* E2E90 001E2E90 1E000012 */  beqz       $16, .L001E2F0C
    /* E2E94 001E2E94 00000000 */   nop
    /* E2E98 001E2E98 01000424 */  addiu      $4, $0, 0x1
    /* E2E9C 001E2E9C 00730A0C */  jal        func_0029cc00
    /* E2EA0 001E2EA0 00000000 */   nop
    /* E2EA4 001E2EA4 3C1A0200 */  dsll32     $3, $2, 8
    /* E2EA8 001E2EA8 3E1A0300 */  dsrl32     $3, $3, 8
    /* E2EAC 001E2EAC 0018023C */  lui        $2, (0x18000000 >> 16)
    /* E2EB0 001E2EB0 25206200 */  or         $4, $3, $2
    /* E2EB4 001E2EB4 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E2EB8 001E2EB8 24108200 */  and        $2, $4, $2
    /* E2EBC 001E2EBC 021E0200 */  srl        $3, $2, 24
    /* E2EC0 001E2EC0 3C2A0400 */  dsll32     $5, $4, 8
    /* E2EC4 001E2EC4 3E2A0500 */  dsrl32     $5, $5, 8
    /* E2EC8 001E2EC8 04006014 */  bnez       $3, .L001E2EDC
    /* E2ECC 001E2ECC 00000000 */   nop
    /* E2ED0 001E2ED0 2D100000 */  daddu      $2, $0, $0
    /* E2ED4 001E2ED4 0B000010 */  b          .L001E2F04
    /* E2ED8 001E2ED8 00000000 */   nop
  .L001E2EDC:
    /* E2EDC 001E2EDC 2D200002 */  daddu      $4, $16, $0
    /* E2EE0 001E2EE0 40100300 */  sll        $2, $3, 1
    /* E2EE4 001E2EE4 21104300 */  addu       $2, $2, $3
    /* E2EE8 001E2EE8 80180200 */  sll        $3, $2, 2
    /* E2EEC 001E2EEC 6100023C */  lui        $2, %hi(D_00609850)
    /* E2EF0 001E2EF0 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E2EF4 001E2EF4 21104300 */  addu       $2, $2, $3
    /* E2EF8 001E2EF8 0000428C */  lw         $2, 0x0($2)
    /* E2EFC 001E2EFC 09F84000 */  jalr       $2
    /* E2F00 001E2F00 00000000 */   nop
  .L001E2F04:
    /* E2F04 001E2F04 02000010 */  b          .L001E2F10
    /* E2F08 001E2F08 00000000 */   nop
  .L001E2F0C:
    /* E2F0C 001E2F0C 2D100000 */  daddu      $2, $0, $0
  .L001E2F10:
    /* E2F10 001E2F10 2B200200 */  sltu       $4, $0, $2
    /* E2F14 001E2F14 D4730A0C */  jal        func_0029cf50
    /* E2F18 001E2F18 00000000 */   nop
    /* E2F1C 001E2F1C 01000224 */  addiu      $2, $0, 0x1
    /* E2F20 001E2F20 1000BFDF */  ld         $31, 0x10($29)
    /* E2F24 001E2F24 0000B07B */  lq         $16, 0x0($29)
    /* E2F28 001E2F28 2000BD27 */  addiu      $29, $29, 0x20
    /* E2F2C 001E2F2C 0800E003 */  jr         $31
    /* E2F30 001E2F30 00000000 */   nop
    /* E2F34 001E2F34 00000000 */  nop
    /* E2F38 001E2F38 00000000 */  nop
    /* E2F3C 001E2F3C 00000000 */  nop
.size func_001e2e30, 0x110
