.section .text
.set noat
.set noreorder
glabel func_004de218
    /* 3DE218 004DE218 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE21C 004DE21C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE220 004DE220 0000848C */  lw         $4, 0x0($4)
    /* 3DE224 004DE224 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE228 004DE228 4C691308 */  j          func_004da530
    /* 3DE22C 004DE22C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de218, 0x18
