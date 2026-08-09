.section .text
.set noat
.set noreorder
glabel func_004df0f8
    /* 3DF0F8 004DF0F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF0FC 004DF0FC 06008014 */  bnez       $4, .L004DF118
    /* 3DF100 004DF100 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF104 004DF104 7600043C */  lui        $4, %hi(D_00759920)
    /* 3DF108 004DF108 B078130C */  jal        func_004de2c0
    /* 3DF10C 004DF10C 20998424 */   addiu     $4, $4, %lo(D_00759920)
    /* 3DF110 004DF110 02000010 */  b          .L004DF11C
    /* 3DF114 004DF114 FFFF0224 */   addiu     $2, $0, -0x1
  .L004DF118:
    /* 3DF118 004DF118 C001828C */  lw         $2, 0x1C0($4)
  .L004DF11C:
    /* 3DF11C 004DF11C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF120 004DF120 0800E003 */  jr         $31
    /* 3DF124 004DF124 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df0f8, 0x30
