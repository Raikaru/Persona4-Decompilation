.section .text
.set noat
.set noreorder
glabel func_004abb60
    /* 3ABB60 004ABB60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ABB64 004ABB64 0000BFFF */  sd         $31, 0x0($29)
    /* 3ABB68 004ABB68 E006100C */  jal        func_00401b80
    /* 3ABB6C 004ABB6C 00000000 */   nop
    /* 3ABB70 004ABB70 9200033C */  lui        $3, %hi(D_00922D90)
    /* 3ABB74 004ABB74 902D62AC */  sw         $2, %lo(D_00922D90)($3)
    /* 3ABB78 004ABB78 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* 3ABB7C 004ABB7C 20008046 */  cvt.s.w    $f0, $f0
    /* 3ABB80 004ABB80 9200033C */  lui        $3, %hi(D_00922D94)
    /* 3ABB84 004ABB84 942D60E4 */  swc1       $f0, %lo(D_00922D94)($3)
    /* 3ABB88 004ABB88 100040C4 */  lwc1       $f0, 0x10($2)
    /* 3ABB8C 004ABB8C 20008046 */  cvt.s.w    $f0, $f0
    /* 3ABB90 004ABB90 9200033C */  lui        $3, %hi(D_00922D98)
    /* 3ABB94 004ABB94 982D60E4 */  swc1       $f0, %lo(D_00922D98)($3)
    /* 3ABB98 004ABB98 0000BFDF */  ld         $31, 0x0($29)
    /* 3ABB9C 004ABB9C 1000BD27 */  addiu      $29, $29, 0x10
    /* 3ABBA0 004ABBA0 0800E003 */  jr         $31
    /* 3ABBA4 004ABBA4 00000000 */   nop
    /* 3ABBA8 004ABBA8 00000000 */  nop
    /* 3ABBAC 004ABBAC 00000000 */  nop
.size func_004abb60, 0x50
