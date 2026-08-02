.section .text
.set noat
.set noreorder
glabel func_00102cb0
    /* 2CB0 00102CB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB4 00102CB4 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB8 00102CB8 0000B07F */  sq         $16, 0x0($29)
    /* 2CBC 00102CBC 5E00043C */  lui        $4, %hi(D_005DCB80)
    /* 2CC0 00102CC0 80CB8424 */  addiu      $4, $4, %lo(D_005DCB80)
    /* 2CC4 00102CC4 E048110C */  jal        func_00452380
    /* 2CC8 00102CC8 00000000 */   nop
    /* 2CCC 00102CCC 2D804000 */  daddu      $16, $2, $0
    /* 2CD0 00102CD0 06000016 */  bnez       $16, .L00102CEC
    /* 2CD4 00102CD4 00000000 */   nop
    /* 2CD8 00102CD8 5E00043C */  lui        $4, %hi(D_005DCB68)
    /* 2CDC 00102CDC 68CB8424 */  addiu      $4, $4, %lo(D_005DCB68)
    /* 2CE0 00102CE0 74000524 */  addiu      $5, $0, 0x74
    /* 2CE4 00102CE4 CCB5110C */  jal        func_0046d730
    /* 2CE8 00102CE8 00000000 */   nop
  .L00102CEC:
    /* 2CEC 00102CEC 2D200002 */  daddu      $4, $16, $0
    /* 2CF0 00102CF0 2048110C */  jal        func_00452080
    /* 2CF4 00102CF4 00000000 */   nop
    /* 2CF8 00102CF8 1000BFDF */  ld         $31, 0x10($29)
    /* 2CFC 00102CFC 0000B07B */  lq         $16, 0x0($29)
    /* 2D00 00102D00 2000BD27 */  addiu      $29, $29, 0x20
    /* 2D04 00102D04 0800E003 */  jr         $31
    /* 2D08 00102D08 00000000 */   nop
    /* 2D0C 00102D0C 00000000 */  nop
.size func_00102cb0, 0x60
