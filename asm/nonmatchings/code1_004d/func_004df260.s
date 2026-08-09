.section .text
.set noat
.set noreorder
glabel func_004df260
    /* 3DF260 004DF260 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DF264 004DF264 0000B0FF */  sd         $16, 0x0($29)
    /* 3DF268 004DF268 2D808000 */  daddu      $16, $4, $0
    /* 3DF26C 004DF26C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DF270 004DF270 2D88A000 */  daddu      $17, $5, $0
    /* 3DF274 004DF274 08000016 */  bnez       $16, .L004DF298
    /* 3DF278 004DF278 1000BFFF */   sd        $31, 0x10($29)
    /* 3DF27C 004DF27C 7600043C */  lui        $4, %hi(D_007599E0)
    /* 3DF280 004DF280 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF284 004DF284 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF288 004DF288 E0998424 */  addiu      $4, $4, %lo(D_007599E0)
    /* 3DF28C 004DF28C 1000BFDF */  ld         $31, 0x10($29)
    /* 3DF290 004DF290 B0781308 */  j          func_004de2c0
    /* 3DF294 004DF294 2000BD27 */   addiu     $29, $29, 0x20
  .L004DF298:
    /* 3DF298 004DF298 867B130C */  jal        func_004dee18
    /* 3DF29C 004DF29C 00000000 */   nop
    /* 3DF2A0 004DF2A0 01000324 */  addiu      $3, $0, 0x1
    /* 3DF2A4 004DF2A4 01000282 */  lb         $2, 0x1($16)
    /* 3DF2A8 004DF2A8 2D200002 */  daddu      $4, $16, $0
    /* 3DF2AC 004DF2AC 2D282002 */  daddu      $5, $17, $0
    /* 3DF2B0 004DF2B0 07004310 */  beq        $2, $3, .L004DF2D0
    /* 3DF2B4 004DF2B4 A80111AE */   sw        $17, 0x1A8($16)
    /* 3DF2B8 004DF2B8 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF2BC 004DF2BC 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF2C0 004DF2C0 1000BFDF */  ld         $31, 0x10($29)
    /* 3DF2C4 004DF2C4 16801308 */  j          func_004e0058
    /* 3DF2C8 004DF2C8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF2CC 004DF2CC 00000000 */  nop
  .L004DF2D0:
    /* 3DF2D0 004DF2D0 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF2D4 004DF2D4 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF2D8 004DF2D8 1000BFDF */  ld         $31, 0x10($29)
    /* 3DF2DC 004DF2DC 0800E003 */  jr         $31
    /* 3DF2E0 004DF2E0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF2E4 004DF2E4 00000000 */  nop
.size func_004df260, 0x88
