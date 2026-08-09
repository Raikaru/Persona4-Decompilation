.section .text
.set noat
.set noreorder
glabel func_00511838
    /* 411838 00511838 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41183C 0051183C 0000BFFF */  sd         $31, 0x0($29)
    /* 411840 00511840 0000BFDF */  ld         $31, 0x0($29)
    /* 411844 00511844 40461408 */  j          func_00511900
    /* 411848 00511848 1000BD27 */   addiu     $29, $29, 0x10
    /* 41184C 0051184C 00000000 */  nop
.size func_00511838, 0x18
