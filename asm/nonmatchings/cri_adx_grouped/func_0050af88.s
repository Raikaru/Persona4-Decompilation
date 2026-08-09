.section .text
.set noat
.set noreorder
glabel func_0050af88
    /* 40AF88 0050AF88 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40AF8C 0050AF8C 1000BFFF */  sd         $31, 0x10($29)
    /* 40AF90 0050AF90 E8A5140C */  jal        func_005297a0
    /* 40AF94 0050AF94 2D28A003 */   daddu     $5, $29, $0
    /* 40AF98 0050AF98 01000324 */  addiu      $3, $0, 0x1
    /* 40AF9C 0050AF9C 0000A58F */  lw         $5, 0x0($29)
    /* 40AFA0 0050AFA0 26204300 */  xor        $4, $2, $3
    /* 40AFA4 0050AFA4 1000BFDF */  ld         $31, 0x10($29)
    /* 40AFA8 0050AFA8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 40AFAC 0050AFAC 0A10A400 */  movz       $2, $5, $4
    /* 40AFB0 0050AFB0 0800E003 */  jr         $31
    /* 40AFB4 0050AFB4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050af88, 0x30
