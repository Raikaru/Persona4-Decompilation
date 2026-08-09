.section .text
.set noat
.set noreorder
glabel func_0019faf0
    /* 9FAF0 0019FAF0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 9FAF4 0019FAF4 3000BFFF */  sd         $31, 0x30($29)
    /* 9FAF8 0019FAF8 2000B27F */  sq         $18, 0x20($29)
    /* 9FAFC 0019FAFC 1000B17F */  sq         $17, 0x10($29)
    /* 9FB00 0019FB00 0000B07F */  sq         $16, 0x0($29)
    /* 9FB04 0019FB04 2D908000 */  daddu      $18, $4, $0
    /* 9FB08 0019FB08 ACB3838F */  lw         $3, -0x4C54($28)
    /* 9FB0C 0019FB0C 7401718C */  lw         $17, 0x174($3)
    /* 9FB10 0019FB10 47000010 */  b          .L0019FC30
    /* 9FB14 0019FB14 00000000 */   nop
  .L0019FB18:
    /* 9FB18 0019FB18 1A002396 */  lhu        $3, 0x1A($17)
    /* 9FB1C 0019FB1C 01006330 */  andi       $3, $3, 0x1
    /* 9FB20 0019FB20 42006010 */  beqz       $3, .L0019FC2C
    /* 9FB24 0019FB24 00000000 */   nop
    /* 9FB28 0019FB28 3000308E */  lw         $16, 0x30($17)
    /* 9FB2C 0019FB2C 9C00038E */  lw         $3, 0x9C($16)
    /* 9FB30 0019FB30 08006330 */  andi       $3, $3, 0x8
    /* 9FB34 0019FB34 3D006010 */  beqz       $3, .L0019FC2C
    /* 9FB38 0019FB38 00000000 */   nop
    /* 9FB3C 0019FB3C 2D200002 */  daddu      $4, $16, $0
    /* 9FB40 0019FB40 1062060C */  jal        func_00198840
    /* 9FB44 0019FB44 00000000 */   nop
    /* 9FB48 0019FB48 38004010 */  beqz       $2, .L0019FC2C
    /* 9FB4C 0019FB4C 00000000 */   nop
    /* 9FB50 0019FB50 2D200002 */  daddu      $4, $16, $0
    /* 9FB54 0019FB54 D45A060C */  jal        func_00196b50
    /* 9FB58 0019FB58 00000000 */   nop
    /* 9FB5C 0019FB5C 33004014 */  bnez       $2, .L0019FC2C
    /* 9FB60 0019FB60 00000000 */   nop
    /* 9FB64 0019FB64 640A048E */  lw         $4, 0xA64($16)
    /* 9FB68 0019FB68 1000053C */  lui        $5, (0x100000 >> 16)
    /* 9FB6C 0019FB6C C4C9080C */  jal        func_00232710
    /* 9FB70 0019FB70 00000000 */   nop
    /* 9FB74 0019FB74 2D004014 */  bnez       $2, .L0019FC2C
    /* 9FB78 0019FB78 00000000 */   nop
    /* 9FB7C 0019FB7C 640A048E */  lw         $4, 0xA64($16)
    /* 9FB80 0019FB80 0F00023C */  lui        $2, (0xFFFFF >> 16)
    /* 9FB84 0019FB84 FFFF4534 */  ori        $5, $2, (0xFFFFF & 0xFFFF)
    /* 9FB88 0019FB88 C4C9080C */  jal        func_00232710
    /* 9FB8C 0019FB8C 00000000 */   nop
    /* 9FB90 0019FB90 26004014 */  bnez       $2, .L0019FC2C
    /* 9FB94 0019FB94 00000000 */   nop
    /* 9FB98 0019FB98 640A048E */  lw         $4, 0xA64($16)
    /* 9FB9C 0019FB9C 4C0A090C */  jal        func_00242930
    /* 9FBA0 0019FBA0 00000000 */   nop
    /* 9FBA4 0019FBA4 21004014 */  bnez       $2, .L0019FC2C
    /* 9FBA8 0019FBA8 00000000 */   nop
    /* 9FBAC 0019FBAC 640A048E */  lw         $4, 0xA64($16)
    /* 9FBB0 0019FBB0 2D280000 */  daddu      $5, $0, $0
    /* 9FBB4 0019FBB4 3C0A090C */  jal        func_002428f0
    /* 9FBB8 0019FBB8 00000000 */   nop
    /* 9FBBC 0019FBBC 1B004014 */  bnez       $2, .L0019FC2C
    /* 9FBC0 0019FBC0 00000000 */   nop
    /* 9FBC4 0019FBC4 0C002496 */  lhu        $4, 0xC($17)
    /* 9FBC8 0019FBC8 05000324 */  addiu      $3, $0, 0x5
    /* 9FBCC 0019FBCC 06008310 */  beq        $4, $3, .L0019FBE8
    /* 9FBD0 0019FBD0 00000000 */   nop
    /* 9FBD4 0019FBD4 01000324 */  addiu      $3, $0, 0x1
    /* 9FBD8 0019FBD8 03008310 */  beq        $4, $3, .L0019FBE8
    /* 9FBDC 0019FBDC 00000000 */   nop
    /* 9FBE0 0019FBE0 12000010 */  b          .L0019FC2C
    /* 9FBE4 0019FBE4 00000000 */   nop
  .L0019FBE8:
    /* 9FBE8 0019FBE8 10005112 */  beq        $18, $17, .L0019FC2C
    /* 9FBEC 0019FBEC 00000000 */   nop
    /* 9FBF0 0019FBF0 2D200002 */  daddu      $4, $16, $0
    /* 9FBF4 0019FBF4 2D280000 */  daddu      $5, $0, $0
    /* 9FBF8 0019FBF8 2D300000 */  daddu      $6, $0, $0
    /* 9FBFC 0019FBFC 4000A727 */  addiu      $7, $29, 0x40
    /* 9FC00 0019FC00 FC53060C */  jal        func_00194ff0
    /* 9FC04 0019FC04 00000000 */   nop
    /* 9FC08 0019FC08 2D200002 */  daddu      $4, $16, $0
    /* 9FC0C 0019FC0C 4000A527 */  addiu      $5, $29, 0x40
    /* 9FC10 0019FC10 2D300000 */  daddu      $6, $0, $0
    /* 9FC14 0019FC14 5478060C */  jal        func_0019e150
    /* 9FC18 0019FC18 00000000 */   nop
    /* 9FC1C 0019FC1C 2D204000 */  daddu      $4, $2, $0
    /* 9FC20 0019FC20 01000524 */  addiu      $5, $0, 0x1
    /* 9FC24 0019FC24 6451060C */  jal        func_00194590
    /* 9FC28 0019FC28 00000000 */   nop
  .L0019FC2C:
    /* 9FC2C 0019FC2C 5004318E */  lw         $17, 0x450($17)
  .L0019FC30:
    /* 9FC30 0019FC30 B9FF2016 */  bnez       $17, .L0019FB18
    /* 9FC34 0019FC34 00000000 */   nop
    /* 9FC38 0019FC38 3000BFDF */  ld         $31, 0x30($29)
    /* 9FC3C 0019FC3C 2000B27B */  lq         $18, 0x20($29)
    /* 9FC40 0019FC40 1000B17B */  lq         $17, 0x10($29)
    /* 9FC44 0019FC44 0000B07B */  lq         $16, 0x0($29)
    /* 9FC48 0019FC48 5000BD27 */  addiu      $29, $29, 0x50
    /* 9FC4C 0019FC4C 0800E003 */  jr         $31
    /* 9FC50 0019FC50 00000000 */   nop
    /* 9FC54 0019FC54 00000000 */  nop
    /* 9FC58 0019FC58 00000000 */  nop
    /* 9FC5C 0019FC5C 00000000 */  nop
.size func_0019faf0, 0x170
