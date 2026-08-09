.section .text
.set noat
.set noreorder
glabel func_004cbbb0
    /* 3CBBB0 004CBBB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CBBB4 004CBBB4 7200023C */  lui        $2, %hi(D_00719A98)
    /* 3CBBB8 004CBBB8 0000B0FF */  sd         $16, 0x0($29)
    /* 3CBBBC 004CBBBC 989A4524 */  addiu      $5, $2, %lo(D_00719A98)
    /* 3CBBC0 004CBBC0 0800B1FF */  sd         $17, 0x8($29)
    /* 3CBBC4 004CBBC4 1000B2FF */  sd         $18, 0x10($29)
    /* 3CBBC8 004CBBC8 1800B3FF */  sd         $19, 0x18($29)
    /* 3CBBCC 004CBBCC 2000B4FF */  sd         $20, 0x20($29)
    /* 3CBBD0 004CBBD0 2800B5FF */  sd         $21, 0x28($29)
    /* 3CBBD4 004CBBD4 3000BFFF */  sd         $31, 0x30($29)
    /* 3CBBD8 004CBBD8 0000A3DC */  ld         $3, 0x0($5)
    /* 3CBBDC 004CBBDC 1D006014 */  bnez       $3, .L004CBC54
    /* 3CBBE0 004CBBE0 7200023C */   lui       $2, %hi(D_00719AA0)
    /* 3CBBE4 004CBBE4 7200023C */  lui        $2, %hi(D_00719A18)
    /* 3CBBE8 004CBBE8 7200033C */  lui        $3, %hi(D_007199E8)
    /* 3CBBEC 004CBBEC 7200043C */  lui        $4, %hi(D_007199D4)
    /* 3CBBF0 004CBBF0 189A5424 */  addiu      $20, $2, %lo(D_00719A18)
    /* 3CBBF4 004CBBF4 E8997324 */  addiu      $19, $3, %lo(D_007199E8)
    /* 3CBBF8 004CBBF8 D4999224 */  addiu      $18, $4, %lo(D_007199D4)
    /* 3CBBFC 004CBBFC 2DA8A000 */  daddu      $21, $5, $0
    /* 3CBC00 004CBC00 01001124 */  addiu      $17, $0, 0x1
    /* 3CBC04 004CBC04 00000000 */  nop
  .L004CBC08:
    /* 3CBC08 004CBC08 000082DE */  ld         $2, 0x0($20)
    /* 3CBC0C 004CBC0C 01004264 */  daddiu     $2, $2, 0x1
    /* 3CBC10 004CBC10 000082FE */  sd         $2, 0x0($20)
    /* 3CBC14 004CBC14 3EC4130C */  jal        func_004f10f8
    /* 3CBC18 004CBC18 000071AE */   sw        $17, 0x0($19)
    /* 3CBC1C 004CBC1C 000060AE */  sw         $0, 0x0($19)
    /* 3CBC20 004CBC20 2D804000 */  daddu      $16, $2, $0
    /* 3CBC24 004CBC24 0000428E */  lw         $2, 0x0($18)
    /* 3CBC28 004CBC28 03005114 */  bne        $2, $17, .L004CBC38
    /* 3CBC2C 004CBC2C 00000000 */   nop
    /* 3CBC30 004CBC30 4A2F130C */  jal        func_004cbd28
    /* 3CBC34 004CBC34 000040AE */   sw        $0, 0x0($18)
  .L004CBC38:
    /* 3CBC38 004CBC38 03000016 */  bnez       $16, .L004CBC48
    /* 3CBC3C 004CBC3C 00000000 */   nop
    /* 3CBC40 004CBC40 4A2F130C */  jal        func_004cbd28
    /* 3CBC44 004CBC44 00000000 */   nop
  .L004CBC48:
    /* 3CBC48 004CBC48 0000A2DE */  ld         $2, 0x0($21)
    /* 3CBC4C 004CBC4C EEFF4010 */  beqz       $2, .L004CBC08
    /* 3CBC50 004CBC50 7200023C */   lui       $2, %hi(D_00719AA0)
  .L004CBC54:
    /* 3CBC54 004CBC54 0000B0DF */  ld         $16, 0x0($29)
    /* 3CBC58 004CBC58 0800B1DF */  ld         $17, 0x8($29)
    /* 3CBC5C 004CBC5C 01000324 */  addiu      $3, $0, 0x1
    /* 3CBC60 004CBC60 1000B2DF */  ld         $18, 0x10($29)
    /* 3CBC64 004CBC64 A09A4224 */  addiu      $2, $2, %lo(D_00719AA0)
    /* 3CBC68 004CBC68 1800B3DF */  ld         $19, 0x18($29)
    /* 3CBC6C 004CBC6C 2000B4DF */  ld         $20, 0x20($29)
    /* 3CBC70 004CBC70 2800B5DF */  ld         $21, 0x28($29)
    /* 3CBC74 004CBC74 3000BFDF */  ld         $31, 0x30($29)
    /* 3CBC78 004CBC78 000043FC */  sd         $3, 0x0($2)
    /* 3CBC7C 004CBC7C 88851008 */  j          func_00421620
    /* 3CBC80 004CBC80 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CBC84 004CBC84 00000000 */  nop
.size func_004cbbb0, 0xd8
