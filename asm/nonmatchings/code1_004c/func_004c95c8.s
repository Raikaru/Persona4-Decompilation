.section .text
.set noat
.set noreorder
glabel func_004c95c8
    /* 3C95C8 004C95C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C95CC 004C95CC 06008014 */  bnez       $4, .L004C95E8
    /* 3C95D0 004C95D0 0000BFFF */   sd        $31, 0x0($29)
    /* 3C95D4 004C95D4 7600043C */  lui        $4, %hi(D_00758470)
    /* 3C95D8 004C95D8 A61A130C */  jal        func_004c6a98
    /* 3C95DC 004C95DC 70848424 */   addiu     $4, $4, %lo(D_00758470)
    /* 3C95E0 004C95E0 02000010 */  b          .L004C95EC
    /* 3C95E4 004C95E4 FDFF0224 */   addiu     $2, $0, -0x3
  .L004C95E8:
    /* 3C95E8 004C95E8 1400828C */  lw         $2, 0x14($4)
  .L004C95EC:
    /* 3C95EC 004C95EC 0000BFDF */  ld         $31, 0x0($29)
    /* 3C95F0 004C95F0 0800E003 */  jr         $31
    /* 3C95F4 004C95F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c95c8, 0x30
