.section .text
.set noat
.set noreorder
glabel func_003ea690
    /* 2EA690 003EA690 80FFBD27 */  addiu      $29, $29, -0x80
    /* 2EA694 003EA694 0400A28C */  lw         $2, 0x4($5)
    /* 2EA698 003EA698 6000BFFF */  sd         $31, 0x60($29)
    /* 2EA69C 003EA69C 5000B57F */  sq         $21, 0x50($29)
    /* 2EA6A0 003EA6A0 4000B47F */  sq         $20, 0x40($29)
    /* 2EA6A4 003EA6A4 3000B37F */  sq         $19, 0x30($29)
    /* 2EA6A8 003EA6A8 2DA08000 */  daddu      $20, $4, $0
    /* 2EA6AC 003EA6AC 2000B27F */  sq         $18, 0x20($29)
    /* 2EA6B0 003EA6B0 1000B17F */  sq         $17, 0x10($29)
    /* 2EA6B4 003EA6B4 0000B07F */  sq         $16, 0x0($29)
    /* 2EA6B8 003EA6B8 0400918C */  lw         $17, 0x4($4)
    /* 2EA6BC 003EA6BC 8B002216 */  bne        $17, $2, .L003EA8EC
    /* 2EA6C0 003EA6C0 2D98A000 */   daddu     $19, $5, $0
    /* 2EA6C4 003EA6C4 0800958E */  lw         $21, 0x8($20)
    /* 2EA6C8 003EA6C8 0800628E */  lw         $2, 0x8($19)
    /* 2EA6CC 003EA6CC 8700A216 */  bne        $21, $2, .L003EA8EC
    /* 2EA6D0 003EA6D0 00000000 */   nop
    /* 2EA6D4 003EA6D4 0C00908E */  lw         $16, 0xC($20)
    /* 2EA6D8 003EA6D8 20000224 */  addiu      $2, $0, 0x20
    /* 2EA6DC 003EA6DC 39000212 */  beq        $16, $2, .L003EA7C4
    /* 2EA6E0 003EA6E0 00000000 */   nop
    /* 2EA6E4 003EA6E4 08000224 */  addiu      $2, $0, 0x8
    /* 2EA6E8 003EA6E8 06000212 */  beq        $16, $2, .L003EA704
    /* 2EA6EC 003EA6EC 00000000 */   nop
    /* 2EA6F0 003EA6F0 04000224 */  addiu      $2, $0, 0x4
    /* 2EA6F4 003EA6F4 03000212 */  beq        $16, $2, .L003EA704
    /* 2EA6F8 003EA6F8 00000000 */   nop
    /* 2EA6FC 003EA6FC 72000010 */  b          .L003EA8C8
    /* 2EA700 003EA700 01000324 */   addiu     $3, $0, 0x1
  .L003EA704:
    /* 2EA704 003EA704 C8B7868F */  lw         $6, -0x4838($28)
    /* 2EA708 003EA708 8800043C */  lui        $4, %hi(D_008872E0)
    /* 2EA70C 003EA70C 0300033C */  lui        $3, (0x30018 >> 16)
    /* 2EA710 003EA710 8800023C */  lui        $2, %hi(D_008873F8)
    /* 2EA714 003EA714 E0728424 */  addiu      $4, $4, %lo(D_008872E0)
    /* 2EA718 003EA718 18006534 */  ori        $5, $3, (0x30018 & 0xFFFF)
    /* 2EA71C 003EA71C F873428C */  lw         $2, %lo(D_008873F8)($2)
    /* 2EA720 003EA720 21188600 */  addu       $3, $4, $6
    /* 2EA724 003EA724 09F84000 */  jalr       $2
    /* 2EA728 003EA728 0000648C */   lw        $4, 0x0($3)
    /* 2EA72C 003EA72C 2D904000 */  daddu      $18, $2, $0
    /* 2EA730 003EA730 78004012 */  beqz       $18, .L003EA914
    /* 2EA734 003EA734 00000000 */   nop
    /* 2EA738 003EA738 040051AE */  sw         $17, 0x4($18)
    /* 2EA73C 003EA73C 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EA740 003EA740 080055AE */  sw         $21, 0x8($18)
    /* 2EA744 003EA744 C0B78424 */  addiu      $4, $4, %lo(D_0070B7C0)
    /* 2EA748 003EA748 0C0050AE */  sw         $16, 0xC($18)
    /* 2EA74C 003EA74C 2D284002 */  daddu      $5, $18, $0
    /* 2EA750 003EA750 140040AE */  sw         $0, 0x14($18)
    /* 2EA754 003EA754 180040AE */  sw         $0, 0x18($18)
    /* 2EA758 003EA758 DC8E0F0C */  jal        func_003e3b70
    /* 2EA75C 003EA75C 000040AE */   sw        $0, 0x0($18)
  .L003EA760:
    /* 2EA760 003EA760 6E004012 */  beqz       $18, .L003EA91C
    /* 2EA764 003EA764 00000000 */   nop
    /* 2EA768 003EA768 F8A80F0C */  jal        func_003ea3e0
    /* 2EA76C 003EA76C 2D204002 */   daddu     $4, $18, $0
    /* 2EA770 003EA770 77004014 */  bnez       $2, .L003EA950
    /* 2EA774 003EA774 00000000 */   nop
    /* 2EA778 003EA778 0000428E */  lw         $2, 0x0($18)
    /* 2EA77C 003EA77C 01004230 */  andi       $2, $2, 0x1
    /* 2EA780 003EA780 68004014 */  bnez       $2, .L003EA924
    /* 2EA784 003EA784 00000000 */   nop
  .L003EA788:
    /* 2EA788 003EA788 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EA78C 003EA78C 2D284002 */  daddu      $5, $18, $0
    /* 2EA790 003EA790 088F0F0C */  jal        func_003e3c20
    /* 2EA794 003EA794 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EA798 003EA798 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EA79C 003EA79C 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EA7A0 003EA7A0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EA7A4 003EA7A4 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EA7A8 003EA7A8 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EA7AC 003EA7AC 21186400 */  addu       $3, $3, $4
    /* 2EA7B0 003EA7B0 0000648C */  lw         $4, 0x0($3)
    /* 2EA7B4 003EA7B4 09F84000 */  jalr       $2
    /* 2EA7B8 003EA7B8 2D284002 */   daddu     $5, $18, $0
    /* 2EA7BC 003EA7BC A5000010 */  b          .L003EAA54
    /* 2EA7C0 003EA7C0 2D100000 */   daddu     $2, $0, $0
  .L003EA7C4:
    /* 2EA7C4 003EA7C4 0800828E */  lw         $2, 0x8($20)
  .L003EA7C8:
    /* 2EA7C8 003EA7C8 1400698E */  lw         $9, 0x14($19)
    /* 2EA7CC 003EA7CC 1800668E */  lw         $6, 0x18($19)
    /* 2EA7D0 003EA7D0 1400888E */  lw         $8, 0x14($20)
    /* 2EA7D4 003EA7D4 2A080200 */  slt        $1, $0, $2
    /* 2EA7D8 003EA7D8 39002010 */  beqz       $1, .L003EA8C0
    /* 2EA7DC 003EA7DC 2D500000 */   daddu     $10, $0, $0
    /* 2EA7E0 003EA7E0 10006B8E */  lw         $11, 0x10($19)
    /* 2EA7E4 003EA7E4 04000224 */  addiu      $2, $0, 0x4
    /* 2EA7E8 003EA7E8 0C00658E */  lw         $5, 0xC($19)
    /* 2EA7EC 003EA7EC 08000324 */  addiu      $3, $0, 0x8
    /* 2EA7F0 003EA7F0 20000424 */  addiu      $4, $0, 0x20
  .L003EA7F4:
    /* 2EA7F4 003EA7F4 1C00A410 */  beq        $5, $4, .L003EA868
    /* 2EA7F8 003EA7F8 2D380001 */   daddu     $7, $8, $0
    /* 2EA7FC 003EA7FC 0600A310 */  beq        $5, $3, .L003EA818
    /* 2EA800 003EA800 00000000 */   nop
    /* 2EA804 003EA804 0400A210 */  beq        $5, $2, .L003EA818
    /* 2EA808 003EA808 00000000 */   nop
    /* 2EA80C 003EA80C 24000010 */  b          .L003EA8A0
    /* 2EA810 003EA810 00000000 */   nop
    /* 2EA814 003EA814 00000000 */  nop
  .L003EA818:
    /* 2EA818 003EA818 04008C8E */  lw         $12, 0x4($20)
    /* 2EA81C 003EA81C 2D682001 */  daddu      $13, $9, $0
    /* 2EA820 003EA820 2A080C00 */  slt        $1, $0, $12
    /* 2EA824 003EA824 1E002010 */  beqz       $1, .L003EA8A0
    /* 2EA828 003EA828 2D700000 */   daddu     $14, $0, $0
    /* 2EA82C 003EA82C 00000000 */  nop
  .L003EA830:
    /* 2EA830 003EA830 0000AC91 */  lbu        $12, 0x0($13)
    /* 2EA834 003EA834 0100CE25 */  addiu      $14, $14, 0x1
    /* 2EA838 003EA838 80600C00 */  sll        $12, $12, 2
    /* 2EA83C 003EA83C 0100AD25 */  addiu      $13, $13, 0x1
    /* 2EA840 003EA840 2160CC00 */  addu       $12, $6, $12
    /* 2EA844 003EA844 03008C91 */  lbu        $12, 0x3($12)
    /* 2EA848 003EA848 0300ECA0 */  sb         $12, 0x3($7)
    /* 2EA84C 003EA84C 04008C8E */  lw         $12, 0x4($20)
    /* 2EA850 003EA850 2A60CC01 */  slt        $12, $14, $12
    /* 2EA854 003EA854 F6FF8015 */  bnez       $12, .L003EA830
    /* 2EA858 003EA858 0400E724 */   addiu     $7, $7, 0x4
    /* 2EA85C 003EA85C 10000010 */  b          .L003EA8A0
    /* 2EA860 003EA860 00000000 */   nop
    /* 2EA864 003EA864 00000000 */  nop
  .L003EA868:
    /* 2EA868 003EA868 04008C8E */  lw         $12, 0x4($20)
    /* 2EA86C 003EA86C 2D702001 */  daddu      $14, $9, $0
    /* 2EA870 003EA870 2A080C00 */  slt        $1, $0, $12
    /* 2EA874 003EA874 0A002010 */  beqz       $1, .L003EA8A0
    /* 2EA878 003EA878 2D680000 */   daddu     $13, $0, $0
    /* 2EA87C 003EA87C 00000000 */  nop
  .L003EA880:
    /* 2EA880 003EA880 0300CC91 */  lbu        $12, 0x3($14)
    /* 2EA884 003EA884 0100AD25 */  addiu      $13, $13, 0x1
    /* 2EA888 003EA888 0300ECA0 */  sb         $12, 0x3($7)
    /* 2EA88C 003EA88C 0400CE25 */  addiu      $14, $14, 0x4
    /* 2EA890 003EA890 04008C8E */  lw         $12, 0x4($20)
    /* 2EA894 003EA894 2A60AC01 */  slt        $12, $13, $12
    /* 2EA898 003EA898 F9FF8015 */  bnez       $12, .L003EA880
    /* 2EA89C 003EA89C 0400E724 */   addiu     $7, $7, 0x4
  .L003EA8A0:
    /* 2EA8A0 003EA8A0 0800878E */  lw         $7, 0x8($20)
    /* 2EA8A4 003EA8A4 10008C8E */  lw         $12, 0x10($20)
    /* 2EA8A8 003EA8A8 01004A25 */  addiu      $10, $10, 0x1
    /* 2EA8AC 003EA8AC 21482B01 */  addu       $9, $9, $11
    /* 2EA8B0 003EA8B0 2A384701 */  slt        $7, $10, $7
    /* 2EA8B4 003EA8B4 CFFFE014 */  bnez       $7, .L003EA7F4
    /* 2EA8B8 003EA8B8 21400C01 */   addu      $8, $8, $12
    /* 2EA8BC 003EA8BC 00000000 */  nop
  .L003EA8C0:
    /* 2EA8C0 003EA8C0 64000010 */  b          .L003EAA54
    /* 2EA8C4 003EA8C4 2D108002 */   daddu     $2, $20, $0
  .L003EA8C8:
    /* 2EA8C8 003EA8C8 0080023C */  lui        $2, (0x80000009 >> 16)
    /* 2EA8CC 003EA8CC 7000A3AF */  sw         $3, 0x70($29)
    /* 2EA8D0 003EA8D0 647D0F0C */  jal        func_003df590
    /* 2EA8D4 003EA8D4 09004434 */   ori       $4, $2, (0x80000009 & 0xFFFF)
    /* 2EA8D8 003EA8D8 7400A2AF */  sw         $2, 0x74($29)
    /* 2EA8DC 003EA8DC 347D0F0C */  jal        func_003df4d0
    /* 2EA8E0 003EA8E0 7000A427 */   addiu     $4, $29, 0x70
    /* 2EA8E4 003EA8E4 5B000010 */  b          .L003EAA54
    /* 2EA8E8 003EA8E8 2D100000 */   daddu     $2, $0, $0
  .L003EA8EC:
    /* 2EA8EC 003EA8EC 01000324 */  addiu      $3, $0, 0x1
    /* 2EA8F0 003EA8F0 0080023C */  lui        $2, (0x8000000A >> 16)
    /* 2EA8F4 003EA8F4 7800A3AF */  sw         $3, 0x78($29)
    /* 2EA8F8 003EA8F8 647D0F0C */  jal        func_003df590
    /* 2EA8FC 003EA8FC 0A004434 */   ori       $4, $2, (0x8000000A & 0xFFFF)
    /* 2EA900 003EA900 7C00A2AF */  sw         $2, 0x7C($29)
    /* 2EA904 003EA904 347D0F0C */  jal        func_003df4d0
    /* 2EA908 003EA908 7800A427 */   addiu     $4, $29, 0x78
    /* 2EA90C 003EA90C 51000010 */  b          .L003EAA54
    /* 2EA910 003EA910 2D100000 */   daddu     $2, $0, $0
  .L003EA914:
    /* 2EA914 003EA914 92FF0010 */  b          .L003EA760
    /* 2EA918 003EA918 2D900000 */   daddu     $18, $0, $0
  .L003EA91C:
    /* 2EA91C 003EA91C 4D000010 */  b          .L003EAA54
    /* 2EA920 003EA920 2D100000 */   daddu     $2, $0, $0
  .L003EA924:
    /* 2EA924 003EA924 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EA928 003EA928 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EA92C 003EA92C 09F84000 */  jalr       $2
    /* 2EA930 003EA930 1400448E */   lw        $4, 0x14($18)
    /* 2EA934 003EA934 140040AE */  sw         $0, 0x14($18)
    /* 2EA938 003EA938 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EA93C 003EA93C 180040AE */  sw         $0, 0x18($18)
    /* 2EA940 003EA940 0000438E */  lw         $3, 0x0($18)
    /* 2EA944 003EA944 24106200 */  and        $2, $3, $2
    /* 2EA948 003EA948 8FFF0010 */  b          .L003EA788
    /* 2EA94C 003EA94C 000042AE */   sw        $2, 0x0($18)
  .L003EA950:
    /* 2EA950 003EA950 2D204002 */  daddu      $4, $18, $0
    /* 2EA954 003EA954 B0AE0F0C */  jal        func_003ebac0
    /* 2EA958 003EA958 2D288002 */   daddu     $5, $20, $0
    /* 2EA95C 003EA95C 0000828E */  lw         $2, 0x0($20)
    /* 2EA960 003EA960 01004230 */  andi       $2, $2, 0x1
    /* 2EA964 003EA964 26004014 */  bnez       $2, .L003EAA00
    /* 2EA968 003EA968 00000000 */   nop
  .L003EA96C:
    /* 2EA96C 003EA96C 20000224 */  addiu      $2, $0, 0x20
    /* 2EA970 003EA970 2D208002 */  daddu      $4, $20, $0
    /* 2EA974 003EA974 F8A80F0C */  jal        func_003ea3e0
    /* 2EA978 003EA978 0C0082AE */   sw        $2, 0xC($20)
    /* 2EA97C 003EA97C 2D208002 */  daddu      $4, $20, $0
    /* 2EA980 003EA980 B0AE0F0C */  jal        func_003ebac0
    /* 2EA984 003EA984 2D284002 */   daddu     $5, $18, $0
    /* 2EA988 003EA988 8800103C */  lui        $16, %hi(jtbl_008873EC)
    /* 2EA98C 003EA98C EC731026 */  addiu      $16, $16, %lo(jtbl_008873EC)
    /* 2EA990 003EA990 0000028E */  lw         $2, 0x0($16)
    /* 2EA994 003EA994 09F84000 */  jalr       $2
    /* 2EA998 003EA998 1400448E */   lw        $4, 0x14($18)
    /* 2EA99C 003EA99C 140040AE */  sw         $0, 0x14($18)
    /* 2EA9A0 003EA9A0 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EA9A4 003EA9A4 180040AE */  sw         $0, 0x18($18)
    /* 2EA9A8 003EA9A8 0000438E */  lw         $3, 0x0($18)
    /* 2EA9AC 003EA9AC 24106200 */  and        $2, $3, $2
    /* 2EA9B0 003EA9B0 000042AE */  sw         $2, 0x0($18)
    /* 2EA9B4 003EA9B4 0000428E */  lw         $2, 0x0($18)
    /* 2EA9B8 003EA9B8 01004230 */  andi       $2, $2, 0x1
    /* 2EA9BC 003EA9BC 1B004014 */  bnez       $2, .L003EAA2C
    /* 2EA9C0 003EA9C0 00000000 */   nop
  .L003EA9C4:
    /* 2EA9C4 003EA9C4 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EA9C8 003EA9C8 2D284002 */  daddu      $5, $18, $0
    /* 2EA9CC 003EA9CC 088F0F0C */  jal        func_003e3c20
    /* 2EA9D0 003EA9D0 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EA9D4 003EA9D4 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EA9D8 003EA9D8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EA9DC 003EA9DC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EA9E0 003EA9E0 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EA9E4 003EA9E4 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EA9E8 003EA9E8 21186400 */  addu       $3, $3, $4
    /* 2EA9EC 003EA9EC 0000648C */  lw         $4, 0x0($3)
    /* 2EA9F0 003EA9F0 09F84000 */  jalr       $2
    /* 2EA9F4 003EA9F4 2D284002 */   daddu     $5, $18, $0
    /* 2EA9F8 003EA9F8 73FF0010 */  b          .L003EA7C8
    /* 2EA9FC 003EA9FC 0800828E */   lw        $2, 0x8($20)
  .L003EAA00:
    /* 2EAA00 003EAA00 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EAA04 003EAA04 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EAA08 003EAA08 09F84000 */  jalr       $2
    /* 2EAA0C 003EAA0C 1400848E */   lw        $4, 0x14($20)
    /* 2EAA10 003EAA10 140080AE */  sw         $0, 0x14($20)
    /* 2EAA14 003EAA14 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EAA18 003EAA18 180080AE */  sw         $0, 0x18($20)
    /* 2EAA1C 003EAA1C 0000838E */  lw         $3, 0x0($20)
    /* 2EAA20 003EAA20 24106200 */  and        $2, $3, $2
    /* 2EAA24 003EAA24 D1FF0010 */  b          .L003EA96C
    /* 2EAA28 003EAA28 000082AE */   sw        $2, 0x0($20)
  .L003EAA2C:
    /* 2EAA2C 003EAA2C 0000028E */  lw         $2, 0x0($16)
    /* 2EAA30 003EAA30 09F84000 */  jalr       $2
    /* 2EAA34 003EAA34 1400448E */   lw        $4, 0x14($18)
    /* 2EAA38 003EAA38 140040AE */  sw         $0, 0x14($18)
    /* 2EAA3C 003EAA3C FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EAA40 003EAA40 180040AE */  sw         $0, 0x18($18)
    /* 2EAA44 003EAA44 0000438E */  lw         $3, 0x0($18)
    /* 2EAA48 003EAA48 24106200 */  and        $2, $3, $2
    /* 2EAA4C 003EAA4C DDFF0010 */  b          .L003EA9C4
    /* 2EAA50 003EAA50 000042AE */   sw        $2, 0x0($18)
  .L003EAA54:
    /* 2EAA54 003EAA54 6000BFDF */  ld         $31, 0x60($29)
    /* 2EAA58 003EAA58 5000B57B */  lq         $21, 0x50($29)
    /* 2EAA5C 003EAA5C 4000B47B */  lq         $20, 0x40($29)
    /* 2EAA60 003EAA60 3000B37B */  lq         $19, 0x30($29)
    /* 2EAA64 003EAA64 2000B27B */  lq         $18, 0x20($29)
    /* 2EAA68 003EAA68 1000B17B */  lq         $17, 0x10($29)
    /* 2EAA6C 003EAA6C 0000B07B */  lq         $16, 0x0($29)
    /* 2EAA70 003EAA70 0800E003 */  jr         $31
    /* 2EAA74 003EAA74 8000BD27 */   addiu     $29, $29, 0x80
    /* 2EAA78 003EAA78 00000000 */  nop
    /* 2EAA7C 003EAA7C 00000000 */  nop
.size func_003ea690, 0x3f0
