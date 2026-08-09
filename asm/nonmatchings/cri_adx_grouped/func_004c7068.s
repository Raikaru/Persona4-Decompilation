.section .text
.set noat
.set noreorder
glabel func_004c7068
    /* 3C7068 004C7068 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C706C 004C706C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7070 004C7070 0800BFFF */  sd         $31, 0x8($29)
    /* 3C7074 004C7074 8A1C130C */  jal        func_004c7228
    /* 3C7078 004C7078 2D808000 */   daddu     $16, $4, $0
    /* 3C707C 004C707C 261C130C */  jal        func_004c7098
    /* 3C7080 004C7080 2D200002 */   daddu     $4, $16, $0
    /* 3C7084 004C7084 0000B0DF */  ld         $16, 0x0($29)
    /* 3C7088 004C7088 0800BFDF */  ld         $31, 0x8($29)
    /* 3C708C 004C708C 8C1C1308 */  j          func_004c7230
    /* 3C7090 004C7090 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C7094 004C7094 00000000 */  nop
.size func_004c7068, 0x30
