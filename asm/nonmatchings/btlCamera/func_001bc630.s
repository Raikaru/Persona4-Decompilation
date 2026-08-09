.section .text
.set noat
.set noreorder
glabel func_001bc630
    /* BC630 001BC630 E000828C */  lw         $2, 0xE0($4)
    /* BC634 001BC634 6E004294 */  lhu        $2, 0x6E($2)
    /* BC638 001BC638 80180200 */  sll        $3, $2, 2
    /* BC63C 001BC63C BCB3828F */  lw         $2, -0x4C44($28)
    /* BC640 001BC640 21106200 */  addu       $2, $3, $2
    /* BC644 001BC644 02004294 */  lhu        $2, 0x2($2)
    /* BC648 001BC648 00404230 */  andi       $2, $2, 0x4000
    /* BC64C 001BC64C 2B100200 */  sltu       $2, $0, $2
    /* BC650 001BC650 0800E003 */  jr         $31
    /* BC654 001BC654 00000000 */   nop
    /* BC658 001BC658 00000000 */  nop
    /* BC65C 001BC65C 00000000 */  nop
.size func_001bc630, 0x30
