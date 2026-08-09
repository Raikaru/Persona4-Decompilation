.section .text
.set noat
.set noreorder
glabel func_00511198
    /* 411198 00511198 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41119C 0051119C 0000BFFF */  sd         $31, 0x0($29)
    /* 4111A0 005111A0 9AC1130C */  jal        func_004f0668
    /* 4111A4 005111A4 00000000 */   nop
    /* 4111A8 005111A8 0000BFDF */  ld         $31, 0x0($29)
    /* 4111AC 005111AC 01000224 */  addiu      $2, $0, 0x1
    /* 4111B0 005111B0 0800E003 */  jr         $31
    /* 4111B4 005111B4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511198, 0x20
