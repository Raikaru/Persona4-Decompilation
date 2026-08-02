.section .text
.set noat
.set noreorder
glabel func_001e3ce0
    /* E3CE0 001E3CE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E3CE4 001E3CE4 0000BFFF */  sd         $31, 0x0($29)
    /* E3CE8 001E3CE8 14740A0C */  jal        func_0029d050
    /* E3CEC 001E3CEC 00000000 */   nop
    /* E3CF0 001E3CF0 2D204000 */  daddu      $4, $2, $0
    /* E3CF4 001E3CF4 2D280000 */  daddu      $5, $0, $0
    /* E3CF8 001E3CF8 6100023C */  lui        $2, %hi(D_00609B8C)
    /* E3CFC 001E3CFC 8C9B428C */  lw         $2, %lo(D_00609B8C)($2)
    /* E3D00 001E3D00 09F84000 */  jalr       $2
    /* E3D04 001E3D04 00000000 */   nop
    /* E3D08 001E3D08 2B200200 */  sltu       $4, $0, $2
    /* E3D0C 001E3D0C D4730A0C */  jal        func_0029cf50
    /* E3D10 001E3D10 00000000 */   nop
    /* E3D14 001E3D14 01000224 */  addiu      $2, $0, 0x1
    /* E3D18 001E3D18 0000BFDF */  ld         $31, 0x0($29)
    /* E3D1C 001E3D1C 1000BD27 */  addiu      $29, $29, 0x10
    /* E3D20 001E3D20 0800E003 */  jr         $31
    /* E3D24 001E3D24 00000000 */   nop
    /* E3D28 001E3D28 00000000 */  nop
    /* E3D2C 001E3D2C 00000000 */  nop
.size func_001e3ce0, 0x50
