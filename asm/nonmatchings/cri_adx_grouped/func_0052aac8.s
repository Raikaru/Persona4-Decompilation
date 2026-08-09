.section .text
.set noat
.set noreorder
glabel func_0052aac8
    /* 42AAC8 0052AAC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42AACC 0052AACC 0000BFFF */  sd         $31, 0x0($29)
    /* 42AAD0 0052AAD0 3800848C */  lw         $4, 0x38($4)
    /* 42AAD4 0052AAD4 0000BFDF */  ld         $31, 0x0($29)
    /* 42AAD8 0052AAD8 B8AA1408 */  j          func_0052aae0
    /* 42AADC 0052AADC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052aac8, 0x18
