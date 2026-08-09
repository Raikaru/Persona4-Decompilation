.section .text
.set noat
.set noreorder
glabel func_004eac58
    /* 3EAC58 004EAC58 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EAC5C 004EAC5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EAC60 004EAC60 2D808000 */  daddu      $16, $4, $0
    /* 3EAC64 004EAC64 0800B1FF */  sd         $17, 0x8($29)
    /* 3EAC68 004EAC68 2D88A000 */  daddu      $17, $5, $0
    /* 3EAC6C 004EAC6C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EAC70 004EAC70 2D90C000 */  daddu      $18, $6, $0
    /* 3EAC74 004EAC74 1800B3FF */  sd         $19, 0x18($29)
    /* 3EAC78 004EAC78 2000BFFF */  sd         $31, 0x20($29)
    /* 3EAC7C 004EAC7C C4A9130C */  jal        func_004ea710
    /* 3EAC80 004EAC80 2D98E000 */   daddu     $19, $7, $0
    /* 3EAC84 004EAC84 2D200002 */  daddu      $4, $16, $0
    /* 3EAC88 004EAC88 2D282002 */  daddu      $5, $17, $0
    /* 3EAC8C 004EAC8C 2D304002 */  daddu      $6, $18, $0
    /* 3EAC90 004EAC90 2EAB130C */  jal        func_004eacb8
    /* 3EAC94 004EAC94 2D386002 */   daddu     $7, $19, $0
    /* 3EAC98 004EAC98 0000B0DF */  ld         $16, 0x0($29)
    /* 3EAC9C 004EAC9C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EACA0 004EACA0 1000B2DF */  ld         $18, 0x10($29)
    /* 3EACA4 004EACA4 1800B3DF */  ld         $19, 0x18($29)
    /* 3EACA8 004EACA8 2000BFDF */  ld         $31, 0x20($29)
    /* 3EACAC 004EACAC CAA91308 */  j          func_004ea728
    /* 3EACB0 004EACB0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3EACB4 004EACB4 00000000 */  nop
.size func_004eac58, 0x60
