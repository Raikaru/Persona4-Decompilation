.section .text
.set noat
.set noreorder
glabel func_004df1f0
    /* 3DF1F0 004DF1F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF1F4 004DF1F4 06008014 */  bnez       $4, .L004DF210
    /* 3DF1F8 004DF1F8 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF1FC 004DF1FC 7600043C */  lui        $4, %hi(D_007599B0)
    /* 3DF200 004DF200 B078130C */  jal        func_004de2c0
    /* 3DF204 004DF204 B0998424 */   addiu     $4, $4, %lo(D_007599B0)
    /* 3DF208 004DF208 02000010 */  b          .L004DF214
    /* 3DF20C 004DF20C 2D100000 */   daddu     $2, $0, $0
  .L004DF210:
    /* 3DF210 004DF210 9000828C */  lw         $2, 0x90($4)
  .L004DF214:
    /* 3DF214 004DF214 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF218 004DF218 0800E003 */  jr         $31
    /* 3DF21C 004DF21C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df1f0, 0x30
