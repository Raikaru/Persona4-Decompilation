.section .text
.set noat
.set noreorder
glabel func_00468fa0
    /* 368FA0 00468FA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 368FA4 00468FA4 1000BFFF */  sd         $31, 0x10($29)
    /* 368FA8 00468FA8 0000B07F */  sq         $16, 0x0($29)
    /* 368FAC 00468FAC 3800908C */  lw         $16, 0x38($4)
    /* 368FB0 00468FB0 6482110C */  jal        func_00460990
    /* 368FB4 00468FB4 00000000 */   nop
    /* 368FB8 00468FB8 2D284000 */  daddu      $5, $2, $0
    /* 368FBC 00468FBC 4700033C */  lui        $3, %hi(func_00468ff0)
    /* 368FC0 00468FC0 F08F6324 */  addiu      $3, $3, %lo(func_00468ff0)
    /* 368FC4 00468FC4 080043AC */  sw         $3, 0x8($2)
    /* 368FC8 00468FC8 100050AC */  sw         $16, 0x10($2)
    /* 368FCC 00468FCC 1802048E */  lw         $4, 0x218($16)
    /* 368FD0 00468FD0 B082110C */  jal        func_00460ac0
    /* 368FD4 00468FD4 00000000 */   nop
    /* 368FD8 00468FD8 2D100000 */  daddu      $2, $0, $0
    /* 368FDC 00468FDC 1000BFDF */  ld         $31, 0x10($29)
    /* 368FE0 00468FE0 0000B07B */  lq         $16, 0x0($29)
    /* 368FE4 00468FE4 2000BD27 */  addiu      $29, $29, 0x20
    /* 368FE8 00468FE8 0800E003 */  jr         $31
    /* 368FEC 00468FEC 00000000 */   nop
.size func_00468fa0, 0x50
