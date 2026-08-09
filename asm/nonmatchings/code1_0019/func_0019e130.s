.section .text
.set noat
.set noreorder
glabel func_0019e130
    /* 9E130 0019E130 0000848C */  lw         $4, 0x0($4)
    /* 9E134 0019E134 04008010 */  beqz       $4, .L0019E148
    /* 9E138 0019E138 00000000 */   nop
    /* 9E13C 0019E13C A0008394 */  lhu        $3, 0xA0($4)
    /* 9E140 0019E140 FFFF6324 */  addiu      $3, $3, -0x1
    /* 9E144 0019E144 A00083A4 */  sh         $3, 0xA0($4)
  .L0019E148:
    /* 9E148 0019E148 0800E003 */  jr         $31
    /* 9E14C 0019E14C 00000000 */   nop
.size func_0019e130, 0x20
