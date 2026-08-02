.section .text
.set noat
.set noreorder
glabel func_001dff70
    /* DFF70 001DFF70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DFF74 001DFF74 0000BFFF */  sd         $31, 0x0($29)
    /* DFF78 001DFF78 14740A0C */  jal        func_0029d050
    /* DFF7C 001DFF7C 00000000 */   nop
    /* DFF80 001DFF80 2D204000 */  daddu      $4, $2, $0
    /* DFF84 001DFF84 2D280000 */  daddu      $5, $0, $0
    /* DFF88 001DFF88 6100023C */  lui        $2, %hi(D_00609934)
    /* DFF8C 001DFF8C 3499428C */  lw         $2, %lo(D_00609934)($2)
    /* DFF90 001DFF90 09F84000 */  jalr       $2
    /* DFF94 001DFF94 00000000 */   nop
    /* DFF98 001DFF98 2B200200 */  sltu       $4, $0, $2
    /* DFF9C 001DFF9C D4730A0C */  jal        func_0029cf50
    /* DFFA0 001DFFA0 00000000 */   nop
    /* DFFA4 001DFFA4 01000224 */  addiu      $2, $0, 0x1
    /* DFFA8 001DFFA8 0000BFDF */  ld         $31, 0x0($29)
    /* DFFAC 001DFFAC 1000BD27 */  addiu      $29, $29, 0x10
    /* DFFB0 001DFFB0 0800E003 */  jr         $31
    /* DFFB4 001DFFB4 00000000 */   nop
    /* DFFB8 001DFFB8 00000000 */  nop
    /* DFFBC 001DFFBC 00000000 */  nop
.size func_001dff70, 0x50
