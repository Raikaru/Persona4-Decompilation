.section .text
.set noat
.set noreorder
glabel func_0039bb70
    /* 29BB70 0039BB70 0400868C */  lw         $6, 0x4($4)
    /* 29BB74 0039BB74 2B080600 */  sltu       $1, $0, $6
    /* 29BB78 0039BB78 0F002010 */  beqz       $1, .L0039BBB8
    /* 29BB7C 0039BB7C 2D380000 */   daddu     $7, $0, $0
    /* 29BB80 0039BB80 0000838C */  lw         $3, 0x0($4)
    /* 29BB84 0039BB84 2D206000 */  daddu      $4, $3, $0
  .L0039BB88:
    /* 29BB88 0039BB88 0800828C */  lw         $2, 0x8($4)
    /* 29BB8C 0039BB8C 0600A214 */  bne        $5, $2, .L0039BBA8
    /* 29BB90 0039BB90 00000000 */   nop
    /* 29BB94 0039BB94 80100700 */  sll        $2, $7, 2
    /* 29BB98 0039BB98 21104700 */  addu       $2, $2, $7
    /* 29BB9C 0039BB9C 80100200 */  sll        $2, $2, 2
    /* 29BBA0 0039BBA0 06000010 */  b          .L0039BBBC
    /* 29BBA4 0039BBA4 21106200 */   addu      $2, $3, $2
  .L0039BBA8:
    /* 29BBA8 0039BBA8 0100E724 */  addiu      $7, $7, 0x1
    /* 29BBAC 0039BBAC 2B10E600 */  sltu       $2, $7, $6
    /* 29BBB0 0039BBB0 F5FF4014 */  bnez       $2, .L0039BB88
    /* 29BBB4 0039BBB4 14008424 */   addiu     $4, $4, 0x14
  .L0039BBB8:
    /* 29BBB8 0039BBB8 2D100000 */  daddu      $2, $0, $0
  .L0039BBBC:
    /* 29BBBC 0039BBBC 0800E003 */  jr         $31
    /* 29BBC0 0039BBC0 00000000 */   nop
    /* 29BBC4 0039BBC4 00000000 */  nop
    /* 29BBC8 0039BBC8 00000000 */  nop
    /* 29BBCC 0039BBCC 00000000 */  nop
.size func_0039bb70, 0x60
