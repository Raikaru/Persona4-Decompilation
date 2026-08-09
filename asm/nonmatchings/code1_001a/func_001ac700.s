.section .text
.set noat
.set noreorder
glabel func_001ac700
    /* AC700 001AC700 80FFBD27 */  addiu      $29, $29, -0x80
    /* AC704 001AC704 7000BFFF */  sd         $31, 0x70($29)
    /* AC708 001AC708 6000B57F */  sq         $21, 0x60($29)
    /* AC70C 001AC70C 5000B47F */  sq         $20, 0x50($29)
    /* AC710 001AC710 4000B37F */  sq         $19, 0x40($29)
    /* AC714 001AC714 3000B27F */  sq         $18, 0x30($29)
    /* AC718 001AC718 2000B17F */  sq         $17, 0x20($29)
    /* AC71C 001AC71C 1000B07F */  sq         $16, 0x10($29)
    /* AC720 001AC720 0000B4E7 */  swc1       $f20, 0x0($29)
    /* AC724 001AC724 2D808000 */  daddu      $16, $4, $0
    /* AC728 001AC728 EC80060C */  jal        func_001a03b0
    /* AC72C 001AC72C 00000000 */   nop
    /* AC730 001AC730 6C000296 */  lhu        $2, 0x6C($16)
    /* AC734 001AC734 03004238 */  xori       $2, $2, 0x3
    /* AC738 001AC738 0100522C */  sltiu      $18, $2, 0x1
    /* AC73C 001AC73C 000011DE */  ld         $17, 0x0($16)
    /* AC740 001AC740 0C004016 */  bnez       $18, .L001AC774
    /* AC744 001AC744 00000000 */   nop
    /* AC748 001AC748 3000048E */  lw         $4, 0x30($16)
    /* AC74C 001AC74C 6E000596 */  lhu        $5, 0x6E($16)
    /* AC750 001AC750 0408080C */  jal        func_00202010
    /* AC754 001AC754 00000000 */   nop
    /* AC758 001AC758 2D204000 */  daddu      $4, $2, $0
    /* AC75C 001AC75C 600051FC */  sd         $17, 0x60($2)
    /* AC760 001AC760 03000524 */  addiu      $5, $0, 0x3
    /* AC764 001AC764 6451060C */  jal        func_00194590
    /* AC768 001AC768 00000000 */   nop
    /* AC76C 001AC76C 0A000010 */  b          .L001AC798
    /* AC770 001AC770 00000000 */   nop
  .L001AC774:
    /* AC774 001AC774 3000048E */  lw         $4, 0x30($16)
    /* AC778 001AC778 70000596 */  lhu        $5, 0x70($16)
    /* AC77C 001AC77C 4808080C */  jal        func_00202120
    /* AC780 001AC780 00000000 */   nop
    /* AC784 001AC784 2D204000 */  daddu      $4, $2, $0
    /* AC788 001AC788 600051FC */  sd         $17, 0x60($2)
    /* AC78C 001AC78C 03000524 */  addiu      $5, $0, 0x3
    /* AC790 001AC790 6451060C */  jal        func_00194590
    /* AC794 001AC794 00000000 */   nop
  .L001AC798:
    /* AC798 001AC798 3000048E */  lw         $4, 0x30($16)
    /* AC79C 001AC79C A2008290 */  lbu        $2, 0xA2($4)
    /* AC7A0 001AC7A0 14004014 */  bnez       $2, .L001AC7F4
    /* AC7A4 001AC7A4 00000000 */   nop
    /* AC7A8 001AC7A8 05004016 */  bnez       $18, .L001AC7C0
    /* AC7AC 001AC7AC 00000000 */   nop
    /* AC7B0 001AC7B0 0D001464 */  daddiu     $20, $0, 0xD
    /* AC7B4 001AC7B4 0B001364 */  daddiu     $19, $0, 0xB
    /* AC7B8 001AC7B8 03000010 */  b          .L001AC7C8
    /* AC7BC 001AC7BC 00000000 */   nop
  .L001AC7C0:
    /* AC7C0 001AC7C0 16001464 */  daddiu     $20, $0, 0x16
    /* AC7C4 001AC7C4 21001364 */  daddiu     $19, $0, 0x21
  .L001AC7C8:
    /* AC7C8 001AC7C8 14001264 */  daddiu     $18, $0, 0x14
    /* AC7CC 001AC7CC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AC7D0 001AC7D0 00608244 */  mtc1       $2, $f12
    /* AC7D4 001AC7D4 2D288002 */  daddu      $5, $20, $0
    /* AC7D8 001AC7D8 4065060C */  jal        func_00199500
    /* AC7DC 001AC7DC 00000000 */   nop
    /* AC7E0 001AC7E0 FFFF5530 */  andi       $21, $2, 0xFFFF
    /* AC7E4 001AC7E4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AC7E8 001AC7E8 00A08244 */  mtc1       $2, $f20
    /* AC7EC 001AC7EC 1D000010 */  b          .L001AC864
    /* AC7F0 001AC7F0 00000000 */   nop
  .L001AC7F4:
    /* AC7F4 001AC7F4 6E000486 */  lh         $4, 0x6E($16)
    /* AC7F8 001AC7F8 78C4070C */  jal        func_001f11e0
    /* AC7FC 001AC7FC 00000000 */   nop
    /* AC800 001AC800 04004010 */  beqz       $2, .L001AC814
    /* AC804 001AC804 00000000 */   nop
    /* AC808 001AC808 04000224 */  addiu      $2, $0, 0x4
    /* AC80C 001AC80C 02000010 */  b          .L001AC818
    /* AC810 001AC810 00000000 */   nop
  .L001AC814:
    /* AC814 001AC814 08000224 */  addiu      $2, $0, 0x8
  .L001AC818:
    /* AC818 001AC818 FFFF5430 */  andi       $20, $2, 0xFFFF
    /* AC81C 001AC81C 0F001364 */  daddiu     $19, $0, 0xF
    /* AC820 001AC820 15001264 */  daddiu     $18, $0, 0x15
    /* AC824 001AC824 18000296 */  lhu        $2, 0x18($16)
    /* AC828 001AC828 00404230 */  andi       $2, $2, 0x4000
    /* AC82C 001AC82C 05004010 */  beqz       $2, .L001AC844
    /* AC830 001AC830 00000000 */   nop
    /* AC834 001AC834 0040023C */  lui        $2, (0x40000000 >> 16)
    /* AC838 001AC838 00A08244 */  mtc1       $2, $f20
    /* AC83C 001AC83C 03000010 */  b          .L001AC84C
    /* AC840 001AC840 00000000 */   nop
  .L001AC844:
    /* AC844 001AC844 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AC848 001AC848 00A08244 */  mtc1       $2, $f20
  .L001AC84C:
    /* AC84C 001AC84C 3000048E */  lw         $4, 0x30($16)
    /* AC850 001AC850 2D288002 */  daddu      $5, $20, $0
    /* AC854 001AC854 06A30046 */  mov.s      $f12, $f20
    /* AC858 001AC858 7064060C */  jal        func_001991c0
    /* AC85C 001AC85C 00000000 */   nop
    /* AC860 001AC860 FFFF5530 */  andi       $21, $2, 0xFFFF
  .L001AC864:
    /* AC864 001AC864 3C2C1400 */  dsll32     $5, $20, 16
    /* AC868 001AC868 3F2C0500 */  dsra32     $5, $5, 16
    /* AC86C 001AC86C 3000048E */  lw         $4, 0x30($16)
    /* AC870 001AC870 06000624 */  addiu      $6, $0, 0x6
    /* AC874 001AC874 06A30046 */  mov.s      $f12, $f20
    /* AC878 001AC878 2D380000 */  daddu      $7, $0, $0
    /* AC87C 001AC87C B867060C */  jal        func_00199ee0
    /* AC880 001AC880 00000000 */   nop
    /* AC884 001AC884 2DA04000 */  daddu      $20, $2, $0
    /* AC888 001AC888 600051FC */  sd         $17, 0x60($2)
    /* AC88C 001AC88C FFFFA332 */  andi       $3, $21, 0xFFFF
    /* AC890 001AC890 06006324 */  addiu      $3, $3, 0x6
    /* AC894 001AC894 4A0043A4 */  sh         $3, 0x4A($2)
    /* AC898 001AC898 2D208002 */  daddu      $4, $20, $0
    /* AC89C 001AC89C 2D280000 */  daddu      $5, $0, $0
    /* AC8A0 001AC8A0 6451060C */  jal        func_00194590
    /* AC8A4 001AC8A4 00000000 */   nop
    /* AC8A8 001AC8A8 ACB3838F */  lw         $3, -0x4C54($28)
    /* AC8AC 001AC8AC FFFF6232 */  andi       $2, $19, 0xFFFF
    /* AC8B0 001AC8B0 80100200 */  sll        $2, $2, 2
    /* AC8B4 001AC8B4 21104300 */  addu       $2, $2, $3
    /* AC8B8 001AC8B8 040D448C */  lw         $4, 0xD04($2)
    /* AC8BC 001AC8BC 3000058E */  lw         $5, 0x30($16)
    /* AC8C0 001AC8C0 2D300000 */  daddu      $6, $0, $0
    /* AC8C4 001AC8C4 580087DE */  ld         $7, 0x58($20)
    /* AC8C8 001AC8C8 00010824 */  addiu      $8, $0, 0x100
    /* AC8CC 001AC8CC 7459070C */  jal        func_001d65d0
    /* AC8D0 001AC8D0 00000000 */   nop
    /* AC8D4 001AC8D4 2D204000 */  daddu      $4, $2, $0
    /* AC8D8 001AC8D8 600051FC */  sd         $17, 0x60($2)
    /* AC8DC 001AC8DC 02000524 */  addiu      $5, $0, 0x2
    /* AC8E0 001AC8E0 6451060C */  jal        func_00194590
    /* AC8E4 001AC8E4 00000000 */   nop
    /* AC8E8 001AC8E8 2D200002 */  daddu      $4, $16, $0
    /* AC8EC 001AC8EC 2D284002 */  daddu      $5, $18, $0
    /* AC8F0 001AC8F0 48F2060C */  jal        func_001bc920
    /* AC8F4 001AC8F4 00000000 */   nop
    /* AC8F8 001AC8F8 2D204000 */  daddu      $4, $2, $0
    /* AC8FC 001AC8FC 600051FC */  sd         $17, 0x60($2)
    /* AC900 001AC900 2D280000 */  daddu      $5, $0, $0
    /* AC904 001AC904 6451060C */  jal        func_00194590
    /* AC908 001AC908 00000000 */   nop
    /* AC90C 001AC90C EC000586 */  lh         $5, 0xEC($16)
    /* AC910 001AC910 3000048E */  lw         $4, 0x30($16)
    /* AC914 001AC914 0009080C */  jal        func_00202400
    /* AC918 001AC918 00000000 */   nop
    /* AC91C 001AC91C 2D204000 */  daddu      $4, $2, $0
    /* AC920 001AC920 04000324 */  addiu      $3, $0, 0x4
    /* AC924 001AC924 000043A0 */  sb         $3, 0x0($2)
    /* AC928 001AC928 580083DE */  ld         $3, 0x58($20)
    /* AC92C 001AC92C 080043FC */  sd         $3, 0x8($2)
    /* AC930 001AC930 600051FC */  sd         $17, 0x60($2)
    /* AC934 001AC934 03000524 */  addiu      $5, $0, 0x3
    /* AC938 001AC938 6451060C */  jal        func_00194590
    /* AC93C 001AC93C 00000000 */   nop
    /* AC940 001AC940 2D200002 */  daddu      $4, $16, $0
    /* AC944 001AC944 2D280000 */  daddu      $5, $0, $0
    /* AC948 001AC948 1CCE070C */  jal        func_001f3870
    /* AC94C 001AC94C 00000000 */   nop
    /* AC950 001AC950 2D204000 */  daddu      $4, $2, $0
    /* AC954 001AC954 04000324 */  addiu      $3, $0, 0x4
    /* AC958 001AC958 000043A0 */  sb         $3, 0x0($2)
    /* AC95C 001AC95C 580083DE */  ld         $3, 0x58($20)
    /* AC960 001AC960 080043FC */  sd         $3, 0x8($2)
    /* AC964 001AC964 600051FC */  sd         $17, 0x60($2)
    /* AC968 001AC968 01000524 */  addiu      $5, $0, 0x1
    /* AC96C 001AC96C 6451060C */  jal        func_00194590
    /* AC970 001AC970 00000000 */   nop
    /* AC974 001AC974 10000424 */  addiu      $4, $0, 0x10
    /* AC978 001AC978 88DF060C */  jal        func_001b7e20
    /* AC97C 001AC97C 00000000 */   nop
    /* AC980 001AC980 2D204000 */  daddu      $4, $2, $0
    /* AC984 001AC984 04000324 */  addiu      $3, $0, 0x4
    /* AC988 001AC988 000043A0 */  sb         $3, 0x0($2)
    /* AC98C 001AC98C 580083DE */  ld         $3, 0x58($20)
    /* AC990 001AC990 080043FC */  sd         $3, 0x8($2)
    /* AC994 001AC994 47004390 */  lbu        $3, 0x47($2)
    /* AC998 001AC998 DF006330 */  andi       $3, $3, 0xDF
    /* AC99C 001AC99C 470043A0 */  sb         $3, 0x47($2)
    /* AC9A0 001AC9A0 600051FC */  sd         $17, 0x60($2)
    /* AC9A4 001AC9A4 01000524 */  addiu      $5, $0, 0x1
    /* AC9A8 001AC9A8 6451060C */  jal        func_00194590
    /* AC9AC 001AC9AC 00000000 */   nop
    /* AC9B0 001AC9B0 10000424 */  addiu      $4, $0, 0x10
    /* AC9B4 001AC9B4 2D280000 */  daddu      $5, $0, $0
    /* AC9B8 001AC9B8 D8E4060C */  jal        func_001b9360
    /* AC9BC 001AC9BC 00000000 */   nop
    /* AC9C0 001AC9C0 2D204000 */  daddu      $4, $2, $0
    /* AC9C4 001AC9C4 04000324 */  addiu      $3, $0, 0x4
    /* AC9C8 001AC9C8 000043A0 */  sb         $3, 0x0($2)
    /* AC9CC 001AC9CC 580083DE */  ld         $3, 0x58($20)
    /* AC9D0 001AC9D0 080043FC */  sd         $3, 0x8($2)
    /* AC9D4 001AC9D4 47004390 */  lbu        $3, 0x47($2)
    /* AC9D8 001AC9D8 DF006330 */  andi       $3, $3, 0xDF
    /* AC9DC 001AC9DC 470043A0 */  sb         $3, 0x47($2)
    /* AC9E0 001AC9E0 600051FC */  sd         $17, 0x60($2)
    /* AC9E4 001AC9E4 01000524 */  addiu      $5, $0, 0x1
    /* AC9E8 001AC9E8 6451060C */  jal        func_00194590
    /* AC9EC 001AC9EC 00000000 */   nop
    /* AC9F0 001AC9F0 10000424 */  addiu      $4, $0, 0x10
    /* AC9F4 001AC9F4 68E6060C */  jal        func_001b99a0
    /* AC9F8 001AC9F8 00000000 */   nop
    /* AC9FC 001AC9FC 2D204000 */  daddu      $4, $2, $0
    /* ACA00 001ACA00 04000324 */  addiu      $3, $0, 0x4
    /* ACA04 001ACA04 000043A0 */  sb         $3, 0x0($2)
    /* ACA08 001ACA08 580083DE */  ld         $3, 0x58($20)
    /* ACA0C 001ACA0C 080043FC */  sd         $3, 0x8($2)
    /* ACA10 001ACA10 47004390 */  lbu        $3, 0x47($2)
    /* ACA14 001ACA14 DF006330 */  andi       $3, $3, 0xDF
    /* ACA18 001ACA18 470043A0 */  sb         $3, 0x47($2)
    /* ACA1C 001ACA1C 600051FC */  sd         $17, 0x60($2)
    /* ACA20 001ACA20 01000524 */  addiu      $5, $0, 0x1
    /* ACA24 001ACA24 6451060C */  jal        func_00194590
    /* ACA28 001ACA28 00000000 */   nop
    /* ACA2C 001ACA2C 08000424 */  addiu      $4, $0, 0x8
    /* ACA30 001ACA30 24E8060C */  jal        func_001ba090
    /* ACA34 001ACA34 00000000 */   nop
    /* ACA38 001ACA38 2D204000 */  daddu      $4, $2, $0
    /* ACA3C 001ACA3C 04000324 */  addiu      $3, $0, 0x4
    /* ACA40 001ACA40 000043A0 */  sb         $3, 0x0($2)
    /* ACA44 001ACA44 580083DE */  ld         $3, 0x58($20)
    /* ACA48 001ACA48 080043FC */  sd         $3, 0x8($2)
    /* ACA4C 001ACA4C 47004390 */  lbu        $3, 0x47($2)
    /* ACA50 001ACA50 DF006330 */  andi       $3, $3, 0xDF
    /* ACA54 001ACA54 470043A0 */  sb         $3, 0x47($2)
    /* ACA58 001ACA58 600051FC */  sd         $17, 0x60($2)
    /* ACA5C 001ACA5C 2D280000 */  daddu      $5, $0, $0
    /* ACA60 001ACA60 6451060C */  jal        func_00194590
    /* ACA64 001ACA64 00000000 */   nop
    /* ACA68 001ACA68 2D200002 */  daddu      $4, $16, $0
    /* ACA6C 001ACA6C 38DA070C */  jal        func_001f68e0
    /* ACA70 001ACA70 00000000 */   nop
    /* ACA74 001ACA74 07004010 */  beqz       $2, .L001ACA94
    /* ACA78 001ACA78 00000000 */   nop
    /* ACA7C 001ACA7C 2D200002 */  daddu      $4, $16, $0
    /* ACA80 001ACA80 1B000524 */  addiu      $5, $0, 0x1B
    /* ACA84 001ACA84 00C2060C */  jal        func_001b0800
    /* ACA88 001ACA88 00000000 */   nop
    /* ACA8C 001ACA8C 14000010 */  b          .L001ACAE0
    /* ACA90 001ACA90 00000000 */   nop
  .L001ACA94:
    /* ACA94 001ACA94 6C000396 */  lhu        $3, 0x6C($16)
    /* ACA98 001ACA98 02000224 */  addiu      $2, $0, 0x2
    /* ACA9C 001ACA9C 09006210 */  beq        $3, $2, .L001ACAC4
    /* ACAA0 001ACAA0 00000000 */   nop
    /* ACAA4 001ACAA4 03000224 */  addiu      $2, $0, 0x3
    /* ACAA8 001ACAA8 06006210 */  beq        $3, $2, .L001ACAC4
    /* ACAAC 001ACAAC 00000000 */   nop
    /* ACAB0 001ACAB0 01000224 */  addiu      $2, $0, 0x1
    /* ACAB4 001ACAB4 03006210 */  beq        $3, $2, .L001ACAC4
    /* ACAB8 001ACAB8 00000000 */   nop
    /* ACABC 001ACABC 04000010 */  b          .L001ACAD0
    /* ACAC0 001ACAC0 00000000 */   nop
  .L001ACAC4:
    /* ACAC4 001ACAC4 20000564 */  daddiu     $5, $0, 0x20
    /* ACAC8 001ACAC8 02000010 */  b          .L001ACAD4
    /* ACACC 001ACACC 00000000 */   nop
  .L001ACAD0:
    /* ACAD0 001ACAD0 20000564 */  daddiu     $5, $0, 0x20
  .L001ACAD4:
    /* ACAD4 001ACAD4 2D200002 */  daddu      $4, $16, $0
    /* ACAD8 001ACAD8 00C2060C */  jal        func_001b0800
    /* ACADC 001ACADC 00000000 */   nop
  .L001ACAE0:
    /* ACAE0 001ACAE0 7000BFDF */  ld         $31, 0x70($29)
    /* ACAE4 001ACAE4 6000B57B */  lq         $21, 0x60($29)
    /* ACAE8 001ACAE8 5000B47B */  lq         $20, 0x50($29)
    /* ACAEC 001ACAEC 4000B37B */  lq         $19, 0x40($29)
    /* ACAF0 001ACAF0 3000B27B */  lq         $18, 0x30($29)
    /* ACAF4 001ACAF4 2000B17B */  lq         $17, 0x20($29)
    /* ACAF8 001ACAF8 1000B07B */  lq         $16, 0x10($29)
    /* ACAFC 001ACAFC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* ACB00 001ACB00 8000BD27 */  addiu      $29, $29, 0x80
    /* ACB04 001ACB04 0800E003 */  jr         $31
    /* ACB08 001ACB08 00000000 */   nop
    /* ACB0C 001ACB0C 00000000 */  nop
.size func_001ac700, 0x410
