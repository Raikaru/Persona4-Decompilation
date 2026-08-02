.section .text
.set noat
.set noreorder
glabel func_001fc630
    /* FC630 001FC630 10FFBD27 */  addiu      $29, $29, -0xF0
    /* FC634 001FC634 8000BFFF */  sd         $31, 0x80($29)
    /* FC638 001FC638 7000B67F */  sq         $22, 0x70($29)
    /* FC63C 001FC63C 6000B57F */  sq         $21, 0x60($29)
    /* FC640 001FC640 5000B47F */  sq         $20, 0x50($29)
    /* FC644 001FC644 4000B37F */  sq         $19, 0x40($29)
    /* FC648 001FC648 3000B27F */  sq         $18, 0x30($29)
    /* FC64C 001FC64C 2000B17F */  sq         $17, 0x20($29)
    /* FC650 001FC650 1000B07F */  sq         $16, 0x10($29)
    /* FC654 001FC654 0000B4E7 */  swc1       $f20, 0x0($29)
    /* FC658 001FC658 2DA08000 */  daddu      $20, $4, $0
    /* FC65C 001FC65C 3000928C */  lw         $18, 0x30($4)
    /* FC660 001FC660 3800938C */  lw         $19, 0x38($4)
    /* FC664 001FC664 2800918C */  lw         $17, 0x28($4)
    /* FC668 001FC668 0C00708E */  lw         $16, 0xC($19)
    /* FC66C 001FC66C 2B081102 */  sltu       $1, $16, $17
    /* FC670 001FC670 03002010 */  beqz       $1, .L001FC680
    /* FC674 001FC674 00000000 */   nop
    /* FC678 001FC678 DE010016 */  bnez       $16, .L001FCDF4
    /* FC67C 001FC67C 00000000 */   nop
  .L001FC680:
    /* FC680 001FC680 2DA80000 */  daddu      $21, $0, $0
    /* FC684 001FC684 5E000012 */  beqz       $16, .L001FC800
    /* FC688 001FC688 00000000 */   nop
    /* FC68C 001FC68C 10006596 */  lhu        $5, 0x10($19)
    /* FC690 001FC690 2B08B100 */  sltu       $1, $5, $17
    /* FC694 001FC694 2C002014 */  bnez       $1, .L001FC748
    /* FC698 001FC698 00000000 */   nop
    /* FC69C 001FC69C 2500A018 */  blez       $5, .L001FC734
    /* FC6A0 001FC6A0 00000000 */   nop
    /* FC6A4 001FC6A4 06002006 */  bltz       $17, .L001FC6C0
    /* FC6A8 001FC6A8 00000000 */   nop
    /* FC6AC 001FC6AC 00009144 */  mtc1       $17, $f0
    /* FC6B0 001FC6B0 00000000 */  nop
    /* FC6B4 001FC6B4 60008046 */  cvt.s.w    $f1, $f0
    /* FC6B8 001FC6B8 08000010 */  b          .L001FC6DC
    /* FC6BC 001FC6BC 00000000 */   nop
  .L001FC6C0:
    /* FC6C0 001FC6C0 42201100 */  srl        $4, $17, 1
    /* FC6C4 001FC6C4 01002332 */  andi       $3, $17, 0x1
    /* FC6C8 001FC6C8 25208300 */  or         $4, $4, $3
    /* FC6CC 001FC6CC 00008444 */  mtc1       $4, $f0
    /* FC6D0 001FC6D0 00000000 */  nop
    /* FC6D4 001FC6D4 60008046 */  cvt.s.w    $f1, $f0
    /* FC6D8 001FC6D8 40080146 */  add.s      $f1, $f1, $f1
  .L001FC6DC:
    /* FC6DC 001FC6DC 0600A004 */  bltz       $5, .L001FC6F8
    /* FC6E0 001FC6E0 00000000 */   nop
    /* FC6E4 001FC6E4 00008544 */  mtc1       $5, $f0
    /* FC6E8 001FC6E8 00000000 */  nop
    /* FC6EC 001FC6EC 20008046 */  cvt.s.w    $f0, $f0
    /* FC6F0 001FC6F0 08000010 */  b          .L001FC714
    /* FC6F4 001FC6F4 00000000 */   nop
  .L001FC6F8:
    /* FC6F8 001FC6F8 42200500 */  srl        $4, $5, 1
    /* FC6FC 001FC6FC 0100A330 */  andi       $3, $5, 0x1
    /* FC700 001FC700 25208300 */  or         $4, $4, $3
    /* FC704 001FC704 00008444 */  mtc1       $4, $f0
    /* FC708 001FC708 00000000 */  nop
    /* FC70C 001FC70C 20008046 */  cvt.s.w    $f0, $f0
    /* FC710 001FC710 00000046 */  add.s      $f0, $f0, $f0
  .L001FC714:
    /* FC714 001FC714 00000000 */  nop
    /* FC718 001FC718 00000000 */  nop
    /* FC71C 001FC71C 030D0046 */  div.s      $f20, $f1, $f0
    /* FC720 001FC720 00000000 */  nop
    /* FC724 001FC724 00000000 */  nop
    /* FC728 001FC728 00000000 */  nop
    /* FC72C 001FC72C 03000010 */  b          .L001FC73C
    /* FC730 001FC730 00000000 */   nop
  .L001FC734:
    /* FC734 001FC734 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FC738 001FC738 00A08344 */  mtc1       $3, $f20
  .L001FC73C:
    /* FC73C 001FC73C 01001564 */  daddiu     $21, $0, 0x1
    /* FC740 001FC740 2F000010 */  b          .L001FC800
    /* FC744 001FC744 00000000 */   nop
  .L001FC748:
    /* FC748 001FC748 12006596 */  lhu        $5, 0x12($19)
    /* FC74C 001FC74C 23180502 */  subu       $3, $16, $5
    /* FC750 001FC750 2B182302 */  sltu       $3, $17, $3
    /* FC754 001FC754 2A006014 */  bnez       $3, .L001FC800
    /* FC758 001FC758 00000000 */   nop
    /* FC75C 001FC75C 2600A018 */  blez       $5, .L001FC7F8
    /* FC760 001FC760 00000000 */   nop
    /* FC764 001FC764 23181102 */  subu       $3, $16, $17
    /* FC768 001FC768 06006004 */  bltz       $3, .L001FC784
    /* FC76C 001FC76C 00000000 */   nop
    /* FC770 001FC770 00008344 */  mtc1       $3, $f0
    /* FC774 001FC774 00000000 */  nop
    /* FC778 001FC778 60008046 */  cvt.s.w    $f1, $f0
    /* FC77C 001FC77C 08000010 */  b          .L001FC7A0
    /* FC780 001FC780 00000000 */   nop
  .L001FC784:
    /* FC784 001FC784 42200300 */  srl        $4, $3, 1
    /* FC788 001FC788 01006330 */  andi       $3, $3, 0x1
    /* FC78C 001FC78C 25208300 */  or         $4, $4, $3
    /* FC790 001FC790 00008444 */  mtc1       $4, $f0
    /* FC794 001FC794 00000000 */  nop
    /* FC798 001FC798 60008046 */  cvt.s.w    $f1, $f0
    /* FC79C 001FC79C 40080146 */  add.s      $f1, $f1, $f1
  .L001FC7A0:
    /* FC7A0 001FC7A0 0600A004 */  bltz       $5, .L001FC7BC
    /* FC7A4 001FC7A4 00000000 */   nop
    /* FC7A8 001FC7A8 00008544 */  mtc1       $5, $f0
    /* FC7AC 001FC7AC 00000000 */  nop
    /* FC7B0 001FC7B0 20008046 */  cvt.s.w    $f0, $f0
    /* FC7B4 001FC7B4 08000010 */  b          .L001FC7D8
    /* FC7B8 001FC7B8 00000000 */   nop
  .L001FC7BC:
    /* FC7BC 001FC7BC 42200500 */  srl        $4, $5, 1
    /* FC7C0 001FC7C0 0100A330 */  andi       $3, $5, 0x1
    /* FC7C4 001FC7C4 25208300 */  or         $4, $4, $3
    /* FC7C8 001FC7C8 00008444 */  mtc1       $4, $f0
    /* FC7CC 001FC7CC 00000000 */  nop
    /* FC7D0 001FC7D0 20008046 */  cvt.s.w    $f0, $f0
    /* FC7D4 001FC7D4 00000046 */  add.s      $f0, $f0, $f0
  .L001FC7D8:
    /* FC7D8 001FC7D8 00000000 */  nop
    /* FC7DC 001FC7DC 00000000 */  nop
    /* FC7E0 001FC7E0 030D0046 */  div.s      $f20, $f1, $f0
    /* FC7E4 001FC7E4 00000000 */  nop
    /* FC7E8 001FC7E8 00000000 */  nop
    /* FC7EC 001FC7EC 00000000 */  nop
    /* FC7F0 001FC7F0 02000010 */  b          .L001FC7FC
    /* FC7F4 001FC7F4 00000000 */   nop
  .L001FC7F8:
    /* FC7F8 001FC7F8 00A08044 */  mtc1       $0, $f20
  .L001FC7FC:
    /* FC7FC 001FC7FC 02001564 */  daddiu     $21, $0, 0x2
  .L001FC800:
    /* FC800 001FC800 2DB00000 */  daddu      $22, $0, $0
    /* FC804 001FC804 0000438E */  lw         $3, 0x0($18)
    /* FC808 001FC808 30006010 */  beqz       $3, .L001FC8CC
    /* FC80C 001FC80C 00000000 */   nop
    /* FC810 001FC810 9000A427 */  addiu      $4, $29, 0x90
    /* FC814 001FC814 10008526 */  addiu      $5, $20, 0x10
    /* FC818 001FC818 5428120C */  jal        func_0048a150
    /* FC81C 001FC81C 00000000 */   nop
    /* FC820 001FC820 0000448E */  lw         $4, 0x0($18)
    /* FC824 001FC824 9000A527 */  addiu      $5, $29, 0x90
    /* FC828 001FC828 2D300000 */  daddu      $6, $0, $0
    /* FC82C 001FC82C 70E8110C */  jal        func_0047a1c0
    /* FC830 001FC830 00000000 */   nop
    /* FC834 001FC834 200081C6 */  lwc1       $f1, 0x20($20)
    /* FC838 001FC838 1C0060C6 */  lwc1       $f0, 0x1C($19)
    /* FC83C 001FC83C 02080046 */  mul.s      $f0, $f1, $f0
    /* FC840 001FC840 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* FC844 001FC844 D400A0E7 */  swc1       $f0, 0xD4($29)
    /* FC848 001FC848 D000A0E7 */  swc1       $f0, 0xD0($29)
    /* FC84C 001FC84C 0000448E */  lw         $4, 0x0($18)
    /* FC850 001FC850 D000A527 */  addiu      $5, $29, 0xD0
    /* FC854 001FC854 02000624 */  addiu      $6, $0, 0x2
    /* FC858 001FC858 78E8110C */  jal        func_0047a1e0
    /* FC85C 001FC85C 00000000 */   nop
    /* FC860 001FC860 000080C6 */  lwc1       $f0, 0x0($20)
    /* FC864 001FC864 D000A0E7 */  swc1       $f0, 0xD0($29)
    /* FC868 001FC868 040080C6 */  lwc1       $f0, 0x4($20)
    /* FC86C 001FC86C D400A0E7 */  swc1       $f0, 0xD4($29)
    /* FC870 001FC870 080080C6 */  lwc1       $f0, 0x8($20)
    /* FC874 001FC874 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* FC878 001FC878 0000448E */  lw         $4, 0x0($18)
    /* FC87C 001FC87C D000A527 */  addiu      $5, $29, 0xD0
    /* FC880 001FC880 02000624 */  addiu      $6, $0, 0x2
    /* FC884 001FC884 60E8110C */  jal        func_0047a180
    /* FC888 001FC888 00000000 */   nop
    /* FC88C 001FC88C 0000448E */  lw         $4, 0x0($18)
    /* FC890 001FC890 2D280000 */  daddu      $5, $0, $0
    /* FC894 001FC894 18006CC6 */  lwc1       $f12, 0x18($19)
    /* FC898 001FC898 38E8110C */  jal        func_0047a0e0
    /* FC89C 001FC89C 00000000 */   nop
    /* FC8A0 001FC8A0 0000448E */  lw         $4, 0x0($18)
    /* FC8A4 001FC8A4 9CE3110C */  jal        func_00478e70
    /* FC8A8 001FC8A8 00000000 */   nop
    /* FC8AC 001FC8AC 0000448E */  lw         $4, 0x0($18)
    /* FC8B0 001FC8B0 2D280000 */  daddu      $5, $0, $0
    /* FC8B4 001FC8B4 E000A627 */  addiu      $6, $29, 0xE0
    /* FC8B8 001FC8B8 B4E9110C */  jal        func_0047a6d0
    /* FC8BC 001FC8BC 00000000 */   nop
    /* FC8C0 001FC8C0 02004010 */  beqz       $2, .L001FC8CC
    /* FC8C4 001FC8C4 00000000 */   nop
    /* FC8C8 001FC8C8 01001624 */  addiu      $22, $0, 0x1
  .L001FC8CC:
    /* FC8CC 001FC8CC 2D600000 */  daddu      $12, $0, $0
    /* FC8D0 001FC8D0 FF00AB32 */  andi       $11, $21, 0xFF
    /* FC8D4 001FC8D4 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FC8D8 001FC8D8 00008344 */  mtc1       $3, $f0
    /* FC8DC 001FC8DC 00000000 */  nop
    /* FC8E0 001FC8E0 01001446 */  sub.s      $f0, $f0, $f20
    /* FC8E4 001FC8E4 40010010 */  b          .L001FCDE8
    /* FC8E8 001FC8E8 00000000 */   nop
  .L001FC8EC:
    /* FC8EC 001FC8EC C0200C00 */  sll        $4, $12, 3
    /* FC8F0 001FC8F0 ACB3838F */  lw         $3, -0x4C54($28)
    /* FC8F4 001FC8F4 21186400 */  addu       $3, $3, $4
    /* FC8F8 001FC8F8 7801648C */  lw         $4, 0x178($3)
    /* FC8FC 001FC8FC 37010010 */  b          .L001FCDDC
    /* FC900 001FC900 00000000 */   nop
  .L001FC904:
    /* FC904 001FC904 2D286002 */  daddu      $5, $19, $0
    /* FC908 001FC908 C0F0070C */  jal        func_001fc300
    /* FC90C 001FC90C 00000000 */   nop
    /* FC910 001FC910 31014010 */  beqz       $2, .L001FCDD8
    /* FC914 001FC914 00000000 */   nop
    /* FC918 001FC918 02000324 */  addiu      $3, $0, 0x2
    /* FC91C 001FC91C BB006311 */  beq        $11, $3, .L001FCC0C
    /* FC920 001FC920 00000000 */   nop
    /* FC924 001FC924 01000324 */  addiu      $3, $0, 0x1
    /* FC928 001FC928 53006311 */  beq        $11, $3, .L001FCA78
    /* FC92C 001FC92C 00000000 */   nop
    /* FC930 001FC930 03006011 */  beqz       $11, .L001FC940
    /* FC934 001FC934 00000000 */   nop
    /* FC938 001FC938 17010010 */  b          .L001FCD98
    /* FC93C 001FC93C 00000000 */   nop
  .L001FC940:
    /* FC940 001FC940 15012016 */  bnez       $17, .L001FCD98
    /* FC944 001FC944 00000000 */   nop
    /* FC948 001FC948 1400638E */  lw         $3, 0x14($19)
    /* FC94C 001FC94C EC00A3AF */  sw         $3, 0xEC($29)
    /* FC950 001FC950 EC00A393 */  lbu        $3, 0xEC($29)
    /* FC954 001FC954 06006004 */  bltz       $3, .L001FC970
    /* FC958 001FC958 00000000 */   nop
    /* FC95C 001FC95C 00088344 */  mtc1       $3, $f1
    /* FC960 001FC960 00000000 */  nop
    /* FC964 001FC964 A0088046 */  cvt.s.w    $f2, $f1
    /* FC968 001FC968 08000010 */  b          .L001FC98C
    /* FC96C 001FC96C 00000000 */   nop
  .L001FC970:
    /* FC970 001FC970 42280300 */  srl        $5, $3, 1
    /* FC974 001FC974 01006330 */  andi       $3, $3, 0x1
    /* FC978 001FC978 2528A300 */  or         $5, $5, $3
    /* FC97C 001FC97C 00088544 */  mtc1       $5, $f1
    /* FC980 001FC980 00000000 */  nop
    /* FC984 001FC984 A0088046 */  cvt.s.w    $f2, $f1
    /* FC988 001FC988 80100246 */  add.s      $f2, $f2, $f2
  .L001FC98C:
    /* FC98C 001FC98C AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FC990 001FC990 42080246 */  mul.s      $f1, $f1, $f2
    /* FC994 001FC994 700081E4 */  swc1       $f1, 0x70($4)
    /* FC998 001FC998 ED00A393 */  lbu        $3, 0xED($29)
    /* FC99C 001FC99C 06006004 */  bltz       $3, .L001FC9B8
    /* FC9A0 001FC9A0 00000000 */   nop
    /* FC9A4 001FC9A4 00088344 */  mtc1       $3, $f1
    /* FC9A8 001FC9A8 00000000 */  nop
    /* FC9AC 001FC9AC A0088046 */  cvt.s.w    $f2, $f1
    /* FC9B0 001FC9B0 08000010 */  b          .L001FC9D4
    /* FC9B4 001FC9B4 00000000 */   nop
  .L001FC9B8:
    /* FC9B8 001FC9B8 42280300 */  srl        $5, $3, 1
    /* FC9BC 001FC9BC 01006330 */  andi       $3, $3, 0x1
    /* FC9C0 001FC9C0 2528A300 */  or         $5, $5, $3
    /* FC9C4 001FC9C4 00088544 */  mtc1       $5, $f1
    /* FC9C8 001FC9C8 00000000 */  nop
    /* FC9CC 001FC9CC A0088046 */  cvt.s.w    $f2, $f1
    /* FC9D0 001FC9D0 80100246 */  add.s      $f2, $f2, $f2
  .L001FC9D4:
    /* FC9D4 001FC9D4 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FC9D8 001FC9D8 42080246 */  mul.s      $f1, $f1, $f2
    /* FC9DC 001FC9DC 740081E4 */  swc1       $f1, 0x74($4)
    /* FC9E0 001FC9E0 EE00A393 */  lbu        $3, 0xEE($29)
    /* FC9E4 001FC9E4 06006004 */  bltz       $3, .L001FCA00
    /* FC9E8 001FC9E8 00000000 */   nop
    /* FC9EC 001FC9EC 00088344 */  mtc1       $3, $f1
    /* FC9F0 001FC9F0 00000000 */  nop
    /* FC9F4 001FC9F4 A0088046 */  cvt.s.w    $f2, $f1
    /* FC9F8 001FC9F8 08000010 */  b          .L001FCA1C
    /* FC9FC 001FC9FC 00000000 */   nop
  .L001FCA00:
    /* FCA00 001FCA00 42280300 */  srl        $5, $3, 1
    /* FCA04 001FCA04 01006330 */  andi       $3, $3, 0x1
    /* FCA08 001FCA08 2528A300 */  or         $5, $5, $3
    /* FCA0C 001FCA0C 00088544 */  mtc1       $5, $f1
    /* FCA10 001FCA10 00000000 */  nop
    /* FCA14 001FCA14 A0088046 */  cvt.s.w    $f2, $f1
    /* FCA18 001FCA18 80100246 */  add.s      $f2, $f2, $f2
  .L001FCA1C:
    /* FCA1C 001FCA1C AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCA20 001FCA20 42080246 */  mul.s      $f1, $f1, $f2
    /* FCA24 001FCA24 780081E4 */  swc1       $f1, 0x78($4)
    /* FCA28 001FCA28 EF00A393 */  lbu        $3, 0xEF($29)
    /* FCA2C 001FCA2C 06006004 */  bltz       $3, .L001FCA48
    /* FCA30 001FCA30 00000000 */   nop
    /* FCA34 001FCA34 00088344 */  mtc1       $3, $f1
    /* FCA38 001FCA38 00000000 */  nop
    /* FCA3C 001FCA3C A0088046 */  cvt.s.w    $f2, $f1
    /* FCA40 001FCA40 08000010 */  b          .L001FCA64
    /* FCA44 001FCA44 00000000 */   nop
  .L001FCA48:
    /* FCA48 001FCA48 42280300 */  srl        $5, $3, 1
    /* FCA4C 001FCA4C 01006330 */  andi       $3, $3, 0x1
    /* FCA50 001FCA50 2528A300 */  or         $5, $5, $3
    /* FCA54 001FCA54 00088544 */  mtc1       $5, $f1
    /* FCA58 001FCA58 00000000 */  nop
    /* FCA5C 001FCA5C A0088046 */  cvt.s.w    $f2, $f1
    /* FCA60 001FCA60 80100246 */  add.s      $f2, $f2, $f2
  .L001FCA64:
    /* FCA64 001FCA64 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCA68 001FCA68 42080246 */  mul.s      $f1, $f1, $f2
    /* FCA6C 001FCA6C 7C0081E4 */  swc1       $f1, 0x7C($4)
    /* FCA70 001FCA70 C9000010 */  b          .L001FCD98
    /* FCA74 001FCA74 00000000 */   nop
  .L001FCA78:
    /* FCA78 001FCA78 09002016 */  bnez       $17, .L001FCAA0
    /* FCA7C 001FCA7C 00000000 */   nop
    /* FCA80 001FCA80 700084C4 */  lwc1       $f4, 0x70($4)
    /* FCA84 001FCA84 740083C4 */  lwc1       $f3, 0x74($4)
    /* FCA88 001FCA88 780082C4 */  lwc1       $f2, 0x78($4)
    /* FCA8C 001FCA8C 7C0081C4 */  lwc1       $f1, 0x7C($4)
    /* FCA90 001FCA90 600084E4 */  swc1       $f4, 0x60($4)
    /* FCA94 001FCA94 640083E4 */  swc1       $f3, 0x64($4)
    /* FCA98 001FCA98 680082E4 */  swc1       $f2, 0x68($4)
    /* FCA9C 001FCA9C 6C0081E4 */  swc1       $f1, 0x6C($4)
  .L001FCAA0:
    /* FCAA0 001FCAA0 1400638E */  lw         $3, 0x14($19)
    /* FCAA4 001FCAA4 EC00A3AF */  sw         $3, 0xEC($29)
    /* FCAA8 001FCAA8 EC00A393 */  lbu        $3, 0xEC($29)
    /* FCAAC 001FCAAC 06006004 */  bltz       $3, .L001FCAC8
    /* FCAB0 001FCAB0 00000000 */   nop
    /* FCAB4 001FCAB4 00088344 */  mtc1       $3, $f1
    /* FCAB8 001FCAB8 00000000 */  nop
    /* FCABC 001FCABC A0088046 */  cvt.s.w    $f2, $f1
    /* FCAC0 001FCAC0 08000010 */  b          .L001FCAE4
    /* FCAC4 001FCAC4 00000000 */   nop
  .L001FCAC8:
    /* FCAC8 001FCAC8 42280300 */  srl        $5, $3, 1
    /* FCACC 001FCACC 01006330 */  andi       $3, $3, 0x1
    /* FCAD0 001FCAD0 2528A300 */  or         $5, $5, $3
    /* FCAD4 001FCAD4 00088544 */  mtc1       $5, $f1
    /* FCAD8 001FCAD8 00000000 */  nop
    /* FCADC 001FCADC A0088046 */  cvt.s.w    $f2, $f1
    /* FCAE0 001FCAE0 80100246 */  add.s      $f2, $f2, $f2
  .L001FCAE4:
    /* FCAE4 001FCAE4 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCAE8 001FCAE8 420A0246 */  mul.s      $f9, $f1, $f2
    /* FCAEC 001FCAEC ED00A393 */  lbu        $3, 0xED($29)
    /* FCAF0 001FCAF0 06006004 */  bltz       $3, .L001FCB0C
    /* FCAF4 001FCAF4 00000000 */   nop
    /* FCAF8 001FCAF8 00088344 */  mtc1       $3, $f1
    /* FCAFC 001FCAFC 00000000 */  nop
    /* FCB00 001FCB00 A0088046 */  cvt.s.w    $f2, $f1
    /* FCB04 001FCB04 08000010 */  b          .L001FCB28
    /* FCB08 001FCB08 00000000 */   nop
  .L001FCB0C:
    /* FCB0C 001FCB0C 42280300 */  srl        $5, $3, 1
    /* FCB10 001FCB10 01006330 */  andi       $3, $3, 0x1
    /* FCB14 001FCB14 2528A300 */  or         $5, $5, $3
    /* FCB18 001FCB18 00088544 */  mtc1       $5, $f1
    /* FCB1C 001FCB1C 00000000 */  nop
    /* FCB20 001FCB20 A0088046 */  cvt.s.w    $f2, $f1
    /* FCB24 001FCB24 80100246 */  add.s      $f2, $f2, $f2
  .L001FCB28:
    /* FCB28 001FCB28 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCB2C 001FCB2C C2080246 */  mul.s      $f3, $f1, $f2
    /* FCB30 001FCB30 EE00A393 */  lbu        $3, 0xEE($29)
    /* FCB34 001FCB34 06006004 */  bltz       $3, .L001FCB50
    /* FCB38 001FCB38 00000000 */   nop
    /* FCB3C 001FCB3C 00088344 */  mtc1       $3, $f1
    /* FCB40 001FCB40 00000000 */  nop
    /* FCB44 001FCB44 A0088046 */  cvt.s.w    $f2, $f1
    /* FCB48 001FCB48 08000010 */  b          .L001FCB6C
    /* FCB4C 001FCB4C 00000000 */   nop
  .L001FCB50:
    /* FCB50 001FCB50 42280300 */  srl        $5, $3, 1
    /* FCB54 001FCB54 01006330 */  andi       $3, $3, 0x1
    /* FCB58 001FCB58 2528A300 */  or         $5, $5, $3
    /* FCB5C 001FCB5C 00088544 */  mtc1       $5, $f1
    /* FCB60 001FCB60 00000000 */  nop
    /* FCB64 001FCB64 A0088046 */  cvt.s.w    $f2, $f1
    /* FCB68 001FCB68 80100246 */  add.s      $f2, $f2, $f2
  .L001FCB6C:
    /* FCB6C 001FCB6C AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCB70 001FCB70 020A0246 */  mul.s      $f8, $f1, $f2
    /* FCB74 001FCB74 EF00A393 */  lbu        $3, 0xEF($29)
    /* FCB78 001FCB78 06006004 */  bltz       $3, .L001FCB94
    /* FCB7C 001FCB7C 00000000 */   nop
    /* FCB80 001FCB80 00088344 */  mtc1       $3, $f1
    /* FCB84 001FCB84 00000000 */  nop
    /* FCB88 001FCB88 A0088046 */  cvt.s.w    $f2, $f1
    /* FCB8C 001FCB8C 08000010 */  b          .L001FCBB0
    /* FCB90 001FCB90 00000000 */   nop
  .L001FCB94:
    /* FCB94 001FCB94 42280300 */  srl        $5, $3, 1
    /* FCB98 001FCB98 01006330 */  andi       $3, $3, 0x1
    /* FCB9C 001FCB9C 2528A300 */  or         $5, $5, $3
    /* FCBA0 001FCBA0 00088544 */  mtc1       $5, $f1
    /* FCBA4 001FCBA4 00000000 */  nop
    /* FCBA8 001FCBA8 A0088046 */  cvt.s.w    $f2, $f1
    /* FCBAC 001FCBAC 80100246 */  add.s      $f2, $f2, $f2
  .L001FCBB0:
    /* FCBB0 001FCBB0 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCBB4 001FCBB4 C2090246 */  mul.s      $f7, $f1, $f2
    /* FCBB8 001FCBB8 600081C4 */  lwc1       $f1, 0x60($4)
    /* FCBBC 001FCBBC 82090046 */  mul.s      $f6, $f1, $f0
    /* FCBC0 001FCBC0 640081C4 */  lwc1       $f1, 0x64($4)
    /* FCBC4 001FCBC4 42090046 */  mul.s      $f5, $f1, $f0
    /* FCBC8 001FCBC8 680081C4 */  lwc1       $f1, 0x68($4)
    /* FCBCC 001FCBCC 02090046 */  mul.s      $f4, $f1, $f0
    /* FCBD0 001FCBD0 6C0081C4 */  lwc1       $f1, 0x6C($4)
    /* FCBD4 001FCBD4 1A080046 */  mula.s     $f1, $f0
    /* FCBD8 001FCBD8 42481446 */  mul.s      $f1, $f9, $f20
    /* FCBDC 001FCBDC C2181446 */  mul.s      $f3, $f3, $f20
    /* FCBE0 001FCBE0 82401446 */  mul.s      $f2, $f8, $f20
    /* FCBE4 001FCBE4 40300146 */  add.s      $f1, $f6, $f1
    /* FCBE8 001FCBE8 700081E4 */  swc1       $f1, 0x70($4)
    /* FCBEC 001FCBEC 40280346 */  add.s      $f1, $f5, $f3
    /* FCBF0 001FCBF0 740081E4 */  swc1       $f1, 0x74($4)
    /* FCBF4 001FCBF4 40200246 */  add.s      $f1, $f4, $f2
    /* FCBF8 001FCBF8 780081E4 */  swc1       $f1, 0x78($4)
    /* FCBFC 001FCBFC 5C381446 */  madd.s     $f1, $f7, $f20
    /* FCC00 001FCC00 7C0081E4 */  swc1       $f1, 0x7C($4)
    /* FCC04 001FCC04 64000010 */  b          .L001FCD98
    /* FCC08 001FCC08 00000000 */   nop
  .L001FCC0C:
    /* FCC0C 001FCC0C 12006396 */  lhu        $3, 0x12($19)
    /* FCC10 001FCC10 23180302 */  subu       $3, $16, $3
    /* FCC14 001FCC14 09002316 */  bne        $17, $3, .L001FCC3C
    /* FCC18 001FCC18 00000000 */   nop
    /* FCC1C 001FCC1C 700084C4 */  lwc1       $f4, 0x70($4)
    /* FCC20 001FCC20 740083C4 */  lwc1       $f3, 0x74($4)
    /* FCC24 001FCC24 780082C4 */  lwc1       $f2, 0x78($4)
    /* FCC28 001FCC28 7C0081C4 */  lwc1       $f1, 0x7C($4)
    /* FCC2C 001FCC2C 600084E4 */  swc1       $f4, 0x60($4)
    /* FCC30 001FCC30 640083E4 */  swc1       $f3, 0x64($4)
    /* FCC34 001FCC34 680082E4 */  swc1       $f2, 0x68($4)
    /* FCC38 001FCC38 6C0081E4 */  swc1       $f1, 0x6C($4)
  .L001FCC3C:
    /* FCC3C 001FCC3C 64BB8393 */  lbu        $3, -0x449C($28)
    /* FCC40 001FCC40 06006004 */  bltz       $3, .L001FCC5C
    /* FCC44 001FCC44 00000000 */   nop
    /* FCC48 001FCC48 00088344 */  mtc1       $3, $f1
    /* FCC4C 001FCC4C 00000000 */  nop
    /* FCC50 001FCC50 A0088046 */  cvt.s.w    $f2, $f1
    /* FCC54 001FCC54 08000010 */  b          .L001FCC78
    /* FCC58 001FCC58 00000000 */   nop
  .L001FCC5C:
    /* FCC5C 001FCC5C 42280300 */  srl        $5, $3, 1
    /* FCC60 001FCC60 01006330 */  andi       $3, $3, 0x1
    /* FCC64 001FCC64 2528A300 */  or         $5, $5, $3
    /* FCC68 001FCC68 00088544 */  mtc1       $5, $f1
    /* FCC6C 001FCC6C 00000000 */  nop
    /* FCC70 001FCC70 A0088046 */  cvt.s.w    $f2, $f1
    /* FCC74 001FCC74 80100246 */  add.s      $f2, $f2, $f2
  .L001FCC78:
    /* FCC78 001FCC78 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCC7C 001FCC7C 42090246 */  mul.s      $f5, $f1, $f2
    /* FCC80 001FCC80 65BB8393 */  lbu        $3, -0x449B($28)
    /* FCC84 001FCC84 06006004 */  bltz       $3, .L001FCCA0
    /* FCC88 001FCC88 00000000 */   nop
    /* FCC8C 001FCC8C 00088344 */  mtc1       $3, $f1
    /* FCC90 001FCC90 00000000 */  nop
    /* FCC94 001FCC94 A0088046 */  cvt.s.w    $f2, $f1
    /* FCC98 001FCC98 08000010 */  b          .L001FCCBC
    /* FCC9C 001FCC9C 00000000 */   nop
  .L001FCCA0:
    /* FCCA0 001FCCA0 42280300 */  srl        $5, $3, 1
    /* FCCA4 001FCCA4 01006330 */  andi       $3, $3, 0x1
    /* FCCA8 001FCCA8 2528A300 */  or         $5, $5, $3
    /* FCCAC 001FCCAC 00088544 */  mtc1       $5, $f1
    /* FCCB0 001FCCB0 00000000 */  nop
    /* FCCB4 001FCCB4 A0088046 */  cvt.s.w    $f2, $f1
    /* FCCB8 001FCCB8 80100246 */  add.s      $f2, $f2, $f2
  .L001FCCBC:
    /* FCCBC 001FCCBC AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCCC0 001FCCC0 02090246 */  mul.s      $f4, $f1, $f2
    /* FCCC4 001FCCC4 66BB8393 */  lbu        $3, -0x449A($28)
    /* FCCC8 001FCCC8 06006004 */  bltz       $3, .L001FCCE4
    /* FCCCC 001FCCCC 00000000 */   nop
    /* FCCD0 001FCCD0 00088344 */  mtc1       $3, $f1
    /* FCCD4 001FCCD4 00000000 */  nop
    /* FCCD8 001FCCD8 A0088046 */  cvt.s.w    $f2, $f1
    /* FCCDC 001FCCDC 08000010 */  b          .L001FCD00
    /* FCCE0 001FCCE0 00000000 */   nop
  .L001FCCE4:
    /* FCCE4 001FCCE4 42280300 */  srl        $5, $3, 1
    /* FCCE8 001FCCE8 01006330 */  andi       $3, $3, 0x1
    /* FCCEC 001FCCEC 2528A300 */  or         $5, $5, $3
    /* FCCF0 001FCCF0 00088544 */  mtc1       $5, $f1
    /* FCCF4 001FCCF4 00000000 */  nop
    /* FCCF8 001FCCF8 A0088046 */  cvt.s.w    $f2, $f1
    /* FCCFC 001FCCFC 80100246 */  add.s      $f2, $f2, $f2
  .L001FCD00:
    /* FCD00 001FCD00 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCD04 001FCD04 C2080246 */  mul.s      $f3, $f1, $f2
    /* FCD08 001FCD08 67BB8393 */  lbu        $3, -0x4499($28)
    /* FCD0C 001FCD0C 06006004 */  bltz       $3, .L001FCD28
    /* FCD10 001FCD10 00000000 */   nop
    /* FCD14 001FCD14 00088344 */  mtc1       $3, $f1
    /* FCD18 001FCD18 00000000 */  nop
    /* FCD1C 001FCD1C A0088046 */  cvt.s.w    $f2, $f1
    /* FCD20 001FCD20 08000010 */  b          .L001FCD44
    /* FCD24 001FCD24 00000000 */   nop
  .L001FCD28:
    /* FCD28 001FCD28 42280300 */  srl        $5, $3, 1
    /* FCD2C 001FCD2C 01006330 */  andi       $3, $3, 0x1
    /* FCD30 001FCD30 2528A300 */  or         $5, $5, $3
    /* FCD34 001FCD34 00088544 */  mtc1       $5, $f1
    /* FCD38 001FCD38 00000000 */  nop
    /* FCD3C 001FCD3C A0088046 */  cvt.s.w    $f2, $f1
    /* FCD40 001FCD40 80100246 */  add.s      $f2, $f2, $f2
  .L001FCD44:
    /* FCD44 001FCD44 AC8181C7 */  lwc1       $f1, -0x7E54($28)
    /* FCD48 001FCD48 42080246 */  mul.s      $f1, $f1, $f2
    /* FCD4C 001FCD4C 022A0046 */  mul.s      $f8, $f5, $f0
    /* FCD50 001FCD50 C2210046 */  mul.s      $f7, $f4, $f0
    /* FCD54 001FCD54 82190046 */  mul.s      $f6, $f3, $f0
    /* FCD58 001FCD58 1A080046 */  mula.s     $f1, $f0
    /* FCD5C 001FCD5C 600081C4 */  lwc1       $f1, 0x60($4)
    /* FCD60 001FCD60 42091446 */  mul.s      $f5, $f1, $f20
    /* FCD64 001FCD64 640081C4 */  lwc1       $f1, 0x64($4)
    /* FCD68 001FCD68 02091446 */  mul.s      $f4, $f1, $f20
    /* FCD6C 001FCD6C 680081C4 */  lwc1       $f1, 0x68($4)
    /* FCD70 001FCD70 C2081446 */  mul.s      $f3, $f1, $f20
    /* FCD74 001FCD74 6C0082C4 */  lwc1       $f2, 0x6C($4)
    /* FCD78 001FCD78 40400546 */  add.s      $f1, $f8, $f5
    /* FCD7C 001FCD7C 700081E4 */  swc1       $f1, 0x70($4)
    /* FCD80 001FCD80 40380446 */  add.s      $f1, $f7, $f4
    /* FCD84 001FCD84 740081E4 */  swc1       $f1, 0x74($4)
    /* FCD88 001FCD88 40300346 */  add.s      $f1, $f6, $f3
    /* FCD8C 001FCD8C 780081E4 */  swc1       $f1, 0x78($4)
    /* FCD90 001FCD90 5C101446 */  madd.s     $f1, $f2, $f20
    /* FCD94 001FCD94 7C0081E4 */  swc1       $f1, 0x7C($4)
  .L001FCD98:
    /* FCD98 001FCD98 0900C012 */  beqz       $22, .L001FCDC0
    /* FCD9C 001FCD9C 00000000 */   nop
    /* FCDA0 001FCDA0 E000A3C7 */  lwc1       $f3, 0xE0($29)
    /* FCDA4 001FCDA4 E400A2C7 */  lwc1       $f2, 0xE4($29)
    /* FCDA8 001FCDA8 E800A1C7 */  lwc1       $f1, 0xE8($29)
    /* FCDAC 001FCDAC 540083E4 */  swc1       $f3, 0x54($4)
    /* FCDB0 001FCDB0 580082E4 */  swc1       $f2, 0x58($4)
    /* FCDB4 001FCDB4 5C0081E4 */  swc1       $f1, 0x5C($4)
    /* FCDB8 001FCDB8 07000010 */  b          .L001FCDD8
    /* FCDBC 001FCDBC 00000000 */   nop
  .L001FCDC0:
    /* FCDC0 001FCDC0 000081C6 */  lwc1       $f1, 0x0($20)
    /* FCDC4 001FCDC4 540081E4 */  swc1       $f1, 0x54($4)
    /* FCDC8 001FCDC8 040081C6 */  lwc1       $f1, 0x4($20)
    /* FCDCC 001FCDCC 580081E4 */  swc1       $f1, 0x58($4)
    /* FCDD0 001FCDD0 080081C6 */  lwc1       $f1, 0x8($20)
    /* FCDD4 001FCDD4 5C0081E4 */  swc1       $f1, 0x5C($4)
  .L001FCDD8:
    /* FCDD8 001FCDD8 6C0A848C */  lw         $4, 0xA6C($4)
  .L001FCDDC:
    /* FCDDC 001FCDDC C9FE8014 */  bnez       $4, .L001FC904
    /* FCDE0 001FCDE0 00000000 */   nop
    /* FCDE4 001FCDE4 01008C25 */  addiu      $12, $12, 0x1
  .L001FCDE8:
    /* FCDE8 001FCDE8 0400832D */  sltiu      $3, $12, 0x4
    /* FCDEC 001FCDEC BFFE6014 */  bnez       $3, .L001FC8EC
    /* FCDF0 001FCDF0 00000000 */   nop
  .L001FCDF4:
    /* FCDF4 001FCDF4 8000BFDF */  ld         $31, 0x80($29)
    /* FCDF8 001FCDF8 7000B67B */  lq         $22, 0x70($29)
    /* FCDFC 001FCDFC 6000B57B */  lq         $21, 0x60($29)
    /* FCE00 001FCE00 5000B47B */  lq         $20, 0x50($29)
    /* FCE04 001FCE04 4000B37B */  lq         $19, 0x40($29)
    /* FCE08 001FCE08 3000B27B */  lq         $18, 0x30($29)
    /* FCE0C 001FCE0C 2000B17B */  lq         $17, 0x20($29)
    /* FCE10 001FCE10 1000B07B */  lq         $16, 0x10($29)
    /* FCE14 001FCE14 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* FCE18 001FCE18 F000BD27 */  addiu      $29, $29, 0xF0
    /* FCE1C 001FCE1C 0800E003 */  jr         $31
    /* FCE20 001FCE20 00000000 */   nop
    /* FCE24 001FCE24 00000000 */  nop
    /* FCE28 001FCE28 00000000 */  nop
    /* FCE2C 001FCE2C 00000000 */  nop
.size func_001fc630, 0x800
