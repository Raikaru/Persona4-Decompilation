.section .text
.set noat
.set noreorder
glabel func_004f2438
    /* 3F2438 004F2438 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F243C 004F243C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F2440 004F2440 0800BFFF */  sd         $31, 0x8($29)
    /* 3F2444 004F2444 28D5130C */  jal        func_004f54a0
    /* 3F2448 004F2448 2D808000 */   daddu     $16, $4, $0
    /* 3F244C 004F244C 0800BFDF */  ld         $31, 0x8($29)
    /* 3F2450 004F2450 2D200002 */  daddu      $4, $16, $0
    /* 3F2454 004F2454 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2458 004F2458 1EC71308 */  j          func_004f1c78
    /* 3F245C 004F245C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f2438, 0x28
