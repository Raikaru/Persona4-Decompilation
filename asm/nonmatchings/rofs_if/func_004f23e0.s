.section .text
.set noat
.set noreorder
glabel func_004f23e0
    /* 3F23E0 004F23E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F23E4 004F23E4 0000B0FF */  sd         $16, 0x0($29)
    /* 3F23E8 004F23E8 0800BFFF */  sd         $31, 0x8($29)
    /* 3F23EC 004F23EC 28D5130C */  jal        func_004f54a0
    /* 3F23F0 004F23F0 2D808000 */   daddu     $16, $4, $0
    /* 3F23F4 004F23F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3F23F8 004F23F8 2D200002 */  daddu      $4, $16, $0
    /* 3F23FC 004F23FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2400 004F2400 84C71308 */  j          func_004f1e10
    /* 3F2404 004F2404 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f23e0, 0x28
