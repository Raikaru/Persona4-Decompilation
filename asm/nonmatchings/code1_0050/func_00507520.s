.section .text
.set noat
.set noreorder
glabel func_00507520
    /* 407520 00507520 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 407524 00507524 0000BFFF */  sd         $31, 0x0($29)
    /* 407528 00507528 B003848C */  lw         $4, 0x3B0($4)
    /* 40752C 0050752C 0000BFDF */  ld         $31, 0x0($29)
    /* 407530 00507530 A0EC1308 */  j          func_004fb280
    /* 407534 00507534 1000BD27 */   addiu     $29, $29, 0x10
.size func_00507520, 0x18
