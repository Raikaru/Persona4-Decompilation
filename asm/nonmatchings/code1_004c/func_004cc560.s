.section .text
.set noat
.set noreorder
glabel func_004cc560
    /* 3CC560 004CC560 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CC564 004CC564 3000B6FF */  sd         $22, 0x30($29)
    /* 3CC568 004CC568 7200163C */  lui        $22, %hi(D_00719A90)
    /* 3CC56C 004CC56C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CC570 004CC570 909AC326 */  addiu      $3, $22, %lo(D_00719A90)
    /* 3CC574 004CC574 0800B1FF */  sd         $17, 0x8($29)
    /* 3CC578 004CC578 1000B2FF */  sd         $18, 0x10($29)
    /* 3CC57C 004CC57C 1800B3FF */  sd         $19, 0x18($29)
    /* 3CC580 004CC580 2000B4FF */  sd         $20, 0x20($29)
    /* 3CC584 004CC584 2800B5FF */  sd         $21, 0x28($29)
    /* 3CC588 004CC588 3800BFFF */  sd         $31, 0x38($29)
    /* 3CC58C 004CC58C 000062DC */  ld         $2, 0x0($3)
    /* 3CC590 004CC590 15004014 */  bnez       $2, .L004CC5E8
    /* 3CC594 004CC594 7200153C */   lui       $21, %hi(D_00719A88)
    /* 3CC598 004CC598 7200143C */  lui        $20, %hi(D_00719A3C)
    /* 3CC59C 004CC59C 2D986000 */  daddu      $19, $3, $0
    /* 3CC5A0 004CC5A0 889AB226 */  addiu      $18, $21, %lo(D_00719A88)
    /* 3CC5A4 004CC5A4 01001124 */  addiu      $17, $0, 0x1
    /* 3CC5A8 004CC5A8 3C9A9026 */  addiu      $16, $20, %lo(D_00719A3C)
    /* 3CC5AC 004CC5AC 00000000 */  nop
  .L004CC5B0:
    /* 3CC5B0 004CC5B0 000051FE */  sd         $17, 0x0($18)
    /* 3CC5B4 004CC5B4 01000524 */  addiu      $5, $0, 0x1
    /* 3CC5B8 004CC5B8 9C85100C */  jal        func_00421670
    /* 3CC5BC 004CC5BC 0000048E */   lw        $4, 0x0($16)
    /* 3CC5C0 004CC5C0 C485100C */  jal        func_00421710
    /* 3CC5C4 004CC5C4 0000048E */   lw        $4, 0x0($16)
    /* 3CC5C8 004CC5C8 502F130C */  jal        func_004cbd40
    /* 3CC5CC 004CC5CC 0000048E */   lw        $4, 0x0($16)
    /* 3CC5D0 004CC5D0 000063DE */  ld         $3, 0x0($19)
    /* 3CC5D4 004CC5D4 F6FF6010 */  beqz       $3, .L004CC5B0
    /* 3CC5D8 004CC5D8 909AC226 */   addiu     $2, $22, %lo(D_00719A90)
    /* 3CC5DC 004CC5DC 05000010 */  b          .L004CC5F4
    /* 3CC5E0 004CC5E0 3000B6DF */   ld        $22, 0x30($29)
    /* 3CC5E4 004CC5E4 00000000 */  nop
  .L004CC5E8:
    /* 3CC5E8 004CC5E8 7200143C */  lui        $20, %hi(D_00719A3C)
    /* 3CC5EC 004CC5EC 909AC226 */  addiu      $2, $22, %lo(D_00719A90)
    /* 3CC5F0 004CC5F0 3000B6DF */  ld         $22, 0x30($29)
  .L004CC5F4:
    /* 3CC5F4 004CC5F4 889AA326 */  addiu      $3, $21, %lo(D_00719A88)
    /* 3CC5F8 004CC5F8 2800B5DF */  ld         $21, 0x28($29)
    /* 3CC5FC 004CC5FC 3C9A8426 */  addiu      $4, $20, %lo(D_00719A3C)
    /* 3CC600 004CC600 2000B4DF */  ld         $20, 0x20($29)
    /* 3CC604 004CC604 0000B0DF */  ld         $16, 0x0($29)
    /* 3CC608 004CC608 0800B1DF */  ld         $17, 0x8($29)
    /* 3CC60C 004CC60C 1000B2DF */  ld         $18, 0x10($29)
    /* 3CC610 004CC610 1800B3DF */  ld         $19, 0x18($29)
    /* 3CC614 004CC614 3800BFDF */  ld         $31, 0x38($29)
    /* 3CC618 004CC618 000040FC */  sd         $0, 0x0($2)
    /* 3CC61C 004CC61C 000060FC */  sd         $0, 0x0($3)
    /* 3CC620 004CC620 000080AC */  sw         $0, 0x0($4)
    /* 3CC624 004CC624 0800E003 */  jr         $31
    /* 3CC628 004CC628 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CC62C 004CC62C 00000000 */  nop
.size func_004cc560, 0xd0
