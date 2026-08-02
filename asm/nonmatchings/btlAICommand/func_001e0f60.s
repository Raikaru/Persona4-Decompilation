.section .text
.set noat
.set noreorder
glabel func_001e0f60
    /* E0F60 001E0F60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E0F64 001E0F64 0000BFFF */  sd         $31, 0x0($29)
    /* E0F68 001E0F68 14740A0C */  jal        func_0029d050
    /* E0F6C 001E0F6C 00000000 */   nop
    /* E0F70 001E0F70 2D204000 */  daddu      $4, $2, $0
    /* E0F74 001E0F74 2D280000 */  daddu      $5, $0, $0
    /* E0F78 001E0F78 6100023C */  lui        $2, %hi(D_00609A78)
    /* E0F7C 001E0F7C 789A428C */  lw         $2, %lo(D_00609A78)($2)
    /* E0F80 001E0F80 09F84000 */  jalr       $2
    /* E0F84 001E0F84 00000000 */   nop
    /* E0F88 001E0F88 2B200200 */  sltu       $4, $0, $2
    /* E0F8C 001E0F8C D4730A0C */  jal        func_0029cf50
    /* E0F90 001E0F90 00000000 */   nop
    /* E0F94 001E0F94 01000224 */  addiu      $2, $0, 0x1
    /* E0F98 001E0F98 0000BFDF */  ld         $31, 0x0($29)
    /* E0F9C 001E0F9C 1000BD27 */  addiu      $29, $29, 0x10
    /* E0FA0 001E0FA0 0800E003 */  jr         $31
    /* E0FA4 001E0FA4 00000000 */   nop
    /* E0FA8 001E0FA8 00000000 */  nop
    /* E0FAC 001E0FAC 00000000 */  nop
.size func_001e0f60, 0x50
