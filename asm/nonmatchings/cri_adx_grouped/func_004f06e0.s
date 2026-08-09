.section .text
.set noat
.set noreorder
glabel func_004f06e0
    /* 3F06E0 004F06E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F06E4 004F06E4 04000424 */  addiu      $4, $0, 0x4
    /* 3F06E8 004F06E8 0000BFFF */  sd         $31, 0x0($29)
    /* 3F06EC 004F06EC 0000BFDF */  ld         $31, 0x0($29)
    /* 3F06F0 004F06F0 5EC11308 */  j          func_004f0578
    /* 3F06F4 004F06F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f06e0, 0x18
