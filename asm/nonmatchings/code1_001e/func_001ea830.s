.section .text
.set noat
.set noreorder
glabel func_001ea830
    /* EA830 001EA830 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA834 001EA834 0000BFFF */  sd         $31, 0x0($29)
    /* EA838 001EA838 2D200000 */  daddu      $4, $0, $0
    /* EA83C 001EA83C 54730A0C */  jal        func_0029cd50
    /* EA840 001EA840 00000000 */   nop
    /* EA844 001EA844 8800023C */  lui        $2, %hi(D_00881410)
    /* EA848 001EA848 101440E4 */  swc1       $f0, %lo(D_00881410)($2)
    /* EA84C 001EA84C 01000424 */  addiu      $4, $0, 0x1
    /* EA850 001EA850 54730A0C */  jal        func_0029cd50
    /* EA854 001EA854 00000000 */   nop
    /* EA858 001EA858 8800023C */  lui        $2, %hi(D_00881414)
    /* EA85C 001EA85C 141440E4 */  swc1       $f0, %lo(D_00881414)($2)
    /* EA860 001EA860 02000424 */  addiu      $4, $0, 0x2
    /* EA864 001EA864 54730A0C */  jal        func_0029cd50
    /* EA868 001EA868 00000000 */   nop
    /* EA86C 001EA86C 8800023C */  lui        $2, %hi(D_00881418)
    /* EA870 001EA870 181440E4 */  swc1       $f0, %lo(D_00881418)($2)
    /* EA874 001EA874 03000424 */  addiu      $4, $0, 0x3
    /* EA878 001EA878 54730A0C */  jal        func_0029cd50
    /* EA87C 001EA87C 00000000 */   nop
    /* EA880 001EA880 8800023C */  lui        $2, %hi(D_008813F0)
    /* EA884 001EA884 F01340E4 */  swc1       $f0, %lo(D_008813F0)($2)
    /* EA888 001EA888 04000424 */  addiu      $4, $0, 0x4
    /* EA88C 001EA88C 54730A0C */  jal        func_0029cd50
    /* EA890 001EA890 00000000 */   nop
    /* EA894 001EA894 8800023C */  lui        $2, %hi(D_008813F4)
    /* EA898 001EA898 F41340E4 */  swc1       $f0, %lo(D_008813F4)($2)
    /* EA89C 001EA89C 05000424 */  addiu      $4, $0, 0x5
    /* EA8A0 001EA8A0 54730A0C */  jal        func_0029cd50
    /* EA8A4 001EA8A4 00000000 */   nop
    /* EA8A8 001EA8A8 8800023C */  lui        $2, %hi(D_008813F8)
    /* EA8AC 001EA8AC F81340E4 */  swc1       $f0, %lo(D_008813F8)($2)
    /* EA8B0 001EA8B0 06000424 */  addiu      $4, $0, 0x6
    /* EA8B4 001EA8B4 54730A0C */  jal        func_0029cd50
    /* EA8B8 001EA8B8 00000000 */   nop
    /* EA8BC 001EA8BC 54B480E7 */  swc1       $f0, -0x4BAC($28)
    /* EA8C0 001EA8C0 01000224 */  addiu      $2, $0, 0x1
    /* EA8C4 001EA8C4 0000BFDF */  ld         $31, 0x0($29)
    /* EA8C8 001EA8C8 1000BD27 */  addiu      $29, $29, 0x10
    /* EA8CC 001EA8CC 0800E003 */  jr         $31
    /* EA8D0 001EA8D0 00000000 */   nop
    /* EA8D4 001EA8D4 00000000 */  nop
    /* EA8D8 001EA8D8 00000000 */  nop
    /* EA8DC 001EA8DC 00000000 */  nop
.size func_001ea830, 0xb0
