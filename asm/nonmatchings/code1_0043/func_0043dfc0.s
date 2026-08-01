.section .text
.set noat
.set noreorder
glabel func_0043dfc0
    /* 33DFC0 0043DFC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33DFC4 0043DFC4 71000F3C */  lui        $15, %hi(D_00710070)
    /* 33DFC8 0043DFC8 0000BFFF */  sd         $31, 0x0($29)
    /* 33DFCC 0043DFCC 7000E48D */  lw         $4, %lo(D_00710070)($15)
    /* 33DFD0 0043DFD0 0000BFDF */  ld         $31, 0x0($29)
    /* 33DFD4 0043DFD4 E8F71008 */  j          func_0043DFA0
    /* 33DFD8 0043DFD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 33DFDC 0043DFDC 00000000 */  nop
.size func_0043dfc0, 0x20
