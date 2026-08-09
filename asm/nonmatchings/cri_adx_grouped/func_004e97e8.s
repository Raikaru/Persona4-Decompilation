.section .text
.set noat
.set noreorder
glabel func_004e97e8
    /* 3E97E8 004E97E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E97EC 004E97EC 06008014 */  bnez       $4, .L004E9808
    /* 3E97F0 004E97F0 0000BFFF */   sd        $31, 0x0($29)
    /* 3E97F4 004E97F4 7600043C */  lui        $4, %hi(D_0075BD10)
    /* 3E97F8 004E97F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E97FC 004E97FC 10BD8424 */  addiu      $4, $4, %lo(D_0075BD10)
    /* 3E9800 004E9800 1EA61308 */  j          func_004e9878
    /* 3E9804 004E9804 1000BD27 */   addiu     $29, $29, 0x10
  .L004E9808:
    /* 3E9808 004E9808 0000BFDF */  ld         $31, 0x0($29)
    /* 3E980C 004E980C 030085A0 */  sb         $5, 0x3($4)
    /* 3E9810 004E9810 0800E003 */  jr         $31
    /* 3E9814 004E9814 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e97e8, 0x30
