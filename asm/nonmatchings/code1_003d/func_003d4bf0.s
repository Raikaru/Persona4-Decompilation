.section .text
.set noat
.set noreorder
glabel func_003d4bf0
    /* 2D4BF0 003D4BF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D4BF4 003D4BF4 0000BFFF */  sd         $31, 0x0($29)
    /* 2D4BF8 003D4BF8 7800858C */  lw         $5, 0x78($4)
    /* 2D4BFC 003D4BFC 1700A010 */  beqz       $5, .L003D4C5C
    /* 2D4C00 003D4C00 00000000 */   nop
    /* 2D4C04 003D4C04 28B7828F */  lw         $2, -0x48D8($28)
    /* 2D4C08 003D4C08 21208200 */  addu       $4, $4, $2
    /* 2D4C0C 003D4C0C 0000828C */  lw         $2, 0x0($4)
    /* 2D4C10 003D4C10 06004010 */  beqz       $2, .L003D4C2C
    /* 2D4C14 003D4C14 2D300000 */   daddu     $6, $0, $0
    /* 2D4C18 003D4C18 0000428C */  lw         $2, 0x0($2)
    /* 2D4C1C 003D4C1C 0400A394 */  lhu        $3, 0x4($5)
    /* 2D4C20 003D4C20 02006214 */  bne        $3, $2, .L003D4C2C
    /* 2D4C24 003D4C24 00000000 */   nop
    /* 2D4C28 003D4C28 01000624 */  addiu      $6, $0, 0x1
  .L003D4C2C:
    /* 2D4C2C 003D4C2C 0300C010 */  beqz       $6, .L003D4C3C
    /* 2D4C30 003D4C30 00000000 */   nop
    /* 2D4C34 003D4C34 05000010 */  b          .L003D4C4C
    /* 2D4C38 003D4C38 0000828C */   lw        $2, 0x0($4)
  .L003D4C3C:
    /* 2D4C3C 003D4C3C 14380F0C */  jal        func_003ce050
    /* 2D4C40 003D4C40 0400A594 */   lhu       $5, 0x4($5)
    /* 2D4C44 003D4C44 2D204000 */  daddu      $4, $2, $0
    /* 2D4C48 003D4C48 0000828C */  lw         $2, 0x0($4)
  .L003D4C4C:
    /* 2D4C4C 003D4C4C 03004014 */  bnez       $2, .L003D4C5C
    /* 2D4C50 003D4C50 00000000 */   nop
    /* 2D4C54 003D4C54 02000010 */  b          .L003D4C60
    /* 2D4C58 003D4C58 2D100000 */   daddu     $2, $0, $0
  .L003D4C5C:
    /* 2D4C5C 003D4C5C 01000224 */  addiu      $2, $0, 0x1
  .L003D4C60:
    /* 2D4C60 003D4C60 0000BFDF */  ld         $31, 0x0($29)
    /* 2D4C64 003D4C64 0800E003 */  jr         $31
    /* 2D4C68 003D4C68 1000BD27 */   addiu     $29, $29, 0x10
    /* 2D4C6C 003D4C6C 00000000 */  nop
.size func_003d4bf0, 0x80
