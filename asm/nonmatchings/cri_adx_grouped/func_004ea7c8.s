.section .text
.set noat
.set noreorder
glabel func_004ea7c8
    /* 3EA7C8 004EA7C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA7CC 004EA7CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA7D0 004EA7D0 0800BFFF */  sd         $31, 0x8($29)
    /* 3EA7D4 004EA7D4 C4A9130C */  jal        func_004ea710
    /* 3EA7D8 004EA7D8 2D808000 */   daddu     $16, $4, $0
    /* 3EA7DC 004EA7DC FEA9130C */  jal        func_004ea7f8
    /* 3EA7E0 004EA7E0 2D200002 */   daddu     $4, $16, $0
    /* 3EA7E4 004EA7E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA7E8 004EA7E8 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA7EC 004EA7EC CAA91308 */  j          func_004ea728
    /* 3EA7F0 004EA7F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA7F4 004EA7F4 00000000 */  nop
.size func_004ea7c8, 0x30
