.section .text
.set noat
.set noreorder
glabel func_0052a898
    /* 42A898 0052A898 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42A89C 0052A89C 0000BFFF */  sd         $31, 0x0($29)
    /* 42A8A0 0052A8A0 0000BFDF */  ld         $31, 0x0($29)
    /* 42A8A4 0052A8A4 2CAA1408 */  j          func_0052a8b0
    /* 42A8A8 0052A8A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 42A8AC 0052A8AC 00000000 */  nop
.size func_0052a898, 0x18
