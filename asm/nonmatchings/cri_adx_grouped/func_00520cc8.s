.section .text
.set noat
.set noreorder
glabel func_00520cc8
    /* 420CC8 00520CC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 420CCC 00520CCC 0000BFFF */  sd         $31, 0x0($29)
    /* 420CD0 00520CD0 C01FC48C */  lw         $4, 0x1FC0($6)
    /* 420CD4 00520CD4 0E81140C */  jal        func_00520438
    /* 420CD8 00520CD8 98118424 */   addiu     $4, $4, 0x1198
    /* 420CDC 00520CDC 01000224 */  addiu      $2, $0, 0x1
    /* 420CE0 00520CE0 0000BFDF */  ld         $31, 0x0($29)
    /* 420CE4 00520CE4 0800E003 */  jr         $31
    /* 420CE8 00520CE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 420CEC 00520CEC 00000000 */  nop
.size func_00520cc8, 0x28
