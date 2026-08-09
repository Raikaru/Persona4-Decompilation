.section .text
.set noat
.set noreorder
glabel func_004e60e8
    /* 3E60E8 004E60E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E60EC 004E60EC 2D108000 */  daddu      $2, $4, $0
    /* 3E60F0 004E60F0 07004014 */  bnez       $2, .L004E6110
    /* 3E60F4 004E60F4 0000BFFF */   sd        $31, 0x0($29)
    /* 3E60F8 004E60F8 7600053C */  lui        $5, %hi(D_0075B1C8)
    /* 3E60FC 004E60FC 8E96130C */  jal        func_004e5a38
    /* 3E6100 004E6100 C8B1A524 */   addiu     $5, $5, %lo(D_0075B1C8)
    /* 3E6104 004E6104 03000010 */  b          .L004E6114
    /* 3E6108 004E6108 2D100000 */   daddu     $2, $0, $0
    /* 3E610C 004E610C 00000000 */  nop
  .L004E6110:
    /* 3E6110 004E6110 0C00428C */  lw         $2, 0xC($2)
  .L004E6114:
    /* 3E6114 004E6114 0000BFDF */  ld         $31, 0x0($29)
    /* 3E6118 004E6118 0800E003 */  jr         $31
    /* 3E611C 004E611C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e60e8, 0x38
