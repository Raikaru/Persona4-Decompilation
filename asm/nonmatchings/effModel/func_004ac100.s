.section .text
.set noat
.set noreorder
glabel func_004ac100
    /* 3AC100 004AC100 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AC104 004AC104 2000BFFF */  sd         $31, 0x20($29)
    /* 3AC108 004AC108 1000B17F */  sq         $17, 0x10($29)
    /* 3AC10C 004AC10C 0000B07F */  sq         $16, 0x0($29)
    /* 3AC110 004AC110 2D888000 */  daddu      $17, $4, $0
    /* 3AC114 004AC114 2D200000 */  daddu      $4, $0, $0
    /* 3AC118 004AC118 A0AF120C */  jal        func_004abe80
    /* 3AC11C 004AC11C 00000000 */   nop
    /* 3AC120 004AC120 2D804000 */  daddu      $16, $2, $0
    /* 3AC124 004AC124 2C000426 */  addiu      $4, $16, 0x2C
    /* 3AC128 004AC128 2C002526 */  addiu      $5, $17, 0x2C
    /* 3AC12C 004AC12C 68000624 */  addiu      $6, $0, 0x68
    /* 3AC130 004AC130 04FE100C */  jal        func_0043f810
    /* 3AC134 004AC134 00000000 */   nop
    /* 3AC138 004AC138 2D200002 */  daddu      $4, $16, $0
    /* 3AC13C 004AC13C 2D282002 */  daddu      $5, $17, $0
    /* 3AC140 004AC140 5CB0120C */  jal        func_004ac170
    /* 3AC144 004AC144 00000000 */   nop
    /* 3AC148 004AC148 2D100002 */  daddu      $2, $16, $0
    /* 3AC14C 004AC14C 2000BFDF */  ld         $31, 0x20($29)
    /* 3AC150 004AC150 1000B17B */  lq         $17, 0x10($29)
    /* 3AC154 004AC154 0000B07B */  lq         $16, 0x0($29)
    /* 3AC158 004AC158 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AC15C 004AC15C 0800E003 */  jr         $31
    /* 3AC160 004AC160 00000000 */   nop
    /* 3AC164 004AC164 00000000 */  nop
    /* 3AC168 004AC168 00000000 */  nop
    /* 3AC16C 004AC16C 00000000 */  nop
.size func_004ac100, 0x70
