.section .text
.set noat
.set noreorder
glabel func_004e9fb0
    /* 3E9FB0 004E9FB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E9FB4 004E9FB4 7400023C */  lui        $2, %hi(D_00738D68)
    /* 3E9FB8 004E9FB8 1000BFFF */  sd         $31, 0x10($29)
    /* 3E9FBC 004E9FBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3E9FC0 004E9FC0 688D5024 */  addiu      $16, $2, %lo(D_00738D68)
    /* 3E9FC4 004E9FC4 0800B1FF */  sd         $17, 0x8($29)
    /* 3E9FC8 004E9FC8 27001124 */  addiu      $17, $0, 0x27
    /* 3E9FCC 004E9FCC 00000000 */  nop
  .L004E9FD0:
    /* 3E9FD0 004E9FD0 00000282 */  lb         $2, 0x0($16)
    /* 3E9FD4 004E9FD4 04004050 */  beql       $2, $0, .L004E9FE8
    /* 3E9FD8 004E9FD8 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3E9FDC 004E9FDC EAA7130C */  jal        func_004e9fa8
    /* 3E9FE0 004E9FE0 2D200002 */   daddu     $4, $16, $0
    /* 3E9FE4 004E9FE4 FFFF3126 */  addiu      $17, $17, -0x1
  .L004E9FE8:
    /* 3E9FE8 004E9FE8 F9FF2106 */  bgez       $17, .L004E9FD0
    /* 3E9FEC 004E9FEC 38001026 */   addiu     $16, $16, 0x38
    /* 3E9FF0 004E9FF0 0000B0DF */  ld         $16, 0x0($29)
    /* 3E9FF4 004E9FF4 0800B1DF */  ld         $17, 0x8($29)
    /* 3E9FF8 004E9FF8 1000BFDF */  ld         $31, 0x10($29)
    /* 3E9FFC 004E9FFC 0800E003 */  jr         $31
    /* 3EA000 004EA000 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EA004 004EA004 00000000 */  nop
.size func_004e9fb0, 0x58
