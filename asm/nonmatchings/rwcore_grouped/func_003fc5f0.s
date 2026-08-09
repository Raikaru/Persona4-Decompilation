.section .text
.set noat
.set noreorder
glabel func_003fc5f0
    /* 2FC5F0 003FC5F0 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 2FC5F4 003FC5F4 8000BFFF */  sd         $31, 0x80($29)
    /* 2FC5F8 003FC5F8 7000B77F */  sq         $23, 0x70($29)
    /* 2FC5FC 003FC5FC 6000B67F */  sq         $22, 0x60($29)
    /* 2FC600 003FC600 2DB88000 */  daddu      $23, $4, $0
    /* 2FC604 003FC604 5000B57F */  sq         $21, 0x50($29)
    /* 2FC608 003FC608 01000424 */  addiu      $4, $0, 0x1
    /* 2FC60C 003FC60C 4000B47F */  sq         $20, 0x40($29)
    /* 2FC610 003FC610 3000B37F */  sq         $19, 0x30($29)
    /* 2FC614 003FC614 2000B27F */  sq         $18, 0x20($29)
    /* 2FC618 003FC618 2D98C000 */  daddu      $19, $6, $0
    /* 2FC61C 003FC61C 1000B17F */  sq         $17, 0x10($29)
    /* 2FC620 003FC620 00FF6332 */  andi       $3, $19, 0xFF00
    /* 2FC624 003FC624 0000B07F */  sq         $16, 0x0($29)
    /* 2FC628 003FC628 031A0300 */  sra        $3, $3, 8
    /* 2FC62C 003FC62C 2000A290 */  lbu        $2, 0x20($5)
    /* 2FC630 003FC630 FF007230 */  andi       $18, $3, 0xFF
    /* 2FC634 003FC634 07004330 */  andi       $3, $2, 0x7
    /* 2FC638 003FC638 93006410 */  beq        $3, $4, .L003FC888
    /* 2FC63C 003FC63C 2D80A000 */   daddu     $16, $5, $0
    /* 2FC640 003FC640 05000224 */  addiu      $2, $0, 0x5
    /* 2FC644 003FC644 47006210 */  beq        $3, $2, .L003FC764
    /* 2FC648 003FC648 00000000 */   nop
    /* 2FC64C 003FC64C 02000224 */  addiu      $2, $0, 0x2
    /* 2FC650 003FC650 03006210 */  beq        $3, $2, .L003FC660
    /* 2FC654 003FC654 00000000 */   nop
    /* 2FC658 003FC658 95000010 */  b          .L003FC8B0
    /* 2FC65C 003FC65C 38B9828F */   lw        $2, -0x46C8($28)
  .L003FC660:
    /* 2FC660 003FC660 F9006232 */  andi       $2, $19, 0xF9
    /* 2FC664 003FC664 A1014014 */  bnez       $2, .L003FCCEC
    /* 2FC668 003FC668 00000000 */   nop
    /* 2FC66C 003FC66C FF004232 */  andi       $2, $18, 0xFF
    /* 2FC670 003FC670 A7014014 */  bnez       $2, .L003FCD10
    /* 2FC674 003FC674 00000000 */   nop
    /* 2FC678 003FC678 0400028E */  lw         $2, 0x4($16)
    /* 2FC67C 003FC67C AD014010 */  beqz       $2, .L003FCD34
    /* 2FC680 003FC680 00000000 */   nop
    /* 2FC684 003FC684 0F004230 */  andi       $2, $2, 0xF
    /* 2FC688 003FC688 AA014014 */  bnez       $2, .L003FCD34
    /* 2FC68C 003FC68C 00000000 */   nop
    /* 2FC690 003FC690 B4CC0F0C */  jal        func_003f32d0
    /* 2FC694 003FC694 00000000 */   nop
    /* 2FC698 003FC698 B4CC0F0C */  jal        func_003f32d0
    /* 2FC69C 003FC69C 00000000 */   nop
    /* 2FC6A0 003FC6A0 2D200000 */  daddu      $4, $0, $0
    /* 2FC6A4 003FC6A4 0C60100C */  jal        func_00418030
    /* 2FC6A8 003FC6A8 2D280000 */   daddu     $5, $0, $0
    /* 2FC6AC 003FC6AC 0400048E */  lw         $4, 0x4($16)
    /* 2FC6B0 003FC6B0 0C00038E */  lw         $3, 0xC($16)
    /* 2FC6B4 003FC6B4 1400028E */  lw         $2, 0x14($16)
    /* 2FC6B8 003FC6B8 1000148E */  lw         $20, 0x10($16)
    /* 2FC6BC 003FC6BC 1E001286 */  lh         $18, 0x1E($16)
    /* 2FC6C0 003FC6C0 2D888000 */  daddu      $17, $4, $0
    /* 2FC6C4 003FC6C4 18186200 */  mult       $3, $3, $2
    /* 2FC6C8 003FC6C8 0F00023C */  lui        $2, (0xFFFF0 >> 16)
    /* 2FC6CC 003FC6CC C3180300 */  sra        $3, $3, 3
    /* 2FC6D0 003FC6D0 F0FF4234 */  ori        $2, $2, (0xFFFF0 & 0xFFFF)
    /* 2FC6D4 003FC6D4 1A004300 */  div        $0, $2, $3
    /* 2FC6D8 003FC6D8 12980000 */  mflo       $19
    /* 2FC6DC 003FC6DC 2A087402 */  slt        $1, $19, $20
    /* 2FC6E0 003FC6E0 0E002010 */  beqz       $1, .L003FC71C
    /* 2FC6E4 003FC6E4 00000000 */   nop
    /* 2FC6E8 003FC6E8 18106302 */  mult       $2, $19, $3
    /* 2FC6EC 003FC6EC 0F004230 */  andi       $2, $2, 0xF
    /* 2FC6F0 003FC6F0 92014010 */  beqz       $2, .L003FCD3C
    /* 2FC6F4 003FC6F4 00000000 */   nop
  .L003FC6F8:
    /* 2FC6F8 003FC6F8 FFFF7326 */  addiu      $19, $19, -0x1
    /* 2FC6FC 003FC6FC 18106302 */  mult       $2, $19, $3
    /* 2FC700 003FC700 0F004230 */  andi       $2, $2, 0xF
    /* 2FC704 003FC704 00000000 */  nop
    /* 2FC708 003FC708 00000000 */  nop
    /* 2FC70C 003FC70C FAFF4014 */  bnez       $2, .L003FC6F8
    /* 2FC710 003FC710 00000000 */   nop
    /* 2FC714 003FC714 89010010 */  b          .L003FCD3C
    /* 2FC718 003FC718 00000000 */   nop
  .L003FC71C:
    /* 2FC71C 003FC71C 2D988002 */  daddu      $19, $20, $0
  .L003FC720:
    /* 2FC720 003FC720 18108302 */  mult       $2, $20, $3
    /* 2FC724 003FC724 3688100C */  jal        func_004220d8
    /* 2FC728 003FC728 21288200 */   addu      $5, $4, $2
    /* 2FC72C 003FC72C 87018016 */  bnez       $20, .L003FCD4C
    /* 2FC730 003FC730 00000000 */   nop
    /* 2FC734 003FC734 0C00038E */  lw         $3, 0xC($16)
  .L003FC738:
    /* 2FC738 003FC738 1400028E */  lw         $2, 0x14($16)
    /* 2FC73C 003FC73C 18186200 */  mult       $3, $3, $2
    /* 2FC740 003FC740 C3180300 */  sra        $3, $3, 3
    /* 2FC744 003FC744 01000224 */  addiu      $2, $0, 0x1
    /* 2FC748 003FC748 180003AE */  sw         $3, 0x18($16)
    /* 2FC74C 003FC74C 0400038E */  lw         $3, 0x4($16)
    /* 2FC750 003FC750 0000E3AE */  sw         $3, 0x0($23)
    /* 2FC754 003FC754 22000392 */  lbu        $3, 0x22($16)
    /* 2FC758 003FC758 02006334 */  ori        $3, $3, 0x2
    /* 2FC75C 003FC75C A8020010 */  b          .L003FD200
    /* 2FC760 003FC760 220003A2 */   sb        $3, 0x22($16)
  .L003FC764:
    /* 2FC764 003FC764 21000292 */  lbu        $2, 0x21($16)
    /* 2FC768 003FC768 38B9838F */  lw         $3, -0x46C8($28)
    /* 2FC76C 003FC76C 80004230 */  andi       $2, $2, 0x80
    /* 2FC770 003FC770 CC014014 */  bnez       $2, .L003FCEA4
    /* 2FC774 003FC774 21880302 */   addu      $17, $16, $3
    /* 2FC778 003FC778 F9006232 */  andi       $2, $19, 0xF9
    /* 2FC77C 003FC77C CB014014 */  bnez       $2, .L003FCEAC
    /* 2FC780 003FC780 00000000 */   nop
    /* 2FC784 003FC784 5800228E */  lw         $2, 0x58($17)
    /* 2FC788 003FC788 D1014010 */  beqz       $2, .L003FCED0
    /* 2FC78C 003FC78C 00000000 */   nop
    /* 2FC790 003FC790 FF004232 */  andi       $2, $18, 0xFF
    /* 2FC794 003FC794 D7014014 */  bnez       $2, .L003FCEF4
    /* 2FC798 003FC798 00000000 */   nop
    /* 2FC79C 003FC79C 0400028E */  lw         $2, 0x4($16)
    /* 2FC7A0 003FC7A0 DD014010 */  beqz       $2, .L003FCF18
    /* 2FC7A4 003FC7A4 00000000 */   nop
    /* 2FC7A8 003FC7A8 0F004230 */  andi       $2, $2, 0xF
    /* 2FC7AC 003FC7AC DA014014 */  bnez       $2, .L003FCF18
    /* 2FC7B0 003FC7B0 00000000 */   nop
    /* 2FC7B4 003FC7B4 B4CC0F0C */  jal        func_003f32d0
    /* 2FC7B8 003FC7B8 00000000 */   nop
    /* 2FC7BC 003FC7BC B4CC0F0C */  jal        func_003f32d0
    /* 2FC7C0 003FC7C0 00000000 */   nop
    /* 2FC7C4 003FC7C4 2D200000 */  daddu      $4, $0, $0
    /* 2FC7C8 003FC7C8 0C60100C */  jal        func_00418030
    /* 2FC7CC 003FC7CC 2D280000 */   daddu     $5, $0, $0
    /* 2FC7D0 003FC7D0 0400048E */  lw         $4, 0x4($16)
    /* 2FC7D4 003FC7D4 0C00038E */  lw         $3, 0xC($16)
    /* 2FC7D8 003FC7D8 1400028E */  lw         $2, 0x14($16)
    /* 2FC7DC 003FC7DC 1000158E */  lw         $21, 0x10($16)
    /* 2FC7E0 003FC7E0 1E001386 */  lh         $19, 0x1E($16)
    /* 2FC7E4 003FC7E4 2D908000 */  daddu      $18, $4, $0
    /* 2FC7E8 003FC7E8 18186200 */  mult       $3, $3, $2
    /* 2FC7EC 003FC7EC 0F00023C */  lui        $2, (0xFFFF0 >> 16)
    /* 2FC7F0 003FC7F0 C3180300 */  sra        $3, $3, 3
    /* 2FC7F4 003FC7F4 F0FF4234 */  ori        $2, $2, (0xFFFF0 & 0xFFFF)
    /* 2FC7F8 003FC7F8 1A004300 */  div        $0, $2, $3
    /* 2FC7FC 003FC7FC 12A00000 */  mflo       $20
    /* 2FC800 003FC800 2A089502 */  slt        $1, $20, $21
    /* 2FC804 003FC804 0E002010 */  beqz       $1, .L003FC840
    /* 2FC808 003FC808 00000000 */   nop
    /* 2FC80C 003FC80C 18108302 */  mult       $2, $20, $3
    /* 2FC810 003FC810 0F004230 */  andi       $2, $2, 0xF
    /* 2FC814 003FC814 C2014010 */  beqz       $2, .L003FCF20
    /* 2FC818 003FC818 00000000 */   nop
  .L003FC81C:
    /* 2FC81C 003FC81C FFFF9426 */  addiu      $20, $20, -0x1
    /* 2FC820 003FC820 18108302 */  mult       $2, $20, $3
    /* 2FC824 003FC824 0F004230 */  andi       $2, $2, 0xF
    /* 2FC828 003FC828 00000000 */  nop
    /* 2FC82C 003FC82C 00000000 */  nop
    /* 2FC830 003FC830 FAFF4014 */  bnez       $2, .L003FC81C
    /* 2FC834 003FC834 00000000 */   nop
    /* 2FC838 003FC838 B9010010 */  b          .L003FCF20
    /* 2FC83C 003FC83C 00000000 */   nop
  .L003FC840:
    /* 2FC840 003FC840 2DA0A002 */  daddu      $20, $21, $0
  .L003FC844:
    /* 2FC844 003FC844 1810A302 */  mult       $2, $21, $3
    /* 2FC848 003FC848 3688100C */  jal        func_004220d8
    /* 2FC84C 003FC84C 21288200 */   addu      $5, $4, $2
    /* 2FC850 003FC850 B701A016 */  bnez       $21, .L003FCF30
    /* 2FC854 003FC854 00000000 */   nop
    /* 2FC858 003FC858 0C00038E */  lw         $3, 0xC($16)
  .L003FC85C:
    /* 2FC85C 003FC85C 1400028E */  lw         $2, 0x14($16)
    /* 2FC860 003FC860 18186200 */  mult       $3, $3, $2
    /* 2FC864 003FC864 C3180300 */  sra        $3, $3, 3
    /* 2FC868 003FC868 01000224 */  addiu      $2, $0, 0x1
    /* 2FC86C 003FC86C 180003AE */  sw         $3, 0x18($16)
    /* 2FC870 003FC870 0400038E */  lw         $3, 0x4($16)
    /* 2FC874 003FC874 0000E3AE */  sw         $3, 0x0($23)
    /* 2FC878 003FC878 22000392 */  lbu        $3, 0x22($16)
    /* 2FC87C 003FC87C 02006334 */  ori        $3, $3, 0x2
    /* 2FC880 003FC880 5F020010 */  b          .L003FD200
    /* 2FC884 003FC884 220003A2 */   sb        $3, 0x22($16)
  .L003FC888:
    /* 2FC888 003FC888 9800A4AF */  sw         $4, 0x98($29)
    /* 2FC88C 003FC88C 0080023C */  lui        $2, (0x8000000E >> 16)
    /* 2FC890 003FC890 647D0F0C */  jal        func_003df590
    /* 2FC894 003FC894 0E004434 */   ori       $4, $2, (0x8000000E & 0xFFFF)
    /* 2FC898 003FC898 9C00A2AF */  sw         $2, 0x9C($29)
    /* 2FC89C 003FC89C 347D0F0C */  jal        func_003df4d0
    /* 2FC8A0 003FC8A0 9800A427 */   addiu     $4, $29, 0x98
    /* 2FC8A4 003FC8A4 56020010 */  b          .L003FD200
    /* 2FC8A8 003FC8A8 2D100000 */   daddu     $2, $0, $0
    /* 2FC8AC 003FC8AC 38B9828F */  lw         $2, -0x46C8($28)
  .L003FC8B0:
    /* 2FC8B0 003FC8B0 FF005432 */  andi       $20, $18, 0xFF
    /* 2FC8B4 003FC8B4 21A80202 */  addu       $21, $16, $2
    /* 2FC8B8 003FC8B8 1600A292 */  lbu        $2, 0x16($21)
    /* 2FC8BC 003FC8BC 83100200 */  sra        $2, $2, 2
    /* 2FC8C0 003FC8C0 2A085400 */  slt        $1, $2, $20
    /* 2FC8C4 003FC8C4 ED012014 */  bnez       $1, .L003FD07C
    /* 2FC8C8 003FC8C8 00000000 */   nop
    /* 2FC8CC 003FC8CC 01007132 */  andi       $17, $19, 0x1
    /* 2FC8D0 003FC8D0 F3012016 */  bnez       $17, .L003FD0A0
    /* 2FC8D4 003FC8D4 00000000 */   nop
    /* 2FC8D8 003FC8D8 3600A592 */  lbu        $5, 0x36($21)
  .L003FC8DC:
    /* 2FC8DC 003FC8DC 0100A230 */  andi       $2, $5, 0x1
    /* 2FC8E0 003FC8E0 F3014014 */  bnez       $2, .L003FD0B0
    /* 2FC8E4 003FC8E4 00000000 */   nop
    /* 2FC8E8 003FC8E8 0000028E */  lw         $2, 0x0($16)
    /* 2FC8EC 003FC8EC 2A081400 */  slt        $1, $0, $20
    /* 2FC8F0 003FC8F0 0C00458C */  lw         $5, 0xC($2)
    /* 2FC8F4 003FC8F4 1000448C */  lw         $4, 0x10($2)
    /* 2FC8F8 003FC8F8 CF002010 */  beqz       $1, .L003FCC38
    /* 2FC8FC 003FC8FC 2D300000 */   daddu     $6, $0, $0
    /* 2FC900 003FC900 0900812E */  sltiu      $1, $20, 0x9
    /* 2FC904 003FC904 AE002014 */  bnez       $1, .L003FCBC0
    /* 2FC908 003FC908 F8FF8326 */   addiu     $3, $20, -0x8
    /* 2FC90C 003FC90C F0FF0224 */  addiu      $2, $0, -0x10
  .L003FC910:
    /* 2FC910 003FC910 1400078E */  lw         $7, 0x14($16)
    /* 2FC914 003FC914 1838E500 */  mult       $7, $7, $5
    /* 2FC918 003FC918 C3380700 */  sra        $7, $7, 3
    /* 2FC91C 003FC91C 180007AE */  sw         $7, 0x18($16)
    /* 2FC920 003FC920 0400078E */  lw         $7, 0x4($16)
    /* 2FC924 003FC924 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FC928 003FC928 2438E200 */  and        $7, $7, $2
    /* 2FC92C 003FC92C 040007AE */  sw         $7, 0x4($16)
    /* 2FC930 003FC930 1800078E */  lw         $7, 0x18($16)
    /* 2FC934 003FC934 1848E470 */  mult1      $9, $7, $4
    /* 2FC938 003FC938 43400500 */  sra        $8, $5, 1
    /* 2FC93C 003FC93C 0400078E */  lw         $7, 0x4($16)
    /* 2FC940 003FC940 2138E900 */  addu       $7, $7, $9
    /* 2FC944 003FC944 040007AE */  sw         $7, 0x4($16)
    /* 2FC948 003FC948 0C00078E */  lw         $7, 0xC($16)
    /* 2FC94C 003FC94C 43380700 */  sra        $7, $7, 1
    /* 2FC950 003FC950 0C0007AE */  sw         $7, 0xC($16)
    /* 2FC954 003FC954 1000078E */  lw         $7, 0x10($16)
    /* 2FC958 003FC958 43380700 */  sra        $7, $7, 1
    /* 2FC95C 003FC95C 100007AE */  sw         $7, 0x10($16)
    /* 2FC960 003FC960 1400078E */  lw         $7, 0x14($16)
    /* 2FC964 003FC964 1838E800 */  mult       $7, $7, $8
    /* 2FC968 003FC968 C3380700 */  sra        $7, $7, 3
    /* 2FC96C 003FC96C 43400400 */  sra        $8, $4, 1
    /* 2FC970 003FC970 180007AE */  sw         $7, 0x18($16)
    /* 2FC974 003FC974 0400078E */  lw         $7, 0x4($16)
    /* 2FC978 003FC978 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FC97C 003FC97C 2438E200 */  and        $7, $7, $2
    /* 2FC980 003FC980 040007AE */  sw         $7, 0x4($16)
    /* 2FC984 003FC984 1800078E */  lw         $7, 0x18($16)
    /* 2FC988 003FC988 1848E870 */  mult1      $9, $7, $8
    /* 2FC98C 003FC98C 0400078E */  lw         $7, 0x4($16)
    /* 2FC990 003FC990 83400500 */  sra        $8, $5, 2
    /* 2FC994 003FC994 2138E900 */  addu       $7, $7, $9
    /* 2FC998 003FC998 040007AE */  sw         $7, 0x4($16)
    /* 2FC99C 003FC99C 0C00078E */  lw         $7, 0xC($16)
    /* 2FC9A0 003FC9A0 43380700 */  sra        $7, $7, 1
    /* 2FC9A4 003FC9A4 0C0007AE */  sw         $7, 0xC($16)
    /* 2FC9A8 003FC9A8 1000078E */  lw         $7, 0x10($16)
    /* 2FC9AC 003FC9AC 43380700 */  sra        $7, $7, 1
    /* 2FC9B0 003FC9B0 100007AE */  sw         $7, 0x10($16)
    /* 2FC9B4 003FC9B4 1400078E */  lw         $7, 0x14($16)
    /* 2FC9B8 003FC9B8 1838E800 */  mult       $7, $7, $8
    /* 2FC9BC 003FC9BC C3380700 */  sra        $7, $7, 3
    /* 2FC9C0 003FC9C0 83400400 */  sra        $8, $4, 2
    /* 2FC9C4 003FC9C4 180007AE */  sw         $7, 0x18($16)
    /* 2FC9C8 003FC9C8 0400078E */  lw         $7, 0x4($16)
    /* 2FC9CC 003FC9CC 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FC9D0 003FC9D0 2438E200 */  and        $7, $7, $2
    /* 2FC9D4 003FC9D4 040007AE */  sw         $7, 0x4($16)
    /* 2FC9D8 003FC9D8 1800078E */  lw         $7, 0x18($16)
    /* 2FC9DC 003FC9DC 1848E870 */  mult1      $9, $7, $8
    /* 2FC9E0 003FC9E0 0400078E */  lw         $7, 0x4($16)
    /* 2FC9E4 003FC9E4 C3400500 */  sra        $8, $5, 3
    /* 2FC9E8 003FC9E8 2138E900 */  addu       $7, $7, $9
    /* 2FC9EC 003FC9EC 040007AE */  sw         $7, 0x4($16)
    /* 2FC9F0 003FC9F0 0C00078E */  lw         $7, 0xC($16)
    /* 2FC9F4 003FC9F4 43380700 */  sra        $7, $7, 1
    /* 2FC9F8 003FC9F8 0C0007AE */  sw         $7, 0xC($16)
    /* 2FC9FC 003FC9FC 1000078E */  lw         $7, 0x10($16)
    /* 2FCA00 003FCA00 43380700 */  sra        $7, $7, 1
    /* 2FCA04 003FCA04 100007AE */  sw         $7, 0x10($16)
    /* 2FCA08 003FCA08 1400078E */  lw         $7, 0x14($16)
    /* 2FCA0C 003FCA0C 1838E800 */  mult       $7, $7, $8
    /* 2FCA10 003FCA10 C3380700 */  sra        $7, $7, 3
    /* 2FCA14 003FCA14 C3400400 */  sra        $8, $4, 3
    /* 2FCA18 003FCA18 180007AE */  sw         $7, 0x18($16)
    /* 2FCA1C 003FCA1C 0400078E */  lw         $7, 0x4($16)
    /* 2FCA20 003FCA20 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FCA24 003FCA24 2438E200 */  and        $7, $7, $2
    /* 2FCA28 003FCA28 040007AE */  sw         $7, 0x4($16)
    /* 2FCA2C 003FCA2C 1800078E */  lw         $7, 0x18($16)
    /* 2FCA30 003FCA30 1848E870 */  mult1      $9, $7, $8
    /* 2FCA34 003FCA34 0400078E */  lw         $7, 0x4($16)
    /* 2FCA38 003FCA38 03410500 */  sra        $8, $5, 4
    /* 2FCA3C 003FCA3C 2138E900 */  addu       $7, $7, $9
    /* 2FCA40 003FCA40 040007AE */  sw         $7, 0x4($16)
    /* 2FCA44 003FCA44 0C00078E */  lw         $7, 0xC($16)
    /* 2FCA48 003FCA48 43380700 */  sra        $7, $7, 1
    /* 2FCA4C 003FCA4C 0C0007AE */  sw         $7, 0xC($16)
    /* 2FCA50 003FCA50 1000078E */  lw         $7, 0x10($16)
    /* 2FCA54 003FCA54 43380700 */  sra        $7, $7, 1
    /* 2FCA58 003FCA58 100007AE */  sw         $7, 0x10($16)
    /* 2FCA5C 003FCA5C 1400078E */  lw         $7, 0x14($16)
    /* 2FCA60 003FCA60 1838E800 */  mult       $7, $7, $8
    /* 2FCA64 003FCA64 C3380700 */  sra        $7, $7, 3
    /* 2FCA68 003FCA68 03410400 */  sra        $8, $4, 4
    /* 2FCA6C 003FCA6C 180007AE */  sw         $7, 0x18($16)
    /* 2FCA70 003FCA70 0400078E */  lw         $7, 0x4($16)
    /* 2FCA74 003FCA74 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FCA78 003FCA78 2438E200 */  and        $7, $7, $2
    /* 2FCA7C 003FCA7C 040007AE */  sw         $7, 0x4($16)
    /* 2FCA80 003FCA80 1800078E */  lw         $7, 0x18($16)
    /* 2FCA84 003FCA84 1848E870 */  mult1      $9, $7, $8
    /* 2FCA88 003FCA88 0400078E */  lw         $7, 0x4($16)
    /* 2FCA8C 003FCA8C 43410500 */  sra        $8, $5, 5
    /* 2FCA90 003FCA90 2138E900 */  addu       $7, $7, $9
    /* 2FCA94 003FCA94 040007AE */  sw         $7, 0x4($16)
    /* 2FCA98 003FCA98 0C00078E */  lw         $7, 0xC($16)
    /* 2FCA9C 003FCA9C 43380700 */  sra        $7, $7, 1
    /* 2FCAA0 003FCAA0 0C0007AE */  sw         $7, 0xC($16)
    /* 2FCAA4 003FCAA4 1000078E */  lw         $7, 0x10($16)
    /* 2FCAA8 003FCAA8 43380700 */  sra        $7, $7, 1
    /* 2FCAAC 003FCAAC 100007AE */  sw         $7, 0x10($16)
    /* 2FCAB0 003FCAB0 1400078E */  lw         $7, 0x14($16)
    /* 2FCAB4 003FCAB4 1838E800 */  mult       $7, $7, $8
    /* 2FCAB8 003FCAB8 C3380700 */  sra        $7, $7, 3
    /* 2FCABC 003FCABC 43410400 */  sra        $8, $4, 5
    /* 2FCAC0 003FCAC0 180007AE */  sw         $7, 0x18($16)
    /* 2FCAC4 003FCAC4 0400078E */  lw         $7, 0x4($16)
    /* 2FCAC8 003FCAC8 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FCACC 003FCACC 2438E200 */  and        $7, $7, $2
    /* 2FCAD0 003FCAD0 040007AE */  sw         $7, 0x4($16)
    /* 2FCAD4 003FCAD4 1800078E */  lw         $7, 0x18($16)
    /* 2FCAD8 003FCAD8 1848E870 */  mult1      $9, $7, $8
    /* 2FCADC 003FCADC 0400078E */  lw         $7, 0x4($16)
    /* 2FCAE0 003FCAE0 83410500 */  sra        $8, $5, 6
    /* 2FCAE4 003FCAE4 2138E900 */  addu       $7, $7, $9
    /* 2FCAE8 003FCAE8 040007AE */  sw         $7, 0x4($16)
    /* 2FCAEC 003FCAEC 0C00078E */  lw         $7, 0xC($16)
    /* 2FCAF0 003FCAF0 43380700 */  sra        $7, $7, 1
    /* 2FCAF4 003FCAF4 0C0007AE */  sw         $7, 0xC($16)
    /* 2FCAF8 003FCAF8 1000078E */  lw         $7, 0x10($16)
    /* 2FCAFC 003FCAFC 43380700 */  sra        $7, $7, 1
    /* 2FCB00 003FCB00 100007AE */  sw         $7, 0x10($16)
    /* 2FCB04 003FCB04 1400078E */  lw         $7, 0x14($16)
    /* 2FCB08 003FCB08 1838E800 */  mult       $7, $7, $8
    /* 2FCB0C 003FCB0C C3380700 */  sra        $7, $7, 3
    /* 2FCB10 003FCB10 83410400 */  sra        $8, $4, 6
    /* 2FCB14 003FCB14 180007AE */  sw         $7, 0x18($16)
    /* 2FCB18 003FCB18 0400078E */  lw         $7, 0x4($16)
    /* 2FCB1C 003FCB1C 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FCB20 003FCB20 2438E200 */  and        $7, $7, $2
    /* 2FCB24 003FCB24 040007AE */  sw         $7, 0x4($16)
    /* 2FCB28 003FCB28 1800078E */  lw         $7, 0x18($16)
    /* 2FCB2C 003FCB2C 1848E870 */  mult1      $9, $7, $8
    /* 2FCB30 003FCB30 0400078E */  lw         $7, 0x4($16)
    /* 2FCB34 003FCB34 C3410500 */  sra        $8, $5, 7
    /* 2FCB38 003FCB38 2138E900 */  addu       $7, $7, $9
    /* 2FCB3C 003FCB3C 040007AE */  sw         $7, 0x4($16)
    /* 2FCB40 003FCB40 0C00078E */  lw         $7, 0xC($16)
    /* 2FCB44 003FCB44 43380700 */  sra        $7, $7, 1
    /* 2FCB48 003FCB48 0C0007AE */  sw         $7, 0xC($16)
    /* 2FCB4C 003FCB4C 1000078E */  lw         $7, 0x10($16)
    /* 2FCB50 003FCB50 43380700 */  sra        $7, $7, 1
    /* 2FCB54 003FCB54 100007AE */  sw         $7, 0x10($16)
    /* 2FCB58 003FCB58 1400078E */  lw         $7, 0x14($16)
    /* 2FCB5C 003FCB5C 1838E800 */  mult       $7, $7, $8
    /* 2FCB60 003FCB60 C3380700 */  sra        $7, $7, 3
    /* 2FCB64 003FCB64 C3410400 */  sra        $8, $4, 7
    /* 2FCB68 003FCB68 180007AE */  sw         $7, 0x18($16)
    /* 2FCB6C 003FCB6C 0400078E */  lw         $7, 0x4($16)
    /* 2FCB70 003FCB70 0F00E724 */  addiu      $7, $7, 0xF
    /* 2FCB74 003FCB74 2438E200 */  and        $7, $7, $2
    /* 2FCB78 003FCB78 040007AE */  sw         $7, 0x4($16)
    /* 2FCB7C 003FCB7C 1800078E */  lw         $7, 0x18($16)
    /* 2FCB80 003FCB80 1848E870 */  mult1      $9, $7, $8
    /* 2FCB84 003FCB84 0800C624 */  addiu      $6, $6, 0x8
    /* 2FCB88 003FCB88 0400088E */  lw         $8, 0x4($16)
    /* 2FCB8C 003FCB8C FF00C630 */  andi       $6, $6, 0xFF
    /* 2FCB90 003FCB90 2A38C300 */  slt        $7, $6, $3
    /* 2FCB94 003FCB94 032A0500 */  sra        $5, $5, 8
    /* 2FCB98 003FCB98 03220400 */  sra        $4, $4, 8
    /* 2FCB9C 003FCB9C 21400901 */  addu       $8, $8, $9
    /* 2FCBA0 003FCBA0 040008AE */  sw         $8, 0x4($16)
    /* 2FCBA4 003FCBA4 0C00088E */  lw         $8, 0xC($16)
    /* 2FCBA8 003FCBA8 43400800 */  sra        $8, $8, 1
    /* 2FCBAC 003FCBAC 0C0008AE */  sw         $8, 0xC($16)
    /* 2FCBB0 003FCBB0 1000088E */  lw         $8, 0x10($16)
    /* 2FCBB4 003FCBB4 43400800 */  sra        $8, $8, 1
    /* 2FCBB8 003FCBB8 55FFE014 */  bnez       $7, .L003FC910
    /* 2FCBBC 003FCBBC 100008AE */   sw        $8, 0x10($16)
  .L003FCBC0:
    /* 2FCBC0 003FCBC0 FF00C230 */  andi       $2, $6, 0xFF
    /* 2FCBC4 003FCBC4 2A085400 */  slt        $1, $2, $20
    /* 2FCBC8 003FCBC8 1B002010 */  beqz       $1, .L003FCC38
    /* 2FCBCC 003FCBCC 00000000 */   nop
    /* 2FCBD0 003FCBD0 F0FF0824 */  addiu      $8, $0, -0x10
  .L003FCBD4:
    /* 2FCBD4 003FCBD4 1400028E */  lw         $2, 0x14($16)
    /* 2FCBD8 003FCBD8 18104500 */  mult       $2, $2, $5
    /* 2FCBDC 003FCBDC C3100200 */  sra        $2, $2, 3
    /* 2FCBE0 003FCBE0 180002AE */  sw         $2, 0x18($16)
    /* 2FCBE4 003FCBE4 0400028E */  lw         $2, 0x4($16)
    /* 2FCBE8 003FCBE8 0F004224 */  addiu      $2, $2, 0xF
    /* 2FCBEC 003FCBEC 24104800 */  and        $2, $2, $8
    /* 2FCBF0 003FCBF0 040002AE */  sw         $2, 0x4($16)
    /* 2FCBF4 003FCBF4 1800028E */  lw         $2, 0x18($16)
    /* 2FCBF8 003FCBF8 18384470 */  mult1      $7, $2, $4
    /* 2FCBFC 003FCBFC 0400038E */  lw         $3, 0x4($16)
    /* 2FCC00 003FCC00 0100C224 */  addiu      $2, $6, 0x1
    /* 2FCC04 003FCC04 43280500 */  sra        $5, $5, 1
    /* 2FCC08 003FCC08 FF004630 */  andi       $6, $2, 0xFF
    /* 2FCC0C 003FCC0C 43200400 */  sra        $4, $4, 1
    /* 2FCC10 003FCC10 2A10D400 */  slt        $2, $6, $20
    /* 2FCC14 003FCC14 21186700 */  addu       $3, $3, $7
    /* 2FCC18 003FCC18 040003AE */  sw         $3, 0x4($16)
    /* 2FCC1C 003FCC1C 0C00038E */  lw         $3, 0xC($16)
    /* 2FCC20 003FCC20 43180300 */  sra        $3, $3, 1
    /* 2FCC24 003FCC24 0C0003AE */  sw         $3, 0xC($16)
    /* 2FCC28 003FCC28 1000038E */  lw         $3, 0x10($16)
    /* 2FCC2C 003FCC2C 43180300 */  sra        $3, $3, 1
    /* 2FCC30 003FCC30 E8FF4014 */  bnez       $2, .L003FCBD4
    /* 2FCC34 003FCC34 100003AE */   sw        $3, 0x10($16)
  .L003FCC38:
    /* 2FCC38 003FCC38 0400038E */  lw         $3, 0x4($16)
    /* 2FCC3C 003FCC3C F0FF0224 */  addiu      $2, $0, -0x10
    /* 2FCC40 003FCC40 0F006324 */  addiu      $3, $3, 0xF
    /* 2FCC44 003FCC44 24106200 */  and        $2, $3, $2
    /* 2FCC48 003FCC48 040002AE */  sw         $2, 0x4($16)
    /* 2FCC4C 003FCC4C 1400028E */  lw         $2, 0x14($16)
    /* 2FCC50 003FCC50 18104500 */  mult       $2, $2, $5
    /* 2FCC54 003FCC54 C3100200 */  sra        $2, $2, 3
    /* 2FCC58 003FCC58 180002AE */  sw         $2, 0x18($16)
  .L003FCC5C:
    /* 2FCC5C 003FCC5C 02006232 */  andi       $2, $19, 0x2
    /* 2FCC60 003FCC60 17004010 */  beqz       $2, .L003FCCC0
    /* 2FCC64 003FCC64 00000000 */   nop
    /* 2FCC68 003FCC68 3600A592 */  lbu        $5, 0x36($21)
    /* 2FCC6C 003FCC6C 0200A330 */  andi       $3, $5, 0x2
    /* 2FCC70 003FCC70 46016014 */  bnez       $3, .L003FD18C
    /* 2FCC74 003FCC74 00000000 */   nop
  .L003FCC78:
    /* 2FCC78 003FCC78 0400A330 */  andi       $3, $5, 0x4
    /* 2FCC7C 003FCC7C 10006010 */  beqz       $3, .L003FCCC0
    /* 2FCC80 003FCC80 00000000 */   nop
    /* 2FCC84 003FCC84 0800A48E */  lw         $4, 0x8($21)
    /* 2FCC88 003FCC88 14000324 */  addiu      $3, $0, 0x14
    /* 2FCC8C 003FCC8C 02250400 */  srl        $4, $4, 20
    /* 2FCC90 003FCC90 3F008430 */  andi       $4, $4, 0x3F
    /* 2FCC94 003FCC94 0A008314 */  bne        $4, $3, .L003FCCC0
    /* 2FCC98 003FCC98 00000000 */   nop
    /* 2FCC9C 003FCC9C 1800038E */  lw         $3, 0x18($16)
    /* 2FCCA0 003FCCA0 10006328 */  slti       $3, $3, 0x10
    /* 2FCCA4 003FCCA4 06006014 */  bnez       $3, .L003FCCC0
    /* 2FCCA8 003FCCA8 00000000 */   nop
    /* 2FCCAC 003FCCAC 08006332 */  andi       $3, $19, 0x8
    /* 2FCCB0 003FCCB0 03006014 */  bnez       $3, .L003FCCC0
    /* 2FCCB4 003FCCB4 00000000 */   nop
    /* 2FCCB8 003FCCB8 14EF0F0C */  jal        func_003fbc50
    /* 2FCCBC 003FCCBC 2D200002 */   daddu     $4, $16, $0
  .L003FCCC0:
    /* 2FCCC0 003FCCC0 0400038E */  lw         $3, 0x4($16)
  .L003FCCC4:
    /* 2FCCC4 003FCCC4 0000E3AE */  sw         $3, 0x0($23)
    /* 2FCCC8 003FCCC8 41014014 */  bnez       $2, .L003FD1D0
    /* 2FCCCC 003FCCCC 3500B2A2 */   sb        $18, 0x35($21)
  .L003FCCD0:
    /* 2FCCD0 003FCCD0 43012016 */  bnez       $17, .L003FD1E0
    /* 2FCCD4 003FCCD4 00000000 */   nop
  .L003FCCD8:
    /* 2FCCD8 003FCCD8 08006232 */  andi       $2, $19, 0x8
    /* 2FCCDC 003FCCDC 44014014 */  bnez       $2, .L003FD1F0
    /* 2FCCE0 003FCCE0 00000000 */   nop
  .L003FCCE4:
    /* 2FCCE4 003FCCE4 46010010 */  b          .L003FD200
    /* 2FCCE8 003FCCE8 01000224 */   addiu     $2, $0, 0x1
  .L003FCCEC:
    /* 2FCCEC 003FCCEC C000A4AF */  sw         $4, 0xC0($29)
    /* 2FCCF0 003FCCF0 0080023C */  lui        $2, (0x8000000E >> 16)
    /* 2FCCF4 003FCCF4 647D0F0C */  jal        func_003df590
    /* 2FCCF8 003FCCF8 0E004434 */   ori       $4, $2, (0x8000000E & 0xFFFF)
    /* 2FCCFC 003FCCFC C400A2AF */  sw         $2, 0xC4($29)
    /* 2FCD00 003FCD00 347D0F0C */  jal        func_003df4d0
    /* 2FCD04 003FCD04 C000A427 */   addiu     $4, $29, 0xC0
    /* 2FCD08 003FCD08 3D010010 */  b          .L003FD200
    /* 2FCD0C 003FCD0C 2D100000 */   daddu     $2, $0, $0
  .L003FCD10:
    /* 2FCD10 003FCD10 B800A4AF */  sw         $4, 0xB8($29)
    /* 2FCD14 003FCD14 0080023C */  lui        $2, (0x8000000F >> 16)
    /* 2FCD18 003FCD18 647D0F0C */  jal        func_003df590
    /* 2FCD1C 003FCD1C 0F004434 */   ori       $4, $2, (0x8000000F & 0xFFFF)
    /* 2FCD20 003FCD20 BC00A2AF */  sw         $2, 0xBC($29)
    /* 2FCD24 003FCD24 347D0F0C */  jal        func_003df4d0
    /* 2FCD28 003FCD28 B800A427 */   addiu     $4, $29, 0xB8
    /* 2FCD2C 003FCD2C 34010010 */  b          .L003FD200
    /* 2FCD30 003FCD30 2D100000 */   daddu     $2, $0, $0
  .L003FCD34:
    /* 2FCD34 003FCD34 32010010 */  b          .L003FD200
    /* 2FCD38 003FCD38 2D100000 */   daddu     $2, $0, $0
  .L003FCD3C:
    /* 2FCD3C 003FCD3C 78FE6016 */  bnez       $19, .L003FC720
    /* 2FCD40 003FCD40 00000000 */   nop
    /* 2FCD44 003FCD44 2E010010 */  b          .L003FD200
    /* 2FCD48 003FCD48 2D100000 */   daddu     $2, $0, $0
  .L003FCD4C:
    /* 2FCD4C 003FCD4C 8900153C */  lui        $21, %hi(D_0088C5B0)
    /* 2FCD50 003FCD50 B0C5B526 */  addiu      $21, $21, %lo(D_0088C5B0)
  .L003FCD54:
    /* 2FCD54 003FCD54 C8B887DF */  ld         $7, -0x4738($28)
    /* 2FCD58 003FCD58 FF074232 */  andi       $2, $18, 0x7FF
    /* 2FCD5C 003FCD5C 3F00063C */  lui        $6, (0x3F0000 >> 16)
    /* 2FCD60 003FCD60 3C4C0200 */  dsll32     $9, $2, 16
    /* 2FCD64 003FCD64 003F053C */  lui        $5, (0x3F000000 >> 16)
    /* 2FCD68 003FCD68 3C5C1300 */  dsll32     $11, $19, 16
    /* 2FCD6C 003FCD6C 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FCD70 003FCD70 1C000386 */  lh         $3, 0x1C($16)
    /* 2FCD74 003FCD74 0C000A86 */  lh         $10, 0xC($16)
    /* 2FCD78 003FCD78 3F4C0900 */  dsra32     $9, $9, 16
    /* 2FCD7C 003FCD7C 3F5C0B00 */  dsra32     $11, $11, 16
    /* 2FCD80 003FCD80 40C58424 */  addiu      $4, $4, %lo(D_0088C540)
    /* 2FCD84 003FCD84 2410E500 */  and        $2, $7, $5
    /* 2FCD88 003FCD88 2430E600 */  and        $6, $7, $6
    /* 2FCD8C 003FCD8C FF01E730 */  andi       $7, $7, 0x1FF
    /* 2FCD90 003FCD90 3B2C0600 */  dsra       $5, $6, 16
    /* 2FCD94 003FCD94 3C340500 */  dsll32     $6, $5, 16
    /* 2FCD98 003FCD98 78390700 */  dsll       $7, $7, 5
    /* 2FCD9C 003FCD9C 3C2C0700 */  dsll32     $5, $7, 16
    /* 2FCDA0 003FCDA0 3B160200 */  dsra       $2, $2, 24
    /* 2FCDA4 003FCDA4 3C3C0200 */  dsll32     $7, $2, 16
    /* 2FCDA8 003FCDA8 3F340600 */  dsra32     $6, $6, 16
    /* 2FCDAC 003FCDAC FF076230 */  andi       $2, $3, 0x7FF
    /* 2FCDB0 003FCDB0 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FCDB4 003FCDB4 3C440200 */  dsll32     $8, $2, 16
    /* 2FCDB8 003FCDB8 3F3C0700 */  dsra32     $7, $7, 16
    /* 2FCDBC 003FCDBC D260100C */  jal        func_00418348
    /* 2FCDC0 003FCDC0 3F440800 */   dsra32    $8, $8, 16
    /* 2FCDC4 003FCDC4 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FCDC8 003FCDC8 2D28A002 */  daddu      $5, $21, $0
    /* 2FCDCC 003FCDCC 3688100C */  jal        func_004220d8
    /* 2FCDD0 003FCDD0 40C58424 */   addiu     $4, $4, %lo(D_0088C540)
    /* 2FCDD4 003FCDD4 00000000 */  nop
  .L003FCDD8:
    /* 2FCDD8 003FCDD8 D463100C */  jal        func_00418f50
    /* 2FCDDC 003FCDDC 01000424 */   addiu     $4, $0, 0x1
    /* 2FCDE0 003FCDE0 0000428C */  lw         $2, 0x0($2)
    /* 2FCDE4 003FCDE4 00014230 */  andi       $2, $2, 0x100
    /* 2FCDE8 003FCDE8 00000000 */  nop
    /* 2FCDEC 003FCDEC FAFF4014 */  bnez       $2, .L003FCDD8
    /* 2FCDF0 003FCDF0 00000000 */   nop
    /* 2FCDF4 003FCDF4 00000000 */  nop
  .L003FCDF8:
    /* 2FCDF8 003FCDF8 D463100C */  jal        func_00418f50
    /* 2FCDFC 003FCDFC 02000424 */   addiu     $4, $0, 0x2
    /* 2FCE00 003FCE00 0000428C */  lw         $2, 0x0($2)
    /* 2FCE04 003FCE04 00014230 */  andi       $2, $2, 0x100
    /* 2FCE08 003FCE08 00000000 */  nop
    /* 2FCE0C 003FCE0C FAFF4014 */  bnez       $2, .L003FCDF8
    /* 2FCE10 003FCE10 00000000 */   nop
    /* 2FCE14 003FCE14 2D200000 */  daddu      $4, $0, $0
    /* 2FCE18 003FCE18 0C60100C */  jal        func_00418030
    /* 2FCE1C 003FCE1C 2D280000 */   daddu     $5, $0, $0
    /* 2FCE20 003FCE20 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FCE24 003FCE24 2D282002 */  daddu      $5, $17, $0
    /* 2FCE28 003FCE28 2261100C */  jal        func_00418488
    /* 2FCE2C 003FCE2C 40C58424 */   addiu     $4, $4, %lo(D_0088C540)
    /* 2FCE30 003FCE30 FFFF0324 */  addiu      $3, $0, -0x1
    /* 2FCE34 003FCE34 12004310 */  beq        $2, $3, .L003FCE80
    /* 2FCE38 003FCE38 00000000 */   nop
    /* 2FCE3C 003FCE3C 00000000 */  nop
  .L003FCE40:
    /* 2FCE40 003FCE40 0C00038E */  lw         $3, 0xC($16)
    /* 2FCE44 003FCE44 1400028E */  lw         $2, 0x14($16)
    /* 2FCE48 003FCE48 23A09302 */  subu       $20, $20, $19
    /* 2FCE4C 003FCE4C 21905302 */  addu       $18, $18, $19
    /* 2FCE50 003FCE50 18106200 */  mult       $2, $3, $2
    /* 2FCE54 003FCE54 C3100200 */  sra        $2, $2, 3
    /* 2FCE58 003FCE58 18106202 */  mult       $2, $19, $2
    /* 2FCE5C 003FCE5C 2A089302 */  slt        $1, $20, $19
    /* 2FCE60 003FCE60 03002010 */  beqz       $1, .L003FCE70
    /* 2FCE64 003FCE64 21882202 */   addu      $17, $17, $2
    /* 2FCE68 003FCE68 2D988002 */  daddu      $19, $20, $0
    /* 2FCE6C 003FCE6C 00000000 */  nop
  .L003FCE70:
    /* 2FCE70 003FCE70 B8FF8016 */  bnez       $20, .L003FCD54
    /* 2FCE74 003FCE74 00000000 */   nop
    /* 2FCE78 003FCE78 2FFE0010 */  b          .L003FC738
    /* 2FCE7C 003FCE7C 0C00038E */   lw        $3, 0xC($16)
  .L003FCE80:
    /* 2FCE80 003FCE80 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FCE84 003FCE84 2D282002 */  daddu      $5, $17, $0
    /* 2FCE88 003FCE88 2261100C */  jal        func_00418488
    /* 2FCE8C 003FCE8C 40C58424 */   addiu     $4, $4, %lo(D_0088C540)
    /* 2FCE90 003FCE90 FFFF0324 */  addiu      $3, $0, -0x1
    /* 2FCE94 003FCE94 EAFF4314 */  bne        $2, $3, .L003FCE40
    /* 2FCE98 003FCE98 00000000 */   nop
    /* 2FCE9C 003FCE9C D8000010 */  b          .L003FD200
    /* 2FCEA0 003FCEA0 2D100000 */   daddu     $2, $0, $0
  .L003FCEA4:
    /* 2FCEA4 003FCEA4 D6000010 */  b          .L003FD200
    /* 2FCEA8 003FCEA8 2D100000 */   daddu     $2, $0, $0
  .L003FCEAC:
    /* 2FCEAC 003FCEAC B000A4AF */  sw         $4, 0xB0($29)
    /* 2FCEB0 003FCEB0 0080023C */  lui        $2, (0x8000000E >> 16)
    /* 2FCEB4 003FCEB4 647D0F0C */  jal        func_003df590
    /* 2FCEB8 003FCEB8 0E004434 */   ori       $4, $2, (0x8000000E & 0xFFFF)
    /* 2FCEBC 003FCEBC B400A2AF */  sw         $2, 0xB4($29)
    /* 2FCEC0 003FCEC0 347D0F0C */  jal        func_003df4d0
    /* 2FCEC4 003FCEC4 B000A427 */   addiu     $4, $29, 0xB0
    /* 2FCEC8 003FCEC8 CD000010 */  b          .L003FD200
    /* 2FCECC 003FCECC 2D100000 */   daddu     $2, $0, $0
  .L003FCED0:
    /* 2FCED0 003FCED0 A800A4AF */  sw         $4, 0xA8($29)
    /* 2FCED4 003FCED4 0080023C */  lui        $2, (0x8000000E >> 16)
    /* 2FCED8 003FCED8 647D0F0C */  jal        func_003df590
    /* 2FCEDC 003FCEDC 0E004434 */   ori       $4, $2, (0x8000000E & 0xFFFF)
    /* 2FCEE0 003FCEE0 AC00A2AF */  sw         $2, 0xAC($29)
    /* 2FCEE4 003FCEE4 347D0F0C */  jal        func_003df4d0
    /* 2FCEE8 003FCEE8 A800A427 */   addiu     $4, $29, 0xA8
    /* 2FCEEC 003FCEEC C4000010 */  b          .L003FD200
    /* 2FCEF0 003FCEF0 2D100000 */   daddu     $2, $0, $0
  .L003FCEF4:
    /* 2FCEF4 003FCEF4 A000A4AF */  sw         $4, 0xA0($29)
    /* 2FCEF8 003FCEF8 0080023C */  lui        $2, (0x8000000F >> 16)
    /* 2FCEFC 003FCEFC 647D0F0C */  jal        func_003df590
    /* 2FCF00 003FCF00 0F004434 */   ori       $4, $2, (0x8000000F & 0xFFFF)
    /* 2FCF04 003FCF04 A400A2AF */  sw         $2, 0xA4($29)
    /* 2FCF08 003FCF08 347D0F0C */  jal        func_003df4d0
    /* 2FCF0C 003FCF0C A000A427 */   addiu     $4, $29, 0xA0
    /* 2FCF10 003FCF10 BB000010 */  b          .L003FD200
    /* 2FCF14 003FCF14 2D100000 */   daddu     $2, $0, $0
  .L003FCF18:
    /* 2FCF18 003FCF18 B9000010 */  b          .L003FD200
    /* 2FCF1C 003FCF1C 2D100000 */   daddu     $2, $0, $0
  .L003FCF20:
    /* 2FCF20 003FCF20 48FE8016 */  bnez       $20, .L003FC844
    /* 2FCF24 003FCF24 00000000 */   nop
    /* 2FCF28 003FCF28 B5000010 */  b          .L003FD200
    /* 2FCF2C 003FCF2C 2D100000 */   daddu     $2, $0, $0
  .L003FCF30:
    /* 2FCF30 003FCF30 8900163C */  lui        $22, %hi(D_0088C5B0)
    /* 2FCF34 003FCF34 B0C5D626 */  addiu      $22, $22, %lo(D_0088C5B0)
  .L003FCF38:
    /* 2FCF38 003FCF38 0800278E */  lw         $7, 0x8($17)
    /* 2FCF3C 003FCF3C FF076232 */  andi       $2, $19, 0x7FF
    /* 2FCF40 003FCF40 3C4C0200 */  dsll32     $9, $2, 16
    /* 2FCF44 003FCF44 3C5C1400 */  dsll32     $11, $20, 16
    /* 2FCF48 003FCF48 1C000286 */  lh         $2, 0x1C($16)
    /* 2FCF4C 003FCF4C 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FCF50 003FCF50 0C000A86 */  lh         $10, 0xC($16)
    /* 2FCF54 003FCF54 3F4C0900 */  dsra32     $9, $9, 16
    /* 2FCF58 003FCF58 3F5C0B00 */  dsra32     $11, $11, 16
    /* 2FCF5C 003FCF5C 40C58424 */  addiu      $4, $4, %lo(D_0088C540)
    /* 2FCF60 003FCF60 821B0700 */  srl        $3, $7, 14
    /* 2FCF64 003FCF64 FF3FE530 */  andi       $5, $7, 0x3FFF
    /* 2FCF68 003FCF68 3F006330 */  andi       $3, $3, 0x3F
    /* 2FCF6C 003FCF6C 3C2C0500 */  dsll32     $5, $5, 16
    /* 2FCF70 003FCF70 3C340300 */  dsll32     $6, $3, 16
    /* 2FCF74 003FCF74 FF074230 */  andi       $2, $2, 0x7FF
    /* 2FCF78 003FCF78 021D0700 */  srl        $3, $7, 20
    /* 2FCF7C 003FCF7C 3C440200 */  dsll32     $8, $2, 16
    /* 2FCF80 003FCF80 3F006330 */  andi       $3, $3, 0x3F
    /* 2FCF84 003FCF84 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FCF88 003FCF88 3C3C0300 */  dsll32     $7, $3, 16
    /* 2FCF8C 003FCF8C 3F340600 */  dsra32     $6, $6, 16
    /* 2FCF90 003FCF90 3F3C0700 */  dsra32     $7, $7, 16
    /* 2FCF94 003FCF94 D260100C */  jal        func_00418348
    /* 2FCF98 003FCF98 3F440800 */   dsra32    $8, $8, 16
    /* 2FCF9C 003FCF9C 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FCFA0 003FCFA0 2D28C002 */  daddu      $5, $22, $0
    /* 2FCFA4 003FCFA4 3688100C */  jal        func_004220d8
    /* 2FCFA8 003FCFA8 40C58424 */   addiu     $4, $4, %lo(D_0088C540)
    /* 2FCFAC 003FCFAC 00000000 */  nop
  .L003FCFB0:
    /* 2FCFB0 003FCFB0 D463100C */  jal        func_00418f50
    /* 2FCFB4 003FCFB4 01000424 */   addiu     $4, $0, 0x1
    /* 2FCFB8 003FCFB8 0000428C */  lw         $2, 0x0($2)
    /* 2FCFBC 003FCFBC 00014230 */  andi       $2, $2, 0x100
    /* 2FCFC0 003FCFC0 00000000 */  nop
    /* 2FCFC4 003FCFC4 FAFF4014 */  bnez       $2, .L003FCFB0
    /* 2FCFC8 003FCFC8 00000000 */   nop
    /* 2FCFCC 003FCFCC 00000000 */  nop
  .L003FCFD0:
    /* 2FCFD0 003FCFD0 D463100C */  jal        func_00418f50
    /* 2FCFD4 003FCFD4 02000424 */   addiu     $4, $0, 0x2
    /* 2FCFD8 003FCFD8 0000428C */  lw         $2, 0x0($2)
    /* 2FCFDC 003FCFDC 00014230 */  andi       $2, $2, 0x100
    /* 2FCFE0 003FCFE0 00000000 */  nop
    /* 2FCFE4 003FCFE4 FAFF4014 */  bnez       $2, .L003FCFD0
    /* 2FCFE8 003FCFE8 00000000 */   nop
    /* 2FCFEC 003FCFEC 2D200000 */  daddu      $4, $0, $0
    /* 2FCFF0 003FCFF0 0C60100C */  jal        func_00418030
    /* 2FCFF4 003FCFF4 2D280000 */   daddu     $5, $0, $0
    /* 2FCFF8 003FCFF8 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FCFFC 003FCFFC 2D284002 */  daddu      $5, $18, $0
    /* 2FD000 003FD000 2261100C */  jal        func_00418488
    /* 2FD004 003FD004 40C58424 */   addiu     $4, $4, %lo(D_0088C540)
    /* 2FD008 003FD008 FFFF0324 */  addiu      $3, $0, -0x1
    /* 2FD00C 003FD00C 12004310 */  beq        $2, $3, .L003FD058
    /* 2FD010 003FD010 00000000 */   nop
    /* 2FD014 003FD014 00000000 */  nop
  .L003FD018:
    /* 2FD018 003FD018 0C00038E */  lw         $3, 0xC($16)
    /* 2FD01C 003FD01C 1400028E */  lw         $2, 0x14($16)
    /* 2FD020 003FD020 23A8B402 */  subu       $21, $21, $20
    /* 2FD024 003FD024 21987402 */  addu       $19, $19, $20
    /* 2FD028 003FD028 18106200 */  mult       $2, $3, $2
    /* 2FD02C 003FD02C C3100200 */  sra        $2, $2, 3
    /* 2FD030 003FD030 18108202 */  mult       $2, $20, $2
    /* 2FD034 003FD034 2A08B402 */  slt        $1, $21, $20
    /* 2FD038 003FD038 03002010 */  beqz       $1, .L003FD048
    /* 2FD03C 003FD03C 21904202 */   addu      $18, $18, $2
    /* 2FD040 003FD040 2DA0A002 */  daddu      $20, $21, $0
    /* 2FD044 003FD044 00000000 */  nop
  .L003FD048:
    /* 2FD048 003FD048 BBFFA016 */  bnez       $21, .L003FCF38
    /* 2FD04C 003FD04C 00000000 */   nop
    /* 2FD050 003FD050 02FE0010 */  b          .L003FC85C
    /* 2FD054 003FD054 0C00038E */   lw        $3, 0xC($16)
  .L003FD058:
    /* 2FD058 003FD058 8900043C */  lui        $4, %hi(D_0088C540)
    /* 2FD05C 003FD05C 2D284002 */  daddu      $5, $18, $0
    /* 2FD060 003FD060 2261100C */  jal        func_00418488
    /* 2FD064 003FD064 40C58424 */   addiu     $4, $4, %lo(D_0088C540)
    /* 2FD068 003FD068 FFFF0324 */  addiu      $3, $0, -0x1
    /* 2FD06C 003FD06C EAFF4314 */  bne        $2, $3, .L003FD018
    /* 2FD070 003FD070 00000000 */   nop
    /* 2FD074 003FD074 62000010 */  b          .L003FD200
    /* 2FD078 003FD078 2D100000 */   daddu     $2, $0, $0
  .L003FD07C:
    /* 2FD07C 003FD07C 9000A4AF */  sw         $4, 0x90($29)
    /* 2FD080 003FD080 0080023C */  lui        $2, (0x8000000F >> 16)
    /* 2FD084 003FD084 647D0F0C */  jal        func_003df590
    /* 2FD088 003FD088 0F004434 */   ori       $4, $2, (0x8000000F & 0xFFFF)
    /* 2FD08C 003FD08C 9400A2AF */  sw         $2, 0x94($29)
    /* 2FD090 003FD090 347D0F0C */  jal        func_003df4d0
    /* 2FD094 003FD094 9000A427 */   addiu     $4, $29, 0x90
    /* 2FD098 003FD098 59000010 */  b          .L003FD200
    /* 2FD09C 003FD09C 2D100000 */   daddu     $2, $0, $0
  .L003FD0A0:
    /* 2FD0A0 003FD0A0 A43E100C */  jal        func_0040fa90
    /* 2FD0A4 003FD0A4 2D200002 */   daddu     $4, $16, $0
    /* 2FD0A8 003FD0A8 0CFE0010 */  b          .L003FC8DC
    /* 2FD0AC 003FD0AC 3600A592 */   lbu       $5, 0x36($21)
  .L003FD0B0:
    /* 2FD0B0 003FD0B0 0800A28E */  lw         $2, 0x8($21)
    /* 2FD0B4 003FD0B4 CC00A627 */  addiu      $6, $29, 0xCC
    /* 2FD0B8 003FD0B8 C800A727 */  addiu      $7, $29, 0xC8
    /* 2FD0BC 003FD0BC 02150200 */  srl        $2, $2, 20
    /* 2FD0C0 003FD0C0 D4E50F0C */  jal        func_003f9750
    /* 2FD0C4 003FD0C4 3F004430 */   andi      $4, $2, 0x3F
    /* 2FD0C8 003FD0C8 0000038E */  lw         $3, 0x0($16)
    /* 2FD0CC 003FD0CC 2A081400 */  slt        $1, $0, $20
    /* 2FD0D0 003FD0D0 0C00068E */  lw         $6, 0xC($16)
    /* 2FD0D4 003FD0D4 1000058E */  lw         $5, 0x10($16)
    /* 2FD0D8 003FD0D8 0C00648C */  lw         $4, 0xC($3)
    /* 2FD0DC 003FD0DC 1000638C */  lw         $3, 0x10($3)
    /* 2FD0E0 003FD0E0 20002010 */  beqz       $1, .L003FD164
    /* 2FD0E4 003FD0E4 2D100000 */   daddu     $2, $0, $0
    /* 2FD0E8 003FD0E8 F0FF0A24 */  addiu      $10, $0, -0x10
  .L003FD0EC:
    /* 2FD0EC 003FD0EC CC00A98F */  lw         $9, 0xCC($29)
    /* 2FD0F0 003FD0F0 2A088900 */  slt        $1, $4, $9
    /* 2FD0F4 003FD0F4 03002010 */  beqz       $1, .L003FD104
    /* 2FD0F8 003FD0F8 00000000 */   nop
    /* 2FD0FC 003FD0FC 02000010 */  b          .L003FD108
    /* 2FD100 003FD100 2D402001 */   daddu     $8, $9, $0
  .L003FD104:
    /* 2FD104 003FD104 2D408000 */  daddu      $8, $4, $0
  .L003FD108:
    /* 2FD108 003FD108 C800A78F */  lw         $7, 0xC8($29)
    /* 2FD10C 003FD10C 2A086700 */  slt        $1, $3, $7
    /* 2FD110 003FD110 0A486100 */  movz       $9, $3, $1
    /* 2FD114 003FD114 18400901 */  mult       $8, $8, $9
    /* 2FD118 003FD118 1400078E */  lw         $7, 0x14($16)
    /* 2FD11C 003FD11C 1838E800 */  mult       $7, $7, $8
    /* 2FD120 003FD120 01004224 */  addiu      $2, $2, 0x1
    /* 2FD124 003FD124 FF004230 */  andi       $2, $2, 0xFF
    /* 2FD128 003FD128 43300600 */  sra        $6, $6, 1
    /* 2FD12C 003FD12C 43200400 */  sra        $4, $4, 1
    /* 2FD130 003FD130 43280500 */  sra        $5, $5, 1
    /* 2FD134 003FD134 43180300 */  sra        $3, $3, 1
    /* 2FD138 003FD138 0400088E */  lw         $8, 0x4($16)
    /* 2FD13C 003FD13C C3380700 */  sra        $7, $7, 3
    /* 2FD140 003FD140 0F00E924 */  addiu      $9, $7, 0xF
    /* 2FD144 003FD144 24482A01 */  and        $9, $9, $10
    /* 2FD148 003FD148 2A385400 */  slt        $7, $2, $20
    /* 2FD14C 003FD14C 21400901 */  addu       $8, $8, $9
    /* 2FD150 003FD150 040008AE */  sw         $8, 0x4($16)
    /* 2FD154 003FD154 0400088E */  lw         $8, 0x4($16)
    /* 2FD158 003FD158 50000825 */  addiu      $8, $8, 0x50
    /* 2FD15C 003FD15C E3FFE014 */  bnez       $7, .L003FD0EC
    /* 2FD160 003FD160 040008AE */   sw        $8, 0x4($16)
  .L003FD164:
    /* 2FD164 003FD164 CC00A38F */  lw         $3, 0xCC($29)
    /* 2FD168 003FD168 2A088300 */  slt        $1, $4, $3
    /* 2FD16C 003FD16C 0A188100 */  movz       $3, $4, $1
    /* 2FD170 003FD170 1400028E */  lw         $2, 0x14($16)
    /* 2FD174 003FD174 18104300 */  mult       $2, $2, $3
    /* 2FD178 003FD178 C3100200 */  sra        $2, $2, 3
    /* 2FD17C 003FD17C 180002AE */  sw         $2, 0x18($16)
    /* 2FD180 003FD180 0C0006AE */  sw         $6, 0xC($16)
    /* 2FD184 003FD184 B5FE0010 */  b          .L003FCC5C
    /* 2FD188 003FD188 100005AE */   sw        $5, 0x10($16)
  .L003FD18C:
    /* 2FD18C 003FD18C 0800A48E */  lw         $4, 0x8($21)
    /* 2FD190 003FD190 13000324 */  addiu      $3, $0, 0x13
    /* 2FD194 003FD194 02250400 */  srl        $4, $4, 20
    /* 2FD198 003FD198 3F008430 */  andi       $4, $4, 0x3F
    /* 2FD19C 003FD19C B6FE8314 */  bne        $4, $3, .L003FCC78
    /* 2FD1A0 003FD1A0 00000000 */   nop
    /* 2FD1A4 003FD1A4 1800038E */  lw         $3, 0x18($16)
    /* 2FD1A8 003FD1A8 10006328 */  slti       $3, $3, 0x10
    /* 2FD1AC 003FD1AC B2FE6014 */  bnez       $3, .L003FCC78
    /* 2FD1B0 003FD1B0 00000000 */   nop
    /* 2FD1B4 003FD1B4 08006332 */  andi       $3, $19, 0x8
    /* 2FD1B8 003FD1B8 AFFE6014 */  bnez       $3, .L003FCC78
    /* 2FD1BC 003FD1BC 00000000 */   nop
    /* 2FD1C0 003FD1C0 74EE0F0C */  jal        func_003fb9d0
    /* 2FD1C4 003FD1C4 2D200002 */   daddu     $4, $16, $0
    /* 2FD1C8 003FD1C8 BEFE0010 */  b          .L003FCCC4
    /* 2FD1CC 003FD1CC 0400038E */   lw        $3, 0x4($16)
  .L003FD1D0:
    /* 2FD1D0 003FD1D0 22000292 */  lbu        $2, 0x22($16)
    /* 2FD1D4 003FD1D4 02004234 */  ori        $2, $2, 0x2
    /* 2FD1D8 003FD1D8 BDFE0010 */  b          .L003FCCD0
    /* 2FD1DC 003FD1DC 220002A2 */   sb        $2, 0x22($16)
  .L003FD1E0:
    /* 2FD1E0 003FD1E0 22000292 */  lbu        $2, 0x22($16)
    /* 2FD1E4 003FD1E4 04004234 */  ori        $2, $2, 0x4
    /* 2FD1E8 003FD1E8 BBFE0010 */  b          .L003FCCD8
    /* 2FD1EC 003FD1EC 220002A2 */   sb        $2, 0x22($16)
  .L003FD1F0:
    /* 2FD1F0 003FD1F0 22000292 */  lbu        $2, 0x22($16)
    /* 2FD1F4 003FD1F4 20004234 */  ori        $2, $2, 0x20
    /* 2FD1F8 003FD1F8 BAFE0010 */  b          .L003FCCE4
    /* 2FD1FC 003FD1FC 220002A2 */   sb        $2, 0x22($16)
  .L003FD200:
    /* 2FD200 003FD200 8000BFDF */  ld         $31, 0x80($29)
    /* 2FD204 003FD204 7000B77B */  lq         $23, 0x70($29)
    /* 2FD208 003FD208 6000B67B */  lq         $22, 0x60($29)
    /* 2FD20C 003FD20C 5000B57B */  lq         $21, 0x50($29)
    /* 2FD210 003FD210 4000B47B */  lq         $20, 0x40($29)
    /* 2FD214 003FD214 3000B37B */  lq         $19, 0x30($29)
    /* 2FD218 003FD218 2000B27B */  lq         $18, 0x20($29)
    /* 2FD21C 003FD21C 1000B17B */  lq         $17, 0x10($29)
    /* 2FD220 003FD220 0000B07B */  lq         $16, 0x0($29)
    /* 2FD224 003FD224 0800E003 */  jr         $31
    /* 2FD228 003FD228 D000BD27 */   addiu     $29, $29, 0xD0
    /* 2FD22C 003FD22C 00000000 */  nop
.size func_003fc5f0, 0xc40
