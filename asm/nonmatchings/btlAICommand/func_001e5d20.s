.section .text
.set noat
.set noreorder
glabel func_001e5d20
    /* E5D20 001E5D20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E5D24 001E5D24 1000BFFF */  sd         $31, 0x10($29)
    /* E5D28 001E5D28 0000B07F */  sq         $16, 0x0($29)
    /* E5D2C 001E5D2C 14740A0C */  jal        func_0029d050
    /* E5D30 001E5D30 00000000 */   nop
    /* E5D34 001E5D34 2D804000 */  daddu      $16, $2, $0
    /* E5D38 001E5D38 2D200002 */  daddu      $4, $16, $0
    /* E5D3C 001E5D3C 2D280000 */  daddu      $5, $0, $0
    /* E5D40 001E5D40 6100023C */  lui        $2, %hi(D_00609E18)
    /* E5D44 001E5D44 189E428C */  lw         $2, %lo(D_00609E18)($2)
    /* E5D48 001E5D48 09F84000 */  jalr       $2
    /* E5D4C 001E5D4C 00000000 */   nop
    /* E5D50 001E5D50 07004014 */  bnez       $2, .L001E5D70
    /* E5D54 001E5D54 00000000 */   nop
    /* E5D58 001E5D58 2D200002 */  daddu      $4, $16, $0
    /* E5D5C 001E5D5C 2D280000 */  daddu      $5, $0, $0
    /* E5D60 001E5D60 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E5D64 001E5D64 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E5D68 001E5D68 09F84000 */  jalr       $2
    /* E5D6C 001E5D6C 00000000 */   nop
  .L001E5D70:
    /* E5D70 001E5D70 01000224 */  addiu      $2, $0, 0x1
    /* E5D74 001E5D74 1000BFDF */  ld         $31, 0x10($29)
    /* E5D78 001E5D78 0000B07B */  lq         $16, 0x0($29)
    /* E5D7C 001E5D7C 2000BD27 */  addiu      $29, $29, 0x20
    /* E5D80 001E5D80 0800E003 */  jr         $31
    /* E5D84 001E5D84 00000000 */   nop
    /* E5D88 001E5D88 00000000 */  nop
    /* E5D8C 001E5D8C 00000000 */  nop
.size func_001e5d20, 0x70
