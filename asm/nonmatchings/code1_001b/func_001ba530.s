.section .text
.set noat
.set noreorder
glabel func_001ba530
    /* BA530 001BA530 D0FFBD27 */  addiu      $29, $29, -0x30
    /* BA534 001BA534 2000BFFF */  sd         $31, 0x20($29)
    /* BA538 001BA538 1000B17F */  sq         $17, 0x10($29)
    /* BA53C 001BA53C 0000B07F */  sq         $16, 0x0($29)
    /* BA540 001BA540 2D888000 */  daddu      $17, $4, $0
    /* BA544 001BA544 2D80A000 */  daddu      $16, $5, $0
    /* BA548 001BA548 08060424 */  addiu      $4, $0, 0x608
    /* BA54C 001BA54C 10000524 */  addiu      $5, $0, 0x10
    /* BA550 001BA550 1C51060C */  jal        func_00194470
    /* BA554 001BA554 00000000 */   nop
    /* BA558 001BA558 1C00033C */  lui        $3, %hi(func_001ba0e0)
    /* BA55C 001BA55C E0A06324 */  addiu      $3, $3, %lo(func_001ba0e0)
    /* BA560 001BA560 6C0043AC */  sw         $3, 0x6C($2)
    /* BA564 001BA564 7800438C */  lw         $3, 0x78($2)
    /* BA568 001BA568 000071AC */  sw         $17, 0x0($3)
    /* BA56C 001BA56C 080070AC */  sw         $16, 0x8($3)
    /* BA570 001BA570 2000BFDF */  ld         $31, 0x20($29)
    /* BA574 001BA574 1000B17B */  lq         $17, 0x10($29)
    /* BA578 001BA578 0000B07B */  lq         $16, 0x0($29)
    /* BA57C 001BA57C 3000BD27 */  addiu      $29, $29, 0x30
    /* BA580 001BA580 0800E003 */  jr         $31
    /* BA584 001BA584 00000000 */   nop
    /* BA588 001BA588 00000000 */  nop
    /* BA58C 001BA58C 00000000 */  nop
.size func_001ba530, 0x60
