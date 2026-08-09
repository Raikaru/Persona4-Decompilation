.section .text
.set noat
.set noreorder
glabel func_004be038
    /* 3BE038 004BE038 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE03C 004BE03C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE040 004BE040 0400848C */  lw         $4, 0x4($4)
    /* 3BE044 004BE044 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE048 004BE048 70541308 */  j          func_004d51c0
    /* 3BE04C 004BE04C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be038, 0x18
