.section .text
.set noat
.set noreorder
glabel func_0020ba90
    /* 10BA90 0020BA90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10BA94 0020BA94 0000BFFF */  sd         $31, 0x0($29)
    /* 10BA98 0020BA98 5849110C */  jal        func_00452560
    /* 10BA9C 0020BA9C 00000000 */   nop
    /* 10BAA0 0020BAA0 2007448C */  lw         $4, 0x720($2)
    /* 10BAA4 0020BAA4 F062070C */  jal        func_001d8bc0
    /* 10BAA8 0020BAA8 00000000 */   nop
    /* 10BAAC 0020BAAC 0000BFDF */  ld         $31, 0x0($29)
    /* 10BAB0 0020BAB0 1000BD27 */  addiu      $29, $29, 0x10
    /* 10BAB4 0020BAB4 0800E003 */  jr         $31
    /* 10BAB8 0020BAB8 00000000 */   nop
    /* 10BABC 0020BABC 00000000 */  nop
.size func_0020ba90, 0x30
