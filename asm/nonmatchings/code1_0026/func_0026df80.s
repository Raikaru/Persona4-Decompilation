.section .text
.set noat
.set noreorder
glabel func_0026df80
    /* 16DF80 0026DF80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 16DF84 0026DF84 1000BFFF */  sd         $31, 0x10($29)
    /* 16DF88 0026DF88 0000B07F */  sq         $16, 0x0($29)
    /* 16DF8C 0026DF8C 2D200000 */  daddu      $4, $0, $0
    /* 16DF90 0026DF90 6400053C */  lui        $5, %hi(D_0063B5A0)
    /* 16DF94 0026DF94 A0B5A524 */  addiu      $5, $5, %lo(D_0063B5A0)
    /* 16DF98 0026DF98 10000624 */  addiu      $6, $0, 0x10
    /* 16DF9C 0026DF9C 2D380000 */  daddu      $7, $0, $0
    /* 16DFA0 0026DFA0 2D400000 */  daddu      $8, $0, $0
    /* 16DFA4 0026DFA4 2700093C */  lui        $9, %hi(func_0026db60)
    /* 16DFA8 0026DFA8 60DB2925 */  addiu      $9, $9, %lo(func_0026db60)
    /* 16DFAC 0026DFAC 27000A3C */  lui        $10, %hi(func_0026dc30)
    /* 16DFB0 0026DFB0 30DC4A25 */  addiu      $10, $10, %lo(func_0026dc30)
    /* 16DFB4 0026DFB4 2D580000 */  daddu      $11, $0, $0
    /* 16DFB8 0026DFB8 F047110C */  jal        func_00451fc0
    /* 16DFBC 0026DFBC 00000000 */   nop
    /* 16DFC0 0026DFC0 2D804000 */  daddu      $16, $2, $0
    /* 16DFC4 0026DFC4 2D200002 */  daddu      $4, $16, $0
    /* 16DFC8 0026DFC8 6400053C */  lui        $5, %hi(D_0063B5C0)
    /* 16DFCC 0026DFCC C0B5A524 */  addiu      $5, $5, %lo(D_0063B5C0)
    /* 16DFD0 0026DFD0 10000624 */  addiu      $6, $0, 0x10
    /* 16DFD4 0026DFD4 2D380000 */  daddu      $7, $0, $0
    /* 16DFD8 0026DFD8 2D400000 */  daddu      $8, $0, $0
    /* 16DFDC 0026DFDC 2700093C */  lui        $9, %hi(func_0026dee0)
    /* 16DFE0 0026DFE0 E0DE2925 */  addiu      $9, $9, %lo(func_0026dee0)
    /* 16DFE4 0026DFE4 2D500000 */  daddu      $10, $0, $0
    /* 16DFE8 0026DFE8 2D580000 */  daddu      $11, $0, $0
    /* 16DFEC 0026DFEC F047110C */  jal        func_00451fc0
    /* 16DFF0 0026DFF0 00000000 */   nop
    /* 16DFF4 0026DFF4 2D100002 */  daddu      $2, $16, $0
    /* 16DFF8 0026DFF8 1000BFDF */  ld         $31, 0x10($29)
    /* 16DFFC 0026DFFC 0000B07B */  lq         $16, 0x0($29)
    /* 16E000 0026E000 2000BD27 */  addiu      $29, $29, 0x20
    /* 16E004 0026E004 0800E003 */  jr         $31
    /* 16E008 0026E008 00000000 */   nop
    /* 16E00C 0026E00C 00000000 */  nop
.size func_0026df80, 0x90
