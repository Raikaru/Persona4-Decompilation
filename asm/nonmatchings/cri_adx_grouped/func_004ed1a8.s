.section .text
.set noat
.set noreorder
glabel func_004ed1a8
    /* 3ED1A8 004ED1A8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED1AC 004ED1AC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED1B0 004ED1B0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED1B4 004ED1B4 01000424 */  addiu      $4, $0, 0x1
    /* 3ED1B8 004ED1B8 05006414 */  bne        $3, $4, .L004ED1D0
    /* 3ED1BC 004ED1BC 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED1C0 004ED1C0 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED1C4 004ED1C4 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED1C8 004ED1C8 05006018 */  blez       $3, .L004ED1E0
    /* 3ED1CC 004ED1CC 2D100000 */   daddu     $2, $0, $0
  .L004ED1D0:
    /* 3ED1D0 004ED1D0 7600043C */  lui        $4, %hi(D_0075CB40)
    /* 3ED1D4 004ED1D4 FC34130C */  jal        func_004cd3f0
    /* 3ED1D8 004ED1D8 40CB8424 */   addiu     $4, $4, %lo(D_0075CB40)
    /* 3ED1DC 004ED1DC 2D100000 */  daddu      $2, $0, $0
  .L004ED1E0:
    /* 3ED1E0 004ED1E0 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED1E4 004ED1E4 0800E003 */  jr         $31
    /* 3ED1E8 004ED1E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED1EC 004ED1EC 00000000 */  nop
.size func_004ed1a8, 0x48
