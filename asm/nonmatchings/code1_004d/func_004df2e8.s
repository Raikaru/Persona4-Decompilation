.section .text
.set noat
.set noreorder
glabel func_004df2e8
    /* 3DF2E8 004DF2E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF2EC 004DF2EC 06008014 */  bnez       $4, .L004DF308
    /* 3DF2F0 004DF2F0 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF2F4 004DF2F4 7600043C */  lui        $4, %hi(D_00759A10)
    /* 3DF2F8 004DF2F8 B078130C */  jal        func_004de2c0
    /* 3DF2FC 004DF2FC 109A8424 */   addiu     $4, $4, %lo(D_00759A10)
    /* 3DF300 004DF300 02000010 */  b          .L004DF30C
    /* 3DF304 004DF304 2D100000 */   daddu     $2, $0, $0
  .L004DF308:
    /* 3DF308 004DF308 A801828C */  lw         $2, 0x1A8($4)
  .L004DF30C:
    /* 3DF30C 004DF30C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF310 004DF310 0800E003 */  jr         $31
    /* 3DF314 004DF314 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df2e8, 0x30
