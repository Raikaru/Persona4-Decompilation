.section .text
.set noat
.set noreorder
glabel func_004ecac0
    /* 3ECAC0 004ECAC0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECAC4 004ECAC4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ECAC8 004ECAC8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECACC 004ECACC 01000424 */  addiu      $4, $0, 0x1
    /* 3ECAD0 004ECAD0 05006414 */  bne        $3, $4, .L004ECAE8
    /* 3ECAD4 004ECAD4 0000BFFF */   sd        $31, 0x0($29)
    /* 3ECAD8 004ECAD8 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECADC 004ECADC 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECAE0 004ECAE0 07006018 */  blez       $3, .L004ECB00
    /* 3ECAE4 004ECAE4 0000BFDF */   ld        $31, 0x0($29)
  .L004ECAE8:
    /* 3ECAE8 004ECAE8 7600043C */  lui        $4, %hi(D_0075CA58)
    /* 3ECAEC 004ECAEC 0000BFDF */  ld         $31, 0x0($29)
    /* 3ECAF0 004ECAF0 58CA8424 */  addiu      $4, $4, %lo(D_0075CA58)
    /* 3ECAF4 004ECAF4 FC341308 */  j          func_004cd3f0
    /* 3ECAF8 004ECAF8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ECAFC 004ECAFC 00000000 */  nop
  .L004ECB00:
    /* 3ECB00 004ECB00 0800E003 */  jr         $31
    /* 3ECB04 004ECB04 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ecac0, 0x48
