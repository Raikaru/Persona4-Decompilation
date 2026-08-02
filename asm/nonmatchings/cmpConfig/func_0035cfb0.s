.section .text
.set noat
.set noreorder
glabel func_0035cfb0
    /* 25CFB0 0035CFB0 1800838C */  lw         $3, 0x18($4)
    /* 25CFB4 0035CFB4 01000224 */  addiu      $2, $0, 0x1
    /* 25CFB8 0035CFB8 09006210 */  beq        $3, $2, .L0035CFE0
    /* 25CFBC 0035CFBC 00000000 */   nop
    /* 25CFC0 0035CFC0 03006010 */  beqz       $3, .L0035CFD0
    /* 25CFC4 0035CFC4 00000000 */   nop
    /* 25CFC8 0035CFC8 07000010 */  b          .L0035CFE8
    /* 25CFCC 0035CFCC 00000000 */   nop
  .L0035CFD0:
    /* 25CFD0 0035CFD0 01006324 */  addiu      $3, $3, 0x1
    /* 25CFD4 0035CFD4 180083AC */  sw         $3, 0x18($4)
    /* 25CFD8 0035CFD8 04000010 */  b          .L0035CFEC
    /* 25CFDC 0035CFDC 00000000 */   nop
  .L0035CFE0:
    /* 25CFE0 0035CFE0 02000010 */  b          .L0035CFEC
    /* 25CFE4 0035CFE4 00000000 */   nop
  .L0035CFE8:
    /* 25CFE8 0035CFE8 2D100000 */  daddu      $2, $0, $0
  .L0035CFEC:
    /* 25CFEC 0035CFEC 0800E003 */  jr         $31
    /* 25CFF0 0035CFF0 00000000 */   nop
    /* 25CFF4 0035CFF4 00000000 */  nop
    /* 25CFF8 0035CFF8 00000000 */  nop
    /* 25CFFC 0035CFFC 00000000 */  nop
.size func_0035cfb0, 0x50
