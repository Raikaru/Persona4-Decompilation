.section .text
.set noat
.set noreorder
glabel func_004cc9d0
    /* 3CC9D0 004CC9D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CC9D4 004CC9D4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CC9D8 004CC9D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CC9DC 004CC9DC 82C11308 */  j          func_004f0608
    /* 3CC9E0 004CC9E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CC9E4 004CC9E4 00000000 */  nop
.size func_004cc9d0, 0x18
