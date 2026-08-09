.section .text
.set noat
.set noreorder
glabel func_00507db0
    /* 407DB0 00507DB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 407DB4 00507DB4 0000BFFF */  sd         $31, 0x0($29)
    /* 407DB8 00507DB8 0000BFDF */  ld         $31, 0x0($29)
    /* 407DBC 00507DBC 721F1408 */  j          func_00507dc8
    /* 407DC0 00507DC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 407DC4 00507DC4 00000000 */  nop
.size func_00507db0, 0x18
