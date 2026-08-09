.section .text
.set noat
.set noreorder
glabel func_003d6e80
    /* 2D6E80 003D6E80 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2D6E84 003D6E84 49C0033C */  lui        $3, (0xC0490FDB >> 16)
    /* 2D6E88 003D6E88 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* 2D6E8C 003D6E8C DB0F6334 */  ori        $3, $3, (0xC0490FDB & 0xFFFF)
    /* 2D6E90 003D6E90 08008724 */  addiu      $7, $4, 0x8
    /* 2D6E94 003D6E94 0800C824 */  addiu      $8, $6, 0x8
    /* 2D6E98 003D6E98 00008344 */  mtc1       $3, $f0
    /* 2D6E9C 003D6E9C 00000000 */  nop
    /* 2D6EA0 003D6EA0 41080346 */  sub.s      $f1, $f1, $f3
    /* 2D6EA4 003D6EA4 34080046 */  c.lt.s     $f1, $f0
    /* 2D6EA8 003D6EA8 31000145 */  bc1t       .L003D6F70
    /* 2D6EAC 003D6EAC 0800A424 */   addiu     $4, $5, 0x8
    /* 2D6EB0 003D6EB0 4940033C */  lui        $3, (0x40490FDB >> 16)
    /* 2D6EB4 003D6EB4 DB0F6334 */  ori        $3, $3, (0x40490FDB & 0xFFFF)
    /* 2D6EB8 003D6EB8 00008344 */  mtc1       $3, $f0
    /* 2D6EBC 003D6EBC 00000000 */  nop
    /* 2D6EC0 003D6EC0 36080046 */  c.le.s     $f1, $f0
    /* 2D6EC4 003D6EC4 06000145 */  bc1t       .L003D6EE0
    /* 2D6EC8 003D6EC8 00000000 */   nop
    /* 2D6ECC 003D6ECC C940033C */  lui        $3, (0x40C90FDB >> 16)
    /* 2D6ED0 003D6ED0 DB0F6334 */  ori        $3, $3, (0x40C90FDB & 0xFFFF)
    /* 2D6ED4 003D6ED4 00008344 */  mtc1       $3, $f0
    /* 2D6ED8 003D6ED8 00000000 */  nop
    /* 2D6EDC 003D6EDC 41080046 */  sub.s      $f1, $f1, $f0
  .L003D6EE0:
    /* 2D6EE0 003D6EE0 00108044 */  mtc1       $0, $f2
    /* 2D6EE4 003D6EE4 00000000 */  nop
    /* 2D6EE8 003D6EE8 18100346 */  adda.s     $f2, $f3
    /* 2D6EEC 003D6EEC 1C600146 */  madd.s     $f0, $f12, $f1
    /* 2D6EF0 003D6EF0 0000E0E4 */  swc1       $f0, 0x0($7)
    /* 2D6EF4 003D6EF4 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2D6EF8 003D6EF8 040000C5 */  lwc1       $f0, 0x4($8)
    /* 2D6EFC 003D6EFC 18100146 */  adda.s     $f2, $f1
    /* 2D6F00 003D6F00 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6F04 003D6F04 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6F08 003D6F08 0400E0E4 */  swc1       $f0, 0x4($7)
    /* 2D6F0C 003D6F0C 080081C4 */  lwc1       $f1, 0x8($4)
    /* 2D6F10 003D6F10 080000C5 */  lwc1       $f0, 0x8($8)
    /* 2D6F14 003D6F14 18100146 */  adda.s     $f2, $f1
    /* 2D6F18 003D6F18 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6F1C 003D6F1C 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6F20 003D6F20 0800E0E4 */  swc1       $f0, 0x8($7)
    /* 2D6F24 003D6F24 0C0081C4 */  lwc1       $f1, 0xC($4)
    /* 2D6F28 003D6F28 0C0000C5 */  lwc1       $f0, 0xC($8)
    /* 2D6F2C 003D6F2C 18100146 */  adda.s     $f2, $f1
    /* 2D6F30 003D6F30 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6F34 003D6F34 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6F38 003D6F38 0C00E0E4 */  swc1       $f0, 0xC($7)
    /* 2D6F3C 003D6F3C 100081C4 */  lwc1       $f1, 0x10($4)
    /* 2D6F40 003D6F40 100000C5 */  lwc1       $f0, 0x10($8)
    /* 2D6F44 003D6F44 18100146 */  adda.s     $f2, $f1
    /* 2D6F48 003D6F48 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6F4C 003D6F4C 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6F50 003D6F50 1000E0E4 */  swc1       $f0, 0x10($7)
    /* 2D6F54 003D6F54 140081C4 */  lwc1       $f1, 0x14($4)
    /* 2D6F58 003D6F58 140000C5 */  lwc1       $f0, 0x14($8)
    /* 2D6F5C 003D6F5C 18100146 */  adda.s     $f2, $f1
    /* 2D6F60 003D6F60 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6F64 003D6F64 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6F68 003D6F68 06000010 */  b          .L003D6F84
    /* 2D6F6C 003D6F6C 1400E0E4 */   swc1      $f0, 0x14($7)
  .L003D6F70:
    /* 2D6F70 003D6F70 C940033C */  lui        $3, (0x40C90FDB >> 16)
    /* 2D6F74 003D6F74 DB0F6334 */  ori        $3, $3, (0x40C90FDB & 0xFFFF)
    /* 2D6F78 003D6F78 00008344 */  mtc1       $3, $f0
    /* 2D6F7C 003D6F7C D8FF0010 */  b          .L003D6EE0
    /* 2D6F80 003D6F80 40080046 */   add.s     $f1, $f1, $f0
  .L003D6F84:
    /* 2D6F84 003D6F84 0800E003 */  jr         $31
    /* 2D6F88 003D6F88 00000000 */   nop
    /* 2D6F8C 003D6F8C 00000000 */  nop
.size func_003d6e80, 0x110
