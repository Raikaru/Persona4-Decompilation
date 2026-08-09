.section .text
.set noat
.set noreorder
glabel func_003bfdf0
    /* 2BFDF0 003BFDF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2BFDF4 003BFDF4 3C00063C */  lui        $6, %hi(func_003bf1a0)
    /* 2BFDF8 003BFDF8 3C00073C */  lui        $7, %hi(func_003bf1c0)
    /* 2BFDFC 003BFDFC 0000BFFF */  sd         $31, 0x0($29)
    /* 2BFE00 003BFE00 0C000424 */  addiu      $4, $0, 0xC
    /* 2BFE04 003BFE04 10000524 */  addiu      $5, $0, 0x10
    /* 2BFE08 003BFE08 A0F1C624 */  addiu      $6, $6, %lo(func_003bf1a0)
    /* 2BFE0C 003BFE0C C0F1E724 */  addiu      $7, $7, %lo(func_003bf1c0)
    /* 2BFE10 003BFE10 04A10F0C */  jal        func_003e8410
    /* 2BFE14 003BFE14 2D400000 */   daddu     $8, $0, $0
    /* 2BFE18 003BFE18 03004104 */  bgez       $2, .L003BFE28
    /* 2BFE1C 003BFE1C B0B682AF */   sw        $2, -0x4950($28)
    /* 2BFE20 003BFE20 0C000010 */  b          .L003BFE54
    /* 2BFE24 003BFE24 2D100000 */   daddu     $2, $0, $0
  .L003BFE28:
    /* 2BFE28 003BFE28 3C00063C */  lui        $6, %hi(func_003bf1d0)
    /* 2BFE2C 003BFE2C 3C00073C */  lui        $7, %hi(func_003bf1f0)
    /* 2BFE30 003BFE30 0C000424 */  addiu      $4, $0, 0xC
    /* 2BFE34 003BFE34 10000524 */  addiu      $5, $0, 0x10
    /* 2BFE38 003BFE38 D0F1C624 */  addiu      $6, $6, %lo(func_003bf1d0)
    /* 2BFE3C 003BFE3C F0F1E724 */  addiu      $7, $7, %lo(func_003bf1f0)
    /* 2BFE40 003BFE40 480E0F0C */  jal        func_003c3920
    /* 2BFE44 003BFE44 2D400000 */   daddu     $8, $0, $0
    /* 2BFE48 003BFE48 B4B682AF */  sw         $2, -0x494C($28)
    /* 2BFE4C 003BFE4C 2A104000 */  slt        $2, $2, $0
    /* 2BFE50 003BFE50 01004238 */  xori       $2, $2, 0x1
  .L003BFE54:
    /* 2BFE54 003BFE54 0000BFDF */  ld         $31, 0x0($29)
    /* 2BFE58 003BFE58 0800E003 */  jr         $31
    /* 2BFE5C 003BFE5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_003bfdf0, 0x70
