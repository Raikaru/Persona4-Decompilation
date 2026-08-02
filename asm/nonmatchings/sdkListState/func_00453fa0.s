.section .text
.set noat
.set noreorder
glabel func_00453fa0
    /* 353FA0 00453FA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 353FA4 00453FA4 2000BFFF */  sd         $31, 0x20($29)
    /* 353FA8 00453FA8 1000B17F */  sq         $17, 0x10($29)
    /* 353FAC 00453FAC 0000B07F */  sq         $16, 0x0($29)
    /* 353FB0 00453FB0 2D888000 */  daddu      $17, $4, $0
    /* 353FB4 00453FB4 2D80A000 */  daddu      $16, $5, $0
    /* 353FB8 00453FB8 06002016 */  bnez       $17, .L00453FD4
    /* 353FBC 00453FBC 00000000 */   nop
    /* 353FC0 00453FC0 7100043C */  lui        $4, %hi(D_007105E8)
    /* 353FC4 00453FC4 E8058424 */  addiu      $4, $4, %lo(D_007105E8)
    /* 353FC8 00453FC8 44010524 */  addiu      $5, $0, 0x144
    /* 353FCC 00453FCC CCB5110C */  jal        func_0046d730
    /* 353FD0 00453FD0 00000000 */   nop
  .L00453FD4:
    /* 353FD4 00453FD4 140030AE */  sw         $16, 0x14($17)
    /* 353FD8 00453FD8 2000BFDF */  ld         $31, 0x20($29)
    /* 353FDC 00453FDC 1000B17B */  lq         $17, 0x10($29)
    /* 353FE0 00453FE0 0000B07B */  lq         $16, 0x0($29)
    /* 353FE4 00453FE4 3000BD27 */  addiu      $29, $29, 0x30
    /* 353FE8 00453FE8 0800E003 */  jr         $31
    /* 353FEC 00453FEC 00000000 */   nop
.size func_00453fa0, 0x50
