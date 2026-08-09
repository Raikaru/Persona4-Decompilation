.section .text
.set noat
.set noreorder
glabel func_004cb988
    /* 3CB988 004CB988 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CB98C 004CB98C 2800B5FF */  sd         $21, 0x28($29)
    /* 3CB990 004CB990 7200153C */  lui        $21, %hi(D_00719A78)
    /* 3CB994 004CB994 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB998 004CB998 789AA226 */  addiu      $2, $21, %lo(D_00719A78)
    /* 3CB99C 004CB99C 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB9A0 004CB9A0 1000B2FF */  sd         $18, 0x10($29)
    /* 3CB9A4 004CB9A4 1800B3FF */  sd         $19, 0x18($29)
    /* 3CB9A8 004CB9A8 2000B4FF */  sd         $20, 0x20($29)
    /* 3CB9AC 004CB9AC 3000B6FF */  sd         $22, 0x30($29)
    /* 3CB9B0 004CB9B0 3800BFFF */  sd         $31, 0x38($29)
    /* 3CB9B4 004CB9B4 000043DC */  ld         $3, 0x0($2)
    /* 3CB9B8 004CB9B8 22006014 */  bnez       $3, .L004CBA44
    /* 3CB9BC 004CB9BC 7200023C */   lui       $2, %hi(D_00719A80)
    /* 3CB9C0 004CB9C0 7200023C */  lui        $2, %hi(D_00719A08)
    /* 3CB9C4 004CB9C4 7200033C */  lui        $3, %hi(D_007199E0)
    /* 3CB9C8 004CB9C8 7200043C */  lui        $4, %hi(D_00719AB4)
    /* 3CB9CC 004CB9CC 0012123C */  lui        $18, (0x120000E0 >> 16)
    /* 3CB9D0 004CB9D0 089A5424 */  addiu      $20, $2, %lo(D_00719A08)
    /* 3CB9D4 004CB9D4 E0997324 */  addiu      $19, $3, %lo(D_007199E0)
    /* 3CB9D8 004CB9D8 B49A9124 */  addiu      $17, $4, %lo(D_00719AB4)
    /* 3CB9DC 004CB9DC 01001624 */  addiu      $22, $0, 0x1
    /* 3CB9E0 004CB9E0 E0005236 */  ori        $18, $18, (0x120000E0 & 0xFFFF)
    /* 3CB9E4 004CB9E4 00000000 */  nop
  .L004CB9E8:
    /* 3CB9E8 004CB9E8 000082DE */  ld         $2, 0x0($20)
    /* 3CB9EC 004CB9EC 00002396 */  lhu        $3, 0x0($17)
    /* 3CB9F0 004CB9F0 01004264 */  daddiu     $2, $2, 0x1
    /* 3CB9F4 004CB9F4 000082FE */  sd         $2, 0x0($20)
    /* 3CB9F8 004CB9F8 03006010 */  beqz       $3, .L004CBA08
    /* 3CB9FC 004CB9FC 000076AE */   sw        $22, 0x0($19)
    /* 3CBA00 004CBA00 00002296 */  lhu        $2, 0x0($17)
    /* 3CBA04 004CBA04 000042FE */  sd         $2, 0x0($18)
  .L004CBA08:
    /* 3CBA08 004CBA08 2CC4130C */  jal        func_004f10b0
    /* 3CBA0C 004CBA0C 00000000 */   nop
    /* 3CBA10 004CBA10 00002396 */  lhu        $3, 0x0($17)
    /* 3CBA14 004CBA14 01006054 */  bnel       $3, $0, .L004CBA1C
    /* 3CBA18 004CBA18 000040FE */   sd        $0, 0x0($18)
  .L004CBA1C:
    /* 3CBA1C 004CBA1C 000060AE */  sw         $0, 0x0($19)
    /* 3CBA20 004CBA20 789AB026 */  addiu      $16, $21, %lo(D_00719A78)
    /* 3CBA24 004CBA24 000002DE */  ld         $2, 0x0($16)
    /* 3CBA28 004CBA28 06004054 */  bnel       $2, $0, .L004CBA44
    /* 3CBA2C 004CBA2C 7200023C */   lui       $2, %hi(D_00719A80)
    /* 3CBA30 004CBA30 4A2F130C */  jal        func_004cbd28
    /* 3CBA34 004CBA34 00000000 */   nop
    /* 3CBA38 004CBA38 000002DE */  ld         $2, 0x0($16)
    /* 3CBA3C 004CBA3C EAFF4010 */  beqz       $2, .L004CB9E8
    /* 3CBA40 004CBA40 7200023C */   lui       $2, %hi(D_00719A80)
  .L004CBA44:
    /* 3CBA44 004CBA44 0000B0DF */  ld         $16, 0x0($29)
    /* 3CBA48 004CBA48 0800B1DF */  ld         $17, 0x8($29)
    /* 3CBA4C 004CBA4C 01000324 */  addiu      $3, $0, 0x1
    /* 3CBA50 004CBA50 1000B2DF */  ld         $18, 0x10($29)
    /* 3CBA54 004CBA54 809A4224 */  addiu      $2, $2, %lo(D_00719A80)
    /* 3CBA58 004CBA58 1800B3DF */  ld         $19, 0x18($29)
    /* 3CBA5C 004CBA5C 2000B4DF */  ld         $20, 0x20($29)
    /* 3CBA60 004CBA60 2800B5DF */  ld         $21, 0x28($29)
    /* 3CBA64 004CBA64 3000B6DF */  ld         $22, 0x30($29)
    /* 3CBA68 004CBA68 3800BFDF */  ld         $31, 0x38($29)
    /* 3CBA6C 004CBA6C 000043FC */  sd         $3, 0x0($2)
    /* 3CBA70 004CBA70 88851008 */  j          func_00421620
    /* 3CBA74 004CBA74 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cb988, 0xf0
