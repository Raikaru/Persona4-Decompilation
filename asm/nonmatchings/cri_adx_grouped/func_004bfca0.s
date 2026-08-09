.section .text
.set noat
.set noreorder
glabel func_004bfca0
    /* 3BFCA0 004BFCA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BFCA4 004BFCA4 0000B0FF */  sd         $16, 0x0($29)
    /* 3BFCA8 004BFCA8 2D808000 */  daddu      $16, $4, $0
    /* 3BFCAC 004BFCAC 0800B1FF */  sd         $17, 0x8($29)
    /* 3BFCB0 004BFCB0 2D880000 */  daddu      $17, $0, $0
    /* 3BFCB4 004BFCB4 2000B4FF */  sd         $20, 0x20($29)
    /* 3BFCB8 004BFCB8 1000B2FF */  sd         $18, 0x10($29)
    /* 3BFCBC 004BFCBC 1800B3FF */  sd         $19, 0x18($29)
    /* 3BFCC0 004BFCC0 2800BFFF */  sd         $31, 0x28($29)
    /* 3BFCC4 004BFCC4 5000028E */  lw         $2, 0x50($16)
    /* 3BFCC8 004BFCC8 0B004014 */  bnez       $2, .L004BFCF8
    /* 3BFCCC 004BFCCC 2DA0A000 */   daddu     $20, $5, $0
    /* 3BFCD0 004BFCD0 7500043C */  lui        $4, %hi(D_007572C0)
    /* 3BFCD4 004BFCD4 0000B0DF */  ld         $16, 0x0($29)
    /* 3BFCD8 004BFCD8 0800B1DF */  ld         $17, 0x8($29)
    /* 3BFCDC 004BFCDC C0728424 */  addiu      $4, $4, %lo(D_007572C0)
    /* 3BFCE0 004BFCE0 1000B2DF */  ld         $18, 0x10($29)
    /* 3BFCE4 004BFCE4 1800B3DF */  ld         $19, 0x18($29)
    /* 3BFCE8 004BFCE8 2000B4DF */  ld         $20, 0x20($29)
    /* 3BFCEC 004BFCEC 2800BFDF */  ld         $31, 0x28($29)
    /* 3BFCF0 004BFCF0 A8F51208 */  j          func_004bd6a0
    /* 3BFCF4 004BFCF4 3000BD27 */   addiu     $29, $29, 0x30
  .L004BFCF8:
    /* 3BFCF8 004BFCF8 96F5120C */  jal        func_004bd658
    /* 3BFCFC 004BFCFC 00000000 */   nop
    /* 3BFD00 004BFD00 2D200002 */  daddu      $4, $16, $0
    /* 3BFD04 004BFD04 7000130C */  jal        func_004c01c0
    /* 3BFD08 004BFD08 01000524 */   addiu     $5, $0, 0x1
    /* 3BFD0C 004BFD0C B400068E */  lw         $6, 0xB4($16)
    /* 3BFD10 004BFD10 0500C304 */  bgezl      $6, .L004BFD28
    /* 3BFD14 004BFD14 2D90C000 */   daddu     $18, $6, $0
    /* 3BFD18 004BFD18 23980600 */  negu       $19, $6
    /* 3BFD1C 004BFD1C 03000010 */  b          .L004BFD2C
    /* 3BFD20 004BFD20 2D900000 */   daddu     $18, $0, $0
    /* 3BFD24 004BFD24 00000000 */  nop
  .L004BFD28:
    /* 3BFD28 004BFD28 2D980000 */  daddu      $19, $0, $0
  .L004BFD2C:
    /* 3BFD2C 004BFD2C 5C00028E */  lw         $2, 0x5C($16)
    /* 3BFD30 004BFD30 57004010 */  beqz       $2, .L004BFE90
    /* 3BFD34 004BFD34 2D200002 */   daddu     $4, $16, $0
    /* 3BFD38 004BFD38 C200130C */  jal        func_004c0308
    /* 3BFD3C 004BFD3C 08001126 */   addiu     $17, $16, 0x8
    /* 3BFD40 004BFD40 0800048E */  lw         $4, 0x8($16)
    /* 3BFD44 004BFD44 0000838C */  lw         $3, 0x0($4)
    /* 3BFD48 004BFD48 1C00628C */  lw         $2, 0x1C($3)
    /* 3BFD4C 004BFD4C 09F84000 */  jalr       $2
    /* 3BFD50 004BFD50 01000524 */   addiu     $5, $0, 0x1
    /* 3BFD54 004BFD54 01000324 */  addiu      $3, $0, 0x1
    /* 3BFD58 004BFD58 1400048E */  lw         $4, 0x14($16)
    /* 3BFD5C 004BFD5C 640003AE */  sw         $3, 0x64($16)
    /* 3BFD60 004BFD60 40100400 */  sll        $2, $4, 1
    /* 3BFD64 004BFD64 21104400 */  addu       $2, $2, $4
    /* 3BFD68 004BFD68 80100200 */  sll        $2, $2, 2
    /* 3BFD6C 004BFD6C 21105100 */  addu       $2, $2, $17
    /* 3BFD70 004BFD70 1000448C */  lw         $4, 0x10($2)
    /* 3BFD74 004BFD74 0000838C */  lw         $3, 0x0($4)
    /* 3BFD78 004BFD78 2400628C */  lw         $2, 0x24($3)
    /* 3BFD7C 004BFD7C 09F84000 */  jalr       $2
    /* 3BFD80 004BFD80 00000000 */   nop
    /* 3BFD84 004BFD84 0C004014 */  bnez       $2, .L004BFDB8
    /* 3BFD88 004BFD88 1000028E */   lw        $2, 0x10($16)
    /* 3BFD8C 004BFD8C 2D200002 */  daddu      $4, $16, $0
    /* 3BFD90 004BFD90 2D300000 */  daddu      $6, $0, $0
    /* 3BFD94 004BFD94 2D380000 */  daddu      $7, $0, $0
    /* 3BFD98 004BFD98 40280200 */  sll        $5, $2, 1
    /* 3BFD9C 004BFD9C 2128A200 */  addu       $5, $5, $2
    /* 3BFDA0 004BFDA0 80280500 */  sll        $5, $5, 2
    /* 3BFDA4 004BFDA4 21280502 */  addu       $5, $16, $5
    /* 3BFDA8 004BFDA8 1A00130C */  jal        func_004c0068
    /* 3BFDAC 004BFDAC 1800A524 */   addiu     $5, $5, 0x18
    /* 3BFDB0 004BFDB0 0B000010 */  b          .L004BFDE0
    /* 3BFDB4 004BFDB4 1400038E */   lw        $3, 0x14($16)
  .L004BFDB8:
    /* 3BFDB8 004BFDB8 2D304002 */  daddu      $6, $18, $0
    /* 3BFDBC 004BFDBC 2D200002 */  daddu      $4, $16, $0
    /* 3BFDC0 004BFDC0 2D380000 */  daddu      $7, $0, $0
    /* 3BFDC4 004BFDC4 40280200 */  sll        $5, $2, 1
    /* 3BFDC8 004BFDC8 2128A200 */  addu       $5, $5, $2
    /* 3BFDCC 004BFDCC 80280500 */  sll        $5, $5, 2
    /* 3BFDD0 004BFDD0 21280502 */  addu       $5, $16, $5
    /* 3BFDD4 004BFDD4 1A00130C */  jal        func_004c0068
    /* 3BFDD8 004BFDD8 1800A524 */   addiu     $5, $5, 0x18
    /* 3BFDDC 004BFDDC 1400038E */  lw         $3, 0x14($16)
  .L004BFDE0:
    /* 3BFDE0 004BFDE0 40100300 */  sll        $2, $3, 1
    /* 3BFDE4 004BFDE4 21104300 */  addu       $2, $2, $3
    /* 3BFDE8 004BFDE8 80100200 */  sll        $2, $2, 2
    /* 3BFDEC 004BFDEC 21105100 */  addu       $2, $2, $17
    /* 3BFDF0 004BFDF0 1000448C */  lw         $4, 0x10($2)
    /* 3BFDF4 004BFDF4 0000838C */  lw         $3, 0x0($4)
    /* 3BFDF8 004BFDF8 2400628C */  lw         $2, 0x24($3)
    /* 3BFDFC 004BFDFC 09F84000 */  jalr       $2
    /* 3BFE00 004BFE00 00000000 */   nop
    /* 3BFE04 004BFE04 20004010 */  beqz       $2, .L004BFE88
    /* 3BFE08 004BFE08 2D306002 */   daddu     $6, $19, $0
    /* 3BFE0C 004BFE0C 1400028E */  lw         $2, 0x14($16)
    /* 3BFE10 004BFE10 2D200002 */  daddu      $4, $16, $0
    /* 3BFE14 004BFE14 02000724 */  addiu      $7, $0, 0x2
    /* 3BFE18 004BFE18 40280200 */  sll        $5, $2, 1
    /* 3BFE1C 004BFE1C 2128A200 */  addu       $5, $5, $2
    /* 3BFE20 004BFE20 80280500 */  sll        $5, $5, 2
    /* 3BFE24 004BFE24 21280502 */  addu       $5, $16, $5
    /* 3BFE28 004BFE28 4600130C */  jal        func_004c0118
    /* 3BFE2C 004BFE2C 1800A524 */   addiu     $5, $5, 0x18
    /* 3BFE30 004BFE30 6000038E */  lw         $3, 0x60($16)
    /* 3BFE34 004BFE34 01000224 */  addiu      $2, $0, 0x1
    /* 3BFE38 004BFE38 3E006254 */  bnel       $3, $2, .L004BFF34
    /* 3BFE3C 004BFE3C 01001124 */   addiu     $17, $0, 0x1
    /* 3BFE40 004BFE40 1400038E */  lw         $3, 0x14($16)
    /* 3BFE44 004BFE44 40100300 */  sll        $2, $3, 1
    /* 3BFE48 004BFE48 21104300 */  addu       $2, $2, $3
    /* 3BFE4C 004BFE4C 80100200 */  sll        $2, $2, 2
    /* 3BFE50 004BFE50 21105100 */  addu       $2, $2, $17
    /* 3BFE54 004BFE54 1000448C */  lw         $4, 0x10($2)
    /* 3BFE58 004BFE58 0000838C */  lw         $3, 0x0($4)
    /* 3BFE5C 004BFE5C 1800628C */  lw         $2, 0x18($3)
    /* 3BFE60 004BFE60 09F84000 */  jalr       $2
    /* 3BFE64 004BFE64 00000000 */   nop
    /* 3BFE68 004BFE68 1400038E */  lw         $3, 0x14($16)
    /* 3BFE6C 004BFE6C 40FC0524 */  addiu      $5, $0, -0x3C0
    /* 3BFE70 004BFE70 40100300 */  sll        $2, $3, 1
    /* 3BFE74 004BFE74 21104300 */  addu       $2, $2, $3
    /* 3BFE78 004BFE78 80100200 */  sll        $2, $2, 2
    /* 3BFE7C 004BFE7C 21105000 */  addu       $2, $2, $16
    /* 3BFE80 004BFE80 D8F5120C */  jal        func_004bd760
    /* 3BFE84 004BFE84 2000448C */   lw        $4, 0x20($2)
  .L004BFE88:
    /* 3BFE88 004BFE88 2A000010 */  b          .L004BFF34
    /* 3BFE8C 004BFE8C 01001124 */   addiu     $17, $0, 0x1
  .L004BFE90:
    /* 3BFE90 004BFE90 0800048E */  lw         $4, 0x8($16)
    /* 3BFE94 004BFE94 0000838C */  lw         $3, 0x0($4)
    /* 3BFE98 004BFE98 2400628C */  lw         $2, 0x24($3)
    /* 3BFE9C 004BFE9C 09F84000 */  jalr       $2
    /* 3BFEA0 004BFEA0 00000000 */   nop
    /* 3BFEA4 004BFEA4 02000324 */  addiu      $3, $0, 0x2
    /* 3BFEA8 004BFEA8 06004354 */  bnel       $2, $3, .L004BFEC4
    /* 3BFEAC 004BFEAC 0800048E */   lw        $4, 0x8($16)
    /* 3BFEB0 004BFEB0 6000038E */  lw         $3, 0x60($16)
    /* 3BFEB4 004BFEB4 01000224 */  addiu      $2, $0, 0x1
    /* 3BFEB8 004BFEB8 15006254 */  bnel       $3, $2, .L004BFF10
    /* 3BFEBC 004BFEBC 1000028E */   lw        $2, 0x10($16)
    /* 3BFEC0 004BFEC0 0800048E */  lw         $4, 0x8($16)
  .L004BFEC4:
    /* 3BFEC4 004BFEC4 01000524 */  addiu      $5, $0, 0x1
    /* 3BFEC8 004BFEC8 0000838C */  lw         $3, 0x0($4)
    /* 3BFECC 004BFECC 1C00628C */  lw         $2, 0x1C($3)
    /* 3BFED0 004BFED0 09F84000 */  jalr       $2
    /* 3BFED4 004BFED4 01001124 */   addiu     $17, $0, 0x1
    /* 3BFED8 004BFED8 01000324 */  addiu      $3, $0, 0x1
    /* 3BFEDC 004BFEDC 1000028E */  lw         $2, 0x10($16)
    /* 3BFEE0 004BFEE0 2D200002 */  daddu      $4, $16, $0
    /* 3BFEE4 004BFEE4 640003AE */  sw         $3, 0x64($16)
    /* 3BFEE8 004BFEE8 2D300000 */  daddu      $6, $0, $0
    /* 3BFEEC 004BFEEC 40280200 */  sll        $5, $2, 1
    /* 3BFEF0 004BFEF0 2D380000 */  daddu      $7, $0, $0
    /* 3BFEF4 004BFEF4 2128A200 */  addu       $5, $5, $2
    /* 3BFEF8 004BFEF8 80280500 */  sll        $5, $5, 2
    /* 3BFEFC 004BFEFC 21280502 */  addu       $5, $16, $5
    /* 3BFF00 004BFF00 1A00130C */  jal        func_004c0068
    /* 3BFF04 004BFF04 1800A524 */   addiu     $5, $5, 0x18
    /* 3BFF08 004BFF08 0A000010 */  b          .L004BFF34
    /* 3BFF0C 004BFF0C 00000000 */   nop
  .L004BFF10:
    /* 3BFF10 004BFF10 2D200002 */  daddu      $4, $16, $0
    /* 3BFF14 004BFF14 2D300000 */  daddu      $6, $0, $0
    /* 3BFF18 004BFF18 01000724 */  addiu      $7, $0, 0x1
    /* 3BFF1C 004BFF1C 40280200 */  sll        $5, $2, 1
    /* 3BFF20 004BFF20 2128A200 */  addu       $5, $5, $2
    /* 3BFF24 004BFF24 80280500 */  sll        $5, $5, 2
    /* 3BFF28 004BFF28 21280502 */  addu       $5, $16, $5
    /* 3BFF2C 004BFF2C 4600130C */  jal        func_004c0118
    /* 3BFF30 004BFF30 1800A524 */   addiu     $5, $5, 0x18
  .L004BFF34:
    /* 3BFF34 004BFF34 9CF5120C */  jal        func_004bd670
    /* 3BFF38 004BFF38 00000000 */   nop
    /* 3BFF3C 004BFF3C 01000224 */  addiu      $2, $0, 0x1
    /* 3BFF40 004BFF40 0D002256 */  bnel       $17, $2, .L004BFF78
    /* 3BFF44 004BFF44 0000B0DF */   ld        $16, 0x0($29)
    /* 3BFF48 004BFF48 1000028E */  lw         $2, 0x10($16)
    /* 3BFF4C 004BFF4C 2D200002 */  daddu      $4, $16, $0
    /* 3BFF50 004BFF50 40280200 */  sll        $5, $2, 1
    /* 3BFF54 004BFF54 2128A200 */  addu       $5, $5, $2
    /* 3BFF58 004BFF58 80280500 */  sll        $5, $5, 2
    /* 3BFF5C 004BFF5C 21280502 */  addu       $5, $16, $5
    /* 3BFF60 004BFF60 4601130C */  jal        func_004c0518
    /* 3BFF64 004BFF64 1800A524 */   addiu     $5, $5, 0x18
    /* 3BFF68 004BFF68 2D200002 */  daddu      $4, $16, $0
    /* 3BFF6C 004BFF6C E6FF120C */  jal        func_004bff98
    /* 3BFF70 004BFF70 2D288002 */   daddu     $5, $20, $0
    /* 3BFF74 004BFF74 0000B0DF */  ld         $16, 0x0($29)
  .L004BFF78:
    /* 3BFF78 004BFF78 0800B1DF */  ld         $17, 0x8($29)
    /* 3BFF7C 004BFF7C 1000B2DF */  ld         $18, 0x10($29)
    /* 3BFF80 004BFF80 1800B3DF */  ld         $19, 0x18($29)
    /* 3BFF84 004BFF84 2000B4DF */  ld         $20, 0x20($29)
    /* 3BFF88 004BFF88 2800BFDF */  ld         $31, 0x28($29)
    /* 3BFF8C 004BFF8C 0800E003 */  jr         $31
    /* 3BFF90 004BFF90 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BFF94 004BFF94 00000000 */  nop
.size func_004bfca0, 0x2f8
