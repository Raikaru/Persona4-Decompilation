.section .text
.set noat
.set noreorder
glabel func_001e0f10
    /* E0F10 001E0F10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E0F14 001E0F14 0000BFFF */  sd         $31, 0x0($29)
    /* E0F18 001E0F18 14740A0C */  jal        func_0029d050
    /* E0F1C 001E0F1C 00000000 */   nop
    /* E0F20 001E0F20 2D204000 */  daddu      $4, $2, $0
    /* E0F24 001E0F24 2D280000 */  daddu      $5, $0, $0
    /* E0F28 001E0F28 6100023C */  lui        $2, %hi(D_00609A6C)
    /* E0F2C 001E0F2C 6C9A428C */  lw         $2, %lo(D_00609A6C)($2)
    /* E0F30 001E0F30 09F84000 */  jalr       $2
    /* E0F34 001E0F34 00000000 */   nop
    /* E0F38 001E0F38 2B200200 */  sltu       $4, $0, $2
    /* E0F3C 001E0F3C D4730A0C */  jal        func_0029cf50
    /* E0F40 001E0F40 00000000 */   nop
    /* E0F44 001E0F44 01000224 */  addiu      $2, $0, 0x1
    /* E0F48 001E0F48 0000BFDF */  ld         $31, 0x0($29)
    /* E0F4C 001E0F4C 1000BD27 */  addiu      $29, $29, 0x10
    /* E0F50 001E0F50 0800E003 */  jr         $31
    /* E0F54 001E0F54 00000000 */   nop
    /* E0F58 001E0F58 00000000 */  nop
    /* E0F5C 001E0F5C 00000000 */  nop
.size func_001e0f10, 0x50
