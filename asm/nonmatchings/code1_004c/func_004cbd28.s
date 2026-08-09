.section .text
.set noat
.set noreorder
glabel func_004cbd28
    /* 3CBD28 004CBD28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CBD2C 004CBD2C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CBD30 004CBD30 0000BFDF */  ld         $31, 0x0($29)
    /* 3CBD34 004CBD34 C0851008 */  j          func_00421700
    /* 3CBD38 004CBD38 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CBD3C 004CBD3C 00000000 */  nop
.size func_004cbd28, 0x18
