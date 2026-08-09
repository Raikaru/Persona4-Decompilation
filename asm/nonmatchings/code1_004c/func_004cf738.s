.section .text
.set noat
.set noreorder
glabel func_004cf738
    /* 3CF738 004CF738 7200033C */  lui        $3, %hi(D_00723548)
    /* 3CF73C 004CF73C 48356324 */  addiu      $3, $3, %lo(D_00723548)
    /* 3CF740 004CF740 00006280 */  lb         $2, 0x0($3)
    /* 3CF744 004CF744 10004010 */  beqz       $2, .L004CF788
    /* 3CF748 004CF748 2D380000 */   daddu     $7, $0, $0
    /* 3CF74C 004CF74C 2D306000 */  daddu      $6, $3, $0
    /* 3CF750 004CF750 2D286000 */  daddu      $5, $3, $0
    /* 3CF754 004CF754 00000000 */  nop
  .L004CF758:
    /* 3CF758 004CF758 0100E724 */  addiu      $7, $7, 0x1
    /* 3CF75C 004CF75C 0C00C624 */  addiu      $6, $6, 0xC
    /* 3CF760 004CF760 1000E428 */  slti       $4, $7, 0x10
    /* 3CF764 004CF764 09008010 */  beqz       $4, .L004CF78C
    /* 3CF768 004CF768 0C00A524 */   addiu     $5, $5, 0xC
    /* 3CF76C 004CF76C 0000C280 */  lb         $2, 0x0($6)
    /* 3CF770 004CF770 00000000 */  nop
    /* 3CF774 004CF774 F8FF4014 */  bnez       $2, .L004CF758
    /* 3CF778 004CF778 2D18A000 */   daddu     $3, $5, $0
    /* 3CF77C 004CF77C 04000010 */  b          .L004CF790
    /* 3CF780 004CF780 2D100000 */   daddu     $2, $0, $0
    /* 3CF784 004CF784 00000000 */  nop
  .L004CF788:
    /* 3CF788 004CF788 01000424 */  addiu      $4, $0, 0x1
  .L004CF78C:
    /* 3CF78C 004CF78C 2D100000 */  daddu      $2, $0, $0
  .L004CF790:
    /* 3CF790 004CF790 0800E003 */  jr         $31
    /* 3CF794 004CF794 0B106400 */   movn      $2, $3, $4
.size func_004cf738, 0x60
