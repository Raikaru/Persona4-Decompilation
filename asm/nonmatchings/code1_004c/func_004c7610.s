.section .text
.set noat
.set noreorder
glabel func_004c7610
    /* 3C7610 004C7610 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7614 004C7614 71000A3C */  lui        $10, %hi(D_007167C8)
    /* 3C7618 004C7618 0000BFFF */  sd         $31, 0x0($29)
    /* 3C761C 004C761C C0FF0224 */  addiu      $2, $0, -0x40
    /* 3C7620 004C7620 C8674A25 */  addiu      $10, $10, %lo(D_007167C8)
    /* 3C7624 004C7624 00080B24 */  addiu      $11, $0, 0x800
    /* 3C7628 004C7628 0000BFDF */  ld         $31, 0x0($29)
    /* 3C762C 004C762C 24504201 */  and        $10, $10, $2
    /* 3C7630 004C7630 8E1D1308 */  j          func_004c7638
    /* 3C7634 004C7634 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7610, 0x28
