.section .text
.set noat
.set noreorder
glabel func_001f38e0
    /* F38E0 001F38E0 0000838C */  lw         $3, 0x0($4)
    /* F38E4 001F38E4 3000648C */  lw         $4, 0x30($3)
    /* F38E8 001F38E8 A0008394 */  lhu        $3, 0xA0($4)
    /* F38EC 001F38EC 01006324 */  addiu      $3, $3, 0x1
    /* F38F0 001F38F0 A00083A4 */  sh         $3, 0xA0($4)
    /* F38F4 001F38F4 0800E003 */  jr         $31
    /* F38F8 001F38F8 00000000 */   nop
    /* F38FC 001F38FC 00000000 */  nop
.size func_001f38e0, 0x20
