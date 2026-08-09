.section .text
.set noat
.set noreorder
glabel func_0043fe48
    /* 33FE48 0043FE48 FFFF0F3C */  lui        $15, (0xFFFF0000 >> 16)
    /* 33FE4C 0043FE4C 24788F00 */  and        $15, $4, $15
    /* 33FE50 0043FE50 0300E015 */  bnez       $15, .L0043FE60
    /* 33FE54 0043FE54 2D700000 */   daddu     $14, $0, $0
    /* 33FE58 0043FE58 10000E24 */  addiu      $14, $0, 0x10
    /* 33FE5C 0043FE5C 00240400 */  sll        $4, $4, 16
  .L0043FE60:
    /* 33FE60 0043FE60 00FF0F3C */  lui        $15, (0xFF000000 >> 16)
    /* 33FE64 0043FE64 24788F00 */  and        $15, $4, $15
    /* 33FE68 0043FE68 0300E015 */  bnez       $15, .L0043FE78
    /* 33FE6C 0043FE6C 00F00F3C */   lui       $15, (0xF0000000 >> 16)
    /* 33FE70 0043FE70 0800CE25 */  addiu      $14, $14, 0x8
    /* 33FE74 0043FE74 00220400 */  sll        $4, $4, 8
  .L0043FE78:
    /* 33FE78 0043FE78 24788F00 */  and        $15, $4, $15
    /* 33FE7C 0043FE7C 0300E015 */  bnez       $15, .L0043FE8C
    /* 33FE80 0043FE80 00C00F3C */   lui       $15, (0xC0000000 >> 16)
    /* 33FE84 0043FE84 0400CE25 */  addiu      $14, $14, 0x4
    /* 33FE88 0043FE88 00210400 */  sll        $4, $4, 4
  .L0043FE8C:
    /* 33FE8C 0043FE8C 24788F00 */  and        $15, $4, $15
    /* 33FE90 0043FE90 0300E015 */  bnez       $15, .L0043FEA0
    /* 33FE94 0043FE94 00000000 */   nop
    /* 33FE98 0043FE98 0200CE25 */  addiu      $14, $14, 0x2
    /* 33FE9C 0043FE9C 80200400 */  sll        $4, $4, 2
  .L0043FEA0:
    /* 33FEA0 0043FEA0 05008004 */  bltz       $4, .L0043FEB8
    /* 33FEA4 0043FEA4 00400F3C */   lui       $15, (0x40000000 >> 16)
    /* 33FEA8 0043FEA8 0100CE25 */  addiu      $14, $14, 0x1
    /* 33FEAC 0043FEAC 24788F00 */  and        $15, $4, $15
    /* 33FEB0 0043FEB0 0200E011 */  beqz       $15, .L0043FEBC
    /* 33FEB4 0043FEB4 20000224 */   addiu     $2, $0, 0x20
  .L0043FEB8:
    /* 33FEB8 0043FEB8 2D10C001 */  daddu      $2, $14, $0
  .L0043FEBC:
    /* 33FEBC 0043FEBC 0800E003 */  jr         $31
    /* 33FEC0 0043FEC0 00000000 */   nop
    /* 33FEC4 0043FEC4 00000000 */  nop
.size func_0043fe48, 0x80
