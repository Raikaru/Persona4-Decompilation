.section .text
.set noat
.set noreorder
glabel func_004f0de8
    /* 3F0DE8 004F0DE8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F0DEC 004F0DEC 0000B0FF */  sd         $16, 0x0($29)
    /* 3F0DF0 004F0DF0 2D808000 */  daddu      $16, $4, $0
    /* 3F0DF4 004F0DF4 0800B1FF */  sd         $17, 0x8($29)
    /* 3F0DF8 004F0DF8 2D88A000 */  daddu      $17, $5, $0
    /* 3F0DFC 004F0DFC 1000B2FF */  sd         $18, 0x10($29)
    /* 3F0E00 004F0E00 1800BFFF */  sd         $31, 0x18($29)
    /* 3F0E04 004F0E04 82C1130C */  jal        func_004f0608
    /* 3F0E08 004F0E08 2D90C000 */   daddu     $18, $6, $0
    /* 3F0E0C 004F0E0C 9200023C */  lui        $2, %hi(D_00925E20)
    /* 3F0E10 004F0E10 C0801000 */  sll        $16, $16, 3
    /* 3F0E14 004F0E14 205E4224 */  addiu      $2, $2, %lo(D_00925E20)
    /* 3F0E18 004F0E18 1800BFDF */  ld         $31, 0x18($29)
    /* 3F0E1C 004F0E1C 21185000 */  addu       $3, $2, $16
    /* 3F0E20 004F0E20 21800202 */  addu       $16, $16, $2
    /* 3F0E24 004F0E24 000011AE */  sw         $17, 0x0($16)
    /* 3F0E28 004F0E28 040072AC */  sw         $18, 0x4($3)
    /* 3F0E2C 004F0E2C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0E30 004F0E30 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0E34 004F0E34 1000B2DF */  ld         $18, 0x10($29)
    /* 3F0E38 004F0E38 88C11308 */  j          func_004f0620
    /* 3F0E3C 004F0E3C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004f0de8, 0x58
