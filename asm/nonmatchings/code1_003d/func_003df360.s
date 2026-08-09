.section .text
.set noat
.set noreorder
glabel func_003df360
    /* 2DF360 003DF360 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2DF364 003DF364 1000BFFF */  sd         $31, 0x10($29)
    /* 2DF368 003DF368 0000B07F */  sq         $16, 0x0($29)
    /* 2DF36C 003DF36C 448A0F0C */  jal        func_003e2910
    /* 2DF370 003DF370 2D808000 */   daddu     $16, $4, $0
    /* 2DF374 003DF374 03004010 */  beqz       $2, .L003DF384
    /* 2DF378 003DF378 00000000 */   nop
    /* 2DF37C 003DF37C 0A000010 */  b          .L003DF3A8
    /* 2DF380 003DF380 2D100002 */   daddu     $2, $16, $0
  .L003DF384:
    /* 2DF384 003DF384 01000324 */  addiu      $3, $0, 0x1
    /* 2DF388 003DF388 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2DF38C 003DF38C 2800A3AF */  sw         $3, 0x28($29)
    /* 2DF390 003DF390 647D0F0C */  jal        func_003df590
    /* 2DF394 003DF394 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2DF398 003DF398 2C00A2AF */  sw         $2, 0x2C($29)
    /* 2DF39C 003DF39C 347D0F0C */  jal        func_003df4d0
    /* 2DF3A0 003DF3A0 2800A427 */   addiu     $4, $29, 0x28
    /* 2DF3A4 003DF3A4 2D100000 */  daddu      $2, $0, $0
  .L003DF3A8:
    /* 2DF3A8 003DF3A8 1000BFDF */  ld         $31, 0x10($29)
    /* 2DF3AC 003DF3AC 0000B07B */  lq         $16, 0x0($29)
    /* 2DF3B0 003DF3B0 0800E003 */  jr         $31
    /* 2DF3B4 003DF3B4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2DF3B8 003DF3B8 00000000 */  nop
    /* 2DF3BC 003DF3BC 00000000 */  nop
.size func_003df360, 0x60
