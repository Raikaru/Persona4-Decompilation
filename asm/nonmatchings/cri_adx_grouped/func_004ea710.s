.section .text
.set noat
.set noreorder
glabel func_004ea710
    /* 3EA710 004EA710 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA714 004EA714 0000BFFF */  sd         $31, 0x0($29)
    /* 3EA718 004EA718 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA71C 004EA71C 82C11308 */  j          func_004f0608
    /* 3EA720 004EA720 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA724 004EA724 00000000 */  nop
.size func_004ea710, 0x18
