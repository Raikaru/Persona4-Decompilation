.section .text
.set noat
.set noreorder
glabel func_0052bf10
    /* 42BF10 0052BF10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BF14 0052BF14 2D280000 */  daddu      $5, $0, $0
    /* 42BF18 0052BF18 0000B0FF */  sd         $16, 0x0($29)
    /* 42BF1C 0052BF1C 7400103C */  lui        $16, %hi(D_00746138)
    /* 42BF20 0052BF20 38611026 */  addiu      $16, $16, %lo(D_00746138)
    /* 42BF24 0052BF24 6C020624 */  addiu      $6, $0, 0x26C
    /* 42BF28 0052BF28 0800BFFF */  sd         $31, 0x8($29)
    /* 42BF2C 0052BF2C 72FE100C */  jal        func_0043f9c8
    /* 42BF30 0052BF30 2D200002 */   daddu     $4, $16, $0
    /* 42BF34 0052BF34 08000324 */  addiu      $3, $0, 0x8
    /* 42BF38 0052BF38 080003AE */  sw         $3, 0x8($16)
    /* 42BF3C 0052BF3C 2D200000 */  daddu      $4, $0, $0
    /* 42BF40 0052BF40 0000B0DF */  ld         $16, 0x0($29)
    /* 42BF44 0052BF44 0800BFDF */  ld         $31, 0x8($29)
    /* 42BF48 0052BF48 1CB21408 */  j          func_0052c870
    /* 42BF4C 0052BF4C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052bf10, 0x40
