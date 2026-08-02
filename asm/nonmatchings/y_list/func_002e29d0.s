.section .text
.set noat
.set noreorder
glabel func_002e29d0
    /* 1E29D0 002E29D0 8CB5828F */  lw         $2, -0x4A74($28)
    /* 1E29D4 002E29D4 05004010 */  beqz       $2, .L002E29EC
    /* 1E29D8 002E29D8 00000000 */   nop
    /* 1E29DC 002E29DC 3800428C */  lw         $2, 0x38($2)
    /* 1E29E0 002E29E0 00004280 */  lb         $2, 0x0($2)
    /* 1E29E4 002E29E4 02000010 */  b          .L002E29F0
    /* 1E29E8 002E29E8 00000000 */   nop
  .L002E29EC:
    /* 1E29EC 002E29EC FFFF0224 */  addiu      $2, $0, -0x1
  .L002E29F0:
    /* 1E29F0 002E29F0 0800E003 */  jr         $31
    /* 1E29F4 002E29F4 00000000 */   nop
    /* 1E29F8 002E29F8 00000000 */  nop
    /* 1E29FC 002E29FC 00000000 */  nop
.size func_002e29d0, 0x30
