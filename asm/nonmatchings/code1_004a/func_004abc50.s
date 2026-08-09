.section .text
.set noat
.set noreorder
glabel func_004abc50
    /* 3ABC50 004ABC50 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3ABC54 004ABC54 2000BFFF */  sd         $31, 0x20($29)
    /* 3ABC58 004ABC58 1000B17F */  sq         $17, 0x10($29)
    /* 3ABC5C 004ABC5C 0000B07F */  sq         $16, 0x0($29)
    /* 3ABC60 004ABC60 2D888000 */  daddu      $17, $4, $0
    /* 3ABC64 004ABC64 2D80A000 */  daddu      $16, $5, $0
    /* 3ABC68 004ABC68 04000010 */  b          .L004ABC7C
    /* 3ABC6C 004ABC6C 00000000 */   nop
  .L004ABC70:
    /* 3ABC70 004ABC70 90BB8297 */  lhu        $2, -0x4470($28)
    /* 3ABC74 004ABC74 01004224 */  addiu      $2, $2, 0x1
    /* 3ABC78 004ABC78 90BB82A7 */  sh         $2, -0x4470($28)
  .L004ABC7C:
    /* 3ABC7C 004ABC7C 06000424 */  addiu      $4, $0, 0x6
    /* 3ABC80 004ABC80 90BB8597 */  lhu        $5, -0x4470($28)
    /* 3ABC84 004ABC84 2D300000 */  daddu      $6, $0, $0
    /* 3ABC88 004ABC88 10DF110C */  jal        func_00477c40
    /* 3ABC8C 004ABC8C 00000000 */   nop
    /* 3ABC90 004ABC90 F7FF4014 */  bnez       $2, .L004ABC70
    /* 3ABC94 004ABC94 00000000 */   nop
    /* 3ABC98 004ABC98 06000424 */  addiu      $4, $0, 0x6
    /* 3ABC9C 004ABC9C 90BB8597 */  lhu        $5, -0x4470($28)
    /* 3ABCA0 004ABCA0 2D302002 */  daddu      $6, $17, $0
    /* 3ABCA4 004ABCA4 2D380002 */  daddu      $7, $16, $0
    /* 3ABCA8 004ABCA8 01000824 */  addiu      $8, $0, 0x1
    /* 3ABCAC 004ABCAC C4DF110C */  jal        func_00477f10
    /* 3ABCB0 004ABCB0 00000000 */   nop
    /* 3ABCB4 004ABCB4 2D804000 */  daddu      $16, $2, $0
    /* 3ABCB8 004ABCB8 2D200002 */  daddu      $4, $16, $0
    /* 3ABCBC 004ABCBC A8E8110C */  jal        func_0047a2a0
    /* 3ABCC0 004ABCC0 00000000 */   nop
    /* 3ABCC4 004ABCC4 2D200002 */  daddu      $4, $16, $0
    /* 3ABCC8 004ABCC8 2D280000 */  daddu      $5, $0, $0
    /* 3ABCCC 004ABCCC 28E7110C */  jal        func_00479ca0
    /* 3ABCD0 004ABCD0 00000000 */   nop
    /* 3ABCD4 004ABCD4 0E004010 */  beqz       $2, .L004ABD10
    /* 3ABCD8 004ABCD8 00000000 */   nop
    /* 3ABCDC 004ABCDC 2D200002 */  daddu      $4, $16, $0
    /* 3ABCE0 004ABCE0 2D280000 */  daddu      $5, $0, $0
    /* 3ABCE4 004ABCE4 2D300000 */  daddu      $6, $0, $0
    /* 3ABCE8 004ABCE8 2D380000 */  daddu      $7, $0, $0
    /* 3ABCEC 004ABCEC 2D400000 */  daddu      $8, $0, $0
    /* 3ABCF0 004ABCF0 50E6110C */  jal        func_00479940
    /* 3ABCF4 004ABCF4 00000000 */   nop
    /* 3ABCF8 004ABCF8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3ABCFC 004ABCFC 00608244 */  mtc1       $2, $f12
    /* 3ABD00 004ABD00 2D200002 */  daddu      $4, $16, $0
    /* 3ABD04 004ABD04 2D280000 */  daddu      $5, $0, $0
    /* 3ABD08 004ABD08 38E8110C */  jal        func_0047a0e0
    /* 3ABD0C 004ABD0C 00000000 */   nop
  .L004ABD10:
    /* 3ABD10 004ABD10 D800038E */  lw         $3, 0xD8($16)
    /* 3ABD14 004ABD14 FDFF0224 */  addiu      $2, $0, -0x3
    /* 3ABD18 004ABD18 24106200 */  and        $2, $3, $2
    /* 3ABD1C 004ABD1C D80002AE */  sw         $2, 0xD8($16)
    /* 3ABD20 004ABD20 2D200002 */  daddu      $4, $16, $0
    /* 3ABD24 004ABD24 4B00053C */  lui        $5, %hi(func_004abe60)
    /* 3ABD28 004ABD28 60BEA524 */  addiu      $5, $5, %lo(func_004abe60)
    /* 3ABD2C 004ABD2C 2D300002 */  daddu      $6, $16, $0
    /* 3ABD30 004ABD30 ACE3110C */  jal        func_00478eb0
    /* 3ABD34 004ABD34 00000000 */   nop
    /* 3ABD38 004ABD38 90BB8297 */  lhu        $2, -0x4470($28)
    /* 3ABD3C 004ABD3C 01004224 */  addiu      $2, $2, 0x1
    /* 3ABD40 004ABD40 90BB82A7 */  sh         $2, -0x4470($28)
    /* 3ABD44 004ABD44 2D100002 */  daddu      $2, $16, $0
    /* 3ABD48 004ABD48 2000BFDF */  ld         $31, 0x20($29)
    /* 3ABD4C 004ABD4C 1000B17B */  lq         $17, 0x10($29)
    /* 3ABD50 004ABD50 0000B07B */  lq         $16, 0x0($29)
    /* 3ABD54 004ABD54 3000BD27 */  addiu      $29, $29, 0x30
    /* 3ABD58 004ABD58 0800E003 */  jr         $31
    /* 3ABD5C 004ABD5C 00000000 */   nop
.size func_004abc50, 0x110
