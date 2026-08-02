.section .text
.set noat
.set noreorder
glabel func_00136fa0
    /* 36FA0 00136FA0 40100500 */  sll        $2, $5, 1
    /* 36FA4 00136FA4 21184400 */  addu       $3, $2, $4
    /* 36FA8 00136FA8 50006284 */  lh         $2, 0x50($3)
    /* 36FAC 00136FAC 580062A4 */  sh         $2, 0x58($3)
    /* 36FB0 00136FB0 500066A4 */  sh         $6, 0x50($3)
    /* 36FB4 00136FB4 01000224 */  addiu      $2, $0, 0x1
    /* 36FB8 00136FB8 0800E003 */  jr         $31
    /* 36FBC 00136FBC 00000000 */   nop
.size func_00136fa0, 0x20
