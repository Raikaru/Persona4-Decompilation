.section .text
.set noat
.set noreorder
glabel func_003d5300
    /* 2D5300 003D5300 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D5304 003D5304 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2D5308 003D5308 0000BFFF */  sd         $31, 0x0($29)
    /* 2D530C 003D530C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2D5310 003D5310 09F84000 */  jalr       $2
    /* 2D5314 003D5314 00000000 */   nop
    /* 2D5318 003D5318 0000BFDF */  ld         $31, 0x0($29)
    /* 2D531C 003D531C 01000224 */  addiu      $2, $0, 0x1
    /* 2D5320 003D5320 0800E003 */  jr         $31
    /* 2D5324 003D5324 1000BD27 */   addiu     $29, $29, 0x10
    /* 2D5328 003D5328 00000000 */  nop
    /* 2D532C 003D532C 00000000 */  nop
.size func_003d5300, 0x30
