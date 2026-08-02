.section .text
.set noat
.set noreorder
glabel func_0011ba00
    /* 1BA00 0011BA00 3800828C */  lw         $2, 0x38($4)
    /* 1BA04 0011BA04 3405438C */  lw         $3, 0x534($2)
    /* 1BA08 0011BA08 02006230 */  andi       $2, $3, 0x2
    /* 1BA0C 0011BA0C 04004014 */  bnez       $2, .L0011BA20
    /* 1BA10 0011BA10 00000000 */   nop
    /* 1BA14 0011BA14 04006230 */  andi       $2, $3, 0x4
    /* 1BA18 0011BA18 04004010 */  beqz       $2, .L0011BA2C
    /* 1BA1C 0011BA1C 00000000 */   nop
  .L0011BA20:
    /* 1BA20 0011BA20 01000224 */  addiu      $2, $0, 0x1
    /* 1BA24 0011BA24 02000010 */  b          .L0011BA30
    /* 1BA28 0011BA28 00000000 */   nop
  .L0011BA2C:
    /* 1BA2C 0011BA2C 2D100000 */  daddu      $2, $0, $0
  .L0011BA30:
    /* 1BA30 0011BA30 0800E003 */  jr         $31
    /* 1BA34 0011BA34 00000000 */   nop
    /* 1BA38 0011BA38 00000000 */  nop
    /* 1BA3C 0011BA3C 00000000 */  nop
.size func_0011ba00, 0x40
