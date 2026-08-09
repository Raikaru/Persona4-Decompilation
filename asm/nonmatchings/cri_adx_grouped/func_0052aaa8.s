.section .text
.set noat
.set noreorder
glabel func_0052aaa8
    /* 42AAA8 0052AAA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42AAAC 0052AAAC 0000BFFF */  sd         $31, 0x0($29)
    /* 42AAB0 0052AAB0 3800868C */  lw         $6, 0x38($4)
    /* 42AAB4 0052AAB4 4C00A58C */  lw         $5, 0x4C($5)
    /* 42AAB8 0052AAB8 2400848C */  lw         $4, 0x24($4)
    /* 42AABC 0052AABC 0000BFDF */  ld         $31, 0x0($29)
    /* 42AAC0 0052AAC0 1CB11408 */  j          func_0052c470
    /* 42AAC4 0052AAC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052aaa8, 0x20
