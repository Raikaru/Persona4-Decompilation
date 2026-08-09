.section .text
.set noat
.set noreorder
glabel func_00520da0
    /* 420DA0 00520DA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 420DA4 00520DA4 9400053C */  lui        $5, %hi(D_00938930)
    /* 420DA8 00520DA8 0000BFFF */  sd         $31, 0x0($29)
    /* 420DAC 00520DAC 3089A524 */  addiu      $5, $5, %lo(D_00938930)
    /* 420DB0 00520DB0 48000624 */  addiu      $6, $0, 0x48
    /* 420DB4 00520DB4 C01F848C */  lw         $4, 0x1FC0($4)
    /* 420DB8 00520DB8 0000BFDF */  ld         $31, 0x0($29)
    /* 420DBC 00520DBC 50118424 */  addiu      $4, $4, 0x1150
    /* 420DC0 00520DC0 58041408 */  j          func_00501160
    /* 420DC4 00520DC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00520da0, 0x28
