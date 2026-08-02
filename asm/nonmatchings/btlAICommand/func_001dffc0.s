.section .text
.set noat
.set noreorder
glabel func_001dffc0
    /* DFFC0 001DFFC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DFFC4 001DFFC4 0000BFFF */  sd         $31, 0x0($29)
    /* DFFC8 001DFFC8 14740A0C */  jal        func_0029d050
    /* DFFCC 001DFFCC 00000000 */   nop
    /* DFFD0 001DFFD0 2D204000 */  daddu      $4, $2, $0
    /* DFFD4 001DFFD4 2D280000 */  daddu      $5, $0, $0
    /* DFFD8 001DFFD8 6100023C */  lui        $2, %hi(D_00609940)
    /* DFFDC 001DFFDC 4099428C */  lw         $2, %lo(D_00609940)($2)
    /* DFFE0 001DFFE0 09F84000 */  jalr       $2
    /* DFFE4 001DFFE4 00000000 */   nop
    /* DFFE8 001DFFE8 2B200200 */  sltu       $4, $0, $2
    /* DFFEC 001DFFEC D4730A0C */  jal        func_0029cf50
    /* DFFF0 001DFFF0 00000000 */   nop
    /* DFFF4 001DFFF4 01000224 */  addiu      $2, $0, 0x1
    /* DFFF8 001DFFF8 0000BFDF */  ld         $31, 0x0($29)
    /* DFFFC 001DFFFC 1000BD27 */  addiu      $29, $29, 0x10
    /* E0000 001E0000 0800E003 */  jr         $31
    /* E0004 001E0004 00000000 */   nop
    /* E0008 001E0008 00000000 */  nop
    /* E000C 001E000C 00000000 */  nop
.size func_001dffc0, 0x50
