.section .text
.set noat
.set noreorder
glabel func_0033e7c0
    /* 23E7C0 0033E7C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 23E7C4 0033E7C4 1000BFFF */  sd         $31, 0x10($29)
    /* 23E7C8 0033E7C8 0000B07F */  sq         $16, 0x0($29)
    /* 23E7CC 0033E7CC 2D808000 */  daddu      $16, $4, $0
    /* 23E7D0 0033E7D0 3800828C */  lw         $2, 0x38($4)
    /* 23E7D4 0033E7D4 20004424 */  addiu      $4, $2, 0x20
    /* 23E7D8 0033E7D8 50B60D0C */  jal        func_0036d940
    /* 23E7DC 0033E7DC 00000000 */   nop
    /* 23E7E0 0033E7E0 3800048E */  lw         $4, 0x38($16)
    /* 23E7E4 0033E7E4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 23E7E8 0033E7E8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 23E7EC 0033E7EC 09F84000 */  jalr       $2
    /* 23E7F0 0033E7F0 00000000 */   nop
    /* 23E7F4 0033E7F4 1000BFDF */  ld         $31, 0x10($29)
    /* 23E7F8 0033E7F8 0000B07B */  lq         $16, 0x0($29)
    /* 23E7FC 0033E7FC 2000BD27 */  addiu      $29, $29, 0x20
    /* 23E800 0033E800 0800E003 */  jr         $31
    /* 23E804 0033E804 00000000 */   nop
    /* 23E808 0033E808 00000000 */  nop
    /* 23E80C 0033E80C 00000000 */  nop
.size func_0033e7c0, 0x50
