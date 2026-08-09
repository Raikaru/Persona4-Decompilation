.section .text
.set noat
.set noreorder
glabel func_004c7f30
    /* 3C7F30 004C7F30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7F34 004C7F34 0000BFFF */  sd         $31, 0x0($29)
    /* 3C7F38 004C7F38 0000BFDF */  ld         $31, 0x0($29)
    /* 3C7F3C 004C7F3C E01F1308 */  j          func_004c7f80
    /* 3C7F40 004C7F40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C7F44 004C7F44 00000000 */  nop
.size func_004c7f30, 0x18
