.section .text
.set noat
.set noreorder
glabel func_001f8280
    /* F8280 001F8280 0000838C */  lw         $3, 0x0($4)
    /* F8284 001F8284 9800628C */  lw         $2, 0x98($3)
    /* F8288 001F8288 02004230 */  andi       $2, $2, 0x2
    /* F828C 001F828C 04004010 */  beqz       $2, .L001F82A0
    /* F8290 001F8290 00000000 */   nop
    /* F8294 001F8294 D8096294 */  lhu        $2, 0x9D8($3)
    /* F8298 001F8298 EFFF4230 */  andi       $2, $2, 0xFFEF
    /* F829C 001F829C D80962A4 */  sh         $2, 0x9D8($3)
  .L001F82A0:
    /* F82A0 001F82A0 01000224 */  addiu      $2, $0, 0x1
    /* F82A4 001F82A4 0800E003 */  jr         $31
    /* F82A8 001F82A8 00000000 */   nop
    /* F82AC 001F82AC 00000000 */  nop
.size func_001f8280, 0x30
