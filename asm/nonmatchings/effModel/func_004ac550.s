.section .text
.set noat
.set noreorder
glabel func_004ac550
    /* 3AC550 004AC550 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AC554 004AC554 1000BFFF */  sd         $31, 0x10($29)
    /* 3AC558 004AC558 0000B07F */  sq         $16, 0x0($29)
    /* 3AC55C 004AC55C 2D808000 */  daddu      $16, $4, $0
    /* 3AC560 004AC560 54008494 */  lhu        $4, 0x54($4)
    /* 3AC564 004AC564 1805120C */  jal        func_00481460
    /* 3AC568 004AC568 00000000 */   nop
    /* 3AC56C 004AC56C 2D204000 */  daddu      $4, $2, $0
    /* 3AC570 004AC570 2D280002 */  daddu      $5, $16, $0
    /* 3AC574 004AC574 C0B0120C */  jal        func_004ac300
    /* 3AC578 004AC578 00000000 */   nop
    /* 3AC57C 004AC57C 1000BFDF */  ld         $31, 0x10($29)
    /* 3AC580 004AC580 0000B07B */  lq         $16, 0x0($29)
    /* 3AC584 004AC584 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AC588 004AC588 0800E003 */  jr         $31
    /* 3AC58C 004AC58C 00000000 */   nop
.size func_004ac550, 0x40
