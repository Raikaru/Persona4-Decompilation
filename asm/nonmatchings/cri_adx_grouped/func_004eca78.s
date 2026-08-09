.section .text
.set noat
.set noreorder
glabel func_004eca78
    /* 3ECA78 004ECA78 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECA7C 004ECA7C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ECA80 004ECA80 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECA84 004ECA84 01000424 */  addiu      $4, $0, 0x1
    /* 3ECA88 004ECA88 05006414 */  bne        $3, $4, .L004ECAA0
    /* 3ECA8C 004ECA8C 0000BFFF */   sd        $31, 0x0($29)
    /* 3ECA90 004ECA90 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECA94 004ECA94 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECA98 004ECA98 07006018 */  blez       $3, .L004ECAB8
    /* 3ECA9C 004ECA9C 0000BFDF */   ld        $31, 0x0($29)
  .L004ECAA0:
    /* 3ECAA0 004ECAA0 7600043C */  lui        $4, %hi(D_0075CA30)
    /* 3ECAA4 004ECAA4 0000BFDF */  ld         $31, 0x0($29)
    /* 3ECAA8 004ECAA8 30CA8424 */  addiu      $4, $4, %lo(D_0075CA30)
    /* 3ECAAC 004ECAAC FC341308 */  j          func_004cd3f0
    /* 3ECAB0 004ECAB0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ECAB4 004ECAB4 00000000 */  nop
  .L004ECAB8:
    /* 3ECAB8 004ECAB8 0800E003 */  jr         $31
    /* 3ECABC 004ECABC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eca78, 0x48
