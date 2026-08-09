.section .text
.set noat
.set noreorder
glabel func_003d6d50
    /* 2D6D50 003D6D50 0400A4C4 */  lwc1       $f4, 0x4($5)
    /* 2D6D54 003D6D54 49C0033C */  lui        $3, (0xC0490FDB >> 16)
    /* 2D6D58 003D6D58 0400C3C4 */  lwc1       $f3, 0x4($6)
    /* 2D6D5C 003D6D5C 08008824 */  addiu      $8, $4, 0x8
    /* 2D6D60 003D6D60 DB0F6334 */  ori        $3, $3, (0xC0490FDB & 0xFFFF)
    /* 2D6D64 003D6D64 0800A724 */  addiu      $7, $5, 0x8
    /* 2D6D68 003D6D68 0800A5C4 */  lwc1       $f5, 0x8($5)
    /* 2D6D6C 003D6D6C 0800C424 */  addiu      $4, $6, 0x8
    /* 2D6D70 003D6D70 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* 2D6D74 003D6D74 00008344 */  mtc1       $3, $f0
    /* 2D6D78 003D6D78 81600446 */  sub.s      $f2, $f12, $f4
    /* 2D6D7C 003D6D7C C1180446 */  sub.s      $f3, $f3, $f4
    /* 2D6D80 003D6D80 C3100346 */  div.s      $f3, $f2, $f3
    /* 2D6D84 003D6D84 00000000 */  nop
    /* 2D6D88 003D6D88 41080546 */  sub.s      $f1, $f1, $f5
    /* 2D6D8C 003D6D8C 34080046 */  c.lt.s     $f1, $f0
    /* 2D6D90 003D6D90 31000145 */  bc1t       .L003D6E58
    /* 2D6D94 003D6D94 00000000 */   nop
    /* 2D6D98 003D6D98 4940033C */  lui        $3, (0x40490FDB >> 16)
    /* 2D6D9C 003D6D9C DB0F6334 */  ori        $3, $3, (0x40490FDB & 0xFFFF)
    /* 2D6DA0 003D6DA0 00008344 */  mtc1       $3, $f0
    /* 2D6DA4 003D6DA4 00000000 */  nop
    /* 2D6DA8 003D6DA8 36080046 */  c.le.s     $f1, $f0
    /* 2D6DAC 003D6DAC 06000145 */  bc1t       .L003D6DC8
    /* 2D6DB0 003D6DB0 00000000 */   nop
    /* 2D6DB4 003D6DB4 C940033C */  lui        $3, (0x40C90FDB >> 16)
    /* 2D6DB8 003D6DB8 DB0F6334 */  ori        $3, $3, (0x40C90FDB & 0xFFFF)
    /* 2D6DBC 003D6DBC 00008344 */  mtc1       $3, $f0
    /* 2D6DC0 003D6DC0 00000000 */  nop
    /* 2D6DC4 003D6DC4 41080046 */  sub.s      $f1, $f1, $f0
  .L003D6DC8:
    /* 2D6DC8 003D6DC8 00108044 */  mtc1       $0, $f2
    /* 2D6DCC 003D6DCC 00000000 */  nop
    /* 2D6DD0 003D6DD0 18100546 */  adda.s     $f2, $f5
    /* 2D6DD4 003D6DD4 1C180146 */  madd.s     $f0, $f3, $f1
    /* 2D6DD8 003D6DD8 000000E5 */  swc1       $f0, 0x0($8)
    /* 2D6DDC 003D6DDC 0400E1C4 */  lwc1       $f1, 0x4($7)
    /* 2D6DE0 003D6DE0 040080C4 */  lwc1       $f0, 0x4($4)
    /* 2D6DE4 003D6DE4 18100146 */  adda.s     $f2, $f1
    /* 2D6DE8 003D6DE8 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6DEC 003D6DEC 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2D6DF0 003D6DF0 040000E5 */  swc1       $f0, 0x4($8)
    /* 2D6DF4 003D6DF4 0800E1C4 */  lwc1       $f1, 0x8($7)
    /* 2D6DF8 003D6DF8 080080C4 */  lwc1       $f0, 0x8($4)
    /* 2D6DFC 003D6DFC 18100146 */  adda.s     $f2, $f1
    /* 2D6E00 003D6E00 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6E04 003D6E04 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2D6E08 003D6E08 080000E5 */  swc1       $f0, 0x8($8)
    /* 2D6E0C 003D6E0C 0C00E1C4 */  lwc1       $f1, 0xC($7)
    /* 2D6E10 003D6E10 0C0080C4 */  lwc1       $f0, 0xC($4)
    /* 2D6E14 003D6E14 18100146 */  adda.s     $f2, $f1
    /* 2D6E18 003D6E18 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6E1C 003D6E1C 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2D6E20 003D6E20 0C0000E5 */  swc1       $f0, 0xC($8)
    /* 2D6E24 003D6E24 1000E1C4 */  lwc1       $f1, 0x10($7)
    /* 2D6E28 003D6E28 100080C4 */  lwc1       $f0, 0x10($4)
    /* 2D6E2C 003D6E2C 18100146 */  adda.s     $f2, $f1
    /* 2D6E30 003D6E30 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6E34 003D6E34 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2D6E38 003D6E38 100000E5 */  swc1       $f0, 0x10($8)
    /* 2D6E3C 003D6E3C 1400E1C4 */  lwc1       $f1, 0x14($7)
    /* 2D6E40 003D6E40 140080C4 */  lwc1       $f0, 0x14($4)
    /* 2D6E44 003D6E44 18100146 */  adda.s     $f2, $f1
    /* 2D6E48 003D6E48 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6E4C 003D6E4C 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2D6E50 003D6E50 06000010 */  b          .L003D6E6C
    /* 2D6E54 003D6E54 140000E5 */   swc1      $f0, 0x14($8)
  .L003D6E58:
    /* 2D6E58 003D6E58 C940033C */  lui        $3, (0x40C90FDB >> 16)
    /* 2D6E5C 003D6E5C DB0F6334 */  ori        $3, $3, (0x40C90FDB & 0xFFFF)
    /* 2D6E60 003D6E60 00008344 */  mtc1       $3, $f0
    /* 2D6E64 003D6E64 D8FF0010 */  b          .L003D6DC8
    /* 2D6E68 003D6E68 40080046 */   add.s     $f1, $f1, $f0
  .L003D6E6C:
    /* 2D6E6C 003D6E6C 0800E003 */  jr         $31
    /* 2D6E70 003D6E70 00000000 */   nop
    /* 2D6E74 003D6E74 00000000 */  nop
    /* 2D6E78 003D6E78 00000000 */  nop
    /* 2D6E7C 003D6E7C 00000000 */  nop
.size func_003d6d50, 0x130
