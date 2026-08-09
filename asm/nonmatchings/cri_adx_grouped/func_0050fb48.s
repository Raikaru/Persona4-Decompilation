.section .text
.set noat
.set noreorder
glabel func_0050fb48
    /* 40FB48 0050FB48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FB4C 0050FB4C 0000BFFF */  sd         $31, 0x0($29)
    /* 40FB50 0050FB50 0000BFDF */  ld         $31, 0x0($29)
    /* 40FB54 0050FB54 ACAF1408 */  j          func_0052beb0
    /* 40FB58 0050FB58 1000BD27 */   addiu     $29, $29, 0x10
    /* 40FB5C 0050FB5C 00000000 */  nop
.size func_0050fb48, 0x18
