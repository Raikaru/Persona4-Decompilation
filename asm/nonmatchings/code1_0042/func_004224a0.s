.section .text
.set noat
.set noreorder
glabel func_004224a0
    /* 3224A0 004224A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3224A4 004224A4 0000BFFF */  sd         $31, 0x0($29)
    /* 3224A8 004224A8 6885100C */  jal        func_004215a0
    /* 3224AC 004224AC 00000000 */   nop
    /* 3224B0 004224B0 0F000000 */  sync
    /* 3224B4 004224B4 0000BFDF */  ld         $31, 0x0($29)
    /* 3224B8 004224B8 0800E003 */  jr         $31
    /* 3224BC 004224BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004224a0, 0x20
