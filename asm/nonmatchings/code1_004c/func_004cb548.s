.section .text
.set noat
.set noreorder
glabel func_004cb548
    /* 3CB548 004CB548 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CB54C 004CB54C 7200023C */  lui        $2, %hi(D_007199D0)
    /* 3CB550 004CB550 1000B2FF */  sd         $18, 0x10($29)
    /* 3CB554 004CB554 D0995224 */  addiu      $18, $2, %lo(D_007199D0)
    /* 3CB558 004CB558 0000428E */  lw         $2, 0x0($18)
    /* 3CB55C 004CB55C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB560 004CB560 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB564 004CB564 11004014 */  bnez       $2, .L004CB5AC
    /* 3CB568 004CB568 1800BFFF */   sd        $31, 0x18($29)
    /* 3CB56C 004CB56C B485100C */  jal        func_004216d0
    /* 3CB570 004CB570 7200103C */   lui       $16, %hi(D_00719A28)
    /* 3CB574 004CB574 2D884000 */  daddu      $17, $2, $0
    /* 3CB578 004CB578 7200023C */  lui        $2, %hi(D_007199A0)
    /* 3CB57C 004CB57C A099458C */  lw         $5, %lo(D_007199A0)($2)
    /* 3CB580 004CB580 2D202002 */  daddu      $4, $17, $0
    /* 3CB584 004CB584 9C85100C */  jal        func_00421670
    /* 3CB588 004CB588 289A1026 */   addiu     $16, $16, %lo(D_00719A28)
    /* 3CB58C 004CB58C 7200033C */  lui        $3, %hi(D_007212C0)
    /* 3CB590 004CB590 C01262AC */  sw         $2, %lo(D_007212C0)($3)
    /* 3CB594 004CB594 7200053C */  lui        $5, %hi(D_007212C4)
    /* 3CB598 004CB598 0000048E */  lw         $4, 0x0($16)
    /* 3CB59C 004CB59C 502F130C */  jal        func_004cbd40
    /* 3CB5A0 004CB5A0 C412B1AC */   sw        $17, %lo(D_007212C4)($5)
    /* 3CB5A4 004CB5A4 0000038E */  lw         $3, 0x0($16)
    /* 3CB5A8 004CB5A8 0000428E */  lw         $2, 0x0($18)
  .L004CB5AC:
    /* 3CB5AC 004CB5AC 01004224 */  addiu      $2, $2, 0x1
    /* 3CB5B0 004CB5B0 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB5B4 004CB5B4 000042AE */  sw         $2, 0x0($18)
    /* 3CB5B8 004CB5B8 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB5BC 004CB5BC 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB5C0 004CB5C0 1800BFDF */  ld         $31, 0x18($29)
    /* 3CB5C4 004CB5C4 0800E003 */  jr         $31
    /* 3CB5C8 004CB5C8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CB5CC 004CB5CC 00000000 */  nop
.size func_004cb548, 0x88
