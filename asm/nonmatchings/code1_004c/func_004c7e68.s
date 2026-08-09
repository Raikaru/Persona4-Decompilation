.section .text
.set noat
.set noreorder
glabel func_004c7e68
    /* 3C7E68 004C7E68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7E6C 004C7E6C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C7E70 004C7E70 4627130C */  jal        func_004c9d18
    /* 3C7E74 004C7E74 00000000 */   nop
    /* 3C7E78 004C7E78 A41F130C */  jal        func_004c7e90
    /* 3C7E7C 004C7E7C 00000000 */   nop
    /* 3C7E80 004C7E80 0000BFDF */  ld         $31, 0x0($29)
    /* 3C7E84 004C7E84 4C271308 */  j          func_004c9d30
    /* 3C7E88 004C7E88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C7E8C 004C7E8C 00000000 */  nop
.size func_004c7e68, 0x28
