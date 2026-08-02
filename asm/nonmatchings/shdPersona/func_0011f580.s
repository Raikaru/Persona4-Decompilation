.section .text
.set noat
.set noreorder
glabel func_0011f580
    /* 1F580 0011F580 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1F584 0011F584 0000BFFF */  sd         $31, 0x0($29)
    /* 1F588 0011F588 2048110C */  jal        func_00452080
    /* 1F58C 0011F58C 00000000 */   nop
    /* 1F590 0011F590 0000BFDF */  ld         $31, 0x0($29)
    /* 1F594 0011F594 1000BD27 */  addiu      $29, $29, 0x10
    /* 1F598 0011F598 0800E003 */  jr         $31
    /* 1F59C 0011F59C 00000000 */   nop
.size func_0011f580, 0x20
