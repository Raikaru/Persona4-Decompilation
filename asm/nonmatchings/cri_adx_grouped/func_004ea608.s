.section .text
.set noat
.set noreorder
glabel func_004ea608
    /* 3EA608 004EA608 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA60C 004EA60C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA610 004EA610 0500801C */  bgtz       $4, .L004EA628
    /* 3EA614 004EA614 0800BFFF */   sd        $31, 0x8($29)
    /* 3EA618 004EA618 7600053C */  lui        $5, %hi(D_0075BFF0)
    /* 3EA61C 004EA61C 2D200000 */  daddu      $4, $0, $0
    /* 3EA620 004EA620 0E000010 */  b          .L004EA65C
    /* 3EA624 004EA624 F0BFA524 */   addiu     $5, $5, %lo(D_0075BFF0)
  .L004EA628:
    /* 3EA628 004EA628 0500C010 */  beqz       $6, .L004EA640
    /* 3EA62C 004EA62C 7600053C */   lui       $5, %hi(D_0075C020)
    /* 3EA630 004EA630 2D200000 */  daddu      $4, $0, $0
    /* 3EA634 004EA634 09000010 */  b          .L004EA65C
    /* 3EA638 004EA638 20C0A524 */   addiu     $5, $5, %lo(D_0075C020)
    /* 3EA63C 004EA63C 00000000 */  nop
  .L004EA640:
    /* 3EA640 004EA640 10A8130C */  jal        func_004ea040
    /* 3EA644 004EA644 00000000 */   nop
    /* 3EA648 004EA648 7600053C */  lui        $5, %hi(D_0075C048)
    /* 3EA64C 004EA64C 2D804000 */  daddu      $16, $2, $0
    /* 3EA650 004EA650 48C0A524 */  addiu      $5, $5, %lo(D_0075C048)
    /* 3EA654 004EA654 06000016 */  bnez       $16, .L004EA670
    /* 3EA658 004EA658 2D200000 */   daddu     $4, $0, $0
  .L004EA65C:
    /* 3EA65C 004EA65C 9AA7130C */  jal        func_004e9e68
    /* 3EA660 004EA660 00000000 */   nop
    /* 3EA664 004EA664 05000010 */  b          .L004EA67C
    /* 3EA668 004EA668 2D100000 */   daddu     $2, $0, $0
    /* 3EA66C 004EA66C 00000000 */  nop
  .L004EA670:
    /* 3EA670 004EA670 2EA8130C */  jal        func_004ea0b8
    /* 3EA674 004EA674 2D200002 */   daddu     $4, $16, $0
    /* 3EA678 004EA678 2D100002 */  daddu      $2, $16, $0
  .L004EA67C:
    /* 3EA67C 004EA67C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA680 004EA680 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA684 004EA684 0800E003 */  jr         $31
    /* 3EA688 004EA688 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA68C 004EA68C 00000000 */  nop
.size func_004ea608, 0x88
