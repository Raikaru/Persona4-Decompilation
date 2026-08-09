.section .text
.set noat
.set noreorder
glabel func_0014be50
    /* 4BE50 0014BE50 90FFBD27 */  addiu      $29, $29, -0x70
    /* 4BE54 0014BE54 4000BFFF */  sd         $31, 0x40($29)
    /* 4BE58 0014BE58 3000B37F */  sq         $19, 0x30($29)
    /* 4BE5C 0014BE5C 2000B27F */  sq         $18, 0x20($29)
    /* 4BE60 0014BE60 1000B17F */  sq         $17, 0x10($29)
    /* 4BE64 0014BE64 0000B07F */  sq         $16, 0x0($29)
    /* 4BE68 0014BE68 2D988000 */  daddu      $19, $4, $0
    /* 4BE6C 0014BE6C 2D90A000 */  daddu      $18, $5, $0
    /* 4BE70 0014BE70 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* 4BE74 0014BE74 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* 4BE78 0014BE78 0D000424 */  addiu      $4, $0, 0xD
    /* 4BE7C 0014BE7C AC14050C */  jal        func_001452b0
    /* 4BE80 0014BE80 00000000 */   nop
    /* 4BE84 0014BE84 2D804000 */  daddu      $16, $2, $0
    /* 4BE88 0014BE88 8028050C */  jal        func_0014a200
    /* 4BE8C 0014BE8C 00000000 */   nop
    /* 4BE90 0014BE90 01000324 */  addiu      $3, $0, 0x1
    /* 4BE94 0014BE94 4B004314 */  bne        $2, $3, .L0014BFC4
    /* 4BE98 0014BE98 00000000 */   nop
    /* 4BE9C 0014BE9C FFFF0234 */  ori        $2, $0, 0xFFFF
    /* 4BEA0 0014BEA0 4B000010 */  b          .L0014BFD0
    /* 4BEA4 0014BEA4 00000000 */   nop
  .L0014BEA8:
    /* 4BEA8 0014BEA8 5000A627 */  addiu      $6, $29, 0x50
    /* 4BEAC 0014BEAC 5F00023C */  lui        $2, %hi(D_005EFB98)
    /* 4BEB0 0014BEB0 98FB43DC */  ld         $3, %lo(D_005EFB98)($2)
    /* 4BEB4 0014BEB4 5F00023C */  lui        $2, %hi(D_005EFBA0)
    /* 4BEB8 0014BEB8 A0FB40C4 */  lwc1       $f0, %lo(D_005EFBA0)($2)
    /* 4BEBC 0014BEBC 5000A3FF */  sd         $3, 0x50($29)
    /* 4BEC0 0014BEC0 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 4BEC4 0014BEC4 5C010226 */  addiu      $2, $16, 0x15C
    /* 4BEC8 0014BEC8 6000A2AF */  sw         $2, 0x60($29)
    /* 4BECC 0014BECC 68010226 */  addiu      $2, $16, 0x168
    /* 4BED0 0014BED0 6400A2AF */  sw         $2, 0x64($29)
    /* 4BED4 0014BED4 74010226 */  addiu      $2, $16, 0x174
    /* 4BED8 0014BED8 6800A2AF */  sw         $2, 0x68($29)
    /* 4BEDC 0014BEDC 2D206002 */  daddu      $4, $19, $0
    /* 4BEE0 0014BEE0 6000A527 */  addiu      $5, $29, 0x60
    /* 4BEE4 0014BEE4 B0A3050C */  jal        func_00168ec0
    /* 4BEE8 0014BEE8 00000000 */   nop
    /* 4BEEC 0014BEEC 01000324 */  addiu      $3, $0, 0x1
    /* 4BEF0 0014BEF0 13004314 */  bne        $2, $3, .L0014BF40
    /* 4BEF4 0014BEF4 00000000 */   nop
    /* 4BEF8 0014BEF8 6000A28F */  lw         $2, 0x60($29)
    /* 4BEFC 0014BEFC 040043C4 */  lwc1       $f3, 0x4($2)
    /* 4BF00 0014BF00 040062C6 */  lwc1       $f2, 0x4($19)
    /* 4BF04 0014BF04 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 4BF08 0014BF08 00088244 */  mtc1       $2, $f1
    /* 4BF0C 0014BF0C 00000000 */  nop
    /* 4BF10 0014BF10 00080346 */  add.s      $f0, $f1, $f3
    /* 4BF14 0014BF14 34100046 */  c.lt.s     $f2, $f0
    /* 4BF18 0014BF18 09000045 */  bc1f       .L0014BF40
    /* 4BF1C 0014BF1C 00000000 */   nop
    /* 4BF20 0014BF20 01180146 */  sub.s      $f0, $f3, $f1
    /* 4BF24 0014BF24 36100046 */  c.le.s     $f2, $f0
    /* 4BF28 0014BF28 05000145 */  bc1t       .L0014BF40
    /* 4BF2C 0014BF2C 00000000 */   nop
    /* 4BF30 0014BF30 00001196 */  lhu        $17, 0x0($16)
    /* 4BF34 0014BF34 000050AE */  sw         $16, 0x0($18)
    /* 4BF38 0014BF38 24000010 */  b          .L0014BFCC
    /* 4BF3C 0014BF3C 00000000 */   nop
  .L0014BF40:
    /* 4BF40 0014BF40 68010226 */  addiu      $2, $16, 0x168
    /* 4BF44 0014BF44 6000A2AF */  sw         $2, 0x60($29)
    /* 4BF48 0014BF48 74010226 */  addiu      $2, $16, 0x174
    /* 4BF4C 0014BF4C 6400A2AF */  sw         $2, 0x64($29)
    /* 4BF50 0014BF50 80010226 */  addiu      $2, $16, 0x180
    /* 4BF54 0014BF54 6800A2AF */  sw         $2, 0x68($29)
    /* 4BF58 0014BF58 2D206002 */  daddu      $4, $19, $0
    /* 4BF5C 0014BF5C 6000A527 */  addiu      $5, $29, 0x60
    /* 4BF60 0014BF60 5000A627 */  addiu      $6, $29, 0x50
    /* 4BF64 0014BF64 B0A3050C */  jal        func_00168ec0
    /* 4BF68 0014BF68 00000000 */   nop
    /* 4BF6C 0014BF6C 01000324 */  addiu      $3, $0, 0x1
    /* 4BF70 0014BF70 13004314 */  bne        $2, $3, .L0014BFC0
    /* 4BF74 0014BF74 00000000 */   nop
    /* 4BF78 0014BF78 6000A28F */  lw         $2, 0x60($29)
    /* 4BF7C 0014BF7C 040043C4 */  lwc1       $f3, 0x4($2)
    /* 4BF80 0014BF80 040062C6 */  lwc1       $f2, 0x4($19)
    /* 4BF84 0014BF84 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 4BF88 0014BF88 00088244 */  mtc1       $2, $f1
    /* 4BF8C 0014BF8C 00000000 */  nop
    /* 4BF90 0014BF90 00080346 */  add.s      $f0, $f1, $f3
    /* 4BF94 0014BF94 34100046 */  c.lt.s     $f2, $f0
    /* 4BF98 0014BF98 09000045 */  bc1f       .L0014BFC0
    /* 4BF9C 0014BF9C 00000000 */   nop
    /* 4BFA0 0014BFA0 01180146 */  sub.s      $f0, $f3, $f1
    /* 4BFA4 0014BFA4 36100046 */  c.le.s     $f2, $f0
    /* 4BFA8 0014BFA8 05000145 */  bc1t       .L0014BFC0
    /* 4BFAC 0014BFAC 00000000 */   nop
    /* 4BFB0 0014BFB0 00001196 */  lhu        $17, 0x0($16)
    /* 4BFB4 0014BFB4 000050AE */  sw         $16, 0x0($18)
    /* 4BFB8 0014BFB8 04000010 */  b          .L0014BFCC
    /* 4BFBC 0014BFBC 00000000 */   nop
  .L0014BFC0:
    /* 4BFC0 0014BFC0 3801108E */  lw         $16, 0x138($16)
  .L0014BFC4:
    /* 4BFC4 0014BFC4 B8FF0016 */  bnez       $16, .L0014BEA8
    /* 4BFC8 0014BFC8 00000000 */   nop
  .L0014BFCC:
    /* 4BFCC 0014BFCC 2D102002 */  daddu      $2, $17, $0
  .L0014BFD0:
    /* 4BFD0 0014BFD0 4000BFDF */  ld         $31, 0x40($29)
    /* 4BFD4 0014BFD4 3000B37B */  lq         $19, 0x30($29)
    /* 4BFD8 0014BFD8 2000B27B */  lq         $18, 0x20($29)
    /* 4BFDC 0014BFDC 1000B17B */  lq         $17, 0x10($29)
    /* 4BFE0 0014BFE0 0000B07B */  lq         $16, 0x0($29)
    /* 4BFE4 0014BFE4 7000BD27 */  addiu      $29, $29, 0x70
    /* 4BFE8 0014BFE8 0800E003 */  jr         $31
    /* 4BFEC 0014BFEC 00000000 */   nop
.size func_0014be50, 0x1a0
