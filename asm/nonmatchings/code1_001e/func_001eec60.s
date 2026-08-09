.section .text
.set noat
.set noreorder
glabel func_001eec60
    /* EEC60 001EEC60 0500033C */  lui        $3, (0x55730 >> 16)
    /* EEC64 001EEC64 30576334 */  ori        $3, $3, (0x55730 & 0xFFFF)
    /* EEC68 001EEC68 00008344 */  mtc1       $3, $f0
    /* EEC6C 001EEC6C 00000000 */  nop
    /* EEC70 001EEC70 60008046 */  cvt.s.w    $f1, $f0
    /* EEC74 001EEC74 ACB3838F */  lw         $3, -0x4C54($28)
    /* EEC78 001EEC78 3C0A6424 */  addiu      $4, $3, 0xA3C
    /* EEC7C 001EEC7C 3C0A638C */  lw         $3, 0xA3C($3)
    /* EEC80 001EEC80 2D286000 */  daddu      $5, $3, $0
    /* EEC84 001EEC84 08000010 */  b          .L001EECA8
    /* EEC88 001EEC88 00000000 */   nop
  .L001EEC8C:
    /* EEC8C 001EEC8C 2000A0C4 */  lwc1       $f0, 0x20($5)
    /* EEC90 001EEC90 36080046 */  c.le.s     $f1, $f0
    /* EEC94 001EEC94 03000145 */  bc1t       .L001EECA4
    /* EEC98 001EEC98 00000000 */   nop
    /* EEC9C 001EEC9C 2D10A000 */  daddu      $2, $5, $0
    /* EECA0 001EECA0 46000046 */  mov.s      $f1, $f0
  .L001EECA4:
    /* EECA4 001EECA4 2400A58C */  lw         $5, 0x24($5)
  .L001EECA8:
    /* EECA8 001EECA8 F8FFA014 */  bnez       $5, .L001EEC8C
    /* EECAC 001EECAC 00000000 */   nop
    /* EECB0 001EECB0 2D280000 */  daddu      $5, $0, $0
    /* EECB4 001EECB4 05000010 */  b          .L001EECCC
    /* EECB8 001EECB8 00000000 */   nop
  .L001EECBC:
    /* EECBC 001EECBC 07006210 */  beq        $3, $2, .L001EECDC
    /* EECC0 001EECC0 00000000 */   nop
    /* EECC4 001EECC4 2D286000 */  daddu      $5, $3, $0
    /* EECC8 001EECC8 2400638C */  lw         $3, 0x24($3)
  .L001EECCC:
    /* EECCC 001EECCC 00000000 */  nop
    /* EECD0 001EECD0 00000000 */  nop
    /* EECD4 001EECD4 F9FF6014 */  bnez       $3, .L001EECBC
    /* EECD8 001EECD8 00000000 */   nop
  .L001EECDC:
    /* EECDC 001EECDC 09006010 */  beqz       $3, .L001EED04
    /* EECE0 001EECE0 00000000 */   nop
    /* EECE4 001EECE4 0500A010 */  beqz       $5, .L001EECFC
    /* EECE8 001EECE8 00000000 */   nop
    /* EECEC 001EECEC 2400638C */  lw         $3, 0x24($3)
    /* EECF0 001EECF0 2400A3AC */  sw         $3, 0x24($5)
    /* EECF4 001EECF4 03000010 */  b          .L001EED04
    /* EECF8 001EECF8 00000000 */   nop
  .L001EECFC:
    /* EECFC 001EECFC 2400638C */  lw         $3, 0x24($3)
    /* EED00 001EED00 000083AC */  sw         $3, 0x0($4)
  .L001EED04:
    /* EED04 001EED04 0800E003 */  jr         $31
    /* EED08 001EED08 00000000 */   nop
    /* EED0C 001EED0C 00000000 */  nop
.size func_001eec60, 0xb0
