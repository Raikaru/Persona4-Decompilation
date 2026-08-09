.section .text
.set noat
.set noreorder
glabel func_004cc490
    /* 3CC490 004CC490 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CC494 004CC494 3000B6FF */  sd         $22, 0x30($29)
    /* 3CC498 004CC498 7200163C */  lui        $22, %hi(D_00719AA0)
    /* 3CC49C 004CC49C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CC4A0 004CC4A0 A09AC326 */  addiu      $3, $22, %lo(D_00719AA0)
    /* 3CC4A4 004CC4A4 0800B1FF */  sd         $17, 0x8($29)
    /* 3CC4A8 004CC4A8 1000B2FF */  sd         $18, 0x10($29)
    /* 3CC4AC 004CC4AC 1800B3FF */  sd         $19, 0x18($29)
    /* 3CC4B0 004CC4B0 2000B4FF */  sd         $20, 0x20($29)
    /* 3CC4B4 004CC4B4 2800B5FF */  sd         $21, 0x28($29)
    /* 3CC4B8 004CC4B8 3800BFFF */  sd         $31, 0x38($29)
    /* 3CC4BC 004CC4BC 000062DC */  ld         $2, 0x0($3)
    /* 3CC4C0 004CC4C0 15004014 */  bnez       $2, .L004CC518
    /* 3CC4C4 004CC4C4 7200153C */   lui       $21, %hi(D_00719A98)
    /* 3CC4C8 004CC4C8 7200143C */  lui        $20, %hi(D_00719A40)
    /* 3CC4CC 004CC4CC 2D986000 */  daddu      $19, $3, $0
    /* 3CC4D0 004CC4D0 989AB226 */  addiu      $18, $21, %lo(D_00719A98)
    /* 3CC4D4 004CC4D4 01001124 */  addiu      $17, $0, 0x1
    /* 3CC4D8 004CC4D8 409A9026 */  addiu      $16, $20, %lo(D_00719A40)
    /* 3CC4DC 004CC4DC 00000000 */  nop
  .L004CC4E0:
    /* 3CC4E0 004CC4E0 000051FE */  sd         $17, 0x0($18)
    /* 3CC4E4 004CC4E4 01000524 */  addiu      $5, $0, 0x1
    /* 3CC4E8 004CC4E8 9C85100C */  jal        func_00421670
    /* 3CC4EC 004CC4EC 0000048E */   lw        $4, 0x0($16)
    /* 3CC4F0 004CC4F0 C485100C */  jal        func_00421710
    /* 3CC4F4 004CC4F4 0000048E */   lw        $4, 0x0($16)
    /* 3CC4F8 004CC4F8 502F130C */  jal        func_004cbd40
    /* 3CC4FC 004CC4FC 0000048E */   lw        $4, 0x0($16)
    /* 3CC500 004CC500 000063DE */  ld         $3, 0x0($19)
    /* 3CC504 004CC504 F6FF6010 */  beqz       $3, .L004CC4E0
    /* 3CC508 004CC508 A09AC226 */   addiu     $2, $22, %lo(D_00719AA0)
    /* 3CC50C 004CC50C 05000010 */  b          .L004CC524
    /* 3CC510 004CC510 3000B6DF */   ld        $22, 0x30($29)
    /* 3CC514 004CC514 00000000 */  nop
  .L004CC518:
    /* 3CC518 004CC518 7200143C */  lui        $20, %hi(D_00719A40)
    /* 3CC51C 004CC51C A09AC226 */  addiu      $2, $22, %lo(D_00719AA0)
    /* 3CC520 004CC520 3000B6DF */  ld         $22, 0x30($29)
  .L004CC524:
    /* 3CC524 004CC524 989AA326 */  addiu      $3, $21, %lo(D_00719A98)
    /* 3CC528 004CC528 2800B5DF */  ld         $21, 0x28($29)
    /* 3CC52C 004CC52C 409A8426 */  addiu      $4, $20, %lo(D_00719A40)
    /* 3CC530 004CC530 2000B4DF */  ld         $20, 0x20($29)
    /* 3CC534 004CC534 0000B0DF */  ld         $16, 0x0($29)
    /* 3CC538 004CC538 0800B1DF */  ld         $17, 0x8($29)
    /* 3CC53C 004CC53C 1000B2DF */  ld         $18, 0x10($29)
    /* 3CC540 004CC540 1800B3DF */  ld         $19, 0x18($29)
    /* 3CC544 004CC544 3800BFDF */  ld         $31, 0x38($29)
    /* 3CC548 004CC548 000040FC */  sd         $0, 0x0($2)
    /* 3CC54C 004CC54C 000060FC */  sd         $0, 0x0($3)
    /* 3CC550 004CC550 000080AC */  sw         $0, 0x0($4)
    /* 3CC554 004CC554 0800E003 */  jr         $31
    /* 3CC558 004CC558 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CC55C 004CC55C 00000000 */  nop
.size func_004cc490, 0xd0
