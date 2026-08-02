.section .text
.set noat
.set noreorder
glabel func_001e0d10
    /* E0D10 001E0D10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E0D14 001E0D14 0000BFFF */  sd         $31, 0x0($29)
    /* E0D18 001E0D18 14740A0C */  jal        func_0029d050
    /* E0D1C 001E0D1C 00000000 */   nop
    /* E0D20 001E0D20 2D204000 */  daddu      $4, $2, $0
    /* E0D24 001E0D24 2D280000 */  daddu      $5, $0, $0
    /* E0D28 001E0D28 6100023C */  lui        $2, %hi(D_00609A3C)
    /* E0D2C 001E0D2C 3C9A428C */  lw         $2, %lo(D_00609A3C)($2)
    /* E0D30 001E0D30 09F84000 */  jalr       $2
    /* E0D34 001E0D34 00000000 */   nop
    /* E0D38 001E0D38 2B200200 */  sltu       $4, $0, $2
    /* E0D3C 001E0D3C D4730A0C */  jal        func_0029cf50
    /* E0D40 001E0D40 00000000 */   nop
    /* E0D44 001E0D44 01000224 */  addiu      $2, $0, 0x1
    /* E0D48 001E0D48 0000BFDF */  ld         $31, 0x0($29)
    /* E0D4C 001E0D4C 1000BD27 */  addiu      $29, $29, 0x10
    /* E0D50 001E0D50 0800E003 */  jr         $31
    /* E0D54 001E0D54 00000000 */   nop
    /* E0D58 001E0D58 00000000 */  nop
    /* E0D5C 001E0D5C 00000000 */  nop
.size func_001e0d10, 0x50
