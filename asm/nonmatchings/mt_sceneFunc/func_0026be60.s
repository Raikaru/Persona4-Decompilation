.section .text
.set noat
.set noreorder
glabel func_0026be60
    /* 16BE60 0026BE60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 16BE64 0026BE64 1000BFFF */  sd         $31, 0x10($29)
    /* 16BE68 0026BE68 0000B07F */  sq         $16, 0x0($29)
    /* 16BE6C 0026BE6C 9C14050C */  jal        func_00145270
    /* 16BE70 0026BE70 00000000 */   nop
    /* 16BE74 0026BE74 2D804000 */  daddu      $16, $2, $0
    /* 16BE78 0026BE78 04000016 */  bnez       $16, .L0026BE8C
    /* 16BE7C 0026BE7C 00000000 */   nop
    /* 16BE80 0026BE80 2D100000 */  daddu      $2, $0, $0
    /* 16BE84 0026BE84 1E000010 */  b          .L0026BF00
    /* 16BE88 0026BE88 00000000 */   nop
  .L0026BE8C:
    /* 16BE8C 0026BE8C 04000016 */  bnez       $16, .L0026BEA0
    /* 16BE90 0026BE90 00000000 */   nop
    /* 16BE94 0026BE94 2D100000 */  daddu      $2, $0, $0
    /* 16BE98 0026BE98 19000010 */  b          .L0026BF00
    /* 16BE9C 0026BE9C 00000000 */   nop
  .L0026BEA0:
    /* 16BEA0 0026BEA0 00000396 */  lhu        $3, 0x0($16)
    /* 16BEA4 0026BEA4 0F00023C */  lui        $2, (0xFFC00 >> 16)
    /* 16BEA8 0026BEA8 00FC4234 */  ori        $2, $2, (0xFFC00 & 0xFFFF)
    /* 16BEAC 0026BEAC 24106200 */  and        $2, $3, $2
    /* 16BEB0 0026BEB0 83120200 */  sra        $2, $2, 10
    /* 16BEB4 0026BEB4 07000424 */  addiu      $4, $0, 0x7
    /* 16BEB8 0026BEB8 04004410 */  beq        $2, $4, .L0026BECC
    /* 16BEBC 0026BEBC 00000000 */   nop
    /* 16BEC0 0026BEC0 2D100000 */  daddu      $2, $0, $0
    /* 16BEC4 0026BEC4 0E000010 */  b          .L0026BF00
    /* 16BEC8 0026BEC8 00000000 */   nop
  .L0026BECC:
    /* 16BECC 0026BECC AC14050C */  jal        func_001452b0
    /* 16BED0 0026BED0 00000000 */   nop
    /* 16BED4 0026BED4 03000010 */  b          .L0026BEE4
    /* 16BED8 0026BED8 00000000 */   nop
  .L0026BEDC:
    /* 16BEDC 0026BEDC 480140AC */  sw         $0, 0x148($2)
    /* 16BEE0 0026BEE0 3801428C */  lw         $2, 0x138($2)
  .L0026BEE4:
    /* 16BEE4 0026BEE4 00000000 */  nop
    /* 16BEE8 0026BEE8 00000000 */  nop
    /* 16BEEC 0026BEEC 00000000 */  nop
    /* 16BEF0 0026BEF0 FAFF4014 */  bnez       $2, .L0026BEDC
    /* 16BEF4 0026BEF4 00000000 */   nop
    /* 16BEF8 0026BEF8 01000224 */  addiu      $2, $0, 0x1
    /* 16BEFC 0026BEFC 480102AE */  sw         $2, 0x148($16)
  .L0026BF00:
    /* 16BF00 0026BF00 1000BFDF */  ld         $31, 0x10($29)
    /* 16BF04 0026BF04 0000B07B */  lq         $16, 0x0($29)
    /* 16BF08 0026BF08 2000BD27 */  addiu      $29, $29, 0x20
    /* 16BF0C 0026BF0C 0800E003 */  jr         $31
    /* 16BF10 0026BF10 00000000 */   nop
    /* 16BF14 0026BF14 00000000 */  nop
    /* 16BF18 0026BF18 00000000 */  nop
    /* 16BF1C 0026BF1C 00000000 */  nop
.size func_0026be60, 0xc0
