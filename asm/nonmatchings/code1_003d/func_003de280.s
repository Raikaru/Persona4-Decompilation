.section .text
.set noat
.set noreorder
glabel func_003de280
    /* 2DE280 003DE280 0400828C */  lw         $2, 0x4($4)
    /* 2DE284 003DE284 2B08A200 */  sltu       $1, $5, $2
    /* 2DE288 003DE288 07002010 */  beqz       $1, .L003DE2A8
    /* 2DE28C 003DE28C 00000000 */   nop
    /* 2DE290 003DE290 5800828C */  lw         $2, 0x58($4)
    /* 2DE294 003DE294 C0180500 */  sll        $3, $5, 3
    /* 2DE298 003DE298 23186500 */  subu       $3, $3, $5
    /* 2DE29C 003DE29C 00190300 */  sll        $3, $3, 4
    /* 2DE2A0 003DE2A0 02000010 */  b          .L003DE2AC
    /* 2DE2A4 003DE2A4 21104300 */   addu      $2, $2, $3
  .L003DE2A8:
    /* 2DE2A8 003DE2A8 2D100000 */  daddu      $2, $0, $0
  .L003DE2AC:
    /* 2DE2AC 003DE2AC 0800E003 */  jr         $31
    /* 2DE2B0 003DE2B0 00000000 */   nop
    /* 2DE2B4 003DE2B4 00000000 */  nop
    /* 2DE2B8 003DE2B8 00000000 */  nop
    /* 2DE2BC 003DE2BC 00000000 */  nop
.size func_003de280, 0x40
