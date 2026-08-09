.section .text
.set noat
.set noreorder
glabel func_004ed240
    /* 3ED240 004ED240 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED244 004ED244 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED248 004ED248 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED24C 004ED24C 01000424 */  addiu      $4, $0, 0x1
    /* 3ED250 004ED250 05006414 */  bne        $3, $4, .L004ED268
    /* 3ED254 004ED254 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED258 004ED258 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED25C 004ED25C 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED260 004ED260 05006018 */  blez       $3, .L004ED278
    /* 3ED264 004ED264 2D100000 */   daddu     $2, $0, $0
  .L004ED268:
    /* 3ED268 004ED268 7600043C */  lui        $4, %hi(D_0075CB90)
    /* 3ED26C 004ED26C FC34130C */  jal        func_004cd3f0
    /* 3ED270 004ED270 90CB8424 */   addiu     $4, $4, %lo(D_0075CB90)
    /* 3ED274 004ED274 2D100000 */  daddu      $2, $0, $0
  .L004ED278:
    /* 3ED278 004ED278 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED27C 004ED27C 0800E003 */  jr         $31
    /* 3ED280 004ED280 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED284 004ED284 00000000 */  nop
.size func_004ed240, 0x48
