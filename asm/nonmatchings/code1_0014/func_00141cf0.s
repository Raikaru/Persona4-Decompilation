.section .text
.set noat
.set noreorder
glabel func_00141cf0
    /* 41CF0 00141CF0 40100500 */  sll        $2, $5, 1
    /* 41CF4 00141CF4 21184400 */  addu       $3, $2, $4
    /* 41CF8 00141CF8 34006284 */  lh         $2, 0x34($3)
    /* 41CFC 00141CFC 360062A4 */  sh         $2, 0x36($3)
    /* 41D00 00141D00 340066A4 */  sh         $6, 0x34($3)
    /* 41D04 00141D04 01000224 */  addiu      $2, $0, 0x1
    /* 41D08 00141D08 0800E003 */  jr         $31
    /* 41D0C 00141D0C 00000000 */   nop
.size func_00141cf0, 0x20
