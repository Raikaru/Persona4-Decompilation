.section .text
.set noat
.set noreorder
glabel func_0050c8f8
    /* 40C8F8 0050C8F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C8FC 0050C8FC 0000BFFF */  sd         $31, 0x0($29)
    /* 40C900 0050C900 3C00848C */  lw         $4, 0x3C($4)
    /* 40C904 0050C904 0000BFDF */  ld         $31, 0x0($29)
    /* 40C908 0050C908 A24F1408 */  j          func_00513e88
    /* 40C90C 0050C90C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050c8f8, 0x18
