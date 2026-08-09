.section .text
.set noat
.set noreorder
glabel func_004cb1d8
    /* 3CB1D8 004CB1D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB1DC 004CB1DC 08008014 */  bnez       $4, .L004CB200
    /* 3CB1E0 004CB1E0 0000BFFF */   sd        $31, 0x0($29)
    /* 3CB1E4 004CB1E4 7600043C */  lui        $4, %hi(D_00758880)
    /* 3CB1E8 004CB1E8 A61A130C */  jal        func_004c6a98
    /* 3CB1EC 004CB1EC 80888424 */   addiu     $4, $4, %lo(D_00758880)
    /* 3CB1F0 004CB1F0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3CB1F4 004CB1F4 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB1F8 004CB1F8 0800E003 */  jr         $31
    /* 3CB1FC 004CB1FC 1000BD27 */   addiu     $29, $29, 0x10
  .L004CB200:
    /* 3CB200 004CB200 9400848C */  lw         $4, 0x94($4)
    /* 3CB204 004CB204 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB208 004CB208 14A51308 */  j          func_004e9450
    /* 3CB20C 004CB20C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb1d8, 0x38
