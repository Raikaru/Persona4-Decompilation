.section .text
.set noat
.set noreorder
glabel func_004e2f20
    /* 3E2F20 004E2F20 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3E2F24 004E2F24 2000B0FF */  sd         $16, 0x20($29)
    /* 3E2F28 004E2F28 2D80A000 */  daddu      $16, $5, $0
    /* 3E2F2C 004E2F2C 2800B1FF */  sd         $17, 0x28($29)
    /* 3E2F30 004E2F30 05008014 */  bnez       $4, .L004E2F48
    /* 3E2F34 004E2F34 3000BFFF */   sd        $31, 0x30($29)
    /* 3E2F38 004E2F38 7600043C */  lui        $4, %hi(D_0075A740)
    /* 3E2F3C 004E2F3C 11000010 */  b          .L004E2F84
    /* 3E2F40 004E2F40 40A78424 */   addiu     $4, $4, %lo(D_0075A740)
    /* 3E2F44 004E2F44 00000000 */  nop
  .L004E2F48:
    /* 3E2F48 004E2F48 05000016 */  bnez       $16, .L004E2F60
    /* 3E2F4C 004E2F4C 00000000 */   nop
    /* 3E2F50 004E2F50 7600043C */  lui        $4, %hi(D_0075A768)
    /* 3E2F54 004E2F54 0B000010 */  b          .L004E2F84
    /* 3E2F58 004E2F58 68A78424 */   addiu     $4, $4, %lo(D_0075A768)
    /* 3E2F5C 004E2F5C 00000000 */  nop
  .L004E2F60:
    /* 3E2F60 004E2F60 4286130C */  jal        func_004e1908
    /* 3E2F64 004E2F64 00000000 */   nop
    /* 3E2F68 004E2F68 2D280000 */  daddu      $5, $0, $0
    /* 3E2F6C 004E2F6C 2D884000 */  daddu      $17, $2, $0
    /* 3E2F70 004E2F70 2D20A003 */  daddu      $4, $29, $0
    /* 3E2F74 004E2F74 08002016 */  bnez       $17, .L004E2F98
    /* 3E2F78 004E2F78 14000624 */   addiu     $6, $0, 0x14
    /* 3E2F7C 004E2F7C 7600043C */  lui        $4, %hi(D_0075A798)
    /* 3E2F80 004E2F80 98A78424 */  addiu      $4, $4, %lo(D_0075A798)
  .L004E2F84:
    /* 3E2F84 004E2F84 6A85130C */  jal        func_004e15a8
    /* 3E2F88 004E2F88 00000000 */   nop
    /* 3E2F8C 004E2F8C 0E000010 */  b          .L004E2FC8
    /* 3E2F90 004E2F90 FFFF0224 */   addiu     $2, $0, -0x1
    /* 3E2F94 004E2F94 00000000 */  nop
  .L004E2F98:
    /* 3E2F98 004E2F98 72FE100C */  jal        func_0043f9c8
    /* 3E2F9C 004E2F9C 00000000 */   nop
    /* 3E2FA0 004E2FA0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3E2FA4 004E2FA4 0000B0AF */  sw         $16, 0x0($29)
    /* 3E2FA8 004E2FA8 2D20A003 */  daddu      $4, $29, $0
    /* 3E2FAC 004E2FAC 01000524 */  addiu      $5, $0, 0x1
    /* 3E2FB0 004E2FB0 2D300000 */  daddu      $6, $0, $0
    /* 3E2FB4 004E2FB4 6000238E */  lw         $3, 0x60($17)
    /* 3E2FB8 004E2FB8 03006010 */  beqz       $3, .L004E2FC8
    /* 3E2FBC 004E2FBC 2D380000 */   daddu     $7, $0, $0
    /* 3E2FC0 004E2FC0 09F86000 */  jalr       $3
    /* 3E2FC4 004E2FC4 00000000 */   nop
  .L004E2FC8:
    /* 3E2FC8 004E2FC8 2000B0DF */  ld         $16, 0x20($29)
    /* 3E2FCC 004E2FCC 2800B1DF */  ld         $17, 0x28($29)
    /* 3E2FD0 004E2FD0 3000BFDF */  ld         $31, 0x30($29)
    /* 3E2FD4 004E2FD4 0800E003 */  jr         $31
    /* 3E2FD8 004E2FD8 4000BD27 */   addiu     $29, $29, 0x40
    /* 3E2FDC 004E2FDC 00000000 */  nop
.size func_004e2f20, 0xc0
