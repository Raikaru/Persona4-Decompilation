.section .text
.set noat
.set noreorder
glabel func_004cfd08
    /* 3CFD08 004CFD08 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 3CFD0C 004CFD0C 3000B4FF */  sd         $20, 0x30($29)
    /* 3CFD10 004CFD10 2DA0A000 */  daddu      $20, $5, $0
    /* 3CFD14 004CFD14 2000B2FF */  sd         $18, 0x20($29)
    /* 3CFD18 004CFD18 2D900000 */  daddu      $18, $0, $0
    /* 3CFD1C 004CFD1C 2800B3FF */  sd         $19, 0x28($29)
    /* 3CFD20 004CFD20 2D988000 */  daddu      $19, $4, $0
    /* 3CFD24 004CFD24 4000B6FF */  sd         $22, 0x40($29)
    /* 3CFD28 004CFD28 0C007626 */  addiu      $22, $19, 0xC
    /* 3CFD2C 004CFD2C 4800B7FF */  sd         $23, 0x48($29)
    /* 3CFD30 004CFD30 08007726 */  addiu      $23, $19, 0x8
    /* 3CFD34 004CFD34 5000BEFF */  sd         $30, 0x50($29)
    /* 3CFD38 004CFD38 40F01400 */  sll        $30, $20, 1
    /* 3CFD3C 004CFD3C 1000B0FF */  sd         $16, 0x10($29)
    /* 3CFD40 004CFD40 80181400 */  sll        $3, $20, 2
    /* 3CFD44 004CFD44 1800B1FF */  sd         $17, 0x18($29)
    /* 3CFD48 004CFD48 21187300 */  addu       $3, $3, $19
    /* 3CFD4C 004CFD4C 3800B5FF */  sd         $21, 0x38($29)
    /* 3CFD50 004CFD50 8000C227 */  addiu      $2, $30, 0x80
    /* 3CFD54 004CFD54 5800BFFF */  sd         $31, 0x58($29)
    /* 3CFD58 004CFD58 2120C202 */  addu       $4, $22, $2
    /* 3CFD5C 004CFD5C 2110E202 */  addu       $2, $23, $2
    /* 3CFD60 004CFD60 8000718C */  lw         $17, 0x80($3)
    /* 3CFD64 004CFD64 00008684 */  lh         $6, 0x0($4)
    /* 3CFD68 004CFD68 00004584 */  lh         $5, 0x0($2)
    /* 3CFD6C 004CFD6C 2D202002 */  daddu      $4, $17, $0
    /* 3CFD70 004CFD70 8800228E */  lw         $2, 0x88($17)
    /* 3CFD74 004CFD74 703E130C */  jal        func_004cf9c0
    /* 3CFD78 004CFD78 0400A2AF */   sw        $2, 0x4($29)
    /* 3CFD7C 004CFD7C 4400628E */  lw         $2, 0x44($19)
    /* 3CFD80 004CFD80 0F004018 */  blez       $2, .L004CFDC0
    /* 3CFD84 004CFD84 2D202002 */   daddu     $4, $17, $0
    /* 3CFD88 004CFD88 80A91400 */  sll        $21, $20, 6
    /* 3CFD8C 004CFD8C 2110B302 */  addu       $2, $21, $19
    /* 3CFD90 004CFD90 90005024 */  addiu      $16, $2, 0x90
    /* 3CFD94 004CFD94 00000686 */  lh         $6, 0x0($16)
  .L004CFD98:
    /* 3CFD98 004CFD98 02001026 */  addiu      $16, $16, 0x2
    /* 3CFD9C 004CFD9C 2D284002 */  daddu      $5, $18, $0
    /* 3CFDA0 004CFDA0 01005226 */  addiu      $18, $18, 0x1
    /* 3CFDA4 004CFDA4 743E130C */  jal        func_004cf9d0
    /* 3CFDA8 004CFDA8 2D202002 */   daddu     $4, $17, $0
    /* 3CFDAC 004CFDAC 4400628E */  lw         $2, 0x44($19)
    /* 3CFDB0 004CFDB0 2A104202 */  slt        $2, $18, $2
    /* 3CFDB4 004CFDB4 F8FF4054 */  bnel       $2, $0, .L004CFD98
    /* 3CFDB8 004CFDB8 00000686 */   lh        $6, 0x0($16)
    /* 3CFDBC 004CFDBC 2D202002 */  daddu      $4, $17, $0
  .L004CFDC0:
    /* 3CFDC0 004CFDC0 AE3E130C */  jal        func_004cfab8
    /* 3CFDC4 004CFDC4 2D900000 */   daddu     $18, $0, $0
    /* 3CFDC8 004CFDC8 8000C227 */  addiu      $2, $30, 0x80
    /* 3CFDCC 004CFDCC 2118C202 */  addu       $3, $22, $2
    /* 3CFDD0 004CFDD0 2110E202 */  addu       $2, $23, $2
    /* 3CFDD4 004CFDD4 00004584 */  lh         $5, 0x0($2)
    /* 3CFDD8 004CFDD8 00006684 */  lh         $6, 0x0($3)
    /* 3CFDDC 004CFDDC F83D130C */  jal        func_004cf7e0
    /* 3CFDE0 004CFDE0 8800248E */   lw        $4, 0x88($17)
    /* 3CFDE4 004CFDE4 4400628E */  lw         $2, 0x44($19)
    /* 3CFDE8 004CFDE8 53004018 */  blez       $2, .L004CFF38
    /* 3CFDEC 004CFDEC 1000B0DF */   ld        $16, 0x10($29)
    /* 3CFDF0 004CFDF0 80A91400 */  sll        $21, $20, 6
    /* 3CFDF4 004CFDF4 49121424 */  addiu      $20, $0, 0x1249
    /* 3CFDF8 004CFDF8 0200BE27 */  addiu      $30, $29, 0x2
    /* 3CFDFC 004CFDFC FF7F1724 */  addiu      $23, $0, 0x7FFF
    /* 3CFE00 004CFE00 00801624 */  addiu      $22, $0, -0x8000
    /* 3CFE04 004CFE04 0400A48F */  lw         $4, 0x4($29)
  .L004CFE08:
    /* 3CFE08 004CFE08 2110B302 */  addu       $2, $21, $19
    /* 3CFE0C 004CFE0C 40181200 */  sll        $3, $18, 1
    /* 3CFE10 004CFE10 2D28A003 */  daddu      $5, $29, $0
    /* 3CFE14 004CFE14 21186200 */  addu       $3, $3, $2
    /* 3CFE18 004CFE18 2D30C003 */  daddu      $6, $30, $0
    /* 3CFE1C 004CFE1C FC3D130C */  jal        func_004cf7f0
    /* 3CFE20 004CFE20 90007084 */   lh        $16, 0x90($3)
    /* 3CFE24 004CFE24 0000A587 */  lh         $5, 0x0($29)
    /* 3CFE28 004CFE28 2D202002 */  daddu      $4, $17, $0
    /* 3CFE2C 004CFE2C 703E130C */  jal        func_004cf9c0
    /* 3CFE30 004CFE30 0200A687 */   lh        $6, 0x2($29)
    /* 3CFE34 004CFE34 2D202002 */  daddu      $4, $17, $0
    /* 3CFE38 004CFE38 2D300002 */  daddu      $6, $16, $0
    /* 3CFE3C 004CFE3C 743E130C */  jal        func_004cf9d0
    /* 3CFE40 004CFE40 2D284002 */   daddu     $5, $18, $0
    /* 3CFE44 004CFE44 2D202002 */  daddu      $4, $17, $0
    /* 3CFE48 004CFE48 D43E130C */  jal        func_004cfb50
    /* 3CFE4C 004CFE4C 2D284002 */   daddu     $5, $18, $0
    /* 3CFE50 004CFE50 9639110C */  jal        func_0044e658
    /* 3CFE54 004CFE54 2D204000 */   daddu     $4, $2, $0
    /* 3CFE58 004CFE58 800025DE */  ld         $5, 0x80($17)
    /* 3CFE5C 004CFE5C 5A38110C */  jal        func_0044e168
    /* 3CFE60 004CFE60 2D204000 */   daddu     $4, $2, $0
    /* 3CFE64 004CFE64 C239110C */  jal        func_0044e708
    /* 3CFE68 004CFE68 2D204000 */   daddu     $4, $2, $0
    /* 3CFE6C 004CFE6C 2D804000 */  daddu      $16, $2, $0
    /* 3CFE70 004CFE70 2A10F002 */  slt        $2, $23, $16
    /* 3CFE74 004CFE74 06004054 */  bnel       $2, $0, .L004CFE90
    /* 3CFE78 004CFE78 FF7F0224 */   addiu     $2, $0, 0x7FFF
    /* 3CFE7C 004CFE7C 0080032A */  slti       $3, $16, -0x8000
    /* 3CFE80 004CFE80 2D10C002 */  daddu      $2, $22, $0
    /* 3CFE84 004CFE84 0A100302 */  movz       $2, $16, $3
    /* 3CFE88 004CFE88 00140200 */  sll        $2, $2, 16
    /* 3CFE8C 004CFE8C 03140200 */  sra        $2, $2, 16
  .L004CFE90:
    /* 3CFE90 004CFE90 2D804000 */  daddu      $16, $2, $0
    /* 3CFE94 004CFE94 02000306 */  bgezl      $16, .L004CFEA0
    /* 3CFE98 004CFE98 24090226 */   addiu     $2, $16, 0x924
    /* 3CFE9C 004CFE9C DCF60226 */  addiu      $2, $16, -0x924
  .L004CFEA0:
    /* 3CFEA0 004CFEA0 01008052 */  beql       $20, $0, .L004CFEA8
    /* 3CFEA4 004CFEA4 CD010000 */   break     0, 7
  .L004CFEA8:
    /* 3CFEA8 004CFEA8 1A005400 */  div        $0, $2, $20
    /* 3CFEAC 004CFEAC 12100000 */  mflo       $2
    /* 3CFEB0 004CFEB0 2D804000 */  daddu      $16, $2, $0
    /* 3CFEB4 004CFEB4 0700022A */  slti       $2, $16, 0x7
    /* 3CFEB8 004CFEB8 07004010 */  beqz       $2, .L004CFED8
    /* 3CFEBC 004CFEBC 07000324 */   addiu     $3, $0, 0x7
    /* 3CFEC0 004CFEC0 2D180002 */  daddu      $3, $16, $0
    /* 3CFEC4 004CFEC4 F8FF6228 */  slti       $2, $3, -0x8
    /* 3CFEC8 004CFEC8 03004054 */  bnel       $2, $0, .L004CFED8
    /* 3CFECC 004CFECC F8FF0324 */   addiu     $3, $0, -0x8
    /* 3CFED0 004CFED0 02000010 */  b          .L004CFEDC
    /* 3CFED4 004CFED4 2D806000 */   daddu     $16, $3, $0
  .L004CFED8:
    /* 3CFED8 004CFED8 2D806000 */  daddu      $16, $3, $0
  .L004CFEDC:
    /* 3CFEDC 004CFEDC 2D202002 */  daddu      $4, $17, $0
    /* 3CFEE0 004CFEE0 00361000 */  sll        $6, $16, 24
    /* 3CFEE4 004CFEE4 2D284002 */  daddu      $5, $18, $0
    /* 3CFEE8 004CFEE8 E23E130C */  jal        func_004cfb88
    /* 3CFEEC 004CFEEC 03360600 */   sra       $6, $6, 24
    /* 3CFEF0 004CFEF0 7C002286 */  lh         $2, 0x7C($17)
    /* 3CFEF4 004CFEF4 18800202 */  mult       $16, $16, $2
    /* 3CFEF8 004CFEF8 2A18F002 */  slt        $3, $23, $16
    /* 3CFEFC 004CFEFC 06006054 */  bnel       $3, $0, .L004CFF18
    /* 3CFF00 004CFF00 FF7F0524 */   addiu     $5, $0, 0x7FFF
    /* 3CFF04 004CFF04 0080032A */  slti       $3, $16, -0x8000
    /* 3CFF08 004CFF08 2D10C002 */  daddu      $2, $22, $0
    /* 3CFF0C 004CFF0C 0A100302 */  movz       $2, $16, $3
    /* 3CFF10 004CFF10 00140200 */  sll        $2, $2, 16
    /* 3CFF14 004CFF14 032C0200 */  sra        $5, $2, 16
  .L004CFF18:
    /* 3CFF18 004CFF18 8800248E */  lw         $4, 0x88($17)
    /* 3CFF1C 004CFF1C 023E130C */  jal        func_004cf808
    /* 3CFF20 004CFF20 01005226 */   addiu     $18, $18, 0x1
    /* 3CFF24 004CFF24 4400638E */  lw         $3, 0x44($19)
    /* 3CFF28 004CFF28 2A184302 */  slt        $3, $18, $3
    /* 3CFF2C 004CFF2C B6FF6014 */  bnez       $3, .L004CFE08
    /* 3CFF30 004CFF30 0400A48F */   lw        $4, 0x4($29)
    /* 3CFF34 004CFF34 1000B0DF */  ld         $16, 0x10($29)
  .L004CFF38:
    /* 3CFF38 004CFF38 2D100000 */  daddu      $2, $0, $0
    /* 3CFF3C 004CFF3C 1800B1DF */  ld         $17, 0x18($29)
    /* 3CFF40 004CFF40 2000B2DF */  ld         $18, 0x20($29)
    /* 3CFF44 004CFF44 2800B3DF */  ld         $19, 0x28($29)
    /* 3CFF48 004CFF48 3000B4DF */  ld         $20, 0x30($29)
    /* 3CFF4C 004CFF4C 3800B5DF */  ld         $21, 0x38($29)
    /* 3CFF50 004CFF50 4000B6DF */  ld         $22, 0x40($29)
    /* 3CFF54 004CFF54 4800B7DF */  ld         $23, 0x48($29)
    /* 3CFF58 004CFF58 5000BEDF */  ld         $30, 0x50($29)
    /* 3CFF5C 004CFF5C 5800BFDF */  ld         $31, 0x58($29)
    /* 3CFF60 004CFF60 0800E003 */  jr         $31
    /* 3CFF64 004CFF64 6000BD27 */   addiu     $29, $29, 0x60
.size func_004cfd08, 0x260
