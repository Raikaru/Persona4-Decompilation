.section .text
.set noat
.set noreorder
glabel func_004c8e80
    /* 3C8E80 004C8E80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C8E84 004C8E84 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8E88 004C8E88 2D808000 */  daddu      $16, $4, $0
    /* 3C8E8C 004C8E8C 1800B3FF */  sd         $19, 0x18($29)
    /* 3C8E90 004C8E90 2D98C000 */  daddu      $19, $6, $0
    /* 3C8E94 004C8E94 2000B4FF */  sd         $20, 0x20($29)
    /* 3C8E98 004C8E98 2DA0A000 */  daddu      $20, $5, $0
    /* 3C8E9C 004C8E9C 04000424 */  addiu      $4, $0, 0x4
    /* 3C8EA0 004C8EA0 2D300002 */  daddu      $6, $16, $0
    /* 3C8EA4 004C8EA4 2D280000 */  daddu      $5, $0, $0
    /* 3C8EA8 004C8EA8 2D388002 */  daddu      $7, $20, $0
    /* 3C8EAC 004C8EAC 0800B1FF */  sd         $17, 0x8($29)
    /* 3C8EB0 004C8EB0 1000B2FF */  sd         $18, 0x10($29)
    /* 3C8EB4 004C8EB4 2800BFFF */  sd         $31, 0x28($29)
    /* 3C8EB8 004C8EB8 981C130C */  jal        func_004c7260
    /* 3C8EBC 004C8EBC 2D406002 */   daddu     $8, $19, $0
    /* 3C8EC0 004C8EC0 03000016 */  bnez       $16, .L004C8ED0
    /* 3C8EC4 004C8EC4 7600043C */   lui       $4, %hi(D_00758288)
    /* 3C8EC8 004C8EC8 09000010 */  b          .L004C8EF0
    /* 3C8ECC 004C8ECC 88828424 */   addiu     $4, $4, %lo(D_00758288)
  .L004C8ED0:
    /* 3C8ED0 004C8ED0 03008106 */  bgez       $20, .L004C8EE0
    /* 3C8ED4 004C8ED4 7600043C */   lui       $4, %hi(D_007582B0)
    /* 3C8ED8 004C8ED8 05000010 */  b          .L004C8EF0
    /* 3C8EDC 004C8EDC B0828424 */   addiu     $4, $4, %lo(D_007582B0)
  .L004C8EE0:
    /* 3C8EE0 004C8EE0 07006056 */  bnel       $19, $0, .L004C8F00
    /* 3C8EE4 004C8EE4 01000482 */   lb        $4, 0x1($16)
    /* 3C8EE8 004C8EE8 7600043C */  lui        $4, %hi(D_007582E0)
    /* 3C8EEC 004C8EEC E0828424 */  addiu      $4, $4, %lo(D_007582E0)
  .L004C8EF0:
    /* 3C8EF0 004C8EF0 A61A130C */  jal        func_004c6a98
    /* 3C8EF4 004C8EF4 00000000 */   nop
    /* 3C8EF8 004C8EF8 3C000010 */  b          .L004C8FEC
    /* 3C8EFC 004C8EFC FDFF0224 */   addiu     $2, $0, -0x3
  .L004C8F00:
    /* 3C8F00 004C8F00 02000324 */  addiu      $3, $0, 0x2
    /* 3C8F04 004C8F04 39008310 */  beq        $4, $3, .L004C8FEC
    /* 3C8F08 004C8F08 2D100000 */   daddu     $2, $0, $0
    /* 3C8F0C 004C8F0C 0800028E */  lw         $2, 0x8($16)
    /* 3C8F10 004C8F10 05004010 */  beqz       $2, .L004C8F28
    /* 3C8F14 004C8F14 7600043C */   lui       $4, %hi(D_00758308)
    /* 3C8F18 004C8F18 A61A130C */  jal        func_004c6a98
    /* 3C8F1C 004C8F1C 08838424 */   addiu     $4, $4, %lo(D_00758308)
    /* 3C8F20 004C8F20 32000010 */  b          .L004C8FEC
    /* 3C8F24 004C8F24 FFFF0224 */   addiu     $2, $0, -0x1
  .L004C8F28:
    /* 3C8F28 004C8F28 C0921400 */  sll        $18, $20, 11
    /* 3C8F2C 004C8F2C 2D206002 */  daddu      $4, $19, $0
    /* 3C8F30 004C8F30 2D284002 */  daddu      $5, $18, $0
    /* 3C8F34 004C8F34 06B8130C */  jal        func_004ee018
    /* 3C8F38 004C8F38 2D300000 */   daddu     $6, $0, $0
    /* 3C8F3C 004C8F3C 2D884000 */  daddu      $17, $2, $0
    /* 3C8F40 004C8F40 2A002012 */  beqz       $17, .L004C8FEC
    /* 3C8F44 004C8F44 FEFF0224 */   addiu     $2, $0, -0x2
    /* 3C8F48 004C8F48 2A15130C */  jal        func_004c54a8
    /* 3C8F4C 004C8F4C 00000000 */   nop
    /* 3C8F50 004C8F50 240013AE */  sw         $19, 0x24($16)
    /* 3C8F54 004C8F54 080011AE */  sw         $17, 0x8($16)
    /* 3C8F58 004C8F58 7100043C */  lui        $4, %hi(D_007165F0)
    /* 3C8F5C 004C8F5C 280012AE */  sw         $18, 0x28($16)
    /* 3C8F60 004C8F60 01000324 */  addiu      $3, $0, 0x1
    /* 3C8F64 004C8F64 F065828C */  lw         $2, %lo(D_007165F0)($4)
    /* 3C8F68 004C8F68 03004314 */  bne        $2, $3, .L004C8F78
    /* 3C8F6C 004C8F6C 2D284002 */   daddu     $5, $18, $0
    /* 3C8F70 004C8F70 3C1B130C */  jal        func_004c6cf0
    /* 3C8F74 004C8F74 2D206002 */   daddu     $4, $19, $0
  .L004C8F78:
    /* 3C8F78 004C8F78 3015130C */  jal        func_004c54c0
    /* 3C8F7C 004C8F7C 00000000 */   nop
    /* 3C8F80 004C8F80 2D200002 */  daddu      $4, $16, $0
    /* 3C8F84 004C8F84 0800068E */  lw         $6, 0x8($16)
    /* 3C8F88 004C8F88 F422130C */  jal        func_004c8bd0
    /* 3C8F8C 004C8F8C 2D288002 */   daddu     $5, $20, $0
    /* 3C8F90 004C8F90 2D884000 */  daddu      $17, $2, $0
    /* 3C8F94 004C8F94 0E00205E */  bgtzl      $17, .L004C8FD0
    /* 3C8F98 004C8F98 020000A2 */   sb        $0, 0x2($16)
    /* 3C8F9C 004C8F9C 2A15130C */  jal        func_004c54a8
    /* 3C8FA0 004C8FA0 00000000 */   nop
    /* 3C8FA4 004C8FA4 0800048E */  lw         $4, 0x8($16)
    /* 3C8FA8 004C8FA8 06008010 */  beqz       $4, .L004C8FC4
    /* 3C8FAC 004C8FAC 00000000 */   nop
    /* 3C8FB0 004C8FB0 0000838C */  lw         $3, 0x0($4)
    /* 3C8FB4 004C8FB4 0C00628C */  lw         $2, 0xC($3)
    /* 3C8FB8 004C8FB8 09F84000 */  jalr       $2
    /* 3C8FBC 004C8FBC 00000000 */   nop
    /* 3C8FC0 004C8FC0 080000AE */  sw         $0, 0x8($16)
  .L004C8FC4:
    /* 3C8FC4 004C8FC4 3015130C */  jal        func_004c54c0
    /* 3C8FC8 004C8FC8 00000000 */   nop
    /* 3C8FCC 004C8FCC 020000A2 */  sb         $0, 0x2($16)
  .L004C8FD0:
    /* 3C8FD0 004C8FD0 2D300002 */  daddu      $6, $16, $0
    /* 3C8FD4 004C8FD4 2D388002 */  daddu      $7, $20, $0
    /* 3C8FD8 004C8FD8 2D406002 */  daddu      $8, $19, $0
    /* 3C8FDC 004C8FDC 04000424 */  addiu      $4, $0, 0x4
    /* 3C8FE0 004C8FE0 981C130C */  jal        func_004c7260
    /* 3C8FE4 004C8FE4 01000524 */   addiu     $5, $0, 0x1
    /* 3C8FE8 004C8FE8 2D102002 */  daddu      $2, $17, $0
  .L004C8FEC:
    /* 3C8FEC 004C8FEC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8FF0 004C8FF0 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8FF4 004C8FF4 1000B2DF */  ld         $18, 0x10($29)
    /* 3C8FF8 004C8FF8 1800B3DF */  ld         $19, 0x18($29)
    /* 3C8FFC 004C8FFC 2000B4DF */  ld         $20, 0x20($29)
    /* 3C9000 004C9000 2800BFDF */  ld         $31, 0x28($29)
    /* 3C9004 004C9004 0800E003 */  jr         $31
    /* 3C9008 004C9008 3000BD27 */   addiu     $29, $29, 0x30
    /* 3C900C 004C900C 00000000 */  nop
.size func_004c8e80, 0x190
