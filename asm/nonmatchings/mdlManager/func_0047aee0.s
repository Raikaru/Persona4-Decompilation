.section .text
.set noat
.set noreorder
glabel func_0047aee0
    /* 37AEE0 0047AEE0 2D580000 */  daddu      $11, $0, $0
    /* 37AEE4 0047AEE4 08000624 */  addiu      $6, $0, 0x8
    /* 37AEE8 0047AEE8 17000010 */  b          .L0047AF48
    /* 37AEEC 0047AEEC 00000000 */   nop
  .L0047AEF0:
    /* 37AEF0 0047AEF0 FFFF6731 */  andi       $7, $11, 0xFFFF
    /* 37AEF4 0047AEF4 40180700 */  sll        $3, $7, 1
    /* 37AEF8 0047AEF8 21186700 */  addu       $3, $3, $7
    /* 37AEFC 0047AEFC 80180300 */  sll        $3, $3, 2
    /* 37AF00 0047AF00 21188300 */  addu       $3, $4, $3
    /* 37AF04 0047AF04 9002638C */  lw         $3, 0x290($3)
    /* 37AF08 0047AF08 0D006010 */  beqz       $3, .L0047AF40
    /* 37AF0C 0047AF0C 00000000 */   nop
    /* 37AF10 0047AF10 90006924 */  addiu      $9, $3, 0x90
    /* 37AF14 0047AF14 2D40C000 */  daddu      $8, $6, $0
    /* 37AF18 0047AF18 2D50A000 */  daddu      $10, $5, $0
  .L0047AF1C:
    /* 37AF1C 0047AF1C 0000478D */  lw         $7, 0x0($10)
    /* 37AF20 0047AF20 0400438D */  lw         $3, 0x4($10)
    /* 37AF24 0047AF24 08004A25 */  addiu      $10, $10, 0x8
    /* 37AF28 0047AF28 FFFF0825 */  addiu      $8, $8, -0x1
    /* 37AF2C 0047AF2C 000027AD */  sw         $7, 0x0($9)
    /* 37AF30 0047AF30 040023AD */  sw         $3, 0x4($9)
    /* 37AF34 0047AF34 08002925 */  addiu      $9, $9, 0x8
    /* 37AF38 0047AF38 F8FF001D */  bgtz       $8, .L0047AF1C
    /* 37AF3C 0047AF3C 00000000 */   nop
  .L0047AF40:
    /* 37AF40 0047AF40 01006325 */  addiu      $3, $11, 0x1
    /* 37AF44 0047AF44 FFFF6B30 */  andi       $11, $3, 0xFFFF
  .L0047AF48:
    /* 37AF48 0047AF48 FFFF6331 */  andi       $3, $11, 0xFFFF
    /* 37AF4C 0047AF4C 05006328 */  slti       $3, $3, 0x5
    /* 37AF50 0047AF50 E7FF6014 */  bnez       $3, .L0047AEF0
    /* 37AF54 0047AF54 00000000 */   nop
    /* 37AF58 0047AF58 0800E003 */  jr         $31
    /* 37AF5C 0047AF5C 00000000 */   nop
.size func_0047aee0, 0x80
