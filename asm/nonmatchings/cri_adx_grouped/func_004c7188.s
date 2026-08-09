.section .text
.set noat
.set noreorder
glabel func_004c7188
    /* 3C7188 004C7188 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C718C 004C718C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7190 004C7190 0800BFFF */  sd         $31, 0x8($29)
    /* 3C7194 004C7194 8A1C130C */  jal        func_004c7228
    /* 3C7198 004C7198 2D808000 */   daddu     $16, $4, $0
    /* 3C719C 004C719C 6E1C130C */  jal        func_004c71b8
    /* 3C71A0 004C71A0 2D200002 */   daddu     $4, $16, $0
    /* 3C71A4 004C71A4 0000B0DF */  ld         $16, 0x0($29)
    /* 3C71A8 004C71A8 0800BFDF */  ld         $31, 0x8($29)
    /* 3C71AC 004C71AC 8C1C1308 */  j          func_004c7230
    /* 3C71B0 004C71B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C71B4 004C71B4 00000000 */  nop
.size func_004c7188, 0x30
