.section .text
.set noat
.set noreorder
glabel func_004e73a8
    /* 3E73A8 004E73A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E73AC 004E73AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3E73B0 004E73B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3E73B4 004E73B4 A2911308 */  j          func_004e4688
    /* 3E73B8 004E73B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E73BC 004E73BC 00000000 */  nop
.size func_004e73a8, 0x18
