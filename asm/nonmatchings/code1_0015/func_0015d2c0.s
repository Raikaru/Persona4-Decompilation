.section .text
.set noat
.set noreorder
glabel func_0015d2c0
    /* 5D2C0 0015D2C0 94B2828F */  lw         $2, -0x4D6C($28)
    /* 5D2C4 0015D2C4 2D380000 */  daddu      $7, $0, $0
    /* 5D2C8 0015D2C8 2D400000 */  daddu      $8, $0, $0
    /* 5D2CC 0015D2CC 9CB2868F */  lw         $6, -0x4D64($28)
    /* 5D2D0 0015D2D0 FFFF0534 */  ori        $5, $0, 0xFFFF
    /* 5D2D4 0015D2D4 09000010 */  b          .L0015D2FC
    /* 5D2D8 0015D2D8 00000000 */   nop
  .L0015D2DC:
    /* 5D2DC 0015D2DC 0A00E410 */  beq        $7, $4, .L0015D308
    /* 5D2E0 0015D2E0 00000000 */   nop
    /* 5D2E4 0015D2E4 00004394 */  lhu        $3, 0x0($2)
    /* 5D2E8 0015D2E8 02006514 */  bne        $3, $5, .L0015D2F4
    /* 5D2EC 0015D2EC 00000000 */   nop
    /* 5D2F0 0015D2F0 0100E724 */  addiu      $7, $7, 0x1
  .L0015D2F4:
    /* 5D2F4 0015D2F4 01000825 */  addiu      $8, $8, 0x1
    /* 5D2F8 0015D2F8 84004224 */  addiu      $2, $2, 0x84
  .L0015D2FC:
    /* 5D2FC 0015D2FC 2B180601 */  sltu       $3, $8, $6
    /* 5D300 0015D300 F6FF6014 */  bnez       $3, .L0015D2DC
    /* 5D304 0015D304 00000000 */   nop
  .L0015D308:
    /* 5D308 0015D308 0800E003 */  jr         $31
    /* 5D30C 0015D30C 00000000 */   nop
.size func_0015d2c0, 0x50
