.section .text
.set noat
.set noreorder
glabel func_003ec6f0
    /* 2EC6F0 003EC6F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC6F4 003EC6F4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EC6F8 003EC6F8 1000BFFF */  sd         $31, 0x10($29)
    /* 2EC6FC 003EC6FC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EC700 003EC700 0000B07F */  sq         $16, 0x0($29)
    /* 2EC704 003EC704 D0B7838F */  lw         $3, -0x4830($28)
    /* 2EC708 003EC708 2D808000 */  daddu      $16, $4, $0
    /* 2EC70C 003EC70C 21104300 */  addu       $2, $2, $3
    /* 2EC710 003EC710 6000448C */  lw         $4, 0x60($2)
    /* 2EC714 003EC714 08008010 */  beqz       $4, .L003EC738
    /* 2EC718 003EC718 00000000 */   nop
    /* 2EC71C 003EC71C BC840F0C */  jal        func_003e12f0
    /* 2EC720 003EC720 00000000 */   nop
    /* 2EC724 003EC724 D0B7838F */  lw         $3, -0x4830($28)
    /* 2EC728 003EC728 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EC72C 003EC72C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EC730 003EC730 21104300 */  addu       $2, $2, $3
    /* 2EC734 003EC734 600040AC */  sw         $0, 0x60($2)
  .L003EC738:
    /* 2EC738 003EC738 D4B7838F */  lw         $3, -0x482C($28)
    /* 2EC73C 003EC73C 2D100002 */  daddu      $2, $16, $0
    /* 2EC740 003EC740 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2EC744 003EC744 D4B783AF */  sw         $3, -0x482C($28)
    /* 2EC748 003EC748 1000BFDF */  ld         $31, 0x10($29)
    /* 2EC74C 003EC74C 0000B07B */  lq         $16, 0x0($29)
    /* 2EC750 003EC750 0800E003 */  jr         $31
    /* 2EC754 003EC754 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EC758 003EC758 00000000 */  nop
    /* 2EC75C 003EC75C 00000000 */  nop
.size func_003ec6f0, 0x70
