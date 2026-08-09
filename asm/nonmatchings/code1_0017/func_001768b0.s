.section .text
.set noat
.set noreorder
glabel func_001768b0
    /* 768B0 001768B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 768B4 001768B4 0000BFFF */  sd         $31, 0x0($29)
    /* 768B8 001768B8 A454050C */  jal        func_00155290
    /* 768BC 001768BC 00000000 */   nop
    /* 768C0 001768C0 2D204000 */  daddu      $4, $2, $0
    /* 768C4 001768C4 D4730A0C */  jal        func_0029cf50
    /* 768C8 001768C8 00000000 */   nop
    /* 768CC 001768CC 01000224 */  addiu      $2, $0, 0x1
    /* 768D0 001768D0 0000BFDF */  ld         $31, 0x0($29)
    /* 768D4 001768D4 1000BD27 */  addiu      $29, $29, 0x10
    /* 768D8 001768D8 0800E003 */  jr         $31
    /* 768DC 001768DC 00000000 */   nop
.size func_001768b0, 0x30
