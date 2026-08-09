.section .text
.set noat
.set noreorder
glabel func_0052c318
    /* 42C318 0052C318 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42C31C 0052C31C 0000BFFF */  sd         $31, 0x0($29)
    /* 42C320 0052C320 0000BFDF */  ld         $31, 0x0($29)
    /* 42C324 0052C324 CCB01408 */  j          func_0052c330
    /* 42C328 0052C328 1000BD27 */   addiu     $29, $29, 0x10
    /* 42C32C 0052C32C 00000000 */  nop
.size func_0052c318, 0x18
