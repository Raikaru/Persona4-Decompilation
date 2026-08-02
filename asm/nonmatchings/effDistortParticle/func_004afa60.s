.section .text
.set noat
.set noreorder
glabel func_004afa60
    /* 3AFA60 004AFA60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AFA64 004AFA64 1000BFFF */  sd         $31, 0x10($29)
    /* 3AFA68 004AFA68 0000B07F */  sq         $16, 0x0($29)
    /* 3AFA6C 004AFA6C 2D808000 */  daddu      $16, $4, $0
    /* 3AFA70 004AFA70 2D20A000 */  daddu      $4, $5, $0
    /* 3AFA74 004AFA74 E404120C */  jal        func_00481390
    /* 3AFA78 004AFA78 00000000 */   nop
    /* 3AFA7C 004AFA7C 600002AE */  sw         $2, 0x60($16)
    /* 3AFA80 004AFA80 1000BFDF */  ld         $31, 0x10($29)
    /* 3AFA84 004AFA84 0000B07B */  lq         $16, 0x0($29)
    /* 3AFA88 004AFA88 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AFA8C 004AFA8C 0800E003 */  jr         $31
    /* 3AFA90 004AFA90 00000000 */   nop
    /* 3AFA94 004AFA94 00000000 */  nop
    /* 3AFA98 004AFA98 00000000 */  nop
    /* 3AFA9C 004AFA9C 00000000 */  nop
.size func_004afa60, 0x40
