.section .text
.set noat
.set noreorder
glabel func_003ed960
    /* 2ED960 003ED960 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2ED964 003ED964 5000BFFF */  sd         $31, 0x50($29)
    /* 2ED968 003ED968 4000B47F */  sq         $20, 0x40($29)
    /* 2ED96C 003ED96C 3000B37F */  sq         $19, 0x30($29)
    /* 2ED970 003ED970 2000B27F */  sq         $18, 0x20($29)
    /* 2ED974 003ED974 1000B17F */  sq         $17, 0x10($29)
    /* 2ED978 003ED978 0000B07F */  sq         $16, 0x0($29)
    /* 2ED97C 003ED97C 03009190 */  lbu        $17, 0x3($4)
    /* 2ED980 003ED980 04002332 */  andi       $3, $17, 0x4
    /* 2ED984 003ED984 14006014 */  bnez       $3, .L003ED9D8
    /* 2ED988 003ED988 2DA08000 */   daddu     $20, $4, $0
    /* 2ED98C 003ED98C 9800938E */  lw         $19, 0x98($20)
  .L003ED990:
    /* 2ED990 003ED990 0D006012 */  beqz       $19, .L003ED9C8
    /* 2ED994 003ED994 00000000 */   nop
  .L003ED998:
    /* 2ED998 003ED998 03006292 */  lbu        $2, 0x3($19)
    /* 2ED99C 003ED99C 25902202 */  or         $18, $17, $2
    /* 2ED9A0 003ED9A0 04004232 */  andi       $2, $18, 0x4
    /* 2ED9A4 003ED9A4 19004014 */  bnez       $2, .L003EDA0C
    /* 2ED9A8 003ED9A8 03007026 */   addiu     $16, $19, 0x3
    /* 2ED9AC 003ED9AC 00000000 */  nop
  .L003ED9B0:
    /* 2ED9B0 003ED9B0 9800648E */  lw         $4, 0x98($19)
    /* 2ED9B4 003ED9B4 14B60F0C */  jal        func_003ed850
    /* 2ED9B8 003ED9B8 2D284002 */   daddu     $5, $18, $0
    /* 2ED9BC 003ED9BC 9C00738E */  lw         $19, 0x9C($19)
    /* 2ED9C0 003ED9C0 F5FF6016 */  bnez       $19, .L003ED998
    /* 2ED9C4 003ED9C4 00000000 */   nop
  .L003ED9C8:
    /* 2ED9C8 003ED9C8 FAFF0324 */  addiu      $3, $0, -0x6
    /* 2ED9CC 003ED9CC 24182302 */  and        $3, $17, $3
    /* 2ED9D0 003ED9D0 19000010 */  b          .L003EDA38
    /* 2ED9D4 003ED9D4 030083A2 */   sb        $3, 0x3($20)
  .L003ED9D8:
    /* 2ED9D8 003ED9D8 10008726 */  addiu      $7, $20, 0x10
    /* 2ED9DC 003ED9DC 50008626 */  addiu      $6, $20, 0x50
    /* 2ED9E0 003ED9E0 08000524 */  addiu      $5, $0, 0x8
  .L003ED9E4:
    /* 2ED9E4 003ED9E4 0000E48C */  lw         $4, 0x0($7)
    /* 2ED9E8 003ED9E8 FFFFA524 */  addiu      $5, $5, -0x1
    /* 2ED9EC 003ED9EC 0400E38C */  lw         $3, 0x4($7)
    /* 2ED9F0 003ED9F0 0000C4AC */  sw         $4, 0x0($6)
    /* 2ED9F4 003ED9F4 0800E724 */  addiu      $7, $7, 0x8
    /* 2ED9F8 003ED9F8 0400C3AC */  sw         $3, 0x4($6)
    /* 2ED9FC 003ED9FC F9FFA01C */  bgtz       $5, .L003ED9E4
    /* 2EDA00 003EDA00 0800C624 */   addiu     $6, $6, 0x8
    /* 2EDA04 003EDA04 E2FF0010 */  b          .L003ED990
    /* 2EDA08 003EDA08 9800938E */   lw        $19, 0x98($20)
  .L003EDA0C:
    /* 2EDA0C 003EDA0C 0400628E */  lw         $2, 0x4($19)
    /* 2EDA10 003EDA10 50006426 */  addiu      $4, $19, 0x50
    /* 2EDA14 003EDA14 10006526 */  addiu      $5, $19, 0x10
    /* 2EDA18 003EDA18 7C810F0C */  jal        func_003e05f0
    /* 2EDA1C 003EDA1C 50004624 */   addiu     $6, $2, 0x50
    /* 2EDA20 003EDA20 00000392 */  lbu        $3, 0x0($16)
    /* 2EDA24 003EDA24 FBFF0224 */  addiu      $2, $0, -0x5
    /* 2EDA28 003EDA28 24106200 */  and        $2, $3, $2
    /* 2EDA2C 003EDA2C E0FF0010 */  b          .L003ED9B0
    /* 2EDA30 003EDA30 030062A2 */   sb        $2, 0x3($19)
    /* 2EDA34 003EDA34 00000000 */  nop
  .L003EDA38:
    /* 2EDA38 003EDA38 5000BFDF */  ld         $31, 0x50($29)
    /* 2EDA3C 003EDA3C 4000B47B */  lq         $20, 0x40($29)
    /* 2EDA40 003EDA40 3000B37B */  lq         $19, 0x30($29)
    /* 2EDA44 003EDA44 2000B27B */  lq         $18, 0x20($29)
    /* 2EDA48 003EDA48 1000B17B */  lq         $17, 0x10($29)
    /* 2EDA4C 003EDA4C 0000B07B */  lq         $16, 0x0($29)
    /* 2EDA50 003EDA50 0800E003 */  jr         $31
    /* 2EDA54 003EDA54 6000BD27 */   addiu     $29, $29, 0x60
    /* 2EDA58 003EDA58 00000000 */  nop
    /* 2EDA5C 003EDA5C 00000000 */  nop
.size func_003ed960, 0x100
