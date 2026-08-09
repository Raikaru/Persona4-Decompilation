.section .text
.set noat
.set noreorder
glabel func_0018bbf0
    /* 8BBF0 0018BBF0 04008014 */  bnez       $4, .L0018BC04
    /* 8BBF4 0018BBF4 00000000 */   nop
    /* 8BBF8 0018BBF8 01000224 */  addiu      $2, $0, 0x1
    /* 8BBFC 0018BBFC 05000010 */  b          .L0018BC14
    /* 8BC00 0018BC00 00000000 */   nop
  .L0018BC04:
    /* 8BC04 0018BC04 3800828C */  lw         $2, 0x38($4)
    /* 8BC08 0018BC08 0000428C */  lw         $2, 0x0($2)
    /* 8BC0C 0018BC0C 0400422C */  sltiu      $2, $2, 0x4
    /* 8BC10 0018BC10 01004238 */  xori       $2, $2, 0x1
  .L0018BC14:
    /* 8BC14 0018BC14 0800E003 */  jr         $31
    /* 8BC18 0018BC18 00000000 */   nop
    /* 8BC1C 0018BC1C 00000000 */  nop
.size func_0018bbf0, 0x30
