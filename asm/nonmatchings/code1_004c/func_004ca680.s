.section .text
.set noat
.set noreorder
glabel func_004ca680
    /* 3CA680 004CA680 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA684 004CA684 2D20A000 */  daddu      $4, $5, $0
    /* 3CA688 004CA688 0000BFFF */  sd         $31, 0x0($29)
    /* 3CA68C 004CA68C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CA690 004CA690 A61A1308 */  j          func_004c6a98
    /* 3CA694 004CA694 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca680, 0x18
