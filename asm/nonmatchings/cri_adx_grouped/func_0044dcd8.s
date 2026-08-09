.section .text
.set noat
.set noreorder
glabel func_0044dcd8
    /* 34DCD8 0044DCD8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 34DCDC 0044DCDC 2000BFFF */  sd         $31, 0x20($29)
    /* 34DCE0 0044DCE0 1000A427 */  addiu      $4, $29, 0x10
    /* 34DCE4 0044DCE4 1000ACE7 */  swc1       $f12, 0x10($29)
    /* 34DCE8 0044DCE8 1437110C */  jal        func_0044dc50
    /* 34DCEC 0044DCEC 2D28A003 */   daddu     $5, $29, $0
    /* 34DCF0 0044DCF0 0C00A79F */  lwu        $7, 0xC($29)
    /* 34DCF4 0044DCF4 0000A48F */  lw         $4, 0x0($29)
    /* 34DCF8 0044DCF8 0400A58F */  lw         $5, 0x4($29)
    /* 34DCFC 0044DCFC B83F0700 */  dsll       $7, $7, 30
    /* 34DD00 0044DD00 EA39110C */  jal        func_0044e7a8
    /* 34DD04 0044DD04 0800A68F */   lw        $6, 0x8($29)
    /* 34DD08 0044DD08 2000BFDF */  ld         $31, 0x20($29)
    /* 34DD0C 0044DD0C 0800E003 */  jr         $31
    /* 34DD10 0044DD10 3000BD27 */   addiu     $29, $29, 0x30
    /* 34DD14 0044DD14 00000000 */  nop
.size func_0044dcd8, 0x40
