.section .text
.set noat
.set noreorder
glabel func_004defa0
    /* 3DEFA0 004DEFA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DEFA4 004DEFA4 0000B0FF */  sd         $16, 0x0($29)
    /* 3DEFA8 004DEFA8 2D808000 */  daddu      $16, $4, $0
    /* 3DEFAC 004DEFAC 0800BFFF */  sd         $31, 0x8($29)
    /* 3DEFB0 004DEFB0 E080130C */  jal        func_004e0380
    /* 3DEFB4 004DEFB4 E0010CE6 */   swc1      $f12, 0x1E0($16)
    /* 3DEFB8 004DEFB8 867B130C */  jal        func_004dee18
    /* 3DEFBC 004DEFBC 2D200002 */   daddu     $4, $16, $0
    /* 3DEFC0 004DEFC0 02000324 */  addiu      $3, $0, 0x2
    /* 3DEFC4 004DEFC4 03004314 */  bne        $2, $3, .L004DEFD4
    /* 3DEFC8 004DEFC8 2D200002 */   daddu     $4, $16, $0
    /* 3DEFCC 004DEFCC C67B130C */  jal        func_004def18
    /* 3DEFD0 004DEFD0 00000000 */   nop
  .L004DEFD4:
    /* 3DEFD4 004DEFD4 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEFD8 004DEFD8 0800BFDF */  ld         $31, 0x8($29)
    /* 3DEFDC 004DEFDC E6801308 */  j          func_004e0398
    /* 3DEFE0 004DEFE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DEFE4 004DEFE4 00000000 */  nop
.size func_004defa0, 0x48
