.section .text
.set noat
.set noreorder
glabel func_004c97f0
    /* 3C97F0 004C97F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C97F4 004C97F4 06008014 */  bnez       $4, .L004C9810
    /* 3C97F8 004C97F8 0000BFFF */   sd        $31, 0x0($29)
    /* 3C97FC 004C97FC 7600043C */  lui        $4, %hi(D_007584F8)
    /* 3C9800 004C9800 A61A130C */  jal        func_004c6a98
    /* 3C9804 004C9804 F8848424 */   addiu     $4, $4, %lo(D_007584F8)
    /* 3C9808 004C9808 02000010 */  b          .L004C9814
    /* 3C980C 004C980C FDFF0224 */   addiu     $2, $0, -0x3
  .L004C9810:
    /* 3C9810 004C9810 2000828C */  lw         $2, 0x20($4)
  .L004C9814:
    /* 3C9814 004C9814 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9818 004C9818 0800E003 */  jr         $31
    /* 3C981C 004C981C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c97f0, 0x30
