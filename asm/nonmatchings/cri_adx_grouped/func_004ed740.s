.section .text
.set noat
.set noreorder
glabel func_004ed740
    /* 3ED740 004ED740 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED744 004ED744 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED748 004ED748 2D808000 */  daddu      $16, $4, $0
    /* 3ED74C 004ED74C 0A000016 */  bnez       $16, .L004ED778
    /* 3ED750 004ED750 0800BFFF */   sd        $31, 0x8($29)
    /* 3ED754 004ED754 7600043C */  lui        $4, %hi(D_0075CC30)
    /* 3ED758 004ED758 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3ED75C 004ED75C 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED760 004ED760 30CC8424 */  addiu      $4, $4, %lo(D_0075CC30)
    /* 3ED764 004ED764 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED768 004ED768 40CCA524 */  addiu      $5, $5, %lo(D_0075CC40)
    /* 3ED76C 004ED76C 2EB51308 */  j          func_004ed4b8
    /* 3ED770 004ED770 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED774 004ED774 00000000 */  nop
  .L004ED778:
    /* 3ED778 004ED778 0400028E */  lw         $2, 0x4($16)
    /* 3ED77C 004ED77C 0A004014 */  bnez       $2, .L004ED7A8
    /* 3ED780 004ED780 2D280000 */   daddu     $5, $0, $0
    /* 3ED784 004ED784 7600043C */  lui        $4, %hi(D_0075CC60)
    /* 3ED788 004ED788 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3ED78C 004ED78C 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED790 004ED790 60CC8424 */  addiu      $4, $4, %lo(D_0075CC60)
    /* 3ED794 004ED794 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED798 004ED798 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
    /* 3ED79C 004ED79C 2EB51308 */  j          func_004ed4b8
    /* 3ED7A0 004ED7A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED7A4 004ED7A4 00000000 */  nop
  .L004ED7A8:
    /* 3ED7A8 004ED7A8 72FE100C */  jal        func_0043f9c8
    /* 3ED7AC 004ED7AC 24000624 */   addiu     $6, $0, 0x24
    /* 3ED7B0 004ED7B0 040000AE */  sw         $0, 0x4($16)
    /* 3ED7B4 004ED7B4 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED7B8 004ED7B8 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED7BC 004ED7BC 0800E003 */  jr         $31
    /* 3ED7C0 004ED7C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED7C4 004ED7C4 00000000 */  nop
.size func_004ed740, 0x88
