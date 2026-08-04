.section .text
.set noat
.set noreorder
glabel func_003e3f00
    /* 2E3F00 003E3F00 0000A5C4 */  lwc1       $f5, 0x0($5)
    /* 2E3F04 003E3F04 2D108000 */  daddu      $2, $4, $0
    /* 2E3F08 003E3F08 0400C2C4 */  lwc1       $f2, 0x4($6)
    /* 2E3F0C 003E3F0C 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* 2E3F10 003E3F10 0000C4C4 */  lwc1       $f4, 0x0($6)
    /* 2E3F14 003E3F14 0400A8C4 */  lwc1       $f8, 0x4($5)
    /* 2E3F18 003E3F18 1000C0C4 */  lwc1       $f0, 0x10($6)
    /* 2E3F1C 003E3F1C 00308044 */  mtc1       $0, $f6
    /* 2E3F20 003E3F20 82280246 */  mul.s      $f2, $f5, $f2
    /* 2E3F24 003E3F24 1A280446 */  mula.s     $f5, $f4
    /* 2E3F28 003E3F28 422A0146 */  mul.s      $f9, $f5, $f1
    /* 2E3F2C 003E3F2C DC410046 */  madd.s     $f7, $f8, $f0
    /* 2E3F30 003E3F30 18300246 */  adda.s     $f6, $f2
    /* 2E3F34 003E3F34 1400C5C4 */  lwc1       $f5, 0x14($6)
    /* 2E3F38 003E3F38 1800C4C4 */  lwc1       $f4, 0x18($6)
    /* 2E3F3C 003E3F3C 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2E3F40 003E3F40 2000C2C4 */  lwc1       $f2, 0x20($6)
    /* 2E3F44 003E3F44 2400C1C4 */  lwc1       $f1, 0x24($6)
    /* 2E3F48 003E3F48 2800C0C4 */  lwc1       $f0, 0x28($6)
    /* 2E3F4C 003E3F4C 5C410546 */  madd.s     $f5, $f8, $f5
    /* 2E3F50 003E3F50 18300946 */  adda.s     $f6, $f9
    /* 2E3F54 003E3F54 1C410446 */  madd.s     $f4, $f8, $f4
    /* 2E3F58 003E3F58 18300746 */  adda.s     $f6, $f7
    /* 2E3F5C 003E3F5C 9C180246 */  madd.s     $f2, $f3, $f2
    /* 2E3F60 003E3F60 18300546 */  adda.s     $f6, $f5
    /* 2E3F64 003E3F64 5C180146 */  madd.s     $f1, $f3, $f1
    /* 2E3F68 003E3F68 000082E4 */  swc1       $f2, 0x0($4)
    /* 2E3F6C 003E3F6C 18300446 */  adda.s     $f6, $f4
    /* 2E3F70 003E3F70 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2E3F74 003E3F74 040081E4 */  swc1       $f1, 0x4($4)
    /* 2E3F78 003E3F78 0800E003 */  jr         $31
    /* 2E3F7C 003E3F7C 080080E4 */   swc1      $f0, 0x8($4)
.size func_003e3f00, 0x80
