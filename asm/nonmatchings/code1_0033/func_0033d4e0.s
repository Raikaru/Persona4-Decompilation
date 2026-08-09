.section .text
.set noat
.set noreorder
glabel func_0033d4e0
    /* 23D4E0 0033D4E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 23D4E4 0033D4E4 0000BFFF */  sd         $31, 0x0($29)
    /* 23D4E8 0033D4E8 3800828C */  lw         $2, 0x38($4)
    /* 23D4EC 0033D4EC 3C3C0700 */  dsll32     $7, $7, 16
    /* 23D4F0 0033D4F0 3F3C0700 */  dsra32     $7, $7, 16
    /* 23D4F4 0033D4F4 04004424 */  addiu      $4, $2, 0x4
    /* 23D4F8 0033D4F8 86630046 */  mov.s      $f14, $f12
    /* 23D4FC 0033D4FC C66B0046 */  mov.s      $f15, $f13
    /* 23D500 0033D500 C0E00A0C */  jal        func_002b8300
    /* 23D504 0033D504 00000000 */   nop
    /* 23D508 0033D508 0000BFDF */  ld         $31, 0x0($29)
    /* 23D50C 0033D50C 1000BD27 */  addiu      $29, $29, 0x10
    /* 23D510 0033D510 0800E003 */  jr         $31
    /* 23D514 0033D514 00000000 */   nop
    /* 23D518 0033D518 00000000 */  nop
    /* 23D51C 0033D51C 00000000 */  nop
.size func_0033d4e0, 0x40
