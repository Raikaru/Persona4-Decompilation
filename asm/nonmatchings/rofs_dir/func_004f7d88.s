.section .text
.set noat
.set noreorder
glabel func_004f7d88
    /* 3F7D88 004F7D88 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3F7D8C 004F7D8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F7D90 004F7D90 2D808000 */  daddu      $16, $4, $0
    /* 3F7D94 004F7D94 0800B1FF */  sd         $17, 0x8($29)
    /* 3F7D98 004F7D98 2D88A000 */  daddu      $17, $5, $0
    /* 3F7D9C 004F7D9C 1000B2FF */  sd         $18, 0x10($29)
    /* 3F7DA0 004F7DA0 2D90C000 */  daddu      $18, $6, $0
    /* 3F7DA4 004F7DA4 1800B3FF */  sd         $19, 0x18($29)
    /* 3F7DA8 004F7DA8 2D98E000 */  daddu      $19, $7, $0
    /* 3F7DAC 004F7DAC 2000B4FF */  sd         $20, 0x20($29)
    /* 3F7DB0 004F7DB0 2800B5FF */  sd         $21, 0x28($29)
    /* 3F7DB4 004F7DB4 3000BFFF */  sd         $31, 0x30($29)
    /* 3F7DB8 004F7DB8 08DA130C */  jal        func_004f6820
    /* 3F7DBC 004F7DBC 2DA00001 */   daddu     $20, $8, $0
    /* 3F7DC0 004F7DC0 2DA84000 */  daddu      $21, $2, $0
    /* 3F7DC4 004F7DC4 2D200002 */  daddu      $4, $16, $0
    /* 3F7DC8 004F7DC8 2D282002 */  daddu      $5, $17, $0
    /* 3F7DCC 004F7DCC 2D304002 */  daddu      $6, $18, $0
    /* 3F7DD0 004F7DD0 2D386002 */  daddu      $7, $19, $0
    /* 3F7DD4 004F7DD4 0400A016 */  bnez       $21, .L004F7DE8
    /* 3F7DD8 004F7DD8 2D408002 */   daddu     $8, $20, $0
    /* 3F7DDC 004F7DDC 94DE130C */  jal        func_004f7a50
    /* 3F7DE0 004F7DE0 00000000 */   nop
    /* 3F7DE4 004F7DE4 2DA84000 */  daddu      $21, $2, $0
  .L004F7DE8:
    /* 3F7DE8 004F7DE8 1CDA130C */  jal        func_004f6870
    /* 3F7DEC 004F7DEC 00000000 */   nop
    /* 3F7DF0 004F7DF0 2D10A002 */  daddu      $2, $21, $0
    /* 3F7DF4 004F7DF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F7DF8 004F7DF8 0800B1DF */  ld         $17, 0x8($29)
    /* 3F7DFC 004F7DFC 1000B2DF */  ld         $18, 0x10($29)
    /* 3F7E00 004F7E00 1800B3DF */  ld         $19, 0x18($29)
    /* 3F7E04 004F7E04 2000B4DF */  ld         $20, 0x20($29)
    /* 3F7E08 004F7E08 2800B5DF */  ld         $21, 0x28($29)
    /* 3F7E0C 004F7E0C 3000BFDF */  ld         $31, 0x30($29)
    /* 3F7E10 004F7E10 0800E003 */  jr         $31
    /* 3F7E14 004F7E14 4000BD27 */   addiu     $29, $29, 0x40
.size func_004f7d88, 0x90
