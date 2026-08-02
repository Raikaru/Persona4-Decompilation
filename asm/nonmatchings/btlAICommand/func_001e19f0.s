.section .text
.set noat
.set noreorder
glabel func_001e19f0
    /* E19F0 001E19F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E19F4 001E19F4 1000BFFF */  sd         $31, 0x10($29)
    /* E19F8 001E19F8 0000B07F */  sq         $16, 0x0($29)
    /* E19FC 001E19FC 14740A0C */  jal        func_0029d050
    /* E1A00 001E1A00 00000000 */   nop
    /* E1A04 001E1A04 2D804000 */  daddu      $16, $2, $0
    /* E1A08 001E1A08 2D200000 */  daddu      $4, $0, $0
    /* E1A0C 001E1A0C 00730A0C */  jal        func_0029cc00
    /* E1A10 001E1A10 00000000 */   nop
    /* E1A14 001E1A14 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E1A18 001E1A18 3000028E */  lw         $2, 0x30($16)
    /* E1A1C 001E1A1C A2004390 */  lbu        $3, 0xA2($2)
    /* E1A20 001E1A20 01000224 */  addiu      $2, $0, 0x1
    /* E1A24 001E1A24 04106200 */  sllv       $2, $2, $3
    /* E1A28 001E1A28 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E1A2C 001E1A2C 0800063C */  lui        $6, (0x80000 >> 16)
    /* E1A30 001E1A30 A064070C */  jal        func_001d9280
    /* E1A34 001E1A34 00000000 */   nop
    /* E1A38 001E1A38 2D804000 */  daddu      $16, $2, $0
    /* E1A3C 001E1A3C 1E000012 */  beqz       $16, .L001E1AB8
    /* E1A40 001E1A40 00000000 */   nop
    /* E1A44 001E1A44 01000424 */  addiu      $4, $0, 0x1
    /* E1A48 001E1A48 00730A0C */  jal        func_0029cc00
    /* E1A4C 001E1A4C 00000000 */   nop
    /* E1A50 001E1A50 3C1A0200 */  dsll32     $3, $2, 8
    /* E1A54 001E1A54 3E1A0300 */  dsrl32     $3, $3, 8
    /* E1A58 001E1A58 0016023C */  lui        $2, (0x16000000 >> 16)
    /* E1A5C 001E1A5C 25206200 */  or         $4, $3, $2
    /* E1A60 001E1A60 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E1A64 001E1A64 24108200 */  and        $2, $4, $2
    /* E1A68 001E1A68 021E0200 */  srl        $3, $2, 24
    /* E1A6C 001E1A6C 3C2A0400 */  dsll32     $5, $4, 8
    /* E1A70 001E1A70 3E2A0500 */  dsrl32     $5, $5, 8
    /* E1A74 001E1A74 04006014 */  bnez       $3, .L001E1A88
    /* E1A78 001E1A78 00000000 */   nop
    /* E1A7C 001E1A7C 2D100000 */  daddu      $2, $0, $0
    /* E1A80 001E1A80 0B000010 */  b          .L001E1AB0
    /* E1A84 001E1A84 00000000 */   nop
  .L001E1A88:
    /* E1A88 001E1A88 2D200002 */  daddu      $4, $16, $0
    /* E1A8C 001E1A8C 40100300 */  sll        $2, $3, 1
    /* E1A90 001E1A90 21104300 */  addu       $2, $2, $3
    /* E1A94 001E1A94 80180200 */  sll        $3, $2, 2
    /* E1A98 001E1A98 6100023C */  lui        $2, %hi(D_00609850)
    /* E1A9C 001E1A9C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E1AA0 001E1AA0 21104300 */  addu       $2, $2, $3
    /* E1AA4 001E1AA4 0000428C */  lw         $2, 0x0($2)
    /* E1AA8 001E1AA8 09F84000 */  jalr       $2
    /* E1AAC 001E1AAC 00000000 */   nop
  .L001E1AB0:
    /* E1AB0 001E1AB0 02000010 */  b          .L001E1ABC
    /* E1AB4 001E1AB4 00000000 */   nop
  .L001E1AB8:
    /* E1AB8 001E1AB8 2D100000 */  daddu      $2, $0, $0
  .L001E1ABC:
    /* E1ABC 001E1ABC 2B200200 */  sltu       $4, $0, $2
    /* E1AC0 001E1AC0 D4730A0C */  jal        func_0029cf50
    /* E1AC4 001E1AC4 00000000 */   nop
    /* E1AC8 001E1AC8 01000224 */  addiu      $2, $0, 0x1
    /* E1ACC 001E1ACC 1000BFDF */  ld         $31, 0x10($29)
    /* E1AD0 001E1AD0 0000B07B */  lq         $16, 0x0($29)
    /* E1AD4 001E1AD4 2000BD27 */  addiu      $29, $29, 0x20
    /* E1AD8 001E1AD8 0800E003 */  jr         $31
    /* E1ADC 001E1ADC 00000000 */   nop
.size func_001e19f0, 0xf0
