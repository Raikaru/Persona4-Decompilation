.section .text
.set noat
.set noreorder
glabel func_004c34e8
    /* 3C34E8 004C34E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C34EC 004C34EC 2D108000 */  daddu      $2, $4, $0
    /* 3C34F0 004C34F0 0000BFFF */  sd         $31, 0x0($29)
    /* 3C34F4 004C34F4 80FF0324 */  addiu      $3, $0, -0x80
    /* 3C34F8 004C34F8 D0004424 */  addiu      $4, $2, 0xD0
    /* 3C34FC 004C34FC 2D280000 */  daddu      $5, $0, $0
    /* 3C3500 004C3500 0000BFDF */  ld         $31, 0x0($29)
    /* 3C3504 004C3504 10000624 */  addiu      $6, $0, 0x10
    /* 3C3508 004C3508 E40043A4 */  sh         $3, 0xE4($2)
    /* 3C350C 004C350C CC0040AC */  sw         $0, 0xCC($2)
    /* 3C3510 004C3510 E00040A4 */  sh         $0, 0xE0($2)
    /* 3C3514 004C3514 E20043A4 */  sh         $3, 0xE2($2)
    /* 3C3518 004C3518 72FE1008 */  j          func_0043f9c8
    /* 3C351C 004C351C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c34e8, 0x38
