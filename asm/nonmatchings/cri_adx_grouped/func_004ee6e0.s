.section .text
.set noat
.set noreorder
glabel func_004ee6e0
    /* 3EE6E0 004EE6E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EE6E4 004EE6E4 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE6E8 004EE6E8 2D808000 */  daddu      $16, $4, $0
    /* 3EE6EC 004EE6EC 0800B1FF */  sd         $17, 0x8($29)
    /* 3EE6F0 004EE6F0 2D88A000 */  daddu      $17, $5, $0
    /* 3EE6F4 004EE6F4 1000B2FF */  sd         $18, 0x10($29)
    /* 3EE6F8 004EE6F8 1800BFFF */  sd         $31, 0x18($29)
    /* 3EE6FC 004EE6FC 14B5130C */  jal        func_004ed450
    /* 3EE700 004EE700 2D90C000 */   daddu     $18, $6, $0
    /* 3EE704 004EE704 2D200002 */  daddu      $4, $16, $0
    /* 3EE708 004EE708 2D282002 */  daddu      $5, $17, $0
    /* 3EE70C 004EE70C CCB9130C */  jal        func_004ee730
    /* 3EE710 004EE710 2D304002 */   daddu     $6, $18, $0
    /* 3EE714 004EE714 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE718 004EE718 0800B1DF */  ld         $17, 0x8($29)
    /* 3EE71C 004EE71C 1000B2DF */  ld         $18, 0x10($29)
    /* 3EE720 004EE720 1800BFDF */  ld         $31, 0x18($29)
    /* 3EE724 004EE724 1AB51308 */  j          func_004ed468
    /* 3EE728 004EE728 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EE72C 004EE72C 00000000 */  nop
.size func_004ee6e0, 0x50
