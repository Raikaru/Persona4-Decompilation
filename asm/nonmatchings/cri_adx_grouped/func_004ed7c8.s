.section .text
.set noat
.set noreorder
glabel func_004ed7c8
    /* 3ED7C8 004ED7C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED7CC 004ED7CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED7D0 004ED7D0 0800BFFF */  sd         $31, 0x8($29)
    /* 3ED7D4 004ED7D4 14B5130C */  jal        func_004ed450
    /* 3ED7D8 004ED7D8 2D808000 */   daddu     $16, $4, $0
    /* 3ED7DC 004ED7DC 00B6130C */  jal        func_004ed800
    /* 3ED7E0 004ED7E0 2D200002 */   daddu     $4, $16, $0
    /* 3ED7E4 004ED7E4 1AB5130C */  jal        func_004ed468
    /* 3ED7E8 004ED7E8 2D804000 */   daddu     $16, $2, $0
    /* 3ED7EC 004ED7EC 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED7F0 004ED7F0 2D100002 */  daddu      $2, $16, $0
    /* 3ED7F4 004ED7F4 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED7F8 004ED7F8 0800E003 */  jr         $31
    /* 3ED7FC 004ED7FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ed7c8, 0x38
