.section .text
.set noat
.set noreorder
glabel func_004d9aa8
    /* 3D9AA8 004D9AA8 7300023C */  lui        $2, %hi(D_007286F4)
    /* 3D9AAC 004D9AAC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9AB0 004D9AB0 F486438C */  lw         $3, %lo(D_007286F4)($2)
    /* 3D9AB4 004D9AB4 2D288000 */  daddu      $5, $4, $0
    /* 3D9AB8 004D9AB8 04006010 */  beqz       $3, .L004D9ACC
    /* 3D9ABC 004D9ABC 0000BFFF */   sd        $31, 0x0($29)
    /* 3D9AC0 004D9AC0 7300023C */  lui        $2, %hi(D_007286F8)
    /* 3D9AC4 004D9AC4 09F86000 */  jalr       $3
    /* 3D9AC8 004D9AC8 F886448C */   lw        $4, %lo(D_007286F8)($2)
  .L004D9ACC:
    /* 3D9ACC 004D9ACC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9AD0 004D9AD0 2D100000 */  daddu      $2, $0, $0
    /* 3D9AD4 004D9AD4 0800E003 */  jr         $31
    /* 3D9AD8 004D9AD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9ADC 004D9ADC 00000000 */  nop
.size func_004d9aa8, 0x38
