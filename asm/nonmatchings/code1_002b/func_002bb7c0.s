.section .text
.set noat
.set noreorder
glabel func_002bb7c0
    /* 1BB7C0 002BB7C0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BB7C4 002BB7C4 2000BFFF */  sd         $31, 0x20($29)
    /* 1BB7C8 002BB7C8 1000B17F */  sq         $17, 0x10($29)
    /* 1BB7CC 002BB7CC 0000B07F */  sq         $16, 0x0($29)
    /* 1BB7D0 002BB7D0 2D888000 */  daddu      $17, $4, $0
    /* 1BB7D4 002BB7D4 DCEF0A0C */  jal        func_002bbf70
    /* 1BB7D8 002BB7D8 00000000 */   nop
    /* 1BB7DC 002BB7DC 2D804000 */  daddu      $16, $2, $0
    /* 1BB7E0 002BB7E0 78000012 */  beqz       $16, .L002BB9C4
    /* 1BB7E4 002BB7E4 00000000 */   nop
    /* 1BB7E8 002BB7E8 0000048E */  lw         $4, 0x0($16)
    /* 1BB7EC 002BB7EC 75008004 */  bltz       $4, .L002BB9C4
    /* 1BB7F0 002BB7F0 00000000 */   nop
    /* 1BB7F4 002BB7F4 04000582 */  lb         $5, 0x4($16)
    /* 1BB7F8 002BB7F8 03000324 */  addiu      $3, $0, 0x3
    /* 1BB7FC 002BB7FC 5900A310 */  beq        $5, $3, .L002BB964
    /* 1BB800 002BB800 00000000 */   nop
    /* 1BB804 002BB804 02000324 */  addiu      $3, $0, 0x2
    /* 1BB808 002BB808 1200A310 */  beq        $5, $3, .L002BB854
    /* 1BB80C 002BB80C 00000000 */   nop
    /* 1BB810 002BB810 01000324 */  addiu      $3, $0, 0x1
    /* 1BB814 002BB814 0700A310 */  beq        $5, $3, .L002BB834
    /* 1BB818 002BB818 00000000 */   nop
    /* 1BB81C 002BB81C 0300A010 */  beqz       $5, .L002BB82C
    /* 1BB820 002BB820 00000000 */   nop
    /* 1BB824 002BB824 67000010 */  b          .L002BB9C4
    /* 1BB828 002BB828 00000000 */   nop
  .L002BB82C:
    /* 1BB82C 002BB82C 65000010 */  b          .L002BB9C4
    /* 1BB830 002BB830 00000000 */   nop
  .L002BB834:
    /* 1BB834 002BB834 84DB090C */  jal        func_00276e10
    /* 1BB838 002BB838 00000000 */   nop
    /* 1BB83C 002BB83C 61004104 */  bgez       $2, .L002BB9C4
    /* 1BB840 002BB840 00000000 */   nop
    /* 1BB844 002BB844 02000324 */  addiu      $3, $0, 0x2
    /* 1BB848 002BB848 040003A2 */  sb         $3, 0x4($16)
    /* 1BB84C 002BB84C 5D000010 */  b          .L002BB9C4
    /* 1BB850 002BB850 00000000 */   nop
  .L002BB854:
    /* 1BB854 002BB854 0800038E */  lw         $3, 0x8($16)
    /* 1BB858 002BB858 12006004 */  bltz       $3, .L002BB8A4
    /* 1BB85C 002BB85C 00000000 */   nop
    /* 1BB860 002BB860 78B58283 */  lb         $2, -0x4A88($28)
    /* 1BB864 002BB864 01000624 */  addiu      $6, $0, 0x1
    /* 1BB868 002BB868 04004614 */  bne        $2, $6, .L002BB87C
    /* 1BB86C 002BB86C 00000000 */   nop
    /* 1BB870 002BB870 06000524 */  addiu      $5, $0, 0x6
    /* 1BB874 002BB874 B0E1090C */  jal        func_002786c0
    /* 1BB878 002BB878 00000000 */   nop
  .L002BB87C:
    /* 1BB87C 002BB87C 0C000582 */  lb         $5, 0xC($16)
    /* 1BB880 002BB880 0000048E */  lw         $4, 0x0($16)
    /* 1BB884 002BB884 F4DF090C */  jal        func_00277fd0
    /* 1BB888 002BB888 00000000 */   nop
    /* 1BB88C 002BB88C 0000048E */  lw         $4, 0x0($16)
    /* 1BB890 002BB890 0800058E */  lw         $5, 0x8($16)
    /* 1BB894 002BB894 F8DE090C */  jal        func_00277be0
    /* 1BB898 002BB898 00000000 */   nop
    /* 1BB89C 002BB89C FFFF0324 */  addiu      $3, $0, -0x1
    /* 1BB8A0 002BB8A0 080003AE */  sw         $3, 0x8($16)
  .L002BB8A4:
    /* 1BB8A4 002BB8A4 05000382 */  lb         $3, 0x5($16)
    /* 1BB8A8 002BB8A8 46006014 */  bnez       $3, .L002BB9C4
    /* 1BB8AC 002BB8AC 00000000 */   nop
    /* 1BB8B0 002BB8B0 DCEF0A0C */  jal        func_002bbf70
    /* 1BB8B4 002BB8B4 00000000 */   nop
    /* 1BB8B8 002BB8B8 2D884000 */  daddu      $17, $2, $0
    /* 1BB8BC 002BB8BC 04002016 */  bnez       $17, .L002BB8D0
    /* 1BB8C0 002BB8C0 00000000 */   nop
    /* 1BB8C4 002BB8C4 2D180000 */  daddu      $3, $0, $0
    /* 1BB8C8 002BB8C8 20000010 */  b          .L002BB94C
    /* 1BB8CC 002BB8CC 00000000 */   nop
  .L002BB8D0:
    /* 1BB8D0 002BB8D0 0000248E */  lw         $4, 0x0($17)
    /* 1BB8D4 002BB8D4 04008104 */  bgez       $4, .L002BB8E8
    /* 1BB8D8 002BB8D8 00000000 */   nop
    /* 1BB8DC 002BB8DC 2D180000 */  daddu      $3, $0, $0
    /* 1BB8E0 002BB8E0 1A000010 */  b          .L002BB94C
    /* 1BB8E4 002BB8E4 00000000 */   nop
  .L002BB8E8:
    /* 1BB8E8 002BB8E8 ECDB090C */  jal        func_00276fb0
    /* 1BB8EC 002BB8EC 00000000 */   nop
    /* 1BB8F0 002BB8F0 04004104 */  bgez       $2, .L002BB904
    /* 1BB8F4 002BB8F4 00000000 */   nop
    /* 1BB8F8 002BB8F8 2D180000 */  daddu      $3, $0, $0
    /* 1BB8FC 002BB8FC 13000010 */  b          .L002BB94C
    /* 1BB900 002BB900 00000000 */   nop
  .L002BB904:
    /* 1BB904 002BB904 DCEF0A0C */  jal        func_002bbf70
    /* 1BB908 002BB908 00000000 */   nop
    /* 1BB90C 002BB90C 04004014 */  bnez       $2, .L002BB920
    /* 1BB910 002BB910 00000000 */   nop
    /* 1BB914 002BB914 FFFF0324 */  addiu      $3, $0, -0x1
    /* 1BB918 002BB918 0A000010 */  b          .L002BB944
    /* 1BB91C 002BB91C 00000000 */   nop
  .L002BB920:
    /* 1BB920 002BB920 0000448C */  lw         $4, 0x0($2)
    /* 1BB924 002BB924 04008104 */  bgez       $4, .L002BB938
    /* 1BB928 002BB928 00000000 */   nop
    /* 1BB92C 002BB92C FFFF0324 */  addiu      $3, $0, -0x1
    /* 1BB930 002BB930 04000010 */  b          .L002BB944
    /* 1BB934 002BB934 00000000 */   nop
  .L002BB938:
    /* 1BB938 002BB938 1CDC090C */  jal        func_00277070
    /* 1BB93C 002BB93C 00000000 */   nop
    /* 1BB940 002BB940 2D184000 */  daddu      $3, $2, $0
  .L002BB944:
    /* 1BB944 002BB944 0D0023A2 */  sb         $3, 0xD($17)
    /* 1BB948 002BB948 01000324 */  addiu      $3, $0, 0x1
  .L002BB94C:
    /* 1BB94C 002BB94C 1D006014 */  bnez       $3, .L002BB9C4
    /* 1BB950 002BB950 00000000 */   nop
    /* 1BB954 002BB954 03000324 */  addiu      $3, $0, 0x3
    /* 1BB958 002BB958 040003A2 */  sb         $3, 0x4($16)
    /* 1BB95C 002BB95C 19000010 */  b          .L002BB9C4
    /* 1BB960 002BB960 00000000 */   nop
  .L002BB964:
    /* 1BB964 002BB964 DCEF0A0C */  jal        func_002bbf70
    /* 1BB968 002BB968 00000000 */   nop
    /* 1BB96C 002BB96C 2D804000 */  daddu      $16, $2, $0
    /* 1BB970 002BB970 14000012 */  beqz       $16, .L002BB9C4
    /* 1BB974 002BB974 00000000 */   nop
    /* 1BB978 002BB978 0000048E */  lw         $4, 0x0($16)
    /* 1BB97C 002BB97C 11008004 */  bltz       $4, .L002BB9C4
    /* 1BB980 002BB980 00000000 */   nop
    /* 1BB984 002BB984 2D280000 */  daddu      $5, $0, $0
    /* 1BB988 002BB988 9CDB090C */  jal        func_00276e70
    /* 1BB98C 002BB98C 00000000 */   nop
    /* 1BB990 002BB990 04002012 */  beqz       $17, .L002BB9A4
    /* 1BB994 002BB994 00000000 */   nop
    /* 1BB998 002BB998 0000048E */  lw         $4, 0x0($16)
    /* 1BB99C 002BB99C 94DC090C */  jal        func_00277250
    /* 1BB9A0 002BB9A0 00000000 */   nop
  .L002BB9A4:
    /* 1BB9A4 002BB9A4 0000048E */  lw         $4, 0x0($16)
    /* 1BB9A8 002BB9A8 2D280000 */  daddu      $5, $0, $0
    /* 1BB9AC 002BB9AC B4DE090C */  jal        func_00277ad0
    /* 1BB9B0 002BB9B0 00000000 */   nop
    /* 1BB9B4 002BB9B4 01000424 */  addiu      $4, $0, 0x1
    /* 1BB9B8 002BB9B8 74EF0A0C */  jal        func_002bbdd0
    /* 1BB9BC 002BB9BC 00000000 */   nop
    /* 1BB9C0 002BB9C0 040000A2 */  sb         $0, 0x4($16)
  .L002BB9C4:
    /* 1BB9C4 002BB9C4 2000BFDF */  ld         $31, 0x20($29)
    /* 1BB9C8 002BB9C8 1000B17B */  lq         $17, 0x10($29)
    /* 1BB9CC 002BB9CC 0000B07B */  lq         $16, 0x0($29)
    /* 1BB9D0 002BB9D0 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BB9D4 002BB9D4 0800E003 */  jr         $31
    /* 1BB9D8 002BB9D8 00000000 */   nop
    /* 1BB9DC 002BB9DC 00000000 */  nop
.size func_002bb7c0, 0x220
