.section .text
.set noat
.set noreorder
glabel func_004be3a8
    /* 3BE3A8 004BE3A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE3AC 004BE3AC 40FC0324 */  addiu      $3, $0, -0x3C0
    /* 3BE3B0 004BE3B0 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE3B4 004BE3B4 40FCC228 */  slti       $2, $6, -0x3C0
    /* 3BE3B8 004BE3B8 0B306200 */  movn       $6, $3, $2
    /* 3BE3BC 004BE3BC 0400848C */  lw         $4, 0x4($4)
    /* 3BE3C0 004BE3C0 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE3C4 004BE3C4 5E7F1308 */  j          func_004dfd78
    /* 3BE3C8 004BE3C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE3CC 004BE3CC 00000000 */  nop
.size func_004be3a8, 0x28
