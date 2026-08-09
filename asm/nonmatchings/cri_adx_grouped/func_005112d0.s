.section .text
.set noat
.set noreorder
glabel func_005112d0
    /* 4112D0 005112D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4112D4 005112D4 0000BFFF */  sd         $31, 0x0($29)
    /* 4112D8 005112D8 0000BFDF */  ld         $31, 0x0($29)
    /* 4112DC 005112DC 80301308 */  j          func_004cc200
    /* 4112E0 005112E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4112E4 005112E4 00000000 */  nop
.size func_005112d0, 0x18
