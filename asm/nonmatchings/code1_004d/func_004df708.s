.section .text
.set noat
.set noreorder
glabel func_004df708
    /* 3DF708 004DF708 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DF70C 004DF70C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DF710 004DF710 2D808000 */  daddu      $16, $4, $0
    /* 3DF714 004DF714 1000B2FF */  sd         $18, 0x10($29)
    /* 3DF718 004DF718 2D900000 */  daddu      $18, $0, $0
    /* 3DF71C 004DF71C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DF720 004DF720 1800BFFF */  sd         $31, 0x18($29)
    /* 3DF724 004DF724 C047130C */  jal        func_004d1f00
    /* 3DF728 004DF728 0800048E */   lw        $4, 0x8($16)
    /* 3DF72C 004DF72C 9000048E */  lw         $4, 0x90($16)
    /* 3DF730 004DF730 0000838C */  lw         $3, 0x0($4)
    /* 3DF734 004DF734 1400628C */  lw         $2, 0x14($3)
    /* 3DF738 004DF738 09F84000 */  jalr       $2
    /* 3DF73C 004DF73C 00000000 */   nop
    /* 3DF740 004DF740 03000382 */  lb         $3, 0x3($16)
    /* 3DF744 004DF744 0E006058 */  blezl      $3, .L004DF780
    /* 3DF748 004DF748 D401078E */   lw        $7, 0x1D4($16)
    /* 3DF74C 004DF74C 94001126 */  addiu      $17, $16, 0x94
    /* 3DF750 004DF750 0000248E */  lw         $4, 0x0($17)
    /* 3DF754 004DF754 00000000 */  nop
  .L004DF758:
    /* 3DF758 004DF758 04003126 */  addiu      $17, $17, 0x4
    /* 3DF75C 004DF75C 0000828C */  lw         $2, 0x0($4)
    /* 3DF760 004DF760 1400438C */  lw         $3, 0x14($2)
    /* 3DF764 004DF764 09F86000 */  jalr       $3
    /* 3DF768 004DF768 01005226 */   addiu     $18, $18, 0x1
    /* 3DF76C 004DF76C 03000282 */  lb         $2, 0x3($16)
    /* 3DF770 004DF770 2A104202 */  slt        $2, $18, $2
    /* 3DF774 004DF774 F8FF4054 */  bnel       $2, $0, .L004DF758
    /* 3DF778 004DF778 0000248E */   lw        $4, 0x0($17)
    /* 3DF77C 004DF77C D401078E */  lw         $7, 0x1D4($16)
  .L004DF780:
    /* 3DF780 004DF780 D801088E */  lw         $8, 0x1D8($16)
    /* 3DF784 004DF784 0800048E */  lw         $4, 0x8($16)
    /* 3DF788 004DF788 CC01058E */  lw         $5, 0x1CC($16)
    /* 3DF78C 004DF78C 5C47130C */  jal        func_004d1d70
    /* 3DF790 004DF790 D001068E */   lw        $6, 0x1D0($16)
    /* 3DF794 004DF794 1801058E */  lw         $5, 0x118($16)
    /* 3DF798 004DF798 0800048E */  lw         $4, 0x8($16)
    /* 3DF79C 004DF79C FF7F063C */  lui        $6, (0x7FFFFFFF >> 16)
    /* 3DF7A0 004DF7A0 C2170500 */  srl        $2, $5, 31
    /* 3DF7A4 004DF7A4 FFFFC634 */  ori        $6, $6, (0x7FFFFFFF & 0xFFFF)
    /* 3DF7A8 004DF7A8 2128A200 */  addu       $5, $5, $2
    /* 3DF7AC 004DF7AC 0C4B130C */  jal        func_004d2c30
    /* 3DF7B0 004DF7B0 43280500 */   sra       $5, $5, 1
    /* 3DF7B4 004DF7B4 0800048E */  lw         $4, 0x8($16)
    /* 3DF7B8 004DF7B8 0E48130C */  jal        func_004d2038
    /* 3DF7BC 004DF7BC 2D280000 */   daddu     $5, $0, $0
    /* 3DF7C0 004DF7C0 0800048E */  lw         $4, 0x8($16)
    /* 3DF7C4 004DF7C4 EA48130C */  jal        func_004d23a8
    /* 3DF7C8 004DF7C8 03000524 */   addiu     $5, $0, 0x3
    /* 3DF7CC 004DF7CC 4A48130C */  jal        func_004d2128
    /* 3DF7D0 004DF7D0 0800048E */   lw        $4, 0x8($16)
    /* 3DF7D4 004DF7D4 0400048E */  lw         $4, 0x4($16)
    /* 3DF7D8 004DF7D8 7A81130C */  jal        func_004e05e8
    /* 3DF7DC 004DF7DC 01000524 */   addiu     $5, $0, 0x1
    /* 3DF7E0 004DF7E0 0400048E */  lw         $4, 0x4($16)
    /* 3DF7E4 004DF7E4 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF7E8 004DF7E8 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF7EC 004DF7EC 1000B2DF */  ld         $18, 0x10($29)
    /* 3DF7F0 004DF7F0 1800BFDF */  ld         $31, 0x18($29)
    /* 3DF7F4 004DF7F4 66811308 */  j          func_004e0598
    /* 3DF7F8 004DF7F8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF7FC 004DF7FC 00000000 */  nop
.size func_004df708, 0xf8
