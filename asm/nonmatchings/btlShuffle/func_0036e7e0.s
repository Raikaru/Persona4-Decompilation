.section .text
.set noat
.set noreorder
glabel func_0036e7e0
    /* 26E7E0 0036E7E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26E7E4 0036E7E4 0000BFFF */  sd         $31, 0x0($29)
    /* 26E7E8 0036E7E8 5849110C */  jal        func_00452560
    /* 26E7EC 0036E7EC 00000000 */   nop
    /* 26E7F0 0036E7F0 00004394 */  lhu        $3, 0x0($2)
    /* 26E7F4 0036E7F4 01006334 */  ori        $3, $3, 0x1
    /* 26E7F8 0036E7F8 000043A4 */  sh         $3, 0x0($2)
    /* 26E7FC 0036E7FC 0000BFDF */  ld         $31, 0x0($29)
    /* 26E800 0036E800 1000BD27 */  addiu      $29, $29, 0x10
    /* 26E804 0036E804 0800E003 */  jr         $31
    /* 26E808 0036E808 00000000 */   nop
    /* 26E80C 0036E80C 00000000 */  nop
.size func_0036e7e0, 0x30
