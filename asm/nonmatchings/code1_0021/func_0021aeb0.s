.section .text
.set noat
.set noreorder
glabel func_0021aeb0
    /* 11AEB0 0021AEB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 11AEB4 0021AEB4 3000BFFF */  sd         $31, 0x30($29)
    /* 11AEB8 0021AEB8 2000B17F */  sq         $17, 0x20($29)
    /* 11AEBC 0021AEBC 1000B07F */  sq         $16, 0x10($29)
    /* 11AEC0 0021AEC0 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 11AEC4 0021AEC4 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 11AEC8 0021AEC8 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 11AECC 0021AECC 2D888000 */  daddu      $17, $4, $0
    /* 11AED0 0021AED0 2D80A000 */  daddu      $16, $5, $0
    /* 11AED4 0021AED4 86650046 */  mov.s      $f22, $f12
    /* 11AED8 0021AED8 466D0046 */  mov.s      $f21, $f13
    /* 11AEDC 0021AEDC 06750046 */  mov.s      $f20, $f14
    /* 11AEE0 0021AEE0 2500C010 */  beqz       $6, .L0021AF78
    /* 11AEE4 0021AEE4 00000000 */   nop
    /* 11AEE8 0021AEE8 640A048E */  lw         $4, 0xA64($16)
    /* 11AEEC 0021AEEC 1B008010 */  beqz       $4, .L0021AF5C
    /* 11AEF0 0021AEF0 00000000 */   nop
    /* 11AEF4 0021AEF4 2D280000 */  daddu      $5, $0, $0
    /* 11AEF8 0021AEF8 3C0A090C */  jal        func_002428f0
    /* 11AEFC 0021AEFC 00000000 */   nop
    /* 11AF00 0021AF00 16004014 */  bnez       $2, .L0021AF5C
    /* 11AF04 0021AF04 00000000 */   nop
    /* 11AF08 0021AF08 640A048E */  lw         $4, 0xA64($16)
    /* 11AF0C 0021AF0C 00008294 */  lhu        $2, 0x0($4)
    /* 11AF10 0021AF10 20004230 */  andi       $2, $2, 0x20
    /* 11AF14 0021AF14 07004010 */  beqz       $2, .L0021AF34
    /* 11AF18 0021AF18 00000000 */   nop
    /* 11AF1C 0021AF1C B4C7080C */  jal        func_00231ed0
    /* 11AF20 0021AF20 00000000 */   nop
    /* 11AF24 0021AF24 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 11AF28 0021AF28 02004128 */  slti       $1, $2, 0x2
    /* 11AF2C 0021AF2C 0B002014 */  bnez       $1, .L0021AF5C
    /* 11AF30 0021AF30 00000000 */   nop
  .L0021AF34:
    /* 11AF34 0021AF34 00008044 */  mtc1       $0, $f0
    /* 11AF38 0021AF38 00000000 */  nop
    /* 11AF3C 0021AF3C 36A00046 */  c.le.s     $f20, $f0
    /* 11AF40 0021AF40 06000145 */  bc1t       .L0021AF5C
    /* 11AF44 0021AF44 00000000 */   nop
    /* 11AF48 0021AF48 988480C7 */  lwc1       $f0, -0x7B68($28)
    /* 11AF4C 0021AF4C 34A00046 */  c.lt.s     $f20, $f0
    /* 11AF50 0021AF50 02000045 */  bc1f       .L0021AF5C
    /* 11AF54 0021AF54 00000000 */   nop
    /* 11AF58 0021AF58 06050046 */  mov.s      $f20, $f0
  .L0021AF5C:
    /* 11AF5C 0021AF5C 2D202002 */  daddu      $4, $17, $0
    /* 11AF60 0021AF60 3C0A0526 */  addiu      $5, $16, 0xA3C
    /* 11AF64 0021AF64 06B30046 */  mov.s      $f12, $f22
    /* 11AF68 0021AF68 46AB0046 */  mov.s      $f13, $f21
    /* 11AF6C 0021AF6C 86A30046 */  mov.s      $f14, $f20
    /* 11AF70 0021AF70 CC6C080C */  jal        func_0021b330
    /* 11AF74 0021AF74 00000000 */   nop
  .L0021AF78:
    /* 11AF78 0021AF78 3000BFDF */  ld         $31, 0x30($29)
    /* 11AF7C 0021AF7C 2000B17B */  lq         $17, 0x20($29)
    /* 11AF80 0021AF80 1000B07B */  lq         $16, 0x10($29)
    /* 11AF84 0021AF84 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 11AF88 0021AF88 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 11AF8C 0021AF8C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 11AF90 0021AF90 4000BD27 */  addiu      $29, $29, 0x40
    /* 11AF94 0021AF94 0800E003 */  jr         $31
    /* 11AF98 0021AF98 00000000 */   nop
    /* 11AF9C 0021AF9C 00000000 */  nop
.size func_0021aeb0, 0xf0
