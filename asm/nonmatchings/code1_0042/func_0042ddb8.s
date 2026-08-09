.section .text
.set noat
.set noreorder
glabel func_0042ddb8
    /* 32DDB8 0042DDB8 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 32DDBC 0042DDBC 8000BEFF */  sd         $30, 0x80($29)
    /* 32DDC0 0042DDC0 7000B7FF */  sd         $23, 0x70($29)
    /* 32DDC4 0042DDC4 89001E3C */  lui        $30, %hi(D_00894C94)
    /* 32DDC8 0042DDC8 6000B6FF */  sd         $22, 0x60($29)
    /* 32DDCC 0042DDCC 7100173C */  lui        $23, %hi(D_0070DCD0)
    /* 32DDD0 0042DDD0 5000B5FF */  sd         $21, 0x50($29)
    /* 32DDD4 0042DDD4 7500163C */  lui        $22, %hi(D_00754498)
    /* 32DDD8 0042DDD8 4000B4FF */  sd         $20, 0x40($29)
    /* 32DDDC 0042DDDC 8900153C */  lui        $21, %hi(D_00894C84)
    /* 32DDE0 0042DDE0 3000B3FF */  sd         $19, 0x30($29)
    /* 32DDE4 0042DDE4 7100143C */  lui        $20, %hi(D_0070DD20)
    /* 32DDE8 0042DDE8 2000B2FF */  sd         $18, 0x20($29)
    /* 32DDEC 0042DDEC 7100133C */  lui        $19, %hi(D_0070DCF4)
    /* 32DDF0 0042DDF0 1000B1FF */  sd         $17, 0x10($29)
    /* 32DDF4 0042DDF4 8900123C */  lui        $18, %hi(D_00894C80)
    /* 32DDF8 0042DDF8 9000BFFF */  sd         $31, 0x90($29)
    /* 32DDFC 0042DDFC 7100113C */  lui        $17, %hi(D_0070DD24)
    /* 32DE00 0042DE00 0000B0FF */  sd         $16, 0x0($29)
    /* 32DE04 0042DE04 7100023C */  lui        $2, %hi(D_0070DCE0)
  .L0042DE08:
    /* 32DE08 0042DE08 0886100C */  jal        func_00421820
    /* 32DE0C 0042DE0C E0DC448C */   lw        $4, %lo(D_0070DCE0)($2)
    /* 32DE10 0042DE10 20DD838E */  lw         $3, %lo(D_0070DD20)($20)
    /* 32DE14 0042DE14 FFFF0224 */  addiu      $2, $0, -0x1
    /* 32DE18 0042DE18 08006214 */  bne        $3, $2, .L0042DE3C
    /* 32DE1C 0042DE1C D0DCE28E */   lw        $2, %lo(D_0070DCD0)($23)
    /* 32DE20 0042DE20 F4DC60AE */  sw         $0, %lo(D_0070DCF4)($19)
    /* 32DE24 0042DE24 7100023C */  lui        $2, %hi(D_0070DCD4)
    /* 32DE28 0042DE28 20DD80AE */  sw         $0, %lo(D_0070DD20)($20)
    /* 32DE2C 0042DE2C D4DC40AC */  sw         $0, %lo(D_0070DCD4)($2)
    /* 32DE30 0042DE30 8885100C */  jal        func_00421620
    /* 32DE34 0042DE34 944CC0AF */   sw        $0, %lo(D_00894C94)($30)
    /* 32DE38 0042DE38 D0DCE28E */  lw         $2, %lo(D_0070DCD0)($23)
  .L0042DE3C:
    /* 32DE3C 0042DE3C 04004018 */  blez       $2, .L0042DE50
    /* 32DE40 0042DE40 9844C426 */   addiu     $4, $22, %lo(D_00754498)
    /* 32DE44 0042DE44 804C458E */  lw         $5, %lo(D_00894C80)($18)
    /* 32DE48 0042DE48 3291100C */  jal        func_004244c8
    /* 32DE4C 0042DE4C 24DD268E */   lw        $6, %lo(D_0070DD24)($17)
  .L0042DE50:
    /* 32DE50 0042DE50 804C438E */  lw         $3, %lo(D_00894C80)($18)
    /* 32DE54 0042DE54 09006010 */  beqz       $3, .L0042DE7C
    /* 32DE58 0042DE58 00000000 */   nop
    /* 32DE5C 0042DE5C 24DD228E */  lw         $2, %lo(D_0070DD24)($17)
    /* 32DE60 0042DE60 06004010 */  beqz       $2, .L0042DE7C
    /* 32DE64 0042DE64 00000000 */   nop
    /* 32DE68 0042DE68 2D808003 */  daddu      $16, $28, $0
    /* 32DE6C 0042DE6C 844CBC8E */  lw         $28, %lo(D_00894C84)($21)
    /* 32DE70 0042DE70 09F86000 */  jalr       $3
    /* 32DE74 0042DE74 24DD248E */   lw        $4, %lo(D_0070DD24)($17)
    /* 32DE78 0042DE78 2DE00002 */  daddu      $28, $16, $0
  .L0042DE7C:
    /* 32DE7C 0042DE7C F4DC60AE */  sw         $0, %lo(D_0070DCF4)($19)
    /* 32DE80 0042DE80 E1FF0010 */  b          .L0042DE08
    /* 32DE84 0042DE84 7100023C */   lui       $2, %hi(D_0070DCE0)
    /* 32DE88 0042DE88 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32DE8C 0042DE8C 2D388000 */  daddu      $7, $4, $0
    /* 32DE90 0042DE90 1000B1FF */  sd         $17, 0x10($29)
    /* 32DE94 0042DE94 2D40A000 */  daddu      $8, $5, $0
    /* 32DE98 0042DE98 7100113C */  lui        $17, %hi(D_0070DCD4)
    /* 32DE9C 0042DE9C 0000B0FF */  sd         $16, 0x0($29)
    /* 32DEA0 0042DEA0 D4DC248E */  lw         $4, %lo(D_0070DCD4)($17)
    /* 32DEA4 0042DEA4 01001024 */  addiu      $16, $0, 0x1
    /* 32DEA8 0042DEA8 15008014 */  bnez       $4, .L0042DF00
    /* 32DEAC 0042DEAC 2000BFFF */   sd        $31, 0x20($29)
    /* 32DEB0 0042DEB0 8900023C */  lui        $2, %hi(D_00894C98)
    /* 32DEB4 0042DEB4 4300033C */  lui        $3, %hi(func_0042ddb8)
    /* 32DEB8 0042DEB8 7500053C */  lui        $5, %hi(D_007544C0)
    /* 32DEBC 0042DEBC 984C4224 */  addiu      $2, $2, %lo(D_00894C98)
    /* 32DEC0 0042DEC0 B8DD6324 */  addiu      $3, $3, %lo(func_0042ddb8)
    /* 32DEC4 0042DEC4 C044A524 */  addiu      $5, $5, %lo(D_007544C0)
    /* 32DEC8 0042DEC8 0C0046AC */  sw         $6, 0xC($2)
    /* 32DECC 0042DECC 2D204000 */  daddu      $4, $2, $0
    /* 32DED0 0042DED0 040043AC */  sw         $3, 0x4($2)
    /* 32DED4 0042DED4 080048AC */  sw         $8, 0x8($2)
    /* 32DED8 0042DED8 140047AC */  sw         $7, 0x14($2)
    /* 32DEDC 0042DEDC 200045AC */  sw         $5, 0x20($2)
    /* 32DEE0 0042DEE0 7885100C */  jal        func_004215e0
    /* 32DEE4 0042DEE4 100040AC */   sw        $0, 0x10($2)
    /* 32DEE8 0042DEE8 2D280000 */  daddu      $5, $0, $0
    /* 32DEEC 0042DEEC D4DC22AE */  sw         $2, %lo(D_0070DCD4)($17)
    /* 32DEF0 0042DEF0 488A100C */  jal        func_00422920
    /* 32DEF4 0042DEF4 2D204000 */   daddu     $4, $2, $0
    /* 32DEF8 0042DEF8 05000010 */  b          .L0042DF10
    /* 32DEFC 0042DEFC 2D100002 */   daddu     $2, $16, $0
  .L0042DF00:
    /* 32DF00 0042DF00 2D28E000 */  daddu      $5, $7, $0
    /* 32DF04 0042DF04 9C85100C */  jal        func_00421670
    /* 32DF08 0042DF08 2D800000 */   daddu     $16, $0, $0
    /* 32DF0C 0042DF0C 2D100002 */  daddu      $2, $16, $0
  .L0042DF10:
    /* 32DF10 0042DF10 2000BFDF */  ld         $31, 0x20($29)
    /* 32DF14 0042DF14 1000B1DF */  ld         $17, 0x10($29)
    /* 32DF18 0042DF18 0000B0DF */  ld         $16, 0x0($29)
    /* 32DF1C 0042DF1C 0800E003 */  jr         $31
    /* 32DF20 0042DF20 3000BD27 */   addiu     $29, $29, 0x30
    /* 32DF24 0042DF24 00000000 */  nop
.size func_0042ddb8, 0x170
