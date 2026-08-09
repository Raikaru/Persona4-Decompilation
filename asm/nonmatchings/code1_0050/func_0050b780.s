.section .text
.set noat
.set noreorder
glabel func_0050b780
    /* 40B780 0050B780 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B784 0050B784 7400023C */  lui        $2, %hi(D_00744298)
    /* 40B788 0050B788 0000BFFF */  sd         $31, 0x0($29)
    /* 40B78C 0050B78C 98424224 */  addiu      $2, $2, %lo(D_00744298)
    /* 40B790 0050B790 0000438C */  lw         $3, 0x0($2)
    /* 40B794 0050B794 04006010 */  beqz       $3, .L0050B7A8
    /* 40B798 0050B798 0000BFDF */   ld        $31, 0x0($29)
    /* 40B79C 0050B79C 000040AC */  sw         $0, 0x0($2)
    /* 40B7A0 0050B7A0 FE2C1408 */  j          func_0050b3f8
    /* 40B7A4 0050B7A4 1000BD27 */   addiu     $29, $29, 0x10
  .L0050B7A8:
    /* 40B7A8 0050B7A8 0800E003 */  jr         $31
    /* 40B7AC 0050B7AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b780, 0x30
