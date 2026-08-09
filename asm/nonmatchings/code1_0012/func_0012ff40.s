.section .text
.set noat
.set noreorder
glabel func_0012ff40
    /* 2FF40 0012FF40 40100500 */  sll        $2, $5, 1
    /* 2FF44 0012FF44 21184400 */  addu       $3, $2, $4
    /* 2FF48 0012FF48 22006284 */  lh         $2, 0x22($3)
    /* 2FF4C 0012FF4C 280062A4 */  sh         $2, 0x28($3)
    /* 2FF50 0012FF50 220066A4 */  sh         $6, 0x22($3)
    /* 2FF54 0012FF54 01000224 */  addiu      $2, $0, 0x1
    /* 2FF58 0012FF58 0800E003 */  jr         $31
    /* 2FF5C 0012FF5C 00000000 */   nop
.size func_0012ff40, 0x20
