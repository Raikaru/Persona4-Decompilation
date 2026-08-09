.section .text
.set noat
.set noreorder
glabel func_003d4a60
    /* 2D4A60 003D4A60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D4A64 003D4A64 1000BFFF */  sd         $31, 0x10($29)
    /* 2D4A68 003D4A68 0000B07F */  sq         $16, 0x0($29)
    /* 2D4A6C 003D4A6C 7800858C */  lw         $5, 0x78($4)
    /* 2D4A70 003D4A70 1900A010 */  beqz       $5, .L003D4AD8
    /* 2D4A74 003D4A74 2D808000 */   daddu     $16, $4, $0
    /* 2D4A78 003D4A78 28B7828F */  lw         $2, -0x48D8($28)
    /* 2D4A7C 003D4A7C 21200202 */  addu       $4, $16, $2
    /* 2D4A80 003D4A80 0000828C */  lw         $2, 0x0($4)
    /* 2D4A84 003D4A84 06004010 */  beqz       $2, .L003D4AA0
    /* 2D4A88 003D4A88 2D300000 */   daddu     $6, $0, $0
    /* 2D4A8C 003D4A8C 0000428C */  lw         $2, 0x0($2)
    /* 2D4A90 003D4A90 0400A394 */  lhu        $3, 0x4($5)
    /* 2D4A94 003D4A94 02006214 */  bne        $3, $2, .L003D4AA0
    /* 2D4A98 003D4A98 00000000 */   nop
    /* 2D4A9C 003D4A9C 01000624 */  addiu      $6, $0, 0x1
  .L003D4AA0:
    /* 2D4AA0 003D4AA0 0300C010 */  beqz       $6, .L003D4AB0
    /* 2D4AA4 003D4AA4 00000000 */   nop
    /* 2D4AA8 003D4AA8 05000010 */  b          .L003D4AC0
    /* 2D4AAC 003D4AAC 0000828C */   lw        $2, 0x0($4)
  .L003D4AB0:
    /* 2D4AB0 003D4AB0 14380F0C */  jal        func_003ce050
    /* 2D4AB4 003D4AB4 0400A594 */   lhu       $5, 0x4($5)
    /* 2D4AB8 003D4AB8 2D204000 */  daddu      $4, $2, $0
    /* 2D4ABC 003D4ABC 0000828C */  lw         $2, 0x0($4)
  .L003D4AC0:
    /* 2D4AC0 003D4AC0 03004014 */  bnez       $2, .L003D4AD0
    /* 2D4AC4 003D4AC4 00000000 */   nop
    /* 2D4AC8 003D4AC8 07000010 */  b          .L003D4AE8
    /* 2D4ACC 003D4ACC 2D100000 */   daddu     $2, $0, $0
  .L003D4AD0:
    /* 2D4AD0 003D4AD0 05000010 */  b          .L003D4AE8
    /* 2D4AD4 003D4AD4 2D100002 */   daddu     $2, $16, $0
  .L003D4AD8:
    /* 2D4AD8 003D4AD8 28B7828F */  lw         $2, -0x48D8($28)
    /* 2D4ADC 003D4ADC 21100202 */  addu       $2, $16, $2
    /* 2D4AE0 003D4AE0 FBFF0010 */  b          .L003D4AD0
    /* 2D4AE4 003D4AE4 000040AC */   sw        $0, 0x0($2)
  .L003D4AE8:
    /* 2D4AE8 003D4AE8 1000BFDF */  ld         $31, 0x10($29)
    /* 2D4AEC 003D4AEC 0000B07B */  lq         $16, 0x0($29)
    /* 2D4AF0 003D4AF0 0800E003 */  jr         $31
    /* 2D4AF4 003D4AF4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D4AF8 003D4AF8 00000000 */  nop
    /* 2D4AFC 003D4AFC 00000000 */  nop
.size func_003d4a60, 0xa0
