.section .text
.set noat
.set noreorder
glabel func_0050cfe0
    /* 40CFE0 0050CFE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CFE4 0050CFE4 03000624 */  addiu      $6, $0, 0x3
    /* 40CFE8 0050CFE8 0000BFFF */  sd         $31, 0x0($29)
    /* 40CFEC 0050CFEC 0000BFDF */  ld         $31, 0x0($29)
    /* 40CFF0 0050CFF0 04341408 */  j          func_0050d010
    /* 40CFF4 0050CFF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050cfe0, 0x18
