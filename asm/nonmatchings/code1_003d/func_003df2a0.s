.section .text
.set noat
.set noreorder
glabel func_003df2a0
    /* 2DF2A0 003DF2A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2DF2A4 003DF2A4 1000BFFF */  sd         $31, 0x10($29)
    /* 2DF2A8 003DF2A8 0000B07F */  sq         $16, 0x0($29)
    /* 2DF2AC 003DF2AC 448A0F0C */  jal        func_003e2910
    /* 2DF2B0 003DF2B0 2D808000 */   daddu     $16, $4, $0
    /* 2DF2B4 003DF2B4 03004010 */  beqz       $2, .L003DF2C4
    /* 2DF2B8 003DF2B8 00000000 */   nop
    /* 2DF2BC 003DF2BC 0A000010 */  b          .L003DF2E8
    /* 2DF2C0 003DF2C0 2D100002 */   daddu     $2, $16, $0
  .L003DF2C4:
    /* 2DF2C4 003DF2C4 01000324 */  addiu      $3, $0, 0x1
    /* 2DF2C8 003DF2C8 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2DF2CC 003DF2CC 2800A3AF */  sw         $3, 0x28($29)
    /* 2DF2D0 003DF2D0 647D0F0C */  jal        func_003df590
    /* 2DF2D4 003DF2D4 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2DF2D8 003DF2D8 2C00A2AF */  sw         $2, 0x2C($29)
    /* 2DF2DC 003DF2DC 347D0F0C */  jal        func_003df4d0
    /* 2DF2E0 003DF2E0 2800A427 */   addiu     $4, $29, 0x28
    /* 2DF2E4 003DF2E4 2D100000 */  daddu      $2, $0, $0
  .L003DF2E8:
    /* 2DF2E8 003DF2E8 1000BFDF */  ld         $31, 0x10($29)
    /* 2DF2EC 003DF2EC 0000B07B */  lq         $16, 0x0($29)
    /* 2DF2F0 003DF2F0 0800E003 */  jr         $31
    /* 2DF2F4 003DF2F4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2DF2F8 003DF2F8 00000000 */  nop
    /* 2DF2FC 003DF2FC 00000000 */  nop
.size func_003df2a0, 0x60
