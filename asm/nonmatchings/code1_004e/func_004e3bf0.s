.section .text
.set noat
.set noreorder
glabel func_004e3bf0
    /* 3E3BF0 004E3BF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E3BF4 004E3BF4 7300043C */  lui        $4, %hi(D_00731C00)
    /* 3E3BF8 004E3BF8 0000BFFF */  sd         $31, 0x0($29)
    /* 3E3BFC 004E3BFC 001C8424 */  addiu      $4, $4, %lo(D_00731C00)
    /* 3E3C00 004E3C00 0000BFDF */  ld         $31, 0x0($29)
    /* 3E3C04 004E3C04 B88E1308 */  j          func_004e3ae0
    /* 3E3C08 004E3C08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E3C0C 004E3C0C 00000000 */  nop
.size func_004e3bf0, 0x20
