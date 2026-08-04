.section .text
.set noat
.set noreorder
glabel func_0016eaa0
    /* 6EAA0 0016EAA0 3800878C */  lw         $7, 0x38($4)
    /* 6EAA4 0016EAA4 3C2E0500 */  dsll32     $5, $5, 24
    /* 6EAA8 0016EAA8 3F2E0500 */  dsra32     $5, $5, 24
    /* 6EAAC 0016EAAC 01000424 */  addiu      $4, $0, 0x1
    /* 6EAB0 0016EAB0 2118A700 */  addu       $3, $5, $7
    /* 6EAB4 0016EAB4 E80064A0 */  sb         $4, 0xE8($3)
    /* 6EAB8 0016EAB8 40180500 */  sll        $3, $5, 1
    /* 6EABC 0016EABC 21186500 */  addu       $3, $3, $5
    /* 6EAC0 0016EAC0 80180300 */  sll        $3, $3, 2
    /* 6EAC4 0016EAC4 21186700 */  addu       $3, $3, $7
    /* 6EAC8 0016EAC8 0000C2C4 */  lwc1       $f2, 0x0($6)
    /* 6EACC 0016EACC 0400C1C4 */  lwc1       $f1, 0x4($6)
    /* 6EAD0 0016EAD0 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 6EAD4 0016EAD4 080162E4 */  swc1       $f2, 0x108($3)
    /* 6EAD8 0016EAD8 0C0161E4 */  swc1       $f1, 0x10C($3)
    /* 6EADC 0016EADC 100160E4 */  swc1       $f0, 0x110($3)
    /* 6EAE0 0016EAE0 0800E003 */  jr         $31
    /* 6EAE4 0016EAE4 00000000 */   nop
    /* 6EAE8 0016EAE8 00000000 */  nop
    /* 6EAEC 0016EAEC 00000000 */  nop
.size func_0016eaa0, 0x50
