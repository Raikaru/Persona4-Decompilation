.section .text
.set noat
.set noreorder
glabel func_0043c6b0
    /* 33C6B0 0043C6B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33C6B4 0043C6B4 2D280000 */  daddu      $5, $0, $0
    /* 33C6B8 0043C6B8 0000BFFF */  sd         $31, 0x0($29)
    /* 33C6BC 0043C6BC 8410110C */  jal        func_00444210
    /* 33C6C0 0043C6C0 0A000624 */   addiu     $6, $0, 0xA
    /* 33C6C4 0043C6C4 3C100200 */  dsll32     $2, $2, 0
    /* 33C6C8 0043C6C8 0000BFDF */  ld         $31, 0x0($29)
    /* 33C6CC 0043C6CC 3F100200 */  dsra32     $2, $2, 0
    /* 33C6D0 0043C6D0 0800E003 */  jr         $31
    /* 33C6D4 0043C6D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043c6b0, 0x28
