.section .text
.set noat
.set noreorder
glabel func_004eaa18
    /* 3EAA18 004EAA18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EAA1C 004EAA1C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EAA20 004EAA20 0800BFFF */  sd         $31, 0x8($29)
    /* 3EAA24 004EAA24 C4A9130C */  jal        func_004ea710
    /* 3EAA28 004EAA28 2D808000 */   daddu     $16, $4, $0
    /* 3EAA2C 004EAA2C 92AA130C */  jal        func_004eaa48
    /* 3EAA30 004EAA30 2D200002 */   daddu     $4, $16, $0
    /* 3EAA34 004EAA34 0000B0DF */  ld         $16, 0x0($29)
    /* 3EAA38 004EAA38 0800BFDF */  ld         $31, 0x8($29)
    /* 3EAA3C 004EAA3C CAA91308 */  j          func_004ea728
    /* 3EAA40 004EAA40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EAA44 004EAA44 00000000 */  nop
.size func_004eaa18, 0x30
