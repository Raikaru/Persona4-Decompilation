.section .text
.set noat
.set noreorder
glabel func_004de260
    /* 3DE260 004DE260 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE264 004DE264 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE268 004DE268 0000848C */  lw         $4, 0x0($4)
    /* 3DE26C 004DE26C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE270 004DE270 6E691308 */  j          func_004da5b8
    /* 3DE274 004DE274 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de260, 0x18
