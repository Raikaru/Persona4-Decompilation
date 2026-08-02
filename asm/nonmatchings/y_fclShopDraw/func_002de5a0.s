.section .text
.set noat
.set noreorder
glabel func_002de5a0
    /* 1DE5A0 002DE5A0 E0FEBD27 */  addiu      $29, $29, -0x120
    /* 1DE5A4 002DE5A4 3000BFFF */  sd         $31, 0x30($29)
    /* 1DE5A8 002DE5A8 2000B17F */  sq         $17, 0x20($29)
    /* 1DE5AC 002DE5AC 1000B07F */  sq         $16, 0x10($29)
    /* 1DE5B0 002DE5B0 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 1DE5B4 002DE5B4 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1DE5B8 002DE5B8 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1DE5BC 002DE5BC 3800908C */  lw         $16, 0x38($4)
    /* 1DE5C0 002DE5C0 BD43023C */  lui        $2, (0x43BD0000 >> 16)
    /* 1DE5C4 002DE5C4 00608244 */  mtc1       $2, $f12
    /* 1DE5C8 002DE5C8 7543023C */  lui        $2, (0x43750000 >> 16)
    /* 1DE5CC 002DE5CC 00688244 */  mtc1       $2, $f13
    /* 1DE5D0 002DE5D0 1801A427 */  addiu      $4, $29, 0x118
    /* 1DE5D4 002DE5D4 5CCA0A0C */  jal        func_002b2970
    /* 1DE5D8 002DE5D8 00000000 */   nop
    /* 1DE5DC 002DE5DC 2D200000 */  daddu      $4, $0, $0
    /* 1DE5E0 002DE5E0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DE5E4 002DE5E4 96000624 */  addiu      $6, $0, 0x96
    /* 1DE5E8 002DE5E8 2D380000 */  daddu      $7, $0, $0
    /* 1DE5EC 002DE5EC 8CCA0A0C */  jal        func_002b2a30
    /* 1DE5F0 002DE5F0 00000000 */   nop
    /* 1DE5F4 002DE5F4 08000382 */  lb         $3, 0x8($16)
    /* 1DE5F8 002DE5F8 21187000 */  addu       $3, $3, $16
    /* 1DE5FC 002DE5FC 7C0F6480 */  lb         $4, 0xF7C($3)
    /* 1DE600 002DE600 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DE604 002DE604 00608344 */  mtc1       $3, $f12
    /* 1DE608 002DE608 1801A5DF */  ld         $5, 0x118($29)
    /* 1DE60C 002DE60C 2D304000 */  daddu      $6, $2, $0
    /* 1DE610 002DE610 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE614 002DE614 2D400000 */  daddu      $8, $0, $0
    /* 1DE618 002DE618 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1DE61C 002DE61C 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1DE620 002DE620 C8820B0C */  jal        func_002e0b20
    /* 1DE624 002DE624 00000000 */   nop
    /* 1DE628 002DE628 07000282 */  lb         $2, 0x7($16)
    /* 1DE62C 002DE62C 66004014 */  bnez       $2, .L002DE7C8
    /* 1DE630 002DE630 00000000 */   nop
    /* 1DE634 002DE634 8C42023C */  lui        $2, (0x428C0000 >> 16)
    /* 1DE638 002DE638 00B08244 */  mtc1       $2, $f22
    /* 1DE63C 002DE63C 77010224 */  addiu      $2, $0, 0x177
    /* 1DE640 002DE640 00008244 */  mtc1       $2, $f0
    /* 1DE644 002DE644 00000000 */  nop
    /* 1DE648 002DE648 60058046 */  cvt.s.w    $f21, $f0
    /* 1DE64C 002DE64C 7343023C */  lui        $2, (0x43730000 >> 16)
    /* 1DE650 002DE650 00688244 */  mtc1       $2, $f13
    /* 1DE654 002DE654 1001A427 */  addiu      $4, $29, 0x110
    /* 1DE658 002DE658 06AB0046 */  mov.s      $f12, $f21
    /* 1DE65C 002DE65C 5CCA0A0C */  jal        func_002b2970
    /* 1DE660 002DE660 00000000 */   nop
    /* 1DE664 002DE664 2D200000 */  daddu      $4, $0, $0
    /* 1DE668 002DE668 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DE66C 002DE66C 2D30A000 */  daddu      $6, $5, $0
    /* 1DE670 002DE670 2D38A000 */  daddu      $7, $5, $0
    /* 1DE674 002DE674 8CCA0A0C */  jal        func_002b2a30
    /* 1DE678 002DE678 00000000 */   nop
    /* 1DE67C 002DE67C 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DE680 002DE680 00608344 */  mtc1       $3, $f12
    /* 1DE684 002DE684 02000424 */  addiu      $4, $0, 0x2
    /* 1DE688 002DE688 1001A5DF */  ld         $5, 0x110($29)
    /* 1DE68C 002DE68C 2D304000 */  daddu      $6, $2, $0
    /* 1DE690 002DE690 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE694 002DE694 2D400000 */  daddu      $8, $0, $0
    /* 1DE698 002DE698 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DE69C 002DE69C 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DE6A0 002DE6A0 C8820B0C */  jal        func_002e0b20
    /* 1DE6A4 002DE6A4 00000000 */   nop
    /* 1DE6A8 002DE6A8 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DE6AC 002DE6AC 00608244 */  mtc1       $2, $f12
    /* 1DE6B0 002DE6B0 7643023C */  lui        $2, (0x43760000 >> 16)
    /* 1DE6B4 002DE6B4 00688244 */  mtc1       $2, $f13
    /* 1DE6B8 002DE6B8 0801A427 */  addiu      $4, $29, 0x108
    /* 1DE6BC 002DE6BC 5CCA0A0C */  jal        func_002b2970
    /* 1DE6C0 002DE6C0 00000000 */   nop
    /* 1DE6C4 002DE6C4 2D200000 */  daddu      $4, $0, $0
    /* 1DE6C8 002DE6C8 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DE6CC 002DE6CC 2D30A000 */  daddu      $6, $5, $0
    /* 1DE6D0 002DE6D0 2D38A000 */  daddu      $7, $5, $0
    /* 1DE6D4 002DE6D4 8CCA0A0C */  jal        func_002b2a30
    /* 1DE6D8 002DE6D8 00000000 */   nop
    /* 1DE6DC 002DE6DC 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DE6E0 002DE6E0 00608344 */  mtc1       $3, $f12
    /* 1DE6E4 002DE6E4 05000424 */  addiu      $4, $0, 0x5
    /* 1DE6E8 002DE6E8 0801A5DF */  ld         $5, 0x108($29)
    /* 1DE6EC 002DE6EC 2D304000 */  daddu      $6, $2, $0
    /* 1DE6F0 002DE6F0 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE6F4 002DE6F4 2D400000 */  daddu      $8, $0, $0
    /* 1DE6F8 002DE6F8 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DE6FC 002DE6FC 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DE700 002DE700 C8820B0C */  jal        func_002e0b20
    /* 1DE704 002DE704 00000000 */   nop
    /* 1DE708 002DE708 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DE70C 002DE70C 2D288000 */  daddu      $5, $4, $0
    /* 1DE710 002DE710 2D308000 */  daddu      $6, $4, $0
    /* 1DE714 002DE714 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE718 002DE718 8CCA0A0C */  jal        func_002b2a30
    /* 1DE71C 002DE71C 00000000 */   nop
    /* 1DE720 002DE720 2D884000 */  daddu      $17, $2, $0
    /* 1DE724 002DE724 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DE728 002DE728 00608244 */  mtc1       $2, $f12
    /* 1DE72C 002DE72C 0F010224 */  addiu      $2, $0, 0x10F
    /* 1DE730 002DE730 00008244 */  mtc1       $2, $f0
    /* 1DE734 002DE734 00000000 */  nop
    /* 1DE738 002DE738 60038046 */  cvt.s.w    $f13, $f0
    /* 1DE73C 002DE73C 0001A427 */  addiu      $4, $29, 0x100
    /* 1DE740 002DE740 5CCA0A0C */  jal        func_002b2970
    /* 1DE744 002DE744 00000000 */   nop
    /* 1DE748 002DE748 0001A1C7 */  lwc1       $f1, 0x100($29)
    /* 1DE74C 002DE74C 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* 1DE750 002DE750 7000A1E7 */  swc1       $f1, 0x70($29)
    /* 1DE754 002DE754 7400A0E7 */  swc1       $f0, 0x74($29)
    /* 1DE758 002DE758 08000282 */  lb         $2, 0x8($16)
    /* 1DE75C 002DE75C 21105000 */  addu       $2, $2, $16
    /* 1DE760 002DE760 730F4480 */  lb         $4, 0xF73($2)
    /* 1DE764 002DE764 2D280000 */  daddu      $5, $0, $0
    /* 1DE768 002DE768 341B040C */  jal        func_00106cd0
    /* 1DE76C 002DE76C 00000000 */   nop
    /* 1DE770 002DE770 3C240200 */  dsll32     $4, $2, 16
    /* 1DE774 002DE774 3F240400 */  dsra32     $4, $4, 16
    /* 1DE778 002DE778 FC19040C */  jal        func_001067f0
    /* 1DE77C 002DE77C 00000000 */   nop
    /* 1DE780 002DE780 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DE784 002DE784 00A08344 */  mtc1       $3, $f20
    /* 1DE788 002DE788 7000ACC7 */  lwc1       $f12, 0x70($29)
    /* 1DE78C 002DE78C 7400ADC7 */  lwc1       $f13, 0x74($29)
    /* 1DE790 002DE790 86A30046 */  mov.s      $f14, $f20
    /* 1DE794 002DE794 2D202002 */  daddu      $4, $17, $0
    /* 1DE798 002DE798 2D280000 */  daddu      $5, $0, $0
    /* 1DE79C 002DE79C 01000624 */  addiu      $6, $0, 0x1
    /* 1DE7A0 002DE7A0 2D384000 */  daddu      $7, $2, $0
    /* 1DE7A4 002DE7A4 2D400000 */  daddu      $8, $0, $0
    /* 1DE7A8 002DE7A8 2D480000 */  daddu      $9, $0, $0
    /* 1DE7AC 002DE7AC 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DE7B0 002DE7B0 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DE7B4 002DE7B4 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DE7B8 002DE7B8 A0D5090C */  jal        func_00275680
    /* 1DE7BC 002DE7BC 00000000 */   nop
    /* 1DE7C0 002DE7C0 64000010 */  b          .L002DE954
    /* 1DE7C4 002DE7C4 00000000 */   nop
  .L002DE7C8:
    /* 1DE7C8 002DE7C8 8C42023C */  lui        $2, (0x428C0000 >> 16)
    /* 1DE7CC 002DE7CC 00B08244 */  mtc1       $2, $f22
    /* 1DE7D0 002DE7D0 77010224 */  addiu      $2, $0, 0x177
    /* 1DE7D4 002DE7D4 00008244 */  mtc1       $2, $f0
    /* 1DE7D8 002DE7D8 00000000 */  nop
    /* 1DE7DC 002DE7DC 60058046 */  cvt.s.w    $f21, $f0
    /* 1DE7E0 002DE7E0 7343023C */  lui        $2, (0x43730000 >> 16)
    /* 1DE7E4 002DE7E4 00688244 */  mtc1       $2, $f13
    /* 1DE7E8 002DE7E8 F800A427 */  addiu      $4, $29, 0xF8
    /* 1DE7EC 002DE7EC 06AB0046 */  mov.s      $f12, $f21
    /* 1DE7F0 002DE7F0 5CCA0A0C */  jal        func_002b2970
    /* 1DE7F4 002DE7F4 00000000 */   nop
    /* 1DE7F8 002DE7F8 2D200000 */  daddu      $4, $0, $0
    /* 1DE7FC 002DE7FC FF000524 */  addiu      $5, $0, 0xFF
    /* 1DE800 002DE800 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DE804 002DE804 80000724 */  addiu      $7, $0, 0x80
    /* 1DE808 002DE808 8CCA0A0C */  jal        func_002b2a30
    /* 1DE80C 002DE80C 00000000 */   nop
    /* 1DE810 002DE810 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DE814 002DE814 00608344 */  mtc1       $3, $f12
    /* 1DE818 002DE818 02000424 */  addiu      $4, $0, 0x2
    /* 1DE81C 002DE81C F800A5DF */  ld         $5, 0xF8($29)
    /* 1DE820 002DE820 2D304000 */  daddu      $6, $2, $0
    /* 1DE824 002DE824 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE828 002DE828 2D400000 */  daddu      $8, $0, $0
    /* 1DE82C 002DE82C 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DE830 002DE830 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DE834 002DE834 C8820B0C */  jal        func_002e0b20
    /* 1DE838 002DE838 00000000 */   nop
    /* 1DE83C 002DE83C D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DE840 002DE840 00608244 */  mtc1       $2, $f12
    /* 1DE844 002DE844 7643023C */  lui        $2, (0x43760000 >> 16)
    /* 1DE848 002DE848 00688244 */  mtc1       $2, $f13
    /* 1DE84C 002DE84C F000A427 */  addiu      $4, $29, 0xF0
    /* 1DE850 002DE850 5CCA0A0C */  jal        func_002b2970
    /* 1DE854 002DE854 00000000 */   nop
    /* 1DE858 002DE858 2D200000 */  daddu      $4, $0, $0
    /* 1DE85C 002DE85C FF000524 */  addiu      $5, $0, 0xFF
    /* 1DE860 002DE860 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DE864 002DE864 80000724 */  addiu      $7, $0, 0x80
    /* 1DE868 002DE868 8CCA0A0C */  jal        func_002b2a30
    /* 1DE86C 002DE86C 00000000 */   nop
    /* 1DE870 002DE870 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DE874 002DE874 00608344 */  mtc1       $3, $f12
    /* 1DE878 002DE878 05000424 */  addiu      $4, $0, 0x5
    /* 1DE87C 002DE87C F000A5DF */  ld         $5, 0xF0($29)
    /* 1DE880 002DE880 2D304000 */  daddu      $6, $2, $0
    /* 1DE884 002DE884 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE888 002DE888 2D400000 */  daddu      $8, $0, $0
    /* 1DE88C 002DE88C 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DE890 002DE890 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DE894 002DE894 C8820B0C */  jal        func_002e0b20
    /* 1DE898 002DE898 00000000 */   nop
    /* 1DE89C 002DE89C FF000424 */  addiu      $4, $0, 0xFF
    /* 1DE8A0 002DE8A0 EF000524 */  addiu      $5, $0, 0xEF
    /* 1DE8A4 002DE8A4 81000624 */  addiu      $6, $0, 0x81
    /* 1DE8A8 002DE8A8 2D388000 */  daddu      $7, $4, $0
    /* 1DE8AC 002DE8AC 8CCA0A0C */  jal        func_002b2a30
    /* 1DE8B0 002DE8B0 00000000 */   nop
    /* 1DE8B4 002DE8B4 2D884000 */  daddu      $17, $2, $0
    /* 1DE8B8 002DE8B8 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DE8BC 002DE8BC 00608244 */  mtc1       $2, $f12
    /* 1DE8C0 002DE8C0 0F010224 */  addiu      $2, $0, 0x10F
    /* 1DE8C4 002DE8C4 00008244 */  mtc1       $2, $f0
    /* 1DE8C8 002DE8C8 00000000 */  nop
    /* 1DE8CC 002DE8CC 60038046 */  cvt.s.w    $f13, $f0
    /* 1DE8D0 002DE8D0 E800A427 */  addiu      $4, $29, 0xE8
    /* 1DE8D4 002DE8D4 5CCA0A0C */  jal        func_002b2970
    /* 1DE8D8 002DE8D8 00000000 */   nop
    /* 1DE8DC 002DE8DC E800A1C7 */  lwc1       $f1, 0xE8($29)
    /* 1DE8E0 002DE8E0 EC00A0C7 */  lwc1       $f0, 0xEC($29)
    /* 1DE8E4 002DE8E4 6800A1E7 */  swc1       $f1, 0x68($29)
    /* 1DE8E8 002DE8E8 6C00A0E7 */  swc1       $f0, 0x6C($29)
    /* 1DE8EC 002DE8EC 08000282 */  lb         $2, 0x8($16)
    /* 1DE8F0 002DE8F0 21105000 */  addu       $2, $2, $16
    /* 1DE8F4 002DE8F4 730F4480 */  lb         $4, 0xF73($2)
    /* 1DE8F8 002DE8F8 2D280000 */  daddu      $5, $0, $0
    /* 1DE8FC 002DE8FC 341B040C */  jal        func_00106cd0
    /* 1DE900 002DE900 00000000 */   nop
    /* 1DE904 002DE904 3C240200 */  dsll32     $4, $2, 16
    /* 1DE908 002DE908 3F240400 */  dsra32     $4, $4, 16
    /* 1DE90C 002DE90C FC19040C */  jal        func_001067f0
    /* 1DE910 002DE910 00000000 */   nop
    /* 1DE914 002DE914 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DE918 002DE918 00A08344 */  mtc1       $3, $f20
    /* 1DE91C 002DE91C 6800ACC7 */  lwc1       $f12, 0x68($29)
    /* 1DE920 002DE920 6C00ADC7 */  lwc1       $f13, 0x6C($29)
    /* 1DE924 002DE924 86A30046 */  mov.s      $f14, $f20
    /* 1DE928 002DE928 2D202002 */  daddu      $4, $17, $0
    /* 1DE92C 002DE92C 2D280000 */  daddu      $5, $0, $0
    /* 1DE930 002DE930 01000624 */  addiu      $6, $0, 0x1
    /* 1DE934 002DE934 2D384000 */  daddu      $7, $2, $0
    /* 1DE938 002DE938 2D400000 */  daddu      $8, $0, $0
    /* 1DE93C 002DE93C 2D480000 */  daddu      $9, $0, $0
    /* 1DE940 002DE940 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DE944 002DE944 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DE948 002DE948 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DE94C 002DE94C A0D5090C */  jal        func_00275680
    /* 1DE950 002DE950 00000000 */   nop
  .L002DE954:
    /* 1DE954 002DE954 BD43023C */  lui        $2, (0x43BD0000 >> 16)
    /* 1DE958 002DE958 00608244 */  mtc1       $2, $f12
    /* 1DE95C 002DE95C 2F010224 */  addiu      $2, $0, 0x12F
    /* 1DE960 002DE960 00008244 */  mtc1       $2, $f0
    /* 1DE964 002DE964 00000000 */  nop
    /* 1DE968 002DE968 60038046 */  cvt.s.w    $f13, $f0
    /* 1DE96C 002DE96C E000A427 */  addiu      $4, $29, 0xE0
    /* 1DE970 002DE970 5CCA0A0C */  jal        func_002b2970
    /* 1DE974 002DE974 00000000 */   nop
    /* 1DE978 002DE978 2D200000 */  daddu      $4, $0, $0
    /* 1DE97C 002DE97C FF000524 */  addiu      $5, $0, 0xFF
    /* 1DE980 002DE980 96000624 */  addiu      $6, $0, 0x96
    /* 1DE984 002DE984 2D380000 */  daddu      $7, $0, $0
    /* 1DE988 002DE988 8CCA0A0C */  jal        func_002b2a30
    /* 1DE98C 002DE98C 00000000 */   nop
    /* 1DE990 002DE990 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DE994 002DE994 00608344 */  mtc1       $3, $f12
    /* 1DE998 002DE998 1B000424 */  addiu      $4, $0, 0x1B
    /* 1DE99C 002DE99C E000A5DF */  ld         $5, 0xE0($29)
    /* 1DE9A0 002DE9A0 2D304000 */  daddu      $6, $2, $0
    /* 1DE9A4 002DE9A4 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE9A8 002DE9A8 2D400000 */  daddu      $8, $0, $0
    /* 1DE9AC 002DE9AC 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1DE9B0 002DE9B0 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1DE9B4 002DE9B4 C8820B0C */  jal        func_002e0b20
    /* 1DE9B8 002DE9B8 00000000 */   nop
    /* 1DE9BC 002DE9BC 07000382 */  lb         $3, 0x7($16)
    /* 1DE9C0 002DE9C0 01000224 */  addiu      $2, $0, 0x1
    /* 1DE9C4 002DE9C4 5F006214 */  bne        $3, $2, .L002DEB44
    /* 1DE9C8 002DE9C8 00000000 */   nop
    /* 1DE9CC 002DE9CC 2D010224 */  addiu      $2, $0, 0x12D
    /* 1DE9D0 002DE9D0 00008244 */  mtc1       $2, $f0
    /* 1DE9D4 002DE9D4 00000000 */  nop
    /* 1DE9D8 002DE9D8 60038046 */  cvt.s.w    $f13, $f0
    /* 1DE9DC 002DE9DC D800A427 */  addiu      $4, $29, 0xD8
    /* 1DE9E0 002DE9E0 06AB0046 */  mov.s      $f12, $f21
    /* 1DE9E4 002DE9E4 5CCA0A0C */  jal        func_002b2970
    /* 1DE9E8 002DE9E8 00000000 */   nop
    /* 1DE9EC 002DE9EC 2D200000 */  daddu      $4, $0, $0
    /* 1DE9F0 002DE9F0 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DE9F4 002DE9F4 2D30A000 */  daddu      $6, $5, $0
    /* 1DE9F8 002DE9F8 2D38A000 */  daddu      $7, $5, $0
    /* 1DE9FC 002DE9FC 8CCA0A0C */  jal        func_002b2a30
    /* 1DEA00 002DEA00 00000000 */   nop
    /* 1DEA04 002DEA04 03000424 */  addiu      $4, $0, 0x3
    /* 1DEA08 002DEA08 D800A5DF */  ld         $5, 0xD8($29)
    /* 1DEA0C 002DEA0C 06B30046 */  mov.s      $f12, $f22
    /* 1DEA10 002DEA10 2D304000 */  daddu      $6, $2, $0
    /* 1DEA14 002DEA14 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEA18 002DEA18 2D400000 */  daddu      $8, $0, $0
    /* 1DEA1C 002DEA1C 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DEA20 002DEA20 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DEA24 002DEA24 C8820B0C */  jal        func_002e0b20
    /* 1DEA28 002DEA28 00000000 */   nop
    /* 1DEA2C 002DEA2C D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DEA30 002DEA30 00608244 */  mtc1       $2, $f12
    /* 1DEA34 002DEA34 31010224 */  addiu      $2, $0, 0x131
    /* 1DEA38 002DEA38 00008244 */  mtc1       $2, $f0
    /* 1DEA3C 002DEA3C 00000000 */  nop
    /* 1DEA40 002DEA40 60038046 */  cvt.s.w    $f13, $f0
    /* 1DEA44 002DEA44 D000A427 */  addiu      $4, $29, 0xD0
    /* 1DEA48 002DEA48 5CCA0A0C */  jal        func_002b2970
    /* 1DEA4C 002DEA4C 00000000 */   nop
    /* 1DEA50 002DEA50 2D200000 */  daddu      $4, $0, $0
    /* 1DEA54 002DEA54 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DEA58 002DEA58 2D30A000 */  daddu      $6, $5, $0
    /* 1DEA5C 002DEA5C 2D38A000 */  daddu      $7, $5, $0
    /* 1DEA60 002DEA60 8CCA0A0C */  jal        func_002b2a30
    /* 1DEA64 002DEA64 00000000 */   nop
    /* 1DEA68 002DEA68 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DEA6C 002DEA6C 00608344 */  mtc1       $3, $f12
    /* 1DEA70 002DEA70 06000424 */  addiu      $4, $0, 0x6
    /* 1DEA74 002DEA74 D000A5DF */  ld         $5, 0xD0($29)
    /* 1DEA78 002DEA78 2D304000 */  daddu      $6, $2, $0
    /* 1DEA7C 002DEA7C FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEA80 002DEA80 2D400000 */  daddu      $8, $0, $0
    /* 1DEA84 002DEA84 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DEA88 002DEA88 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DEA8C 002DEA8C C8820B0C */  jal        func_002e0b20
    /* 1DEA90 002DEA90 00000000 */   nop
    /* 1DEA94 002DEA94 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DEA98 002DEA98 2D288000 */  daddu      $5, $4, $0
    /* 1DEA9C 002DEA9C 2D308000 */  daddu      $6, $4, $0
    /* 1DEAA0 002DEAA0 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEAA4 002DEAA4 8CCA0A0C */  jal        func_002b2a30
    /* 1DEAA8 002DEAA8 00000000 */   nop
    /* 1DEAAC 002DEAAC 2D884000 */  daddu      $17, $2, $0
    /* 1DEAB0 002DEAB0 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DEAB4 002DEAB4 00608244 */  mtc1       $2, $f12
    /* 1DEAB8 002DEAB8 A543023C */  lui        $2, (0x43A50000 >> 16)
    /* 1DEABC 002DEABC 00688244 */  mtc1       $2, $f13
    /* 1DEAC0 002DEAC0 C800A427 */  addiu      $4, $29, 0xC8
    /* 1DEAC4 002DEAC4 5CCA0A0C */  jal        func_002b2970
    /* 1DEAC8 002DEAC8 00000000 */   nop
    /* 1DEACC 002DEACC C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* 1DEAD0 002DEAD0 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* 1DEAD4 002DEAD4 6000A1E7 */  swc1       $f1, 0x60($29)
    /* 1DEAD8 002DEAD8 6400A0E7 */  swc1       $f0, 0x64($29)
    /* 1DEADC 002DEADC 08000282 */  lb         $2, 0x8($16)
    /* 1DEAE0 002DEAE0 21105000 */  addu       $2, $2, $16
    /* 1DEAE4 002DEAE4 730F4480 */  lb         $4, 0xF73($2)
    /* 1DEAE8 002DEAE8 01000524 */  addiu      $5, $0, 0x1
    /* 1DEAEC 002DEAEC 341B040C */  jal        func_00106cd0
    /* 1DEAF0 002DEAF0 00000000 */   nop
    /* 1DEAF4 002DEAF4 3C240200 */  dsll32     $4, $2, 16
    /* 1DEAF8 002DEAF8 3F240400 */  dsra32     $4, $4, 16
    /* 1DEAFC 002DEAFC FC19040C */  jal        func_001067f0
    /* 1DEB00 002DEB00 00000000 */   nop
    /* 1DEB04 002DEB04 6000ACC7 */  lwc1       $f12, 0x60($29)
    /* 1DEB08 002DEB08 6400ADC7 */  lwc1       $f13, 0x64($29)
    /* 1DEB0C 002DEB0C 86A30046 */  mov.s      $f14, $f20
    /* 1DEB10 002DEB10 2D202002 */  daddu      $4, $17, $0
    /* 1DEB14 002DEB14 2D280000 */  daddu      $5, $0, $0
    /* 1DEB18 002DEB18 01000624 */  addiu      $6, $0, 0x1
    /* 1DEB1C 002DEB1C 2D384000 */  daddu      $7, $2, $0
    /* 1DEB20 002DEB20 2D400000 */  daddu      $8, $0, $0
    /* 1DEB24 002DEB24 2D480000 */  daddu      $9, $0, $0
    /* 1DEB28 002DEB28 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DEB2C 002DEB2C 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DEB30 002DEB30 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DEB34 002DEB34 A0D5090C */  jal        func_00275680
    /* 1DEB38 002DEB38 00000000 */   nop
    /* 1DEB3C 002DEB3C 5D000010 */  b          .L002DECB4
    /* 1DEB40 002DEB40 00000000 */   nop
  .L002DEB44:
    /* 1DEB44 002DEB44 2D010224 */  addiu      $2, $0, 0x12D
    /* 1DEB48 002DEB48 00008244 */  mtc1       $2, $f0
    /* 1DEB4C 002DEB4C 00000000 */  nop
    /* 1DEB50 002DEB50 60038046 */  cvt.s.w    $f13, $f0
    /* 1DEB54 002DEB54 C000A427 */  addiu      $4, $29, 0xC0
    /* 1DEB58 002DEB58 06AB0046 */  mov.s      $f12, $f21
    /* 1DEB5C 002DEB5C 5CCA0A0C */  jal        func_002b2970
    /* 1DEB60 002DEB60 00000000 */   nop
    /* 1DEB64 002DEB64 2D200000 */  daddu      $4, $0, $0
    /* 1DEB68 002DEB68 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DEB6C 002DEB6C EF000624 */  addiu      $6, $0, 0xEF
    /* 1DEB70 002DEB70 80000724 */  addiu      $7, $0, 0x80
    /* 1DEB74 002DEB74 8CCA0A0C */  jal        func_002b2a30
    /* 1DEB78 002DEB78 00000000 */   nop
    /* 1DEB7C 002DEB7C 03000424 */  addiu      $4, $0, 0x3
    /* 1DEB80 002DEB80 C000A5DF */  ld         $5, 0xC0($29)
    /* 1DEB84 002DEB84 06B30046 */  mov.s      $f12, $f22
    /* 1DEB88 002DEB88 2D304000 */  daddu      $6, $2, $0
    /* 1DEB8C 002DEB8C FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEB90 002DEB90 2D400000 */  daddu      $8, $0, $0
    /* 1DEB94 002DEB94 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DEB98 002DEB98 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DEB9C 002DEB9C C8820B0C */  jal        func_002e0b20
    /* 1DEBA0 002DEBA0 00000000 */   nop
    /* 1DEBA4 002DEBA4 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DEBA8 002DEBA8 00608244 */  mtc1       $2, $f12
    /* 1DEBAC 002DEBAC 31010224 */  addiu      $2, $0, 0x131
    /* 1DEBB0 002DEBB0 00008244 */  mtc1       $2, $f0
    /* 1DEBB4 002DEBB4 00000000 */  nop
    /* 1DEBB8 002DEBB8 60038046 */  cvt.s.w    $f13, $f0
    /* 1DEBBC 002DEBBC B800A427 */  addiu      $4, $29, 0xB8
    /* 1DEBC0 002DEBC0 5CCA0A0C */  jal        func_002b2970
    /* 1DEBC4 002DEBC4 00000000 */   nop
    /* 1DEBC8 002DEBC8 2D200000 */  daddu      $4, $0, $0
    /* 1DEBCC 002DEBCC FF000524 */  addiu      $5, $0, 0xFF
    /* 1DEBD0 002DEBD0 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DEBD4 002DEBD4 80000724 */  addiu      $7, $0, 0x80
    /* 1DEBD8 002DEBD8 8CCA0A0C */  jal        func_002b2a30
    /* 1DEBDC 002DEBDC 00000000 */   nop
    /* 1DEBE0 002DEBE0 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DEBE4 002DEBE4 00608344 */  mtc1       $3, $f12
    /* 1DEBE8 002DEBE8 06000424 */  addiu      $4, $0, 0x6
    /* 1DEBEC 002DEBEC B800A5DF */  ld         $5, 0xB8($29)
    /* 1DEBF0 002DEBF0 2D304000 */  daddu      $6, $2, $0
    /* 1DEBF4 002DEBF4 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEBF8 002DEBF8 2D400000 */  daddu      $8, $0, $0
    /* 1DEBFC 002DEBFC 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DEC00 002DEC00 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DEC04 002DEC04 C8820B0C */  jal        func_002e0b20
    /* 1DEC08 002DEC08 00000000 */   nop
    /* 1DEC0C 002DEC0C FF000424 */  addiu      $4, $0, 0xFF
    /* 1DEC10 002DEC10 EF000524 */  addiu      $5, $0, 0xEF
    /* 1DEC14 002DEC14 81000624 */  addiu      $6, $0, 0x81
    /* 1DEC18 002DEC18 2D388000 */  daddu      $7, $4, $0
    /* 1DEC1C 002DEC1C 8CCA0A0C */  jal        func_002b2a30
    /* 1DEC20 002DEC20 00000000 */   nop
    /* 1DEC24 002DEC24 2D884000 */  daddu      $17, $2, $0
    /* 1DEC28 002DEC28 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DEC2C 002DEC2C 00608244 */  mtc1       $2, $f12
    /* 1DEC30 002DEC30 A543023C */  lui        $2, (0x43A50000 >> 16)
    /* 1DEC34 002DEC34 00688244 */  mtc1       $2, $f13
    /* 1DEC38 002DEC38 B000A427 */  addiu      $4, $29, 0xB0
    /* 1DEC3C 002DEC3C 5CCA0A0C */  jal        func_002b2970
    /* 1DEC40 002DEC40 00000000 */   nop
    /* 1DEC44 002DEC44 B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* 1DEC48 002DEC48 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* 1DEC4C 002DEC4C 5800A1E7 */  swc1       $f1, 0x58($29)
    /* 1DEC50 002DEC50 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* 1DEC54 002DEC54 08000282 */  lb         $2, 0x8($16)
    /* 1DEC58 002DEC58 21105000 */  addu       $2, $2, $16
    /* 1DEC5C 002DEC5C 730F4480 */  lb         $4, 0xF73($2)
    /* 1DEC60 002DEC60 01000524 */  addiu      $5, $0, 0x1
    /* 1DEC64 002DEC64 341B040C */  jal        func_00106cd0
    /* 1DEC68 002DEC68 00000000 */   nop
    /* 1DEC6C 002DEC6C 3C240200 */  dsll32     $4, $2, 16
    /* 1DEC70 002DEC70 3F240400 */  dsra32     $4, $4, 16
    /* 1DEC74 002DEC74 FC19040C */  jal        func_001067f0
    /* 1DEC78 002DEC78 00000000 */   nop
    /* 1DEC7C 002DEC7C 5800ACC7 */  lwc1       $f12, 0x58($29)
    /* 1DEC80 002DEC80 5C00ADC7 */  lwc1       $f13, 0x5C($29)
    /* 1DEC84 002DEC84 86A30046 */  mov.s      $f14, $f20
    /* 1DEC88 002DEC88 2D202002 */  daddu      $4, $17, $0
    /* 1DEC8C 002DEC8C 2D280000 */  daddu      $5, $0, $0
    /* 1DEC90 002DEC90 01000624 */  addiu      $6, $0, 0x1
    /* 1DEC94 002DEC94 2D384000 */  daddu      $7, $2, $0
    /* 1DEC98 002DEC98 2D400000 */  daddu      $8, $0, $0
    /* 1DEC9C 002DEC9C 2D480000 */  daddu      $9, $0, $0
    /* 1DECA0 002DECA0 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DECA4 002DECA4 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DECA8 002DECA8 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DECAC 002DECAC A0D5090C */  jal        func_00275680
    /* 1DECB0 002DECB0 00000000 */   nop
  .L002DECB4:
    /* 1DECB4 002DECB4 BD43023C */  lui        $2, (0x43BD0000 >> 16)
    /* 1DECB8 002DECB8 00608244 */  mtc1       $2, $f12
    /* 1DECBC 002DECBC B843023C */  lui        $2, (0x43B80000 >> 16)
    /* 1DECC0 002DECC0 00688244 */  mtc1       $2, $f13
    /* 1DECC4 002DECC4 A800A427 */  addiu      $4, $29, 0xA8
    /* 1DECC8 002DECC8 5CCA0A0C */  jal        func_002b2970
    /* 1DECCC 002DECCC 00000000 */   nop
    /* 1DECD0 002DECD0 2D200000 */  daddu      $4, $0, $0
    /* 1DECD4 002DECD4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DECD8 002DECD8 96000624 */  addiu      $6, $0, 0x96
    /* 1DECDC 002DECDC 2D380000 */  daddu      $7, $0, $0
    /* 1DECE0 002DECE0 8CCA0A0C */  jal        func_002b2a30
    /* 1DECE4 002DECE4 00000000 */   nop
    /* 1DECE8 002DECE8 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DECEC 002DECEC 00608344 */  mtc1       $3, $f12
    /* 1DECF0 002DECF0 1C000424 */  addiu      $4, $0, 0x1C
    /* 1DECF4 002DECF4 A800A5DF */  ld         $5, 0xA8($29)
    /* 1DECF8 002DECF8 2D304000 */  daddu      $6, $2, $0
    /* 1DECFC 002DECFC FF000724 */  addiu      $7, $0, 0xFF
    /* 1DED00 002DED00 2D400000 */  daddu      $8, $0, $0
    /* 1DED04 002DED04 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1DED08 002DED08 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1DED0C 002DED0C C8820B0C */  jal        func_002e0b20
    /* 1DED10 002DED10 00000000 */   nop
    /* 1DED14 002DED14 07000382 */  lb         $3, 0x7($16)
    /* 1DED18 002DED18 02000224 */  addiu      $2, $0, 0x2
    /* 1DED1C 002DED1C 5D006214 */  bne        $3, $2, .L002DEE94
    /* 1DED20 002DED20 00000000 */   nop
    /* 1DED24 002DED24 B743023C */  lui        $2, (0x43B70000 >> 16)
    /* 1DED28 002DED28 00688244 */  mtc1       $2, $f13
    /* 1DED2C 002DED2C A000A427 */  addiu      $4, $29, 0xA0
    /* 1DED30 002DED30 06AB0046 */  mov.s      $f12, $f21
    /* 1DED34 002DED34 5CCA0A0C */  jal        func_002b2970
    /* 1DED38 002DED38 00000000 */   nop
    /* 1DED3C 002DED3C 2D200000 */  daddu      $4, $0, $0
    /* 1DED40 002DED40 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DED44 002DED44 2D30A000 */  daddu      $6, $5, $0
    /* 1DED48 002DED48 2D38A000 */  daddu      $7, $5, $0
    /* 1DED4C 002DED4C 8CCA0A0C */  jal        func_002b2a30
    /* 1DED50 002DED50 00000000 */   nop
    /* 1DED54 002DED54 03000424 */  addiu      $4, $0, 0x3
    /* 1DED58 002DED58 A000A5DF */  ld         $5, 0xA0($29)
    /* 1DED5C 002DED5C 06B30046 */  mov.s      $f12, $f22
    /* 1DED60 002DED60 2D304000 */  daddu      $6, $2, $0
    /* 1DED64 002DED64 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DED68 002DED68 2D400000 */  daddu      $8, $0, $0
    /* 1DED6C 002DED6C 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DED70 002DED70 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DED74 002DED74 C8820B0C */  jal        func_002e0b20
    /* 1DED78 002DED78 00000000 */   nop
    /* 1DED7C 002DED7C D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DED80 002DED80 00608244 */  mtc1       $2, $f12
    /* 1DED84 002DED84 71010224 */  addiu      $2, $0, 0x171
    /* 1DED88 002DED88 00008244 */  mtc1       $2, $f0
    /* 1DED8C 002DED8C 00000000 */  nop
    /* 1DED90 002DED90 60038046 */  cvt.s.w    $f13, $f0
    /* 1DED94 002DED94 9800A427 */  addiu      $4, $29, 0x98
    /* 1DED98 002DED98 5CCA0A0C */  jal        func_002b2970
    /* 1DED9C 002DED9C 00000000 */   nop
    /* 1DEDA0 002DEDA0 2D200000 */  daddu      $4, $0, $0
    /* 1DEDA4 002DEDA4 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DEDA8 002DEDA8 2D30A000 */  daddu      $6, $5, $0
    /* 1DEDAC 002DEDAC 2D38A000 */  daddu      $7, $5, $0
    /* 1DEDB0 002DEDB0 8CCA0A0C */  jal        func_002b2a30
    /* 1DEDB4 002DEDB4 00000000 */   nop
    /* 1DEDB8 002DEDB8 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DEDBC 002DEDBC 00608344 */  mtc1       $3, $f12
    /* 1DEDC0 002DEDC0 07000424 */  addiu      $4, $0, 0x7
    /* 1DEDC4 002DEDC4 9800A5DF */  ld         $5, 0x98($29)
    /* 1DEDC8 002DEDC8 2D304000 */  daddu      $6, $2, $0
    /* 1DEDCC 002DEDCC FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEDD0 002DEDD0 2D400000 */  daddu      $8, $0, $0
    /* 1DEDD4 002DEDD4 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DEDD8 002DEDD8 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DEDDC 002DEDDC C8820B0C */  jal        func_002e0b20
    /* 1DEDE0 002DEDE0 00000000 */   nop
    /* 1DEDE4 002DEDE4 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DEDE8 002DEDE8 2D288000 */  daddu      $5, $4, $0
    /* 1DEDEC 002DEDEC 2D308000 */  daddu      $6, $4, $0
    /* 1DEDF0 002DEDF0 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEDF4 002DEDF4 8CCA0A0C */  jal        func_002b2a30
    /* 1DEDF8 002DEDF8 00000000 */   nop
    /* 1DEDFC 002DEDFC 2D884000 */  daddu      $17, $2, $0
    /* 1DEE00 002DEE00 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DEE04 002DEE04 00608244 */  mtc1       $2, $f12
    /* 1DEE08 002DEE08 C543023C */  lui        $2, (0x43C50000 >> 16)
    /* 1DEE0C 002DEE0C 00688244 */  mtc1       $2, $f13
    /* 1DEE10 002DEE10 9000A427 */  addiu      $4, $29, 0x90
    /* 1DEE14 002DEE14 5CCA0A0C */  jal        func_002b2970
    /* 1DEE18 002DEE18 00000000 */   nop
    /* 1DEE1C 002DEE1C 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* 1DEE20 002DEE20 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* 1DEE24 002DEE24 5000A1E7 */  swc1       $f1, 0x50($29)
    /* 1DEE28 002DEE28 5400A0E7 */  swc1       $f0, 0x54($29)
    /* 1DEE2C 002DEE2C 08000282 */  lb         $2, 0x8($16)
    /* 1DEE30 002DEE30 21105000 */  addu       $2, $2, $16
    /* 1DEE34 002DEE34 730F4480 */  lb         $4, 0xF73($2)
    /* 1DEE38 002DEE38 02000524 */  addiu      $5, $0, 0x2
    /* 1DEE3C 002DEE3C 341B040C */  jal        func_00106cd0
    /* 1DEE40 002DEE40 00000000 */   nop
    /* 1DEE44 002DEE44 3C240200 */  dsll32     $4, $2, 16
    /* 1DEE48 002DEE48 3F240400 */  dsra32     $4, $4, 16
    /* 1DEE4C 002DEE4C FC19040C */  jal        func_001067f0
    /* 1DEE50 002DEE50 00000000 */   nop
    /* 1DEE54 002DEE54 5000ACC7 */  lwc1       $f12, 0x50($29)
    /* 1DEE58 002DEE58 5400ADC7 */  lwc1       $f13, 0x54($29)
    /* 1DEE5C 002DEE5C 86A30046 */  mov.s      $f14, $f20
    /* 1DEE60 002DEE60 2D202002 */  daddu      $4, $17, $0
    /* 1DEE64 002DEE64 2D280000 */  daddu      $5, $0, $0
    /* 1DEE68 002DEE68 01000624 */  addiu      $6, $0, 0x1
    /* 1DEE6C 002DEE6C 2D384000 */  daddu      $7, $2, $0
    /* 1DEE70 002DEE70 2D400000 */  daddu      $8, $0, $0
    /* 1DEE74 002DEE74 2D480000 */  daddu      $9, $0, $0
    /* 1DEE78 002DEE78 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DEE7C 002DEE7C 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DEE80 002DEE80 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DEE84 002DEE84 A0D5090C */  jal        func_00275680
    /* 1DEE88 002DEE88 00000000 */   nop
    /* 1DEE8C 002DEE8C 5B000010 */  b          .L002DEFFC
    /* 1DEE90 002DEE90 00000000 */   nop
  .L002DEE94:
    /* 1DEE94 002DEE94 B743023C */  lui        $2, (0x43B70000 >> 16)
    /* 1DEE98 002DEE98 00688244 */  mtc1       $2, $f13
    /* 1DEE9C 002DEE9C 8800A427 */  addiu      $4, $29, 0x88
    /* 1DEEA0 002DEEA0 06AB0046 */  mov.s      $f12, $f21
    /* 1DEEA4 002DEEA4 5CCA0A0C */  jal        func_002b2970
    /* 1DEEA8 002DEEA8 00000000 */   nop
    /* 1DEEAC 002DEEAC 2D200000 */  daddu      $4, $0, $0
    /* 1DEEB0 002DEEB0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DEEB4 002DEEB4 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DEEB8 002DEEB8 80000724 */  addiu      $7, $0, 0x80
    /* 1DEEBC 002DEEBC 8CCA0A0C */  jal        func_002b2a30
    /* 1DEEC0 002DEEC0 00000000 */   nop
    /* 1DEEC4 002DEEC4 03000424 */  addiu      $4, $0, 0x3
    /* 1DEEC8 002DEEC8 8800A5DF */  ld         $5, 0x88($29)
    /* 1DEECC 002DEECC 06B30046 */  mov.s      $f12, $f22
    /* 1DEED0 002DEED0 2D304000 */  daddu      $6, $2, $0
    /* 1DEED4 002DEED4 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEED8 002DEED8 2D400000 */  daddu      $8, $0, $0
    /* 1DEEDC 002DEEDC 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DEEE0 002DEEE0 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DEEE4 002DEEE4 C8820B0C */  jal        func_002e0b20
    /* 1DEEE8 002DEEE8 00000000 */   nop
    /* 1DEEEC 002DEEEC D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DEEF0 002DEEF0 00608244 */  mtc1       $2, $f12
    /* 1DEEF4 002DEEF4 71010224 */  addiu      $2, $0, 0x171
    /* 1DEEF8 002DEEF8 00008244 */  mtc1       $2, $f0
    /* 1DEEFC 002DEEFC 00000000 */  nop
    /* 1DEF00 002DEF00 60038046 */  cvt.s.w    $f13, $f0
    /* 1DEF04 002DEF04 8000A427 */  addiu      $4, $29, 0x80
    /* 1DEF08 002DEF08 5CCA0A0C */  jal        func_002b2970
    /* 1DEF0C 002DEF0C 00000000 */   nop
    /* 1DEF10 002DEF10 2D200000 */  daddu      $4, $0, $0
    /* 1DEF14 002DEF14 FF000524 */  addiu      $5, $0, 0xFF
    /* 1DEF18 002DEF18 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DEF1C 002DEF1C 80000724 */  addiu      $7, $0, 0x80
    /* 1DEF20 002DEF20 8CCA0A0C */  jal        func_002b2a30
    /* 1DEF24 002DEF24 00000000 */   nop
    /* 1DEF28 002DEF28 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DEF2C 002DEF2C 00608344 */  mtc1       $3, $f12
    /* 1DEF30 002DEF30 07000424 */  addiu      $4, $0, 0x7
    /* 1DEF34 002DEF34 8000A5DF */  ld         $5, 0x80($29)
    /* 1DEF38 002DEF38 2D304000 */  daddu      $6, $2, $0
    /* 1DEF3C 002DEF3C FF000724 */  addiu      $7, $0, 0xFF
    /* 1DEF40 002DEF40 2D400000 */  daddu      $8, $0, $0
    /* 1DEF44 002DEF44 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DEF48 002DEF48 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DEF4C 002DEF4C C8820B0C */  jal        func_002e0b20
    /* 1DEF50 002DEF50 00000000 */   nop
    /* 1DEF54 002DEF54 FF000424 */  addiu      $4, $0, 0xFF
    /* 1DEF58 002DEF58 EF000524 */  addiu      $5, $0, 0xEF
    /* 1DEF5C 002DEF5C 81000624 */  addiu      $6, $0, 0x81
    /* 1DEF60 002DEF60 2D388000 */  daddu      $7, $4, $0
    /* 1DEF64 002DEF64 8CCA0A0C */  jal        func_002b2a30
    /* 1DEF68 002DEF68 00000000 */   nop
    /* 1DEF6C 002DEF6C 2D884000 */  daddu      $17, $2, $0
    /* 1DEF70 002DEF70 D243023C */  lui        $2, (0x43D20000 >> 16)
    /* 1DEF74 002DEF74 00608244 */  mtc1       $2, $f12
    /* 1DEF78 002DEF78 C543023C */  lui        $2, (0x43C50000 >> 16)
    /* 1DEF7C 002DEF7C 00688244 */  mtc1       $2, $f13
    /* 1DEF80 002DEF80 7800A427 */  addiu      $4, $29, 0x78
    /* 1DEF84 002DEF84 5CCA0A0C */  jal        func_002b2970
    /* 1DEF88 002DEF88 00000000 */   nop
    /* 1DEF8C 002DEF8C 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* 1DEF90 002DEF90 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* 1DEF94 002DEF94 4800A1E7 */  swc1       $f1, 0x48($29)
    /* 1DEF98 002DEF98 4C00A0E7 */  swc1       $f0, 0x4C($29)
    /* 1DEF9C 002DEF9C 08000282 */  lb         $2, 0x8($16)
    /* 1DEFA0 002DEFA0 21105000 */  addu       $2, $2, $16
    /* 1DEFA4 002DEFA4 730F4480 */  lb         $4, 0xF73($2)
    /* 1DEFA8 002DEFA8 02000524 */  addiu      $5, $0, 0x2
    /* 1DEFAC 002DEFAC 341B040C */  jal        func_00106cd0
    /* 1DEFB0 002DEFB0 00000000 */   nop
    /* 1DEFB4 002DEFB4 3C240200 */  dsll32     $4, $2, 16
    /* 1DEFB8 002DEFB8 3F240400 */  dsra32     $4, $4, 16
    /* 1DEFBC 002DEFBC FC19040C */  jal        func_001067f0
    /* 1DEFC0 002DEFC0 00000000 */   nop
    /* 1DEFC4 002DEFC4 4800ACC7 */  lwc1       $f12, 0x48($29)
    /* 1DEFC8 002DEFC8 4C00ADC7 */  lwc1       $f13, 0x4C($29)
    /* 1DEFCC 002DEFCC 86A30046 */  mov.s      $f14, $f20
    /* 1DEFD0 002DEFD0 2D202002 */  daddu      $4, $17, $0
    /* 1DEFD4 002DEFD4 2D280000 */  daddu      $5, $0, $0
    /* 1DEFD8 002DEFD8 01000624 */  addiu      $6, $0, 0x1
    /* 1DEFDC 002DEFDC 2D384000 */  daddu      $7, $2, $0
    /* 1DEFE0 002DEFE0 2D400000 */  daddu      $8, $0, $0
    /* 1DEFE4 002DEFE4 2D480000 */  daddu      $9, $0, $0
    /* 1DEFE8 002DEFE8 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DEFEC 002DEFEC 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DEFF0 002DEFF0 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DEFF4 002DEFF4 A0D5090C */  jal        func_00275680
    /* 1DEFF8 002DEFF8 00000000 */   nop
  .L002DEFFC:
    /* 1DEFFC 002DEFFC 3000BFDF */  ld         $31, 0x30($29)
    /* 1DF000 002DF000 2000B17B */  lq         $17, 0x20($29)
    /* 1DF004 002DF004 1000B07B */  lq         $16, 0x10($29)
    /* 1DF008 002DF008 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 1DF00C 002DF00C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1DF010 002DF010 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1DF014 002DF014 2001BD27 */  addiu      $29, $29, 0x120
    /* 1DF018 002DF018 0800E003 */  jr         $31
    /* 1DF01C 002DF01C 00000000 */   nop
.size func_002de5a0, 0xa80
