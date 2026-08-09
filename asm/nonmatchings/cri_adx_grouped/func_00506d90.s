.section .text
.set noat
.set noreorder
glabel func_00506d90
    /* 406D90 00506D90 9200033C */  lui        $3, %hi(D_009270C0)
    /* 406D94 00506D94 C070628C */  lw         $2, %lo(D_009270C0)($3)
    /* 406D98 00506D98 03004010 */  beqz       $2, .L00506DA8
    /* 406D9C 00506D9C 00000000 */   nop
    /* 406DA0 00506DA0 0002023C */  lui        $2, (0x2000000 >> 16)
    /* 406DA4 00506DA4 25208200 */  or         $4, $4, $2
  .L00506DA8:
    /* 406DA8 00506DA8 0800E003 */  jr         $31
    /* 406DAC 00506DAC 2D108000 */   daddu     $2, $4, $0
.size func_00506d90, 0x20
