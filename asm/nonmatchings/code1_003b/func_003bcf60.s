.section .text
.set noat
.set noreorder
glabel func_003bcf60
    /* 2BCF60 003BCF60 68B6828F */  lw         $2, -0x4998($28)
    /* 2BCF64 003BCF64 21208200 */  addu       $4, $4, $2
    /* 2BCF68 003BCF68 0000828C */  lw         $2, 0x0($4)
    /* 2BCF6C 003BCF6C 2A08A200 */  slt        $1, $5, $2
    /* 2BCF70 003BCF70 05002010 */  beqz       $1, .L003BCF88
    /* 2BCF74 003BCF74 00000000 */   nop
    /* 2BCF78 003BCF78 0400828C */  lw         $2, 0x4($4)
    /* 2BCF7C 003BCF7C 00190500 */  sll        $3, $5, 4
    /* 2BCF80 003BCF80 02000010 */  b          .L003BCF8C
    /* 2BCF84 003BCF84 21104300 */   addu      $2, $2, $3
  .L003BCF88:
    /* 2BCF88 003BCF88 2D100000 */  daddu      $2, $0, $0
  .L003BCF8C:
    /* 2BCF8C 003BCF8C 0800E003 */  jr         $31
    /* 2BCF90 003BCF90 00000000 */   nop
    /* 2BCF94 003BCF94 00000000 */  nop
    /* 2BCF98 003BCF98 00000000 */  nop
    /* 2BCF9C 003BCF9C 00000000 */  nop
.size func_003bcf60, 0x40
