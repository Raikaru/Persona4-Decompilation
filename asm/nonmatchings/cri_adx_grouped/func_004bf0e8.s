.section .text
.set noat
.set noreorder
glabel func_004bf0e8
    /* 3BF0E8 004BF0E8 9400838C */  lw         $3, 0x94($4)
    /* 3BF0EC 004BF0EC 0F006010 */  beqz       $3, .L004BF12C
    /* 3BF0F0 004BF0F0 2D100000 */   daddu     $2, $0, $0
    /* 3BF0F4 004BF0F4 0500A004 */  bltz       $5, .L004BF10C
    /* 3BF0F8 004BF0F8 00000000 */   nop
    /* 3BF0FC 004BF0FC 8400828C */  lw         $2, 0x84($4)
    /* 3BF100 004BF100 2A10A200 */  slt        $2, $5, $2
    /* 3BF104 004BF104 04004054 */  bnel       $2, $0, .L004BF118
    /* 3BF108 004BF108 C000848C */   lw        $4, 0xC0($4)
  .L004BF10C:
    /* 3BF10C 004BF10C 0800E003 */  jr         $31
    /* 3BF110 004BF110 2D100000 */   daddu     $2, $0, $0
    /* 3BF114 004BF114 00000000 */  nop
  .L004BF118:
    /* 3BF118 004BF118 04008010 */  beqz       $4, .L004BF12C
    /* 3BF11C 004BF11C 2D100000 */   daddu     $2, $0, $0
    /* 3BF120 004BF120 80180500 */  sll        $3, $5, 2
    /* 3BF124 004BF124 21186400 */  addu       $3, $3, $4
    /* 3BF128 004BF128 0000628C */  lw         $2, 0x0($3)
  .L004BF12C:
    /* 3BF12C 004BF12C 0800E003 */  jr         $31
    /* 3BF130 004BF130 00000000 */   nop
    /* 3BF134 004BF134 00000000 */  nop
.size func_004bf0e8, 0x50
