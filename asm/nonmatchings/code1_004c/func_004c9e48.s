.section .text
.set noat
.set noreorder
glabel func_004c9e48
    /* 3C9E48 004C9E48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9E4C 004C9E4C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C9E50 004C9E50 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9E54 004C9E54 52271308 */  j          func_004c9d48
    /* 3C9E58 004C9E58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9E5C 004C9E5C 00000000 */  nop
.size func_004c9e48, 0x18
