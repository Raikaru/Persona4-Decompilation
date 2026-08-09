.section .text
.set noat
.set noreorder
glabel func_004cf968
    /* 3CF968 004CF968 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CF96C 004CF96C 00140500 */  sll        $2, $5, 16
    /* 3CF970 004CF970 1000B0FF */  sd         $16, 0x10($29)
    /* 3CF974 004CF974 2D808000 */  daddu      $16, $4, $0
    /* 3CF978 004CF978 0200A727 */  addiu      $7, $29, 0x2
    /* 3CF97C 004CF97C 2D28C000 */  daddu      $5, $6, $0
    /* 3CF980 004CF980 03240200 */  sra        $4, $2, 16
    /* 3CF984 004CF984 1800BFFF */  sd         $31, 0x18($29)
    /* 3CF988 004CF988 3A15130C */  jal        func_004c54e8
    /* 3CF98C 004CF98C 2D30A003 */   daddu     $6, $29, $0
    /* 3CF990 004CF990 0000A587 */  lh         $5, 0x0($29)
    /* 3CF994 004CF994 2D200002 */  daddu      $4, $16, $0
    /* 3CF998 004CF998 563E130C */  jal        func_004cf958
    /* 3CF99C 004CF99C 0200A687 */   lh        $6, 0x2($29)
    /* 3CF9A0 004CF9A0 8800048E */  lw         $4, 0x88($16)
    /* 3CF9A4 004CF9A4 0000A587 */  lh         $5, 0x0($29)
    /* 3CF9A8 004CF9A8 F43D130C */  jal        func_004cf7d0
    /* 3CF9AC 004CF9AC 0200A687 */   lh        $6, 0x2($29)
    /* 3CF9B0 004CF9B0 1000B0DF */  ld         $16, 0x10($29)
    /* 3CF9B4 004CF9B4 1800BFDF */  ld         $31, 0x18($29)
    /* 3CF9B8 004CF9B8 0800E003 */  jr         $31
    /* 3CF9BC 004CF9BC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004cf968, 0x58
