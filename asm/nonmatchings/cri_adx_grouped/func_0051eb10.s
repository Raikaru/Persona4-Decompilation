.section .text
.set noat
.set noreorder
glabel func_0051eb10
    /* 41EB10 0051EB10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41EB14 0051EB14 FFFF0524 */  addiu      $5, $0, -0x1
    /* 41EB18 0051EB18 0000BFFF */  sd         $31, 0x0($29)
    /* 41EB1C 0051EB1C 20000624 */  addiu      $6, $0, 0x20
    /* 41EB20 0051EB20 0000BFDF */  ld         $31, 0x0($29)
    /* 41EB24 0051EB24 44051408 */  j          func_00501510
    /* 41EB28 0051EB28 1000BD27 */   addiu     $29, $29, 0x10
    /* 41EB2C 0051EB2C 00000000 */  nop
.size func_0051eb10, 0x20
