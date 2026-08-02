.section .text
.set noat
.set noreorder
glabel func_0033de40
    /* 23DE40 0033DE40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 23DE44 0033DE44 1000BFFF */  sd         $31, 0x10($29)
    /* 23DE48 0033DE48 0000B07F */  sq         $16, 0x0($29)
    /* 23DE4C 0033DE4C 2D808000 */  daddu      $16, $4, $0
    /* 23DE50 0033DE50 02000424 */  addiu      $4, $0, 0x2
    /* 23DE54 0033DE54 2D280000 */  daddu      $5, $0, $0
    /* 23DE58 0033DE58 2D300000 */  daddu      $6, $0, $0
    /* 23DE5C 0033DE5C B06A110C */  jal        func_0045aac0
    /* 23DE60 0033DE60 00000000 */   nop
    /* 23DE64 0033DE64 3800048E */  lw         $4, 0x38($16)
    /* 23DE68 0033DE68 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 23DE6C 0033DE6C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 23DE70 0033DE70 09F84000 */  jalr       $2
    /* 23DE74 0033DE74 00000000 */   nop
    /* 23DE78 0033DE78 1000BFDF */  ld         $31, 0x10($29)
    /* 23DE7C 0033DE7C 0000B07B */  lq         $16, 0x0($29)
    /* 23DE80 0033DE80 2000BD27 */  addiu      $29, $29, 0x20
    /* 23DE84 0033DE84 0800E003 */  jr         $31
    /* 23DE88 0033DE88 00000000 */   nop
    /* 23DE8C 0033DE8C 00000000 */  nop
.size func_0033de40, 0x50
