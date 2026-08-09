.section .text
.set noat
.set noreorder
glabel func_002ba970
    /* 1BA970 002BA970 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BA974 002BA974 0C00A6AF */  sw         $6, 0xC($29)
    /* 1BA978 002BA978 3C1C0500 */  dsll32     $3, $5, 16
    /* 1BA97C 002BA97C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1BA980 002BA980 40300300 */  sll        $6, $3, 1
    /* 1BA984 002BA984 3C2C0600 */  dsll32     $5, $6, 16
    /* 1BA988 002BA988 3F2C0500 */  dsra32     $5, $5, 16
    /* 1BA98C 002BA98C 00190500 */  sll        $3, $5, 4
    /* 1BA990 002BA990 21186500 */  addu       $3, $3, $5
    /* 1BA994 002BA994 40590300 */  sll        $11, $3, 5
    /* 1BA998 002BA998 3800838C */  lw         $3, 0x38($4)
    /* 1BA99C 002BA99C 21186B00 */  addu       $3, $3, $11
    /* 1BA9A0 002BA9A0 0C00AA93 */  lbu        $10, 0xC($29)
    /* 1BA9A4 002BA9A4 0D00A993 */  lbu        $9, 0xD($29)
    /* 1BA9A8 002BA9A8 0E00A893 */  lbu        $8, 0xE($29)
    /* 1BA9AC 002BA9AC 0F00A793 */  lbu        $7, 0xF($29)
    /* 1BA9B0 002BA9B0 79016AA0 */  sb         $10, 0x179($3)
    /* 1BA9B4 002BA9B4 7A0169A0 */  sb         $9, 0x17A($3)
    /* 1BA9B8 002BA9B8 7B0168A0 */  sb         $8, 0x17B($3)
    /* 1BA9BC 002BA9BC 7C0167A0 */  sb         $7, 0x17C($3)
    /* 1BA9C0 002BA9C0 0100C324 */  addiu      $3, $6, 0x1
    /* 1BA9C4 002BA9C4 3C2C0300 */  dsll32     $5, $3, 16
    /* 1BA9C8 002BA9C8 3F2C0500 */  dsra32     $5, $5, 16
    /* 1BA9CC 002BA9CC 00190500 */  sll        $3, $5, 4
    /* 1BA9D0 002BA9D0 21186500 */  addu       $3, $3, $5
    /* 1BA9D4 002BA9D4 40310300 */  sll        $6, $3, 5
    /* 1BA9D8 002BA9D8 3800838C */  lw         $3, 0x38($4)
    /* 1BA9DC 002BA9DC 21186600 */  addu       $3, $3, $6
    /* 1BA9E0 002BA9E0 79016AA0 */  sb         $10, 0x179($3)
    /* 1BA9E4 002BA9E4 7A0169A0 */  sb         $9, 0x17A($3)
    /* 1BA9E8 002BA9E8 7B0168A0 */  sb         $8, 0x17B($3)
    /* 1BA9EC 002BA9EC 7C0167A0 */  sb         $7, 0x17C($3)
    /* 1BA9F0 002BA9F0 3800838C */  lw         $3, 0x38($4)
    /* 1BA9F4 002BA9F4 21186B00 */  addu       $3, $3, $11
    /* 1BA9F8 002BA9F8 0F00A593 */  lbu        $5, 0xF($29)
    /* 1BA9FC 002BA9FC 620165A0 */  sb         $5, 0x162($3)
    /* 1BAA00 002BAA00 3800838C */  lw         $3, 0x38($4)
    /* 1BAA04 002BAA04 21186600 */  addu       $3, $3, $6
    /* 1BAA08 002BAA08 620165A0 */  sb         $5, 0x162($3)
    /* 1BAA0C 002BAA0C 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BAA10 002BAA10 0800E003 */  jr         $31
    /* 1BAA14 002BAA14 00000000 */   nop
    /* 1BAA18 002BAA18 00000000 */  nop
    /* 1BAA1C 002BAA1C 00000000 */  nop
.size func_002ba970, 0xb0
