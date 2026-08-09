.section .text
.set noat
.set noreorder
glabel func_003ebde0
    /* 2EBDE0 003EBDE0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2EBDE4 003EBDE4 20000224 */  addiu      $2, $0, 0x20
    /* 2EBDE8 003EBDE8 0000BFFF */  sd         $31, 0x0($29)
    /* 2EBDEC 003EBDEC 0C00838C */  lw         $3, 0xC($4)
    /* 2EBDF0 003EBDF0 2A006210 */  beq        $3, $2, .L003EBE9C
    /* 2EBDF4 003EBDF4 00000000 */   nop
    /* 2EBDF8 003EBDF8 08000224 */  addiu      $2, $0, 0x8
    /* 2EBDFC 003EBDFC 06006210 */  beq        $3, $2, .L003EBE18
    /* 2EBE00 003EBE00 00000000 */   nop
    /* 2EBE04 003EBE04 04000224 */  addiu      $2, $0, 0x4
    /* 2EBE08 003EBE08 03006210 */  beq        $3, $2, .L003EBE18
    /* 2EBE0C 003EBE0C 00000000 */   nop
    /* 2EBE10 003EBE10 49000010 */  b          .L003EBF38
    /* 2EBE14 003EBE14 00000000 */   nop
  .L003EBE18:
    /* 2EBE18 003EBE18 1800888C */  lw         $8, 0x18($4)
    /* 2EBE1C 003EBE1C 01000224 */  addiu      $2, $0, 0x1
    /* 2EBE20 003EBE20 54000011 */  beqz       $8, .L003EBF74
    /* 2EBE24 003EBE24 04306200 */   sllv      $6, $2, $3
    /* 2EBE28 003EBE28 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EBE2C 003EBE2C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EBE30 003EBE30 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EBE34 003EBE34 2D480001 */  daddu      $9, $8, $0
    /* 2EBE38 003EBE38 FFFFC724 */  addiu      $7, $6, -0x1
    /* 2EBE3C 003EBE3C 21104300 */  addu       $2, $2, $3
    /* 2EBE40 003EBE40 4700C010 */  beqz       $6, .L003EBF60
    /* 2EBE44 003EBE44 0C004524 */   addiu     $5, $2, 0xC
  .L003EBE48:
    /* 2EBE48 003EBE48 00000391 */  lbu        $3, 0x0($8)
    /* 2EBE4C 003EBE4C 2D10E000 */  daddu      $2, $7, $0
    /* 2EBE50 003EBE50 FFFFE724 */  addiu      $7, $7, -0x1
    /* 2EBE54 003EBE54 2118A300 */  addu       $3, $5, $3
    /* 2EBE58 003EBE58 00006390 */  lbu        $3, 0x0($3)
    /* 2EBE5C 003EBE5C 000023A1 */  sb         $3, 0x0($9)
    /* 2EBE60 003EBE60 01000391 */  lbu        $3, 0x1($8)
    /* 2EBE64 003EBE64 2118A300 */  addu       $3, $5, $3
    /* 2EBE68 003EBE68 00006390 */  lbu        $3, 0x0($3)
    /* 2EBE6C 003EBE6C 010023A1 */  sb         $3, 0x1($9)
    /* 2EBE70 003EBE70 02000391 */  lbu        $3, 0x2($8)
    /* 2EBE74 003EBE74 2118A300 */  addu       $3, $5, $3
    /* 2EBE78 003EBE78 00006390 */  lbu        $3, 0x0($3)
    /* 2EBE7C 003EBE7C 020023A1 */  sb         $3, 0x2($9)
    /* 2EBE80 003EBE80 03000391 */  lbu        $3, 0x3($8)
    /* 2EBE84 003EBE84 030023A1 */  sb         $3, 0x3($9)
    /* 2EBE88 003EBE88 04000825 */  addiu      $8, $8, 0x4
    /* 2EBE8C 003EBE8C EEFF4014 */  bnez       $2, .L003EBE48
    /* 2EBE90 003EBE90 04002925 */   addiu     $9, $9, 0x4
    /* 2EBE94 003EBE94 33000010 */  b          .L003EBF64
    /* 2EBE98 003EBE98 0000838C */   lw        $3, 0x0($4)
  .L003EBE9C:
    /* 2EBE9C 003EBE9C 14008B8C */  lw         $11, 0x14($4)
    /* 2EBEA0 003EBEA0 0800858C */  lw         $5, 0x8($4)
    /* 2EBEA4 003EBEA4 3C006011 */  beqz       $11, .L003EBF98
    /* 2EBEA8 003EBEA8 04008A8C */   lw        $10, 0x4($4)
    /* 2EBEAC 003EBEAC 2A080500 */  slt        $1, $0, $5
    /* 2EBEB0 003EBEB0 2B002010 */  beqz       $1, .L003EBF60
    /* 2EBEB4 003EBEB4 2D480000 */   daddu     $9, $0, $0
    /* 2EBEB8 003EBEB8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EBEBC 003EBEBC FFFF4225 */  addiu      $2, $10, -0x1
    /* 2EBEC0 003EBEC0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
  .L003EBEC4:
    /* 2EBEC4 003EBEC4 C8B78C8F */  lw         $12, -0x4838($28)
    /* 2EBEC8 003EBEC8 2D386001 */  daddu      $7, $11, $0
    /* 2EBECC 003EBECC 2D406001 */  daddu      $8, $11, $0
    /* 2EBED0 003EBED0 2D304000 */  daddu      $6, $2, $0
    /* 2EBED4 003EBED4 21606C00 */  addu       $12, $3, $12
    /* 2EBED8 003EBED8 39004011 */  beqz       $10, .L003EBFC0
    /* 2EBEDC 003EBEDC 0C008E25 */   addiu     $14, $12, 0xC
  .L003EBEE0:
    /* 2EBEE0 003EBEE0 0000ED90 */  lbu        $13, 0x0($7)
    /* 2EBEE4 003EBEE4 2D60C000 */  daddu      $12, $6, $0
    /* 2EBEE8 003EBEE8 FFFFC624 */  addiu      $6, $6, -0x1
    /* 2EBEEC 003EBEEC 2168CD01 */  addu       $13, $14, $13
    /* 2EBEF0 003EBEF0 0000AD91 */  lbu        $13, 0x0($13)
    /* 2EBEF4 003EBEF4 00000DA1 */  sb         $13, 0x0($8)
    /* 2EBEF8 003EBEF8 0100ED90 */  lbu        $13, 0x1($7)
    /* 2EBEFC 003EBEFC 2168CD01 */  addu       $13, $14, $13
    /* 2EBF00 003EBF00 0000AD91 */  lbu        $13, 0x0($13)
    /* 2EBF04 003EBF04 01000DA1 */  sb         $13, 0x1($8)
    /* 2EBF08 003EBF08 0200ED90 */  lbu        $13, 0x2($7)
    /* 2EBF0C 003EBF0C 2168CD01 */  addu       $13, $14, $13
    /* 2EBF10 003EBF10 0000AD91 */  lbu        $13, 0x0($13)
    /* 2EBF14 003EBF14 02000DA1 */  sb         $13, 0x2($8)
    /* 2EBF18 003EBF18 0300ED90 */  lbu        $13, 0x3($7)
    /* 2EBF1C 003EBF1C 03000DA1 */  sb         $13, 0x3($8)
    /* 2EBF20 003EBF20 0400E724 */  addiu      $7, $7, 0x4
    /* 2EBF24 003EBF24 EEFF8015 */  bnez       $12, .L003EBEE0
    /* 2EBF28 003EBF28 04000825 */   addiu     $8, $8, 0x4
    /* 2EBF2C 003EBF2C 25000010 */  b          .L003EBFC4
    /* 2EBF30 003EBF30 1000878C */   lw        $7, 0x10($4)
    /* 2EBF34 003EBF34 00000000 */  nop
  .L003EBF38:
    /* 2EBF38 003EBF38 01000224 */  addiu      $2, $0, 0x1
    /* 2EBF3C 003EBF3C 1800A2AF */  sw         $2, 0x18($29)
    /* 2EBF40 003EBF40 0080023C */  lui        $2, (0x80000008 >> 16)
    /* 2EBF44 003EBF44 647D0F0C */  jal        func_003df590
    /* 2EBF48 003EBF48 08004434 */   ori       $4, $2, (0x80000008 & 0xFFFF)
    /* 2EBF4C 003EBF4C 1C00A2AF */  sw         $2, 0x1C($29)
    /* 2EBF50 003EBF50 347D0F0C */  jal        func_003df4d0
    /* 2EBF54 003EBF54 1800A427 */   addiu     $4, $29, 0x18
    /* 2EBF58 003EBF58 20000010 */  b          .L003EBFDC
    /* 2EBF5C 003EBF5C 2D100000 */   daddu     $2, $0, $0
  .L003EBF60:
    /* 2EBF60 003EBF60 0000838C */  lw         $3, 0x0($4)
  .L003EBF64:
    /* 2EBF64 003EBF64 2D108000 */  daddu      $2, $4, $0
    /* 2EBF68 003EBF68 02006334 */  ori        $3, $3, 0x2
    /* 2EBF6C 003EBF6C 1B000010 */  b          .L003EBFDC
    /* 2EBF70 003EBF70 000083AC */   sw        $3, 0x0($4)
  .L003EBF74:
    /* 2EBF74 003EBF74 2800A2AF */  sw         $2, 0x28($29)
    /* 2EBF78 003EBF78 0080023C */  lui        $2, (0x80000016 >> 16)
    /* 2EBF7C 003EBF7C 647D0F0C */  jal        func_003df590
    /* 2EBF80 003EBF80 16004434 */   ori       $4, $2, (0x80000016 & 0xFFFF)
    /* 2EBF84 003EBF84 2C00A2AF */  sw         $2, 0x2C($29)
    /* 2EBF88 003EBF88 347D0F0C */  jal        func_003df4d0
    /* 2EBF8C 003EBF8C 2800A427 */   addiu     $4, $29, 0x28
    /* 2EBF90 003EBF90 12000010 */  b          .L003EBFDC
    /* 2EBF94 003EBF94 2D100000 */   daddu     $2, $0, $0
  .L003EBF98:
    /* 2EBF98 003EBF98 01000324 */  addiu      $3, $0, 0x1
    /* 2EBF9C 003EBF9C 0080023C */  lui        $2, (0x80000016 >> 16)
    /* 2EBFA0 003EBFA0 2000A3AF */  sw         $3, 0x20($29)
    /* 2EBFA4 003EBFA4 647D0F0C */  jal        func_003df590
    /* 2EBFA8 003EBFA8 16004434 */   ori       $4, $2, (0x80000016 & 0xFFFF)
    /* 2EBFAC 003EBFAC 2400A2AF */  sw         $2, 0x24($29)
    /* 2EBFB0 003EBFB0 347D0F0C */  jal        func_003df4d0
    /* 2EBFB4 003EBFB4 2000A427 */   addiu     $4, $29, 0x20
    /* 2EBFB8 003EBFB8 08000010 */  b          .L003EBFDC
    /* 2EBFBC 003EBFBC 2D100000 */   daddu     $2, $0, $0
  .L003EBFC0:
    /* 2EBFC0 003EBFC0 1000878C */  lw         $7, 0x10($4)
  .L003EBFC4:
    /* 2EBFC4 003EBFC4 01002925 */  addiu      $9, $9, 0x1
    /* 2EBFC8 003EBFC8 2A302501 */  slt        $6, $9, $5
    /* 2EBFCC 003EBFCC BDFFC014 */  bnez       $6, .L003EBEC4
    /* 2EBFD0 003EBFD0 21586701 */   addu      $11, $11, $7
    /* 2EBFD4 003EBFD4 E2FF0010 */  b          .L003EBF60
    /* 2EBFD8 003EBFD8 00000000 */   nop
  .L003EBFDC:
    /* 2EBFDC 003EBFDC 0000BFDF */  ld         $31, 0x0($29)
    /* 2EBFE0 003EBFE0 0800E003 */  jr         $31
    /* 2EBFE4 003EBFE4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2EBFE8 003EBFE8 00000000 */  nop
    /* 2EBFEC 003EBFEC 00000000 */  nop
.size func_003ebde0, 0x210
