.section .text
.set noat
.set noreorder
glabel func_002ac360
    /* 1AC360 002AC360 2D280000 */  daddu      $5, $0, $0
    /* 1AC364 002AC364 08000010 */  b          .L002AC388
    /* 1AC368 002AC368 00000000 */   nop
  .L002AC36C:
    /* 1AC36C 002AC36C 40200400 */  sll        $4, $4, 1
    /* 1AC370 002AC370 68B5838F */  lw         $3, -0x4A98($28)
    /* 1AC374 002AC374 21186400 */  addu       $3, $3, $4
    /* 1AC378 002AC378 000060A4 */  sh         $0, 0x0($3)
    /* 1AC37C 002AC37C 0100A324 */  addiu      $3, $5, 0x1
    /* 1AC380 002AC380 3C2C0300 */  dsll32     $5, $3, 16
    /* 1AC384 002AC384 3F2C0500 */  dsra32     $5, $5, 16
  .L002AC388:
    /* 1AC388 002AC388 3C240500 */  dsll32     $4, $5, 16
    /* 1AC38C 002AC38C 3F240400 */  dsra32     $4, $4, 16
    /* 1AC390 002AC390 18008328 */  slti       $3, $4, 0x18
    /* 1AC394 002AC394 F5FF6014 */  bnez       $3, .L002AC36C
    /* 1AC398 002AC398 00000000 */   nop
    /* 1AC39C 002AC39C 0800E003 */  jr         $31
    /* 1AC3A0 002AC3A0 00000000 */   nop
    /* 1AC3A4 002AC3A4 00000000 */  nop
    /* 1AC3A8 002AC3A8 00000000 */  nop
    /* 1AC3AC 002AC3AC 00000000 */  nop
.size func_002ac360, 0x50
