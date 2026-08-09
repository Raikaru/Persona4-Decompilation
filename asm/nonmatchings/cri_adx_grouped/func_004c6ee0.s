.section .text
.set noat
.set noreorder
glabel func_004c6ee0
    /* 3C6EE0 004C6EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6EE4 004C6EE4 7500043C */  lui        $4, %hi(D_00757EF8)
    /* 3C6EE8 004C6EE8 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6EEC 004C6EEC 5000053C */  lui        $5, %hi(func_004f8518)
    /* 3C6EF0 004C6EF0 F87E8424 */  addiu      $4, $4, %lo(D_00757EF8)
    /* 3C6EF4 004C6EF4 1885A524 */  addiu      $5, $5, %lo(func_004f8518)
    /* 3C6EF8 004C6EF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6EFC 004C6EFC 2D300000 */  daddu      $6, $0, $0
    /* 3C6F00 004C6F00 E8851308 */  j          func_004e17a0
    /* 3C6F04 004C6F04 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c6ee0, 0x28
