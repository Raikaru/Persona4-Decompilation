.section .text
.set noat
.set noreorder
glabel func_004cd848
    /* 3CD848 004CD848 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD84C 004CD84C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD850 004CD850 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD854 004CD854 FCB31308 */  j          func_004ecff0
    /* 3CD858 004CD858 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD85C 004CD85C 00000000 */  nop
.size func_004cd848, 0x18
