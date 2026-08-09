.section .text
.set noat
.set noreorder
glabel func_005110f8
    /* 4110F8 005110F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4110FC 005110FC 0000BFFF */  sd         $31, 0x0($29)
    /* 411100 00511100 0000BFDF */  ld         $31, 0x0($29)
    /* 411104 00511104 66331408 */  j          func_0050cd98
    /* 411108 00511108 1000BD27 */   addiu     $29, $29, 0x10
    /* 41110C 0051110C 00000000 */  nop
.size func_005110f8, 0x18
