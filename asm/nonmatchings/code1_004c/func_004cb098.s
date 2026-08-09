.section .text
.set noat
.set noreorder
glabel func_004cb098
    /* 3CB098 004CB098 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CB09C 004CB09C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB0A0 004CB0A0 2D808000 */  daddu      $16, $4, $0
    /* 3CB0A4 004CB0A4 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB0A8 004CB0A8 2D88A000 */  daddu      $17, $5, $0
    /* 3CB0AC 004CB0AC 1000B2FF */  sd         $18, 0x10($29)
    /* 3CB0B0 004CB0B0 1800BFFF */  sd         $31, 0x18($29)
    /* 3CB0B4 004CB0B4 3615130C */  jal        func_004c54d8
    /* 3CB0B8 004CB0B8 2D90C000 */   daddu     $18, $6, $0
    /* 3CB0BC 004CB0BC 2D200002 */  daddu      $4, $16, $0
    /* 3CB0C0 004CB0C0 2D282002 */  daddu      $5, $17, $0
    /* 3CB0C4 004CB0C4 3A2C130C */  jal        func_004cb0e8
    /* 3CB0C8 004CB0C8 2D304002 */   daddu     $6, $18, $0
    /* 3CB0CC 004CB0CC 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB0D0 004CB0D0 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB0D4 004CB0D4 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB0D8 004CB0D8 1800BFDF */  ld         $31, 0x18($29)
    /* 3CB0DC 004CB0DC 38151308 */  j          func_004c54e0
    /* 3CB0E0 004CB0E0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CB0E4 004CB0E4 00000000 */  nop
.size func_004cb098, 0x50
