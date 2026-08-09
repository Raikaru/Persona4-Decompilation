.section .text
.set noat
.set noreorder
glabel func_004ed020
    /* 3ED020 004ED020 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED024 004ED024 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED028 004ED028 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED02C 004ED02C 01000424 */  addiu      $4, $0, 0x1
    /* 3ED030 004ED030 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED034 004ED034 05006414 */  bne        $3, $4, .L004ED04C
    /* 3ED038 004ED038 2D30A000 */   daddu     $6, $5, $0
    /* 3ED03C 004ED03C 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ED040 004ED040 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ED044 004ED044 08006018 */  blez       $3, .L004ED068
    /* 3ED048 004ED048 0000BFDF */   ld        $31, 0x0($29)
  .L004ED04C:
    /* 3ED04C 004ED04C 10000224 */  addiu      $2, $0, 0x10
    /* 3ED050 004ED050 0500C210 */  beq        $6, $2, .L004ED068
    /* 3ED054 004ED054 0000BFDF */   ld        $31, 0x0($29)
    /* 3ED058 004ED058 7600043C */  lui        $4, %hi(D_0075CAE8)
    /* 3ED05C 004ED05C FC34130C */  jal        func_004cd3f0
    /* 3ED060 004ED060 E8CA8424 */   addiu     $4, $4, %lo(D_0075CAE8)
    /* 3ED064 004ED064 0000BFDF */  ld         $31, 0x0($29)
  .L004ED068:
    /* 3ED068 004ED068 0800E003 */  jr         $31
    /* 3ED06C 004ED06C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ed020, 0x50
