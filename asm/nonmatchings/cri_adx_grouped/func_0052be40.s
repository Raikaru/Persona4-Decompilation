.section .text
.set noat
.set noreorder
glabel func_0052be40
    /* 42BE40 0052BE40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42BE44 0052BE44 0000B0FF */  sd         $16, 0x0($29)
    /* 42BE48 0052BE48 2D80A000 */  daddu      $16, $5, $0
    /* 42BE4C 0052BE4C 0800B1FF */  sd         $17, 0x8($29)
    /* 42BE50 0052BE50 2D888000 */  daddu      $17, $4, $0
    /* 42BE54 0052BE54 2D200002 */  daddu      $4, $16, $0
    /* 42BE58 0052BE58 1000BFFF */  sd         $31, 0x10($29)
    /* 42BE5C 0052BE5C D8E6130C */  jal        func_004f9b60
    /* 42BE60 0052BE60 FF001032 */   andi      $16, $16, 0xFF
    /* 42BE64 0052BE64 2D202002 */  daddu      $4, $17, $0
    /* 42BE68 0052BE68 B8AE140C */  jal        func_0052bae0
    /* 42BE6C 0052BE6C 2D280000 */   daddu     $5, $0, $0
    /* 42BE70 0052BE70 2D202002 */  daddu      $4, $17, $0
    /* 42BE74 0052BE74 2D380002 */  daddu      $7, $16, $0
    /* 42BE78 0052BE78 42301000 */  srl        $6, $16, 1
    /* 42BE7C 0052BE7C 0800B1DF */  ld         $17, 0x8($29)
    /* 42BE80 0052BE80 2D280000 */  daddu      $5, $0, $0
    /* 42BE84 0052BE84 0000B0DF */  ld         $16, 0x0($29)
    /* 42BE88 0052BE88 1000BFDF */  ld         $31, 0x10($29)
    /* 42BE8C 0052BE8C 16AF1408 */  j          func_0052bc58
    /* 42BE90 0052BE90 2000BD27 */   addiu     $29, $29, 0x20
    /* 42BE94 0052BE94 00000000 */  nop
.size func_0052be40, 0x58
