.section .text
.set noat
.set noreorder
glabel func_004de290
    /* 3DE290 004DE290 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE294 004DE294 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE298 004DE298 0000848C */  lw         $4, 0x0($4)
    /* 3DE29C 004DE29C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE2A0 004DE2A0 46691308 */  j          func_004da518
    /* 3DE2A4 004DE2A4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de290, 0x18
