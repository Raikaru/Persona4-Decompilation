.section .text
.set noat
.set noreorder
glabel func_00516d98
    /* 416D98 00516D98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 416D9C 00516D9C 9300053C */  lui        $5, %hi(D_00933D50)
    /* 416DA0 00516DA0 0000BFFF */  sd         $31, 0x0($29)
    /* 416DA4 00516DA4 20000424 */  addiu      $4, $0, 0x20
    /* 416DA8 00516DA8 503DA524 */  addiu      $5, $5, %lo(D_00933D50)
    /* 416DAC 00516DAC 0000BFDF */  ld         $31, 0x0($29)
    /* 416DB0 00516DB0 14A31408 */  j          func_00528c50
    /* 416DB4 00516DB4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00516d98, 0x20
