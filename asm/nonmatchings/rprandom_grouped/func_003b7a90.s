.section .text
.set noat
.set noreorder
glabel func_003b7a90
    /* 2B7A90 003B7A90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2B7A94 003B7A94 8800023C */  lui        $2, %hi(D_00886494)
    /* 2B7A98 003B7A98 1000BFFF */  sd         $31, 0x10($29)
    /* 2B7A9C 003B7A9C 2D280000 */  daddu      $5, $0, $0
    /* 2B7AA0 003B7AA0 0000B07F */  sq         $16, 0x0($29)
    /* 2B7AA4 003B7AA4 04000624 */  addiu      $6, $0, 0x4
    /* 2B7AA8 003B7AA8 9464428C */  lw         $2, %lo(D_00886494)($2)
    /* 2B7AAC 003B7AAC 2D808000 */  daddu      $16, $4, $0
    /* 2B7AB0 003B7AB0 72FE100C */  jal        func_0043f9c8
    /* 2B7AB4 003B7AB4 21200202 */   addu      $4, $16, $2
    /* 2B7AB8 003B7AB8 2D100002 */  daddu      $2, $16, $0
    /* 2B7ABC 003B7ABC 1000BFDF */  ld         $31, 0x10($29)
    /* 2B7AC0 003B7AC0 0000B07B */  lq         $16, 0x0($29)
    /* 2B7AC4 003B7AC4 0800E003 */  jr         $31
    /* 2B7AC8 003B7AC8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2B7ACC 003B7ACC 00000000 */  nop
.size func_003b7a90, 0x40
