.section .text
.set noat
.set noreorder
glabel func_0019df00
    /* 9DF00 0019DF00 0000848C */  lw         $4, 0x0($4)
    /* 9DF04 0019DF04 04008010 */  beqz       $4, .L0019DF18
    /* 9DF08 0019DF08 00000000 */   nop
    /* 9DF0C 0019DF0C A0008394 */  lhu        $3, 0xA0($4)
    /* 9DF10 0019DF10 01006324 */  addiu      $3, $3, 0x1
    /* 9DF14 0019DF14 A00083A4 */  sh         $3, 0xA0($4)
  .L0019DF18:
    /* 9DF18 0019DF18 0800E003 */  jr         $31
    /* 9DF1C 0019DF1C 00000000 */   nop
.size func_0019df00, 0x20
