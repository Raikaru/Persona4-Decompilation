.section .text
.set noat
.set noreorder
glabel func_004c7690
    /* 3C7690 004C7690 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C7694 004C7694 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7698 004C7698 2D808000 */  daddu      $16, $4, $0
    /* 3C769C 004C769C 0800B1FF */  sd         $17, 0x8($29)
    /* 3C76A0 004C76A0 2D88A000 */  daddu      $17, $5, $0
    /* 3C76A4 004C76A4 1000B2FF */  sd         $18, 0x10($29)
    /* 3C76A8 004C76A8 2D90C000 */  daddu      $18, $6, $0
    /* 3C76AC 004C76AC 1800B3FF */  sd         $19, 0x18($29)
    /* 3C76B0 004C76B0 2000BFFF */  sd         $31, 0x20($29)
    /* 3C76B4 004C76B4 4627130C */  jal        func_004c9d18
    /* 3C76B8 004C76B8 2D98E000 */   daddu     $19, $7, $0
    /* 3C76BC 004C76BC 2D200002 */  daddu      $4, $16, $0
    /* 3C76C0 004C76C0 2D282002 */  daddu      $5, $17, $0
    /* 3C76C4 004C76C4 2D304002 */  daddu      $6, $18, $0
    /* 3C76C8 004C76C8 BE1D130C */  jal        func_004c76f8
    /* 3C76CC 004C76CC 2D386002 */   daddu     $7, $19, $0
    /* 3C76D0 004C76D0 4C27130C */  jal        func_004c9d30
    /* 3C76D4 004C76D4 2D804000 */   daddu     $16, $2, $0
    /* 3C76D8 004C76D8 0800B1DF */  ld         $17, 0x8($29)
    /* 3C76DC 004C76DC 2D100002 */  daddu      $2, $16, $0
    /* 3C76E0 004C76E0 1000B2DF */  ld         $18, 0x10($29)
    /* 3C76E4 004C76E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3C76E8 004C76E8 1800B3DF */  ld         $19, 0x18($29)
    /* 3C76EC 004C76EC 2000BFDF */  ld         $31, 0x20($29)
    /* 3C76F0 004C76F0 0800E003 */  jr         $31
    /* 3C76F4 004C76F4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004c7690, 0x68
