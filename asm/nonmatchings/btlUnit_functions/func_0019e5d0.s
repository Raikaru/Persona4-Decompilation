.section .text
.set noat
.set noreorder
glabel func_0019e5d0
    /* 9E5D0 0019E5D0 0000848C */  lw         $4, 0x0($4)
    /* 9E5D4 0019E5D4 04008010 */  beqz       $4, .L0019E5E8
    /* 9E5D8 0019E5D8 00000000 */   nop
    /* 9E5DC 0019E5DC A0008394 */  lhu        $3, 0xA0($4)
    /* 9E5E0 0019E5E0 01006324 */  addiu      $3, $3, 0x1
    /* 9E5E4 0019E5E4 A00083A4 */  sh         $3, 0xA0($4)
  .L0019E5E8:
    /* 9E5E8 0019E5E8 0800E003 */  jr         $31
    /* 9E5EC 0019E5EC 00000000 */   nop
.size func_0019e5d0, 0x20
