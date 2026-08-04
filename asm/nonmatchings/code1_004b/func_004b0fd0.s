.section .text
.set noat
.set noreorder
glabel func_004b0fd0
    /* 3B0FD0 004B0FD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3B0FD4 004B0FD4 1000BFFF */  sd         $31, 0x10($29)
    /* 3B0FD8 004B0FD8 0000B07F */  sq         $16, 0x0($29)
    /* 3B0FDC 004B0FDC 2D808000 */  daddu      $16, $4, $0
    /* 3B0FE0 004B0FE0 5C00838C */  lw         $3, 0x5C($4)
    /* 3B0FE4 004B0FE4 0B006010 */  beqz       $3, .L004B1014
    /* 3B0FE8 004B0FE8 00000000 */   nop
    /* 3B0FEC 004B0FEC 2000628C */  lw         $2, 0x20($3)
    /* 3B0FF0 004B0FF0 6C0000AE */  sw         $0, 0x6C($16)
    /* 3B0FF4 004B0FF4 700000AE */  sw         $0, 0x70($16)
    /* 3B0FF8 004B0FF8 54004494 */  lhu        $4, 0x54($2)
    /* 3B0FFC 004B0FFC 1805120C */  jal        func_00481460
    /* 3B1000 004B1000 00000000 */   nop
    /* 3B1004 004B1004 2D204000 */  daddu      $4, $2, $0
    /* 3B1008 004B1008 6C000526 */  addiu      $5, $16, 0x6C
    /* 3B100C 004B100C B082110C */  jal        func_00460ac0
    /* 3B1010 004B1010 00000000 */   nop
  .L004B1014:
    /* 3B1014 004B1014 1000BFDF */  ld         $31, 0x10($29)
    /* 3B1018 004B1018 0000B07B */  lq         $16, 0x0($29)
    /* 3B101C 004B101C 2000BD27 */  addiu      $29, $29, 0x20
    /* 3B1020 004B1020 0800E003 */  jr         $31
    /* 3B1024 004B1024 00000000 */   nop
    /* 3B1028 004B1028 00000000 */  nop
    /* 3B102C 004B102C 00000000 */  nop
.size func_004b0fd0, 0x60
