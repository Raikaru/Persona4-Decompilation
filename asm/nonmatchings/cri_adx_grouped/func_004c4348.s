.section .text
.set noat
.set noreorder
glabel func_004c4348
    /* 3C4348 004C4348 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C434C 004C434C 40280500 */  sll        $5, $5, 1
    /* 3C4350 004C4350 0000BFFF */  sd         $31, 0x0($29)
    /* 3C4354 004C4354 2D30E000 */  daddu      $6, $7, $0
    /* 3C4358 004C4358 21288500 */  addu       $5, $4, $5
    /* 3C435C 004C435C 0000BFDF */  ld         $31, 0x0($29)
    /* 3C4360 004C4360 AA101308 */  j          func_004c42a8
    /* 3C4364 004C4364 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c4348, 0x20
