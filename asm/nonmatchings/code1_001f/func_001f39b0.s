.section .text
.set noat
.set noreorder
glabel func_001f39b0
    /* F39B0 001F39B0 0000838C */  lw         $3, 0x0($4)
    /* F39B4 001F39B4 3000648C */  lw         $4, 0x30($3)
    /* F39B8 001F39B8 A0008394 */  lhu        $3, 0xA0($4)
    /* F39BC 001F39BC 01006324 */  addiu      $3, $3, 0x1
    /* F39C0 001F39C0 A00083A4 */  sh         $3, 0xA0($4)
    /* F39C4 001F39C4 0800E003 */  jr         $31
    /* F39C8 001F39C8 00000000 */   nop
    /* F39CC 001F39CC 00000000 */  nop
.size func_001f39b0, 0x20
