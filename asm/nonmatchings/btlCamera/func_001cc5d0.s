.section .text
.set noat
.set noreorder
glabel func_001cc5d0
    /* CC5D0 001CC5D0 40FFBD27 */  addiu      $29, $29, -0xC0
    /* CC5D4 001CC5D4 3000BFFF */  sd         $31, 0x30($29)
    /* CC5D8 001CC5D8 2000B17F */  sq         $17, 0x20($29)
    /* CC5DC 001CC5DC 1000B07F */  sq         $16, 0x10($29)
    /* CC5E0 001CC5E0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CC5E4 001CC5E4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CC5E8 001CC5E8 2D888000 */  daddu      $17, $4, $0
    /* CC5EC 001CC5EC 2D80A000 */  daddu      $16, $5, $0
    /* CC5F0 001CC5F0 03000424 */  addiu      $4, $0, 0x3
    /* CC5F4 001CC5F4 01000524 */  addiu      $5, $0, 0x1
    /* CC5F8 001CC5F8 8800A627 */  addiu      $6, $29, 0x88
    /* CC5FC 001CC5FC BC00A727 */  addiu      $7, $29, 0xBC
    /* CC600 001CC600 B800A827 */  addiu      $8, $29, 0xB8
    /* CC604 001CC604 2D48A000 */  daddu      $9, $5, $0
    /* CC608 001CC608 1058060C */  jal        func_00196040
    /* CC60C 001CC60C 00000000 */   nop
    /* CC610 001CC610 06050046 */  mov.s      $f20, $f0
    /* CC614 001CC614 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CC618 001CC618 00088244 */  mtc1       $2, $f1
    /* CC61C 001CC61C B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CC620 001CC620 42080046 */  mul.s      $f1, $f1, $f0
    /* CC624 001CC624 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CC628 001CC628 02030146 */  mul.s      $f12, $f0, $f1
    /* CC62C 001CC62C 1A2E110C */  jal        func_0044b868
    /* CC630 001CC630 00000000 */   nop
    /* CC634 001CC634 00000000 */  nop
    /* CC638 001CC638 00000000 */  nop
    /* CC63C 001CC63C 43A50046 */  div.s      $f21, $f20, $f0
    /* CC640 001CC640 A800A0AF */  sw         $0, 0xA8($29)
    /* CC644 001CC644 BC00A0C7 */  lwc1       $f0, 0xBC($29)
    /* CC648 001CC648 AC00A0E7 */  swc1       $f0, 0xAC($29)
    /* CC64C 001CC64C 07A00046 */  neg.s      $f0, $f20
    /* CC650 001CC650 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* CC654 001CC654 0C000426 */  addiu      $4, $16, 0xC
    /* CC658 001CC658 A800A527 */  addiu      $5, $29, 0xA8
    /* CC65C 001CC65C 8800A627 */  addiu      $6, $29, 0x88
    /* CC660 001CC660 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CC664 001CC664 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CC668 001CC668 E0F5060C */  jal        func_001bd780
    /* CC66C 001CC66C 00000000 */   nop
    /* CC670 001CC670 A8002426 */  addiu      $4, $17, 0xA8
    /* CC674 001CC674 0C000526 */  addiu      $5, $16, 0xC
    /* CC678 001CC678 ACB0070C */  jal        func_001ec2b0
    /* CC67C 001CC67C 00000000 */   nop
    /* CC680 001CC680 DC8081C7 */  lwc1       $f1, -0x7F24($28)
    /* CC684 001CC684 36000146 */  c.le.s     $f0, $f1
    /* CC688 001CC688 87000145 */  bc1t       .L001CC8A8
    /* CC68C 001CC68C 00000000 */   nop
    /* CC690 001CC690 00000000 */  nop
    /* CC694 001CC694 00000000 */  nop
    /* CC698 001CC698 030D0046 */  div.s      $f20, $f1, $f0
    /* CC69C 001CC69C A8002426 */  addiu      $4, $17, 0xA8
    /* CC6A0 001CC6A0 0C000526 */  addiu      $5, $16, 0xC
    /* CC6A4 001CC6A4 4000A627 */  addiu      $6, $29, 0x40
    /* CC6A8 001CC6A8 1C730F0C */  jal        func_003dcc70
    /* CC6AC 001CC6AC 00000000 */   nop
    /* CC6B0 001CC6B0 00588044 */  mtc1       $0, $f11
    /* CC6B4 001CC6B4 00000000 */  nop
    /* CC6B8 001CC6B8 36A00B46 */  c.le.s     $f20, $f11
    /* CC6BC 001CC6BC 0B000045 */  bc1f       .L001CC6EC
    /* CC6C0 001CC6C0 00000000 */   nop
    /* CC6C4 001CC6C4 A80023C6 */  lwc1       $f3, 0xA8($17)
    /* CC6C8 001CC6C8 AC0022C6 */  lwc1       $f2, 0xAC($17)
    /* CC6CC 001CC6CC B00021C6 */  lwc1       $f1, 0xB0($17)
    /* CC6D0 001CC6D0 B40020C6 */  lwc1       $f0, 0xB4($17)
    /* CC6D4 001CC6D4 7000A3E7 */  swc1       $f3, 0x70($29)
    /* CC6D8 001CC6D8 7400A2E7 */  swc1       $f2, 0x74($29)
    /* CC6DC 001CC6DC 7800A1E7 */  swc1       $f1, 0x78($29)
    /* CC6E0 001CC6E0 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* CC6E4 001CC6E4 56000010 */  b          .L001CC840
    /* CC6E8 001CC6E8 00000000 */   nop
  .L001CC6EC:
    /* CC6EC 001CC6EC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* CC6F0 001CC6F0 00008244 */  mtc1       $2, $f0
    /* CC6F4 001CC6F4 00000000 */  nop
    /* CC6F8 001CC6F8 36001446 */  c.le.s     $f0, $f20
    /* CC6FC 001CC6FC 0B000045 */  bc1f       .L001CC72C
    /* CC700 001CC700 00000000 */   nop
    /* CC704 001CC704 0C0003C6 */  lwc1       $f3, 0xC($16)
    /* CC708 001CC708 100002C6 */  lwc1       $f2, 0x10($16)
    /* CC70C 001CC70C 140001C6 */  lwc1       $f1, 0x14($16)
    /* CC710 001CC710 180000C6 */  lwc1       $f0, 0x18($16)
    /* CC714 001CC714 7000A3E7 */  swc1       $f3, 0x70($29)
    /* CC718 001CC718 7400A2E7 */  swc1       $f2, 0x74($29)
    /* CC71C 001CC71C 7800A1E7 */  swc1       $f1, 0x78($29)
    /* CC720 001CC720 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* CC724 001CC724 46000010 */  b          .L001CC840
    /* CC728 001CC728 00000000 */   nop
  .L001CC72C:
    /* CC72C 001CC72C 01001446 */  sub.s      $f0, $f0, $f20
    /* CC730 001CC730 6400A28F */  lw         $2, 0x64($29)
    /* CC734 001CC734 26004014 */  bnez       $2, .L001CC7D0
    /* CC738 001CC738 00000000 */   nop
    /* CC73C 001CC73C 6000AAC7 */  lwc1       $f10, 0x60($29)
    /* CC740 001CC740 02010A46 */  mul.s      $f4, $f0, $f10
    /* CC744 001CC744 C2200446 */  mul.s      $f3, $f4, $f4
    /* CC748 001CC748 808189C7 */  lwc1       $f9, -0x7E80($28)
    /* CC74C 001CC74C 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* CC750 001CC750 18580846 */  adda.s     $f11, $f8
    /* CC754 001CC754 1C480346 */  madd.s     $f0, $f9, $f3
    /* CC758 001CC758 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* CC75C 001CC75C 18580746 */  adda.s     $f11, $f7
    /* CC760 001CC760 1C180046 */  madd.s     $f0, $f3, $f0
    /* CC764 001CC764 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* CC768 001CC768 18580646 */  adda.s     $f11, $f6
    /* CC76C 001CC76C 1C180046 */  madd.s     $f0, $f3, $f0
    /* CC770 001CC770 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* CC774 001CC774 18580546 */  adda.s     $f11, $f5
    /* CC778 001CC778 1C180046 */  madd.s     $f0, $f3, $f0
    /* CC77C 001CC77C 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* CC780 001CC780 18580246 */  adda.s     $f11, $f2
    /* CC784 001CC784 5C180046 */  madd.s     $f1, $f3, $f0
    /* CC788 001CC788 02180446 */  mul.s      $f0, $f3, $f4
    /* CC78C 001CC78C 18580446 */  adda.s     $f11, $f4
    /* CC790 001CC790 1C000146 */  madd.s     $f0, $f0, $f1
    /* CC794 001CC794 02A10A46 */  mul.s      $f4, $f20, $f10
    /* CC798 001CC798 C2200446 */  mul.s      $f3, $f4, $f4
    /* CC79C 001CC79C 18580846 */  adda.s     $f11, $f8
    /* CC7A0 001CC7A0 5C480346 */  madd.s     $f1, $f9, $f3
    /* CC7A4 001CC7A4 18580746 */  adda.s     $f11, $f7
    /* CC7A8 001CC7A8 5C180146 */  madd.s     $f1, $f3, $f1
    /* CC7AC 001CC7AC 18580646 */  adda.s     $f11, $f6
    /* CC7B0 001CC7B0 5C180146 */  madd.s     $f1, $f3, $f1
    /* CC7B4 001CC7B4 18580546 */  adda.s     $f11, $f5
    /* CC7B8 001CC7B8 5C180146 */  madd.s     $f1, $f3, $f1
    /* CC7BC 001CC7BC 18580246 */  adda.s     $f11, $f2
    /* CC7C0 001CC7C0 9C180146 */  madd.s     $f2, $f3, $f1
    /* CC7C4 001CC7C4 42180446 */  mul.s      $f1, $f3, $f4
    /* CC7C8 001CC7C8 18580446 */  adda.s     $f11, $f4
    /* CC7CC 001CC7CC 1C0D0246 */  madd.s     $f20, $f1, $f2
  .L001CC7D0:
    /* CC7D0 001CC7D0 4000A1C7 */  lwc1       $f1, 0x40($29)
    /* CC7D4 001CC7D4 42090046 */  mul.s      $f5, $f1, $f0
    /* CC7D8 001CC7D8 7000A5E7 */  swc1       $f5, 0x70($29)
    /* CC7DC 001CC7DC 4400A1C7 */  lwc1       $f1, 0x44($29)
    /* CC7E0 001CC7E0 02090046 */  mul.s      $f4, $f1, $f0
    /* CC7E4 001CC7E4 7400A4E7 */  swc1       $f4, 0x74($29)
    /* CC7E8 001CC7E8 4800A1C7 */  lwc1       $f1, 0x48($29)
    /* CC7EC 001CC7EC C2080046 */  mul.s      $f3, $f1, $f0
    /* CC7F0 001CC7F0 7800A3E7 */  swc1       $f3, 0x78($29)
    /* CC7F4 001CC7F4 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* CC7F8 001CC7F8 00108044 */  mtc1       $0, $f2
    /* CC7FC 001CC7FC 00000000 */  nop
    /* CC800 001CC800 18100546 */  adda.s     $f2, $f5
    /* CC804 001CC804 5C081446 */  madd.s     $f1, $f1, $f20
    /* CC808 001CC808 7000A1E7 */  swc1       $f1, 0x70($29)
    /* CC80C 001CC80C 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* CC810 001CC810 18100446 */  adda.s     $f2, $f4
    /* CC814 001CC814 5C081446 */  madd.s     $f1, $f1, $f20
    /* CC818 001CC818 7400A1E7 */  swc1       $f1, 0x74($29)
    /* CC81C 001CC81C 5800A1C7 */  lwc1       $f1, 0x58($29)
    /* CC820 001CC820 18100346 */  adda.s     $f2, $f3
    /* CC824 001CC824 5C081446 */  madd.s     $f1, $f1, $f20
    /* CC828 001CC828 7800A1E7 */  swc1       $f1, 0x78($29)
    /* CC82C 001CC82C 4C00A2C7 */  lwc1       $f2, 0x4C($29)
    /* CC830 001CC830 5C00A1C7 */  lwc1       $f1, 0x5C($29)
    /* CC834 001CC834 1A081446 */  mula.s     $f1, $f20
    /* CC838 001CC838 1C100046 */  madd.s     $f0, $f2, $f0
    /* CC83C 001CC83C 7C00A0E7 */  swc1       $f0, 0x7C($29)
  .L001CC840:
    /* CC840 001CC840 9800A427 */  addiu      $4, $29, 0x98
    /* CC844 001CC844 6100053C */  lui        $5, %hi(D_0060A100)
    /* CC848 001CC848 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CC84C 001CC84C 01000624 */  addiu      $6, $0, 0x1
    /* CC850 001CC850 7000A727 */  addiu      $7, $29, 0x70
    /* CC854 001CC854 D0720F0C */  jal        func_003dcb40
    /* CC858 001CC858 00000000 */   nop
    /* CC85C 001CC85C 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* CC860 001CC860 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CC864 001CC864 00080046 */  add.s      $f0, $f1, $f0
    /* CC868 001CC868 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* CC86C 001CC86C 8C00A1C7 */  lwc1       $f1, 0x8C($29)
    /* CC870 001CC870 9C00A0C7 */  lwc1       $f0, 0x9C($29)
    /* CC874 001CC874 00080046 */  add.s      $f0, $f1, $f0
    /* CC878 001CC878 AC00A0E7 */  swc1       $f0, 0xAC($29)
    /* CC87C 001CC87C 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* CC880 001CC880 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CC884 001CC884 00080046 */  add.s      $f0, $f1, $f0
    /* CC888 001CC888 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* CC88C 001CC88C 0C000426 */  addiu      $4, $16, 0xC
    /* CC890 001CC890 A800A527 */  addiu      $5, $29, 0xA8
    /* CC894 001CC894 8800A627 */  addiu      $6, $29, 0x88
    /* CC898 001CC898 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CC89C 001CC89C E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CC8A0 001CC8A0 E0F5060C */  jal        func_001bd780
    /* CC8A4 001CC8A4 00000000 */   nop
  .L001CC8A8:
    /* CC8A8 001CC8A8 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* CC8AC 001CC8AC 00008244 */  mtc1       $2, $f0
    /* CC8B0 001CC8B0 00000000 */  nop
    /* CC8B4 001CC8B4 34A80046 */  c.lt.s     $f21, $f0
    /* CC8B8 001CC8B8 02000045 */  bc1f       .L001CC8C4
    /* CC8BC 001CC8BC 00000000 */   nop
    /* CC8C0 001CC8C0 46050046 */  mov.s      $f21, $f0
  .L001CC8C4:
    /* CC8C4 001CC8C4 9800A427 */  addiu      $4, $29, 0x98
    /* CC8C8 001CC8C8 6100053C */  lui        $5, %hi(D_0060A100)
    /* CC8CC 001CC8CC 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CC8D0 001CC8D0 01000624 */  addiu      $6, $0, 0x1
    /* CC8D4 001CC8D4 0C000726 */  addiu      $7, $16, 0xC
    /* CC8D8 001CC8D8 D0720F0C */  jal        func_003dcb40
    /* CC8DC 001CC8DC 00000000 */   nop
    /* CC8E0 001CC8E0 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CC8E4 001CC8E4 02001546 */  mul.s      $f0, $f0, $f21
    /* CC8E8 001CC8E8 9800A0E7 */  swc1       $f0, 0x98($29)
    /* CC8EC 001CC8EC 9C00A0C7 */  lwc1       $f0, 0x9C($29)
    /* CC8F0 001CC8F0 02001546 */  mul.s      $f0, $f0, $f21
    /* CC8F4 001CC8F4 9C00A0E7 */  swc1       $f0, 0x9C($29)
    /* CC8F8 001CC8F8 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CC8FC 001CC8FC 02001546 */  mul.s      $f0, $f0, $f21
    /* CC900 001CC900 A000A0E7 */  swc1       $f0, 0xA0($29)
    /* CC904 001CC904 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CC908 001CC908 00088244 */  mtc1       $2, $f1
    /* CC90C 001CC90C B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CC910 001CC910 42080046 */  mul.s      $f1, $f1, $f0
    /* CC914 001CC914 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CC918 001CC918 02030146 */  mul.s      $f12, $f0, $f1
    /* CC91C 001CC91C 1A2E110C */  jal        func_0044b868
    /* CC920 001CC920 00000000 */   nop
    /* CC924 001CC924 42A80046 */  mul.s      $f1, $f21, $f0
    /* CC928 001CC928 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* CC92C 001CC92C 00008244 */  mtc1       $2, $f0
    /* CC930 001CC930 00000000 */  nop
    /* CC934 001CC934 020D0046 */  mul.s      $f20, $f1, $f0
    /* CC938 001CC938 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CC93C 001CC93C 8000A0E7 */  swc1       $f0, 0x80($29)
    /* CC940 001CC940 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CC944 001CC944 8400A0E7 */  swc1       $f0, 0x84($29)
    /* CC948 001CC948 8000A427 */  addiu      $4, $29, 0x80
    /* CC94C 001CC94C 2D288000 */  daddu      $5, $4, $0
    /* CC950 001CC950 78900F0C */  jal        func_003e41e0
    /* CC954 001CC954 00000000 */   nop
    /* CC958 001CC958 8400A1C7 */  lwc1       $f1, 0x84($29)
    /* CC95C 001CC95C 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CC960 001CC960 00108044 */  mtc1       $0, $f2
    /* CC964 001CC964 00000000 */  nop
    /* CC968 001CC968 18100046 */  adda.s     $f2, $f0
    /* CC96C 001CC96C DC081446 */  madd.s     $f3, $f1, $f20
    /* CC970 001CC970 8800A3E7 */  swc1       $f3, 0x88($29)
    /* CC974 001CC974 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* CC978 001CC978 9000A0C7 */  lwc1       $f0, 0x90($29)
    /* CC97C 001CC97C 18100046 */  adda.s     $f2, $f0
    /* CC980 001CC980 1D081446 */  msub.s     $f0, $f1, $f20
    /* CC984 001CC984 9000A0E7 */  swc1       $f0, 0x90($29)
    /* CC988 001CC988 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CC98C 001CC98C 00180046 */  add.s      $f0, $f3, $f0
    /* CC990 001CC990 000000E6 */  swc1       $f0, 0x0($16)
    /* CC994 001CC994 8C00A1C7 */  lwc1       $f1, 0x8C($29)
    /* CC998 001CC998 9C00A0C7 */  lwc1       $f0, 0x9C($29)
    /* CC99C 001CC99C 00080046 */  add.s      $f0, $f1, $f0
    /* CC9A0 001CC9A0 040000E6 */  swc1       $f0, 0x4($16)
    /* CC9A4 001CC9A4 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* CC9A8 001CC9A8 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CC9AC 001CC9AC 00080046 */  add.s      $f0, $f1, $f0
    /* CC9B0 001CC9B0 080000E6 */  swc1       $f0, 0x8($16)
    /* CC9B4 001CC9B4 3000BFDF */  ld         $31, 0x30($29)
    /* CC9B8 001CC9B8 2000B17B */  lq         $17, 0x20($29)
    /* CC9BC 001CC9BC 1000B07B */  lq         $16, 0x10($29)
    /* CC9C0 001CC9C0 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CC9C4 001CC9C4 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CC9C8 001CC9C8 C000BD27 */  addiu      $29, $29, 0xC0
    /* CC9CC 001CC9CC 0800E003 */  jr         $31
    /* CC9D0 001CC9D0 00000000 */   nop
    /* CC9D4 001CC9D4 00000000 */  nop
    /* CC9D8 001CC9D8 00000000 */  nop
    /* CC9DC 001CC9DC 00000000 */  nop
.size func_001cc5d0, 0x410
