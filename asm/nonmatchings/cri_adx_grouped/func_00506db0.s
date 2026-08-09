.section .text
.set noat
.set noreorder
glabel func_00506db0
    /* 406DB0 00506DB0 9200033C */  lui        $3, %hi(D_009270C4)
    /* 406DB4 00506DB4 C470628C */  lw         $2, %lo(D_009270C4)($3)
    /* 406DB8 00506DB8 03004010 */  beqz       $2, .L00506DC8
    /* 406DBC 00506DBC 00000000 */   nop
    /* 406DC0 00506DC0 0002023C */  lui        $2, (0x2000000 >> 16)
    /* 406DC4 00506DC4 25208200 */  or         $4, $4, $2
  .L00506DC8:
    /* 406DC8 00506DC8 0800E003 */  jr         $31
    /* 406DCC 00506DCC 2D108000 */   daddu     $2, $4, $0
.size func_00506db0, 0x20
