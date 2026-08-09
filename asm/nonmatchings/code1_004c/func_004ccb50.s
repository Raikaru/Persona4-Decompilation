.section .text
.set noat
.set noreorder
glabel func_004ccb50
    /* 3CCB50 004CCB50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCB54 004CCB54 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCB58 004CCB58 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCB5C 004CCB5C B42C1308 */  j          func_004cb2d0
    /* 3CCB60 004CCB60 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCB64 004CCB64 00000000 */  nop
.size func_004ccb50, 0x18
