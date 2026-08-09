.section .text
.set noat
.set noreorder
glabel func_004ef838
    /* 3EF838 004EF838 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EF83C 004EF83C 06008014 */  bnez       $4, .L004EF858
    /* 3EF840 004EF840 0000BFFF */   sd        $31, 0x0($29)
    /* 3EF844 004EF844 7600043C */  lui        $4, %hi(D_0075D068)
    /* 3EF848 004EF848 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EF84C 004EF84C 68D08424 */  addiu      $4, $4, %lo(D_0075D068)
    /* 3EF850 004EF850 08000010 */  b          .L004EF874
    /* 3EF854 004EF854 F8CEA524 */   addiu     $5, $5, %lo(D_0075CEF8)
  .L004EF858:
    /* 3EF858 004EF858 04008280 */  lb         $2, 0x4($4)
    /* 3EF85C 004EF85C 0A004054 */  bnel       $2, $0, .L004EF888
    /* 3EF860 004EF860 1400848C */   lw        $4, 0x14($4)
    /* 3EF864 004EF864 7600043C */  lui        $4, %hi(D_0075D078)
    /* 3EF868 004EF868 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EF86C 004EF86C 78D08424 */  addiu      $4, $4, %lo(D_0075D078)
    /* 3EF870 004EF870 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
  .L004EF874:
    /* 3EF874 004EF874 B6BA130C */  jal        func_004eead8
    /* 3EF878 004EF878 00000000 */   nop
    /* 3EF87C 004EF87C 0B000010 */  b          .L004EF8AC
    /* 3EF880 004EF880 2D100000 */   daddu     $2, $0, $0
    /* 3EF884 004EF884 00000000 */  nop
  .L004EF888:
    /* 3EF888 004EF888 08008010 */  beqz       $4, .L004EF8AC
    /* 3EF88C 004EF88C 2D100000 */   daddu     $2, $0, $0
  .L004EF890:
    /* 3EF890 004EF890 0000848C */  lw         $4, 0x0($4)
    /* 3EF894 004EF894 00000000 */  nop
    /* 3EF898 004EF898 00000000 */  nop
    /* 3EF89C 004EF89C 00000000 */  nop
    /* 3EF8A0 004EF8A0 00000000 */  nop
    /* 3EF8A4 004EF8A4 FAFF8014 */  bnez       $4, .L004EF890
    /* 3EF8A8 004EF8A8 01004224 */   addiu     $2, $2, 0x1
  .L004EF8AC:
    /* 3EF8AC 004EF8AC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF8B0 004EF8B0 0800E003 */  jr         $31
    /* 3EF8B4 004EF8B4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ef838, 0x80
