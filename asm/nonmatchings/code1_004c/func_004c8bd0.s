.section .text
.set noat
.set noreorder
glabel func_004c8bd0
    /* 3C8BD0 004C8BD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C8BD4 004C8BD4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8BD8 004C8BD8 2D808000 */  daddu      $16, $4, $0
    /* 3C8BDC 004C8BDC 0800B1FF */  sd         $17, 0x8($29)
    /* 3C8BE0 004C8BE0 2D88A000 */  daddu      $17, $5, $0
    /* 3C8BE4 004C8BE4 1000B2FF */  sd         $18, 0x10($29)
    /* 3C8BE8 004C8BE8 2D90C000 */  daddu      $18, $6, $0
    /* 3C8BEC 004C8BEC 1800BFFF */  sd         $31, 0x18($29)
    /* 3C8BF0 004C8BF0 FE47130C */  jal        func_004d1ff8
    /* 3C8BF4 004C8BF4 0400048E */   lw        $4, 0x4($16)
    /* 3C8BF8 004C8BF8 01000324 */  addiu      $3, $0, 0x1
    /* 3C8BFC 004C8BFC 03004310 */  beq        $2, $3, .L004C8C0C
    /* 3C8C00 004C8C00 00000000 */   nop
    /* 3C8C04 004C8C04 B248130C */  jal        func_004d22c8
    /* 3C8C08 004C8C08 0400048E */   lw        $4, 0x4($16)
  .L004C8C0C:
    /* 3C8C0C 004C8C0C 2A15130C */  jal        func_004c54a8
    /* 3C8C10 004C8C10 00000000 */   nop
    /* 3C8C14 004C8C14 1400068E */  lw         $6, 0x14($16)
    /* 3C8C18 004C8C18 0C00028E */  lw         $2, 0xC($16)
    /* 3C8C1C 004C8C1C FFFF0524 */  addiu      $5, $0, -0x1
    /* 3C8C20 004C8C20 3000038E */  lw         $3, 0x30($16)
    /* 3C8C24 004C8C24 23104600 */  subu       $2, $2, $6
    /* 3C8C28 004C8C28 200000AE */  sw         $0, 0x20($16)
    /* 3C8C2C 004C8C2C 2A202202 */  slt        $4, $17, $2
    /* 3C8C30 004C8C30 21186600 */  addu       $3, $3, $6
    /* 3C8C34 004C8C34 0B102402 */  movn       $2, $17, $4
    /* 3C8C38 004C8C38 180003AE */  sw         $3, 0x18($16)
    /* 3C8C3C 004C8C3C 06004014 */  bnez       $2, .L004C8C58
    /* 3C8C40 004C8C40 1C0002AE */   sw        $2, 0x1C($16)
    /* 3C8C44 004C8C44 03000224 */  addiu      $2, $0, 0x3
    /* 3C8C48 004C8C48 010002A2 */  sb         $2, 0x1($16)
    /* 3C8C4C 004C8C4C 17000010 */  b          .L004C8CAC
    /* 3C8C50 004C8C50 2D800000 */   daddu     $16, $0, $0
    /* 3C8C54 004C8C54 00000000 */  nop
  .L004C8C58:
    /* 3C8C58 004C8C58 EA48130C */  jal        func_004d23a8
    /* 3C8C5C 004C8C5C 0400048E */   lw        $4, 0x4($16)
    /* 3C8C60 004C8C60 0400048E */  lw         $4, 0x4($16)
    /* 3C8C64 004C8C64 EA4B130C */  jal        func_004d2fa8
    /* 3C8C68 004C8C68 2D284002 */   daddu     $5, $18, $0
    /* 3C8C6C 004C8C6C 0400048E */  lw         $4, 0x4($16)
    /* 3C8C70 004C8C70 264B130C */  jal        func_004d2c98
    /* 3C8C74 004C8C74 2C00058E */   lw        $5, 0x2C($16)
    /* 3C8C78 004C8C78 02000324 */  addiu      $3, $0, 0x2
    /* 3C8C7C 004C8C7C 010003A2 */  sb         $3, 0x1($16)
    /* 3C8C80 004C8C80 2D280000 */  daddu      $5, $0, $0
    /* 3C8C84 004C8C84 0400048E */  lw         $4, 0x4($16)
    /* 3C8C88 004C8C88 724B130C */  jal        func_004d2dc8
    /* 3C8C8C 004C8C8C 030000A2 */   sb        $0, 0x3($16)
    /* 3C8C90 004C8C90 0400048E */  lw         $4, 0x4($16)
    /* 3C8C94 004C8C94 0E48130C */  jal        func_004d2038
    /* 3C8C98 004C8C98 1400058E */   lw        $5, 0x14($16)
    /* 3C8C9C 004C8C9C 0400048E */  lw         $4, 0x4($16)
    /* 3C8CA0 004C8CA0 6848130C */  jal        func_004d21a0
    /* 3C8CA4 004C8CA4 1C00058E */   lw        $5, 0x1C($16)
    /* 3C8CA8 004C8CA8 1C00108E */  lw         $16, 0x1C($16)
  .L004C8CAC:
    /* 3C8CAC 004C8CAC 3015130C */  jal        func_004c54c0
    /* 3C8CB0 004C8CB0 00000000 */   nop
    /* 3C8CB4 004C8CB4 2D100002 */  daddu      $2, $16, $0
    /* 3C8CB8 004C8CB8 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8CBC 004C8CBC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8CC0 004C8CC0 1000B2DF */  ld         $18, 0x10($29)
    /* 3C8CC4 004C8CC4 1800BFDF */  ld         $31, 0x18($29)
    /* 3C8CC8 004C8CC8 0800E003 */  jr         $31
    /* 3C8CCC 004C8CCC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c8bd0, 0x100
