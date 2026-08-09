.section .text
.set noat
.set noreorder
glabel func_0042a2f8
    /* 32A2F8 0042A2F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32A2FC 0042A2FC 7100023C */  lui        $2, %hi(D_0070C6A0)
    /* 32A300 0042A300 FFFF0324 */  addiu      $3, $0, -0x1
    /* 32A304 0042A304 8900043C */  lui        $4, %hi(D_00891368)
    /* 32A308 0042A308 0000BFFF */  sd         $31, 0x0($29)
    /* 32A30C 0042A30C 68138424 */  addiu      $4, $4, %lo(D_00891368)
    /* 32A310 0042A310 A0C643AC */  sw         $3, %lo(D_0070C6A0)($2)
    /* 32A314 0042A314 2D280000 */  daddu      $5, $0, $0
    /* 32A318 0042A318 72FE100C */  jal        func_0043f9c8
    /* 32A31C 0042A31C 04000624 */   addiu     $6, $0, 0x4
    /* 32A320 0042A320 0000BFDF */  ld         $31, 0x0($29)
    /* 32A324 0042A324 2D100000 */  daddu      $2, $0, $0
    /* 32A328 0042A328 0800E003 */  jr         $31
    /* 32A32C 0042A32C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0042a2f8, 0x38
