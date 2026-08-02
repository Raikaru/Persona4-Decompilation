.section .text
.set noat
.set noreorder
glabel func_002be530
    /* 1BE530 002BE530 70F8BD27 */  addiu      $29, $29, -0x790
    /* 1BE534 002BE534 B000BFFF */  sd         $31, 0xB0($29)
    /* 1BE538 002BE538 A000BE7F */  sq         $30, 0xA0($29)
    /* 1BE53C 002BE53C 9000B77F */  sq         $23, 0x90($29)
    /* 1BE540 002BE540 8000B67F */  sq         $22, 0x80($29)
    /* 1BE544 002BE544 7000B57F */  sq         $21, 0x70($29)
    /* 1BE548 002BE548 6000B47F */  sq         $20, 0x60($29)
    /* 1BE54C 002BE54C 5000B37F */  sq         $19, 0x50($29)
    /* 1BE550 002BE550 4000B27F */  sq         $18, 0x40($29)
    /* 1BE554 002BE554 3000B17F */  sq         $17, 0x30($29)
    /* 1BE558 002BE558 2000B07F */  sq         $16, 0x20($29)
    /* 1BE55C 002BE55C 1400B5E7 */  swc1       $f21, 0x14($29)
    /* 1BE560 002BE560 1000B4E7 */  swc1       $f20, 0x10($29)
    /* 1BE564 002BE564 2DA08000 */  daddu      $20, $4, $0
    /* 1BE568 002BE568 3800918C */  lw         $17, 0x38($4)
    /* 1BE56C 002BE56C 2D980000 */  daddu      $19, $0, $0
    /* 1BE570 002BE570 6482110C */  jal        func_00460990
    /* 1BE574 002BE574 00000000 */   nop
    /* 1BE578 002BE578 2D284000 */  daddu      $5, $2, $0
    /* 1BE57C 002BE57C 2C00033C */  lui        $3, %hi(func_002be4a0)
    /* 1BE580 002BE580 A0E46324 */  addiu      $3, $3, %lo(func_002be4a0)
    /* 1BE584 002BE584 080043AC */  sw         $3, 0x8($2)
    /* 1BE588 002BE588 100051AC */  sw         $17, 0x10($2)
    /* 1BE58C 002BE58C 7900043C */  lui        $4, %hi(D_00795FE0)
    /* 1BE590 002BE590 E05F8424 */  addiu      $4, $4, %lo(D_00795FE0)
    /* 1BE594 002BE594 B082110C */  jal        func_00460ac0
    /* 1BE598 002BE598 00000000 */   nop
    /* 1BE59C 002BE59C 00002282 */  lb         $2, 0x0($17)
    /* 1BE5A0 002BE5A0 F7FF4224 */  addiu      $2, $2, -0x9
    /* 1BE5A4 002BE5A4 2F00412C */  sltiu      $1, $2, 0x2F
    /* 1BE5A8 002BE5A8 5F302010 */  beqz       $1, .L002CA728
    /* 1BE5AC 002BE5AC 00000000 */   nop
    /* 1BE5B0 002BE5B0 7500033C */  lui        $3, %hi(jtbl_00748930)
    /* 1BE5B4 002BE5B4 30896324 */  addiu      $3, $3, %lo(jtbl_00748930)
    /* 1BE5B8 002BE5B8 80100200 */  sll        $2, $2, 2
    /* 1BE5BC 002BE5BC 21104300 */  addu       $2, $2, $3
    /* 1BE5C0 002BE5C0 0000428C */  lw         $2, 0x0($2)
    /* 1BE5C4 002BE5C4 08004000 */  jr         $2
    /* 1BE5C8 002BE5C8 00000000 */   nop
    /* 1BE5CC 002BE5CC 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1BE5D0 002BE5D0 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1BE5D4 002BE5D4 A8AB110C */  jal        func_0046aea0
    /* 1BE5D8 002BE5D8 00000000 */   nop
    /* 1BE5DC 002BE5DC 280F22AE */  sw         $2, 0xF28($17)
    /* 1BE5E0 002BE5E0 78A88427 */  addiu      $4, $28, -0x5788
    /* 1BE5E4 002BE5E4 6400053C */  lui        $5, %hi(D_0063FAC0)
    /* 1BE5E8 002BE5E8 C0FAA524 */  addiu      $5, $5, %lo(D_0063FAC0)
    /* 1BE5EC 002BE5EC 47010624 */  addiu      $6, $0, 0x147
    /* 1BE5F0 002BE5F0 DA02110C */  jal        func_00440b68
    /* 1BE5F4 002BE5F4 00000000 */   nop
    /* 1BE5F8 002BE5F8 6400043C */  lui        $4, %hi(D_0063FAD0)
    /* 1BE5FC 002BE5FC D0FA8424 */  addiu      $4, $4, %lo(D_0063FAD0)
    /* 1BE600 002BE600 2D280000 */  daddu      $5, $0, $0
    /* 1BE604 002BE604 9852110C */  jal        func_00454a60
    /* 1BE608 002BE608 00000000 */   nop
    /* 1BE60C 002BE60C 2C0F22AE */  sw         $2, 0xF2C($17)
    /* 1BE610 002BE610 0A000224 */  addiu      $2, $0, 0xA
    /* 1BE614 002BE614 000022A2 */  sb         $2, 0x0($17)
    /* 1BE618 002BE618 280F248E */  lw         $4, 0xF28($17)
    /* 1BE61C 002BE61C D4A9110C */  jal        func_0046a750
    /* 1BE620 002BE620 00000000 */   nop
    /* 1BE624 002BE624 40304010 */  beqz       $2, .L002CA728
    /* 1BE628 002BE628 00000000 */   nop
    /* 1BE62C 002BE62C 2C0F248E */  lw         $4, 0xF2C($17)
    /* 1BE630 002BE630 F054110C */  jal        func_004553c0
    /* 1BE634 002BE634 00000000 */   nop
    /* 1BE638 002BE638 3B304010 */  beqz       $2, .L002CA728
    /* 1BE63C 002BE63C 00000000 */   nop
    /* 1BE640 002BE640 0B000224 */  addiu      $2, $0, 0xB
    /* 1BE644 002BE644 000022A2 */  sb         $2, 0x0($17)
    /* 1BE648 002BE648 01000224 */  addiu      $2, $0, 0x1
    /* 1BE64C 002BE64C 300F22A2 */  sb         $2, 0xF30($17)
    /* 1BE650 002BE650 2D800000 */  daddu      $16, $0, $0
    /* 1BE654 002BE654 0C000010 */  b          .L002BE688
    /* 1BE658 002BE658 00000000 */   nop
  .L002BE65C:
    /* 1BE65C 002BE65C 2D208002 */  daddu      $4, $20, $0
    /* 1BE660 002BE660 2D280002 */  daddu      $5, $16, $0
    /* 1BE664 002BE664 280F268E */  lw         $6, 0xF28($17)
    /* 1BE668 002BE668 C0800B0C */  jal        func_002e0300
    /* 1BE66C 002BE66C 00000000 */   nop
    /* 1BE670 002BE670 80181200 */  sll        $3, $18, 2
    /* 1BE674 002BE674 21182302 */  addu       $3, $17, $3
    /* 1BE678 002BE678 380C62AC */  sw         $2, 0xC38($3)
    /* 1BE67C 002BE67C 01000226 */  addiu      $2, $16, 0x1
    /* 1BE680 002BE680 3C840200 */  dsll32     $16, $2, 16
    /* 1BE684 002BE684 3F841000 */  dsra32     $16, $16, 16
  .L002BE688:
    /* 1BE688 002BE688 3C941000 */  dsll32     $18, $16, 16
    /* 1BE68C 002BE68C 3F941200 */  dsra32     $18, $18, 16
    /* 1BE690 002BE690 9100422A */  slti       $2, $18, 0x91
    /* 1BE694 002BE694 F1FF4014 */  bnez       $2, .L002BE65C
    /* 1BE698 002BE698 00000000 */   nop
    /* 1BE69C 002BE69C 2D208002 */  daddu      $4, $20, $0
    /* 1BE6A0 002BE6A0 06000524 */  addiu      $5, $0, 0x6
    /* 1BE6A4 002BE6A4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE6A8 002BE6A8 C0800B0C */  jal        func_002e0300
    /* 1BE6AC 002BE6AC 00000000 */   nop
    /* 1BE6B0 002BE6B0 7C0E22AE */  sw         $2, 0xE7C($17)
    /* 1BE6B4 002BE6B4 2D208002 */  daddu      $4, $20, $0
    /* 1BE6B8 002BE6B8 0A000524 */  addiu      $5, $0, 0xA
    /* 1BE6BC 002BE6BC 280F268E */  lw         $6, 0xF28($17)
    /* 1BE6C0 002BE6C0 C0800B0C */  jal        func_002e0300
    /* 1BE6C4 002BE6C4 00000000 */   nop
    /* 1BE6C8 002BE6C8 800E22AE */  sw         $2, 0xE80($17)
    /* 1BE6CC 002BE6CC 2D208002 */  daddu      $4, $20, $0
    /* 1BE6D0 002BE6D0 1D000524 */  addiu      $5, $0, 0x1D
    /* 1BE6D4 002BE6D4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE6D8 002BE6D8 C0800B0C */  jal        func_002e0300
    /* 1BE6DC 002BE6DC 00000000 */   nop
    /* 1BE6E0 002BE6E0 840E22AE */  sw         $2, 0xE84($17)
    /* 1BE6E4 002BE6E4 2D800000 */  daddu      $16, $0, $0
    /* 1BE6E8 002BE6E8 10000010 */  b          .L002BE72C
    /* 1BE6EC 002BE6EC 00000000 */   nop
  .L002BE6F0:
    /* 1BE6F0 002BE6F0 3C941000 */  dsll32     $18, $16, 16
    /* 1BE6F4 002BE6F4 3F941200 */  dsra32     $18, $18, 16
    /* 1BE6F8 002BE6F8 61004226 */  addiu      $2, $18, 0x61
    /* 1BE6FC 002BE6FC 3C2C0200 */  dsll32     $5, $2, 16
    /* 1BE700 002BE700 3F2C0500 */  dsra32     $5, $5, 16
    /* 1BE704 002BE704 2D208002 */  daddu      $4, $20, $0
    /* 1BE708 002BE708 280F268E */  lw         $6, 0xF28($17)
    /* 1BE70C 002BE70C C0800B0C */  jal        func_002e0300
    /* 1BE710 002BE710 00000000 */   nop
    /* 1BE714 002BE714 80181200 */  sll        $3, $18, 2
    /* 1BE718 002BE718 21182302 */  addu       $3, $17, $3
    /* 1BE71C 002BE71C 880E62AC */  sw         $2, 0xE88($3)
    /* 1BE720 002BE720 01000226 */  addiu      $2, $16, 0x1
    /* 1BE724 002BE724 3C840200 */  dsll32     $16, $2, 16
    /* 1BE728 002BE728 3F841000 */  dsra32     $16, $16, 16
  .L002BE72C:
    /* 1BE72C 002BE72C 3C141000 */  dsll32     $2, $16, 16
    /* 1BE730 002BE730 3F140200 */  dsra32     $2, $2, 16
    /* 1BE734 002BE734 03004228 */  slti       $2, $2, 0x3
    /* 1BE738 002BE738 EDFF4014 */  bnez       $2, .L002BE6F0
    /* 1BE73C 002BE73C 00000000 */   nop
    /* 1BE740 002BE740 2D800000 */  daddu      $16, $0, $0
    /* 1BE744 002BE744 10000010 */  b          .L002BE788
    /* 1BE748 002BE748 00000000 */   nop
  .L002BE74C:
    /* 1BE74C 002BE74C 3C941000 */  dsll32     $18, $16, 16
    /* 1BE750 002BE750 3F941200 */  dsra32     $18, $18, 16
    /* 1BE754 002BE754 19004226 */  addiu      $2, $18, 0x19
    /* 1BE758 002BE758 3C2C0200 */  dsll32     $5, $2, 16
    /* 1BE75C 002BE75C 3F2C0500 */  dsra32     $5, $5, 16
    /* 1BE760 002BE760 2D208002 */  daddu      $4, $20, $0
    /* 1BE764 002BE764 280F268E */  lw         $6, 0xF28($17)
    /* 1BE768 002BE768 C0800B0C */  jal        func_002e0300
    /* 1BE76C 002BE76C 00000000 */   nop
    /* 1BE770 002BE770 80181200 */  sll        $3, $18, 2
    /* 1BE774 002BE774 21182302 */  addu       $3, $17, $3
    /* 1BE778 002BE778 940E62AC */  sw         $2, 0xE94($3)
    /* 1BE77C 002BE77C 01000226 */  addiu      $2, $16, 0x1
    /* 1BE780 002BE780 3C840200 */  dsll32     $16, $2, 16
    /* 1BE784 002BE784 3F841000 */  dsra32     $16, $16, 16
  .L002BE788:
    /* 1BE788 002BE788 3C141000 */  dsll32     $2, $16, 16
    /* 1BE78C 002BE78C 3F140200 */  dsra32     $2, $2, 16
    /* 1BE790 002BE790 04004228 */  slti       $2, $2, 0x4
    /* 1BE794 002BE794 EDFF4014 */  bnez       $2, .L002BE74C
    /* 1BE798 002BE798 00000000 */   nop
    /* 1BE79C 002BE79C 2D208002 */  daddu      $4, $20, $0
    /* 1BE7A0 002BE7A0 1D000524 */  addiu      $5, $0, 0x1D
    /* 1BE7A4 002BE7A4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE7A8 002BE7A8 C0800B0C */  jal        func_002e0300
    /* 1BE7AC 002BE7AC 00000000 */   nop
    /* 1BE7B0 002BE7B0 A40E22AE */  sw         $2, 0xEA4($17)
    /* 1BE7B4 002BE7B4 2D208002 */  daddu      $4, $20, $0
    /* 1BE7B8 002BE7B8 1D000524 */  addiu      $5, $0, 0x1D
    /* 1BE7BC 002BE7BC 280F268E */  lw         $6, 0xF28($17)
    /* 1BE7C0 002BE7C0 C0800B0C */  jal        func_002e0300
    /* 1BE7C4 002BE7C4 00000000 */   nop
    /* 1BE7C8 002BE7C8 A80E22AE */  sw         $2, 0xEA8($17)
    /* 1BE7CC 002BE7CC 2D208002 */  daddu      $4, $20, $0
    /* 1BE7D0 002BE7D0 20000524 */  addiu      $5, $0, 0x20
    /* 1BE7D4 002BE7D4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE7D8 002BE7D8 C0800B0C */  jal        func_002e0300
    /* 1BE7DC 002BE7DC 00000000 */   nop
    /* 1BE7E0 002BE7E0 AC0E22AE */  sw         $2, 0xEAC($17)
    /* 1BE7E4 002BE7E4 2D208002 */  daddu      $4, $20, $0
    /* 1BE7E8 002BE7E8 21000524 */  addiu      $5, $0, 0x21
    /* 1BE7EC 002BE7EC 280F268E */  lw         $6, 0xF28($17)
    /* 1BE7F0 002BE7F0 C0800B0C */  jal        func_002e0300
    /* 1BE7F4 002BE7F4 00000000 */   nop
    /* 1BE7F8 002BE7F8 B00E22AE */  sw         $2, 0xEB0($17)
    /* 1BE7FC 002BE7FC 2D208002 */  daddu      $4, $20, $0
    /* 1BE800 002BE800 03000524 */  addiu      $5, $0, 0x3
    /* 1BE804 002BE804 280F268E */  lw         $6, 0xF28($17)
    /* 1BE808 002BE808 C0800B0C */  jal        func_002e0300
    /* 1BE80C 002BE80C 00000000 */   nop
    /* 1BE810 002BE810 B40E22AE */  sw         $2, 0xEB4($17)
    /* 1BE814 002BE814 2D208002 */  daddu      $4, $20, $0
    /* 1BE818 002BE818 04000524 */  addiu      $5, $0, 0x4
    /* 1BE81C 002BE81C 280F268E */  lw         $6, 0xF28($17)
    /* 1BE820 002BE820 C0800B0C */  jal        func_002e0300
    /* 1BE824 002BE824 00000000 */   nop
    /* 1BE828 002BE828 B80E22AE */  sw         $2, 0xEB8($17)
    /* 1BE82C 002BE82C 2D208002 */  daddu      $4, $20, $0
    /* 1BE830 002BE830 03000524 */  addiu      $5, $0, 0x3
    /* 1BE834 002BE834 280F268E */  lw         $6, 0xF28($17)
    /* 1BE838 002BE838 C0800B0C */  jal        func_002e0300
    /* 1BE83C 002BE83C 00000000 */   nop
    /* 1BE840 002BE840 BC0E22AE */  sw         $2, 0xEBC($17)
    /* 1BE844 002BE844 2D208002 */  daddu      $4, $20, $0
    /* 1BE848 002BE848 04000524 */  addiu      $5, $0, 0x4
    /* 1BE84C 002BE84C 280F268E */  lw         $6, 0xF28($17)
    /* 1BE850 002BE850 C0800B0C */  jal        func_002e0300
    /* 1BE854 002BE854 00000000 */   nop
    /* 1BE858 002BE858 C00E22AE */  sw         $2, 0xEC0($17)
    /* 1BE85C 002BE85C 2D208002 */  daddu      $4, $20, $0
    /* 1BE860 002BE860 03000524 */  addiu      $5, $0, 0x3
    /* 1BE864 002BE864 280F268E */  lw         $6, 0xF28($17)
    /* 1BE868 002BE868 C0800B0C */  jal        func_002e0300
    /* 1BE86C 002BE86C 00000000 */   nop
    /* 1BE870 002BE870 C40E22AE */  sw         $2, 0xEC4($17)
    /* 1BE874 002BE874 2D208002 */  daddu      $4, $20, $0
    /* 1BE878 002BE878 04000524 */  addiu      $5, $0, 0x4
    /* 1BE87C 002BE87C 280F268E */  lw         $6, 0xF28($17)
    /* 1BE880 002BE880 C0800B0C */  jal        func_002e0300
    /* 1BE884 002BE884 00000000 */   nop
    /* 1BE888 002BE888 C80E22AE */  sw         $2, 0xEC8($17)
    /* 1BE88C 002BE88C 2D208002 */  daddu      $4, $20, $0
    /* 1BE890 002BE890 03000524 */  addiu      $5, $0, 0x3
    /* 1BE894 002BE894 280F268E */  lw         $6, 0xF28($17)
    /* 1BE898 002BE898 C0800B0C */  jal        func_002e0300
    /* 1BE89C 002BE89C 00000000 */   nop
    /* 1BE8A0 002BE8A0 D40E22AE */  sw         $2, 0xED4($17)
    /* 1BE8A4 002BE8A4 2D208002 */  daddu      $4, $20, $0
    /* 1BE8A8 002BE8A8 04000524 */  addiu      $5, $0, 0x4
    /* 1BE8AC 002BE8AC 280F268E */  lw         $6, 0xF28($17)
    /* 1BE8B0 002BE8B0 C0800B0C */  jal        func_002e0300
    /* 1BE8B4 002BE8B4 00000000 */   nop
    /* 1BE8B8 002BE8B8 D80E22AE */  sw         $2, 0xED8($17)
    /* 1BE8BC 002BE8BC 2D208002 */  daddu      $4, $20, $0
    /* 1BE8C0 002BE8C0 05000524 */  addiu      $5, $0, 0x5
    /* 1BE8C4 002BE8C4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE8C8 002BE8C8 C0800B0C */  jal        func_002e0300
    /* 1BE8CC 002BE8CC 00000000 */   nop
    /* 1BE8D0 002BE8D0 CC0E22AE */  sw         $2, 0xECC($17)
    /* 1BE8D4 002BE8D4 2D208002 */  daddu      $4, $20, $0
    /* 1BE8D8 002BE8D8 2B000524 */  addiu      $5, $0, 0x2B
    /* 1BE8DC 002BE8DC 280F268E */  lw         $6, 0xF28($17)
    /* 1BE8E0 002BE8E0 C0800B0C */  jal        func_002e0300
    /* 1BE8E4 002BE8E4 00000000 */   nop
    /* 1BE8E8 002BE8E8 DC0E22AE */  sw         $2, 0xEDC($17)
    /* 1BE8EC 002BE8EC 2D208002 */  daddu      $4, $20, $0
    /* 1BE8F0 002BE8F0 2C000524 */  addiu      $5, $0, 0x2C
    /* 1BE8F4 002BE8F4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE8F8 002BE8F8 C0800B0C */  jal        func_002e0300
    /* 1BE8FC 002BE8FC 00000000 */   nop
    /* 1BE900 002BE900 E00E22AE */  sw         $2, 0xEE0($17)
    /* 1BE904 002BE904 2D208002 */  daddu      $4, $20, $0
    /* 1BE908 002BE908 5F000524 */  addiu      $5, $0, 0x5F
    /* 1BE90C 002BE90C 280F268E */  lw         $6, 0xF28($17)
    /* 1BE910 002BE910 C0800B0C */  jal        func_002e0300
    /* 1BE914 002BE914 00000000 */   nop
    /* 1BE918 002BE918 D00E22AE */  sw         $2, 0xED0($17)
    /* 1BE91C 002BE91C 2D208002 */  daddu      $4, $20, $0
    /* 1BE920 002BE920 5F000524 */  addiu      $5, $0, 0x5F
    /* 1BE924 002BE924 280F268E */  lw         $6, 0xF28($17)
    /* 1BE928 002BE928 C0800B0C */  jal        func_002e0300
    /* 1BE92C 002BE92C 00000000 */   nop
    /* 1BE930 002BE930 140F22AE */  sw         $2, 0xF14($17)
    /* 1BE934 002BE934 2D208002 */  daddu      $4, $20, $0
    /* 1BE938 002BE938 65000524 */  addiu      $5, $0, 0x65
    /* 1BE93C 002BE93C 280F268E */  lw         $6, 0xF28($17)
    /* 1BE940 002BE940 C0800B0C */  jal        func_002e0300
    /* 1BE944 002BE944 00000000 */   nop
    /* 1BE948 002BE948 E40E22AE */  sw         $2, 0xEE4($17)
    /* 1BE94C 002BE94C 2D208002 */  daddu      $4, $20, $0
    /* 1BE950 002BE950 66000524 */  addiu      $5, $0, 0x66
    /* 1BE954 002BE954 280F268E */  lw         $6, 0xF28($17)
    /* 1BE958 002BE958 C0800B0C */  jal        func_002e0300
    /* 1BE95C 002BE95C 00000000 */   nop
    /* 1BE960 002BE960 E80E22AE */  sw         $2, 0xEE8($17)
    /* 1BE964 002BE964 2D208002 */  daddu      $4, $20, $0
    /* 1BE968 002BE968 0A000524 */  addiu      $5, $0, 0xA
    /* 1BE96C 002BE96C 280F268E */  lw         $6, 0xF28($17)
    /* 1BE970 002BE970 C0800B0C */  jal        func_002e0300
    /* 1BE974 002BE974 00000000 */   nop
    /* 1BE978 002BE978 EC0E22AE */  sw         $2, 0xEEC($17)
    /* 1BE97C 002BE97C 2D208002 */  daddu      $4, $20, $0
    /* 1BE980 002BE980 0A000524 */  addiu      $5, $0, 0xA
    /* 1BE984 002BE984 280F268E */  lw         $6, 0xF28($17)
    /* 1BE988 002BE988 C0800B0C */  jal        func_002e0300
    /* 1BE98C 002BE98C 00000000 */   nop
    /* 1BE990 002BE990 F00E22AE */  sw         $2, 0xEF0($17)
    /* 1BE994 002BE994 2D208002 */  daddu      $4, $20, $0
    /* 1BE998 002BE998 12000524 */  addiu      $5, $0, 0x12
    /* 1BE99C 002BE99C 280F268E */  lw         $6, 0xF28($17)
    /* 1BE9A0 002BE9A0 C0800B0C */  jal        func_002e0300
    /* 1BE9A4 002BE9A4 00000000 */   nop
    /* 1BE9A8 002BE9A8 F40E22AE */  sw         $2, 0xEF4($17)
    /* 1BE9AC 002BE9AC 2D208002 */  daddu      $4, $20, $0
    /* 1BE9B0 002BE9B0 0E000524 */  addiu      $5, $0, 0xE
    /* 1BE9B4 002BE9B4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE9B8 002BE9B8 C0800B0C */  jal        func_002e0300
    /* 1BE9BC 002BE9BC 00000000 */   nop
    /* 1BE9C0 002BE9C0 F80E22AE */  sw         $2, 0xEF8($17)
    /* 1BE9C4 002BE9C4 2D208002 */  daddu      $4, $20, $0
    /* 1BE9C8 002BE9C8 13000524 */  addiu      $5, $0, 0x13
    /* 1BE9CC 002BE9CC 280F268E */  lw         $6, 0xF28($17)
    /* 1BE9D0 002BE9D0 C0800B0C */  jal        func_002e0300
    /* 1BE9D4 002BE9D4 00000000 */   nop
    /* 1BE9D8 002BE9D8 FC0E22AE */  sw         $2, 0xEFC($17)
    /* 1BE9DC 002BE9DC 2D208002 */  daddu      $4, $20, $0
    /* 1BE9E0 002BE9E0 0F000524 */  addiu      $5, $0, 0xF
    /* 1BE9E4 002BE9E4 280F268E */  lw         $6, 0xF28($17)
    /* 1BE9E8 002BE9E8 C0800B0C */  jal        func_002e0300
    /* 1BE9EC 002BE9EC 00000000 */   nop
    /* 1BE9F0 002BE9F0 000F22AE */  sw         $2, 0xF00($17)
    /* 1BE9F4 002BE9F4 2D208002 */  daddu      $4, $20, $0
    /* 1BE9F8 002BE9F8 10000524 */  addiu      $5, $0, 0x10
    /* 1BE9FC 002BE9FC 280F268E */  lw         $6, 0xF28($17)
    /* 1BEA00 002BEA00 C0800B0C */  jal        func_002e0300
    /* 1BEA04 002BEA04 00000000 */   nop
    /* 1BEA08 002BEA08 040F22AE */  sw         $2, 0xF04($17)
    /* 1BEA0C 002BEA0C 2D208002 */  daddu      $4, $20, $0
    /* 1BEA10 002BEA10 8C000524 */  addiu      $5, $0, 0x8C
    /* 1BEA14 002BEA14 280F268E */  lw         $6, 0xF28($17)
    /* 1BEA18 002BEA18 C0800B0C */  jal        func_002e0300
    /* 1BEA1C 002BEA1C 00000000 */   nop
    /* 1BEA20 002BEA20 080F22AE */  sw         $2, 0xF08($17)
    /* 1BEA24 002BEA24 2D208002 */  daddu      $4, $20, $0
    /* 1BEA28 002BEA28 8D000524 */  addiu      $5, $0, 0x8D
    /* 1BEA2C 002BEA2C 280F268E */  lw         $6, 0xF28($17)
    /* 1BEA30 002BEA30 C0800B0C */  jal        func_002e0300
    /* 1BEA34 002BEA34 00000000 */   nop
    /* 1BEA38 002BEA38 0C0F22AE */  sw         $2, 0xF0C($17)
    /* 1BEA3C 002BEA3C 2D208002 */  daddu      $4, $20, $0
    /* 1BEA40 002BEA40 8E000524 */  addiu      $5, $0, 0x8E
    /* 1BEA44 002BEA44 280F268E */  lw         $6, 0xF28($17)
    /* 1BEA48 002BEA48 C0800B0C */  jal        func_002e0300
    /* 1BEA4C 002BEA4C 00000000 */   nop
    /* 1BEA50 002BEA50 100F22AE */  sw         $2, 0xF10($17)
    /* 1BEA54 002BEA54 280F248E */  lw         $4, 0xF28($17)
    /* 1BEA58 002BEA58 48000524 */  addiu      $5, $0, 0x48
    /* 1BEA5C 002BEA5C 80B4110C */  jal        func_0046d200
    /* 1BEA60 002BEA60 00000000 */   nop
    /* 1BEA64 002BEA64 2D804000 */  daddu      $16, $2, $0
    /* 1BEA68 002BEA68 2D200002 */  daddu      $4, $16, $0
    /* 1BEA6C 002BEA6C 98AC110C */  jal        func_0046b260
    /* 1BEA70 002BEA70 00000000 */   nop
    /* 1BEA74 002BEA74 1E44023C */  lui        $2, (0x441E0000 >> 16)
    /* 1BEA78 002BEA78 00088244 */  mtc1       $2, $f1
    /* 1BEA7C 002BEA7C 00000000 */  nop
    /* 1BEA80 002BEA80 400D0046 */  add.s      $f21, $f1, $f0
    /* 1BEA84 002BEA84 2D200002 */  daddu      $4, $16, $0
    /* 1BEA88 002BEA88 A0B4110C */  jal        func_0046d280
    /* 1BEA8C 002BEA8C 00000000 */   nop
    /* 1BEA90 002BEA90 280F248E */  lw         $4, 0xF28($17)
    /* 1BEA94 002BEA94 47000524 */  addiu      $5, $0, 0x47
    /* 1BEA98 002BEA98 80B4110C */  jal        func_0046d200
    /* 1BEA9C 002BEA9C 00000000 */   nop
    /* 1BEAA0 002BEAA0 2D804000 */  daddu      $16, $2, $0
    /* 1BEAA4 002BEAA4 2D200002 */  daddu      $4, $16, $0
    /* 1BEAA8 002BEAA8 BCAC110C */  jal        func_0046b2f0
    /* 1BEAAC 002BEAAC 00000000 */   nop
    /* 1BEAB0 002BEAB0 0843023C */  lui        $2, (0x43080000 >> 16)
    /* 1BEAB4 002BEAB4 00088244 */  mtc1       $2, $f1
    /* 1BEAB8 002BEAB8 00000000 */  nop
    /* 1BEABC 002BEABC 000D0046 */  add.s      $f20, $f1, $f0
    /* 1BEAC0 002BEAC0 2D200002 */  daddu      $4, $16, $0
    /* 1BEAC4 002BEAC4 A0B4110C */  jal        func_0046d280
    /* 1BEAC8 002BEAC8 00000000 */   nop
    /* 1BEACC 002BEACC A3010224 */  addiu      $2, $0, 0x1A3
    /* 1BEAD0 002BEAD0 00008244 */  mtc1       $2, $f0
    /* 1BEAD4 002BEAD4 00000000 */  nop
    /* 1BEAD8 002BEAD8 60008046 */  cvt.s.w    $f1, $f0
    /* 1BEADC 002BEADC 01A80146 */  sub.s      $f0, $f21, $f1
    /* 1BEAE0 002BEAE0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1BEAE4 002BEAE4 00108244 */  mtc1       $2, $f2
    /* 1BEAE8 002BEAE8 00000000 */  nop
    /* 1BEAEC 002BEAEC 03000246 */  div.s      $f0, $f0, $f2
    /* 1BEAF0 002BEAF0 00080046 */  add.s      $f0, $f1, $f0
    /* 1BEAF4 002BEAF4 340F20E6 */  swc1       $f0, 0xF34($17)
    /* 1BEAF8 002BEAF8 8242023C */  lui        $2, (0x42820000 >> 16)
    /* 1BEAFC 002BEAFC 00088244 */  mtc1       $2, $f1
    /* 1BEB00 002BEB00 00000000 */  nop
    /* 1BEB04 002BEB04 01A00146 */  sub.s      $f0, $f20, $f1
    /* 1BEB08 002BEB08 03000246 */  div.s      $f0, $f0, $f2
    /* 1BEB0C 002BEB0C 00080046 */  add.s      $f0, $f1, $f0
    /* 1BEB10 002BEB10 380F20E6 */  swc1       $f0, 0xF38($17)
    /* 1BEB14 002BEB14 01000424 */  addiu      $4, $0, 0x1
    /* 1BEB18 002BEB18 730F24A2 */  sb         $4, 0xF73($17)
    /* 1BEB1C 002BEB1C 2D280000 */  daddu      $5, $0, $0
    /* 1BEB20 002BEB20 341B040C */  jal        func_00106cd0
    /* 1BEB24 002BEB24 00000000 */   nop
    /* 1BEB28 002BEB28 2D204000 */  daddu      $4, $2, $0
    /* 1BEB2C 002BEB2C 201A040C */  jal        func_00106880
    /* 1BEB30 002BEB30 00000000 */   nop
    /* 1BEB34 002BEB34 3C240200 */  dsll32     $4, $2, 16
    /* 1BEB38 002BEB38 3F240400 */  dsra32     $4, $4, 16
    /* 1BEB3C 002BEB3C CC530B0C */  jal        func_002d4f30
    /* 1BEB40 002BEB40 00000000 */   nop
    /* 1BEB44 002BEB44 7C0F22A2 */  sb         $2, 0xF7C($17)
    /* 1BEB48 002BEB48 01000224 */  addiu      $2, $0, 0x1
    /* 1BEB4C 002BEB4C 090022A2 */  sb         $2, 0x9($17)
    /* 1BEB50 002BEB50 30000424 */  addiu      $4, $0, 0x30
    /* 1BEB54 002BEB54 CC18040C */  jal        func_00106330
    /* 1BEB58 002BEB58 00000000 */   nop
    /* 1BEB5C 002BEB5C 18004010 */  beqz       $2, .L002BEBC0
    /* 1BEB60 002BEB60 00000000 */   nop
    /* 1BEB64 002BEB64 02000324 */  addiu      $3, $0, 0x2
    /* 1BEB68 002BEB68 09002282 */  lb         $2, 0x9($17)
    /* 1BEB6C 002BEB6C 21105100 */  addu       $2, $2, $17
    /* 1BEB70 002BEB70 730F43A0 */  sb         $3, 0xF73($2)
    /* 1BEB74 002BEB74 09002282 */  lb         $2, 0x9($17)
    /* 1BEB78 002BEB78 21105100 */  addu       $2, $2, $17
    /* 1BEB7C 002BEB7C 730F4480 */  lb         $4, 0xF73($2)
    /* 1BEB80 002BEB80 2D280000 */  daddu      $5, $0, $0
    /* 1BEB84 002BEB84 341B040C */  jal        func_00106cd0
    /* 1BEB88 002BEB88 00000000 */   nop
    /* 1BEB8C 002BEB8C 2D204000 */  daddu      $4, $2, $0
    /* 1BEB90 002BEB90 201A040C */  jal        func_00106880
    /* 1BEB94 002BEB94 00000000 */   nop
    /* 1BEB98 002BEB98 3C240200 */  dsll32     $4, $2, 16
    /* 1BEB9C 002BEB9C 3F240400 */  dsra32     $4, $4, 16
    /* 1BEBA0 002BEBA0 CC530B0C */  jal        func_002d4f30
    /* 1BEBA4 002BEBA4 00000000 */   nop
    /* 1BEBA8 002BEBA8 09002382 */  lb         $3, 0x9($17)
    /* 1BEBAC 002BEBAC 21187100 */  addu       $3, $3, $17
    /* 1BEBB0 002BEBB0 7C0F62A0 */  sb         $2, 0xF7C($3)
    /* 1BEBB4 002BEBB4 09002282 */  lb         $2, 0x9($17)
    /* 1BEBB8 002BEBB8 01004224 */  addiu      $2, $2, 0x1
    /* 1BEBBC 002BEBBC 090022A2 */  sb         $2, 0x9($17)
  .L002BEBC0:
    /* 1BEBC0 002BEBC0 31000424 */  addiu      $4, $0, 0x31
    /* 1BEBC4 002BEBC4 CC18040C */  jal        func_00106330
    /* 1BEBC8 002BEBC8 00000000 */   nop
    /* 1BEBCC 002BEBCC 18004010 */  beqz       $2, .L002BEC30
    /* 1BEBD0 002BEBD0 00000000 */   nop
    /* 1BEBD4 002BEBD4 03000324 */  addiu      $3, $0, 0x3
    /* 1BEBD8 002BEBD8 09002282 */  lb         $2, 0x9($17)
    /* 1BEBDC 002BEBDC 21105100 */  addu       $2, $2, $17
    /* 1BEBE0 002BEBE0 730F43A0 */  sb         $3, 0xF73($2)
    /* 1BEBE4 002BEBE4 09002282 */  lb         $2, 0x9($17)
    /* 1BEBE8 002BEBE8 21105100 */  addu       $2, $2, $17
    /* 1BEBEC 002BEBEC 730F4480 */  lb         $4, 0xF73($2)
    /* 1BEBF0 002BEBF0 2D280000 */  daddu      $5, $0, $0
    /* 1BEBF4 002BEBF4 341B040C */  jal        func_00106cd0
    /* 1BEBF8 002BEBF8 00000000 */   nop
    /* 1BEBFC 002BEBFC 2D204000 */  daddu      $4, $2, $0
    /* 1BEC00 002BEC00 201A040C */  jal        func_00106880
    /* 1BEC04 002BEC04 00000000 */   nop
    /* 1BEC08 002BEC08 3C240200 */  dsll32     $4, $2, 16
    /* 1BEC0C 002BEC0C 3F240400 */  dsra32     $4, $4, 16
    /* 1BEC10 002BEC10 CC530B0C */  jal        func_002d4f30
    /* 1BEC14 002BEC14 00000000 */   nop
    /* 1BEC18 002BEC18 09002382 */  lb         $3, 0x9($17)
    /* 1BEC1C 002BEC1C 21187100 */  addu       $3, $3, $17
    /* 1BEC20 002BEC20 7C0F62A0 */  sb         $2, 0xF7C($3)
    /* 1BEC24 002BEC24 09002282 */  lb         $2, 0x9($17)
    /* 1BEC28 002BEC28 01004224 */  addiu      $2, $2, 0x1
    /* 1BEC2C 002BEC2C 090022A2 */  sb         $2, 0x9($17)
  .L002BEC30:
    /* 1BEC30 002BEC30 32000424 */  addiu      $4, $0, 0x32
    /* 1BEC34 002BEC34 CC18040C */  jal        func_00106330
    /* 1BEC38 002BEC38 00000000 */   nop
    /* 1BEC3C 002BEC3C 18004010 */  beqz       $2, .L002BECA0
    /* 1BEC40 002BEC40 00000000 */   nop
    /* 1BEC44 002BEC44 04000324 */  addiu      $3, $0, 0x4
    /* 1BEC48 002BEC48 09002282 */  lb         $2, 0x9($17)
    /* 1BEC4C 002BEC4C 21105100 */  addu       $2, $2, $17
    /* 1BEC50 002BEC50 730F43A0 */  sb         $3, 0xF73($2)
    /* 1BEC54 002BEC54 09002282 */  lb         $2, 0x9($17)
    /* 1BEC58 002BEC58 21105100 */  addu       $2, $2, $17
    /* 1BEC5C 002BEC5C 730F4480 */  lb         $4, 0xF73($2)
    /* 1BEC60 002BEC60 2D280000 */  daddu      $5, $0, $0
    /* 1BEC64 002BEC64 341B040C */  jal        func_00106cd0
    /* 1BEC68 002BEC68 00000000 */   nop
    /* 1BEC6C 002BEC6C 2D204000 */  daddu      $4, $2, $0
    /* 1BEC70 002BEC70 201A040C */  jal        func_00106880
    /* 1BEC74 002BEC74 00000000 */   nop
    /* 1BEC78 002BEC78 3C240200 */  dsll32     $4, $2, 16
    /* 1BEC7C 002BEC7C 3F240400 */  dsra32     $4, $4, 16
    /* 1BEC80 002BEC80 CC530B0C */  jal        func_002d4f30
    /* 1BEC84 002BEC84 00000000 */   nop
    /* 1BEC88 002BEC88 09002382 */  lb         $3, 0x9($17)
    /* 1BEC8C 002BEC8C 21187100 */  addu       $3, $3, $17
    /* 1BEC90 002BEC90 7C0F62A0 */  sb         $2, 0xF7C($3)
    /* 1BEC94 002BEC94 09002282 */  lb         $2, 0x9($17)
    /* 1BEC98 002BEC98 01004224 */  addiu      $2, $2, 0x1
    /* 1BEC9C 002BEC9C 090022A2 */  sb         $2, 0x9($17)
  .L002BECA0:
    /* 1BECA0 002BECA0 33000424 */  addiu      $4, $0, 0x33
    /* 1BECA4 002BECA4 CC18040C */  jal        func_00106330
    /* 1BECA8 002BECA8 00000000 */   nop
    /* 1BECAC 002BECAC 18004010 */  beqz       $2, .L002BED10
    /* 1BECB0 002BECB0 00000000 */   nop
    /* 1BECB4 002BECB4 06000324 */  addiu      $3, $0, 0x6
    /* 1BECB8 002BECB8 09002282 */  lb         $2, 0x9($17)
    /* 1BECBC 002BECBC 21105100 */  addu       $2, $2, $17
    /* 1BECC0 002BECC0 730F43A0 */  sb         $3, 0xF73($2)
    /* 1BECC4 002BECC4 09002282 */  lb         $2, 0x9($17)
    /* 1BECC8 002BECC8 21105100 */  addu       $2, $2, $17
    /* 1BECCC 002BECCC 730F4480 */  lb         $4, 0xF73($2)
    /* 1BECD0 002BECD0 2D280000 */  daddu      $5, $0, $0
    /* 1BECD4 002BECD4 341B040C */  jal        func_00106cd0
    /* 1BECD8 002BECD8 00000000 */   nop
    /* 1BECDC 002BECDC 2D204000 */  daddu      $4, $2, $0
    /* 1BECE0 002BECE0 201A040C */  jal        func_00106880
    /* 1BECE4 002BECE4 00000000 */   nop
    /* 1BECE8 002BECE8 3C240200 */  dsll32     $4, $2, 16
    /* 1BECEC 002BECEC 3F240400 */  dsra32     $4, $4, 16
    /* 1BECF0 002BECF0 CC530B0C */  jal        func_002d4f30
    /* 1BECF4 002BECF4 00000000 */   nop
    /* 1BECF8 002BECF8 09002382 */  lb         $3, 0x9($17)
    /* 1BECFC 002BECFC 21187100 */  addu       $3, $3, $17
    /* 1BED00 002BED00 7C0F62A0 */  sb         $2, 0xF7C($3)
    /* 1BED04 002BED04 09002282 */  lb         $2, 0x9($17)
    /* 1BED08 002BED08 01004224 */  addiu      $2, $2, 0x1
    /* 1BED0C 002BED0C 090022A2 */  sb         $2, 0x9($17)
  .L002BED10:
    /* 1BED10 002BED10 35000424 */  addiu      $4, $0, 0x35
    /* 1BED14 002BED14 CC18040C */  jal        func_00106330
    /* 1BED18 002BED18 00000000 */   nop
    /* 1BED1C 002BED1C 18004010 */  beqz       $2, .L002BED80
    /* 1BED20 002BED20 00000000 */   nop
    /* 1BED24 002BED24 08000324 */  addiu      $3, $0, 0x8
    /* 1BED28 002BED28 09002282 */  lb         $2, 0x9($17)
    /* 1BED2C 002BED2C 21105100 */  addu       $2, $2, $17
    /* 1BED30 002BED30 730F43A0 */  sb         $3, 0xF73($2)
    /* 1BED34 002BED34 09002282 */  lb         $2, 0x9($17)
    /* 1BED38 002BED38 21105100 */  addu       $2, $2, $17
    /* 1BED3C 002BED3C 730F4480 */  lb         $4, 0xF73($2)
    /* 1BED40 002BED40 2D280000 */  daddu      $5, $0, $0
    /* 1BED44 002BED44 341B040C */  jal        func_00106cd0
    /* 1BED48 002BED48 00000000 */   nop
    /* 1BED4C 002BED4C 2D204000 */  daddu      $4, $2, $0
    /* 1BED50 002BED50 201A040C */  jal        func_00106880
    /* 1BED54 002BED54 00000000 */   nop
    /* 1BED58 002BED58 3C240200 */  dsll32     $4, $2, 16
    /* 1BED5C 002BED5C 3F240400 */  dsra32     $4, $4, 16
    /* 1BED60 002BED60 CC530B0C */  jal        func_002d4f30
    /* 1BED64 002BED64 00000000 */   nop
    /* 1BED68 002BED68 09002382 */  lb         $3, 0x9($17)
    /* 1BED6C 002BED6C 21187100 */  addu       $3, $3, $17
    /* 1BED70 002BED70 7C0F62A0 */  sb         $2, 0xF7C($3)
    /* 1BED74 002BED74 09002282 */  lb         $2, 0x9($17)
    /* 1BED78 002BED78 01004224 */  addiu      $2, $2, 0x1
    /* 1BED7C 002BED7C 090022A2 */  sb         $2, 0x9($17)
  .L002BED80:
    /* 1BED80 002BED80 36000424 */  addiu      $4, $0, 0x36
    /* 1BED84 002BED84 CC18040C */  jal        func_00106330
    /* 1BED88 002BED88 00000000 */   nop
    /* 1BED8C 002BED8C 18004010 */  beqz       $2, .L002BEDF0
    /* 1BED90 002BED90 00000000 */   nop
    /* 1BED94 002BED94 07000324 */  addiu      $3, $0, 0x7
    /* 1BED98 002BED98 09002282 */  lb         $2, 0x9($17)
    /* 1BED9C 002BED9C 21105100 */  addu       $2, $2, $17
    /* 1BEDA0 002BEDA0 730F43A0 */  sb         $3, 0xF73($2)
    /* 1BEDA4 002BEDA4 09002282 */  lb         $2, 0x9($17)
    /* 1BEDA8 002BEDA8 21105100 */  addu       $2, $2, $17
    /* 1BEDAC 002BEDAC 730F4480 */  lb         $4, 0xF73($2)
    /* 1BEDB0 002BEDB0 2D280000 */  daddu      $5, $0, $0
    /* 1BEDB4 002BEDB4 341B040C */  jal        func_00106cd0
    /* 1BEDB8 002BEDB8 00000000 */   nop
    /* 1BEDBC 002BEDBC 2D204000 */  daddu      $4, $2, $0
    /* 1BEDC0 002BEDC0 201A040C */  jal        func_00106880
    /* 1BEDC4 002BEDC4 00000000 */   nop
    /* 1BEDC8 002BEDC8 3C240200 */  dsll32     $4, $2, 16
    /* 1BEDCC 002BEDCC 3F240400 */  dsra32     $4, $4, 16
    /* 1BEDD0 002BEDD0 CC530B0C */  jal        func_002d4f30
    /* 1BEDD4 002BEDD4 00000000 */   nop
    /* 1BEDD8 002BEDD8 09002382 */  lb         $3, 0x9($17)
    /* 1BEDDC 002BEDDC 21187100 */  addu       $3, $3, $17
    /* 1BEDE0 002BEDE0 7C0F62A0 */  sb         $2, 0xF7C($3)
    /* 1BEDE4 002BEDE4 09002282 */  lb         $2, 0x9($17)
    /* 1BEDE8 002BEDE8 01004224 */  addiu      $2, $2, 0x1
    /* 1BEDEC 002BEDEC 090022A2 */  sb         $2, 0x9($17)
  .L002BEDF0:
    /* 1BEDF0 002BEDF0 2D280000 */  daddu      $5, $0, $0
    /* 1BEDF4 002BEDF4 0D000010 */  b          .L002BEE2C
    /* 1BEDF8 002BEDF8 00000000 */   nop
  .L002BEDFC:
    /* 1BEDFC 002BEDFC 3C240500 */  dsll32     $4, $5, 16
    /* 1BEE00 002BEE00 3F240400 */  dsra32     $4, $4, 16
    /* 1BEE04 002BEE04 40100400 */  sll        $2, $4, 1
    /* 1BEE08 002BEE08 21182202 */  addu       $3, $17, $2
    /* 1BEE0C 002BEE0C 21104400 */  addu       $2, $2, $4
    /* 1BEE10 002BEE10 460F62A4 */  sh         $2, 0xF46($3)
    /* 1BEE14 002BEE14 580F60A4 */  sh         $0, 0xF58($3)
    /* 1BEE18 002BEE18 21102402 */  addu       $2, $17, $4
    /* 1BEE1C 002BEE1C 6A0F40A0 */  sb         $0, 0xF6A($2)
    /* 1BEE20 002BEE20 0100A224 */  addiu      $2, $5, 0x1
    /* 1BEE24 002BEE24 3C2C0200 */  dsll32     $5, $2, 16
    /* 1BEE28 002BEE28 3F2C0500 */  dsra32     $5, $5, 16
  .L002BEE2C:
    /* 1BEE2C 002BEE2C 3C140500 */  dsll32     $2, $5, 16
    /* 1BEE30 002BEE30 3F140200 */  dsra32     $2, $2, 16
    /* 1BEE34 002BEE34 09004228 */  slti       $2, $2, 0x9
    /* 1BEE38 002BEE38 F0FF4014 */  bnez       $2, .L002BEDFC
    /* 1BEE3C 002BEE3C 00000000 */   nop
    /* 1BEE40 002BEE40 080020A2 */  sb         $0, 0x8($17)
    /* 1BEE44 002BEE44 382E0010 */  b          .L002CA728
    /* 1BEE48 002BEE48 00000000 */   nop
    /* 1BEE4C 002BEE4C 10002482 */  lb         $4, 0x10($17)
    /* 1BEE50 002BEE50 A0ED0A0C */  jal        func_002bb680
    /* 1BEE54 002BEE54 00000000 */   nop
    /* 1BEE58 002BEE58 06004010 */  beqz       $2, .L002BEE74
    /* 1BEE5C 002BEE5C 00000000 */   nop
    /* 1BEE60 002BEE60 10002482 */  lb         $4, 0x10($17)
    /* 1BEE64 002BEE64 3CEF0A0C */  jal        func_002bbcf0
    /* 1BEE68 002BEE68 00000000 */   nop
    /* 1BEE6C 002BEE6C 2E2E0010 */  b          .L002CA728
    /* 1BEE70 002BEE70 00000000 */   nop
  .L002BEE74:
    /* 1BEE74 002BEE74 10002482 */  lb         $4, 0x10($17)
    /* 1BEE78 002BEE78 54ED0A0C */  jal        func_002bb550
    /* 1BEE7C 002BEE7C 00000000 */   nop
    /* 1BEE80 002BEE80 24130424 */  addiu      $4, $0, 0x1324
    /* 1BEE84 002BEE84 01000524 */  addiu      $5, $0, 0x1
    /* 1BEE88 002BEE88 E418040C */  jal        func_00106390
    /* 1BEE8C 002BEE8C 00000000 */   nop
    /* 1BEE90 002BEE90 0D000224 */  addiu      $2, $0, 0xD
    /* 1BEE94 002BEE94 000022A2 */  sb         $2, 0x0($17)
    /* 1BEE98 002BEE98 232E0010 */  b          .L002CA728
    /* 1BEE9C 002BEE9C 00000000 */   nop
    /* 1BEEA0 002BEEA0 180F248E */  lw         $4, 0xF18($17)
    /* 1BEEA4 002BEEA4 BC890B0C */  jal        func_002e26f0
    /* 1BEEA8 002BEEA8 00000000 */   nop
    /* 1BEEAC 002BEEAC 7500033C */  lui        $3, %hi(D_00748908)
    /* 1BEEB0 002BEEB0 08896380 */  lb         $3, %lo(D_00748908)($3)
    /* 1BEEB4 002BEEB4 2A086200 */  slt        $1, $3, $2
    /* 1BEEB8 002BEEB8 15002010 */  beqz       $1, .L002BEF10
    /* 1BEEBC 002BEEBC 00000000 */   nop
    /* 1BEEC0 002BEEC0 24130424 */  addiu      $4, $0, 0x1324
    /* 1BEEC4 002BEEC4 CC18040C */  jal        func_00106330
    /* 1BEEC8 002BEEC8 00000000 */   nop
    /* 1BEECC 002BEECC 10004014 */  bnez       $2, .L002BEF10
    /* 1BEED0 002BEED0 00000000 */   nop
    /* 1BEED4 002BEED4 2C0F228E */  lw         $2, 0xF2C($17)
    /* 1BEED8 002BEED8 1001448C */  lw         $4, 0x110($2)
    /* 1BEEDC 002BEEDC E0EA0A0C */  jal        func_002bab80
    /* 1BEEE0 002BEEE0 00000000 */   nop
    /* 1BEEE4 002BEEE4 100022A2 */  sb         $2, 0x10($17)
    /* 1BEEE8 002BEEE8 3C260200 */  dsll32     $4, $2, 24
    /* 1BEEEC 002BEEEC 3F260400 */  dsra32     $4, $4, 24
    /* 1BEEF0 002BEEF0 0B000524 */  addiu      $5, $0, 0xB
    /* 1BEEF4 002BEEF4 A0EB0A0C */  jal        func_002bae80
    /* 1BEEF8 002BEEF8 00000000 */   nop
    /* 1BEEFC 002BEEFC 0C000224 */  addiu      $2, $0, 0xC
    /* 1BEF00 002BEF00 000022A2 */  sb         $2, 0x0($17)
    /* 1BEF04 002BEF04 2D100000 */  daddu      $2, $0, $0
    /* 1BEF08 002BEF08 082E0010 */  b          .L002CA72C
    /* 1BEF0C 002BEF0C 00000000 */   nop
  .L002BEF10:
    /* 1BEF10 002BEF10 289E0B0C */  jal        func_002e78a0
    /* 1BEF14 002BEF14 00000000 */   nop
    /* 1BEF18 002BEF18 FF005030 */  andi       $16, $2, 0xFF
    /* 1BEF1C 002BEF1C 389E0B0C */  jal        func_002e78e0
    /* 1BEF20 002BEF20 00000000 */   nop
    /* 1BEF24 002BEF24 FF004530 */  andi       $5, $2, 0xFF
    /* 1BEF28 002BEF28 2D200002 */  daddu      $4, $16, $0
    /* 1BEF2C 002BEF2C 9842040C */  jal        func_00110a60
    /* 1BEF30 002BEF30 00000000 */   nop
    /* 1BEF34 002BEF34 3C1E0200 */  dsll32     $3, $2, 24
    /* 1BEF38 002BEF38 3F1E0300 */  dsra32     $3, $3, 24
    /* 1BEF3C 002BEF3C 01000224 */  addiu      $2, $0, 0x1
    /* 1BEF40 002BEF40 29006214 */  bne        $3, $2, .L002BEFE8
    /* 1BEF44 002BEF44 00000000 */   nop
    /* 1BEF48 002BEF48 389E0B0C */  jal        func_002e78e0
    /* 1BEF4C 002BEF4C 00000000 */   nop
    /* 1BEF50 002BEF50 FF005030 */  andi       $16, $2, 0xFF
    /* 1BEF54 002BEF54 289E0B0C */  jal        func_002e78a0
    /* 1BEF58 002BEF58 00000000 */   nop
    /* 1BEF5C 002BEF5C FF004330 */  andi       $3, $2, 0xFF
    /* 1BEF60 002BEF60 80100300 */  sll        $2, $3, 2
    /* 1BEF64 002BEF64 21184300 */  addu       $3, $2, $3
    /* 1BEF68 002BEF68 80100300 */  sll        $2, $3, 2
    /* 1BEF6C 002BEF6C 21106200 */  addu       $2, $3, $2
    /* 1BEF70 002BEF70 80100200 */  sll        $2, $2, 2
    /* 1BEF74 002BEF74 21100202 */  addu       $2, $16, $2
    /* 1BEF78 002BEF78 3C1C0200 */  dsll32     $3, $2, 16
    /* 1BEF7C 002BEF7C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1BEF80 002BEF80 90016228 */  slti       $2, $3, 0x190
    /* 1BEF84 002BEF84 0E004014 */  bnez       $2, .L002BEFC0
    /* 1BEF88 002BEF88 00000000 */   nop
    /* 1BEF8C 002BEF8C 07026128 */  slti       $1, $3, 0x207
    /* 1BEF90 002BEF90 0B002010 */  beqz       $1, .L002BEFC0
    /* 1BEF94 002BEF94 00000000 */   nop
    /* 1BEF98 002BEF98 2C0F228E */  lw         $2, 0xF2C($17)
    /* 1BEF9C 002BEF9C 2D208002 */  daddu      $4, $20, $0
    /* 1BEFA0 002BEFA0 0C000524 */  addiu      $5, $0, 0xC
    /* 1BEFA4 002BEFA4 1001468C */  lw         $6, 0x110($2)
    /* 1BEFA8 002BEFA8 2D380000 */  daddu      $7, $0, $0
    /* 1BEFAC 002BEFAC B07F0B0C */  jal        func_002dfec0
    /* 1BEFB0 002BEFB0 00000000 */   nop
    /* 1BEFB4 002BEFB4 100022A2 */  sb         $2, 0x10($17)
    /* 1BEFB8 002BEFB8 13000010 */  b          .L002BF008
    /* 1BEFBC 002BEFBC 00000000 */   nop
  .L002BEFC0:
    /* 1BEFC0 002BEFC0 2C0F228E */  lw         $2, 0xF2C($17)
    /* 1BEFC4 002BEFC4 2D208002 */  daddu      $4, $20, $0
    /* 1BEFC8 002BEFC8 0D000524 */  addiu      $5, $0, 0xD
    /* 1BEFCC 002BEFCC 1001468C */  lw         $6, 0x110($2)
    /* 1BEFD0 002BEFD0 2D380000 */  daddu      $7, $0, $0
    /* 1BEFD4 002BEFD4 B07F0B0C */  jal        func_002dfec0
    /* 1BEFD8 002BEFD8 00000000 */   nop
    /* 1BEFDC 002BEFDC 100022A2 */  sb         $2, 0x10($17)
    /* 1BEFE0 002BEFE0 09000010 */  b          .L002BF008
    /* 1BEFE4 002BEFE4 00000000 */   nop
  .L002BEFE8:
    /* 1BEFE8 002BEFE8 2C0F228E */  lw         $2, 0xF2C($17)
    /* 1BEFEC 002BEFEC 2D208002 */  daddu      $4, $20, $0
    /* 1BEFF0 002BEFF0 0C000524 */  addiu      $5, $0, 0xC
    /* 1BEFF4 002BEFF4 1001468C */  lw         $6, 0x110($2)
    /* 1BEFF8 002BEFF8 2D380000 */  daddu      $7, $0, $0
    /* 1BEFFC 002BEFFC B07F0B0C */  jal        func_002dfec0
    /* 1BF000 002BF000 00000000 */   nop
    /* 1BF004 002BF004 100022A2 */  sb         $2, 0x10($17)
  .L002BF008:
    /* 1BF008 002BF008 0F000224 */  addiu      $2, $0, 0xF
    /* 1BF00C 002BF00C 000022A2 */  sb         $2, 0x0($17)
    /* 1BF010 002BF010 C52D0010 */  b          .L002CA728
    /* 1BF014 002BF014 00000000 */   nop
    /* 1BF018 002BF018 10002482 */  lb         $4, 0x10($17)
    /* 1BF01C 002BF01C A0ED0A0C */  jal        func_002bb680
    /* 1BF020 002BF020 00000000 */   nop
    /* 1BF024 002BF024 06004010 */  beqz       $2, .L002BF040
    /* 1BF028 002BF028 00000000 */   nop
    /* 1BF02C 002BF02C 10002482 */  lb         $4, 0x10($17)
    /* 1BF030 002BF030 3CEF0A0C */  jal        func_002bbcf0
    /* 1BF034 002BF034 00000000 */   nop
    /* 1BF038 002BF038 BB2D0010 */  b          .L002CA728
    /* 1BF03C 002BF03C 00000000 */   nop
  .L002BF040:
    /* 1BF040 002BF040 10002482 */  lb         $4, 0x10($17)
    /* 1BF044 002BF044 54ED0A0C */  jal        func_002bb550
    /* 1BF048 002BF048 00000000 */   nop
    /* 1BF04C 002BF04C 0E000224 */  addiu      $2, $0, 0xE
    /* 1BF050 002BF050 000022A2 */  sb         $2, 0x0($17)
    /* 1BF054 002BF054 B42D0010 */  b          .L002CA728
    /* 1BF058 002BF058 00000000 */   nop
    /* 1BF05C 002BF05C 070020A2 */  sb         $0, 0x7($17)
    /* 1BF060 002BF060 3C1E0000 */  dsll32     $3, $0, 24
    /* 1BF064 002BF064 3F1E0300 */  dsra32     $3, $3, 24
    /* 1BF068 002BF068 40100300 */  sll        $2, $3, 1
    /* 1BF06C 002BF06C 21104300 */  addu       $2, $2, $3
    /* 1BF070 002BF070 80180200 */  sll        $3, $2, 2
    /* 1BF074 002BF074 6400023C */  lui        $2, %hi(D_0063F9F0)
    /* 1BF078 002BF078 F0F94224 */  addiu      $2, $2, %lo(D_0063F9F0)
    /* 1BF07C 002BF07C 21804300 */  addu       $16, $2, $3
    /* 1BF080 002BF080 FC42023C */  lui        $2, (0x42FC0000 >> 16)
    /* 1BF084 002BF084 00608244 */  mtc1       $2, $f12
    /* 1BF088 002BF088 440C248E */  lw         $4, 0xC44($17)
    /* 1BF08C 002BF08C 41000524 */  addiu      $5, $0, 0x41
    /* 1BF090 002BF090 78820B0C */  jal        func_002e09e0
    /* 1BF094 002BF094 00000000 */   nop
    /* 1BF098 002BF098 000014C6 */  lwc1       $f20, 0x0($16)
    /* 1BF09C 002BF09C 440C248E */  lw         $4, 0xC44($17)
    /* 1BF0A0 002BF0A0 38810B0C */  jal        func_002e04e0
    /* 1BF0A4 002BF0A4 00000000 */   nop
    /* 1BF0A8 002BF0A8 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BF0AC 002BF0AC 040014C6 */  lwc1       $f20, 0x4($16)
    /* 1BF0B0 002BF0B0 440C248E */  lw         $4, 0xC44($17)
    /* 1BF0B4 002BF0B4 38810B0C */  jal        func_002e04e0
    /* 1BF0B8 002BF0B8 00000000 */   nop
    /* 1BF0BC 002BF0BC 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BF0C0 002BF0C0 8C07A427 */  addiu      $4, $29, 0x78C
    /* 1BF0C4 002BF0C4 FE000524 */  addiu      $5, $0, 0xFE
    /* 1BF0C8 002BF0C8 C6000624 */  addiu      $6, $0, 0xC6
    /* 1BF0CC 002BF0CC 31000724 */  addiu      $7, $0, 0x31
    /* 1BF0D0 002BF0D0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF0D4 002BF0D4 98CA0A0C */  jal        func_002b2a60
    /* 1BF0D8 002BF0D8 00000000 */   nop
    /* 1BF0DC 002BF0DC 440C248E */  lw         $4, 0xC44($17)
    /* 1BF0E0 002BF0E0 38810B0C */  jal        func_002e04e0
    /* 1BF0E4 002BF0E4 00000000 */   nop
    /* 1BF0E8 002BF0E8 8C07A693 */  lbu        $6, 0x78C($29)
    /* 1BF0EC 002BF0EC 8D07A593 */  lbu        $5, 0x78D($29)
    /* 1BF0F0 002BF0F0 8E07A493 */  lbu        $4, 0x78E($29)
    /* 1BF0F4 002BF0F4 8F07A393 */  lbu        $3, 0x78F($29)
    /* 1BF0F8 002BF0F8 790046A0 */  sb         $6, 0x79($2)
    /* 1BF0FC 002BF0FC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF100 002BF100 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF104 002BF104 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF108 002BF108 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1BF10C 002BF10C A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1BF110 002BF110 00008244 */  mtc1       $2, $f0
    /* 1BF114 002BF114 00000000 */  nop
    /* 1BF118 002BF118 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1BF11C 002BF11C 4806A427 */  addiu      $4, $29, 0x648
    /* 1BF120 002BF120 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1BF124 002BF124 5CCA0A0C */  jal        func_002b2970
    /* 1BF128 002BF128 00000000 */   nop
    /* 1BF12C 002BF12C 4006A427 */  addiu      $4, $29, 0x640
    /* 1BF130 002BF130 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1BF134 002BF134 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1BF138 002BF138 5CCA0A0C */  jal        func_002b2970
    /* 1BF13C 002BF13C 00000000 */   nop
    /* 1BF140 002BF140 07002282 */  lb         $2, 0x7($17)
    /* 1BF144 002BF144 01004224 */  addiu      $2, $2, 0x1
    /* 1BF148 002BF148 3C4C0200 */  dsll32     $9, $2, 16
    /* 1BF14C 002BF14C 3F4C0900 */  dsra32     $9, $9, 16
    /* 1BF150 002BF150 440C248E */  lw         $4, 0xC44($17)
    /* 1BF154 002BF154 4806A5DF */  ld         $5, 0x648($29)
    /* 1BF158 002BF158 4006A6DF */  ld         $6, 0x640($29)
    /* 1BF15C 002BF15C 2D380000 */  daddu      $7, $0, $0
    /* 1BF160 002BF160 03000824 */  addiu      $8, $0, 0x3
    /* 1BF164 002BF164 88810B0C */  jal        func_002e0620
    /* 1BF168 002BF168 00000000 */   nop
    /* 1BF16C 002BF16C 07002282 */  lb         $2, 0x7($17)
    /* 1BF170 002BF170 01004224 */  addiu      $2, $2, 0x1
    /* 1BF174 002BF174 3C4C0200 */  dsll32     $9, $2, 16
    /* 1BF178 002BF178 3F4C0900 */  dsra32     $9, $9, 16
    /* 1BF17C 002BF17C 440C248E */  lw         $4, 0xC44($17)
    /* 1BF180 002BF180 2D280000 */  daddu      $5, $0, $0
    /* 1BF184 002BF184 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BF188 002BF188 2D380000 */  daddu      $7, $0, $0
    /* 1BF18C 002BF18C 03000824 */  addiu      $8, $0, 0x3
    /* 1BF190 002BF190 98810B0C */  jal        func_002e0660
    /* 1BF194 002BF194 00000000 */   nop
    /* 1BF198 002BF198 FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1BF19C 002BF19C 00608244 */  mtc1       $2, $f12
    /* 1BF1A0 002BF1A0 480C248E */  lw         $4, 0xC48($17)
    /* 1BF1A4 002BF1A4 41000524 */  addiu      $5, $0, 0x41
    /* 1BF1A8 002BF1A8 78820B0C */  jal        func_002e09e0
    /* 1BF1AC 002BF1AC 00000000 */   nop
    /* 1BF1B0 002BF1B0 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1BF1B4 002BF1B4 080000C6 */  lwc1       $f0, 0x8($16)
    /* 1BF1B8 002BF1B8 000D0046 */  add.s      $f20, $f1, $f0
    /* 1BF1BC 002BF1BC 480C248E */  lw         $4, 0xC48($17)
    /* 1BF1C0 002BF1C0 38810B0C */  jal        func_002e04e0
    /* 1BF1C4 002BF1C4 00000000 */   nop
    /* 1BF1C8 002BF1C8 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BF1CC 002BF1CC 040014C6 */  lwc1       $f20, 0x4($16)
    /* 1BF1D0 002BF1D0 480C248E */  lw         $4, 0xC48($17)
    /* 1BF1D4 002BF1D4 38810B0C */  jal        func_002e04e0
    /* 1BF1D8 002BF1D8 00000000 */   nop
    /* 1BF1DC 002BF1DC 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BF1E0 002BF1E0 8807A427 */  addiu      $4, $29, 0x788
    /* 1BF1E4 002BF1E4 FE000524 */  addiu      $5, $0, 0xFE
    /* 1BF1E8 002BF1E8 C6000624 */  addiu      $6, $0, 0xC6
    /* 1BF1EC 002BF1EC 31000724 */  addiu      $7, $0, 0x31
    /* 1BF1F0 002BF1F0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF1F4 002BF1F4 98CA0A0C */  jal        func_002b2a60
    /* 1BF1F8 002BF1F8 00000000 */   nop
    /* 1BF1FC 002BF1FC 480C248E */  lw         $4, 0xC48($17)
    /* 1BF200 002BF200 38810B0C */  jal        func_002e04e0
    /* 1BF204 002BF204 00000000 */   nop
    /* 1BF208 002BF208 8807A693 */  lbu        $6, 0x788($29)
    /* 1BF20C 002BF20C 8907A593 */  lbu        $5, 0x789($29)
    /* 1BF210 002BF210 8A07A493 */  lbu        $4, 0x78A($29)
    /* 1BF214 002BF214 8B07A393 */  lbu        $3, 0x78B($29)
    /* 1BF218 002BF218 790046A0 */  sb         $6, 0x79($2)
    /* 1BF21C 002BF21C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF220 002BF220 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF224 002BF224 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF228 002BF228 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1BF22C 002BF22C 080000C6 */  lwc1       $f0, 0x8($16)
    /* 1BF230 002BF230 40080046 */  add.s      $f1, $f1, $f0
    /* 1BF234 002BF234 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1BF238 002BF238 00008244 */  mtc1       $2, $f0
    /* 1BF23C 002BF23C 00000000 */  nop
    /* 1BF240 002BF240 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1BF244 002BF244 3806A427 */  addiu      $4, $29, 0x638
    /* 1BF248 002BF248 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1BF24C 002BF24C 5CCA0A0C */  jal        func_002b2970
    /* 1BF250 002BF250 00000000 */   nop
    /* 1BF254 002BF254 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1BF258 002BF258 080000C6 */  lwc1       $f0, 0x8($16)
    /* 1BF25C 002BF25C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1BF260 002BF260 3006A427 */  addiu      $4, $29, 0x630
    /* 1BF264 002BF264 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1BF268 002BF268 5CCA0A0C */  jal        func_002b2970
    /* 1BF26C 002BF26C 00000000 */   nop
    /* 1BF270 002BF270 07002282 */  lb         $2, 0x7($17)
    /* 1BF274 002BF274 01004224 */  addiu      $2, $2, 0x1
    /* 1BF278 002BF278 3C4C0200 */  dsll32     $9, $2, 16
    /* 1BF27C 002BF27C 3F4C0900 */  dsra32     $9, $9, 16
    /* 1BF280 002BF280 480C248E */  lw         $4, 0xC48($17)
    /* 1BF284 002BF284 3806A5DF */  ld         $5, 0x638($29)
    /* 1BF288 002BF288 3006A6DF */  ld         $6, 0x630($29)
    /* 1BF28C 002BF28C 2D380000 */  daddu      $7, $0, $0
    /* 1BF290 002BF290 03000824 */  addiu      $8, $0, 0x3
    /* 1BF294 002BF294 88810B0C */  jal        func_002e0620
    /* 1BF298 002BF298 00000000 */   nop
    /* 1BF29C 002BF29C 07002282 */  lb         $2, 0x7($17)
    /* 1BF2A0 002BF2A0 01004224 */  addiu      $2, $2, 0x1
    /* 1BF2A4 002BF2A4 3C4C0200 */  dsll32     $9, $2, 16
    /* 1BF2A8 002BF2A8 3F4C0900 */  dsra32     $9, $9, 16
    /* 1BF2AC 002BF2AC 480C248E */  lw         $4, 0xC48($17)
    /* 1BF2B0 002BF2B0 2D280000 */  daddu      $5, $0, $0
    /* 1BF2B4 002BF2B4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BF2B8 002BF2B8 2D380000 */  daddu      $7, $0, $0
    /* 1BF2BC 002BF2BC 03000824 */  addiu      $8, $0, 0x3
    /* 1BF2C0 002BF2C0 98810B0C */  jal        func_002e0660
    /* 1BF2C4 002BF2C4 00000000 */   nop
    /* 1BF2C8 002BF2C8 2D208002 */  daddu      $4, $20, $0
    /* 1BF2CC 002BF2CC E45F0B0C */  jal        func_002d7f90
    /* 1BF2D0 002BF2D0 00000000 */   nop
    /* 1BF2D4 002BF2D4 2DA00000 */  daddu      $20, $0, $0
    /* 1BF2D8 002BF2D8 4C000010 */  b          .L002BF40C
    /* 1BF2DC 002BF2DC 00000000 */   nop
  .L002BF2E0:
    /* 1BF2E0 002BF2E0 3C9C1400 */  dsll32     $19, $20, 16
    /* 1BF2E4 002BF2E4 3F9C1300 */  dsra32     $19, $19, 16
    /* 1BF2E8 002BF2E8 3A006226 */  addiu      $2, $19, 0x3A
    /* 1BF2EC 002BF2EC C0180200 */  sll        $3, $2, 3
    /* 1BF2F0 002BF2F0 6400023C */  lui        $2, %hi(D_0063F560)
    /* 1BF2F4 002BF2F4 60F54224 */  addiu      $2, $2, %lo(D_0063F560)
    /* 1BF2F8 002BF2F8 21904300 */  addu       $18, $2, $3
    /* 1BF2FC 002BF2FC 80101300 */  sll        $2, $19, 2
    /* 1BF300 002BF300 21182202 */  addu       $3, $17, $2
    /* 1BF304 002BF304 200D7024 */  addiu      $16, $3, 0xD20
    /* 1BF308 002BF308 64006226 */  addiu      $2, $19, 0x64
    /* 1BF30C 002BF30C 00008244 */  mtc1       $2, $f0
    /* 1BF310 002BF310 00000000 */  nop
    /* 1BF314 002BF314 20038046 */  cvt.s.w    $f12, $f0
    /* 1BF318 002BF318 200D648C */  lw         $4, 0xD20($3)
    /* 1BF31C 002BF31C 56000524 */  addiu      $5, $0, 0x56
    /* 1BF320 002BF320 78820B0C */  jal        func_002e09e0
    /* 1BF324 002BF324 00000000 */   nop
    /* 1BF328 002BF328 1300601A */  blez       $19, .L002BF378
    /* 1BF32C 002BF32C 00000000 */   nop
    /* 1BF330 002BF330 8407A427 */  addiu      $4, $29, 0x784
    /* 1BF334 002BF334 ED000524 */  addiu      $5, $0, 0xED
    /* 1BF338 002BF338 80000624 */  addiu      $6, $0, 0x80
    /* 1BF33C 002BF33C 2D380000 */  daddu      $7, $0, $0
    /* 1BF340 002BF340 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF344 002BF344 98CA0A0C */  jal        func_002b2a60
    /* 1BF348 002BF348 00000000 */   nop
    /* 1BF34C 002BF34C 0000048E */  lw         $4, 0x0($16)
    /* 1BF350 002BF350 38810B0C */  jal        func_002e04e0
    /* 1BF354 002BF354 00000000 */   nop
    /* 1BF358 002BF358 8407A693 */  lbu        $6, 0x784($29)
    /* 1BF35C 002BF35C 8507A593 */  lbu        $5, 0x785($29)
    /* 1BF360 002BF360 8607A493 */  lbu        $4, 0x786($29)
    /* 1BF364 002BF364 8707A393 */  lbu        $3, 0x787($29)
    /* 1BF368 002BF368 790046A0 */  sb         $6, 0x79($2)
    /* 1BF36C 002BF36C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF370 002BF370 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF374 002BF374 7C0043A0 */  sb         $3, 0x7C($2)
  .L002BF378:
    /* 1BF378 002BF378 3C141400 */  dsll32     $2, $20, 16
    /* 1BF37C 002BF37C 3F140200 */  dsra32     $2, $2, 16
    /* 1BF380 002BF380 80100200 */  sll        $2, $2, 2
    /* 1BF384 002BF384 21102202 */  addu       $2, $17, $2
    /* 1BF388 002BF388 200D5024 */  addiu      $16, $2, 0xD20
    /* 1BF38C 002BF38C A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1BF390 002BF390 00088244 */  mtc1       $2, $f1
    /* 1BF394 002BF394 000040C6 */  lwc1       $f0, 0x0($18)
    /* 1BF398 002BF398 000B0046 */  add.s      $f12, $f1, $f0
    /* 1BF39C 002BF39C 2806A427 */  addiu      $4, $29, 0x628
    /* 1BF3A0 002BF3A0 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1BF3A4 002BF3A4 5CCA0A0C */  jal        func_002b2970
    /* 1BF3A8 002BF3A8 00000000 */   nop
    /* 1BF3AC 002BF3AC 2006A427 */  addiu      $4, $29, 0x620
    /* 1BF3B0 002BF3B0 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1BF3B4 002BF3B4 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1BF3B8 002BF3B8 5CCA0A0C */  jal        func_002b2970
    /* 1BF3BC 002BF3BC 00000000 */   nop
    /* 1BF3C0 002BF3C0 0000048E */  lw         $4, 0x0($16)
    /* 1BF3C4 002BF3C4 2806A5DF */  ld         $5, 0x628($29)
    /* 1BF3C8 002BF3C8 2006A6DF */  ld         $6, 0x620($29)
    /* 1BF3CC 002BF3CC 2D380000 */  daddu      $7, $0, $0
    /* 1BF3D0 002BF3D0 03000824 */  addiu      $8, $0, 0x3
    /* 1BF3D4 002BF3D4 2D488002 */  daddu      $9, $20, $0
    /* 1BF3D8 002BF3D8 88810B0C */  jal        func_002e0620
    /* 1BF3DC 002BF3DC 00000000 */   nop
    /* 1BF3E0 002BF3E0 0000048E */  lw         $4, 0x0($16)
    /* 1BF3E4 002BF3E4 2D280000 */  daddu      $5, $0, $0
    /* 1BF3E8 002BF3E8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BF3EC 002BF3EC 2D380000 */  daddu      $7, $0, $0
    /* 1BF3F0 002BF3F0 03000824 */  addiu      $8, $0, 0x3
    /* 1BF3F4 002BF3F4 2D488002 */  daddu      $9, $20, $0
    /* 1BF3F8 002BF3F8 98810B0C */  jal        func_002e0660
    /* 1BF3FC 002BF3FC 00000000 */   nop
    /* 1BF400 002BF400 01008226 */  addiu      $2, $20, 0x1
    /* 1BF404 002BF404 3CA40200 */  dsll32     $20, $2, 16
    /* 1BF408 002BF408 3FA41400 */  dsra32     $20, $20, 16
  .L002BF40C:
    /* 1BF40C 002BF40C 3C141400 */  dsll32     $2, $20, 16
    /* 1BF410 002BF410 3F140200 */  dsra32     $2, $2, 16
    /* 1BF414 002BF414 07004228 */  slti       $2, $2, 0x7
    /* 1BF418 002BF418 B1FF4014 */  bnez       $2, .L002BF2E0
    /* 1BF41C 002BF41C 00000000 */   nop
    /* 1BF420 002BF420 8007A427 */  addiu      $4, $29, 0x780
    /* 1BF424 002BF424 2D000524 */  addiu      $5, $0, 0x2D
    /* 1BF428 002BF428 2D30A000 */  daddu      $6, $5, $0
    /* 1BF42C 002BF42C 2D38A000 */  daddu      $7, $5, $0
    /* 1BF430 002BF430 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF434 002BF434 98CA0A0C */  jal        func_002b2a60
    /* 1BF438 002BF438 00000000 */   nop
    /* 1BF43C 002BF43C 07002282 */  lb         $2, 0x7($17)
    /* 1BF440 002BF440 80100200 */  sll        $2, $2, 2
    /* 1BF444 002BF444 21105100 */  addu       $2, $2, $17
    /* 1BF448 002BF448 240D448C */  lw         $4, 0xD24($2)
    /* 1BF44C 002BF44C 38810B0C */  jal        func_002e04e0
    /* 1BF450 002BF450 00000000 */   nop
    /* 1BF454 002BF454 8007A693 */  lbu        $6, 0x780($29)
    /* 1BF458 002BF458 8107A593 */  lbu        $5, 0x781($29)
    /* 1BF45C 002BF45C 8207A493 */  lbu        $4, 0x782($29)
    /* 1BF460 002BF460 8307A393 */  lbu        $3, 0x783($29)
    /* 1BF464 002BF464 790046A0 */  sb         $6, 0x79($2)
    /* 1BF468 002BF468 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF46C 002BF46C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF470 002BF470 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF474 002BF474 3843023C */  lui        $2, (0x43380000 >> 16)
    /* 1BF478 002BF478 00608244 */  mtc1       $2, $f12
    /* 1BF47C 002BF47C 3C0C248E */  lw         $4, 0xC3C($17)
    /* 1BF480 002BF480 41000524 */  addiu      $5, $0, 0x41
    /* 1BF484 002BF484 78820B0C */  jal        func_002e09e0
    /* 1BF488 002BF488 00000000 */   nop
    /* 1BF48C 002BF48C 7C07A427 */  addiu      $4, $29, 0x77C
    /* 1BF490 002BF490 5A000524 */  addiu      $5, $0, 0x5A
    /* 1BF494 002BF494 2D300000 */  daddu      $6, $0, $0
    /* 1BF498 002BF498 02000724 */  addiu      $7, $0, 0x2
    /* 1BF49C 002BF49C FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF4A0 002BF4A0 98CA0A0C */  jal        func_002b2a60
    /* 1BF4A4 002BF4A4 00000000 */   nop
    /* 1BF4A8 002BF4A8 3C0C248E */  lw         $4, 0xC3C($17)
    /* 1BF4AC 002BF4AC 38810B0C */  jal        func_002e04e0
    /* 1BF4B0 002BF4B0 00000000 */   nop
    /* 1BF4B4 002BF4B4 7C07A693 */  lbu        $6, 0x77C($29)
    /* 1BF4B8 002BF4B8 7D07A593 */  lbu        $5, 0x77D($29)
    /* 1BF4BC 002BF4BC 7E07A493 */  lbu        $4, 0x77E($29)
    /* 1BF4C0 002BF4C0 7F07A393 */  lbu        $3, 0x77F($29)
    /* 1BF4C4 002BF4C4 790046A0 */  sb         $6, 0x79($2)
    /* 1BF4C8 002BF4C8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF4CC 002BF4CC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF4D0 002BF4D0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF4D4 002BF4D4 3643023C */  lui        $2, (0x43360000 >> 16)
    /* 1BF4D8 002BF4D8 00608244 */  mtc1       $2, $f12
    /* 1BF4DC 002BF4DC 380C248E */  lw         $4, 0xC38($17)
    /* 1BF4E0 002BF4E0 56000524 */  addiu      $5, $0, 0x56
    /* 1BF4E4 002BF4E4 78820B0C */  jal        func_002e09e0
    /* 1BF4E8 002BF4E8 00000000 */   nop
    /* 1BF4EC 002BF4EC 3743023C */  lui        $2, (0x43370000 >> 16)
    /* 1BF4F0 002BF4F0 00608244 */  mtc1       $2, $f12
    /* 1BF4F4 002BF4F4 400C248E */  lw         $4, 0xC40($17)
    /* 1BF4F8 002BF4F8 56000524 */  addiu      $5, $0, 0x56
    /* 1BF4FC 002BF4FC 78820B0C */  jal        func_002e09e0
    /* 1BF500 002BF500 00000000 */   nop
    /* 1BF504 002BF504 7807A427 */  addiu      $4, $29, 0x778
    /* 1BF508 002BF508 FE000524 */  addiu      $5, $0, 0xFE
    /* 1BF50C 002BF50C BE000624 */  addiu      $6, $0, 0xBE
    /* 1BF510 002BF510 1E000724 */  addiu      $7, $0, 0x1E
    /* 1BF514 002BF514 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF518 002BF518 98CA0A0C */  jal        func_002b2a60
    /* 1BF51C 002BF51C 00000000 */   nop
    /* 1BF520 002BF520 400C248E */  lw         $4, 0xC40($17)
    /* 1BF524 002BF524 38810B0C */  jal        func_002e04e0
    /* 1BF528 002BF528 00000000 */   nop
    /* 1BF52C 002BF52C 7807A693 */  lbu        $6, 0x778($29)
    /* 1BF530 002BF530 7907A593 */  lbu        $5, 0x779($29)
    /* 1BF534 002BF534 7A07A493 */  lbu        $4, 0x77A($29)
    /* 1BF538 002BF538 7B07A393 */  lbu        $3, 0x77B($29)
    /* 1BF53C 002BF53C 790046A0 */  sb         $6, 0x79($2)
    /* 1BF540 002BF540 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF544 002BF544 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF548 002BF548 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF54C 002BF54C 280F248E */  lw         $4, 0xF28($17)
    /* 1BF550 002BF550 02000524 */  addiu      $5, $0, 0x2
    /* 1BF554 002BF554 80B4110C */  jal        func_0046d200
    /* 1BF558 002BF558 00000000 */   nop
    /* 1BF55C 002BF55C 2D804000 */  daddu      $16, $2, $0
    /* 1BF560 002BF560 2D200002 */  daddu      $4, $16, $0
    /* 1BF564 002BF564 98AC110C */  jal        func_0046b260
    /* 1BF568 002BF568 00000000 */   nop
    /* 1BF56C 002BF56C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1BF570 002BF570 00088244 */  mtc1       $2, $f1
    /* 1BF574 002BF574 00000000 */  nop
    /* 1BF578 002BF578 03000146 */  div.s      $f0, $f0, $f1
    /* 1BF57C 002BF57C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BF580 002BF580 00000244 */  mfc1       $2, $f0
    /* 1BF584 002BF584 00000000 */  nop
    /* 1BF588 002BF588 3C940200 */  dsll32     $18, $2, 16
    /* 1BF58C 002BF58C 3F941200 */  dsra32     $18, $18, 16
    /* 1BF590 002BF590 400C248E */  lw         $4, 0xC40($17)
    /* 1BF594 002BF594 38810B0C */  jal        func_002e04e0
    /* 1BF598 002BF598 00000000 */   nop
    /* 1BF59C 002BF59C 000152A4 */  sh         $18, 0x100($2)
    /* 1BF5A0 002BF5A0 2D200002 */  daddu      $4, $16, $0
    /* 1BF5A4 002BF5A4 BCAC110C */  jal        func_0046b2f0
    /* 1BF5A8 002BF5A8 00000000 */   nop
    /* 1BF5AC 002BF5AC 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1BF5B0 002BF5B0 00088244 */  mtc1       $2, $f1
    /* 1BF5B4 002BF5B4 00000000 */  nop
    /* 1BF5B8 002BF5B8 03000146 */  div.s      $f0, $f0, $f1
    /* 1BF5BC 002BF5BC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BF5C0 002BF5C0 00000244 */  mfc1       $2, $f0
    /* 1BF5C4 002BF5C4 00000000 */  nop
    /* 1BF5C8 002BF5C8 3C940200 */  dsll32     $18, $2, 16
    /* 1BF5CC 002BF5CC 3F941200 */  dsra32     $18, $18, 16
    /* 1BF5D0 002BF5D0 400C248E */  lw         $4, 0xC40($17)
    /* 1BF5D4 002BF5D4 38810B0C */  jal        func_002e04e0
    /* 1BF5D8 002BF5D8 00000000 */   nop
    /* 1BF5DC 002BF5DC 020152A4 */  sh         $18, 0x102($2)
    /* 1BF5E0 002BF5E0 2D200002 */  daddu      $4, $16, $0
    /* 1BF5E4 002BF5E4 A0B4110C */  jal        func_0046d280
    /* 1BF5E8 002BF5E8 00000000 */   nop
    /* 1BF5EC 002BF5EC B4C2023C */  lui        $2, (0xC2B40000 >> 16)
    /* 1BF5F0 002BF5F0 00608244 */  mtc1       $2, $f12
    /* 1BF5F4 002BF5F4 400C248E */  lw         $4, 0xC40($17)
    /* 1BF5F8 002BF5F8 46630046 */  mov.s      $f13, $f12
    /* 1BF5FC 002BF5FC 2D280000 */  daddu      $5, $0, $0
    /* 1BF600 002BF600 2D300000 */  daddu      $6, $0, $0
    /* 1BF604 002BF604 2D380000 */  daddu      $7, $0, $0
    /* 1BF608 002BF608 50820B0C */  jal        func_002e0940
    /* 1BF60C 002BF60C 00000000 */   nop
    /* 1BF610 002BF610 3F43023C */  lui        $2, (0x433F0000 >> 16)
    /* 1BF614 002BF614 00608244 */  mtc1       $2, $f12
    /* 1BF618 002BF618 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1BF61C 002BF61C 40000524 */  addiu      $5, $0, 0x40
    /* 1BF620 002BF620 78820B0C */  jal        func_002e09e0
    /* 1BF624 002BF624 00000000 */   nop
    /* 1BF628 002BF628 7407A427 */  addiu      $4, $29, 0x774
    /* 1BF62C 002BF62C 2D280000 */  daddu      $5, $0, $0
    /* 1BF630 002BF630 2D300000 */  daddu      $6, $0, $0
    /* 1BF634 002BF634 2D380000 */  daddu      $7, $0, $0
    /* 1BF638 002BF638 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF63C 002BF63C 98CA0A0C */  jal        func_002b2a60
    /* 1BF640 002BF640 00000000 */   nop
    /* 1BF644 002BF644 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1BF648 002BF648 38810B0C */  jal        func_002e04e0
    /* 1BF64C 002BF64C 00000000 */   nop
    /* 1BF650 002BF650 7407A693 */  lbu        $6, 0x774($29)
    /* 1BF654 002BF654 7507A593 */  lbu        $5, 0x775($29)
    /* 1BF658 002BF658 7607A493 */  lbu        $4, 0x776($29)
    /* 1BF65C 002BF65C 7707A393 */  lbu        $3, 0x777($29)
    /* 1BF660 002BF660 790046A0 */  sb         $6, 0x79($2)
    /* 1BF664 002BF664 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF668 002BF668 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF66C 002BF66C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF670 002BF670 280F248E */  lw         $4, 0xF28($17)
    /* 1BF674 002BF674 05000524 */  addiu      $5, $0, 0x5
    /* 1BF678 002BF678 80B4110C */  jal        func_0046d200
    /* 1BF67C 002BF67C 00000000 */   nop
    /* 1BF680 002BF680 2D804000 */  daddu      $16, $2, $0
    /* 1BF684 002BF684 2D200002 */  daddu      $4, $16, $0
    /* 1BF688 002BF688 98AC110C */  jal        func_0046b260
    /* 1BF68C 002BF68C 00000000 */   nop
    /* 1BF690 002BF690 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BF694 002BF694 00000244 */  mfc1       $2, $f0
    /* 1BF698 002BF698 00000000 */  nop
    /* 1BF69C 002BF69C 3C940200 */  dsll32     $18, $2, 16
    /* 1BF6A0 002BF6A0 3F941200 */  dsra32     $18, $18, 16
    /* 1BF6A4 002BF6A4 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1BF6A8 002BF6A8 38810B0C */  jal        func_002e04e0
    /* 1BF6AC 002BF6AC 00000000 */   nop
    /* 1BF6B0 002BF6B0 000152A4 */  sh         $18, 0x100($2)
    /* 1BF6B4 002BF6B4 2D200002 */  daddu      $4, $16, $0
    /* 1BF6B8 002BF6B8 BCAC110C */  jal        func_0046b2f0
    /* 1BF6BC 002BF6BC 00000000 */   nop
    /* 1BF6C0 002BF6C0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BF6C4 002BF6C4 00000244 */  mfc1       $2, $f0
    /* 1BF6C8 002BF6C8 00000000 */  nop
    /* 1BF6CC 002BF6CC 3C940200 */  dsll32     $18, $2, 16
    /* 1BF6D0 002BF6D0 3F941200 */  dsra32     $18, $18, 16
    /* 1BF6D4 002BF6D4 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1BF6D8 002BF6D8 38810B0C */  jal        func_002e04e0
    /* 1BF6DC 002BF6DC 00000000 */   nop
    /* 1BF6E0 002BF6E0 020152A4 */  sh         $18, 0x102($2)
    /* 1BF6E4 002BF6E4 2D200002 */  daddu      $4, $16, $0
    /* 1BF6E8 002BF6E8 A0B4110C */  jal        func_0046d280
    /* 1BF6EC 002BF6EC 00000000 */   nop
    /* 1BF6F0 002BF6F0 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1BF6F4 002BF6F4 2D280000 */  daddu      $5, $0, $0
    /* 1BF6F8 002BF6F8 A0000624 */  addiu      $6, $0, 0xA0
    /* 1BF6FC 002BF6FC 2D380000 */  daddu      $7, $0, $0
    /* 1BF700 002BF700 04000824 */  addiu      $8, $0, 0x4
    /* 1BF704 002BF704 2D480001 */  daddu      $9, $8, $0
    /* 1BF708 002BF708 98810B0C */  jal        func_002e0660
    /* 1BF70C 002BF70C 00000000 */   nop
    /* 1BF710 002BF710 00608044 */  mtc1       $0, $f12
    /* 1BF714 002BF714 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1BF718 002BF718 20858DC7 */  lwc1       $f13, -0x7AE0($28)
    /* 1BF71C 002BF71C 2D280000 */  daddu      $5, $0, $0
    /* 1BF720 002BF720 04000624 */  addiu      $6, $0, 0x4
    /* 1BF724 002BF724 2D38C000 */  daddu      $7, $6, $0
    /* 1BF728 002BF728 50820B0C */  jal        func_002e0940
    /* 1BF72C 002BF72C 00000000 */   nop
    /* 1BF730 002BF730 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1BF734 002BF734 00608244 */  mtc1       $2, $f12
    /* 1BF738 002BF738 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 1BF73C 002BF73C 00688244 */  mtc1       $2, $f13
    /* 1BF740 002BF740 1806A427 */  addiu      $4, $29, 0x618
    /* 1BF744 002BF744 5CCA0A0C */  jal        func_002b2970
    /* 1BF748 002BF748 00000000 */   nop
    /* 1BF74C 002BF74C 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1BF750 002BF750 00608244 */  mtc1       $2, $f12
    /* 1BF754 002BF754 9B43023C */  lui        $2, (0x439B0000 >> 16)
    /* 1BF758 002BF758 00688244 */  mtc1       $2, $f13
    /* 1BF75C 002BF75C 1006A427 */  addiu      $4, $29, 0x610
    /* 1BF760 002BF760 5CCA0A0C */  jal        func_002b2970
    /* 1BF764 002BF764 00000000 */   nop
    /* 1BF768 002BF768 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1BF76C 002BF76C 1806A5DF */  ld         $5, 0x618($29)
    /* 1BF770 002BF770 1006A6DF */  ld         $6, 0x610($29)
    /* 1BF774 002BF774 2D380000 */  daddu      $7, $0, $0
    /* 1BF778 002BF778 04000824 */  addiu      $8, $0, 0x4
    /* 1BF77C 002BF77C 2D480001 */  daddu      $9, $8, $0
    /* 1BF780 002BF780 88810B0C */  jal        func_002e0620
    /* 1BF784 002BF784 00000000 */   nop
    /* 1BF788 002BF788 4043023C */  lui        $2, (0x43400000 >> 16)
    /* 1BF78C 002BF78C 00608244 */  mtc1       $2, $f12
    /* 1BF790 002BF790 500C248E */  lw         $4, 0xC50($17)
    /* 1BF794 002BF794 40000524 */  addiu      $5, $0, 0x40
    /* 1BF798 002BF798 78820B0C */  jal        func_002e09e0
    /* 1BF79C 002BF79C 00000000 */   nop
    /* 1BF7A0 002BF7A0 7007A427 */  addiu      $4, $29, 0x770
    /* 1BF7A4 002BF7A4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1BF7A8 002BF7A8 BE000624 */  addiu      $6, $0, 0xBE
    /* 1BF7AC 002BF7AC 22000724 */  addiu      $7, $0, 0x22
    /* 1BF7B0 002BF7B0 2D40A000 */  daddu      $8, $5, $0
    /* 1BF7B4 002BF7B4 98CA0A0C */  jal        func_002b2a60
    /* 1BF7B8 002BF7B8 00000000 */   nop
    /* 1BF7BC 002BF7BC 500C248E */  lw         $4, 0xC50($17)
    /* 1BF7C0 002BF7C0 38810B0C */  jal        func_002e04e0
    /* 1BF7C4 002BF7C4 00000000 */   nop
    /* 1BF7C8 002BF7C8 7007A693 */  lbu        $6, 0x770($29)
    /* 1BF7CC 002BF7CC 7107A593 */  lbu        $5, 0x771($29)
    /* 1BF7D0 002BF7D0 7207A493 */  lbu        $4, 0x772($29)
    /* 1BF7D4 002BF7D4 7307A393 */  lbu        $3, 0x773($29)
    /* 1BF7D8 002BF7D8 790046A0 */  sb         $6, 0x79($2)
    /* 1BF7DC 002BF7DC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF7E0 002BF7E0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF7E4 002BF7E4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF7E8 002BF7E8 DC42023C */  lui        $2, (0x42DC0000 >> 16)
    /* 1BF7EC 002BF7EC 00A08244 */  mtc1       $2, $f20
    /* 1BF7F0 002BF7F0 500C248E */  lw         $4, 0xC50($17)
    /* 1BF7F4 002BF7F4 38810B0C */  jal        func_002e04e0
    /* 1BF7F8 002BF7F8 00000000 */   nop
    /* 1BF7FC 002BF7FC 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BF800 002BF800 48C2023C */  lui        $2, (0xC2480000 >> 16)
    /* 1BF804 002BF804 00A08244 */  mtc1       $2, $f20
    /* 1BF808 002BF808 500C248E */  lw         $4, 0xC50($17)
    /* 1BF80C 002BF80C 38810B0C */  jal        func_002e04e0
    /* 1BF810 002BF810 00000000 */   nop
    /* 1BF814 002BF814 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BF818 002BF818 280F248E */  lw         $4, 0xF28($17)
    /* 1BF81C 002BF81C 06000524 */  addiu      $5, $0, 0x6
    /* 1BF820 002BF820 80B4110C */  jal        func_0046d200
    /* 1BF824 002BF824 00000000 */   nop
    /* 1BF828 002BF828 2D904000 */  daddu      $18, $2, $0
    /* 1BF82C 002BF82C 2D204002 */  daddu      $4, $18, $0
    /* 1BF830 002BF830 98AC110C */  jal        func_0046b260
    /* 1BF834 002BF834 00000000 */   nop
    /* 1BF838 002BF838 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BF83C 002BF83C 00000244 */  mfc1       $2, $f0
    /* 1BF840 002BF840 00000000 */  nop
    /* 1BF844 002BF844 3C840200 */  dsll32     $16, $2, 16
    /* 1BF848 002BF848 3F841000 */  dsra32     $16, $16, 16
    /* 1BF84C 002BF84C 500C248E */  lw         $4, 0xC50($17)
    /* 1BF850 002BF850 38810B0C */  jal        func_002e04e0
    /* 1BF854 002BF854 00000000 */   nop
    /* 1BF858 002BF858 000150A4 */  sh         $16, 0x100($2)
    /* 1BF85C 002BF85C 500C248E */  lw         $4, 0xC50($17)
    /* 1BF860 002BF860 38810B0C */  jal        func_002e04e0
    /* 1BF864 002BF864 00000000 */   nop
    /* 1BF868 002BF868 020140A4 */  sh         $0, 0x102($2)
    /* 1BF86C 002BF86C B4C2023C */  lui        $2, (0xC2B40000 >> 16)
    /* 1BF870 002BF870 00608244 */  mtc1       $2, $f12
    /* 1BF874 002BF874 500C248E */  lw         $4, 0xC50($17)
    /* 1BF878 002BF878 24858DC7 */  lwc1       $f13, -0x7ADC($28)
    /* 1BF87C 002BF87C 2D280000 */  daddu      $5, $0, $0
    /* 1BF880 002BF880 04000624 */  addiu      $6, $0, 0x4
    /* 1BF884 002BF884 2D380000 */  daddu      $7, $0, $0
    /* 1BF888 002BF888 50820B0C */  jal        func_002e0940
    /* 1BF88C 002BF88C 00000000 */   nop
    /* 1BF890 002BF890 2D204002 */  daddu      $4, $18, $0
    /* 1BF894 002BF894 A0B4110C */  jal        func_0046d280
    /* 1BF898 002BF898 00000000 */   nop
    /* 1BF89C 002BF89C 500C248E */  lw         $4, 0xC50($17)
    /* 1BF8A0 002BF8A0 2D280000 */  daddu      $5, $0, $0
    /* 1BF8A4 002BF8A4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BF8A8 002BF8A8 2D380000 */  daddu      $7, $0, $0
    /* 1BF8AC 002BF8AC 04000824 */  addiu      $8, $0, 0x4
    /* 1BF8B0 002BF8B0 2D480000 */  daddu      $9, $0, $0
    /* 1BF8B4 002BF8B4 98810B0C */  jal        func_002e0660
    /* 1BF8B8 002BF8B8 00000000 */   nop
    /* 1BF8BC 002BF8BC 3E43023C */  lui        $2, (0x433E0000 >> 16)
    /* 1BF8C0 002BF8C0 00608244 */  mtc1       $2, $f12
    /* 1BF8C4 002BF8C4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF8C8 002BF8C8 40000524 */  addiu      $5, $0, 0x40
    /* 1BF8CC 002BF8CC 78820B0C */  jal        func_002e09e0
    /* 1BF8D0 002BF8D0 00000000 */   nop
    /* 1BF8D4 002BF8D4 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1BF8D8 002BF8D8 00A08244 */  mtc1       $2, $f20
    /* 1BF8DC 002BF8DC 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF8E0 002BF8E0 38810B0C */  jal        func_002e04e0
    /* 1BF8E4 002BF8E4 00000000 */   nop
    /* 1BF8E8 002BF8E8 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BF8EC 002BF8EC F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1BF8F0 002BF8F0 00A08244 */  mtc1       $2, $f20
    /* 1BF8F4 002BF8F4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF8F8 002BF8F8 38810B0C */  jal        func_002e04e0
    /* 1BF8FC 002BF8FC 00000000 */   nop
    /* 1BF900 002BF900 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BF904 002BF904 6C07A427 */  addiu      $4, $29, 0x76C
    /* 1BF908 002BF908 ED000524 */  addiu      $5, $0, 0xED
    /* 1BF90C 002BF90C 81000624 */  addiu      $6, $0, 0x81
    /* 1BF910 002BF910 03000724 */  addiu      $7, $0, 0x3
    /* 1BF914 002BF914 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BF918 002BF918 98CA0A0C */  jal        func_002b2a60
    /* 1BF91C 002BF91C 00000000 */   nop
    /* 1BF920 002BF920 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF924 002BF924 38810B0C */  jal        func_002e04e0
    /* 1BF928 002BF928 00000000 */   nop
    /* 1BF92C 002BF92C 6C07A693 */  lbu        $6, 0x76C($29)
    /* 1BF930 002BF930 6D07A593 */  lbu        $5, 0x76D($29)
    /* 1BF934 002BF934 6E07A493 */  lbu        $4, 0x76E($29)
    /* 1BF938 002BF938 6F07A393 */  lbu        $3, 0x76F($29)
    /* 1BF93C 002BF93C 790046A0 */  sb         $6, 0x79($2)
    /* 1BF940 002BF940 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BF944 002BF944 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BF948 002BF948 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BF94C 002BF94C 280F248E */  lw         $4, 0xF28($17)
    /* 1BF950 002BF950 06000524 */  addiu      $5, $0, 0x6
    /* 1BF954 002BF954 80B4110C */  jal        func_0046d200
    /* 1BF958 002BF958 00000000 */   nop
    /* 1BF95C 002BF95C 2D904000 */  daddu      $18, $2, $0
    /* 1BF960 002BF960 2D204002 */  daddu      $4, $18, $0
    /* 1BF964 002BF964 98AC110C */  jal        func_0046b260
    /* 1BF968 002BF968 00000000 */   nop
    /* 1BF96C 002BF96C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BF970 002BF970 00000244 */  mfc1       $2, $f0
    /* 1BF974 002BF974 00000000 */  nop
    /* 1BF978 002BF978 3C840200 */  dsll32     $16, $2, 16
    /* 1BF97C 002BF97C 3F841000 */  dsra32     $16, $16, 16
    /* 1BF980 002BF980 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF984 002BF984 38810B0C */  jal        func_002e04e0
    /* 1BF988 002BF988 00000000 */   nop
    /* 1BF98C 002BF98C 000150A4 */  sh         $16, 0x100($2)
    /* 1BF990 002BF990 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF994 002BF994 38810B0C */  jal        func_002e04e0
    /* 1BF998 002BF998 00000000 */   nop
    /* 1BF99C 002BF99C 020140A4 */  sh         $0, 0x102($2)
    /* 1BF9A0 002BF9A0 2D204002 */  daddu      $4, $18, $0
    /* 1BF9A4 002BF9A4 A0B4110C */  jal        func_0046d280
    /* 1BF9A8 002BF9A8 00000000 */   nop
    /* 1BF9AC 002BF9AC AAC2023C */  lui        $2, (0xC2AA0000 >> 16)
    /* 1BF9B0 002BF9B0 00608244 */  mtc1       $2, $f12
    /* 1BF9B4 002BF9B4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF9B8 002BF9B8 28858DC7 */  lwc1       $f13, -0x7AD8($28)
    /* 1BF9BC 002BF9BC 2D280000 */  daddu      $5, $0, $0
    /* 1BF9C0 002BF9C0 04000624 */  addiu      $6, $0, 0x4
    /* 1BF9C4 002BF9C4 02000724 */  addiu      $7, $0, 0x2
    /* 1BF9C8 002BF9C8 50820B0C */  jal        func_002e0940
    /* 1BF9CC 002BF9CC 00000000 */   nop
    /* 1BF9D0 002BF9D0 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1BF9D4 002BF9D4 2D280000 */  daddu      $5, $0, $0
    /* 1BF9D8 002BF9D8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BF9DC 002BF9DC 2D380000 */  daddu      $7, $0, $0
    /* 1BF9E0 002BF9E0 04000824 */  addiu      $8, $0, 0x4
    /* 1BF9E4 002BF9E4 02000924 */  addiu      $9, $0, 0x2
    /* 1BF9E8 002BF9E8 98810B0C */  jal        func_002e0660
    /* 1BF9EC 002BF9EC 00000000 */   nop
    /* 1BF9F0 002BF9F0 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1BF9F4 002BF9F4 00608244 */  mtc1       $2, $f12
    /* 1BF9F8 002BF9F8 E80D248E */  lw         $4, 0xDE8($17)
    /* 1BF9FC 002BF9FC 41000524 */  addiu      $5, $0, 0x41
    /* 1BFA00 002BFA00 78820B0C */  jal        func_002e09e0
    /* 1BFA04 002BFA04 00000000 */   nop
    /* 1BFA08 002BFA08 E80D248E */  lw         $4, 0xDE8($17)
    /* 1BFA0C 002BFA0C 2D280000 */  daddu      $5, $0, $0
    /* 1BFA10 002BFA10 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BFA14 002BFA14 2D380000 */  daddu      $7, $0, $0
    /* 1BFA18 002BFA18 06000824 */  addiu      $8, $0, 0x6
    /* 1BFA1C 002BFA1C 2D480000 */  daddu      $9, $0, $0
    /* 1BFA20 002BFA20 98810B0C */  jal        func_002e0660
    /* 1BFA24 002BFA24 00000000 */   nop
    /* 1BFA28 002BFA28 4643023C */  lui        $2, (0x43460000 >> 16)
    /* 1BFA2C 002BFA2C 00A08244 */  mtc1       $2, $f20
    /* 1BFA30 002BFA30 E80D248E */  lw         $4, 0xDE8($17)
    /* 1BFA34 002BFA34 38810B0C */  jal        func_002e04e0
    /* 1BFA38 002BFA38 00000000 */   nop
    /* 1BFA3C 002BFA3C 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BFA40 002BFA40 51010224 */  addiu      $2, $0, 0x151
    /* 1BFA44 002BFA44 00008244 */  mtc1       $2, $f0
    /* 1BFA48 002BFA48 00000000 */  nop
    /* 1BFA4C 002BFA4C 20058046 */  cvt.s.w    $f20, $f0
    /* 1BFA50 002BFA50 E80D248E */  lw         $4, 0xDE8($17)
    /* 1BFA54 002BFA54 38810B0C */  jal        func_002e04e0
    /* 1BFA58 002BFA58 00000000 */   nop
    /* 1BFA5C 002BFA5C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BFA60 002BFA60 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1BFA64 002BFA64 00608244 */  mtc1       $2, $f12
    /* 1BFA68 002BFA68 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1BFA6C 002BFA6C 41000524 */  addiu      $5, $0, 0x41
    /* 1BFA70 002BFA70 78820B0C */  jal        func_002e09e0
    /* 1BFA74 002BFA74 00000000 */   nop
    /* 1BFA78 002BFA78 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1BFA7C 002BFA7C 2D280000 */  daddu      $5, $0, $0
    /* 1BFA80 002BFA80 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BFA84 002BFA84 2D380000 */  daddu      $7, $0, $0
    /* 1BFA88 002BFA88 06000824 */  addiu      $8, $0, 0x6
    /* 1BFA8C 002BFA8C 2D480000 */  daddu      $9, $0, $0
    /* 1BFA90 002BFA90 98810B0C */  jal        func_002e0660
    /* 1BFA94 002BFA94 00000000 */   nop
    /* 1BFA98 002BFA98 5843023C */  lui        $2, (0x43580000 >> 16)
    /* 1BFA9C 002BFA9C 00A08244 */  mtc1       $2, $f20
    /* 1BFAA0 002BFAA0 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1BFAA4 002BFAA4 38810B0C */  jal        func_002e04e0
    /* 1BFAA8 002BFAA8 00000000 */   nop
    /* 1BFAAC 002BFAAC 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BFAB0 002BFAB0 B843023C */  lui        $2, (0x43B80000 >> 16)
    /* 1BFAB4 002BFAB4 00A08244 */  mtc1       $2, $f20
    /* 1BFAB8 002BFAB8 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1BFABC 002BFABC 38810B0C */  jal        func_002e04e0
    /* 1BFAC0 002BFAC0 00000000 */   nop
    /* 1BFAC4 002BFAC4 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BFAC8 002BFAC8 4F43023C */  lui        $2, (0x434F0000 >> 16)
    /* 1BFACC 002BFACC 00608244 */  mtc1       $2, $f12
    /* 1BFAD0 002BFAD0 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1BFAD4 002BFAD4 3F000524 */  addiu      $5, $0, 0x3F
    /* 1BFAD8 002BFAD8 78820B0C */  jal        func_002e09e0
    /* 1BFADC 002BFADC 00000000 */   nop
    /* 1BFAE0 002BFAE0 6807A427 */  addiu      $4, $29, 0x768
    /* 1BFAE4 002BFAE4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1BFAE8 002BFAE8 AE000624 */  addiu      $6, $0, 0xAE
    /* 1BFAEC 002BFAEC 2D380000 */  daddu      $7, $0, $0
    /* 1BFAF0 002BFAF0 2D40A000 */  daddu      $8, $5, $0
    /* 1BFAF4 002BFAF4 98CA0A0C */  jal        func_002b2a60
    /* 1BFAF8 002BFAF8 00000000 */   nop
    /* 1BFAFC 002BFAFC 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1BFB00 002BFB00 38810B0C */  jal        func_002e04e0
    /* 1BFB04 002BFB04 00000000 */   nop
    /* 1BFB08 002BFB08 6807A693 */  lbu        $6, 0x768($29)
    /* 1BFB0C 002BFB0C 6907A593 */  lbu        $5, 0x769($29)
    /* 1BFB10 002BFB10 6A07A493 */  lbu        $4, 0x76A($29)
    /* 1BFB14 002BFB14 6B07A393 */  lbu        $3, 0x76B($29)
    /* 1BFB18 002BFB18 790046A0 */  sb         $6, 0x79($2)
    /* 1BFB1C 002BFB1C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BFB20 002BFB20 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BFB24 002BFB24 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BFB28 002BFB28 00608044 */  mtc1       $0, $f12
    /* 1BFB2C 002BFB2C B443023C */  lui        $2, (0x43B40000 >> 16)
    /* 1BFB30 002BFB30 00688244 */  mtc1       $2, $f13
    /* 1BFB34 002BFB34 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1BFB38 002BFB38 2D280000 */  daddu      $5, $0, $0
    /* 1BFB3C 002BFB3C 08070624 */  addiu      $6, $0, 0x708
    /* 1BFB40 002BFB40 2D380000 */  daddu      $7, $0, $0
    /* 1BFB44 002BFB44 50820B0C */  jal        func_002e0940
    /* 1BFB48 002BFB48 00000000 */   nop
    /* 1BFB4C 002BFB4C 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1BFB50 002BFB50 06000524 */  addiu      $5, $0, 0x6
    /* 1BFB54 002BFB54 2D300000 */  daddu      $6, $0, $0
    /* 1BFB58 002BFB58 3C810B0C */  jal        func_002e04f0
    /* 1BFB5C 002BFB5C 00000000 */   nop
    /* 1BFB60 002BFB60 5143023C */  lui        $2, (0x43510000 >> 16)
    /* 1BFB64 002BFB64 00608244 */  mtc1       $2, $f12
    /* 1BFB68 002BFB68 900D248E */  lw         $4, 0xD90($17)
    /* 1BFB6C 002BFB6C 3D000524 */  addiu      $5, $0, 0x3D
    /* 1BFB70 002BFB70 78820B0C */  jal        func_002e09e0
    /* 1BFB74 002BFB74 00000000 */   nop
    /* 1BFB78 002BFB78 6407A427 */  addiu      $4, $29, 0x764
    /* 1BFB7C 002BFB7C E4000524 */  addiu      $5, $0, 0xE4
    /* 1BFB80 002BFB80 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BFB84 002BFB84 2D380000 */  daddu      $7, $0, $0
    /* 1BFB88 002BFB88 2D40C000 */  daddu      $8, $6, $0
    /* 1BFB8C 002BFB8C 98CA0A0C */  jal        func_002b2a60
    /* 1BFB90 002BFB90 00000000 */   nop
    /* 1BFB94 002BFB94 900D248E */  lw         $4, 0xD90($17)
    /* 1BFB98 002BFB98 38810B0C */  jal        func_002e04e0
    /* 1BFB9C 002BFB9C 00000000 */   nop
    /* 1BFBA0 002BFBA0 6407A693 */  lbu        $6, 0x764($29)
    /* 1BFBA4 002BFBA4 6507A593 */  lbu        $5, 0x765($29)
    /* 1BFBA8 002BFBA8 6607A493 */  lbu        $4, 0x766($29)
    /* 1BFBAC 002BFBAC 6707A393 */  lbu        $3, 0x767($29)
    /* 1BFBB0 002BFBB0 790046A0 */  sb         $6, 0x79($2)
    /* 1BFBB4 002BFBB4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BFBB8 002BFBB8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BFBBC 002BFBBC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BFBC0 002BFBC0 280F248E */  lw         $4, 0xF28($17)
    /* 1BFBC4 002BFBC4 56000524 */  addiu      $5, $0, 0x56
    /* 1BFBC8 002BFBC8 80B4110C */  jal        func_0046d200
    /* 1BFBCC 002BFBCC 00000000 */   nop
    /* 1BFBD0 002BFBD0 2D804000 */  daddu      $16, $2, $0
    /* 1BFBD4 002BFBD4 2D200002 */  daddu      $4, $16, $0
    /* 1BFBD8 002BFBD8 98AC110C */  jal        func_0046b260
    /* 1BFBDC 002BFBDC 00000000 */   nop
    /* 1BFBE0 002BFBE0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BFBE4 002BFBE4 00000244 */  mfc1       $2, $f0
    /* 1BFBE8 002BFBE8 00000000 */  nop
    /* 1BFBEC 002BFBEC 3C940200 */  dsll32     $18, $2, 16
    /* 1BFBF0 002BFBF0 3F941200 */  dsra32     $18, $18, 16
    /* 1BFBF4 002BFBF4 900D248E */  lw         $4, 0xD90($17)
    /* 1BFBF8 002BFBF8 38810B0C */  jal        func_002e04e0
    /* 1BFBFC 002BFBFC 00000000 */   nop
    /* 1BFC00 002BFC00 000152A4 */  sh         $18, 0x100($2)
    /* 1BFC04 002BFC04 2D200002 */  daddu      $4, $16, $0
    /* 1BFC08 002BFC08 BCAC110C */  jal        func_0046b2f0
    /* 1BFC0C 002BFC0C 00000000 */   nop
    /* 1BFC10 002BFC10 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1BFC14 002BFC14 00088244 */  mtc1       $2, $f1
    /* 1BFC18 002BFC18 00000000 */  nop
    /* 1BFC1C 002BFC1C 03000146 */  div.s      $f0, $f0, $f1
    /* 1BFC20 002BFC20 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BFC24 002BFC24 00000244 */  mfc1       $2, $f0
    /* 1BFC28 002BFC28 00000000 */  nop
    /* 1BFC2C 002BFC2C 3C940200 */  dsll32     $18, $2, 16
    /* 1BFC30 002BFC30 3F941200 */  dsra32     $18, $18, 16
    /* 1BFC34 002BFC34 900D248E */  lw         $4, 0xD90($17)
    /* 1BFC38 002BFC38 38810B0C */  jal        func_002e04e0
    /* 1BFC3C 002BFC3C 00000000 */   nop
    /* 1BFC40 002BFC40 020152A4 */  sh         $18, 0x102($2)
    /* 1BFC44 002BFC44 2D200002 */  daddu      $4, $16, $0
    /* 1BFC48 002BFC48 A0B4110C */  jal        func_0046d280
    /* 1BFC4C 002BFC4C 00000000 */   nop
    /* 1BFC50 002BFC50 00608044 */  mtc1       $0, $f12
    /* 1BFC54 002BFC54 B443023C */  lui        $2, (0x43B40000 >> 16)
    /* 1BFC58 002BFC58 00688244 */  mtc1       $2, $f13
    /* 1BFC5C 002BFC5C 900D248E */  lw         $4, 0xD90($17)
    /* 1BFC60 002BFC60 2D280000 */  daddu      $5, $0, $0
    /* 1BFC64 002BFC64 A0050624 */  addiu      $6, $0, 0x5A0
    /* 1BFC68 002BFC68 2D380000 */  daddu      $7, $0, $0
    /* 1BFC6C 002BFC6C 50820B0C */  jal        func_002e0940
    /* 1BFC70 002BFC70 00000000 */   nop
    /* 1BFC74 002BFC74 900D248E */  lw         $4, 0xD90($17)
    /* 1BFC78 002BFC78 06000524 */  addiu      $5, $0, 0x6
    /* 1BFC7C 002BFC7C 2D300000 */  daddu      $6, $0, $0
    /* 1BFC80 002BFC80 3C810B0C */  jal        func_002e04f0
    /* 1BFC84 002BFC84 00000000 */   nop
    /* 1BFC88 002BFC88 900D248E */  lw         $4, 0xD90($17)
    /* 1BFC8C 002BFC8C 2D280000 */  daddu      $5, $0, $0
    /* 1BFC90 002BFC90 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BFC94 002BFC94 2D380000 */  daddu      $7, $0, $0
    /* 1BFC98 002BFC98 0A000824 */  addiu      $8, $0, 0xA
    /* 1BFC9C 002BFC9C 2D480000 */  daddu      $9, $0, $0
    /* 1BFCA0 002BFCA0 98810B0C */  jal        func_002e0660
    /* 1BFCA4 002BFCA4 00000000 */   nop
    /* 1BFCA8 002BFCA8 5243023C */  lui        $2, (0x43520000 >> 16)
    /* 1BFCAC 002BFCAC 00608244 */  mtc1       $2, $f12
    /* 1BFCB0 002BFCB0 940D248E */  lw         $4, 0xD94($17)
    /* 1BFCB4 002BFCB4 3D000524 */  addiu      $5, $0, 0x3D
    /* 1BFCB8 002BFCB8 78820B0C */  jal        func_002e09e0
    /* 1BFCBC 002BFCBC 00000000 */   nop
    /* 1BFCC0 002BFCC0 6007A427 */  addiu      $4, $29, 0x760
    /* 1BFCC4 002BFCC4 E4000524 */  addiu      $5, $0, 0xE4
    /* 1BFCC8 002BFCC8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BFCCC 002BFCCC 2D380000 */  daddu      $7, $0, $0
    /* 1BFCD0 002BFCD0 2D40C000 */  daddu      $8, $6, $0
    /* 1BFCD4 002BFCD4 98CA0A0C */  jal        func_002b2a60
    /* 1BFCD8 002BFCD8 00000000 */   nop
    /* 1BFCDC 002BFCDC 940D248E */  lw         $4, 0xD94($17)
    /* 1BFCE0 002BFCE0 38810B0C */  jal        func_002e04e0
    /* 1BFCE4 002BFCE4 00000000 */   nop
    /* 1BFCE8 002BFCE8 6007A693 */  lbu        $6, 0x760($29)
    /* 1BFCEC 002BFCEC 6107A593 */  lbu        $5, 0x761($29)
    /* 1BFCF0 002BFCF0 6207A493 */  lbu        $4, 0x762($29)
    /* 1BFCF4 002BFCF4 6307A393 */  lbu        $3, 0x763($29)
    /* 1BFCF8 002BFCF8 790046A0 */  sb         $6, 0x79($2)
    /* 1BFCFC 002BFCFC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BFD00 002BFD00 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BFD04 002BFD04 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BFD08 002BFD08 280F248E */  lw         $4, 0xF28($17)
    /* 1BFD0C 002BFD0C 57000524 */  addiu      $5, $0, 0x57
    /* 1BFD10 002BFD10 80B4110C */  jal        func_0046d200
    /* 1BFD14 002BFD14 00000000 */   nop
    /* 1BFD18 002BFD18 2D904000 */  daddu      $18, $2, $0
    /* 1BFD1C 002BFD1C 940D248E */  lw         $4, 0xD94($17)
    /* 1BFD20 002BFD20 38810B0C */  jal        func_002e04e0
    /* 1BFD24 002BFD24 00000000 */   nop
    /* 1BFD28 002BFD28 000140A4 */  sh         $0, 0x100($2)
    /* 1BFD2C 002BFD2C 2D204002 */  daddu      $4, $18, $0
    /* 1BFD30 002BFD30 BCAC110C */  jal        func_0046b2f0
    /* 1BFD34 002BFD34 00000000 */   nop
    /* 1BFD38 002BFD38 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1BFD3C 002BFD3C 00088244 */  mtc1       $2, $f1
    /* 1BFD40 002BFD40 00000000 */  nop
    /* 1BFD44 002BFD44 03000146 */  div.s      $f0, $f0, $f1
    /* 1BFD48 002BFD48 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1BFD4C 002BFD4C 00000244 */  mfc1       $2, $f0
    /* 1BFD50 002BFD50 00000000 */  nop
    /* 1BFD54 002BFD54 3C840200 */  dsll32     $16, $2, 16
    /* 1BFD58 002BFD58 3F841000 */  dsra32     $16, $16, 16
    /* 1BFD5C 002BFD5C 940D248E */  lw         $4, 0xD94($17)
    /* 1BFD60 002BFD60 38810B0C */  jal        func_002e04e0
    /* 1BFD64 002BFD64 00000000 */   nop
    /* 1BFD68 002BFD68 020150A4 */  sh         $16, 0x102($2)
    /* 1BFD6C 002BFD6C 2D204002 */  daddu      $4, $18, $0
    /* 1BFD70 002BFD70 A0B4110C */  jal        func_0046d280
    /* 1BFD74 002BFD74 00000000 */   nop
    /* 1BFD78 002BFD78 00608044 */  mtc1       $0, $f12
    /* 1BFD7C 002BFD7C B443023C */  lui        $2, (0x43B40000 >> 16)
    /* 1BFD80 002BFD80 00688244 */  mtc1       $2, $f13
    /* 1BFD84 002BFD84 940D248E */  lw         $4, 0xD94($17)
    /* 1BFD88 002BFD88 2D280000 */  daddu      $5, $0, $0
    /* 1BFD8C 002BFD8C A0050624 */  addiu      $6, $0, 0x5A0
    /* 1BFD90 002BFD90 2D380000 */  daddu      $7, $0, $0
    /* 1BFD94 002BFD94 50820B0C */  jal        func_002e0940
    /* 1BFD98 002BFD98 00000000 */   nop
    /* 1BFD9C 002BFD9C 940D248E */  lw         $4, 0xD94($17)
    /* 1BFDA0 002BFDA0 06000524 */  addiu      $5, $0, 0x6
    /* 1BFDA4 002BFDA4 2D300000 */  daddu      $6, $0, $0
    /* 1BFDA8 002BFDA8 3C810B0C */  jal        func_002e04f0
    /* 1BFDAC 002BFDAC 00000000 */   nop
    /* 1BFDB0 002BFDB0 940D248E */  lw         $4, 0xD94($17)
    /* 1BFDB4 002BFDB4 2D280000 */  daddu      $5, $0, $0
    /* 1BFDB8 002BFDB8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1BFDBC 002BFDBC 2D380000 */  daddu      $7, $0, $0
    /* 1BFDC0 002BFDC0 0A000824 */  addiu      $8, $0, 0xA
    /* 1BFDC4 002BFDC4 2D480000 */  daddu      $9, $0, $0
    /* 1BFDC8 002BFDC8 98810B0C */  jal        func_002e0660
    /* 1BFDCC 002BFDCC 00000000 */   nop
    /* 1BFDD0 002BFDD0 59001024 */  addiu      $16, $0, 0x59
    /* 1BFDD4 002BFDD4 18000010 */  b          .L002BFE38
    /* 1BFDD8 002BFDD8 00000000 */   nop
  .L002BFDDC:
    /* 1BFDDC 002BFDDC 5C07A427 */  addiu      $4, $29, 0x75C
    /* 1BFDE0 002BFDE0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1BFDE4 002BFDE4 AE000624 */  addiu      $6, $0, 0xAE
    /* 1BFDE8 002BFDE8 2D380000 */  daddu      $7, $0, $0
    /* 1BFDEC 002BFDEC 2D40A000 */  daddu      $8, $5, $0
    /* 1BFDF0 002BFDF0 98CA0A0C */  jal        func_002b2a60
    /* 1BFDF4 002BFDF4 00000000 */   nop
    /* 1BFDF8 002BFDF8 80101200 */  sll        $2, $18, 2
    /* 1BFDFC 002BFDFC 21102202 */  addu       $2, $17, $2
    /* 1BFE00 002BFE00 380C448C */  lw         $4, 0xC38($2)
    /* 1BFE04 002BFE04 38810B0C */  jal        func_002e04e0
    /* 1BFE08 002BFE08 00000000 */   nop
    /* 1BFE0C 002BFE0C 5C07A693 */  lbu        $6, 0x75C($29)
    /* 1BFE10 002BFE10 5D07A593 */  lbu        $5, 0x75D($29)
    /* 1BFE14 002BFE14 5E07A493 */  lbu        $4, 0x75E($29)
    /* 1BFE18 002BFE18 5F07A393 */  lbu        $3, 0x75F($29)
    /* 1BFE1C 002BFE1C 790046A0 */  sb         $6, 0x79($2)
    /* 1BFE20 002BFE20 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BFE24 002BFE24 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BFE28 002BFE28 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BFE2C 002BFE2C 01000226 */  addiu      $2, $16, 0x1
    /* 1BFE30 002BFE30 3C840200 */  dsll32     $16, $2, 16
    /* 1BFE34 002BFE34 3F841000 */  dsra32     $16, $16, 16
  .L002BFE38:
    /* 1BFE38 002BFE38 3C941000 */  dsll32     $18, $16, 16
    /* 1BFE3C 002BFE3C 3F941200 */  dsra32     $18, $18, 16
    /* 1BFE40 002BFE40 6000422A */  slti       $2, $18, 0x60
    /* 1BFE44 002BFE44 E5FF4014 */  bnez       $2, .L002BFDDC
    /* 1BFE48 002BFE48 00000000 */   nop
    /* 1BFE4C 002BFE4C 64001024 */  addiu      $16, $0, 0x64
    /* 1BFE50 002BFE50 18000010 */  b          .L002BFEB4
    /* 1BFE54 002BFE54 00000000 */   nop
  .L002BFE58:
    /* 1BFE58 002BFE58 5807A427 */  addiu      $4, $29, 0x758
    /* 1BFE5C 002BFE5C FE000524 */  addiu      $5, $0, 0xFE
    /* 1BFE60 002BFE60 C6000624 */  addiu      $6, $0, 0xC6
    /* 1BFE64 002BFE64 31000724 */  addiu      $7, $0, 0x31
    /* 1BFE68 002BFE68 FF000824 */  addiu      $8, $0, 0xFF
    /* 1BFE6C 002BFE6C 98CA0A0C */  jal        func_002b2a60
    /* 1BFE70 002BFE70 00000000 */   nop
    /* 1BFE74 002BFE74 80101200 */  sll        $2, $18, 2
    /* 1BFE78 002BFE78 21102202 */  addu       $2, $17, $2
    /* 1BFE7C 002BFE7C 380C448C */  lw         $4, 0xC38($2)
    /* 1BFE80 002BFE80 38810B0C */  jal        func_002e04e0
    /* 1BFE84 002BFE84 00000000 */   nop
    /* 1BFE88 002BFE88 5807A693 */  lbu        $6, 0x758($29)
    /* 1BFE8C 002BFE8C 5907A593 */  lbu        $5, 0x759($29)
    /* 1BFE90 002BFE90 5A07A493 */  lbu        $4, 0x75A($29)
    /* 1BFE94 002BFE94 5B07A393 */  lbu        $3, 0x75B($29)
    /* 1BFE98 002BFE98 790046A0 */  sb         $6, 0x79($2)
    /* 1BFE9C 002BFE9C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1BFEA0 002BFEA0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1BFEA4 002BFEA4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1BFEA8 002BFEA8 01000226 */  addiu      $2, $16, 0x1
    /* 1BFEAC 002BFEAC 3C840200 */  dsll32     $16, $2, 16
    /* 1BFEB0 002BFEB0 3F841000 */  dsra32     $16, $16, 16
  .L002BFEB4:
    /* 1BFEB4 002BFEB4 3C941000 */  dsll32     $18, $16, 16
    /* 1BFEB8 002BFEB8 3F941200 */  dsra32     $18, $18, 16
    /* 1BFEBC 002BFEBC 6700422A */  slti       $2, $18, 0x67
    /* 1BFEC0 002BFEC0 E5FF4014 */  bnez       $2, .L002BFE58
    /* 1BFEC4 002BFEC4 00000000 */   nop
    /* 1BFEC8 002BFEC8 10000224 */  addiu      $2, $0, 0x10
    /* 1BFECC 002BFECC 000022A2 */  sb         $2, 0x0($17)
    /* 1BFED0 002BFED0 01000224 */  addiu      $2, $0, 0x1
    /* 1BFED4 002BFED4 260C22A6 */  sh         $2, 0xC26($17)
    /* 1BFED8 002BFED8 132A0010 */  b          .L002CA728
    /* 1BFEDC 002BFEDC 00000000 */   nop
    /* 1BFEE0 002BFEE0 8C00023C */  lui        $2, %hi(D_008C027A)
    /* 1BFEE4 002BFEE4 7A024394 */  lhu        $3, %lo(D_008C027A)($2)
    /* 1BFEE8 002BFEE8 00406230 */  andi       $2, $3, 0x4000
    /* 1BFEEC 002BFEEC AD004010 */  beqz       $2, .L002C01A4
    /* 1BFEF0 002BFEF0 00000000 */   nop
    /* 1BFEF4 002BFEF4 07002482 */  lb         $4, 0x7($17)
    /* 1BFEF8 002BFEF8 01000524 */  addiu      $5, $0, 0x1
    /* 1BFEFC 002BFEFC 05000624 */  addiu      $6, $0, 0x5
    /* 1BFF00 002BFF00 2D380000 */  daddu      $7, $0, $0
    /* 1BFF04 002BFF04 02000824 */  addiu      $8, $0, 0x2
    /* 1BFF08 002BFF08 2CCB0A0C */  jal        func_002b2cb0
    /* 1BFF0C 002BFF0C 00000000 */   nop
    /* 1BFF10 002BFF10 070022A2 */  sb         $2, 0x7($17)
    /* 1BFF14 002BFF14 2D208002 */  daddu      $4, $20, $0
    /* 1BFF18 002BFF18 E45F0B0C */  jal        func_002d7f90
    /* 1BFF1C 002BFF1C 00000000 */   nop
    /* 1BFF20 002BFF20 07002382 */  lb         $3, 0x7($17)
    /* 1BFF24 002BFF24 40100300 */  sll        $2, $3, 1
    /* 1BFF28 002BFF28 21104300 */  addu       $2, $2, $3
    /* 1BFF2C 002BFF2C 80180200 */  sll        $3, $2, 2
    /* 1BFF30 002BFF30 6400023C */  lui        $2, %hi(D_0063F9F0)
    /* 1BFF34 002BFF34 F0F94224 */  addiu      $2, $2, %lo(D_0063F9F0)
    /* 1BFF38 002BFF38 21804300 */  addu       $16, $2, $3
    /* 1BFF3C 002BFF3C 000014C6 */  lwc1       $f20, 0x0($16)
    /* 1BFF40 002BFF40 440C248E */  lw         $4, 0xC44($17)
    /* 1BFF44 002BFF44 38810B0C */  jal        func_002e04e0
    /* 1BFF48 002BFF48 00000000 */   nop
    /* 1BFF4C 002BFF4C 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BFF50 002BFF50 040014C6 */  lwc1       $f20, 0x4($16)
    /* 1BFF54 002BFF54 440C248E */  lw         $4, 0xC44($17)
    /* 1BFF58 002BFF58 38810B0C */  jal        func_002e04e0
    /* 1BFF5C 002BFF5C 00000000 */   nop
    /* 1BFF60 002BFF60 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BFF64 002BFF64 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1BFF68 002BFF68 080000C6 */  lwc1       $f0, 0x8($16)
    /* 1BFF6C 002BFF6C 000D0046 */  add.s      $f20, $f1, $f0
    /* 1BFF70 002BFF70 480C248E */  lw         $4, 0xC48($17)
    /* 1BFF74 002BFF74 38810B0C */  jal        func_002e04e0
    /* 1BFF78 002BFF78 00000000 */   nop
    /* 1BFF7C 002BFF7C 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1BFF80 002BFF80 040014C6 */  lwc1       $f20, 0x4($16)
    /* 1BFF84 002BFF84 480C248E */  lw         $4, 0xC48($17)
    /* 1BFF88 002BFF88 38810B0C */  jal        func_002e04e0
    /* 1BFF8C 002BFF8C 00000000 */   nop
    /* 1BFF90 002BFF90 300054E4 */  swc1       $f20, 0x30($2)
    /* 1BFF94 002BFF94 440C248E */  lw         $4, 0xC44($17)
    /* 1BFF98 002BFF98 38810B0C */  jal        func_002e04e0
    /* 1BFF9C 002BFF9C 00000000 */   nop
    /* 1BFFA0 002BFFA0 2D804000 */  daddu      $16, $2, $0
    /* 1BFFA4 002BFFA4 440C248E */  lw         $4, 0xC44($17)
    /* 1BFFA8 002BFFA8 38810B0C */  jal        func_002e04e0
    /* 1BFFAC 002BFFAC 00000000 */   nop
    /* 1BFFB0 002BFFB0 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1BFFB4 002BFFB4 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1BFFB8 002BFFB8 00008244 */  mtc1       $2, $f0
    /* 1BFFBC 002BFFBC 00000000 */  nop
    /* 1BFFC0 002BFFC0 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1BFFC4 002BFFC4 0806A427 */  addiu      $4, $29, 0x608
    /* 1BFFC8 002BFFC8 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1BFFCC 002BFFCC 5CCA0A0C */  jal        func_002b2970
    /* 1BFFD0 002BFFD0 00000000 */   nop
    /* 1BFFD4 002BFFD4 440C248E */  lw         $4, 0xC44($17)
    /* 1BFFD8 002BFFD8 38810B0C */  jal        func_002e04e0
    /* 1BFFDC 002BFFDC 00000000 */   nop
    /* 1BFFE0 002BFFE0 2D804000 */  daddu      $16, $2, $0
    /* 1BFFE4 002BFFE4 440C248E */  lw         $4, 0xC44($17)
    /* 1BFFE8 002BFFE8 38810B0C */  jal        func_002e04e0
    /* 1BFFEC 002BFFEC 00000000 */   nop
    /* 1BFFF0 002BFFF0 0006A427 */  addiu      $4, $29, 0x600
    /* 1BFFF4 002BFFF4 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1BFFF8 002BFFF8 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1BFFFC 002BFFFC 5CCA0A0C */  jal        func_002b2970
    /* 1C0000 002C0000 00000000 */   nop
    /* 1C0004 002C0004 440C248E */  lw         $4, 0xC44($17)
    /* 1C0008 002C0008 0806A5DF */  ld         $5, 0x608($29)
    /* 1C000C 002C000C 0006A6DF */  ld         $6, 0x600($29)
    /* 1C0010 002C0010 01000724 */  addiu      $7, $0, 0x1
    /* 1C0014 002C0014 02000824 */  addiu      $8, $0, 0x2
    /* 1C0018 002C0018 2D480000 */  daddu      $9, $0, $0
    /* 1C001C 002C001C 88810B0C */  jal        func_002e0620
    /* 1C0020 002C0020 00000000 */   nop
    /* 1C0024 002C0024 480C248E */  lw         $4, 0xC48($17)
    /* 1C0028 002C0028 38810B0C */  jal        func_002e04e0
    /* 1C002C 002C002C 00000000 */   nop
    /* 1C0030 002C0030 2D804000 */  daddu      $16, $2, $0
    /* 1C0034 002C0034 480C248E */  lw         $4, 0xC48($17)
    /* 1C0038 002C0038 38810B0C */  jal        func_002e04e0
    /* 1C003C 002C003C 00000000 */   nop
    /* 1C0040 002C0040 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C0044 002C0044 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C0048 002C0048 00008244 */  mtc1       $2, $f0
    /* 1C004C 002C004C 00000000 */  nop
    /* 1C0050 002C0050 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C0054 002C0054 F805A427 */  addiu      $4, $29, 0x5F8
    /* 1C0058 002C0058 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C005C 002C005C 5CCA0A0C */  jal        func_002b2970
    /* 1C0060 002C0060 00000000 */   nop
    /* 1C0064 002C0064 480C248E */  lw         $4, 0xC48($17)
    /* 1C0068 002C0068 38810B0C */  jal        func_002e04e0
    /* 1C006C 002C006C 00000000 */   nop
    /* 1C0070 002C0070 2D804000 */  daddu      $16, $2, $0
    /* 1C0074 002C0074 480C248E */  lw         $4, 0xC48($17)
    /* 1C0078 002C0078 38810B0C */  jal        func_002e04e0
    /* 1C007C 002C007C 00000000 */   nop
    /* 1C0080 002C0080 F005A427 */  addiu      $4, $29, 0x5F0
    /* 1C0084 002C0084 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C0088 002C0088 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C008C 002C008C 5CCA0A0C */  jal        func_002b2970
    /* 1C0090 002C0090 00000000 */   nop
    /* 1C0094 002C0094 480C248E */  lw         $4, 0xC48($17)
    /* 1C0098 002C0098 F805A5DF */  ld         $5, 0x5F8($29)
    /* 1C009C 002C009C F005A6DF */  ld         $6, 0x5F0($29)
    /* 1C00A0 002C00A0 01000724 */  addiu      $7, $0, 0x1
    /* 1C00A4 002C00A4 02000824 */  addiu      $8, $0, 0x2
    /* 1C00A8 002C00A8 2D480000 */  daddu      $9, $0, $0
    /* 1C00AC 002C00AC 88810B0C */  jal        func_002e0620
    /* 1C00B0 002C00B0 00000000 */   nop
    /* 1C00B4 002C00B4 2D800000 */  daddu      $16, $0, $0
    /* 1C00B8 002C00B8 18000010 */  b          .L002C011C
    /* 1C00BC 002C00BC 00000000 */   nop
  .L002C00C0:
    /* 1C00C0 002C00C0 5407A427 */  addiu      $4, $29, 0x754
    /* 1C00C4 002C00C4 ED000524 */  addiu      $5, $0, 0xED
    /* 1C00C8 002C00C8 80000624 */  addiu      $6, $0, 0x80
    /* 1C00CC 002C00CC 2D380000 */  daddu      $7, $0, $0
    /* 1C00D0 002C00D0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C00D4 002C00D4 98CA0A0C */  jal        func_002b2a60
    /* 1C00D8 002C00D8 00000000 */   nop
    /* 1C00DC 002C00DC 80101200 */  sll        $2, $18, 2
    /* 1C00E0 002C00E0 21102202 */  addu       $2, $17, $2
    /* 1C00E4 002C00E4 240D448C */  lw         $4, 0xD24($2)
    /* 1C00E8 002C00E8 38810B0C */  jal        func_002e04e0
    /* 1C00EC 002C00EC 00000000 */   nop
    /* 1C00F0 002C00F0 5407A693 */  lbu        $6, 0x754($29)
    /* 1C00F4 002C00F4 5507A593 */  lbu        $5, 0x755($29)
    /* 1C00F8 002C00F8 5607A493 */  lbu        $4, 0x756($29)
    /* 1C00FC 002C00FC 5707A393 */  lbu        $3, 0x757($29)
    /* 1C0100 002C0100 790046A0 */  sb         $6, 0x79($2)
    /* 1C0104 002C0104 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C0108 002C0108 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C010C 002C010C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C0110 002C0110 01000226 */  addiu      $2, $16, 0x1
    /* 1C0114 002C0114 3C840200 */  dsll32     $16, $2, 16
    /* 1C0118 002C0118 3F841000 */  dsra32     $16, $16, 16
  .L002C011C:
    /* 1C011C 002C011C 3C941000 */  dsll32     $18, $16, 16
    /* 1C0120 002C0120 3F941200 */  dsra32     $18, $18, 16
    /* 1C0124 002C0124 0600422A */  slti       $2, $18, 0x6
    /* 1C0128 002C0128 E5FF4014 */  bnez       $2, .L002C00C0
    /* 1C012C 002C012C 00000000 */   nop
    /* 1C0130 002C0130 5007A427 */  addiu      $4, $29, 0x750
    /* 1C0134 002C0134 2D000524 */  addiu      $5, $0, 0x2D
    /* 1C0138 002C0138 2D30A000 */  daddu      $6, $5, $0
    /* 1C013C 002C013C 2D38A000 */  daddu      $7, $5, $0
    /* 1C0140 002C0140 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C0144 002C0144 98CA0A0C */  jal        func_002b2a60
    /* 1C0148 002C0148 00000000 */   nop
    /* 1C014C 002C014C 07002282 */  lb         $2, 0x7($17)
    /* 1C0150 002C0150 80100200 */  sll        $2, $2, 2
    /* 1C0154 002C0154 21105100 */  addu       $2, $2, $17
    /* 1C0158 002C0158 240D448C */  lw         $4, 0xD24($2)
    /* 1C015C 002C015C 38810B0C */  jal        func_002e04e0
    /* 1C0160 002C0160 00000000 */   nop
    /* 1C0164 002C0164 5007A693 */  lbu        $6, 0x750($29)
    /* 1C0168 002C0168 5107A593 */  lbu        $5, 0x751($29)
    /* 1C016C 002C016C 5207A493 */  lbu        $4, 0x752($29)
    /* 1C0170 002C0170 5307A393 */  lbu        $3, 0x753($29)
    /* 1C0174 002C0174 790046A0 */  sb         $6, 0x79($2)
    /* 1C0178 002C0178 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C017C 002C017C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C0180 002C0180 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C0184 002C0184 2D200000 */  daddu      $4, $0, $0
    /* 1C0188 002C0188 2D280000 */  daddu      $5, $0, $0
    /* 1C018C 002C018C 2D300000 */  daddu      $6, $0, $0
    /* 1C0190 002C0190 2D380000 */  daddu      $7, $0, $0
    /* 1C0194 002C0194 D86B110C */  jal        func_0045af60
    /* 1C0198 002C0198 00000000 */   nop
    /* 1C019C 002C019C 62290010 */  b          .L002CA728
    /* 1C01A0 002C01A0 00000000 */   nop
  .L002C01A4:
    /* 1C01A4 002C01A4 00106230 */  andi       $2, $3, 0x1000
    /* 1C01A8 002C01A8 AD004010 */  beqz       $2, .L002C0460
    /* 1C01AC 002C01AC 00000000 */   nop
    /* 1C01B0 002C01B0 07002482 */  lb         $4, 0x7($17)
    /* 1C01B4 002C01B4 01000524 */  addiu      $5, $0, 0x1
    /* 1C01B8 002C01B8 2D300000 */  daddu      $6, $0, $0
    /* 1C01BC 002C01BC 05000724 */  addiu      $7, $0, 0x5
    /* 1C01C0 002C01C0 02000824 */  addiu      $8, $0, 0x2
    /* 1C01C4 002C01C4 40CB0A0C */  jal        func_002b2d00
    /* 1C01C8 002C01C8 00000000 */   nop
    /* 1C01CC 002C01CC 070022A2 */  sb         $2, 0x7($17)
    /* 1C01D0 002C01D0 2D208002 */  daddu      $4, $20, $0
    /* 1C01D4 002C01D4 E45F0B0C */  jal        func_002d7f90
    /* 1C01D8 002C01D8 00000000 */   nop
    /* 1C01DC 002C01DC 07002382 */  lb         $3, 0x7($17)
    /* 1C01E0 002C01E0 40100300 */  sll        $2, $3, 1
    /* 1C01E4 002C01E4 21104300 */  addu       $2, $2, $3
    /* 1C01E8 002C01E8 80180200 */  sll        $3, $2, 2
    /* 1C01EC 002C01EC 6400023C */  lui        $2, %hi(D_0063F9F0)
    /* 1C01F0 002C01F0 F0F94224 */  addiu      $2, $2, %lo(D_0063F9F0)
    /* 1C01F4 002C01F4 21804300 */  addu       $16, $2, $3
    /* 1C01F8 002C01F8 000014C6 */  lwc1       $f20, 0x0($16)
    /* 1C01FC 002C01FC 440C248E */  lw         $4, 0xC44($17)
    /* 1C0200 002C0200 38810B0C */  jal        func_002e04e0
    /* 1C0204 002C0204 00000000 */   nop
    /* 1C0208 002C0208 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C020C 002C020C 040014C6 */  lwc1       $f20, 0x4($16)
    /* 1C0210 002C0210 440C248E */  lw         $4, 0xC44($17)
    /* 1C0214 002C0214 38810B0C */  jal        func_002e04e0
    /* 1C0218 002C0218 00000000 */   nop
    /* 1C021C 002C021C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C0220 002C0220 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1C0224 002C0224 080000C6 */  lwc1       $f0, 0x8($16)
    /* 1C0228 002C0228 000D0046 */  add.s      $f20, $f1, $f0
    /* 1C022C 002C022C 480C248E */  lw         $4, 0xC48($17)
    /* 1C0230 002C0230 38810B0C */  jal        func_002e04e0
    /* 1C0234 002C0234 00000000 */   nop
    /* 1C0238 002C0238 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C023C 002C023C 040014C6 */  lwc1       $f20, 0x4($16)
    /* 1C0240 002C0240 480C248E */  lw         $4, 0xC48($17)
    /* 1C0244 002C0244 38810B0C */  jal        func_002e04e0
    /* 1C0248 002C0248 00000000 */   nop
    /* 1C024C 002C024C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C0250 002C0250 440C248E */  lw         $4, 0xC44($17)
    /* 1C0254 002C0254 38810B0C */  jal        func_002e04e0
    /* 1C0258 002C0258 00000000 */   nop
    /* 1C025C 002C025C 2D804000 */  daddu      $16, $2, $0
    /* 1C0260 002C0260 440C248E */  lw         $4, 0xC44($17)
    /* 1C0264 002C0264 38810B0C */  jal        func_002e04e0
    /* 1C0268 002C0268 00000000 */   nop
    /* 1C026C 002C026C 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C0270 002C0270 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C0274 002C0274 00008244 */  mtc1       $2, $f0
    /* 1C0278 002C0278 00000000 */  nop
    /* 1C027C 002C027C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C0280 002C0280 E805A427 */  addiu      $4, $29, 0x5E8
    /* 1C0284 002C0284 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C0288 002C0288 5CCA0A0C */  jal        func_002b2970
    /* 1C028C 002C028C 00000000 */   nop
    /* 1C0290 002C0290 440C248E */  lw         $4, 0xC44($17)
    /* 1C0294 002C0294 38810B0C */  jal        func_002e04e0
    /* 1C0298 002C0298 00000000 */   nop
    /* 1C029C 002C029C 2D804000 */  daddu      $16, $2, $0
    /* 1C02A0 002C02A0 440C248E */  lw         $4, 0xC44($17)
    /* 1C02A4 002C02A4 38810B0C */  jal        func_002e04e0
    /* 1C02A8 002C02A8 00000000 */   nop
    /* 1C02AC 002C02AC E005A427 */  addiu      $4, $29, 0x5E0
    /* 1C02B0 002C02B0 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C02B4 002C02B4 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C02B8 002C02B8 5CCA0A0C */  jal        func_002b2970
    /* 1C02BC 002C02BC 00000000 */   nop
    /* 1C02C0 002C02C0 440C248E */  lw         $4, 0xC44($17)
    /* 1C02C4 002C02C4 E805A5DF */  ld         $5, 0x5E8($29)
    /* 1C02C8 002C02C8 E005A6DF */  ld         $6, 0x5E0($29)
    /* 1C02CC 002C02CC 01000724 */  addiu      $7, $0, 0x1
    /* 1C02D0 002C02D0 02000824 */  addiu      $8, $0, 0x2
    /* 1C02D4 002C02D4 2D480000 */  daddu      $9, $0, $0
    /* 1C02D8 002C02D8 88810B0C */  jal        func_002e0620
    /* 1C02DC 002C02DC 00000000 */   nop
    /* 1C02E0 002C02E0 480C248E */  lw         $4, 0xC48($17)
    /* 1C02E4 002C02E4 38810B0C */  jal        func_002e04e0
    /* 1C02E8 002C02E8 00000000 */   nop
    /* 1C02EC 002C02EC 2D804000 */  daddu      $16, $2, $0
    /* 1C02F0 002C02F0 480C248E */  lw         $4, 0xC48($17)
    /* 1C02F4 002C02F4 38810B0C */  jal        func_002e04e0
    /* 1C02F8 002C02F8 00000000 */   nop
    /* 1C02FC 002C02FC 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C0300 002C0300 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C0304 002C0304 00008244 */  mtc1       $2, $f0
    /* 1C0308 002C0308 00000000 */  nop
    /* 1C030C 002C030C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C0310 002C0310 D805A427 */  addiu      $4, $29, 0x5D8
    /* 1C0314 002C0314 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C0318 002C0318 5CCA0A0C */  jal        func_002b2970
    /* 1C031C 002C031C 00000000 */   nop
    /* 1C0320 002C0320 480C248E */  lw         $4, 0xC48($17)
    /* 1C0324 002C0324 38810B0C */  jal        func_002e04e0
    /* 1C0328 002C0328 00000000 */   nop
    /* 1C032C 002C032C 2D804000 */  daddu      $16, $2, $0
    /* 1C0330 002C0330 480C248E */  lw         $4, 0xC48($17)
    /* 1C0334 002C0334 38810B0C */  jal        func_002e04e0
    /* 1C0338 002C0338 00000000 */   nop
    /* 1C033C 002C033C D005A427 */  addiu      $4, $29, 0x5D0
    /* 1C0340 002C0340 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C0344 002C0344 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C0348 002C0348 5CCA0A0C */  jal        func_002b2970
    /* 1C034C 002C034C 00000000 */   nop
    /* 1C0350 002C0350 480C248E */  lw         $4, 0xC48($17)
    /* 1C0354 002C0354 D805A5DF */  ld         $5, 0x5D8($29)
    /* 1C0358 002C0358 D005A6DF */  ld         $6, 0x5D0($29)
    /* 1C035C 002C035C 01000724 */  addiu      $7, $0, 0x1
    /* 1C0360 002C0360 02000824 */  addiu      $8, $0, 0x2
    /* 1C0364 002C0364 2D480000 */  daddu      $9, $0, $0
    /* 1C0368 002C0368 88810B0C */  jal        func_002e0620
    /* 1C036C 002C036C 00000000 */   nop
    /* 1C0370 002C0370 2D800000 */  daddu      $16, $0, $0
    /* 1C0374 002C0374 18000010 */  b          .L002C03D8
    /* 1C0378 002C0378 00000000 */   nop
  .L002C037C:
    /* 1C037C 002C037C 4C07A427 */  addiu      $4, $29, 0x74C
    /* 1C0380 002C0380 ED000524 */  addiu      $5, $0, 0xED
    /* 1C0384 002C0384 80000624 */  addiu      $6, $0, 0x80
    /* 1C0388 002C0388 2D380000 */  daddu      $7, $0, $0
    /* 1C038C 002C038C FF000824 */  addiu      $8, $0, 0xFF
    /* 1C0390 002C0390 98CA0A0C */  jal        func_002b2a60
    /* 1C0394 002C0394 00000000 */   nop
    /* 1C0398 002C0398 80101200 */  sll        $2, $18, 2
    /* 1C039C 002C039C 21102202 */  addu       $2, $17, $2
    /* 1C03A0 002C03A0 240D448C */  lw         $4, 0xD24($2)
    /* 1C03A4 002C03A4 38810B0C */  jal        func_002e04e0
    /* 1C03A8 002C03A8 00000000 */   nop
    /* 1C03AC 002C03AC 4C07A693 */  lbu        $6, 0x74C($29)
    /* 1C03B0 002C03B0 4D07A593 */  lbu        $5, 0x74D($29)
    /* 1C03B4 002C03B4 4E07A493 */  lbu        $4, 0x74E($29)
    /* 1C03B8 002C03B8 4F07A393 */  lbu        $3, 0x74F($29)
    /* 1C03BC 002C03BC 790046A0 */  sb         $6, 0x79($2)
    /* 1C03C0 002C03C0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C03C4 002C03C4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C03C8 002C03C8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C03CC 002C03CC 01000226 */  addiu      $2, $16, 0x1
    /* 1C03D0 002C03D0 3C840200 */  dsll32     $16, $2, 16
    /* 1C03D4 002C03D4 3F841000 */  dsra32     $16, $16, 16
  .L002C03D8:
    /* 1C03D8 002C03D8 3C941000 */  dsll32     $18, $16, 16
    /* 1C03DC 002C03DC 3F941200 */  dsra32     $18, $18, 16
    /* 1C03E0 002C03E0 0600422A */  slti       $2, $18, 0x6
    /* 1C03E4 002C03E4 E5FF4014 */  bnez       $2, .L002C037C
    /* 1C03E8 002C03E8 00000000 */   nop
    /* 1C03EC 002C03EC 4807A427 */  addiu      $4, $29, 0x748
    /* 1C03F0 002C03F0 2D000524 */  addiu      $5, $0, 0x2D
    /* 1C03F4 002C03F4 2D30A000 */  daddu      $6, $5, $0
    /* 1C03F8 002C03F8 2D38A000 */  daddu      $7, $5, $0
    /* 1C03FC 002C03FC FF000824 */  addiu      $8, $0, 0xFF
    /* 1C0400 002C0400 98CA0A0C */  jal        func_002b2a60
    /* 1C0404 002C0404 00000000 */   nop
    /* 1C0408 002C0408 07002282 */  lb         $2, 0x7($17)
    /* 1C040C 002C040C 80100200 */  sll        $2, $2, 2
    /* 1C0410 002C0410 21105100 */  addu       $2, $2, $17
    /* 1C0414 002C0414 240D448C */  lw         $4, 0xD24($2)
    /* 1C0418 002C0418 38810B0C */  jal        func_002e04e0
    /* 1C041C 002C041C 00000000 */   nop
    /* 1C0420 002C0420 4807A693 */  lbu        $6, 0x748($29)
    /* 1C0424 002C0424 4907A593 */  lbu        $5, 0x749($29)
    /* 1C0428 002C0428 4A07A493 */  lbu        $4, 0x74A($29)
    /* 1C042C 002C042C 4B07A393 */  lbu        $3, 0x74B($29)
    /* 1C0430 002C0430 790046A0 */  sb         $6, 0x79($2)
    /* 1C0434 002C0434 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C0438 002C0438 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C043C 002C043C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C0440 002C0440 2D200000 */  daddu      $4, $0, $0
    /* 1C0444 002C0444 2D280000 */  daddu      $5, $0, $0
    /* 1C0448 002C0448 2D300000 */  daddu      $6, $0, $0
    /* 1C044C 002C044C 2D380000 */  daddu      $7, $0, $0
    /* 1C0450 002C0450 D86B110C */  jal        func_0045af60
    /* 1C0454 002C0454 00000000 */   nop
    /* 1C0458 002C0458 B3280010 */  b          .L002CA728
    /* 1C045C 002C045C 00000000 */   nop
  .L002C0460:
    /* 1C0460 002C0460 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 1C0464 002C0464 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 1C0468 002C0468 40006230 */  andi       $2, $3, 0x40
    /* 1C046C 002C046C 41004010 */  beqz       $2, .L002C0574
    /* 1C0470 002C0470 00000000 */   nop
    /* 1C0474 002C0474 440C248E */  lw         $4, 0xC44($17)
    /* 1C0478 002C0478 38810B0C */  jal        func_002e04e0
    /* 1C047C 002C047C 00000000 */   nop
    /* 1C0480 002C0480 00688044 */  mtc1       $0, $f13
    /* 1C0484 002C0484 440C248E */  lw         $4, 0xC44($17)
    /* 1C0488 002C0488 C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C048C 002C048C 2D280000 */  daddu      $5, $0, $0
    /* 1C0490 002C0490 02000624 */  addiu      $6, $0, 0x2
    /* 1C0494 002C0494 2D380000 */  daddu      $7, $0, $0
    /* 1C0498 002C0498 50820B0C */  jal        func_002e0940
    /* 1C049C 002C049C 00000000 */   nop
    /* 1C04A0 002C04A0 480C248E */  lw         $4, 0xC48($17)
    /* 1C04A4 002C04A4 38810B0C */  jal        func_002e04e0
    /* 1C04A8 002C04A8 00000000 */   nop
    /* 1C04AC 002C04AC 00688044 */  mtc1       $0, $f13
    /* 1C04B0 002C04B0 480C248E */  lw         $4, 0xC48($17)
    /* 1C04B4 002C04B4 C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C04B8 002C04B8 2D280000 */  daddu      $5, $0, $0
    /* 1C04BC 002C04BC 02000624 */  addiu      $6, $0, 0x2
    /* 1C04C0 002C04C0 2D380000 */  daddu      $7, $0, $0
    /* 1C04C4 002C04C4 50820B0C */  jal        func_002e0940
    /* 1C04C8 002C04C8 00000000 */   nop
    /* 1C04CC 002C04CC 2D900000 */  daddu      $18, $0, $0
    /* 1C04D0 002C04D0 18000010 */  b          .L002C0534
    /* 1C04D4 002C04D4 00000000 */   nop
  .L002C04D8:
    /* 1C04D8 002C04D8 3C141200 */  dsll32     $2, $18, 16
    /* 1C04DC 002C04DC 3F140200 */  dsra32     $2, $2, 16
    /* 1C04E0 002C04E0 80100200 */  sll        $2, $2, 2
    /* 1C04E4 002C04E4 21802202 */  addu       $16, $17, $2
    /* 1C04E8 002C04E8 440C1326 */  addiu      $19, $16, 0xC44
    /* 1C04EC 002C04EC 440C048E */  lw         $4, 0xC44($16)
    /* 1C04F0 002C04F0 38810B0C */  jal        func_002e04e0
    /* 1C04F4 002C04F4 00000000 */   nop
    /* 1C04F8 002C04F8 79004290 */  lbu        $2, 0x79($2)
    /* 1C04FC 002C04FC 3E0F02A2 */  sb         $2, 0xF3E($16)
    /* 1C0500 002C0500 0000648E */  lw         $4, 0x0($19)
    /* 1C0504 002C0504 38810B0C */  jal        func_002e04e0
    /* 1C0508 002C0508 00000000 */   nop
    /* 1C050C 002C050C 7A004290 */  lbu        $2, 0x7A($2)
    /* 1C0510 002C0510 3F0F02A2 */  sb         $2, 0xF3F($16)
    /* 1C0514 002C0514 0000648E */  lw         $4, 0x0($19)
    /* 1C0518 002C0518 38810B0C */  jal        func_002e04e0
    /* 1C051C 002C051C 00000000 */   nop
    /* 1C0520 002C0520 7B004290 */  lbu        $2, 0x7B($2)
    /* 1C0524 002C0524 400F02A2 */  sb         $2, 0xF40($16)
    /* 1C0528 002C0528 01004226 */  addiu      $2, $18, 0x1
    /* 1C052C 002C052C 3C940200 */  dsll32     $18, $2, 16
    /* 1C0530 002C0530 3F941200 */  dsra32     $18, $18, 16
  .L002C0534:
    /* 1C0534 002C0534 3C141200 */  dsll32     $2, $18, 16
    /* 1C0538 002C0538 3F140200 */  dsra32     $2, $2, 16
    /* 1C053C 002C053C 02004228 */  slti       $2, $2, 0x2
    /* 1C0540 002C0540 E5FF4014 */  bnez       $2, .L002C04D8
    /* 1C0544 002C0544 00000000 */   nop
    /* 1C0548 002C0548 3C0F20A6 */  sh         $0, 0xF3C($17)
    /* 1C054C 002C054C 12000224 */  addiu      $2, $0, 0x12
    /* 1C0550 002C0550 000022A2 */  sb         $2, 0x0($17)
    /* 1C0554 002C0554 2D200000 */  daddu      $4, $0, $0
    /* 1C0558 002C0558 2D280000 */  daddu      $5, $0, $0
    /* 1C055C 002C055C 2D300000 */  daddu      $6, $0, $0
    /* 1C0560 002C0560 01000724 */  addiu      $7, $0, 0x1
    /* 1C0564 002C0564 D86B110C */  jal        func_0045af60
    /* 1C0568 002C0568 00000000 */   nop
    /* 1C056C 002C056C 6E280010 */  b          .L002CA728
    /* 1C0570 002C0570 00000000 */   nop
  .L002C0574:
    /* 1C0574 002C0574 20006230 */  andi       $2, $3, 0x20
    /* 1C0578 002C0578 6B284010 */  beqz       $2, .L002CA728
    /* 1C057C 002C057C 00000000 */   nop
    /* 1C0580 002C0580 2D800000 */  daddu      $16, $0, $0
    /* 1C0584 002C0584 12000010 */  b          .L002C05D0
    /* 1C0588 002C0588 00000000 */   nop
  .L002C058C:
    /* 1C058C 002C058C 3C241000 */  dsll32     $4, $16, 16
    /* 1C0590 002C0590 3F240400 */  dsra32     $4, $4, 16
    /* 1C0594 002C0594 80100400 */  sll        $2, $4, 2
    /* 1C0598 002C0598 21182202 */  addu       $3, $17, $2
    /* 1C059C 002C059C 40100400 */  sll        $2, $4, 1
    /* 1C05A0 002C05A0 3C4C0200 */  dsll32     $9, $2, 16
    /* 1C05A4 002C05A4 3F4C0900 */  dsra32     $9, $9, 16
    /* 1C05A8 002C05A8 200D648C */  lw         $4, 0xD20($3)
    /* 1C05AC 002C05AC FF000524 */  addiu      $5, $0, 0xFF
    /* 1C05B0 002C05B0 2D300000 */  daddu      $6, $0, $0
    /* 1C05B4 002C05B4 2D380000 */  daddu      $7, $0, $0
    /* 1C05B8 002C05B8 05000824 */  addiu      $8, $0, 0x5
    /* 1C05BC 002C05BC 98810B0C */  jal        func_002e0660
    /* 1C05C0 002C05C0 00000000 */   nop
    /* 1C05C4 002C05C4 01000226 */  addiu      $2, $16, 0x1
    /* 1C05C8 002C05C8 3C840200 */  dsll32     $16, $2, 16
    /* 1C05CC 002C05CC 3F841000 */  dsra32     $16, $16, 16
  .L002C05D0:
    /* 1C05D0 002C05D0 3C141000 */  dsll32     $2, $16, 16
    /* 1C05D4 002C05D4 3F140200 */  dsra32     $2, $2, 16
    /* 1C05D8 002C05D8 07004228 */  slti       $2, $2, 0x7
    /* 1C05DC 002C05DC EBFF4014 */  bnez       $2, .L002C058C
    /* 1C05E0 002C05E0 00000000 */   nop
    /* 1C05E4 002C05E4 07002282 */  lb         $2, 0x7($17)
    /* 1C05E8 002C05E8 40100200 */  sll        $2, $2, 1
    /* 1C05EC 002C05EC 02004224 */  addiu      $2, $2, 0x2
    /* 1C05F0 002C05F0 3C4C0200 */  dsll32     $9, $2, 16
    /* 1C05F4 002C05F4 3F4C0900 */  dsra32     $9, $9, 16
    /* 1C05F8 002C05F8 440C248E */  lw         $4, 0xC44($17)
    /* 1C05FC 002C05FC FF000524 */  addiu      $5, $0, 0xFF
    /* 1C0600 002C0600 2D300000 */  daddu      $6, $0, $0
    /* 1C0604 002C0604 2D380000 */  daddu      $7, $0, $0
    /* 1C0608 002C0608 2D400000 */  daddu      $8, $0, $0
    /* 1C060C 002C060C 98810B0C */  jal        func_002e0660
    /* 1C0610 002C0610 00000000 */   nop
    /* 1C0614 002C0614 07002282 */  lb         $2, 0x7($17)
    /* 1C0618 002C0618 40100200 */  sll        $2, $2, 1
    /* 1C061C 002C061C 02004224 */  addiu      $2, $2, 0x2
    /* 1C0620 002C0620 3C4C0200 */  dsll32     $9, $2, 16
    /* 1C0624 002C0624 3F4C0900 */  dsra32     $9, $9, 16
    /* 1C0628 002C0628 480C248E */  lw         $4, 0xC48($17)
    /* 1C062C 002C062C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C0630 002C0630 2D300000 */  daddu      $6, $0, $0
    /* 1C0634 002C0634 2D380000 */  daddu      $7, $0, $0
    /* 1C0638 002C0638 2D400000 */  daddu      $8, $0, $0
    /* 1C063C 002C063C 98810B0C */  jal        func_002e0660
    /* 1C0640 002C0640 00000000 */   nop
    /* 1C0644 002C0644 3F43023C */  lui        $2, (0x433F0000 >> 16)
    /* 1C0648 002C0648 00608244 */  mtc1       $2, $f12
    /* 1C064C 002C064C 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C0650 002C0650 40000524 */  addiu      $5, $0, 0x40
    /* 1C0654 002C0654 78820B0C */  jal        func_002e09e0
    /* 1C0658 002C0658 00000000 */   nop
    /* 1C065C 002C065C 280F248E */  lw         $4, 0xF28($17)
    /* 1C0660 002C0660 05000524 */  addiu      $5, $0, 0x5
    /* 1C0664 002C0664 80B4110C */  jal        func_0046d200
    /* 1C0668 002C0668 00000000 */   nop
    /* 1C066C 002C066C 2D804000 */  daddu      $16, $2, $0
    /* 1C0670 002C0670 2D200002 */  daddu      $4, $16, $0
    /* 1C0674 002C0674 98AC110C */  jal        func_0046b260
    /* 1C0678 002C0678 00000000 */   nop
    /* 1C067C 002C067C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C0680 002C0680 00088244 */  mtc1       $2, $f1
    /* 1C0684 002C0684 00000000 */  nop
    /* 1C0688 002C0688 03000146 */  div.s      $f0, $f0, $f1
    /* 1C068C 002C068C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0690 002C0690 00000244 */  mfc1       $2, $f0
    /* 1C0694 002C0694 00000000 */  nop
    /* 1C0698 002C0698 3C940200 */  dsll32     $18, $2, 16
    /* 1C069C 002C069C 3F941200 */  dsra32     $18, $18, 16
    /* 1C06A0 002C06A0 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C06A4 002C06A4 38810B0C */  jal        func_002e04e0
    /* 1C06A8 002C06A8 00000000 */   nop
    /* 1C06AC 002C06AC 000152A4 */  sh         $18, 0x100($2)
    /* 1C06B0 002C06B0 2D200002 */  daddu      $4, $16, $0
    /* 1C06B4 002C06B4 BCAC110C */  jal        func_0046b2f0
    /* 1C06B8 002C06B8 00000000 */   nop
    /* 1C06BC 002C06BC 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C06C0 002C06C0 00088244 */  mtc1       $2, $f1
    /* 1C06C4 002C06C4 00000000 */  nop
    /* 1C06C8 002C06C8 03000146 */  div.s      $f0, $f0, $f1
    /* 1C06CC 002C06CC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C06D0 002C06D0 00000244 */  mfc1       $2, $f0
    /* 1C06D4 002C06D4 00000000 */  nop
    /* 1C06D8 002C06D8 3C940200 */  dsll32     $18, $2, 16
    /* 1C06DC 002C06DC 3F941200 */  dsra32     $18, $18, 16
    /* 1C06E0 002C06E0 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C06E4 002C06E4 38810B0C */  jal        func_002e04e0
    /* 1C06E8 002C06E8 00000000 */   nop
    /* 1C06EC 002C06EC 020152A4 */  sh         $18, 0x102($2)
    /* 1C06F0 002C06F0 2D200002 */  daddu      $4, $16, $0
    /* 1C06F4 002C06F4 A0B4110C */  jal        func_0046d280
    /* 1C06F8 002C06F8 00000000 */   nop
    /* 1C06FC 002C06FC 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C0700 002C0700 38810B0C */  jal        func_002e04e0
    /* 1C0704 002C0704 00000000 */   nop
    /* 1C0708 002C0708 2D804000 */  daddu      $16, $2, $0
    /* 1C070C 002C070C 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C0710 002C0710 38810B0C */  jal        func_002e04e0
    /* 1C0714 002C0714 00000000 */   nop
    /* 1C0718 002C0718 C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C071C 002C071C A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1C0720 002C0720 00008244 */  mtc1       $2, $f0
    /* 1C0724 002C0724 00000000 */  nop
    /* 1C0728 002C0728 40030146 */  add.s      $f13, $f0, $f1
    /* 1C072C 002C072C 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C0730 002C0730 C4000CC6 */  lwc1       $f12, 0xC4($16)
    /* 1C0734 002C0734 2D280000 */  daddu      $5, $0, $0
    /* 1C0738 002C0738 0A000624 */  addiu      $6, $0, 0xA
    /* 1C073C 002C073C 2D380000 */  daddu      $7, $0, $0
    /* 1C0740 002C0740 50820B0C */  jal        func_002e0940
    /* 1C0744 002C0744 00000000 */   nop
    /* 1C0748 002C0748 6041023C */  lui        $2, (0x41600000 >> 16)
    /* 1C074C 002C074C 00A08244 */  mtc1       $2, $f20
    /* 1C0750 002C0750 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C0754 002C0754 38810B0C */  jal        func_002e04e0
    /* 1C0758 002C0758 00000000 */   nop
    /* 1C075C 002C075C 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C0760 002C0760 2443023C */  lui        $2, (0x43240000 >> 16)
    /* 1C0764 002C0764 00A08244 */  mtc1       $2, $f20
    /* 1C0768 002C0768 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C076C 002C076C 38810B0C */  jal        func_002e04e0
    /* 1C0770 002C0770 00000000 */   nop
    /* 1C0774 002C0774 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C0778 002C0778 4043023C */  lui        $2, (0x43400000 >> 16)
    /* 1C077C 002C077C 00608244 */  mtc1       $2, $f12
    /* 1C0780 002C0780 500C248E */  lw         $4, 0xC50($17)
    /* 1C0784 002C0784 40000524 */  addiu      $5, $0, 0x40
    /* 1C0788 002C0788 78820B0C */  jal        func_002e09e0
    /* 1C078C 002C078C 00000000 */   nop
    /* 1C0790 002C0790 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 1C0794 002C0794 00A08244 */  mtc1       $2, $f20
    /* 1C0798 002C0798 500C248E */  lw         $4, 0xC50($17)
    /* 1C079C 002C079C 38810B0C */  jal        func_002e04e0
    /* 1C07A0 002C07A0 00000000 */   nop
    /* 1C07A4 002C07A4 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C07A8 002C07A8 0243023C */  lui        $2, (0x43020000 >> 16)
    /* 1C07AC 002C07AC 00A08244 */  mtc1       $2, $f20
    /* 1C07B0 002C07B0 500C248E */  lw         $4, 0xC50($17)
    /* 1C07B4 002C07B4 38810B0C */  jal        func_002e04e0
    /* 1C07B8 002C07B8 00000000 */   nop
    /* 1C07BC 002C07BC 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C07C0 002C07C0 280F248E */  lw         $4, 0xF28($17)
    /* 1C07C4 002C07C4 06000524 */  addiu      $5, $0, 0x6
    /* 1C07C8 002C07C8 80B4110C */  jal        func_0046d200
    /* 1C07CC 002C07CC 00000000 */   nop
    /* 1C07D0 002C07D0 2D804000 */  daddu      $16, $2, $0
    /* 1C07D4 002C07D4 2D200002 */  daddu      $4, $16, $0
    /* 1C07D8 002C07D8 98AC110C */  jal        func_0046b260
    /* 1C07DC 002C07DC 00000000 */   nop
    /* 1C07E0 002C07E0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C07E4 002C07E4 00088244 */  mtc1       $2, $f1
    /* 1C07E8 002C07E8 00000000 */  nop
    /* 1C07EC 002C07EC 03000146 */  div.s      $f0, $f0, $f1
    /* 1C07F0 002C07F0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C07F4 002C07F4 00000244 */  mfc1       $2, $f0
    /* 1C07F8 002C07F8 00000000 */  nop
    /* 1C07FC 002C07FC 3C940200 */  dsll32     $18, $2, 16
    /* 1C0800 002C0800 3F941200 */  dsra32     $18, $18, 16
    /* 1C0804 002C0804 500C248E */  lw         $4, 0xC50($17)
    /* 1C0808 002C0808 38810B0C */  jal        func_002e04e0
    /* 1C080C 002C080C 00000000 */   nop
    /* 1C0810 002C0810 000152A4 */  sh         $18, 0x100($2)
    /* 1C0814 002C0814 2D200002 */  daddu      $4, $16, $0
    /* 1C0818 002C0818 BCAC110C */  jal        func_0046b2f0
    /* 1C081C 002C081C 00000000 */   nop
    /* 1C0820 002C0820 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C0824 002C0824 00088244 */  mtc1       $2, $f1
    /* 1C0828 002C0828 00000000 */  nop
    /* 1C082C 002C082C 03000146 */  div.s      $f0, $f0, $f1
    /* 1C0830 002C0830 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0834 002C0834 00000244 */  mfc1       $2, $f0
    /* 1C0838 002C0838 00000000 */  nop
    /* 1C083C 002C083C 3C940200 */  dsll32     $18, $2, 16
    /* 1C0840 002C0840 3F941200 */  dsra32     $18, $18, 16
    /* 1C0844 002C0844 500C248E */  lw         $4, 0xC50($17)
    /* 1C0848 002C0848 38810B0C */  jal        func_002e04e0
    /* 1C084C 002C084C 00000000 */   nop
    /* 1C0850 002C0850 020152A4 */  sh         $18, 0x102($2)
    /* 1C0854 002C0854 500C248E */  lw         $4, 0xC50($17)
    /* 1C0858 002C0858 38810B0C */  jal        func_002e04e0
    /* 1C085C 002C085C 00000000 */   nop
    /* 1C0860 002C0860 2D904000 */  daddu      $18, $2, $0
    /* 1C0864 002C0864 500C248E */  lw         $4, 0xC50($17)
    /* 1C0868 002C0868 38810B0C */  jal        func_002e04e0
    /* 1C086C 002C086C 00000000 */   nop
    /* 1C0870 002C0870 C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C0874 002C0874 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1C0878 002C0878 00008244 */  mtc1       $2, $f0
    /* 1C087C 002C087C 00000000 */  nop
    /* 1C0880 002C0880 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C0884 002C0884 500C248E */  lw         $4, 0xC50($17)
    /* 1C0888 002C0888 C4004CC6 */  lwc1       $f12, 0xC4($18)
    /* 1C088C 002C088C 2D280000 */  daddu      $5, $0, $0
    /* 1C0890 002C0890 0A000624 */  addiu      $6, $0, 0xA
    /* 1C0894 002C0894 2D380000 */  daddu      $7, $0, $0
    /* 1C0898 002C0898 50820B0C */  jal        func_002e0940
    /* 1C089C 002C089C 00000000 */   nop
    /* 1C08A0 002C08A0 2D200002 */  daddu      $4, $16, $0
    /* 1C08A4 002C08A4 A0B4110C */  jal        func_0046d280
    /* 1C08A8 002C08A8 00000000 */   nop
    /* 1C08AC 002C08AC 3E43023C */  lui        $2, (0x433E0000 >> 16)
    /* 1C08B0 002C08B0 00608244 */  mtc1       $2, $f12
    /* 1C08B4 002C08B4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C08B8 002C08B8 40000524 */  addiu      $5, $0, 0x40
    /* 1C08BC 002C08BC 78820B0C */  jal        func_002e09e0
    /* 1C08C0 002C08C0 00000000 */   nop
    /* 1C08C4 002C08C4 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 1C08C8 002C08C8 00A08244 */  mtc1       $2, $f20
    /* 1C08CC 002C08CC 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C08D0 002C08D0 38810B0C */  jal        func_002e04e0
    /* 1C08D4 002C08D4 00000000 */   nop
    /* 1C08D8 002C08D8 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C08DC 002C08DC 3B43023C */  lui        $2, (0x433B0000 >> 16)
    /* 1C08E0 002C08E0 00A08244 */  mtc1       $2, $f20
    /* 1C08E4 002C08E4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C08E8 002C08E8 38810B0C */  jal        func_002e04e0
    /* 1C08EC 002C08EC 00000000 */   nop
    /* 1C08F0 002C08F0 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C08F4 002C08F4 280F248E */  lw         $4, 0xF28($17)
    /* 1C08F8 002C08F8 06000524 */  addiu      $5, $0, 0x6
    /* 1C08FC 002C08FC 80B4110C */  jal        func_0046d200
    /* 1C0900 002C0900 00000000 */   nop
    /* 1C0904 002C0904 2D804000 */  daddu      $16, $2, $0
    /* 1C0908 002C0908 2D200002 */  daddu      $4, $16, $0
    /* 1C090C 002C090C 98AC110C */  jal        func_0046b260
    /* 1C0910 002C0910 00000000 */   nop
    /* 1C0914 002C0914 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C0918 002C0918 00088244 */  mtc1       $2, $f1
    /* 1C091C 002C091C 00000000 */  nop
    /* 1C0920 002C0920 03000146 */  div.s      $f0, $f0, $f1
    /* 1C0924 002C0924 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0928 002C0928 00000244 */  mfc1       $2, $f0
    /* 1C092C 002C092C 00000000 */  nop
    /* 1C0930 002C0930 3C940200 */  dsll32     $18, $2, 16
    /* 1C0934 002C0934 3F941200 */  dsra32     $18, $18, 16
    /* 1C0938 002C0938 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C093C 002C093C 38810B0C */  jal        func_002e04e0
    /* 1C0940 002C0940 00000000 */   nop
    /* 1C0944 002C0944 000152A4 */  sh         $18, 0x100($2)
    /* 1C0948 002C0948 2D200002 */  daddu      $4, $16, $0
    /* 1C094C 002C094C BCAC110C */  jal        func_0046b2f0
    /* 1C0950 002C0950 00000000 */   nop
    /* 1C0954 002C0954 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C0958 002C0958 00088244 */  mtc1       $2, $f1
    /* 1C095C 002C095C 00000000 */  nop
    /* 1C0960 002C0960 03000146 */  div.s      $f0, $f0, $f1
    /* 1C0964 002C0964 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0968 002C0968 00000244 */  mfc1       $2, $f0
    /* 1C096C 002C096C 00000000 */  nop
    /* 1C0970 002C0970 3C940200 */  dsll32     $18, $2, 16
    /* 1C0974 002C0974 3F941200 */  dsra32     $18, $18, 16
    /* 1C0978 002C0978 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C097C 002C097C 38810B0C */  jal        func_002e04e0
    /* 1C0980 002C0980 00000000 */   nop
    /* 1C0984 002C0984 020152A4 */  sh         $18, 0x102($2)
    /* 1C0988 002C0988 2D200002 */  daddu      $4, $16, $0
    /* 1C098C 002C098C A0B4110C */  jal        func_0046d280
    /* 1C0990 002C0990 00000000 */   nop
    /* 1C0994 002C0994 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C0998 002C0998 38810B0C */  jal        func_002e04e0
    /* 1C099C 002C099C 00000000 */   nop
    /* 1C09A0 002C09A0 2D804000 */  daddu      $16, $2, $0
    /* 1C09A4 002C09A4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C09A8 002C09A8 38810B0C */  jal        func_002e04e0
    /* 1C09AC 002C09AC 00000000 */   nop
    /* 1C09B0 002C09B0 C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C09B4 002C09B4 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1C09B8 002C09B8 00008244 */  mtc1       $2, $f0
    /* 1C09BC 002C09BC 00000000 */  nop
    /* 1C09C0 002C09C0 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C09C4 002C09C4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C09C8 002C09C8 C4000CC6 */  lwc1       $f12, 0xC4($16)
    /* 1C09CC 002C09CC 2D280000 */  daddu      $5, $0, $0
    /* 1C09D0 002C09D0 0A000624 */  addiu      $6, $0, 0xA
    /* 1C09D4 002C09D4 2D380000 */  daddu      $7, $0, $0
    /* 1C09D8 002C09D8 50820B0C */  jal        func_002e0940
    /* 1C09DC 002C09DC 00000000 */   nop
    /* 1C09E0 002C09E0 2D800000 */  daddu      $16, $0, $0
    /* 1C09E4 002C09E4 0E000010 */  b          .L002C0A20
    /* 1C09E8 002C09E8 00000000 */   nop
  .L002C09EC:
    /* 1C09EC 002C09EC 80100300 */  sll        $2, $3, 2
    /* 1C09F0 002C09F0 21102202 */  addu       $2, $17, $2
    /* 1C09F4 002C09F4 380C448C */  lw         $4, 0xC38($2)
    /* 1C09F8 002C09F8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C09FC 002C09FC 2D300000 */  daddu      $6, $0, $0
    /* 1C0A00 002C0A00 2D380000 */  daddu      $7, $0, $0
    /* 1C0A04 002C0A04 0A000824 */  addiu      $8, $0, 0xA
    /* 1C0A08 002C0A08 2D480000 */  daddu      $9, $0, $0
    /* 1C0A0C 002C0A0C 98810B0C */  jal        func_002e0660
    /* 1C0A10 002C0A10 00000000 */   nop
    /* 1C0A14 002C0A14 01000226 */  addiu      $2, $16, 0x1
    /* 1C0A18 002C0A18 3C840200 */  dsll32     $16, $2, 16
    /* 1C0A1C 002C0A1C 3F841000 */  dsra32     $16, $16, 16
  .L002C0A20:
    /* 1C0A20 002C0A20 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C0A24 002C0A24 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C0A28 002C0A28 03006228 */  slti       $2, $3, 0x3
    /* 1C0A2C 002C0A2C EFFF4014 */  bnez       $2, .L002C09EC
    /* 1C0A30 002C0A30 00000000 */   nop
    /* 1C0A34 002C0A34 05000224 */  addiu      $2, $0, 0x5
    /* 1C0A38 002C0A38 070022A2 */  sb         $2, 0x7($17)
    /* 1C0A3C 002C0A3C 13000224 */  addiu      $2, $0, 0x13
    /* 1C0A40 002C0A40 000022A2 */  sb         $2, 0x0($17)
    /* 1C0A44 002C0A44 2D200000 */  daddu      $4, $0, $0
    /* 1C0A48 002C0A48 2D280000 */  daddu      $5, $0, $0
    /* 1C0A4C 002C0A4C 2D300000 */  daddu      $6, $0, $0
    /* 1C0A50 002C0A50 02000724 */  addiu      $7, $0, 0x2
    /* 1C0A54 002C0A54 D86B110C */  jal        func_0045af60
    /* 1C0A58 002C0A58 00000000 */   nop
    /* 1C0A5C 002C0A5C 32270010 */  b          .L002CA728
    /* 1C0A60 002C0A60 00000000 */   nop
    /* 1C0A64 002C0A64 55001024 */  addiu      $16, $0, 0x55
    /* 1C0A68 002C0A68 14000010 */  b          .L002C0ABC
    /* 1C0A6C 002C0A6C 00000000 */   nop
  .L002C0A70:
    /* 1C0A70 002C0A70 80100300 */  sll        $2, $3, 2
    /* 1C0A74 002C0A74 21102202 */  addu       $2, $17, $2
    /* 1C0A78 002C0A78 380C5224 */  addiu      $18, $2, 0xC38
    /* 1C0A7C 002C0A7C 380C448C */  lw         $4, 0xC38($2)
    /* 1C0A80 002C0A80 01000524 */  addiu      $5, $0, 0x1
    /* 1C0A84 002C0A84 5C810B0C */  jal        func_002e0570
    /* 1C0A88 002C0A88 00000000 */   nop
    /* 1C0A8C 002C0A8C 3C160200 */  dsll32     $2, $2, 24
    /* 1C0A90 002C0A90 3F160200 */  dsra32     $2, $2, 24
    /* 1C0A94 002C0A94 06004014 */  bnez       $2, .L002C0AB0
    /* 1C0A98 002C0A98 00000000 */   nop
    /* 1C0A9C 002C0A9C 0000448E */  lw         $4, 0x0($18)
    /* 1C0AA0 002C0AA0 03000524 */  addiu      $5, $0, 0x3
    /* 1C0AA4 002C0AA4 2D300000 */  daddu      $6, $0, $0
    /* 1C0AA8 002C0AA8 3C810B0C */  jal        func_002e04f0
    /* 1C0AAC 002C0AAC 00000000 */   nop
  .L002C0AB0:
    /* 1C0AB0 002C0AB0 01000226 */  addiu      $2, $16, 0x1
    /* 1C0AB4 002C0AB4 3C840200 */  dsll32     $16, $2, 16
    /* 1C0AB8 002C0AB8 3F841000 */  dsra32     $16, $16, 16
  .L002C0ABC:
    /* 1C0ABC 002C0ABC 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C0AC0 002C0AC0 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C0AC4 002C0AC4 58006228 */  slti       $2, $3, 0x58
    /* 1C0AC8 002C0AC8 E9FF4014 */  bnez       $2, .L002C0A70
    /* 1C0ACC 002C0ACC 00000000 */   nop
    /* 1C0AD0 002C0AD0 59001024 */  addiu      $16, $0, 0x59
    /* 1C0AD4 002C0AD4 14000010 */  b          .L002C0B28
    /* 1C0AD8 002C0AD8 00000000 */   nop
  .L002C0ADC:
    /* 1C0ADC 002C0ADC 80100300 */  sll        $2, $3, 2
    /* 1C0AE0 002C0AE0 21102202 */  addu       $2, $17, $2
    /* 1C0AE4 002C0AE4 380C5224 */  addiu      $18, $2, 0xC38
    /* 1C0AE8 002C0AE8 380C448C */  lw         $4, 0xC38($2)
    /* 1C0AEC 002C0AEC 01000524 */  addiu      $5, $0, 0x1
    /* 1C0AF0 002C0AF0 5C810B0C */  jal        func_002e0570
    /* 1C0AF4 002C0AF4 00000000 */   nop
    /* 1C0AF8 002C0AF8 3C160200 */  dsll32     $2, $2, 24
    /* 1C0AFC 002C0AFC 3F160200 */  dsra32     $2, $2, 24
    /* 1C0B00 002C0B00 06004014 */  bnez       $2, .L002C0B1C
    /* 1C0B04 002C0B04 00000000 */   nop
    /* 1C0B08 002C0B08 0000448E */  lw         $4, 0x0($18)
    /* 1C0B0C 002C0B0C 03000524 */  addiu      $5, $0, 0x3
    /* 1C0B10 002C0B10 2D300000 */  daddu      $6, $0, $0
    /* 1C0B14 002C0B14 3C810B0C */  jal        func_002e04f0
    /* 1C0B18 002C0B18 00000000 */   nop
  .L002C0B1C:
    /* 1C0B1C 002C0B1C 01000226 */  addiu      $2, $16, 0x1
    /* 1C0B20 002C0B20 3C840200 */  dsll32     $16, $2, 16
    /* 1C0B24 002C0B24 3F841000 */  dsra32     $16, $16, 16
  .L002C0B28:
    /* 1C0B28 002C0B28 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C0B2C 002C0B2C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C0B30 002C0B30 60006228 */  slti       $2, $3, 0x60
    /* 1C0B34 002C0B34 E9FF4014 */  bnez       $2, .L002C0ADC
    /* 1C0B38 002C0B38 00000000 */   nop
    /* 1C0B3C 002C0B3C 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C0B40 002C0B40 01000524 */  addiu      $5, $0, 0x1
    /* 1C0B44 002C0B44 5C810B0C */  jal        func_002e0570
    /* 1C0B48 002C0B48 00000000 */   nop
    /* 1C0B4C 002C0B4C 3C160200 */  dsll32     $2, $2, 24
    /* 1C0B50 002C0B50 3F160200 */  dsra32     $2, $2, 24
    /* 1C0B54 002C0B54 F4264014 */  bnez       $2, .L002CA728
    /* 1C0B58 002C0B58 00000000 */   nop
    /* 1C0B5C 002C0B5C 900D248E */  lw         $4, 0xD90($17)
    /* 1C0B60 002C0B60 01000524 */  addiu      $5, $0, 0x1
    /* 1C0B64 002C0B64 5C810B0C */  jal        func_002e0570
    /* 1C0B68 002C0B68 00000000 */   nop
    /* 1C0B6C 002C0B6C 3C160200 */  dsll32     $2, $2, 24
    /* 1C0B70 002C0B70 3F160200 */  dsra32     $2, $2, 24
    /* 1C0B74 002C0B74 EC264014 */  bnez       $2, .L002CA728
    /* 1C0B78 002C0B78 00000000 */   nop
    /* 1C0B7C 002C0B7C 940D248E */  lw         $4, 0xD94($17)
    /* 1C0B80 002C0B80 01000524 */  addiu      $5, $0, 0x1
    /* 1C0B84 002C0B84 5C810B0C */  jal        func_002e0570
    /* 1C0B88 002C0B88 00000000 */   nop
    /* 1C0B8C 002C0B8C 3C160200 */  dsll32     $2, $2, 24
    /* 1C0B90 002C0B90 3F160200 */  dsra32     $2, $2, 24
    /* 1C0B94 002C0B94 E4264014 */  bnez       $2, .L002CA728
    /* 1C0B98 002C0B98 00000000 */   nop
    /* 1C0B9C 002C0B9C 10000224 */  addiu      $2, $0, 0x10
    /* 1C0BA0 002C0BA0 000022A2 */  sb         $2, 0x0($17)
    /* 1C0BA4 002C0BA4 E0260010 */  b          .L002CA728
    /* 1C0BA8 002C0BA8 00000000 */   nop
    /* 1C0BAC 002C0BAC 93000010 */  b          .L002C0DFC
    /* 1C0BB0 002C0BB0 00000000 */   nop
  .L002C0BB4:
    /* 1C0BB4 002C0BB4 3C141300 */  dsll32     $2, $19, 16
    /* 1C0BB8 002C0BB8 3F140200 */  dsra32     $2, $2, 16
    /* 1C0BBC 002C0BBC 80100200 */  sll        $2, $2, 2
    /* 1C0BC0 002C0BC0 21902202 */  addu       $18, $17, $2
    /* 1C0BC4 002C0BC4 440C448E */  lw         $4, 0xC44($18)
    /* 1C0BC8 002C0BC8 38810B0C */  jal        func_002e04e0
    /* 1C0BCC 002C0BCC 00000000 */   nop
    /* 1C0BD0 002C0BD0 2D804000 */  daddu      $16, $2, $0
    /* 1C0BD4 002C0BD4 3E0F4292 */  lbu        $2, 0xF3E($18)
    /* 1C0BD8 002C0BD8 06004004 */  bltz       $2, .L002C0BF4
    /* 1C0BDC 002C0BDC 00000000 */   nop
    /* 1C0BE0 002C0BE0 00008244 */  mtc1       $2, $f0
    /* 1C0BE4 002C0BE4 00000000 */  nop
    /* 1C0BE8 002C0BE8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C0BEC 002C0BEC 08000010 */  b          .L002C0C10
    /* 1C0BF0 002C0BF0 00000000 */   nop
  .L002C0BF4:
    /* 1C0BF4 002C0BF4 42180200 */  srl        $3, $2, 1
    /* 1C0BF8 002C0BF8 01004230 */  andi       $2, $2, 0x1
    /* 1C0BFC 002C0BFC 25186200 */  or         $3, $3, $2
    /* 1C0C00 002C0C00 00008344 */  mtc1       $3, $f0
    /* 1C0C04 002C0C04 00000000 */  nop
    /* 1C0C08 002C0C08 20038046 */  cvt.s.w    $f12, $f0
    /* 1C0C0C 002C0C0C 00630C46 */  add.s      $f12, $f12, $f12
  .L002C0C10:
    /* 1C0C10 002C0C10 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C0C14 002C0C14 00008244 */  mtc1       $2, $f0
    /* 1C0C18 002C0C18 00000000 */  nop
    /* 1C0C1C 002C0C1C A0038046 */  cvt.s.w    $f14, $f0
    /* 1C0C20 002C0C20 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C0C24 002C0C24 00688244 */  mtc1       $2, $f13
    /* 1C0C28 002C0C28 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C0C2C 002C0C2C 00788244 */  mtc1       $2, $f15
    /* 1C0C30 002C0C30 01000424 */  addiu      $4, $0, 0x1
    /* 1C0C34 002C0C34 A8CA0A0C */  jal        func_002b2aa0
    /* 1C0C38 002C0C38 00000000 */   nop
    /* 1C0C3C 002C0C3C 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C0C40 002C0C40 00088244 */  mtc1       $2, $f1
    /* 1C0C44 002C0C44 00000000 */  nop
    /* 1C0C48 002C0C48 36080046 */  c.le.s     $f1, $f0
    /* 1C0C4C 002C0C4C 07000145 */  bc1t       .L002C0C6C
    /* 1C0C50 002C0C50 00000000 */   nop
    /* 1C0C54 002C0C54 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0C58 002C0C58 00000344 */  mfc1       $3, $f0
    /* 1C0C5C 002C0C5C 00000000 */  nop
    /* 1C0C60 002C0C60 FF006330 */  andi       $3, $3, 0xFF
    /* 1C0C64 002C0C64 07000010 */  b          .L002C0C84
    /* 1C0C68 002C0C68 00000000 */   nop
  .L002C0C6C:
    /* 1C0C6C 002C0C6C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C0C70 002C0C70 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0C74 002C0C74 00000344 */  mfc1       $3, $f0
    /* 1C0C78 002C0C78 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C0C7C 002C0C7C 25186200 */  or         $3, $3, $2
    /* 1C0C80 002C0C80 FF006330 */  andi       $3, $3, 0xFF
  .L002C0C84:
    /* 1C0C84 002C0C84 790003A2 */  sb         $3, 0x79($16)
    /* 1C0C88 002C0C88 3F0F4292 */  lbu        $2, 0xF3F($18)
    /* 1C0C8C 002C0C8C 06004004 */  bltz       $2, .L002C0CA8
    /* 1C0C90 002C0C90 00000000 */   nop
    /* 1C0C94 002C0C94 00008244 */  mtc1       $2, $f0
    /* 1C0C98 002C0C98 00000000 */  nop
    /* 1C0C9C 002C0C9C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C0CA0 002C0CA0 08000010 */  b          .L002C0CC4
    /* 1C0CA4 002C0CA4 00000000 */   nop
  .L002C0CA8:
    /* 1C0CA8 002C0CA8 42180200 */  srl        $3, $2, 1
    /* 1C0CAC 002C0CAC 01004230 */  andi       $2, $2, 0x1
    /* 1C0CB0 002C0CB0 25186200 */  or         $3, $3, $2
    /* 1C0CB4 002C0CB4 00008344 */  mtc1       $3, $f0
    /* 1C0CB8 002C0CB8 00000000 */  nop
    /* 1C0CBC 002C0CBC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C0CC0 002C0CC0 00630C46 */  add.s      $f12, $f12, $f12
  .L002C0CC4:
    /* 1C0CC4 002C0CC4 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C0CC8 002C0CC8 00008244 */  mtc1       $2, $f0
    /* 1C0CCC 002C0CCC 00000000 */  nop
    /* 1C0CD0 002C0CD0 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C0CD4 002C0CD4 6243023C */  lui        $2, (0x43620000 >> 16)
    /* 1C0CD8 002C0CD8 00688244 */  mtc1       $2, $f13
    /* 1C0CDC 002C0CDC 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C0CE0 002C0CE0 00788244 */  mtc1       $2, $f15
    /* 1C0CE4 002C0CE4 01000424 */  addiu      $4, $0, 0x1
    /* 1C0CE8 002C0CE8 A8CA0A0C */  jal        func_002b2aa0
    /* 1C0CEC 002C0CEC 00000000 */   nop
    /* 1C0CF0 002C0CF0 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C0CF4 002C0CF4 00088244 */  mtc1       $2, $f1
    /* 1C0CF8 002C0CF8 00000000 */  nop
    /* 1C0CFC 002C0CFC 36080046 */  c.le.s     $f1, $f0
    /* 1C0D00 002C0D00 07000145 */  bc1t       .L002C0D20
    /* 1C0D04 002C0D04 00000000 */   nop
    /* 1C0D08 002C0D08 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0D0C 002C0D0C 00000344 */  mfc1       $3, $f0
    /* 1C0D10 002C0D10 00000000 */  nop
    /* 1C0D14 002C0D14 FF006330 */  andi       $3, $3, 0xFF
    /* 1C0D18 002C0D18 07000010 */  b          .L002C0D38
    /* 1C0D1C 002C0D1C 00000000 */   nop
  .L002C0D20:
    /* 1C0D20 002C0D20 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C0D24 002C0D24 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0D28 002C0D28 00000344 */  mfc1       $3, $f0
    /* 1C0D2C 002C0D2C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C0D30 002C0D30 25186200 */  or         $3, $3, $2
    /* 1C0D34 002C0D34 FF006330 */  andi       $3, $3, 0xFF
  .L002C0D38:
    /* 1C0D38 002C0D38 7A0003A2 */  sb         $3, 0x7A($16)
    /* 1C0D3C 002C0D3C 400F4292 */  lbu        $2, 0xF40($18)
    /* 1C0D40 002C0D40 06004004 */  bltz       $2, .L002C0D5C
    /* 1C0D44 002C0D44 00000000 */   nop
    /* 1C0D48 002C0D48 00008244 */  mtc1       $2, $f0
    /* 1C0D4C 002C0D4C 00000000 */  nop
    /* 1C0D50 002C0D50 20038046 */  cvt.s.w    $f12, $f0
    /* 1C0D54 002C0D54 08000010 */  b          .L002C0D78
    /* 1C0D58 002C0D58 00000000 */   nop
  .L002C0D5C:
    /* 1C0D5C 002C0D5C 42180200 */  srl        $3, $2, 1
    /* 1C0D60 002C0D60 01004230 */  andi       $2, $2, 0x1
    /* 1C0D64 002C0D64 25186200 */  or         $3, $3, $2
    /* 1C0D68 002C0D68 00008344 */  mtc1       $3, $f0
    /* 1C0D6C 002C0D6C 00000000 */  nop
    /* 1C0D70 002C0D70 20038046 */  cvt.s.w    $f12, $f0
    /* 1C0D74 002C0D74 00630C46 */  add.s      $f12, $f12, $f12
  .L002C0D78:
    /* 1C0D78 002C0D78 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C0D7C 002C0D7C 00008244 */  mtc1       $2, $f0
    /* 1C0D80 002C0D80 00000000 */  nop
    /* 1C0D84 002C0D84 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C0D88 002C0D88 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1C0D8C 002C0D8C 00688244 */  mtc1       $2, $f13
    /* 1C0D90 002C0D90 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C0D94 002C0D94 00788244 */  mtc1       $2, $f15
    /* 1C0D98 002C0D98 01000424 */  addiu      $4, $0, 0x1
    /* 1C0D9C 002C0D9C A8CA0A0C */  jal        func_002b2aa0
    /* 1C0DA0 002C0DA0 00000000 */   nop
    /* 1C0DA4 002C0DA4 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C0DA8 002C0DA8 00088244 */  mtc1       $2, $f1
    /* 1C0DAC 002C0DAC 00000000 */  nop
    /* 1C0DB0 002C0DB0 36080046 */  c.le.s     $f1, $f0
    /* 1C0DB4 002C0DB4 07000145 */  bc1t       .L002C0DD4
    /* 1C0DB8 002C0DB8 00000000 */   nop
    /* 1C0DBC 002C0DBC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0DC0 002C0DC0 00000344 */  mfc1       $3, $f0
    /* 1C0DC4 002C0DC4 00000000 */  nop
    /* 1C0DC8 002C0DC8 FF006330 */  andi       $3, $3, 0xFF
    /* 1C0DCC 002C0DCC 07000010 */  b          .L002C0DEC
    /* 1C0DD0 002C0DD0 00000000 */   nop
  .L002C0DD4:
    /* 1C0DD4 002C0DD4 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C0DD8 002C0DD8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0DDC 002C0DDC 00000344 */  mfc1       $3, $f0
    /* 1C0DE0 002C0DE0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C0DE4 002C0DE4 25186200 */  or         $3, $3, $2
    /* 1C0DE8 002C0DE8 FF006330 */  andi       $3, $3, 0xFF
  .L002C0DEC:
    /* 1C0DEC 002C0DEC 7B0003A2 */  sb         $3, 0x7B($16)
    /* 1C0DF0 002C0DF0 01006226 */  addiu      $2, $19, 0x1
    /* 1C0DF4 002C0DF4 3C9C0200 */  dsll32     $19, $2, 16
    /* 1C0DF8 002C0DF8 3F9C1300 */  dsra32     $19, $19, 16
  .L002C0DFC:
    /* 1C0DFC 002C0DFC 3C141300 */  dsll32     $2, $19, 16
    /* 1C0E00 002C0E00 3F140200 */  dsra32     $2, $2, 16
    /* 1C0E04 002C0E04 02004228 */  slti       $2, $2, 0x2
    /* 1C0E08 002C0E08 6AFF4014 */  bnez       $2, .L002C0BB4
    /* 1C0E0C 002C0E0C 00000000 */   nop
    /* 1C0E10 002C0E10 3C0F2486 */  lh         $4, 0xF3C($17)
    /* 1C0E14 002C0E14 06008128 */  slti       $1, $4, 0x6
    /* 1C0E18 002C0E18 0A002010 */  beqz       $1, .L002C0E44
    /* 1C0E1C 002C0E1C 00000000 */   nop
    /* 1C0E20 002C0E20 01000524 */  addiu      $5, $0, 0x1
    /* 1C0E24 002C0E24 06000624 */  addiu      $6, $0, 0x6
    /* 1C0E28 002C0E28 2D380000 */  daddu      $7, $0, $0
    /* 1C0E2C 002C0E2C 2D40A000 */  daddu      $8, $5, $0
    /* 1C0E30 002C0E30 2CCB0A0C */  jal        func_002b2cb0
    /* 1C0E34 002C0E34 00000000 */   nop
    /* 1C0E38 002C0E38 3C0F22A6 */  sh         $2, 0xF3C($17)
    /* 1C0E3C 002C0E3C 3A260010 */  b          .L002CA728
    /* 1C0E40 002C0E40 00000000 */   nop
  .L002C0E44:
    /* 1C0E44 002C0E44 2D800000 */  daddu      $16, $0, $0
    /* 1C0E48 002C0E48 13000010 */  b          .L002C0E98
    /* 1C0E4C 002C0E4C 00000000 */   nop
  .L002C0E50:
    /* 1C0E50 002C0E50 3C141000 */  dsll32     $2, $16, 16
    /* 1C0E54 002C0E54 3F140200 */  dsra32     $2, $2, 16
    /* 1C0E58 002C0E58 80100200 */  sll        $2, $2, 2
    /* 1C0E5C 002C0E5C 21902202 */  addu       $18, $17, $2
    /* 1C0E60 002C0E60 440C448E */  lw         $4, 0xC44($18)
    /* 1C0E64 002C0E64 38810B0C */  jal        func_002e04e0
    /* 1C0E68 002C0E68 00000000 */   nop
    /* 1C0E6C 002C0E6C 3E0F4692 */  lbu        $6, 0xF3E($18)
    /* 1C0E70 002C0E70 3F0F4592 */  lbu        $5, 0xF3F($18)
    /* 1C0E74 002C0E74 400F4492 */  lbu        $4, 0xF40($18)
    /* 1C0E78 002C0E78 410F4392 */  lbu        $3, 0xF41($18)
    /* 1C0E7C 002C0E7C 790046A0 */  sb         $6, 0x79($2)
    /* 1C0E80 002C0E80 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C0E84 002C0E84 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C0E88 002C0E88 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C0E8C 002C0E8C 01000226 */  addiu      $2, $16, 0x1
    /* 1C0E90 002C0E90 3C840200 */  dsll32     $16, $2, 16
    /* 1C0E94 002C0E94 3F841000 */  dsra32     $16, $16, 16
  .L002C0E98:
    /* 1C0E98 002C0E98 3C141000 */  dsll32     $2, $16, 16
    /* 1C0E9C 002C0E9C 3F140200 */  dsra32     $2, $2, 16
    /* 1C0EA0 002C0EA0 02004228 */  slti       $2, $2, 0x2
    /* 1C0EA4 002C0EA4 EAFF4014 */  bnez       $2, .L002C0E50
    /* 1C0EA8 002C0EA8 00000000 */   nop
    /* 1C0EAC 002C0EAC 2D800000 */  daddu      $16, $0, $0
    /* 1C0EB0 002C0EB0 12000010 */  b          .L002C0EFC
    /* 1C0EB4 002C0EB4 00000000 */   nop
  .L002C0EB8:
    /* 1C0EB8 002C0EB8 3C241000 */  dsll32     $4, $16, 16
    /* 1C0EBC 002C0EBC 3F240400 */  dsra32     $4, $4, 16
    /* 1C0EC0 002C0EC0 80100400 */  sll        $2, $4, 2
    /* 1C0EC4 002C0EC4 21182202 */  addu       $3, $17, $2
    /* 1C0EC8 002C0EC8 40100400 */  sll        $2, $4, 1
    /* 1C0ECC 002C0ECC 3C4C0200 */  dsll32     $9, $2, 16
    /* 1C0ED0 002C0ED0 3F4C0900 */  dsra32     $9, $9, 16
    /* 1C0ED4 002C0ED4 200D648C */  lw         $4, 0xD20($3)
    /* 1C0ED8 002C0ED8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C0EDC 002C0EDC 2D300000 */  daddu      $6, $0, $0
    /* 1C0EE0 002C0EE0 2D380000 */  daddu      $7, $0, $0
    /* 1C0EE4 002C0EE4 05000824 */  addiu      $8, $0, 0x5
    /* 1C0EE8 002C0EE8 98810B0C */  jal        func_002e0660
    /* 1C0EEC 002C0EEC 00000000 */   nop
    /* 1C0EF0 002C0EF0 01000226 */  addiu      $2, $16, 0x1
    /* 1C0EF4 002C0EF4 3C840200 */  dsll32     $16, $2, 16
    /* 1C0EF8 002C0EF8 3F841000 */  dsra32     $16, $16, 16
  .L002C0EFC:
    /* 1C0EFC 002C0EFC 3C141000 */  dsll32     $2, $16, 16
    /* 1C0F00 002C0F00 3F140200 */  dsra32     $2, $2, 16
    /* 1C0F04 002C0F04 07004228 */  slti       $2, $2, 0x7
    /* 1C0F08 002C0F08 EBFF4014 */  bnez       $2, .L002C0EB8
    /* 1C0F0C 002C0F0C 00000000 */   nop
    /* 1C0F10 002C0F10 07002282 */  lb         $2, 0x7($17)
    /* 1C0F14 002C0F14 40100200 */  sll        $2, $2, 1
    /* 1C0F18 002C0F18 02004224 */  addiu      $2, $2, 0x2
    /* 1C0F1C 002C0F1C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1C0F20 002C0F20 3F4C0900 */  dsra32     $9, $9, 16
    /* 1C0F24 002C0F24 440C248E */  lw         $4, 0xC44($17)
    /* 1C0F28 002C0F28 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C0F2C 002C0F2C 2D300000 */  daddu      $6, $0, $0
    /* 1C0F30 002C0F30 2D380000 */  daddu      $7, $0, $0
    /* 1C0F34 002C0F34 2D400000 */  daddu      $8, $0, $0
    /* 1C0F38 002C0F38 98810B0C */  jal        func_002e0660
    /* 1C0F3C 002C0F3C 00000000 */   nop
    /* 1C0F40 002C0F40 07002282 */  lb         $2, 0x7($17)
    /* 1C0F44 002C0F44 40100200 */  sll        $2, $2, 1
    /* 1C0F48 002C0F48 02004224 */  addiu      $2, $2, 0x2
    /* 1C0F4C 002C0F4C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1C0F50 002C0F50 3F4C0900 */  dsra32     $9, $9, 16
    /* 1C0F54 002C0F54 480C248E */  lw         $4, 0xC48($17)
    /* 1C0F58 002C0F58 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C0F5C 002C0F5C 2D300000 */  daddu      $6, $0, $0
    /* 1C0F60 002C0F60 2D380000 */  daddu      $7, $0, $0
    /* 1C0F64 002C0F64 2D400000 */  daddu      $8, $0, $0
    /* 1C0F68 002C0F68 98810B0C */  jal        func_002e0660
    /* 1C0F6C 002C0F6C 00000000 */   nop
    /* 1C0F70 002C0F70 3F43023C */  lui        $2, (0x433F0000 >> 16)
    /* 1C0F74 002C0F74 00608244 */  mtc1       $2, $f12
    /* 1C0F78 002C0F78 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C0F7C 002C0F7C 40000524 */  addiu      $5, $0, 0x40
    /* 1C0F80 002C0F80 78820B0C */  jal        func_002e09e0
    /* 1C0F84 002C0F84 00000000 */   nop
    /* 1C0F88 002C0F88 280F248E */  lw         $4, 0xF28($17)
    /* 1C0F8C 002C0F8C 05000524 */  addiu      $5, $0, 0x5
    /* 1C0F90 002C0F90 80B4110C */  jal        func_0046d200
    /* 1C0F94 002C0F94 00000000 */   nop
    /* 1C0F98 002C0F98 2D804000 */  daddu      $16, $2, $0
    /* 1C0F9C 002C0F9C 2D200002 */  daddu      $4, $16, $0
    /* 1C0FA0 002C0FA0 98AC110C */  jal        func_0046b260
    /* 1C0FA4 002C0FA4 00000000 */   nop
    /* 1C0FA8 002C0FA8 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C0FAC 002C0FAC 00088244 */  mtc1       $2, $f1
    /* 1C0FB0 002C0FB0 00000000 */  nop
    /* 1C0FB4 002C0FB4 03000146 */  div.s      $f0, $f0, $f1
    /* 1C0FB8 002C0FB8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0FBC 002C0FBC 00000244 */  mfc1       $2, $f0
    /* 1C0FC0 002C0FC0 00000000 */  nop
    /* 1C0FC4 002C0FC4 3C940200 */  dsll32     $18, $2, 16
    /* 1C0FC8 002C0FC8 3F941200 */  dsra32     $18, $18, 16
    /* 1C0FCC 002C0FCC 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C0FD0 002C0FD0 38810B0C */  jal        func_002e04e0
    /* 1C0FD4 002C0FD4 00000000 */   nop
    /* 1C0FD8 002C0FD8 000152A4 */  sh         $18, 0x100($2)
    /* 1C0FDC 002C0FDC 2D200002 */  daddu      $4, $16, $0
    /* 1C0FE0 002C0FE0 BCAC110C */  jal        func_0046b2f0
    /* 1C0FE4 002C0FE4 00000000 */   nop
    /* 1C0FE8 002C0FE8 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C0FEC 002C0FEC 00088244 */  mtc1       $2, $f1
    /* 1C0FF0 002C0FF0 00000000 */  nop
    /* 1C0FF4 002C0FF4 03000146 */  div.s      $f0, $f0, $f1
    /* 1C0FF8 002C0FF8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C0FFC 002C0FFC 00000244 */  mfc1       $2, $f0
    /* 1C1000 002C1000 00000000 */  nop
    /* 1C1004 002C1004 3C940200 */  dsll32     $18, $2, 16
    /* 1C1008 002C1008 3F941200 */  dsra32     $18, $18, 16
    /* 1C100C 002C100C 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1010 002C1010 38810B0C */  jal        func_002e04e0
    /* 1C1014 002C1014 00000000 */   nop
    /* 1C1018 002C1018 020152A4 */  sh         $18, 0x102($2)
    /* 1C101C 002C101C 2D200002 */  daddu      $4, $16, $0
    /* 1C1020 002C1020 A0B4110C */  jal        func_0046d280
    /* 1C1024 002C1024 00000000 */   nop
    /* 1C1028 002C1028 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C102C 002C102C 38810B0C */  jal        func_002e04e0
    /* 1C1030 002C1030 00000000 */   nop
    /* 1C1034 002C1034 2D804000 */  daddu      $16, $2, $0
    /* 1C1038 002C1038 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C103C 002C103C 38810B0C */  jal        func_002e04e0
    /* 1C1040 002C1040 00000000 */   nop
    /* 1C1044 002C1044 C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C1048 002C1048 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1C104C 002C104C 00008244 */  mtc1       $2, $f0
    /* 1C1050 002C1050 00000000 */  nop
    /* 1C1054 002C1054 40030146 */  add.s      $f13, $f0, $f1
    /* 1C1058 002C1058 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C105C 002C105C C4000CC6 */  lwc1       $f12, 0xC4($16)
    /* 1C1060 002C1060 2D280000 */  daddu      $5, $0, $0
    /* 1C1064 002C1064 0A000624 */  addiu      $6, $0, 0xA
    /* 1C1068 002C1068 2D380000 */  daddu      $7, $0, $0
    /* 1C106C 002C106C 50820B0C */  jal        func_002e0940
    /* 1C1070 002C1070 00000000 */   nop
    /* 1C1074 002C1074 6041023C */  lui        $2, (0x41600000 >> 16)
    /* 1C1078 002C1078 00A08244 */  mtc1       $2, $f20
    /* 1C107C 002C107C 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1080 002C1080 38810B0C */  jal        func_002e04e0
    /* 1C1084 002C1084 00000000 */   nop
    /* 1C1088 002C1088 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C108C 002C108C 2443023C */  lui        $2, (0x43240000 >> 16)
    /* 1C1090 002C1090 00A08244 */  mtc1       $2, $f20
    /* 1C1094 002C1094 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1098 002C1098 38810B0C */  jal        func_002e04e0
    /* 1C109C 002C109C 00000000 */   nop
    /* 1C10A0 002C10A0 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C10A4 002C10A4 4043023C */  lui        $2, (0x43400000 >> 16)
    /* 1C10A8 002C10A8 00608244 */  mtc1       $2, $f12
    /* 1C10AC 002C10AC 500C248E */  lw         $4, 0xC50($17)
    /* 1C10B0 002C10B0 40000524 */  addiu      $5, $0, 0x40
    /* 1C10B4 002C10B4 78820B0C */  jal        func_002e09e0
    /* 1C10B8 002C10B8 00000000 */   nop
    /* 1C10BC 002C10BC A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 1C10C0 002C10C0 00A08244 */  mtc1       $2, $f20
    /* 1C10C4 002C10C4 500C248E */  lw         $4, 0xC50($17)
    /* 1C10C8 002C10C8 38810B0C */  jal        func_002e04e0
    /* 1C10CC 002C10CC 00000000 */   nop
    /* 1C10D0 002C10D0 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C10D4 002C10D4 0243023C */  lui        $2, (0x43020000 >> 16)
    /* 1C10D8 002C10D8 00A08244 */  mtc1       $2, $f20
    /* 1C10DC 002C10DC 500C248E */  lw         $4, 0xC50($17)
    /* 1C10E0 002C10E0 38810B0C */  jal        func_002e04e0
    /* 1C10E4 002C10E4 00000000 */   nop
    /* 1C10E8 002C10E8 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C10EC 002C10EC 280F248E */  lw         $4, 0xF28($17)
    /* 1C10F0 002C10F0 06000524 */  addiu      $5, $0, 0x6
    /* 1C10F4 002C10F4 80B4110C */  jal        func_0046d200
    /* 1C10F8 002C10F8 00000000 */   nop
    /* 1C10FC 002C10FC 2D804000 */  daddu      $16, $2, $0
    /* 1C1100 002C1100 2D200002 */  daddu      $4, $16, $0
    /* 1C1104 002C1104 98AC110C */  jal        func_0046b260
    /* 1C1108 002C1108 00000000 */   nop
    /* 1C110C 002C110C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C1110 002C1110 00088244 */  mtc1       $2, $f1
    /* 1C1114 002C1114 00000000 */  nop
    /* 1C1118 002C1118 03000146 */  div.s      $f0, $f0, $f1
    /* 1C111C 002C111C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C1120 002C1120 00000244 */  mfc1       $2, $f0
    /* 1C1124 002C1124 00000000 */  nop
    /* 1C1128 002C1128 3C940200 */  dsll32     $18, $2, 16
    /* 1C112C 002C112C 3F941200 */  dsra32     $18, $18, 16
    /* 1C1130 002C1130 500C248E */  lw         $4, 0xC50($17)
    /* 1C1134 002C1134 38810B0C */  jal        func_002e04e0
    /* 1C1138 002C1138 00000000 */   nop
    /* 1C113C 002C113C 000152A4 */  sh         $18, 0x100($2)
    /* 1C1140 002C1140 2D200002 */  daddu      $4, $16, $0
    /* 1C1144 002C1144 BCAC110C */  jal        func_0046b2f0
    /* 1C1148 002C1148 00000000 */   nop
    /* 1C114C 002C114C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C1150 002C1150 00088244 */  mtc1       $2, $f1
    /* 1C1154 002C1154 00000000 */  nop
    /* 1C1158 002C1158 03000146 */  div.s      $f0, $f0, $f1
    /* 1C115C 002C115C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C1160 002C1160 00000244 */  mfc1       $2, $f0
    /* 1C1164 002C1164 00000000 */  nop
    /* 1C1168 002C1168 3C940200 */  dsll32     $18, $2, 16
    /* 1C116C 002C116C 3F941200 */  dsra32     $18, $18, 16
    /* 1C1170 002C1170 500C248E */  lw         $4, 0xC50($17)
    /* 1C1174 002C1174 38810B0C */  jal        func_002e04e0
    /* 1C1178 002C1178 00000000 */   nop
    /* 1C117C 002C117C 020152A4 */  sh         $18, 0x102($2)
    /* 1C1180 002C1180 500C248E */  lw         $4, 0xC50($17)
    /* 1C1184 002C1184 38810B0C */  jal        func_002e04e0
    /* 1C1188 002C1188 00000000 */   nop
    /* 1C118C 002C118C 2D904000 */  daddu      $18, $2, $0
    /* 1C1190 002C1190 500C248E */  lw         $4, 0xC50($17)
    /* 1C1194 002C1194 38810B0C */  jal        func_002e04e0
    /* 1C1198 002C1198 00000000 */   nop
    /* 1C119C 002C119C C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C11A0 002C11A0 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1C11A4 002C11A4 00008244 */  mtc1       $2, $f0
    /* 1C11A8 002C11A8 00000000 */  nop
    /* 1C11AC 002C11AC 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C11B0 002C11B0 500C248E */  lw         $4, 0xC50($17)
    /* 1C11B4 002C11B4 C4004CC6 */  lwc1       $f12, 0xC4($18)
    /* 1C11B8 002C11B8 2D280000 */  daddu      $5, $0, $0
    /* 1C11BC 002C11BC 0A000624 */  addiu      $6, $0, 0xA
    /* 1C11C0 002C11C0 2D380000 */  daddu      $7, $0, $0
    /* 1C11C4 002C11C4 50820B0C */  jal        func_002e0940
    /* 1C11C8 002C11C8 00000000 */   nop
    /* 1C11CC 002C11CC 2D200002 */  daddu      $4, $16, $0
    /* 1C11D0 002C11D0 A0B4110C */  jal        func_0046d280
    /* 1C11D4 002C11D4 00000000 */   nop
    /* 1C11D8 002C11D8 3E43023C */  lui        $2, (0x433E0000 >> 16)
    /* 1C11DC 002C11DC 00608244 */  mtc1       $2, $f12
    /* 1C11E0 002C11E0 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C11E4 002C11E4 40000524 */  addiu      $5, $0, 0x40
    /* 1C11E8 002C11E8 78820B0C */  jal        func_002e09e0
    /* 1C11EC 002C11EC 00000000 */   nop
    /* 1C11F0 002C11F0 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 1C11F4 002C11F4 00A08244 */  mtc1       $2, $f20
    /* 1C11F8 002C11F8 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C11FC 002C11FC 38810B0C */  jal        func_002e04e0
    /* 1C1200 002C1200 00000000 */   nop
    /* 1C1204 002C1204 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C1208 002C1208 3B43023C */  lui        $2, (0x433B0000 >> 16)
    /* 1C120C 002C120C 00A08244 */  mtc1       $2, $f20
    /* 1C1210 002C1210 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C1214 002C1214 38810B0C */  jal        func_002e04e0
    /* 1C1218 002C1218 00000000 */   nop
    /* 1C121C 002C121C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C1220 002C1220 280F248E */  lw         $4, 0xF28($17)
    /* 1C1224 002C1224 06000524 */  addiu      $5, $0, 0x6
    /* 1C1228 002C1228 80B4110C */  jal        func_0046d200
    /* 1C122C 002C122C 00000000 */   nop
    /* 1C1230 002C1230 2D804000 */  daddu      $16, $2, $0
    /* 1C1234 002C1234 2D200002 */  daddu      $4, $16, $0
    /* 1C1238 002C1238 98AC110C */  jal        func_0046b260
    /* 1C123C 002C123C 00000000 */   nop
    /* 1C1240 002C1240 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C1244 002C1244 00088244 */  mtc1       $2, $f1
    /* 1C1248 002C1248 00000000 */  nop
    /* 1C124C 002C124C 03000146 */  div.s      $f0, $f0, $f1
    /* 1C1250 002C1250 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C1254 002C1254 00000244 */  mfc1       $2, $f0
    /* 1C1258 002C1258 00000000 */  nop
    /* 1C125C 002C125C 3C940200 */  dsll32     $18, $2, 16
    /* 1C1260 002C1260 3F941200 */  dsra32     $18, $18, 16
    /* 1C1264 002C1264 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C1268 002C1268 38810B0C */  jal        func_002e04e0
    /* 1C126C 002C126C 00000000 */   nop
    /* 1C1270 002C1270 000152A4 */  sh         $18, 0x100($2)
    /* 1C1274 002C1274 2D200002 */  daddu      $4, $16, $0
    /* 1C1278 002C1278 BCAC110C */  jal        func_0046b2f0
    /* 1C127C 002C127C 00000000 */   nop
    /* 1C1280 002C1280 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C1284 002C1284 00088244 */  mtc1       $2, $f1
    /* 1C1288 002C1288 00000000 */  nop
    /* 1C128C 002C128C 03000146 */  div.s      $f0, $f0, $f1
    /* 1C1290 002C1290 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C1294 002C1294 00000244 */  mfc1       $2, $f0
    /* 1C1298 002C1298 00000000 */  nop
    /* 1C129C 002C129C 3C940200 */  dsll32     $18, $2, 16
    /* 1C12A0 002C12A0 3F941200 */  dsra32     $18, $18, 16
    /* 1C12A4 002C12A4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C12A8 002C12A8 38810B0C */  jal        func_002e04e0
    /* 1C12AC 002C12AC 00000000 */   nop
    /* 1C12B0 002C12B0 020152A4 */  sh         $18, 0x102($2)
    /* 1C12B4 002C12B4 2D200002 */  daddu      $4, $16, $0
    /* 1C12B8 002C12B8 A0B4110C */  jal        func_0046d280
    /* 1C12BC 002C12BC 00000000 */   nop
    /* 1C12C0 002C12C0 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C12C4 002C12C4 38810B0C */  jal        func_002e04e0
    /* 1C12C8 002C12C8 00000000 */   nop
    /* 1C12CC 002C12CC 2D804000 */  daddu      $16, $2, $0
    /* 1C12D0 002C12D0 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C12D4 002C12D4 38810B0C */  jal        func_002e04e0
    /* 1C12D8 002C12D8 00000000 */   nop
    /* 1C12DC 002C12DC C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C12E0 002C12E0 A040023C */  lui        $2, (0x40A00000 >> 16)
    /* 1C12E4 002C12E4 00008244 */  mtc1       $2, $f0
    /* 1C12E8 002C12E8 00000000 */  nop
    /* 1C12EC 002C12EC 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C12F0 002C12F0 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C12F4 002C12F4 C4000CC6 */  lwc1       $f12, 0xC4($16)
    /* 1C12F8 002C12F8 2D280000 */  daddu      $5, $0, $0
    /* 1C12FC 002C12FC 0A000624 */  addiu      $6, $0, 0xA
    /* 1C1300 002C1300 2D380000 */  daddu      $7, $0, $0
    /* 1C1304 002C1304 50820B0C */  jal        func_002e0940
    /* 1C1308 002C1308 00000000 */   nop
    /* 1C130C 002C130C 07002382 */  lb         $3, 0x7($17)
    /* 1C1310 002C1310 05000224 */  addiu      $2, $0, 0x5
    /* 1C1314 002C1314 4B006210 */  beq        $3, $2, .L002C1444
    /* 1C1318 002C1318 00000000 */   nop
    /* 1C131C 002C131C 900D248E */  lw         $4, 0xD90($17)
    /* 1C1320 002C1320 38810B0C */  jal        func_002e04e0
    /* 1C1324 002C1324 00000000 */   nop
    /* 1C1328 002C1328 2D804000 */  daddu      $16, $2, $0
    /* 1C132C 002C132C 83C3023C */  lui        $2, (0xC3830000 >> 16)
    /* 1C1330 002C1330 00608244 */  mtc1       $2, $f12
    /* 1C1334 002C1334 60C2023C */  lui        $2, (0xC2600000 >> 16)
    /* 1C1338 002C1338 00688244 */  mtc1       $2, $f13
    /* 1C133C 002C133C C805A427 */  addiu      $4, $29, 0x5C8
    /* 1C1340 002C1340 5CCA0A0C */  jal        func_002b2970
    /* 1C1344 002C1344 00000000 */   nop
    /* 1C1348 002C1348 900D248E */  lw         $4, 0xD90($17)
    /* 1C134C 002C134C 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C1350 002C1350 3300056A */  ldl        $5, 0x33($16)
    /* 1C1354 002C1354 C805A6DF */  ld         $6, 0x5C8($29)
    /* 1C1358 002C1358 2D380000 */  daddu      $7, $0, $0
    /* 1C135C 002C135C 0A000824 */  addiu      $8, $0, 0xA
    /* 1C1360 002C1360 2D480000 */  daddu      $9, $0, $0
    /* 1C1364 002C1364 88810B0C */  jal        func_002e0620
    /* 1C1368 002C1368 00000000 */   nop
    /* 1C136C 002C136C 940D248E */  lw         $4, 0xD94($17)
    /* 1C1370 002C1370 38810B0C */  jal        func_002e04e0
    /* 1C1374 002C1374 00000000 */   nop
    /* 1C1378 002C1378 2D804000 */  daddu      $16, $2, $0
    /* 1C137C 002C137C 10C1023C */  lui        $2, (0xC1100000 >> 16)
    /* 1C1380 002C1380 00608244 */  mtc1       $2, $f12
    /* 1C1384 002C1384 60C2023C */  lui        $2, (0xC2600000 >> 16)
    /* 1C1388 002C1388 00688244 */  mtc1       $2, $f13
    /* 1C138C 002C138C C005A427 */  addiu      $4, $29, 0x5C0
    /* 1C1390 002C1390 5CCA0A0C */  jal        func_002b2970
    /* 1C1394 002C1394 00000000 */   nop
    /* 1C1398 002C1398 940D248E */  lw         $4, 0xD94($17)
    /* 1C139C 002C139C 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C13A0 002C13A0 3300056A */  ldl        $5, 0x33($16)
    /* 1C13A4 002C13A4 C005A6DF */  ld         $6, 0x5C0($29)
    /* 1C13A8 002C13A8 2D380000 */  daddu      $7, $0, $0
    /* 1C13AC 002C13AC 0A000824 */  addiu      $8, $0, 0xA
    /* 1C13B0 002C13B0 2D480000 */  daddu      $9, $0, $0
    /* 1C13B4 002C13B4 88810B0C */  jal        func_002e0620
    /* 1C13B8 002C13B8 00000000 */   nop
    /* 1C13BC 002C13BC 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C13C0 002C13C0 38810B0C */  jal        func_002e04e0
    /* 1C13C4 002C13C4 00000000 */   nop
    /* 1C13C8 002C13C8 2D804000 */  daddu      $16, $2, $0
    /* 1C13CC 002C13CC 9C43023C */  lui        $2, (0x439C0000 >> 16)
    /* 1C13D0 002C13D0 00608244 */  mtc1       $2, $f12
    /* 1C13D4 002C13D4 0DC3023C */  lui        $2, (0xC30D0000 >> 16)
    /* 1C13D8 002C13D8 00688244 */  mtc1       $2, $f13
    /* 1C13DC 002C13DC B805A427 */  addiu      $4, $29, 0x5B8
    /* 1C13E0 002C13E0 5CCA0A0C */  jal        func_002b2970
    /* 1C13E4 002C13E4 00000000 */   nop
    /* 1C13E8 002C13E8 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C13EC 002C13EC 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C13F0 002C13F0 3300056A */  ldl        $5, 0x33($16)
    /* 1C13F4 002C13F4 B805A6DF */  ld         $6, 0x5B8($29)
    /* 1C13F8 002C13F8 2D380000 */  daddu      $7, $0, $0
    /* 1C13FC 002C13FC 0A000824 */  addiu      $8, $0, 0xA
    /* 1C1400 002C1400 2D480000 */  daddu      $9, $0, $0
    /* 1C1404 002C1404 88810B0C */  jal        func_002e0620
    /* 1C1408 002C1408 00000000 */   nop
    /* 1C140C 002C140C 00608044 */  mtc1       $0, $f12
    /* 1C1410 002C1410 B443023C */  lui        $2, (0x43B40000 >> 16)
    /* 1C1414 002C1414 00688244 */  mtc1       $2, $f13
    /* 1C1418 002C1418 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C141C 002C141C 2D280000 */  daddu      $5, $0, $0
    /* 1C1420 002C1420 08070624 */  addiu      $6, $0, 0x708
    /* 1C1424 002C1424 2D380000 */  daddu      $7, $0, $0
    /* 1C1428 002C1428 50820B0C */  jal        func_002e0940
    /* 1C142C 002C142C 00000000 */   nop
    /* 1C1430 002C1430 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C1434 002C1434 06000524 */  addiu      $5, $0, 0x6
    /* 1C1438 002C1438 2D300000 */  daddu      $6, $0, $0
    /* 1C143C 002C143C 3C810B0C */  jal        func_002e04f0
    /* 1C1440 002C1440 00000000 */   nop
  .L002C1444:
    /* 1C1444 002C1444 2D800000 */  daddu      $16, $0, $0
    /* 1C1448 002C1448 0E000010 */  b          .L002C1484
    /* 1C144C 002C144C 00000000 */   nop
  .L002C1450:
    /* 1C1450 002C1450 80100300 */  sll        $2, $3, 2
    /* 1C1454 002C1454 21102202 */  addu       $2, $17, $2
    /* 1C1458 002C1458 380C448C */  lw         $4, 0xC38($2)
    /* 1C145C 002C145C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C1460 002C1460 2D300000 */  daddu      $6, $0, $0
    /* 1C1464 002C1464 2D380000 */  daddu      $7, $0, $0
    /* 1C1468 002C1468 0A000824 */  addiu      $8, $0, 0xA
    /* 1C146C 002C146C 2D480000 */  daddu      $9, $0, $0
    /* 1C1470 002C1470 98810B0C */  jal        func_002e0660
    /* 1C1474 002C1474 00000000 */   nop
    /* 1C1478 002C1478 01000226 */  addiu      $2, $16, 0x1
    /* 1C147C 002C147C 3C840200 */  dsll32     $16, $2, 16
    /* 1C1480 002C1480 3F841000 */  dsra32     $16, $16, 16
  .L002C1484:
    /* 1C1484 002C1484 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C1488 002C1488 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C148C 002C148C 03006228 */  slti       $2, $3, 0x3
    /* 1C1490 002C1490 EFFF4014 */  bnez       $2, .L002C1450
    /* 1C1494 002C1494 00000000 */   nop
    /* 1C1498 002C1498 13000224 */  addiu      $2, $0, 0x13
    /* 1C149C 002C149C 000022A2 */  sb         $2, 0x0($17)
    /* 1C14A0 002C14A0 A1240010 */  b          .L002CA728
    /* 1C14A4 002C14A4 00000000 */   nop
    /* 1C14A8 002C14A8 55001024 */  addiu      $16, $0, 0x55
    /* 1C14AC 002C14AC 14000010 */  b          .L002C1500
    /* 1C14B0 002C14B0 00000000 */   nop
  .L002C14B4:
    /* 1C14B4 002C14B4 80100300 */  sll        $2, $3, 2
    /* 1C14B8 002C14B8 21102202 */  addu       $2, $17, $2
    /* 1C14BC 002C14BC 380C5224 */  addiu      $18, $2, 0xC38
    /* 1C14C0 002C14C0 380C448C */  lw         $4, 0xC38($2)
    /* 1C14C4 002C14C4 01000524 */  addiu      $5, $0, 0x1
    /* 1C14C8 002C14C8 5C810B0C */  jal        func_002e0570
    /* 1C14CC 002C14CC 00000000 */   nop
    /* 1C14D0 002C14D0 3C160200 */  dsll32     $2, $2, 24
    /* 1C14D4 002C14D4 3F160200 */  dsra32     $2, $2, 24
    /* 1C14D8 002C14D8 06004014 */  bnez       $2, .L002C14F4
    /* 1C14DC 002C14DC 00000000 */   nop
    /* 1C14E0 002C14E0 0000448E */  lw         $4, 0x0($18)
    /* 1C14E4 002C14E4 03000524 */  addiu      $5, $0, 0x3
    /* 1C14E8 002C14E8 2D300000 */  daddu      $6, $0, $0
    /* 1C14EC 002C14EC 3C810B0C */  jal        func_002e04f0
    /* 1C14F0 002C14F0 00000000 */   nop
  .L002C14F4:
    /* 1C14F4 002C14F4 01000226 */  addiu      $2, $16, 0x1
    /* 1C14F8 002C14F8 3C840200 */  dsll32     $16, $2, 16
    /* 1C14FC 002C14FC 3F841000 */  dsra32     $16, $16, 16
  .L002C1500:
    /* 1C1500 002C1500 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C1504 002C1504 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C1508 002C1508 58006228 */  slti       $2, $3, 0x58
    /* 1C150C 002C150C E9FF4014 */  bnez       $2, .L002C14B4
    /* 1C1510 002C1510 00000000 */   nop
    /* 1C1514 002C1514 59001024 */  addiu      $16, $0, 0x59
    /* 1C1518 002C1518 14000010 */  b          .L002C156C
    /* 1C151C 002C151C 00000000 */   nop
  .L002C1520:
    /* 1C1520 002C1520 80100300 */  sll        $2, $3, 2
    /* 1C1524 002C1524 21102202 */  addu       $2, $17, $2
    /* 1C1528 002C1528 380C5224 */  addiu      $18, $2, 0xC38
    /* 1C152C 002C152C 380C448C */  lw         $4, 0xC38($2)
    /* 1C1530 002C1530 01000524 */  addiu      $5, $0, 0x1
    /* 1C1534 002C1534 5C810B0C */  jal        func_002e0570
    /* 1C1538 002C1538 00000000 */   nop
    /* 1C153C 002C153C 3C160200 */  dsll32     $2, $2, 24
    /* 1C1540 002C1540 3F160200 */  dsra32     $2, $2, 24
    /* 1C1544 002C1544 06004014 */  bnez       $2, .L002C1560
    /* 1C1548 002C1548 00000000 */   nop
    /* 1C154C 002C154C 0000448E */  lw         $4, 0x0($18)
    /* 1C1550 002C1550 03000524 */  addiu      $5, $0, 0x3
    /* 1C1554 002C1554 2D300000 */  daddu      $6, $0, $0
    /* 1C1558 002C1558 3C810B0C */  jal        func_002e04f0
    /* 1C155C 002C155C 00000000 */   nop
  .L002C1560:
    /* 1C1560 002C1560 01000226 */  addiu      $2, $16, 0x1
    /* 1C1564 002C1564 3C840200 */  dsll32     $16, $2, 16
    /* 1C1568 002C1568 3F841000 */  dsra32     $16, $16, 16
  .L002C156C:
    /* 1C156C 002C156C 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C1570 002C1570 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C1574 002C1574 60006228 */  slti       $2, $3, 0x60
    /* 1C1578 002C1578 E9FF4014 */  bnez       $2, .L002C1520
    /* 1C157C 002C157C 00000000 */   nop
    /* 1C1580 002C1580 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1584 002C1584 68810B0C */  jal        func_002e05a0
    /* 1C1588 002C1588 00000000 */   nop
    /* 1C158C 002C158C 3C160200 */  dsll32     $2, $2, 24
    /* 1C1590 002C1590 3F160200 */  dsra32     $2, $2, 24
    /* 1C1594 002C1594 64244014 */  bnez       $2, .L002CA728
    /* 1C1598 002C1598 00000000 */   nop
    /* 1C159C 002C159C 500C248E */  lw         $4, 0xC50($17)
    /* 1C15A0 002C15A0 68810B0C */  jal        func_002e05a0
    /* 1C15A4 002C15A4 00000000 */   nop
    /* 1C15A8 002C15A8 3C160200 */  dsll32     $2, $2, 24
    /* 1C15AC 002C15AC 3F160200 */  dsra32     $2, $2, 24
    /* 1C15B0 002C15B0 5D244014 */  bnez       $2, .L002CA728
    /* 1C15B4 002C15B4 00000000 */   nop
    /* 1C15B8 002C15B8 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C15BC 002C15BC 01000524 */  addiu      $5, $0, 0x1
    /* 1C15C0 002C15C0 5C810B0C */  jal        func_002e0570
    /* 1C15C4 002C15C4 00000000 */   nop
    /* 1C15C8 002C15C8 3C160200 */  dsll32     $2, $2, 24
    /* 1C15CC 002C15CC 3F160200 */  dsra32     $2, $2, 24
    /* 1C15D0 002C15D0 55244014 */  bnez       $2, .L002CA728
    /* 1C15D4 002C15D4 00000000 */   nop
    /* 1C15D8 002C15D8 900D248E */  lw         $4, 0xD90($17)
    /* 1C15DC 002C15DC 01000524 */  addiu      $5, $0, 0x1
    /* 1C15E0 002C15E0 5C810B0C */  jal        func_002e0570
    /* 1C15E4 002C15E4 00000000 */   nop
    /* 1C15E8 002C15E8 3C160200 */  dsll32     $2, $2, 24
    /* 1C15EC 002C15EC 3F160200 */  dsra32     $2, $2, 24
    /* 1C15F0 002C15F0 4D244014 */  bnez       $2, .L002CA728
    /* 1C15F4 002C15F4 00000000 */   nop
    /* 1C15F8 002C15F8 940D248E */  lw         $4, 0xD94($17)
    /* 1C15FC 002C15FC 01000524 */  addiu      $5, $0, 0x1
    /* 1C1600 002C1600 5C810B0C */  jal        func_002e0570
    /* 1C1604 002C1604 00000000 */   nop
    /* 1C1608 002C1608 3C160200 */  dsll32     $2, $2, 24
    /* 1C160C 002C160C 3F160200 */  dsra32     $2, $2, 24
    /* 1C1610 002C1610 45244014 */  bnez       $2, .L002CA728
    /* 1C1614 002C1614 00000000 */   nop
    /* 1C1618 002C1618 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C161C 002C161C 68810B0C */  jal        func_002e05a0
    /* 1C1620 002C1620 00000000 */   nop
    /* 1C1624 002C1624 3C160200 */  dsll32     $2, $2, 24
    /* 1C1628 002C1628 3F160200 */  dsra32     $2, $2, 24
    /* 1C162C 002C162C 3E244014 */  bnez       $2, .L002CA728
    /* 1C1630 002C1630 00000000 */   nop
    /* 1C1634 002C1634 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1638 002C1638 38810B0C */  jal        func_002e04e0
    /* 1C163C 002C163C 00000000 */   nop
    /* 1C1640 002C1640 00688044 */  mtc1       $0, $f13
    /* 1C1644 002C1644 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1648 002C1648 C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C164C 002C164C 2D280000 */  daddu      $5, $0, $0
    /* 1C1650 002C1650 07000624 */  addiu      $6, $0, 0x7
    /* 1C1654 002C1654 06000724 */  addiu      $7, $0, 0x6
    /* 1C1658 002C1658 50820B0C */  jal        func_002e0940
    /* 1C165C 002C165C 00000000 */   nop
    /* 1C1660 002C1660 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1664 002C1664 38810B0C */  jal        func_002e04e0
    /* 1C1668 002C1668 00000000 */   nop
    /* 1C166C 002C166C 2D804000 */  daddu      $16, $2, $0
    /* 1C1670 002C1670 C8C3023C */  lui        $2, (0xC3C80000 >> 16)
    /* 1C1674 002C1674 00608244 */  mtc1       $2, $f12
    /* 1C1678 002C1678 E143023C */  lui        $2, (0x43E10000 >> 16)
    /* 1C167C 002C167C 00688244 */  mtc1       $2, $f13
    /* 1C1680 002C1680 B005A427 */  addiu      $4, $29, 0x5B0
    /* 1C1684 002C1684 5CCA0A0C */  jal        func_002b2970
    /* 1C1688 002C1688 00000000 */   nop
    /* 1C168C 002C168C 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1690 002C1690 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C1694 002C1694 3300056A */  ldl        $5, 0x33($16)
    /* 1C1698 002C1698 B005A6DF */  ld         $6, 0x5B0($29)
    /* 1C169C 002C169C 2D380000 */  daddu      $7, $0, $0
    /* 1C16A0 002C16A0 07000824 */  addiu      $8, $0, 0x7
    /* 1C16A4 002C16A4 06000924 */  addiu      $9, $0, 0x6
    /* 1C16A8 002C16A8 88810B0C */  jal        func_002e0620
    /* 1C16AC 002C16AC 00000000 */   nop
    /* 1C16B0 002C16B0 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C16B4 002C16B4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C16B8 002C16B8 2D300000 */  daddu      $6, $0, $0
    /* 1C16BC 002C16BC 2D380000 */  daddu      $7, $0, $0
    /* 1C16C0 002C16C0 07000824 */  addiu      $8, $0, 0x7
    /* 1C16C4 002C16C4 06000924 */  addiu      $9, $0, 0x6
    /* 1C16C8 002C16C8 98810B0C */  jal        func_002e0660
    /* 1C16CC 002C16CC 00000000 */   nop
    /* 1C16D0 002C16D0 500C248E */  lw         $4, 0xC50($17)
    /* 1C16D4 002C16D4 38810B0C */  jal        func_002e04e0
    /* 1C16D8 002C16D8 00000000 */   nop
    /* 1C16DC 002C16DC 2D804000 */  daddu      $16, $2, $0
    /* 1C16E0 002C16E0 500C248E */  lw         $4, 0xC50($17)
    /* 1C16E4 002C16E4 38810B0C */  jal        func_002e04e0
    /* 1C16E8 002C16E8 00000000 */   nop
    /* 1C16EC 002C16EC C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C16F0 002C16F0 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1C16F4 002C16F4 00008244 */  mtc1       $2, $f0
    /* 1C16F8 002C16F8 00000000 */  nop
    /* 1C16FC 002C16FC 40030146 */  add.s      $f13, $f0, $f1
    /* 1C1700 002C1700 500C248E */  lw         $4, 0xC50($17)
    /* 1C1704 002C1704 C4000CC6 */  lwc1       $f12, 0xC4($16)
    /* 1C1708 002C1708 2D280000 */  daddu      $5, $0, $0
    /* 1C170C 002C170C 07000624 */  addiu      $6, $0, 0x7
    /* 1C1710 002C1710 05000724 */  addiu      $7, $0, 0x5
    /* 1C1714 002C1714 50820B0C */  jal        func_002e0940
    /* 1C1718 002C1718 00000000 */   nop
    /* 1C171C 002C171C 500C248E */  lw         $4, 0xC50($17)
    /* 1C1720 002C1720 38810B0C */  jal        func_002e04e0
    /* 1C1724 002C1724 00000000 */   nop
    /* 1C1728 002C1728 2D804000 */  daddu      $16, $2, $0
    /* 1C172C 002C172C 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C1730 002C1730 00608244 */  mtc1       $2, $f12
    /* 1C1734 002C1734 EE020224 */  addiu      $2, $0, 0x2EE
    /* 1C1738 002C1738 00008244 */  mtc1       $2, $f0
    /* 1C173C 002C173C 00000000 */  nop
    /* 1C1740 002C1740 60038046 */  cvt.s.w    $f13, $f0
    /* 1C1744 002C1744 A805A427 */  addiu      $4, $29, 0x5A8
    /* 1C1748 002C1748 5CCA0A0C */  jal        func_002b2970
    /* 1C174C 002C174C 00000000 */   nop
    /* 1C1750 002C1750 500C248E */  lw         $4, 0xC50($17)
    /* 1C1754 002C1754 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C1758 002C1758 3300056A */  ldl        $5, 0x33($16)
    /* 1C175C 002C175C A805A6DF */  ld         $6, 0x5A8($29)
    /* 1C1760 002C1760 2D380000 */  daddu      $7, $0, $0
    /* 1C1764 002C1764 07000824 */  addiu      $8, $0, 0x7
    /* 1C1768 002C1768 05000924 */  addiu      $9, $0, 0x5
    /* 1C176C 002C176C 88810B0C */  jal        func_002e0620
    /* 1C1770 002C1770 00000000 */   nop
    /* 1C1774 002C1774 500C248E */  lw         $4, 0xC50($17)
    /* 1C1778 002C1778 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C177C 002C177C 2D300000 */  daddu      $6, $0, $0
    /* 1C1780 002C1780 2D380000 */  daddu      $7, $0, $0
    /* 1C1784 002C1784 07000824 */  addiu      $8, $0, 0x7
    /* 1C1788 002C1788 05000924 */  addiu      $9, $0, 0x5
    /* 1C178C 002C178C 98810B0C */  jal        func_002e0660
    /* 1C1790 002C1790 00000000 */   nop
    /* 1C1794 002C1794 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C1798 002C1798 38810B0C */  jal        func_002e04e0
    /* 1C179C 002C179C 00000000 */   nop
    /* 1C17A0 002C17A0 2D804000 */  daddu      $16, $2, $0
    /* 1C17A4 002C17A4 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C17A8 002C17A8 00608244 */  mtc1       $2, $f12
    /* 1C17AC 002C17AC EE020224 */  addiu      $2, $0, 0x2EE
    /* 1C17B0 002C17B0 00008244 */  mtc1       $2, $f0
    /* 1C17B4 002C17B4 00000000 */  nop
    /* 1C17B8 002C17B8 60038046 */  cvt.s.w    $f13, $f0
    /* 1C17BC 002C17BC A005A427 */  addiu      $4, $29, 0x5A0
    /* 1C17C0 002C17C0 5CCA0A0C */  jal        func_002b2970
    /* 1C17C4 002C17C4 00000000 */   nop
    /* 1C17C8 002C17C8 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C17CC 002C17CC 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C17D0 002C17D0 3300056A */  ldl        $5, 0x33($16)
    /* 1C17D4 002C17D4 A005A6DF */  ld         $6, 0x5A0($29)
    /* 1C17D8 002C17D8 2D380000 */  daddu      $7, $0, $0
    /* 1C17DC 002C17DC 07000824 */  addiu      $8, $0, 0x7
    /* 1C17E0 002C17E0 03000924 */  addiu      $9, $0, 0x3
    /* 1C17E4 002C17E4 88810B0C */  jal        func_002e0620
    /* 1C17E8 002C17E8 00000000 */   nop
    /* 1C17EC 002C17EC 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C17F0 002C17F0 38810B0C */  jal        func_002e04e0
    /* 1C17F4 002C17F4 00000000 */   nop
    /* 1C17F8 002C17F8 2D804000 */  daddu      $16, $2, $0
    /* 1C17FC 002C17FC 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C1800 002C1800 38810B0C */  jal        func_002e04e0
    /* 1C1804 002C1804 00000000 */   nop
    /* 1C1808 002C1808 C40041C4 */  lwc1       $f1, 0xC4($2)
    /* 1C180C 002C180C F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1C1810 002C1810 00008244 */  mtc1       $2, $f0
    /* 1C1814 002C1814 00000000 */  nop
    /* 1C1818 002C1818 40030146 */  add.s      $f13, $f0, $f1
    /* 1C181C 002C181C 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C1820 002C1820 C4000CC6 */  lwc1       $f12, 0xC4($16)
    /* 1C1824 002C1824 2D280000 */  daddu      $5, $0, $0
    /* 1C1828 002C1828 07000624 */  addiu      $6, $0, 0x7
    /* 1C182C 002C182C 03000724 */  addiu      $7, $0, 0x3
    /* 1C1830 002C1830 50820B0C */  jal        func_002e0940
    /* 1C1834 002C1834 00000000 */   nop
    /* 1C1838 002C1838 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C183C 002C183C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C1840 002C1840 2D300000 */  daddu      $6, $0, $0
    /* 1C1844 002C1844 2D380000 */  daddu      $7, $0, $0
    /* 1C1848 002C1848 07000824 */  addiu      $8, $0, 0x7
    /* 1C184C 002C184C 03000924 */  addiu      $9, $0, 0x3
    /* 1C1850 002C1850 98810B0C */  jal        func_002e0660
    /* 1C1854 002C1854 00000000 */   nop
    /* 1C1858 002C1858 07002282 */  lb         $2, 0x7($17)
    /* 1C185C 002C185C 0600412C */  sltiu      $1, $2, 0x6
    /* 1C1860 002C1860 B1232010 */  beqz       $1, .L002CA728
    /* 1C1864 002C1864 00000000 */   nop
    /* 1C1868 002C1868 7500033C */  lui        $3, %hi(jtbl_00748910)
    /* 1C186C 002C186C 10896324 */  addiu      $3, $3, %lo(jtbl_00748910)
    /* 1C1870 002C1870 80100200 */  sll        $2, $2, 2
    /* 1C1874 002C1874 21104300 */  addu       $2, $2, $3
    /* 1C1878 002C1878 0000428C */  lw         $2, 0x0($2)
    /* 1C187C 002C187C 08004000 */  jr         $2
    /* 1C1880 002C1880 00000000 */   nop
    /* 1C1884 002C1884 2D208002 */  daddu      $4, $20, $0
    /* 1C1888 002C1888 28680B0C */  jal        func_002da0a0
    /* 1C188C 002C188C 00000000 */   nop
    /* 1C1890 002C1890 A5230010 */  b          .L002CA728
    /* 1C1894 002C1894 00000000 */   nop
    /* 1C1898 002C1898 2D208002 */  daddu      $4, $20, $0
    /* 1C189C 002C189C 006D0B0C */  jal        func_002db400
    /* 1C18A0 002C18A0 00000000 */   nop
    /* 1C18A4 002C18A4 200C20AE */  sw         $0, 0xC20($17)
    /* 1C18A8 002C18A8 01001024 */  addiu      $16, $0, 0x1
    /* 1C18AC 002C18AC 37000010 */  b          .L002C198C
    /* 1C18B0 002C18B0 00000000 */   nop
  .L002C18B4:
    /* 1C18B4 002C18B4 3C9C1000 */  dsll32     $19, $16, 16
    /* 1C18B8 002C18B8 3F9C1300 */  dsra32     $19, $19, 16
    /* 1C18BC 002C18BC 180F248E */  lw         $4, 0xF18($17)
    /* 1C18C0 002C18C0 2D286002 */  daddu      $5, $19, $0
    /* 1C18C4 002C18C4 0C8A0B0C */  jal        func_002e2830
    /* 1C18C8 002C18C8 00000000 */   nop
    /* 1C18CC 002C18CC 3C940200 */  dsll32     $18, $2, 16
    /* 1C18D0 002C18D0 3F941200 */  dsra32     $18, $18, 16
    /* 1C18D4 002C18D4 180F248E */  lw         $4, 0xF18($17)
    /* 1C18D8 002C18D8 2D286002 */  daddu      $5, $19, $0
    /* 1C18DC 002C18DC 3C8A0B0C */  jal        func_002e28f0
    /* 1C18E0 002C18E0 00000000 */   nop
    /* 1C18E4 002C18E4 3CA41200 */  dsll32     $20, $18, 16
    /* 1C18E8 002C18E8 3FA41400 */  dsra32     $20, $20, 16
    /* 1C18EC 002C18EC 2D208002 */  daddu      $4, $20, $0
    /* 1C18F0 002C18F0 0C42040C */  jal        func_00110830
    /* 1C18F4 002C18F4 00000000 */   nop
    /* 1C18F8 002C18F8 FF005330 */  andi       $19, $2, 0xFF
    /* 1C18FC 002C18FC 2D204002 */  daddu      $4, $18, $0
    /* 1C1900 002C1900 8019040C */  jal        func_00106600
    /* 1C1904 002C1904 00000000 */   nop
    /* 1C1908 002C1908 FF004530 */  andi       $5, $2, 0xFF
    /* 1C190C 002C190C 2D206002 */  daddu      $4, $19, $0
    /* 1C1910 002C1910 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C1914 002C1914 2D380000 */  daddu      $7, $0, $0
    /* 1C1918 002C1918 01000824 */  addiu      $8, $0, 0x1
    /* 1C191C 002C191C 2CCB0A0C */  jal        func_002b2cb0
    /* 1C1920 002C1920 00000000 */   nop
    /* 1C1924 002C1924 3C241400 */  dsll32     $4, $20, 16
    /* 1C1928 002C1928 3F240400 */  dsra32     $4, $4, 16
    /* 1C192C 002C192C A41A040C */  jal        func_00106a90
    /* 1C1930 002C1930 00000000 */   nop
    /* 1C1934 002C1934 05000324 */  addiu      $3, $0, 0x5
    /* 1C1938 002C1938 1B004300 */  divu       $0, $2, $3
    /* 1C193C 002C193C 12980000 */  mflo       $19
    /* 1C1940 002C1940 2D204002 */  daddu      $4, $18, $0
    /* 1C1944 002C1944 8019040C */  jal        func_00106600
    /* 1C1948 002C1948 00000000 */   nop
    /* 1C194C 002C194C FF004230 */  andi       $2, $2, 0xFF
    /* 1C1950 002C1950 18186202 */  mult       $3, $19, $2
    /* 1C1954 002C1954 200C228E */  lw         $2, 0xC20($17)
    /* 1C1958 002C1958 21204300 */  addu       $4, $2, $3
    /* 1C195C 002C195C 200C24AE */  sw         $4, 0xC20($17)
    /* 1C1960 002C1960 2D280000 */  daddu      $5, $0, $0
    /* 1C1964 002C1964 9800023C */  lui        $2, (0x98967F >> 16)
    /* 1C1968 002C1968 7F964634 */  ori        $6, $2, (0x98967F & 0xFFFF)
    /* 1C196C 002C196C 2D380000 */  daddu      $7, $0, $0
    /* 1C1970 002C1970 01000824 */  addiu      $8, $0, 0x1
    /* 1C1974 002C1974 2CCB0A0C */  jal        func_002b2cb0
    /* 1C1978 002C1978 00000000 */   nop
    /* 1C197C 002C197C 200C22AE */  sw         $2, 0xC20($17)
    /* 1C1980 002C1980 01000226 */  addiu      $2, $16, 0x1
    /* 1C1984 002C1984 3C840200 */  dsll32     $16, $2, 16
    /* 1C1988 002C1988 3F841000 */  dsra32     $16, $16, 16
  .L002C198C:
    /* 1C198C 002C198C 3C941000 */  dsll32     $18, $16, 16
    /* 1C1990 002C1990 3F941200 */  dsra32     $18, $18, 16
    /* 1C1994 002C1994 180F248E */  lw         $4, 0xF18($17)
    /* 1C1998 002C1998 BC890B0C */  jal        func_002e26f0
    /* 1C199C 002C199C 00000000 */   nop
    /* 1C19A0 002C19A0 2A104202 */  slt        $2, $18, $2
    /* 1C19A4 002C19A4 C3FF4014 */  bnez       $2, .L002C18B4
    /* 1C19A8 002C19A8 00000000 */   nop
    /* 1C19AC 002C19AC 5E230010 */  b          .L002CA728
    /* 1C19B0 002C19B0 00000000 */   nop
    /* 1C19B4 002C19B4 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C19B8 002C19B8 2D280000 */  daddu      $5, $0, $0
    /* 1C19BC 002C19BC 01000624 */  addiu      $6, $0, 0x1
    /* 1C19C0 002C19C0 3C810B0C */  jal        func_002e04f0
    /* 1C19C4 002C19C4 00000000 */   nop
    /* 1C19C8 002C19C8 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1C19CC 002C19CC 2D280000 */  daddu      $5, $0, $0
    /* 1C19D0 002C19D0 01000624 */  addiu      $6, $0, 0x1
    /* 1C19D4 002C19D4 3C810B0C */  jal        func_002e04f0
    /* 1C19D8 002C19D8 00000000 */   nop
    /* 1C19DC 002C19DC 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C19E0 002C19E0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C19E4 002C19E4 2D300000 */  daddu      $6, $0, $0
    /* 1C19E8 002C19E8 2D380000 */  daddu      $7, $0, $0
    /* 1C19EC 002C19EC 0A000824 */  addiu      $8, $0, 0xA
    /* 1C19F0 002C19F0 2D480000 */  daddu      $9, $0, $0
    /* 1C19F4 002C19F4 98810B0C */  jal        func_002e0660
    /* 1C19F8 002C19F8 00000000 */   nop
    /* 1C19FC 002C19FC 900D248E */  lw         $4, 0xD90($17)
    /* 1C1A00 002C1A00 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C1A04 002C1A04 2D300000 */  daddu      $6, $0, $0
    /* 1C1A08 002C1A08 2D380000 */  daddu      $7, $0, $0
    /* 1C1A0C 002C1A0C 0A000824 */  addiu      $8, $0, 0xA
    /* 1C1A10 002C1A10 2D480000 */  daddu      $9, $0, $0
    /* 1C1A14 002C1A14 98810B0C */  jal        func_002e0660
    /* 1C1A18 002C1A18 00000000 */   nop
    /* 1C1A1C 002C1A1C 940D248E */  lw         $4, 0xD94($17)
    /* 1C1A20 002C1A20 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C1A24 002C1A24 2D300000 */  daddu      $6, $0, $0
    /* 1C1A28 002C1A28 2D380000 */  daddu      $7, $0, $0
    /* 1C1A2C 002C1A2C 0A000824 */  addiu      $8, $0, 0xA
    /* 1C1A30 002C1A30 2D480000 */  daddu      $9, $0, $0
    /* 1C1A34 002C1A34 98810B0C */  jal        func_002e0660
    /* 1C1A38 002C1A38 00000000 */   nop
    /* 1C1A3C 002C1A3C 2D208002 */  daddu      $4, $20, $0
    /* 1C1A40 002C1A40 F0C70C0C */  jal        func_00331fc0
    /* 1C1A44 002C1A44 00000000 */   nop
    /* 1C1A48 002C1A48 35000224 */  addiu      $2, $0, 0x35
    /* 1C1A4C 002C1A4C 000022A2 */  sb         $2, 0x0($17)
    /* 1C1A50 002C1A50 35230010 */  b          .L002CA728
    /* 1C1A54 002C1A54 00000000 */   nop
    /* 1C1A58 002C1A58 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C1A5C 002C1A5C 2D280000 */  daddu      $5, $0, $0
    /* 1C1A60 002C1A60 01000624 */  addiu      $6, $0, 0x1
    /* 1C1A64 002C1A64 3C810B0C */  jal        func_002e04f0
    /* 1C1A68 002C1A68 00000000 */   nop
    /* 1C1A6C 002C1A6C EC0D248E */  lw         $4, 0xDEC($17)
    /* 1C1A70 002C1A70 2D280000 */  daddu      $5, $0, $0
    /* 1C1A74 002C1A74 01000624 */  addiu      $6, $0, 0x1
    /* 1C1A78 002C1A78 3C810B0C */  jal        func_002e04f0
    /* 1C1A7C 002C1A7C 00000000 */   nop
    /* 1C1A80 002C1A80 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C1A84 002C1A84 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C1A88 002C1A88 2D300000 */  daddu      $6, $0, $0
    /* 1C1A8C 002C1A8C 2D380000 */  daddu      $7, $0, $0
    /* 1C1A90 002C1A90 0A000824 */  addiu      $8, $0, 0xA
    /* 1C1A94 002C1A94 2D480000 */  daddu      $9, $0, $0
    /* 1C1A98 002C1A98 98810B0C */  jal        func_002e0660
    /* 1C1A9C 002C1A9C 00000000 */   nop
    /* 1C1AA0 002C1AA0 900D248E */  lw         $4, 0xD90($17)
    /* 1C1AA4 002C1AA4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C1AA8 002C1AA8 2D300000 */  daddu      $6, $0, $0
    /* 1C1AAC 002C1AAC 2D380000 */  daddu      $7, $0, $0
    /* 1C1AB0 002C1AB0 0A000824 */  addiu      $8, $0, 0xA
    /* 1C1AB4 002C1AB4 2D480000 */  daddu      $9, $0, $0
    /* 1C1AB8 002C1AB8 98810B0C */  jal        func_002e0660
    /* 1C1ABC 002C1ABC 00000000 */   nop
    /* 1C1AC0 002C1AC0 940D248E */  lw         $4, 0xD94($17)
    /* 1C1AC4 002C1AC4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C1AC8 002C1AC8 2D300000 */  daddu      $6, $0, $0
    /* 1C1ACC 002C1ACC 2D380000 */  daddu      $7, $0, $0
    /* 1C1AD0 002C1AD0 0A000824 */  addiu      $8, $0, 0xA
    /* 1C1AD4 002C1AD4 2D480000 */  daddu      $9, $0, $0
    /* 1C1AD8 002C1AD8 98810B0C */  jal        func_002e0660
    /* 1C1ADC 002C1ADC 00000000 */   nop
    /* 1C1AE0 002C1AE0 37000224 */  addiu      $2, $0, 0x37
    /* 1C1AE4 002C1AE4 000022A2 */  sb         $2, 0x0($17)
    /* 1C1AE8 002C1AE8 0F230010 */  b          .L002CA728
    /* 1C1AEC 002C1AEC 00000000 */   nop
    /* 1C1AF0 002C1AF0 D40E248E */  lw         $4, 0xED4($17)
    /* 1C1AF4 002C1AF4 68810B0C */  jal        func_002e05a0
    /* 1C1AF8 002C1AF8 00000000 */   nop
    /* 1C1AFC 002C1AFC 3C160200 */  dsll32     $2, $2, 24
    /* 1C1B00 002C1B00 3F160200 */  dsra32     $2, $2, 24
    /* 1C1B04 002C1B04 4B004014 */  bnez       $2, .L002C1C34
    /* 1C1B08 002C1B08 00000000 */   nop
    /* 1C1B0C 002C1B0C D40E248E */  lw         $4, 0xED4($17)
    /* 1C1B10 002C1B10 38810B0C */  jal        func_002e04e0
    /* 1C1B14 002C1B14 00000000 */   nop
    /* 1C1B18 002C1B18 2D804000 */  daddu      $16, $2, $0
    /* 1C1B1C 002C1B1C D40E248E */  lw         $4, 0xED4($17)
    /* 1C1B20 002C1B20 38810B0C */  jal        func_002e04e0
    /* 1C1B24 002C1B24 00000000 */   nop
    /* 1C1B28 002C1B28 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C1B2C 002C1B2C 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C1B30 002C1B30 00008244 */  mtc1       $2, $f0
    /* 1C1B34 002C1B34 00000000 */  nop
    /* 1C1B38 002C1B38 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C1B3C 002C1B3C 9805A427 */  addiu      $4, $29, 0x598
    /* 1C1B40 002C1B40 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C1B44 002C1B44 5CCA0A0C */  jal        func_002b2970
    /* 1C1B48 002C1B48 00000000 */   nop
    /* 1C1B4C 002C1B4C D40E248E */  lw         $4, 0xED4($17)
    /* 1C1B50 002C1B50 38810B0C */  jal        func_002e04e0
    /* 1C1B54 002C1B54 00000000 */   nop
    /* 1C1B58 002C1B58 2D804000 */  daddu      $16, $2, $0
    /* 1C1B5C 002C1B5C D40E248E */  lw         $4, 0xED4($17)
    /* 1C1B60 002C1B60 38810B0C */  jal        func_002e04e0
    /* 1C1B64 002C1B64 00000000 */   nop
    /* 1C1B68 002C1B68 9005A427 */  addiu      $4, $29, 0x590
    /* 1C1B6C 002C1B6C 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C1B70 002C1B70 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C1B74 002C1B74 5CCA0A0C */  jal        func_002b2970
    /* 1C1B78 002C1B78 00000000 */   nop
    /* 1C1B7C 002C1B7C D40E248E */  lw         $4, 0xED4($17)
    /* 1C1B80 002C1B80 9805A5DF */  ld         $5, 0x598($29)
    /* 1C1B84 002C1B84 9005A6DF */  ld         $6, 0x590($29)
    /* 1C1B88 002C1B88 01000724 */  addiu      $7, $0, 0x1
    /* 1C1B8C 002C1B8C 04000824 */  addiu      $8, $0, 0x4
    /* 1C1B90 002C1B90 2D480000 */  daddu      $9, $0, $0
    /* 1C1B94 002C1B94 88810B0C */  jal        func_002e0620
    /* 1C1B98 002C1B98 00000000 */   nop
    /* 1C1B9C 002C1B9C D80E248E */  lw         $4, 0xED8($17)
    /* 1C1BA0 002C1BA0 38810B0C */  jal        func_002e04e0
    /* 1C1BA4 002C1BA4 00000000 */   nop
    /* 1C1BA8 002C1BA8 2D804000 */  daddu      $16, $2, $0
    /* 1C1BAC 002C1BAC D80E248E */  lw         $4, 0xED8($17)
    /* 1C1BB0 002C1BB0 38810B0C */  jal        func_002e04e0
    /* 1C1BB4 002C1BB4 00000000 */   nop
    /* 1C1BB8 002C1BB8 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C1BBC 002C1BBC 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C1BC0 002C1BC0 00008244 */  mtc1       $2, $f0
    /* 1C1BC4 002C1BC4 00000000 */  nop
    /* 1C1BC8 002C1BC8 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C1BCC 002C1BCC 8805A427 */  addiu      $4, $29, 0x588
    /* 1C1BD0 002C1BD0 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C1BD4 002C1BD4 5CCA0A0C */  jal        func_002b2970
    /* 1C1BD8 002C1BD8 00000000 */   nop
    /* 1C1BDC 002C1BDC D80E248E */  lw         $4, 0xED8($17)
    /* 1C1BE0 002C1BE0 38810B0C */  jal        func_002e04e0
    /* 1C1BE4 002C1BE4 00000000 */   nop
    /* 1C1BE8 002C1BE8 2D804000 */  daddu      $16, $2, $0
    /* 1C1BEC 002C1BEC D80E248E */  lw         $4, 0xED8($17)
    /* 1C1BF0 002C1BF0 38810B0C */  jal        func_002e04e0
    /* 1C1BF4 002C1BF4 00000000 */   nop
    /* 1C1BF8 002C1BF8 8005A427 */  addiu      $4, $29, 0x580
    /* 1C1BFC 002C1BFC 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C1C00 002C1C00 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C1C04 002C1C04 5CCA0A0C */  jal        func_002b2970
    /* 1C1C08 002C1C08 00000000 */   nop
    /* 1C1C0C 002C1C0C D80E248E */  lw         $4, 0xED8($17)
    /* 1C1C10 002C1C10 8805A5DF */  ld         $5, 0x588($29)
    /* 1C1C14 002C1C14 8005A6DF */  ld         $6, 0x580($29)
    /* 1C1C18 002C1C18 01000724 */  addiu      $7, $0, 0x1
    /* 1C1C1C 002C1C1C 04000824 */  addiu      $8, $0, 0x4
    /* 1C1C20 002C1C20 2D480000 */  daddu      $9, $0, $0
    /* 1C1C24 002C1C24 88810B0C */  jal        func_002e0620
    /* 1C1C28 002C1C28 00000000 */   nop
    /* 1C1C2C 002C1C2C 15000224 */  addiu      $2, $0, 0x15
    /* 1C1C30 002C1C30 000022A2 */  sb         $2, 0x0($17)
  .L002C1C34:
    /* 1C1C34 002C1C34 600D248E */  lw         $4, 0xD60($17)
    /* 1C1C38 002C1C38 68810B0C */  jal        func_002e05a0
    /* 1C1C3C 002C1C3C 00000000 */   nop
    /* 1C1C40 002C1C40 3C160200 */  dsll32     $2, $2, 24
    /* 1C1C44 002C1C44 3F160200 */  dsra32     $2, $2, 24
    /* 1C1C48 002C1C48 04004014 */  bnez       $2, .L002C1C5C
    /* 1C1C4C 002C1C4C 00000000 */   nop
    /* 1C1C50 002C1C50 2D208002 */  daddu      $4, $20, $0
    /* 1C1C54 002C1C54 68790B0C */  jal        func_002de5a0
    /* 1C1C58 002C1C58 00000000 */   nop
  .L002C1C5C:
    /* 1C1C5C 002C1C5C 580C248E */  lw         $4, 0xC58($17)
    /* 1C1C60 002C1C60 68810B0C */  jal        func_002e05a0
    /* 1C1C64 002C1C64 00000000 */   nop
    /* 1C1C68 002C1C68 3C160200 */  dsll32     $2, $2, 24
    /* 1C1C6C 002C1C6C 3F160200 */  dsra32     $2, $2, 24
    /* 1C1C70 002C1C70 AD224014 */  bnez       $2, .L002CA728
    /* 1C1C74 002C1C74 00000000 */   nop
    /* 1C1C78 002C1C78 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C1C7C 002C1C7C 68810B0C */  jal        func_002e05a0
    /* 1C1C80 002C1C80 00000000 */   nop
    /* 1C1C84 002C1C84 3C160200 */  dsll32     $2, $2, 24
    /* 1C1C88 002C1C88 3F160200 */  dsra32     $2, $2, 24
    /* 1C1C8C 002C1C8C 02004010 */  beqz       $2, .L002C1C98
    /* 1C1C90 002C1C90 00000000 */   nop
    /* 1C1C94 002C1C94 01001324 */  addiu      $19, $0, 0x1
  .L002C1C98:
    /* 1C1C98 002C1C98 500C248E */  lw         $4, 0xC50($17)
    /* 1C1C9C 002C1C9C 68810B0C */  jal        func_002e05a0
    /* 1C1CA0 002C1CA0 00000000 */   nop
    /* 1C1CA4 002C1CA4 3C160200 */  dsll32     $2, $2, 24
    /* 1C1CA8 002C1CA8 3F160200 */  dsra32     $2, $2, 24
    /* 1C1CAC 002C1CAC 02004010 */  beqz       $2, .L002C1CB8
    /* 1C1CB0 002C1CB0 00000000 */   nop
    /* 1C1CB4 002C1CB4 01001324 */  addiu      $19, $0, 0x1
  .L002C1CB8:
    /* 1C1CB8 002C1CB8 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C1CBC 002C1CBC 68810B0C */  jal        func_002e05a0
    /* 1C1CC0 002C1CC0 00000000 */   nop
    /* 1C1CC4 002C1CC4 3C160200 */  dsll32     $2, $2, 24
    /* 1C1CC8 002C1CC8 3F160200 */  dsra32     $2, $2, 24
    /* 1C1CCC 002C1CCC 02004010 */  beqz       $2, .L002C1CD8
    /* 1C1CD0 002C1CD0 00000000 */   nop
    /* 1C1CD4 002C1CD4 01001324 */  addiu      $19, $0, 0x1
  .L002C1CD8:
    /* 1C1CD8 002C1CD8 00002382 */  lb         $3, 0x0($17)
    /* 1C1CDC 002C1CDC 14000224 */  addiu      $2, $0, 0x14
    /* 1C1CE0 002C1CE0 02006214 */  bne        $3, $2, .L002C1CEC
    /* 1C1CE4 002C1CE4 00000000 */   nop
    /* 1C1CE8 002C1CE8 01001324 */  addiu      $19, $0, 0x1
  .L002C1CEC:
    /* 1C1CEC 002C1CEC 2D900000 */  daddu      $18, $0, $0
    /* 1C1CF0 002C1CF0 6D000010 */  b          .L002C1EA8
    /* 1C1CF4 002C1CF4 00000000 */   nop
  .L002C1CF8:
    /* 1C1CF8 002C1CF8 40100300 */  sll        $2, $3, 1
    /* 1C1CFC 002C1CFC 21102202 */  addu       $2, $17, $2
    /* 1C1D00 002C1D00 460F4484 */  lh         $4, 0xF46($2)
    /* 1C1D04 002C1D04 10008010 */  beqz       $4, .L002C1D48
    /* 1C1D08 002C1D08 00000000 */   nop
    /* 1C1D0C 002C1D0C 3C141200 */  dsll32     $2, $18, 16
    /* 1C1D10 002C1D10 3F140200 */  dsra32     $2, $2, 16
    /* 1C1D14 002C1D14 40100200 */  sll        $2, $2, 1
    /* 1C1D18 002C1D18 21102202 */  addu       $2, $17, $2
    /* 1C1D1C 002C1D1C 460F5024 */  addiu      $16, $2, 0xF46
    /* 1C1D20 002C1D20 01000524 */  addiu      $5, $0, 0x1
    /* 1C1D24 002C1D24 2D300000 */  daddu      $6, $0, $0
    /* 1C1D28 002C1D28 2D380000 */  daddu      $7, $0, $0
    /* 1C1D2C 002C1D2C 2D40A000 */  daddu      $8, $5, $0
    /* 1C1D30 002C1D30 40CB0A0C */  jal        func_002b2d00
    /* 1C1D34 002C1D34 00000000 */   nop
    /* 1C1D38 002C1D38 000002A6 */  sh         $2, 0x0($16)
    /* 1C1D3C 002C1D3C 01001324 */  addiu      $19, $0, 0x1
    /* 1C1D40 002C1D40 56000010 */  b          .L002C1E9C
    /* 1C1D44 002C1D44 00000000 */   nop
  .L002C1D48:
    /* 1C1D48 002C1D48 3C841200 */  dsll32     $16, $18, 16
    /* 1C1D4C 002C1D4C 3F841000 */  dsra32     $16, $16, 16
    /* 1C1D50 002C1D50 40101000 */  sll        $2, $16, 1
    /* 1C1D54 002C1D54 21102202 */  addu       $2, $17, $2
    /* 1C1D58 002C1D58 580F5624 */  addiu      $22, $2, 0xF58
    /* 1C1D5C 002C1D5C 21B83002 */  addu       $23, $17, $16
    /* 1C1D60 002C1D60 6A0FF526 */  addiu      $21, $23, 0xF6A
    /* 1C1D64 002C1D64 580F4284 */  lh         $2, 0xF58($2)
    /* 1C1D68 002C1D68 00008244 */  mtc1       $2, $f0
    /* 1C1D6C 002C1D6C 00000000 */  nop
    /* 1C1D70 002C1D70 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C1D74 002C1D74 00608044 */  mtc1       $0, $f12
    /* 1C1D78 002C1D78 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C1D7C 002C1D7C 00688244 */  mtc1       $2, $f13
    /* 1C1D80 002C1D80 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C1D84 002C1D84 00788244 */  mtc1       $2, $f15
    /* 1C1D88 002C1D88 2D200000 */  daddu      $4, $0, $0
    /* 1C1D8C 002C1D8C A8CA0A0C */  jal        func_002b2aa0
    /* 1C1D90 002C1D90 00000000 */   nop
    /* 1C1D94 002C1D94 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C1D98 002C1D98 00088244 */  mtc1       $2, $f1
    /* 1C1D9C 002C1D9C 00000000 */  nop
    /* 1C1DA0 002C1DA0 36080046 */  c.le.s     $f1, $f0
    /* 1C1DA4 002C1DA4 07000145 */  bc1t       .L002C1DC4
    /* 1C1DA8 002C1DA8 00000000 */   nop
    /* 1C1DAC 002C1DAC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C1DB0 002C1DB0 00000344 */  mfc1       $3, $f0
    /* 1C1DB4 002C1DB4 00000000 */  nop
    /* 1C1DB8 002C1DB8 FF006330 */  andi       $3, $3, 0xFF
    /* 1C1DBC 002C1DBC 07000010 */  b          .L002C1DDC
    /* 1C1DC0 002C1DC0 00000000 */   nop
  .L002C1DC4:
    /* 1C1DC4 002C1DC4 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C1DC8 002C1DC8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C1DCC 002C1DCC 00000344 */  mfc1       $3, $f0
    /* 1C1DD0 002C1DD0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C1DD4 002C1DD4 25186200 */  or         $3, $3, $2
    /* 1C1DD8 002C1DD8 FF006330 */  andi       $3, $3, 0xFF
  .L002C1DDC:
    /* 1C1DDC 002C1DDC 0000A3A2 */  sb         $3, 0x0($21)
    /* 1C1DE0 002C1DE0 0000C486 */  lh         $4, 0x0($22)
    /* 1C1DE4 002C1DE4 01000524 */  addiu      $5, $0, 0x1
    /* 1C1DE8 002C1DE8 06000624 */  addiu      $6, $0, 0x6
    /* 1C1DEC 002C1DEC 2D380000 */  daddu      $7, $0, $0
    /* 1C1DF0 002C1DF0 2D40A000 */  daddu      $8, $5, $0
    /* 1C1DF4 002C1DF4 2CCB0A0C */  jal        func_002b2cb0
    /* 1C1DF8 002C1DF8 00000000 */   nop
    /* 1C1DFC 002C1DFC 0000C2A6 */  sh         $2, 0x0($22)
    /* 1C1E00 002C1E00 EC000424 */  addiu      $4, $0, 0xEC
    /* 1C1E04 002C1E04 7F000524 */  addiu      $5, $0, 0x7F
    /* 1C1E08 002C1E08 2D300000 */  daddu      $6, $0, $0
    /* 1C1E0C 002C1E0C 0000A792 */  lbu        $7, 0x0($21)
    /* 1C1E10 002C1E10 8CCA0A0C */  jal        func_002b2a30
    /* 1C1E14 002C1E14 00000000 */   nop
    /* 1C1E18 002C1E18 2DB04000 */  daddu      $22, $2, $0
    /* 1C1E1C 002C1E1C 08002282 */  lb         $2, 0x8($17)
    /* 1C1E20 002C1E20 08005014 */  bne        $2, $16, .L002C1E44
    /* 1C1E24 002C1E24 00000000 */   nop
    /* 1C1E28 002C1E28 2D000424 */  addiu      $4, $0, 0x2D
    /* 1C1E2C 002C1E2C 2D288000 */  daddu      $5, $4, $0
    /* 1C1E30 002C1E30 2D308000 */  daddu      $6, $4, $0
    /* 1C1E34 002C1E34 0000A792 */  lbu        $7, 0x0($21)
    /* 1C1E38 002C1E38 8CCA0A0C */  jal        func_002b2a30
    /* 1C1E3C 002C1E3C 00000000 */   nop
    /* 1C1E40 002C1E40 2DB04000 */  daddu      $22, $2, $0
  .L002C1E44:
    /* 1C1E44 002C1E44 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1C1E48 002C1E48 00188244 */  mtc1       $2, $f3
    /* 1C1E4C 002C1E4C 00009244 */  mtc1       $18, $f0
    /* 1C1E50 002C1E50 00000000 */  nop
    /* 1C1E54 002C1E54 A0008046 */  cvt.s.w    $f2, $f0
    /* 1C1E58 002C1E58 AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1C1E5C 002C1E5C 00088244 */  mtc1       $2, $f1
    /* 1C1E60 002C1E60 00008044 */  mtc1       $0, $f0
    /* 1C1E64 002C1E64 00000000 */  nop
    /* 1C1E68 002C1E68 18000146 */  adda.s     $f0, $f1
    /* 1C1E6C 002C1E6C 5C1B0246 */  madd.s     $f13, $f3, $f2
    /* 1C1E70 002C1E70 8E42023C */  lui        $2, (0x428E0000 >> 16)
    /* 1C1E74 002C1E74 00608244 */  mtc1       $2, $f12
    /* 1C1E78 002C1E78 7805A427 */  addiu      $4, $29, 0x578
    /* 1C1E7C 002C1E7C 5CCA0A0C */  jal        func_002b2970
    /* 1C1E80 002C1E80 00000000 */   nop
    /* 1C1E84 002C1E84 2D208002 */  daddu      $4, $20, $0
    /* 1C1E88 002C1E88 730FE582 */  lb         $5, 0xF73($23)
    /* 1C1E8C 002C1E8C 7805A6DF */  ld         $6, 0x578($29)
    /* 1C1E90 002C1E90 2D38C002 */  daddu      $7, $22, $0
    /* 1C1E94 002C1E94 20800B0C */  jal        func_002e0080
    /* 1C1E98 002C1E98 00000000 */   nop
  .L002C1E9C:
    /* 1C1E9C 002C1E9C 01004226 */  addiu      $2, $18, 0x1
    /* 1C1EA0 002C1EA0 3C940200 */  dsll32     $18, $2, 16
    /* 1C1EA4 002C1EA4 3F941200 */  dsra32     $18, $18, 16
  .L002C1EA8:
    /* 1C1EA8 002C1EA8 09002582 */  lb         $5, 0x9($17)
    /* 1C1EAC 002C1EAC 3C1C1200 */  dsll32     $3, $18, 16
    /* 1C1EB0 002C1EB0 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C1EB4 002C1EB4 2A106500 */  slt        $2, $3, $5
    /* 1C1EB8 002C1EB8 8FFF4014 */  bnez       $2, .L002C1CF8
    /* 1C1EBC 002C1EBC 00000000 */   nop
    /* 1C1EC0 002C1EC0 3C141300 */  dsll32     $2, $19, 16
    /* 1C1EC4 002C1EC4 3F140200 */  dsra32     $2, $2, 16
    /* 1C1EC8 002C1EC8 17224014 */  bnez       $2, .L002CA728
    /* 1C1ECC 002C1ECC 00000000 */   nop
    /* 1C1ED0 002C1ED0 8C00023C */  lui        $2, %hi(D_008C027A)
    /* 1C1ED4 002C1ED4 7A024394 */  lhu        $3, %lo(D_008C027A)($2)
    /* 1C1ED8 002C1ED8 00406230 */  andi       $2, $3, 0x4000
    /* 1C1EDC 002C1EDC 70004010 */  beqz       $2, .L002C20A0
    /* 1C1EE0 002C1EE0 00000000 */   nop
    /* 1C1EE4 002C1EE4 08002482 */  lb         $4, 0x8($17)
    /* 1C1EE8 002C1EE8 FFFFA624 */  addiu      $6, $5, -0x1
    /* 1C1EEC 002C1EEC 01000524 */  addiu      $5, $0, 0x1
    /* 1C1EF0 002C1EF0 2D380000 */  daddu      $7, $0, $0
    /* 1C1EF4 002C1EF4 02000824 */  addiu      $8, $0, 0x2
    /* 1C1EF8 002C1EF8 2CCB0A0C */  jal        func_002b2cb0
    /* 1C1EFC 002C1EFC 00000000 */   nop
    /* 1C1F00 002C1F00 080022A2 */  sb         $2, 0x8($17)
    /* 1C1F04 002C1F04 2D208002 */  daddu      $4, $20, $0
    /* 1C1F08 002C1F08 F0600B0C */  jal        func_002d83c0
    /* 1C1F0C 002C1F0C 00000000 */   nop
    /* 1C1F10 002C1F10 08002282 */  lb         $2, 0x8($17)
    /* 1C1F14 002C1F14 00008244 */  mtc1       $2, $f0
    /* 1C1F18 002C1F18 00000000 */  nop
    /* 1C1F1C 002C1F1C E0008046 */  cvt.s.w    $f3, $f0
    /* 1C1F20 002C1F20 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1C1F24 002C1F24 00108244 */  mtc1       $2, $f2
    /* 1C1F28 002C1F28 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1C1F2C 002C1F2C 00088244 */  mtc1       $2, $f1
    /* 1C1F30 002C1F30 00008044 */  mtc1       $0, $f0
    /* 1C1F34 002C1F34 00000000 */  nop
    /* 1C1F38 002C1F38 18000146 */  adda.s     $f0, $f1
    /* 1C1F3C 002C1F3C 1C150346 */  madd.s     $f20, $f2, $f3
    /* 1C1F40 002C1F40 D80E248E */  lw         $4, 0xED8($17)
    /* 1C1F44 002C1F44 38810B0C */  jal        func_002e04e0
    /* 1C1F48 002C1F48 00000000 */   nop
    /* 1C1F4C 002C1F4C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C1F50 002C1F50 D40E248E */  lw         $4, 0xED4($17)
    /* 1C1F54 002C1F54 38810B0C */  jal        func_002e04e0
    /* 1C1F58 002C1F58 00000000 */   nop
    /* 1C1F5C 002C1F5C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C1F60 002C1F60 D40E248E */  lw         $4, 0xED4($17)
    /* 1C1F64 002C1F64 38810B0C */  jal        func_002e04e0
    /* 1C1F68 002C1F68 00000000 */   nop
    /* 1C1F6C 002C1F6C 2D804000 */  daddu      $16, $2, $0
    /* 1C1F70 002C1F70 D40E248E */  lw         $4, 0xED4($17)
    /* 1C1F74 002C1F74 38810B0C */  jal        func_002e04e0
    /* 1C1F78 002C1F78 00000000 */   nop
    /* 1C1F7C 002C1F7C 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C1F80 002C1F80 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C1F84 002C1F84 00008244 */  mtc1       $2, $f0
    /* 1C1F88 002C1F88 00000000 */  nop
    /* 1C1F8C 002C1F8C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C1F90 002C1F90 7005A427 */  addiu      $4, $29, 0x570
    /* 1C1F94 002C1F94 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C1F98 002C1F98 5CCA0A0C */  jal        func_002b2970
    /* 1C1F9C 002C1F9C 00000000 */   nop
    /* 1C1FA0 002C1FA0 D40E248E */  lw         $4, 0xED4($17)
    /* 1C1FA4 002C1FA4 38810B0C */  jal        func_002e04e0
    /* 1C1FA8 002C1FA8 00000000 */   nop
    /* 1C1FAC 002C1FAC 2D804000 */  daddu      $16, $2, $0
    /* 1C1FB0 002C1FB0 D40E248E */  lw         $4, 0xED4($17)
    /* 1C1FB4 002C1FB4 38810B0C */  jal        func_002e04e0
    /* 1C1FB8 002C1FB8 00000000 */   nop
    /* 1C1FBC 002C1FBC 6805A427 */  addiu      $4, $29, 0x568
    /* 1C1FC0 002C1FC0 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C1FC4 002C1FC4 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C1FC8 002C1FC8 5CCA0A0C */  jal        func_002b2970
    /* 1C1FCC 002C1FCC 00000000 */   nop
    /* 1C1FD0 002C1FD0 D40E248E */  lw         $4, 0xED4($17)
    /* 1C1FD4 002C1FD4 7005A5DF */  ld         $5, 0x570($29)
    /* 1C1FD8 002C1FD8 6805A6DF */  ld         $6, 0x568($29)
    /* 1C1FDC 002C1FDC 01000724 */  addiu      $7, $0, 0x1
    /* 1C1FE0 002C1FE0 02000824 */  addiu      $8, $0, 0x2
    /* 1C1FE4 002C1FE4 2D480000 */  daddu      $9, $0, $0
    /* 1C1FE8 002C1FE8 88810B0C */  jal        func_002e0620
    /* 1C1FEC 002C1FEC 00000000 */   nop
    /* 1C1FF0 002C1FF0 D80E248E */  lw         $4, 0xED8($17)
    /* 1C1FF4 002C1FF4 38810B0C */  jal        func_002e04e0
    /* 1C1FF8 002C1FF8 00000000 */   nop
    /* 1C1FFC 002C1FFC 2D804000 */  daddu      $16, $2, $0
    /* 1C2000 002C2000 D80E248E */  lw         $4, 0xED8($17)
    /* 1C2004 002C2004 38810B0C */  jal        func_002e04e0
    /* 1C2008 002C2008 00000000 */   nop
    /* 1C200C 002C200C 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C2010 002C2010 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C2014 002C2014 00008244 */  mtc1       $2, $f0
    /* 1C2018 002C2018 00000000 */  nop
    /* 1C201C 002C201C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C2020 002C2020 6005A427 */  addiu      $4, $29, 0x560
    /* 1C2024 002C2024 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C2028 002C2028 5CCA0A0C */  jal        func_002b2970
    /* 1C202C 002C202C 00000000 */   nop
    /* 1C2030 002C2030 D80E248E */  lw         $4, 0xED8($17)
    /* 1C2034 002C2034 38810B0C */  jal        func_002e04e0
    /* 1C2038 002C2038 00000000 */   nop
    /* 1C203C 002C203C 2D804000 */  daddu      $16, $2, $0
    /* 1C2040 002C2040 D80E248E */  lw         $4, 0xED8($17)
    /* 1C2044 002C2044 38810B0C */  jal        func_002e04e0
    /* 1C2048 002C2048 00000000 */   nop
    /* 1C204C 002C204C 5805A427 */  addiu      $4, $29, 0x558
    /* 1C2050 002C2050 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C2054 002C2054 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C2058 002C2058 5CCA0A0C */  jal        func_002b2970
    /* 1C205C 002C205C 00000000 */   nop
    /* 1C2060 002C2060 D80E248E */  lw         $4, 0xED8($17)
    /* 1C2064 002C2064 6005A5DF */  ld         $5, 0x560($29)
    /* 1C2068 002C2068 5805A6DF */  ld         $6, 0x558($29)
    /* 1C206C 002C206C 01000724 */  addiu      $7, $0, 0x1
    /* 1C2070 002C2070 02000824 */  addiu      $8, $0, 0x2
    /* 1C2074 002C2074 2D480000 */  daddu      $9, $0, $0
    /* 1C2078 002C2078 88810B0C */  jal        func_002e0620
    /* 1C207C 002C207C 00000000 */   nop
    /* 1C2080 002C2080 2D200000 */  daddu      $4, $0, $0
    /* 1C2084 002C2084 2D280000 */  daddu      $5, $0, $0
    /* 1C2088 002C2088 2D300000 */  daddu      $6, $0, $0
    /* 1C208C 002C208C 2D380000 */  daddu      $7, $0, $0
    /* 1C2090 002C2090 D86B110C */  jal        func_0045af60
    /* 1C2094 002C2094 00000000 */   nop
    /* 1C2098 002C2098 A3210010 */  b          .L002CA728
    /* 1C209C 002C209C 00000000 */   nop
  .L002C20A0:
    /* 1C20A0 002C20A0 00106230 */  andi       $2, $3, 0x1000
    /* 1C20A4 002C20A4 70004010 */  beqz       $2, .L002C2268
    /* 1C20A8 002C20A8 00000000 */   nop
    /* 1C20AC 002C20AC 08002482 */  lb         $4, 0x8($17)
    /* 1C20B0 002C20B0 FFFFA724 */  addiu      $7, $5, -0x1
    /* 1C20B4 002C20B4 01000524 */  addiu      $5, $0, 0x1
    /* 1C20B8 002C20B8 2D300000 */  daddu      $6, $0, $0
    /* 1C20BC 002C20BC 02000824 */  addiu      $8, $0, 0x2
    /* 1C20C0 002C20C0 40CB0A0C */  jal        func_002b2d00
    /* 1C20C4 002C20C4 00000000 */   nop
    /* 1C20C8 002C20C8 080022A2 */  sb         $2, 0x8($17)
    /* 1C20CC 002C20CC 2D208002 */  daddu      $4, $20, $0
    /* 1C20D0 002C20D0 F0600B0C */  jal        func_002d83c0
    /* 1C20D4 002C20D4 00000000 */   nop
    /* 1C20D8 002C20D8 08002282 */  lb         $2, 0x8($17)
    /* 1C20DC 002C20DC 00008244 */  mtc1       $2, $f0
    /* 1C20E0 002C20E0 00000000 */  nop
    /* 1C20E4 002C20E4 E0008046 */  cvt.s.w    $f3, $f0
    /* 1C20E8 002C20E8 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1C20EC 002C20EC 00108244 */  mtc1       $2, $f2
    /* 1C20F0 002C20F0 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1C20F4 002C20F4 00088244 */  mtc1       $2, $f1
    /* 1C20F8 002C20F8 00008044 */  mtc1       $0, $f0
    /* 1C20FC 002C20FC 00000000 */  nop
    /* 1C2100 002C2100 18000146 */  adda.s     $f0, $f1
    /* 1C2104 002C2104 1C150346 */  madd.s     $f20, $f2, $f3
    /* 1C2108 002C2108 D80E248E */  lw         $4, 0xED8($17)
    /* 1C210C 002C210C 38810B0C */  jal        func_002e04e0
    /* 1C2110 002C2110 00000000 */   nop
    /* 1C2114 002C2114 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C2118 002C2118 D40E248E */  lw         $4, 0xED4($17)
    /* 1C211C 002C211C 38810B0C */  jal        func_002e04e0
    /* 1C2120 002C2120 00000000 */   nop
    /* 1C2124 002C2124 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C2128 002C2128 D40E248E */  lw         $4, 0xED4($17)
    /* 1C212C 002C212C 38810B0C */  jal        func_002e04e0
    /* 1C2130 002C2130 00000000 */   nop
    /* 1C2134 002C2134 2D804000 */  daddu      $16, $2, $0
    /* 1C2138 002C2138 D40E248E */  lw         $4, 0xED4($17)
    /* 1C213C 002C213C 38810B0C */  jal        func_002e04e0
    /* 1C2140 002C2140 00000000 */   nop
    /* 1C2144 002C2144 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C2148 002C2148 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C214C 002C214C 00008244 */  mtc1       $2, $f0
    /* 1C2150 002C2150 00000000 */  nop
    /* 1C2154 002C2154 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C2158 002C2158 5005A427 */  addiu      $4, $29, 0x550
    /* 1C215C 002C215C 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C2160 002C2160 5CCA0A0C */  jal        func_002b2970
    /* 1C2164 002C2164 00000000 */   nop
    /* 1C2168 002C2168 D40E248E */  lw         $4, 0xED4($17)
    /* 1C216C 002C216C 38810B0C */  jal        func_002e04e0
    /* 1C2170 002C2170 00000000 */   nop
    /* 1C2174 002C2174 2D804000 */  daddu      $16, $2, $0
    /* 1C2178 002C2178 D40E248E */  lw         $4, 0xED4($17)
    /* 1C217C 002C217C 38810B0C */  jal        func_002e04e0
    /* 1C2180 002C2180 00000000 */   nop
    /* 1C2184 002C2184 4805A427 */  addiu      $4, $29, 0x548
    /* 1C2188 002C2188 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C218C 002C218C 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C2190 002C2190 5CCA0A0C */  jal        func_002b2970
    /* 1C2194 002C2194 00000000 */   nop
    /* 1C2198 002C2198 D40E248E */  lw         $4, 0xED4($17)
    /* 1C219C 002C219C 5005A5DF */  ld         $5, 0x550($29)
    /* 1C21A0 002C21A0 4805A6DF */  ld         $6, 0x548($29)
    /* 1C21A4 002C21A4 01000724 */  addiu      $7, $0, 0x1
    /* 1C21A8 002C21A8 02000824 */  addiu      $8, $0, 0x2
    /* 1C21AC 002C21AC 2D480000 */  daddu      $9, $0, $0
    /* 1C21B0 002C21B0 88810B0C */  jal        func_002e0620
    /* 1C21B4 002C21B4 00000000 */   nop
    /* 1C21B8 002C21B8 D80E248E */  lw         $4, 0xED8($17)
    /* 1C21BC 002C21BC 38810B0C */  jal        func_002e04e0
    /* 1C21C0 002C21C0 00000000 */   nop
    /* 1C21C4 002C21C4 2D804000 */  daddu      $16, $2, $0
    /* 1C21C8 002C21C8 D80E248E */  lw         $4, 0xED8($17)
    /* 1C21CC 002C21CC 38810B0C */  jal        func_002e04e0
    /* 1C21D0 002C21D0 00000000 */   nop
    /* 1C21D4 002C21D4 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1C21D8 002C21D8 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 1C21DC 002C21DC 00008244 */  mtc1       $2, $f0
    /* 1C21E0 002C21E0 00000000 */  nop
    /* 1C21E4 002C21E4 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C21E8 002C21E8 4005A427 */  addiu      $4, $29, 0x540
    /* 1C21EC 002C21EC 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C21F0 002C21F0 5CCA0A0C */  jal        func_002b2970
    /* 1C21F4 002C21F4 00000000 */   nop
    /* 1C21F8 002C21F8 D80E248E */  lw         $4, 0xED8($17)
    /* 1C21FC 002C21FC 38810B0C */  jal        func_002e04e0
    /* 1C2200 002C2200 00000000 */   nop
    /* 1C2204 002C2204 2D804000 */  daddu      $16, $2, $0
    /* 1C2208 002C2208 D80E248E */  lw         $4, 0xED8($17)
    /* 1C220C 002C220C 38810B0C */  jal        func_002e04e0
    /* 1C2210 002C2210 00000000 */   nop
    /* 1C2214 002C2214 3805A427 */  addiu      $4, $29, 0x538
    /* 1C2218 002C2218 2C000CC6 */  lwc1       $f12, 0x2C($16)
    /* 1C221C 002C221C 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C2220 002C2220 5CCA0A0C */  jal        func_002b2970
    /* 1C2224 002C2224 00000000 */   nop
    /* 1C2228 002C2228 D80E248E */  lw         $4, 0xED8($17)
    /* 1C222C 002C222C 4005A5DF */  ld         $5, 0x540($29)
    /* 1C2230 002C2230 3805A6DF */  ld         $6, 0x538($29)
    /* 1C2234 002C2234 01000724 */  addiu      $7, $0, 0x1
    /* 1C2238 002C2238 02000824 */  addiu      $8, $0, 0x2
    /* 1C223C 002C223C 2D480000 */  daddu      $9, $0, $0
    /* 1C2240 002C2240 88810B0C */  jal        func_002e0620
    /* 1C2244 002C2244 00000000 */   nop
    /* 1C2248 002C2248 2D200000 */  daddu      $4, $0, $0
    /* 1C224C 002C224C 2D280000 */  daddu      $5, $0, $0
    /* 1C2250 002C2250 2D300000 */  daddu      $6, $0, $0
    /* 1C2254 002C2254 2D380000 */  daddu      $7, $0, $0
    /* 1C2258 002C2258 D86B110C */  jal        func_0045af60
    /* 1C225C 002C225C 00000000 */   nop
    /* 1C2260 002C2260 31210010 */  b          .L002CA728
    /* 1C2264 002C2264 00000000 */   nop
  .L002C2268:
    /* 1C2268 002C2268 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 1C226C 002C226C 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 1C2270 002C2270 20006230 */  andi       $2, $3, 0x20
    /* 1C2274 002C2274 62024010 */  beqz       $2, .L002C2C00
    /* 1C2278 002C2278 00000000 */   nop
    /* 1C227C 002C227C 2D200000 */  daddu      $4, $0, $0
    /* 1C2280 002C2280 2D280000 */  daddu      $5, $0, $0
    /* 1C2284 002C2284 2D300000 */  daddu      $6, $0, $0
    /* 1C2288 002C2288 02000724 */  addiu      $7, $0, 0x2
    /* 1C228C 002C228C D86B110C */  jal        func_0045af60
    /* 1C2290 002C2290 00000000 */   nop
    /* 1C2294 002C2294 6400103C */  lui        $16, %hi(D_0063F5A0)
    /* 1C2298 002C2298 A0F51026 */  addiu      $16, $16, %lo(D_0063F5A0)
    /* 1C229C 002C229C 3005A427 */  addiu      $4, $29, 0x530
    /* 1C22A0 002C22A0 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C22A4 002C22A4 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C22A8 002C22A8 5CCA0A0C */  jal        func_002b2970
    /* 1C22AC 002C22AC 00000000 */   nop
    /* 1C22B0 002C22B0 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C22B4 002C22B4 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1C22B8 002C22B8 00008244 */  mtc1       $2, $f0
    /* 1C22BC 002C22BC 00000000 */  nop
    /* 1C22C0 002C22C0 40030146 */  add.s      $f13, $f0, $f1
    /* 1C22C4 002C22C4 2805A427 */  addiu      $4, $29, 0x528
    /* 1C22C8 002C22C8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C22CC 002C22CC 5CCA0A0C */  jal        func_002b2970
    /* 1C22D0 002C22D0 00000000 */   nop
    /* 1C22D4 002C22D4 580C248E */  lw         $4, 0xC58($17)
    /* 1C22D8 002C22D8 3005A5DF */  ld         $5, 0x530($29)
    /* 1C22DC 002C22DC 2805A6DF */  ld         $6, 0x528($29)
    /* 1C22E0 002C22E0 2D380000 */  daddu      $7, $0, $0
    /* 1C22E4 002C22E4 04000824 */  addiu      $8, $0, 0x4
    /* 1C22E8 002C22E8 2D480000 */  daddu      $9, $0, $0
    /* 1C22EC 002C22EC 88810B0C */  jal        func_002e0620
    /* 1C22F0 002C22F0 00000000 */   nop
    /* 1C22F4 002C22F4 580C248E */  lw         $4, 0xC58($17)
    /* 1C22F8 002C22F8 CC000524 */  addiu      $5, $0, 0xCC
    /* 1C22FC 002C22FC 2D300000 */  daddu      $6, $0, $0
    /* 1C2300 002C2300 2D380000 */  daddu      $7, $0, $0
    /* 1C2304 002C2304 02000824 */  addiu      $8, $0, 0x2
    /* 1C2308 002C2308 2D480000 */  daddu      $9, $0, $0
    /* 1C230C 002C230C 98810B0C */  jal        func_002e0660
    /* 1C2310 002C2310 00000000 */   nop
    /* 1C2314 002C2314 6400103C */  lui        $16, %hi(D_0063F5A8)
    /* 1C2318 002C2318 A8F51026 */  addiu      $16, $16, %lo(D_0063F5A8)
    /* 1C231C 002C231C 2005A427 */  addiu      $4, $29, 0x520
    /* 1C2320 002C2320 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C2324 002C2324 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C2328 002C2328 5CCA0A0C */  jal        func_002b2970
    /* 1C232C 002C232C 00000000 */   nop
    /* 1C2330 002C2330 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C2334 002C2334 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1C2338 002C2338 00008244 */  mtc1       $2, $f0
    /* 1C233C 002C233C 00000000 */  nop
    /* 1C2340 002C2340 40030146 */  add.s      $f13, $f0, $f1
    /* 1C2344 002C2344 1805A427 */  addiu      $4, $29, 0x518
    /* 1C2348 002C2348 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C234C 002C234C 5CCA0A0C */  jal        func_002b2970
    /* 1C2350 002C2350 00000000 */   nop
    /* 1C2354 002C2354 5C0C248E */  lw         $4, 0xC5C($17)
    /* 1C2358 002C2358 2005A5DF */  ld         $5, 0x520($29)
    /* 1C235C 002C235C 1805A6DF */  ld         $6, 0x518($29)
    /* 1C2360 002C2360 2D380000 */  daddu      $7, $0, $0
    /* 1C2364 002C2364 04000824 */  addiu      $8, $0, 0x4
    /* 1C2368 002C2368 2D480000 */  daddu      $9, $0, $0
    /* 1C236C 002C236C 88810B0C */  jal        func_002e0620
    /* 1C2370 002C2370 00000000 */   nop
    /* 1C2374 002C2374 5C0C248E */  lw         $4, 0xC5C($17)
    /* 1C2378 002C2378 CC000524 */  addiu      $5, $0, 0xCC
    /* 1C237C 002C237C 2D300000 */  daddu      $6, $0, $0
    /* 1C2380 002C2380 2D380000 */  daddu      $7, $0, $0
    /* 1C2384 002C2384 02000824 */  addiu      $8, $0, 0x2
    /* 1C2388 002C2388 2D480000 */  daddu      $9, $0, $0
    /* 1C238C 002C238C 98810B0C */  jal        func_002e0660
    /* 1C2390 002C2390 00000000 */   nop
    /* 1C2394 002C2394 6400103C */  lui        $16, %hi(D_0063F7B0)
    /* 1C2398 002C2398 B0F71026 */  addiu      $16, $16, %lo(D_0063F7B0)
    /* 1C239C 002C239C 1005A427 */  addiu      $4, $29, 0x510
    /* 1C23A0 002C23A0 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C23A4 002C23A4 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C23A8 002C23A8 5CCA0A0C */  jal        func_002b2970
    /* 1C23AC 002C23AC 00000000 */   nop
    /* 1C23B0 002C23B0 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C23B4 002C23B4 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 1C23B8 002C23B8 00008244 */  mtc1       $2, $f0
    /* 1C23BC 002C23BC 00000000 */  nop
    /* 1C23C0 002C23C0 40030146 */  add.s      $f13, $f0, $f1
    /* 1C23C4 002C23C4 0805A427 */  addiu      $4, $29, 0x508
    /* 1C23C8 002C23C8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C23CC 002C23CC 5CCA0A0C */  jal        func_002b2970
    /* 1C23D0 002C23D0 00000000 */   nop
    /* 1C23D4 002C23D4 600D248E */  lw         $4, 0xD60($17)
    /* 1C23D8 002C23D8 1005A5DF */  ld         $5, 0x510($29)
    /* 1C23DC 002C23DC 0805A6DF */  ld         $6, 0x508($29)
    /* 1C23E0 002C23E0 02000724 */  addiu      $7, $0, 0x2
    /* 1C23E4 002C23E4 04000824 */  addiu      $8, $0, 0x4
    /* 1C23E8 002C23E8 2D480000 */  daddu      $9, $0, $0
    /* 1C23EC 002C23EC 88810B0C */  jal        func_002e0620
    /* 1C23F0 002C23F0 00000000 */   nop
    /* 1C23F4 002C23F4 6400103C */  lui        $16, %hi(D_0063F7B8)
    /* 1C23F8 002C23F8 B8F71026 */  addiu      $16, $16, %lo(D_0063F7B8)
    /* 1C23FC 002C23FC 0005A427 */  addiu      $4, $29, 0x500
    /* 1C2400 002C2400 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C2404 002C2404 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C2408 002C2408 5CCA0A0C */  jal        func_002b2970
    /* 1C240C 002C240C 00000000 */   nop
    /* 1C2410 002C2410 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C2414 002C2414 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 1C2418 002C2418 00008244 */  mtc1       $2, $f0
    /* 1C241C 002C241C 00000000 */  nop
    /* 1C2420 002C2420 40030146 */  add.s      $f13, $f0, $f1
    /* 1C2424 002C2424 F804A427 */  addiu      $4, $29, 0x4F8
    /* 1C2428 002C2428 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C242C 002C242C 5CCA0A0C */  jal        func_002b2970
    /* 1C2430 002C2430 00000000 */   nop
    /* 1C2434 002C2434 640D248E */  lw         $4, 0xD64($17)
    /* 1C2438 002C2438 0005A5DF */  ld         $5, 0x500($29)
    /* 1C243C 002C243C F804A6DF */  ld         $6, 0x4F8($29)
    /* 1C2440 002C2440 02000724 */  addiu      $7, $0, 0x2
    /* 1C2444 002C2444 04000824 */  addiu      $8, $0, 0x4
    /* 1C2448 002C2448 2D480000 */  daddu      $9, $0, $0
    /* 1C244C 002C244C 88810B0C */  jal        func_002e0620
    /* 1C2450 002C2450 00000000 */   nop
    /* 1C2454 002C2454 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C2458 002C2458 2D280000 */  daddu      $5, $0, $0
    /* 1C245C 002C245C 01000624 */  addiu      $6, $0, 0x1
    /* 1C2460 002C2460 3C810B0C */  jal        func_002e04f0
    /* 1C2464 002C2464 00000000 */   nop
    /* 1C2468 002C2468 F00D248E */  lw         $4, 0xDF0($17)
    /* 1C246C 002C246C 2D280000 */  daddu      $5, $0, $0
    /* 1C2470 002C2470 01000624 */  addiu      $6, $0, 0x1
    /* 1C2474 002C2474 3C810B0C */  jal        func_002e04f0
    /* 1C2478 002C2478 00000000 */   nop
    /* 1C247C 002C247C 3C0D248E */  lw         $4, 0xD3C($17)
    /* 1C2480 002C2480 2D280000 */  daddu      $5, $0, $0
    /* 1C2484 002C2484 01000624 */  addiu      $6, $0, 0x1
    /* 1C2488 002C2488 3C810B0C */  jal        func_002e04f0
    /* 1C248C 002C248C 00000000 */   nop
    /* 1C2490 002C2490 2D980000 */  daddu      $19, $0, $0
    /* 1C2494 002C2494 20000010 */  b          .L002C2518
    /* 1C2498 002C2498 00000000 */   nop
  .L002C249C:
    /* 1C249C 002C249C 3C941300 */  dsll32     $18, $19, 16
    /* 1C24A0 002C24A0 3F941200 */  dsra32     $18, $18, 16
    /* 1C24A4 002C24A4 43004226 */  addiu      $2, $18, 0x43
    /* 1C24A8 002C24A8 C0180200 */  sll        $3, $2, 3
    /* 1C24AC 002C24AC 6400023C */  lui        $2, %hi(D_0063F560)
    /* 1C24B0 002C24B0 60F54224 */  addiu      $2, $2, %lo(D_0063F560)
    /* 1C24B4 002C24B4 21804300 */  addu       $16, $2, $3
    /* 1C24B8 002C24B8 F004A427 */  addiu      $4, $29, 0x4F0
    /* 1C24BC 002C24BC 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C24C0 002C24C0 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C24C4 002C24C4 5CCA0A0C */  jal        func_002b2970
    /* 1C24C8 002C24C8 00000000 */   nop
    /* 1C24CC 002C24CC 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C24D0 002C24D0 00688244 */  mtc1       $2, $f13
    /* 1C24D4 002C24D4 E804A427 */  addiu      $4, $29, 0x4E8
    /* 1C24D8 002C24D8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C24DC 002C24DC 5CCA0A0C */  jal        func_002b2970
    /* 1C24E0 002C24E0 00000000 */   nop
    /* 1C24E4 002C24E4 80101200 */  sll        $2, $18, 2
    /* 1C24E8 002C24E8 21102202 */  addu       $2, $17, $2
    /* 1C24EC 002C24EC 440D448C */  lw         $4, 0xD44($2)
    /* 1C24F0 002C24F0 F004A5DF */  ld         $5, 0x4F0($29)
    /* 1C24F4 002C24F4 E804A6DF */  ld         $6, 0x4E8($29)
    /* 1C24F8 002C24F8 02000724 */  addiu      $7, $0, 0x2
    /* 1C24FC 002C24FC 05000824 */  addiu      $8, $0, 0x5
    /* 1C2500 002C2500 2D480000 */  daddu      $9, $0, $0
    /* 1C2504 002C2504 88810B0C */  jal        func_002e0620
    /* 1C2508 002C2508 00000000 */   nop
    /* 1C250C 002C250C 01006226 */  addiu      $2, $19, 0x1
    /* 1C2510 002C2510 3C9C0200 */  dsll32     $19, $2, 16
    /* 1C2514 002C2514 3F9C1300 */  dsra32     $19, $19, 16
  .L002C2518:
    /* 1C2518 002C2518 3C141300 */  dsll32     $2, $19, 16
    /* 1C251C 002C251C 3F140200 */  dsra32     $2, $2, 16
    /* 1C2520 002C2520 06004228 */  slti       $2, $2, 0x6
    /* 1C2524 002C2524 DDFF4014 */  bnez       $2, .L002C249C
    /* 1C2528 002C2528 00000000 */   nop
    /* 1C252C 002C252C D40E248E */  lw         $4, 0xED4($17)
    /* 1C2530 002C2530 2D280000 */  daddu      $5, $0, $0
    /* 1C2534 002C2534 01000624 */  addiu      $6, $0, 0x1
    /* 1C2538 002C2538 3C810B0C */  jal        func_002e04f0
    /* 1C253C 002C253C 00000000 */   nop
    /* 1C2540 002C2540 D80E248E */  lw         $4, 0xED8($17)
    /* 1C2544 002C2544 2D280000 */  daddu      $5, $0, $0
    /* 1C2548 002C2548 01000624 */  addiu      $6, $0, 0x1
    /* 1C254C 002C254C 3C810B0C */  jal        func_002e04f0
    /* 1C2550 002C2550 00000000 */   nop
    /* 1C2554 002C2554 2D208002 */  daddu      $4, $20, $0
    /* 1C2558 002C2558 8C740B0C */  jal        func_002dd230
    /* 1C255C 002C255C 00000000 */   nop
    /* 1C2560 002C2560 2D800000 */  daddu      $16, $0, $0
    /* 1C2564 002C2564 0B000010 */  b          .L002C2594
    /* 1C2568 002C2568 00000000 */   nop
  .L002C256C:
    /* 1C256C 002C256C 80100300 */  sll        $2, $3, 2
    /* 1C2570 002C2570 21102202 */  addu       $2, $17, $2
    /* 1C2574 002C2574 200D448C */  lw         $4, 0xD20($2)
    /* 1C2578 002C2578 2D280000 */  daddu      $5, $0, $0
    /* 1C257C 002C257C 2D300000 */  daddu      $6, $0, $0
    /* 1C2580 002C2580 3C810B0C */  jal        func_002e04f0
    /* 1C2584 002C2584 00000000 */   nop
    /* 1C2588 002C2588 01000226 */  addiu      $2, $16, 0x1
    /* 1C258C 002C258C 3C840200 */  dsll32     $16, $2, 16
    /* 1C2590 002C2590 3F841000 */  dsra32     $16, $16, 16
  .L002C2594:
    /* 1C2594 002C2594 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C2598 002C2598 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C259C 002C259C 07006228 */  slti       $2, $3, 0x7
    /* 1C25A0 002C25A0 F2FF4014 */  bnez       $2, .L002C256C
    /* 1C25A4 002C25A4 00000000 */   nop
    /* 1C25A8 002C25A8 440C248E */  lw         $4, 0xC44($17)
    /* 1C25AC 002C25AC 2D280000 */  daddu      $5, $0, $0
    /* 1C25B0 002C25B0 2D300000 */  daddu      $6, $0, $0
    /* 1C25B4 002C25B4 3C810B0C */  jal        func_002e04f0
    /* 1C25B8 002C25B8 00000000 */   nop
    /* 1C25BC 002C25BC 480C248E */  lw         $4, 0xC48($17)
    /* 1C25C0 002C25C0 2D280000 */  daddu      $5, $0, $0
    /* 1C25C4 002C25C4 2D300000 */  daddu      $6, $0, $0
    /* 1C25C8 002C25C8 3C810B0C */  jal        func_002e04f0
    /* 1C25CC 002C25CC 00000000 */   nop
    /* 1C25D0 002C25D0 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1C25D4 002C25D4 00608244 */  mtc1       $2, $f12
    /* 1C25D8 002C25D8 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C25DC 002C25DC 41000524 */  addiu      $5, $0, 0x41
    /* 1C25E0 002C25E0 78820B0C */  jal        func_002e09e0
    /* 1C25E4 002C25E4 00000000 */   nop
    /* 1C25E8 002C25E8 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C25EC 002C25EC 2D280000 */  daddu      $5, $0, $0
    /* 1C25F0 002C25F0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C25F4 002C25F4 2D380000 */  daddu      $7, $0, $0
    /* 1C25F8 002C25F8 06000824 */  addiu      $8, $0, 0x6
    /* 1C25FC 002C25FC 2D480000 */  daddu      $9, $0, $0
    /* 1C2600 002C2600 98810B0C */  jal        func_002e0660
    /* 1C2604 002C2604 00000000 */   nop
    /* 1C2608 002C2608 4643023C */  lui        $2, (0x43460000 >> 16)
    /* 1C260C 002C260C 00A08244 */  mtc1       $2, $f20
    /* 1C2610 002C2610 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C2614 002C2614 38810B0C */  jal        func_002e04e0
    /* 1C2618 002C2618 00000000 */   nop
    /* 1C261C 002C261C 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C2620 002C2620 51010224 */  addiu      $2, $0, 0x151
    /* 1C2624 002C2624 00008244 */  mtc1       $2, $f0
    /* 1C2628 002C2628 00000000 */  nop
    /* 1C262C 002C262C 20058046 */  cvt.s.w    $f20, $f0
    /* 1C2630 002C2630 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C2634 002C2634 38810B0C */  jal        func_002e04e0
    /* 1C2638 002C2638 00000000 */   nop
    /* 1C263C 002C263C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C2640 002C2640 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1C2644 002C2644 00608244 */  mtc1       $2, $f12
    /* 1C2648 002C2648 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1C264C 002C264C 41000524 */  addiu      $5, $0, 0x41
    /* 1C2650 002C2650 78820B0C */  jal        func_002e09e0
    /* 1C2654 002C2654 00000000 */   nop
    /* 1C2658 002C2658 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1C265C 002C265C 2D280000 */  daddu      $5, $0, $0
    /* 1C2660 002C2660 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C2664 002C2664 2D380000 */  daddu      $7, $0, $0
    /* 1C2668 002C2668 06000824 */  addiu      $8, $0, 0x6
    /* 1C266C 002C266C 2D480000 */  daddu      $9, $0, $0
    /* 1C2670 002C2670 98810B0C */  jal        func_002e0660
    /* 1C2674 002C2674 00000000 */   nop
    /* 1C2678 002C2678 5843023C */  lui        $2, (0x43580000 >> 16)
    /* 1C267C 002C267C 00A08244 */  mtc1       $2, $f20
    /* 1C2680 002C2680 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1C2684 002C2684 38810B0C */  jal        func_002e04e0
    /* 1C2688 002C2688 00000000 */   nop
    /* 1C268C 002C268C 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C2690 002C2690 B843023C */  lui        $2, (0x43B80000 >> 16)
    /* 1C2694 002C2694 00A08244 */  mtc1       $2, $f20
    /* 1C2698 002C2698 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1C269C 002C269C 38810B0C */  jal        func_002e04e0
    /* 1C26A0 002C26A0 00000000 */   nop
    /* 1C26A4 002C26A4 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C26A8 002C26A8 3F43023C */  lui        $2, (0x433F0000 >> 16)
    /* 1C26AC 002C26AC 00608244 */  mtc1       $2, $f12
    /* 1C26B0 002C26B0 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C26B4 002C26B4 40000524 */  addiu      $5, $0, 0x40
    /* 1C26B8 002C26B8 78820B0C */  jal        func_002e09e0
    /* 1C26BC 002C26BC 00000000 */   nop
    /* 1C26C0 002C26C0 280F248E */  lw         $4, 0xF28($17)
    /* 1C26C4 002C26C4 05000524 */  addiu      $5, $0, 0x5
    /* 1C26C8 002C26C8 80B4110C */  jal        func_0046d200
    /* 1C26CC 002C26CC 00000000 */   nop
    /* 1C26D0 002C26D0 2D804000 */  daddu      $16, $2, $0
    /* 1C26D4 002C26D4 2D200002 */  daddu      $4, $16, $0
    /* 1C26D8 002C26D8 98AC110C */  jal        func_0046b260
    /* 1C26DC 002C26DC 00000000 */   nop
    /* 1C26E0 002C26E0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C26E4 002C26E4 00000244 */  mfc1       $2, $f0
    /* 1C26E8 002C26E8 00000000 */  nop
    /* 1C26EC 002C26EC 3C940200 */  dsll32     $18, $2, 16
    /* 1C26F0 002C26F0 3F941200 */  dsra32     $18, $18, 16
    /* 1C26F4 002C26F4 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C26F8 002C26F8 38810B0C */  jal        func_002e04e0
    /* 1C26FC 002C26FC 00000000 */   nop
    /* 1C2700 002C2700 000152A4 */  sh         $18, 0x100($2)
    /* 1C2704 002C2704 2D200002 */  daddu      $4, $16, $0
    /* 1C2708 002C2708 BCAC110C */  jal        func_0046b2f0
    /* 1C270C 002C270C 00000000 */   nop
    /* 1C2710 002C2710 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C2714 002C2714 00000244 */  mfc1       $2, $f0
    /* 1C2718 002C2718 00000000 */  nop
    /* 1C271C 002C271C 3C940200 */  dsll32     $18, $2, 16
    /* 1C2720 002C2720 3F941200 */  dsra32     $18, $18, 16
    /* 1C2724 002C2724 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C2728 002C2728 38810B0C */  jal        func_002e04e0
    /* 1C272C 002C272C 00000000 */   nop
    /* 1C2730 002C2730 020152A4 */  sh         $18, 0x102($2)
    /* 1C2734 002C2734 2D200002 */  daddu      $4, $16, $0
    /* 1C2738 002C2738 A0B4110C */  jal        func_0046d280
    /* 1C273C 002C273C 00000000 */   nop
    /* 1C2740 002C2740 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C2744 002C2744 2D280000 */  daddu      $5, $0, $0
    /* 1C2748 002C2748 CC000624 */  addiu      $6, $0, 0xCC
    /* 1C274C 002C274C 2D380000 */  daddu      $7, $0, $0
    /* 1C2750 002C2750 04000824 */  addiu      $8, $0, 0x4
    /* 1C2754 002C2754 2D480001 */  daddu      $9, $8, $0
    /* 1C2758 002C2758 98810B0C */  jal        func_002e0660
    /* 1C275C 002C275C 00000000 */   nop
    /* 1C2760 002C2760 00608044 */  mtc1       $0, $f12
    /* 1C2764 002C2764 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C2768 002C2768 20858DC7 */  lwc1       $f13, -0x7AE0($28)
    /* 1C276C 002C276C 2D280000 */  daddu      $5, $0, $0
    /* 1C2770 002C2770 04000624 */  addiu      $6, $0, 0x4
    /* 1C2774 002C2774 2D38C000 */  daddu      $7, $6, $0
    /* 1C2778 002C2778 50820B0C */  jal        func_002e0940
    /* 1C277C 002C277C 00000000 */   nop
    /* 1C2780 002C2780 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1C2784 002C2784 00608244 */  mtc1       $2, $f12
    /* 1C2788 002C2788 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 1C278C 002C278C 00688244 */  mtc1       $2, $f13
    /* 1C2790 002C2790 E004A427 */  addiu      $4, $29, 0x4E0
    /* 1C2794 002C2794 5CCA0A0C */  jal        func_002b2970
    /* 1C2798 002C2798 00000000 */   nop
    /* 1C279C 002C279C 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1C27A0 002C27A0 00608244 */  mtc1       $2, $f12
    /* 1C27A4 002C27A4 9B43023C */  lui        $2, (0x439B0000 >> 16)
    /* 1C27A8 002C27A8 00688244 */  mtc1       $2, $f13
    /* 1C27AC 002C27AC D804A427 */  addiu      $4, $29, 0x4D8
    /* 1C27B0 002C27B0 5CCA0A0C */  jal        func_002b2970
    /* 1C27B4 002C27B4 00000000 */   nop
    /* 1C27B8 002C27B8 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C27BC 002C27BC E004A5DF */  ld         $5, 0x4E0($29)
    /* 1C27C0 002C27C0 D804A6DF */  ld         $6, 0x4D8($29)
    /* 1C27C4 002C27C4 2D380000 */  daddu      $7, $0, $0
    /* 1C27C8 002C27C8 04000824 */  addiu      $8, $0, 0x4
    /* 1C27CC 002C27CC 2D480001 */  daddu      $9, $8, $0
    /* 1C27D0 002C27D0 88810B0C */  jal        func_002e0620
    /* 1C27D4 002C27D4 00000000 */   nop
    /* 1C27D8 002C27D8 4043023C */  lui        $2, (0x43400000 >> 16)
    /* 1C27DC 002C27DC 00608244 */  mtc1       $2, $f12
    /* 1C27E0 002C27E0 500C248E */  lw         $4, 0xC50($17)
    /* 1C27E4 002C27E4 40000524 */  addiu      $5, $0, 0x40
    /* 1C27E8 002C27E8 78820B0C */  jal        func_002e09e0
    /* 1C27EC 002C27EC 00000000 */   nop
    /* 1C27F0 002C27F0 DC42023C */  lui        $2, (0x42DC0000 >> 16)
    /* 1C27F4 002C27F4 00A08244 */  mtc1       $2, $f20
    /* 1C27F8 002C27F8 500C248E */  lw         $4, 0xC50($17)
    /* 1C27FC 002C27FC 38810B0C */  jal        func_002e04e0
    /* 1C2800 002C2800 00000000 */   nop
    /* 1C2804 002C2804 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C2808 002C2808 48C2023C */  lui        $2, (0xC2480000 >> 16)
    /* 1C280C 002C280C 00A08244 */  mtc1       $2, $f20
    /* 1C2810 002C2810 500C248E */  lw         $4, 0xC50($17)
    /* 1C2814 002C2814 38810B0C */  jal        func_002e04e0
    /* 1C2818 002C2818 00000000 */   nop
    /* 1C281C 002C281C 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C2820 002C2820 280F248E */  lw         $4, 0xF28($17)
    /* 1C2824 002C2824 06000524 */  addiu      $5, $0, 0x6
    /* 1C2828 002C2828 80B4110C */  jal        func_0046d200
    /* 1C282C 002C282C 00000000 */   nop
    /* 1C2830 002C2830 2D804000 */  daddu      $16, $2, $0
    /* 1C2834 002C2834 2D200002 */  daddu      $4, $16, $0
    /* 1C2838 002C2838 98AC110C */  jal        func_0046b260
    /* 1C283C 002C283C 00000000 */   nop
    /* 1C2840 002C2840 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C2844 002C2844 00000244 */  mfc1       $2, $f0
    /* 1C2848 002C2848 00000000 */  nop
    /* 1C284C 002C284C 3C940200 */  dsll32     $18, $2, 16
    /* 1C2850 002C2850 3F941200 */  dsra32     $18, $18, 16
    /* 1C2854 002C2854 500C248E */  lw         $4, 0xC50($17)
    /* 1C2858 002C2858 38810B0C */  jal        func_002e04e0
    /* 1C285C 002C285C 00000000 */   nop
    /* 1C2860 002C2860 000152A4 */  sh         $18, 0x100($2)
    /* 1C2864 002C2864 500C248E */  lw         $4, 0xC50($17)
    /* 1C2868 002C2868 38810B0C */  jal        func_002e04e0
    /* 1C286C 002C286C 00000000 */   nop
    /* 1C2870 002C2870 020140A4 */  sh         $0, 0x102($2)
    /* 1C2874 002C2874 B4C2023C */  lui        $2, (0xC2B40000 >> 16)
    /* 1C2878 002C2878 00608244 */  mtc1       $2, $f12
    /* 1C287C 002C287C 500C248E */  lw         $4, 0xC50($17)
    /* 1C2880 002C2880 24858DC7 */  lwc1       $f13, -0x7ADC($28)
    /* 1C2884 002C2884 2D280000 */  daddu      $5, $0, $0
    /* 1C2888 002C2888 04000624 */  addiu      $6, $0, 0x4
    /* 1C288C 002C288C 2D38C000 */  daddu      $7, $6, $0
    /* 1C2890 002C2890 50820B0C */  jal        func_002e0940
    /* 1C2894 002C2894 00000000 */   nop
    /* 1C2898 002C2898 500C248E */  lw         $4, 0xC50($17)
    /* 1C289C 002C289C 2D280000 */  daddu      $5, $0, $0
    /* 1C28A0 002C28A0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C28A4 002C28A4 2D380000 */  daddu      $7, $0, $0
    /* 1C28A8 002C28A8 04000824 */  addiu      $8, $0, 0x4
    /* 1C28AC 002C28AC 2D480001 */  daddu      $9, $8, $0
    /* 1C28B0 002C28B0 98810B0C */  jal        func_002e0660
    /* 1C28B4 002C28B4 00000000 */   nop
    /* 1C28B8 002C28B8 2D200002 */  daddu      $4, $16, $0
    /* 1C28BC 002C28BC A0B4110C */  jal        func_0046d280
    /* 1C28C0 002C28C0 00000000 */   nop
    /* 1C28C4 002C28C4 3E43023C */  lui        $2, (0x433E0000 >> 16)
    /* 1C28C8 002C28C8 00608244 */  mtc1       $2, $f12
    /* 1C28CC 002C28CC 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C28D0 002C28D0 40000524 */  addiu      $5, $0, 0x40
    /* 1C28D4 002C28D4 78820B0C */  jal        func_002e09e0
    /* 1C28D8 002C28D8 00000000 */   nop
    /* 1C28DC 002C28DC 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1C28E0 002C28E0 00A08244 */  mtc1       $2, $f20
    /* 1C28E4 002C28E4 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C28E8 002C28E8 38810B0C */  jal        func_002e04e0
    /* 1C28EC 002C28EC 00000000 */   nop
    /* 1C28F0 002C28F0 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C28F4 002C28F4 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1C28F8 002C28F8 00A08244 */  mtc1       $2, $f20
    /* 1C28FC 002C28FC 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C2900 002C2900 38810B0C */  jal        func_002e04e0
    /* 1C2904 002C2904 00000000 */   nop
    /* 1C2908 002C2908 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C290C 002C290C 280F248E */  lw         $4, 0xF28($17)
    /* 1C2910 002C2910 06000524 */  addiu      $5, $0, 0x6
    /* 1C2914 002C2914 80B4110C */  jal        func_0046d200
    /* 1C2918 002C2918 00000000 */   nop
    /* 1C291C 002C291C 2D904000 */  daddu      $18, $2, $0
    /* 1C2920 002C2920 2D204002 */  daddu      $4, $18, $0
    /* 1C2924 002C2924 98AC110C */  jal        func_0046b260
    /* 1C2928 002C2928 00000000 */   nop
    /* 1C292C 002C292C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C2930 002C2930 00000244 */  mfc1       $2, $f0
    /* 1C2934 002C2934 00000000 */  nop
    /* 1C2938 002C2938 3C840200 */  dsll32     $16, $2, 16
    /* 1C293C 002C293C 3F841000 */  dsra32     $16, $16, 16
    /* 1C2940 002C2940 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C2944 002C2944 38810B0C */  jal        func_002e04e0
    /* 1C2948 002C2948 00000000 */   nop
    /* 1C294C 002C294C 000150A4 */  sh         $16, 0x100($2)
    /* 1C2950 002C2950 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C2954 002C2954 38810B0C */  jal        func_002e04e0
    /* 1C2958 002C2958 00000000 */   nop
    /* 1C295C 002C295C 020140A4 */  sh         $0, 0x102($2)
    /* 1C2960 002C2960 2D204002 */  daddu      $4, $18, $0
    /* 1C2964 002C2964 A0B4110C */  jal        func_0046d280
    /* 1C2968 002C2968 00000000 */   nop
    /* 1C296C 002C296C AAC2023C */  lui        $2, (0xC2AA0000 >> 16)
    /* 1C2970 002C2970 00608244 */  mtc1       $2, $f12
    /* 1C2974 002C2974 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C2978 002C2978 28858DC7 */  lwc1       $f13, -0x7AD8($28)
    /* 1C297C 002C297C 2D280000 */  daddu      $5, $0, $0
    /* 1C2980 002C2980 04000624 */  addiu      $6, $0, 0x4
    /* 1C2984 002C2984 02000724 */  addiu      $7, $0, 0x2
    /* 1C2988 002C2988 50820B0C */  jal        func_002e0940
    /* 1C298C 002C298C 00000000 */   nop
    /* 1C2990 002C2990 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1C2994 002C2994 2D280000 */  daddu      $5, $0, $0
    /* 1C2998 002C2998 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C299C 002C299C 2D380000 */  daddu      $7, $0, $0
    /* 1C29A0 002C29A0 04000824 */  addiu      $8, $0, 0x4
    /* 1C29A4 002C29A4 02000924 */  addiu      $9, $0, 0x2
    /* 1C29A8 002C29A8 98810B0C */  jal        func_002e0660
    /* 1C29AC 002C29AC 00000000 */   nop
    /* 1C29B0 002C29B0 2DA80000 */  daddu      $21, $0, $0
    /* 1C29B4 002C29B4 4C000010 */  b          .L002C2AE8
    /* 1C29B8 002C29B8 00000000 */   nop
  .L002C29BC:
    /* 1C29BC 002C29BC 3C9C1500 */  dsll32     $19, $21, 16
    /* 1C29C0 002C29C0 3F9C1300 */  dsra32     $19, $19, 16
    /* 1C29C4 002C29C4 3A006226 */  addiu      $2, $19, 0x3A
    /* 1C29C8 002C29C8 C0180200 */  sll        $3, $2, 3
    /* 1C29CC 002C29CC 6400023C */  lui        $2, %hi(D_0063F560)
    /* 1C29D0 002C29D0 60F54224 */  addiu      $2, $2, %lo(D_0063F560)
    /* 1C29D4 002C29D4 21904300 */  addu       $18, $2, $3
    /* 1C29D8 002C29D8 80101300 */  sll        $2, $19, 2
    /* 1C29DC 002C29DC 21182202 */  addu       $3, $17, $2
    /* 1C29E0 002C29E0 200D7024 */  addiu      $16, $3, 0xD20
    /* 1C29E4 002C29E4 64006226 */  addiu      $2, $19, 0x64
    /* 1C29E8 002C29E8 00008244 */  mtc1       $2, $f0
    /* 1C29EC 002C29EC 00000000 */  nop
    /* 1C29F0 002C29F0 20038046 */  cvt.s.w    $f12, $f0
    /* 1C29F4 002C29F4 200D648C */  lw         $4, 0xD20($3)
    /* 1C29F8 002C29F8 56000524 */  addiu      $5, $0, 0x56
    /* 1C29FC 002C29FC 78820B0C */  jal        func_002e09e0
    /* 1C2A00 002C2A00 00000000 */   nop
    /* 1C2A04 002C2A04 1300601A */  blez       $19, .L002C2A54
    /* 1C2A08 002C2A08 00000000 */   nop
    /* 1C2A0C 002C2A0C 4407A427 */  addiu      $4, $29, 0x744
    /* 1C2A10 002C2A10 ED000524 */  addiu      $5, $0, 0xED
    /* 1C2A14 002C2A14 80000624 */  addiu      $6, $0, 0x80
    /* 1C2A18 002C2A18 2D380000 */  daddu      $7, $0, $0
    /* 1C2A1C 002C2A1C FF000824 */  addiu      $8, $0, 0xFF
    /* 1C2A20 002C2A20 98CA0A0C */  jal        func_002b2a60
    /* 1C2A24 002C2A24 00000000 */   nop
    /* 1C2A28 002C2A28 0000048E */  lw         $4, 0x0($16)
    /* 1C2A2C 002C2A2C 38810B0C */  jal        func_002e04e0
    /* 1C2A30 002C2A30 00000000 */   nop
    /* 1C2A34 002C2A34 4407A693 */  lbu        $6, 0x744($29)
    /* 1C2A38 002C2A38 4507A593 */  lbu        $5, 0x745($29)
    /* 1C2A3C 002C2A3C 4607A493 */  lbu        $4, 0x746($29)
    /* 1C2A40 002C2A40 4707A393 */  lbu        $3, 0x747($29)
    /* 1C2A44 002C2A44 790046A0 */  sb         $6, 0x79($2)
    /* 1C2A48 002C2A48 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C2A4C 002C2A4C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C2A50 002C2A50 7C0043A0 */  sb         $3, 0x7C($2)
  .L002C2A54:
    /* 1C2A54 002C2A54 3C141500 */  dsll32     $2, $21, 16
    /* 1C2A58 002C2A58 3F140200 */  dsra32     $2, $2, 16
    /* 1C2A5C 002C2A5C 80100200 */  sll        $2, $2, 2
    /* 1C2A60 002C2A60 21102202 */  addu       $2, $17, $2
    /* 1C2A64 002C2A64 200D5024 */  addiu      $16, $2, 0xD20
    /* 1C2A68 002C2A68 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1C2A6C 002C2A6C 00088244 */  mtc1       $2, $f1
    /* 1C2A70 002C2A70 000040C6 */  lwc1       $f0, 0x0($18)
    /* 1C2A74 002C2A74 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C2A78 002C2A78 D004A427 */  addiu      $4, $29, 0x4D0
    /* 1C2A7C 002C2A7C 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1C2A80 002C2A80 5CCA0A0C */  jal        func_002b2970
    /* 1C2A84 002C2A84 00000000 */   nop
    /* 1C2A88 002C2A88 C804A427 */  addiu      $4, $29, 0x4C8
    /* 1C2A8C 002C2A8C 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1C2A90 002C2A90 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1C2A94 002C2A94 5CCA0A0C */  jal        func_002b2970
    /* 1C2A98 002C2A98 00000000 */   nop
    /* 1C2A9C 002C2A9C 0000048E */  lw         $4, 0x0($16)
    /* 1C2AA0 002C2AA0 D004A5DF */  ld         $5, 0x4D0($29)
    /* 1C2AA4 002C2AA4 C804A6DF */  ld         $6, 0x4C8($29)
    /* 1C2AA8 002C2AA8 2D380000 */  daddu      $7, $0, $0
    /* 1C2AAC 002C2AAC 03000824 */  addiu      $8, $0, 0x3
    /* 1C2AB0 002C2AB0 2D48A002 */  daddu      $9, $21, $0
    /* 1C2AB4 002C2AB4 88810B0C */  jal        func_002e0620
    /* 1C2AB8 002C2AB8 00000000 */   nop
    /* 1C2ABC 002C2ABC 0000048E */  lw         $4, 0x0($16)
    /* 1C2AC0 002C2AC0 2D280000 */  daddu      $5, $0, $0
    /* 1C2AC4 002C2AC4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C2AC8 002C2AC8 2D380000 */  daddu      $7, $0, $0
    /* 1C2ACC 002C2ACC 03000824 */  addiu      $8, $0, 0x3
    /* 1C2AD0 002C2AD0 2D48A002 */  daddu      $9, $21, $0
    /* 1C2AD4 002C2AD4 98810B0C */  jal        func_002e0660
    /* 1C2AD8 002C2AD8 00000000 */   nop
    /* 1C2ADC 002C2ADC 0100A226 */  addiu      $2, $21, 0x1
    /* 1C2AE0 002C2AE0 3CAC0200 */  dsll32     $21, $2, 16
    /* 1C2AE4 002C2AE4 3FAC1500 */  dsra32     $21, $21, 16
  .L002C2AE8:
    /* 1C2AE8 002C2AE8 3C141500 */  dsll32     $2, $21, 16
    /* 1C2AEC 002C2AEC 3F140200 */  dsra32     $2, $2, 16
    /* 1C2AF0 002C2AF0 07004228 */  slti       $2, $2, 0x7
    /* 1C2AF4 002C2AF4 B1FF4014 */  bnez       $2, .L002C29BC
    /* 1C2AF8 002C2AF8 00000000 */   nop
    /* 1C2AFC 002C2AFC 4007A427 */  addiu      $4, $29, 0x740
    /* 1C2B00 002C2B00 2D000524 */  addiu      $5, $0, 0x2D
    /* 1C2B04 002C2B04 2D30A000 */  daddu      $6, $5, $0
    /* 1C2B08 002C2B08 2D38A000 */  daddu      $7, $5, $0
    /* 1C2B0C 002C2B0C FF000824 */  addiu      $8, $0, 0xFF
    /* 1C2B10 002C2B10 98CA0A0C */  jal        func_002b2a60
    /* 1C2B14 002C2B14 00000000 */   nop
    /* 1C2B18 002C2B18 07002282 */  lb         $2, 0x7($17)
    /* 1C2B1C 002C2B1C 80100200 */  sll        $2, $2, 2
    /* 1C2B20 002C2B20 21105100 */  addu       $2, $2, $17
    /* 1C2B24 002C2B24 240D448C */  lw         $4, 0xD24($2)
    /* 1C2B28 002C2B28 38810B0C */  jal        func_002e04e0
    /* 1C2B2C 002C2B2C 00000000 */   nop
    /* 1C2B30 002C2B30 4007A693 */  lbu        $6, 0x740($29)
    /* 1C2B34 002C2B34 4107A593 */  lbu        $5, 0x741($29)
    /* 1C2B38 002C2B38 4207A493 */  lbu        $4, 0x742($29)
    /* 1C2B3C 002C2B3C 4307A393 */  lbu        $3, 0x743($29)
    /* 1C2B40 002C2B40 790046A0 */  sb         $6, 0x79($2)
    /* 1C2B44 002C2B44 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C2B48 002C2B48 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C2B4C 002C2B4C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C2B50 002C2B50 07002982 */  lb         $9, 0x7($17)
    /* 1C2B54 002C2B54 440C248E */  lw         $4, 0xC44($17)
    /* 1C2B58 002C2B58 2D280000 */  daddu      $5, $0, $0
    /* 1C2B5C 002C2B5C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C2B60 002C2B60 2D380000 */  daddu      $7, $0, $0
    /* 1C2B64 002C2B64 2D400000 */  daddu      $8, $0, $0
    /* 1C2B68 002C2B68 98810B0C */  jal        func_002e0660
    /* 1C2B6C 002C2B6C 00000000 */   nop
    /* 1C2B70 002C2B70 07002982 */  lb         $9, 0x7($17)
    /* 1C2B74 002C2B74 480C248E */  lw         $4, 0xC48($17)
    /* 1C2B78 002C2B78 2D280000 */  daddu      $5, $0, $0
    /* 1C2B7C 002C2B7C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C2B80 002C2B80 2D380000 */  daddu      $7, $0, $0
    /* 1C2B84 002C2B84 2D400000 */  daddu      $8, $0, $0
    /* 1C2B88 002C2B88 98810B0C */  jal        func_002e0660
    /* 1C2B8C 002C2B8C 00000000 */   nop
    /* 1C2B90 002C2B90 2D800000 */  daddu      $16, $0, $0
    /* 1C2B94 002C2B94 0E000010 */  b          .L002C2BD0
    /* 1C2B98 002C2B98 00000000 */   nop
  .L002C2B9C:
    /* 1C2B9C 002C2B9C 80100300 */  sll        $2, $3, 2
    /* 1C2BA0 002C2BA0 21102202 */  addu       $2, $17, $2
    /* 1C2BA4 002C2BA4 380C448C */  lw         $4, 0xC38($2)
    /* 1C2BA8 002C2BA8 2D280000 */  daddu      $5, $0, $0
    /* 1C2BAC 002C2BAC FF000624 */  addiu      $6, $0, 0xFF
    /* 1C2BB0 002C2BB0 2D380000 */  daddu      $7, $0, $0
    /* 1C2BB4 002C2BB4 0A000824 */  addiu      $8, $0, 0xA
    /* 1C2BB8 002C2BB8 2D480000 */  daddu      $9, $0, $0
    /* 1C2BBC 002C2BBC 98810B0C */  jal        func_002e0660
    /* 1C2BC0 002C2BC0 00000000 */   nop
    /* 1C2BC4 002C2BC4 01000226 */  addiu      $2, $16, 0x1
    /* 1C2BC8 002C2BC8 3C840200 */  dsll32     $16, $2, 16
    /* 1C2BCC 002C2BCC 3F841000 */  dsra32     $16, $16, 16
  .L002C2BD0:
    /* 1C2BD0 002C2BD0 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C2BD4 002C2BD4 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C2BD8 002C2BD8 03006228 */  slti       $2, $3, 0x3
    /* 1C2BDC 002C2BDC EFFF4014 */  bnez       $2, .L002C2B9C
    /* 1C2BE0 002C2BE0 00000000 */   nop
    /* 1C2BE4 002C2BE4 2D208002 */  daddu      $4, $20, $0
    /* 1C2BE8 002C2BE8 E45F0B0C */  jal        func_002d7f90
    /* 1C2BEC 002C2BEC 00000000 */   nop
    /* 1C2BF0 002C2BF0 11000224 */  addiu      $2, $0, 0x11
    /* 1C2BF4 002C2BF4 000022A2 */  sb         $2, 0x0($17)
    /* 1C2BF8 002C2BF8 CB1E0010 */  b          .L002CA728
    /* 1C2BFC 002C2BFC 00000000 */   nop
  .L002C2C00:
    /* 1C2C00 002C2C00 40006230 */  andi       $2, $3, 0x40
    /* 1C2C04 002C2C04 C81E4010 */  beqz       $2, .L002CA728
    /* 1C2C08 002C2C08 00000000 */   nop
    /* 1C2C0C 002C2C0C D40E248E */  lw         $4, 0xED4($17)
    /* 1C2C10 002C2C10 38810B0C */  jal        func_002e04e0
    /* 1C2C14 002C2C14 00000000 */   nop
    /* 1C2C18 002C2C18 00688044 */  mtc1       $0, $f13
    /* 1C2C1C 002C2C1C D40E248E */  lw         $4, 0xED4($17)
    /* 1C2C20 002C2C20 C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C2C24 002C2C24 2D280000 */  daddu      $5, $0, $0
    /* 1C2C28 002C2C28 02000624 */  addiu      $6, $0, 0x2
    /* 1C2C2C 002C2C2C 2D380000 */  daddu      $7, $0, $0
    /* 1C2C30 002C2C30 50820B0C */  jal        func_002e0940
    /* 1C2C34 002C2C34 00000000 */   nop
    /* 1C2C38 002C2C38 D80E248E */  lw         $4, 0xED8($17)
    /* 1C2C3C 002C2C3C 38810B0C */  jal        func_002e04e0
    /* 1C2C40 002C2C40 00000000 */   nop
    /* 1C2C44 002C2C44 00688044 */  mtc1       $0, $f13
    /* 1C2C48 002C2C48 D80E248E */  lw         $4, 0xED8($17)
    /* 1C2C4C 002C2C4C C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C2C50 002C2C50 2D280000 */  daddu      $5, $0, $0
    /* 1C2C54 002C2C54 02000624 */  addiu      $6, $0, 0x2
    /* 1C2C58 002C2C58 2D380000 */  daddu      $7, $0, $0
    /* 1C2C5C 002C2C5C 50820B0C */  jal        func_002e0940
    /* 1C2C60 002C2C60 00000000 */   nop
    /* 1C2C64 002C2C64 2D900000 */  daddu      $18, $0, $0
    /* 1C2C68 002C2C68 18000010 */  b          .L002C2CCC
    /* 1C2C6C 002C2C6C 00000000 */   nop
  .L002C2C70:
    /* 1C2C70 002C2C70 3C141200 */  dsll32     $2, $18, 16
    /* 1C2C74 002C2C74 3F140200 */  dsra32     $2, $2, 16
    /* 1C2C78 002C2C78 80100200 */  sll        $2, $2, 2
    /* 1C2C7C 002C2C7C 21802202 */  addu       $16, $17, $2
    /* 1C2C80 002C2C80 D40E1326 */  addiu      $19, $16, 0xED4
    /* 1C2C84 002C2C84 D40E048E */  lw         $4, 0xED4($16)
    /* 1C2C88 002C2C88 38810B0C */  jal        func_002e04e0
    /* 1C2C8C 002C2C8C 00000000 */   nop
    /* 1C2C90 002C2C90 79004290 */  lbu        $2, 0x79($2)
    /* 1C2C94 002C2C94 3E0F02A2 */  sb         $2, 0xF3E($16)
    /* 1C2C98 002C2C98 0000648E */  lw         $4, 0x0($19)
    /* 1C2C9C 002C2C9C 38810B0C */  jal        func_002e04e0
    /* 1C2CA0 002C2CA0 00000000 */   nop
    /* 1C2CA4 002C2CA4 7A004290 */  lbu        $2, 0x7A($2)
    /* 1C2CA8 002C2CA8 3F0F02A2 */  sb         $2, 0xF3F($16)
    /* 1C2CAC 002C2CAC 0000648E */  lw         $4, 0x0($19)
    /* 1C2CB0 002C2CB0 38810B0C */  jal        func_002e04e0
    /* 1C2CB4 002C2CB4 00000000 */   nop
    /* 1C2CB8 002C2CB8 7B004290 */  lbu        $2, 0x7B($2)
    /* 1C2CBC 002C2CBC 400F02A2 */  sb         $2, 0xF40($16)
    /* 1C2CC0 002C2CC0 01004226 */  addiu      $2, $18, 0x1
    /* 1C2CC4 002C2CC4 3C940200 */  dsll32     $18, $2, 16
    /* 1C2CC8 002C2CC8 3F941200 */  dsra32     $18, $18, 16
  .L002C2CCC:
    /* 1C2CCC 002C2CCC 3C141200 */  dsll32     $2, $18, 16
    /* 1C2CD0 002C2CD0 3F140200 */  dsra32     $2, $2, 16
    /* 1C2CD4 002C2CD4 02004228 */  slti       $2, $2, 0x2
    /* 1C2CD8 002C2CD8 E5FF4014 */  bnez       $2, .L002C2C70
    /* 1C2CDC 002C2CDC 00000000 */   nop
    /* 1C2CE0 002C2CE0 3C0F20A6 */  sh         $0, 0xF3C($17)
    /* 1C2CE4 002C2CE4 16000224 */  addiu      $2, $0, 0x16
    /* 1C2CE8 002C2CE8 000022A2 */  sb         $2, 0x0($17)
    /* 1C2CEC 002C2CEC 2D200000 */  daddu      $4, $0, $0
    /* 1C2CF0 002C2CF0 2D280000 */  daddu      $5, $0, $0
    /* 1C2CF4 002C2CF4 2D300000 */  daddu      $6, $0, $0
    /* 1C2CF8 002C2CF8 01000724 */  addiu      $7, $0, 0x1
    /* 1C2CFC 002C2CFC D86B110C */  jal        func_0045af60
    /* 1C2D00 002C2D00 00000000 */   nop
    /* 1C2D04 002C2D04 881E0010 */  b          .L002CA728
    /* 1C2D08 002C2D08 00000000 */   nop
    /* 1C2D0C 002C2D0C 2D208002 */  daddu      $4, $20, $0
    /* 1C2D10 002C2D10 68790B0C */  jal        func_002de5a0
    /* 1C2D14 002C2D14 00000000 */   nop
    /* 1C2D18 002C2D18 6C000010 */  b          .L002C2ECC
    /* 1C2D1C 002C2D1C 00000000 */   nop
  .L002C2D20:
    /* 1C2D20 002C2D20 40100300 */  sll        $2, $3, 1
    /* 1C2D24 002C2D24 21102202 */  addu       $2, $17, $2
    /* 1C2D28 002C2D28 460F4484 */  lh         $4, 0xF46($2)
    /* 1C2D2C 002C2D2C 0F008010 */  beqz       $4, .L002C2D6C
    /* 1C2D30 002C2D30 00000000 */   nop
    /* 1C2D34 002C2D34 3C141300 */  dsll32     $2, $19, 16
    /* 1C2D38 002C2D38 3F140200 */  dsra32     $2, $2, 16
    /* 1C2D3C 002C2D3C 40100200 */  sll        $2, $2, 1
    /* 1C2D40 002C2D40 21102202 */  addu       $2, $17, $2
    /* 1C2D44 002C2D44 460F5024 */  addiu      $16, $2, 0xF46
    /* 1C2D48 002C2D48 01000524 */  addiu      $5, $0, 0x1
    /* 1C2D4C 002C2D4C 2D300000 */  daddu      $6, $0, $0
    /* 1C2D50 002C2D50 2D380000 */  daddu      $7, $0, $0
    /* 1C2D54 002C2D54 2D40A000 */  daddu      $8, $5, $0
    /* 1C2D58 002C2D58 40CB0A0C */  jal        func_002b2d00
    /* 1C2D5C 002C2D5C 00000000 */   nop
    /* 1C2D60 002C2D60 000002A6 */  sh         $2, 0x0($16)
    /* 1C2D64 002C2D64 56000010 */  b          .L002C2EC0
    /* 1C2D68 002C2D68 00000000 */   nop
  .L002C2D6C:
    /* 1C2D6C 002C2D6C 3C941300 */  dsll32     $18, $19, 16
    /* 1C2D70 002C2D70 3F941200 */  dsra32     $18, $18, 16
    /* 1C2D74 002C2D74 40101200 */  sll        $2, $18, 1
    /* 1C2D78 002C2D78 21102202 */  addu       $2, $17, $2
    /* 1C2D7C 002C2D7C 580F5524 */  addiu      $21, $2, 0xF58
    /* 1C2D80 002C2D80 21B03202 */  addu       $22, $17, $18
    /* 1C2D84 002C2D84 6A0FD026 */  addiu      $16, $22, 0xF6A
    /* 1C2D88 002C2D88 580F4284 */  lh         $2, 0xF58($2)
    /* 1C2D8C 002C2D8C 00008244 */  mtc1       $2, $f0
    /* 1C2D90 002C2D90 00000000 */  nop
    /* 1C2D94 002C2D94 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C2D98 002C2D98 00608044 */  mtc1       $0, $f12
    /* 1C2D9C 002C2D9C 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C2DA0 002C2DA0 00688244 */  mtc1       $2, $f13
    /* 1C2DA4 002C2DA4 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C2DA8 002C2DA8 00788244 */  mtc1       $2, $f15
    /* 1C2DAC 002C2DAC 2D200000 */  daddu      $4, $0, $0
    /* 1C2DB0 002C2DB0 A8CA0A0C */  jal        func_002b2aa0
    /* 1C2DB4 002C2DB4 00000000 */   nop
    /* 1C2DB8 002C2DB8 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C2DBC 002C2DBC 00088244 */  mtc1       $2, $f1
    /* 1C2DC0 002C2DC0 00000000 */  nop
    /* 1C2DC4 002C2DC4 36080046 */  c.le.s     $f1, $f0
    /* 1C2DC8 002C2DC8 07000145 */  bc1t       .L002C2DE8
    /* 1C2DCC 002C2DCC 00000000 */   nop
    /* 1C2DD0 002C2DD0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C2DD4 002C2DD4 00000344 */  mfc1       $3, $f0
    /* 1C2DD8 002C2DD8 00000000 */  nop
    /* 1C2DDC 002C2DDC FF006330 */  andi       $3, $3, 0xFF
    /* 1C2DE0 002C2DE0 07000010 */  b          .L002C2E00
    /* 1C2DE4 002C2DE4 00000000 */   nop
  .L002C2DE8:
    /* 1C2DE8 002C2DE8 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C2DEC 002C2DEC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C2DF0 002C2DF0 00000344 */  mfc1       $3, $f0
    /* 1C2DF4 002C2DF4 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C2DF8 002C2DF8 25186200 */  or         $3, $3, $2
    /* 1C2DFC 002C2DFC FF006330 */  andi       $3, $3, 0xFF
  .L002C2E00:
    /* 1C2E00 002C2E00 000003A2 */  sb         $3, 0x0($16)
    /* 1C2E04 002C2E04 0000A486 */  lh         $4, 0x0($21)
    /* 1C2E08 002C2E08 01000524 */  addiu      $5, $0, 0x1
    /* 1C2E0C 002C2E0C 06000624 */  addiu      $6, $0, 0x6
    /* 1C2E10 002C2E10 2D380000 */  daddu      $7, $0, $0
    /* 1C2E14 002C2E14 2D40A000 */  daddu      $8, $5, $0
    /* 1C2E18 002C2E18 2CCB0A0C */  jal        func_002b2cb0
    /* 1C2E1C 002C2E1C 00000000 */   nop
    /* 1C2E20 002C2E20 0000A2A6 */  sh         $2, 0x0($21)
    /* 1C2E24 002C2E24 EC000424 */  addiu      $4, $0, 0xEC
    /* 1C2E28 002C2E28 7F000524 */  addiu      $5, $0, 0x7F
    /* 1C2E2C 002C2E2C 2D300000 */  daddu      $6, $0, $0
    /* 1C2E30 002C2E30 00000792 */  lbu        $7, 0x0($16)
    /* 1C2E34 002C2E34 8CCA0A0C */  jal        func_002b2a30
    /* 1C2E38 002C2E38 00000000 */   nop
    /* 1C2E3C 002C2E3C 2DA84000 */  daddu      $21, $2, $0
    /* 1C2E40 002C2E40 08002282 */  lb         $2, 0x8($17)
    /* 1C2E44 002C2E44 08005214 */  bne        $2, $18, .L002C2E68
    /* 1C2E48 002C2E48 00000000 */   nop
    /* 1C2E4C 002C2E4C 2D000424 */  addiu      $4, $0, 0x2D
    /* 1C2E50 002C2E50 2D288000 */  daddu      $5, $4, $0
    /* 1C2E54 002C2E54 2D308000 */  daddu      $6, $4, $0
    /* 1C2E58 002C2E58 00000792 */  lbu        $7, 0x0($16)
    /* 1C2E5C 002C2E5C 8CCA0A0C */  jal        func_002b2a30
    /* 1C2E60 002C2E60 00000000 */   nop
    /* 1C2E64 002C2E64 2DA84000 */  daddu      $21, $2, $0
  .L002C2E68:
    /* 1C2E68 002C2E68 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1C2E6C 002C2E6C 00188244 */  mtc1       $2, $f3
    /* 1C2E70 002C2E70 00009344 */  mtc1       $19, $f0
    /* 1C2E74 002C2E74 00000000 */  nop
    /* 1C2E78 002C2E78 A0008046 */  cvt.s.w    $f2, $f0
    /* 1C2E7C 002C2E7C AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1C2E80 002C2E80 00088244 */  mtc1       $2, $f1
    /* 1C2E84 002C2E84 00008044 */  mtc1       $0, $f0
    /* 1C2E88 002C2E88 00000000 */  nop
    /* 1C2E8C 002C2E8C 18000146 */  adda.s     $f0, $f1
    /* 1C2E90 002C2E90 5C1B0246 */  madd.s     $f13, $f3, $f2
    /* 1C2E94 002C2E94 8E42023C */  lui        $2, (0x428E0000 >> 16)
    /* 1C2E98 002C2E98 00608244 */  mtc1       $2, $f12
    /* 1C2E9C 002C2E9C C004A427 */  addiu      $4, $29, 0x4C0
    /* 1C2EA0 002C2EA0 5CCA0A0C */  jal        func_002b2970
    /* 1C2EA4 002C2EA4 00000000 */   nop
    /* 1C2EA8 002C2EA8 2D208002 */  daddu      $4, $20, $0
    /* 1C2EAC 002C2EAC 730FC582 */  lb         $5, 0xF73($22)
    /* 1C2EB0 002C2EB0 C004A6DF */  ld         $6, 0x4C0($29)
    /* 1C2EB4 002C2EB4 2D38A002 */  daddu      $7, $21, $0
    /* 1C2EB8 002C2EB8 20800B0C */  jal        func_002e0080
    /* 1C2EBC 002C2EBC 00000000 */   nop
  .L002C2EC0:
    /* 1C2EC0 002C2EC0 01006226 */  addiu      $2, $19, 0x1
    /* 1C2EC4 002C2EC4 3C9C0200 */  dsll32     $19, $2, 16
    /* 1C2EC8 002C2EC8 3F9C1300 */  dsra32     $19, $19, 16
  .L002C2ECC:
    /* 1C2ECC 002C2ECC 3C1C1300 */  dsll32     $3, $19, 16
    /* 1C2ED0 002C2ED0 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C2ED4 002C2ED4 09002282 */  lb         $2, 0x9($17)
    /* 1C2ED8 002C2ED8 2A106200 */  slt        $2, $3, $2
    /* 1C2EDC 002C2EDC 90FF4014 */  bnez       $2, .L002C2D20
    /* 1C2EE0 002C2EE0 00000000 */   nop
    /* 1C2EE4 002C2EE4 2D980000 */  daddu      $19, $0, $0
    /* 1C2EE8 002C2EE8 93000010 */  b          .L002C3138
    /* 1C2EEC 002C2EEC 00000000 */   nop
  .L002C2EF0:
    /* 1C2EF0 002C2EF0 3C141300 */  dsll32     $2, $19, 16
    /* 1C2EF4 002C2EF4 3F140200 */  dsra32     $2, $2, 16
    /* 1C2EF8 002C2EF8 80100200 */  sll        $2, $2, 2
    /* 1C2EFC 002C2EFC 21902202 */  addu       $18, $17, $2
    /* 1C2F00 002C2F00 D40E448E */  lw         $4, 0xED4($18)
    /* 1C2F04 002C2F04 38810B0C */  jal        func_002e04e0
    /* 1C2F08 002C2F08 00000000 */   nop
    /* 1C2F0C 002C2F0C 2D804000 */  daddu      $16, $2, $0
    /* 1C2F10 002C2F10 3E0F4292 */  lbu        $2, 0xF3E($18)
    /* 1C2F14 002C2F14 06004004 */  bltz       $2, .L002C2F30
    /* 1C2F18 002C2F18 00000000 */   nop
    /* 1C2F1C 002C2F1C 00008244 */  mtc1       $2, $f0
    /* 1C2F20 002C2F20 00000000 */  nop
    /* 1C2F24 002C2F24 20038046 */  cvt.s.w    $f12, $f0
    /* 1C2F28 002C2F28 08000010 */  b          .L002C2F4C
    /* 1C2F2C 002C2F2C 00000000 */   nop
  .L002C2F30:
    /* 1C2F30 002C2F30 42180200 */  srl        $3, $2, 1
    /* 1C2F34 002C2F34 01004230 */  andi       $2, $2, 0x1
    /* 1C2F38 002C2F38 25186200 */  or         $3, $3, $2
    /* 1C2F3C 002C2F3C 00008344 */  mtc1       $3, $f0
    /* 1C2F40 002C2F40 00000000 */  nop
    /* 1C2F44 002C2F44 20038046 */  cvt.s.w    $f12, $f0
    /* 1C2F48 002C2F48 00630C46 */  add.s      $f12, $f12, $f12
  .L002C2F4C:
    /* 1C2F4C 002C2F4C 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C2F50 002C2F50 00008244 */  mtc1       $2, $f0
    /* 1C2F54 002C2F54 00000000 */  nop
    /* 1C2F58 002C2F58 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C2F5C 002C2F5C 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C2F60 002C2F60 00688244 */  mtc1       $2, $f13
    /* 1C2F64 002C2F64 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C2F68 002C2F68 00788244 */  mtc1       $2, $f15
    /* 1C2F6C 002C2F6C 01000424 */  addiu      $4, $0, 0x1
    /* 1C2F70 002C2F70 A8CA0A0C */  jal        func_002b2aa0
    /* 1C2F74 002C2F74 00000000 */   nop
    /* 1C2F78 002C2F78 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C2F7C 002C2F7C 00088244 */  mtc1       $2, $f1
    /* 1C2F80 002C2F80 00000000 */  nop
    /* 1C2F84 002C2F84 36080046 */  c.le.s     $f1, $f0
    /* 1C2F88 002C2F88 07000145 */  bc1t       .L002C2FA8
    /* 1C2F8C 002C2F8C 00000000 */   nop
    /* 1C2F90 002C2F90 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C2F94 002C2F94 00000344 */  mfc1       $3, $f0
    /* 1C2F98 002C2F98 00000000 */  nop
    /* 1C2F9C 002C2F9C FF006330 */  andi       $3, $3, 0xFF
    /* 1C2FA0 002C2FA0 07000010 */  b          .L002C2FC0
    /* 1C2FA4 002C2FA4 00000000 */   nop
  .L002C2FA8:
    /* 1C2FA8 002C2FA8 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C2FAC 002C2FAC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C2FB0 002C2FB0 00000344 */  mfc1       $3, $f0
    /* 1C2FB4 002C2FB4 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C2FB8 002C2FB8 25186200 */  or         $3, $3, $2
    /* 1C2FBC 002C2FBC FF006330 */  andi       $3, $3, 0xFF
  .L002C2FC0:
    /* 1C2FC0 002C2FC0 790003A2 */  sb         $3, 0x79($16)
    /* 1C2FC4 002C2FC4 3F0F4292 */  lbu        $2, 0xF3F($18)
    /* 1C2FC8 002C2FC8 06004004 */  bltz       $2, .L002C2FE4
    /* 1C2FCC 002C2FCC 00000000 */   nop
    /* 1C2FD0 002C2FD0 00008244 */  mtc1       $2, $f0
    /* 1C2FD4 002C2FD4 00000000 */  nop
    /* 1C2FD8 002C2FD8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C2FDC 002C2FDC 08000010 */  b          .L002C3000
    /* 1C2FE0 002C2FE0 00000000 */   nop
  .L002C2FE4:
    /* 1C2FE4 002C2FE4 42180200 */  srl        $3, $2, 1
    /* 1C2FE8 002C2FE8 01004230 */  andi       $2, $2, 0x1
    /* 1C2FEC 002C2FEC 25186200 */  or         $3, $3, $2
    /* 1C2FF0 002C2FF0 00008344 */  mtc1       $3, $f0
    /* 1C2FF4 002C2FF4 00000000 */  nop
    /* 1C2FF8 002C2FF8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C2FFC 002C2FFC 00630C46 */  add.s      $f12, $f12, $f12
  .L002C3000:
    /* 1C3000 002C3000 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C3004 002C3004 00008244 */  mtc1       $2, $f0
    /* 1C3008 002C3008 00000000 */  nop
    /* 1C300C 002C300C A0038046 */  cvt.s.w    $f14, $f0
    /* 1C3010 002C3010 6243023C */  lui        $2, (0x43620000 >> 16)
    /* 1C3014 002C3014 00688244 */  mtc1       $2, $f13
    /* 1C3018 002C3018 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C301C 002C301C 00788244 */  mtc1       $2, $f15
    /* 1C3020 002C3020 01000424 */  addiu      $4, $0, 0x1
    /* 1C3024 002C3024 A8CA0A0C */  jal        func_002b2aa0
    /* 1C3028 002C3028 00000000 */   nop
    /* 1C302C 002C302C 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C3030 002C3030 00088244 */  mtc1       $2, $f1
    /* 1C3034 002C3034 00000000 */  nop
    /* 1C3038 002C3038 36080046 */  c.le.s     $f1, $f0
    /* 1C303C 002C303C 07000145 */  bc1t       .L002C305C
    /* 1C3040 002C3040 00000000 */   nop
    /* 1C3044 002C3044 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C3048 002C3048 00000344 */  mfc1       $3, $f0
    /* 1C304C 002C304C 00000000 */  nop
    /* 1C3050 002C3050 FF006330 */  andi       $3, $3, 0xFF
    /* 1C3054 002C3054 07000010 */  b          .L002C3074
    /* 1C3058 002C3058 00000000 */   nop
  .L002C305C:
    /* 1C305C 002C305C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C3060 002C3060 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C3064 002C3064 00000344 */  mfc1       $3, $f0
    /* 1C3068 002C3068 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C306C 002C306C 25186200 */  or         $3, $3, $2
    /* 1C3070 002C3070 FF006330 */  andi       $3, $3, 0xFF
  .L002C3074:
    /* 1C3074 002C3074 7A0003A2 */  sb         $3, 0x7A($16)
    /* 1C3078 002C3078 400F4292 */  lbu        $2, 0xF40($18)
    /* 1C307C 002C307C 06004004 */  bltz       $2, .L002C3098
    /* 1C3080 002C3080 00000000 */   nop
    /* 1C3084 002C3084 00008244 */  mtc1       $2, $f0
    /* 1C3088 002C3088 00000000 */  nop
    /* 1C308C 002C308C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C3090 002C3090 08000010 */  b          .L002C30B4
    /* 1C3094 002C3094 00000000 */   nop
  .L002C3098:
    /* 1C3098 002C3098 42180200 */  srl        $3, $2, 1
    /* 1C309C 002C309C 01004230 */  andi       $2, $2, 0x1
    /* 1C30A0 002C30A0 25186200 */  or         $3, $3, $2
    /* 1C30A4 002C30A4 00008344 */  mtc1       $3, $f0
    /* 1C30A8 002C30A8 00000000 */  nop
    /* 1C30AC 002C30AC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C30B0 002C30B0 00630C46 */  add.s      $f12, $f12, $f12
  .L002C30B4:
    /* 1C30B4 002C30B4 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C30B8 002C30B8 00008244 */  mtc1       $2, $f0
    /* 1C30BC 002C30BC 00000000 */  nop
    /* 1C30C0 002C30C0 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C30C4 002C30C4 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1C30C8 002C30C8 00688244 */  mtc1       $2, $f13
    /* 1C30CC 002C30CC 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C30D0 002C30D0 00788244 */  mtc1       $2, $f15
    /* 1C30D4 002C30D4 01000424 */  addiu      $4, $0, 0x1
    /* 1C30D8 002C30D8 A8CA0A0C */  jal        func_002b2aa0
    /* 1C30DC 002C30DC 00000000 */   nop
    /* 1C30E0 002C30E0 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C30E4 002C30E4 00088244 */  mtc1       $2, $f1
    /* 1C30E8 002C30E8 00000000 */  nop
    /* 1C30EC 002C30EC 36080046 */  c.le.s     $f1, $f0
    /* 1C30F0 002C30F0 07000145 */  bc1t       .L002C3110
    /* 1C30F4 002C30F4 00000000 */   nop
    /* 1C30F8 002C30F8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C30FC 002C30FC 00000344 */  mfc1       $3, $f0
    /* 1C3100 002C3100 00000000 */  nop
    /* 1C3104 002C3104 FF006330 */  andi       $3, $3, 0xFF
    /* 1C3108 002C3108 07000010 */  b          .L002C3128
    /* 1C310C 002C310C 00000000 */   nop
  .L002C3110:
    /* 1C3110 002C3110 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C3114 002C3114 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C3118 002C3118 00000344 */  mfc1       $3, $f0
    /* 1C311C 002C311C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C3120 002C3120 25186200 */  or         $3, $3, $2
    /* 1C3124 002C3124 FF006330 */  andi       $3, $3, 0xFF
  .L002C3128:
    /* 1C3128 002C3128 7B0003A2 */  sb         $3, 0x7B($16)
    /* 1C312C 002C312C 01006226 */  addiu      $2, $19, 0x1
    /* 1C3130 002C3130 3C9C0200 */  dsll32     $19, $2, 16
    /* 1C3134 002C3134 3F9C1300 */  dsra32     $19, $19, 16
  .L002C3138:
    /* 1C3138 002C3138 3C141300 */  dsll32     $2, $19, 16
    /* 1C313C 002C313C 3F140200 */  dsra32     $2, $2, 16
    /* 1C3140 002C3140 02004228 */  slti       $2, $2, 0x2
    /* 1C3144 002C3144 6AFF4014 */  bnez       $2, .L002C2EF0
    /* 1C3148 002C3148 00000000 */   nop
    /* 1C314C 002C314C 3C0F2486 */  lh         $4, 0xF3C($17)
    /* 1C3150 002C3150 06008128 */  slti       $1, $4, 0x6
    /* 1C3154 002C3154 0A002010 */  beqz       $1, .L002C3180
    /* 1C3158 002C3158 00000000 */   nop
    /* 1C315C 002C315C 01000524 */  addiu      $5, $0, 0x1
    /* 1C3160 002C3160 06000624 */  addiu      $6, $0, 0x6
    /* 1C3164 002C3164 2D380000 */  daddu      $7, $0, $0
    /* 1C3168 002C3168 2D40A000 */  daddu      $8, $5, $0
    /* 1C316C 002C316C 2CCB0A0C */  jal        func_002b2cb0
    /* 1C3170 002C3170 00000000 */   nop
    /* 1C3174 002C3174 3C0F22A6 */  sh         $2, 0xF3C($17)
    /* 1C3178 002C3178 6B1D0010 */  b          .L002CA728
    /* 1C317C 002C317C 00000000 */   nop
  .L002C3180:
    /* 1C3180 002C3180 2D900000 */  daddu      $18, $0, $0
    /* 1C3184 002C3184 13000010 */  b          .L002C31D4
    /* 1C3188 002C3188 00000000 */   nop
  .L002C318C:
    /* 1C318C 002C318C 3C141200 */  dsll32     $2, $18, 16
    /* 1C3190 002C3190 3F140200 */  dsra32     $2, $2, 16
    /* 1C3194 002C3194 80100200 */  sll        $2, $2, 2
    /* 1C3198 002C3198 21802202 */  addu       $16, $17, $2
    /* 1C319C 002C319C D40E048E */  lw         $4, 0xED4($16)
    /* 1C31A0 002C31A0 38810B0C */  jal        func_002e04e0
    /* 1C31A4 002C31A4 00000000 */   nop
    /* 1C31A8 002C31A8 3E0F0692 */  lbu        $6, 0xF3E($16)
    /* 1C31AC 002C31AC 3F0F0592 */  lbu        $5, 0xF3F($16)
    /* 1C31B0 002C31B0 400F0492 */  lbu        $4, 0xF40($16)
    /* 1C31B4 002C31B4 410F0392 */  lbu        $3, 0xF41($16)
    /* 1C31B8 002C31B8 790046A0 */  sb         $6, 0x79($2)
    /* 1C31BC 002C31BC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C31C0 002C31C0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C31C4 002C31C4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C31C8 002C31C8 01004226 */  addiu      $2, $18, 0x1
    /* 1C31CC 002C31CC 3C940200 */  dsll32     $18, $2, 16
    /* 1C31D0 002C31D0 3F941200 */  dsra32     $18, $18, 16
  .L002C31D4:
    /* 1C31D4 002C31D4 3C141200 */  dsll32     $2, $18, 16
    /* 1C31D8 002C31D8 3F140200 */  dsra32     $2, $2, 16
    /* 1C31DC 002C31DC 02004228 */  slti       $2, $2, 0x2
    /* 1C31E0 002C31E0 EAFF4014 */  bnez       $2, .L002C318C
    /* 1C31E4 002C31E4 00000000 */   nop
    /* 1C31E8 002C31E8 6400103C */  lui        $16, %hi(D_0063F7C8)
    /* 1C31EC 002C31EC C8F71026 */  addiu      $16, $16, %lo(D_0063F7C8)
    /* 1C31F0 002C31F0 1842023C */  lui        $2, (0x42180000 >> 16)
    /* 1C31F4 002C31F4 00608244 */  mtc1       $2, $f12
    /* 1C31F8 002C31F8 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C31FC 002C31FC 41000524 */  addiu      $5, $0, 0x41
    /* 1C3200 002C3200 78820B0C */  jal        func_002e09e0
    /* 1C3204 002C3204 00000000 */   nop
    /* 1C3208 002C3208 D2C2023C */  lui        $2, (0xC2D20000 >> 16)
    /* 1C320C 002C320C 00608244 */  mtc1       $2, $f12
    /* 1C3210 002C3210 D841023C */  lui        $2, (0x41D80000 >> 16)
    /* 1C3214 002C3214 00688244 */  mtc1       $2, $f13
    /* 1C3218 002C3218 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C321C 002C321C 2D280000 */  daddu      $5, $0, $0
    /* 1C3220 002C3220 05000624 */  addiu      $6, $0, 0x5
    /* 1C3224 002C3224 2D380000 */  daddu      $7, $0, $0
    /* 1C3228 002C3228 50820B0C */  jal        func_002e0940
    /* 1C322C 002C322C 00000000 */   nop
    /* 1C3230 002C3230 3C07A427 */  addiu      $4, $29, 0x73C
    /* 1C3234 002C3234 97000524 */  addiu      $5, $0, 0x97
    /* 1C3238 002C3238 0F000624 */  addiu      $6, $0, 0xF
    /* 1C323C 002C323C 2D380000 */  daddu      $7, $0, $0
    /* 1C3240 002C3240 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C3244 002C3244 98CA0A0C */  jal        func_002b2a60
    /* 1C3248 002C3248 00000000 */   nop
    /* 1C324C 002C324C 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C3250 002C3250 38810B0C */  jal        func_002e04e0
    /* 1C3254 002C3254 00000000 */   nop
    /* 1C3258 002C3258 3C07A693 */  lbu        $6, 0x73C($29)
    /* 1C325C 002C325C 3D07A593 */  lbu        $5, 0x73D($29)
    /* 1C3260 002C3260 3E07A493 */  lbu        $4, 0x73E($29)
    /* 1C3264 002C3264 3F07A393 */  lbu        $3, 0x73F($29)
    /* 1C3268 002C3268 790046A0 */  sb         $6, 0x79($2)
    /* 1C326C 002C326C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C3270 002C3270 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C3274 002C3274 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C3278 002C3278 2D43023C */  lui        $2, (0x432D0000 >> 16)
    /* 1C327C 002C327C 00088244 */  mtc1       $2, $f1
    /* 1C3280 002C3280 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C3284 002C3284 01080046 */  sub.s      $f0, $f1, $f0
    /* 1C3288 002C3288 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C328C 002C328C 00000244 */  mfc1       $2, $f0
    /* 1C3290 002C3290 00000000 */  nop
    /* 1C3294 002C3294 3C940200 */  dsll32     $18, $2, 16
    /* 1C3298 002C3298 3F941200 */  dsra32     $18, $18, 16
    /* 1C329C 002C329C 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C32A0 002C32A0 38810B0C */  jal        func_002e04e0
    /* 1C32A4 002C32A4 00000000 */   nop
    /* 1C32A8 002C32A8 000152A4 */  sh         $18, 0x100($2)
    /* 1C32AC 002C32AC 23020224 */  addiu      $2, $0, 0x223
    /* 1C32B0 002C32B0 00008244 */  mtc1       $2, $f0
    /* 1C32B4 002C32B4 00000000 */  nop
    /* 1C32B8 002C32B8 60008046 */  cvt.s.w    $f1, $f0
    /* 1C32BC 002C32BC 040000C6 */  lwc1       $f0, 0x4($16)
    /* 1C32C0 002C32C0 01080046 */  sub.s      $f0, $f1, $f0
    /* 1C32C4 002C32C4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C32C8 002C32C8 00000244 */  mfc1       $2, $f0
    /* 1C32CC 002C32CC 00000000 */  nop
    /* 1C32D0 002C32D0 3C840200 */  dsll32     $16, $2, 16
    /* 1C32D4 002C32D4 3F841000 */  dsra32     $16, $16, 16
    /* 1C32D8 002C32D8 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C32DC 002C32DC 38810B0C */  jal        func_002e04e0
    /* 1C32E0 002C32E0 00000000 */   nop
    /* 1C32E4 002C32E4 020150A4 */  sh         $16, 0x102($2)
    /* 1C32E8 002C32E8 6400103C */  lui        $16, %hi(D_0063F780)
    /* 1C32EC 002C32EC 80F71026 */  addiu      $16, $16, %lo(D_0063F780)
    /* 1C32F0 002C32F0 B804A427 */  addiu      $4, $29, 0x4B8
    /* 1C32F4 002C32F4 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C32F8 002C32F8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C32FC 002C32FC 5CCA0A0C */  jal        func_002b2970
    /* 1C3300 002C3300 00000000 */   nop
    /* 1C3304 002C3304 02C3023C */  lui        $2, (0xC3020000 >> 16)
    /* 1C3308 002C3308 00608244 */  mtc1       $2, $f12
    /* 1C330C 002C330C 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C3310 002C3310 4842023C */  lui        $2, (0x42480000 >> 16)
    /* 1C3314 002C3314 00008244 */  mtc1       $2, $f0
    /* 1C3318 002C3318 00000000 */  nop
    /* 1C331C 002C331C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C3320 002C3320 B004A427 */  addiu      $4, $29, 0x4B0
    /* 1C3324 002C3324 5CCA0A0C */  jal        func_002b2970
    /* 1C3328 002C3328 00000000 */   nop
    /* 1C332C 002C332C 480D248E */  lw         $4, 0xD48($17)
    /* 1C3330 002C3330 B804A5DF */  ld         $5, 0x4B8($29)
    /* 1C3334 002C3334 B004A6DF */  ld         $6, 0x4B0($29)
    /* 1C3338 002C3338 2D380000 */  daddu      $7, $0, $0
    /* 1C333C 002C333C 07000824 */  addiu      $8, $0, 0x7
    /* 1C3340 002C3340 03000924 */  addiu      $9, $0, 0x3
    /* 1C3344 002C3344 88810B0C */  jal        func_002e0620
    /* 1C3348 002C3348 00000000 */   nop
    /* 1C334C 002C334C 00608044 */  mtc1       $0, $f12
    /* 1C3350 002C3350 A0C1023C */  lui        $2, (0xC1A00000 >> 16)
    /* 1C3354 002C3354 00688244 */  mtc1       $2, $f13
    /* 1C3358 002C3358 480D248E */  lw         $4, 0xD48($17)
    /* 1C335C 002C335C 2D280000 */  daddu      $5, $0, $0
    /* 1C3360 002C3360 07000624 */  addiu      $6, $0, 0x7
    /* 1C3364 002C3364 03000724 */  addiu      $7, $0, 0x3
    /* 1C3368 002C3368 50820B0C */  jal        func_002e0940
    /* 1C336C 002C336C 00000000 */   nop
    /* 1C3370 002C3370 6400103C */  lui        $16, %hi(D_0063F778)
    /* 1C3374 002C3374 78F71026 */  addiu      $16, $16, %lo(D_0063F778)
    /* 1C3378 002C3378 A804A427 */  addiu      $4, $29, 0x4A8
    /* 1C337C 002C337C 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3380 002C3380 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C3384 002C3384 5CCA0A0C */  jal        func_002b2970
    /* 1C3388 002C3388 00000000 */   nop
    /* 1C338C 002C338C 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1C3390 002C3390 4843023C */  lui        $2, (0x43480000 >> 16)
    /* 1C3394 002C3394 00008244 */  mtc1       $2, $f0
    /* 1C3398 002C3398 00000000 */  nop
    /* 1C339C 002C339C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C33A0 002C33A0 02C3023C */  lui        $2, (0xC3020000 >> 16)
    /* 1C33A4 002C33A4 00688244 */  mtc1       $2, $f13
    /* 1C33A8 002C33A8 A004A427 */  addiu      $4, $29, 0x4A0
    /* 1C33AC 002C33AC 5CCA0A0C */  jal        func_002b2970
    /* 1C33B0 002C33B0 00000000 */   nop
    /* 1C33B4 002C33B4 440D248E */  lw         $4, 0xD44($17)
    /* 1C33B8 002C33B8 A804A5DF */  ld         $5, 0x4A8($29)
    /* 1C33BC 002C33BC A004A6DF */  ld         $6, 0x4A0($29)
    /* 1C33C0 002C33C0 2D380000 */  daddu      $7, $0, $0
    /* 1C33C4 002C33C4 07000824 */  addiu      $8, $0, 0x7
    /* 1C33C8 002C33C8 03000924 */  addiu      $9, $0, 0x3
    /* 1C33CC 002C33CC 88810B0C */  jal        func_002e0620
    /* 1C33D0 002C33D0 00000000 */   nop
    /* 1C33D4 002C33D4 00608044 */  mtc1       $0, $f12
    /* 1C33D8 002C33D8 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1C33DC 002C33DC 00688244 */  mtc1       $2, $f13
    /* 1C33E0 002C33E0 440D248E */  lw         $4, 0xD44($17)
    /* 1C33E4 002C33E4 2D280000 */  daddu      $5, $0, $0
    /* 1C33E8 002C33E8 07000624 */  addiu      $6, $0, 0x7
    /* 1C33EC 002C33EC 03000724 */  addiu      $7, $0, 0x3
    /* 1C33F0 002C33F0 50820B0C */  jal        func_002e0940
    /* 1C33F4 002C33F4 00000000 */   nop
    /* 1C33F8 002C33F8 6400103C */  lui        $16, %hi(D_0063F788)
    /* 1C33FC 002C33FC 88F71026 */  addiu      $16, $16, %lo(D_0063F788)
    /* 1C3400 002C3400 9804A427 */  addiu      $4, $29, 0x498
    /* 1C3404 002C3404 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3408 002C3408 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C340C 002C340C 5CCA0A0C */  jal        func_002b2970
    /* 1C3410 002C3410 00000000 */   nop
    /* 1C3414 002C3414 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1C3418 002C3418 2042023C */  lui        $2, (0x42200000 >> 16)
    /* 1C341C 002C341C 00008244 */  mtc1       $2, $f0
    /* 1C3420 002C3420 00000000 */  nop
    /* 1C3424 002C3424 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C3428 002C3428 26020224 */  addiu      $2, $0, 0x226
    /* 1C342C 002C342C 00008244 */  mtc1       $2, $f0
    /* 1C3430 002C3430 00000000 */  nop
    /* 1C3434 002C3434 60038046 */  cvt.s.w    $f13, $f0
    /* 1C3438 002C3438 9004A427 */  addiu      $4, $29, 0x490
    /* 1C343C 002C343C 5CCA0A0C */  jal        func_002b2970
    /* 1C3440 002C3440 00000000 */   nop
    /* 1C3444 002C3444 4C0D248E */  lw         $4, 0xD4C($17)
    /* 1C3448 002C3448 9804A5DF */  ld         $5, 0x498($29)
    /* 1C344C 002C344C 9004A6DF */  ld         $6, 0x490($29)
    /* 1C3450 002C3450 2D380000 */  daddu      $7, $0, $0
    /* 1C3454 002C3454 07000824 */  addiu      $8, $0, 0x7
    /* 1C3458 002C3458 03000924 */  addiu      $9, $0, 0x3
    /* 1C345C 002C345C 88810B0C */  jal        func_002e0620
    /* 1C3460 002C3460 00000000 */   nop
    /* 1C3464 002C3464 00608044 */  mtc1       $0, $f12
    /* 1C3468 002C3468 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1C346C 002C346C 00688244 */  mtc1       $2, $f13
    /* 1C3470 002C3470 4C0D248E */  lw         $4, 0xD4C($17)
    /* 1C3474 002C3474 2D280000 */  daddu      $5, $0, $0
    /* 1C3478 002C3478 07000624 */  addiu      $6, $0, 0x7
    /* 1C347C 002C347C 03000724 */  addiu      $7, $0, 0x3
    /* 1C3480 002C3480 50820B0C */  jal        func_002e0940
    /* 1C3484 002C3484 00000000 */   nop
    /* 1C3488 002C3488 6400103C */  lui        $16, %hi(D_0063F798)
    /* 1C348C 002C348C 98F71026 */  addiu      $16, $16, %lo(D_0063F798)
    /* 1C3490 002C3490 8804A427 */  addiu      $4, $29, 0x488
    /* 1C3494 002C3494 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3498 002C3498 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C349C 002C349C 5CCA0A0C */  jal        func_002b2970
    /* 1C34A0 002C34A0 00000000 */   nop
    /* 1C34A4 002C34A4 2042023C */  lui        $2, (0x42200000 >> 16)
    /* 1C34A8 002C34A8 00088244 */  mtc1       $2, $f1
    /* 1C34AC 002C34AC 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C34B0 002C34B0 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C34B4 002C34B4 26020224 */  addiu      $2, $0, 0x226
    /* 1C34B8 002C34B8 00008244 */  mtc1       $2, $f0
    /* 1C34BC 002C34BC 00000000 */  nop
    /* 1C34C0 002C34C0 60038046 */  cvt.s.w    $f13, $f0
    /* 1C34C4 002C34C4 8004A427 */  addiu      $4, $29, 0x480
    /* 1C34C8 002C34C8 5CCA0A0C */  jal        func_002b2970
    /* 1C34CC 002C34CC 00000000 */   nop
    /* 1C34D0 002C34D0 540D248E */  lw         $4, 0xD54($17)
    /* 1C34D4 002C34D4 8804A5DF */  ld         $5, 0x488($29)
    /* 1C34D8 002C34D8 8004A6DF */  ld         $6, 0x480($29)
    /* 1C34DC 002C34DC 2D380000 */  daddu      $7, $0, $0
    /* 1C34E0 002C34E0 07000824 */  addiu      $8, $0, 0x7
    /* 1C34E4 002C34E4 03000924 */  addiu      $9, $0, 0x3
    /* 1C34E8 002C34E8 88810B0C */  jal        func_002e0620
    /* 1C34EC 002C34EC 00000000 */   nop
    /* 1C34F0 002C34F0 00608044 */  mtc1       $0, $f12
    /* 1C34F4 002C34F4 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1C34F8 002C34F8 00688244 */  mtc1       $2, $f13
    /* 1C34FC 002C34FC 540D248E */  lw         $4, 0xD54($17)
    /* 1C3500 002C3500 2D280000 */  daddu      $5, $0, $0
    /* 1C3504 002C3504 07000624 */  addiu      $6, $0, 0x7
    /* 1C3508 002C3508 03000724 */  addiu      $7, $0, 0x3
    /* 1C350C 002C350C 50820B0C */  jal        func_002e0940
    /* 1C3510 002C3510 00000000 */   nop
    /* 1C3514 002C3514 6400103C */  lui        $16, %hi(D_0063F790)
    /* 1C3518 002C3518 90F71026 */  addiu      $16, $16, %lo(D_0063F790)
    /* 1C351C 002C351C 7804A427 */  addiu      $4, $29, 0x478
    /* 1C3520 002C3520 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3524 002C3524 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C3528 002C3528 5CCA0A0C */  jal        func_002b2970
    /* 1C352C 002C352C 00000000 */   nop
    /* 1C3530 002C3530 2042023C */  lui        $2, (0x42200000 >> 16)
    /* 1C3534 002C3534 00088244 */  mtc1       $2, $f1
    /* 1C3538 002C3538 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C353C 002C353C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C3540 002C3540 16C3023C */  lui        $2, (0xC3160000 >> 16)
    /* 1C3544 002C3544 00688244 */  mtc1       $2, $f13
    /* 1C3548 002C3548 7004A427 */  addiu      $4, $29, 0x470
    /* 1C354C 002C354C 5CCA0A0C */  jal        func_002b2970
    /* 1C3550 002C3550 00000000 */   nop
    /* 1C3554 002C3554 500D248E */  lw         $4, 0xD50($17)
    /* 1C3558 002C3558 7804A5DF */  ld         $5, 0x478($29)
    /* 1C355C 002C355C 7004A6DF */  ld         $6, 0x470($29)
    /* 1C3560 002C3560 2D380000 */  daddu      $7, $0, $0
    /* 1C3564 002C3564 07000824 */  addiu      $8, $0, 0x7
    /* 1C3568 002C3568 03000924 */  addiu      $9, $0, 0x3
    /* 1C356C 002C356C 88810B0C */  jal        func_002e0620
    /* 1C3570 002C3570 00000000 */   nop
    /* 1C3574 002C3574 00608044 */  mtc1       $0, $f12
    /* 1C3578 002C3578 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1C357C 002C357C 00688244 */  mtc1       $2, $f13
    /* 1C3580 002C3580 500D248E */  lw         $4, 0xD50($17)
    /* 1C3584 002C3584 2D280000 */  daddu      $5, $0, $0
    /* 1C3588 002C3588 07000624 */  addiu      $6, $0, 0x7
    /* 1C358C 002C358C 03000724 */  addiu      $7, $0, 0x3
    /* 1C3590 002C3590 50820B0C */  jal        func_002e0940
    /* 1C3594 002C3594 00000000 */   nop
    /* 1C3598 002C3598 6400103C */  lui        $16, %hi(D_0063F7A0)
    /* 1C359C 002C359C A0F71026 */  addiu      $16, $16, %lo(D_0063F7A0)
    /* 1C35A0 002C35A0 6804A427 */  addiu      $4, $29, 0x468
    /* 1C35A4 002C35A4 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C35A8 002C35A8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C35AC 002C35AC 5CCA0A0C */  jal        func_002b2970
    /* 1C35B0 002C35B0 00000000 */   nop
    /* 1C35B4 002C35B4 2042023C */  lui        $2, (0x42200000 >> 16)
    /* 1C35B8 002C35B8 00088244 */  mtc1       $2, $f1
    /* 1C35BC 002C35BC 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C35C0 002C35C0 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C35C4 002C35C4 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1C35C8 002C35C8 00688244 */  mtc1       $2, $f13
    /* 1C35CC 002C35CC 6004A427 */  addiu      $4, $29, 0x460
    /* 1C35D0 002C35D0 5CCA0A0C */  jal        func_002b2970
    /* 1C35D4 002C35D4 00000000 */   nop
    /* 1C35D8 002C35D8 580D248E */  lw         $4, 0xD58($17)
    /* 1C35DC 002C35DC 6804A5DF */  ld         $5, 0x468($29)
    /* 1C35E0 002C35E0 6004A6DF */  ld         $6, 0x460($29)
    /* 1C35E4 002C35E4 2D380000 */  daddu      $7, $0, $0
    /* 1C35E8 002C35E8 07000824 */  addiu      $8, $0, 0x7
    /* 1C35EC 002C35EC 03000924 */  addiu      $9, $0, 0x3
    /* 1C35F0 002C35F0 88810B0C */  jal        func_002e0620
    /* 1C35F4 002C35F4 00000000 */   nop
    /* 1C35F8 002C35F8 00608044 */  mtc1       $0, $f12
    /* 1C35FC 002C35FC A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1C3600 002C3600 00688244 */  mtc1       $2, $f13
    /* 1C3604 002C3604 580D248E */  lw         $4, 0xD58($17)
    /* 1C3608 002C3608 2D280000 */  daddu      $5, $0, $0
    /* 1C360C 002C360C 07000624 */  addiu      $6, $0, 0x7
    /* 1C3610 002C3610 03000724 */  addiu      $7, $0, 0x3
    /* 1C3614 002C3614 50820B0C */  jal        func_002e0940
    /* 1C3618 002C3618 00000000 */   nop
    /* 1C361C 002C361C 6400103C */  lui        $16, %hi(D_0063F7B0)
    /* 1C3620 002C3620 B0F71026 */  addiu      $16, $16, %lo(D_0063F7B0)
    /* 1C3624 002C3624 5804A427 */  addiu      $4, $29, 0x458
    /* 1C3628 002C3628 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C362C 002C362C 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C3630 002C3630 5CCA0A0C */  jal        func_002b2970
    /* 1C3634 002C3634 00000000 */   nop
    /* 1C3638 002C3638 9E020224 */  addiu      $2, $0, 0x29E
    /* 1C363C 002C363C 00008244 */  mtc1       $2, $f0
    /* 1C3640 002C3640 00000000 */  nop
    /* 1C3644 002C3644 60008046 */  cvt.s.w    $f1, $f0
    /* 1C3648 002C3648 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C364C 002C364C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C3650 002C3650 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C3654 002C3654 9643023C */  lui        $2, (0x43960000 >> 16)
    /* 1C3658 002C3658 00008244 */  mtc1       $2, $f0
    /* 1C365C 002C365C 00000000 */  nop
    /* 1C3660 002C3660 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C3664 002C3664 5004A427 */  addiu      $4, $29, 0x450
    /* 1C3668 002C3668 5CCA0A0C */  jal        func_002b2970
    /* 1C366C 002C366C 00000000 */   nop
    /* 1C3670 002C3670 600D248E */  lw         $4, 0xD60($17)
    /* 1C3674 002C3674 5804A5DF */  ld         $5, 0x458($29)
    /* 1C3678 002C3678 5004A6DF */  ld         $6, 0x450($29)
    /* 1C367C 002C367C 01000724 */  addiu      $7, $0, 0x1
    /* 1C3680 002C3680 0A000824 */  addiu      $8, $0, 0xA
    /* 1C3684 002C3684 03000924 */  addiu      $9, $0, 0x3
    /* 1C3688 002C3688 88810B0C */  jal        func_002e0620
    /* 1C368C 002C368C 00000000 */   nop
    /* 1C3690 002C3690 7042023C */  lui        $2, (0x42700000 >> 16)
    /* 1C3694 002C3694 00688244 */  mtc1       $2, $f13
    /* 1C3698 002C3698 600D248E */  lw         $4, 0xD60($17)
    /* 1C369C 002C369C 2C858CC7 */  lwc1       $f12, -0x7AD4($28)
    /* 1C36A0 002C36A0 01000524 */  addiu      $5, $0, 0x1
    /* 1C36A4 002C36A4 04000624 */  addiu      $6, $0, 0x4
    /* 1C36A8 002C36A8 03000724 */  addiu      $7, $0, 0x3
    /* 1C36AC 002C36AC 50820B0C */  jal        func_002e0940
    /* 1C36B0 002C36B0 00000000 */   nop
    /* 1C36B4 002C36B4 6400103C */  lui        $16, %hi(D_0063F7B8)
    /* 1C36B8 002C36B8 B8F71026 */  addiu      $16, $16, %lo(D_0063F7B8)
    /* 1C36BC 002C36BC 4804A427 */  addiu      $4, $29, 0x448
    /* 1C36C0 002C36C0 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C36C4 002C36C4 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C36C8 002C36C8 5CCA0A0C */  jal        func_002b2970
    /* 1C36CC 002C36CC 00000000 */   nop
    /* 1C36D0 002C36D0 9E020224 */  addiu      $2, $0, 0x29E
    /* 1C36D4 002C36D4 00008244 */  mtc1       $2, $f0
    /* 1C36D8 002C36D8 00000000 */  nop
    /* 1C36DC 002C36DC 60008046 */  cvt.s.w    $f1, $f0
    /* 1C36E0 002C36E0 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C36E4 002C36E4 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C36E8 002C36E8 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C36EC 002C36EC 9643023C */  lui        $2, (0x43960000 >> 16)
    /* 1C36F0 002C36F0 00008244 */  mtc1       $2, $f0
    /* 1C36F4 002C36F4 00000000 */  nop
    /* 1C36F8 002C36F8 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C36FC 002C36FC 4004A427 */  addiu      $4, $29, 0x440
    /* 1C3700 002C3700 5CCA0A0C */  jal        func_002b2970
    /* 1C3704 002C3704 00000000 */   nop
    /* 1C3708 002C3708 640D248E */  lw         $4, 0xD64($17)
    /* 1C370C 002C370C 4804A5DF */  ld         $5, 0x448($29)
    /* 1C3710 002C3710 4004A6DF */  ld         $6, 0x440($29)
    /* 1C3714 002C3714 01000724 */  addiu      $7, $0, 0x1
    /* 1C3718 002C3718 04000824 */  addiu      $8, $0, 0x4
    /* 1C371C 002C371C 03000924 */  addiu      $9, $0, 0x3
    /* 1C3720 002C3720 88810B0C */  jal        func_002e0620
    /* 1C3724 002C3724 00000000 */   nop
    /* 1C3728 002C3728 7042023C */  lui        $2, (0x42700000 >> 16)
    /* 1C372C 002C372C 00688244 */  mtc1       $2, $f13
    /* 1C3730 002C3730 640D248E */  lw         $4, 0xD64($17)
    /* 1C3734 002C3734 2C858CC7 */  lwc1       $f12, -0x7AD4($28)
    /* 1C3738 002C3738 01000524 */  addiu      $5, $0, 0x1
    /* 1C373C 002C373C 04000624 */  addiu      $6, $0, 0x4
    /* 1C3740 002C3740 03000724 */  addiu      $7, $0, 0x3
    /* 1C3744 002C3744 50820B0C */  jal        func_002e0940
    /* 1C3748 002C3748 00000000 */   nop
    /* 1C374C 002C374C 6400103C */  lui        $16, %hi(D_0063F5A0)
    /* 1C3750 002C3750 A0F51026 */  addiu      $16, $16, %lo(D_0063F5A0)
    /* 1C3754 002C3754 3804A427 */  addiu      $4, $29, 0x438
    /* 1C3758 002C3758 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C375C 002C375C 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C3760 002C3760 5CCA0A0C */  jal        func_002b2970
    /* 1C3764 002C3764 00000000 */   nop
    /* 1C3768 002C3768 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C376C 002C376C FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1C3770 002C3770 00008244 */  mtc1       $2, $f0
    /* 1C3774 002C3774 00000000 */  nop
    /* 1C3778 002C3778 40030146 */  add.s      $f13, $f0, $f1
    /* 1C377C 002C377C 3004A427 */  addiu      $4, $29, 0x430
    /* 1C3780 002C3780 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3784 002C3784 5CCA0A0C */  jal        func_002b2970
    /* 1C3788 002C3788 00000000 */   nop
    /* 1C378C 002C378C 580C248E */  lw         $4, 0xC58($17)
    /* 1C3790 002C3790 3804A5DF */  ld         $5, 0x438($29)
    /* 1C3794 002C3794 3004A6DF */  ld         $6, 0x430($29)
    /* 1C3798 002C3798 2D380000 */  daddu      $7, $0, $0
    /* 1C379C 002C379C 04000824 */  addiu      $8, $0, 0x4
    /* 1C37A0 002C37A0 2D480000 */  daddu      $9, $0, $0
    /* 1C37A4 002C37A4 88810B0C */  jal        func_002e0620
    /* 1C37A8 002C37A8 00000000 */   nop
    /* 1C37AC 002C37AC 580C248E */  lw         $4, 0xC58($17)
    /* 1C37B0 002C37B0 CC000524 */  addiu      $5, $0, 0xCC
    /* 1C37B4 002C37B4 2D300000 */  daddu      $6, $0, $0
    /* 1C37B8 002C37B8 2D380000 */  daddu      $7, $0, $0
    /* 1C37BC 002C37BC 02000824 */  addiu      $8, $0, 0x2
    /* 1C37C0 002C37C0 2D480000 */  daddu      $9, $0, $0
    /* 1C37C4 002C37C4 98810B0C */  jal        func_002e0660
    /* 1C37C8 002C37C8 00000000 */   nop
    /* 1C37CC 002C37CC 6400103C */  lui        $16, %hi(D_0063F5A8)
    /* 1C37D0 002C37D0 A8F51026 */  addiu      $16, $16, %lo(D_0063F5A8)
    /* 1C37D4 002C37D4 2804A427 */  addiu      $4, $29, 0x428
    /* 1C37D8 002C37D8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C37DC 002C37DC 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C37E0 002C37E0 5CCA0A0C */  jal        func_002b2970
    /* 1C37E4 002C37E4 00000000 */   nop
    /* 1C37E8 002C37E8 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C37EC 002C37EC FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1C37F0 002C37F0 00008244 */  mtc1       $2, $f0
    /* 1C37F4 002C37F4 00000000 */  nop
    /* 1C37F8 002C37F8 40030146 */  add.s      $f13, $f0, $f1
    /* 1C37FC 002C37FC 2004A427 */  addiu      $4, $29, 0x420
    /* 1C3800 002C3800 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3804 002C3804 5CCA0A0C */  jal        func_002b2970
    /* 1C3808 002C3808 00000000 */   nop
    /* 1C380C 002C380C 5C0C248E */  lw         $4, 0xC5C($17)
    /* 1C3810 002C3810 2804A5DF */  ld         $5, 0x428($29)
    /* 1C3814 002C3814 2004A6DF */  ld         $6, 0x420($29)
    /* 1C3818 002C3818 2D380000 */  daddu      $7, $0, $0
    /* 1C381C 002C381C 04000824 */  addiu      $8, $0, 0x4
    /* 1C3820 002C3820 2D480000 */  daddu      $9, $0, $0
    /* 1C3824 002C3824 88810B0C */  jal        func_002e0620
    /* 1C3828 002C3828 00000000 */   nop
    /* 1C382C 002C382C 5C0C248E */  lw         $4, 0xC5C($17)
    /* 1C3830 002C3830 CC000524 */  addiu      $5, $0, 0xCC
    /* 1C3834 002C3834 2D300000 */  daddu      $6, $0, $0
    /* 1C3838 002C3838 2D380000 */  daddu      $7, $0, $0
    /* 1C383C 002C383C 02000824 */  addiu      $8, $0, 0x2
    /* 1C3840 002C3840 2D480000 */  daddu      $9, $0, $0
    /* 1C3844 002C3844 98810B0C */  jal        func_002e0660
    /* 1C3848 002C3848 00000000 */   nop
    /* 1C384C 002C384C 3C0D248E */  lw         $4, 0xD3C($17)
    /* 1C3850 002C3850 2D280000 */  daddu      $5, $0, $0
    /* 1C3854 002C3854 01000624 */  addiu      $6, $0, 0x1
    /* 1C3858 002C3858 3C810B0C */  jal        func_002e04f0
    /* 1C385C 002C385C 00000000 */   nop
    /* 1C3860 002C3860 D40E248E */  lw         $4, 0xED4($17)
    /* 1C3864 002C3864 2D280000 */  daddu      $5, $0, $0
    /* 1C3868 002C3868 01000624 */  addiu      $6, $0, 0x1
    /* 1C386C 002C386C 3C810B0C */  jal        func_002e04f0
    /* 1C3870 002C3870 00000000 */   nop
    /* 1C3874 002C3874 D80E248E */  lw         $4, 0xED8($17)
    /* 1C3878 002C3878 2D280000 */  daddu      $5, $0, $0
    /* 1C387C 002C387C 01000624 */  addiu      $6, $0, 0x1
    /* 1C3880 002C3880 3C810B0C */  jal        func_002e04f0
    /* 1C3884 002C3884 00000000 */   nop
    /* 1C3888 002C3888 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C388C 002C388C 2D280000 */  daddu      $5, $0, $0
    /* 1C3890 002C3890 01000624 */  addiu      $6, $0, 0x1
    /* 1C3894 002C3894 3C810B0C */  jal        func_002e04f0
    /* 1C3898 002C3898 00000000 */   nop
    /* 1C389C 002C389C F00D248E */  lw         $4, 0xDF0($17)
    /* 1C38A0 002C38A0 2D280000 */  daddu      $5, $0, $0
    /* 1C38A4 002C38A4 01000624 */  addiu      $6, $0, 0x1
    /* 1C38A8 002C38A8 3C810B0C */  jal        func_002e04f0
    /* 1C38AC 002C38AC 00000000 */   nop
    /* 1C38B0 002C38B0 17000224 */  addiu      $2, $0, 0x17
    /* 1C38B4 002C38B4 000022A2 */  sb         $2, 0x0($17)
    /* 1C38B8 002C38B8 9B1B0010 */  b          .L002CA728
    /* 1C38BC 002C38BC 00000000 */   nop
    /* 1C38C0 002C38C0 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C38C4 002C38C4 03000524 */  addiu      $5, $0, 0x3
    /* 1C38C8 002C38C8 5C810B0C */  jal        func_002e0570
    /* 1C38CC 002C38CC 00000000 */   nop
    /* 1C38D0 002C38D0 3C160200 */  dsll32     $2, $2, 24
    /* 1C38D4 002C38D4 3F160200 */  dsra32     $2, $2, 24
    /* 1C38D8 002C38D8 931B4014 */  bnez       $2, .L002CA728
    /* 1C38DC 002C38DC 00000000 */   nop
    /* 1C38E0 002C38E0 D841023C */  lui        $2, (0x41D80000 >> 16)
    /* 1C38E4 002C38E4 00608244 */  mtc1       $2, $f12
    /* 1C38E8 002C38E8 60C1023C */  lui        $2, (0xC1600000 >> 16)
    /* 1C38EC 002C38EC 00688244 */  mtc1       $2, $f13
    /* 1C38F0 002C38F0 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C38F4 002C38F4 2D280000 */  daddu      $5, $0, $0
    /* 1C38F8 002C38F8 03000624 */  addiu      $6, $0, 0x3
    /* 1C38FC 002C38FC 2D380000 */  daddu      $7, $0, $0
    /* 1C3900 002C3900 50820B0C */  jal        func_002e0940
    /* 1C3904 002C3904 00000000 */   nop
    /* 1C3908 002C3908 6400103C */  lui        $16, %hi(D_0063F5B8)
    /* 1C390C 002C390C B8F51026 */  addiu      $16, $16, %lo(D_0063F5B8)
    /* 1C3910 002C3910 1D43023C */  lui        $2, (0x431D0000 >> 16)
    /* 1C3914 002C3914 00608244 */  mtc1       $2, $f12
    /* 1C3918 002C3918 640C248E */  lw         $4, 0xC64($17)
    /* 1C391C 002C391C 41000524 */  addiu      $5, $0, 0x41
    /* 1C3920 002C3920 78820B0C */  jal        func_002e09e0
    /* 1C3924 002C3924 00000000 */   nop
    /* 1C3928 002C3928 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C392C 002C392C 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1C3930 002C3930 00008244 */  mtc1       $2, $f0
    /* 1C3934 002C3934 00000000 */  nop
    /* 1C3938 002C3938 40030146 */  add.s      $f13, $f0, $f1
    /* 1C393C 002C393C 1804A427 */  addiu      $4, $29, 0x418
    /* 1C3940 002C3940 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3944 002C3944 5CCA0A0C */  jal        func_002b2970
    /* 1C3948 002C3948 00000000 */   nop
    /* 1C394C 002C394C 1004A427 */  addiu      $4, $29, 0x410
    /* 1C3950 002C3950 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C3954 002C3954 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C3958 002C3958 5CCA0A0C */  jal        func_002b2970
    /* 1C395C 002C395C 00000000 */   nop
    /* 1C3960 002C3960 640C248E */  lw         $4, 0xC64($17)
    /* 1C3964 002C3964 1804A5DF */  ld         $5, 0x418($29)
    /* 1C3968 002C3968 1004A6DF */  ld         $6, 0x410($29)
    /* 1C396C 002C396C 2D380000 */  daddu      $7, $0, $0
    /* 1C3970 002C3970 07000824 */  addiu      $8, $0, 0x7
    /* 1C3974 002C3974 2D480000 */  daddu      $9, $0, $0
    /* 1C3978 002C3978 88810B0C */  jal        func_002e0620
    /* 1C397C 002C397C 00000000 */   nop
    /* 1C3980 002C3980 640C248E */  lw         $4, 0xC64($17)
    /* 1C3984 002C3984 2D280000 */  daddu      $5, $0, $0
    /* 1C3988 002C3988 CC000624 */  addiu      $6, $0, 0xCC
    /* 1C398C 002C398C 2D380000 */  daddu      $7, $0, $0
    /* 1C3990 002C3990 07000824 */  addiu      $8, $0, 0x7
    /* 1C3994 002C3994 2D480000 */  daddu      $9, $0, $0
    /* 1C3998 002C3998 98810B0C */  jal        func_002e0660
    /* 1C399C 002C399C 00000000 */   nop
    /* 1C39A0 002C39A0 3807A427 */  addiu      $4, $29, 0x738
    /* 1C39A4 002C39A4 2D280000 */  daddu      $5, $0, $0
    /* 1C39A8 002C39A8 2D300000 */  daddu      $6, $0, $0
    /* 1C39AC 002C39AC 2D380000 */  daddu      $7, $0, $0
    /* 1C39B0 002C39B0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C39B4 002C39B4 98CA0A0C */  jal        func_002b2a60
    /* 1C39B8 002C39B8 00000000 */   nop
    /* 1C39BC 002C39BC 640C248E */  lw         $4, 0xC64($17)
    /* 1C39C0 002C39C0 38810B0C */  jal        func_002e04e0
    /* 1C39C4 002C39C4 00000000 */   nop
    /* 1C39C8 002C39C8 3807A693 */  lbu        $6, 0x738($29)
    /* 1C39CC 002C39CC 3907A593 */  lbu        $5, 0x739($29)
    /* 1C39D0 002C39D0 3A07A493 */  lbu        $4, 0x73A($29)
    /* 1C39D4 002C39D4 3B07A393 */  lbu        $3, 0x73B($29)
    /* 1C39D8 002C39D8 790046A0 */  sb         $6, 0x79($2)
    /* 1C39DC 002C39DC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C39E0 002C39E0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C39E4 002C39E4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C39E8 002C39E8 00608044 */  mtc1       $0, $f12
    /* 1C39EC 002C39EC 80C0023C */  lui        $2, (0xC0800000 >> 16)
    /* 1C39F0 002C39F0 00688244 */  mtc1       $2, $f13
    /* 1C39F4 002C39F4 640C248E */  lw         $4, 0xC64($17)
    /* 1C39F8 002C39F8 2D280000 */  daddu      $5, $0, $0
    /* 1C39FC 002C39FC 2D300000 */  daddu      $6, $0, $0
    /* 1C3A00 002C3A00 2D380000 */  daddu      $7, $0, $0
    /* 1C3A04 002C3A04 50820B0C */  jal        func_002e0940
    /* 1C3A08 002C3A08 00000000 */   nop
    /* 1C3A0C 002C3A0C A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 1C3A10 002C3A10 00088244 */  mtc1       $2, $f1
    /* 1C3A14 002C3A14 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C3A18 002C3A18 01080046 */  sub.s      $f0, $f1, $f0
    /* 1C3A1C 002C3A1C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C3A20 002C3A20 00000244 */  mfc1       $2, $f0
    /* 1C3A24 002C3A24 00000000 */  nop
    /* 1C3A28 002C3A28 3C940200 */  dsll32     $18, $2, 16
    /* 1C3A2C 002C3A2C 3F941200 */  dsra32     $18, $18, 16
    /* 1C3A30 002C3A30 640C248E */  lw         $4, 0xC64($17)
    /* 1C3A34 002C3A34 38810B0C */  jal        func_002e04e0
    /* 1C3A38 002C3A38 00000000 */   nop
    /* 1C3A3C 002C3A3C 000152A4 */  sh         $18, 0x100($2)
    /* 1C3A40 002C3A40 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C3A44 002C3A44 A642023C */  lui        $2, (0x42A60000 >> 16)
    /* 1C3A48 002C3A48 00008244 */  mtc1       $2, $f0
    /* 1C3A4C 002C3A4C 00000000 */  nop
    /* 1C3A50 002C3A50 01080046 */  sub.s      $f0, $f1, $f0
    /* 1C3A54 002C3A54 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C3A58 002C3A58 00000244 */  mfc1       $2, $f0
    /* 1C3A5C 002C3A5C 00000000 */  nop
    /* 1C3A60 002C3A60 3C840200 */  dsll32     $16, $2, 16
    /* 1C3A64 002C3A64 3F841000 */  dsra32     $16, $16, 16
    /* 1C3A68 002C3A68 640C248E */  lw         $4, 0xC64($17)
    /* 1C3A6C 002C3A6C 38810B0C */  jal        func_002e04e0
    /* 1C3A70 002C3A70 00000000 */   nop
    /* 1C3A74 002C3A74 020150A4 */  sh         $16, 0x102($2)
    /* 1C3A78 002C3A78 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C3A7C 002C3A7C 00608244 */  mtc1       $2, $f12
    /* 1C3A80 002C3A80 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* 1C3A84 002C3A84 00688244 */  mtc1       $2, $f13
    /* 1C3A88 002C3A88 640C248E */  lw         $4, 0xC64($17)
    /* 1C3A8C 002C3A8C 86630046 */  mov.s      $f14, $f12
    /* 1C3A90 002C3A90 C6630046 */  mov.s      $f15, $f12
    /* 1C3A94 002C3A94 2D280000 */  daddu      $5, $0, $0
    /* 1C3A98 002C3A98 2D300000 */  daddu      $6, $0, $0
    /* 1C3A9C 002C3A9C 2D380000 */  daddu      $7, $0, $0
    /* 1C3AA0 002C3AA0 B4810B0C */  jal        func_002e06d0
    /* 1C3AA4 002C3AA4 00000000 */   nop
    /* 1C3AA8 002C3AA8 18000224 */  addiu      $2, $0, 0x18
    /* 1C3AAC 002C3AAC 000022A2 */  sb         $2, 0x0($17)
    /* 1C3AB0 002C3AB0 1D1B0010 */  b          .L002CA728
    /* 1C3AB4 002C3AB4 00000000 */   nop
    /* 1C3AB8 002C3AB8 640C248E */  lw         $4, 0xC64($17)
    /* 1C3ABC 002C3ABC 68810B0C */  jal        func_002e05a0
    /* 1C3AC0 002C3AC0 00000000 */   nop
    /* 1C3AC4 002C3AC4 3C160200 */  dsll32     $2, $2, 24
    /* 1C3AC8 002C3AC8 3F160200 */  dsra32     $2, $2, 24
    /* 1C3ACC 002C3ACC 161B4014 */  bnez       $2, .L002CA728
    /* 1C3AD0 002C3AD0 00000000 */   nop
    /* 1C3AD4 002C3AD4 1843023C */  lui        $2, (0x43180000 >> 16)
    /* 1C3AD8 002C3AD8 00608244 */  mtc1       $2, $f12
    /* 1C3ADC 002C3ADC 2C0E248E */  lw         $4, 0xE2C($17)
    /* 1C3AE0 002C3AE0 41000524 */  addiu      $5, $0, 0x41
    /* 1C3AE4 002C3AE4 78820B0C */  jal        func_002e09e0
    /* 1C3AE8 002C3AE8 00000000 */   nop
    /* 1C3AEC 002C3AEC 2C0E248E */  lw         $4, 0xE2C($17)
    /* 1C3AF0 002C3AF0 2D280000 */  daddu      $5, $0, $0
    /* 1C3AF4 002C3AF4 CC000624 */  addiu      $6, $0, 0xCC
    /* 1C3AF8 002C3AF8 2D380000 */  daddu      $7, $0, $0
    /* 1C3AFC 002C3AFC 05000824 */  addiu      $8, $0, 0x5
    /* 1C3B00 002C3B00 2D480000 */  daddu      $9, $0, $0
    /* 1C3B04 002C3B04 98810B0C */  jal        func_002e0660
    /* 1C3B08 002C3B08 00000000 */   nop
    /* 1C3B0C 002C3B0C 3407A427 */  addiu      $4, $29, 0x734
    /* 1C3B10 002C3B10 2D280000 */  daddu      $5, $0, $0
    /* 1C3B14 002C3B14 2D300000 */  daddu      $6, $0, $0
    /* 1C3B18 002C3B18 2D380000 */  daddu      $7, $0, $0
    /* 1C3B1C 002C3B1C FF000824 */  addiu      $8, $0, 0xFF
    /* 1C3B20 002C3B20 98CA0A0C */  jal        func_002b2a60
    /* 1C3B24 002C3B24 00000000 */   nop
    /* 1C3B28 002C3B28 2C0E248E */  lw         $4, 0xE2C($17)
    /* 1C3B2C 002C3B2C 38810B0C */  jal        func_002e04e0
    /* 1C3B30 002C3B30 00000000 */   nop
    /* 1C3B34 002C3B34 3407A693 */  lbu        $6, 0x734($29)
    /* 1C3B38 002C3B38 3507A593 */  lbu        $5, 0x735($29)
    /* 1C3B3C 002C3B3C 3607A493 */  lbu        $4, 0x736($29)
    /* 1C3B40 002C3B40 3707A393 */  lbu        $3, 0x737($29)
    /* 1C3B44 002C3B44 790046A0 */  sb         $6, 0x79($2)
    /* 1C3B48 002C3B48 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C3B4C 002C3B4C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C3B50 002C3B50 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C3B54 002C3B54 1843023C */  lui        $2, (0x43180000 >> 16)
    /* 1C3B58 002C3B58 00608244 */  mtc1       $2, $f12
    /* 1C3B5C 002C3B5C 300E248E */  lw         $4, 0xE30($17)
    /* 1C3B60 002C3B60 41000524 */  addiu      $5, $0, 0x41
    /* 1C3B64 002C3B64 78820B0C */  jal        func_002e09e0
    /* 1C3B68 002C3B68 00000000 */   nop
    /* 1C3B6C 002C3B6C 300E248E */  lw         $4, 0xE30($17)
    /* 1C3B70 002C3B70 2D280000 */  daddu      $5, $0, $0
    /* 1C3B74 002C3B74 CC000624 */  addiu      $6, $0, 0xCC
    /* 1C3B78 002C3B78 2D380000 */  daddu      $7, $0, $0
    /* 1C3B7C 002C3B7C 05000824 */  addiu      $8, $0, 0x5
    /* 1C3B80 002C3B80 2D480000 */  daddu      $9, $0, $0
    /* 1C3B84 002C3B84 98810B0C */  jal        func_002e0660
    /* 1C3B88 002C3B88 00000000 */   nop
    /* 1C3B8C 002C3B8C 3007A427 */  addiu      $4, $29, 0x730
    /* 1C3B90 002C3B90 2D280000 */  daddu      $5, $0, $0
    /* 1C3B94 002C3B94 2D300000 */  daddu      $6, $0, $0
    /* 1C3B98 002C3B98 2D380000 */  daddu      $7, $0, $0
    /* 1C3B9C 002C3B9C FF000824 */  addiu      $8, $0, 0xFF
    /* 1C3BA0 002C3BA0 98CA0A0C */  jal        func_002b2a60
    /* 1C3BA4 002C3BA4 00000000 */   nop
    /* 1C3BA8 002C3BA8 300E248E */  lw         $4, 0xE30($17)
    /* 1C3BAC 002C3BAC 38810B0C */  jal        func_002e04e0
    /* 1C3BB0 002C3BB0 00000000 */   nop
    /* 1C3BB4 002C3BB4 3007A693 */  lbu        $6, 0x730($29)
    /* 1C3BB8 002C3BB8 3107A593 */  lbu        $5, 0x731($29)
    /* 1C3BBC 002C3BBC 3207A493 */  lbu        $4, 0x732($29)
    /* 1C3BC0 002C3BC0 3307A393 */  lbu        $3, 0x733($29)
    /* 1C3BC4 002C3BC4 790046A0 */  sb         $6, 0x79($2)
    /* 1C3BC8 002C3BC8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C3BCC 002C3BCC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C3BD0 002C3BD0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C3BD4 002C3BD4 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1C3BD8 002C3BD8 00608244 */  mtc1       $2, $f12
    /* 1C3BDC 002C3BDC 700D248E */  lw         $4, 0xD70($17)
    /* 1C3BE0 002C3BE0 41000524 */  addiu      $5, $0, 0x41
    /* 1C3BE4 002C3BE4 78820B0C */  jal        func_002e09e0
    /* 1C3BE8 002C3BE8 00000000 */   nop
    /* 1C3BEC 002C3BEC 700D248E */  lw         $4, 0xD70($17)
    /* 1C3BF0 002C3BF0 2D280000 */  daddu      $5, $0, $0
    /* 1C3BF4 002C3BF4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C3BF8 002C3BF8 2D380000 */  daddu      $7, $0, $0
    /* 1C3BFC 002C3BFC 0A000824 */  addiu      $8, $0, 0xA
    /* 1C3C00 002C3C00 2D480000 */  daddu      $9, $0, $0
    /* 1C3C04 002C3C04 98810B0C */  jal        func_002e0660
    /* 1C3C08 002C3C08 00000000 */   nop
    /* 1C3C0C 002C3C0C 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1C3C10 002C3C10 00608244 */  mtc1       $2, $f12
    /* 1C3C14 002C3C14 9343023C */  lui        $2, (0x43930000 >> 16)
    /* 1C3C18 002C3C18 00688244 */  mtc1       $2, $f13
    /* 1C3C1C 002C3C1C 0804A427 */  addiu      $4, $29, 0x408
    /* 1C3C20 002C3C20 5CCA0A0C */  jal        func_002b2970
    /* 1C3C24 002C3C24 00000000 */   nop
    /* 1C3C28 002C3C28 700D248E */  lw         $4, 0xD70($17)
    /* 1C3C2C 002C3C2C 38810B0C */  jal        func_002e04e0
    /* 1C3C30 002C3C30 00000000 */   nop
    /* 1C3C34 002C3C34 0804A1C7 */  lwc1       $f1, 0x408($29)
    /* 1C3C38 002C3C38 0C04A0C7 */  lwc1       $f0, 0x40C($29)
    /* 1C3C3C 002C3C3C 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C3C40 002C3C40 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C3C44 002C3C44 0041023C */  lui        $2, (0x41000000 >> 16)
    /* 1C3C48 002C3C48 00608244 */  mtc1       $2, $f12
    /* 1C3C4C 002C3C4C 7C0D248E */  lw         $4, 0xD7C($17)
    /* 1C3C50 002C3C50 41000524 */  addiu      $5, $0, 0x41
    /* 1C3C54 002C3C54 78820B0C */  jal        func_002e09e0
    /* 1C3C58 002C3C58 00000000 */   nop
    /* 1C3C5C 002C3C5C 7C0D248E */  lw         $4, 0xD7C($17)
    /* 1C3C60 002C3C60 2D280000 */  daddu      $5, $0, $0
    /* 1C3C64 002C3C64 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C3C68 002C3C68 2D380000 */  daddu      $7, $0, $0
    /* 1C3C6C 002C3C6C 0A000824 */  addiu      $8, $0, 0xA
    /* 1C3C70 002C3C70 2D480000 */  daddu      $9, $0, $0
    /* 1C3C74 002C3C74 98810B0C */  jal        func_002e0660
    /* 1C3C78 002C3C78 00000000 */   nop
    /* 1C3C7C 002C3C7C 3442023C */  lui        $2, (0x42340000 >> 16)
    /* 1C3C80 002C3C80 00608244 */  mtc1       $2, $f12
    /* 1C3C84 002C3C84 D80D248E */  lw         $4, 0xDD8($17)
    /* 1C3C88 002C3C88 41000524 */  addiu      $5, $0, 0x41
    /* 1C3C8C 002C3C8C 78820B0C */  jal        func_002e09e0
    /* 1C3C90 002C3C90 00000000 */   nop
    /* 1C3C94 002C3C94 D80D248E */  lw         $4, 0xDD8($17)
    /* 1C3C98 002C3C98 2D280000 */  daddu      $5, $0, $0
    /* 1C3C9C 002C3C9C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C3CA0 002C3CA0 2D380000 */  daddu      $7, $0, $0
    /* 1C3CA4 002C3CA4 06000824 */  addiu      $8, $0, 0x6
    /* 1C3CA8 002C3CA8 2D480000 */  daddu      $9, $0, $0
    /* 1C3CAC 002C3CAC 98810B0C */  jal        func_002e0660
    /* 1C3CB0 002C3CB0 00000000 */   nop
    /* 1C3CB4 002C3CB4 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1C3CB8 002C3CB8 00608244 */  mtc1       $2, $f12
    /* 1C3CBC 002C3CBC E80D248E */  lw         $4, 0xDE8($17)
    /* 1C3CC0 002C3CC0 41000524 */  addiu      $5, $0, 0x41
    /* 1C3CC4 002C3CC4 78820B0C */  jal        func_002e09e0
    /* 1C3CC8 002C3CC8 00000000 */   nop
    /* 1C3CCC 002C3CCC E80D248E */  lw         $4, 0xDE8($17)
    /* 1C3CD0 002C3CD0 2D280000 */  daddu      $5, $0, $0
    /* 1C3CD4 002C3CD4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C3CD8 002C3CD8 2D380000 */  daddu      $7, $0, $0
    /* 1C3CDC 002C3CDC 06000824 */  addiu      $8, $0, 0x6
    /* 1C3CE0 002C3CE0 2D480000 */  daddu      $9, $0, $0
    /* 1C3CE4 002C3CE4 98810B0C */  jal        func_002e0660
    /* 1C3CE8 002C3CE8 00000000 */   nop
    /* 1C3CEC 002C3CEC 7F010224 */  addiu      $2, $0, 0x17F
    /* 1C3CF0 002C3CF0 00008244 */  mtc1       $2, $f0
    /* 1C3CF4 002C3CF4 00000000 */  nop
    /* 1C3CF8 002C3CF8 20058046 */  cvt.s.w    $f20, $f0
    /* 1C3CFC 002C3CFC E80D248E */  lw         $4, 0xDE8($17)
    /* 1C3D00 002C3D00 38810B0C */  jal        func_002e04e0
    /* 1C3D04 002C3D04 00000000 */   nop
    /* 1C3D08 002C3D08 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C3D0C 002C3D0C CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1C3D10 002C3D10 00A08244 */  mtc1       $2, $f20
    /* 1C3D14 002C3D14 E80D248E */  lw         $4, 0xDE8($17)
    /* 1C3D18 002C3D18 38810B0C */  jal        func_002e04e0
    /* 1C3D1C 002C3D1C 00000000 */   nop
    /* 1C3D20 002C3D20 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C3D24 002C3D24 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1C3D28 002C3D28 00608244 */  mtc1       $2, $f12
    /* 1C3D2C 002C3D2C F00D248E */  lw         $4, 0xDF0($17)
    /* 1C3D30 002C3D30 41000524 */  addiu      $5, $0, 0x41
    /* 1C3D34 002C3D34 78820B0C */  jal        func_002e09e0
    /* 1C3D38 002C3D38 00000000 */   nop
    /* 1C3D3C 002C3D3C F00D248E */  lw         $4, 0xDF0($17)
    /* 1C3D40 002C3D40 2D280000 */  daddu      $5, $0, $0
    /* 1C3D44 002C3D44 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C3D48 002C3D48 2D380000 */  daddu      $7, $0, $0
    /* 1C3D4C 002C3D4C 06000824 */  addiu      $8, $0, 0x6
    /* 1C3D50 002C3D50 2D480000 */  daddu      $9, $0, $0
    /* 1C3D54 002C3D54 98810B0C */  jal        func_002e0660
    /* 1C3D58 002C3D58 00000000 */   nop
    /* 1C3D5C 002C3D5C DF43023C */  lui        $2, (0x43DF0000 >> 16)
    /* 1C3D60 002C3D60 00A08244 */  mtc1       $2, $f20
    /* 1C3D64 002C3D64 F00D248E */  lw         $4, 0xDF0($17)
    /* 1C3D68 002C3D68 38810B0C */  jal        func_002e04e0
    /* 1C3D6C 002C3D6C 00000000 */   nop
    /* 1C3D70 002C3D70 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1C3D74 002C3D74 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1C3D78 002C3D78 00A08244 */  mtc1       $2, $f20
    /* 1C3D7C 002C3D7C F00D248E */  lw         $4, 0xDF0($17)
    /* 1C3D80 002C3D80 38810B0C */  jal        func_002e04e0
    /* 1C3D84 002C3D84 00000000 */   nop
    /* 1C3D88 002C3D88 300054E4 */  swc1       $f20, 0x30($2)
    /* 1C3D8C 002C3D8C 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1C3D90 002C3D90 00608244 */  mtc1       $2, $f12
    /* 1C3D94 002C3D94 E40D248E */  lw         $4, 0xDE4($17)
    /* 1C3D98 002C3D98 41000524 */  addiu      $5, $0, 0x41
    /* 1C3D9C 002C3D9C 78820B0C */  jal        func_002e09e0
    /* 1C3DA0 002C3DA0 00000000 */   nop
    /* 1C3DA4 002C3DA4 E40D248E */  lw         $4, 0xDE4($17)
    /* 1C3DA8 002C3DA8 2D280000 */  daddu      $5, $0, $0
    /* 1C3DAC 002C3DAC FF000624 */  addiu      $6, $0, 0xFF
    /* 1C3DB0 002C3DB0 2D380000 */  daddu      $7, $0, $0
    /* 1C3DB4 002C3DB4 06000824 */  addiu      $8, $0, 0x6
    /* 1C3DB8 002C3DB8 2D480000 */  daddu      $9, $0, $0
    /* 1C3DBC 002C3DBC 98810B0C */  jal        func_002e0660
    /* 1C3DC0 002C3DC0 00000000 */   nop
    /* 1C3DC4 002C3DC4 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1C3DC8 002C3DC8 00608244 */  mtc1       $2, $f12
    /* 1C3DCC 002C3DCC E00D248E */  lw         $4, 0xDE0($17)
    /* 1C3DD0 002C3DD0 41000524 */  addiu      $5, $0, 0x41
    /* 1C3DD4 002C3DD4 78820B0C */  jal        func_002e09e0
    /* 1C3DD8 002C3DD8 00000000 */   nop
    /* 1C3DDC 002C3DDC E40D248E */  lw         $4, 0xDE4($17)
    /* 1C3DE0 002C3DE0 38810B0C */  jal        func_002e04e0
    /* 1C3DE4 002C3DE4 00000000 */   nop
    /* 1C3DE8 002C3DE8 2D804000 */  daddu      $16, $2, $0
    /* 1C3DEC 002C3DEC E00D248E */  lw         $4, 0xDE0($17)
    /* 1C3DF0 002C3DF0 38810B0C */  jal        func_002e04e0
    /* 1C3DF4 002C3DF4 00000000 */   nop
    /* 1C3DF8 002C3DF8 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* 1C3DFC 002C3DFC 300000C6 */  lwc1       $f0, 0x30($16)
    /* 1C3E00 002C3E00 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C3E04 002C3E04 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C3E08 002C3E08 FF001024 */  addiu      $16, $0, 0xFF
    /* 1C3E0C 002C3E0C E00D248E */  lw         $4, 0xDE0($17)
    /* 1C3E10 002C3E10 38810B0C */  jal        func_002e04e0
    /* 1C3E14 002C3E14 00000000 */   nop
    /* 1C3E18 002C3E18 620050A0 */  sb         $16, 0x62($2)
    /* 1C3E1C 002C3E1C E00D248E */  lw         $4, 0xDE0($17)
    /* 1C3E20 002C3E20 2D280000 */  daddu      $5, $0, $0
    /* 1C3E24 002C3E24 01000624 */  addiu      $6, $0, 0x1
    /* 1C3E28 002C3E28 3C810B0C */  jal        func_002e04f0
    /* 1C3E2C 002C3E2C 00000000 */   nop
    /* 1C3E30 002C3E30 0B43023C */  lui        $2, (0x430B0000 >> 16)
    /* 1C3E34 002C3E34 00608244 */  mtc1       $2, $f12
    /* 1C3E38 002C3E38 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C3E3C 002C3E3C 41000524 */  addiu      $5, $0, 0x41
    /* 1C3E40 002C3E40 78820B0C */  jal        func_002e09e0
    /* 1C3E44 002C3E44 00000000 */   nop
    /* 1C3E48 002C3E48 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C3E4C 002C3E4C 2D280000 */  daddu      $5, $0, $0
    /* 1C3E50 002C3E50 2D300002 */  daddu      $6, $16, $0
    /* 1C3E54 002C3E54 2D380000 */  daddu      $7, $0, $0
    /* 1C3E58 002C3E58 06000824 */  addiu      $8, $0, 0x6
    /* 1C3E5C 002C3E5C 2D480000 */  daddu      $9, $0, $0
    /* 1C3E60 002C3E60 98810B0C */  jal        func_002e0660
    /* 1C3E64 002C3E64 00000000 */   nop
    /* 1C3E68 002C3E68 2C07A427 */  addiu      $4, $29, 0x72C
    /* 1C3E6C 002C3E6C CE000524 */  addiu      $5, $0, 0xCE
    /* 1C3E70 002C3E70 71000624 */  addiu      $6, $0, 0x71
    /* 1C3E74 002C3E74 02000724 */  addiu      $7, $0, 0x2
    /* 1C3E78 002C3E78 2D400002 */  daddu      $8, $16, $0
    /* 1C3E7C 002C3E7C 98CA0A0C */  jal        func_002b2a60
    /* 1C3E80 002C3E80 00000000 */   nop
    /* 1C3E84 002C3E84 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C3E88 002C3E88 38810B0C */  jal        func_002e04e0
    /* 1C3E8C 002C3E8C 00000000 */   nop
    /* 1C3E90 002C3E90 2C07A693 */  lbu        $6, 0x72C($29)
    /* 1C3E94 002C3E94 2D07A593 */  lbu        $5, 0x72D($29)
    /* 1C3E98 002C3E98 2E07A493 */  lbu        $4, 0x72E($29)
    /* 1C3E9C 002C3E9C 2F07A393 */  lbu        $3, 0x72F($29)
    /* 1C3EA0 002C3EA0 790046A0 */  sb         $6, 0x79($2)
    /* 1C3EA4 002C3EA4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C3EA8 002C3EA8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C3EAC 002C3EAC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C3EB0 002C3EB0 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1C3EB4 002C3EB4 00608244 */  mtc1       $2, $f12
    /* 1C3EB8 002C3EB8 900C248E */  lw         $4, 0xC90($17)
    /* 1C3EBC 002C3EBC 41000524 */  addiu      $5, $0, 0x41
    /* 1C3EC0 002C3EC0 78820B0C */  jal        func_002e09e0
    /* 1C3EC4 002C3EC4 00000000 */   nop
    /* 1C3EC8 002C3EC8 900C248E */  lw         $4, 0xC90($17)
    /* 1C3ECC 002C3ECC 2D280000 */  daddu      $5, $0, $0
    /* 1C3ED0 002C3ED0 2D300002 */  daddu      $6, $16, $0
    /* 1C3ED4 002C3ED4 2D380000 */  daddu      $7, $0, $0
    /* 1C3ED8 002C3ED8 06000824 */  addiu      $8, $0, 0x6
    /* 1C3EDC 002C3EDC 2D480000 */  daddu      $9, $0, $0
    /* 1C3EE0 002C3EE0 98810B0C */  jal        func_002e0660
    /* 1C3EE4 002C3EE4 00000000 */   nop
    /* 1C3EE8 002C3EE8 2807A427 */  addiu      $4, $29, 0x728
    /* 1C3EEC 002C3EEC CE000524 */  addiu      $5, $0, 0xCE
    /* 1C3EF0 002C3EF0 71000624 */  addiu      $6, $0, 0x71
    /* 1C3EF4 002C3EF4 02000724 */  addiu      $7, $0, 0x2
    /* 1C3EF8 002C3EF8 2D400002 */  daddu      $8, $16, $0
    /* 1C3EFC 002C3EFC 98CA0A0C */  jal        func_002b2a60
    /* 1C3F00 002C3F00 00000000 */   nop
    /* 1C3F04 002C3F04 900C248E */  lw         $4, 0xC90($17)
    /* 1C3F08 002C3F08 38810B0C */  jal        func_002e04e0
    /* 1C3F0C 002C3F0C 00000000 */   nop
    /* 1C3F10 002C3F10 2807A693 */  lbu        $6, 0x728($29)
    /* 1C3F14 002C3F14 2907A593 */  lbu        $5, 0x729($29)
    /* 1C3F18 002C3F18 2A07A493 */  lbu        $4, 0x72A($29)
    /* 1C3F1C 002C3F1C 2B07A393 */  lbu        $3, 0x72B($29)
    /* 1C3F20 002C3F20 790046A0 */  sb         $6, 0x79($2)
    /* 1C3F24 002C3F24 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C3F28 002C3F28 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C3F2C 002C3F2C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C3F30 002C3F30 040020A6 */  sh         $0, 0x4($17)
    /* 1C3F34 002C3F34 020020A6 */  sh         $0, 0x2($17)
    /* 1C3F38 002C3F38 07002282 */  lb         $2, 0x7($17)
    /* 1C3F3C 002C3F3C 02000624 */  addiu      $6, $0, 0x2
    /* 1C3F40 002C3F40 22004610 */  beq        $2, $6, .L002C3FCC
    /* 1C3F44 002C3F44 00000000 */   nop
    /* 1C3F48 002C3F48 01000524 */  addiu      $5, $0, 0x1
    /* 1C3F4C 002C3F4C 14004510 */  beq        $2, $5, .L002C3FA0
    /* 1C3F50 002C3F50 00000000 */   nop
    /* 1C3F54 002C3F54 03004010 */  beqz       $2, .L002C3F64
    /* 1C3F58 002C3F58 00000000 */   nop
    /* 1C3F5C 002C3F5C 25000010 */  b          .L002C3FF4
    /* 1C3F60 002C3F60 00000000 */   nop
  .L002C3F64:
    /* 1C3F64 002C3F64 08002282 */  lb         $2, 0x8($17)
    /* 1C3F68 002C3F68 21185100 */  addu       $3, $2, $17
    /* 1C3F6C 002C3F6C 7C0F6280 */  lb         $2, 0xF7C($3)
    /* 1C3F70 002C3F70 ECFF4224 */  addiu      $2, $2, -0x14
    /* 1C3F74 002C3F74 3C140200 */  dsll32     $2, $2, 16
    /* 1C3F78 002C3F78 3F140200 */  dsra32     $2, $2, 16
    /* 1C3F7C 002C3F7C 04204500 */  sllv       $4, $5, $2
    /* 1C3F80 002C3F80 730F6280 */  lb         $2, 0xF73($3)
    /* 1C3F84 002C3F84 04004224 */  addiu      $2, $2, 0x4
    /* 1C3F88 002C3F88 04284500 */  sllv       $5, $5, $2
    /* 1C3F8C 002C3F8C 2D38C000 */  daddu      $7, $6, $0
    /* 1C3F90 002C3F90 28890B0C */  jal        func_002e24a0
    /* 1C3F94 002C3F94 00000000 */   nop
    /* 1C3F98 002C3F98 16000010 */  b          .L002C3FF4
    /* 1C3F9C 002C3F9C 00000000 */   nop
  .L002C3FA0:
    /* 1C3FA0 002C3FA0 08002282 */  lb         $2, 0x8($17)
    /* 1C3FA4 002C3FA4 21105100 */  addu       $2, $2, $17
    /* 1C3FA8 002C3FA8 730F4280 */  lb         $2, 0xF73($2)
    /* 1C3FAC 002C3FAC 04004224 */  addiu      $2, $2, 0x4
    /* 1C3FB0 002C3FB0 04284500 */  sllv       $5, $5, $2
    /* 1C3FB4 002C3FB4 00400424 */  addiu      $4, $0, 0x4000
    /* 1C3FB8 002C3FB8 2D38C000 */  daddu      $7, $6, $0
    /* 1C3FBC 002C3FBC 28890B0C */  jal        func_002e24a0
    /* 1C3FC0 002C3FC0 00000000 */   nop
    /* 1C3FC4 002C3FC4 0B000010 */  b          .L002C3FF4
    /* 1C3FC8 002C3FC8 00000000 */   nop
  .L002C3FCC:
    /* 1C3FCC 002C3FCC 08002282 */  lb         $2, 0x8($17)
    /* 1C3FD0 002C3FD0 21105100 */  addu       $2, $2, $17
    /* 1C3FD4 002C3FD4 730F4280 */  lb         $2, 0xF73($2)
    /* 1C3FD8 002C3FD8 04004324 */  addiu      $3, $2, 0x4
    /* 1C3FDC 002C3FDC 01000224 */  addiu      $2, $0, 0x1
    /* 1C3FE0 002C3FE0 04286200 */  sllv       $5, $2, $3
    /* 1C3FE4 002C3FE4 00800434 */  ori        $4, $0, 0x8000
    /* 1C3FE8 002C3FE8 2D38C000 */  daddu      $7, $6, $0
    /* 1C3FEC 002C3FEC 28890B0C */  jal        func_002e24a0
    /* 1C3FF0 002C3FF0 00000000 */   nop
  .L002C3FF4:
    /* 1C3FF4 002C3FF4 1B000224 */  addiu      $2, $0, 0x1B
    /* 1C3FF8 002C3FF8 000022A2 */  sb         $2, 0x0($17)
    /* 1C3FFC 002C3FFC CA190010 */  b          .L002CA728
    /* 1C4000 002C4000 00000000 */   nop
    /* 1C4004 002C4004 2D208002 */  daddu      $4, $20, $0
    /* 1C4008 002C4008 2D280000 */  daddu      $5, $0, $0
    /* 1C400C 002C400C B02D0B0C */  jal        func_002cb6c0
    /* 1C4010 002C4010 00000000 */   nop
    /* 1C4014 002C4014 4E020224 */  addiu      $2, $0, 0x24E
    /* 1C4018 002C4018 00008244 */  mtc1       $2, $f0
    /* 1C401C 002C401C 00000000 */  nop
    /* 1C4020 002C4020 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4024 002C4024 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1C4028 002C4028 00688244 */  mtc1       $2, $f13
    /* 1C402C 002C402C 0004A427 */  addiu      $4, $29, 0x400
    /* 1C4030 002C4030 5CCA0A0C */  jal        func_002b2970
    /* 1C4034 002C4034 00000000 */   nop
    /* 1C4038 002C4038 2407A427 */  addiu      $4, $29, 0x724
    /* 1C403C 002C403C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C4040 002C4040 2D30A000 */  daddu      $6, $5, $0
    /* 1C4044 002C4044 2D38A000 */  daddu      $7, $5, $0
    /* 1C4048 002C4048 2D40A000 */  daddu      $8, $5, $0
    /* 1C404C 002C404C 98CA0A0C */  jal        func_002b2a60
    /* 1C4050 002C4050 00000000 */   nop
    /* 1C4054 002C4054 02002486 */  lh         $4, 0x2($17)
    /* 1C4058 002C4058 D0890B0C */  jal        func_002e2740
    /* 1C405C 002C405C 00000000 */   nop
    /* 1C4060 002C4060 3C240200 */  dsll32     $4, $2, 16
    /* 1C4064 002C4064 3F240400 */  dsra32     $4, $4, 16
    /* 1C4068 002C4068 A41A040C */  jal        func_00106a90
    /* 1C406C 002C406C 00000000 */   nop
    /* 1C4070 002C4070 2D884000 */  daddu      $17, $2, $0
    /* 1C4074 002C4074 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4078 002C4078 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C407C 002C407C DCA9110C */  jal        func_0046a770
    /* 1C4080 002C4080 00000000 */   nop
    /* 1C4084 002C4084 2D804000 */  daddu      $16, $2, $0
    /* 1C4088 002C4088 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C408C 002C408C A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4090 002C4090 DCA9110C */  jal        func_0046a770
    /* 1C4094 002C4094 00000000 */   nop
    /* 1C4098 002C4098 0000A2FF */  sd         $2, 0x0($29)
    /* 1C409C 002C409C AA000224 */  addiu      $2, $0, 0xAA
    /* 1C40A0 002C40A0 0800A2FF */  sd         $2, 0x8($29)
    /* 1C40A4 002C40A4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C40A8 002C40A8 00608244 */  mtc1       $2, $f12
    /* 1C40AC 002C40AC 0004A4DF */  ld         $4, 0x400($29)
    /* 1C40B0 002C40B0 2407A58F */  lw         $5, 0x724($29)
    /* 1C40B4 002C40B4 11000624 */  addiu      $6, $0, 0x11
    /* 1C40B8 002C40B8 05000724 */  addiu      $7, $0, 0x5
    /* 1C40BC 002C40BC 2D402002 */  daddu      $8, $17, $0
    /* 1C40C0 002C40C0 70000924 */  addiu      $9, $0, 0x70
    /* 1C40C4 002C40C4 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1C40C8 002C40C8 2D580002 */  daddu      $11, $16, $0
    /* 1C40CC 002C40CC 342B0B0C */  jal        func_002cacd0
    /* 1C40D0 002C40D0 00000000 */   nop
    /* 1C40D4 002C40D4 94190010 */  b          .L002CA728
    /* 1C40D8 002C40D8 00000000 */   nop
    /* 1C40DC 002C40DC 2D208002 */  daddu      $4, $20, $0
    /* 1C40E0 002C40E0 01000524 */  addiu      $5, $0, 0x1
    /* 1C40E4 002C40E4 B02D0B0C */  jal        func_002cb6c0
    /* 1C40E8 002C40E8 00000000 */   nop
    /* 1C40EC 002C40EC 4E020224 */  addiu      $2, $0, 0x24E
    /* 1C40F0 002C40F0 00008244 */  mtc1       $2, $f0
    /* 1C40F4 002C40F4 00000000 */  nop
    /* 1C40F8 002C40F8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C40FC 002C40FC 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1C4100 002C4100 00688244 */  mtc1       $2, $f13
    /* 1C4104 002C4104 F803A427 */  addiu      $4, $29, 0x3F8
    /* 1C4108 002C4108 5CCA0A0C */  jal        func_002b2970
    /* 1C410C 002C410C 00000000 */   nop
    /* 1C4110 002C4110 2007A427 */  addiu      $4, $29, 0x720
    /* 1C4114 002C4114 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C4118 002C4118 2D30A000 */  daddu      $6, $5, $0
    /* 1C411C 002C411C 2D38A000 */  daddu      $7, $5, $0
    /* 1C4120 002C4120 2D40A000 */  daddu      $8, $5, $0
    /* 1C4124 002C4124 98CA0A0C */  jal        func_002b2a60
    /* 1C4128 002C4128 00000000 */   nop
    /* 1C412C 002C412C 02002486 */  lh         $4, 0x2($17)
    /* 1C4130 002C4130 D0890B0C */  jal        func_002e2740
    /* 1C4134 002C4134 00000000 */   nop
    /* 1C4138 002C4138 3C240200 */  dsll32     $4, $2, 16
    /* 1C413C 002C413C 3F240400 */  dsra32     $4, $4, 16
    /* 1C4140 002C4140 A41A040C */  jal        func_00106a90
    /* 1C4144 002C4144 00000000 */   nop
    /* 1C4148 002C4148 2D904000 */  daddu      $18, $2, $0
    /* 1C414C 002C414C 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4150 002C4150 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4154 002C4154 DCA9110C */  jal        func_0046a770
    /* 1C4158 002C4158 00000000 */   nop
    /* 1C415C 002C415C 2D804000 */  daddu      $16, $2, $0
    /* 1C4160 002C4160 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4164 002C4164 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4168 002C4168 DCA9110C */  jal        func_0046a770
    /* 1C416C 002C416C 00000000 */   nop
    /* 1C4170 002C4170 0000A2FF */  sd         $2, 0x0($29)
    /* 1C4174 002C4174 AA000224 */  addiu      $2, $0, 0xAA
    /* 1C4178 002C4178 0800A2FF */  sd         $2, 0x8($29)
    /* 1C417C 002C417C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C4180 002C4180 00608244 */  mtc1       $2, $f12
    /* 1C4184 002C4184 F803A4DF */  ld         $4, 0x3F8($29)
    /* 1C4188 002C4188 2007A58F */  lw         $5, 0x720($29)
    /* 1C418C 002C418C 11000624 */  addiu      $6, $0, 0x11
    /* 1C4190 002C4190 05000724 */  addiu      $7, $0, 0x5
    /* 1C4194 002C4194 2D404002 */  daddu      $8, $18, $0
    /* 1C4198 002C4198 70000924 */  addiu      $9, $0, 0x70
    /* 1C419C 002C419C 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1C41A0 002C41A0 2D580002 */  daddu      $11, $16, $0
    /* 1C41A4 002C41A4 342B0B0C */  jal        func_002cacd0
    /* 1C41A8 002C41A8 00000000 */   nop
    /* 1C41AC 002C41AC 2DA80000 */  daddu      $21, $0, $0
    /* 1C41B0 002C41B0 9A000010 */  b          .L002C441C
    /* 1C41B4 002C41B4 00000000 */   nop
  .L002C41B8:
    /* 1C41B8 002C41B8 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C41BC 002C41BC 38810B0C */  jal        func_002e04e0
    /* 1C41C0 002C41C0 00000000 */   nop
    /* 1C41C4 002C41C4 2D984000 */  daddu      $19, $2, $0
    /* 1C41C8 002C41C8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C41CC 002C41CC 38810B0C */  jal        func_002e04e0
    /* 1C41D0 002C41D0 00000000 */   nop
    /* 1C41D4 002C41D4 2D904000 */  daddu      $18, $2, $0
    /* 1C41D8 002C41D8 3C141500 */  dsll32     $2, $21, 16
    /* 1C41DC 002C41DC 3F140200 */  dsra32     $2, $2, 16
    /* 1C41E0 002C41E0 80100200 */  sll        $2, $2, 2
    /* 1C41E4 002C41E4 21802202 */  addu       $16, $17, $2
    /* 1C41E8 002C41E8 3E0F0292 */  lbu        $2, 0xF3E($16)
    /* 1C41EC 002C41EC 06004004 */  bltz       $2, .L002C4208
    /* 1C41F0 002C41F0 00000000 */   nop
    /* 1C41F4 002C41F4 00008244 */  mtc1       $2, $f0
    /* 1C41F8 002C41F8 00000000 */  nop
    /* 1C41FC 002C41FC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4200 002C4200 08000010 */  b          .L002C4224
    /* 1C4204 002C4204 00000000 */   nop
  .L002C4208:
    /* 1C4208 002C4208 42180200 */  srl        $3, $2, 1
    /* 1C420C 002C420C 01004230 */  andi       $2, $2, 0x1
    /* 1C4210 002C4210 25186200 */  or         $3, $3, $2
    /* 1C4214 002C4214 00008344 */  mtc1       $3, $f0
    /* 1C4218 002C4218 00000000 */  nop
    /* 1C421C 002C421C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4220 002C4220 00630C46 */  add.s      $f12, $f12, $f12
  .L002C4224:
    /* 1C4224 002C4224 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C4228 002C4228 00008244 */  mtc1       $2, $f0
    /* 1C422C 002C422C 00000000 */  nop
    /* 1C4230 002C4230 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C4234 002C4234 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C4238 002C4238 00688244 */  mtc1       $2, $f13
    /* 1C423C 002C423C 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C4240 002C4240 00788244 */  mtc1       $2, $f15
    /* 1C4244 002C4244 01000424 */  addiu      $4, $0, 0x1
    /* 1C4248 002C4248 A8CA0A0C */  jal        func_002b2aa0
    /* 1C424C 002C424C 00000000 */   nop
    /* 1C4250 002C4250 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C4254 002C4254 00088244 */  mtc1       $2, $f1
    /* 1C4258 002C4258 00000000 */  nop
    /* 1C425C 002C425C 36080046 */  c.le.s     $f1, $f0
    /* 1C4260 002C4260 07000145 */  bc1t       .L002C4280
    /* 1C4264 002C4264 00000000 */   nop
    /* 1C4268 002C4268 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C426C 002C426C 00000344 */  mfc1       $3, $f0
    /* 1C4270 002C4270 00000000 */  nop
    /* 1C4274 002C4274 FF006330 */  andi       $3, $3, 0xFF
    /* 1C4278 002C4278 07000010 */  b          .L002C4298
    /* 1C427C 002C427C 00000000 */   nop
  .L002C4280:
    /* 1C4280 002C4280 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C4284 002C4284 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C4288 002C4288 00000344 */  mfc1       $3, $f0
    /* 1C428C 002C428C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C4290 002C4290 25186200 */  or         $3, $3, $2
    /* 1C4294 002C4294 FF006330 */  andi       $3, $3, 0xFF
  .L002C4298:
    /* 1C4298 002C4298 790043A2 */  sb         $3, 0x79($18)
    /* 1C429C 002C429C 790063A2 */  sb         $3, 0x79($19)
    /* 1C42A0 002C42A0 3F0F0292 */  lbu        $2, 0xF3F($16)
    /* 1C42A4 002C42A4 06004004 */  bltz       $2, .L002C42C0
    /* 1C42A8 002C42A8 00000000 */   nop
    /* 1C42AC 002C42AC 00008244 */  mtc1       $2, $f0
    /* 1C42B0 002C42B0 00000000 */  nop
    /* 1C42B4 002C42B4 20038046 */  cvt.s.w    $f12, $f0
    /* 1C42B8 002C42B8 08000010 */  b          .L002C42DC
    /* 1C42BC 002C42BC 00000000 */   nop
  .L002C42C0:
    /* 1C42C0 002C42C0 42180200 */  srl        $3, $2, 1
    /* 1C42C4 002C42C4 01004230 */  andi       $2, $2, 0x1
    /* 1C42C8 002C42C8 25186200 */  or         $3, $3, $2
    /* 1C42CC 002C42CC 00008344 */  mtc1       $3, $f0
    /* 1C42D0 002C42D0 00000000 */  nop
    /* 1C42D4 002C42D4 20038046 */  cvt.s.w    $f12, $f0
    /* 1C42D8 002C42D8 00630C46 */  add.s      $f12, $f12, $f12
  .L002C42DC:
    /* 1C42DC 002C42DC 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C42E0 002C42E0 00008244 */  mtc1       $2, $f0
    /* 1C42E4 002C42E4 00000000 */  nop
    /* 1C42E8 002C42E8 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C42EC 002C42EC 6243023C */  lui        $2, (0x43620000 >> 16)
    /* 1C42F0 002C42F0 00688244 */  mtc1       $2, $f13
    /* 1C42F4 002C42F4 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C42F8 002C42F8 00788244 */  mtc1       $2, $f15
    /* 1C42FC 002C42FC 01000424 */  addiu      $4, $0, 0x1
    /* 1C4300 002C4300 A8CA0A0C */  jal        func_002b2aa0
    /* 1C4304 002C4304 00000000 */   nop
    /* 1C4308 002C4308 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C430C 002C430C 00088244 */  mtc1       $2, $f1
    /* 1C4310 002C4310 00000000 */  nop
    /* 1C4314 002C4314 36080046 */  c.le.s     $f1, $f0
    /* 1C4318 002C4318 07000145 */  bc1t       .L002C4338
    /* 1C431C 002C431C 00000000 */   nop
    /* 1C4320 002C4320 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C4324 002C4324 00000344 */  mfc1       $3, $f0
    /* 1C4328 002C4328 00000000 */  nop
    /* 1C432C 002C432C FF006330 */  andi       $3, $3, 0xFF
    /* 1C4330 002C4330 07000010 */  b          .L002C4350
    /* 1C4334 002C4334 00000000 */   nop
  .L002C4338:
    /* 1C4338 002C4338 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C433C 002C433C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C4340 002C4340 00000344 */  mfc1       $3, $f0
    /* 1C4344 002C4344 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C4348 002C4348 25186200 */  or         $3, $3, $2
    /* 1C434C 002C434C FF006330 */  andi       $3, $3, 0xFF
  .L002C4350:
    /* 1C4350 002C4350 7A0043A2 */  sb         $3, 0x7A($18)
    /* 1C4354 002C4354 7A0063A2 */  sb         $3, 0x7A($19)
    /* 1C4358 002C4358 400F0292 */  lbu        $2, 0xF40($16)
    /* 1C435C 002C435C 06004004 */  bltz       $2, .L002C4378
    /* 1C4360 002C4360 00000000 */   nop
    /* 1C4364 002C4364 00008244 */  mtc1       $2, $f0
    /* 1C4368 002C4368 00000000 */  nop
    /* 1C436C 002C436C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4370 002C4370 08000010 */  b          .L002C4394
    /* 1C4374 002C4374 00000000 */   nop
  .L002C4378:
    /* 1C4378 002C4378 42180200 */  srl        $3, $2, 1
    /* 1C437C 002C437C 01004230 */  andi       $2, $2, 0x1
    /* 1C4380 002C4380 25186200 */  or         $3, $3, $2
    /* 1C4384 002C4384 00008344 */  mtc1       $3, $f0
    /* 1C4388 002C4388 00000000 */  nop
    /* 1C438C 002C438C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4390 002C4390 00630C46 */  add.s      $f12, $f12, $f12
  .L002C4394:
    /* 1C4394 002C4394 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C4398 002C4398 00008244 */  mtc1       $2, $f0
    /* 1C439C 002C439C 00000000 */  nop
    /* 1C43A0 002C43A0 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C43A4 002C43A4 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1C43A8 002C43A8 00688244 */  mtc1       $2, $f13
    /* 1C43AC 002C43AC 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C43B0 002C43B0 00788244 */  mtc1       $2, $f15
    /* 1C43B4 002C43B4 01000424 */  addiu      $4, $0, 0x1
    /* 1C43B8 002C43B8 A8CA0A0C */  jal        func_002b2aa0
    /* 1C43BC 002C43BC 00000000 */   nop
    /* 1C43C0 002C43C0 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C43C4 002C43C4 00088244 */  mtc1       $2, $f1
    /* 1C43C8 002C43C8 00000000 */  nop
    /* 1C43CC 002C43CC 36080046 */  c.le.s     $f1, $f0
    /* 1C43D0 002C43D0 07000145 */  bc1t       .L002C43F0
    /* 1C43D4 002C43D4 00000000 */   nop
    /* 1C43D8 002C43D8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C43DC 002C43DC 00000344 */  mfc1       $3, $f0
    /* 1C43E0 002C43E0 00000000 */  nop
    /* 1C43E4 002C43E4 FF006330 */  andi       $3, $3, 0xFF
    /* 1C43E8 002C43E8 07000010 */  b          .L002C4408
    /* 1C43EC 002C43EC 00000000 */   nop
  .L002C43F0:
    /* 1C43F0 002C43F0 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C43F4 002C43F4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C43F8 002C43F8 00000344 */  mfc1       $3, $f0
    /* 1C43FC 002C43FC 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C4400 002C4400 25186200 */  or         $3, $3, $2
    /* 1C4404 002C4404 FF006330 */  andi       $3, $3, 0xFF
  .L002C4408:
    /* 1C4408 002C4408 7B0043A2 */  sb         $3, 0x7B($18)
    /* 1C440C 002C440C 7B0063A2 */  sb         $3, 0x7B($19)
    /* 1C4410 002C4410 0100A226 */  addiu      $2, $21, 0x1
    /* 1C4414 002C4414 3CAC0200 */  dsll32     $21, $2, 16
    /* 1C4418 002C4418 3FAC1500 */  dsra32     $21, $21, 16
  .L002C441C:
    /* 1C441C 002C441C 3C141500 */  dsll32     $2, $21, 16
    /* 1C4420 002C4420 3F140200 */  dsra32     $2, $2, 16
    /* 1C4424 002C4424 02004228 */  slti       $2, $2, 0x2
    /* 1C4428 002C4428 63FF4014 */  bnez       $2, .L002C41B8
    /* 1C442C 002C442C 00000000 */   nop
    /* 1C4430 002C4430 3C0F2486 */  lh         $4, 0xF3C($17)
    /* 1C4434 002C4434 06008128 */  slti       $1, $4, 0x6
    /* 1C4438 002C4438 0A002010 */  beqz       $1, .L002C4464
    /* 1C443C 002C443C 00000000 */   nop
    /* 1C4440 002C4440 01000524 */  addiu      $5, $0, 0x1
    /* 1C4444 002C4444 06000624 */  addiu      $6, $0, 0x6
    /* 1C4448 002C4448 2D380000 */  daddu      $7, $0, $0
    /* 1C444C 002C444C 2D40A000 */  daddu      $8, $5, $0
    /* 1C4450 002C4450 2CCB0A0C */  jal        func_002b2cb0
    /* 1C4454 002C4454 00000000 */   nop
    /* 1C4458 002C4458 3C0F22A6 */  sh         $2, 0xF3C($17)
    /* 1C445C 002C445C B2180010 */  b          .L002CA728
    /* 1C4460 002C4460 00000000 */   nop
  .L002C4464:
    /* 1C4464 002C4464 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4468 002C4468 38810B0C */  jal        func_002e04e0
    /* 1C446C 002C446C 00000000 */   nop
    /* 1C4470 002C4470 3E0F2692 */  lbu        $6, 0xF3E($17)
    /* 1C4474 002C4474 3F0F2592 */  lbu        $5, 0xF3F($17)
    /* 1C4478 002C4478 400F2492 */  lbu        $4, 0xF40($17)
    /* 1C447C 002C447C 410F2392 */  lbu        $3, 0xF41($17)
    /* 1C4480 002C4480 790046A0 */  sb         $6, 0x79($2)
    /* 1C4484 002C4484 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C4488 002C4488 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C448C 002C448C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C4490 002C4490 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C4494 002C4494 38810B0C */  jal        func_002e04e0
    /* 1C4498 002C4498 00000000 */   nop
    /* 1C449C 002C449C 420F2692 */  lbu        $6, 0xF42($17)
    /* 1C44A0 002C44A0 430F2592 */  lbu        $5, 0xF43($17)
    /* 1C44A4 002C44A4 440F2492 */  lbu        $4, 0xF44($17)
    /* 1C44A8 002C44A8 450F2392 */  lbu        $3, 0xF45($17)
    /* 1C44AC 002C44AC 790046A0 */  sb         $6, 0x79($2)
    /* 1C44B0 002C44B0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C44B4 002C44B4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C44B8 002C44B8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C44BC 002C44BC 02002486 */  lh         $4, 0x2($17)
    /* 1C44C0 002C44C0 D0890B0C */  jal        func_002e2740
    /* 1C44C4 002C44C4 00000000 */   nop
    /* 1C44C8 002C44C8 A006A2AF */  sw         $2, 0x6A0($29)
    /* 1C44CC 002C44CC A406A0AF */  sw         $0, 0x6A4($29)
    /* 1C44D0 002C44D0 2D208002 */  daddu      $4, $20, $0
    /* 1C44D4 002C44D4 01000524 */  addiu      $5, $0, 0x1
    /* 1C44D8 002C44D8 A006A627 */  addiu      $6, $29, 0x6A0
    /* 1C44DC 002C44DC 2D38A000 */  daddu      $7, $5, $0
    /* 1C44E0 002C44E0 B07F0B0C */  jal        func_002dfec0
    /* 1C44E4 002C44E4 00000000 */   nop
    /* 1C44E8 002C44E8 100022A2 */  sb         $2, 0x10($17)
    /* 1C44EC 002C44EC 1D000224 */  addiu      $2, $0, 0x1D
    /* 1C44F0 002C44F0 000022A2 */  sb         $2, 0x0($17)
    /* 1C44F4 002C44F4 2D208002 */  daddu      $4, $20, $0
    /* 1C44F8 002C44F8 64580B0C */  jal        func_002d6190
    /* 1C44FC 002C44FC 00000000 */   nop
    /* 1C4500 002C4500 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4504 002C4504 2D280000 */  daddu      $5, $0, $0
    /* 1C4508 002C4508 01000624 */  addiu      $6, $0, 0x1
    /* 1C450C 002C450C 3C810B0C */  jal        func_002e04f0
    /* 1C4510 002C4510 00000000 */   nop
    /* 1C4514 002C4514 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C4518 002C4518 2D280000 */  daddu      $5, $0, $0
    /* 1C451C 002C451C 01000624 */  addiu      $6, $0, 0x1
    /* 1C4520 002C4520 3C810B0C */  jal        func_002e04f0
    /* 1C4524 002C4524 00000000 */   nop
    /* 1C4528 002C4528 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C452C 002C452C 2D280000 */  daddu      $5, $0, $0
    /* 1C4530 002C4530 01000624 */  addiu      $6, $0, 0x1
    /* 1C4534 002C4534 3C810B0C */  jal        func_002e04f0
    /* 1C4538 002C4538 00000000 */   nop
    /* 1C453C 002C453C 900C248E */  lw         $4, 0xC90($17)
    /* 1C4540 002C4540 2D280000 */  daddu      $5, $0, $0
    /* 1C4544 002C4544 01000624 */  addiu      $6, $0, 0x1
    /* 1C4548 002C4548 3C810B0C */  jal        func_002e04f0
    /* 1C454C 002C454C 00000000 */   nop
    /* 1C4550 002C4550 75180010 */  b          .L002CA728
    /* 1C4554 002C4554 00000000 */   nop
    /* 1C4558 002C4558 2D208002 */  daddu      $4, $20, $0
    /* 1C455C 002C455C 10540B0C */  jal        func_002d5040
    /* 1C4560 002C4560 00000000 */   nop
    /* 1C4564 002C4564 4E020224 */  addiu      $2, $0, 0x24E
    /* 1C4568 002C4568 00008244 */  mtc1       $2, $f0
    /* 1C456C 002C456C 00000000 */  nop
    /* 1C4570 002C4570 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4574 002C4574 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1C4578 002C4578 00688244 */  mtc1       $2, $f13
    /* 1C457C 002C457C F003A427 */  addiu      $4, $29, 0x3F0
    /* 1C4580 002C4580 5CCA0A0C */  jal        func_002b2970
    /* 1C4584 002C4584 00000000 */   nop
    /* 1C4588 002C4588 1C07A427 */  addiu      $4, $29, 0x71C
    /* 1C458C 002C458C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C4590 002C4590 2D30A000 */  daddu      $6, $5, $0
    /* 1C4594 002C4594 2D38A000 */  daddu      $7, $5, $0
    /* 1C4598 002C4598 2D40A000 */  daddu      $8, $5, $0
    /* 1C459C 002C459C 98CA0A0C */  jal        func_002b2a60
    /* 1C45A0 002C45A0 00000000 */   nop
    /* 1C45A4 002C45A4 02002486 */  lh         $4, 0x2($17)
    /* 1C45A8 002C45A8 D0890B0C */  jal        func_002e2740
    /* 1C45AC 002C45AC 00000000 */   nop
    /* 1C45B0 002C45B0 3C240200 */  dsll32     $4, $2, 16
    /* 1C45B4 002C45B4 3F240400 */  dsra32     $4, $4, 16
    /* 1C45B8 002C45B8 A41A040C */  jal        func_00106a90
    /* 1C45BC 002C45BC 00000000 */   nop
    /* 1C45C0 002C45C0 2D904000 */  daddu      $18, $2, $0
    /* 1C45C4 002C45C4 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C45C8 002C45C8 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C45CC 002C45CC DCA9110C */  jal        func_0046a770
    /* 1C45D0 002C45D0 00000000 */   nop
    /* 1C45D4 002C45D4 2D804000 */  daddu      $16, $2, $0
    /* 1C45D8 002C45D8 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C45DC 002C45DC A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C45E0 002C45E0 DCA9110C */  jal        func_0046a770
    /* 1C45E4 002C45E4 00000000 */   nop
    /* 1C45E8 002C45E8 0000A2FF */  sd         $2, 0x0($29)
    /* 1C45EC 002C45EC AA000224 */  addiu      $2, $0, 0xAA
    /* 1C45F0 002C45F0 0800A2FF */  sd         $2, 0x8($29)
    /* 1C45F4 002C45F4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C45F8 002C45F8 00608244 */  mtc1       $2, $f12
    /* 1C45FC 002C45FC F003A4DF */  ld         $4, 0x3F0($29)
    /* 1C4600 002C4600 1C07A58F */  lw         $5, 0x71C($29)
    /* 1C4604 002C4604 11000624 */  addiu      $6, $0, 0x11
    /* 1C4608 002C4608 05000724 */  addiu      $7, $0, 0x5
    /* 1C460C 002C460C 2D404002 */  daddu      $8, $18, $0
    /* 1C4610 002C4610 70000924 */  addiu      $9, $0, 0x70
    /* 1C4614 002C4614 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1C4618 002C4618 2D580002 */  daddu      $11, $16, $0
    /* 1C461C 002C461C 342B0B0C */  jal        func_002cacd0
    /* 1C4620 002C4620 00000000 */   nop
    /* 1C4624 002C4624 4C42023C */  lui        $2, (0x424C0000 >> 16)
    /* 1C4628 002C4628 00608244 */  mtc1       $2, $f12
    /* 1C462C 002C462C 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1C4630 002C4630 00688244 */  mtc1       $2, $f13
    /* 1C4634 002C4634 E803A427 */  addiu      $4, $29, 0x3E8
    /* 1C4638 002C4638 5CCA0A0C */  jal        func_002b2970
    /* 1C463C 002C463C 00000000 */   nop
    /* 1C4640 002C4640 FF000424 */  addiu      $4, $0, 0xFF
    /* 1C4644 002C4644 2D288000 */  daddu      $5, $4, $0
    /* 1C4648 002C4648 2D308000 */  daddu      $6, $4, $0
    /* 1C464C 002C464C 2D388000 */  daddu      $7, $4, $0
    /* 1C4650 002C4650 8CCA0A0C */  jal        func_002b2a30
    /* 1C4654 002C4654 00000000 */   nop
    /* 1C4658 002C4658 08002382 */  lb         $3, 0x8($17)
    /* 1C465C 002C465C 21187100 */  addu       $3, $3, $17
    /* 1C4660 002C4660 2D208002 */  daddu      $4, $20, $0
    /* 1C4664 002C4664 730F6580 */  lb         $5, 0xF73($3)
    /* 1C4668 002C4668 E803A6DF */  ld         $6, 0x3E8($29)
    /* 1C466C 002C466C 2D384000 */  daddu      $7, $2, $0
    /* 1C4670 002C4670 20800B0C */  jal        func_002e0080
    /* 1C4674 002C4674 00000000 */   nop
    /* 1C4678 002C4678 10002482 */  lb         $4, 0x10($17)
    /* 1C467C 002C467C A0ED0A0C */  jal        func_002bb680
    /* 1C4680 002C4680 00000000 */   nop
    /* 1C4684 002C4684 06004010 */  beqz       $2, .L002C46A0
    /* 1C4688 002C4688 00000000 */   nop
    /* 1C468C 002C468C 10002482 */  lb         $4, 0x10($17)
    /* 1C4690 002C4690 3CEF0A0C */  jal        func_002bbcf0
    /* 1C4694 002C4694 00000000 */   nop
    /* 1C4698 002C4698 23180010 */  b          .L002CA728
    /* 1C469C 002C469C 00000000 */   nop
  .L002C46A0:
    /* 1C46A0 002C46A0 10002482 */  lb         $4, 0x10($17)
    /* 1C46A4 002C46A4 70EC0A0C */  jal        func_002bb1c0
    /* 1C46A8 002C46A8 00000000 */   nop
    /* 1C46AC 002C46AC 27004014 */  bnez       $2, .L002C474C
    /* 1C46B0 002C46B0 00000000 */   nop
    /* 1C46B4 002C46B4 2D200000 */  daddu      $4, $0, $0
    /* 1C46B8 002C46B8 2D280000 */  daddu      $5, $0, $0
    /* 1C46BC 002C46BC 2D300000 */  daddu      $6, $0, $0
    /* 1C46C0 002C46C0 06000724 */  addiu      $7, $0, 0x6
    /* 1C46C4 002C46C4 D86B110C */  jal        func_0045af60
    /* 1C46C8 002C46C8 00000000 */   nop
    /* 1C46CC 002C46CC 10002482 */  lb         $4, 0x10($17)
    /* 1C46D0 002C46D0 54ED0A0C */  jal        func_002bb550
    /* 1C46D4 002C46D4 00000000 */   nop
    /* 1C46D8 002C46D8 02002486 */  lh         $4, 0x2($17)
    /* 1C46DC 002C46DC D0890B0C */  jal        func_002e2740
    /* 1C46E0 002C46E0 00000000 */   nop
    /* 1C46E4 002C46E4 3C240200 */  dsll32     $4, $2, 16
    /* 1C46E8 002C46E8 3F240400 */  dsra32     $4, $4, 16
    /* 1C46EC 002C46EC A41A040C */  jal        func_00106a90
    /* 1C46F0 002C46F0 00000000 */   nop
    /* 1C46F4 002C46F4 2D804000 */  daddu      $16, $2, $0
    /* 1C46F8 002C46F8 989E0B0C */  jal        func_002e7a60
    /* 1C46FC 002C46FC 00000000 */   nop
    /* 1C4700 002C4700 23205000 */  subu       $4, $2, $16
    /* 1C4704 002C4704 A09E0B0C */  jal        func_002e7a80
    /* 1C4708 002C4708 00000000 */   nop
    /* 1C470C 002C470C 02002486 */  lh         $4, 0x2($17)
    /* 1C4710 002C4710 D0890B0C */  jal        func_002e2740
    /* 1C4714 002C4714 00000000 */   nop
    /* 1C4718 002C4718 9806A2AF */  sw         $2, 0x698($29)
    /* 1C471C 002C471C 9C06A0AF */  sw         $0, 0x69C($29)
    /* 1C4720 002C4720 2D208002 */  daddu      $4, $20, $0
    /* 1C4724 002C4724 04000524 */  addiu      $5, $0, 0x4
    /* 1C4728 002C4728 9806A627 */  addiu      $6, $29, 0x698
    /* 1C472C 002C472C 01000724 */  addiu      $7, $0, 0x1
    /* 1C4730 002C4730 B07F0B0C */  jal        func_002dfec0
    /* 1C4734 002C4734 00000000 */   nop
    /* 1C4738 002C4738 100022A2 */  sb         $2, 0x10($17)
    /* 1C473C 002C473C 1E000224 */  addiu      $2, $0, 0x1E
    /* 1C4740 002C4740 000022A2 */  sb         $2, 0x0($17)
    /* 1C4744 002C4744 F8170010 */  b          .L002CA728
    /* 1C4748 002C4748 00000000 */   nop
  .L002C474C:
    /* 1C474C 002C474C 2D208002 */  daddu      $4, $20, $0
    /* 1C4750 002C4750 C05C0B0C */  jal        func_002d7300
    /* 1C4754 002C4754 00000000 */   nop
    /* 1C4758 002C4758 10002482 */  lb         $4, 0x10($17)
    /* 1C475C 002C475C 54ED0A0C */  jal        func_002bb550
    /* 1C4760 002C4760 00000000 */   nop
    /* 1C4764 002C4764 1B000224 */  addiu      $2, $0, 0x1B
    /* 1C4768 002C4768 000022A2 */  sb         $2, 0x0($17)
    /* 1C476C 002C476C 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C4770 002C4770 2D280000 */  daddu      $5, $0, $0
    /* 1C4774 002C4774 2D300000 */  daddu      $6, $0, $0
    /* 1C4778 002C4778 3C810B0C */  jal        func_002e04f0
    /* 1C477C 002C477C 00000000 */   nop
    /* 1C4780 002C4780 900C248E */  lw         $4, 0xC90($17)
    /* 1C4784 002C4784 2D280000 */  daddu      $5, $0, $0
    /* 1C4788 002C4788 2D300000 */  daddu      $6, $0, $0
    /* 1C478C 002C478C 3C810B0C */  jal        func_002e04f0
    /* 1C4790 002C4790 00000000 */   nop
    /* 1C4794 002C4794 E4170010 */  b          .L002CA728
    /* 1C4798 002C4798 00000000 */   nop
    /* 1C479C 002C479C 2D208002 */  daddu      $4, $20, $0
    /* 1C47A0 002C47A0 10540B0C */  jal        func_002d5040
    /* 1C47A4 002C47A4 00000000 */   nop
    /* 1C47A8 002C47A8 4C42023C */  lui        $2, (0x424C0000 >> 16)
    /* 1C47AC 002C47AC 00608244 */  mtc1       $2, $f12
    /* 1C47B0 002C47B0 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1C47B4 002C47B4 00688244 */  mtc1       $2, $f13
    /* 1C47B8 002C47B8 E003A427 */  addiu      $4, $29, 0x3E0
    /* 1C47BC 002C47BC 5CCA0A0C */  jal        func_002b2970
    /* 1C47C0 002C47C0 00000000 */   nop
    /* 1C47C4 002C47C4 FF000424 */  addiu      $4, $0, 0xFF
    /* 1C47C8 002C47C8 2D288000 */  daddu      $5, $4, $0
    /* 1C47CC 002C47CC 2D308000 */  daddu      $6, $4, $0
    /* 1C47D0 002C47D0 2D388000 */  daddu      $7, $4, $0
    /* 1C47D4 002C47D4 8CCA0A0C */  jal        func_002b2a30
    /* 1C47D8 002C47D8 00000000 */   nop
    /* 1C47DC 002C47DC 08002382 */  lb         $3, 0x8($17)
    /* 1C47E0 002C47E0 21187100 */  addu       $3, $3, $17
    /* 1C47E4 002C47E4 2D208002 */  daddu      $4, $20, $0
    /* 1C47E8 002C47E8 730F6580 */  lb         $5, 0xF73($3)
    /* 1C47EC 002C47EC E003A6DF */  ld         $6, 0x3E0($29)
    /* 1C47F0 002C47F0 2D384000 */  daddu      $7, $2, $0
    /* 1C47F4 002C47F4 20800B0C */  jal        func_002e0080
    /* 1C47F8 002C47F8 00000000 */   nop
    /* 1C47FC 002C47FC 4E020224 */  addiu      $2, $0, 0x24E
    /* 1C4800 002C4800 00008244 */  mtc1       $2, $f0
    /* 1C4804 002C4804 00000000 */  nop
    /* 1C4808 002C4808 20038046 */  cvt.s.w    $f12, $f0
    /* 1C480C 002C480C 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1C4810 002C4810 00688244 */  mtc1       $2, $f13
    /* 1C4814 002C4814 D803A427 */  addiu      $4, $29, 0x3D8
    /* 1C4818 002C4818 5CCA0A0C */  jal        func_002b2970
    /* 1C481C 002C481C 00000000 */   nop
    /* 1C4820 002C4820 1807A427 */  addiu      $4, $29, 0x718
    /* 1C4824 002C4824 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C4828 002C4828 2D30A000 */  daddu      $6, $5, $0
    /* 1C482C 002C482C 2D38A000 */  daddu      $7, $5, $0
    /* 1C4830 002C4830 2D40A000 */  daddu      $8, $5, $0
    /* 1C4834 002C4834 98CA0A0C */  jal        func_002b2a60
    /* 1C4838 002C4838 00000000 */   nop
    /* 1C483C 002C483C 02002486 */  lh         $4, 0x2($17)
    /* 1C4840 002C4840 D0890B0C */  jal        func_002e2740
    /* 1C4844 002C4844 00000000 */   nop
    /* 1C4848 002C4848 3C240200 */  dsll32     $4, $2, 16
    /* 1C484C 002C484C 3F240400 */  dsra32     $4, $4, 16
    /* 1C4850 002C4850 A41A040C */  jal        func_00106a90
    /* 1C4854 002C4854 00000000 */   nop
    /* 1C4858 002C4858 2D904000 */  daddu      $18, $2, $0
    /* 1C485C 002C485C 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4860 002C4860 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4864 002C4864 DCA9110C */  jal        func_0046a770
    /* 1C4868 002C4868 00000000 */   nop
    /* 1C486C 002C486C 2D804000 */  daddu      $16, $2, $0
    /* 1C4870 002C4870 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4874 002C4874 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4878 002C4878 DCA9110C */  jal        func_0046a770
    /* 1C487C 002C487C 00000000 */   nop
    /* 1C4880 002C4880 0000A2FF */  sd         $2, 0x0($29)
    /* 1C4884 002C4884 AA000224 */  addiu      $2, $0, 0xAA
    /* 1C4888 002C4888 0800A2FF */  sd         $2, 0x8($29)
    /* 1C488C 002C488C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C4890 002C4890 00608244 */  mtc1       $2, $f12
    /* 1C4894 002C4894 D803A4DF */  ld         $4, 0x3D8($29)
    /* 1C4898 002C4898 1807A58F */  lw         $5, 0x718($29)
    /* 1C489C 002C489C 11000624 */  addiu      $6, $0, 0x11
    /* 1C48A0 002C48A0 05000724 */  addiu      $7, $0, 0x5
    /* 1C48A4 002C48A4 2D404002 */  daddu      $8, $18, $0
    /* 1C48A8 002C48A8 70000924 */  addiu      $9, $0, 0x70
    /* 1C48AC 002C48AC 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1C48B0 002C48B0 2D580002 */  daddu      $11, $16, $0
    /* 1C48B4 002C48B4 342B0B0C */  jal        func_002cacd0
    /* 1C48B8 002C48B8 00000000 */   nop
    /* 1C48BC 002C48BC 10002482 */  lb         $4, 0x10($17)
    /* 1C48C0 002C48C0 A0ED0A0C */  jal        func_002bb680
    /* 1C48C4 002C48C4 00000000 */   nop
    /* 1C48C8 002C48C8 06004010 */  beqz       $2, .L002C48E4
    /* 1C48CC 002C48CC 00000000 */   nop
    /* 1C48D0 002C48D0 10002482 */  lb         $4, 0x10($17)
    /* 1C48D4 002C48D4 3CEF0A0C */  jal        func_002bbcf0
    /* 1C48D8 002C48D8 00000000 */   nop
    /* 1C48DC 002C48DC 92170010 */  b          .L002CA728
    /* 1C48E0 002C48E0 00000000 */   nop
  .L002C48E4:
    /* 1C48E4 002C48E4 10002482 */  lb         $4, 0x10($17)
    /* 1C48E8 002C48E8 70EC0A0C */  jal        func_002bb1c0
    /* 1C48EC 002C48EC 00000000 */   nop
    /* 1C48F0 002C48F0 1F004014 */  bnez       $2, .L002C4970
    /* 1C48F4 002C48F4 00000000 */   nop
    /* 1C48F8 002C48F8 2D200000 */  daddu      $4, $0, $0
    /* 1C48FC 002C48FC 2D280000 */  daddu      $5, $0, $0
    /* 1C4900 002C4900 2D300000 */  daddu      $6, $0, $0
    /* 1C4904 002C4904 07000724 */  addiu      $7, $0, 0x7
    /* 1C4908 002C4908 D86B110C */  jal        func_0045af60
    /* 1C490C 002C490C 00000000 */   nop
    /* 1C4910 002C4910 10002482 */  lb         $4, 0x10($17)
    /* 1C4914 002C4914 54ED0A0C */  jal        func_002bb550
    /* 1C4918 002C4918 00000000 */   nop
    /* 1C491C 002C491C 08002282 */  lb         $2, 0x8($17)
    /* 1C4920 002C4920 21105100 */  addu       $2, $2, $17
    /* 1C4924 002C4924 730F4480 */  lb         $4, 0xF73($2)
    /* 1C4928 002C4928 07002582 */  lb         $5, 0x7($17)
    /* 1C492C 002C492C 341B040C */  jal        func_00106cd0
    /* 1C4930 002C4930 00000000 */   nop
    /* 1C4934 002C4934 3C140200 */  dsll32     $2, $2, 16
    /* 1C4938 002C4938 3F140200 */  dsra32     $2, $2, 16
    /* 1C493C 002C493C 9006A2AF */  sw         $2, 0x690($29)
    /* 1C4940 002C4940 9406A0AF */  sw         $0, 0x694($29)
    /* 1C4944 002C4944 2D208002 */  daddu      $4, $20, $0
    /* 1C4948 002C4948 05000524 */  addiu      $5, $0, 0x5
    /* 1C494C 002C494C 9006A627 */  addiu      $6, $29, 0x690
    /* 1C4950 002C4950 01000724 */  addiu      $7, $0, 0x1
    /* 1C4954 002C4954 B07F0B0C */  jal        func_002dfec0
    /* 1C4958 002C4958 00000000 */   nop
    /* 1C495C 002C495C 100022A2 */  sb         $2, 0x10($17)
    /* 1C4960 002C4960 1F000224 */  addiu      $2, $0, 0x1F
    /* 1C4964 002C4964 000022A2 */  sb         $2, 0x0($17)
    /* 1C4968 002C4968 18000010 */  b          .L002C49CC
    /* 1C496C 002C496C 00000000 */   nop
  .L002C4970:
    /* 1C4970 002C4970 10002482 */  lb         $4, 0x10($17)
    /* 1C4974 002C4974 54ED0A0C */  jal        func_002bb550
    /* 1C4978 002C4978 00000000 */   nop
    /* 1C497C 002C497C 02002486 */  lh         $4, 0x2($17)
    /* 1C4980 002C4980 D0890B0C */  jal        func_002e2740
    /* 1C4984 002C4984 00000000 */   nop
    /* 1C4988 002C4988 3C840200 */  dsll32     $16, $2, 16
    /* 1C498C 002C498C 3F841000 */  dsra32     $16, $16, 16
    /* 1C4990 002C4990 02002486 */  lh         $4, 0x2($17)
    /* 1C4994 002C4994 D0890B0C */  jal        func_002e2740
    /* 1C4998 002C4998 00000000 */   nop
    /* 1C499C 002C499C 3C240200 */  dsll32     $4, $2, 16
    /* 1C49A0 002C49A0 3F240400 */  dsra32     $4, $4, 16
    /* 1C49A4 002C49A4 8019040C */  jal        func_00106600
    /* 1C49A8 002C49A8 00000000 */   nop
    /* 1C49AC 002C49AC FF004230 */  andi       $2, $2, 0xFF
    /* 1C49B0 002C49B0 01004224 */  addiu      $2, $2, 0x1
    /* 1C49B4 002C49B4 FF004530 */  andi       $5, $2, 0xFF
    /* 1C49B8 002C49B8 2D200002 */  daddu      $4, $16, $0
    /* 1C49BC 002C49BC 8819040C */  jal        func_00106620
    /* 1C49C0 002C49C0 00000000 */   nop
    /* 1C49C4 002C49C4 1B000224 */  addiu      $2, $0, 0x1B
    /* 1C49C8 002C49C8 000022A2 */  sb         $2, 0x0($17)
  .L002C49CC:
    /* 1C49CC 002C49CC 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C49D0 002C49D0 2D280000 */  daddu      $5, $0, $0
    /* 1C49D4 002C49D4 2D300000 */  daddu      $6, $0, $0
    /* 1C49D8 002C49D8 3C810B0C */  jal        func_002e04f0
    /* 1C49DC 002C49DC 00000000 */   nop
    /* 1C49E0 002C49E0 900C248E */  lw         $4, 0xC90($17)
    /* 1C49E4 002C49E4 2D280000 */  daddu      $5, $0, $0
    /* 1C49E8 002C49E8 2D300000 */  daddu      $6, $0, $0
    /* 1C49EC 002C49EC 3C810B0C */  jal        func_002e04f0
    /* 1C49F0 002C49F0 00000000 */   nop
    /* 1C49F4 002C49F4 9C890B0C */  jal        func_002e2670
    /* 1C49F8 002C49F8 00000000 */   nop
    /* 1C49FC 002C49FC 06004128 */  slti       $1, $2, 0x6
    /* 1C4A00 002C4A00 0B002014 */  bnez       $1, .L002C4A30
    /* 1C4A04 002C4A04 00000000 */   nop
    /* 1C4A08 002C4A08 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4A0C 002C4A0C 2D280000 */  daddu      $5, $0, $0
    /* 1C4A10 002C4A10 2D300000 */  daddu      $6, $0, $0
    /* 1C4A14 002C4A14 3C810B0C */  jal        func_002e04f0
    /* 1C4A18 002C4A18 00000000 */   nop
    /* 1C4A1C 002C4A1C D00D248E */  lw         $4, 0xDD0($17)
    /* 1C4A20 002C4A20 2D280000 */  daddu      $5, $0, $0
    /* 1C4A24 002C4A24 2D300000 */  daddu      $6, $0, $0
    /* 1C4A28 002C4A28 3C810B0C */  jal        func_002e04f0
    /* 1C4A2C 002C4A2C 00000000 */   nop
  .L002C4A30:
    /* 1C4A30 002C4A30 2D208002 */  daddu      $4, $20, $0
    /* 1C4A34 002C4A34 C05C0B0C */  jal        func_002d7300
    /* 1C4A38 002C4A38 00000000 */   nop
    /* 1C4A3C 002C4A3C 3A170010 */  b          .L002CA728
    /* 1C4A40 002C4A40 00000000 */   nop
    /* 1C4A44 002C4A44 2D208002 */  daddu      $4, $20, $0
    /* 1C4A48 002C4A48 10540B0C */  jal        func_002d5040
    /* 1C4A4C 002C4A4C 00000000 */   nop
    /* 1C4A50 002C4A50 2D208002 */  daddu      $4, $20, $0
    /* 1C4A54 002C4A54 01000524 */  addiu      $5, $0, 0x1
    /* 1C4A58 002C4A58 B02D0B0C */  jal        func_002cb6c0
    /* 1C4A5C 002C4A5C 00000000 */   nop
    /* 1C4A60 002C4A60 4E020224 */  addiu      $2, $0, 0x24E
    /* 1C4A64 002C4A64 00008244 */  mtc1       $2, $f0
    /* 1C4A68 002C4A68 00000000 */  nop
    /* 1C4A6C 002C4A6C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4A70 002C4A70 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1C4A74 002C4A74 00688244 */  mtc1       $2, $f13
    /* 1C4A78 002C4A78 D003A427 */  addiu      $4, $29, 0x3D0
    /* 1C4A7C 002C4A7C 5CCA0A0C */  jal        func_002b2970
    /* 1C4A80 002C4A80 00000000 */   nop
    /* 1C4A84 002C4A84 1407A427 */  addiu      $4, $29, 0x714
    /* 1C4A88 002C4A88 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C4A8C 002C4A8C 2D30A000 */  daddu      $6, $5, $0
    /* 1C4A90 002C4A90 2D38A000 */  daddu      $7, $5, $0
    /* 1C4A94 002C4A94 2D40A000 */  daddu      $8, $5, $0
    /* 1C4A98 002C4A98 98CA0A0C */  jal        func_002b2a60
    /* 1C4A9C 002C4A9C 00000000 */   nop
    /* 1C4AA0 002C4AA0 02002486 */  lh         $4, 0x2($17)
    /* 1C4AA4 002C4AA4 D0890B0C */  jal        func_002e2740
    /* 1C4AA8 002C4AA8 00000000 */   nop
    /* 1C4AAC 002C4AAC 3C240200 */  dsll32     $4, $2, 16
    /* 1C4AB0 002C4AB0 3F240400 */  dsra32     $4, $4, 16
    /* 1C4AB4 002C4AB4 A41A040C */  jal        func_00106a90
    /* 1C4AB8 002C4AB8 00000000 */   nop
    /* 1C4ABC 002C4ABC 2D904000 */  daddu      $18, $2, $0
    /* 1C4AC0 002C4AC0 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4AC4 002C4AC4 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4AC8 002C4AC8 DCA9110C */  jal        func_0046a770
    /* 1C4ACC 002C4ACC 00000000 */   nop
    /* 1C4AD0 002C4AD0 2D804000 */  daddu      $16, $2, $0
    /* 1C4AD4 002C4AD4 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4AD8 002C4AD8 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4ADC 002C4ADC DCA9110C */  jal        func_0046a770
    /* 1C4AE0 002C4AE0 00000000 */   nop
    /* 1C4AE4 002C4AE4 0000A2FF */  sd         $2, 0x0($29)
    /* 1C4AE8 002C4AE8 AA000224 */  addiu      $2, $0, 0xAA
    /* 1C4AEC 002C4AEC 0800A2FF */  sd         $2, 0x8($29)
    /* 1C4AF0 002C4AF0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C4AF4 002C4AF4 00608244 */  mtc1       $2, $f12
    /* 1C4AF8 002C4AF8 D003A4DF */  ld         $4, 0x3D0($29)
    /* 1C4AFC 002C4AFC 1407A58F */  lw         $5, 0x714($29)
    /* 1C4B00 002C4B00 11000624 */  addiu      $6, $0, 0x11
    /* 1C4B04 002C4B04 05000724 */  addiu      $7, $0, 0x5
    /* 1C4B08 002C4B08 2D404002 */  daddu      $8, $18, $0
    /* 1C4B0C 002C4B0C 70000924 */  addiu      $9, $0, 0x70
    /* 1C4B10 002C4B10 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1C4B14 002C4B14 2D580002 */  daddu      $11, $16, $0
    /* 1C4B18 002C4B18 342B0B0C */  jal        func_002cacd0
    /* 1C4B1C 002C4B1C 00000000 */   nop
    /* 1C4B20 002C4B20 10002482 */  lb         $4, 0x10($17)
    /* 1C4B24 002C4B24 A0ED0A0C */  jal        func_002bb680
    /* 1C4B28 002C4B28 00000000 */   nop
    /* 1C4B2C 002C4B2C 06004010 */  beqz       $2, .L002C4B48
    /* 1C4B30 002C4B30 00000000 */   nop
    /* 1C4B34 002C4B34 10002482 */  lb         $4, 0x10($17)
    /* 1C4B38 002C4B38 3CEF0A0C */  jal        func_002bbcf0
    /* 1C4B3C 002C4B3C 00000000 */   nop
    /* 1C4B40 002C4B40 F9160010 */  b          .L002CA728
    /* 1C4B44 002C4B44 00000000 */   nop
  .L002C4B48:
    /* 1C4B48 002C4B48 10002482 */  lb         $4, 0x10($17)
    /* 1C4B4C 002C4B4C 70EC0A0C */  jal        func_002bb1c0
    /* 1C4B50 002C4B50 00000000 */   nop
    /* 1C4B54 002C4B54 18004014 */  bnez       $2, .L002C4BB8
    /* 1C4B58 002C4B58 00000000 */   nop
    /* 1C4B5C 002C4B5C 08002282 */  lb         $2, 0x8($17)
    /* 1C4B60 002C4B60 21105100 */  addu       $2, $2, $17
    /* 1C4B64 002C4B64 730F4480 */  lb         $4, 0xF73($2)
    /* 1C4B68 002C4B68 07002582 */  lb         $5, 0x7($17)
    /* 1C4B6C 002C4B6C 341B040C */  jal        func_00106cd0
    /* 1C4B70 002C4B70 00000000 */   nop
    /* 1C4B74 002C4B74 2D204000 */  daddu      $4, $2, $0
    /* 1C4B78 002C4B78 A41A040C */  jal        func_00106a90
    /* 1C4B7C 002C4B7C 00000000 */   nop
    /* 1C4B80 002C4B80 82800200 */  srl        $16, $2, 2
    /* 1C4B84 002C4B84 989E0B0C */  jal        func_002e7a60
    /* 1C4B88 002C4B88 00000000 */   nop
    /* 1C4B8C 002C4B8C 21205000 */  addu       $4, $2, $16
    /* 1C4B90 002C4B90 A09E0B0C */  jal        func_002e7a80
    /* 1C4B94 002C4B94 00000000 */   nop
    /* 1C4B98 002C4B98 2D200000 */  daddu      $4, $0, $0
    /* 1C4B9C 002C4B9C 2D280000 */  daddu      $5, $0, $0
    /* 1C4BA0 002C4BA0 2D300000 */  daddu      $6, $0, $0
    /* 1C4BA4 002C4BA4 06000724 */  addiu      $7, $0, 0x6
    /* 1C4BA8 002C4BA8 D86B110C */  jal        func_0045af60
    /* 1C4BAC 002C4BAC 00000000 */   nop
    /* 1C4BB0 002C4BB0 17000010 */  b          .L002C4C10
    /* 1C4BB4 002C4BB4 00000000 */   nop
  .L002C4BB8:
    /* 1C4BB8 002C4BB8 08002282 */  lb         $2, 0x8($17)
    /* 1C4BBC 002C4BBC 21105100 */  addu       $2, $2, $17
    /* 1C4BC0 002C4BC0 730F4480 */  lb         $4, 0xF73($2)
    /* 1C4BC4 002C4BC4 07002582 */  lb         $5, 0x7($17)
    /* 1C4BC8 002C4BC8 341B040C */  jal        func_00106cd0
    /* 1C4BCC 002C4BCC 00000000 */   nop
    /* 1C4BD0 002C4BD0 2D804000 */  daddu      $16, $2, $0
    /* 1C4BD4 002C4BD4 08002282 */  lb         $2, 0x8($17)
    /* 1C4BD8 002C4BD8 21105100 */  addu       $2, $2, $17
    /* 1C4BDC 002C4BDC 730F4480 */  lb         $4, 0xF73($2)
    /* 1C4BE0 002C4BE0 07002582 */  lb         $5, 0x7($17)
    /* 1C4BE4 002C4BE4 341B040C */  jal        func_00106cd0
    /* 1C4BE8 002C4BE8 00000000 */   nop
    /* 1C4BEC 002C4BEC 2D204000 */  daddu      $4, $2, $0
    /* 1C4BF0 002C4BF0 8019040C */  jal        func_00106600
    /* 1C4BF4 002C4BF4 00000000 */   nop
    /* 1C4BF8 002C4BF8 FF004230 */  andi       $2, $2, 0xFF
    /* 1C4BFC 002C4BFC 01004224 */  addiu      $2, $2, 0x1
    /* 1C4C00 002C4C00 FF004530 */  andi       $5, $2, 0xFF
    /* 1C4C04 002C4C04 2D200002 */  daddu      $4, $16, $0
    /* 1C4C08 002C4C08 8819040C */  jal        func_00106620
    /* 1C4C0C 002C4C0C 00000000 */   nop
  .L002C4C10:
    /* 1C4C10 002C4C10 02002486 */  lh         $4, 0x2($17)
    /* 1C4C14 002C4C14 D0890B0C */  jal        func_002e2740
    /* 1C4C18 002C4C18 00000000 */   nop
    /* 1C4C1C 002C4C1C 3C340200 */  dsll32     $6, $2, 16
    /* 1C4C20 002C4C20 3F340600 */  dsra32     $6, $6, 16
    /* 1C4C24 002C4C24 08002282 */  lb         $2, 0x8($17)
    /* 1C4C28 002C4C28 21105100 */  addu       $2, $2, $17
    /* 1C4C2C 002C4C2C 730F4480 */  lb         $4, 0xF73($2)
    /* 1C4C30 002C4C30 07002582 */  lb         $5, 0x7($17)
    /* 1C4C34 002C4C34 501B040C */  jal        func_00106d40
    /* 1C4C38 002C4C38 00000000 */   nop
    /* 1C4C3C 002C4C3C 10002482 */  lb         $4, 0x10($17)
    /* 1C4C40 002C4C40 54ED0A0C */  jal        func_002bb550
    /* 1C4C44 002C4C44 00000000 */   nop
    /* 1C4C48 002C4C48 1B000224 */  addiu      $2, $0, 0x1B
    /* 1C4C4C 002C4C4C 000022A2 */  sb         $2, 0x0($17)
    /* 1C4C50 002C4C50 B5160010 */  b          .L002CA728
    /* 1C4C54 002C4C54 00000000 */   nop
    /* 1C4C58 002C4C58 2D208002 */  daddu      $4, $20, $0
    /* 1C4C5C 002C4C5C 01000524 */  addiu      $5, $0, 0x1
    /* 1C4C60 002C4C60 B02D0B0C */  jal        func_002cb6c0
    /* 1C4C64 002C4C64 00000000 */   nop
    /* 1C4C68 002C4C68 4E020224 */  addiu      $2, $0, 0x24E
    /* 1C4C6C 002C4C6C 00008244 */  mtc1       $2, $f0
    /* 1C4C70 002C4C70 00000000 */  nop
    /* 1C4C74 002C4C74 20038046 */  cvt.s.w    $f12, $f0
    /* 1C4C78 002C4C78 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1C4C7C 002C4C7C 00688244 */  mtc1       $2, $f13
    /* 1C4C80 002C4C80 C803A427 */  addiu      $4, $29, 0x3C8
    /* 1C4C84 002C4C84 5CCA0A0C */  jal        func_002b2970
    /* 1C4C88 002C4C88 00000000 */   nop
    /* 1C4C8C 002C4C8C 1007A427 */  addiu      $4, $29, 0x710
    /* 1C4C90 002C4C90 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C4C94 002C4C94 2D30A000 */  daddu      $6, $5, $0
    /* 1C4C98 002C4C98 2D38A000 */  daddu      $7, $5, $0
    /* 1C4C9C 002C4C9C 2D40A000 */  daddu      $8, $5, $0
    /* 1C4CA0 002C4CA0 98CA0A0C */  jal        func_002b2a60
    /* 1C4CA4 002C4CA4 00000000 */   nop
    /* 1C4CA8 002C4CA8 02002486 */  lh         $4, 0x2($17)
    /* 1C4CAC 002C4CAC D0890B0C */  jal        func_002e2740
    /* 1C4CB0 002C4CB0 00000000 */   nop
    /* 1C4CB4 002C4CB4 3C240200 */  dsll32     $4, $2, 16
    /* 1C4CB8 002C4CB8 3F240400 */  dsra32     $4, $4, 16
    /* 1C4CBC 002C4CBC A41A040C */  jal        func_00106a90
    /* 1C4CC0 002C4CC0 00000000 */   nop
    /* 1C4CC4 002C4CC4 2D904000 */  daddu      $18, $2, $0
    /* 1C4CC8 002C4CC8 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4CCC 002C4CCC A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4CD0 002C4CD0 DCA9110C */  jal        func_0046a770
    /* 1C4CD4 002C4CD4 00000000 */   nop
    /* 1C4CD8 002C4CD8 2D804000 */  daddu      $16, $2, $0
    /* 1C4CDC 002C4CDC 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C4CE0 002C4CE0 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C4CE4 002C4CE4 DCA9110C */  jal        func_0046a770
    /* 1C4CE8 002C4CE8 00000000 */   nop
    /* 1C4CEC 002C4CEC 0000A2FF */  sd         $2, 0x0($29)
    /* 1C4CF0 002C4CF0 AA000224 */  addiu      $2, $0, 0xAA
    /* 1C4CF4 002C4CF4 0800A2FF */  sd         $2, 0x8($29)
    /* 1C4CF8 002C4CF8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C4CFC 002C4CFC 00608244 */  mtc1       $2, $f12
    /* 1C4D00 002C4D00 C803A4DF */  ld         $4, 0x3C8($29)
    /* 1C4D04 002C4D04 1007A58F */  lw         $5, 0x710($29)
    /* 1C4D08 002C4D08 11000624 */  addiu      $6, $0, 0x11
    /* 1C4D0C 002C4D0C 05000724 */  addiu      $7, $0, 0x5
    /* 1C4D10 002C4D10 2D404002 */  daddu      $8, $18, $0
    /* 1C4D14 002C4D14 70000924 */  addiu      $9, $0, 0x70
    /* 1C4D18 002C4D18 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1C4D1C 002C4D1C 2D580002 */  daddu      $11, $16, $0
    /* 1C4D20 002C4D20 342B0B0C */  jal        func_002cacd0
    /* 1C4D24 002C4D24 00000000 */   nop
    /* 1C4D28 002C4D28 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4D2C 002C4D2C 09000524 */  addiu      $5, $0, 0x9
    /* 1C4D30 002C4D30 5C810B0C */  jal        func_002e0570
    /* 1C4D34 002C4D34 00000000 */   nop
    /* 1C4D38 002C4D38 3C160200 */  dsll32     $2, $2, 24
    /* 1C4D3C 002C4D3C 3F160200 */  dsra32     $2, $2, 24
    /* 1C4D40 002C4D40 79164014 */  bnez       $2, .L002CA728
    /* 1C4D44 002C4D44 00000000 */   nop
    /* 1C4D48 002C4D48 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C4D4C 002C4D4C 09000524 */  addiu      $5, $0, 0x9
    /* 1C4D50 002C4D50 5C810B0C */  jal        func_002e0570
    /* 1C4D54 002C4D54 00000000 */   nop
    /* 1C4D58 002C4D58 3C160200 */  dsll32     $2, $2, 24
    /* 1C4D5C 002C4D5C 3F160200 */  dsra32     $2, $2, 24
    /* 1C4D60 002C4D60 71164014 */  bnez       $2, .L002CA728
    /* 1C4D64 002C4D64 00000000 */   nop
    /* 1C4D68 002C4D68 60C1023C */  lui        $2, (0xC1600000 >> 16)
    /* 1C4D6C 002C4D6C 00608244 */  mtc1       $2, $f12
    /* 1C4D70 002C4D70 DC42023C */  lui        $2, (0x42DC0000 >> 16)
    /* 1C4D74 002C4D74 00688244 */  mtc1       $2, $f13
    /* 1C4D78 002C4D78 6C0D248E */  lw         $4, 0xD6C($17)
    /* 1C4D7C 002C4D7C 2D280000 */  daddu      $5, $0, $0
    /* 1C4D80 002C4D80 04000624 */  addiu      $6, $0, 0x4
    /* 1C4D84 002C4D84 2D380000 */  daddu      $7, $0, $0
    /* 1C4D88 002C4D88 50820B0C */  jal        func_002e0940
    /* 1C4D8C 002C4D8C 00000000 */   nop
    /* 1C4D90 002C4D90 6400103C */  lui        $16, %hi(D_0063F7D0)
    /* 1C4D94 002C4D94 D0F71026 */  addiu      $16, $16, %lo(D_0063F7D0)
    /* 1C4D98 002C4D98 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C4D9C 002C4D9C 00608244 */  mtc1       $2, $f12
    /* 1C4DA0 002C4DA0 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* 1C4DA4 002C4DA4 00688244 */  mtc1       $2, $f13
    /* 1C4DA8 002C4DA8 700D248E */  lw         $4, 0xD70($17)
    /* 1C4DAC 002C4DAC 2D280000 */  daddu      $5, $0, $0
    /* 1C4DB0 002C4DB0 05000624 */  addiu      $6, $0, 0x5
    /* 1C4DB4 002C4DB4 2D380000 */  daddu      $7, $0, $0
    /* 1C4DB8 002C4DB8 A4810B0C */  jal        func_002e0690
    /* 1C4DBC 002C4DBC 00000000 */   nop
    /* 1C4DC0 002C4DC0 700D248E */  lw         $4, 0xD70($17)
    /* 1C4DC4 002C4DC4 38810B0C */  jal        func_002e04e0
    /* 1C4DC8 002C4DC8 00000000 */   nop
    /* 1C4DCC 002C4DCC 700D248E */  lw         $4, 0xD70($17)
    /* 1C4DD0 002C4DD0 62004590 */  lbu        $5, 0x62($2)
    /* 1C4DD4 002C4DD4 2D300000 */  daddu      $6, $0, $0
    /* 1C4DD8 002C4DD8 2D380000 */  daddu      $7, $0, $0
    /* 1C4DDC 002C4DDC 05000824 */  addiu      $8, $0, 0x5
    /* 1C4DE0 002C4DE0 2D480000 */  daddu      $9, $0, $0
    /* 1C4DE4 002C4DE4 98810B0C */  jal        func_002e0660
    /* 1C4DE8 002C4DE8 00000000 */   nop
    /* 1C4DEC 002C4DEC 280F248E */  lw         $4, 0xF28($17)
    /* 1C4DF0 002C4DF0 4E000524 */  addiu      $5, $0, 0x4E
    /* 1C4DF4 002C4DF4 80B4110C */  jal        func_0046d200
    /* 1C4DF8 002C4DF8 00000000 */   nop
    /* 1C4DFC 002C4DFC 2D904000 */  daddu      $18, $2, $0
    /* 1C4E00 002C4E00 C003A427 */  addiu      $4, $29, 0x3C0
    /* 1C4E04 002C4E04 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C4E08 002C4E08 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C4E0C 002C4E0C 5CCA0A0C */  jal        func_002b2970
    /* 1C4E10 002C4E10 00000000 */   nop
    /* 1C4E14 002C4E14 2D204002 */  daddu      $4, $18, $0
    /* 1C4E18 002C4E18 98AC110C */  jal        func_0046b260
    /* 1C4E1C 002C4E1C 00000000 */   nop
    /* 1C4E20 002C4E20 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C4E24 002C4E24 00088244 */  mtc1       $2, $f1
    /* 1C4E28 002C4E28 00000000 */  nop
    /* 1C4E2C 002C4E2C C3000146 */  div.s      $f3, $f0, $f1
    /* 1C4E30 002C4E30 2040023C */  lui        $2, (0x40200000 >> 16)
    /* 1C4E34 002C4E34 00108244 */  mtc1       $2, $f2
    /* 1C4E38 002C4E38 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1C4E3C 002C4E3C 00008044 */  mtc1       $0, $f0
    /* 1C4E40 002C4E40 00000000 */  nop
    /* 1C4E44 002C4E44 18000146 */  adda.s     $f0, $f1
    /* 1C4E48 002C4E48 1D150346 */  msub.s     $f20, $f2, $f3
    /* 1C4E4C 002C4E4C 2D204002 */  daddu      $4, $18, $0
    /* 1C4E50 002C4E50 BCAC110C */  jal        func_0046b2f0
    /* 1C4E54 002C4E54 00000000 */   nop
    /* 1C4E58 002C4E58 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C4E5C 002C4E5C 00088244 */  mtc1       $2, $f1
    /* 1C4E60 002C4E60 00000000 */  nop
    /* 1C4E64 002C4E64 C3000146 */  div.s      $f3, $f0, $f1
    /* 1C4E68 002C4E68 2040023C */  lui        $2, (0x40200000 >> 16)
    /* 1C4E6C 002C4E6C 00108244 */  mtc1       $2, $f2
    /* 1C4E70 002C4E70 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C4E74 002C4E74 00008044 */  mtc1       $0, $f0
    /* 1C4E78 002C4E78 00000000 */  nop
    /* 1C4E7C 002C4E7C 18000146 */  adda.s     $f0, $f1
    /* 1C4E80 002C4E80 5D130346 */  msub.s     $f13, $f2, $f3
    /* 1C4E84 002C4E84 B803A427 */  addiu      $4, $29, 0x3B8
    /* 1C4E88 002C4E88 06A30046 */  mov.s      $f12, $f20
    /* 1C4E8C 002C4E8C 5CCA0A0C */  jal        func_002b2970
    /* 1C4E90 002C4E90 00000000 */   nop
    /* 1C4E94 002C4E94 700D248E */  lw         $4, 0xD70($17)
    /* 1C4E98 002C4E98 C003A5DF */  ld         $5, 0x3C0($29)
    /* 1C4E9C 002C4E9C B803A6DF */  ld         $6, 0x3B8($29)
    /* 1C4EA0 002C4EA0 2D380000 */  daddu      $7, $0, $0
    /* 1C4EA4 002C4EA4 05000824 */  addiu      $8, $0, 0x5
    /* 1C4EA8 002C4EA8 2D480000 */  daddu      $9, $0, $0
    /* 1C4EAC 002C4EAC 88810B0C */  jal        func_002e0620
    /* 1C4EB0 002C4EB0 00000000 */   nop
    /* 1C4EB4 002C4EB4 2D204002 */  daddu      $4, $18, $0
    /* 1C4EB8 002C4EB8 A0B4110C */  jal        func_0046d280
    /* 1C4EBC 002C4EBC 00000000 */   nop
    /* 1C4EC0 002C4EC0 7C0D248E */  lw         $4, 0xD7C($17)
    /* 1C4EC4 002C4EC4 38810B0C */  jal        func_002e04e0
    /* 1C4EC8 002C4EC8 00000000 */   nop
    /* 1C4ECC 002C4ECC 7C0D248E */  lw         $4, 0xD7C($17)
    /* 1C4ED0 002C4ED0 62004590 */  lbu        $5, 0x62($2)
    /* 1C4ED4 002C4ED4 2D300000 */  daddu      $6, $0, $0
    /* 1C4ED8 002C4ED8 2D380000 */  daddu      $7, $0, $0
    /* 1C4EDC 002C4EDC 05000824 */  addiu      $8, $0, 0x5
    /* 1C4EE0 002C4EE0 2D480000 */  daddu      $9, $0, $0
    /* 1C4EE4 002C4EE4 98810B0C */  jal        func_002e0660
    /* 1C4EE8 002C4EE8 00000000 */   nop
    /* 1C4EEC 002C4EEC 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C4EF0 002C4EF0 38810B0C */  jal        func_002e04e0
    /* 1C4EF4 002C4EF4 00000000 */   nop
    /* 1C4EF8 002C4EF8 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C4EFC 002C4EFC 62004590 */  lbu        $5, 0x62($2)
    /* 1C4F00 002C4F00 2D300000 */  daddu      $6, $0, $0
    /* 1C4F04 002C4F04 2D380000 */  daddu      $7, $0, $0
    /* 1C4F08 002C4F08 05000824 */  addiu      $8, $0, 0x5
    /* 1C4F0C 002C4F0C 2D480000 */  daddu      $9, $0, $0
    /* 1C4F10 002C4F10 98810B0C */  jal        func_002e0660
    /* 1C4F14 002C4F14 00000000 */   nop
    /* 1C4F18 002C4F18 900C248E */  lw         $4, 0xC90($17)
    /* 1C4F1C 002C4F1C 38810B0C */  jal        func_002e04e0
    /* 1C4F20 002C4F20 00000000 */   nop
    /* 1C4F24 002C4F24 900C248E */  lw         $4, 0xC90($17)
    /* 1C4F28 002C4F28 62004590 */  lbu        $5, 0x62($2)
    /* 1C4F2C 002C4F2C 2D300000 */  daddu      $6, $0, $0
    /* 1C4F30 002C4F30 2D380000 */  daddu      $7, $0, $0
    /* 1C4F34 002C4F34 05000824 */  addiu      $8, $0, 0x5
    /* 1C4F38 002C4F38 2D480000 */  daddu      $9, $0, $0
    /* 1C4F3C 002C4F3C 98810B0C */  jal        func_002e0660
    /* 1C4F40 002C4F40 00000000 */   nop
    /* 1C4F44 002C4F44 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4F48 002C4F48 38810B0C */  jal        func_002e04e0
    /* 1C4F4C 002C4F4C 00000000 */   nop
    /* 1C4F50 002C4F50 2D804000 */  daddu      $16, $2, $0
    /* 1C4F54 002C4F54 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4F58 002C4F58 38810B0C */  jal        func_002e04e0
    /* 1C4F5C 002C4F5C 00000000 */   nop
    /* 1C4F60 002C4F60 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C4F64 002C4F64 7A44023C */  lui        $2, (0x447A0000 >> 16)
    /* 1C4F68 002C4F68 00008244 */  mtc1       $2, $f0
    /* 1C4F6C 002C4F6C 00000000 */  nop
    /* 1C4F70 002C4F70 010D0046 */  sub.s      $f20, $f1, $f0
    /* 1C4F74 002C4F74 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4F78 002C4F78 38810B0C */  jal        func_002e04e0
    /* 1C4F7C 002C4F7C 00000000 */   nop
    /* 1C4F80 002C4F80 B003A427 */  addiu      $4, $29, 0x3B0
    /* 1C4F84 002C4F84 06A30046 */  mov.s      $f12, $f20
    /* 1C4F88 002C4F88 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C4F8C 002C4F8C 5CCA0A0C */  jal        func_002b2970
    /* 1C4F90 002C4F90 00000000 */   nop
    /* 1C4F94 002C4F94 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C4F98 002C4F98 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C4F9C 002C4F9C 3300056A */  ldl        $5, 0x33($16)
    /* 1C4FA0 002C4FA0 B003A6DF */  ld         $6, 0x3B0($29)
    /* 1C4FA4 002C4FA4 02000724 */  addiu      $7, $0, 0x2
    /* 1C4FA8 002C4FA8 03000824 */  addiu      $8, $0, 0x3
    /* 1C4FAC 002C4FAC 2D480000 */  daddu      $9, $0, $0
    /* 1C4FB0 002C4FB0 88810B0C */  jal        func_002e0620
    /* 1C4FB4 002C4FB4 00000000 */   nop
    /* 1C4FB8 002C4FB8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C4FBC 002C4FBC 38810B0C */  jal        func_002e04e0
    /* 1C4FC0 002C4FC0 00000000 */   nop
    /* 1C4FC4 002C4FC4 2D804000 */  daddu      $16, $2, $0
    /* 1C4FC8 002C4FC8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C4FCC 002C4FCC 38810B0C */  jal        func_002e04e0
    /* 1C4FD0 002C4FD0 00000000 */   nop
    /* 1C4FD4 002C4FD4 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C4FD8 002C4FD8 7A44023C */  lui        $2, (0x447A0000 >> 16)
    /* 1C4FDC 002C4FDC 00008244 */  mtc1       $2, $f0
    /* 1C4FE0 002C4FE0 00000000 */  nop
    /* 1C4FE4 002C4FE4 010D0046 */  sub.s      $f20, $f1, $f0
    /* 1C4FE8 002C4FE8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C4FEC 002C4FEC 38810B0C */  jal        func_002e04e0
    /* 1C4FF0 002C4FF0 00000000 */   nop
    /* 1C4FF4 002C4FF4 A803A427 */  addiu      $4, $29, 0x3A8
    /* 1C4FF8 002C4FF8 06A30046 */  mov.s      $f12, $f20
    /* 1C4FFC 002C4FFC 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1C5000 002C5000 5CCA0A0C */  jal        func_002b2970
    /* 1C5004 002C5004 00000000 */   nop
    /* 1C5008 002C5008 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C500C 002C500C 2C00056E */  ldr        $5, 0x2C($16)
    /* 1C5010 002C5010 3300056A */  ldl        $5, 0x33($16)
    /* 1C5014 002C5014 A803A6DF */  ld         $6, 0x3A8($29)
    /* 1C5018 002C5018 02000724 */  addiu      $7, $0, 0x2
    /* 1C501C 002C501C 03000824 */  addiu      $8, $0, 0x3
    /* 1C5020 002C5020 2D480000 */  daddu      $9, $0, $0
    /* 1C5024 002C5024 88810B0C */  jal        func_002e0620
    /* 1C5028 002C5028 00000000 */   nop
    /* 1C502C 002C502C E40D248E */  lw         $4, 0xDE4($17)
    /* 1C5030 002C5030 2D280000 */  daddu      $5, $0, $0
    /* 1C5034 002C5034 01000624 */  addiu      $6, $0, 0x1
    /* 1C5038 002C5038 3C810B0C */  jal        func_002e04f0
    /* 1C503C 002C503C 00000000 */   nop
    /* 1C5040 002C5040 E00D248E */  lw         $4, 0xDE0($17)
    /* 1C5044 002C5044 2D280000 */  daddu      $5, $0, $0
    /* 1C5048 002C5048 2D300000 */  daddu      $6, $0, $0
    /* 1C504C 002C504C 3C810B0C */  jal        func_002e04f0
    /* 1C5050 002C5050 00000000 */   nop
    /* 1C5054 002C5054 640C248E */  lw         $4, 0xC64($17)
    /* 1C5058 002C5058 38810B0C */  jal        func_002e04e0
    /* 1C505C 002C505C 00000000 */   nop
    /* 1C5060 002C5060 640C248E */  lw         $4, 0xC64($17)
    /* 1C5064 002C5064 62004590 */  lbu        $5, 0x62($2)
    /* 1C5068 002C5068 2D300000 */  daddu      $6, $0, $0
    /* 1C506C 002C506C 2D380000 */  daddu      $7, $0, $0
    /* 1C5070 002C5070 0A000824 */  addiu      $8, $0, 0xA
    /* 1C5074 002C5074 2D480000 */  daddu      $9, $0, $0
    /* 1C5078 002C5078 98810B0C */  jal        func_002e0660
    /* 1C507C 002C507C 00000000 */   nop
    /* 1C5080 002C5080 6400103C */  lui        $16, %hi(D_0063F5B0)
    /* 1C5084 002C5084 B0F51026 */  addiu      $16, $16, %lo(D_0063F5B0)
    /* 1C5088 002C5088 DA42023C */  lui        $2, (0x42DA0000 >> 16)
    /* 1C508C 002C508C 00608244 */  mtc1       $2, $f12
    /* 1C5090 002C5090 600C248E */  lw         $4, 0xC60($17)
    /* 1C5094 002C5094 41000524 */  addiu      $5, $0, 0x41
    /* 1C5098 002C5098 78820B0C */  jal        func_002e09e0
    /* 1C509C 002C509C 00000000 */   nop
    /* 1C50A0 002C50A0 2544023C */  lui        $2, (0x44250000 >> 16)
    /* 1C50A4 002C50A4 00088244 */  mtc1       $2, $f1
    /* 1C50A8 002C50A8 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C50AC 002C50AC 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C50B0 002C50B0 A003A427 */  addiu      $4, $29, 0x3A0
    /* 1C50B4 002C50B4 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C50B8 002C50B8 5CCA0A0C */  jal        func_002b2970
    /* 1C50BC 002C50BC 00000000 */   nop
    /* 1C50C0 002C50C0 9803A427 */  addiu      $4, $29, 0x398
    /* 1C50C4 002C50C4 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C50C8 002C50C8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C50CC 002C50CC 5CCA0A0C */  jal        func_002b2970
    /* 1C50D0 002C50D0 00000000 */   nop
    /* 1C50D4 002C50D4 600C248E */  lw         $4, 0xC60($17)
    /* 1C50D8 002C50D8 A003A5DF */  ld         $5, 0x3A0($29)
    /* 1C50DC 002C50DC 9803A6DF */  ld         $6, 0x398($29)
    /* 1C50E0 002C50E0 2D380000 */  daddu      $7, $0, $0
    /* 1C50E4 002C50E4 04000824 */  addiu      $8, $0, 0x4
    /* 1C50E8 002C50E8 06000924 */  addiu      $9, $0, 0x6
    /* 1C50EC 002C50EC 88810B0C */  jal        func_002e0620
    /* 1C50F0 002C50F0 00000000 */   nop
    /* 1C50F4 002C50F4 CC001024 */  addiu      $16, $0, 0xCC
    /* 1C50F8 002C50F8 600C248E */  lw         $4, 0xC60($17)
    /* 1C50FC 002C50FC 38810B0C */  jal        func_002e04e0
    /* 1C5100 002C5100 00000000 */   nop
    /* 1C5104 002C5104 620050A0 */  sb         $16, 0x62($2)
    /* 1C5108 002C5108 0C07A427 */  addiu      $4, $29, 0x70C
    /* 1C510C 002C510C 2D280000 */  daddu      $5, $0, $0
    /* 1C5110 002C5110 2D300000 */  daddu      $6, $0, $0
    /* 1C5114 002C5114 2D380000 */  daddu      $7, $0, $0
    /* 1C5118 002C5118 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C511C 002C511C 98CA0A0C */  jal        func_002b2a60
    /* 1C5120 002C5120 00000000 */   nop
    /* 1C5124 002C5124 600C248E */  lw         $4, 0xC60($17)
    /* 1C5128 002C5128 38810B0C */  jal        func_002e04e0
    /* 1C512C 002C512C 00000000 */   nop
    /* 1C5130 002C5130 0C07A693 */  lbu        $6, 0x70C($29)
    /* 1C5134 002C5134 0D07A593 */  lbu        $5, 0x70D($29)
    /* 1C5138 002C5138 0E07A493 */  lbu        $4, 0x70E($29)
    /* 1C513C 002C513C 0F07A393 */  lbu        $3, 0x70F($29)
    /* 1C5140 002C5140 790046A0 */  sb         $6, 0x79($2)
    /* 1C5144 002C5144 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C5148 002C5148 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C514C 002C514C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C5150 002C5150 6400103C */  lui        $16, %hi(D_0063F5F0)
    /* 1C5154 002C5154 F0F51026 */  addiu      $16, $16, %lo(D_0063F5F0)
    /* 1C5158 002C5158 DA42023C */  lui        $2, (0x42DA0000 >> 16)
    /* 1C515C 002C515C 00608244 */  mtc1       $2, $f12
    /* 1C5160 002C5160 800C248E */  lw         $4, 0xC80($17)
    /* 1C5164 002C5164 41000524 */  addiu      $5, $0, 0x41
    /* 1C5168 002C5168 78820B0C */  jal        func_002e09e0
    /* 1C516C 002C516C 00000000 */   nop
    /* 1C5170 002C5170 2544023C */  lui        $2, (0x44250000 >> 16)
    /* 1C5174 002C5174 00088244 */  mtc1       $2, $f1
    /* 1C5178 002C5178 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C517C 002C517C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C5180 002C5180 9003A427 */  addiu      $4, $29, 0x390
    /* 1C5184 002C5184 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C5188 002C5188 5CCA0A0C */  jal        func_002b2970
    /* 1C518C 002C518C 00000000 */   nop
    /* 1C5190 002C5190 8803A427 */  addiu      $4, $29, 0x388
    /* 1C5194 002C5194 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C5198 002C5198 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C519C 002C519C 5CCA0A0C */  jal        func_002b2970
    /* 1C51A0 002C51A0 00000000 */   nop
    /* 1C51A4 002C51A4 800C248E */  lw         $4, 0xC80($17)
    /* 1C51A8 002C51A8 9003A5DF */  ld         $5, 0x390($29)
    /* 1C51AC 002C51AC 8803A6DF */  ld         $6, 0x388($29)
    /* 1C51B0 002C51B0 2D380000 */  daddu      $7, $0, $0
    /* 1C51B4 002C51B4 04000824 */  addiu      $8, $0, 0x4
    /* 1C51B8 002C51B8 06000924 */  addiu      $9, $0, 0x6
    /* 1C51BC 002C51BC 88810B0C */  jal        func_002e0620
    /* 1C51C0 002C51C0 00000000 */   nop
    /* 1C51C4 002C51C4 CC001024 */  addiu      $16, $0, 0xCC
    /* 1C51C8 002C51C8 800C248E */  lw         $4, 0xC80($17)
    /* 1C51CC 002C51CC 38810B0C */  jal        func_002e04e0
    /* 1C51D0 002C51D0 00000000 */   nop
    /* 1C51D4 002C51D4 620050A0 */  sb         $16, 0x62($2)
    /* 1C51D8 002C51D8 0807A427 */  addiu      $4, $29, 0x708
    /* 1C51DC 002C51DC 2D280000 */  daddu      $5, $0, $0
    /* 1C51E0 002C51E0 2D300000 */  daddu      $6, $0, $0
    /* 1C51E4 002C51E4 2D380000 */  daddu      $7, $0, $0
    /* 1C51E8 002C51E8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C51EC 002C51EC 98CA0A0C */  jal        func_002b2a60
    /* 1C51F0 002C51F0 00000000 */   nop
    /* 1C51F4 002C51F4 800C248E */  lw         $4, 0xC80($17)
    /* 1C51F8 002C51F8 38810B0C */  jal        func_002e04e0
    /* 1C51FC 002C51FC 00000000 */   nop
    /* 1C5200 002C5200 0807A693 */  lbu        $6, 0x708($29)
    /* 1C5204 002C5204 0907A593 */  lbu        $5, 0x709($29)
    /* 1C5208 002C5208 0A07A493 */  lbu        $4, 0x70A($29)
    /* 1C520C 002C520C 0B07A393 */  lbu        $3, 0x70B($29)
    /* 1C5210 002C5210 790046A0 */  sb         $6, 0x79($2)
    /* 1C5214 002C5214 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C5218 002C5218 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C521C 002C521C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C5220 002C5220 6400103C */  lui        $16, %hi(D_0063F5D0)
    /* 1C5224 002C5224 D0F51026 */  addiu      $16, $16, %lo(D_0063F5D0)
    /* 1C5228 002C5228 DE42023C */  lui        $2, (0x42DE0000 >> 16)
    /* 1C522C 002C522C 00608244 */  mtc1       $2, $f12
    /* 1C5230 002C5230 700C248E */  lw         $4, 0xC70($17)
    /* 1C5234 002C5234 41000524 */  addiu      $5, $0, 0x41
    /* 1C5238 002C5238 78820B0C */  jal        func_002e09e0
    /* 1C523C 002C523C 00000000 */   nop
    /* 1C5240 002C5240 2544023C */  lui        $2, (0x44250000 >> 16)
    /* 1C5244 002C5244 00088244 */  mtc1       $2, $f1
    /* 1C5248 002C5248 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C524C 002C524C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C5250 002C5250 8003A427 */  addiu      $4, $29, 0x380
    /* 1C5254 002C5254 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C5258 002C5258 5CCA0A0C */  jal        func_002b2970
    /* 1C525C 002C525C 00000000 */   nop
    /* 1C5260 002C5260 7803A427 */  addiu      $4, $29, 0x378
    /* 1C5264 002C5264 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C5268 002C5268 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C526C 002C526C 5CCA0A0C */  jal        func_002b2970
    /* 1C5270 002C5270 00000000 */   nop
    /* 1C5274 002C5274 700C248E */  lw         $4, 0xC70($17)
    /* 1C5278 002C5278 8003A5DF */  ld         $5, 0x380($29)
    /* 1C527C 002C527C 7803A6DF */  ld         $6, 0x378($29)
    /* 1C5280 002C5280 2D380000 */  daddu      $7, $0, $0
    /* 1C5284 002C5284 04000824 */  addiu      $8, $0, 0x4
    /* 1C5288 002C5288 06000924 */  addiu      $9, $0, 0x6
    /* 1C528C 002C528C 88810B0C */  jal        func_002e0620
    /* 1C5290 002C5290 00000000 */   nop
    /* 1C5294 002C5294 CC001024 */  addiu      $16, $0, 0xCC
    /* 1C5298 002C5298 700C248E */  lw         $4, 0xC70($17)
    /* 1C529C 002C529C 38810B0C */  jal        func_002e04e0
    /* 1C52A0 002C52A0 00000000 */   nop
    /* 1C52A4 002C52A4 620050A0 */  sb         $16, 0x62($2)
    /* 1C52A8 002C52A8 0407A427 */  addiu      $4, $29, 0x704
    /* 1C52AC 002C52AC 2D280000 */  daddu      $5, $0, $0
    /* 1C52B0 002C52B0 2D300000 */  daddu      $6, $0, $0
    /* 1C52B4 002C52B4 2D380000 */  daddu      $7, $0, $0
    /* 1C52B8 002C52B8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C52BC 002C52BC 98CA0A0C */  jal        func_002b2a60
    /* 1C52C0 002C52C0 00000000 */   nop
    /* 1C52C4 002C52C4 700C248E */  lw         $4, 0xC70($17)
    /* 1C52C8 002C52C8 38810B0C */  jal        func_002e04e0
    /* 1C52CC 002C52CC 00000000 */   nop
    /* 1C52D0 002C52D0 0407A693 */  lbu        $6, 0x704($29)
    /* 1C52D4 002C52D4 0507A593 */  lbu        $5, 0x705($29)
    /* 1C52D8 002C52D8 0607A493 */  lbu        $4, 0x706($29)
    /* 1C52DC 002C52DC 0707A393 */  lbu        $3, 0x707($29)
    /* 1C52E0 002C52E0 790046A0 */  sb         $6, 0x79($2)
    /* 1C52E4 002C52E4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C52E8 002C52E8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C52EC 002C52EC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C52F0 002C52F0 DA42023C */  lui        $2, (0x42DA0000 >> 16)
    /* 1C52F4 002C52F4 00608244 */  mtc1       $2, $f12
    /* 1C52F8 002C52F8 800E248E */  lw         $4, 0xE80($17)
    /* 1C52FC 002C52FC 41000524 */  addiu      $5, $0, 0x41
    /* 1C5300 002C5300 78820B0C */  jal        func_002e09e0
    /* 1C5304 002C5304 00000000 */   nop
    /* 1C5308 002C5308 9AFD0224 */  addiu      $2, $0, -0x266
    /* 1C530C 002C530C 00008244 */  mtc1       $2, $f0
    /* 1C5310 002C5310 00000000 */  nop
    /* 1C5314 002C5314 20038046 */  cvt.s.w    $f12, $f0
    /* 1C5318 002C5318 7243023C */  lui        $2, (0x43720000 >> 16)
    /* 1C531C 002C531C 00688244 */  mtc1       $2, $f13
    /* 1C5320 002C5320 7003A427 */  addiu      $4, $29, 0x370
    /* 1C5324 002C5324 5CCA0A0C */  jal        func_002b2970
    /* 1C5328 002C5328 00000000 */   nop
    /* 1C532C 002C532C AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1C5330 002C5330 00608244 */  mtc1       $2, $f12
    /* 1C5334 002C5334 7243023C */  lui        $2, (0x43720000 >> 16)
    /* 1C5338 002C5338 00688244 */  mtc1       $2, $f13
    /* 1C533C 002C533C 6803A427 */  addiu      $4, $29, 0x368
    /* 1C5340 002C5340 5CCA0A0C */  jal        func_002b2970
    /* 1C5344 002C5344 00000000 */   nop
    /* 1C5348 002C5348 800E248E */  lw         $4, 0xE80($17)
    /* 1C534C 002C534C 7003A5DF */  ld         $5, 0x370($29)
    /* 1C5350 002C5350 6803A6DF */  ld         $6, 0x368($29)
    /* 1C5354 002C5354 2D380000 */  daddu      $7, $0, $0
    /* 1C5358 002C5358 04000824 */  addiu      $8, $0, 0x4
    /* 1C535C 002C535C 06000924 */  addiu      $9, $0, 0x6
    /* 1C5360 002C5360 88810B0C */  jal        func_002e0620
    /* 1C5364 002C5364 00000000 */   nop
    /* 1C5368 002C5368 0007A427 */  addiu      $4, $29, 0x700
    /* 1C536C 002C536C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C5370 002C5370 CB000624 */  addiu      $6, $0, 0xCB
    /* 1C5374 002C5374 35000724 */  addiu      $7, $0, 0x35
    /* 1C5378 002C5378 2D40A000 */  daddu      $8, $5, $0
    /* 1C537C 002C537C 98CA0A0C */  jal        func_002b2a60
    /* 1C5380 002C5380 00000000 */   nop
    /* 1C5384 002C5384 800E248E */  lw         $4, 0xE80($17)
    /* 1C5388 002C5388 38810B0C */  jal        func_002e04e0
    /* 1C538C 002C538C 00000000 */   nop
    /* 1C5390 002C5390 0007A693 */  lbu        $6, 0x700($29)
    /* 1C5394 002C5394 0107A593 */  lbu        $5, 0x701($29)
    /* 1C5398 002C5398 0207A493 */  lbu        $4, 0x702($29)
    /* 1C539C 002C539C 0307A393 */  lbu        $3, 0x703($29)
    /* 1C53A0 002C53A0 790046A0 */  sb         $6, 0x79($2)
    /* 1C53A4 002C53A4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C53A8 002C53A8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C53AC 002C53AC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C53B0 002C53B0 6400103C */  lui        $16, %hi(D_0063F5F8)
    /* 1C53B4 002C53B4 F8F51026 */  addiu      $16, $16, %lo(D_0063F5F8)
    /* 1C53B8 002C53B8 E042023C */  lui        $2, (0x42E00000 >> 16)
    /* 1C53BC 002C53BC 00608244 */  mtc1       $2, $f12
    /* 1C53C0 002C53C0 840C248E */  lw         $4, 0xC84($17)
    /* 1C53C4 002C53C4 41000524 */  addiu      $5, $0, 0x41
    /* 1C53C8 002C53C8 78820B0C */  jal        func_002e09e0
    /* 1C53CC 002C53CC 00000000 */   nop
    /* 1C53D0 002C53D0 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1C53D4 002C53D4 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C53D8 002C53D8 00008244 */  mtc1       $2, $f0
    /* 1C53DC 002C53DC 00000000 */  nop
    /* 1C53E0 002C53E0 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C53E4 002C53E4 6003A427 */  addiu      $4, $29, 0x360
    /* 1C53E8 002C53E8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C53EC 002C53EC 5CCA0A0C */  jal        func_002b2970
    /* 1C53F0 002C53F0 00000000 */   nop
    /* 1C53F4 002C53F4 5803A427 */  addiu      $4, $29, 0x358
    /* 1C53F8 002C53F8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C53FC 002C53FC 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C5400 002C5400 5CCA0A0C */  jal        func_002b2970
    /* 1C5404 002C5404 00000000 */   nop
    /* 1C5408 002C5408 840C248E */  lw         $4, 0xC84($17)
    /* 1C540C 002C540C 6003A5DF */  ld         $5, 0x360($29)
    /* 1C5410 002C5410 5803A6DF */  ld         $6, 0x358($29)
    /* 1C5414 002C5414 2D380000 */  daddu      $7, $0, $0
    /* 1C5418 002C5418 04000824 */  addiu      $8, $0, 0x4
    /* 1C541C 002C541C 06000924 */  addiu      $9, $0, 0x6
    /* 1C5420 002C5420 88810B0C */  jal        func_002e0620
    /* 1C5424 002C5424 00000000 */   nop
    /* 1C5428 002C5428 FC06A427 */  addiu      $4, $29, 0x6FC
    /* 1C542C 002C542C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C5430 002C5430 CB000624 */  addiu      $6, $0, 0xCB
    /* 1C5434 002C5434 35000724 */  addiu      $7, $0, 0x35
    /* 1C5438 002C5438 2D40A000 */  daddu      $8, $5, $0
    /* 1C543C 002C543C 98CA0A0C */  jal        func_002b2a60
    /* 1C5440 002C5440 00000000 */   nop
    /* 1C5444 002C5444 840C248E */  lw         $4, 0xC84($17)
    /* 1C5448 002C5448 38810B0C */  jal        func_002e04e0
    /* 1C544C 002C544C 00000000 */   nop
    /* 1C5450 002C5450 FC06A693 */  lbu        $6, 0x6FC($29)
    /* 1C5454 002C5454 FD06A593 */  lbu        $5, 0x6FD($29)
    /* 1C5458 002C5458 FE06A493 */  lbu        $4, 0x6FE($29)
    /* 1C545C 002C545C FF06A393 */  lbu        $3, 0x6FF($29)
    /* 1C5460 002C5460 790046A0 */  sb         $6, 0x79($2)
    /* 1C5464 002C5464 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C5468 002C5468 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C546C 002C546C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C5470 002C5470 6400103C */  lui        $16, %hi(D_0063F5D8)
    /* 1C5474 002C5474 D8F51026 */  addiu      $16, $16, %lo(D_0063F5D8)
    /* 1C5478 002C5478 E242023C */  lui        $2, (0x42E20000 >> 16)
    /* 1C547C 002C547C 00608244 */  mtc1       $2, $f12
    /* 1C5480 002C5480 740C248E */  lw         $4, 0xC74($17)
    /* 1C5484 002C5484 41000524 */  addiu      $5, $0, 0x41
    /* 1C5488 002C5488 78820B0C */  jal        func_002e09e0
    /* 1C548C 002C548C 00000000 */   nop
    /* 1C5490 002C5490 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1C5494 002C5494 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C5498 002C5498 00008244 */  mtc1       $2, $f0
    /* 1C549C 002C549C 00000000 */  nop
    /* 1C54A0 002C54A0 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C54A4 002C54A4 5003A427 */  addiu      $4, $29, 0x350
    /* 1C54A8 002C54A8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C54AC 002C54AC 5CCA0A0C */  jal        func_002b2970
    /* 1C54B0 002C54B0 00000000 */   nop
    /* 1C54B4 002C54B4 4803A427 */  addiu      $4, $29, 0x348
    /* 1C54B8 002C54B8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C54BC 002C54BC 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C54C0 002C54C0 5CCA0A0C */  jal        func_002b2970
    /* 1C54C4 002C54C4 00000000 */   nop
    /* 1C54C8 002C54C8 740C248E */  lw         $4, 0xC74($17)
    /* 1C54CC 002C54CC 5003A5DF */  ld         $5, 0x350($29)
    /* 1C54D0 002C54D0 4803A6DF */  ld         $6, 0x348($29)
    /* 1C54D4 002C54D4 2D380000 */  daddu      $7, $0, $0
    /* 1C54D8 002C54D8 04000824 */  addiu      $8, $0, 0x4
    /* 1C54DC 002C54DC 06000924 */  addiu      $9, $0, 0x6
    /* 1C54E0 002C54E0 88810B0C */  jal        func_002e0620
    /* 1C54E4 002C54E4 00000000 */   nop
    /* 1C54E8 002C54E8 6400103C */  lui        $16, %hi(D_0063F5E0)
    /* 1C54EC 002C54EC E0F51026 */  addiu      $16, $16, %lo(D_0063F5E0)
    /* 1C54F0 002C54F0 E442023C */  lui        $2, (0x42E40000 >> 16)
    /* 1C54F4 002C54F4 00608244 */  mtc1       $2, $f12
    /* 1C54F8 002C54F8 780C248E */  lw         $4, 0xC78($17)
    /* 1C54FC 002C54FC 41000524 */  addiu      $5, $0, 0x41
    /* 1C5500 002C5500 78820B0C */  jal        func_002e09e0
    /* 1C5504 002C5504 00000000 */   nop
    /* 1C5508 002C5508 000001C6 */  lwc1       $f1, 0x0($16)
    /* 1C550C 002C550C 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C5510 002C5510 00008244 */  mtc1       $2, $f0
    /* 1C5514 002C5514 00000000 */  nop
    /* 1C5518 002C5518 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C551C 002C551C 4003A427 */  addiu      $4, $29, 0x340
    /* 1C5520 002C5520 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C5524 002C5524 5CCA0A0C */  jal        func_002b2970
    /* 1C5528 002C5528 00000000 */   nop
    /* 1C552C 002C552C 3803A427 */  addiu      $4, $29, 0x338
    /* 1C5530 002C5530 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C5534 002C5534 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C5538 002C5538 5CCA0A0C */  jal        func_002b2970
    /* 1C553C 002C553C 00000000 */   nop
    /* 1C5540 002C5540 780C248E */  lw         $4, 0xC78($17)
    /* 1C5544 002C5544 4003A5DF */  ld         $5, 0x340($29)
    /* 1C5548 002C5548 3803A6DF */  ld         $6, 0x338($29)
    /* 1C554C 002C554C 2D380000 */  daddu      $7, $0, $0
    /* 1C5550 002C5550 04000824 */  addiu      $8, $0, 0x4
    /* 1C5554 002C5554 06000924 */  addiu      $9, $0, 0x6
    /* 1C5558 002C5558 88810B0C */  jal        func_002e0620
    /* 1C555C 002C555C 00000000 */   nop
    /* 1C5560 002C5560 21000224 */  addiu      $2, $0, 0x21
    /* 1C5564 002C5564 000022A2 */  sb         $2, 0x0($17)
    /* 1C5568 002C5568 6F140010 */  b          .L002CA728
    /* 1C556C 002C556C 00000000 */   nop
    /* 1C5570 002C5570 2D208002 */  daddu      $4, $20, $0
    /* 1C5574 002C5574 64450B0C */  jal        func_002d1590
    /* 1C5578 002C5578 00000000 */   nop
    /* 1C557C 002C557C 01000324 */  addiu      $3, $0, 0x1
    /* 1C5580 002C5580 69144314 */  bne        $2, $3, .L002CA728
    /* 1C5584 002C5584 00000000 */   nop
    /* 1C5588 002C5588 8C00023C */  lui        $2, %hi(D_008C0276)
    /* 1C558C 002C558C 76024494 */  lhu        $4, %lo(D_008C0276)($2)
    /* 1C5590 002C5590 00108230 */  andi       $2, $4, 0x1000
    /* 1C5594 002C5594 35004010 */  beqz       $2, .L002C566C
    /* 1C5598 002C5598 00000000 */   nop
    /* 1C559C 002C559C 14002282 */  lb         $2, 0x14($17)
    /* 1C55A0 002C55A0 32004014 */  bnez       $2, .L002C566C
    /* 1C55A4 002C55A4 00000000 */   nop
    /* 1C55A8 002C55A8 2D200000 */  daddu      $4, $0, $0
    /* 1C55AC 002C55AC 2D280000 */  daddu      $5, $0, $0
    /* 1C55B0 002C55B0 2D300000 */  daddu      $6, $0, $0
    /* 1C55B4 002C55B4 2D380000 */  daddu      $7, $0, $0
    /* 1C55B8 002C55B8 D86B110C */  jal        func_0045af60
    /* 1C55BC 002C55BC 00000000 */   nop
    /* 1C55C0 002C55C0 02002286 */  lh         $2, 0x2($17)
    /* 1C55C4 002C55C4 0F004014 */  bnez       $2, .L002C5604
    /* 1C55C8 002C55C8 00000000 */   nop
    /* 1C55CC 002C55CC A8890B0C */  jal        func_002e26a0
    /* 1C55D0 002C55D0 00000000 */   nop
    /* 1C55D4 002C55D4 020022A6 */  sh         $2, 0x2($17)
    /* 1C55D8 002C55D8 3C2C0200 */  dsll32     $5, $2, 16
    /* 1C55DC 002C55DC 3F2C0500 */  dsra32     $5, $5, 16
    /* 1C55E0 002C55E0 2D200000 */  daddu      $4, $0, $0
    /* 1C55E4 002C55E4 04000624 */  addiu      $6, $0, 0x4
    /* 1C55E8 002C55E8 2D380000 */  daddu      $7, $0, $0
    /* 1C55EC 002C55EC 01000824 */  addiu      $8, $0, 0x1
    /* 1C55F0 002C55F0 2CCB0A0C */  jal        func_002b2cb0
    /* 1C55F4 002C55F4 00000000 */   nop
    /* 1C55F8 002C55F8 040022A6 */  sh         $2, 0x4($17)
    /* 1C55FC 002C55FC 16000010 */  b          .L002C5658
    /* 1C5600 002C5600 00000000 */   nop
  .L002C5604:
    /* 1C5604 002C5604 9C890B0C */  jal        func_002e2670
    /* 1C5608 002C5608 00000000 */   nop
    /* 1C560C 002C560C 02002486 */  lh         $4, 0x2($17)
    /* 1C5610 002C5610 01000524 */  addiu      $5, $0, 0x1
    /* 1C5614 002C5614 2D300000 */  daddu      $6, $0, $0
    /* 1C5618 002C5618 2D384000 */  daddu      $7, $2, $0
    /* 1C561C 002C561C 02000824 */  addiu      $8, $0, 0x2
    /* 1C5620 002C5620 40CB0A0C */  jal        func_002b2d00
    /* 1C5624 002C5624 00000000 */   nop
    /* 1C5628 002C5628 020022A6 */  sh         $2, 0x2($17)
    /* 1C562C 002C562C 9C890B0C */  jal        func_002e2670
    /* 1C5630 002C5630 00000000 */   nop
    /* 1C5634 002C5634 3C340200 */  dsll32     $6, $2, 16
    /* 1C5638 002C5638 3F340600 */  dsra32     $6, $6, 16
    /* 1C563C 002C563C 02002486 */  lh         $4, 0x2($17)
    /* 1C5640 002C5640 04002586 */  lh         $5, 0x4($17)
    /* 1C5644 002C5644 05000724 */  addiu      $7, $0, 0x5
    /* 1C5648 002C5648 FFFF0824 */  addiu      $8, $0, -0x1
    /* 1C564C 002C564C 54CB0A0C */  jal        func_002b2d50
    /* 1C5650 002C5650 00000000 */   nop
    /* 1C5654 002C5654 040022A6 */  sh         $2, 0x4($17)
  .L002C5658:
    /* 1C5658 002C5658 01000224 */  addiu      $2, $0, 0x1
    /* 1C565C 002C565C 140022A2 */  sb         $2, 0x14($17)
    /* 1C5660 002C5660 2D100000 */  daddu      $2, $0, $0
    /* 1C5664 002C5664 31140010 */  b          .L002CA72C
    /* 1C5668 002C5668 00000000 */   nop
  .L002C566C:
    /* 1C566C 002C566C 8C00023C */  lui        $2, %hi(D_008C027A)
    /* 1C5670 002C5670 7A024394 */  lhu        $3, %lo(D_008C027A)($2)
    /* 1C5674 002C5674 00106230 */  andi       $2, $3, 0x1000
    /* 1C5678 002C5678 26004010 */  beqz       $2, .L002C5714
    /* 1C567C 002C567C 00000000 */   nop
    /* 1C5680 002C5680 9C890B0C */  jal        func_002e2670
    /* 1C5684 002C5684 00000000 */   nop
    /* 1C5688 002C5688 08024018 */  blez       $2, .L002C5EAC
    /* 1C568C 002C568C 00000000 */   nop
    /* 1C5690 002C5690 02002286 */  lh         $2, 0x2($17)
    /* 1C5694 002C5694 07004010 */  beqz       $2, .L002C56B4
    /* 1C5698 002C5698 00000000 */   nop
    /* 1C569C 002C569C 2D200000 */  daddu      $4, $0, $0
    /* 1C56A0 002C56A0 2D280000 */  daddu      $5, $0, $0
    /* 1C56A4 002C56A4 2D300000 */  daddu      $6, $0, $0
    /* 1C56A8 002C56A8 2D380000 */  daddu      $7, $0, $0
    /* 1C56AC 002C56AC D86B110C */  jal        func_0045af60
    /* 1C56B0 002C56B0 00000000 */   nop
  .L002C56B4:
    /* 1C56B4 002C56B4 02002486 */  lh         $4, 0x2($17)
    /* 1C56B8 002C56B8 01000524 */  addiu      $5, $0, 0x1
    /* 1C56BC 002C56BC 2D300000 */  daddu      $6, $0, $0
    /* 1C56C0 002C56C0 2D380000 */  daddu      $7, $0, $0
    /* 1C56C4 002C56C4 2D40A000 */  daddu      $8, $5, $0
    /* 1C56C8 002C56C8 40CB0A0C */  jal        func_002b2d00
    /* 1C56CC 002C56CC 00000000 */   nop
    /* 1C56D0 002C56D0 020022A6 */  sh         $2, 0x2($17)
    /* 1C56D4 002C56D4 9C890B0C */  jal        func_002e2670
    /* 1C56D8 002C56D8 00000000 */   nop
    /* 1C56DC 002C56DC 3C340200 */  dsll32     $6, $2, 16
    /* 1C56E0 002C56E0 3F340600 */  dsra32     $6, $6, 16
    /* 1C56E4 002C56E4 02002486 */  lh         $4, 0x2($17)
    /* 1C56E8 002C56E8 04002586 */  lh         $5, 0x4($17)
    /* 1C56EC 002C56EC 05000724 */  addiu      $7, $0, 0x5
    /* 1C56F0 002C56F0 FFFF0824 */  addiu      $8, $0, -0x1
    /* 1C56F4 002C56F4 54CB0A0C */  jal        func_002b2d50
    /* 1C56F8 002C56F8 00000000 */   nop
    /* 1C56FC 002C56FC 040022A6 */  sh         $2, 0x4($17)
    /* 1C5700 002C5700 01000224 */  addiu      $2, $0, 0x1
    /* 1C5704 002C5704 140022A2 */  sb         $2, 0x14($17)
    /* 1C5708 002C5708 2D100000 */  daddu      $2, $0, $0
    /* 1C570C 002C570C 07140010 */  b          .L002CA72C
    /* 1C5710 002C5710 00000000 */   nop
  .L002C5714:
    /* 1C5714 002C5714 00408230 */  andi       $2, $4, 0x4000
    /* 1C5718 002C5718 41004010 */  beqz       $2, .L002C5820
    /* 1C571C 002C571C 00000000 */   nop
    /* 1C5720 002C5720 14002282 */  lb         $2, 0x14($17)
    /* 1C5724 002C5724 3E004014 */  bnez       $2, .L002C5820
    /* 1C5728 002C5728 00000000 */   nop
    /* 1C572C 002C572C 2D200000 */  daddu      $4, $0, $0
    /* 1C5730 002C5730 2D280000 */  daddu      $5, $0, $0
    /* 1C5734 002C5734 2D300000 */  daddu      $6, $0, $0
    /* 1C5738 002C5738 2D380000 */  daddu      $7, $0, $0
    /* 1C573C 002C573C D86B110C */  jal        func_0045af60
    /* 1C5740 002C5740 00000000 */   nop
    /* 1C5744 002C5744 A8890B0C */  jal        func_002e26a0
    /* 1C5748 002C5748 00000000 */   nop
    /* 1C574C 002C574C 02002486 */  lh         $4, 0x2($17)
    /* 1C5750 002C5750 01000524 */  addiu      $5, $0, 0x1
    /* 1C5754 002C5754 2D304000 */  daddu      $6, $2, $0
    /* 1C5758 002C5758 2D380000 */  daddu      $7, $0, $0
    /* 1C575C 002C575C 02000824 */  addiu      $8, $0, 0x2
    /* 1C5760 002C5760 2CCB0A0C */  jal        func_002b2cb0
    /* 1C5764 002C5764 00000000 */   nop
    /* 1C5768 002C5768 020022A6 */  sh         $2, 0x2($17)
    /* 1C576C 002C576C 3C140200 */  dsll32     $2, $2, 16
    /* 1C5770 002C5770 3F140200 */  dsra32     $2, $2, 16
    /* 1C5774 002C5774 04004014 */  bnez       $2, .L002C5788
    /* 1C5778 002C5778 00000000 */   nop
    /* 1C577C 002C577C 040020A6 */  sh         $0, 0x4($17)
    /* 1C5780 002C5780 22000010 */  b          .L002C580C
    /* 1C5784 002C5784 00000000 */   nop
  .L002C5788:
    /* 1C5788 002C5788 A8890B0C */  jal        func_002e26a0
    /* 1C578C 002C578C 00000000 */   nop
    /* 1C5790 002C5790 05004228 */  slti       $2, $2, 0x5
    /* 1C5794 002C5794 0E004014 */  bnez       $2, .L002C57D0
    /* 1C5798 002C5798 00000000 */   nop
    /* 1C579C 002C579C A8890B0C */  jal        func_002e26a0
    /* 1C57A0 002C57A0 00000000 */   nop
    /* 1C57A4 002C57A4 3C340200 */  dsll32     $6, $2, 16
    /* 1C57A8 002C57A8 3F340600 */  dsra32     $6, $6, 16
    /* 1C57AC 002C57AC 02002486 */  lh         $4, 0x2($17)
    /* 1C57B0 002C57B0 04002586 */  lh         $5, 0x4($17)
    /* 1C57B4 002C57B4 05000724 */  addiu      $7, $0, 0x5
    /* 1C57B8 002C57B8 01000824 */  addiu      $8, $0, 0x1
    /* 1C57BC 002C57BC 54CB0A0C */  jal        func_002b2d50
    /* 1C57C0 002C57C0 00000000 */   nop
    /* 1C57C4 002C57C4 040022A6 */  sh         $2, 0x4($17)
    /* 1C57C8 002C57C8 10000010 */  b          .L002C580C
    /* 1C57CC 002C57CC 00000000 */   nop
  .L002C57D0:
    /* 1C57D0 002C57D0 A8890B0C */  jal        func_002e26a0
    /* 1C57D4 002C57D4 00000000 */   nop
    /* 1C57D8 002C57D8 3C840200 */  dsll32     $16, $2, 16
    /* 1C57DC 002C57DC 3F841000 */  dsra32     $16, $16, 16
    /* 1C57E0 002C57E0 9C890B0C */  jal        func_002e2670
    /* 1C57E4 002C57E4 00000000 */   nop
    /* 1C57E8 002C57E8 3C3C0200 */  dsll32     $7, $2, 16
    /* 1C57EC 002C57EC 3F3C0700 */  dsra32     $7, $7, 16
    /* 1C57F0 002C57F0 02002486 */  lh         $4, 0x2($17)
    /* 1C57F4 002C57F4 04002586 */  lh         $5, 0x4($17)
    /* 1C57F8 002C57F8 2D300002 */  daddu      $6, $16, $0
    /* 1C57FC 002C57FC 01000824 */  addiu      $8, $0, 0x1
    /* 1C5800 002C5800 54CB0A0C */  jal        func_002b2d50
    /* 1C5804 002C5804 00000000 */   nop
    /* 1C5808 002C5808 040022A6 */  sh         $2, 0x4($17)
  .L002C580C:
    /* 1C580C 002C580C 01000224 */  addiu      $2, $0, 0x1
    /* 1C5810 002C5810 140022A2 */  sb         $2, 0x14($17)
    /* 1C5814 002C5814 2D100000 */  daddu      $2, $0, $0
    /* 1C5818 002C5818 C4130010 */  b          .L002CA72C
    /* 1C581C 002C581C 00000000 */   nop
  .L002C5820:
    /* 1C5820 002C5820 00406230 */  andi       $2, $3, 0x4000
    /* 1C5824 002C5824 40004010 */  beqz       $2, .L002C5928
    /* 1C5828 002C5828 00000000 */   nop
    /* 1C582C 002C582C 9C890B0C */  jal        func_002e2670
    /* 1C5830 002C5830 00000000 */   nop
    /* 1C5834 002C5834 9D014018 */  blez       $2, .L002C5EAC
    /* 1C5838 002C5838 00000000 */   nop
    /* 1C583C 002C583C 02003086 */  lh         $16, 0x2($17)
    /* 1C5840 002C5840 A8890B0C */  jal        func_002e26a0
    /* 1C5844 002C5844 00000000 */   nop
    /* 1C5848 002C5848 07000212 */  beq        $16, $2, .L002C5868
    /* 1C584C 002C584C 00000000 */   nop
    /* 1C5850 002C5850 2D200000 */  daddu      $4, $0, $0
    /* 1C5854 002C5854 2D280000 */  daddu      $5, $0, $0
    /* 1C5858 002C5858 2D300000 */  daddu      $6, $0, $0
    /* 1C585C 002C585C 2D380000 */  daddu      $7, $0, $0
    /* 1C5860 002C5860 D86B110C */  jal        func_0045af60
    /* 1C5864 002C5864 00000000 */   nop
  .L002C5868:
    /* 1C5868 002C5868 A8890B0C */  jal        func_002e26a0
    /* 1C586C 002C586C 00000000 */   nop
    /* 1C5870 002C5870 02002486 */  lh         $4, 0x2($17)
    /* 1C5874 002C5874 01000524 */  addiu      $5, $0, 0x1
    /* 1C5878 002C5878 2D304000 */  daddu      $6, $2, $0
    /* 1C587C 002C587C 2D380000 */  daddu      $7, $0, $0
    /* 1C5880 002C5880 2D40A000 */  daddu      $8, $5, $0
    /* 1C5884 002C5884 2CCB0A0C */  jal        func_002b2cb0
    /* 1C5888 002C5888 00000000 */   nop
    /* 1C588C 002C588C 020022A6 */  sh         $2, 0x2($17)
    /* 1C5890 002C5890 A8890B0C */  jal        func_002e26a0
    /* 1C5894 002C5894 00000000 */   nop
    /* 1C5898 002C5898 05004228 */  slti       $2, $2, 0x5
    /* 1C589C 002C589C 0E004014 */  bnez       $2, .L002C58D8
    /* 1C58A0 002C58A0 00000000 */   nop
    /* 1C58A4 002C58A4 A8890B0C */  jal        func_002e26a0
    /* 1C58A8 002C58A8 00000000 */   nop
    /* 1C58AC 002C58AC 3C340200 */  dsll32     $6, $2, 16
    /* 1C58B0 002C58B0 3F340600 */  dsra32     $6, $6, 16
    /* 1C58B4 002C58B4 02002486 */  lh         $4, 0x2($17)
    /* 1C58B8 002C58B8 04002586 */  lh         $5, 0x4($17)
    /* 1C58BC 002C58BC 05000724 */  addiu      $7, $0, 0x5
    /* 1C58C0 002C58C0 01000824 */  addiu      $8, $0, 0x1
    /* 1C58C4 002C58C4 54CB0A0C */  jal        func_002b2d50
    /* 1C58C8 002C58C8 00000000 */   nop
    /* 1C58CC 002C58CC 040022A6 */  sh         $2, 0x4($17)
    /* 1C58D0 002C58D0 10000010 */  b          .L002C5914
    /* 1C58D4 002C58D4 00000000 */   nop
  .L002C58D8:
    /* 1C58D8 002C58D8 A8890B0C */  jal        func_002e26a0
    /* 1C58DC 002C58DC 00000000 */   nop
    /* 1C58E0 002C58E0 3C840200 */  dsll32     $16, $2, 16
    /* 1C58E4 002C58E4 3F841000 */  dsra32     $16, $16, 16
    /* 1C58E8 002C58E8 9C890B0C */  jal        func_002e2670
    /* 1C58EC 002C58EC 00000000 */   nop
    /* 1C58F0 002C58F0 3C3C0200 */  dsll32     $7, $2, 16
    /* 1C58F4 002C58F4 3F3C0700 */  dsra32     $7, $7, 16
    /* 1C58F8 002C58F8 02002486 */  lh         $4, 0x2($17)
    /* 1C58FC 002C58FC 04002586 */  lh         $5, 0x4($17)
    /* 1C5900 002C5900 2D300002 */  daddu      $6, $16, $0
    /* 1C5904 002C5904 01000824 */  addiu      $8, $0, 0x1
    /* 1C5908 002C5908 54CB0A0C */  jal        func_002b2d50
    /* 1C590C 002C590C 00000000 */   nop
    /* 1C5910 002C5910 040022A6 */  sh         $2, 0x4($17)
  .L002C5914:
    /* 1C5914 002C5914 01000224 */  addiu      $2, $0, 0x1
    /* 1C5918 002C5918 140022A2 */  sb         $2, 0x14($17)
    /* 1C591C 002C591C 2D100000 */  daddu      $2, $0, $0
    /* 1C5920 002C5920 82130010 */  b          .L002CA72C
    /* 1C5924 002C5924 00000000 */   nop
  .L002C5928:
    /* 1C5928 002C5928 02006230 */  andi       $2, $3, 0x2
    /* 1C592C 002C592C 04004014 */  bnez       $2, .L002C5940
    /* 1C5930 002C5930 00000000 */   nop
    /* 1C5934 002C5934 00206230 */  andi       $2, $3, 0x2000
    /* 1C5938 002C5938 18004010 */  beqz       $2, .L002C599C
    /* 1C593C 002C593C 00000000 */   nop
  .L002C5940:
    /* 1C5940 002C5940 02003086 */  lh         $16, 0x2($17)
    /* 1C5944 002C5944 A8890B0C */  jal        func_002e26a0
    /* 1C5948 002C5948 00000000 */   nop
    /* 1C594C 002C594C 07000212 */  beq        $16, $2, .L002C596C
    /* 1C5950 002C5950 00000000 */   nop
    /* 1C5954 002C5954 2D200000 */  daddu      $4, $0, $0
    /* 1C5958 002C5958 2D280000 */  daddu      $5, $0, $0
    /* 1C595C 002C595C 2D300000 */  daddu      $6, $0, $0
    /* 1C5960 002C5960 2D380000 */  daddu      $7, $0, $0
    /* 1C5964 002C5964 D86B110C */  jal        func_0045af60
    /* 1C5968 002C5968 00000000 */   nop
  .L002C596C:
    /* 1C596C 002C596C 9C890B0C */  jal        func_002e2670
    /* 1C5970 002C5970 00000000 */   nop
    /* 1C5974 002C5974 02002486 */  lh         $4, 0x2($17)
    /* 1C5978 002C5978 04002586 */  lh         $5, 0x4($17)
    /* 1C597C 002C597C 2D304000 */  daddu      $6, $2, $0
    /* 1C5980 002C5980 05000724 */  addiu      $7, $0, 0x5
    /* 1C5984 002C5984 02002826 */  addiu      $8, $17, 0x2
    /* 1C5988 002C5988 04002926 */  addiu      $9, $17, 0x4
    /* 1C598C 002C598C 9CCB0A0C */  jal        func_002b2e70
    /* 1C5990 002C5990 00000000 */   nop
    /* 1C5994 002C5994 45010010 */  b          .L002C5EAC
    /* 1C5998 002C5998 00000000 */   nop
  .L002C599C:
    /* 1C599C 002C599C 01006230 */  andi       $2, $3, 0x1
    /* 1C59A0 002C59A0 04004014 */  bnez       $2, .L002C59B4
    /* 1C59A4 002C59A4 00000000 */   nop
    /* 1C59A8 002C59A8 00806230 */  andi       $2, $3, 0x8000
    /* 1C59AC 002C59AC 16004010 */  beqz       $2, .L002C5A08
    /* 1C59B0 002C59B0 00000000 */   nop
  .L002C59B4:
    /* 1C59B4 002C59B4 02002286 */  lh         $2, 0x2($17)
    /* 1C59B8 002C59B8 07004010 */  beqz       $2, .L002C59D8
    /* 1C59BC 002C59BC 00000000 */   nop
    /* 1C59C0 002C59C0 2D200000 */  daddu      $4, $0, $0
    /* 1C59C4 002C59C4 2D280000 */  daddu      $5, $0, $0
    /* 1C59C8 002C59C8 2D300000 */  daddu      $6, $0, $0
    /* 1C59CC 002C59CC 2D380000 */  daddu      $7, $0, $0
    /* 1C59D0 002C59D0 D86B110C */  jal        func_0045af60
    /* 1C59D4 002C59D4 00000000 */   nop
  .L002C59D8:
    /* 1C59D8 002C59D8 9C890B0C */  jal        func_002e2670
    /* 1C59DC 002C59DC 00000000 */   nop
    /* 1C59E0 002C59E0 02002486 */  lh         $4, 0x2($17)
    /* 1C59E4 002C59E4 04002586 */  lh         $5, 0x4($17)
    /* 1C59E8 002C59E8 2D304000 */  daddu      $6, $2, $0
    /* 1C59EC 002C59EC 05000724 */  addiu      $7, $0, 0x5
    /* 1C59F0 002C59F0 02002826 */  addiu      $8, $17, 0x2
    /* 1C59F4 002C59F4 04002926 */  addiu      $9, $17, 0x4
    /* 1C59F8 002C59F8 E4CB0A0C */  jal        func_002b2f90
    /* 1C59FC 002C59FC 00000000 */   nop
    /* 1C5A00 002C5A00 2A010010 */  b          .L002C5EAC
    /* 1C5A04 002C5A04 00000000 */   nop
  .L002C5A08:
    /* 1C5A08 002C5A08 08006230 */  andi       $2, $3, 0x8
    /* 1C5A0C 002C5A0C 4A004010 */  beqz       $2, .L002C5B38
    /* 1C5A10 002C5A10 00000000 */   nop
    /* 1C5A14 002C5A14 020020A6 */  sh         $0, 0x2($17)
    /* 1C5A18 002C5A18 040020A6 */  sh         $0, 0x4($17)
    /* 1C5A1C 002C5A1C 08002482 */  lb         $4, 0x8($17)
    /* 1C5A20 002C5A20 09002282 */  lb         $2, 0x9($17)
    /* 1C5A24 002C5A24 FFFF4624 */  addiu      $6, $2, -0x1
    /* 1C5A28 002C5A28 01000524 */  addiu      $5, $0, 0x1
    /* 1C5A2C 002C5A2C 2D380000 */  daddu      $7, $0, $0
    /* 1C5A30 002C5A30 02000824 */  addiu      $8, $0, 0x2
    /* 1C5A34 002C5A34 2CCB0A0C */  jal        func_002b2cb0
    /* 1C5A38 002C5A38 00000000 */   nop
    /* 1C5A3C 002C5A3C 080022A2 */  sb         $2, 0x8($17)
    /* 1C5A40 002C5A40 07002282 */  lb         $2, 0x7($17)
    /* 1C5A44 002C5A44 02000624 */  addiu      $6, $0, 0x2
    /* 1C5A48 002C5A48 22004610 */  beq        $2, $6, .L002C5AD4
    /* 1C5A4C 002C5A4C 00000000 */   nop
    /* 1C5A50 002C5A50 01000524 */  addiu      $5, $0, 0x1
    /* 1C5A54 002C5A54 14004510 */  beq        $2, $5, .L002C5AA8
    /* 1C5A58 002C5A58 00000000 */   nop
    /* 1C5A5C 002C5A5C 03004010 */  beqz       $2, .L002C5A6C
    /* 1C5A60 002C5A60 00000000 */   nop
    /* 1C5A64 002C5A64 25000010 */  b          .L002C5AFC
    /* 1C5A68 002C5A68 00000000 */   nop
  .L002C5A6C:
    /* 1C5A6C 002C5A6C 08002282 */  lb         $2, 0x8($17)
    /* 1C5A70 002C5A70 21185100 */  addu       $3, $2, $17
    /* 1C5A74 002C5A74 7C0F6280 */  lb         $2, 0xF7C($3)
    /* 1C5A78 002C5A78 ECFF4224 */  addiu      $2, $2, -0x14
    /* 1C5A7C 002C5A7C 3C140200 */  dsll32     $2, $2, 16
    /* 1C5A80 002C5A80 3F140200 */  dsra32     $2, $2, 16
    /* 1C5A84 002C5A84 04204500 */  sllv       $4, $5, $2
    /* 1C5A88 002C5A88 730F6280 */  lb         $2, 0xF73($3)
    /* 1C5A8C 002C5A8C 04004224 */  addiu      $2, $2, 0x4
    /* 1C5A90 002C5A90 04284500 */  sllv       $5, $5, $2
    /* 1C5A94 002C5A94 2D38C000 */  daddu      $7, $6, $0
    /* 1C5A98 002C5A98 848A0B0C */  jal        func_002e2a10
    /* 1C5A9C 002C5A9C 00000000 */   nop
    /* 1C5AA0 002C5AA0 16000010 */  b          .L002C5AFC
    /* 1C5AA4 002C5AA4 00000000 */   nop
  .L002C5AA8:
    /* 1C5AA8 002C5AA8 08002282 */  lb         $2, 0x8($17)
    /* 1C5AAC 002C5AAC 21105100 */  addu       $2, $2, $17
    /* 1C5AB0 002C5AB0 730F4280 */  lb         $2, 0xF73($2)
    /* 1C5AB4 002C5AB4 04004224 */  addiu      $2, $2, 0x4
    /* 1C5AB8 002C5AB8 04284500 */  sllv       $5, $5, $2
    /* 1C5ABC 002C5ABC 00400424 */  addiu      $4, $0, 0x4000
    /* 1C5AC0 002C5AC0 2D38C000 */  daddu      $7, $6, $0
    /* 1C5AC4 002C5AC4 848A0B0C */  jal        func_002e2a10
    /* 1C5AC8 002C5AC8 00000000 */   nop
    /* 1C5ACC 002C5ACC 0B000010 */  b          .L002C5AFC
    /* 1C5AD0 002C5AD0 00000000 */   nop
  .L002C5AD4:
    /* 1C5AD4 002C5AD4 08002282 */  lb         $2, 0x8($17)
    /* 1C5AD8 002C5AD8 21105100 */  addu       $2, $2, $17
    /* 1C5ADC 002C5ADC 730F4280 */  lb         $2, 0xF73($2)
    /* 1C5AE0 002C5AE0 04004324 */  addiu      $3, $2, 0x4
    /* 1C5AE4 002C5AE4 01000224 */  addiu      $2, $0, 0x1
    /* 1C5AE8 002C5AE8 04286200 */  sllv       $5, $2, $3
    /* 1C5AEC 002C5AEC 00800434 */  ori        $4, $0, 0x8000
    /* 1C5AF0 002C5AF0 2D38C000 */  daddu      $7, $6, $0
    /* 1C5AF4 002C5AF4 848A0B0C */  jal        func_002e2a10
    /* 1C5AF8 002C5AF8 00000000 */   nop
  .L002C5AFC:
    /* 1C5AFC 002C5AFC 2D208002 */  daddu      $4, $20, $0
    /* 1C5B00 002C5B00 BC2B0B0C */  jal        func_002caef0
    /* 1C5B04 002C5B04 00000000 */   nop
    /* 1C5B08 002C5B08 2D208002 */  daddu      $4, $20, $0
    /* 1C5B0C 002C5B0C 2D280000 */  daddu      $5, $0, $0
    /* 1C5B10 002C5B10 80600B0C */  jal        func_002d8200
    /* 1C5B14 002C5B14 00000000 */   nop
    /* 1C5B18 002C5B18 2D200000 */  daddu      $4, $0, $0
    /* 1C5B1C 002C5B1C 2D280000 */  daddu      $5, $0, $0
    /* 1C5B20 002C5B20 2D300000 */  daddu      $6, $0, $0
    /* 1C5B24 002C5B24 05000724 */  addiu      $7, $0, 0x5
    /* 1C5B28 002C5B28 D86B110C */  jal        func_0045af60
    /* 1C5B2C 002C5B2C 00000000 */   nop
    /* 1C5B30 002C5B30 DE000010 */  b          .L002C5EAC
    /* 1C5B34 002C5B34 00000000 */   nop
  .L002C5B38:
    /* 1C5B38 002C5B38 04006230 */  andi       $2, $3, 0x4
    /* 1C5B3C 002C5B3C 4A004010 */  beqz       $2, .L002C5C68
    /* 1C5B40 002C5B40 00000000 */   nop
    /* 1C5B44 002C5B44 020020A6 */  sh         $0, 0x2($17)
    /* 1C5B48 002C5B48 040020A6 */  sh         $0, 0x4($17)
    /* 1C5B4C 002C5B4C 08002482 */  lb         $4, 0x8($17)
    /* 1C5B50 002C5B50 09002282 */  lb         $2, 0x9($17)
    /* 1C5B54 002C5B54 FFFF4724 */  addiu      $7, $2, -0x1
    /* 1C5B58 002C5B58 01000524 */  addiu      $5, $0, 0x1
    /* 1C5B5C 002C5B5C 2D300000 */  daddu      $6, $0, $0
    /* 1C5B60 002C5B60 02000824 */  addiu      $8, $0, 0x2
    /* 1C5B64 002C5B64 40CB0A0C */  jal        func_002b2d00
    /* 1C5B68 002C5B68 00000000 */   nop
    /* 1C5B6C 002C5B6C 080022A2 */  sb         $2, 0x8($17)
    /* 1C5B70 002C5B70 07002282 */  lb         $2, 0x7($17)
    /* 1C5B74 002C5B74 02000624 */  addiu      $6, $0, 0x2
    /* 1C5B78 002C5B78 22004610 */  beq        $2, $6, .L002C5C04
    /* 1C5B7C 002C5B7C 00000000 */   nop
    /* 1C5B80 002C5B80 01000524 */  addiu      $5, $0, 0x1
    /* 1C5B84 002C5B84 14004510 */  beq        $2, $5, .L002C5BD8
    /* 1C5B88 002C5B88 00000000 */   nop
    /* 1C5B8C 002C5B8C 03004010 */  beqz       $2, .L002C5B9C
    /* 1C5B90 002C5B90 00000000 */   nop
    /* 1C5B94 002C5B94 25000010 */  b          .L002C5C2C
    /* 1C5B98 002C5B98 00000000 */   nop
  .L002C5B9C:
    /* 1C5B9C 002C5B9C 08002282 */  lb         $2, 0x8($17)
    /* 1C5BA0 002C5BA0 21185100 */  addu       $3, $2, $17
    /* 1C5BA4 002C5BA4 7C0F6280 */  lb         $2, 0xF7C($3)
    /* 1C5BA8 002C5BA8 ECFF4224 */  addiu      $2, $2, -0x14
    /* 1C5BAC 002C5BAC 3C140200 */  dsll32     $2, $2, 16
    /* 1C5BB0 002C5BB0 3F140200 */  dsra32     $2, $2, 16
    /* 1C5BB4 002C5BB4 04204500 */  sllv       $4, $5, $2
    /* 1C5BB8 002C5BB8 730F6280 */  lb         $2, 0xF73($3)
    /* 1C5BBC 002C5BBC 04004224 */  addiu      $2, $2, 0x4
    /* 1C5BC0 002C5BC0 04284500 */  sllv       $5, $5, $2
    /* 1C5BC4 002C5BC4 2D38C000 */  daddu      $7, $6, $0
    /* 1C5BC8 002C5BC8 848A0B0C */  jal        func_002e2a10
    /* 1C5BCC 002C5BCC 00000000 */   nop
    /* 1C5BD0 002C5BD0 16000010 */  b          .L002C5C2C
    /* 1C5BD4 002C5BD4 00000000 */   nop
  .L002C5BD8:
    /* 1C5BD8 002C5BD8 08002282 */  lb         $2, 0x8($17)
    /* 1C5BDC 002C5BDC 21105100 */  addu       $2, $2, $17
    /* 1C5BE0 002C5BE0 730F4280 */  lb         $2, 0xF73($2)
    /* 1C5BE4 002C5BE4 04004224 */  addiu      $2, $2, 0x4
    /* 1C5BE8 002C5BE8 04284500 */  sllv       $5, $5, $2
    /* 1C5BEC 002C5BEC 00400424 */  addiu      $4, $0, 0x4000
    /* 1C5BF0 002C5BF0 2D38C000 */  daddu      $7, $6, $0
    /* 1C5BF4 002C5BF4 848A0B0C */  jal        func_002e2a10
    /* 1C5BF8 002C5BF8 00000000 */   nop
    /* 1C5BFC 002C5BFC 0B000010 */  b          .L002C5C2C
    /* 1C5C00 002C5C00 00000000 */   nop
  .L002C5C04:
    /* 1C5C04 002C5C04 08002282 */  lb         $2, 0x8($17)
    /* 1C5C08 002C5C08 21105100 */  addu       $2, $2, $17
    /* 1C5C0C 002C5C0C 730F4280 */  lb         $2, 0xF73($2)
    /* 1C5C10 002C5C10 04004324 */  addiu      $3, $2, 0x4
    /* 1C5C14 002C5C14 01000224 */  addiu      $2, $0, 0x1
    /* 1C5C18 002C5C18 04286200 */  sllv       $5, $2, $3
    /* 1C5C1C 002C5C1C 00800434 */  ori        $4, $0, 0x8000
    /* 1C5C20 002C5C20 2D38C000 */  daddu      $7, $6, $0
    /* 1C5C24 002C5C24 848A0B0C */  jal        func_002e2a10
    /* 1C5C28 002C5C28 00000000 */   nop
  .L002C5C2C:
    /* 1C5C2C 002C5C2C 2D208002 */  daddu      $4, $20, $0
    /* 1C5C30 002C5C30 BC2B0B0C */  jal        func_002caef0
    /* 1C5C34 002C5C34 00000000 */   nop
    /* 1C5C38 002C5C38 2D208002 */  daddu      $4, $20, $0
    /* 1C5C3C 002C5C3C 2D280000 */  daddu      $5, $0, $0
    /* 1C5C40 002C5C40 80600B0C */  jal        func_002d8200
    /* 1C5C44 002C5C44 00000000 */   nop
    /* 1C5C48 002C5C48 2D200000 */  daddu      $4, $0, $0
    /* 1C5C4C 002C5C4C 2D280000 */  daddu      $5, $0, $0
    /* 1C5C50 002C5C50 2D300000 */  daddu      $6, $0, $0
    /* 1C5C54 002C5C54 05000724 */  addiu      $7, $0, 0x5
    /* 1C5C58 002C5C58 D86B110C */  jal        func_0045af60
    /* 1C5C5C 002C5C5C 00000000 */   nop
    /* 1C5C60 002C5C60 92000010 */  b          .L002C5EAC
    /* 1C5C64 002C5C64 00000000 */   nop
  .L002C5C68:
    /* 1C5C68 002C5C68 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 1C5C6C 002C5C6C 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 1C5C70 002C5C70 20006230 */  andi       $2, $3, 0x20
    /* 1C5C74 002C5C74 24004010 */  beqz       $2, .L002C5D08
    /* 1C5C78 002C5C78 00000000 */   nop
    /* 1C5C7C 002C5C7C 2D208002 */  daddu      $4, $20, $0
    /* 1C5C80 002C5C80 B84F0B0C */  jal        func_002d3ee0
    /* 1C5C84 002C5C84 00000000 */   nop
    /* 1C5C88 002C5C88 22000224 */  addiu      $2, $0, 0x22
    /* 1C5C8C 002C5C8C 000022A2 */  sb         $2, 0x0($17)
    /* 1C5C90 002C5C90 2C0E248E */  lw         $4, 0xE2C($17)
    /* 1C5C94 002C5C94 38810B0C */  jal        func_002e04e0
    /* 1C5C98 002C5C98 00000000 */   nop
    /* 1C5C9C 002C5C9C 00688044 */  mtc1       $0, $f13
    /* 1C5CA0 002C5CA0 2C0E248E */  lw         $4, 0xE2C($17)
    /* 1C5CA4 002C5CA4 C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C5CA8 002C5CA8 2D280000 */  daddu      $5, $0, $0
    /* 1C5CAC 002C5CAC 02000624 */  addiu      $6, $0, 0x2
    /* 1C5CB0 002C5CB0 2D380000 */  daddu      $7, $0, $0
    /* 1C5CB4 002C5CB4 50820B0C */  jal        func_002e0940
    /* 1C5CB8 002C5CB8 00000000 */   nop
    /* 1C5CBC 002C5CBC 300E248E */  lw         $4, 0xE30($17)
    /* 1C5CC0 002C5CC0 38810B0C */  jal        func_002e04e0
    /* 1C5CC4 002C5CC4 00000000 */   nop
    /* 1C5CC8 002C5CC8 00688044 */  mtc1       $0, $f13
    /* 1C5CCC 002C5CCC 300E248E */  lw         $4, 0xE30($17)
    /* 1C5CD0 002C5CD0 C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C5CD4 002C5CD4 2D280000 */  daddu      $5, $0, $0
    /* 1C5CD8 002C5CD8 02000624 */  addiu      $6, $0, 0x2
    /* 1C5CDC 002C5CDC 2D380000 */  daddu      $7, $0, $0
    /* 1C5CE0 002C5CE0 50820B0C */  jal        func_002e0940
    /* 1C5CE4 002C5CE4 00000000 */   nop
    /* 1C5CE8 002C5CE8 2D200000 */  daddu      $4, $0, $0
    /* 1C5CEC 002C5CEC 01000524 */  addiu      $5, $0, 0x1
    /* 1C5CF0 002C5CF0 2D300000 */  daddu      $6, $0, $0
    /* 1C5CF4 002C5CF4 04000724 */  addiu      $7, $0, 0x4
    /* 1C5CF8 002C5CF8 D86B110C */  jal        func_0045af60
    /* 1C5CFC 002C5CFC 00000000 */   nop
    /* 1C5D00 002C5D00 6A000010 */  b          .L002C5EAC
    /* 1C5D04 002C5D04 00000000 */   nop
  .L002C5D08:
    /* 1C5D08 002C5D08 80006230 */  andi       $2, $3, 0x80
    /* 1C5D0C 002C5D0C 24004010 */  beqz       $2, .L002C5DA0
    /* 1C5D10 002C5D10 00000000 */   nop
    /* 1C5D14 002C5D14 2D208002 */  daddu      $4, $20, $0
    /* 1C5D18 002C5D18 B84F0B0C */  jal        func_002d3ee0
    /* 1C5D1C 002C5D1C 00000000 */   nop
    /* 1C5D20 002C5D20 22000224 */  addiu      $2, $0, 0x22
    /* 1C5D24 002C5D24 000022A2 */  sb         $2, 0x0($17)
    /* 1C5D28 002C5D28 2C0E248E */  lw         $4, 0xE2C($17)
    /* 1C5D2C 002C5D2C 38810B0C */  jal        func_002e04e0
    /* 1C5D30 002C5D30 00000000 */   nop
    /* 1C5D34 002C5D34 00688044 */  mtc1       $0, $f13
    /* 1C5D38 002C5D38 2C0E248E */  lw         $4, 0xE2C($17)
    /* 1C5D3C 002C5D3C C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C5D40 002C5D40 2D280000 */  daddu      $5, $0, $0
    /* 1C5D44 002C5D44 02000624 */  addiu      $6, $0, 0x2
    /* 1C5D48 002C5D48 2D380000 */  daddu      $7, $0, $0
    /* 1C5D4C 002C5D4C 50820B0C */  jal        func_002e0940
    /* 1C5D50 002C5D50 00000000 */   nop
    /* 1C5D54 002C5D54 300E248E */  lw         $4, 0xE30($17)
    /* 1C5D58 002C5D58 38810B0C */  jal        func_002e04e0
    /* 1C5D5C 002C5D5C 00000000 */   nop
    /* 1C5D60 002C5D60 00688044 */  mtc1       $0, $f13
    /* 1C5D64 002C5D64 300E248E */  lw         $4, 0xE30($17)
    /* 1C5D68 002C5D68 C4004CC4 */  lwc1       $f12, 0xC4($2)
    /* 1C5D6C 002C5D6C 2D280000 */  daddu      $5, $0, $0
    /* 1C5D70 002C5D70 02000624 */  addiu      $6, $0, 0x2
    /* 1C5D74 002C5D74 2D380000 */  daddu      $7, $0, $0
    /* 1C5D78 002C5D78 50820B0C */  jal        func_002e0940
    /* 1C5D7C 002C5D7C 00000000 */   nop
    /* 1C5D80 002C5D80 2D200000 */  daddu      $4, $0, $0
    /* 1C5D84 002C5D84 01000524 */  addiu      $5, $0, 0x1
    /* 1C5D88 002C5D88 2D300000 */  daddu      $6, $0, $0
    /* 1C5D8C 002C5D8C 04000724 */  addiu      $7, $0, 0x4
    /* 1C5D90 002C5D90 D86B110C */  jal        func_0045af60
    /* 1C5D94 002C5D94 00000000 */   nop
    /* 1C5D98 002C5D98 44000010 */  b          .L002C5EAC
    /* 1C5D9C 002C5D9C 00000000 */   nop
  .L002C5DA0:
    /* 1C5DA0 002C5DA0 40006230 */  andi       $2, $3, 0x40
    /* 1C5DA4 002C5DA4 41004010 */  beqz       $2, .L002C5EAC
    /* 1C5DA8 002C5DA8 00000000 */   nop
    /* 1C5DAC 002C5DAC 9C890B0C */  jal        func_002e2670
    /* 1C5DB0 002C5DB0 00000000 */   nop
    /* 1C5DB4 002C5DB4 37004018 */  blez       $2, .L002C5E94
    /* 1C5DB8 002C5DB8 00000000 */   nop
    /* 1C5DBC 002C5DBC 02002486 */  lh         $4, 0x2($17)
    /* 1C5DC0 002C5DC0 D0890B0C */  jal        func_002e2740
    /* 1C5DC4 002C5DC4 00000000 */   nop
    /* 1C5DC8 002C5DC8 3C240200 */  dsll32     $4, $2, 16
    /* 1C5DCC 002C5DCC 3F240400 */  dsra32     $4, $4, 16
    /* 1C5DD0 002C5DD0 A41A040C */  jal        func_00106a90
    /* 1C5DD4 002C5DD4 00000000 */   nop
    /* 1C5DD8 002C5DD8 2D804000 */  daddu      $16, $2, $0
    /* 1C5DDC 002C5DDC 989E0B0C */  jal        func_002e7a60
    /* 1C5DE0 002C5DE0 00000000 */   nop
    /* 1C5DE4 002C5DE4 2B085000 */  sltu       $1, $2, $16
    /* 1C5DE8 002C5DE8 22002014 */  bnez       $1, .L002C5E74
    /* 1C5DEC 002C5DEC 00000000 */   nop
    /* 1C5DF0 002C5DF0 02002486 */  lh         $4, 0x2($17)
    /* 1C5DF4 002C5DF4 D0890B0C */  jal        func_002e2740
    /* 1C5DF8 002C5DF8 00000000 */   nop
    /* 1C5DFC 002C5DFC 3C240200 */  dsll32     $4, $2, 16
    /* 1C5E00 002C5E00 3F240400 */  dsra32     $4, $4, 16
    /* 1C5E04 002C5E04 8019040C */  jal        func_00106600
    /* 1C5E08 002C5E08 00000000 */   nop
    /* 1C5E0C 002C5E0C FF004230 */  andi       $2, $2, 0xFF
    /* 1C5E10 002C5E10 63004128 */  slti       $1, $2, 0x63
    /* 1C5E14 002C5E14 17002010 */  beqz       $1, .L002C5E74
    /* 1C5E18 002C5E18 00000000 */   nop
    /* 1C5E1C 002C5E1C 02002486 */  lh         $4, 0x2($17)
    /* 1C5E20 002C5E20 D0890B0C */  jal        func_002e2740
    /* 1C5E24 002C5E24 00000000 */   nop
    /* 1C5E28 002C5E28 8806A2AF */  sw         $2, 0x688($29)
    /* 1C5E2C 002C5E2C 8C06A0AF */  sw         $0, 0x68C($29)
    /* 1C5E30 002C5E30 2D208002 */  daddu      $4, $20, $0
    /* 1C5E34 002C5E34 01000524 */  addiu      $5, $0, 0x1
    /* 1C5E38 002C5E38 8806A627 */  addiu      $6, $29, 0x688
    /* 1C5E3C 002C5E3C 2D38A000 */  daddu      $7, $5, $0
    /* 1C5E40 002C5E40 B07F0B0C */  jal        func_002dfec0
    /* 1C5E44 002C5E44 00000000 */   nop
    /* 1C5E48 002C5E48 100022A2 */  sb         $2, 0x10($17)
    /* 1C5E4C 002C5E4C 23000224 */  addiu      $2, $0, 0x23
    /* 1C5E50 002C5E50 000022A2 */  sb         $2, 0x0($17)
    /* 1C5E54 002C5E54 2D200000 */  daddu      $4, $0, $0
    /* 1C5E58 002C5E58 2D280000 */  daddu      $5, $0, $0
    /* 1C5E5C 002C5E5C 2D300000 */  daddu      $6, $0, $0
    /* 1C5E60 002C5E60 01000724 */  addiu      $7, $0, 0x1
    /* 1C5E64 002C5E64 D86B110C */  jal        func_0045af60
    /* 1C5E68 002C5E68 00000000 */   nop
    /* 1C5E6C 002C5E6C 0F000010 */  b          .L002C5EAC
    /* 1C5E70 002C5E70 00000000 */   nop
  .L002C5E74:
    /* 1C5E74 002C5E74 2D200000 */  daddu      $4, $0, $0
    /* 1C5E78 002C5E78 2D280000 */  daddu      $5, $0, $0
    /* 1C5E7C 002C5E7C 2D300000 */  daddu      $6, $0, $0
    /* 1C5E80 002C5E80 08000724 */  addiu      $7, $0, 0x8
    /* 1C5E84 002C5E84 D86B110C */  jal        func_0045af60
    /* 1C5E88 002C5E88 00000000 */   nop
    /* 1C5E8C 002C5E8C 07000010 */  b          .L002C5EAC
    /* 1C5E90 002C5E90 00000000 */   nop
  .L002C5E94:
    /* 1C5E94 002C5E94 2D200000 */  daddu      $4, $0, $0
    /* 1C5E98 002C5E98 2D280000 */  daddu      $5, $0, $0
    /* 1C5E9C 002C5E9C 2D300000 */  daddu      $6, $0, $0
    /* 1C5EA0 002C5EA0 08000724 */  addiu      $7, $0, 0x8
    /* 1C5EA4 002C5EA4 D86B110C */  jal        func_0045af60
    /* 1C5EA8 002C5EA8 00000000 */   nop
  .L002C5EAC:
    /* 1C5EAC 002C5EAC 140020A2 */  sb         $0, 0x14($17)
    /* 1C5EB0 002C5EB0 1D120010 */  b          .L002CA728
    /* 1C5EB4 002C5EB4 00000000 */   nop
    /* 1C5EB8 002C5EB8 4E020224 */  addiu      $2, $0, 0x24E
    /* 1C5EBC 002C5EBC 00008244 */  mtc1       $2, $f0
    /* 1C5EC0 002C5EC0 00000000 */  nop
    /* 1C5EC4 002C5EC4 20038046 */  cvt.s.w    $f12, $f0
    /* 1C5EC8 002C5EC8 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1C5ECC 002C5ECC 00688244 */  mtc1       $2, $f13
    /* 1C5ED0 002C5ED0 3003A427 */  addiu      $4, $29, 0x330
    /* 1C5ED4 002C5ED4 5CCA0A0C */  jal        func_002b2970
    /* 1C5ED8 002C5ED8 00000000 */   nop
    /* 1C5EDC 002C5EDC F806A427 */  addiu      $4, $29, 0x6F8
    /* 1C5EE0 002C5EE0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C5EE4 002C5EE4 2D30A000 */  daddu      $6, $5, $0
    /* 1C5EE8 002C5EE8 2D38A000 */  daddu      $7, $5, $0
    /* 1C5EEC 002C5EEC 2D40A000 */  daddu      $8, $5, $0
    /* 1C5EF0 002C5EF0 98CA0A0C */  jal        func_002b2a60
    /* 1C5EF4 002C5EF4 00000000 */   nop
    /* 1C5EF8 002C5EF8 02002486 */  lh         $4, 0x2($17)
    /* 1C5EFC 002C5EFC D0890B0C */  jal        func_002e2740
    /* 1C5F00 002C5F00 00000000 */   nop
    /* 1C5F04 002C5F04 3C240200 */  dsll32     $4, $2, 16
    /* 1C5F08 002C5F08 3F240400 */  dsra32     $4, $4, 16
    /* 1C5F0C 002C5F0C A41A040C */  jal        func_00106a90
    /* 1C5F10 002C5F10 00000000 */   nop
    /* 1C5F14 002C5F14 2D904000 */  daddu      $18, $2, $0
    /* 1C5F18 002C5F18 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C5F1C 002C5F1C A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C5F20 002C5F20 DCA9110C */  jal        func_0046a770
    /* 1C5F24 002C5F24 00000000 */   nop
    /* 1C5F28 002C5F28 2D804000 */  daddu      $16, $2, $0
    /* 1C5F2C 002C5F2C 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1C5F30 002C5F30 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1C5F34 002C5F34 DCA9110C */  jal        func_0046a770
    /* 1C5F38 002C5F38 00000000 */   nop
    /* 1C5F3C 002C5F3C 0000A2FF */  sd         $2, 0x0($29)
    /* 1C5F40 002C5F40 AA000224 */  addiu      $2, $0, 0xAA
    /* 1C5F44 002C5F44 0800A2FF */  sd         $2, 0x8($29)
    /* 1C5F48 002C5F48 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C5F4C 002C5F4C 00608244 */  mtc1       $2, $f12
    /* 1C5F50 002C5F50 3003A4DF */  ld         $4, 0x330($29)
    /* 1C5F54 002C5F54 F806A58F */  lw         $5, 0x6F8($29)
    /* 1C5F58 002C5F58 11000624 */  addiu      $6, $0, 0x11
    /* 1C5F5C 002C5F5C 05000724 */  addiu      $7, $0, 0x5
    /* 1C5F60 002C5F60 2D404002 */  daddu      $8, $18, $0
    /* 1C5F64 002C5F64 70000924 */  addiu      $9, $0, 0x70
    /* 1C5F68 002C5F68 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1C5F6C 002C5F6C 2D580002 */  daddu      $11, $16, $0
    /* 1C5F70 002C5F70 342B0B0C */  jal        func_002cacd0
    /* 1C5F74 002C5F74 00000000 */   nop
    /* 1C5F78 002C5F78 2D208002 */  daddu      $4, $20, $0
    /* 1C5F7C 002C5F7C 2D280000 */  daddu      $5, $0, $0
    /* 1C5F80 002C5F80 B02D0B0C */  jal        func_002cb6c0
    /* 1C5F84 002C5F84 00000000 */   nop
    /* 1C5F88 002C5F88 700D248E */  lw         $4, 0xD70($17)
    /* 1C5F8C 002C5F8C 68810B0C */  jal        func_002e05a0
    /* 1C5F90 002C5F90 00000000 */   nop
    /* 1C5F94 002C5F94 3C160200 */  dsll32     $2, $2, 24
    /* 1C5F98 002C5F98 3F160200 */  dsra32     $2, $2, 24
    /* 1C5F9C 002C5F9C E2114014 */  bnez       $2, .L002CA728
    /* 1C5FA0 002C5FA0 00000000 */   nop
    /* 1C5FA4 002C5FA4 7C0D248E */  lw         $4, 0xD7C($17)
    /* 1C5FA8 002C5FA8 68810B0C */  jal        func_002e05a0
    /* 1C5FAC 002C5FAC 00000000 */   nop
    /* 1C5FB0 002C5FB0 3C160200 */  dsll32     $2, $2, 24
    /* 1C5FB4 002C5FB4 3F160200 */  dsra32     $2, $2, 24
    /* 1C5FB8 002C5FB8 DB114014 */  bnez       $2, .L002CA728
    /* 1C5FBC 002C5FBC 00000000 */   nop
    /* 1C5FC0 002C5FC0 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C5FC4 002C5FC4 68810B0C */  jal        func_002e05a0
    /* 1C5FC8 002C5FC8 00000000 */   nop
    /* 1C5FCC 002C5FCC 3C160200 */  dsll32     $2, $2, 24
    /* 1C5FD0 002C5FD0 3F160200 */  dsra32     $2, $2, 24
    /* 1C5FD4 002C5FD4 D4114014 */  bnez       $2, .L002CA728
    /* 1C5FD8 002C5FD8 00000000 */   nop
    /* 1C5FDC 002C5FDC 900C248E */  lw         $4, 0xC90($17)
    /* 1C5FE0 002C5FE0 68810B0C */  jal        func_002e05a0
    /* 1C5FE4 002C5FE4 00000000 */   nop
    /* 1C5FE8 002C5FE8 3C160200 */  dsll32     $2, $2, 24
    /* 1C5FEC 002C5FEC 3F160200 */  dsra32     $2, $2, 24
    /* 1C5FF0 002C5FF0 CD114014 */  bnez       $2, .L002CA728
    /* 1C5FF4 002C5FF4 00000000 */   nop
    /* 1C5FF8 002C5FF8 1B000224 */  addiu      $2, $0, 0x1B
    /* 1C5FFC 002C5FFC 000022A2 */  sb         $2, 0x0($17)
    /* 1C6000 002C6000 C9110010 */  b          .L002CA728
    /* 1C6004 002C6004 00000000 */   nop
    /* 1C6008 002C6008 2D208002 */  daddu      $4, $20, $0
    /* 1C600C 002C600C 64450B0C */  jal        func_002d1590
    /* 1C6010 002C6010 00000000 */   nop
    /* 1C6014 002C6014 10002482 */  lb         $4, 0x10($17)
    /* 1C6018 002C6018 A0ED0A0C */  jal        func_002bb680
    /* 1C601C 002C601C 00000000 */   nop
    /* 1C6020 002C6020 06004010 */  beqz       $2, .L002C603C
    /* 1C6024 002C6024 00000000 */   nop
    /* 1C6028 002C6028 10002482 */  lb         $4, 0x10($17)
    /* 1C602C 002C602C 3CEF0A0C */  jal        func_002bbcf0
    /* 1C6030 002C6030 00000000 */   nop
    /* 1C6034 002C6034 BC110010 */  b          .L002CA728
    /* 1C6038 002C6038 00000000 */   nop
  .L002C603C:
    /* 1C603C 002C603C 10002482 */  lb         $4, 0x10($17)
    /* 1C6040 002C6040 70EC0A0C */  jal        func_002bb1c0
    /* 1C6044 002C6044 00000000 */   nop
    /* 1C6048 002C6048 41004014 */  bnez       $2, .L002C6150
    /* 1C604C 002C604C 00000000 */   nop
    /* 1C6050 002C6050 2D200000 */  daddu      $4, $0, $0
    /* 1C6054 002C6054 2D280000 */  daddu      $5, $0, $0
    /* 1C6058 002C6058 2D300000 */  daddu      $6, $0, $0
    /* 1C605C 002C605C 06000724 */  addiu      $7, $0, 0x6
    /* 1C6060 002C6060 D86B110C */  jal        func_0045af60
    /* 1C6064 002C6064 00000000 */   nop
    /* 1C6068 002C6068 10002482 */  lb         $4, 0x10($17)
    /* 1C606C 002C606C 54ED0A0C */  jal        func_002bb550
    /* 1C6070 002C6070 00000000 */   nop
    /* 1C6074 002C6074 2D208002 */  daddu      $4, $20, $0
    /* 1C6078 002C6078 B84F0B0C */  jal        func_002d3ee0
    /* 1C607C 002C607C 00000000 */   nop
    /* 1C6080 002C6080 C80D248E */  lw         $4, 0xDC8($17)
    /* 1C6084 002C6084 2D280000 */  daddu      $5, $0, $0
    /* 1C6088 002C6088 01000624 */  addiu      $6, $0, 0x1
    /* 1C608C 002C608C 3C810B0C */  jal        func_002e04f0
    /* 1C6090 002C6090 00000000 */   nop
    /* 1C6094 002C6094 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C6098 002C6098 2D280000 */  daddu      $5, $0, $0
    /* 1C609C 002C609C 01000624 */  addiu      $6, $0, 0x1
    /* 1C60A0 002C60A0 3C810B0C */  jal        func_002e04f0
    /* 1C60A4 002C60A4 00000000 */   nop
    /* 1C60A8 002C60A8 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C60AC 002C60AC 2D280000 */  daddu      $5, $0, $0
    /* 1C60B0 002C60B0 01000624 */  addiu      $6, $0, 0x1
    /* 1C60B4 002C60B4 3C810B0C */  jal        func_002e04f0
    /* 1C60B8 002C60B8 00000000 */   nop
    /* 1C60BC 002C60BC 900C248E */  lw         $4, 0xC90($17)
    /* 1C60C0 002C60C0 2D280000 */  daddu      $5, $0, $0
    /* 1C60C4 002C60C4 01000624 */  addiu      $6, $0, 0x1
    /* 1C60C8 002C60C8 3C810B0C */  jal        func_002e04f0
    /* 1C60CC 002C60CC 00000000 */   nop
    /* 1C60D0 002C60D0 02002486 */  lh         $4, 0x2($17)
    /* 1C60D4 002C60D4 D0890B0C */  jal        func_002e2740
    /* 1C60D8 002C60D8 00000000 */   nop
    /* 1C60DC 002C60DC 8006A2AF */  sw         $2, 0x680($29)
    /* 1C60E0 002C60E0 8406A0AF */  sw         $0, 0x684($29)
    /* 1C60E4 002C60E4 2D208002 */  daddu      $4, $20, $0
    /* 1C60E8 002C60E8 04000524 */  addiu      $5, $0, 0x4
    /* 1C60EC 002C60EC 8006A627 */  addiu      $6, $29, 0x680
    /* 1C60F0 002C60F0 01000724 */  addiu      $7, $0, 0x1
    /* 1C60F4 002C60F4 B07F0B0C */  jal        func_002dfec0
    /* 1C60F8 002C60F8 00000000 */   nop
    /* 1C60FC 002C60FC 100022A2 */  sb         $2, 0x10($17)
    /* 1C6100 002C6100 2D208002 */  daddu      $4, $20, $0
    /* 1C6104 002C6104 64580B0C */  jal        func_002d6190
    /* 1C6108 002C6108 00000000 */   nop
    /* 1C610C 002C610C 02002486 */  lh         $4, 0x2($17)
    /* 1C6110 002C6110 D0890B0C */  jal        func_002e2740
    /* 1C6114 002C6114 00000000 */   nop
    /* 1C6118 002C6118 3C240200 */  dsll32     $4, $2, 16
    /* 1C611C 002C611C 3F240400 */  dsra32     $4, $4, 16
    /* 1C6120 002C6120 A41A040C */  jal        func_00106a90
    /* 1C6124 002C6124 00000000 */   nop
    /* 1C6128 002C6128 2D804000 */  daddu      $16, $2, $0
    /* 1C612C 002C612C 989E0B0C */  jal        func_002e7a60
    /* 1C6130 002C6130 00000000 */   nop
    /* 1C6134 002C6134 23205000 */  subu       $4, $2, $16
    /* 1C6138 002C6138 A09E0B0C */  jal        func_002e7a80
    /* 1C613C 002C613C 00000000 */   nop
    /* 1C6140 002C6140 1E000224 */  addiu      $2, $0, 0x1E
    /* 1C6144 002C6144 000022A2 */  sb         $2, 0x0($17)
    /* 1C6148 002C6148 77110010 */  b          .L002CA728
    /* 1C614C 002C614C 00000000 */   nop
  .L002C6150:
    /* 1C6150 002C6150 10002482 */  lb         $4, 0x10($17)
    /* 1C6154 002C6154 54ED0A0C */  jal        func_002bb550
    /* 1C6158 002C6158 00000000 */   nop
    /* 1C615C 002C615C 21000224 */  addiu      $2, $0, 0x21
    /* 1C6160 002C6160 000022A2 */  sb         $2, 0x0($17)
    /* 1C6164 002C6164 70110010 */  b          .L002CA728
    /* 1C6168 002C6168 00000000 */   nop
    /* 1C616C 002C616C 01000224 */  addiu      $2, $0, 0x1
    /* 1C6170 002C6170 120022A6 */  sh         $2, 0x12($17)
    /* 1C6174 002C6174 640C248E */  lw         $4, 0xC64($17)
    /* 1C6178 002C6178 68810B0C */  jal        func_002e05a0
    /* 1C617C 002C617C 00000000 */   nop
    /* 1C6180 002C6180 3C160200 */  dsll32     $2, $2, 24
    /* 1C6184 002C6184 3F160200 */  dsra32     $2, $2, 24
    /* 1C6188 002C6188 67114014 */  bnez       $2, .L002CA728
    /* 1C618C 002C618C 00000000 */   nop
    /* 1C6190 002C6190 2D208002 */  daddu      $4, $20, $0
    /* 1C6194 002C6194 2D280000 */  daddu      $5, $0, $0
    /* 1C6198 002C6198 E0370B0C */  jal        func_002cdf80
    /* 1C619C 002C619C 00000000 */   nop
    /* 1C61A0 002C61A0 61110010 */  b          .L002CA728
    /* 1C61A4 002C61A4 00000000 */   nop
    /* 1C61A8 002C61A8 2D208002 */  daddu      $4, $20, $0
    /* 1C61AC 002C61AC 02000524 */  addiu      $5, $0, 0x2
    /* 1C61B0 002C61B0 E0370B0C */  jal        func_002cdf80
    /* 1C61B4 002C61B4 00000000 */   nop
    /* 1C61B8 002C61B8 2D208002 */  daddu      $4, $20, $0
    /* 1C61BC 002C61BC EC740B0C */  jal        func_002dd3b0
    /* 1C61C0 002C61C0 00000000 */   nop
    /* 1C61C4 002C61C4 9A000010 */  b          .L002C6430
    /* 1C61C8 002C61C8 00000000 */   nop
  .L002C61CC:
    /* 1C61CC 002C61CC CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C61D0 002C61D0 38810B0C */  jal        func_002e04e0
    /* 1C61D4 002C61D4 00000000 */   nop
    /* 1C61D8 002C61D8 2D904000 */  daddu      $18, $2, $0
    /* 1C61DC 002C61DC D00D248E */  lw         $4, 0xDD0($17)
    /* 1C61E0 002C61E0 38810B0C */  jal        func_002e04e0
    /* 1C61E4 002C61E4 00000000 */   nop
    /* 1C61E8 002C61E8 2D804000 */  daddu      $16, $2, $0
    /* 1C61EC 002C61EC 3C141300 */  dsll32     $2, $19, 16
    /* 1C61F0 002C61F0 3F140200 */  dsra32     $2, $2, 16
    /* 1C61F4 002C61F4 80100200 */  sll        $2, $2, 2
    /* 1C61F8 002C61F8 21A82202 */  addu       $21, $17, $2
    /* 1C61FC 002C61FC 3E0FA292 */  lbu        $2, 0xF3E($21)
    /* 1C6200 002C6200 06004004 */  bltz       $2, .L002C621C
    /* 1C6204 002C6204 00000000 */   nop
    /* 1C6208 002C6208 00008244 */  mtc1       $2, $f0
    /* 1C620C 002C620C 00000000 */  nop
    /* 1C6210 002C6210 20038046 */  cvt.s.w    $f12, $f0
    /* 1C6214 002C6214 08000010 */  b          .L002C6238
    /* 1C6218 002C6218 00000000 */   nop
  .L002C621C:
    /* 1C621C 002C621C 42180200 */  srl        $3, $2, 1
    /* 1C6220 002C6220 01004230 */  andi       $2, $2, 0x1
    /* 1C6224 002C6224 25186200 */  or         $3, $3, $2
    /* 1C6228 002C6228 00008344 */  mtc1       $3, $f0
    /* 1C622C 002C622C 00000000 */  nop
    /* 1C6230 002C6230 20038046 */  cvt.s.w    $f12, $f0
    /* 1C6234 002C6234 00630C46 */  add.s      $f12, $f12, $f12
  .L002C6238:
    /* 1C6238 002C6238 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C623C 002C623C 00008244 */  mtc1       $2, $f0
    /* 1C6240 002C6240 00000000 */  nop
    /* 1C6244 002C6244 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C6248 002C6248 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C624C 002C624C 00688244 */  mtc1       $2, $f13
    /* 1C6250 002C6250 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C6254 002C6254 00788244 */  mtc1       $2, $f15
    /* 1C6258 002C6258 01000424 */  addiu      $4, $0, 0x1
    /* 1C625C 002C625C A8CA0A0C */  jal        func_002b2aa0
    /* 1C6260 002C6260 00000000 */   nop
    /* 1C6264 002C6264 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C6268 002C6268 00088244 */  mtc1       $2, $f1
    /* 1C626C 002C626C 00000000 */  nop
    /* 1C6270 002C6270 36080046 */  c.le.s     $f1, $f0
    /* 1C6274 002C6274 07000145 */  bc1t       .L002C6294
    /* 1C6278 002C6278 00000000 */   nop
    /* 1C627C 002C627C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C6280 002C6280 00000344 */  mfc1       $3, $f0
    /* 1C6284 002C6284 00000000 */  nop
    /* 1C6288 002C6288 FF006330 */  andi       $3, $3, 0xFF
    /* 1C628C 002C628C 07000010 */  b          .L002C62AC
    /* 1C6290 002C6290 00000000 */   nop
  .L002C6294:
    /* 1C6294 002C6294 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C6298 002C6298 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C629C 002C629C 00000344 */  mfc1       $3, $f0
    /* 1C62A0 002C62A0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C62A4 002C62A4 25186200 */  or         $3, $3, $2
    /* 1C62A8 002C62A8 FF006330 */  andi       $3, $3, 0xFF
  .L002C62AC:
    /* 1C62AC 002C62AC 790003A2 */  sb         $3, 0x79($16)
    /* 1C62B0 002C62B0 790043A2 */  sb         $3, 0x79($18)
    /* 1C62B4 002C62B4 3F0FA292 */  lbu        $2, 0xF3F($21)
    /* 1C62B8 002C62B8 06004004 */  bltz       $2, .L002C62D4
    /* 1C62BC 002C62BC 00000000 */   nop
    /* 1C62C0 002C62C0 00008244 */  mtc1       $2, $f0
    /* 1C62C4 002C62C4 00000000 */  nop
    /* 1C62C8 002C62C8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C62CC 002C62CC 08000010 */  b          .L002C62F0
    /* 1C62D0 002C62D0 00000000 */   nop
  .L002C62D4:
    /* 1C62D4 002C62D4 42180200 */  srl        $3, $2, 1
    /* 1C62D8 002C62D8 01004230 */  andi       $2, $2, 0x1
    /* 1C62DC 002C62DC 25186200 */  or         $3, $3, $2
    /* 1C62E0 002C62E0 00008344 */  mtc1       $3, $f0
    /* 1C62E4 002C62E4 00000000 */  nop
    /* 1C62E8 002C62E8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C62EC 002C62EC 00630C46 */  add.s      $f12, $f12, $f12
  .L002C62F0:
    /* 1C62F0 002C62F0 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C62F4 002C62F4 00008244 */  mtc1       $2, $f0
    /* 1C62F8 002C62F8 00000000 */  nop
    /* 1C62FC 002C62FC A0038046 */  cvt.s.w    $f14, $f0
    /* 1C6300 002C6300 6243023C */  lui        $2, (0x43620000 >> 16)
    /* 1C6304 002C6304 00688244 */  mtc1       $2, $f13
    /* 1C6308 002C6308 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C630C 002C630C 00788244 */  mtc1       $2, $f15
    /* 1C6310 002C6310 01000424 */  addiu      $4, $0, 0x1
    /* 1C6314 002C6314 A8CA0A0C */  jal        func_002b2aa0
    /* 1C6318 002C6318 00000000 */   nop
    /* 1C631C 002C631C 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C6320 002C6320 00088244 */  mtc1       $2, $f1
    /* 1C6324 002C6324 00000000 */  nop
    /* 1C6328 002C6328 36080046 */  c.le.s     $f1, $f0
    /* 1C632C 002C632C 07000145 */  bc1t       .L002C634C
    /* 1C6330 002C6330 00000000 */   nop
    /* 1C6334 002C6334 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C6338 002C6338 00000344 */  mfc1       $3, $f0
    /* 1C633C 002C633C 00000000 */  nop
    /* 1C6340 002C6340 FF006330 */  andi       $3, $3, 0xFF
    /* 1C6344 002C6344 07000010 */  b          .L002C6364
    /* 1C6348 002C6348 00000000 */   nop
  .L002C634C:
    /* 1C634C 002C634C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C6350 002C6350 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C6354 002C6354 00000344 */  mfc1       $3, $f0
    /* 1C6358 002C6358 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C635C 002C635C 25186200 */  or         $3, $3, $2
    /* 1C6360 002C6360 FF006330 */  andi       $3, $3, 0xFF
  .L002C6364:
    /* 1C6364 002C6364 7A0003A2 */  sb         $3, 0x7A($16)
    /* 1C6368 002C6368 7A0043A2 */  sb         $3, 0x7A($18)
    /* 1C636C 002C636C 400FA292 */  lbu        $2, 0xF40($21)
    /* 1C6370 002C6370 06004004 */  bltz       $2, .L002C638C
    /* 1C6374 002C6374 00000000 */   nop
    /* 1C6378 002C6378 00008244 */  mtc1       $2, $f0
    /* 1C637C 002C637C 00000000 */  nop
    /* 1C6380 002C6380 20038046 */  cvt.s.w    $f12, $f0
    /* 1C6384 002C6384 08000010 */  b          .L002C63A8
    /* 1C6388 002C6388 00000000 */   nop
  .L002C638C:
    /* 1C638C 002C638C 42180200 */  srl        $3, $2, 1
    /* 1C6390 002C6390 01004230 */  andi       $2, $2, 0x1
    /* 1C6394 002C6394 25186200 */  or         $3, $3, $2
    /* 1C6398 002C6398 00008344 */  mtc1       $3, $f0
    /* 1C639C 002C639C 00000000 */  nop
    /* 1C63A0 002C63A0 20038046 */  cvt.s.w    $f12, $f0
    /* 1C63A4 002C63A4 00630C46 */  add.s      $f12, $f12, $f12
  .L002C63A8:
    /* 1C63A8 002C63A8 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C63AC 002C63AC 00008244 */  mtc1       $2, $f0
    /* 1C63B0 002C63B0 00000000 */  nop
    /* 1C63B4 002C63B4 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C63B8 002C63B8 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1C63BC 002C63BC 00688244 */  mtc1       $2, $f13
    /* 1C63C0 002C63C0 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C63C4 002C63C4 00788244 */  mtc1       $2, $f15
    /* 1C63C8 002C63C8 01000424 */  addiu      $4, $0, 0x1
    /* 1C63CC 002C63CC A8CA0A0C */  jal        func_002b2aa0
    /* 1C63D0 002C63D0 00000000 */   nop
    /* 1C63D4 002C63D4 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C63D8 002C63D8 00088244 */  mtc1       $2, $f1
    /* 1C63DC 002C63DC 00000000 */  nop
    /* 1C63E0 002C63E0 36080046 */  c.le.s     $f1, $f0
    /* 1C63E4 002C63E4 07000145 */  bc1t       .L002C6404
    /* 1C63E8 002C63E8 00000000 */   nop
    /* 1C63EC 002C63EC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C63F0 002C63F0 00000344 */  mfc1       $3, $f0
    /* 1C63F4 002C63F4 00000000 */  nop
    /* 1C63F8 002C63F8 FF006330 */  andi       $3, $3, 0xFF
    /* 1C63FC 002C63FC 07000010 */  b          .L002C641C
    /* 1C6400 002C6400 00000000 */   nop
  .L002C6404:
    /* 1C6404 002C6404 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C6408 002C6408 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C640C 002C640C 00000344 */  mfc1       $3, $f0
    /* 1C6410 002C6410 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C6414 002C6414 25186200 */  or         $3, $3, $2
    /* 1C6418 002C6418 FF006330 */  andi       $3, $3, 0xFF
  .L002C641C:
    /* 1C641C 002C641C 7B0003A2 */  sb         $3, 0x7B($16)
    /* 1C6420 002C6420 7B0043A2 */  sb         $3, 0x7B($18)
    /* 1C6424 002C6424 01006226 */  addiu      $2, $19, 0x1
    /* 1C6428 002C6428 3C9C0200 */  dsll32     $19, $2, 16
    /* 1C642C 002C642C 3F9C1300 */  dsra32     $19, $19, 16
  .L002C6430:
    /* 1C6430 002C6430 3C141300 */  dsll32     $2, $19, 16
    /* 1C6434 002C6434 3F140200 */  dsra32     $2, $2, 16
    /* 1C6438 002C6438 02004228 */  slti       $2, $2, 0x2
    /* 1C643C 002C643C 63FF4014 */  bnez       $2, .L002C61CC
    /* 1C6440 002C6440 00000000 */   nop
    /* 1C6444 002C6444 3C0F2486 */  lh         $4, 0xF3C($17)
    /* 1C6448 002C6448 06008128 */  slti       $1, $4, 0x6
    /* 1C644C 002C644C 0A002010 */  beqz       $1, .L002C6478
    /* 1C6450 002C6450 00000000 */   nop
    /* 1C6454 002C6454 01000524 */  addiu      $5, $0, 0x1
    /* 1C6458 002C6458 06000624 */  addiu      $6, $0, 0x6
    /* 1C645C 002C645C 2D380000 */  daddu      $7, $0, $0
    /* 1C6460 002C6460 2D40A000 */  daddu      $8, $5, $0
    /* 1C6464 002C6464 2CCB0A0C */  jal        func_002b2cb0
    /* 1C6468 002C6468 00000000 */   nop
    /* 1C646C 002C646C 3C0F22A6 */  sh         $2, 0xF3C($17)
    /* 1C6470 002C6470 AD100010 */  b          .L002CA728
    /* 1C6474 002C6474 00000000 */   nop
  .L002C6478:
    /* 1C6478 002C6478 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C647C 002C647C 38810B0C */  jal        func_002e04e0
    /* 1C6480 002C6480 00000000 */   nop
    /* 1C6484 002C6484 3E0F2692 */  lbu        $6, 0xF3E($17)
    /* 1C6488 002C6488 3F0F2592 */  lbu        $5, 0xF3F($17)
    /* 1C648C 002C648C 400F2492 */  lbu        $4, 0xF40($17)
    /* 1C6490 002C6490 410F2392 */  lbu        $3, 0xF41($17)
    /* 1C6494 002C6494 790046A0 */  sb         $6, 0x79($2)
    /* 1C6498 002C6498 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C649C 002C649C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C64A0 002C64A0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C64A4 002C64A4 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C64A8 002C64A8 38810B0C */  jal        func_002e04e0
    /* 1C64AC 002C64AC 00000000 */   nop
    /* 1C64B0 002C64B0 420F2692 */  lbu        $6, 0xF42($17)
    /* 1C64B4 002C64B4 430F2592 */  lbu        $5, 0xF43($17)
    /* 1C64B8 002C64B8 440F2492 */  lbu        $4, 0xF44($17)
    /* 1C64BC 002C64BC 450F2392 */  lbu        $3, 0xF45($17)
    /* 1C64C0 002C64C0 790046A0 */  sb         $6, 0x79($2)
    /* 1C64C4 002C64C4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C64C8 002C64C8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C64CC 002C64CC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C64D0 002C64D0 11002382 */  lb         $3, 0x11($17)
    /* 1C64D4 002C64D4 44006014 */  bnez       $3, .L002C65E8
    /* 1C64D8 002C64D8 00000000 */   nop
    /* 1C64DC 002C64DC 02002286 */  lh         $2, 0x2($17)
    /* 1C64E0 002C64E0 41004014 */  bnez       $2, .L002C65E8
    /* 1C64E4 002C64E4 00000000 */   nop
    /* 1C64E8 002C64E8 2D980000 */  daddu      $19, $0, $0
    /* 1C64EC 002C64EC 01001224 */  addiu      $18, $0, 0x1
    /* 1C64F0 002C64F0 1A000010 */  b          .L002C655C
    /* 1C64F4 002C64F4 00000000 */   nop
  .L002C64F8:
    /* 1C64F8 002C64F8 11002282 */  lb         $2, 0x11($17)
    /* 1C64FC 002C64FC 80100200 */  sll        $2, $2, 2
    /* 1C6500 002C6500 21102202 */  addu       $2, $17, $2
    /* 1C6504 002C6504 180F448C */  lw         $4, 0xF18($2)
    /* 1C6508 002C6508 2D280002 */  daddu      $5, $16, $0
    /* 1C650C 002C650C 0C8A0B0C */  jal        func_002e2830
    /* 1C6510 002C6510 00000000 */   nop
    /* 1C6514 002C6514 2D804000 */  daddu      $16, $2, $0
    /* 1C6518 002C6518 3C241000 */  dsll32     $4, $16, 16
    /* 1C651C 002C651C 3F240400 */  dsra32     $4, $4, 16
    /* 1C6520 002C6520 A41A040C */  jal        func_00106a90
    /* 1C6524 002C6524 00000000 */   nop
    /* 1C6528 002C6528 05000324 */  addiu      $3, $0, 0x5
    /* 1C652C 002C652C 1B004300 */  divu       $0, $2, $3
    /* 1C6530 002C6530 12A80000 */  mflo       $21
    /* 1C6534 002C6534 3C241000 */  dsll32     $4, $16, 16
    /* 1C6538 002C6538 3F240400 */  dsra32     $4, $4, 16
    /* 1C653C 002C653C 8019040C */  jal        func_00106600
    /* 1C6540 002C6540 00000000 */   nop
    /* 1C6544 002C6544 FF004230 */  andi       $2, $2, 0xFF
    /* 1C6548 002C6548 1810A202 */  mult       $2, $21, $2
    /* 1C654C 002C654C 21986202 */  addu       $19, $19, $2
    /* 1C6550 002C6550 01004226 */  addiu      $2, $18, 0x1
    /* 1C6554 002C6554 3C940200 */  dsll32     $18, $2, 16
    /* 1C6558 002C6558 3F941200 */  dsra32     $18, $18, 16
  .L002C655C:
    /* 1C655C 002C655C 3C841200 */  dsll32     $16, $18, 16
    /* 1C6560 002C6560 3F841000 */  dsra32     $16, $16, 16
    /* 1C6564 002C6564 11002282 */  lb         $2, 0x11($17)
    /* 1C6568 002C6568 80100200 */  sll        $2, $2, 2
    /* 1C656C 002C656C 21102202 */  addu       $2, $17, $2
    /* 1C6570 002C6570 180F448C */  lw         $4, 0xF18($2)
    /* 1C6574 002C6574 BC890B0C */  jal        func_002e26f0
    /* 1C6578 002C6578 00000000 */   nop
    /* 1C657C 002C657C 2A100202 */  slt        $2, $16, $2
    /* 1C6580 002C6580 DDFF4014 */  bnez       $2, .L002C64F8
    /* 1C6584 002C6584 00000000 */   nop
    /* 1C6588 002C6588 2D206002 */  daddu      $4, $19, $0
    /* 1C658C 002C658C 2D280000 */  daddu      $5, $0, $0
    /* 1C6590 002C6590 9800023C */  lui        $2, (0x98967F >> 16)
    /* 1C6594 002C6594 7F964634 */  ori        $6, $2, (0x98967F & 0xFFFF)
    /* 1C6598 002C6598 2D380000 */  daddu      $7, $0, $0
    /* 1C659C 002C659C 01000824 */  addiu      $8, $0, 0x1
    /* 1C65A0 002C65A0 2CCB0A0C */  jal        func_002b2cb0
    /* 1C65A4 002C65A4 00000000 */   nop
    /* 1C65A8 002C65A8 D000A427 */  addiu      $4, $29, 0xD0
    /* 1C65AC 002C65AC 80A88527 */  addiu      $5, $28, -0x5780
    /* 1C65B0 002C65B0 2D304000 */  daddu      $6, $2, $0
    /* 1C65B4 002C65B4 2208110C */  jal        func_00442088
    /* 1C65B8 002C65B8 00000000 */   nop
    /* 1C65BC 002C65BC 2D208002 */  daddu      $4, $20, $0
    /* 1C65C0 002C65C0 06000524 */  addiu      $5, $0, 0x6
    /* 1C65C4 002C65C4 D000A627 */  addiu      $6, $29, 0xD0
    /* 1C65C8 002C65C8 01000724 */  addiu      $7, $0, 0x1
    /* 1C65CC 002C65CC B07F0B0C */  jal        func_002dfec0
    /* 1C65D0 002C65D0 00000000 */   nop
    /* 1C65D4 002C65D4 100022A2 */  sb         $2, 0x10($17)
    /* 1C65D8 002C65D8 2E000224 */  addiu      $2, $0, 0x2E
    /* 1C65DC 002C65DC 000022A2 */  sb         $2, 0x0($17)
    /* 1C65E0 002C65E0 51100010 */  b          .L002CA728
    /* 1C65E4 002C65E4 00000000 */   nop
  .L002C65E8:
    /* 1C65E8 002C65E8 80100300 */  sll        $2, $3, 2
    /* 1C65EC 002C65EC 21105100 */  addu       $2, $2, $17
    /* 1C65F0 002C65F0 180F448C */  lw         $4, 0xF18($2)
    /* 1C65F4 002C65F4 BC890B0C */  jal        func_002e26f0
    /* 1C65F8 002C65F8 00000000 */   nop
    /* 1C65FC 002C65FC 4A104018 */  blez       $2, .L002CA728
    /* 1C6600 002C6600 00000000 */   nop
    /* 1C6604 002C6604 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C6608 002C6608 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C660C 002C660C 2D300000 */  daddu      $6, $0, $0
    /* 1C6610 002C6610 2D380000 */  daddu      $7, $0, $0
    /* 1C6614 002C6614 05000824 */  addiu      $8, $0, 0x5
    /* 1C6618 002C6618 2D480000 */  daddu      $9, $0, $0
    /* 1C661C 002C661C 98810B0C */  jal        func_002e0660
    /* 1C6620 002C6620 00000000 */   nop
    /* 1C6624 002C6624 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C6628 002C6628 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C662C 002C662C 2D300000 */  daddu      $6, $0, $0
    /* 1C6630 002C6630 2D380000 */  daddu      $7, $0, $0
    /* 1C6634 002C6634 05000824 */  addiu      $8, $0, 0x5
    /* 1C6638 002C6638 2D480000 */  daddu      $9, $0, $0
    /* 1C663C 002C663C 98810B0C */  jal        func_002e0660
    /* 1C6640 002C6640 00000000 */   nop
    /* 1C6644 002C6644 240C2282 */  lb         $2, 0xC24($17)
    /* 1C6648 002C6648 7D014014 */  bnez       $2, .L002C6C40
    /* 1C664C 002C664C 00000000 */   nop
    /* 1C6650 002C6650 280F248E */  lw         $4, 0xF28($17)
    /* 1C6654 002C6654 2A000524 */  addiu      $5, $0, 0x2A
    /* 1C6658 002C6658 80B4110C */  jal        func_0046d200
    /* 1C665C 002C665C 00000000 */   nop
    /* 1C6660 002C6660 2D804000 */  daddu      $16, $2, $0
    /* 1C6664 002C6664 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1C6668 002C6668 00608244 */  mtc1       $2, $f12
    /* 1C666C 002C666C E00C248E */  lw         $4, 0xCE0($17)
    /* 1C6670 002C6670 56000524 */  addiu      $5, $0, 0x56
    /* 1C6674 002C6674 78820B0C */  jal        func_002e09e0
    /* 1C6678 002C6678 00000000 */   nop
    /* 1C667C 002C667C F406A427 */  addiu      $4, $29, 0x6F4
    /* 1C6680 002C6680 FE000524 */  addiu      $5, $0, 0xFE
    /* 1C6684 002C6684 C6000624 */  addiu      $6, $0, 0xC6
    /* 1C6688 002C6688 31000724 */  addiu      $7, $0, 0x31
    /* 1C668C 002C668C FF000824 */  addiu      $8, $0, 0xFF
    /* 1C6690 002C6690 98CA0A0C */  jal        func_002b2a60
    /* 1C6694 002C6694 00000000 */   nop
    /* 1C6698 002C6698 E00C248E */  lw         $4, 0xCE0($17)
    /* 1C669C 002C669C 38810B0C */  jal        func_002e04e0
    /* 1C66A0 002C66A0 00000000 */   nop
    /* 1C66A4 002C66A4 F406A693 */  lbu        $6, 0x6F4($29)
    /* 1C66A8 002C66A8 F506A593 */  lbu        $5, 0x6F5($29)
    /* 1C66AC 002C66AC F606A493 */  lbu        $4, 0x6F6($29)
    /* 1C66B0 002C66B0 F706A393 */  lbu        $3, 0x6F7($29)
    /* 1C66B4 002C66B4 790046A0 */  sb         $6, 0x79($2)
    /* 1C66B8 002C66B8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C66BC 002C66BC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C66C0 002C66C0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C66C4 002C66C4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C66C8 002C66C8 00608244 */  mtc1       $2, $f12
    /* 1C66CC 002C66CC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 1C66D0 002C66D0 00708244 */  mtc1       $2, $f14
    /* 1C66D4 002C66D4 E00C248E */  lw         $4, 0xCE0($17)
    /* 1C66D8 002C66D8 46630046 */  mov.s      $f13, $f12
    /* 1C66DC 002C66DC C6630046 */  mov.s      $f15, $f12
    /* 1C66E0 002C66E0 2D280000 */  daddu      $5, $0, $0
    /* 1C66E4 002C66E4 05000624 */  addiu      $6, $0, 0x5
    /* 1C66E8 002C66E8 2D380000 */  daddu      $7, $0, $0
    /* 1C66EC 002C66EC B4810B0C */  jal        func_002e06d0
    /* 1C66F0 002C66F0 00000000 */   nop
    /* 1C66F4 002C66F4 2D200002 */  daddu      $4, $16, $0
    /* 1C66F8 002C66F8 BCAC110C */  jal        func_0046b2f0
    /* 1C66FC 002C66FC 00000000 */   nop
    /* 1C6700 002C6700 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C6704 002C6704 00088244 */  mtc1       $2, $f1
    /* 1C6708 002C6708 00000000 */  nop
    /* 1C670C 002C670C C3000146 */  div.s      $f3, $f0, $f1
    /* 1C6710 002C6710 2040023C */  lui        $2, (0x40200000 >> 16)
    /* 1C6714 002C6714 00108244 */  mtc1       $2, $f2
    /* 1C6718 002C6718 0F43023C */  lui        $2, (0x430F0000 >> 16)
    /* 1C671C 002C671C 00088244 */  mtc1       $2, $f1
    /* 1C6720 002C6720 00008044 */  mtc1       $0, $f0
    /* 1C6724 002C6724 00000000 */  nop
    /* 1C6728 002C6728 18000146 */  adda.s     $f0, $f1
    /* 1C672C 002C672C 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C6730 002C6730 7C42023C */  lui        $2, (0x427C0000 >> 16)
    /* 1C6734 002C6734 00608244 */  mtc1       $2, $f12
    /* 1C6738 002C6738 2803A427 */  addiu      $4, $29, 0x328
    /* 1C673C 002C673C 5CCA0A0C */  jal        func_002b2970
    /* 1C6740 002C6740 00000000 */   nop
    /* 1C6744 002C6744 7C42023C */  lui        $2, (0x427C0000 >> 16)
    /* 1C6748 002C6748 00608244 */  mtc1       $2, $f12
    /* 1C674C 002C674C 0F43023C */  lui        $2, (0x430F0000 >> 16)
    /* 1C6750 002C6750 00688244 */  mtc1       $2, $f13
    /* 1C6754 002C6754 2003A427 */  addiu      $4, $29, 0x320
    /* 1C6758 002C6758 5CCA0A0C */  jal        func_002b2970
    /* 1C675C 002C675C 00000000 */   nop
    /* 1C6760 002C6760 E00C248E */  lw         $4, 0xCE0($17)
    /* 1C6764 002C6764 2803A5DF */  ld         $5, 0x328($29)
    /* 1C6768 002C6768 2003A6DF */  ld         $6, 0x320($29)
    /* 1C676C 002C676C 2D380000 */  daddu      $7, $0, $0
    /* 1C6770 002C6770 05000824 */  addiu      $8, $0, 0x5
    /* 1C6774 002C6774 2D480000 */  daddu      $9, $0, $0
    /* 1C6778 002C6778 88810B0C */  jal        func_002e0620
    /* 1C677C 002C677C 00000000 */   nop
    /* 1C6780 002C6780 E00C248E */  lw         $4, 0xCE0($17)
    /* 1C6784 002C6784 2D280000 */  daddu      $5, $0, $0
    /* 1C6788 002C6788 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C678C 002C678C 2D380000 */  daddu      $7, $0, $0
    /* 1C6790 002C6790 2D400000 */  daddu      $8, $0, $0
    /* 1C6794 002C6794 2D480000 */  daddu      $9, $0, $0
    /* 1C6798 002C6798 98810B0C */  jal        func_002e0660
    /* 1C679C 002C679C 00000000 */   nop
    /* 1C67A0 002C67A0 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C67A4 002C67A4 00608244 */  mtc1       $2, $f12
    /* 1C67A8 002C67A8 E00C248E */  lw         $4, 0xCE0($17)
    /* 1C67AC 002C67AC 03000524 */  addiu      $5, $0, 0x3
    /* 1C67B0 002C67B0 6C820B0C */  jal        func_002e09b0
    /* 1C67B4 002C67B4 00000000 */   nop
    /* 1C67B8 002C67B8 2D200002 */  daddu      $4, $16, $0
    /* 1C67BC 002C67BC A0B4110C */  jal        func_0046d280
    /* 1C67C0 002C67C0 00000000 */   nop
    /* 1C67C4 002C67C4 280F248E */  lw         $4, 0xF28($17)
    /* 1C67C8 002C67C8 2C000524 */  addiu      $5, $0, 0x2C
    /* 1C67CC 002C67CC 80B4110C */  jal        func_0046d200
    /* 1C67D0 002C67D0 00000000 */   nop
    /* 1C67D4 002C67D4 2D804000 */  daddu      $16, $2, $0
    /* 1C67D8 002C67D8 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1C67DC 002C67DC 00608244 */  mtc1       $2, $f12
    /* 1C67E0 002C67E0 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C67E4 002C67E4 56000524 */  addiu      $5, $0, 0x56
    /* 1C67E8 002C67E8 78820B0C */  jal        func_002e09e0
    /* 1C67EC 002C67EC 00000000 */   nop
    /* 1C67F0 002C67F0 F006A427 */  addiu      $4, $29, 0x6F0
    /* 1C67F4 002C67F4 FE000524 */  addiu      $5, $0, 0xFE
    /* 1C67F8 002C67F8 C6000624 */  addiu      $6, $0, 0xC6
    /* 1C67FC 002C67FC 31000724 */  addiu      $7, $0, 0x31
    /* 1C6800 002C6800 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C6804 002C6804 98CA0A0C */  jal        func_002b2a60
    /* 1C6808 002C6808 00000000 */   nop
    /* 1C680C 002C680C E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6810 002C6810 38810B0C */  jal        func_002e04e0
    /* 1C6814 002C6814 00000000 */   nop
    /* 1C6818 002C6818 F006A693 */  lbu        $6, 0x6F0($29)
    /* 1C681C 002C681C F106A593 */  lbu        $5, 0x6F1($29)
    /* 1C6820 002C6820 F206A493 */  lbu        $4, 0x6F2($29)
    /* 1C6824 002C6824 F306A393 */  lbu        $3, 0x6F3($29)
    /* 1C6828 002C6828 790046A0 */  sb         $6, 0x79($2)
    /* 1C682C 002C682C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C6830 002C6830 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C6834 002C6834 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C6838 002C6838 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C683C 002C683C 00608244 */  mtc1       $2, $f12
    /* 1C6840 002C6840 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 1C6844 002C6844 00708244 */  mtc1       $2, $f14
    /* 1C6848 002C6848 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C684C 002C684C 46630046 */  mov.s      $f13, $f12
    /* 1C6850 002C6850 C6630046 */  mov.s      $f15, $f12
    /* 1C6854 002C6854 2D280000 */  daddu      $5, $0, $0
    /* 1C6858 002C6858 05000624 */  addiu      $6, $0, 0x5
    /* 1C685C 002C685C 2D380000 */  daddu      $7, $0, $0
    /* 1C6860 002C6860 B4810B0C */  jal        func_002e06d0
    /* 1C6864 002C6864 00000000 */   nop
    /* 1C6868 002C6868 2D200002 */  daddu      $4, $16, $0
    /* 1C686C 002C686C BCAC110C */  jal        func_0046b2f0
    /* 1C6870 002C6870 00000000 */   nop
    /* 1C6874 002C6874 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C6878 002C6878 00088244 */  mtc1       $2, $f1
    /* 1C687C 002C687C 00000000 */  nop
    /* 1C6880 002C6880 C3000146 */  div.s      $f3, $f0, $f1
    /* 1C6884 002C6884 2040023C */  lui        $2, (0x40200000 >> 16)
    /* 1C6888 002C6888 00108244 */  mtc1       $2, $f2
    /* 1C688C 002C688C 0F43023C */  lui        $2, (0x430F0000 >> 16)
    /* 1C6890 002C6890 00088244 */  mtc1       $2, $f1
    /* 1C6894 002C6894 00008044 */  mtc1       $0, $f0
    /* 1C6898 002C6898 00000000 */  nop
    /* 1C689C 002C689C 18000146 */  adda.s     $f0, $f1
    /* 1C68A0 002C68A0 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C68A4 002C68A4 22020224 */  addiu      $2, $0, 0x222
    /* 1C68A8 002C68A8 00008244 */  mtc1       $2, $f0
    /* 1C68AC 002C68AC 00000000 */  nop
    /* 1C68B0 002C68B0 20038046 */  cvt.s.w    $f12, $f0
    /* 1C68B4 002C68B4 1803A427 */  addiu      $4, $29, 0x318
    /* 1C68B8 002C68B8 5CCA0A0C */  jal        func_002b2970
    /* 1C68BC 002C68BC 00000000 */   nop
    /* 1C68C0 002C68C0 22020224 */  addiu      $2, $0, 0x222
    /* 1C68C4 002C68C4 00008244 */  mtc1       $2, $f0
    /* 1C68C8 002C68C8 00000000 */  nop
    /* 1C68CC 002C68CC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C68D0 002C68D0 0F43023C */  lui        $2, (0x430F0000 >> 16)
    /* 1C68D4 002C68D4 00688244 */  mtc1       $2, $f13
    /* 1C68D8 002C68D8 1003A427 */  addiu      $4, $29, 0x310
    /* 1C68DC 002C68DC 5CCA0A0C */  jal        func_002b2970
    /* 1C68E0 002C68E0 00000000 */   nop
    /* 1C68E4 002C68E4 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C68E8 002C68E8 1803A5DF */  ld         $5, 0x318($29)
    /* 1C68EC 002C68EC 1003A6DF */  ld         $6, 0x310($29)
    /* 1C68F0 002C68F0 2D380000 */  daddu      $7, $0, $0
    /* 1C68F4 002C68F4 05000824 */  addiu      $8, $0, 0x5
    /* 1C68F8 002C68F8 2D480000 */  daddu      $9, $0, $0
    /* 1C68FC 002C68FC 88810B0C */  jal        func_002e0620
    /* 1C6900 002C6900 00000000 */   nop
    /* 1C6904 002C6904 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6908 002C6908 2D280000 */  daddu      $5, $0, $0
    /* 1C690C 002C690C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C6910 002C6910 2D380000 */  daddu      $7, $0, $0
    /* 1C6914 002C6914 2D400000 */  daddu      $8, $0, $0
    /* 1C6918 002C6918 2D480000 */  daddu      $9, $0, $0
    /* 1C691C 002C691C 98810B0C */  jal        func_002e0660
    /* 1C6920 002C6920 00000000 */   nop
    /* 1C6924 002C6924 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C6928 002C6928 00608244 */  mtc1       $2, $f12
    /* 1C692C 002C692C E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6930 002C6930 03000524 */  addiu      $5, $0, 0x3
    /* 1C6934 002C6934 6C820B0C */  jal        func_002e09b0
    /* 1C6938 002C6938 00000000 */   nop
    /* 1C693C 002C693C 2D200002 */  daddu      $4, $16, $0
    /* 1C6940 002C6940 A0B4110C */  jal        func_0046d280
    /* 1C6944 002C6944 00000000 */   nop
    /* 1C6948 002C6948 280F248E */  lw         $4, 0xF28($17)
    /* 1C694C 002C694C 27000524 */  addiu      $5, $0, 0x27
    /* 1C6950 002C6950 80B4110C */  jal        func_0046d200
    /* 1C6954 002C6954 00000000 */   nop
    /* 1C6958 002C6958 2D804000 */  daddu      $16, $2, $0
    /* 1C695C 002C695C A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1C6960 002C6960 00608244 */  mtc1       $2, $f12
    /* 1C6964 002C6964 D40C248E */  lw         $4, 0xCD4($17)
    /* 1C6968 002C6968 41000524 */  addiu      $5, $0, 0x41
    /* 1C696C 002C696C 78820B0C */  jal        func_002e09e0
    /* 1C6970 002C6970 00000000 */   nop
    /* 1C6974 002C6974 EC06A427 */  addiu      $4, $29, 0x6EC
    /* 1C6978 002C6978 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C697C 002C697C 96000624 */  addiu      $6, $0, 0x96
    /* 1C6980 002C6980 2D380000 */  daddu      $7, $0, $0
    /* 1C6984 002C6984 2D40A000 */  daddu      $8, $5, $0
    /* 1C6988 002C6988 98CA0A0C */  jal        func_002b2a60
    /* 1C698C 002C698C 00000000 */   nop
    /* 1C6990 002C6990 D40C248E */  lw         $4, 0xCD4($17)
    /* 1C6994 002C6994 38810B0C */  jal        func_002e04e0
    /* 1C6998 002C6998 00000000 */   nop
    /* 1C699C 002C699C EC06A693 */  lbu        $6, 0x6EC($29)
    /* 1C69A0 002C69A0 ED06A593 */  lbu        $5, 0x6ED($29)
    /* 1C69A4 002C69A4 EE06A493 */  lbu        $4, 0x6EE($29)
    /* 1C69A8 002C69A8 EF06A393 */  lbu        $3, 0x6EF($29)
    /* 1C69AC 002C69AC 790046A0 */  sb         $6, 0x79($2)
    /* 1C69B0 002C69B0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C69B4 002C69B4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C69B8 002C69B8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C69BC 002C69BC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C69C0 002C69C0 00608244 */  mtc1       $2, $f12
    /* 1C69C4 002C69C4 D40C248E */  lw         $4, 0xCD4($17)
    /* 1C69C8 002C69C8 46630046 */  mov.s      $f13, $f12
    /* 1C69CC 002C69CC 70818EC7 */  lwc1       $f14, -0x7E90($28)
    /* 1C69D0 002C69D0 C6630046 */  mov.s      $f15, $f12
    /* 1C69D4 002C69D4 02000524 */  addiu      $5, $0, 0x2
    /* 1C69D8 002C69D8 04000624 */  addiu      $6, $0, 0x4
    /* 1C69DC 002C69DC 2D380000 */  daddu      $7, $0, $0
    /* 1C69E0 002C69E0 B4810B0C */  jal        func_002e06d0
    /* 1C69E4 002C69E4 00000000 */   nop
    /* 1C69E8 002C69E8 D40C248E */  lw         $4, 0xCD4($17)
    /* 1C69EC 002C69EC 2D280000 */  daddu      $5, $0, $0
    /* 1C69F0 002C69F0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C69F4 002C69F4 2D380000 */  daddu      $7, $0, $0
    /* 1C69F8 002C69F8 04000824 */  addiu      $8, $0, 0x4
    /* 1C69FC 002C69FC 2D480000 */  daddu      $9, $0, $0
    /* 1C6A00 002C6A00 98810B0C */  jal        func_002e0660
    /* 1C6A04 002C6A04 00000000 */   nop
    /* 1C6A08 002C6A08 2D200002 */  daddu      $4, $16, $0
    /* 1C6A0C 002C6A0C BCAC110C */  jal        func_0046b2f0
    /* 1C6A10 002C6A10 00000000 */   nop
    /* 1C6A14 002C6A14 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C6A18 002C6A18 00088244 */  mtc1       $2, $f1
    /* 1C6A1C 002C6A1C 00000000 */  nop
    /* 1C6A20 002C6A20 C3000146 */  div.s      $f3, $f0, $f1
    /* 1C6A24 002C6A24 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C6A28 002C6A28 00108244 */  mtc1       $2, $f2
    /* 1C6A2C 002C6A2C 0443023C */  lui        $2, (0x43040000 >> 16)
    /* 1C6A30 002C6A30 00088244 */  mtc1       $2, $f1
    /* 1C6A34 002C6A34 00008044 */  mtc1       $0, $f0
    /* 1C6A38 002C6A38 00000000 */  nop
    /* 1C6A3C 002C6A3C 18000146 */  adda.s     $f0, $f1
    /* 1C6A40 002C6A40 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C6A44 002C6A44 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1C6A48 002C6A48 00608244 */  mtc1       $2, $f12
    /* 1C6A4C 002C6A4C 0803A427 */  addiu      $4, $29, 0x308
    /* 1C6A50 002C6A50 5CCA0A0C */  jal        func_002b2970
    /* 1C6A54 002C6A54 00000000 */   nop
    /* 1C6A58 002C6A58 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1C6A5C 002C6A5C 00608244 */  mtc1       $2, $f12
    /* 1C6A60 002C6A60 0443023C */  lui        $2, (0x43040000 >> 16)
    /* 1C6A64 002C6A64 00688244 */  mtc1       $2, $f13
    /* 1C6A68 002C6A68 0003A427 */  addiu      $4, $29, 0x300
    /* 1C6A6C 002C6A6C 5CCA0A0C */  jal        func_002b2970
    /* 1C6A70 002C6A70 00000000 */   nop
    /* 1C6A74 002C6A74 D40C248E */  lw         $4, 0xCD4($17)
    /* 1C6A78 002C6A78 0803A5DF */  ld         $5, 0x308($29)
    /* 1C6A7C 002C6A7C 0003A6DF */  ld         $6, 0x300($29)
    /* 1C6A80 002C6A80 02000724 */  addiu      $7, $0, 0x2
    /* 1C6A84 002C6A84 04000824 */  addiu      $8, $0, 0x4
    /* 1C6A88 002C6A88 2D480000 */  daddu      $9, $0, $0
    /* 1C6A8C 002C6A8C 88810B0C */  jal        func_002e0620
    /* 1C6A90 002C6A90 00000000 */   nop
    /* 1C6A94 002C6A94 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C6A98 002C6A98 00608244 */  mtc1       $2, $f12
    /* 1C6A9C 002C6A9C D40C248E */  lw         $4, 0xCD4($17)
    /* 1C6AA0 002C6AA0 03000524 */  addiu      $5, $0, 0x3
    /* 1C6AA4 002C6AA4 6C820B0C */  jal        func_002e09b0
    /* 1C6AA8 002C6AA8 00000000 */   nop
    /* 1C6AAC 002C6AAC 2D200002 */  daddu      $4, $16, $0
    /* 1C6AB0 002C6AB0 A0B4110C */  jal        func_0046d280
    /* 1C6AB4 002C6AB4 00000000 */   nop
    /* 1C6AB8 002C6AB8 280F248E */  lw         $4, 0xF28($17)
    /* 1C6ABC 002C6ABC 29000524 */  addiu      $5, $0, 0x29
    /* 1C6AC0 002C6AC0 80B4110C */  jal        func_0046d200
    /* 1C6AC4 002C6AC4 00000000 */   nop
    /* 1C6AC8 002C6AC8 2D804000 */  daddu      $16, $2, $0
    /* 1C6ACC 002C6ACC A841023C */  lui        $2, (0x41A80000 >> 16)
    /* 1C6AD0 002C6AD0 00608244 */  mtc1       $2, $f12
    /* 1C6AD4 002C6AD4 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C6AD8 002C6AD8 41000524 */  addiu      $5, $0, 0x41
    /* 1C6ADC 002C6ADC 78820B0C */  jal        func_002e09e0
    /* 1C6AE0 002C6AE0 00000000 */   nop
    /* 1C6AE4 002C6AE4 E806A427 */  addiu      $4, $29, 0x6E8
    /* 1C6AE8 002C6AE8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C6AEC 002C6AEC 96000624 */  addiu      $6, $0, 0x96
    /* 1C6AF0 002C6AF0 2D380000 */  daddu      $7, $0, $0
    /* 1C6AF4 002C6AF4 2D40A000 */  daddu      $8, $5, $0
    /* 1C6AF8 002C6AF8 98CA0A0C */  jal        func_002b2a60
    /* 1C6AFC 002C6AFC 00000000 */   nop
    /* 1C6B00 002C6B00 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C6B04 002C6B04 38810B0C */  jal        func_002e04e0
    /* 1C6B08 002C6B08 00000000 */   nop
    /* 1C6B0C 002C6B0C E806A693 */  lbu        $6, 0x6E8($29)
    /* 1C6B10 002C6B10 E906A593 */  lbu        $5, 0x6E9($29)
    /* 1C6B14 002C6B14 EA06A493 */  lbu        $4, 0x6EA($29)
    /* 1C6B18 002C6B18 EB06A393 */  lbu        $3, 0x6EB($29)
    /* 1C6B1C 002C6B1C 790046A0 */  sb         $6, 0x79($2)
    /* 1C6B20 002C6B20 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C6B24 002C6B24 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C6B28 002C6B28 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C6B2C 002C6B2C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C6B30 002C6B30 00608244 */  mtc1       $2, $f12
    /* 1C6B34 002C6B34 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C6B38 002C6B38 46630046 */  mov.s      $f13, $f12
    /* 1C6B3C 002C6B3C 70818EC7 */  lwc1       $f14, -0x7E90($28)
    /* 1C6B40 002C6B40 C6630046 */  mov.s      $f15, $f12
    /* 1C6B44 002C6B44 02000524 */  addiu      $5, $0, 0x2
    /* 1C6B48 002C6B48 04000624 */  addiu      $6, $0, 0x4
    /* 1C6B4C 002C6B4C 2D380000 */  daddu      $7, $0, $0
    /* 1C6B50 002C6B50 B4810B0C */  jal        func_002e06d0
    /* 1C6B54 002C6B54 00000000 */   nop
    /* 1C6B58 002C6B58 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C6B5C 002C6B5C 2D280000 */  daddu      $5, $0, $0
    /* 1C6B60 002C6B60 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C6B64 002C6B64 2D380000 */  daddu      $7, $0, $0
    /* 1C6B68 002C6B68 04000824 */  addiu      $8, $0, 0x4
    /* 1C6B6C 002C6B6C 2D480000 */  daddu      $9, $0, $0
    /* 1C6B70 002C6B70 98810B0C */  jal        func_002e0660
    /* 1C6B74 002C6B74 00000000 */   nop
    /* 1C6B78 002C6B78 2D200002 */  daddu      $4, $16, $0
    /* 1C6B7C 002C6B7C BCAC110C */  jal        func_0046b2f0
    /* 1C6B80 002C6B80 00000000 */   nop
    /* 1C6B84 002C6B84 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C6B88 002C6B88 00088244 */  mtc1       $2, $f1
    /* 1C6B8C 002C6B8C 00000000 */  nop
    /* 1C6B90 002C6B90 C3000146 */  div.s      $f3, $f0, $f1
    /* 1C6B94 002C6B94 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C6B98 002C6B98 00108244 */  mtc1       $2, $f2
    /* 1C6B9C 002C6B9C 0443023C */  lui        $2, (0x43040000 >> 16)
    /* 1C6BA0 002C6BA0 00088244 */  mtc1       $2, $f1
    /* 1C6BA4 002C6BA4 00008044 */  mtc1       $0, $f0
    /* 1C6BA8 002C6BA8 00000000 */  nop
    /* 1C6BAC 002C6BAC 18000146 */  adda.s     $f0, $f1
    /* 1C6BB0 002C6BB0 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C6BB4 002C6BB4 32020224 */  addiu      $2, $0, 0x232
    /* 1C6BB8 002C6BB8 00008244 */  mtc1       $2, $f0
    /* 1C6BBC 002C6BBC 00000000 */  nop
    /* 1C6BC0 002C6BC0 20038046 */  cvt.s.w    $f12, $f0
    /* 1C6BC4 002C6BC4 F802A427 */  addiu      $4, $29, 0x2F8
    /* 1C6BC8 002C6BC8 5CCA0A0C */  jal        func_002b2970
    /* 1C6BCC 002C6BCC 00000000 */   nop
    /* 1C6BD0 002C6BD0 32020224 */  addiu      $2, $0, 0x232
    /* 1C6BD4 002C6BD4 00008244 */  mtc1       $2, $f0
    /* 1C6BD8 002C6BD8 00000000 */  nop
    /* 1C6BDC 002C6BDC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C6BE0 002C6BE0 0443023C */  lui        $2, (0x43040000 >> 16)
    /* 1C6BE4 002C6BE4 00688244 */  mtc1       $2, $f13
    /* 1C6BE8 002C6BE8 F002A427 */  addiu      $4, $29, 0x2F0
    /* 1C6BEC 002C6BEC 5CCA0A0C */  jal        func_002b2970
    /* 1C6BF0 002C6BF0 00000000 */   nop
    /* 1C6BF4 002C6BF4 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C6BF8 002C6BF8 F802A5DF */  ld         $5, 0x2F8($29)
    /* 1C6BFC 002C6BFC F002A6DF */  ld         $6, 0x2F0($29)
    /* 1C6C00 002C6C00 02000724 */  addiu      $7, $0, 0x2
    /* 1C6C04 002C6C04 04000824 */  addiu      $8, $0, 0x4
    /* 1C6C08 002C6C08 2D480000 */  daddu      $9, $0, $0
    /* 1C6C0C 002C6C0C 88810B0C */  jal        func_002e0620
    /* 1C6C10 002C6C10 00000000 */   nop
    /* 1C6C14 002C6C14 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C6C18 002C6C18 00608244 */  mtc1       $2, $f12
    /* 1C6C1C 002C6C1C DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C6C20 002C6C20 03000524 */  addiu      $5, $0, 0x3
    /* 1C6C24 002C6C24 6C820B0C */  jal        func_002e09b0
    /* 1C6C28 002C6C28 00000000 */   nop
    /* 1C6C2C 002C6C2C 2D200002 */  daddu      $4, $16, $0
    /* 1C6C30 002C6C30 A0B4110C */  jal        func_0046d280
    /* 1C6C34 002C6C34 00000000 */   nop
    /* 1C6C38 002C6C38 77010010 */  b          .L002C7218
    /* 1C6C3C 002C6C3C 00000000 */   nop
  .L002C6C40:
    /* 1C6C40 002C6C40 280F248E */  lw         $4, 0xF28($17)
    /* 1C6C44 002C6C44 2B000524 */  addiu      $5, $0, 0x2B
    /* 1C6C48 002C6C48 80B4110C */  jal        func_0046d200
    /* 1C6C4C 002C6C4C 00000000 */   nop
    /* 1C6C50 002C6C50 2D804000 */  daddu      $16, $2, $0
    /* 1C6C54 002C6C54 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1C6C58 002C6C58 00608244 */  mtc1       $2, $f12
    /* 1C6C5C 002C6C5C E40C248E */  lw         $4, 0xCE4($17)
    /* 1C6C60 002C6C60 56000524 */  addiu      $5, $0, 0x56
    /* 1C6C64 002C6C64 78820B0C */  jal        func_002e09e0
    /* 1C6C68 002C6C68 00000000 */   nop
    /* 1C6C6C 002C6C6C E406A427 */  addiu      $4, $29, 0x6E4
    /* 1C6C70 002C6C70 FE000524 */  addiu      $5, $0, 0xFE
    /* 1C6C74 002C6C74 C6000624 */  addiu      $6, $0, 0xC6
    /* 1C6C78 002C6C78 31000724 */  addiu      $7, $0, 0x31
    /* 1C6C7C 002C6C7C FF000824 */  addiu      $8, $0, 0xFF
    /* 1C6C80 002C6C80 98CA0A0C */  jal        func_002b2a60
    /* 1C6C84 002C6C84 00000000 */   nop
    /* 1C6C88 002C6C88 E40C248E */  lw         $4, 0xCE4($17)
    /* 1C6C8C 002C6C8C 38810B0C */  jal        func_002e04e0
    /* 1C6C90 002C6C90 00000000 */   nop
    /* 1C6C94 002C6C94 E406A693 */  lbu        $6, 0x6E4($29)
    /* 1C6C98 002C6C98 E506A593 */  lbu        $5, 0x6E5($29)
    /* 1C6C9C 002C6C9C E606A493 */  lbu        $4, 0x6E6($29)
    /* 1C6CA0 002C6CA0 E706A393 */  lbu        $3, 0x6E7($29)
    /* 1C6CA4 002C6CA4 790046A0 */  sb         $6, 0x79($2)
    /* 1C6CA8 002C6CA8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C6CAC 002C6CAC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C6CB0 002C6CB0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C6CB4 002C6CB4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C6CB8 002C6CB8 00608244 */  mtc1       $2, $f12
    /* 1C6CBC 002C6CBC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 1C6CC0 002C6CC0 00708244 */  mtc1       $2, $f14
    /* 1C6CC4 002C6CC4 E40C248E */  lw         $4, 0xCE4($17)
    /* 1C6CC8 002C6CC8 46630046 */  mov.s      $f13, $f12
    /* 1C6CCC 002C6CCC C6630046 */  mov.s      $f15, $f12
    /* 1C6CD0 002C6CD0 2D280000 */  daddu      $5, $0, $0
    /* 1C6CD4 002C6CD4 05000624 */  addiu      $6, $0, 0x5
    /* 1C6CD8 002C6CD8 2D380000 */  daddu      $7, $0, $0
    /* 1C6CDC 002C6CDC B4810B0C */  jal        func_002e06d0
    /* 1C6CE0 002C6CE0 00000000 */   nop
    /* 1C6CE4 002C6CE4 2D200002 */  daddu      $4, $16, $0
    /* 1C6CE8 002C6CE8 BCAC110C */  jal        func_0046b2f0
    /* 1C6CEC 002C6CEC 00000000 */   nop
    /* 1C6CF0 002C6CF0 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C6CF4 002C6CF4 00088244 */  mtc1       $2, $f1
    /* 1C6CF8 002C6CF8 00000000 */  nop
    /* 1C6CFC 002C6CFC C3000146 */  div.s      $f3, $f0, $f1
    /* 1C6D00 002C6D00 2040023C */  lui        $2, (0x40200000 >> 16)
    /* 1C6D04 002C6D04 00108244 */  mtc1       $2, $f2
    /* 1C6D08 002C6D08 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1C6D0C 002C6D0C 00088244 */  mtc1       $2, $f1
    /* 1C6D10 002C6D10 00008044 */  mtc1       $0, $f0
    /* 1C6D14 002C6D14 00000000 */  nop
    /* 1C6D18 002C6D18 18000146 */  adda.s     $f0, $f1
    /* 1C6D1C 002C6D1C 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C6D20 002C6D20 8642023C */  lui        $2, (0x42860000 >> 16)
    /* 1C6D24 002C6D24 00608244 */  mtc1       $2, $f12
    /* 1C6D28 002C6D28 E802A427 */  addiu      $4, $29, 0x2E8
    /* 1C6D2C 002C6D2C 5CCA0A0C */  jal        func_002b2970
    /* 1C6D30 002C6D30 00000000 */   nop
    /* 1C6D34 002C6D34 8642023C */  lui        $2, (0x42860000 >> 16)
    /* 1C6D38 002C6D38 00608244 */  mtc1       $2, $f12
    /* 1C6D3C 002C6D3C 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1C6D40 002C6D40 00688244 */  mtc1       $2, $f13
    /* 1C6D44 002C6D44 E002A427 */  addiu      $4, $29, 0x2E0
    /* 1C6D48 002C6D48 5CCA0A0C */  jal        func_002b2970
    /* 1C6D4C 002C6D4C 00000000 */   nop
    /* 1C6D50 002C6D50 E40C248E */  lw         $4, 0xCE4($17)
    /* 1C6D54 002C6D54 E802A5DF */  ld         $5, 0x2E8($29)
    /* 1C6D58 002C6D58 E002A6DF */  ld         $6, 0x2E0($29)
    /* 1C6D5C 002C6D5C 2D380000 */  daddu      $7, $0, $0
    /* 1C6D60 002C6D60 05000824 */  addiu      $8, $0, 0x5
    /* 1C6D64 002C6D64 2D480000 */  daddu      $9, $0, $0
    /* 1C6D68 002C6D68 88810B0C */  jal        func_002e0620
    /* 1C6D6C 002C6D6C 00000000 */   nop
    /* 1C6D70 002C6D70 E40C248E */  lw         $4, 0xCE4($17)
    /* 1C6D74 002C6D74 2D280000 */  daddu      $5, $0, $0
    /* 1C6D78 002C6D78 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C6D7C 002C6D7C 2D380000 */  daddu      $7, $0, $0
    /* 1C6D80 002C6D80 2D400000 */  daddu      $8, $0, $0
    /* 1C6D84 002C6D84 2D480000 */  daddu      $9, $0, $0
    /* 1C6D88 002C6D88 98810B0C */  jal        func_002e0660
    /* 1C6D8C 002C6D8C 00000000 */   nop
    /* 1C6D90 002C6D90 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C6D94 002C6D94 00608244 */  mtc1       $2, $f12
    /* 1C6D98 002C6D98 E40C248E */  lw         $4, 0xCE4($17)
    /* 1C6D9C 002C6D9C 03000524 */  addiu      $5, $0, 0x3
    /* 1C6DA0 002C6DA0 6C820B0C */  jal        func_002e09b0
    /* 1C6DA4 002C6DA4 00000000 */   nop
    /* 1C6DA8 002C6DA8 2D200002 */  daddu      $4, $16, $0
    /* 1C6DAC 002C6DAC A0B4110C */  jal        func_0046d280
    /* 1C6DB0 002C6DB0 00000000 */   nop
    /* 1C6DB4 002C6DB4 280F248E */  lw         $4, 0xF28($17)
    /* 1C6DB8 002C6DB8 2C000524 */  addiu      $5, $0, 0x2C
    /* 1C6DBC 002C6DBC 80B4110C */  jal        func_0046d200
    /* 1C6DC0 002C6DC0 00000000 */   nop
    /* 1C6DC4 002C6DC4 2D804000 */  daddu      $16, $2, $0
    /* 1C6DC8 002C6DC8 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1C6DCC 002C6DCC 00608244 */  mtc1       $2, $f12
    /* 1C6DD0 002C6DD0 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6DD4 002C6DD4 56000524 */  addiu      $5, $0, 0x56
    /* 1C6DD8 002C6DD8 78820B0C */  jal        func_002e09e0
    /* 1C6DDC 002C6DDC 00000000 */   nop
    /* 1C6DE0 002C6DE0 E006A427 */  addiu      $4, $29, 0x6E0
    /* 1C6DE4 002C6DE4 FE000524 */  addiu      $5, $0, 0xFE
    /* 1C6DE8 002C6DE8 C6000624 */  addiu      $6, $0, 0xC6
    /* 1C6DEC 002C6DEC 31000724 */  addiu      $7, $0, 0x31
    /* 1C6DF0 002C6DF0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C6DF4 002C6DF4 98CA0A0C */  jal        func_002b2a60
    /* 1C6DF8 002C6DF8 00000000 */   nop
    /* 1C6DFC 002C6DFC E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6E00 002C6E00 38810B0C */  jal        func_002e04e0
    /* 1C6E04 002C6E04 00000000 */   nop
    /* 1C6E08 002C6E08 E006A693 */  lbu        $6, 0x6E0($29)
    /* 1C6E0C 002C6E0C E106A593 */  lbu        $5, 0x6E1($29)
    /* 1C6E10 002C6E10 E206A493 */  lbu        $4, 0x6E2($29)
    /* 1C6E14 002C6E14 E306A393 */  lbu        $3, 0x6E3($29)
    /* 1C6E18 002C6E18 790046A0 */  sb         $6, 0x79($2)
    /* 1C6E1C 002C6E1C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C6E20 002C6E20 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C6E24 002C6E24 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C6E28 002C6E28 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C6E2C 002C6E2C 00608244 */  mtc1       $2, $f12
    /* 1C6E30 002C6E30 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 1C6E34 002C6E34 00708244 */  mtc1       $2, $f14
    /* 1C6E38 002C6E38 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6E3C 002C6E3C 46630046 */  mov.s      $f13, $f12
    /* 1C6E40 002C6E40 C6630046 */  mov.s      $f15, $f12
    /* 1C6E44 002C6E44 2D280000 */  daddu      $5, $0, $0
    /* 1C6E48 002C6E48 05000624 */  addiu      $6, $0, 0x5
    /* 1C6E4C 002C6E4C 2D380000 */  daddu      $7, $0, $0
    /* 1C6E50 002C6E50 B4810B0C */  jal        func_002e06d0
    /* 1C6E54 002C6E54 00000000 */   nop
    /* 1C6E58 002C6E58 2D200002 */  daddu      $4, $16, $0
    /* 1C6E5C 002C6E5C BCAC110C */  jal        func_0046b2f0
    /* 1C6E60 002C6E60 00000000 */   nop
    /* 1C6E64 002C6E64 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C6E68 002C6E68 00088244 */  mtc1       $2, $f1
    /* 1C6E6C 002C6E6C 00000000 */  nop
    /* 1C6E70 002C6E70 C3000146 */  div.s      $f3, $f0, $f1
    /* 1C6E74 002C6E74 2040023C */  lui        $2, (0x40200000 >> 16)
    /* 1C6E78 002C6E78 00108244 */  mtc1       $2, $f2
    /* 1C6E7C 002C6E7C 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1C6E80 002C6E80 00088244 */  mtc1       $2, $f1
    /* 1C6E84 002C6E84 00008044 */  mtc1       $0, $f0
    /* 1C6E88 002C6E88 00000000 */  nop
    /* 1C6E8C 002C6E8C 18000146 */  adda.s     $f0, $f1
    /* 1C6E90 002C6E90 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C6E94 002C6E94 2F020224 */  addiu      $2, $0, 0x22F
    /* 1C6E98 002C6E98 00008244 */  mtc1       $2, $f0
    /* 1C6E9C 002C6E9C 00000000 */  nop
    /* 1C6EA0 002C6EA0 20038046 */  cvt.s.w    $f12, $f0
    /* 1C6EA4 002C6EA4 D802A427 */  addiu      $4, $29, 0x2D8
    /* 1C6EA8 002C6EA8 5CCA0A0C */  jal        func_002b2970
    /* 1C6EAC 002C6EAC 00000000 */   nop
    /* 1C6EB0 002C6EB0 2F020224 */  addiu      $2, $0, 0x22F
    /* 1C6EB4 002C6EB4 00008244 */  mtc1       $2, $f0
    /* 1C6EB8 002C6EB8 00000000 */  nop
    /* 1C6EBC 002C6EBC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C6EC0 002C6EC0 0C43023C */  lui        $2, (0x430C0000 >> 16)
    /* 1C6EC4 002C6EC4 00688244 */  mtc1       $2, $f13
    /* 1C6EC8 002C6EC8 D002A427 */  addiu      $4, $29, 0x2D0
    /* 1C6ECC 002C6ECC 5CCA0A0C */  jal        func_002b2970
    /* 1C6ED0 002C6ED0 00000000 */   nop
    /* 1C6ED4 002C6ED4 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6ED8 002C6ED8 D802A5DF */  ld         $5, 0x2D8($29)
    /* 1C6EDC 002C6EDC D002A6DF */  ld         $6, 0x2D0($29)
    /* 1C6EE0 002C6EE0 2D380000 */  daddu      $7, $0, $0
    /* 1C6EE4 002C6EE4 05000824 */  addiu      $8, $0, 0x5
    /* 1C6EE8 002C6EE8 2D480000 */  daddu      $9, $0, $0
    /* 1C6EEC 002C6EEC 88810B0C */  jal        func_002e0620
    /* 1C6EF0 002C6EF0 00000000 */   nop
    /* 1C6EF4 002C6EF4 E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6EF8 002C6EF8 2D280000 */  daddu      $5, $0, $0
    /* 1C6EFC 002C6EFC FF000624 */  addiu      $6, $0, 0xFF
    /* 1C6F00 002C6F00 2D380000 */  daddu      $7, $0, $0
    /* 1C6F04 002C6F04 2D400000 */  daddu      $8, $0, $0
    /* 1C6F08 002C6F08 2D480000 */  daddu      $9, $0, $0
    /* 1C6F0C 002C6F0C 98810B0C */  jal        func_002e0660
    /* 1C6F10 002C6F10 00000000 */   nop
    /* 1C6F14 002C6F14 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C6F18 002C6F18 00608244 */  mtc1       $2, $f12
    /* 1C6F1C 002C6F1C E80C248E */  lw         $4, 0xCE8($17)
    /* 1C6F20 002C6F20 03000524 */  addiu      $5, $0, 0x3
    /* 1C6F24 002C6F24 6C820B0C */  jal        func_002e09b0
    /* 1C6F28 002C6F28 00000000 */   nop
    /* 1C6F2C 002C6F2C 2D200002 */  daddu      $4, $16, $0
    /* 1C6F30 002C6F30 A0B4110C */  jal        func_0046d280
    /* 1C6F34 002C6F34 00000000 */   nop
    /* 1C6F38 002C6F38 280F248E */  lw         $4, 0xF28($17)
    /* 1C6F3C 002C6F3C 28000524 */  addiu      $5, $0, 0x28
    /* 1C6F40 002C6F40 80B4110C */  jal        func_0046d200
    /* 1C6F44 002C6F44 00000000 */   nop
    /* 1C6F48 002C6F48 2D804000 */  daddu      $16, $2, $0
    /* 1C6F4C 002C6F4C A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1C6F50 002C6F50 00608244 */  mtc1       $2, $f12
    /* 1C6F54 002C6F54 D80C248E */  lw         $4, 0xCD8($17)
    /* 1C6F58 002C6F58 41000524 */  addiu      $5, $0, 0x41
    /* 1C6F5C 002C6F5C 78820B0C */  jal        func_002e09e0
    /* 1C6F60 002C6F60 00000000 */   nop
    /* 1C6F64 002C6F64 DC06A427 */  addiu      $4, $29, 0x6DC
    /* 1C6F68 002C6F68 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C6F6C 002C6F6C 96000624 */  addiu      $6, $0, 0x96
    /* 1C6F70 002C6F70 2D380000 */  daddu      $7, $0, $0
    /* 1C6F74 002C6F74 2D40A000 */  daddu      $8, $5, $0
    /* 1C6F78 002C6F78 98CA0A0C */  jal        func_002b2a60
    /* 1C6F7C 002C6F7C 00000000 */   nop
    /* 1C6F80 002C6F80 D80C248E */  lw         $4, 0xCD8($17)
    /* 1C6F84 002C6F84 38810B0C */  jal        func_002e04e0
    /* 1C6F88 002C6F88 00000000 */   nop
    /* 1C6F8C 002C6F8C DC06A693 */  lbu        $6, 0x6DC($29)
    /* 1C6F90 002C6F90 DD06A593 */  lbu        $5, 0x6DD($29)
    /* 1C6F94 002C6F94 DE06A493 */  lbu        $4, 0x6DE($29)
    /* 1C6F98 002C6F98 DF06A393 */  lbu        $3, 0x6DF($29)
    /* 1C6F9C 002C6F9C 790046A0 */  sb         $6, 0x79($2)
    /* 1C6FA0 002C6FA0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C6FA4 002C6FA4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C6FA8 002C6FA8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C6FAC 002C6FAC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C6FB0 002C6FB0 00608244 */  mtc1       $2, $f12
    /* 1C6FB4 002C6FB4 D80C248E */  lw         $4, 0xCD8($17)
    /* 1C6FB8 002C6FB8 46630046 */  mov.s      $f13, $f12
    /* 1C6FBC 002C6FBC 70818EC7 */  lwc1       $f14, -0x7E90($28)
    /* 1C6FC0 002C6FC0 C6630046 */  mov.s      $f15, $f12
    /* 1C6FC4 002C6FC4 02000524 */  addiu      $5, $0, 0x2
    /* 1C6FC8 002C6FC8 04000624 */  addiu      $6, $0, 0x4
    /* 1C6FCC 002C6FCC 2D380000 */  daddu      $7, $0, $0
    /* 1C6FD0 002C6FD0 B4810B0C */  jal        func_002e06d0
    /* 1C6FD4 002C6FD4 00000000 */   nop
    /* 1C6FD8 002C6FD8 D80C248E */  lw         $4, 0xCD8($17)
    /* 1C6FDC 002C6FDC 2D280000 */  daddu      $5, $0, $0
    /* 1C6FE0 002C6FE0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C6FE4 002C6FE4 2D380000 */  daddu      $7, $0, $0
    /* 1C6FE8 002C6FE8 04000824 */  addiu      $8, $0, 0x4
    /* 1C6FEC 002C6FEC 2D480000 */  daddu      $9, $0, $0
    /* 1C6FF0 002C6FF0 98810B0C */  jal        func_002e0660
    /* 1C6FF4 002C6FF4 00000000 */   nop
    /* 1C6FF8 002C6FF8 2D200002 */  daddu      $4, $16, $0
    /* 1C6FFC 002C6FFC BCAC110C */  jal        func_0046b2f0
    /* 1C7000 002C7000 00000000 */   nop
    /* 1C7004 002C7004 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C7008 002C7008 00088244 */  mtc1       $2, $f1
    /* 1C700C 002C700C 00000000 */  nop
    /* 1C7010 002C7010 C3000146 */  div.s      $f3, $f0, $f1
    /* 1C7014 002C7014 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C7018 002C7018 00108244 */  mtc1       $2, $f2
    /* 1C701C 002C701C FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1C7020 002C7020 00088244 */  mtc1       $2, $f1
    /* 1C7024 002C7024 00008044 */  mtc1       $0, $f0
    /* 1C7028 002C7028 00000000 */  nop
    /* 1C702C 002C702C 18000146 */  adda.s     $f0, $f1
    /* 1C7030 002C7030 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C7034 002C7034 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1C7038 002C7038 00608244 */  mtc1       $2, $f12
    /* 1C703C 002C703C C802A427 */  addiu      $4, $29, 0x2C8
    /* 1C7040 002C7040 5CCA0A0C */  jal        func_002b2970
    /* 1C7044 002C7044 00000000 */   nop
    /* 1C7048 002C7048 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1C704C 002C704C 00608244 */  mtc1       $2, $f12
    /* 1C7050 002C7050 FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1C7054 002C7054 00688244 */  mtc1       $2, $f13
    /* 1C7058 002C7058 C002A427 */  addiu      $4, $29, 0x2C0
    /* 1C705C 002C705C 5CCA0A0C */  jal        func_002b2970
    /* 1C7060 002C7060 00000000 */   nop
    /* 1C7064 002C7064 D80C248E */  lw         $4, 0xCD8($17)
    /* 1C7068 002C7068 C802A5DF */  ld         $5, 0x2C8($29)
    /* 1C706C 002C706C C002A6DF */  ld         $6, 0x2C0($29)
    /* 1C7070 002C7070 02000724 */  addiu      $7, $0, 0x2
    /* 1C7074 002C7074 04000824 */  addiu      $8, $0, 0x4
    /* 1C7078 002C7078 2D480000 */  daddu      $9, $0, $0
    /* 1C707C 002C707C 88810B0C */  jal        func_002e0620
    /* 1C7080 002C7080 00000000 */   nop
    /* 1C7084 002C7084 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C7088 002C7088 00608244 */  mtc1       $2, $f12
    /* 1C708C 002C708C D80C248E */  lw         $4, 0xCD8($17)
    /* 1C7090 002C7090 03000524 */  addiu      $5, $0, 0x3
    /* 1C7094 002C7094 6C820B0C */  jal        func_002e09b0
    /* 1C7098 002C7098 00000000 */   nop
    /* 1C709C 002C709C 2D200002 */  daddu      $4, $16, $0
    /* 1C70A0 002C70A0 A0B4110C */  jal        func_0046d280
    /* 1C70A4 002C70A4 00000000 */   nop
    /* 1C70A8 002C70A8 280F248E */  lw         $4, 0xF28($17)
    /* 1C70AC 002C70AC 29000524 */  addiu      $5, $0, 0x29
    /* 1C70B0 002C70B0 80B4110C */  jal        func_0046d200
    /* 1C70B4 002C70B4 00000000 */   nop
    /* 1C70B8 002C70B8 2D804000 */  daddu      $16, $2, $0
    /* 1C70BC 002C70BC A841023C */  lui        $2, (0x41A80000 >> 16)
    /* 1C70C0 002C70C0 00608244 */  mtc1       $2, $f12
    /* 1C70C4 002C70C4 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C70C8 002C70C8 41000524 */  addiu      $5, $0, 0x41
    /* 1C70CC 002C70CC 78820B0C */  jal        func_002e09e0
    /* 1C70D0 002C70D0 00000000 */   nop
    /* 1C70D4 002C70D4 D806A427 */  addiu      $4, $29, 0x6D8
    /* 1C70D8 002C70D8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C70DC 002C70DC 96000624 */  addiu      $6, $0, 0x96
    /* 1C70E0 002C70E0 2D380000 */  daddu      $7, $0, $0
    /* 1C70E4 002C70E4 2D40A000 */  daddu      $8, $5, $0
    /* 1C70E8 002C70E8 98CA0A0C */  jal        func_002b2a60
    /* 1C70EC 002C70EC 00000000 */   nop
    /* 1C70F0 002C70F0 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C70F4 002C70F4 38810B0C */  jal        func_002e04e0
    /* 1C70F8 002C70F8 00000000 */   nop
    /* 1C70FC 002C70FC D806A693 */  lbu        $6, 0x6D8($29)
    /* 1C7100 002C7100 D906A593 */  lbu        $5, 0x6D9($29)
    /* 1C7104 002C7104 DA06A493 */  lbu        $4, 0x6DA($29)
    /* 1C7108 002C7108 DB06A393 */  lbu        $3, 0x6DB($29)
    /* 1C710C 002C710C 790046A0 */  sb         $6, 0x79($2)
    /* 1C7110 002C7110 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C7114 002C7114 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C7118 002C7118 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C711C 002C711C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1C7120 002C7120 00608244 */  mtc1       $2, $f12
    /* 1C7124 002C7124 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C7128 002C7128 46630046 */  mov.s      $f13, $f12
    /* 1C712C 002C712C 70818EC7 */  lwc1       $f14, -0x7E90($28)
    /* 1C7130 002C7130 C6630046 */  mov.s      $f15, $f12
    /* 1C7134 002C7134 02000524 */  addiu      $5, $0, 0x2
    /* 1C7138 002C7138 04000624 */  addiu      $6, $0, 0x4
    /* 1C713C 002C713C 2D380000 */  daddu      $7, $0, $0
    /* 1C7140 002C7140 B4810B0C */  jal        func_002e06d0
    /* 1C7144 002C7144 00000000 */   nop
    /* 1C7148 002C7148 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C714C 002C714C 2D280000 */  daddu      $5, $0, $0
    /* 1C7150 002C7150 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C7154 002C7154 2D380000 */  daddu      $7, $0, $0
    /* 1C7158 002C7158 04000824 */  addiu      $8, $0, 0x4
    /* 1C715C 002C715C 2D480000 */  daddu      $9, $0, $0
    /* 1C7160 002C7160 98810B0C */  jal        func_002e0660
    /* 1C7164 002C7164 00000000 */   nop
    /* 1C7168 002C7168 2D200002 */  daddu      $4, $16, $0
    /* 1C716C 002C716C BCAC110C */  jal        func_0046b2f0
    /* 1C7170 002C7170 00000000 */   nop
    /* 1C7174 002C7174 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1C7178 002C7178 00088244 */  mtc1       $2, $f1
    /* 1C717C 002C717C 00000000 */  nop
    /* 1C7180 002C7180 C3000146 */  div.s      $f3, $f0, $f1
    /* 1C7184 002C7184 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1C7188 002C7188 00108244 */  mtc1       $2, $f2
    /* 1C718C 002C718C FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1C7190 002C7190 00088244 */  mtc1       $2, $f1
    /* 1C7194 002C7194 00008044 */  mtc1       $0, $f0
    /* 1C7198 002C7198 00000000 */  nop
    /* 1C719C 002C719C 18000146 */  adda.s     $f0, $f1
    /* 1C71A0 002C71A0 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C71A4 002C71A4 1244023C */  lui        $2, (0x44120000 >> 16)
    /* 1C71A8 002C71A8 00608244 */  mtc1       $2, $f12
    /* 1C71AC 002C71AC B802A427 */  addiu      $4, $29, 0x2B8
    /* 1C71B0 002C71B0 5CCA0A0C */  jal        func_002b2970
    /* 1C71B4 002C71B4 00000000 */   nop
    /* 1C71B8 002C71B8 1244023C */  lui        $2, (0x44120000 >> 16)
    /* 1C71BC 002C71BC 00608244 */  mtc1       $2, $f12
    /* 1C71C0 002C71C0 FE42023C */  lui        $2, (0x42FE0000 >> 16)
    /* 1C71C4 002C71C4 00688244 */  mtc1       $2, $f13
    /* 1C71C8 002C71C8 B002A427 */  addiu      $4, $29, 0x2B0
    /* 1C71CC 002C71CC 5CCA0A0C */  jal        func_002b2970
    /* 1C71D0 002C71D0 00000000 */   nop
    /* 1C71D4 002C71D4 DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C71D8 002C71D8 B802A5DF */  ld         $5, 0x2B8($29)
    /* 1C71DC 002C71DC B002A6DF */  ld         $6, 0x2B0($29)
    /* 1C71E0 002C71E0 02000724 */  addiu      $7, $0, 0x2
    /* 1C71E4 002C71E4 04000824 */  addiu      $8, $0, 0x4
    /* 1C71E8 002C71E8 2D480000 */  daddu      $9, $0, $0
    /* 1C71EC 002C71EC 88810B0C */  jal        func_002e0620
    /* 1C71F0 002C71F0 00000000 */   nop
    /* 1C71F4 002C71F4 C040023C */  lui        $2, (0x40C00000 >> 16)
    /* 1C71F8 002C71F8 00608244 */  mtc1       $2, $f12
    /* 1C71FC 002C71FC DC0C248E */  lw         $4, 0xCDC($17)
    /* 1C7200 002C7200 03000524 */  addiu      $5, $0, 0x3
    /* 1C7204 002C7204 6C820B0C */  jal        func_002e09b0
    /* 1C7208 002C7208 00000000 */   nop
    /* 1C720C 002C720C 2D200002 */  daddu      $4, $16, $0
    /* 1C7210 002C7210 A0B4110C */  jal        func_0046d280
    /* 1C7214 002C7214 00000000 */   nop
  .L002C7218:
    /* 1C7218 002C7218 6400103C */  lui        $16, %hi(D_0063F688)
    /* 1C721C 002C721C 88F61026 */  addiu      $16, $16, %lo(D_0063F688)
    /* 1C7220 002C7220 6041023C */  lui        $2, (0x41600000 >> 16)
    /* 1C7224 002C7224 00608244 */  mtc1       $2, $f12
    /* 1C7228 002C7228 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C722C 002C722C 57000524 */  addiu      $5, $0, 0x57
    /* 1C7230 002C7230 78820B0C */  jal        func_002e09e0
    /* 1C7234 002C7234 00000000 */   nop
    /* 1C7238 002C7238 A802A427 */  addiu      $4, $29, 0x2A8
    /* 1C723C 002C723C 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C7240 002C7240 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C7244 002C7244 5CCA0A0C */  jal        func_002b2970
    /* 1C7248 002C7248 00000000 */   nop
    /* 1C724C 002C724C 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C7250 002C7250 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1C7254 002C7254 00008244 */  mtc1       $2, $f0
    /* 1C7258 002C7258 00000000 */  nop
    /* 1C725C 002C725C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C7260 002C7260 A002A427 */  addiu      $4, $29, 0x2A0
    /* 1C7264 002C7264 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C7268 002C7268 5CCA0A0C */  jal        func_002b2970
    /* 1C726C 002C726C 00000000 */   nop
    /* 1C7270 002C7270 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C7274 002C7274 A802A5DF */  ld         $5, 0x2A8($29)
    /* 1C7278 002C7278 A002A6DF */  ld         $6, 0x2A0($29)
    /* 1C727C 002C727C 01000724 */  addiu      $7, $0, 0x1
    /* 1C7280 002C7280 0A000824 */  addiu      $8, $0, 0xA
    /* 1C7284 002C7284 02000924 */  addiu      $9, $0, 0x2
    /* 1C7288 002C7288 88810B0C */  jal        func_002e0620
    /* 1C728C 002C728C 00000000 */   nop
    /* 1C7290 002C7290 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C7294 002C7294 2D280000 */  daddu      $5, $0, $0
    /* 1C7298 002C7298 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C729C 002C729C 2D380000 */  daddu      $7, $0, $0
    /* 1C72A0 002C72A0 0A000824 */  addiu      $8, $0, 0xA
    /* 1C72A4 002C72A4 02000924 */  addiu      $9, $0, 0x2
    /* 1C72A8 002C72A8 98810B0C */  jal        func_002e0660
    /* 1C72AC 002C72AC 00000000 */   nop
    /* 1C72B0 002C72B0 01001024 */  addiu      $16, $0, 0x1
    /* 1C72B4 002C72B4 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C72B8 002C72B8 38810B0C */  jal        func_002e04e0
    /* 1C72BC 002C72BC 00000000 */   nop
    /* 1C72C0 002C72C0 3B0050A0 */  sb         $16, 0x3B($2)
    /* 1C72C4 002C72C4 D406A427 */  addiu      $4, $29, 0x6D4
    /* 1C72C8 002C72C8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C72CC 002C72CC 96000624 */  addiu      $6, $0, 0x96
    /* 1C72D0 002C72D0 2D380000 */  daddu      $7, $0, $0
    /* 1C72D4 002C72D4 2D40A000 */  daddu      $8, $5, $0
    /* 1C72D8 002C72D8 98CA0A0C */  jal        func_002b2a60
    /* 1C72DC 002C72DC 00000000 */   nop
    /* 1C72E0 002C72E0 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C72E4 002C72E4 38810B0C */  jal        func_002e04e0
    /* 1C72E8 002C72E8 00000000 */   nop
    /* 1C72EC 002C72EC D406A693 */  lbu        $6, 0x6D4($29)
    /* 1C72F0 002C72F0 D506A593 */  lbu        $5, 0x6D5($29)
    /* 1C72F4 002C72F4 D606A493 */  lbu        $4, 0x6D6($29)
    /* 1C72F8 002C72F8 D706A393 */  lbu        $3, 0x6D7($29)
    /* 1C72FC 002C72FC 790046A0 */  sb         $6, 0x79($2)
    /* 1C7300 002C7300 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C7304 002C7304 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C7308 002C7308 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C730C 002C730C CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C7310 002C7310 38810B0C */  jal        func_002e04e0
    /* 1C7314 002C7314 00000000 */   nop
    /* 1C7318 002C7318 850050A0 */  sb         $16, 0x85($2)
    /* 1C731C 002C731C 6400103C */  lui        $16, %hi(D_0063F690)
    /* 1C7320 002C7320 90F61026 */  addiu      $16, $16, %lo(D_0063F690)
    /* 1C7324 002C7324 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 1C7328 002C7328 00608244 */  mtc1       $2, $f12
    /* 1C732C 002C732C D00C248E */  lw         $4, 0xCD0($17)
    /* 1C7330 002C7330 57000524 */  addiu      $5, $0, 0x57
    /* 1C7334 002C7334 78820B0C */  jal        func_002e09e0
    /* 1C7338 002C7338 00000000 */   nop
    /* 1C733C 002C733C 9802A427 */  addiu      $4, $29, 0x298
    /* 1C7340 002C7340 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C7344 002C7344 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C7348 002C7348 5CCA0A0C */  jal        func_002b2970
    /* 1C734C 002C734C 00000000 */   nop
    /* 1C7350 002C7350 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C7354 002C7354 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1C7358 002C7358 00008244 */  mtc1       $2, $f0
    /* 1C735C 002C735C 00000000 */  nop
    /* 1C7360 002C7360 40030146 */  add.s      $f13, $f0, $f1
    /* 1C7364 002C7364 9002A427 */  addiu      $4, $29, 0x290
    /* 1C7368 002C7368 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C736C 002C736C 5CCA0A0C */  jal        func_002b2970
    /* 1C7370 002C7370 00000000 */   nop
    /* 1C7374 002C7374 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C7378 002C7378 9802A5DF */  ld         $5, 0x298($29)
    /* 1C737C 002C737C 9002A6DF */  ld         $6, 0x290($29)
    /* 1C7380 002C7380 01000724 */  addiu      $7, $0, 0x1
    /* 1C7384 002C7384 0A000824 */  addiu      $8, $0, 0xA
    /* 1C7388 002C7388 02000924 */  addiu      $9, $0, 0x2
    /* 1C738C 002C738C 88810B0C */  jal        func_002e0620
    /* 1C7390 002C7390 00000000 */   nop
    /* 1C7394 002C7394 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C7398 002C7398 2D280000 */  daddu      $5, $0, $0
    /* 1C739C 002C739C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C73A0 002C73A0 2D380000 */  daddu      $7, $0, $0
    /* 1C73A4 002C73A4 0A000824 */  addiu      $8, $0, 0xA
    /* 1C73A8 002C73A8 02000924 */  addiu      $9, $0, 0x2
    /* 1C73AC 002C73AC 98810B0C */  jal        func_002e0660
    /* 1C73B0 002C73B0 00000000 */   nop
    /* 1C73B4 002C73B4 01001024 */  addiu      $16, $0, 0x1
    /* 1C73B8 002C73B8 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C73BC 002C73BC 38810B0C */  jal        func_002e04e0
    /* 1C73C0 002C73C0 00000000 */   nop
    /* 1C73C4 002C73C4 3B0050A0 */  sb         $16, 0x3B($2)
    /* 1C73C8 002C73C8 D006A427 */  addiu      $4, $29, 0x6D0
    /* 1C73CC 002C73CC FF000524 */  addiu      $5, $0, 0xFF
    /* 1C73D0 002C73D0 96000624 */  addiu      $6, $0, 0x96
    /* 1C73D4 002C73D4 2D380000 */  daddu      $7, $0, $0
    /* 1C73D8 002C73D8 2D40A000 */  daddu      $8, $5, $0
    /* 1C73DC 002C73DC 98CA0A0C */  jal        func_002b2a60
    /* 1C73E0 002C73E0 00000000 */   nop
    /* 1C73E4 002C73E4 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C73E8 002C73E8 38810B0C */  jal        func_002e04e0
    /* 1C73EC 002C73EC 00000000 */   nop
    /* 1C73F0 002C73F0 D006A693 */  lbu        $6, 0x6D0($29)
    /* 1C73F4 002C73F4 D106A593 */  lbu        $5, 0x6D1($29)
    /* 1C73F8 002C73F8 D206A493 */  lbu        $4, 0x6D2($29)
    /* 1C73FC 002C73FC D306A393 */  lbu        $3, 0x6D3($29)
    /* 1C7400 002C7400 790046A0 */  sb         $6, 0x79($2)
    /* 1C7404 002C7404 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C7408 002C7408 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C740C 002C740C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C7410 002C7410 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C7414 002C7414 38810B0C */  jal        func_002e04e0
    /* 1C7418 002C7418 00000000 */   nop
    /* 1C741C 002C741C 850050A0 */  sb         $16, 0x85($2)
    /* 1C7420 002C7420 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 1C7424 002C7424 00608244 */  mtc1       $2, $f12
    /* 1C7428 002C7428 C80C248E */  lw         $4, 0xCC8($17)
    /* 1C742C 002C742C 57000524 */  addiu      $5, $0, 0x57
    /* 1C7430 002C7430 78820B0C */  jal        func_002e09e0
    /* 1C7434 002C7434 00000000 */   nop
    /* 1C7438 002C7438 CC06A427 */  addiu      $4, $29, 0x6CC
    /* 1C743C 002C743C DF000524 */  addiu      $5, $0, 0xDF
    /* 1C7440 002C7440 6C000624 */  addiu      $6, $0, 0x6C
    /* 1C7444 002C7444 2D380000 */  daddu      $7, $0, $0
    /* 1C7448 002C7448 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C744C 002C744C 98CA0A0C */  jal        func_002b2a60
    /* 1C7450 002C7450 00000000 */   nop
    /* 1C7454 002C7454 C80C248E */  lw         $4, 0xCC8($17)
    /* 1C7458 002C7458 38810B0C */  jal        func_002e04e0
    /* 1C745C 002C745C 00000000 */   nop
    /* 1C7460 002C7460 CC06A693 */  lbu        $6, 0x6CC($29)
    /* 1C7464 002C7464 CD06A593 */  lbu        $5, 0x6CD($29)
    /* 1C7468 002C7468 CE06A493 */  lbu        $4, 0x6CE($29)
    /* 1C746C 002C746C CF06A393 */  lbu        $3, 0x6CF($29)
    /* 1C7470 002C7470 790046A0 */  sb         $6, 0x79($2)
    /* 1C7474 002C7474 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C7478 002C7478 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C747C 002C747C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C7480 002C7480 C80C248E */  lw         $4, 0xCC8($17)
    /* 1C7484 002C7484 2D280000 */  daddu      $5, $0, $0
    /* 1C7488 002C7488 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C748C 002C748C 2D380000 */  daddu      $7, $0, $0
    /* 1C7490 002C7490 04000824 */  addiu      $8, $0, 0x4
    /* 1C7494 002C7494 02000924 */  addiu      $9, $0, 0x2
    /* 1C7498 002C7498 98810B0C */  jal        func_002e0660
    /* 1C749C 002C749C 00000000 */   nop
    /* 1C74A0 002C74A0 27000224 */  addiu      $2, $0, 0x27
    /* 1C74A4 002C74A4 000022A2 */  sb         $2, 0x0($17)
    /* 1C74A8 002C74A8 9F0C0010 */  b          .L002CA728
    /* 1C74AC 002C74AC 00000000 */   nop
    /* 1C74B0 002C74B0 11002282 */  lb         $2, 0x11($17)
    /* 1C74B4 002C74B4 80100200 */  sll        $2, $2, 2
    /* 1C74B8 002C74B8 21105100 */  addu       $2, $2, $17
    /* 1C74BC 002C74BC 02002586 */  lh         $5, 0x2($17)
    /* 1C74C0 002C74C0 180F448C */  lw         $4, 0xF18($2)
    /* 1C74C4 002C74C4 0C8A0B0C */  jal        func_002e2830
    /* 1C74C8 002C74C8 00000000 */   nop
    /* 1C74CC 002C74CC 3C840200 */  dsll32     $16, $2, 16
    /* 1C74D0 002C74D0 3F841000 */  dsra32     $16, $16, 16
    /* 1C74D4 002C74D4 11002282 */  lb         $2, 0x11($17)
    /* 1C74D8 002C74D8 80100200 */  sll        $2, $2, 2
    /* 1C74DC 002C74DC 21105100 */  addu       $2, $2, $17
    /* 1C74E0 002C74E0 02002586 */  lh         $5, 0x2($17)
    /* 1C74E4 002C74E4 180F448C */  lw         $4, 0xF18($2)
    /* 1C74E8 002C74E8 3C8A0B0C */  jal        func_002e28f0
    /* 1C74EC 002C74EC 00000000 */   nop
    /* 1C74F0 002C74F0 FF005230 */  andi       $18, $2, 0xFF
    /* 1C74F4 002C74F4 2D208002 */  daddu      $4, $20, $0
    /* 1C74F8 002C74F8 02000524 */  addiu      $5, $0, 0x2
    /* 1C74FC 002C74FC E0370B0C */  jal        func_002cdf80
    /* 1C7500 002C7500 00000000 */   nop
    /* 1C7504 002C7504 2D208002 */  daddu      $4, $20, $0
    /* 1C7508 002C7508 2D280002 */  daddu      $5, $16, $0
    /* 1C750C 002C750C 2D304002 */  daddu      $6, $18, $0
    /* 1C7510 002C7510 087C0B0C */  jal        func_002df020
    /* 1C7514 002C7514 00000000 */   nop
    /* 1C7518 002C7518 2D208002 */  daddu      $4, $20, $0
    /* 1C751C 002C751C EC740B0C */  jal        func_002dd3b0
    /* 1C7520 002C7520 00000000 */   nop
    /* 1C7524 002C7524 8C00023C */  lui        $2, %hi(D_008C027A)
    /* 1C7528 002C7528 7A024394 */  lhu        $3, %lo(D_008C027A)($2)
    /* 1C752C 002C752C 00106230 */  andi       $2, $3, 0x1000
    /* 1C7530 002C7530 38004010 */  beqz       $2, .L002C7614
    /* 1C7534 002C7534 00000000 */   nop
    /* 1C7538 002C7538 12003286 */  lh         $18, 0x12($17)
    /* 1C753C 002C753C 2D200002 */  daddu      $4, $16, $0
    /* 1C7540 002C7540 8019040C */  jal        func_00106600
    /* 1C7544 002C7544 00000000 */   nop
    /* 1C7548 002C7548 FF004230 */  andi       $2, $2, 0xFF
    /* 1C754C 002C754C 07004212 */  beq        $18, $2, .L002C756C
    /* 1C7550 002C7550 00000000 */   nop
    /* 1C7554 002C7554 2D200000 */  daddu      $4, $0, $0
    /* 1C7558 002C7558 2D280000 */  daddu      $5, $0, $0
    /* 1C755C 002C755C 2D300000 */  daddu      $6, $0, $0
    /* 1C7560 002C7560 2D380000 */  daddu      $7, $0, $0
    /* 1C7564 002C7564 D86B110C */  jal        func_0045af60
    /* 1C7568 002C7568 00000000 */   nop
  .L002C756C:
    /* 1C756C 002C756C 2D200002 */  daddu      $4, $16, $0
    /* 1C7570 002C7570 8019040C */  jal        func_00106600
    /* 1C7574 002C7574 00000000 */   nop
    /* 1C7578 002C7578 FF004630 */  andi       $6, $2, 0xFF
    /* 1C757C 002C757C 12002486 */  lh         $4, 0x12($17)
    /* 1C7580 002C7580 01000524 */  addiu      $5, $0, 0x1
    /* 1C7584 002C7584 2D38A000 */  daddu      $7, $5, $0
    /* 1C7588 002C7588 2D40A000 */  daddu      $8, $5, $0
    /* 1C758C 002C758C 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7590 002C7590 00000000 */   nop
    /* 1C7594 002C7594 120022A6 */  sh         $2, 0x12($17)
    /* 1C7598 002C7598 6400103C */  lui        $16, %hi(D_0063F688)
    /* 1C759C 002C759C 88F61026 */  addiu      $16, $16, %lo(D_0063F688)
    /* 1C75A0 002C75A0 8802A427 */  addiu      $4, $29, 0x288
    /* 1C75A4 002C75A4 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C75A8 002C75A8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C75AC 002C75AC 5CCA0A0C */  jal        func_002b2970
    /* 1C75B0 002C75B0 00000000 */   nop
    /* 1C75B4 002C75B4 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C75B8 002C75B8 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1C75BC 002C75BC 00008244 */  mtc1       $2, $f0
    /* 1C75C0 002C75C0 00000000 */  nop
    /* 1C75C4 002C75C4 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C75C8 002C75C8 8002A427 */  addiu      $4, $29, 0x280
    /* 1C75CC 002C75CC 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C75D0 002C75D0 5CCA0A0C */  jal        func_002b2970
    /* 1C75D4 002C75D4 00000000 */   nop
    /* 1C75D8 002C75D8 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C75DC 002C75DC 8802A5DF */  ld         $5, 0x288($29)
    /* 1C75E0 002C75E0 8002A6DF */  ld         $6, 0x280($29)
    /* 1C75E4 002C75E4 01000724 */  addiu      $7, $0, 0x1
    /* 1C75E8 002C75E8 0A000824 */  addiu      $8, $0, 0xA
    /* 1C75EC 002C75EC 2D480000 */  daddu      $9, $0, $0
    /* 1C75F0 002C75F0 88810B0C */  jal        func_002e0620
    /* 1C75F4 002C75F4 00000000 */   nop
    /* 1C75F8 002C75F8 01001024 */  addiu      $16, $0, 0x1
    /* 1C75FC 002C75FC CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C7600 002C7600 38810B0C */  jal        func_002e04e0
    /* 1C7604 002C7604 00000000 */   nop
    /* 1C7608 002C7608 850050A0 */  sb         $16, 0x85($2)
    /* 1C760C 002C760C 460C0010 */  b          .L002CA728
    /* 1C7610 002C7610 00000000 */   nop
  .L002C7614:
    /* 1C7614 002C7614 00206230 */  andi       $2, $3, 0x2000
    /* 1C7618 002C7618 38004010 */  beqz       $2, .L002C76FC
    /* 1C761C 002C761C 00000000 */   nop
    /* 1C7620 002C7620 12003286 */  lh         $18, 0x12($17)
    /* 1C7624 002C7624 2D200002 */  daddu      $4, $16, $0
    /* 1C7628 002C7628 8019040C */  jal        func_00106600
    /* 1C762C 002C762C 00000000 */   nop
    /* 1C7630 002C7630 FF004230 */  andi       $2, $2, 0xFF
    /* 1C7634 002C7634 07004212 */  beq        $18, $2, .L002C7654
    /* 1C7638 002C7638 00000000 */   nop
    /* 1C763C 002C763C 2D200000 */  daddu      $4, $0, $0
    /* 1C7640 002C7640 2D280000 */  daddu      $5, $0, $0
    /* 1C7644 002C7644 2D300000 */  daddu      $6, $0, $0
    /* 1C7648 002C7648 2D380000 */  daddu      $7, $0, $0
    /* 1C764C 002C764C D86B110C */  jal        func_0045af60
    /* 1C7650 002C7650 00000000 */   nop
  .L002C7654:
    /* 1C7654 002C7654 2D200002 */  daddu      $4, $16, $0
    /* 1C7658 002C7658 8019040C */  jal        func_00106600
    /* 1C765C 002C765C 00000000 */   nop
    /* 1C7660 002C7660 FF004630 */  andi       $6, $2, 0xFF
    /* 1C7664 002C7664 12002486 */  lh         $4, 0x12($17)
    /* 1C7668 002C7668 0A000524 */  addiu      $5, $0, 0xA
    /* 1C766C 002C766C 01000724 */  addiu      $7, $0, 0x1
    /* 1C7670 002C7670 2D40E000 */  daddu      $8, $7, $0
    /* 1C7674 002C7674 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7678 002C7678 00000000 */   nop
    /* 1C767C 002C767C 120022A6 */  sh         $2, 0x12($17)
    /* 1C7680 002C7680 6400103C */  lui        $16, %hi(D_0063F688)
    /* 1C7684 002C7684 88F61026 */  addiu      $16, $16, %lo(D_0063F688)
    /* 1C7688 002C7688 7802A427 */  addiu      $4, $29, 0x278
    /* 1C768C 002C768C 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C7690 002C7690 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C7694 002C7694 5CCA0A0C */  jal        func_002b2970
    /* 1C7698 002C7698 00000000 */   nop
    /* 1C769C 002C769C 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C76A0 002C76A0 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1C76A4 002C76A4 00008244 */  mtc1       $2, $f0
    /* 1C76A8 002C76A8 00000000 */  nop
    /* 1C76AC 002C76AC 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1C76B0 002C76B0 7002A427 */  addiu      $4, $29, 0x270
    /* 1C76B4 002C76B4 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C76B8 002C76B8 5CCA0A0C */  jal        func_002b2970
    /* 1C76BC 002C76BC 00000000 */   nop
    /* 1C76C0 002C76C0 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C76C4 002C76C4 7802A5DF */  ld         $5, 0x278($29)
    /* 1C76C8 002C76C8 7002A6DF */  ld         $6, 0x270($29)
    /* 1C76CC 002C76CC 01000724 */  addiu      $7, $0, 0x1
    /* 1C76D0 002C76D0 0A000824 */  addiu      $8, $0, 0xA
    /* 1C76D4 002C76D4 2D480000 */  daddu      $9, $0, $0
    /* 1C76D8 002C76D8 88810B0C */  jal        func_002e0620
    /* 1C76DC 002C76DC 00000000 */   nop
    /* 1C76E0 002C76E0 01001024 */  addiu      $16, $0, 0x1
    /* 1C76E4 002C76E4 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C76E8 002C76E8 38810B0C */  jal        func_002e04e0
    /* 1C76EC 002C76EC 00000000 */   nop
    /* 1C76F0 002C76F0 850050A0 */  sb         $16, 0x85($2)
    /* 1C76F4 002C76F4 0C0C0010 */  b          .L002CA728
    /* 1C76F8 002C76F8 00000000 */   nop
  .L002C76FC:
    /* 1C76FC 002C76FC 00406230 */  andi       $2, $3, 0x4000
    /* 1C7700 002C7700 35004010 */  beqz       $2, .L002C77D8
    /* 1C7704 002C7704 00000000 */   nop
    /* 1C7708 002C7708 12002386 */  lh         $3, 0x12($17)
    /* 1C770C 002C770C 01000224 */  addiu      $2, $0, 0x1
    /* 1C7710 002C7710 07006210 */  beq        $3, $2, .L002C7730
    /* 1C7714 002C7714 00000000 */   nop
    /* 1C7718 002C7718 2D200000 */  daddu      $4, $0, $0
    /* 1C771C 002C771C 2D280000 */  daddu      $5, $0, $0
    /* 1C7720 002C7720 2D300000 */  daddu      $6, $0, $0
    /* 1C7724 002C7724 2D380000 */  daddu      $7, $0, $0
    /* 1C7728 002C7728 D86B110C */  jal        func_0045af60
    /* 1C772C 002C772C 00000000 */   nop
  .L002C7730:
    /* 1C7730 002C7730 2D200002 */  daddu      $4, $16, $0
    /* 1C7734 002C7734 8019040C */  jal        func_00106600
    /* 1C7738 002C7738 00000000 */   nop
    /* 1C773C 002C773C FF004730 */  andi       $7, $2, 0xFF
    /* 1C7740 002C7740 12002486 */  lh         $4, 0x12($17)
    /* 1C7744 002C7744 01000524 */  addiu      $5, $0, 0x1
    /* 1C7748 002C7748 2D30A000 */  daddu      $6, $5, $0
    /* 1C774C 002C774C 2D40A000 */  daddu      $8, $5, $0
    /* 1C7750 002C7750 40CB0A0C */  jal        func_002b2d00
    /* 1C7754 002C7754 00000000 */   nop
    /* 1C7758 002C7758 120022A6 */  sh         $2, 0x12($17)
    /* 1C775C 002C775C 6400103C */  lui        $16, %hi(D_0063F690)
    /* 1C7760 002C7760 90F61026 */  addiu      $16, $16, %lo(D_0063F690)
    /* 1C7764 002C7764 6802A427 */  addiu      $4, $29, 0x268
    /* 1C7768 002C7768 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C776C 002C776C 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C7770 002C7770 5CCA0A0C */  jal        func_002b2970
    /* 1C7774 002C7774 00000000 */   nop
    /* 1C7778 002C7778 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C777C 002C777C E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1C7780 002C7780 00008244 */  mtc1       $2, $f0
    /* 1C7784 002C7784 00000000 */  nop
    /* 1C7788 002C7788 40030146 */  add.s      $f13, $f0, $f1
    /* 1C778C 002C778C 6002A427 */  addiu      $4, $29, 0x260
    /* 1C7790 002C7790 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C7794 002C7794 5CCA0A0C */  jal        func_002b2970
    /* 1C7798 002C7798 00000000 */   nop
    /* 1C779C 002C779C D00C248E */  lw         $4, 0xCD0($17)
    /* 1C77A0 002C77A0 6802A5DF */  ld         $5, 0x268($29)
    /* 1C77A4 002C77A4 6002A6DF */  ld         $6, 0x260($29)
    /* 1C77A8 002C77A8 01000724 */  addiu      $7, $0, 0x1
    /* 1C77AC 002C77AC 0A000824 */  addiu      $8, $0, 0xA
    /* 1C77B0 002C77B0 2D480000 */  daddu      $9, $0, $0
    /* 1C77B4 002C77B4 88810B0C */  jal        func_002e0620
    /* 1C77B8 002C77B8 00000000 */   nop
    /* 1C77BC 002C77BC 01001024 */  addiu      $16, $0, 0x1
    /* 1C77C0 002C77C0 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C77C4 002C77C4 38810B0C */  jal        func_002e04e0
    /* 1C77C8 002C77C8 00000000 */   nop
    /* 1C77CC 002C77CC 850050A0 */  sb         $16, 0x85($2)
    /* 1C77D0 002C77D0 D50B0010 */  b          .L002CA728
    /* 1C77D4 002C77D4 00000000 */   nop
  .L002C77D8:
    /* 1C77D8 002C77D8 00806230 */  andi       $2, $3, 0x8000
    /* 1C77DC 002C77DC 35004010 */  beqz       $2, .L002C78B4
    /* 1C77E0 002C77E0 00000000 */   nop
    /* 1C77E4 002C77E4 12002386 */  lh         $3, 0x12($17)
    /* 1C77E8 002C77E8 01000224 */  addiu      $2, $0, 0x1
    /* 1C77EC 002C77EC 07006210 */  beq        $3, $2, .L002C780C
    /* 1C77F0 002C77F0 00000000 */   nop
    /* 1C77F4 002C77F4 2D200000 */  daddu      $4, $0, $0
    /* 1C77F8 002C77F8 2D280000 */  daddu      $5, $0, $0
    /* 1C77FC 002C77FC 2D300000 */  daddu      $6, $0, $0
    /* 1C7800 002C7800 2D380000 */  daddu      $7, $0, $0
    /* 1C7804 002C7804 D86B110C */  jal        func_0045af60
    /* 1C7808 002C7808 00000000 */   nop
  .L002C780C:
    /* 1C780C 002C780C 2D200002 */  daddu      $4, $16, $0
    /* 1C7810 002C7810 8019040C */  jal        func_00106600
    /* 1C7814 002C7814 00000000 */   nop
    /* 1C7818 002C7818 FF004730 */  andi       $7, $2, 0xFF
    /* 1C781C 002C781C 12002486 */  lh         $4, 0x12($17)
    /* 1C7820 002C7820 0A000524 */  addiu      $5, $0, 0xA
    /* 1C7824 002C7824 01000624 */  addiu      $6, $0, 0x1
    /* 1C7828 002C7828 2D40C000 */  daddu      $8, $6, $0
    /* 1C782C 002C782C 40CB0A0C */  jal        func_002b2d00
    /* 1C7830 002C7830 00000000 */   nop
    /* 1C7834 002C7834 120022A6 */  sh         $2, 0x12($17)
    /* 1C7838 002C7838 6400103C */  lui        $16, %hi(D_0063F690)
    /* 1C783C 002C783C 90F61026 */  addiu      $16, $16, %lo(D_0063F690)
    /* 1C7840 002C7840 5802A427 */  addiu      $4, $29, 0x258
    /* 1C7844 002C7844 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C7848 002C7848 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1C784C 002C784C 5CCA0A0C */  jal        func_002b2970
    /* 1C7850 002C7850 00000000 */   nop
    /* 1C7854 002C7854 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1C7858 002C7858 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1C785C 002C785C 00008244 */  mtc1       $2, $f0
    /* 1C7860 002C7860 00000000 */  nop
    /* 1C7864 002C7864 40030146 */  add.s      $f13, $f0, $f1
    /* 1C7868 002C7868 5002A427 */  addiu      $4, $29, 0x250
    /* 1C786C 002C786C 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C7870 002C7870 5CCA0A0C */  jal        func_002b2970
    /* 1C7874 002C7874 00000000 */   nop
    /* 1C7878 002C7878 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C787C 002C787C 5802A5DF */  ld         $5, 0x258($29)
    /* 1C7880 002C7880 5002A6DF */  ld         $6, 0x250($29)
    /* 1C7884 002C7884 01000724 */  addiu      $7, $0, 0x1
    /* 1C7888 002C7888 0A000824 */  addiu      $8, $0, 0xA
    /* 1C788C 002C788C 2D480000 */  daddu      $9, $0, $0
    /* 1C7890 002C7890 88810B0C */  jal        func_002e0620
    /* 1C7894 002C7894 00000000 */   nop
    /* 1C7898 002C7898 01001024 */  addiu      $16, $0, 0x1
    /* 1C789C 002C789C D00C248E */  lw         $4, 0xCD0($17)
    /* 1C78A0 002C78A0 38810B0C */  jal        func_002e04e0
    /* 1C78A4 002C78A4 00000000 */   nop
    /* 1C78A8 002C78A8 850050A0 */  sb         $16, 0x85($2)
    /* 1C78AC 002C78AC 9E0B0010 */  b          .L002CA728
    /* 1C78B0 002C78B0 00000000 */   nop
  .L002C78B4:
    /* 1C78B4 002C78B4 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 1C78B8 002C78B8 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 1C78BC 002C78BC 40006230 */  andi       $2, $3, 0x40
    /* 1C78C0 002C78C0 1C004010 */  beqz       $2, .L002C7934
    /* 1C78C4 002C78C4 00000000 */   nop
    /* 1C78C8 002C78C8 3C141000 */  dsll32     $2, $16, 16
    /* 1C78CC 002C78CC 3F140200 */  dsra32     $2, $2, 16
    /* 1C78D0 002C78D0 7806A2AF */  sw         $2, 0x678($29)
    /* 1C78D4 002C78D4 7C06A0AF */  sw         $0, 0x67C($29)
    /* 1C78D8 002C78D8 12002686 */  lh         $6, 0x12($17)
    /* 1C78DC 002C78DC C000A427 */  addiu      $4, $29, 0xC0
    /* 1C78E0 002C78E0 80A88527 */  addiu      $5, $28, -0x5780
    /* 1C78E4 002C78E4 2208110C */  jal        func_00442088
    /* 1C78E8 002C78E8 00000000 */   nop
    /* 1C78EC 002C78EC 2D208002 */  daddu      $4, $20, $0
    /* 1C78F0 002C78F0 02000524 */  addiu      $5, $0, 0x2
    /* 1C78F4 002C78F4 7806A627 */  addiu      $6, $29, 0x678
    /* 1C78F8 002C78F8 C000A727 */  addiu      $7, $29, 0xC0
    /* 1C78FC 002C78FC 01000824 */  addiu      $8, $0, 0x1
    /* 1C7900 002C7900 E47F0B0C */  jal        func_002dff90
    /* 1C7904 002C7904 00000000 */   nop
    /* 1C7908 002C7908 100022A2 */  sb         $2, 0x10($17)
    /* 1C790C 002C790C 28000224 */  addiu      $2, $0, 0x28
    /* 1C7910 002C7910 000022A2 */  sb         $2, 0x0($17)
    /* 1C7914 002C7914 2D200000 */  daddu      $4, $0, $0
    /* 1C7918 002C7918 2D280000 */  daddu      $5, $0, $0
    /* 1C791C 002C791C 2D300000 */  daddu      $6, $0, $0
    /* 1C7920 002C7920 01000724 */  addiu      $7, $0, 0x1
    /* 1C7924 002C7924 D86B110C */  jal        func_0045af60
    /* 1C7928 002C7928 00000000 */   nop
    /* 1C792C 002C792C 7E0B0010 */  b          .L002CA728
    /* 1C7930 002C7930 00000000 */   nop
  .L002C7934:
    /* 1C7934 002C7934 20006230 */  andi       $2, $3, 0x20
    /* 1C7938 002C7938 7B0B4010 */  beqz       $2, .L002CA728
    /* 1C793C 002C793C 00000000 */   nop
    /* 1C7940 002C7940 2D200000 */  daddu      $4, $0, $0
    /* 1C7944 002C7944 2D280000 */  daddu      $5, $0, $0
    /* 1C7948 002C7948 2D300000 */  daddu      $6, $0, $0
    /* 1C794C 002C794C 02000724 */  addiu      $7, $0, 0x2
    /* 1C7950 002C7950 D86B110C */  jal        func_0045af60
    /* 1C7954 002C7954 00000000 */   nop
    /* 1C7958 002C7958 2D208002 */  daddu      $4, $20, $0
    /* 1C795C 002C795C 307D0B0C */  jal        func_002df4c0
    /* 1C7960 002C7960 00000000 */   nop
    /* 1C7964 002C7964 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C7968 002C7968 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C796C 002C796C 2D300000 */  daddu      $6, $0, $0
    /* 1C7970 002C7970 2D380000 */  daddu      $7, $0, $0
    /* 1C7974 002C7974 05000824 */  addiu      $8, $0, 0x5
    /* 1C7978 002C7978 2D480000 */  daddu      $9, $0, $0
    /* 1C797C 002C797C 98810B0C */  jal        func_002e0660
    /* 1C7980 002C7980 00000000 */   nop
    /* 1C7984 002C7984 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C7988 002C7988 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C798C 002C798C 2D300000 */  daddu      $6, $0, $0
    /* 1C7990 002C7990 2D380000 */  daddu      $7, $0, $0
    /* 1C7994 002C7994 05000824 */  addiu      $8, $0, 0x5
    /* 1C7998 002C7998 2D480000 */  daddu      $9, $0, $0
    /* 1C799C 002C799C 98810B0C */  jal        func_002e0660
    /* 1C79A0 002C79A0 00000000 */   nop
    /* 1C79A4 002C79A4 C80C248E */  lw         $4, 0xCC8($17)
    /* 1C79A8 002C79A8 2D280000 */  daddu      $5, $0, $0
    /* 1C79AC 002C79AC 01000624 */  addiu      $6, $0, 0x1
    /* 1C79B0 002C79B0 3C810B0C */  jal        func_002e04f0
    /* 1C79B4 002C79B4 00000000 */   nop
    /* 1C79B8 002C79B8 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C79BC 002C79BC 2D280000 */  daddu      $5, $0, $0
    /* 1C79C0 002C79C0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C79C4 002C79C4 2D380000 */  daddu      $7, $0, $0
    /* 1C79C8 002C79C8 05000824 */  addiu      $8, $0, 0x5
    /* 1C79CC 002C79CC 2D480000 */  daddu      $9, $0, $0
    /* 1C79D0 002C79D0 98810B0C */  jal        func_002e0660
    /* 1C79D4 002C79D4 00000000 */   nop
    /* 1C79D8 002C79D8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C79DC 002C79DC 2D280000 */  daddu      $5, $0, $0
    /* 1C79E0 002C79E0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C79E4 002C79E4 2D380000 */  daddu      $7, $0, $0
    /* 1C79E8 002C79E8 05000824 */  addiu      $8, $0, 0x5
    /* 1C79EC 002C79EC 2D480000 */  daddu      $9, $0, $0
    /* 1C79F0 002C79F0 98810B0C */  jal        func_002e0660
    /* 1C79F4 002C79F4 00000000 */   nop
    /* 1C79F8 002C79F8 24000224 */  addiu      $2, $0, 0x24
    /* 1C79FC 002C79FC 000022A2 */  sb         $2, 0x0($17)
    /* 1C7A00 002C7A00 240C2382 */  lb         $3, 0xC24($17)
    /* 1C7A04 002C7A04 01000224 */  addiu      $2, $0, 0x1
    /* 1C7A08 002C7A08 470B6214 */  bne        $3, $2, .L002CA728
    /* 1C7A0C 002C7A0C 00000000 */   nop
    /* 1C7A10 002C7A10 31000224 */  addiu      $2, $0, 0x31
    /* 1C7A14 002C7A14 000022A2 */  sb         $2, 0x0($17)
    /* 1C7A18 002C7A18 430B0010 */  b          .L002CA728
    /* 1C7A1C 002C7A1C 00000000 */   nop
    /* 1C7A20 002C7A20 2D208002 */  daddu      $4, $20, $0
    /* 1C7A24 002C7A24 02000524 */  addiu      $5, $0, 0x2
    /* 1C7A28 002C7A28 E0370B0C */  jal        func_002cdf80
    /* 1C7A2C 002C7A2C 00000000 */   nop
    /* 1C7A30 002C7A30 11002282 */  lb         $2, 0x11($17)
    /* 1C7A34 002C7A34 80100200 */  sll        $2, $2, 2
    /* 1C7A38 002C7A38 21105100 */  addu       $2, $2, $17
    /* 1C7A3C 002C7A3C 02002586 */  lh         $5, 0x2($17)
    /* 1C7A40 002C7A40 180F448C */  lw         $4, 0xF18($2)
    /* 1C7A44 002C7A44 0C8A0B0C */  jal        func_002e2830
    /* 1C7A48 002C7A48 00000000 */   nop
    /* 1C7A4C 002C7A4C 3C9C0200 */  dsll32     $19, $2, 16
    /* 1C7A50 002C7A50 3F9C1300 */  dsra32     $19, $19, 16
    /* 1C7A54 002C7A54 11002282 */  lb         $2, 0x11($17)
    /* 1C7A58 002C7A58 80100200 */  sll        $2, $2, 2
    /* 1C7A5C 002C7A5C 21105100 */  addu       $2, $2, $17
    /* 1C7A60 002C7A60 02002586 */  lh         $5, 0x2($17)
    /* 1C7A64 002C7A64 180F448C */  lw         $4, 0xF18($2)
    /* 1C7A68 002C7A68 3C8A0B0C */  jal        func_002e28f0
    /* 1C7A6C 002C7A6C 00000000 */   nop
    /* 1C7A70 002C7A70 3C840200 */  dsll32     $16, $2, 16
    /* 1C7A74 002C7A74 3F841000 */  dsra32     $16, $16, 16
    /* 1C7A78 002C7A78 11002282 */  lb         $2, 0x11($17)
    /* 1C7A7C 002C7A7C 80100200 */  sll        $2, $2, 2
    /* 1C7A80 002C7A80 21105100 */  addu       $2, $2, $17
    /* 1C7A84 002C7A84 180F448C */  lw         $4, 0xF18($2)
    /* 1C7A88 002C7A88 BC890B0C */  jal        func_002e26f0
    /* 1C7A8C 002C7A8C 00000000 */   nop
    /* 1C7A90 002C7A90 2D904000 */  daddu      $18, $2, $0
    /* 1C7A94 002C7A94 02003786 */  lh         $23, 0x2($17)
    /* 1C7A98 002C7A98 04003E86 */  lh         $30, 0x4($17)
    /* 1C7A9C 002C7A9C FF000632 */  andi       $6, $16, 0xFF
    /* 1C7AA0 002C7AA0 2D208002 */  daddu      $4, $20, $0
    /* 1C7AA4 002C7AA4 2D286002 */  daddu      $5, $19, $0
    /* 1C7AA8 002C7AA8 087C0B0C */  jal        func_002df020
    /* 1C7AAC 002C7AAC 00000000 */   nop
    /* 1C7AB0 002C7AB0 10002482 */  lb         $4, 0x10($17)
    /* 1C7AB4 002C7AB4 A0ED0A0C */  jal        func_002bb680
    /* 1C7AB8 002C7AB8 00000000 */   nop
    /* 1C7ABC 002C7ABC 06004010 */  beqz       $2, .L002C7AD8
    /* 1C7AC0 002C7AC0 00000000 */   nop
    /* 1C7AC4 002C7AC4 10002482 */  lb         $4, 0x10($17)
    /* 1C7AC8 002C7AC8 3CEF0A0C */  jal        func_002bbcf0
    /* 1C7ACC 002C7ACC 00000000 */   nop
    /* 1C7AD0 002C7AD0 150B0010 */  b          .L002CA728
    /* 1C7AD4 002C7AD4 00000000 */   nop
  .L002C7AD8:
    /* 1C7AD8 002C7AD8 160C20A6 */  sh         $0, 0xC16($17)
    /* 1C7ADC 002C7ADC 180C20A6 */  sh         $0, 0xC18($17)
    /* 1C7AE0 002C7AE0 10002482 */  lb         $4, 0x10($17)
    /* 1C7AE4 002C7AE4 70EC0A0C */  jal        func_002bb1c0
    /* 1C7AE8 002C7AE8 00000000 */   nop
    /* 1C7AEC 002C7AEC 2B014014 */  bnez       $2, .L002C7F9C
    /* 1C7AF0 002C7AF0 00000000 */   nop
    /* 1C7AF4 002C7AF4 2D200000 */  daddu      $4, $0, $0
    /* 1C7AF8 002C7AF8 2D280000 */  daddu      $5, $0, $0
    /* 1C7AFC 002C7AFC 2D300000 */  daddu      $6, $0, $0
    /* 1C7B00 002C7B00 06000724 */  addiu      $7, $0, 0x6
    /* 1C7B04 002C7B04 D86B110C */  jal        func_0045af60
    /* 1C7B08 002C7B08 00000000 */   nop
    /* 1C7B0C 002C7B0C 2D206002 */  daddu      $4, $19, $0
    /* 1C7B10 002C7B10 141A040C */  jal        func_00106850
    /* 1C7B14 002C7B14 00000000 */   nop
    /* 1C7B18 002C7B18 05000324 */  addiu      $3, $0, 0x5
    /* 1C7B1C 002C7B1C 4A004314 */  bne        $2, $3, .L002C7C48
    /* 1C7B20 002C7B20 00000000 */   nop
    /* 1C7B24 002C7B24 3C841300 */  dsll32     $16, $19, 16
    /* 1C7B28 002C7B28 3F841000 */  dsra32     $16, $16, 16
    /* 1C7B2C 002C7B2C 2D200002 */  daddu      $4, $16, $0
    /* 1C7B30 002C7B30 0C42040C */  jal        func_00110830
    /* 1C7B34 002C7B34 00000000 */   nop
    /* 1C7B38 002C7B38 FF004430 */  andi       $4, $2, 0xFF
    /* 1C7B3C 002C7B3C 12002586 */  lh         $5, 0x12($17)
    /* 1C7B40 002C7B40 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C7B44 002C7B44 2D380000 */  daddu      $7, $0, $0
    /* 1C7B48 002C7B48 01000824 */  addiu      $8, $0, 0x1
    /* 1C7B4C 002C7B4C 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7B50 002C7B50 00000000 */   nop
    /* 1C7B54 002C7B54 FF004530 */  andi       $5, $2, 0xFF
    /* 1C7B58 002C7B58 2D200002 */  daddu      $4, $16, $0
    /* 1C7B5C 002C7B5C 0442040C */  jal        func_00110810
    /* 1C7B60 002C7B60 00000000 */   nop
    /* 1C7B64 002C7B64 2D800000 */  daddu      $16, $0, $0
    /* 1C7B68 002C7B68 32000010 */  b          .L002C7C34
    /* 1C7B6C 002C7B6C 00000000 */   nop
  .L002C7B70:
    /* 1C7B70 002C7B70 0C42040C */  jal        func_00110830
    /* 1C7B74 002C7B74 00000000 */   nop
    /* 1C7B78 002C7B78 FF004230 */  andi       $2, $2, 0xFF
    /* 1C7B7C 002C7B7C 2A004014 */  bnez       $2, .L002C7C28
    /* 1C7B80 002C7B80 00000000 */   nop
    /* 1C7B84 002C7B84 2D200002 */  daddu      $4, $16, $0
    /* 1C7B88 002C7B88 C81A040C */  jal        func_00106b20
    /* 1C7B8C 002C7B8C 00000000 */   nop
    /* 1C7B90 002C7B90 0F00033C */  lui        $3, (0xFFF00 >> 16)
    /* 1C7B94 002C7B94 00FF6334 */  ori        $3, $3, (0xFFF00 & 0xFFFF)
    /* 1C7B98 002C7B98 24104300 */  and        $2, $2, $3
    /* 1C7B9C 002C7B9C 03AA0200 */  sra        $21, $2, 8
    /* 1C7BA0 002C7BA0 2D200002 */  daddu      $4, $16, $0
    /* 1C7BA4 002C7BA4 C81A040C */  jal        func_00106b20
    /* 1C7BA8 002C7BA8 00000000 */   nop
    /* 1C7BAC 002C7BAC FF004530 */  andi       $5, $2, 0xFF
    /* 1C7BB0 002C7BB0 2D20A002 */  daddu      $4, $21, $0
    /* 1C7BB4 002C7BB4 58F80A0C */  jal        func_002be160
    /* 1C7BB8 002C7BB8 00000000 */   nop
    /* 1C7BBC 002C7BBC 01000324 */  addiu      $3, $0, 0x1
    /* 1C7BC0 002C7BC0 19004314 */  bne        $2, $3, .L002C7C28
    /* 1C7BC4 002C7BC4 00000000 */   nop
    /* 1C7BC8 002C7BC8 2D200002 */  daddu      $4, $16, $0
    /* 1C7BCC 002C7BCC D41A040C */  jal        func_00106b50
    /* 1C7BD0 002C7BD0 00000000 */   nop
    /* 1C7BD4 002C7BD4 0F00033C */  lui        $3, (0xFFF00 >> 16)
    /* 1C7BD8 002C7BD8 00FF6334 */  ori        $3, $3, (0xFFF00 & 0xFFFF)
    /* 1C7BDC 002C7BDC 24104300 */  and        $2, $2, $3
    /* 1C7BE0 002C7BE0 03AA0200 */  sra        $21, $2, 8
    /* 1C7BE4 002C7BE4 2D200002 */  daddu      $4, $16, $0
    /* 1C7BE8 002C7BE8 D41A040C */  jal        func_00106b50
    /* 1C7BEC 002C7BEC 00000000 */   nop
    /* 1C7BF0 002C7BF0 FF004530 */  andi       $5, $2, 0xFF
    /* 1C7BF4 002C7BF4 2D20A002 */  daddu      $4, $21, $0
    /* 1C7BF8 002C7BF8 58F80A0C */  jal        func_002be160
    /* 1C7BFC 002C7BFC 00000000 */   nop
    /* 1C7C00 002C7C00 01000324 */  addiu      $3, $0, 0x1
    /* 1C7C04 002C7C04 08004314 */  bne        $2, $3, .L002C7C28
    /* 1C7C08 002C7C08 00000000 */   nop
    /* 1C7C0C 002C7C0C 160C2286 */  lh         $2, 0xC16($17)
    /* 1C7C10 002C7C10 40100200 */  sll        $2, $2, 1
    /* 1C7C14 002C7C14 21102202 */  addu       $2, $17, $2
    /* 1C7C18 002C7C18 160050A4 */  sh         $16, 0x16($2)
    /* 1C7C1C 002C7C1C 160C2286 */  lh         $2, 0xC16($17)
    /* 1C7C20 002C7C20 01004224 */  addiu      $2, $2, 0x1
    /* 1C7C24 002C7C24 160C22A6 */  sh         $2, 0xC16($17)
  .L002C7C28:
    /* 1C7C28 002C7C28 01000226 */  addiu      $2, $16, 0x1
    /* 1C7C2C 002C7C2C 3C840200 */  dsll32     $16, $2, 16
    /* 1C7C30 002C7C30 3F841000 */  dsra32     $16, $16, 16
  .L002C7C34:
    /* 1C7C34 002C7C34 3C241000 */  dsll32     $4, $16, 16
    /* 1C7C38 002C7C38 3F240400 */  dsra32     $4, $4, 16
    /* 1C7C3C 002C7C3C FF028228 */  slti       $2, $4, 0x2FF
    /* 1C7C40 002C7C40 CBFF4014 */  bnez       $2, .L002C7B70
    /* 1C7C44 002C7C44 00000000 */   nop
  .L002C7C48:
    /* 1C7C48 002C7C48 3C241300 */  dsll32     $4, $19, 16
    /* 1C7C4C 002C7C4C 3F240400 */  dsra32     $4, $4, 16
    /* 1C7C50 002C7C50 A41A040C */  jal        func_00106a90
    /* 1C7C54 002C7C54 00000000 */   nop
    /* 1C7C58 002C7C58 05000324 */  addiu      $3, $0, 0x5
    /* 1C7C5C 002C7C5C 1B004300 */  divu       $0, $2, $3
    /* 1C7C60 002C7C60 12800000 */  mflo       $16
    /* 1C7C64 002C7C64 989E0B0C */  jal        func_002e7a60
    /* 1C7C68 002C7C68 00000000 */   nop
    /* 1C7C6C 002C7C6C 12002386 */  lh         $3, 0x12($17)
    /* 1C7C70 002C7C70 18187000 */  mult       $3, $3, $16
    /* 1C7C74 002C7C74 21204300 */  addu       $4, $2, $3
    /* 1C7C78 002C7C78 A09E0B0C */  jal        func_002e7a80
    /* 1C7C7C 002C7C7C 00000000 */   nop
    /* 1C7C80 002C7C80 2D206002 */  daddu      $4, $19, $0
    /* 1C7C84 002C7C84 8019040C */  jal        func_00106600
    /* 1C7C88 002C7C88 00000000 */   nop
    /* 1C7C8C 002C7C8C FF004330 */  andi       $3, $2, 0xFF
    /* 1C7C90 002C7C90 12002286 */  lh         $2, 0x12($17)
    /* 1C7C94 002C7C94 23106200 */  subu       $2, $3, $2
    /* 1C7C98 002C7C98 FF004530 */  andi       $5, $2, 0xFF
    /* 1C7C9C 002C7C9C 2D206002 */  daddu      $4, $19, $0
    /* 1C7CA0 002C7CA0 8819040C */  jal        func_00106620
    /* 1C7CA4 002C7CA4 00000000 */   nop
    /* 1C7CA8 002C7CA8 11002382 */  lb         $3, 0x11($17)
    /* 1C7CAC 002C7CAC 02000224 */  addiu      $2, $0, 0x2
    /* 1C7CB0 002C7CB0 68006210 */  beq        $3, $2, .L002C7E54
    /* 1C7CB4 002C7CB4 00000000 */   nop
    /* 1C7CB8 002C7CB8 01000724 */  addiu      $7, $0, 0x1
    /* 1C7CBC 002C7CBC 5B006710 */  beq        $3, $7, .L002C7E2C
    /* 1C7CC0 002C7CC0 00000000 */   nop
    /* 1C7CC4 002C7CC4 03006010 */  beqz       $3, .L002C7CD4
    /* 1C7CC8 002C7CC8 00000000 */   nop
    /* 1C7CCC 002C7CCC 6A000010 */  b          .L002C7E78
    /* 1C7CD0 002C7CD0 00000000 */   nop
  .L002C7CD4:
    /* 1C7CD4 002C7CD4 80100300 */  sll        $2, $3, 2
    /* 1C7CD8 002C7CD8 21105100 */  addu       $2, $2, $17
    /* 1C7CDC 002C7CDC 180F448C */  lw         $4, 0xF18($2)
    /* 1C7CE0 002C7CE0 0400053C */  lui        $5, (0x40000 >> 16)
    /* 1C7CE4 002C7CE4 2D300000 */  daddu      $6, $0, $0
    /* 1C7CE8 002C7CE8 04000724 */  addiu      $7, $0, 0x4
    /* 1C7CEC 002C7CEC 2D400000 */  daddu      $8, $0, $0
    /* 1C7CF0 002C7CF0 588D0B0C */  jal        func_002e3560
    /* 1C7CF4 002C7CF4 00000000 */   nop
    /* 1C7CF8 002C7CF8 200C20AE */  sw         $0, 0xC20($17)
    /* 1C7CFC 002C7CFC 01001324 */  addiu      $19, $0, 0x1
    /* 1C7D00 002C7D00 3D000010 */  b          .L002C7DF8
    /* 1C7D04 002C7D04 00000000 */   nop
  .L002C7D08:
    /* 1C7D08 002C7D08 3C841300 */  dsll32     $16, $19, 16
    /* 1C7D0C 002C7D0C 3F841000 */  dsra32     $16, $16, 16
    /* 1C7D10 002C7D10 11002282 */  lb         $2, 0x11($17)
    /* 1C7D14 002C7D14 80100200 */  sll        $2, $2, 2
    /* 1C7D18 002C7D18 21102202 */  addu       $2, $17, $2
    /* 1C7D1C 002C7D1C 180F448C */  lw         $4, 0xF18($2)
    /* 1C7D20 002C7D20 2D280002 */  daddu      $5, $16, $0
    /* 1C7D24 002C7D24 0C8A0B0C */  jal        func_002e2830
    /* 1C7D28 002C7D28 00000000 */   nop
    /* 1C7D2C 002C7D2C 3CAC0200 */  dsll32     $21, $2, 16
    /* 1C7D30 002C7D30 3FAC1500 */  dsra32     $21, $21, 16
    /* 1C7D34 002C7D34 11002282 */  lb         $2, 0x11($17)
    /* 1C7D38 002C7D38 80100200 */  sll        $2, $2, 2
    /* 1C7D3C 002C7D3C 21102202 */  addu       $2, $17, $2
    /* 1C7D40 002C7D40 180F448C */  lw         $4, 0xF18($2)
    /* 1C7D44 002C7D44 2D280002 */  daddu      $5, $16, $0
    /* 1C7D48 002C7D48 3C8A0B0C */  jal        func_002e28f0
    /* 1C7D4C 002C7D4C 00000000 */   nop
    /* 1C7D50 002C7D50 3C841500 */  dsll32     $16, $21, 16
    /* 1C7D54 002C7D54 3F841000 */  dsra32     $16, $16, 16
    /* 1C7D58 002C7D58 2D200002 */  daddu      $4, $16, $0
    /* 1C7D5C 002C7D5C 0C42040C */  jal        func_00110830
    /* 1C7D60 002C7D60 00000000 */   nop
    /* 1C7D64 002C7D64 FF005630 */  andi       $22, $2, 0xFF
    /* 1C7D68 002C7D68 2D20A002 */  daddu      $4, $21, $0
    /* 1C7D6C 002C7D6C 8019040C */  jal        func_00106600
    /* 1C7D70 002C7D70 00000000 */   nop
    /* 1C7D74 002C7D74 FF004530 */  andi       $5, $2, 0xFF
    /* 1C7D78 002C7D78 2D20C002 */  daddu      $4, $22, $0
    /* 1C7D7C 002C7D7C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C7D80 002C7D80 2D380000 */  daddu      $7, $0, $0
    /* 1C7D84 002C7D84 01000824 */  addiu      $8, $0, 0x1
    /* 1C7D88 002C7D88 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7D8C 002C7D8C 00000000 */   nop
    /* 1C7D90 002C7D90 3C241000 */  dsll32     $4, $16, 16
    /* 1C7D94 002C7D94 3F240400 */  dsra32     $4, $4, 16
    /* 1C7D98 002C7D98 A41A040C */  jal        func_00106a90
    /* 1C7D9C 002C7D9C 00000000 */   nop
    /* 1C7DA0 002C7DA0 05000324 */  addiu      $3, $0, 0x5
    /* 1C7DA4 002C7DA4 1B004300 */  divu       $0, $2, $3
    /* 1C7DA8 002C7DA8 12800000 */  mflo       $16
    /* 1C7DAC 002C7DAC 2D20A002 */  daddu      $4, $21, $0
    /* 1C7DB0 002C7DB0 8019040C */  jal        func_00106600
    /* 1C7DB4 002C7DB4 00000000 */   nop
    /* 1C7DB8 002C7DB8 FF004230 */  andi       $2, $2, 0xFF
    /* 1C7DBC 002C7DBC 18180202 */  mult       $3, $16, $2
    /* 1C7DC0 002C7DC0 200C228E */  lw         $2, 0xC20($17)
    /* 1C7DC4 002C7DC4 21204300 */  addu       $4, $2, $3
    /* 1C7DC8 002C7DC8 200C24AE */  sw         $4, 0xC20($17)
    /* 1C7DCC 002C7DCC 2D280000 */  daddu      $5, $0, $0
    /* 1C7DD0 002C7DD0 9800023C */  lui        $2, (0x98967F >> 16)
    /* 1C7DD4 002C7DD4 7F964634 */  ori        $6, $2, (0x98967F & 0xFFFF)
    /* 1C7DD8 002C7DD8 2D380000 */  daddu      $7, $0, $0
    /* 1C7DDC 002C7DDC 01000824 */  addiu      $8, $0, 0x1
    /* 1C7DE0 002C7DE0 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7DE4 002C7DE4 00000000 */   nop
    /* 1C7DE8 002C7DE8 200C22AE */  sw         $2, 0xC20($17)
    /* 1C7DEC 002C7DEC 01006226 */  addiu      $2, $19, 0x1
    /* 1C7DF0 002C7DF0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1C7DF4 002C7DF4 3F9C1300 */  dsra32     $19, $19, 16
  .L002C7DF8:
    /* 1C7DF8 002C7DF8 3C841300 */  dsll32     $16, $19, 16
    /* 1C7DFC 002C7DFC 3F841000 */  dsra32     $16, $16, 16
    /* 1C7E00 002C7E00 11002282 */  lb         $2, 0x11($17)
    /* 1C7E04 002C7E04 80100200 */  sll        $2, $2, 2
    /* 1C7E08 002C7E08 21102202 */  addu       $2, $17, $2
    /* 1C7E0C 002C7E0C 180F448C */  lw         $4, 0xF18($2)
    /* 1C7E10 002C7E10 BC890B0C */  jal        func_002e26f0
    /* 1C7E14 002C7E14 00000000 */   nop
    /* 1C7E18 002C7E18 2A100202 */  slt        $2, $16, $2
    /* 1C7E1C 002C7E1C BAFF4014 */  bnez       $2, .L002C7D08
    /* 1C7E20 002C7E20 00000000 */   nop
    /* 1C7E24 002C7E24 14000010 */  b          .L002C7E78
    /* 1C7E28 002C7E28 00000000 */   nop
  .L002C7E2C:
    /* 1C7E2C 002C7E2C 80100300 */  sll        $2, $3, 2
    /* 1C7E30 002C7E30 21105100 */  addu       $2, $2, $17
    /* 1C7E34 002C7E34 180F448C */  lw         $4, 0xF18($2)
    /* 1C7E38 002C7E38 FFFF0534 */  ori        $5, $0, 0xFFFF
    /* 1C7E3C 002C7E3C E01F0624 */  addiu      $6, $0, 0x1FE0
    /* 1C7E40 002C7E40 2D400000 */  daddu      $8, $0, $0
    /* 1C7E44 002C7E44 588D0B0C */  jal        func_002e3560
    /* 1C7E48 002C7E48 00000000 */   nop
    /* 1C7E4C 002C7E4C 0A000010 */  b          .L002C7E78
    /* 1C7E50 002C7E50 00000000 */   nop
  .L002C7E54:
    /* 1C7E54 002C7E54 80100300 */  sll        $2, $3, 2
    /* 1C7E58 002C7E58 21105100 */  addu       $2, $2, $17
    /* 1C7E5C 002C7E5C 180F448C */  lw         $4, 0xF18($2)
    /* 1C7E60 002C7E60 0100053C */  lui        $5, (0x10000 >> 16)
    /* 1C7E64 002C7E64 2D300000 */  daddu      $6, $0, $0
    /* 1C7E68 002C7E68 01000724 */  addiu      $7, $0, 0x1
    /* 1C7E6C 002C7E6C 2D400000 */  daddu      $8, $0, $0
    /* 1C7E70 002C7E70 588D0B0C */  jal        func_002e3560
    /* 1C7E74 002C7E74 00000000 */   nop
  .L002C7E78:
    /* 1C7E78 002C7E78 11002282 */  lb         $2, 0x11($17)
    /* 1C7E7C 002C7E7C 80100200 */  sll        $2, $2, 2
    /* 1C7E80 002C7E80 21105100 */  addu       $2, $2, $17
    /* 1C7E84 002C7E84 180F448C */  lw         $4, 0xF18($2)
    /* 1C7E88 002C7E88 BC890B0C */  jal        func_002e26f0
    /* 1C7E8C 002C7E8C 00000000 */   nop
    /* 1C7E90 002C7E90 3E004212 */  beq        $18, $2, .L002C7F8C
    /* 1C7E94 002C7E94 00000000 */   nop
    /* 1C7E98 002C7E98 3C241700 */  dsll32     $4, $23, 16
    /* 1C7E9C 002C7E9C 3F240400 */  dsra32     $4, $4, 16
    /* 1C7EA0 002C7EA0 3C141E00 */  dsll32     $2, $30, 16
    /* 1C7EA4 002C7EA4 3F140200 */  dsra32     $2, $2, 16
    /* 1C7EA8 002C7EA8 23108200 */  subu       $2, $4, $2
    /* 1C7EAC 002C7EAC 1B004018 */  blez       $2, .L002C7F1C
    /* 1C7EB0 002C7EB0 00000000 */   nop
    /* 1C7EB4 002C7EB4 01000524 */  addiu      $5, $0, 0x1
    /* 1C7EB8 002C7EB8 2D300000 */  daddu      $6, $0, $0
    /* 1C7EBC 002C7EBC 2D380000 */  daddu      $7, $0, $0
    /* 1C7EC0 002C7EC0 2D40A000 */  daddu      $8, $5, $0
    /* 1C7EC4 002C7EC4 40CB0A0C */  jal        func_002b2d00
    /* 1C7EC8 002C7EC8 00000000 */   nop
    /* 1C7ECC 002C7ECC 3C840200 */  dsll32     $16, $2, 16
    /* 1C7ED0 002C7ED0 3F841000 */  dsra32     $16, $16, 16
    /* 1C7ED4 002C7ED4 020020A6 */  sh         $0, 0x2($17)
    /* 1C7ED8 002C7ED8 11002282 */  lb         $2, 0x11($17)
    /* 1C7EDC 002C7EDC 80100200 */  sll        $2, $2, 2
    /* 1C7EE0 002C7EE0 21105100 */  addu       $2, $2, $17
    /* 1C7EE4 002C7EE4 180F448C */  lw         $4, 0xF18($2)
    /* 1C7EE8 002C7EE8 C0890B0C */  jal        func_002e2700
    /* 1C7EEC 002C7EEC 00000000 */   nop
    /* 1C7EF0 002C7EF0 02002486 */  lh         $4, 0x2($17)
    /* 1C7EF4 002C7EF4 3C2C1000 */  dsll32     $5, $16, 16
    /* 1C7EF8 002C7EF8 3F2C0500 */  dsra32     $5, $5, 16
    /* 1C7EFC 002C7EFC 2D304000 */  daddu      $6, $2, $0
    /* 1C7F00 002C7F00 2D380000 */  daddu      $7, $0, $0
    /* 1C7F04 002C7F04 01000824 */  addiu      $8, $0, 0x1
    /* 1C7F08 002C7F08 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7F0C 002C7F0C 00000000 */   nop
    /* 1C7F10 002C7F10 020022A6 */  sh         $2, 0x2($17)
    /* 1C7F14 002C7F14 0F000010 */  b          .L002C7F54
    /* 1C7F18 002C7F18 00000000 */   nop
  .L002C7F1C:
    /* 1C7F1C 002C7F1C 11002282 */  lb         $2, 0x11($17)
    /* 1C7F20 002C7F20 80100200 */  sll        $2, $2, 2
    /* 1C7F24 002C7F24 21105100 */  addu       $2, $2, $17
    /* 1C7F28 002C7F28 180F448C */  lw         $4, 0xF18($2)
    /* 1C7F2C 002C7F2C C0890B0C */  jal        func_002e2700
    /* 1C7F30 002C7F30 00000000 */   nop
    /* 1C7F34 002C7F34 02002486 */  lh         $4, 0x2($17)
    /* 1C7F38 002C7F38 2D280000 */  daddu      $5, $0, $0
    /* 1C7F3C 002C7F3C 2D304000 */  daddu      $6, $2, $0
    /* 1C7F40 002C7F40 2D380000 */  daddu      $7, $0, $0
    /* 1C7F44 002C7F44 01000824 */  addiu      $8, $0, 0x1
    /* 1C7F48 002C7F48 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7F4C 002C7F4C 00000000 */   nop
    /* 1C7F50 002C7F50 020022A6 */  sh         $2, 0x2($17)
  .L002C7F54:
    /* 1C7F54 002C7F54 11002282 */  lb         $2, 0x11($17)
    /* 1C7F58 002C7F58 80100200 */  sll        $2, $2, 2
    /* 1C7F5C 002C7F5C 21105100 */  addu       $2, $2, $17
    /* 1C7F60 002C7F60 180F448C */  lw         $4, 0xF18($2)
    /* 1C7F64 002C7F64 C0890B0C */  jal        func_002e2700
    /* 1C7F68 002C7F68 00000000 */   nop
    /* 1C7F6C 002C7F6C 04002486 */  lh         $4, 0x4($17)
    /* 1C7F70 002C7F70 2D280000 */  daddu      $5, $0, $0
    /* 1C7F74 002C7F74 2D304000 */  daddu      $6, $2, $0
    /* 1C7F78 002C7F78 2D380000 */  daddu      $7, $0, $0
    /* 1C7F7C 002C7F7C 01000824 */  addiu      $8, $0, 0x1
    /* 1C7F80 002C7F80 2CCB0A0C */  jal        func_002b2cb0
    /* 1C7F84 002C7F84 00000000 */   nop
    /* 1C7F88 002C7F88 040022A6 */  sh         $2, 0x4($17)
  .L002C7F8C:
    /* 1C7F8C 002C7F8C 11002582 */  lb         $5, 0x11($17)
    /* 1C7F90 002C7F90 2D208002 */  daddu      $4, $20, $0
    /* 1C7F94 002C7F94 D8510B0C */  jal        func_002d4760
    /* 1C7F98 002C7F98 00000000 */   nop
  .L002C7F9C:
    /* 1C7F9C 002C7F9C 2D208002 */  daddu      $4, $20, $0
    /* 1C7FA0 002C7FA0 307D0B0C */  jal        func_002df4c0
    /* 1C7FA4 002C7FA4 00000000 */   nop
    /* 1C7FA8 002C7FA8 10002482 */  lb         $4, 0x10($17)
    /* 1C7FAC 002C7FAC 54ED0A0C */  jal        func_002bb550
    /* 1C7FB0 002C7FB0 00000000 */   nop
    /* 1C7FB4 002C7FB4 CC0C248E */  lw         $4, 0xCCC($17)
    /* 1C7FB8 002C7FB8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C7FBC 002C7FBC 2D300000 */  daddu      $6, $0, $0
    /* 1C7FC0 002C7FC0 2D380000 */  daddu      $7, $0, $0
    /* 1C7FC4 002C7FC4 05000824 */  addiu      $8, $0, 0x5
    /* 1C7FC8 002C7FC8 2D480000 */  daddu      $9, $0, $0
    /* 1C7FCC 002C7FCC 98810B0C */  jal        func_002e0660
    /* 1C7FD0 002C7FD0 00000000 */   nop
    /* 1C7FD4 002C7FD4 D00C248E */  lw         $4, 0xCD0($17)
    /* 1C7FD8 002C7FD8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C7FDC 002C7FDC 2D300000 */  daddu      $6, $0, $0
    /* 1C7FE0 002C7FE0 2D380000 */  daddu      $7, $0, $0
    /* 1C7FE4 002C7FE4 05000824 */  addiu      $8, $0, 0x5
    /* 1C7FE8 002C7FE8 2D480000 */  daddu      $9, $0, $0
    /* 1C7FEC 002C7FEC 98810B0C */  jal        func_002e0660
    /* 1C7FF0 002C7FF0 00000000 */   nop
    /* 1C7FF4 002C7FF4 C80C248E */  lw         $4, 0xCC8($17)
    /* 1C7FF8 002C7FF8 2D280000 */  daddu      $5, $0, $0
    /* 1C7FFC 002C7FFC 01000624 */  addiu      $6, $0, 0x1
    /* 1C8000 002C8000 3C810B0C */  jal        func_002e04f0
    /* 1C8004 002C8004 00000000 */   nop
    /* 1C8008 002C8008 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C800C 002C800C 2D280000 */  daddu      $5, $0, $0
    /* 1C8010 002C8010 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C8014 002C8014 2D380000 */  daddu      $7, $0, $0
    /* 1C8018 002C8018 05000824 */  addiu      $8, $0, 0x5
    /* 1C801C 002C801C 2D480000 */  daddu      $9, $0, $0
    /* 1C8020 002C8020 98810B0C */  jal        func_002e0660
    /* 1C8024 002C8024 00000000 */   nop
    /* 1C8028 002C8028 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C802C 002C802C 2D280000 */  daddu      $5, $0, $0
    /* 1C8030 002C8030 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C8034 002C8034 2D380000 */  daddu      $7, $0, $0
    /* 1C8038 002C8038 05000824 */  addiu      $8, $0, 0x5
    /* 1C803C 002C803C 2D480000 */  daddu      $9, $0, $0
    /* 1C8040 002C8040 98810B0C */  jal        func_002e0660
    /* 1C8044 002C8044 00000000 */   nop
    /* 1C8048 002C8048 24000224 */  addiu      $2, $0, 0x24
    /* 1C804C 002C804C 000022A2 */  sb         $2, 0x0($17)
    /* 1C8050 002C8050 240C2382 */  lb         $3, 0xC24($17)
    /* 1C8054 002C8054 01000224 */  addiu      $2, $0, 0x1
    /* 1C8058 002C8058 16006214 */  bne        $3, $2, .L002C80B4
    /* 1C805C 002C805C 00000000 */   nop
    /* 1C8060 002C8060 11002282 */  lb         $2, 0x11($17)
    /* 1C8064 002C8064 80100200 */  sll        $2, $2, 2
    /* 1C8068 002C8068 21105100 */  addu       $2, $2, $17
    /* 1C806C 002C806C 180F448C */  lw         $4, 0xF18($2)
    /* 1C8070 002C8070 BC890B0C */  jal        func_002e26f0
    /* 1C8074 002C8074 00000000 */   nop
    /* 1C8078 002C8078 11002482 */  lb         $4, 0x11($17)
    /* 1C807C 002C807C 7500033C */  lui        $3, %hi(D_00748908)
    /* 1C8080 002C8080 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1C8084 002C8084 21186400 */  addu       $3, $3, $4
    /* 1C8088 002C8088 00006380 */  lb         $3, 0x0($3)
    /* 1C808C 002C808C 2A086200 */  slt        $1, $3, $2
    /* 1C8090 002C8090 06002014 */  bnez       $1, .L002C80AC
    /* 1C8094 002C8094 00000000 */   nop
    /* 1C8098 002C8098 2D208002 */  daddu      $4, $20, $0
    /* 1C809C 002C809C 80610B0C */  jal        func_002d8600
    /* 1C80A0 002C80A0 00000000 */   nop
    /* 1C80A4 002C80A4 03000010 */  b          .L002C80B4
    /* 1C80A8 002C80A8 00000000 */   nop
  .L002C80AC:
    /* 1C80AC 002C80AC 31000224 */  addiu      $2, $0, 0x31
    /* 1C80B0 002C80B0 000022A2 */  sb         $2, 0x0($17)
  .L002C80B4:
    /* 1C80B4 002C80B4 160C2286 */  lh         $2, 0xC16($17)
    /* 1C80B8 002C80B8 9B094018 */  blez       $2, .L002CA728
    /* 1C80BC 002C80BC 00000000 */   nop
    /* 1C80C0 002C80C0 1A0C20A2 */  sb         $0, 0xC1A($17)
    /* 1C80C4 002C80C4 2D208002 */  daddu      $4, $20, $0
    /* 1C80C8 002C80C8 807F0B0C */  jal        func_002dfe00
    /* 1C80CC 002C80CC 00000000 */   nop
    /* 1C80D0 002C80D0 29000224 */  addiu      $2, $0, 0x29
    /* 1C80D4 002C80D4 000022A2 */  sb         $2, 0x0($17)
    /* 1C80D8 002C80D8 93090010 */  b          .L002CA728
    /* 1C80DC 002C80DC 00000000 */   nop
    /* 1C80E0 002C80E0 2D208002 */  daddu      $4, $20, $0
    /* 1C80E4 002C80E4 02000524 */  addiu      $5, $0, 0x2
    /* 1C80E8 002C80E8 E0370B0C */  jal        func_002cdf80
    /* 1C80EC 002C80EC 00000000 */   nop
    /* 1C80F0 002C80F0 10002482 */  lb         $4, 0x10($17)
    /* 1C80F4 002C80F4 A0ED0A0C */  jal        func_002bb680
    /* 1C80F8 002C80F8 00000000 */   nop
    /* 1C80FC 002C80FC 06004010 */  beqz       $2, .L002C8118
    /* 1C8100 002C8100 00000000 */   nop
    /* 1C8104 002C8104 10002482 */  lb         $4, 0x10($17)
    /* 1C8108 002C8108 3CEF0A0C */  jal        func_002bbcf0
    /* 1C810C 002C810C 00000000 */   nop
    /* 1C8110 002C8110 85090010 */  b          .L002CA728
    /* 1C8114 002C8114 00000000 */   nop
  .L002C8118:
    /* 1C8118 002C8118 160C20A6 */  sh         $0, 0xC16($17)
    /* 1C811C 002C811C 180C20A6 */  sh         $0, 0xC18($17)
    /* 1C8120 002C8120 10002482 */  lb         $4, 0x10($17)
    /* 1C8124 002C8124 70EC0A0C */  jal        func_002bb1c0
    /* 1C8128 002C8128 00000000 */   nop
    /* 1C812C 002C812C FD004014 */  bnez       $2, .L002C8524
    /* 1C8130 002C8130 00000000 */   nop
    /* 1C8134 002C8134 10002482 */  lb         $4, 0x10($17)
    /* 1C8138 002C8138 54ED0A0C */  jal        func_002bb550
    /* 1C813C 002C813C 00000000 */   nop
    /* 1C8140 002C8140 2D200000 */  daddu      $4, $0, $0
    /* 1C8144 002C8144 2D280000 */  daddu      $5, $0, $0
    /* 1C8148 002C8148 2D300000 */  daddu      $6, $0, $0
    /* 1C814C 002C814C 06000724 */  addiu      $7, $0, 0x6
    /* 1C8150 002C8150 D86B110C */  jal        func_0045af60
    /* 1C8154 002C8154 00000000 */   nop
    /* 1C8158 002C8158 01001224 */  addiu      $18, $0, 0x1
    /* 1C815C 002C815C 3F000010 */  b          .L002C825C
    /* 1C8160 002C8160 00000000 */   nop
  .L002C8164:
    /* 1C8164 002C8164 3C841200 */  dsll32     $16, $18, 16
    /* 1C8168 002C8168 3F841000 */  dsra32     $16, $16, 16
    /* 1C816C 002C816C 11002282 */  lb         $2, 0x11($17)
    /* 1C8170 002C8170 80100200 */  sll        $2, $2, 2
    /* 1C8174 002C8174 21102202 */  addu       $2, $17, $2
    /* 1C8178 002C8178 180F448C */  lw         $4, 0xF18($2)
    /* 1C817C 002C817C 2D280002 */  daddu      $5, $16, $0
    /* 1C8180 002C8180 0C8A0B0C */  jal        func_002e2830
    /* 1C8184 002C8184 00000000 */   nop
    /* 1C8188 002C8188 2D984000 */  daddu      $19, $2, $0
    /* 1C818C 002C818C 11002282 */  lb         $2, 0x11($17)
    /* 1C8190 002C8190 80100200 */  sll        $2, $2, 2
    /* 1C8194 002C8194 21102202 */  addu       $2, $17, $2
    /* 1C8198 002C8198 180F448C */  lw         $4, 0xF18($2)
    /* 1C819C 002C819C 2D280002 */  daddu      $5, $16, $0
    /* 1C81A0 002C81A0 3C8A0B0C */  jal        func_002e28f0
    /* 1C81A4 002C81A4 00000000 */   nop
    /* 1C81A8 002C81A8 2D206002 */  daddu      $4, $19, $0
    /* 1C81AC 002C81AC 0C42040C */  jal        func_00110830
    /* 1C81B0 002C81B0 00000000 */   nop
    /* 1C81B4 002C81B4 FF005030 */  andi       $16, $2, 0xFF
    /* 1C81B8 002C81B8 3C241300 */  dsll32     $4, $19, 16
    /* 1C81BC 002C81BC 3F240400 */  dsra32     $4, $4, 16
    /* 1C81C0 002C81C0 8019040C */  jal        func_00106600
    /* 1C81C4 002C81C4 00000000 */   nop
    /* 1C81C8 002C81C8 FF004530 */  andi       $5, $2, 0xFF
    /* 1C81CC 002C81CC 2D200002 */  daddu      $4, $16, $0
    /* 1C81D0 002C81D0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1C81D4 002C81D4 2D380000 */  daddu      $7, $0, $0
    /* 1C81D8 002C81D8 01000824 */  addiu      $8, $0, 0x1
    /* 1C81DC 002C81DC 2CCB0A0C */  jal        func_002b2cb0
    /* 1C81E0 002C81E0 00000000 */   nop
    /* 1C81E4 002C81E4 FF004530 */  andi       $5, $2, 0xFF
    /* 1C81E8 002C81E8 2D206002 */  daddu      $4, $19, $0
    /* 1C81EC 002C81EC 0442040C */  jal        func_00110810
    /* 1C81F0 002C81F0 00000000 */   nop
    /* 1C81F4 002C81F4 3C241300 */  dsll32     $4, $19, 16
    /* 1C81F8 002C81F8 3F240400 */  dsra32     $4, $4, 16
    /* 1C81FC 002C81FC A41A040C */  jal        func_00106a90
    /* 1C8200 002C8200 00000000 */   nop
    /* 1C8204 002C8204 05000324 */  addiu      $3, $0, 0x5
    /* 1C8208 002C8208 1B004300 */  divu       $0, $2, $3
    /* 1C820C 002C820C 12800000 */  mflo       $16
    /* 1C8210 002C8210 3C241300 */  dsll32     $4, $19, 16
    /* 1C8214 002C8214 3F240400 */  dsra32     $4, $4, 16
    /* 1C8218 002C8218 8019040C */  jal        func_00106600
    /* 1C821C 002C821C 00000000 */   nop
    /* 1C8220 002C8220 FF004230 */  andi       $2, $2, 0xFF
    /* 1C8224 002C8224 18800202 */  mult       $16, $16, $2
    /* 1C8228 002C8228 989E0B0C */  jal        func_002e7a60
    /* 1C822C 002C822C 00000000 */   nop
    /* 1C8230 002C8230 21205000 */  addu       $4, $2, $16
    /* 1C8234 002C8234 A09E0B0C */  jal        func_002e7a80
    /* 1C8238 002C8238 00000000 */   nop
    /* 1C823C 002C823C 3C241300 */  dsll32     $4, $19, 16
    /* 1C8240 002C8240 3F240400 */  dsra32     $4, $4, 16
    /* 1C8244 002C8244 2D280000 */  daddu      $5, $0, $0
    /* 1C8248 002C8248 8819040C */  jal        func_00106620
    /* 1C824C 002C824C 00000000 */   nop
    /* 1C8250 002C8250 01004226 */  addiu      $2, $18, 0x1
    /* 1C8254 002C8254 3C940200 */  dsll32     $18, $2, 16
    /* 1C8258 002C8258 3F941200 */  dsra32     $18, $18, 16
  .L002C825C:
    /* 1C825C 002C825C 3C841200 */  dsll32     $16, $18, 16
    /* 1C8260 002C8260 3F841000 */  dsra32     $16, $16, 16
    /* 1C8264 002C8264 11002282 */  lb         $2, 0x11($17)
    /* 1C8268 002C8268 80100200 */  sll        $2, $2, 2
    /* 1C826C 002C826C 21102202 */  addu       $2, $17, $2
    /* 1C8270 002C8270 180F448C */  lw         $4, 0xF18($2)
    /* 1C8274 002C8274 BC890B0C */  jal        func_002e26f0
    /* 1C8278 002C8278 00000000 */   nop
    /* 1C827C 002C827C 2A100202 */  slt        $2, $16, $2
    /* 1C8280 002C8280 B8FF4014 */  bnez       $2, .L002C8164
    /* 1C8284 002C8284 00000000 */   nop
    /* 1C8288 002C8288 200C20AE */  sw         $0, 0xC20($17)
    /* 1C828C 002C828C 2D800000 */  daddu      $16, $0, $0
    /* 1C8290 002C8290 32000010 */  b          .L002C835C
    /* 1C8294 002C8294 00000000 */   nop
  .L002C8298:
    /* 1C8298 002C8298 0C42040C */  jal        func_00110830
    /* 1C829C 002C829C 00000000 */   nop
    /* 1C82A0 002C82A0 FF004230 */  andi       $2, $2, 0xFF
    /* 1C82A4 002C82A4 2A004014 */  bnez       $2, .L002C8350
    /* 1C82A8 002C82A8 00000000 */   nop
    /* 1C82AC 002C82AC 2D200002 */  daddu      $4, $16, $0
    /* 1C82B0 002C82B0 C81A040C */  jal        func_00106b20
    /* 1C82B4 002C82B4 00000000 */   nop
    /* 1C82B8 002C82B8 0F00033C */  lui        $3, (0xFFF00 >> 16)
    /* 1C82BC 002C82BC 00FF6334 */  ori        $3, $3, (0xFFF00 & 0xFFFF)
    /* 1C82C0 002C82C0 24104300 */  and        $2, $2, $3
    /* 1C82C4 002C82C4 03920200 */  sra        $18, $2, 8
    /* 1C82C8 002C82C8 2D200002 */  daddu      $4, $16, $0
    /* 1C82CC 002C82CC C81A040C */  jal        func_00106b20
    /* 1C82D0 002C82D0 00000000 */   nop
    /* 1C82D4 002C82D4 FF004530 */  andi       $5, $2, 0xFF
    /* 1C82D8 002C82D8 2D204002 */  daddu      $4, $18, $0
    /* 1C82DC 002C82DC 58F80A0C */  jal        func_002be160
    /* 1C82E0 002C82E0 00000000 */   nop
    /* 1C82E4 002C82E4 01000324 */  addiu      $3, $0, 0x1
    /* 1C82E8 002C82E8 19004314 */  bne        $2, $3, .L002C8350
    /* 1C82EC 002C82EC 00000000 */   nop
    /* 1C82F0 002C82F0 2D200002 */  daddu      $4, $16, $0
    /* 1C82F4 002C82F4 D41A040C */  jal        func_00106b50
    /* 1C82F8 002C82F8 00000000 */   nop
    /* 1C82FC 002C82FC 0F00033C */  lui        $3, (0xFFF00 >> 16)
    /* 1C8300 002C8300 00FF6334 */  ori        $3, $3, (0xFFF00 & 0xFFFF)
    /* 1C8304 002C8304 24104300 */  and        $2, $2, $3
    /* 1C8308 002C8308 03920200 */  sra        $18, $2, 8
    /* 1C830C 002C830C 2D200002 */  daddu      $4, $16, $0
    /* 1C8310 002C8310 D41A040C */  jal        func_00106b50
    /* 1C8314 002C8314 00000000 */   nop
    /* 1C8318 002C8318 FF004530 */  andi       $5, $2, 0xFF
    /* 1C831C 002C831C 2D204002 */  daddu      $4, $18, $0
    /* 1C8320 002C8320 58F80A0C */  jal        func_002be160
    /* 1C8324 002C8324 00000000 */   nop
    /* 1C8328 002C8328 01000324 */  addiu      $3, $0, 0x1
    /* 1C832C 002C832C 08004314 */  bne        $2, $3, .L002C8350
    /* 1C8330 002C8330 00000000 */   nop
    /* 1C8334 002C8334 160C2286 */  lh         $2, 0xC16($17)
    /* 1C8338 002C8338 40100200 */  sll        $2, $2, 1
    /* 1C833C 002C833C 21102202 */  addu       $2, $17, $2
    /* 1C8340 002C8340 160050A4 */  sh         $16, 0x16($2)
    /* 1C8344 002C8344 160C2286 */  lh         $2, 0xC16($17)
    /* 1C8348 002C8348 01004224 */  addiu      $2, $2, 0x1
    /* 1C834C 002C834C 160C22A6 */  sh         $2, 0xC16($17)
  .L002C8350:
    /* 1C8350 002C8350 01000226 */  addiu      $2, $16, 0x1
    /* 1C8354 002C8354 3C840200 */  dsll32     $16, $2, 16
    /* 1C8358 002C8358 3F841000 */  dsra32     $16, $16, 16
  .L002C835C:
    /* 1C835C 002C835C 3C241000 */  dsll32     $4, $16, 16
    /* 1C8360 002C8360 3F240400 */  dsra32     $4, $4, 16
    /* 1C8364 002C8364 FF028228 */  slti       $2, $4, 0x2FF
    /* 1C8368 002C8368 CBFF4014 */  bnez       $2, .L002C8298
    /* 1C836C 002C836C 00000000 */   nop
    /* 1C8370 002C8370 11002282 */  lb         $2, 0x11($17)
    /* 1C8374 002C8374 80100200 */  sll        $2, $2, 2
    /* 1C8378 002C8378 21105100 */  addu       $2, $2, $17
    /* 1C837C 002C837C 180F448C */  lw         $4, 0xF18($2)
    /* 1C8380 002C8380 0400053C */  lui        $5, (0x40000 >> 16)
    /* 1C8384 002C8384 2D300000 */  daddu      $6, $0, $0
    /* 1C8388 002C8388 04000724 */  addiu      $7, $0, 0x4
    /* 1C838C 002C838C 2D400000 */  daddu      $8, $0, $0
    /* 1C8390 002C8390 588D0B0C */  jal        func_002e3560
    /* 1C8394 002C8394 00000000 */   nop
    /* 1C8398 002C8398 200C20AE */  sw         $0, 0xC20($17)
    /* 1C839C 002C839C 11002282 */  lb         $2, 0x11($17)
    /* 1C83A0 002C83A0 80100200 */  sll        $2, $2, 2
    /* 1C83A4 002C83A4 21105100 */  addu       $2, $2, $17
    /* 1C83A8 002C83A8 180F448C */  lw         $4, 0xF18($2)
    /* 1C83AC 002C83AC C0890B0C */  jal        func_002e2700
    /* 1C83B0 002C83B0 00000000 */   nop
    /* 1C83B4 002C83B4 02002486 */  lh         $4, 0x2($17)
    /* 1C83B8 002C83B8 2D280000 */  daddu      $5, $0, $0
    /* 1C83BC 002C83BC 2D304000 */  daddu      $6, $2, $0
    /* 1C83C0 002C83C0 2D380000 */  daddu      $7, $0, $0
    /* 1C83C4 002C83C4 01000824 */  addiu      $8, $0, 0x1
    /* 1C83C8 002C83C8 2CCB0A0C */  jal        func_002b2cb0
    /* 1C83CC 002C83CC 00000000 */   nop
    /* 1C83D0 002C83D0 020022A6 */  sh         $2, 0x2($17)
    /* 1C83D4 002C83D4 04003286 */  lh         $18, 0x4($17)
    /* 1C83D8 002C83D8 11002282 */  lb         $2, 0x11($17)
    /* 1C83DC 002C83DC 80100200 */  sll        $2, $2, 2
    /* 1C83E0 002C83E0 21105100 */  addu       $2, $2, $17
    /* 1C83E4 002C83E4 180F448C */  lw         $4, 0xF18($2)
    /* 1C83E8 002C83E8 BC890B0C */  jal        func_002e26f0
    /* 1C83EC 002C83EC 00000000 */   nop
    /* 1C83F0 002C83F0 2D804000 */  daddu      $16, $2, $0
    /* 1C83F4 002C83F4 11002282 */  lb         $2, 0x11($17)
    /* 1C83F8 002C83F8 80100200 */  sll        $2, $2, 2
    /* 1C83FC 002C83FC 21105100 */  addu       $2, $2, $17
    /* 1C8400 002C8400 180F448C */  lw         $4, 0xF18($2)
    /* 1C8404 002C8404 C0890B0C */  jal        func_002e2700
    /* 1C8408 002C8408 00000000 */   nop
    /* 1C840C 002C840C 04002486 */  lh         $4, 0x4($17)
    /* 1C8410 002C8410 05000524 */  addiu      $5, $0, 0x5
    /* 1C8414 002C8414 2D300002 */  daddu      $6, $16, $0
    /* 1C8418 002C8418 2D384000 */  daddu      $7, $2, $0
    /* 1C841C 002C841C A8CC0A0C */  jal        func_002b32a0
    /* 1C8420 002C8420 00000000 */   nop
    /* 1C8424 002C8424 2A085200 */  slt        $1, $2, $18
    /* 1C8428 002C8428 17002010 */  beqz       $1, .L002C8488
    /* 1C842C 002C842C 00000000 */   nop
    /* 1C8430 002C8430 11002282 */  lb         $2, 0x11($17)
    /* 1C8434 002C8434 80100200 */  sll        $2, $2, 2
    /* 1C8438 002C8438 21105100 */  addu       $2, $2, $17
    /* 1C843C 002C843C 180F448C */  lw         $4, 0xF18($2)
    /* 1C8440 002C8440 BC890B0C */  jal        func_002e26f0
    /* 1C8444 002C8444 00000000 */   nop
    /* 1C8448 002C8448 3C840200 */  dsll32     $16, $2, 16
    /* 1C844C 002C844C 3F841000 */  dsra32     $16, $16, 16
    /* 1C8450 002C8450 11002282 */  lb         $2, 0x11($17)
    /* 1C8454 002C8454 80100200 */  sll        $2, $2, 2
    /* 1C8458 002C8458 21105100 */  addu       $2, $2, $17
    /* 1C845C 002C845C 180F448C */  lw         $4, 0xF18($2)
    /* 1C8460 002C8460 C0890B0C */  jal        func_002e2700
    /* 1C8464 002C8464 00000000 */   nop
    /* 1C8468 002C8468 3C3C0200 */  dsll32     $7, $2, 16
    /* 1C846C 002C846C 3F3C0700 */  dsra32     $7, $7, 16
    /* 1C8470 002C8470 04002486 */  lh         $4, 0x4($17)
    /* 1C8474 002C8474 05000524 */  addiu      $5, $0, 0x5
    /* 1C8478 002C8478 2D300002 */  daddu      $6, $16, $0
    /* 1C847C 002C847C A8CC0A0C */  jal        func_002b32a0
    /* 1C8480 002C8480 00000000 */   nop
    /* 1C8484 002C8484 040022A6 */  sh         $2, 0x4($17)
  .L002C8488:
    /* 1C8488 002C8488 400E248E */  lw         $4, 0xE40($17)
    /* 1C848C 002C848C 2D280000 */  daddu      $5, $0, $0
    /* 1C8490 002C8490 01000624 */  addiu      $6, $0, 0x1
    /* 1C8494 002C8494 3C810B0C */  jal        func_002e04f0
    /* 1C8498 002C8498 00000000 */   nop
    /* 1C849C 002C849C 440E248E */  lw         $4, 0xE44($17)
    /* 1C84A0 002C84A0 2D280000 */  daddu      $5, $0, $0
    /* 1C84A4 002C84A4 01000624 */  addiu      $6, $0, 0x1
    /* 1C84A8 002C84A8 3C810B0C */  jal        func_002e04f0
    /* 1C84AC 002C84AC 00000000 */   nop
    /* 1C84B0 002C84B0 480E248E */  lw         $4, 0xE48($17)
    /* 1C84B4 002C84B4 2D280000 */  daddu      $5, $0, $0
    /* 1C84B8 002C84B8 01000624 */  addiu      $6, $0, 0x1
    /* 1C84BC 002C84BC 3C810B0C */  jal        func_002e04f0
    /* 1C84C0 002C84C0 00000000 */   nop
    /* 1C84C4 002C84C4 11002582 */  lb         $5, 0x11($17)
    /* 1C84C8 002C84C8 2D208002 */  daddu      $4, $20, $0
    /* 1C84CC 002C84CC D8510B0C */  jal        func_002d4760
    /* 1C84D0 002C84D0 00000000 */   nop
    /* 1C84D4 002C84D4 24000224 */  addiu      $2, $0, 0x24
    /* 1C84D8 002C84D8 000022A2 */  sb         $2, 0x0($17)
    /* 1C84DC 002C84DC 240C2382 */  lb         $3, 0xC24($17)
    /* 1C84E0 002C84E0 01000224 */  addiu      $2, $0, 0x1
    /* 1C84E4 002C84E4 04006214 */  bne        $3, $2, .L002C84F8
    /* 1C84E8 002C84E8 00000000 */   nop
    /* 1C84EC 002C84EC 2D208002 */  daddu      $4, $20, $0
    /* 1C84F0 002C84F0 80610B0C */  jal        func_002d8600
    /* 1C84F4 002C84F4 00000000 */   nop
  .L002C84F8:
    /* 1C84F8 002C84F8 160C2286 */  lh         $2, 0xC16($17)
    /* 1C84FC 002C84FC 8A084018 */  blez       $2, .L002CA728
    /* 1C8500 002C8500 00000000 */   nop
    /* 1C8504 002C8504 1A0C20A2 */  sb         $0, 0xC1A($17)
    /* 1C8508 002C8508 2D208002 */  daddu      $4, $20, $0
    /* 1C850C 002C850C 807F0B0C */  jal        func_002dfe00
    /* 1C8510 002C8510 00000000 */   nop
    /* 1C8514 002C8514 29000224 */  addiu      $2, $0, 0x29
    /* 1C8518 002C8518 000022A2 */  sb         $2, 0x0($17)
    /* 1C851C 002C851C 82080010 */  b          .L002CA728
    /* 1C8520 002C8520 00000000 */   nop
  .L002C8524:
    /* 1C8524 002C8524 10002482 */  lb         $4, 0x10($17)
    /* 1C8528 002C8528 54ED0A0C */  jal        func_002bb550
    /* 1C852C 002C852C 00000000 */   nop
    /* 1C8530 002C8530 24000224 */  addiu      $2, $0, 0x24
    /* 1C8534 002C8534 000022A2 */  sb         $2, 0x0($17)
    /* 1C8538 002C8538 240C2382 */  lb         $3, 0xC24($17)
    /* 1C853C 002C853C 01000224 */  addiu      $2, $0, 0x1
    /* 1C8540 002C8540 79086214 */  bne        $3, $2, .L002CA728
    /* 1C8544 002C8544 00000000 */   nop
    /* 1C8548 002C8548 2D208002 */  daddu      $4, $20, $0
    /* 1C854C 002C854C 80610B0C */  jal        func_002d8600
    /* 1C8550 002C8550 00000000 */   nop
    /* 1C8554 002C8554 74080010 */  b          .L002CA728
    /* 1C8558 002C8558 00000000 */   nop
    /* 1C855C 002C855C 2D208002 */  daddu      $4, $20, $0
    /* 1C8560 002C8560 02000524 */  addiu      $5, $0, 0x2
    /* 1C8564 002C8564 E0370B0C */  jal        func_002cdf80
    /* 1C8568 002C8568 00000000 */   nop
    /* 1C856C 002C856C 2D208002 */  daddu      $4, $20, $0
    /* 1C8570 002C8570 EC740B0C */  jal        func_002dd3b0
    /* 1C8574 002C8574 00000000 */   nop
    /* 1C8578 002C8578 10002482 */  lb         $4, 0x10($17)
    /* 1C857C 002C857C A0ED0A0C */  jal        func_002bb680
    /* 1C8580 002C8580 00000000 */   nop
    /* 1C8584 002C8584 06004010 */  beqz       $2, .L002C85A0
    /* 1C8588 002C8588 00000000 */   nop
    /* 1C858C 002C858C 10002482 */  lb         $4, 0x10($17)
    /* 1C8590 002C8590 3CEF0A0C */  jal        func_002bbcf0
    /* 1C8594 002C8594 00000000 */   nop
    /* 1C8598 002C8598 63080010 */  b          .L002CA728
    /* 1C859C 002C859C 00000000 */   nop
  .L002C85A0:
    /* 1C85A0 002C85A0 10002482 */  lb         $4, 0x10($17)
    /* 1C85A4 002C85A4 54ED0A0C */  jal        func_002bb550
    /* 1C85A8 002C85A8 00000000 */   nop
    /* 1C85AC 002C85AC 02000424 */  addiu      $4, $0, 0x2
    /* 1C85B0 002C85B0 6400053C */  lui        $5, %hi(D_0063FAF0)
    /* 1C85B4 002C85B4 F0FAA524 */  addiu      $5, $5, %lo(D_0063FAF0)
    /* 1C85B8 002C85B8 AC6B110C */  jal        func_0045aeb0
    /* 1C85BC 002C85BC 00000000 */   nop
    /* 1C85C0 002C85C0 2A000224 */  addiu      $2, $0, 0x2A
    /* 1C85C4 002C85C4 000022A2 */  sb         $2, 0x0($17)
    /* 1C85C8 002C85C8 57080010 */  b          .L002CA728
    /* 1C85CC 002C85CC 00000000 */   nop
    /* 1C85D0 002C85D0 2D208002 */  daddu      $4, $20, $0
    /* 1C85D4 002C85D4 02000524 */  addiu      $5, $0, 0x2
    /* 1C85D8 002C85D8 E0370B0C */  jal        func_002cdf80
    /* 1C85DC 002C85DC 00000000 */   nop
    /* 1C85E0 002C85E0 2D208002 */  daddu      $4, $20, $0
    /* 1C85E4 002C85E4 EC740B0C */  jal        func_002dd3b0
    /* 1C85E8 002C85E8 00000000 */   nop
    /* 1C85EC 002C85EC 1A0C2482 */  lb         $4, 0xC1A($17)
    /* 1C85F0 002C85F0 01000524 */  addiu      $5, $0, 0x1
    /* 1C85F4 002C85F4 3C000624 */  addiu      $6, $0, 0x3C
    /* 1C85F8 002C85F8 2D380000 */  daddu      $7, $0, $0
    /* 1C85FC 002C85FC 2D40A000 */  daddu      $8, $5, $0
    /* 1C8600 002C8600 2CCB0A0C */  jal        func_002b2cb0
    /* 1C8604 002C8604 00000000 */   nop
    /* 1C8608 002C8608 1A0C22A2 */  sb         $2, 0xC1A($17)
    /* 1C860C 002C860C 3C160200 */  dsll32     $2, $2, 24
    /* 1C8610 002C8610 3F160200 */  dsra32     $2, $2, 24
    /* 1C8614 002C8614 3C004228 */  slti       $2, $2, 0x3C
    /* 1C8618 002C8618 43084014 */  bnez       $2, .L002CA728
    /* 1C861C 002C861C 00000000 */   nop
    /* 1C8620 002C8620 2D208002 */  daddu      $4, $20, $0
    /* 1C8624 002C8624 0A000524 */  addiu      $5, $0, 0xA
    /* 1C8628 002C8628 2D300000 */  daddu      $6, $0, $0
    /* 1C862C 002C862C 2D380000 */  daddu      $7, $0, $0
    /* 1C8630 002C8630 B07F0B0C */  jal        func_002dfec0
    /* 1C8634 002C8634 00000000 */   nop
    /* 1C8638 002C8638 100022A2 */  sb         $2, 0x10($17)
    /* 1C863C 002C863C 2B000224 */  addiu      $2, $0, 0x2B
    /* 1C8640 002C8640 000022A2 */  sb         $2, 0x0($17)
    /* 1C8644 002C8644 1A0C20A2 */  sb         $0, 0xC1A($17)
    /* 1C8648 002C8648 37080010 */  b          .L002CA728
    /* 1C864C 002C864C 00000000 */   nop
    /* 1C8650 002C8650 2D208002 */  daddu      $4, $20, $0
    /* 1C8654 002C8654 02000524 */  addiu      $5, $0, 0x2
    /* 1C8658 002C8658 E0370B0C */  jal        func_002cdf80
    /* 1C865C 002C865C 00000000 */   nop
    /* 1C8660 002C8660 2D208002 */  daddu      $4, $20, $0
    /* 1C8664 002C8664 EC740B0C */  jal        func_002dd3b0
    /* 1C8668 002C8668 00000000 */   nop
    /* 1C866C 002C866C 10002482 */  lb         $4, 0x10($17)
    /* 1C8670 002C8670 A0ED0A0C */  jal        func_002bb680
    /* 1C8674 002C8674 00000000 */   nop
    /* 1C8678 002C8678 06004010 */  beqz       $2, .L002C8694
    /* 1C867C 002C867C 00000000 */   nop
    /* 1C8680 002C8680 10002482 */  lb         $4, 0x10($17)
    /* 1C8684 002C8684 3CEF0A0C */  jal        func_002bbcf0
    /* 1C8688 002C8688 00000000 */   nop
    /* 1C868C 002C868C 26080010 */  b          .L002CA728
    /* 1C8690 002C8690 00000000 */   nop
  .L002C8694:
    /* 1C8694 002C8694 10002482 */  lb         $4, 0x10($17)
    /* 1C8698 002C8698 54ED0A0C */  jal        func_002bb550
    /* 1C869C 002C869C 00000000 */   nop
    /* 1C86A0 002C86A0 180C2286 */  lh         $2, 0xC18($17)
    /* 1C86A4 002C86A4 40100200 */  sll        $2, $2, 1
    /* 1C86A8 002C86A8 21105100 */  addu       $2, $2, $17
    /* 1C86AC 002C86AC 16004284 */  lh         $2, 0x16($2)
    /* 1C86B0 002C86B0 7006A2AF */  sw         $2, 0x670($29)
    /* 1C86B4 002C86B4 7406A0AF */  sw         $0, 0x674($29)
    /* 1C86B8 002C86B8 2D208002 */  daddu      $4, $20, $0
    /* 1C86BC 002C86BC 03000524 */  addiu      $5, $0, 0x3
    /* 1C86C0 002C86C0 7006A627 */  addiu      $6, $29, 0x670
    /* 1C86C4 002C86C4 2D380000 */  daddu      $7, $0, $0
    /* 1C86C8 002C86C8 B07F0B0C */  jal        func_002dfec0
    /* 1C86CC 002C86CC 00000000 */   nop
    /* 1C86D0 002C86D0 100022A2 */  sb         $2, 0x10($17)
    /* 1C86D4 002C86D4 2D000224 */  addiu      $2, $0, 0x2D
    /* 1C86D8 002C86D8 000022A2 */  sb         $2, 0x0($17)
    /* 1C86DC 002C86DC 12080010 */  b          .L002CA728
    /* 1C86E0 002C86E0 00000000 */   nop
    /* 1C86E4 002C86E4 2D208002 */  daddu      $4, $20, $0
    /* 1C86E8 002C86E8 02000524 */  addiu      $5, $0, 0x2
    /* 1C86EC 002C86EC E0370B0C */  jal        func_002cdf80
    /* 1C86F0 002C86F0 00000000 */   nop
    /* 1C86F4 002C86F4 2D208002 */  daddu      $4, $20, $0
    /* 1C86F8 002C86F8 EC740B0C */  jal        func_002dd3b0
    /* 1C86FC 002C86FC 00000000 */   nop
    /* 1C8700 002C8700 180C2286 */  lh         $2, 0xC18($17)
    /* 1C8704 002C8704 40100200 */  sll        $2, $2, 1
    /* 1C8708 002C8708 21105100 */  addu       $2, $2, $17
    /* 1C870C 002C870C 16004284 */  lh         $2, 0x16($2)
    /* 1C8710 002C8710 6806A2AF */  sw         $2, 0x668($29)
    /* 1C8714 002C8714 6C06A0AF */  sw         $0, 0x66C($29)
    /* 1C8718 002C8718 2D208002 */  daddu      $4, $20, $0
    /* 1C871C 002C871C 03000524 */  addiu      $5, $0, 0x3
    /* 1C8720 002C8720 6806A627 */  addiu      $6, $29, 0x668
    /* 1C8724 002C8724 2D380000 */  daddu      $7, $0, $0
    /* 1C8728 002C8728 B07F0B0C */  jal        func_002dfec0
    /* 1C872C 002C872C 00000000 */   nop
    /* 1C8730 002C8730 100022A2 */  sb         $2, 0x10($17)
    /* 1C8734 002C8734 2D000224 */  addiu      $2, $0, 0x2D
    /* 1C8738 002C8738 000022A2 */  sb         $2, 0x0($17)
    /* 1C873C 002C873C FA070010 */  b          .L002CA728
    /* 1C8740 002C8740 00000000 */   nop
    /* 1C8744 002C8744 2D208002 */  daddu      $4, $20, $0
    /* 1C8748 002C8748 02000524 */  addiu      $5, $0, 0x2
    /* 1C874C 002C874C E0370B0C */  jal        func_002cdf80
    /* 1C8750 002C8750 00000000 */   nop
    /* 1C8754 002C8754 2D208002 */  daddu      $4, $20, $0
    /* 1C8758 002C8758 EC740B0C */  jal        func_002dd3b0
    /* 1C875C 002C875C 00000000 */   nop
    /* 1C8760 002C8760 10002482 */  lb         $4, 0x10($17)
    /* 1C8764 002C8764 A0ED0A0C */  jal        func_002bb680
    /* 1C8768 002C8768 00000000 */   nop
    /* 1C876C 002C876C 06004010 */  beqz       $2, .L002C8788
    /* 1C8770 002C8770 00000000 */   nop
    /* 1C8774 002C8774 10002482 */  lb         $4, 0x10($17)
    /* 1C8778 002C8778 3CEF0A0C */  jal        func_002bbcf0
    /* 1C877C 002C877C 00000000 */   nop
    /* 1C8780 002C8780 E9070010 */  b          .L002CA728
    /* 1C8784 002C8784 00000000 */   nop
  .L002C8788:
    /* 1C8788 002C8788 180C2286 */  lh         $2, 0xC18($17)
    /* 1C878C 002C878C 40100200 */  sll        $2, $2, 1
    /* 1C8790 002C8790 21105100 */  addu       $2, $2, $17
    /* 1C8794 002C8794 16004484 */  lh         $4, 0x16($2)
    /* 1C8798 002C8798 0C42040C */  jal        func_00110830
    /* 1C879C 002C879C 00000000 */   nop
    /* 1C87A0 002C87A0 FF004330 */  andi       $3, $2, 0xFF
    /* 1C87A4 002C87A4 180C2286 */  lh         $2, 0xC18($17)
    /* 1C87A8 002C87A8 40100200 */  sll        $2, $2, 1
    /* 1C87AC 002C87AC 21105100 */  addu       $2, $2, $17
    /* 1C87B0 002C87B0 16004484 */  lh         $4, 0x16($2)
    /* 1C87B4 002C87B4 01006234 */  ori        $2, $3, 0x1
    /* 1C87B8 002C87B8 FF004530 */  andi       $5, $2, 0xFF
    /* 1C87BC 002C87BC 0442040C */  jal        func_00110810
    /* 1C87C0 002C87C0 00000000 */   nop
    /* 1C87C4 002C87C4 10002482 */  lb         $4, 0x10($17)
    /* 1C87C8 002C87C8 54ED0A0C */  jal        func_002bb550
    /* 1C87CC 002C87CC 00000000 */   nop
    /* 1C87D0 002C87D0 180C2286 */  lh         $2, 0xC18($17)
    /* 1C87D4 002C87D4 01004224 */  addiu      $2, $2, 0x1
    /* 1C87D8 002C87D8 180C22A6 */  sh         $2, 0xC18($17)
    /* 1C87DC 002C87DC 3C1C0200 */  dsll32     $3, $2, 16
    /* 1C87E0 002C87E0 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C87E4 002C87E4 160C2286 */  lh         $2, 0xC16($17)
    /* 1C87E8 002C87E8 2A106200 */  slt        $2, $3, $2
    /* 1C87EC 002C87EC 0B004014 */  bnez       $2, .L002C881C
    /* 1C87F0 002C87F0 00000000 */   nop
    /* 1C87F4 002C87F4 24000224 */  addiu      $2, $0, 0x24
    /* 1C87F8 002C87F8 000022A2 */  sb         $2, 0x0($17)
    /* 1C87FC 002C87FC 240C2382 */  lb         $3, 0xC24($17)
    /* 1C8800 002C8800 01000224 */  addiu      $2, $0, 0x1
    /* 1C8804 002C8804 C8076214 */  bne        $3, $2, .L002CA728
    /* 1C8808 002C8808 00000000 */   nop
    /* 1C880C 002C880C 31000224 */  addiu      $2, $0, 0x31
    /* 1C8810 002C8810 000022A2 */  sb         $2, 0x0($17)
    /* 1C8814 002C8814 C4070010 */  b          .L002CA728
    /* 1C8818 002C8818 00000000 */   nop
  .L002C881C:
    /* 1C881C 002C881C 2D208002 */  daddu      $4, $20, $0
    /* 1C8820 002C8820 807F0B0C */  jal        func_002dfe00
    /* 1C8824 002C8824 00000000 */   nop
    /* 1C8828 002C8828 29000224 */  addiu      $2, $0, 0x29
    /* 1C882C 002C882C 000022A2 */  sb         $2, 0x0($17)
    /* 1C8830 002C8830 BD070010 */  b          .L002CA728
    /* 1C8834 002C8834 00000000 */   nop
    /* 1C8838 002C8838 2D208002 */  daddu      $4, $20, $0
    /* 1C883C 002C883C 02000524 */  addiu      $5, $0, 0x2
    /* 1C8840 002C8840 E0370B0C */  jal        func_002cdf80
    /* 1C8844 002C8844 00000000 */   nop
    /* 1C8848 002C8848 2DA00000 */  daddu      $20, $0, $0
    /* 1C884C 002C884C 9A000010 */  b          .L002C8AB8
    /* 1C8850 002C8850 00000000 */   nop
  .L002C8854:
    /* 1C8854 002C8854 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8858 002C8858 38810B0C */  jal        func_002e04e0
    /* 1C885C 002C885C 00000000 */   nop
    /* 1C8860 002C8860 2D984000 */  daddu      $19, $2, $0
    /* 1C8864 002C8864 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8868 002C8868 38810B0C */  jal        func_002e04e0
    /* 1C886C 002C886C 00000000 */   nop
    /* 1C8870 002C8870 2D904000 */  daddu      $18, $2, $0
    /* 1C8874 002C8874 3C141400 */  dsll32     $2, $20, 16
    /* 1C8878 002C8878 3F140200 */  dsra32     $2, $2, 16
    /* 1C887C 002C887C 80100200 */  sll        $2, $2, 2
    /* 1C8880 002C8880 21802202 */  addu       $16, $17, $2
    /* 1C8884 002C8884 3E0F0292 */  lbu        $2, 0xF3E($16)
    /* 1C8888 002C8888 06004004 */  bltz       $2, .L002C88A4
    /* 1C888C 002C888C 00000000 */   nop
    /* 1C8890 002C8890 00008244 */  mtc1       $2, $f0
    /* 1C8894 002C8894 00000000 */  nop
    /* 1C8898 002C8898 20038046 */  cvt.s.w    $f12, $f0
    /* 1C889C 002C889C 08000010 */  b          .L002C88C0
    /* 1C88A0 002C88A0 00000000 */   nop
  .L002C88A4:
    /* 1C88A4 002C88A4 42180200 */  srl        $3, $2, 1
    /* 1C88A8 002C88A8 01004230 */  andi       $2, $2, 0x1
    /* 1C88AC 002C88AC 25186200 */  or         $3, $3, $2
    /* 1C88B0 002C88B0 00008344 */  mtc1       $3, $f0
    /* 1C88B4 002C88B4 00000000 */  nop
    /* 1C88B8 002C88B8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C88BC 002C88BC 00630C46 */  add.s      $f12, $f12, $f12
  .L002C88C0:
    /* 1C88C0 002C88C0 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C88C4 002C88C4 00008244 */  mtc1       $2, $f0
    /* 1C88C8 002C88C8 00000000 */  nop
    /* 1C88CC 002C88CC A0038046 */  cvt.s.w    $f14, $f0
    /* 1C88D0 002C88D0 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C88D4 002C88D4 00688244 */  mtc1       $2, $f13
    /* 1C88D8 002C88D8 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C88DC 002C88DC 00788244 */  mtc1       $2, $f15
    /* 1C88E0 002C88E0 01000424 */  addiu      $4, $0, 0x1
    /* 1C88E4 002C88E4 A8CA0A0C */  jal        func_002b2aa0
    /* 1C88E8 002C88E8 00000000 */   nop
    /* 1C88EC 002C88EC 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C88F0 002C88F0 00088244 */  mtc1       $2, $f1
    /* 1C88F4 002C88F4 00000000 */  nop
    /* 1C88F8 002C88F8 36080046 */  c.le.s     $f1, $f0
    /* 1C88FC 002C88FC 07000145 */  bc1t       .L002C891C
    /* 1C8900 002C8900 00000000 */   nop
    /* 1C8904 002C8904 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8908 002C8908 00000344 */  mfc1       $3, $f0
    /* 1C890C 002C890C 00000000 */  nop
    /* 1C8910 002C8910 FF006330 */  andi       $3, $3, 0xFF
    /* 1C8914 002C8914 07000010 */  b          .L002C8934
    /* 1C8918 002C8918 00000000 */   nop
  .L002C891C:
    /* 1C891C 002C891C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C8920 002C8920 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8924 002C8924 00000344 */  mfc1       $3, $f0
    /* 1C8928 002C8928 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C892C 002C892C 25186200 */  or         $3, $3, $2
    /* 1C8930 002C8930 FF006330 */  andi       $3, $3, 0xFF
  .L002C8934:
    /* 1C8934 002C8934 790043A2 */  sb         $3, 0x79($18)
    /* 1C8938 002C8938 790063A2 */  sb         $3, 0x79($19)
    /* 1C893C 002C893C 3F0F0292 */  lbu        $2, 0xF3F($16)
    /* 1C8940 002C8940 06004004 */  bltz       $2, .L002C895C
    /* 1C8944 002C8944 00000000 */   nop
    /* 1C8948 002C8948 00008244 */  mtc1       $2, $f0
    /* 1C894C 002C894C 00000000 */  nop
    /* 1C8950 002C8950 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8954 002C8954 08000010 */  b          .L002C8978
    /* 1C8958 002C8958 00000000 */   nop
  .L002C895C:
    /* 1C895C 002C895C 42180200 */  srl        $3, $2, 1
    /* 1C8960 002C8960 01004230 */  andi       $2, $2, 0x1
    /* 1C8964 002C8964 25186200 */  or         $3, $3, $2
    /* 1C8968 002C8968 00008344 */  mtc1       $3, $f0
    /* 1C896C 002C896C 00000000 */  nop
    /* 1C8970 002C8970 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8974 002C8974 00630C46 */  add.s      $f12, $f12, $f12
  .L002C8978:
    /* 1C8978 002C8978 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C897C 002C897C 00008244 */  mtc1       $2, $f0
    /* 1C8980 002C8980 00000000 */  nop
    /* 1C8984 002C8984 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C8988 002C8988 6243023C */  lui        $2, (0x43620000 >> 16)
    /* 1C898C 002C898C 00688244 */  mtc1       $2, $f13
    /* 1C8990 002C8990 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C8994 002C8994 00788244 */  mtc1       $2, $f15
    /* 1C8998 002C8998 01000424 */  addiu      $4, $0, 0x1
    /* 1C899C 002C899C A8CA0A0C */  jal        func_002b2aa0
    /* 1C89A0 002C89A0 00000000 */   nop
    /* 1C89A4 002C89A4 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C89A8 002C89A8 00088244 */  mtc1       $2, $f1
    /* 1C89AC 002C89AC 00000000 */  nop
    /* 1C89B0 002C89B0 36080046 */  c.le.s     $f1, $f0
    /* 1C89B4 002C89B4 07000145 */  bc1t       .L002C89D4
    /* 1C89B8 002C89B8 00000000 */   nop
    /* 1C89BC 002C89BC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C89C0 002C89C0 00000344 */  mfc1       $3, $f0
    /* 1C89C4 002C89C4 00000000 */  nop
    /* 1C89C8 002C89C8 FF006330 */  andi       $3, $3, 0xFF
    /* 1C89CC 002C89CC 07000010 */  b          .L002C89EC
    /* 1C89D0 002C89D0 00000000 */   nop
  .L002C89D4:
    /* 1C89D4 002C89D4 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C89D8 002C89D8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C89DC 002C89DC 00000344 */  mfc1       $3, $f0
    /* 1C89E0 002C89E0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C89E4 002C89E4 25186200 */  or         $3, $3, $2
    /* 1C89E8 002C89E8 FF006330 */  andi       $3, $3, 0xFF
  .L002C89EC:
    /* 1C89EC 002C89EC 7A0043A2 */  sb         $3, 0x7A($18)
    /* 1C89F0 002C89F0 7A0063A2 */  sb         $3, 0x7A($19)
    /* 1C89F4 002C89F4 400F0292 */  lbu        $2, 0xF40($16)
    /* 1C89F8 002C89F8 06004004 */  bltz       $2, .L002C8A14
    /* 1C89FC 002C89FC 00000000 */   nop
    /* 1C8A00 002C8A00 00008244 */  mtc1       $2, $f0
    /* 1C8A04 002C8A04 00000000 */  nop
    /* 1C8A08 002C8A08 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8A0C 002C8A0C 08000010 */  b          .L002C8A30
    /* 1C8A10 002C8A10 00000000 */   nop
  .L002C8A14:
    /* 1C8A14 002C8A14 42180200 */  srl        $3, $2, 1
    /* 1C8A18 002C8A18 01004230 */  andi       $2, $2, 0x1
    /* 1C8A1C 002C8A1C 25186200 */  or         $3, $3, $2
    /* 1C8A20 002C8A20 00008344 */  mtc1       $3, $f0
    /* 1C8A24 002C8A24 00000000 */  nop
    /* 1C8A28 002C8A28 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8A2C 002C8A2C 00630C46 */  add.s      $f12, $f12, $f12
  .L002C8A30:
    /* 1C8A30 002C8A30 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C8A34 002C8A34 00008244 */  mtc1       $2, $f0
    /* 1C8A38 002C8A38 00000000 */  nop
    /* 1C8A3C 002C8A3C A0038046 */  cvt.s.w    $f14, $f0
    /* 1C8A40 002C8A40 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1C8A44 002C8A44 00688244 */  mtc1       $2, $f13
    /* 1C8A48 002C8A48 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C8A4C 002C8A4C 00788244 */  mtc1       $2, $f15
    /* 1C8A50 002C8A50 01000424 */  addiu      $4, $0, 0x1
    /* 1C8A54 002C8A54 A8CA0A0C */  jal        func_002b2aa0
    /* 1C8A58 002C8A58 00000000 */   nop
    /* 1C8A5C 002C8A5C 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C8A60 002C8A60 00088244 */  mtc1       $2, $f1
    /* 1C8A64 002C8A64 00000000 */  nop
    /* 1C8A68 002C8A68 36080046 */  c.le.s     $f1, $f0
    /* 1C8A6C 002C8A6C 07000145 */  bc1t       .L002C8A8C
    /* 1C8A70 002C8A70 00000000 */   nop
    /* 1C8A74 002C8A74 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8A78 002C8A78 00000344 */  mfc1       $3, $f0
    /* 1C8A7C 002C8A7C 00000000 */  nop
    /* 1C8A80 002C8A80 FF006330 */  andi       $3, $3, 0xFF
    /* 1C8A84 002C8A84 07000010 */  b          .L002C8AA4
    /* 1C8A88 002C8A88 00000000 */   nop
  .L002C8A8C:
    /* 1C8A8C 002C8A8C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C8A90 002C8A90 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8A94 002C8A94 00000344 */  mfc1       $3, $f0
    /* 1C8A98 002C8A98 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C8A9C 002C8A9C 25186200 */  or         $3, $3, $2
    /* 1C8AA0 002C8AA0 FF006330 */  andi       $3, $3, 0xFF
  .L002C8AA4:
    /* 1C8AA4 002C8AA4 7B0043A2 */  sb         $3, 0x7B($18)
    /* 1C8AA8 002C8AA8 7B0063A2 */  sb         $3, 0x7B($19)
    /* 1C8AAC 002C8AAC 01008226 */  addiu      $2, $20, 0x1
    /* 1C8AB0 002C8AB0 3CA40200 */  dsll32     $20, $2, 16
    /* 1C8AB4 002C8AB4 3FA41400 */  dsra32     $20, $20, 16
  .L002C8AB8:
    /* 1C8AB8 002C8AB8 3C141400 */  dsll32     $2, $20, 16
    /* 1C8ABC 002C8ABC 3F140200 */  dsra32     $2, $2, 16
    /* 1C8AC0 002C8AC0 02004228 */  slti       $2, $2, 0x2
    /* 1C8AC4 002C8AC4 63FF4014 */  bnez       $2, .L002C8854
    /* 1C8AC8 002C8AC8 00000000 */   nop
    /* 1C8ACC 002C8ACC 3C0F2486 */  lh         $4, 0xF3C($17)
    /* 1C8AD0 002C8AD0 06008128 */  slti       $1, $4, 0x6
    /* 1C8AD4 002C8AD4 0A002010 */  beqz       $1, .L002C8B00
    /* 1C8AD8 002C8AD8 00000000 */   nop
    /* 1C8ADC 002C8ADC 01000524 */  addiu      $5, $0, 0x1
    /* 1C8AE0 002C8AE0 06000624 */  addiu      $6, $0, 0x6
    /* 1C8AE4 002C8AE4 2D380000 */  daddu      $7, $0, $0
    /* 1C8AE8 002C8AE8 2D40A000 */  daddu      $8, $5, $0
    /* 1C8AEC 002C8AEC 2CCB0A0C */  jal        func_002b2cb0
    /* 1C8AF0 002C8AF0 00000000 */   nop
    /* 1C8AF4 002C8AF4 3C0F22A6 */  sh         $2, 0xF3C($17)
    /* 1C8AF8 002C8AF8 0B070010 */  b          .L002CA728
    /* 1C8AFC 002C8AFC 00000000 */   nop
  .L002C8B00:
    /* 1C8B00 002C8B00 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8B04 002C8B04 38810B0C */  jal        func_002e04e0
    /* 1C8B08 002C8B08 00000000 */   nop
    /* 1C8B0C 002C8B0C 3E0F2692 */  lbu        $6, 0xF3E($17)
    /* 1C8B10 002C8B10 3F0F2592 */  lbu        $5, 0xF3F($17)
    /* 1C8B14 002C8B14 400F2492 */  lbu        $4, 0xF40($17)
    /* 1C8B18 002C8B18 410F2392 */  lbu        $3, 0xF41($17)
    /* 1C8B1C 002C8B1C 790046A0 */  sb         $6, 0x79($2)
    /* 1C8B20 002C8B20 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C8B24 002C8B24 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C8B28 002C8B28 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C8B2C 002C8B2C D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8B30 002C8B30 38810B0C */  jal        func_002e04e0
    /* 1C8B34 002C8B34 00000000 */   nop
    /* 1C8B38 002C8B38 420F2692 */  lbu        $6, 0xF42($17)
    /* 1C8B3C 002C8B3C 430F2592 */  lbu        $5, 0xF43($17)
    /* 1C8B40 002C8B40 440F2492 */  lbu        $4, 0xF44($17)
    /* 1C8B44 002C8B44 450F2392 */  lbu        $3, 0xF45($17)
    /* 1C8B48 002C8B48 790046A0 */  sb         $6, 0x79($2)
    /* 1C8B4C 002C8B4C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C8B50 002C8B50 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C8B54 002C8B54 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C8B58 002C8B58 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8B5C 002C8B5C 38810B0C */  jal        func_002e04e0
    /* 1C8B60 002C8B60 00000000 */   nop
    /* 1C8B64 002C8B64 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C8B68 002C8B68 300040C4 */  lwc1       $f0, 0x30($2)
    /* 1C8B6C 002C8B6C 6006A1E7 */  swc1       $f1, 0x660($29)
    /* 1C8B70 002C8B70 6406A0E7 */  swc1       $f0, 0x664($29)
    /* 1C8B74 002C8B74 6006A1C7 */  lwc1       $f1, 0x660($29)
    /* 1C8B78 002C8B78 7A44023C */  lui        $2, (0x447A0000 >> 16)
    /* 1C8B7C 002C8B7C 00008244 */  mtc1       $2, $f0
    /* 1C8B80 002C8B80 00000000 */  nop
    /* 1C8B84 002C8B84 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C8B88 002C8B88 4802A427 */  addiu      $4, $29, 0x248
    /* 1C8B8C 002C8B8C 6406ADC7 */  lwc1       $f13, 0x664($29)
    /* 1C8B90 002C8B90 5CCA0A0C */  jal        func_002b2970
    /* 1C8B94 002C8B94 00000000 */   nop
    /* 1C8B98 002C8B98 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8B9C 002C8B9C 6006A5DF */  ld         $5, 0x660($29)
    /* 1C8BA0 002C8BA0 4802A6DF */  ld         $6, 0x248($29)
    /* 1C8BA4 002C8BA4 01000724 */  addiu      $7, $0, 0x1
    /* 1C8BA8 002C8BA8 03000824 */  addiu      $8, $0, 0x3
    /* 1C8BAC 002C8BAC 2D480000 */  daddu      $9, $0, $0
    /* 1C8BB0 002C8BB0 88810B0C */  jal        func_002e0620
    /* 1C8BB4 002C8BB4 00000000 */   nop
    /* 1C8BB8 002C8BB8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8BBC 002C8BBC 38810B0C */  jal        func_002e04e0
    /* 1C8BC0 002C8BC0 00000000 */   nop
    /* 1C8BC4 002C8BC4 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C8BC8 002C8BC8 300040C4 */  lwc1       $f0, 0x30($2)
    /* 1C8BCC 002C8BCC 6001A1E7 */  swc1       $f1, 0x160($29)
    /* 1C8BD0 002C8BD0 6401A0E7 */  swc1       $f0, 0x164($29)
    /* 1C8BD4 002C8BD4 6001A1C7 */  lwc1       $f1, 0x160($29)
    /* 1C8BD8 002C8BD8 7A44023C */  lui        $2, (0x447A0000 >> 16)
    /* 1C8BDC 002C8BDC 00008244 */  mtc1       $2, $f0
    /* 1C8BE0 002C8BE0 00000000 */  nop
    /* 1C8BE4 002C8BE4 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C8BE8 002C8BE8 4002A427 */  addiu      $4, $29, 0x240
    /* 1C8BEC 002C8BEC 6401ADC7 */  lwc1       $f13, 0x164($29)
    /* 1C8BF0 002C8BF0 5CCA0A0C */  jal        func_002b2970
    /* 1C8BF4 002C8BF4 00000000 */   nop
    /* 1C8BF8 002C8BF8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8BFC 002C8BFC 6001A5DF */  ld         $5, 0x160($29)
    /* 1C8C00 002C8C00 4002A6DF */  ld         $6, 0x240($29)
    /* 1C8C04 002C8C04 01000724 */  addiu      $7, $0, 0x1
    /* 1C8C08 002C8C08 03000824 */  addiu      $8, $0, 0x3
    /* 1C8C0C 002C8C0C 2D480000 */  daddu      $9, $0, $0
    /* 1C8C10 002C8C10 88810B0C */  jal        func_002e0620
    /* 1C8C14 002C8C14 00000000 */   nop
    /* 1C8C18 002C8C18 2F000224 */  addiu      $2, $0, 0x2F
    /* 1C8C1C 002C8C1C 000022A2 */  sb         $2, 0x0($17)
    /* 1C8C20 002C8C20 C1060010 */  b          .L002CA728
    /* 1C8C24 002C8C24 00000000 */   nop
    /* 1C8C28 002C8C28 2D208002 */  daddu      $4, $20, $0
    /* 1C8C2C 002C8C2C 02000524 */  addiu      $5, $0, 0x2
    /* 1C8C30 002C8C30 E0370B0C */  jal        func_002cdf80
    /* 1C8C34 002C8C34 00000000 */   nop
    /* 1C8C38 002C8C38 2DA00000 */  daddu      $20, $0, $0
    /* 1C8C3C 002C8C3C 9A000010 */  b          .L002C8EA8
    /* 1C8C40 002C8C40 00000000 */   nop
  .L002C8C44:
    /* 1C8C44 002C8C44 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8C48 002C8C48 38810B0C */  jal        func_002e04e0
    /* 1C8C4C 002C8C4C 00000000 */   nop
    /* 1C8C50 002C8C50 2D984000 */  daddu      $19, $2, $0
    /* 1C8C54 002C8C54 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8C58 002C8C58 38810B0C */  jal        func_002e04e0
    /* 1C8C5C 002C8C5C 00000000 */   nop
    /* 1C8C60 002C8C60 2D904000 */  daddu      $18, $2, $0
    /* 1C8C64 002C8C64 3C141400 */  dsll32     $2, $20, 16
    /* 1C8C68 002C8C68 3F140200 */  dsra32     $2, $2, 16
    /* 1C8C6C 002C8C6C 80100200 */  sll        $2, $2, 2
    /* 1C8C70 002C8C70 21802202 */  addu       $16, $17, $2
    /* 1C8C74 002C8C74 3E0F0292 */  lbu        $2, 0xF3E($16)
    /* 1C8C78 002C8C78 06004004 */  bltz       $2, .L002C8C94
    /* 1C8C7C 002C8C7C 00000000 */   nop
    /* 1C8C80 002C8C80 00008244 */  mtc1       $2, $f0
    /* 1C8C84 002C8C84 00000000 */  nop
    /* 1C8C88 002C8C88 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8C8C 002C8C8C 08000010 */  b          .L002C8CB0
    /* 1C8C90 002C8C90 00000000 */   nop
  .L002C8C94:
    /* 1C8C94 002C8C94 42180200 */  srl        $3, $2, 1
    /* 1C8C98 002C8C98 01004230 */  andi       $2, $2, 0x1
    /* 1C8C9C 002C8C9C 25186200 */  or         $3, $3, $2
    /* 1C8CA0 002C8CA0 00008344 */  mtc1       $3, $f0
    /* 1C8CA4 002C8CA4 00000000 */  nop
    /* 1C8CA8 002C8CA8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8CAC 002C8CAC 00630C46 */  add.s      $f12, $f12, $f12
  .L002C8CB0:
    /* 1C8CB0 002C8CB0 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C8CB4 002C8CB4 00008244 */  mtc1       $2, $f0
    /* 1C8CB8 002C8CB8 00000000 */  nop
    /* 1C8CBC 002C8CBC A0038046 */  cvt.s.w    $f14, $f0
    /* 1C8CC0 002C8CC0 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1C8CC4 002C8CC4 00688244 */  mtc1       $2, $f13
    /* 1C8CC8 002C8CC8 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C8CCC 002C8CCC 00788244 */  mtc1       $2, $f15
    /* 1C8CD0 002C8CD0 01000424 */  addiu      $4, $0, 0x1
    /* 1C8CD4 002C8CD4 A8CA0A0C */  jal        func_002b2aa0
    /* 1C8CD8 002C8CD8 00000000 */   nop
    /* 1C8CDC 002C8CDC 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C8CE0 002C8CE0 00088244 */  mtc1       $2, $f1
    /* 1C8CE4 002C8CE4 00000000 */  nop
    /* 1C8CE8 002C8CE8 36080046 */  c.le.s     $f1, $f0
    /* 1C8CEC 002C8CEC 07000145 */  bc1t       .L002C8D0C
    /* 1C8CF0 002C8CF0 00000000 */   nop
    /* 1C8CF4 002C8CF4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8CF8 002C8CF8 00000344 */  mfc1       $3, $f0
    /* 1C8CFC 002C8CFC 00000000 */  nop
    /* 1C8D00 002C8D00 FF006330 */  andi       $3, $3, 0xFF
    /* 1C8D04 002C8D04 07000010 */  b          .L002C8D24
    /* 1C8D08 002C8D08 00000000 */   nop
  .L002C8D0C:
    /* 1C8D0C 002C8D0C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C8D10 002C8D10 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8D14 002C8D14 00000344 */  mfc1       $3, $f0
    /* 1C8D18 002C8D18 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C8D1C 002C8D1C 25186200 */  or         $3, $3, $2
    /* 1C8D20 002C8D20 FF006330 */  andi       $3, $3, 0xFF
  .L002C8D24:
    /* 1C8D24 002C8D24 790043A2 */  sb         $3, 0x79($18)
    /* 1C8D28 002C8D28 790063A2 */  sb         $3, 0x79($19)
    /* 1C8D2C 002C8D2C 3F0F0292 */  lbu        $2, 0xF3F($16)
    /* 1C8D30 002C8D30 06004004 */  bltz       $2, .L002C8D4C
    /* 1C8D34 002C8D34 00000000 */   nop
    /* 1C8D38 002C8D38 00008244 */  mtc1       $2, $f0
    /* 1C8D3C 002C8D3C 00000000 */  nop
    /* 1C8D40 002C8D40 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8D44 002C8D44 08000010 */  b          .L002C8D68
    /* 1C8D48 002C8D48 00000000 */   nop
  .L002C8D4C:
    /* 1C8D4C 002C8D4C 42180200 */  srl        $3, $2, 1
    /* 1C8D50 002C8D50 01004230 */  andi       $2, $2, 0x1
    /* 1C8D54 002C8D54 25186200 */  or         $3, $3, $2
    /* 1C8D58 002C8D58 00008344 */  mtc1       $3, $f0
    /* 1C8D5C 002C8D5C 00000000 */  nop
    /* 1C8D60 002C8D60 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8D64 002C8D64 00630C46 */  add.s      $f12, $f12, $f12
  .L002C8D68:
    /* 1C8D68 002C8D68 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C8D6C 002C8D6C 00008244 */  mtc1       $2, $f0
    /* 1C8D70 002C8D70 00000000 */  nop
    /* 1C8D74 002C8D74 A0038046 */  cvt.s.w    $f14, $f0
    /* 1C8D78 002C8D78 6243023C */  lui        $2, (0x43620000 >> 16)
    /* 1C8D7C 002C8D7C 00688244 */  mtc1       $2, $f13
    /* 1C8D80 002C8D80 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C8D84 002C8D84 00788244 */  mtc1       $2, $f15
    /* 1C8D88 002C8D88 01000424 */  addiu      $4, $0, 0x1
    /* 1C8D8C 002C8D8C A8CA0A0C */  jal        func_002b2aa0
    /* 1C8D90 002C8D90 00000000 */   nop
    /* 1C8D94 002C8D94 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C8D98 002C8D98 00088244 */  mtc1       $2, $f1
    /* 1C8D9C 002C8D9C 00000000 */  nop
    /* 1C8DA0 002C8DA0 36080046 */  c.le.s     $f1, $f0
    /* 1C8DA4 002C8DA4 07000145 */  bc1t       .L002C8DC4
    /* 1C8DA8 002C8DA8 00000000 */   nop
    /* 1C8DAC 002C8DAC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8DB0 002C8DB0 00000344 */  mfc1       $3, $f0
    /* 1C8DB4 002C8DB4 00000000 */  nop
    /* 1C8DB8 002C8DB8 FF006330 */  andi       $3, $3, 0xFF
    /* 1C8DBC 002C8DBC 07000010 */  b          .L002C8DDC
    /* 1C8DC0 002C8DC0 00000000 */   nop
  .L002C8DC4:
    /* 1C8DC4 002C8DC4 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C8DC8 002C8DC8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8DCC 002C8DCC 00000344 */  mfc1       $3, $f0
    /* 1C8DD0 002C8DD0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C8DD4 002C8DD4 25186200 */  or         $3, $3, $2
    /* 1C8DD8 002C8DD8 FF006330 */  andi       $3, $3, 0xFF
  .L002C8DDC:
    /* 1C8DDC 002C8DDC 7A0043A2 */  sb         $3, 0x7A($18)
    /* 1C8DE0 002C8DE0 7A0063A2 */  sb         $3, 0x7A($19)
    /* 1C8DE4 002C8DE4 400F0292 */  lbu        $2, 0xF40($16)
    /* 1C8DE8 002C8DE8 06004004 */  bltz       $2, .L002C8E04
    /* 1C8DEC 002C8DEC 00000000 */   nop
    /* 1C8DF0 002C8DF0 00008244 */  mtc1       $2, $f0
    /* 1C8DF4 002C8DF4 00000000 */  nop
    /* 1C8DF8 002C8DF8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8DFC 002C8DFC 08000010 */  b          .L002C8E20
    /* 1C8E00 002C8E00 00000000 */   nop
  .L002C8E04:
    /* 1C8E04 002C8E04 42180200 */  srl        $3, $2, 1
    /* 1C8E08 002C8E08 01004230 */  andi       $2, $2, 0x1
    /* 1C8E0C 002C8E0C 25186200 */  or         $3, $3, $2
    /* 1C8E10 002C8E10 00008344 */  mtc1       $3, $f0
    /* 1C8E14 002C8E14 00000000 */  nop
    /* 1C8E18 002C8E18 20038046 */  cvt.s.w    $f12, $f0
    /* 1C8E1C 002C8E1C 00630C46 */  add.s      $f12, $f12, $f12
  .L002C8E20:
    /* 1C8E20 002C8E20 3C0F2286 */  lh         $2, 0xF3C($17)
    /* 1C8E24 002C8E24 00008244 */  mtc1       $2, $f0
    /* 1C8E28 002C8E28 00000000 */  nop
    /* 1C8E2C 002C8E2C A0038046 */  cvt.s.w    $f14, $f0
    /* 1C8E30 002C8E30 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1C8E34 002C8E34 00688244 */  mtc1       $2, $f13
    /* 1C8E38 002C8E38 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1C8E3C 002C8E3C 00788244 */  mtc1       $2, $f15
    /* 1C8E40 002C8E40 01000424 */  addiu      $4, $0, 0x1
    /* 1C8E44 002C8E44 A8CA0A0C */  jal        func_002b2aa0
    /* 1C8E48 002C8E48 00000000 */   nop
    /* 1C8E4C 002C8E4C 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1C8E50 002C8E50 00088244 */  mtc1       $2, $f1
    /* 1C8E54 002C8E54 00000000 */  nop
    /* 1C8E58 002C8E58 36080046 */  c.le.s     $f1, $f0
    /* 1C8E5C 002C8E5C 07000145 */  bc1t       .L002C8E7C
    /* 1C8E60 002C8E60 00000000 */   nop
    /* 1C8E64 002C8E64 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8E68 002C8E68 00000344 */  mfc1       $3, $f0
    /* 1C8E6C 002C8E6C 00000000 */  nop
    /* 1C8E70 002C8E70 FF006330 */  andi       $3, $3, 0xFF
    /* 1C8E74 002C8E74 07000010 */  b          .L002C8E94
    /* 1C8E78 002C8E78 00000000 */   nop
  .L002C8E7C:
    /* 1C8E7C 002C8E7C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1C8E80 002C8E80 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C8E84 002C8E84 00000344 */  mfc1       $3, $f0
    /* 1C8E88 002C8E88 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1C8E8C 002C8E8C 25186200 */  or         $3, $3, $2
    /* 1C8E90 002C8E90 FF006330 */  andi       $3, $3, 0xFF
  .L002C8E94:
    /* 1C8E94 002C8E94 7B0043A2 */  sb         $3, 0x7B($18)
    /* 1C8E98 002C8E98 7B0063A2 */  sb         $3, 0x7B($19)
    /* 1C8E9C 002C8E9C 01008226 */  addiu      $2, $20, 0x1
    /* 1C8EA0 002C8EA0 3CA40200 */  dsll32     $20, $2, 16
    /* 1C8EA4 002C8EA4 3FA41400 */  dsra32     $20, $20, 16
  .L002C8EA8:
    /* 1C8EA8 002C8EA8 3C141400 */  dsll32     $2, $20, 16
    /* 1C8EAC 002C8EAC 3F140200 */  dsra32     $2, $2, 16
    /* 1C8EB0 002C8EB0 02004228 */  slti       $2, $2, 0x2
    /* 1C8EB4 002C8EB4 63FF4014 */  bnez       $2, .L002C8C44
    /* 1C8EB8 002C8EB8 00000000 */   nop
    /* 1C8EBC 002C8EBC 3C0F2486 */  lh         $4, 0xF3C($17)
    /* 1C8EC0 002C8EC0 06008128 */  slti       $1, $4, 0x6
    /* 1C8EC4 002C8EC4 0A002010 */  beqz       $1, .L002C8EF0
    /* 1C8EC8 002C8EC8 00000000 */   nop
    /* 1C8ECC 002C8ECC 01000524 */  addiu      $5, $0, 0x1
    /* 1C8ED0 002C8ED0 06000624 */  addiu      $6, $0, 0x6
    /* 1C8ED4 002C8ED4 2D380000 */  daddu      $7, $0, $0
    /* 1C8ED8 002C8ED8 2D40A000 */  daddu      $8, $5, $0
    /* 1C8EDC 002C8EDC 2CCB0A0C */  jal        func_002b2cb0
    /* 1C8EE0 002C8EE0 00000000 */   nop
    /* 1C8EE4 002C8EE4 3C0F22A6 */  sh         $2, 0xF3C($17)
    /* 1C8EE8 002C8EE8 0F060010 */  b          .L002CA728
    /* 1C8EEC 002C8EEC 00000000 */   nop
  .L002C8EF0:
    /* 1C8EF0 002C8EF0 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8EF4 002C8EF4 38810B0C */  jal        func_002e04e0
    /* 1C8EF8 002C8EF8 00000000 */   nop
    /* 1C8EFC 002C8EFC 3E0F2692 */  lbu        $6, 0xF3E($17)
    /* 1C8F00 002C8F00 3F0F2592 */  lbu        $5, 0xF3F($17)
    /* 1C8F04 002C8F04 400F2492 */  lbu        $4, 0xF40($17)
    /* 1C8F08 002C8F08 410F2392 */  lbu        $3, 0xF41($17)
    /* 1C8F0C 002C8F0C 790046A0 */  sb         $6, 0x79($2)
    /* 1C8F10 002C8F10 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C8F14 002C8F14 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C8F18 002C8F18 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C8F1C 002C8F1C D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8F20 002C8F20 38810B0C */  jal        func_002e04e0
    /* 1C8F24 002C8F24 00000000 */   nop
    /* 1C8F28 002C8F28 420F2692 */  lbu        $6, 0xF42($17)
    /* 1C8F2C 002C8F2C 430F2592 */  lbu        $5, 0xF43($17)
    /* 1C8F30 002C8F30 440F2492 */  lbu        $4, 0xF44($17)
    /* 1C8F34 002C8F34 450F2392 */  lbu        $3, 0xF45($17)
    /* 1C8F38 002C8F38 790046A0 */  sb         $6, 0x79($2)
    /* 1C8F3C 002C8F3C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C8F40 002C8F40 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C8F44 002C8F44 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C8F48 002C8F48 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8F4C 002C8F4C 38810B0C */  jal        func_002e04e0
    /* 1C8F50 002C8F50 00000000 */   nop
    /* 1C8F54 002C8F54 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C8F58 002C8F58 300040C4 */  lwc1       $f0, 0x30($2)
    /* 1C8F5C 002C8F5C 5806A1E7 */  swc1       $f1, 0x658($29)
    /* 1C8F60 002C8F60 5C06A0E7 */  swc1       $f0, 0x65C($29)
    /* 1C8F64 002C8F64 5806A1C7 */  lwc1       $f1, 0x658($29)
    /* 1C8F68 002C8F68 7A44023C */  lui        $2, (0x447A0000 >> 16)
    /* 1C8F6C 002C8F6C 00008244 */  mtc1       $2, $f0
    /* 1C8F70 002C8F70 00000000 */  nop
    /* 1C8F74 002C8F74 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C8F78 002C8F78 3802A427 */  addiu      $4, $29, 0x238
    /* 1C8F7C 002C8F7C 5C06ADC7 */  lwc1       $f13, 0x65C($29)
    /* 1C8F80 002C8F80 5CCA0A0C */  jal        func_002b2970
    /* 1C8F84 002C8F84 00000000 */   nop
    /* 1C8F88 002C8F88 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C8F8C 002C8F8C 5806A5DF */  ld         $5, 0x658($29)
    /* 1C8F90 002C8F90 3802A6DF */  ld         $6, 0x238($29)
    /* 1C8F94 002C8F94 01000724 */  addiu      $7, $0, 0x1
    /* 1C8F98 002C8F98 03000824 */  addiu      $8, $0, 0x3
    /* 1C8F9C 002C8F9C 2D480000 */  daddu      $9, $0, $0
    /* 1C8FA0 002C8FA0 88810B0C */  jal        func_002e0620
    /* 1C8FA4 002C8FA4 00000000 */   nop
    /* 1C8FA8 002C8FA8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8FAC 002C8FAC 38810B0C */  jal        func_002e04e0
    /* 1C8FB0 002C8FB0 00000000 */   nop
    /* 1C8FB4 002C8FB4 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C8FB8 002C8FB8 300040C4 */  lwc1       $f0, 0x30($2)
    /* 1C8FBC 002C8FBC 5801A1E7 */  swc1       $f1, 0x158($29)
    /* 1C8FC0 002C8FC0 5C01A0E7 */  swc1       $f0, 0x15C($29)
    /* 1C8FC4 002C8FC4 5801A1C7 */  lwc1       $f1, 0x158($29)
    /* 1C8FC8 002C8FC8 7A44023C */  lui        $2, (0x447A0000 >> 16)
    /* 1C8FCC 002C8FCC 00008244 */  mtc1       $2, $f0
    /* 1C8FD0 002C8FD0 00000000 */  nop
    /* 1C8FD4 002C8FD4 010B0046 */  sub.s      $f12, $f1, $f0
    /* 1C8FD8 002C8FD8 3002A427 */  addiu      $4, $29, 0x230
    /* 1C8FDC 002C8FDC 5C01ADC7 */  lwc1       $f13, 0x15C($29)
    /* 1C8FE0 002C8FE0 5CCA0A0C */  jal        func_002b2970
    /* 1C8FE4 002C8FE4 00000000 */   nop
    /* 1C8FE8 002C8FE8 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C8FEC 002C8FEC 5801A5DF */  ld         $5, 0x158($29)
    /* 1C8FF0 002C8FF0 3002A6DF */  ld         $6, 0x230($29)
    /* 1C8FF4 002C8FF4 01000724 */  addiu      $7, $0, 0x1
    /* 1C8FF8 002C8FF8 03000824 */  addiu      $8, $0, 0x3
    /* 1C8FFC 002C8FFC 2D480000 */  daddu      $9, $0, $0
    /* 1C9000 002C9000 88810B0C */  jal        func_002e0620
    /* 1C9004 002C9004 00000000 */   nop
    /* 1C9008 002C9008 DA42023C */  lui        $2, (0x42DA0000 >> 16)
    /* 1C900C 002C900C 00608244 */  mtc1       $2, $f12
    /* 1C9010 002C9010 500E248E */  lw         $4, 0xE50($17)
    /* 1C9014 002C9014 41000524 */  addiu      $5, $0, 0x41
    /* 1C9018 002C9018 78820B0C */  jal        func_002e09e0
    /* 1C901C 002C901C 00000000 */   nop
    /* 1C9020 002C9020 8FFD0224 */  addiu      $2, $0, -0x271
    /* 1C9024 002C9024 00008244 */  mtc1       $2, $f0
    /* 1C9028 002C9028 00000000 */  nop
    /* 1C902C 002C902C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9030 002C9030 F842023C */  lui        $2, (0x42F80000 >> 16)
    /* 1C9034 002C9034 00688244 */  mtc1       $2, $f13
    /* 1C9038 002C9038 2802A427 */  addiu      $4, $29, 0x228
    /* 1C903C 002C903C 5CCA0A0C */  jal        func_002b2970
    /* 1C9040 002C9040 00000000 */   nop
    /* 1C9044 002C9044 9642023C */  lui        $2, (0x42960000 >> 16)
    /* 1C9048 002C9048 00608244 */  mtc1       $2, $f12
    /* 1C904C 002C904C F842023C */  lui        $2, (0x42F80000 >> 16)
    /* 1C9050 002C9050 00688244 */  mtc1       $2, $f13
    /* 1C9054 002C9054 2002A427 */  addiu      $4, $29, 0x220
    /* 1C9058 002C9058 5CCA0A0C */  jal        func_002b2970
    /* 1C905C 002C905C 00000000 */   nop
    /* 1C9060 002C9060 500E248E */  lw         $4, 0xE50($17)
    /* 1C9064 002C9064 2802A5DF */  ld         $5, 0x228($29)
    /* 1C9068 002C9068 2002A6DF */  ld         $6, 0x220($29)
    /* 1C906C 002C906C 2D380000 */  daddu      $7, $0, $0
    /* 1C9070 002C9070 04000824 */  addiu      $8, $0, 0x4
    /* 1C9074 002C9074 05000924 */  addiu      $9, $0, 0x5
    /* 1C9078 002C9078 88810B0C */  jal        func_002e0620
    /* 1C907C 002C907C 00000000 */   nop
    /* 1C9080 002C9080 C806A427 */  addiu      $4, $29, 0x6C8
    /* 1C9084 002C9084 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C9088 002C9088 CB000624 */  addiu      $6, $0, 0xCB
    /* 1C908C 002C908C 35000724 */  addiu      $7, $0, 0x35
    /* 1C9090 002C9090 2D40A000 */  daddu      $8, $5, $0
    /* 1C9094 002C9094 98CA0A0C */  jal        func_002b2a60
    /* 1C9098 002C9098 00000000 */   nop
    /* 1C909C 002C909C 500E248E */  lw         $4, 0xE50($17)
    /* 1C90A0 002C90A0 38810B0C */  jal        func_002e04e0
    /* 1C90A4 002C90A4 00000000 */   nop
    /* 1C90A8 002C90A8 C806A693 */  lbu        $6, 0x6C8($29)
    /* 1C90AC 002C90AC C906A593 */  lbu        $5, 0x6C9($29)
    /* 1C90B0 002C90B0 CA06A493 */  lbu        $4, 0x6CA($29)
    /* 1C90B4 002C90B4 CB06A393 */  lbu        $3, 0x6CB($29)
    /* 1C90B8 002C90B8 790046A0 */  sb         $6, 0x79($2)
    /* 1C90BC 002C90BC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C90C0 002C90C0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C90C4 002C90C4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C90C8 002C90C8 E042023C */  lui        $2, (0x42E00000 >> 16)
    /* 1C90CC 002C90CC 00608244 */  mtc1       $2, $f12
    /* 1C90D0 002C90D0 540E248E */  lw         $4, 0xE54($17)
    /* 1C90D4 002C90D4 41000524 */  addiu      $5, $0, 0x41
    /* 1C90D8 002C90D8 78820B0C */  jal        func_002e09e0
    /* 1C90DC 002C90DC 00000000 */   nop
    /* 1C90E0 002C90E0 8FFD0224 */  addiu      $2, $0, -0x271
    /* 1C90E4 002C90E4 00008244 */  mtc1       $2, $f0
    /* 1C90E8 002C90E8 00000000 */  nop
    /* 1C90EC 002C90EC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C90F0 002C90F0 1D010224 */  addiu      $2, $0, 0x11D
    /* 1C90F4 002C90F4 00008244 */  mtc1       $2, $f0
    /* 1C90F8 002C90F8 00000000 */  nop
    /* 1C90FC 002C90FC 60038046 */  cvt.s.w    $f13, $f0
    /* 1C9100 002C9100 1802A427 */  addiu      $4, $29, 0x218
    /* 1C9104 002C9104 5CCA0A0C */  jal        func_002b2970
    /* 1C9108 002C9108 00000000 */   nop
    /* 1C910C 002C910C 9642023C */  lui        $2, (0x42960000 >> 16)
    /* 1C9110 002C9110 00608244 */  mtc1       $2, $f12
    /* 1C9114 002C9114 1D010224 */  addiu      $2, $0, 0x11D
    /* 1C9118 002C9118 00008244 */  mtc1       $2, $f0
    /* 1C911C 002C911C 00000000 */  nop
    /* 1C9120 002C9120 60038046 */  cvt.s.w    $f13, $f0
    /* 1C9124 002C9124 1002A427 */  addiu      $4, $29, 0x210
    /* 1C9128 002C9128 5CCA0A0C */  jal        func_002b2970
    /* 1C912C 002C912C 00000000 */   nop
    /* 1C9130 002C9130 540E248E */  lw         $4, 0xE54($17)
    /* 1C9134 002C9134 1802A5DF */  ld         $5, 0x218($29)
    /* 1C9138 002C9138 1002A6DF */  ld         $6, 0x210($29)
    /* 1C913C 002C913C 2D380000 */  daddu      $7, $0, $0
    /* 1C9140 002C9140 04000824 */  addiu      $8, $0, 0x4
    /* 1C9144 002C9144 05000924 */  addiu      $9, $0, 0x5
    /* 1C9148 002C9148 88810B0C */  jal        func_002e0620
    /* 1C914C 002C914C 00000000 */   nop
    /* 1C9150 002C9150 C406A427 */  addiu      $4, $29, 0x6C4
    /* 1C9154 002C9154 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C9158 002C9158 CB000624 */  addiu      $6, $0, 0xCB
    /* 1C915C 002C915C 35000724 */  addiu      $7, $0, 0x35
    /* 1C9160 002C9160 2D40A000 */  daddu      $8, $5, $0
    /* 1C9164 002C9164 98CA0A0C */  jal        func_002b2a60
    /* 1C9168 002C9168 00000000 */   nop
    /* 1C916C 002C916C 540E248E */  lw         $4, 0xE54($17)
    /* 1C9170 002C9170 38810B0C */  jal        func_002e04e0
    /* 1C9174 002C9174 00000000 */   nop
    /* 1C9178 002C9178 C406A693 */  lbu        $6, 0x6C4($29)
    /* 1C917C 002C917C C506A593 */  lbu        $5, 0x6C5($29)
    /* 1C9180 002C9180 C606A493 */  lbu        $4, 0x6C6($29)
    /* 1C9184 002C9184 C706A393 */  lbu        $3, 0x6C7($29)
    /* 1C9188 002C9188 790046A0 */  sb         $6, 0x79($2)
    /* 1C918C 002C918C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C9190 002C9190 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C9194 002C9194 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C9198 002C9198 E242023C */  lui        $2, (0x42E20000 >> 16)
    /* 1C919C 002C919C 00608244 */  mtc1       $2, $f12
    /* 1C91A0 002C91A0 580E248E */  lw         $4, 0xE58($17)
    /* 1C91A4 002C91A4 41000524 */  addiu      $5, $0, 0x41
    /* 1C91A8 002C91A8 78820B0C */  jal        func_002e09e0
    /* 1C91AC 002C91AC 00000000 */   nop
    /* 1C91B0 002C91B0 EAC2023C */  lui        $2, (0xC2EA0000 >> 16)
    /* 1C91B4 002C91B4 00608244 */  mtc1       $2, $f12
    /* 1C91B8 002C91B8 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1C91BC 002C91BC 00688244 */  mtc1       $2, $f13
    /* 1C91C0 002C91C0 0802A427 */  addiu      $4, $29, 0x208
    /* 1C91C4 002C91C4 5CCA0A0C */  jal        func_002b2970
    /* 1C91C8 002C91C8 00000000 */   nop
    /* 1C91CC 002C91CC 47020224 */  addiu      $2, $0, 0x247
    /* 1C91D0 002C91D0 00008244 */  mtc1       $2, $f0
    /* 1C91D4 002C91D4 00000000 */  nop
    /* 1C91D8 002C91D8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C91DC 002C91DC 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1C91E0 002C91E0 00688244 */  mtc1       $2, $f13
    /* 1C91E4 002C91E4 0002A427 */  addiu      $4, $29, 0x200
    /* 1C91E8 002C91E8 5CCA0A0C */  jal        func_002b2970
    /* 1C91EC 002C91EC 00000000 */   nop
    /* 1C91F0 002C91F0 580E248E */  lw         $4, 0xE58($17)
    /* 1C91F4 002C91F4 0802A5DF */  ld         $5, 0x208($29)
    /* 1C91F8 002C91F8 0002A6DF */  ld         $6, 0x200($29)
    /* 1C91FC 002C91FC 2D380000 */  daddu      $7, $0, $0
    /* 1C9200 002C9200 04000824 */  addiu      $8, $0, 0x4
    /* 1C9204 002C9204 05000924 */  addiu      $9, $0, 0x5
    /* 1C9208 002C9208 88810B0C */  jal        func_002e0620
    /* 1C920C 002C920C 00000000 */   nop
    /* 1C9210 002C9210 E442023C */  lui        $2, (0x42E40000 >> 16)
    /* 1C9214 002C9214 00608244 */  mtc1       $2, $f12
    /* 1C9218 002C9218 5C0E248E */  lw         $4, 0xE5C($17)
    /* 1C921C 002C921C 41000524 */  addiu      $5, $0, 0x41
    /* 1C9220 002C9220 78820B0C */  jal        func_002e09e0
    /* 1C9224 002C9224 00000000 */   nop
    /* 1C9228 002C9228 03FD0224 */  addiu      $2, $0, -0x2FD
    /* 1C922C 002C922C 00008244 */  mtc1       $2, $f0
    /* 1C9230 002C9230 00000000 */  nop
    /* 1C9234 002C9234 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9238 002C9238 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1C923C 002C923C 00688244 */  mtc1       $2, $f13
    /* 1C9240 002C9240 F801A427 */  addiu      $4, $29, 0x1F8
    /* 1C9244 002C9244 5CCA0A0C */  jal        func_002b2970
    /* 1C9248 002C9248 00000000 */   nop
    /* 1C924C 002C924C 82C2023C */  lui        $2, (0xC2820000 >> 16)
    /* 1C9250 002C9250 00608244 */  mtc1       $2, $f12
    /* 1C9254 002C9254 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1C9258 002C9258 00688244 */  mtc1       $2, $f13
    /* 1C925C 002C925C F001A427 */  addiu      $4, $29, 0x1F0
    /* 1C9260 002C9260 5CCA0A0C */  jal        func_002b2970
    /* 1C9264 002C9264 00000000 */   nop
    /* 1C9268 002C9268 5C0E248E */  lw         $4, 0xE5C($17)
    /* 1C926C 002C926C F801A5DF */  ld         $5, 0x1F8($29)
    /* 1C9270 002C9270 F001A6DF */  ld         $6, 0x1F0($29)
    /* 1C9274 002C9274 2D380000 */  daddu      $7, $0, $0
    /* 1C9278 002C9278 04000824 */  addiu      $8, $0, 0x4
    /* 1C927C 002C927C 05000924 */  addiu      $9, $0, 0x5
    /* 1C9280 002C9280 88810B0C */  jal        func_002e0620
    /* 1C9284 002C9284 00000000 */   nop
    /* 1C9288 002C9288 01000224 */  addiu      $2, $0, 0x1
    /* 1C928C 002C928C 240C22A2 */  sb         $2, 0xC24($17)
    /* 1C9290 002C9290 30000224 */  addiu      $2, $0, 0x30
    /* 1C9294 002C9294 000022A2 */  sb         $2, 0x0($17)
    /* 1C9298 002C9298 23050010 */  b          .L002CA728
    /* 1C929C 002C929C 00000000 */   nop
    /* 1C92A0 002C92A0 2D208002 */  daddu      $4, $20, $0
    /* 1C92A4 002C92A4 02000524 */  addiu      $5, $0, 0x2
    /* 1C92A8 002C92A8 E0370B0C */  jal        func_002cdf80
    /* 1C92AC 002C92AC 00000000 */   nop
    /* 1C92B0 002C92B0 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C92B4 002C92B4 09000524 */  addiu      $5, $0, 0x9
    /* 1C92B8 002C92B8 5C810B0C */  jal        func_002e0570
    /* 1C92BC 002C92BC 00000000 */   nop
    /* 1C92C0 002C92C0 3C160200 */  dsll32     $2, $2, 24
    /* 1C92C4 002C92C4 3F160200 */  dsra32     $2, $2, 24
    /* 1C92C8 002C92C8 17054014 */  bnez       $2, .L002CA728
    /* 1C92CC 002C92CC 00000000 */   nop
    /* 1C92D0 002C92D0 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C92D4 002C92D4 09000524 */  addiu      $5, $0, 0x9
    /* 1C92D8 002C92D8 5C810B0C */  jal        func_002e0570
    /* 1C92DC 002C92DC 00000000 */   nop
    /* 1C92E0 002C92E0 3C160200 */  dsll32     $2, $2, 24
    /* 1C92E4 002C92E4 3F160200 */  dsra32     $2, $2, 24
    /* 1C92E8 002C92E8 0F054014 */  bnez       $2, .L002CA728
    /* 1C92EC 002C92EC 00000000 */   nop
    /* 1C92F0 002C92F0 500E248E */  lw         $4, 0xE50($17)
    /* 1C92F4 002C92F4 68810B0C */  jal        func_002e05a0
    /* 1C92F8 002C92F8 00000000 */   nop
    /* 1C92FC 002C92FC 3C160200 */  dsll32     $2, $2, 24
    /* 1C9300 002C9300 3F160200 */  dsra32     $2, $2, 24
    /* 1C9304 002C9304 08054014 */  bnez       $2, .L002CA728
    /* 1C9308 002C9308 00000000 */   nop
    /* 1C930C 002C930C 540E248E */  lw         $4, 0xE54($17)
    /* 1C9310 002C9310 68810B0C */  jal        func_002e05a0
    /* 1C9314 002C9314 00000000 */   nop
    /* 1C9318 002C9318 3C160200 */  dsll32     $2, $2, 24
    /* 1C931C 002C931C 3F160200 */  dsra32     $2, $2, 24
    /* 1C9320 002C9320 01054014 */  bnez       $2, .L002CA728
    /* 1C9324 002C9324 00000000 */   nop
    /* 1C9328 002C9328 580E248E */  lw         $4, 0xE58($17)
    /* 1C932C 002C932C 68810B0C */  jal        func_002e05a0
    /* 1C9330 002C9330 00000000 */   nop
    /* 1C9334 002C9334 3C160200 */  dsll32     $2, $2, 24
    /* 1C9338 002C9338 3F160200 */  dsra32     $2, $2, 24
    /* 1C933C 002C933C FA044014 */  bnez       $2, .L002CA728
    /* 1C9340 002C9340 00000000 */   nop
    /* 1C9344 002C9344 5C0E248E */  lw         $4, 0xE5C($17)
    /* 1C9348 002C9348 68810B0C */  jal        func_002e05a0
    /* 1C934C 002C934C 00000000 */   nop
    /* 1C9350 002C9350 3C160200 */  dsll32     $2, $2, 24
    /* 1C9354 002C9354 3F160200 */  dsra32     $2, $2, 24
    /* 1C9358 002C9358 F3044014 */  bnez       $2, .L002CA728
    /* 1C935C 002C935C 00000000 */   nop
    /* 1C9360 002C9360 2D800000 */  daddu      $16, $0, $0
    /* 1C9364 002C9364 21000010 */  b          .L002C93EC
    /* 1C9368 002C9368 00000000 */   nop
  .L002C936C:
    /* 1C936C 002C936C 3C141000 */  dsll32     $2, $16, 16
    /* 1C9370 002C9370 3F140200 */  dsra32     $2, $2, 16
    /* 1C9374 002C9374 80100200 */  sll        $2, $2, 2
    /* 1C9378 002C9378 21182202 */  addu       $3, $17, $2
    /* 1C937C 002C937C BC0D7224 */  addiu      $18, $3, 0xDBC
    /* 1C9380 002C9380 BE42023C */  lui        $2, (0x42BE0000 >> 16)
    /* 1C9384 002C9384 00608244 */  mtc1       $2, $f12
    /* 1C9388 002C9388 BC0D648C */  lw         $4, 0xDBC($3)
    /* 1C938C 002C938C 41000524 */  addiu      $5, $0, 0x41
    /* 1C9390 002C9390 78820B0C */  jal        func_002e09e0
    /* 1C9394 002C9394 00000000 */   nop
    /* 1C9398 002C9398 C006A427 */  addiu      $4, $29, 0x6C0
    /* 1C939C 002C939C FF000524 */  addiu      $5, $0, 0xFF
    /* 1C93A0 002C93A0 EF000624 */  addiu      $6, $0, 0xEF
    /* 1C93A4 002C93A4 80000724 */  addiu      $7, $0, 0x80
    /* 1C93A8 002C93A8 2D40A000 */  daddu      $8, $5, $0
    /* 1C93AC 002C93AC 98CA0A0C */  jal        func_002b2a60
    /* 1C93B0 002C93B0 00000000 */   nop
    /* 1C93B4 002C93B4 0000448E */  lw         $4, 0x0($18)
    /* 1C93B8 002C93B8 38810B0C */  jal        func_002e04e0
    /* 1C93BC 002C93BC 00000000 */   nop
    /* 1C93C0 002C93C0 C006A693 */  lbu        $6, 0x6C0($29)
    /* 1C93C4 002C93C4 C106A593 */  lbu        $5, 0x6C1($29)
    /* 1C93C8 002C93C8 C206A493 */  lbu        $4, 0x6C2($29)
    /* 1C93CC 002C93CC C306A393 */  lbu        $3, 0x6C3($29)
    /* 1C93D0 002C93D0 790046A0 */  sb         $6, 0x79($2)
    /* 1C93D4 002C93D4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C93D8 002C93D8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C93DC 002C93DC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C93E0 002C93E0 01000226 */  addiu      $2, $16, 0x1
    /* 1C93E4 002C93E4 3C840200 */  dsll32     $16, $2, 16
    /* 1C93E8 002C93E8 3F841000 */  dsra32     $16, $16, 16
  .L002C93EC:
    /* 1C93EC 002C93EC 3C141000 */  dsll32     $2, $16, 16
    /* 1C93F0 002C93F0 3F140200 */  dsra32     $2, $2, 16
    /* 1C93F4 002C93F4 03004228 */  slti       $2, $2, 0x3
    /* 1C93F8 002C93F8 DCFF4014 */  bnez       $2, .L002C936C
    /* 1C93FC 002C93FC 00000000 */   nop
    /* 1C9400 002C9400 B242023C */  lui        $2, (0x42B20000 >> 16)
    /* 1C9404 002C9404 00608244 */  mtc1       $2, $f12
    /* 1C9408 002C9408 2343023C */  lui        $2, (0x43230000 >> 16)
    /* 1C940C 002C940C 00688244 */  mtc1       $2, $f13
    /* 1C9410 002C9410 E801A427 */  addiu      $4, $29, 0x1E8
    /* 1C9414 002C9414 5CCA0A0C */  jal        func_002b2970
    /* 1C9418 002C9418 00000000 */   nop
    /* 1C941C 002C941C BC0D248E */  lw         $4, 0xDBC($17)
    /* 1C9420 002C9420 38810B0C */  jal        func_002e04e0
    /* 1C9424 002C9424 00000000 */   nop
    /* 1C9428 002C9428 E801A1C7 */  lwc1       $f1, 0x1E8($29)
    /* 1C942C 002C942C EC01A0C7 */  lwc1       $f0, 0x1EC($29)
    /* 1C9430 002C9430 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C9434 002C9434 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C9438 002C9438 D1010224 */  addiu      $2, $0, 0x1D1
    /* 1C943C 002C943C 00008244 */  mtc1       $2, $f0
    /* 1C9440 002C9440 00000000 */  nop
    /* 1C9444 002C9444 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9448 002C9448 2343023C */  lui        $2, (0x43230000 >> 16)
    /* 1C944C 002C944C 00688244 */  mtc1       $2, $f13
    /* 1C9450 002C9450 E001A427 */  addiu      $4, $29, 0x1E0
    /* 1C9454 002C9454 5CCA0A0C */  jal        func_002b2970
    /* 1C9458 002C9458 00000000 */   nop
    /* 1C945C 002C945C C00D248E */  lw         $4, 0xDC0($17)
    /* 1C9460 002C9460 38810B0C */  jal        func_002e04e0
    /* 1C9464 002C9464 00000000 */   nop
    /* 1C9468 002C9468 E001A1C7 */  lwc1       $f1, 0x1E0($29)
    /* 1C946C 002C946C E401A0C7 */  lwc1       $f0, 0x1E4($29)
    /* 1C9470 002C9470 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C9474 002C9474 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C9478 002C9478 2E020224 */  addiu      $2, $0, 0x22E
    /* 1C947C 002C947C 00008244 */  mtc1       $2, $f0
    /* 1C9480 002C9480 00000000 */  nop
    /* 1C9484 002C9484 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9488 002C9488 2343023C */  lui        $2, (0x43230000 >> 16)
    /* 1C948C 002C948C 00688244 */  mtc1       $2, $f13
    /* 1C9490 002C9490 D801A427 */  addiu      $4, $29, 0x1D8
    /* 1C9494 002C9494 5CCA0A0C */  jal        func_002b2970
    /* 1C9498 002C9498 00000000 */   nop
    /* 1C949C 002C949C C40D248E */  lw         $4, 0xDC4($17)
    /* 1C94A0 002C94A0 38810B0C */  jal        func_002e04e0
    /* 1C94A4 002C94A4 00000000 */   nop
    /* 1C94A8 002C94A8 D801A1C7 */  lwc1       $f1, 0x1D8($29)
    /* 1C94AC 002C94AC DC01A0C7 */  lwc1       $f0, 0x1DC($29)
    /* 1C94B0 002C94B0 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C94B4 002C94B4 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C94B8 002C94B8 B642023C */  lui        $2, (0x42B60000 >> 16)
    /* 1C94BC 002C94BC 00608244 */  mtc1       $2, $f12
    /* 1C94C0 002C94C0 AC0C248E */  lw         $4, 0xCAC($17)
    /* 1C94C4 002C94C4 56000524 */  addiu      $5, $0, 0x56
    /* 1C94C8 002C94C8 78820B0C */  jal        func_002e09e0
    /* 1C94CC 002C94CC 00000000 */   nop
    /* 1C94D0 002C94D0 DF010224 */  addiu      $2, $0, 0x1DF
    /* 1C94D4 002C94D4 00008244 */  mtc1       $2, $f0
    /* 1C94D8 002C94D8 00000000 */  nop
    /* 1C94DC 002C94DC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C94E0 002C94E0 2743023C */  lui        $2, (0x43270000 >> 16)
    /* 1C94E4 002C94E4 00688244 */  mtc1       $2, $f13
    /* 1C94E8 002C94E8 D001A427 */  addiu      $4, $29, 0x1D0
    /* 1C94EC 002C94EC 5CCA0A0C */  jal        func_002b2970
    /* 1C94F0 002C94F0 00000000 */   nop
    /* 1C94F4 002C94F4 AC0C248E */  lw         $4, 0xCAC($17)
    /* 1C94F8 002C94F8 38810B0C */  jal        func_002e04e0
    /* 1C94FC 002C94FC 00000000 */   nop
    /* 1C9500 002C9500 D001A1C7 */  lwc1       $f1, 0x1D0($29)
    /* 1C9504 002C9504 D401A0C7 */  lwc1       $f0, 0x1D4($29)
    /* 1C9508 002C9508 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C950C 002C950C 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C9510 002C9510 BC06A427 */  addiu      $4, $29, 0x6BC
    /* 1C9514 002C9514 FE000524 */  addiu      $5, $0, 0xFE
    /* 1C9518 002C9518 C7000624 */  addiu      $6, $0, 0xC7
    /* 1C951C 002C951C 31000724 */  addiu      $7, $0, 0x31
    /* 1C9520 002C9520 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C9524 002C9524 98CA0A0C */  jal        func_002b2a60
    /* 1C9528 002C9528 00000000 */   nop
    /* 1C952C 002C952C AC0C248E */  lw         $4, 0xCAC($17)
    /* 1C9530 002C9530 38810B0C */  jal        func_002e04e0
    /* 1C9534 002C9534 00000000 */   nop
    /* 1C9538 002C9538 BC06A693 */  lbu        $6, 0x6BC($29)
    /* 1C953C 002C953C BD06A593 */  lbu        $5, 0x6BD($29)
    /* 1C9540 002C9540 BE06A493 */  lbu        $4, 0x6BE($29)
    /* 1C9544 002C9544 BF06A393 */  lbu        $3, 0x6BF($29)
    /* 1C9548 002C9548 790046A0 */  sb         $6, 0x79($2)
    /* 1C954C 002C954C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C9550 002C9550 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C9554 002C9554 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C9558 002C9558 B642023C */  lui        $2, (0x42B60000 >> 16)
    /* 1C955C 002C955C 00608244 */  mtc1       $2, $f12
    /* 1C9560 002C9560 840E248E */  lw         $4, 0xE84($17)
    /* 1C9564 002C9564 56000524 */  addiu      $5, $0, 0x56
    /* 1C9568 002C9568 78820B0C */  jal        func_002e09e0
    /* 1C956C 002C956C 00000000 */   nop
    /* 1C9570 002C9570 B806A427 */  addiu      $4, $29, 0x6B8
    /* 1C9574 002C9574 FE000524 */  addiu      $5, $0, 0xFE
    /* 1C9578 002C9578 C7000624 */  addiu      $6, $0, 0xC7
    /* 1C957C 002C957C 31000724 */  addiu      $7, $0, 0x31
    /* 1C9580 002C9580 FF000824 */  addiu      $8, $0, 0xFF
    /* 1C9584 002C9584 98CA0A0C */  jal        func_002b2a60
    /* 1C9588 002C9588 00000000 */   nop
    /* 1C958C 002C958C 840E248E */  lw         $4, 0xE84($17)
    /* 1C9590 002C9590 38810B0C */  jal        func_002e04e0
    /* 1C9594 002C9594 00000000 */   nop
    /* 1C9598 002C9598 B806A693 */  lbu        $6, 0x6B8($29)
    /* 1C959C 002C959C B906A593 */  lbu        $5, 0x6B9($29)
    /* 1C95A0 002C95A0 BA06A493 */  lbu        $4, 0x6BA($29)
    /* 1C95A4 002C95A4 BB06A393 */  lbu        $3, 0x6BB($29)
    /* 1C95A8 002C95A8 790046A0 */  sb         $6, 0x79($2)
    /* 1C95AC 002C95AC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C95B0 002C95B0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C95B4 002C95B4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C95B8 002C95B8 DF010224 */  addiu      $2, $0, 0x1DF
    /* 1C95BC 002C95BC 00008244 */  mtc1       $2, $f0
    /* 1C95C0 002C95C0 00000000 */  nop
    /* 1C95C4 002C95C4 20038046 */  cvt.s.w    $f12, $f0
    /* 1C95C8 002C95C8 5943023C */  lui        $2, (0x43590000 >> 16)
    /* 1C95CC 002C95CC 00688244 */  mtc1       $2, $f13
    /* 1C95D0 002C95D0 C801A427 */  addiu      $4, $29, 0x1C8
    /* 1C95D4 002C95D4 5CCA0A0C */  jal        func_002b2970
    /* 1C95D8 002C95D8 00000000 */   nop
    /* 1C95DC 002C95DC 840E248E */  lw         $4, 0xE84($17)
    /* 1C95E0 002C95E0 38810B0C */  jal        func_002e04e0
    /* 1C95E4 002C95E4 00000000 */   nop
    /* 1C95E8 002C95E8 C801A1C7 */  lwc1       $f1, 0x1C8($29)
    /* 1C95EC 002C95EC CC01A0C7 */  lwc1       $f0, 0x1CC($29)
    /* 1C95F0 002C95F0 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C95F4 002C95F4 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C95F8 002C95F8 11002282 */  lb         $2, 0x11($17)
    /* 1C95FC 002C95FC 80100200 */  sll        $2, $2, 2
    /* 1C9600 002C9600 21105100 */  addu       $2, $2, $17
    /* 1C9604 002C9604 180F448C */  lw         $4, 0xF18($2)
    /* 1C9608 002C9608 BC890B0C */  jal        func_002e26f0
    /* 1C960C 002C960C 00000000 */   nop
    /* 1C9610 002C9610 02004228 */  slti       $2, $2, 0x2
    /* 1C9614 002C9614 51004014 */  bnez       $2, .L002C975C
    /* 1C9618 002C9618 00000000 */   nop
    /* 1C961C 002C961C B042023C */  lui        $2, (0x42B00000 >> 16)
    /* 1C9620 002C9620 00608244 */  mtc1       $2, $f12
    /* 1C9624 002C9624 940C248E */  lw         $4, 0xC94($17)
    /* 1C9628 002C9628 41000524 */  addiu      $5, $0, 0x41
    /* 1C962C 002C962C 78820B0C */  jal        func_002e09e0
    /* 1C9630 002C9630 00000000 */   nop
    /* 1C9634 002C9634 B406A427 */  addiu      $4, $29, 0x6B4
    /* 1C9638 002C9638 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C963C 002C963C 96000624 */  addiu      $6, $0, 0x96
    /* 1C9640 002C9640 2D380000 */  daddu      $7, $0, $0
    /* 1C9644 002C9644 2D40A000 */  daddu      $8, $5, $0
    /* 1C9648 002C9648 98CA0A0C */  jal        func_002b2a60
    /* 1C964C 002C964C 00000000 */   nop
    /* 1C9650 002C9650 940C248E */  lw         $4, 0xC94($17)
    /* 1C9654 002C9654 38810B0C */  jal        func_002e04e0
    /* 1C9658 002C9658 00000000 */   nop
    /* 1C965C 002C965C B406A693 */  lbu        $6, 0x6B4($29)
    /* 1C9660 002C9660 B506A593 */  lbu        $5, 0x6B5($29)
    /* 1C9664 002C9664 B606A493 */  lbu        $4, 0x6B6($29)
    /* 1C9668 002C9668 B706A393 */  lbu        $3, 0x6B7($29)
    /* 1C966C 002C966C 790046A0 */  sb         $6, 0x79($2)
    /* 1C9670 002C9670 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C9674 002C9674 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C9678 002C9678 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C967C 002C967C 47020224 */  addiu      $2, $0, 0x247
    /* 1C9680 002C9680 00008244 */  mtc1       $2, $f0
    /* 1C9684 002C9684 00000000 */  nop
    /* 1C9688 002C9688 20038046 */  cvt.s.w    $f12, $f0
    /* 1C968C 002C968C 0843023C */  lui        $2, (0x43080000 >> 16)
    /* 1C9690 002C9690 00688244 */  mtc1       $2, $f13
    /* 1C9694 002C9694 C001A427 */  addiu      $4, $29, 0x1C0
    /* 1C9698 002C9698 5CCA0A0C */  jal        func_002b2970
    /* 1C969C 002C969C 00000000 */   nop
    /* 1C96A0 002C96A0 940C248E */  lw         $4, 0xC94($17)
    /* 1C96A4 002C96A4 38810B0C */  jal        func_002e04e0
    /* 1C96A8 002C96A8 00000000 */   nop
    /* 1C96AC 002C96AC C001A1C7 */  lwc1       $f1, 0x1C0($29)
    /* 1C96B0 002C96B0 C401A0C7 */  lwc1       $f0, 0x1C4($29)
    /* 1C96B4 002C96B4 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C96B8 002C96B8 300040E4 */  swc1       $f0, 0x30($2)
    /* 1C96BC 002C96BC B242023C */  lui        $2, (0x42B20000 >> 16)
    /* 1C96C0 002C96C0 00608244 */  mtc1       $2, $f12
    /* 1C96C4 002C96C4 980C248E */  lw         $4, 0xC98($17)
    /* 1C96C8 002C96C8 41000524 */  addiu      $5, $0, 0x41
    /* 1C96CC 002C96CC 78820B0C */  jal        func_002e09e0
    /* 1C96D0 002C96D0 00000000 */   nop
    /* 1C96D4 002C96D4 B006A427 */  addiu      $4, $29, 0x6B0
    /* 1C96D8 002C96D8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1C96DC 002C96DC 96000624 */  addiu      $6, $0, 0x96
    /* 1C96E0 002C96E0 2D380000 */  daddu      $7, $0, $0
    /* 1C96E4 002C96E4 2D40A000 */  daddu      $8, $5, $0
    /* 1C96E8 002C96E8 98CA0A0C */  jal        func_002b2a60
    /* 1C96EC 002C96EC 00000000 */   nop
    /* 1C96F0 002C96F0 980C248E */  lw         $4, 0xC98($17)
    /* 1C96F4 002C96F4 38810B0C */  jal        func_002e04e0
    /* 1C96F8 002C96F8 00000000 */   nop
    /* 1C96FC 002C96FC B006A693 */  lbu        $6, 0x6B0($29)
    /* 1C9700 002C9700 B106A593 */  lbu        $5, 0x6B1($29)
    /* 1C9704 002C9704 B206A493 */  lbu        $4, 0x6B2($29)
    /* 1C9708 002C9708 B306A393 */  lbu        $3, 0x6B3($29)
    /* 1C970C 002C970C 790046A0 */  sb         $6, 0x79($2)
    /* 1C9710 002C9710 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1C9714 002C9714 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1C9718 002C9718 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1C971C 002C971C 47020224 */  addiu      $2, $0, 0x247
    /* 1C9720 002C9720 00008244 */  mtc1       $2, $f0
    /* 1C9724 002C9724 00000000 */  nop
    /* 1C9728 002C9728 20038046 */  cvt.s.w    $f12, $f0
    /* 1C972C 002C972C 8843023C */  lui        $2, (0x43880000 >> 16)
    /* 1C9730 002C9730 00688244 */  mtc1       $2, $f13
    /* 1C9734 002C9734 B801A427 */  addiu      $4, $29, 0x1B8
    /* 1C9738 002C9738 5CCA0A0C */  jal        func_002b2970
    /* 1C973C 002C973C 00000000 */   nop
    /* 1C9740 002C9740 980C248E */  lw         $4, 0xC98($17)
    /* 1C9744 002C9744 38810B0C */  jal        func_002e04e0
    /* 1C9748 002C9748 00000000 */   nop
    /* 1C974C 002C974C B801A1C7 */  lwc1       $f1, 0x1B8($29)
    /* 1C9750 002C9750 BC01A0C7 */  lwc1       $f0, 0x1BC($29)
    /* 1C9754 002C9754 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1C9758 002C9758 300040E4 */  swc1       $f0, 0x30($2)
  .L002C975C:
    /* 1C975C 002C975C 31000224 */  addiu      $2, $0, 0x31
    /* 1C9760 002C9760 000022A2 */  sb         $2, 0x0($17)
    /* 1C9764 002C9764 F0030010 */  b          .L002CA728
    /* 1C9768 002C9768 00000000 */   nop
    /* 1C976C 002C976C A00C248E */  lw         $4, 0xCA0($17)
    /* 1C9770 002C9770 2D280000 */  daddu      $5, $0, $0
    /* 1C9774 002C9774 01000624 */  addiu      $6, $0, 0x1
    /* 1C9778 002C9778 3C810B0C */  jal        func_002e04f0
    /* 1C977C 002C977C 00000000 */   nop
    /* 1C9780 002C9780 A80C248E */  lw         $4, 0xCA8($17)
    /* 1C9784 002C9784 2D280000 */  daddu      $5, $0, $0
    /* 1C9788 002C9788 01000624 */  addiu      $6, $0, 0x1
    /* 1C978C 002C978C 3C810B0C */  jal        func_002e04f0
    /* 1C9790 002C9790 00000000 */   nop
    /* 1C9794 002C9794 9C0C248E */  lw         $4, 0xC9C($17)
    /* 1C9798 002C9798 2D280000 */  daddu      $5, $0, $0
    /* 1C979C 002C979C 01000624 */  addiu      $6, $0, 0x1
    /* 1C97A0 002C97A0 3C810B0C */  jal        func_002e04f0
    /* 1C97A4 002C97A4 00000000 */   nop
    /* 1C97A8 002C97A8 A40C248E */  lw         $4, 0xCA4($17)
    /* 1C97AC 002C97AC 2D280000 */  daddu      $5, $0, $0
    /* 1C97B0 002C97B0 01000624 */  addiu      $6, $0, 0x1
    /* 1C97B4 002C97B4 3C810B0C */  jal        func_002e04f0
    /* 1C97B8 002C97B8 00000000 */   nop
    /* 1C97BC 002C97BC B80C248E */  lw         $4, 0xCB8($17)
    /* 1C97C0 002C97C0 2D280000 */  daddu      $5, $0, $0
    /* 1C97C4 002C97C4 01000624 */  addiu      $6, $0, 0x1
    /* 1C97C8 002C97C8 3C810B0C */  jal        func_002e04f0
    /* 1C97CC 002C97CC 00000000 */   nop
    /* 1C97D0 002C97D0 AC0E248E */  lw         $4, 0xEAC($17)
    /* 1C97D4 002C97D4 2D280000 */  daddu      $5, $0, $0
    /* 1C97D8 002C97D8 01000624 */  addiu      $6, $0, 0x1
    /* 1C97DC 002C97DC 3C810B0C */  jal        func_002e04f0
    /* 1C97E0 002C97E0 00000000 */   nop
    /* 1C97E4 002C97E4 2D208002 */  daddu      $4, $20, $0
    /* 1C97E8 002C97E8 01000524 */  addiu      $5, $0, 0x1
    /* 1C97EC 002C97EC E0370B0C */  jal        func_002cdf80
    /* 1C97F0 002C97F0 00000000 */   nop
    /* 1C97F4 002C97F4 2D208002 */  daddu      $4, $20, $0
    /* 1C97F8 002C97F8 EC740B0C */  jal        func_002dd3b0
    /* 1C97FC 002C97FC 00000000 */   nop
    /* 1C9800 002C9800 380E248E */  lw         $4, 0xE38($17)
    /* 1C9804 002C9804 01000524 */  addiu      $5, $0, 0x1
    /* 1C9808 002C9808 5C810B0C */  jal        func_002e0570
    /* 1C980C 002C980C 00000000 */   nop
    /* 1C9810 002C9810 3C160200 */  dsll32     $2, $2, 24
    /* 1C9814 002C9814 3F160200 */  dsra32     $2, $2, 24
    /* 1C9818 002C9818 C3034014 */  bnez       $2, .L002CA728
    /* 1C981C 002C981C 00000000 */   nop
    /* 1C9820 002C9820 C40C248E */  lw         $4, 0xCC4($17)
    /* 1C9824 002C9824 01000524 */  addiu      $5, $0, 0x1
    /* 1C9828 002C9828 5C810B0C */  jal        func_002e0570
    /* 1C982C 002C982C 00000000 */   nop
    /* 1C9830 002C9830 3C160200 */  dsll32     $2, $2, 24
    /* 1C9834 002C9834 3F160200 */  dsra32     $2, $2, 24
    /* 1C9838 002C9838 BB034014 */  bnez       $2, .L002CA728
    /* 1C983C 002C983C 00000000 */   nop
    /* 1C9840 002C9840 C00C248E */  lw         $4, 0xCC0($17)
    /* 1C9844 002C9844 01000524 */  addiu      $5, $0, 0x1
    /* 1C9848 002C9848 5C810B0C */  jal        func_002e0570
    /* 1C984C 002C984C 00000000 */   nop
    /* 1C9850 002C9850 3C160200 */  dsll32     $2, $2, 24
    /* 1C9854 002C9854 3F160200 */  dsra32     $2, $2, 24
    /* 1C9858 002C9858 B3034014 */  bnez       $2, .L002CA728
    /* 1C985C 002C985C 00000000 */   nop
    /* 1C9860 002C9860 8C00023C */  lui        $2, %hi(D_008C0276)
    /* 1C9864 002C9864 76024394 */  lhu        $3, %lo(D_008C0276)($2)
    /* 1C9868 002C9868 80006230 */  andi       $2, $3, 0x80
    /* 1C986C 002C986C 04004014 */  bnez       $2, .L002C9880
    /* 1C9870 002C9870 00000000 */   nop
    /* 1C9874 002C9874 20006230 */  andi       $2, $3, 0x20
    /* 1C9878 002C9878 AB034010 */  beqz       $2, .L002CA728
    /* 1C987C 002C987C 00000000 */   nop
  .L002C9880:
    /* 1C9880 002C9880 2D200000 */  daddu      $4, $0, $0
    /* 1C9884 002C9884 01000524 */  addiu      $5, $0, 0x1
    /* 1C9888 002C9888 2D300000 */  daddu      $6, $0, $0
    /* 1C988C 002C988C 04000724 */  addiu      $7, $0, 0x4
    /* 1C9890 002C9890 D86B110C */  jal        func_0045af60
    /* 1C9894 002C9894 00000000 */   nop
    /* 1C9898 002C9898 2D208002 */  daddu      $4, $20, $0
    /* 1C989C 002C989C 80610B0C */  jal        func_002d8600
    /* 1C98A0 002C98A0 00000000 */   nop
    /* 1C98A4 002C98A4 E40D248E */  lw         $4, 0xDE4($17)
    /* 1C98A8 002C98A8 2D280000 */  daddu      $5, $0, $0
    /* 1C98AC 002C98AC 2D300000 */  daddu      $6, $0, $0
    /* 1C98B0 002C98B0 3C810B0C */  jal        func_002e04f0
    /* 1C98B4 002C98B4 00000000 */   nop
    /* 1C98B8 002C98B8 E00D248E */  lw         $4, 0xDE0($17)
    /* 1C98BC 002C98BC 2D280000 */  daddu      $5, $0, $0
    /* 1C98C0 002C98C0 01000624 */  addiu      $6, $0, 0x1
    /* 1C98C4 002C98C4 3C810B0C */  jal        func_002e04f0
    /* 1C98C8 002C98C8 00000000 */   nop
    /* 1C98CC 002C98CC CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C98D0 002C98D0 38810B0C */  jal        func_002e04e0
    /* 1C98D4 002C98D4 00000000 */   nop
    /* 1C98D8 002C98D8 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C98DC 002C98DC 300040C4 */  lwc1       $f0, 0x30($2)
    /* 1C98E0 002C98E0 5006A1E7 */  swc1       $f1, 0x650($29)
    /* 1C98E4 002C98E4 5406A0E7 */  swc1       $f0, 0x654($29)
    /* 1C98E8 002C98E8 6400103C */  lui        $16, %hi(D_0063F888)
    /* 1C98EC 002C98EC 88F81026 */  addiu      $16, $16, %lo(D_0063F888)
    /* 1C98F0 002C98F0 5406B4C7 */  lwc1       $f20, 0x654($29)
    /* 1C98F4 002C98F4 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C98F8 002C98F8 00088244 */  mtc1       $2, $f1
    /* 1C98FC 002C98FC 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C9900 002C9900 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C9904 002C9904 B001A427 */  addiu      $4, $29, 0x1B0
    /* 1C9908 002C9908 46A30046 */  mov.s      $f13, $f20
    /* 1C990C 002C990C 5CCA0A0C */  jal        func_002b2970
    /* 1C9910 002C9910 00000000 */   nop
    /* 1C9914 002C9914 A801A427 */  addiu      $4, $29, 0x1A8
    /* 1C9918 002C9918 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C991C 002C991C 46A30046 */  mov.s      $f13, $f20
    /* 1C9920 002C9920 5CCA0A0C */  jal        func_002b2970
    /* 1C9924 002C9924 00000000 */   nop
    /* 1C9928 002C9928 CC0D248E */  lw         $4, 0xDCC($17)
    /* 1C992C 002C992C B001A5DF */  ld         $5, 0x1B0($29)
    /* 1C9930 002C9930 A801A6DF */  ld         $6, 0x1A8($29)
    /* 1C9934 002C9934 01000724 */  addiu      $7, $0, 0x1
    /* 1C9938 002C9938 03000824 */  addiu      $8, $0, 0x3
    /* 1C993C 002C993C 02000924 */  addiu      $9, $0, 0x2
    /* 1C9940 002C9940 88810B0C */  jal        func_002e0620
    /* 1C9944 002C9944 00000000 */   nop
    /* 1C9948 002C9948 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C994C 002C994C 38810B0C */  jal        func_002e04e0
    /* 1C9950 002C9950 00000000 */   nop
    /* 1C9954 002C9954 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1C9958 002C9958 300040C4 */  lwc1       $f0, 0x30($2)
    /* 1C995C 002C995C 5001A1E7 */  swc1       $f1, 0x150($29)
    /* 1C9960 002C9960 5401A0E7 */  swc1       $f0, 0x154($29)
    /* 1C9964 002C9964 6400103C */  lui        $16, %hi(D_0063F890)
    /* 1C9968 002C9968 90F81026 */  addiu      $16, $16, %lo(D_0063F890)
    /* 1C996C 002C996C 5401B4C7 */  lwc1       $f20, 0x154($29)
    /* 1C9970 002C9970 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1C9974 002C9974 00088244 */  mtc1       $2, $f1
    /* 1C9978 002C9978 000000C6 */  lwc1       $f0, 0x0($16)
    /* 1C997C 002C997C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1C9980 002C9980 A001A427 */  addiu      $4, $29, 0x1A0
    /* 1C9984 002C9984 46A30046 */  mov.s      $f13, $f20
    /* 1C9988 002C9988 5CCA0A0C */  jal        func_002b2970
    /* 1C998C 002C998C 00000000 */   nop
    /* 1C9990 002C9990 9801A427 */  addiu      $4, $29, 0x198
    /* 1C9994 002C9994 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1C9998 002C9998 46A30046 */  mov.s      $f13, $f20
    /* 1C999C 002C999C 5CCA0A0C */  jal        func_002b2970
    /* 1C99A0 002C99A0 00000000 */   nop
    /* 1C99A4 002C99A4 D00D248E */  lw         $4, 0xDD0($17)
    /* 1C99A8 002C99A8 A001A5DF */  ld         $5, 0x1A0($29)
    /* 1C99AC 002C99AC 9801A6DF */  ld         $6, 0x198($29)
    /* 1C99B0 002C99B0 01000724 */  addiu      $7, $0, 0x1
    /* 1C99B4 002C99B4 03000824 */  addiu      $8, $0, 0x3
    /* 1C99B8 002C99B8 02000924 */  addiu      $9, $0, 0x2
    /* 1C99BC 002C99BC 88810B0C */  jal        func_002e0620
    /* 1C99C0 002C99C0 00000000 */   nop
    /* 1C99C4 002C99C4 24000224 */  addiu      $2, $0, 0x24
    /* 1C99C8 002C99C8 000022A2 */  sb         $2, 0x0($17)
    /* 1C99CC 002C99CC 56030010 */  b          .L002CA728
    /* 1C99D0 002C99D0 00000000 */   nop
    /* 1C99D4 002C99D4 24000224 */  addiu      $2, $0, 0x24
    /* 1C99D8 002C99D8 000022A2 */  sb         $2, 0x0($17)
    /* 1C99DC 002C99DC 52030010 */  b          .L002CA728
    /* 1C99E0 002C99E0 00000000 */   nop
    /* 1C99E4 002C99E4 11002282 */  lb         $2, 0x11($17)
    /* 1C99E8 002C99E8 80100200 */  sll        $2, $2, 2
    /* 1C99EC 002C99EC 21105100 */  addu       $2, $2, $17
    /* 1C99F0 002C99F0 180F448C */  lw         $4, 0xF18($2)
    /* 1C99F4 002C99F4 BC890B0C */  jal        func_002e26f0
    /* 1C99F8 002C99F8 00000000 */   nop
    /* 1C99FC 002C99FC 06004128 */  slti       $1, $2, 0x6
    /* 1C9A00 002C9A00 5A002014 */  bnez       $1, .L002C9B6C
    /* 1C9A04 002C9A04 00000000 */   nop
    /* 1C9A08 002C9A08 11003082 */  lb         $16, 0x11($17)
    /* 1C9A0C 002C9A0C 80101000 */  sll        $2, $16, 2
    /* 1C9A10 002C9A10 21105100 */  addu       $2, $2, $17
    /* 1C9A14 002C9A14 180F448C */  lw         $4, 0xF18($2)
    /* 1C9A18 002C9A18 BC890B0C */  jal        func_002e26f0
    /* 1C9A1C 002C9A1C 00000000 */   nop
    /* 1C9A20 002C9A20 7500033C */  lui        $3, %hi(D_00748908)
    /* 1C9A24 002C9A24 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1C9A28 002C9A28 21187000 */  addu       $3, $3, $16
    /* 1C9A2C 002C9A2C 00006380 */  lb         $3, 0x0($3)
    /* 1C9A30 002C9A30 2A086200 */  slt        $1, $3, $2
    /* 1C9A34 002C9A34 41002010 */  beqz       $1, .L002C9B3C
    /* 1C9A38 002C9A38 00000000 */   nop
    /* 1C9A3C 002C9A3C 80101000 */  sll        $2, $16, 2
    /* 1C9A40 002C9A40 21105100 */  addu       $2, $2, $17
    /* 1C9A44 002C9A44 180F448C */  lw         $4, 0xF18($2)
    /* 1C9A48 002C9A48 BC890B0C */  jal        func_002e26f0
    /* 1C9A4C 002C9A4C 00000000 */   nop
    /* 1C9A50 002C9A50 06004128 */  slti       $1, $2, 0x6
    /* 1C9A54 002C9A54 10002014 */  bnez       $1, .L002C9A98
    /* 1C9A58 002C9A58 00000000 */   nop
    /* 1C9A5C 002C9A5C 11002282 */  lb         $2, 0x11($17)
    /* 1C9A60 002C9A60 80100200 */  sll        $2, $2, 2
    /* 1C9A64 002C9A64 21105100 */  addu       $2, $2, $17
    /* 1C9A68 002C9A68 180F448C */  lw         $4, 0xF18($2)
    /* 1C9A6C 002C9A6C BC890B0C */  jal        func_002e26f0
    /* 1C9A70 002C9A70 00000000 */   nop
    /* 1C9A74 002C9A74 FBFF4224 */  addiu      $2, $2, -0x5
    /* 1C9A78 002C9A78 00008244 */  mtc1       $2, $f0
    /* 1C9A7C 002C9A7C 00000000 */  nop
    /* 1C9A80 002C9A80 60008046 */  cvt.s.w    $f1, $f0
    /* 1C9A84 002C9A84 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1C9A88 002C9A88 00008244 */  mtc1       $2, $f0
    /* 1C9A8C 002C9A8C 00000000 */  nop
    /* 1C9A90 002C9A90 03000146 */  div.s      $f0, $f0, $f1
    /* 1C9A94 002C9A94 0C0020E6 */  swc1       $f0, 0xC($17)
  .L002C9A98:
    /* 1C9A98 002C9A98 02002386 */  lh         $3, 0x2($17)
    /* 1C9A9C 002C9A9C 04002286 */  lh         $2, 0x4($17)
    /* 1C9AA0 002C9AA0 23106200 */  subu       $2, $3, $2
    /* 1C9AA4 002C9AA4 00008244 */  mtc1       $2, $f0
    /* 1C9AA8 002C9AA8 00000000 */  nop
    /* 1C9AAC 002C9AAC E0008046 */  cvt.s.w    $f3, $f0
    /* 1C9AB0 002C9AB0 0C0022C6 */  lwc1       $f2, 0xC($17)
    /* 1C9AB4 002C9AB4 0E43023C */  lui        $2, (0x430E0000 >> 16)
    /* 1C9AB8 002C9AB8 00088244 */  mtc1       $2, $f1
    /* 1C9ABC 002C9ABC 00008044 */  mtc1       $0, $f0
    /* 1C9AC0 002C9AC0 00000000 */  nop
    /* 1C9AC4 002C9AC4 18000146 */  adda.s     $f0, $f1
    /* 1C9AC8 002C9AC8 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C9ACC 002C9ACC 21020224 */  addiu      $2, $0, 0x221
    /* 1C9AD0 002C9AD0 00008244 */  mtc1       $2, $f0
    /* 1C9AD4 002C9AD4 00000000 */  nop
    /* 1C9AD8 002C9AD8 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9ADC 002C9ADC 9001A427 */  addiu      $4, $29, 0x190
    /* 1C9AE0 002C9AE0 5CCA0A0C */  jal        func_002b2970
    /* 1C9AE4 002C9AE4 00000000 */   nop
    /* 1C9AE8 002C9AE8 FF000424 */  addiu      $4, $0, 0xFF
    /* 1C9AEC 002C9AEC FE000524 */  addiu      $5, $0, 0xFE
    /* 1C9AF0 002C9AF0 C6000624 */  addiu      $6, $0, 0xC6
    /* 1C9AF4 002C9AF4 31000724 */  addiu      $7, $0, 0x31
    /* 1C9AF8 002C9AF8 8CCA0A0C */  jal        func_002b2a30
    /* 1C9AFC 002C9AFC 00000000 */   nop
    /* 1C9B00 002C9B00 2D804000 */  daddu      $16, $2, $0
    /* 1C9B04 002C9B04 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C9B08 002C9B08 38810B0C */  jal        func_002e04e0
    /* 1C9B0C 002C9B0C 00000000 */   nop
    /* 1C9B10 002C9B10 0A43033C */  lui        $3, (0x430A0000 >> 16)
    /* 1C9B14 002C9B14 00608344 */  mtc1       $3, $f12
    /* 1C9B18 002C9B18 36000424 */  addiu      $4, $0, 0x36
    /* 1C9B1C 002C9B1C 9001A5DF */  ld         $5, 0x190($29)
    /* 1C9B20 002C9B20 2D300002 */  daddu      $6, $16, $0
    /* 1C9B24 002C9B24 62004790 */  lbu        $7, 0x62($2)
    /* 1C9B28 002C9B28 2D400000 */  daddu      $8, $0, $0
    /* 1C9B2C 002C9B2C 7900093C */  lui        $9, %hi(D_00794EA0)
    /* 1C9B30 002C9B30 A04E2925 */  addiu      $9, $9, %lo(D_00794EA0)
    /* 1C9B34 002C9B34 C8820B0C */  jal        func_002e0b20
    /* 1C9B38 002C9B38 00000000 */   nop
  .L002C9B3C:
    /* 1C9B3C 002C9B3C 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C9B40 002C9B40 2D280000 */  daddu      $5, $0, $0
    /* 1C9B44 002C9B44 2D300000 */  daddu      $6, $0, $0
    /* 1C9B48 002C9B48 3C810B0C */  jal        func_002e04f0
    /* 1C9B4C 002C9B4C 00000000 */   nop
    /* 1C9B50 002C9B50 900C248E */  lw         $4, 0xC90($17)
    /* 1C9B54 002C9B54 2D280000 */  daddu      $5, $0, $0
    /* 1C9B58 002C9B58 2D300000 */  daddu      $6, $0, $0
    /* 1C9B5C 002C9B5C 3C810B0C */  jal        func_002e04f0
    /* 1C9B60 002C9B60 00000000 */   nop
    /* 1C9B64 002C9B64 0B000010 */  b          .L002C9B94
    /* 1C9B68 002C9B68 00000000 */   nop
  .L002C9B6C:
    /* 1C9B6C 002C9B6C 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C9B70 002C9B70 2D280000 */  daddu      $5, $0, $0
    /* 1C9B74 002C9B74 01000624 */  addiu      $6, $0, 0x1
    /* 1C9B78 002C9B78 3C810B0C */  jal        func_002e04f0
    /* 1C9B7C 002C9B7C 00000000 */   nop
    /* 1C9B80 002C9B80 900C248E */  lw         $4, 0xC90($17)
    /* 1C9B84 002C9B84 2D280000 */  daddu      $5, $0, $0
    /* 1C9B88 002C9B88 01000624 */  addiu      $6, $0, 0x1
    /* 1C9B8C 002C9B8C 3C810B0C */  jal        func_002e04f0
    /* 1C9B90 002C9B90 00000000 */   nop
  .L002C9B94:
    /* 1C9B94 002C9B94 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1C9B98 002C9B98 00608244 */  mtc1       $2, $f12
    /* 1C9B9C 002C9B9C 52030224 */  addiu      $2, $0, 0x352
    /* 1C9BA0 002C9BA0 00008244 */  mtc1       $2, $f0
    /* 1C9BA4 002C9BA4 00000000 */  nop
    /* 1C9BA8 002C9BA8 60038046 */  cvt.s.w    $f13, $f0
    /* 1C9BAC 002C9BAC 2D208002 */  daddu      $4, $20, $0
    /* 1C9BB0 002C9BB0 6E112582 */  lb         $5, 0x116E($17)
    /* 1C9BB4 002C9BB4 98620B0C */  jal        func_002d8a60
    /* 1C9BB8 002C9BB8 00000000 */   nop
    /* 1C9BBC 002C9BBC 11002582 */  lb         $5, 0x11($17)
    /* 1C9BC0 002C9BC0 AEFC0224 */  addiu      $2, $0, -0x352
    /* 1C9BC4 002C9BC4 00008244 */  mtc1       $2, $f0
    /* 1C9BC8 002C9BC8 00000000 */  nop
    /* 1C9BCC 002C9BCC 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9BD0 002C9BD0 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1C9BD4 002C9BD4 00688244 */  mtc1       $2, $f13
    /* 1C9BD8 002C9BD8 2D208002 */  daddu      $4, $20, $0
    /* 1C9BDC 002C9BDC 98620B0C */  jal        func_002d8a60
    /* 1C9BE0 002C9BE0 00000000 */   nop
    /* 1C9BE4 002C9BE4 70112486 */  lh         $4, 0x1170($17)
    /* 1C9BE8 002C9BE8 01000524 */  addiu      $5, $0, 0x1
    /* 1C9BEC 002C9BEC 2D300000 */  daddu      $6, $0, $0
    /* 1C9BF0 002C9BF0 2D380000 */  daddu      $7, $0, $0
    /* 1C9BF4 002C9BF4 2D40A000 */  daddu      $8, $5, $0
    /* 1C9BF8 002C9BF8 40CB0A0C */  jal        func_002b2d00
    /* 1C9BFC 002C9BFC 00000000 */   nop
    /* 1C9C00 002C9C00 701122A6 */  sh         $2, 0x1170($17)
    /* 1C9C04 002C9C04 3C140200 */  dsll32     $2, $2, 16
    /* 1C9C08 002C9C08 3F140200 */  dsra32     $2, $2, 16
    /* 1C9C0C 002C9C0C C6024014 */  bnez       $2, .L002CA728
    /* 1C9C10 002C9C10 00000000 */   nop
    /* 1C9C14 002C9C14 24000224 */  addiu      $2, $0, 0x24
    /* 1C9C18 002C9C18 000022A2 */  sb         $2, 0x0($17)
    /* 1C9C1C 002C9C1C C2020010 */  b          .L002CA728
    /* 1C9C20 002C9C20 00000000 */   nop
    /* 1C9C24 002C9C24 11002282 */  lb         $2, 0x11($17)
    /* 1C9C28 002C9C28 80100200 */  sll        $2, $2, 2
    /* 1C9C2C 002C9C2C 21105100 */  addu       $2, $2, $17
    /* 1C9C30 002C9C30 180F448C */  lw         $4, 0xF18($2)
    /* 1C9C34 002C9C34 BC890B0C */  jal        func_002e26f0
    /* 1C9C38 002C9C38 00000000 */   nop
    /* 1C9C3C 002C9C3C 06004128 */  slti       $1, $2, 0x6
    /* 1C9C40 002C9C40 5A002014 */  bnez       $1, .L002C9DAC
    /* 1C9C44 002C9C44 00000000 */   nop
    /* 1C9C48 002C9C48 11003082 */  lb         $16, 0x11($17)
    /* 1C9C4C 002C9C4C 80101000 */  sll        $2, $16, 2
    /* 1C9C50 002C9C50 21105100 */  addu       $2, $2, $17
    /* 1C9C54 002C9C54 180F448C */  lw         $4, 0xF18($2)
    /* 1C9C58 002C9C58 BC890B0C */  jal        func_002e26f0
    /* 1C9C5C 002C9C5C 00000000 */   nop
    /* 1C9C60 002C9C60 7500033C */  lui        $3, %hi(D_00748908)
    /* 1C9C64 002C9C64 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1C9C68 002C9C68 21187000 */  addu       $3, $3, $16
    /* 1C9C6C 002C9C6C 00006380 */  lb         $3, 0x0($3)
    /* 1C9C70 002C9C70 2A086200 */  slt        $1, $3, $2
    /* 1C9C74 002C9C74 41002010 */  beqz       $1, .L002C9D7C
    /* 1C9C78 002C9C78 00000000 */   nop
    /* 1C9C7C 002C9C7C 80101000 */  sll        $2, $16, 2
    /* 1C9C80 002C9C80 21105100 */  addu       $2, $2, $17
    /* 1C9C84 002C9C84 180F448C */  lw         $4, 0xF18($2)
    /* 1C9C88 002C9C88 BC890B0C */  jal        func_002e26f0
    /* 1C9C8C 002C9C8C 00000000 */   nop
    /* 1C9C90 002C9C90 06004128 */  slti       $1, $2, 0x6
    /* 1C9C94 002C9C94 10002014 */  bnez       $1, .L002C9CD8
    /* 1C9C98 002C9C98 00000000 */   nop
    /* 1C9C9C 002C9C9C 11002282 */  lb         $2, 0x11($17)
    /* 1C9CA0 002C9CA0 80100200 */  sll        $2, $2, 2
    /* 1C9CA4 002C9CA4 21105100 */  addu       $2, $2, $17
    /* 1C9CA8 002C9CA8 180F448C */  lw         $4, 0xF18($2)
    /* 1C9CAC 002C9CAC BC890B0C */  jal        func_002e26f0
    /* 1C9CB0 002C9CB0 00000000 */   nop
    /* 1C9CB4 002C9CB4 FBFF4224 */  addiu      $2, $2, -0x5
    /* 1C9CB8 002C9CB8 00008244 */  mtc1       $2, $f0
    /* 1C9CBC 002C9CBC 00000000 */  nop
    /* 1C9CC0 002C9CC0 60008046 */  cvt.s.w    $f1, $f0
    /* 1C9CC4 002C9CC4 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1C9CC8 002C9CC8 00008244 */  mtc1       $2, $f0
    /* 1C9CCC 002C9CCC 00000000 */  nop
    /* 1C9CD0 002C9CD0 03000146 */  div.s      $f0, $f0, $f1
    /* 1C9CD4 002C9CD4 0C0020E6 */  swc1       $f0, 0xC($17)
  .L002C9CD8:
    /* 1C9CD8 002C9CD8 02002386 */  lh         $3, 0x2($17)
    /* 1C9CDC 002C9CDC 04002286 */  lh         $2, 0x4($17)
    /* 1C9CE0 002C9CE0 23106200 */  subu       $2, $3, $2
    /* 1C9CE4 002C9CE4 00008244 */  mtc1       $2, $f0
    /* 1C9CE8 002C9CE8 00000000 */  nop
    /* 1C9CEC 002C9CEC E0008046 */  cvt.s.w    $f3, $f0
    /* 1C9CF0 002C9CF0 0C0022C6 */  lwc1       $f2, 0xC($17)
    /* 1C9CF4 002C9CF4 0E43023C */  lui        $2, (0x430E0000 >> 16)
    /* 1C9CF8 002C9CF8 00088244 */  mtc1       $2, $f1
    /* 1C9CFC 002C9CFC 00008044 */  mtc1       $0, $f0
    /* 1C9D00 002C9D00 00000000 */  nop
    /* 1C9D04 002C9D04 18000146 */  adda.s     $f0, $f1
    /* 1C9D08 002C9D08 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1C9D0C 002C9D0C 21020224 */  addiu      $2, $0, 0x221
    /* 1C9D10 002C9D10 00008244 */  mtc1       $2, $f0
    /* 1C9D14 002C9D14 00000000 */  nop
    /* 1C9D18 002C9D18 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9D1C 002C9D1C 8801A427 */  addiu      $4, $29, 0x188
    /* 1C9D20 002C9D20 5CCA0A0C */  jal        func_002b2970
    /* 1C9D24 002C9D24 00000000 */   nop
    /* 1C9D28 002C9D28 FF000424 */  addiu      $4, $0, 0xFF
    /* 1C9D2C 002C9D2C FE000524 */  addiu      $5, $0, 0xFE
    /* 1C9D30 002C9D30 C6000624 */  addiu      $6, $0, 0xC6
    /* 1C9D34 002C9D34 31000724 */  addiu      $7, $0, 0x31
    /* 1C9D38 002C9D38 8CCA0A0C */  jal        func_002b2a30
    /* 1C9D3C 002C9D3C 00000000 */   nop
    /* 1C9D40 002C9D40 2D804000 */  daddu      $16, $2, $0
    /* 1C9D44 002C9D44 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C9D48 002C9D48 38810B0C */  jal        func_002e04e0
    /* 1C9D4C 002C9D4C 00000000 */   nop
    /* 1C9D50 002C9D50 0A43033C */  lui        $3, (0x430A0000 >> 16)
    /* 1C9D54 002C9D54 00608344 */  mtc1       $3, $f12
    /* 1C9D58 002C9D58 36000424 */  addiu      $4, $0, 0x36
    /* 1C9D5C 002C9D5C 8801A5DF */  ld         $5, 0x188($29)
    /* 1C9D60 002C9D60 2D300002 */  daddu      $6, $16, $0
    /* 1C9D64 002C9D64 62004790 */  lbu        $7, 0x62($2)
    /* 1C9D68 002C9D68 2D400000 */  daddu      $8, $0, $0
    /* 1C9D6C 002C9D6C 7900093C */  lui        $9, %hi(D_00794EA0)
    /* 1C9D70 002C9D70 A04E2925 */  addiu      $9, $9, %lo(D_00794EA0)
    /* 1C9D74 002C9D74 C8820B0C */  jal        func_002e0b20
    /* 1C9D78 002C9D78 00000000 */   nop
  .L002C9D7C:
    /* 1C9D7C 002C9D7C 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C9D80 002C9D80 2D280000 */  daddu      $5, $0, $0
    /* 1C9D84 002C9D84 2D300000 */  daddu      $6, $0, $0
    /* 1C9D88 002C9D88 3C810B0C */  jal        func_002e04f0
    /* 1C9D8C 002C9D8C 00000000 */   nop
    /* 1C9D90 002C9D90 900C248E */  lw         $4, 0xC90($17)
    /* 1C9D94 002C9D94 2D280000 */  daddu      $5, $0, $0
    /* 1C9D98 002C9D98 2D300000 */  daddu      $6, $0, $0
    /* 1C9D9C 002C9D9C 3C810B0C */  jal        func_002e04f0
    /* 1C9DA0 002C9DA0 00000000 */   nop
    /* 1C9DA4 002C9DA4 0B000010 */  b          .L002C9DD4
    /* 1C9DA8 002C9DA8 00000000 */   nop
  .L002C9DAC:
    /* 1C9DAC 002C9DAC 8C0C248E */  lw         $4, 0xC8C($17)
    /* 1C9DB0 002C9DB0 2D280000 */  daddu      $5, $0, $0
    /* 1C9DB4 002C9DB4 01000624 */  addiu      $6, $0, 0x1
    /* 1C9DB8 002C9DB8 3C810B0C */  jal        func_002e04f0
    /* 1C9DBC 002C9DBC 00000000 */   nop
    /* 1C9DC0 002C9DC0 900C248E */  lw         $4, 0xC90($17)
    /* 1C9DC4 002C9DC4 2D280000 */  daddu      $5, $0, $0
    /* 1C9DC8 002C9DC8 01000624 */  addiu      $6, $0, 0x1
    /* 1C9DCC 002C9DCC 3C810B0C */  jal        func_002e04f0
    /* 1C9DD0 002C9DD0 00000000 */   nop
  .L002C9DD4:
    /* 1C9DD4 002C9DD4 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1C9DD8 002C9DD8 00608244 */  mtc1       $2, $f12
    /* 1C9DDC 002C9DDC AEFC0224 */  addiu      $2, $0, -0x352
    /* 1C9DE0 002C9DE0 00008244 */  mtc1       $2, $f0
    /* 1C9DE4 002C9DE4 00000000 */  nop
    /* 1C9DE8 002C9DE8 60038046 */  cvt.s.w    $f13, $f0
    /* 1C9DEC 002C9DEC 2D208002 */  daddu      $4, $20, $0
    /* 1C9DF0 002C9DF0 6E112582 */  lb         $5, 0x116E($17)
    /* 1C9DF4 002C9DF4 98620B0C */  jal        func_002d8a60
    /* 1C9DF8 002C9DF8 00000000 */   nop
    /* 1C9DFC 002C9DFC 11002582 */  lb         $5, 0x11($17)
    /* 1C9E00 002C9E00 52030224 */  addiu      $2, $0, 0x352
    /* 1C9E04 002C9E04 00008244 */  mtc1       $2, $f0
    /* 1C9E08 002C9E08 00000000 */  nop
    /* 1C9E0C 002C9E0C 20038046 */  cvt.s.w    $f12, $f0
    /* 1C9E10 002C9E10 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1C9E14 002C9E14 00688244 */  mtc1       $2, $f13
    /* 1C9E18 002C9E18 2D208002 */  daddu      $4, $20, $0
    /* 1C9E1C 002C9E1C 98620B0C */  jal        func_002d8a60
    /* 1C9E20 002C9E20 00000000 */   nop
    /* 1C9E24 002C9E24 70112486 */  lh         $4, 0x1170($17)
    /* 1C9E28 002C9E28 01000524 */  addiu      $5, $0, 0x1
    /* 1C9E2C 002C9E2C 2D300000 */  daddu      $6, $0, $0
    /* 1C9E30 002C9E30 2D380000 */  daddu      $7, $0, $0
    /* 1C9E34 002C9E34 2D40A000 */  daddu      $8, $5, $0
    /* 1C9E38 002C9E38 40CB0A0C */  jal        func_002b2d00
    /* 1C9E3C 002C9E3C 00000000 */   nop
    /* 1C9E40 002C9E40 701122A6 */  sh         $2, 0x1170($17)
    /* 1C9E44 002C9E44 3C140200 */  dsll32     $2, $2, 16
    /* 1C9E48 002C9E48 3F140200 */  dsra32     $2, $2, 16
    /* 1C9E4C 002C9E4C 36024014 */  bnez       $2, .L002CA728
    /* 1C9E50 002C9E50 00000000 */   nop
    /* 1C9E54 002C9E54 24000224 */  addiu      $2, $0, 0x24
    /* 1C9E58 002C9E58 000022A2 */  sb         $2, 0x0($17)
    /* 1C9E5C 002C9E5C 32020010 */  b          .L002CA728
    /* 1C9E60 002C9E60 00000000 */   nop
    /* 1C9E64 002C9E64 6400043C */  lui        $4, %hi(D_0063FB10)
    /* 1C9E68 002C9E68 10FB8424 */  addiu      $4, $4, %lo(D_0063FB10)
    /* 1C9E6C 002C9E6C E048110C */  jal        func_00452380
    /* 1C9E70 002C9E70 00000000 */   nop
    /* 1C9E74 002C9E74 2C024014 */  bnez       $2, .L002CA728
    /* 1C9E78 002C9E78 00000000 */   nop
    /* 1C9E7C 002C9E7C 2D800000 */  daddu      $16, $0, $0
    /* 1C9E80 002C9E80 0B000010 */  b          .L002C9EB0
    /* 1C9E84 002C9E84 00000000 */   nop
  .L002C9E88:
    /* 1C9E88 002C9E88 80100300 */  sll        $2, $3, 2
    /* 1C9E8C 002C9E8C 21102202 */  addu       $2, $17, $2
    /* 1C9E90 002C9E90 200D448C */  lw         $4, 0xD20($2)
    /* 1C9E94 002C9E94 2D280000 */  daddu      $5, $0, $0
    /* 1C9E98 002C9E98 2D300000 */  daddu      $6, $0, $0
    /* 1C9E9C 002C9E9C 3C810B0C */  jal        func_002e04f0
    /* 1C9EA0 002C9EA0 00000000 */   nop
    /* 1C9EA4 002C9EA4 01000226 */  addiu      $2, $16, 0x1
    /* 1C9EA8 002C9EA8 3C840200 */  dsll32     $16, $2, 16
    /* 1C9EAC 002C9EAC 3F841000 */  dsra32     $16, $16, 16
  .L002C9EB0:
    /* 1C9EB0 002C9EB0 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C9EB4 002C9EB4 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C9EB8 002C9EB8 07006228 */  slti       $2, $3, 0x7
    /* 1C9EBC 002C9EBC F2FF4014 */  bnez       $2, .L002C9E88
    /* 1C9EC0 002C9EC0 00000000 */   nop
    /* 1C9EC4 002C9EC4 440C248E */  lw         $4, 0xC44($17)
    /* 1C9EC8 002C9EC8 2D280000 */  daddu      $5, $0, $0
    /* 1C9ECC 002C9ECC 2D300000 */  daddu      $6, $0, $0
    /* 1C9ED0 002C9ED0 3C810B0C */  jal        func_002e04f0
    /* 1C9ED4 002C9ED4 00000000 */   nop
    /* 1C9ED8 002C9ED8 480C248E */  lw         $4, 0xC48($17)
    /* 1C9EDC 002C9EDC 2D280000 */  daddu      $5, $0, $0
    /* 1C9EE0 002C9EE0 2D300000 */  daddu      $6, $0, $0
    /* 1C9EE4 002C9EE4 3C810B0C */  jal        func_002e04f0
    /* 1C9EE8 002C9EE8 00000000 */   nop
    /* 1C9EEC 002C9EEC EC0D248E */  lw         $4, 0xDEC($17)
    /* 1C9EF0 002C9EF0 2D280000 */  daddu      $5, $0, $0
    /* 1C9EF4 002C9EF4 2D300000 */  daddu      $6, $0, $0
    /* 1C9EF8 002C9EF8 3C810B0C */  jal        func_002e04f0
    /* 1C9EFC 002C9EFC 00000000 */   nop
    /* 1C9F00 002C9F00 2D800000 */  daddu      $16, $0, $0
    /* 1C9F04 002C9F04 0E000010 */  b          .L002C9F40
    /* 1C9F08 002C9F08 00000000 */   nop
  .L002C9F0C:
    /* 1C9F0C 002C9F0C 80100300 */  sll        $2, $3, 2
    /* 1C9F10 002C9F10 21102202 */  addu       $2, $17, $2
    /* 1C9F14 002C9F14 380C448C */  lw         $4, 0xC38($2)
    /* 1C9F18 002C9F18 2D280000 */  daddu      $5, $0, $0
    /* 1C9F1C 002C9F1C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C9F20 002C9F20 2D380000 */  daddu      $7, $0, $0
    /* 1C9F24 002C9F24 0A000824 */  addiu      $8, $0, 0xA
    /* 1C9F28 002C9F28 2D480000 */  daddu      $9, $0, $0
    /* 1C9F2C 002C9F2C 98810B0C */  jal        func_002e0660
    /* 1C9F30 002C9F30 00000000 */   nop
    /* 1C9F34 002C9F34 01000226 */  addiu      $2, $16, 0x1
    /* 1C9F38 002C9F38 3C840200 */  dsll32     $16, $2, 16
    /* 1C9F3C 002C9F3C 3F841000 */  dsra32     $16, $16, 16
  .L002C9F40:
    /* 1C9F40 002C9F40 3C1C1000 */  dsll32     $3, $16, 16
    /* 1C9F44 002C9F44 3F1C0300 */  dsra32     $3, $3, 16
    /* 1C9F48 002C9F48 03006228 */  slti       $2, $3, 0x3
    /* 1C9F4C 002C9F4C EFFF4014 */  bnez       $2, .L002C9F0C
    /* 1C9F50 002C9F50 00000000 */   nop
    /* 1C9F54 002C9F54 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1C9F58 002C9F58 2D280000 */  daddu      $5, $0, $0
    /* 1C9F5C 002C9F5C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C9F60 002C9F60 2D380000 */  daddu      $7, $0, $0
    /* 1C9F64 002C9F64 0A000824 */  addiu      $8, $0, 0xA
    /* 1C9F68 002C9F68 2D480000 */  daddu      $9, $0, $0
    /* 1C9F6C 002C9F6C 98810B0C */  jal        func_002e0660
    /* 1C9F70 002C9F70 00000000 */   nop
    /* 1C9F74 002C9F74 900D248E */  lw         $4, 0xD90($17)
    /* 1C9F78 002C9F78 2D280000 */  daddu      $5, $0, $0
    /* 1C9F7C 002C9F7C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C9F80 002C9F80 2D380000 */  daddu      $7, $0, $0
    /* 1C9F84 002C9F84 0A000824 */  addiu      $8, $0, 0xA
    /* 1C9F88 002C9F88 2D480000 */  daddu      $9, $0, $0
    /* 1C9F8C 002C9F8C 98810B0C */  jal        func_002e0660
    /* 1C9F90 002C9F90 00000000 */   nop
    /* 1C9F94 002C9F94 940D248E */  lw         $4, 0xD94($17)
    /* 1C9F98 002C9F98 2D280000 */  daddu      $5, $0, $0
    /* 1C9F9C 002C9F9C FF000624 */  addiu      $6, $0, 0xFF
    /* 1C9FA0 002C9FA0 2D380000 */  daddu      $7, $0, $0
    /* 1C9FA4 002C9FA4 0A000824 */  addiu      $8, $0, 0xA
    /* 1C9FA8 002C9FA8 2D480000 */  daddu      $9, $0, $0
    /* 1C9FAC 002C9FAC 98810B0C */  jal        func_002e0660
    /* 1C9FB0 002C9FB0 00000000 */   nop
    /* 1C9FB4 002C9FB4 3F43023C */  lui        $2, (0x433F0000 >> 16)
    /* 1C9FB8 002C9FB8 00608244 */  mtc1       $2, $f12
    /* 1C9FBC 002C9FBC 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1C9FC0 002C9FC0 40000524 */  addiu      $5, $0, 0x40
    /* 1C9FC4 002C9FC4 78820B0C */  jal        func_002e09e0
    /* 1C9FC8 002C9FC8 00000000 */   nop
    /* 1C9FCC 002C9FCC 280F248E */  lw         $4, 0xF28($17)
    /* 1C9FD0 002C9FD0 05000524 */  addiu      $5, $0, 0x5
    /* 1C9FD4 002C9FD4 80B4110C */  jal        func_0046d200
    /* 1C9FD8 002C9FD8 00000000 */   nop
    /* 1C9FDC 002C9FDC 2D804000 */  daddu      $16, $2, $0
    /* 1C9FE0 002C9FE0 2D200002 */  daddu      $4, $16, $0
    /* 1C9FE4 002C9FE4 98AC110C */  jal        func_0046b260
    /* 1C9FE8 002C9FE8 00000000 */   nop
    /* 1C9FEC 002C9FEC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1C9FF0 002C9FF0 00000244 */  mfc1       $2, $f0
    /* 1C9FF4 002C9FF4 00000000 */  nop
    /* 1C9FF8 002C9FF8 3C940200 */  dsll32     $18, $2, 16
    /* 1C9FFC 002C9FFC 3F941200 */  dsra32     $18, $18, 16
    /* 1CA000 002CA000 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1CA004 002CA004 38810B0C */  jal        func_002e04e0
    /* 1CA008 002CA008 00000000 */   nop
    /* 1CA00C 002CA00C 000152A4 */  sh         $18, 0x100($2)
    /* 1CA010 002CA010 2D200002 */  daddu      $4, $16, $0
    /* 1CA014 002CA014 BCAC110C */  jal        func_0046b2f0
    /* 1CA018 002CA018 00000000 */   nop
    /* 1CA01C 002CA01C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CA020 002CA020 00000244 */  mfc1       $2, $f0
    /* 1CA024 002CA024 00000000 */  nop
    /* 1CA028 002CA028 3C940200 */  dsll32     $18, $2, 16
    /* 1CA02C 002CA02C 3F941200 */  dsra32     $18, $18, 16
    /* 1CA030 002CA030 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1CA034 002CA034 38810B0C */  jal        func_002e04e0
    /* 1CA038 002CA038 00000000 */   nop
    /* 1CA03C 002CA03C 020152A4 */  sh         $18, 0x102($2)
    /* 1CA040 002CA040 2D200002 */  daddu      $4, $16, $0
    /* 1CA044 002CA044 A0B4110C */  jal        func_0046d280
    /* 1CA048 002CA048 00000000 */   nop
    /* 1CA04C 002CA04C 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1CA050 002CA050 2D280000 */  daddu      $5, $0, $0
    /* 1CA054 002CA054 CC000624 */  addiu      $6, $0, 0xCC
    /* 1CA058 002CA058 2D380000 */  daddu      $7, $0, $0
    /* 1CA05C 002CA05C 04000824 */  addiu      $8, $0, 0x4
    /* 1CA060 002CA060 2D480001 */  daddu      $9, $8, $0
    /* 1CA064 002CA064 98810B0C */  jal        func_002e0660
    /* 1CA068 002CA068 00000000 */   nop
    /* 1CA06C 002CA06C 00608044 */  mtc1       $0, $f12
    /* 1CA070 002CA070 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1CA074 002CA074 20858DC7 */  lwc1       $f13, -0x7AE0($28)
    /* 1CA078 002CA078 2D280000 */  daddu      $5, $0, $0
    /* 1CA07C 002CA07C 04000624 */  addiu      $6, $0, 0x4
    /* 1CA080 002CA080 2D38C000 */  daddu      $7, $6, $0
    /* 1CA084 002CA084 50820B0C */  jal        func_002e0940
    /* 1CA088 002CA088 00000000 */   nop
    /* 1CA08C 002CA08C 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1CA090 002CA090 00608244 */  mtc1       $2, $f12
    /* 1CA094 002CA094 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 1CA098 002CA098 00688244 */  mtc1       $2, $f13
    /* 1CA09C 002CA09C 8001A427 */  addiu      $4, $29, 0x180
    /* 1CA0A0 002CA0A0 5CCA0A0C */  jal        func_002b2970
    /* 1CA0A4 002CA0A4 00000000 */   nop
    /* 1CA0A8 002CA0A8 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1CA0AC 002CA0AC 00608244 */  mtc1       $2, $f12
    /* 1CA0B0 002CA0B0 9B43023C */  lui        $2, (0x439B0000 >> 16)
    /* 1CA0B4 002CA0B4 00688244 */  mtc1       $2, $f13
    /* 1CA0B8 002CA0B8 7801A427 */  addiu      $4, $29, 0x178
    /* 1CA0BC 002CA0BC 5CCA0A0C */  jal        func_002b2970
    /* 1CA0C0 002CA0C0 00000000 */   nop
    /* 1CA0C4 002CA0C4 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1CA0C8 002CA0C8 8001A5DF */  ld         $5, 0x180($29)
    /* 1CA0CC 002CA0CC 7801A6DF */  ld         $6, 0x178($29)
    /* 1CA0D0 002CA0D0 2D380000 */  daddu      $7, $0, $0
    /* 1CA0D4 002CA0D4 04000824 */  addiu      $8, $0, 0x4
    /* 1CA0D8 002CA0D8 2D480001 */  daddu      $9, $8, $0
    /* 1CA0DC 002CA0DC 88810B0C */  jal        func_002e0620
    /* 1CA0E0 002CA0E0 00000000 */   nop
    /* 1CA0E4 002CA0E4 4043023C */  lui        $2, (0x43400000 >> 16)
    /* 1CA0E8 002CA0E8 00608244 */  mtc1       $2, $f12
    /* 1CA0EC 002CA0EC 500C248E */  lw         $4, 0xC50($17)
    /* 1CA0F0 002CA0F0 40000524 */  addiu      $5, $0, 0x40
    /* 1CA0F4 002CA0F4 78820B0C */  jal        func_002e09e0
    /* 1CA0F8 002CA0F8 00000000 */   nop
    /* 1CA0FC 002CA0FC DC42023C */  lui        $2, (0x42DC0000 >> 16)
    /* 1CA100 002CA100 00A08244 */  mtc1       $2, $f20
    /* 1CA104 002CA104 500C248E */  lw         $4, 0xC50($17)
    /* 1CA108 002CA108 38810B0C */  jal        func_002e04e0
    /* 1CA10C 002CA10C 00000000 */   nop
    /* 1CA110 002CA110 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1CA114 002CA114 48C2023C */  lui        $2, (0xC2480000 >> 16)
    /* 1CA118 002CA118 00A08244 */  mtc1       $2, $f20
    /* 1CA11C 002CA11C 500C248E */  lw         $4, 0xC50($17)
    /* 1CA120 002CA120 38810B0C */  jal        func_002e04e0
    /* 1CA124 002CA124 00000000 */   nop
    /* 1CA128 002CA128 300054E4 */  swc1       $f20, 0x30($2)
    /* 1CA12C 002CA12C 280F248E */  lw         $4, 0xF28($17)
    /* 1CA130 002CA130 06000524 */  addiu      $5, $0, 0x6
    /* 1CA134 002CA134 80B4110C */  jal        func_0046d200
    /* 1CA138 002CA138 00000000 */   nop
    /* 1CA13C 002CA13C 2D804000 */  daddu      $16, $2, $0
    /* 1CA140 002CA140 2D200002 */  daddu      $4, $16, $0
    /* 1CA144 002CA144 98AC110C */  jal        func_0046b260
    /* 1CA148 002CA148 00000000 */   nop
    /* 1CA14C 002CA14C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CA150 002CA150 00000244 */  mfc1       $2, $f0
    /* 1CA154 002CA154 00000000 */  nop
    /* 1CA158 002CA158 3C940200 */  dsll32     $18, $2, 16
    /* 1CA15C 002CA15C 3F941200 */  dsra32     $18, $18, 16
    /* 1CA160 002CA160 500C248E */  lw         $4, 0xC50($17)
    /* 1CA164 002CA164 38810B0C */  jal        func_002e04e0
    /* 1CA168 002CA168 00000000 */   nop
    /* 1CA16C 002CA16C 000152A4 */  sh         $18, 0x100($2)
    /* 1CA170 002CA170 500C248E */  lw         $4, 0xC50($17)
    /* 1CA174 002CA174 38810B0C */  jal        func_002e04e0
    /* 1CA178 002CA178 00000000 */   nop
    /* 1CA17C 002CA17C 020140A4 */  sh         $0, 0x102($2)
    /* 1CA180 002CA180 B4C2023C */  lui        $2, (0xC2B40000 >> 16)
    /* 1CA184 002CA184 00608244 */  mtc1       $2, $f12
    /* 1CA188 002CA188 500C248E */  lw         $4, 0xC50($17)
    /* 1CA18C 002CA18C 24858DC7 */  lwc1       $f13, -0x7ADC($28)
    /* 1CA190 002CA190 2D280000 */  daddu      $5, $0, $0
    /* 1CA194 002CA194 04000624 */  addiu      $6, $0, 0x4
    /* 1CA198 002CA198 2D38C000 */  daddu      $7, $6, $0
    /* 1CA19C 002CA19C 50820B0C */  jal        func_002e0940
    /* 1CA1A0 002CA1A0 00000000 */   nop
    /* 1CA1A4 002CA1A4 500C248E */  lw         $4, 0xC50($17)
    /* 1CA1A8 002CA1A8 2D280000 */  daddu      $5, $0, $0
    /* 1CA1AC 002CA1AC FF000624 */  addiu      $6, $0, 0xFF
    /* 1CA1B0 002CA1B0 2D380000 */  daddu      $7, $0, $0
    /* 1CA1B4 002CA1B4 04000824 */  addiu      $8, $0, 0x4
    /* 1CA1B8 002CA1B8 2D480001 */  daddu      $9, $8, $0
    /* 1CA1BC 002CA1BC 98810B0C */  jal        func_002e0660
    /* 1CA1C0 002CA1C0 00000000 */   nop
    /* 1CA1C4 002CA1C4 2D200002 */  daddu      $4, $16, $0
    /* 1CA1C8 002CA1C8 A0B4110C */  jal        func_0046d280
    /* 1CA1CC 002CA1CC 00000000 */   nop
    /* 1CA1D0 002CA1D0 3E43023C */  lui        $2, (0x433E0000 >> 16)
    /* 1CA1D4 002CA1D4 00608244 */  mtc1       $2, $f12
    /* 1CA1D8 002CA1D8 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA1DC 002CA1DC 40000524 */  addiu      $5, $0, 0x40
    /* 1CA1E0 002CA1E0 78820B0C */  jal        func_002e09e0
    /* 1CA1E4 002CA1E4 00000000 */   nop
    /* 1CA1E8 002CA1E8 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1CA1EC 002CA1EC 00A08244 */  mtc1       $2, $f20
    /* 1CA1F0 002CA1F0 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA1F4 002CA1F4 38810B0C */  jal        func_002e04e0
    /* 1CA1F8 002CA1F8 00000000 */   nop
    /* 1CA1FC 002CA1FC 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1CA200 002CA200 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1CA204 002CA204 00A08244 */  mtc1       $2, $f20
    /* 1CA208 002CA208 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA20C 002CA20C 38810B0C */  jal        func_002e04e0
    /* 1CA210 002CA210 00000000 */   nop
    /* 1CA214 002CA214 300054E4 */  swc1       $f20, 0x30($2)
    /* 1CA218 002CA218 280F248E */  lw         $4, 0xF28($17)
    /* 1CA21C 002CA21C 06000524 */  addiu      $5, $0, 0x6
    /* 1CA220 002CA220 80B4110C */  jal        func_0046d200
    /* 1CA224 002CA224 00000000 */   nop
    /* 1CA228 002CA228 2D904000 */  daddu      $18, $2, $0
    /* 1CA22C 002CA22C 2D204002 */  daddu      $4, $18, $0
    /* 1CA230 002CA230 98AC110C */  jal        func_0046b260
    /* 1CA234 002CA234 00000000 */   nop
    /* 1CA238 002CA238 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CA23C 002CA23C 00000244 */  mfc1       $2, $f0
    /* 1CA240 002CA240 00000000 */  nop
    /* 1CA244 002CA244 3C840200 */  dsll32     $16, $2, 16
    /* 1CA248 002CA248 3F841000 */  dsra32     $16, $16, 16
    /* 1CA24C 002CA24C 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA250 002CA250 38810B0C */  jal        func_002e04e0
    /* 1CA254 002CA254 00000000 */   nop
    /* 1CA258 002CA258 000150A4 */  sh         $16, 0x100($2)
    /* 1CA25C 002CA25C 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA260 002CA260 38810B0C */  jal        func_002e04e0
    /* 1CA264 002CA264 00000000 */   nop
    /* 1CA268 002CA268 020140A4 */  sh         $0, 0x102($2)
    /* 1CA26C 002CA26C 2D204002 */  daddu      $4, $18, $0
    /* 1CA270 002CA270 A0B4110C */  jal        func_0046d280
    /* 1CA274 002CA274 00000000 */   nop
    /* 1CA278 002CA278 AAC2023C */  lui        $2, (0xC2AA0000 >> 16)
    /* 1CA27C 002CA27C 00608244 */  mtc1       $2, $f12
    /* 1CA280 002CA280 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA284 002CA284 28858DC7 */  lwc1       $f13, -0x7AD8($28)
    /* 1CA288 002CA288 2D280000 */  daddu      $5, $0, $0
    /* 1CA28C 002CA28C 04000624 */  addiu      $6, $0, 0x4
    /* 1CA290 002CA290 02000724 */  addiu      $7, $0, 0x2
    /* 1CA294 002CA294 50820B0C */  jal        func_002e0940
    /* 1CA298 002CA298 00000000 */   nop
    /* 1CA29C 002CA29C 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA2A0 002CA2A0 2D280000 */  daddu      $5, $0, $0
    /* 1CA2A4 002CA2A4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CA2A8 002CA2A8 2D380000 */  daddu      $7, $0, $0
    /* 1CA2AC 002CA2AC 04000824 */  addiu      $8, $0, 0x4
    /* 1CA2B0 002CA2B0 02000924 */  addiu      $9, $0, 0x2
    /* 1CA2B4 002CA2B4 98810B0C */  jal        func_002e0660
    /* 1CA2B8 002CA2B8 00000000 */   nop
    /* 1CA2BC 002CA2BC 2DA80000 */  daddu      $21, $0, $0
    /* 1CA2C0 002CA2C0 4C000010 */  b          .L002CA3F4
    /* 1CA2C4 002CA2C4 00000000 */   nop
  .L002CA2C8:
    /* 1CA2C8 002CA2C8 3C9C1500 */  dsll32     $19, $21, 16
    /* 1CA2CC 002CA2CC 3F9C1300 */  dsra32     $19, $19, 16
    /* 1CA2D0 002CA2D0 3A006226 */  addiu      $2, $19, 0x3A
    /* 1CA2D4 002CA2D4 C0180200 */  sll        $3, $2, 3
    /* 1CA2D8 002CA2D8 6400023C */  lui        $2, %hi(D_0063F560)
    /* 1CA2DC 002CA2DC 60F54224 */  addiu      $2, $2, %lo(D_0063F560)
    /* 1CA2E0 002CA2E0 21904300 */  addu       $18, $2, $3
    /* 1CA2E4 002CA2E4 80101300 */  sll        $2, $19, 2
    /* 1CA2E8 002CA2E8 21182202 */  addu       $3, $17, $2
    /* 1CA2EC 002CA2EC 200D7024 */  addiu      $16, $3, 0xD20
    /* 1CA2F0 002CA2F0 64006226 */  addiu      $2, $19, 0x64
    /* 1CA2F4 002CA2F4 00008244 */  mtc1       $2, $f0
    /* 1CA2F8 002CA2F8 00000000 */  nop
    /* 1CA2FC 002CA2FC 20038046 */  cvt.s.w    $f12, $f0
    /* 1CA300 002CA300 200D648C */  lw         $4, 0xD20($3)
    /* 1CA304 002CA304 56000524 */  addiu      $5, $0, 0x56
    /* 1CA308 002CA308 78820B0C */  jal        func_002e09e0
    /* 1CA30C 002CA30C 00000000 */   nop
    /* 1CA310 002CA310 1300601A */  blez       $19, .L002CA360
    /* 1CA314 002CA314 00000000 */   nop
    /* 1CA318 002CA318 AC06A427 */  addiu      $4, $29, 0x6AC
    /* 1CA31C 002CA31C ED000524 */  addiu      $5, $0, 0xED
    /* 1CA320 002CA320 80000624 */  addiu      $6, $0, 0x80
    /* 1CA324 002CA324 2D380000 */  daddu      $7, $0, $0
    /* 1CA328 002CA328 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CA32C 002CA32C 98CA0A0C */  jal        func_002b2a60
    /* 1CA330 002CA330 00000000 */   nop
    /* 1CA334 002CA334 0000048E */  lw         $4, 0x0($16)
    /* 1CA338 002CA338 38810B0C */  jal        func_002e04e0
    /* 1CA33C 002CA33C 00000000 */   nop
    /* 1CA340 002CA340 AC06A693 */  lbu        $6, 0x6AC($29)
    /* 1CA344 002CA344 AD06A593 */  lbu        $5, 0x6AD($29)
    /* 1CA348 002CA348 AE06A493 */  lbu        $4, 0x6AE($29)
    /* 1CA34C 002CA34C AF06A393 */  lbu        $3, 0x6AF($29)
    /* 1CA350 002CA350 790046A0 */  sb         $6, 0x79($2)
    /* 1CA354 002CA354 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CA358 002CA358 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CA35C 002CA35C 7C0043A0 */  sb         $3, 0x7C($2)
  .L002CA360:
    /* 1CA360 002CA360 3C141500 */  dsll32     $2, $21, 16
    /* 1CA364 002CA364 3F140200 */  dsra32     $2, $2, 16
    /* 1CA368 002CA368 80100200 */  sll        $2, $2, 2
    /* 1CA36C 002CA36C 21102202 */  addu       $2, $17, $2
    /* 1CA370 002CA370 200D5024 */  addiu      $16, $2, 0xD20
    /* 1CA374 002CA374 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1CA378 002CA378 00088244 */  mtc1       $2, $f1
    /* 1CA37C 002CA37C 000040C6 */  lwc1       $f0, 0x0($18)
    /* 1CA380 002CA380 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CA384 002CA384 7001A427 */  addiu      $4, $29, 0x170
    /* 1CA388 002CA388 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CA38C 002CA38C 5CCA0A0C */  jal        func_002b2970
    /* 1CA390 002CA390 00000000 */   nop
    /* 1CA394 002CA394 6801A427 */  addiu      $4, $29, 0x168
    /* 1CA398 002CA398 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CA39C 002CA39C 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CA3A0 002CA3A0 5CCA0A0C */  jal        func_002b2970
    /* 1CA3A4 002CA3A4 00000000 */   nop
    /* 1CA3A8 002CA3A8 0000048E */  lw         $4, 0x0($16)
    /* 1CA3AC 002CA3AC 7001A5DF */  ld         $5, 0x170($29)
    /* 1CA3B0 002CA3B0 6801A6DF */  ld         $6, 0x168($29)
    /* 1CA3B4 002CA3B4 2D380000 */  daddu      $7, $0, $0
    /* 1CA3B8 002CA3B8 03000824 */  addiu      $8, $0, 0x3
    /* 1CA3BC 002CA3BC 2D48A002 */  daddu      $9, $21, $0
    /* 1CA3C0 002CA3C0 88810B0C */  jal        func_002e0620
    /* 1CA3C4 002CA3C4 00000000 */   nop
    /* 1CA3C8 002CA3C8 0000048E */  lw         $4, 0x0($16)
    /* 1CA3CC 002CA3CC 2D280000 */  daddu      $5, $0, $0
    /* 1CA3D0 002CA3D0 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CA3D4 002CA3D4 2D380000 */  daddu      $7, $0, $0
    /* 1CA3D8 002CA3D8 03000824 */  addiu      $8, $0, 0x3
    /* 1CA3DC 002CA3DC 2D48A002 */  daddu      $9, $21, $0
    /* 1CA3E0 002CA3E0 98810B0C */  jal        func_002e0660
    /* 1CA3E4 002CA3E4 00000000 */   nop
    /* 1CA3E8 002CA3E8 0100A226 */  addiu      $2, $21, 0x1
    /* 1CA3EC 002CA3EC 3CAC0200 */  dsll32     $21, $2, 16
    /* 1CA3F0 002CA3F0 3FAC1500 */  dsra32     $21, $21, 16
  .L002CA3F4:
    /* 1CA3F4 002CA3F4 3C141500 */  dsll32     $2, $21, 16
    /* 1CA3F8 002CA3F8 3F140200 */  dsra32     $2, $2, 16
    /* 1CA3FC 002CA3FC 07004228 */  slti       $2, $2, 0x7
    /* 1CA400 002CA400 B1FF4014 */  bnez       $2, .L002CA2C8
    /* 1CA404 002CA404 00000000 */   nop
    /* 1CA408 002CA408 A806A427 */  addiu      $4, $29, 0x6A8
    /* 1CA40C 002CA40C 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CA410 002CA410 2D30A000 */  daddu      $6, $5, $0
    /* 1CA414 002CA414 2D38A000 */  daddu      $7, $5, $0
    /* 1CA418 002CA418 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CA41C 002CA41C 98CA0A0C */  jal        func_002b2a60
    /* 1CA420 002CA420 00000000 */   nop
    /* 1CA424 002CA424 07002282 */  lb         $2, 0x7($17)
    /* 1CA428 002CA428 80100200 */  sll        $2, $2, 2
    /* 1CA42C 002CA42C 21105100 */  addu       $2, $2, $17
    /* 1CA430 002CA430 240D448C */  lw         $4, 0xD24($2)
    /* 1CA434 002CA434 38810B0C */  jal        func_002e04e0
    /* 1CA438 002CA438 00000000 */   nop
    /* 1CA43C 002CA43C A806A693 */  lbu        $6, 0x6A8($29)
    /* 1CA440 002CA440 A906A593 */  lbu        $5, 0x6A9($29)
    /* 1CA444 002CA444 AA06A493 */  lbu        $4, 0x6AA($29)
    /* 1CA448 002CA448 AB06A393 */  lbu        $3, 0x6AB($29)
    /* 1CA44C 002CA44C 790046A0 */  sb         $6, 0x79($2)
    /* 1CA450 002CA450 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CA454 002CA454 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CA458 002CA458 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CA45C 002CA45C 07002982 */  lb         $9, 0x7($17)
    /* 1CA460 002CA460 440C248E */  lw         $4, 0xC44($17)
    /* 1CA464 002CA464 2D280000 */  daddu      $5, $0, $0
    /* 1CA468 002CA468 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CA46C 002CA46C 2D380000 */  daddu      $7, $0, $0
    /* 1CA470 002CA470 2D400000 */  daddu      $8, $0, $0
    /* 1CA474 002CA474 98810B0C */  jal        func_002e0660
    /* 1CA478 002CA478 00000000 */   nop
    /* 1CA47C 002CA47C 07002982 */  lb         $9, 0x7($17)
    /* 1CA480 002CA480 480C248E */  lw         $4, 0xC48($17)
    /* 1CA484 002CA484 2D280000 */  daddu      $5, $0, $0
    /* 1CA488 002CA488 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CA48C 002CA48C 2D380000 */  daddu      $7, $0, $0
    /* 1CA490 002CA490 2D400000 */  daddu      $8, $0, $0
    /* 1CA494 002CA494 98810B0C */  jal        func_002e0660
    /* 1CA498 002CA498 00000000 */   nop
    /* 1CA49C 002CA49C 2D208002 */  daddu      $4, $20, $0
    /* 1CA4A0 002CA4A0 E45F0B0C */  jal        func_002d7f90
    /* 1CA4A4 002CA4A4 00000000 */   nop
    /* 1CA4A8 002CA4A8 2D208002 */  daddu      $4, $20, $0
    /* 1CA4AC 002CA4AC 8C740B0C */  jal        func_002dd230
    /* 1CA4B0 002CA4B0 00000000 */   nop
    /* 1CA4B4 002CA4B4 E80D248E */  lw         $4, 0xDE8($17)
    /* 1CA4B8 002CA4B8 2D280000 */  daddu      $5, $0, $0
    /* 1CA4BC 002CA4BC 2D300000 */  daddu      $6, $0, $0
    /* 1CA4C0 002CA4C0 3C810B0C */  jal        func_002e04f0
    /* 1CA4C4 002CA4C4 00000000 */   nop
    /* 1CA4C8 002CA4C8 EC0D248E */  lw         $4, 0xDEC($17)
    /* 1CA4CC 002CA4CC 2D280000 */  daddu      $5, $0, $0
    /* 1CA4D0 002CA4D0 2D300000 */  daddu      $6, $0, $0
    /* 1CA4D4 002CA4D4 3C810B0C */  jal        func_002e04f0
    /* 1CA4D8 002CA4D8 00000000 */   nop
    /* 1CA4DC 002CA4DC 36000224 */  addiu      $2, $0, 0x36
    /* 1CA4E0 002CA4E0 000022A2 */  sb         $2, 0x0($17)
    /* 1CA4E4 002CA4E4 90000010 */  b          .L002CA728
    /* 1CA4E8 002CA4E8 00000000 */   nop
    /* 1CA4EC 002CA4EC 55001024 */  addiu      $16, $0, 0x55
    /* 1CA4F0 002CA4F0 14000010 */  b          .L002CA544
    /* 1CA4F4 002CA4F4 00000000 */   nop
  .L002CA4F8:
    /* 1CA4F8 002CA4F8 80100300 */  sll        $2, $3, 2
    /* 1CA4FC 002CA4FC 21102202 */  addu       $2, $17, $2
    /* 1CA500 002CA500 380C5224 */  addiu      $18, $2, 0xC38
    /* 1CA504 002CA504 380C448C */  lw         $4, 0xC38($2)
    /* 1CA508 002CA508 01000524 */  addiu      $5, $0, 0x1
    /* 1CA50C 002CA50C 5C810B0C */  jal        func_002e0570
    /* 1CA510 002CA510 00000000 */   nop
    /* 1CA514 002CA514 3C160200 */  dsll32     $2, $2, 24
    /* 1CA518 002CA518 3F160200 */  dsra32     $2, $2, 24
    /* 1CA51C 002CA51C 06004014 */  bnez       $2, .L002CA538
    /* 1CA520 002CA520 00000000 */   nop
    /* 1CA524 002CA524 0000448E */  lw         $4, 0x0($18)
    /* 1CA528 002CA528 03000524 */  addiu      $5, $0, 0x3
    /* 1CA52C 002CA52C 2D300000 */  daddu      $6, $0, $0
    /* 1CA530 002CA530 3C810B0C */  jal        func_002e04f0
    /* 1CA534 002CA534 00000000 */   nop
  .L002CA538:
    /* 1CA538 002CA538 01000226 */  addiu      $2, $16, 0x1
    /* 1CA53C 002CA53C 3C840200 */  dsll32     $16, $2, 16
    /* 1CA540 002CA540 3F841000 */  dsra32     $16, $16, 16
  .L002CA544:
    /* 1CA544 002CA544 3C1C1000 */  dsll32     $3, $16, 16
    /* 1CA548 002CA548 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CA54C 002CA54C 58006228 */  slti       $2, $3, 0x58
    /* 1CA550 002CA550 E9FF4014 */  bnez       $2, .L002CA4F8
    /* 1CA554 002CA554 00000000 */   nop
    /* 1CA558 002CA558 59001024 */  addiu      $16, $0, 0x59
    /* 1CA55C 002CA55C 14000010 */  b          .L002CA5B0
    /* 1CA560 002CA560 00000000 */   nop
  .L002CA564:
    /* 1CA564 002CA564 80100300 */  sll        $2, $3, 2
    /* 1CA568 002CA568 21102202 */  addu       $2, $17, $2
    /* 1CA56C 002CA56C 380C5224 */  addiu      $18, $2, 0xC38
    /* 1CA570 002CA570 380C448C */  lw         $4, 0xC38($2)
    /* 1CA574 002CA574 01000524 */  addiu      $5, $0, 0x1
    /* 1CA578 002CA578 5C810B0C */  jal        func_002e0570
    /* 1CA57C 002CA57C 00000000 */   nop
    /* 1CA580 002CA580 3C160200 */  dsll32     $2, $2, 24
    /* 1CA584 002CA584 3F160200 */  dsra32     $2, $2, 24
    /* 1CA588 002CA588 06004014 */  bnez       $2, .L002CA5A4
    /* 1CA58C 002CA58C 00000000 */   nop
    /* 1CA590 002CA590 0000448E */  lw         $4, 0x0($18)
    /* 1CA594 002CA594 03000524 */  addiu      $5, $0, 0x3
    /* 1CA598 002CA598 2D300000 */  daddu      $6, $0, $0
    /* 1CA59C 002CA59C 3C810B0C */  jal        func_002e04f0
    /* 1CA5A0 002CA5A0 00000000 */   nop
  .L002CA5A4:
    /* 1CA5A4 002CA5A4 01000226 */  addiu      $2, $16, 0x1
    /* 1CA5A8 002CA5A8 3C840200 */  dsll32     $16, $2, 16
    /* 1CA5AC 002CA5AC 3F841000 */  dsra32     $16, $16, 16
  .L002CA5B0:
    /* 1CA5B0 002CA5B0 3C1C1000 */  dsll32     $3, $16, 16
    /* 1CA5B4 002CA5B4 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CA5B8 002CA5B8 60006228 */  slti       $2, $3, 0x60
    /* 1CA5BC 002CA5BC E9FF4014 */  bnez       $2, .L002CA564
    /* 1CA5C0 002CA5C0 00000000 */   nop
    /* 1CA5C4 002CA5C4 8C0D248E */  lw         $4, 0xD8C($17)
    /* 1CA5C8 002CA5C8 01000524 */  addiu      $5, $0, 0x1
    /* 1CA5CC 002CA5CC 5C810B0C */  jal        func_002e0570
    /* 1CA5D0 002CA5D0 00000000 */   nop
    /* 1CA5D4 002CA5D4 3C160200 */  dsll32     $2, $2, 24
    /* 1CA5D8 002CA5D8 3F160200 */  dsra32     $2, $2, 24
    /* 1CA5DC 002CA5DC 52004014 */  bnez       $2, .L002CA728
    /* 1CA5E0 002CA5E0 00000000 */   nop
    /* 1CA5E4 002CA5E4 900D248E */  lw         $4, 0xD90($17)
    /* 1CA5E8 002CA5E8 01000524 */  addiu      $5, $0, 0x1
    /* 1CA5EC 002CA5EC 5C810B0C */  jal        func_002e0570
    /* 1CA5F0 002CA5F0 00000000 */   nop
    /* 1CA5F4 002CA5F4 3C160200 */  dsll32     $2, $2, 24
    /* 1CA5F8 002CA5F8 3F160200 */  dsra32     $2, $2, 24
    /* 1CA5FC 002CA5FC 4A004014 */  bnez       $2, .L002CA728
    /* 1CA600 002CA600 00000000 */   nop
    /* 1CA604 002CA604 940D248E */  lw         $4, 0xD94($17)
    /* 1CA608 002CA608 01000524 */  addiu      $5, $0, 0x1
    /* 1CA60C 002CA60C 5C810B0C */  jal        func_002e0570
    /* 1CA610 002CA610 00000000 */   nop
    /* 1CA614 002CA614 3C160200 */  dsll32     $2, $2, 24
    /* 1CA618 002CA618 3F160200 */  dsra32     $2, $2, 24
    /* 1CA61C 002CA61C 42004014 */  bnez       $2, .L002CA728
    /* 1CA620 002CA620 00000000 */   nop
    /* 1CA624 002CA624 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1CA628 002CA628 02000524 */  addiu      $5, $0, 0x2
    /* 1CA62C 002CA62C 5C810B0C */  jal        func_002e0570
    /* 1CA630 002CA630 00000000 */   nop
    /* 1CA634 002CA634 3C160200 */  dsll32     $2, $2, 24
    /* 1CA638 002CA638 3F160200 */  dsra32     $2, $2, 24
    /* 1CA63C 002CA63C 3A004014 */  bnez       $2, .L002CA728
    /* 1CA640 002CA640 00000000 */   nop
    /* 1CA644 002CA644 500C248E */  lw         $4, 0xC50($17)
    /* 1CA648 002CA648 02000524 */  addiu      $5, $0, 0x2
    /* 1CA64C 002CA64C 5C810B0C */  jal        func_002e0570
    /* 1CA650 002CA650 00000000 */   nop
    /* 1CA654 002CA654 3C160200 */  dsll32     $2, $2, 24
    /* 1CA658 002CA658 3F160200 */  dsra32     $2, $2, 24
    /* 1CA65C 002CA65C 32004014 */  bnez       $2, .L002CA728
    /* 1CA660 002CA660 00000000 */   nop
    /* 1CA664 002CA664 10000224 */  addiu      $2, $0, 0x10
    /* 1CA668 002CA668 000022A2 */  sb         $2, 0x0($17)
    /* 1CA66C 002CA66C 2E000010 */  b          .L002CA728
    /* 1CA670 002CA670 00000000 */   nop
    /* 1CA674 002CA674 4C0C248E */  lw         $4, 0xC4C($17)
    /* 1CA678 002CA678 68810B0C */  jal        func_002e05a0
    /* 1CA67C 002CA67C 00000000 */   nop
    /* 1CA680 002CA680 3C160200 */  dsll32     $2, $2, 24
    /* 1CA684 002CA684 3F160200 */  dsra32     $2, $2, 24
    /* 1CA688 002CA688 27004014 */  bnez       $2, .L002CA728
    /* 1CA68C 002CA68C 00000000 */   nop
    /* 1CA690 002CA690 500C248E */  lw         $4, 0xC50($17)
    /* 1CA694 002CA694 68810B0C */  jal        func_002e05a0
    /* 1CA698 002CA698 00000000 */   nop
    /* 1CA69C 002CA69C 3C160200 */  dsll32     $2, $2, 24
    /* 1CA6A0 002CA6A0 3F160200 */  dsra32     $2, $2, 24
    /* 1CA6A4 002CA6A4 20004014 */  bnez       $2, .L002CA728
    /* 1CA6A8 002CA6A8 00000000 */   nop
    /* 1CA6AC 002CA6AC 7C0E248E */  lw         $4, 0xE7C($17)
    /* 1CA6B0 002CA6B0 68810B0C */  jal        func_002e05a0
    /* 1CA6B4 002CA6B4 00000000 */   nop
    /* 1CA6B8 002CA6B8 3C160200 */  dsll32     $2, $2, 24
    /* 1CA6BC 002CA6BC 3F160200 */  dsra32     $2, $2, 24
    /* 1CA6C0 002CA6C0 19004014 */  bnez       $2, .L002CA728
    /* 1CA6C4 002CA6C4 00000000 */   nop
    /* 1CA6C8 002CA6C8 380C248E */  lw         $4, 0xC38($17)
    /* 1CA6CC 002CA6CC 68810B0C */  jal        func_002e05a0
    /* 1CA6D0 002CA6D0 00000000 */   nop
    /* 1CA6D4 002CA6D4 3C160200 */  dsll32     $2, $2, 24
    /* 1CA6D8 002CA6D8 3F160200 */  dsra32     $2, $2, 24
    /* 1CA6DC 002CA6DC 12004014 */  bnez       $2, .L002CA728
    /* 1CA6E0 002CA6E0 00000000 */   nop
    /* 1CA6E4 002CA6E4 3C0C248E */  lw         $4, 0xC3C($17)
    /* 1CA6E8 002CA6E8 68810B0C */  jal        func_002e05a0
    /* 1CA6EC 002CA6EC 00000000 */   nop
    /* 1CA6F0 002CA6F0 3C160200 */  dsll32     $2, $2, 24
    /* 1CA6F4 002CA6F4 3F160200 */  dsra32     $2, $2, 24
    /* 1CA6F8 002CA6F8 0B004014 */  bnez       $2, .L002CA728
    /* 1CA6FC 002CA6FC 00000000 */   nop
    /* 1CA700 002CA700 400C248E */  lw         $4, 0xC40($17)
    /* 1CA704 002CA704 68810B0C */  jal        func_002e05a0
    /* 1CA708 002CA708 00000000 */   nop
    /* 1CA70C 002CA70C 3C160200 */  dsll32     $2, $2, 24
    /* 1CA710 002CA710 3F160200 */  dsra32     $2, $2, 24
    /* 1CA714 002CA714 04004014 */  bnez       $2, .L002CA728
    /* 1CA718 002CA718 00000000 */   nop
    /* 1CA71C 002CA71C FFFF0224 */  addiu      $2, $0, -0x1
    /* 1CA720 002CA720 02000010 */  b          .L002CA72C
    /* 1CA724 002CA724 00000000 */   nop
  .L002CA728:
    /* 1CA728 002CA728 2D100000 */  daddu      $2, $0, $0
  .L002CA72C:
    /* 1CA72C 002CA72C B000BFDF */  ld         $31, 0xB0($29)
    /* 1CA730 002CA730 A000BE7B */  lq         $30, 0xA0($29)
    /* 1CA734 002CA734 9000B77B */  lq         $23, 0x90($29)
    /* 1CA738 002CA738 8000B67B */  lq         $22, 0x80($29)
    /* 1CA73C 002CA73C 7000B57B */  lq         $21, 0x70($29)
    /* 1CA740 002CA740 6000B47B */  lq         $20, 0x60($29)
    /* 1CA744 002CA744 5000B37B */  lq         $19, 0x50($29)
    /* 1CA748 002CA748 4000B27B */  lq         $18, 0x40($29)
    /* 1CA74C 002CA74C 3000B17B */  lq         $17, 0x30($29)
    /* 1CA750 002CA750 2000B07B */  lq         $16, 0x20($29)
    /* 1CA754 002CA754 1400B5C7 */  lwc1       $f21, 0x14($29)
    /* 1CA758 002CA758 1000B4C7 */  lwc1       $f20, 0x10($29)
    /* 1CA75C 002CA75C 9007BD27 */  addiu      $29, $29, 0x790
    /* 1CA760 002CA760 0800E003 */  jr         $31
    /* 1CA764 002CA764 00000000 */   nop
    /* 1CA768 002CA768 00000000 */  nop
    /* 1CA76C 002CA76C 00000000 */  nop
.size func_002be530, 0xc240
