.section .text
.set noat
.set noreorder
glabel func_002ae630
    /* 1AE630 002AE630 F0FDBD27 */  addiu      $29, $29, -0x210
    /* 1AE634 002AE634 A000BFFF */  sd         $31, 0xA0($29)
    /* 1AE638 002AE638 9000BE7F */  sq         $30, 0x90($29)
    /* 1AE63C 002AE63C 8000B77F */  sq         $23, 0x80($29)
    /* 1AE640 002AE640 7000B67F */  sq         $22, 0x70($29)
    /* 1AE644 002AE644 6000B57F */  sq         $21, 0x60($29)
    /* 1AE648 002AE648 5000B47F */  sq         $20, 0x50($29)
    /* 1AE64C 002AE64C 4000B37F */  sq         $19, 0x40($29)
    /* 1AE650 002AE650 3000B27F */  sq         $18, 0x30($29)
    /* 1AE654 002AE654 2000B17F */  sq         $17, 0x20($29)
    /* 1AE658 002AE658 1000B07F */  sq         $16, 0x10($29)
    /* 1AE65C 002AE65C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1AE660 002AE660 2D808000 */  daddu      $16, $4, $0
    /* 1AE664 002AE664 6400043C */  lui        $4, %hi(D_0063EF60)
    /* 1AE668 002AE668 60EF8424 */  addiu      $4, $4, %lo(D_0063EF60)
    /* 1AE66C 002AE66C 89030524 */  addiu      $5, $0, 0x389
    /* 1AE670 002AE670 A43A110C */  jal        func_0044ea90
    /* 1AE674 002AE674 00000000 */   nop
    /* 1AE678 002AE678 01000424 */  addiu      $4, $0, 0x1
    /* 1AE67C 002AE67C 68070524 */  addiu      $5, $0, 0x768
    /* 1AE680 002AE680 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1AE684 002AE684 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1AE688 002AE688 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1AE68C 002AE68C 09F84000 */  jalr       $2
    /* 1AE690 002AE690 00000000 */   nop
    /* 1AE694 002AE694 2D984000 */  daddu      $19, $2, $0
    /* 1AE698 002AE698 2D200002 */  daddu      $4, $16, $0
    /* 1AE69C 002AE69C 6400053C */  lui        $5, %hi(D_0063EFD8)
    /* 1AE6A0 002AE6A0 D8EFA524 */  addiu      $5, $5, %lo(D_0063EFD8)
    /* 1AE6A4 002AE6A4 0F000624 */  addiu      $6, $0, 0xF
    /* 1AE6A8 002AE6A8 2D380000 */  daddu      $7, $0, $0
    /* 1AE6AC 002AE6AC 2D400000 */  daddu      $8, $0, $0
    /* 1AE6B0 002AE6B0 2B00093C */  lui        $9, %hi(func_002add90)
    /* 1AE6B4 002AE6B4 90DD2925 */  addiu      $9, $9, %lo(func_002add90)
    /* 1AE6B8 002AE6B8 2B000A3C */  lui        $10, %hi(func_002ae520)
    /* 1AE6BC 002AE6BC 20E54A25 */  addiu      $10, $10, %lo(func_002ae520)
    /* 1AE6C0 002AE6C0 2D586002 */  daddu      $11, $19, $0
    /* 1AE6C4 002AE6C4 F047110C */  jal        func_00451fc0
    /* 1AE6C8 002AE6C8 00000000 */   nop
    /* 1AE6CC 002AE6CC 2DA04000 */  daddu      $20, $2, $0
    /* 1AE6D0 002AE6D0 000073AE */  sw         $19, 0x0($19)
    /* 1AE6D4 002AE6D4 040060A2 */  sb         $0, 0x4($19)
    /* 1AE6D8 002AE6D8 7F00023C */  lui        $2, %hi(D_007EFA04)
    /* 1AE6DC 002AE6DC 04FA428C */  lw         $2, %lo(D_007EFA04)($2)
    /* 1AE6E0 002AE6E0 2002448C */  lw         $4, 0x220($2)
    /* 1AE6E4 002AE6E4 F4A1050C */  jal        func_001687d0
    /* 1AE6E8 002AE6E8 00000000 */   nop
    /* 1AE6EC 002AE6EC FF005030 */  andi       $16, $2, 0xFF
    /* 1AE6F0 002AE6F0 7F00023C */  lui        $2, %hi(D_007EFA04)
    /* 1AE6F4 002AE6F4 04FA428C */  lw         $2, %lo(D_007EFA04)($2)
    /* 1AE6F8 002AE6F8 2002448C */  lw         $4, 0x220($2)
    /* 1AE6FC 002AE6FC F8A1050C */  jal        func_001687e0
    /* 1AE700 002AE700 00000000 */   nop
    /* 1AE704 002AE704 FF004630 */  andi       $6, $2, 0xFF
    /* 1AE708 002AE708 E801A427 */  addiu      $4, $29, 0x1E8
    /* 1AE70C 002AE70C 2D280002 */  daddu      $5, $16, $0
    /* 1AE710 002AE710 40C40A0C */  jal        func_002b1100
    /* 1AE714 002AE714 00000000 */   nop
    /* 1AE718 002AE718 08006426 */  addiu      $4, $19, 0x8
    /* 1AE71C 002AE71C E801A2C7 */  lwc1       $f2, 0x1E8($29)
    /* 1AE720 002AE720 EC01A1C7 */  lwc1       $f1, 0x1EC($29)
    /* 1AE724 002AE724 F001A0C7 */  lwc1       $f0, 0x1F0($29)
    /* 1AE728 002AE728 080062E6 */  swc1       $f2, 0x8($19)
    /* 1AE72C 002AE72C 0C0061E6 */  swc1       $f1, 0xC($19)
    /* 1AE730 002AE730 100060E6 */  swc1       $f0, 0x10($19)
    /* 1AE734 002AE734 70C40A0C */  jal        func_002b11c0
    /* 1AE738 002AE738 00000000 */   nop
    /* 1AE73C 002AE73C 70B582A3 */  sb         $2, -0x4A90($28)
    /* 1AE740 002AE740 08006426 */  addiu      $4, $19, 0x8
    /* 1AE744 002AE744 84C40A0C */  jal        func_002b1210
    /* 1AE748 002AE748 00000000 */   nop
    /* 1AE74C 002AE74C 6CB582A3 */  sb         $2, -0x4A94($28)
    /* 1AE750 002AE750 12000224 */  addiu      $2, $0, 0x12
    /* 1AE754 002AE754 200062A2 */  sb         $2, 0x20($19)
    /* 1AE758 002AE758 2D900000 */  daddu      $18, $0, $0
    /* 1AE75C 002AE75C 11020010 */  b          .L002AEFA4
    /* 1AE760 002AE760 00000000 */   nop
  .L002AE764:
    /* 1AE764 002AE764 2D880000 */  daddu      $17, $0, $0
    /* 1AE768 002AE768 00821200 */  sll        $16, $18, 8
    /* 1AE76C 002AE76C 80111200 */  sll        $2, $18, 6
    /* 1AE770 002AE770 21B06202 */  addu       $22, $19, $2
    /* 1AE774 002AE774 07020010 */  b          .L002AEF94
    /* 1AE778 002AE778 00000000 */   nop
  .L002AE77C:
    /* 1AE77C 002AE77C 00A91100 */  sll        $21, $17, 4
    /* 1AE780 002AE780 A054050C */  jal        func_00155280
    /* 1AE784 002AE784 00000000 */   nop
    /* 1AE788 002AE788 21100202 */  addu       $2, $16, $2
    /* 1AE78C 002AE78C 21105500 */  addu       $2, $2, $21
    /* 1AE790 002AE790 54004290 */  lbu        $2, 0x54($2)
    /* 1AE794 002AE794 FE014010 */  beqz       $2, .L002AEF90
    /* 1AE798 002AE798 00000000 */   nop
    /* 1AE79C 002AE79C A054050C */  jal        func_00155280
    /* 1AE7A0 002AE7A0 00000000 */   nop
    /* 1AE7A4 002AE7A4 21100202 */  addu       $2, $16, $2
    /* 1AE7A8 002AE7A8 21105500 */  addu       $2, $2, $21
    /* 1AE7AC 002AE7AC 55004290 */  lbu        $2, 0x55($2)
    /* 1AE7B0 002AE7B0 0F004330 */  andi       $3, $2, 0xF
    /* 1AE7B4 002AE7B4 01000224 */  addiu      $2, $0, 0x1
    /* 1AE7B8 002AE7B8 F5016214 */  bne        $3, $2, .L002AEF90
    /* 1AE7BC 002AE7BC 00000000 */   nop
    /* 1AE7C0 002AE7C0 A054050C */  jal        func_00155280
    /* 1AE7C4 002AE7C4 00000000 */   nop
    /* 1AE7C8 002AE7C8 21100202 */  addu       $2, $16, $2
    /* 1AE7CC 002AE7CC 21105500 */  addu       $2, $2, $21
    /* 1AE7D0 002AE7D0 58004290 */  lbu        $2, 0x58($2)
    /* 1AE7D4 002AE7D4 09004228 */  slti       $2, $2, 0x9
    /* 1AE7D8 002AE7D8 6D014014 */  bnez       $2, .L002AED90
    /* 1AE7DC 002AE7DC 00000000 */   nop
    /* 1AE7E0 002AE7E0 A054050C */  jal        func_00155280
    /* 1AE7E4 002AE7E4 00000000 */   nop
    /* 1AE7E8 002AE7E8 21100202 */  addu       $2, $16, $2
    /* 1AE7EC 002AE7EC 21105500 */  addu       $2, $2, $21
    /* 1AE7F0 002AE7F0 58004290 */  lbu        $2, 0x58($2)
    /* 1AE7F4 002AE7F4 F7FF4224 */  addiu      $2, $2, -0x9
    /* 1AE7F8 002AE7F8 0600412C */  sltiu      $1, $2, 0x6
    /* 1AE7FC 002AE7FC E4012010 */  beqz       $1, .L002AEF90
    /* 1AE800 002AE800 00000000 */   nop
    /* 1AE804 002AE804 7500033C */  lui        $3, %hi(jtbl_00748820)
    /* 1AE808 002AE808 20886324 */  addiu      $3, $3, %lo(jtbl_00748820)
    /* 1AE80C 002AE80C 80100200 */  sll        $2, $2, 2
    /* 1AE810 002AE810 21104300 */  addu       $2, $2, $3
    /* 1AE814 002AE814 0000428C */  lw         $2, 0x0($2)
    /* 1AE818 002AE818 08004000 */  jr         $2
    /* 1AE81C 002AE81C 00000000 */   nop
    /* 1AE820 002AE820 A054050C */  jal        func_00155280
    /* 1AE824 002AE824 00000000 */   nop
    /* 1AE828 002AE828 21100202 */  addu       $2, $16, $2
    /* 1AE82C 002AE82C 21105500 */  addu       $2, $2, $21
    /* 1AE830 002AE830 59004290 */  lbu        $2, 0x59($2)
    /* 1AE834 002AE834 40180200 */  sll        $3, $2, 1
    /* 1AE838 002AE838 6400023C */  lui        $2, %hi(D_0063EEE0)
    /* 1AE83C 002AE83C E0EE4224 */  addiu      $2, $2, %lo(D_0063EEE0)
    /* 1AE840 002AE840 21104300 */  addu       $2, $2, $3
    /* 1AE844 002AE844 00005E80 */  lb         $30, 0x0($2)
    /* 1AE848 002AE848 A054050C */  jal        func_00155280
    /* 1AE84C 002AE84C 00000000 */   nop
    /* 1AE850 002AE850 21100202 */  addu       $2, $16, $2
    /* 1AE854 002AE854 21105500 */  addu       $2, $2, $21
    /* 1AE858 002AE858 59004290 */  lbu        $2, 0x59($2)
    /* 1AE85C 002AE85C 40180200 */  sll        $3, $2, 1
    /* 1AE860 002AE860 6400023C */  lui        $2, %hi(D_0063EEE0)
    /* 1AE864 002AE864 E0EE4224 */  addiu      $2, $2, %lo(D_0063EEE0)
    /* 1AE868 002AE868 21104300 */  addu       $2, $2, $3
    /* 1AE86C 002AE86C 01005780 */  lb         $23, 0x1($2)
    /* 1AE870 002AE870 3C161E00 */  dsll32     $2, $30, 24
    /* 1AE874 002AE874 3F160200 */  dsra32     $2, $2, 24
    /* 1AE878 002AE878 21F02202 */  addu       $30, $17, $2
    /* 1AE87C 002AE87C A054050C */  jal        func_00155280
    /* 1AE880 002AE880 00000000 */   nop
    /* 1AE884 002AE884 21100202 */  addu       $2, $16, $2
    /* 1AE888 002AE888 21105500 */  addu       $2, $2, $21
    /* 1AE88C 002AE88C B001A27F */  sq         $2, 0x1B0($29)
    /* 1AE890 002AE890 A054050C */  jal        func_00155280
    /* 1AE894 002AE894 00000000 */   nop
    /* 1AE898 002AE898 21100202 */  addu       $2, $16, $2
    /* 1AE89C 002AE89C 21185500 */  addu       $3, $2, $21
    /* 1AE8A0 002AE8A0 FF00C533 */  andi       $5, $30, 0xFF
    /* 1AE8A4 002AE8A4 21105702 */  addu       $2, $18, $23
    /* 1AE8A8 002AE8A8 FF004630 */  andi       $6, $2, 0xFF
    /* 1AE8AC 002AE8AC FF002A32 */  andi       $10, $17, 0xFF
    /* 1AE8B0 002AE8B0 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AE8B4 002AE8B4 2D208002 */  daddu      $4, $20, $0
    /* 1AE8B8 002AE8B8 B001A27B */  lq         $2, 0x1B0($29)
    /* 1AE8BC 002AE8BC 58004790 */  lbu        $7, 0x58($2)
    /* 1AE8C0 002AE8C0 01000824 */  addiu      $8, $0, 0x1
    /* 1AE8C4 002AE8C4 59006990 */  lbu        $9, 0x59($3)
    /* 1AE8C8 002AE8C8 94C00A0C */  jal        func_002b0250
    /* 1AE8CC 002AE8CC 00000000 */   nop
    /* 1AE8D0 002AE8D0 80191700 */  sll        $3, $23, 6
    /* 1AE8D4 002AE8D4 2120C302 */  addu       $4, $22, $3
    /* 1AE8D8 002AE8D8 80181E00 */  sll        $3, $30, 2
    /* 1AE8DC 002AE8DC 21188300 */  addu       $3, $4, $3
    /* 1AE8E0 002AE8E0 480162AC */  sw         $2, 0x148($3)
    /* 1AE8E4 002AE8E4 A054050C */  jal        func_00155280
    /* 1AE8E8 002AE8E8 00000000 */   nop
    /* 1AE8EC 002AE8EC 21100202 */  addu       $2, $16, $2
    /* 1AE8F0 002AE8F0 21105500 */  addu       $2, $2, $21
    /* 1AE8F4 002AE8F4 59004290 */  lbu        $2, 0x59($2)
    /* 1AE8F8 002AE8F8 40180200 */  sll        $3, $2, 1
    /* 1AE8FC 002AE8FC 6400023C */  lui        $2, %hi(D_0063EEE0)
    /* 1AE900 002AE900 E0EE4224 */  addiu      $2, $2, %lo(D_0063EEE0)
    /* 1AE904 002AE904 21104300 */  addu       $2, $2, $3
    /* 1AE908 002AE908 08005E80 */  lb         $30, 0x8($2)
    /* 1AE90C 002AE90C A054050C */  jal        func_00155280
    /* 1AE910 002AE910 00000000 */   nop
    /* 1AE914 002AE914 21100202 */  addu       $2, $16, $2
    /* 1AE918 002AE918 21105500 */  addu       $2, $2, $21
    /* 1AE91C 002AE91C 59004290 */  lbu        $2, 0x59($2)
    /* 1AE920 002AE920 40180200 */  sll        $3, $2, 1
    /* 1AE924 002AE924 6400023C */  lui        $2, %hi(D_0063EEE0)
    /* 1AE928 002AE928 E0EE4224 */  addiu      $2, $2, %lo(D_0063EEE0)
    /* 1AE92C 002AE92C 21104300 */  addu       $2, $2, $3
    /* 1AE930 002AE930 09005780 */  lb         $23, 0x9($2)
    /* 1AE934 002AE934 3C161E00 */  dsll32     $2, $30, 24
    /* 1AE938 002AE938 3F160200 */  dsra32     $2, $2, 24
    /* 1AE93C 002AE93C 21F02202 */  addu       $30, $17, $2
    /* 1AE940 002AE940 A054050C */  jal        func_00155280
    /* 1AE944 002AE944 00000000 */   nop
    /* 1AE948 002AE948 21100202 */  addu       $2, $16, $2
    /* 1AE94C 002AE94C 21105500 */  addu       $2, $2, $21
    /* 1AE950 002AE950 A001A27F */  sq         $2, 0x1A0($29)
    /* 1AE954 002AE954 A054050C */  jal        func_00155280
    /* 1AE958 002AE958 00000000 */   nop
    /* 1AE95C 002AE95C 21100202 */  addu       $2, $16, $2
    /* 1AE960 002AE960 21185500 */  addu       $3, $2, $21
    /* 1AE964 002AE964 FF00C533 */  andi       $5, $30, 0xFF
    /* 1AE968 002AE968 21105702 */  addu       $2, $18, $23
    /* 1AE96C 002AE96C FF004630 */  andi       $6, $2, 0xFF
    /* 1AE970 002AE970 FF002A32 */  andi       $10, $17, 0xFF
    /* 1AE974 002AE974 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AE978 002AE978 2D208002 */  daddu      $4, $20, $0
    /* 1AE97C 002AE97C A001A27B */  lq         $2, 0x1A0($29)
    /* 1AE980 002AE980 58004790 */  lbu        $7, 0x58($2)
    /* 1AE984 002AE984 02000824 */  addiu      $8, $0, 0x2
    /* 1AE988 002AE988 59006990 */  lbu        $9, 0x59($3)
    /* 1AE98C 002AE98C 94C00A0C */  jal        func_002b0250
    /* 1AE990 002AE990 00000000 */   nop
    /* 1AE994 002AE994 80191700 */  sll        $3, $23, 6
    /* 1AE998 002AE998 2120C302 */  addu       $4, $22, $3
    /* 1AE99C 002AE99C 80181E00 */  sll        $3, $30, 2
    /* 1AE9A0 002AE9A0 21188300 */  addu       $3, $4, $3
    /* 1AE9A4 002AE9A4 480162AC */  sw         $2, 0x148($3)
    /* 1AE9A8 002AE9A8 79010010 */  b          .L002AEF90
    /* 1AE9AC 002AE9AC 00000000 */   nop
    /* 1AE9B0 002AE9B0 6400173C */  lui        $23, %hi(D_0063EF00)
    /* 1AE9B4 002AE9B4 00EFF726 */  addiu      $23, $23, %lo(D_0063EF00)
    /* 1AE9B8 002AE9B8 A054050C */  jal        func_00155280
    /* 1AE9BC 002AE9BC 00000000 */   nop
    /* 1AE9C0 002AE9C0 21100202 */  addu       $2, $16, $2
    /* 1AE9C4 002AE9C4 21105500 */  addu       $2, $2, $21
    /* 1AE9C8 002AE9C8 59004290 */  lbu        $2, 0x59($2)
    /* 1AE9CC 002AE9CC 40100200 */  sll        $2, $2, 1
    /* 1AE9D0 002AE9D0 2110E202 */  addu       $2, $23, $2
    /* 1AE9D4 002AE9D4 00004280 */  lb         $2, 0x0($2)
    /* 1AE9D8 002AE9D8 9001A27F */  sq         $2, 0x190($29)
    /* 1AE9DC 002AE9DC A054050C */  jal        func_00155280
    /* 1AE9E0 002AE9E0 00000000 */   nop
    /* 1AE9E4 002AE9E4 21100202 */  addu       $2, $16, $2
    /* 1AE9E8 002AE9E8 21105500 */  addu       $2, $2, $21
    /* 1AE9EC 002AE9EC 59004290 */  lbu        $2, 0x59($2)
    /* 1AE9F0 002AE9F0 40100200 */  sll        $2, $2, 1
    /* 1AE9F4 002AE9F4 2110E202 */  addu       $2, $23, $2
    /* 1AE9F8 002AE9F8 01005E80 */  lb         $30, 0x1($2)
    /* 1AE9FC 002AE9FC 9001A27B */  lq         $2, 0x190($29)
    /* 1AEA00 002AEA00 3C160200 */  dsll32     $2, $2, 24
    /* 1AEA04 002AEA04 3F160200 */  dsra32     $2, $2, 24
    /* 1AEA08 002AEA08 21102202 */  addu       $2, $17, $2
    /* 1AEA0C 002AEA0C 8001A27F */  sq         $2, 0x180($29)
    /* 1AEA10 002AEA10 A054050C */  jal        func_00155280
    /* 1AEA14 002AEA14 00000000 */   nop
    /* 1AEA18 002AEA18 21100202 */  addu       $2, $16, $2
    /* 1AEA1C 002AEA1C 21105500 */  addu       $2, $2, $21
    /* 1AEA20 002AEA20 7001A27F */  sq         $2, 0x170($29)
    /* 1AEA24 002AEA24 A054050C */  jal        func_00155280
    /* 1AEA28 002AEA28 00000000 */   nop
    /* 1AEA2C 002AEA2C 21100202 */  addu       $2, $16, $2
    /* 1AEA30 002AEA30 21185500 */  addu       $3, $2, $21
    /* 1AEA34 002AEA34 8001A27B */  lq         $2, 0x180($29)
    /* 1AEA38 002AEA38 FF004530 */  andi       $5, $2, 0xFF
    /* 1AEA3C 002AEA3C 21105E02 */  addu       $2, $18, $30
    /* 1AEA40 002AEA40 FF004630 */  andi       $6, $2, 0xFF
    /* 1AEA44 002AEA44 FF002A32 */  andi       $10, $17, 0xFF
    /* 1AEA48 002AEA48 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AEA4C 002AEA4C 2D208002 */  daddu      $4, $20, $0
    /* 1AEA50 002AEA50 7001A27B */  lq         $2, 0x170($29)
    /* 1AEA54 002AEA54 58004790 */  lbu        $7, 0x58($2)
    /* 1AEA58 002AEA58 01000824 */  addiu      $8, $0, 0x1
    /* 1AEA5C 002AEA5C 59006990 */  lbu        $9, 0x59($3)
    /* 1AEA60 002AEA60 94C00A0C */  jal        func_002b0250
    /* 1AEA64 002AEA64 00000000 */   nop
    /* 1AEA68 002AEA68 80191E00 */  sll        $3, $30, 6
    /* 1AEA6C 002AEA6C 2120C302 */  addu       $4, $22, $3
    /* 1AEA70 002AEA70 8001A37B */  lq         $3, 0x180($29)
    /* 1AEA74 002AEA74 80180300 */  sll        $3, $3, 2
    /* 1AEA78 002AEA78 21188300 */  addu       $3, $4, $3
    /* 1AEA7C 002AEA7C 480162AC */  sw         $2, 0x148($3)
    /* 1AEA80 002AEA80 A054050C */  jal        func_00155280
    /* 1AEA84 002AEA84 00000000 */   nop
    /* 1AEA88 002AEA88 21100202 */  addu       $2, $16, $2
    /* 1AEA8C 002AEA8C 21105500 */  addu       $2, $2, $21
    /* 1AEA90 002AEA90 59004290 */  lbu        $2, 0x59($2)
    /* 1AEA94 002AEA94 40100200 */  sll        $2, $2, 1
    /* 1AEA98 002AEA98 2110E202 */  addu       $2, $23, $2
    /* 1AEA9C 002AEA9C 08005E80 */  lb         $30, 0x8($2)
    /* 1AEAA0 002AEAA0 A054050C */  jal        func_00155280
    /* 1AEAA4 002AEAA4 00000000 */   nop
    /* 1AEAA8 002AEAA8 21100202 */  addu       $2, $16, $2
    /* 1AEAAC 002AEAAC 21105500 */  addu       $2, $2, $21
    /* 1AEAB0 002AEAB0 59004290 */  lbu        $2, 0x59($2)
    /* 1AEAB4 002AEAB4 40100200 */  sll        $2, $2, 1
    /* 1AEAB8 002AEAB8 2110E202 */  addu       $2, $23, $2
    /* 1AEABC 002AEABC 09005780 */  lb         $23, 0x9($2)
    /* 1AEAC0 002AEAC0 3C161E00 */  dsll32     $2, $30, 24
    /* 1AEAC4 002AEAC4 3F160200 */  dsra32     $2, $2, 24
    /* 1AEAC8 002AEAC8 21F02202 */  addu       $30, $17, $2
    /* 1AEACC 002AEACC A054050C */  jal        func_00155280
    /* 1AEAD0 002AEAD0 00000000 */   nop
    /* 1AEAD4 002AEAD4 21100202 */  addu       $2, $16, $2
    /* 1AEAD8 002AEAD8 21105500 */  addu       $2, $2, $21
    /* 1AEADC 002AEADC 6001A27F */  sq         $2, 0x160($29)
    /* 1AEAE0 002AEAE0 A054050C */  jal        func_00155280
    /* 1AEAE4 002AEAE4 00000000 */   nop
    /* 1AEAE8 002AEAE8 21100202 */  addu       $2, $16, $2
    /* 1AEAEC 002AEAEC 21185500 */  addu       $3, $2, $21
    /* 1AEAF0 002AEAF0 FF00C533 */  andi       $5, $30, 0xFF
    /* 1AEAF4 002AEAF4 21105702 */  addu       $2, $18, $23
    /* 1AEAF8 002AEAF8 FF004630 */  andi       $6, $2, 0xFF
    /* 1AEAFC 002AEAFC FF002A32 */  andi       $10, $17, 0xFF
    /* 1AEB00 002AEB00 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AEB04 002AEB04 2D208002 */  daddu      $4, $20, $0
    /* 1AEB08 002AEB08 6001A27B */  lq         $2, 0x160($29)
    /* 1AEB0C 002AEB0C 58004790 */  lbu        $7, 0x58($2)
    /* 1AEB10 002AEB10 02000824 */  addiu      $8, $0, 0x2
    /* 1AEB14 002AEB14 59006990 */  lbu        $9, 0x59($3)
    /* 1AEB18 002AEB18 94C00A0C */  jal        func_002b0250
    /* 1AEB1C 002AEB1C 00000000 */   nop
    /* 1AEB20 002AEB20 80191700 */  sll        $3, $23, 6
    /* 1AEB24 002AEB24 2120C302 */  addu       $4, $22, $3
    /* 1AEB28 002AEB28 80181E00 */  sll        $3, $30, 2
    /* 1AEB2C 002AEB2C 21188300 */  addu       $3, $4, $3
    /* 1AEB30 002AEB30 480162AC */  sw         $2, 0x148($3)
    /* 1AEB34 002AEB34 16010010 */  b          .L002AEF90
    /* 1AEB38 002AEB38 00000000 */   nop
    /* 1AEB3C 002AEB3C 6400173C */  lui        $23, %hi(D_0063EF20)
    /* 1AEB40 002AEB40 20EFF726 */  addiu      $23, $23, %lo(D_0063EF20)
    /* 1AEB44 002AEB44 A054050C */  jal        func_00155280
    /* 1AEB48 002AEB48 00000000 */   nop
    /* 1AEB4C 002AEB4C 21100202 */  addu       $2, $16, $2
    /* 1AEB50 002AEB50 21105500 */  addu       $2, $2, $21
    /* 1AEB54 002AEB54 59004290 */  lbu        $2, 0x59($2)
    /* 1AEB58 002AEB58 40100200 */  sll        $2, $2, 1
    /* 1AEB5C 002AEB5C 2110E202 */  addu       $2, $23, $2
    /* 1AEB60 002AEB60 00004280 */  lb         $2, 0x0($2)
    /* 1AEB64 002AEB64 5001A27F */  sq         $2, 0x150($29)
    /* 1AEB68 002AEB68 A054050C */  jal        func_00155280
    /* 1AEB6C 002AEB6C 00000000 */   nop
    /* 1AEB70 002AEB70 21100202 */  addu       $2, $16, $2
    /* 1AEB74 002AEB74 21105500 */  addu       $2, $2, $21
    /* 1AEB78 002AEB78 59004290 */  lbu        $2, 0x59($2)
    /* 1AEB7C 002AEB7C 40100200 */  sll        $2, $2, 1
    /* 1AEB80 002AEB80 2110E202 */  addu       $2, $23, $2
    /* 1AEB84 002AEB84 01005E80 */  lb         $30, 0x1($2)
    /* 1AEB88 002AEB88 5001A27B */  lq         $2, 0x150($29)
    /* 1AEB8C 002AEB8C 3C160200 */  dsll32     $2, $2, 24
    /* 1AEB90 002AEB90 3F160200 */  dsra32     $2, $2, 24
    /* 1AEB94 002AEB94 21102202 */  addu       $2, $17, $2
    /* 1AEB98 002AEB98 4001A27F */  sq         $2, 0x140($29)
    /* 1AEB9C 002AEB9C A054050C */  jal        func_00155280
    /* 1AEBA0 002AEBA0 00000000 */   nop
    /* 1AEBA4 002AEBA4 21100202 */  addu       $2, $16, $2
    /* 1AEBA8 002AEBA8 21105500 */  addu       $2, $2, $21
    /* 1AEBAC 002AEBAC 3001A27F */  sq         $2, 0x130($29)
    /* 1AEBB0 002AEBB0 A054050C */  jal        func_00155280
    /* 1AEBB4 002AEBB4 00000000 */   nop
    /* 1AEBB8 002AEBB8 21100202 */  addu       $2, $16, $2
    /* 1AEBBC 002AEBBC 21185500 */  addu       $3, $2, $21
    /* 1AEBC0 002AEBC0 4001A27B */  lq         $2, 0x140($29)
    /* 1AEBC4 002AEBC4 FF004530 */  andi       $5, $2, 0xFF
    /* 1AEBC8 002AEBC8 21105E02 */  addu       $2, $18, $30
    /* 1AEBCC 002AEBCC FF004630 */  andi       $6, $2, 0xFF
    /* 1AEBD0 002AEBD0 FF002A32 */  andi       $10, $17, 0xFF
    /* 1AEBD4 002AEBD4 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AEBD8 002AEBD8 2D208002 */  daddu      $4, $20, $0
    /* 1AEBDC 002AEBDC 3001A27B */  lq         $2, 0x130($29)
    /* 1AEBE0 002AEBE0 58004790 */  lbu        $7, 0x58($2)
    /* 1AEBE4 002AEBE4 01000824 */  addiu      $8, $0, 0x1
    /* 1AEBE8 002AEBE8 59006990 */  lbu        $9, 0x59($3)
    /* 1AEBEC 002AEBEC 94C00A0C */  jal        func_002b0250
    /* 1AEBF0 002AEBF0 00000000 */   nop
    /* 1AEBF4 002AEBF4 80191E00 */  sll        $3, $30, 6
    /* 1AEBF8 002AEBF8 2120C302 */  addu       $4, $22, $3
    /* 1AEBFC 002AEBFC 4001A37B */  lq         $3, 0x140($29)
    /* 1AEC00 002AEC00 80180300 */  sll        $3, $3, 2
    /* 1AEC04 002AEC04 21188300 */  addu       $3, $4, $3
    /* 1AEC08 002AEC08 480162AC */  sw         $2, 0x148($3)
    /* 1AEC0C 002AEC0C A054050C */  jal        func_00155280
    /* 1AEC10 002AEC10 00000000 */   nop
    /* 1AEC14 002AEC14 21100202 */  addu       $2, $16, $2
    /* 1AEC18 002AEC18 21105500 */  addu       $2, $2, $21
    /* 1AEC1C 002AEC1C 59004290 */  lbu        $2, 0x59($2)
    /* 1AEC20 002AEC20 40100200 */  sll        $2, $2, 1
    /* 1AEC24 002AEC24 2110E202 */  addu       $2, $23, $2
    /* 1AEC28 002AEC28 08004280 */  lb         $2, 0x8($2)
    /* 1AEC2C 002AEC2C 2001A27F */  sq         $2, 0x120($29)
    /* 1AEC30 002AEC30 A054050C */  jal        func_00155280
    /* 1AEC34 002AEC34 00000000 */   nop
    /* 1AEC38 002AEC38 21100202 */  addu       $2, $16, $2
    /* 1AEC3C 002AEC3C 21105500 */  addu       $2, $2, $21
    /* 1AEC40 002AEC40 59004290 */  lbu        $2, 0x59($2)
    /* 1AEC44 002AEC44 40100200 */  sll        $2, $2, 1
    /* 1AEC48 002AEC48 2110E202 */  addu       $2, $23, $2
    /* 1AEC4C 002AEC4C 09005E80 */  lb         $30, 0x9($2)
    /* 1AEC50 002AEC50 2001A27B */  lq         $2, 0x120($29)
    /* 1AEC54 002AEC54 3C160200 */  dsll32     $2, $2, 24
    /* 1AEC58 002AEC58 3F160200 */  dsra32     $2, $2, 24
    /* 1AEC5C 002AEC5C 21102202 */  addu       $2, $17, $2
    /* 1AEC60 002AEC60 1001A27F */  sq         $2, 0x110($29)
    /* 1AEC64 002AEC64 A054050C */  jal        func_00155280
    /* 1AEC68 002AEC68 00000000 */   nop
    /* 1AEC6C 002AEC6C 21100202 */  addu       $2, $16, $2
    /* 1AEC70 002AEC70 21105500 */  addu       $2, $2, $21
    /* 1AEC74 002AEC74 0001A27F */  sq         $2, 0x100($29)
    /* 1AEC78 002AEC78 A054050C */  jal        func_00155280
    /* 1AEC7C 002AEC7C 00000000 */   nop
    /* 1AEC80 002AEC80 21100202 */  addu       $2, $16, $2
    /* 1AEC84 002AEC84 21185500 */  addu       $3, $2, $21
    /* 1AEC88 002AEC88 1001A27B */  lq         $2, 0x110($29)
    /* 1AEC8C 002AEC8C FF004530 */  andi       $5, $2, 0xFF
    /* 1AEC90 002AEC90 21105E02 */  addu       $2, $18, $30
    /* 1AEC94 002AEC94 FF004630 */  andi       $6, $2, 0xFF
    /* 1AEC98 002AEC98 FF002A32 */  andi       $10, $17, 0xFF
    /* 1AEC9C 002AEC9C FF004B32 */  andi       $11, $18, 0xFF
    /* 1AECA0 002AECA0 2D208002 */  daddu      $4, $20, $0
    /* 1AECA4 002AECA4 0001A27B */  lq         $2, 0x100($29)
    /* 1AECA8 002AECA8 58004790 */  lbu        $7, 0x58($2)
    /* 1AECAC 002AECAC 02000824 */  addiu      $8, $0, 0x2
    /* 1AECB0 002AECB0 59006990 */  lbu        $9, 0x59($3)
    /* 1AECB4 002AECB4 94C00A0C */  jal        func_002b0250
    /* 1AECB8 002AECB8 00000000 */   nop
    /* 1AECBC 002AECBC 80191E00 */  sll        $3, $30, 6
    /* 1AECC0 002AECC0 2120C302 */  addu       $4, $22, $3
    /* 1AECC4 002AECC4 1001A37B */  lq         $3, 0x110($29)
    /* 1AECC8 002AECC8 80180300 */  sll        $3, $3, 2
    /* 1AECCC 002AECCC 21188300 */  addu       $3, $4, $3
    /* 1AECD0 002AECD0 480162AC */  sw         $2, 0x148($3)
    /* 1AECD4 002AECD4 A054050C */  jal        func_00155280
    /* 1AECD8 002AECD8 00000000 */   nop
    /* 1AECDC 002AECDC 21100202 */  addu       $2, $16, $2
    /* 1AECE0 002AECE0 21105500 */  addu       $2, $2, $21
    /* 1AECE4 002AECE4 59004290 */  lbu        $2, 0x59($2)
    /* 1AECE8 002AECE8 40100200 */  sll        $2, $2, 1
    /* 1AECEC 002AECEC 2110E202 */  addu       $2, $23, $2
    /* 1AECF0 002AECF0 10005E80 */  lb         $30, 0x10($2)
    /* 1AECF4 002AECF4 A054050C */  jal        func_00155280
    /* 1AECF8 002AECF8 00000000 */   nop
    /* 1AECFC 002AECFC 21100202 */  addu       $2, $16, $2
    /* 1AED00 002AED00 21105500 */  addu       $2, $2, $21
    /* 1AED04 002AED04 59004290 */  lbu        $2, 0x59($2)
    /* 1AED08 002AED08 40100200 */  sll        $2, $2, 1
    /* 1AED0C 002AED0C 2110E202 */  addu       $2, $23, $2
    /* 1AED10 002AED10 11005780 */  lb         $23, 0x11($2)
    /* 1AED14 002AED14 3C161E00 */  dsll32     $2, $30, 24
    /* 1AED18 002AED18 3F160200 */  dsra32     $2, $2, 24
    /* 1AED1C 002AED1C 21F02202 */  addu       $30, $17, $2
    /* 1AED20 002AED20 A054050C */  jal        func_00155280
    /* 1AED24 002AED24 00000000 */   nop
    /* 1AED28 002AED28 21100202 */  addu       $2, $16, $2
    /* 1AED2C 002AED2C 21105500 */  addu       $2, $2, $21
    /* 1AED30 002AED30 F000A27F */  sq         $2, 0xF0($29)
    /* 1AED34 002AED34 A054050C */  jal        func_00155280
    /* 1AED38 002AED38 00000000 */   nop
    /* 1AED3C 002AED3C 21100202 */  addu       $2, $16, $2
    /* 1AED40 002AED40 21185500 */  addu       $3, $2, $21
    /* 1AED44 002AED44 FF00C533 */  andi       $5, $30, 0xFF
    /* 1AED48 002AED48 21105702 */  addu       $2, $18, $23
    /* 1AED4C 002AED4C FF004630 */  andi       $6, $2, 0xFF
    /* 1AED50 002AED50 FF002A32 */  andi       $10, $17, 0xFF
    /* 1AED54 002AED54 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AED58 002AED58 2D208002 */  daddu      $4, $20, $0
    /* 1AED5C 002AED5C F000A27B */  lq         $2, 0xF0($29)
    /* 1AED60 002AED60 58004790 */  lbu        $7, 0x58($2)
    /* 1AED64 002AED64 03000824 */  addiu      $8, $0, 0x3
    /* 1AED68 002AED68 59006990 */  lbu        $9, 0x59($3)
    /* 1AED6C 002AED6C 94C00A0C */  jal        func_002b0250
    /* 1AED70 002AED70 00000000 */   nop
    /* 1AED74 002AED74 80191700 */  sll        $3, $23, 6
    /* 1AED78 002AED78 2120C302 */  addu       $4, $22, $3
    /* 1AED7C 002AED7C 80181E00 */  sll        $3, $30, 2
    /* 1AED80 002AED80 21188300 */  addu       $3, $4, $3
    /* 1AED84 002AED84 480162AC */  sw         $2, 0x148($3)
    /* 1AED88 002AED88 81000010 */  b          .L002AEF90
    /* 1AED8C 002AED8C 00000000 */   nop
  .L002AED90:
    /* 1AED90 002AED90 A054050C */  jal        func_00155280
    /* 1AED94 002AED94 00000000 */   nop
    /* 1AED98 002AED98 21100202 */  addu       $2, $16, $2
    /* 1AED9C 002AED9C 21105500 */  addu       $2, $2, $21
    /* 1AEDA0 002AEDA0 58004390 */  lbu        $3, 0x58($2)
    /* 1AEDA4 002AEDA4 02000224 */  addiu      $2, $0, 0x2
    /* 1AEDA8 002AEDA8 64006214 */  bne        $3, $2, .L002AEF3C
    /* 1AEDAC 002AEDAC 00000000 */   nop
    /* 1AEDB0 002AEDB0 6400173C */  lui        $23, %hi(D_0063EF40)
    /* 1AEDB4 002AEDB4 40EFF726 */  addiu      $23, $23, %lo(D_0063EF40)
    /* 1AEDB8 002AEDB8 A054050C */  jal        func_00155280
    /* 1AEDBC 002AEDBC 00000000 */   nop
    /* 1AEDC0 002AEDC0 21100202 */  addu       $2, $16, $2
    /* 1AEDC4 002AEDC4 21105500 */  addu       $2, $2, $21
    /* 1AEDC8 002AEDC8 59004290 */  lbu        $2, 0x59($2)
    /* 1AEDCC 002AEDCC 40100200 */  sll        $2, $2, 1
    /* 1AEDD0 002AEDD0 2110E202 */  addu       $2, $23, $2
    /* 1AEDD4 002AEDD4 00004280 */  lb         $2, 0x0($2)
    /* 1AEDD8 002AEDD8 E000A27F */  sq         $2, 0xE0($29)
    /* 1AEDDC 002AEDDC A054050C */  jal        func_00155280
    /* 1AEDE0 002AEDE0 00000000 */   nop
    /* 1AEDE4 002AEDE4 21100202 */  addu       $2, $16, $2
    /* 1AEDE8 002AEDE8 21105500 */  addu       $2, $2, $21
    /* 1AEDEC 002AEDEC 59004290 */  lbu        $2, 0x59($2)
    /* 1AEDF0 002AEDF0 40100200 */  sll        $2, $2, 1
    /* 1AEDF4 002AEDF4 2110E202 */  addu       $2, $23, $2
    /* 1AEDF8 002AEDF8 01005E80 */  lb         $30, 0x1($2)
    /* 1AEDFC 002AEDFC E000A27B */  lq         $2, 0xE0($29)
    /* 1AEE00 002AEE00 3C160200 */  dsll32     $2, $2, 24
    /* 1AEE04 002AEE04 3F160200 */  dsra32     $2, $2, 24
    /* 1AEE08 002AEE08 21102202 */  addu       $2, $17, $2
    /* 1AEE0C 002AEE0C D000A27F */  sq         $2, 0xD0($29)
    /* 1AEE10 002AEE10 A054050C */  jal        func_00155280
    /* 1AEE14 002AEE14 00000000 */   nop
    /* 1AEE18 002AEE18 21100202 */  addu       $2, $16, $2
    /* 1AEE1C 002AEE1C 21105500 */  addu       $2, $2, $21
    /* 1AEE20 002AEE20 C000A27F */  sq         $2, 0xC0($29)
    /* 1AEE24 002AEE24 A054050C */  jal        func_00155280
    /* 1AEE28 002AEE28 00000000 */   nop
    /* 1AEE2C 002AEE2C 21100202 */  addu       $2, $16, $2
    /* 1AEE30 002AEE30 21185500 */  addu       $3, $2, $21
    /* 1AEE34 002AEE34 D000A27B */  lq         $2, 0xD0($29)
    /* 1AEE38 002AEE38 FF004530 */  andi       $5, $2, 0xFF
    /* 1AEE3C 002AEE3C 21105E02 */  addu       $2, $18, $30
    /* 1AEE40 002AEE40 FF004630 */  andi       $6, $2, 0xFF
    /* 1AEE44 002AEE44 FF002A32 */  andi       $10, $17, 0xFF
    /* 1AEE48 002AEE48 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AEE4C 002AEE4C 2D208002 */  daddu      $4, $20, $0
    /* 1AEE50 002AEE50 C000A27B */  lq         $2, 0xC0($29)
    /* 1AEE54 002AEE54 58004790 */  lbu        $7, 0x58($2)
    /* 1AEE58 002AEE58 01000824 */  addiu      $8, $0, 0x1
    /* 1AEE5C 002AEE5C 59006990 */  lbu        $9, 0x59($3)
    /* 1AEE60 002AEE60 94C00A0C */  jal        func_002b0250
    /* 1AEE64 002AEE64 00000000 */   nop
    /* 1AEE68 002AEE68 80191E00 */  sll        $3, $30, 6
    /* 1AEE6C 002AEE6C 2120C302 */  addu       $4, $22, $3
    /* 1AEE70 002AEE70 D000A37B */  lq         $3, 0xD0($29)
    /* 1AEE74 002AEE74 80180300 */  sll        $3, $3, 2
    /* 1AEE78 002AEE78 21188300 */  addu       $3, $4, $3
    /* 1AEE7C 002AEE7C 480162AC */  sw         $2, 0x148($3)
    /* 1AEE80 002AEE80 A054050C */  jal        func_00155280
    /* 1AEE84 002AEE84 00000000 */   nop
    /* 1AEE88 002AEE88 21100202 */  addu       $2, $16, $2
    /* 1AEE8C 002AEE8C 21105500 */  addu       $2, $2, $21
    /* 1AEE90 002AEE90 59004290 */  lbu        $2, 0x59($2)
    /* 1AEE94 002AEE94 40100200 */  sll        $2, $2, 1
    /* 1AEE98 002AEE98 2110E202 */  addu       $2, $23, $2
    /* 1AEE9C 002AEE9C 08005E80 */  lb         $30, 0x8($2)
    /* 1AEEA0 002AEEA0 A054050C */  jal        func_00155280
    /* 1AEEA4 002AEEA4 00000000 */   nop
    /* 1AEEA8 002AEEA8 21100202 */  addu       $2, $16, $2
    /* 1AEEAC 002AEEAC 21105500 */  addu       $2, $2, $21
    /* 1AEEB0 002AEEB0 59004290 */  lbu        $2, 0x59($2)
    /* 1AEEB4 002AEEB4 40100200 */  sll        $2, $2, 1
    /* 1AEEB8 002AEEB8 2110E202 */  addu       $2, $23, $2
    /* 1AEEBC 002AEEBC 09005780 */  lb         $23, 0x9($2)
    /* 1AEEC0 002AEEC0 3C161E00 */  dsll32     $2, $30, 24
    /* 1AEEC4 002AEEC4 3F160200 */  dsra32     $2, $2, 24
    /* 1AEEC8 002AEEC8 21F02202 */  addu       $30, $17, $2
    /* 1AEECC 002AEECC A054050C */  jal        func_00155280
    /* 1AEED0 002AEED0 00000000 */   nop
    /* 1AEED4 002AEED4 21100202 */  addu       $2, $16, $2
    /* 1AEED8 002AEED8 21105500 */  addu       $2, $2, $21
    /* 1AEEDC 002AEEDC B000A27F */  sq         $2, 0xB0($29)
    /* 1AEEE0 002AEEE0 A054050C */  jal        func_00155280
    /* 1AEEE4 002AEEE4 00000000 */   nop
    /* 1AEEE8 002AEEE8 21100202 */  addu       $2, $16, $2
    /* 1AEEEC 002AEEEC 21185500 */  addu       $3, $2, $21
    /* 1AEEF0 002AEEF0 FF00C533 */  andi       $5, $30, 0xFF
    /* 1AEEF4 002AEEF4 21105702 */  addu       $2, $18, $23
    /* 1AEEF8 002AEEF8 FF004630 */  andi       $6, $2, 0xFF
    /* 1AEEFC 002AEEFC FF002A32 */  andi       $10, $17, 0xFF
    /* 1AEF00 002AEF00 FF004B32 */  andi       $11, $18, 0xFF
    /* 1AEF04 002AEF04 2D208002 */  daddu      $4, $20, $0
    /* 1AEF08 002AEF08 B000A27B */  lq         $2, 0xB0($29)
    /* 1AEF0C 002AEF0C 58004790 */  lbu        $7, 0x58($2)
    /* 1AEF10 002AEF10 02000824 */  addiu      $8, $0, 0x2
    /* 1AEF14 002AEF14 59006990 */  lbu        $9, 0x59($3)
    /* 1AEF18 002AEF18 94C00A0C */  jal        func_002b0250
    /* 1AEF1C 002AEF1C 00000000 */   nop
    /* 1AEF20 002AEF20 80191700 */  sll        $3, $23, 6
    /* 1AEF24 002AEF24 2120C302 */  addu       $4, $22, $3
    /* 1AEF28 002AEF28 80181E00 */  sll        $3, $30, 2
    /* 1AEF2C 002AEF2C 21188300 */  addu       $3, $4, $3
    /* 1AEF30 002AEF30 480162AC */  sw         $2, 0x148($3)
    /* 1AEF34 002AEF34 16000010 */  b          .L002AEF90
    /* 1AEF38 002AEF38 00000000 */   nop
  .L002AEF3C:
    /* 1AEF3C 002AEF3C A054050C */  jal        func_00155280
    /* 1AEF40 002AEF40 00000000 */   nop
    /* 1AEF44 002AEF44 21100202 */  addu       $2, $16, $2
    /* 1AEF48 002AEF48 21B85500 */  addu       $23, $2, $21
    /* 1AEF4C 002AEF4C A054050C */  jal        func_00155280
    /* 1AEF50 002AEF50 00000000 */   nop
    /* 1AEF54 002AEF54 21100202 */  addu       $2, $16, $2
    /* 1AEF58 002AEF58 21105500 */  addu       $2, $2, $21
    /* 1AEF5C 002AEF5C FF002532 */  andi       $5, $17, 0xFF
    /* 1AEF60 002AEF60 FF004632 */  andi       $6, $18, 0xFF
    /* 1AEF64 002AEF64 2D208002 */  daddu      $4, $20, $0
    /* 1AEF68 002AEF68 5800E792 */  lbu        $7, 0x58($23)
    /* 1AEF6C 002AEF6C 01000824 */  addiu      $8, $0, 0x1
    /* 1AEF70 002AEF70 59004990 */  lbu        $9, 0x59($2)
    /* 1AEF74 002AEF74 2D50A000 */  daddu      $10, $5, $0
    /* 1AEF78 002AEF78 2D58C000 */  daddu      $11, $6, $0
    /* 1AEF7C 002AEF7C 94C00A0C */  jal        func_002b0250
    /* 1AEF80 002AEF80 00000000 */   nop
    /* 1AEF84 002AEF84 80181100 */  sll        $3, $17, 2
    /* 1AEF88 002AEF88 2118C302 */  addu       $3, $22, $3
    /* 1AEF8C 002AEF8C 480162AC */  sw         $2, 0x148($3)
  .L002AEF90:
    /* 1AEF90 002AEF90 01003126 */  addiu      $17, $17, 0x1
  .L002AEF94:
    /* 1AEF94 002AEF94 1000222A */  slti       $2, $17, 0x10
    /* 1AEF98 002AEF98 F8FD4014 */  bnez       $2, .L002AE77C
    /* 1AEF9C 002AEF9C 00000000 */   nop
    /* 1AEFA0 002AEFA0 01005226 */  addiu      $18, $18, 0x1
  .L002AEFA4:
    /* 1AEFA4 002AEFA4 1800422A */  slti       $2, $18, 0x18
    /* 1AEFA8 002AEFA8 EEFD4014 */  bnez       $2, .L002AE764
    /* 1AEFAC 002AEFAC 00000000 */   nop
    /* 1AEFB0 002AEFB0 8841023C */  lui        $2, (0x41880000 >> 16)
    /* 1AEFB4 002AEFB4 00608244 */  mtc1       $2, $f12
    /* 1AEFB8 002AEFB8 1643023C */  lui        $2, (0x43160000 >> 16)
    /* 1AEFBC 002AEFBC 00688244 */  mtc1       $2, $f13
    /* 1AEFC0 002AEFC0 E001A427 */  addiu      $4, $29, 0x1E0
    /* 1AEFC4 002AEFC4 5CCA0A0C */  jal        func_002b2970
    /* 1AEFC8 002AEFC8 00000000 */   nop
    /* 1AEFCC 002AEFCC 0C02A427 */  addiu      $4, $29, 0x20C
    /* 1AEFD0 002AEFD0 80000524 */  addiu      $5, $0, 0x80
    /* 1AEFD4 002AEFD4 2D30A000 */  daddu      $6, $5, $0
    /* 1AEFD8 002AEFD8 2D38A000 */  daddu      $7, $5, $0
    /* 1AEFDC 002AEFDC 2D400000 */  daddu      $8, $0, $0
    /* 1AEFE0 002AEFE0 98CA0A0C */  jal        func_002b2a60
    /* 1AEFE4 002AEFE4 00000000 */   nop
    /* 1AEFE8 002AEFE8 7043023C */  lui        $2, (0x43700000 >> 16)
    /* 1AEFEC 002AEFEC 00608244 */  mtc1       $2, $f12
    /* 1AEFF0 002AEFF0 F042023C */  lui        $2, (0x42F00000 >> 16)
    /* 1AEFF4 002AEFF4 00688244 */  mtc1       $2, $f13
    /* 1AEFF8 002AEFF8 2D208002 */  daddu      $4, $20, $0
    /* 1AEFFC 002AEFFC E001A5DF */  ld         $5, 0x1E0($29)
    /* 1AF000 002AF000 0C02A68F */  lw         $6, 0x20C($29)
    /* 1AF004 002AF004 0CCA0A0C */  jal        func_002b2830
    /* 1AF008 002AF008 00000000 */   nop
    /* 1AF00C 002AF00C BC0062AE */  sw         $2, 0xBC($19)
    /* 1AF010 002AF010 1443023C */  lui        $2, (0x43140000 >> 16)
    /* 1AF014 002AF014 00608244 */  mtc1       $2, $f12
    /* 1AF018 002AF018 7943023C */  lui        $2, (0x43790000 >> 16)
    /* 1AF01C 002AF01C 00688244 */  mtc1       $2, $f13
    /* 1AF020 002AF020 D801A427 */  addiu      $4, $29, 0x1D8
    /* 1AF024 002AF024 5CCA0A0C */  jal        func_002b2970
    /* 1AF028 002AF028 00000000 */   nop
    /* 1AF02C 002AF02C 0802A427 */  addiu      $4, $29, 0x208
    /* 1AF030 002AF030 80000524 */  addiu      $5, $0, 0x80
    /* 1AF034 002AF034 2D300000 */  daddu      $6, $0, $0
    /* 1AF038 002AF038 2D380000 */  daddu      $7, $0, $0
    /* 1AF03C 002AF03C 2D400000 */  daddu      $8, $0, $0
    /* 1AF040 002AF040 98CA0A0C */  jal        func_002b2a60
    /* 1AF044 002AF044 00000000 */   nop
    /* 1AF048 002AF048 1643023C */  lui        $2, (0x43160000 >> 16)
    /* 1AF04C 002AF04C 00608244 */  mtc1       $2, $f12
    /* 1AF050 002AF050 6743023C */  lui        $2, (0x43670000 >> 16)
    /* 1AF054 002AF054 00688244 */  mtc1       $2, $f13
    /* 1AF058 002AF058 2D208002 */  daddu      $4, $20, $0
    /* 1AF05C 002AF05C D801A5DF */  ld         $5, 0x1D8($29)
    /* 1AF060 002AF060 0802A68F */  lw         $6, 0x208($29)
    /* 1AF064 002AF064 0CCA0A0C */  jal        func_002b2830
    /* 1AF068 002AF068 00000000 */   nop
    /* 1AF06C 002AF06C C00062AE */  sw         $2, 0xC0($19)
    /* 1AF070 002AF070 00608044 */  mtc1       $0, $f12
    /* 1AF074 002AF074 8B010224 */  addiu      $2, $0, 0x18B
    /* 1AF078 002AF078 00008244 */  mtc1       $2, $f0
    /* 1AF07C 002AF07C 00000000 */  nop
    /* 1AF080 002AF080 60038046 */  cvt.s.w    $f13, $f0
    /* 1AF084 002AF084 D001A427 */  addiu      $4, $29, 0x1D0
    /* 1AF088 002AF088 5CCA0A0C */  jal        func_002b2970
    /* 1AF08C 002AF08C 00000000 */   nop
    /* 1AF090 002AF090 0402A427 */  addiu      $4, $29, 0x204
    /* 1AF094 002AF094 2D280000 */  daddu      $5, $0, $0
    /* 1AF098 002AF098 80000624 */  addiu      $6, $0, 0x80
    /* 1AF09C 002AF09C 2D380000 */  daddu      $7, $0, $0
    /* 1AF0A0 002AF0A0 2D400000 */  daddu      $8, $0, $0
    /* 1AF0A4 002AF0A4 98CA0A0C */  jal        func_002b2a60
    /* 1AF0A8 002AF0A8 00000000 */   nop
    /* 1AF0AC 002AF0AC 1743023C */  lui        $2, (0x43170000 >> 16)
    /* 1AF0B0 002AF0B0 00608244 */  mtc1       $2, $f12
    /* 1AF0B4 002AF0B4 F242023C */  lui        $2, (0x42F20000 >> 16)
    /* 1AF0B8 002AF0B8 00688244 */  mtc1       $2, $f13
    /* 1AF0BC 002AF0BC 2D208002 */  daddu      $4, $20, $0
    /* 1AF0C0 002AF0C0 D001A5DF */  ld         $5, 0x1D0($29)
    /* 1AF0C4 002AF0C4 0402A68F */  lw         $6, 0x204($29)
    /* 1AF0C8 002AF0C8 0CCA0A0C */  jal        func_002b2830
    /* 1AF0CC 002AF0CC 00000000 */   nop
    /* 1AF0D0 002AF0D0 C40062AE */  sw         $2, 0xC4($19)
    /* 1AF0D4 002AF0D4 00608044 */  mtc1       $0, $f12
    /* 1AF0D8 002AF0D8 1643023C */  lui        $2, (0x43160000 >> 16)
    /* 1AF0DC 002AF0DC 00688244 */  mtc1       $2, $f13
    /* 1AF0E0 002AF0E0 C801A427 */  addiu      $4, $29, 0x1C8
    /* 1AF0E4 002AF0E4 5CCA0A0C */  jal        func_002b2970
    /* 1AF0E8 002AF0E8 00000000 */   nop
    /* 1AF0EC 002AF0EC 0002A427 */  addiu      $4, $29, 0x200
    /* 1AF0F0 002AF0F0 2D280000 */  daddu      $5, $0, $0
    /* 1AF0F4 002AF0F4 2D300000 */  daddu      $6, $0, $0
    /* 1AF0F8 002AF0F8 80000724 */  addiu      $7, $0, 0x80
    /* 1AF0FC 002AF0FC 2D400000 */  daddu      $8, $0, $0
    /* 1AF100 002AF100 98CA0A0C */  jal        func_002b2a60
    /* 1AF104 002AF104 00000000 */   nop
    /* 1AF108 002AF108 B841023C */  lui        $2, (0x41B80000 >> 16)
    /* 1AF10C 002AF10C 00608244 */  mtc1       $2, $f12
    /* 1AF110 002AF110 8B010224 */  addiu      $2, $0, 0x18B
    /* 1AF114 002AF114 00008244 */  mtc1       $2, $f0
    /* 1AF118 002AF118 00000000 */  nop
    /* 1AF11C 002AF11C 60038046 */  cvt.s.w    $f13, $f0
    /* 1AF120 002AF120 2D208002 */  daddu      $4, $20, $0
    /* 1AF124 002AF124 C801A5DF */  ld         $5, 0x1C8($29)
    /* 1AF128 002AF128 0002A68F */  lw         $6, 0x200($29)
    /* 1AF12C 002AF12C 0CCA0A0C */  jal        func_002b2830
    /* 1AF130 002AF130 00000000 */   nop
    /* 1AF134 002AF134 C80062AE */  sw         $2, 0xC8($19)
    /* 1AF138 002AF138 2D208002 */  daddu      $4, $20, $0
    /* 1AF13C 002AF13C 64CE0A0C */  jal        func_002b3990
    /* 1AF140 002AF140 00000000 */   nop
    /* 1AF144 002AF144 CC0062AE */  sw         $2, 0xCC($19)
    /* 1AF148 002AF148 2D800000 */  daddu      $16, $0, $0
    /* 1AF14C 002AF14C 1B000010 */  b          .L002AF1BC
    /* 1AF150 002AF150 00000000 */   nop
  .L002AF154:
    /* 1AF154 002AF154 2D200000 */  daddu      $4, $0, $0
    /* 1AF158 002AF158 50070224 */  addiu      $2, $0, 0x750
    /* 1AF15C 002AF15C 18180202 */  mult       $3, $16, $2
    /* 1AF160 002AF160 7F00023C */  lui        $2, %hi(D_007E8C00)
    /* 1AF164 002AF164 008C4224 */  addiu      $2, $2, %lo(D_007E8C00)
    /* 1AF168 002AF168 21184300 */  addu       $3, $2, $3
    /* 1AF16C 002AF16C 4800628C */  lw         $2, 0x48($3)
    /* 1AF170 002AF170 05004010 */  beqz       $2, .L002AF188
    /* 1AF174 002AF174 00000000 */   nop
    /* 1AF178 002AF178 5400628C */  lw         $2, 0x54($3)
    /* 1AF17C 002AF17C 02004010 */  beqz       $2, .L002AF188
    /* 1AF180 002AF180 00000000 */   nop
    /* 1AF184 002AF184 01000424 */  addiu      $4, $0, 0x1
  .L002AF188:
    /* 1AF188 002AF188 2B180400 */  sltu       $3, $0, $4
    /* 1AF18C 002AF18C 01000224 */  addiu      $2, $0, 0x1
    /* 1AF190 002AF190 09006214 */  bne        $3, $2, .L002AF1B8
    /* 1AF194 002AF194 00000000 */   nop
    /* 1AF198 002AF198 3C2E1000 */  dsll32     $5, $16, 24
    /* 1AF19C 002AF19C 3F2E0500 */  dsra32     $5, $5, 24
    /* 1AF1A0 002AF1A0 2D208002 */  daddu      $4, $20, $0
    /* 1AF1A4 002AF1A4 84D20A0C */  jal        func_002b4a10
    /* 1AF1A8 002AF1A8 00000000 */   nop
    /* 1AF1AC 002AF1AC 80181000 */  sll        $3, $16, 2
    /* 1AF1B0 002AF1B0 21186302 */  addu       $3, $19, $3
    /* 1AF1B4 002AF1B4 D80062AC */  sw         $2, 0xD8($3)
  .L002AF1B8:
    /* 1AF1B8 002AF1B8 01001026 */  addiu      $16, $16, 0x1
  .L002AF1BC:
    /* 1AF1BC 002AF1BC 0F00022A */  slti       $2, $16, 0xF
    /* 1AF1C0 002AF1C0 E4FF4014 */  bnez       $2, .L002AF154
    /* 1AF1C4 002AF1C4 00000000 */   nop
    /* 1AF1C8 002AF1C8 54B5848F */  lw         $4, -0x4AAC($28)
    /* 1AF1CC 002AF1CC 12000524 */  addiu      $5, $0, 0x12
    /* 1AF1D0 002AF1D0 80B4110C */  jal        func_0046d200
    /* 1AF1D4 002AF1D4 00000000 */   nop
    /* 1AF1D8 002AF1D8 2D904000 */  daddu      $18, $2, $0
    /* 1AF1DC 002AF1DC 2D800000 */  daddu      $16, $0, $0
    /* 1AF1E0 002AF1E0 44000010 */  b          .L002AF2F4
    /* 1AF1E4 002AF1E4 00000000 */   nop
  .L002AF1E8:
    /* 1AF1E8 002AF1E8 00111000 */  sll        $2, $16, 4
    /* 1AF1EC 002AF1EC 23185000 */  subu       $3, $2, $16
    /* 1AF1F0 002AF1F0 80100300 */  sll        $2, $3, 2
    /* 1AF1F4 002AF1F4 23104300 */  subu       $2, $2, $3
    /* 1AF1F8 002AF1F8 C0180200 */  sll        $3, $2, 3
    /* 1AF1FC 002AF1FC 7F00023C */  lui        $2, %hi(D_007E80A0)
    /* 1AF200 002AF200 A0804224 */  addiu      $2, $2, %lo(D_007E80A0)
    /* 1AF204 002AF204 21184300 */  addu       $3, $2, $3
    /* 1AF208 002AF208 0000628C */  lw         $2, 0x0($3)
    /* 1AF20C 002AF20C 38004010 */  beqz       $2, .L002AF2F0
    /* 1AF210 002AF210 00000000 */   nop
    /* 1AF214 002AF214 50017124 */  addiu      $17, $3, 0x150
    /* 1AF218 002AF218 2D202002 */  daddu      $4, $17, $0
    /* 1AF21C 002AF21C 70C40A0C */  jal        func_002b11c0
    /* 1AF220 002AF220 00000000 */   nop
    /* 1AF224 002AF224 00008244 */  mtc1       $2, $f0
    /* 1AF228 002AF228 00000000 */  nop
    /* 1AF22C 002AF22C A0008046 */  cvt.s.w    $f2, $f0
    /* 1AF230 002AF230 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1AF234 002AF234 00608244 */  mtc1       $2, $f12
    /* 1AF238 002AF238 2C43023C */  lui        $2, (0x432C0000 >> 16)
    /* 1AF23C 002AF23C 00088244 */  mtc1       $2, $f1
    /* 1AF240 002AF240 00008044 */  mtc1       $0, $f0
    /* 1AF244 002AF244 00000000 */  nop
    /* 1AF248 002AF248 18000146 */  adda.s     $f0, $f1
    /* 1AF24C 002AF24C 1C650246 */  madd.s     $f20, $f12, $f2
    /* 1AF250 002AF250 2D202002 */  daddu      $4, $17, $0
    /* 1AF254 002AF254 F8C40A0C */  jal        func_002b13e0
    /* 1AF258 002AF258 00000000 */   nop
    /* 1AF25C 002AF25C 41A00046 */  sub.s      $f1, $f20, $f0
    /* 1AF260 002AF260 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1AF264 002AF264 00008244 */  mtc1       $2, $f0
    /* 1AF268 002AF268 00000000 */  nop
    /* 1AF26C 002AF26C 01080046 */  sub.s      $f0, $f1, $f0
    /* 1AF270 002AF270 F801A0E7 */  swc1       $f0, 0x1F8($29)
    /* 1AF274 002AF274 2D202002 */  daddu      $4, $17, $0
    /* 1AF278 002AF278 84C40A0C */  jal        func_002b1210
    /* 1AF27C 002AF27C 00000000 */   nop
    /* 1AF280 002AF280 00008244 */  mtc1       $2, $f0
    /* 1AF284 002AF284 00000000 */  nop
    /* 1AF288 002AF288 A0008046 */  cvt.s.w    $f2, $f0
    /* 1AF28C 002AF28C 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1AF290 002AF290 00608244 */  mtc1       $2, $f12
    /* 1AF294 002AF294 1041023C */  lui        $2, (0x41100000 >> 16)
    /* 1AF298 002AF298 00088244 */  mtc1       $2, $f1
    /* 1AF29C 002AF29C 00008044 */  mtc1       $0, $f0
    /* 1AF2A0 002AF2A0 00000000 */  nop
    /* 1AF2A4 002AF2A4 18000146 */  adda.s     $f0, $f1
    /* 1AF2A8 002AF2A8 1C650246 */  madd.s     $f20, $f12, $f2
    /* 1AF2AC 002AF2AC 2D202002 */  daddu      $4, $17, $0
    /* 1AF2B0 002AF2B0 20C50A0C */  jal        func_002b1480
    /* 1AF2B4 002AF2B4 00000000 */   nop
    /* 1AF2B8 002AF2B8 41A00046 */  sub.s      $f1, $f20, $f0
    /* 1AF2BC 002AF2BC 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1AF2C0 002AF2C0 00008244 */  mtc1       $2, $f0
    /* 1AF2C4 002AF2C4 00000000 */  nop
    /* 1AF2C8 002AF2C8 01080046 */  sub.s      $f0, $f1, $f0
    /* 1AF2CC 002AF2CC FC01A0E7 */  swc1       $f0, 0x1FC($29)
    /* 1AF2D0 002AF2D0 FF000632 */  andi       $6, $16, 0xFF
    /* 1AF2D4 002AF2D4 2D208002 */  daddu      $4, $20, $0
    /* 1AF2D8 002AF2D8 F801A5DF */  ld         $5, 0x1F8($29)
    /* 1AF2DC 002AF2DC F8D30A0C */  jal        func_002b4fe0
    /* 1AF2E0 002AF2E0 00000000 */   nop
    /* 1AF2E4 002AF2E4 80181000 */  sll        $3, $16, 2
    /* 1AF2E8 002AF2E8 21186302 */  addu       $3, $19, $3
    /* 1AF2EC 002AF2EC 140162AC */  sw         $2, 0x114($3)
  .L002AF2F0:
    /* 1AF2F0 002AF2F0 01001026 */  addiu      $16, $16, 0x1
  .L002AF2F4:
    /* 1AF2F4 002AF2F4 0800022A */  slti       $2, $16, 0x8
    /* 1AF2F8 002AF2F8 BBFF4014 */  bnez       $2, .L002AF1E8
    /* 1AF2FC 002AF2FC 00000000 */   nop
    /* 1AF300 002AF300 2D204002 */  daddu      $4, $18, $0
    /* 1AF304 002AF304 A0B4110C */  jal        func_0046d280
    /* 1AF308 002AF308 00000000 */   nop
    /* 1AF30C 002AF30C 2D208002 */  daddu      $4, $20, $0
    /* 1AF310 002AF310 0C000524 */  addiu      $5, $0, 0xC
    /* 1AF314 002AF314 54B5868F */  lw         $6, -0x4AAC($28)
    /* 1AF318 002AF318 64D90A0C */  jal        func_002b6590
    /* 1AF31C 002AF31C 00000000 */   nop
    /* 1AF320 002AF320 480762AE */  sw         $2, 0x748($19)
    /* 1AF324 002AF324 2D208002 */  daddu      $4, $20, $0
    /* 1AF328 002AF328 0D000524 */  addiu      $5, $0, 0xD
    /* 1AF32C 002AF32C 54B5868F */  lw         $6, -0x4AAC($28)
    /* 1AF330 002AF330 64D90A0C */  jal        func_002b6590
    /* 1AF334 002AF334 00000000 */   nop
    /* 1AF338 002AF338 4C0762AE */  sw         $2, 0x74C($19)
    /* 1AF33C 002AF33C 03000424 */  addiu      $4, $0, 0x3
    /* 1AF340 002AF340 AC14050C */  jal        func_001452b0
    /* 1AF344 002AF344 00000000 */   nop
    /* 1AF348 002AF348 2D884000 */  daddu      $17, $2, $0
    /* 1AF34C 002AF34C 2D800000 */  daddu      $16, $0, $0
    /* 1AF350 002AF350 D40060AE */  sw         $0, 0xD4($19)
    /* 1AF354 002AF354 D00060AE */  sw         $0, 0xD0($19)
    /* 1AF358 002AF358 0F000010 */  b          .L002AF398
    /* 1AF35C 002AF35C 00000000 */   nop
  .L002AF360:
    /* 1AF360 002AF360 6401248E */  lw         $4, 0x164($17)
    /* 1AF364 002AF364 BCE8110C */  jal        func_0047a2f0
    /* 1AF368 002AF368 00000000 */   nop
    /* 1AF36C 002AF36C 3C2E1000 */  dsll32     $5, $16, 24
    /* 1AF370 002AF370 3F2E0500 */  dsra32     $5, $5, 24
    /* 1AF374 002AF374 2D208002 */  daddu      $4, $20, $0
    /* 1AF378 002AF378 30004624 */  addiu      $6, $2, 0x30
    /* 1AF37C 002AF37C 50D00A0C */  jal        func_002b4140
    /* 1AF380 002AF380 00000000 */   nop
    /* 1AF384 002AF384 80181000 */  sll        $3, $16, 2
    /* 1AF388 002AF388 21186302 */  addu       $3, $19, $3
    /* 1AF38C 002AF38C D00062AC */  sw         $2, 0xD0($3)
    /* 1AF390 002AF390 01001026 */  addiu      $16, $16, 0x1
    /* 1AF394 002AF394 3801318E */  lw         $17, 0x138($17)
  .L002AF398:
    /* 1AF398 002AF398 F1FF2016 */  bnez       $17, .L002AF360
    /* 1AF39C 002AF39C 00000000 */   nop
    /* 1AF3A0 002AF3A0 2D108002 */  daddu      $2, $20, $0
    /* 1AF3A4 002AF3A4 A000BFDF */  ld         $31, 0xA0($29)
    /* 1AF3A8 002AF3A8 9000BE7B */  lq         $30, 0x90($29)
    /* 1AF3AC 002AF3AC 8000B77B */  lq         $23, 0x80($29)
    /* 1AF3B0 002AF3B0 7000B67B */  lq         $22, 0x70($29)
    /* 1AF3B4 002AF3B4 6000B57B */  lq         $21, 0x60($29)
    /* 1AF3B8 002AF3B8 5000B47B */  lq         $20, 0x50($29)
    /* 1AF3BC 002AF3BC 4000B37B */  lq         $19, 0x40($29)
    /* 1AF3C0 002AF3C0 3000B27B */  lq         $18, 0x30($29)
    /* 1AF3C4 002AF3C4 2000B17B */  lq         $17, 0x20($29)
    /* 1AF3C8 002AF3C8 1000B07B */  lq         $16, 0x10($29)
    /* 1AF3CC 002AF3CC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1AF3D0 002AF3D0 1002BD27 */  addiu      $29, $29, 0x210
    /* 1AF3D4 002AF3D4 0800E003 */  jr         $31
    /* 1AF3D8 002AF3D8 00000000 */   nop
    /* 1AF3DC 002AF3DC 00000000 */  nop
.size func_002ae630, 0xdb0
