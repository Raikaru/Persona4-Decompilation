.section .text
.set noat
.set noreorder
glabel func_004c9398
    /* 3C9398 004C9398 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C939C 004C939C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C93A0 004C93A0 4627130C */  jal        func_004c9d18
    /* 3C93A4 004C93A4 00000000 */   nop
    /* 3C93A8 004C93A8 F024130C */  jal        func_004c93c0
    /* 3C93AC 004C93AC 00000000 */   nop
    /* 3C93B0 004C93B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3C93B4 004C93B4 4C271308 */  j          func_004c9d30
    /* 3C93B8 004C93B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C93BC 004C93BC 00000000 */  nop
.size func_004c9398, 0x28
