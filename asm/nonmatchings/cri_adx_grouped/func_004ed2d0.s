.section .text
.set noat
.set noreorder
glabel func_004ed2d0
    /* 3ED2D0 004ED2D0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED2D4 004ED2D4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED2D8 004ED2D8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED2DC 004ED2DC 01000424 */  addiu      $4, $0, 0x1
    /* 3ED2E0 004ED2E0 05006414 */  bne        $3, $4, .L004ED2F8
    /* 3ED2E4 004ED2E4 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED2E8 004ED2E8 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED2EC 004ED2EC 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED2F0 004ED2F0 05006018 */  blez       $3, .L004ED308
    /* 3ED2F4 004ED2F4 2D100000 */   daddu     $2, $0, $0
  .L004ED2F8:
    /* 3ED2F8 004ED2F8 7600043C */  lui        $4, %hi(D_0075CBE8)
    /* 3ED2FC 004ED2FC FC34130C */  jal        func_004cd3f0
    /* 3ED300 004ED300 E8CB8424 */   addiu     $4, $4, %lo(D_0075CBE8)
    /* 3ED304 004ED304 2D100000 */  daddu      $2, $0, $0
  .L004ED308:
    /* 3ED308 004ED308 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED30C 004ED30C 0800E003 */  jr         $31
    /* 3ED310 004ED310 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED314 004ED314 00000000 */  nop
.size func_004ed2d0, 0x48
