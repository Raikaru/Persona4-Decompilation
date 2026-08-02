.section .text
.set noat
.set noreorder
glabel func_004f2398
    /* 3F2398 004F2398 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F239C 004F239C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F23A0 004F23A0 2D808000 */  daddu      $16, $4, $0
    /* 3F23A4 004F23A4 0800B1FF */  sd         $17, 0x8($29)
    /* 3F23A8 004F23A8 2D88A000 */  daddu      $17, $5, $0
    /* 3F23AC 004F23AC 1000B2FF */  sd         $18, 0x10($29)
    /* 3F23B0 004F23B0 1800BFFF */  sd         $31, 0x18($29)
    /* 3F23B4 004F23B4 28D5130C */  jal        func_004f54a0
    /* 3F23B8 004F23B8 2D90C000 */   daddu     $18, $6, $0
    /* 3F23BC 004F23BC 1800BFDF */  ld         $31, 0x18($29)
    /* 3F23C0 004F23C0 2D200002 */  daddu      $4, $16, $0
    /* 3F23C4 004F23C4 2D282002 */  daddu      $5, $17, $0
    /* 3F23C8 004F23C8 0800B1DF */  ld         $17, 0x8($29)
    /* 3F23CC 004F23CC 2D304002 */  daddu      $6, $18, $0
    /* 3F23D0 004F23D0 1000B2DF */  ld         $18, 0x10($29)
    /* 3F23D4 004F23D4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F23D8 004F23D8 A8C61308 */  j          func_004f1aa0
    /* 3F23DC 004F23DC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004f2398, 0x48
