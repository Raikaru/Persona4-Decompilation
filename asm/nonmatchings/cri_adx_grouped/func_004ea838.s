.section .text
.set noat
.set noreorder
glabel func_004ea838
    /* 3EA838 004EA838 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA83C 004EA83C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA840 004EA840 0800BFFF */  sd         $31, 0x8($29)
    /* 3EA844 004EA844 C4A9130C */  jal        func_004ea710
    /* 3EA848 004EA848 2D808000 */   daddu     $16, $4, $0
    /* 3EA84C 004EA84C 1AAA130C */  jal        func_004ea868
    /* 3EA850 004EA850 2D200002 */   daddu     $4, $16, $0
    /* 3EA854 004EA854 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA858 004EA858 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA85C 004EA85C CAA91308 */  j          func_004ea728
    /* 3EA860 004EA860 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA864 004EA864 00000000 */  nop
.size func_004ea838, 0x30
