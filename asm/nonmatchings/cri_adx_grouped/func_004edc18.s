.section .text
.set noat
.set noreorder
glabel func_004edc18
    /* 3EDC18 004EDC18 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EDC1C 004EDC1C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EDC20 004EDC20 2D808000 */  daddu      $16, $4, $0
    /* 3EDC24 004EDC24 0800B1FF */  sd         $17, 0x8($29)
    /* 3EDC28 004EDC28 2D88A000 */  daddu      $17, $5, $0
    /* 3EDC2C 004EDC2C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EDC30 004EDC30 1800BFFF */  sd         $31, 0x18($29)
    /* 3EDC34 004EDC34 14B5130C */  jal        func_004ed450
    /* 3EDC38 004EDC38 2D90C000 */   daddu     $18, $6, $0
    /* 3EDC3C 004EDC3C 2D200002 */  daddu      $4, $16, $0
    /* 3EDC40 004EDC40 2D282002 */  daddu      $5, $17, $0
    /* 3EDC44 004EDC44 1AB7130C */  jal        func_004edc68
    /* 3EDC48 004EDC48 2D304002 */   daddu     $6, $18, $0
    /* 3EDC4C 004EDC4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EDC50 004EDC50 0800B1DF */  ld         $17, 0x8($29)
    /* 3EDC54 004EDC54 1000B2DF */  ld         $18, 0x10($29)
    /* 3EDC58 004EDC58 1800BFDF */  ld         $31, 0x18($29)
    /* 3EDC5C 004EDC5C 1AB51308 */  j          func_004ed468
    /* 3EDC60 004EDC60 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EDC64 004EDC64 00000000 */  nop
.size func_004edc18, 0x50
