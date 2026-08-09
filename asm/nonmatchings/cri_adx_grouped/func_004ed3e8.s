.section .text
.set noat
.set noreorder
glabel func_004ed3e8
    /* 3ED3E8 004ED3E8 7400033C */  lui        $3, %hi(D_0073DAC8)
    /* 3ED3EC 004ED3EC 01000524 */  addiu      $5, $0, 0x1
    /* 3ED3F0 004ED3F0 C8DA6324 */  addiu      $3, $3, %lo(D_0073DAC8)
    /* 3ED3F4 004ED3F4 0000628C */  lw         $2, 0x0($3)
    /* 3ED3F8 004ED3F8 01004224 */  addiu      $2, $2, 0x1
    /* 3ED3FC 004ED3FC 000062AC */  sw         $2, 0x0($3)
    /* 3ED400 004ED400 0000648C */  lw         $4, 0x0($3)
    /* 3ED404 004ED404 03008514 */  bne        $4, $5, .L004ED414
    /* 3ED408 004ED408 7400023C */   lui       $2, %hi(D_0073DAC0)
    /* 3ED40C 004ED40C C0DA4224 */  addiu      $2, $2, %lo(D_0073DAC0)
    /* 3ED410 004ED410 000040AC */  sw         $0, 0x0($2)
  .L004ED414:
    /* 3ED414 004ED414 0800E003 */  jr         $31
    /* 3ED418 004ED418 00000000 */   nop
    /* 3ED41C 004ED41C 00000000 */  nop
.size func_004ed3e8, 0x38
