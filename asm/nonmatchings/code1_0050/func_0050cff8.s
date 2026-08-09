.section .text
.set noat
.set noreorder
glabel func_0050cff8
    /* 40CFF8 0050CFF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CFFC 0050CFFC 04000624 */  addiu      $6, $0, 0x4
    /* 40D000 0050D000 0000BFFF */  sd         $31, 0x0($29)
    /* 40D004 0050D004 0000BFDF */  ld         $31, 0x0($29)
    /* 40D008 0050D008 04341408 */  j          func_0050d010
    /* 40D00C 0050D00C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050cff8, 0x18
