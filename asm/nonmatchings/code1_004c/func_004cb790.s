.section .text
.set noat
.set noreorder
glabel func_004cb790
    /* 3CB790 004CB790 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB794 004CB794 7200023C */  lui        $2, %hi(D_00719A48)
    /* 3CB798 004CB798 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB79C 004CB79C 489A4224 */  addiu      $2, $2, %lo(D_00719A48)
    /* 3CB7A0 004CB7A0 0800BFFF */  sd         $31, 0x8($29)
    /* 3CB7A4 004CB7A4 000043DC */  ld         $3, 0x0($2)
    /* 3CB7A8 004CB7A8 08006054 */  bnel       $3, $0, .L004CB7CC
    /* 3CB7AC 004CB7AC 7200023C */   lui       $2, %hi(D_00719A50)
    /* 3CB7B0 004CB7B0 2D804000 */  daddu      $16, $2, $0
    /* 3CB7B4 004CB7B4 00000000 */  nop
  .L004CB7B8:
    /* 3CB7B8 004CB7B8 DE2D130C */  jal        func_004cb778
    /* 3CB7BC 004CB7BC 00000000 */   nop
    /* 3CB7C0 004CB7C0 000002DE */  ld         $2, 0x0($16)
    /* 3CB7C4 004CB7C4 FCFF4010 */  beqz       $2, .L004CB7B8
    /* 3CB7C8 004CB7C8 7200023C */   lui       $2, %hi(D_00719A50)
  .L004CB7CC:
    /* 3CB7CC 004CB7CC 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB7D0 004CB7D0 0800BFDF */  ld         $31, 0x8($29)
    /* 3CB7D4 004CB7D4 01000324 */  addiu      $3, $0, 0x1
    /* 3CB7D8 004CB7D8 509A4224 */  addiu      $2, $2, %lo(D_00719A50)
    /* 3CB7DC 004CB7DC 000043FC */  sd         $3, 0x0($2)
    /* 3CB7E0 004CB7E0 88851008 */  j          func_00421620
    /* 3CB7E4 004CB7E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb790, 0x58
