.section .text
.set noat
.set noreorder
glabel func_004de2c0
    /* 3DE2C0 004DE2C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE2C4 004DE2C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE2C8 004DE2C8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE2CC 004DE2CC A61A1308 */  j          func_004c6a98
    /* 3DE2D0 004DE2D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DE2D4 004DE2D4 00000000 */  nop
.size func_004de2c0, 0x18
