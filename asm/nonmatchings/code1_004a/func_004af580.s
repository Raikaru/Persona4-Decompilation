.section .text
.set noat
.set noreorder
glabel func_004af580
    /* 3AF580 004AF580 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AF584 004AF584 1000BFFF */  sd         $31, 0x10($29)
    /* 3AF588 004AF588 0000B07F */  sq         $16, 0x0($29)
    /* 3AF58C 004AF58C 2D808000 */  daddu      $16, $4, $0
    /* 3AF590 004AF590 20BB120C */  jal        func_004aec80
    /* 3AF594 004AF594 00000000 */   nop
    /* 3AF598 004AF598 5800038E */  lw         $3, 0x58($16)
    /* 3AF59C 004AF59C 0B006010 */  beqz       $3, .L004AF5CC
    /* 3AF5A0 004AF5A0 00000000 */   nop
    /* 3AF5A4 004AF5A4 2000628C */  lw         $2, 0x20($3)
    /* 3AF5A8 004AF5A8 640000AE */  sw         $0, 0x64($16)
    /* 3AF5AC 004AF5AC 680000AE */  sw         $0, 0x68($16)
    /* 3AF5B0 004AF5B0 54004494 */  lhu        $4, 0x54($2)
    /* 3AF5B4 004AF5B4 1805120C */  jal        func_00481460
    /* 3AF5B8 004AF5B8 00000000 */   nop
    /* 3AF5BC 004AF5BC 2D204000 */  daddu      $4, $2, $0
    /* 3AF5C0 004AF5C0 64000526 */  addiu      $5, $16, 0x64
    /* 3AF5C4 004AF5C4 B082110C */  jal        func_00460ac0
    /* 3AF5C8 004AF5C8 00000000 */   nop
  .L004AF5CC:
    /* 3AF5CC 004AF5CC 1000BFDF */  ld         $31, 0x10($29)
    /* 3AF5D0 004AF5D0 0000B07B */  lq         $16, 0x0($29)
    /* 3AF5D4 004AF5D4 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AF5D8 004AF5D8 0800E003 */  jr         $31
    /* 3AF5DC 004AF5DC 00000000 */   nop
.size func_004af580, 0x60
