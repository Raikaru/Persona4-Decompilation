.section .text
.set noat
.set noreorder
glabel func_004f8f60
    /* 3F8F60 004F8F60 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3F8F64 004F8F64 00150400 */  sll        $2, $4, 20
    /* 3F8F68 004F8F68 2000B0FF */  sd         $16, 0x20($29)
    /* 3F8F6C 004F8F6C 2D80A000 */  daddu      $16, $5, $0
    /* 3F8F70 004F8F70 21204400 */  addu       $4, $2, $4
    /* 3F8F74 004F8F74 2D28A003 */  daddu      $5, $29, $0
    /* 3F8F78 004F8F78 2800B1FF */  sd         $17, 0x28($29)
    /* 3F8F7C 004F8F7C 3000BFFF */  sd         $31, 0x30($29)
    /* 3F8F80 004F8F80 66E3130C */  jal        func_004f8d98
    /* 3F8F84 004F8F84 2D88C000 */   daddu     $17, $6, $0
    /* 3F8F88 004F8F88 2D20A003 */  daddu      $4, $29, $0
    /* 3F8F8C 004F8F8C 1000A627 */  addiu      $6, $29, 0x10
    /* 3F8F90 004F8F90 1200A727 */  addiu      $7, $29, 0x12
    /* 3F8F94 004F8F94 1400A827 */  addiu      $8, $29, 0x14
    /* 3F8F98 004F8F98 C6E2130C */  jal        func_004f8b18
    /* 3F8F9C 004F8F9C 04000524 */   addiu     $5, $0, 0x4
    /* 3F8FA0 004F8FA0 09000324 */  addiu      $3, $0, 0x9
    /* 3F8FA4 004F8FA4 1000A687 */  lh         $6, 0x10($29)
    /* 3F8FA8 004F8FA8 01006050 */  beql       $3, $0, .L004F8FB0
    /* 3F8FAC 004F8FAC CD010000 */   break     0, 7
  .L004F8FB0:
    /* 3F8FB0 004F8FB0 1200A497 */  lhu        $4, 0x12($29)
    /* 3F8FB4 004F8FB4 2D280002 */  daddu      $5, $16, $0
    /* 3F8FB8 004F8FB8 1A00C300 */  div        $0, $6, $3
    /* 3F8FBC 004F8FBC 10100000 */  mfhi       $2
    /* 3F8FC0 004F8FC0 58E3130C */  jal        func_004f8d60
    /* 3F8FC4 004F8FC4 000022AE */   sw        $2, 0x0($17)
    /* 3F8FC8 004F8FC8 02000526 */  addiu      $5, $16, 0x2
    /* 3F8FCC 004F8FCC 58E3130C */  jal        func_004f8d60
    /* 3F8FD0 004F8FD0 1400A497 */   lhu       $4, 0x14($29)
    /* 3F8FD4 004F8FD4 2000B0DF */  ld         $16, 0x20($29)
    /* 3F8FD8 004F8FD8 2800B1DF */  ld         $17, 0x28($29)
    /* 3F8FDC 004F8FDC 3000BFDF */  ld         $31, 0x30($29)
    /* 3F8FE0 004F8FE0 0800E003 */  jr         $31
    /* 3F8FE4 004F8FE4 4000BD27 */   addiu     $29, $29, 0x40
.size func_004f8f60, 0x88
