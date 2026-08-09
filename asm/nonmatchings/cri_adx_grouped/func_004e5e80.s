.section .text
.set noat
.set noreorder
glabel func_004e5e80
    /* 3E5E80 004E5E80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E5E84 004E5E84 1000B2FF */  sd         $18, 0x10($29)
    /* 3E5E88 004E5E88 2D908000 */  daddu      $18, $4, $0
    /* 3E5E8C 004E5E8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3E5E90 004E5E90 0800B1FF */  sd         $17, 0x8($29)
    /* 3E5E94 004E5E94 1800B3FF */  sd         $19, 0x18($29)
    /* 3E5E98 004E5E98 2000B4FF */  sd         $20, 0x20($29)
    /* 3E5E9C 004E5E9C 04004016 */  bnez       $18, .L004E5EB0
    /* 3E5EA0 004E5EA0 2800BFFF */   sd        $31, 0x28($29)
    /* 3E5EA4 004E5EA4 7600053C */  lui        $5, %hi(D_0075B0F0)
    /* 3E5EA8 004E5EA8 0F000010 */  b          .L004E5EE8
    /* 3E5EAC 004E5EAC F0B0A524 */   addiu     $5, $5, %lo(D_0075B0F0)
  .L004E5EB0:
    /* 3E5EB0 004E5EB0 0500C010 */  beqz       $6, .L004E5EC8
    /* 3E5EB4 004E5EB4 7600053C */   lui       $5, %hi(D_0075B118)
    /* 3E5EB8 004E5EB8 2D200000 */  daddu      $4, $0, $0
    /* 3E5EBC 004E5EBC 0A000010 */  b          .L004E5EE8
    /* 3E5EC0 004E5EC0 18B1A524 */   addiu     $5, $5, %lo(D_0075B118)
    /* 3E5EC4 004E5EC4 00000000 */  nop
  .L004E5EC8:
    /* 3E5EC8 004E5EC8 8A97130C */  jal        func_004e5e28
    /* 3E5ECC 004E5ECC 00000000 */   nop
    /* 3E5ED0 004E5ED0 2D884000 */  daddu      $17, $2, $0
    /* 3E5ED4 004E5ED4 08002016 */  bnez       $17, .L004E5EF8
    /* 3E5ED8 004E5ED8 20003326 */   addiu     $19, $17, 0x20
    /* 3E5EDC 004E5EDC 7600053C */  lui        $5, %hi(D_0075B140)
    /* 3E5EE0 004E5EE0 2D200000 */  daddu      $4, $0, $0
    /* 3E5EE4 004E5EE4 40B1A524 */  addiu      $5, $5, %lo(D_0075B140)
  .L004E5EE8:
    /* 3E5EE8 004E5EE8 8E96130C */  jal        func_004e5a38
    /* 3E5EEC 004E5EEC 00000000 */   nop
    /* 3E5EF0 004E5EF0 39000010 */  b          .L004E5FD8
    /* 3E5EF4 004E5EF4 2D100000 */   daddu     $2, $0, $0
  .L004E5EF8:
    /* 3E5EF8 004E5EF8 2D204002 */  daddu      $4, $18, $0
    /* 3E5EFC 004E5EFC AC9B130C */  jal        func_004e6eb0
    /* 3E5F00 004E5F00 2D286002 */   daddu     $5, $19, $0
    /* 3E5F04 004E5F04 2400258E */  lw         $5, 0x24($17)
    /* 3E5F08 004E5F08 1F00A014 */  bnez       $5, .L004E5F88
    /* 3E5F0C 004E5F0C 2DA04000 */   daddu     $20, $2, $0
    /* 3E5F10 004E5F10 7300103C */  lui        $16, %hi(D_00733C80)
    /* 3E5F14 004E5F14 2D204002 */  daddu      $4, $18, $0
    /* 3E5F18 004E5F18 803C1026 */  addiu      $16, $16, %lo(D_00733C80)
    /* 3E5F1C 004E5F1C 9099130C */  jal        func_004e6640
    /* 3E5F20 004E5F20 2D280002 */   daddu     $5, $16, $0
    /* 3E5F24 004E5F24 7600043C */  lui        $4, %hi(D_0075B170)
    /* 3E5F28 004E5F28 2D280002 */  daddu      $5, $16, $0
    /* 3E5F2C 004E5F2C FC34130C */  jal        func_004cd3f0
    /* 3E5F30 004E5F30 70B18424 */   addiu     $4, $4, %lo(D_0075B170)
    /* 3E5F34 004E5F34 8691130C */  jal        func_004e4618
    /* 3E5F38 004E5F38 00830434 */   ori       $4, $0, 0x8300
    /* 3E5F3C 004E5F3C F2B9100C */  jal        func_0042e7c8
    /* 3E5F40 004E5F40 2D200000 */   daddu     $4, $0, $0
    /* 3E5F44 004E5F44 8691130C */  jal        func_004e4618
    /* 3E5F48 004E5F48 01830434 */   ori       $4, $0, 0x8301
    /* 3E5F4C 004E5F4C 2D206002 */  daddu      $4, $19, $0
    /* 3E5F50 004E5F50 9A96130C */  jal        func_004e5a68
    /* 3E5F54 004E5F54 2D280002 */   daddu     $5, $16, $0
    /* 3E5F58 004E5F58 09004054 */  bnel       $2, $0, .L004E5F80
    /* 3E5F5C 004E5F5C 010020A2 */   sb        $0, 0x1($17)
    /* 3E5F60 004E5F60 7600053C */  lui        $5, %hi(D_0075B198)
    /* 3E5F64 004E5F64 2D200000 */  daddu      $4, $0, $0
    /* 3E5F68 004E5F68 8E96130C */  jal        func_004e5a38
    /* 3E5F6C 004E5F6C 98B1A524 */   addiu     $5, $5, %lo(D_0075B198)
    /* 3E5F70 004E5F70 9897130C */  jal        func_004e5e60
    /* 3E5F74 004E5F74 2D202002 */   daddu     $4, $17, $0
    /* 3E5F78 004E5F78 17000010 */  b          .L004E5FD8
    /* 3E5F7C 004E5F7C 2D100000 */   daddu     $2, $0, $0
  .L004E5F80:
    /* 3E5F80 004E5F80 03000010 */  b          .L004E5F90
    /* 3E5F84 004E5F84 2400258E */   lw        $5, 0x24($17)
  .L004E5F88:
    /* 3E5F88 004E5F88 01000224 */  addiu      $2, $0, 0x1
    /* 3E5F8C 004E5F8C 010022A2 */  sb         $2, 0x1($17)
  .L004E5F90:
    /* 3E5F90 004E5F90 FF07A224 */  addiu      $2, $5, 0x7FF
    /* 3E5F94 004E5F94 01000324 */  addiu      $3, $0, 0x1
    /* 3E5F98 004E5F98 C2120200 */  srl        $2, $2, 11
    /* 3E5F9C 004E5F9C 01000424 */  addiu      $4, $0, 0x1
    /* 3E5FA0 004E5FA0 080022AE */  sw         $2, 0x8($17)
    /* 3E5FA4 004E5FA4 000023A2 */  sb         $3, 0x0($17)
    /* 3E5FA8 004E5FA8 040025AE */  sw         $5, 0x4($17)
    /* 3E5FAC 004E5FAC 0C0020AE */  sw         $0, 0xC($17)
    /* 3E5FB0 004E5FB0 180020AE */  sw         $0, 0x18($17)
    /* 3E5FB4 004E5FB4 100020AE */  sw         $0, 0x10($17)
    /* 3E5FB8 004E5FB8 140020AE */  sw         $0, 0x14($17)
    /* 3E5FBC 004E5FBC 020020A2 */  sb         $0, 0x2($17)
    /* 3E5FC0 004E5FC0 04008416 */  bne        $20, $4, .L004E5FD4
    /* 3E5FC4 004E5FC4 1C0020AE */   sw        $0, 0x1C($17)
    /* 3E5FC8 004E5FC8 FF7F023C */  lui        $2, (0x7FFFFFFF >> 16)
    /* 3E5FCC 004E5FCC FFFF4234 */  ori        $2, $2, (0x7FFFFFFF & 0xFFFF)
    /* 3E5FD0 004E5FD0 080022AE */  sw         $2, 0x8($17)
  .L004E5FD4:
    /* 3E5FD4 004E5FD4 2D102002 */  daddu      $2, $17, $0
  .L004E5FD8:
    /* 3E5FD8 004E5FD8 0000B0DF */  ld         $16, 0x0($29)
    /* 3E5FDC 004E5FDC 0800B1DF */  ld         $17, 0x8($29)
    /* 3E5FE0 004E5FE0 1000B2DF */  ld         $18, 0x10($29)
    /* 3E5FE4 004E5FE4 1800B3DF */  ld         $19, 0x18($29)
    /* 3E5FE8 004E5FE8 2000B4DF */  ld         $20, 0x20($29)
    /* 3E5FEC 004E5FEC 2800BFDF */  ld         $31, 0x28($29)
    /* 3E5FF0 004E5FF0 0800E003 */  jr         $31
    /* 3E5FF4 004E5FF4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004e5e80, 0x178
