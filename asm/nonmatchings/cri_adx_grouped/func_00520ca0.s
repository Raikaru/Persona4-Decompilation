.section .text
.set noat
.set noreorder
glabel func_00520ca0
    /* 420CA0 00520CA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 420CA4 00520CA4 0000BFFF */  sd         $31, 0x0($29)
    /* 420CA8 00520CA8 C01FC48C */  lw         $4, 0x1FC0($6)
    /* 420CAC 00520CAC CE80140C */  jal        func_00520338
    /* 420CB0 00520CB0 98118424 */   addiu     $4, $4, 0x1198
    /* 420CB4 00520CB4 01000224 */  addiu      $2, $0, 0x1
    /* 420CB8 00520CB8 0000BFDF */  ld         $31, 0x0($29)
    /* 420CBC 00520CBC 0800E003 */  jr         $31
    /* 420CC0 00520CC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 420CC4 00520CC4 00000000 */  nop
.size func_00520ca0, 0x28
