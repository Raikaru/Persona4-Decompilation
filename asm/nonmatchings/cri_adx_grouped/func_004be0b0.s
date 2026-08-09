.section .text
.set noat
.set noreorder
glabel func_004be0b0
    /* 3BE0B0 004BE0B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE0B4 004BE0B4 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE0B8 004BE0B8 0400848C */  lw         $4, 0x4($4)
    /* 3BE0BC 004BE0BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE0C0 004BE0C0 72571308 */  j          func_004d5dc8
    /* 3BE0C4 004BE0C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be0b0, 0x18
