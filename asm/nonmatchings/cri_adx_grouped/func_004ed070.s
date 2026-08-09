.section .text
.set noat
.set noreorder
glabel func_004ed070
    /* 3ED070 004ED070 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED074 004ED074 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED078 004ED078 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED07C 004ED07C 01000424 */  addiu      $4, $0, 0x1
    /* 3ED080 004ED080 05006414 */  bne        $3, $4, .L004ED098
    /* 3ED084 004ED084 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED088 004ED088 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED08C 004ED08C 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED090 004ED090 05006018 */  blez       $3, .L004ED0A8
    /* 3ED094 004ED094 2D100000 */   daddu     $2, $0, $0
  .L004ED098:
    /* 3ED098 004ED098 7600043C */  lui        $4, %hi(D_0075CB18)
    /* 3ED09C 004ED09C FC34130C */  jal        func_004cd3f0
    /* 3ED0A0 004ED0A0 18CB8424 */   addiu     $4, $4, %lo(D_0075CB18)
    /* 3ED0A4 004ED0A4 2D100000 */  daddu      $2, $0, $0
  .L004ED0A8:
    /* 3ED0A8 004ED0A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED0AC 004ED0AC 0800E003 */  jr         $31
    /* 3ED0B0 004ED0B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED0B4 004ED0B4 00000000 */  nop
.size func_004ed070, 0x48
