.section .text
.set noat
.set noreorder
glabel func_004f06f8
    /* 3F06F8 004F06F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F06FC 004F06FC 05000424 */  addiu      $4, $0, 0x5
    /* 3F0700 004F0700 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0704 004F0704 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0708 004F0708 5EC11308 */  j          func_004f0578
    /* 3F070C 004F070C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f06f8, 0x18
