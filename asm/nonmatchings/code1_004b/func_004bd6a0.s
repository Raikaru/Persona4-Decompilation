.section .text
.set noat
.set noreorder
glabel func_004bd6a0
    /* 3BD6A0 004BD6A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD6A4 004BD6A4 0000BFFF */  sd         $31, 0x0($29)
    /* 3BD6A8 004BD6A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD6AC 004BD6AC A61A1308 */  j          func_004c6a98
    /* 3BD6B0 004BD6B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD6B4 004BD6B4 00000000 */  nop
.size func_004bd6a0, 0x18
