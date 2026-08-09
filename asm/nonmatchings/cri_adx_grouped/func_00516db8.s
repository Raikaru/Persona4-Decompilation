.section .text
.set noat
.set noreorder
glabel func_00516db8
    /* 416DB8 00516DB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 416DBC 00516DBC 0000BFFF */  sd         $31, 0x0($29)
    /* 416DC0 00516DC0 0000BFDF */  ld         $31, 0x0($29)
    /* 416DC4 00516DC4 38A31408 */  j          func_00528ce0
    /* 416DC8 00516DC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 416DCC 00516DCC 00000000 */  nop
.size func_00516db8, 0x18
