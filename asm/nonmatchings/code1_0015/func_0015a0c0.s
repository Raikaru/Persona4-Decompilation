.section .text
.set noat
.set noreorder
glabel func_0015a0c0
    /* 5A0C0 0015A0C0 44B2828F */  lw         $2, -0x4DBC($28)
    /* 5A0C4 0015A0C4 04004014 */  bnez       $2, .L0015A0D8
    /* 5A0C8 0015A0C8 00000000 */   nop
    /* 5A0CC 0015A0CC 2D100000 */  daddu      $2, $0, $0
    /* 5A0D0 0015A0D0 06000010 */  b          .L0015A0EC
    /* 5A0D4 0015A0D4 00000000 */   nop
  .L0015A0D8:
    /* 5A0D8 0015A0D8 3800448C */  lw         $4, 0x38($2)
    /* 5A0DC 0015A0DC 0400828C */  lw         $2, 0x4($4)
    /* 5A0E0 0015A0E0 00190200 */  sll        $3, $2, 4
    /* 5A0E4 0015A0E4 2000828C */  lw         $2, 0x20($4)
    /* 5A0E8 0015A0E8 21104300 */  addu       $2, $2, $3
  .L0015A0EC:
    /* 5A0EC 0015A0EC 0800E003 */  jr         $31
    /* 5A0F0 0015A0F0 00000000 */   nop
    /* 5A0F4 0015A0F4 00000000 */  nop
    /* 5A0F8 0015A0F8 00000000 */  nop
    /* 5A0FC 0015A0FC 00000000 */  nop
.size func_0015a0c0, 0x40
