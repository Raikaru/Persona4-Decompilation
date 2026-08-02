.section .text
.set noat
.set noreorder
glabel func_0049fba0
    /* 39FBA0 0049FBA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 39FBA4 0049FBA4 1000BFFF */  sd         $31, 0x10($29)
    /* 39FBA8 0049FBA8 0000B07F */  sq         $16, 0x0($29)
    /* 39FBAC 0049FBAC 2D808000 */  daddu      $16, $4, $0
    /* 39FBB0 0049FBB0 0400848C */  lw         $4, 0x4($4)
    /* 39FBB4 0049FBB4 FC0C120C */  jal        func_004833f0
    /* 39FBB8 0049FBB8 00000000 */   nop
    /* 39FBBC 0049FBBC 0800048E */  lw         $4, 0x8($16)
    /* 39FBC0 0049FBC0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 39FBC4 0049FBC4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 39FBC8 0049FBC8 09F84000 */  jalr       $2
    /* 39FBCC 0049FBCC 00000000 */   nop
    /* 39FBD0 0049FBD0 1000BFDF */  ld         $31, 0x10($29)
    /* 39FBD4 0049FBD4 0000B07B */  lq         $16, 0x0($29)
    /* 39FBD8 0049FBD8 2000BD27 */  addiu      $29, $29, 0x20
    /* 39FBDC 0049FBDC 0800E003 */  jr         $31
    /* 39FBE0 0049FBE0 00000000 */   nop
    /* 39FBE4 0049FBE4 00000000 */  nop
    /* 39FBE8 0049FBE8 00000000 */  nop
    /* 39FBEC 0049FBEC 00000000 */  nop
.size func_0049fba0, 0x50
