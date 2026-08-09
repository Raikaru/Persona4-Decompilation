.section .text
.set noat
.set noreorder
glabel func_001d2fe0
    /* D2FE0 001D2FE0 0000848C */  lw         $4, 0x0($4)
    /* D2FE4 001D2FE4 A0008394 */  lhu        $3, 0xA0($4)
    /* D2FE8 001D2FE8 FFFF6324 */  addiu      $3, $3, -0x1
    /* D2FEC 001D2FEC A00083A4 */  sh         $3, 0xA0($4)
    /* D2FF0 001D2FF0 0800E003 */  jr         $31
    /* D2FF4 001D2FF4 00000000 */   nop
    /* D2FF8 001D2FF8 00000000 */  nop
    /* D2FFC 001D2FFC 00000000 */  nop
.size func_001d2fe0, 0x20
