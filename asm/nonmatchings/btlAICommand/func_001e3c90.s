.section .text
.set noat
.set noreorder
glabel func_001e3c90
    /* E3C90 001E3C90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E3C94 001E3C94 0000BFFF */  sd         $31, 0x0($29)
    /* E3C98 001E3C98 14740A0C */  jal        func_0029d050
    /* E3C9C 001E3C9C 00000000 */   nop
    /* E3CA0 001E3CA0 2D204000 */  daddu      $4, $2, $0
    /* E3CA4 001E3CA4 2D280000 */  daddu      $5, $0, $0
    /* E3CA8 001E3CA8 6100023C */  lui        $2, %hi(D_00609B80)
    /* E3CAC 001E3CAC 809B428C */  lw         $2, %lo(D_00609B80)($2)
    /* E3CB0 001E3CB0 09F84000 */  jalr       $2
    /* E3CB4 001E3CB4 00000000 */   nop
    /* E3CB8 001E3CB8 2B200200 */  sltu       $4, $0, $2
    /* E3CBC 001E3CBC D4730A0C */  jal        func_0029cf50
    /* E3CC0 001E3CC0 00000000 */   nop
    /* E3CC4 001E3CC4 01000224 */  addiu      $2, $0, 0x1
    /* E3CC8 001E3CC8 0000BFDF */  ld         $31, 0x0($29)
    /* E3CCC 001E3CCC 1000BD27 */  addiu      $29, $29, 0x10
    /* E3CD0 001E3CD0 0800E003 */  jr         $31
    /* E3CD4 001E3CD4 00000000 */   nop
    /* E3CD8 001E3CD8 00000000 */  nop
    /* E3CDC 001E3CDC 00000000 */  nop
.size func_001e3c90, 0x50
