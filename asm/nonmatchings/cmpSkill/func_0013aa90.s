.section .text
.set noat
.set noreorder
glabel func_0013aa90
    /* 3AA90 0013AA90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AA94 0013AA94 2000BFFF */  sd         $31, 0x20($29)
    /* 3AA98 0013AA98 1000B17F */  sq         $17, 0x10($29)
    /* 3AA9C 0013AA9C 0000B07F */  sq         $16, 0x0($29)
    /* 3AAA0 0013AAA0 2D888000 */  daddu      $17, $4, $0
    /* 3AAA4 0013AAA4 2D800000 */  daddu      $16, $0, $0
    /* 3AAA8 0013AAA8 18000010 */  b          .L0013AB0C
    /* 3AAAC 0013AAAC 00000000 */   nop
  .L0013AAB0:
    /* 3AAB0 0013AAB0 18DC0E0C */  jal        func_003b7060
    /* 3AAB4 0013AAB4 00000000 */   nop
    /* 3AAB8 0013AAB8 01004330 */  andi       $3, $2, 0x1
    /* 3AABC 0013AABC 12006014 */  bnez       $3, .L0013AB08
    /* 3AAC0 0013AAC0 00000000 */   nop
    /* 3AAC4 0013AAC4 40281000 */  sll        $5, $16, 1
    /* 3AAC8 0013AAC8 2118B000 */  addu       $3, $5, $16
    /* 3AACC 0013AACC 00190300 */  sll        $3, $3, 4
    /* 3AAD0 0013AAD0 21202302 */  addu       $4, $17, $3
    /* 3AAD4 0013AAD4 FA000324 */  addiu      $3, $0, 0xFA
    /* 3AAD8 0013AAD8 C20C83A4 */  sh         $3, 0xCC2($4)
    /* 3AADC 0013AADC 90010324 */  addiu      $3, $0, 0x190
    /* 3AAE0 0013AAE0 C80C83A4 */  sh         $3, 0xCC8($4)
    /* 3AAE4 0013AAE4 F0C1033C */  lui        $3, (0xC1F00000 >> 16)
    /* 3AAE8 0013AAE8 A40C83AC */  sw         $3, 0xCA4($4)
    /* 3AAEC 0013AAEC A80C83AC */  sw         $3, 0xCA8($4)
    /* 3AAF0 0013AAF0 AC0C83AC */  sw         $3, 0xCAC($4)
    /* 3AAF4 0013AAF4 B00C83AC */  sw         $3, 0xCB0($4)
    /* 3AAF8 0013AAF8 0A000324 */  addiu      $3, $0, 0xA
    /* 3AAFC 0013AAFC D00C83AC */  sw         $3, 0xCD0($4)
    /* 3AB00 0013AB00 21182502 */  addu       $3, $17, $5
    /* 3AB04 0013AB04 240060A4 */  sh         $0, 0x24($3)
  .L0013AB08:
    /* 3AB08 0013AB08 01001026 */  addiu      $16, $16, 0x1
  .L0013AB0C:
    /* 3AB0C 0013AB0C 0600032A */  slti       $3, $16, 0x6
    /* 3AB10 0013AB10 E7FF6014 */  bnez       $3, .L0013AAB0
    /* 3AB14 0013AB14 00000000 */   nop
    /* 3AB18 0013AB18 2000BFDF */  ld         $31, 0x20($29)
    /* 3AB1C 0013AB1C 1000B17B */  lq         $17, 0x10($29)
    /* 3AB20 0013AB20 0000B07B */  lq         $16, 0x0($29)
    /* 3AB24 0013AB24 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AB28 0013AB28 0800E003 */  jr         $31
    /* 3AB2C 0013AB2C 00000000 */   nop
.size func_0013aa90, 0xa0
