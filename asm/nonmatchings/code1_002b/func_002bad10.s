.section .text
.set noat
.set noreorder
glabel func_002bad10
    /* 1BAD10 002BAD10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BAD14 002BAD14 2000BFFF */  sd         $31, 0x20($29)
    /* 1BAD18 002BAD18 1000B17F */  sq         $17, 0x10($29)
    /* 1BAD1C 002BAD1C 0000B07F */  sq         $16, 0x0($29)
    /* 1BAD20 002BAD20 2D888000 */  daddu      $17, $4, $0
    /* 1BAD24 002BAD24 DCEF0A0C */  jal        func_002bbf70
    /* 1BAD28 002BAD28 00000000 */   nop
    /* 1BAD2C 002BAD2C 2D804000 */  daddu      $16, $2, $0
    /* 1BAD30 002BAD30 04000016 */  bnez       $16, .L002BAD44
    /* 1BAD34 002BAD34 00000000 */   nop
    /* 1BAD38 002BAD38 2D100000 */  daddu      $2, $0, $0
    /* 1BAD3C 002BAD3C 19000010 */  b          .L002BADA4
    /* 1BAD40 002BAD40 00000000 */   nop
  .L002BAD44:
    /* 1BAD44 002BAD44 0000048E */  lw         $4, 0x0($16)
    /* 1BAD48 002BAD48 04008104 */  bgez       $4, .L002BAD5C
    /* 1BAD4C 002BAD4C 00000000 */   nop
    /* 1BAD50 002BAD50 2D100000 */  daddu      $2, $0, $0
    /* 1BAD54 002BAD54 13000010 */  b          .L002BADA4
    /* 1BAD58 002BAD58 00000000 */   nop
  .L002BAD5C:
    /* 1BAD5C 002BAD5C 2D280000 */  daddu      $5, $0, $0
    /* 1BAD60 002BAD60 84E1090C */  jal        func_00278610
    /* 1BAD64 002BAD64 00000000 */   nop
    /* 1BAD68 002BAD68 0000048E */  lw         $4, 0x0($16)
    /* 1BAD6C 002BAD6C 2000053C */  lui        $5, (0x200000 >> 16)
    /* 1BAD70 002BAD70 5CE0090C */  jal        func_00278170
    /* 1BAD74 002BAD74 00000000 */   nop
    /* 1BAD78 002BAD78 0000048E */  lw         $4, 0x0($16)
    /* 1BAD7C 002BAD7C 2D282002 */  daddu      $5, $17, $0
    /* 1BAD80 002BAD80 2D300000 */  daddu      $6, $0, $0
    /* 1BAD84 002BAD84 30DE090C */  jal        func_002778c0
    /* 1BAD88 002BAD88 00000000 */   nop
    /* 1BAD8C 002BAD8C 0000048E */  lw         $4, 0x0($16)
    /* 1BAD90 002BAD90 FFFF0524 */  addiu      $5, $0, -0x1
    /* 1BAD94 002BAD94 04DC090C */  jal        func_00277010
    /* 1BAD98 002BAD98 00000000 */   nop
    /* 1BAD9C 002BAD9C 01000224 */  addiu      $2, $0, 0x1
    /* 1BADA0 002BADA0 040002A2 */  sb         $2, 0x4($16)
  .L002BADA4:
    /* 1BADA4 002BADA4 2000BFDF */  ld         $31, 0x20($29)
    /* 1BADA8 002BADA8 1000B17B */  lq         $17, 0x10($29)
    /* 1BADAC 002BADAC 0000B07B */  lq         $16, 0x0($29)
    /* 1BADB0 002BADB0 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BADB4 002BADB4 0800E003 */  jr         $31
    /* 1BADB8 002BADB8 00000000 */   nop
    /* 1BADBC 002BADBC 00000000 */  nop
.size func_002bad10, 0xb0
