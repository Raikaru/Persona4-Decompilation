.section .text
.set noat
.set noreorder
glabel func_002ca830
    /* 1CA830 002CA830 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1CA834 002CA834 2000BFFF */  sd         $31, 0x20($29)
    /* 1CA838 002CA838 1000B17F */  sq         $17, 0x10($29)
    /* 1CA83C 002CA83C 0000B07F */  sq         $16, 0x0($29)
    /* 1CA840 002CA840 2D888000 */  daddu      $17, $4, $0
    /* 1CA844 002CA844 6400043C */  lui        $4, %hi(D_0063FAC0)
    /* 1CA848 002CA848 C0FA8424 */  addiu      $4, $4, %lo(D_0063FAC0)
    /* 1CA84C 002CA84C 470C0524 */  addiu      $5, $0, 0xC47
    /* 1CA850 002CA850 A43A110C */  jal        func_0044ea90
    /* 1CA854 002CA854 00000000 */   nop
    /* 1CA858 002CA858 01000424 */  addiu      $4, $0, 0x1
    /* 1CA85C 002CA85C 74110524 */  addiu      $5, $0, 0x1174
    /* 1CA860 002CA860 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1CA864 002CA864 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1CA868 002CA868 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1CA86C 002CA86C 09F84000 */  jalr       $2
    /* 1CA870 002CA870 00000000 */   nop
    /* 1CA874 002CA874 2D804000 */  daddu      $16, $2, $0
    /* 1CA878 002CA878 2D202002 */  daddu      $4, $17, $0
    /* 1CA87C 002CA87C 6400053C */  lui        $5, %hi(D_0063FB30)
    /* 1CA880 002CA880 30FBA524 */  addiu      $5, $5, %lo(D_0063FB30)
    /* 1CA884 002CA884 0F000624 */  addiu      $6, $0, 0xF
    /* 1CA888 002CA888 2D380000 */  daddu      $7, $0, $0
    /* 1CA88C 002CA88C 2D400000 */  daddu      $8, $0, $0
    /* 1CA890 002CA890 2C00093C */  lui        $9, %hi(func_002be530)
    /* 1CA894 002CA894 30E52925 */  addiu      $9, $9, %lo(func_002be530)
    /* 1CA898 002CA898 2D000A3C */  lui        $10, %hi(func_002ca770)
    /* 1CA89C 002CA89C 70A74A25 */  addiu      $10, $10, %lo(func_002ca770)
    /* 1CA8A0 002CA8A0 2D580002 */  daddu      $11, $16, $0
    /* 1CA8A4 002CA8A4 F047110C */  jal        func_00451fc0
    /* 1CA8A8 002CA8A8 00000000 */   nop
    /* 1CA8AC 002CA8AC 2D884000 */  daddu      $17, $2, $0
    /* 1CA8B0 002CA8B0 09000224 */  addiu      $2, $0, 0x9
    /* 1CA8B4 002CA8B4 000002A2 */  sb         $2, 0x0($16)
    /* 1CA8B8 002CA8B8 7043023C */  lui        $2, (0x43700000 >> 16)
    /* 1CA8BC 002CA8BC 00608244 */  mtc1       $2, $f12
    /* 1CA8C0 002CA8C0 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 1CA8C4 002CA8C4 00688244 */  mtc1       $2, $f13
    /* 1CA8C8 002CA8C8 4800A427 */  addiu      $4, $29, 0x48
    /* 1CA8CC 002CA8CC 5CCA0A0C */  jal        func_002b2970
    /* 1CA8D0 002CA8D0 00000000 */   nop
    /* 1CA8D4 002CA8D4 2D202002 */  daddu      $4, $17, $0
    /* 1CA8D8 002CA8D8 4800A5DF */  ld         $5, 0x48($29)
    /* 1CA8DC 002CA8DC 24D70A0C */  jal        func_002b5c90
    /* 1CA8E0 002CA8E0 00000000 */   nop
    /* 1CA8E4 002CA8E4 280C02AE */  sw         $2, 0xC28($16)
    /* 1CA8E8 002CA8E8 240C00A2 */  sb         $0, 0xC24($16)
    /* 1CA8EC 002CA8EC 4842023C */  lui        $2, (0x42480000 >> 16)
    /* 1CA8F0 002CA8F0 00608244 */  mtc1       $2, $f12
    /* 1CA8F4 002CA8F4 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1CA8F8 002CA8F8 00688244 */  mtc1       $2, $f13
    /* 1CA8FC 002CA8FC 4000A427 */  addiu      $4, $29, 0x40
    /* 1CA900 002CA900 5CCA0A0C */  jal        func_002b2970
    /* 1CA904 002CA904 00000000 */   nop
    /* 1CA908 002CA908 2D202002 */  daddu      $4, $17, $0
    /* 1CA90C 002CA90C 4000A5DF */  ld         $5, 0x40($29)
    /* 1CA910 002CA910 24D70A0C */  jal        func_002b5c90
    /* 1CA914 002CA914 00000000 */   nop
    /* 1CA918 002CA918 2C0C02AE */  sw         $2, 0xC2C($16)
    /* 1CA91C 002CA91C 4842023C */  lui        $2, (0x42480000 >> 16)
    /* 1CA920 002CA920 00608244 */  mtc1       $2, $f12
    /* 1CA924 002CA924 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1CA928 002CA928 00688244 */  mtc1       $2, $f13
    /* 1CA92C 002CA92C 3800A427 */  addiu      $4, $29, 0x38
    /* 1CA930 002CA930 5CCA0A0C */  jal        func_002b2970
    /* 1CA934 002CA934 00000000 */   nop
    /* 1CA938 002CA938 2D202002 */  daddu      $4, $17, $0
    /* 1CA93C 002CA93C 3800A5DF */  ld         $5, 0x38($29)
    /* 1CA940 002CA940 24D70A0C */  jal        func_002b5c90
    /* 1CA944 002CA944 00000000 */   nop
    /* 1CA948 002CA948 300C02AE */  sw         $2, 0xC30($16)
    /* 1CA94C 002CA94C 4842023C */  lui        $2, (0x42480000 >> 16)
    /* 1CA950 002CA950 00608244 */  mtc1       $2, $f12
    /* 1CA954 002CA954 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1CA958 002CA958 00688244 */  mtc1       $2, $f13
    /* 1CA95C 002CA95C 3000A427 */  addiu      $4, $29, 0x30
    /* 1CA960 002CA960 5CCA0A0C */  jal        func_002b2970
    /* 1CA964 002CA964 00000000 */   nop
    /* 1CA968 002CA968 2D202002 */  daddu      $4, $17, $0
    /* 1CA96C 002CA96C 3000A5DF */  ld         $5, 0x30($29)
    /* 1CA970 002CA970 24D70A0C */  jal        func_002b5c90
    /* 1CA974 002CA974 00000000 */   nop
    /* 1CA978 002CA978 340C02AE */  sw         $2, 0xC34($16)
    /* 1CA97C 002CA97C 280F00AE */  sw         $0, 0xF28($16)
    /* 1CA980 002CA980 300F00A2 */  sb         $0, 0xF30($16)
    /* 1CA984 002CA984 2D202002 */  daddu      $4, $17, $0
    /* 1CA988 002CA988 0400053C */  lui        $5, (0x40000 >> 16)
    /* 1CA98C 002CA98C 2D300000 */  daddu      $6, $0, $0
    /* 1CA990 002CA990 04000724 */  addiu      $7, $0, 0x4
    /* 1CA994 002CA994 2D400000 */  daddu      $8, $0, $0
    /* 1CA998 002CA998 64890B0C */  jal        func_002e2590
    /* 1CA99C 002CA99C 00000000 */   nop
    /* 1CA9A0 002CA9A0 180F02AE */  sw         $2, 0xF18($16)
    /* 1CA9A4 002CA9A4 2D202002 */  daddu      $4, $17, $0
    /* 1CA9A8 002CA9A8 FFFF0534 */  ori        $5, $0, 0xFFFF
    /* 1CA9AC 002CA9AC E01F0624 */  addiu      $6, $0, 0x1FE0
    /* 1CA9B0 002CA9B0 01000724 */  addiu      $7, $0, 0x1
    /* 1CA9B4 002CA9B4 2D400000 */  daddu      $8, $0, $0
    /* 1CA9B8 002CA9B8 64890B0C */  jal        func_002e2590
    /* 1CA9BC 002CA9BC 00000000 */   nop
    /* 1CA9C0 002CA9C0 1C0F02AE */  sw         $2, 0xF1C($16)
    /* 1CA9C4 002CA9C4 2D202002 */  daddu      $4, $17, $0
    /* 1CA9C8 002CA9C8 0100053C */  lui        $5, (0x10000 >> 16)
    /* 1CA9CC 002CA9CC 2D300000 */  daddu      $6, $0, $0
    /* 1CA9D0 002CA9D0 01000724 */  addiu      $7, $0, 0x1
    /* 1CA9D4 002CA9D4 2D400000 */  daddu      $8, $0, $0
    /* 1CA9D8 002CA9D8 64890B0C */  jal        func_002e2590
    /* 1CA9DC 002CA9DC 00000000 */   nop
    /* 1CA9E0 002CA9E0 200F02AE */  sw         $2, 0xF20($16)
    /* 1CA9E4 002CA9E4 2D102002 */  daddu      $2, $17, $0
    /* 1CA9E8 002CA9E8 2000BFDF */  ld         $31, 0x20($29)
    /* 1CA9EC 002CA9EC 1000B17B */  lq         $17, 0x10($29)
    /* 1CA9F0 002CA9F0 0000B07B */  lq         $16, 0x0($29)
    /* 1CA9F4 002CA9F4 5000BD27 */  addiu      $29, $29, 0x50
    /* 1CA9F8 002CA9F8 0800E003 */  jr         $31
    /* 1CA9FC 002CA9FC 00000000 */   nop
.size func_002ca830, 0x1d0
