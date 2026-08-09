.section .text
.set noat
.set noreorder
glabel func_004c79e0
    /* 3C79E0 004C79E0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3C79E4 004C79E4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C79E8 004C79E8 2D808000 */  daddu      $16, $4, $0
    /* 3C79EC 004C79EC 0800B1FF */  sd         $17, 0x8($29)
    /* 3C79F0 004C79F0 2D88A000 */  daddu      $17, $5, $0
    /* 3C79F4 004C79F4 1000B2FF */  sd         $18, 0x10($29)
    /* 3C79F8 004C79F8 2D90C000 */  daddu      $18, $6, $0
    /* 3C79FC 004C79FC 1800B3FF */  sd         $19, 0x18($29)
    /* 3C7A00 004C7A00 2D98E000 */  daddu      $19, $7, $0
    /* 3C7A04 004C7A04 2000B4FF */  sd         $20, 0x20($29)
    /* 3C7A08 004C7A08 2DA00001 */  daddu      $20, $8, $0
    /* 3C7A0C 004C7A0C 2800B5FF */  sd         $21, 0x28($29)
    /* 3C7A10 004C7A10 3000BFFF */  sd         $31, 0x30($29)
    /* 3C7A14 004C7A14 4627130C */  jal        func_004c9d18
    /* 3C7A18 004C7A18 2DA82001 */   daddu     $21, $9, $0
    /* 3C7A1C 004C7A1C 2D200002 */  daddu      $4, $16, $0
    /* 3C7A20 004C7A20 2D282002 */  daddu      $5, $17, $0
    /* 3C7A24 004C7A24 2D304002 */  daddu      $6, $18, $0
    /* 3C7A28 004C7A28 2D386002 */  daddu      $7, $19, $0
    /* 3C7A2C 004C7A2C 2D408002 */  daddu      $8, $20, $0
    /* 3C7A30 004C7A30 9A1E130C */  jal        func_004c7a68
    /* 3C7A34 004C7A34 2D48A002 */   daddu     $9, $21, $0
    /* 3C7A38 004C7A38 4C27130C */  jal        func_004c9d30
    /* 3C7A3C 004C7A3C 2D804000 */   daddu     $16, $2, $0
    /* 3C7A40 004C7A40 0800B1DF */  ld         $17, 0x8($29)
    /* 3C7A44 004C7A44 2D100002 */  daddu      $2, $16, $0
    /* 3C7A48 004C7A48 1000B2DF */  ld         $18, 0x10($29)
    /* 3C7A4C 004C7A4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3C7A50 004C7A50 1800B3DF */  ld         $19, 0x18($29)
    /* 3C7A54 004C7A54 2000B4DF */  ld         $20, 0x20($29)
    /* 3C7A58 004C7A58 2800B5DF */  ld         $21, 0x28($29)
    /* 3C7A5C 004C7A5C 3000BFDF */  ld         $31, 0x30($29)
    /* 3C7A60 004C7A60 0800E003 */  jr         $31
    /* 3C7A64 004C7A64 4000BD27 */   addiu     $29, $29, 0x40
.size func_004c79e0, 0x88
