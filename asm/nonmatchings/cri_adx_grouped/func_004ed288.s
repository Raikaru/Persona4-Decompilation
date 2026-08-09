.section .text
.set noat
.set noreorder
glabel func_004ed288
    /* 3ED288 004ED288 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED28C 004ED28C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED290 004ED290 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED294 004ED294 01000424 */  addiu      $4, $0, 0x1
    /* 3ED298 004ED298 05006414 */  bne        $3, $4, .L004ED2B0
    /* 3ED29C 004ED29C 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED2A0 004ED2A0 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ED2A4 004ED2A4 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ED2A8 004ED2A8 07006018 */  blez       $3, .L004ED2C8
    /* 3ED2AC 004ED2AC 0000BFDF */   ld        $31, 0x0($29)
  .L004ED2B0:
    /* 3ED2B0 004ED2B0 7600043C */  lui        $4, %hi(D_0075CBB8)
    /* 3ED2B4 004ED2B4 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED2B8 004ED2B8 B8CB8424 */  addiu      $4, $4, %lo(D_0075CBB8)
    /* 3ED2BC 004ED2BC FC341308 */  j          func_004cd3f0
    /* 3ED2C0 004ED2C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED2C4 004ED2C4 00000000 */  nop
  .L004ED2C8:
    /* 3ED2C8 004ED2C8 0800E003 */  jr         $31
    /* 3ED2CC 004ED2CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ed288, 0x48
