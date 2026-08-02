.section .text
.set noat
.set noreorder
glabel func_0018dcd0
    /* 8DCD0 0018DCD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 8DCD4 0018DCD4 2000BFFF */  sd         $31, 0x20($29)
    /* 8DCD8 0018DCD8 1000B17F */  sq         $17, 0x10($29)
    /* 8DCDC 0018DCDC 0000B07F */  sq         $16, 0x0($29)
    /* 8DCE0 0018DCE0 2D888000 */  daddu      $17, $4, $0
    /* 8DCE4 0018DCE4 3800908C */  lw         $16, 0x38($4)
    /* 8DCE8 0018DCE8 0800048E */  lw         $4, 0x8($16)
    /* 8DCEC 0018DCEC F452110C */  jal        func_00454bd0
    /* 8DCF0 0018DCF0 00000000 */   nop
    /* 8DCF4 0018DCF4 0400048E */  lw         $4, 0x4($16)
    /* 8DCF8 0018DCF8 D0830F0C */  jal        func_003e0f40
    /* 8DCFC 0018DCFC 00000000 */   nop
    /* 8DD00 0018DD00 2014050C */  jal        func_00145080
    /* 8DD04 0018DD04 00000000 */   nop
    /* 8DD08 0018DD08 3800248E */  lw         $4, 0x38($17)
    /* 8DD0C 0018DD0C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 8DD10 0018DD10 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 8DD14 0018DD14 09F84000 */  jalr       $2
    /* 8DD18 0018DD18 00000000 */   nop
    /* 8DD1C 0018DD1C 2000BFDF */  ld         $31, 0x20($29)
    /* 8DD20 0018DD20 1000B17B */  lq         $17, 0x10($29)
    /* 8DD24 0018DD24 0000B07B */  lq         $16, 0x0($29)
    /* 8DD28 0018DD28 3000BD27 */  addiu      $29, $29, 0x30
    /* 8DD2C 0018DD2C 0800E003 */  jr         $31
    /* 8DD30 0018DD30 00000000 */   nop
    /* 8DD34 0018DD34 00000000 */  nop
    /* 8DD38 0018DD38 00000000 */  nop
    /* 8DD3C 0018DD3C 00000000 */  nop
.size func_0018dcd0, 0x70
