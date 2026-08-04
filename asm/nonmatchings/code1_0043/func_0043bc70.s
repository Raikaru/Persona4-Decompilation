.section .text
.set noat
.set noreorder
glabel func_0043bc70
    /* 33BC70 0043BC70 7100033C */  lui        $3, %hi(D_0070FC64)
    /* 33BC74 0043BC74 0C000624 */  addiu      $6, $0, 0xC
    /* 33BC78 0043BC78 64FC658C */  lw         $5, %lo(D_0070FC64)($3)
    /* 33BC7C 0043BC7C 7100023C */  lui        $2, %hi(D_0070FC58)
    /* 33BC80 0043BC80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33BC84 0043BC84 58FC448C */  lw         $4, %lo(D_0070FC58)($2)
    /* 33BC88 0043BC88 1800A600 */  mult       $0, $5, $6
    /* 33BC8C 0043BC8C 0000BFFF */  sd         $31, 0x0($29)
    /* 33BC90 0043BC90 B6F1100C */  jal        func_0043c6d8
    /* 33BC94 0043BC94 12280000 */   mflo      $5
    /* 33BC98 0043BC98 7100023C */  lui        $2, %hi(D_0070FC60)
    /* 33BC9C 0043BC9C 7100033C */  lui        $3, %hi(D_0070FC5C)
    /* 33BCA0 0043BCA0 60FC40AC */  sw         $0, %lo(D_0070FC60)($2)
    /* 33BCA4 0043BCA4 0000BFDF */  ld         $31, 0x0($29)
    /* 33BCA8 0043BCA8 2D100000 */  daddu      $2, $0, $0
    /* 33BCAC 0043BCAC 5CFC60AC */  sw         $0, %lo(D_0070FC5C)($3)
    /* 33BCB0 0043BCB0 0800E003 */  jr         $31
    /* 33BCB4 0043BCB4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043bc70, 0x48
