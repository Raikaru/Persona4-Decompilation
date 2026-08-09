.section .text
.set noat
.set noreorder
glabel func_004c6eb0
    /* 3C6EB0 004C6EB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6EB4 004C6EB4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C6EB8 004C6EB8 0800BFFF */  sd         $31, 0x8($29)
    /* 3C6EBC 004C6EBC 8A1C130C */  jal        func_004c7228
    /* 3C6EC0 004C6EC0 2D808000 */   daddu     $16, $4, $0
    /* 3C6EC4 004C6EC4 B81B130C */  jal        func_004c6ee0
    /* 3C6EC8 004C6EC8 2D200002 */   daddu     $4, $16, $0
    /* 3C6ECC 004C6ECC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C6ED0 004C6ED0 0800BFDF */  ld         $31, 0x8($29)
    /* 3C6ED4 004C6ED4 8C1C1308 */  j          func_004c7230
    /* 3C6ED8 004C6ED8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C6EDC 004C6EDC 00000000 */  nop
.size func_004c6eb0, 0x30
