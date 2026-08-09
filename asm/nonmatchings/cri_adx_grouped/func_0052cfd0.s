.section .text
.set noat
.set noreorder
glabel func_0052cfd0
    /* 42CFD0 0052CFD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42CFD4 0052CFD4 03008010 */  beqz       $4, .L0052CFE4
    /* 42CFD8 0052CFD8 0000BFFF */   sd        $31, 0x0($29)
    /* 42CFDC 0052CFDC 0400A104 */  bgez       $5, .L0052CFF0
    /* 42CFE0 0052CFE0 7600053C */   lui       $5, %hi(D_00760FF8)
  .L0052CFE4:
    /* 42CFE4 0052CFE4 07000010 */  b          .L0052D004
    /* 42CFE8 0052CFE8 2D100000 */   daddu     $2, $0, $0
    /* 42CFEC 0052CFEC 00000000 */  nop
  .L0052CFF0:
    /* 42CFF0 0052CFF0 12008424 */  addiu      $4, $4, 0x12
    /* 42CFF4 0052CFF4 F80FA524 */  addiu      $5, $5, %lo(D_00760FF8)
    /* 42CFF8 0052CFF8 0C0B110C */  jal        func_00442c30
    /* 42CFFC 0052CFFC 01000624 */   addiu     $6, $0, 0x1
    /* 42D000 0052D000 0100422C */  sltiu      $2, $2, 0x1
  .L0052D004:
    /* 42D004 0052D004 0000BFDF */  ld         $31, 0x0($29)
    /* 42D008 0052D008 0800E003 */  jr         $31
    /* 42D00C 0052D00C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052cfd0, 0x40
