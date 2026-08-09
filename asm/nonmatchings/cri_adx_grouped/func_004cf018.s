.section .text
.set noat
.set noreorder
glabel func_004cf018
    /* 3CF018 004CF018 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF01C 004CF01C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CF020 004CF020 0400848C */  lw         $4, 0x4($4)
    /* 3CF024 004CF024 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF028 004CF028 000F1308 */  j          func_004c3c00
    /* 3CF02C 004CF02C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cf018, 0x18
