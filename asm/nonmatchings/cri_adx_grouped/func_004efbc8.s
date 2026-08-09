.section .text
.set noat
.set noreorder
glabel func_004efbc8
    /* 3EFBC8 004EFBC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFBCC 004EFBCC 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFBD0 004EFBD0 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFBD4 004EFBD4 9200103C */  lui        $16, %hi(D_00925AC0)
    /* 3EFBD8 004EFBD8 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFBDC 004EFBDC 0800BFFF */  sd         $31, 0x8($29)
    /* 3EFBE0 004EFBE0 C05A1026 */  addiu      $16, $16, %lo(D_00925AC0)
    /* 3EFBE4 004EFBE4 000044AC */  sw         $4, 0x0($2)
    /* 3EFBE8 004EFBE8 040045AC */  sw         $5, 0x4($2)
    /* 3EFBEC 004EFBEC 2D284000 */  daddu      $5, $2, $0
    /* 3EFBF0 004EFBF0 080046AC */  sw         $6, 0x8($2)
    /* 3EFBF4 004EFBF4 03000624 */  addiu      $6, $0, 0x3
    /* 3EFBF8 004EFBF8 2D380002 */  daddu      $7, $16, $0
    /* 3EFBFC 004EFBFC 20000424 */  addiu      $4, $0, 0x20
    /* 3EFC00 004EFC00 2896130C */  jal        func_004e58a0
    /* 3EFC04 004EFC04 01000824 */   addiu     $8, $0, 0x1
    /* 3EFC08 004EFC08 0000028E */  lw         $2, 0x0($16)
    /* 3EFC0C 004EFC0C 0800BFDF */  ld         $31, 0x8($29)
    /* 3EFC10 004EFC10 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFC14 004EFC14 0800E003 */  jr         $31
    /* 3EFC18 004EFC18 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EFC1C 004EFC1C 00000000 */  nop
.size func_004efbc8, 0x58
