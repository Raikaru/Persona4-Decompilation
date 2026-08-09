.section .text
.set noat
.set noreorder
glabel func_003bfd00
    /* 2BFD00 003BFD00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BFD04 003BFD04 8800083C */  lui        $8, %hi(D_00886520)
    /* 2BFD08 003BFD08 1000BFFF */  sd         $31, 0x10($29)
    /* 2BFD0C 003BFD0C 7100023C */  lui        $2, %hi(D_0070AF70)
    /* 2BFD10 003BFD10 0000B07F */  sq         $16, 0x0($29)
    /* 2BFD14 003BFD14 10000624 */  addiu      $6, $0, 0x10
    /* 2BFD18 003BFD18 2D808000 */  daddu      $16, $4, $0
    /* 2BFD1C 003BFD1C C0B685AF */  sw         $5, -0x4940($28)
    /* 2BFD20 003BFD20 70AF448C */  lw         $4, %lo(D_0070AF70)($2)
    /* 2BFD24 003BFD24 20650825 */  addiu      $8, $8, %lo(D_00886520)
    /* 2BFD28 003BFD28 88AA858F */  lw         $5, -0x5578($28)
    /* 2BFD2C 003BFD2C 8CAA878F */  lw         $7, -0x5574($28)
    /* 2BFD30 003BFD30 0400023C */  lui        $2, (0x40010 >> 16)
    /* 2BFD34 003BFD34 88840F0C */  jal        func_003e1220
    /* 2BFD38 003BFD38 10004934 */   ori       $9, $2, (0x40010 & 0xFFFF)
    /* 2BFD3C 003BFD3C C0B6848F */  lw         $4, -0x4940($28)
    /* 2BFD40 003BFD40 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2BFD44 003BFD44 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2BFD48 003BFD48 21186400 */  addu       $3, $3, $4
    /* 2BFD4C 003BFD4C 000062AC */  sw         $2, 0x0($3)
    /* 2BFD50 003BFD50 0000628C */  lw         $2, 0x0($3)
    /* 2BFD54 003BFD54 03004014 */  bnez       $2, .L003BFD64
    /* 2BFD58 003BFD58 00000000 */   nop
  .L003BFD5C:
    /* 2BFD5C 003BFD5C 20000010 */  b          .L003BFDE0
    /* 2BFD60 003BFD60 2D100000 */   daddu     $2, $0, $0
  .L003BFD64:
    /* 2BFD64 003BFD64 7100023C */  lui        $2, %hi(D_0070AF90)
    /* 2BFD68 003BFD68 8800083C */  lui        $8, %hi(D_008864F0)
    /* 2BFD6C 003BFD6C 90AF448C */  lw         $4, %lo(D_0070AF90)($2)
    /* 2BFD70 003BFD70 10000624 */  addiu      $6, $0, 0x10
    /* 2BFD74 003BFD74 90AA858F */  lw         $5, -0x5570($28)
    /* 2BFD78 003BFD78 F0640825 */  addiu      $8, $8, %lo(D_008864F0)
    /* 2BFD7C 003BFD7C 94AA878F */  lw         $7, -0x556C($28)
    /* 2BFD80 003BFD80 0400023C */  lui        $2, (0x40014 >> 16)
    /* 2BFD84 003BFD84 88840F0C */  jal        func_003e1220
    /* 2BFD88 003BFD88 14004934 */   ori       $9, $2, (0x40014 & 0xFFFF)
    /* 2BFD8C 003BFD8C C0B6848F */  lw         $4, -0x4940($28)
    /* 2BFD90 003BFD90 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2BFD94 003BFD94 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2BFD98 003BFD98 21186400 */  addu       $3, $3, $4
    /* 2BFD9C 003BFD9C 040062AC */  sw         $2, 0x4($3)
    /* 2BFDA0 003BFDA0 0400628C */  lw         $2, 0x4($3)
    /* 2BFDA4 003BFDA4 06004010 */  beqz       $2, .L003BFDC0
    /* 2BFDA8 003BFDA8 00000000 */   nop
    /* 2BFDAC 003BFDAC C4B6838F */  lw         $3, -0x493C($28)
    /* 2BFDB0 003BFDB0 2D100002 */  daddu      $2, $16, $0
    /* 2BFDB4 003BFDB4 01006324 */  addiu      $3, $3, 0x1
    /* 2BFDB8 003BFDB8 09000010 */  b          .L003BFDE0
    /* 2BFDBC 003BFDBC C4B683AF */   sw        $3, -0x493C($28)
  .L003BFDC0:
    /* 2BFDC0 003BFDC0 BC840F0C */  jal        func_003e12f0
    /* 2BFDC4 003BFDC4 0000648C */   lw        $4, 0x0($3)
    /* 2BFDC8 003BFDC8 C0B6838F */  lw         $3, -0x4940($28)
    /* 2BFDCC 003BFDCC 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2BFDD0 003BFDD0 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2BFDD4 003BFDD4 21104300 */  addu       $2, $2, $3
    /* 2BFDD8 003BFDD8 E0FF0010 */  b          .L003BFD5C
    /* 2BFDDC 003BFDDC 000040AC */   sw        $0, 0x0($2)
  .L003BFDE0:
    /* 2BFDE0 003BFDE0 1000BFDF */  ld         $31, 0x10($29)
    /* 2BFDE4 003BFDE4 0000B07B */  lq         $16, 0x0($29)
    /* 2BFDE8 003BFDE8 0800E003 */  jr         $31
    /* 2BFDEC 003BFDEC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003bfd00, 0xf0
