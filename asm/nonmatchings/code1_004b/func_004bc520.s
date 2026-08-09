.section .text
.set noat
.set noreorder
glabel func_004bc520
    /* 3BC520 004BC520 2C0081C4 */  lwc1       $f1, 0x2C($4)
    /* 3BC524 004BC524 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 3BC528 004BC528 00080046 */  add.s      $f0, $f1, $f0
    /* 3BC52C 004BC52C 2C0080E4 */  swc1       $f0, 0x2C($4)
    /* 3BC530 004BC530 0800E003 */  jr         $31
    /* 3BC534 004BC534 00000000 */   nop
    /* 3BC538 004BC538 00000000 */  nop
    /* 3BC53C 004BC53C 00000000 */  nop
.size func_004bc520, 0x20
