.section .text
.set noat
.set noreorder
glabel func_003db630
    /* 2DB630 003DB630 E0FEBD27 */  addiu      $29, $29, -0x120
    /* 2DB634 003DB634 48000624 */  addiu      $6, $0, 0x48
    /* 2DB638 003DB638 9000BFFF */  sd         $31, 0x90($29)
    /* 2DB63C 003DB63C 8000BE7F */  sq         $30, 0x80($29)
    /* 2DB640 003DB640 7000B77F */  sq         $23, 0x70($29)
    /* 2DB644 003DB644 6000B67F */  sq         $22, 0x60($29)
    /* 2DB648 003DB648 5000B57F */  sq         $21, 0x50($29)
    /* 2DB64C 003DB64C 4000B47F */  sq         $20, 0x40($29)
    /* 2DB650 003DB650 3000B37F */  sq         $19, 0x30($29)
    /* 2DB654 003DB654 2000B27F */  sq         $18, 0x20($29)
    /* 2DB658 003DB658 2D988000 */  daddu      $19, $4, $0
    /* 2DB65C 003DB65C BC00A5AF */  sw         $5, 0xBC($29)
    /* 2DB660 003DB660 1000B17F */  sq         $17, 0x10($29)
    /* 2DB664 003DB664 C000A527 */  addiu      $5, $29, 0xC0
    /* 2DB668 003DB668 0000B07F */  sq         $16, 0x0($29)
    /* 2DB66C 003DB66C 448A0F0C */  jal        func_003e2910
    /* 2DB670 003DB670 A000A0AF */   sw        $0, 0xA0($29)
    /* 2DB674 003DB674 48000324 */  addiu      $3, $0, 0x48
    /* 2DB678 003DB678 03004310 */  beq        $2, $3, .L003DB688
    /* 2DB67C 003DB67C 00000000 */   nop
    /* 2DB680 003DB680 43010010 */  b          .L003DBB90
    /* 2DB684 003DB684 2D100000 */   daddu     $2, $0, $0
  .L003DB688:
    /* 2DB688 003DB688 0100023C */  lui        $2, (0x101B3 >> 16)
    /* 2DB68C 003DB68C 0001B027 */  addiu      $16, $29, 0x100
    /* 2DB690 003DB690 B3014534 */  ori        $5, $2, (0x101B3 & 0xFFFF)
    /* 2DB694 003DB694 0000038E */  lw         $3, 0x0($16)
    /* 2DB698 003DB698 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2DB69C 003DB69C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2DB6A0 003DB6A0 09F84000 */  jalr       $2
    /* 2DB6A4 003DB6A4 80200300 */   sll       $4, $3, 2
    /* 2DB6A8 003DB6A8 2DA84000 */  daddu      $21, $2, $0
    /* 2DB6AC 003DB6AC 9F00A012 */  beqz       $21, .L003DB92C
    /* 2DB6B0 003DB6B0 00000000 */   nop
    /* 2DB6B4 003DB6B4 0000028E */  lw         $2, 0x0($16)
    /* 2DB6B8 003DB6B8 2A100200 */  slt        $2, $0, $2
    /* 2DB6BC 003DB6BC A7004014 */  bnez       $2, .L003DB95C
    /* 2DB6C0 003DB6C0 2D900000 */   daddu     $18, $0, $0
    /* 2DB6C4 003DB6C4 0000A38E */  lw         $3, 0x0($21)
  .L003DB6C8:
    /* 2DB6C8 003DB6C8 04001124 */  addiu      $17, $0, 0x4
    /* 2DB6CC 003DB6CC 0000028E */  lw         $2, 0x0($16)
    /* 2DB6D0 003DB6D0 0400638C */  lw         $3, 0x4($3)
    /* 2DB6D4 003DB6D4 02004128 */  slti       $1, $2, 0x2
    /* 2DB6D8 003DB6D8 1C01A3AF */  sw         $3, 0x11C($29)
    /* 2DB6DC 003DB6DC 0000A38E */  lw         $3, 0x0($21)
    /* 2DB6E0 003DB6E0 0800638C */  lw         $3, 0x8($3)
    /* 2DB6E4 003DB6E4 1801A3AF */  sw         $3, 0x118($29)
    /* 2DB6E8 003DB6E8 0000A38E */  lw         $3, 0x0($21)
    /* 2DB6EC 003DB6EC 0C00638C */  lw         $3, 0xC($3)
    /* 2DB6F0 003DB6F0 03002014 */  bnez       $1, .L003DB700
    /* 2DB6F4 003DB6F4 1401A3AF */   sw        $3, 0x114($29)
    /* 2DB6F8 003DB6F8 09000010 */  b          .L003DB720
    /* 2DB6FC 003DB6FC 00803136 */   ori       $17, $17, 0x8000
  .L003DB700:
    /* 2DB700 003DB700 0401A393 */  lbu        $3, 0x104($29)
    /* 2DB704 003DB704 01000224 */  addiu      $2, $0, 0x1
    /* 2DB708 003DB708 05006210 */  beq        $3, $2, .L003DB720
    /* 2DB70C 003DB70C 00000000 */   nop
    /* 2DB710 003DB710 02000224 */  addiu      $2, $0, 0x2
    /* 2DB714 003DB714 02006210 */  beq        $3, $2, .L003DB720
    /* 2DB718 003DB718 00000000 */   nop
    /* 2DB71C 003DB71C 00903136 */  ori        $17, $17, 0x9000
  .L003DB720:
    /* 2DB720 003DB720 0000A48E */  lw         $4, 0x0($21)
    /* 2DB724 003DB724 2D282002 */  daddu      $5, $17, $0
    /* 2DB728 003DB728 1C01A627 */  addiu      $6, $29, 0x11C
    /* 2DB72C 003DB72C 1801A727 */  addiu      $7, $29, 0x118
    /* 2DB730 003DB730 1401A827 */  addiu      $8, $29, 0x114
    /* 2DB734 003DB734 7CB00F0C */  jal        func_003ec1f0
    /* 2DB738 003DB738 1001A927 */   addiu     $9, $29, 0x110
    /* 2DB73C 003DB73C 1001A28F */  lw         $2, 0x110($29)
    /* 2DB740 003DB740 1C01A48F */  lw         $4, 0x11C($29)
    /* 2DB744 003DB744 1801A58F */  lw         $5, 0x118($29)
    /* 2DB748 003DB748 1401A68F */  lw         $6, 0x114($29)
    /* 2DB74C 003DB74C 64B10F0C */  jal        func_003ec590
    /* 2DB750 003DB750 25382202 */   or        $7, $17, $2
    /* 2DB754 003DB754 2DA04000 */  daddu      $20, $2, $0
    /* 2DB758 003DB758 A3008012 */  beqz       $20, .L003DB9E8
    /* 2DB75C 003DB75C 00000000 */   nop
    /* 2DB760 003DB760 0000A38E */  lw         $3, 0x0($21)
    /* 2DB764 003DB764 0C00938E */  lw         $19, 0xC($20)
    /* 2DB768 003DB768 0400628C */  lw         $2, 0x4($3)
    /* 2DB76C 003DB76C 05005314 */  bne        $2, $19, .L003DB784
    /* 2DB770 003DB770 00000000 */   nop
    /* 2DB774 003DB774 0800638C */  lw         $3, 0x8($3)
    /* 2DB778 003DB778 1000828E */  lw         $2, 0x10($20)
    /* 2DB77C 003DB77C 34006210 */  beq        $3, $2, .L003DB850
    /* 2DB780 003DB780 00000000 */   nop
  .L003DB784:
    /* 2DB784 003DB784 1401A38F */  lw         $3, 0x114($29)
    /* 2DB788 003DB788 08000224 */  addiu      $2, $0, 0x8
    /* 2DB78C 003DB78C 11006214 */  bne        $3, $2, .L003DB7D4
    /* 2DB790 003DB790 1000928E */   lw        $18, 0x10($20)
    /* 2DB794 003DB794 CCB00F0C */  jal        func_003ec330
    /* 2DB798 003DB798 2D208002 */   daddu     $4, $20, $0
    /* 2DB79C 003DB79C 00052736 */  ori        $7, $17, 0x500
    /* 2DB7A0 003DB7A0 2D206002 */  daddu      $4, $19, $0
    /* 2DB7A4 003DB7A4 2D284002 */  daddu      $5, $18, $0
    /* 2DB7A8 003DB7A8 64B10F0C */  jal        func_003ec590
    /* 2DB7AC 003DB7AC 20000624 */   addiu     $6, $0, 0x20
    /* 2DB7B0 003DB7B0 2DA04000 */  daddu      $20, $2, $0
    /* 2DB7B4 003DB7B4 07008016 */  bnez       $20, .L003DB7D4
    /* 2DB7B8 003DB7B8 00000000 */   nop
    /* 2DB7BC 003DB7BC 00012736 */  ori        $7, $17, 0x100
    /* 2DB7C0 003DB7C0 2D206002 */  daddu      $4, $19, $0
    /* 2DB7C4 003DB7C4 2D284002 */  daddu      $5, $18, $0
    /* 2DB7C8 003DB7C8 64B10F0C */  jal        func_003ec590
    /* 2DB7CC 003DB7CC 10000624 */   addiu     $6, $0, 0x10
    /* 2DB7D0 003DB7D0 2DA04000 */  daddu      $20, $2, $0
  .L003DB7D4:
    /* 2DB7D4 003DB7D4 08B10F0C */  jal        func_003ec420
    /* 2DB7D8 003DB7D8 2D208002 */   daddu     $4, $20, $0
    /* 2DB7DC 003DB7DC 2DF04000 */  daddu      $30, $2, $0
    /* 2DB7E0 003DB7E0 2A081E00 */  slt        $1, $0, $30
    /* 2DB7E4 003DB7E4 1A002010 */  beqz       $1, .L003DB850
    /* 2DB7E8 003DB7E8 2DB00000 */   daddu     $22, $0, $0
    /* 2DB7EC 003DB7EC 2D88A002 */  daddu      $17, $21, $0
  .L003DB7F0:
    /* 2DB7F0 003DB7F0 0000248E */  lw         $4, 0x0($17)
    /* 2DB7F4 003DB7F4 2D286002 */  daddu      $5, $19, $0
    /* 2DB7F8 003DB7F8 B4B40F0C */  jal        func_003ed2d0
    /* 2DB7FC 003DB7FC 2D304002 */   daddu     $6, $18, $0
    /* 2DB800 003DB800 2DB84000 */  daddu      $23, $2, $0
    /* 2DB804 003DB804 0300E016 */  bnez       $23, .L003DB814
    /* 2DB808 003DB808 00000000 */   nop
    /* 2DB80C 003DB80C E0000010 */  b          .L003DBB90
    /* 2DB810 003DB810 2D100000 */   daddu     $2, $0, $0
  .L003DB814:
    /* 2DB814 003DB814 DCA80F0C */  jal        func_003ea370
    /* 2DB818 003DB818 0000248E */   lw        $4, 0x0($17)
    /* 2DB81C 003DB81C 0200612A */  slti       $1, $19, 0x2
    /* 2DB820 003DB820 03002014 */  bnez       $1, .L003DB830
    /* 2DB824 003DB824 000037AE */   sw        $23, 0x0($17)
    /* 2DB828 003DB828 43981300 */  sra        $19, $19, 1
    /* 2DB82C 003DB82C 00000000 */  nop
  .L003DB830:
    /* 2DB830 003DB830 0200412A */  slti       $1, $18, 0x2
    /* 2DB834 003DB834 02002014 */  bnez       $1, .L003DB840
    /* 2DB838 003DB838 00000000 */   nop
    /* 2DB83C 003DB83C 43901200 */  sra        $18, $18, 1
  .L003DB840:
    /* 2DB840 003DB840 0100D626 */  addiu      $22, $22, 0x1
    /* 2DB844 003DB844 2A10DE02 */  slt        $2, $22, $30
    /* 2DB848 003DB848 E9FF4014 */  bnez       $2, .L003DB7F0
    /* 2DB84C 003DB84C 04003126 */   addiu     $17, $17, 0x4
  .L003DB850:
    /* 2DB850 003DB850 0000028E */  lw         $2, 0x0($16)
    /* 2DB854 003DB854 02004128 */  slti       $1, $2, 0x2
    /* 2DB858 003DB858 75002010 */  beqz       $1, .L003DBA30
    /* 2DB85C 003DB85C 00000000 */   nop
  .L003DB860:
    /* 2DB860 003DB860 08B10F0C */  jal        func_003ec420
    /* 2DB864 003DB864 2D208002 */   daddu     $4, $20, $0
    /* 2DB868 003DB868 2D884000 */  daddu      $17, $2, $0
    /* 2DB86C 003DB86C 2A081100 */  slt        $1, $0, $17
    /* 2DB870 003DB870 1B002010 */  beqz       $1, .L003DB8E0
    /* 2DB874 003DB874 2D900000 */   daddu     $18, $0, $0
    /* 2DB878 003DB878 2D98A002 */  daddu      $19, $21, $0
  .L003DB87C:
    /* 2DB87C 003DB87C 0000028E */  lw         $2, 0x0($16)
    /* 2DB880 003DB880 17004212 */  beq        $18, $2, .L003DB8E0
    /* 2DB884 003DB884 00000000 */   nop
    /* 2DB888 003DB888 FF004532 */  andi       $5, $18, 0xFF
    /* 2DB88C 003DB88C 2D208002 */  daddu      $4, $20, $0
    /* 2DB890 003DB890 A8B10F0C */  jal        func_003ec6a0
    /* 2DB894 003DB894 01000624 */   addiu     $6, $0, 0x1
    /* 2DB898 003DB898 6D004010 */  beqz       $2, .L003DBA50
    /* 2DB89C 003DB89C 00000000 */   nop
    /* 2DB8A0 003DB8A0 0000658E */  lw         $5, 0x0($19)
    /* 2DB8A4 003DB8A4 60B00F0C */  jal        func_003ec180
    /* 2DB8A8 003DB8A8 2D208002 */   daddu     $4, $20, $0
    /* 2DB8AC 003DB8AC 6A004010 */  beqz       $2, .L003DBA58
    /* 2DB8B0 003DB8B0 00000000 */   nop
    /* 2DB8B4 003DB8B4 A8B00F0C */  jal        func_003ec2a0
    /* 2DB8B8 003DB8B8 2D208002 */   daddu     $4, $20, $0
    /* 2DB8BC 003DB8BC 68004010 */  beqz       $2, .L003DBA60
    /* 2DB8C0 003DB8C0 00000000 */   nop
    /* 2DB8C4 003DB8C4 DCA80F0C */  jal        func_003ea370
    /* 2DB8C8 003DB8C8 0000648E */   lw        $4, 0x0($19)
    /* 2DB8CC 003DB8CC 01005226 */  addiu      $18, $18, 0x1
    /* 2DB8D0 003DB8D0 2A105102 */  slt        $2, $18, $17
    /* 2DB8D4 003DB8D4 E9FF4014 */  bnez       $2, .L003DB87C
    /* 2DB8D8 003DB8D8 04007326 */   addiu     $19, $19, 0x4
    /* 2DB8DC 003DB8DC 00000000 */  nop
  .L003DB8E0:
    /* 2DB8E0 003DB8E0 0000028E */  lw         $2, 0x0($16)
    /* 2DB8E4 003DB8E4 02004128 */  slti       $1, $2, 0x2
    /* 2DB8E8 003DB8E8 5F002010 */  beqz       $1, .L003DBA68
    /* 2DB8EC 003DB8EC 00000000 */   nop
  .L003DB8F0:
    /* 2DB8F0 003DB8F0 0000028E */  lw         $2, 0x0($16)
    /* 2DB8F4 003DB8F4 2A084202 */  slt        $1, $18, $2
    /* 2DB8F8 003DB8F8 61002010 */  beqz       $1, .L003DBA80
    /* 2DB8FC 003DB8FC 00000000 */   nop
    /* 2DB900 003DB900 80101200 */  sll        $2, $18, 2
    /* 2DB904 003DB904 2188A202 */  addu       $17, $21, $2
  .L003DB908:
    /* 2DB908 003DB908 DCA80F0C */  jal        func_003ea370
    /* 2DB90C 003DB90C 0000248E */   lw        $4, 0x0($17)
    /* 2DB910 003DB910 0000028E */  lw         $2, 0x0($16)
    /* 2DB914 003DB914 01005226 */  addiu      $18, $18, 0x1
    /* 2DB918 003DB918 2A104202 */  slt        $2, $18, $2
    /* 2DB91C 003DB91C FAFF4014 */  bnez       $2, .L003DB908
    /* 2DB920 003DB920 04003126 */   addiu     $17, $17, 0x4
    /* 2DB924 003DB924 56000010 */  b          .L003DBA80
    /* 2DB928 003DB928 00000000 */   nop
  .L003DB92C:
    /* 2DB92C 003DB92C 0000038E */  lw         $3, 0x0($16)
    /* 2DB930 003DB930 B3010224 */  addiu      $2, $0, 0x1B3
    /* 2DB934 003DB934 0801A2AF */  sw         $2, 0x108($29)
    /* 2DB938 003DB938 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2DB93C 003DB93C 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2DB940 003DB940 647D0F0C */  jal        func_003df590
    /* 2DB944 003DB944 80280300 */   sll       $5, $3, 2
    /* 2DB948 003DB948 0C01A2AF */  sw         $2, 0x10C($29)
    /* 2DB94C 003DB94C 347D0F0C */  jal        func_003df4d0
    /* 2DB950 003DB950 0801A427 */   addiu     $4, $29, 0x108
    /* 2DB954 003DB954 8E000010 */  b          .L003DBB90
    /* 2DB958 003DB958 2D100000 */   daddu     $2, $0, $0
  .L003DB95C:
    /* 2DB95C 003DB95C 2D88A002 */  daddu      $17, $21, $0
  .L003DB960:
    /* 2DB960 003DB960 2D206002 */  daddu      $4, $19, $0
    /* 2DB964 003DB964 18000524 */  addiu      $5, $0, 0x18
    /* 2DB968 003DB968 2D300000 */  daddu      $6, $0, $0
    /* 2DB96C 003DB96C 147C0F0C */  jal        func_003df050
    /* 2DB970 003DB970 2D380000 */   daddu     $7, $0, $0
    /* 2DB974 003DB974 03004014 */  bnez       $2, .L003DB984
    /* 2DB978 003DB978 00000000 */   nop
    /* 2DB97C 003DB97C 84000010 */  b          .L003DBB90
    /* 2DB980 003DB980 2D100000 */   daddu     $2, $0, $0
  .L003DB984:
    /* 2DB984 003DB984 FCAE0F0C */  jal        func_003ebbf0
    /* 2DB988 003DB988 2D206002 */   daddu     $4, $19, $0
    /* 2DB98C 003DB98C 000022AE */  sw         $2, 0x0($17)
    /* 2DB990 003DB990 0000248E */  lw         $4, 0x0($17)
    /* 2DB994 003DB994 0D008010 */  beqz       $4, .L003DB9CC
    /* 2DB998 003DB998 00000000 */   nop
    /* 2DB99C 003DB99C 0000828C */  lw         $2, 0x0($4)
    /* 2DB9A0 003DB9A0 02004230 */  andi       $2, $2, 0x2
    /* 2DB9A4 003DB9A4 0B004010 */  beqz       $2, .L003DB9D4
    /* 2DB9A8 003DB9A8 00000000 */   nop
    /* 2DB9AC 003DB9AC 00000000 */  nop
  .L003DB9B0:
    /* 2DB9B0 003DB9B0 0000028E */  lw         $2, 0x0($16)
    /* 2DB9B4 003DB9B4 01005226 */  addiu      $18, $18, 0x1
    /* 2DB9B8 003DB9B8 2A104202 */  slt        $2, $18, $2
    /* 2DB9BC 003DB9BC E8FF4014 */  bnez       $2, .L003DB960
    /* 2DB9C0 003DB9C0 04003126 */   addiu     $17, $17, 0x4
    /* 2DB9C4 003DB9C4 40FF0010 */  b          .L003DB6C8
    /* 2DB9C8 003DB9C8 0000A38E */   lw        $3, 0x0($21)
  .L003DB9CC:
    /* 2DB9CC 003DB9CC 70000010 */  b          .L003DBB90
    /* 2DB9D0 003DB9D0 2D100000 */   daddu     $2, $0, $0
  .L003DB9D4:
    /* 2DB9D4 003DB9D4 78AF0F0C */  jal        func_003ebde0
    /* 2DB9D8 003DB9D8 00000000 */   nop
    /* 2DB9DC 003DB9DC F4FF0010 */  b          .L003DB9B0
    /* 2DB9E0 003DB9E0 00000000 */   nop
    /* 2DB9E4 003DB9E4 00000000 */  nop
  .L003DB9E8:
    /* 2DB9E8 003DB9E8 0000028E */  lw         $2, 0x0($16)
    /* 2DB9EC 003DB9EC 2A080200 */  slt        $1, $0, $2
    /* 2DB9F0 003DB9F0 09002010 */  beqz       $1, .L003DBA18
    /* 2DB9F4 003DB9F4 2D880000 */   daddu     $17, $0, $0
    /* 2DB9F8 003DB9F8 2D90A002 */  daddu      $18, $21, $0
  .L003DB9FC:
    /* 2DB9FC 003DB9FC DCA80F0C */  jal        func_003ea370
    /* 2DBA00 003DBA00 0000448E */   lw        $4, 0x0($18)
    /* 2DBA04 003DBA04 0000028E */  lw         $2, 0x0($16)
    /* 2DBA08 003DBA08 01003126 */  addiu      $17, $17, 0x1
    /* 2DBA0C 003DBA0C 2A102202 */  slt        $2, $17, $2
    /* 2DBA10 003DBA10 FAFF4014 */  bnez       $2, .L003DB9FC
    /* 2DBA14 003DBA14 04005226 */   addiu     $18, $18, 0x4
  .L003DBA18:
    /* 2DBA18 003DBA18 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2DBA1C 003DBA1C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2DBA20 003DBA20 09F84000 */  jalr       $2
    /* 2DBA24 003DBA24 2D20A002 */   daddu     $4, $21, $0
    /* 2DBA28 003DBA28 59000010 */  b          .L003DBB90
    /* 2DBA2C 003DBA2C 2D100000 */   daddu     $2, $0, $0
  .L003DBA30:
    /* 2DBA30 003DBA30 23008392 */  lbu        $3, 0x23($20)
    /* 2DBA34 003DBA34 10006230 */  andi       $2, $3, 0x10
    /* 2DBA38 003DBA38 A000A2AF */  sw         $2, 0xA0($29)
    /* 2DBA3C 003DBA3C 27104000 */  not        $2, $2
    /* 2DBA40 003DBA40 FF004230 */  andi       $2, $2, 0xFF
    /* 2DBA44 003DBA44 24106200 */  and        $2, $3, $2
    /* 2DBA48 003DBA48 85FF0010 */  b          .L003DB860
    /* 2DBA4C 003DBA4C 230082A2 */   sb        $2, 0x23($20)
  .L003DBA50:
    /* 2DBA50 003DBA50 4F000010 */  b          .L003DBB90
    /* 2DBA54 003DBA54 2D100000 */   daddu     $2, $0, $0
  .L003DBA58:
    /* 2DBA58 003DBA58 4D000010 */  b          .L003DBB90
    /* 2DBA5C 003DBA5C 2D100000 */   daddu     $2, $0, $0
  .L003DBA60:
    /* 2DBA60 003DBA60 4B000010 */  b          .L003DBB90
    /* 2DBA64 003DBA64 2D100000 */   daddu     $2, $0, $0
  .L003DBA68:
    /* 2DBA68 003DBA68 A000A293 */  lbu        $2, 0xA0($29)
    /* 2DBA6C 003DBA6C 2D184000 */  daddu      $3, $2, $0
    /* 2DBA70 003DBA70 23008292 */  lbu        $2, 0x23($20)
    /* 2DBA74 003DBA74 25104300 */  or         $2, $2, $3
    /* 2DBA78 003DBA78 9DFF0010 */  b          .L003DB8F0
    /* 2DBA7C 003DBA7C 230082A2 */   sb        $2, 0x23($20)
  .L003DBA80:
    /* 2DBA80 003DBA80 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2DBA84 003DBA84 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2DBA88 003DBA88 09F84000 */  jalr       $2
    /* 2DBA8C 003DBA8C 2D20A002 */   daddu     $4, $21, $0
    /* 2DBA90 003DBA90 B8BC0F0C */  jal        func_003ef2e0
    /* 2DBA94 003DBA94 2D208002 */   daddu     $4, $20, $0
    /* 2DBA98 003DBA98 2D804000 */  daddu      $16, $2, $0
    /* 2DBA9C 003DBA9C 31000012 */  beqz       $16, .L003DBB64
    /* 2DBAA0 003DBAA0 00000000 */   nop
    /* 2DBAA4 003DBAA4 2D200002 */  daddu      $4, $16, $0
    /* 2DBAA8 003DBAA8 1CBD0F0C */  jal        func_003ef470
    /* 2DBAAC 003DBAAC C000A527 */   addiu     $5, $29, 0xC0
    /* 2DBAB0 003DBAB0 2D200002 */  daddu      $4, $16, $0
    /* 2DBAB4 003DBAB4 44BD0F0C */  jal        func_003ef510
    /* 2DBAB8 003DBAB8 E000A527 */   addiu     $5, $29, 0xE0
    /* 2DBABC 003DBABC 0401A527 */  addiu      $5, $29, 0x104
    /* 2DBAC0 003DBAC0 5000048E */  lw         $4, 0x50($16)
    /* 2DBAC4 003DBAC4 0000A290 */  lbu        $2, 0x0($5)
    /* 2DBAC8 003DBAC8 00FF0324 */  addiu      $3, $0, -0x100
    /* 2DBACC 003DBACC 24188300 */  and        $3, $4, $3
    /* 2DBAD0 003DBAD0 25106200 */  or         $2, $3, $2
    /* 2DBAD4 003DBAD4 500002AE */  sw         $2, 0x50($16)
    /* 2DBAD8 003DBAD8 0000A28C */  lw         $2, 0x0($5)
    /* 2DBADC 003DBADC 000F4330 */  andi       $3, $2, 0xF00
    /* 2DBAE0 003DBAE0 00F04230 */  andi       $2, $2, 0xF000
    /* 2DBAE4 003DBAE4 021A0300 */  srl        $3, $3, 8
    /* 2DBAE8 003DBAE8 20006010 */  beqz       $3, .L003DBB6C
    /* 2DBAEC 003DBAEC 02130200 */   srl       $2, $2, 12
  .L003DBAF0:
    /* 2DBAF0 003DBAF0 23006010 */  beqz       $3, .L003DBB80
    /* 2DBAF4 003DBAF4 00000000 */   nop
  .L003DBAF8:
    /* 2DBAF8 003DBAF8 04006010 */  beqz       $3, .L003DBB0C
    /* 2DBAFC 003DBAFC 00000000 */   nop
    /* 2DBB00 003DBB00 02004014 */  bnez       $2, .L003DBB0C
    /* 2DBB04 003DBB04 00000000 */   nop
    /* 2DBB08 003DBB08 2D106000 */  daddu      $2, $3, $0
  .L003DBB0C:
    /* 2DBB0C 003DBB0C 5000078E */  lw         $7, 0x50($16)
    /* 2DBB10 003DBB10 001A0300 */  sll        $3, $3, 8
    /* 2DBB14 003DBB14 FFF00624 */  addiu      $6, $0, -0xF01
    /* 2DBB18 003DBB18 000F6430 */  andi       $4, $3, 0xF00
    /* 2DBB1C 003DBB1C FFFF033C */  lui        $3, (0xFFFF0FFF >> 16)
    /* 2DBB20 003DBB20 00130200 */  sll        $2, $2, 12
    /* 2DBB24 003DBB24 FF0F6334 */  ori        $3, $3, (0xFFFF0FFF & 0xFFFF)
    /* 2DBB28 003DBB28 00F04230 */  andi       $2, $2, 0xF000
    /* 2DBB2C 003DBB2C 2430E600 */  and        $6, $7, $6
    /* 2DBB30 003DBB30 2520C400 */  or         $4, $6, $4
    /* 2DBB34 003DBB34 500004AE */  sw         $4, 0x50($16)
    /* 2DBB38 003DBB38 5000048E */  lw         $4, 0x50($16)
    /* 2DBB3C 003DBB3C 24188300 */  and        $3, $4, $3
    /* 2DBB40 003DBB40 25106200 */  or         $2, $3, $2
    /* 2DBB44 003DBB44 500002AE */  sw         $2, 0x50($16)
    /* 2DBB48 003DBB48 BC00A28F */  lw         $2, 0xBC($29)
    /* 2DBB4C 003DBB4C 0000448C */  lw         $4, 0x0($2)
    /* 2DBB50 003DBB50 6CBD0F0C */  jal        func_003ef5b0
    /* 2DBB54 003DBB54 2D280002 */   daddu     $5, $16, $0
    /* 2DBB58 003DBB58 BC00A28F */  lw         $2, 0xBC($29)
    /* 2DBB5C 003DBB5C 0C000010 */  b          .L003DBB90
    /* 2DBB60 003DBB60 0000428C */   lw        $2, 0x0($2)
  .L003DBB64:
    /* 2DBB64 003DBB64 0A000010 */  b          .L003DBB90
    /* 2DBB68 003DBB68 2D100000 */   daddu     $2, $0, $0
  .L003DBB6C:
    /* 2DBB6C 003DBB6C E0FF4014 */  bnez       $2, .L003DBAF0
    /* 2DBB70 003DBB70 00000000 */   nop
    /* 2DBB74 003DBB74 01000224 */  addiu      $2, $0, 0x1
    /* 2DBB78 003DBB78 E4FF0010 */  b          .L003DBB0C
    /* 2DBB7C 003DBB7C 2D184000 */   daddu     $3, $2, $0
  .L003DBB80:
    /* 2DBB80 003DBB80 DDFF4010 */  beqz       $2, .L003DBAF8
    /* 2DBB84 003DBB84 00000000 */   nop
    /* 2DBB88 003DBB88 E0FF0010 */  b          .L003DBB0C
    /* 2DBB8C 003DBB8C 2D184000 */   daddu     $3, $2, $0
  .L003DBB90:
    /* 2DBB90 003DBB90 9000BFDF */  ld         $31, 0x90($29)
    /* 2DBB94 003DBB94 8000BE7B */  lq         $30, 0x80($29)
    /* 2DBB98 003DBB98 7000B77B */  lq         $23, 0x70($29)
    /* 2DBB9C 003DBB9C 6000B67B */  lq         $22, 0x60($29)
    /* 2DBBA0 003DBBA0 5000B57B */  lq         $21, 0x50($29)
    /* 2DBBA4 003DBBA4 4000B47B */  lq         $20, 0x40($29)
    /* 2DBBA8 003DBBA8 3000B37B */  lq         $19, 0x30($29)
    /* 2DBBAC 003DBBAC 2000B27B */  lq         $18, 0x20($29)
    /* 2DBBB0 003DBBB0 1000B17B */  lq         $17, 0x10($29)
    /* 2DBBB4 003DBBB4 0000B07B */  lq         $16, 0x0($29)
    /* 2DBBB8 003DBBB8 0800E003 */  jr         $31
    /* 2DBBBC 003DBBBC 2001BD27 */   addiu     $29, $29, 0x120
.size func_003db630, 0x590
