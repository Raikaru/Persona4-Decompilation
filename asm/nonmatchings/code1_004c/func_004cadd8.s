.section .text
.set noat
.set noreorder
glabel func_004cadd8
    /* 3CADD8 004CADD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CADDC 004CADDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3CADE0 004CADE0 0800BFFF */  sd         $31, 0x8($29)
    /* 3CADE4 004CADE4 3615130C */  jal        func_004c54d8
    /* 3CADE8 004CADE8 2D808000 */   daddu     $16, $4, $0
    /* 3CADEC 004CADEC 822B130C */  jal        func_004cae08
    /* 3CADF0 004CADF0 2D200002 */   daddu     $4, $16, $0
    /* 3CADF4 004CADF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3CADF8 004CADF8 0800BFDF */  ld         $31, 0x8($29)
    /* 3CADFC 004CADFC 38151308 */  j          func_004c54e0
    /* 3CAE00 004CAE00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CAE04 004CAE04 00000000 */  nop
.size func_004cadd8, 0x30
