.section .text
.set noat
.set noreorder
glabel func_004cd638
    /* 3CD638 004CD638 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD63C 004CD63C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD640 004CD640 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD644 004CD644 C0B01308 */  j          func_004ec300
    /* 3CD648 004CD648 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD64C 004CD64C 00000000 */  nop
.size func_004cd638, 0x18
