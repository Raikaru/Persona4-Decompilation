.section .text
.set noat
.set noreorder
glabel func_00528b98
    /* 428B98 00528B98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 428B9C 00528B9C 00FF053C */  lui        $5, (0xFF000701 >> 16)
    /* 428BA0 00528BA0 0000BFFF */  sd         $31, 0x0($29)
    /* 428BA4 00528BA4 0107A534 */  ori        $5, $5, (0xFF000701 & 0xFFFF)
    /* 428BA8 00528BA8 0000BFDF */  ld         $31, 0x0($29)
    /* 428BAC 00528BAC B45E1408 */  j          func_00517ad0
    /* 428BB0 00528BB0 1000BD27 */   addiu     $29, $29, 0x10
    /* 428BB4 00528BB4 00000000 */  nop
.size func_00528b98, 0x20
