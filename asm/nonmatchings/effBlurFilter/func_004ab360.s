.section .text
.set noat
.set noreorder
glabel func_004ab360
    /* 3AB360 004AB360 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB364 004AB364 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB368 004AB368 0000B07F */  sq         $16, 0x0($29)
    /* 3AB36C 004AB36C 2D808000 */  daddu      $16, $4, $0
    /* 3AB370 004AB370 1800838C */  lw         $3, 0x18($4)
    /* 3AB374 004AB374 40100300 */  sll        $2, $3, 1
    /* 3AB378 004AB378 21104300 */  addu       $2, $2, $3
    /* 3AB37C 004AB37C C0180200 */  sll        $3, $2, 3
    /* 3AB380 004AB380 7100023C */  lui        $2, %hi(D_00714398)
    /* 3AB384 004AB384 98434224 */  addiu      $2, $2, %lo(D_00714398)
    /* 3AB388 004AB388 21104300 */  addu       $2, $2, $3
    /* 3AB38C 004AB38C 0000428C */  lw         $2, 0x0($2)
    /* 3AB390 004AB390 09F84000 */  jalr       $2
    /* 3AB394 004AB394 00000000 */   nop
    /* 3AB398 004AB398 1C00038E */  lw         $3, 0x1C($16)
    /* 3AB39C 004AB39C 01006324 */  addiu      $3, $3, 0x1
    /* 3AB3A0 004AB3A0 1C0003AE */  sw         $3, 0x1C($16)
    /* 3AB3A4 004AB3A4 0B006018 */  blez       $3, .L004AB3D4
    /* 3AB3A8 004AB3A8 00000000 */   nop
    /* 3AB3AC 004AB3AC 2400028E */  lw         $2, 0x24($16)
    /* 3AB3B0 004AB3B0 2C0000AE */  sw         $0, 0x2C($16)
    /* 3AB3B4 004AB3B4 300000AE */  sw         $0, 0x30($16)
    /* 3AB3B8 004AB3B8 28004494 */  lhu        $4, 0x28($2)
    /* 3AB3BC 004AB3BC 3405120C */  jal        func_004814d0
    /* 3AB3C0 004AB3C0 00000000 */   nop
    /* 3AB3C4 004AB3C4 2D204000 */  daddu      $4, $2, $0
    /* 3AB3C8 004AB3C8 2C000526 */  addiu      $5, $16, 0x2C
    /* 3AB3CC 004AB3CC B082110C */  jal        func_00460ac0
    /* 3AB3D0 004AB3D0 00000000 */   nop
  .L004AB3D4:
    /* 3AB3D4 004AB3D4 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB3D8 004AB3D8 0000B07B */  lq         $16, 0x0($29)
    /* 3AB3DC 004AB3DC 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB3E0 004AB3E0 0800E003 */  jr         $31
    /* 3AB3E4 004AB3E4 00000000 */   nop
    /* 3AB3E8 004AB3E8 00000000 */  nop
    /* 3AB3EC 004AB3EC 00000000 */  nop
.size func_004ab360, 0x90
