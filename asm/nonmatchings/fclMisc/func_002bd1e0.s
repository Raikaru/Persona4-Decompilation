.section .text
.set noat
.set noreorder
glabel func_002bd1e0
    /* 1BD1E0 002BD1E0 7CB5838F */  lw         $3, -0x4A84($28)
    /* 1BD1E4 002BD1E4 40100400 */  sll        $2, $4, 1
    /* 1BD1E8 002BD1E8 21104400 */  addu       $2, $2, $4
    /* 1BD1EC 002BD1EC 80100200 */  sll        $2, $2, 2
    /* 1BD1F0 002BD1F0 21184300 */  addu       $3, $2, $3
    /* 1BD1F4 002BD1F4 1C00628C */  lw         $2, 0x1C($3)
    /* 1BD1F8 002BD1F8 02004230 */  andi       $2, $2, 0x2
    /* 1BD1FC 002BD1FC 04004014 */  bnez       $2, .L002BD210
    /* 1BD200 002BD200 00000000 */   nop
    /* 1BD204 002BD204 2D100000 */  daddu      $2, $0, $0
    /* 1BD208 002BD208 02000010 */  b          .L002BD214
    /* 1BD20C 002BD20C 00000000 */   nop
  .L002BD210:
    /* 1BD210 002BD210 2400628C */  lw         $2, 0x24($3)
  .L002BD214:
    /* 1BD214 002BD214 0800E003 */  jr         $31
    /* 1BD218 002BD218 00000000 */   nop
    /* 1BD21C 002BD21C 00000000 */  nop
.size func_002bd1e0, 0x40
