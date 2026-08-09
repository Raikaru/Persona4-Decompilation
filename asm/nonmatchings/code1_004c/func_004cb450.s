.section .text
.set noat
.set noreorder
glabel func_004cb450
    /* 3CB450 004CB450 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB454 004CB454 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB458 004CB458 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB45C 004CB45C 14C41308 */  j          func_004f1050
    /* 3CB460 004CB460 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB464 004CB464 00000000 */  nop
.size func_004cb450, 0x18
