.section .text
.set noat
.set noreorder
glabel func_00105fa0
    /* 5FA0 00105FA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 5FA4 00105FA4 1000BFFF */  sd         $31, 0x10($29)
    /* 5FA8 00105FA8 0000B07F */  sq         $16, 0x0($29)
    /* 5FAC 00105FAC 2D808000 */  daddu      $16, $4, $0
    /* 5FB0 00105FB0 9800013C */  lui        $1, (0x989680 >> 16)
    /* 5FB4 00105FB4 80962134 */  ori        $1, $1, (0x989680 & 0xFFFF)
    /* 5FB8 00105FB8 2B080102 */  sltu       $1, $16, $1
    /* 5FBC 00105FBC 06002014 */  bnez       $1, .L00105FD8
    /* 5FC0 00105FC0 00000000 */   nop
    /* 5FC4 00105FC4 5E00043C */  lui        $4, %hi(D_005E4298)
    /* 5FC8 00105FC8 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* 5FCC 00105FCC 59030524 */  addiu      $5, $0, 0x359
    /* 5FD0 00105FD0 CCB5110C */  jal        func_0046d730
    /* 5FD4 00105FD4 00000000 */   nop
  .L00105FD8:
    /* 5FD8 00105FD8 7A00033C */  lui        $3, %hi(D_0079B68C)
    /* 5FDC 00105FDC 8CB670AC */  sw         $16, %lo(D_0079B68C)($3)
    /* 5FE0 00105FE0 1000BFDF */  ld         $31, 0x10($29)
    /* 5FE4 00105FE4 0000B07B */  lq         $16, 0x0($29)
    /* 5FE8 00105FE8 2000BD27 */  addiu      $29, $29, 0x20
    /* 5FEC 00105FEC 0800E003 */  jr         $31
    /* 5FF0 00105FF0 00000000 */   nop
    /* 5FF4 00105FF4 00000000 */  nop
    /* 5FF8 00105FF8 00000000 */  nop
    /* 5FFC 00105FFC 00000000 */  nop
.size func_00105fa0, 0x60
