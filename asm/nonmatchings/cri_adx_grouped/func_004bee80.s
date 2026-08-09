.section .text
.set noat
.set noreorder
glabel func_004bee80
    /* 3BEE80 004BEE80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BEE84 004BEE84 2D108000 */  daddu      $2, $4, $0
    /* 3BEE88 004BEE88 0000BFFF */  sd         $31, 0x0($29)
    /* 3BEE8C 004BEE8C 5000438C */  lw         $3, 0x50($2)
    /* 3BEE90 004BEE90 05006014 */  bnez       $3, .L004BEEA8
    /* 3BEE94 004BEE94 78004224 */   addiu     $2, $2, 0x78
    /* 3BEE98 004BEE98 7500043C */  lui        $4, %hi(D_00756F18)
    /* 3BEE9C 004BEE9C A8F5120C */  jal        func_004bd6a0
    /* 3BEEA0 004BEEA0 186F8424 */   addiu     $4, $4, %lo(D_00756F18)
    /* 3BEEA4 004BEEA4 2D100000 */  daddu      $2, $0, $0
  .L004BEEA8:
    /* 3BEEA8 004BEEA8 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEEAC 004BEEAC 0800E003 */  jr         $31
    /* 3BEEB0 004BEEB0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BEEB4 004BEEB4 00000000 */  nop
.size func_004bee80, 0x38
