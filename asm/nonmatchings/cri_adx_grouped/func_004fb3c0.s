.section .text
.set noat
.set noreorder
glabel func_004fb3c0
    /* 3FB3C0 004FB3C0 7400023C */  lui        $2, %hi(D_00743CB0)
    /* 3FB3C4 004FB3C4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB3C8 004FB3C8 B03C428C */  lw         $2, %lo(D_00743CB0)($2)
    /* 3FB3CC 004FB3CC 03004010 */  beqz       $2, .L004FB3DC
    /* 3FB3D0 004FB3D0 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB3D4 004FB3D4 09F84000 */  jalr       $2
    /* 3FB3D8 004FB3D8 00000000 */   nop
  .L004FB3DC:
    /* 3FB3DC 004FB3DC 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB3E0 004FB3E0 0800E003 */  jr         $31
    /* 3FB3E4 004FB3E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb3c0, 0x28
