.section .text
.set noat
.set noreorder
glabel func_003ec760
    /* 2EC760 003EC760 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC764 003EC764 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EC768 003EC768 1000BFFF */  sd         $31, 0x10($29)
    /* 2EC76C 003EC76C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EC770 003EC770 0000B07F */  sq         $16, 0x0($29)
    /* 2EC774 003EC774 21104500 */  addu       $2, $2, $5
    /* 2EC778 003EC778 D0B785AF */  sw         $5, -0x4830($28)
    /* 2EC77C 003EC77C 2D808000 */  daddu      $16, $4, $0
    /* 2EC780 003EC780 34000624 */  addiu      $6, $0, 0x34
    /* 2EC784 003EC784 2C004424 */  addiu      $4, $2, 0x2C
    /* 2EC788 003EC788 72FE100C */  jal        func_0043f9c8
    /* 2EC78C 003EC78C 2D280000 */   daddu     $5, $0, $0
    /* 2EC790 003EC790 D0B78B8F */  lw         $11, -0x4830($28)
    /* 2EC794 003EC794 88000A3C */  lui        $10, %hi(D_008872E0)
    /* 2EC798 003EC798 E0724A25 */  addiu      $10, $10, %lo(D_008872E0)
    /* 2EC79C 003EC79C 7100023C */  lui        $2, %hi(D_0070B7E0)
    /* 2EC7A0 003EC7A0 E0B7448C */  lw         $4, %lo(D_0070B7E0)($2)
    /* 2EC7A4 003EC7A4 8900083C */  lui        $8, %hi(D_0088B370)
    /* 2EC7A8 003EC7A8 80000324 */  addiu      $3, $0, 0x80
    /* 2EC7AC 003EC7AC A8AB858F */  lw         $5, -0x5458($28)
    /* 2EC7B0 003EC7B0 ACAB878F */  lw         $7, -0x5454($28)
    /* 2EC7B4 003EC7B4 04000624 */  addiu      $6, $0, 0x4
    /* 2EC7B8 003EC7B8 70B30825 */  addiu      $8, $8, %lo(D_0088B370)
    /* 2EC7BC 003EC7BC 21504B01 */  addu       $10, $10, $11
    /* 2EC7C0 003EC7C0 380040AD */  sw         $0, 0x38($10)
    /* 2EC7C4 003EC7C4 3C0040AD */  sw         $0, 0x3C($10)
    /* 2EC7C8 003EC7C8 0400023C */  lui        $2, (0x40407 >> 16)
    /* 2EC7CC 003EC7CC 400040AD */  sw         $0, 0x40($10)
    /* 2EC7D0 003EC7D0 07044934 */  ori        $9, $2, (0x40407 & 0xFFFF)
    /* 2EC7D4 003EC7D4 4D0043A1 */  sb         $3, 0x4D($10)
    /* 2EC7D8 003EC7D8 2C004225 */  addiu      $2, $10, 0x2C
    /* 2EC7DC 003EC7DC 300040AD */  sw         $0, 0x30($10)
    /* 2EC7E0 003EC7E0 340040AD */  sw         $0, 0x34($10)
    /* 2EC7E4 003EC7E4 4C0040A1 */  sb         $0, 0x4C($10)
    /* 2EC7E8 003EC7E8 280040AD */  sw         $0, 0x28($10)
    /* 2EC7EC 003EC7EC 88840F0C */  jal        func_003e1220
    /* 2EC7F0 003EC7F0 000042AD */   sw        $2, 0x0($10)
    /* 2EC7F4 003EC7F4 D0B7848F */  lw         $4, -0x4830($28)
    /* 2EC7F8 003EC7F8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EC7FC 003EC7FC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EC800 003EC800 21186400 */  addu       $3, $3, $4
    /* 2EC804 003EC804 600062AC */  sw         $2, 0x60($3)
    /* 2EC808 003EC808 6000628C */  lw         $2, 0x60($3)
    /* 2EC80C 003EC80C 03004014 */  bnez       $2, .L003EC81C
    /* 2EC810 003EC810 00000000 */   nop
    /* 2EC814 003EC814 05000010 */  b          .L003EC82C
    /* 2EC818 003EC818 2D100000 */   daddu     $2, $0, $0
  .L003EC81C:
    /* 2EC81C 003EC81C D4B7838F */  lw         $3, -0x482C($28)
    /* 2EC820 003EC820 2D100002 */  daddu      $2, $16, $0
    /* 2EC824 003EC824 01006324 */  addiu      $3, $3, 0x1
    /* 2EC828 003EC828 D4B783AF */  sw         $3, -0x482C($28)
  .L003EC82C:
    /* 2EC82C 003EC82C 1000BFDF */  ld         $31, 0x10($29)
    /* 2EC830 003EC830 0000B07B */  lq         $16, 0x0($29)
    /* 2EC834 003EC834 0800E003 */  jr         $31
    /* 2EC838 003EC838 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EC83C 003EC83C 00000000 */  nop
.size func_003ec760, 0xe0
