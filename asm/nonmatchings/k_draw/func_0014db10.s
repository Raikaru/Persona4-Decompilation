.section .text
.set noat
.set noreorder
glabel func_0014db10
    /* 4DB10 0014DB10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 4DB14 0014DB14 1000BFFF */  sd         $31, 0x10($29)
    /* 4DB18 0014DB18 0000B07F */  sq         $16, 0x0($29)
    /* 4DB1C 0014DB1C 3800908C */  lw         $16, 0x38($4)
    /* 4DB20 0014DB20 4400028E */  lw         $2, 0x44($16)
    /* 4DB24 0014DB24 04004014 */  bnez       $2, .L0014DB38
    /* 4DB28 0014DB28 00000000 */   nop
    /* 4DB2C 0014DB2C 2D100000 */  daddu      $2, $0, $0
    /* 4DB30 0014DB30 0C000010 */  b          .L0014DB64
    /* 4DB34 0014DB34 00000000 */   nop
  .L0014DB38:
    /* 4DB38 0014DB38 6482110C */  jal        func_00460990
    /* 4DB3C 0014DB3C 00000000 */   nop
    /* 4DB40 0014DB40 2D284000 */  daddu      $5, $2, $0
    /* 4DB44 0014DB44 1500033C */  lui        $3, %hi(func_0014da30)
    /* 4DB48 0014DB48 30DA6324 */  addiu      $3, $3, %lo(func_0014da30)
    /* 4DB4C 0014DB4C 080043AC */  sw         $3, 0x8($2)
    /* 4DB50 0014DB50 100050AC */  sw         $16, 0x10($2)
    /* 4DB54 0014DB54 4C00048E */  lw         $4, 0x4C($16)
    /* 4DB58 0014DB58 B082110C */  jal        func_00460ac0
    /* 4DB5C 0014DB5C 00000000 */   nop
    /* 4DB60 0014DB60 2D100000 */  daddu      $2, $0, $0
  .L0014DB64:
    /* 4DB64 0014DB64 1000BFDF */  ld         $31, 0x10($29)
    /* 4DB68 0014DB68 0000B07B */  lq         $16, 0x0($29)
    /* 4DB6C 0014DB6C 2000BD27 */  addiu      $29, $29, 0x20
    /* 4DB70 0014DB70 0800E003 */  jr         $31
    /* 4DB74 0014DB74 00000000 */   nop
    /* 4DB78 0014DB78 00000000 */  nop
    /* 4DB7C 0014DB7C 00000000 */  nop
.size func_0014db10, 0x70
