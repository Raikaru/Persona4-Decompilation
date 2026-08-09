.section .text
.set noat
.set noreorder
glabel func_0039beb0
    /* 29BEB0 0039BEB0 70FFBD27 */  addiu      $29, $29, -0x90
    /* 29BEB4 0039BEB4 4000BFFF */  sd         $31, 0x40($29)
    /* 29BEB8 0039BEB8 3000B37F */  sq         $19, 0x30($29)
    /* 29BEBC 0039BEBC 2000B27F */  sq         $18, 0x20($29)
    /* 29BEC0 0039BEC0 2D988000 */  daddu      $19, $4, $0
    /* 29BEC4 0039BEC4 1000B17F */  sq         $17, 0x10($29)
    /* 29BEC8 0039BEC8 2D90A000 */  daddu      $18, $5, $0
    /* 29BECC 0039BECC 2D006012 */  beqz       $19, .L0039BF84
    /* 29BED0 0039BED0 0000B07F */   sq        $16, 0x0($29)
  .L0039BED4:
    /* 29BED4 0039BED4 8800023C */  lui        $2, %hi(D_008872E8)
    /* 29BED8 0039BED8 0800D18C */  lw         $17, 0x8($6)
    /* 29BEDC 0039BEDC E8725094 */  lhu        $16, %lo(D_008872E8)($2)
    /* 29BEE0 0039BEE0 04B6828F */  lw         $2, -0x49FC($28)
    /* 29BEE4 0039BEE4 2B002212 */  beq        $17, $2, .L0039BF94
    /* 29BEE8 0039BEE8 00000000 */   nop
  .L0039BEEC:
    /* 29BEEC 0039BEEC C0A50F0C */  jal        func_003e9700
    /* 29BEF0 0039BEF0 2D206002 */   daddu     $4, $19, $0
    /* 29BEF4 0039BEF4 00002492 */  lbu        $4, 0x0($17)
    /* 29BEF8 0039BEF8 FF000324 */  addiu      $3, $0, 0xFF
    /* 29BEFC 0039BEFC 2D008310 */  beq        $4, $3, .L0039BFB4
    /* 29BF00 0039BF00 00000000 */   nop
    /* 29BF04 0039BF04 2D284000 */  daddu      $5, $2, $0
    /* 29BF08 0039BF08 58820F0C */  jal        func_003e0960
    /* 29BF0C 0039BF0C 5000A427 */   addiu     $4, $29, 0x50
    /* 29BF10 0039BF10 C0A50F0C */  jal        func_003e9700
    /* 29BF14 0039BF14 0400248E */   lw        $4, 0x4($17)
    /* 29BF18 0039BF18 8800043C */  lui        $4, %hi(D_00884AE0)
    /* 29BF1C 0039BF1C 2D284000 */  daddu      $5, $2, $0
    /* 29BF20 0039BF20 E04A8424 */  addiu      $4, $4, %lo(D_00884AE0)
    /* 29BF24 0039BF24 7C810F0C */  jal        func_003e05f0
    /* 29BF28 0039BF28 5000A627 */   addiu     $6, $29, 0x50
  .L0039BF2C:
    /* 29BF2C 0039BF2C 8800023C */  lui        $2, %hi(D_00884AEC)
    /* 29BF30 0039BF30 03000324 */  addiu      $3, $0, 0x3
    /* 29BF34 0039BF34 EC4A428C */  lw         $2, %lo(D_00884AEC)($2)
    /* 29BF38 0039BF38 03004230 */  andi       $2, $2, 0x3
    /* 29BF3C 0039BF3C 23004314 */  bne        $2, $3, .L0039BFCC
    /* 29BF40 0039BF40 00000000 */   nop
    /* 29BF44 0039BF44 04B691AF */  sw         $17, -0x49FC($28)
  .L0039BF48:
    /* 29BF48 0039BF48 08B690FF */  sd         $16, -0x49F8($28)
    /* 29BF4C 0039BF4C 00B693AF */  sw         $19, -0x4A00($28)
  .L0039BF50:
    /* 29BF50 0039BF50 8800053C */  lui        $5, %hi(D_00884AE0)
    /* 29BF54 0039BF54 08000424 */  addiu      $4, $0, 0x8
    /* 29BF58 0039BF58 E04AA524 */  addiu      $5, $5, %lo(D_00884AE0)
  .L0039BF5C:
    /* 29BF5C 0039BF5C 0000A38C */  lw         $3, 0x0($5)
    /* 29BF60 0039BF60 FFFF8424 */  addiu      $4, $4, -0x1
    /* 29BF64 0039BF64 0400A28C */  lw         $2, 0x4($5)
    /* 29BF68 0039BF68 000043AE */  sw         $3, 0x0($18)
    /* 29BF6C 0039BF6C 0800A524 */  addiu      $5, $5, 0x8
    /* 29BF70 0039BF70 040042AE */  sw         $2, 0x4($18)
    /* 29BF74 0039BF74 F9FF801C */  bgtz       $4, .L0039BF5C
    /* 29BF78 0039BF78 08005226 */   addiu     $18, $18, 0x8
    /* 29BF7C 0039BF7C 19000010 */  b          .L0039BFE4
    /* 29BF80 0039BF80 2D106002 */   daddu     $2, $19, $0
  .L0039BF84:
    /* 29BF84 0039BF84 8800023C */  lui        $2, %hi(D_008872E0)
    /* 29BF88 0039BF88 E072428C */  lw         $2, %lo(D_008872E0)($2)
    /* 29BF8C 0039BF8C D1FF0010 */  b          .L0039BED4
    /* 29BF90 0039BF90 0400538C */   lw        $19, 0x4($2)
  .L0039BF94:
    /* 29BF94 0039BF94 00B6828F */  lw         $2, -0x4A00($28)
    /* 29BF98 0039BF98 D4FF6216 */  bne        $19, $2, .L0039BEEC
    /* 29BF9C 0039BF9C 00000000 */   nop
    /* 29BFA0 0039BFA0 08B682DF */  ld         $2, -0x49F8($28)
    /* 29BFA4 0039BFA4 EAFF0212 */  beq        $16, $2, .L0039BF50
    /* 29BFA8 0039BFA8 00000000 */   nop
    /* 29BFAC 0039BFAC CFFF0010 */  b          .L0039BEEC
    /* 29BFB0 0039BFB0 00000000 */   nop
  .L0039BFB4:
    /* 29BFB4 0039BFB4 8800043C */  lui        $4, %hi(D_00884AE0)
    /* 29BFB8 0039BFB8 2D284000 */  daddu      $5, $2, $0
    /* 29BFBC 0039BFBC 58820F0C */  jal        func_003e0960
    /* 29BFC0 0039BFC0 E04A8424 */   addiu     $4, $4, %lo(D_00884AE0)
    /* 29BFC4 0039BFC4 D9FF0010 */  b          .L0039BF2C
    /* 29BFC8 0039BFC8 00000000 */   nop
  .L0039BFCC:
    /* 29BFCC 0039BFCC 8800043C */  lui        $4, %hi(D_00884AE0)
    /* 29BFD0 0039BFD0 E04A8424 */  addiu      $4, $4, %lo(D_00884AE0)
    /* 29BFD4 0039BFD4 9C810F0C */  jal        func_003e0670
    /* 29BFD8 0039BFD8 2D288000 */   daddu     $5, $4, $0
    /* 29BFDC 0039BFDC DAFF0010 */  b          .L0039BF48
    /* 29BFE0 0039BFE0 04B691AF */   sw        $17, -0x49FC($28)
  .L0039BFE4:
    /* 29BFE4 0039BFE4 4000BFDF */  ld         $31, 0x40($29)
    /* 29BFE8 0039BFE8 3000B37B */  lq         $19, 0x30($29)
    /* 29BFEC 0039BFEC 2000B27B */  lq         $18, 0x20($29)
    /* 29BFF0 0039BFF0 1000B17B */  lq         $17, 0x10($29)
    /* 29BFF4 0039BFF4 0000B07B */  lq         $16, 0x0($29)
    /* 29BFF8 0039BFF8 0800E003 */  jr         $31
    /* 29BFFC 0039BFFC 9000BD27 */   addiu     $29, $29, 0x90
.size func_0039beb0, 0x150
