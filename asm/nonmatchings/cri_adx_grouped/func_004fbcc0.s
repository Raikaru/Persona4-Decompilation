.section .text
.set noat
.set noreorder
glabel func_004fbcc0
    /* 3FBCC0 004FBCC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3FBCC4 004FBCC4 3000B2FF */  sd         $18, 0x30($29)
    /* 3FBCC8 004FBCC8 2D908000 */  daddu      $18, $4, $0
    /* 3FBCCC 004FBCCC 2800B1FF */  sd         $17, 0x28($29)
    /* 3FBCD0 004FBCD0 2D88A000 */  daddu      $17, $5, $0
    /* 3FBCD4 004FBCD4 3800B3FF */  sd         $19, 0x38($29)
    /* 3FBCD8 004FBCD8 60015326 */  addiu      $19, $18, 0x160
    /* 3FBCDC 004FBCDC 4000B4FF */  sd         $20, 0x40($29)
    /* 3FBCE0 004FBCE0 1000B427 */  addiu      $20, $29, 0x10
    /* 3FBCE4 004FBCE4 2000B0FF */  sd         $16, 0x20($29)
    /* 3FBCE8 004FBCE8 4800BFFF */  sd         $31, 0x48($29)
    /* 3FBCEC 004FBCEC F80460AE */  sw         $0, 0x4F8($19)
    /* 3FBCF0 004FBCF0 FC0460AE */  sw         $0, 0x4FC($19)
    /* 3FBCF4 004FBCF4 080360AE */  sw         $0, 0x308($19)
    /* 3FBCF8 004FBCF8 5D000010 */  b          .L004FBE70
    /* 3FBCFC 004FBCFC 0C0360AE */   sw        $0, 0x30C($19)
  .L004FBD00:
    /* 3FBD00 004FBD00 FF7F063C */  lui        $6, (0x7FFFFFFF >> 16)
    /* 3FBD04 004FBD04 2D202002 */  daddu      $4, $17, $0
    /* 3FBD08 004FBD08 01000524 */  addiu      $5, $0, 0x1
    /* 3FBD0C 004FBD0C 1800628C */  lw         $2, 0x18($3)
    /* 3FBD10 004FBD10 FFFFC634 */  ori        $6, $6, (0x7FFFFFFF & 0xFFFF)
    /* 3FBD14 004FBD14 09F84000 */  jalr       $2
    /* 3FBD18 004FBD18 2D38A003 */   daddu     $7, $29, $0
    /* 3FBD1C 004FBD1C 10000224 */  addiu      $2, $0, 0x10
    /* 3FBD20 004FBD20 27000212 */  beq        $16, $2, .L004FBDC0
    /* 3FBD24 004FBD24 2D180000 */   daddu     $3, $0, $0
    /* 3FBD28 004FBD28 1100022A */  slti       $2, $16, 0x11
    /* 3FBD2C 004FBD2C 08004010 */  beqz       $2, .L004FBD50
    /* 3FBD30 004FBD30 40000224 */   addiu     $2, $0, 0x40
    /* 3FBD34 004FBD34 04000224 */  addiu      $2, $0, 0x4
    /* 3FBD38 004FBD38 2B000212 */  beq        $16, $2, .L004FBDE8
    /* 3FBD3C 004FBD3C 08000224 */   addiu     $2, $0, 0x8
    /* 3FBD40 004FBD40 25000212 */  beq        $16, $2, .L004FBDD8
    /* 3FBD44 004FBD44 0000A58F */   lw        $5, 0x0($29)
    /* 3FBD48 004FBD48 2B000010 */  b          .L004FBDF8
    /* 3FBD4C 004FBD4C 00000000 */   nop
  .L004FBD50:
    /* 3FBD50 004FBD50 0D000212 */  beq        $16, $2, .L004FBD88
    /* 3FBD54 004FBD54 4100022A */   slti      $2, $16, 0x41
    /* 3FBD58 004FBD58 07004010 */  beqz       $2, .L004FBD78
    /* 3FBD5C 004FBD5C 80000224 */   addiu     $2, $0, 0x80
    /* 3FBD60 004FBD60 20000224 */  addiu      $2, $0, 0x20
    /* 3FBD64 004FBD64 12000212 */  beq        $16, $2, .L004FBDB0
    /* 3FBD68 004FBD68 0000A58F */   lw        $5, 0x0($29)
    /* 3FBD6C 004FBD6C 22000010 */  b          .L004FBDF8
    /* 3FBD70 004FBD70 00000000 */   nop
    /* 3FBD74 004FBD74 00000000 */  nop
  .L004FBD78:
    /* 3FBD78 004FBD78 09000212 */  beq        $16, $2, .L004FBDA0
    /* 3FBD7C 004FBD7C 0000A58F */   lw        $5, 0x0($29)
    /* 3FBD80 004FBD80 1D000010 */  b          .L004FBDF8
    /* 3FBD84 004FBD84 00000000 */   nop
  .L004FBD88:
    /* 3FBD88 004FBD88 0000A58F */  lw         $5, 0x0($29)
    /* 3FBD8C 004FBD8C 14F0130C */  jal        func_004fc050
    /* 3FBD90 004FBD90 2D204002 */   daddu     $4, $18, $0
    /* 3FBD94 004FBD94 18000010 */  b          .L004FBDF8
    /* 3FBD98 004FBD98 2D184000 */   daddu     $3, $2, $0
    /* 3FBD9C 004FBD9C 00000000 */  nop
  .L004FBDA0:
    /* 3FBDA0 004FBDA0 0AF2130C */  jal        func_004fc828
    /* 3FBDA4 004FBDA4 2D204002 */   daddu     $4, $18, $0
    /* 3FBDA8 004FBDA8 13000010 */  b          .L004FBDF8
    /* 3FBDAC 004FBDAC 2D184000 */   daddu     $3, $2, $0
  .L004FBDB0:
    /* 3FBDB0 004FBDB0 52F2130C */  jal        func_004fc948
    /* 3FBDB4 004FBDB4 2D204002 */   daddu     $4, $18, $0
    /* 3FBDB8 004FBDB8 0F000010 */  b          .L004FBDF8
    /* 3FBDBC 004FBDBC 2D184000 */   daddu     $3, $2, $0
  .L004FBDC0:
    /* 3FBDC0 004FBDC0 0000A58F */  lw         $5, 0x0($29)
    /* 3FBDC4 004FBDC4 46F3130C */  jal        func_004fcd18
    /* 3FBDC8 004FBDC8 2D204002 */   daddu     $4, $18, $0
    /* 3FBDCC 004FBDCC 0A000010 */  b          .L004FBDF8
    /* 3FBDD0 004FBDD0 2D184000 */   daddu     $3, $2, $0
    /* 3FBDD4 004FBDD4 00000000 */  nop
  .L004FBDD8:
    /* 3FBDD8 004FBDD8 3EFF130C */  jal        func_004ffcf8
    /* 3FBDDC 004FBDDC 2D204002 */   daddu     $4, $18, $0
    /* 3FBDE0 004FBDE0 05000010 */  b          .L004FBDF8
    /* 3FBDE4 004FBDE4 2D184000 */   daddu     $3, $2, $0
  .L004FBDE8:
    /* 3FBDE8 004FBDE8 0000A58F */  lw         $5, 0x0($29)
    /* 3FBDEC 004FBDEC 9800140C */  jal        func_00500260
    /* 3FBDF0 004FBDF0 2D204002 */   daddu     $4, $18, $0
    /* 3FBDF4 004FBDF4 2D184000 */  daddu      $3, $2, $0
  .L004FBDF8:
    /* 3FBDF8 004FBDF8 09006054 */  bnel       $3, $0, .L004FBE20
    /* 3FBDFC 004FBDFC 0000A58F */   lw        $5, 0x0($29)
    /* 3FBE00 004FBE00 0000238E */  lw         $3, 0x0($17)
    /* 3FBE04 004FBE04 2D30A003 */  daddu      $6, $29, $0
    /* 3FBE08 004FBE08 2D202002 */  daddu      $4, $17, $0
    /* 3FBE0C 004FBE0C 1C00628C */  lw         $2, 0x1C($3)
    /* 3FBE10 004FBE10 09F84000 */  jalr       $2
    /* 3FBE14 004FBE14 01000524 */   addiu     $5, $0, 0x1
    /* 3FBE18 004FBE18 1B000010 */  b          .L004FBE88
    /* 3FBE1C 004FBE1C F804668E */   lw        $6, 0x4F8($19)
  .L004FBE20:
    /* 3FBE20 004FBE20 2D20A003 */  daddu      $4, $29, $0
    /* 3FBE24 004FBE24 2D30A003 */  daddu      $6, $29, $0
    /* 3FBE28 004FBE28 2D388002 */  daddu      $7, $20, $0
    /* 3FBE2C 004FBE2C 2EBE130C */  jal        func_004ef8b8
    /* 3FBE30 004FBE30 23286500 */   subu      $5, $3, $5
    /* 3FBE34 004FBE34 0000238E */  lw         $3, 0x0($17)
    /* 3FBE38 004FBE38 2D30A003 */  daddu      $6, $29, $0
    /* 3FBE3C 004FBE3C 2D202002 */  daddu      $4, $17, $0
    /* 3FBE40 004FBE40 2000628C */  lw         $2, 0x20($3)
    /* 3FBE44 004FBE44 09F84000 */  jalr       $2
    /* 3FBE48 004FBE48 2D280000 */   daddu     $5, $0, $0
    /* 3FBE4C 004FBE4C 0000238E */  lw         $3, 0x0($17)
    /* 3FBE50 004FBE50 2D308002 */  daddu      $6, $20, $0
    /* 3FBE54 004FBE54 2D202002 */  daddu      $4, $17, $0
    /* 3FBE58 004FBE58 1C00628C */  lw         $2, 0x1C($3)
    /* 3FBE5C 004FBE5C 09F84000 */  jalr       $2
    /* 3FBE60 004FBE60 01000524 */   addiu     $5, $0, 0x1
    /* 3FBE64 004FBE64 F804668E */  lw         $6, 0x4F8($19)
    /* 3FBE68 004FBE68 0800C054 */  bnel       $6, $0, .L004FBE8C
    /* 3FBE6C 004FBE6C 0005638E */   lw        $3, 0x500($19)
  .L004FBE70:
    /* 3FBE70 004FBE70 3E1A140C */  jal        func_005068f8
    /* 3FBE74 004FBE74 2D202002 */   daddu     $4, $17, $0
    /* 3FBE78 004FBE78 2D804000 */  daddu      $16, $2, $0
    /* 3FBE7C 004FBE7C A0FF0056 */  bnel       $16, $0, .L004FBD00
    /* 3FBE80 004FBE80 0000238E */   lw        $3, 0x0($17)
    /* 3FBE84 004FBE84 F804668E */  lw         $6, 0x4F8($19)
  .L004FBE88:
    /* 3FBE88 004FBE88 0005638E */  lw         $3, 0x500($19)
  .L004FBE8C:
    /* 3FBE8C 004FBE8C FEFF0224 */  addiu      $2, $0, -0x2
    /* 3FBE90 004FBE90 0405648E */  lw         $4, 0x504($19)
    /* 3FBE94 004FBE94 0A100600 */  movz       $2, $0, $6
    /* 3FBE98 004FBE98 FC04658E */  lw         $5, 0x4FC($19)
    /* 3FBE9C 004FBE9C 21186600 */  addu       $3, $3, $6
    /* 3FBEA0 004FBEA0 000563AE */  sw         $3, 0x500($19)
    /* 3FBEA4 004FBEA4 21208500 */  addu       $4, $4, $5
    /* 3FBEA8 004FBEA8 2000B0DF */  ld         $16, 0x20($29)
    /* 3FBEAC 004FBEAC 040564AE */  sw         $4, 0x504($19)
    /* 3FBEB0 004FBEB0 2800B1DF */  ld         $17, 0x28($29)
    /* 3FBEB4 004FBEB4 3000B2DF */  ld         $18, 0x30($29)
    /* 3FBEB8 004FBEB8 3800B3DF */  ld         $19, 0x38($29)
    /* 3FBEBC 004FBEBC 4000B4DF */  ld         $20, 0x40($29)
    /* 3FBEC0 004FBEC0 4800BFDF */  ld         $31, 0x48($29)
    /* 3FBEC4 004FBEC4 0800E003 */  jr         $31
    /* 3FBEC8 004FBEC8 5000BD27 */   addiu     $29, $29, 0x50
    /* 3FBECC 004FBECC 00000000 */  nop
.size func_004fbcc0, 0x210
