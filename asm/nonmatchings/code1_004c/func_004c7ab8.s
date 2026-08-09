.section .text
.set noat
.set noreorder
glabel func_004c7ab8
    /* 3C7AB8 004C7AB8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3C7ABC 004C7ABC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7AC0 004C7AC0 2D808000 */  daddu      $16, $4, $0
    /* 3C7AC4 004C7AC4 0800B1FF */  sd         $17, 0x8($29)
    /* 3C7AC8 004C7AC8 2D88A000 */  daddu      $17, $5, $0
    /* 3C7ACC 004C7ACC 1000B2FF */  sd         $18, 0x10($29)
    /* 3C7AD0 004C7AD0 2D90C000 */  daddu      $18, $6, $0
    /* 3C7AD4 004C7AD4 1800B3FF */  sd         $19, 0x18($29)
    /* 3C7AD8 004C7AD8 2D98E000 */  daddu      $19, $7, $0
    /* 3C7ADC 004C7ADC 2000B4FF */  sd         $20, 0x20($29)
    /* 3C7AE0 004C7AE0 2DA00001 */  daddu      $20, $8, $0
    /* 3C7AE4 004C7AE4 2800B5FF */  sd         $21, 0x28($29)
    /* 3C7AE8 004C7AE8 3000BFFF */  sd         $31, 0x30($29)
    /* 3C7AEC 004C7AEC 4627130C */  jal        func_004c9d18
    /* 3C7AF0 004C7AF0 2DA82001 */   daddu     $21, $9, $0
    /* 3C7AF4 004C7AF4 2D200002 */  daddu      $4, $16, $0
    /* 3C7AF8 004C7AF8 2D282002 */  daddu      $5, $17, $0
    /* 3C7AFC 004C7AFC 2D304002 */  daddu      $6, $18, $0
    /* 3C7B00 004C7B00 2D386002 */  daddu      $7, $19, $0
    /* 3C7B04 004C7B04 2D408002 */  daddu      $8, $20, $0
    /* 3C7B08 004C7B08 D01E130C */  jal        func_004c7b40
    /* 3C7B0C 004C7B0C 2D48A002 */   daddu     $9, $21, $0
    /* 3C7B10 004C7B10 4C27130C */  jal        func_004c9d30
    /* 3C7B14 004C7B14 2D804000 */   daddu     $16, $2, $0
    /* 3C7B18 004C7B18 0800B1DF */  ld         $17, 0x8($29)
    /* 3C7B1C 004C7B1C 2D100002 */  daddu      $2, $16, $0
    /* 3C7B20 004C7B20 1000B2DF */  ld         $18, 0x10($29)
    /* 3C7B24 004C7B24 0000B0DF */  ld         $16, 0x0($29)
    /* 3C7B28 004C7B28 1800B3DF */  ld         $19, 0x18($29)
    /* 3C7B2C 004C7B2C 2000B4DF */  ld         $20, 0x20($29)
    /* 3C7B30 004C7B30 2800B5DF */  ld         $21, 0x28($29)
    /* 3C7B34 004C7B34 3000BFDF */  ld         $31, 0x30($29)
    /* 3C7B38 004C7B38 0800E003 */  jr         $31
    /* 3C7B3C 004C7B3C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004c7ab8, 0x88
