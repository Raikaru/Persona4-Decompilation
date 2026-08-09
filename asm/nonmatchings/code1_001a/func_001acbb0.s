.section .text
.set noat
.set noreorder
glabel func_001acbb0
    /* ACBB0 001ACBB0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* ACBB4 001ACBB4 7000BFFF */  sd         $31, 0x70($29)
    /* ACBB8 001ACBB8 6000B57F */  sq         $21, 0x60($29)
    /* ACBBC 001ACBBC 5000B47F */  sq         $20, 0x50($29)
    /* ACBC0 001ACBC0 4000B37F */  sq         $19, 0x40($29)
    /* ACBC4 001ACBC4 3000B27F */  sq         $18, 0x30($29)
    /* ACBC8 001ACBC8 2000B17F */  sq         $17, 0x20($29)
    /* ACBCC 001ACBCC 1000B07F */  sq         $16, 0x10($29)
    /* ACBD0 001ACBD0 2D908000 */  daddu      $18, $4, $0
    /* ACBD4 001ACBD4 3000908C */  lw         $16, 0x30($4)
    /* ACBD8 001ACBD8 9C00038E */  lw         $3, 0x9C($16)
    /* ACBDC 001ACBDC EFFF0224 */  addiu      $2, $0, -0x11
    /* ACBE0 001ACBE0 24106200 */  and        $2, $3, $2
    /* ACBE4 001ACBE4 9C0002AE */  sw         $2, 0x9C($16)
    /* ACBE8 001ACBE8 03FF0434 */  ori        $4, $0, 0xFF03
    /* ACBEC 001ACBEC 344F060C */  jal        func_00193cd0
    /* ACBF0 001ACBF0 00000000 */   nop
    /* ACBF4 001ACBF4 C5004014 */  bnez       $2, .L001ACF0C
    /* ACBF8 001ACBF8 00000000 */   nop
    /* ACBFC 001ACBFC ACB3828F */  lw         $2, -0x4C54($28)
    /* ACC00 001ACC00 0C004524 */  addiu      $5, $2, 0xC
    /* ACC04 001ACC04 0C00448C */  lw         $4, 0xC($2)
    /* ACC08 001ACC08 0800033C */  lui        $3, (0x80000 >> 16)
    /* ACC0C 001ACC0C 24108300 */  and        $2, $4, $3
    /* ACC10 001ACC10 06004014 */  bnez       $2, .L001ACC2C
    /* ACC14 001ACC14 00000000 */   nop
    /* ACC18 001ACC18 25108300 */  or         $2, $4, $3
    /* ACC1C 001ACC1C 0000A2AC */  sw         $2, 0x0($5)
    /* ACC20 001ACC20 01001124 */  addiu      $17, $0, 0x1
    /* ACC24 001ACC24 02000010 */  b          .L001ACC30
    /* ACC28 001ACC28 00000000 */   nop
  .L001ACC2C:
    /* ACC2C 001ACC2C 2D880000 */  daddu      $17, $0, $0
  .L001ACC30:
    /* ACC30 001ACC30 F4034396 */  lhu        $3, 0x3F4($18)
    /* ACC34 001ACC34 32020224 */  addiu      $2, $0, 0x232
    /* ACC38 001ACC38 1D006210 */  beq        $3, $2, .L001ACCB0
    /* ACC3C 001ACC3C 00000000 */   nop
    /* ACC40 001ACC40 31020224 */  addiu      $2, $0, 0x231
    /* ACC44 001ACC44 17006210 */  beq        $3, $2, .L001ACCA4
    /* ACC48 001ACC48 00000000 */   nop
    /* ACC4C 001ACC4C 54010224 */  addiu      $2, $0, 0x154
    /* ACC50 001ACC50 11006210 */  beq        $3, $2, .L001ACC98
    /* ACC54 001ACC54 00000000 */   nop
    /* ACC58 001ACC58 10020224 */  addiu      $2, $0, 0x210
    /* ACC5C 001ACC5C 03006210 */  beq        $3, $2, .L001ACC6C
    /* ACC60 001ACC60 00000000 */   nop
    /* ACC64 001ACC64 15000010 */  b          .L001ACCBC
    /* ACC68 001ACC68 00000000 */   nop
  .L001ACC6C:
    /* ACC6C 001ACC6C A2000292 */  lbu        $2, 0xA2($16)
    /* ACC70 001ACC70 04004014 */  bnez       $2, .L001ACC84
    /* ACC74 001ACC74 00000000 */   nop
    /* ACC78 001ACC78 3E000224 */  addiu      $2, $0, 0x3E
    /* ACC7C 001ACC7C 02000010 */  b          .L001ACC88
    /* ACC80 001ACC80 00000000 */   nop
  .L001ACC84:
    /* ACC84 001ACC84 3F000224 */  addiu      $2, $0, 0x3F
  .L001ACC88:
    /* ACC88 001ACC88 3C140200 */  dsll32     $2, $2, 16
    /* ACC8C 001ACC8C 3F140200 */  dsra32     $2, $2, 16
    /* ACC90 001ACC90 13000010 */  b          .L001ACCE0
    /* ACC94 001ACC94 00000000 */   nop
  .L001ACC98:
    /* ACC98 001ACC98 9B000224 */  addiu      $2, $0, 0x9B
    /* ACC9C 001ACC9C 10000010 */  b          .L001ACCE0
    /* ACCA0 001ACCA0 00000000 */   nop
  .L001ACCA4:
    /* ACCA4 001ACCA4 B4000224 */  addiu      $2, $0, 0xB4
    /* ACCA8 001ACCA8 0D000010 */  b          .L001ACCE0
    /* ACCAC 001ACCAC 00000000 */   nop
  .L001ACCB0:
    /* ACCB0 001ACCB0 B6000224 */  addiu      $2, $0, 0xB6
    /* ACCB4 001ACCB4 0A000010 */  b          .L001ACCE0
    /* ACCB8 001ACCB8 00000000 */   nop
  .L001ACCBC:
    /* ACCBC 001ACCBC A2000292 */  lbu        $2, 0xA2($16)
    /* ACCC0 001ACCC0 04004014 */  bnez       $2, .L001ACCD4
    /* ACCC4 001ACCC4 00000000 */   nop
    /* ACCC8 001ACCC8 3C000224 */  addiu      $2, $0, 0x3C
    /* ACCCC 001ACCCC 02000010 */  b          .L001ACCD8
    /* ACCD0 001ACCD0 00000000 */   nop
  .L001ACCD4:
    /* ACCD4 001ACCD4 3D000224 */  addiu      $2, $0, 0x3D
  .L001ACCD8:
    /* ACCD8 001ACCD8 3C140200 */  dsll32     $2, $2, 16
    /* ACCDC 001ACCDC 3F140200 */  dsra32     $2, $2, 16
  .L001ACCE0:
    /* ACCE0 001ACCE0 3C2C0200 */  dsll32     $5, $2, 16
    /* ACCE4 001ACCE4 3F2C0500 */  dsra32     $5, $5, 16
    /* ACCE8 001ACCE8 3000448E */  lw         $4, 0x30($18)
    /* ACCEC 001ACCEC 0009080C */  jal        func_00202400
    /* ACCF0 001ACCF0 00000000 */   nop
    /* ACCF4 001ACCF4 2D984000 */  daddu      $19, $2, $0
    /* ACCF8 001ACCF8 08000324 */  addiu      $3, $0, 0x8
    /* ACCFC 001ACCFC 480043A4 */  sh         $3, 0x48($2)
    /* ACD00 001ACD00 000043DE */  ld         $3, 0x0($18)
    /* ACD04 001ACD04 600043FC */  sd         $3, 0x60($2)
    /* ACD08 001ACD08 2D206002 */  daddu      $4, $19, $0
    /* ACD0C 001ACD0C 03000524 */  addiu      $5, $0, 0x3
    /* ACD10 001ACD10 6451060C */  jal        func_00194590
    /* ACD14 001ACD14 00000000 */   nop
    /* ACD18 001ACD18 580075DE */  ld         $21, 0x58($19)
    /* ACD1C 001ACD1C D852060C */  jal        func_00194b60
    /* ACD20 001ACD20 00000000 */   nop
    /* ACD24 001ACD24 2D984000 */  daddu      $19, $2, $0
    /* ACD28 001ACD28 08000324 */  addiu      $3, $0, 0x8
    /* ACD2C 001ACD2C 480043A4 */  sh         $3, 0x48($2)
    /* ACD30 001ACD30 000043DE */  ld         $3, 0x0($18)
    /* ACD34 001ACD34 600043FC */  sd         $3, 0x60($2)
    /* ACD38 001ACD38 2D206002 */  daddu      $4, $19, $0
    /* ACD3C 001ACD3C 2D280000 */  daddu      $5, $0, $0
    /* ACD40 001ACD40 6451060C */  jal        func_00194590
    /* ACD44 001ACD44 00000000 */   nop
    /* ACD48 001ACD48 580074DE */  ld         $20, 0x58($19)
    /* ACD4C 001ACD4C F4034396 */  lhu        $3, 0x3F4($18)
    /* ACD50 001ACD50 54010224 */  addiu      $2, $0, 0x154
    /* ACD54 001ACD54 0C006214 */  bne        $3, $2, .L001ACD88
    /* ACD58 001ACD58 00000000 */   nop
    /* ACD5C 001ACD5C 40030424 */  addiu      $4, $0, 0x340
    /* ACD60 001ACD60 8019040C */  jal        func_00106600
    /* ACD64 001ACD64 00000000 */   nop
    /* ACD68 001ACD68 FF004230 */  andi       $2, $2, 0xFF
    /* ACD6C 001ACD6C 06004018 */  blez       $2, .L001ACD88
    /* ACD70 001ACD70 00000000 */   nop
    /* ACD74 001ACD74 FFFF4224 */  addiu      $2, $2, -0x1
    /* ACD78 001ACD78 FF004530 */  andi       $5, $2, 0xFF
    /* ACD7C 001ACD7C 40030424 */  addiu      $4, $0, 0x340
    /* ACD80 001ACD80 8819040C */  jal        func_00106620
    /* ACD84 001ACD84 00000000 */   nop
  .L001ACD88:
    /* ACD88 001ACD88 F4034396 */  lhu        $3, 0x3F4($18)
    /* ACD8C 001ACD8C 10020224 */  addiu      $2, $0, 0x210
    /* ACD90 001ACD90 4C006214 */  bne        $3, $2, .L001ACEC4
    /* ACD94 001ACD94 00000000 */   nop
    /* ACD98 001ACD98 8000A427 */  addiu      $4, $29, 0x80
    /* ACD9C 001ACD9C 84C2070C */  jal        func_001f0a10
    /* ACDA0 001ACDA0 00000000 */   nop
    /* ACDA4 001ACDA4 640A048E */  lw         $4, 0xA64($16)
    /* ACDA8 001ACDA8 E0C7080C */  jal        func_00231f80
    /* ACDAC 001ACDAC 00000000 */   nop
    /* ACDB0 001ACDB0 FFFF5330 */  andi       $19, $2, 0xFFFF
    /* ACDB4 001ACDB4 640A048E */  lw         $4, 0xA64($16)
    /* ACDB8 001ACDB8 B4C7080C */  jal        func_00231ed0
    /* ACDBC 001ACDBC 00000000 */   nop
    /* ACDC0 001ACDC0 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* ACDC4 001ACDC4 23106202 */  subu       $2, $19, $2
    /* ACDC8 001ACDC8 8000A2AF */  sw         $2, 0x80($29)
    /* ACDCC 001ACDCC 2D204002 */  daddu      $4, $18, $0
    /* ACDD0 001ACDD0 2D284002 */  daddu      $5, $18, $0
    /* ACDD4 001ACDD4 8000A627 */  addiu      $6, $29, 0x80
    /* ACDD8 001ACDD8 01000724 */  addiu      $7, $0, 0x1
    /* ACDDC 001ACDDC 2D40E000 */  daddu      $8, $7, $0
    /* ACDE0 001ACDE0 B8CD070C */  jal        func_001f36e0
    /* ACDE4 001ACDE4 00000000 */   nop
    /* ACDE8 001ACDE8 2D204000 */  daddu      $4, $2, $0
    /* ACDEC 001ACDEC 04000324 */  addiu      $3, $0, 0x4
    /* ACDF0 001ACDF0 000043A0 */  sb         $3, 0x0($2)
    /* ACDF4 001ACDF4 080054FC */  sd         $20, 0x8($2)
    /* ACDF8 001ACDF8 000043DE */  ld         $3, 0x0($18)
    /* ACDFC 001ACDFC 600043FC */  sd         $3, 0x60($2)
    /* ACE00 001ACE00 01000524 */  addiu      $5, $0, 0x1
    /* ACE04 001ACE04 6451060C */  jal        func_00194590
    /* ACE08 001ACE08 00000000 */   nop
    /* ACE0C 001ACE0C 2D200002 */  daddu      $4, $16, $0
    /* ACE10 001ACE10 D009080C */  jal        func_00202740
    /* ACE14 001ACE14 00000000 */   nop
    /* ACE18 001ACE18 2D204000 */  daddu      $4, $2, $0
    /* ACE1C 001ACE1C 04000324 */  addiu      $3, $0, 0x4
    /* ACE20 001ACE20 000043A0 */  sb         $3, 0x0($2)
    /* ACE24 001ACE24 080054FC */  sd         $20, 0x8($2)
    /* ACE28 001ACE28 000043DE */  ld         $3, 0x0($18)
    /* ACE2C 001ACE2C 600043FC */  sd         $3, 0x60($2)
    /* ACE30 001ACE30 01000524 */  addiu      $5, $0, 0x1
    /* ACE34 001ACE34 6451060C */  jal        func_00194590
    /* ACE38 001ACE38 00000000 */   nop
    /* ACE3C 001ACE3C 0000A0FF */  sd         $0, 0x0($29)
    /* ACE40 001ACE40 2D200002 */  daddu      $4, $16, $0
    /* ACE44 001ACE44 2D280002 */  daddu      $5, $16, $0
    /* ACE48 001ACE48 FFFF0624 */  addiu      $6, $0, -0x1
    /* ACE4C 001ACE4C 2D380000 */  daddu      $7, $0, $0
    /* ACE50 001ACE50 2D400000 */  daddu      $8, $0, $0
    /* ACE54 001ACE54 2D480000 */  daddu      $9, $0, $0
    /* ACE58 001ACE58 01000A24 */  addiu      $10, $0, 0x1
    /* ACE5C 001ACE5C 8000AB27 */  addiu      $11, $29, 0x80
    /* ACE60 001ACE60 7807080C */  jal        func_00201de0
    /* ACE64 001ACE64 00000000 */   nop
    /* ACE68 001ACE68 2D204000 */  daddu      $4, $2, $0
    /* ACE6C 001ACE6C 04000324 */  addiu      $3, $0, 0x4
    /* ACE70 001ACE70 000043A0 */  sb         $3, 0x0($2)
    /* ACE74 001ACE74 080054FC */  sd         $20, 0x8($2)
    /* ACE78 001ACE78 000043DE */  ld         $3, 0x0($18)
    /* ACE7C 001ACE7C 600043FC */  sd         $3, 0x60($2)
    /* ACE80 001ACE80 03000524 */  addiu      $5, $0, 0x3
    /* ACE84 001ACE84 6451060C */  jal        func_00194590
    /* ACE88 001ACE88 00000000 */   nop
    /* ACE8C 001ACE8C 2D200002 */  daddu      $4, $16, $0
    /* ACE90 001ACE90 2D280000 */  daddu      $5, $0, $0
    /* ACE94 001ACE94 2D300000 */  daddu      $6, $0, $0
    /* ACE98 001ACE98 6409080C */  jal        func_00202590
    /* ACE9C 001ACE9C 00000000 */   nop
    /* ACEA0 001ACEA0 2D204000 */  daddu      $4, $2, $0
    /* ACEA4 001ACEA4 04000324 */  addiu      $3, $0, 0x4
    /* ACEA8 001ACEA8 000043A0 */  sb         $3, 0x0($2)
    /* ACEAC 001ACEAC 080054FC */  sd         $20, 0x8($2)
    /* ACEB0 001ACEB0 000043DE */  ld         $3, 0x0($18)
    /* ACEB4 001ACEB4 600043FC */  sd         $3, 0x60($2)
    /* ACEB8 001ACEB8 03000524 */  addiu      $5, $0, 0x3
    /* ACEBC 001ACEBC 6451060C */  jal        func_00194590
    /* ACEC0 001ACEC0 00000000 */   nop
  .L001ACEC4:
    /* ACEC4 001ACEC4 0D002012 */  beqz       $17, .L001ACEFC
    /* ACEC8 001ACEC8 00000000 */   nop
    /* ACECC 001ACECC 0800043C */  lui        $4, (0x80000 >> 16)
    /* ACED0 001ACED0 FC4D060C */  jal        func_001937f0
    /* ACED4 001ACED4 00000000 */   nop
    /* ACED8 001ACED8 2D204000 */  daddu      $4, $2, $0
    /* ACEDC 001ACEDC 04000324 */  addiu      $3, $0, 0x4
    /* ACEE0 001ACEE0 000043A0 */  sb         $3, 0x0($2)
    /* ACEE4 001ACEE4 080055FC */  sd         $21, 0x8($2)
    /* ACEE8 001ACEE8 000043DE */  ld         $3, 0x0($18)
    /* ACEEC 001ACEEC 600043FC */  sd         $3, 0x60($2)
    /* ACEF0 001ACEF0 2D280000 */  daddu      $5, $0, $0
    /* ACEF4 001ACEF4 6451060C */  jal        func_00194590
    /* ACEF8 001ACEF8 00000000 */   nop
  .L001ACEFC:
    /* ACEFC 001ACEFC 2D204002 */  daddu      $4, $18, $0
    /* ACF00 001ACF00 30044596 */  lhu        $5, 0x430($18)
    /* ACF04 001ACF04 00C2060C */  jal        func_001b0800
    /* ACF08 001ACF08 00000000 */   nop
  .L001ACF0C:
    /* ACF0C 001ACF0C 7000BFDF */  ld         $31, 0x70($29)
    /* ACF10 001ACF10 6000B57B */  lq         $21, 0x60($29)
    /* ACF14 001ACF14 5000B47B */  lq         $20, 0x50($29)
    /* ACF18 001ACF18 4000B37B */  lq         $19, 0x40($29)
    /* ACF1C 001ACF1C 3000B27B */  lq         $18, 0x30($29)
    /* ACF20 001ACF20 2000B17B */  lq         $17, 0x20($29)
    /* ACF24 001ACF24 1000B07B */  lq         $16, 0x10($29)
    /* ACF28 001ACF28 A000BD27 */  addiu      $29, $29, 0xA0
    /* ACF2C 001ACF2C 0800E003 */  jr         $31
    /* ACF30 001ACF30 00000000 */   nop
    /* ACF34 001ACF34 00000000 */  nop
    /* ACF38 001ACF38 00000000 */  nop
    /* ACF3C 001ACF3C 00000000 */  nop
.size func_001acbb0, 0x390
