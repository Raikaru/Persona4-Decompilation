.section .text
.set noat
.set noreorder
glabel func_0019e7a0
    /* 9E7A0 0019E7A0 0000848C */  lw         $4, 0x0($4)
    /* 9E7A4 0019E7A4 04008010 */  beqz       $4, .L0019E7B8
    /* 9E7A8 0019E7A8 00000000 */   nop
    /* 9E7AC 0019E7AC A0008394 */  lhu        $3, 0xA0($4)
    /* 9E7B0 0019E7B0 FFFF6324 */  addiu      $3, $3, -0x1
    /* 9E7B4 0019E7B4 A00083A4 */  sh         $3, 0xA0($4)
  .L0019E7B8:
    /* 9E7B8 0019E7B8 0800E003 */  jr         $31
    /* 9E7BC 0019E7BC 00000000 */   nop
.size func_0019e7a0, 0x20
