.section .text
.set noat
.set noreorder
glabel func_004f2370
    /* 3F2370 004F2370 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F2374 004F2374 0000B0FF */  sd         $16, 0x0($29)
    /* 3F2378 004F2378 0800BFFF */  sd         $31, 0x8($29)
    /* 3F237C 004F237C 28D5130C */  jal        func_004f54a0
    /* 3F2380 004F2380 2D808000 */   daddu     $16, $4, $0
    /* 3F2384 004F2384 0800BFDF */  ld         $31, 0x8($29)
    /* 3F2388 004F2388 2D200002 */  daddu      $4, $16, $0
    /* 3F238C 004F238C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2390 004F2390 14C61308 */  j          func_004f1850
    /* 3F2394 004F2394 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f2370, 0x28
