.section .text
.set noat
.set noreorder
glabel func_004efef8
    /* 3EFEF8 004EFEF8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EFEFC 004EFEFC 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFF00 004EFF00 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFF04 004EFF04 9200103C */  lui        $16, %hi(D_00925AC0)
    /* 3EFF08 004EFF08 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFF0C 004EFF0C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EFF10 004EFF10 1000BFFF */  sd         $31, 0x10($29)
    /* 3EFF14 004EFF14 C05A1026 */  addiu      $16, $16, %lo(D_00925AC0)
    /* 3EFF18 004EFF18 000044AC */  sw         $4, 0x0($2)
    /* 3EFF1C 004EFF1C 2A000424 */  addiu      $4, $0, 0x2A
    /* 3EFF20 004EFF20 040045AC */  sw         $5, 0x4($2)
    /* 3EFF24 004EFF24 2D284000 */  daddu      $5, $2, $0
    /* 3EFF28 004EFF28 080046AC */  sw         $6, 0x8($2)
    /* 3EFF2C 004EFF2C 03000624 */  addiu      $6, $0, 0x3
    /* 3EFF30 004EFF30 2D88E000 */  daddu      $17, $7, $0
    /* 3EFF34 004EFF34 2D380002 */  daddu      $7, $16, $0
    /* 3EFF38 004EFF38 2896130C */  jal        func_004e58a0
    /* 3EFF3C 004EFF3C 01000824 */   addiu     $8, $0, 0x1
    /* 3EFF40 004EFF40 0400038E */  lw         $3, 0x4($16)
    /* 3EFF44 004EFF44 1000BFDF */  ld         $31, 0x10($29)
    /* 3EFF48 004EFF48 000023AE */  sw         $3, 0x0($17)
    /* 3EFF4C 004EFF4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EFF50 004EFF50 0000028E */  lw         $2, 0x0($16)
    /* 3EFF54 004EFF54 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFF58 004EFF58 0800E003 */  jr         $31
    /* 3EFF5C 004EFF5C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004efef8, 0x68
