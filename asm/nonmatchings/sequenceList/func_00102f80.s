.section .text
.set noat
.set noreorder
glabel func_00102f80
    /* 2F80 00102F80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2F84 00102F84 1000BFFF */  sd         $31, 0x10($29)
    /* 2F88 00102F88 0000B07F */  sq         $16, 0x0($29)
    /* 2F8C 00102F8C 5E00043C */  lui        $4, %hi(D_005DCBB0)
    /* 2F90 00102F90 B0CB8424 */  addiu      $4, $4, %lo(D_005DCBB0)
    /* 2F94 00102F94 E048110C */  jal        func_00452380
    /* 2F98 00102F98 00000000 */   nop
    /* 2F9C 00102F9C 2D804000 */  daddu      $16, $2, $0
    /* 2FA0 00102FA0 06000016 */  bnez       $16, .L00102FBC
    /* 2FA4 00102FA4 00000000 */   nop
    /* 2FA8 00102FA8 5E00043C */  lui        $4, %hi(D_005DCB68)
    /* 2FAC 00102FAC 68CB8424 */  addiu      $4, $4, %lo(D_005DCB68)
    /* 2FB0 00102FB0 45010524 */  addiu      $5, $0, 0x145
    /* 2FB4 00102FB4 CCB5110C */  jal        func_0046d730
    /* 2FB8 00102FB8 00000000 */   nop
  .L00102FBC:
    /* 2FBC 00102FBC 2D200002 */  daddu      $4, $16, $0
    /* 2FC0 00102FC0 2048110C */  jal        func_00452080
    /* 2FC4 00102FC4 00000000 */   nop
    /* 2FC8 00102FC8 1000BFDF */  ld         $31, 0x10($29)
    /* 2FCC 00102FCC 0000B07B */  lq         $16, 0x0($29)
    /* 2FD0 00102FD0 2000BD27 */  addiu      $29, $29, 0x20
    /* 2FD4 00102FD4 0800E003 */  jr         $31
    /* 2FD8 00102FD8 00000000 */   nop
    /* 2FDC 00102FDC 00000000 */  nop
.size func_00102f80, 0x60
