.section .text
.set noat
.set noreorder
glabel func_004ed800
    /* 3ED800 004ED800 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED804 004ED804 06008014 */  bnez       $4, .L004ED820
    /* 3ED808 004ED808 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED80C 004ED80C 7600043C */  lui        $4, %hi(D_0075CC90)
    /* 3ED810 004ED810 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3ED814 004ED814 90CC8424 */  addiu      $4, $4, %lo(D_0075CC90)
    /* 3ED818 004ED818 08000010 */  b          .L004ED83C
    /* 3ED81C 004ED81C 40CCA524 */   addiu     $5, $5, %lo(D_0075CC40)
  .L004ED820:
    /* 3ED820 004ED820 0400828C */  lw         $2, 0x4($4)
    /* 3ED824 004ED824 08004054 */  bnel       $2, $0, .L004ED848
    /* 3ED828 004ED828 0800828C */   lw        $2, 0x8($4)
    /* 3ED82C 004ED82C 7600043C */  lui        $4, %hi(D_0075CCA0)
    /* 3ED830 004ED830 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3ED834 004ED834 A0CC8424 */  addiu      $4, $4, %lo(D_0075CCA0)
    /* 3ED838 004ED838 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
  .L004ED83C:
    /* 3ED83C 004ED83C 2EB5130C */  jal        func_004ed4b8
    /* 3ED840 004ED840 00000000 */   nop
    /* 3ED844 004ED844 2D100000 */  daddu      $2, $0, $0
  .L004ED848:
    /* 3ED848 004ED848 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED84C 004ED84C 0800E003 */  jr         $31
    /* 3ED850 004ED850 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED854 004ED854 00000000 */  nop
.size func_004ed800, 0x58
