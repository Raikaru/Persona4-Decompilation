.section .text
.set noat
.set noreorder
glabel func_004c54a8
    /* 3C54A8 004C54A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C54AC 004C54AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3C54B0 004C54B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3C54B4 004C54B4 82C11308 */  j          func_004f0608
    /* 3C54B8 004C54B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C54BC 004C54BC 00000000 */  nop
.size func_004c54a8, 0x18
