.section .text
.set noat
.set noreorder
glabel func_0027b5d0
    /* 17B5D0 0027B5D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17B5D4 0027B5D4 1000BFFF */  sd         $31, 0x10($29)
    /* 17B5D8 0027B5D8 0000B07F */  sq         $16, 0x0($29)
    /* 17B5DC 0027B5DC 2D808000 */  daddu      $16, $4, $0
    /* 17B5E0 0027B5E0 6482110C */  jal        func_00460990
    /* 17B5E4 0027B5E4 00000000 */   nop
    /* 17B5E8 0027B5E8 2D284000 */  daddu      $5, $2, $0
    /* 17B5EC 0027B5EC 2800033C */  lui        $3, %hi(func_0027b5a0)
    /* 17B5F0 0027B5F0 A0B56324 */  addiu      $3, $3, %lo(func_0027b5a0)
    /* 17B5F4 0027B5F4 080043AC */  sw         $3, 0x8($2)
    /* 17B5F8 0027B5F8 100050AC */  sw         $16, 0x10($2)
    /* 17B5FC 0027B5FC 7900043C */  lui        $4, %hi(D_007964C0)
    /* 17B600 0027B600 C0648424 */  addiu      $4, $4, %lo(D_007964C0)
    /* 17B604 0027B604 B082110C */  jal        func_00460ac0
    /* 17B608 0027B608 00000000 */   nop
    /* 17B60C 0027B60C 1000BFDF */  ld         $31, 0x10($29)
    /* 17B610 0027B610 0000B07B */  lq         $16, 0x0($29)
    /* 17B614 0027B614 2000BD27 */  addiu      $29, $29, 0x20
    /* 17B618 0027B618 0800E003 */  jr         $31
    /* 17B61C 0027B61C 00000000 */   nop
.size func_0027b5d0, 0x50
