.section .text
.set noat
.set noreorder
glabel func_004f2e80
    /* 3F2E80 004F2E80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3F2E84 004F2E84 1000B2FF */  sd         $18, 0x10($29)
    /* 3F2E88 004F2E88 2D908000 */  daddu      $18, $4, $0
    /* 3F2E8C 004F2E8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F2E90 004F2E90 0800B1FF */  sd         $17, 0x8($29)
    /* 3F2E94 004F2E94 1800B3FF */  sd         $19, 0x18($29)
    /* 3F2E98 004F2E98 2000B4FF */  sd         $20, 0x20($29)
    /* 3F2E9C 004F2E9C 06004016 */  bnez       $18, .L004F2EB8
    /* 3F2EA0 004F2EA0 2800BFFF */   sd        $31, 0x28($29)
    /* 3F2EA4 004F2EA4 01000224 */  addiu      $2, $0, 0x1
    /* 3F2EA8 004F2EA8 2300A214 */  bne        $5, $2, .L004F2F38
    /* 3F2EAC 004F2EAC 2D100000 */   daddu     $2, $0, $0
    /* 3F2EB0 004F2EB0 06000010 */  b          .L004F2ECC
    /* 3F2EB4 004F2EB4 00000000 */   nop
  .L004F2EB8:
    /* 3F2EB8 004F2EB8 7600053C */  lui        $5, %hi(D_0075D6C0)
    /* 3F2EBC 004F2EBC BA09110C */  jal        func_004426e8
    /* 3F2EC0 004F2EC0 C0D6A524 */   addiu     $5, $5, %lo(D_0075D6C0)
    /* 3F2EC4 004F2EC4 0A004014 */  bnez       $2, .L004F2EF0
    /* 3F2EC8 004F2EC8 7400033C */   lui       $3, %hi(D_00743A50)
  .L004F2ECC:
    /* 3F2ECC 004F2ECC FECF130C */  jal        func_004f3ff8
    /* 3F2ED0 004F2ED0 00000000 */   nop
    /* 3F2ED4 004F2ED4 2D904000 */  daddu      $18, $2, $0
    /* 3F2ED8 004F2ED8 05004016 */  bnez       $18, .L004F2EF0
    /* 3F2EDC 004F2EDC 7400033C */   lui       $3, %hi(D_00743A50)
    /* 3F2EE0 004F2EE0 16000010 */  b          .L004F2F3C
    /* 3F2EE4 004F2EE4 0000B0DF */   ld        $16, 0x0($29)
  .L004F2EE8:
    /* 3F2EE8 004F2EE8 13000010 */  b          .L004F2F38
    /* 3F2EEC 004F2EEC 2D102002 */   daddu     $2, $17, $0
  .L004F2EF0:
    /* 3F2EF0 004F2EF0 2DA00000 */  daddu      $20, $0, $0
    /* 3F2EF4 004F2EF4 503A628C */  lw         $2, %lo(D_00743A50)($3)
    /* 3F2EF8 004F2EF8 0800538C */  lw         $19, 0x8($2)
    /* 3F2EFC 004F2EFC 0D00601A */  blez       $19, .L004F2F34
    /* 3F2F00 004F2F00 2800458C */   lw        $5, 0x28($2)
    /* 3F2F04 004F2F04 2D88A000 */  daddu      $17, $5, $0
    /* 3F2F08 004F2F08 1600B024 */  addiu      $16, $5, 0x16
    /* 3F2F0C 004F2F0C 00000000 */  nop
  .L004F2F10:
    /* 3F2F10 004F2F10 2D280002 */  daddu      $5, $16, $0
    /* 3F2F14 004F2F14 34001026 */  addiu      $16, $16, 0x34
    /* 3F2F18 004F2F18 BA09110C */  jal        func_004426e8
    /* 3F2F1C 004F2F1C 2D204002 */   daddu     $4, $18, $0
    /* 3F2F20 004F2F20 F1FF4010 */  beqz       $2, .L004F2EE8
    /* 3F2F24 004F2F24 01009426 */   addiu     $20, $20, 0x1
    /* 3F2F28 004F2F28 2A109302 */  slt        $2, $20, $19
    /* 3F2F2C 004F2F2C F8FF4014 */  bnez       $2, .L004F2F10
    /* 3F2F30 004F2F30 34003126 */   addiu     $17, $17, 0x34
  .L004F2F34:
    /* 3F2F34 004F2F34 2D100000 */  daddu      $2, $0, $0
  .L004F2F38:
    /* 3F2F38 004F2F38 0000B0DF */  ld         $16, 0x0($29)
  .L004F2F3C:
    /* 3F2F3C 004F2F3C 0800B1DF */  ld         $17, 0x8($29)
    /* 3F2F40 004F2F40 1000B2DF */  ld         $18, 0x10($29)
    /* 3F2F44 004F2F44 1800B3DF */  ld         $19, 0x18($29)
    /* 3F2F48 004F2F48 2000B4DF */  ld         $20, 0x20($29)
    /* 3F2F4C 004F2F4C 2800BFDF */  ld         $31, 0x28($29)
    /* 3F2F50 004F2F50 0800E003 */  jr         $31
    /* 3F2F54 004F2F54 3000BD27 */   addiu     $29, $29, 0x30
.size func_004f2e80, 0xd8
