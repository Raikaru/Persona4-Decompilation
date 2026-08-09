.section .text
.set noat
.set noreorder
glabel func_004eb300
    /* 3EB300 004EB300 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EB304 004EB304 2D20A000 */  daddu      $4, $5, $0
    /* 3EB308 004EB308 0000BFFF */  sd         $31, 0x0($29)
    /* 3EB30C 004EB30C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB310 004EB310 A61A1308 */  j          func_004c6a98
    /* 3EB314 004EB314 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eb300, 0x18
