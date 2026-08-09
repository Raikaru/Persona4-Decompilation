.section .text
.set noat
.set noreorder
glabel func_0047ea40
    /* 37EA40 0047EA40 0000A58C */  lw         $5, 0x0($5)
    /* 37EA44 0047EA44 0500A010 */  beqz       $5, .L0047EA5C
    /* 37EA48 0047EA48 00000000 */   nop
    /* 37EA4C 0047EA4C 0800A38C */  lw         $3, 0x8($5)
    /* 37EA50 0047EA50 01006324 */  addiu      $3, $3, 0x1
    /* 37EA54 0047EA54 0800A3AC */  sw         $3, 0x8($5)
    /* 37EA58 0047EA58 000085AC */  sw         $5, 0x0($4)
  .L0047EA5C:
    /* 37EA5C 0047EA5C 0800E003 */  jr         $31
    /* 37EA60 0047EA60 00000000 */   nop
    /* 37EA64 0047EA64 00000000 */  nop
    /* 37EA68 0047EA68 00000000 */  nop
    /* 37EA6C 0047EA6C 00000000 */  nop
.size func_0047ea40, 0x30
