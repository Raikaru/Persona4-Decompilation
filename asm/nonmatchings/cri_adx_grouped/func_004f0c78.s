.section .text
.set noat
.set noreorder
glabel func_004f0c78
    /* 3F0C78 004F0C78 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3F0C7C 004F0C7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F0C80 004F0C80 2D808000 */  daddu      $16, $4, $0
    /* 3F0C84 004F0C84 0800B1FF */  sd         $17, 0x8($29)
    /* 3F0C88 004F0C88 2D88A000 */  daddu      $17, $5, $0
    /* 3F0C8C 004F0C8C 1000B2FF */  sd         $18, 0x10($29)
    /* 3F0C90 004F0C90 2D90C000 */  daddu      $18, $6, $0
    /* 3F0C94 004F0C94 1800B3FF */  sd         $19, 0x18($29)
    /* 3F0C98 004F0C98 2D98E000 */  daddu      $19, $7, $0
    /* 3F0C9C 004F0C9C 2000B4FF */  sd         $20, 0x20($29)
    /* 3F0CA0 004F0CA0 2800BFFF */  sd         $31, 0x28($29)
    /* 3F0CA4 004F0CA4 82C1130C */  jal        func_004f0608
    /* 3F0CA8 004F0CA8 2DA00001 */   daddu     $20, $8, $0
    /* 3F0CAC 004F0CAC 2D200002 */  daddu      $4, $16, $0
    /* 3F0CB0 004F0CB0 2D282002 */  daddu      $5, $17, $0
    /* 3F0CB4 004F0CB4 2D304002 */  daddu      $6, $18, $0
    /* 3F0CB8 004F0CB8 2D386002 */  daddu      $7, $19, $0
    /* 3F0CBC 004F0CBC 3AC3130C */  jal        func_004f0ce8
    /* 3F0CC0 004F0CC0 2D408002 */   daddu     $8, $20, $0
    /* 3F0CC4 004F0CC4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0CC8 004F0CC8 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0CCC 004F0CCC 1000B2DF */  ld         $18, 0x10($29)
    /* 3F0CD0 004F0CD0 1800B3DF */  ld         $19, 0x18($29)
    /* 3F0CD4 004F0CD4 2000B4DF */  ld         $20, 0x20($29)
    /* 3F0CD8 004F0CD8 2800BFDF */  ld         $31, 0x28($29)
    /* 3F0CDC 004F0CDC 88C11308 */  j          func_004f0620
    /* 3F0CE0 004F0CE0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3F0CE4 004F0CE4 00000000 */  nop
.size func_004f0c78, 0x70
