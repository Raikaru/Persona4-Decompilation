.section .text
.set noat
.set noreorder
glabel func_004e9090
    /* 3E9090 004E9090 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E9094 004E9094 0F00083C */  lui        $8, (0xFFFFF >> 16)
    /* 3E9098 004E9098 0000BFFF */  sd         $31, 0x0($29)
    /* 3E909C 004E909C 2D300000 */  daddu      $6, $0, $0
    /* 3E90A0 004E90A0 2D380000 */  daddu      $7, $0, $0
    /* 3E90A4 004E90A4 FFFF0835 */  ori        $8, $8, (0xFFFFF & 0xFFFF)
    /* 3E90A8 004E90A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E90AC 004E90AC 2EA41308 */  j          func_004e90b8
    /* 3E90B0 004E90B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E90B4 004E90B4 00000000 */  nop
.size func_004e9090, 0x28
