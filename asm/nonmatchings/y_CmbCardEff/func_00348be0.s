.section .text
.set noat
.set noreorder
glabel func_00348be0
    /* 248BE0 00348BE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 248BE4 00348BE4 0000BFFF */  sd         $31, 0x0($29)
    /* 248BE8 00348BE8 3800828C */  lw         $2, 0x38($4)
    /* 248BEC 00348BEC 0000448C */  lw         $4, 0x0($2)
    /* 248BF0 00348BF0 F054110C */  jal        func_004553c0
    /* 248BF4 00348BF4 00000000 */   nop
    /* 248BF8 00348BF8 2B100200 */  sltu       $2, $0, $2
    /* 248BFC 00348BFC 0000BFDF */  ld         $31, 0x0($29)
    /* 248C00 00348C00 1000BD27 */  addiu      $29, $29, 0x10
    /* 248C04 00348C04 0800E003 */  jr         $31
    /* 248C08 00348C08 00000000 */   nop
    /* 248C0C 00348C0C 00000000 */  nop
.size func_00348be0, 0x30
