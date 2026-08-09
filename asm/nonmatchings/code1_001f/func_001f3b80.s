.section .text
.set noat
.set noreorder
glabel func_001f3b80
    /* F3B80 001F3B80 ACB3828F */  lw         $2, -0x4C54($28)
    /* F3B84 001F3B84 540A428C */  lw         $2, 0xA54($2)
    /* F3B88 001F3B88 1001458C */  lw         $5, 0x110($2)
    /* F3B8C 001F3B8C FFFF8330 */  andi       $3, $4, 0xFFFF
    /* F3B90 001F3B90 40100300 */  sll        $2, $3, 1
    /* F3B94 001F3B94 21104300 */  addu       $2, $2, $3
    /* F3B98 001F3B98 80100200 */  sll        $2, $2, 2
    /* F3B9C 001F3B9C 21104500 */  addu       $2, $2, $5
    /* F3BA0 001F3BA0 0400428C */  lw         $2, 0x4($2)
    /* F3BA4 001F3BA4 2110A200 */  addu       $2, $5, $2
    /* F3BA8 001F3BA8 0800E003 */  jr         $31
    /* F3BAC 001F3BAC 00000000 */   nop
.size func_001f3b80, 0x30
