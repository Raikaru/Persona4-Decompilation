.section .text
.set noat
.set noreorder
glabel func_004ee910
    /* 3EE910 004EE910 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EE914 004EE914 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE918 004EE918 2D808000 */  daddu      $16, $4, $0
    /* 3EE91C 004EE91C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EE920 004EE920 2D88A000 */  daddu      $17, $5, $0
    /* 3EE924 004EE924 1000B2FF */  sd         $18, 0x10($29)
    /* 3EE928 004EE928 2D90C000 */  daddu      $18, $6, $0
    /* 3EE92C 004EE92C 1800B3FF */  sd         $19, 0x18($29)
    /* 3EE930 004EE930 2000BFFF */  sd         $31, 0x20($29)
    /* 3EE934 004EE934 14B5130C */  jal        func_004ed450
    /* 3EE938 004EE938 2D98E000 */   daddu     $19, $7, $0
    /* 3EE93C 004EE93C 2D200002 */  daddu      $4, $16, $0
    /* 3EE940 004EE940 2D282002 */  daddu      $5, $17, $0
    /* 3EE944 004EE944 2D304002 */  daddu      $6, $18, $0
    /* 3EE948 004EE948 5EBA130C */  jal        func_004ee978
    /* 3EE94C 004EE94C 2D386002 */   daddu     $7, $19, $0
    /* 3EE950 004EE950 1AB5130C */  jal        func_004ed468
    /* 3EE954 004EE954 2D804000 */   daddu     $16, $2, $0
    /* 3EE958 004EE958 0800B1DF */  ld         $17, 0x8($29)
    /* 3EE95C 004EE95C 2D100002 */  daddu      $2, $16, $0
    /* 3EE960 004EE960 1000B2DF */  ld         $18, 0x10($29)
    /* 3EE964 004EE964 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE968 004EE968 1800B3DF */  ld         $19, 0x18($29)
    /* 3EE96C 004EE96C 2000BFDF */  ld         $31, 0x20($29)
    /* 3EE970 004EE970 0800E003 */  jr         $31
    /* 3EE974 004EE974 3000BD27 */   addiu     $29, $29, 0x30
.size func_004ee910, 0x68
