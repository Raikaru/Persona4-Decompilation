.section .text
.set noat
.set noreorder
glabel func_0014ec50
    /* 4EC50 0014EC50 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 4EC54 0014EC54 4000BFFF */  sd         $31, 0x40($29)
    /* 4EC58 0014EC58 3000B37F */  sq         $19, 0x30($29)
    /* 4EC5C 0014EC5C 2000B27F */  sq         $18, 0x20($29)
    /* 4EC60 0014EC60 1000B17F */  sq         $17, 0x10($29)
    /* 4EC64 0014EC64 0000B07F */  sq         $16, 0x0($29)
    /* 4EC68 0014EC68 2D908000 */  daddu      $18, $4, $0
    /* 4EC6C 0014EC6C 2D98A000 */  daddu      $19, $5, $0
    /* 4EC70 0014EC70 E09D8427 */  addiu      $4, $28, -0x6220
    /* 4EC74 0014EC74 DF020524 */  addiu      $5, $0, 0x2DF
    /* 4EC78 0014EC78 A43A110C */  jal        func_0044ea90
    /* 4EC7C 0014EC7C 00000000 */   nop
    /* 4EC80 0014EC80 8800103C */  lui        $16, %hi(D_008873F4)
    /* 4EC84 0014EC84 F4731026 */  addiu      $16, $16, %lo(D_008873F4)
    /* 4EC88 0014EC88 01000424 */  addiu      $4, $0, 0x1
    /* 4EC8C 0014EC8C 50000524 */  addiu      $5, $0, 0x50
    /* 4EC90 0014EC90 0400063C */  lui        $6, (0x40000 >> 16)
    /* 4EC94 0014EC94 0000028E */  lw         $2, 0x0($16)
    /* 4EC98 0014EC98 09F84000 */  jalr       $2
    /* 4EC9C 0014EC9C 00000000 */   nop
    /* 4ECA0 0014ECA0 2D884000 */  daddu      $17, $2, $0
    /* 4ECA4 0014ECA4 04002016 */  bnez       $17, .L0014ECB8
    /* 4ECA8 0014ECA8 00000000 */   nop
    /* 4ECAC 0014ECAC 2D100000 */  daddu      $2, $0, $0
    /* 4ECB0 0014ECB0 7A000010 */  b          .L0014EE9C
    /* 4ECB4 0014ECB4 00000000 */   nop
  .L0014ECB8:
    /* 4ECB8 0014ECB8 2D204002 */  daddu      $4, $18, $0
    /* 4ECBC 0014ECBC 5F00053C */  lui        $5, %hi(D_005EFC28)
    /* 4ECC0 0014ECC0 28FCA524 */  addiu      $5, $5, %lo(D_005EFC28)
    /* 4ECC4 0014ECC4 0F000624 */  addiu      $6, $0, 0xF
    /* 4ECC8 0014ECC8 2D380000 */  daddu      $7, $0, $0
    /* 4ECCC 0014ECCC 2D400000 */  daddu      $8, $0, $0
    /* 4ECD0 0014ECD0 1500093C */  lui        $9, %hi(func_0014e950)
    /* 4ECD4 0014ECD4 50E92925 */  addiu      $9, $9, %lo(func_0014e950)
    /* 4ECD8 0014ECD8 15000A3C */  lui        $10, %hi(func_0014ec20)
    /* 4ECDC 0014ECDC 20EC4A25 */  addiu      $10, $10, %lo(func_0014ec20)
    /* 4ECE0 0014ECE0 2D582002 */  daddu      $11, $17, $0
    /* 4ECE4 0014ECE4 F047110C */  jal        func_00451fc0
    /* 4ECE8 0014ECE8 00000000 */   nop
    /* 4ECEC 0014ECEC 2D904000 */  daddu      $18, $2, $0
    /* 4ECF0 0014ECF0 040033AE */  sw         $19, 0x4($17)
    /* 4ECF4 0014ECF4 34006016 */  bnez       $19, .L0014EDC8
    /* 4ECF8 0014ECF8 00000000 */   nop
    /* 4ECFC 0014ECFC E09D8427 */  addiu      $4, $28, -0x6220
    /* 4ED00 0014ED00 C2000524 */  addiu      $5, $0, 0xC2
    /* 4ED04 0014ED04 A43A110C */  jal        func_0044ea90
    /* 4ED08 0014ED08 00000000 */   nop
    /* 4ED0C 0014ED0C 01000424 */  addiu      $4, $0, 0x1
    /* 4ED10 0014ED10 FC000524 */  addiu      $5, $0, 0xFC
    /* 4ED14 0014ED14 0400063C */  lui        $6, (0x40000 >> 16)
    /* 4ED18 0014ED18 0000028E */  lw         $2, 0x0($16)
    /* 4ED1C 0014ED1C 09F84000 */  jalr       $2
    /* 4ED20 0014ED20 00000000 */   nop
    /* 4ED24 0014ED24 2D804000 */  daddu      $16, $2, $0
    /* 4ED28 0014ED28 04000016 */  bnez       $16, .L0014ED3C
    /* 4ED2C 0014ED2C 00000000 */   nop
    /* 4ED30 0014ED30 2D980000 */  daddu      $19, $0, $0
    /* 4ED34 0014ED34 21000010 */  b          .L0014EDBC
    /* 4ED38 0014ED38 00000000 */   nop
  .L0014ED3C:
    /* 4ED3C 0014ED3C 2D204002 */  daddu      $4, $18, $0
    /* 4ED40 0014ED40 5F00053C */  lui        $5, %hi(D_005EFC18)
    /* 4ED44 0014ED44 18FCA524 */  addiu      $5, $5, %lo(D_005EFC18)
    /* 4ED48 0014ED48 0F000624 */  addiu      $6, $0, 0xF
    /* 4ED4C 0014ED4C 2D380000 */  daddu      $7, $0, $0
    /* 4ED50 0014ED50 2D400000 */  daddu      $8, $0, $0
    /* 4ED54 0014ED54 1500093C */  lui        $9, %hi(func_0014e2a0)
    /* 4ED58 0014ED58 A0E22925 */  addiu      $9, $9, %lo(func_0014e2a0)
    /* 4ED5C 0014ED5C 15000A3C */  lui        $10, %hi(func_0014e540)
    /* 4ED60 0014ED60 40E54A25 */  addiu      $10, $10, %lo(func_0014e540)
    /* 4ED64 0014ED64 2D580002 */  daddu      $11, $16, $0
    /* 4ED68 0014ED68 F047110C */  jal        func_00451fc0
    /* 4ED6C 0014ED6C 00000000 */   nop
    /* 4ED70 0014ED70 2D984000 */  daddu      $19, $2, $0
    /* 4ED74 0014ED74 E89D8427 */  addiu      $4, $28, -0x6218
    /* 4ED78 0014ED78 E09D8527 */  addiu      $5, $28, -0x6220
    /* 4ED7C 0014ED7C D0000624 */  addiu      $6, $0, 0xD0
    /* 4ED80 0014ED80 DA02110C */  jal        func_00440b68
    /* 4ED84 0014ED84 00000000 */   nop
    /* 4ED88 0014ED88 5F00043C */  lui        $4, %hi(D_005EFC40)
    /* 4ED8C 0014ED8C 40FC8424 */  addiu      $4, $4, %lo(D_005EFC40)
    /* 4ED90 0014ED90 2D280000 */  daddu      $5, $0, $0
    /* 4ED94 0014ED94 9852110C */  jal        func_00454a60
    /* 4ED98 0014ED98 00000000 */   nop
    /* 4ED9C 0014ED9C 040002AE */  sw         $2, 0x4($16)
    /* 4EDA0 0014EDA0 53000224 */  addiu      $2, $0, 0x53
    /* 4EDA4 0014EDA4 080002AE */  sw         $2, 0x8($16)
    /* 4EDA8 0014EDA8 BC000426 */  addiu      $4, $16, 0xBC
    /* 4EDAC 0014EDAC 5F00053C */  lui        $5, %hi(D_005EFC40)
    /* 4EDB0 0014EDB0 40FCA524 */  addiu      $5, $5, %lo(D_005EFC40)
    /* 4EDB4 0014EDB4 0C0A110C */  jal        func_00442830
    /* 4EDB8 0014EDB8 00000000 */   nop
  .L0014EDBC:
    /* 4EDBC 0014EDBC 0C0033AE */  sw         $19, 0xC($17)
    /* 4EDC0 0014EDC0 35000010 */  b          .L0014EE98
    /* 4EDC4 0014EDC4 00000000 */   nop
  .L0014EDC8:
    /* 4EDC8 0014EDC8 01000224 */  addiu      $2, $0, 0x1
    /* 4EDCC 0014EDCC 32006216 */  bne        $19, $2, .L0014EE98
    /* 4EDD0 0014EDD0 00000000 */   nop
    /* 4EDD4 0014EDD4 E09D8427 */  addiu      $4, $28, -0x6220
    /* 4EDD8 0014EDD8 C2000524 */  addiu      $5, $0, 0xC2
    /* 4EDDC 0014EDDC A43A110C */  jal        func_0044ea90
    /* 4EDE0 0014EDE0 00000000 */   nop
    /* 4EDE4 0014EDE4 01000424 */  addiu      $4, $0, 0x1
    /* 4EDE8 0014EDE8 FC000524 */  addiu      $5, $0, 0xFC
    /* 4EDEC 0014EDEC 0400063C */  lui        $6, (0x40000 >> 16)
    /* 4EDF0 0014EDF0 0000028E */  lw         $2, 0x0($16)
    /* 4EDF4 0014EDF4 09F84000 */  jalr       $2
    /* 4EDF8 0014EDF8 00000000 */   nop
    /* 4EDFC 0014EDFC 2D804000 */  daddu      $16, $2, $0
    /* 4EE00 0014EE00 04000016 */  bnez       $16, .L0014EE14
    /* 4EE04 0014EE04 00000000 */   nop
    /* 4EE08 0014EE08 2D980000 */  daddu      $19, $0, $0
    /* 4EE0C 0014EE0C 21000010 */  b          .L0014EE94
    /* 4EE10 0014EE10 00000000 */   nop
  .L0014EE14:
    /* 4EE14 0014EE14 2D204002 */  daddu      $4, $18, $0
    /* 4EE18 0014EE18 5F00053C */  lui        $5, %hi(D_005EFC18)
    /* 4EE1C 0014EE1C 18FCA524 */  addiu      $5, $5, %lo(D_005EFC18)
    /* 4EE20 0014EE20 0F000624 */  addiu      $6, $0, 0xF
    /* 4EE24 0014EE24 2D380000 */  daddu      $7, $0, $0
    /* 4EE28 0014EE28 2D400000 */  daddu      $8, $0, $0
    /* 4EE2C 0014EE2C 1500093C */  lui        $9, %hi(func_0014e2a0)
    /* 4EE30 0014EE30 A0E22925 */  addiu      $9, $9, %lo(func_0014e2a0)
    /* 4EE34 0014EE34 15000A3C */  lui        $10, %hi(func_0014e540)
    /* 4EE38 0014EE38 40E54A25 */  addiu      $10, $10, %lo(func_0014e540)
    /* 4EE3C 0014EE3C 2D580002 */  daddu      $11, $16, $0
    /* 4EE40 0014EE40 F047110C */  jal        func_00451fc0
    /* 4EE44 0014EE44 00000000 */   nop
    /* 4EE48 0014EE48 2D984000 */  daddu      $19, $2, $0
    /* 4EE4C 0014EE4C E89D8427 */  addiu      $4, $28, -0x6218
    /* 4EE50 0014EE50 E09D8527 */  addiu      $5, $28, -0x6220
    /* 4EE54 0014EE54 D0000624 */  addiu      $6, $0, 0xD0
    /* 4EE58 0014EE58 DA02110C */  jal        func_00440b68
    /* 4EE5C 0014EE5C 00000000 */   nop
    /* 4EE60 0014EE60 5F00043C */  lui        $4, %hi(D_005EFC40)
    /* 4EE64 0014EE64 40FC8424 */  addiu      $4, $4, %lo(D_005EFC40)
    /* 4EE68 0014EE68 2D280000 */  daddu      $5, $0, $0
    /* 4EE6C 0014EE6C 9852110C */  jal        func_00454a60
    /* 4EE70 0014EE70 00000000 */   nop
    /* 4EE74 0014EE74 040002AE */  sw         $2, 0x4($16)
    /* 4EE78 0014EE78 32000224 */  addiu      $2, $0, 0x32
    /* 4EE7C 0014EE7C 080002AE */  sw         $2, 0x8($16)
    /* 4EE80 0014EE80 BC000426 */  addiu      $4, $16, 0xBC
    /* 4EE84 0014EE84 5F00053C */  lui        $5, %hi(D_005EFC40)
    /* 4EE88 0014EE88 40FCA524 */  addiu      $5, $5, %lo(D_005EFC40)
    /* 4EE8C 0014EE8C 0C0A110C */  jal        func_00442830
    /* 4EE90 0014EE90 00000000 */   nop
  .L0014EE94:
    /* 4EE94 0014EE94 0C0033AE */  sw         $19, 0xC($17)
  .L0014EE98:
    /* 4EE98 0014EE98 2D104002 */  daddu      $2, $18, $0
  .L0014EE9C:
    /* 4EE9C 0014EE9C 4000BFDF */  ld         $31, 0x40($29)
    /* 4EEA0 0014EEA0 3000B37B */  lq         $19, 0x30($29)
    /* 4EEA4 0014EEA4 2000B27B */  lq         $18, 0x20($29)
    /* 4EEA8 0014EEA8 1000B17B */  lq         $17, 0x10($29)
    /* 4EEAC 0014EEAC 0000B07B */  lq         $16, 0x0($29)
    /* 4EEB0 0014EEB0 5000BD27 */  addiu      $29, $29, 0x50
    /* 4EEB4 0014EEB4 0800E003 */  jr         $31
    /* 4EEB8 0014EEB8 00000000 */   nop
    /* 4EEBC 0014EEBC 00000000 */  nop
.size func_0014ec50, 0x270
