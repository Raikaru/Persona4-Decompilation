.section .text
.set noat
.set noreorder
glabel func_0050e450
    /* 40E450 0050E450 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E454 0050E454 2D20A000 */  daddu      $4, $5, $0
    /* 40E458 0050E458 0000BFFF */  sd         $31, 0x0($29)
    /* 40E45C 0050E45C 0000BFDF */  ld         $31, 0x0($29)
    /* 40E460 0050E460 88441408 */  j          func_00511220
    /* 40E464 0050E464 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e450, 0x18
