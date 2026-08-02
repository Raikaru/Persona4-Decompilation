.section .text
.set noat
.set noreorder
glabel func_00102d60
    /* 2D60 00102D60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D64 00102D64 1000BFFF */  sd         $31, 0x10($29)
    /* 2D68 00102D68 0000B07F */  sq         $16, 0x0($29)
    /* 2D6C 00102D6C 5E00043C */  lui        $4, %hi(D_005DCB98)
    /* 2D70 00102D70 98CB8424 */  addiu      $4, $4, %lo(D_005DCB98)
    /* 2D74 00102D74 E048110C */  jal        func_00452380
    /* 2D78 00102D78 00000000 */   nop
    /* 2D7C 00102D7C 2D804000 */  daddu      $16, $2, $0
    /* 2D80 00102D80 06000016 */  bnez       $16, .L00102D9C
    /* 2D84 00102D84 00000000 */   nop
    /* 2D88 00102D88 5E00043C */  lui        $4, %hi(D_005DCB68)
    /* 2D8C 00102D8C 68CB8424 */  addiu      $4, $4, %lo(D_005DCB68)
    /* 2D90 00102D90 95000524 */  addiu      $5, $0, 0x95
    /* 2D94 00102D94 CCB5110C */  jal        func_0046d730
    /* 2D98 00102D98 00000000 */   nop
  .L00102D9C:
    /* 2D9C 00102D9C 2D200002 */  daddu      $4, $16, $0
    /* 2DA0 00102DA0 2048110C */  jal        func_00452080
    /* 2DA4 00102DA4 00000000 */   nop
    /* 2DA8 00102DA8 1000BFDF */  ld         $31, 0x10($29)
    /* 2DAC 00102DAC 0000B07B */  lq         $16, 0x0($29)
    /* 2DB0 00102DB0 2000BD27 */  addiu      $29, $29, 0x20
    /* 2DB4 00102DB4 0800E003 */  jr         $31
    /* 2DB8 00102DB8 00000000 */   nop
    /* 2DBC 00102DBC 00000000 */  nop
.size func_00102d60, 0x60
