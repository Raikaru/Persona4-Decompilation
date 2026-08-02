.section .text
.set noat
.set noreorder
glabel func_001e3a30
    /* E3A30 001E3A30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E3A34 001E3A34 1000BFFF */  sd         $31, 0x10($29)
    /* E3A38 001E3A38 0000B07F */  sq         $16, 0x0($29)
    /* E3A3C 001E3A3C 2D200000 */  daddu      $4, $0, $0
    /* E3A40 001E3A40 00730A0C */  jal        func_0029cc00
    /* E3A44 001E3A44 00000000 */   nop
    /* E3A48 001E3A48 3C1A0200 */  dsll32     $3, $2, 8
    /* E3A4C 001E3A4C 3E1A0300 */  dsrl32     $3, $3, 8
    /* E3A50 001E3A50 0040023C */  lui        $2, (0x40000000 >> 16)
    /* E3A54 001E3A54 25806200 */  or         $16, $3, $2
    /* E3A58 001E3A58 14740A0C */  jal        func_0029d050
    /* E3A5C 001E3A5C 00000000 */   nop
    /* E3A60 001E3A60 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* E3A64 001E3A64 24180302 */  and        $3, $16, $3
    /* E3A68 001E3A68 021E0300 */  srl        $3, $3, 24
    /* E3A6C 001E3A6C 3C2A1000 */  dsll32     $5, $16, 8
    /* E3A70 001E3A70 3E2A0500 */  dsrl32     $5, $5, 8
    /* E3A74 001E3A74 04006014 */  bnez       $3, .L001E3A88
    /* E3A78 001E3A78 00000000 */   nop
    /* E3A7C 001E3A7C 2D100000 */  daddu      $2, $0, $0
    /* E3A80 001E3A80 0B000010 */  b          .L001E3AB0
    /* E3A84 001E3A84 00000000 */   nop
  .L001E3A88:
    /* E3A88 001E3A88 2D204000 */  daddu      $4, $2, $0
    /* E3A8C 001E3A8C 40100300 */  sll        $2, $3, 1
    /* E3A90 001E3A90 21104300 */  addu       $2, $2, $3
    /* E3A94 001E3A94 80180200 */  sll        $3, $2, 2
    /* E3A98 001E3A98 6100023C */  lui        $2, %hi(D_00609850)
    /* E3A9C 001E3A9C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E3AA0 001E3AA0 21104300 */  addu       $2, $2, $3
    /* E3AA4 001E3AA4 0000428C */  lw         $2, 0x0($2)
    /* E3AA8 001E3AA8 09F84000 */  jalr       $2
    /* E3AAC 001E3AAC 00000000 */   nop
  .L001E3AB0:
    /* E3AB0 001E3AB0 2B200200 */  sltu       $4, $0, $2
    /* E3AB4 001E3AB4 D4730A0C */  jal        func_0029cf50
    /* E3AB8 001E3AB8 00000000 */   nop
    /* E3ABC 001E3ABC 01000224 */  addiu      $2, $0, 0x1
    /* E3AC0 001E3AC0 1000BFDF */  ld         $31, 0x10($29)
    /* E3AC4 001E3AC4 0000B07B */  lq         $16, 0x0($29)
    /* E3AC8 001E3AC8 2000BD27 */  addiu      $29, $29, 0x20
    /* E3ACC 001E3ACC 0800E003 */  jr         $31
    /* E3AD0 001E3AD0 00000000 */   nop
    /* E3AD4 001E3AD4 00000000 */  nop
    /* E3AD8 001E3AD8 00000000 */  nop
    /* E3ADC 001E3ADC 00000000 */  nop
.size func_001e3a30, 0xb0
