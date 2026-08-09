.section .text
.set noat
.set noreorder
glabel func_004f14e0
    /* 3F14E0 004F14E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F14E4 004F14E4 0000B0FF */  sd         $16, 0x0($29)
    /* 3F14E8 004F14E8 0800BFFF */  sd         $31, 0x8($29)
    /* 3F14EC 004F14EC 128D130C */  jal        func_004e3448
    /* 3F14F0 004F14F0 2D808000 */   daddu     $16, $4, $0
    /* 3F14F4 004F14F4 03004014 */  bnez       $2, .L004F1504
    /* 3F14F8 004F14F8 2D200002 */   daddu     $4, $16, $0
    /* 3F14FC 004F14FC 32C5130C */  jal        func_004f14c8
    /* 3F1500 004F1500 00000000 */   nop
  .L004F1504:
    /* 3F1504 004F1504 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1508 004F1508 0800BFDF */  ld         $31, 0x8($29)
    /* 3F150C 004F150C 0800E003 */  jr         $31
    /* 3F1510 004F1510 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1514 004F1514 00000000 */  nop
.size func_004f14e0, 0x38
