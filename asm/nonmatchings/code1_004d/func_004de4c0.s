.section .text
.set noat
.set noreorder
glabel func_004de4c0
    /* 3DE4C0 004DE4C0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3DE4C4 004DE4C4 1000B0FF */  sd         $16, 0x10($29)
    /* 3DE4C8 004DE4C8 2D80A000 */  daddu      $16, $5, $0
    /* 3DE4CC 004DE4CC 1800B1FF */  sd         $17, 0x18($29)
    /* 3DE4D0 004DE4D0 2D888000 */  daddu      $17, $4, $0
    /* 3DE4D4 004DE4D4 2800B3FF */  sd         $19, 0x28($29)
    /* 3DE4D8 004DE4D8 2D98C000 */  daddu      $19, $6, $0
    /* 3DE4DC 004DE4DC 2D20A003 */  daddu      $4, $29, $0
    /* 3DE4E0 004DE4E0 2D280000 */  daddu      $5, $0, $0
    /* 3DE4E4 004DE4E4 0C000624 */  addiu      $6, $0, 0xC
    /* 3DE4E8 004DE4E8 2000B2FF */  sd         $18, 0x20($29)
    /* 3DE4EC 004DE4EC 3000BFFF */  sd         $31, 0x30($29)
    /* 3DE4F0 004DE4F0 72FE100C */  jal        func_0043f9c8
    /* 3DE4F4 004DE4F4 2D90E000 */   daddu     $18, $7, $0
    /* 3DE4F8 004DE4F8 0000B1AF */  sw         $17, 0x0($29)
    /* 3DE4FC 004DE4FC 0400B0AF */  sw         $16, 0x4($29)
    /* 3DE500 004DE500 E080130C */  jal        func_004e0380
    /* 3DE504 004DE504 0800A0AF */   sw        $0, 0x8($29)
    /* 3DE508 004DE508 2D20A003 */  daddu      $4, $29, $0
    /* 3DE50C 004DE50C 2D286002 */  daddu      $5, $19, $0
    /* 3DE510 004DE510 7079130C */  jal        func_004de5c0
    /* 3DE514 004DE514 2D304002 */   daddu     $6, $18, $0
    /* 3DE518 004DE518 E680130C */  jal        func_004e0398
    /* 3DE51C 004DE51C 2D804000 */   daddu     $16, $2, $0
    /* 3DE520 004DE520 1800B1DF */  ld         $17, 0x18($29)
    /* 3DE524 004DE524 2D100002 */  daddu      $2, $16, $0
    /* 3DE528 004DE528 2000B2DF */  ld         $18, 0x20($29)
    /* 3DE52C 004DE52C 1000B0DF */  ld         $16, 0x10($29)
    /* 3DE530 004DE530 2800B3DF */  ld         $19, 0x28($29)
    /* 3DE534 004DE534 3000BFDF */  ld         $31, 0x30($29)
    /* 3DE538 004DE538 0800E003 */  jr         $31
    /* 3DE53C 004DE53C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004de4c0, 0x80
