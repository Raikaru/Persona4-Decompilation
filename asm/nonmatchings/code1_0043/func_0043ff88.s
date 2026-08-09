.section .text
.set noat
.set noreorder
glabel func_0043ff88
    /* 33FF88 0043FF88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33FF8C 0043FF8C 0000B0FF */  sd         $16, 0x0($29)
    /* 33FF90 0043FF90 0800BFFF */  sd         $31, 0x8($29)
    /* 33FF94 0043FF94 2D80A000 */  daddu      $16, $5, $0
    /* 33FF98 0043FF98 CEFE100C */  jal        func_0043fb38
    /* 33FF9C 0043FF9C 01000524 */   addiu     $5, $0, 0x1
    /* 33FFA0 0043FFA0 140050AC */  sw         $16, 0x14($2)
    /* 33FFA4 0043FFA4 01000F24 */  addiu      $15, $0, 0x1
    /* 33FFA8 0043FFA8 10004FAC */  sw         $15, 0x10($2)
    /* 33FFAC 0043FFAC 0000B0DF */  ld         $16, 0x0($29)
    /* 33FFB0 0043FFB0 0800BFDF */  ld         $31, 0x8($29)
    /* 33FFB4 0043FFB4 0800E003 */  jr         $31
    /* 33FFB8 0043FFB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 33FFBC 0043FFBC 00000000 */  nop
.size func_0043ff88, 0x38
