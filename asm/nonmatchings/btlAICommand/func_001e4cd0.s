.section .text
.set noat
.set noreorder
glabel func_001e4cd0
    /* E4CD0 001E4CD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E4CD4 001E4CD4 1000BFFF */  sd         $31, 0x10($29)
    /* E4CD8 001E4CD8 0000B07F */  sq         $16, 0x0($29)
    /* E4CDC 001E4CDC 14740A0C */  jal        func_0029d050
    /* E4CE0 001E4CE0 00000000 */   nop
    /* E4CE4 001E4CE4 2D804000 */  daddu      $16, $2, $0
    /* E4CE8 001E4CE8 2D200002 */  daddu      $4, $16, $0
    /* E4CEC 001E4CEC 2D280000 */  daddu      $5, $0, $0
    /* E4CF0 001E4CF0 6100023C */  lui        $2, %hi(D_00609D20)
    /* E4CF4 001E4CF4 209D428C */  lw         $2, %lo(D_00609D20)($2)
    /* E4CF8 001E4CF8 09F84000 */  jalr       $2
    /* E4CFC 001E4CFC 00000000 */   nop
    /* E4D00 001E4D00 07004014 */  bnez       $2, .L001E4D20
    /* E4D04 001E4D04 00000000 */   nop
    /* E4D08 001E4D08 2D200002 */  daddu      $4, $16, $0
    /* E4D0C 001E4D0C 2D280000 */  daddu      $5, $0, $0
    /* E4D10 001E4D10 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4D14 001E4D14 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E4D18 001E4D18 09F84000 */  jalr       $2
    /* E4D1C 001E4D1C 00000000 */   nop
  .L001E4D20:
    /* E4D20 001E4D20 01000224 */  addiu      $2, $0, 0x1
    /* E4D24 001E4D24 1000BFDF */  ld         $31, 0x10($29)
    /* E4D28 001E4D28 0000B07B */  lq         $16, 0x0($29)
    /* E4D2C 001E4D2C 2000BD27 */  addiu      $29, $29, 0x20
    /* E4D30 001E4D30 0800E003 */  jr         $31
    /* E4D34 001E4D34 00000000 */   nop
    /* E4D38 001E4D38 00000000 */  nop
    /* E4D3C 001E4D3C 00000000 */  nop
.size func_001e4cd0, 0x70
