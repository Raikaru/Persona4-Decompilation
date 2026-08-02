.section .text
.set noat
.set noreorder
glabel func_0010fd40
    /* FD40 0010FD40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* FD44 0010FD44 1000BFFF */  sd         $31, 0x10($29)
    /* FD48 0010FD48 0000B07F */  sq         $16, 0x0($29)
    /* FD4C 0010FD4C 2D808000 */  daddu      $16, $4, $0
    /* FD50 0010FD50 06000016 */  bnez       $16, .L0010FD6C
    /* FD54 0010FD54 00000000 */   nop
    /* FD58 0010FD58 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FD5C 0010FD5C 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FD60 0010FD60 270F0524 */  addiu      $5, $0, 0xF27
    /* FD64 0010FD64 CCB5110C */  jal        func_0046d730
    /* FD68 0010FD68 00000000 */   nop
  .L0010FD6C:
    /* FD6C 0010FD6C 02000296 */  lhu        $2, 0x2($16)
    /* FD70 0010FD70 04004004 */  bltz       $2, .L0010FD84
    /* FD74 0010FD74 00000000 */   nop
    /* FD78 0010FD78 00014228 */  slti       $2, $2, 0x100
    /* FD7C 0010FD7C 06004014 */  bnez       $2, .L0010FD98
    /* FD80 0010FD80 00000000 */   nop
  .L0010FD84:
    /* FD84 0010FD84 5E00043C */  lui        $4, %hi(D_005E4298)
    /* FD88 0010FD88 98428424 */  addiu      $4, $4, %lo(D_005E4298)
    /* FD8C 0010FD8C 280F0524 */  addiu      $5, $0, 0xF28
    /* FD90 0010FD90 CCB5110C */  jal        func_0046d730
    /* FD94 0010FD94 00000000 */   nop
  .L0010FD98:
    /* FD98 0010FD98 02000396 */  lhu        $3, 0x2($16)
    /* FD9C 0010FD9C 40100300 */  sll        $2, $3, 1
    /* FDA0 0010FDA0 21104300 */  addu       $2, $2, $3
    /* FDA4 0010FDA4 00190200 */  sll        $3, $2, 4
    /* FDA8 0010FDA8 7900023C */  lui        $2, %hi(D_007973A0)
    /* FDAC 0010FDAC A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* FDB0 0010FDB0 21104300 */  addu       $2, $2, $3
    /* FDB4 0010FDB4 2C0E4424 */  addiu      $4, $2, 0xE2C
    /* FDB8 0010FDB8 2D280002 */  daddu      $5, $16, $0
    /* FDBC 0010FDBC 30000624 */  addiu      $6, $0, 0x30
    /* FDC0 0010FDC0 04FE100C */  jal        func_0043f810
    /* FDC4 0010FDC4 00000000 */   nop
    /* FDC8 0010FDC8 1000BFDF */  ld         $31, 0x10($29)
    /* FDCC 0010FDCC 0000B07B */  lq         $16, 0x0($29)
    /* FDD0 0010FDD0 2000BD27 */  addiu      $29, $29, 0x20
    /* FDD4 0010FDD4 0800E003 */  jr         $31
    /* FDD8 0010FDD8 00000000 */   nop
    /* FDDC 0010FDDC 00000000 */  nop
.size func_0010fd40, 0xa0
