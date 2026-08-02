.section .text
.set noat
.set noreorder
glabel func_004ab300
    /* 3AB300 004AB300 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB304 004AB304 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB308 004AB308 0000B07F */  sq         $16, 0x0($29)
    /* 3AB30C 004AB30C 2D808000 */  daddu      $16, $4, $0
    /* 3AB310 004AB310 1C00838C */  lw         $3, 0x1C($4)
    /* 3AB314 004AB314 0B006018 */  blez       $3, .L004AB344
    /* 3AB318 004AB318 00000000 */   nop
    /* 3AB31C 004AB31C 2400028E */  lw         $2, 0x24($16)
    /* 3AB320 004AB320 2C0000AE */  sw         $0, 0x2C($16)
    /* 3AB324 004AB324 300000AE */  sw         $0, 0x30($16)
    /* 3AB328 004AB328 28004494 */  lhu        $4, 0x28($2)
    /* 3AB32C 004AB32C 3405120C */  jal        func_004814d0
    /* 3AB330 004AB330 00000000 */   nop
    /* 3AB334 004AB334 2D204000 */  daddu      $4, $2, $0
    /* 3AB338 004AB338 2C000526 */  addiu      $5, $16, 0x2C
    /* 3AB33C 004AB33C B082110C */  jal        func_00460ac0
    /* 3AB340 004AB340 00000000 */   nop
  .L004AB344:
    /* 3AB344 004AB344 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB348 004AB348 0000B07B */  lq         $16, 0x0($29)
    /* 3AB34C 004AB34C 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB350 004AB350 0800E003 */  jr         $31
    /* 3AB354 004AB354 00000000 */   nop
    /* 3AB358 004AB358 00000000 */  nop
    /* 3AB35C 004AB35C 00000000 */  nop
.size func_004ab300, 0x60
