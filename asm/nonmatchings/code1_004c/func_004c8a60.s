.section .text
.set noat
.set noreorder
glabel func_004c8a60
    /* 3C8A60 004C8A60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C8A64 004C8A64 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8A68 004C8A68 0800BFFF */  sd         $31, 0x8($29)
    /* 3C8A6C 004C8A6C 4627130C */  jal        func_004c9d18
    /* 3C8A70 004C8A70 2D808000 */   daddu     $16, $4, $0
    /* 3C8A74 004C8A74 A422130C */  jal        func_004c8a90
    /* 3C8A78 004C8A78 2D200002 */   daddu     $4, $16, $0
    /* 3C8A7C 004C8A7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8A80 004C8A80 0800BFDF */  ld         $31, 0x8($29)
    /* 3C8A84 004C8A84 4C271308 */  j          func_004c9d30
    /* 3C8A88 004C8A88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C8A8C 004C8A8C 00000000 */  nop
.size func_004c8a60, 0x30
