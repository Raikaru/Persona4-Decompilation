.section .text
.set noat
.set noreorder
glabel func_004be010
    /* 3BE010 004BE010 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE014 004BE014 40FC0324 */  addiu      $3, $0, -0x3C0
    /* 3BE018 004BE018 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE01C 004BE01C 40FCA228 */  slti       $2, $5, -0x3C0
    /* 3BE020 004BE020 0B286200 */  movn       $5, $3, $2
    /* 3BE024 004BE024 0400848C */  lw         $4, 0x4($4)
    /* 3BE028 004BE028 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE02C 004BE02C 44541308 */  j          func_004d5110
    /* 3BE030 004BE030 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE034 004BE034 00000000 */  nop
.size func_004be010, 0x28
