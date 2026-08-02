.section .text
.set noat
.set noreorder
glabel func_004ab8a0
    /* 3AB8A0 004AB8A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB8A4 004AB8A4 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB8A8 004AB8A8 0000B07F */  sq         $16, 0x0($29)
    /* 3AB8AC 004AB8AC 2D808000 */  daddu      $16, $4, $0
    /* 3AB8B0 004AB8B0 1800838C */  lw         $3, 0x18($4)
    /* 3AB8B4 004AB8B4 40100300 */  sll        $2, $3, 1
    /* 3AB8B8 004AB8B8 21104300 */  addu       $2, $2, $3
    /* 3AB8BC 004AB8BC C0180200 */  sll        $3, $2, 3
    /* 3AB8C0 004AB8C0 7100023C */  lui        $2, %hi(D_00714468)
    /* 3AB8C4 004AB8C4 68444224 */  addiu      $2, $2, %lo(D_00714468)
    /* 3AB8C8 004AB8C8 21104300 */  addu       $2, $2, $3
    /* 3AB8CC 004AB8CC 0000428C */  lw         $2, 0x0($2)
    /* 3AB8D0 004AB8D0 09F84000 */  jalr       $2
    /* 3AB8D4 004AB8D4 00000000 */   nop
    /* 3AB8D8 004AB8D8 1C00038E */  lw         $3, 0x1C($16)
    /* 3AB8DC 004AB8DC 01006324 */  addiu      $3, $3, 0x1
    /* 3AB8E0 004AB8E0 1C0003AE */  sw         $3, 0x1C($16)
    /* 3AB8E4 004AB8E4 0B006018 */  blez       $3, .L004AB914
    /* 3AB8E8 004AB8E8 00000000 */   nop
    /* 3AB8EC 004AB8EC 2400028E */  lw         $2, 0x24($16)
    /* 3AB8F0 004AB8F0 2C0000AE */  sw         $0, 0x2C($16)
    /* 3AB8F4 004AB8F4 300000AE */  sw         $0, 0x30($16)
    /* 3AB8F8 004AB8F8 28004494 */  lhu        $4, 0x28($2)
    /* 3AB8FC 004AB8FC 3405120C */  jal        func_004814d0
    /* 3AB900 004AB900 00000000 */   nop
    /* 3AB904 004AB904 2D204000 */  daddu      $4, $2, $0
    /* 3AB908 004AB908 2C000526 */  addiu      $5, $16, 0x2C
    /* 3AB90C 004AB90C B082110C */  jal        func_00460ac0
    /* 3AB910 004AB910 00000000 */   nop
  .L004AB914:
    /* 3AB914 004AB914 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB918 004AB918 0000B07B */  lq         $16, 0x0($29)
    /* 3AB91C 004AB91C 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB920 004AB920 0800E003 */  jr         $31
    /* 3AB924 004AB924 00000000 */   nop
    /* 3AB928 004AB928 00000000 */  nop
    /* 3AB92C 004AB92C 00000000 */  nop
.size func_004ab8a0, 0x90
