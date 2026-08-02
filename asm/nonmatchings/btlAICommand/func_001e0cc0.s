.section .text
.set noat
.set noreorder
glabel func_001e0cc0
    /* E0CC0 001E0CC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E0CC4 001E0CC4 0000BFFF */  sd         $31, 0x0($29)
    /* E0CC8 001E0CC8 14740A0C */  jal        func_0029d050
    /* E0CCC 001E0CCC 00000000 */   nop
    /* E0CD0 001E0CD0 2D204000 */  daddu      $4, $2, $0
    /* E0CD4 001E0CD4 2D280000 */  daddu      $5, $0, $0
    /* E0CD8 001E0CD8 6100023C */  lui        $2, %hi(D_00609A30)
    /* E0CDC 001E0CDC 309A428C */  lw         $2, %lo(D_00609A30)($2)
    /* E0CE0 001E0CE0 09F84000 */  jalr       $2
    /* E0CE4 001E0CE4 00000000 */   nop
    /* E0CE8 001E0CE8 2B200200 */  sltu       $4, $0, $2
    /* E0CEC 001E0CEC D4730A0C */  jal        func_0029cf50
    /* E0CF0 001E0CF0 00000000 */   nop
    /* E0CF4 001E0CF4 01000224 */  addiu      $2, $0, 0x1
    /* E0CF8 001E0CF8 0000BFDF */  ld         $31, 0x0($29)
    /* E0CFC 001E0CFC 1000BD27 */  addiu      $29, $29, 0x10
    /* E0D00 001E0D00 0800E003 */  jr         $31
    /* E0D04 001E0D04 00000000 */   nop
    /* E0D08 001E0D08 00000000 */  nop
    /* E0D0C 001E0D0C 00000000 */  nop
.size func_001e0cc0, 0x50
