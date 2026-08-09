.section .text
.set noat
.set noreorder
glabel func_003e1cb0
    /* 2E1CB0 003E1CB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2E1CB4 003E1CB4 2000BFFF */  sd         $31, 0x20($29)
    /* 2E1CB8 003E1CB8 1000B17F */  sq         $17, 0x10($29)
    /* 2E1CBC 003E1CBC 0000B07F */  sq         $16, 0x0($29)
    /* 2E1CC0 003E1CC0 2D80A000 */  daddu      $16, $5, $0
    /* 2E1CC4 003E1CC4 0F000016 */  bnez       $16, .L003E1D04
    /* 2E1CC8 003E1CC8 2D888000 */   daddu     $17, $4, $0
    /* 2E1CCC 003E1CCC 0C0020AE */  sw         $0, 0xC($17)
  .L003E1CD0:
    /* 2E1CD0 003E1CD0 10002426 */  addiu      $4, $17, 0x10
    /* 2E1CD4 003E1CD4 18002326 */  addiu      $3, $17, 0x18
    /* 2E1CD8 003E1CD8 100024AE */  sw         $4, 0x10($17)
    /* 2E1CDC 003E1CDC 2D102002 */  daddu      $2, $17, $0
    /* 2E1CE0 003E1CE0 140024AE */  sw         $4, 0x14($17)
    /* 2E1CE4 003E1CE4 180023AE */  sw         $3, 0x18($17)
    /* 2E1CE8 003E1CE8 1C0023AE */  sw         $3, 0x1C($17)
    /* 2E1CEC 003E1CEC 240024AE */  sw         $4, 0x24($17)
    /* 2E1CF0 003E1CF0 200023AE */  sw         $3, 0x20($17)
    /* 2E1CF4 003E1CF4 000030AE */  sw         $16, 0x0($17)
    /* 2E1CF8 003E1CF8 040020AE */  sw         $0, 0x4($17)
    /* 2E1CFC 003E1CFC 27000010 */  b          .L003E1D9C
    /* 2E1D00 003E1D00 080020AE */   sw        $0, 0x8($17)
  .L003E1D04:
    /* 2E1D04 003E1D04 0400023C */  lui        $2, (0x4040B >> 16)
    /* 2E1D08 003E1D08 0B044534 */  ori        $5, $2, (0x4040B & 0xFFFF)
    /* 2E1D0C 003E1D0C 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2E1D10 003E1D10 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2E1D14 003E1D14 09F84000 */  jalr       $2
    /* 2E1D18 003E1D18 2D200002 */   daddu     $4, $16, $0
    /* 2E1D1C 003E1D1C 0C0022AE */  sw         $2, 0xC($17)
    /* 2E1D20 003E1D20 0C00248E */  lw         $4, 0xC($17)
    /* 2E1D24 003E1D24 13008010 */  beqz       $4, .L003E1D74
    /* 2E1D28 003E1D28 00000000 */   nop
    /* 2E1D2C 003E1D2C 2C910F0C */  jal        func_003e44b0
    /* 2E1D30 003E1D30 2D280002 */   daddu     $5, $16, $0
    /* 2E1D34 003E1D34 E6FF4014 */  bnez       $2, .L003E1CD0
    /* 2E1D38 003E1D38 00000000 */   nop
    /* 2E1D3C 003E1D3C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2E1D40 003E1D40 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2E1D44 003E1D44 09F84000 */  jalr       $2
    /* 2E1D48 003E1D48 0C00248E */   lw        $4, 0xC($17)
    /* 2E1D4C 003E1D4C 01000224 */  addiu      $2, $0, 0x1
    /* 2E1D50 003E1D50 0C000424 */  addiu      $4, $0, 0xC
    /* 2E1D54 003E1D54 3000A2AF */  sw         $2, 0x30($29)
    /* 2E1D58 003E1D58 647D0F0C */  jal        func_003df590
    /* 2E1D5C 003E1D5C 2D280000 */   daddu     $5, $0, $0
    /* 2E1D60 003E1D60 3400A2AF */  sw         $2, 0x34($29)
    /* 2E1D64 003E1D64 347D0F0C */  jal        func_003df4d0
    /* 2E1D68 003E1D68 3000A427 */   addiu     $4, $29, 0x30
    /* 2E1D6C 003E1D6C 0B000010 */  b          .L003E1D9C
    /* 2E1D70 003E1D70 2D100000 */   daddu     $2, $0, $0
  .L003E1D74:
    /* 2E1D74 003E1D74 01000224 */  addiu      $2, $0, 0x1
    /* 2E1D78 003E1D78 2D280002 */  daddu      $5, $16, $0
    /* 2E1D7C 003E1D7C 3800A2AF */  sw         $2, 0x38($29)
    /* 2E1D80 003E1D80 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2E1D84 003E1D84 647D0F0C */  jal        func_003df590
    /* 2E1D88 003E1D88 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2E1D8C 003E1D8C 3C00A2AF */  sw         $2, 0x3C($29)
    /* 2E1D90 003E1D90 347D0F0C */  jal        func_003df4d0
    /* 2E1D94 003E1D94 3800A427 */   addiu     $4, $29, 0x38
    /* 2E1D98 003E1D98 2D100000 */  daddu      $2, $0, $0
  .L003E1D9C:
    /* 2E1D9C 003E1D9C 2000BFDF */  ld         $31, 0x20($29)
    /* 2E1DA0 003E1DA0 1000B17B */  lq         $17, 0x10($29)
    /* 2E1DA4 003E1DA4 0000B07B */  lq         $16, 0x0($29)
    /* 2E1DA8 003E1DA8 0800E003 */  jr         $31
    /* 2E1DAC 003E1DAC 4000BD27 */   addiu     $29, $29, 0x40
.size func_003e1cb0, 0x100
