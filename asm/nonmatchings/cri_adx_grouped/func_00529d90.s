.section .text
.set noat
.set noreorder
glabel func_00529d90
    /* 429D90 00529D90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 429D94 00529D94 1000B2FF */  sd         $18, 0x10($29)
    /* 429D98 00529D98 2D90C000 */  daddu      $18, $6, $0
    /* 429D9C 00529D9C 0000B0FF */  sd         $16, 0x0($29)
    /* 429DA0 00529DA0 FF00B030 */  andi       $16, $5, 0xFF
    /* 429DA4 00529DA4 000040AE */  sw         $0, 0x0($18)
    /* 429DA8 00529DA8 0800B1FF */  sd         $17, 0x8($29)
    /* 429DAC 00529DAC 1800BFFF */  sd         $31, 0x18($29)
    /* 429DB0 00529DB0 BEA6140C */  jal        func_00529af8
    /* 429DB4 00529DB4 2D280002 */   daddu     $5, $16, $0
    /* 429DB8 00529DB8 2D884000 */  daddu      $17, $2, $0
    /* 429DBC 00529DBC 0B002012 */  beqz       $17, .L00529DEC
    /* 429DC0 00529DC0 2D200002 */   daddu     $4, $16, $0
    /* 429DC4 00529DC4 FCA8140C */  jal        func_0052a3f0
    /* 429DC8 00529DC8 00000000 */   nop
    /* 429DCC 00529DCC E0000324 */  addiu      $3, $0, 0xE0
    /* 429DD0 00529DD0 06004314 */  bne        $2, $3, .L00529DEC
    /* 429DD4 00529DD4 2D100000 */   daddu     $2, $0, $0
    /* 429DD8 00529DD8 1A002396 */  lhu        $3, 0x1A($17)
    /* 429DDC 00529DDC 01000224 */  addiu      $2, $0, 0x1
    /* 429DE0 00529DE0 FFFF6438 */  xori       $4, $3, 0xFFFF
    /* 429DE4 00529DE4 0A180400 */  movz       $3, $0, $4
    /* 429DE8 00529DE8 000043AE */  sw         $3, 0x0($18)
  .L00529DEC:
    /* 429DEC 00529DEC 0000B0DF */  ld         $16, 0x0($29)
    /* 429DF0 00529DF0 0800B1DF */  ld         $17, 0x8($29)
    /* 429DF4 00529DF4 1000B2DF */  ld         $18, 0x10($29)
    /* 429DF8 00529DF8 1800BFDF */  ld         $31, 0x18($29)
    /* 429DFC 00529DFC 0800E003 */  jr         $31
    /* 429E00 00529E00 2000BD27 */   addiu     $29, $29, 0x20
    /* 429E04 00529E04 00000000 */  nop
.size func_00529d90, 0x78
