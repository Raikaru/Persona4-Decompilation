.section .text
.set noat
.set noreorder
glabel func_004d4fa0
    /* 3D4FA0 004D4FA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4FA4 004D4FA4 40180500 */  sll        $3, $5, 1
    /* 3D4FA8 004D4FA8 07008014 */  bnez       $4, .L004D4FC8
    /* 3D4FAC 004D4FAC 0000BFFF */   sd        $31, 0x0($29)
    /* 3D4FB0 004D4FB0 7600043C */  lui        $4, %hi(D_00758DF8)
    /* 3D4FB4 004D4FB4 A61A130C */  jal        func_004c6a98
    /* 3D4FB8 004D4FB8 F88D8424 */   addiu     $4, $4, %lo(D_00758DF8)
    /* 3D4FBC 004D4FBC 04000010 */  b          .L004D4FD0
    /* 3D4FC0 004D4FC0 2D100000 */   daddu     $2, $0, $0
    /* 3D4FC4 004D4FC4 00000000 */  nop
  .L004D4FC8:
    /* 3D4FC8 004D4FC8 21186400 */  addu       $3, $3, $4
    /* 3D4FCC 004D4FCC 42006284 */  lh         $2, 0x42($3)
  .L004D4FD0:
    /* 3D4FD0 004D4FD0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4FD4 004D4FD4 0800E003 */  jr         $31
    /* 3D4FD8 004D4FD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4FDC 004D4FDC 00000000 */  nop
.size func_004d4fa0, 0x40
