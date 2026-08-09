.section .text
.set noat
.set noreorder
glabel func_0019ef90
    /* 9EF90 0019EF90 ACB3838F */  lw         $3, -0x4C54($28)
    /* 9EF94 0019EF94 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* 9EF98 0019EF98 C0100200 */  sll        $2, $2, 3
    /* 9EF9C 0019EF9C 21104300 */  addu       $2, $2, $3
    /* 9EFA0 0019EFA0 7C01428C */  lw         $2, 0x17C($2)
    /* 9EFA4 0019EFA4 FFFFA430 */  andi       $4, $5, 0xFFFF
    /* 9EFA8 0019EFA8 07000010 */  b          .L0019EFC8
    /* 9EFAC 0019EFAC 00000000 */   nop
  .L0019EFB0:
    /* 9EFB0 0019EFB0 A4004394 */  lhu        $3, 0xA4($2)
    /* 9EFB4 0019EFB4 03006414 */  bne        $3, $4, .L0019EFC4
    /* 9EFB8 0019EFB8 00000000 */   nop
    /* 9EFBC 0019EFBC 05000010 */  b          .L0019EFD4
    /* 9EFC0 0019EFC0 00000000 */   nop
  .L0019EFC4:
    /* 9EFC4 0019EFC4 680A428C */  lw         $2, 0xA68($2)
  .L0019EFC8:
    /* 9EFC8 0019EFC8 F9FF4014 */  bnez       $2, .L0019EFB0
    /* 9EFCC 0019EFCC 00000000 */   nop
    /* 9EFD0 0019EFD0 2D100000 */  daddu      $2, $0, $0
  .L0019EFD4:
    /* 9EFD4 0019EFD4 0800E003 */  jr         $31
    /* 9EFD8 0019EFD8 00000000 */   nop
    /* 9EFDC 0019EFDC 00000000 */  nop
.size func_0019ef90, 0x50
