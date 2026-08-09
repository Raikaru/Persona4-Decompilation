.section .text
.set noat
.set noreorder
glabel func_004e2e50
    /* 3E2E50 004E2E50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E2E54 004E2E54 0000B0FF */  sd         $16, 0x0($29)
    /* 3E2E58 004E2E58 2D800000 */  daddu      $16, $0, $0
    /* 3E2E5C 004E2E5C 06008014 */  bnez       $4, .L004E2E78
    /* 3E2E60 004E2E60 0800BFFF */   sd        $31, 0x8($29)
    /* 3E2E64 004E2E64 7600043C */  lui        $4, %hi(D_0075A6C0)
    /* 3E2E68 004E2E68 6A85130C */  jal        func_004e15a8
    /* 3E2E6C 004E2E6C C0A68424 */   addiu     $4, $4, %lo(D_0075A6C0)
    /* 3E2E70 004E2E70 0C000010 */  b          .L004E2EA4
    /* 3E2E74 004E2E74 2D100000 */   daddu     $2, $0, $0
  .L004E2E78:
    /* 3E2E78 004E2E78 0000828C */  lw         $2, 0x0($4)
    /* 3E2E7C 004E2E7C 6000428C */  lw         $2, 0x60($2)
    /* 3E2E80 004E2E80 05004050 */  beql       $2, $0, .L004E2E98
    /* 3E2E84 004E2E84 7600043C */   lui       $4, %hi(D_0075A6E0)
    /* 3E2E88 004E2E88 09F84000 */  jalr       $2
    /* 3E2E8C 004E2E8C 0400848C */   lw        $4, 0x4($4)
    /* 3E2E90 004E2E90 03000010 */  b          .L004E2EA0
    /* 3E2E94 004E2E94 2D804000 */   daddu     $16, $2, $0
  .L004E2E98:
    /* 3E2E98 004E2E98 6A85130C */  jal        func_004e15a8
    /* 3E2E9C 004E2E9C E0A68424 */   addiu     $4, $4, %lo(D_0075A6E0)
  .L004E2EA0:
    /* 3E2EA0 004E2EA0 2D100002 */  daddu      $2, $16, $0
  .L004E2EA4:
    /* 3E2EA4 004E2EA4 0000B0DF */  ld         $16, 0x0($29)
    /* 3E2EA8 004E2EA8 0800BFDF */  ld         $31, 0x8($29)
    /* 3E2EAC 004E2EAC 0800E003 */  jr         $31
    /* 3E2EB0 004E2EB0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E2EB4 004E2EB4 00000000 */  nop
.size func_004e2e50, 0x68
