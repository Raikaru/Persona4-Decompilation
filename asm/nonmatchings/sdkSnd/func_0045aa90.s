.section .text
.set noat
.set noreorder
glabel func_0045aa90
    /* 35AA90 0045AA90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 35AA94 0045AA94 0000BFFF */  sd         $31, 0x0($29)
    /* 35AA98 0045AA98 4471110C */  jal        func_0045c510
    /* 35AA9C 0045AA9C 00000000 */   nop
    /* 35AAA0 0045AAA0 01000224 */  addiu      $2, $0, 0x1
    /* 35AAA4 0045AAA4 0000BFDF */  ld         $31, 0x0($29)
    /* 35AAA8 0045AAA8 1000BD27 */  addiu      $29, $29, 0x10
    /* 35AAAC 0045AAAC 0800E003 */  jr         $31
    /* 35AAB0 0045AAB0 00000000 */   nop
    /* 35AAB4 0045AAB4 00000000 */  nop
    /* 35AAB8 0045AAB8 00000000 */  nop
    /* 35AABC 0045AABC 00000000 */  nop
.size func_0045aa90, 0x30
