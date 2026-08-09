.section .text
.set noat
.set noreorder
glabel func_00522e60
    /* 422E60 00522E60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 422E64 00522E64 03000524 */  addiu      $5, $0, 0x3
    /* 422E68 00522E68 0000BFFF */  sd         $31, 0x0($29)
    /* 422E6C 00522E6C 0000BFDF */  ld         $31, 0x0($29)
    /* 422E70 00522E70 069E1408 */  j          func_00527818
    /* 422E74 00522E74 1000BD27 */   addiu     $29, $29, 0x10
.size func_00522e60, 0x18
