.section .text
.set noat
.set noreorder
glabel func_004cabf0
    /* 3CABF0 004CABF0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3CABF4 004CABF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CABF8 004CABF8 2D808000 */  daddu      $16, $4, $0
    /* 3CABFC 004CABFC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CAC00 004CAC00 2D88A000 */  daddu      $17, $5, $0
    /* 3CAC04 004CAC04 1000B2FF */  sd         $18, 0x10($29)
    /* 3CAC08 004CAC08 2D90C000 */  daddu      $18, $6, $0
    /* 3CAC0C 004CAC0C 1800B3FF */  sd         $19, 0x18($29)
    /* 3CAC10 004CAC10 2000BFFF */  sd         $31, 0x20($29)
    /* 3CAC14 004CAC14 3615130C */  jal        func_004c54d8
    /* 3CAC18 004CAC18 2D98E000 */   daddu     $19, $7, $0
    /* 3CAC1C 004CAC1C 2D200002 */  daddu      $4, $16, $0
    /* 3CAC20 004CAC20 2D282002 */  daddu      $5, $17, $0
    /* 3CAC24 004CAC24 2D304002 */  daddu      $6, $18, $0
    /* 3CAC28 004CAC28 142B130C */  jal        func_004cac50
    /* 3CAC2C 004CAC2C 2D386002 */   daddu     $7, $19, $0
    /* 3CAC30 004CAC30 0000B0DF */  ld         $16, 0x0($29)
    /* 3CAC34 004CAC34 0800B1DF */  ld         $17, 0x8($29)
    /* 3CAC38 004CAC38 1000B2DF */  ld         $18, 0x10($29)
    /* 3CAC3C 004CAC3C 1800B3DF */  ld         $19, 0x18($29)
    /* 3CAC40 004CAC40 2000BFDF */  ld         $31, 0x20($29)
    /* 3CAC44 004CAC44 38151308 */  j          func_004c54e0
    /* 3CAC48 004CAC48 3000BD27 */   addiu     $29, $29, 0x30
    /* 3CAC4C 004CAC4C 00000000 */  nop
.size func_004cabf0, 0x60
