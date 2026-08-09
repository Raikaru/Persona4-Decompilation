.section .text
.set noat
.set noreorder
glabel func_00515c60
    /* 415C60 00515C60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 415C64 00515C64 0000BFFF */  sd         $31, 0x0($29)
    /* 415C68 00515C68 2694140C */  jal        func_00525098
    /* 415C6C 00515C6C 31000524 */   addiu     $5, $0, 0x31
    /* 415C70 00515C70 0000BFDF */  ld         $31, 0x0($29)
    /* 415C74 00515C74 2B100200 */  sltu       $2, $0, $2
    /* 415C78 00515C78 0800E003 */  jr         $31
    /* 415C7C 00515C7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00515c60, 0x20
