.section .text
.set noat
.set noreorder
glabel func_004d2af0
    /* 3D2AF0 004D2AF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2AF4 004D2AF4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D2AF8 004D2AF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D2AFC 004D2AFC A6881308 */  j          func_004e2298
    /* 3D2B00 004D2B00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D2B04 004D2B04 00000000 */  nop
.size func_004d2af0, 0x18
