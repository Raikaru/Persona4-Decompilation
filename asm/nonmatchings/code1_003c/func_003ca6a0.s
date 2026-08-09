.section .text
.set noat
.set noreorder
glabel func_003ca6a0
    /* 2CA6A0 003CA6A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CA6A4 003CA6A4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CA6A8 003CA6A8 1000BFFF */  sd         $31, 0x10($29)
    /* 2CA6AC 003CA6AC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CA6B0 003CA6B0 0000B07F */  sq         $16, 0x0($29)
    /* 2CA6B4 003CA6B4 18B7838F */  lw         $3, -0x48E8($28)
    /* 2CA6B8 003CA6B8 2D808000 */  daddu      $16, $4, $0
    /* 2CA6BC 003CA6BC 21104300 */  addu       $2, $2, $3
    /* 2CA6C0 003CA6C0 0400448C */  lw         $4, 0x4($2)
    /* 2CA6C4 003CA6C4 08008010 */  beqz       $4, .L003CA6E8
    /* 2CA6C8 003CA6C8 00000000 */   nop
    /* 2CA6CC 003CA6CC BC840F0C */  jal        func_003e12f0
    /* 2CA6D0 003CA6D0 00000000 */   nop
    /* 2CA6D4 003CA6D4 18B7838F */  lw         $3, -0x48E8($28)
    /* 2CA6D8 003CA6D8 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CA6DC 003CA6DC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CA6E0 003CA6E0 21104300 */  addu       $2, $2, $3
    /* 2CA6E4 003CA6E4 040040AC */  sw         $0, 0x4($2)
  .L003CA6E8:
    /* 2CA6E8 003CA6E8 18B7838F */  lw         $3, -0x48E8($28)
    /* 2CA6EC 003CA6EC 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CA6F0 003CA6F0 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CA6F4 003CA6F4 21104300 */  addu       $2, $2, $3
    /* 2CA6F8 003CA6F8 0000448C */  lw         $4, 0x0($2)
    /* 2CA6FC 003CA6FC 08008010 */  beqz       $4, .L003CA720
    /* 2CA700 003CA700 00000000 */   nop
    /* 2CA704 003CA704 BC840F0C */  jal        func_003e12f0
    /* 2CA708 003CA708 00000000 */   nop
    /* 2CA70C 003CA70C 18B7838F */  lw         $3, -0x48E8($28)
    /* 2CA710 003CA710 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CA714 003CA714 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CA718 003CA718 21104300 */  addu       $2, $2, $3
    /* 2CA71C 003CA71C 000040AC */  sw         $0, 0x0($2)
  .L003CA720:
    /* 2CA720 003CA720 1CB7838F */  lw         $3, -0x48E4($28)
    /* 2CA724 003CA724 2D100002 */  daddu      $2, $16, $0
    /* 2CA728 003CA728 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2CA72C 003CA72C 1CB783AF */  sw         $3, -0x48E4($28)
    /* 2CA730 003CA730 1000BFDF */  ld         $31, 0x10($29)
    /* 2CA734 003CA734 0000B07B */  lq         $16, 0x0($29)
    /* 2CA738 003CA738 0800E003 */  jr         $31
    /* 2CA73C 003CA73C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003ca6a0, 0xa0
