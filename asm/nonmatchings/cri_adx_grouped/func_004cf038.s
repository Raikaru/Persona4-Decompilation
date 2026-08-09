.section .text
.set noat
.set noreorder
glabel func_004cf038
    /* 3CF038 004CF038 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF03C 004CF03C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CF040 004CF040 0400848C */  lw         $4, 0x4($4)
    /* 3CF044 004CF044 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF048 004CF048 3C0F1308 */  j          func_004c3cf0
    /* 3CF04C 004CF04C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cf038, 0x18
