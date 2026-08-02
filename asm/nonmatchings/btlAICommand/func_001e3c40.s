.section .text
.set noat
.set noreorder
glabel func_001e3c40
    /* E3C40 001E3C40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E3C44 001E3C44 0000BFFF */  sd         $31, 0x0($29)
    /* E3C48 001E3C48 14740A0C */  jal        func_0029d050
    /* E3C4C 001E3C4C 00000000 */   nop
    /* E3C50 001E3C50 2D204000 */  daddu      $4, $2, $0
    /* E3C54 001E3C54 2D280000 */  daddu      $5, $0, $0
    /* E3C58 001E3C58 6100023C */  lui        $2, %hi(D_00609B74)
    /* E3C5C 001E3C5C 749B428C */  lw         $2, %lo(D_00609B74)($2)
    /* E3C60 001E3C60 09F84000 */  jalr       $2
    /* E3C64 001E3C64 00000000 */   nop
    /* E3C68 001E3C68 2B200200 */  sltu       $4, $0, $2
    /* E3C6C 001E3C6C D4730A0C */  jal        func_0029cf50
    /* E3C70 001E3C70 00000000 */   nop
    /* E3C74 001E3C74 01000224 */  addiu      $2, $0, 0x1
    /* E3C78 001E3C78 0000BFDF */  ld         $31, 0x0($29)
    /* E3C7C 001E3C7C 1000BD27 */  addiu      $29, $29, 0x10
    /* E3C80 001E3C80 0800E003 */  jr         $31
    /* E3C84 001E3C84 00000000 */   nop
    /* E3C88 001E3C88 00000000 */  nop
    /* E3C8C 001E3C8C 00000000 */  nop
.size func_001e3c40, 0x50
