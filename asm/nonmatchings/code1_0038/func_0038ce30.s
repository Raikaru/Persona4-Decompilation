.section .text
.set noat
.set noreorder
glabel func_0038ce30
    /* 28CE30 0038CE30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 28CE34 0038CE34 1000BFFF */  sd         $31, 0x10($29)
    /* 28CE38 0038CE38 0000B07F */  sq         $16, 0x0($29)
    /* 28CE3C 0038CE3C 3800908C */  lw         $16, 0x38($4)
    /* 28CE40 0038CE40 080000AE */  sw         $0, 0x8($16)
    /* 28CE44 0038CE44 0C0000AE */  sw         $0, 0xC($16)
    /* 28CE48 0038CE48 7900043C */  lui        $4, %hi(D_00794990)
    /* 28CE4C 0038CE4C 90498424 */  addiu      $4, $4, %lo(D_00794990)
    /* 28CE50 0038CE50 08000526 */  addiu      $5, $16, 0x8
    /* 28CE54 0038CE54 B082110C */  jal        func_00460ac0
    /* 28CE58 0038CE58 00000000 */   nop
    /* 28CE5C 0038CE5C 380000AE */  sw         $0, 0x38($16)
    /* 28CE60 0038CE60 3C0000AE */  sw         $0, 0x3C($16)
    /* 28CE64 0038CE64 7900043C */  lui        $4, %hi(D_00794E40)
    /* 28CE68 0038CE68 404E8424 */  addiu      $4, $4, %lo(D_00794E40)
    /* 28CE6C 0038CE6C 38000526 */  addiu      $5, $16, 0x38
    /* 28CE70 0038CE70 B082110C */  jal        func_00460ac0
    /* 28CE74 0038CE74 00000000 */   nop
    /* 28CE78 0038CE78 2D100000 */  daddu      $2, $0, $0
    /* 28CE7C 0038CE7C 1000BFDF */  ld         $31, 0x10($29)
    /* 28CE80 0038CE80 0000B07B */  lq         $16, 0x0($29)
    /* 28CE84 0038CE84 2000BD27 */  addiu      $29, $29, 0x20
    /* 28CE88 0038CE88 0800E003 */  jr         $31
    /* 28CE8C 0038CE8C 00000000 */   nop
.size func_0038ce30, 0x60
