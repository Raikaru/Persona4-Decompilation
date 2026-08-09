.section .text
.set noat
.set noreorder
glabel func_0013ff80
    /* 3FF80 0013FF80 1400838C */  lw         $3, 0x14($4)
    /* 3FF84 0013FF84 01000224 */  addiu      $2, $0, 0x1
    /* 3FF88 0013FF88 09006210 */  beq        $3, $2, .L0013FFB0
    /* 3FF8C 0013FF8C 00000000 */   nop
    /* 3FF90 0013FF90 03006010 */  beqz       $3, .L0013FFA0
    /* 3FF94 0013FF94 00000000 */   nop
    /* 3FF98 0013FF98 07000010 */  b          .L0013FFB8
    /* 3FF9C 0013FF9C 00000000 */   nop
  .L0013FFA0:
    /* 3FFA0 0013FFA0 01006324 */  addiu      $3, $3, 0x1
    /* 3FFA4 0013FFA4 140083AC */  sw         $3, 0x14($4)
    /* 3FFA8 0013FFA8 04000010 */  b          .L0013FFBC
    /* 3FFAC 0013FFAC 00000000 */   nop
  .L0013FFB0:
    /* 3FFB0 0013FFB0 02000010 */  b          .L0013FFBC
    /* 3FFB4 0013FFB4 00000000 */   nop
  .L0013FFB8:
    /* 3FFB8 0013FFB8 2D100000 */  daddu      $2, $0, $0
  .L0013FFBC:
    /* 3FFBC 0013FFBC 0800E003 */  jr         $31
    /* 3FFC0 0013FFC0 00000000 */   nop
    /* 3FFC4 0013FFC4 00000000 */  nop
    /* 3FFC8 0013FFC8 00000000 */  nop
    /* 3FFCC 0013FFCC 00000000 */  nop
.size func_0013ff80, 0x50
