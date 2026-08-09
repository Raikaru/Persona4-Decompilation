.section .text
.set noat
.set noreorder
glabel func_004ea9c8
    /* 3EA9C8 004EA9C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA9CC 004EA9CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA9D0 004EA9D0 0800BFFF */  sd         $31, 0x8($29)
    /* 3EA9D4 004EA9D4 C4A9130C */  jal        func_004ea710
    /* 3EA9D8 004EA9D8 2D808000 */   daddu     $16, $4, $0
    /* 3EA9DC 004EA9DC 7EAA130C */  jal        func_004ea9f8
    /* 3EA9E0 004EA9E0 2D200002 */   daddu     $4, $16, $0
    /* 3EA9E4 004EA9E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA9E8 004EA9E8 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA9EC 004EA9EC CAA91308 */  j          func_004ea728
    /* 3EA9F0 004EA9F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA9F4 004EA9F4 00000000 */  nop
.size func_004ea9c8, 0x30
