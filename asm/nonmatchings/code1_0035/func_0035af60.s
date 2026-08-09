.section .text
.set noat
.set noreorder
glabel func_0035af60
    /* 25AF60 0035AF60 3800838C */  lw         $3, 0x38($4)
    /* 25AF64 0035AF64 2C00628C */  lw         $2, 0x2C($3)
    /* 25AF68 0035AF68 04004010 */  beqz       $2, .L0035AF7C
    /* 25AF6C 0035AF6C 00000000 */   nop
    /* 25AF70 0035AF70 20006280 */  lb         $2, 0x20($3)
    /* 25AF74 0035AF74 04004014 */  bnez       $2, .L0035AF88
    /* 25AF78 0035AF78 00000000 */   nop
  .L0035AF7C:
    /* 25AF7C 0035AF7C 2D100000 */  daddu      $2, $0, $0
    /* 25AF80 0035AF80 02000010 */  b          .L0035AF8C
    /* 25AF84 0035AF84 00000000 */   nop
  .L0035AF88:
    /* 25AF88 0035AF88 01000224 */  addiu      $2, $0, 0x1
  .L0035AF8C:
    /* 25AF8C 0035AF8C 0800E003 */  jr         $31
    /* 25AF90 0035AF90 00000000 */   nop
    /* 25AF94 0035AF94 00000000 */  nop
    /* 25AF98 0035AF98 00000000 */  nop
    /* 25AF9C 0035AF9C 00000000 */  nop
.size func_0035af60, 0x40
