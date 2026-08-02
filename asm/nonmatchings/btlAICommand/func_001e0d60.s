.section .text
.set noat
.set noreorder
glabel func_001e0d60
    /* E0D60 001E0D60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E0D64 001E0D64 0000BFFF */  sd         $31, 0x0($29)
    /* E0D68 001E0D68 14740A0C */  jal        func_0029d050
    /* E0D6C 001E0D6C 00000000 */   nop
    /* E0D70 001E0D70 2D204000 */  daddu      $4, $2, $0
    /* E0D74 001E0D74 2D280000 */  daddu      $5, $0, $0
    /* E0D78 001E0D78 6100023C */  lui        $2, %hi(D_00609A48)
    /* E0D7C 001E0D7C 489A428C */  lw         $2, %lo(D_00609A48)($2)
    /* E0D80 001E0D80 09F84000 */  jalr       $2
    /* E0D84 001E0D84 00000000 */   nop
    /* E0D88 001E0D88 2B200200 */  sltu       $4, $0, $2
    /* E0D8C 001E0D8C D4730A0C */  jal        func_0029cf50
    /* E0D90 001E0D90 00000000 */   nop
    /* E0D94 001E0D94 01000224 */  addiu      $2, $0, 0x1
    /* E0D98 001E0D98 0000BFDF */  ld         $31, 0x0($29)
    /* E0D9C 001E0D9C 1000BD27 */  addiu      $29, $29, 0x10
    /* E0DA0 001E0DA0 0800E003 */  jr         $31
    /* E0DA4 001E0DA4 00000000 */   nop
    /* E0DA8 001E0DA8 00000000 */  nop
    /* E0DAC 001E0DAC 00000000 */  nop
.size func_001e0d60, 0x50
