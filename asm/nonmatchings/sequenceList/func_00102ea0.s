.section .text
.set noat
.set noreorder
glabel func_00102ea0
    /* 2EA0 00102EA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2EA4 00102EA4 0000BFFF */  sd         $31, 0x0($29)
    /* 2EA8 00102EA8 C04D060C */  jal        func_00193700
    /* 2EAC 00102EAC 00000000 */   nop
    /* 2EB0 00102EB0 2B100200 */  sltu       $2, $0, $2
    /* 2EB4 00102EB4 0000BFDF */  ld         $31, 0x0($29)
    /* 2EB8 00102EB8 1000BD27 */  addiu      $29, $29, 0x10
    /* 2EBC 00102EBC 0800E003 */  jr         $31
    /* 2EC0 00102EC0 00000000 */   nop
    /* 2EC4 00102EC4 00000000 */  nop
    /* 2EC8 00102EC8 00000000 */  nop
    /* 2ECC 00102ECC 00000000 */  nop
.size func_00102ea0, 0x30
