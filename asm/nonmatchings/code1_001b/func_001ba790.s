.section .text
.set noat
.set noreorder
glabel func_001ba790
    /* BA790 001BA790 80FFBD27 */  addiu      $29, $29, -0x80
    /* BA794 001BA794 4000BFFF */  sd         $31, 0x40($29)
    /* BA798 001BA798 3000B27F */  sq         $18, 0x30($29)
    /* BA79C 001BA79C 2000B17F */  sq         $17, 0x20($29)
    /* BA7A0 001BA7A0 1000B07F */  sq         $16, 0x10($29)
    /* BA7A4 001BA7A4 0400B5E7 */  swc1       $f21, 0x4($29)
    /* BA7A8 001BA7A8 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BA7AC 001BA7AC 2D808000 */  daddu      $16, $4, $0
    /* BA7B0 001BA7B0 2D90A000 */  daddu      $18, $5, $0
    /* BA7B4 001BA7B4 2D88C000 */  daddu      $17, $6, $0
    /* BA7B8 001BA7B8 46650046 */  mov.s      $f21, $f12
    /* BA7BC 001BA7BC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BA7C0 001BA7C0 00008244 */  mtc1       $2, $f0
    /* BA7C4 001BA7C4 00000000 */  nop
    /* BA7C8 001BA7C8 01051546 */  sub.s      $f20, $f0, $f21
    /* BA7CC 001BA7CC 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* BA7D0 001BA7D0 42011446 */  mul.s      $f5, $f0, $f20
    /* BA7D4 001BA7D4 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* BA7D8 001BA7D8 02011446 */  mul.s      $f4, $f0, $f20
    /* BA7DC 001BA7DC 0400C0C4 */  lwc1       $f0, 0x4($6)
    /* BA7E0 001BA7E0 C2001546 */  mul.s      $f3, $f0, $f21
    /* BA7E4 001BA7E4 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* BA7E8 001BA7E8 82001546 */  mul.s      $f2, $f0, $f21
    /* BA7EC 001BA7EC 0000A1C4 */  lwc1       $f1, 0x0($5)
    /* BA7F0 001BA7F0 0000C0C4 */  lwc1       $f0, 0x0($6)
    /* BA7F4 001BA7F4 1A001546 */  mula.s     $f0, $f21
    /* BA7F8 001BA7F8 1C081446 */  madd.s     $f0, $f1, $f20
    /* BA7FC 001BA7FC 000080E4 */  swc1       $f0, 0x0($4)
    /* BA800 001BA800 00280346 */  add.s      $f0, $f5, $f3
    /* BA804 001BA804 040080E4 */  swc1       $f0, 0x4($4)
    /* BA808 001BA808 00200246 */  add.s      $f0, $f4, $f2
    /* BA80C 001BA80C 080080E4 */  swc1       $f0, 0x8($4)
    /* BA810 001BA810 0C004426 */  addiu      $4, $18, 0xC
    /* BA814 001BA814 0C002526 */  addiu      $5, $17, 0xC
    /* BA818 001BA818 5000A627 */  addiu      $6, $29, 0x50
    /* BA81C 001BA81C 1C730F0C */  jal        func_003dcc70
    /* BA820 001BA820 00000000 */   nop
    /* BA824 001BA824 00588044 */  mtc1       $0, $f11
    /* BA828 001BA828 00000000 */  nop
    /* BA82C 001BA82C 36A80B46 */  c.le.s     $f21, $f11
    /* BA830 001BA830 0B000045 */  bc1f       .L001BA860
    /* BA834 001BA834 00000000 */   nop
    /* BA838 001BA838 0C0043C6 */  lwc1       $f3, 0xC($18)
    /* BA83C 001BA83C 100042C6 */  lwc1       $f2, 0x10($18)
    /* BA840 001BA840 140041C6 */  lwc1       $f1, 0x14($18)
    /* BA844 001BA844 180040C6 */  lwc1       $f0, 0x18($18)
    /* BA848 001BA848 0C0003E6 */  swc1       $f3, 0xC($16)
    /* BA84C 001BA84C 100002E6 */  swc1       $f2, 0x10($16)
    /* BA850 001BA850 140001E6 */  swc1       $f1, 0x14($16)
    /* BA854 001BA854 180000E6 */  swc1       $f0, 0x18($16)
    /* BA858 001BA858 58000010 */  b          .L001BA9BC
    /* BA85C 001BA85C 00000000 */   nop
  .L001BA860:
    /* BA860 001BA860 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* BA864 001BA864 00008344 */  mtc1       $3, $f0
    /* BA868 001BA868 00000000 */  nop
    /* BA86C 001BA86C 36001546 */  c.le.s     $f0, $f21
    /* BA870 001BA870 0B000045 */  bc1f       .L001BA8A0
    /* BA874 001BA874 00000000 */   nop
    /* BA878 001BA878 0C0023C6 */  lwc1       $f3, 0xC($17)
    /* BA87C 001BA87C 100022C6 */  lwc1       $f2, 0x10($17)
    /* BA880 001BA880 140021C6 */  lwc1       $f1, 0x14($17)
    /* BA884 001BA884 180020C6 */  lwc1       $f0, 0x18($17)
    /* BA888 001BA888 0C0003E6 */  swc1       $f3, 0xC($16)
    /* BA88C 001BA88C 100002E6 */  swc1       $f2, 0x10($16)
    /* BA890 001BA890 140001E6 */  swc1       $f1, 0x14($16)
    /* BA894 001BA894 180000E6 */  swc1       $f0, 0x18($16)
    /* BA898 001BA898 48000010 */  b          .L001BA9BC
    /* BA89C 001BA89C 00000000 */   nop
  .L001BA8A0:
    /* BA8A0 001BA8A0 7400A38F */  lw         $3, 0x74($29)
    /* BA8A4 001BA8A4 26006014 */  bnez       $3, .L001BA940
    /* BA8A8 001BA8A8 00000000 */   nop
    /* BA8AC 001BA8AC 7000AAC7 */  lwc1       $f10, 0x70($29)
    /* BA8B0 001BA8B0 C2A00A46 */  mul.s      $f3, $f20, $f10
    /* BA8B4 001BA8B4 82180346 */  mul.s      $f2, $f3, $f3
    /* BA8B8 001BA8B8 048189C7 */  lwc1       $f9, -0x7EFC($28)
    /* BA8BC 001BA8BC 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* BA8C0 001BA8C0 18580846 */  adda.s     $f11, $f8
    /* BA8C4 001BA8C4 1C480246 */  madd.s     $f0, $f9, $f2
    /* BA8C8 001BA8C8 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* BA8CC 001BA8CC 18580746 */  adda.s     $f11, $f7
    /* BA8D0 001BA8D0 1C100046 */  madd.s     $f0, $f2, $f0
    /* BA8D4 001BA8D4 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* BA8D8 001BA8D8 18580646 */  adda.s     $f11, $f6
    /* BA8DC 001BA8DC 1C100046 */  madd.s     $f0, $f2, $f0
    /* BA8E0 001BA8E0 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* BA8E4 001BA8E4 18580546 */  adda.s     $f11, $f5
    /* BA8E8 001BA8E8 1C100046 */  madd.s     $f0, $f2, $f0
    /* BA8EC 001BA8EC 088184C7 */  lwc1       $f4, -0x7EF8($28)
    /* BA8F0 001BA8F0 18580446 */  adda.s     $f11, $f4
    /* BA8F4 001BA8F4 5C100046 */  madd.s     $f1, $f2, $f0
    /* BA8F8 001BA8F8 02100346 */  mul.s      $f0, $f2, $f3
    /* BA8FC 001BA8FC 18580346 */  adda.s     $f11, $f3
    /* BA900 001BA900 1C050146 */  madd.s     $f20, $f0, $f1
    /* BA904 001BA904 C2A80A46 */  mul.s      $f3, $f21, $f10
    /* BA908 001BA908 82180346 */  mul.s      $f2, $f3, $f3
    /* BA90C 001BA90C 18580846 */  adda.s     $f11, $f8
    /* BA910 001BA910 1C480246 */  madd.s     $f0, $f9, $f2
    /* BA914 001BA914 18580746 */  adda.s     $f11, $f7
    /* BA918 001BA918 1C100046 */  madd.s     $f0, $f2, $f0
    /* BA91C 001BA91C 18580646 */  adda.s     $f11, $f6
    /* BA920 001BA920 1C100046 */  madd.s     $f0, $f2, $f0
    /* BA924 001BA924 18580546 */  adda.s     $f11, $f5
    /* BA928 001BA928 1C100046 */  madd.s     $f0, $f2, $f0
    /* BA92C 001BA92C 18580446 */  adda.s     $f11, $f4
    /* BA930 001BA930 5C100046 */  madd.s     $f1, $f2, $f0
    /* BA934 001BA934 02100346 */  mul.s      $f0, $f2, $f3
    /* BA938 001BA938 18580346 */  adda.s     $f11, $f3
    /* BA93C 001BA93C 5C050146 */  madd.s     $f21, $f0, $f1
  .L001BA940:
    /* BA940 001BA940 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* BA944 001BA944 02001446 */  mul.s      $f0, $f0, $f20
    /* BA948 001BA948 0C0000E6 */  swc1       $f0, 0xC($16)
    /* BA94C 001BA94C 5400A0C7 */  lwc1       $f0, 0x54($29)
    /* BA950 001BA950 02001446 */  mul.s      $f0, $f0, $f20
    /* BA954 001BA954 100000E6 */  swc1       $f0, 0x10($16)
    /* BA958 001BA958 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* BA95C 001BA95C 02001446 */  mul.s      $f0, $f0, $f20
    /* BA960 001BA960 140000E6 */  swc1       $f0, 0x14($16)
    /* BA964 001BA964 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* BA968 001BA968 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* BA96C 001BA96C 00108044 */  mtc1       $0, $f2
    /* BA970 001BA970 00000000 */  nop
    /* BA974 001BA974 18100046 */  adda.s     $f2, $f0
    /* BA978 001BA978 1C081546 */  madd.s     $f0, $f1, $f21
    /* BA97C 001BA97C 0C0000E6 */  swc1       $f0, 0xC($16)
    /* BA980 001BA980 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* BA984 001BA984 100000C6 */  lwc1       $f0, 0x10($16)
    /* BA988 001BA988 18100046 */  adda.s     $f2, $f0
    /* BA98C 001BA98C 1C081546 */  madd.s     $f0, $f1, $f21
    /* BA990 001BA990 100000E6 */  swc1       $f0, 0x10($16)
    /* BA994 001BA994 6800A1C7 */  lwc1       $f1, 0x68($29)
    /* BA998 001BA998 140000C6 */  lwc1       $f0, 0x14($16)
    /* BA99C 001BA99C 18100046 */  adda.s     $f2, $f0
    /* BA9A0 001BA9A0 1C081546 */  madd.s     $f0, $f1, $f21
    /* BA9A4 001BA9A4 140000E6 */  swc1       $f0, 0x14($16)
    /* BA9A8 001BA9A8 5C00A1C7 */  lwc1       $f1, 0x5C($29)
    /* BA9AC 001BA9AC 6C00A0C7 */  lwc1       $f0, 0x6C($29)
    /* BA9B0 001BA9B0 1A001546 */  mula.s     $f0, $f21
    /* BA9B4 001BA9B4 1C081446 */  madd.s     $f0, $f1, $f20
    /* BA9B8 001BA9B8 180000E6 */  swc1       $f0, 0x18($16)
  .L001BA9BC:
    /* BA9BC 001BA9BC 4000BFDF */  ld         $31, 0x40($29)
    /* BA9C0 001BA9C0 3000B27B */  lq         $18, 0x30($29)
    /* BA9C4 001BA9C4 2000B17B */  lq         $17, 0x20($29)
    /* BA9C8 001BA9C8 1000B07B */  lq         $16, 0x10($29)
    /* BA9CC 001BA9CC 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* BA9D0 001BA9D0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* BA9D4 001BA9D4 8000BD27 */  addiu      $29, $29, 0x80
    /* BA9D8 001BA9D8 0800E003 */  jr         $31
    /* BA9DC 001BA9DC 00000000 */   nop
.size func_001ba790, 0x250
