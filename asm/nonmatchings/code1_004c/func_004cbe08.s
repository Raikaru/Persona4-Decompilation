.section .text
.set noat
.set noreorder
glabel func_004cbe08
    /* 3CBE08 004CBE08 7200023C */  lui        $2, %hi(D_007212C8)
    /* 3CBE0C 004CBE0C C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CBE10 004CBE10 C812478C */  lw         $7, %lo(D_007212C8)($2)
    /* 3CBE14 004CBE14 7700023C */  lui        $2, %hi(D_007690F0)
    /* 3CBE18 004CBE18 4D00053C */  lui        $5, %hi(func_004cb790)
    /* 3CBE1C 004CBE1C 7200033C */  lui        $3, %hi(D_00719AC0)
    /* 3CBE20 004CBE20 90B7A524 */  addiu      $5, $5, %lo(func_004cb790)
    /* 3CBE24 004CBE24 C09A6324 */  addiu      $3, $3, %lo(D_00719AC0)
    /* 3CBE28 004CBE28 2D20A003 */  daddu      $4, $29, $0
    /* 3CBE2C 004CBE2C 00080624 */  addiu      $6, $0, 0x800
    /* 3CBE30 004CBE30 F0904224 */  addiu      $2, $2, %lo(D_007690F0)
    /* 3CBE34 004CBE34 3000B0FF */  sd         $16, 0x30($29)
    /* 3CBE38 004CBE38 0400A5AF */  sw         $5, 0x4($29)
    /* 3CBE3C 004CBE3C 0800A3AF */  sw         $3, 0x8($29)
    /* 3CBE40 004CBE40 3800BFFF */  sd         $31, 0x38($29)
    /* 3CBE44 004CBE44 0C00A6AF */  sw         $6, 0xC($29)
    /* 3CBE48 004CBE48 1400A7AF */  sw         $7, 0x14($29)
    /* 3CBE4C 004CBE4C 7885100C */  jal        func_004215e0
    /* 3CBE50 004CBE50 1000A2AF */   sw        $2, 0x10($29)
    /* 3CBE54 004CBE54 7200033C */  lui        $3, %hi(D_00719A28)
    /* 3CBE58 004CBE58 2D280000 */  daddu      $5, $0, $0
    /* 3CBE5C 004CBE5C 289A7024 */  addiu      $16, $3, %lo(D_00719A28)
    /* 3CBE60 004CBE60 000002AE */  sw         $2, 0x0($16)
    /* 3CBE64 004CBE64 0000028E */  lw         $2, 0x0($16)
    /* 3CBE68 004CBE68 488A100C */  jal        func_00422920
    /* 3CBE6C 004CBE6C 0000048E */   lw        $4, 0x0($16)
    /* 3CBE70 004CBE70 0000038E */  lw         $3, 0x0($16)
    /* 3CBE74 004CBE74 06006010 */  beqz       $3, .L004CBE90
    /* 3CBE78 004CBE78 7200023C */   lui       $2, %hi(D_007199A4)
    /* 3CBE7C 004CBE7C 0000048E */  lw         $4, 0x0($16)
    /* 3CBE80 004CBE80 6A2F130C */  jal        func_004cbda8
    /* 3CBE84 004CBE84 00000000 */   nop
    /* 3CBE88 004CBE88 0000038E */  lw         $3, 0x0($16)
    /* 3CBE8C 004CBE8C 7200023C */  lui        $2, %hi(D_007199A4)
  .L004CBE90:
    /* 3CBE90 004CBE90 0000048E */  lw         $4, 0x0($16)
    /* 3CBE94 004CBE94 9C85100C */  jal        func_00421670
    /* 3CBE98 004CBE98 A499458C */   lw        $5, %lo(D_007199A4)($2)
    /* 3CBE9C 004CBE9C 3000B0DF */  ld         $16, 0x30($29)
    /* 3CBEA0 004CBEA0 3800BFDF */  ld         $31, 0x38($29)
    /* 3CBEA4 004CBEA4 0800E003 */  jr         $31
    /* 3CBEA8 004CBEA8 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CBEAC 004CBEAC 00000000 */  nop
.size func_004cbe08, 0xa8
