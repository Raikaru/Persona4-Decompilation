.section .text
.set noat
.set noreorder
glabel func_004cb210
    /* 3CB210 004CB210 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB214 004CB214 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB218 004CB218 0800BFFF */  sd         $31, 0x8($29)
    /* 3CB21C 004CB21C 3615130C */  jal        func_004c54d8
    /* 3CB220 004CB220 2D808000 */   daddu     $16, $4, $0
    /* 3CB224 004CB224 902C130C */  jal        func_004cb240
    /* 3CB228 004CB228 2D200002 */   daddu     $4, $16, $0
    /* 3CB22C 004CB22C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB230 004CB230 0800BFDF */  ld         $31, 0x8($29)
    /* 3CB234 004CB234 38151308 */  j          func_004c54e0
    /* 3CB238 004CB238 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB23C 004CB23C 00000000 */  nop
.size func_004cb210, 0x30
