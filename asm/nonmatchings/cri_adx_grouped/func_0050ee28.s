.section .text
.set noat
.set noreorder
glabel func_0050ee28
    /* 40EE28 0050EE28 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 40EE2C 0050EE2C 0000B0FF */  sd         $16, 0x0($29)
    /* 40EE30 0050EE30 2D808000 */  daddu      $16, $4, $0
    /* 40EE34 0050EE34 0800B1FF */  sd         $17, 0x8($29)
    /* 40EE38 0050EE38 2D88A000 */  daddu      $17, $5, $0
    /* 40EE3C 0050EE3C 1000B2FF */  sd         $18, 0x10($29)
    /* 40EE40 0050EE40 2D90C000 */  daddu      $18, $6, $0
    /* 40EE44 0050EE44 1800B3FF */  sd         $19, 0x18($29)
    /* 40EE48 0050EE48 2000BFFF */  sd         $31, 0x20($29)
    /* 40EE4C 0050EE4C 0A35140C */  jal        func_0050d428
    /* 40EE50 0050EE50 2D98E000 */   daddu     $19, $7, $0
    /* 40EE54 0050EE54 01000324 */  addiu      $3, $0, 0x1
    /* 40EE58 0050EE58 0B004310 */  beq        $2, $3, .L0050EE88
    /* 40EE5C 0050EE5C 2D200002 */   daddu     $4, $16, $0
    /* 40EE60 0050EE60 7600043C */  lui        $4, %hi(D_0075F948)
    /* 40EE64 0050EE64 0000B0DF */  ld         $16, 0x0($29)
    /* 40EE68 0050EE68 0800B1DF */  ld         $17, 0x8($29)
    /* 40EE6C 0050EE6C 48F98424 */  addiu      $4, $4, %lo(D_0075F948)
    /* 40EE70 0050EE70 1000B2DF */  ld         $18, 0x10($29)
    /* 40EE74 0050EE74 1800B3DF */  ld         $19, 0x18($29)
    /* 40EE78 0050EE78 2000BFDF */  ld         $31, 0x20($29)
    /* 40EE7C 0050EE7C 88441408 */  j          func_00511220
    /* 40EE80 0050EE80 3000BD27 */   addiu     $29, $29, 0x30
    /* 40EE84 0050EE84 00000000 */  nop
  .L0050EE88:
    /* 40EE88 0050EE88 2E39140C */  jal        func_0050e4b8
    /* 40EE8C 0050EE8C 00000000 */   nop
    /* 40EE90 0050EE90 2D282002 */  daddu      $5, $17, $0
    /* 40EE94 0050EE94 2D804000 */  daddu      $16, $2, $0
    /* 40EE98 0050EE98 2D304002 */  daddu      $6, $18, $0
    /* 40EE9C 0050EE9C 94AE140C */  jal        func_0052ba50
    /* 40EEA0 0050EEA0 2D200002 */   daddu     $4, $16, $0
    /* 40EEA4 0050EEA4 2D200002 */  daddu      $4, $16, $0
    /* 40EEA8 0050EEA8 2D286002 */  daddu      $5, $19, $0
    /* 40EEAC 0050EEAC 1800B3DF */  ld         $19, 0x18($29)
    /* 40EEB0 0050EEB0 0000B0DF */  ld         $16, 0x0($29)
    /* 40EEB4 0050EEB4 0800B1DF */  ld         $17, 0x8($29)
    /* 40EEB8 0050EEB8 1000B2DF */  ld         $18, 0x10($29)
    /* 40EEBC 0050EEBC 2000BFDF */  ld         $31, 0x20($29)
    /* 40EEC0 0050EEC0 9EAE1408 */  j          func_0052ba78
    /* 40EEC4 0050EEC4 3000BD27 */   addiu     $29, $29, 0x30
.size func_0050ee28, 0xa0
