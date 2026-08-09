.section .text
.set noat
.set noreorder
glabel func_004df068
    /* 3DF068 004DF068 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF06C 004DF06C 06008014 */  bnez       $4, .L004DF088
    /* 3DF070 004DF070 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF074 004DF074 7600043C */  lui        $4, %hi(D_00759890)
    /* 3DF078 004DF078 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF07C 004DF07C 90988424 */  addiu      $4, $4, %lo(D_00759890)
    /* 3DF080 004DF080 B0781308 */  j          func_004de2c0
    /* 3DF084 004DF084 1000BD27 */   addiu     $29, $29, 0x10
  .L004DF088:
    /* 3DF088 004DF088 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF08C 004DF08C B00185A0 */  sb         $5, 0x1B0($4)
    /* 3DF090 004DF090 0800E003 */  jr         $31
    /* 3DF094 004DF094 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df068, 0x30
