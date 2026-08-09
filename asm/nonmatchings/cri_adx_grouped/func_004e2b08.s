.section .text
.set noat
.set noreorder
glabel func_004e2b08
    /* 3E2B08 004E2B08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E2B0C 004E2B0C 06008014 */  bnez       $4, .L004E2B28
    /* 3E2B10 004E2B10 0000BFFF */   sd        $31, 0x0($29)
    /* 3E2B14 004E2B14 7600043C */  lui        $4, %hi(D_0075A490)
    /* 3E2B18 004E2B18 6A85130C */  jal        func_004e15a8
    /* 3E2B1C 004E2B1C 90A48424 */   addiu     $4, $4, %lo(D_0075A490)
    /* 3E2B20 004E2B20 0C000010 */  b          .L004E2B54
    /* 3E2B24 004E2B24 2D100000 */   daddu     $2, $0, $0
  .L004E2B28:
    /* 3E2B28 004E2B28 0000828C */  lw         $2, 0x0($4)
    /* 3E2B2C 004E2B2C 4C00428C */  lw         $2, 0x4C($2)
    /* 3E2B30 004E2B30 05004050 */  beql       $2, $0, .L004E2B48
    /* 3E2B34 004E2B34 7600043C */   lui       $4, %hi(D_0075A4B8)
    /* 3E2B38 004E2B38 09F84000 */  jalr       $2
    /* 3E2B3C 004E2B3C 0400848C */   lw        $4, 0x4($4)
    /* 3E2B40 004E2B40 05000010 */  b          .L004E2B58
    /* 3E2B44 004E2B44 0000BFDF */   ld        $31, 0x0($29)
  .L004E2B48:
    /* 3E2B48 004E2B48 6A85130C */  jal        func_004e15a8
    /* 3E2B4C 004E2B4C B8A48424 */   addiu     $4, $4, %lo(D_0075A4B8)
    /* 3E2B50 004E2B50 2D100000 */  daddu      $2, $0, $0
  .L004E2B54:
    /* 3E2B54 004E2B54 0000BFDF */  ld         $31, 0x0($29)
  .L004E2B58:
    /* 3E2B58 004E2B58 0800E003 */  jr         $31
    /* 3E2B5C 004E2B5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e2b08, 0x58
