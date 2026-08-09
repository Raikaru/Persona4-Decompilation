.section .text
.set noat
.set noreorder
glabel func_0051edd0
    /* 41EDD0 0051EDD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 41EDD4 0051EDD4 0000B0FF */  sd         $16, 0x0($29)
    /* 41EDD8 0051EDD8 2D808000 */  daddu      $16, $4, $0
    /* 41EDDC 0051EDDC 0800B1FF */  sd         $17, 0x8($29)
    /* 41EDE0 0051EDE0 2D88A000 */  daddu      $17, $5, $0
    /* 41EDE4 0051EDE4 1000B2FF */  sd         $18, 0x10($29)
    /* 41EDE8 0051EDE8 1800B3FF */  sd         $19, 0x18($29)
    /* 41EDEC 0051EDEC 300D1326 */  addiu      $19, $16, 0xD30
    /* 41EDF0 0051EDF0 2000B4FF */  sd         $20, 0x20($29)
    /* 41EDF4 0051EDF4 2800BFFF */  sd         $31, 0x28($29)
    /* 41EDF8 0051EDF8 F27D140C */  jal        func_0051f7c8
    /* 41EDFC 0051EDFC 2DA0C000 */   daddu     $20, $6, $0
    /* 41EE00 0051EE00 2D904000 */  daddu      $18, $2, $0
    /* 41EE04 0051EE04 2D200002 */  daddu      $4, $16, $0
    /* 41EE08 0051EE08 2D284002 */  daddu      $5, $18, $0
    /* 41EE0C 0051EE0C 0D004012 */  beqz       $18, .L0051EE44
    /* 41EE10 0051EE10 2D302002 */   daddu     $6, $17, $0
    /* 41EE14 0051EE14 A47B140C */  jal        func_0051ee90
    /* 41EE18 0051EE18 00000000 */   nop
    /* 41EE1C 0051EE1C 0000228E */  lw         $2, 0x0($17)
    /* 41EE20 0051EE20 2D200002 */  daddu      $4, $16, $0
    /* 41EE24 0051EE24 1400468C */  lw         $6, 0x14($2)
    /* 41EE28 0051EE28 2D284000 */  daddu      $5, $2, $0
    /* 41EE2C 0051EE2C 7C0266AE */  sw         $6, 0x27C($19)
    /* 41EE30 0051EE30 1800438C */  lw         $3, 0x18($2)
    /* 41EE34 0051EE34 C69A140C */  jal        func_00526b18
    /* 41EE38 0051EE38 800263AE */   sw        $3, 0x280($19)
    /* 41EE3C 0051EE3C 04004014 */  bnez       $2, .L0051EE50
    /* 41EE40 0051EE40 02000324 */   addiu     $3, $0, 0x2
  .L0051EE44:
    /* 41EE44 0051EE44 0A000010 */  b          .L0051EE70
    /* 41EE48 0051EE48 000020AE */   sw        $0, 0x0($17)
    /* 41EE4C 0051EE4C 00000000 */  nop
  .L0051EE50:
    /* 41EE50 0051EE50 5800028E */  lw         $2, 0x58($16)
    /* 41EE54 0051EE54 06004354 */  bnel       $2, $3, .L0051EE70
    /* 41EE58 0051EE58 2D100000 */   daddu     $2, $0, $0
    /* 41EE5C 0051EE5C 187F140C */  jal        func_0051fc60
    /* 41EE60 0051EE60 2D200002 */   daddu     $4, $16, $0
    /* 41EE64 0051EE64 580042AE */  sw         $2, 0x58($18)
    /* 41EE68 0051EE68 000082AE */  sw         $2, 0x0($20)
    /* 41EE6C 0051EE6C 2D100000 */  daddu      $2, $0, $0
  .L0051EE70:
    /* 41EE70 0051EE70 0000B0DF */  ld         $16, 0x0($29)
    /* 41EE74 0051EE74 0800B1DF */  ld         $17, 0x8($29)
    /* 41EE78 0051EE78 1000B2DF */  ld         $18, 0x10($29)
    /* 41EE7C 0051EE7C 1800B3DF */  ld         $19, 0x18($29)
    /* 41EE80 0051EE80 2000B4DF */  ld         $20, 0x20($29)
    /* 41EE84 0051EE84 2800BFDF */  ld         $31, 0x28($29)
    /* 41EE88 0051EE88 0800E003 */  jr         $31
    /* 41EE8C 0051EE8C 3000BD27 */   addiu     $29, $29, 0x30
.size func_0051edd0, 0xc0
