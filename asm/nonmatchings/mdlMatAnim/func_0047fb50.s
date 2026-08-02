.section .text
.set noat
.set noreorder
glabel func_0047fb50
    /* 37FB50 0047FB50 0400A894 */  lhu        $8, 0x4($5)
    /* 37FB54 0047FB54 0000828C */  lw         $2, 0x0($4)
    /* 37FB58 0047FB58 1F000010 */  b          .L0047FBD8
    /* 37FB5C 0047FB5C 00000000 */   nop
  .L0047FB60:
    /* 37FB60 0047FB60 5000478C */  lw         $7, 0x50($2)
    /* 37FB64 0047FB64 0300E514 */  bne        $7, $5, .L0047FB74
    /* 37FB68 0047FB68 00000000 */   nop
    /* 37FB6C 0047FB6C 1D000010 */  b          .L0047FBE4
    /* 37FB70 0047FB70 00000000 */   nop
  .L0047FB74:
    /* 37FB74 0047FB74 0400E394 */  lhu        $3, 0x4($7)
    /* 37FB78 0047FB78 16006814 */  bne        $3, $8, .L0047FBD4
    /* 37FB7C 0047FB7C 00000000 */   nop
    /* 37FB80 0047FB80 2D480000 */  daddu      $9, $0, $0
    /* 37FB84 0047FB84 0C000010 */  b          .L0047FBB8
    /* 37FB88 0047FB88 00000000 */   nop
  .L0047FB8C:
    /* 37FB8C 0047FB8C FFFF2331 */  andi       $3, $9, 0xFFFF
    /* 37FB90 0047FB90 80300300 */  sll        $6, $3, 2
    /* 37FB94 0047FB94 0000E38C */  lw         $3, 0x0($7)
    /* 37FB98 0047FB98 21186600 */  addu       $3, $3, $6
    /* 37FB9C 0047FB9C 0000648C */  lw         $4, 0x0($3)
    /* 37FBA0 0047FBA0 0000A38C */  lw         $3, 0x0($5)
    /* 37FBA4 0047FBA4 21186600 */  addu       $3, $3, $6
    /* 37FBA8 0047FBA8 0000638C */  lw         $3, 0x0($3)
    /* 37FBAC 0047FBAC 05008314 */  bne        $4, $3, .L0047FBC4
    /* 37FBB0 0047FBB0 00000000 */   nop
    /* 37FBB4 0047FBB4 01002925 */  addiu      $9, $9, 0x1
  .L0047FBB8:
    /* 37FBB8 0047FBB8 2A182801 */  slt        $3, $9, $8
    /* 37FBBC 0047FBBC F3FF6014 */  bnez       $3, .L0047FB8C
    /* 37FBC0 0047FBC0 00000000 */   nop
  .L0047FBC4:
    /* 37FBC4 0047FBC4 03002815 */  bne        $9, $8, .L0047FBD4
    /* 37FBC8 0047FBC8 00000000 */   nop
    /* 37FBCC 0047FBCC 05000010 */  b          .L0047FBE4
    /* 37FBD0 0047FBD0 00000000 */   nop
  .L0047FBD4:
    /* 37FBD4 0047FBD4 5400428C */  lw         $2, 0x54($2)
  .L0047FBD8:
    /* 37FBD8 0047FBD8 E1FF4014 */  bnez       $2, .L0047FB60
    /* 37FBDC 0047FBDC 00000000 */   nop
    /* 37FBE0 0047FBE0 2D100000 */  daddu      $2, $0, $0
  .L0047FBE4:
    /* 37FBE4 0047FBE4 0800E003 */  jr         $31
    /* 37FBE8 0047FBE8 00000000 */   nop
    /* 37FBEC 0047FBEC 00000000 */  nop
.size func_0047fb50, 0xa0
