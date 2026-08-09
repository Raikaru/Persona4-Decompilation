.section .text
.set noat
.set noreorder
glabel func_0052bec8
    /* 42BEC8 0052BEC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BECC 0052BECC 0000BFFF */  sd         $31, 0x0($29)
    /* 42BED0 0052BED0 0000BFDF */  ld         $31, 0x0($29)
    /* 42BED4 0052BED4 66B31408 */  j          func_0052cd98
    /* 42BED8 0052BED8 1000BD27 */   addiu     $29, $29, 0x10
    /* 42BEDC 0052BEDC 00000000 */  nop
.size func_0052bec8, 0x18
