.section .text
.set noat
.set noreorder
glabel func_001d2e00
    /* D2E00 001D2E00 0000848C */  lw         $4, 0x0($4)
    /* D2E04 001D2E04 A0008394 */  lhu        $3, 0xA0($4)
    /* D2E08 001D2E08 01006324 */  addiu      $3, $3, 0x1
    /* D2E0C 001D2E0C A00083A4 */  sh         $3, 0xA0($4)
    /* D2E10 001D2E10 0800E003 */  jr         $31
    /* D2E14 001D2E14 00000000 */   nop
    /* D2E18 001D2E18 00000000 */  nop
    /* D2E1C 001D2E1C 00000000 */  nop
.size func_001d2e00, 0x20
