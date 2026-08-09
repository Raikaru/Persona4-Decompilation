.section .text
.set noat
.set noreorder
glabel func_004edd68
    /* 3EDD68 004EDD68 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EDD6C 004EDD6C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EDD70 004EDD70 2D808000 */  daddu      $16, $4, $0
    /* 3EDD74 004EDD74 0800B1FF */  sd         $17, 0x8($29)
    /* 3EDD78 004EDD78 2D88A000 */  daddu      $17, $5, $0
    /* 3EDD7C 004EDD7C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EDD80 004EDD80 2D90C000 */  daddu      $18, $6, $0
    /* 3EDD84 004EDD84 1800B3FF */  sd         $19, 0x18($29)
    /* 3EDD88 004EDD88 2000BFFF */  sd         $31, 0x20($29)
    /* 3EDD8C 004EDD8C 14B5130C */  jal        func_004ed450
    /* 3EDD90 004EDD90 2D98E000 */   daddu     $19, $7, $0
    /* 3EDD94 004EDD94 2D200002 */  daddu      $4, $16, $0
    /* 3EDD98 004EDD98 2D282002 */  daddu      $5, $17, $0
    /* 3EDD9C 004EDD9C 2D304002 */  daddu      $6, $18, $0
    /* 3EDDA0 004EDDA0 74B7130C */  jal        func_004eddd0
    /* 3EDDA4 004EDDA4 2D386002 */   daddu     $7, $19, $0
    /* 3EDDA8 004EDDA8 1AB5130C */  jal        func_004ed468
    /* 3EDDAC 004EDDAC 2D804000 */   daddu     $16, $2, $0
    /* 3EDDB0 004EDDB0 0800B1DF */  ld         $17, 0x8($29)
    /* 3EDDB4 004EDDB4 2D100002 */  daddu      $2, $16, $0
    /* 3EDDB8 004EDDB8 1000B2DF */  ld         $18, 0x10($29)
    /* 3EDDBC 004EDDBC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EDDC0 004EDDC0 1800B3DF */  ld         $19, 0x18($29)
    /* 3EDDC4 004EDDC4 2000BFDF */  ld         $31, 0x20($29)
    /* 3EDDC8 004EDDC8 0800E003 */  jr         $31
    /* 3EDDCC 004EDDCC 3000BD27 */   addiu     $29, $29, 0x30
.size func_004edd68, 0x68
