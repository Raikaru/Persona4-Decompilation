.section .text
.set noat
.set noreorder
glabel func_004ad410
    /* 3AD410 004AD410 B400828C */  lw         $2, 0xB4($4)
    /* 3AD414 004AD414 06004010 */  beqz       $2, .L004AD430
    /* 3AD418 004AD418 00000000 */   nop
    /* 3AD41C 004AD41C EE004290 */  lbu        $2, 0xEE($2)
    /* 3AD420 004AD420 01004238 */  xori       $2, $2, 0x1
    /* 3AD424 004AD424 0100422C */  sltiu      $2, $2, 0x1
    /* 3AD428 004AD428 02000010 */  b          .L004AD434
    /* 3AD42C 004AD42C 00000000 */   nop
  .L004AD430:
    /* 3AD430 004AD430 01000224 */  addiu      $2, $0, 0x1
  .L004AD434:
    /* 3AD434 004AD434 0800E003 */  jr         $31
    /* 3AD438 004AD438 00000000 */   nop
    /* 3AD43C 004AD43C 00000000 */  nop
.size func_004ad410, 0x30
