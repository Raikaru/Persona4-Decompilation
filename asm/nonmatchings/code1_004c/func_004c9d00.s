.section .text
.set noat
.set noreorder
glabel func_004c9d00
    /* 3C9D00 004C9D00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9D04 004C9D04 0000BFFF */  sd         $31, 0x0($29)
    /* 3C9D08 004C9D08 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9D0C 004C9D0C 5E4B1308 */  j          func_004d2d78
    /* 3C9D10 004C9D10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9D14 004C9D14 00000000 */  nop
.size func_004c9d00, 0x18
