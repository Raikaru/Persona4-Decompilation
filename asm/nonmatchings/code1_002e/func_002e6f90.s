.section .text
.set noat
.set noreorder
glabel func_002e6f90
    /* 1E6F90 002E6F90 2D400000 */  daddu      $8, $0, $0
    /* 1E6F94 002E6F94 3C3C0500 */  dsll32     $7, $5, 16
    /* 1E6F98 002E6F98 3F3C0700 */  dsra32     $7, $7, 16
    /* 1E6F9C 002E6F9C 60008684 */  lh         $6, 0x60($4)
    /* 1E6FA0 002E6FA0 0C000010 */  b          .L002E6FD4
    /* 1E6FA4 002E6FA4 00000000 */   nop
  .L002E6FA8:
    /* 1E6FA8 002E6FA8 40100300 */  sll        $2, $3, 1
    /* 1E6FAC 002E6FAC 21108200 */  addu       $2, $4, $2
    /* 1E6FB0 002E6FB0 00004284 */  lh         $2, 0x0($2)
    /* 1E6FB4 002E6FB4 0400E214 */  bne        $7, $2, .L002E6FC8
    /* 1E6FB8 002E6FB8 00000000 */   nop
    /* 1E6FBC 002E6FBC 2D100000 */  daddu      $2, $0, $0
    /* 1E6FC0 002E6FC0 10000010 */  b          .L002E7004
    /* 1E6FC4 002E6FC4 00000000 */   nop
  .L002E6FC8:
    /* 1E6FC8 002E6FC8 01000225 */  addiu      $2, $8, 0x1
    /* 1E6FCC 002E6FCC 3C440200 */  dsll32     $8, $2, 16
    /* 1E6FD0 002E6FD0 3F440800 */  dsra32     $8, $8, 16
  .L002E6FD4:
    /* 1E6FD4 002E6FD4 3C1C0800 */  dsll32     $3, $8, 16
    /* 1E6FD8 002E6FD8 3F1C0300 */  dsra32     $3, $3, 16
    /* 1E6FDC 002E6FDC 2A106600 */  slt        $2, $3, $6
    /* 1E6FE0 002E6FE0 F1FF4014 */  bnez       $2, .L002E6FA8
    /* 1E6FE4 002E6FE4 00000000 */   nop
    /* 1E6FE8 002E6FE8 40100600 */  sll        $2, $6, 1
    /* 1E6FEC 002E6FEC 21108200 */  addu       $2, $4, $2
    /* 1E6FF0 002E6FF0 000045A4 */  sh         $5, 0x0($2)
    /* 1E6FF4 002E6FF4 60008284 */  lh         $2, 0x60($4)
    /* 1E6FF8 002E6FF8 01004224 */  addiu      $2, $2, 0x1
    /* 1E6FFC 002E6FFC 600082A4 */  sh         $2, 0x60($4)
    /* 1E7000 002E7000 01000224 */  addiu      $2, $0, 0x1
  .L002E7004:
    /* 1E7004 002E7004 0800E003 */  jr         $31
    /* 1E7008 002E7008 00000000 */   nop
    /* 1E700C 002E700C 00000000 */  nop
.size func_002e6f90, 0x80
