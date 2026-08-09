.section .text
.set noat
.set noreorder
glabel func_0050fd00
    /* 40FD00 0050FD00 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 40FD04 0050FD04 0000B0FF */  sd         $16, 0x0($29)
    /* 40FD08 0050FD08 2D808000 */  daddu      $16, $4, $0
    /* 40FD0C 0050FD0C 1000B2FF */  sd         $18, 0x10($29)
    /* 40FD10 0050FD10 2D90C000 */  daddu      $18, $6, $0
    /* 40FD14 0050FD14 1800B3FF */  sd         $19, 0x18($29)
    /* 40FD18 0050FD18 2D98A000 */  daddu      $19, $5, $0
    /* 40FD1C 0050FD1C 2000BFFF */  sd         $31, 0x20($29)
    /* 40FD20 0050FD20 0800B1FF */  sd         $17, 0x8($29)
    /* 40FD24 0050FD24 3A3B140C */  jal        func_0050ece8
    /* 40FD28 0050FD28 A800118E */   lw        $17, 0xA8($16)
    /* 40FD2C 0050FD2C 2000BFDF */  ld         $31, 0x20($29)
    /* 40FD30 0050FD30 2D406002 */  daddu      $8, $19, $0
    /* 40FD34 0050FD34 2D202002 */  daddu      $4, $17, $0
    /* 40FD38 0050FD38 0800B1DF */  ld         $17, 0x8($29)
    /* 40FD3C 0050FD3C 1000058E */  lw         $5, 0x10($16)
    /* 40FD40 0050FD40 2D484002 */  daddu      $9, $18, $0
    /* 40FD44 0050FD44 1400068E */  lw         $6, 0x14($16)
    /* 40FD48 0050FD48 2D384000 */  daddu      $7, $2, $0
    /* 40FD4C 0050FD4C 0000B0DF */  ld         $16, 0x0($29)
    /* 40FD50 0050FD50 1000B2DF */  ld         $18, 0x10($29)
    /* 40FD54 0050FD54 1800B3DF */  ld         $19, 0x18($29)
    /* 40FD58 0050FD58 1EAD1408 */  j          func_0052b478
    /* 40FD5C 0050FD5C 3000BD27 */   addiu     $29, $29, 0x30
.size func_0050fd00, 0x60
