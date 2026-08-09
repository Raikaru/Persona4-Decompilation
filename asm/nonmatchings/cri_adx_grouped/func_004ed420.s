.section .text
.set noat
.set noreorder
glabel func_004ed420
    /* 3ED420 004ED420 7400023C */  lui        $2, %hi(D_0073DAC8)
    /* 3ED424 004ED424 C8DA4224 */  addiu      $2, $2, %lo(D_0073DAC8)
    /* 3ED428 004ED428 0000438C */  lw         $3, 0x0($2)
    /* 3ED42C 004ED42C FFFF6324 */  addiu      $3, $3, -0x1
    /* 3ED430 004ED430 000043AC */  sw         $3, 0x0($2)
    /* 3ED434 004ED434 0000448C */  lw         $4, 0x0($2)
    /* 3ED438 004ED438 03008014 */  bnez       $4, .L004ED448
    /* 3ED43C 004ED43C 7400023C */   lui       $2, %hi(D_0073DAC0)
    /* 3ED440 004ED440 C0DA4224 */  addiu      $2, $2, %lo(D_0073DAC0)
    /* 3ED444 004ED444 000040AC */  sw         $0, 0x0($2)
  .L004ED448:
    /* 3ED448 004ED448 0800E003 */  jr         $31
    /* 3ED44C 004ED44C 00000000 */   nop
.size func_004ed420, 0x30
