.section .text
.set noat
.set noreorder
glabel func_003df300
    /* 2DF300 003DF300 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2DF304 003DF304 1000BFFF */  sd         $31, 0x10($29)
    /* 2DF308 003DF308 0000B07F */  sq         $16, 0x0($29)
    /* 2DF30C 003DF30C 448A0F0C */  jal        func_003e2910
    /* 2DF310 003DF310 2D808000 */   daddu     $16, $4, $0
    /* 2DF314 003DF314 03004010 */  beqz       $2, .L003DF324
    /* 2DF318 003DF318 00000000 */   nop
    /* 2DF31C 003DF31C 0A000010 */  b          .L003DF348
    /* 2DF320 003DF320 2D100002 */   daddu     $2, $16, $0
  .L003DF324:
    /* 2DF324 003DF324 01000324 */  addiu      $3, $0, 0x1
    /* 2DF328 003DF328 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2DF32C 003DF32C 2800A3AF */  sw         $3, 0x28($29)
    /* 2DF330 003DF330 647D0F0C */  jal        func_003df590
    /* 2DF334 003DF334 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2DF338 003DF338 2C00A2AF */  sw         $2, 0x2C($29)
    /* 2DF33C 003DF33C 347D0F0C */  jal        func_003df4d0
    /* 2DF340 003DF340 2800A427 */   addiu     $4, $29, 0x28
    /* 2DF344 003DF344 2D100000 */  daddu      $2, $0, $0
  .L003DF348:
    /* 2DF348 003DF348 1000BFDF */  ld         $31, 0x10($29)
    /* 2DF34C 003DF34C 0000B07B */  lq         $16, 0x0($29)
    /* 2DF350 003DF350 0800E003 */  jr         $31
    /* 2DF354 003DF354 3000BD27 */   addiu     $29, $29, 0x30
    /* 2DF358 003DF358 00000000 */  nop
    /* 2DF35C 003DF35C 00000000 */  nop
.size func_003df300, 0x60
