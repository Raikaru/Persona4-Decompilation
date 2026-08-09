.section .text
.set noat
.set noreorder
glabel func_00528b78
    /* 428B78 00528B78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 428B7C 00528B7C 00FF053C */  lui        $5, (0xFF000701 >> 16)
    /* 428B80 00528B80 0000BFFF */  sd         $31, 0x0($29)
    /* 428B84 00528B84 0107A534 */  ori        $5, $5, (0xFF000701 & 0xFFFF)
    /* 428B88 00528B88 0000BFDF */  ld         $31, 0x0($29)
    /* 428B8C 00528B8C B45E1408 */  j          func_00517ad0
    /* 428B90 00528B90 1000BD27 */   addiu     $29, $29, 0x10
    /* 428B94 00528B94 00000000 */  nop
.size func_00528b78, 0x20
