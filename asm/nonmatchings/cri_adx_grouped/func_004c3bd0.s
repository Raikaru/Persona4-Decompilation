.section .text
.set noat
.set noreorder
glabel func_004c3bd0
    /* 3C3BD0 004C3BD0 0E008280 */  lb         $2, 0xE($4)
    /* 3C3BD4 004C3BD4 01000324 */  addiu      $3, $0, 0x1
    /* 3C3BD8 004C3BD8 04004314 */  bne        $2, $3, .L004C3BEC
    /* 3C3BDC 004C3BDC 0E008590 */   lbu       $5, 0xE($4)
    /* 3C3BE0 004C3BE0 E800838C */  lw         $3, 0xE8($4)
    /* 3C3BE4 004C3BE4 03006014 */  bnez       $3, .L004C3BF4
    /* 3C3BE8 004C3BE8 02000224 */   addiu     $2, $0, 0x2
  .L004C3BEC:
    /* 3C3BEC 004C3BEC 00160500 */  sll        $2, $5, 24
    /* 3C3BF0 004C3BF0 03160200 */  sra        $2, $2, 24
  .L004C3BF4:
    /* 3C3BF4 004C3BF4 0800E003 */  jr         $31
    /* 3C3BF8 004C3BF8 00000000 */   nop
    /* 3C3BFC 004C3BFC 00000000 */  nop
.size func_004c3bd0, 0x30
