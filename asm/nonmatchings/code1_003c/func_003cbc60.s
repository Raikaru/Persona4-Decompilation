.section .text
.set noat
.set noreorder
glabel func_003cbc60
    /* 2CBC60 003CBC60 08B7828F */  lw         $2, -0x48F8($28)
    /* 2CBC64 003CBC64 2118A200 */  addu       $3, $5, $2
    /* 2CBC68 003CBC68 0C00628C */  lw         $2, 0xC($3)
    /* 2CBC6C 003CBC6C 03004014 */  bnez       $2, .L003CBC7C
    /* 2CBC70 003CBC70 00000000 */   nop
    /* 2CBC74 003CBC74 04000010 */  b          .L003CBC88
    /* 2CBC78 003CBC78 2D100000 */   daddu     $2, $0, $0
  .L003CBC7C:
    /* 2CBC7C 003CBC7C 0C0060AC */  sw         $0, 0xC($3)
    /* 2CBC80 003CBC80 2D108000 */  daddu      $2, $4, $0
    /* 2CBC84 003CBC84 080060AC */  sw         $0, 0x8($3)
  .L003CBC88:
    /* 2CBC88 003CBC88 0800E003 */  jr         $31
    /* 2CBC8C 003CBC8C 00000000 */   nop
.size func_003cbc60, 0x30
