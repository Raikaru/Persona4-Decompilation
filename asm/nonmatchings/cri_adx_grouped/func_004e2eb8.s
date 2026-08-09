.section .text
.set noat
.set noreorder
glabel func_004e2eb8
    /* 3E2EB8 004E2EB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E2EBC 004E2EBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3E2EC0 004E2EC0 2D800000 */  daddu      $16, $0, $0
    /* 3E2EC4 004E2EC4 06008014 */  bnez       $4, .L004E2EE0
    /* 3E2EC8 004E2EC8 0800BFFF */   sd        $31, 0x8($29)
    /* 3E2ECC 004E2ECC 7600043C */  lui        $4, %hi(D_0075A700)
    /* 3E2ED0 004E2ED0 6A85130C */  jal        func_004e15a8
    /* 3E2ED4 004E2ED4 00A78424 */   addiu     $4, $4, %lo(D_0075A700)
    /* 3E2ED8 004E2ED8 0C000010 */  b          .L004E2F0C
    /* 3E2EDC 004E2EDC 2D100000 */   daddu     $2, $0, $0
  .L004E2EE0:
    /* 3E2EE0 004E2EE0 0000828C */  lw         $2, 0x0($4)
    /* 3E2EE4 004E2EE4 6400428C */  lw         $2, 0x64($2)
    /* 3E2EE8 004E2EE8 05004050 */  beql       $2, $0, .L004E2F00
    /* 3E2EEC 004E2EEC 7600043C */   lui       $4, %hi(D_0075A720)
    /* 3E2EF0 004E2EF0 09F84000 */  jalr       $2
    /* 3E2EF4 004E2EF4 0400848C */   lw        $4, 0x4($4)
    /* 3E2EF8 004E2EF8 03000010 */  b          .L004E2F08
    /* 3E2EFC 004E2EFC 2D804000 */   daddu     $16, $2, $0
  .L004E2F00:
    /* 3E2F00 004E2F00 6A85130C */  jal        func_004e15a8
    /* 3E2F04 004E2F04 20A78424 */   addiu     $4, $4, %lo(D_0075A720)
  .L004E2F08:
    /* 3E2F08 004E2F08 2D100002 */  daddu      $2, $16, $0
  .L004E2F0C:
    /* 3E2F0C 004E2F0C 0000B0DF */  ld         $16, 0x0($29)
    /* 3E2F10 004E2F10 0800BFDF */  ld         $31, 0x8($29)
    /* 3E2F14 004E2F14 0800E003 */  jr         $31
    /* 3E2F18 004E2F18 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E2F1C 004E2F1C 00000000 */  nop
.size func_004e2eb8, 0x68
