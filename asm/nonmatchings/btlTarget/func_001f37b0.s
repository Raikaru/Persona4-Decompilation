.section .text
.set noat
.set noreorder
glabel func_001f37b0
    /* F37B0 001F37B0 0000838C */  lw         $3, 0x0($4)
    /* F37B4 001F37B4 3000648C */  lw         $4, 0x30($3)
    /* F37B8 001F37B8 A0008394 */  lhu        $3, 0xA0($4)
    /* F37BC 001F37BC 01006324 */  addiu      $3, $3, 0x1
    /* F37C0 001F37C0 A00083A4 */  sh         $3, 0xA0($4)
    /* F37C4 001F37C4 0800E003 */  jr         $31
    /* F37C8 001F37C8 00000000 */   nop
    /* F37CC 001F37CC 00000000 */  nop
.size func_001f37b0, 0x20
