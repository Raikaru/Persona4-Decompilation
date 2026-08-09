.section .text
.set noat
.set noreorder
glabel func_004e8058
    /* 3E8058 004E8058 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E805C 004E805C 0000BFFF */  sd         $31, 0x0($29)
    /* 3E8060 004E8060 0000BFDF */  ld         $31, 0x0($29)
    /* 3E8064 004E8064 F09D1308 */  j          func_004e77c0
    /* 3E8068 004E8068 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E806C 004E806C 00000000 */  nop
.size func_004e8058, 0x18
