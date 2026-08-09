.section .text
.set noat
.set noreorder
glabel func_003dd990
    /* 2DD990 003DD990 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2DD994 003DD994 8800023C */  lui        $2, %hi(D_00887180)
    /* 2DD998 003DD998 3000BFFF */  sd         $31, 0x30($29)
    /* 2DD99C 003DD99C 2000B27F */  sq         $18, 0x20($29)
    /* 2DD9A0 003DD9A0 1000B17F */  sq         $17, 0x10($29)
    /* 2DD9A4 003DD9A4 0000B07F */  sq         $16, 0x0($29)
    /* 2DD9A8 003DD9A8 8071518C */  lw         $17, %lo(D_00887180)($2)
    /* 2DD9AC 003DD9AC 0E002012 */  beqz       $17, .L003DD9E8
    /* 2DD9B0 003DD9B0 2D908000 */   daddu     $18, $4, $0
    /* 2DD9B4 003DD9B4 8800103C */  lui        $16, %hi(D_008873C8)
    /* 2DD9B8 003DD9B8 C8731026 */  addiu      $16, $16, %lo(D_008873C8)
  .L003DD9BC:
    /* 2DD9BC 003DD9BC 0000028E */  lw         $2, 0x0($16)
    /* 2DD9C0 003DD9C0 50002426 */  addiu      $4, $17, 0x50
    /* 2DD9C4 003DD9C4 09F84000 */  jalr       $2
    /* 2DD9C8 003DD9C8 2D284002 */   daddu     $5, $18, $0
    /* 2DD9CC 003DD9CC 03004014 */  bnez       $2, .L003DD9DC
    /* 2DD9D0 003DD9D0 00000000 */   nop
    /* 2DD9D4 003DD9D4 0B000010 */  b          .L003DDA04
    /* 2DD9D8 003DD9D8 00000000 */   nop
  .L003DD9DC:
    /* 2DD9DC 003DD9DC 0000318E */  lw         $17, 0x0($17)
    /* 2DD9E0 003DD9E0 F6FF2016 */  bnez       $17, .L003DD9BC
    /* 2DD9E4 003DD9E4 00000000 */   nop
  .L003DD9E8:
    /* 2DD9E8 003DD9E8 8800023C */  lui        $2, %hi(D_00887194)
    /* 2DD9EC 003DD9EC 9471428C */  lw         $2, %lo(D_00887194)($2)
    /* 2DD9F0 003DD9F0 03004010 */  beqz       $2, .L003DDA00
    /* 2DD9F4 003DD9F4 00000000 */   nop
    /* 2DD9F8 003DD9F8 09F84000 */  jalr       $2
    /* 2DD9FC 003DD9FC 06000424 */   addiu     $4, $0, 0x6
  .L003DDA00:
    /* 2DDA00 003DDA00 2D880000 */  daddu      $17, $0, $0
  .L003DDA04:
    /* 2DDA04 003DDA04 09002012 */  beqz       $17, .L003DDA2C
    /* 2DDA08 003DDA08 00000000 */   nop
    /* 2DDA0C 003DDA0C 8800023C */  lui        $2, %hi(D_00887194)
    /* 2DDA10 003DDA10 9471428C */  lw         $2, %lo(D_00887194)($2)
    /* 2DDA14 003DDA14 03004010 */  beqz       $2, .L003DDA24
    /* 2DDA18 003DDA18 00000000 */   nop
    /* 2DDA1C 003DDA1C 09F84000 */  jalr       $2
    /* 2DDA20 003DDA20 07000424 */   addiu     $4, $0, 0x7
  .L003DDA24:
    /* 2DDA24 003DDA24 02000010 */  b          .L003DDA30
    /* 2DDA28 003DDA28 01000224 */   addiu     $2, $0, 0x1
  .L003DDA2C:
    /* 2DDA2C 003DDA2C 2D100000 */  daddu      $2, $0, $0
  .L003DDA30:
    /* 2DDA30 003DDA30 3000BFDF */  ld         $31, 0x30($29)
    /* 2DDA34 003DDA34 2000B27B */  lq         $18, 0x20($29)
    /* 2DDA38 003DDA38 1000B17B */  lq         $17, 0x10($29)
    /* 2DDA3C 003DDA3C 0000B07B */  lq         $16, 0x0($29)
    /* 2DDA40 003DDA40 0800E003 */  jr         $31
    /* 2DDA44 003DDA44 4000BD27 */   addiu     $29, $29, 0x40
    /* 2DDA48 003DDA48 00000000 */  nop
    /* 2DDA4C 003DDA4C 00000000 */  nop
.size func_003dd990, 0xc0
