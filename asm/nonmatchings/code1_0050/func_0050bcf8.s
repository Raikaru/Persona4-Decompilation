.section .text
.set noat
.set noreorder
glabel func_0050bcf8
    /* 40BCF8 0050BCF8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40BCFC 0050BCFC 0000B0FF */  sd         $16, 0x0($29)
    /* 40BD00 0050BD00 2D80A000 */  daddu      $16, $5, $0
    /* 40BD04 0050BD04 0800B1FF */  sd         $17, 0x8($29)
    /* 40BD08 0050BD08 2D88C000 */  daddu      $17, $6, $0
    /* 40BD0C 0050BD0C 1000B2FF */  sd         $18, 0x10($29)
    /* 40BD10 0050BD10 1800BFFF */  sd         $31, 0x18($29)
    /* 40BD14 0050BD14 9833140C */  jal        func_0050ce60
    /* 40BD18 0050BD18 2D90E000 */   daddu     $18, $7, $0
    /* 40BD1C 0050BD1C 1800BFDF */  ld         $31, 0x18($29)
    /* 40BD20 0050BD20 2D280002 */  daddu      $5, $16, $0
    /* 40BD24 0050BD24 2D302002 */  daddu      $6, $17, $0
    /* 40BD28 0050BD28 0800B1DF */  ld         $17, 0x8($29)
    /* 40BD2C 0050BD2C 2D384002 */  daddu      $7, $18, $0
    /* 40BD30 0050BD30 1000B2DF */  ld         $18, 0x10($29)
    /* 40BD34 0050BD34 0000B0DF */  ld         $16, 0x0($29)
    /* 40BD38 0050BD38 2D204000 */  daddu      $4, $2, $0
    /* 40BD3C 0050BD3C A4981408 */  j          func_00526290
    /* 40BD40 0050BD40 2000BD27 */   addiu     $29, $29, 0x20
    /* 40BD44 0050BD44 00000000 */  nop
.size func_0050bcf8, 0x50
