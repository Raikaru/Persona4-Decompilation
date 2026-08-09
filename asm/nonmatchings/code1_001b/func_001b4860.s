.section .text
.set noat
.set noreorder
glabel func_001b4860
    /* B4860 001B4860 0000828C */  lw         $2, 0x0($4)
    /* B4864 001B4864 0B004238 */  xori       $2, $2, 0xB
    /* B4868 001B4868 2B100200 */  sltu       $2, $0, $2
    /* B486C 001B486C 0800E003 */  jr         $31
    /* B4870 001B4870 00000000 */   nop
    /* B4874 001B4874 00000000 */  nop
    /* B4878 001B4878 00000000 */  nop
    /* B487C 001B487C 00000000 */  nop
.size func_001b4860, 0x20
