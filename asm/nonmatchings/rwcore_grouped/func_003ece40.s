.section .text
.set noat
.set noreorder
glabel func_003ece40
    /* 2ECE40 003ECE40 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2ECE44 003ECE44 2D700001 */  daddu      $14, $8, $0
    /* 2ECE48 003ECE48 4000BFFF */  sd         $31, 0x40($29)
    /* 2ECE4C 003ECE4C 8037033C */  lui        $3, (0x37800000 >> 16)
    /* 2ECE50 003ECE50 3000B37F */  sq         $19, 0x30($29)
    /* 2ECE54 003ECE54 00008344 */  mtc1       $3, $f0
    /* 2ECE58 003ECE58 2000B27F */  sq         $18, 0x20($29)
    /* 2ECE5C 003ECE5C 03640E00 */  sra        $12, $14, 16
    /* 2ECE60 003ECE60 1000B17F */  sq         $17, 0x10($29)
    /* 2ECE64 003ECE64 2D682001 */  daddu      $13, $9, $0
    /* 2ECE68 003ECE68 0000B07F */  sq         $16, 0x0($29)
    /* 2ECE6C 003ECE6C 2DC08000 */  daddu      $24, $4, $0
    /* 2ECE70 003ECE70 2D80E000 */  daddu      $16, $7, $0
    /* 2ECE74 003ECE74 2D78A000 */  daddu      $15, $5, $0
    /* 2ECE78 003ECE78 2340D001 */  subu       $8, $14, $16
    /* 2ECE7C 003ECE7C 031C1000 */  sra        $3, $16, 16
    /* 2ECE80 003ECE80 00088844 */  mtc1       $8, $f1
    /* 2ECE84 003ECE84 00000000 */  nop
    /* 2ECE88 003ECE88 60088046 */  cvt.s.w    $f1, $f1
    /* 2ECE8C 003ECE8C 38006C10 */  beq        $3, $12, .L003ECF70
    /* 2ECE90 003ECE90 42020146 */   mul.s     $f9, $f0, $f1
    /* 2ECE94 003ECE94 01006324 */  addiu      $3, $3, 0x1
    /* 2ECE98 003ECE98 2D40A001 */  daddu      $8, $13, $0
    /* 2ECE9C 003ECE9C 10B20F0C */  jal        func_003ec840
    /* 2ECEA0 003ECEA0 009C0300 */   sll       $19, $3, 16
    /* 2ECEA4 003ECEA4 23207002 */  subu       $4, $19, $16
    /* 2ECEA8 003ECEA8 8037033C */  lui        $3, (0x37800000 >> 16)
    /* 2ECEAC 003ECEAC 00088444 */  mtc1       $4, $f1
    /* 2ECEB0 003ECEB0 03941300 */  sra        $18, $19, 16
    /* 2ECEB4 003ECEB4 00008344 */  mtc1       $3, $f0
    /* 2ECEB8 003ECEB8 00000000 */  nop
    /* 2ECEBC 003ECEBC 60088046 */  cvt.s.w    $f1, $f1
    /* 2ECEC0 003ECEC0 42000146 */  mul.s      $f1, $f0, $f1
    /* 2ECEC4 003ECEC4 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2ECEC8 003ECEC8 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECECC 003ECECC 0000A0E5 */  swc1       $f0, 0x0($13)
    /* 2ECED0 003ECED0 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2ECED4 003ECED4 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECED8 003ECED8 0400A0E5 */  swc1       $f0, 0x4($13)
    /* 2ECEDC 003ECEDC 0800A0C5 */  lwc1       $f0, 0x8($13)
    /* 2ECEE0 003ECEE0 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECEE4 003ECEE4 0800A0E5 */  swc1       $f0, 0x8($13)
    /* 2ECEE8 003ECEE8 0C00A0C5 */  lwc1       $f0, 0xC($13)
    /* 2ECEEC 003ECEEC 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECEF0 003ECEF0 3D004C12 */  beq        $18, $12, .L003ECFE8
    /* 2ECEF4 003ECEF4 0C00A0E5 */   swc1      $f0, 0xC($13)
    /* 2ECEF8 003ECEF8 5400B127 */  addiu      $17, $29, 0x54
    /* 2ECEFC 003ECEFC 5800B027 */  addiu      $16, $29, 0x58
    /* 2ECF00 003ECF00 5C00B927 */  addiu      $25, $29, 0x5C
  .L003ECF04:
    /* 2ECF04 003ECF04 2D200003 */  daddu      $4, $24, $0
    /* 2ECF08 003ECF08 2D28E001 */  daddu      $5, $15, $0
    /* 2ECF0C 003ECF0C 2D386002 */  daddu      $7, $19, $0
    /* 2ECF10 003ECF10 10B20F0C */  jal        func_003ec840
    /* 2ECF14 003ECF14 5000A827 */   addiu     $8, $29, 0x50
    /* 2ECF18 003ECF18 0000A1C5 */  lwc1       $f1, 0x0($13)
    /* 2ECF1C 003ECF1C 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2ECF20 003ECF20 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* 2ECF24 003ECF24 01005226 */  addiu      $18, $18, 0x1
    /* 2ECF28 003ECF28 21986302 */  addu       $19, $19, $3
    /* 2ECF2C 003ECF2C 00080046 */  add.s      $f0, $f1, $f0
    /* 2ECF30 003ECF30 0000A0E5 */  swc1       $f0, 0x0($13)
    /* 2ECF34 003ECF34 0400A1C5 */  lwc1       $f1, 0x4($13)
    /* 2ECF38 003ECF38 000020C6 */  lwc1       $f0, 0x0($17)
    /* 2ECF3C 003ECF3C 00080046 */  add.s      $f0, $f1, $f0
    /* 2ECF40 003ECF40 0400A0E5 */  swc1       $f0, 0x4($13)
    /* 2ECF44 003ECF44 0800A1C5 */  lwc1       $f1, 0x8($13)
    /* 2ECF48 003ECF48 000000C6 */  lwc1       $f0, 0x0($16)
    /* 2ECF4C 003ECF4C 00080046 */  add.s      $f0, $f1, $f0
    /* 2ECF50 003ECF50 0800A0E5 */  swc1       $f0, 0x8($13)
    /* 2ECF54 003ECF54 0C00A1C5 */  lwc1       $f1, 0xC($13)
    /* 2ECF58 003ECF58 000020C7 */  lwc1       $f0, 0x0($25)
    /* 2ECF5C 003ECF5C 00080046 */  add.s      $f0, $f1, $f0
    /* 2ECF60 003ECF60 E8FF4C16 */  bne        $18, $12, .L003ECF04
    /* 2ECF64 003ECF64 0C00A0E5 */   swc1      $f0, 0xC($13)
    /* 2ECF68 003ECF68 20000010 */  b          .L003ECFEC
    /* 2ECF6C 003ECF6C 2D200003 */   daddu     $4, $24, $0
  .L003ECF70:
    /* 2ECF70 003ECF70 10B20F0C */  jal        func_003ec840
    /* 2ECF74 003ECF74 2D40A001 */   daddu     $8, $13, $0
    /* 2ECF78 003ECF78 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2ECF7C 003ECF7C 02000946 */  mul.s      $f0, $f0, $f9
    /* 2ECF80 003ECF80 0000A0E5 */  swc1       $f0, 0x0($13)
    /* 2ECF84 003ECF84 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2ECF88 003ECF88 02000946 */  mul.s      $f0, $f0, $f9
    /* 2ECF8C 003ECF8C 0400A0E5 */  swc1       $f0, 0x4($13)
    /* 2ECF90 003ECF90 0800A0C5 */  lwc1       $f0, 0x8($13)
    /* 2ECF94 003ECF94 02000946 */  mul.s      $f0, $f0, $f9
    /* 2ECF98 003ECF98 0800A0E5 */  swc1       $f0, 0x8($13)
    /* 2ECF9C 003ECF9C 0C00A0C5 */  lwc1       $f0, 0xC($13)
    /* 2ECFA0 003ECFA0 02000946 */  mul.s      $f0, $f0, $f9
    /* 2ECFA4 003ECFA4 0C00A0E5 */  swc1       $f0, 0xC($13)
  .L003ECFA8:
    /* 2ECFA8 003ECFA8 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2ECFAC 003ECFAC 00088344 */  mtc1       $3, $f1
    /* 2ECFB0 003ECFB0 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2ECFB4 003ECFB4 43080946 */  div.s      $f1, $f1, $f9
    /* 2ECFB8 003ECFB8 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECFBC 003ECFBC 0000A0E5 */  swc1       $f0, 0x0($13)
    /* 2ECFC0 003ECFC0 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2ECFC4 003ECFC4 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECFC8 003ECFC8 0400A0E5 */  swc1       $f0, 0x4($13)
    /* 2ECFCC 003ECFCC 0800A0C5 */  lwc1       $f0, 0x8($13)
    /* 2ECFD0 003ECFD0 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECFD4 003ECFD4 0800A0E5 */  swc1       $f0, 0x8($13)
    /* 2ECFD8 003ECFD8 0C00A0C5 */  lwc1       $f0, 0xC($13)
    /* 2ECFDC 003ECFDC 02000146 */  mul.s      $f0, $f0, $f1
    /* 2ECFE0 003ECFE0 2B000010 */  b          .L003ED090
    /* 2ECFE4 003ECFE4 0C00A0E5 */   swc1      $f0, 0xC($13)
  .L003ECFE8:
    /* 2ECFE8 003ECFE8 2D200003 */  daddu      $4, $24, $0
  .L003ECFEC:
    /* 2ECFEC 003ECFEC 2D28E001 */  daddu      $5, $15, $0
    /* 2ECFF0 003ECFF0 2D386002 */  daddu      $7, $19, $0
    /* 2ECFF4 003ECFF4 10B20F0C */  jal        func_003ec840
    /* 2ECFF8 003ECFF8 5000A827 */   addiu     $8, $29, 0x50
    /* 2ECFFC 003ECFFC 2320D301 */  subu       $4, $14, $19
    /* 2ED000 003ED000 8037033C */  lui        $3, (0x37800000 >> 16)
    /* 2ED004 003ED004 00108444 */  mtc1       $4, $f2
    /* 2ED008 003ED008 5400A527 */  addiu      $5, $29, 0x54
    /* 2ED00C 003ED00C 00088344 */  mtc1       $3, $f1
    /* 2ED010 003ED010 A0108046 */  cvt.s.w    $f2, $f2
    /* 2ED014 003ED014 5800A427 */  addiu      $4, $29, 0x58
    /* 2ED018 003ED018 5C00A327 */  addiu      $3, $29, 0x5C
    /* 2ED01C 003ED01C 02090246 */  mul.s      $f4, $f1, $f2
    /* 2ED020 003ED020 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* 2ED024 003ED024 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 2ED028 003ED028 000081C4 */  lwc1       $f1, 0x0($4)
    /* 2ED02C 003ED02C C2000446 */  mul.s      $f3, $f0, $f4
    /* 2ED030 003ED030 000060C4 */  lwc1       $f0, 0x0($3)
    /* 2ED034 003ED034 82100446 */  mul.s      $f2, $f2, $f4
    /* 2ED038 003ED038 42080446 */  mul.s      $f1, $f1, $f4
    /* 2ED03C 003ED03C 02000446 */  mul.s      $f0, $f0, $f4
    /* 2ED040 003ED040 5000A3E7 */  swc1       $f3, 0x50($29)
    /* 2ED044 003ED044 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 2ED048 003ED048 000081E4 */  swc1       $f1, 0x0($4)
    /* 2ED04C 003ED04C 000060E4 */  swc1       $f0, 0x0($3)
    /* 2ED050 003ED050 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2ED054 003ED054 00000346 */  add.s      $f0, $f0, $f3
    /* 2ED058 003ED058 0000A0E5 */  swc1       $f0, 0x0($13)
    /* 2ED05C 003ED05C 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 2ED060 003ED060 0400A1C5 */  lwc1       $f1, 0x4($13)
    /* 2ED064 003ED064 00080046 */  add.s      $f0, $f1, $f0
    /* 2ED068 003ED068 0400A0E5 */  swc1       $f0, 0x4($13)
    /* 2ED06C 003ED06C 000080C4 */  lwc1       $f0, 0x0($4)
    /* 2ED070 003ED070 0800A1C5 */  lwc1       $f1, 0x8($13)
    /* 2ED074 003ED074 00080046 */  add.s      $f0, $f1, $f0
    /* 2ED078 003ED078 0800A0E5 */  swc1       $f0, 0x8($13)
    /* 2ED07C 003ED07C 000060C4 */  lwc1       $f0, 0x0($3)
    /* 2ED080 003ED080 0C00A1C5 */  lwc1       $f1, 0xC($13)
    /* 2ED084 003ED084 00080046 */  add.s      $f0, $f1, $f0
    /* 2ED088 003ED088 C7FF0010 */  b          .L003ECFA8
    /* 2ED08C 003ED08C 0C00A0E5 */   swc1      $f0, 0xC($13)
  .L003ED090:
    /* 2ED090 003ED090 4000BFDF */  ld         $31, 0x40($29)
    /* 2ED094 003ED094 3000B37B */  lq         $19, 0x30($29)
    /* 2ED098 003ED098 2000B27B */  lq         $18, 0x20($29)
    /* 2ED09C 003ED09C 1000B17B */  lq         $17, 0x10($29)
    /* 2ED0A0 003ED0A0 0000B07B */  lq         $16, 0x0($29)
    /* 2ED0A4 003ED0A4 0800E003 */  jr         $31
    /* 2ED0A8 003ED0A8 6000BD27 */   addiu     $29, $29, 0x60
    /* 2ED0AC 003ED0AC 00000000 */  nop
.size func_003ece40, 0x270
