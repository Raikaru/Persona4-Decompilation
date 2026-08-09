.section .text
.set noat
.set noreorder
glabel func_004cd830
    /* 3CD830 004CD830 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD834 004CD834 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD838 004CD838 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD83C 004CD83C E8B31308 */  j          func_004ecfa0
    /* 3CD840 004CD840 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD844 004CD844 00000000 */  nop
.size func_004cd830, 0x18
