.section .text
.set noat
.set noreorder
glabel func_001708a0
    /* 708A0 001708A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 708A4 001708A4 0000BFFF */  sd         $31, 0x0($29)
    /* 708A8 001708A8 2D200000 */  daddu      $4, $0, $0
    /* 708AC 001708AC 5037060C */  jal        func_0018dd40
    /* 708B0 001708B0 00000000 */   nop
    /* 708B4 001708B4 0000BFDF */  ld         $31, 0x0($29)
    /* 708B8 001708B8 1000BD27 */  addiu      $29, $29, 0x10
    /* 708BC 001708BC 0800E003 */  jr         $31
    /* 708C0 001708C0 00000000 */   nop
    /* 708C4 001708C4 00000000 */  nop
    /* 708C8 001708C8 00000000 */  nop
    /* 708CC 001708CC 00000000 */  nop
.size func_001708a0, 0x30
