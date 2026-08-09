.section .text
.set noat
.set noreorder
glabel func_004ece70
    /* 3ECE70 004ECE70 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECE74 004ECE74 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ECE78 004ECE78 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECE7C 004ECE7C 01000424 */  addiu      $4, $0, 0x1
    /* 3ECE80 004ECE80 05006414 */  bne        $3, $4, .L004ECE98
    /* 3ECE84 004ECE84 0000BFFF */   sd        $31, 0x0($29)
    /* 3ECE88 004ECE88 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECE8C 004ECE8C 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECE90 004ECE90 07006018 */  blez       $3, .L004ECEB0
    /* 3ECE94 004ECE94 0000BFDF */   ld        $31, 0x0($29)
  .L004ECE98:
    /* 3ECE98 004ECE98 7600043C */  lui        $4, %hi(D_0075CA80)
    /* 3ECE9C 004ECE9C 0000BFDF */  ld         $31, 0x0($29)
    /* 3ECEA0 004ECEA0 80CA8424 */  addiu      $4, $4, %lo(D_0075CA80)
    /* 3ECEA4 004ECEA4 FC341308 */  j          func_004cd3f0
    /* 3ECEA8 004ECEA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ECEAC 004ECEAC 00000000 */  nop
  .L004ECEB0:
    /* 3ECEB0 004ECEB0 0800E003 */  jr         $31
    /* 3ECEB4 004ECEB4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ece70, 0x48
