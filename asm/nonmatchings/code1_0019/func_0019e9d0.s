.section .text
.set noat
.set noreorder
glabel func_0019e9d0
    /* 9E9D0 0019E9D0 0000848C */  lw         $4, 0x0($4)
    /* 9E9D4 0019E9D4 04008010 */  beqz       $4, .L0019E9E8
    /* 9E9D8 0019E9D8 00000000 */   nop
    /* 9E9DC 0019E9DC A0008394 */  lhu        $3, 0xA0($4)
    /* 9E9E0 0019E9E0 FFFF6324 */  addiu      $3, $3, -0x1
    /* 9E9E4 0019E9E4 A00083A4 */  sh         $3, 0xA0($4)
  .L0019E9E8:
    /* 9E9E8 0019E9E8 0800E003 */  jr         $31
    /* 9E9EC 0019E9EC 00000000 */   nop
.size func_0019e9d0, 0x20
