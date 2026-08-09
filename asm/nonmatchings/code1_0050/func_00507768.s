.section .text
.set noat
.set noreorder
glabel func_00507768
    /* 407768 00507768 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40776C 0050776C 0000BFFF */  sd         $31, 0x0($29)
    /* 407770 00507770 0000BFDF */  ld         $31, 0x0($29)
    /* 407774 00507774 E01D1408 */  j          func_00507780
    /* 407778 00507778 1000BD27 */   addiu     $29, $29, 0x10
    /* 40777C 0050777C 00000000 */  nop
.size func_00507768, 0x18
