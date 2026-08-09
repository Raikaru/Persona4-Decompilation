.section .text
.set noat
.set noreorder
glabel func_001227d0
    /* 227D0 001227D0 CCB1848F */  lw         $4, -0x4E34($28)
    /* 227D4 001227D4 03008010 */  beqz       $4, .L001227E4
    /* 227D8 001227D8 00000000 */   nop
    /* 227DC 001227DC 01000324 */  addiu      $3, $0, 0x1
    /* 227E0 001227E0 140083AC */  sw         $3, 0x14($4)
  .L001227E4:
    /* 227E4 001227E4 0800E003 */  jr         $31
    /* 227E8 001227E8 00000000 */   nop
    /* 227EC 001227EC 00000000 */  nop
.size func_001227d0, 0x20
