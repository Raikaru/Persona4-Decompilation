.section .text
.set noat
.set noreorder
glabel func_004edf18
    /* 3EDF18 004EDF18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDF1C 004EDF1C 0000BFFF */  sd         $31, 0x0($29)
    /* 3EDF20 004EDF20 FAB4130C */  jal        func_004ed3e8
    /* 3EDF24 004EDF24 00000000 */   nop
    /* 3EDF28 004EDF28 14B5130C */  jal        func_004ed450
    /* 3EDF2C 004EDF2C 00000000 */   nop
    /* 3EDF30 004EDF30 D2B7130C */  jal        func_004edf48
    /* 3EDF34 004EDF34 00000000 */   nop
    /* 3EDF38 004EDF38 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDF3C 004EDF3C 1AB51308 */  j          func_004ed468
    /* 3EDF40 004EDF40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDF44 004EDF44 00000000 */  nop
.size func_004edf18, 0x30
