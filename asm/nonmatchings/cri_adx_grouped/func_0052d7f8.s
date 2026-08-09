.section .text
.set noat
.set noreorder
glabel func_0052d7f8
    /* 42D7F8 0052D7F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42D7FC 0052D7FC 0000BFFF */  sd         $31, 0x0($29)
    /* 42D800 0052D800 0000BFDF */  ld         $31, 0x0($29)
    /* 42D804 0052D804 5CB61408 */  j          func_0052d970
    /* 42D808 0052D808 1000BD27 */   addiu     $29, $29, 0x10
    /* 42D80C 0052D80C 00000000 */  nop
.size func_0052d7f8, 0x18
