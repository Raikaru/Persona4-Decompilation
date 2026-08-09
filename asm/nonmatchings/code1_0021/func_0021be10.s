.section .text
.set noat
.set noreorder
glabel func_0021be10
    /* 11BE10 0021BE10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 11BE14 0021BE14 2000BFFF */  sd         $31, 0x20($29)
    /* 11BE18 0021BE18 1000B17F */  sq         $17, 0x10($29)
    /* 11BE1C 0021BE1C 0000B07F */  sq         $16, 0x0($29)
    /* 11BE20 0021BE20 2D888000 */  daddu      $17, $4, $0
    /* 11BE24 0021BE24 2D80A000 */  daddu      $16, $5, $0
    /* 11BE28 0021BE28 2D280000 */  daddu      $5, $0, $0
    /* 11BE2C 0021BE2C 0C000624 */  addiu      $6, $0, 0xC
    /* 11BE30 0021BE30 72FE100C */  jal        func_0043f9c8
    /* 11BE34 0021BE34 00000000 */   nop
    /* 11BE38 0021BE38 080030AE */  sw         $16, 0x8($17)
    /* 11BE3C 0021BE3C 01000324 */  addiu      $3, $0, 0x1
    /* 11BE40 0021BE40 040023A6 */  sh         $3, 0x4($17)
    /* 11BE44 0021BE44 2000BFDF */  ld         $31, 0x20($29)
    /* 11BE48 0021BE48 1000B17B */  lq         $17, 0x10($29)
    /* 11BE4C 0021BE4C 0000B07B */  lq         $16, 0x0($29)
    /* 11BE50 0021BE50 3000BD27 */  addiu      $29, $29, 0x30
    /* 11BE54 0021BE54 0800E003 */  jr         $31
    /* 11BE58 0021BE58 00000000 */   nop
    /* 11BE5C 0021BE5C 00000000 */  nop
.size func_0021be10, 0x50
