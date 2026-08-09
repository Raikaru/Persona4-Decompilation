.section .text
.set noat
.set noreorder
glabel func_004d5f48
    /* 3D5F48 004D5F48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5F4C 004D5F4C 06008014 */  bnez       $4, .L004D5F68
    /* 3D5F50 004D5F50 0000BFFF */   sd        $31, 0x0($29)
    /* 3D5F54 004D5F54 7600043C */  lui        $4, %hi(D_00759160)
    /* 3D5F58 004D5F58 A61A130C */  jal        func_004c6a98
    /* 3D5F5C 004D5F5C 60918424 */   addiu     $4, $4, %lo(D_00759160)
    /* 3D5F60 004D5F60 02000010 */  b          .L004D5F6C
    /* 3D5F64 004D5F64 2D100000 */   daddu     $2, $0, $0
  .L004D5F68:
    /* 3D5F68 004D5F68 1400828C */  lw         $2, 0x14($4)
  .L004D5F6C:
    /* 3D5F6C 004D5F6C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5F70 004D5F70 0800E003 */  jr         $31
    /* 3D5F74 004D5F74 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5f48, 0x30
