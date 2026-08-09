.section .text
.set noat
.set noreorder
glabel func_004de248
    /* 3DE248 004DE248 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE24C 004DE24C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE250 004DE250 0000848C */  lw         $4, 0x0($4)
    /* 3DE254 004DE254 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE258 004DE258 5C691308 */  j          func_004da570
    /* 3DE25C 004DE25C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de248, 0x18
