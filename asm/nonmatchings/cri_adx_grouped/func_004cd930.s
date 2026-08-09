.section .text
.set noat
.set noreorder
glabel func_004cd930
    /* 3CD930 004CD930 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD934 004CD934 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD938 004CD938 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD93C 004CD93C 84B21308 */  j          func_004eca10
    /* 3CD940 004CD940 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD944 004CD944 00000000 */  nop
.size func_004cd930, 0x18
