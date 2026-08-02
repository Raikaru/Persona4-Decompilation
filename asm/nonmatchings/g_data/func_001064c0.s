.section .text
.set noat
.set noreorder
glabel func_001064c0
    /* 64C0 001064C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 64C4 001064C4 0000BFFF */  sd         $31, 0x0($29)
    /* 64C8 001064C8 2D200000 */  daddu      $4, $0, $0
    /* 64CC 001064CC 842D040C */  jal        func_0010b610
    /* 64D0 001064D0 00000000 */   nop
    /* 64D4 001064D4 0000BFDF */  ld         $31, 0x0($29)
    /* 64D8 001064D8 1000BD27 */  addiu      $29, $29, 0x10
    /* 64DC 001064DC 0800E003 */  jr         $31
    /* 64E0 001064E0 00000000 */   nop
    /* 64E4 001064E4 00000000 */  nop
    /* 64E8 001064E8 00000000 */  nop
    /* 64EC 001064EC 00000000 */  nop
.size func_001064c0, 0x30
