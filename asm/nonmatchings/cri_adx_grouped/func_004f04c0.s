.section .text
.set noat
.set noreorder
glabel func_004f04c0
    /* 3F04C0 004F04C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F04C4 004F04C4 01000624 */  addiu      $6, $0, 0x1
    /* 3F04C8 004F04C8 1000B0FF */  sd         $16, 0x10($29)
    /* 3F04CC 004F04CC 2D808000 */  daddu      $16, $4, $0
    /* 3F04D0 004F04D0 1800BFFF */  sd         $31, 0x18($29)
    /* 3F04D4 004F04D4 2D28A003 */  daddu      $5, $29, $0
    /* 3F04D8 004F04D8 01000424 */  addiu      $4, $0, 0x1
    /* 3F04DC 004F04DC 2D380000 */  daddu      $7, $0, $0
    /* 3F04E0 004F04E0 1000028E */  lw         $2, 0x10($16)
    /* 3F04E4 004F04E4 2D400000 */  daddu      $8, $0, $0
    /* 3F04E8 004F04E8 2896130C */  jal        func_004e58a0
    /* 3F04EC 004F04EC 0000A2AF */   sw        $2, 0x0($29)
    /* 3F04F0 004F04F0 1800BFDF */  ld         $31, 0x18($29)
    /* 3F04F4 004F04F4 000000A2 */  sb         $0, 0x0($16)
    /* 3F04F8 004F04F8 1000B0DF */  ld         $16, 0x10($29)
    /* 3F04FC 004F04FC 0800E003 */  jr         $31
    /* 3F0500 004F0500 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F0504 004F0504 00000000 */  nop
.size func_004f04c0, 0x48
