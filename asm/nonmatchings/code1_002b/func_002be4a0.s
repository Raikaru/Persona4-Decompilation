.section .text
.set noat
.set noreorder
glabel func_002be4a0
    /* 1BE4A0 002BE4A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BE4A4 002BE4A4 0000BFFF */  sd         $31, 0x0($29)
    /* 1BE4A8 002BE4A8 989E0B0C */  jal        func_002e7a60
    /* 1BE4AC 002BE4AC 00000000 */   nop
    /* 1BE4B0 002BE4B0 2D204000 */  daddu      $4, $2, $0
    /* 1BE4B4 002BE4B4 5CCC0A0C */  jal        func_002b3170
    /* 1BE4B8 002BE4B8 00000000 */   nop
    /* 1BE4BC 002BE4BC 00008244 */  mtc1       $2, $f0
    /* 1BE4C0 002BE4C0 00000000 */  nop
    /* 1BE4C4 002BE4C4 E0008046 */  cvt.s.w    $f3, $f0
    /* 1BE4C8 002BE4C8 A841023C */  lui        $2, (0x41A80000 >> 16)
    /* 1BE4CC 002BE4CC 00108244 */  mtc1       $2, $f2
    /* 1BE4D0 002BE4D0 1144023C */  lui        $2, (0x44110000 >> 16)
    /* 1BE4D4 002BE4D4 00088244 */  mtc1       $2, $f1
    /* 1BE4D8 002BE4D8 00008044 */  mtc1       $0, $f0
    /* 1BE4DC 002BE4DC 00000000 */  nop
    /* 1BE4E0 002BE4E0 18000146 */  adda.s     $f0, $f1
    /* 1BE4E4 002BE4E4 1D130346 */  msub.s     $f12, $f2, $f3
    /* 1BE4E8 002BE4E8 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 1BE4EC 002BE4EC 00688244 */  mtc1       $2, $f13
    /* 1BE4F0 002BE4F0 1800A427 */  addiu      $4, $29, 0x18
    /* 1BE4F4 002BE4F4 5CCA0A0C */  jal        func_002b2970
    /* 1BE4F8 002BE4F8 00000000 */   nop
    /* 1BE4FC 002BE4FC 989E0B0C */  jal        func_002e7a60
    /* 1BE500 002BE500 00000000 */   nop
    /* 1BE504 002BE504 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1BE508 002BE508 00608344 */  mtc1       $3, $f12
    /* 1BE50C 002BE50C 1800A4DF */  ld         $4, 0x18($29)
    /* 1BE510 002BE510 FF000524 */  addiu      $5, $0, 0xFF
    /* 1BE514 002BE514 2D304000 */  daddu      $6, $2, $0
    /* 1BE518 002BE518 C8900D0C */  jal        func_00364320
    /* 1BE51C 002BE51C 00000000 */   nop
    /* 1BE520 002BE520 0000BFDF */  ld         $31, 0x0($29)
    /* 1BE524 002BE524 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BE528 002BE528 0800E003 */  jr         $31
    /* 1BE52C 002BE52C 00000000 */   nop
.size func_002be4a0, 0x90
