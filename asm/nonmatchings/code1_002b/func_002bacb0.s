.section .text
.set noat
.set noreorder
glabel func_002bacb0
    /* 1BACB0 002BACB0 2D200000 */  daddu      $4, $0, $0
    /* 1BACB4 002BACB4 8800033C */  lui        $3, %hi(D_00882F40)
    /* 1BACB8 002BACB8 402F6324 */  addiu      $3, $3, %lo(D_00882F40)
    /* 1BACBC 002BACBC 0B000010 */  b          .L002BACEC
    /* 1BACC0 002BACC0 00000000 */   nop
  .L002BACC4:
    /* 1BACC4 002BACC4 80100400 */  sll        $2, $4, 2
    /* 1BACC8 002BACC8 21106200 */  addu       $2, $3, $2
    /* 1BACCC 002BACCC 0000428C */  lw         $2, 0x0($2)
    /* 1BACD0 002BACD0 05004014 */  bnez       $2, .L002BACE8
    /* 1BACD4 002BACD4 00000000 */   nop
    /* 1BACD8 002BACD8 3C160400 */  dsll32     $2, $4, 24
    /* 1BACDC 002BACDC 3F160200 */  dsra32     $2, $2, 24
    /* 1BACE0 002BACE0 06000010 */  b          .L002BACFC
    /* 1BACE4 002BACE4 00000000 */   nop
  .L002BACE8:
    /* 1BACE8 002BACE8 01008424 */  addiu      $4, $4, 0x1
  .L002BACEC:
    /* 1BACEC 002BACEC 05008228 */  slti       $2, $4, 0x5
    /* 1BACF0 002BACF0 F4FF4014 */  bnez       $2, .L002BACC4
    /* 1BACF4 002BACF4 00000000 */   nop
    /* 1BACF8 002BACF8 FFFF0224 */  addiu      $2, $0, -0x1
  .L002BACFC:
    /* 1BACFC 002BACFC 0800E003 */  jr         $31
    /* 1BAD00 002BAD00 00000000 */   nop
    /* 1BAD04 002BAD04 00000000 */  nop
    /* 1BAD08 002BAD08 00000000 */  nop
    /* 1BAD0C 002BAD0C 00000000 */  nop
.size func_002bacb0, 0x60
