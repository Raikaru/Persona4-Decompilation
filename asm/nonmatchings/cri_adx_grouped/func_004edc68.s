.section .text
.set noat
.set noreorder
glabel func_004edc68
    /* 3EDC68 004EDC68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDC6C 004EDC6C 2D408000 */  daddu      $8, $4, $0
    /* 3EDC70 004EDC70 0000BFFF */  sd         $31, 0x0($29)
    /* 3EDC74 004EDC74 08000015 */  bnez       $8, .L004EDC98
    /* 3EDC78 004EDC78 2D18C000 */   daddu     $3, $6, $0
    /* 3EDC7C 004EDC7C 7600043C */  lui        $4, %hi(D_0075CD30)
    /* 3EDC80 004EDC80 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3EDC84 004EDC84 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDC88 004EDC88 30CD8424 */  addiu      $4, $4, %lo(D_0075CD30)
    /* 3EDC8C 004EDC8C 40CCA524 */  addiu      $5, $5, %lo(D_0075CC40)
    /* 3EDC90 004EDC90 2EB51308 */  j          func_004ed4b8
    /* 3EDC94 004EDC94 1000BD27 */   addiu     $29, $29, 0x10
  .L004EDC98:
    /* 3EDC98 004EDC98 0400028D */  lw         $2, 0x4($8)
    /* 3EDC9C 004EDC9C 08004054 */  bnel       $2, $0, .L004EDCC0
    /* 3EDCA0 004EDCA0 0400668C */   lw        $6, 0x4($3)
    /* 3EDCA4 004EDCA4 7600043C */  lui        $4, %hi(D_0075CD40)
    /* 3EDCA8 004EDCA8 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3EDCAC 004EDCAC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDCB0 004EDCB0 40CD8424 */  addiu      $4, $4, %lo(D_0075CD40)
    /* 3EDCB4 004EDCB4 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
    /* 3EDCB8 004EDCB8 2EB51308 */  j          func_004ed4b8
    /* 3EDCBC 004EDCBC 1000BD27 */   addiu     $29, $29, 0x10
  .L004EDCC0:
    /* 3EDCC0 004EDCC0 2600C018 */  blez       $6, .L004EDD5C
    /* 3EDCC4 004EDCC4 0000BFDF */   ld        $31, 0x0($29)
    /* 3EDCC8 004EDCC8 0000698C */  lw         $9, 0x0($3)
    /* 3EDCCC 004EDCCC 23002011 */  beqz       $9, .L004EDD5C
    /* 3EDCD0 004EDCD0 00000000 */   nop
    /* 3EDCD4 004EDCD4 1200A010 */  beqz       $5, .L004EDD20
    /* 3EDCD8 004EDCD8 01000224 */   addiu     $2, $0, 0x1
    /* 3EDCDC 004EDCDC 1800A254 */  bnel       $5, $2, .L004EDD40
    /* 3EDCE0 004EDCE0 1C00028D */   lw        $2, 0x1C($8)
    /* 3EDCE4 004EDCE4 1000048D */  lw         $4, 0x10($8)
    /* 3EDCE8 004EDCE8 0C00058D */  lw         $5, 0xC($8)
    /* 3EDCEC 004EDCEC 23208600 */  subu       $4, $4, $6
    /* 3EDCF0 004EDCF0 1400068D */  lw         $6, 0x14($8)
    /* 3EDCF4 004EDCF4 00008228 */  slti       $2, $4, 0x0
    /* 3EDCF8 004EDCF8 1800078D */  lw         $7, 0x18($8)
    /* 3EDCFC 004EDCFC 0B200200 */  movn       $4, $0, $2
    /* 3EDD00 004EDD00 23302601 */  subu       $6, $9, $6
    /* 3EDD04 004EDD04 100004AD */  sw         $4, 0x10($8)
    /* 3EDD08 004EDD08 0400628C */  lw         $2, 0x4($3)
    /* 3EDD0C 004EDD0C 2128A200 */  addu       $5, $5, $2
    /* 3EDD10 004EDD10 2A18E500 */  slt        $3, $7, $5
    /* 3EDD14 004EDD14 0B28E300 */  movn       $5, $7, $3
    /* 3EDD18 004EDD18 10008610 */  beq        $4, $6, .L004EDD5C
    /* 3EDD1C 004EDD1C 0C0005AD */   sw        $5, 0xC($8)
  .L004EDD20:
    /* 3EDD20 004EDD20 1C00028D */  lw         $2, 0x1C($8)
    /* 3EDD24 004EDD24 0D004050 */  beql       $2, $0, .L004EDD5C
    /* 3EDD28 004EDD28 0000BFDF */   ld        $31, 0x0($29)
    /* 3EDD2C 004EDD2C 2000048D */  lw         $4, 0x20($8)
    /* 3EDD30 004EDD30 09F84000 */  jalr       $2
    /* 3EDD34 004EDD34 FDFF0524 */   addiu     $5, $0, -0x3
    /* 3EDD38 004EDD38 08000010 */  b          .L004EDD5C
    /* 3EDD3C 004EDD3C 0000BFDF */   ld        $31, 0x0($29)
  .L004EDD40:
    /* 3EDD40 004EDD40 000060AC */  sw         $0, 0x0($3)
    /* 3EDD44 004EDD44 04004010 */  beqz       $2, .L004EDD58
    /* 3EDD48 004EDD48 040060AC */   sw        $0, 0x4($3)
    /* 3EDD4C 004EDD4C 2000048D */  lw         $4, 0x20($8)
    /* 3EDD50 004EDD50 09F84000 */  jalr       $2
    /* 3EDD54 004EDD54 FDFF0524 */   addiu     $5, $0, -0x3
  .L004EDD58:
    /* 3EDD58 004EDD58 0000BFDF */  ld         $31, 0x0($29)
  .L004EDD5C:
    /* 3EDD5C 004EDD5C 0800E003 */  jr         $31
    /* 3EDD60 004EDD60 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDD64 004EDD64 00000000 */  nop
.size func_004edc68, 0x100
