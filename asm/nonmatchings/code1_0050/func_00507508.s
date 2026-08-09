.section .text
.set noat
.set noreorder
glabel func_00507508
    /* 407508 00507508 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40750C 0050750C 0000BFFF */  sd         $31, 0x0($29)
    /* 407510 00507510 0000BFDF */  ld         $31, 0x0($29)
    /* 407514 00507514 94EC1308 */  j          func_004fb250
    /* 407518 00507518 1000BD27 */   addiu     $29, $29, 0x10
    /* 40751C 0050751C 00000000 */  nop
.size func_00507508, 0x18
