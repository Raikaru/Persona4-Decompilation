.section .text
.set noat
.set noreorder
glabel func_001ece50
    /* ECE50 001ECE50 A0FFBD27 */  addiu      $29, $29, -0x60
    /* ECE54 001ECE54 5000BFFF */  sd         $31, 0x50($29)
    /* ECE58 001ECE58 4000B37F */  sq         $19, 0x40($29)
    /* ECE5C 001ECE5C 3000B27F */  sq         $18, 0x30($29)
    /* ECE60 001ECE60 2000B17F */  sq         $17, 0x20($29)
    /* ECE64 001ECE64 1000B07F */  sq         $16, 0x10($29)
    /* ECE68 001ECE68 0000B4E7 */  swc1       $f20, 0x0($29)
    /* ECE6C 001ECE6C 2D988000 */  daddu      $19, $4, $0
    /* ECE70 001ECE70 2D90A000 */  daddu      $18, $5, $0
    /* ECE74 001ECE74 06650046 */  mov.s      $f20, $f12
    /* ECE78 001ECE78 ACB3828F */  lw         $2, -0x4C54($28)
    /* ECE7C 001ECE7C 1803518C */  lw         $17, 0x318($2)
    /* ECE80 001ECE80 69000010 */  b          .L001ED028
    /* ECE84 001ECE84 00000000 */   nop
  .L001ECE88:
    /* ECE88 001ECE88 000062C6 */  lwc1       $f2, 0x0($19)
    /* ECE8C 001ECE8C 080023C6 */  lwc1       $f3, 0x8($17)
    /* ECE90 001ECE90 34180246 */  c.lt.s     $f3, $f2
    /* ECE94 001ECE94 0E000045 */  bc1f       .L001ECED0
    /* ECE98 001ECE98 00000000 */   nop
    /* ECE9C 001ECE9C 040061C6 */  lwc1       $f1, 0x4($19)
    /* ECEA0 001ECEA0 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* ECEA4 001ECEA4 34000146 */  c.lt.s     $f0, $f1
    /* ECEA8 001ECEA8 09000045 */  bc1f       .L001ECED0
    /* ECEAC 001ECEAC 00000000 */   nop
    /* ECEB0 001ECEB0 680220C6 */  lwc1       $f0, 0x268($17)
    /* ECEB4 001ECEB4 36000246 */  c.le.s     $f0, $f2
    /* ECEB8 001ECEB8 05000145 */  bc1t       .L001ECED0
    /* ECEBC 001ECEBC 00000000 */   nop
    /* ECEC0 001ECEC0 6C0220C6 */  lwc1       $f0, 0x26C($17)
    /* ECEC4 001ECEC4 36000146 */  c.le.s     $f0, $f1
    /* ECEC8 001ECEC8 56000045 */  bc1f       .L001ED024
    /* ECECC 001ECECC 00000000 */   nop
  .L001ECED0:
    /* ECED0 001ECED0 000042C6 */  lwc1       $f2, 0x0($18)
    /* ECED4 001ECED4 34180246 */  c.lt.s     $f3, $f2
    /* ECED8 001ECED8 0E000045 */  bc1f       .L001ECF14
    /* ECEDC 001ECEDC 00000000 */   nop
    /* ECEE0 001ECEE0 040041C6 */  lwc1       $f1, 0x4($18)
    /* ECEE4 001ECEE4 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* ECEE8 001ECEE8 34000146 */  c.lt.s     $f0, $f1
    /* ECEEC 001ECEEC 09000045 */  bc1f       .L001ECF14
    /* ECEF0 001ECEF0 00000000 */   nop
    /* ECEF4 001ECEF4 680220C6 */  lwc1       $f0, 0x268($17)
    /* ECEF8 001ECEF8 36000246 */  c.le.s     $f0, $f2
    /* ECEFC 001ECEFC 05000145 */  bc1t       .L001ECF14
    /* ECF00 001ECF00 00000000 */   nop
    /* ECF04 001ECF04 6C0220C6 */  lwc1       $f0, 0x26C($17)
    /* ECF08 001ECF08 36000146 */  c.le.s     $f0, $f1
    /* ECF0C 001ECF0C 45000045 */  bc1f       .L001ED024
    /* ECF10 001ECF10 00000000 */   nop
  .L001ECF14:
    /* ECF14 001ECF14 2D800000 */  daddu      $16, $0, $0
    /* ECF18 001ECF18 3F000010 */  b          .L001ED018
    /* ECF1C 001ECF1C 00000000 */   nop
  .L001ECF20:
    /* ECF20 001ECF20 01000226 */  addiu      $2, $16, 0x1
    /* ECF24 001ECF24 03004330 */  andi       $3, $2, 0x3
    /* ECF28 001ECF28 C0100300 */  sll        $2, $3, 3
    /* ECF2C 001ECF2C 21104300 */  addu       $2, $2, $3
    /* ECF30 001ECF30 40100200 */  sll        $2, $2, 1
    /* ECF34 001ECF34 21104300 */  addu       $2, $2, $3
    /* ECF38 001ECF38 00110200 */  sll        $2, $2, 4
    /* ECF3C 001ECF3C 21102202 */  addu       $2, $17, $2
    /* ECF40 001ECF40 08004824 */  addiu      $8, $2, 0x8
    /* ECF44 001ECF44 C0101000 */  sll        $2, $16, 3
    /* ECF48 001ECF48 21105000 */  addu       $2, $2, $16
    /* ECF4C 001ECF4C 40100200 */  sll        $2, $2, 1
    /* ECF50 001ECF50 21105000 */  addu       $2, $2, $16
    /* ECF54 001ECF54 00110200 */  sll        $2, $2, 4
    /* ECF58 001ECF58 21102202 */  addu       $2, $17, $2
    /* ECF5C 001ECF5C 08004724 */  addiu      $7, $2, 0x8
    /* ECF60 001ECF60 2D20E000 */  daddu      $4, $7, $0
    /* ECF64 001ECF64 2D280001 */  daddu      $5, $8, $0
    /* ECF68 001ECF68 2D306002 */  daddu      $6, $19, $0
    /* ECF6C 001ECF6C 78B3070C */  jal        func_001ecde0
    /* ECF70 001ECF70 00000000 */   nop
    /* ECF74 001ECF74 2D184000 */  daddu      $3, $2, $0
    /* ECF78 001ECF78 2D304002 */  daddu      $6, $18, $0
    /* ECF7C 001ECF7C 78B3070C */  jal        func_001ecde0
    /* ECF80 001ECF80 00000000 */   nop
    /* ECF84 001ECF84 12006210 */  beq        $3, $2, .L001ECFD0
    /* ECF88 001ECF88 00000000 */   nop
    /* ECF8C 001ECF8C 2D206002 */  daddu      $4, $19, $0
    /* ECF90 001ECF90 2D284002 */  daddu      $5, $18, $0
    /* ECF94 001ECF94 2D30E000 */  daddu      $6, $7, $0
    /* ECF98 001ECF98 78B3070C */  jal        func_001ecde0
    /* ECF9C 001ECF9C 00000000 */   nop
    /* ECFA0 001ECFA0 2D184000 */  daddu      $3, $2, $0
    /* ECFA4 001ECFA4 2D300001 */  daddu      $6, $8, $0
    /* ECFA8 001ECFA8 78B3070C */  jal        func_001ecde0
    /* ECFAC 001ECFAC 00000000 */   nop
    /* ECFB0 001ECFB0 04006210 */  beq        $3, $2, .L001ECFC4
    /* ECFB4 001ECFB4 00000000 */   nop
    /* ECFB8 001ECFB8 01000224 */  addiu      $2, $0, 0x1
    /* ECFBC 001ECFBC 05000010 */  b          .L001ECFD4
    /* ECFC0 001ECFC0 00000000 */   nop
  .L001ECFC4:
    /* ECFC4 001ECFC4 2D100000 */  daddu      $2, $0, $0
    /* ECFC8 001ECFC8 02000010 */  b          .L001ECFD4
    /* ECFCC 001ECFCC 00000000 */   nop
  .L001ECFD0:
    /* ECFD0 001ECFD0 2D100000 */  daddu      $2, $0, $0
  .L001ECFD4:
    /* ECFD4 001ECFD4 04004010 */  beqz       $2, .L001ECFE8
    /* ECFD8 001ECFD8 00000000 */   nop
    /* ECFDC 001ECFDC 01000224 */  addiu      $2, $0, 0x1
    /* ECFE0 001ECFE0 14000010 */  b          .L001ED034
    /* ECFE4 001ECFE4 00000000 */   nop
  .L001ECFE8:
    /* ECFE8 001ECFE8 2D206002 */  daddu      $4, $19, $0
    /* ECFEC 001ECFEC 2D284002 */  daddu      $5, $18, $0
    /* ECFF0 001ECFF0 2D30E000 */  daddu      $6, $7, $0
    /* ECFF4 001ECFF4 06A30046 */  mov.s      $f12, $f20
    /* ECFF8 001ECFF8 30B2070C */  jal        func_001ec8c0
    /* ECFFC 001ECFFC 00000000 */   nop
    /* ED000 001ED000 04004010 */  beqz       $2, .L001ED014
    /* ED004 001ED004 00000000 */   nop
    /* ED008 001ED008 01000224 */  addiu      $2, $0, 0x1
    /* ED00C 001ED00C 09000010 */  b          .L001ED034
    /* ED010 001ED010 00000000 */   nop
  .L001ED014:
    /* ED014 001ED014 01001026 */  addiu      $16, $16, 0x1
  .L001ED018:
    /* ED018 001ED018 0400022A */  slti       $2, $16, 0x4
    /* ED01C 001ED01C C0FF4014 */  bnez       $2, .L001ECF20
    /* ED020 001ED020 00000000 */   nop
  .L001ED024:
    /* ED024 001ED024 CC04318E */  lw         $17, 0x4CC($17)
  .L001ED028:
    /* ED028 001ED028 97FF2016 */  bnez       $17, .L001ECE88
    /* ED02C 001ED02C 00000000 */   nop
    /* ED030 001ED030 2D100000 */  daddu      $2, $0, $0
  .L001ED034:
    /* ED034 001ED034 5000BFDF */  ld         $31, 0x50($29)
    /* ED038 001ED038 4000B37B */  lq         $19, 0x40($29)
    /* ED03C 001ED03C 3000B27B */  lq         $18, 0x30($29)
    /* ED040 001ED040 2000B17B */  lq         $17, 0x20($29)
    /* ED044 001ED044 1000B07B */  lq         $16, 0x10($29)
    /* ED048 001ED048 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* ED04C 001ED04C 6000BD27 */  addiu      $29, $29, 0x60
    /* ED050 001ED050 0800E003 */  jr         $31
    /* ED054 001ED054 00000000 */   nop
    /* ED058 001ED058 00000000 */  nop
    /* ED05C 001ED05C 00000000 */  nop
.size func_001ece50, 0x210
